/*
; stub.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Hardware specific stub.
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

#include	"uKOS.h"

#define KPSCT1		0u							// Prescaler for 240'000'000-Hz
#define KARRT1		((1u<<12u) - 1u)			// Autoreload (4096-bits for 58-KHz)

#define KPSCT15		0u							// Prescaler for 240'000'000-Hz
#define KARRT15		60000u						// Autoreload (> 8192-bits for 20-KHz)

/*
 * \brief stub_intr_timer_init
 *
 */
void	stub_intr_timer_init(void) {

	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	RCC->APB2ENR |= RCC_APB2ENR_TIM15EN;

// Timer 1 (58-KHz PWM)

	TIM1->CNT  = 0u;
	TIM1->PSC  = KPSCT1;
	TIM1->ARR  = KARRT1;

// Timer 15 (58-KHz PWM)

	TIM15->CNT  = 0u;
	TIM15->PSC  = KPSCT15;
	TIM15->ARR  = KARRT15;

// CH1 - Tim 1

	TIM1->CCR1   = ((TIM1->ARR + 1u) * 33u) / 100u;
	TIM1->CCMR1 |= (6u * TIM1_CCMR1_OC1M_0);
	TIM1->CCMR1 |= TIM1_CCMR1_OC1PE;
	TIM1->CCER  |= TIM1_CCER_CC1E;

// CH2 - Tim 1

	TIM1->CCR2   = ((TIM1->ARR + 1u) * 75u) / 100u;
	TIM1->CCMR1 |= (6u * TIM1_CCMR1_OC2M_0);
	TIM1->CCMR1 |= TIM1_CCMR1_OC2PE;
	TIM1->CCER  |= TIM1_CCER_CC2E;

// CH3 - Tim 1

	TIM1->CCR3   = ((TIM1->ARR + 1u) * 50u) / 100u;
	TIM1->CCMR2 |= (6u * TIM1_CCMR2_OC3M_0);
	TIM1->CCMR2 |= TIM1_CCMR2_OC3PE;
	TIM1->CCER  |= TIM1_CCER_CC3E;

	TIM1->BDTR |= TIM1_BDTR_MOE;
	TIM1->CR1  |= TIM1_CR1_CEN;

// CH1 - Tim 15

	TIM15->CCR1   = ((TIM15->ARR + 1u) * 50u) / 100u;
	TIM15->CCMR1 |= (6u * TIM15_CCMR1_OC1M_0);
	TIM15->CCMR1 |= TIM15_CCMR1_OC1PE;
	TIM15->CCER  |= TIM15_CCER_CC1E;

	TIM15->BDTR |= TIM15_BDTR_MOE;
	TIM15->CR1  |= TIM15_CR1_CEN;
}
