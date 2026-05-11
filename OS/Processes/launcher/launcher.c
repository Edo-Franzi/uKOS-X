/*
; launcher.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		launcher process; launch all the defined daemon & processes.
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

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"launcher     Launcher: launch the daemons & processes. (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "launcher process\n"
									"================\n\n"

									"Launch all the available daemons & processes of the system\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// This process has to run on the following cores:

#define	KEXECUTION_CORE		((1u<<BCORE_0) | (1u<<BCORE_1) | (1u<<BCORE_2) | (1u<<BCORE_3))

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Launcher,						// Module name (the first letter has to be upper case)
	KID_FAM_PROCESSES,				// Family (defined in the module.h)
	KNUM_LAUNCHER,					// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	prgm,							// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	KEXECUTION_CORE					// Execution cores
);

// Process specific
// ================

#define	KID_IDLE			(((uint32_t)KID_FAM_DAEMONS<<24u)   | ((uint32_t)KNUM_IDLE<<8u)		| (uint32_t)'_')
#define	KID_ALIVE			(((uint32_t)KID_FAM_PROCESSES<<24u) | ((uint32_t)KNUM_ALIVE<<8u)	| (uint32_t)'_')
#define	KID_LAUNCHER		(((uint32_t)KID_FAM_PROCESSES<<24u) | ((uint32_t)KNUM_LAUNCHER<<8u) | (uint32_t)'_')

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Process_launcher";
STRG_LOC_CONST(aStrText[]) = "Process launcher: launch processes.       (c) EFr-2026";

// Prototypes

static	void	local_process(const void *argument);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	proc_t	*process;

	UNUSED(argc);
	UNUSED(argv);

	PROCESS_STACKMALLOC(
		0,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process,						// Code of the process
		aStrIden,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

// Force the privileged mode to make possible the daemon installation

	specification.oMode = KPROC_PRIVILEGED;

	if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "launcher: create proc"); exit(EXIT_OS_PANIC); }

	LOG(KINFO_SYSTEM, "launcher: process launcher launched");
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - Install all the processes of the system
 *
 */
[[noreturn]]
static	void	local_process(const void *argument) {
			uint16_t		index = 0u;
			uint32_t		core, idModule, argc = 4u;
	const	uKOS_module_t	*module;

	static	const	char_t			*vArgv_alive[4][4] = {

//										  name     ton   toff   LED
										{ "alive", "50", "950", "0" },	// Core 0
										{ "alive", "50", "950", "1" },	// Core 1
										{ "alive", "50", "950", "2" },	// Core 2
										{ "alive", "50", "950", "3" }	// Core 3
									};

	UNUSED(argument);

	core = GET_RUNNING_CORE;
	LOG(KINFO_SYSTEM, "launcher: launching all the processes");

// Looking for a module early initialisation

	index = 0u;
	while (system_getModuleFamily((uint8_t)KID_FAM_ALL_FAMILIES, &idModule, &index, &module) == KERR_SYSTEM_NOERR) {
		if (module->oInit != nullptr) {
			module->oInit(0u, nullptr);
		}
		index++;
	}
	LOG(KINFO_SYSTEM, "launcher: early initialisations");

// Install all the processes (special case for the ALIVE process)

	index = 0u;
	while (system_getModuleFamily((uint8_t)KID_FAM_PROCESSES, &idModule, &index, &module) == KERR_SYSTEM_NOERR) {
		if (!((idModule == (uint32_t)KID_ALIVE) || (idModule == (uint32_t)KID_LAUNCHER))) {
			if (((1u<<core) & module->oExecutionCore) != 0u) {
				module->oExecution(0u, nullptr);
			}
		}
		index++;
	}
	if (system_getModuleId((uint32_t)KID_ALIVE, &index, &module) == KERR_SYSTEM_NOERR) {
		if (((1u<<core) & module->oExecutionCore) != 0) {
			module->oExecution(argc, &vArgv_alive[core][0]);
		}
	}
	LOG(KINFO_SYSTEM, "launcher: all process launched");

// Install all the deamons (except the idle)
// Consider all the possible cores

	index = 0u;
	while (system_getModuleFamily((uint8_t)KID_FAM_DAEMONS, &idModule, &index, &module) == KERR_SYSTEM_NOERR) {
		if ((idModule != (uint32_t)KID_IDLE)) {
			if (((1u<<core) & module->oExecutionCore) != 0) {
				module->oExecution(0u, nullptr);
			}
		}
		index++;
	}
	LOG(KINFO_SYSTEM, "launcher: all daemon launched");

// Process launcher commits a suicide (by the exit)

	exit(EXIT_OS_SUCCESS);
}
