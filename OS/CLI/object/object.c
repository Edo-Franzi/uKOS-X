/*
; object.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Display the structure of a uKOS-X object.
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
#include	"kern/private/private_processes.h"
#include	"kern/private/private_mailboxes.h"
#include	"kern/private/private_pools.h"
#include	"kern/private/private_semaphores.h"
#include	"kern/private/private_mutexes.h"
#include	"kern/private/private_signals.h"
#include	"kern/private/private_softwareTimer.h"
#include	"kern/private/private_preciseSignals.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"object       Display the structure of an object.       (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Display the structure of an object\n"
									"==================================\n\n"

									"This tool displays the information content\n"
									"in the structure of an object.\n\n"

									"Input format:  object {{core} [-proc | -sema | -mutx | -mbox | -stim | -prcs] number}\n"
									"Output format: object information\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	void		local_printObjects(void);
static	void		local_printProcess(uint32_t core, uint16_t number);
static	void		local_printSemaphore(uint32_t core, uint16_t number);
static	void		local_printMutex(uint32_t core, uint16_t number);
static	void		local_printMailBox(uint32_t core, uint16_t number);
static	void		local_printSignalGroup(uint32_t core, uint16_t number);

#if (KKERN_NB_SOFTWARE_TIMERS > 0)
static	void		local_printSoftwareTimer(uint32_t core, uint16_t number);
#endif

#if (KKERN_NB_PRECISE_SIGNALS > 0)
static	void		local_printSPreciseSignal(uint32_t core, uint16_t number);
#endif

MODULE(
	Object,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_OBJECT,								// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	char_t		*dummy;
	bool		equals;
	enum		{ KOBJ_ALL, KOBJ_PROC, KOBJ_SEMA, KOBJ_MUTX, KOBJ_MBOX, KOBJ_STIM, KOBJ_SIGN, KOBJ_POOL, KOBJ_PSIG } object = KOBJ_ALL;
	enum		{ KERR_NOT, KERR_PAR, KERR_NOB, KERR_NOC } error = KERR_NOT;
	uint32_t	core, number;
	int32_t		status;

	(void)dprintf(KSYST, "uKOS-X object information.\n\n");

	PRIVILEGE_ELEVATE;

// Analyse the command line
// ------------------------
//
// Example:
//
// object 0 -proc 5
// object 1 -mbox 1
// object -proc 5 (default, core 0)
// object -mbox 1 (default, core 0)

	switch (argc) {
		default:
		case 1u: {
			object = KOBJ_ALL;
			break;
		}
		case 3u: {
			core = 0u;
			number = (uint32_t)strtol(argv[2], &dummy, 10u);
			text_checkAsciiBuffer(argv[1], "-proc", &equals); if (equals == true) { object = KOBJ_PROC; break; }
			text_checkAsciiBuffer(argv[1], "-sema", &equals); if (equals == true) { object = KOBJ_SEMA;	break; }
			text_checkAsciiBuffer(argv[1], "-mutx", &equals); if (equals == true) { object = KOBJ_MUTX; break; }
			text_checkAsciiBuffer(argv[1], "-mbox", &equals); if (equals == true) { object = KOBJ_MBOX; break; }
			text_checkAsciiBuffer(argv[1], "-stim", &equals); if (equals == true) { object = KOBJ_STIM;	break; }
			text_checkAsciiBuffer(argv[1], "-sign", &equals); if (equals == true) { object = KOBJ_SIGN; break; }
			text_checkAsciiBuffer(argv[1], "-prcs", &equals); if (equals == true) { object = KOBJ_PSIG; break; }

			error = KERR_NOB;
			break;
		}
		case 4: {
			core = (uint32_t)strtol(argv[1], &dummy, 10u);
			if (core >= KNB_CORES) {
				error = KERR_NOC;
				break;
			}

			number = (uint32_t)strtol(argv[3], &dummy, 10u);
			text_checkAsciiBuffer(argv[2], "-proc", &equals); if (equals == true) { object = KOBJ_PROC; break; }
			text_checkAsciiBuffer(argv[2], "-sema", &equals); if (equals == true) { object = KOBJ_SEMA;	break; }
			text_checkAsciiBuffer(argv[1], "-mutx", &equals); if (equals == true) { object = KOBJ_MUTX; break; }
			text_checkAsciiBuffer(argv[2], "-mbox", &equals); if (equals == true) { object = KOBJ_MBOX; break; }
			text_checkAsciiBuffer(argv[2], "-stim", &equals); if (equals == true) { object = KOBJ_STIM;	break; }
			text_checkAsciiBuffer(argv[2], "-sign", &equals); if (equals == true) { object = KOBJ_SIGN; break; }
			text_checkAsciiBuffer(argv[2], "-prcs", &equals); if (equals == true) { object = KOBJ_PSIG; break; }

			error = KERR_NOB;
			break;
		}
	}

	switch (error) {
		case KERR_NOT: {

			switch (object) {
				case KOBJ_ALL: {
					local_printObjects();
					break;
				}
				case KOBJ_PROC: {
					local_printProcess(core, (uint16_t)number);
					break;
				}
				case KOBJ_SEMA: {
					local_printSemaphore(core, (uint16_t)number);
					break;
				}
				case KOBJ_MUTX: {
					local_printMutex(core, (uint16_t)number);
					break;
				}
				case KOBJ_MBOX: {
					local_printMailBox(core, (uint16_t)number);
					break;
				}
				case KOBJ_SIGN: {
					local_printSignalGroup(core, (uint16_t)number);
					break;
				}
				case KOBJ_STIM: {

					#if (KKERN_NB_SOFTWARE_TIMERS > 0)
					local_printSoftwareTimer(core, (uint16_t)number);

					#else
					(void)dprintf(KSYST, "No S-timer in the system\n");
					#endif

					break;
				}
				case KOBJ_PSIG: {

					#if (KKERN_NB_PRECISE_SIGNALS > 0)
					local_printSPreciseSignal(core, (uint16_t)number);

					#else
					(void)dprintf(KSYST, "No precise signal in the system\n");
					#endif

					break;
				}
				default: {

// Make MISRA happy :-)

					break;
				}
			}
																				 status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_NOC: { (void)dprintf(KSYST, "The core does not exist.\n\n");   status = EXIT_OS_FAILURE;     break; }
		case KERR_NOB: { (void)dprintf(KSYST, "The object does not exist.\n\n"); status = EXIT_OS_FAILURE;     break; }
		case KERR_PAR: { (void)dprintf(KSYST, "Incorrect arguments.\n\n");		 status = EXIT_OS_FAILURE;     break; }
		default:	   {														 status = EXIT_OS_FAILURE;     break; }
	}

	PRIVILEGE_RESTORE;
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_printObjects
 *
 * - Print the max number and the number of the used uKOS-X objects
 *
 */
static	void	local_printObjects(void) {
	uint32_t	core;

	for (core = 0u; core < KNB_CORES; core++) {
		(void)dprintf(KSYST, "Objects used by the core %"PRIu32"\n\n", core);
		(void)dprintf(KSYST, "Available processes      = %3"PRIu16", max. used processes      = %3"PRIu16", used processes      = %3"PRIu16"\n", KKERN_NB_PROCESSES,       vKern_nbMaxProc[core], vKern_nbProc[core]);
		(void)dprintf(KSYST, "Available semaphores     = %3"PRIu16", max. used semaphores     = %3"PRIu16", used semaphores     = %3"PRIu16"\n", KKERN_NB_SEMAPHORES,      vKern_nbMaxSema[core], vKern_nbSema[core]);
		(void)dprintf(KSYST, "Available mutex          = %3"PRIu16", max. used mutex          = %3"PRIu16", used mutex          = %3"PRIu16"\n", KKERN_NB_MUTEXES,         vKern_nbMaxMutx[core], vKern_nbMutx[core]);
		(void)dprintf(KSYST, "Available mailboxes      = %3"PRIu16", max. used mailboxes      = %3"PRIu16", used mailboxes      = %3"PRIu16"\n", KKERN_NB_MAILBOXES,       vKern_nbMaxMbox[core], vKern_nbMbox[core]);
		(void)dprintf(KSYST, "Available signal groups  = %3"PRIu16", max. used signal groups  = %3"PRIu16", used signal groups  = %3"PRIu16"\n", KKERN_NB_SIGNALS,         vKern_nbMaxSign[core], vKern_nbSign[core]);

		#if (KKERN_NB_SOFTWARE_TIMERS > 0)
		(void)dprintf(KSYST, "Available soft-timers    = %3"PRIu16", max. used soft-timers    = %3"PRIu16", used soft-timers    = %3"PRIu16"\n", KKERN_NB_SOFTWARE_TIMERS, vKern_nbMaxStim[core], vKern_nbStim[core]);

		#else
		(void)dprintf(KSYST, "No soft-timer in the system\n");
		#endif

		#if (KKERN_NB_PRECISE_SIGNALS > 0)
		(void)dprintf(KSYST, "Available precise signal = %3"PRIu16", max. used precise signal = %3"PRIu16", used precise signal = %3"PRIu16"\n", KKERN_NB_PRECISE_SIGNALS, vKern_nbMaxPrcs[core], vKern_nbPrcs[core]);

		#else
		(void)dprintf(KSYST, "No precise signal in the system\n\n");
		#endif
	}
}

/*
 * \brief local_printProcess
 *
 * - Print the main elements of the process descriptor
 *
 */
static	void	local_printProcess(uint32_t core, uint16_t number) {
			char_t		serialManagerA[4 + 1];
			uint32_t	serialManager;
			uint8_t		i;
			proc_t		process;
	const	char_t		*father, *mode, *kind, *space, *state, *eleva;

	if (number >= KKERN_NB_PROCESSES) {
		(void)dprintf(KSYST, "The process %"PRIu16" does not exist\n", number);
		return;
	}

// Collect the information

	kern_criticalSection(KENTER_CRITICAL);
	process = vKern_proc[core][number];
	kern_criticalSection(KEXIT_CRITICAL);

// Prepare for printing

	serialManager = (uint32_t)process.oSpecification.oSerialManager;

	#if (defined(BIG_ENDIAN_S))
	for (i = 0u; i < 4u; i++) {
		serialManagerA[i] = (char_t)(serialManager & 0xFFu);
		serialManager = serialManager>>8;
	}

	#else
	for (i = 0u; i < 4u; i++) {
		serialManagerA[3u - i] = (char_t)(serialManager & 0xFFu);
		serialManager = serialManager>>8;
	}
	#endif

	serialManagerA[4] = '\0';

	father = (process.oInternal.oProcFather == nullptr)					    ? ("Orphan")   : (process.oInternal.oProcFather->oSpecification.oIdentifier);
	mode   = (process.oSpecification.oStackMode == KPROC_STACK_STATIC)	    ? ("Static")   : ("Dynamic");
	kind   = (process.oSpecification.oKind == KPROC_NORMAL)				    ? ("Normal")   : ("Daemon");
	space  = (process.oSpecification.oMode == KPROC_USER)				    ? ("User")	   : ("Privileged");
	eleva  = ((process.oInternal.oState & (1u<<BPROC_PRIV_ELEVATED)) != 0u) ? ("Elevated") : ("");

	state  = "Not installed";
	state  = ((process.oInternal.oState & (1u<<BPROC_INSTALLED))   != 0u)	? ("Installed")								   : (state);
	state  = ((process.oInternal.oState & (1u<<BPROC_RUNNING))     != 0u)	? ("Installed & running")					   : (state);
	state  = ((process.oInternal.oState & (1u<<BPROC_SUSP_TIME))   != 0u)	? ("Installed & waiting for a time")		   : (state);
	state  = ((process.oInternal.oState & (1u<<BPROC_SUSP_SIGN))   != 0u)	? ("Installed & waiting for a signal")		   : (state);
	state  = ((process.oInternal.oState & (1u<<BPROC_SUSP_SEMA))   != 0u)	? ("Installed & waiting for a semaphore")	   : (state);
	state  = ((process.oInternal.oState & (1u<<BPROC_SUSP_MBOX_E)) != 0u)	? ("Installed & waiting for a non empty mbox") : (state);
	state  = ((process.oInternal.oState & (1u<<BPROC_SUSP_MBOX_F)) != 0u)	? ("Installed & waiting for a non full mbox")  : (state);
	state  = ((process.oInternal.oState & (1u<<BPROC_SUSP_DEBG))   != 0u)	? ("Installed & waiting for a debug")		   : (state);

// Print the result

	(void)dprintf(KSYST, "Process %02"PRIu16":\n", number);
	(void)dprintf(KSYST, "-----------\n\n");

	(void)dprintf(KSYST, "   Identifier:           %s\n",					 process.oSpecification.oIdentifier);
	(void)dprintf(KSYST, "   Text:                 %s\n",					 process.oSpecification.oText);
	(void)dprintf(KSYST, "   Process father:       %s\n",					 father);
	(void)dprintf(KSYST, "   Impure data:          0x%016"PRIXPTR"\n",		 (uintptr_t)process.oInternal.oLocal);
	(void)dprintf(KSYST, "   Stack mode:           0x%04"PRIX16", %s\n",	 process.oSpecification.oStackMode, mode);
	(void)dprintf(KSYST, "   Stack start:          0x%016"PRIXPTR"\n",		 (uintptr_t)process.oSpecification.oStackStart);
	(void)dprintf(KSYST, "   Stack:                0x%016"PRIXPTR"\n",		 (uintptr_t)process.oSpecification.oStack);
	(void)dprintf(KSYST, "   Stack size:           %"PRIu32" [Bytes]\n",	 (process.oSpecification.oStackSize<<2));
	(void)dprintf(KSYST, "   Code:                 0x%016"PRIXPTR"\n",		 (uintptr_t)process.oSpecification.oCode);
	(void)dprintf(KSYST, "   Kind:                 0x%02"PRIX8", %s\n",		 process.oSpecification.oKind, kind);
	(void)dprintf(KSYST, "   Process space:        0x%02"PRIX8", %s\n",		 process.oSpecification.oMode, space);
	(void)dprintf(KSYST, "   Process state:        0x%04"PRIX16", %s, %s\n", process.oInternal.oState, state, eleva);
	(void)dprintf(KSYST, "   Priority:             %d\n",					 process.oSpecification.oPriority);
	(void)dprintf(KSYST, "   Dyn. priority:        %d\n",					 process.oInternal.oDynamicPriority);
	(void)dprintf(KSYST, "   Serial manager:       %s\n",					 &serialManagerA[0]);
	(void)dprintf(KSYST, "   Timeout:              %"PRIu32" [ms]\n",		 process.oInternal.oTimeout);

	#if (KKERN_WITH_STATISTICS_S == true)
	(void)dprintf(KSYST, "   Cumulate CPU:         %"PRIu64" [us]\n",		 process.oStatistic.oTimePCum);
	(void)dprintf(KSYST, "   Cumulate Kernel:      %"PRIu64" [us]\n",		 process.oStatistic.oTimeKCum);
	(void)dprintf(KSYST, "   Cumulate Ints:        %"PRIu64" [us]\n",		 process.oStatistic.oTimeECum);
	#endif

	(void)dprintf(KSYST, "   Skip:                 %d\n",					 process.oInternal.oSkip);
	(void)dprintf(KSYST, "   Nb. executions:       %"PRIu64"\n\n",			 process.oStatistic.oNbExecutions);
}

/*
 * \brief local_printSemaphore
 *
 * - Print the main elements of the semaphore descriptor
 *
 */
static	void	local_printSemaphore(uint32_t core, uint16_t number) {
			sema_t	semaphore;
	const	char_t	*state, *owner;

	if (number >= KKERN_NB_SEMAPHORES) {
		(void)dprintf(KSYST, "The semaphore %"PRIu16" does not exist\n", number);
		return;
	}

// Collect the information

	kern_criticalSection(KENTER_CRITICAL);
	semaphore = vKern_sema[core][number];
	kern_criticalSection(KEXIT_CRITICAL);

// Prepare for printing

	state = "Not installed";
	state = ((semaphore.oState & (1u<<BSEMA_INSTALLED)) != 0u) ? ("Installed semaphore") : (state);

	owner = "No owner";
	owner = (semaphore.oOwner == KKERN_HANDLE_FROM_ISR) ? ("ISR owner")					 : (owner);
	owner = (semaphore.oOwner >  KKERN_HANDLE_FROM_ISR) ? ("Process owner")				 : (owner);

// Print the result

	(void)dprintf(KSYST, "Semaphore %02"PRIu16":\n", number);
	(void)dprintf(KSYST, "-------------\n\n");

	(void)dprintf(KSYST, "   Identifier:           %s\n",					 semaphore.oIdentifier);
	(void)dprintf(KSYST, "   Semaphore state:      0x%04"PRIX16", %s\n",	 semaphore.oState, state);
	(void)dprintf(KSYST, "   Counter:              %"PRId32"\n",			 semaphore.oCounter);
	(void)dprintf(KSYST, "   Max. Counter:         %"PRId32"\n",			 semaphore.oMaxCounter);
	(void)dprintf(KSYST, "   Owner:                0x%016"PRIXPTR", %s\n\n", (uintptr_t)semaphore.oOwner, owner);
}

/*
 * \brief local_printMutex
 *
 * - Print the main elements of the mutex descriptor
 *
 */
static	void	local_printMutex(uint32_t core, uint16_t number) {
			mutx_t	mutex;
	const	char_t	*state, *owner;

	if (number >= KKERN_NB_MUTEXES) {
		(void)dprintf(KSYST, "The mutex %"PRIu16" does not exist\n", number);
		return;
	}

// Collect the information

	kern_criticalSection(KENTER_CRITICAL);
	mutex = vKern_mutx[core][number];
	kern_criticalSection(KEXIT_CRITICAL);

// Prepare for printing

	state = "Not installed";
	state = ((mutex.oState & (1u<<BMUTX_INSTALLED)) != 0u) ? ("Installed mutex") : (state);

	owner = "No owner";
	owner = (mutex.oOwner == KKERN_HANDLE_FROM_ISR) ? ("ISR owner")				 : (owner);
	owner = (mutex.oOwner >  KKERN_HANDLE_FROM_ISR) ? ("Process owner")			 : (owner);

// Print the result

	(void)dprintf(KSYST, "Mutex %02"PRIu16":\n", number);
	(void)dprintf(KSYST, "---------\n\n");

	(void)dprintf(KSYST, "   Identifier:           %s\n",					 mutex.oIdentifier);
	(void)dprintf(KSYST, "   Mutex state:          0x%04"PRIX16", %s\n",	 mutex.oState, state);
	(void)dprintf(KSYST, "   Counter:              %"PRId32"\n",			 mutex.oCounter);
	(void)dprintf(KSYST, "   Max. Counter:         %"PRId32"\n",			 mutex.oMaxCounter);
	(void)dprintf(KSYST, "   Owner:                0x%016"PRIXPTR", %s\n\n", (uintptr_t)mutex.oOwner, owner);
}

/*
 * \brief local_printMailBox
 *
 * - Print the main elements of the mailbox descriptor
 *
 */
static	void	local_printMailBox(uint32_t core, uint16_t number) {
			mbox_t	mailBox;
	const	char_t	*state;

	if (number >= KKERN_NB_MAILBOXES) {
		(void)dprintf(KSYST, "The mailbox %"PRIu16" does not exist\n", number);
		return;
	}

// Collect the information

	kern_criticalSection(KENTER_CRITICAL);
	mailBox = vKern_mbox[core][number];
	kern_criticalSection(KEXIT_CRITICAL);

// Prepare for printing

	state = "Not installed";
	state = ((mailBox.oState & (1u<<BMBOX_CONFIGURED)) != 0u) ? ("Installed & configured mailbox") : (state);
	state = ((mailBox.oState & (1u<<BMBOX_EMPTY))	   != 0u) ? ("Mailbox empty")				   : (state);
	state = ((mailBox.oState & (1u<<BMBOX_FULL))	   != 0u) ? ("Mailbox full")				   : (state);

// Print the result

	(void)dprintf(KSYST, "Mailbox %02"PRIu16":\n", number);
	(void)dprintf(KSYST, "-----------\n\n");

	(void)dprintf(KSYST, "   Identifier:           %s\n",				 mailBox.oIdentifier);
	(void)dprintf(KSYST, "   Mailbox state:        0x%04"PRIX16", %s\n", mailBox.oState, state);
	(void)dprintf(KSYST, "   Max. packets:         %"PRIu32"\n",		 mailBox.oNbMaxPacks);
	(void)dprintf(KSYST, "   Used packets:         %"PRIu32"\n",		 mailBox.oNbUsedPacks);
	(void)dprintf(KSYST, "   Max. used packets:    %"PRIu32"\n",		 mailBox.oNbMaxUsedPacks);
	(void)dprintf(KSYST, "   Fifo *buffer:         0x%016"PRIXPTR"\n",	 (uintptr_t)mailBox.oFIFO);
	(void)dprintf(KSYST, "   Fifo *W:              0x%016"PRIXPTR"\n",	 (uintptr_t)mailBox.oWrite);
	(void)dprintf(KSYST, "   Fifo *R:              0x%016"PRIXPTR"\n\n", (uintptr_t)mailBox.oRead);
}

/*
 * \brief local_printSignalGroup
 *
 * - Print the main elements of the signal group descriptor
 *
 */
static	void	local_printSignalGroup(uint32_t core, uint16_t number) {
			sign_t		signalGroup;
			uint16_t	i;
	const	proc_t		*from;

	if (number >= KKERN_NB_SIGNALS) {
		(void)dprintf(KSYST, "The signal group %"PRIu16" does not exist\n", number);
		return;
	}

// Collect the information

	kern_criticalSection(KENTER_CRITICAL);
	signalGroup  = vKern_sign[core][number];
	kern_criticalSection(KEXIT_CRITICAL);

// Print the result

	(void)dprintf(KSYST, "Signal group %02"PRIu16":\n", number);
	(void)dprintf(KSYST, "----------------\n\n");

	(void)dprintf(KSYST, "   Identifier:           %s\n",			   signalGroup.oIdentifier);
	(void)dprintf(KSYST, "   Group number:         %"PRIu32"\n",	   signalGroup.oGroupNumber);
	(void)dprintf(KSYST, "   Used bit:             0x%08"PRIX32"\n\n", signalGroup.oUsedBit);

	for (i = 0u; i < KKERN_NB_PROCESSES; i++) {
		from = signalGroup.oSynchro[i].oSignalFromProcess;

		(void)dprintf(KSYST, "   Process %02"PRIu16"  -->  Signal pending: 0x%08"PRIX32", Signal generate: 0x%08"PRIX32", ", i, signalGroup.oSynchro[i].oSignalBitPending, signalGroup.oSynchro[i].oSignalBitGenerate);

		if (from == KKERN_HANDLE_FROM_ISR)						  { (void)dprintf(KSYST, "From process: ISR\n");																    }
		if (from == KKERN_HANDLE_BROADCAST)						  { (void)dprintf(KSYST, "From process: Broadcast\n");															    }
		if ((from == nullptr) || (from > KKERN_HANDLE_BROADCAST)) { (void)dprintf(KSYST, "From process: 0x%016"PRIXPTR"\n", (uintptr_t)signalGroup.oSynchro[i].oSignalFromProcess); }
	}
	(void)dprintf(KSYST, "\n");
}

#if (KKERN_NB_SOFTWARE_TIMERS > 0)
/*
 * \brief local_printSoftwareTimer
 *
 * - Print the main elements of the S-timer descriptor
 *
 */
static	void	local_printSoftwareTimer(uint32_t core, uint16_t number) {
			stim_t	softwareTimer;
	const	char_t	*state, *mode;

	if (number >= KKERN_NB_SOFTWARE_TIMERS) {
		(void)dprintf(KSYST, "The S-timer %"PRIu16" does not exist\n", number);
		return;
	}

// Collect the information

	kern_criticalSection(KENTER_CRITICAL);
	softwareTimer = vKern_stim[core][number];
	kern_criticalSection(KEXIT_CRITICAL);

// Prepare for printing

	state = "Not installed";
	state = ((softwareTimer.oState & (1u<<BSTIM_CONFIGURED)) != 0u) ? ("installed & configured S-Timer") : (state);
	state = ((softwareTimer.oState & (1u<<BSTIM_RUNNING))	 != 0u) ? ("S-Timer running")				 : (state);
	state = ((softwareTimer.oState & (1u<<BSTIM_EXECUTED))   != 0u) ? ("S-Timer executed")				 : (state);

	mode = "Stop";
	mode = (softwareTimer.oTimerSpec.oMode == KSTIM_SINGLE_SHOT)	? ("Single shot mode")				 : (mode);
	mode = (softwareTimer.oTimerSpec.oMode == KSTIM_CONTINUOUS) 	? ("Continuous mode")				 : (mode);

// Print the result

	(void)dprintf(KSYST, "S-timer %02"PRIu16":\n", number);
	(void)dprintf(KSYST, "-----------\n\n");

	(void)dprintf(KSYST, "   Identifier:           %s\n",				 softwareTimer.oIdentifier);
	(void)dprintf(KSYST, "   S-Timer state:        0x%04"PRIX16", %s\n", softwareTimer.oState, state);
	(void)dprintf(KSYST, "   S-Timer mode:         0x%02"PRIX8", %s\n",  softwareTimer.oTimerSpec.oMode, mode);
	(void)dprintf(KSYST, "   Initial time:         %"PRIu32" [ms]\n",	 softwareTimer.oTimerSpec.oInitialTime);
	(void)dprintf(KSYST, "   Repeat  time:         %"PRIu32" [ms]\n",	 softwareTimer.oTimerSpec.oTime);
	(void)dprintf(KSYST, "   Code:                 0x%016"PRIXPTR"\n",	 (uintptr_t)softwareTimer.oTimerSpec.oCode);
	(void)dprintf(KSYST, "   Initial time cpt:     %"PRIu32" [ms]\n",	 softwareTimer.oInitCounter);
	(void)dprintf(KSYST, "   Repeat  time cpt:     %"PRIu32" [ms]\n\n",	 softwareTimer.oCounter);
}
#endif

#if (KKERN_NB_PRECISE_SIGNALS > 0)
/*
 * \brief local_printSPreciseSignal
 *
 * - Print the main elements of the precise signal descriptor
 *
 */
static	void	local_printSPreciseSignal(uint32_t core, uint16_t number) {
			prcs_t	preciseSignal;
	const	char_t	*state, *mode, *toProcess;

	if (number >= KKERN_NB_PRECISE_SIGNALS) {
		(void)dprintf(KSYST, "The precise signal %"PRIu16" does not exist\n", number);
		return;
	}

// Collect the information

	kern_criticalSection(KENTER_CRITICAL);
	preciseSignal = vKern_prcs[core][number];
	kern_criticalSection(KEXIT_CRITICAL);

// Prepare for printing

	state = "Not installed";
	state = ((preciseSignal.oState & (1u<<BPRCS_INSTALLED)) != 0u) ? ("installed precise signal") : (state);

	mode = "Stop";
	mode = (preciseSignal.oMode == KPRCS_SINGLE_SHOT) ? ("Single shot mode")					  : (mode);
	mode = (preciseSignal.oMode == KPRCS_CONTINUOUS)  ? ("Continuous mode")						  : (mode);

	toProcess = "To a selective process";
	toProcess = (preciseSignal.oToProcess == KKERN_HANDLE_BROADCAST) ? ("To process: Broadcast")  : (toProcess);

// Print the result

	(void)dprintf(KSYST, "Precise signal %02"PRIu16":\n", number);
	(void)dprintf(KSYST, "------------------\n\n");

	(void)dprintf(KSYST, "   Identifier:           %s\n",				   preciseSignal.oIdentifier);
	(void)dprintf(KSYST, "   Precise signal state: 0x%04"PRIX16", %s\n",   preciseSignal.oState, state);
	(void)dprintf(KSYST, "   Precise signal mode:  0x%02"PRIX8", %s\n",	   preciseSignal.oMode, mode);
	(void)dprintf(KSYST, "   Period:               %"PRIu64"\n",		   preciseSignal.oPeriod);
	(void)dprintf(KSYST, "   To process:           0x%016"PRIXPTR", %s\n", (uintptr_t)preciseSignal.oToProcess, toProcess);
	(void)dprintf(KSYST, "   Signal:               0x%08"PRIX32"\n\n",	   preciseSignal.oSignal);
}
#endif
