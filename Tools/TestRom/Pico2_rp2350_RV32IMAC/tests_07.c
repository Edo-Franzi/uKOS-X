/*
; tests_07.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the UART0 Tx interruption.
;
;   (c) 2025-2026, Laurent von Allmen
;   ---------------------------------
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

			bool		vTransmitted = false;
volatile	uint8_t		vString[] = ".. but we are not afraid, we are alway firsts ...\n";

// Prototypes

void	local_UART0_IRQHandler(void);

/*
 * \brief test_07
 *
 * - Test of the UART0 Tx interruption
 *
 */
void	test_07(void) {

// Initialise the UART0 to generate Tx interruptions

	INTERRUPT_VECTOR(UART0_IRQ_C0_IRQn, local_UART0_IRQHandler);
	core_enableExternalIRQ(UART0_IRQ_C0_IRQn);
	core_setBitCSR(RV_CSR_MIE, MIE_MEIE);

	cmns_init();

	INTERRUPTION_ON_HARD;

	while (true) {
		REG(UART0)->UARTIMSC |= UART_UARTIMSC_TXIM;
		core_setPendingExternalIRQ(UART0_IRQ_C0_IRQn);

// Let terminate the buffer transfer

		cmns_wait(1000000);
		do { } while (vTransmitted == false);

		vTransmitted = false;
		LED_RED_TOGGLE;
	}
}

/*
 * \brief local_UART0_IRQHandler
 *
 * - Blink the GREEN Led on the end of the Tx
 *
 */
void	local_UART0_IRQHandler(void) {
			volatile	uint32_t	data;
	static	volatile	uint8_t		index = 0u;

// Clear the force-pending bit (set by core_setPendingExternalIRQ)

	core_clearPendingExternalIRQ(UART0_IRQ_C0_IRQn);

// Tx interruption

	REG(UART0)->UARTICR = UART_UARTICR_TXIC;

 	data = (uint32_t)vString[index];
	REG(UART0)->UARTDR = data;
	index++;
	if (vString[index] == 0u) {


// Terminated

		LED_GREEN_TOGGLE;

		index = 0u;
		vTransmitted = true;
		REG(UART0)->UARTIMSC &= ~UART_UARTIMSC_TXIM;
	}
}
