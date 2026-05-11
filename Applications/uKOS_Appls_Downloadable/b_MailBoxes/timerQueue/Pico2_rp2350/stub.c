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

#define	KTIM_ESAMPLING_0	((float64_t)(0.0001))								// 100-us
#define KDELTA_TIME_0		((uint32_t)(KFREQUENCY_TIM * KTIM_ESAMPLING_0))		// Delta time

// Prototypes

static	void	stub_intr_timer_interruption(void);

/*
 * \brief stub_intr_timer_init
 *
 */
void	stub_intr_timer_init(void) {

// Alarme 3 (100-us)

	REG(TIMER0)->INTE	= REG(TIMER0)->INTE | TIMER_INTE_ALARM_3;
	REG(TIMER0)->ALARM3 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_0;

	INTERRUPT_VECTOR(TIMER0_IRQ_3_C0_IRQn, stub_intr_timer_interruption);
	NVIC_SetPriority(TIMER0_IRQ_3_C0_IRQn, KINT_LEVEL_KERNEL_TIMERS);
	NVIC_EnableIRQ(TIMER0_IRQ_3_C0_IRQn);
}

/*
 * \brief stub_intr_timer_interruption
 *
 */
static	void	stub_intr_timer_interruption(void) {
			uint32_t	core;
			int32_t		status;
	static	mbox_t		*vQueue;
	static	bool		vInit = false;
	static	uintptr_t	vCounter = 0u;

	core = GET_RUNNING_CORE;

	if (vInit == false) {
		if (kern_getMailboxById("Queue tim", &vQueue) == KERR_KERN_NOERR) {
			vInit = true;
		}
	}

// INT acknowledge

	if ((REG(TIMER0)->INTS & TIMER_INTS_ALARM_3) != 0u) {
		REG(TIMER0)->INTR = TIMER_INTR_ALARM_3;

		REG(TIMER0)->ALARM3 = REG(TIMER0)->TIMERAWL + KDELTA_TIME_0;
	}

	status = kern_writeQueue(vQueue, vCounter, 0u);
	if (status == KERR_KERN_NOERR) {
		vCounter++;
	}

	PREEMPTION_THRESHOLD(core);
}
