/*
; test_cpp.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application shows how to operate with the uKOS-X uKernel.
;
;			Launch 1 processes in C++:
;
;			- P0: Display a classe
;				  Every 100-ms
;				  Toggle LED 0
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
 * \ingroup app_special
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 1 processes:
 *
 *			- P0: Every 100-ms
 *					- Toggle LED 0
 *
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"test_cpp     Example of how to use the C++.            (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])        = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  test_cpp\n"
									"Output format: [result]\n\n";

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

class  TestClass {
public:
	TestClass()	: counter_(0)	{ (void)dprintf(KSYST, "Construction\n");  }
	~TestClass()				{ (void)dprintf(KSYST, "Destruction\n");   }
	void doit()	const			{ (void)dprintf(KSYST, "in the middle\n"); }

private:
	uint32_t	counter_;
};

/*
 * \brief aProcess
 *
 * - P0: - Display the class
 *		 - Every 100-ms
 *			- Toggle LED 0
 *
 */
namespace {
	void	__attribute__ ((noreturn)) aProcess_0(const void *argument) {

		UNUSED(argument);

// Waiting from the uKOS-X prompt

		kern_suspendProcess(100u);
		(void)dprintf(KSYST, "\n");

		{
		const	TestClass titi;
		titi.doit();
		}

		while (true) {
			kern_suspendProcess(100u);
			led_toggle(KLED_0);
		}
	}
}

/*
 * \brief main
 *
 * - Initialize the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
int		main(int argc, const char *argv[]) {
	proc_t	*process_0;

// ------------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) =    "Process_User";
	STRG_LOC_CONST(aStrText_0[]) =    "Process user.                             (c) EFr-2025";

	UNUSED(argc);
	UNUSED(argv);

// Initialise the C++ constructors

	CPP_INIT_ARRAYS;

// Specifications for the processes

// NOLINTBEGIN(misc-const-correctness)
//
	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use vSpecification_x)
		aStrText_0,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_MM,					// KSZSTACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		aStrIden_0,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_02				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

// NOLINTEND(misc-const-correctness)
//

	if (kern_createProcess(&specification_0, NULL, &process_0) != KERR_KERN_NOERR) { exit(EXIT_OS_FAILURE); }
	return (EXIT_OS_SUCCESS_CLI);
}
