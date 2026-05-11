/*
; tracing.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application shows how to operate with the uKOS-X uKernel.
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

/*!
 * \file
 * \ingroup app_moreKernel
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 1 processes:
 *
 *			- P0: Use the tracing
 *				  Generate an exception (core dump)
 *				  Display the registers
 *
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"tracing      uKernel test of the exceptions.           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  tracing\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#if (defined(ROMABLE_S))

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Tracing,							// Module name (the first letter has to be upper case)
	KID_FAM_CLI,						// Family (defined in the module.h)
	KNUM_ROMABLE_0,						// Module identifier (defined in the module.h)
	nullptr,							// Address of the initialisation code (early pre-init)
	prgm,								// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,							// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);

#else
MODULE(
	UserAppl,							// Module name (the first letter has to be upper case)
	KID_FAM_APPLICATIONS,				// Family (defined in the module.h)
	KNUM_APPLICATION,					// Module identifier (defined in the module.h)
	nullptr,							// Address of the initialisation code (early pre-init)
	aStart,								// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,							// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);
#endif

// Application specific
// ====================

#define LOC_CRASH	(volatile uint32_t *)(0x001FFFFFu)

/*
 * \brief aProcess
 *
 * - P0: Use the tracing
 *		 Generate an exception (cire dump)
 *		 Display the registers
 *
 */
[[noreturn]]
static	void	aProcess(const void *argument) {
	uint32_t	time = 20u;
	uintptr_t	i;

	UNUSED(argument);

	LOG(KINFO_USER, "launched");
	(void)dprintf(KSYST,"The machine will crash in %"PRIu32" seconds!!\n", time--);

	record_trace("--> Process 0: trace2 example", 0x02020202u);

	for (i = 0u; i < 20u; i++) {
		record_trace("--> Process 0: value", i);

		kern_suspendProcess(1000u);
		(void)dprintf(KSYST,"The machine will crash in %"PRIu32" seconds!!\n", time--);
	}

	record_trace("--> Process 0: Out loop", 0x01010101u);

	kern_suspendProcess(1000u);

// Load the registers

	record_trace("--> Process 0: save the context", 0x02020202u);

// Crash the system

	LOG(KFATAL_USER, "... and now the crash!");
	*(LOC_CRASH);
	while (true) { ; }
}

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
MAIN_ENTRY(argc, argv[]) {
	proc_t	*process;

// -------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden[]) = "Process_User_0";
	STRG_LOC_CONST(aStrText[]) = "Process user 0.                           (c) EFr-2026";

	UNUSED(argc);
	UNUSED(argv);

	LOG(KINFO_USER, "launched");
	record_trace("--> Main: Enter", 0x04040404);

// Specifications for the processes

	record_trace("--> Main: Process specifications", 0x05050505u);

	PROCESS_STACKMALLOC(
		0,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess,							// Code of the process
		aStrIden,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	record_trace("--> Main: Process launched", 0x06060606u);

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
