/*
; ticTac.
; =======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application shows how to operate with the uKOS-X uKernel.
; Expected results:
;			Serial terminal output
;			uKOS-X > run
;			Execute the downloaded application.
;			Run the downloaded application...
;
;	uKOS-X >
;	dprintf time_1 0 [us]
;	Machine = Firefly_H743 cpt = 0  Firefly_H743, privileged-user mode, V.0.5.7
;	(c) LvA, Jun  7 2026  08:41:18
;	gcc-16.1.0, git: a55ba3e003
;
;	dprintf time_1 1006 [us]
;	dprintf time_1 1005 [us]
;	Machine = Firefly_H743 cpt = 1  Firefly_H743, privileged-user mode, V.0.5.7
;	(c) LvA, Jun  7 2026  08:41:18
;	gcc-16.1.0, git: a55ba3e003
;
;	dprintf time_1 1006 [us]
;	TickCount time 3 [us]
;	dprintf time_1 1006 [us]
;	Machine = Firefly_H743 cpt = 2  Firefly_H743, privileged-user mode, V.0.5.7
;	(c) LvA, Jun  7 2026  08:41:18
;	gcc-16.1.0, git: a55ba3e003
;
;	dprintf time_1 1006 [us]
;	dprintf time_1 1006 [us]
;	Machine = Firefly_H743 cpt = 3  Firefly_H743, privileged-user mode, V.0.5.7
;	(c) LvA, Jun  7 2026  08:41:18
;	gcc-16.1.0, git: a55ba3e003
;
;	dprintf time_1 1006 [us]
;	Machine = Firefly_H743 cpt = 4  Firefly_H743, privileged-user mode, V.0.5.7
;	(c) LvA, Jun  7 2026  08:41:18
;	gcc-16.1.0, git: a55ba3e003
;
;	.....
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
 *			Launch 3 processes:
 *
 *			- P0: Every 1000-ms
 *					- Toggle LED 1
 *					- Measure (tac - tic) time of the Toggle LED 1 function
 *
 *			- P1: Every 200-ms
 *					- Measure (tac - tic) time of the printf function
 *					- Display the function time durations
 *
 *			- P2: Every 350-ms
 *				  	- Read the identifier string of the TBox library
 *				  	- Display the identifier string
 *
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"ticTac       Example of how to measure exec. times.    (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  ticTac\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#if (defined(ROMABLE_S))

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	TicTac,								// Module name (the first letter has to be upper case)
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

/*
 * \brief aProcess 0
 *
 * - P0: Every 1000-ms
 *			- Toggle LED 1
 *			- Measure (tac - tic) time of the Toggle LED 1 function
 *
 */
[[noreturn]]
static	void	aProcess_0(const void *argument) {
	uint64_t	time[2];
	uint32_t	delta;

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(1000u);
		kern_readTickCount(&time[0]);
		led_toggle(KLED_1);
		kern_readTickCount(&time[1]);

		delta = (uint32_t)(time[1] - time[0]);
		(void)dprintf(KSYST, "TickCount time %"PRIu32" [us]\n", delta);
	}
}

/*
 * \brief aProcess 1
 *
 * - P1: Every 200-ms
 *			- Measure (tac - tic) time of the printf function
 *			- Display the function time durations
 *
 */
[[noreturn]]
static	void	aProcess_1(const void *argument) {
	uint64_t	time[2];
	uint32_t	delta = 0u;

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(200u);

		kern_readTickCount(&time[0]);
		(void)dprintf(KSYST, "dprintf time_1 %"PRIu32" [us]\n", delta);
		kern_readTickCount(&time[1]);
		delta = (uint32_t)(time[1] - time[0]);
	}
}

/*
 * \brief aProcess 2
 *
 * - P2: Every 350-ms
 *			- Read the identifier string of the TBox library
 *			- Display the identifier string
 *
 */
[[noreturn]]
static	void	aProcess_2(const void *argument) {
			uint32_t	cpt = 0;
	const	char_t		*identifier;
	const	char_t		*family;

	UNUSED(argument);

	system_getSystemId(&identifier);
	system_getFamilyId(&family);

	while (true) {
		kern_suspendProcess(350u);

		(void)dprintf(KSYST, "Machine = %s cpt = %"PRIu32"  %s\n", family, cpt++, identifier);
	}
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
	proc_t	*process_0, *process_1, *process_2;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
	STRG_LOC_CONST(aStrIden_2[]) = "Process_User_2";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2026";
	STRG_LOC_CONST(aStrText_1[]) = "Process user 1.                           (c) EFr-2026";
	STRG_LOC_CONST(aStrText_2[]) = "Process user 2.                           (c) EFr-2026";

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use specification_x)
		aStrText_0,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		aStrIden_0,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		1,									// Index
		specification_1,					// Specifications (just use specification_x)
		aStrText_1,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_1,							// Code of the process
		aStrIden_1,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		2,									// Index
		specification_2,					// Specifications (just use specification_x)
		aStrText_2,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_2,							// Code of the process
		aStrIden_2,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, nullptr, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, nullptr, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_2, nullptr, &process_2) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
