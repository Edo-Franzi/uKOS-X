/*
; init.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Low level init for the uKOS-X Nucleo_L4R5 module.
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

// Runtime specific
// ================

// Prototypes

static	void	local_PWR_Configuration(void);
static	void	local_GPIO_Configuration(void);
static	void	local_RCC_Configuration(void);
static	void	local_MPU_Configuration(void);
static	void	local_FPE_Configuration(void);
static	void	local_USB_Configuration(void);

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

	local_PWR_Configuration();
	local_GPIO_Configuration();
	local_RCC_Configuration();
	local_MPU_Configuration();
	local_FPE_Configuration();
	local_USB_Configuration();
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

	SCB->CPACR |= (SCB_CPACR_CP10  | SCB_CPACR_CP11);
	FPE->FPCCR |= (FPE_FPCCR_ASPEN | FPE_FPCCR_LSPEN);
}

/*
 * \brief local_PWR_Configuration
 *
 * - PWR configuration
 *
 */
static	void	local_PWR_Configuration(void) {

	RCC->APB1ENR1 |= RCC_APB1ENR1_PWREN;

// R+MODE = 0 for 120-MHz
// IOSV on to power the PORTG[2..15]

	PWR->CR5 &= ~PWR_CR5_R1MODE;
	PWR->CR2  = PWR_CR2_IOSV | PWR_CR2_PVME2;
	PWR->CR2 |= PWR_CR2_USV;
}

/*
 * \brief local_USB_Configuration
 *
 * - Enable the USB
 *
 */
static	void	local_USB_Configuration(void) {

	RCC->AHB2ENR |= RCC_AHB2ENR_OTGFSEN;

	OTG_FS_GLOBAL->FS_GCCFG |= USB_OTG_GCCFG_VBDEN;
}

/*
 * \brief local_GPIO_Configuration
 *
 * - GPIO configuration
 *
 */
static	void	local_GPIO_Configuration(void) {

// Turn on all the GPIOx

	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIODEN;
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOFEN;
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOGEN;
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOHEN;

// Init all the GPIO A, B, C, D, E, F, G, H

// PA00, AL,  50-MHz, Push-pull	TIM2_PWM1	AF1		CN10 D32 +-
// PA01, AN,  50-MHz, Pull-up	ADC			AF15	CN10 A8 +-
// PA02, OU,  50-MHz, Push-pull	QSPI1_NSS	AF15	CN10 D26 +-
// PA03, AN,  50-MHz, Pull-up	ADC			AF15	CN9  A0 +-
// PA04, OU,  50-MHz, Push-pull	SPI3_NSS	AF15	CN7  D24 +-
// PA05, AL,  50-MHz, Push-pull	SPI1_SCK	AF5		CN7  D13 +-
// PA06, AL,  50-MHz, Pull-up	SPI1_MISO	AF5		CN7  D12 +-
// PA07, AL,  50-MHz, Push-pull	SPI1_MOSI	AF5		CN7  D11 +-
// PA08, AL,  50-MHz, Pull-up	TPI (MCO)	AF0 +-
// PA09, IN,  50-MHz, -			VBUS_FS!!	AF15 +-
// PA10, AL,  50-MHz, Pull-up	USB_ID		AF10 +-
// PA11, AL,  99-MHz, -			USB_DM		AF10 +-
// PA12, AL,  99-MHz, -			USB_DP		AF10 +-
// PA13, AL,  50-MHz, Pull-up 	TMS			AF0 +-
// PA14, AL,  50-MHz, Pull-down TCK			AF0 +-
// PA15, AL,  50-MHz, Pull-up	TDI			AF0

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(A,KAL,KAL,KAL,KAL,KAL,KAL,KIN,KAL,KAL,KAL,KAL,KOU,KAN,KOU,KAN,KAL,
			  K50,K50,K50,K99,K99,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KPD,KPU,KNO,KNO,KPU,KNO,KNO,KNO,KPU,KNO,KNO,KPU,KNO,KPU,KPU,
			  A00,A00,A00,A10,A10,A10,A15,A00,A05,A05,A05,A15,A15,A15,A15,A01,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 1u, 0u, 0u);

// PB00, AL,  50-MHz, Pull-up	QSPI1_IO1	AF0		CN10 D29 +-
// PB01, AN,  50-MHz, Pull-up	ADC			AF15	CN10 A6 +-
// PB02, IN,  50-MHz, Pull-up	--------	AF15	CN9  D72 +-
// PB03, AL,  50-MHz, Push-pull	SPI3_SCK	AF6		CN7  D23 +-
// PB04, AL,  50-MHz, Pull-up	SPI3_MISO	AF6		CN7  D25 +-
// PB05, AL,  50-MHz, Push-pull	SPI3_MOSI	AF6		CN7  D22 +-
// PB06, IN,  50-MHz, Pull-up	--------	AF15	CN9	 D71 +-
// PB07, OU,  50-MHz, Push-pull	LED_Blue	AF15 +-
// PB08, AL,  50-MHz, Open DU	I2C1_SCL	AF4		CN7  D15 +-
// PB09, AL,  50-MHz, Open DU	I2C1_SDA	AF4		CN7  D14 +-
// PB10, AL,  50-MHz, Push-pull	QSPI1_SCK	AF10	CN10 D27 +-
// PB11, AL,  50-MHz, Push-pull	TIM2_PWM3	AF1		CN10 D35 +-
// PB12, AL,  50-MHz, Push-pull	I2S2_WS_A	AF13	CN7  D19 +-
// PB13, AL,  50-MHz, Push-pull	I2S2_CK_A	AF13	CN7  D18 +-
// PB14, OU,  50-MHz, Push-pull	LED_Red		AF15 +-
// PB15, AL,  50-MHz, Push-pull	I2S2_SDO_A	AF13	CN7  D17 +-

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(B,KAL,KOU,KAL,KAL,KAL,KAL,KAL,KAL,KOU,KIN,KAL,KAL,KAL,KIN,KAN,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KNO,KNO,KNO,KNO,KNO,KPU,KPU,KNO,KPU,KNO,KPU,KNO,KPU,KPU,KPU,
			  A13,A15,A13,A13,A01,A10,A04,A04,A15,A15,A06,A06,A06,A15,A15,A00,
			  KPP,KPP,KPP,KPP,KPP,KPP,KOD,KOD,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PC00, AN,  50-MHz, Pull-up	ADC			AF15	CN9  A1 +-
// PC01, AN,  50-MHz, Pull-up	ADC			AF15	CN9  A3 +-
// PC02, AN,  50-MHz, Pull-up	ADC			AF15	CN10 A7 +-
// PC03, AN,  50-MHz, Pull-up	ADC			AF15	CN9  A2 +-
// PC04, AN,  50-MHz, Pull-up	ADC			AF15	CN9	 A4 +-
// PC05, AN,  50-MHz, Pull-up	ADC			AF15	CN9	 A5 +-
// PC06, AL,  50-MHz, Push-pull	I2S2_MCK_A	AF13	CN7  D16 +-
// PC07, OU,  50-MHz, Push-pull	LED_Green	AF15 +-
// PC08, AL,  50-MHz, Push-pull	SDMMC_D0	AF12	CN8  D43 +-
// PC09, AL,  50-MHz, Push-pull	SDMMC_D1	AF12	CN8  D44 +-
// PC10, AL,  50-MHz, Push-pull	SDMMC_D2	AF12	CN8  D45 +-
// PC11, AL,  50-MHz, Push-pull	SDMMC_D3	AF12	CN8  D46 +-
// PC12, AL,  50-MHz, Push-pull	SDMMC_CLK	AF12	CN8  D47 +-
// PC13, IN,  50-MHz, Pull-up	SW_User		AF15 +-
// PC14, AL,  50-MHz, -			OSC			AF0 +-
// PC15, AL,  50-MHz, -			OSC			AF0 +-

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(C,KAL,KAL,KIN,KAL,KAL,KAL,KAL,KAL,KOU,KAL,KAN,KAN,KAN,KAN,KAN,KAN,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KNO,KPD,KNO,KPU,KPU,KPU,KPU,KNO,KNO,KPU,KPU,KPU,KPU,KPU,KPU,
			  A00,A00,A15,A12,A12,A12,A12,A12,A15,A13,A15,A15,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u);

// PD00, AL,  50-MHz, Pull-up	CAN1_RX		AF9		CN9  D67 +-
// PD01, AL,  50-MHz, Push-pull	CAN1_TX		AF9		CN9  D66 +-
// PD02, AL,  50-MHz, Push-pull	SDMMC_CMD	AF12	CN8  D48 +-
// PD03, IN,  50-MHz, Pull-up	USART2_CTS	AF15	CN9  D55 +-
// PD04, OU,  50-MHz, Push-pull	USART2_RTS	AF15	CN9  D54 +-
// PD05, AL,  50-MHz, Push-pull	USART2_TX	AF7		CN9  D53 +-
// PD06, AL,  50-MHz, Pull-up	USART2_RX	AF7		CN9  D52 +-
// PD07, AL,  50-MHz, Push-pull	USART2_SCLK	AF7		CN9  D51 +-
// PD08, AL,  50-MHz, Push-pull	USART3_TX	AF7		CN10 D1 +-
// PD09, AL,  50-MHz, Pull-up	USART3_RX	AF7		CN10 D0 +-
// PD10, OU,  50-MHz, Push-pull	Out			AF15 +-
// PD11, OU,  50-MHz, Push-pull	Out			AF15 +-
// PD12, OU,  50-MHz, Push-pull	Out			AF15 +-
// PD13, OU,  50-MHz, Push-pull	Out			AF15 +-
// PD14, OU,  50-MHz, Push-pull	SPI1_NSS	AF15	CN7  D10 +-
// PD15, AL,  50-MHz, Push-pull	TIM4_PWM2	AF2		CN7  D9 +-

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(D,KAL,KOU,KOU,KOU,KOU,KOU,KAL,KAL,KAL,KAL,KAL,KOU,KIN,KAL,KAL,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KNO,KNO,KNO,KNO,KNO,KPU,KNO,KNO,KPU,KNO,KNO,KPU,KNO,KNO,KPU,
			  A15,A00,A15,A15,A15,A15,A07,A07,A07,A07,A07,A15,A15,A12,A09,A09,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PE00, AL,  50-MHz, Pull-up	TIM4_ETR	AF2		CN10 D34 +-
// PE01, OU,  50-MHz, Push-pull	Out			AF15 +-
// PE02, AL,  50-MHz, Push-pull	SAI1_SCK_A	AF3		CN9  D56 +-
// PE03, AL,  50-MHz, Push-pull	SAI1_SD_B	AF13	CN9  D60 +-
// PE04, AL,  50-MHz, Push-pull	SAI1_FS_A	AF3		CN9  D57 +-
// PE05, AL,  50-MHz, Push-pull	SAI1_SCK_A	AF3		CN9  D58 +-
// PE06, AL,  50-MHz, Push-pull	SAI1_SD_A	AF3		CN9  D59 +-
// PE07, AL,  50-MHz, Pull-up	TIM1_ETR	AF1		CN10 D41 +-
// PE08, AL,  50-MHz, Push-pull	TIM1_PWM1N	AF1		CN10 D42 +-
// PE09, AL,  50-MHz, Push-pull	TIM1_PWM1	AF1		CN10 D6 +-
// PE10, AL,  50-MHz, Push-pull	TIM1_PWM2N	AF1		CN10 D40 +-
// PE11, AL,  50-MHz, Push-pull	TIM1_PWM2	AF1		CN10 D5 +-
// PE12, AL,  50-MHz, Push-pull	QSPI1_IO0	AF10	CN10 D30 +-
// PE13, AL,  50-MHz, Push-pull	TIM1_PWM3	AF1		CN10 D3 +-
// PE14, AL,  50-MHz, Pull-up	QSPI1_IO2	AF10	CN10 D31 +-
// PE15, AL,  50-MHz, Pull-up	QSPI1_IO3	AF10	CN10 D28 +-

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(E,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KOU,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KPU,KNO,KPU,KNO,KNO,KNO,KNO,KPU,KPU,KNO,KNO,KPU,KNO,KNO,KPU,
			  A10,A10,A01,A10,A01,A01,A01,A01,A01,A03,A03,A03,A13,A03,A15,A02,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PF00, AL,  50-MHz, Open DU	I2C2_SDA	AF4		CN9  D68 +-
// PF01, AL,  50-MHz, Open DU	I2C2_SCL	AF4		CN9  D69 +-
// PF02, AL,  50-MHz, Push-pull	I2C2_SMBA	AF4		CN9  D70 +-
// PF03, OU,  50-MHz, Push-pull	Out			AF15	CN8  D49 +-
// PF04, OU,  50-MHz, Push-pull	Out			AF15 +-
// PF05, OU,  50-MHz, Push-pull	Out			AF15	CN8  D50 +-
// PF06, OU,  50-MHz, Push-pull	Out			AF15 +-
// PF07, AL,  50-MHz, Push-pull	SAI1_MCLK_B	AF13	CN9  D62 +-
// PF08, AL,  50-MHz, Push-pull	SAI1_SLK_B	AF13	CN9  D61 +-
// PF09, AL,  50-MHz, Push-pull	SAI1_FS_B	AF13	CN9  D63 +-
// PF10, OU,  50-MHz, Push-pull	Out			AF15 +-
// PF11, OU,  50-MHz, Push-pull	Out			AF15 +-
// PF12, OU,  50-MHz, Push-pull	Out			AF15	CN7  D8 +-
// PF13, OU,  50-MHz, Push-pull	Out			AF15	CN10 D7 +-
// PF14, OU,  50-MHz, Push-pull	Out			AF15	CN10 D4 +-
// PF15, OU,  50-MHz, Push-pull	Out			AF15	CN10 D2 +-

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(F,KOU,KOU,KOU,KOU,KOU,KOU,KAL,KAL,KAL,KOU,KOU,KOU,KOU,KAL,KAL,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KPU,KPU,KPU,
			  A15,A15,A15,A15,A15,A15,A13,A13,A13,A15,A15,A15,A15,A04,A04,A04,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KOD,KOD,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PG00, OU,  50-MHz, Push-pull	Out			AF15	CN9  D65 +-
// PG01, OU,  50-MHz, Push-pull	Out			AF15	CN9  D64 +-
// PG02, OU,  50-MHz, Push-pull	Out			AF15 +-
// PG03, OU,  50-MHz, Push-pull	Out			AF15 +-
// PG04, OU,  50-MHz, Push-pull	Out			AF15 +-
// PG05, IN,  50-MHz, Pull-up	In			AF15	USB_FAULT
// PG06, OU,  50-MHz, Push-pull	Out			AF15	USB_POWER
// PG07, AL,  50-MHz, Push-pull	LPUSART1_TX	AF8  +-
// PG08, AL,  50-MHz, Pull-up	LPUSART1_RX	AF8  +-
// PG09, OU,  50-MHz, Push-pull	Out			AF15 +-
// PG10, OU,  50-MHz, Push-pull	Out			AF15 +-
// PG11, OU,  50-MHz, Push-pull	Out			AF15 +-
// PG12, OU,  50-MHz, Push-pull	Out			AF15 +-
// PG13, OU,  50-MHz, Push-pull	Out			AF15 +-
// PG14, OU,  50-MHz, Push-pull	Out			AF0  +-
// PG15, IN,  50-MHz, Pull-up	In			AF15 +-

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(G,KIN,KOU,KOU,KOU,KOU,KOU,KOU,KAL,KAL,KOU,KIN,KOU,KOU,KOU,KOU,KOU,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KNO,KNO,KNO,KNO,KNO,KNO,KPU,KNO,KNO,KPU,KNO,KNO,KNO,KNO,KNO,
			  A15,A15,A15,A15,A15,A15,A15,A08,A08,A15,A15,A15,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PH00, AL,  50-MHz, -			OSC			AF0
// PH01, AL,  50-MHz, -			OSC			AF0
// PH02, IN,  50-MHz, Pull-up	--------	AF15
// PH03, AL,  50-MHz, Pull-up	--------	AF0
// PH04, IN,  50-MHz, Pull-up	--------	AF15
// PH05, IN,  50-MHz, Pull-up	--------	AF15
// PH06, IN,  99-MHz, Pull-up	--------	AF15
// PH07, IN,  99-MHz, Pull-up	--------	AF15
// PH08, IN,  50-MHz, Pull-up	--------	AF15
// PH09, IN,  50-MHz, Pull-up	--------	AF15
// PH10, IN,  50-MHz, Pull-up	--------	AF15
// PH11, IN,  50-MHz, Pull-up	--------	AF15
// PH12, IN,  50-MHz, Pull-up	--------	AF15
// PH13, IN,  50-MHz, Pull-up	--------	AF15
// PH14, IN,  50-MHz, Pull-up	--------	AF15
// PH15, IN,  50-MHz, Pull-up	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(H,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KAL,KIN,KAL,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K99,K99,K50,K50,K50,K50,K50,K50,
			  KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KNO,KNO,
			  A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A00,A15,A00,A00,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);
}

/*
 * \brief local_RCC_Configuration
 *
 * - Clock, PLL configuration
 *
 */
static	void	local_RCC_Configuration(void) {

	RCC->CSR	 |= RCC_CSR_LSION;						// Enable the LSI

	#ifdef KCALENDAR_WITH_HW_RTC_S
	while ((RCC->CSR & RCC_CSR_LSIRDY) == 0u) { ; }		// Wait for LSI ready

// Enable backup domain access and configure RTC

	PWR->CR1 |= PWR_CR1_DBP;							// Disable backup domain write protection

// Select LSI as RTC clock source and enable RTC

	RCC->BDCR = (RCC->BDCR & ~RCC_BDCR_RTCSEL)
			  | (2u * RCC_BDCR_RTCSEL_0);				// LSI is the source for the RTC
	RCC->BDCR |= RCC_BDCR_RTCEN;						// RTC enable
	#endif

	RCC->CR      &= 0xFFFFFF0EU;						// MSI off
	RCC->CR      |= 0x000101BCU;						// HSI & HSE on, MSI 48-MHz
	RCC->CFGR     = 0x00000000U;						// Reset CFGR register
	RCC->CR      &= 0xFEF7FFFFU;						// Reset CSSON and PLLON bits
	RCC->PLLCFGR  = 0x00001000U;						// Reset PLLCFGR register
	RCC->CR      &= 0xFFFBFFFFU;						// Reset HSEBYP bit
	RCC->CR      |= 0x00000001U;						// MSI on

// Activate the ART + 5ws (OK for 120-MHz)

	FLASH->ACR = FLASH_ACR_DCEN							//
			   | FLASH_ACR_ICEN							//
			   | FLASH_ACR_PRFTEN						//
			   | (5u * FLASH_ACR_LATENCY_0);			// Enable caches and prefetch

// For f(ck in) = 16-MHz
// f(out) = f(vco) / R			f(out) = 120-MHz, R = 2		---> f(vco) = 240-MHz
// f(vco) = f(ck in) * (N/M)	N/M = 30/2 = 15				---> N = 30, M = 2
// f(usb) = f(vco) / Q			Q = 6						---> f(xx) = 40-MHz

	RCC->PLLCFGR = (0u * RCC_PLLCFGR_PLLPDIV_0)			// PLLPDIV (not available)
				 | (0u * RCC_PLLCFGR_PLLR_0)			// R = 2
				 | RCC_PLLCFGR_PLLREN					// PLLR enabled
				 | (2u * RCC_PLLCFGR_PLLQ_0)			// Q = 6
				 | RCC_PLLCFGR_PLLQEN					// PLLQ enabled
				 | (0u * RCC_PLLCFGR_PLLP)				// P = 7
				 | RCC_PLLCFGR_PLLPEN					// PLLP enabled
				 | (30u * RCC_PLLCFGR_PLLN_0)			// N = 30
				 | (1u * RCC_PLLCFGR_PLLM_0)			// M = 2
				 | (2u * RCC_PLLCFGR_PLLSRC_0);			// HSI16 as a PLL source

	RCC->CFGR = (0u * RCC_CFGR_MCOPRE_0)				// MCO (no division)
			  | (2u * RCC_CFGR_MCOSEL_0)				// MSI output
			  | (0u * RCC_CFGR_PPRE2_0)					// APB2 bus @ 120/1 = 120-MHz
			  | (0u * RCC_CFGR_PPRE1_0)					// APB1 bus @ 120/1 = 120-MHz
			  | (0u * RCC_CFGR_HPRE_0)					// HPRE bus @ 120-MHz
			  | (3u * RCC_CFGR_SW_0);					// PLL selected as a system clock

// MSI 48-MHz for RNG, USB, ..., PCLK (120-MHz) for LPUART1

	RCC->CRRCR |= RCC_CRRCR_HSI48ON;
	RCC->CCIPR  = (3u * RCC_CCIPR_CLK48SEL_0)
				| (0u * RCC_CCIPR_LPUART1SEL_0);

	RCC->CR	  |= RCC_CR_PLLON;
	RCC->CFGR |= (3u * RCC_CFGR_SW_0);

// Waiting for the lock

	while ((RCC->CR & RCC_CR_PLLRDY) == 0u) { ; }
	while (((RCC->CFGR) & RCC_CFGR_SWS) != (3u * RCC_CFGR_SWS_0)) { ; }
}

/*
 * \brief local_MPU_Configuration
 *
 * - Initialise the MPU for the different
 *   memory regions of the system
 *
 * - https://interrupt.memfault.com/blog/fix-bugs-and-secure-firmware-with-the-mpu#overview-of-mpu-functionality
 *
 */
static	void	local_MPU_Configuration(void) {

	#if (defined(PRIVILEGED_USER_S))
	SET_MPU7_REGION(0u, 0u,	ST_FLASH_INT_0,		SZ_FLASH_INT_0,		KMPU_EXECUTABLE,		KMPU_R_ALL,		KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(1u, 0u,	ST_RAM_INT_0,		SZ_RAM_INT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(2u, 0u,	ST_RAM_INT_0_OS,	SZ_RAM_INT_0_OS,	KMPU_EXECUTABLE,		KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(3u, 0u,	ST_PERIPH_SOC,		SZ_PERIPH_SOC,		KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_BUFFERABLE);
	SET_MPU7_REGION(4u, 0u,	ST_PERIPH_CORE,		SZ_PERIPH_CORE,		KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_BUFFERABLE);

	#else
	SET_MPU7_REGION(0u, 0u,	ST_FLASH_INT_0,		SZ_FLASH_INT_0,		KMPU_EXECUTABLE,		KMPU_R_ALL,		KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(1u, 0u,	ST_RAM_INT_0,		SZ_RAM_INT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	#endif

// Enable branch prediction
// Normally not necessary (always on)

	SCB->CCR |= (1u<<18u);
	DATA_SYNC_BARRIER;
}
