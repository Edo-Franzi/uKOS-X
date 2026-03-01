/*
; tests_08.
; =========

; SPDX-License-Identifier: MIT

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

#if (defined(TEST_08_S))
#define	KTTIMESAMPLING	500									// 2-Hz

#define	KFPRET5			1000000								// 1'000'000-Hz
#define	KFINTT5			(1000 / KTTIMESAMPLING)				// 50-Hz
#define KPSCT5			((KFREQUENCY_TIM / KFPRET5) - 1)	// Prescaler for 1'000'000-Hz
#define KARRT5			((KFPRET5 / KFINTT5) - 1)			// Autoreload

// Prototypes

void	local_TIM5_IRQHandler(void);

/*
 * \brief test_08
 *
 * - Test of the TIM5 interruption
 *
 */
void	test_08(void) {

	RCC->APB1LENR |= RCC_APB1LENR_TIM5EN;

// Initialise the TIM5 to generate an interruption every 500-ms

	INTERRUPT_VECTOR(TIM5_C0_IRQn, local_TIM5_IRQHandler);
	NVIC_SetPriority(TIM5_C0_IRQn, KINT_LEVEL_KERNEL_TIMERS);
	NVIC_EnableIRQ(TIM5_C0_IRQn);

	TIM5->CR1 &= ~TIM5_CR1_CEN;
	TIM5->PSC  = KPSCT5;
	TIM5->ARR  = KARRT5;
	TIM5->CNT  = 0;
	TIM5->DIER = TIM5_DIER_UIE;
	TIM5->CR1 |= TIM5_CR1_CEN;

// Waiting for the TIM5 interruption

	INTERRUPTION_ON_HARD;

	while (true) {
		cmns_wait(100000);
		LED_RED_TOGGLE;
	}
}

/*
 * \brief local_TIM5_IRQHandler
 *
 * - Blink the YELLOW Led
 *
 */
void	local_TIM5_IRQHandler(void) {

// Acknowledge the TIM5 interruption

	TIM5->SR &= ~TIM5_SR_UIF;

	LED_YELLOW_TOGGLE;
	LED_YELLOW_TOGGLE;
	LED_YELLOW_TOGGLE;
}
#endif
