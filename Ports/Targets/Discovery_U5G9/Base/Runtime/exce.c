/*
; exce.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Exceptions for the Nucleo_U5A5 module.
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

STRG_LOC_CONST(aStrApplication[]) =	"exce         Exception management.                     (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Exce\n"
									"====\n\n"

									"This code manages the spurious exceptions.\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Exce,							// Module name (the first letter has to be upper case)
	KID_FAM_STARTUPS,				// Family (defined in the module.h)
	KNUM_EXCE,						// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Runtime specific
// ================

void	(*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
void	(*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);

// Prototypes

extern	void	cmns_send(serialManager_t serialManager, const char_t *ascii);
extern	void	cmns_wait(uint32_t us);
static	void	local_setLEDs(uint8_t ledNb);
static	void	local_clrLEDs(uint8_t ledNb);
static	void	local_cpyLEDs(uint8_t value);

/*
 * \brief exce_init
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
void	exce_init(void) {
	uint8_t		nbExceptions, nbInterruptions;

	for (nbExceptions = 0u; nbExceptions < KNB_EXCEPTIONS; nbExceptions++) {
		vExce_indExcVectors[GET_RUNNING_CORE][nbExceptions] = nullptr;
	}

	for (nbInterruptions = 0u; nbInterruptions < KNB_INTERRUPTIONS; nbInterruptions++) {
		vExce_indIntVectors[GET_RUNNING_CORE][nbInterruptions] = nullptr;
	}

	core_setBASEPRI((uint32_t)KINT_LEVEL_PERIPHERALS<<(uint32_t)KNVIC_PRIORITY_SHIFT);
	REG(SCB)->AIRCR = SCB_AIRCR_VECTKEY_MASK | 0x0300u;

	REG(SCB)->SHCSR |= SCB_SHCSR_MEMFAULTENA | SCB_SHCSR_BUSFAULTENA | SCB_SHCSR_USGFAULTENA | SCB_SHCSR_SECUREFAULTENA;
}

// Model callbacks
// ---------------

/*
 * \brief cb_signal
 *
 * - Signal an exception or an interruption
 *   - Exception
 *   - Interruption
 *
 */
static void __attribute__ ((noreturn)) cb_signal(uint8_t mode) {

	switch (mode) {
		default:
		case KEXCEPTION: {
			local_cpyLEDs(0xFFu);
			while (true) {
				cmns_wait(1000000u);
				local_setLEDs(0u);
				cmns_wait(1000000u);
				local_clrLEDs(0u);
			}
		}
		case KINTERRUPTION: {
			local_cpyLEDs(0xFFu);
			while (true) {
				cmns_wait(1000000u);
				local_setLEDs(1u);
				cmns_wait(1000000u);
				local_clrLEDs(1u);
			}
		}
	}
}

// Local routines
// ==============

/*
 * \brief local_setLEDs
 *
 * - Turn on a LED
 *
 */
static	void	local_setLEDs(uint8_t ledNb) {

	switch (ledNb) {
		case 0: { REG(GPIOE)->ODR |= (1u<<BLED_0); break; }
		case 1: { REG(GPIOE)->ODR |= (1u<<BLED_1); break; }
		default: {

// Make MISRA happy :-)

			break;
		}
	}
}

/*
 * \brief local_clrLEDs
 *
 * - Turn off a LED
 *
 */
static	void	local_clrLEDs(uint8_t ledNb) {

	switch (ledNb) {
		case 0: { REG(GPIOE)->ODR &= ~(1u<<BLED_0); break; }
		case 1: { REG(GPIOE)->ODR &= ~(1u<<BLED_1); break; }
		default: {

// Make MISRA happy :-)

			break;
		}
	}
}

/*
 * \brief local_cpyLEDs
 *
 * - Write on the LEDs
 *
 */
static	void	local_cpyLEDs(uint8_t value) {
	uint8_t		led, mask;

	mask = 0x01u;
	for (led = 0u; led < 2u; led++) {
		(value & mask) ? (local_setLEDs(led)) : (local_clrLEDs(led));
		mask = (uint8_t)(mask<<1);
	}
}

#include	"model_coreDump_tracing.c_inc"
#include	"model_coreDump_generic.c_inc"
#include	"model_coreDump_core.c_inc"
#include	"model_coredump_soc.c_inc"
