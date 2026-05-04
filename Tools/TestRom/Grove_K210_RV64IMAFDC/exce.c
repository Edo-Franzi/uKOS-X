/*
; exce.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Exceptions for the K210_AI_GROVE module.
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

/*
 * \brief exce_init
 *
 *
 * \note This function does not return a value (None).
 *
 */
void	exce_init(void) {
	uint64_t	i;
	uint32_t	core;

	core = GET_RUNNING_CORE;

// Disable the interruptions

	for (i = 0; i < PLIC_NUM_SOURCES; i++) {
		plic->source_priorities.priority[i] = 0;
	}

// Set the threshold to KINT_IMASK_ALL

	plic->targets.target[core].priority_threshold = KINT_IMASK_ALL;

// A successful claim will also atomically clear the corresponding
// pending bit on the interrupt source. A target can perform a claim
// at any time, even if the EIP is not set.

	i = 0;
	while ((plic->targets.target[core].claim_complete > 0) && (i < 100)) {

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

	if (core == 0) {

// Set priorities to zero

		for (i = 0; i < PLIC_NUM_SOURCES; i++) {
			plic->source_priorities.priority[i] = 0;
		}
	}
}
