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
;   (c) 2025-20xx, Edo. Franzi
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
 * \ingroup app_newlib
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 2 processes:
 *
 *			- P0: Every 100-ms
 *					- Spigot algorithm:
 *					- Pi = Sum 1/16^^n * (4/(8n + 1) - 2/(8n + 4) - 1/(8n + 5) - 1/(8n + 6))
 *					- Print Pi (with the newlib dprintf) on the stdout
 *					- Toggle LED 0
 *
 *			- P1: Every 100-ms
 *					- Read 4 integers on the stdin
 *					- Print the read values (with the newlib dprintf) on the uart1
 *					- Toggle LED 1
 *
 *			- P2: Every 100-ms
 *					- Print a string (with the newlib printf) on the stdout
 *
 */

#include	"uKOS.h"
#include	<unistd.h>
#include	<fcntl.h>
#include	<math.h>

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"basic        Example of how to use the newlib.         (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  basic\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

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

/*
 * \brief aProcess 0
 *
 * - P0: Every 100-ms
 *			- Spigot algorithm:
 *			- Pi = Sum 1/16^^n * (4/(8n + 1) - 2/(8n + 4) - 1/(8n + 5) - 1/(8n + 6))
 *			- Print Pi (with the newlib dprintf) on the stdout
 *			- Toggle LED 0
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {
				uint32_t	delta;
				uint64_t	time[2];
	volatile	float64_t	n = 0.0, Pi = 0.0;

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(100u);
		led_toggle(KLED_0);

		kern_readTickCount(&time[0]);
		Pi = Pi + ((1.0 / pow(16, n)) * ((4.0 / ((8.0 * n) + 1.0)))
	   			- (2.0 / ((8.0 * n) + 4.0))
	    		- (1.0 / ((8.0 * n) + 5.0))
				- (1.0 / ((8.0 * n) + 6.0)));

		kern_readTickCount(&time[1]);
		delta = (uint32_t)(time[1] - time[0]);

		n = n + 1.0;

		(void)dprintf(KSTDOUT, "n = %"PRIu32", Pi = %.9f Time = %"PRIu32"\n", (uint32_t)n, Pi, delta);
	}
}

/*
 * \brief aProcess 1
 *
 * - P1: Every 100-ms
 *			- Read 4 integers on the uart0
 *			- Print the read values (with the newlib dprintf) on the uart1
 *			- Toggle LED 1
 *
 */
static void __attribute__ ((noreturn)) aProcess_1(const void *argument) {
	int32_t		a, b, c, d;

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(100u);
		led_toggle(KLED_1);

// Waiting for 4 integers
// If we enter garbage, the length will be 0 and we need to empty the buffer

// NOLINTBEGIN(cert-err34-c)
//
		if (scanf("%"PRId32" %"PRId32" %"PRId32" %"PRId32"", &a, &b, &c, &d) != 4) {
			while (getchar() != '\n') { ; }
		}
		else {
			(void)dprintf(KURT1, "a = %"PRId32", b = %"PRId32", c = %"PRId32", d = %"PRId32"\n", a, b, c, d);
		}

// NOLINTEND(cert-err34-c)
//
	}
}

/*
 * \brief aProcess 2
 *
 * - P1: Every 100-ms
 *			- Print a string on the stdout
 *
 */
static void __attribute__ ((noreturn)) aProcess_2(const void *argument) {

// !!! For big strings, consider to use pointers to accomodate them

	char_t	myBigText[] = "P2: The old dreams were good dreams. They didn't work out, but I'm glad I had them.\n";

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(100u);

		(void)printf("%s", myBigText);
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
int		main(int argc, const char *argv[]) {
	proc_t	*process_0, *process_1, *process_2;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2025";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
	STRG_LOC_CONST(aStrText_1[]) = "Process user 1.                           (c) EFr-2025";
	STRG_LOC_CONST(aStrIden_2[]) = "Process_User_2";
	STRG_LOC_CONST(aStrText_2[]) = "Process user 2.                           (c) EFr-2025";

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use specification_x)
		aStrText_0,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_XLIB,				// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		aStrIden_0,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		1,									// Index
		specification_1,					// Specifications (just use specification_x)
		aStrText_1,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_XLIB,				// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_1,							// Code of the process
		aStrIden_1,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		2,									// Index
		specification_2,					// Specifications (just use specification_x)
		aStrText_2,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_XLIB,				// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_2,							// Code of the process
		aStrIden_2,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, NULL, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, NULL, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_2, NULL, &process_2) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched, kill the console");
	return (EXIT_OS_SUCCESS);
}
