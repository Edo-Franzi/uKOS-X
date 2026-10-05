/*
; run.
; ====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Launch a function module.
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

STRG_LOC_CONST(aStrApplication[]) =	"run          Run a downloaded code.                    (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Launch a function module\n"
									"========================\n\n"

									"This tool runs a downloaded code.\n\n"

									"Input format:  run\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Run,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_RUN,									// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

#define	KIDUSER	((KID_FAM_APPLICATIONS<<24u) | (KNUM_APPLICATION<<8u) | '_')

// Prototypes

static	bool	local_isApplication(int32_t (*code)(uint32_t argc, const char_t *argv[]));

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	int32_t		status, (*code)(uint32_t argc, const char_t *argv[]);

	(void)dprintf(KSYST, "Execute the downloaded application.\n");

	system_getDownloadCodeAddress((void **)&code);
	if (code == nullptr) {
		(void)dprintf(KSYST, "No application in the memory!\n\n");
		status = EXIT_OS_FAILURE;
	}

// A loader publishes an address even for a download that is not an application
// (an S-record terminator alone publishes the start of the user memory): verify
// that an application for this system is really there before jumping to it,
// and forget an address that is not one - the next run reports an empty memory

	else if (local_isApplication(code) == false) {
		(void)dprintf(KSYST, "The downloaded code is not an application for this system!\n\n");
		system_setDownloadCodeAddress(nullptr);
		status = EXIT_OS_FAILURE;
	}
	else {
		(void)dprintf(KSYST, "Run the downloaded application...\n\n");
		system_setDownloadCodeAddress(nullptr);
		status = (*code)(argc, argv);
	}
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_isApplication
 *
 * - Verify that the user memory holds the application a loader announced
 *   - the header at the start of the user memory is marked KMEMU
 *   - the entry point it declares is the address that was published
 *   - its length fits in the user memory
 *   - the system signature lies inside the application itself: SRAM keeps
 *     its content across resets, so a stale copy may sit anywhere else
 *
 */
static	bool	local_isApplication(int32_t (*code)(uint32_t argc, const char_t *argv[])) {
			uKOS_header_t	header;
			size_t			ln, i = 0u;
	const	uint8_t			*ptr = (const uint8_t *)linker_stUMemo;
	const	char_t			*signature;

	memcpy(&header, (const void *)linker_stUMemo, sizeof(header));

	if ((header.oMemLocation != KMEMU) || (header.oStart != code)) {
		return (false);
	}

	if ((header.oLnApplication == 0u) || (header.oLnApplication > (uintptr_t)linker_lnUMemo)) {
		return (false);
	}

	system_getSystemSignature(&signature);

	for (ln = (size_t)header.oLnApplication; ln > 0u; --ln) {
		if (*ptr == (uint8_t)signature[i]) {
			i++;
			if (*ptr == 0u) {
				return (true);
			}
		}
		else {

// A mismatch may still be the first character of the signature

			i = (*ptr == (uint8_t)signature[0]) ? (1u) : (0u);
		}
		ptr++;
	}
	return (false);
}
