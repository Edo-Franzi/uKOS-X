/*
; tests_14.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of IPC communication.
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

#if (defined(TEST_14_S))

// Channel cpu A to cpu B
// - Write A to B on channel 0
// - Ready, B read the message on channel 1
//
// Channel cpu B to cpu A
// - Write B to A on channel 2
// - Ready, A read the message on channel 3

static	volatile	bool	vAck = false;

// Prototypes

void	local_IPC_IRQHandler(void);

/*
 * \brief test_14
 *
 * - Test of IPC communication
 *
 */
void	test_14(void) {

// Initialise the IPC to generate an interruption on the reception

	INTERRUPT_VECTOR(IPC_C0_IRQn, local_IPC_IRQHandler);
	NVIC_SetPriority(IPC_C0_IRQn, KINT_LEVEL_KERNEL_TIMERS);
	NVIC_EnableIRQ(IPC_C0_IRQn);

// A to B channel

	#if (defined(CPU_APPLICATION_S))
	REG(IPC)->SEND_CNF[0]	 = (1u<<0);				// Send data to B
	REG(IPC)->RECEIVE_CNF[1] = (1u<<1);				// Receive data from B
	REG(IPC)->SEND_CNF[2]	 = (1u<<2);				// Acknowledge to B
	REG(IPC)->RECEIVE_CNF[3] = (1u<<3);				// Acknowledge from B
	REG(IPC)->INTENSET		 = (1u<<3) | (1u<<1);	// Interruption on the Acknowledge from B and Receive data from B
	#endif

// B to A channel

	#if (defined(CPU_NETWORK_S))
	REG(IPC)->SEND_CNF[1]	 = (1u<<1);				// Send data to A
	REG(IPC)->RECEIVE_CNF[0] = (1u<<0);				// Receive data from A
	REG(IPC)->SEND_CNF[3]	 = (1u<<3);				// Acknowledge to A
	REG(IPC)->RECEIVE_CNF[2] = (1u<<2);				// Acknowledge from A
	REG(IPC)->INTENSET		 = (1u<<2) | (1u<<0);	// Interruption on the Acknowledge from A and Receive data from A
	#endif

	cmns_wait(1000000);

// Waiting for the TIM1 interruption

	INTERRUPTION_ON_HARD;

	while (true) {
		#if (defined(CPU_APPLICATION_S))
		cmns_wait(1000000);

		vAck = false;
		REG(IPC)->TASKS_SEND[0] = 1u;				// Send data to B
		while (vAck == false) { ; }					// Waiting for the acknowledge from B
		LED_0_TOGGLE;
		#endif

		#if (defined(CPU_NETWORK_S))
		cmns_wait(1000000);

		vAck = false;
		REG(IPC)->TASKS_SEND[1] = 1u;				// Send data to A
		while (vAck == false) { ; }					// Waiting for the acknowledge from A
		LED_0_TOGGLE;
		#endif

	}
}

/*
 * \brief local_IPC_IRQHandler
 *
 * - Channel management
 *
 */
void	local_IPC_IRQHandler(void) {

// Acknowledge the IPC interruption
// Verify if interruption data

	#if (defined(CPU_APPLICATION_S))
	if (REG(IPC)->EVENTS_RECEIVE[1] != 0) {			//
		REG(IPC)->EVENTS_RECEIVE[1] = 0;			// Receive data from B
		REG(IPC)->TASKS_SEND[2] = 1u;				// Acknowledge to B
	}

	if (REG(IPC)->EVENTS_RECEIVE[3] != 0) {			//
		REG(IPC)->EVENTS_RECEIVE[3] = 0;			// Acknowledge from B
		vAck = true;								//
	}
	#endif

	#if (defined(CPU_NETWORK_S))
	if (REG(IPC)->EVENTS_RECEIVE[0] != 0) {			//
		REG(IPC)->EVENTS_RECEIVE[0] = 0;			// Receive data from A
		REG(IPC)->TASKS_SEND[3] = 1u;				// Acknowledge to A
	}

	if (REG(IPC)->EVENTS_RECEIVE[2] != 0) {			//
		REG(IPC)->EVENTS_RECEIVE[2] = 0;			// Acknowledge from A
		vAck = true;								//
	}
	#endif
}
#endif
