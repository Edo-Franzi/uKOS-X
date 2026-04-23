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
 * \ingroup app_psig
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 2 processes:
 *
 *			- P0: Every 500-ms
 *  				- Print the state machine timings
 *
 *			- P1: Create the precise signal "My_State_Machine"
 *				  Initialise a state machine (single shot triggers every xxx-us)
 *       			- Waiting for the synchros
 *       			- Manage the state machine
 *
 *					state        1    2          3        4    1
 *					            +----+          +--------+
 *					       		|    |          |        |
 *					       	----+    +----------+        +----+
 *					              T1      T2        T3      T4
 *					              550-us  2830-us   2510-us 320-us
 *
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"basic        test of a process with a state machine.   (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  basic\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#if (defined(ROMABLE_S))

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Basic,								// Module name (the first letter has to be upper case)
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

static	uint64_t	vTime[4];
static	uint32_t	vDelta[4];
static	proc_t		*vProcess_0, *vProcess_1;

static	enum		{ KSTATE1, KSTATE2, KSTATE3, KSTATE4 } vState = KSTATE1;

#define	KSYNC_STATE_MACHINE		(1u<<0u)	// Synchro for the state machine (P1)
#define	KSYNC_CONTINUOUS		(1u<<1u)	// Synchro for the continuous (P2)

/*
 * \brief aProcess_0
 *
 * - P0: Every 500-ms
 *			- Print the "state machine" timings
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(500u);
		(void)dprintf(KSYST,"T1 = %"PRIu32", T2 = %"PRIu32", T3 = %"PRIu32", T4 = %"PRIu32"\n",
							vDelta[0],
							vDelta[1],
							vDelta[2],
							vDelta[3]);
	}
}

/*
 * \brief aProcess_1
 *
 * - P1: Create the precise signal "My_State_Machine"
 *		 Initialise a state machine (single shot triggers every xxx-us)
 *		 Waiting for the synchros
 *			- Manage the state machine
 *
 * state		1    2          3        4    1
 *				+----+          +--------+
 *				|    |          |        |
 *			----+    +----------+        +----+
 *				T1      T2        T3      T4
 *				550-us  2830-us   2510-us 320-us
 *
 */
static void __attribute__ ((noreturn)) aProcess_1(const void *argument) {
	uint32_t	signal;
	prcs_t		*preciseSignal;
	sign_t		*sigGroup = nullptr;

	UNUSED(argument);

	if (kern_createPreciseSignal("My_State_Machine", &preciseSignal) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create prcs"); exit(EXIT_OS_FAILURE); }

	kern_setPreciseSignal(preciseSignal, &sigGroup, vProcess_1, 320u, KPRCS_SINGLE_SHOT, KSYNC_STATE_MACHINE);

	while (true) {
		switch (vState) {

// State 1 --> State 2

			case KSTATE1: {
				signal = KSYNC_STATE_MACHINE;
				kern_waitSignal(sigGroup, &signal, KKERN_HANDLE_FROM_ISR, KWAIT_INFINITY);

				kern_setPreciseSignal(preciseSignal, &sigGroup, vProcess_1, 550u, KPRCS_SINGLE_SHOT, KSYNC_STATE_MACHINE);
				kern_readTickCount(&vTime[0]);
				vDelta[3] = (uint32_t)(vTime[0] - vTime[3]);
				vState = KSTATE2;
				break;
			}

// State 2 --> State 3

			case KSTATE2: {
				signal = KSYNC_STATE_MACHINE;
				kern_waitSignal(sigGroup, &signal, KKERN_HANDLE_FROM_ISR, KWAIT_INFINITY);

				kern_setPreciseSignal(preciseSignal, &sigGroup, vProcess_1, 2830u, KPRCS_SINGLE_SHOT, KSYNC_STATE_MACHINE);
				kern_readTickCount(&vTime[1]);
				vDelta[0] = (uint32_t)(vTime[1] - vTime[0]);
				vState = KSTATE3;
				break;
			}

// State 3 --> State 4

			case KSTATE3: {
				signal = KSYNC_STATE_MACHINE;
				kern_waitSignal(sigGroup, &signal, KKERN_HANDLE_FROM_ISR, KWAIT_INFINITY);

				kern_setPreciseSignal(preciseSignal, &sigGroup, vProcess_1, 2510u, KPRCS_SINGLE_SHOT, KSYNC_STATE_MACHINE);
				kern_readTickCount(&vTime[2]);
				vDelta[1] = (uint32_t)(vTime[2] - vTime[1]);
				vState = KSTATE4;
				break;
			}

// State 4 --> State 1

			case KSTATE4: {
				signal = KSYNC_STATE_MACHINE;
				kern_waitSignal(sigGroup, &signal, KKERN_HANDLE_FROM_ISR, KWAIT_INFINITY);

				kern_setPreciseSignal(preciseSignal, &sigGroup, vProcess_1, 320u, KPRCS_SINGLE_SHOT, KSYNC_STATE_MACHINE);
				kern_readTickCount(&vTime[3]);
				vDelta[2] = (uint32_t)(vTime[3] - vTime[2]);
				vState = KSTATE1;
				break;
			}
			default: {

// Make MISRA happy :-)

				break;
			}
		}
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

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2026";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
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
		KKERN_PRIORITY_MEDIUM_02			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		1,									// Index
		specification_1,					// Specifications (just use specification_x)
		aStrText_1,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_1,							// Code of the process
		aStrIden_1,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_02			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, nullptr, &vProcess_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, nullptr, &vProcess_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
