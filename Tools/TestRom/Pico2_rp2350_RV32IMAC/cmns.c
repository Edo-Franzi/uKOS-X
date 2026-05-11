/*
; cmns.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		Common routines for RISC-V TestROM.
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

/*
 * \brief cmns_init
 *
 * - Initialise the UART0 and UART1 peripherals
 *
 *
 * \note This function does not return a value (None).
 *
 */
void	cmns_init(void) {

// Reset of the devices

	REG(RESETS)->RESET &= ~RESETS_RESET_UART0;
	while ((REG(RESETS)->RESET_DONE & RESETS_RESET_UART0) != RESETS_RESET_UART0) { }

	REG(RESETS)->RESET &= ~RESETS_RESET_UART1;
	while ((REG(RESETS)->RESET_DONE & RESETS_RESET_UART1) != RESETS_RESET_UART1) { }

// Disable the UARTx

	REG(UART0)->UARTCR = 0;
	REG(UART1)->UARTCR = 0;

// Bauds:
// Div = UARTCLK / (16 * BAUD) = IBRD + FBRD / 64
// For 150 MHz et 460800 b/s: IBRD = 20, FBRD = 22 (≈460830 b/s)
// Format 8N1

	BAUDRATE(UART0, 150000000, 460800);
	BAUDRATE(UART1, 150000000, 460800);
	REG(UART0)->UARTLCR_H = (3u * UART_UARTLCR_H_WLEN_0);
	REG(UART1)->UARTLCR_H = (3u * UART_UARTLCR_H_WLEN_0);

// Enable the UARTx

	REG(UART0)->UARTCR = UART_UARTCR_UARTEN | UART_UARTCR_RXE | UART_UARTCR_TXE;
	REG(UART1)->UARTCR = UART_UARTCR_UARTEN | UART_UARTCR_RXE | UART_UARTCR_TXE;
}

/*
 * \brief cmns_send
 *
 * - Send ASCII string via UART
 *
 * \param[in]	serialManager	Serial Communication Manager
 * \param[in]	*ascii			Ptr on the ascii buffer
 *
 * \note This function does not return a value (None).
 *
 */
void	cmns_send([[maybe_unused]] serialManager_t serialManager, const char_t *ascii) {
			uint8_t		data;
			uint32_t	core;
	const	char_t		*wkAscii = ascii;

	core = GET_RUNNING_CORE;

	if (ascii == nullptr) { return; }

	switch (core) {

// Core 0

		default:
		case KCORE_0: {
			while (true) {
				while ((REG(UART0)->UARTFR & UART_UARTFR_TXFF) != 0u) { }

				data = (uint8_t)*wkAscii;
				wkAscii++;
				if (data == '\0') {
					return;
				}

				cmns_wait(100);
				REG(UART0)->UARTDR = (uint32_t)data;
			}
			break;
		}

// Core 1

		case KCORE_1: {
			while (true) {
				while ((REG(UART1)->UARTFR & UART_UARTFR_TXFF) != 0u) { }

				data = (uint8_t)*wkAscii;
				wkAscii++;
				if (data == '\0') {
					return;
				}

				cmns_wait(100);
				REG(UART1)->UARTDR = (uint32_t)data;
			}
			break;
		}
	}
}

/*
 * \brief cmns_receive
 *
 * - Receive a character from UART
 *
 * \param[in]	serialManager	Serial Communication Manager
 * \param[out]	*data			Data received
 *
 * \note This function does not return a value (None).
 *
 */
void	cmns_receive(serialManager_t serialManager, char_t *data) {
	uint32_t	core;
	uint32_t	dr;

	UNUSED(serialManager);

	core = GET_RUNNING_CORE;

	switch (core) {

// Core 0

		default:
		case KCORE_0: {
			while ((REG(UART0)->UARTFR & UART_UARTFR_RXFE) != 0u) { }

			dr = REG(UART0)->UARTDR;
			*data = (uint8_t)dr;
			break;
		}

// Core 1

		case KCORE_1: {
			while ((REG(UART1)->UARTFR & UART_UARTFR_RXFE) != 0u) { }

			dr = REG(UART1)->UARTDR;
			*data = (uint8_t)dr;
			break;
		}
	}
}

/*
 * \brief cmns_wait
 *
 * - Simple delay loop for RISC-V
 *
 * \param[in]	us		Delay in microseconds (approximate)
 *
 * \note This function does not return a value (None).
 *
 */
void	cmns_wait(uint32_t us) {
	uint32_t	wkUs = us, time;

	// Calibrated for ~150 MHz RISC-V with cache
	// Adjust divisor based on actual timing measurements

	wkUs = (wkUs / 7u) * (KFREQUENCY_CORE / 1000000u);

	wkUs = (wkUs == 0u) ? (1u) : (wkUs);
	for (time = 0; time < wkUs; time++) {
		__asm volatile ("nop");
	}
}
