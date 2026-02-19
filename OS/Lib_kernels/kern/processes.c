/*
; processes.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Process management.
;
;			This module manages the processes.
;
;			Service system calls
;			--------------------
;
;			void	processes_init(void);
;			int32_t	kern_createProcess(const spec_t *specification, const void *argument, proc_t **handle);
;			int32_t	kern_killProcess(proc_t *handle);
;			int32_t	kern_setPriority(proc_t *handle, priority_t priority);
;			int32_t	kern_getPriority(proc_t *handle, priority_t *priority);
;			int32_t	kern_getProcessById(const char_t *identifier, proc_t **handle);
;			int32_t	kern_getProcessRun(proc_t **handle);
;			int32_t	kern_installCallBack(void (*code)(uint8_t state));
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
#include	"kern/private/private_processes.h"
#include	"kern/private/private_xLibrary.h"
#include	"kern/private/private_identifiers.h"
#include	"kern/private/private_lists.h"

		proc_t		vKern_proc[KNB_CORES][KKERN_NB_PROCESSES];
		proc_t		*vKern_runProc[KNB_CORES];
		proc_t		*vKern_backwardProc[KNB_CORES];
		proc_t		vKern_frstProc[KNB_CORES];
		list_t		vKern_listFree[KNB_CORES];
		list_t		vKern_listExec[KNB_CORES];
		uint16_t	vKern_nbProc[KNB_CORES];
		uint16_t	vKern_nbMaxProc[KNB_CORES];
		void		(*vKern_codeRoutine[KNB_CORES])(uint8_t state);
static	uintptr_t	*vKern_stackLocation[KNB_CORES];

// Module strings

STRG_LOC_CONST(aStrFirst[])		 = "Process_First";
STRG_LOC_CONST(aStrIden_idle[])  = "Deamon_idle";
STRG_LOC_CONST(aStrIden_stack[]) = "Deamon_stack";

// Prototypes

static	void	local_initialise(proc_t *handle);
static	void	local_setupDescriptor(proc_t *handle, proc_t *father, const spec_t *specification, uint16_t state);
static	void	local_fatherKilled(const proc_t *handle);
static	void	local_initStackFrame(proc_t *handle, const void *argument);

/*
 * \brief Initialise the manager
 *
 * - This function initialises the "processes" manager
 *   Before using the manager functions, it is necessary to
 *   call this function
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
void	processes_init(void) {
					uint16_t	i;
					uint32_t	core;
	static	const	spec_t		specification = {
									.oIdentifier    = aStrFirst,
									.oText		    = nullptr,
									.oCode		    = nullptr,
									.oStackStart    = nullptr,
									.oStack         = nullptr,
									.oStackSize	    = 0u,
									.oStackMode	    = 0u,
									.oSerialManager = KDEF0,
									.oPriority	    = KKERN_PRIORITY_HIGH_01,
									.oKind		    = KPROC_NORMAL,
									.oMode	 	    = KPROC_PRIVILEGED
								};

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

// Initialise & connect the descriptors to the lists

	local_initialise(&vKern_frstProc[core]);
	for (i = 0u; i < KKERN_NB_PROCESSES; i++) {
		local_initialise(&vKern_proc[core][i]);
	}
	local_setupDescriptor(&vKern_frstProc[core], nullptr, &specification, (1u<<BPROC_INSTALLED) | (1u<<BPROC_FIRST));

// Initialise the lists and connect all the descriptors to the free list

	lists_initialise(&vKern_listFree[core]);
	lists_initialise(&vKern_listExec[core]);
	for (i = 0u; i < KKERN_NB_PROCESSES; i++) {
		lists_connect(&vKern_listFree[core], &vKern_proc[core][i]);
	}

// Some initialisation

	vKern_runProc[core]		 = &vKern_frstProc[core];
	vKern_backwardProc[core] = &vKern_frstProc[core];
	vKern_codeRoutine[core]	 = nullptr;
	vKern_nbProc[core]		 = 0u;
	vKern_nbMaxProc[core]	 = 0u;
	DEBUG_KERN_TRACE("exit: OK");
}

/*
 * \brief Create and install a process
 * \brief Create and install a process
 *
 * Call example in C:
 *
 * \code{.c}
 * // Example for 32-bit machines
 *
 * #define    KSIZE         1024          // Size of the stack in bytes
 * #define    KSZSTACK32    (KSIZE>>2)    // Size of the stack in number of 32-bit words
 *
 * int32_t    status;
 * static     uintptr_t    vStack_0[KSZSTACK32];
 * static     proc_t       *vProcess_0, *vProcess_1;
 *
 * const      spec_t       vSpecs_0 = {
 *                             .oIdentifier    = "User Process 0”,
 *                             .oText          = ”Process to do something (static mode)”,
 *                             .oCode          = (const void (*)(const void *argument))process_0,
 *                             .oStackStart    = &vStack_0[0],
 *                             .oStack         = &vStack_0[((KSZSTACK32 - KSTACK_ALIGNMENT) & KSTACK_ALIGNMENT_MASK)],
 *                             .oStackSize     = ((KSZSTACK32 - KSTACK_ALIGNMENT) & KSTACK_ALIGNMENT_MASK),
 *                             .oStackMode     = KPROC_STACK_STATIC,
 *                             .oPriority      = 5,
 *                             .oSerialManager = KDEF0,
 *                             .oKind          = KPROC_NORMAL,
 *                             .oMode          = KPROC_USER,
 *                             .oScheduleHook  = nullptr
 *                         };
 *
 *            uintptr_t    *vStack_1 = (uintptr_t *)memo_malloc(KMEMO_ALIGN_16, (KSZSTACK32 * sizeof(uintptr_t)), "stack");
 * const      spec_t       vSpecs_1 = {
 *                             .oIdentifier    = "User Process 1”,
 *                             .oText          = ”Process to do something (dynamic mode)”,
 *                             .oCode          = (const void (*)(const void *argument))process_1,
 *                             .oStackStart    = &vStack_1[0],
 *                             .oStack         = &vStack_1[((KSZSTACK32 - KSTACK_ALIGNMENT) & KSTACK_ALIGNMENT_MASK)],
 *                             .oStackSize     = ((KSZSTACK32 - KSTACK_ALIGNMENT) & KSTACK_ALIGNMENT_MASK),
 *                             .oStackMode     = KPROC_STACK_DYNAMIC,
 *                             .oPriority      = 5,
 *                             .oSerialManager = KDEF0,
 *                             .oKind          = KPROC_NORMAL,
 *                             .oMode          = KPROC_USER,
 *                             .oScheduleHook  = nullptr
 *                         };
 *
 * status = kern_createProcess(&vSpecs_0, nullptr, &vProcess_0);
 * status = kern_createProcess(&vSpecs_1, nullptr, &vProcess_1);
 *
 * To simplify the way to write this initialisation, a couple of macros are available;
 * so, the previous example can be written in this way:
 *
 * #define    KSIZE         1024          // Size of the stack in bytes
 * #define    KSZSTACK32    (KSIZE>>2)    // Size of the stack in number of 32-bit words
 *
 * int32_t    status;
 * static     char_t      aStrProcess_0[] = "Process to do something 0r\n";
 * static     char_t      aStrProcess_1[] = "Process to do something 1\r\n";
 * static     proc_t      *vProcess_0, *vProcess_1;
 *
 * PROCESS(0, vSpecs_0, aStrProcess_0, KSZSTACK32, process_0, "User Process 0", KDEF0, 5, 0)
 * PROCESS(1, vSpecs_1, aStrProcess_1, KSZSTACK32, process_1, "User Process 1", KCDC0, 5, 0)
 *
 * status = kern_createProcess(&vSpecs_0, nullptr, &vProcess_0);
 * status = kern_createProcess(&vSpecs_1, nullptr, &vProcess_1);
 * \endcode
 *
 * - Disconnect a process from the empty list
 * - Initialise the stack frame
 * - Connect the process to the execution list
 *
 * \par Fields of \c specification (struct ::spec_t):
 * - \c oIdentifier     : Ptr on the process identifier (nullptr = anonymous)
 * - \c oText           : Ptr on the process text (nullptr = anonymous)
 * - \c oCode           : Ptr on the process code
 * - \c oStackMode      : Stack mode
 * - \c oStackStart     : Begin of the process stack
 * - \c oStack          : Process stack (aligned on 8 bytes)
 * - \c oStackSize      : Size (number of uint32_t) of the process stack
 * - \c oSerialManager  : Default Serial Communication Manager
 * - \c oPriority       : Process priority
 * - \c oKind           : Process kind
 * - \c oMode           : Process running mode
 *
 * \param[in]	*specification				Ptr on the process specification
 * \param[in]	*argument					Ptr on the process argument
 * \param[out]	**handle					Ptr on the handle
 * \return		KERR_KERN_NOERR				OK
 * \return		KERR_KERN_LIFUL				No more process
 * \return		KERR_KERN_IDPRO				The process identifier is already used
 * \return		KERR_KERN_NOSTK				No memory for the stack
 * \return		KERR_KERN_FRISR				Execution from ISR
 * \return		KERR_KERN_PRIVI				Privilege violation
 *
 */
int32_t	kern_createProcess(const spec_t *specification, const void *argument, proc_t **handle) {
	uint16_t	i;
	uint32_t	core;
	bool		preemption = false;
	proc_t		*process, *father;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*handle = nullptr;

	if (IS_EXCEPTION)																															   { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_FRISR); }
	if (specification->oStackStart == nullptr)																										   { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOSTK); }
	if (vKern_listFree[core].oNbElements == 0u)																									   { DEBUG_KERN_TRACE("exit: KO 3"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_LIFUL); }
	if ((specification->oMode == KPROC_PRIVILEGED) &&
	   ((vKern_runProc[core]->oSpecification.oMode == KPROC_USER) && ((vKern_runProc[core]->oInternal.oState & (1u<<BPROC_PRIV_ELEVATED)) == 0u))) { DEBUG_KERN_TRACE("exit: KO 4"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_PRIVI); }

// Check if the identifier is already used (nullptr = anonymous)
// If the identifier is already used, then, return an error but
// with the handle of the previously created object

	if (specification->oIdentifier != nullptr) {
		for (i = 0u; i < KKERN_NB_PROCESSES; i++) {
			if ((vKern_proc[core][i].oInternal.oState & (1u<<BPROC_INSTALLED)) != 0u) {
				if (identifiers_cmpStrings(vKern_proc[core][i].oSpecification.oIdentifier, specification->oIdentifier) == true) {
					*handle = &vKern_proc[core][i];
					DEBUG_KERN_TRACE("exit: KO 5");
					INTERRUPTION_RESTORE;
					PRIVILEGE_RESTORE;
					return (KERR_KERN_IDPRO);
				}

			}
		}
	}

// Prepare the process

	process = vKern_listFree[core].oFirst;
	father	= vKern_runProc[core];

	lists_disconnectConnect(&vKern_listFree[core], &vKern_listExec[core], process);
	local_setupDescriptor(process, father, specification, (1u<<BPROC_INSTALLED));

// Prepare the stack frame

	local_initStackFrame(process, argument);
	*handle = process;

// Initialise the impure data of the process

	xLibrary_initialise(process);

// If the ready process has a higher priority, then preemption occurs

	preemption = (process->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority) ? (true) : (false);

	vKern_nbProc[core]    = (uint16_t)(vKern_nbProc[core] + 1u);
	vKern_nbMaxProc[core] = (vKern_nbProc[core] > vKern_nbMaxProc[core]) ? (vKern_nbProc[core]) : (vKern_nbMaxProc[core]);
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Kill the process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * proc_t     *process;
 *
 *    status = kern_killProcess();
 * \endcode
 *
 * - Disconnect a process from the list to which it is connected
 * - Connect the process to the empty list
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_REFRS	The first process cannot be removed
 * \return		KERR_KERN_RESDE	The system daemons cannot be removed
 * \return		KERR_KERN_NOPRO	The process does not exist
 * \return		KERR_KERN_FRISR	Execution from ISR
 * \return		KERR_KERN_PRIVI	Privilege violation
 *
 */
int32_t	kern_killProcess(proc_t *handle) {
	int32_t		status = KERR_KERN_NOERR;
	uint32_t	core;
	enum		{ KNOTPRESENT, KSUICIDE, KNORMAL } action;
	proc_t		*wkHandle = handle;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;

// If the handle == nullptr, then, commit a suicide

	wkHandle = (wkHandle == nullptr) ? (vKern_runProc[core]) : (wkHandle);

	if (IS_EXCEPTION)																															   { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_FRISR); }
	if (identifiers_cmpStrings(wkHandle->oSpecification.oIdentifier, aStrFirst) == true)														   { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_REFRS); }
	if (identifiers_cmpStrings(wkHandle->oSpecification.oIdentifier, aStrIden_idle) == true)													   { DEBUG_KERN_TRACE("exit: KO 3"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_RESDE); }
	if ((wkHandle->oSpecification.oMode == KPROC_PRIVILEGED) &&
	   ((vKern_runProc[core]->oSpecification.oMode == KPROC_USER) && ((vKern_runProc[core]->oInternal.oState & (1u<<BPROC_PRIV_ELEVATED)) == 0u))) { DEBUG_KERN_TRACE("exit: KO 4"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_PRIVI); }

	#if (defined(CONFIG_DAEM_KILL_S))

	#else
	if (identifiers_cmpStrings(wkHandle->oSpecification.oIdentifier, aStrIden_stack) == true)													   { DEBUG_KERN_TRACE("exit: KO 5"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_RESDE); }
	#endif

// Determine the next action

	if ((wkHandle->oInternal.oState & (1u<<BPROC_INSTALLED)) == 0u) { action = KNOTPRESENT;   }
	else if (wkHandle == vKern_runProc[core])					    { action = KSUICIDE;      }
	else															{ action = KNORMAL;		  }

	if (vKern_nbProc[core] != 0u) { vKern_nbProc[core] = (uint16_t)(vKern_nbProc[core] - 1u); }
	switch (action) {

// The process is not present: it is free for the user

		case KNOTPRESENT: {
			status = KERR_KERN_NOPRO;
			break;
		}

// The process wants to commit a suicide.
// Here the sequence of the operation is highly sensitive (DO NOT CHANGE THE SEQUENCE)
//
// 1. IOFF (only traps can be executed)
// 2. Release the process memory stack (using memo_delayedFree)
// 3. Disconnect the process descriptor from the execution list and connect it to the free one
// 4. Initialise the descriptor
// 5. Go to the uKernel

		case KSUICIDE: {
			local_fatherKilled(wkHandle);
			vKern_stackLocation[core] = (wkHandle->oSpecification.oStackMode == KPROC_STACK_DYNAMIC) ? (wkHandle->oSpecification.oStackStart) : (nullptr);
			memo_delayedFree(vKern_stackLocation[core]);
			lists_disconnectConnect(wkHandle->oObject.oList, &vKern_listFree[core], wkHandle);
			local_initialise(wkHandle);

// Go to the uKernel

			GOTO_KERN_I(KKERN_MSG_JUMP_KERN);

// We should newer reach this point; the process committed a suicide

			LOG(KFATAL_KERNEL, "desc: suicide: we sould never reach this point");
			exit(EXIT_OS_PANIC);
		}

// Remove a normal process

		case KNORMAL: {
			local_fatherKilled(wkHandle);
			vKern_stackLocation[core] = (wkHandle->oSpecification.oStackMode == KPROC_STACK_DYNAMIC) ? (wkHandle->oSpecification.oStackStart) : (nullptr);
			memo_free(vKern_stackLocation[core]);
			lists_disconnectConnect(wkHandle->oObject.oList, &vKern_listFree[core], wkHandle);
			local_initialise(wkHandle);
			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}
	DEBUG_KERN_TRACE("exit: ->");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Set a new static priority for a process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * proc_t     *process;
 *
 *    status = kern_setPriority(process, 23);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[in]	priority		Process priority
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRO	The process does not exist
 *
 */
int32_t	kern_setPriority(proc_t *handle, priority_t priority) {
	priority_t	wkPriority = priority;
	bool		preemption = false;
	uint32_t	core;
	proc_t		*wkHandle = handle;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;

// If the handle == nullptr, then, consider the current process

	wkHandle = (wkHandle == nullptr) ? (vKern_runProc[core]) : (wkHandle);

	if ((wkHandle->oInternal.oState & (1u<<BPROC_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRO); }

	wkPriority = (wkPriority == KKERN_PRIORITY_HIGH_Reserved) ? (KKERN_PRIORITY_HIGH_01) : (wkPriority);
	wkPriority = (wkPriority >= KKERN_NB_PRIORITIES)		  ? (KKERN_PRIORITY_LOW_14)	 : (wkPriority);

// If the new process priority is higher than the current one, then preemption

	preemption = (wkPriority < vKern_runProc[core]->oInternal.oDynamicPriority) ? (true) : (false);
	wkHandle->oSpecification.oPriority = wkPriority;
	wkHandle->oInternal.oDynamicPriority  = wkPriority;
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Get the static priority of a process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * uint8_t    priority
 * proc_t     *process;
 *
 *    status = kern_getPriority(process, &priority);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \param[out]	*priority		Ptr on the process priority
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRO	The process does not exist
 *
 */
int32_t	kern_getPriority(proc_t *handle, priority_t *priority) {
	uint32_t	core;
	proc_t		*wkHandle = handle;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;

// If the handle == nullptr, then, consider the current process

	wkHandle = (wkHandle == nullptr) ? (vKern_runProc[core]) : (wkHandle);

	if ((wkHandle->oInternal.oState & (1u<<BPROC_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRO); }
	*priority = wkHandle->oSpecification.oPriority;
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Get the handle of a process by its identifier
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * const      char_t    identifier[] = ”Process 0 - read a sensors”;
 *            proc_t    *process;
 *
 *    status = kern_getProcessById(identifier, &process);
 * \endcode
 *
 * - This function returns the handle of the process
 *
 * \param[in]	*identifier		Ptr on the process identifier
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRO	The process does not exist
 *
 */
int32_t	kern_getProcessById(const char_t *identifier, proc_t **handle) {
	uint16_t	i;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*handle = nullptr;

	for (i = 0u; i < KKERN_NB_PROCESSES; i++) {
		if (identifiers_cmpStrings(vKern_proc[core][i].oSpecification.oIdentifier, identifier) == true) {
			*handle = &vKern_proc[core][i];
			DEBUG_KERN_TRACE("exit: OK");
			INTERRUPTION_RESTORE;
			PRIVILEGE_RESTORE;
			return (KERR_KERN_NOERR);
		}

	}
	DEBUG_KERN_TRACE("exit: KO 1");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOPRO);
}

/*
 * \brief Get the handle of the running process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * proc_t     *process;
 *
 *    status = kern_getProcessRun(&process);
 * \endcode
 *
 * - This function returns the handle of the current process
 *
 * \param[out]	**handle		Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 *
 */
int32_t	kern_getProcessRun(proc_t **handle) {
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	*handle = vKern_runProc[core];
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Install the idle calls back routine
 *
 * \warning	This callback has to feed simple and non blocking code!!!
 * \warning	It is forbidden to use functions that unschedule the idle process.
 * \warning	e.g. kern_suspendProcess, etc.
 *
 * Call example in C:
 *
 * \code{.c}
 *            int32_t    status;
 * static     void       local_myRoutine(uint8_t state);
 *
 *    status = kern_installCallBack(local_myRoutine);
 *
 *    // My callback routine
 *
 *    static    void    local_myRoutine(uint8_t state) {
 *
 *        if (state == KKERN_IDLE_IN) led_off(KLED_IDLE);
 *        else                        led_on(KLED_IDLE);
 *    }
 * \endcode
 *
 * - I.e, this function implements a mechanism for visually display
 *   the load of the cpu by a LED intensity (the more the light is on,
 *   the more the load is heavy)
 *
 * \param[in]	*code			Ptr on the routine code
 * \return		KERR_KERN_NOERR	OK
 *
 */
int32_t	kern_installCallBack(void (*code)(uint8_t state)) {
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	vKern_codeRoutine[core] = code;
	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

// Local routines
// ==============

/*
 * \brief local_initialise
 *
 */
static	void	local_initialise(proc_t *handle) {
	static	const	spec_t	specification = {
								.oIdentifier	= nullptr,
								.oText			= nullptr,
								.oCode			= nullptr,
								.oStackStart	= nullptr,
								.oStack			= nullptr,
								.oStackSize		= 0u,
								.oStackMode		= 0u,
								.oSerialManager	= KDEF0,
								.oPriority		= KKERN_PRIORITY_HIGH_01,
								.oKind			= 0u,
								.oMode			= 0u,
								.oScheduleHook	= nullptr
							};

	local_setupDescriptor(handle, nullptr, &specification, 0u);
	handle->oObject.oList	 = nullptr;
	handle->oObject.oBack    = nullptr;
	handle->oObject.oForward = nullptr;
}

/*
 * \brief local_setupDescriptor
 *
 */
static	void	local_setupDescriptor(proc_t *handle, proc_t *father, const spec_t *specification, uint16_t state) {
	priority_t	priority;

	priority = (specification->oPriority == KKERN_PRIORITY_HIGH_Reserved) ? (KKERN_PRIORITY_HIGH_01)  : (specification->oPriority);
	priority = (priority >= KKERN_NB_PRIORITIES)						  ? (KKERN_PRIORITY_LOW_IDLE) : (priority);

// The process specifications

	handle->oSpecification.oIdentifier	  = ((specification->oIdentifier == nullptr) && (state == (1u<<BPROC_INSTALLED))) ? (KPROC_ANONYMOUS_ID) : (specification->oIdentifier);
	handle->oSpecification.oText		  = ((specification->oText       == nullptr) && (state == (1u<<BPROC_INSTALLED))) ? (KPROC_ANONYMOUS_TX) : (specification->oText);
	handle->oSpecification.oCode		  = specification->oCode;
	handle->oSpecification.oStackStart	  = specification->oStackStart;
	handle->oSpecification.oStack		  = specification->oStack;
	handle->oSpecification.oStackSize	  = specification->oStackSize;
	handle->oSpecification.oStackMode	  = specification->oStackMode;
	handle->oSpecification.oSerialManager = specification->oSerialManager;
	handle->oSpecification.oKind		  = specification->oKind;
	handle->oSpecification.oMode		  = specification->oMode;
	handle->oSpecification.oPriority	  = priority;
	handle->oSpecification.oScheduleHook  = nullptr;

// The process work

	handle->oInternal.oListDebg			  = nullptr;
	handle->oInternal.oStateDebg		  = 0u;
	handle->oInternal.oState			  = state;
	handle->oInternal.oProcFather		  = father;
	handle->oInternal.oNestedPrivilege	  = 0u;
	handle->oInternal.oStatus			  = 0u;
	handle->oInternal.oTimeout			  = 0u;
	handle->oInternal.oLocal			  = nullptr;
	handle->oInternal.oDynamicPriority	  = priority;
	handle->oInternal.oSkip				  = 0u;

// The process statistic

	handle->oStatistic.oNbExecutions	  = 0u;
	handle->oStatistic.oNbKernCalls		  = 0u;

	#if (KKERN_WITH_STATISTICS_S == true)

	#if (KDAEMONS_WITH_STACK_INT_S == true)
	handle->oStatistic.oAvStack			  = UINT32_MAX;
	#endif

	handle->oStatistic.oTimePMin		  = UINT16_MAX;
	handle->oStatistic.oTimePMax		  = 0u;
	handle->oStatistic.oTimePAvg		  = 0u;
	handle->oStatistic.oTimePCum		  = 0u;
	handle->oStatistic.oTimeKMin		  = UINT16_MAX;
	handle->oStatistic.oTimeKMax		  = 0u;
	handle->oStatistic.oTimeKAvg		  = 0u;
	handle->oStatistic.oTimeKCum		  = 0u;
	handle->oStatistic.oTimeEMin		  = UINT16_MAX;
	handle->oStatistic.oTimeEMax		  = 0u;
	handle->oStatistic.oTimeEAvg		  = 0u;
	handle->oStatistic.oTimeECum		  = 0u;
	#endif
}

/*
 * \brief local_fatherKilled
 *
 */
static	void	local_fatherKilled(const proc_t *handle) {
	uint32_t	i, core;

	core = GET_RUNNING_CORE;

	for (i = 0u; i < KKERN_NB_PROCESSES; i++) {
		if ((vKern_proc[core][i].oInternal.oState & (1u<<BPROC_INSTALLED)) != 0u) {
			if (vKern_proc[core][i].oInternal.oProcFather == handle) {
				vKern_proc[core][i].oInternal.oProcFather = nullptr;
			}
		}
	}
}

/*
 * \brief local_initStackFrame
 *
 */
static	void	local_initStackFrame(proc_t *handle, const void *argument) {
	uint32_t	i, core;
	uintptr_t	*stackFrame;

	core = GET_RUNNING_CORE;

// Fill the stack with a "magic" pattern (for statistic)

	stackFrame = handle->oSpecification.oStackStart;
	for (i = 0u; i < handle->oSpecification.oStackSize; i++) {
		*stackFrame = (uintptr_t)KMAGICSTACK;
		stackFrame++;
	}

// Prepare the stack frame

	stackFrame = handle->oSpecification.oStack;
	KERN_PREPARE_FRAME(stackFrame, handle->oSpecification.oCode, core, argument, KINT_IMASK_ALL);
	handle->oSpecification.oStack = stackFrame;
}
