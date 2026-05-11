/*
; debug.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Debug list management.
;
;			This module implements the stop list primitives.
;
; 			Software debug system calls
; 			---------------------------
;
;			void	debug_init(void);
;			int32_t	kern_stopProcess(proc_t *handle);
;			int32_t	kern_reactivateProcess(proc_t *handle);
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

#if (KKERN_WITH_DEBUG_S == true)
list_t		vKern_listStop[KNB_CORES];

/*
 * \brief Initialise the manager
 *
 * - This function initialises the "debug" manager
 *   Before using the manager functions, it is necessary to
 *   call this function
 *
 *
 * \note This function does not return a value (None).
 *
 */
void	debug_init(void) {
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;
	lists_initialise(&vKern_listStop[core]);
	DEBUG_KERN_TRACE("exit: OK");
}

/*
 * \brief Stop a process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * proc_t     *process;
 *
 *    status = kern_stopProcess(process);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRO	The process does not exist
 * \return		KERR_KERN_DBGER	The process is already in the debug list
 * \return		KERR_KERN_DBNOS	The process is attached to a sensitive list and cannot be stopped
 *
 */
int32_t	kern_stopProcess(proc_t *handle) {
	bool		preemption = false;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)                           			  { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRO); }
	if ((handle->oInternal.oState & (1u<<BPROC_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRO); }
	if ((handle->oInternal.oState & (1u<<BPROC_SUSP_DEBG)) != 0u) { DEBUG_KERN_TRACE("exit: KO 3"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_DBGER); }
	if ((handle->oInternal.oState & (1u<<BPROC_SUSP_SEMA)) != 0u) { DEBUG_KERN_TRACE("exit: KO 4"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_DBNOS); }

	handle->oInternal.oListDebg  = handle->oObject.oList;
	handle->oInternal.oStateDebg = handle->oInternal.oState;
	handle->oInternal.oState     = (1u<<BPROC_INSTALLED) | (1u<<BPROC_SUSP_DEBG);
	lists_disconnectConnect(handle->oObject.oList, &vKern_listStop[core], handle);

// The process is stopped by itself

	preemption = (handle == vKern_runProc[core]) ? (true) : (false);

	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}

/*
 * \brief Reactivate a process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * proc_t     *process;
 *
 *    status = kern_reactivateProcess(process);
 * \endcode
 *
 * \param[in]	*handle			Ptr on the handle
 * \return		KERR_KERN_NOERR	OK
 * \return		KERR_KERN_NOPRO	The process does not exist
 * \return		KERR_KERN_DBGER	The process is not in the debug list
 *
 */
int32_t	kern_reactivateProcess(proc_t *handle) {
	bool		preemption = false;
	uint32_t	core;

	DEBUG_KERN_TRACE("entry: ");
	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	vKern_runProc[core]->oStatistic.oNbKernCalls++;
	if (handle == nullptr)                           			  { DEBUG_KERN_TRACE("exit: KO 1"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRO); }
	if ((handle->oInternal.oState & (1u<<BPROC_INSTALLED)) == 0u) { DEBUG_KERN_TRACE("exit: KO 2"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_NOPRO); }
	if ((handle->oInternal.oState & (1u<<BPROC_SUSP_DEBG)) == 0u) { DEBUG_KERN_TRACE("exit: KO 3"); INTERRUPTION_RESTORE; PRIVILEGE_RESTORE; return (KERR_KERN_DBGER); }

	handle->oInternal.oState = handle->oInternal.oStateDebg;
	lists_disconnectConnect(handle->oObject.oList, handle->oInternal.oListDebg, handle);

// If the ready process has a higher priority, then preemption occurs

	handle->oInternal.oDynamicPriority = handle->oSpecification.oPriority;
	preemption = ((handle->oInternal.oListDebg == &vKern_listExec[core]) && (handle->oInternal.oDynamicPriority < vKern_runProc[core]->oInternal.oDynamicPriority)) ? (true) : (false);

	DEBUG_KERN_TRACE("exit: OK");
	INTERRUPTION_RESTORE;

	if (preemption == true) { PREEMPTION; }
	PRIVILEGE_RESTORE;
	return (KERR_KERN_NOERR);
}
#endif
