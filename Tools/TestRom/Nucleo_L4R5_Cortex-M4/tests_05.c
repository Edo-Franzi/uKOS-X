/*
; tests_05.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the LPUART1 Tx interruption.
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

#if (defined(TEST_05_S))
bool		vTransmitted = false;
uint8_t		vString[] = ".. but we are not afraid, we are alway firsts ...\n";

// Prototypes

void	local_LPUART1_IRQHandler(void);

/*
 * \brief test_05
 *
 * - Test of the LPUART1 Tx interruption
 *
 */
void	test_05(void) {

// Initialise the LPUART1 to generate Tx interruptions

	INTERRUPT_VECTOR(LPUART1_C0_IRQn, local_LPUART1_IRQHandler);
	NVIC_SetPriority(LPUART1_C0_IRQn, KINT_LEVEL_COMMUNICATIONS);
	NVIC_EnableIRQ(LPUART1_C0_IRQn);

	cmns_init();

// Waiting for the LPUART1 interruption

	INTERRUPTION_ON_HARD;

	while (true) {
		LPUART1->CR1 |= LPUART1_CR1_TXFEIE;

// Let terminate the buffer transfer

		cmns_wait(1000000);
		do { } while (vTransmitted == false);

		vTransmitted = false;
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
			volatile	uint16_t	data;
			volatile	uint32_t	iir;
	static	volatile	uint8_t		index = 0;
	static	const		uint8_t		aSendText[] = "This is a text ...\n";

	iir = LPUART1->ISR;
	if ((iir & LPUART1_ISR_RXFNE) != 0) {

// Rx interruption

		data = LPUART1->RDR;
		LED_BLUE_TOGGLE;
	}

	if (((iir & LPUART1_ISR_TXFNF) && (LPUART1->CR1 & LPUART1_CR1_TXFEIE)) != 0) {
		data = (uint16_t)aSendText[index];
		if (data == 0) {

// Terminated

			index = 0;
			vTransmitted = true;
			LPUART1->CR1 &= ~LPUART1_CR1_TXFEIE;
		}
		else {
			LPUART1->TDR = data;
			index++;
		}
	}
}
#endif
