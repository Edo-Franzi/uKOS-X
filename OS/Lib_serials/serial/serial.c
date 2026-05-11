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

#include	"uKOS.h"

#if (defined(CONFIG_MAN_SERIAL_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"serial       serial manager.                           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "serial manager\n"
									"==============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Serial,							// Module name (the first letter has to be upper case)
	KID_FAM_SERIALS,				// Family (defined in the module.h)
	KNUM_SERIAL,					// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

static	serialManager_t		vDefSerialManager[KNB_CORES];

// Prototypes

static	void	local_getDevice(serialManager_t serialManager, serialManager_t *manager);

/*
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
int32_t	serial_reserve(serialManager_t serialManager, reserveMode_t reserveMode, uint32_t timeout) {
	serialManager_t		manager;

	local_getDevice(serialManager, &manager);

	switch (manager) {

		#if (defined(CONFIG_MAN_URT0_S))
		case KURT0: { return (urt0_reserve(reserveMode, timeout)); }
		#endif

		#if (defined(CONFIG_MAN_URT1_S))
		case KURT1: { return (urt1_reserve(reserveMode, timeout)); }
		#endif

		#if (defined(CONFIG_MAN_URT2_S))
		case KURT2: { return (urt2_reserve(reserveMode, timeout)); }
		#endif

		#if (defined(CONFIG_MAN_URT3_S))
		case KURT3: { return (urt3_reserve(reserveMode, timeout)); }
		#endif

		#if (defined(CONFIG_MAN_URT4_S))
		case KURT4: { return (urt4_reserve(reserveMode, timeout)); }
		#endif

		#if (defined(CONFIG_MAN_CDC0_S))
		case KCDC0: { return (cdc0_reserve(reserveMode, timeout)); }
		#endif

		#if (defined(CONFIG_MAN_CDC1_S))
		case KCDC1: { return (cdc1_reserve(reserveMode, timeout)); }
		#endif

		#if (defined(CONFIG_MAN_WFI0_S))
		case KWFI0: { return (wfi0_reserve(reserveMode, timeout)); }
		#endif

		default:    { return (KERR_SERIAL_NODEV);				   }
	}
}

/*
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
int32_t	serial_release(serialManager_t serialManager, reserveMode_t reserveMode) {
	serialManager_t		manager;

	local_getDevice(serialManager, &manager);

	switch (manager) {

		#if (defined(CONFIG_MAN_URT0_S))
		case KURT0: { return (urt0_release(reserveMode)); }
		#endif

		#if (defined(CONFIG_MAN_URT1_S))
		case KURT1: { return (urt1_release(reserveMode)); }
		#endif

		#if (defined(CONFIG_MAN_URT2_S))
		case KURT2: { return (urt2_release(reserveMode)); }
		#endif

		#if (defined(CONFIG_MAN_URT3_S))
		case KURT3: { return (urt3_release(reserveMode)); }
		#endif

		#if (defined(CONFIG_MAN_URT4_S))
		case KURT4: { return (urt4_release(reserveMode)); }
		#endif

		#if (defined(CONFIG_MAN_CDC0_S))
		case KCDC0: { return (cdc0_release(reserveMode)); }
		#endif

		#if (defined(CONFIG_MAN_CDC1_S))
		case KCDC1: { return (cdc1_release(reserveMode)); }
		#endif

		#if (defined(CONFIG_MAN_WFI0_S))
		case KWFI0: { return (wfi0_release(reserveMode)); }
		#endif

		default:    { return (KERR_SERIAL_NODEV);		  }
	}
}

/*
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
int32_t	serial_configure(serialManager_t serialManager, const void *configure) {
	serialManager_t		manager;

	local_getDevice(serialManager, &manager);

	switch (manager) {

		#if (defined(CONFIG_MAN_URT0_S))
		case KURT0: { return (urt0_configure((const urtxCnf_t *)configure)); }
		#endif

		#if (defined(CONFIG_MAN_URT1_S))
		case KURT1: { return (urt1_configure((const urtxCnf_t *)configure)); }
		#endif

		#if (defined(CONFIG_MAN_URT2_S))
		case KURT2: { return (urt2_configure((const urtxCnf_t *)configure)); }
		#endif

		#if (defined(CONFIG_MAN_URT3_S))
		case KURT3: { return (urt3_configure((const urtxCnf_t *)configure)); }
		#endif

		#if (defined(CONFIG_MAN_URT4_S))
		case KURT4: { return (urt4_configure((const urtxCnf_t *)configure)); }
		#endif

		#if (defined(CONFIG_MAN_CDC0_S))
		case KCDC0: { return (cdc0_configure((const cdcxCnf_t *)configure)); }
		#endif

		#if (defined(CONFIG_MAN_CDC1_S))
		case KCDC1: { return (cdc1_configure((const cdcxCnf_t *)configure)); }
		#endif

		#if (defined(CONFIG_MAN_WFI0_S))
		case KWFI0: { return (wfi0_configure((const urtxCnf_t *)configure)); }
		#endif

		default:    { return (KERR_SERIAL_NODEV);							  }
	}
}

/*
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
int32_t	serial_write(serialManager_t serialManager, const uint8_t *buffer, uint32_t size) {
	serialManager_t		manager;

	local_getDevice(serialManager, &manager);

	switch (manager) {

		#if (defined(CONFIG_MAN_URT0_S))
		case KURT0: { return (urt0_write(buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_URT1_S))
		case KURT1: { return (urt1_write(buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_URT2_S))
		case KURT2: { return (urt2_write(buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_URT3_S))
		case KURT3: { return (urt3_write(buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_URT4_S))
		case KURT4: { return (urt4_write(buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_CDC0_S))
		case KCDC0: { return (cdc0_write(buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_CDC1_S))
		case KCDC1: { return (cdc1_write(buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_WFI0_S))
		case KWFI0: { return (wfi0_write(buffer, size)); }
		#endif

		default:    { return (KERR_SERIAL_NODEV);		 }
	}
}

/*
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
int32_t	serial_read(serialManager_t serialManager, uint8_t *buffer, uint32_t *size) {
	serialManager_t		manager;

	local_getDevice(serialManager, &manager);

	switch (manager) {

		#if (defined(CONFIG_MAN_URT0_S))
		case KURT0: { return (urt0_read(buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_URT1_S))
		case KURT1: { return (urt1_read(buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_URT2_S))
		case KURT2: { return (urt2_read(buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_URT3_S))
		case KURT3: { return (urt3_read(buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_URT4_S))
		case KURT4: { return (urt4_read(buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_CDC0_S))
		case KCDC0: { return (cdc0_read(buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_CDC1_S))
		case KCDC1: { return (cdc1_read(buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_WFI0_S))
		case KWFI0: { return (wfi0_read(buffer, size)); }
		#endif

		default:    { return (KERR_SERIAL_NODEV);		}
	}
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
 *    status = serial_getIdSemaphore(KURT0, BSERIAL_SEMAPHORE_RX, &identifier[0];
 *    status = serial_getIdSemaphore(KURT0, BSERIAL_SEMAPHORE_TX, &identifier[1];
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
int32_t	serial_getIdSemaphore(serialManager_t serialManager, uint8_t semaphore, char_t **identifier) {
	serialManager_t		manager;

	local_getDevice(serialManager, &manager);

	switch (manager) {

		#if (defined(CONFIG_MAN_URT0_S))
		case KURT0: { return (urt0_getIdSemaphore(semaphore, identifier)); }
		#endif

		#if (defined(CONFIG_MAN_URT1_S))
		case KURT1: { return (urt1_getIdSemaphore(semaphore, identifier)); }
		#endif

		#if (defined(CONFIG_MAN_URT2_S))
		case KURT2: { return (urt2_getIdSemaphore(semaphore, identifier)); }
		#endif

		#if (defined(CONFIG_MAN_URT3_S))
		case KURT3: { return (urt3_getIdSemaphore(semaphore, identifier)); }
		#endif

		#if (defined(CONFIG_MAN_URT4_S))
		case KURT4: { return (urt4_getIdSemaphore(semaphore, identifier)); }
		#endif

		#if (defined(CONFIG_MAN_CDC0_S))
		case KCDC0: { return (cdc0_getIdSemaphore(semaphore, identifier)); }
		#endif

		#if (defined(CONFIG_MAN_CDC1_S))
		case KCDC1: { return (cdc1_getIdSemaphore(semaphore, identifier)); }
		#endif

		#if (defined(CONFIG_MAN_WFI0_S))
		case KWFI0: { return (wfi0_getIdSemaphore(semaphore, identifier)); }
		#endif

		default:    { return (KERR_SERIAL_NODEV);						   }
	}
}

/*
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
 * \param[in]	serialManager		Serial Communication Manager
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_NODEV	The serialManager does not exist
 *
 */
int32_t	serial_flush(serialManager_t serialManager) {
	serialManager_t		manager;

	local_getDevice(serialManager, &manager);

	switch (manager) {

		#if (defined(CONFIG_MAN_URT0_S))
		case KURT0: { return (urt0_flush());	  }
		#endif

		#if (defined(CONFIG_MAN_URT1_S))
		case KURT1: { return (urt1_flush());	  }
		#endif

		#if (defined(CONFIG_MAN_URT2_S))
		case KURT2: { return (urt2_flush());	  }
		#endif

		#if (defined(CONFIG_MAN_URT3_S))
		case KURT3: { return (urt3_flush());	  }
		#endif

		#if (defined(CONFIG_MAN_URT4_S))
		case KURT4: { return (urt4_flush());	  }
		#endif

		#if (defined(CONFIG_MAN_CDC0_S))
		case KCDC0: { return (cdc0_flush());	  }
		#endif

		#if (defined(CONFIG_MAN_CDC1_S))
		case KCDC1: { return (cdc1_flush());	  }
		#endif

		#if (defined(CONFIG_MAN_WFI0_S))
		case KWFI0: { return (wfi0_flush());	  }
		#endif

		default:    { return (KERR_SERIAL_NODEV); }
	}
}

/*
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
int32_t	serial_setDefSerialManager(serialManager_t serialManager) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	vDefSerialManager[core] = serialManager;
	PRIVILEGE_RESTORE;
	return (KERR_SERIAL_NOERR);
}

/*
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
int32_t	serial_getDefSerialManager(serialManager_t *serialManager) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	*serialManager = vDefSerialManager[core];
	PRIVILEGE_RESTORE;
	return (KERR_SERIAL_NOERR);
}

/*
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
int32_t	serial_getFatherSerialManager(serialManager_t *serialManager) {

	local_getDevice(KSYST, serialManager);
	return (KERR_SERIAL_NOERR);
}

// Local routines
// ==============

/*
 * \brief local_getDevice
 *
 * - if (serialManager == KSYST) ---> continue to search in the dynasty
 * - if (serialManager == KDEF0) ---> use the default Serial Communication Manager
 * - if (serialManager == KXYZT) ---> use the KXYZT Serial Communication Manager
 *
 */
static	void	local_getDevice(serialManager_t serialManager, serialManager_t *manager) {
	uint32_t	core;
	proc_t		*process;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	*manager = serialManager;

// As long as we have KSYST, scan the dynasty for a logical device (KURT0, KCDC0, ...)
// Stop searching for a valuable logical device or if the process is orphan

	kern_getProcessRun(&process);
	while (*manager == KSYST) {
		kern_getSerialForProcess(process, manager);
		if ((*manager != KSYST) || (process->oInternal.oProcFather == nullptr)) {
			break;
		}
		process = process->oInternal.oProcFather;
	}

// At this point we should have:
// - The logical device (KURT0, KCDC0, ...)
// - KDEF0 --> *manager = vDefSerialManager
// - KSYST --> *manager = vDefSerialManager

	if ((*manager == KDEF0) || (*manager == KSYST)) {
		*manager = vDefSerialManager[core];
	}
	PRIVILEGE_RESTORE;
}

#endif
