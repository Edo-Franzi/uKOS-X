/*
; flash.
; ======
;
; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
;
;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		flash manager.
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
 * \addtogroup Lib_storages
 */
/**@{*/

/*!
 * \defgroup flash Flash
 *
 * \brief Flash
 *
 * Flash management
 *
 * @{
 */

// Semaphores
// ----------

#define	KFLASH_MUTEX_RESERVE	"Reserve_flash"

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	FLASH_reserve	flash_reserve
#define	FLASH_release	flash_release

/*!
 * \brief Reserve the flash manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = flash_reserve(KMODE_READ_WRITE, 1234u);
 *    ....
 *    flash_xyz();
 *    ....
 *    status = flash_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode			Any mode
 * \param[in]	timeout				Timeout (1-ms of resolution)
 *									KWAIT_INFINITY, waiting forever
 *									KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_STORAGE_NOERR	The manager is reserved
 * \return		KERR_STORAGE_GEERR	General error
 * \return		KERR_STORAGE_CHBSY	The manager is busy
 *
 */
extern	int32_t	flash_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the flash manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = flash_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode			Any mode
 * \return		KERR_STORAGE_NOERR	OK
 * \return		KERR_STORAGE_GEERR	General error
 * \return		KERR_STORAGE_CAREL	Cannot release the manager
 *
 */
extern	int32_t	flash_release(reserveMode_t reserveMode);

/*!
 * \brief Initialise the flash
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = flash_initialise();
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \return		KERR_STORAGE_NOERR	OK
 * \return		KERR_STORAGE_GEERR	General error
 *
 */
extern	int32_t	flash_initialise(void);

/*!
 * \brief Is the flash present
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = flash_isPresent();
 * \endcode
 *
 * \return		KERR_STORAGE_NOERR	OK
 *
 */
extern	int32_t	flash_isPresent(void);

/*!
 * \brief Read 1 or more sectors from the flash
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KNB_BYTES    53423
 *
 * int32_t    status;
 * int8_t     readBuffer[KNB_BYTES];
 *
 *    status = flash_read(&readBuffer[], KNB_BYTES, 5);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]	*buffer				Ptr on the buffer
 * \param[in]	size				Number of bytes to read
 * \param[in]	sector				Start sector
 * \return		KERR_STORAGE_NOERR	OK
 * \return		KERR_STORAGE_GEERR	General error
 * \return		KERR_STORAGE_LNBU0	The number of sectors is = 0
 *
 */
extern	int32_t	flash_read(uint8_t *buffer, uint32_t size, uint32_t sector);

/*!
 * \brief Write 1 or more sectors to the flash
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KNB_BYTES    53423
 *
 *          int32_t    status;
 * const    int8_t     writeBuffer[KNB_BYTES];
 *
 *    status = flash_write(&writeBuffer[], KNB_BYTES, 5);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]	*buffer				Ptr on the buffer
 * \param[in]	size				Number of bytes to write
 * \param[in]	sector				Start sector
 * \return		KERR_STORAGE_NOERR	OK
 * \return		KERR_STORAGE_GEERR	General error
 * \return		KERR_STORAGE_LNBU0	The number of sectors is = 0
 *
 */
extern	int32_t	flash_write(const uint8_t *buffer, uint32_t size, uint32_t sector);

/*!
 * \brief Get some storage parameters by ioctl
 *
 * Call example in C:
 *
 * \code{.c}
 * uint8_t    buffer[10];
 *
 * int32_t    status;
 *
 *    status = flash_ioctl(KGET_BLOCK_SIZE, buffer);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]	command				Command
 * \param[in]	*buffer				Ptr on the buffer
 * \return		KERR_STORAGE_NOERR	OK
 * \return		KERR_STORAGE_GEERR	General error
 *
 */
extern	int32_t	flash_ioctl(storageIoctl_t command, void *buffer);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
