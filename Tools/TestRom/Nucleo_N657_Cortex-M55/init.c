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
; Goal:		Low level init for the uKOS-X Nucleo_N657_Cortex-M55 module.
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

#include	"tests.h"
#include	"linker.h"

// Runtime specific
// ================

// Prototypes

static			void	local_MCO2_Configuration(void);
static			void	local_EnableSRAM(void);
static			void	local_StackLimit_Configuration(void);
static			void	local_PWR_Configuration(void);
static			void	local_GPIO_Configuration(void);
static			void	local_RCC_Configuration(void);
static			void	local_MPU_Configuration(void);
static			void	local_FPE_Configuration(void);
static			void	local_CACHE_Enable(void);
static			void	local_USB_Configuration(void);

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

	local_EnableSRAM();
	local_StackLimit_Configuration();
	local_GPIO_Configuration();
	local_PWR_Configuration();
	local_RCC_Configuration();
	local_MPU_Configuration();
	local_FPE_Configuration();
	local_USB_Configuration();
	local_MCO2_Configuration();
	local_CACHE_Enable();
}

/*
 * \brief local_EnableSRAM
 *
 * - Enable the SRAMs
 *
 */
static	void	local_EnableSRAM(void) {

// Enable SRAM -1, -2, -3, -4, -5, -6

	REG(RCC)->MEMENR  |= RCC_MEMENR_AXISRAM3EN | RCC_MEMENR_AXISRAM4EN | RCC_MEMENR_AXISRAM5EN | RCC_MEMENR_AXISRAM6EN;
	REG(RCC)->AHB2ENR |= RCC_AHB2ENR_RAMCFGEN;
	STRONG_BARRIER;

	REG(RAMCFG)->AXISRAM1CR = 0u;
	REG(RAMCFG)->AXISRAM2CR = 0u;
	REG(RAMCFG)->AXISRAM3CR = 0u;
	REG(RAMCFG)->AXISRAM4CR = 0u;
	REG(RAMCFG)->AXISRAM5CR = 0u;
	REG(RAMCFG)->AXISRAM6CR = 0u;
	STRONG_BARRIER;
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
 * \brief local_FPE_Configuration
 *
 * - Enable the FPE
 *
 */
static	void	local_FPE_Configuration(void) {

// Set CP10 and CP11 Full Access
// Lazy stacking enable

	REG(SCB)->CPACR |= (SCB_CPACR_CP10	| SCB_CPACR_CP11);
	REG(FPE)->FPCCR |= (FPE_FPCCR_ASPEN | FPE_FPCCR_LSPEN);
}

/*
 * \brief local_PWR_Configuration
 *
 * - PWR configuration
 *
 */
static	void	local_PWR_Configuration(void) {

	REG(RCC)->AHB4ENR |= RCC_AHB4ENR_PWREN;
	STRONG_BARRIER;

	REG(PWR)->VOSCR |= PWR_VOSCR_VOS;
	while ((REG(PWR)->VOSCR & PWR_VOSCR_VOSRDY) == 0u) { ; }

	REG(PWR)->SVMCR3 |= PWR_SVMCR3_ASV;
	(void)(REG(PWR)->SVMCR3);
	REG(PWR)->SVMCR3 |= PWR_SVMCR3_VDDIO2SV;
	(void)(REG(PWR)->SVMCR3);
	REG(PWR)->SVMCR3 |= PWR_SVMCR3_VDDIO3SV;
	(void)(REG(PWR)->SVMCR3);
	REG(PWR)->SVMCR1 |= PWR_SVMCR1_VDDIO4SV;
	(void)(REG(PWR)->SVMCR1);
	REG(PWR)->SVMCR2 |= PWR_SVMCR2_VDDIO5SV;
	(void)(REG(PWR)->SVMCR2);

	REG(PWR)->SVMCR1 |= PWR_SVMCR1_VDDIO4VMEN;
	(void)(REG(PWR)->SVMCR1);
	REG(PWR)->SVMCR2 |= PWR_SVMCR2_VDDIO5VMEN;
	(void)(REG(PWR)->SVMCR2);
}

/*
 * \brief local_USB_Configuration
 *
 * - Enable the USB
 *
 */
static	void	local_USB_Configuration(void) {

}

/*
 * \brief local_GPIO_Configuration
 *
 * - GPIO configuration
 *
 */
static	void	local_GPIO_Configuration(void) {

// Turn on all the GPIOx

	REG(RCC)->AHB4ENR |= (RCC_AHB4ENR_GPIOEEN
					   |  RCC_AHB4ENR_GPIOGEN);
	STRONG_BARRIER;

// PE00, IN,  50-MHz, Pull-down	--------	AF15
// PE01, IN,  50-MHz, Pull-down	--------	AF15
// PE02, IN,  50-MHz, Pull-down	--------	AF15
// PE03, IN,  50-MHz, Pull-down	--------	AF15
// PE04, IN,  50-MHz, Pull-down	--------	AF15
// PE05, AL,  50-MHz, Push-pull	USART1_TX	AF07
// PE06, AL,  50-MHz, Pull-up	USART1_RX	AF07
// PE07, IN,  50-MHz, Pull-down	--------	AF15
// PE08, IN,  50-MHz, Pull-down	--------	AF15
// PE09, IN,  50-MHz, Pull-down	--------	AF15
// PE10, IN,  50-MHz, Pull-down	--------	AF15
// PE11, IN,  50-MHz, Pull-down	--------	AF15
// PE12, IN,  50-MHz, Pull-down	--------	AF15
// PE13, IN,  50-MHz, Pull-down	--------	AF15
// PE14, IN,  50-MHz, Pull-down	--------	AF15
// PE15, IN,  50-MHz, Pull-down	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(E,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KAL,KAL,KIN,KIN,KIN,KIN,KIN,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPU,KNO,KPD,KPD,KPD,KPD,KPD,
			  A15,A15,A15,A15,A15,A15,A15,A15,A15,A07,A07,A15,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PG00, OU,  50-MHz, Open-D	GPIO		AF15	Led 3
// PG01, OU,  50-MHz, Push-pull	--------	AF15	(Test analyser)
// PG02, IN,  50-MHz, Pull-down	--------	AF15
// PG03, IN,  50-MHz, Pull-down	--------	AF15
// PG04, IN,  50-MHz, Pull-down	--------	AF15
// PG05, IN,  50-MHz, Pull-down	--------	AF15
// PG06, IN,  50-MHz, Pull-down	--------	AF15
// PG07, IN,  50-MHz, Pull-down	--------	AF15
// PG08, OU,  50-MHz, Open-D	GPIO		AF15	Led 1
// PG09, IN,  50-MHz, Pull-up	--------	AF15
// PG10, OU,  50-MHz, Open-D	GPIO		AF15	Led 2
// PG11, IN,  99-MHz, Pull-down	--------	AF15
// PG12, IN,  99-MHz, Pull-down	--------	AF15
// PG13, IN,  50-MHz, Pull-down	--------	AF15
// PG14, IN,  50-MHz, Pull-down	--------	AF15
// PG15, IN,  50-MHz, Pull-down	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(G,KIN,KIN,KIN,KIN,KIN,KOU,KIN,KOU,KIN,KIN,KIN,KIN,KIN,KIN,KOU,KOU,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPD,KPD,KPD,KPD,KPD,KNO,KPD,KNO,KPD,KPD,KPD,KPD,KPD,KPD,KNO,KNO,
			  A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KOD,KPP,KOD,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KOD,
			  0u, 0u, 0u, 0u, 0u, 1u, 0u, 1u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 1u);

}

/*
 * \brief local_RCC_Configuration
 *
 * Constraints:
 *
 * Fcpu:			800-MHz		sysa_ck (ic1)
 * Fnpu:			800-MHz		sysc_ck (ic6)
 * Faxi:			400-MHz		sysb_ck (ic2)
 * FaxiRAMNPU:		400-MHz		sysd_ck (1c11)
 *
 * Faxi, 400-MHz, FBusMax
 * - Timer group 1, 100-MHz
 * - Timer group 2, 100-MHz
 * - sys_bus2_ck (pclkx), 200-MHz, Faxi / 2
 *		- APB1,2,4,5, 50-MHz, sys_bus2_ck / 8
 *
 * Simple peripherals
 * Fadc12, 		pclk5 50-MHz
 * Fi2cx, 		pclk5 50-MHz (x=1, 2, 3 ,4)
 * Fi3cx, 		pclk5 50-MHz (x=1, 2)
 * Fsaix, 		pclk2 50-MHz (x=1, 2)
 * Fspix, 		pclk4 50-MHz (x=1, 2, 3, 4, 5, 6)
 * Flptimx,		pclk4 50-MHz (x=1, 2, 3, 4, 5)
 * Fusartx,		pclk1 50-MHz (x=1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
 * Flpusartx,	pclk4 50-MHz (x=1, 2)
 * Flpuartx,	pclk4 50-MHz (x=1)
 *
 */
static	void	local_RCC_Configuration(void) {

	REG(RCC)->CR |= RCC_CR_HSION								// Set HSION bit (64-MHz)
				  | RCC_CR_HSEON;								// Set HSEON bit (48-MHz)
	(void)(REG(RCC)->CR);										//

	while ((REG(RCC)->SR & RCC_SR_HSIRDY) == 0u) { ; }			// Waiting for the HSI stable
	while ((REG(RCC)->SR & RCC_SR_HSERDY) == 0u) { ; }			// Waiting for the HSE stable
	STRONG_BARRIER;

// PLL 1, 800-MHz, clocks to the CPU, buses, and storage (XSPI, SDMMC)
// -------------------------------------------------------------------

// FVCO min..max, 800-MHz..3200-MHz
// For f(ck in) = 64-MHz (HSI)
// f(vco) = f(ck in) * (N / M)
// f(vco) = 1600-MHz, N/M = 25
// N = 125, M = 5

	REG(RCC)->PLL1CFGR1 = (0u   * RCC_PLL1CFGR1_PLL1SEL_0)		// f(input) HSI
						| (0u   * RCC_PLL1CFGR1_PLL1BYP)		// No bypass
						| (5u   * RCC_PLL1CFGR1_PLL1DIVM_0)		// M = 5
						| (125u * RCC_PLL1CFGR1_PLL1DIVN_0);	// N = 125

	REG(RCC)->PLL1CFGR2 = 0u;									// No fractional

	REG(RCC)->PLL1CFGR3 = RCC_PLL1CFGR3_PLL1PDIVEN				// Post div activate
						| (2u * RCC_PLL1CFGR3_PLL1PDIV1_0)		//
						| (1u * RCC_PLL1CFGR3_PLL1PDIV2_0)		// VCO / 2
						| (0u * RCC_PLL1CFGR3_PLL1MODSPR_0)		//
						| (0u * RCC_PLL1CFGR3_PLL1MODDIV_0)		//
						| (0u * RCC_PLL1CFGR3_PLL1MODSPRDW)		//
						| (0u * RCC_PLL1CFGR3_PLL1MODDSEN)		//
						| (1u * RCC_PLL1CFGR3_PLL1MODSSDIS)		//
						| (0u * RCC_PLL1CFGR3_PLL1DACEN)		//
						| (1u * RCC_PLL1CFGR3_PLL1MODSSRST);	//

	REG(RCC)->CR |= RCC_CR_PLL1ON;								// PLL1 on
	(void)(REG(RCC)->CR);										//
	while ((REG(RCC)->SR & RCC_SR_PLL1RDY) == 0u) { ; }			// Waiting for the PLL 1 stable

// PLL 2, 800-MHz, clocks to NPU and audio peripherals
// ---------------------------------------------------

// FVCO min..max, 800-MHz..3200-MHz
// For f(ck in) = 64-MHz (HSI)
// f(vco) = f(ck in) * (N / M)
// f(vco) = 1600-MHz, N/M = 25
// N = 125, M = 5

	REG(RCC)->PLL2CFGR1 = (0u   * RCC_PLL2CFGR1_PLL2SEL_0)		// f(input) HSI
						| (0u   * RCC_PLL2CFGR1_PLL2BYP)		// No bypass
						| (5u   * RCC_PLL2CFGR1_PLL2DIVM_0)		// M = 5
						| (125u * RCC_PLL2CFGR1_PLL2DIVN_0);	// N = 125

	REG(RCC)->PLL2CFGR2 = 0u;									// No fractional

	REG(RCC)->PLL2CFGR3 = RCC_PLL2CFGR3_PLL2PDIVEN				// Post div activate
						| (2u * RCC_PLL2CFGR3_PLL2PDIV1_0)		//
						| (1u * RCC_PLL2CFGR3_PLL2PDIV2_0)		// VCO / 2
						| (0u * RCC_PLL2CFGR3_PLL2MODSPR_0)		//
						| (0u * RCC_PLL2CFGR3_PLL2MODDIV_0)		//
						| (0u * RCC_PLL2CFGR3_PLL2MODSPRDW)		//
						| (0u * RCC_PLL2CFGR3_PLL2MODDSEN)		//
						| (1u * RCC_PLL2CFGR3_PLL2MODSSDIS)		//
						| (0u * RCC_PLL2CFGR3_PLL2DACEN)		//
						| (1u * RCC_PLL2CFGR3_PLL2MODSSRST);	//

	REG(RCC)->CR |= RCC_CR_PLL2ON;								// PLL2 on
	(void)(REG(RCC)->CR);										//
	while ((REG(RCC)->SR & RCC_SR_PLL2RDY) == 0u) { ; }			// Waiting for the PLL 2 stable

// PLL 3, 400-MHz, clocks to CACHEAXI RAM and Ethernet
// ---------------------------------------------------

// FVCO min..max, 800-MHz..3200-MHz
// For f(ck in) = 64-MHz (HSI)
// f(vco) = f(ck in) * (N / M)
// f(vco) = 1600-MHz, N/M = 25
// N = 125, M = 5

	REG(RCC)->PLL3CFGR1 = (0u   * RCC_PLL3CFGR1_PLL3SEL_0)		// f(input) HSI
						| (0u   * RCC_PLL3CFGR1_PLL3BYP)		// No bypass
						| (5u   * RCC_PLL3CFGR1_PLL3DIVM_0)		// M = 5
						| (125u * RCC_PLL3CFGR1_PLL3DIVN_0);	// N = 125

	REG(RCC)->PLL3CFGR2 = 0u;									// No fractional

	REG(RCC)->PLL3CFGR3 = RCC_PLL3CFGR3_PLL3PDIVEN				// Post div activate
						| (4u * RCC_PLL3CFGR3_PLL3PDIV1_0)		//
						| (1u * RCC_PLL3CFGR3_PLL3PDIV2_0)		// VCO / 4
						| (0u * RCC_PLL3CFGR3_PLL3MODSPR_0)		//
						| (0u * RCC_PLL3CFGR3_PLL3MODDIV_0)		//
						| (0u * RCC_PLL3CFGR3_PLL3MODSPRDW)		//
						| (0u * RCC_PLL3CFGR3_PLL3MODDSEN)		//
						| (1u * RCC_PLL3CFGR3_PLL3MODSSDIS)		//
						| (0u * RCC_PLL3CFGR3_PLL3DACEN)		//
						| (1u * RCC_PLL3CFGR3_PLL3MODSSRST);	//

	REG(RCC)->CR |= RCC_CR_PLL3ON;								// PLL3 on
	(void)(REG(RCC)->CR);										//
	while ((REG(RCC)->SR & RCC_SR_PLL3RDY) == 0u) { ; }			// Waiting for the PLL 3 stable

// PLL 4, 400-MHz, clocks to display, camera, FDCAN, and other peripherals
// -----------------------------------------------------------------------

// FVCO min..max, 800-MHz..3200-MHz
// For f(ck in) = 64-MHz (HSI)
// f(vco) = f(ck in) * (N / M)
// f(vco) = 1600-MHz, N/M = 25
// N = 125, M = 5

	REG(RCC)->PLL4CFGR1 = (0u   * RCC_PLL4CFGR1_PLL4SEL_0)		// f(input) HSI
						| (0u   * RCC_PLL4CFGR1_PLL4BYP)		// No bypass
						| (5u   * RCC_PLL4CFGR1_PLL4DIVM_0)		// M = 5
						| (125u * RCC_PLL4CFGR1_PLL4DIVN_0);	// N = 125

	REG(RCC)->PLL4CFGR2 = 0u;									// No fractional

	REG(RCC)->PLL4CFGR3 = RCC_PLL4CFGR3_PLL4PDIVEN				// Post div activate
						| (4u * RCC_PLL4CFGR3_PLL4PDIV1_0)		//
						| (1u * RCC_PLL4CFGR3_PLL4PDIV2_0)		// VCO / 4
						| (0u * RCC_PLL4CFGR3_PLL4MODSPR_0)		//
						| (0u * RCC_PLL4CFGR3_PLL4MODDIV_0)		//
						| (0u * RCC_PLL4CFGR3_PLL4MODSPRDW)		//
						| (0u * RCC_PLL4CFGR3_PLL4MODDSEN)		//
						| (1u * RCC_PLL4CFGR3_PLL4MODSSDIS)		//
						| (0u * RCC_PLL4CFGR3_PLL4DACEN)		//
						| (1u * RCC_PLL4CFGR3_PLL4MODSSRST);	//

	REG(RCC)->CR |= RCC_CR_PLL4ON;								// PLL4 on
	(void)(REG(RCC)->CR);										//
	while ((REG(RCC)->SR & RCC_SR_PLL4RDY) == 0u) { ; }			// Waiting for the PLL 4 stable

// Muxes
// -----

// System clock (IC1 mux)

	REG(RCC)->IC1CFGR = (0u * RCC_IC1CFGR_IC1SEL_0)				// PLL1
					  | ((1u - 1u) * RCC_IC1CFGR_IC1INT_0);		// IC1 = PLL1 / 1, ~800-MHz
	STRONG_BARRIER;												//
	REG(RCC)->DIVENR |= RCC_DIVENR_IC1EN;						//
	(void)(REG(RCC)->DIVENR);									//

// System clock (IC2 mux)

	REG(RCC)->IC2CFGR = (3u * RCC_IC2CFGR_IC2SEL_0)				// PLL4
					  | ((1u - 1u) * RCC_IC2CFGR_IC2INT_0);		// IC2 = PLL4 / 1, ~400_MHz
	STRONG_BARRIER;												//
	REG(RCC)->DIVENR |= RCC_DIVENR_IC2EN;						//
	(void)(REG(RCC)->DIVENR);									//

// System clock (IC15 mux) (for MCO2)

	REG(RCC)->IC15CFGR = (0u * RCC_IC15CFGR_IC15SEL_0)			// PLL1
					   | ((2u - 1u) * RCC_IC15CFGR_IC15INT_0);	// IC15 = PLL1 / 2, ~400-MHz
	STRONG_BARRIER;												//
	REG(RCC)->DIVENR |= RCC_DIVENR_IC15EN;						//
	(void)(REG(RCC)->DIVENR);									//

// System clock (IC20 mux) (for MCO2)

	REG(RCC)->IC20CFGR = (2u * RCC_IC20CFGR_IC20SEL_0)			// PLL3
					   | ((10u - 1u) * RCC_IC20CFGR_IC20INT_0);	// IC20 = PLL3 / 10, ~40-MHz
	STRONG_BARRIER;												//
	REG(RCC)->DIVENR |= RCC_DIVENR_IC20EN;						//
	(void)(REG(RCC)->DIVENR);									//

// System clock (IC9 mux) (for ....)

	REG(RCC)->IC9CFGR = (2u * RCC_IC9CFGR_IC9SEL_0)				// PLL3
					  | ((4u - 1u) * RCC_IC9CFGR_IC9INT_0);		// IC9 = PLL3 / 4, ~100-MHz
	STRONG_BARRIER;												//
	REG(RCC)->DIVENR |= RCC_DIVENR_IC9EN;						//
	(void)(REG(RCC)->DIVENR);									//

// Bus speeds
// ----------

// CPU & AXI clocks
// - CPU -> 800-MHz (sysa_ck)
// - SYS -> 400-MHz (sysb_ck)
//					(sysc_ck) not used
//					(sysd_ck) not used
// - PERCK -> HSI

// Bus peripheral clocks
// - Timers					-> 100-MHz
// - HPRE					-> 100-MHz
// - PBx (x, 1, 2, 4, 5)	-> 100-MHz
// !!! Silicon limitation. PBx HAS to be = to AHB
// !!! ES0620 - Rev 1: errata 2.2.1 Incorrect APB prescaler setting

	REG(RCC)->CFGR2 = (KTIMPRE * RCC_CFGR2_TIMPRE_0)			// sys_bus_ck / 4
					| (KHPRE   * RCC_CFGR2_HPRE_0)				// sys_bus_ck / 4
					| (KPPRE1  * RCC_CFGR2_PPRE1_0)				// sys_bus_ck2 / 1
					| (KPPRE2  * RCC_CFGR2_PPRE2_0)				// sys_bus_ck2 / 1
					| (KPPRE4  * RCC_CFGR2_PPRE4_0)				// sys_bus_ck2 / 1
					| (KPPRE5  * RCC_CFGR2_PPRE5_0);			// sys_bus_ck2 / 1
	STRONG_BARRIER;
	(void)(REG(RCC)->CFGR2);

	REG(RCC)->CFGR1 = (3u * RCC_CFGR1_CPUSW_0)					// IC1 (PLL1 / 1) as a CPU clock
					| (3u * RCC_CFGR1_SYSSW_0);					// IC2 (PLL4 / 2) as a SYS clock
	STRONG_BARRIER;
	(void)(REG(RCC)->CFGR1);

	cmns_wait(10000);
	REG(RCC)->CCIPR7 = (0u * RCC_CCIPR7_PERSEL_0);				// per_ck (periph kernel = HSI)
}

/*
 * \brief local_MPU_Configuration
 *
 * - Initialise the MPU for the different
 *   memory regions of the system
 *
 */
static	void	local_MPU_Configuration(void) {

}

/*
 * \brief local_MCO2_Configuration
 *
 * - Select of the clocks via MCO1-2
 *
 */
static	void	local_MCO2_Configuration(void) {
	volatile	uint32_t	value;

	REG(RCC)->MISCENR |= RCC_MISCENR_MCO2EN;
	STRONG_BARRIER;

// PA08, MCO1 (not usable)
// PC09, MCO2 (maybe blocked by OTP124)

	value = REG(RCC)->CCIPR5 & ((0xFFF8u<<19u) | (0x1u<<11u) | (0x1u<<3u));

// MCO2
//
// n = 0, hsi_div_ck	(OK, ~64-MHz !!!)
// n = 1, lse_ck		(KO)
// n = 2, msi_ck		(KO)
// n = 3, lsi_ck		(OK, ~32-KHz !!!)
// n = 4, hse_ck		(OK, ~48-MHz !!!)
// n = 5, ic15_ck		(OK, ~300-MHz !!!) = pll1 / 2  -> pll1 = 600-MHz
// n = 6, ic20_ck		(OK, ~30-MHz !!!)  = pll3 / 10 -> pll3 = 300-MHz
// n = 7, sysb_ck		(OK, ~300-MHz !!!) = pll4

#define	n	7u

	value |= (n			 * RCC_CCIPR5_MCO2SEL_0)	//
		   | ((10u - 1u) * RCC_CCIPR5_MCO2PRE_0);	// Clock / 10
	REG(RCC)->CCIPR5 = value;						//
}

/*
 * \brief local_CACHE_Enable
 *
 * - Enable the L1 instruction & the data caches
 *
 */
static	void	local_CACHE_Enable(void) {

	#if 1
	REG(MEMSYSCTL)->MSCR |= MEMSYSCTL_MSCR_DCACTIVE | MEMSYSCTL_MSCR_ICACTIVE;

	cache_I_Invalidate();
	cache_I_Enable();

	cache_D_Invalidate();
	cache_D_Enable();
	#endif
	
}
