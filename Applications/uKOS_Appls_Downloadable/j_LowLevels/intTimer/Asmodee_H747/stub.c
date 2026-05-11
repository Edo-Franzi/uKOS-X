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

#define KTTIM1MS		1000u									// For 1-ms (1000-Hz)
#define	KFPRET8			1000000u								// 1'000'000-Hz
#define	KFINTT8			KTTIM1MS								// 1'000-Hz
#define KPSCT8			((KFREQUENCY_APB2 / KFPRET8) - 1u)		// Prescaler for 1'000'000-Hz
#define KARRT8			((KFPRET8 / KFINTT8) - 1u)				// Autoreload

extern	volatile	uint32_t	vTimer;

// Prototypes

static	void	stub_intr_timer_interruption(void);
extern	void	aTimer_callBack(void);

/*
 * \brief stub_intr_timer_init
 *
 */
void	stub_intr_timer_init(void) {

	RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;

// Timer 8 (1-ms)

	INTERRUPT_VECTOR(TIM8_UP_TIM13_C0_IRQn, stub_intr_timer_interruption);
	NVIC_SetPriority(TIM8_UP_TIM13_C0_IRQn, KHW_PRIORITY_MODERATE);
	NVIC_EnableIRQ(TIM8_UP_TIM13_C0_IRQn);

	TIM8->PSC  = KPSCT8;
	TIM8->ARR  = KARRT8;
	TIM8->DIER = TIM8_DIER_UIE;
	TIM8->CR1 |= TIM8_CR1_CEN;
}

/*
 * \brief stub_intr_timer_interruption
 *
 */
static	void	stub_intr_timer_interruption(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

// INT acknowledge

	if ((TIM8->SR & TIM8_SR_UIF) != 0u) {
		TIM8->SR &= (uint16_t)~TIM8_SR_UIF;
	}
	if ((++vTimer % 100u) == 0u) { aTimer_callBack(); }

	PREEMPTION_THRESHOLD(core);
}
