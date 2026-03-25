/*
; fill.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		This tool allows to fill a memory with a pattern.
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

STRG_LOC_CONST(aStrApplication[]) =	"fill         Fill a memory area with a pattern.        (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Fill a memory area with a pattern\n"
									"=================================\n\n"

									"This tool fills a memory area with a\n"
									"pattern.\n"
									"The memory space is accessed in user mode;\n"
									"to avoid privilege violations, -S should be used.\n\n"

									"Input format:  fill [-S] {hex_startAdd hex_endAdd data}\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Fill,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_FILL,									// Module identifier (defined in the module.h)
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
	char_t		*dummy;
	uint8_t		*firstAdd;
	uint32_t	i, nbBytes;
	int32_t		status, value;
	uintptr_t	startAdd, endAdd;
	bool		error = false, equals;

	(void)dprintf(KSYST, "Memory fill.\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// fill A0001234 A0011234 34
// fill -S A0001234 A0011234 34

	if ((argc < 4u) || (argc > 5u)) {
		error = true;
	}
	else {
		if (argc == 4u) {

// User access

			startAdd = (uintptr_t)strtoul(argv[1], &dummy, 16u);
			endAdd	 = (uintptr_t)strtoul(argv[2], &dummy, 16u);
			value	 = (int32_t)  strtoul(argv[3], &dummy, 16u);

			nbBytes = (uint32_t)(endAdd - startAdd);
			firstAdd = (uint8_t *)startAdd;
			for (i = 0u; i < nbBytes; i++) {
				*firstAdd = (uint8_t)value;
				firstAdd++;
			}
		}
		else {
			text_checkAsciiBuffer(argv[1], "-S", &equals);
			if (equals == true) {

// Privileged access

				PRIVILEGE_ELEVATE;

				startAdd = (uintptr_t)strtoul(argv[2], &dummy, 16u);
				endAdd	 = (uintptr_t)strtoul(argv[3], &dummy, 16u);
				value	 = (int32_t)  strtoul(argv[4], &dummy, 16u);

				nbBytes = (uint32_t)(endAdd - startAdd);
				firstAdd = (uint8_t *)startAdd;
				for (i = 0u; i < nbBytes; i++) {
					*firstAdd = (uint8_t)value;
					firstAdd++;
				}

				PRIVILEGE_RESTORE;
			}
			else {
				error = true;
			}
		}
	}

	if (error == false) { (void)dprintf(KSYST, "\n");				   status = EXIT_OS_SUCCESS_CLI; }
	else				{ (void)dprintf(KSYST, "Protocol error.\n\n"); status = EXIT_OS_FAILURE;     }
	return (status);
}
