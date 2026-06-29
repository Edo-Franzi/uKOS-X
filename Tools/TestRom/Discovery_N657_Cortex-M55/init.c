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
; Goal:		Low level init for the uKOS-X Discovery_N657_Cortex-M55 module.
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
	REG(PWR)->SVMCR3 |= (PWR_SVMCR3_VDDIO2SV | PWR_SVMCR3_VDDIO2VRSEL);
	(void)(REG(PWR)->SVMCR3);
	REG(PWR)->SVMCR3 |= (PWR_SVMCR3_VDDIO3SV | PWR_SVMCR3_VDDIO3VRSEL);
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

	REG(RCC)->AHB4ENR |= (RCC_AHB4ENR_GPIOAEN
					   |  RCC_AHB4ENR_GPIOBEN
					   |  RCC_AHB4ENR_GPIOCEN
					   |  RCC_AHB4ENR_GPIODEN
					   |  RCC_AHB4ENR_GPIOEEN
					   |  RCC_AHB4ENR_GPIOFEN
					   |  RCC_AHB4ENR_GPIOGEN
					   |  RCC_AHB4ENR_GPIOHEN
					   |  RCC_AHB4ENR_GPIOOEN
					   |  RCC_AHB4ENR_GPIOQEN);
	(void)(REG(RCC)->AHB4ENR);

// Init all the GPIO A, B, C, D, E, F, G, H, I, J

// PA00, AL,  99-MHz, Push-pull	RGB.G3		AF14
// PA01, AL,  99-MHz, Push-pull	RGB.G2		AF15
// PA02, AL,  99-MHz, Push-pull	RGB.B7		AF15
// PA03, IN,  50-MHz, Pull-up	--------	AF15
// PA04, IN,  50-MHz, Pull-up	--------	AF15
// PA05, IN,  50-MHz, Pull-up	--------	AF15
// PA06, IN,  50-MHz, Pull-up	--------	AF15
// PA07, AL,  99-MHz, Push-pull	RGB.B1		AF15
// PA08, AL,  99-MHz, Push-pull	RGB.B6		AF15
// PA09, IN,  50-MHz, Pull-up	--------	AF15
// PA10, IN,  50-MHz, Pull-up	--------	AF15
// PA11, IN,  50-MHz, Pull-up	--------	AF15
// PA12, IN,  50-MHz, Pull-up	--------	AF15
// PA13, AL,  50-MHz, Pull-up 	TMS			AF00
// PA14, AL,  50-MHz, Pull-down TCK			AF00
// PA15, AL,  99-MHz, Push-pull	RGB.R5		AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(A,KAL,KAL,KAL,KIN,KIN,KIN,KIN,KAL,KAL,KIN,KIN,KIN,KIN,KAL,KAL,KAL,
			  K99,K50,K50,K50,K50,K50,K50,K99,K99,K50,K50,K50,K50,K99,K99,K99,
			  KNO,KPU,KPU,KPU,KPU,KPU,KPU,KNO,KNO,KPU,KPU,KPU,KPU,KNO,KNO,KNO,
			  A15,A00,A00,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A14,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PB00, IN,  50-MHz, Pull-down	--------	AF15
// PB01, IN,  50-MHz, Pull-down	--------	AF15
// PB02, AL,  99-MHz, Push-pull	RGB.B2		AF14
// PB03, IN,  50-MHz, Pull-down	--------	AF15
// PB04, AL,  99-MHz, Push-pull	RGB.R3		AF14
// PB05, IN,  50-MHz, Pull-down	--------	AF15
// PB06, IN,  50-MHz, Pull-down	--------	AF15
// PB07, IN,  50-MHz, Pull-down	--------	AF15
// PB08, IN,  50-MHz, Pull-down	--------	AF15
// PB09, IN,  50-MHz, Pull-down	--------	AF15
// PB10, IN,  50-MHz, Pull-down	--------	AF15
// PB11, AL,  99-MHz, Push-pull	RGB.G6		AF14
// PB12, AL,  99-MHz, Push-pull	RGB.G5		AF14
// PB13, AL,  99-MHz, Push-pull	LCD_CLK		AF14
// PB14, AL,  99-MHz, Push-pull	LCD_HSYNC 	AF14
// PB15, AL,  99-MHz, Push-pull	RGB.G4		AF14

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(B,KAL,KAL,KAL,KAL,KAL,KIN,KIN,KIN,KIN,KIN,KIN,KAL,KIN,KAL,KIN,KIN,
			  K99,K99,K99,K99,K99,K50,K50,K50,K50,K50,K50,K99,K50,K99,K50,K50,
			  KNO,KNO,KNO,KNO,KNO,KPD,KPD,KPD,KPD,KPD,KPD,KNO,KPD,KNO,KPD,KPD,
			  A14,A14,A14,A14,A14,A15,A15,A15,A15,A15,A15,A14,A15,A14,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PC00, AL,  99-MHz, Push-pull	SDMMC1_D2	AF11
// PC01, AL,  50-MHz, Open-D	I2C1_SDA	AF04
// PC02, AL,  99-MHz, Push-pull	SDMMC1_CLK	AF11
// PC03, AL,  99-MHz, Push-pull	SDMMC1_CMD	AF11
// PC04, AL,  99-MHz, Push-pull	SDMMC1_D0	AF11
// PC05, AL,  99-MHz, Push-pull	SDMMC1_D1	AF11
// PC06, IN,  50-MHz, Pull-down	--------	AF15
// PC07, IN,  50-MHz, Pull-down	--------	AF15
// PC08, IN,  50-MHz, Pull-down	--------	AF15
// PC09, AL,  50-MHz, Pull-down	MCO2		AF00
// PC10, IN,  50-MHz, Pull-down	--------	AF15
// PC11, IN,  50-MHz, Pull-down	--------	AF15
// PC12, IN,  50-MHz, Pull-down	--------	AF15
// PC13, IN,  50-MHz, Pull-down	GPIO		AF15	BSW_0
// PC14, IN,  50-MHz, Pull-down	--------	AF15
// PC15, IN,  50-MHz, Pull-down	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(C,KIN,KIN,KIN,KIN,KIN,KIN,KAL,KIN,KIN,KIN,KAL,KAL,KAL,KAL,KAL,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K99,K99,K99,K99,K50,K99,
			  KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPU,KPU,KPU,KPU,KPU,KPU,
			  A15,A15,A15,A15,A15,A15,A00,A15,A15,A15,A11,A11,A11,A11,A04,A11,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KOD,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u);

// PD00, IN,  50-MHz, Pull-down	--------	AF15
// PD01, IN,  50-MHz, Pull-down	--------	AF15
// PD02, IN,  50-MHz, Pull-down	--------	AF15
// PD03, IN,  50-MHz, Pull-down	--------	AF15
// PD04, AL,  50-MHz, Open-D	I2C2_SDA	AF04
// PD05, IN,  50-MHz, Pull-down	--------	AF15
// PD06, IN,  50-MHz, Pull-down	--------	AF15
// PD07, IN,  50-MHz, Pull-down	--------	AF15
// PD08, AL,  99-MHz, Push-pull	RGB.R7		AF14
// PD09, AL,  99-MHz, Push-pull	RGB.R1		AF14
// PD10, IN,  50-MHz, Pull-down	--------	AF15
// PD11, IN,  50-MHz, Pull-down	--------	AF15
// PD12, IN,  50-MHz, Pull-down	--------	AF15
// PD13, IN,  50-MHz, Pull-down	--------	AF15
// PD14, AL,  50-MHz, Open-D	I2C2_SCL	AF04
// PD15, AL,  99-MHz, Push-pull	RGB.R2		AF14

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(D,KAL,KAL,KIN,KIN,KIN,KIN,KAL,KAL,KIN,KIN,KIN,KAL,KIN,KIN,KIN,KIN,
			  K99,K50,K50,K50,K50,K50,K99,K99,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KPD,KPD,KPD,KPD,KPD,KNO,KNO,KPD,KPD,KPD,KPU,KPD,KPD,KPD,KPD,
			  A14,A10,A15,A15,A15,A15,A14,A14,A15,A15,A15,A04,A15,A15,A15,A15,
			  KPP,KOD,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KOD,KPP,KPP,KPP,KPP,
			  0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u);

// PE00, IN,  50-MHz, Pull-down	--------	AF15	TAMP
// PE01, OU,  50-MHz, Push_pul	--------	AF15	LCD_RST
// PE02, IN,  50-MHz, Pull-down	--------	AF15
// PE03, IN,  50-MHz, Pull-down	--------	AF15
// PE04, AL,  99-MHz, Push-pull	SDMMC1_D3	AF11
// PE05, AL,  50-MHz, Push-pull	USART1_TX	AF07
// PE06, AL,  50-MHz, Pull-up	USART1_RX	AF07
// PE07, IN,  50-MHz, Pull-down	--------	AF15
// PE08, IN,  50-MHz, Pull-down	--------	AF15
// PE09, IN,  50-MHz, Pull-down	--------	AF15
// PE10, IN,  50-MHz, Pull-down	--------	AF15
// PE11, AL,  50-MHz, Push-pull	LCD_VSYNC	AF14
// PE12, IN,  50-MHz, Pull-down	--------	AF15
// PE13, IN,  50-MHz, Pull-down	--------	AF15
// PE14, IN,  50-MHz, Pull-down	--------	AF15
// PE15, OU,  50-MHz, Push-pull	GPIO		AF15	Led 0

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(E,KOU,KIN,KIN,KIN,KAL,KIN,KIN,KIN,KIN,KAL,KAL,KAL,KIN,KIN,KOU,KIN,
			  K50,K50,K50,K50,K99,K50,K50,K50,K50,K50,K50,K99,K50,K50,K50,K50,
			  KNO,KPD,KPD,KPD,KNO,KPD,KPD,KPD,KPD,KPU,KNO,KPU,KPD,KPD,KNO,KPD,
			  A15,A15,A15,A15,A14,A15,A15,A15,A15,A07,A07,A11,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PF00, IN,  50-MHz, Pull-down	--------	AF15
// PF01, IN,  50-MHz, Pull-down	--------	AF15
// PF02, IN,  50-MHz, Pull-down	--------	AF15
// PF03, IN,  50-MHz, Pull-down	--------	AF15
// PF04, OU,  50-MHz, Push-pull	OVERDRIVE	AF15
// PF05, IN,  50-MHz, Pull-down	--------	AF15
// PF06, IN,  50-MHz, Pull-down	--------	AF15
// PF07, IN,  50-MHz, Pull-down	--------	AF15
// PF08, IN,  50-MHz, Pull-down	--------	AF15
// PF09, IN,  50-MHz, Pull-down	--------	AF15
// PF10, IN,  50-MHz, Pull-down	--------	AF15
// PF11, IN,  50-MHz, Pull-down	--------	AF15
// PF12, IN,  50-MHz, Pull-down	--------	AF15
// PF13, IN,  50-MHz, Pull-down	--------	AF15
// PF14, IN,  50-MHz, Pull-down	--------	AF15
// PF15, IN,  50-MHz, Pull-down	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(F,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KOU,KIN,KIN,KIN,KIN,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KNO,KPD,KPD,KPD,KPD,
			  A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u);

// PG00, AL,  99-MHz, Push-pull	RGB.R0		AF14
// PG01, AL,  99-MHz, Push-pull	RGB.G1		AF14
// PG02, IN,  50-MHz, Pull-down	--------	AF15
// PG03, IN,  50-MHz, Pull-down	--------	AF15
// PG04, IN,  50-MHz, Pull-down	--------	AF15
// PG05, IN,  50-MHz, Pull-down	--------	AF15
// PG06, AL,  99-MHz, Push-pull	RGB.B3		AF14
// PG07, IN,  50-MHz, Pull-down	--------	AF15
// PG08, AL,  99-MHz, Push-pull	RGB.G7		AF14
// PG09, IN,  50-MHz, Pull-up	--------	AF15
// PG10, OU,  50-MHz, Open-D	GPIO		AF15	Led 2
// PG11, AL,  99-MHz, Push-pull	RGB.R6		AF14
// PG12, AL,  99-MHz, Push-pull	RGB.G0		AF14
// PG13, AL,  99-MHz, Push-pull	LCD_DE		AF14
// PG14, IN,  50-MHz, Pull-down	--------	AF15
// PG15, AL,  99-MHz, Push-pull	RGB.B0		AF14

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(G,KAL,KIN,KAL,KAL,KAL,KOU,KIN,KAL,KIN,KAL,KIN,KIN,KIN,KIN,KAL,KAL,
			  K99,K50,K99,K99,K99,K50,K50,K99,K50,K99,K50,K50,K50,K50,K99,K99,
			  KNO,KPD,KNO,KNO,KNO,KNO,KPD,KNO,KPD,KNO,KPD,KPD,KPD,KPD,KNO,KNO,
			  A14,A15,A14,A14,A14,A15,A15,A14,A15,A14,A15,A15,A15,A15,A14,A14,
			  KPP,KPP,KPP,KPP,KPP,KOD,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PH00, IN,  50-MHz, Pull-down	--------	AF15
// PH01, IN,  50-MHz, Pull-down	--------	AF15
// PH02, IN,  50-MHz, Pull-down	--------	AF15
// PH03, AL,  99-MHz, Push-pull	RGB.B4		AF14
// PH04, AL,  99-MHz, Push-pull	RGB.R4		AF14
// PH05, IN,  50-MHz, Pull-down	--------	AF15
// PH06, AL,  99-MHz, Push-pull	RGB.B5		AF14
// PH07, IN,  50-MHz, Pull-down	--------	AF15
// PH08, IN,  50-MHz, Pull-down	--------	AF15
// PH09, AL,  50-MHz, Open-D	I2C1_SCL	AF04
// PH10, IN,  50-MHz, Pull-down	--------	AF15
// PH11, IN,  50-MHz, Pull-down	--------	AF15
// PH12, IN,  50-MHz, Pull-down	--------	AF15
// PH13, IN,  50-MHz, Pull-down	--------	AF15
// PH14, IN,  50-MHz, Pull-down	--------	AF15
// PH15, IN,  50-MHz, Pull-down	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(H,KIN,KIN,KIN,KIN,KIN,KIN,KAL,KIN,KIN,KAL,KIN,KAL,KAL,KIN,KIN,KIN,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K99,K50,K99,K99,K50,K50,K50,
			  KPD,KPD,KPD,KPD,KPD,KPD,KPU,KPD,KPD,KNO,KPD,KNO,KNO,KPD,KPD,KPD,
			  A15,A15,A15,A15,A15,A15,A04,A15,A15,A14,A15,A14,A14,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KOD,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PO00, IN,  50-MHz, Pull-down	--------	AF15
// PO01, OU,  50-MHz, Push-pull	GPIO		AF15	Led 1
// PO02, IN,  50-MHz, Pull-down	--------	AF15
// PO03, IN,  50-MHz, Pull-down	--------	AF15
// PO04, IN,  50-MHz, Pull-down	--------	AF15
// PO05, IN,  50-MHz, Pull-down	--------	AF15
// PO06, IN,  50-MHz, Pull-down	--------	AF15
// PO07, IN,  50-MHz, Pull-down	--------	AF15
// PO08, IN,  50-MHz, Pull-down	--------	AF15
// PO09, IN,  50-MHz, Pull-down	--------	AF15
// PO10, IN,  50-MHz, Pull-down	--------	AF15
// PO11, IN,  50-MHz, Pull-down	--------	AF15
// PO12, IN,  50-MHz, Pull-down	--------	AF15
// PO13, IN,  50-MHz, Pull-down	--------	AF15
// PO14, IN,  50-MHz, Pull-down	--------	AF15
// PO15, IN,  50-MHz, Pull-down	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(O,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KOU,KIN,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KNO,KPD,
			  A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PQ00, IN,  50-MHz, Pull-down	--------	AF15
// PQ01, IN,  50-MHz, Pull-down	--------	AF15
// PQ02, IN,  50-MHz, Pull-down	--------	AF15
// PQ03, OU,  50-MHz, Pull-down	GPIO		AF15	LCD_POWER
// PQ04, IN,  50-MHz, Pull-down	--------	AF15
// PQ05, IN,  50-MHz, Pull-down	--------	AF15
// PQ06, IN,  50-MHz, Pull-down	--------	AF15
// PQ07, IN,  50-MHz, Pull-down	--------	AF15
// PQ08, IN,  50-MHz, Pull-down	--------	AF15
// PQ09, IN,  50-MHz, Pull-down	--------	AF15
// PQ10, IN,  50-MHz, Pull-down	--------	AF15
// PQ11, IN,  50-MHz, Pull-down	--------	AF15
// PQ12, IN,  50-MHz, Pull-down	--------	AF15
// PQ13, IN,  50-MHz, Pull-down	--------	AF15
// PQ14, IN,  50-MHz, Pull-down	--------	AF15
// PQ15, IN,  50-MHz, Pull-down	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(Q,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KOU,KIN,KIN,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KNO,KPD,KPD,
			  A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);
}

/*
 * \brief local_RCC_Configuration
 *
 * Constraints:
 *
 * Fcpu:			600-MHz		sysa_ck (ic1)
 * Fnpu:			600-MHz		sysc_ck (ic6)
 * Faxi:			300-MHz		sysb_ck (ic2)
 * FaxiRAMNPU:		300-MHz		sysd_ck (1c11)
 *
 * Faxi, 400-MHz, FBusMax
 * - Timer group 1, 75-MHz
 * - Timer group 2, 75-MHz
 * - sys_bus2_ck (pclkx), 150-MHz, Faxi / 2
 *		- APB1,2,4,5, 50-MHz, sys_bus2_ck / 8
 *
 * Simple peripherals
 * Fadc12, 		pclk5 37-MHz
 * Fi2cx, 		pclk5 37-MHz (x=1, 2, 3 ,4)
 * Fi3cx, 		pclk5 37-MHz (x=1, 2)
 * Fsaix, 		pclk2 37-MHz (x=1, 2)
 * Fspix, 		pclk4 37-MHz (x=1, 2, 3, 4, 5, 6)
 * Flptimx,		pclk4 37-MHz (x=1, 2, 3, 4, 5)
 * Fusartx,		pclk1 37-MHz (x=1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
 * Flpusartx,	pclk4 37-MHz (x=1, 2)
 * Flpuartx,	pclk4 37-MHz (x=1)
 *
 */
static	void	local_RCC_Configuration(void) {

	REG(RCC)->CR |= RCC_CR_HSION								// Set HSION bit (64-MHz)
				  | RCC_CR_HSEON;								// Set HSEON bit (48-MHz)
	(void)(REG(RCC)->CR);										//

	while ((REG(RCC)->SR & RCC_SR_HSIRDY) == 0u) { ; }			// Waiting for the HSI stable
	while ((REG(RCC)->SR & RCC_SR_HSERDY) == 0u) { ; }			// Waiting for the HSE stable
	STRONG_BARRIER;

	cmns_wait(10000);

// PLL 1, 608-MHz, clocks to the CPU, buses, and storage (XSPI, SDMMC)
// -------------------------------------------------------------------

// FVCO min..max, 800-MHz..3200-MHz
// For f(ck in) = 64-MHz (HSI)
// f(vco) = f(ck in) * (N / M)
// f(vco) = 1216-MHz, N/M = 19
// N = 95, M = 5

	REG(RCC)->PLL1CFGR1 = (0u  * RCC_PLL1CFGR1_PLL1SEL_0)		// f(input) HSI
						| (0u  * RCC_PLL1CFGR1_PLL1BYP)			// No bypass
						| (5u  * RCC_PLL1CFGR1_PLL1DIVM_0)		// M = 5
						| (95u * RCC_PLL1CFGR1_PLL1DIVN_0);		// N = 95

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

// PLL 2, 608-MHz, clocks to NPU and audio peripherals
// ---------------------------------------------------

// FVCO min..max, 800-MHz..3200-MHz
// For f(ck in) = 64-MHz (HSI)
// f(vco) = f(ck in) * (N / M)
// f(vco) = 1216-MHz, N/M = 19
// N = 95, M = 5

	REG(RCC)->PLL2CFGR1 = (0u  * RCC_PLL2CFGR1_PLL2SEL_0)		// f(input) HSI
						| (0u  * RCC_PLL2CFGR1_PLL2BYP)			// No bypass
						| (5u  * RCC_PLL2CFGR1_PLL2DIVM_0)		// M = 5
						| (95u * RCC_PLL2CFGR1_PLL2DIVN_0);		// N = 95

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

// PLL 3, 300-MHz, clocks to CACHEAXI RAM and Ethernet
// ---------------------------------------------------

// FVCO min..max, 800-MHz..3200-MHz
// For f(ck in) = 64-MHz (HSI)
// f(vco) = f(ck in) * (N / M)
// f(vco) = 1216-MHz, N/M = 19
// N = 95, M = 5

	REG(RCC)->PLL3CFGR1 = (0u  * RCC_PLL3CFGR1_PLL3SEL_0)		// f(input) HSI
						| (0u  * RCC_PLL3CFGR1_PLL3BYP)			// No bypass
						| (5u  * RCC_PLL3CFGR1_PLL3DIVM_0)		// M = 5
						| (95u * RCC_PLL3CFGR1_PLL3DIVN_0);		// N = 95

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

// PLL 4, 300-MHz, clocks to display, camera, FDCAN, and other peripherals
// -----------------------------------------------------------------------

// FVCO min..max, 800-MHz..3200-MHz
// For f(ck in) = 64-MHz (HSI)
// f(vco) = f(ck in) * (N / M)
// f(vco) = 1216-MHz, N/M = 19
// N = 95, M = 5

	REG(RCC)->PLL4CFGR1 = (0u  * RCC_PLL4CFGR1_PLL4SEL_0)		// f(input) HSI
						| (0u  * RCC_PLL4CFGR1_PLL4BYP)			// No bypass
						| (5u  * RCC_PLL4CFGR1_PLL4DIVM_0)		// M = 5
						| (95u * RCC_PLL4CFGR1_PLL4DIVN_0);		// N = 95

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
					  | ((1u - 1u) * RCC_IC1CFGR_IC1INT_0);		// IC1 = PLL1 / 1, ~600-MHz
	STRONG_BARRIER;												//
	REG(RCC)->DIVENR |= RCC_DIVENR_IC1EN;						//
	(void)(REG(RCC)->DIVENR);									//

// System clock (IC2 mux)

	REG(RCC)->IC2CFGR = (3u * RCC_IC2CFGR_IC2SEL_0)				// PLL4
					  | ((2u - 1u) * RCC_IC2CFGR_IC2INT_0);		// IC2 = PLL4 / 2, ~150_MHz
	STRONG_BARRIER;												//
	REG(RCC)->DIVENR |= RCC_DIVENR_IC2EN;						//
	(void)(REG(RCC)->DIVENR);									//

// System clock (IC15 mux) (for MCO2)

	REG(RCC)->IC15CFGR = (0u * RCC_IC15CFGR_IC15SEL_0)			// PLL1
					   | ((2u - 1u) * RCC_IC15CFGR_IC15INT_0);	// IC15 = PLL1 / 2, ~300-MHz
	STRONG_BARRIER;												//
	REG(RCC)->DIVENR |= RCC_DIVENR_IC15EN;						//
	(void)(REG(RCC)->DIVENR);									//

// System clock (IC20 mux) (for MCO2)

	REG(RCC)->IC20CFGR = (2u * RCC_IC20CFGR_IC20SEL_0)			// PLL3
					   | ((10u - 1u) * RCC_IC20CFGR_IC20INT_0);	// IC20 = PLL3 / 10, ~30-MHz
	STRONG_BARRIER;												//
	REG(RCC)->DIVENR |= RCC_DIVENR_IC20EN;						//
	(void)(REG(RCC)->DIVENR);									//

// System clock (IC9 mux) (for ....)

	REG(RCC)->IC9CFGR = (2u * RCC_IC9CFGR_IC9SEL_0)				// PLL3
					  | ((4u - 1u) * RCC_IC9CFGR_IC9INT_0);		// IC9 = PLL3 / 4, ~75-MHz
	STRONG_BARRIER;												//
	REG(RCC)->DIVENR |= RCC_DIVENR_IC9EN;						//
	(void)(REG(RCC)->DIVENR);									//

// Bus speeds
// ----------

// CPU & AXI clocks
// - CPU -> 600-MHz (sysa_ck)
// - SYS -> 300-MHz (sysb_ck)
//					(sysc_ck) not used
//					(sysd_ck) not used
// - PERCK -> HSI

// Bus peripheral clocks
// - Timers					-> 75-MHz
// - HPRE					-> 75-MHz
// - PBx (x, 1, 2, 4, 5)	-> 75-MHz
// !!! Silicon limitation. PBx HAS to be = to AHB
// !!! ES0620 - Rev 1: errata 2.2.1 Incorrect APB prescaler setting

	REG(RCC)->CFGR2 = (0 * RCC_CFGR2_TIMPRE_0)					// sys_bus_ck
					| (0 * RCC_CFGR2_HPRE_0)					// sys_bus_ck
					| (0 * RCC_CFGR2_PPRE1_0)					// sys_bus_ck2
					| (0 * RCC_CFGR2_PPRE2_0)					// sys_bus_ck2
					| (0 * RCC_CFGR2_PPRE4_0)					// sys_bus_ck2
					| (0 * RCC_CFGR2_PPRE5_0);					// sys_bus_ck2
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
