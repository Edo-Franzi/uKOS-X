/*
; stimer.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stim daemon; software timer management
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
#include	"kern/private/private_processes.h"
#include	"kern/private/private_softwareTimer.h"

#if (KKERN_NB_SOFTWARE_TIMERS > 0)

proc_t	*vStimer_handle[KNB_CORES];

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"stimer       stimer: software timer management.        (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "stim deamon\n"
									"===========\n\n"

									"Install the stimer deamon\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	void		local_process(const void *argument);

// This process has to run on the following cores:

#define	KEXECUTION_CORE		((1u<<BCORE_0) | (1u<<BCORE_1) | (1u<<BCORE_2) | (1u<<BCORE_3))

MODULE(
	Stimer,									// Module name (the first letter has to be upper case)
	KID_FAM_DAEMONS,						// Family (defined in the module.h)
	KNUM_STIMER,							// Module identifier (defined in the module.h)
	nullptr,								// Address of the initialisation code (early pre-init)
	prgm,									// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,								// Address of the clean code (clean the module)
	" 1.0",									// Revision string (major . minor)
	(1u<<BSHOW),							// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	KEXECUTION_CORE							// Execution cores
);

// Daemon specific
// ===============

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Deamon_stimer";
STRG_LOC_CONST(aStrText[]) = "Daemon stimer: software timer management. (c) EFr-2026";

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	uint32_t	core;

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;

	VAR_DECLARED_ALIGN(static uintptr_t vStack[KNB_CORES][KKERN_SZ_STACK_MM], KSTACK_ALIGNMENT);

	DAEMON_PRIVILEGED(
		core,								// Core
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (nullptr if anonymous)
		vStack,								// Stack location
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process,						// Code of the process
		aStrIden,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_15				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, nullptr, &vStimer_handle[core]) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "stimer: create proc"); exit(EXIT_OS_PANIC); }

	LOG(KINFO_SYSTEM, "stimer: daemon stim launched");

	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_execute
 *
 * - Execute a software timer entry
 *
 */
static	void	local_execute(uint16_t i) {
			void		(*code)(const void *argument);
			uint32_t	core;
	const	void		*argument;

	core = GET_RUNNING_CORE;
	vKern_stim[core][i].oCounter = vKern_stim[core][i].oTimerSpec.oTime;
	code = vKern_stim[core][i].oTimerSpec.oCode;

	vKern_curStim[core] = i;
	vKern_runProc[core]->oInternal.oState |= (1u<<BPROC_LIKE_ISR);

	argument = vKern_stim[core][i].oTimerSpec.oArgument;
	kern_setPrivilegeMode(KPROC_USER);
	code(argument);
	kern_setPrivilegeMode(KPROC_PRIVILEGED);

	vKern_runProc[core]->oInternal.oState &= (uint16_t)~(1u<<BPROC_LIKE_ISR);
	vKern_curStim[core] = (uint16_t)-1;

	(vKern_stim[core][i].oTimerSpec.oMode == KSTIM_SINGLE_SHOT) ? (vKern_stim[core][i].oState &= (uint16_t)~((1u<<BSTIM_RUNNING) | (1u<<BSTIM_CONFIGURED))) : (vKern_stim[core][i].oState &= (uint16_t)~(0x00));
	vKern_stim[core][i].oState |= (1u<<BSTIM_EXECUTED);
}

/*
 * \brief local_process
 *
 * - This daemon is scheduled cyclically for the management of
 *   the software timers
 *
 */
static void __attribute__ ((noreturn)) local_process(const void *argument) {
	uint16_t	i;
	uintptr_t	data;
	uint32_t	core, delay, nextTimeout, lastTimeout, errorTimeout, compTime;
	uint64_t	time[2], delta, suspendStart, suspendEnd;
	bool		gotMailBox = false;
	stim_t		*newSTimer;
	mbox_t		*mailBox;

	UNUSED(argument);

	DEBUG_KERN_TRACE("entry: software timer daemon");
	core = GET_RUNNING_CORE;
	kern_setPrivilegeMode(KPROC_PRIVILEGED);
	nextTimeout  = KWAIT_INFINITY;
	errorTimeout = 0u;

// Special case to support the creation of a software timer before
// starting the uKernel
// Check if the mailbox exist
// If yes, check if there is new software timers that
// need to be included

	if (kern_getMailboxById(KMBOX_SOFTWARE_TIMER, &mailBox) == KERR_KERN_NOERR) {
		while (kern_readQueue(mailBox, &data, 0) == KERR_KERN_NOERR) {
			newSTimer		  = (stim_t *)data;
			newSTimer->oState = (newSTimer->oTimerSpec.oMode == KSTIM_STOP)	? (0)                       : ((1u<<BSTIM_CONFIGURED) | (1u<<BSTIM_RUNNING));
			nextTimeout		  = (newSTimer->oInitCounter < nextTimeout)		? (newSTimer->oInitCounter) : (nextTimeout);
		}
	}

	while (true) {
		kern_readTickCount(&suspendStart);
		delay = (nextTimeout == KWAIT_INFINITY) ? (KWAIT_INFINITY) : (nextTimeout * KKERN_TIC_TIME);
		kern_suspendProcess(delay);
		kern_readTickCount(&suspendEnd);

		delta = ((suspendEnd - suspendStart) + (uint64_t)errorTimeout) * (uint64_t)KKERN_TIC_FREQUENCY;
		lastTimeout  = (uint32_t)(delta / (uint64_t)KKERN_TICKCOUNT_PER_SECOND);
		errorTimeout = (uint32_t)((suspendEnd - suspendStart) + errorTimeout) % ((KKERN_TICKCOUNT_PER_SECOND + (KKERN_TIC_FREQUENCY / 2u)) / KKERN_TIC_FREQUENCY);

		if (lastTimeout > 0) {
			nextTimeout = KWAIT_INFINITY;
			kern_readTickCount(&time[0]);
			for (i = 0u; i < KKERN_NB_SOFTWARE_TIMERS; i++) {
				if (((vKern_stim[core][i].oState & (1u<<BSTIM_CONFIGURED)) != 0u)) {

// Execute only if mode = Continue
// or, if mode = SingleShot but never executed

					if ((vKern_stim[core][i].oState & (1u<<BSTIM_RE_CONFIGURED)) == 0u) {
						if ((vKern_stim[core][i].oTimerSpec.oMode == KSTIM_CONTINUOUS) || ((vKern_stim[core][i].oTimerSpec.oMode == KSTIM_SINGLE_SHOT) && ((vKern_stim[core][i].oState & (1u<<BSTIM_EXECUTED)) == 0u))) {

// Verify the initial time
// Verify the time

							if (vKern_stim[core][i].oInitCounter <= lastTimeout) {
								if (vKern_stim[core][i].oInitCounter > 0u) {
									vKern_stim[core][i].oCounter = (vKern_stim[core][i].oCounter > (lastTimeout - vKern_stim[core][i].oInitCounter)) ? (vKern_stim[core][i].oCounter - (lastTimeout - vKern_stim[core][i].oInitCounter)) : 0u;
									vKern_stim[core][i].oInitCounter = 0u;
									if (vKern_stim[core][i].oCounter == 0u){
										local_execute(i);
										if (vKern_stim[core][i].oTimerSpec.oMode == KSTIM_CONTINUOUS) {
											nextTimeout = (nextTimeout < vKern_stim[core][i].oCounter) ? (nextTimeout) : (vKern_stim[core][i].oCounter);
										}
									}
									else {
										nextTimeout = (nextTimeout < vKern_stim[core][i].oCounter) ? (nextTimeout) : (vKern_stim[core][i].oCounter);
									}
								}
								else if (vKern_stim[core][i].oCounter <= lastTimeout) {
									local_execute(i);
									if (vKern_stim[core][i].oTimerSpec.oMode == KSTIM_CONTINUOUS) {
										nextTimeout = (nextTimeout < vKern_stim[core][i].oCounter) ? (nextTimeout) : (vKern_stim[core][i].oCounter);
									}
								}
								else {
									vKern_stim[core][i].oCounter = (vKern_stim[core][i].oCounter < lastTimeout) ? (0u)		    : (vKern_stim[core][i].oCounter - lastTimeout);
									nextTimeout = (nextTimeout < vKern_stim[core][i].oCounter)					? (nextTimeout) : (vKern_stim[core][i].oCounter);
								}
							}
							else {
								vKern_stim[core][i].oInitCounter = (vKern_stim[core][i].oInitCounter < lastTimeout) ? (0u)			: (vKern_stim[core][i].oInitCounter - lastTimeout);
								nextTimeout = (nextTimeout < vKern_stim[core][i].oInitCounter)						? (nextTimeout) : (vKern_stim[core][i].oInitCounter);
							}
						}
					}
				}
			}
			kern_readTickCount(&time[1]);

// Compensation time in ms
// This time has to be subtracted from the nexTimeout to avoid temporal shifts

			#if (defined(KKERN_TICKCOUNT_PER_SECOND) && defined(KKERN_TIC_FREQUENCY))
			compTime = (uint32_t)(KKERN_TIC_FREQUENCY * (time[1] - time[0])) / KKERN_TICKCOUNT_PER_SECOND;

			#else
			compTime = (uint32_t)((uint32_t)(time[1] - time[0])) / (1000u * KKERN_TIC_TIME);
			#endif

			if (nextTimeout != KWAIT_INFINITY) {
				nextTimeout = (nextTimeout > compTime) ? (nextTimeout - compTime) : (0u);
			}
		}

// Check if the mailbox exist
// If yes, check if there is a new software timer that
// need to be included

		if (gotMailBox == false) {
			if (kern_getMailboxById(KMBOX_SOFTWARE_TIMER, &mailBox) == KERR_KERN_NOERR) {
				gotMailBox = true;
			}
		}

		if (gotMailBox == true) {
			while (kern_readQueue(mailBox, &data, 0u) == KERR_KERN_NOERR) {
				newSTimer		  = (stim_t *)data;
				newSTimer->oState = (newSTimer->oTimerSpec.oMode == KSTIM_STOP) ? ((1u<<BSTIM_INSTALLED))	: ((1u<<BSTIM_INSTALLED) | (1u<<BSTIM_CONFIGURED) | (1u<<BSTIM_RUNNING));
				if (newSTimer->oInitCounter > 0u) {
					nextTimeout   = (newSTimer->oInitCounter < nextTimeout)		? (newSTimer->oInitCounter) : (nextTimeout);
				}
				else {
					nextTimeout   = (newSTimer->oCounter < nextTimeout)			? (newSTimer->oCounter)     : (nextTimeout);
				}
			}
		}
	}
}

#endif
