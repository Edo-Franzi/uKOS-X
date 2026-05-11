/*
; xLibrary.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - impure data for xlib management.
;
;			This module is responsible for creating and swapping the impure data
;			for the xlib newlib of the uKernel.
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
#include	"kern/private/private_xLibrary.h"

reent_t		vKern_impureData[KNB_CORES][KKERN_NB_PROCESSES];

/*
 * \brief Initialise the impure data of the process
 *
 * \warning call usable only by the uKernel.
 *
 * \param[in]	*handle		Ptr on the handle
 *
 * \note This function does not return a value (None).
 *
 */
void	xLibrary_initialise(proc_t *handle) {
	uint16_t	i;
	uint32_t	core;
	proc_t		*process = handle;

	core = GET_RUNNING_CORE;

	i = (uint16_t)(((uintptr_t)process - (uintptr_t)&vKern_proc[core][0]) / sizeof(proc_t));
	_REENT_INIT_PTR(&vKern_impureData[core][i]);
	process->oInternal.oLocal = &vKern_impureData[core][i];
}

/*
 * \brief update the impure pointer with the impure data of the process
 *
 * \warning call usable only by the uKernel.
 *
 *
 * \note This function does not return a value (None).
 *
 */
void	xLibrary_update(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	if (vKern_runProc[core]->oInternal.oLocal != nullptr) {
		_impure_ptr = (reent_t *)vKern_runProc[core]->oInternal.oLocal;
	}
}
