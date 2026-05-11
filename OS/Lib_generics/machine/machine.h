/*
; machine.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		machine manager.
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
 * \addtogroup Lib_generics
 */
/**@{*/

/*!
 * \defgroup machine Machine
 *
 * \brief Machine
 *
 * Machine management
 *
 * @{
 */

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

/*!
 * \brief Read the PC of a process
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * proc_t       *process;
 * uintptr_t    pc;
 *
 *    status = machine_readPC(process, &pc);
 * \endcode
 *
 * - This function returns the PC of a process
 *
 * \param[in]	*handle				Ptr on the handle
 * \param[out]	*pc					Ptr on the pc
 * \return		KERR_MACHINE_NOERR	OK
 *
 */
extern	int32_t	machine_readPC(const proc_t *handle, uintptr_t *pc);

/*!
 * \brief Read the function name
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t      status;
 *          uintptr_t    pc;
 * const    char_t       *functionName
 *
 *    status = machine_readFunctionName(pc, &functionName);
 * \endcode
 *
 * - This function returns the name of a function
 *
 * \param[in]	pc					The pc
 * \param[out]	**function			Ptr on the function name
 * \return		KERR_MACHINE_NOERR	OK
 *
 */
extern	int32_t	machine_readFunctionName(const uintptr_t pc, const char_t **function);

/*!
 * \brief Restart of the system
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = stub_machine_restart();
 * \endcode
 *
 * \return		KERR_SYSTEM_NOERR	OK
 *
 */
extern	int32_t	machine_restart(void);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
