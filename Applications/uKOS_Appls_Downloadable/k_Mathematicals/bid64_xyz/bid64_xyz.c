/*
; bid64_xyz.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application shows how to operate with the uKOS-X uKernel.
;
;   (c) 2025-20xx, Edo. Franzi
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

/*!
 * \file
 * \ingroup app_mathematic
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 1 processes:
 *
 *			- P0: - Initialise the Intel math library
 *				  - Compute the mul & div
 *				  - Display the result
 *				  - Commit a suicide
 *
 */

#include	"uKOS.h"
#include	"bid_conf.h"
#include	"bid_functions.h"
#include	<math.h>
#include	<string.h>

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"bid64_xyz    Example of how to use the Intel math lib. (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  bid64_xyz\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

MODULE(
	UserAppl,							// Module name (the first letter has to be upper case)
	KID_FAM_APPLICATIONS,				// Family (defined in the module.h)
	KNUM_APPLICATION,					// Module identifier (defined in the module.h)
	NULL,								// Address of the initialisation code (early pre-init)
	aStart,								// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,								// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);

// Application specific
// ====================

typedef	struct	exception	exception_t;

struct exception {
				uint8_t		oFlag;
		const	char_t		*oMessage;
};

static	char_t	vResult[128];
static	char_t	*vN1 = "0.004565e-3";
static	char_t	*vN2 = "1.747470e+4";
static	char_t	*vZe = "00000000000";

// Prototypes

static void	local_printStatus(_IDEC_flags fpsf);

/*
 * \brief aProcess
 *
 * - Initialise the Intel math library
 * - Compute the mul & div
 * - Display the result
 * - Commit a suicide
 *
 */
static void __attribute__ ((noreturn)) aProcess(const void *argument) {
	_IDEC_flags		fpsf;
	BID_UINT64		x, y, z;

	UNUSED(argument);

	kern_suspendProcess(1000u);
	(void)dprintf(KSYST, "\n");

// Multiplication

	fpsf = 0;
	x = bid64_from_string((char *)vN1, BID_ROUNDING_TO_NEAREST, &fpsf);
	y = bid64_from_string((char *)vN2, BID_ROUNDING_TO_NEAREST, &fpsf);
	z = bid64_mul(x, y, BID_ROUNDING_TO_NEAREST, &fpsf);

    bid64_to_string(vResult, z, &fpsf);
	local_printStatus(fpsf);

	(void)dprintf(KSYST, "%s mul %s = %s\n\n", vN1, vN2, vResult);

// Division (!= 0)

	fpsf = 0;
	x = bid64_from_string((char *)vN1, BID_ROUNDING_TO_NEAREST, &fpsf);
	y = bid64_from_string((char *)vN2, BID_ROUNDING_TO_NEAREST, &fpsf);
	z = bid64_div(x, y, BID_ROUNDING_TO_NEAREST, &fpsf);

    bid64_to_string(vResult, z, &fpsf);
	local_printStatus(fpsf);

	(void)dprintf(KSYST, "%s div %s = %s\n\n", vN1, vN2, vResult);

// Division (= 0)

	fpsf = 0;
	x = bid64_from_string((char *)vN1, BID_ROUNDING_TO_NEAREST, &fpsf);
	y = bid64_from_string((char *)vZe, BID_ROUNDING_TO_NEAREST, &fpsf);
	z = bid64_div(x, y, BID_ROUNDING_TO_NEAREST, &fpsf);

    bid64_to_string(vResult, z, &fpsf);
	local_printStatus(fpsf);

	(void)dprintf(KSYST, "%s div %s = %s\n\n", vN1, vZe, vResult);

	kern_suspendProcess(1000u);
	exit(EXIT_OS_SUCCESS);
}

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
int		main(int argc, const char *argv[]) {
	proc_t	*process;

// -------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden[]) = "Process_User";
	STRG_LOC_CONST(aStrText[]) = "Process user.                             (c) EFr-2025";

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess,							// Code of the process
		aStrIden,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, NULL, &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_printStatus
 *
 * - Display the status of the operation
 *
 */
static void	local_printStatus(_IDEC_flags fpsf) {
	const	exception_t		aTabException[] = {
								{ DEC_FE_INVALID,	"NaN, conversion impossible" },
								{ DEC_FE_UNNORMAL,	"Not normal"				 },
								{ DEC_FE_DIVBYZERO,	"Division by 0"				 },
								{ DEC_FE_OVERFLOW,	"Overflow"					 },
								{ DEC_FE_UNDERFLOW,	"Underflow"					 },
								{ DEC_FE_INEXACT,	"Inexact"					 },
								{ 0u,				NULL						 }
							};
	const exception_t		*table = &aTabException[0];

	if (fpsf == 0u) { return; }

	while (table->oFlag != 0u) {
		if (fpsf & table->oFlag) { (void)dprintf(KSYST, "%s\n", table->oMessage); }
		table++;
	}
}
