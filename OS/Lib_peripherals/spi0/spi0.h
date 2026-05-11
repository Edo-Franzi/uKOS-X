/*
; spi0.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		spi0 manager.
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
 * \defgroup spi0 Spi0
 *
 * \brief Spi0
 *
 * Spi0 management
 *
 * @{
 */

#include	"Lib_peripherals/spi_common.h"

// Semaphores
// ----------

#define	KSPI0_MUTEX_RESERVE			"Reserve_spi0"

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	SPI0_reserve	spi0_reserve
#define	SPI0_release	spi0_release

/*!
 * \brief Reserve the spi0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = spi0_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    spi0_xyz();
 *    ....
 *    status = spi0_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \param[in]	timeout			Timeout (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_SPI_NOERR	The manager is reserved
 * \return		KERR_SPI_GEERR	General error
 * \return		KERR_SPI_CHBSY	The manager is busy
 *
 */
extern	int32_t	spi0_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the spi0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = spi0_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \return		KERR_SPI_NOERR	OK
 * \return		KERR_SPI_GEERR	General error
 * \return		KERR_SPI_CAREL	Cannot release the manager
 *
 */
extern	int32_t	spi0_release(reserveMode_t reserveMode);

/*!
 * \brief Configure the spi0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t       status;
 * const    spiCnf_t    configure = {
 *                            .oSpeed    = 5000000u,
 *                            .oMode     = (uint8_t)KSPI_MASTER,
 *                            .oClock    = (1u<<(uint8_t)BSPI_POL) | (1u<<(uint8_t)BSPI_PHA)
 *                        };
 *
 *    status = spi0_configure(&configure);
 * \endcode
 *
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_SPI_NOERR	OK
 * \return		KERR_SPI_GEERR	General error
 *
 */
extern	int32_t	spi0_configure(const spiCnf_t *configure);

/*!
 * \brief Write-Read a byte to-from the spi0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * uint8_t    data;
 *
 *    data = 0x34;
 *    status = spi0_writeRead(&data);
 * \endcode
 *
 * \param[in]	*data			Ptr on the data to write-read
 * \return		KERR_SPI_NOERR	OK
 * \return		KERR_SPI_GEERR	General error
 *
 */
extern	int32_t	spi0_writeRead(uint8_t *data);

/*!
 * \brief Generic, multiple Write-Read bytes to-from the spi0 manager
 *
 * Supported transfers
 *
 * Simple reads: spi_multipleWriteRead(xyz, 0, &rBuffer[0], 20, KWAIT_INFINITY);			R, R, R, ..
 * Writes-reads: spi_multipleWriteRead(xyz, 20, &rBuffer[0], 20, KWAIT_INFINITY);			W, R, W, ..
 *				 condition (wSize == rSize)
 *				 if xyz == nullptr, write 0x00
 *				 if xyz == (&wBuffer[0], write the buffer content
 *
 * EEPROM mode:  spi_multipleWriteRead(&wBuffer[0], 4, &rBuffer[0], 20, KWAIT_INFINITY);	W, W, W, R, R, R, R, ..
 *				 condition (wSize != rSize)
 *
 * Call example in C:
 *
 * \code{.c}
 * // Reading 1024 bytes from an SPI EEPROM
 *
 * #define    KCMD_READ    0x03
 * #define    KADD_MLSB    0x00
 * #define    KADD_LMSB    0x10
 * #define    KADD_LLSB    0x00
 *
 * int32_t    status;
 * uint8_t    wBuffer[4] = { KCMD_READ, KADD_MLSB, KADD_LMSB, KADD_LLSB };
 * uint8_t    rBuffer[1024];
 *
 * ...
 * status = spi_multipleWriteRead(&wBuffer[0], 4, &rBuffer[0], 1024, KWAIT_INFINITY);
 * ...
 *
 * \endcode
 *
 * \param[in]	*wData			Ptr on the data to write
 * \param[in]	wSize			Size of the write buffer
 * \param[in]	*rData			Ptr on the data to read
 * \param[in]	rSize			Size of the read buffer
 * \param[in]	timeout			Timeout (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_SPI_NOERR	OK
 * \return		KERR_SPI_GEERR	General error
 * \return		KERR_SPI_TIMEO	Timeout error
 *
 */
extern	int32_t	spi0_multipleWriteRead(const uint8_t *wData, uint16_t wSize, uint8_t *rData, uint16_t rSize, uint32_t timeout);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
