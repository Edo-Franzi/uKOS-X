/*
; stub_urt0_lpuart1.
; ==================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the connection of the "urt0" manager to the lpuart1 device.
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

#include	"uKOS.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define	USART					LPUART1
#define	USART_VECTOR_NUMBER		LPUART1_C0_IRQn
#define	USART_FREQUENCY			KFREQUENCY_APB1

#define	model_usart_init		stub_urt0_init
#define	model_usart_configure	stub_urt0_configure
#define	model_usart_write		stub_urt0_write
#define	model_usart_read		stub_urt0_read
#define	model_usart_flush		stub_urt0_flush

#define	KUSART_SEMA_RX_S
#define	KUSART_SEMA_TX_S
#define	KUSART_SEMAPHORE_RX		KURT0_SEMAPHORE_RX
#define	KUSART_SEMAPHORE_TX		KURT0_SEMAPHORE_TX

#define	KUSART_SZ_TX_BUF		64u
#define	KUSART_SZ_RX_BUF		128u

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the device (clock)
 *
 */
static	void	cb_enable(void) {

	RCC->APB1ENR2 |= RCC_APB1ENR2_LPUART1EN;
}

/*
 * \brief cb_CTSCheck
 *
 * - Verify the CTS state
 *   If CTS =  1, then disable the uart TX interruptions
 *
 */
static	bool	cb_CTSCheck(void) {

	return (true);
}

/*
 * \brief cb_init
 *
 * - Specific initialisations          __
 *   i.e the hardware CTS interruption   \__
 *
 */
static	void	cb_init(void) {

}

#include	"model_usart.c_inc"
