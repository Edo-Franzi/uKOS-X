/*
; private_kern.
; =============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - misc management.
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
 * \addtogroup kern
 * @{
 */

/*!
 * \defgroup private_kern Private Kern
 *
 * \brief Private variables and structures
 *
 * Internal variables & structures, which are not supposed to be accessed by genuine user application
 *
 * @{
 */

// Have to be used with the macros
// GOTO_KERN_I and GOTO_KERN_M

// For the uKernel basic services

#define	KKERN_MSG_NO_PARAM			(0x0000u<<16u)					// Message without parameters
#define	KKERN_MSG_JUMP_KERN			(KKERN_MSG_NO_PARAM + 0x0000u)	// Message: jump to the uKernel
#define	KKERN_MSG_WAIT_TIME			(KKERN_MSG_NO_PARAM + 0x0001u)	// Message: waiting for a time
#define	KKERN_MSG_WAIT_SIGN			(KKERN_MSG_NO_PARAM + 0x0002u)	// Message: waiting for a signal

// For the uKernel semaphore synchronizations
// For the uKernel mutex synchronizations

#define	KKERN_MSG_WAIT_SEMA_SYN		(0x0001u<<16u)					// Message: waiting for a semaphore
#define	KKERN_MSG_WAIT_MUTX_SYN		(0x0002u<<16u)					// Message: waiting for a mutex

// For the uKernel mailbox synchronizations

#define	KKERN_MSG_WAIT_MBOX_E		(0x0003u<<16u)					// Message: waiting for an mbox empty
#define	KKERN_MSG_WAIT_MBOX_F		(0x0004u<<16u)					// Message: waiting for an mbox full

extern	uint32_t	vKern_nbIntImbrications[KNB_CORES];				// Nb of interruptions imbrications

/**@}*/
/**@}*/
/**@}*/
