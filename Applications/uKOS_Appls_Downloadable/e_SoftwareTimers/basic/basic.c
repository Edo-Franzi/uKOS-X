/*
; basic.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

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
 * \ingroup app_stim
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 1 processes:
 *
 *			- P0: Install the software timers
 *				  Every 2000-ms
 *					- Change dynamically the time of the stim 0
 *					- Print a message
 *
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"basic        Example of how to use a software timer.   (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  basic\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#if (defined(ROMABLE_S))

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Basic,								// Module name (the first letter has to be upper case)
	KID_FAM_CLI,						// Family (defined in the module.h)
	KNUM_ROMABLE_0,						// Module identifier (defined in the module.h)
	nullptr,							// Address of the initialisation code (early pre-init)
	prgm,								// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,							// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);

#else
MODULE(
	UserAppl,							// Module name (the first letter has to be upper case)
	KID_FAM_APPLICATIONS,				// Family (defined in the module.h)
	KNUM_APPLICATION,					// Module identifier (defined in the module.h)
	nullptr,							// Address of the initialisation code (early pre-init)
	aStart,								// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,							// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);
#endif

// Application specific
// ====================

// Prototypes

static	void	local_changeStateLed(const void *argument);

/*
 * \brief aProcess
 *
 * - P0: Install the software timers
 *		 Every 2000-ms
 *			- Change dynamically the time of the stim 0
 *			- Print a message
 *
 */
[[noreturn]]
static	void	aProcess(const void *argument) {
					uint32_t	time;
					tspc_t		configure_0, configure_1;
					stim_t		*softwareTimer_0, *softwareTimer_1;
	static	const	uint32_t	argument_0[2] = { 0u }, argument_1[2] = { 1u };

	UNUSED(argument);


	configure_0.oMode		 = KSTIM_SINGLE_SHOT;
	configure_0.oInitialTime = 200u;
	configure_0.oTime 		 = 1234u;
	configure_0.oCode 		 = local_changeStateLed;
	configure_0.oArgument	 = &argument_0[0];

	configure_1.oMode		 = KSTIM_CONTINUOUS;
	configure_1.oInitialTime = 1345u;
	configure_1.oTime		 = 34u;
	configure_1.oCode		 = local_changeStateLed;
	configure_1.oArgument	 = &argument_1[0];

	if (kern_createSoftwareTimer("Blink Led 0", &softwareTimer_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create stim"); exit(EXIT_OS_FAILURE); }
	if (kern_createSoftwareTimer("Blink Led 1", &softwareTimer_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create stim"); exit(EXIT_OS_FAILURE); }

// Start the timer 0 in one shot mode

	if (kern_setSoftwareTimer(softwareTimer_0, &configure_0) != KERR_KERN_NOERR) {
		LOG(KFATAL_USER, "Configure stim");
		exit(EXIT_OS_FAILURE);
	}

	kern_suspendProcess(3900u);

// Start the timer 1 in one shot mode

	if (kern_setSoftwareTimer(softwareTimer_1, &configure_1) != KERR_KERN_NOERR) {
		LOG(KFATAL_USER, "Configure stim");
		exit(EXIT_OS_FAILURE);
	}

// Restart the timer 0 in continue mode

	configure_0.oMode		 = KSTIM_CONTINUOUS;
	configure_0.oInitialTime = 200u;
	configure_0.oTime		 = 56u;
	configure_0.oCode		 = local_changeStateLed;
	configure_0.oArgument	 = &argument_0[0];
	if (kern_setSoftwareTimer(softwareTimer_0, &configure_0) != KERR_KERN_NOERR) {
		LOG(KFATAL_USER, "Configure stim");
		exit(EXIT_OS_FAILURE);
	}

// Forever

	time = 50u;
	kern_suspendProcess(1000u);
	while (true) {
		kern_suspendProcess(2000u);

		time = (time > 5000u) ? (50u) : (time + 200u);
		configure_0.oMode		 = KSTIM_CONTINUOUS;
		configure_0.oInitialTime = 0u;
		configure_0.oTime		 = time;
		configure_0.oCode		 = local_changeStateLed;
		configure_0.oArgument	 = &argument_0[0];
		if (kern_setSoftwareTimer(softwareTimer_0, &configure_0) != KERR_KERN_NOERR) {
			LOG(KFATAL_USER, "Configure stim");
			exit(EXIT_OS_FAILURE);
		}

		(void)dprintf(KSYST, "Running ...\n");
	}
}

// Routine cyclically called by a software timers

static	void	local_changeStateLed(const void *argument) {
			uint32_t	led;
	const	uint32_t	*pack;

	pack = (const uint32_t *)argument;
	led = *pack;
	led_toggle((uint8_t)led);
}

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
MAIN_ENTRY(argc, argv[]) {
	proc_t	*process;

// -------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden[]) = "Process_Software_Timer";
	STRG_LOC_CONST(aStrText[]) = "Process Software Timer.                   (c) EFr-2026";

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,										// Index
		specification,							// Specifications (just use specification_x)
		aStrText,								// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,						// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess,								// Code of the process
		aStrIden,								// Identifier (nullptr if anonymous)
		KDEF0,									// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_15				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, nullptr, &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
