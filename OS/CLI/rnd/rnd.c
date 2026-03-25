/*
; rnd.
; ====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Give a random (eventually pseudo-random) number.
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

STRG_LOC_CONST(aStrApplication[]) =	"rnd          Give a random number.                     (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Give a random number\n"
									"====================\n\n"

									"This tool gives a random (eventually pseudo-random)\n"
									"number.\n\n"

									"Example\n"
									"   rnd                      get 1 number from the software generator\n"
									"   rnd x (x, 1..16)         get x number from the software generator\n"
									"   rnd -soft x (x, 1..16)   get x number from the software generator\n"
									"   rnd -hard x (x, 1..16)   get x number from the hardware generator\n\n"

									"Input format:  rnd {-hard, -soft} [x, x = 1 to 16]\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Rnd,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_RND,									// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

#define	KNB_MAX_NUMBERS		16u					// Considered max numbers

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	bool				equals;
	char_t				*dummy;
	uint32_t			i, randomNumber[KNB_MAX_NUMBERS], nbRandomNumber;
	int32_t				status;
	randomGenerator_t	generator;
	bool				error = false;

	(void)dprintf(KSYST, "Give random number(s).\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// rnd						1 number from the software generator
// rnd x (x, 1..16)			x number from the software generator
// rnd -soft x (x, 1..16)	x number from the software generator
// rnd -hard x (x, 1..16)	x number from the hardware generator

	switch (argc) {
		default:
		case 1u: {

// Single number from the soft generator

			if (random_read(KRANDOM_SOFT, &randomNumber[0], 1u) != KERR_RANDOM_NOERR) {
				error = true;
			}
			nbRandomNumber = 1u;
			break;
		}

// Multiple number, 1 <= nb <= 16 from the soft generator

		case 2u: {
			nbRandomNumber = (uint32_t)strtoul(argv[1], &dummy, 10u);
			nbRandomNumber = ((nbRandomNumber >= 1u) && (nbRandomNumber <= KNB_MAX_NUMBERS)) ? (nbRandomNumber) : (1u);
			if (random_read(KRANDOM_SOFT, &randomNumber[0], nbRandomNumber) != KERR_RANDOM_NOERR) {
				error = true;
			}
			break;
		}

// Multiple number, 1 <= nb <= 16 from the soft/hard generator

		case 3u: {
			generator = KRANDOM_SOFT;
			text_checkAsciiBuffer(argv[1], "-hard", &equals); if (equals == true) { generator = KRANDOM_HARD; }
			text_checkAsciiBuffer(argv[1], "-soft", &equals); if (equals == true) { generator = KRANDOM_SOFT; }

			nbRandomNumber = (uint32_t)strtoul(argv[2], &dummy, 10u);
			nbRandomNumber = ((nbRandomNumber >= 1u) && (nbRandomNumber <= KNB_MAX_NUMBERS)) ? (nbRandomNumber) : (1u);
			if (random_read(generator, &randomNumber[0], nbRandomNumber) != KERR_RANDOM_NOERR) {
				error = true;
			}
			break;
		}
	}

	if (error == true) {										 (void)dprintf(KSYST, "Protocol error.\n");				 status = EXIT_OS_FAILURE;     }
	else			   { for (i = 0u; i < nbRandomNumber; i++) { (void)dprintf(KSYST, "%"PRIu32"\n", randomNumber[i]); } status = EXIT_OS_SUCCESS_CLI; }
	(void)dprintf(KSYST, "\n");
	return (status);
}
