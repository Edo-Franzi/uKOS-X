/*
; uKOS_minimal.
; =============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a minimal application using the uKOS-X uKernel.
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
 * \ingroup app_special
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 3 processes:
 *
 *			- P0: process_actuator
 *				  Get the queue "Queue dispatcher" handle
 *				  Every 1000-ms
 *					- Generate a new gray code
 *					- Write the code to the queue
 *
 *			- P1: process_sensor
 *				  Get the queue "Queue dispatcher" handle
 *				  Every 100-ms
 *					- Increment a counter
 *					- Write the counter to the queue
 *
 *			- P2: process_dispatcher
 *				  Get the queue "Queue dispatcher" handle
 *				  Read the messages coming from the queue
 *				  if KID_SENSOR
 *					- turn on/off the led 0
 *				  if KID_ACTUATOR
 *					- Display the code on the KURT0
 *
 */

#include	"uKOS.h"
#include	"hard.h"

// Prototypes

extern	bool	installaProcess_sensor(void);
extern	bool	installaProcess_actuator(void);
extern	bool	installaProcess_dispatcher(void);
static	void	local_changeStateLed(const void *argument);

mbox_t	*vQueue_dispatcher = nullptr;

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"uKOS_minimal Minimal app (for ASIC).                   (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  uKOS_minimal\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

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

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
int		main(int argc, const char *argv[]) {
	stim_t	*softwareTimer;
	mcnf_t	configure_mbox = {
				.oNbMaxPacks	= 10u,
				.oDataEntrySize	= 0u
			};
	tspc_t	configure_stim = {
				.oMode		  = KSTIM_CONTINUOUS,
				.oInitialTime = 2000u,
				.oTime		  = 30u,
				.oCode		  = local_changeStateLed,
				.oArgument	  = nullptr
			};

	UNUSED(argc);
	UNUSED(argv);

// Create the "dispatcher" queue
// Create the software timer
// Launch the processes

	if (kern_createMailbox("Queue dispatcher", &vQueue_dispatcher) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create mbox");	 exit(EXIT_OS_FAILURE); }
	if (kern_setMailbox(vQueue_dispatcher, &configure_mbox)		   != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Configure mbox"); exit(EXIT_OS_FAILURE); }
	if (kern_createSoftwareTimer("Blink Led 2", &softwareTimer)	   != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create stim");	 exit(EXIT_OS_FAILURE); }
	if (kern_setSoftwareTimer(softwareTimer, &configure_stim)	   != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Configure stim"); exit(EXIT_OS_FAILURE); }

	if (installaProcess_sensor()	 == false)										   { LOG(KFATAL_USER, "Create proc");	 exit(EXIT_OS_FAILURE); }
	if (installaProcess_actuator()	 == false)										   { LOG(KFATAL_USER, "Create proc");	 exit(EXIT_OS_FAILURE); }
	if (installaProcess_dispatcher() == false)										   { LOG(KFATAL_USER, "Create proc");	 exit(EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}

/*
 * \brief Routine cyclically called by a software timers
 *
 * - 8 x blinks and long pause
 *
 */
static	void	local_changeStateLed(const void *argument) {
	static	uint8_t		vCptBlink = 0u;

	UNUSED(argument);

	((vCptBlink & 0x1Fu) > 8u) ? (led_off(KLED_1)) : (led_toggle(KLED_1));
	vCptBlink++;
}
