/*
; cycle.
; ======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		cycle tool; launch a program cyclically.
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

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"cycle        Cycle function.                           (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "cycle\n"
									"=====\n\n"

									"This tool launches cyclically a tool/program\n"
									"or a protocol.\n"

									"The -stop without parameters kill the KURT0 session\n\n"

									"Input format:  cycle {nbRep {0..n, -1 infinity} time serialManager {urt0 | ...} prgmName [p0 p1 pn]}\n"
									"Input format:  cycle -stop [commDevice]\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	int32_t		cycle_clean(uint32_t argc, const char_t *argv[]);
static	void		local_process(const void *argument);
static	bool		local_getIndex(serialManager_t serialManager, uint16_t *index);

MODULE(
	Cycle,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_CYCLE,									// Module identifier (defined in the module.h)
	NULL,										// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	cycle_clean,								// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

typedef	struct	cycle		cycle_t;
typedef	struct	cyclePack	cyclePack_t;

struct	cycle {
				serialManager_t		oSerialManager;									// Serial Communication Manager
		const	char_t				*oIdentifier;									// Ptr on the process identifier
		const	char_t				*oText;											// Ptr on the process identifier text
		};

struct	cyclePack {
				bool				*oKillRequest;									// Kill request
				int32_t				oNbRep;											// Number of repetitions
				serialManager_t		oSerialManager;									// Serial Communication Manager
				uint32_t			oTime;											// Cyclic time
				uint32_t			oArgc;											// argc of the command line
		const	char_t				**oArgv;										// argv of the command line
				int32_t				(*oTool)(uint32_t argc, const char_t *argv[]);	// The tool to call cyclically
				bool				*oReleasePack;									// Release the pack
		};

// -----------------------------------------------------I-----------------------------------------I--------------I

static	const	cycle_t		aTabCycle[] = {
								{ KSYST, "Cycle_syst", "Process cycle syst.                       (c) EFr-2025" },
								{ KURT0, "Cycle_urt0", "Process cycle urt0.                       (c) EFr-2025" },
								{ KURT1, "Cycle_urt1", "Process cycle urt1.                       (c) EFr-2025" },
								{ KURT2, "Cycle_urt2", "Process cycle urt2.                       (c) EFr-2025" },
								{ KURT3, "Cycle_urt3", "Process cycle urt3.                       (c) EFr-2025" },
								{ KURT4, "Cycle_urt4", "Process cycle urt4.                       (c) EFr-2025" },
								{ KCDC0, "Cycle_cdc0", "Process cycle cdc0.                       (c) EFr-2025" },
								{ KCDC1, "Cycle_cdc1", "Process cycle cdc1.                       (c) EFr-2025" },
								{ KWFI0, "Cycle_wfi0", "Process cycle wfi0.                       (c) EFr-2025" }
							};

#define	KNB_CHANNELS	(sizeof(aTabCycle) / sizeof(cycle_t))

static	proc_t	*vProcess[KNB_CORES][KNB_CHANNELS];
static	bool	vKillRequest[KNB_CORES] = MCSET(false);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
			uint32_t			core;
			char_t				*dummy;
			uint16_t			indexModule, indexSerialManager = 0u;
			int32_t				status, nbRep = 0;
			enum				{ KERR_NOT, KERR_INA, KERR_PNE, KERR_CAU, KERR_PRO, KERR_TER } error = KERR_NOT;
			enum				{ KMOD_INA, KMOD_FUL, KMOD_PNE, KMOD_STP } mode = KMOD_INA;
			uint32_t			time = 0;
			serialManager_t		serialManager = KURT0;
			cyclePack_t			pack;
			bool				stop = false, releasePack = false;
	const	uKOS_module_t		*module = NULL;

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;
	vKillRequest[core] = false;

	(void)dprintf(KSYST, "Run cyclically.\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// cycle -stop (it always stops the urt0 session)
// cycle -stop urt3
// cycle 34 1000 urt0 process -all
// cycle 12 1000 urt0 dump 20000000 20001000
// cycle -1 1000 urt0 memory

// Analyse the command line and determine the mode
// 	- Case of the -stop
// 	- Case of the -stop commDevice
// 	- Normal case, cycle xx yyyy zzzz tool

	switch (argc) {
		case 1:
		case 4: {
			mode = KMOD_INA;
			break;
		}
		case 2: {
			text_checkAsciiBuffer(argv[1], "-stop",  &stop);
			if (stop == true) {
				serialManager = KURT0;
				if (local_getIndex(serialManager, &indexSerialManager) == true) {
					mode = KMOD_STP;
				}
			}
			break;
		}
		case 3: {
			text_checkAsciiBuffer(argv[1], "-stop",  &stop);
			if (stop == true) {
				serialManager = (serialManager_t)(GET_PTR_32(argv[2]));
				if (local_getIndex(serialManager, &indexSerialManager) == true) {
					mode = KMOD_STP;
				}
			}
			break;
		}
		default: {
			nbRep = (int32_t) strtol(argv[1], &dummy, 10u);
			time  = (uint32_t)strtol(argv[2], &dummy, 10u);

			serialManager = (serialManager_t)(GET_PTR_32(argv[3]));
			if (local_getIndex(serialManager, &indexSerialManager) == true) {
				if (system_getModuleName(argv[4], &indexModule, &module) != KERR_SYSTEM_NOERR) {
					mode = KMOD_PNE;
				}
				else {
					mode = KMOD_FUL;
				}
			}
			break;
		}
	}

// Analyse the mode
// 	- Normal case, cycle xx yyyy zzzz tool
//	- Stop case (-stop)
//	- Stop case (-stop serialManager)
//	- The selected tool does not exist
//	- Probably an incorrect arguments

	switch (mode) {
		case KMOD_FUL: {
			pack.oKillRequest   = &vKillRequest[core];
			pack.oNbRep		    = nbRep;
			pack.oSerialManager = serialManager;
			pack.oTime		    = time;
			pack.oTool		    = module->oExecution;

// Remove the unused parameters (x)
//
// xxxxx xxxx xxxx xxxx
// cycle 234  1000 urt0 process -all

			pack.oArgc		  = argc - 4u;
			pack.oArgv		  = &argv[4];
			pack.oReleasePack = &releasePack;

			PROCESS_STACKMALLOC(
				0,											// Index
				specification,								// Specifications (just use specification_x)
				aTabCycle[indexSerialManager].oText,		// Info string (NULL if anonymous)
				KKERN_SZ_STACK_LL,							// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
				local_process,								// Code of the process
				aTabCycle[indexSerialManager].oIdentifier,	// Identifier (NULL if anonymous)
				serialManager,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
				KKERN_PRIORITY_NORMAL_01					// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
			);

			if (vProcess[core][indexSerialManager] == NULL) {
				if (kern_createProcess(&specification, &pack, &vProcess[core][indexSerialManager]) != KERR_KERN_NOERR) {
					error = KERR_PRO;
				}
			}
			else {
				error = KERR_CAU;
			}
			break;
		}
		case KMOD_STP: {
			if (vProcess[core][indexSerialManager] != NULL) {
				kern_killProcess(vProcess[core][indexSerialManager]);
				vProcess[core][indexSerialManager] = NULL;
				error = KERR_TER;
			}
			else {
				error = KERR_INA;
			}
			break;
		}
		case KMOD_PNE: {
			error = KERR_PNE;
			break;
		}
		case KMOD_INA:
		default: {
			error = KERR_INA;
			break;
		}
	}

	switch (error) {
		case KERR_NOT: { (void)dprintf(KSYST, "Process launched.\n\n");					   status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_TER: { (void)dprintf(KSYST, "Cycle terminated.\n\n");					   status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_PRO: { (void)dprintf(KSYST, "Cannot create the cycle process.\n\n");	   status = EXIT_OS_FAILURE;     break; }
		case KERR_INA: { (void)dprintf(KSYST, "Incorrect arguments.\n\n");				   status = EXIT_OS_FAILURE;     break; }
		case KERR_PNE: { (void)dprintf(KSYST, "The selected program does not exist.\n\n"); status = EXIT_OS_FAILURE;     break; }
		case KERR_CAU: { (void)dprintf(KSYST, "Cycle already in use.\n\n");				   status = EXIT_OS_FAILURE;     break; }
		default:	   {																   status = EXIT_OS_FAILURE;     break; }
	}

// Let the time to the process "local_process" to run

	do { kern_suspendProcess(1u); } while ((releasePack == false) && (error == KERR_NOT));
	return (status);
}

/*
 * \brief cycle_clean
 *
 * - Try to clean the ressources
 *		- Free all the ressources
 *
 */
static	int32_t	cycle_clean(uint32_t argc, const char_t *argv[]) {
	uint32_t	core;

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;
	vKillRequest[core] = true;

	return (EXIT_OS_SUCCESS);
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - Launch a cycle
 *
 */
static void __attribute__ ((noreturn)) local_process(const void *argument) {
			uint32_t			core, time, argc;
			serialManager_t		serialManager;
			uint16_t			indexSerialManager;
			int32_t				nbRep;
			int32_t				(*code)(uint32_t argc, const char_t *argv[]);
			proc_t				*process;
			bool				*releasePack;
	const	bool				*killRequest;
	const	char_t				**argv;
	const	cyclePack_t			*pack;

	core = GET_RUNNING_CORE;
	kern_getProcessRun(&process);

// Recover the process arguments

	pack = (const cyclePack_t *)argument;
	serialManager = pack->oSerialManager;

	kern_setSerialForProcess(process, serialManager);
	local_getIndex(serialManager, &indexSerialManager);

	killRequest	 = pack->oKillRequest;
	code		 = pack->oTool;
	nbRep		 = pack->oNbRep;
	time		 = pack->oTime;
	argc		 = pack->oArgc;
	argv		 = pack->oArgv;
	releasePack	 = pack->oReleasePack;
	*releasePack = true;

	while ((*killRequest == false) && (nbRep != 0u)) {
		kern_suspendProcess(time);
		if ((*code)(argc, argv) != EXIT_OS_SUCCESS_CLI) { break; }
		nbRep = (nbRep == -1) ? (nbRep) : (nbRep - 1);
	}

// Kill the process & the ressources

	system_release(KMODE_READ_WRITE);
	vProcess[core][indexSerialManager] = NULL;
	vKillRequest[core] = false;
	(void)dprintf(KSYST, "Cycle terminated.\n\n");
	exit(EXIT_OS_SUCCESS);
}

/*
 * \brief local_getIndex
 *
 * - Get the index of the table f(serialManager)
 *
 */
static	bool	local_getIndex(serialManager_t serialManager, uint16_t *index) {
	uint8_t	i;

	*index = 0u;
	for (i = 0u; i < (uint8_t)KNB_CHANNELS; i++) {
		if (aTabCycle[i].oSerialManager == serialManager) {
			*index = i;
			return (true);
		}

	}
	return (false);
}
