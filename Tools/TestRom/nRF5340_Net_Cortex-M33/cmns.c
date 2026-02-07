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
#include	<string.h>

#define	CONFIG_DEFAULT_BAUDRATE		460800

#define	KCMNS_SZ_TX_BUF				128

static	char_t	vTxBuffer_0[KCMNS_SZ_TX_BUF];

/*
 * \brief cmns_init
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
void	cmns_init(void) {

	REG(UARTE0)->ENABLE   = 0x8u;
	REG(UARTE0)->BAUDRATE = BAUDRATE_NRF(CONFIG_DEFAULT_BAUDRATE);
	REG(UARTE0)->CONFIG   = 0;
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
	size_t	length;

	if (ascii == nullptr) { return; }

	switch (serialManager) {

// UART 0 device

		default:
		case KURT0: {
			length = strlen(ascii);
			length = (length >= KCMNS_SZ_TX_BUF) ? (KCMNS_SZ_TX_BUF) : (length);
			memcpy(vTxBuffer_0, ascii, length);

			REG(UARTE0)->TXD_PTR	   = (uint32_t)vTxBuffer_0;
			REG(UARTE0)->TXD_MAXCNT	   = (uint32_t)length;
			REG(UARTE0)->TASKS_STARTTX = 1u;

			while ((REG(UARTE0)->EVENTS_ENDTX & 1u) == 0) { ; }
			REG(UARTE0)->EVENTS_ENDTX  = 0u;
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
			REG(UARTE0)->RXD_PTR	   = (uint32_t)data;
			REG(UARTE0)->RXD_MAXCNT	   = 1u;
			REG(UARTE0)->TASKS_STARTRX = 1u;

			while ((REG(UARTE0)->EVENTS_ENDRX & 1u) == 0) { ; }
			REG(UARTE0)->EVENTS_ENDRX  = 0u;
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
	wkUs = (wkUs / 6u) * (KFREQUENCY_CORE / 1000000u);

	#else
	wkUs = (wkUs / 12u) * (KFREQUENCY_CORE / 1000000u);
	#endif

	for (time = 0; time < wkUs; time++) { NOP; }
}
