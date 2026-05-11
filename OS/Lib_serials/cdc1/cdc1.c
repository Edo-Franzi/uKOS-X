/*
; cdc1.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		cdc1 manager.
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

// cppcheck-suppress missingInclude
//
#include	"tusb_config.h"

#if (defined(CONFIG_MAN_CDC1_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"cdc1         cdc1 manager.                             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "cdc1 manager\n"
									"============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Cdc1,							// Module name (the first letter has to be upper case)
	KID_FAM_SERIALS,				// Family (defined in the module.h)
	KNUM_CDC1,						// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

#define	CDC1_SEMA_TX_S

#define	KCDC1_SZ_TX_BUF		CFG_TUD_CDC_TX_BUFSIZE
#define	KCDC1_SZ_RX_BUF		CFG_TUD_CDC_RX_BUFSIZE
#define	KPORT1				1

STRG_LOC_CONST(aStrSemaphore_TX[]) = KCDC1_SEMAPHORE_TX;

static	bool		vWithSemaphore_TX[KNB_CORES] = MCSET(false);

static	sema_t		*vSemaphore_TX[KNB_CORES];
static	mutx_t		*vMutex_Reserve_RX[KNB_CORES];
static	mutx_t		*vMutex_Reserve_TX[KNB_CORES];

// Prototypes

		void		TinyUSB_cdc_init(void);
		void		TinyUSB_cdc_write(uint8_t itf, const uint8_t *buffer, uint32_t size);
		void		TinyUSB_cdc_read(uint8_t itf, uint8_t *buffer, uint32_t *size);
static	int32_t		local_init(void);
static	int32_t		local_configure(const cdcxCnf_t *configure);
static	int32_t		local_write(const uint8_t *buffer, uint32_t size);
static	int32_t		local_read(uint8_t *buffer, uint32_t *size);
static	int32_t		local_flush(void);

/*
 * \brief Reserve the cdc1 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = cdc1_reserve(KMODE_WRITE, 1234);
 *    ....
 *    cdc1_xyz();
 *    ....
 *    status = cdc1_release(KMODE_WRITE);
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
int32_t	cdc1_reserve(reserveMode_t reserveMode, uint32_t timeout) {
	int32_t		status;
	uint32_t	core;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SERIAL_NOERR) { PRIVILEGE_RESTORE; return (status); }

	switch (reserveMode) {
		case KMODE_READ: {
			status = kern_lockMutex(vMutex_Reserve_RX[core], timeout);
			if (status != KERR_KERN_NOERR) {
				PRIVILEGE_RESTORE;
				return (KERR_SERIAL_CHBSY);
			}

			break;
		}
		case KMODE_WRITE: {
			status = kern_lockMutex(vMutex_Reserve_TX[core], timeout);
			if (status != KERR_KERN_NOERR) {
				PRIVILEGE_RESTORE;
				return (KERR_SERIAL_CHBSY);
			}

			break;
		}
		case KMODE_READ_WRITE: {
			status = kern_lockMutex(vMutex_Reserve_RX[core], timeout);
			if (status != KERR_KERN_NOERR) {
				PRIVILEGE_RESTORE;
				return (KERR_SERIAL_CHBSY);
			}

			status = kern_lockMutex(vMutex_Reserve_TX[core], timeout);
			if (status != KERR_KERN_NOERR) {
				kern_unlockMutex(vMutex_Reserve_RX[core]);
				PRIVILEGE_RESTORE;
				return (KERR_SERIAL_CHBSY);
			}

			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}
	PRIVILEGE_RESTORE;
	return (KERR_SERIAL_NOERR);
}

/*
 * \brief Release the cdc1 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = cdc1_release(KMODE_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode			KMODE_READ, KMODE_WRITE, KMODE_READ_WRITE
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_GEERR	General error
 * \return		KERR_SERIAL_CAREL	Cannot release the manager
 *
 */
int32_t	cdc1_release(reserveMode_t reserveMode) {
	int32_t		status;
	uint32_t	core;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SERIAL_NOERR) { PRIVILEGE_RESTORE; return (status); }

	switch (reserveMode) {
		case KMODE_READ: {
			status = kern_unlockMutex(vMutex_Reserve_RX[core]);
			if (status != KERR_KERN_NOERR) {
				PRIVILEGE_RESTORE;
				return (KERR_SERIAL_CAREL);
			}

			break;
		}
		case KMODE_WRITE: {
			status = kern_unlockMutex(vMutex_Reserve_TX[core]);
			if (status != KERR_KERN_NOERR) {
				PRIVILEGE_RESTORE;
				return (KERR_SERIAL_CAREL);
			}

			break;
		}
		case KMODE_READ_WRITE: {
			status = kern_unlockMutex(vMutex_Reserve_RX[core]);
			if (status != KERR_KERN_NOERR) {
				PRIVILEGE_RESTORE;
				return (KERR_SERIAL_CAREL);
			}

			status = kern_unlockMutex(vMutex_Reserve_TX[core]);
			if (status != KERR_KERN_NOERR) {
				PRIVILEGE_RESTORE;
				return (KERR_SERIAL_CAREL);
			}

			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}
	PRIVILEGE_RESTORE;
	return (KERR_SERIAL_NOERR);
}

/*
 * \brief Configure the cdc1 manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t       status;
 * const    cdcxCnf_t    configure = {
 *                              .oKernSync = (1u<<BSERIAL_SEMAPHORE_RX),
 *                        };
 *
 *    status = cdc1_configure(&configure);
 * \endcode
 *
 * \param[in]	*configure			Ptr on the configuration buffer
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_GEERR	General error
 * \return		KERR_SERIAL_NOCNF	The configuration does not exist
 *
 */
int32_t	cdc1_configure(const cdcxCnf_t *configure) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SERIAL_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = local_configure(configure);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Write a buffer to the cdc1 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KSIZE    10
 *
 * uint8_t    buffer[KSIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
 * int32_t    status;
 *
 *    status = cdc1_write(buffer, KSIZE);
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
int32_t	cdc1_write(const uint8_t *buffer, uint32_t size) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SERIAL_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = local_write(buffer, size);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Read a buffer from the cdc1 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * uint8_t     buffer[1];
 * uint32_t    size;
 * int32_t     status;
 *
 *    size = 1;
 *    status = cdc1_read(buffer, &size);
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
int32_t	cdc1_read(uint8_t *buffer, uint32_t *size) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SERIAL_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = local_read(buffer, size);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Get the semaphore identifier
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * char_t     *identifier[2];
 *
 *    status = cdc1_getIdSemaphore(BSERIAL_SEMAPHORE_RX, &identifier[0];
 *    status = cdc1_getIdSemaphore(BSERIAL_SEMAPHORE_TX, &identifier[1];
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
int32_t	cdc1_getIdSemaphore(uint8_t semaphore, char_t **identifier) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SERIAL_NOERR) { PRIVILEGE_RESTORE; return (status); }

	if (semaphore == BSERIAL_SEMAPHORE_RX) { *identifier = KCDC1_SEMAPHORE_RX; PRIVILEGE_RESTORE; return (KERR_SERIAL_NOERR); }
	if (semaphore == BSERIAL_SEMAPHORE_TX) { *identifier = KCDC1_SEMAPHORE_TX; PRIVILEGE_RESTORE; return (KERR_SERIAL_NOERR); }
	PRIVILEGE_RESTORE;
	return (KERR_SERIAL_SENOE);
}

/*
 * \brief Flush the cdc1 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = cdc1_flush();
 * \endcode
 *
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_GEERR	General error
 *
 */
int32_t	cdc1_flush(void) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SERIAL_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = local_flush();
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
			int32_t		status = KERR_SERIAL_NOERR;
			uint32_t	core;
	static	bool		vInit[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vInit[core] == false) {
		vInit[core] = true;

		TinyUSB_cdc_init();

		if (kern_createMutex(KCDC1_MUTEX_RESERVE_RX, &vMutex_Reserve_RX[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "cdc1: create mutx"); exit(EXIT_OS_PANIC); }
		if (kern_createMutex(KCDC1_MUTEX_RESERVE_TX, &vMutex_Reserve_TX[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "cdc1: create mutx"); exit(EXIT_OS_PANIC); }
		if (kern_createSemaphore(aStrSemaphore_TX, 0, 1, &vSemaphore_TX[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "cdc1: Create sema"); exit(EXIT_OS_PANIC); }
	}
	RETURN_INT_RESTORE(status);
}

/*
 * \brief local_configure
 *
 * - Configure the manager
 *
 */
static	int32_t	local_configure(const cdcxCnf_t *configure) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	vWithSemaphore_TX[core] = ((configure->oKernSync & ((uint32_t)1u<<(uint32_t)BSERIAL_SEMAPHORE_TX)) != 0u) ? (true) : (false);
	RETURN_INT_RESTORE(KERR_SERIAL_NOERR);
}

/*
 * \brief local_write
 *
 * - Write a buffer
 *
 */
static	int32_t	local_write(const uint8_t *buffer, uint32_t size) {
			uint32_t	core, newSize, wkSize = size;
	const	uint8_t		*wkBuffer = buffer;
	static	bool		vTerminate[KNB_CORES] = MCSET(false), vBusy[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vBusy[core])  { RETURN_INT_RESTORE(KERR_SERIAL_SEPRO); }
	if (wkSize == 0u) { RETURN_INT_RESTORE(KERR_SERIAL_LNBU0); }

	vBusy[core] = true;
	INTERRUPTION_RESTORE;

	while (vTerminate[core] == false) {
		if (wkSize > KCDC1_SZ_TX_BUF) { newSize = KCDC1_SZ_TX_BUF; wkSize -= KCDC1_SZ_TX_BUF; }
		else						  { newSize = wkSize; vTerminate[core] = true;			  }

// Copy the input buffer into the send one and start the transfer
// Enable the TX interruption

		TinyUSB_cdc_write(KPORT1, wkBuffer, newSize);
		wkBuffer = (const uint8_t *)((uintptr_t)wkBuffer + (uintptr_t)newSize);
	}

// Signal end of the message

	#if (defined(CDC1_SEMA_TX_S))
	if (vWithSemaphore_TX[core] == true) { kern_signalSemaphore(vSemaphore_TX[core]); }
	#endif

	vBusy[core] = false;
	vTerminate[core] = false;
	return (KERR_SERIAL_NOERR);
}

/*
 * \brief local_read
 *
 * - Read n x bytes
 *   - Try to read a buffer from the EP usb
 *
 */
static	int32_t	local_read(uint8_t *buffer, uint32_t *size) {
	uint32_t	wkSize;

	INTERRUPTION_OFF;
	if (*size == 0u) { *size = 0u; RETURN_INT_RESTORE(KERR_SERIAL_NOERR); }

// Read the data

	wkSize = (*size > KCDC1_SZ_RX_BUF) ? (KCDC1_SZ_RX_BUF) : (*size);
	TinyUSB_cdc_read(KPORT1, buffer, &wkSize);

	if (wkSize > 0u) {
		*size = wkSize;
		RETURN_INT_RESTORE(KERR_SERIAL_NOERR);
	}

	*size = 0u;
	RETURN_INT_RESTORE(KERR_SERIAL_RBUEM);
}

/*
 * \brief local_flush
 *
 * - Flush the cdc1 manager
 *
 */
static	int32_t	local_flush(void) {
	uint8_t		i, buffer[32];
	uint32_t	size;

	INTERRUPTION_OFF;
	for (i = 0u; i < (512u / 32u); i++) { TinyUSB_cdc_read(KPORT1, &buffer[0], &size); }
	RETURN_INT_RESTORE(KERR_SERIAL_NOERR);
}

#endif
