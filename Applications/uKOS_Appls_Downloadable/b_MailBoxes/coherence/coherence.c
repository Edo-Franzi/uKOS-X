/*
; coherence.
; ==========

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
 *			Launch 2 processes:
 *
 *			- P0: Create a mailbox "Mailbox_test"
 *				  Every 10-ms
 *					- Write a new message into the mailbox "Mailbox_test"
 *
 *			- P1: Get the mailbox "Mailbox_test" handle
 *				  Every 10-ms
 *					- Read from the mailbox "Mailbox_test"
 *					- Test the coherence
 *
 */

#include	"uKOS.h"
#include	"kern/private/private_mailboxes.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"coherence    Example of how to use mailboxes.          (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  coherence\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#if (defined(ROMABLE_S))

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Coherence,							// Module name (the first letter has to be upper case)
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

#define	KNB_MESSAGES	10u					// Number of usable messages
#define	KSZ_MAILBOX		(KNB_MESSAGES - 1u)	// Size of the mailbox (!!! has to be smaller than the number of available messages !!)
#define	KSZ_MESSAGE		20u					// Size of each message

typedef	struct	msg		msg_t;

struct	msg {
		uint32_t	oMessage[KSZ_MESSAGE];
		char_t		oCharMessage;
};

/*
 * \brief aProcess 0
 *
 * - P0: Create a mailbox "Mailbox_test"
 *		 Every 10-ms
 *			- Write a new message into the mailbox "Mailbox_test"
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {
			char_t		charMessage = ' ';
			uint32_t	i = 0u, j, k = 0u;
			mcnf_t		configure;
			mbox_t		*mailBox;
	static	msg_t		sndMessages[KNB_MESSAGES];

	UNUSED(argument);

// Create and configure the "Mailbox_test"

	configure.oNbMaxPacks	 = KSZ_MAILBOX;
	configure.oDataEntrySize = 0u;

	if (kern_createMailbox("Mailbox_test", &mailBox) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create mbox");	   exit(EXIT_OS_FAILURE); }
	if (kern_setMailbox(mailBox, &configure)         != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Configure mbox"); exit(EXIT_OS_FAILURE); }

	while (true) {
		kern_suspendProcess(10u);

// Prepare the message

		for (j = 0; j < KSZ_MESSAGE; j++) {
			sndMessages[i].oMessage[j] = k++;
		}
		sndMessages[i].oCharMessage = charMessage;

// Send a pack

		if (kern_writeMailbox(mailBox, &sndMessages[i], sizeof(msg_t), KWAIT_INFINITY) == KERR_KERN_TIMEO) {
			LOG(KFATAL_USER, "mbox full");
			exit(EXIT_OS_FAILURE);
		}

// Prepare for the next pack

		i = (i < (KNB_MESSAGES - 1u)) ? (i + 1u) : (0u);
		charMessage = (charMessage < '~') ? (charMessage + 1u) : (' ');
	}
}

/*
 * \brief aProcess 1
 *
 * - P1: Get the mailbox "Mailbox_test" handle
 *		 Every 50-ms
 *			- Read from the mailbox "Mailbox_test"
 *			- Test the coherence
 *
 */
static void __attribute__ ((noreturn)) aProcess_1(const void *argument) {
			uint64_t	time[2];
			uint32_t	i = 0u, j, k = 0u, size;
			mbox_t		*mailBox;
			msg_t		*recMessages;
	static	msg_t		lastMessage;

	UNUSED(argument);

// Waiting for the "Mailbox 1 to 0"

	while (kern_getMailboxById("Mailbox_test", &mailBox) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }

	while (true) {
		kern_suspendProcess(50u);

// Read the pack
//
// IMPORTANT
// Copy the content of the message into the local buffer under ioff
// This because the "kern_readMailbox" release the message in the fifo

		kern_criticalSection(KENTER_CRITICAL);
		kern_readTickCount(&time[0]);
		if (kern_readMailbox(mailBox, (void **)&recMessages, &size, KWAIT_INFINITY) == KERR_KERN_TIMEO) {

			kern_criticalSection(KEXIT_CRITICAL);
			LOG(KFATAL_USER, "Read mbox");
			exit(EXIT_OS_FAILURE);
		}

		PRIVILEGE_ELEVATE;
		time[1] = mailBox->oRead->oWriteTimeStmp;
		PRIVILEGE_RESTORE;

		for (j = 0u; j < KSZ_MESSAGE; j++) { lastMessage.oMessage[j] = recMessages->oMessage[j]; }
		lastMessage.oCharMessage = recMessages->oCharMessage;
		kern_criticalSection(KEXIT_CRITICAL);

		(void)dprintf(KSYST, "Message Read: %"PRId64", Message Written: %"PRId64", Delta: %"PRId64"\n", time[0], time[1], (time[0] - time[1]));

// Display
// Test the coherence
// Prepare for the next pack

		(void)dprintf(KSYST, "Message rec:  %c --> ", lastMessage.oCharMessage);
		for (j = 0u; j < KSZ_MESSAGE; j++) {
			(void)dprintf(KSYST, "%"PRIu32" ", lastMessage.oMessage[j]);
		}
		(void)dprintf(KSYST, "\n\n");

		for (j = 0u; j < KSZ_MESSAGE; j++) {
			if (lastMessage.oMessage[j] != k++) {
				LOG(KFATAL_USER, "Coherency problem!!");
				exit(EXIT_OS_FAILURE);
			}

		}
		i = (i < (KNB_MESSAGES - 1u)) ? (i + 1u) : (0u);
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

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2026";
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

	if (kern_createProcess(&specification_0, nullptr, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, nullptr, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
