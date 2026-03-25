/*
; mcore.
; ======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		mcore process; multi-core layer via mbox & asmp.
;			For the moment, this layer is limited to 2 cores.
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

STRG_LOC_CONST(aStrApplication[]) =	"mcore        mcore process: manage the multi-core      (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "mcore process\n"
									"=============\n\n"

									"Management of the multi-cores\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// This process has to run on the following cores:

#define	KEXECUTION_CORE		((1u<<BCORE_0) | (1u<<BCORE_1) | (1u<<BCORE_2) | (1u<<BCORE_3))

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Mcore,							// Module name (the first letter has to be upper case)
	KID_FAM_DAEMONS,				// Family (defined in the module.h)
	KNUM_MCORE,						// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	prgm,							// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	KEXECUTION_CORE					// Execution cores
);

// Daemon specific
// ===============

// --------------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden_RecX[]) = "Daemon_rec_from_core_x";
STRG_LOC_CONST(aStrIden_SndX[]) = "Daemon_snd_to_core_x";
STRG_LOC_CONST(aStrText_RecX[]) = "Daemon mcore: receive from core x.        (c) EFr-2026";
STRG_LOC_CONST(aStrText_SndX[]) = "Daemon mcore: send to core x.             (c) EFr-2026";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	void		local_process_SndX(const void *argument);
static	void		local_process_RecX(const void *argument);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	uint32_t	core;
	proc_t		*process_SndX, *process_RecX;

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;

	VAR_DECLARED_ALIGN(static uintptr_t vStack_SndX[KNB_CORES][KKERN_SZ_STACK_XL], KSTACK_ALIGNMENT);
	VAR_DECLARED_ALIGN(static uintptr_t vStack_RecX[KNB_CORES][KKERN_SZ_STACK_XL], KSTACK_ALIGNMENT);

	DAEMON_PRIVILEGED(
		core,								// Core
		specification_SndX,					// Specifications (just use specification_x)
		aStrText_SndX,						// Info string (nullptr if anonymous)
		vStack_SndX,						// Stack location
		KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process_SndX,					// Code of the process
		aStrIden_SndX,						// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	DAEMON_PRIVILEGED(
		core,								// Core
		specification_RecX,					// Specifications (just use specification_x)
		aStrText_RecX,						// Info string (nullptr if anonymous)
		vStack_RecX,						// Stack location
		KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process_RecX,					// Code of the process
		aStrIden_RecX,						// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

// Waiting 10-ms for the ASMP ready to operate

	while (asmp_waitingForReady() != KERR_ASMP_NOERR) { kern_suspendProcess(10); }

	if (kern_createProcess(&specification_SndX, nullptr, &process_SndX) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "mcore: create proc"); exit(EXIT_OS_PANIC); }
	if (kern_createProcess(&specification_RecX, nullptr, &process_RecX) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "mcore: create proc"); exit(EXIT_OS_PANIC); }

	LOG(KINFO_SYSTEM, "mcore: daemon mcore launched");
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_process_SndX
 *
 * - Snd X: - Create a mailbox "To send to core x"
 *				- Read the data coming from the mailbox "To send to core x"
 *				- Release the memory
 *				- Send the data to core x"
 *
 */
static void __attribute__ ((noreturn)) local_process_SndX(const void *argument) {
			uint32_t	core, toCore, size, order = 0u;
			uint8_t		*receive = nullptr, *send = nullptr;
			mbox_t		*mailBox;
			sema_t		*semaphore;
			mcnf_t		configure = {
							.oNbMaxPacks	= KASMP_MBOX_MAX_PACK,
							.oDataEntrySize	= KASMP_MBOX_ENTRY_SIZE
						};
	const	char_t		*idSendMbox;

	UNUSED(argument);

// If the running core is the core 0
//	- The message is for the core 1 via the mailbox 1
//
// If the running core is the core 1
//	- The message is for the core 0 via the mailbox 0

	asmp_getRunningCore(&core);

	toCore	   = (core == KASMP_CORE_0) ? ((uint32_t)KASMP_CORE_1)	  : ((uint32_t)KASMP_CORE_0);
	idSendMbox = (core == KASMP_CORE_0) ? (KASMP_MBOX_SEND_TO_CORE_1) : (KASMP_MBOX_SEND_TO_CORE_0);

	asmp_getSemaphoreTXEmpty(core, &semaphore);

	if (kern_createMailbox(idSendMbox, &mailBox) != KERR_KERN_NOERR) {
		LOG(KFATAL_SYSTEM, "mcore: no MBox");
		exit(EXIT_OS_FAILURE);
	}

	if (kern_setMailbox(mailBox, &configure) != KERR_KERN_NOERR) {
		LOG(KFATAL_SYSTEM, "mcore: configure mbox");
		exit(EXIT_OS_FAILURE);
	}

	send = (uint8_t *)memo_malloc(KMEMO_ALIGN_32, (KASMP_SZ_BUFFER * sizeof(uint8_t)), "send");
	if (send == nullptr) {
		LOG(KFATAL_SYSTEM, "mcore: out of memory");
		exit(EXIT_OS_FAILURE);
	}

// Waiting for the asmp TX empty
// Read a message coming from a user
// Send the message to the core x

	while (true) {
		kern_waitSemaphore(semaphore, KWAIT_INFINITY);

		kern_readMailbox(mailBox, (void **)&receive, &size, KWAIT_INFINITY);
		if (size > KASMP_SZ_BUFFER) {
			LOG(KFATAL_SYSTEM, "mcore: coherency problem!!");
			exit(EXIT_OS_FAILURE);
		}

// Aligne the message size. This to avoid an unaligned hard fault

		memcpy(send, receive, size);

// Release the memory if the allocation is dynamic

		if (KASMP_MBOX_ENTRY_SIZE == 0u) { memo_free(receive); }

		if (asmp_send(toCore, order, size, send) != KERR_ASMP_NOERR) {
			LOG(KFATAL_SYSTEM, "mcore: coherency problem!!");
			exit(EXIT_OS_FAILURE);
		}

	}
}

/*
 * \brief local_process_RecX
 *
 * - Rec X: - Create a mailbox "To receive from core x"
 *				- Read the data from core x"
 *				- Allocate the memory
 *				- Write a message into the mailbox "To receive from core x"
 *
 */
static void __attribute__ ((noreturn)) local_process_RecX(const void *argument) {
			uint32_t	core, fromCore, size, order;
			uint8_t		*receive = nullptr, *send = nullptr;
			mbox_t		*mailBox;
			sema_t		*semaphore;
			mcnf_t		configure = {
							.oNbMaxPacks	= KASMP_MBOX_MAX_PACK,
							.oDataEntrySize	= KASMP_MBOX_ENTRY_SIZE
						};
	const	char_t		*idReceiveMbox;

	UNUSED(argument);

// If the running core is the core 0
//	- The message is coming from the core 1 via the mailbox 1
//
// If the running core is the core 1
//	- The message is coming from the core 0 via the mailbox 0

	asmp_getRunningCore(&core);
	idReceiveMbox = (core == KASMP_CORE_0) ? (KASMP_MBOX_RECEIVE_FROM_CORE_1) : (KASMP_MBOX_RECEIVE_FROM_CORE_0);

	asmp_getSemaphoreRXFull(core, &semaphore);

	if (kern_createMailbox(idReceiveMbox, &mailBox) != KERR_KERN_NOERR) {
		LOG(KFATAL_SYSTEM, "mcore: no MBox");
		exit(EXIT_OS_FAILURE);
	}

	if (kern_setMailbox(mailBox, &configure) != KERR_KERN_NOERR) {
		LOG(KFATAL_SYSTEM, "mcore: configure mbox");
		exit(EXIT_OS_FAILURE);
	}

	receive = (uint8_t *)memo_malloc(KMEMO_ALIGN_32, (KASMP_SZ_BUFFER * sizeof(uint8_t)), "receive");
	if (receive == nullptr) {
		LOG(KFATAL_SYSTEM, "mcore: out of memory");
		exit(EXIT_OS_FAILURE);
	}

// Waiting for the asmp RX full
// Read a message coming from the core x
// Send the message to a user

	while (true) {
		kern_waitSemaphore(semaphore, KWAIT_INFINITY);

		if (asmp_receive(&fromCore, &order, &size, receive) != KERR_ASMP_NOERR) {
			LOG(KFATAL_SYSTEM, "mcore: coherency problem!!");
			exit(EXIT_OS_FAILURE);
		}

		send = (uint8_t *)memo_malloc(KMEMO_ALIGN_32, (size * sizeof(uint8_t)), "send");
		if (send == nullptr) {
			LOG(KFATAL_SYSTEM, "mcore: out of memory");
			exit(EXIT_OS_FAILURE);
		}

// Aligne the message size. This to avoid an unaligned hard fault

		memcpy(send, receive, size);
		kern_writeMailbox(mailBox, send, size, KWAIT_INFINITY);
	}
}
