/*
; privileges.
; ===========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kern - Privilege management.
;
;			This module implements the software primitives.
;
; 			Privilege system calls
; 			---------------------------
;
;			void	privileges_init(void);
;			int32_t	kern_setPrivilegeMode(uint8_t mode);
;			void	kern_privilegeElevate(void); !!! Not for user applications
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
 * \defgroup privileges Privileges
 *
 * \brief Privileges
 *
 * Privilege management
 *
 * @{
 */

#if (defined(__cplusplus))
extern	"C" {
#endif

#if (defined(UKOS_S))
extern	volatile	bool	vPriv_insideSVC[KNB_CORES];
extern	volatile	bool	vPriv_insideException[KNB_CORES];
#endif

extern	void	privileges_init(void);

/*!
 * \brief Set the privilege mode
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = kern_setPrivilegeMode(KPROC_PRIVILEGED);
 *    ...
 *    code executed in privileged mode
 *    ...
 *    status = kern_setPrivilegeMode(KPROC_USER);
 * \endcode
 *
 * - This function allows to change the execution mode (Privileged / user)
 *
 * \param[in]	mode			KPROC_USER, Reduction the process rights in the user mode
 *								KPROC_PRIVILEGED, Elevate the process rights in the privileged mode
 * \return		KERR_KERN_NOERR	OK
 *
 */
extern	int32_t	kern_setPrivilegeMode(uint8_t mode);

/*!
 * \brief Elevate the privilege
 *
 * Call example in C:
 *
 * \code{.c} *
 *    kern_privilegeElevate();
 *    ...
 * \endcode
 *
 * - This is not a user call.
 * - Coming from the TRAP dispatcher.
 * - Set the privileged mode
 *
 *
 * \note This function does not return a value (None).
 *
 */
[[gnu::naked]]
extern	void	kern_privilegeElevate(void);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
