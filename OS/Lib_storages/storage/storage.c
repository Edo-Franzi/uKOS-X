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

#include	"uKOS.h"

#if (defined(CONFIG_MAN_STORAGE_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"storage      storage manager.                          (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "storage manager\n"
									"===============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Storage,						// Module name (the first letter has to be upper case)
	KID_FAM_STORAGE,				// Family (defined in the module.h)
	KNUM_STORAGE,					// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

/*
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
 *									KWAIT_INFINITY, waiting forever
 *									KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_FLASH_XXXXX	Depends on the "xxxx" device manager
 *
 */
int32_t	storage_reserve(storage_manager_t manager, reserveMode_t reserveMode, uint32_t timeout) {

	switch (manager) {

		#if (defined(CONFIG_MAN_SDCARD_S))
		case KSDCARD: { return (sdcard_reserve(reserveMode, timeout));			  }
		#endif

		#if (defined(CONFIG_MAN_SERIAL_FLASH_S))
		case KSERIAL_FLASH: { return (serialFlash_reserve(reserveMode, timeout)); }
		#endif

		default: { return (KERR_STORAGE_NODEV);									  }
	}

}

/*
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
int32_t	storage_release(storage_manager_t manager, reserveMode_t reserveMode) {

	switch (manager) {

		#if (defined(CONFIG_MAN_SDCARD_S))
		case KSDCARD: { return (sdcard_release(reserveMode));			 }
		#endif

		#if (defined(CONFIG_MAN_SERIAL_FLASH_S))
		case KSERIAL_FLASH: { return (serialFlash_release(reserveMode)); }
		#endif

		default: { return (KERR_STORAGE_NODEV);							 }
	}

}

/*
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
int32_t	storage_initialise(storage_manager_t manager, void  *specification) {

	switch (manager) {

		#if (defined(CONFIG_MAN_SDCARD_S))
		case KSDCARD: { return (sdcard_initialise((sdcard_specification_t *)specification)); }
		#endif

		#if (defined(CONFIG_MAN_SERIAL_FLASH_S))
		case KSERIAL_FLASH: { return (serialFlash_initialise());							 }
		#endif

		default: { return (KERR_STORAGE_NODEV);												 }
	}

}

/*
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
int32_t	storage_readStatus(storage_manager_t manager) {

	switch (manager) {

		#if (defined(CONFIG_MAN_SDCARD_S))
		case KSDCARD: { return (sdcard_readStatus());			 }
		#endif

		#if (defined(CONFIG_MAN_SERIAL_FLASH_S))
		case KSERIAL_FLASH: { return (serialFlash_readStatus()); }
		#endif

		default: { return (KERR_STORAGE_NODEV);					 }
	}

}

/*
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
int32_t	storage_read(storage_manager_t manager, uint8_t *buffer, uint32_t size, uint32_t sector) {

	switch (manager) {

		#if (defined(CONFIG_MAN_SDCARD_S))
		case KSDCARD: { return (sdcard_read(buffer, size, sector));			   }
		#endif

		#if (defined(CONFIG_MAN_SERIAL_FLASH_S))
		case KSERIAL_FLASH: { return (serialFlash_read(buffer, size, sector)); }
		#endif

		default: { return (KERR_STORAGE_NODEV);								   }
	}

}

/*
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
int32_t	storage_write(storage_manager_t manager, const uint8_t *buffer, uint32_t size, uint32_t sector) {

	switch (manager) {

		#if (defined(CONFIG_MAN_SDCARD_S))
		case KSDCARD: { return (sdcard_write(buffer, size, sector));			}
		#endif

		#if (defined(CONFIG_MAN_SERIAL_FLASH_S))
		case KSERIAL_FLASH: { return (serialFlash_write(buffer, size, sector)); }
		#endif

		default: { return (KERR_STORAGE_NODEV);									}
	}

}

/*
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
int32_t	storage_ioctl(storage_manager_t manager, storageIoctl_t command, void *buffer) {

	switch (manager) {

		#if (defined(CONFIG_MAN_SDCARD_S))
		case KSDCARD: { return (sdcard_ioctl(command, buffer));			   }
		#endif

		#if (defined(CONFIG_MAN_SERIAL_FLASH_S))
		case KSERIAL_FLASH: { return (serialFlash_ioctl(command, buffer)); }
		#endif

		default: { return (KERR_STORAGE_NODEV);							   }
	}

}

#endif
