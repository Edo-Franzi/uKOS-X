/*
; runDemo.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Launch an N6 demo.
;			The code located in the Octo Flash is copien inside the
;			APSRam and executed.
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

STRG_LOC_CONST(aStrApplication[]) =	"runDemo      Run a demo code.                          (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Launch a function module\n"
									"========================\n\n"

									"This tool runs a demo code.\n"
									"This tool is reserved for Discovery_N657 boards\n\n"

									"Input format:  runDemo\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	int32_t		pre_init(uint32_t argc, const char_t *argv[]);

extern	uint8_t		linker_stUMemo[];
extern	uint8_t		linker_stExtFlash[];

MODULE(
	RunDemo,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_RUN_DEMO,								// Module identifier (defined in the module.h)
	pre_init,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

#define	KIDUSER	((KID_FAM_APPLICATIONS<<24u) | (KNUM_APPLICATION<<8u) | '_')

/*
 * \brief Main entry point
 *
 */
static	int32_t prgm(uint32_t argc, const char_t *argv[]) {
			int32_t			status, (*code)(uint32_t argc, const char_t *argv[]);
			uKOS_header_t	APSRamHeader;
			uKOS_header_t	flashHeader;
			uint8_t			*demoAPSRAM = linker_stUMemo;
	const	uint8_t			*demoFlash	= (linker_stExtFlash + 0x300000u + 0x400);
	const	size_t			demoSize	= 0x800000;

	(void)dprintf(KSYST, "Execute the flash demo application.\n");

// Verify if a demo is available

	memcpy(&flashHeader, demoFlash, sizeof(flashHeader));

	if ((flashHeader.oMemLocation == KMEMU) &&
		(flashHeader.oStart != nullptr)	 &&
		(flashHeader.oLnApplication != 0)	 &&
		(flashHeader.oModule != nullptr)) {

// Verify the size

		if ((size_t)flashHeader.oLnApplication > demoSize) {
			(void)dprintf(KSYST, "Demo application is too large: %" PRIuPTR " bytes.\n\n", (uintptr_t)flashHeader.oLnApplication);
			return (EXIT_OS_FAILURE);
		}

// It seems that an available demo is available
// Copy the demo into the APSRam and execute it

		memcpy(demoAPSRAM,	  demoFlash,  demoSize);
        memcpy(&APSRamHeader, demoAPSRAM, sizeof(APSRamHeader));

		code = APSRamHeader.oStart;
		(void)dprintf(KSYST, "Run the demo application...@address = 0x%016"PRIXPTR"\n\n", (uintptr_t)code);
		status = ((*code)(argc, argv));
		return (status);
	}

	(void)dprintf(KSYST, "No demo in the flash!\n\n");
	status = EXIT_OS_FAILURE;
	return (status);
}

/*
 * \brief pre_init
 *
 * - Try to clean the ressources
 *		- Free all the ressources
 *
 */
static	int32_t pre_init(uint32_t argc, const char_t *argv[]) {
			uint8_t			*demoAPSRAM = linker_stUMemo;
	const	size_t			demoSize	= 0x800000;

	UNUSED(argc);
	UNUSED(argv);

	memset(demoAPSRAM, 0, demoSize);

	return (EXIT_OS_SUCCESS);
}
