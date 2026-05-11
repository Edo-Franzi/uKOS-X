/*
; init.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Low level init for the uKOS-X Pico2_rp2350 module.
;
;			!!! This code HAS not to contain static data.
;			!!! It is called before to copy and to initialise
;			!!! the variable into the RAM.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
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
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
*/

#include	"uKOS.h"
#include	"linker.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"init         First hardware initialisations.           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Init\n"
									"====\n\n"

									"This code places in a quite state the hardware resources.\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Init,							// Module name (the first letter has to be upper case)
	KID_FAM_STARTUPS,				// Family (defined in the module.h)
	KNUM_INIT,						// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Runtime specific
// ================

// MISRA suggestion

typedef	uintptr_t	 entryAddr_t;

static	inline	void		sev(void) { __asm volatile ("sev"); }
static	inline	void		wfe(void) { __asm volatile ("wfe"); }

// Prototypes

extern			void		Reset_C1_Handler(void);
extern			void		cmns_wait(uint32_t us);
static			void		local_StackLimit_Configuration(void);
static			void		local_GPIO_Configuration(void);
static			void		local_PLL_Configuration(void);
static			void		local_MPU_Configuration(void);
static			void		local_FPU_Configuration(void);
static			void		local_USB_Configuration(void);
static			void		local_RAM_SHARED_Configuration(void);
static			void		local_launchCore_1(entryAddr_t entry);

static			void		local_emptyRxFifo(void);
static			void		local_writeRTxFifo(uint32_t data);
static			uint32_t	local_readRxFifo(void);

#define	KSZ_TABLE	(2u + KNB_EXCEPTIONS + KNB_INTERRUPTIONS)

extern			uintptr_t	g_pfnVectors_C0[];
extern			uintptr_t	g_pfnVectors_C1[];

[[gnu::aligned(512)]]
static			uintptr_t	vTableRam_C0[KSZ_TABLE];

/*
 * \brief init_init
 *
 * - Initialise some basic periphs
 * - GPIO, watchdog, SDRAM
 *
 *
 * \note This function does not return a value (None).
 *
 */
void	init_init(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	if (core == KCORE_0) {

// Initialisations under the control of the core 0

		local_GPIO_Configuration();
		local_PLL_Configuration();
		local_USB_Configuration();
		local_RAM_SHARED_Configuration();
		local_launchCore_1((entryAddr_t)&Reset_C1_Handler);
	}

// Initialisations for all the cores

	local_MPU_Configuration();
	local_FPU_Configuration();
	local_StackLimit_Configuration();
}

/*
 * \brief init_relocate
 *
 * - Vector table relocation
 *
 *
 * \note This function does not return a value (None).
 *
 */
void	init_relocate(void) {
	uint32_t	core, i;

	core = GET_RUNNING_CORE;

	if (core == KCORE_0) {

// Relocate the VTOR for the core 0
// This is necessary for TinyUSB

		for (i = 0u; i < KSZ_TABLE; i++) {
			vTableRam_C0[i] = g_pfnVectors_C0[i];
		}

		REG(SCB)->VTOR = (uint32_t)(uintptr_t)&vTableRam_C0[0];
		DATA_SYNC_BARRIER;
		INST_SYNC_BARRIER;
	}
}

/*
 * \brief local_GPIO_Configuration
 *
 * - GPIO configuration
 *
 */
static	void	local_GPIO_Configuration(void) {

	REG(RESETS)->RESET &= ~(RESETS_RESET_DONE_IO_BANK0 | RESETS_RESET_DONE_PADS_BANK0);
	while ((REG(RESETS)->RESET_DONE & (RESETS_RESET_DONE_IO_BANK0 | RESETS_RESET_DONE_PADS_BANK0)) != (RESETS_RESET_DONE_IO_BANK0 | RESETS_RESET_DONE_PADS_BANK0)) { ; }

// ISO=0, outputs

	REG(PADS_BANK0)->GPIO11 &= ~PADS_BANK0_GPIO11_ISO;
	REG(PADS_BANK0)->GPIO12 &= ~PADS_BANK0_GPIO12_ISO;
	REG(PADS_BANK0)->GPIO13 &= ~PADS_BANK0_GPIO13_ISO;
	REG(PADS_BANK0)->GPIO25 &= ~PADS_BANK0_GPIO25_ISO;

	REG(IO_BANK0)->GPIO11_CTRL = IO_BANK0_GPIO11_CTRL_FUNCSEL_SIOB_PROC_11;
	REG(IO_BANK0)->GPIO12_CTRL = IO_BANK0_GPIO12_CTRL_FUNCSEL_SIOB_PROC_12;
	REG(IO_BANK0)->GPIO13_CTRL = IO_BANK0_GPIO13_CTRL_FUNCSEL_SIOB_PROC_13;
	REG(IO_BANK0)->GPIO25_CTRL = IO_BANK0_GPIO25_CTRL_FUNCSEL_SIOB_PROC_25;

	REG(SIO)->GPIO_OE_SET	   = (1u<<BLED_s) | (1u<<BLED_0) | (1u<<BLED_1) | (1u<<BLED_2);

// ISO=0, inputs

	REG(PADS_BANK0)->GPIO21	   = PADS_BANK0_GPIO21_IE | PADS_BANK0_GPIO21_SCHMITT | PADS_BANK0_GPIO21_PUE;
	REG(IO_BANK0)->GPIO21_CTRL = IO_BANK0_GPIO21_CTRL_FUNCSEL_SIOB_PROC_21;

// Configure for UART0:
// - GPIO16 (TX): out, no pull-up (OD = 0), Schmitt on
// - GPIO17 (RX): inp, IE = 1, activate the Schmitt, no pull-up
// - GPIO16 -> UART0 TX, GPIO17 -> UART0 RX
// - (FUNCSEL = F1 for these UART0 pins)

	REG(PADS_BANK0)->GPIO16	   = PADS_BANK0_GPIO16_SCHMITT;
	REG(PADS_BANK0)->GPIO17	   = PADS_BANK0_GPIO17_IE | PADS_BANK0_GPIO17_SCHMITT;
	REG(IO_BANK0)->GPIO16_CTRL = IO_BANK0_GPIO16_CTRL_FUNCSEL_UART0_TX;
	REG(IO_BANK0)->GPIO17_CTRL = IO_BANK0_GPIO17_CTRL_FUNCSEL_UART0_RX;

// Configure for UART1:
// - GPIO4 (TX): out, no pull-up (OD = 0), Schmitt on
// - GPIO5 (RX): inp, IE = 1, activate the Schmitt, no pull-up
// - GPIO4 -> UART1 TX, GPIO5 -> UART1 RX
// - (FUNCSEL = F1 for these UART0 pins)

	REG(PADS_BANK0)->GPIO4	   = PADS_BANK0_GPIO4_SCHMITT;
	REG(PADS_BANK0)->GPIO5	   = PADS_BANK0_GPIO5_IE | PADS_BANK0_GPIO1_SCHMITT;
	REG(IO_BANK0)->GPIO4_CTRL  = IO_BANK0_GPIO4_CTRL_FUNCSEL_UART1_TX;
	REG(IO_BANK0)->GPIO5_CTRL  = IO_BANK0_GPIO5_CTRL_FUNCSEL_UART1_RX;
}

/*
 * \brief local_PLL_Configuration
 *
 * - Clock, PLL configuration
 *
 */
static	void	local_PLL_Configuration(void) {

#define	PLL_USB_PWR_PD				PLL_SYS_PWR_PD
#define	PLL_USB_PWR_VCOPD			PLL_SYS_PWR_VCOPD
#define	PLL_USB_PWR_POSTDIVPD		PLL_SYS_PWR_POSTDIVPD
#define	PLL_USB_CS_LOCK				PLL_SYS_CS_LOCK
#define	PLL_USB_PRIM_POSTDIV1_0		PLL_SYS_PRIM_POSTDIV1_0
#define	PLL_USB_PRIM_POSTDIV2_0		PLL_SYS_PRIM_POSTDIV2_0

// The quartz oscillator
// ---------------------

// Turn on the 12-MHz clock

	REG(XOSC)->CTRL	   = XOSC_CTRL_FREQ_RANGE_1_15MHZ;
	REG(XOSC)->STARTUP = 0x00C4u;
	REG(XOSC)->CTRL	  |= XOSC_CTRL_ENABLE_ENABLE;
	while ((REG(XOSC)->STATUS & XOSC_STATUS_STABLE) == 0x0u) { ; }

// Switch clk_ref on XOSC (glitchless)

	REG(CLOCKS)->CLK_REF_DIV  = 1u * CLOCKS_CLK_REF_DIV_INT_0;
	REG(CLOCKS)->CLK_REF_CTRL = (REG(CLOCKS)->CLK_REF_CTRL & ~0x3u) | 0x2u;
	while ((REG(CLOCKS)->CLK_REF_SELECTED & (1u<<0x2u)) == 0x0u) { ; }

// The main PLL
// ------------

// Reset the PLL_SYS

	REG(RESETS)->RESET |= RESETS_RESET_PLL_SYS;
	cmns_wait(10);
	REG(RESETS)->RESET &= ~RESETS_RESET_PLL_SYS;
	while ((REG(RESETS)->RESET_DONE & RESETS_RESET_DONE_PLL_SYS) == 0x0u) { ; }

	REG(PLL_SYS)->PWR |= (PLL_SYS_PWR_PD | PLL_SYS_PWR_VCOPD | PLL_SYS_PWR_POSTDIVPD);

// Configurer PLL_SYS for 150-MHz
// - VCO = 1500-MHz, REFDIV = 1, FBDIV = 125 (12 * 125 = 1500)
// - postdiv1 = 5, postdiv2 = 2  => 1500 / (5 * 2) = 150-MHz

	REG(PLL_SYS)->CS		= 0x1u;
	REG(PLL_SYS)->FBDIV_INT = 125u;

// Turn on the VCO

	REG(PLL_SYS)->PWR &= ~(PLL_SYS_PWR_PD | PLL_SYS_PWR_VCOPD);
	while ((REG(PLL_SYS)->CS & PLL_SYS_CS_LOCK) == 0u) { ; }

	REG(PLL_SYS)->PRIM = (5u * PLL_SYS_PRIM_POSTDIV1_0) | (2u * PLL_SYS_PRIM_POSTDIV2_0);
	REG(PLL_SYS)->PWR &= ~PLL_SYS_PWR_POSTDIVPD;

// Switch the clk_sys on the PLL_SYS (glitchless via SRC/AUXSRC)

	REG(CLOCKS)->CLK_SYS_DIV  = 1u * CLOCKS_CLK_SYS_DIV_INT_0;
	REG(CLOCKS)->CLK_SYS_CTRL = (REG(CLOCKS)->CLK_SYS_CTRL & ~(0x7u<<5u)) | (0x0u<<5u);
	REG(CLOCKS)->CLK_SYS_CTRL = (REG(CLOCKS)->CLK_SYS_CTRL & ~0x1u) | 0x1u;
	while ((REG(CLOCKS)->CLK_SYS_SELECTED & (1u<<0x1u)) == 0x0u) { ; }

// Optionnel : clk_peri = clk_sys (no glitchless, just AUXSRC + ENABLE)

	REG(CLOCKS)->CLK_PERI_DIV  = 1u * CLOCKS_CLK_PERI_DIV_INT_0;
	REG(CLOCKS)->CLK_PERI_CTRL = CLOCKS_CLK_PERI_CTRL_AUXSRC_CLK_SYS | CLOCKS_CLK_PERI_CTRL_ENABLE;

// The USB PLL
// -----------

// Reset the PLL_USB

	REG(RESETS)->RESET |= RESETS_RESET_PLL_USB;
	cmns_wait(10u);
	REG(RESETS)->RESET &= ~RESETS_RESET_PLL_USB;
	while ((REG(RESETS)->RESET_DONE & RESETS_RESET_DONE_PLL_USB) == 0x0u) { ; }

	REG(PLL_USB)->PWR |= (PLL_USB_PWR_PD | PLL_USB_PWR_VCOPD | PLL_USB_PWR_POSTDIVPD);

// Configurer PLL_USB for 48-MHz
// - VCO = 480-MHz, REFDIV = 1, FBDIV = 40 (12 * 40 = 480)
// - postdiv1 = 5, postdiv2 = 2  => 480 / (5 * 2) = 48-MHz

	REG(PLL_USB)->CS		= 0x1u;
	REG(PLL_USB)->FBDIV_INT = 40u;

// Turn on the VCO

	REG(PLL_USB)->PWR &= ~(PLL_USB_PWR_PD | PLL_USB_PWR_VCOPD);
	while ((REG(PLL_USB)->CS & PLL_USB_CS_LOCK) == 0u) { ; }

	REG(PLL_USB)->PRIM = (5u * PLL_USB_PRIM_POSTDIV1_0) | (2u * PLL_USB_PRIM_POSTDIV2_0);
	REG(PLL_USB)->PWR &= ~PLL_USB_PWR_POSTDIVPD;

// Switch the clk_usb on the PLL_USB (via SRC/AUXSRC)

	REG(CLOCKS)->CLK_USB_DIV  = 1u * CLOCKS_CLK_USB_DIV_INT_0;
	REG(CLOCKS)->CLK_USB_CTRL = (REG(CLOCKS)->CLK_USB_CTRL & ~(0x7u<<5u)) | (0x0u<<5u);
	REG(CLOCKS)->CLK_USB_CTRL = (REG(CLOCKS)->CLK_USB_CTRL | CLOCKS_CLK_USB_CTRL_ENABLE);

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
 * \brief local_USB_Configuration
 *
 * - Enable the USB
 *
 */
static	void	local_USB_Configuration(void) {

	REG(RESETS)->RESET &= ~RESETS_RESET_USBCTRL;
	while ((REG(RESETS)->RESET_DONE & RESETS_RESET_DONE_USBCTRL) == 0x0u) { ; }

	REG(USB)->MAIN_CTRL &= ~USB_MAIN_CTRL_PHY_ISO;
	REG(USB)->MAIN_CTRL |= USB_MAIN_CTRL_CONTROLLER_EN;
}

/*
 * \brief local_RAM_SHARED_Configuration
 *
 * - Clear the RAM Shared
 *
 */
static	void	local_RAM_SHARED_Configuration(void) {
	uint8_t		*ramShared;
	intptr_t	nbBytes;

	ramShared = ALIGNED_PTR(uint8_t, linker_stShare);
	nbBytes	  = (intptr_t)(linker_lnShare);

	while (nbBytes-- > 0) { *ramShared = 0u; ramShared++; }
}

/*
 * \brief local_launchCore_1
 *
 * - Launch the core 1
 *
 */
static	void	local_launchCore_1(entryAddr_t entry) {
			uint32_t	i, cmd, echo;
	const	uint32_t	vtor   = (uint32_t)g_pfnVectors_C1;
	const	uint32_t	sp	   = (uint32_t)(uintptr_t)linker_topStackFirst_C1;
	const	uint32_t	pc	   = ((uint32_t)(uintptr_t)entry) | 1u;
    const	uint32_t	seq[6] = { 0u, 0u, 1u, vtor, sp, pc };

	i = 0u;
    do {
		cmd = seq[i];

// Before each 0 : empty RX + SEV

        if (cmd == 0u) { local_emptyRxFifo(); sev(); }

// Send and waiting for the echo

		local_writeRTxFifo(cmd);
		DATA_SYNC_BARRIER;

		echo = local_readRxFifo();
		i = (echo == cmd) ? (i + 1u) : (0u);
	} while (i < 6u);
 }

/*
 * \brief local_MPU_Configuration
 *
 * - Initialise the MPU for the different
 *   memory regions of the system
 *
 */
static	void	local_MPU_Configuration(void) {

	SET_MPU8_INDEX(KMPU_FLASH_ATTR, KMPU_RAM_CACHE_ATTR, KMPU_RAM_NOT_CACHE_ATTR, KMPU_PERIPH_ATTR, 0u, 0u, 0u, 0u, 0u);

	#if (defined(PRIVILEGED_USER_S))
	SET_MPU8_REGION(0u,	ST_FLASH_INT_0,			EN_FLASH_INT_0,			KMPU_EXECUTABLE,		KMPU_R_ALL,  0u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(1u,	ST_RAM_INT_0_OS,		EN_RAM_INT_0_OS,		KMPU_EXECUTABLE,		KMPU_RW_PRI, 1u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(2u,	ST_RAM_INT_0,			EN_RAM_INT_0,			KMPU_EXECUTABLE,		KMPU_RW_ALL, 1u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(3u,	ST_RAM_INT_0_SHARED,	EN_RAM_INT_0_SHARED,	KMPU_EXECUTABLE,		KMPU_RW_ALL, 2u, KMPU_NOT_SHAREABLE);
	SET_MPU8_REGION(4u,	ST_PERIPH_SOC,			EN_PERIPH_SOC,			KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI, 3u, KMPU_NOT_SHAREABLE);
	SET_MPU8_REGION(5u,	ST_EXTERNAL,			EN_EXTERNAL,			KMPU_NOT_EXECUTABLE,	KMPU_RW_ALL, 3u, KMPU_NOT_SHAREABLE);
	SET_MPU8_REGION(6u,	ST_PERIPH_CORE,			EN_PERIPH_CORE,			KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI, 3u, KMPU_NOT_SHAREABLE);

	#else
	SET_MPU8_REGION(0u,	ST_FLASH_INT_0,			EN_FLASH_INT_0,			KMPU_EXECUTABLE,		KMPU_R_ALL,  0u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(1u,	ST_RAM_INT_0,			EN_RAM_INT_0,			KMPU_EXECUTABLE,		KMPU_RW_ALL, 1u, KMPU_INNER_SHAREABLE);
	#endif
}

/*
 * \brief local_FPU_Configuration
 *
 * - Enable the FPU
 *
 */
static	void	local_FPU_Configuration(void) {

// Set CP10 and CP11 Full Access
// Lazy stacking enable

	REG(SCB)->CPACR |= (SCB_CPACR_CP10	| SCB_CPACR_CP11);
	REG(FPE)->FPCCR |= (FPE_FPCCR_ASPEN | FPE_FPCCR_LSPEN);
}

/*
 * \brief local_StackLimit_Configuration
 *
 * - Enable the xSPLIM
 *	 - PSP is the initial stack used by the first process
 *	   The PSPLIM is adjusted during the switching of the processes
 *
 *	 - MSP is the system stack
 *
 */
static	void	local_StackLimit_Configuration(void) {

// Stack limit faults at requested priorities of less than 0 ignored

	#if (defined(STUB_KERN_CHECK_XSP_LIMIT_S))
	REG(SCB)->CCR |= (1u<<SCB_CCR_STKOFHFNMIGN);

	core_setPSPLIM((uintptr_t)linker_lowStackFirst_C0 & 0xFFFFFFF8u);
	core_setMSPLIM((uintptr_t)linker_lowStackSystem_C0 & 0xFFFFFFF8u);
	#endif
}

/*
 * \brief local_emptyRxFifo
 *
 * - Empty the Rx SIO fifo
 *
 */
static	void	local_emptyRxFifo(void) {
	uint8_t		i;

	for (i = 0u; i < 8u; i++) {
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

	while ((REG(SIO)->FIFO_ST & SIO_FIFO_ST_RDY) == 0u) { wfe(); }
	REG(SIO)->FIFO_WR = data;
	sev();
}

/*
 * \brief local_readRxFifo
 *
 * - Send a word to the Tx SIO fifo
 *
 */
static	uint32_t	local_readRxFifo(void) {

// Waiting for data in the Rx fifo, and read

	while ((REG(SIO)->FIFO_ST & SIO_FIFO_ST_VLD) == 0u) { wfe(); }
	return (REG(SIO)->FIFO_RD);
}
