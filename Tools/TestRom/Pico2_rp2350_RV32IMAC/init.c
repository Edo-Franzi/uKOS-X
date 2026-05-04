/*
; init.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		Low level init for the uKOS-X Pico2_rp2350 RISC-V module.
;
;			!!! This code HAS not to contain static data.
;			!!! It is called before to copy and to initialise
;			!!! the variable into the RAM.
;
;   (c) 2025-2026, Laurent von Allmen
;   ---------------------------------
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;------------------------------------------------------------------------
*/

#include	"tests.h"

// RISC-V specific runtime
// =======================

static	inline	void	wfi(void) { __asm volatile ("wfi"); }
static	inline	void	fence(void) { __asm volatile ("fence" ::: "memory"); }
static	inline	void	sev(void) { __asm volatile ("slt x0, x0, x1" ::: "memory"); }

// Prototypes

static	void		local_GPIO_Configuration(void);
static	void		local_PLL_Configuration(void);
static	void		local_emptyRxFifo(void);
static	void		local_writeRTxFifo(uint32_t data);
static	uint32_t	local_readRxFifo(void);

extern	void		first_handle_trap(void);
extern	uint8_t		linker_topStackFirst_C1[];

/*
 * \brief init_init
 *
 * - Initialise basic peripherals for RISC-V
 * - GPIO, clocks
 *
 *
 * \note This function does not return a value (None).
 *
 */
void	init_init(void) {

	local_GPIO_Configuration();
	local_PLL_Configuration();
}

/*
 * \brief local_GPIO_Configuration
 *
 * - Configure GPIO pins for LEDs
 *
 */
static	void	local_GPIO_Configuration(void) {

	// Release GPIO from reset
	REG(RESETS)->RESET &= ~(RESETS_RESET_IO_BANK0 | RESETS_RESET_PADS_BANK0);
	while ((REG(RESETS)->RESET_DONE & (RESETS_RESET_IO_BANK0 | RESETS_RESET_PADS_BANK0)) !=
	       (RESETS_RESET_IO_BANK0 | RESETS_RESET_PADS_BANK0)) { }

// ISO=0, outputs

	REG(PADS_BANK0)->GPIO11 &= ~PADS_BANK0_GPIO11_ISO;
	REG(PADS_BANK0)->GPIO12 &= ~PADS_BANK0_GPIO12_ISO;
	REG(PADS_BANK0)->GPIO13 &= ~PADS_BANK0_GPIO13_ISO;

	#if (BOARD_Pico2 == true)
	REG(PADS_BANK0)->GPIO25 &= ~PADS_BANK0_GPIO25_ISO;
	#endif

	#if (BOARD_Pico2W == true)
	REG(PADS_BANK0)->GPIO0 &= ~PADS_BANK0_GPIO0_ISO;
	#endif

	REG(IO_BANK0)->GPIO11_CTRL = IO_BANK0_GPIO11_CTRL_FUNCSEL_SIOB_PROC_11;
	REG(IO_BANK0)->GPIO12_CTRL = IO_BANK0_GPIO12_CTRL_FUNCSEL_SIOB_PROC_12;
	REG(IO_BANK0)->GPIO13_CTRL = IO_BANK0_GPIO13_CTRL_FUNCSEL_SIOB_PROC_13;

	#if (BOARD_Pico2 == true)
	REG(IO_BANK0)->GPIO25_CTRL = IO_BANK0_GPIO25_CTRL_FUNCSEL_SIOB_PROC_25;
	#endif

	#if (BOARD_Pico2W == true)
	REG(IO_BANK0)->GPIO0_CTRL = IO_BANK0_GPIO0_CTRL_FUNCSEL_SIOB_PROC_0;
	#endif

	REG(SIO)->GPIO_OE_SET = (1u << BLED_s) | (1u << BLED_0) | (1u << BLED_1) | (1u << BLED_2);

// Configure for UART0:
// - GPIO16 (TX): out, no pull-up (OD = 0), Schmitt on
// - GPIO17 (RX): inp, IE = 1, activate the Schmitt, no pull-up
// - GPIO16 -> UART0 TX, GPIO17 -> UART0 RX
// - (FUNCSEL = F1 for these UART0 pins)

	REG(PADS_BANK0)->GPIO16    = PADS_BANK0_GPIO16_SCHMITT;
	REG(PADS_BANK0)->GPIO17    = PADS_BANK0_GPIO17_IE | PADS_BANK0_GPIO17_SCHMITT;
	REG(IO_BANK0)->GPIO16_CTRL = IO_BANK0_GPIO16_CTRL_FUNCSEL_UART0_TX;
	REG(IO_BANK0)->GPIO17_CTRL = IO_BANK0_GPIO17_CTRL_FUNCSEL_UART0_RX;

// Configure for UART1:
// - GPIO4 (TX): out, no pull-up (OD = 0), Schmitt on
// - GPIO5 (RX): inp, IE = 1, activate the Schmitt, no pull-up
// - GPIO4 -> UART1 TX, GPIO5 -> UART1 RX
// - (FUNCSEL = F1 for these UART1 pins)

	REG(PADS_BANK0)->GPIO4    = PADS_BANK0_GPIO4_SCHMITT;
	REG(PADS_BANK0)->GPIO5    = PADS_BANK0_GPIO5_IE | PADS_BANK0_GPIO5_SCHMITT;
	REG(IO_BANK0)->GPIO4_CTRL = IO_BANK0_GPIO4_CTRL_FUNCSEL_UART1_TX;
	REG(IO_BANK0)->GPIO5_CTRL = IO_BANK0_GPIO5_CTRL_FUNCSEL_UART1_RX;
}

/*
 * \brief local_PLL_Configuration
 *
 * - Configure PLLs and clocks for 150 MHz system
 * - Same configuration as ARM version (registers are identical)
 *
 */
static	void	local_PLL_Configuration(void) {

// Disable clock resuscitation (may have been enabled by bootrom)

	REG(CLOCKS)->CLK_SYS_RESUS_CTRL = 0x0u;

// Before touching PLLs or XOSC, switch clk_sys and clk_ref to safe
// default sources (ROSC). This prevents killing the clock if the
// bootrom left clk_sys running from PLL or clk_ref running from XOSC.

	REG(CLOCKS)->CLK_SYS_CTRL &= ~CLOCKS_CLK_SYS_CTRL_SRC;
	while ((REG(CLOCKS)->CLK_SYS_SELECTED & 0x1u) == 0x0u) { }

	REG(CLOCKS)->CLK_REF_CTRL &= ~CLOCKS_CLK_REF_CTRL_SRC;
	while ((REG(CLOCKS)->CLK_REF_SELECTED & 0x1u) == 0x0u) { }

// Turn on the 12-MHz crystal oscillator

	REG(XOSC)->CTRL    = XOSC_CTRL_FREQ_RANGE_1_15MHZ;
	REG(XOSC)->STARTUP = 0x00C4u;
	REG(XOSC)->CTRL   |= XOSC_CTRL_ENABLE_ENABLE;
	while ((REG(XOSC)->STATUS & XOSC_STATUS_STABLE) == 0x0u) { }

// Switch clk_ref to XOSC (glitchless)

	REG(CLOCKS)->CLK_REF_DIV  = 1u * CLOCKS_CLK_REF_DIV_INT_0;
	REG(CLOCKS)->CLK_REF_CTRL = (REG(CLOCKS)->CLK_REF_CTRL & ~0x3u) | 0x2u;
	while ((REG(CLOCKS)->CLK_REF_SELECTED & (1u<<0x2u)) == 0x0u) { }

// Reset PLL_SYS
	REG(RESETS)->RESET |= RESETS_RESET_PLL_SYS;
	cmns_wait(10);
	REG(RESETS)->RESET &= ~RESETS_RESET_PLL_SYS;
	while ((REG(RESETS)->RESET_DONE & RESETS_RESET_DONE_PLL_SYS) == 0x0u) { }

	REG(PLL_SYS)->PWR |= (PLL_SYS_PWR_PD | PLL_SYS_PWR_VCOPD | PLL_SYS_PWR_POSTDIVPD);

	// Configure PLL_SYS for 150 MHz
	// VCO = 1500 MHz, REFDIV = 1, FBDIV = 125 (12 * 125 = 1500)
	// postdiv1 = 5, postdiv2 = 2 => 1500 / (5 * 2) = 150 MHz
	REG(PLL_SYS)->CS        = 0x1u;
	REG(PLL_SYS)->FBDIV_INT = 125u;

	// Turn on the VCO
	REG(PLL_SYS)->PWR &= ~(PLL_SYS_PWR_PD | PLL_SYS_PWR_VCOPD);
	while ((REG(PLL_SYS)->CS & PLL_SYS_CS_LOCK) == 0u) { }

	REG(PLL_SYS)->PRIM = (5u * PLL_SYS_PRIM_POSTDIV1_0) | (2u * PLL_SYS_PRIM_POSTDIV2_0);
	REG(PLL_SYS)->PWR &= ~PLL_SYS_PWR_POSTDIVPD;

	// Switch clk_sys to PLL_SYS (glitchless via SRC/AUXSRC)
	REG(CLOCKS)->CLK_SYS_DIV  = 1u * CLOCKS_CLK_SYS_DIV_INT_0;
	REG(CLOCKS)->CLK_SYS_CTRL = (REG(CLOCKS)->CLK_SYS_CTRL & ~(0x7u<<5u)) | (0x0u<<5u);
	REG(CLOCKS)->CLK_SYS_CTRL = (REG(CLOCKS)->CLK_SYS_CTRL & ~0x1u) | 0x1u;
	while ((REG(CLOCKS)->CLK_SYS_SELECTED & (1u<<0x1u)) == 0x0u) { }

	// Configure clk_peri = clk_sys (for UART, etc.)
	REG(CLOCKS)->CLK_PERI_CTRL = (0x0u<<5u) | (1u<<0x0Bu);

// The timer clocks
// ----------------

// Timer 0 clocked to 1-MHz

	REG(TICKS)->TIMER0_CTRL	  = TICKS_TIMER0_CTRL_ENABLE;
	REG(TICKS)->TIMER0_CYCLES = KCRYSTAL / KFREQUENCY_TIM;
	REG(TIMER0)->SOURCE		  = 0u;

// Timer 1 clocked to 1-MHz

	REG(TICKS)->TIMER1_CTRL	  = TICKS_TIMER1_CTRL_ENABLE;
	REG(TICKS)->TIMER1_CYCLES = KCRYSTAL / KFREQUENCY_TIM;
	REG(TIMER1)->SOURCE		  = 0u;
}

/*
 * \brief init_launchCore_1
 *
 * - Launch the core 1 using the RP2350 SIO FIFO mailbox protocol
 * - Sends {0, 0, 1, vtor, sp, pc} sequence and waits for echoes
 *
 */
void	init_launchCore_1(void (*entry)(void)) {
			uint32_t	i, cmd, echo;
	const	uint32_t	vtor   = (uint32_t)(uintptr_t)first_handle_trap;
	const	uint32_t	sp	   = (uint32_t)(uintptr_t)linker_topStackFirst_C1;
	const	uint32_t	pc	   = (uint32_t)(uintptr_t)entry;
    const	uint32_t	seq[6] = { 0u, 0u, 1u, vtor, sp, pc };

	i = 0u;
    do {
		cmd = seq[i];

// Before each 0 : empty RX + SEV

        if (cmd == 0u) { local_emptyRxFifo(); sev(); }

// Send and waiting for the echo

		local_writeRTxFifo(cmd);
        fence();

		echo = local_readRxFifo();
		i = (echo == cmd) ? (i + 1) : (0);
	} while (i < 6);
}

/*
 * \brief local_emptyRxFifo
 *
 * - Empty the Rx SIO fifo
 *
 */
static	void	local_emptyRxFifo(void) {
	uint8_t		i;

	for (i = 0; i < 8; i++) {
		if ((REG(SIO)->FIFO_ST & SIO_FIFO_ST_VLD) != 0u) {
			(void)REG(SIO)->FIFO_RD;
		}
		else { break; }
	}
}

/*
 * \brief local_writeRTxFifo
 *
 * - Send a word to the Tx SIO fifo
 *
 */
static	void	local_writeRTxFifo(uint32_t data) {

// Waiting for a room in the Tx fifo, and write
// Wake-up the core 1

	while ((REG(SIO)->FIFO_ST & SIO_FIFO_ST_RDY) == 0u) { }
	REG(SIO)->FIFO_WR = data;
	sev();
}

/*
 * \brief local_readRxFifo
 *
 * - Read a word from the Rx SIO fifo
 *
 */
static	uint32_t	local_readRxFifo(void) {

// Waiting for data in the Rx fifo, and read

	while ((REG(SIO)->FIFO_ST & SIO_FIFO_ST_VLD) == 0u) { }
	return (REG(SIO)->FIFO_RD);
}
