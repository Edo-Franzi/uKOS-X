/*
; bench.
; ======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		System benches.
;
;			Launch 1 processes:
;
;			- P0: bench performance
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

STRG_LOC_CONST(aStrApplication[]) =	"bench        CPU core performance benches.             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "The CPU cores benches\n"
									"=====================\n\n"

									"This tool performs some benches to figure-out the real\n"
									"CPU performances\n\n"

									"Input format:  bench\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
extern	bool		bench_00(void);
extern	bool		bench_01(void);
extern	bool		bench_02(void);
extern	bool		bench_03(void);
extern	bool		bench_04(void);
extern	bool		bench_05(void);

MODULE(
	Bench,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_BENCH,									// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	priority_t	priority;
	proc_t		*process;

	UNUSED(argc);
	UNUSED(argv);

	PRIVILEGE_ELEVATE;

	(void)dprintf(KSYST, "System bench.\n");

// Save the priority & make the process realtime

	kern_getProcessRun(&process);
	kern_getPriority(process, &priority);
	kern_setPriority(process, KKERN_PRIORITY_HIGH_01);

	if (bench_00() == false) { (void)dprintf(KSYST, "Not enough memory.\n"); return (EXIT_OS_FAILURE); }
	if (bench_01() == false) { (void)dprintf(KSYST, "Not enough memory.\n"); return (EXIT_OS_FAILURE); }
	if (bench_02() == false) { (void)dprintf(KSYST, "Not enough memory.\n"); return (EXIT_OS_FAILURE); }
	if (bench_03() == false) { (void)dprintf(KSYST, "Not enough memory.\n"); return (EXIT_OS_FAILURE); }
	if (bench_04() == false) { (void)dprintf(KSYST, "Not enough memory.\n"); return (EXIT_OS_FAILURE); }
	if (bench_05() == false) { (void)dprintf(KSYST, "Not enough memory.\n"); return (EXIT_OS_FAILURE); }

	kern_setPriority(process, priority);
	return (EXIT_OS_SUCCESS_CLI);
}
