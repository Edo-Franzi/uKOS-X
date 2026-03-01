/*
; tests_08.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the TIM2 interruption.
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

#if (defined(TEST_08_S))

#define	KTTIMESAMPLING	((float64_t)(0.5))										// 500-ms
#define KPSCT2			((KFREQUENCY_TIM / (KFREQUENCY_1MHz)) - 1)				// Prescaler for 1'000'000-Hz
#define KARRT2			((uint32_t)((KFREQUENCY_1MHz * KTTIMESAMPLING) - 1))	// Autoreload

// Prototypes

void	TIM2_C0_IRQHandler(void);

/*
 * \brief test_08
 *
 * - Test of the TIM2 interruption
 *
 */
void	test_08(void) {

	REG(RCC)->APB1LENR |= RCC_APB1LENR_TIM2EN;
	STRONG_BARRIER;

	NVIC_SetPriority(TIM2_C0_IRQn, KINT_LEVEL_KERNEL_TIMERS);
	NVIC_EnableIRQ(TIM2_C0_IRQn);

	REG(TIM2)->CR1  = 0;
	REG(TIM2)->PSC  = KPSCT2;
	REG(TIM2)->ARR  = KARRT2;
	REG(TIM2)->CNT  = 0;
	REG(TIM2)->DIER = TIM2_DIER_UIE;
	REG(TIM2)->CR1  = TIM2_CR1_CEN;

	while (true) {
		cmns_wait(500000);
		LED_RED_TOGGLE;
	}
}

/*
 * \brief TIM2_C0_IRQHandler
 *
 * - Blink the BLUE Led
 *
 */
void	TIM2_C0_IRQHandler(void) {

// Acknowledge the TIM2 interruption
// Read-back to ensure the write completes before the handler returns;
// without this, on Cortex-M55 the NVIC can re-enter the handler immediately.

	REG(TIM2)->SR = ~TIM2_SR_UIF;
	(void)REG(TIM2)->SR;

	LED_BLUE_TOGGLE;
}
#endif
