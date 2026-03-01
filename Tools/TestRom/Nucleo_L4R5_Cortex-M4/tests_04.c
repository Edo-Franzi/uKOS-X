/*
; tests_04.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the LPUART1 Rx interruption.
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

#if (defined(TEST_04_S))

// Prototypes

void	local_LPUART1_IRQHandler(void);

/*
 * \brief test_04
 *
 * - Test of the LPUART1 Rx interruption
 *
 */
void	test_04(void) {

// Initialise the LPUART1 to generate Rx interruptions

	INTERRUPT_VECTOR(LPUART1_C0_IRQn, local_LPUART1_IRQHandler);
	NVIC_SetPriority(LPUART1_C0_IRQn, KINT_LEVEL_COMMUNICATIONS);
	NVIC_EnableIRQ(LPUART1_C0_IRQn);

	cmns_init();
	LPUART1->CR1 |= LPUART1_CR1_RXFNEIE;

// Waiting for the USART3 interruption

	INTERRUPTION_ON_HARD;

	while (true) {
		cmns_wait(1000000);
		LED_RED_TOGGLE;
	}
}

/*
 * \brief local_LPUART1_IRQHandler
 *
 * - Blink the BLUE Led
 *
 */
void	local_LPUART1_IRQHandler(void) {

// Acknowledge the LPUART1 interruption

	LPUART1->RDR;

	cmns_send(KURT0, "OK interruptions\n");
	LED_BLUE_TOGGLE;
}
#endif
