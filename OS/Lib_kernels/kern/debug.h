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
;			This module implements the debug list primitives.
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

#pragma	once

#if (KKERN_WITH_DEBUG_S == true)

/*!
 * \addtogroup Lib_kernels
 */
/**@{*/

/*!
 * \defgroup debug Debug
 *
 * \brief Debug
 *
 * Debug management
 *
 * @{
 */

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

extern	void	debug_init(void);

/*!
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
extern	int32_t	kern_stopProcess(proc_t *handle);

/*!
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
extern	int32_t	kern_reactivateProcess(proc_t *handle);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/

#endif
