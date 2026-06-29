/*
; tests_10.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the TIM0 interruption with reading of the CNT.
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
#define KTIMPRESC0		4									// For 1'000'000-Hz, 16'000'000 / (2^4)
#define	KTTIMESAMPLING	500000								// 2-Hz

static	char_t	vString[20];

// Prototypes

void	local_TIM0_IRQHandler(void);

/*
 * \brief test_10
 *
 * - Test of the TIM0 interruption with reading of the CNT
 *
 */
void	test_10(void) {
	uint32_t	time;

	cmns_init();

// Clock frequency of 1'000'000-Hz
// Mode timer
// 32-bit counter

	REG(TIMER0)->PRESCALER	 = KTIMPRESC0;
	REG(TIMER0)->MODE		 = 0;
	REG(TIMER0)->BITMODE	 = (3u<<0);

	REG(TIMER0)->CC[0]		 = KTTIMESAMPLING;
	REG(TIMER0)->TASKS_CLEAR = 1u;
	REG(TIMER0)->TASKS_COUNT = 1u;
	REG(TIMER0)->TASKS_START = 1u;

// Initialise the TIM0 to generate an interruption every 500-ms

	INTERRUPT_VECTOR(TIMER0_C0_IRQn, local_TIM0_IRQHandler);
	NVIC_SetPriority(TIMER0_C0_IRQn, KINT_LEVEL_KERNEL_TIMERS);
	NVIC_EnableIRQ(TIMER0_C0_IRQn);

	REG(TIMER0)->INTENSET = (1u<<16);

// Waiting for the TIM1 interruption

	INTERRUPTION_ON_HARD;

	while (true) {
		cmns_wait(1000000);
		REG(TIMER0)->TASKS_CAPTURE[1] = 1u;
		time = REG(TIMER0)->CC[1];

		(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)time);
		cmns_send(KURT0, "Time captured 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");
	}
}

/*
 * \brief local_TIM0_IRQHandler
 *
 * - Blink the 1 Led
 *
 */
void	local_TIM0_IRQHandler(void) {

// Acknowledge the TIM0 interruption

	REG(TIMER0)->CC[0] += KTTIMESAMPLING;
	REG(TIMER0)->EVENTS_COMPARE[0] = 0;
	LED_1_TOGGLE;
}
#endif
