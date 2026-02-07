/*
; exce.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Exceptions for the MAiXDUiNO_K210 module.
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

		void	(*vExce_intIntVectors[KNB_CORES][KNB_INT_INTERRUPTIONS])(uint32_t core, uint64_t parameter);
		void	(*vExce_intExcVectors[KNB_CORES][KNB_INT_EXCEPTIONS])(uint32_t core, uint64_t parameter);
		void	(*vExce_extIntVectors[KNB_CORES][KNB_EXT_INTERRUPTIONS])(uint32_t core, uint64_t parameter);
		void	(*vMsgs_process[KNB_CORES])(uint32_t core, uint64_t message);
		bool	vExce_isException[KNB_CORES] = MCSET(false);

// Prototypes

extern	void	first_handle_trap(void);
extern	void	first_handle_MachineExternal(uint32_t core, uint64_t parameter);
extern	void	first_handle_EnvironmentalCallM(uint32_t core, uint64_t message);
extern	void	cmns_send(serialManager_t serialManager, const char_t *ascii);
extern	void	cmns_wait(uint32_t us);
static	void	coreDump_displayInt_Interruption(uint32_t core, uint64_t number);
static	void	coreDump_displayInt_Exceptions(uint32_t core, uint64_t number);
static	void	coreDump_displayExt_Interruption(uint32_t core, uint64_t number);
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
	uint64_t	i;
	uint32_t	core;
	uint32_t	nbInt_Exceptions, nbInt_Interruptions, nbExt_Interruptions;

	core = GET_RUNNING_CORE;

// mcause bit 63 == 0: Internal exception

	for (nbInt_Exceptions = 0u; nbInt_Exceptions < KNB_INT_INTERRUPTIONS; nbInt_Exceptions++) {
		INT_EXCEPTION_VECTOR(nbInt_Exceptions, (void (*)(uint32_t core, uint64_t parameter))coreDump_displayInt_Exceptions);
	}

// mcause bit 63 == 1: Internal interruption

	for (nbInt_Interruptions = 0u; nbInt_Interruptions < KNB_INT_INTERRUPTIONS; nbInt_Interruptions++) {
		INT_INTERRUPT_VECTOR(nbInt_Interruptions, (void (*)(uint32_t core, uint64_t parameter))coreDump_displayInt_Interruption);
	}

// mcause bit 63 == 1: Internal interruption
// Machine External Interrupt (PLIC)

	for (nbExt_Interruptions = 0u; nbExt_Interruptions < KNB_EXT_INTERRUPTIONS; nbExt_Interruptions++) {
		EXT_INTERRUPT_VECTOR(nbExt_Interruptions, (void (*)(uint32_t core, uint64_t parameter))coreDump_displayExt_Interruption);
	}

// Disable the interruptions

	for (i = (uint64_t)0u; i < (((uint64_t)PLIC_NUM_SOURCES + (uint64_t)32u) / (uint64_t)32u); i++) {
		plic->target_enables.target[core].enable[i] = 0u;
	}

// Set the threshold to KINT_IMASK_ALL

	plic->targets.target[core].priority_threshold = KINT_IMASK_ALL;

// A successful claim will also atomically clear the corresponding
// pending bit on the interrupt source. A target can perform a claim
// at any time, even if the EIP is not set.

	i = 0;
	while ((plic->targets.target[core].claim_complete > 0u) && (i < 100u)) {

// This loop will clear pending bit on the interrupt source

		i++;
	}

// Enable machine external interrupts

	INT_INTERRUPT_VECTOR(IINT_MACHINE_EXTERNAL, first_handle_MachineExternal);
	INT_EXCEPTION_VECTOR(IEXC_ENVIRONMENTAL_CALL_M_MODE, first_handle_EnvironmentalCallM);

// Disable the interruptions

	core_clrBitCSR(RV_CSR_MIE, MIP_MEIP);
	core_clrBitCSR(RV_CSR_MSTATUS, MSTATUS_MIE);

	core_putCSR(RV_CSR_MTVEC, (uintptr_t)&first_handle_trap);

// The following code has to be initialised
// only by the core 0.

	if (core == 0u) {

// Set priorities to zero

		for (i = (uint64_t)0u; i < (uint64_t)PLIC_NUM_SOURCES; i++) {
			plic->source_priorities.priority[i] = 0u;
		}
	}
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
		case 0 : { gpiohs->output_val.u32[0] &= (uint32_t)~(1u<<BLED_0); break; }
		case 1 : { gpiohs->output_val.u32[0] &= (uint32_t)~(1u<<BLED_1); break; }
		case 2 : { gpiohs->output_val.u32[0] &= (uint32_t)~(1u<<BLED_2); break; }
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
		case 0u: { gpiohs->output_val.u32[0] |= (1u<<BLED_0); break; }
		case 1u: { gpiohs->output_val.u32[0] |= (1u<<BLED_1); break; }
		case 2u: { gpiohs->output_val.u32[0] |= (1u<<BLED_2); break; }
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
		mask = (uint8_t)(mask<<1u);
	}
}

#include	"model_coreDump_tracing.c_inc"
#include	"model_coreDump_generic.c_inc"
#include	"model_coreDump_core.c_inc"
#include	"model_coredump_soc.c_inc"
