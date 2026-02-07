/*
; startUp.
; ========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		startUp process; execute some important initializations
;			before jumping to the selected function.
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

STRG_LOC_CONST(aStrApplication[]) =	"startUp      StartUp process of the system.            (c) EFr-2026";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	void		local_process(const void *argument);
extern	void		stub_startUp_launch(void);

extern	VAR_DECLARED_ALIGN(const char_t aStartUp_StrHelp[], 4);
#define	aStrHelp	aStartUp_StrHelp

// This process has to run on the following cores:

#define	KEXECUTION_CORE		((1u<<BCORE_1) | (1u<<BCORE_0))

MODULE(
	StartUp,						// Module name (the first letter has to be upper case)
	KID_FAM_PROCESSES,				// Family (defined in the module.h)
	KNUM_STARTUP,					// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	prgm,							// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	KEXECUTION_CORE					// Execution cores
);

// Process specific
// ================

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Process_startUp";
STRG_LOC_CONST(aStrText[]) = "Process startUp: start of the system.     (c) EFr-2026";

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
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process,						// Code of the process
		aStrIden,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KFATAL_SYSTEM, "startup: reate proc"); exit(EXIT_OS_PANIC); }

	LOG(KINFO_SYSTEM, "startup: process start-up launched");
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - Start-up of the system
 *
 */
static void __attribute__ ((noreturn)) local_process(const void *argument) {

	UNUSED(argument);

	stub_startUp_launch();
	exit(EXIT_OS_SUCCESS);
}
