/*
; temporal.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - time management.
;
;			This module implements the temporal and the call-back primitives.
;
; 			Temporal system calls
; 			---------------------
;
;			void	temporal_init(void);
;			int32_t	kern_suspendProcess(uint32_t time);
;			int32_t	kern_setNewTimeout(proc_t *handle, uint32_t timeout);
;			int32_t	kern_resumeProcessWithTimeout(proc_t *handle);
;			int32_t	kern_readRemainingProcessTimeout(uint32_t *timeout);
;			int32_t	kern_switchFast(void);
;			int32_t	kern_readTickCount(uint64_t *tickCount);
;			int32_t	kern_waitAtLeast(uint16_t time);
;			int32_t	kern_hasPendingTimeoutProcesses(bool *nonInfTOActive);
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
#include	"kern/private/private_temporal.h"
#include	"kern/private/private_processes.h"

			list_t		vKern_listWait[KNB_CORES];
volatile	uint32_t	vKern_TimeException[KNB_CORES] = MCSET(0u);

/*
 * \brief Initialise the manager
 *
 * - This function initialises the "temporal" manager
 *   Before using the manager functions, it is necessary to
 *   call this function
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
void	temporal_init(void) {
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;
	lists_initialise(&vKern_listWait[core]);
	DEBUG_KERN_TRACE("exit: OK");
}

/*
 * \brief Suspend the process for a time
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KWAIT312MS    312    // Wait for 312-ms
 *
 * int32_t    status;
 *
 *    status = kern_suspendProcess(KWAIT312MS);
 * \endcode
 *
 * - Disconnect a process from the execution list
 * - Connect the process to the time list
 *
 * \param[in]	time			Suspend the process for a time (1-ms of resolution)
 * \param[in]	-				KWAIT_INFINITY, waiting forever
 * \param[in]	-				KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_FRISR	Execution from ISR
 *
 */
int32_t	kern_suspendProcess(uint32_t time) {
	uint32_t	core, wkTime;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (IS_EXCEPTION) { PRIVILEGE_RESTORE; return (KERR_KERN_FRISR); }
	if (time == 0u)	  { PRIVILEGE_RESTORE; return (KERR_KERN_NOERR); }

	INTERRUPTION_OFF;
	if (time != KWAIT_REMAINING_TIMEOUT) {
		wkTime = (time == KWAIT_INFINITY) ? (KWAIT_INFINITY) : (time / KKERN_TIC_TIME);
		vKern_runProc[core]->oInternal.oTimeout = wkTime;
	}
	else {
		if (vKern_runProc[core]->oInternal.oTimeout == 0u) {
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	GOTO_KERN_I(KKERN_MSG_WAIT_TIME);
	vKern_runProc[core]->oInternal.oStatus = KERR_KERN_NOERR;
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Set a new timeout
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KWAIT312MS    312    // Wait for 312-ms
 *
 * int32_t    status;
 *
 *    status = kern_setNewTimeout(nullptr, KWAIT312MS);
 * \endcode
 *
 * - Just change the internal timeout counter
 * - Do not de-schedule the process
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	timeout			Set a new timeout (1-ms of resolution)
 * \param[in]	-				Set with KWAIT_INFINITY, waiting forever
 * \param[in]	-				Set with KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRO	The process does not exist
 *
 */
int32_t	kern_setNewTimeout(proc_t *handle, uint32_t timeout) {
	uint32_t	core, wkTimeout;
	proc_t		*wkHandle = handle;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;

	wkHandle = (wkHandle == nullptr) ? (vKern_runProc[core]) : (wkHandle);

	if ((wkHandle->oInternal.oState & (1u<<BPROC_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRO); }

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

	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Restore a waiting process by forcing a timeout
 *
 * Resume a process waiting on an event (elapsed time (suspend), semaphore,
 * signal, ...) before its time with a KERR_KERN_TIMEO status.
 *
 * \note: This will distort the timing of a process relying upon an adequate
 * time-out interval.
 *
 * Call example in C:
 *
 * \code{.c}
 * proc_t     *process;
 * int32_t    status;
 *
 *    status = kern_resumeProcessWithTimeout(process);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRO	The process does not exist
 * \return		KERR_KERN_TIMEO	Timeout
 *
 */
int32_t	kern_resumeProcessWithTimeout(proc_t *handle) {
	uint32_t	core

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)										  { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRO); }
	if ((handle->oInternal.oState & (1u<<BPROC_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRO); }

	if ((handle->oInternal.oState & KSTATE_EOT_MASK) != 0u) {

		lists_disconnectConnect(handle->oObject.oList, &vKern_listExec[core], handle);
		handle->oInternal.oState &= (uint16_t)~KSTATE_EOT_MASK;
		handle->oInternal.oStatus = KERR_KERN_TIMEO;

		DEBUG_KERN_TRACE("exit: OK");
		if ((handle->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority) || (vKern_runProc[core] == &vKern_proc[core][0])) {
			PREEMPTION;
		}
		INTERRUPTION_RESTORE;
		PRIVILEGE_RESTORE;
		return (KERR_KERN_NOERR);
	}

	DEBUG_KERN_TRACE("exit: KO 3");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_TIMEO);
}

/*
 * \brief Read the remaining process timeout
 *
 * Call example in C:
 *
 * \code{.c}
 *
 * int32_t     status;
 * uint32_t    timeout;
 *
 *    status = kern_readRemainingProcessTimeout(&timeout);
 * \endcode
 *
 * \param[in]	*timeout		Ptr on the timeout
 * \return		KERR_KERN_NOERR	OK
 *
 */
int32_t	kern_readRemainingProcessTimeout(uint32_t *timeout) {
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*timeout = (IS_EXCEPTION) ? (0u) : (vKern_runProc[core]->oInternal.oTimeout);
	DEBUG_KERN_TRACE("exit: OK");
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Force the context switching
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = kern_switchFast();
 * \endcode
 *
 * - Force a context switch
 *
 * \param[in]	-
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_FRISR	Execution from ISR
 *
 */
int32_t	kern_switchFast(void) {
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (IS_EXCEPTION) { PRIVILEGE_RESTORE; return (KERR_KERN_FRISR); }

	INTERRUPTION_OFF;

	GOTO_KERN_I(KKERN_MSG_JUMP_KERN);
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Read the tickCount (1-us) from the start of the uKernel
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint64_t    tickCount;
 *
 *    status = kern_readTickCount(&tickCount);
 * \endcode
 *
 * - Return the 1-us tickCount value from the start of the uKernel
 *
 * \param[out]	*tickCount		Ptr on the tickCount
 * \return		KERR_KERN_NOERR	OK
 *
 */
int32_t	kern_readTickCount(uint64_t *tickCount) {
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;

	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	stub_kern_readTickCount(tickCount);
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Waiting for short times (at least ... a certain time)
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KWAITMIN    120    // Wait at least 120-µs
 *
 * int32_t    status;
 *
 *    status = kern_waitAtLeast(KWAITMIN);
 * \endcode
 *
 * - Return when the time is reached. Max. 65536-us
 *   This call ensure the minimum time but not the maximum
 *
 * \param[in]	time			Suspend the process for a time (1-us of resolution)
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_FRISR	Execution from ISR
 *
 */
int32_t	kern_waitAtLeast(uint16_t time) {
	uint64_t	timeStmp[2];
	uint32_t	core;
	bool		terminate = false;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (IS_EXCEPTION) { PRIVILEGE_RESTORE; return (KERR_KERN_FRISR); }

	stub_kern_readTickCount(&timeStmp[0]);

	do {
		stub_kern_readTickCount(&timeStmp[1]);
		if ((timeStmp[1] - timeStmp[0]) >= (uint64_t)time) {
			terminate = true;
		}
		else {
			kern_switchFast();
		}
	} while (terminate == false);

	DEBUG_KERN_TRACE("exit: OK");
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Check if a waiting process has a timeout set
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * bool       nonInfTOActive;
 *
 *    status = kern_hasPendingTimeoutProcesses(&nonInfTOActive);
 * \endcode
 *
 * - This functions scans the currently waiting processes and check
 *   if all timeouts are infinite or not
 *
 * \param[in]	-
 * \param[out]	*nonInfTOActive	Non infinite active timeout
 * \param[out]	-				true, If a non-infinite timeout is active
 * \param[out]	-				false, All waiting processes have an KWAIT_INFINITY timeout
 * \return		KERR_KERN_NOERR	OK
 *
 */
int32_t	kern_hasPendingTimeoutProcesses(bool *nonInfTOActive) {
	uint16_t	i;
	uint32_t	core;
	proc_t		*process;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	for (i = 0u; i < KKERN_NB_PROCESSES; i++) {
		process = &vKern_proc[core][i];
		const uint16_t state = process->oInternal.oState;
		if (((state & (1u<<BPROC_INSTALLED)) != 0u) && ((state & KSTATE_EOT_MASK) != 0u)) {
			if ((process->oInternal.oTimeout > 0u) && (process->oInternal.oTimeout != KWAIT_INFINITY)) {
				*nonInfTOActive = true;
				DEBUG_KERN_TRACE("exit: OK");
				return (KERR_KERN_NOERR);
			}

		}
	}
	*nonInfTOActive = false;
	DEBUG_KERN_TRACE("exit: OK");
	return (KERR_KERN_NOERR);
}

/*
 * \brief Test of the time suspended condition
 *
 * \warning	call usable only by the uKernel.
 *
 * \param[in]	time	Elapsed time
 *
 * \note This function does not return a value (None).
 *
 */
void	temporal_testEOTime(uint32_t time) {
	bool		preemption = false;
	uint16_t	i;
	uint32_t	core;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	for (i = 0u; i < KKERN_NB_PROCESSES; i++) {
		if ((vKern_proc[core][i].oInternal.oState & KSTATE_EOT_MASK) != 0u) {
			if (vKern_proc[core][i].oInternal.oTimeout != KWAIT_INFINITY) {

				vKern_proc[core][i].oInternal.oTimeout = (vKern_proc[core][i].oInternal.oTimeout < time) ? (0u) : (vKern_proc[core][i].oInternal.oTimeout - time);

				if (vKern_proc[core][i].oInternal.oTimeout == 0u) {
					lists_disconnectConnect(vKern_proc[core][i].oObject.oList, &vKern_listExec[core], &vKern_proc[core][i]);
					vKern_proc[core][i].oInternal.oState &= (uint16_t)~KSTATE_EOT_MASK;
					vKern_proc[core][i].oInternal.oStatus = KERR_KERN_TIMEO;

// If the ready process has a higher priority, then preemption occurs

					preemption |= ((vKern_proc[core][i].oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority) || (vKern_runProc[core] == &vKern_proc[core][0])) ? (true) : (false);
				}
			}
		}

// Decrement the internal timeout of all the process installed and not suspended.
// The process that can be scheduled

		if (((vKern_proc[core][i].oInternal.oState & (1u<<BPROC_INSTALLED)) != 0u) && ((vKern_proc[core][i].oInternal.oState & KSTATE_EOT_MASK) == 0u)) {
			if (vKern_proc[core][i].oInternal.oTimeout != KWAIT_INFINITY) {
				vKern_proc[core][i].oInternal.oTimeout = (vKern_proc[core][i].oInternal.oTimeout < time) ? (0u) : (vKern_proc[core][i].oInternal.oTimeout - time);
			}
		}
	}
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
}

/*
 * \brief Get the next wake-up time (for the low power mode)
 *
 * \warning call usable only by the uKernel.
 *
 * \param[in]	-
 * \return		time	The next wake-up time
 *
 */
uint32_t	temporal_getNextLowPowerTime(void) {
	uint16_t	i;
	uint32_t	core, minTime;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	minTime = KWAIT_INFINITY;

	for (i = 0u; i < KKERN_NB_PROCESSES; i++) {
		if ((vKern_proc[core][i].oInternal.oState & KSTATE_EOT_MASK) != 0u) {
			if (vKern_proc[core][i].oInternal.oTimeout < minTime) {
				minTime = vKern_proc[core][i].oInternal.oTimeout;
				if (minTime == 0u) {
					break;
				}
			}
		}
	}
	PRIVILEGE_RESTORE;
	return (minTime);
}
