/*
; asmp.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		asmp manager.
;
;			Interprocessor communication
;
;			core0, 1, 2 ---> core3
;			core1, 2, 3 ---> core0
;			core2, 3, 0 ---> core1
;			core3, 0, 1 ---> core2
;
;			The buffer is associated to the input of a core.
;			Transfer example (core2 send data to core0)
;
;			core2
;			if (Buffer core0 empty)
;				Fill the core0 buffer
;				Buffer core0 Full
;				Send a message to the core0 (strobe)
;
;			core0
;			Read the data
;			Send a message to the core2 (Ack)
;			Buffer core0 Empty
;
;			Important:
;			In this multicore communication layer, we must take into account both heterogeneous (e.g., M4 + M7)
;			and homogeneous (e.g., 2 × M33) core configurations.
;
;			For uKOS:
;			In a heterogeneous configuration, KNB_CORES is always equal to 1.
;			In a homogeneous configuration, KNB_CORES is always greater than 1.
;			Be careful with the PREEMPTION_THRESHOLD macro to ensure it returns the correct core:
;			In a heterogeneous configuration: PREEMPTION_THRESHOLD(KCORE_0)
;			In a homogeneous configuration: PREEMPTION_THRESHOLD(core)
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
#include	"linker.h"

#if (defined(CONFIG_MAN_ASMP_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"asmp         asmp manager.                             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "asmp manager\n"
									"============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Asmp,							// Module name (the first letter has to be upper case)
	KID_FAM_GENERICS,				// Family (defined in the module.h)
	KNUM_ASMP,						// Module identifier (defined in the module.h)
	NULL,							// Address of the initialisation code (early pre-init)
	NULL,							// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,							// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

asmpShared_t	*vAsmp_InterCore;

// Prototypes

static	void		local_init(void);
extern	void		stub_asmp_init(void);
extern	int32_t		stub_asmp_getRunningCore(uint32_t *core);
extern	int32_t		stub_asmp_getNumberOfCore(uint8_t *nbCore);
extern	int32_t		stub_asmp_getReferenceCore(uint32_t core, const char_t **coreReference);
extern	int32_t		stub_asmp_signal(uint32_t message);
extern	int32_t		stub_asmp_waitingForReady(void);

/*
 * \brief Send data to core 0..3
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    toCore = KASMP_CORE_1;
 * uint32_t    order = 3;
 * uint32_t    size = 5;
 * uint8_t     send[5] = { 0, 1, 2, 3, 4 };
 *
 *    status = asmp_send(toCore, order, length, send);
 * \endcode
 *
 * \param[in]	toCore			Core number that will receive the message
 * \param[in]	order			Order (optional)
 * \param[in]	size			Size of the message
 * \param[in]	*send			Ptr on the sending buffer
 * \return		KERR_ASMP_NOERR	OK
 * \return		KERR_ASMP_GEERR	General error
 * \return		KERR_ASMP_SBFUL	The sender buffer is full
 * \return		KERR_ASMP_CORNA	The core number is not not allowed
 * \return		KERR_ASMP_LNBUB	The buffer size is too big
 *
 */
int32_t	asmp_send(uint32_t toCore, uint32_t order, uint32_t size, const uint8_t *send) {
	uint32_t	core, message = 0u;
	uint8_t		nbCore;

	PRIVILEGE_ELEVATE;
	local_init();

	stub_asmp_getRunningCore(&core);
	stub_asmp_getNumberOfCore(&nbCore);

// Core does not exist or toCore = sender
// size > KASMP_SZ_BUFFER

	if ((toCore >= nbCore) || (toCore == core)) { PRIVILEGE_RESTORE; return (KERR_ASMP_CORNA); }
	if (size >= KASMP_SZ_BUFFER)				{ PRIVILEGE_RESTORE; return (KERR_ASMP_LNBUB); }

	switch (toCore) {
		case KASMP_CORE_0: { message = KASMP_MESSAGE_VALID_FOR_CORE_0; break; }
		case KASMP_CORE_1: { message = KASMP_MESSAGE_VALID_FOR_CORE_1; break; }
		case KASMP_CORE_2: { message = KASMP_MESSAGE_VALID_FOR_CORE_2; break; }
		case KASMP_CORE_3: { message = KASMP_MESSAGE_VALID_FOR_CORE_3; break; }
		default: {

// Make MISRA happy :-)

			break;
		}
	}

// Verify if the previous message was read

// NOLINTBEGIN(clang-analyzer-security.ArrayBound)
//
	INTERRUPTION_OFF;
	if (vAsmp_InterCore->oStatusTX[toCore] == KASMP_FREE) {
		vAsmp_InterCore->oStatusTX[toCore]  = KASMP_LOCK;
		INTERRUPTION_RESTORE;

		vAsmp_InterCore->oSender[toCore] = core;
		vAsmp_InterCore->oOrder[toCore]  = order;
		vAsmp_InterCore->oSize[toCore]	 = size;

		memcpy(&vAsmp_InterCore->oBuffer[toCore][0], &send[0], size);

		stub_asmp_signal(message);
		PRIVILEGE_RESTORE;
		return (KERR_ASMP_NOERR);
	}

// NOLINTEND(clang-analyzer-security.ArrayBound)
//
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_ASMP_SBFUL);
}

/*
 * \brief Receive data from core 0..3
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    fromCore;
 * uint32_t    order;
 * uint32_t    size;
 * uint8_t     receive[1024];
 *
 *    status = asmp_receive(&fromCore, &order, &size, &receive[0]);
 * \endcode
 *
 * \param[in]	*fromCore		Ptr on the core number that sent the message
 * \param[in]	*order			Ptr on the order
 * \param[in]	*size			Ptr on the size of the receive buffer
 * \param[in]	*receive		Ptr on the receiving buffer (the buffer size should be al lest KASMP_SZ_BUFFER)
 * \return		KERR_ASMP_NOERR	OK
 * \return		KERR_ASMP_GEERR	General error
 * \return		KERR_ASMP_CORNA	The core number is not not allowed
 * \return		KERR_ASMP_RBUEM	The receiver buffer is empty
 *
 */
int32_t	asmp_receive(uint32_t *fromCore, uint32_t *order, uint32_t *size, uint8_t *receive) {
	uint32_t	core, message = 0u;

	PRIVILEGE_ELEVATE;
	local_init();

	stub_asmp_getRunningCore(&core);

// Verify if there is a message

	INTERRUPTION_OFF;
	if (vAsmp_InterCore->oStatusRX[core] == KASMP_LOCK) {
		*fromCore = vAsmp_InterCore->oSender[core];
		*order	  = vAsmp_InterCore->oOrder[core];
		*size	  = vAsmp_InterCore->oSize[core];

		memcpy(&receive[0], &vAsmp_InterCore->oBuffer[core][0], *size);

		vAsmp_InterCore->oStatusRX[core] = KASMP_FREE;

		INTERRUPTION_RESTORE;

// Acknowledge the fromCore

		switch (*fromCore) {
			case KASMP_CORE_0: { message = KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_0; break; }
			case KASMP_CORE_1: { message = KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_1; break; }
			case KASMP_CORE_2: { message = KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_2; break; }
			case KASMP_CORE_3: { message = KASMP_MESSAGE_ACKNOWLEDGE_THE_CORE_3; break; }
			default: {

// Make MISRA happy :-)

				break;
			}
		}

		stub_asmp_signal(message);
		PRIVILEGE_RESTORE;
		return (KERR_ASMP_NOERR);
	}

	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_ASMP_RBUEM);
}

/*
 * \brief Get the running core
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    core;
 *
 *    status = asmp_getRunningCore(&core);
 * \endcode
 *
 * \param[in]	*core			Ptr on the running core number
 * \return		KERR_ASMP_NOERR	OK
 *
 */
int32_t	asmp_getRunningCore(uint32_t *core) {

	PRIVILEGE_ELEVATE;
	local_init();

	stub_asmp_getRunningCore(core);
	PRIVILEGE_RESTORE;
	return (KERR_ASMP_NOERR);
}

/*
 * \brief Get the reference of the running core
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    core;
 * char_t      *coreReference;
 *
 *    status = asmp_getReferenceCore(core, &coreReference);
 * \endcode
 *
 * \param[in]	core			Core number
 * \param[in]	**coreReference	Ptr on the core number reference
 * \return		KERR_ASMP_NOERR	OK
 * \return		KERR_ASMP_CORNA	The core number is not not allowed
 *
 */
int32_t	asmp_getReferenceCore(uint32_t core, const char_t **coreReference) {

	PRIVILEGE_ELEVATE;
	local_init();

	*coreReference = NULL;

	if (core > KASMP_NB_CORES) {
		PRIVILEGE_RESTORE;
		return (KERR_ASMP_NOERR);
	}

	stub_asmp_getReferenceCore(core, coreReference);
	PRIVILEGE_RESTORE;
	return (KERR_ASMP_NOERR);
}

/*
 * \brief Get the handle of the RX full semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    core;
 * sema_t      *semaphore;
 *
 *    status = asmp_getRunningCore(&core);
 *    status = asmp_getSemaphoreRXFull(core, &semaphore);
 * \endcode
 *
 * \param[in]	core			Running core number
 * \param[in]	**semaphore		Ptr on the semaphore handle
 * \return		KERR_ASMP_NOERR	OK
 * \return		KERR_ASMP_CORNA	The core number is not not allowed
 *
 */
int32_t	asmp_getSemaphoreRXFull(uint32_t core, sema_t **semaphore) {
	const	char_t	*identifier = NULL;

	PRIVILEGE_ELEVATE;
	local_init();

	switch (core) {
		case KASMP_CORE_0: {
			if (KASMP_NB_CORES > 0u) { identifier = KASMP_SEMA_RX_CORE_0_FULL; }
			break;
		}
		case KASMP_CORE_1: {
			if (KASMP_NB_CORES > 1u) { identifier = KASMP_SEMA_RX_CORE_1_FULL; }
			break;
		}
		case KASMP_CORE_2: {
			if (KASMP_NB_CORES > 2u) { identifier = KASMP_SEMA_RX_CORE_2_FULL; }
			break;
		}
		case KASMP_CORE_3: {
			if (KASMP_NB_CORES > 3u) { identifier = KASMP_SEMA_RX_CORE_3_FULL; }
			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}

	if (identifier == NULL) {
		PRIVILEGE_RESTORE;
		return (KERR_ASMP_CORNA);
	}

	while (kern_getSemaphoreById(identifier, semaphore) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }
	PRIVILEGE_RESTORE;
	return (KERR_ASMP_NOERR);
}

/*
 * \brief Get the handle of the TX empty semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    core;
 * sema_t      *semaphore;
 *
 *    status = asmp_getRunningCore(&core);
 *    status = asmp_getSemaphoreTXEmpty(core, &semaphore);
 * \endcode
 *
 * \param[in]	core			Running core number
 * \param[in]	**semaphore		Ptr on the semaphore handle
 * \return		KERR_ASMP_NOERR	OK
 * \return		KERR_ASMP_CORNA	The core number is not not allowed
 *
 */
int32_t	asmp_getSemaphoreTXEmpty(uint32_t core, sema_t **semaphore) {
	const	char_t	*identifier = NULL;

	PRIVILEGE_ELEVATE;
	local_init();

	switch (core) {
		case KASMP_CORE_0: {
			if (KASMP_NB_CORES > 0u) { identifier = KASMP_SEMA_TX_CORE_0_EMPTY; }
			break;
		}
		case KASMP_CORE_1: {
			if (KASMP_NB_CORES > 1u) { identifier = KASMP_SEMA_TX_CORE_1_EMPTY; }
			break;
		}
		case KASMP_CORE_2: {
			if (KASMP_NB_CORES > 2u) { identifier = KASMP_SEMA_TX_CORE_2_EMPTY; }
			break;
		}
		case KASMP_CORE_3: {
			if (KASMP_NB_CORES > 3u) { identifier = KASMP_SEMA_TX_CORE_3_EMPTY; }
			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}

	if (identifier == NULL) {
		PRIVILEGE_RESTORE;
		return (KERR_ASMP_CORNA);
	}

	while (kern_getSemaphoreById(identifier, semaphore) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }
	PRIVILEGE_RESTORE;
	return (KERR_ASMP_NOERR);
}

/*
 * \brief Waiting for asmp ready
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = asmp_waitingForReady();
 * \endcode
 *
 * \return		KERR_ASMP_NOERR	OK
 * \return		KERR_ASMP_NORDY	The asmp is not ready
 *
 */
int32_t	asmp_waitingForReady(void) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	local_init();

	status = stub_asmp_waitingForReady();
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
static	void	local_init(void) {
			uint32_t	core;
	static	bool		vInit[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vInit[core] == false) {
		vInit[core] = true;

		vAsmp_InterCore = ALIGNED_PTR(asmpShared_t, linker_stShare);

		stub_asmp_init();
	}
	INTERRUPTION_RESTORE;
}

#endif
