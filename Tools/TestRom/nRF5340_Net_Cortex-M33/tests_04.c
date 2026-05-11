/*
; tests_04.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the UARTE_0 Tx interruption.
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
#include	<string.h>

#if (defined(TEST_04_S))
bool		vTransmitted = false;
char_t		vString[] = ".. but we are not afraid, we are alway firsts ...\n";

// Prototypes

void	local_SERIAL0_IRQHandler(void);

/*
 * \brief test_04
 *
 * - Test of the UARTE_1 Tx interruption
 *
 */
void	test_04(void) {
	size_t	length;

// Initialise the LPUART1 to generate Tx interruptions

	INTERRUPT_VECTOR(SERIAL0_C0_IRQn, local_SERIAL0_IRQHandler);
	NVIC_SetPriority(SERIAL0_C0_IRQn, KINT_LEVEL_COMMUNICATIONS);
	NVIC_EnableIRQ(SERIAL0_C0_IRQn);

	cmns_init();

// Waiting for the UARTE_1 interruption

	INTERRUPTION_ON_HARD;

	while (true) {
		length = strlen(vString);
		REG(UARTE0)->TXD_PTR	   = (uint32_t)vString;
		REG(UARTE0)->TXD_MAXCNT	   = (uint32_t)length;
		REG(UARTE0)->INTENSET	   = (1u<<8);
		REG(UARTE0)->TASKS_STARTTX = 1u;

// Let terminate the buffer transfer

		cmns_wait(1000000);
		do { } while (vTransmitted == false);

		vTransmitted = false;
		LED_0_TOGGLE;
	}
}

/*
 * \brief local_SERIAL0_IRQHandler
 *
 * - Blink the Led 1
 *
 */
void	local_SERIAL0_IRQHandler(void) {

	REG(UARTE0)->EVENTS_ENDTX = 0u;
	vTransmitted = true;
	LED_1_TOGGLE;
}
#endif
