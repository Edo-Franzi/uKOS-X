/*
; storage.
; ========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		storage manager.
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
 * \defgroup storage Storage
 *
 * \brief Storage
 *
 * Storage management
 *
 * @{
 */

typedef	enum {
			KSDCARD		  = (((uint32_t)'s'<<24u) | ((uint32_t)'d'<<16u) | ((uint32_t)'c'<<8u) | (uint32_t)'d'),	// sdcard manager
			KSERIAL_FLASH = (((uint32_t)'s'<<24u) | ((uint32_t)'f'<<16u) | ((uint32_t)'l'<<8u) | (uint32_t)'h')		// serial flash manager
} storage_manager_t;

// For ioctl (!! Maintain the same order than suggested by FatFs)

typedef enum {
		KGET_CNTRL_SYNC = 0,																						// Not supported
		KGET_SECTOR_COUNT,																							// Sector count
		KGET_SECTOR_SIZE,																							// Sector site
		KGET_BLOCK_SIZE,																							// Block size (1)
		KGET_CTRL_TRIM																								// Not supported
} storageIoctl_t;

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	STORAGE_reserve		storage_reserve
#define	STORAGE_release		storage_release

/*!
 * \brief Reserve the storage manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = storage_reserve(KSERIAL_FLASH, KMODE_READ_WRITE, 1234);
 *    ....
 *    storage__xyz();
 *    ....
 *    status = storage_release(KSERIAL_FLASH, KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	manager				Storage manager
 * \param[in]	reserveMode			Any mode
 * \param[in]	timeout				Timeout (1-ms of resolution)
 * \param[in]	-					KWAIT_INFINITY, waiting forever
 * \param[in]	-					KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_FLASH_XXXXX	Depends on the "xxxx" device manager
 *
 */
extern	int32_t	storage_reserve(storage_manager_t manager, reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the storage manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = storage_release(KSERIAL_FLASH, KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	manager				Storage manager
 * \param[in]	reserveMode			Any mode
 * \return		KERR_STORAGE_XXXXX	Depends on the "xxxx" device manager
 *
 */
extern	int32_t	storage_release(storage_manager_t manager, reserveMode_t reserveMode);

/*!
 * \brief Initialise the storage manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = storage_initialise(KSERIAL_FLASH, nullptr);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]	manager				Storage manager
 * \param[in]	*specification		Ptr on the sdcard specification
 * \return		KERR_STORAGE_XXXXX	Depends on the "xxxx" device manager
 *
 */
extern	int32_t	storage_initialise(storage_manager_t manager, void *specification);

/*!
 * \brief Read the status of the storage manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = storage_readStatus();
 * \endcode
 *
 * \param[in]	manager				Storage manager
 * \return		KERR_STORAGE_XXXXX	Depends on the "xxxx" device manager
 *
 */
extern	int32_t	storage_readStatus(storage_manager_t manager);

/*!
 * \brief Read 1 or more sectors from the storage manager
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KNB_BYTES    53423
 *
 * int32_t    status;
 * int8_t     readBuffer[KNB_BYTES];
 *
 *    status = storage_read(KSERIAL_FLASH, &readBuffer[], KNB_BYTES, 5);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]	manager				Storage manager
 * \param[in]	*buffer				Ptr on the buffer
 * \param[in]	size				Number of bytes to read
 * \param[in]	sector				Start sector
 * \return		KERR_STORAGE_XXXXX	Depends on the "xxxx" device manager
 *
 */
extern	int32_t	storage_read(storage_manager_t manager, uint8_t *buffer, uint32_t size, uint32_t sector);

/*!
 * \brief Write 1 or more sectors to the storage manager
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KNB_BYTES    53423
 *
 *          int32_t    status;
 * const    int8_t     writeBuffer[KNB_BYTES];
 *
 *    status = storage_write(KSERIAL_FLASH, &writeBuffer[], KNB_BYTES, 5);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]	manager				Storage manager
 * \param[in]	*buffer				Ptr on the buffer
 * \param[in]	size				Number of bytes to write
 * \param[in]	sector				Start sector
 * \return		KERR_STORAGE_XXXXX	Depends on the "xxxx" device manager
 *
 */
extern	int32_t	storage_write(storage_manager_t manager, const uint8_t *buffer, uint32_t size, uint32_t sector);

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
 *    status = storage_ioctl(KSERIAL_FLASH, KGET_BLOCK_SIZE, buffer);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 * \endcode
 *
 * \param[in]	manager				Storage manager
 * \param[in]	command				Command
 * \param[in]	*buffer				Ptr on the buffer
 * \return		KERR_STORAGE_XXXXX	Depends on the "xxxx" device manager
 *
 */
extern	int32_t	storage_ioctl(storage_manager_t manager, storageIoctl_t command, void *buffer);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
