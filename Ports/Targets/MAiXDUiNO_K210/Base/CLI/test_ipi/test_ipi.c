/*
; test_ipi.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Preliminary test of the ipi.
;
;			core 0					core 1
;			test_ipi -generate		counter[core 1]++
;			counter[core 0]++		test_ipi -generate
;
;			test_ipi -display		test_ipi -display
;			counter[core 0]			counter[core 1]
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

STRG_LOC_CONST(aStrApplication[]) =	"test_ipi     preliminary ipi test.                     (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Test of the cores\n"
									"=================\n\n"

									"This tool performs a preliminary ipi tests.\n\n"

									"Input format:  test_ipi -generate/-display\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		test_ipi_pre_init(uint32_t argc, const char_t *argv[]);
static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Test_ipi,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	(((uint32_t)'_'<<8u)+(uint32_t)'M'),		// Module identifier (defined in the module.h)
	test_ipi_pre_init,							// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

volatile	uint8_t		vCounter[KNB_CORES] = MCSET(0u);
volatile	bool		vDataAvailable[KNB_CORES] = MCSET(false);

// Prototypes

static	void	local_machineSoftware_IRQHandler(uint32_t core, uint64_t parameter);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	uint32_t	core, destCore;
	bool		display = false, generate = false;

	core = GET_RUNNING_CORE;
	(void)dprintf(KSYST, "Ipi test.\n");

	switch (argc) {
		case 2: {
			text_checkAsciiBuffer(argv[1], "-display",  &display);
			if (display == true) {
				if (vDataAvailable[core] == true) {
					vDataAvailable[core] = false;
					(void)dprintf(KSYST, "Counter = %"PRIu8"\n", vCounter[core]);
				}
				else {
					(void)dprintf(KSYST, "No data!\n");
				}
				break;
			}
			text_checkAsciiBuffer(argv[1], "-generate",  &generate);
			if (generate == true) {
				destCore = (core == KCORE_0) ? (1u) : (0u);
				if (clint->msip[destCore].msip == 0u) {
					clint->msip[destCore].msip = 1u;
				}
				else {
					(void)dprintf(KSYST, "Channel busy!\n");
				}
				break;
			}
			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}
	return (EXIT_OS_SUCCESS_CLI);
}

/*
 * \brief test_ipi_pre_init
 *
 * - Initialise the interruption vector
 *
 */
static	int32_t	test_ipi_pre_init(uint32_t argc, const char_t *argv[]) {
	uint32_t	core;

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;

	INT_INTERRUPT_VECTOR(IINT_MACHINE_SOFTWARE, local_machineSoftware_IRQHandler);

	clint->msip[core].msip = 0u;
	core_setBitCSR(RV_CSR_MIE, ((uint64_t)1u<<(uint64_t)IINT_MACHINE_SOFTWARE));
	return (EXIT_OS_SUCCESS);
}

/*
 * \brief local_machineSoftware_IRQHandler
 *
 * - Increment a counter
 *
 */
static	void	local_machineSoftware_IRQHandler(uint32_t core, uint64_t parameter) {

	UNUSED(parameter);

	clint->msip[core].msip = 0u;
	vCounter[core]++;
	vDataAvailable[core] = true;
}
