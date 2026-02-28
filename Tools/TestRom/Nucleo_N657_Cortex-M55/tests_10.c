/*
; tests_10.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the TIM4 interruption.
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

#if (defined(TEST_10_S))
#define	KTTIMESAMPLING	((float64_t)(0.5))										// 500-ms
#define KPSCT4			((KFREQUENCY_TIM / (KFREQUENCY_1MHz)) - 1)				// Prescaler for 1'000'000-Hz
#define KARRT4			((uint32_t)((KFREQUENCY_1MHz * KTTIMESAMPLING) - 1))	// Autoreload

// Prototypes

void	local_TIM4_IRQHandler(void);

/*
 * \brief test_10
 *
 * - Test of the TIM4 interruption
 *
 */
void	test_10(void) {

	REG(RCC)->APB1LENR |= RCC_APB1LENR_TIM4EN;
	STRONG_BARRIER;

// Initialise the TIM4 to generate an interruption every 500-ms

	INTERRUPT_VECTOR(TIM4_C0_IRQn, local_TIM4_IRQHandler);
	NVIC_SetPriority(TIM4_C0_IRQn, KINT_LEVEL_KERNEL_TIMERS);
	NVIC_EnableIRQ(TIM4_C0_IRQn);

	REG(TIM4)->CR1 &= ~TIM4_CR1_CEN;
	REG(TIM4)->PSC  = KPSCT4;
	REG(TIM4)->ARR  = KARRT4;
	REG(TIM4)->CNT  = 0;
	REG(TIM4)->DIER = TIM4_DIER_UIE;
	REG(TIM4)->CR1 |= TIM4_CR1_CEN;

// Waiting for the TIM4 interruption

	__asm volatile ("			\n \
	cpsie		i"				   \
	);

	while (true) {
		cmns_wait(100000);
		LED_RED_TOGGLE;
	}
}

/*
 * \brief local_TIM4_IRQHandler
 *
 * - Blink the BLUE Led
 *
 */
void	local_TIM4_IRQHandler(void) {

// Acknowledge the TIM4 interruption

	REG(TIM4)->SR &= ~TIM4_SR_UIF;
	(void)REG(TIM4)->SR;

	LED_BLUE_TOGGLE;
}
#endif
