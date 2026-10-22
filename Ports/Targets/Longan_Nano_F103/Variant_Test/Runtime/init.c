/*
; init.
; =====
;
; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
;
;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Low level init for the uKOS-X Longan_Nano_F103 module.
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

bool	vExce_isException[KNB_CORES] = MCSET(false);

typedef	struct	gpio	gpio_t;

struct	gpio {
			uint8_t		oPort;				// Port
			uint8_t		oConfiguration;		// Configuration
			uint8_t		oOutputQuite;		// Output value in a quite state
		};

// Prototypes

static	void	local_GPIO_Configuration(void);
static	void	local_RCU_Configuration(void);
static	void	local_ECLIC_Configuration(void);

/*
 * \brief init_init
 *
 * - Initialise some basic periphs
 * - GPIO, watchdog, RTC
 *
 *
 * \note This function does not return a value (None).
 *
 */
void	init_init(void) {

	local_GPIO_Configuration();				// GPIO Config
	local_RCU_Configuration();				// Clock Config
	local_ECLIC_Configuration();			// ECLIC Config
}

/*
 * \brief local_GPIO_Configuration
 *
 * - GPIO configuration
 *
 */
static	void	local_PortConfigure(uint8_t configuration, uint8_t index, uint8_t pos, uint8_t out, volatile uint32_t *ctl, volatile uint32_t *octl) {

	index = index * 4u;

	switch (configuration) {
		case KIN_ANAOG:		{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0x0u<<index);																	  break; }
		case KIN_FLOAT:		{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0x4u<<index);																	  break; }
		case KIN_PULLD:		{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0x8u<<index); *octl = (*octl & (uint32_t)~(0x1u<<pos));						  break; }
		case KIN_PULLU:		{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0x8u<<index); *octl = (*octl & (uint32_t)~(0x1u<<pos)) | (uint32_t)(0x1u<<pos); break; }
		case KOU_PUSHP_02:	{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0x2u<<index); *octl = (*octl & (uint32_t)~(0x1u<<pos)) | (uint32_t)(out<<pos);  break; }
		case KOU_OPEND_02:	{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0x6u<<index); *octl = (*octl & (uint32_t)~(0x1u<<pos)) | (uint32_t)(out<<pos);  break; }
		case KOU_PUSHP_10:	{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0x1u<<index); *octl = (*octl & (uint32_t)~(0x1u<<pos)) | (uint32_t)(out<<pos);  break; }
		case KOU_OPEND_10:	{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0x5u<<index); *octl = (*octl & (uint32_t)~(0x1u<<pos)) | (uint32_t)(out<<pos);  break; }
		case KOU_PUSHP_50:	{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0x3u<<index); *octl = (*octl & (uint32_t)~(0x1u<<pos)) | (uint32_t)(out<<pos);  break; }
		case KOU_OPEND_50:	{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0x7u<<index); *octl = (*octl & (uint32_t)~(0x1u<<pos)) | (uint32_t)(out<<pos);  break; }
		case KAF_PUSHP_02:	{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0xAu<<index); *octl = (*octl & (uint32_t)~(0x1u<<pos)) | (uint32_t)(out<<pos);  break; }
		case KAF_OPEND_02:	{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0xEu<<index); *octl = (*octl & (uint32_t)~(0x1u<<pos)) | (uint32_t)(out<<pos);  break; }
		case KAF_PUSHP_10:	{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0x9u<<index); *octl = (*octl & (uint32_t)~(0x1u<<pos)) | (uint32_t)(out<<pos);  break; }
		case KAF_OPEND_10:	{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0xDu<<index); *octl = (*octl & (uint32_t)~(0x1u<<pos)) | (uint32_t)(out<<pos);  break; }
		case KAF_PUSHP_50:	{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0xBu<<index); *octl = (*octl & (uint32_t)~(0x1u<<pos)) | (uint32_t)(out<<pos);  break; }
		case KAF_OPEND_50:	{ *ctl = (*ctl & (uint32_t)~(0xFu<<index)) | (0xFu<<index); *octl = (*octl & (uint32_t)~(0x1u<<pos)) | (uint32_t)(out<<pos);  break; }
		default: {

// Make MISRA happy :-)

			break;
		}
	}
}

static	void	local_GPIO_Configuration(void) {
		uint8_t		i;
static	const		gpio_t	aGPIO_Cnf[] = {
								{ (uint8_t)PA00, KIN_PULLD,    0u },			// GPIO input
								{ (uint8_t)PA01, KOU_PUSHP_02, 1u },			// GPIO output	LED_G
								{ (uint8_t)PA02, KOU_PUSHP_02, 1u },			// GPIO output	LED_B
								{ (uint8_t)PA03, KIN_PULLD,    0u },			// GPIO input
								{ (uint8_t)PA04, KIN_PULLD,    0u },			// GPIO input
								{ (uint8_t)PA05, KAF_OPEND_50, 0u },			// SPI0_CLK		LCD_SCK
								{ (uint8_t)PA06, KIN_PULLD,    0u },			// GPIO input
								{ (uint8_t)PA07, KAF_OPEND_50, 0u },			// SPI0_MOSI	LCD_SDA
								{ (uint8_t)PA08, KAF_PUSHP_50, 0u },			// GPIO output	(clock-out)(
								{ (uint8_t)PA09, KAF_PUSHP_50, 0u },			// USART_TX
								{ (uint8_t)PA10, KIN_PULLD,    0u },			// USART_RX
								{ (uint8_t)PA11, KIN_PULLD,    0u },			// GPIO input
								{ (uint8_t)PA12, KIN_PULLD,    0u },			// GPIO input
								{ (uint8_t)PA13, KIN_PULLU,    0u },			// JTAG_TMS
								{ (uint8_t)PA14, KIN_PULLD,    0u },			// JTAG_TCK
								{ (uint8_t)PA15, KIN_PULLU,    0u },			// JTAG_TDI

								{ (uint8_t)PB00, KOU_PUSHP_50, 0u },			// GPIO output	LCD_RS
								{ (uint8_t)PB01, KOU_PUSHP_50, 0u },			// GPIO output	LCD_RST
								{ (uint8_t)PB02, KOU_PUSHP_50, 0u },			// GPIO output	LCD_CS
								{ (uint8_t)PB03, KAF_PUSHP_50, 0u },			// JTAG_TDO
								{ (uint8_t)PB04, KIN_PULLD,    0u },			// GPIO input
								{ (uint8_t)PB05, KIN_PULLD,    0u },			// GPIO input
								{ (uint8_t)PB06, KIN_PULLD,    0u },			// GPIO input
								{ (uint8_t)PB07, KIN_PULLD,    0u },			// GPIO input
								{ (uint8_t)PB08, KIN_PULLD,    0u },			// GPIO input
								{ (uint8_t)PB09, KIN_PULLD,    0u },			// GPIO input
								{ (uint8_t)PB10, KIN_PULLD,    0u },			// GPIO input
								{ (uint8_t)PB11, KIN_PULLD,    0u },			// GPIO input
								{ (uint8_t)PB12, KOU_PUSHP_50, 0u },			// SDCARD_CS	SDCARD_CS
								{ (uint8_t)PB13, KAF_PUSHP_50, 0u },			// SPI1_CLK		SDCARD_SCK
								{ (uint8_t)PB14, KIN_PULLD,    0u },			// SPI1_MISO	SDCARD_MISO
								{ (uint8_t)PB15, KAF_PUSHP_50, 0u },			// SPI1_MOSI	SDCARD_MOSI

								{ (uint8_t)PC13, KOU_PUSHP_02, 1u },			// GPIO output	LED_R
								{ (uint8_t)PC14, KIN_FLOAT,    0u },			// 32K quartz
								{ (uint8_t)PC15, KIN_FLOAT,    0u },			// 32K quartz
							};

#define	KNBCNF		(sizeof(aGPIO_Cnf) / sizeof(gpio_t))

	RCU->APB2EN |= RCU_APB2EN_PAEN;				// Turn on the GPIOA
	RCU->APB2EN |= RCU_APB2EN_PBEN;				// Turn on the GPIOB
	RCU->APB2EN |= RCU_APB2EN_PCEN;				// Turn on the GPIOC

	for (i = 0u; i < (uint8_t)KNBCNF; i++) {

// Port A

		if (										 (aGPIO_Cnf[i].oPort <= (uint8_t)PA07)) { local_PortConfigure(aGPIO_Cnf[i].oConfiguration, (aGPIO_Cnf[i].oPort - (uint8_t)PA00), (aGPIO_Cnf[i].oPort - (uint8_t)PA00), aGPIO_Cnf[i].oOutputQuite, &GPIOA->CTL0, &GPIOA->OCTL); }
		if ((aGPIO_Cnf[i].oPort >= (uint8_t)PA08) && (aGPIO_Cnf[i].oPort <= (uint8_t)PA15)) { local_PortConfigure(aGPIO_Cnf[i].oConfiguration, (aGPIO_Cnf[i].oPort - (uint8_t)PA08), (aGPIO_Cnf[i].oPort - (uint8_t)PA00), aGPIO_Cnf[i].oOutputQuite, &GPIOA->CTL1, &GPIOA->OCTL); }

// Port B

		if ((aGPIO_Cnf[i].oPort >= (uint8_t)PB00) && (aGPIO_Cnf[i].oPort <= (uint8_t)PB07)) { local_PortConfigure(aGPIO_Cnf[i].oConfiguration, (aGPIO_Cnf[i].oPort - (uint8_t)PB00), (aGPIO_Cnf[i].oPort - (uint8_t)PB00), aGPIO_Cnf[i].oOutputQuite, &GPIOB->CTL0, &GPIOB->OCTL); }
		if ((aGPIO_Cnf[i].oPort >= (uint8_t)PB08) && (aGPIO_Cnf[i].oPort <= (uint8_t)PB15)) { local_PortConfigure(aGPIO_Cnf[i].oConfiguration, (aGPIO_Cnf[i].oPort - (uint8_t)PB08), (aGPIO_Cnf[i].oPort - (uint8_t)PB00), aGPIO_Cnf[i].oOutputQuite, &GPIOB->CTL1, &GPIOB->OCTL); }

// Port C

		if ((aGPIO_Cnf[i].oPort >= (uint8_t)PC00) && (aGPIO_Cnf[i].oPort <= (uint8_t)PC07)) { local_PortConfigure(aGPIO_Cnf[i].oConfiguration, (aGPIO_Cnf[i].oPort - (uint8_t)PC00), (aGPIO_Cnf[i].oPort - (uint8_t)PC00), aGPIO_Cnf[i].oOutputQuite, &GPIOC->CTL0, &GPIOC->OCTL); }
		if ((aGPIO_Cnf[i].oPort >= (uint8_t)PC08) && (aGPIO_Cnf[i].oPort <= (uint8_t)PC15)) { local_PortConfigure(aGPIO_Cnf[i].oConfiguration, (aGPIO_Cnf[i].oPort - (uint8_t)PC08), (aGPIO_Cnf[i].oPort - (uint8_t)PC00), aGPIO_Cnf[i].oOutputQuite, &GPIOC->CTL1, &GPIOC->OCTL); }
	}
}

/*
 * \brief local_RCU_Configuration
 *
 * - RCU configuration
 * 		For f(ck in) = 8 / 2 = 4-MHz
 * 		CK_SYS  = 108-MHz -> factor = 108 / 4 = 27 (108-MHz to permit the USB 54-MHz clock !!)
 * 		CK AHB  = 108-MHz
 * 		CK APB1 = 54-MHz
 * 		CK APB2 = 54-MHz
 * 		CK USB  = 54-MHz
 *
 */
static	void	local_RCU_Configuration(void) {

// Remap for clock observation (clockout on PA8)

	AFIO->PCF0 = (0x3u<<6u);

// Main PLL CPU

// For f(ck in) = 8 / 2 = 4-MHz (IRC8M / 2)
// f(PLL) = f(ck in) * PLLMF		PLLMF = 27	---> CK_PLL = 108-MHz (108-MHz to permit the USB 54-MHz clock !!)
//		CK_SYS  = 108-MHz
//		CK AHB  = 108-MHz
//		CK APB1 = 54-MHz
//		CK APB2 = 54-MHz
//		CK USB  = 54-MHz

	KPLL_STATIC_CHECKS(KCFG_PLLMF);

	RCU->CFG0 = ((KPLL_PLLMF(KCFG_PLLMF) >> 4u) * RCU_CFG0_PLLMF_4)			// PLLMF bit 4
			  | (0u * RCU_CFG0_ADCPSC_2)									// ADCPSC
			  | (4u * RCU_CFG0_CKOUT0SEL_0)									// CLOCKOUT = CKSYS
			  | (KCFG_USBFSPSC * RCU_CFG0_USBFSPSC_0)						// 54-MHz = CK_PLL / 2
			  | ((KPLL_PLLMF(KCFG_PLLMF) & 0xFu) * RCU_CFG0_PLLMF_3_0_0)	// PLLMF bits 3-0
			  | (0u * RCU_CFG0_PREDV0_LSB)									// PREDIV0 not used
			  | (0u * RCU_CFG0_PLLSEL)										// PLLSEL = IRC8M / 2
			  | (0u * RCU_CFG0_ADCPSC_1_0_0)								// ADC clock = CK_APB2 / 2
			  | (4u * RCU_CFG0_APB2PSC_0)									// APB2 = CK_AHB / 2 = 54-MHz
			  | (4u * RCU_CFG0_APB1PSC_0)									// APB1 = CK_AHB / 2 = 54-MHz
			  | (0u * RCU_CFG0_AHBPSC_0)									// AHB  = CK_SYS / 1 = 108-MHz
			  | (2u * RCU_CFG0_SCS_0);										// CK_PLL as the CK_SYS source

	RCU->CTL |= (0u * RCU_CTL_PLL2EN)										// PLL2 off
			  | (0u * RCU_CTL_PLL1EN)										// PLL1 off
			  | (1u * RCU_CTL_PLLEN)										// PLL on
			  | (0u * RCU_CTL_CKMEN)										// Clock monitor disable
			  | (0u * RCU_CTL_HXTALBPS)										// HXTAL not bypassed
			  | (0u * RCU_CTL_HXTALEN);										// HXTAL off

	RCU->AHBEN |= RCU_AHBEN_USBFSEN;										// USBFS clock enable

	while ((RCU->CTL & RCU_CTL_PLLSTB) == 0u) { ; }							// Waiting for PLL stable

// Turn on the 40-KHz clock

	RCU->RSTSCK |= RCU_RSTSCK_IRC40KEN;
}

/*
 * \brief local_ECLIC_Configuration
 *
 * - ECLIC configuration
 *
 */
static	void	local_ECLIC_Configuration(void) {
	uint32_t	i;

// Disable the interruptions

	core_clrBitCSR(RV_CSR_MSTATUS, MSTATUS_MIE);
	core_clrBitCSR(RVBB_CSR_MMISC_CTL, (1u<<9u));

// Configure the ECLIC
// Initialise the ECLIC

	core_putCSR(RV_CSR_MTVEC, (uint32_t)linker_stVECTORS | (uint32_t)0x3u);
	core_putCSR(RVBB_CSR_MTVT, (uint32_t)linker_stVECTORS);

	for (i = 0u; i < KNB_INTERRUPTIONS; i++) {
		ECLIC->CLICINT[i].IE = 0u;
		ECLIC->CLICINT[i].IP = 0u;
	}
	ECLIC->MTH = KINT_IMASK_ALL;

// nlbit = 3 (LEVEL3) -> LLL1 1111 (set by default at the start-up)
//
// LLLH HHHH means that the possible interruption level should be:
//
// 000H HHHH	31
// 001H HHHH	63
// 010H HHHH	95
// 011H HHHH	127
// 100H HHHH	159
// 101H HHHH	191
// 110H HHHH	223
// 111H HHHH	255

	ECLIC->CLICCFG = (uint8_t)((ECLIC->CLICCFG & ~ECLIC_CFG_NLBITS_MASK) | ECLIC_GROUP_LEVEL3_PRIO1);
}
