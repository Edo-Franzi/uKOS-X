/*
; init.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Low level init for the uKOS-X MAiXDUiNO_K210 module.
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

typedef	struct	mainGpio	mainGpio_t;

struct	mainGpio {
			uint32_t	IOxx    : 8;		// IO number (IO00 .. IO47)
			uint32_t	ch_sel  : 8;		// Channel select from 256 input
			uint32_t	ds      : 4;		// Driving selector
			uint32_t	oe_en   : 1;		// Static output enable, will AND with OE_INV
			uint32_t	oe_inv  : 1;		// Invert output enable
			uint32_t	do_sel  : 1;		// Data output select: 0 for DO, 1 for OE
			uint32_t	do_inv  : 1;		// Invert the result of data output select (DO_SEL)
			uint32_t	pu      : 1;		// Pull up enable. 0 for nothing, 1 for pull up
			uint32_t	pd      : 1;		// Pull down enable. 0 for nothing, 1 for pull down
			uint32_t	resv0   : 1;		// Reserved bits
			uint32_t	sl      : 1;		// Slew rate control enable
			uint32_t	ie_en   : 1;		// Static input enable, will AND with IE_INV
			uint32_t	ie_inv  : 1;		// Invert input enable
			uint32_t	di_inv  : 1;		// Invert Data input
			uint32_t	st      : 1;		// Schmitt trigger
			uint32_t	tie_en  : 1;		// Input tie enable, 1 for enable, 0 for disable
			uint32_t	tie_val : 1;		// Input tie value, 1 for high, 0 for low
			uint32_t	resv1   : 5;		// Reserved bits
			uint32_t	pad_di  : 1;		// Read current PAD's data input
		};

extern	void	(*vExce_intIntVectors[KNB_CORES][KNB_INT_INTERRUPTIONS])(uint32_t core, uint64_t parameter);
extern	void	(*vExce_intExcVectors[KNB_CORES][KNB_INT_EXCEPTIONS])(uint32_t core, uint64_t parameter);
extern	void	(*vExce_extIntVectors[KNB_CORES][KNB_EXT_INTERRUPTIONS])(uint32_t core, uint64_t parameter);
extern	void	(*vMsgs_process[KNB_CORES])(uint32_t core, uint64_t message);

// Runtime specific
// ================

// Prototypes

static	void	local_GPIO_Configuration(void);
static	void	local_RCU_Configuration(void);
static	void	local_wait_100n(uint32_t n);
extern	void	first_handle_MachineExternal(uint32_t core, uint64_t parameter);
extern	void	first_handle_EnvironmentalCallM(uint32_t core, uint64_t parameter);
extern	void	first_handle_trap(void);

/*
 * \brief init_init
 *
 * - Initialise some basic periphs
 * - GPIO, watchdog, SDRAM
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
void	init_init(void) {

	local_GPIO_Configuration();				// GPIO Config
	local_RCU_Configuration();				// Clock Config
}

/*
 * \brief local_GPIO_Configuration
 *
 * - GPIO configuration
 *
 */
static	void	local_GPIO_Configuration(void) {
			uint16_t		i;
			uint32_t		ioxx;
			fpioa_tie_t		tie = { 0 };
	static	const			mainGpio_t	aGPIO_Cnf[] = {

//			  .IOxx  .ch_sel,				.ds,              .oe_en,  .oe_inv,  .do_sel,  .do_inv, .pu,   .pd,  .resv1, .sl,    .ie_en, .ie_inv,  .di_inv,  .st,  .tie_en,  .tie_val, .resv0,  .pad_di

			{ 0u,     FUNC_JTAG_TCLK,		FPIOA_DRIVING_0,  0u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 1u,     FUNC_JTAG_TDI,		FPIOA_DRIVING_0,  0u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 2u,     FUNC_JTAG_TMS,		FPIOA_DRIVING_0,  0u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 3u,     FUNC_JTAG_TDO,		FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    0u,     0u,       0u,       0u,   0u,       0u,        0u,      0u },
			{ 4u,     FUNC_UART2_RX,		FPIOA_DRIVING_0,  0u,      0u,       0u,       0u,       1u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 5u,     FUNC_UART2_TX,		FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       1u,   0u,   0u,      0u,    0u,     0u,       0u,       0u,   0u,       0u,        0u,      0u },

			{ 6u,     FUNC_UART3_RX,		FPIOA_DRIVING_0,  0u,      0u,       0u,       0u,       1u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 7u,     FUNC_UART3_TX,		FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       1u,   0u,   0u,      0u,    0u,     0u,       0u,       0u,   0u,       0u,        0u,      0u },
			{ 8u,     FUNC_GPIOHS0,			FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       1u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 9u,     FUNC_GPIOHS1,			FPIOA_DRIVING_0,  0u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 10u,    FUNC_UART1_RX,		FPIOA_DRIVING_0,  0u,      0u,       0u,       0u,       1u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 11u,    FUNC_GPIOHS5,			FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },

			{ 12u,    FUNC_GPIOHS8,			FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 13u,    FUNC_GPIOHS9,			FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 14u,    FUNC_GPIOHS10,		FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 15u,    FUNC_UART1_TX,		FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       1u,   0u,   0u,      0u,    0u,     0u,       0u,       0u,   0u,       0u,        0u,      0u },
			{ 16u,    FUNC_GPIOHS6,			FPIOA_DRIVING_0,  0u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 17u,    FUNC_GPIOHS7,			FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },

			{ 36u,    FUNC_SPI0_SS3,		FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    0u,     0u,       0u,       0u,   0u,       0u,        0u,      0u },
			{ 37u,    FUNC_GPIOHS3,			FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 38u,    FUNC_GPIOHS2,			FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 39u,    FUNC_SPI0_SCLK,		FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    0u,     0u,       0u,       0u,   0u,       0u,        0u,      0u },

			{ 40u,    FUNC_SCCB_SDA,		FPIOA_DRIVING_0,  1u,      1u,       0u,       0u,       1u,   0u,   0u,      1u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 41u,    FUNC_SCCB_SCLK,		FPIOA_DRIVING_0,  1u,      1u,       0u,       0u,       1u,   0u,   0u,      1u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 42u,    FUNC_CMOS_RST,		FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    0u,     0u,       0u,       0u,   0u,       0u,        0u,      0u },
			{ 43u,    FUNC_CMOS_VSYNC,		FPIOA_DRIVING_0,  0u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 44u,    FUNC_CMOS_PWDN,		FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    0u,     0u,       0u,       0u,   0u,       0u,        0u,      0u },
			{ 45u,    FUNC_CMOS_HREF,		FPIOA_DRIVING_0,  0u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u },
			{ 46u,    FUNC_CMOS_XCLK,		FPIOA_DRIVING_15, 1u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    0u,     0u,       0u,       0u,   0u,       0u,        0u,      0u },
			{ 47u,    FUNC_CMOS_PCLK,		FPIOA_DRIVING_0,  0u,      0u,       0u,       0u,       0u,   0u,   0u,      0u,    1u,     0u,       0u,       1u,   0u,       0u,        0u,      0u }
		};

#define	KNBCNF		(sizeof(aGPIO_Cnf)/sizeof(mainGpio_t))

	sysctl->clk_en_cent.apb0_clk_en  = 1u;			// Turn on APB0
	sysctl->clk_en_peri.fpioa_clk_en = 1u;			// Turn on the FPIOA
	local_wait_100n(1u);							//

	sysctl->misc.spi_dvp_data_enable = 1u;			//
	sysctl->clk_en_peri.dvp_clk_en	 = 1u;			// Enable the spi0-dvp
	local_wait_100n(1u);							//

	sysctl->peri_reset.dvp_reset = 1u;				//
	local_wait_100n(100u);							//
	sysctl->peri_reset.dvp_reset = 0u;				// Reset the dvp
	local_wait_100n(100u);							//

// Initialise tie
// Set tie enable and tie value
// 1 seems necessary only for SPIs

	for (i = 0; i < (uint16_t)FUNC_MAX; i++) {
		tie.en[i  / 32u] = 0u;
		tie.val[i / 32u] = 0u;
	}

	tie.en[(uint32_t)FUNC_SPI0_ARB  / 32u] |= (uint32_t)1u<<((uint32_t)FUNC_SPI0_ARB % 32u);
	tie.val[(uint32_t)FUNC_SPI0_ARB / 32u] |= (uint32_t)1u<<((uint32_t)FUNC_SPI0_ARB % 32u);
	tie.en[(uint32_t)FUNC_SPI1_ARB  / 32u] |= (uint32_t)1u<<((uint32_t)FUNC_SPI1_ARB % 32u);
	tie.val[(uint32_t)FUNC_SPI1_ARB / 32u] |= (uint32_t)1u<<((uint32_t)FUNC_SPI1_ARB % 32u);

// Atomic write every 32-bit register to fpioa function

	for (i = 0u; i < (uint16_t)((uint32_t)FUNC_MAX / 32u); i++) {
		fpioa->tie.val[i] = tie.val[i];
		fpioa->tie.en[i]  = tie.en[i];
	}

// Initialise the GPIO
// First, for all the PAD attribute the FUNC_RESV0 function
// Then, scann the table to customize the PADs

	for (i = 0u; i < FPIOA_NUM_IO; i++) {
		fpioa->io[i].ch_sel = FUNC_RESV0;
		fpioa->io[i].ds     = 0u;
		fpioa->io[i].oe_en  = 0u;
		fpioa->io[i].oe_inv = 0u;
		fpioa->io[i].do_sel = 0u;
		fpioa->io[i].do_inv = 0u;
		fpioa->io[i].pu     = 0u;
		fpioa->io[i].pd     = 0u;
		fpioa->io[i].sl     = 0u;
		fpioa->io[i].ie_en  = 0u;
		fpioa->io[i].ie_inv = 0u;
		fpioa->io[i].di_inv = 0u;
		fpioa->io[i].st     = 0u;
	}

	for (i = 0u; i < (uint16_t)KNBCNF; i++) {
		ioxx = aGPIO_Cnf[i].IOxx;

		fpioa->io[ioxx].ch_sel = aGPIO_Cnf[i].ch_sel;
		fpioa->io[ioxx].ds     = aGPIO_Cnf[i].ds;
		fpioa->io[ioxx].oe_en  = aGPIO_Cnf[i].oe_en;
		fpioa->io[ioxx].oe_inv = aGPIO_Cnf[i].oe_inv;
		fpioa->io[ioxx].do_sel = aGPIO_Cnf[i].do_sel;
		fpioa->io[ioxx].do_inv = aGPIO_Cnf[i].do_inv;
		fpioa->io[ioxx].pu     = aGPIO_Cnf[i].pu;
		fpioa->io[ioxx].pd     = aGPIO_Cnf[i].pd;
		fpioa->io[ioxx].sl     = aGPIO_Cnf[i].sl;
		fpioa->io[ioxx].ie_en  = aGPIO_Cnf[i].ie_en;
		fpioa->io[ioxx].ie_inv = aGPIO_Cnf[i].ie_inv;
		fpioa->io[ioxx].di_inv = aGPIO_Cnf[i].di_inv;
		fpioa->io[ioxx].st     = aGPIO_Cnf[i].st;
	}

// Port 6 & 7 & 1.8-V (dvp & spi)
// SYSCTL_POWER_V18 = 1, SYSCTL_POWER_V33 = 0

	*((volatile uint32_t *)(&sysctl->power_sel)) |= (1u<<(uint32_t)SYSCTL_POWER_BANK6);
	*((volatile uint32_t *)(&sysctl->power_sel)) |= (1u<<(uint32_t)SYSCTL_POWER_BANK7);

// Power the outputs

	gpiohs->output_en.u32[0] |= (1u<<BLED_0)
							 |  (1u<<BLED_1)
							 |  (1u<<BLED_2)
							 |  (1u<<BLCD_RST)
							 |  (1u<<BLCD_DCX)
							 |  (1u<<BESP32_ENABLE);

// Led off and esp32 on

	gpiohs->output_val.u32[0] |= (1u<<BLED_0);
	gpiohs->output_val.u32[0] |= (1u<<BLED_1);
	gpiohs->output_val.u32[0] |= (1u<<BLED_2);

	gpiohs->output_val.u32[0] |= (1u<<BESP32_ENABLE);
}

/*
 * \brief local_RCU_Configuration
 *
 * - Main PLLs: sysctl_pll_set_freq(SYSCTL_PLL0, 800000000)
 *			    sysctl_pll_set_freq(SYSCTL_PLL1, 160000000)
 *			    sysctl_pll_set_freq(SYSCTL_PLL2,  45158400)
 *
 */
static	void	local_RCU_Configuration(void) {
				sysctl_pll0_t			pll0;
				sysctl_pll1_t			pll1;
				sysctl_pll2_t			pll2;
	volatile	sysctl_general_pll_t	*v_pll_t0, *v_pll_t1, *v_pll_t2;

	v_pll_t0 = (volatile sysctl_general_pll_t *)(&sysctl->pll0);
	v_pll_t1 = (volatile sysctl_general_pll_t *)(&sysctl->pll1);
	v_pll_t2 = (volatile sysctl_general_pll_t *)(&sysctl->pll2);

// 1. Change CPU CLK to XTAL

	sysctl->clk_sel0.aclk_sel = (uint32_t)SYSCTL_SOURCE_IN0 & 0x01u;

// 2. Disable PLLs output

	v_pll_t0->pll_out_en = 0u;
	v_pll_t1->pll_out_en = 0u;
	v_pll_t2->pll_out_en = 0u;

// 3. Turn off PLLs

	v_pll_t0->pll_pwrd = 0u;
	v_pll_t1->pll_pwrd = 0u;
	v_pll_t2->pll_pwrd = 0u;

// 4. Set PLL new value
//    Read the registers from the bus
//    Set registers values (printed by a test)
//    Write registers back to bus

	pll0 = sysctl->pll0;
	pll1 = sysctl->pll1;
	pll2 = sysctl->pll2;

// Values for sysctl_pll_set_freq(SYSCTL_PLL0, 800000000)

	pll0.clkr0  = 0x00u;
	pll0.clkf0  = 0x3Du;
	pll0.clkod0 = 0x01u;
	pll0.bwadj0 = 0x3Du;

// Values for sysctl_pll_set_freq(SYSCTL_PLL1, 160000000)

	pll1.clkr1  = 0x00u;
	pll1.clkf1  = 0x2Au;
	pll1.clkod1 = 0x06u;
	pll1.bwadj1 = 0x2Au;

// Values for sysctl_pll_set_freq(SYSCTL_PLL2,  45158400)

	pll2.clkr2  = 0x00u;
	pll2.clkf2  = 0x19u;
	pll2.clkod2 = 0x0Eu;
	pll2.bwadj2 = 0x19u;

	sysctl->pll0 = pll0;
	sysctl->pll1 = pll1;
	sysctl->pll2 = pll2;

// 5. Power on PLLs

	v_pll_t0->pll_pwrd = 1u;
	v_pll_t1->pll_pwrd = 1u;
	v_pll_t2->pll_pwrd = 1u;
	local_wait_100n(1u);

// 6. Reset PLLs then Release Reset

	v_pll_t0->pll_reset = 0u;
	v_pll_t1->pll_reset = 0u;
	v_pll_t2->pll_reset = 0u;
	v_pll_t0->pll_reset = 1u;
	v_pll_t1->pll_reset = 1u;
	v_pll_t2->pll_reset = 1u;
	local_wait_100n(1u);

	v_pll_t0->pll_reset = 0u;
	v_pll_t1->pll_reset = 0u;
	v_pll_t2->pll_reset = 0u;

// 7. Get lock status, waiting for the PLLs stable

	while ((sysctl->pll_lock.pll_lock0 & 3u) == 0u) {
		sysctl->pll_lock.pll_slip_clear0 = 1u;
	}
	while ((sysctl->pll_lock.pll_lock1 & 1u) == 0u) {
		sysctl->pll_lock.pll_slip_clear1 = 1u;
	}
	while ((sysctl->pll_lock.pll_lock2 & 1u) == 0u) {
		sysctl->pll_lock.pll_slip_clear2 = 1u;
	}

// 8. Enable PLLs output

	v_pll_t0->pll_out_en = 1u;
	v_pll_t1->pll_out_en = 1u;
	v_pll_t2->pll_out_en = 1u;

// 9. Change CPU CLK to PLL

	sysctl->clk_sel0.aclk_sel = (uint32_t)SYSCTL_SOURCE_PLL0 & 0x01u;

// 10. Initialise RTC if enabled

	#ifdef KCALENDAR_WITH_HW_RTC_S

// Enable RTC clock

	sysctl->clk_en_peri.rtc_clk_en = 1u;

// Release RTC from reset

	sysctl->peri_reset.rtc_reset = 0u;

// Waiting for RTC to be ready

	local_wait_100n(100u);
	#endif
}

/*
 * \brief local_wait_100n
 *
 * - Waiting n x 100-ns
 *
 */
static	void	local_wait_100n(uint32_t n) {
	uint32_t	i, j;

	for (j = 0u; j < n; j++) {
		for (i = 0; i < 1000u; i++) { NOP; }
	}
}
