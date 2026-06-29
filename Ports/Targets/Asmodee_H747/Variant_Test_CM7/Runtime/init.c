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
; Goal:		Low level init for the uKOS-X Asmodee_H747 module.
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
#include	"cache.h"
#include	"linker.h"
#include	"PF1550/PF1550.h"

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

#define	FULL_JTAG_S					// With the full JTAG available

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
static			void	local_load_PF1550(void);
static			void	local_FMC_Configuration(void);
static			void	local_MPU_Configuration(void);
static			void	local_RAM_SHARED_Configuration(void);
static			void	local_FPE_Configuration(void);
static			void	local_wait_us(uint32_t us);
static			void	local_CACHE_Enable(void);
static			void	local_USB_Configuration(void);
static			void	local_Boot_CM4(void);
static			void	local_writeByte(uint8_t byte);
static			void	local_waitingForFlagOn(uint32_t flag);
static			void	local_waitingForFlagOff(uint32_t flag);

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

	local_PWR_Configuration();
	local_GPIO_Configuration();
	local_RCC_Configuration();
	local_load_PF1550();
	local_FMC_Configuration();
	local_MPU_Configuration();
	local_RAM_SHARED_Configuration();
	local_FPE_Configuration();
	local_USB_Configuration();
	local_CACHE_Enable();
	local_Boot_CM4();
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

	PWR->CR2   = PWR_CR2_BREN;
	PWR->CR3   = (3u * PWR_CR3_SDLEVEL_0) | PWR_CR3_SDEN | PWR_CR3_LDOEN;
	PWR->D3CR &= ~PWR_D3CR_VOS;
	PWR->D3CR  = (2u * PWR_D3CR_VOS_0);
	while ((PWR->D3CR & PWR_D3CR_VOSRDY) == 0u) { ; }

	PWR->D3CR	   = (3u *PWR_D3CR_VOS_0);
	SYSCFG->PWRCR |= SYSCFG_PWRCR_ODEN;
}

/*
 * \brief local_USB_Configuration
 *
 * - Enable the USB
 *
 */
static	void	local_USB_Configuration(void) {

// The PHY was initialised under the GPIO_Configuration
// Enable USB HS & ULPI Clocks

	RCC->AHB1ENR |= RCC_AHB1ENR_USB1ULPIEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_USB1OTGEN;

// No VBUS sense
// B-peripheral session valid override enable

	RCC->AHB1LPENR &= ~RCC_AHB1LPENR_USB2ULPILPEN;

	local_wait_us(20000u);
	OTG1_HS_GLOBAL->OTG_HS_GCCFG   &= ~USB_OTG_GCCFG_VBDEN;
	OTG1_HS_GLOBAL->OTG_HS_GOTGCTL |=  USB_OTG_GOTGCTL_BVALOEN;
	OTG1_HS_GLOBAL->OTG_HS_GOTGCTL |=  USB_OTG_GOTGCTL_BVALOVAL;

// Force the device mode

	local_wait_us(20000u);
	OTG1_HS_GLOBAL->OTG_HS_GUSBCFG &= ~OTG2_HS_GLOBAL_OTG_HS_GUSBCFG_FHMOD;
	OTG1_HS_GLOBAL->OTG_HS_GUSBCFG |=  OTG2_HS_GLOBAL_OTG_HS_GUSBCFG_FDMOD;

// Reset the PHY
// Reset active low

	local_wait_us(20000u);
	GPIOJ->ODR |=			 (1u<<BRZ_PHY); local_wait_us(200u);
	GPIOJ->ODR &= (uint32_t)~(1u<<BRZ_PHY); local_wait_us(200u);
	GPIOJ->ODR |=			 (1u<<BRZ_PHY); local_wait_us(200u);
	local_wait_us(20000u);
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
	RCC->AHB4ENR |= RCC_AHB4ENR_GPIOKEN;

// Init all the GPIO A, B, C, D, E, F, G, H, I, J, K

// PA00, IN,  50-MHz, Pull-up	PUSH0		AF00	PUSH0
// PA01, AN,  50-MHz, Pull-up	ADC			AF00	A1
// PA02, IN,  50-MHz, Pull-up	MDIO		AF00	Ethernet
// PA03, AL,  99-MHz, Push-pull	D0			AF10	USB3320C
// PA04, AL,  50-MHz, Pull-up	HSYNC		AF13
// PA05, AL,  99-MHz, Push-pull	CKOUT		AF10	USB3320C
// PA06, AL,  50-MHz, Pull-up	PIXCLK		AF13
// PA07, IN,  50-MHz, Pull-up	CRS_DIV		AF00	Ethernet
// PA08, OU,  50-MHz, Push-pull	PWM0		AF00
// PA09, AL,  50-MHz, Push-pull	LPUART1_TX	AF03
// PA10, AL,  50-MHz, Pull-up	LPUART1_RX	AF03
// PA11, AL,  99-MHz, -			OTG_FS_N	AF10
// PA12, AL,  99-MHz, -			OTG_FS_P	AF10
// PA13, AL,  50-MHz, Pull-up 	TMS			AF00
// PA14, AL,  50-MHz, Pull-down TCK			AF00

#if (defined(FULL_JTAG_S))
// PA15, AL,  50-MHz, Pull-up 	TDI			AF00

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(A,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KOU,KIN,KAL,KAL,KAL,KAL,KIN,KAN,KIN,
			  K50,K50,K50,K99,K99,K50,K50,K50,K50,K50,K99,K50,K99,K50,K50,K50,
			  KPU,KPD,KPU,KNO,KNO,KPU,KNO,KNO,KPU,KNO,KNO,KNO,KNO,KPU,KPU,KPU,
			  A00,A00,A00,A10,A10,A03,A03,A00,A00,A13,A10,A13,A10,A00,A00,A00,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

#else
// PA15, AL,  50-MHz, Push-pull	UART7_TX	AF11

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(A,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KOU,KIN,KAL,KAL,KAL,KAL,KIN,KAN,KIN,
			  K50,K50,K50,K99,K99,K50,K50,K50,K50,K50,K99,K50,K99,K50,K50,K50,
			  KNO,KPD,KPU,KNO,KNO,KPU,KNO,KNO,KPU,KNO,KNO,KNO,KNO,KPU,KPU,KPU,
			  A11,A00,A00,A10,A10,A03,A03,A00,A00,A13,A10,A13,A10,A00,A00,A00,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);
#endif

// PB00, AL,  99-MHz, Push-pull	D1			AF10	USB3320C
// PB01, AL,  99-MHz, Push-pull	D2			AF10	USB3320C
// PB02, IN,  50-MHz, Pull-up	SW3			AF00	SW3
// PB05, AL,  99-MHz, Push-pull	D7			AF10	USB3320C
// PB06, AL,  50-MHz, Open DU	I2C1_SCL	AF04
// PB07, AL,  50-MHz, Open DU	I2C1_SDA	AF04
// PB08, IN,  50-MHz, Pull-up	SW0			AF00	SW0
// PB09, OU,  50-MHz, Push-pull	SPI2_NSS	AF00	SELMAGNETO
// PB10, AL,  99-MHz, Push-pull	D3			AF10	USB3320C
// PB11, AL,  99-MHz, Push-pull	D4			AF10	USB3320C
// PB12, AL,  99-MHz, Push-pull	D5			AF10	USB3320C
// PB13, AL,  99-MHz, Push-pull	D6			AF10	USB3320C
// PB14, IN,  50-MHz, Pull-up	SW1			AF00	SW1
// PB15, IN,  50-MHz, Pull-up	SW2			AF00	SW2

#if (defined(FULL_JTAG_Ss))
// PB03, AL,  50-MHz, Push-pull	TDO			AF00
// PB04, AL,  50-MHz, Pull-up	NJTRST		AF00

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(B,KIN,KIN,KAL,KAL,KAL,KAL,KOU,KIN,KAL,KAL,KAL,KAL,KAL,KIN,KAL,KAL,
			  K50,K50,K99,K99,K99,K99,K50,K50,K50,K50,K99,K50,K50,K50,K99,K99,
			  KPU,KPU,KNO,KNO,KNO,KNO,KNO,KPU,KPU,KPU,KNO,KPU,KNO,KPU,KNO,KNO,
			  A00,A00,A10,A10,A10,A10,A00,A00,A04,A04,A10,A00,A00,A00,A10,A10,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KOD,KOD,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

#else
// PB03, AL,  50-MHz, Pull-up	SPI1_SCK	AF05	SPI SLAVE Xfer
// PB04, AL,  50-MHz, Push-pull	SPI1_MISO	AF05	SPI SLAVE Xfer

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(B,KIN,KIN,KAL,KAL,KAL,KAL,KOU,KIN,KAL,KAL,KAL,KAL,KAL,KIN,KAL,KAL,
			  K50,K50,K99,K99,K99,K99,K50,K50,K50,K50,K99,K50,K50,K50,K99,K99,
			  KPU,KPU,KNO,KNO,KNO,KNO,KNO,KPU,KPU,KPU,KNO,KNO,KPU,KPU,KNO,KNO,
			  A00,A00,A10,A10,A10,A10,A00,A00,A04,A04,A10,A05,A05,A00,A10,A10,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KOD,KOD,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);
#endif

// PC00, AL,  99-MHz, Push-pull	STP			AF10	USB3320C
// PC01, IN,  50-MHz, Pull-up	MDC			AF00	Ethernet
// PC02, AN,  50-MHz, Pull-up	ADC			AF00	A2
// PC03, AN,  50-MHz, Pull-up	ADC			AF00	A3
// PC04, IN,  50-MHz, Pull-up	RXD0		AF00	Ethernet
// PC05, IN,  50-MHz, Pull-up	RXD1		AF00	Ethernet
// PC06, OU,  50-MHz, Push-pull	PWM1		AF00
// PC07, OU,  50-MHz, Push-pull	PWM2		AF00
// PC08, AL,  50-MHz, Push-pull	SDMMC1_D0	AF12
// PC09, AL,  50-MHz, Push-pull	SDMMC1_D1	AF12
// PC10, AL,  50-MHz, Push-pull	SDMMC1_D2	AF12
// PC11, AL,  50-MHz, Push-pull	SDMMC1_D3	AF12
// PC12, AL,  50-MHz, Push-pull	SDMMC1_CLK	AF12
// PC13, IN,  50-MHz, Pull-up	GPIO0		AF00
// PC14, AL,  50-MHz, -			OSC			AF00	32KHz in
// PC15, OU,  50-MHz, Push-pull	CAMERA_OI1	AF00	CAMERA_OI1 (DEN_AG)

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(C,KOU,KAL,KIN,KAL,KAL,KAL,KAL,KAL,KOU,KOU,KIN,KIN,KAN,KAN,KIN,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K99,
			  KNO,KNO,KPU,KPU,KPU,KPU,KPU,KPU,KNO,KNO,KPU,KPU,KPU,KPU,KPU,KNO,
			  A00,A00,A00,A12,A12,A12,A12,A12,A00,A00,A00,A00,A00,A00,A00,A10,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PD00, AL,  99-MHz, Pull-up	FMC_D2		AF12
// PD01, AL,  99-MHz, Pull-up	FMC_D3		AF12
// PD02, AL,  50-MHz, Push-pull	SDMMC1_CMD	AF12
// PD03, AL,  50-MHz, Push-pull	I2S2_CK		AF05
// PD04, OU,  50-MHz, Push-pull	CAMERA_OI2	AF00	CAMERA_OI2 (Standby)
// PD05, OU,  50-MHz, Push-pull	CAMERA_OI3	AF00	CAMERA_OI3 (Exposure)
// PD06, OU,  50-MHz, Push-pull	LED6		AF00	LED6
// PD07, AL,  50-MHz, Pull-up	SPI1_MOSI	AF05	SPI SLAVE Xfer
// PD08, AL,  99-MHz, Push-pull	FMC_D13		AF12
// PD09, AL,  99-MHz, Push-pull	FMC_D14		AF12
// PD10, AL,  99-MHz, Push-pull	FMC_D15		AF12
// PD11, AL,  50-MHz, Push-pull	QSPI1_IO0	AF09
// PD12, AL,  50-MHz, Push-pull	QSPI1_IO1	AF09
// PD13, AL,  50-MHz, Push-pull	QSPI1_IO3	AF09
// PD14, AL,  99-MHz, Push-pull	FMC_D0		AF12
// PD15, AL,  99-MHz, Push-pull	FMC_D1		AF12

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(D,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KOU,KOU,KOU,KAL,KAL,KAL,KAL,
			  K99,K99,K50,K50,K50,K99,K99,K99,K50,K50,K50,K50,K50,K50,K99,K99,
			  KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KPU,KNO,KNO,KNO,KNO,KNO,KNO,KNO,
			  A12,A12,A09,A09,A09,A12,A12,A12,A05,A00,A00,A00,A05,A12,A12,A12,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PE00, AL,  99-MHz, Push-pull	FMC_NBL0	AF12
// PE01, AL,  99-MHz, Push-pull	FMC_NBL1	AF12
// PE02, OU,  50-MHz, Push-pull	LED7		AF00	LED7
// PE03, IN,  50-MHz, Pull-up	CAMERA_OI4	AF00	CAMERA_OI4 (INTIMU)
// PE04, AL,  50-MHz, Push-pull	SAI1_FS_A	AF06
// PE05, AL,  50-MHz, Push-pull	SAI1_SCK_A	AF06
// PE06, AL,  50-MHz, Push-pull	SAI1_SD_A	AF06
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
	CNFGPIO(E,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KIN,KOU,KAL,KAL,
			  K99,K99,K99,K99,K99,K99,K99,K99,K99,K50,K50,K50,K50,K50,K99,K99,
			  KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KPU,KNO,KNO,KNO,
			  A12,A12,A12,A12,A12,A12,A12,A12,A12,A06,A06,A06,A00,A00,A12,A12,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PF00, AL,  99-MHz, Push-pull	FMC_A0		AF12
// PF01, AL,  99-MHz, Push-pull	FMC_A1		AF12
// PF02, AL,  99-MHz, Push-pull	FMC_A2		AF12
// PF03, AL,  99-MHz, Push-pull	FMC_A3		AF12
// PF04, AL,  99-MHz, Push-pull	FMC_A4		AF12
// PF05, AL,  99-MHz, Push-pull	FMC_A5		AF12
// PF06, AL,  50-MHz, Pull-up	UART7_RX	AF07
// PF07, AL,  50-MHz, Push-pull	QSPI1_IO2	AF09
// PF08, AL,  50-MHz, Push-pull	UART7_RTS	AF07
// PF09, AL,  50-MHz, Pull-up	UART7_CTS	AF07
// PF10, AL,  50-MHz, Push-pull	QSPI1_SCK	AF09
// PF11, AL,  99-MHz, Push-pull	FMC_RAS		AF12
// PF12, AL,  99-MHz, Push-pull	FMC_A6		AF12
// PF13, AL,  99-MHz, Push-pull	FMC_A7		AF12
// PF14, AL,  99-MHz, Push-pull	FMC_A8		AF12
// PF15, AL,  99-MHz, Push-pull	FMC_A9		AF12

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(F,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,
			  K99,K99,K99,K99,K99,K50,K50,K50,K50,K50,K99,K99,K99,K99,K99,K99,
			  KNO,KNO,KNO,KNO,KNO,KNO,KPU,KNO,KNO,KPU,KNO,KNO,KNO,KNO,KNO,KNO,
			  A12,A12,A12,A12,A12,A09,A07,A07,A09,A07,A12,A12,A12,A12,A12,A12,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PG00, AL,  99-MHz, Push-pull	FMC_A10		AF12
// PG01, AL,  99-MHz, Push-pull	FMC_A11		AF12
// PG02, AL,  99-MHz, Push-pull	FMC_A12		AF12
// PG03, OU,  50-MHz, Push-pull	CAMERA_OI5	AF00	CAMERA_OI5 (SELACCELERO)
// PG04, AL,  99-MHz, Push-pull	FMC_BA0		AF12
// PG05, AL,  99-MHz, Push-pull	FMC_BA1		AF12
// PG06, AL,  50-MHz, Push-pull	QSPI1_CS	AF10
// PG07, OU,  50-MHz, Push-pull	PWM3		AF00
// PG08, AL,  99-MHz, Pull-up	FMC_CLK		AF12
// PG09, AL,  50-MHz, Pull-up	UART6_RX	AF07	Console C
// PG10, AL,  50-MHz, Pull-up	SPI1_NSS	AF05	SPI SLAVE Xfer
// PG11, IN,  50-MHz, Pull-up	TXEN		AF00	Ethernet
// PG12, IN,  50-MHz, Pull-up	TXD1		AF00	Ethernet
// PG13, IN,  50-MHz, Pull-up	TXD0		AF00	Ethernet
// PG14, AL,  50-MHz, Push-pull	USART6_TX	AF07	Console C
// PG15, AL,  99-MHz, Push-pull	FMC_CAS		AF12

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(G,KAL,KAL,KIN,KIN,KIN,KAL,KAL,KAL,KOU,KAL,KAL,KAL,KOU,KAL,KAL,KAL,
			  K99,K50,K50,K50,K50,K50,K50,K99,K50,K50,K99,K99,K50,K99,K99,K99,
			  KNO,KNO,KPU,KPU,KPU,KPU,KPU,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,
			  A12,A07,A00,A00,A00,A05,A07,A12,A00,A10,A12,A12,A00,A12,A12,A12,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 1u, 0u, 0u, 0u);

// PH00, AL,  50-MHz, -			OSC			AF00	25-MHz in
// PH01, OU,  50-MHz, Push-pull	OSCEN		AF00	Clock enable
// PH02, AL,  99-MHz, Push-pull	FMC_CKE		AF12
// PH03, AL,  99-MHz, Push-pull	FMC_NE0		AF12
// PH04, AL,  99-MHz, Pull-up	NXT			AF10	USB3320C
// PH05, AL,  99-MHz, Push-pull	FMC_WE		AF12
// PH06, OU,  50-MHz, Push-pull	PWM9		AF00
// PH07, AL,  50-MHz, Open DU	I2C3_SCL	AF04
// PH08, AL,  50-MHz, Open DU	I2C3_SDA	AF04
// PH09, AL,  50-MHz, Push-pull	DCMI_D0		AF13
// PH10, AL,  50-MHz, Push-pull	DCMI_D1		AF13
// PH11, AL,  50-MHz, Push-pull	DCMI_D2		AF13
// PH12, AL,  50-MHz, Push-pull	DCMI_D3		AF13
// PH13, OU,  50-MHz, Push-pull	LED5		AF00	LED5
// PH14, AL,  50-MHz, Push-pull	DCMI_D4		AF13
// PH15, OU,  50-MHz, Push-pull	PWM6		AF00

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(H,KOU,KAL,KOU,KAL,KAL,KAL,KAL,KAL,KAL,KOU,KAL,KAL,KAL,KAL,KOU,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K99,K99,K99,K99,K50,K50,
			  KNO,KNO,KNO,KNO,KNO,KNO,KNO,KPU,KPU,KNO,KNO,KNO,KNO,KNO,KNO,KNO,
			  A00,A13,A00,A13,A13,A13,A13,A04,A04,A00,A12,A10,A12,A12,A00,A00,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KOD,KOD,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u);

// PI00, OU,  50-MHz, Push-pull	SPI2_CS		AF00
// PI01, AL,  50-MHz, Push-pull	SPI2_CLK	AF05
// PI02, AL,  50-MHz, Pull-up	I2S2_SDI	AF05
// PI03, AL,  50-MHz, Push-pull	I2S2_SDO	AF05
// PI04, AL,  50-MHz, Push-pull	DCMI_D5		AF13
// PI05, AL,  50-MHz, Push-pull	VSYNC		AF13
// PI06, AL,  50-MHz, Push-pull	DCMI_D6		AF13
// PI07, AL,  50-MHz, Push-pull	DCMI_D7		AF13
// PI08, OU,  50-MHz, Push-pull	BTSEL		AF00
// PI09, OU,  50-MHz, Push-pull	LED0		AF00	LED0
// PI10, OU,  50-MHz, Push-pull	LED1		AF00	LED1
// PI11, AL,  99-MHz, Push-pull	DIR			AF10	USB3320C
// PI12, OU,  50-MHz, Push-pull	CRYPTO_EN	AF00
// PI13, OU,  50-MHz, Push-pull	LED2		AF00	LED2
// PI14, OU,  50-MHz, Push-pull	LED3		AF00	LED3
// PI15, OU,  50-MHz, Push-pull	LED4		AF00	LED4

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(I,KOU,KOU,KOU,KOU,KAL,KOU,KOU,KOU,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KOU,
			  K50,K50,K50,K50,K99,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KPU,KNO,KNO,
			  A00,A00,A00,A00,A10,A00,A00,A00,A13,A13,A13,A13,A05,A05,A05,A00,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 1u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u);

// PJ00, IN,  50-MHz, Pull-up	PF1550_STBY	AF00
// PJ01, OU,  50-MHz, Push-pull	OSCEN		AF00
// PJ02, IN,  50-MHz, Pull-up	-			AF00
// PJ03, OU,  50-MHz, Push-pull	RSTN		AF00	Video Ctrl
// PJ04, OU,  50-MHz, Push-pull	RESETB		AF00	USB3320C
// PJ05, IN,  50-MHz, Pull-up	HOST_WAKE	AF00	Wifi Ctrl
// PJ06, OU,  50-MHz, Push-pull	ID/OTG_EN	AF00	USB3320C / NX18P3001
// PJ07, OU,  50-MHz, Push-pull	CAMERA_RZ	AF00	CAMERA_RZ
// PJ08, AL,  50-MHz, Push-pull	UART8_TX	AF08	Console D
// PJ09, AL,  50-MHz, Pull-up	UART8_RX	AF08	Console D
// PJ10, OU,  50-MHz, Push-pull	CAMERA_OI0	AF00	CAMERA_OI0 (CLK_EN)
// PJ11, OU,  50-MHz, Push-pull	PWM4		AF00
// PJ12, OU,  50-MHz, Push-pull	ON			AF00	BLE Ctrl
// PJ13, IN,  50-MHz, Pull-up	HOST_WAKE	AF00	BLE Ctrl
// PJ14, IN,  50-MHz, Pull-up	DEVICE_WAKE	AF00	BLE Ctrl
// PJ15, OU,  50-MHz, Push-pull	RST			AF00	Wifi

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(J,KOU,KIN,KIN,KOU,KOU,KOU,KAL,KAL,KOU,KOU,KIN,KOU,KOU,KIN,KOU,KIN,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KPU,KPU,KNO,KPU,KNO,KPU,KNO,KNO,KNO,KPU,KNO,KNO,KPU,KNO,KPU,
			  A00,A00,A00,A00,A00,A00,A08,A08,A00,A00,A00,A00,A00,A00,A00,A00,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  1u, 0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 1u, 0u);

// PK00, IN,  50-MHz, Pull-up	PF1550_INT	AF00
// PK01, OU,  50-MHz, Push-pull	PWM5		AF00
// PK02, OU,  50-MHz, Push-pull	EN			AF00	Video Ctrl
// PK03, OU,  50-MHz, Push-pull	CABLE		AF00	Video Ctrl
// PK04, OU,  50-MHz, Push-pull	ALT			AF00	Video Ctrl
// PK05, OU,  50-MHz, Push-pull	LEDRed		AF00	LED red
// PK06, OU,  50-MHz, Push-pull	LEDGreen	AF00	LED green
// PK07, OU,  50-MHz, Push-pull	LEDBlue		AF00	LED blue
// PK08, IN,  50-MHz, Pull-up	-			AF00
// PK09, IN,  50-MHz, Pull-up	-			AF00
// PK10, IN,  50-MHz, Pull-up	-			AF00
// PK11, IN,  50-MHz, Pull-up	-			AF00
// PK12, IN,  50-MHz, Pull-up	-			AF00
// PK13, IN,  50-MHz, Pull-up	-			AF00
// PK14, IN,  50-MHz, Pull-up	-			AF00
// PK15, IN,  50-MHz, Pull-up	-			AF00

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(K,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KOU,KOU,KOU,KOU,KOU,KOU,KOU,KIN,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KPU,
			  A00,A00,A00,A00,A00,A00,A00,A00,A00,A00,A00,A00,A00,A00,A00,A00,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u);
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
					| RCC_CR_RC48ON						// Set HSI48ON bit
					| RCC_CR_HSEBYP;					// Set the oscillator bypass

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

	while ((RCC->CR & RCC_CR_RC48RDY) == 0) { ; }		// Waiting for the 48-MHz

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

	while ((RCC->CR & RCC_CR_PLL1RDY) == 0) { ; }		// Waiting for the lock of the PLL

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
// f(R) = f(vco) / (R + 1) R = 1 			 			 ---> f(R) = 120

	RCC->PLLCFGR |= RCC_PLLCFGR_DIVR3EN					// Div R enable
				  | RCC_PLLCFGR_DIVQ3EN					// Div Q enable
				  | RCC_PLLCFGR_DIVP3EN					// Div P enable
				  | (3u * RCC_PLLCFGR_PLL3RGE_0);		// Input 16-MHz

	RCC->PLL3DIVR = (1u * RCC_PLL3DIVR_DIVR3_0)			// Div R
				  | (4u * RCC_PLL3DIVR_DIVQ3_0)			// Div Q
				  | (1u * RCC_PLL3DIVR_DIVP3_0)			// Div P
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

	RCC->D2CFGR = (5u * RCC_D2CFGR_D2PPRE2_0)			// D2PPRE2 / 4
				| (5u * RCC_D2CFGR_D2PPRE1_0);			// D2PPRE1 / 4

	RCC->D3CFGR = (4u * RCC_D3CFGR_D3PPRE_0);			// D3PPRE / 2

// RNG & USB clocks
// ----------------

	RCC->D2CCIP2R = (1u * RCC_D2CCIP2R_RNGSRC_0)		// Set the clock for the RNG @ KFREQUENCY_PLL1Q (240-MHz)
				  | (2u * RCC_D2CCIP2R_USBSRC_0);		// Set the clock for the USB @ KFREQUENCY_PLL3Q (48-MHz)

// Flash latency (for 4x0-MHz ... 4 wait states)
// ---------------------------------------------

	FLASH->ACR = (3u * FLASH_ACR_WRHIGHFREQ_0)			// Bus > 385-MHz
			   | (4u * FLASH_ACR_LATENCY_0);			// 4 wait states

	RCC->CFGR = (4u * RCC_CFGR_MCO1SEL_0)				// MCO1 HSI48
			  | (1u * RCC_CFGR_MCO1PRE_0)				// prescaler / 1
			  | (3u * RCC_CFGR_SW_0);					// CPU clock = PLL
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
// - SDRAM is a AS4C4M16SA-6 speed grade, connected to bank 1 (0x70000000).
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
			   | (1u * FMC_SDCR1_NR_0)					// 12-bit row address
			   | (0u * FMC_SDCR1_NC_0);					// 8-bit column address

	FMC->SDCR2 = 0u;

// One SDRAM clock cycle is 1/120-MHz = 8.3-ns

	FMC->SDTR1 = ((3u - 1u) * FMC_SDTR1_TRCD_0)			// 3 cycle TRCD (24.9-ns > 18-ns)
			   | ((3u - 1u) * FMC_SDTR1_TRP_0)			// 3 cycle TRP (24.9-ns > 18-ns)
			   | ((3u - 1u) * FMC_SDTR1_TWR_0)			// 3 cycle TWR (>= (TRAS - TRCD)
			   | ((8u - 1u) * FMC_SDTR1_TRC_0)			// 8 cycle TRC (66.4-ns > 60-ns)
			   | ((6u - 1u) * FMC_SDTR1_TRAS_0)			// 6 cycle TRAS (49.8-ns > 42-ns)
			   | ((8u - 1u) * FMC_SDTR1_TXSR_0)			// 8 cycle TXSR (66.4-ns > 61.5-ns)
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
	SET_MPU7_REGION(0u, 0u,	ST_FLASH_INT_0,			SZ_FLASH_INT_0,			KMPU_EXECUTABLE,		KMPU_R_ALL,		KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(1u, 0u,	ST_RAM_INT_0,			SZ_RAM_INT_0,			KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(2u, 0u,	ST_RAM_INT_0_OS,		SZ_RAM_INT_0_OS,		KMPU_EXECUTABLE,		KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(3u, 0u,	ST_RAM_INT_1_SHARED,	SZ_RAM_INT_1_SHARED,	KMPU_NOT_EXECUTABLE,	KMPU_RW_ALL,	KMPU_TEX_LEVEL6, KMPU_SHAREABLE,		KMPU_NOT_CASHABLE,	KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(4u, 0u,	ST_RAM_EXT_0,			SZ_RAM_EXT_0,			KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(5u, 0u,	ST_PERIPH_SOC,			SZ_PERIPH_SOC,			KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_BUFFERABLE);
	SET_MPU7_REGION(6u, 0u,	ST_PERIPH_CORE,			SZ_PERIPH_CORE,			KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_BUFFERABLE);

	#else
	SET_MPU7_REGION(0u, 0u,	ST_FLASH_INT_0,			SZ_FLASH_INT_0,			KMPU_EXECUTABLE,		KMPU_R_ALL,		KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(1u, 0u,	ST_RAM_INT_0,			SZ_RAM_INT_0,			KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	SET_MPU7_REGION(2u, 0u,	ST_RAM_INT_1_SHARED,	SZ_RAM_INT_1_SHARED,	KMPU_NOT_EXECUTABLE,	KMPU_RW_ALL,	KMPU_TEX_LEVEL6, KMPU_SHAREABLE,		KMPU_NOT_CASHABLE,	KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(3u, 0u,	ST_RAM_EXT_0,			SZ_RAM_EXT_0,			KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_BUFFERABLE);
	#endif

// Enable branch prediction
// Normally not necessary (always on)

	SCB->CCR |= (1u<<18u);
	DATA_SYNC_BARRIER;
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

/*
 * \brief local_Boot_CM4
 *
 * - Boot the CM4
 *
 */
static	void	local_Boot_CM4(void) {

	RCC->GCR |= RCC_GCR_BOOT_C2;
}

/*
 * \brief local_load_PF1550
 *
 * - Load the PF1550 parameters for the power supply controller
 *	 See: https://github.com/olback/h7-bootloader-rev/
 *	 See: https://forum.arduino.cc/t/portenta-h7-pmic-3-0v-to-3-3v-config/1021433
 *
 */
#define	KEXTEND

static	void	local_load_PF1550(void) {
					uint8_t		i;
	static	const	pf1550_t	aTabInitPF1550[] = {
									{ PF1550_LDO2_VOLT,			0x00u, 0u       },		// LDO 2 to 1.8-V
									{ PF1550_LDO2_CTRL,			0x0Fu, 0u       },		// Enable the LDO 2
									{ PF1550_LDO1_VOLT,			0x05u, 0u       },		// LDO 1 to 1-V
									{ PF1550_LDO1_CTRL,			0x03u, 0u       },		// Enable the LDO 1
									{ PF1550_LDO3_VOLT,			0x09u, 0u       },		// LDO 3 to 1.2-V
									{ PF1550_LDO3_CTRL,			0x0Fu, 100000u  },		// Enable the LDO 3
									{ PF1550_LED_PWM,			0x80u, 0u       },		// Charger LED off - duty cycle
									{ PF1550_LED_CNFG,			0x20u, 100000u  },		// Disable charger LED
									{ PF1550_SW3_CTRL1,			0x02u, 100000u  },		// SW 3: set 2-A as current limit
									{ PF1550_VBUS_INLIM_CNFG,	0xA0u, 0u       },		// Change VBUS input current limit to 1.5-A

									#if	(defined(KEXTEND))
									{ PF1550_SW2_VOLT,			0x07u, 0u       },		// SW 2: 3.3-V (Run mode)
									{ PF1550_SW2_STBY_VOLT,		0x07u, 0u       },		// SW 2: 3.3-V (Standby mode)
									{ PF1550_SW2_SLP_VOLT,		0x07u, 0u       },		// SW 2: 3.3-V (Sleep mode)
									#endif

									{ PF1550_SW2_CTRL,			0x0Fu, 0u       },		// Enable the SW 2

									#if	(defined(KEXTEND))
									{ PF1550_SW1_VOLT,			0x07u, 0u       },		// SW 1: 3.3-V (Run mode)
									{ PF1550_SW1_STBY_VOLT,		0x07u, 0u       },		// SW 1: 3.3-V (Standby mode)
									{ PF1550_SW1_SLP_VOLT,		0x07u, 0u       },		// SW 1: 3.3-V (Sleep mode)
									#endif

									{ PF1550_SW1_CTRL,			0x0Fu, 0u       },		// Enable the SW 1

// SW3 o effects, VCC remains to 3.0-V: Probably due to the OTP configuration

									#if	(defined(KEXTEND))
									{ PF1550_SW3_VOLT,			0x0Fu, 0u       },		// SW 3: 3.3-V (Run mode)
									{ PF1550_SW3_STBY_VOLT,		0x0Fu, 0u       },		// SW 3: 3.3-V (Standby mode)
									{ PF1550_SW3_SLP_VOLT,		0x0Fu, 0u       },		// SW 3: 3.3-V (Sleep mode)
									{ PF1550_SW3_CTRL,			0x0Fu, 0u       },		// Enable the SW 3
									#endif

									{ PF1550_SW1_CTRL1,			0x02u, 10000u   },		// SW 1: set 1.5-A as current limit
									{ PF1550_COINCELL_CONTROL,	0x17u, 10000u   },		// Charger enable, 3.3-V
									{ PF1550_SW3_CTRL1,			0x01u, 10000u   },		// SW 3: set 1.2-A as current limit
								};
	const	uint8_t		szTabInitPF1550 = (sizeof(aTabInitPF1550) / (sizeof(pf1550_t)));

	RCC->APB1LENR |= RCC_APB1LENR_I2C1EN;

// Initialise the I2C Master, default speed 100-KHz

	I2C1->CR1 &= (uint32_t)~I2C_CR1_PE;

	I2C1->TIMINGR = (4u * I2C_TIMINGR_PRESC_0)						// Timing prescaler
				  | (9u * I2C_TIMINGR_SCLDEL_0)						// Data setup time
				  | (1u * I2C_TIMINGR_SDADEL_0)						// Data hold time
				  | (52u * I2C_TIMINGR_SCLH_0)						// SCL high period
				  | (52u * I2C_TIMINGR_SCLL_0);						// SCL Low period

	I2C1->CR1     = I2C_CR1_NOSTRETCH								// Clock stretching disabled
				  | I2C_CR1_ANFOFF;									// Analog noise filter disabled

	I2C1->CR1	  |= I2C_CR1_PE;									// Periph enable

// Minimal send of data to the PF1550

	for (i = 0; i < szTabInitPF1550; i++) {
		local_waitingForFlagOff(I2C_ISR_BERR);
		local_waitingForFlagOn(I2C_ISR_TXE);

		I2C1->CR2 = (0u * I2C_CR2_PECBYTE)							// No packet error
				  | I2C_CR2_AUTOEND									// Automatic end mode
				  | (0u * I2C_CR2_RELOAD)							// No reload mode
				  | ((KPF1550_NB_MONO & 0xFFu) * I2C_CR2_NBYTES_0)	// Number of bytes to transfer
				  | (0u * I2C_CR2_NACK)								// No NACK
				  | (0u * I2C_CR2_STOP)								// No STOP
				  | (0u * I2C_CR2_HEAD10R)							// No HEADER 10
				  | (0u * I2C_CR2_ADD10)							// Address on 7 bits
				  | (0u * I2C_CR2_RD_WRN)							// Write transfer
				  | ((KI2C_ADD_PF1550<<1u) * I2C_CR2_SADD0);		// The slave address

		I2C1->CR2 |= I2C_CR2_START;									// START

		local_waitingForFlagOff(I2C_ISR_BERR);						//
		local_waitingForFlagOn(I2C_ISR_TXE);						//
		local_waitingForFlagOff(I2C_ISR_NACKF);						//

		local_writeByte(aTabInitPF1550[i].oRegister);				//
		local_writeByte(aTabInitPF1550[i].oData);					//

// Wait after each write

		local_wait_us(aTabInitPF1550[i].oDelay);					//
	}

	local_wait_us(1000000u);										//
	RCC->APB1LENR &= ~RCC_APB1LENR_I2C1EN;							// Disable the periph
}

/*
 * \brief local_writeByte
 *
 */
static	void	local_writeByte(uint8_t byte) {

	local_waitingForFlagOn(I2C_ISR_TXE);

	I2C1->TXDR = (uint32_t)byte;
}

/*
 * \brief local_waitingForFlagOn
 *
 */
static	void	local_waitingForFlagOn(uint32_t flag) {

	while ((I2C1->ISR & flag) != flag) { ; }
}

/*
 * \brief local_waitingForFlagOff
 *
 */
static	void	local_waitingForFlagOff(uint32_t flag) {

	while ((I2C1->ISR & flag) == flag) { ; }
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
