/*
; crt0.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		crt0 for the uKOS-X system.
;			Privileged only support
;
;                       CODE
; linker_stTEXT			+-----------------+
;						|                 |
;						| .isr_vector     |
;						| .text           |
;						| .rodata         |
; linker_enRODATA		|                 |                   DATA
;						+-----------------+ ........... +-----------------+ linker_stDATA
; linker_stINDATA		|                 |				|                 |
;						| .data           |				| .data           |
;						|                 |				|                 | linker_enDATA
;						+-----------------+ ........... +-----------------+
; linker_stSignature	|				  |				|                 | linker_stBSS
;						+-----------------+				| .bss            |
;														| COMMON          |
;														|                 | linker_enBSS
;														+-----------------+
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
#include	"linker.h"
#include	"kern/private/private_processes.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"crt0         Runtime crt0.                             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "crt0\n"
									"====\n\n"

									"Runtime crt0 of the system ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Crt0,							// Module name (the first letter has to be upper case)
	KID_FAM_STARTUPS,				// Family (defined in the module.h)
	KNUM_CRT0,						// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Runtime specific
// ================

uint32_t	vCrt0_randomSeed;

// For the stack guard, only 32 and 64-bit machines are considered

extern	uintptr_t	__stack_chk_guard;

#if (UINTPTR_MAX == 0xFFFFFFFFu)
#define	KSTACK_GUARD_VALUE	0xDeadBeefu

#else
#define	KSTACK_GUARD_VALUE	0xDeadBeeffeeBdaeDu
#endif

// Prototypes

extern	void	init_relocate(void);
static	void	local_killProcess(void);
static	void	local_panicMallocBroken(void);
static	void	local_panicStackUnderflow(void);
static	void	local_panicNoSystemCall(void);
static	void	local_panicElevation(void);
static	void	local_panicGeneral(void);
static	void	local_printTrace(void);
static	void	local_printLog(void);

/*
 * \brief crt0
 *
 * - ONLY for the core 0 !!!
 * - Copy the initialised data from the CODE to the DATA region
 * - Initialise the BSS region
 * - Call the main
 *
 */
void	crt0(void) {
			intptr_t	nbWords;
			uint32_t	core, seed;
	const	uint32_t	*regionSeed;

	core = GET_RUNNING_CORE;

// Initialise the LOW level (!!! No static variables !!!)

	init_init();

	if (core == KCORE_0) {

		cmns_init();

// Before to initialise the system RAM, we use its random content
// @ the power-on for generating a random seed usable for the software
// Random Number Generators
//
// seed = seed[k - 1] + memory[k]

		#if (defined(PRIVILEGED_USER_S))
		regionSeed = ALIGNED_PTR(const uint32_t, linker_stPrgmData_u);

		nbWords    = (intptr_t)(((uintptr_t)linker_lnPrgmData_u) / 4u);
		seed       = 0u;
		while (nbWords-- > 0) {
			seed += *regionSeed;
			regionSeed++;
		}

// Copy the initialised data from the CODE region to the DATA one
// Initialise the BSS region

		memcpy(linker_stDATA_p, linker_stINDATA_p, (size_t)((uintptr_t)linker_enDATA_p - (uintptr_t)linker_stDATA_p));
		memcpy(linker_stDATA_u, linker_stINDATA_u, (size_t)((uintptr_t)linker_enDATA_u - (uintptr_t)linker_stDATA_u));
		memset(linker_stBSS_p,  0x00u,			   (size_t)((uintptr_t)linker_enBSS_p  - (uintptr_t)linker_stBSS_p));
		memset(linker_stBSS_u,  0x00u,			   (size_t)((uintptr_t)linker_enBSS_u  - (uintptr_t)linker_stBSS_u));

		#else
		regionSeed = ALIGNED_PTR(uint32_t, linker_stPrgmData);

		nbWords    = (intptr_t)(((uintptr_t)linker_lnPrgmData) / 4);
		seed       = 0u;
		while (nbWords-- > 0) {
			seed += *regionSeed;
			regionSeed++;
		}

// Copy the initialised data from the CODE region to the DATA one
// Initialise the BSS region

		memcpy(linker_stDATA, linker_stINDATA, (size_t)((uintptr_t)linker_enDATA - (uintptr_t)linker_stDATA));
		memset(linker_stBSS,  0x00u,		   (size_t)((uintptr_t)linker_enBSS  - (uintptr_t)linker_stBSS));
		#endif

// Initialise the Heap regions

		memset(linker_stHeap, 0x00u, (size_t)linker_lnHeap);

		vCrt0_randomSeed = seed;

		__stack_chk_guard = KSTACK_GUARD_VALUE;
	}

// Initialise the interruption and exception vectors
// Go to the main

	exce_init();
	init_relocate();
	exit(boot());
}

/*
 * \brief init_relocate
 *
 * - If necessary, in the module init.c there is the
 *	 vector table relocation
 *
 */
[[gnu::weak]]
void	init_relocate(void) {

}

/*
 * \brief __wrap___stack_chk_fail
 *
 * - Stack smashing detection
 *	 - Stop the system & display a message
 *
 * in the makefile add the following lines
 *
 *   CFLAGS  += -fstack-protector-strong
 *   LDFLAGS += -Wl,--wrap=__stack_chk_fail
 *
 */
[[noreturn]]
void	__wrap___stack_chk_fail(void) {

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	cmns_send(KSYST, "\nStack smashing!");
	exit(EXIT_OS_PANIC);
}

/*
 * \brief exit_terminate
 *
 * Same behaviour than exit(EXIT_OS_SUCCESS)
 * This call is used to properly terminate the process execution.
 *
 *
 * \note This function does not return a value (None).
 *
 */
[[noreturn]]
void	exit_terminate(void) {

	exit(EXIT_OS_SUCCESS);
}

/*
 * \brief crt0_exit
 *
 * code = EXIT_OS_SUCCESS				--->		Success, commit a suicide
 * code = EXIT_OS_FAILURE				--->		Failure; commit a suicide
 * code = EXIT_OS_PANIC					--->		Failure; panic. System is stopped
 * code = EXIT_OS_PANIC_MALLOC_BROKEN	--->		Failure; panic. System is stopped
 * code = EXIT_OS_PANIC_STACK_UNDERFLOW	--->		Failure; panic. System is stopped
 * code = EXIT_OS_PANIC_NO_SYSCALL		--->		Failure; panic. System is stopped
 * code = default						--->		Failure; panic. System is stopped
 *
 * \param[in]	number	Exit number
 *
 * \note This function does not return a value (None).
 *
 */
void	crt0_exit(int number) {

	switch (number) {
		case EXIT_OS_SUCCESS:
		case EXIT_OS_SUCCESS_CLI:
		case EXIT_OS_FAILURE:				 { local_killProcess();			break; }

		case EXIT_OS_PANIC_MALLOC_BROKEN:	 { local_panicMallocBroken();	break; }
		case EXIT_OS_PANIC_STACK_UNDERFLOW:  { local_panicStackUnderflow();	break; }
		case EXIT_OS_PANIC_NO_SYSCALL:		 { local_panicNoSystemCall();	break; }
		case EXIT_OS_PANIC_ELEVATION:		 { local_panicElevation();		break; }

		case EXIT_OS_PANIC:
		default:							 { local_panicGeneral();		break; }
	}

	cmns_send(KSYST, "\n");
	local_printTrace();
	local_printLog();
}

// Local routines
// ==============

/*
 * \brief local_killProcess
 *
 */
[[gnu::noinline, noreturn]]
static	void	local_killProcess(void) {
	proc_t	*process;

	kern_getProcessRun(&process);
	kern_killProcess(process);

// Important: do not remove the "while (true);"

	while (true) { ; }
}

/*
 * \brief local_panicMallocBroken
 *
 */
[[gnu::noinline]]
static	void	local_panicMallocBroken(void) {
	uint32_t	core;
	const		char_t	*identifier;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;

	cmns_send(KSYST, "\nPanic: memo_malloc descriptor broken!\nCurrent process: ");
	identifier = (vKern_runProc[core]->oSpecification.oIdentifier == nullptr) ? ("Anonymous") : (vKern_runProc[core]->oSpecification.oIdentifier);
	cmns_send(KSYST, identifier); cmns_send(KSYST, "\n");
}

/*
 * \brief local_panicStackUnderflow
 *
 */
[[gnu::noinline]]
static	void	local_panicStackUnderflow(void) {
			uint32_t	core;
			char_t		string[200 + 1];
	const	char_t		*identifier;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;

	cmns_send(KDEF0, "\nPanic: process stack underflow detected!\n");

	identifier = (vKern_runProc[core]->oSpecification.oIdentifier == nullptr) ? ("Anonymous") : (vKern_runProc[core]->oSpecification.oIdentifier);
	(void)snprintf(&string[0], 200u, "Current process:    %s\n", identifier);
	cmns_send(KDEF0, &string[0]);

	(void)snprintf(&string[0], 200u, "Process code entry: 0x%016"PRIXPTR"\n", (uintptr_t)vKern_runProc[core]->oSpecification.oCode);
	cmns_send(KDEF0, &string[0]);

	(void)snprintf(&string[0], 200u, "Start of Stack:     0x%016"PRIXPTR"\n", (uintptr_t)vKern_runProc[core]->oSpecification.oStackStart);
	cmns_send(KDEF0, &string[0]);

	#if (!defined(RV32IMAC_S))
	uintptr_t	value;

	value = core_getPSP();
	(void)snprintf(&string[0], 200u, "Current Stack PSP:  0x%016"PRIXPTR"\n", value);
	cmns_send(KDEF0, &string[0]);

	value = core_getMSP();
	(void)snprintf(&string[0], 200u, "Current Stack MSP:  0x%016"PRIXPTR"\n", value);
	cmns_send(KDEF0, &string[0]);
	#endif
}

/*
 * \brief local_panicNoSystemCall
 *
 */
[[gnu::noinline]]
static	void	local_panicNoSystemCall(void) {
			uint32_t	core;
	const	char_t		*identifier;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;

	cmns_send(KSYST, "\nPanic: The system call does not exist!\nCurrent process: ");
	identifier = (vKern_runProc[core]->oSpecification.oIdentifier == nullptr) ? ("Anonymous") : (vKern_runProc[core]->oSpecification.oIdentifier);
	cmns_send(KSYST, identifier); cmns_send(KSYST, "\n");
}

/*
 * \brief local_panicElevation
 *
 */
[[gnu::noinline]]
static	void	local_panicElevation(void) {

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;

	cmns_send(KSYST, "\nPanic: Elevation not allowed!\n");
}

/*
 * \brief local_panicGeneral
 *
 */
[[gnu::noinline]]
static	void	local_panicGeneral(void) {

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;

	cmns_send(KSYST, "\nPanic: system stopped!\n");
}

#include	"model_coreDump_tracing.c_inc"
