/*
; mutexes.
; ========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Mutex management.
;
;			This module implements the mutex primitives.
;
;			Mutex system calls
;			------------------
;
;			void	mutexes_init(void);
;			int32_t	kern_createMutex(const char_t *identifier, mutx_t **handle);
;			int32_t	kern_unlockMutex(mutx_t *handle);
;			int32_t	kern_lockMutex(mutx_t *handle, uint32_t timeout);
;			int32_t	kern_killMutex(mutx_t *handle);
;			int32_t	kern_restartMutex(mutx_t *handle);
;			int32_t	kern_getMutexById(const char_t identifier, mutx_t **handle);
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
#include	"kern/private/private_mutexes.h"
#include	"kern/private/private_processes.h"
#include	"kern/private/private_identifiers.h"
#include	"kern/private/private_lists.h"

mutx_t		vKern_mutx[KNB_CORES][KKERN_NB_MUTEXES];
uint16_t	vKern_nbMutx[KNB_CORES];
uint16_t	vKern_nbMaxMutx[KNB_CORES];

// Prototypes

static	int32_t	local_createMutex(const char_t *identifier, int32_t iniCounter, int32_t maxCounter, mutx_t **handle);
static	int32_t	local_waitMutex(uint32_t core, mutx_t *handle, uint32_t timeout);
static	int32_t	local_signalMutex(uint32_t core, mutx_t *handle, bool *preemption);

/*
 * \brief Initialise the manager
 *
 * - This function initialises the "mutexes" manager
 *   Before using the manager functions, it is necessary to
 *   call this function
 *
 *
 * \note This function does not return a value (None).
 *
 */
void	mutexes_init(void) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	for (i = 0u; i < KKERN_NB_MUTEXES; i++) {
		vKern_mutx[core][i].oIdentifier = nullptr;
		vKern_mutx[core][i].oState      = 0u;
		vKern_mutx[core][i].oCounter    = 0;
		vKern_mutx[core][i].oMaxCounter = 0;
		vKern_mutx[core][i].oOwner		= nullptr;
		lists_initialise(&vKern_mutx[core][i].oList);
	}

	vKern_nbMutx[core]	  = 0u;
	vKern_nbMaxMutx[core] = 0u;
	DEBUG_KERN_TRACE("exit: OK");
}

/*
 * \brief Create a mutex
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          mutx_t     *mutex;
 * const    char_t     identifier[] = ”Mutex 0”;
 *
 *    status = kern_createMutex(identifier, &mutex);
 * \endcode
 *
 * \param[in]	*identifier		Ptr on the mutex identifier (nullptr = anonymous)
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_MUFUL	No more mutex
 * \return		KERR_KERN_IDMUT	The mutex identifier is already used
 *
 */
int32_t	kern_createMutex(const char_t *identifier, mutx_t **handle) {
	int32_t		status;

	DEBUG_KERN_TRACE("entry: ");

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	status = local_createMutex(identifier, 0u, KMUTX_MAX_CPT, handle);
	DEBUG_KERN_TRACE("exit: ->");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Unlock a mutex
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * mutx_t     *mutex;
 *
 *    status = kern_lockMutex(mutex);
 *    // Atomic access code portion
 *    status = kern_unlockMutex(mutex);
 * \endcode
 *
 * - counter++
 * - If (counter <= 0)
 *   - Then disconnect the first process from the mutex list (accordingly to the number of events)
 *   - Connect the process to the execution list
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMUT	The mutex does not exist
 * \return		KERR_KERN_MUTME	The mutex counts too many events
 * \return		KERR_KERN_MUNOW	The process is not the owner of the mutex
 * \return		KERR_KERN_FRISR	Execution from ISR
 *
 */
int32_t	kern_unlockMutex(mutx_t *handle) {
	bool		preemption = false;
	uint32_t	core;
	int32_t		status;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	status = local_signalMutex(core, handle, &preemption);
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	DEBUG_KERN_TRACE("exit: ->");
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief lock a mutex
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * mutx_t     *mutex;
 *
 *    status = kern_lockMutex(mutex);
 *    // Atomic access code portion
 *    status = kern_unlockMutex(mutex);
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
 * \return		KERR_KERN_NOMUT	The mutex does not exist
 * \return		KERR_KERN_MUTME	The mutex counts too many events
 * \return		KERR_KERN_MUKIL	The mutex has been killed (with processes in its list)
 * \return		KERR_KERN_TIMEO	Timeout
 * \return		KERR_KERN_FRISR	Execution from ISR
 *
 */
int32_t	kern_lockMutex(mutx_t *handle, uint32_t timeout) {
	uint32_t	core;
	int32_t		status;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	status = local_waitMutex(core, handle, timeout);
	DEBUG_KERN_TRACE("exit: ->");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Kill the mutex
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * mutx_t     *mutex;
 *
 *    status = kern_killMutex(mutex);
 * \endcode
 *
 * - If (process still connected to the mutex list)
 *   - Then return error
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMUT	The mutex does not exist
 *
 */
int32_t	kern_killMutex(mutx_t *handle) {
	bool		preemption = false;
	uint32_t	core;
	proc_t		*process;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)								{ DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOMUT); }
	if ((handle->oState & (1u<<BMUTX_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOMUT); }

// Disconnect the waiting processes from the mutex list

	while (handle->oList.oNbElements > 0u) {
		process = handle->oList.oFirst;
		process->oInternal.oState &= (uint16_t)~(1u<<BPROC_SUSP_MUTX);
		lists_disconnectConnect(&handle->oList, &vKern_listExec[core], process);
		process->oInternal.oStatus = KERR_KERN_MUKIL;

// If the ready process has a higher priority, then preemption occurs

		preemption = (process->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority) ? (true) : (false);
	}

	handle->oIdentifier = nullptr;
	handle->oState      = 0u;
	handle->oCounter    = 0;
	handle->oMaxCounter = 0;
	handle->oOwner	    = nullptr;

	if (vKern_nbMutx[core] != 0u) { vKern_nbMutx[core] = (uint16_t)(vKern_nbMutx[core] - 1u); }
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Restart the mutex
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * mutx_t     *mutex;
 *
 *    status = kern_restartMutex(mutex);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMUT	The mutex does not exist
 *
 */
int32_t	kern_restartMutex(mutx_t *handle) {
	bool		preemption = false;
	uint32_t	core;
	proc_t		*process;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)								{ DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOMUT); }
	if ((handle->oState & (1u<<BMUTX_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOMUT); }

	while (handle->oList.oNbElements > 0u) {
		process = handle->oList.oFirst;
		process->oInternal.oState &= (uint16_t)~(1u<<BPROC_SUSP_MUTX);
		lists_disconnectConnect(&handle->oList, &vKern_listExec[core], process);
		process->oInternal.oStatus = KERR_KERN_NOERR;

// If the ready process has a higher priority, then preemption occurs

		preemption = (process->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority) ? (true) : (false);
	}
	handle->oCounter    = 0;
	handle->oMaxCounter = KMUTX_MAX_CPT;
	handle->oOwner	    = nullptr;
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Get the handle of a mutex by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 *          mutx_t     *mutex;
 * const    char_t     identifier[] = ”Mutex 0”;
 *
 *    status = kern_getMutexById(identifier, &mutex);
 * \endcode
 *
 * - This function returns the handle of the mutex
 *
 * \param[in]	*identifier		Ptr on the mutex identifier
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMUT	The mutex does not exist
 *
 */
int32_t	kern_getMutexById(const char_t *identifier, mutx_t **handle) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*handle = nullptr;

	for (i = 0u; i < KKERN_NB_MUTEXES; i++) {
		if (identifiers_cmpStrings(vKern_mutx[core][i].oIdentifier, identifier) == true) {
			*handle = &vKern_mutx[core][i];
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 1");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOMUT);
}

// Local routines
// ==============

/*
 * \brief local_createMutex
 *
 * \param[in]	*identifier		Ptr on the mutex identifier (nullptr = anonymous)
 * \param[in]	iniCounter		Initial counter value
 * \param[in]	maxCounter		Max counter value
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_MUFUL	No more mutex
 * \return		KERR_KERN_IDMUT	The mutex identifier is already used
 *
 */
static	int32_t	local_createMutex(const char_t *identifier, int32_t iniCounter, int32_t maxCounter, mutx_t **handle) {
	uint16_t	i;
	uint32_t	core;

	core = GET_RUNNING_CORE;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*handle = nullptr;

// Check if the identifier is already used (nullptr = anonymous)
// If the identifier is already used, then, return an error but
// with the handle of the previously created object

	if (identifier != nullptr) {
		for (i = 0u; i < KKERN_NB_MUTEXES; i++) {
			if (identifiers_cmpStrings(vKern_mutx[core][i].oIdentifier, identifier) == true) {
				*handle = &vKern_mutx[core][i];
				DEBUG_KERN_TRACE("exit: KO 1");
				return (KERR_KERN_IDMUT);
			}

		}
	}

	for (i = 0u; i < KKERN_NB_MUTEXES; i++) {
		if (vKern_mutx[core][i].oIdentifier == nullptr) {
			vKern_mutx[core][i].oIdentifier  = (identifier == nullptr) ? (KMUTX_ANONYMOUS_ID) : (identifier);
			vKern_mutx[core][i].oState       = (1u<<BMUTX_INSTALLED);
			vKern_mutx[core][i].oCounter     = iniCounter;
			vKern_mutx[core][i].oMaxCounter  = maxCounter;
			vKern_mutx[core][i].oOwner		 = nullptr;
			*handle = &vKern_mutx[core][i];

			vKern_nbMutx[core]    = (uint16_t)(vKern_nbMutx[core] + 1u);
			vKern_nbMaxMutx[core] = (vKern_nbMutx[core] > vKern_nbMaxMutx[core]) ? (vKern_nbMutx[core]) : (vKern_nbMaxMutx[core]);
			DEBUG_KERN_TRACE("exit: OK");
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 2");
	return (KERR_KERN_MUFUL);
}

/*
 * \brief local_waitMutex
 *
 * \param[in]	core			Core number
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	timeout			Timeout (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMUT	The mutex does not exist
 * \return		KERR_KERN_MUTME	The mutex counts too many events
 * \return		KERR_KERN_MUKIL	The mutex has been killed (with processes in its list)
 * \return		KERR_KERN_TIMEO	Timeout
 * \return		KERR_KERN_FRISR	Execution from ISR
 *
 */
static	int32_t	local_waitMutex(uint32_t core, mutx_t *handle, uint32_t timeout) {
	uint32_t	i, synchro, wkTimeout;

	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (IS_EXCEPTION)								    { DEBUG_KERN_TRACE("exit: KO 1"); return (KERR_KERN_FRISR); }
	if (handle == nullptr) 				   			    { DEBUG_KERN_TRACE("exit: KO 2"); return (KERR_KERN_NOMUT); }
	if ((handle->oState & (1u<<BMUTX_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 3"); return (KERR_KERN_NOMUT); }
	if (handle->oCounter == KMUTX_MIN_CPT) 			    { DEBUG_KERN_TRACE("exit: KO 5"); return (KERR_KERN_MUTME); }

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

	if ((handle->oCounter >= 0) || (handle->oOwner == vKern_runProc[core])) {
		handle->oCounter--;
		handle->oOwner = vKern_runProc[core];
		DEBUG_KERN_TRACE("exit: OK");
		return (KERR_KERN_NOERR);
	}

	if (wkTimeout > 0u) {
		i = (uint32_t)(((uintptr_t)handle - (uintptr_t)&vKern_mutx[core][0]) / sizeof(mutx_t));
		synchro = KKERN_MSG_WAIT_MUTX_SYN + (i & 0x0000FFFFu);
		(void)synchro;

		GOTO_KERN_M(synchro);
		DEBUG_KERN_TRACE("exit: ->");
		return (vKern_runProc[core]->oInternal.oStatus);
	}

	DEBUG_KERN_TRACE("exit: KO 6");
	return (KERR_KERN_TIMEO);
}

/*
 * \brief local_signalMutex
 *
 * \param[in]	core			Core number
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	*preemption		Ptr on the preemption
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOMUT	The mutex does not exist
 * \return		KERR_KERN_MUTME	The mutex counts too many events
 * \return		KERR_KERN_MUNOW	The process is not the owner of the mutex
 * \return		KERR_KERN_FRISR	Execution from ISR
 *
 */
static	int32_t	local_signalMutex(uint32_t core, mutx_t *handle, bool *preemption) {
	proc_t	*process;

	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (IS_EXCEPTION)								    { DEBUG_KERN_TRACE("exit: KO 1"); return (KERR_KERN_FRISR); }
	if (handle == nullptr)                  			{ DEBUG_KERN_TRACE("exit: KO 2"); return (KERR_KERN_NOMUT); }
	if ((handle->oState & (1u<<BMUTX_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 3"); return (KERR_KERN_NOMUT); }
	if (handle->oCounter == KMUTX_MAX_CPT)  		    { DEBUG_KERN_TRACE("exit: KO 5"); return (KERR_KERN_MUTME); }
	if (handle->oOwner != vKern_runProc[core]) 		    { DEBUG_KERN_TRACE("exit: KO 6"); return (KERR_KERN_MUNOW); }

	handle->oCounter++;
	if (handle->oCounter < 0)     					    { DEBUG_KERN_TRACE("exit: OK");   return (KERR_KERN_NOERR); }

// The owner released the mutex
// No new owner is waiting for the mutex
// The new mutex counter remains = 0

	if (handle->oList.oNbElements == 0u) {
		handle->oOwner = nullptr;
		DEBUG_KERN_TRACE("exit: OK");
		return (KERR_KERN_NOERR);
	}

// The owner released the mutex
// The new owner is extracted from the list
// The new mutex counter has to be = -1

	process = handle->oList.oFirst;
	process->oInternal.oState &= (uint16_t)~(1u<<BPROC_SUSP_MUTX);
	lists_disconnectConnect(&handle->oList, &vKern_listExec[core], process);
	process->oInternal.oStatus = KERR_KERN_NOERR;

	handle->oOwner = process;
	handle->oCounter = -1;

// If the ready process has a higher priority, then preemption occurs

	*preemption = (process->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority) ? (true) : (false);

	DEBUG_KERN_TRACE("exit: OK");
	return (KERR_KERN_NOERR);
}
