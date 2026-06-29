/*
; tests_11.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the TIM5 interruption.
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

#if (defined(TEST_11_S))
#define BLINK_PAUSE 100000

#define	KTTIMESAMPLING	((float64_t)(0.5))										// 500-ms
#define KPSCT5			((KFREQUENCY_TIM / (KFREQUENCY_1MHz)) - 1)				// Prescaler for 1'000'000-Hz
#define KARRT5			((uint32_t)((KFREQUENCY_1MHz * KTTIMESAMPLING) - 1))	// Autoreload

// Prototypes

void	local_TIM5_IRQHandler(void);

/*
 * \brief test_11
 *
 * - Test of the TIM5 interruption
 *
 */
void	test_11(void) {

	REG(RCC)->APB1LENR |= RCC_APB1LENR_TIM5EN;
    (void)REG(RCC)->APB1LENR;
	STRONG_BARRIER;

// Initialise the TIM5 to generate an interruption every 500-ms

	REG(TIM5)->CR1 &= ~TIM5_CR1_CEN;
	REG(TIM5)->PSC  = KPSCT5;
	REG(TIM5)->ARR  = KARRT5;
	REG(TIM5)->CNT  = 0;
	REG(TIM5)->DIER = TIM5_DIER_UIE;
	REG(TIM5)->CR1 |= TIM5_CR1_CEN;

	INTERRUPT_VECTOR(TIM5_C0_IRQn, local_TIM5_IRQHandler);
	NVIC_ClearPendingIRQ(TIM5_C0_IRQn);
	NVIC_SetPriority(TIM5_C0_IRQn, KINT_LEVEL_KERNEL_TIMERS);
	NVIC_EnableIRQ(TIM5_C0_IRQn);

// Waiting for the TIM5 interruption

	INTERRUPTION_ON_HARD;

	while (true) {
		cmns_wait(BLINK_PAUSE);
		LED_RED_TOGGLE;
	}
}

/*
 * \brief local_TIM5_IRQHandler
 *
 * - Blink the BLUE Led
 *
 */
void	local_TIM5_IRQHandler(void) {

// Acknowledge the TIM5 interruption
// Read-back to ensure the write completes before the handler returns;
// without this, on Cortex-M55 the NVIC can re-enter the handler immediately.

	REG(TIM5)->SR = ~TIM5_SR_UIF;
	(void)REG(TIM5)->SR;

	LED_GREEN_TOGGLE;
}
#endif
