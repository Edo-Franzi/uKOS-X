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

#define	CONFIG_DEFAULT_BAUDRATE		460800

/*
 * \brief cmns_init
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
void	cmns_init(void) {

	RCC->APB1ENR2 |= RCC_APB1ENR2_LPUART1EN;

	LPUART1->BRR = BAUDRATE_LP(KFREQUENCY_APB1, CONFIG_DEFAULT_BAUDRATE);
	LPUART1->CR1 = (LPUART1_CR1_UE | LPUART1_CR1_TE | LPUART1_CR1_RE);

	RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;

	USART2->BRR = BAUDRATE(KFREQUENCY_APB1, CONFIG_DEFAULT_BAUDRATE);
	USART2->CR1 = (USART2_CR1_UE | USART2_CR1_TE | USART2_CR1_RE);

	RCC->APB1ENR1 |= RCC_APB1ENR1_USART3EN;

	USART3->BRR = BAUDRATE(KFREQUENCY_APB1, CONFIG_DEFAULT_BAUDRATE);
	USART3->CR1 = (USART3_CR1_UE | USART3_CR1_TE | USART3_CR1_RE);
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
				while ((LPUART1->ISR & LPUART1_ISR_TXFE) == 0) { ; }

				data = (uint8_t)*wkAscii;
				wkAscii++;
				if (data == '\0') {
					return;
				}

				LPUART1->TDR = (uint16_t)data;
			}
		}

// UART 1 device

		case KURT1: {
			while (true) {
				while ((USART2->ISR & USART2_ISR_TXFE) == 0) { ; }

				data = (uint8_t)*wkAscii;
				wkAscii++;
				if (data == '\0') {
					return;
				}

				USART2->TDR = (uint16_t)data;
			}
		}

// UART 2 device

		case KURT2: {
			while (true) {
				while ((USART3->ISR & USART3_ISR_TXFE) == 0) { ; }

				data = (uint8_t)*wkAscii;
				wkAscii++;
				if (data == '\0') {
					return;
				}

				USART3->TDR = (uint16_t)data;
			}
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
			while ((LPUART1->ISR & LPUART1_ISR_RXFNE) == 0) { ; }

			*data = (uint8_t)LPUART1->RDR;
			break;
		}

// UART 1 device

		case KURT1: {
			while ((USART2->ISR & USART2_ISR_RXFNE) == 0) { ; }

			*data = (uint8_t)USART2->RDR;
			break;
		}

// UART 2 device

		case KURT2: {
			while ((USART3->ISR & USART3_ISR_RXFNE) == 0) { ; }

			*data = (uint8_t)USART3->RDR;
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
