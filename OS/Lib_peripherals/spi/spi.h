/*
; spi.
; ====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		spi manager.
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
 * \defgroup spi Spi
 *
 * \brief Spi
 *
 * Spi management
 *
 * @{
 */

#include	"Lib_peripherals/spi_common.h"

typedef	enum {
			KSPI0 = (((uint32_t)'s'<<24u) | ((uint32_t)'p'<<16u) | ((uint32_t)'i'<<8u) | (uint32_t)'0'),	// spi0 manager
			KSPI1 = (((uint32_t)'s'<<24u) | ((uint32_t)'p'<<16u) | ((uint32_t)'i'<<8u) | (uint32_t)'1'),	// spi1 manager
			KSPI2 = (((uint32_t)'s'<<24u) | ((uint32_t)'p'<<16u) | ((uint32_t)'i'<<8u) | (uint32_t)'2'),	// spi2 manager
			KSPI3 = (((uint32_t)'s'<<24u) | ((uint32_t)'p'<<16u) | ((uint32_t)'i'<<8u) | (uint32_t)'3')		// spi3 manager
} spiManager_t;

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	SPI_reserve		spi_reserve
#define	SPI_release		spi_release

/*!
 * \brief Reserve the spi manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = spi_reserve(KSPI0, KMODE_READ_WRITE, 1234);
 *    ....
 *    spi_xyz(KSPI0, );
 *    ....
 *    status = spi_release(KSPI0, KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	manager			SPI manager
 * \param[in]	reserveMode		Any mode
 * \param[in]	timeout			Timeout (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_SPI_XXXXX	Depends on the "xxxx" device manager
 *
 */
extern	int32_t	spi_reserve(spiManager_t manager, reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the spi manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = spi_release(KSPI0, KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	manager			SPI manager
 * \param[in]	reserveMode		Any mode
 * \return		KERR_SPI_XXXXX	Depends on the "xxxx" device manager
 *
 */
extern	int32_t	spi_release(spiManager_t manager, reserveMode_t reserveMode);

/*!
 * \brief Configure the spi manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t       status;
 * const    spiCnf_t     configure = {
 *                            .oSpeed    = 5000000u,
 *                            .oMode     = (uint8_t)KSPI_MASTER,
 *                            .oClock    = (1u<<(uint8_t)BSPI_POL) | (1u<<(uint8_t)BSPI_PHA)
 *                        };
 *
 *    status = spi_configure(KSPI0, &configure);
 * \endcode
 *
 * \param[in]	manager			SPI manager
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_SPI_XXXXX	Depends on the "xxxx" device manager
 *
 */
extern	int32_t	spi_configure(spiManager_t manager, const spiCnf_t *configure);

/*!
 * \brief Write-Read a byte to-from the spi manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * uint8_t    data;
 *
 *    data = 0x34;
 *    status = spi_writeRead(KSPI0, &data);
 * \endcode
 *
 * \param[in]	manager			SPI manager
 * \param[in]	*data			Ptr on the data to write-read
 * \return		KERR_SPI_XXXXX	Depends on the "xxxx" device manager
 *
 */
extern	int32_t	spi_writeRead(spiManager_t manager, uint8_t *data);

/*!
 * \brief Generic, multiple Write-Read bytes to-from the spi manager
 *
 * Supported transfers
 *
 * Simple reads: spi_multipleWriteRead(KSPI0, 0,  &rBuffer[0], 20, KWAIT_INFINITY); R, R, R, ..
 * Writes-reads: spi_multipleWriteRead(KSPI0, 20, &rBuffer[0], 20, KWAIT_INFINITY); W, R, W, ..
 *				 condition (wSize == rSize)
 *				 if xyz == nullptr, write 0x00
 *				 if xyz == (&wBuffer[0], write the buffer content
 *
 * EEPROM mode:  spi_multipleWriteRead(KSPI0, &wBuffer[0], 4, &rBuffer[0], 20, KWAIT_INFINITY); W, W, W, R, R, R, R, ..
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
 * status = spi_multipleWriteRead(KSPI0, &wBuffer[0], 4, &rBuffer[0], 1024, KWAIT_INFINITY);
 * ...
 *
 * \endcode
 *
 * \param[in]	manager			SPI manager
 * \param[in]	*wData			Ptr on the data to write
 * \param[in]	wSize			Size of the write buffer
 * \param[in]	*rData			Ptr on the data to read
 * \param[in]	rSize			Size of the read buffer
 * \param[in]	timeout			Timeout (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_SPI_XXXXX	Depends on the "xxxx" device manager
 *
 */
extern	int32_t	spi_multipleWriteRead(spiManager_t manager, const uint8_t *wData, uint16_t wSize, uint8_t *rData, uint16_t rSize, uint32_t timeout);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
