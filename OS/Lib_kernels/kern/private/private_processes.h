/*
; private_processes
; =================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Process management.
;
;			Private uKernel variables.
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

#pragma	once

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \addtogroup processes
 * @{
 */

/*!
 * \defgroup private_processes Private Processes
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#define	KPROC_ANONYMOUS_ID	"Proc_anonymous"
#define	KPROC_ANONYMOUS_TX	"Process anonymous.                        (c) EFr-2026"

extern			void		(*vKern_codeRoutine[KNB_CORES])(uint8_t state);		// Ptr on the Code for the call-back routine
extern			proc_t		*vKern_runProc[KNB_CORES];							// Ptr on the current process
extern			proc_t		*vKern_backwardProc[KNB_CORES];						// Ptr on the backward process
extern			proc_t		vKern_frstProc[KNB_CORES];							// First process,  identifier = 0
extern			proc_t		vKern_proc[KNB_CORES][KKERN_NB_PROCESSES];			// User processes, identifier = 1..2^31; identifier = IDLE if 1
extern			list_t		vKern_listFree[KNB_CORES];							// Empty list (processes reserve)
extern			list_t		vKern_listExec[KNB_CORES];							// Execution list for all the priorities
extern			uint16_t	vKern_nbProc[KNB_CORES];							// Nb of used processes
extern			uint16_t	vKern_nbMaxProc[KNB_CORES];							// Max number of used processes
extern	const	void		**vKern_ptrGlobal[KNB_CORES];						// Save the Ptr on a global variable

/**@}*/
/**@}*/
/**@}*/
