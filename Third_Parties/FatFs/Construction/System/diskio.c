/*
; diskio.
; =======
;
; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
;
;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		uKOS diskio interface to the uKOS-X devices
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

#include	"types.h"
#include	"os_errors.h"
#include	"ff.h"
#include	"diskio.h"
#include	"storage.h"
#include	"sdcard.h"
#include	"sdnand.h"
#include	"flash.h"
#include	"macros.h"
#include	<time.h>

#define	KWAIT_INFINITY	((uint32_t)(-1))		// Waiting forever

[[maybe_unused]]
static	sdcard_specification_t	vSdCard;

[[maybe_unused]]
static	sdnand_specification_t	vSdNand;

enum {
		DEV_SDCARD = 0u,						// Map sdcard to physical drive 0
		DEV_SDNAND,								// Map sdnand to physical drive 1
		DEV_FLASH								// Map flash to physical drive 2
};

/*
 * \brief disk_status
 *
 * - Get the status (is present)
 *
 */
DSTATUS		disk_status(BYTE pdrv) {
	int32_t		status;
	DSTATUS		fatFsStatus = STA_NOINIT;

	switch (pdrv) {
		#if (defined(SDCARD_S))
		case DEV_SDCARD: {
			RESERVE(SDCARD, KMODE_READ_WRITE);
			status = storage_isPresent(KSDCARD);
			RELEASE(SDCARD, KMODE_READ_WRITE);

			fatFsStatus = (status == KERR_STORAGE_NOERR) ? (0) : (STA_NODISK);
			return (fatFsStatus);
		}
		#endif

		#if (defined(SDNAND_S))
		case DEV_SDNAND: {
			RESERVE(SDNAND, KMODE_READ_WRITE);
			status = storage_isPresent(KSDNAND);
			RELEASE(SDNAND, KMODE_READ_WRITE);

			fatFsStatus = (status == KERR_STORAGE_NOERR) ? (0) : (STA_NODISK);
			return (fatFsStatus);
		}
		#endif

		#if (defined(FLASH_S))
		case DEV_FLASH: {
			RESERVE(FLASH, KMODE_READ_WRITE);
			status = storage_isPresent(KFLASH);
			RELEASE(FLASH, KMODE_READ_WRITE);

			fatFsStatus = (status == KERR_STORAGE_NOERR) ? (0) : (STA_NODISK);
			return (fatFsStatus);
		}
		#endif

		default: {
			return (fatFsStatus);
		}

	}
}

/*
 * \brief disk_initialize
 *
 * - Initialise the disk
 *
 */
DSTATUS		disk_initialize(BYTE pdrv) {
	int32_t		status;
	DSTATUS		fatFsStatus = STA_NOINIT;

	switch (pdrv) {
		#if (defined(SDCARD_S))
		case DEV_SDCARD: {
			RESERVE(SDCARD, KMODE_READ_WRITE);
			status = storage_initialise(KSDCARD, &vSdCard);
			RELEASE(SDCARD, KMODE_READ_WRITE);

			fatFsStatus = (status == KERR_STORAGE_NOERR) ? (0) : (STA_NOINIT);
			return (fatFsStatus);
		}
		#endif

		#if (defined(SDNAND_S))
		case DEV_SDNAND: {
			RESERVE(SDNAND, KMODE_READ_WRITE);
			status = storage_initialise(KSDNAND, &vSdNand);
			RELEASE(SDNAND, KMODE_READ_WRITE);

			fatFsStatus = (status == KERR_STORAGE_NOERR) ? (0) : (STA_NOINIT);
			return (fatFsStatus);
		}
		#endif

		#if (defined(FLASH_S))
		case DEV_FLASH: {
			RESERVE(FLASH, KMODE_READ_WRITE);
			status = storage_initialise(KFLASH, nullptr);
			RELEASE(FLASH, KMODE_READ_WRITE);

			fatFsStatus = (status == KERR_STORAGE_NOERR) ? (0) : (STA_NOINIT);
			return (fatFsStatus);
		}
		#endif

		default: {
			return (fatFsStatus);
		}

	}
}

/*
 * \brief disk_read
 *
 * - Read sectors
 *
 */
DRESULT		disk_read(BYTE pdrv, BYTE *buff, LBA_t sector, UINT count) {
	int32_t		status;
	uint16_t	szSector;
	DRESULT		fatFsResult = RES_PARERR;

	switch (pdrv) {
		#if (defined(SDCARD_S))
		case DEV_SDCARD: {
			RESERVE(SDCARD, KMODE_READ_WRITE);
			storage_ioctl(KSDCARD, KGET_SECTOR_SIZE, (void *)&szSector);
			status = storage_read(KSDCARD, (uint8_t *)buff, (uint32_t)(count * szSector), (uint32_t)sector);
			RELEASE(SDCARD, KMODE_READ_WRITE);

			fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_ERROR);
			return (fatFsResult);
		}
		#endif

		#if (defined(SDNAND_S))
		case DEV_SDNAND: {
			RESERVE(SDNAND, KMODE_READ_WRITE);
			storage_ioctl(KSDNAND, KGET_SECTOR_SIZE, (void *)&szSector);
			status = storage_read(KSDNAND, (uint8_t *)buff, (uint32_t)(count * szSector), (uint32_t)sector);
			RELEASE(SDNAND, KMODE_READ_WRITE);

			fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_ERROR);
			return (fatFsResult);
		}
		#endif

		#if (defined(FLASH_S))
		case DEV_FLASH: {
			RESERVE(FLASH, KMODE_READ_WRITE);
			storage_ioctl(KFLASH, KGET_SECTOR_SIZE, (void *)&szSector);
			status = storage_read(KFLASH, (uint8_t *)buff, (uint32_t)(count * szSector), (uint32_t)sector);
			RELEASE(FLASH, KMODE_READ_WRITE);

			fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_ERROR);
			return (fatFsResult);
		}
		#endif

		default: {
			return (fatFsResult);
		}

	}
}

/*
 * \brief disk_write
 *
 * - Write sectors
 *
 */
DRESULT		disk_write(BYTE pdrv, const BYTE *buff, LBA_t sector, UINT count) {
	int32_t		status;
	uint16_t	szSector;
	DRESULT		fatFsResult = RES_PARERR;

	switch (pdrv) {
		#if (defined(SDCARD_S))
		case DEV_SDCARD: {
			RESERVE(SDCARD, KMODE_READ_WRITE);
			storage_ioctl(KSDCARD, KGET_SECTOR_SIZE, (void *)&szSector);
			status = storage_write(KSDCARD, (const uint8_t *)buff, (uint32_t)(count * szSector), (uint32_t)sector);
			RELEASE(SDCARD, KMODE_READ_WRITE);

			fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_ERROR);
			return (fatFsResult);
		}
		#endif

		#if (defined(SDNAND_S))
		case DEV_SDNAND: {
			RESERVE(SDNAND, KMODE_READ_WRITE);
			storage_ioctl(KSDNAND, KGET_SECTOR_SIZE, (void *)&szSector);
			status = storage_write(KSDNAND, (const uint8_t *)buff, (uint32_t)(count * szSector), (uint32_t)sector);
			RELEASE(SDNAND, KMODE_READ_WRITE);

			fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_ERROR);
			return (fatFsResult);
		}
		#endif

		#if (defined(FLASH_S))
		case DEV_FLASH: {
			RESERVE(FLASH, KMODE_READ_WRITE);
			storage_ioctl(KFLASH, KGET_SECTOR_SIZE, (void *)&szSector);
			status = storage_write(KFLASH, (const uint8_t *)buff, (uint32_t)(count * szSector), (uint32_t)sector);
			RELEASE(FLASH, KMODE_READ_WRITE);

			fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_ERROR);
			return (fatFsResult);
		}
		#endif

		default: {
			return (fatFsResult);
		}

	}
}

/*
 * \brief disk_ioctl
 *
 * - Misc functions
 *
 */
DRESULT		disk_ioctl(BYTE pdrv, BYTE cmd, void *buff) {
	int32_t		status;
	DRESULT		fatFsResult = RES_PARERR;

	switch (pdrv) {
		#if (defined(SDCARD_S))
		case DEV_SDCARD: {
			RESERVE(SDCARD, KMODE_READ_WRITE);
			status = storage_ioctl(KSDCARD, (storageIoctl_t)cmd, buff);
			RELEASE(SDCARD, KMODE_READ_WRITE);

			fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_PARERR);
			return (fatFsResult);
		}
		#endif

		#if (defined(SDNAND_S))
		case DEV_SDNAND: {
			RESERVE(SDNAND, KMODE_READ_WRITE);
			status = storage_ioctl(KSDNAND, (storageIoctl_t)cmd, buff);
			RELEASE(SDNAND, KMODE_READ_WRITE);

			fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_PARERR);
			return (fatFsResult);
		}
		#endif

		#if (defined(FLASH_S))
		case DEV_FLASH: {
			RESERVE(FLASH, KMODE_READ_WRITE);
			status = storage_ioctl(KFLASH, (storageIoctl_t)cmd, buff);
			RELEASE(FLASH, KMODE_READ_WRITE);

			fatFsResult = (status == KERR_STORAGE_NOERR) ? (RES_OK) : (RES_PARERR);
			return (fatFsResult);
		}
		#endif

		default: {
			return (fatFsResult);
		}

	}
}

/*
 * \brief get_fattime
 *
 * - Read the local time
 *
 */
DWORD	get_fattime (void) {
	time_t		now;
	tm_t		localTime;

	now = time(nullptr);
	localtime_r(&now, &localTime);

	return ( ((DWORD)localTime.tm_mday<<16u) | ((DWORD)(localTime.tm_mon + 1)<<21u) | ((DWORD)(localTime.tm_year - 80)<<25u)
		   | ((DWORD)localTime.tm_hour<<11u) | ((DWORD)localTime.tm_min<<5u)		| ((DWORD)localTime.tm_sec>>1u));


}
