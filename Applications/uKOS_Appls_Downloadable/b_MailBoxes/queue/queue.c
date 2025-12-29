/*
; queue.
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
 * \ingroup app_mbox
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 2 processes:
 *
 *			- P0: Create a mailbox "Queue 1-to-0"
 *				  Read and display the messages coming from the queue
 *				  Toggle LED 0
 *
 *			- P1: Get the mailbox "Queue 1-to-0" handle
 *				  Every 10-ms
 *					- Write a message into the queue queue 1-to-0
 *
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"queue        Example of how to use queue.              (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  queue\n"
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
 * - P0: Create a mailbox "Queue 1-to-0"
 *		 Read and display the messages coming from the queue
 *			- Toggle LED 0
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {
	uintptr_t	message_1_to_0, expected_1_to_0 = 0u;
	mbox_t		*queue_1_to_0;
	mcnf_t		configure = {
					.oNbMaxPacks = 10u,
					.oDataEntrySize	= 0u
			};

	UNUSED(argument);

	if (kern_createMailbox("Queue 1-to-0", &queue_1_to_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create mbox");	exit(EXIT_OS_FAILURE); }
	if (kern_setMailbox(queue_1_to_0, &configure)         != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Configure mbox"); exit(EXIT_OS_FAILURE); }

	while (true) {

// Receive the message (if FIFO is not empty)
// Display the message

		if (kern_readQueue(queue_1_to_0, &message_1_to_0, 100u) == KERR_KERN_TIMEO) {
			LOG(KFATAL_USER, "Timeout read mbox");
			exit(EXIT_OS_FAILURE);
		}

		if (message_1_to_0 != expected_1_to_0) {
			LOG(KFATAL_USER, "Data lost!!");
			exit(EXIT_OS_FAILURE);
		}

		expected_1_to_0++;
		(void)dprintf(KSYST, "Message = %"PRIu32"\n", (uint32_t)message_1_to_0);
		led_toggle(KLED_0);
	}
}

/*
 * \brief aProcess 1
 *
 * - P1: Get the mailbox "Queue 1-to-0" handle
 *		 Every 10-ms
 *			- Write a message into the queue queue 1-to-0
 *
 */
static void __attribute__ ((noreturn)) aProcess_1(const void *argument) {
	uintptr_t	message_1_to_0 = 0;
	mbox_t		*queue_1_to_0;

	UNUSED(argument);

// Waiting for the queue 1-to-0

	while (kern_getMailboxById("Queue 1-to-0", &queue_1_to_0) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }

	while (true) {
		kern_suspendProcess(10u);

// Send a the message (if FIFO is not full)

		if (kern_writeQueue(queue_1_to_0, message_1_to_0, 100u) == KERR_KERN_TIMEO) {
			LOG(KFATAL_USER, "mbox full");
			exit(EXIT_OS_FAILURE);
		}

		message_1_to_0++;
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
	proc_t	*process_0, *process_1;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2025";
	STRG_LOC_CONST(aStrText_1[]) = "Process user 1.                           (c) EFr-2025";

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
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, NULL, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, NULL, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
