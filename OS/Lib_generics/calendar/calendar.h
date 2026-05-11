/*
; calendar.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		calendar manager.
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

#pragma	once

/*!
 * \addtogroup Lib_generics
 */
/**@{*/

/*!
 * \defgroup calendar Calendar
 *
 * \brief Calendar
 *
 * Calendar management
 *
 * @{
 */

// Modifiable in the makefile: default calendar parameters

#if (!defined(KCALENDAR_WITH_HW_RTC_S))
#define	KCALENDAR_WITH_HW_RTC_S		false
#endif

typedef	enum {
			KFROM_TIMER = 0u,									// Time from the internal timer
			KFROM_RTC											// Time from the RTC
} calendarFromTimer_t;

#if (defined(__cplusplus))
extern	"C" {
#endif

/*!
 * \brief Set UTC
 *
 * Call example in C:
 *
 * \code{.c}
 * char_t     utcLocation[] = { "CET+1"};
 * int32_t    status;
 *
 *    status = calendar_setUTCLocation(&utcLocation[0]);
 * \endcode
 *
 * \param[out]	*utcLocation		Ptr on the UTC location
 * \return		KERR_CALENDAR_NOERR	OK
 *
 */
extern	int32_t	calendar_setUTCLocation(const char_t *utcLocation);

/*!
 * \brief Write the Unix time
 *
 * Call example in C:
 *
 * \code{.c}
 * uint64_t    unixTime;
 * int32_t     status;
 *
 *    status = calendar_writeUnixTime(unixTime);
 * \endcode
 *
 * \param[out]	unixTime			Unix time
 * \return		KERR_CALENDAR_NOERR	OK
 *
 */
extern	int32_t	calendar_writeUnixTime(uint64_t unixTime);

/*!
 * \brief Read the Unix time
 *
 * Call example in C:
 *
 * \code{.c}
 * uint64_t    unixTime;
 * int32_t     status;
 *
 *    status = calendar_readUnixTime(KFROM_TIMER, &unixTime);
 * \endcode
 *
 * \param[in]	fromTimer			KFROM_TIMER, use the Unix time from the Timer (normal mode)
 *									KFROM_RTC, use the Unix time from the RTC (used for better precision)
 * \param[out]	*unixTime			Ptr on the Unix time
 * \return		KERR_CALENDAR_NOERR	OK
 *
 */
extern	int32_t	calendar_readUnixTime(calendarFromTimer_t fromTimer, uint64_t *unixTime);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
