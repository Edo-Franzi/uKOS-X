/*
; boot.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Bootstrap of the system
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
#include	<stdlib.h>

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"boot         Bootstrap of uKOS-X.                      (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Boot\n"
									"====\n\n"

									"This code prepare for the system boot\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Boot,							// Module name (the first letter has to be upper case)
	KID_FAM_STARTUPS,				// Family (defined in the module.h)
	KNUM_BOOT,						// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Boot specific
// =============

#define	KID_IDLE	((KID_FAM_DAEMONS<<24u) | (KNUM_IDLE<<8u) | '_')

/*
 * \brief Main entry point
 *
 * - Create the boot process
 * - Install the "idle" daemon
 * - Install all the system daemon
 * - Install the "launcher" process
 * - Process boot commits a suicide (by the exit)
 *
 */
int32_t		boot(void) {
			uint16_t		index = 0u;
			uint32_t		core;
	const	uKOS_module_t	*module;

	core = GET_RUNNING_CORE;

// Initialise the uKernel
// Set KURT0 as a default (it could be changed in the start-up process)

	kern_init();

	#if (defined(CONFIG_MAN_SERIAL_S))
	serial_setDefSerialManager(KURT0);
	#endif

// Install the daemon idle (HAS TO BE THE FIRST IN THE EXECUTION LIST)
// Consider all the possible cores

	if (system_getModuleName("idle", &index, &module) != KERR_SYSTEM_NOERR) {
		LOG(KFATAL_SYSTEM, "boot: daemon idle not found");
		exit(EXIT_OS_PANIC);
	}

	if (((1u<<core) & module->oExecutionCore) != 0u) {
		module->oExecution(0u, nullptr);
	}
	LOG(KINFO_SYSTEM, "boot: daemon idle launched");

// Install the process launcher
// Consider all the possible cores

	if (system_getModuleName("launcher", &index, &module) != KERR_SYSTEM_NOERR) {
		LOG(KFATAL_SYSTEM, "boot: process launcher not found");
		exit(EXIT_OS_PANIC);
	}

	if (((1u<<core) & module->oExecutionCore) != 0) {
		module->oExecution(0u, nullptr);
	}
	LOG(KINFO_SYSTEM, "boot: Process launcher launched");

// Initialise the C++ constructors
// Start the time sharing
// Leave the "first" process and start ...

	CPP_INIT_ARRAYS;
	kern_runKernel();

	INTERRUPTION_ON_HARD;
	kern_switchFast();
	return (EXIT_OS_SUCCESS_CLI);
}
