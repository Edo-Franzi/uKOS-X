/*
; private_mutexes.
; ================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Mutex management.
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
 * \addtogroup mutexes
 * @{
 */

/*!
 * \defgroup private_mutexes Private Mutexes
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

#define	KMUTX_ANONYMOUS_ID	"Mutx_anonymous"

struct	mutx {
	const	char_t		*oIdentifier;							// Mutex identifier
			uint16_t	oState;									// Mutex state
			#define		BMUTX_INSTALLED		0u					// Mutex installed

			int32_t		oCounter;								// Mutex counter
			int32_t		oMaxCounter;							// Mutex counter max value
			#define		KMUTX_MAX_CPT		INT32_MAX			//
			#define		KMUTX_MIN_CPT		INT32_MIN			//

			proc_t		*oOwner;								// Ptr on the process owner of the mutex
			list_t		oList;									// Mutex list
};

extern	mutx_t		vKern_mutx[KNB_CORES][KKERN_NB_MUTEXES];		// Mutex
extern	uint16_t	vKern_nbMutx[KNB_CORES];					// Nb of used mutex
extern	uint16_t	vKern_nbMaxMutx[KNB_CORES];					// Max number of used mutex

/**@}*/
/**@}*/
/**@}*/
