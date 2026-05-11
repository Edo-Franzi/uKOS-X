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
; Goal:		Low level init for the uKOS-X Nucleo_H743 module.
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

static			void	local_GPIO_Configuration(void);
static			void	local_PWR_Configuration(void);
static			void	local_RCC_Configuration(void);
static			void	local_MPU_Configuration(void);
static			void	local_FPE_Configuration(void);
static			void	local_CACHE_Enable(void);
static			void	local_USB_Configuration(void);
static	inline	void	cache_D_Enable(void);
static	inline	void	cache_D_Disable(void);
static	inline	void	cache_D_Clean(void);
static	inline	void	cache_D_Invalidate(void);
static	inline	void	cache_I_Enable(void);
static	inline	void	cache_I_Disable(void);
static	inline	void	cache_I_Invalidate(void);

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

	DBGMCU->CR |= DBGMCU_CR_DBGSLEEP_D1;

	local_PWR_Configuration();
	local_RCC_Configuration();
	local_GPIO_Configuration();
	local_MPU_Configuration();
	local_FPE_Configuration();
	local_USB_Configuration();
	local_CACHE_Enable();
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

// Scaling VOS to reach the very high speed
//
// - Set to VOS1 (from VOS3 to VOS1)
// - Set the bit ODEN in the SYSCFG->PWRCR
// - Set to VOS0 (from VOS1 to VOS0)

	PWR->CR3  &= ~(PWR_CR3_SCUEN | PWR_CR3_LDOEN | PWR_CR3_BYPASS);
	PWR->CR3  |=   PWR_CR3_LDOEN;
	PWR->CR3  |=   PWR_CR3_USB33DEN;

	PWR->D3CR &= ~(PWR_D3CR_VOS);
	PWR->D3CR |=  (3u * PWR_D3CR_VOS_0);

	while ((PWR->D3CR & PWR_D3CR_VOSRDY) == 0u) { ; }

	RCC->APB4ENR  |= RCC_APB4ENR_SYSCFGEN;
	SYSCFG->PWRCR |= SYSCFG_PWRCR_ODEN;
}

/*
 * \brief local_USB_Configuration
 *
 * - Enable the USB
 *
 */
static	void	local_USB_Configuration(void) {

	RCC->AHB1ENR   |=  RCC_AHB1ENR_USB2OTGEN;
	RCC->AHB1LPENR &= ~RCC_AHB1LPENR_USB2OTGHSULPILPEN;

	OTG2_HS_GLOBAL->OTG_HS_GCCFG   |=  USB_OTG_GCCFG_VBDEN;
	OTG1_HS_GLOBAL->OTG_HS_GUSBCFG &= ~OTG2_HS_GLOBAL_OTG_HS_GUSBCFG_FHMOD;
	OTG1_HS_GLOBAL->OTG_HS_GUSBCFG |=  OTG2_HS_GLOBAL_OTG_HS_GUSBCFG_FDMOD;
}

/*
 * \brief local_GPIO_Configuration
 *
 * - GPIO configuration
 *
 */
static	void	local_GPIO_Configuration(void) {

// Turn on all the GPIOx

	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOAEN;
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOBEN;
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOCEN;
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIODEN;
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOEEN;
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOFEN;
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOGEN;
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOHEN;
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOIEN;
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOJEN;

// Init all the GPIO A, B, C, D, E, F, G, H

// PA00, IN,  50-MHz, Pull-up	INT			AF00	CN10 D32 (interruption)
// PA01, IN,  50-MHz, Pull-up	--------	AF00
// PA02, IN,  50-MHz, Pull-up	--------	AF00
// PA03, AN,  50-MHz, Pull-up	ADC			AF00	CN9  A0
// PA04, OU,  50-MHz, Push-pull	SPI3_NSS0	AF00	CN7  D24
// PA05, AL,  50-MHz, Push-pull	SPI1_SCK	AF05	CN7  D13
// PA06, AL,  50-MHz, Pull-up	SPI1_MISO	AF05	CN7  D12
// PA07, AL,  50-MHz, Push-pull	SPI1_MOSI	AF05	CN7  D11 (JP6 off)
// PA08, AL,  99-MHz, Push-pull	TIM1_CH1	AF01
// PA09, IN,  50-MHz, -			VBUS_FS!!	AF00	+-
// PA10, AL,  99-MHz, Open-d	USB_ID		AF10	+-
// PA11, AL,  99-MHz, -			USB_DM		AF10	+-
// PA12, AL,  99-MHz, -			USB_DP		AF10	+-
// PA13, AL,  50-MHz, Pull-up 	TMS			AF00
// PA14, AL,  50-MHz, Pull-down TCK			AF00
// PA15, AL,  50-MHz, Pull-up	TDI			AF00

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(A,KAL,KAL,KAL,KAL,KAL,KAL,KIN,KAL,KAL,KAL,KAL,KOU,KAN,KIN,KIN,KIN,
			  K50,K50,K50,K99,K99,K99,K50,K99,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KPD,KPU,KNO,KNO,KPU,KNO,KNO,KNO,KPU,KNO,KNO,KPU,KPU,KPU,KPU,
			  A00,A00,A00,A10,A10,A10,A00,A01,A05,A05,A05,A00,A00,A00,A00,A00,
			  KPP,KPP,KPP,KPP,KPP,KOD,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
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
// PD10, OU,  50-MHz, Push-pull	Out			AF00	USB_POWER
// PD11, OU,  50-MHz, Push-pull	Rz_Dis		AF00	CN10 D30
// PD12, OU,  50-MHz, Push-pull	CS_Dis		AF00	CN10 D29
// PD13, OU,  50-MHz, Push-pull	DC_Dis		AF00	CN10 D28
// PD14, OU,  50-MHz, Push-pull	SPI1_NSS	AF00	CN7  D10
// PD15, AL,  50-MHz, Push-pull	TIM4_CH4	AF02	CN7  D9

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(D,KAL,KOU,KOU,KOU,KOU,KOU,KAL,KAL,KAL,KAL,KAL,KOU,KIN,KAL,KAL,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KNO,KNO,KNO,KNO,KNO,KPU,KNO,KNO,KPU,KNO,KNO,KPU,KNO,KNO,KPU,
			  A02,A00,A00,A00,A00,A00,A07,A07,A07,A07,A07,A00,A00,A12,A09,A09,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 1u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PE00, AL,  50-MHz, Push-pull	TIM4_ETR	AF02	CN10 D34
// PE01, OU,  50-MHz, Push-pull	LED_Blue	AF00
// PE02, AL,  50-MHz, Push-pull	QSPI1_IO2	AF09	CN10 D31 (see note 3)
// PE03, AL,  50-MHz, Push-pull	SAI1_SD_B	AF06	CN9  D60
// PE04, AL,  50-MHz, Push-pull	SAI1_FS_A	AF06	CN9  D57
// PE05, AL,  50-MHz, Push-pull	TIM15_CH1	AF04	CN9  D58
// PE06, AL,  50-MHz, Push-pull	SAI1_SD_A	AF06	CN9  D59
// PE07, AL,  50-MHz, Push-pull	TIM1_ETR	AF01	CN10 D41
// PE08, AL,  50-MHz, Push-pull	TIM1_CH1N	AF01	CN10 D42
// PE09, AL,  50-MHz, Push-pull	TIM1_CH1	AF01	CN10 D6
// PE10, AL,  50-MHz, Push-pull	TIM1_CH2N	AF01	CN10 D40
// PE11, AL,  99-MHz, Push-pull	TIM1_CH2	AF01	CN10 D5
// PE12, AL,  50-MHz, Push-pull	SCK4		AF05	CN10 D39
// PE13, AL,  99-MHz, Push-pull	TIM1_CH3	AF01	CN10 D3
// PE14, AL,  50-MHz, Push-pull	MOSI4		AF05	CN10 D38
// PE15, AL,  50-MHz, Pull-up	TIM1_BKIN	AF01	CN10 D35

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(E,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KOU,KAL,
			  K50,K99,K99,K99,K99,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KNO,KNO,KNO,KNO,KOU,KNO,KNO,KNO,KPU,KNO,KNO,KPU,KPU,KNO,KNO,
			  A01,A05,A01,A05,A01,A01,A01,A01,A01,A06,A04,A06,A06,A09,A00,A02,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PF00, AL,  50-MHz, Open DU	I2C2_SDA	AF04	CN9  D68
// PF01, AL,  50-MHz, Open DU	I2C2_SCL	AF04	CN9  D69
// PF02, AL,  50-MHz, Push-pull	I2C2_SMBA	AF04	CN9  D70
// PF03, AN,  50-MHz, Push-pull	ADC			AF00	CN7  D8
// PF04, AN,  50-MHz, Push-pull	ADC			AF00	CN10 A8
// PF05, AN,  50-MHz, Push-pull	ADC			AF00	CN9  A4
// PF06, AN,  50-MHz, Push-pull	ADC			AF00	CN11 9
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
	CNFGPIO(F,KOU,KOU,KOU,KOU,KOU,KAN,KAL,KAL,KAL,KAN,KAN,KAN,KAN,KAL,KAL,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KNO,KNO,KNO,KNO,KPU,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KPU,KPU,KPU,
			  A00,A00,A00,A00,A00,A00,A06,A06,A06,A00,A00,A00,A00,A04,A04,A04,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KOD,KOD,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PG00, OU,  50-MHz, Push-pull	Out			AF00	CN9  D65
// PG01, OU,  50-MHz, Push-pull	Out			AF00	CN9  D64
// PG02, IN,  50-MHz, Pull-up	IN			AF00	CN8  D49
// PG03, OU,  50-MHz, Push-pull	Out			AF00	CN8  D50
// PG04, OU,  50-MHz, Push-pull	Out			AF00	CN12 69
// PG05, OU,  50-MHz, Push-pull	Out			AF00	CN12 68
// PG06, IN,  50-MHz, Pull-up	--------	AF00
// PG07, IN,  50-MHz, Pull-up	In			AF00	USB_FAULT
// PG08, OU,  50-MHz, Push-pull	Out			AF00	CN12 66
// PG09, AL,  50-MHz, Pull-up	USART6_RX	AF07	CN10 D0
// PG10, OU,  50-MHz, Push-pull	Out			AF00	CN11 66
// PG11, IN,  50-MHz, Pull-up	--------	AF00
// PG12, OU,  50-MHz, Push-pull	Out			AF00	CN11 65
// PG13, IN,  50-MHz, Pull-up	--------	AF00
// PG14, AL,  50-MHz, Push-pull	USART6_TX	AF07	CN10 D1
// PG15, OU,  50-MHz, Push-pull	Out			AF00	CN11 64

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(G,KOU,KAL,KIN,KOU,KIN,KOU,KAL,KOU,KIN,KIN,KOU,KOU,KOU,KIN,KOU,KOU,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KNO,KPU,KNO,KPU,KNO,KPU,KNO,KPU,KPU,KNO,KNO,KNO,KPU,KNO,KNO,
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
 * PLL1 P: 			480-MHz	clock CPU
 * 	- HPRE    / 2: 	240-MHz AXI & AHB1, AHB2, AHB3, AHB4 periph clocks
 * 	- D1PPRE  / 2:	120-MHz APB3 peripheral clock
 * 	- D2PPRE1 / 4:	 60-MHz APB1 peripheral clock
 * 	- D2PPRE2 / 4:	 60-MHz APB2 peripheral clock
 * 	- D3PPRE  / 2:	120-MHz APB4 peripheral clock
 *
 * PLL1 Q:			240-MHz	clock usable for the peripherals via the PKSU & PKEU units
 * PLL1 R:			120-MHz	clock usable for the peripherals via the PKSU & PKEU units
 *
 * PLL2 P: 			100-MHz	clock usable for the peripherals via the PKSU & PKEU units
 * PLL2 Q:			50-MHz	clock usable for the peripherals via the PKSU & PKEU units
 * PLL2 R:			25-MHz	clock usable for the peripherals via the PKSU & PKEU units
 *
 * PLL3 P: 			120-MHz	clock usable for the peripherals via the PKSU & PKEU units
 * PLL3 Q:			48-MHz	clock usable for the peripherals via the PKSU & PKEU units
 * PLL3 R:			120-MHz	clock usable for the peripherals via the PKSU & PKEU units
 *
 * The RCC clock muxs are modified only for the RNG & USB. For all the other peripherals the default position is used.
 * For the main peripherals used by uKOS-X means:
 *
 * SPI 1,2,3								ck = PLL1 Q
 * SPI 4,5									ck = rcc_pclk2 -> APB2
 * SPI 6									ck = rcc_pclk4 -> APB4
 * QUAD SPI									ck = rcc_hclk3 -> AHB3
 * I2C 1,2,3								ck = rcc_pclk1 -> APB1
 * I2C 4									ck = rcc_pclk4 -> APB4
 * LPUSART 1								ck = rcc_pclk4 -> APB4
 * USART 1,6								ck = rcc_pclk2 -> APB2
 * USART 2,3,4,5,7,8						ck = rcc_pclk1 -> APB1
 * FMC										ck = rcc_hclk3 -> AHB3
 * ADC 1,2,3								ck = PLL2 P
 * RNG										ck = PLL1 Q
 * USB										ck = PLL3 Q
 * LPTIM 1									ck = rcc_pclk1 -> APB1
 * LPTIM 2,3,4,5							ck = rcc_pclk4 -> APB4
 * TIM 1,2,3,4,5,6,7,8,12,13,14,15,16,17	ck = ??? -> A??
 *
 */
static	void	local_RCC_Configuration(void) {

	RCC->CSR       |= RCC_CSR_LSION;					// Enable the LSI
	RCC->CR         = RCC_CR_HSION						// Set HSION bit
					| RCC_CR_HSEON						// Set HSEON bit
					| RCC_CR_RC48ON;					// Set HSI48ON bit

	RCC->CFGR       = 0x00000000u;						// Reset CFGR registe
	RCC->D1CFGR     = 0x00000000u;						// Reset D1CFGR register
	RCC->D2CFGR     = 0x00000000u;						// Reset D2CFGR register
	RCC->D3CFGR     = 0x00000000u;						// Reset D3CFGR register
	RCC->PLLCKSELR  = 0x00000000u;						// Reset PLLCKSELR register
	RCC->PLLCFGR    = 0x00000000u;						// Reset PLLCFGR register
	RCC->PLL1DIVR   = 0x00000000u;						// Reset PLL1DIVR register
	RCC->PLL1FRACR  = 0x00000000u;						// Reset PLL1FRACR register
	RCC->PLL2DIVR   = 0x00000000u;						// Reset PLL2DIVR register
	RCC->PLL2FRACR  = 0x00000000u;						// Reset PLL2FRACR register
	RCC->PLL3DIVR   = 0x00000000u;						// Reset PLL3DIVR register
	RCC->PLL3FRACR  = 0x00000000u;						// Reset PLL3FRACR register
	RCC->CIER       = 0x00000000u;						// Disable all interrupts
	*((volatile uint32_t *)0x51008108u) = 0x000000001u;	// Change the switch matrix read issuing capability to 1 for the AXI SRAM target (Target 7)

	while ((RCC->CR & RCC_CR_RC48RDY) == 0u) { ; }		// Waiting for the 48-MHz

// Source for the PLL 1 , 2 & 3 input clock (see DM00314099 pages 296, 309 & 348)

	RCC->PLLCKSELR = (0u * RCC_PLLCKSELR_PLLSRC_0)		// PLL1, 2, 3 source HSI (64-MHz)
				   | (4u * RCC_PLLCKSELR_DIVM1_0)		// DivM1 / 4
				   | (4u * RCC_PLLCKSELR_DIVM2_0)		// DivM2 / 4
				   | (4u * RCC_PLLCKSELR_DIVM3_0);		// DivM3 / 4

// PLL 1 CPU
// ---------

// For f(ck in) = 16-MHz
// f(vco) = f(ck in) * (N + 1)   f(vco) = 16-MHz, N = 59 ---> f(vco) = 960-MHz
// f(P) = f(vco) / (P + 1) P = 1 			 			 ---> f(P) = 480
// f(Q) = f(vco) / (Q + 1) Q = 3 			 			 ---> f(Q) = 240
// f(R) = f(vco) / (R + 1) R = 7 			 			 ---> f(R) = 120

	RCC->PLLCFGR |= RCC_PLLCFGR_DIVR1EN					// Div R enable
				  | RCC_PLLCFGR_DIVQ1EN					// Div Q enable
				  | RCC_PLLCFGR_DIVP1EN					// Div P enable
				  | (3u * RCC_PLLCFGR_PLL1RGE_0);		// Input 16-MHz

	RCC->PLL1DIVR = (7u * RCC_PLL1DIVR_DIVR1_0)			// Div R
				  | (3u * RCC_PLL1DIVR_DIVQ1_0)			// Div Q
				  | (1u * RCC_PLL1DIVR_DIVP1_0)			// Div P
				  | (59u * RCC_PLL1DIVR_DIVN1_0);		// Div N 59 = 960-MHz

	RCC->PLL1FRACR  = 0x00000000u;						// Reset PLL1FRACR register
	RCC->CR        |= RCC_CR_PLL1ON;					// PLL1 on

// Waiting for the lock

	while ((RCC->CR & RCC_CR_PLL1RDY) == 0u) { ; }		// Waiting for the lock of the PLL

// PLL 2 CPU
// ---------

// For f(ck in) = 16-MHz
// f(vco) = f(ck in) * (N + 1)	 f(vco) = 16-MHz, N = 24 ---> f(vco) = 400-MHz
// f(P) = f(vco) / (P + 1) P = 3 			 			 ---> f(P) = 100
// f(Q) = f(vco) / (Q + 1) Q = 7 			 			 ---> f(Q) = 50
// f(R) = f(vco) / (R + 1) R = 15 			 			 ---> f(R) = 25

	RCC->PLLCFGR |= RCC_PLLCFGR_DIVR2EN					// Div R enable
				  | RCC_PLLCFGR_DIVQ2EN					// Div Q enable
				  | RCC_PLLCFGR_DIVP2EN					// Div P enable
				  | (3u * RCC_PLLCFGR_PLL2RGE_0);		// Input 16-MHz

	RCC->PLL2DIVR = (15u * RCC_PLL2DIVR_DIVR2_0)		// Div R
				  | (7u * RCC_PLL2DIVR_DIVQ2_0)			// Div Q
				  | (3u * RCC_PLL2DIVR_DIVP2_0)			// Div P
				  | (24u * RCC_PLL2DIVR_DIVN2_0);		// Div N 24 = 400-MHz

	RCC->PLL2FRACR  = 0x00000000u;						// Reset PLL2FRACR register
	RCC->CR        |= RCC_CR_PLL2ON;					// PLL2 on

// Waiting for the lock

	while ((RCC->CR & RCC_CR_PLL2RDY) == 0u) { ; }		// Waiting for the lock of the PLL

// PLL 3 CPU
// ---------

// For f(ck in) = 16-MHz
// f(vco) = f(ck in) * (N + 1)	 f(vco) = 16-MHz, N = 14 ---> f(vco) = 240-MHz
// f(P) = f(vco) / (P + 1) P = 1 			 			 ---> f(P) = 120
// f(Q) = f(vco) / (Q + 1) Q = 4 			 			 ---> f(Q) = 48
// f(R) = f(vco) / (R + 1) R = 1 			 			 ---> f(R) = 120

	RCC->PLLCFGR |= RCC_PLLCFGR_DIVR3EN					// Div R enable
				  | RCC_PLLCFGR_DIVQ3EN					// Div Q enable
				  | RCC_PLLCFGR_DIVP3EN					// Div P enable
				  | (3u * RCC_PLLCFGR_PLL3RGE_0);		// Input 16-MHz

	RCC->PLL3DIVR = (1u * RCC_PLL3DIVR_DIVR3_0)			// Div R
				  | (4u * RCC_PLL3DIVR_DIVQ3_0)			// Div Q
				  | (1u * RCC_PLL3DIVR_DIVP3_0)			// Div P
				  | (14u * RCC_PLL3DIVR_DIVN3_0);		// Div N 14 = 240-MHz

	RCC->PLL3FRACR  = 0x00000000u;						// Reset PLL3FRACR register
	RCC->CR        |= RCC_CR_PLL3ON;					// PLL3 on

// Waiting for the lock

	while ((RCC->CR & RCC_CR_PLL3RDY) == 0u) { ; }		// Waiting for the lock of the PLL

// Domain clocks
// -------------

	RCC->D1CFGR = (0u * RCC_D1CFGR_D1CPRE_0)			// D1CPRE / 1
				| (0u * RCC_D1CFGR_D1PPRE_0)			// D1PPRE / 1
				| (8u * RCC_D1CFGR_HPRE_0);				// HPRE / 2

	RCC->D2CFGR = (4u * RCC_D2CFGR_D2PPRE2_0)			// D2PPRE2 / 2
				| (4u * RCC_D2CFGR_D2PPRE1_0);			// D2PPRE1 / 2

	RCC->D3CFGR = (4u * RCC_D3CFGR_D3PPRE_0);			// D3PPRE / 2

// RNG & USB clocks
// ----------------

	RCC->D2CCIP2R = (1 * RCC_D2CCIP2R_RNGSRC_0)			// Set the clock for the RNG @ KFREQUENCY_PLL1Q (200-MHz)
				  | (2 * RCC_D2CCIP2R_USBSRC_0);		// Set the clock for the USB @ KFREQUENCY_PLL3Q (48-MHz)

// Flash latency (for 4x0-MHz ... 4 wait states)
// ---------------------------------------------

	FLASH->ACR = (3u * FLASH_ACR_WRHIGHFREQ_0)			// Bus > 385-MHz
			   | (4u * FLASH_ACR_LATENCY_0);			// 4 wait states

	RCC->CFGR = (4u * RCC_CFGR_MCO1SEL_0)				// MCO1 HSI48
			  | (1u * RCC_CFGR_MCO1PRE_0)				// prescaler / 1
			  | (3u * RCC_CFGR_SW_0);					// CPU clock = PLL
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
	SET_MPU7_REGION(0u, 0u,	ST_FLASH_INT_0,		SZ_FLASH_INT_0,		KMPU_EXECUTABLE,		KMPU_R_ALL,		KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(1u, 0u,	ST_RAM_INT_0,		SZ_RAM_INT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(2u, 0u,	ST_RAM_INT_1,		SZ_RAM_INT_1,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(3u, 0u,	ST_RAM_INT_2_OS,	SZ_RAM_INT_2_OS,	KMPU_EXECUTABLE,		KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(4u, 0u,	ST_PERIPH_SOC,		SZ_PERIPH_SOC,		KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_BUFFERABLE);
	SET_MPU7_REGION(5u, 0u,	ST_PERIPH_CORE,		SZ_PERIPH_CORE,		KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_BUFFERABLE);

	#else
	SET_MPU7_REGION(0u, 0u,	ST_FLASH_INT_0,		SZ_FLASH_INT_0,		KMPU_EXECUTABLE,		KMPU_R_ALL,		KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(1u, 0u,	ST_RAM_INT_0,		SZ_RAM_INT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(2u, 0u,	ST_RAM_INT_1,		SZ_RAM_INT_1,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(3u, 0u,	ST_RAM_INT_2,		SZ_RAM_INT_2,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	#endif

// Enable branch prediction
// Normally not necessary (always on)

	SCB->CCR |= (1u<<18u);
	DATA_SYNC_BARRIER;
}

/*
 * \brief local_CACHE_Enable
 *
 * - Enable the L1 instruction & the data caches
 *
 */
static	void	local_CACHE_Enable(void) {

	cache_I_Invalidate();
	cache_I_Enable();

	cache_D_Invalidate();
	cache_D_Enable();
}

#include	"model_I_D_cache.c_inc"
