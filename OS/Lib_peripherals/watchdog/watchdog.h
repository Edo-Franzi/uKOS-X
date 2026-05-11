/*
; watchdog.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		watchdog manager.
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
 * \addtogroup Lib_peripherals
 */
/**@{*/

/*!
 * \defgroup watchdog Watchdog
 *
 * \brief Watchdog
 *
 * Watchdog management
 *
 * @{
 */

// Watchdog modes
// --------------

enum {
		KWATCHDOG_AUTO = 0u,									// Mode auto (create a daemon to re-activate the watchdog)
		KWATCHDOG_MANUAL										// Mode manual (the user is responsible to re-activate the watchdog)
};

#define	KWATCHDOG_MARGIN		(0.8)							// Time margin for the watchdog process (timeProcessWatchdog = timeWatchdog * KWATCHDOG_MARGIN)
#define	KWATCHDOG_MAX_TIME_MS	32767u							// Time maximum (in ms) for the watchdog

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

/*!
 * \brief Arm the watchdog
 *
 * \warning	This function is hardware dependent
 *
 * Call example in C:
 *
 * \code{.c}
 * // KWATCHDOG_AUTO      -> Automatic mode (a daemon handles the watchdog)
 * // KWATCHDOG_MANUAL    -> Manual mode (the user handles the watchdog)
 *
 * #define    KWATCHDOG_TIME    10000    // Reset after 10000-ms
 *
 * int32_t    status;
 *
 *    status = watchdog_arm(KWATCHDOG_TIME, KWATCHDOG_AUTO);
 * \endcode
 *
 * - Generate a reset if the timer is not reactivated.
 *   The min-max time is hardware dependent (0 < time < 4294967296-ms)
 *   I.e for the stm32 series the min-max time is 8-ms < time < 32768-ms
 *   I.e for the gd32vf103 series the min-max time is 6.4 < time < 26214.4-ms
 *
 * \param[in]	time				Restart time if the watchdog is not re-activated
 * \param[in]	mode				KWATCHDOG_AUTO, create a daemon to re-activate the watchdog
 * 				-					KWATCHDOG_MANUAL, the user is responsible to re-activate the watchdog
 * \return		KERR_WATCHDOG_NOERR	OK
 *
 */
extern	int32_t	watchdog_arm(uint32_t time, uint8_t mode);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
