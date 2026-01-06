/*
; basic.
; ======

; SPDX-License-Identifier: MIT

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
 * \ingroup app_mutx
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 3 processes:
 *
 *			- P0: Get the semaphore "Critical" handle
 *				  Every 10-ms
 *					- Toggle LED 1
 *					- lock a mutex
 *					- Generate a data structure and print it
 *					- Release a mutex
 *
 *			- P1: Every 100-ms
 *					- Toggle LED 2
 *					- lock a mutex
 *					- Generate a data structure and print it
 *					- Release a mutex
 *
 *			- P2: Every 10-ms
 *					- Toggle LED 3
 *					- lock a mutex
 *					- Generate a data structure and print it
 *					- Release a mutex
 *
 */

#include	"uKOS.h"
#include	"kern/private/private_mutexes.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"basic        Example of how to use mutexes.            (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  basic\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	UserAppl,							// Module name (the first letter has to be upper case)
	KID_FAM_APPLICATIONS,				// Family (defined in the module.h)
	KNUM_APPLICATION,					// Module identifier (defined in the module.h)
	NULL,								// Address of the initialisation code (early pre-init)
	aStart,								// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,								// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);

// Application specific
// ====================

typedef	struct	strt	strt_t;

struct	strt {
			char_t		oProcess;		// Process identifier
			uint32_t	oField;			// Field
			uint32_t	oCounter;		// Counter
		};

static	volatile	strt_t	vData;

// Prototypes

static	void	local_printStruct(mutx_t *mutex, strt_t data);

/*
 * \brief aProcess 0
 *
 * - P0: Get the mutex "Critical" handle
 *		 Every 10-ms
 *			- Toggle LED 1
 *			- lock a mutex
 *			- Generate a data structure and print it
 *			- Release a mutex
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {
	int32_t		status;
	mutx_t		*mutex;

	UNUSED(argument);

// Get the mutex handle

	while (kern_getMutexById("Critical", &mutex) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }

	while (true) {
		kern_suspendProcess(10);

		led_toggle(KLED_1);
		status = kern_lockMutex(mutex, 10000u);
		if (status != KERR_KERN_NOERR) {
			exit(EXIT_OS_PANIC);
		}

// Critical resource

		vData.oProcess = '0';
		vData.oField = 0x0000u;
		vData.oCounter++;

// Force the switch (just to verify that another process cannot use the critical resource)

		kern_switchFast();

		local_printStruct(mutex, vData);
		kern_unlockMutex(mutex);
	}
}

/*
 * \brief aProcess 1
 *
 * - P1: Get the mutex "Critical" handle
 *		 Every 100-ms
 *			- Toggle LED 2
 *			- lock a mutex
 *			- Generate a data structure and print it
 *			- Release a mutex
 *
 */
static void __attribute__ ((noreturn)) aProcess_1(const void *argument) {
	int32_t		status;
	mutx_t		*mutex;

	UNUSED(argument);

// Get the mutex handle

	while (kern_getMutexById("Critical", &mutex) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }

	while (true) {
		kern_suspendProcess(100u);

		led_toggle(KLED_2);
		status = kern_lockMutex(mutex, 10000u);
		if (status != KERR_KERN_NOERR) {
			exit(EXIT_OS_PANIC);
		}

// Critical resource

		vData.oProcess = '1';
		vData.oField = 0x1111u;
		vData.oCounter++;

// Force the switch (just to verify that another process cannot use the critical resource)

		kern_switchFast();

		local_printStruct(mutex, vData);
		kern_unlockMutex(mutex);
	}
}

/*
 * \brief aProcess 2
 *
 * - P2: Get the mutex "Critical" handle
 *		 Every 1000-ms
 *			- Toggle LED 3
 *			- lock a mutex
 *			- Generate a data structure and print it
 *			- Release a mutex
 *
 */
static void __attribute__ ((noreturn)) aProcess_2(const void *argument) {
	int32_t		status;
	mutx_t		*mutex;

	UNUSED(argument);

// Get the mutex handle

	while (kern_getMutexById("Critical", &mutex) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }

	while (true) {
		kern_suspendProcess(1000u);

		led_toggle(KLED_3);
		status = kern_lockMutex(mutex, 10000u);
		if (status != KERR_KERN_NOERR) {
			exit(EXIT_OS_PANIC);
		}

// Critical resource

		vData.oProcess = '2';
		vData.oField = 0x2222u;
		vData.oCounter++;

// Force the switch (just to verify that another process cannot use the critical resource)

		kern_switchFast();

		local_printStruct(mutex, vData);
		kern_unlockMutex(mutex);
	}
}

/*
 * \brief local_printStruct
 *
 */
static	void	local_printStruct(mutx_t *mutex, strt_t data) {
	int32_t		counter;

	PRIVILEGE_ELEVATE;
	counter = mutex->oCounter;
	PRIVILEGE_RESTORE;

	switch (data.oProcess) {
		case '0': {
			(void)dprintf(KSYST, "%"PRId32" --> ", counter);
			if (data.oField != 0x0000u) {
				exit(EXIT_OS_PANIC);
			}

			break;
		}
		case '1': {
			(void)dprintf(KSYST, "%"PRId32" --> ", counter);
			if (data.oField != 0x1111u) {
				exit(EXIT_OS_PANIC);
			}

			break;
		}
		case '2': {
			(void)dprintf(KSYST, "%"PRId32" --> ", counter);
			if (data.oField != 0x2222u) {
				exit(EXIT_OS_PANIC);
			}

			break;
		}
		default: {
			exit(EXIT_OS_PANIC);

			break;
		}
	}

	(void)dprintf(KSYST, "Process %c, Field %4"PRIX32", Counter %"PRIu32"\n", data.oProcess, data.oField, data.oCounter);
}

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
int		main(int argc, const char *argv[]) {
	mutx_t	*mutex;
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
		aStrText_0,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		aStrIden_0,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		1,									// Index
		specification_1,					// Specifications (just use specification_x)
		aStrText_1,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_1,							// Code of the process
		aStrIden_1,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		2,									// Index
		specification_2,					// Specifications (just use specification_x)
		aStrText_2,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_2,							// Code of the process
		aStrIden_2,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createMutex("Critical", &mutex)				   != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create mutx"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_0, NULL, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, NULL, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_2, NULL, &process_2) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
