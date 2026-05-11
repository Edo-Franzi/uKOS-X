/*
; semaphores.
; ===========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Semaphore management.
;
;			This module implements the semaphore primitives.
;
;			Semaphore system calls
;			----------------------
;
;			void	semaphores_init(void);
;			int32_t	kern_createSemaphore(const char_t *identifier, int32_t iniCounter, int32_t maxCounter, sema_t **handle);
;			int32_t	kern_signalSemaphore(sema_t *handle);
;			int32_t	kern_waitSemaphore(sema_t *handle, uint32_t timeout);
;			int32_t	kern_killSemaphore(sema_t *handle);
;			int32_t	kern_restartSemaphore(sema_t *handle);
;			int32_t	kern_getSemaphoreById(const char_t identifier, sema_t **handle);
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
#include	"kern/private/private_kern.h"
#include	"kern/private/private_semaphores.h"
#include	"kern/private/private_processes.h"
#include	"kern/private/private_identifiers.h"
#include	"kern/private/private_lists.h"

sema_t		vKern_sema[KNB_CORES][KKERN_NB_SEMAPHORES];
uint16_t	vKern_nbSema[KNB_CORES];
uint16_t	vKern_nbMaxSema[KNB_CORES];

// Prototypes

static	int32_t	local_createSemaphore(const char_t *identifier, int32_t iniCounter, int32_t maxCounter, sema_t **handle);
static	int32_t	local_waitSync(uint32_t core, sema_t *handle, uint32_t timeout);
static	int32_t	local_signalSync(uint32_t core, sema_t *handle, bool *preemption);

/*
 * \brief Initialise the manager
 *
 * - This function initialises the "semaphores" manager
 *   Before using the manager functions, it is necessary to
 *   call this function
 *
 *
 * \note This function does not return a value (None).
 *
 */
void	semaphores_init(void) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	for (i = 0u; i < KKERN_NB_SEMAPHORES; i++) {
		vKern_sema[core][i].oIdentifier = nullptr;
		vKern_sema[core][i].oState      = 0u;
		vKern_sema[core][i].oCounter    = 0;
		vKern_sema[core][i].oMaxCounter = 0;
		vKern_sema[core][i].oOwner		= nullptr;
		lists_initialise(&vKern_sema[core][i].oList);
	}

	vKern_nbSema[core]	  = 0u;
	vKern_nbMaxSema[core] = 0u;
	DEBUG_KERN_TRACE("exit: OK");
}

/*
 * \brief Create a generic semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          int32_t    iniCounter = 5;
 *          int32_t    maxCounter = 1;
 *          sema_t     *semaphore;
 * const    char_t     identifier[] = ”Semaphore 0”;
 *
 *    status = kern_createSemaphore(identifier, iniCounter, maxCounter, &semaphore);
 * \endcode
 *
 * \param[in]	*identifier		Ptr on the semaphore identifier (nullptr = anonymous)
 * \param[in]	iniCounter		Initial counter value
 * \param[in]	maxCounter		Max counter value
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_SEFUL	No more semaphore
 * \return		KERR_KERN_IDSEM	The semaphore identifier is already used
 *
 */
int32_t	kern_createSemaphore(const char_t *identifier, int32_t iniCounter, int32_t maxCounter, sema_t **handle) {
	int32_t		status;

	DEBUG_KERN_TRACE("entry: ");

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	status = local_createSemaphore(identifier, iniCounter, maxCounter, handle);
	DEBUG_KERN_TRACE("exit: ->");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Signal a semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * sema_t     *semaphore;
 *
 *    status = kern_signalSemaphore(semaphore);
 * \endcode
 *
 * - counter++
 * - If (counter <= 0)
 *   - Then disconnect the first process from the semaphore list (accordingly to the number of events)
 *   - Connect the process to the execution list
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSEM	The semaphore does not exist
 * \return		KERR_KERN_SETME	The semaphore counts too many events
 *
 */
int32_t	kern_signalSemaphore(sema_t *handle) {
	bool		preemption = false;
	uint32_t	core;
	int32_t		status;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	status = local_signalSync(core, handle, &preemption);
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	DEBUG_KERN_TRACE("exit: ->");
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Wait for a semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * sema_t     *semaphore;
 *
 *    status = kern_waitSemaphore(semaphore, timeout);
 * \endcode
 *
 * - counter -= 1
 * - If (counter < 0)
 *   - Then suspend the process
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	timeout			Timeout (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSEM	The semaphore does not exist
 * \return		KERR_KERN_SETME	The semaphore counts too many events
 * \return		KERR_KERN_SEKIL	The semaphore has been killed (with processes in its list)
 * \return		KERR_KERN_TIMEO	Timeout
 *
 */
int32_t	kern_waitSemaphore(sema_t *handle, uint32_t timeout) {
	uint32_t	core;
	int32_t		status;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	status = local_waitSync(core, handle, timeout);
	DEBUG_KERN_TRACE("exit: ->");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Kill the semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * sema_t     *semaphore;
 *
 *    status = kern_killSemaphore(semaphore);
 * \endcode
 *
 * - If (process still connected to the semaphore list)
 *   - Then return error
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSEM	The semaphore does not exist
 *
 */
int32_t	kern_killSemaphore(sema_t *handle) {
	bool		preemption = false;
	uint32_t	core;
	proc_t		*process;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)							 	{ DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOSEM); }
	if ((handle->oState & (1u<<BSEMA_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOSEM); }

// Disconnect the waiting processes from the semaphore list

	while (handle->oList.oNbElements > 0u) {
		process = handle->oList.oFirst;
		process->oInternal.oState &= (uint16_t)~(1u<<BPROC_SUSP_SEMA);
		lists_disconnectConnect(&handle->oList, &vKern_listExec[core], process);
		process->oInternal.oStatus = KERR_KERN_SEKIL;

// If the ready process has a higher priority, then preemption occurs

		preemption = (process->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority) ? (true) : (false);
	}

	handle->oIdentifier = nullptr;
	handle->oState      = 0u;
	handle->oCounter    = 0;
	handle->oMaxCounter = 0;
	handle->oOwner	    = nullptr;

	if (vKern_nbSema[core] != 0u) { vKern_nbSema[core] = (uint16_t)(vKern_nbSema[core] - 1u); }
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Restart the semaphore
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * sema_t     *semaphore;
 *
 *    status = kern_restartSemaphore(semaphore);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSEM	The semaphore does not exist
 *
 */
int32_t	kern_restartSemaphore(sema_t *handle) {
	bool		preemption = false;
	uint32_t	core;
	proc_t		*process;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)								{ DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOSEM); }
	if ((handle->oState & (1u<<BSEMA_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOSEM); }

	while (handle->oList.oNbElements > 0u) {
		process = handle->oList.oFirst;
		process->oInternal.oState &= (uint16_t)~(1u<<BPROC_SUSP_SEMA);
		lists_disconnectConnect(&handle->oList, &vKern_listExec[core], process);
		process->oInternal.oStatus = KERR_KERN_NOERR;

// If the ready process has a higher priority, then preemption occurs

		preemption = (process->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority) ? (true) : (false);
	}
	handle->oCounter    = 0;
	handle->oMaxCounter = KSEMA_MAX_CPT;
	handle->oOwner	    = nullptr;
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Get the handle of a semaphore by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          sema_t     *semaphore;
 * const    char_t     identifier[] = ”Semaphore 0”;
 *
 *    status = kern_getSemaphoreById(identifier, &semaphore);
 * \endcode
 *
 * - This function returns the handle of the semaphore
 *
 * \param[in]	*identifier		Ptr on the semaphore identifier
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSEM	The semaphore does not exist
 *
 */
int32_t	kern_getSemaphoreById(const char_t *identifier, sema_t **handle) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*handle = nullptr;

	for (i = 0u; i < KKERN_NB_SEMAPHORES; i++) {
		if (identifiers_cmpStrings(vKern_sema[core][i].oIdentifier, identifier) == true) {
			*handle = &vKern_sema[core][i];
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 1");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOSEM);
}

// Local routines
// ==============

/*
 * \brief local_createSemaphore
 *
 * \param[in]	*identifier		Ptr on the semaphore identifier (nullptr = anonymous)
 * \param[in]	iniCounter		Initial counter value
 * \param[in]	maxCounter		Max counter value
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_SEFUL	No more semaphore
 * \return		KERR_KERN_IDSEM	The semaphore identifier is already used
 *
 */
static	int32_t	local_createSemaphore(const char_t *identifier, int32_t iniCounter, int32_t maxCounter, sema_t **handle) {
	uint16_t	i;
	uint32_t	core;

	core = GET_RUNNING_CORE;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*handle = nullptr;

// Check if the identifier is already used (nullptr = anonymous)
// If the identifier is already used, then, return an error but
// with the handle of the previously created object

	if (identifier != nullptr) {
		for (i = 0u; i < KKERN_NB_SEMAPHORES; i++) {
			if (identifiers_cmpStrings(vKern_sema[core][i].oIdentifier, identifier) == true) {
				*handle = &vKern_sema[core][i];
				DEBUG_KERN_TRACE("exit: KO 1");
				return (KERR_KERN_IDSEM);
			}

		}
	}

	for (i = 0u; i < KKERN_NB_SEMAPHORES; i++) {
		if (vKern_sema[core][i].oIdentifier == nullptr) {
			vKern_sema[core][i].oIdentifier  = (identifier == nullptr) ? (KSEMA_ANONYMOUS_ID) : (identifier);
			vKern_sema[core][i].oState       = (1u<<BSEMA_INSTALLED);
			vKern_sema[core][i].oCounter     = iniCounter;
			vKern_sema[core][i].oMaxCounter  = maxCounter;
			vKern_sema[core][i].oOwner		 = nullptr;
			*handle = &vKern_sema[core][i];

			vKern_nbSema[core]    = (uint16_t)(vKern_nbSema[core] + 1u);
			vKern_nbMaxSema[core] = (vKern_nbSema[core] > vKern_nbMaxSema[core]) ? (vKern_nbSema[core]) : (vKern_nbMaxSema[core]);
			DEBUG_KERN_TRACE("exit: OK");
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 2");
	return (KERR_KERN_SEFUL);
}

/*
 * \brief local_waitSync
 *
 * \param[in]	core			Core number
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	timeout			Timeout (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSEM	The semaphore does not exist
 * \return		KERR_KERN_SETME	The semaphore counts too many events
 * \return		KERR_KERN_SEKIL	The semaphore has been killed (with processes in its list)
 * \return		KERR_KERN_TIMEO	Timeout
 * \return		KERR_KERN_FRISR	Execution from ISR
 *
 */
static	int32_t	local_waitSync(uint32_t core, sema_t *handle, uint32_t timeout) {
	uint32_t	i, synchro, wkTimeout;

	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if ((IS_EXCEPTION) && (timeout != 0u))			    { DEBUG_KERN_TRACE("exit: KO 1"); return (KERR_KERN_FRISR); }
	if (handle == nullptr) 				   			    { DEBUG_KERN_TRACE("exit: KO 2"); return (KERR_KERN_NOSEM); }
	if ((handle->oState & (1u<<BSEMA_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 3"); return (KERR_KERN_NOSEM); }
	if (handle->oCounter == KSEMA_MIN_CPT) 			    { DEBUG_KERN_TRACE("exit: KO 4"); return (KERR_KERN_SETME); }

// -------------------------- inputs --------------------------		-------------------------------------- output ---------------------------------------
//
// IF (timeout value == ...)										THEN (vKern_runProc[core]->oInternal.oTimeout = ...)	AND (wkTimeout = ...)
//
// == KWAIT_INFINITY			  									= KWAIT_INFINITY										= KWAIT_INFINITY
//					 == KWAIT_REMAINING_TIMEOUT					    = vKern_runProc[core]->oInternal.oTimeout				= vKern_runProc[core]->oInternal.oTimeout
//							  				    == timeout value	= (timeout value / unit)								= (timeout value / unit)

	wkTimeout = (timeout == KWAIT_INFINITY)			 ? (KWAIT_INFINITY)							 : (timeout / KKERN_TIC_TIME);
	wkTimeout = (timeout == KWAIT_REMAINING_TIMEOUT) ? (vKern_runProc[core]->oInternal.oTimeout) : (wkTimeout);
	vKern_runProc[core]->oInternal.oTimeout = wkTimeout;

	handle->oCounter--;
	if (handle->oCounter >= 0) {
		DEBUG_KERN_TRACE("exit: OK");
		return (KERR_KERN_NOERR);
	}

	if (wkTimeout > 0u) {
		i = (uint32_t)(((uintptr_t)handle - (uintptr_t)&vKern_sema[core][0]) / sizeof(sema_t));
		synchro = KKERN_MSG_WAIT_SEMA_SYN + (i & 0x0000FFFFu);
		(void)synchro;

		GOTO_KERN_M(synchro);
		handle->oCounter = (vKern_runProc[core]->oInternal.oStatus == KERR_KERN_TIMEO) ? (handle->oCounter + 1) : (handle->oCounter);
		DEBUG_KERN_TRACE("exit: ->");
		return (vKern_runProc[core]->oInternal.oStatus);
	}

	handle->oCounter++;
	DEBUG_KERN_TRACE("exit: KO 5");
	return (KERR_KERN_TIMEO);
}

/*
 * \brief local_signalSync
 *
 * \param[in]	core			Core number
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	*preemption		Ptr on the preemption
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOSEM	The semaphore does not exist
 * \return		KERR_KERN_SETME	The semaphore counts too many events
 *
 */
static	int32_t	local_signalSync(uint32_t core, sema_t *handle,  bool *preemption) {
	proc_t	*process;

	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)                			 	{ DEBUG_KERN_TRACE("exit: KO 1"); return (KERR_KERN_NOSEM); }
	if ((handle->oState & (1u<<BSEMA_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); return (KERR_KERN_NOSEM); }
	if (handle->oCounter == handle->oMaxCounter)	    { DEBUG_KERN_TRACE("exit: KO 4"); return (KERR_KERN_SETME); }

	handle->oCounter = (handle->oCounter < handle->oMaxCounter) ? (handle->oCounter + 1) : (handle->oCounter);

	if (handle->oList.oNbElements == 0u)				{ DEBUG_KERN_TRACE("exit: OK");   return (KERR_KERN_NOERR); }

// Someone signals an event
// The first process waiting for such event is extracted from the list
// The process that generates the signal is indicated as the owner

	process = handle->oList.oFirst;
	process->oInternal.oState &= (uint16_t)~(1u<<BPROC_SUSP_SEMA);
	lists_disconnectConnect(&handle->oList, &vKern_listExec[core], process);
	process->oInternal.oStatus = KERR_KERN_NOERR;

	handle->oOwner = (IS_EXCEPTION) ? (KKERN_HANDLE_FROM_ISR) : (vKern_runProc[core]);

// If the ready process has a higher priority, then preemption occurs

	*preemption = (process->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority) ? (true) : (false);

	DEBUG_KERN_TRACE("exit: OK");
	return (KERR_KERN_NOERR);
}
