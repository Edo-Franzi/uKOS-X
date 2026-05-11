/*
; signals.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Signal management.
;
;			This module implements the signals primitives.
;
; 			Software signal system calls
; 			----------------------------
;
;			void	signals_init(void);
;			int32_t	kern_createSignalGroup(const char_t *identifier, sign_t **handle);
;			int32_t	kern_createBitSignal(sign_t *handle, uint8_t *bit);
;			int32_t	kern_signalSignal(sign_t *handle, uint32_t signals, proc_t *toProcess, uint32_t mode);
;			int32_t	kern_waitSignal(sign_t *handle, uint32_t *signals, proc_t *fromProcess, uint32_t timeout);
;			int32_t	kern_getWaitingSignalMask(sign_t *handle, uint32_t *waitingSignals);
;			int32_t	kern_clearPendingSignal(sign_t *handle, uint32_t toClearMask);
;			int32_t	kern_killSignalGroup(sign_t *handle);
;			int32_t	kern_killBitSignal(sign_t *handle, uint8_t bitSignal);
;			int32_t	kern_getSignalGroupById(char_t *identifier, sign_t **handle);
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
#include	"kern/private/private_signals.h"
#include	"kern/private/private_processes.h"
#include	"kern/private/private_identifiers.h"
#include	"kern/private/private_lists.h"

sign_t		vKern_sign[KNB_CORES][KKERN_NB_SIGNALS];
list_t		vKern_listSign[KNB_CORES];
uint16_t	vKern_nbSign[KNB_CORES];
uint16_t	vKern_nbMaxSign[KNB_CORES];

/*
 * \brief Initialise the manager
 *
 * - This function initialises the "signals" manager
 *   Before using the manager functions, it is necessary to
 *   call this function
 *
 *
 * \note This function does not return a value (None).
 *
 */
void	signals_init(void) {
	uint16_t	i, j;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	for (i = 0u; i < KKERN_NB_SIGNALS; i++) {
		vKern_sign[core][i].oIdentifier  = nullptr;
		vKern_sign[core][i].oState		 = 0u;
		vKern_sign[core][i].oGroupNumber = 0u;
		vKern_sign[core][i].oUsedBit     = 0u;

		for (j = 0u; j < KKERN_NB_PROCESSES; j++) {
			vKern_sign[core][i].oSynchro[j].oSignalBitPending  = 0u;
			vKern_sign[core][i].oSynchro[j].oSignalBitGenerate = 0u;
			vKern_sign[core][i].oSynchro[j].oSignalFromProcess = nullptr;
		}
	}
	lists_initialise(&vKern_listSign[core]);

	vKern_nbSign[core]	  = 0u;
	vKern_nbMaxSign[core] = 0u;
	DEBUG_KERN_TRACE("exit: OK");
}

/*
 * \brief Create a signal group
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t      status;
 *          sign_t       *signalGroup;
 * const    char_t       identifier[] = ”Chrono trigger”;
 *
 *    status = kern_createSignalGroup(identifier, &signalGroup);
 * \endcode
 *
 * \param[in]	*identifier		Ptr on the signal group identifier (nullptr = anonymous)
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_SIFUL	No more signal group
 * \return		KERR_KERN_IDSIO	The signal group identifier is already used
 *
 */
int32_t	kern_createSignalGroup(const char_t *identifier, sign_t **handle) {
	uint16_t	i, j;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*handle = nullptr;

// Check if the identifier is already used (nullptr = anonymous)
// If the identifier is already used, then, return an error but
// with the handle of the previously created object

	if (identifier != nullptr) {
		for (i = 0u; i < KKERN_NB_SIGNALS; i++) {
			if (identifiers_cmpStrings(vKern_sign[core][i].oIdentifier, identifier) == true) {
				*handle = &vKern_sign[core][i];
				DEBUG_KERN_TRACE("exit: KO 2");
				INTERRUPTION_RESTORE;
				PRIVILEGE_RESTORE;
				return (KERR_KERN_IDSIO);
			}

		}
	}

	for (i = 0u; i < KKERN_NB_SIGNALS; i++) {
		if (vKern_sign[core][i].oIdentifier  == nullptr) {
			vKern_sign[core][i].oIdentifier   = (identifier == nullptr) ? (KSIGN_ANONYMOUS_ID) : (identifier);
			vKern_sign[core][i].oState		  = (1u<<BSIGN_INSTALLED);
			vKern_sign[core][i].oGroupNumber  = i;
			vKern_sign[core][i].oUsedBit      = 0u;

			for (j = 0u; j < KKERN_NB_PROCESSES; j++) {
				vKern_sign[core][i].oSynchro[j].oSignalBitPending  = 0u;
				vKern_sign[core][i].oSynchro[j].oSignalBitGenerate = 0u;
				vKern_sign[core][i].oSynchro[j].oSignalFromProcess = nullptr;
			}
			*handle = &vKern_sign[core][i];

			vKern_nbSign[core]    = (uint16_t)(vKern_nbSign[core] + 1u);
			vKern_nbMaxSign[core] = (vKern_nbSign[core] > vKern_nbMaxSign[core]) ? (vKern_nbSign[core]) : (vKern_nbMaxSign[core]);
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 3");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_SIFUL);
}

/*
 * \brief Create a bit signal
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uint8_t      bitSignal;
 * sign_t       *signalGroup;
 *
 *    status = kern_createBitSignal(signalGroup, &bitSignal);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[out]	*bitSignal		Ptr on the bitSignal (0..31)
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOGRO	The signal group does not exist
 * \return		KERR_KERN_NOSIG	No more bitSignal
 *
 */
int32_t	kern_createBitSignal(sign_t *handle, uint8_t *bitSignal) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)								{ DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOGRO); }
	if ((handle->oState & (1u<<BSIGN_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOGRO); }

	for (i = 0u; i < KSIGN_NB_SIGNALS_PER_GROUP; i++) {
		if ((handle->oUsedBit & (1u<<i)) == 0u) {
			handle->oUsedBit |= (uint32_t)(1u<<i);
			*bitSignal = (uint8_t)i;
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	*bitSignal = 0u;
	DEBUG_KERN_TRACE("exit: KO 3");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOSIG);
}

/*
 * \brief set the signals
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uint32_t     Signals;
 * sign_t       *signalGroup;
 * proc_t       *toProcess;
 *
 *    while (kern_getProcessById(“My process”, &toProcess) != KERR_KERN_NOERR) {
 *        kern_suspendProcess(1u);
 *    }
 *
 * // Mode selective
 *
 *    status = kern_signalSignal(signalGroup, signals, toProcess, KSIGN_SIGNALE_WITH_CONTEXT_SWITCH);
 *
 * // Mode broadcast
 *
 *    status = kern_signalSignal(signalGroup, signals, KKERN_HANDLE_BROADCAST, KSIGN_SIGNALE_WITH_CONTEXT_SWITCH);
 * \endcode
 *
 * - If (mode == KSIGN_SIGNALE_WITH_CONTEXT_SWITCH)
 *   - With the context switching
 *
 * - If (mode == KSIGN_SIGNALE_WITHOUT_CONTEXT_SWITCH)
 *   - Without the context switching
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	signals			Signals
 * \param[in]	*toProcess		Ptr on the process handle (selective signal)
 *								KKERN_HANDLE_BROADCAST, broadcast to all the installed processes the signals
 * \param[in]	mode			KSIGN_SIGNALE_WITH_CONTEXT_SWITCH		-> (synchro with the context switching)
 *								KSIGN_SIGNALE_WITHOUT_CONTEXT_SWITCH	-> (synchro without the context switching)
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOGRO	The signal group does not exist
 * \return		KERR_KERN_NOPRO	The process does not exist
 *
 */
int32_t	kern_signalSignal(sign_t *handle, uint32_t signals, proc_t *toProcess, uint32_t mode) {
	uint16_t	i;
	uint32_t	core, theSignals;
	bool		preemption = false;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)								{ DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOGRO); }
	if ((handle->oState & (1u<<BSIGN_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOGRO); }
	if (toProcess == nullptr)							{ DEBUG_KERN_TRACE("exit: KO 3"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRO); }

	if (toProcess == KKERN_HANDLE_BROADCAST) {

// Process broadcast signal
// ------------------------

		for (i = 0u; i < KKERN_NB_PROCESSES; i++) {
			if ((vKern_proc[core][i].oInternal.oState & (1u<<BPROC_INSTALLED)) != 0u) {
				if (&vKern_proc[core][i] != vKern_runProc[core]) {
					handle->oSynchro[i].oSignalBitPending |= signals;
					if ((vKern_proc[core][i].oInternal.oState & (1u<<BPROC_SUSP_SIGN)) != 0u) {
						theSignals = handle->oSynchro[i].oSignalBitGenerate & signals;
						if ((theSignals != 0) && ((handle->oSynchro[i].oSignalFromProcess == vKern_runProc[core]) || (handle->oSynchro[i].oSignalFromProcess == KKERN_HANDLE_BROADCAST) || (handle->oSynchro[i].oSignalFromProcess == KKERN_HANDLE_FROM_ISR))) {
							vKern_proc[core][i].oInternal.oState &= (uint16_t)~(1u<<BPROC_SUSP_SIGN);
							lists_disconnectConnect(vKern_proc[core][i].oObject.oList, &vKern_listExec[core], &vKern_proc[core][i]);
							vKern_proc[core][i].oInternal.oStatus = KERR_KERN_NOERR;

// mode == KSIGN_SIGNALE_WITH_CONTEXT_SWITCH
// If the ready process has a higher priority, then preemption occurs

							preemption = ((mode == KSIGN_SIGNALE_WITH_CONTEXT_SWITCH) && (vKern_proc[core][i].oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority)) ? (true) : (false);
						}
					}
				}
			}
		}
	}
	else {

// Process selective signal
// ------------------------

		i = (uint16_t)(((uintptr_t)toProcess - (uintptr_t)&vKern_proc[core][0]) / sizeof(proc_t));

		if ((toProcess->oInternal.oState & (1u<<BPROC_INSTALLED)) != 0u) {
			handle->oSynchro[i].oSignalBitPending |= signals;
			if ((toProcess->oInternal.oState & (1u<<BPROC_SUSP_SIGN)) != 0) {
				theSignals = handle->oSynchro[i].oSignalBitGenerate & signals;
				if ((theSignals != 0u) && ((handle->oSynchro[i].oSignalFromProcess == vKern_runProc[core]) || (handle->oSynchro[i].oSignalFromProcess == KKERN_HANDLE_BROADCAST) || (handle->oSynchro[i].oSignalFromProcess == KKERN_HANDLE_FROM_ISR))) {
					toProcess->oInternal.oState &= (uint16_t)~(1u<<BPROC_SUSP_SIGN);
					lists_disconnectConnect(toProcess->oObject.oList, &vKern_listExec[core], toProcess);
					toProcess->oInternal.oStatus = KERR_KERN_NOERR;

// mode == KSIGN_SIGNALE_WITH_CONTEXT_SWITCH
// If the ready process has a higher priority, then preemption occurs

					preemption = ((mode == KSIGN_SIGNALE_WITH_CONTEXT_SWITCH) && (toProcess->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority)) ? (true) : (false);
				}
			}
		}
		else {
			DEBUG_KERN_TRACE("exit: KO 4");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOPRO);
		}

	}
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Wait for the signals
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uint32_t     waitSignals;
 * sign_t       *signalGroup;
 * proc_t       *fromProcess;
 *
 * #define    BMYSIGNAL    3
 *
 *    status = kern_getSignalGroupById(“Chrono trigger”, &signalGroup);
 *
 *    waitSignals = (1u<<BMYSIGNAL)
 *    status = kern_waitSignal(signalGroup, &waitSignals, fromProcess, 1000);
 * \endcode
 *
 * - Disconnect a process from the execution list
 * - Connect the process to the signal list
 *
 * \param[in]		*handle			Ptr on the handle
 * \param[in, out]	*signals		Ptr on the signal (1 or more)
 * \param[in]		*fromProcess	Ptr on the process handle (selective signal)
 *									KKERN_HANDLE_BROADCAST, broadcast to all the installed processes the signals
 *									KKERN_HANDLE_FROM_ISR, selective signal coming from an ISR
 * \param[in]		timeout			Timeout (1-ms of resolution)
 *									KWAIT_INFINITY, waiting forever
 *									KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return			KERR_KERN_NOERR	OK
 * \return			KERR_KERN_NOGRO	The signal group does not exist
 * \return			KERR_KERN_NOPRO	The process does not exist
 * \return			KERR_KERN_SIKIL	The signal has been killed (with processes in its list)
 * \return			KERR_KERN_TIMEO	Timeout
 *
 */
int32_t	kern_waitSignal(sign_t *handle, uint32_t *signals, proc_t *fromProcess, uint32_t timeout) {
	uint16_t	i;
	int32_t		status;
	uint32_t	core, theSignal, wkTimeout;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	if (*signals == 0u) { DEBUG_KERN_TRACE("exit: OK"); return (KERR_KERN_NOERR); }

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)								{ DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOGRO); }
	if ((handle->oState & (1u<<BSIGN_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOGRO); }
	if (fromProcess == nullptr)						    { DEBUG_KERN_TRACE("exit: KO 3"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRO); }

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

	i = (uint16_t)(((uintptr_t)vKern_runProc[core] - (uintptr_t)&vKern_proc[core][0]) / sizeof(proc_t));
	handle->oSynchro[i].oSignalFromProcess = fromProcess;

	theSignal = handle->oSynchro[i].oSignalBitPending & *signals;

	if (theSignal != 0u) {
		handle->oSynchro[i].oSignalBitPending &= ~theSignal;
		*signals = theSignal;
		DEBUG_KERN_TRACE("exit: OK");
		INTERRUPTION_RESTORE;
		PRIVILEGE_RESTORE;
		return (KERR_KERN_NOERR);
	}

// Waiting for the signal

	if (wkTimeout > 0u) {
		handle->oSynchro[i].oSignalBitGenerate |= *signals;

		if (handle->oCbOnWaiting != nullptr) {
			(handle->oCbOnWaiting)(handle, *signals, fromProcess);
		}

		GOTO_KERN_I(KKERN_MSG_WAIT_SIGN);
		theSignal = handle->oSynchro[i].oSignalBitPending & *signals;
		*signals = theSignal;

		handle->oSynchro[i].oSignalBitGenerate &= ~theSignal;
		handle->oSynchro[i].oSignalBitPending  &= ~theSignal;
		DEBUG_KERN_TRACE("exit: ->");
		status = vKern_runProc[core]->oInternal.oStatus;
		INTERRUPTION_RESTORE;
		PRIVILEGE_RESTORE;
		return (status);
	}

	*signals = 0u;
	DEBUG_KERN_TRACE("exit: KO 4");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_TIMEO);
}

/*
 * \brief Retrieve the cumulative bits which are requested by all processes for the signal group
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uint32_t     signal = 0x00000003
 * sign_t       *signalGroup;
 *
 *    status = kern_getWaitingSignalMask(signalGroup, &signal);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[out]	*waitingSignals	Ptr to variable which will hold resulting bit mask
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOGRO	The signal group does not exist
 *
 */
int32_t kern_getWaitingSignalMask(sign_t *handle, uint32_t *waitingSignals) {
	uint16_t	i;
	uint32_t	core, mask;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)								{ DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOGRO); }
	if ((handle->oState & (1u<<BSIGN_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOGRO); }

	mask = 0u;
	for (i = 0u; i < KKERN_NB_PROCESSES; i++) {
		if ((vKern_proc[core][i].oInternal.oState & ((1u<<BPROC_INSTALLED) | (1u<<BPROC_SUSP_SIGN))) == ((1u<<BPROC_INSTALLED) | (1u<<BPROC_SUSP_SIGN))) {
			mask |= handle->oSynchro[i].oSignalBitGenerate;
		}
	}
	*waitingSignals = mask;
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Clear pending signals for the process in the signal group
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uint32_t     mask = 0x00000003
 * sign_t       *signalGroup;
 *
 *    status = kern_clearPendingSignal(signalGroup, mask);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	toClearMask		Signal bit-mask to clear
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOGRO	The signal group does not exist
 *
 */
int32_t kern_clearPendingSignal(sign_t *handle, uint32_t toClearMask) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	if (toClearMask == 0u) { DEBUG_KERN_TRACE("exit: OK"); return (KERR_KERN_NOERR); }

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)								{ DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOGRO); }
	if ((handle->oState & (1u<<BSIGN_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOGRO); }

	i = (uint16_t)(((uintptr_t)vKern_runProc[core] - (uintptr_t)&vKern_proc[core][0]) / sizeof(proc_t));

	handle->oSynchro[i].oSignalBitPending  &= ~toClearMask;
	handle->oSynchro[i].oSignalBitGenerate &= ~toClearMask;
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Kill the signal group
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * sign_t       *signalGroup;
 *
 *    status = kern_killSignalGroup(signalGroup);
 * \endcode
 *
 * - If (process still connected to the signal list)
 *   - Then return error
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOGRO	The signal does not exist
 *
 */
int32_t	kern_killSignalGroup(sign_t *handle) {
	uint16_t	i, j, nbElements;
	uint32_t	core;
	bool		preemption = false;
	proc_t		*process;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)								{ DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOGRO); }
	if ((handle->oState & (1u<<BSIGN_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOGRO); }

// Disconnect the waiting processes from the signal list
// Do not use the "while (vKern_listSign[core].oNbElements > 0) { ... }"

	nbElements = vKern_listSign[core].oNbElements;
	if (nbElements > 0u) {
		for (i = 0u; i < nbElements; i++) {
			process = vKern_listSign[core].oFirst;
			j = (uint16_t)(((uintptr_t)process - (uintptr_t)&vKern_proc[core][0]) / sizeof(proc_t));

			if (handle->oSynchro[j].oSignalBitGenerate != 0u) {
				process->oInternal.oState &= (uint16_t)~(1u<<BPROC_SUSP_SIGN);
				lists_disconnectConnect(process->oObject.oList, &vKern_listExec[core], process);
				process->oInternal.oStatus = KERR_KERN_SIKIL;

// If the ready process has a higher priority, then preemption occurs

				preemption = (process->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority) ? (true) : (false);
			}
		}
	}

	handle->oIdentifier  = nullptr;
	handle->oState       = 0u;
	handle->oGroupNumber = 0u;
	handle->oUsedBit     = 0u;

	for (i = 0; i < KKERN_NB_PROCESSES; i++) {
		handle->oSynchro[i].oSignalBitPending  = 0u;
		handle->oSynchro[i].oSignalBitGenerate = 0u;
		handle->oSynchro[i].oSignalFromProcess = nullptr;
	}

	if (vKern_nbSign[core] != 0) { vKern_nbSign[core] = (uint16_t)(vKern_nbSign[core] - 1u); }
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Kill a bit signal
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uint8_t      bitSignal;
 * sign_t       *signalGroup;
 *
 *    status = kern_killBitSignal(signalGroup, bitSignal);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[out]	*bitSignal		Ptr on the bitSignal (0..31)
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOGRO	The signal group does not exist
 *
 */
int32_t	kern_killBitSignal(sign_t *handle, uint8_t bitSignal) {
	uint32_t	core, maskBit;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)								    { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOGRO); }
	if ((handle->oState & (1u<<BSIGN_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOGRO); }

	maskBit = (uint32_t)(1u<<bitSignal);
	handle->oUsedBit &= ~maskBit;
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Get the handle of an signal group by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t      status;
 *          sign_t       *signalGroup;
 * const    char_t       identifier[] = ”Signal 0”;
 *
 *    status = kern_getSignalGroupById(identifier, &signalGroup);
 * \endcode
 *
 * - This function returns the handle of the signal
 *
 * \param[in]	*identifier		Ptr on the signal group identifier
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOGRO	The signal group does not exist
 *
 */
int32_t	kern_getSignalGroupById(const char_t *identifier, sign_t **handle) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*handle = nullptr;

	for (i = 0u; i < KKERN_NB_SIGNALS; i++) {
		if (identifiers_cmpStrings(vKern_sign[core][i].oIdentifier, identifier) == true) {
			*handle = &vKern_sign[core][i];
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 1");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOGRO);
}
