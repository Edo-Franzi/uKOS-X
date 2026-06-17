/*
; init.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2026-05-14
; Modifs:
;
; Project:	uKOS-X
; Goal:		Low level init for the uKOS-X Firefly_H743 module.
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

#undef	SELF_REFRESH_S				// Refresh under the control of the SDRAM chip

// SDRAM macro

#define	SDRAM_COMMAND_BANK_CTB1(command, mrd, cycles)			\
			do {												\
				FMC->SDCMR = ((uint32_t)((mrd))<<9u)			\
						   | ((uint32_t)((cycles))<<5u)			\
						   | (1u<<4u)							\
						   | ((uint32_t)((command)));			\
			} while (0)

// Prototypes

static			void	local_GPIO_Configuration(void);
static			void	local_PWR_Configuration(void);
static			void	local_RCC_Configuration(void);
static			void	local_FMC_Configuration(void);
static			void	local_MPU_Configuration(void);
static			void	local_FPE_Configuration(void);
static			void	local_wait_us(uint32_t us);
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
	local_FMC_Configuration();
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

// Init all the GPIO A, B, C, D, E, F, G, H

// PA00, IN,  50-MHz, Pull-down	WK_UP		AF00	P1	11
// PA01, IN,  50-MHz, Pull-down	KEY0		AF00	P1	12
// PA02, AL,  99-MHz, Push-pull	LCD_R1		AF14	P1	13
// PA03, IN,  50-MHz, Pull-up	--------	AF00	P1	16
// PA04, AL,  99-MHz, Pull-up	DCMI_HSYNC	AF13
// PA05, IN,  50-MHz, Pull-up	--------	AF00	P1	18
// PA06, AL,  99-MHz, Pull-up	DCMI_PIXCLK	AF13
// PA07, IN,  50-MHz, Pull-up	--------	AF00	P1	20
// PA08, AL,  99-MHz, Push-pull	LCD_B3		AF13	P1	43
// PA09, AL,  50-MHz, Push-pull	USART1_TX	AF07
// PA10, AL,  50-MHz, Pull-up	USART1_RX	AF07
// PA11, AL,  99-MHz, -			USB_DM		AF10
// PA12, AL,  99-MHz, -			USB_DP		AF10
// PA13, AL,  50-MHz, Pull-up 	SWDIO		AF00	P1	49
// PA14, AL,  50-MHz, Pull-down SWCLK		AF00	P2	44
// PA15, IN,  50-MHz, Pull-up	--------	AF00	P2	43

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(A,KIN,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KIN,KAL,KIN,KAL,KIN,KAL,KIN,KIN,
			  K50,K50,K50,K99,K99,K50,K50,K99,K50,K99,K50,K99,K50,K99,K50,K50,
			  KPU,KPD,KPU,KNO,KNO,KPU,KNO,KNO,KPU,KPU,KPU,KPU,KPU,KNO,KPD,KPD,
			  A00,A00,A00,A10,A10,A07,A07,A13,A00,A13,A00,A13,A00,A14,A00,A00,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PB00, OU,  50-MHz, Push-pull	LED_0		AF00	P1	23
// PB01, OU,  50-MHz, Push-pull	LED_1		AF00	P1	24
// PB02, AL,  99-MHz, Push-pull	QSPI1_CLK	AF09
// PB03, AL,  99-MHz, Push-pull	SPI1_SCK	AF05	P2	27
// PB04, AL,  99-MHz, Pull-up	SPI1_MISO	AF05	P2	26
// PB05, AL,  99-MHz, Push-pull	SPI1_MOSI	AF05	P2	25
// PB06, AL,  99-MHz, Push-pull	QSPI1_NSS	AF10	P2	24
// PB07, AL,  99-MHz, Pull-up	DCMI_VSYNC	AF13	P2	23
// PB08, AL,  99-MHz, Pull-up	DCMI_D6		AF13	P2	22
// PB09, AL,  99-MHz, Pull-up	DCMI_D7		AF13	P2	21
// PB10, OU,  50-MHz, Open DU	DCMI_SDA	AF00	P1	25	i2c soft
// PB11, IN,  50-MHz, Pull-up	--------	AF00	P1	26
// PB12, IN,  50-MHz, Pull-up	--------	AF00	P1	34
// PB13, IN,  50-MHz, Pull-up	--------	AF00	P2	25
// PB14, OU,  50-MHz, Push-pull	--------	AF00	P1	36
// PB15, IN,  50-MHz, Pull-up	--------	AF00	P1	36

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(B,KIN,KOU,KIN,KIN,KIN,KOU,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KOU,KOU,
			  K50,K50,K50,K50,K50,K50,K99,K99,K99,K99,K99,K99,K99,K99,K50,K50,
			  KPU,KNO,KPU,KPU,KPU,KOD,KPU,KPU,KPU,KNO,KNO,KPU,KNO,KNO,KNO,KNO,
			  A00,A00,A00,A00,A00,A00,A13,A13,A13,A10,A05,A05,A05,A09,A00,A00,
			  KPP,KPP,KPP,KPP,KPP,KOD,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 1u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u, 1u, 1u);

// PC00, AL,  99-MHz, Push-pull	FMC_SDNWE	AF12
// PC01, OU,  50-MHz, Push-pull	LCD_POWER	AF00	P1	7
// PC02, IN,  50-MHz, Pull-up	--------	AF00	P1	6
// PC03, IN,  50-MHz, Pull-up	--------	AF00	P1	9
// PC04, OU,  50-MHz, Push-pull	LED_EN		AF00	P1	21
// PC05, OU,  50-MHz, Push-pull	DCMI_RST	AF00	P1	22
// PC06, AL,  99-MHz, Push-pull	DCMI_D0		AF13	P1	44
// PC07, AL,  99-MHz, Push-pull	DCMI_D1		AF13	P1	45
// PC08, AL,  99-MHz, Push-pull	SDMMC1_D0	AF12	P1	46	DCMI_D2 muxed with SDMM1_D0
// PC09, AL,  99-MHz, Push-pull	SDMMC1_D1	AF12	P1	47	DCMI_D3 muxed with SDMM1_D1
// PC10, AL,  99-MHz, Push-pull	SDMMC1_D2	AF12	P2	42
// PC11, AL,  99-MHz, Push-pull	SDMMC1_D3	AF12	P2	41	DCMI_D4 muxed with SDMM1_D3
// PC12, AL,  99-MHz, Push-pull	SDMMC1_CLK	AF12	P2	40
// PC13, IN,  50-MHz, Pull-up	--------	AF00	P2	10
// PC14, AL,  50-MHz, -			OSC			AF00
// PC15, AL,  50-MHz, -			OSC			AF00

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(C,KAL,KAL,KIN,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KOU,KOU,KIN,KIN,KOU,KAL,
			  K50,K50,K50,K99,K99,K99,K99,K99,K99,K99,K50,K50,K50,K50,K50,K99,
			  KNO,KNO,KPU,KNO,KPU,KPU,KPU,KPU,KPU,KPU,KNO,KNO,KPU,KPU,KNO,KNO,
			  A00,A00,A00,A12,A12,A12,A12,A12,A13,A13,A00,A00,A00,A00,A00,A12,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 1u, 0u);

// PD00, AL,  99-MHz, Push-pull	FMC_D2		AF12
// PD01, AL,  99-MHz, Push-pull	FMC_D3		AF12
// PD02, AL,  99-MHz, Push-pull	SDMMC1_CMD	AF12	P2	39
// PD03, AL,  99-MHz, Push-pull	DCMI_D5		AF13	P2	38
// PD04, IN,  50-MHz, Pull-up	--------	AF00	P2	37
// PD05, IN,  50-MHz, Pull-up	--------	AF00	P2	36
// PD06, AL,  99-MHz, Push-pull	LCD_B2		AF14	P2	35
// PD07, IN,  50-MHz, Pull-up	--------	AF00	P2	34
// PD08, AL,  99-MHz, Push-pull	FMC_D13		AF12
// PD09, AL,  99-MHz, Push-pull	FMC_D14		AF12
// PD10, AL,  99-MHz, Push-pull	FMC_D15		AF12
// PD11, OU,  50-MHz, Push-pull	LCD_RST		AF00	P1	38
// PD12, OU,  50-MHz, Push-pull	BL_CTR		AF00	P1	39
// PD13, OU,  50-MHz, Push-pull	SPI1_CS		AF00	P1	40
// PD14, AL,  99-MHz, Push-pull	FMC_D0		AF12
// PD15, AL,  99-MHz, Push-pull	FMC_D1		AF12

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(D,KAL,KAL,KOU,KOU,KOU,KAL,KAL,KAL,KIN,KAL,KIN,KIN,KAL,KAL,KAL,KAL,
			  K99,K99,K50,K50,K50,K99,K99,K99,K50,K99,K50,K50,K99,K99,K99,K99,
			  KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KPU,KPU,KPU,KPU,KNO,KNO,KNO,KNO,
			  A12,A12,A00,A00,A00,A12,A12,A12,A00,A14,A00,A00,A13,A12,A12,A12,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PE00, AL,  99-MHz, Push-pull	FMC_NBL0	AF12
// PE01, AL,  99-MHz, Push-pull	FMC_NBL1	AF12
// PE02, IN,  50-MHz, Pull-up	--------	AF00	P2	16
// PE03, IN,  50-MHz, Pull-up	--------	AF00	P2	15
// PE04, IN,  50-MHz, Pull-up	--------	AF00	P2	14
// PE05, AL,  99-MHz, Push-pull	LCD_G0		AF14	P2	13
// PE06, AL,  99-MHz, Push-pull	LCD_G1		AF14	P2	12
// PE07, AL,  99-MHz, Push-pull	FMC_D4		AF12
// PE08, AL,  99-MHz, Push-pull	FMC_D5		AF12
// PE09, AL,  99-MHz, Push-pull	FMC_D6		AF12
// PE10, AL,  99-MHz, Push-pull	FMC_D7		AF12
// PE11, AL,  99-MHz, Push-pull	FMC_D8		AF12
// PE12, AL,  99-MHz, Push-pull	FMC_D9		AF12
// PE13, AL,  99-MHz, Push-pull	FMC_D10		AF12
// PE14, AL,  99-MHz, Push-pull	FMC_D11		AF12
// PE15, AL,  99-MHz, Push-pull	FMC_D12		AF12

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(E,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KIN,KIN,KIN,KAL,KAL,
			  K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,K50,K50,K50,K99,K99,
			  KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KPU,KPU,KNO,KNO,
			  A12,A12,A12,A12,A12,A12,A12,A12,A12,A14,A14,A00,A00,A00,A12,A12,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PF00, AL,  99-MHz, Push-pull	FMC_A0		AF12
// PF01, AL,  99-MHz, Push-pull	FMC_A1		AF12
// PF02, AL,  99-MHz, Push-pull	FMC_A2		AF12
// PF03, AL,  99-MHz, Push-pull	FMC_A3		AF12
// PF04, AL,  99-MHz, Push-pull	FMC_A4		AF12
// PF05, AL,  99-MHz, Push-pull	FMC_A5		AF12
// PF06, AL,  99-MHz, Push-pull	QSPI1_IO3	AF09
// PF07, AL,  99-MHz, Push-pull	QSPI1_IO2	AF09
// PF08, AL,  99-MHz, Push-pull	QSPI1_IO0	AF10
// PF09, AL,  99-MHz, Push-pull	QSPI1_IO1	AF10
// PF10, AL,  99-MHz, Push-pull	LCD_DE		AF14	P1	10
// PF11, AL,  99-MHz, Push-pull	FMC_SDNRAS	AF12
// PF12, AL,  99-MHz, Push-pull	FMC_A6		AF12
// PF13, AL,  99-MHz, Push-pull	FMC_A7		AF12
// PF14, AL,  99-MHz, Push-pull	FMC_A8		AF12
// PF15, AL,  99-MHz, Push-pull	FMC_A9		AF12

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(F,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,
			  K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,
			  KNO,KNO,KNO,KNO,KNO,KNO,KPU,KPU,KPU,KPU,KNO,KNO,KNO,KNO,KNO,KNO,
			  A12,A12,A12,A12,A12,A14,A10,A10,A09,A09,A12,A12,A12,A12,A12,A12,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PG00, AL,  99-MHz, Push-pull	FMC_A10		AF12
// PG01, AL,  99-MHz, Push-pull	FMC_A11		AF12
// PG02, AL,  99-MHz, Push-pull	FMC_A12		AF12
// PG03, OU,  50-MHz, Open DU	DCMI_SCL	AF00	P1	41  i2c soft
// PG04, AL,  99-MHz, Push-pull	BA0			AF12
// PG05, AL,  99-MHz, Push-pull	BA1			AF12
// PG06, AL,  99-MHz, Push-pull	LCD_R7		AF14	P1	42
// PG07, AL,  99-MHz, Push-pull	LCD_PCLK	AF14
// PG08, AL,  99-MHz, Push-pull	FMC_SDCLK	AF12
// PG09, IN,  50-MHz, Pull-up	--------	AF15	P2	33
// PG10, IN,  50-MHz, Pull-up	--------	AF15	P2	32
// PG11, IN,  50-MHz, Pull-up	--------	AF15	P2	31
// PG12, AL,  99-MHz, Push-pull	LCD_B1		AF14	P2	30
// PG13, AL,  99-MHz, Push-pull	LCD_R0		AF14	P2	29
// PG14, AL,  99-MHz, Push-pull	LCD_B0		AF14	P2	28
// PG15, AL,  99-MHz, Push-pull	FMC_SDNCAS	AF12

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(G,KAL,KAL,KAL,KAL,KIN,KIN,KIN,KAL,KAL,KAL,KAL,KAL,KIN,KAL,KAL,KAL,
			  K99,K99,K99,K99,K50,K50,K50,K99,K99,K99,K99,K99,K50,K99,K99,K99,
			  KNO,KNO,KNO,KNO,KPU,KPU,KPU,KNO,KNO,KNO,KNO,KNO,KOD,KNO,KNO,KNO,
			  A12,A14,A14,A14,A00,A00,A00,A12,A14,A14,A12,A12,A00,A12,A12,A12,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u);

// PH00, AL,  50-MHz, -			OSC			AF00
// PH01, AL,  50-MHz, -			OSC			AF00
// PH02, AL,  99-MHz, Push-pull	FMC_SDCKE0	AF12
// PH03, AL,  99-MHz, Push-pull	FMC_SDNEE0	AF12
// PH04, AL,  50-MHz, Open DU	I2C2_SCL	AF04	P1	12
// PH05, AL,  50-MHz, Open DU	I2C2_SDA	AF04	P1	13
// PH06, OU,  50-MHz, Push-pull	LCD_DC		AF00	P1	27
// PH07, IN,  50-MHz, Pull-up	--------	AF00	P1	28
// PH08, AL,  99-MHz, Push-pull	LCD_R2		AF14	P1	29
// PH09, AL,  99-MHz, Push-pull	LCD_R3		AF14	P1	30
// PH10, AL,  99-MHz, Push-pull	LCD_R4		AF14	P1	31
// PH11, AL,  99-MHz, Push-pull	LCD_R5		AF14	P1	32
// PH12, AL,  99-MHz, Push-pull	LCD_R6		AF14	P1	33
// PH13, AL,  99-MHz, Push-pull	LCD_G2		AF14	P1	50
// PH14, AL,  99-MHz, Push-pull	LCD_G3		AF14	P2	50
// PH15, AL,  99-MHz, Push-pull	LCD_G4		AF14	P2	49

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(H,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KIN,KOU,KAL,KAL,KAL,KAL,KAL,KAL,
			  K99,K99,K99,K99,K99,K99,K99,K99,K50,K50,K50,K50,K99,K99,K50,K50,
			  KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KPU,KPU,KNO,KNO,KNO,KNO,
			  A14,A14,A14,A14,A14,A14,A14,A14,A00,A00,A04,A04,A12,A12,A00,A00,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KOD,KOD,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u);

// PI00, AL,  99-MHz, Push-pull	LCD_G5		AF14	P2	48
// PI01, AL,  99-MHz, Push-pull	LCD_G6		AF14	P2	47
// PI02, AL,  99-MHz, Push-pull	LCD_G7		AF14	P2	46
// PI03, OU,  50-MHz, Push-pull	DCMI_PWDN	AF00	P2	45
// PI04, AL,  99-MHz, Push-pull	LCD_B4		AF14
// PI05, AL,  99-MHz, Push-pull	LCD_B5		AF14
// PI06, AL,  99-MHz, Push-pull	LCD_B6		AF14
// PI07, AL,  99-MHz, Push-pull	LCD_B7		AF14
// PI08, IN,  50-MHz, Pull-up	--------	AF00
// PI09, AL,  50-MHz, Push-pull	LCD_VSYNC	AF14
// PI10, AL,  50-MHz, Push-pull	LCD_HSYNC	AF14
// PI11, IN,  50-MHz, Pull-up	--------	AF00
// PI12, IN,  50-MHz, Pull-up	--------	AF00
// PI13, IN,  50-MHz, Pull-up	--------	AF00
// PI14, IN,  50-MHz, Pull-up	--------	AF00
// PI15, IN,  50-MHz, Pull-up	--------	AF00

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(I,KIN,KIN,KIN,KIN,KIN,KAL,KAL,KIN,KAL,KAL,KAL,KAL,KOU,KAL,KAL,KAL,
			  K50,K50,K50,K50,K50,K99,K99,K50,K99,K99,K99,K99,K50,K99,K99,K99,
			  KPU,KPU,KPU,KPU,KPU,KNO,KNO,KPU,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,
			  A00,A00,A00,A00,A00,A14,A14,A00,A14,A14,A14,A14,A00,A14,A14,A14,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);
}

/*
 * \brief local_RCC_Configuration
 *
 * PLL1 P: 			480-MHz	clock CPU
 * 	- HPRE    / 2: 	240-MHz AXI & AHB1, AHB2, AHB3, AHB4 periph clocks
 * 	- D1PPRE  / 2:	120-MHz APB3 peripheral clock
 * 	- D2PPRE1 / 2:	120-MHz APB1 peripheral clock
 * 	- D2PPRE2 / 2:	120-MHz APB2 peripheral clock
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
 * SDMM										ck = PLL1 Q
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

// Change the switch matrix read issuing capability to 1 for the AXI SRAM target (Target 7)
// Document ES0392, section 2.2.10

	if ((DBGMCU->IDC & 0xFFFF0000U) < 0x20000000U) {
		*((volatile uint32_t *)0x51008108u) = 0x000000001u;
	}

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

	RCC->PLL1FRACR = 0x00000000u;						// Reset PLL1FRACR register
	RCC->CR       |= RCC_CR_PLL1ON;						// PLL1 on

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
				  | (7u  * RCC_PLL2DIVR_DIVQ2_0)		// Div Q
				  | (3u  * RCC_PLL2DIVR_DIVP2_0)		// Div P
				  | (24u * RCC_PLL2DIVR_DIVN2_0);		// Div N 24 = 400-MHz

	RCC->PLL2FRACR = 0x00000000u;						// Reset PLL2FRACR register
	RCC->CR       |= RCC_CR_PLL2ON;						// PLL2 on

// Waiting for the lock

	while ((RCC->CR & RCC_CR_PLL2RDY) == 0u) { ; }		// Waiting for the lock of the PLL

// PLL 3 CPU
// ---------

// For f(ck in) = 16-MHz
// f(vco) = f(ck in) * (N + 1)	 f(vco) = 16-MHz, N = 14 ---> f(vco) = 240-MHz
// f(P) = f(vco) / (P + 1) P = 1 			 			 ---> f(P) = 120
// f(Q) = f(vco) / (Q + 1) Q = 4 			 			 ---> f(Q) = 48
// f(R) = f(vco) / (R + 1) R = 1 			 			 ---> f(R) = 24

	RCC->PLLCFGR |= RCC_PLLCFGR_DIVR3EN					// Div R enable
				  | RCC_PLLCFGR_DIVQ3EN					// Div Q enable
				  | RCC_PLLCFGR_DIVP3EN					// Div P enable
				  | (3u * RCC_PLLCFGR_PLL3RGE_0);		// Input 16-MHz

	RCC->PLL3DIVR = (9u  * RCC_PLL3DIVR_DIVR3_0)		// Div R
				  | (4u  * RCC_PLL3DIVR_DIVQ3_0)		// Div Q
				  | (1u  * RCC_PLL3DIVR_DIVP3_0)		// Div P
				  | (14u * RCC_PLL3DIVR_DIVN3_0);		// Div N 14 = 240-MHz

	RCC->PLL3FRACR = 0x00000000u;						// Reset PLL3FRACR register
	RCC->CR       |= RCC_CR_PLL3ON;						// PLL3 on

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

	RCC->D2CCIP2R = (1u * RCC_D2CCIP2R_RNGSRC_0)		// Set the clock for the RNG @ KFREQUENCY_PLL1Q (200-MHz)
				  | (2u * RCC_D2CCIP2R_USBSRC_0);		// Set the clock for the USB @ KFREQUENCY_PLL3Q (48-MHz)

// Flash latency (for 4x0-MHz ... 4 wait states)
// ---------------------------------------------

	FLASH->ACR = (3u * FLASH_ACR_WRHIGHFREQ_0)			// Bus > 385-MHz
			   | (4u * FLASH_ACR_LATENCY_0);			// 4 wait states

	RCC->CFGR = (4u * RCC_CFGR_MCO1SEL_0)				// MCO1 HSI48
			  | (1u * RCC_CFGR_MCO1PRE_0)				// prescaler / 1
			  | (3u * RCC_CFGR_SW_0);					// CPU clock = PLL

	#ifdef KCALENDAR_WITH_HW_RTC_S

// RTC
// ---

	PWR->CR1 |= PWR_CR1_DBP;							//
	while ((PWR->CR1 & PWR_CR1_DBP) == 0u) { ; }		// Disable backup domain write protection

// Prepare the LSE (disable bypass),

	RCC->BDCR &= ~RCC_BDCR_LSEBYP;						// LSE oscillator not bypassed
	RCC->BDCR &= ~RCC_BDCR_LSEDRV;						//
	RCC->BDCR |=  (3u * RCC_BDCR_LSEDRV_0);				// Highest drive
	RCC->BDCR |=  RCC_BDCR_LSEON;						//
	while ((RCC->BDCR & RCC_BDCR_LSERDY) == 0u) { ; }	// LSE on

// LSE as a clock for the RTC

    RCC->BDCR &= ~RCC_BDCR_RTCSRC;						//
    RCC->BDCR |=  (1u * RCC_BDCR_RTCSRC_0);				// LSE is the source for the RTC
    RCC->BDCR |=  RCC_BDCR_RTCEN;						// RTC enable

	RTC->WPR = RTC_WPR_UNLOCK_KEY1;						//
	RTC->WPR = RTC_WPR_UNLOCK_KEY2;						// Unlock

	RTC->CR &= ~RTC_CR_BYPSHAD;							// Disable the bypass

	RTC->WPR = RTC_WPR_LOCK_KEY;						// Lock
	#endif

}

/*
 * \brief local_FMC_Configuration
 *
 * - FMC configuration
 *
 */
static	void	local_FMC_Configuration(void) {

	RCC->AHB3ENR |= RCC_AHB3ENR_FMCEN;

	local_wait_us(200000u);

	FMC->BCR1 &= ~FMC_BCR1_FMCEN;

	SDRAM_COMMAND_BANK_CTB1(0x0u, 0u,      0u    );		// Normal mode

// FMC bank 5-6 & CE0 configuration in the synchronous mode
// - SDRAM is a W9825G6-6 speed grade, connected to bank 1 (0x70000000).
//
// For SDRAM bank 1, the active configuration is in SDCR[0] / SDTR[0].
// Some bits in SDCR[1] and SDTR[1] are don't care for bank 1,
// but keeping them at 0 avoids unwanted side effects.

	FMC->SDCR1 = (1u * FMC_SDCR1_RPIPE_0)				// 1 clock delay after CAS latency
			   | FMC_SDCR1_RBURST						// Read as bursts
			   | (2u * FMC_SDCR1_SDCLK_0)				// SDRAM runs @ 120-MHz
			   | (3u * FMC_SDCR1_CAS_0)					// CAS latency 3 cycles
			   | FMC_SDCR1_NB							// 4 internal banks
			   | (1u * FMC_SDCR1_MWID_0)				// 16-bit data bus
			   | (2u * FMC_SDCR1_NR_0)					// 13-bit row address
			   | (1u * FMC_SDCR1_NC_0);					// 9-bit column address

	FMC->SDCR2 = 0u;

// One SDRAM clock cycle is 1/120-MHz = 8.3-ns

	FMC->SDTR1 = ((3u - 1u) * FMC_SDTR1_TRCD_0)			// 3 cycle TRCD (24.9-ns > 18-ns)
			   | ((3u - 1u) * FMC_SDTR1_TRP_0)			// 3 cycle TRP (24.9-ns > 18-ns)
			   | ((3u - 1u) * FMC_SDTR1_TWR_0)			// 3 cycle TWR (>= (TRAS - TRCD)
			   | ((8u - 1u) * FMC_SDTR1_TRC_0)			// 8 cycle TRC (66.4-ns > 60-ns)
			   | ((6u - 1u) * FMC_SDTR1_TRAS_0)			// 6 cycle TRAS (49.8-ns > 42-ns)
			   | ((9u - 1u) * FMC_SDTR1_TXSR_0)			// 9 cycle TXSR (74.7-ns > 72-ns)
			   | ((2u - 1u) * FMC_SDTR1_TMRD_0);		// 2 cycle TMRD

	FMC->SDTR2 = 0u;

// SDRam mode register
// Mode: 11 10 09 08   07 06 05 04   03 02 01 00
//        -  -  1  0    0  0  1  1    0  0  0  0
//
// M9      = 1		Write node
// M8 - M7 = 00		Standard operation
// M6 - M4 = 011	CAS latency 3
// M3	   = 0		Sequential
// M2 - M0 = 000	Burst length 1

	SDRAM_COMMAND_BANK_CTB1(0x1u, 0u,      0u      );	// Command Clock Configuration Enable
	local_wait_us(1000000u);

	SDRAM_COMMAND_BANK_CTB1(0x2u, 0u,      0u      );	// Command All Bank Precharge
	SDRAM_COMMAND_BANK_CTB1(0x3u, 0u,     (2u - 1u));	// Command Auto Refresh (2 cycles)
	SDRAM_COMMAND_BANK_CTB1(0x4u, 0x230u,  0u      );	// Command Load Mode Register (CAS latency = 3, burst len = 1 (only Read))

// 64-ms/4096 = 15.625-us
// 15.625-us * 120-MHz = 1875-20 = 1855

	FMC->SDRTR = (1855u * FMC_SDRTR_COUNT_0);			// Refresh timer count
	FMC->BCR1 |= FMC_BCR1_FMCEN;
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
	SET_MPU7_REGION(0u, 0u,	ST_FLASH_INT_0,		SZ_FLASH_INT_0,		KMPU_EXECUTABLE,		KMPU_R_ALL,		KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(1u, 0u,	ST_RAM_INT_0,		SZ_RAM_INT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(2u, 0u,	ST_RAM_INT_1,		SZ_RAM_INT_1,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(3u, 0u,	ST_RAM_INT_2_OS,	SZ_RAM_INT_2_OS,	KMPU_EXECUTABLE,		KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(4u, 0u,	ST_RAM_EXT_0,		SZ_RAM_EXT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(5u, 0u,	ST_RAM_EXT_1,		SZ_RAM_EXT_1,		KMPU_NOT_EXECUTABLE,	KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(6u, 0u,	ST_PERIPH_SOC,		SZ_PERIPH_SOC,		KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_BUFFERABLE);
	SET_MPU7_REGION(7u, 0u,	ST_PERIPH_CORE,		SZ_PERIPH_CORE,		KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_BUFFERABLE);

	#else
	SET_MPU7_REGION(0u, 0u,	ST_FLASH_INT_0,		SZ_FLASH_INT_0,		KMPU_EXECUTABLE,		KMPU_R_ALL,		KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(1u, 0u,	ST_RAM_INT_0,		SZ_RAM_INT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(2u, 0u,	ST_RAM_INT_1,		SZ_RAM_INT_1,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(3u, 0u,	ST_RAM_INT_2,		SZ_RAM_INT_2,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(4u, 0u,	ST_RAM_EXT_0,		SZ_RAM_EXT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(5u, 0u,	ST_RAM_EXT_1,		SZ_RAM_EXT_1,		KMPU_NOT_EXECUTABLE,	KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_NOT_BUFFERABLE);
	#endif

// Enable branch prediction
// Normally not necessary (always on)

	SCB->CCR |= (1u<<18u);
	DATA_SYNC_BARRIER;
}

/*
 * \brief local_wait_us
 *
 * - Wait for an approximative time in us
 *   - The flash has 2 wait states ~ 5-ns
 *   - The loop takes ~ 6 clocks (which is considered to be the margin)
 *
 */
static	void	local_wait_us(uint32_t us) {
	uint32_t	time;

	for (time = 0u; time < us; time++) { NOP; }
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
