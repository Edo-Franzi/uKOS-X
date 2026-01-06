/*
; cordic.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application shows how to operate with the uKOS-X uKernel.
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

/*!
 * \file
 * \ingroup app_mathematic
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 2 processes:
 *
 *			- P0: Every 1000-ms
 *					- Toggle LED 1
 *
 *			- P1: Every 1000-ms
 *					- Compute the atan2 with a Cordic
 *
 */

#include	"uKOS.h"
#include	<math.h>

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"cordic       Example of the cordic implementation.     (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  cordic\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

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

#define	KNB_ITERATION	24u
#define KPI				3.14159265358979

// Prototypes

static	float64_t	local_atan2(int32_t y, int32_t x);

/*
 * \brief aProcess 0
 *
 * - P0: Every 1000-ms
 *			- Toggle LED 1
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(1000u);
		led_toggle(KLED_1);
	}
}

/*
 * \brief aProcess 1
 *
 * - P1: Every 1000-ms
 *			- Compute the atan2 with a Cordic
 *
 */
static void __attribute__ ((noreturn)) aProcess_1(const void *argument) {
	uint64_t	time[2];
	uint32_t	delta = 0;
	float64_t	angle;

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(200u);

// Cordic implementation

		kern_readTickCount(&time[0]);
		angle = local_atan2(123456789, 23456789);
		kern_readTickCount(&time[1]);
		delta = (uint32_t)(time[1] - time[0]);

		(void)dprintf(KSYST, "Cordic angle %10.7f, time %"PRIu32"-us\n", angle, delta);

// Newlib implementation

		kern_readTickCount(&time[0]);
		angle = atan2(123456789, 23456789);
		kern_readTickCount(&time[1]);
		delta = (uint32_t)(time[1] - time[0]);

		(void)dprintf(KSYST, "newlib angle %10.7f, time %"PRIu32"-us\n", angle, delta);
	}
}

static	float64_t local_atan2(int32_t y, int32_t x) {
	register	uint32_t	i;
	register	int32_t		lx, ly, yi;
	register	float64_t	angle = 0.0;
	register	float64_t	*tabAtan;
	static		float64_t	aTabAtan[] = {
								0.785398163397448000000000000000, 0.463647609000806000000000000000,
								0.244978663126864000000000000000, 0.124354994546761000000000000000,
								0.062418809995957400000000000000, 0.031239833430268300000000000000,
								0.015623728620476800000000000000, 0.007812341060101110000000000000,
								0.003906230131966970000000000000, 0.001953122516478820000000000000,
								0.000976562189559319000000000000, 0.000488281211194898000000000000,
								0.000244140620149362000000000000, 0.000122070311893670000000000000,
								0.000061035156174208800000000000, 0.000030517578115526100000000000,
								0.000015258789061315800000000000, 0.000007629394531101970000000000,
								0.000003814697265606500000000000, 0.000001907348632810190000000000,
								0.000000953674316405961000000000, 0.000000476837158203089000000000,
								0.000000238418579101558000000000, 0.000000119209289550781000000000,
								0.000000059604644775390600000000, 0.000000029802322387695300000000,
								0.000000014901161193847700000000, 0.000000007450580596923830000000,
								0.000000003725290298461910000000, 0.000000001862645149230960000000,
								0.000000000931322574615479000000, 0.000000000465661287307739000000
							};

	if ((x == 0) && (y == 0)) {
		return (0.0);
	}

	lx = x; ly = y;

// Verify the right plane

	if (lx < 0) { lx = -lx; ly = -ly; angle = KPI;    }
	if (ly > 0) {                     angle = -angle; }

	tabAtan = &aTabAtan[0];

// Rotate the vector and compute the angle

	for (i = 0; i < KNB_ITERATION; i++) {
		if (ly < 0) {
			yi = ly + (lx>>i);
			lx = lx - (ly>>i);
			ly = yi;
			angle -= tabAtan[i];
		}
		else {
			yi = ly - (lx>>i);
			lx = lx + (ly>>i);
			ly = yi;
			angle += tabAtan[i];
		}
	}
	return (angle);
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
	proc_t	*process_0, *process_1;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2026";
	STRG_LOC_CONST(aStrText_1[]) = "Process user 1.                           (c) EFr-2026";

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use specification_x)
		aStrText_0,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		aStrIden_0,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		1,									// Index
		specification_1,					// Specifications (just use specification_x)
		aStrText_1,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_1,							// Code of the process
		aStrIden_1,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, NULL, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, NULL, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
