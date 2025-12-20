/*
; plotSin.
; ========

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
 * \ingroup app_basic
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 1 processes:
 *
 *			- P0: Every 10-ms
 *					- Compute a noisy sinus
 *					- Send it on the serial comm (using the Arduino format)
 *					- Toggle LED 0
 *
 *			Used for the scope observation.
 *
 *			1. Use CoolTerm to display the results (using the Arduino format)
 *			2. Download a uKOS-X application (e.g. plotSin)
 *
 */

#include	"uKOS.h"
#include	<stdlib.h>
#include	<math.h>

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"plotSin      Example of plot functions on CoolTerm2.   (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  plotSin\n"
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

// Application specific
// ====================

#ifndef	M_PI
#define	M_PI				3.14159265358979323846
#endif

#define	KAMPLITUDE_BASIC	5.0
#define	KAMPLITUDE_NOISE	2.0
#define	KAMPLITUDE_FINAL	(400.0 / KAMPLITUDE_BASIC)

/*
 * \brief aProcess 0
 *
 * - P0: Every 10-ms
 *			- Compute a noisy sinus
 *			- Send it on the serial comm (using the Arduino format)
 *			- Toggle LED 0
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {
	uint16_t	x;
	uint32_t	random;
	float64_t	y;

	UNUSED(argument);

// Wait a bit (to allow to switch CoolTerm2 in the right mode)

	kern_suspendProcess(10000u);

	while (true) {
		for (x = 0u; x < 360u; x += 1) {

// Compute the genuine sin
// Add a random noise
// Scale the final signal

			y = KAMPLITUDE_BASIC * sin(x * M_PI / 180.0);

			random_read(KRANDOM_SOFT, &random, 1u);
			y = y + ((((float64_t)random / KRAND_MAX) - 0.5) * KAMPLITUDE_NOISE);
			y = KAMPLITUDE_FINAL * y;

// Print the data using the Arduino format in CoolTerm2

			(void)dprintf(KSYST, "%"PRIu16"\t%5.2f\n", x, y);
			kern_suspendProcess(10u);
		}
		led_toggle(KLED_0);
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
	proc_t	*process_0;

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use specification_x)
		NULL,								// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		NULL,								// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, NULL, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

// Do not return with "EXIT_OS_SUCCESS_CLI" because the "console" uses the KURT0


	LOG(KINFO_USER, "Application launched, kill the console");
	return (EXIT_OS_SUCCESS);
}
