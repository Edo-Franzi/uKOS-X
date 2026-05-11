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

#pragma	once

/*!
 * \addtogroup Lib_storages
 */
/**@{*/

/*!
 * \defgroup sdcard Sdcard
 *
 * \brief Sdcard
 *
 * Sdcard management
 *
 * @{
 */

// Semaphores
// ----------

#define	KSDCARD_MUTEX_RESERVE	"Reserve_sdcard"

// Sizes

#define	KSDCARD_SZ_SECTOR				512u					// Sector size in bytes
#define	KSDCARD_MAX_SECTORS_PER_CALL	128u					// Max. number of sectors per call

// sdcard parameters structure
// ---------------------------

typedef	struct	sdcardSpecifications	sdcard_specification_t;

struct sdcardSpecifications {
			uint64_t	oSize;									// Sdcard size in Bytes
			uint32_t	oSerialNumber;							// Sdcard Serial Number
			uint16_t	oVoltage;								// Sdcard Voltage
			uint8_t		oManufacturer;							// Sdcard Manufacturer ID
			uint32_t	oSpeed;									// Sdcard Speed in bit/s
			uint8_t		oProductName[5 + 1];					// Sdcard Product Name
			uint8_t		oCapacityStatus;						// Sdcard Capacity Status
};

// Voltages

enum {
			KSDCARD_V_27_28		= 0x001u,						// Supported voltage  2.7 to 2.8V
			KSDCARD_V_28_29		= 0x002u,						// Supported voltage  2.8 to 2.9V
			KSDCARD_V_29_30		= 0x004u,						// Supported voltage  2.9 to 3.0V
			KSDCARD_V_30_31		= 0x008u,						// Supported voltage  3.0 to 3.1V
			KSDCARD_V_31_32		= 0x010u,						// Supported voltage  3.1 to 3.2V
			KSDCARD_V_32_33		= 0x020u,						// Supported voltage  3.2 to 3.3V
			KSDCARD_V_33_34		= 0x040u,						// Supported voltage  3.3 to 3.4V
			KSDCARD_V_34_35		= 0x080u,						// Supported voltage  3.4 to 3.5V
			KSDCARD_V_35_36		= 0x100u						// Supported voltage  3.5 to 3.6V
};

// Provider ids

enum {
			KSDCARD_PANASONIC	= 0x0001u,						// Panasonic
			KSDCARD_TOSHIBA		= 0x0002u,						// Toshiba
			KSDCARD_SANDISK		= 0x0003u,						// Sandisk
			KSDCARD_SAMSUNG		= 0x001Bu,						// Samsung
			KSDCARD_ADATA		= 0x001Du,						// Adata
			KSDCARD_PHISON		= 0x0027u,						// Phison
			KSDCARD_LEXAR		= 0x0028u,						// Lexar
			KSDCARD_SILICONPWR	= 0x0031u,						// Silicon PWR
			KSDCARD_KINGSTON	= 0x0041u,						// Kingston
			KSDCARD_TRANSCEND	= 0x0074u,						// Transcend
			KSDCARD_PATRIOT		= 0x0076u,						// Patriot
			KSDCARD_SONY		= 0x0082u						// Sony
};

// Card versions

enum {
			KSDCARD_CT_MMC		= 0x01u,						// MMC sdcard Ver 3 (not supported)
			KSDCARD_CT_SD1		= 0x02u,						// SDC sdcard Ver 1 (not supported)
			KSDCARD_CT_SD2		= 0x04u,						// SDC sdcard Ver 2
			KSDCARD_CT_BLOCK	= 0x08u							// Block addressing
};

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	SDCARD_reserve	sdcard_reserve
#define	SDCARD_release	sdcard_release

/*!
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
extern	int32_t	sdcard_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
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
extern	int32_t	sdcard_release(reserveMode_t reserveMode);

/*!
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
extern	int32_t	sdcard_initialise(sdcard_specification_t *specification);

/*!
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
extern	int32_t	sdcard_readStatus(void);

/*!
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
extern	int32_t	sdcard_read(uint8_t *buffer, uint32_t size, uint32_t sector);

/*!
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
extern	int32_t	sdcard_write(const uint8_t *buffer, uint32_t size, uint32_t sector);

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
extern	int32_t	sdcard_ioctl(storageIoctl_t command, void *buffer);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
