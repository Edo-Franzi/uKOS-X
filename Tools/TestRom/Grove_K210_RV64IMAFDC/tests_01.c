/*
; tests_01.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the TIM0_0 interruption.
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

#if (defined(TEST_01_S))
#define	KTTIMESAMPLING	100000000					// 100-ms -> 100'000'000-ns

// Prototypes

static	void	local_TIM0_0_IRQHandler(uint32_t core, uint64_t parameter);

/*
 * \brief test_01
 *
 * - Test of the TIM0_0 interruption
 *
 */
void	test_01(void) {
	float64_t	step;
	uint32_t	core, current;

	INTERRUPTION_SET;
	INTERRUPTION_ON_HARD;

// Turn on the TIM0

	sysctl->clk_en_peri.timer0_clk_en = 1;

// Set the priority
// Get current enable bit array by IRQ number
// Set enable bit in enable bit array
// Write back the enable bit array

	core = GET_RUNNING_CORE;
	EXT_INTERRUPT_VECTOR(EINT_TIMER0A_INTERRUPT, local_TIM0_0_IRQHandler);

	plic->source_priorities.priority[EINT_TIMER0A_INTERRUPT] = KINT_LEVEL_ALL;
	current = plic->target_enables.target[core].enable[EINT_TIMER0A_INTERRUPT / 32];
	current |= (uint32_t)(1u<<(EINT_TIMER0A_INTERRUPT % 32));
	plic->target_enables.target[core].enable[EINT_TIMER0A_INTERRUPT / 32] = current;

// Initialise the TIM0_0 to generate interruptions every 100-ms

	step = 1e9 / KFREQUENCY_TIM;
	timer0->channel[0].load_count = (uint32_t)(KTTIMESAMPLING / step);
	timer0->channel[0].control &= ~TIMER_CR_INTERRUPT_MASK;
	timer0->channel[0].control |= (TIMER_CR_USER_MODE | TIMER_CR_ENABLE);

// Waiting for the TIM0_0 end of interval

	while (true) {
		cmns_wait(1000000);
		LED_GREEN_1_TOGGLE;
	}
}

/*
 * \brief local_TIM0_0_IRQHandler
 *
 * - Blink the Red 1 Led
 *
 */
static	void	local_TIM0_0_IRQHandler(uint32_t core, uint64_t parameter) {

// Acknowledge the TIM0_0 interruption
// Acknowledge the PLIC claim complete

	if ((timer0->channel[0].intr_stat & 0x1) != 0) {
		timer0->channel[0].eoi;
		LED_RED_1_TOGGLE;
	}
	plic->targets.target[core].claim_complete = (uint32_t)parameter;
}
#endif
