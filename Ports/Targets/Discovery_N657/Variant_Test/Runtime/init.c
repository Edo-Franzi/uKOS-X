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

#include	"uKOS.h"
#include	"cache.h"
#include	"linker.h"
#include	"APS256XXN/APS256XXN.h"

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

// For connecting the LTDC to the AXI graphic frame buffer

extern	uint32_t					linker_stLCD_F_BUFFER[];
extern	uint32_t					linker_lnLCD_F_BUFFER[];
#define	FB_ADDR						((uint32_t)linker_stLCD_F_BUFFER)
#define	FB_SIZE						((uint32_t)linker_lnLCD_F_BUFFER)
#define	FB_END						(FB_ADDR + FB_SIZE - 1u)

// Connect the physical device to the logical manager

#undef	APSRAM_READ_REGISTER
#define	APSRAM_WRITE_REGISTER
#define	XSPI_UNIT					REG(XSPI1)
#define	xspi_apsram_init			model_xspi_apsram_init

// Prototypes

static			void	local_StackLimit_Configuration(void);
static			void	local_Boot_thirdStageBoot(void);
static			void	local_PWR_Configuration(void);
static			void	local_GPIO_Compensation(void);
static			void	local_GPIO_Configuration(void);
static			void	local_RCC_Configuration(void);
static			void	local_MPU_Configuration(void);
static			void	local_FPE_Configuration(void);
static			void	local_USB_Configuration(void);
static			void	local_Protection_Configuration(void);
static			void	local_MCO2_Configuration(void);
static			void	local_CACHE_Enable(void);
static			void	local_write_TCPP0203(uint8_t addresse, uint8_t value);
static			void	local_writeByte(uint8_t byte);
static			void	local_waitingForFlagOn(uint32_t flag);
static			void	local_waitingForFlagOff(uint32_t flag);
static			void	local_wait_us(uint32_t us);
extern			void	model_xspi_apsram_init(void);

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

	local_Boot_thirdStageBoot();
	local_StackLimit_Configuration();
	local_PWR_Configuration();
	local_GPIO_Compensation();
	local_GPIO_Configuration();
	local_RCC_Configuration();
	local_MPU_Configuration();
	local_FPE_Configuration();
	local_USB_Configuration();
	local_Protection_Configuration();
	local_MCO2_Configuration();
	local_CACHE_Enable();
	xspi_apsram_init();
}

/*
 * \brief local_Boot_thirdStageBoot
 *
 * - The FSBL load only 64K
 *	 - This third stage boot copy the remaining bytes
 *	   For the moment, it is copied a fixed length
 *
 *	 !!! Mandatory to use MMIO = Memory-Mapped I/O (volatile)
 *   to avoid the usage of memcpy.
 *
 */
static	void	local_Boot_thirdStageBoot(void) {
						size_t		remaining;
						uint8_t		tmp;
				const	size_t		lnFLASH = (size_t)((uintptr_t)linker_enCODE - (uintptr_t)linker_stCODE);
	volatile	const	uint8_t		*from = (volatile const uint8_t *)(0x70100000u + 0x10000u);
	volatile			uint8_t		*to   = (volatile       uint8_t *)(0x34000000u + 0x10000u);

// Third boot stage (if the lnFLASH > 64K)

	if (lnFLASH >= 65536u) {
		remaining = lnFLASH;
		while (remaining != 0u) {
			tmp = *from;
			*to = tmp;
			to++; from++;
			remaining--;
		}
	}
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
 * \brief local_GPIO_Compensation
 *
 * - GPIO compensation
 *
 */
static	void	local_GPIO_Compensation(void) {

	REG(RCC)->APB4HENR |= RCC_APB4HENR_SYSCFGEN;
	STRONG_BARRIER;

	REG(SYSCFG)->VDDIO1CCCR |= SYSCFG_VDDIO1CCCR_EN;
	REG(SYSCFG)->VDDIO2CCCR |= SYSCFG_VDDIO2CCCR_EN;
	REG(SYSCFG)->VDDIO3CCCR |= SYSCFG_VDDIO3CCCR_EN;
	REG(SYSCFG)->VDDIO4CCCR |= SYSCFG_VDDIO4CCCR_EN;
	REG(SYSCFG)->VDDIOCCCR  |= SYSCFG_VDDIOCCCR_EN;
	STRONG_BARRIER;

	while ((REG(SYSCFG)->VDDIO1CCSR & SYSCFG_VDDIO1CCSR_READY) == 0u) { ; }
	while ((REG(SYSCFG)->VDDIO2CCSR & SYSCFG_VDDIO2CCSR_READY) == 0u) { ; }
	while ((REG(SYSCFG)->VDDIO3CCSR & SYSCFG_VDDIO3CCSR_READY) == 0u) { ; }
	while ((REG(SYSCFG)->VDDIO4CCSR & SYSCFG_VDDIO4CCSR_READY) == 0u) { ; }
	while ((REG(SYSCFG)->VDDIOCCSR  & SYSCFG_VDDIOCCSR_READY)  == 0u) { ; }
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
 *   Setup timeline extracted by chatgpt from the TinyUSB package
 *
 */
static	void	local_USB_Configuration(void) {

	REG(RCC)->APB1LENR |= RCC_APB1LENR_I2C2EN;
	(void)(REG(RCC)->APB1LENR);

// 1. Turn-on the power domain (alredy done in local_PWR_Configuration)
// 2. System clocks (partially done in (local_RCC_Configuration)
// 3. GPIO's already done in (local_GPIO_Configuration)

	REG(RCC)->MISCENSR = RCC_MISCENSR_PERENS;
	(void)(REG(RCC)->MISCENSR);

	REG(RCC)->CCIPR6 |= RCC_CCIPR6_OTGPHY1CKREFSEL | (3u * RCC_CCIPR6_OTGPHY1SEL_0);
	(void)(REG(RCC)->CCIPR6);

	REG(RCC)->HSECFGR |= RCC_HSECFGR_HSEDIV2BYP;
	(void)(REG(RCC)->HSECFGR);

// 4. USB clock & USB 3.3V

	REG(RCC)->AHB5ENR   |= RCC_AHB5ENR_OTG1EN;
	REG(RCC)->AHB5LPENR |= RCC_AHB5LPENR_OTG1LPEN;
	(void)(REG(RCC)->AHB5ENR);
	(void)(REG(RCC)->AHB5LPENR);

	REG(PWR)->SVMCR3 |= PWR_SVMCR3_USB33VMEN;
	(void)(REG(PWR)->SVMCR3);
	while ((REG(PWR)->SVMCR3 & PWR_SVMCR3_USB33RDY) == 0u) { ; }

	REG(PWR)->SVMCR3 |= PWR_SVMCR3_USB33SV;

// 5. USB: resets (SETR/CLRR) + helper HSEDiv2 (LL) + re-enable

	REG(RCC)->AHB5RSTSR = RCC_AHB5RSTSR_SYSCFGOTGHSPHY1RSTS;
	REG(RCC)->AHB5RSTSR = RCC_AHB5RSTSR_OTG1RSTS;
	REG(RCC)->AHB5RSTSR = RCC_AHB5RSTSR_OTGPHY1RSTS;

	REG(RCC)->HSECFGR  |= RCC_HSECFGR_HSEDIV2BYP;
	(void)(REG(RCC)->HSECFGR);

	REG(RCC)->AHB5RSTCR = RCC_AHB5RSTSR_SYSCFGOTGHSPHY1RSTS;

	REG(RCC)->AHB5ENR	|= RCC_AHB5ENR_OTG1EN;
	(void)(REG(RCC)->AHB5ENR);
	REG(RCC)->AHB5LPENR |= RCC_AHB5LPENR_OTG1LPEN;
	(void)(REG(RCC)->AHB5LPENR);

// 6. Setup of the PHY

	local_wait_us(10u);
	REG(USB1_HS_PHYC)->USBPHYC_CR &= (uint32_t)~(0x7u<<0x4u);
	REG(USB1_HS_PHYC)->USBPHYC_CR |= (0x1u<<16u) | (0x2u<<4u) | (0x1u<<2u) | 0x1u;

// 7. PHY: resets (SETR/CLRR) + clock

	REG(RCC)->AHB5RSTCR = RCC_AHB5RSTCR_OTGPHY1RSTC;
	local_wait_us(10u);
	REG(RCC)->AHB5RSTCR = RCC_AHB5RSTCR_OTG1RSTC;
	REG(RCC)->AHB5ENSR  = RCC_AHB5ENSR_OTGPHY1ENS;
	(void)(REG(RCC)->AHB5ENR);

// 8. TCPP0203 (switch USB-PD) — I2C2 + transactions
//    Set the mode hybernate to make possible
//    the usage of all the USB-C cable (CCx negotiation)

	local_wait_us(1000u);
	local_write_TCPP0203(0x00u, 0x00u);
	local_wait_us(1000000u);
}

/*
 * \brief local_Protection_Configuration
 *
 * - Disable the bus protections
 *   This to allow the connection between the LTDC to the AXI bus
 *
 */
#define RISAF_REG_CFGR_BREN				(1u<<0)
#define RISAF_REG_CFGR_SEC				(1u<<8)
#define RISAF_REG_CIDCFGR_RDENC_ALL		(0xFFu<<0)
#define RISAF_REG_CIDCFGR_WRENC_ALL		(0xFFu<<16)
#define RIMC_ATTR_MCID_1				(1u<<4)
#define RIMC_ATTR_MSEC					(1u<<8)
#define RIMC_ATTR_MPRIV					(1u<<9)
#define	RIMC_ATTR_SEC_CID1_PRIV			(RIMC_ATTR_MSEC | RIMC_ATTR_MPRIV | RIMC_ATTR_MCID_1)

static	void	local_Protection_Configuration(void) {

	REG(RCC)->AHB3ENR	|= RCC_AHB3ENR_RIFSCEN;
	REG(RCC)->AHB3LPENR	|= RCC_AHB3LPENR_RIFSCLPEN;
	STRONG_BARRIER;

// Graphic Frame buffer region

	REG(RISAF)->REG1_CFGR	= 0u;
	REG(RISAF)->REG1_STARTR	= FB_ADDR;
	REG(RISAF)->REG1_ENDR	= FB_END;

// CID0..CID7 allow Reads/Writes

	REG(RISAF)->REG1_CIDCFGR = RISAF_REG_CIDCFGR_RDENC_ALL | RISAF_REG_CIDCFGR_WRENC_ALL;

	REG(RISAF)->REG1_ACFGR	 = 0u;
	REG(RISAF)->REG1_ASTARTR = 0u;
	REG(RISAF)->REG1_AENDR	 = 0u;
	REG(RISAF)->REG1_ANESTR	 = 0u;

	REG(RISAF)->REG1_BCFGR	 = 0u;
	REG(RISAF)->REG1_BSTARTR = 0u;
	REG(RISAF)->REG1_BENDR	 = 0u;
	REG(RISAF)->REG1_BNESTR	 = 0u;

	REG(RISAF)->IACR		 = 0xFFFFFFFFu;

// BREN + SEC, sans PRIVC

	REG(RISAF)->REG1_CFGR = RISAF_REG_CFGR_BREN | RISAF_REG_CFGR_SEC;
	STRONG_BARRIER;

// RISUP 102/103/104: LTDC_CMN, LTDC_L1, LTDC_L2

	REG(RIFSC)->RISC_SECCFGR3  |= 0x000001C0u;
	REG(RIFSC)->RISC_PRIVCFGR3 |= 0x000001C0u;

// Master LTDC1 / LTDC_L1 / LTDC_L2
// Important point: The LTDC master needs to have the same
// memory attributes than the periphs

	REG(RIFSC)->RIMC_ATTR10 = RIMC_ATTR_SEC_CID1_PRIV;
	REG(RIFSC)->RIMC_ATTR11 = RIMC_ATTR_SEC_CID1_PRIV;
	STRONG_BARRIER;
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
					   |  RCC_AHB4ENR_GPIOPEN
					   |  RCC_AHB4ENR_GPIOQEN);
	STRONG_BARRIER;

// Init all the GPIO A, B, C, D, E, F, G, H, I, J

// PA00, AL,  99-MHz, Push-pull	RGB.G3		AF14
// PA01, AL,  99-MHz, Push-pull	RGB.G2		AF14	AF15, but Cube initialise AF14
// PA02, AL,  99-MHz, Push-pull	RGB.B7		AF14	AF15, but Cube initialise AF14
// PA03, IN,  50-MHz, Pull-up	--------	AF15
// PA04, OU,  50-MHz, Pull-down	GPIO		AF15	E TCPP03
// PA05, IN,  50-MHz, Pull-up	--------	AF15
// PA06, IN,  50-MHz, Pull-up	--------	AF15
// PA07, AL,  99-MHz, Push-pull	RGB.B1		AF15	AF15, but Cube initialise AF14
// PA08, AL,  99-MHz, Push-pull	RGB.B6		AF14	AF15, but Cube initialise AF14
// PA09, IN,  50-MHz, Pull-up	--------	AF15
// PA10, IN,  50-MHz, Pull-up	--------	AF15
// PA11, IN,  50-MHz, Pull-up	--------	AF15
// PA12, IN,  50-MHz, Pull-up	--------	AF15
// PA13, AL,  50-MHz, Pull-up 	TMS			AF00
// PA14, AL,  50-MHz, Pull-down TCK			AF00
// PA15, AL,  99-MHz, Push-pull	RGB.R5		AF14	AF15, but Cube initialise AF14

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(A,KAL,KAL,KAL,KIN,KIN,KIN,KIN,KAL,KAL,KIN,KIN,KOU,KIN,KAL,KAL,KAL,
			  K99,K50,K50,K50,K50,K50,K50,K99,K99,K50,K50,K50,K50,K99,K99,K99,
			  KNO,KPU,KPU,KPU,KPU,KPU,KPU,KNO,KNO,KPU,KPU,KNO,KPU,KNO,KNO,KNO,
			  A14,A00,A00,A15,A15,A15,A15,A14,A14,A15,A15,A15,A15,A14,A14,A14,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 1u, 0u, 0u, 0u, 0u);

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
			  KNO,KPU,KPD,KPD,KPD,KPD,KNO,KNO,KPD,KPD,KPD,KPU,KPD,KPD,KPD,KPD,
			  A14,A04,A15,A15,A15,A15,A14,A14,A15,A15,A15,A04,A15,A15,A15,A15,
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
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

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
// PG13, OU,  99-MHz, Push-pull	LCD_DE		AF15	Force 1 as described n the cube
// PG14, IN,  50-MHz, Pull-down	--------	AF15
// PG15, AL,  99-MHz, Push-pull	RGB.B0		AF14

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(G,KAL,KIN,KOU,KAL,KAL,KOU,KIN,KAL,KIN,KAL,KIN,KIN,KIN,KIN,KAL,KAL,
			  K99,K50,K99,K99,K99,K50,K50,K99,K50,K99,K50,K50,K50,K50,K99,K99,
			  KNO,KPD,KNO,KNO,KNO,KNO,KPD,KNO,KPD,KNO,KPD,KPD,KPD,KPD,KNO,KNO,
			  A14,A15,A15,A14,A14,A15,A15,A14,A15,A14,A15,A15,A15,A15,A14,A14,
			  KPP,KPP,KPP,KPP,KPP,KOD,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 1u, 0u, 0u, 1u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

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

// PO00, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PO01, OU,  50-MHz, Push-pull	GPIO		AF15	Led 1
// PO02, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PO03, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PO04, AL,  99-MHz, Push_pull	XSPI_IO		AF09
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
	CNFGPIO(O,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KAL,KAL,KAL,KOU,KAL,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K99,K99,K99,K50,K99,
			  KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KNO,KNO,KNO,KNO,KNO,
			  A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A09,A09,A09,A15,A09,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PP00, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PP01, AL,  99-MHz, Push-pull	XSPI_IO		AF09
// PP02, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PP03, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PP04, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PP05, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PP06, AL,  99-MHz, Push-pull	XSPI_IO		AF09
// PP07, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PP08, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PP09, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PP10, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PP11, AL,  99-MHz, Push-pull	XSPI_IO		AF09
// PP12, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PP13, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PP14, AL,  99-MHz, Push_pull	XSPI_IO		AF09
// PP15, AL,  99-MHz, Push_pull	XSPI_IO		AF09

//			   15  14  13  12  11  10   9   8   7   6   5   4   3   2   1   0
	CNFGPIO(P,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,KAL,
			  K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,K99,
			  KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,KNO,
			  A09,A09,A09,A09,A09,A09,A09,A09,A09,A09,A09,A09,A09,A09,A09,A09,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);

// PQ00, IN,  50-MHz, Pull-down	--------	AF15
// PQ01, IN,  50-MHz, Pull-down	--------	AF15
// PQ02, IN,  50-MHz, Pull-down	--------	AF15
// PQ03, OU,  50-MHz, Pull-down	GPIO		AF15	LCD_POWER
// PQ04, IN,  50-MHz, Pull-down	--------	AF15
// PQ05, IN,  50-MHz, Pull-down	--------	AF15
// PQ06, OU,  50-MHz, Pull-down	GPIO		AF15	BBL_CTRL
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
	CNFGPIO(Q,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KIN,KOU,KIN,KIN,KOU,KIN,KIN,KIN,
			  K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,K50,
			  KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KPD,KNO,KPD,KPD,KNO,KPD,KPD,KPD,
			  A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,A15,
			  KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,KPP,
			  0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u);
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

	#ifdef KCALENDAR_WITH_HW_RTC_S

// Enable backup domain access

	REG(PWR)->DBPCR |= PWR_DBPCR_DBP;							// Disable backup domain write protection

// Enable LSI, select it as RTC source, and enable RTC
// On STM32N657: LSI in CR, RTC source in CCIPR7, RTC enable in APB4LENR

	REG(RCC)->CR |= RCC_CR_LSION;								// Enable the LSI

// Waiting for LSI ready

	while ((REG(RCC)->SR & RCC_SR_LSIRDY) == 0U) { ; }

// Select LSI as RTC source and enable RTC

	REG(RCC)->CCIPR7 = (REG(RCC)->CCIPR7 & ~RCC_CCIPR7_RTCSEL)
					 | (2u * RCC_CCIPR7_RTCSEL_0);				// LSI is the source for the RTC
	REG(RCC)->APB4LENR |= RCC_APB4LENR_RTCEN;					// RTC enable
	#endif

	REG(RCC)->CR |= RCC_CR_HSION								// Set HSION bit (64-MHz)
				  | RCC_CR_HSEON;								// Set HSEON bit (48-MHz)
	(void)(REG(RCC)->CR);										//

	while ((REG(RCC)->SR & RCC_SR_HSIRDY) == 0u) { ; }			// Waiting for the HSI stable
	while ((REG(RCC)->SR & RCC_SR_HSERDY) == 0u) { ; }			// Waiting for the HSE stable

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

	REG(RCC)->IC2CFGR = (0u * RCC_IC2CFGR_IC2SEL_0)				// PLL1
					  | ((2u - 1u) * RCC_IC2CFGR_IC2INT_0);		// IC2 = PLL1 / 2, ~400_MHz
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

// System clock (IC3 mux) for xspi2 (set in the FSBL)
// System clock (IC4 mux) for xspi1

	REG(RCC)->IC4CFGR = (3u * RCC_IC4CFGR_IC4SEL_0)				// PLL4
					  | ((2u - 1u) * RCC_IC4CFGR_IC4INT_0);		// IC4 = PLL4 / 2, ~200_MHz
	STRONG_BARRIER;												//
	REG(RCC)->DIVENR |= RCC_DIVENR_IC4EN;						//
	(void)(REG(RCC)->DIVENR);									//

// Bus speeds
// ----------

// CPU & AXI clocks
// - CPU -> 800-MHz (sysa_ck)
// - SYS -> 400-MHz (sysb_ck)
//					(sysc_ck) not used
//					(sysd_ck) not used
// - PERCK -> HSI

	REG(RCC)->CFGR1 = (3u * RCC_CFGR1_CPUSW_0)					// IC1 (PLL1 / 1) as a CPU clock
					| (3u * RCC_CFGR1_SYSSW_0);					// IC2 (PLL4 / 1) as a SYS clock

	REG(RCC)->CCIPR7 = (0u * RCC_CCIPR7_PERSEL_0);				// per_ck (periph kernel = HSI)

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
	SET_MPU8_REGION(0u,	ST_RAM_INT_1,		EN_RAM_INT_1,		KMPU_EXECUTABLE,		KMPU_R_ALL,  0u, KMPU_NOT_SHAREABLE);
	SET_MPU8_REGION(1u,	ST_RAM_INT_2_OS,	EN_RAM_INT_2_OS,	KMPU_EXECUTABLE,		KMPU_RW_PRI, 1u, KMPU_NOT_SHAREABLE);
	SET_MPU8_REGION(2u,	ST_RAM_INT_2,		EN_RAM_INT_2,		KMPU_EXECUTABLE,		KMPU_RW_ALL, 1u, KMPU_NOT_SHAREABLE);
	SET_MPU8_REGION(3u,	ST_RAM_INT_3,		EN_RAM_INT_3,		KMPU_NOT_EXECUTABLE,	KMPU_RW_ALL, 2u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(4u,	ST_APSRAM,			EN_APSRAM,			KMPU_EXECUTABLE,		KMPU_RW_ALL, 1u, KMPU_NOT_SHAREABLE);
	SET_MPU8_REGION(5u,	ST_OCTOFLASH,		EN_OCTOFLASH,		KMPU_NOT_EXECUTABLE,	KMPU_RW_ALL, 2u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(6u,	ST_PERIPH_SOC,		EN_PERIPH_SOC,		KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI, 3u, KMPU_NOT_SHAREABLE);
	SET_MPU8_REGION(7u,	ST_PERIPH_CORE,		EN_PERIPH_CORE,		KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI, 3u, KMPU_NOT_SHAREABLE);

	#else
	SET_MPU8_REGION(0u,	ST_RAM_INT_1,		EN_RAM_INT_1,		KMPU_EXECUTABLE,		KMPU_R_ALL,  0u, KMPU_NOT_SHAREABLE);
	SET_MPU8_REGION(1u,	ST_RAM_INT_2,		EN_RAM_INT_2,		KMPU_EXECUTABLE,		KMPU_RW_ALL, 1u, KMPU_NOT_SHAREABLE);
	SET_MPU8_REGION(2u,	ST_RAM_INT_3,		EN_RAM_INT_3,		KMPU_NOT_EXECUTABLE,	KMPU_RW_ALL, 2u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(3u,	ST_APSRAM,			EN_APSRAM,			KMPU_EXECUTABLE,		KMPU_RW_ALL, 1u, KMPU_NOT_SHAREABLE);
	SET_MPU8_REGION(4u,	ST_OCTOFLASH,		EN_OCTOFLASH,		KMPU_NOT_EXECUTABLE,	KMPU_RW_ALL, 2u, KMPU_INNER_SHAREABLE);
	#endif

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
// n = 5, ic15_ck		(OK, ~400-MHz !!!) = pll1 / 2  -> pll1 = 800-MHz
// n = 6, ic20_ck		(OK, ~40-MHz !!!)  = pll3 / 10 -> pll3 = 400-MHz
// n = 7, sysb_ck		(OK, ~400-MHz !!!) = pll4

#define	n	5u

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

	REG(MEMSYSCTL)->MSCR |= MEMSYSCTL_MSCR_DCACTIVE | MEMSYSCTL_MSCR_ICACTIVE;

	cache_I_Invalidate();
	cache_I_Enable();

	cache_D_Invalidate();
	cache_D_Enable();
}

/*
 * \brief cb_enable
 *
 * - Enable the the necessary harware
 *
 */
static	void	cb_enable(void) {

	REG(RCC)->AHB5ENR	|=  RCC_AHB5ENR_XSPI1EN;
	REG(RCC)->AHB5ENR	|=  RCC_AHB5ENR_XSPIMEN;
	REG(RCC)->AHB5LPENR	|=  RCC_AHB5LPENR_XSPI1LPEN;
	REG(RCC)->AHB5RSTR	|=  RCC_AHB5RSTR_XSPI1RST;
	REG(RCC)->AHB5RSTR	&= ~RCC_AHB5RSTR_XSPI1RST;

	STRONG_BARRIER;

// ic4 = 200-MHz (pll4 / 2)

	#if (defined(WK))
	REG(RCC)->CCIPR6 &= ~RCC_CCIPR6_XSPI1SEL;
	REG(RCC)->CCIPR6 |=  (3u * RCC_CCIPR6_XSPI1SEL_0);
	(void)(REG(RCC)->CCIPR6);
	#endif

	STRONG_BARRIER;
}

/*
 * \brief local_write_TCPP0203
 *
 * - Set the power of the TCPP0203 to normal
 *
 */
#define	KI2C_ADD_TCPP0203	0x34u
#define	KTCPP0203_NB_MONO	2u

static	void	local_write_TCPP0203(uint8_t addresse, uint8_t value) {

// Initialise the I2C Master, default speed 100-KHz

	REG(I2C2)->CR2 &= (uint32_t)~I2C_CR1_PE;

	REG(I2C2)->TIMINGR = (4u * I2C_TIMINGR_PRESC_0)						// Timing prescaler
					   | (9u * I2C_TIMINGR_SCLDEL_0)					// Data setup time
					   | (1u * I2C_TIMINGR_SDADEL_0)					// Data hold time
					   | (52u * I2C_TIMINGR_SCLH_0)						// SCL high period
					   | (52u * I2C_TIMINGR_SCLL_0);					// SCL Low period

	REG(I2C2)->CR1     = I2C_CR1_NOSTRETCH								// Clock stretching disabled
					   | I2C_CR1_ANFOFF;								// Analog noise filter disabled

	REG(I2C2)->CR1	  |= I2C_CR1_PE;									// Periph enable

// Minimal send of data to the TCPP0203

	local_waitingForFlagOff(I2C_ISR_BERR);
	local_waitingForFlagOn(I2C_ISR_TXE);

	REG(I2C2)->CR2 = (0u * I2C_CR2_PECBYTE)								// No packet error
				   | I2C_CR2_AUTOEND									// Automatic end mode
				   | (0u * I2C_CR2_RELOAD)								// No reload mode
				   | ((KTCPP0203_NB_MONO & 0xFFu) * I2C_CR2_NBYTES_0)	// Number of bytes to transfer
				   | (0u * I2C_CR2_NACK)								// No NACK
				   | (0u * I2C_CR2_STOP)								// No STOP
				   | (0u * I2C_CR2_HEAD10R)								// No HEADER 10
				   | (0u * I2C_CR2_ADD10)								// Address on 7 bits
				   | (0u * I2C_CR2_RD_WRN)								// Write transfer
				   | ((KI2C_ADD_TCPP0203<<1u) * I2C_CR2_SADD_0);		// The slave address

	REG(I2C2)->CR2 |= I2C_CR2_START;									// START

	local_waitingForFlagOff(I2C_ISR_BERR);								//
	local_waitingForFlagOn(I2C_ISR_TXE);								//
	local_waitingForFlagOff(I2C_ISR_NACKF);								//

	local_writeByte(addresse);											//
	local_writeByte(value);												//

// Wait after each write

	local_wait_us(1000000u);											//
}

/*
 * \brief local_writeByte
 *
 */
static	void	local_writeByte(uint8_t byte) {

	local_waitingForFlagOn(I2C_ISR_TXE);

	REG(I2C2)->TXDR = (uint32_t)byte;
}

/*
 * \brief local_waitingForFlagOn
 *
 */
static	void	local_waitingForFlagOn(uint32_t flag) {

	while ((REG(I2C2)->ISR & flag) != flag) { ; }
}

/*
 * \brief local_waitingForFlagOff
 *
 */
static	void	local_waitingForFlagOff(uint32_t flag) {

	while ((REG(I2C2)->ISR & flag) == flag) { ; }
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

	for (time = 0; time < us; time++) { NOP; }
}

#include	"model_xpi_apsram.c_inc"
