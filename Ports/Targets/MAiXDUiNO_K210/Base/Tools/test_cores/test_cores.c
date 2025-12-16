/*
; test_cores.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Some core tests.
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

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"test_cores   Some core tests.                          (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "Test of the cores\n"
									"=================\n\n"

									"This tool performs some core tests.\n\n"

									"Input format:  test_core\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Test_cores,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	(((uint32_t)'_'<<8u)+(uint32_t)'C'),		// Module identifier (defined in the module.h)
	NULL,										// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,										// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

extern	volatile	uint8_t		vVector[];
extern				spinlock_t	vLockVector;

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
			uint32_t	core;
			uint8_t		i, first;
	static	bool		vError[KNB_CORES] = MCSET(false);

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;
	(void)dprintf(KSYST, "Core tests.\n");

// If the vector coherence verification failed, then, stop printing

	if (vError[core] == true) { return (EXIT_OS_SUCCESS_CLI); }

// Print the vector

	(void)dprintf(KSYST, "Size = %"PRIu8", core = %"PRIu8", Vector = ", vVector[0], vVector[1]);

	SPIN_LOCK(vLockVector);
	for (i = 2u; i < vVector[0]; i++) {
		(void)dprintf(KSYST, "%"PRIu8" ", vVector[i]);
	}

// Verify the vector coherence

	first = vVector[2];
	for (i = 2u; i < vVector[0]; i++) {
		if (first++ != vVector[i]) {
			(void)dprintf(KSYST, "Problem\n");
			vError[core] = true;
		}
	}
	SPIN_UNLOCK(vLockVector);

	(void)dprintf(KSYST, "\n");
	return (EXIT_OS_SUCCESS_CLI);
}
