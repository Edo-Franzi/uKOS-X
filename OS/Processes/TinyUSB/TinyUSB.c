/*
; TinyUSB.
; ========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		"TinyUSB" management.
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

#define	KTINYUSB_MUTEX_API		"Protect_TinyUSB_API"

// Save the GCC diagnostic
//
#pragma GCC diagnostic	push

// Ignore the GCC diagnostic
//
#pragma GCC diagnostic	ignored	"-Wpedantic"

// cppcheck-suppress missingInclude
//
#include	"tusb.h"

// Restore the GCC diagnostic
//
#pragma GCC	diagnostic	pop

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"TinyUSB      TinyUSB process: management of the USB.   (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "TinyUSB process\n"
									"===============\n\n"

									"TinyUSB management\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";


// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	void		local_process(const void *argument);
extern	void		stub_TinyUSB_init(void);
extern	void		stub_TinyUSB_cyclic(void);

// This process has to run on the following cores:

#define	KEXECUTION_CORE		(1u<<BCORE_0)

MODULE(
	TinyUSB,						// Module name (the first letter has to be upper case)
	KID_FAM_PROCESSES,				// Family (defined in the module.h)
	KNUM_TUSB,						// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	prgm,							// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	KEXECUTION_CORE					// Execution cores
);

mutx_t	*vTinyUSB_API[KNB_CORES];

// Process specific
// ================

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Process_tinyusb";
STRG_LOC_CONST(aStrText[]) = "Process TinyUSB: USB management.          (c) EFr-2026";

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	proc_t	*process;

	UNUSED(argc);
	UNUSED(argv);

	PROCESS_STACKMALLOC(
		0,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_LL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process,						// Code of the process
		aStrIden,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "TinyUSB: create proc"); exit(EXIT_OS_PANIC); }

	LOG(KINFO_SYSTEM, "TinyUSB: process TinyUSB launched");
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - Management of the TinyUSB library
 *
 */
static void __attribute__ ((noreturn)) local_process(const void *argument) {
	uint32_t	core;

	UNUSED(argument);

// Initialise the device stack on configured roothub port

	core = GET_RUNNING_CORE;
	if (kern_createMutex(KTINYUSB_MUTEX_API, &vTinyUSB_API[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "cdc0: create mutx"); exit(EXIT_OS_PANIC); }

	PRIVILEGE_ELEVATE;

	stub_TinyUSB_init();

	while (true) {

// With uKOS, we do not need to have any kern_suspendProcess in the loop
//
// This because tud_task() could be suspended if no data is available
// in the OSAL mailbos queue. The process is suspended as long as the mailbox is empty
// and it will be reactivated by the USB interruptions responsible to fill
// the mailbox

		stub_TinyUSB_cyclic();
	}
}

// Device callbacks
// ================

/*
 * \brief tud_mount_cb
 *
 * - Called when device is mounted
 *
 */
void	tud_mount_cb(void) {

	LOG(KINFO_SYSTEM, "TinyUSB: mounted");
}

/*
 * \brief tud_umount_cb
 *
 * - Called when device is unmounted
 *
 */
void	tud_umount_cb(void) {

	LOG(KINFO_SYSTEM, "TinyUSB: unmounted");
}

/*
 * \brief tud_suspend_cb
 *
 * - Called when usb bus is suspended
 *
 */
void	tud_suspend_cb(bool remote_wakeup_en) {

	UNUSED(remote_wakeup_en);

	LOG(KINFO_SYSTEM, "TinyUSB: suspended");
}

/*
 * \brief tud_resume_cb
 *
 * - Called when usb bus is resumed
 *
 */
void	tud_resume_cb(void) {

	LOG(KINFO_SYSTEM, "TinyUSB: resumed");
}
