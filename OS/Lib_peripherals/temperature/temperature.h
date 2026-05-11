/*
; temperature.
; ============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		temperature manager.
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
 * \defgroup temperature Temperature
 *
 * \brief Temperature
 *
 * Temperature management
 *
 * @{
 */

// Semaphores
// ----------

#define	KTEMPERATURE_MUTEX_RESERVE	"Reserve_temperature"

#define	KTEMPERATURE_ZERO_KELVIN	((float64_t)(-273.16))

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	TEMPERATURE_reserve	temperature_reserve
#define	TEMPERATURE_release	temperature_release

/*!
 * \brief Reserve the temperature manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = temperature_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    temperature_xyz();
 *    ....
 *    status = temperature_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode				Any mode
 * \param[in]	timeout					Timeout (1-ms of resolution)
 *										KWAIT_INFINITY, waiting forever
 *										KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_TEMPERATURE_NOERR	The manager is reserved
 * \return		KERR_TEMPERATURE_GEERR	General error
 * \return		KERR_TEMPERATURE_CHBSY	The manager is busy
 *
 */
extern	int32_t	temperature_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the temperature manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = temperature_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode				Any mode
 * \return		KERR_TEMPERATURE_NOERR	OK
 * \return		KERR_TEMPERATURE_GEERR	General error
 * \return		KERR_TEMPERATURE_CAREL	Cannot release the manager
 *
 */
extern	int32_t	temperature_release(reserveMode_t reserveMode);

/*!
 * \brief Get the temperature (K)
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * float64_t    temperature;
 *
 *    status = temperature_read(&temperature);
 *
 *    (void)dprintf(KSYST, "Temp = %f\n", temperature);
 * \endcode
 *
 * \param[out]	*temperature			Ptr on the temperature
 * \return		KERR_TEMPERATURE_NOERR	OK
 * \return		KERR_TEMPERATURE_GEERR	General error
 *
 */
extern	int32_t	temperature_read(float64_t *temperature);

/*!
 * \brief Set the temperature (K)
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * float64_t    temperature = 37.7 - KTEMPERATURE_ZERO_KELVIN;
 *
 *    status = temperature_write(temperature);
 * \endcode
 *
 * \param[in]	temperature				The temperature
 * \return		KERR_TEMPERATURE_NOERR	OK
 * \return		KERR_TEMPERATURE_GEERR	General error
 *
 */
extern	int32_t	temperature_write(float64_t temperature);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
