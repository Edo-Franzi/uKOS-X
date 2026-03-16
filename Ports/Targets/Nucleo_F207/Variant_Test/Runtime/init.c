/*
; init.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Low level init for the uKOS-X Nucleo_F207 module.
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

static	void	local_GPIO_Configuration(void);
static	void	local_RCC_Configuration(void);
static	void	local_MPU_Configuration(void);
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

	local_GPIO_Configuration();
	local_RCC_Configuration();
	local_MPU_Configuration();
	local_USB_Configuration();
}

/*
 * \brief local_USB_Configuration
 *
 * - Enable the USB
 *
 */
static	void	local_USB_Configuration(void) {

	RCC->AHB2ENR |= RCC_AHB2ENR_OTGFSEN;

	OTG_FS_GLOBAL->FS_GCCFG &= ~OTG_FS_GLOBAL_FS_GCCFG_VBDEN;
	OTG_FS_GLOBAL->FS_GCCFG |=  OTG_FS_GLOBAL_FS_GCCFG_VBUSBSEN;
}

/*
 * \brief local_GPIO_Configuration
 *
 * - GPIO configuration
 *
 */
static	void	local_GPIO_Configuration(void) {

// Turn on all the GPIOx

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;

// Init all the GPIO A, B, C, D, E, F, G, H

// PA00, AL,  50-MHz, Push-pull	TIM2_CH1	AF01	CN10 D32
// PA01, IN,  50-MHz, Pull-up	--------	AF00
// PA02, IN,  50-MHz, Pull-up	--------	AF00
// PA03, AN,  50-MHz, Pull-up	ADC			AF00	CN9  A0
// PA04, OU,  50-MHz, Push-pull	SPI3_NSS0	AF00	CN7  D24
// PA05, AL,  50-MHz, Push-pull	SPI1_SCK	AF05	CN7  D13
// PA06, AL,  50-MHz, Pull-up	SPI1_MISO	AF05	CN7  D12
// PA07, AL,  50-MHz, Push-pull	SPI1_MOSI	AF05	CN7  D11 (JP6 off)
// PA08, OU,  50-MHz, Pull-up	TPI			AF00
// PA09, IN,  50-MHz, -			VBUS_FS!!	AF00
// PA10, AL,  50-MHz, Pull-up	USB_ID		AF10
// PA11, AL,  99-MHz, -			USB_DM		AF10
// PA12, AL,  99-MHz, -			USB_DP		AF10
// PA13, AL,  50-MHz, Pull-up 	TMS			AF00
// PA14, AL,  50-MHz, Pull-down TCK			AF00
// PA15, AL,  50-MHz, Pull-up	TDI			AF00

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(A,KAL,KAL,KAL,KAL,KAL,KAL,KIN,KOU,KAL,KAL,KAL,KOU,KAN,KIN,KIN,KAL,
			  K50,K50,K50,K99,K99,K99,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KPD,KPU,KNO,KNO,KPU,KPU,KNO,KNO,KPU,KNO,KNO,KPU,KPU,KPU,KNO,
			  A00,A00,A00,A10,A10,A10,A00,A00,A05,A05,A05,A00,A00,A00,A00,A01,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u);

// PB00, OU,  50-MHz, Push-pull	LED_Geen	AF00
// PB01, AN,  50-MHz, Pull-up	ADC			AF00	CN10 A6
// PB02, AL,  50-MHz, Push-pull	QSPI1_CLK	AF09	CN10 D27
// PB03, AL,  50-MHz, Push-pull	SPI3_SCK	AF06	CN7  D23
// PB04, AL,  50-MHz, Pull-up	SPI3_MISO	AF06	CN7  D25
// PB05, AL,  50-MHz, Push-pull	SPI3_MOSI	AF07	CN7  D22
// PB06, AL,  50-MHz, Push-pull	QSPI1_NSS	AF10	CN10 D26
// PB07, OU,  50-MHz, Push-pull	LED_Blue	AF00
// PB08, AL,  50-MHz, Open DU	I2C1_SCL	AF04	CN7  D15
// PB09, AL,  50-MHz, Open DU	I2C1_SDA	AF04	CN7  D14
// PB10, AL,  50-MHz, Push-pull	TIM2_CH3	AF01	CN10 D36
// PB11, AL,  50-MHz, Push-pull	TIM2_CH4	AF01	CN10 D35
// PB12, AL,  50-MHz, Push-pull	I2S2_WS_A	AF05	CN7  D19
// PB13, AL,  50-MHz, Push-pull	I2S2_CK_A	AF05	CN7  D18
// PB14, OU,  50-MHz, Push-pull	LED_Red		AF00
// PB15, AL,  50-MHz, Push-pull	I2S2_SDO_A	AF05	CN7  D17

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(B,KAL,KOU,KAL,KAL,KAL,KAL,KAL,KAL,KOU,KAL,KAL,KAL,KAL,KAL,KAN,KOU,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KNO,KNO,KNO,KNO,KNO,KPU,KPU,KNO,KNO,KNO,KPU,KNO,KNO,KPU,KNO,
			  A05,A00,A05,A05,A01,A01,A04,A04,A00,A10,A07,A06,A06,A09,A00,A00,
			  KPP,KPP,KPP,KPP,KPP,KPP,KOD,KOD,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PC00, AN,  50-MHz, Pull-up	ADC			AF00	CN9  A1
// PC01, IN,  50-MHz, Pull-up	--------	AF00
// PC02, AN,  50-MHz, Pull-up	ADC			AF00	CN10 A7
// PC03, AN,  50-MHz, Pull-up	ADC			AF00	CN9  A2
// PC04, IN,  50-MHz, Pull-up	--------	AF00
// PC05, IN,  50-MHz, Pull-up	--------	AF00
// PC06, AL,  50-MHz, Push-pull	I2S2_MCK_A	AF05	CN7  D16
// PC07, OU,  50-MHz, Push-pull	SPI3_NSS1	AF00	CN7  D21
// PC08, AL,  50-MHz, Push-pull	SDMMC1_D0	AF12	CN8  D43
// PC09, AL,  50-MHz, Push-pull	SDMMC1_D1	AF12	CN8  D44
// PC10, AL,  50-MHz, Push-pull	SDMMC1_D2	AF12	CN8  D45
// PC11, AL,  50-MHz, Push-pull	SDMMC1_D3	AF12	CN8  D46
// PC12, AL,  50-MHz, Push-pull	SDMMC1_CLK	AF12	CN8  D47
// PC13, IN,  50-MHz, Pull-down	SW_User		AF00
// PC14, AL,  50-MHz, -			OSC			AF00
// PC15, AL,  50-MHz, -			OSC			AF00

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(C,KAL,KAL,KIN,KAL,KAL,KAL,KAL,KAL,KOU,KAL,KIN,KIN,KAN,KAN,KIN,KAN,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KNO,KPD,KNO,KPU,KPU,KPU,KPU,KNO,KNO,KPU,KPU,KPU,KPU,KPU,KPU,
			  A00,A00,A00,A12,A12,A12,A12,A12,A06,A00,A00,A00,A00,A00,A00,A00,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u);

// PD00, AL,  50-MHz, Pull-up	CAN1_RX		AF09	CN9  D67
// PD01, AL,  50-MHz, Push-pull	CAN1_TX		AF09	CN9  D66
// PD02, AL,  50-MHz, Push-pull	SDIO_CMD	AF12	CN8  D48
// PD03, IN,  50-MHz, Pull-up	USART2_CTS	AF00	CN9  D55
// PD04, OU,  50-MHz, Push-pull	USART2_RTS	AF00	CN9  D54
// PD05, AL,  50-MHz, Push-pull	USART2_TX	AF07	CN9  D53
// PD06, AL,  50-MHz, Pull-up	USART2_RX	AF07	CN9  D52
// PD07, AL,  50-MHz, Push-pull	USART2_SCLK	AF07	CN9  D51
// PD08, AL,  50-MHz, Push-pull	USART3_TX	AF07
// PD09, AL,  50-MHz, Pull-up	USART6_RX	AF07
// PD10, AL,  99-MHz, Push-pull	FMC_D15		AF12
// PD11, AL,  50-MHz, Push-pull	QSPI1_IO0	AF09	CN10 D30
// PD12, AL,  50-MHz, Push-pull	QSPI1_IO1	AF09	CN10 D29
// PD13, AL,  50-MHz, Push-pull	QSPI1_IO3	AF09	CN10 D28
// PD14, OU,  50-MHz, Push-pull	SPI1_NSS	AF00	CN7  D10
// PD15, AL,  50-MHz, Push-pull	TIM4_CH4	AF02	CN7  D9

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(D,KAL,KOU,KAL,KAL,KAL,KIN,KAL,KAL,KAL,KAL,KAL,KOU,KIN,KAL,KAL,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KNO,KPU,KPU,KPU,KPU,KPU,KNO,KNO,KPU,KNO,KNO,KPU,KNO,KNO,KPU,
			  A02,A00,A09,A09,A09,A15,A07,A07,A07,A07,A07,A00,A00,A12,A09,A09,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PE00, AL,  50-MHz, Push-pull	TIM4_ETR	AF02	CN10 D34
// PE01, OU,  50-MHz, Push-pull	Out			AF00	CN11 61
// PE02, AL,  50-MHz, Push-pull	QSPI1_IO2	AF09	CN10 D31 (see note 3)
// PE03, AL,  50-MHz, Push-pull	SAI1_SD_B	AF06	CN9  D60
// PE04, AL,  50-MHz, Push-pull	SAI1_FS_A	AF06	CN9  D57
// PE05, AL,  50-MHz, Push-pull	SAI1_SCK_A	AF06	CN9  D58
// PE06, AL,  50-MHz, Push-pull	SAI1_SD_A	AF06	CN9  D59
// PE07, AL,  50-MHz, Push-pull	TIM1_ETR	AF01	CN10 D41
// PE08, AL,  50-MHz, Push-pull	TIM1_CH1N	AF01	CN10 D42
// PE09, AL,  50-MHz, Push-pull	TIM1_CH1	AF01	CN10 D6
// PE10, AL,  50-MHz, Push-pull	TIM1_CH2N	AF01	CN10 D40
// PE11, OU,  50-MHz, Push-pull	NNS4		AF00	CN10 D5
// PE12, AL,  50-MHz, Push-pull	SCK4		AF05	CN10 D39
// PE13, AL,  50-MHz, Push-pull	MISO		AF05	CN10 D3
// PE14, AL,  50-MHz, Push-pull	MOSI4		AF05	CN10 D38
// PE15, AL,  50-MHz, Pull-up	TIM1_BKIN	AF01	CN10 D35

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(E,KAL,KAL,KAL,KAL,KOU,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KOU,KAL,
			  K50,K99,K99,K99,K99,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KNO,KPU,KNO,KNO,KOU,KNO,KNO,KNO,KPU,KNO,KNO,KPU,KPU,KNO,KNO,
			  A01,A05,A05,A05,A00,A01,A01,A01,A01,A06,A06,A06,A06,A09,A00,A02,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PF00, AL,  50-MHz, Open DU	I2C2_SDA	AF04	CN9  D68
// PF01, AL,  50-MHz, Open DU	I2C2_SCL	AF04	CN9  D69
// PF02, AL,  50-MHz, Push-pull	I2C2_SMBA	AF04	CN9  D70
// PF03, AN,  50-MHz, Pull-up	ADC			AF00	CN9  A3
// PF04, AN,  50-MHz, Pull-up	ADC			AF00	CN10 A8
// PF05, AN,  50-MHz, Pull-up	ADC			AF00	CN9  A4
// PF06, OU,  50-MHz, Push-pull	Out			AF00	CN11 9
// PF07, AL,  50-MHz, Push-pull	SAI1_MCLK_B	AF06	CN9  D62
// PF08, AL,  50-MHz, Push-pull	SAI1_SLK_B	AF06	CN9  D61
// PF09, AL,  50-MHz, Push-pull	SAI1_FS_B	AF06	CN9  D63
// PF10, AN,  50-MHz, Pull-up	ADC			AF00	CN9  A5
// PF11, OU,  50-MHz, Push-pull	Out			AF00	CN12 62
// PF12, OU,  50-MHz, Push-pull	Out			AF00	CN7  D8
// PF13, OU,  50-MHz, Push-pull	Out			AF00	CN10 D7
// PF14, OU,  50-MHz, Push-pull	Out			AF00	CN10 D4
// PF15, OU,  50-MHz, Push-pull	Out			AF00	CN10 D2

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(F,KOU,KIN,KOU,KOU,KOU,KAN,KAL,KAL,KAL,KOU,KAN,KAN,KAN,KAL,KAL,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KNO,KNO,KNO,KNO,KPU,KNO,KNO,KNO,KNO,KPU,KPU,KPU,KPU,KPU,KPU,
			  A00,A00,A00,A00,A00,A00,A06,A06,A06,A00,A00,A00,A00,A04,A04,A04,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KOD,KOD,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PG00, OU,  50-MHz, Push-pull	Out			AF00	CN9  D65
// PG01, OU,  50-MHz, Push-pull	Out			AF00	CN9  D64
// PG02, OU,  50-MHz, Push-pull	Out			AF00	CN8  D49
// PG03, OU,  50-MHz, Push-pull	Out			AF00	CN8  D50
// PG04, OU,  50-MHz, Push-pull	Out			AF00	CN12 69
// PG05, OU,  50-MHz, Push-pull	Out			AF00	CN12 68
// PG06, IN,  50-MHz, Pull-up	--------	AF00
// PG07, IN,  50-MHz, Pull-up	--------	AF00
// PG08, OU,  50-MHz, Push-pull	Out			AF00	CN12 66
// PG09, AL,  50-MHz, Pull-up	USART6_RX	AF07	CN10 D0
// PG10, OU,  50-MHz, Push-pull	Out			AF00	CN11 66
// PG11, IN,  50-MHz, Pull-up	--------	AF00
// PG12, OU,  50-MHz, Push-pull	Out			AF00	CN11 65
// PG13, IN,  50-MHz, Pull-up	--------	AF00
// PG14, AL,  50-MHz, Push-pull	USART6_TX	AF07	CN10 D1
// PG15, OU,  50-MHz, Push-pull	Out			AF00	CN11 64

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(G,KOU,KAL,KIN,KOU,KIN,KOU,KAL,KOU,KIN,KIN,KOU,KOU,KOU,KOU,KOU,KOU,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KNO,KPU,KNO,KPU,KNO,KPU,KNO,KPU,KPU,KNO,KNO,KNO,KNO,KNO,KNO,
			  A00,A07,A00,A00,A00,A00,A07,A00,A00,A00,A00,A00,A00,A00,A00,A00,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PH00, AL,  50-MHz, -			OSC			AF00
// PH01, AL,  50-MHz, -			OSC			AF00
// PH02, IN,  50-MHz, Pull-up	--------	AF00
// PH03, IN,  50-MHz, Pull-up	--------	AF00
// PH04, IN,  50-MHz, Pull-up	--------	AF00
// PH05, IN,  50-MHz, Pull-up	--------	AF00
// PH06, IN,  99-MHz, Pull-up	--------	AF00
// PH07, IN,  99-MHz, Pull-up	--------	AF00
// PH08, IN,  50-MHz, Pull-up	--------	AF00
// PH09, IN,  50-MHz, Pull-up	--------	AF00
// PH10, IN,  50-MHz, Pull-up	--------	AF00
// PH11, IN,  50-MHz, Pull-up	--------	AF00
// PH12, IN,  50-MHz, Pull-up	--------	AF00
// PH13, IN,  50-MHz, Pull-up	--------	AF00
// PH14, IN,  50-MHz, Pull-up	--------	AF00
// PH15, IN,  50-MHz, Pull-up	--------	AF00

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(H,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KAL,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K99,K99,K50,K50,K50,K50,K50,K50,
			  KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KNO,KNO,
			  A00,A00,A00,A00,A00,A00,A00,A00,A00,A00,A00,A00,A00,A00,A00,A00,
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

// Enable LSI clock

	RCC->CSR |= RCC_CSR_LSION;

// Enable HSI
// Configure Flash latency for desired frequency

	RCC->CR |= RCC_CR_HSION;

// Activate the ART + 3ws (OK for 120-MHz)

	FLASH->ACR = (3u * FLASH_ACR_LATENCY_0);			// Enable caches and prefetch

// Main PLL
// --------

// For f(ck in) = 16-MHz
// f(out) = f(vco) / P			f(out) = 120-MHz, P = 2		---> f(vco) = 240-MHz
// f(vco) = f(ck in) * (N/M)	N/M = 240/16 = 15			---> N = 60, M = 4
// f(4x)  = f(vco) / Q			Q = 5						---> f(4x)  = 48-MHz

	RCC->PLLCFGR = (5u * RCC_PLLCFGR_PLLQ0)				// Q = 5
				 | (0u * RCC_PLLCFGR_PLLSRC)			// HSI16 as a PLL source
				 | (0u * RCC_PLLCFGR_PLLP0)				// P = 2
				 | (60u * RCC_PLLCFGR_PLLN0)			// N = 60
				 | (4u * RCC_PLLCFGR_PLLM0);			// M = 4

// Waiting for stable clock and enable PLL
// Waiting for the PLL lock
// Set-up the MCO

	RCC->CR |= RCC_CR_PLLON;
	while ((RCC->CR & RCC_CR_PLLRDY) == 0u) { ; }

	RCC->CFGR = (0u * RCC_CFGR_MCO20)					// MCO2 (system clock)
			  | (0u * RCC_CFGR_MCO2PRE0)				// MCO2 (no division)
			  | (0u * RCC_CFGR_MCO1PRE0)				// MCO1 (no division)
			  | (0u * RCC_CFGR_MCO10)					// MCO1 (HSI clock selected)
			  | (4u * RCC_CFGR_RTCPRE0)					// HSE/4
			  | (4u * RCC_CFGR_PPRE20)					// APB2 bus @ 120/2 = 60-MHz
			  | (5u * RCC_CFGR_PPRE10)					// APB1 bus @ 120/4 = 30-MHz
			  | (0u * RCC_CFGR_HPRE0)					// HPRE bus @ 120-MHz
			  | (2u * RCC_CFGR_SW0);					// System clock on the PLL

	while ((RCC->CFGR & (3u * RCC_CFGR_SWS0)) != (2u * RCC_CFGR_SWS0)) { ; }
}

/*
 * \brief local_MPU_Configuration
 *
 * - Initialise the MPU for the different
 *   memory regions of the system
 *
 */
static	void	local_MPU_Configuration(void) {

	#if (defined(PRIVILEGED_USER_S))
	SET_MPU7_REGION(0u, 0u,	ST_FLASH_INT_0,		SZ_FLASH_INT_0,		KMPU_EXECUTABLE,		KMPU_R_ALL,		KMPU_TEX_LEVEL0,	KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(1u, 0u,	ST_RAM_INT_0,		SZ_RAM_INT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0,	KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(2u, 0u,	ST_RAM_INT_0_OS,	SZ_RAM_INT_0_OS,	KMPU_EXECUTABLE,		KMPU_RW_PRI,	KMPU_TEX_LEVEL0,	KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(3u, 0u,	ST_PERIPH_SOC,		SZ_PERIPH_SOC,		KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0,	KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_BUFFERABLE);
	SET_MPU7_REGION(4u, 0u,	ST_PERIPH_CORE,		SZ_PERIPH_CORE,		KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0,	KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_BUFFERABLE);

	#else
	SET_MPU7_REGION(0u, 0u,	ST_FLASH_INT_0,		SZ_FLASH_INT_0,		KMPU_EXECUTABLE,		KMPU_R_ALL,		KMPU_TEX_LEVEL0,	KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(1u, 0u,	ST_RAM_INT_0,		SZ_RAM_INT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0,	KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	#endif

// Enable branch prediction
// Normally not necessary (always on)

	SCB->CCR |= (1u<<18u);
	DATA_SYNC_BARRIER;
}
