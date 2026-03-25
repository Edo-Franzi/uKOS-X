/*
; dumpshared.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Display the shared area of the multicore system.
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

STRG_LOC_CONST(aStrApplication[]) =	"dumpshared   Dump the shared area of the multicore.    (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Dump the shared area of the multicore\n"
									"=====================================\n\n"

									"This tool display the content of the shared ared\n"
									"of the multicore systems\n\n"

									"Input format:  dumpshared\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Dumpshared,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_DUMP_SHARED,							// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

extern	asmpShared_t	*vAsmp_InterCore;

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	uint32_t	i;

	UNUSED(argc);
	UNUSED(argv);

	(void)dprintf(KSYST, "Shared dump.\n");

	(void)dprintf(KSYST, "\nASMPReady: 0x%02"PRIX8"\n\n", vAsmp_InterCore->oASMPReady);

	for (i = 0u; i < KASMP_NB_CORES; i++) {
		(void)dprintf(KSYST, "Core %ld, StatusRX: %s\n",   i, (vAsmp_InterCore->oStatusRX[i] == true) ? ("LOCK") : ("FREE"));
		(void)dprintf(KSYST, "Core %ld, StatusTX: %s\n",   i, (vAsmp_InterCore->oStatusTX[i] == true) ? ("LOCK") : ("FREE"));

		(void)dprintf(KSYST, "Core %ld, Sender:   %ld\n",  i, vAsmp_InterCore->oSender[i]);
		(void)dprintf(KSYST, "Core %ld, Order:    %ld\n",  i, vAsmp_InterCore->oOrder[i]);
		(void)dprintf(KSYST, "Core %ld, Size:     %ld\n",  i, vAsmp_InterCore->oSize[i]);
		(void)dprintf(KSYST, "Core %ld, Buffer:   %s\n\n", i, vAsmp_InterCore->oBuffer[i]);
	}
	return (EXIT_OS_SUCCESS_CLI);
}
