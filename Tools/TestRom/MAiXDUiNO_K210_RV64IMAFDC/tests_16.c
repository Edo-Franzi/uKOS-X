/*
; tests_16.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the TIM2_0 TIM2_2 interruptions.
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

#if (defined(TEST_16_S))
#define	KTTIMESAMPLING_0	100000000				// 100-ms -> 100'000'000-ns
#define	KTTIMESAMPLING_2	200000000				// 200-ms -> 200'000'000-ns

// Prototypes

static	void	local_TIM2_0_IRQHandler(uint32_t core, uint64_t parameter);
static	void	local_TIM2_2_IRQHandler(uint32_t core, uint64_t parameter);

/*
 * \brief test_16
 *
 * - Test of the TIM2_0 TIM2_2 interruptions
 *
 */
void	test_16(void) {
	float64_t	step;
	uint32_t	core, current;

	INTERRUPTION_SET;
	INTERRUPTION_ON_HARD;

// Turn on the TIM2

	sysctl->clk_en_peri.timer2_clk_en = 1;

// Set the priority
// Get current enable bit array by IRQ number
// Set enable bit in enable bit array
// Write back the enable bit array

	core = GET_RUNNING_CORE;
	EXT_INTERRUPT_VECTOR(EINT_TIMER2A_INTERRUPT, local_TIM2_0_IRQHandler);
	EXT_INTERRUPT_VECTOR(EINT_TIMER2B_INTERRUPT, local_TIM2_2_IRQHandler);

	plic->source_priorities.priority[EINT_TIMER2A_INTERRUPT] = KINT_LEVEL_ALL;
	current = plic->target_enables.target[core].enable[EINT_TIMER2A_INTERRUPT / 32];
	current |= (uint32_t)(1u<<(EINT_TIMER2A_INTERRUPT % 32));
	plic->target_enables.target[core].enable[EINT_TIMER2A_INTERRUPT / 32] = current;

	plic->source_priorities.priority[EINT_TIMER2B_INTERRUPT] = KINT_LEVEL_ALL;
	current = plic->target_enables.target[core].enable[EINT_TIMER2B_INTERRUPT / 32];
	current |= (uint32_t)(1u<<(EINT_TIMER2B_INTERRUPT % 32));
	plic->target_enables.target[core].enable[EINT_TIMER2B_INTERRUPT / 32] = current;

// Initialise the TIM2_0 to generate interruptions every 100-ms

	step = 1e9 / KFREQUENCY_TIM;
	timer2->channel[0].load_count = (uint32_t)(KTTIMESAMPLING_0 / step);
	timer2->channel[0].control &= ~TIMER_CR_INTERRUPT_MASK;
	timer2->channel[0].control |= (TIMER_CR_USER_MODE | TIMER_CR_ENABLE);

// Initialise the TIM2_2 to generate interruptions every 200-ms

	step = 1e9 / KFREQUENCY_TIM;
	timer2->channel[2].load_count = (uint32_t)(KTTIMESAMPLING_2 / step);
	timer2->channel[2].control &= ~TIMER_CR_INTERRUPT_MASK;
	timer2->channel[2].control |= (TIMER_CR_USER_MODE | TIMER_CR_ENABLE);

// Waiting for the TIM2_0 & TIM2_2 interruptions

	while (true) {
		cmns_wait(1000000);
		LED_GREEN_TOGGLE;
	}
}

/*
 * \brief local_TIM2_0_IRQHandler
 *
 * - Blink the Red 1 Led
 *
 */
static	void	local_TIM2_0_IRQHandler(uint32_t core, uint64_t parameter) {

// Acknowledge the TIM2_0 interruption
// Acknowledge the PLIC claim complete

	if ((timer2->channel[0].intr_stat & 0x1) != 0) {
		timer2->channel[0].eoi;
		LED_RED_TOGGLE;
	}
	plic->targets.target[core].claim_complete = (uint32_t)parameter;
}

/*
 * \brief local_TIM2_2_IRQHandler
 *
 * - Blink the Red 2 Led
 *
 */
static	void	local_TIM2_2_IRQHandler(uint32_t core, uint64_t parameter) {

// Acknowledge the TIM2_2 interruption
// Acknowledge the PLIC claim complete

	if ((timer2->channel[2].intr_stat & 0x1) != 0) {
		timer2->channel[2].eoi;
		LED_BLUE_TOGGLE;
	}
	plic->targets.target[core].claim_complete = (uint32_t)parameter;
}
#endif
