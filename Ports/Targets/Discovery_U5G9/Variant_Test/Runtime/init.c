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
; Goal:		Low level init for the uKOS-X Discovery_U5G9 module.
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

// Prototypes

static			void	local_StackLimit_Configuration(void);
static			void	local_PWR_Configuration(void);
static			void	local_GPIO_Configuration(void);
static			void	local_RCC_Configuration(void);
static			void	local_MPU_Configuration(void);
static			void	local_FPE_Configuration(void);
static			void	local_USB_Configuration(void);
static			void	local_CACHE_Enable(void);
static	inline	void	cache_D_Enable(uint8_t unit);
static	inline	void	cache_D_Disable(uint8_t unit);
static	inline	void	cache_D_Invalidate(uint8_t unit);
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

	local_StackLimit_Configuration();
	local_PWR_Configuration();
	local_GPIO_Configuration();
	local_RCC_Configuration();
	local_MPU_Configuration();
	local_FPE_Configuration();
	local_USB_Configuration();
	local_CACHE_Enable();
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

	REG(RCC)->AHB3ENR |= RCC_AHB3ENR_PWREN;

// IOSV on to power the PORTG[2..15]
// ASV on to validate the Analog parts
// Set the mode 0 (highest speed)

	REG(PWR)->SVMCR |= PWR_SVMCR_IO2SV;
	REG(PWR)->SVMCR |= PWR_SVMCR_ASV;

	REG(PWR)->VOSR  = (3u * PWR_VOSR_VOS_0);
	REG(PWR)->VOSR |= PWR_VOSR_BOOSTEN;

	while ((REG(PWR)->VOSR & PWR_VOSR_VOSRDY) == 0u) { ; }
}

/*
 * \brief local_USB_Configuration
 *
 * - Enable the USB
 *
 */
static	void	local_USB_Configuration(void) {
	uint32_t	tmp;

	REG(RCC)->AHB2ENR1 |= RCC_AHB2ENR1_OTGEN;
	REG(RCC)->AHB2ENR1 |= RCC_AHB2ENR1_OTGHSPHYEN;
	REG(RCC)->APB3ENR  |= RCC_APB3ENR_SYSCFGEN;

// USBPHY uses HSE ] 16-MHz

	REG(RCC)->CCIPR2 = REG(RCC)->CCIPR2 & ~RCC_CCIPR2_OTGHSSEL;

	tmp = REG(SYSCFG)->OTGHSPHYCR & ~SYSCFG_OTGHSPHYCR_CLKSEL;
	REG(SYSCFG)->OTGHSPHYCR = tmp | (3u<<2u);

// Enable the USB VDD
// USB power EN and USB boost EN

	REG(PWR)->SVMCR |= PWR_SVMCR_USV;
	REG(PWR)->VOSR  |= (PWR_VOSR_USBPWREN | PWR_VOSR_USBBOOSTEN);

// Enable the USBPHY

	REG(SYSCFG)->OTGHSPHYCR |= SYSCFG_OTGHSPHYCR_EN;

// USB VBus detection disabled
// B-peripheral: Internally Bvalid received from the PHY is overridden with BVALOVAL
// B-peripheral: override value for Bvalid signal when BVALOEN bit is set

	REG(OTG_HS)->GCCFG &= ~OTG_HS_GCCFG_VBDEN;
	REG(OTG_HS)->GCCFG |= OTG_HS_GCCFG_VBVALEXTOEN;
	REG(OTG_HS)->GCCFG |= OTG_HS_GCCFG_VBVALOVAL;
}

/*
 * \brief local_GPIO_Configuration
 *
 * - GPIO configuration
 *
 */
static	void	local_GPIO_Configuration(void) {

// Turn on all the GPIOx

	REG(RCC)->AHB2ENR1 |= RCC_AHB2ENR1_GPIOAEN;
	REG(RCC)->AHB2ENR1 |= RCC_AHB2ENR1_GPIOBEN;
	REG(RCC)->AHB2ENR1 |= RCC_AHB2ENR1_GPIOCEN;
	REG(RCC)->AHB2ENR1 |= RCC_AHB2ENR1_GPIODEN;
	REG(RCC)->AHB2ENR1 |= RCC_AHB2ENR1_GPIOEEN;
	REG(RCC)->AHB2ENR1 |= RCC_AHB2ENR1_GPIOFEN;
	REG(RCC)->AHB2ENR1 |= RCC_AHB2ENR1_GPIOGEN;
	REG(RCC)->AHB2ENR1 |= RCC_AHB2ENR1_GPIOHEN;
	REG(RCC)->AHB2ENR1 |= RCC_AHB2ENR1_GPIOIEN;
	REG(RCC)->AHB2ENR1 |= RCC_AHB2ENR1_GPIOJEN;

// Init all the GPIO A, B, C, D, E, F, G, H, I, J

// PA00, IN,  50-MHz, Pull-up	--------	AF15
// PA01, IN,  50-MHz, Pull-up	--------	AF15
// PA02, IN,  50-MHz, Pull-up	--------	AF15
// PA03, IN,  50-MHz, Pull-up	--------	AF15
// PA04, IN,  50-MHz, Pull-up	--------	AF15
// PA05, IN,  50-MHz, Pull-up	--------	AF15
// PA06, IN,  50-MHz, Pull-up	--------	AF15
// PA07, IN,  50-MHz, Pull-up	--------	AF15
// PA08, AL,  50-MHz, Pull-up	MCO			AF00
// PA09, AL,  50-MHz, Push_pull	USART1_TX	AF07
// PA10, AL,  50-MHz, Pull-up	USART1_RX	AF07
// PA11, AL,  99-MHz, Push_pull	OTG_FS_DM	AF10
// PA12, AL,  99-MHz, Push_pull	OTG_FS_DP	AF10
// PA13, AL,  50-MHz, Pull-up 	SWDIO		AF00
// PA14, AL,  50-MHz, Pull-down SWCLK		AF00
// PA15, AL,  50-MHz, Pull-up	TDI			AF00

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(A,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,
			  K50,K50,K50,K99,K99,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KPD,KPU,KNO,KNO,KPU,KNO,KNO,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,
			  A15,A00,A00,A10,A10,A07,A07,A00,A15,A15,A15,A15,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PB00, IN,  50-MHz, Pull-up	--------	AF15
// PB01, IN,  50-MHz, Pull-up	--------	AF15
// PB02, IN,  50-MHz, Pull-up	--------	AF15
// PB03, IN,  50-MHz, Pull-up	--------	AF15
// PB04, IN,  50-MHz, Pull-up	--------	AF15
// PB05, IN,  50-MHz, Pull-up	--------	AF15
// PB06, AL,  50-MHz, Open DU	I2C4_SCL	AF05
// PB07, AL,  50-MHz, Open DU	I2C4_SDA	AF05
// PB08, IN,  50-MHz, Pull-up	--------	AF15
// PB09, IN,  50-MHz, Pull-up	--------	AF15
// PB10, IN,  50-MHz, Pull-up	--------	AF15
// PB11, IN,  50-MHz, Pull-up	--------	AF15
// PB12, IN,  50-MHz, Pull-up	--------	AF15
// PB13, IN,  50-MHz, Pull-up	--------	AF15
// PB14, IN,  50-MHz, Pull-up 	--------	AF15
// PB15, IN,  50-MHz, Pull-up	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(B,KIN,KIN,KIN,KIN,KIN,KIN,KAL,KAL,KAL,KAL,KIN,KIN,KIN,KIN,KIN,KIN,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,
			  A15,A15,A15,A15,A15,A15,A15,A15,A05,A05,A15,A15,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KOD,KOD,KOD,KOD,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);


// PC00, IN,  50-MHz, Pull-up	--------	AF15
// PC01, IN,  50-MHz, Pull-up	--------	AF15
// PC02, IN,  50-MHz, Pull-up	--------	AF15
// PC03, IN,  50-MHz, Pull-up	--------	AF15
// PC04, IN,  50-MHz, Pull-up	--------	AF15
// PC05, IN,  50-MHz, Pull-up	--------	AF15
// PC06, IN,  50-MHz, Pull-up	--------	AF15
// PC07, IN,  50-MHz, Pull-up	--------	AF15
// PC08, IN,  50-MHz, Pull-up	--------	AF15
// PC09, IN,  50-MHz, Pull-up	--------	AF15
// PC10, IN,  50-MHz, Pull-up	--------	AF15
// PC11, IN,  50-MHz, Pull-up	--------	AF15
// PC12, IN,  50-MHz, Pull-up	--------	AF15
// PC13, IN,  50-MHz, Pull-down	SW_User		AF15
// PC14, IN,  50-MHz, Pull-up 	--------	AF15
// PC15, IN,  50-MHz, Pull-up	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(C,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KPU,KPD,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KNO,KPU,KPU,
			  A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);


// PD00, AL,  50-MHz, Open DU	I2C6_SDA	AF02
// PD01, AL,  50-MHz, Open DU	I2C6_SCL	AF02
// PD02, IN,  50-MHz, Pull-up	--------	AF15
// PD03, IN,  50-MHz, Pull-up	--------	AF15
// PD04, IN,  50-MHz, Pull-up	--------	AF15
// PD05, OU,  50-MHz, Pull-down	DSI_RESET	AF15
// PD06, IN,  50-MHz, Pull-up	--------	AF15
// PD07, IN,  50-MHz, Pull-up	--------	AF15
// PD08, IN,  50-MHz, Pull-up	--------	AF15
// PD09, IN,  50-MHz, Pull-up	--------	AF15
// PD10, IN,  50-MHz, Pull-up	--------	AF15
// PD11, IN,  50-MHz, Pull-up	--------	AF15
// PD12, IN,  50-MHz, Pull-up	--------	AF15
// PD13, IN,  50-MHz, Pull-up	--------	AF15
// PD14, IN,  50-MHz, Pull-up	--------	AF15
// PD15, IN,  50-MHz, Pull-up	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(D,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KOU,KIN,KIN,KIN,KAL,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPD,KPU,KPU,KPU,KPU,KPU,
			  A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A02,A02,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KOD,KOD,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);


// PE00, OU,  50-MHz, Push_pull	LED_Green	AF15
// PE01, OU,  50-MHz, Push_pull	LED_Red		AF15
// PE02, IN,  50-MHz, Pull-up	--------	AF15
// PE03, IN,  50-MHz, Pull-up	--------	AF15
// PE04, IN,  50-MHz, Pull-up	--------	AF15
// PE05, IN,  50-MHz, Pull-up	--------	AF15
// PE06, IN,  50-MHz, Pull-up	--------	AF15
// PE07, IN,  50-MHz, Pull-up	--------	AF15
// PE08, IN,  50-MHz, Pull-up	--------	AF15
// PE09, IN,  50-MHz, Pull-up	--------	AF15
// PE10, IN,  50-MHz, Pull-up	--------	AF15
// PE11, IN,  50-MHz, Pull-up	--------	AF15
// PE12, IN,  50-MHz, Pull-up	--------	AF15
// PE13, IN,  50-MHz, Pull-up	--------	AF15
// PE14, IN,  50-MHz, Pull-up 	--------	AF15
// PE15, IN,  50-MHz, Pull-up	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(E,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KOU,KOU,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,
			  A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PF00, IN,  50-MHz, Pull-up	--------	AF15
// PF01, IN,  50-MHz, Pull-up	--------	AF15
// PF02, IN,  50-MHz, Pull-up	--------	AF15
// PF03, IN,  50-MHz, Pull-up	--------	AF15
// PF04, IN,  50-MHz, Pull-up	--------	AF15
// PF05, IN,  50-MHz, Pull-up	--------	AF15
// PF06, IN,  50-MHz, Pull-up	--------	AF15
// PF07, IN,  50-MHz, Pull-up	--------	AF15
// PF08, IN,  50-MHz, Pull-up	--------	AF15
// PF09, IN,  50-MHz, Pull-up	--------	AF15
// PF10, IN,  50-MHz, Pull-up	--------	AF15
// PF11, IN,  50-MHz, Pull-up	--------	AF15
// PF12, IN,  50-MHz, Pull-up	--------	AF15
// PF13, IN,  50-MHz, Pull-up	--------	AF15
// PF14, IN,  50-MHz, Pull-up 	--------	AF15
// PF15, IN,  50-MHz, Pull-up	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(F,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,
			  A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PG00, IN,  50-MHz, Pull-up	--------	AF15
// PG01, IN,  50-MHz, -------	VBUS_SENSE	AF15
// PG02, IN,  50-MHz, Pull-up	--------	AF15
// PG03, IN,  50-MHz, Pull-up	--------	AF15
// PG04, IN,  50-MHz, Pull-up	--------	AF15
// PG05, IN,  50-MHz, Pull-up	--------	AF15
// PG06, IN,  50-MHz, Pull-up	--------	AF15
// PG07, IN,  50-MHz, Pull-up	--------	AF15
// PG08, IN,  50-MHz, Pull-up	--------	AF15
// PG09, IN,  50-MHz, Pull-up	--------	AF15
// PG10, IN,  50-MHz, Pull-up	--------	AF15
// PG11, IN,  50-MHz, Pull-up	--------	AF15
// PG12, IN,  50-MHz, Pull-up	--------	AF15
// PG13, IN,  50-MHz, Pull-up	--------	AF15
// PG14, IN,  50-MHz, Pull-up 	--------	AF15
// PG15, IN,  50-MHz, Pull-up	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(G,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,
			  A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PH00, IN,  50-MHz, Pull-up	--------	AF15
// PH01, IN,  50-MHz, Pull-up	--------	AF15
// PH02, IN,  50-MHz, Pull-up	--------	AF15
// PH03, IN,  50-MHz, Pull-up	--------	AF15
// PH04, AL,  50-MHz, Open DU	I2C5_SDA	AF02
// PH04, AL,  50-MHz, Open DU	I2C5_SCL	AF02
// PH06, IN,  50-MHz, Pull-up	--------	AF15
// PH07, AL,  50-MHz, Open DU	I2C3_SCL	AF04
// PH08, AL,  50-MHz, Open DU	I2C3_SDA	AF04
// PH09, AL,  99-MHz, --------	HSPI1_NCS	AF08
// PH10, AL,  99-MHz, --------	HSPI1_IO0	AF08
// PH11, AL,  99-MHz, --------	HSPI1_IO1	AF08
// PH12, AL,  99-MHz, --------	HSPI1_IO2	AF08
// PH13, AL,  99-MHz, --------	HSPI1_IO3	AF08
// PH14, AL,  99-MHz, --------	HSPI1_IO4	AF08
// PH15, AL,  99-MHz, --------	HSPI1_IO5	AF08

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(H,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KIN,KAL,KAL,KIN,KIN,KIN,KIN,
			  K99,K99,K99,K99,K99,K99,K99,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KNO,KNO,KNO,KNO,KNO,KNO,KNO,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,
			  A08,A08,A08,A08,A08,A08,A08,A04,A04,A15,A02,A02,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KOD,KOD,KPP,KOD,KOD,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 1u, 0u, 1u, 1u, 0u, 0u, 0u, 0u,
			  1u, 1u, 1u, 1u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PI00, AL,  99-MHz, --------	HSPI1_IO6	AF08
// PI01, AL,  99-MHz, --------	HSPI1_IO7	AF08
// PI02, AL,  99-MHz, --------	HSPI1_DQS0	AF08
// PI03, AL,  99-MHz, --------	HSPI1_CLK	AF08
// PI04, IN,  50-MHz, Pull-up	--------	AF15
// PI05, OU,  50-MHz, --------	DSI_POWER	AF15
// PI06, OU,  50-MHz, --------	BDSI_BL		AF15
// PI07, IN,  50-MHz, Pull-up	--------	AF15
// PI08, AL,  99-MHz, --------	HSPI1_DQS1	AF08
// PI09, AL,  99-MHz, --------	HSPI1_IO8	AF08
// PI10, AL,  99-MHz, --------	HSPI1_IO9	AF08
// PI11, AL,  99-MHz, --------	HSPI1_I10	AF08
// PI12, AL,  99-MHz, --------	HSPI1_I11	AF08
// PI13, AL,  99-MHz, --------	HSPI1_I12	AF08
// PI14, AL,  99-MHz, --------	HSPI1_I13	AF08
// PI15, AL,  99-MHz, --------	HSPI1_I14	AF08

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(I,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KIN,KOU,KOU,KIN,KAL,KAL,KAL,KAL,
			  K99,K99,K99,K99,K99,K99,K99,K99,K50,K50,K50,K50,K99,K99,K99,K99,
			  KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KPU,KNO,KNO,KPU,KNO,KNO,KNO,KNO,
			  A08,A08,A08,A08,A08,A08,A08,A08,A15,A15,A15,A15,A08,A08,A08,A08,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
			  1u, 1u, 1u, 1u, 1u, 1u, 1u, 1u, 0u, 0u, 0u, 0u, 1u, 1u, 1u, 1u);

// PJ00, AL,  99-MHz, --------	HSPI1_IO15	AF08
// PJ01, IN,  50-MHz, Pull-up	--------	AF15
// PJ02, IN,  50-MHz, Pull-up	--------	AF15
// PJ03, IN,  50-MHz, Pull-up	--------	AF15
// PJ04, IN,  50-MHz, Pull-up	--------	AF15
// PJ05, IN,  50-MHz, Pull-up	--------	AF15
// PJ06, IN,  50-MHz, Pull-up	--------	AF15
// PJ07, IN,  50-MHz, Pull-up	--------	AF15
// PJ08, IN,  50-MHz, Pull-up	--------	AF15
// PJ09, IN,  50-MHz, Pull-up	--------	AF15
// PJ10, IN,  50-MHz, Pull-up	--------	AF15
// PJ11, IN,  50-MHz, Pull-up	--------	AF15
// PJ12, IN,  50-MHz, Pull-up	--------	AF15
// PJ13, IN,  50-MHz, Pull-up	--------	AF15
// PJ14, IN,  50-MHz, Pull-up 	--------	AF15
// PJ15, IN,  50-MHz, Pull-up	--------	AF15

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(J,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K99,
			  KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KPU,KNO,
			  A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A08,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u);
}

/*
 * \brief local_RCC_Configuration
 *
 * - Clock, PLL configuration
 *
 */
static	void	local_RCC_Configuration(void) {

	#ifdef KCALENDAR_WITH_HW_RTC_S

// Enable backup domain access

	REG(PWR)->DBPR |= PWR_DBPR_DBP;								// Disable backup domain write protection

// Enable LSI, select it as RTC source, and enable RTC (on STM32U5G9, LSI is in BDCR register)
// Do all BDCR modifications in minimal writes to avoid backup domain issues

	REG(RCC)->BDCR = (REG(RCC)->BDCR & ~RCC_BDCR_RTCSEL)
				   | RCC_BDCR_LSION								// Enable the LSI
				   | (2u * RCC_BDCR_RTCSEL_0)					// LSI is the source for the RTC
				   | RCC_BDCR_RTCEN;							// RTC enable

// Waiting for LSI ready

	while ((REG(RCC)->BDCR & RCC_BDCR_LSIRDY) == 0U) { ; }
	#endif

// Enable HSI, HSE & HSI48 clocks

	REG(RCC)->CR |= RCC_CR_HSION | RCC_CR_HSEON | RCC_CR_HSI48ON;

	while ((REG(RCC)->CR & RCC_CR_HSIRDY)	== 0u) { ; }
	while ((REG(RCC)->CR & RCC_CR_HSERDY)	== 0u) { ; }
	while ((REG(RCC)->CR & RCC_CR_HSI48RDY) == 0u) { ; }

// Configure Flash latency for desired frequency
// 4-ws (OK for 160-MHz)
// The I csache should compensate the 4-ws for ~0-ws

	REG(FLASH)->ACR = (4u * FLASH_ACR_LATENCY_0);

// PLL 1
// -----

// For f(ck in) = 16-MHz (HSI)
// f(out) = f(vco) / R			f(out) = 160-MHz, R = 2		---> f(vco) = 320-MHz
// f(vco) = f(ck in) * (N/M)	N/M = 20/1 = 20				---> N = 20, M = 1
// f(Q)   = f(vco) / Q			Q = 2						---> f(Q) = 160-MHz
// f(P)   = f(vco) / P			P = 2						---> f(P) = 160-MHz

	REG(RCC)->PLL1DIVR = 0u;									//
	REG(RCC)->PLL1DIVR = ((2u - 1u) * RCC_PLL1DIVR_PLL1R_0)		// Divider for R
					   | ((2u - 1u) * RCC_PLL1DIVR_PLL1Q_0)		// Divider for Q
					   | ((2u - 1u) * RCC_PLL1DIVR_PLL1P_0)		// Divider for P
					   | ((20u - 1u) * RCC_PLL1DIVR_PLL1N_0);	// Divider for N

	REG(RCC)->PLL1CFGR = RCC_PLL1CFGR_PLL1REN					// Out R enable
					   | RCC_PLL1CFGR_PLL1QEN					// Out Q enable
					   | RCC_PLL1CFGR_PLL1PEN					// Out P enable
					   | (0u * RCC_PLL1CFGR_PLL1MBOOST_0)		// PLL1 M Booster / 1
					   | (0u * RCC_PLL1CFGR_PLL1M_0)			// PLL1 M Prescaler / 1
					   | (3u * RCC_PLL1CFGR_PLL1RGE_0)			// PLL input frequency in the range of 8-MHz..16-MHz
					   | (2u * RCC_PLL1CFGR_PLL1SRC_0);			// HSI 16-MHz as a PLL input

// Waiting for stable clock and enable PLL
// Waiting for the PLL lock

	REG(RCC)->CR |= RCC_CR_PLL1ON;
	while ((REG(RCC)->CR & RCC_CR_PLL1RDY) == 0) { ; }

// PLL 3
// -----

// For f(ck in) = 16-MHz (HSI)
// f(out) = f(vco) / R			f(out) = 20.84-MHz, R = 24	---> f(vco) = 500-MHz
// f(vco) = f(ck in) * (N/M)	N/M = 125/4					---> N = 125, M = 4
// f(Q)   = f(vco) / Q			Q = 2						---> f(Q) = 250-MHz
// f(P)   = f(vco) / P			P = 24						---> f(P) = 20.84-MHz

	REG(RCC)->PLL3DIVR = 0u;									//
	REG(RCC)->PLL3DIVR = ((24u - 1u) * RCC_PLL3DIVR_PLL3R_0)	// Divider for R
					   | ((2u - 1u) * RCC_PLL3DIVR_PLL3Q_0)		// Divider for Q
					   | ((24u - 1u) * RCC_PLL3DIVR_PLL3P_0)	// Divider for P
					   | ((125u - 1u) * RCC_PLL3DIVR_PLL3N_0);	// Divider for N

	REG(RCC)->PLL3CFGR = RCC_PLL3CFGR_PLL3REN					// Out R enable
					   | RCC_PLL3CFGR_PLL3QEN					// Out Q enable
					   | RCC_PLL3CFGR_PLL3PEN					// Out P enable
					   | ((4u - 1u) * RCC_PLL3CFGR_PLL3M_0)		// PLL3 M Prescaler / 4
					   | (0u * RCC_PLL3CFGR_PLL3RGE_0)			// PLL input frequency in the range of 4-MHz..8-MHz
					   | (2u * RCC_PLL3CFGR_PLL3SRC_0);			// HSI 16-MHz as a PLL input

// Waiting for stable clock and enable PLL
// Waiting for the PLL lock

	REG(RCC)->CR |= RCC_CR_PLL3ON;
	while ((REG(RCC)->CR & RCC_CR_PLL3RDY) == 0u) { ; }

// Set-up the MCO

	REG(RCC)->CFGR1 = (2u * RCC_CFGR1_MCOPRE_0)					// MCO / 4
					| (1u * RCC_CFGR1_MCOSEL_0)					// SYSCLK output
					| (3u * RCC_CFGR1_SW_0);					// System clock on the PLL1

	REG(RCC)->CFGR2 = (4u * RCC_CFGR2_PPRE2_0)					// APB2 = HCLK / 2
					| (4u * RCC_CFGR2_PPRE1_0)					// APB1 = HCLK / 2
					| (0u * RCC_CFGR2_HPRE_0);					// HCLK = SYSCLK / 1

	REG(RCC)->CFGR3 = (4u * RCC_CFGR3_PPRE3_0);					// APB3 = HCLK / 2

	REG(RCC)->CCIPR1 = (0u * RCC_CCIPR1_TIMICSEL_0)				//
					 | (0u * RCC_CCIPR1_ICLKSEL_0)				// USB_OTG_FS uses 48-MHz clock
					 | (1u * RCC_CCIPR1_FDCAN1SEL_0)			// FDCAN uses PLL1Q clock
					 | (0u * RCC_CCIPR1_SYSTICKSEL_0)			// SYSTICK uses HCLK / 8 clock
					 | (0u * RCC_CCIPR1_SPI1SEL_0)				// SPI1 uses PCLK2 clock
					 | (0u * RCC_CCIPR1_LPTIM2SEL_0)			// LPTIM2 uses PCLK1 clock
					 | (0u * RCC_CCIPR1_SPI2SEL_0)				// SPI2 uses PCLK1 clock
					 | (0u * RCC_CCIPR1_I2C4SEL_0)				// I2C4 uses PCLK1 clock
					 | (0u * RCC_CCIPR1_I2C2SEL_0)				// I2C2 uses PCLK1 clock
					 | (0u * RCC_CCIPR1_I2C1SEL_0)				// I2C1 uses PCLK1 clock
					 | (0u * RCC_CCIPR1_UART5SEL_0)				// UART5 uses PCLK1 clock
					 | (0u * RCC_CCIPR1_UART4SEL_0)				// UART4 uses PCLK1 clock
					 | (0u * RCC_CCIPR1_USART3SEL_0)			// USART3 uses PCLK1 clock
					 | (0u * RCC_CCIPR1_USART2SEL_0)			// USART2 uses PCLK1 clock
					 | (0u * RCC_CCIPR1_USART1SEL_0);			// USART1 uses PCLK2 clock

	REG(RCC)->CCIPR2 = (0u * RCC_CCIPR2_OTGHSSEL_0)				// OTGH uses HSE clock
					 | (0u * RCC_CCIPR2_I2C6SEL_0)				// I2C6 uses PCLK1 clock
					 | (0u * RCC_CCIPR2_I2C5SEL_0)				// I2C5 uses PCLK1 clock
					 | (0u * RCC_CCIPR2_HSPI1SEL_0)				// HSPI1 uses System Clock clock
					 | (0u * RCC_CCIPR2_OCTOSPISEL_0)			// OCTOSP uses System Clock clock
					 | (0u * RCC_CCIPR2_LTDCSEL)				// LTDC uses PLL3R clock
					 | (0u * RCC_CCIPR2_USART6SEL_0)			// USART6 uses PCLK1 clock
					 | (0u * RCC_CCIPR2_DSISEL)					// DSI uses PLL3P clock
					 | (2u * RCC_CCIPR2_RNGSEL_0)				// RNG uses HSI clock
					 | (4u * RCC_CCIPR2_SAI2SEL_0)				// SAI2 uses HSI clock
					 | (4u * RCC_CCIPR2_SAI1SEL_0)				// SAI1 uses HSI clock
					 | (0u * RCC_CCIPR2_MDF1SEL_0);				// MDF1 uses HCLK clock

	REG(RCC)->CCIPR3 = (0u * RCC_CCIPR3_ADF1SEL_0)				// ADF1 uses HCLK clock
					 | RCC_CCIPR3_DAC1SEL						// DAC1 uses LSI clock
					 | (0u * RCC_CCIPR3_ADCDACSEL_0)			// ADCDAC uses HCLK clock
					 | (2u * RCC_CCIPR3_LPTIM1SEL_0)			// LPTIM1 uses HSI16 clock
					 | (2u * RCC_CCIPR3_LPTIM34SEL_0)			// LPTIM34 uses HSI clock
					 | (0u * RCC_CCIPR3_I2C3SEL_0)				// I2C3 uses PCLK3 clock
					 | (0u * RCC_CCIPR3_SPI3SEL_0)				// SPI3 uses PCLK3 clock
					 | (0u * RCC_CCIPR3_LPUART1SEL_0);			// LPUART1 uses PCLK3 clock
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
	SET_MPU8_REGION(0u,	ST_FLASH_INT_0,		EN_FLASH_INT_0,		KMPU_EXECUTABLE,		KMPU_R_ALL,  0u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(1u,	ST_RAM_INT_0_OS,	EN_RAM_INT_0_OS,	KMPU_EXECUTABLE,		KMPU_RW_PRI, 1u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(2u,	ST_RAM_INT_0,		EN_RAM_INT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL, 1u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(3u,	ST_PERIPH_SOC,		EN_PERIPH_SOC,		KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI, 3u, KMPU_NOT_SHAREABLE);
	SET_MPU8_REGION(4u,	ST_PERIPH_CORE,		EN_PERIPH_CORE,		KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI, 3u, KMPU_NOT_SHAREABLE);

	#else
	SET_MPU8_REGION(0u,	ST_FLASH_INT_0,		EN_FLASH_INT_0,		KMPU_EXECUTABLE,		KMPU_R_ALL,  0u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(1u,	ST_RAM_INT_0,		EN_RAM_INT_0,		KMPU_EXECUTABLE,		KMPU_RW_ALL, 1u, KMPU_INNER_SHAREABLE);
	#endif
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

	cache_D_Invalidate(0);
	cache_D_Enable(0);
}

#include	"model_I_D_cache.c_inc"
