/*
; sdcard.
; =======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		sdcard manager.
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

#if (defined(CONFIG_MAN_SDCARD_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"sdcard       sdcard manager.                           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "sdcard manager\n"
									"==============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Sdcard,							// Module name (the first letter has to be upper case)
	KID_FAM_STORAGE,				// Family (defined in the module.h)
	KNUM_SDCARD,					// Module identifier (defined in the module.h)
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

extern	int32_t		stub_sdcard_init(void);
extern	int32_t		stub_sdcard_initialise(sdcard_specification_t *specification);
extern	int32_t		stub_sdcard_readStatus(void);
extern	int32_t		stub_sdcard_read(const sdcard_specification_t *specification, uint8_t *buffer, uint8_t nbSectors, uint32_t sector);
extern	int32_t		stub_sdcard_write(const sdcard_specification_t *specification, const uint8_t *buffer, uint8_t nbSectors, uint32_t sector);
extern	int32_t		stub_sdcard_ioctl(storageIoctl_t command, void *buffer);
static	int32_t		local_init(void);
static	int32_t		local_sdcard_read(const sdcard_specification_t *specification, uint8_t *buffer, uint8_t nbSectors, uint32_t sector);
static	int32_t		local_sdcard_write(const sdcard_specification_t *specification, const uint8_t *buffer, uint8_t nbSectors, uint32_t sector);

/*
 * \brief Reserve the sdcard manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = sdcard_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    sdcard_xyz();
 *    ....
 *    status = sdcard_release(KMODE_READ_WRITE);
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
int32_t	sdcard_reserve(reserveMode_t reserveMode, uint32_t timeout) {
	int32_t		status;
	uint32_t	core;

	UNUSED(reserveMode);

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
 * \brief Release the sdcard manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = sdcard_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode			Any mode
 * \return		KERR_STORAGE_NOERR	OK
 * \return		KERR_STORAGE_GEERR	General error
 * \return		KERR_STORAGE_CAREL	Cannot release the manager
 *
 */
int32_t	sdcard_release(reserveMode_t reserveMode) {
	int32_t		status;
	uint32_t	core;

	UNUSED(reserveMode);

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
 * \brief Initialise the sdcard
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t                   status;
 * sdcard_specification_t    sdcard;
 *
 *    status = sdcard_initialise(&sdCard);
 *    if (status != KERR_STORAGE_NOERR) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 *
 *    if (sdcard.oCapacityStatus == KSDCARD_CT_SD1) sdcard = "sdcard V.1";
 *    else                                          sdcard = "sdcard V.2";
 * \endcode
 *
 * \param[in]	*specification		Ptr on the sdcard specification
 * \return		KERR_STORAGE_NOERR	OK
 * \return		KERR_STORAGE_GEERR	General error
 * \return		KERR_STORAGE_NODEV	No sdcard
 * \return		KERR_STORAGE_CANRE	sdcard not recognised
 *
 */
int32_t	sdcard_initialise(sdcard_specification_t *specification) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_sdcard_initialise(specification);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Read the status of the sdcard
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = sdcard_readStatus();
 * \endcode
 *
 * \return		KERR_STORAGE_NOERR	OK
 * \return		KERR_STORAGE_GEERR	General error
 * \return		KERR_STORAGE_NODEV	No sdcard
 *
 */
int32_t	sdcard_readStatus(void) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_sdcard_readStatus();
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Read 1 or more sectors from the sdcard
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KNB_BYTES    53423
 *
 * int32_t    status;
 * int8_t     readBuffer[KNB_BYTES];
 *
 *    status = sdcard_read(&readBuffer[], KNB_BYTES, 5);
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
 * \return		KERR_STORAGE_NODEV	No sdcard
 * \return		KERR_STORAGE_CANRE	sdcard not recognised
 * \return		KERR_STORAGE_LNBU0	The number of sectors is = 0
 * \return		KERR_STORAGE_TRANT	Transfer not terminated
 *
 */
int32_t	sdcard_read(uint8_t *buffer, uint32_t size, uint32_t sector) {
	int32_t					status;
	uint8_t					nbSectorsForThisCall, lastSectorBuffer[KSDCARD_SZ_SECTOR];
	uint32_t				i, nbSectors, nbBytesLastSector, wkSector;
	sdcard_specification_t	sdcard;
	uint8_t					*memory;
	size_t					inc;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return (status); }

// Read the sdcard specifications

	if (sdcard_initialise(&sdcard) != KERR_STORAGE_NOERR) {
		PRIVILEGE_RESTORE;
		return (KERR_STORAGE_NODEV);
	}

// Compute the number of sectors to read.
// We need to treat the last sector specially because
// the input buffer may not fill it fully, in which case
// we need to avoid reading beyond the last element in the buffer

	wkSector		  = sector;
	nbSectors		  = size / KSDCARD_SZ_SECTOR;
	nbBytesLastSector = size % KSDCARD_SZ_SECTOR;
	memory			  = buffer;

// Write the sectors in chunks

	while (nbSectors > 0u) {
		nbSectorsForThisCall = (nbSectors > KSDCARD_MAX_SECTORS_PER_CALL) ? (KSDCARD_MAX_SECTORS_PER_CALL) : ((uint8_t)nbSectors);

		if (local_sdcard_read(&sdcard, memory, nbSectorsForThisCall, wkSector) != KERR_STORAGE_NOERR) {
			PRIVILEGE_RESTORE;
			return (KERR_STORAGE_TRANT);
		}

		inc		  =  (size_t)nbSectorsForThisCall * (size_t)KSDCARD_SZ_SECTOR;
		memory    =  &memory[inc];
		wkSector  += (uint32_t)nbSectorsForThisCall;
		nbSectors -= (uint32_t)nbSectorsForThisCall;
	}

// Read the last sector's data, which may not fill it fully

	if (nbBytesLastSector > 0u) {
		if (local_sdcard_read(&sdcard, lastSectorBuffer, 1u, wkSector) != KERR_STORAGE_NOERR) {
			PRIVILEGE_RESTORE;
			return (KERR_STORAGE_TRANT);
		}

		for (i = 0; i < nbBytesLastSector; i++) {
			*memory = lastSectorBuffer[i];
			memory++;
		}
	}
	PRIVILEGE_RESTORE;
	return (KERR_STORAGE_NOERR);
}

/*
 * \brief Write 1 or more sectors to the sdcard
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KNB_BYTES    53423
 *
 *          int32_t    status;
 * const    int8_t     writeBuffer[KNB_BYTES];
 *
 *    status = sdcard_write(&writeBuffer[], KNB_BYTES, 5);
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
 * \return		KERR_STORAGE_NODEV	No sdcard
 * \return		KERR_STORAGE_CANRE	sdcard not recognised
 * \return		KERR_STORAGE_LNBU0	The number of sectors is = 0
 * \return		KERR_STORAGE_TRANT	Transfer not terminated
 *
 */
int32_t	sdcard_write(const uint8_t *buffer, uint32_t size, uint32_t sector) {
			int32_t					status;
			uint8_t					nbSectorsForThisCall, lastSectorBuffer[KSDCARD_SZ_SECTOR];
			uint32_t				i, nbSectors, nbBytesLastSector, wkSector;
			sdcard_specification_t	sdcard;
			size_t					inc;
	const	uint8_t					*memory;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return (status); }

// Read the sdcard specifications

	if (sdcard_initialise(&sdcard) != KERR_STORAGE_NOERR) {
		PRIVILEGE_RESTORE;
		return (KERR_STORAGE_NODEV);
	}

// Compute the number of sectors to write.
// We need to treat the last sector specially because
// the input buffer may not fill it fully, in which case
// we need to avoid writing beyond the last element in the buffer

	wkSector		  = sector;
	nbSectors		  = size / KSDCARD_SZ_SECTOR;
	nbBytesLastSector = size % KSDCARD_SZ_SECTOR;
	memory			  = buffer;

// Write the sectors in chunks.

	while (nbSectors > 0u) {
		nbSectorsForThisCall = (nbSectors > KSDCARD_MAX_SECTORS_PER_CALL) ? (KSDCARD_MAX_SECTORS_PER_CALL) : ((uint8_t)nbSectors);

		if (local_sdcard_write(&sdcard, memory, nbSectorsForThisCall, wkSector) != KERR_STORAGE_NOERR) {
			PRIVILEGE_RESTORE;
			return (KERR_STORAGE_TRANT);
		}

		inc		  =  (size_t)nbSectorsForThisCall * (size_t)KSDCARD_SZ_SECTOR;
		memory    =  &memory[inc];
		wkSector  += (uint32_t)nbSectorsForThisCall;
		nbSectors -= (uint32_t)nbSectorsForThisCall;
	}

// Write the last sector's data, which may not fill it fully
// Fill the gap with 0x00 (for test)

	if (nbBytesLastSector > 0u) {
		for (i = 0u; i < KSDCARD_SZ_SECTOR; i++) {
			lastSectorBuffer[i] = 0u;
		}
		for (i = 0u; i < nbBytesLastSector; i++) {
			lastSectorBuffer[i] = *memory;
			memory++;
		}
		if (local_sdcard_write(&sdcard, lastSectorBuffer, 1u, wkSector) != KERR_STORAGE_NOERR) {
			PRIVILEGE_RESTORE;
			return (KERR_STORAGE_TRANT);
		}

	}
	PRIVILEGE_RESTORE;
	return (KERR_STORAGE_NOERR);
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
 *    status = sdcard_ioctl(KGET_BLOCK_SIZE, buffer);
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
int32_t	sdcard_ioctl(storageIoctl_t command, void *buffer) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_STORAGE_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_sdcard_ioctl(command, buffer);
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

		if (kern_createMutex(KSDCARD_MUTEX_RESERVE, &vMutex_Reserve[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "sdcard: create mutx"); exit(EXIT_OS_PANIC); }

		status = stub_sdcard_init();
	}
	RETURN_INT_RESTORE(status);
}

/*
 * \brief local_sdcard_read
 *
 * - This function reads 1 or more sectors (<= 128)
 *
 */
static	int32_t	local_sdcard_read(const sdcard_specification_t *specification, uint8_t *buffer, uint8_t nbSectors, uint32_t sector) {
	int32_t		status;

	status = local_init();
	if (status != KERR_STORAGE_NOERR) { return (status); }

	status = stub_sdcard_read(specification, buffer, nbSectors, sector);
	return (status);
}

/*
 * \brief local_sdcard_write
 *
 * - This function writes 1 or more sectors (<= 128)
 *
 */
static	int32_t	local_sdcard_write(const sdcard_specification_t *specification, const uint8_t *buffer, uint8_t nbSectors, uint32_t sector) {
	int32_t		status;

	status = local_init();
	if (status != KERR_STORAGE_NOERR) { return (status); }

	status = stub_sdcard_write(specification, buffer, nbSectors, sector);
	return (status);
}

#endif
