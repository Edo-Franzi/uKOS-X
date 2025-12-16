/*
; coores.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Core > 0 tests.
;
;   (c) 2025-20xx, Edo. Franzi
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

STRG_LOC_CONST(aStrApplication[]) =	"cores        Minimal tests for the cores > 0.          (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "cores\n"
									"=====\n\n"

									"This code provides some minimal core > 0 tests.\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

MODULE(
	Cores,							// Module name (the first letter has to be upper case)
	KID_FAM_STARTUPS,				// Family (defined in the module.h)
	KNUM_CMNS,						// Module identifier (defined in the module.h)
	NULL,							// Address of the initialisation code (early pre-init)
	NULL,							// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,							// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Runtime specific
// ================

#define	KTTIMESAMPLING	200000000u					// 200-ms -> 200'000'000-ns
#define	KSZVECTOR		(2u + 8u)					// Size of the vector (size, core, ... vector)

volatile	uint8_t		vVector[KSZVECTOR];
			spinlock_t	vLockVector = SPIN_LOCK_INIT;

// Prototypes

extern	void	cmns_wait(uint32_t us);
static	void	local_TIM2_2_IRQHandler(uint32_t core, uint64_t parameter);

/*
 * \brief cores_init
 *
 * \param[in]	core	Core number > 0
 *
 * \note This function does not return a value (None).
 *
 */
int32_t	cores_init(uint32_t core) {
	uint8_t		i;
	float64_t	step;
	uint32_t	current;

	INTERRUPTION_SET;
	INTERRUPTION_ON_HARD;

// Prepare for the timer 2B interruption

	sysctl->clk_en_peri.timer2_clk_en = 1u;

	EXT_INTERRUPT_VECTOR(EINT_TIMER2B_INTERRUPT, local_TIM2_2_IRQHandler);

	plic->source_priorities.priority[EINT_TIMER2B_INTERRUPT] = KINT_LEVEL_ALL;
	current = plic->target_enables.target[core].enable[EINT_TIMER2B_INTERRUPT / 32u];
	current |= (uint32_t)(1u<<(EINT_TIMER2B_INTERRUPT % 32u));
	plic->target_enables.target[core].enable[EINT_TIMER2B_INTERRUPT / 32] = current;

// Initialise the TIM2_2 to generate interruptions every 200-ms

	step = 1e9 / KFREQUENCY_TIM;
	timer2->channel[2].load_count = (uint32_t)(KTTIMESAMPLING / step);
	timer2->channel[2].control &= ~TIMER_CR_INTERRUPT_MASK;
	timer2->channel[2].control |= (TIMER_CR_USER_MODE | TIMER_CR_ENABLE);

// For the moment, just performs a simple task
// - increment a 8 element vector every 1-ms

	vVector[0] = KSZVECTOR;
	vVector[1] = (uint8_t)core;
	for (i = 2; i < KSZVECTOR; i++) { vVector[i] = i - 2; }

	while (true) {

		SPIN_LOCK(vLockVector);
		for (i = 2; i < KSZVECTOR; i++) {
			vVector[i]++;
		}
		SPIN_UNLOCK(vLockVector);

		cmns_wait(1000u);
	}
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_TIM2_2_IRQHandler
 *
 * - Blink the Red 2 Led
 *
 */
static	void	local_TIM2_2_IRQHandler(uint32_t core, uint64_t parameter) {

// Acknowledge the TIM2_2 interruption
// Acknowledge the PLIC claim complete

	if ((timer2->channel[2].intr_stat & 0x1) != 0u) {
		timer2->channel[2].eoi;
		LED_1_TOGGLE;
	}
	plic->targets.target[core].claim_complete = (uint32_t)parameter;
}
