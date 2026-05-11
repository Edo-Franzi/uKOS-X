/*
; multiKill.
; ==========

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
 * \ingroup app_basic
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 10 processes:
 *
 *			- main: Every 1-ms & for 1000000000 times
 *					- Create a new process
 *
 *			- Px: Increment the counter t
 *				  Commit a suicide
 *
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"multiKill    Example of how to commit a suicide.       (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  multiKill\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#if (defined(ROMABLE_S))

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	MultiKill,							// Module name (the first letter has to be upper case)
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

// -----------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden_0[]) = "Process_Test_0";
STRG_LOC_CONST(aStrIden_1[]) = "Process_Test_1";
STRG_LOC_CONST(aStrIden_2[]) = "Process_Test_2";
STRG_LOC_CONST(aStrIden_3[]) = "Process_Test_3";
STRG_LOC_CONST(aStrIden_4[]) = "Process_Test_4";
STRG_LOC_CONST(aStrIden_5[]) = "Process_Test_5";
STRG_LOC_CONST(aStrIden_6[]) = "Process_Test_6";
STRG_LOC_CONST(aStrIden_7[]) = "Process_Test_7";
STRG_LOC_CONST(aStrIden_8[]) = "Process_Test_8";
STRG_LOC_CONST(aStrIden_9[]) = "Process_Test_9";
STRG_LOC_CONST(aStrText_0[]) = "Process Test 0.                           (c) EFr-2026";
STRG_LOC_CONST(aStrText_1[]) = "Process Test 1.                           (c) EFr-2026";
STRG_LOC_CONST(aStrText_2[]) = "Process Test 2.                           (c) EFr-2026";
STRG_LOC_CONST(aStrText_3[]) = "Process Test 3.                           (c) EFr-2026";
STRG_LOC_CONST(aStrText_4[]) = "Process Test 4.                           (c) EFr-2026";
STRG_LOC_CONST(aStrText_5[]) = "Process Test 5.                           (c) EFr-2026";
STRG_LOC_CONST(aStrText_6[]) = "Process Test 6.                           (c) EFr-2026";
STRG_LOC_CONST(aStrText_7[]) = "Process Test 7.                           (c) EFr-2026";
STRG_LOC_CONST(aStrText_8[]) = "Process Test 8.                           (c) EFr-2026";
STRG_LOC_CONST(aStrText_9[]) = "Process Test 9.                           (c) EFr-2026";

typedef	struct	myPack	myPack_t;

struct	myPack {
			uint32_t	oIncrement;
		};

static	myPack_t	aParameter[10] = {
						{ 0u },
						{ 1u },
						{ 2u },
						{ 3u },
						{ 4u },
						{ 5u },
						{ 6u },
						{ 7u },
						{ 8u },
						{ 9u }
					};

static				proc_t		*vProcess[10];
static	volatile	uint32_t	vCounter = 0u;

/*
 * \brief aProcess x
 *
 * - Px: - Increment a counter
 *		 - Commit a suicide
 *
 */
[[noreturn]]
static	void	aThread_Px(const void *argument) {
			uint32_t	increment;
	const	myPack_t	*pack;

	pack = (const myPack_t *)argument;

	increment = pack->oIncrement;
	vCounter += increment;
	exit(EXIT_OS_SUCCESS);
}

/*
 * \brief aProcess a
 *
 * - Px: - Increment a counter
 *		 - Commit a suicide
 *
 */
#define	KPRIORITY	KKERN_PRIORITY_LOW_01

[[noreturn]]
static	void	aProcess_a(const void *argument) {
	uint32_t	i;

	UNUSED(argument);

	for (i = 0u; i < 1000000000u; i++) {

// Specifications for the processes

		PROCESS_STACKMALLOC(
			0,									// Index
			specification_0,					// Specifications (just use specification_x)
			aStrText_0,							// Info string (nullptr if anonymous)
			KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
			aThread_Px,							// Code of the process
			aStrIden_0,							// Identifier (nullptr if anonymous)
			KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
			KPRIORITY							// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
		);

		PROCESS_STACKMALLOC(
			1,									// Index
			specification_1,					// Specifications (just use specification_x)
			aStrText_1,							// Info string (nullptr if anonymous)
			KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
			aThread_Px,							// Code of the process
			aStrIden_1,							// Identifier (nullptr if anonymous)
			KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
			KPRIORITY							// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
		);

		PROCESS_STACKMALLOC(
			2,									// Index
			specification_2,					// Specifications (just use specification_x)
			aStrText_2,							// Info string (nullptr if anonymous)
			KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
			aThread_Px,							// Code of the process
			aStrIden_2,							// Identifier (nullptr if anonymous)
			KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
			KPRIORITY							// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
		);

		PROCESS_STACKMALLOC(
			3,									// Index
			specification_3,					// Specifications (just use specification_x)
			aStrText_3,							// Info string (nullptr if anonymous)
			KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
			aThread_Px,							// Code of the process
			aStrIden_3,							// Identifier (nullptr if anonymous)
			KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
			KPRIORITY							// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
		);

		PROCESS_STACKMALLOC(
			4,									// Index
			specification_4,					// Specifications (just use specification_x)
			aStrText_4,							// Info string (nullptr if anonymous)
			KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
			aThread_Px,							// Code of the process
			aStrIden_4,							// Identifier (nullptr if anonymous)
			KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
			KPRIORITY							// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
		);

		PROCESS_STACKMALLOC(
			5,									// Index
			specification_5,					// Specifications (just use specification_x)
			aStrText_5,							// Info string (nullptr if anonymous)
			KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
			aThread_Px,							// Code of the process
			aStrIden_5,							// Identifier (nullptr if anonymous)
			KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
			KPRIORITY							// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
		);

		PROCESS_STACKMALLOC(
			6,									// Index
			specification_6,					// Specifications (just use specification_x)
			aStrText_6,							// Info string (nullptr if anonymous)
			KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
			aThread_Px,							// Code of the process
			aStrIden_6,							// Identifier (nullptr if anonymous)
			KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
			KPRIORITY							// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
		);

		PROCESS_STACKMALLOC(
			7,									// Index
			specification_7,					// Specifications (just use specification_x)
			aStrText_7,							// Info string (nullptr if anonymous)
			KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
			aThread_Px,							// Code of the process
			aStrIden_7,							// Identifier (nullptr if anonymous)
			KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
			KPRIORITY							// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
		);

		PROCESS_STACKMALLOC(
			8,									// Index
			specification_8,					// Specifications (just use specification_x)
			aStrText_8,							// Info string (nullptr if anonymous)
			KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
			aThread_Px,							// Code of the process
			aStrIden_8,							// Identifier (nullptr if anonymous)
			KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
			KPRIORITY							// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
		);

		PROCESS_STACKMALLOC(
			9,									// Index
			specification_9,					// Specifications (just use specification_x)
			aStrText_9,							// Info string (nullptr if anonymous)
			KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
			aThread_Px,							// Code of the process
			aStrIden_9,							// Identifier (nullptr if anonymous)
			KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
			KPRIORITY							// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
		);

		if ((vStack_0 == nullptr) || (vStack_1 == nullptr) || (vStack_2 == nullptr) || (vStack_3 == nullptr) || (vStack_4 == nullptr) ||
			(vStack_5 == nullptr) || (vStack_6 == nullptr) || (vStack_7 == nullptr) || (vStack_8 == nullptr) || (vStack_9 == nullptr)) {
			LOG(KFATAL_USER, "Out of memory");
			exit(EXIT_OS_FAILURE);
		}

		if (kern_createProcess(&specification_0, &aParameter[0], &vProcess[0]) != KERR_KERN_NOERR) {
			LOG(KFATAL_USER, "Create proc");
			exit(EXIT_OS_FAILURE);
		}

		if (kern_createProcess(&specification_1, &aParameter[1], &vProcess[1]) != KERR_KERN_NOERR) {
			LOG(KFATAL_USER, "Create proc");
			exit(EXIT_OS_FAILURE);
		}

		if (kern_createProcess(&specification_2, &aParameter[2], &vProcess[2]) != KERR_KERN_NOERR) {
			LOG(KFATAL_USER, "Create proc");
			exit(EXIT_OS_FAILURE);
		}

		if (kern_createProcess(&specification_3, &aParameter[3], &vProcess[3]) != KERR_KERN_NOERR) {
			LOG(KFATAL_USER, "Create proc");
			exit(EXIT_OS_FAILURE);
		}

		if (kern_createProcess(&specification_4, &aParameter[4], &vProcess[4]) != KERR_KERN_NOERR) {
			LOG(KFATAL_USER, "Create proc");
			exit(EXIT_OS_FAILURE);
		}

		if (kern_createProcess(&specification_5, &aParameter[5], &vProcess[5]) != KERR_KERN_NOERR) {
			LOG(KFATAL_USER, "Create proc");
			exit(EXIT_OS_FAILURE);
		}

		if (kern_createProcess(&specification_6, &aParameter[6], &vProcess[6]) != KERR_KERN_NOERR) {
			LOG(KFATAL_USER, "Create proc");
			exit(EXIT_OS_FAILURE);
		}

		if (kern_createProcess(&specification_7, &aParameter[7], &vProcess[7]) != KERR_KERN_NOERR) {
			LOG(KFATAL_USER, "Create proc");
			exit(EXIT_OS_FAILURE);
		}

		if (kern_createProcess(&specification_8, &aParameter[8], &vProcess[8]) != KERR_KERN_NOERR) {
			LOG(KFATAL_USER, "Create proc");
			exit(EXIT_OS_FAILURE);
		}

		if (kern_createProcess(&specification_9, &aParameter[9], &vProcess[9]) != KERR_KERN_NOERR) {
			LOG(KFATAL_USER, "Create proc");
			exit(EXIT_OS_FAILURE);
		}

		if ((i % 1000u) == 0u) {
			(void)dprintf(KSYST, "Iteration = %"PRIu32"\n", i);
		}
		kern_suspendProcess(1u);
	}

	(void)dprintf(KSYST, "Counter = %"PRIu32"\n", vCounter);
	kern_suspendProcess(1000u);
	exit(EXIT_OS_SUCCESS);
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
	proc_t	*process_a;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_a[]) = "Process_User_0";
	STRG_LOC_CONST(aStrText_a[]) = "Process user 0.                           (c) EFr-2026";

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		a,									// Index
		specification_a,					// Specifications (just use specification_x)
		aStrText_a,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_LL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_a,							// Code of the process
		aStrIden_a,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_a, nullptr, &process_a) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
