/*
; cdc0.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		cdc0 manager.
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
 * \addtogroup Lib_serials
 */
/**@{*/

/*!
 * \defgroup cdc0 Cdc0
 *
 * \brief Cdc0
 *
 * Cdc0 management
 *
 * @{
 */

#include	"Lib_serials/serial_common.h"

// Semaphores
// ----------

#define	KCDC0_SEMAPHORE_RX		"cdc0 - RX char"
#define	KCDC0_SEMAPHORE_TX		"cdc0 - TX buff"
#define	KCDC0_MUTEX_RESERVE_RX	"Reserve_cdc0_R"
#define	KCDC0_MUTEX_RESERVE_TX	"Reserve_cdc0_T"

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	CDC0_reserve	cdc0_reserve
#define	CDC0_release	cdc0_release

/*!
 * \brief Reserve the cdc0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = cdc0_reserve(KMODE_WRITE, 1234);
 *    ....
 *    cdc0_xyz();
 *    ....
 *    status = cdc0_release(KMODE_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode			KMODE_READ, KMODE_WRITE, KMODE_READ_WRITE
 * \param[in]	timeout				Timeout (1-ms of resolution)
 *									KWAIT_INFINITY, waiting forever
 *									KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_SERIAL_NOERR	The manager is reserved
 * \return		KERR_SERIAL_GEERR	General error
 * \return		KERR_SERIAL_CHBSY	The manager is busy
 *
 */
extern	int32_t	cdc0_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the cdc0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = cdc0_release(KMODE_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode			KMODE_READ, KMODE_WRITE, KMODE_READ_WRITE
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_GEERR	General error
 * \return		KERR_SERIAL_CAREL	Cannot release the manager
 *
 */
extern	int32_t	cdc0_release(reserveMode_t reserveMode);

/*!
 * \brief Configure the cdc0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t       status;
 * const    cdcxCnf_t    configure = {
 *                              .oKernSync = (1u<<BSERIAL_SEMAPHORE_RX),
 *                        };
 *
 *    status = cdc0_configure(&configure);
 * \endcode
 *
 * \param[in]	*configure			Ptr on the configuration buffer
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_GEERR	General error
 * \return		KERR_SERIAL_NOCNF	The configuration does not exist
 *
 */
extern	int32_t	cdc0_configure(const cdcxCnf_t *configure);

/*!
 * \brief Write a buffer to the cdc0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KSIZE    10
 *
 * uint8_t    buffer[KSIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
 * int32_t    status;
 *
 *    status = cdc0_write(buffer, KSIZE);
 * \endcode
 *
 * \param[in]	*buffer				Ptr on the buffer
 * \param[in]	size				Size of the buffer
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_GEERR	General error
 * \return		KERR_SERIAL_SEPRO	The sender is busy
 * \return		KERR_SERIAL_LNBUB	The buffer length is too big
 * \return		KERR_SERIAL_LNBU0	The buffer length is = 0
 *
 */
extern	int32_t	cdc0_write(const uint8_t *buffer, uint32_t size);

/*!
 * \brief Read a buffer from the cdc0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * uint8_t     buffer[1];
 * uint32_t    size;
 * int32_t     status;
 *
 *    size = 1;
 *    status = cdc0_read(buffer, &size);
 * \endcode
 *
 * \param[in]		*buffer				Ptr on the buffer
 * \param[in, out]	*size				Ptr on the size
 * \return			KERR_SERIAL_NOERR	OK
 * \return			KERR_SERIAL_GEERR	General error
 * \return			KERR_SERIAL_RBUEM	The receiver buffer is empty
 * \return			KERR_SERIAL_RBFUL	The receiver buffer is full
 * \return			KERR_SERIAL_EROVR	Overrun error
 * \return			KERR_SERIAL_ERNOI	Noise error
 * \return			KERR_SERIAL_ERFRA	Framing error
 * \return			KERR_SERIAL_ERPAR	Parity error
 *
 */
extern	int32_t	cdc0_read(uint8_t *buffer, uint32_t *size);

/*!
 * \brief Get the semaphore identifier
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * char_t     *identifier[2];
 *
 *    status = cdc0_getIdSemaphore(BSERIAL_SEMAPHORE_RX, &identifier[0];
 *    status = cdc0_getIdSemaphore(BSERIAL_SEMAPHORE_TX, &identifier[1];
 *
 *    (void)dprintf(KSYST, "Semaphore ids: %s, ...%s\n", identifier[0], identifier[1]);
 * \endcode
 *
 * \param[in]	semaphore			RX or TX semaphore
 * \param[out]	**identifier		Ptr on the semaphore identifier
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_GEERR	General error
 * \return		KERR_SERIAL_SENOE	The semaphore does not exist
 *
 */
extern	int32_t	cdc0_getIdSemaphore(uint8_t semaphore, char_t **identifier);

/*!
 * \brief Flush the cdc0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = cdc0_flush();
 * \endcode
 *
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_GEERR	General error
 *
 */
extern	int32_t	cdc0_flush(void);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
