/*
; machine.
; ========

; SPDX-License-Identifier: MIT

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

#include	"uKOS.h"
#include	"kern/private/private_processes.h"

#if (defined(CONFIG_MAN_MACHINE_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"machine      machine manager.                          (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "machine manager\n"
									"===============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Machine,						// Module name (the first letter has to be upper case)
	KID_FAM_GENERICS,				// Family (defined in the module.h)
	KNUM_MACHINE,					// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

// Prototypes

static	int32_t		local_init(void);
extern	int32_t		stub_machine_restart(void);
extern	int32_t		stub_machine_readPC(const uintptr_t *stackProcess, uintptr_t *pc);
extern	int32_t		stub_machine_readFunctionName(const uintptr_t pc, const char_t **function);

/*
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
 * \return		KERR_SYSTEM_NOERR	OK
 *
 */
int32_t	machine_readPC(const proc_t *handle, uintptr_t *pc) {
	int32_t	status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SYSTEM_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_machine_readPC(handle->oSpecification.oStack, pc);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
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
 * \return		KERR_SYSTEM_NOERR	OK
 *
 */
int32_t	machine_readFunctionName(const uintptr_t pc, const char_t **function) {
	int32_t	status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SYSTEM_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_machine_readFunctionName(pc, function);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
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
int32_t	machine_restart(void) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SYSTEM_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_machine_restart();
	PRIVILEGE_RESTORE;
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
static	int32_t	local_init(void) {
			int32_t		status = KERR_SYSTEM_NOERR;
			uint32_t	core;
	static	bool		vInit[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vInit[core] == false) {
		vInit[core] = true;
	}
	RETURN_INT_RESTORE(status);
}

#endif
