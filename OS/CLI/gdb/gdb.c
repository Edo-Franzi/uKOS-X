/*
; gdb.
; ====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Freeze the µKernel for gdb.
;			- Freeze the uKernel in order to support gdb sessions
;			- The gdb loaded application has to start with SET_INTERRUPTION
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

STRG_LOC_CONST(aStrApplication[]) =	"gdb          Support a gdb session.                    (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "gdb\n"
									"===\n\n"

									"This tool freezes the uKernel in order to support gdb sessions\n\n"

									"Input format:  gdb\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Gdb,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_GDB,									// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_STATI(vStrText[]) = "GDB process.                              (c) EFr-2026";
STRG_LOC_STATI(vStrIden[]) = "GDB_process";

// Prototypes

static	void	local_process(const void *argument);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	proc_t	*process;

	UNUSED(argc);
	UNUSED(argv);

	(void)dprintf(KSYST, "Freeze the uKernel.\n");

	PROCESS_STACKMALLOC(
		0,									// Index
		specification,						// Specifications (just use specification_x)
		vStrText,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_LL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process,						// Code of the process
		vStrIden,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_NORMAL_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	kern_suspendProcess(1000u);
	kern_createProcess(&specification, nullptr, &process);
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - Freeze the µKernel for gdb
 *
 */
[[noreturn]]
static	void	local_process(const void *argument) {

	UNUSED(argument);

	(void)dprintf(KSYST, "\n\nOn the host open 2 terminal tabs:\n"
				   "(example for cortex based cpus)\n\n"
				   "- On T1: openocd-cortex -f gdb.cfg\n"
				   "- On T2: arm-none-eabi-gdb myPRGM.elf\n"
				   "- On T2: target extended-remote localhost:3333\n"
				   "- On T2: load\n\n");

	kern_suspendProcess(1000u);

	kern_criticalSection(KENTER_CRITICAL);
	while (true) { ; }
}
