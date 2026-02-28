/*
; tests_09.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the TIM3 interruption.
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

#if (defined(TEST_09_S))
#define	KTTIMESAMPLING	((float64_t)(0.5))										// 500-ms
#define KPSCT3			((KFREQUENCY_TIM / (KFREQUENCY_1MHz)) - 1)				// Prescaler for 1'000'000-Hz
#define KARRT3			((uint32_t)((KFREQUENCY_1MHz * KTTIMESAMPLING) - 1))	// Autoreload

// Prototypes

void	local_TIM3_IRQHandler(void);

/*
 * \brief test_09
 *
 * - Test of the TIM3 interruption
 *
 */
void	test_09(void) {

	REG(RCC)->APB1LENR |= RCC_APB1LENR_TIM3EN;
	STRONG_BARRIER;

// Initialise the TIM3 to generate an interruption every 500-ms

	INTERRUPT_VECTOR(TIM3_C0_IRQn, local_TIM3_IRQHandler);
	NVIC_SetPriority(TIM3_C0_IRQn, KINT_LEVEL_KERNEL_TIMERS);
	NVIC_EnableIRQ(TIM3_C0_IRQn);

	REG(TIM3)->CR1 &= ~TIM3_CR1_CEN;
	REG(TIM3)->PSC  = KPSCT3;
	REG(TIM3)->ARR  = KARRT3;
	REG(TIM3)->CNT  = 0;
	REG(TIM3)->DIER = TIM3_DIER_UIE;
	REG(TIM3)->CR1 |= TIM3_CR1_CEN;

// Waiting for the TIM3 interruption

	__asm volatile ("			\n \
	cpsie		i"				   \
	);

	while (true) {
		cmns_wait(100000);
		LED_RED_TOGGLE;
	}
}

/*
 * \brief local_TIM3_IRQHandler
 *
 * - Blink the BLUE Led
 *
 */
void	local_TIM3_IRQHandler(void) {

// Acknowledge the TIM3 interruption

	REG(TIM3)->SR &= ~TIM3_SR_UIF;
	(void)REG(TIM3)->SR;

	LED_BLUE_TOGGLE;
}
#endif
