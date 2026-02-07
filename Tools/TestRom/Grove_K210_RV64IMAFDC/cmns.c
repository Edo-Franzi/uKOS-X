/*
; cmns.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:	Edo. Franzi		The 2025-01-01	Correct for matching some MISRA recommendations
;
; Project:	uKOS-X
; Goal:		Some common routines used in many modules.
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

#define	CONFIG_DEFAULT_BAUDRATE		115200
#define	KDIVISOR					(KFREQUENCY_APB0 / CONFIG_DEFAULT_BAUDRATE)

/*
 * \brief cmns_init
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
void	cmns_init(void) {

// Turn on the UART1

	sysctl->clk_en_peri.uart1_clk_en = 1;

	uart1->LCR |= 1u<<7;

	BAUDRATE(KFREQUENCY_APB0, CONFIG_DEFAULT_BAUDRATE, uart1->DLH, uart1->DLL, uart1->DLF);

	uart1->LCR  = 0;
	uart1->LCR  = UART_LCR_NBBIT8 | UART_LCR_STBIT1 | UART_LCR_PARITYNONE;
	uart1->LCR &= (uint32_t)~(1u<<7);
	uart1->IER |= 0x80;
	uart1->FCR  = (UART_FCR_RECEIVE_FIFO_1 | UART_FCR_SEND_FIFO_8) | (1u<<3) | 0x1;

// Turn on the UART2

	sysctl->clk_en_peri.uart2_clk_en = 1;

	uart2->LCR |= 1u<<7;

	BAUDRATE(KFREQUENCY_APB0, CONFIG_DEFAULT_BAUDRATE, uart2->DLH, uart2->DLL, uart2->DLF);

	uart2->LCR  = 0;
	uart2->LCR  = UART_LCR_NBBIT8 | UART_LCR_STBIT1 | UART_LCR_PARITYNONE;
	uart2->LCR &= (uint32_t)~(1u<<7);
	uart2->IER |= 0x80;
	uart2->FCR  = (UART_FCR_RECEIVE_FIFO_1 | UART_FCR_SEND_FIFO_8) | (1u<<3) | 0x1;
}

/*
 * \brief cmns_send
 *
 * \param[in]	serialManager	Serial Communication Manager
 * \param[in]	*ascii			Ptr on the ascii buffer
 *
 * \note This function does not return a value (None).
 *
 */
void	cmns_send(serialManager_t serialManager, const char_t *ascii) {
			uint8_t		data;
	const	char_t		*wkAscii = ascii;

	if (ascii == nullptr) { return; }

	switch (serialManager) {

// UART 0 device

		default:
		case KURT0: {
			while (true) {
				while ((uart2->LSR & UART_LSR_TEMT) != 0) { ; }

				data = (uint8_t)*wkAscii;
				wkAscii++;
				if(data == '\0') {
					return;
				}

				uart2->THR = data;
			}
			break;
		}
		case KURT1: {
			while (true) {
				while ((uart1->LSR & UART_LSR_TEMT) != 0) { ; }

				data = (uint8_t)*wkAscii;
				wkAscii++;
				if(data == '\0') {
					return;
				}

				uart1->THR = data;
			}
			break;
		}
	}
}

/*
 * \brief cmns_receive
 *
 * \param[in]	serialManager	Serial Communication Manager
 * \param[out]	*data			Data received
 *
 * \note This function does not return a value (None).
 *
 */
void	cmns_receive(serialManager_t serialManager, char_t *data) {

	switch (serialManager) {

// UART 0 device

		default:
		case KURT0: {
			while ((uart2->LSR & UART_LSR_DATAREADY) == 0) { ; }

			*data = (uint8_t)(uart2->RBR & 0xFF);
			break;
		}
	}
}

/*
 * \brief cmns_wait
 *
 * \param[in]	us		Delay in us
 *
 * \note This function does not return a value (None).
 *
 */
void	cmns_wait(uint32_t us) {
	uint32_t	wkUs = us, time;

	#if (defined(CACHE_S))
	wkUs = (wkUs / 7u) * (KFREQUENCY_CORE / 1000000u);

	#else
	wkUs = (wkUs / 12u) * (KFREQUENCY_CORE / 1000000u);
	#endif

	for (time = 0; time < wkUs; time++) { NOP; }
}
