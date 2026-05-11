/*
; scheduler.
; ==========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Scheduler management.
;
;			This module is responsible for controlling the logic of the uKernel.
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
#include	"kern/private/private_scheduler.h"
#include	"kern/private/private_processes.h"
#include	"kern/private/private_semaphores.h"
#include	"kern/private/private_mutexes.h"
#include	"kern/private/private_mailboxes.h"
#include	"kern/private/private_temporal.h"
#include	"kern/private/private_signals.h"
#include	"kern/private/private_xLibrary.h"

uintptr_t	*vKern_stackProc[KNB_CORES];

// Prototypes

static	void	local_nextAction(uint8_t action, list_t *list, uint8_t bitNb);
static	proc_t	*local_getNextProcess(void);
static	void	local_callIdleOut(void);

/*
 * \brief Connect the current process to a list and change the context
 *
 * \param[in]	force	false process timeout
 *						true force to change the context
 * \param[in]	*list	Ptr on the list
 * \param[in]	bitNb	bit number (flag for suspending)
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
void	scheduler_changeContext(bool force, list_t *list, uint8_t bitNb) {
	uint32_t	core;
	void		(*codebackward)(proc_t *handle, bool scheduled);
	void		(*codeCurrent)(proc_t *handle, bool scheduled);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	vKern_backwardProc[core] = vKern_runProc[core];
	vKern_runProc[core]->oInternal.oState &= (uint16_t)~(1u<<BPROC_RUNNING);

// force == true,  Context switching due to a specific demand
// force == false, Context switching due to an event

	if (force == true) { local_nextAction(KSCHE_FORCE_SWITCH_NORM, list, bitNb);   }
	else			   { local_nextAction(KSCHE_TIMEOUT_SWITCH_NORM, list, bitNb); }

// Update the impure pointer with the impure data of the process
// Load the new stack

	xLibrary_update();
	vKern_stackProc[core] = vKern_runProc[core]->oSpecification.oStack;

	vKern_runProc[core]->oInternal.oState |= (1u<<BPROC_RUNNING);

// Give a new timeout for the process

	stub_kern_newProcessTimeout();
	INTERRUPTION_RESTORE;

// Indicate out of the idle

	local_callIdleOut();

// Call-back: exit previous process, set new process

	codebackward = vKern_backwardProc[core]->oSpecification.oScheduleHook;
	codeCurrent  = vKern_runProc[core]->oSpecification.oScheduleHook;

	if (vKern_backwardProc[core] != vKern_runProc[core]) {
		if (codebackward != nullptr) { (codebackward)(vKern_backwardProc[core], false); }
		if (codeCurrent  != nullptr) { (codeCurrent)(vKern_runProc[core],		true);  }
	}
}

/*
 * \brief local_nextAction
 *
 * The next action could be:
 * - KSCHE_FORCE_SWITCH_NORM: Context switching due to a specific demand
 * - KSCHE_TIMEOUT_SWITCH_NORM: Context switching due to an event
 *
 */
static	void	local_nextAction(uint8_t action, list_t *list, uint8_t bitNb) {
	uint32_t	core;
	proc_t		*process;

	core = GET_RUNNING_CORE;

	switch (action) {

// Context switching due to a specific demand
// - Save the stack of the current process
// - Schedule the most priority process

		case KSCHE_FORCE_SWITCH_NORM: {
			process = vKern_runProc[core];
			if ((process->oInternal.oState & (1u<<BPROC_INSTALLED)) != 0u) {
				process->oSpecification.oStack = vKern_stackProc[core];
			}
			vKern_runProc[core] = local_getNextProcess();
			break;
		}

// Context switching due to an event
// - Save the stack of the current process
// - Disconnect the current process from the execution list
// - Connect the current process to the "list" list
// - Schedule the most priority process

		case KSCHE_TIMEOUT_SWITCH_NORM: {
			process = vKern_runProc[core];
			process->oInternal.oState |= (uint16_t)(1u<<bitNb);
			process->oSpecification.oStack = vKern_stackProc[core];
			lists_disconnectConnect(process->oObject.oList, list, process);
			vKern_runProc[core] = local_getNextProcess();
			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}
}

/*
 * \brief Determine the next process to run f(priority)
 *
 *  Process     	Pri.	Pri.	Pri.	Pri.	Pri.	Pri
 *  P1 256 (Idle)   256		256		256		256		256		256
 *  P2 5       		4       3       2		1		5		4
 *  P5 4   			3       2       4		3		2		4
 *  P6 6         	2       6       5		4		3		2
 *  P8 3         	3       2       1		3		2		1
 *
 *  Run     		P6      P5      P8		P2		P5		P8 ..
 *
 * - Scan the "execution" list and search for the process having the highest dynamic priority (smallest value)
 * - If more processes have the same priority, select the process that was waiting for the longer time (Skip counter)
 *   - Increment the counter Skip for all the processes in competition
 *
 * - Decrement the dynamic priority of all the processes of the list
 * - For the selected process, set the dynamic priority with the static one
 *
 */
static	proc_t	*local_getNextProcess(void) {
	uint16_t	i, nbElements;
	uint32_t	core;
	enum		{ KBIGGER, KLOWER, KEQUAL } action;
	proc_t		*idle, *process, *priorityProcess;

	core = GET_RUNNING_CORE;
	nbElements		= vKern_listExec[core].oNbElements;
	idle	    	= vKern_listExec[core].oFirst;
	process			= idle->oObject.oForward;
	priorityProcess = idle->oObject.oForward;

	switch (nbElements) {

// In the execution list the idle is always in place
// Case not possible

		case 0u: {
			LOG(KFATAL_KERNEL, "sche: case not possible");
			exit(EXIT_OS_PANIC);
		}

// Only the idle in the execution list
// Return the idle

		case 1u: {
			return (idle);
		}

// Idle + 1 process in the excecution list
// Return the process connected to the idle

		case 2u: {
			process->oInternal.oSkip = 0;
			process->oInternal.oDynamicPriority = process->oSpecification.oPriority;
			return (process);
		}

// Idle + n process in the excecution list (n > 1)
// Skip the idle
// (nbElements - 1) because "process->oObject.oForward->oxyz"

		default: {
			for (i = 1u; i < (uint16_t)(nbElements - 1u); i++) {

// Determine the next action

				if (priorityProcess->oInternal.oDynamicPriority > process->oObject.oForward->oInternal.oDynamicPriority)     { action = KBIGGER; }
				else {
					if (priorityProcess->oInternal.oDynamicPriority < process->oObject.oForward->oInternal.oDynamicPriority) { action = KLOWER;  }
					else																									 { action = KEQUAL;  }
				}

				switch (action) {

// Case where the P(x) > P(i)

					case KBIGGER: {
						priorityProcess = process->oObject.oForward;
						break;
					}

// Case where the P(x) < P(i)

					case KLOWER: {
						break;
					}

// Case where the P(x) = P(i)

					case KEQUAL: {
						if (priorityProcess->oInternal.oSkip < process->oObject.oForward->oInternal.oSkip) {
							priorityProcess->oInternal.oSkip++;
							priorityProcess = process->oObject.oForward;
						}
						else {
							process->oObject.oForward->oInternal.oSkip++;
						}
						break;
					}
					default: {

// Make MISRA happy :-)

						break;
					}
				}
				process = process->oObject.oForward;
			}
			break;
		}
	}
	priorityProcess->oInternal.oSkip = 0u;
	priorityProcess->oInternal.oDynamicPriority = priorityProcess->oSpecification.oPriority;
	return (priorityProcess);
}

/*
 * \brief Update the dynamic priority of all active processes
 *
 * - Scan the "execution" list
 *   - Decrement the dynamic priority for the following cases
 *      - All the process in the list except the idle and the running one
 *      - Decrement only if the oDynamicPriority > 0
 *
 */
static	void	local_updateDynaPriority(void) {
	uint8_t		dynaPriority;
	uint16_t	i, nbElements;
	uint32_t	core;
	proc_t		*idle, *process;

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	nbElements = vKern_listExec[core].oNbElements;

// Do not modify the dynamic priority of the idle process.

	if (nbElements == 1u) {
		INTERRUPTION_RESTORE;
		return;
	}

	idle	= vKern_listExec[core].oFirst;
	process	= idle->oObject.oForward;

	for (i = 1u; i < nbElements; i++) {

// Do not modify the dynamic priority of the running process.
// Do not modify the dynamic priority if requested by the user.

		if (process != vKern_runProc[core]) {
			if (process->oInternal.oDynamicPriority > 0u) {
				dynaPriority = (uint8_t)process->oInternal.oDynamicPriority;
				dynaPriority--;
				process->oInternal.oDynamicPriority = (priority_t)dynaPriority;
			}
		}
		process = process->oObject.oForward;
	}
	INTERRUPTION_RESTORE;
}

/*
 * \brief callback idle out
 *
 * - Indicate "out of the idle"
 *
 */
static	void	local_callIdleOut(void) {
	uint32_t	core;
	void		(*code)(uint8_t state);

	core = GET_RUNNING_CORE;
	code = vKern_codeRoutine[core];

	if (vKern_backwardProc[core] == &vKern_proc[core][0]) {
		if (code != nullptr) {
			vKern_runProc[core]->oInternal.oState |= (1u<<BPROC_LIKE_ISR);
			code(KKERN_IDLE_OUT);
			vKern_runProc[core]->oInternal.oState &= (uint16_t)~(1u<<BPROC_LIKE_ISR);
		}
	}
}

// The callback routines
// =====================

/*
 * \brief scheduler_callBackFast
 *
 * !!! Normal uKernel logic for dynamic priority management would require to execute
 *     the command local_updateDynaPriority only in uKernel model call-backs ...
 *	   scheduler_callBackSlow
 *	   scheduler_callBackTrap
 *	   To avoid multiple process switches, the dynamic priority is incremented in the scheduler_callBackSlow callback
 *	   This is not optimal but it's the best compromise.
 *
 * - Update the dynamic priority
 * - Verify the timeout condition of the suspended processes
 *
 * \param[in]	time	Suspend the process for a time (1-ms of resolution)
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
void	scheduler_callBackFast(uint32_t time) {

	local_updateDynaPriority();
	temporal_testEOTime(time);
}

/*
 * \brief scheduler_callBackSlow
 *
 * - Change the context and prepare the next process
 * - INT acknowledge and new time for the next process
 *
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
void	scheduler_callBackSlow(void) {

	scheduler_changeContext(true, nullptr, 0u);
}

/*
 * \brief scheduler_callBackTrap
 *
 * - Analysis of the message
 *
 * - Basic services: KKERN_MSG_NO_PARAM
 *	 - KKERN_MSG_JUMP_KERN	force the process switching
 *	 - KKERN_MSG_WAIT_TIME	waiting for a time
 *	 - KKERN_MSG_WAIT_SIGN	waiting for a signal
 *
 * - Semaphore synchronizations: KKERN_MSG_WAIT_SEMA_SYN
 *	 - KKERN_MSG_WAIT_SEMA_SYN		waiting for a semaphore synchro
 *
 * - Semaphore synchronizations: KKERN_MSG_WAIT_MUTX_SYN
 *	 - KKERN_MSG_WAIT_MUTX_SYN		waiting for a mutex synchro
 *
 * \param[in]	message		Message from the process
 *
 * \note This function does not return a value (None).
 *
 * \warning call usable only by the uKernel.
 *
 */
void	scheduler_callBackTrap(uint32_t message) {
	uint32_t	core;

	core = GET_RUNNING_CORE;
	switch (message & 0xFFFF0000u) {

// Messages without parameters
// - Basic services

		case KKERN_MSG_NO_PARAM: {
			switch (message) {
				case KKERN_MSG_JUMP_KERN: {
					scheduler_changeContext(true, nullptr, 0u);
					break;
				}
				case KKERN_MSG_WAIT_TIME: {
					scheduler_changeContext(false, &vKern_listWait[core], BPROC_SUSP_TIME);
					break;
				}
				case KKERN_MSG_WAIT_SIGN: {
					scheduler_changeContext(false, &vKern_listSign[core], BPROC_SUSP_SIGN);
					break;
				}
				default: {
					LOG(KFATAL_KERNEL, "sche: message not possible");
					exit(EXIT_OS_PANIC);
				}
			}
			break;
		}

// Messages with parameters
// - Semaphore synchronizations
// - Mailbox (Empty & Full)

		case KKERN_MSG_WAIT_SEMA_SYN: {
			if ((message & 0x0000FFFFu) >= KKERN_NB_SEMAPHORES) { LOG(KFATAL_KERNEL, "sche: sema number does not exist"); exit(EXIT_OS_PANIC); }
			scheduler_changeContext(false, &vKern_sema[core][(message & 0x0000FFFFu)].oList, BPROC_SUSP_SEMA);
			break;
		}
		case KKERN_MSG_WAIT_MUTX_SYN: {
			if ((message & 0x0000FFFFu) >= KKERN_NB_MUTEXES) { LOG(KFATAL_KERNEL, "sche: mutx number does not exist"); exit(EXIT_OS_PANIC); }
			scheduler_changeContext(false, &vKern_mutx[core][(message & 0x0000FFFFu)].oList, BPROC_SUSP_MUTX);
			break;
		}
		case KKERN_MSG_WAIT_MBOX_E: {
			if ((message & 0x0000FFFFu) >= KKERN_NB_MAILBOXES) { LOG(KFATAL_KERNEL, "sche: mbox number does not exist"); exit(EXIT_OS_PANIC); }
			scheduler_changeContext(false, &vKern_mbox[core][(message & 0x0000FFFFu)].oListEmpty, BPROC_SUSP_MBOX_E);
			break;
		}
		case KKERN_MSG_WAIT_MBOX_F: {
			if ((message & 0x0000FFFFu) >= KKERN_NB_MAILBOXES) { LOG(KFATAL_KERNEL, "sche: mbox number does not exist"); exit(EXIT_OS_PANIC); }
			scheduler_changeContext(false, &vKern_mbox[core][(message & 0x0000FFFFu)].oListFull, BPROC_SUSP_MBOX_F);
			break;
		}
		default: {
			LOG(KFATAL_KERNEL, "sche: message not possible");
			exit(EXIT_OS_PANIC);
		}
	}
}
