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

#if (defined(TEST_01_S))
#define	KFREQUENCY_T2	KFREQUENCY_APB1
#define	KTTIMESAMPLING	500									// 2-Hz

#define	KFPRET2			1000000								// 1'000'000-Hz
#define	KFINTT2			(1000 / KTTIMESAMPLING)				// 50-Hz
#define KPSCT2			((KFREQUENCY_T2 / KFPRET2) - 1)		// Prescaler for 1'000'000-Hz
#define KARRT2			((KFPRET2 / KFINTT2) - 1)			// Autoreload

// Prototypes

void	local_TIM2_IRQHandler(void);

/*
 * \brief test_01
 *
 * - Test of the TIM2 interruption
 *
 */
void	test_01(void) {

	RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN;

// Initialise the TIM2 to generate an interruption every 500-ms

	INTERRUPT_VECTOR(TIM2_C0_IRQn, local_TIM2_IRQHandler);
	NVIC_SetPriority(TIM2_C0_IRQn, KINT_LEVEL_KERNEL_TIMERS);
	NVIC_EnableIRQ(TIM2_C0_IRQn);

	TIM2->PSC  = KPSCT2;
	TIM2->ARR  = KARRT2;
	TIM2->CNT  = 0;
	TIM2->DIER = TIM2_DIER_UIE;
	TIM2->CR1 |= TIM2_CR1_CEN;

// Waiting for the TIM2 interruption

	INTERRUPTION_ON_HARD;

	while (true) {
		cmns_wait(1000000);
		LED_RED_TOGGLE;
	}
}

/*
 * \brief local_TIM2_IRQHandler
 *
 * - Blink the YELLOW Led
 *
 */
void	local_TIM2_IRQHandler(void) {

// Acknowledge the TIM2 interruption

	TIM2->SR &= (uint32_t)~TIM2_SR_UIF;

	LED_BLUE_TOGGLE;
	LED_BLUE_TOGGLE;
	LED_BLUE_TOGGLE;
}
#endif
