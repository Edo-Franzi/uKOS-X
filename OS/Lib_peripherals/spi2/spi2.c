/*
; spi2.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		spi2 manager.
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

#if (defined(CONFIG_MAN_SPI2_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"spi2         spi2 manager.                             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "spi2 manager\n"
									"============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Spi2,							// Module name (the first letter has to be upper case)
	KID_FAM_PERIPHERALS,			// Family (defined in the module.h)
	KNUM_SPI2,						// Module identifier (defined in the module.h)
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

static	int32_t		local_init(void);
extern	int32_t		stub_spi2_init(void);
extern	int32_t		stub_spi2_configure(const spiCnf_t *configure);
extern	int32_t		stub_spi2_multipleWriteRead(const uint8_t *wData, uint16_t wSize, uint8_t *rData, uint16_t rSize, uint32_t timeout);

/*
 * \brief Reserve the spi2 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = spi2_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    spi2_xyz();
 *    ....
 *    status = spi2_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \param[in]	timeout			Timeout (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_SPI_NOERR	The manager is reserved
 * \return		KERR_SPI_GEERR	General error
 * \return		KERR_SPI_CHBSY	The manager is busy
 *
 */
int32_t	spi2_reserve(reserveMode_t reserveMode, uint32_t timeout) {
	int32_t		status;
	uint32_t	core;

	UNUSED(reserveMode);

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SPI_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = kern_lockMutex(vMutex_Reserve[core], timeout);
	if (status != KERR_KERN_NOERR) {
		PRIVILEGE_RESTORE;
		return (KERR_SPI_CHBSY);
	}

	PRIVILEGE_RESTORE;
	return (KERR_SPI_NOERR);
}

/*
 * \brief Release the spi2 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = spi2_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \return		KERR_SPI_NOERR	OK
 * \return		KERR_SPI_GEERR	General error
 * \return		KERR_SPI_CAREL	Cannot release the manager
 *
 */
int32_t	spi2_release(reserveMode_t reserveMode) {
	int32_t		status;
	uint32_t	core;

	UNUSED(reserveMode);

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SPI_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = kern_unlockMutex(vMutex_Reserve[core]);
	if (status != KERR_KERN_NOERR) {
		PRIVILEGE_RESTORE;
		return (KERR_SPI_CAREL);
	}

	PRIVILEGE_RESTORE;
	return (KERR_SPI_NOERR);
}

/*
 * \brief Configure the spi2 manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t       status;
 * const    spiCnf_t    configure = {
 *                            .oSpeed    = 5000000u,
 *                            .oMode     = (uint8_t)KSPI_MASTER,
 *                            .oClock    = (1u<<(uint8_t)BSPI_POL) | (1u<<(uint8_t)BSPI_PHA)
 *                        };
 *
 *    status = spi2_configure(&configure);
 * \endcode
 *
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_SPI_NOERR	OK
 * \return		KERR_SPI_GEERR	General error
 *
 */
int32_t	spi2_configure(const spiCnf_t *configure) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SPI_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_spi2_configure(configure);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Write-Read a byte to-from the spi2 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * uint8_t    data;
 *
 *    data = 0x34;
 *    status = spi2_writeRead(&data);
 * \endcode
 *
 * \param[in]	*data			Ptr on the data to write-read
 * \return		KERR_SPI_NOERR	OK
 * \return		KERR_SPI_GEERR	General error
 *
 */
int32_t	spi2_writeRead(uint8_t *data) {
	int32_t		status;
	uint8_t		rData[1], wData[1];

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SPI_NOERR) { PRIVILEGE_RESTORE; return (status); }

	wData[0] = *data;
	status = stub_spi2_multipleWriteRead(&wData[0], 1u, &rData[0], 1u, KWAIT_INFINITY);

	*data = rData[0];
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Generic, multiple Write-Read bytes to-from the spi2 manager
 *
 * Supported transfers
 *
 * Simple reads: spi_multipleWriteRead(xyz, 0, &rBuffer[0], 20, KWAIT_INFINITY);			R, R, R, ..
 * Writes-reads: spi_multipleWriteRead(xyz, 20, &rBuffer[0], 20, KWAIT_INFINITY);			W, R, W, ..
 *				 condition (wSize == rSize)
 *				 if xyz == nullptr, write 0x00
 *				 if xyz == (&wBuffer[0], write the buffer content
 *
 * EEPROM mode:  spi_multipleWriteRead(&wBuffer[0], 4, &rBuffer[0], 20, KWAIT_INFINITY);	W, W, W, R, R, R, R, ..
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
 * status = spi_multipleWriteRead(&wBuffer[0], 4, &rBuffer[0], 1024, KWAIT_INFINITY);
 * ...
 *
 * \endcode
 *
 * \param[in]	*wData			Ptr on the data to write
 * \param[in]	wSize			Size of the write buffer
 * \param[in]	*rData			Ptr on the data to read
 * \param[in]	rSize			Size of the read buffer
 * \param[in]	timeout			Timeout (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_SPI_NOERR	OK
 * \return		KERR_SPI_GEERR	General error
 * \return		KERR_SPI_TIMEO	Timeout error
 *
 */
int32_t	spi2_multipleWriteRead(const uint8_t *wData, uint16_t wSize, uint8_t *rData, uint16_t rSize, uint32_t timeout) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SPI_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_spi2_multipleWriteRead(wData, wSize, rData, rSize, timeout);
	if (status != KERR_SPI_NOERR) { PRIVILEGE_RESTORE; return (status); }

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
			int32_t		status = KERR_SPI_NOERR;
			uint32_t	core;
	static	bool		vInit[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vInit[core] == false) {
		vInit[core] = true;

		if (kern_createMutex(KSPI2_MUTEX_RESERVE, &vMutex_Reserve[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "spi2: create mutx"); exit(EXIT_OS_PANIC); }

		status = stub_spi2_init();
	}
	RETURN_INT_RESTORE(status);
}

#endif
