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

	REG(RCC)->APB2ENR |= RCC_APB2ENR_TIM1EN;
	REG(RCC)->APB2ENR |= RCC_APB2ENR_TIM15EN;

// Timer 1 (58-KHz PWM)

	REG(TIM1)->CNT  = 0u;
	REG(TIM1)->PSC  = KPSCT1;
	REG(TIM1)->ARR  = KARRT1;

// Timer 15 (58-KHz PWM)

	REG(TIM15)->CNT  = 0u;
	REG(TIM15)->PSC  = KPSCT15;
	REG(TIM15)->ARR  = KARRT15;

// CH1 - Tim 1

	REG(TIM1)->CCR1   = ((REG(TIM1)->ARR + 1u) * 33u) / 100u;
	REG(TIM1)->CCMR1 |= (6u* TIM1_CCMR1_OC1M_0);
	REG(TIM1)->CCMR1 |= TIM1_CCMR1_OC1PE;
	REG(TIM1)->CCER  |= TIM1_CCER_CC1E;

// CH2 - Tim 1

	REG(TIM1)->CCR2   = ((REG(TIM1)->ARR + 1u) * 75u) / 100u;
	REG(TIM1)->CCMR1 |= (6u * TIM1_CCMR1_OC2M_0);
	REG(TIM1)->CCMR1 |= TIM1_CCMR1_OC2PE;
	REG(TIM1)->CCER  |= TIM1_CCER_CC2E;

// CH3 - Tim 1

	REG(TIM1)->CCR3   = ((REG(TIM1)->ARR + 1u) * 50u) / 100u;
	REG(TIM1)->CCMR2 |= (6u * TIM1_CCMR2_OC3M_0);
	REG(TIM1)->CCMR2 |= TIM1_CCMR2_OC3PE;
	REG(TIM1)->CCER  |= TIM1_CCER_CC3E;

	REG(TIM1)->BDTR |= TIM1_BDTR_MOE;
	REG(TIM1)->CR1  |= TIM1_CR1_CEN;

// CH1 - Tim 15

	REG(TIM15)->CCR1   = ((REG(TIM15)->ARR + 1u) * 50u) / 100u;
	REG(TIM15)->CCMR1 |= (6u * TIM15_CCMR1_OC1M_0);
	REG(TIM15)->CCMR1 |= TIM15_CCMR1_OC1PE;
	REG(TIM15)->CCER  |= TIM15_CCER_CC1E;

	REG(TIM15)->BDTR |= TIM15_BDTR_MOE;
	REG(TIM15)->CR1  |= TIM15_CR1_CEN;
}
