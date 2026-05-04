/*
; tests_03.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the UART0 Rx interruption.
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

// Prototypes

void	local_UART0_IRQHandler(void);

/*
 * \brief test_03
 *
 * - Test of the UART0 Rx interruption
 *
 */
void	test_03(void) {

	INTERRUPT_VECTOR(UART0_IRQ_C0_IRQn, local_UART0_IRQHandler);
	core_enableExternalIRQ(UART0_IRQ_C0_IRQn);
	core_setBitCSR(RV_CSR_MIE, MIE_MEIE);

	cmns_init();

// Fifo 1/8, Interruption in reception & timeout interruption

	REG(UART0)->UARTLCR_H |= UART_UARTLCR_H_FEN;
	REG(UART0)->UARTIFLS   = (0u * UART_UARTIFLS_TXIFLSEL_0) | (0u * UART_UARTIFLS_RXIFLSEL_0);
	REG(UART0)->UARTIMSC  |= (UART_UARTIMSC_RXIM | UART_UARTIMSC_RTIM);

// Waiting for the UART0 interruption

	INTERRUPTION_ON_HARD;

	while (true) {
		cmns_wait(100000);
		LED_RED_TOGGLE;
	}
}

/*
 * \brief local_UART0_IRQHandler
 *
 * - Blink the YELLOW Led
 *
 */
void	local_UART0_IRQHandler(void) {
	uint32_t	iir;

	iir = REG(UART0)->UARTMIS;

	if ((iir & (UART_UARTMIS_RXMIS | UART_UARTMIS_RTMIS)) != 0u ) {

		while ((REG(UART0)->UARTFR & UART_UARTFR_RXFE) == 0u) {
			REG(UART0)->UARTDR;
			cmns_send(KURT0, "OK interruptions\n");

			LED_YELLOW_TOGGLE;
		}

// Acknowledge the UART0 interruption

		REG(UART0)->UARTICR = (UART_UARTICR_RXIC | UART_UARTICR_RTIC);
	}
}
