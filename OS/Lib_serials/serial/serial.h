/*
; serial.
; =======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		serial manager.
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
 * \defgroup serial Serial
 *
 * \brief Serial
 *
 * Serial management
 *
 * @{
 */

#include	"Lib_serials/serial_common.h"

// Modifiable in the makefile: default baudrate for the system

#if (!defined(KSERIAL_DEFAULT_BAUDRATE))
#define	KSERIAL_DEFAULT_BAUDRATE	460800
#endif

// Supported managers

typedef	enum {
			KNOTR = (((uint32_t)'n'<<24u) | ((uint32_t)'o'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'R'),	// notr manager
			KSYST = (((uint32_t)'s'<<24u) | ((uint32_t)'y'<<16u) | ((uint32_t)'s'<<8u) | (uint32_t)'t'),	// syst manager
			KDEF0 = (((uint32_t)'d'<<24u) | ((uint32_t)'e'<<16u) | ((uint32_t)'f'<<8u) | (uint32_t)'0'),	// def0 manager
			KURT0 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'0'),	// urt0 manager
			KURT1 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'1'),	// urt1 manager
			KURT2 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'2'),	// urt2 manager
			KURT3 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'3'),	// urt3 manager
			KURT4 = (((uint32_t)'u'<<24u) | ((uint32_t)'r'<<16u) | ((uint32_t)'t'<<8u) | (uint32_t)'4'),	// urt4 manager
			KCDC0 = (((uint32_t)'c'<<24u) | ((uint32_t)'d'<<16u) | ((uint32_t)'c'<<8u) | (uint32_t)'0'),	// cdc0 manager
			KCDC1 = (((uint32_t)'c'<<24u) | ((uint32_t)'d'<<16u) | ((uint32_t)'c'<<8u) | (uint32_t)'1'),	// cdc1 manager
			KWFI0 = (((uint32_t)'w'<<24u) | ((uint32_t)'f'<<16u) | ((uint32_t)'i'<<8u) | (uint32_t)'0')		// wfi0 manager
} serialManager_t;

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	SERIAL_reserve	serial_reserve
#define	SERIAL_release	serial_release

/*!
 * \brief Reserve the Serial Communication Manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = serial_reserve(KDEF0, KMODE_WRITE, 1234);
 *    ....
 *    serial_xyz();
 *    ....
 *    status = serial_release(KDEF0, KMODE_WRITE);
 * \endcode
 *
 * \param[in]	serialManager		Serial Communication Manager
 * \param[in]	reserveMode			KMODE_READ, KMODE_WRITE, KMODE_READ_WRITE
 * \param[in]	timeout				Timeout (1-ms of resolution)
 *									KWAIT_INFINITY, waiting forever
 *									KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_NODEV	No corresponding Serial Communication Manager
 * \return		KERR_xxxxxx_NODEV	Depends on the "xxxx" Serial Communication Manager
 *
 */
extern	int32_t	serial_reserve(serialManager_t serialManager, reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the Serial Communication Manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = serial_release(KDEF0, KMODE_WRITE);
 * \endcode
 *
 * \param[in]	serialManager		Serial Communication Manager
 * \param[in]	reserveMode			KMODE_READ, KMODE_WRITE, KMODE_READ_WRITE
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_NODEV	No corresponding Serial Communication Manager
 * \return		KERR_xxxxxx_NODEV	Depends on the "xxxx" Serial Communication Manager
 *
 */
extern	int32_t	serial_release(serialManager_t serialManager, reserveMode_t reserveMode);

/*!
 * \brief Configure the Serial Communication Manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t       status;
 * const    urtxCnf_t    configure = {
 *                            .oBaudRate = KSERIAL_BAUDRATE_57600,
 *                            .oKernSync = (1u<<BSERIAL_SEMAPHORE_RX),
 *                            .oNBBits   = KSERIAL_NB_BITS_8,
 *                            .oStopBits = KSERIAL_STOPBITS_1,
 *                            .oParity   = KSERIAL_PARITY_NONE
 *                        };
 *
 *    status = serial_configure(KURT0, (void *)&configure);
 * \endcode
 *
 * \param[in]	serialManager		Serial Communication Manager
 * \param[in]	*configure			Ptr on the configuration buffer
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_NODEV	No corresponding Serial Communication Manager
 * \return		KERR_xxxxxx_NODEV	Depends on the "xxxx" Serial Communication Manager
 *
 */
extern	int32_t	serial_configure(serialManager_t serialManager, const void *configure);

/*!
 * \brief Write a buffer to the Serial Communication Manager
 *
 * This function writes into the outgoing buffer of the specified Serial Communication Manager.
 *
 * If the outgoing buffer is not empty at the time of the function call,
 * the function may return KERR_SERIAL_SEPRO.
 *
 * If the provided buffer to transmit is larger than the Serial Communication Manager buffer,
 * the function may block until the provided buffer has been completely written into
 * the Serial Communication Manager's outgoing buffer.
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KSIZE    10
 *
 * uint8_t    buffer[KSIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
 * int32_t    status;
 *
 *    status = serial_write(KDEF0, buffer, KSIZE);
 * \endcode
 *
 * \param[in]	serialManager		Serial Communication Manager
 * \param[in]	*buffer				Ptr on the buffer
 * \param[in]	size				Size of the buffer
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_NODEV	No corresponding Serial Communication Manager
 * \return		KERR_xxxxxx_NODEV	Depends on the "xxxx" Serial Communication Manager
 *
 */
extern	int32_t	serial_write(serialManager_t serialManager, const uint8_t *buffer, uint32_t size);

/*!
 * \brief Read a buffer from the Serial Communication Manager
 *
 * This function reads a maximum of of already received bytes from the specified
 * Serial Communication Manager's incoming buffer.
 *
 * Call example in C:
 *
 * \code{.c}
 * uint8_t     buffer[1];
 * uint32_t    size;
 * int32_t     status;
 *
 *    size = 1;
 *    status = serial_read(KDEF0, buffer, &size);
 * \endcode
 *
 * \param[in]		serialManager		Serial Communication Manager
 * \param[in]		*buffer				Ptr on the buffer
 * \param[in, out]	*size				Ptr to a variable storing the size, initialized with the size of the buffer
 * \return			KERR_SERIAL_NOERR	OK
 * \return			KERR_SERIAL_NODEV	No corresponding Serial Communication Manager
 * \return			KERR_xxxxxx_NODEV	Depends on the "xxxx" Serial Communication Manager
 *
 */
extern	int32_t	serial_read(serialManager_t serialManager, uint8_t *buffer, uint32_t *size);

/*!
 * \brief Get the semaphore identifier
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * char_t     *identifier[2];
 *
 *    status = serial_getIdSemaphore(KURT0, BSERIAL_SEMAPHORE_RX, &identifier[0];
 *    status = serial_getIdSemaphore(KURT0, BURTX_SEMAPHORE_TX, &identifier[1];
 *
 *    (void)dprintf(KSYST, "Semaphore ids: %s, ...%s\n", identifier[0], identifier[1]);
 * \endcode
 *
 * \param[in]	serialManager		Serial Communication Manager
 * \param[in]	semaphore			RX or TX semaphore
 * \param[out]	**identifier		Ptr on the semaphore identifier
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_NODEV	No corresponding Serial Communication Manager
 * \return		KERR_SERIAL_SENOE	The semaphore does not exist
 * \return		KERR_xxxxxx_NODEV	Depends on the "xxxx" Serial Communication Manager
 *
 */
extern	int32_t	serial_getIdSemaphore(serialManager_t serialManager, uint8_t semaphore, char_t **identifier);

/*!
 * \brief Flush the Serial Communication Manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = serial_flush(KDEF0);
 * \endcode
 *
 * \param[in]	serialManager			Serial Communication Manager
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_NODEV	The serialManager does not exist
 *
 */
extern	int32_t	serial_flush(serialManager_t serialManager);

/*!
 * \brief Set the system-wide default Serial Communication Manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = serial_setDefSerialManager(KURT0);
 * \endcode
 *
 * \param[in]	serialManager		Serial Communication Manager
 * \return		KERR_SERIAL_NOERR	OK
 *
 */
extern	int32_t	serial_setDefSerialManager(serialManager_t serialManager);

/*!
 * \brief Get the system-wide default Serial Communication Manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    serialManager;
 *
 *    status = serial_getDefSerialManager(&serialManager);
 * \endcode
 *
 * \param[out]	*serialManager		Ptr on the Serial Communication Manager
 * \return		KERR_SERIAL_NOERR	OK
 *
 */
extern	int32_t	serial_getDefSerialManager(serialManager_t *serialManager);

/*!
 * \brief Get the father (or older) Serial Communication Manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    serialManager;
 *
 *    status = serial_getFatherSerialManager(&serialManager);
 * \endcode
 *
 * \param[out]	*serialManager		Ptr on the Serial Communication Manager
 * \return		KERR_SERIAL_NOERR	OK
 *
 */
extern	int32_t	serial_getFatherSerialManager(serialManager_t *serialManager);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
