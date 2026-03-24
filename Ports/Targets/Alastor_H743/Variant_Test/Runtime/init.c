/*
; init.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Low level init for the uKOS-X Alastor_H743 module.
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

#define	CACHE_I_S					// With the instruction cache
#define	CACHE_D_S					// With the data cache
#undef	SELF_REFRESH_S				// Refresh under the control of the SDRAM chip

// SDRAM macro

#define	SDRAM_COMMAND_BANK2(command, mrd, cycles)				\
			do {												\
				FMC->SDCMR = ((uint32_t)((mrd))<<9u)			\
						   | ((uint32_t)((cycles))<<5u)			\
						   | (1u<<3u)							\
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
 * \param[in]	-
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

	PWR->D3CR &= ~(PWR_D3CR_VOS);
	PWR->D3CR |=  (3u * PWR_D3CR_VOS_0);

	while ((PWR->D3CR & PWR_D3CR_VOSRDY) == 0u) { ; }

	RCC->APB4ENR  |= RCC_APB4ENR_SYSCFGEN;
	SYSCFG->PWRCR |= SYSCFG_PWRCR_ODEN;
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

// PA00, AL,  50-MHz, Push-pull	USART4_TX	AF08
// PA01, AL,  50-MHz, Pull-up	USART4_RX	AF08
// PA02, AL,  50-MHz, Push-pull	USART2_TX	AF07
// PA03, AL,  50-MHz, Pull-up	USART2_RX	AF07
// PA04, OU,  50-MHz, Push-pull	SPI6_NSS	AF15	/BSEL_DEBUG
// PA05, AL,  50-MHz, Push-pull	SPI6_SCK	AF08
// PA06, AL,  50-MHz, Push-pull	DCMI_PIXCK	AF13
// PA07, AL,  50-MHz, Push-pull	SPI6_MOSI	AF08
// PA08, OU,  50-MHz, Pull-up	RzFLASH		AF15	/BRZ_FLASH
// PA09, IN,  50-MHz, Pull-up	VBUS_FS!!	AF15
// PA10, AL,  50-MHz, Pull-up	USART1_RX	AF07
// PA11, IN,  50-MHz, Float		OTG_DM!!	AF15
// PA12, IN,  50-MHz, Float		OTG_DP!!	AF15
// PA13, AL,  50-MHz, Pull-up 	TMS			AF00
// PA14, AL,  50-MHz, Pull-down TCK			AF00
// PA15, AL,  50-MHz, Pull-up	TDI			AF00

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(A,KAL,KAL,KAL,KIN,KIN,KAL,KIN,KOU,KAL,KAL,KAL,KOU,KAL,KAL,KAL,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KPD,KPU,KNO,KNO,KPU,KPU,KNO,KNO,KNO,KNO,KNO,KPU,KNO,KPU,KNO,
			  A00,A00,A00,A15,A15,A07,A15,A15,A08,A13,A08,A15,A07,A07,A08,A08,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u);

// PB00, OU,  50-MHz, Push-pull	SPI2_NSS	AF15	/BSEL_WROOM
// PB01, OU,  50-MHz, Push-pull	LED0		AF15
// PB02, IN,  50-MHz, Pull-up	Boot1		AF15
// PB03, AL,  50-MHz, Push-pull	TDO			AF00
// PB04, AL,  50-MHz, Pull-up	NJTRST		AF00
// PB05, OU,  50-MHz, Push-pull	LED1		AF15
// PB06, AL,  50-MHz, Push-pull	USART1_TX	AF07
// PB07, OU,  50-MHz, Push-pull	LED2		AF15
// PB08, AL,  50-MHz, Open DU	I2C1_SCL	AF04
// PB09, AL,  50-MHz, Open DU	I2C1_SDA	AF04
// PB10, AL,  50-MHz, Push-pull	USART3_TX	AF07
// PB11, AL,  50-MHz, Pull-up	USART3_RX	AF07
// PB12, OU,  50-MHz, Push-pull	SPI2_NSS	AF15	/BSELFLASH
// PB13, AL,  50-MHz, Push-pull	SPI2_SCK	AF05
// PB14, AL,  50-MHz, Pull-up	SPI2_MISO	AF05
// PB15, AL,  50-MHz, Push-pull	SPI2_MOSI	AF05

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(B,KAL,KAL,KAL,KOU,KAL,KAL,KAL,KAL,KOU,KAL,KOU,KAL,KAL,KIN,KOU,KOU,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KPU,KNO,KNO,KPU,KNO,KPU,KPU,KNO,KNO,KNO,KPU,KNO,KPU,KNO,KNO,
			  A05,A05,A05,A15,A07,A07,A04,A04,A15,A07,A15,A00,A00,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KOD,KOD,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 1u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u);

// PC00, AL,  99-MHz, Push-pull	SDNWE		AF12
// PC01, IN,  50-MHz, Pull-up	ADC0		AF15
// PC02, IN,  50-MHz, Pull-up	ADC1		AF15
// PC03, OU,  50-MHz, Push-pull	LED3		AF15
// PC04, OU,  50-MHz, Push-pull	LED4		AF15
// PC05, OU,  50-MHz, Push-pull	LED5		AF15
// PC06, OU,  50-MHz, Push-pull	USART6_TX	AF15	/BSEL_ACCELERO
// PC07, IN,  50-MHz, Pull-up	USART6_RX	AF15	/BINT_IMU
// PC08, OU,  50-MHz, Push-pull	LED6		AF15
// PC09, OU,  50-MHz, Push-pull	LED7		AF15
// PC10, IN,  50-MHz, Pull-down	SW0			AF15
// PC11, IN,  50-MHz, Pull-down	SW1			AF15
// PC12, IN,  50-MHz, Pull-down	SW2			AF15
// PC13, IN,  50-MHz, Pull-down	SW3			AF15
// PC14, AL,  50-MHz, -			OSC			AF00
// PC15, AL,  50-MHz, -			OSC			AF00

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(C,KAL,KAL,KIN,KIN,KIN,KIN,KOU,KOU,KIN,KOU,KOU,KOU,KOU,KIN,KIN,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K99,
			  KNO,KNO,KPD,KPD,KPD,KPD,KNO,KNO,KPU,KNO,KNO,KNO,KNO,KPU,KPU,KNO,
			  A00,A00,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A12,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u);

// PD00, AL,  99-MHz, Push-pull	FMC_D2		AF12
// PD01, AL,  99-MHz, Push-pull	FMC_D3		AF12
// PD02, IN,  50-MHz, Pull-up	IO_W_0		AF15	RXD (Wroom status)
// PD03, IN,  50-MHz, Pull-up	IO_W_1		AF15	/CTS Wroom
// PD04, IN,  50-MHz, Pull-up	IO_W_2		AF15
// PD05, IN,  50-MHz, Pull-up	IO_W_3		AF15
// PD06, IN,  50-MHz, Pull-up	IO_W_4		AF15
// PD07, IN,  50-MHz, Pull-up	IO_W_5		AF15
// PD08, AL,  99-MHz, Push-pull	FMC_D13		AF12
// PD09, AL,  99-MHz, Push-pull	FMC_D14		AF12
// PD10, AL,  99-MHz, Push-pull	FMC_D15		AF12
// PD11, IN,  50-MHz, Push-pull	IO_W_6		AF15
// PD12, IN,  50-MHz, Push-pull	IO_W_7		AF15
// PD13, OU,  50-MHz, Push-pull	-			AF15	BESP32_NDOWNLOAD
// PD14, AL,  99-MHz, Push-pull	FMC_D0		AF12
// PD15, AL,  99-MHz, Push-pull	FMC_D1		AF12

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(D,KAL,KAL,KOU,KIN,KIN,KAL,KAL,KAL,KIN,KIN,KIN,KIN,KIN,KIN,KAL,KAL,
			  K99,K99,K50,K50,K50,K99,K99,K99,K50,K50,K50,K50,K50,K50,K99,K99,
			  KNO,KNO,KNO,KPU,KPU,KNO,KNO,KNO,KPU,KPU,KPU,KPU,KPU,KPU,KNO,KNO,
			  A12,A12,A15,A15,A15,A12,A12,A12,A15,A15,A15,A15,A15,A15,A12,A12,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PE00, AL,  99-MHz, Push-pull	FMC_NBL0	AF12
// PE01, AL,  99-MHz, Push-pull	FMC_NBL1	AF12
// PE02, AL,  50-MHz, Push-pull	SPI4_SCK	AF05
// PE03, OU,  50-MHz, Push-pull	-			AF15	BESP32_ENABLE
// PE04, OU,  50-MHz, Push-pull	SPI4_NSS	AF15	/BSEL_SDCARD
// PE05, AL,  50-MHz, Pull-up	SPI4_MISO	AF05
// PE06, AL,  50-MHz, Push-pull	SPI4_MOSI	AF05
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
	CNFGPIO(E,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KOU,KOU,KAL,KAL,KAL,
			  K99,K99,K99,K99,K99,K99,K99,K99,K99,K50,K50,K50,K50,K50,K99,K99,
			  KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KPU,KNO,KNO,KNO,KPU,KPU,
			  A12,A12,A12,A12,A12,A12,A12,A12,A12,A05,A05,A15,A15,A05,A12,A12,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u);

// PF00, AL,  99-MHz, Push-pull	FMC_A0		AF12
// PF01, AL,  99-MHz, Push-pull	FMC_A1		AF12
// PF02, AL,  99-MHz, Push-pull	FMC_A2		AF12
// PF03, AL,  99-MHz, Push-pull	FMC_A3		AF12
// PF04, AL,  99-MHz, Push-pull	FMC_A4		AF12
// PF05, AL,  99-MHz, Push-pull	FMC_A5		AF12
// PF06, AL,  50-MHz, Pull-up	SPI5_NSS	AF05		/IMAGE
// PF07, AL,  50-MHz, Pull-up	SPI5_SCK	AF05
// PF08, AL,  50-MHz, Pull-up	SPI5_MISO	AF05
// PF09, AL,  50-MHz, Pull-up	SPI5_MOSI	AF05
// PF10, OU,  50-MHz, Push-pull	SPI2_NSS	AF15	/BSEL_MAGNETO
// PF11, AL,  99-MHz, Push-pull	SDNRAS		AF12
// PF12, AL,  99-MHz, Push-pull	FMC_A6		AF12
// PF13, AL,  99-MHz, Push-pull	FMC_A7		AF12
// PF14, AL,  99-MHz, Push-pull	FMC_A8		AF12
// PF15, AL,  99-MHz, Push-pull	FMC_A9		AF12

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(F,KAL,KAL,KAL,KAL,KAL,KOU,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,
			  K99,K99,K99,K99,K99,K50,K50,K50,K50,K50,K99,K99,K99,K99,K99,K99,
			  KNO,KNO,KNO,KNO,KNO,KNO,KPU,KPU,KPU,KPU,KNO,KNO,KNO,KNO,KNO,KNO,
			  A12,A12,A12,A12,A12,A15,A05,A05,A05,A05,A12,A12,A12,A12,A12,A12,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PG00, AL,  99-MHz, Push-pull	FMC_A10		AF12
// PG01, AL,  99-MHz, Push-pull	FMC_A11		AF12
// PG02, AL,  99-MHz, Push-pull	FMC_A12		AF12
// PG03, OU,  50-MHz, Push-pull	OI_W_0		AF15	/RTS ESP32
// PG04, AL,  99-MHz, Push-pull	BA0			AF12
// PG05, AL,  99-MHz, Push-pull	BA1			AF12
// PG06, OU,  50-MHz, Push-pull	OI_W_1		AF15	/Boot Wroom
// PG07, OU,  50-MHz, Push-pull	OI_W_2		AF15	E Wroom
// PG08, AL,  99-MHz, Push-pull	SDCLK		AF12
// PG09, OU,  50-MHz, Push-pull	OI_W_3		AF15
// PG10, OU,  50-MHz, Push-pull	OI_W_4		AF15
// PG11, OU,  50-MHz, Push-pull	OI_W_5		AF15
// PG12, AL,  50-MHz, Push-pull	SPI6_MISO	AF05
// PG13, IN,  50-MHz, Pull-up	IO_DBGCOMR	AF15
// PG14, IN,  50-MHz, Pull-up	CD			AF15	/BNO_SDCARD
// PG15, AL,  99-MHz, Push-pull	SDNCAS		AF12

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(G,KAL,KIN,KIN,KAL,KOU,KOU,KOU,KAL,KOU,KOU,KAL,KAL,KOU,KAL,KAL,KAL,
			  K99,K50,K50,K50,K50,K50,K50,K99,K50,K50,K99,K99,K50,K99,K99,K99,
			  KNO,KPU,KPU,KPU,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,
			  A12,A15,A15,A05,A15,A15,A15,A12,A15,A15,A12,A12,A15,A12,A12,A12,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u);

// PH00, AL,  50-MHz, -			OSC			AF00
// PH01, AL,  50-MHz, -			OSC			AF00
// PH02, OU,  50-MHz, Push-pull	OI_V_0		AF15	BEN_CLK
// PH03, OU,  50-MHz, Push-pull	OI_V_1		AF15
// PH04, AL,  50-MHz, Open DU	I2C2_SCL	AF04
// PH05, AL,  50-MHz, Open DU	I2C2_SDA	AF04
// PH06, AL,  99-MHz, Push-pull	SDNEE1		AF12
// PH07, AL,  99-MHz, Push-pull	SDCKE1		AF12
// PH08, AL,  50-MHz, Push-pull	DCMI_HSYNC	AF13
// PH09, AL,  50-MHz, Push-pull	DCMI_D0		AF13
// PH10, AL,  50-MHz, Push-pull	DCMI_D1		AF13
// PH11, AL,  50-MHz, Push-pull	DCMI_D2		AF13
// PH12, AL,  50-MHz, Push-pull	DCMI_D3		AF13
// PH13, IN,  50-MHz, Pull-up	IO_DBGREQ	AF15
// PH14, AL,  50-MHz, Push-pull	DCMI_D4		AF13
// PH15, IN,  50-MHz, Pull-up	-			AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(H,KIN,KAL,KIN,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KOU,KOU,KAL,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K99,K99,K50,K50,K50,K50,K50,K50,
			  KPU,KNO,KPU,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KPU,KPU,KNO,KNO,KNO,KNO,
			  A15,A13,A15,A13,A13,A13,A13,A13,A12,A12,A04,A04,A15,A15,A00,A00,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KOD,KOD,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u);

// PI00, OU,  50-MHz, Push-pull	OI_W_6		AF15
// PI01, AL,  50-MHz, Push-pull	DCMI_D8		AF13
// PI02, AL,  50-MHz, Push-pull	DCMI_D9		AF13
// PI03, OU,  50-MHz, Push-pull	OI_W_7		AF15
// PI04, AL,  50-MHz, Push-pull	DCMI_D5		AF13
// PI05, AL,  50-MHz, Push-pull	DCMI_VSYNC	AF13
// PI06, AL,  50-MHz, Push-pull	DCMI_D6		AF13
// PI07, AL,  50-MHz, Push-pull	DCMI_D7		AF13
// PI08, OU,  50-MHz, Push-pull	LOGIC0		AF15
// PI09, OU,  50-MHz, Push-pull	LOGIC1		AF15
// PI10, OU,  50-MHz, Push-pull	OI_V_2		AF15	BSTANDBY
// PI11, OU,  50-MHz, Push-pull	OI_V_3		AF15	BEXPOSURE
// PI12, IN,  50-MHz, Pull-up	-			AF15
// PI13, IN,  50-MHz, Pull-up	-			AF15
// PI14, IN,  50-MHz, Pull-up	-			AF15
// PI15, IN,  50-MHz, Pull-up	-			AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(I,KIN,KIN,KIN,KIN,KOU,KOU,KOU,KOU,KAL,KAL,KAL,KAL,KOU,KAL,KAL,KOU,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KPU,KPU,KPU,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,
			  A15,A15,A15,A15,A15,A15,A15,A15,A13,A13,A13,A13,A15,A13,A13,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);
}

/*
 * \brief local_RCC_Configuration
 *
 * PLL1 P: 			400-MHz	clock CPU
 * 	- HPRE    / 2: 	200-MHz AXI & AHB1, AHB2, AHB3, AHB4 periph clocks
 * 	- D1PPRE  / 2:	100-MHz APB3 peripheral clock
 * 	- D2PPRE1 / 4:	 50-MHz APB1 peripheral clock
 * 	- D2PPRE2 / 4:	 50-MHz APB2 peripheral clock
 * 	- D3PPRE  / 2:	100-MHz APB4 peripheral clock
 *
 * PLL1 Q:			200-MHz	clock usable for the peripherals via the PKSU & PKEU units
 * PLL1 R:			100-MHz	clock usable for the peripherals via the PKSU & PKEU units
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
// f(vco) = f(ck in) * (N + 1)   f(vco) = 16-MHz, N = 49 ---> f(vco) = 800-MHz
// f(P) = f(vco) / (P + 1) P = 1 			 			 ---> f(P) = 400
// f(Q) = f(vco) / (Q + 1) Q = 3 			 			 ---> f(Q) = 200
// f(R) = f(vco) / (R + 1) R = 7 			 			 ---> f(R) = 100

	RCC->PLLCFGR |= RCC_PLLCFGR_DIVR1EN					// Div R enable
				  | RCC_PLLCFGR_DIVQ1EN					// Div Q enable
				  | RCC_PLLCFGR_DIVP1EN					// Div P enable
				  | (3u * RCC_PLLCFGR_PLL1RGE_0);		// Input 16-MHz

	RCC->PLL1DIVR = (7u * RCC_PLL1DIVR_DIVR1_0)			// Div R
				  | (3u * RCC_PLL1DIVR_DIVQ1_0)			// Div Q
				  | (1u * RCC_PLL1DIVR_DIVP1_0)			// Div P
				  | (49u * RCC_PLL1DIVR_DIVN1_0);		// Div N 49 = 800-MHz

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

	RCC->D2CCIP2R = (1u * RCC_D2CCIP2R_RNGSRC_0)		// Set the clock for the RNG @ KFREQUENCY_PLL1Q (200-MHz)
				  | (2u * RCC_D2CCIP2R_USBSRC_0);		// Set the clock for the USB @ KFREQUENCY_PLL3Q (48-MHz)

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

// Flash latency (for 400-MHz ... 2 wait states)
// ---------------------------------------------

	FLASH->ACR  = (3u * FLASH_ACR_WRHIGHFREQ_0)			// Bus > 385-MHz
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

// FMC bank 5-6 & CE1 configuration in the synchronous mode
// - SDRAM is a 42S16320F-6 speed grade, connected to bank 2 (0xD0000000)
//   Some bits in SDCR[1] are don't care, and the have to be set in SDCR[0],
//   they aren't just don't care, the controller will fail if they aren't at 0

	FMC->SDCR1 = (1u * FMC_SDCR1_RPIPE_0)				// 1 clocks cycle delay
			   | FMC_SDCR1_RBURST						// Read as bursts
			   | (2u* FMC_SDCR1_SDCLK_0);				// SDRAM runs @ 100-MHz

	FMC->SDCR2 = (2u * FMC_SDCR2_CAS_0)					// CAS latency 2 cycles
			   | FMC_SDCR2_NB							// 4 internal banks
			   | (1u * FMC_SDCR2_MWID_0)				// 16-bit data bus
			   | (2u * FMC_SDCR2_NR_0)					// 13-bit row address
			   | (2u * FMC_SDCR2_NC_0);					// 10-bit column address

// One SDRAM clock cycle is 1/100-MHz = 10-ns
// Some bits in SDTR[1] are don't care, and the have to be set in SDTR[0],
// they aren't just don't care, the controller will fail if they aren't at 0

	FMC->SDTR1 = ((2u - 1u) * FMC_SDTR1_TRP_0)			// 2 cycle TRP (20.x-ns > 18-ns)
			   | ((7u - 1u) * FMC_SDTR1_TRC_0);			// 7 cycle TRC (70.x-ns > 60-ns)

	FMC->SDTR2 = ((2u - 1u) * FMC_SDTR2_TRCD_0)			// 2 cycle TRCD (20.x-ns > 18-ns)
			   | ((3u - 1u) * FMC_SDTR2_TWR_0)			// 3 cycle TWR
			   | ((5u - 1u) * FMC_SDTR2_TRAS_0)			// 5 cycle TRAS (50.x-ns > 42-ns)
			   | ((8u - 1u) * FMC_SDTR2_TXSR_0)			// 8 cycle TXSR (80.x-ns > 70-ns)
			   | ((2u - 1u) * FMC_SDTR2_TMRD_0);		// 2 cycle TMRD

// SDRam mode register
// Mode: 11 10 09 08   07 06 05 04   03 02 01 00
//        -  -  1  0    0  0  1  0    0  0  0  0
//
// M9      = 1		Single location access
// M8 - M7 = 00		Standard operation
// M6 - M4 = 010	CAS latency 2
// M3	   = 0		Sequential
// M2 - M0 = 000	Burst length 1

	SDRAM_COMMAND_BANK2(0x1u, 0u,     0u      );		// Command Clock Configuration Enable
	local_wait_us(200000u);

	SDRAM_COMMAND_BANK2(0x2u, 0u,     0u      );		// Command All Bank Precharge
	SDRAM_COMMAND_BANK2(0x3u, 0u,    (2u - 1u));		// Command Auto Refresh (2 cycles)
	SDRAM_COMMAND_BANK2(0x4u, 0x220u, 0u      );		// Command Load Mode Register (CAS latency = 2, burst len = 1 (only Read))

	#if (defined(SELF_REFRESH_S))
	SDRAM_COMMAND_BANK2(0x5u, 0u,     0u      );		// Command Self Refresh

	#else

// 64-ms/8192 = 7.8125-us
// 7.8125-us * 100-MHz = 781-20 = 761

	FMC->SDRTR = (761u * FMC_SDRTR_COUNT_0);			// Refresh timer count
	#endif

// Remapping of the SDRAM bank 2 (from 0xD0000000 -> 0x70000000)

	FMC->BCR1 |= (2u * FMC_BCR1_BMAP_0);
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
	SET_MPU7_REGION(0u, 0u,	ST_FLASH_INT_0,		SZ_FLASH_INT_0,		KMPU_EXECUTABLE,		KMPU_R_ALL,		KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(1u, 0u,	ST_RAM_INT_0,		SZ_RAM_INT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL6, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(2u, 0u,	ST_RAM_INT_1,		SZ_RAM_INT_1,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL6, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(3u, 0u,	ST_RAM_INT_2_OS,	SZ_RAM_INT_2_OS,	KMPU_EXECUTABLE,		KMPU_RW_PRI,	KMPU_TEX_LEVEL6, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(4u, 0u,	ST_RAM_EXT_0,		SZ_RAM_EXT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL6, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(5u, 0u,	ST_PERIPH_SOC,		SZ_PERIPH_SOC,		KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_BUFFERABLE);
	SET_MPU7_REGION(6u, 0u,	ST_PERIPH_CORE,		SZ_PERIPH_CORE,		KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI,	KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_NOT_CASHABLE,	KMPU_BUFFERABLE);

	#else
	SET_MPU7_REGION(0u, 0u,	ST_FLASH_INT_0,		SZ_FLASH_INT_0,		KMPU_EXECUTABLE,		KMPU_R_ALL,		KMPU_TEX_LEVEL0, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(1u, 0u,	ST_RAM_INT_0,		SZ_RAM_INT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL6, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(2u, 0u,	ST_RAM_INT_1,		SZ_RAM_INT_1,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL6, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(3u, 0u,	ST_RAM_INT_2,		SZ_RAM_INT_2,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL6, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
	SET_MPU7_REGION(4u, 0u,	ST_RAM_EXT_0,		SZ_RAM_EXT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL,	KMPU_TEX_LEVEL6, KMPU_NOT_SHAREABLE,	KMPU_CASHABLE,		KMPU_NOT_BUFFERABLE);
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

	#if (defined(CACHE_I_S))
	cache_I_Invalidate();
	cache_I_Enable();
	#endif

	#if (defined(CACHE_D_S))
	cache_D_Invalidate();
	cache_D_Enable();
	#endif
}

#include	"model_I_D_cache.c_inc"
