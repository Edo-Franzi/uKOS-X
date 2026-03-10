/*
; privileges.
; ===========

; SPDX-License-Identifier: MIT

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

#include	"uKOS.h"
#include	"kern/private/private_processes.h"

volatile	bool	vPriv_insideSVC[KNB_CORES] = MCSET(false);
volatile	bool	vPriv_insideException[KNB_CORES] = MCSET(false);

// Prototypes

#if (defined(PRIVILEGED_USER_S))
static	void	local_elevate(uintptr_t callAddress);
#endif

/*
 * \brief Initialise the manager
 *
 * - This function initialises the "privileges" manager
 *   Before using the manager functions, it is necessary to
 *   call this function
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
void	privileges_init(void) {

	DEBUG_KERN_TRACE("entry: ");

	DEBUG_KERN_TRACE("exit: OK");
}

/*
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
 * \param[in]	-				KPROC_PRIVILEGED, Elevate the process rights in the privileged mode
 * \return		KERR_KERN_NOERR	OK
 *
 */
int32_t	kern_setPrivilegeMode(uint8_t mode) {

	#if (defined(PRIVILEGED_USER_S))
	uint32_t	core;

	core = GET_RUNNING_CORE;

	const	bool	in_svc = vPriv_insideSVC[core];
	const	bool	in_exc = vPriv_insideException[core];

// Determine if the elevation request originates from an SVC or an exception.
// If so, enabling privileged mode is unnecessary.

	if ((in_svc == true) || (in_exc == true)) {
		return (KERR_KERN_NOERR);
	}

	RIGHTS_ELEVATION;

// From this point, we are in hard-ioff state.
//
// If the process is already running in privileged mode, no need to re-enable it.

	if (vKern_runProc[core]->oSpecification.oMode == KPROC_PRIVILEGED) {
		INTERRUPTION_ON_HARD;
		return (KERR_KERN_NOERR);
	}

	switch (mode) {
		case KPROC_PRIVILEGED: {
			vKern_runProc[core]->oInternal.oNestedPrivilege++;
			vKern_runProc[core]->oInternal.oState |= (1u<<BPROC_PRIV_ELEVATED);
			break;
		}
		case KPROC_USER: {
			vKern_runProc[core]->oInternal.oNestedPrivilege -= (vKern_runProc[core]->oInternal.oNestedPrivilege > 0u) ? (1u) : (0u);
			if (vKern_runProc[core]->oInternal.oNestedPrivilege == 0u) {
				vKern_runProc[core]->oInternal.oState &= (uint16_t)~(1u<<BPROC_PRIV_ELEVATED);

				INTERRUPTION_ON_HARD;
				SET_USER_MODE;
				return (KERR_KERN_NOERR);
			}

			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}
	INTERRUPTION_ON_HARD;

	#else
	UNUSED(mode);
	#endif

	return (KERR_KERN_NOERR);
}

/*
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
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
void	kern_privilegeElevate(void) __attribute__ ((naked));
void	kern_privilegeElevate(void) {

	#if (defined(PRIVILEGED_USER_S))

// Load the caller address into r0.
// GET_ADDRESS_ELEVATION_CALLER sets r0, which is then passed as the
// argument to CALL_FNCT_ELEVATION according to the Cortex ABI.

	GET_ADDRESS_ELEVATION_CALLER;
	CALL_FNCT_ELEVATION(local_elevate);

	KERN_RETURN_ELEVATION;
	#endif
}

#if (defined(PRIVILEGED_USER_S))
static	void	__attribute__ ((noinline, used)) local_elevate(uintptr_t callAddress) {
	extern	uintptr_t	priv_returnElevation;

	if (callAddress != (uintptr_t)&priv_returnElevation) {
		LOG(KFATAL_KERNEL, "priv: elevation forbidden");
		exit(EXIT_OS_PANIC_ELEVATION);
	}

	SET_PRIVILEGED_MODE;
	INTERRUPTION_OFF_HARD;
}
#endif
