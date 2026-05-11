/*
; tests_12.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the TIMER4 interruption OCx.
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

#if (defined(TEST_12_S))

#define	KOCTIME			5000								// 5000-us
#define	KFPRET4			1000000								// 1'000'000-Hz
#define KPSCT4			((KFREQUENCY_TIM / KFPRET4) - 1)	// Prescaler for 1'000'000-Hz
#define KARRT4			0xFFFF								// Autoreload (every 65536-us)

// Prototypes

void	local_TIMER4_IRQHandler(void);

/*
 * \brief test_12
 *
 * - Test of the TIMER4 interruption OCx
 *
 */
void	test_12(void) {

	RCU->APB1EN |= RCU_APB1EN_TIMER4EN;

	TIMER4->CTL0	 = TIMER4_CTL0_ARSE;
	TIMER4->PSC 	 = KPSCT4;
	TIMER4->CH0CV	 = KOCTIME;
	TIMER4->CAR  	 = KARRT4;
	TIMER4->CNT  	 = 0;

	TIMER4->DMAINTEN = TIMER4_DMAINTEN_UPIE | TIMER4_DMAINTEN_CH0IE;
	TIMER4->CTL0	|= TIMER4_CTL0_CEN;

// nlbit = 3 (LEVEL3) -> LLL1 1111 (set by default at the start-up)
//
// LLLH HHHH means that the possible interruption level should be:
//
// 000H HHHH	31
// 001H HHHH	63
// 010H HHHH	95
// 011H HHHH	127
// 100H HHHH	159
// 101H HHHH	191
// 110H HHHH	223
// 111H HHHH	255
//
// ctl = 7 -> LLL = 011, level = 127
// mth = 31 (KINT_IMASK_ALL)

	ECLIC->CLICINT[TIMER4_C0_IRQn].CTL  = KINT_LEVEL_ALL;
	ECLIC->CLICINT[TIMER4_C0_IRQn].IP   = 0;
	ECLIC->CLICINT[TIMER4_C0_IRQn].IE   = 1;
	ECLIC->CLICINT[TIMER4_C0_IRQn].ATTR = ECLIC_INT_ATTR_SHV | ECLIC_INT_ATTR_TRIG_EDGE_RISING;
	ECLIC->MTH = KINT_IMASK_ALL;

	INTERRUPT_VECTOR(TIMER4_C0_IRQn, local_TIMER4_IRQHandler);

	INTERRUPTION_ON_HARD;

// Waiting for the TIMER1 interruption

	while (true) {
		cmns_wait(1000000);
	}
}

/*
 * \brief local_TIMER2_IRQHandler
 *
 * - Blink the BLUE Led
 *
 */
void	local_TIMER4_IRQHandler(void) {

// Acknowledge the TIMER4 interruption

	if ((TIMER4->INTF & TIMER4_INTF_UPIF) != 0) {
		TIMER4->INTF &= ~TIMER4_INTF_UPIF;

		LED_BLUE_TOGGLE;
	}

	if ((TIMER4->INTF & TIMER4_INTF_CH0IF) != 0) {
		TIMER4->INTF &= ~TIMER4_INTF_CH0IF;

		TIMER4->CH0CV = TIMER4->CNT + KOCTIME;
		LED_RED_TOGGLE;
	}
}
#endif
