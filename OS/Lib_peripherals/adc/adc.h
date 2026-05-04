/*
; adc.
; ====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		adc manager.
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
 * \defgroup adc Adc
 *
 * \brief Adc
 *
 * Adc management
 *
 * @{
 */

// Semaphores
// ----------

#define	KADC_MUTEX_RESERVE		"Reserve_adc"

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	ADC_reserve		adc_reserve
#define	ADC_release		adc_release

/*!
 * \brief Reserve the adc manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = adc_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    adc_xyz();
 *    ....
 *    status = adc_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \param[in]	timeout			Timeout (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_ADC_NOERR	The manager is reserved
 * \return		KERR_ADC_GEERR	General error
 * \return		KERR_ADC_CHBSY	The manager is busy
 *
 */
extern	int32_t	adc_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the adc manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = adc_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \return		KERR_ADC_NOERR	OK
 * \return		KERR_ADC_GEERR	General error
 * \return		KERR_ADC_CAREL	Cannot release the manager
 *
 */
extern	int32_t	adc_release(reserveMode_t reserveMode);

/*!
 * \brief Read an analog channel
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * float64_t    reference, result[6];
 * uint8_t      channel;
 *
 *    for (channel = 0; channel < 6; channel++) {
 *        status = adc_read(channel, &reference, &result[channel]);
 *        if (status != KERR_ADC_NOERR) {
 *            return (status);
 *        }
 *    }
 * \endcode
 *
 * \param[in]	channel			Channel (0..n)
 * \param[out]	*reference		Ptr on the reference of the A/D
 * \param[out]	*data			Ptr on the conversion result
 * \return		KERR_ADC_NOERR	OK
 * \return		KERR_ADC_GEERR	General error
 * \return		KERR_ADC_NODEV	The selected channel does not exist
 *
 */
extern	int32_t	adc_read(uint8_t channel, float64_t *reference, float64_t *data);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
