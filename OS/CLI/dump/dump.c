/*
; dump.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		This tool allows to dump a memory area.
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

STRG_LOC_CONST(aStrApplication[]) =	"dump         Dump a memory area.                       (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Dump a memory area\n"
									"==================\n\n"

									"This tool displays a memory area. The result\n"
									"is displayed in hexadecimal format.\n"
									"The memory space is accessed in user mode;\n"
									"to avoid privilege violations, -S should be used.\n\n"

									"Input format:  dump [-S] {hex_startAdd hex_endAdd}\n"
									"Output format: add  hexadecimal field\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	void		local_printLine(const uint8_t *memory, uint32_t nbBytes);

MODULE(
	Dump,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_DUMP,									// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

#define	KLN_ASCII_BUF	96u

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
			char_t		*dummy;
			uint32_t	nbBytes;
			int32_t		status;
			uintptr_t	startAdd, endAdd;
			bool		error = false, equals;
	const	uint8_t		*firstAdd;

	(void)dprintf(KSYST, "Memory dump.\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// dump A0001234 A0011234
// dump -S A0001234 A0011234

	if ((argc < 3u) || (argc > 4u)) {
		error = true;
	}
	else {
		if (argc == 3u) {

// User access

			startAdd = (uintptr_t)strtoul(argv[1], &dummy, 16u);
			endAdd	 = (uintptr_t)strtoul(argv[2], &dummy, 16u);

			if (endAdd < startAdd) {
				endAdd += startAdd;
			}
			nbBytes  = (uint32_t)(endAdd - startAdd);
			firstAdd = (uint8_t *)startAdd;
			local_printLine(firstAdd, nbBytes);
		}
		else {
			text_checkAsciiBuffer(argv[1], "-S", &equals);
			if (equals == true) {

// Privileged access

				PRIVILEGE_ELEVATE;

				startAdd = (uintptr_t)strtoul(argv[2], &dummy, 16u);
				endAdd	 = (uintptr_t)strtoul(argv[3], &dummy, 16u);

				if (endAdd < startAdd) {
					endAdd += startAdd;
				}
				nbBytes  = (uint32_t)(endAdd - startAdd);
				firstAdd = (uint8_t *)startAdd;
				local_printLine(firstAdd, nbBytes);

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

// Local routines
// ==============

/*
 * \brief local_printLine
 *
 * - Print a 16-bytes line
 * - 0x12345678: 00 33 34 02 03 04 05 06 07 34 41 BB 62 DD EE FF .34......4A.b...
 *
 */
static	void	local_printLine(const uint8_t *memory, uint32_t nbBytes) {
			uint8_t		j;
			uint32_t	i;
			size_t		offset;
			char_t		ascii[(8u * 2u) + 1u], element;
	const	uint8_t		*param;

	for (i = 0u; i < ((nbBytes + 16u) / 16u); i++) {
		offset = (size_t)i * (size_t)16u;
		param  = (const uint8_t *)(memory + offset);

		(void)dprintf(KSYST, "0x%016X: ", (uintptr_t)param);
		for (j = 0u; j < 15u; j++) {
			(void)dprintf(KSYST, "%02X,",  *(memory + ((size_t)i * (size_t)16u) + (size_t)j));
		}
			(void)dprintf(KSYST, "%02X  ", *(memory + ((size_t)i * (size_t)16u) + (size_t)15u));

// The ASCII part of the line

		for (j = 0u; j < 16u; j++) {
			element = (char_t)*(memory + ((size_t)i * (size_t)16u) + (size_t)j);
			if ((*(memory + ((size_t)i * (size_t)16u) + (size_t)j) < ' ') || (*(memory + ((size_t)i * (size_t)16u) + (size_t)j) > 0x7Fu)) {
				element = '.';
			}
			ascii[j] = element;
		}
		ascii[16] = '\0';
		(void)dprintf(KSYST, "%s\n", ascii);
	}
}
