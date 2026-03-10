/*
; uKOS.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi			The 2025-01-01
; Modifs:	Laurent von Allmen	The 2025-01-01
;
; Project:	uKOS-X
; Goal:		Give some uKOS-X info.
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
#include	"version.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"uKOS         The uKOS-X information.                   (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "The uKOS-X information\n"
									"========================\n\n"

									"This tool gives information about the uKOS-X\n"
									"uKernel.\n\n"

									"Input format:  uKOS\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	UKOS,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_UKOS,									// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

STRG_LOC_CONST(aStruKOS[])	  = STRG_STRIP;
STRG_LOC_CONST(aStrShowRev[]) = SW_VERSION;

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {

	UNUSED(argc);
	UNUSED(argv);

	(void)dprintf(KSYST, "uKOS History\n\n");

	(void)dprintf(KSYST, "1984 - 1986, uKOS-0\n");
	(void)dprintf(KSYST, "The story began with a nano-scheduler running on a Motorola\n");
	(void)dprintf(KSYST, "M6809 microprocessor.\n\n");

	(void)dprintf(KSYST, "1989 - 1997, uKOS-I\n");
	(void)dprintf(KSYST, "A major boost to the project came from an EPFL research initiative:\n");
	(void)dprintf(KSYST, "a mobile robot powered by this kernel, written in CALM assembler.\n");
	(void)dprintf(KSYST, "https://en.wikipedia.org/wiki/Khepera_mobile_robot\n\n");

	(void)dprintf(KSYST, "1997 - 2005, uKOS-II\n");
	(void)dprintf(KSYST, "The first C-based implementation, taking advantage of the Apple\n");
	(void)dprintf(KSYST, "MPW C development environment.\n\n");

	(void)dprintf(KSYST, "2005 - 2017, uKOS-III\n");
	(void)dprintf(KSYST, "A more refined version, built using the GCC toolchain.\n");
	(void)dprintf(KSYST, "It was withdrawn from open-source in 2017.\n\n");

	(void)dprintf(KSYST, "2025 - 20xx, uKOS-X back to the open-source.\n");
	(void)dprintf(KSYST, "The natural evolution of the micro-kernel, uKOS-X is designed to support\n");
	(void)dprintf(KSYST, "modern SoC architectures-both single- and multi-core-using\n");
	(void)dprintf(KSYST, "state-of-the-art toolchains. It reflects over 40 years of accumulated\n");
	(void)dprintf(KSYST, "experience in embedded systems development.\n\n");

	(void)dprintf(KSYST, "Main contributors to uKOS-X:\n");
	(void)dprintf(KSYST, "   Edo. Franzi               - Project initiator and lead maintainer\n");
	(void)dprintf(KSYST, "   Laurent von Allmen        - New ideas, LLVM and CMake toolchain integration,\n");
	(void)dprintf(KSYST, "                               quality, testing, rigour\n");
	(void)dprintf(KSYST, "   Antonio Jose Restrepo Zea - New ideas, quality, testing, rigour\n\n");

	(void)dprintf(KSYST, "VCS#: %s\n\n", aStrShowRev);
	(void)dprintf(KSYST, "%s", aStruKOS);
	return (EXIT_OS_SUCCESS_CLI);
}
