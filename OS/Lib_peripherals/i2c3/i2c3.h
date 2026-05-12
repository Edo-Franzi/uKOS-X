/*
; i2c3.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		i2c3 manager.
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
 * \defgroup i2c3 I2c3
 *
 * \brief I2c3
 *
 * I2c3 management
 *
 * @{
 */

#include	"Lib_peripherals/i2c_common.h"

// Semaphores
// ----------

#define	KI2C3_SEMAPHORE_RX		"i2c3 - RX msg"
#define	KI2C3_SEMAPHORE_TX		"i2c3 - TX msb"
#define	KI2C3_MUTEX_RESERVE		"Reserve_i2c3"

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	I2C3_reserve	i2c3_reserve
#define	I2C3_release	i2c3_release

/*!
 * \brief Reserve the i2c3 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = i2c3_reserve(KMODE_READ_WRITE, 1234u);
 *    ....
 *    i2c3_xyz();
 *    ....
 *    status = i2c3_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \param[in]	timeout			Timeout (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_I2C_NOERR	The manager is reserved
 * \return		KERR_I2C_GEERR	General error
 * \return		KERR_I2C_CHBSY	The manager is busy
 *
 */
extern	int32_t	i2c3_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the i2c3 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = i2c3_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \return		KERR_I2C_NOERR	OK
 * \return		KERR_I2C_GEERR	General error
 * \return		KERR_I2C_CAREL	Cannot release the manager
 *
 */
extern	int32_t	i2c3_release(reserveMode_t reserveMode);

/*!
 * \brief Configure the i2c3 manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t       status;
 * const    i2cCnf_t    configure = {
 *                            .oTimeout  = 1000u;
 *                            .oSpeed    = KI2C_100KBPS;
 *                        };
 *
 *    status = i2c3_configure(&configure);
 * \endcode
 *
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_I2C_NOERR	OK
 * \return		KERR_I2C_GEERR	General error
 *
 */
extern	int32_t	i2c3_configure(const i2cCnf_t *configure);

/*!
 * \brief Write a buffer to the i2c3 manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 * const    uint8_t    buffer[7] = { 1, 2, 3, 4, 5, 6, 7 };
 *
 *    status = i2c3_write(0x34, buffer, sizeof(buffer));
 * \endcode
 *
 * \param[in]	address			i2c device address
 * \param[in]	*buffer			Ptr on the buffer
 * \param[in]	size			Size of the buffer
 * \return		KERR_I2C_NOERR	OK
 * \return		KERR_I2C_GEERR	General error
 * \return		KERR_I2C_TIMEO	Timeout error
 *
 */
extern	int32_t	i2c3_write(uint8_t address, const uint8_t *buffer, uint16_t size);

/*!
 * \brief Read a buffer from the i2c3 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * uint8_t    buffer[10];
 *
 * // Example 1: Read 10 bytes
 *
 *    buffer[0] = 0xFF;
 *    status = i2c3_read(0x34, buffer, 10);
 *
 * // Example 2: Write the register 56 and then read 2 bytes
 *
 *    buffer[0] = 56;
 *    status = i2c3_read(0x34, buffer, 2);
 * \endcode
 *
 * \param[in]	address			i2c device address
 * \param[out]	*buffer			Ptr on the buffer
 * \param[in]	size			Size of the buffer
 * \return		KERR_I2C_NOERR	OK
 * \return		KERR_I2C_GEERR	General error
 * \return		KERR_I2C_TIMEO	Timeout error
 *
 */
extern	int32_t	i2c3_read(uint8_t address, uint8_t *buffer, uint16_t size);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
