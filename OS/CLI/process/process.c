/*
; process.
; ========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		List the installed processes.
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
#include	"kern/private/private_processes.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"process      List the installed processes.             (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "List the installed processes\n"
									"============================\n\n"

									"This tool displays some information concerning\n"
									"the installed processes.\n\n"

									"Input format:  process [-all | -noall]\n"
									"Output format: Process information\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

typedef	struct	process	process_t;

struct	process {
			bool		oValid;					// Process valid
			spec_t		oSpecification;			// Process specification
			work_t		oInternal;				// Process internal stuff
			stts_t		oStatistic;				// uKernel statistic
			uintptr_t	oPC;					// Process PC
		};

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	bool		local_getProcessByNb(uint8_t core, uint16_t number, proc_t **handle);
static	void		local_compose(const char_t *identifier, const char_t **idSpacer);
static	void		local_printParameter_P0(uint8_t core, uint16_t number, process_t *handle);
static	void		local_printParameter_P1(uint8_t core, uint16_t number, process_t *handle);
static	void		local_printParameter_N1(uint8_t core, uint16_t number, process_t *handle);
static	void		local_printParameter_S2(uint8_t core, uint16_t number, process_t *handle);

#if (KKERN_WITH_STATISTICS_S == true)
static	void		local_printParameter_T1(uint8_t core, uint16_t number, process_t *handle);
static	void		local_printParameter_T2(uint8_t core, uint16_t number, process_t *handle);
static	void		local_printParameter_T3(uint8_t core, uint16_t number, process_t *handle);

#if (KDAEMONS_WITH_STACK_INT_S == true)
static	void		local_printParameter_S0(uint8_t core, uint16_t number, process_t *handle);
#endif
#endif

MODULE(
	Process,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_PROCESS,								// Module identifier (defined in the module.h)
	NULL,										// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,										// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

static	uint64_t	vTotalTimeCPU[KNB_CORES] = MCSET(0u);

#if (KNB_CORES > 1)
static	spinlock_t	vProcess = SPIN_LOCK_INIT;
#endif

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
			bool		equals;
			enum		{ KALL, KALL_NOT } all = KALL;
			enum		{ KERR_NOT, KERR_PAR, KERR_MEM } error = KERR_NOT;
			int32_t		status;
			uint16_t	i;
			uint8_t		*bufSysProcess, j;
			process_t	*sysProcess;
			proc_t		*process;
	const	char_t		*functionName;

	(void)dprintf(KSYST, "List of the system processes.\n");

	PRIVILEGE_ELEVATE;

// Analyse the command line
// ------------------------
//
// Example:
//
// process
// process -all
// process -noall

	switch (argc) {
		case 1u: {
			all = KALL_NOT;
			break;
		}
		case 2u: {
			text_checkAsciiBuffer(argv[1], "-noall", &equals); if (equals == true) { all = KALL_NOT; break; }
			text_checkAsciiBuffer(argv[1], "-all",   &equals); if (equals == true) { all = KALL;	 break; }
			error = KERR_PAR;
			break;
		}
		default: {
			error = KERR_PAR;
			break;
		}
	}

	switch (error) {
		case KERR_NOT: {

// Collect the process information usable for the statistics

			bufSysProcess = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, ((size_t)KNB_CORES * (size_t)KKERN_NB_PROCESSES * sizeof(process_t)), "process");
			if (bufSysProcess != NULL) {

				SPIN_LOCK(vProcess);
				kern_criticalSection(KENTER_CRITICAL);
				for (j = 0u; j < KNB_CORES; j++) {
					vTotalTimeCPU[j] = 0u;
					for (i = 0u; i < KKERN_NB_PROCESSES; i++) {
						sysProcess = (process_t *)((uintptr_t)bufSysProcess + ((uintptr_t)j * KKERN_NB_PROCESSES * sizeof(process_t)) + ((uintptr_t)i * sizeof(process_t)));
						sysProcess->oValid = false;
						if (local_getProcessByNb(j, i, &process) == true) {
							sysProcess->oValid = true;

							sysProcess->oSpecification.oIdentifier = process->oSpecification.oIdentifier;
							sysProcess->oSpecification.oText       = process->oSpecification.oText;
							sysProcess->oSpecification.oPriority   = process->oSpecification.oPriority;
							sysProcess->oSpecification.oMode       = process->oSpecification.oMode;

							sysProcess->oInternal.oState           = process->oInternal.oState;
							sysProcess->oInternal.oProcFather	   = process->oInternal.oProcFather;

							sysProcess->oStatistic.oNbExecutions   = process->oStatistic.oNbExecutions;
							sysProcess->oStatistic.oNbKernCalls    = process->oStatistic.oNbKernCalls;

							#if (KKERN_WITH_STATISTICS_S == true)

							#if (KDAEMONS_WITH_STACK_INT_S == true)
							sysProcess->oStatistic.oAvStack        = process->oStatistic.oAvStack;
							#endif

							sysProcess->oStatistic.oTimePMin       = process->oStatistic.oTimePMin;
							sysProcess->oStatistic.oTimePMax       = process->oStatistic.oTimePMax;
							sysProcess->oStatistic.oTimePAvg       = process->oStatistic.oTimePAvg;
							sysProcess->oStatistic.oTimeKMin       = process->oStatistic.oTimeKMin;
							sysProcess->oStatistic.oTimeKMax       = process->oStatistic.oTimeKMax;
							sysProcess->oStatistic.oTimeKAvg       = process->oStatistic.oTimeKAvg;
							sysProcess->oStatistic.oTimeEMin       = process->oStatistic.oTimeEMin;
							sysProcess->oStatistic.oTimeEMax       = process->oStatistic.oTimeEMax;
							sysProcess->oStatistic.oTimeEAvg       = process->oStatistic.oTimeEAvg;
							#endif

							if (vKern_runProc[j]->oSpecification.oStack != process->oSpecification.oStack) {
								machine_readPC(process, &sysProcess->oPC);
							}
							else {
								sysProcess->oPC = 0u;
							}

							#if (KKERN_WITH_STATISTICS_S == true)
							vTotalTimeCPU[j] += ((uint64_t)sysProcess->oStatistic.oTimePAvg + \
												 (uint64_t)sysProcess->oStatistic.oTimeKAvg + \
												 (uint64_t)sysProcess->oStatistic.oTimeEAvg) * sysProcess->oStatistic.oNbExecutions;
							#endif

						}
					}
				}
				kern_criticalSection(KEXIT_CRITICAL);
				SPIN_UNLOCK(vProcess);

// Compute the statistic in % of time CPU
// Print the string process

				for (j = 0u; j < KNB_CORES; j++) {
					if (all == KALL_NOT) {

						#if (KKERN_WITH_STATISTICS_S == true)
						if (j >= 1u) { (void)dprintf(KSYST, "\n"); }
						(void)dprintf(KSYST, " #  Process information of the core %d                        State        Used CPU in %%         PC\n\n", j);

						#else
						if (j >= 1u) { (void)dprintf(KSYST, "\n"); }
						(void)dprintf(KSYST, " #  Process information of the core %d                        State        PC\n\n", j);
						#endif

					}
					else {
						(void)dprintf(KSYST, "Process details of the core %d\n\n", j);
					}

					for (i = 0u; i < KKERN_NB_PROCESSES; i++) {
						sysProcess = (process_t *)((uintptr_t)bufSysProcess + ((uintptr_t)j * KKERN_NB_PROCESSES * sizeof(process_t)) + ((uintptr_t)i * sizeof(process_t)));
						if (sysProcess->oValid == true) {
							if (all == KALL_NOT) {

								local_printParameter_P0(j, i, sysProcess);

								if (sysProcess->oPC != 0u) {
									machine_readFunctionName(sysProcess->oPC, &functionName);
									if (functionName == NULL) { (void)dprintf(KSYST, " - PC = 0x%016"PRIXPTR"\n",    sysProcess->oPC);               }
									else {                      (void)dprintf(KSYST, " - PC = 0x%016"PRIXPTR" %s\n", sysProcess->oPC, functionName); }
								}
								else {
									(void)dprintf(KSYST, "\n");
								}
							}
							else {
								local_printParameter_P1(j, i, sysProcess);

								#if (KKERN_WITH_STATISTICS_S == true)
								local_printParameter_T1(j, i, sysProcess);
								local_printParameter_T2(j, i, sysProcess);
								local_printParameter_T3(j, i, sysProcess);

								#if (KDAEMONS_WITH_STACK_INT_S == true)
								local_printParameter_S0(j, i, sysProcess);
								#endif

								#endif

								local_printParameter_N1(j, i, sysProcess);
								local_printParameter_S2(j, i, sysProcess);
							}
						}
					}
				}
				memo_delayedFree(bufSysProcess);
			}
			else {
				error = KERR_MEM;
			}
			break;
		}
		default: {
			error = KERR_PAR;
			break;
		}
	}

	switch (error) {
		case KERR_NOT: {
			if (all == KALL_NOT) {
				(void)dprintf(KSYST, "\n");
			}
																		   status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_MEM: { (void)dprintf(KSYST, "Not enough memory.\n\n");   status = EXIT_OS_FAILURE;     break; }
		case KERR_PAR: { (void)dprintf(KSYST, "Incorrect arguments.\n\n"); status = EXIT_OS_FAILURE;     break; }
		default:	   {												   status = EXIT_OS_FAILURE;     break; }
	}

	PRIVILEGE_RESTORE;
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_getProcessByNb
 *
 * - Get the handle of a process by its number & core
 *
 */
static	bool	local_getProcessByNb(uint8_t core, uint16_t number, proc_t **handle) {

	kern_criticalSection(KENTER_CRITICAL);
	*handle = NULL;

	if (number >= KKERN_NB_PROCESSES)											   { kern_criticalSection(KEXIT_CRITICAL); return (false); }
	if ((vKern_proc[core][number].oInternal.oState & (1u<<BPROC_INSTALLED)) == 0u) { kern_criticalSection(KEXIT_CRITICAL); return (false); }

	*handle = &vKern_proc[core][number];
	kern_criticalSection(KEXIT_CRITICAL);
	return (true);
}

/*
 * \brief local_printParameter_XYZ
 *
 * - Print a parameter P(riority), T(imes) & N(umbers) ..
 *
 */
static	void	local_printParameter_P0(uint8_t core, uint16_t number, process_t *handle) {

			#if (KKERN_WITH_STATISTICS_S == true)
			uint64_t	pRatio, kRatio, eRatio;
			float64_t	pRatioF, kRatioF, eRatioF;
			float64_t	sum;

			#else
			UNUSED(core);
			#endif

	const	char_t		*idSpacer;

	#if (KKERN_WITH_STATISTICS_S == true)
	pRatio = handle->oStatistic.oTimePAvg * handle->oStatistic.oNbExecutions * 100u;
	kRatio = handle->oStatistic.oTimeKAvg * handle->oStatistic.oNbExecutions * 100u;
	eRatio = handle->oStatistic.oTimeEAvg * handle->oStatistic.oNbExecutions * 100u;

	pRatioF = (float64_t)pRatio / (float64_t)vTotalTimeCPU[core];
	kRatioF = (float64_t)kRatio / (float64_t)vTotalTimeCPU[core];
	eRatioF = (float64_t)eRatio / (float64_t)vTotalTimeCPU[core];
	sum = pRatioF + kRatioF + eRatioF;
	#endif

	local_compose(handle->oSpecification.oText, &idSpacer);

	if (((handle->oInternal.oState & (1u<<BPROC_SUSP_TIME)) != 0u) && ((handle->oInternal.oState & (1u<<BPROC_SUSP_DEBG)) == 0u)) {
		(void)dprintf(KSYST, "%2d  %s%s - Susp. time", number, handle->oSpecification.oText, idSpacer);

		#if (KKERN_WITH_STATISTICS_S == true)
		(void)dprintf(KSYST, " - used CPU %6.2f [%%]", sum);
		#endif

		return;
	}

	if (((handle->oInternal.oState & (1u<<BPROC_SUSP_SIGN)) != 0u) && ((handle->oInternal.oState & (1u<<BPROC_SUSP_DEBG)) == 0u)) {
		(void)dprintf(KSYST, "%2d  %s%s - Susp. sign", number, handle->oSpecification.oText, idSpacer);

		#if (KKERN_WITH_STATISTICS_S == true)
		(void)dprintf(KSYST, " - used CPU %6.2f [%%]", sum);
		#endif

		return;
	}

	if (((handle->oInternal.oState & (1u<<BPROC_SUSP_SEMA)) != 0u) && ((handle->oInternal.oState & (1u<<BPROC_SUSP_DEBG)) == 0u)) {
		(void)dprintf(KSYST, "%2d  %s%s - Susp. sema", number, handle->oSpecification.oText, idSpacer);

		#if (KKERN_WITH_STATISTICS_S == true)
		(void)dprintf(KSYST, " - used CPU %6.2f [%%]", sum);
		#endif

		return;
	}

	if (((handle->oInternal.oState & (1u<<BPROC_SUSP_MBOX_E)) != 0u) && ((handle->oInternal.oState & (1u<<BPROC_SUSP_DEBG)) == 0u)) {
		(void)dprintf(KSYST, "%2d  %s%s - Susp. mboE", number, handle->oSpecification.oText, idSpacer);

		#if (KKERN_WITH_STATISTICS_S == true)
		(void)dprintf(KSYST, " - used CPU %6.2f [%%]", sum);
		#endif

		return;
	}

	if (((handle->oInternal.oState & (1u<<BPROC_SUSP_MBOX_F)) != 0u) && ((handle->oInternal.oState & (1u<<BPROC_SUSP_DEBG)) == 0u)) {
		(void)dprintf(KSYST, "%2d  %s%s - Susp. mboF", number, handle->oSpecification.oText, idSpacer);

		#if (KKERN_WITH_STATISTICS_S == true)
		(void)dprintf(KSYST, " - used CPU %6.2f [%%]", sum);
		#endif

		return;
	}

	if ((handle->oInternal.oState & (1u<<BPROC_SUSP_DEBG)) != 0u) {
		(void)dprintf(KSYST, "%2d  %s%s - Freezed   ", number, handle->oSpecification.oText, idSpacer);

		#if (KKERN_WITH_STATISTICS_S == true)
		(void)dprintf(KSYST, " - used CPU %6.2f [%%]", sum);
		#endif

		return;
	}

	if ((handle->oInternal.oState & (1u<<BPROC_RUNNING)) != 0u) {
		(void)dprintf(KSYST, "%2d  %s%s - Running   ", number, handle->oSpecification.oText, idSpacer);

		#if (KKERN_WITH_STATISTICS_S == true)
		(void)dprintf(KSYST, " - used CPU %6.2f [%%]", sum);
		#endif

		return;
	}

		(void)dprintf(KSYST, "%2d  %s%s - Scheduled ", number, handle->oSpecification.oText, idSpacer);

		#if (KKERN_WITH_STATISTICS_S == true)
		(void)dprintf(KSYST, " - used CPU %6.2f [%%]", sum);
		#endif
}

static	void	local_printParameter_P1(uint8_t core, uint16_t number, process_t *handle) {
	const	char_t	*space, *father;

	UNUSED(core);

	father = (handle->oInternal.oProcFather == NULL)	  ? ("Orphan") : (handle->oInternal.oProcFather->oSpecification.oIdentifier);
	space  = (handle->oSpecification.oMode == KPROC_USER) ? ("User")   : ("Privileged");

	(void)dprintf(KSYST, "Process identifier: %d %s\n", number, handle->oSpecification.oIdentifier);
	(void)dprintf(KSYST, "Process text:       %s\n",    handle->oSpecification.oText);
	(void)dprintf(KSYST, "Process father:     %s\n",    father);
	(void)dprintf(KSYST, "Process space:      %s\n",    space);
	(void)dprintf(KSYST, "Process priority:   %2d\n",   handle->oSpecification.oPriority);
}

#if (KKERN_WITH_STATISTICS_S == true)
static	void	local_printParameter_T1(uint8_t core, uint16_t number, process_t *handle) {
	uint64_t	ratio;
	float64_t	ratioF;

	UNUSED(number);

	ratio  = handle->oStatistic.oTimePAvg * handle->oStatistic.oNbExecutions * 100u;
	ratioF = (float64_t)ratio / (float64_t)vTotalTimeCPU[core];

	(void)dprintf(KSYST, "CPU time used by the process,    min: %5d [us] max: %5d [us] avg: %5d [us] %7.3f [%%]\n",
						 handle->oStatistic.oTimePMin, handle->oStatistic.oTimePMax, handle->oStatistic.oTimePAvg, ratioF);
}

static	void	local_printParameter_T2(uint8_t core, uint16_t number, process_t *handle) {
	uint64_t	ratio;
	float64_t	ratioF;

	UNUSED(number);

	ratio  = handle->oStatistic.oTimeKAvg * handle->oStatistic.oNbExecutions * 100u;
	ratioF = (float64_t)ratio / (float64_t)vTotalTimeCPU[core];

	(void)dprintf(KSYST, "CPU time used by the uKernel,    min: %5d [us] max: %5d [us] avg: %5d [us] %7.3f [%%]\n",
						 handle->oStatistic.oTimeKMin, handle->oStatistic.oTimeKMax, handle->oStatistic.oTimeKAvg, ratioF);
}

static	void	local_printParameter_T3(uint8_t core, uint16_t number, process_t *handle) {
	uint64_t	ratio;
	float64_t	ratioF;

	UNUSED(number);

	ratio  = handle->oStatistic.oTimeEAvg * handle->oStatistic.oNbExecutions * 100u;
	ratioF = (float64_t)ratio / (float64_t)vTotalTimeCPU[core];

	(void)dprintf(KSYST, "CPU time used by the exceptions, min: %5d [us] max: %5d [us] avg: %5d [us] %7.3f [%%]\n",
						 handle->oStatistic.oTimeEMin, handle->oStatistic.oTimeEMax, handle->oStatistic.oTimeEAvg, ratioF);
}

#if (KDAEMONS_WITH_STACK_INT_S == true)
static	void	local_printParameter_S0(uint8_t core, uint16_t number, process_t *handle) {

	UNUSED(core);
	UNUSED(number);

	if (handle->oStatistic.oAvStack != 0xFFFFFFFFu) {
		(void)dprintf(KSYST, "Available stack size:                        %-"PRIu32" [Bytes]\n", handle->oStatistic.oAvStack);
	}
	else {
		(void)dprintf(KSYST, "Available stack size not updated yet!\n");
	}
}
#endif
#endif

static	void	local_printParameter_N1(uint8_t core, uint16_t number, process_t *handle) {

	UNUSED(core);
	UNUSED(number);

	(void)dprintf(KSYST, "Nb of time that the process was scheduled:   %-lld\n", handle->oStatistic.oNbExecutions);
}

static	void	local_printParameter_S2(uint8_t core, uint16_t number, process_t *handle) {

	UNUSED(core);
	UNUSED(number);

	(void)dprintf(KSYST, "Nb of system calls to the uKernel functions: %-lld\n\n", handle->oStatistic.oNbKernCalls);
}

/*
 * \brief local_compose
 *
 * - input:  "1234567"
 * - output: "     "
 * - to accommodate "1234567     "
 * -                "            "
 *
 * \param[in]	*string		Ptr on a string
 * \param[out]	**spacer	Ptr on the final space
 *
 * \note This function does not return a value (None).
 *
 */
static	void	local_compose(const char_t *identifier, const char_t **idSpacer) {
	size_t	len;

// --------------------------------------|----------------------------------------------------|---
//                                      "Process xyz: this process ...             (c) EFr-2025";
	static	const	char_t	aSpacer[] = "                                                      ";

	len = strlen(identifier);
	*idSpacer = (len <= (sizeof(aSpacer) - 1u)) ? (&aSpacer[len]) : (&aSpacer[0]);
}
