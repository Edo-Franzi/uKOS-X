/*
; calendar.
; =========

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
 * \ingroup app_sign
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 3 processes:
 *
 *			- P0: Create the sigbal group "Calendar"
 *				  Every 100-ms
 *					- mSecond++
 *					- if mSecond == 10 Generate the signal KCALENDAR
 *
 *			- P1: Get the signal "Calendar" handle
 *				  Waiting for a broadcast signal (KCALENDAR | KALARME) ("Calendar")
 *					- Compute and display the absolute time
 *
 *			- P2: Get the signal "Calendar" handle
 *				  Every 100-ms
 *					- Generate the signal KALARME
 *
 */

#include	"uKOS.h"
#include	<time.h>

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"calendar     Example of how to use signals.            (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  calendar\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#if (defined(ROMABLE_S))

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Calendar,							// Module name (the first letter has to be upper case)
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

#define	KCALENDAR	0x00000001u
#define	KALARME		0x00000002u

/*
 * \brief aProcess 0
 *
 * - P0: Create the sigbal group "Calendar"
 *		 Every 100-ms
 *			- mSecond++
 *			- if mSecond == 10 Generate the signal KCALENDAR
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {
	uint8_t		mSeconds = 0u;
	sign_t		*group;

	UNUSED(argument);

	if (kern_createSignalGroup("Calendar", &group) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create sigr"); exit(EXIT_OS_FAILURE); }

	while (true) {
		kern_suspendProcess(100u);
		if (mSeconds++ >= 9u) {
			mSeconds = 0u;
			kern_signalSignal(group, KCALENDAR, KKERN_HANDLE_BROADCAST, KSIGN_SIGNALE_WITH_CONTEXT_SWITCH);
		}
	}
}

/*
 * \brief aProcess 1
 *
 * - P1: Get the signal "Calendar" handle
 *		 Waiting for a broadcast signal (KCALENDAR | KALARME) ("Calendar")
 *			- Compute and display the absolute time
 *
 */
static void __attribute__ ((noreturn)) aProcess_1(const void *argument) {
	uint64_t	unixTime;
	time_t		now;
	tm_t		localTime;
	uint32_t	signal;
	sign_t		*group;

	UNUSED(argument);

// Get the synchro handles

	while (kern_getSignalGroupById("Calendar", &group) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }

	while (true) {
		signal = KCALENDAR | KALARME;
		kern_waitSignal(group, &signal, KKERN_HANDLE_BROADCAST, KWAIT_INFINITY);

		if ((signal & KCALENDAR) != 0u) {
			now = time(nullptr);
			localtime_r(&now, &localTime);

			calendar_readUnixTime(KFROM_TIMER, &unixTime);
			(void)dprintf(KSYST, "Signal: %08"PRIX32", Epoch = %"PRIu64", Local time: %s",
						   signal, unixTime, asctime(&localTime));
		}
		if ((signal & KALARME) != 0u) {
			(void)dprintf(KSYST, "Signal: %08"PRIX32", Alarme\n", signal);
		}
	}
}

/*
 * \brief aProcess 2
 *
 * - P2: Get the signal "Calendar" handle
 *		 Every 100-ms
 *			- Generate the signal KALARME
 *
 */
static void __attribute__ ((noreturn)) aProcess_2(const void *argument) {
	sign_t	*group;

	UNUSED(argument);

	while (kern_getSignalGroupById("Calendar", &group) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }

	while (true) {
		kern_suspendProcess(100u);
		kern_signalSignal(group, KALARME, KKERN_HANDLE_BROADCAST, KSIGN_SIGNALE_WITH_CONTEXT_SWITCH);
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

	STRG_LOC_CONST(aStrIden_0[]) = "Process_Synchro";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
	STRG_LOC_CONST(aStrIden_2[]) = "Process_Alarme";
	STRG_LOC_CONST(aStrText_0[]) = "Process Synchro.                          (c) EFr-2026";
	STRG_LOC_CONST(aStrText_1[]) = "Process user 1.                           (c) EFr-2026";
	STRG_LOC_CONST(aStrText_2[]) = "Process Alarm.                            (c) EFr-2026";

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
