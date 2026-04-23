/*
; speed.
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
 * \ingroup app_special
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 2 processes:
 *
 *			- P0: Every 1000-ms
 *					- Toggle LED 1
 *					- Capture the stop time
 *					- time = stop - start
 *					- Display the speed of the test (time)
 *					- generate the signal KTRIGGER
 *
 *			- P1: Waiting for the signal KTRIGGER
 *					- Capture the start time
 *					- Increment a counter
 *
 *			Some results: (bigger values are better)
 *			Compiler used: Cortex gcc-15.2.0
 *
 *			Alastor_H743	400-MHz		External ram (SDRAM)	993563	(with instruction cache)
 *			Asmodee_H747	480-MHz		Internal ram			1193830 (with instruction cache)
 *			DevKit_nRF5340	128-MHz		Internal ram 			71030
 *			Discovery_U5G9	160-MHz		Internal ram 			197506  (with instruction cache)
 *			MAiXDUiNO_K210	400-MHz		Internal ram			1660922 (with instruction cache)
 *			Nucleo_F207		120-MHz		Internal ram 			77639
 *			Nucleo_H743		480-MHz		Internal ram 			1194164 (with instruction cache)
 *			Nucleo_L4R5		120-MHz		Internal ram 			94133
 *			Nucleo_N657		800-MHz		Internal ram 			1449565 (with instruction cache)
 *			Pico2_rp2350	150-MHz		Internal ram			246652
 *
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"speed        Test of the CPU/memory performance.       (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  speed\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#if (defined(ROMABLE_S))

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Speed,								// Module name (the first letter has to be upper case)
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

#define	KTRIGGER	0x00000001u

static				uint64_t	vTime[2];
static	volatile	uint64_t	vCounter;
static	volatile	bool		vEnd = false;

/*
 * \brief aProcess 0
 *
 * - P0: Every 1000-ms
 *			- Toggle LED 1
 *			- Capture the stop time
 *			- time = stop - start
 *			- Display the speed of the test (time)
 *			- generate the signal KTRIGGER
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {
	uint64_t	counter, time;
	sign_t		*group;

	UNUSED(argument);

	if (kern_createSignalGroup("Synchro", &group) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); exit(EXIT_OS_FAILURE); }

	(void)dprintf(KSYST, "Target: "KTARGET"\n");

	while (true) {
		kern_suspendProcess(1000u);
		led_toggle(KLED_1);

// Prepare to synchronize the process 1

		vEnd = false;
		kern_readTickCount(&vTime[0]);
		kern_signalSignal(group, KTRIGGER, KKERN_HANDLE_BROADCAST, KSIGN_SIGNALE_WITH_CONTEXT_SWITCH);

// Run the process 1
// Run the process 1
// Run the process 1
// Run the process 1
// ...

		kern_readTickCount(&vTime[1]);

		counter = vCounter;
		time    = vTime[1]-vTime[0];
		vEnd    = true;

		(void)dprintf(KSYST, "Counter = %"PRIu64", Time = %"PRIu64"\n", counter, time);
		kern_switchFast();

// Run the process 1
// ...

	}
}

/*
 * \brief aProcess 1
 *
 * - P1: Waiting for the signal KTRIGGER
 *			- Capture the start time
 *			- Increment a counter
 *
 */
static void __attribute__ ((noreturn)) aProcess_1(const void *argument) {
	uint32_t	signal;
	sign_t		*group;

	UNUSED(argument);

	while (kern_getSignalGroupById("Synchro", &group) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }

	while (true) {
		signal = KTRIGGER;
		kern_waitSignal(group, &signal, KKERN_HANDLE_BROADCAST, 10000u);

		vCounter = 0u;
		do { vCounter++; } while (vEnd == false);
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
	proc_t	*process_0, *process_1;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_Synchro";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
	STRG_LOC_CONST(aStrText_0[]) = "Process_Synchro.                          (c) EFr-2026";
	STRG_LOC_CONST(aStrText_1[]) = "Process user 1.                           (c) EFr-2026";

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
		KKERN_PRIORITY_HIGH_02				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		1,									// Index
		specification_1,					// Specifications (just use specification_x)
		aStrText_1,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_1,							// Code of the process
		aStrIden_1,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, nullptr, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, nullptr, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
