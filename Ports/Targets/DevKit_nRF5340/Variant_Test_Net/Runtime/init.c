/*
; init.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Low level init for the uKOS-X nRF5340_SDK module.
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

STRG_LOC_CONST(aStrApplication[]) =	"init         First hardware initializations.           (c) EFr-2026";
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

typedef	struct	gpio	gpio_t;

struct	gpio {
			uint8_t		oPin;				// Pin number (32 ... > 0 of P1)
			uint32_t	oPinCNFValue;		// Pin configuration value
			uint8_t		oOutputQuite;		// Output value in a quite state
		};

// Prototypes

static	void	local_StackLimit_Configuration(void);
extern	void	cmns_wait(uint32_t us);
static	void	local_SECU_Configuration(void);
static	void	local_GPIO_Configuration(void);
static	void	local_MPU_Configuration(void);
static	void	local_CLOCK_Configuration(void);

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

	local_StackLimit_Configuration();
	local_SECU_Configuration();
	local_CLOCK_Configuration();
	local_GPIO_Configuration();
	local_MPU_Configuration();
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
 * \brief local_SECU_Configuration
 *
 * - Flash, RAM, Periphs in a non secure mode
 *
 */
static	void	local_SECU_Configuration(void) {

	REG(CTRLAP)->APPROTECT_DISABLE = 0x50FA50FAu;
}

/*
 * \brief local_CLOCK_Configuration
 *
 * - Setting of the clocks
 *	 - HFCLK @ 64-MHz
 *
 */
static	void	local_CLOCK_Configuration(void) {

	REG(CLOCK)->HFCLKCTRL = 0u;
}

/*
 * \brief local_GPIO_Configuration
 *
 * - GPIO configuration
 *
 */
static	void	local_GPIO_Configuration(void) {
					uint8_t		i, pin;
					uint32_t	*pCnf;
	static	const	gpio_t		aGPIO_Cnf[] = {
										{ 8u,  (KPIN_NETCPU | KSENS_DISABLE | KDRIVE_S0S1 | KPULL_UP	  | KINPUT_CONNECT	  | KDIR_INPUT),    0u },	// P0.8 Button 3
										{ 9u,  (KPIN_NETCPU | KSENS_DISABLE | KDRIVE_S0S1 | KPULL_UP	  | KINPUT_CONNECT	  | KDIR_INPUT),    0u },	// P0.9 Button 4

										{ 19u, (KPIN_NETCPU | KSENS_DISABLE | KDRIVE_S0S1 | KPULL_DISABLE | KINPUT_DISCONNECT | KDIR_OUTPUT),   0u },	// P0.19 USART_0 /RTS
										{ 20u, (KPIN_NETCPU | KSENS_DISABLE | KDRIVE_S0S1 | KPULL_DISABLE | KINPUT_DISCONNECT | KDIR_OUTPUT),   0u },	// P0.20 USART_0 TXD
										{ 21u, (KPIN_NETCPU | KSENS_DISABLE | KDRIVE_S0S1 | KPULL_DOWN	  | KINPUT_CONNECT	  | KDIR_INPUT),	0u },	// P0.21 USART_0 /CTS
										{ 22u, (KPIN_NETCPU | KSENS_DISABLE | KDRIVE_S0S1 | KPULL_UP	  | KINPUT_DISCONNECT | KDIR_INPUT),    0u },	// P0.22 USART_0 RXD

										{ 30u, (KPIN_NETCPU | KSENS_DISABLE | KDRIVE_S0S1 | KPULL_DISABLE | KINPUT_DISCONNECT | KDIR_OUTPUT),   1u },	// P0.30 Led 3
										{ 31u, (KPIN_NETCPU | KSENS_DISABLE | KDRIVE_S0S1 | KPULL_DISABLE | KINPUT_DISCONNECT | KDIR_OUTPUT),   1u },	// P0.31 Led 4
									};

#define	KNBCNF		(sizeof(aGPIO_Cnf) / sizeof(gpio_t))

	for (i = 0u; i < (uint8_t)KNBCNF; i++) {
		pin = aGPIO_Cnf[i].oPin;
		if (pin < 32u) {

// P0.0 .. P0.31

			pCnf  = (uint32_t *)((uintptr_t)&REG(P0)->PIN_CNF[0] + (pin * 4u));
			*pCnf = aGPIO_Cnf[i].oPinCNFValue;

			(aGPIO_Cnf[i].oOutputQuite == 0u) ? (REG(P0)->OUTCLR = (1u<<pin)) : (REG(P0)->OUTSET = (1u<<pin));
		}
		else {

// P1.0 .. P1.31

			pin = (uint8_t)(pin - 32u);

			pCnf  = (uint32_t *)((uintptr_t)&REG(P1)->PIN_CNF[0] + (pin * 4u));
			*pCnf = aGPIO_Cnf[i].oPinCNFValue;

			(aGPIO_Cnf[i].oOutputQuite == 0u) ? (REG(P1)->OUTCLR = (1u<<pin)) : (REG(P1)->OUTSET = (1u<<pin));
		}
	}

// RXD & TXD pin attribution for the uarte 0

	REG(UARTE0)->PSEL_TXD = 20u;
	REG(UARTE0)->PSEL_RXD = 22u;
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
	SET_MPU8_REGION(0u,	ST_FLASH_INT_0,			EN_FLASH_INT_0,			KMPU_EXECUTABLE,		KMPU_R_ALL,  0u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(1u,	ST_RAM_INT_0_OS,		EN_RAM_INT_0_OS,		KMPU_EXECUTABLE,		KMPU_RW_PRI, 1u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(2u,	ST_RAM_INT_0,			EN_RAM_INT_0,			KMPU_EXECUTABLE,		KMPU_RW_ALL, 1u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(3u,	ST_RAM_INT_1,			EN_RAM_INT_1,			KMPU_EXECUTABLE,		KMPU_RW_ALL, 1u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(4u,	ST_RAM_INT_1_SHARED,	EN_RAM_INT_1_SHARED,	KMPU_EXECUTABLE,		KMPU_RW_ALL, 2u, KMPU_NOT_SHAREABLE);
	SET_MPU8_REGION(5u,	ST_PERIPH_SOC,			EN_PERIPH_SOC,			KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI, 3u, KMPU_NOT_SHAREABLE);
	SET_MPU8_REGION(6u,	ST_PERIPH_CORE,			EN_PERIPH_CORE,			KMPU_NOT_EXECUTABLE,	KMPU_RW_PRI, 3u, KMPU_NOT_SHAREABLE);

	#else
	SET_MPU8_REGION(0u,	ST_FLASH_INT_0,			EN_FLASH_INT_0,			KMPU_EXECUTABLE,		KMPU_R_ALL,  0u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(1u,	ST_RAM_INT_0,			EN_RAM_INT_0,			KMPU_EXECUTABLE,		KMPU_RW_ALL, 1u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(2u,	ST_RAM_INT_1,			EN_RAM_INT_1,			KMPU_EXECUTABLE,		KMPU_RW_ALL, 1u, KMPU_INNER_SHAREABLE);
	SET_MPU8_REGION(3u,	ST_RAM_INT_1_SHARED,	EN_RAM_INT_1_SHARED,	KMPU_EXECUTABLE,		KMPU_RW_ALL, 2u, KMPU_NOT_SHAREABLE);
	#endif
}
