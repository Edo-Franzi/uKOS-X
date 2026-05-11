/*
; X.
; ==

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Control the temperature.
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

STRG_LOC_CONST(aStrApplication[]) =	"X            Control the temperature.                  (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Control the temperature\n"
									"=======================\n\n"

									"This tool module allows to operate on the xtmp\n"
									"temperature manager\n\n"

									"Input format:  X\n"
									"Output format: x,t0,t1,t...t127\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	X,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,						// Family (defined in the module.h)
	KNUM_X,								// Module identifier (defined in the module.h)
	nullptr,							// Address of the initialisation code (early pre-init)
	prgm,								// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,							// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);

// CLI tool specific
// =================

#define	KNB_SAMPLES		128u			// Nb. of samples

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
			uint32_t	core, sizeRec;
			int32_t		status;
			uint16_t	*bufRec, i;
	static	uint16_t	vTemperature[KNB_CORES][KNB_SAMPLES];
	static	bool		vInitialised[KNB_CORES] = MCSET(false);
	static	mbox_t		*vMailBox[KNB_CORES];

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;

	if (vInitialised[core] == false) {
		if (kern_getMailboxById("Temperature", &vMailBox[core]) != KERR_KERN_NOERR) {
			(void)dprintf(KSYST, "Process Temperature not installed!\n");
			return (EXIT_OS_FAILURE);
		}

		vInitialised[core] = true;
	}

// Receive the message (wait until the FIFO is not empty)

	sizeRec = (KNB_SAMPLES * sizeof(uint16_t));
	status  = kern_readMailbox(vMailBox[core], (void **)&bufRec, &sizeRec, 10000u);

	switch (status) {
		case KERR_KERN_NOERR: {
			break;
		}
		case KERR_KERN_TIMEO:
		case KERR_KERN_MBKIL: {
			(void)dprintf(KSYST, "The process Temperature was killed!\n");
			vInitialised[core] = false;
			break;
		}
		default: {
			(void)dprintf(KSYST, "mbox problem\n");
			LOG(KFATAL_USER, "x: mbox problem");
			exit(EXIT_OS_FAILURE);
		}
	}

// Copy it into the temperature buffer before to "free" the memory

    memcpy(&vTemperature[core][0], bufRec, (KNB_SAMPLES * sizeof(uint16_t)));
	memo_free(bufRec);

	(void)dprintf(KSYST, "x,");
	for (i = 0u; i < (KNB_SAMPLES - 1u); i++) {
		(void)dprintf(KSYST, "%d,",  vTemperature[core][i]);
	}
	(void)dprintf(KSYST, "%d\n", vTemperature[core][KNB_SAMPLES - 1u]);

	return (EXIT_OS_SUCCESS_CLI);
}
