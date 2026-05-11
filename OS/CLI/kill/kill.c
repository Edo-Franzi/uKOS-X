/*
; kill.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Kill a module (process or other).
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

STRG_LOC_CONST(aStrApplication[]) =	"kill         Kill a module.                            (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Kill a module\n"
									"=============\n\n"

									"This tool kills a module.\n\n"

									"Input format:  kill {module_name}\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Kill,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_KILL,									// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
			int32_t			status;
			uint16_t		index = 0u;
			enum { KERR_NOT, KERR_PRO, KERR_PNK, KERR_PNE } error = KERR_NOT;
	const	uKOS_module_t	*module;

	(void)dprintf(KSYST, "kill a module.\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// kill alive

	if (argc != 2u) {
		error = KERR_PRO;
	}
	else {
		if (system_getModuleName(argv[1], &index, &module) == KERR_SYSTEM_NOERR) {
			if (module->oClean != nullptr) {
				module->oClean(0u, nullptr);
			}
			else {
				error = KERR_PNK;
			}
		}
		else {
			error = KERR_PNE;
		}
	}

	switch (error) {
		case KERR_NOT: { (void)dprintf(KSYST, "Module %s killed\n\n", argv[1]);	   status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_PNE: { (void)dprintf(KSYST, "The module does not exist.\n\n");   status = EXIT_OS_FAILURE;     break; }
		case KERR_PNK: { (void)dprintf(KSYST, "The module cannot be killed.\n\n"); status = EXIT_OS_FAILURE;     break; }
		case KERR_PRO: { (void)dprintf(KSYST, "Protocol error.\n\n");			   status = EXIT_OS_FAILURE;     break; }
		default:	   {														   status = EXIT_OS_FAILURE;     break; }
	}
	return (status);
}
