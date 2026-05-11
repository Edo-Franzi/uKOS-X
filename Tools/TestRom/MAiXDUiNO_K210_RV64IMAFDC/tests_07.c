/*
; tests_07.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the preemption interruption.
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

#if (defined(TEST_07_S))
#define	TEST_PREEMPTION		gpiohs->rise_ie.u32[0]   |=(1u<<BKERN_PREEMPTION); \
							gpiohs->input_val.u32[0] |= (1u<<BKERN_PREEMPTION);

static	uint32_t	vCptIn = 0, vCptOut = 0;

// Prototypes

static	void	local_PREEMPTION_IRQHandler(uint32_t core, uint64_t parameter);

/*
 * \brief test_07
 *
 * - Test of the preemption interruption
 *
 */
void	test_07(void) {
	uint32_t	core, current;

	INTERRUPTION_SET;
	INTERRUPTION_ON_HARD;

// Set the priority
// Get current enable bit array by IRQ number
// Set enable bit in enable bit array
// Write back the enable bit array

	core = GET_RUNNING_CORE;
	EXT_INTERRUPT_VECTOR(KKERN_PREEMPTION, local_PREEMPTION_IRQHandler);

	plic->source_priorities.priority[KKERN_PREEMPTION] = KINT_LEVEL_KERNEL_PREEMPTION;
	current = plic->target_enables.target[core].enable[KKERN_PREEMPTION / 32];
	current |= (uint32_t)(1u<<(KKERN_PREEMPTION % 32));
	plic->target_enables.target[core].enable[KKERN_PREEMPTION / 32] = current;

	gpiohs->input_val.u32[0] &= (uint32_t)~(1u<<BKERN_PREEMPTION);
	gpiohs->input_en.u32[0]  |=			   (1u<<BKERN_PREEMPTION);

// Generate continuous preemptions

	while (true) {
		cmns_wait(1000000);

		vCptIn++;
		TEST_PREEMPTION;

		LED_RED_TOGGLE;
	}
}

/*
 * \brief local_PREEMPTION_IRQHandler
 *
 * - Blink the Red 1 Led
 *
 */
static	void	local_PREEMPTION_IRQHandler(uint32_t core, uint64_t parameter) {

// Acknowledge the GPIOHS interruption
// Acknowledge the PLIC claim complete

	gpiohs->rise_ie.u32[0] &= (uint32_t)~(1u<<BKERN_PREEMPTION);
	plic->targets.target[core].claim_complete = (uint32_t)parameter;

	vCptOut++;

// Stop if the 2 counters are not the same

	if (vCptIn != vCptOut) {
		LED_BLUE_ON;
		while (true) { ; }
	}

	LED_BLUE_TOGGLE;
}
#endif
