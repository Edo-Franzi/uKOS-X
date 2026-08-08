/*
; test_mcore.
; ===========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the multi-core communications layer ASMP.
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

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"test_mcore   Test of the multi-core communications.    (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Test of the multi-core communications\n"
									"=====================================\n\n"

									"This tool launch the communications between the core 0-1 & core 1-0.\n\n"

									"Input format:  test_mcore\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	int32_t		test_mcore_clean(uint32_t argc, const char_t *argv[]);

MODULE(
	Test_mcore,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_TEST_MCORE,							// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	test_mcore_clean,							// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

#define	KTIME_SEND_1MS	1u						// Send every 1-ms
#define	KSZ_MESSAGE		256u					// For this App consider a max of 256 chars
#define	KLED_TX			KLED_0					// TX led
#define	KLED_RX			KLED_1					// RX led

// -------------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden_TX[])  = "Process_Send_Mcore";
STRG_LOC_CONST(aStrText_TX[])  = "Process Send Mcore.                       (c) EFr-2026";
STRG_LOC_CONST(aStrIden_RX[])  = "Process_Receive_Mcore";
STRG_LOC_CONST(aStrText_RX[])  = "Process Receive Mcore.                    (c) EFr-2026";

STRG_LOC_CONST(message_0to1[]) = "The old dreams were good dreams. They didn't work out, but I'm glad I had them.";
STRG_LOC_CONST(message_1to0[]) = "The quick brown fox jumps over the lazy dog.";

static	bool	vKillRequest[KNB_CORES] = MCSET(false);

// Prototypes

static	void	local_process_RX(const void *argument);
static	void	local_process_TX(const void *argument);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	uint32_t	core;
	proc_t		*process_RX, *process_TX;

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;
	vKillRequest[core] = false;

	(void)dprintf(KSYST, "Test of the mcore multi-core communication layer.\n");

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_RX,					// Specifications (just use specification_x)
		aStrText_RX,						// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process_RX,					// Code of the process
		aStrIden_RX,						// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		1,									// Index
		specification_TX,					// Specifications (just use specification_x)
		aStrText_TX,						// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process_TX,					// Code of the process
		aStrIden_TX,						// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_TX, &vKillRequest[core], &process_TX) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "test_mcore: create proc"); exit(EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_RX, &vKillRequest[core], &process_RX) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "test_mcore: create proc"); exit(EXIT_OS_FAILURE); }
	return (EXIT_OS_SUCCESS_CLI);
}

/*
 * \brief test_mcore_clean
 *
 * - Try to clean the ressources
 *		- Free all the ressources
 *
 */
static	int32_t	test_mcore_clean(uint32_t argc, const char_t *argv[]) {
	uint32_t	core;

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;
	vKillRequest[core] = true;

	return (EXIT_OS_SUCCESS);
}

// Local routines
// ==============

/*
 * \brief local_process_TX
 *
 * - Send data to the core X
 *
 */
[[noreturn]]
static	void	local_process_TX(const void *argument) {
			uint32_t	core;
			uint8_t		*send = nullptr, counter = (uint8_t)'a';
			size_t		size;
			int32_t		status;
			mbox_t		*mailBox;
	const	bool		*killRequest;
	const	char_t		*idSendMbox;
	const	char_t		*message;

	killRequest	= (const bool *)argument;

	asmp_getRunningCore(&core);

	message	   = (core == KASMP_CORE_0) ? (&message_0to1[0])		  : (&message_1to0[0]);
	idSendMbox = (core == KASMP_CORE_0) ? (KASMP_MBOX_SEND_TO_CORE_1) : (KASMP_MBOX_SEND_TO_CORE_0);

// Waiting for the creation of the mailbax "send to core x"

	while (kern_getMailboxById(idSendMbox, &mailBox) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }

	while (*killRequest == false) {

// Length of the message + the appended counter
// Prepare the sending buffer (+1 ' ', +1 counter, +1 \0) (strlen skip the \0)

		size = strlen(message) + 3;
		send = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (uint32_t)(size * sizeof(uint8_t)), "send");
		if (send == nullptr) {
			LOG(KFATAL_SYSTEM, "test_mcore: out of memory");
			exit(EXIT_OS_FAILURE);
		}

		memcpy(&send[0], &message[0], (size - 3u));

		send[size - 3u] = (uint8_t)' ';
		send[size - 2u] = counter;
		send[size - 1u] = (uint8_t)'\0';

// Try to send a the message (place the message into the mailbox))

		status = kern_writeMailbox(mailBox, send, (uint32_t)size, 1000u);

		switch (status) {
			case KERR_KERN_TIMEO: {
				(void)dprintf(KSYST, "Timeout write mailbox\n");
				break;
			}
			case KERR_KERN_NOERR: {
				counter++;
				counter = (counter > (uint8_t)'z') ? ((uint8_t)'a') : (counter);

				led_toggle(KLED_TX);
				break;
			}
			default: {
				LOG(KFATAL_SYSTEM, "test_mcore: write MBox");
				exit(EXIT_OS_FAILURE);
			}
		}
	}

// Kill the process & the ressources

	INTERRUPTION_OFF;
	memo_free(send);
	led_off(KLED_TX);

	exit(EXIT_OS_SUCCESS);
}

/*
 * \brief local_process_RX
 *
 * - Read the data coming from the core X
 *
 */
[[noreturn]]
static	void	local_process_RX(const void *argument) {
			uint32_t	core, size;
			uint8_t		*receive, *message;
			int32_t		status;
			mbox_t		*mailBox;
	const	bool		*killRequest;
	const	char_t		*idReceiveMbox;

	killRequest	= (const bool *)argument;

	asmp_getRunningCore(&core);

	idReceiveMbox = (core == KASMP_CORE_0) ? (KASMP_MBOX_RECEIVE_FROM_CORE_1) : (KASMP_MBOX_RECEIVE_FROM_CORE_0);

// Waiting for the creation of the mailbax "receive from core x"

	while (kern_getMailboxById(idReceiveMbox, &mailBox) != KERR_KERN_NOERR) { kern_suspendProcess(1u); }

	message = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (KSZ_MESSAGE * sizeof(uint8_t)), "receive");
	if (message == nullptr) {
		LOG(KFATAL_SYSTEM, "test_mcore: out of memory");
		exit(EXIT_OS_FAILURE);
	}

	while (*killRequest == false) {

// Try to receive a the message (located in the mailbox))

		status = kern_readMailbox(mailBox, (void **)&receive, &size, 1000u);

		switch (status) {
			case KERR_KERN_TIMEO: {
				(void)dprintf(KSYST, "Timeout read mailbox\n");
				break;
			}
			case KERR_KERN_NOERR: {
				memcpy(message, receive, size);
				if (KASMP_MBOX_ENTRY_SIZE == 0u) { memo_free(receive); }

				(void)dprintf(KSYST, "Received: %s\n", message);
				led_toggle(KLED_RX);
				break;
			}
			default: {
				LOG(KFATAL_SYSTEM, "test_mcore: read MBox");
				exit(EXIT_OS_FAILURE);
			}
		}
	}

// Kill the process & the ressources

	INTERRUPTION_OFF;
	memo_free(message);
	led_off(KLED_RX);

	exit(EXIT_OS_SUCCESS);
}
