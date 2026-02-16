/*
; tests_04.
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

#if (defined(TEST_04_S))
volatile	bool		vTransmitted = false;
volatile	bool		vFirstKick = false;
volatile	uint8_t		vString[] = ".. but we are not afraid, we are alway firsts ...\n";

// Prototypes

void	local_UART0_IRQHandler(void);

/*
 * \brief test_04
 *
 * - Test of the UART0 Tx interruption
 *
 */
void	test_04(void) {

// Initialise the UART0 to generate Tx interruptions

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
		vTransmitted = false;

		REG(UART0)->UARTICR   = UART_UARTICR_TXIC;
		REG(UART0)->UARTIMSC |= UART_UARTIMSC_TXIM;

		vFirstKick = true;
		core_setPendingExternalIRQ(UART0_IRQ_C0_IRQn);

		LED_RED_TOGGLE;

// Let terminate the buffer transfer

		cmns_wait(1000000);
		do { } while (vTransmitted == false);
	}
}

/*
 * \brief local_UART0_IRQHandler
 *
 * - Blink the YELLOW Led on Rx & the GREEN Led on the end Tx
 *
 */

void	local_UART0_IRQHandler(void) {
			uint8_t		c;
			uint32_t	iir;
	static	uint8_t		index = 0u;

    LED_GREEN_TOGGLE;

	iir = REG(UART0)->UARTMIS;

	if ((iir & (UART_UARTMIS_RXMIS | UART_UARTMIS_RTMIS)) != 0u ) {

// Rx interruption
// Try to get empty the fifo

		while ((REG(UART0)->UARTFR & UART_UARTFR_RXFE) == 0u) {
			REG(UART0)->UARTDR;
			cmns_send(KURT0, "OK interruptions\n");

			LED_YELLOW_TOGGLE;
		}

// Acknowledge the UART0 interruption

		REG(UART0)->UARTICR = (UART_UARTICR_RXIC | UART_UARTICR_RTIC);
	}

	if (((iir & UART_UARTMIS_TXMIS) != 0u) || (vFirstKick == true)) {
		vFirstKick = false;
		core_clearPendingExternalIRQ(UART0_IRQ_C0_IRQn);

// Tx interruption
// Try to fill the fifo

		while ((REG(UART0)->UARTFR & UART_UARTFR_TXFF) == 0u) {
			c = (uint8_t)vString[index++];
			if (c == '\0') {
				LED_GREEN_TOGGLE;

				index = 0u;
				vTransmitted = true;
				REG(UART0)->UARTIMSC &= ~UART_UARTIMSC_TXIM;
				break;
			}
			REG(UART0)->UARTDR = (uint32_t)c;
		}

// Acknowledge the UART0 interruption

       REG(UART0)->UARTICR = UART_UARTICR_TXIC;
	}
}
#endif
