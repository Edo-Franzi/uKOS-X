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

#include	"uKOS.h"

#if (defined(CONFIG_MAN_FLASH_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"flash        flash manager.                            (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "flash manager\n"
									"=============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Flash,							// Module name (the first letter has to be upper case)
	KID_FAM_STORAGE,				// Family (defined in the module.h)
	KNUM_FLASH,						// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

static	mutx_t		*vMutex_Reserve[KNB_CORES];

// Prototypes

extern	int32_t		stub_flash_init(void);
extern	int32_t		stub_flash_initialise(void);
extern	int32_t		stub_flash_isPresent(void);
extern	int32_t		stub_flash_read(uint8_t *buffer, uint32_t size, uint32_t sector);
extern	int32_t		stub_flash_write(const uint8_t *buffer, uint32_t size, uint32_t sector);
extern	int32_t		stub_flash_ioctl(storageIoctl_t command, void *buffer);
static	int32_t		local_init(void);

/*
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
int32_t	flash_reserve([[maybe_unused]] reserveMode_t reserveMode, uint32_t timeout) {
	int32_t		status;
	uint32_t	core;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = kern_lockMutex(vMutex_Reserve[core], timeout);
	if (status != KERR_KERN_NOERR) {
		PRIVILEGE_RESTORE;
		return (KERR_STORAGE_CHBSY);
	}

	PRIVILEGE_RESTORE;
	return (KERR_STORAGE_NOERR);
}

/*
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
int32_t	flash_release([[maybe_unused]] reserveMode_t reserveMode) {
	int32_t		status;
	uint32_t	core;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = kern_unlockMutex(vMutex_Reserve[core]);
	if (status != KERR_KERN_NOERR) {
		PRIVILEGE_RESTORE;
		return (KERR_STORAGE_CAREL);
	}

	PRIVILEGE_RESTORE;
	return (KERR_STORAGE_NOERR);
}

/*
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
int32_t	flash_initialise(void) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_flash_initialise();
	PRIVILEGE_RESTORE;
	return (status);
}

/*
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
int32_t	flash_isPresent(void) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_flash_isPresent();
	PRIVILEGE_RESTORE;
	return (status);
}

/*
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
int32_t	flash_read(uint8_t *buffer, uint32_t size, uint32_t sector) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_flash_read(buffer, size, sector);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
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
int32_t	flash_write(const uint8_t *buffer, uint32_t size, uint32_t sector) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_flash_write(buffer, size, sector);
	PRIVILEGE_RESTORE;
	return (status);
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
int32_t	flash_ioctl(storageIoctl_t command, void *buffer) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_flash_ioctl(command, buffer);
	PRIVILEGE_RESTORE;
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
static	int32_t	local_init(void) {
			int32_t		status = KERR_STORAGE_NOERR;
			uint32_t	core;
	static	bool		vInit[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vInit[core] == false) {
		vInit[core] = true;

		if (kern_createMutex(KFLASH_MUTEX_RESERVE, &vMutex_Reserve[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "flash: create mutx"); exit(EXIT_OS_PANIC); }

		status = stub_flash_init();
	}
	RETURN_INT_RESTORE(status);
}

#endif
