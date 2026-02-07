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
 * \ingroup app_mbox
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 4 processes:
 *
 *			- P0: Create a mailbox "Mailbox Receive text"
 *				  Read and display the messages coming from the mailbox
 *				  Release the associated memory buffer
 *				  Toggle LED 1
 *
 *			- P1: Get the mailbox "Mailbox receive text" handle
 *				  Every 100-ms
 *					- Write a message into the mailbox
 *
 *			- P2: Get the mailbox "Mailbox receive text" handle
 *				  Every 200-ms
 *					- Write a message into the mailbox
 *
 *			- P3: Get the mailbox "Mailbox receive text" handle
 *				  Every 200-ms
 *					- Write a message into the mailbox
 *
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"basic        Example of how to use mailboxes.          (c) EFr-2026";
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
	nullptr,							// Address of the initialisation code (early pre-init)
	aStart,								// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,							// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);

/*
 * \brief aProcess 0
 *
 * - P0: - Create a mailbox "Mailbox Receive text"
 *			- Read and display the messages coming from the mailbox
 *			- Release the associated memory buffer
 *			- Toggle LED 1
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {
	uint32_t	sizeRec;
	uint8_t		*bufPtr;
	uint8_t		*bufRec;
	mbox_t		*mailBox;
	mcnf_t		configure = {
					.oNbMaxPacks	= 10u,
					.oDataEntrySize	= 0u
				};

	UNUSED(argument);

	sizeRec = 256u;
	bufPtr  = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (sizeRec * sizeof(uint8_t)), "basic");
	if (bufPtr == nullptr) {
		LOG(KFATAL_USER, "Out of memory");
		exit(EXIT_OS_FAILURE);
	}

	if (kern_createMailbox("Mailbox receive text", &mailBox) != KERR_KERN_NOERR) { (void)dprintf(KSYST, "Create mbox\n");	   LOG(KFATAL_USER, "Create mbox");	 exit(EXIT_OS_FAILURE); }
	if (kern_setMailbox(mailBox, &configure)                 != KERR_KERN_NOERR) { (void)dprintf(KSYST, "Configure mbox\n"); LOG(KFATAL_USER, "Configure mbox"); exit(EXIT_OS_FAILURE); }

	while (true) {

// Receive the message (wait until the FIFO is not empty)

		if (kern_readMailbox(mailBox, (void **)&bufRec, &sizeRec, 1000u) == KERR_KERN_TIMEO) {
			LOG(KFATAL_USER, "Timeout read mbox");
			exit(EXIT_OS_FAILURE);
		}

// Copy it into a local buffer before to "free" the memory

		strcpy((char_t *)bufPtr, (char_t *)bufRec);
		memo_free(bufRec);
		(void)dprintf(KSYST, "Message size = %"PRIu32"; 0x%016"PRIXPTR" message -> %s\n", sizeRec, (uintptr_t)bufRec, bufPtr);
		led_toggle(KLED_1);
	}
}

/*
 * \brief aProcess 1
 *
 * - P1: Get the mailbox "Mailbox receive text" handle
 *		 Every 100-ms
 *			- Write a message into the mailbox
 *
 */
static void __attribute__ ((noreturn)) aProcess_1(const void *argument) {
	size_t		sizeSnd;
	uint8_t		*bufSnd;
	mbox_t		*mailBox;
	STRG_LOC_CONST(message[]) = "P1: The old dreams were good dreams. They didn't work out, but I'm glad I had them.";

	UNUSED(argument);

// Waiting for the creation of the "Mailbox receive status"

	while (kern_getMailboxById("Mailbox receive text", &mailBox) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }

	while (true) {
		kern_suspendProcess(100u);

// Send the message

		sizeSnd = strlen(message);
		bufSnd  = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (uint32_t)((sizeSnd + 1u) * sizeof(uint8_t)), "basic");
		if (bufSnd == nullptr) {
			LOG(KFATAL_USER, "Out of memory");
			exit(EXIT_OS_FAILURE);
		}

		strcpy((char_t *)bufSnd, message);

// Send a the message (wait until the FIFO is not full)

		if (kern_writeMailbox(mailBox, bufSnd, (uint32_t)sizeSnd, 1000u) == KERR_KERN_TIMEO) {
			(void)dprintf(KSYST, "mbox full\n");
			LOG(KFATAL_USER, "mbox full");
			exit(EXIT_OS_FAILURE);
		}

	}
}

/*
 * \brief aProcess 2
 *
 * - P2: Get the mailbox "Mailbox receive text" handle
 *		 Every 200-ms
 *			- Write a message into the mailbox
 *
 */
static void __attribute__ ((noreturn)) aProcess_2(const void *argument) {
	size_t		sizeSnd;
	uint8_t		*bufSnd;
	mbox_t		*mailBox;
	STRG_LOC_CONST(message[]) = "P2: The quick brown fox jumps over the lazy dog.";

	UNUSED(argument);

// Waiting for the creation of the "Mailbox receive status"

	while (kern_getMailboxById("Mailbox receive text", &mailBox) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }

	while (true) {
		kern_suspendProcess(200u);

// Send the message

		sizeSnd = strlen(message);
		bufSnd  = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (uint32_t)((sizeSnd + 1u) * sizeof(uint8_t)), "basic");
		if (bufSnd == nullptr) {
			(void)dprintf(KSYST, "Out of memory %zu\n", sizeSnd);
			LOG(KFATAL_USER, "Out of memory");
			exit(EXIT_OS_FAILURE);
		}

		strcpy((char_t *)bufSnd, message);

// Send a the message (wait until the FIFO is not full)

		while (kern_writeMailbox(mailBox, bufSnd, (uint32_t)sizeSnd, 1000u) == KERR_KERN_TIMEO) {
			(void)dprintf(KSYST, "mbox full\n");
			LOG(KFATAL_USER, "mbox full");
			exit(EXIT_OS_FAILURE);
		}

	}
}

/*
 * \brief aProcess 3
 *
 * - P3: Get the mailbox "Mailbox receive text" handle
 *		 Every 200-ms
 *			- Write a message into the mailbox
 *
 */
static void __attribute__ ((noreturn)) aProcess_3(const void *argument) {
	size_t		sizeSnd;
	uint8_t		*bufSnd;
	mbox_t		*mailBox;
	STRG_LOC_CONST(message[]) = "P3: I didn't know he was dead...I thought he was British. (Woody Allen).";

	UNUSED(argument);

// Waiting for the creation of the "Mailbox receive status"

	while (kern_getMailboxById("Mailbox receive text", &mailBox) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }

	while (true) {
		kern_suspendProcess(200u);

// Send the message

		sizeSnd = strlen(message);
		bufSnd  = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (uint32_t)((sizeSnd + 1u) * sizeof(uint8_t)), "basic");
		if (bufSnd == nullptr) {
			(void)dprintf(KSYST, "Out of memory %zu\n", sizeSnd);
			LOG(KFATAL_USER, "Out of memory");
			exit(EXIT_OS_FAILURE);
		}

		strcpy((char_t *)bufSnd, message);

// Send a the message (wait until the FIFO is not full)

		while (kern_writeMailbox(mailBox, bufSnd, (uint32_t)sizeSnd, 1000u) == KERR_KERN_TIMEO) {
			(void)dprintf(KSYST, "mbox full\n");
			LOG(KFATAL_USER, "mbox full");
			exit(EXIT_OS_FAILURE);
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
int		main(int argc, const char *argv[]) {
	proc_t	*process_0, *process_1, *process_2, *process_3;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
	STRG_LOC_CONST(aStrIden_2[]) = "Process_User_2";
	STRG_LOC_CONST(aStrIden_3[]) = "Process_User_3";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2026";
	STRG_LOC_CONST(aStrText_1[]) = "Process user 1.                           (c) EFr-2026";
	STRG_LOC_CONST(aStrText_2[]) = "Process user 2.                           (c) EFr-2026";
	STRG_LOC_CONST(aStrText_3[]) = "Process user 3.                           (c) EFr-2026";

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
		KKERN_PRIORITY_LOW_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
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

	PROCESS_STACKMALLOC(
		3,									// Index
		specification_3,					// Specifications (just use specification_x)
		aStrText_3,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_3,							// Code of the process
		aStrIden_3,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, nullptr, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, nullptr, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_2, nullptr, &process_2) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_3, nullptr, &process_3) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
