/*
; stub_urt0_uart.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the connection of the "urt0" manager to the uart1 & 2 device.
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

// Model callbacks
// ---------------

/*
 * \brief cb_enable_Cx
 *
 * - Enable the device (clock)
 *
 */
static	void	cb_enable_C0(void) {

	sysctl->clk_en_peri.uart2_clk_en = 1;
}

static	void	cb_enable_C1(void) {

	sysctl->clk_en_peri.uart1_clk_en = 1;
}

/*
 * \brief cb_CTSCheck_Cx
 *
 * - Verify the CTS state
 *   If CTS =  1, then disable the uart TX interruptions
 *
 */
static	bool	cb_CTSCheck_C0(void) {

	return (true);
}

static	bool	cb_CTSCheck_C1(void) {

	return (true);
}

/*
 * \brief cb_init_Cx
 *
 * - Specific initialisations          __
 *   i.e the hardware CTS interruption   \__
 *
 */
static	void	cb_init_C0(void) {

}

static	void	cb_init_C1(void) {

}

// Connect the physical device to the logical manager
// --------------------------------------------------

#define	USART_C0				uart2
#define	USART_C1				uart1
#define	USART_VECTOR_NUMBER_C0	EINT_UART2_INTERRUPT
#define	USART_VECTOR_NUMBER_C1	EINT_UART1_INTERRUPT
#define	USART_FREQUENCY_C0		KFREQUENCY_UART
#define	USART_FREQUENCY_C1		KFREQUENCY_UART
#define	KUSART_SEMAPHORE_RX_C0	KURT0_SEMAPHORE_RX
#define	KUSART_SEMAPHORE_RX_C1	KURT0_SEMAPHORE_RX
#define	KUSART_SEMAPHORE_TX_C0	KURT0_SEMAPHORE_TX
#define	KUSART_SEMAPHORE_TX_C1	KURT0_SEMAPHORE_TX

#define	KUSART_SZ_TX_BUF_C0		1024u
#define	KUSART_SZ_TX_BUF_C1		1024u
#define	KUSART_SZ_RX_BUF_C0		1024u
#define	KUSART_SZ_RX_BUF_C1		1024u

#define	KUSART_SEMA_RX_C0_S
#define	KUSART_SEMA_RX_C1_S
#define	KUSART_SEMA_TX_C0_S
#define	KUSART_SEMA_TX_C1_S

#include	"model_usart_C0.c_inc"
#include	"model_usart_C1.c_inc"

int32_t	stub_urt0_init(void) {
	uint32_t	core;
	int32_t		status;

	core = GET_RUNNING_CORE;

	if (core == KCORE_0) { status = model_usart_init_C0(); }
	else				 { status = model_usart_init_C1(); }
	return (status);
}

int32_t	stub_urt0_configure(const urtxCnf_t *configure) {
	uint32_t	core;
	int32_t		status;

	core = GET_RUNNING_CORE;

	if (core == KCORE_0) { status = model_usart_configure_C0(configure); }
	else				 { status = model_usart_configure_C1(configure); }
	return (status);
}

int32_t	stub_urt0_write(const uint8_t *buffer, uint32_t size) {
	uint32_t	core;
	int32_t		status;

	core = GET_RUNNING_CORE;

	if (core == KCORE_0) { status = model_usart_write_C0(buffer, size); }
	else				 { status = model_usart_write_C1(buffer, size); }
	return (status);
}

int32_t	stub_urt0_read(uint8_t *buffer, uint32_t *size) {
	uint32_t	core;
	int32_t		status;

	core = GET_RUNNING_CORE;

	if (core == KCORE_0) { status = model_usart_read_C0(buffer, size); }
	else				 { status = model_usart_read_C1(buffer, size); }
	return (status);
}

int32_t	stub_urt0_flush(void) {
	uint32_t	core;
	int32_t		status;

	core = GET_RUNNING_CORE;

	if (core == KCORE_0) { status = model_usart_flush_C0(); }
	else				 { status = model_usart_flush_C1(); }
	return (status);
}
