/*
; tests_13.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of IPC basics.
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

#if (defined(TEST_13_S))

// Prototypes

void	local_IPC_IRQHandler(void);

/*
 * \brief test_13
 *
 * - Test of IPC basics
 *
 */
void	test_13(void) {

// Initialise the IPC to generate an interruption on the reception

	INTERRUPT_VECTOR(IPC_C0_IRQn, local_IPC_IRQHandler);
	NVIC_SetPriority(IPC_C0_IRQn, KINT_LEVEL_KERNEL_TIMERS);
	NVIC_EnableIRQ(IPC_C0_IRQn);

	#if (defined(CPU_APPLICATION_S))
	REG(IPC)->SEND_CNF[0]	 = (1u<<0);
	REG(IPC)->RECEIVE_CNF[1] = (1u<<1);
	REG(IPC)->INTENSET		 = (1u<<1);
	#endif

	#if (defined(CPU_NETWORK_S))
	REG(IPC)->SEND_CNF[1]	 = (1u<<1);
	REG(IPC)->RECEIVE_CNF[0] = (1u<<0);
	REG(IPC)->INTENSET		 = (1u<<0);
	#endif

// Waiting for the TIM1 interruption

	INTERRUPTION_ON_HARD;

	while (true) {
		#if (defined(CPU_APPLICATION_S))
		cmns_wait(100000);

		REG(IPC)->TASKS_SEND[0] = 1u;
		#endif

		#if (defined(CPU_NETWORK_S))
		cmns_wait(1000000);

		REG(IPC)->TASKS_SEND[1] = 1u;
		#endif

	}
}

/*
 * \brief local_IPC_IRQHandler
 *
 * - Blink the 0 Led
 *
 */
void	local_IPC_IRQHandler(void) {

// Acknowledge the IPC interruption

	#if (defined(CPU_APPLICATION_S))
	REG(IPC)->EVENTS_RECEIVE[1] = 0;
	#endif

	#if (defined(CPU_NETWORK_S))
	REG(IPC)->EVENTS_RECEIVE[0] = 0;
	#endif

	LED_0_TOGGLE;
}
#endif
