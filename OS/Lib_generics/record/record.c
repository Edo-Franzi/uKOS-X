/*
; record.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		record manager.
;
; 			Management of the tracing & log
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
#include	"record/private/private_record.h"
#include	"kern/private/private_processes.h"

#if (defined(CONFIG_MAN_RECORD_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"record       record manager.                           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "record manager\n"
									"==============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Record,							// Module name (the first letter has to be upper case)
	KID_FAM_GENERICS,				// Family (defined in the module.h)
	KNUM_RECORD,					// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

typedef	enum {
			KCUMULATE = 0u,
			KSCANN
} recordAction_t;

recordLogging_t		vRecord_logBuffer[KNB_CORES][KRECORD_SZ_LOG_BUF];				// Buffer for log
recordTracing_t		vRecord_traceFifo[KNB_CORES][KRECORD_SZ_TRACE_FIFO];			// Fifo for the trace
recordTracing_t		*vRecord_RTraceFifo[KNB_CORES];									// Ptr (R) for the trace
recordTracing_t		*vRecord_WTraceFifo[KNB_CORES];									// Ptr (W) for the trace
uint32_t			vRecord_NbTraceWrites[KNB_CORES] = MCSET(0u);					// Number of writes in the fifo trace
uint32_t			vRecord_NbLogWrites[KNB_CORES]   = MCSET(0u);					// Number of writes in the buffer log

// Prototypes

static	int32_t	local_init(void);

/*
 * \brief Trace the code with a parameter
 *
 * Call example in C:
 *
 * \code{.c}
 *    record_trace(“Program call the routine _xyz\n”, 0x55);
 *    _xyz();
 *
 *    record_trace(“Program write\n”, 0x24);
 * \endcode
 *
 * \param[in]	*message			Ptr on the message
 * \param[in]	parameter			Parameter
 * \return		KERR_RECORD_NOERR	OK
 * \return		KERR_RECORD_SYCNA	System call not available
 *
 */
int32_t	record_trace(const char_t *message, uintptr_t parameter) {
			int32_t		status;
			uint32_t	core;
			uint64_t	timeStamp;
	static	bool		vRollOver[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_RECORD_NOERR) { PRIVILEGE_RESTORE; return (status); }

	INTERRUPTION_OFF;
	kern_readTickCount(&timeStamp);

	vRecord_WTraceFifo[core]->oMessage   = message;
	vRecord_WTraceFifo[core]->oParameter = parameter;
	vRecord_WTraceFifo[core]->oTimeStamp = timeStamp;
	vRecord_WTraceFifo[core]->oProcess   = (IS_EXCEPTION) ? (nullptr) : (vKern_runProc[core]);
	vRecord_WTraceFifo[core]++;

	vRecord_NbTraceWrites[core] = (vRecord_NbTraceWrites[core] == KRECORD_SZ_TRACE_FIFO) ? (KRECORD_SZ_TRACE_FIFO) : (vRecord_NbTraceWrites[core] + 1);

	vRollOver[core]			 = (vRecord_WTraceFifo[core] == &vRecord_traceFifo[core][KRECORD_SZ_TRACE_FIFO]) ? (true)						 : (vRollOver[core]);
	vRecord_WTraceFifo[core] = (vRecord_WTraceFifo[core] == &vRecord_traceFifo[core][KRECORD_SZ_TRACE_FIFO]) ? (&vRecord_traceFifo[core][0]) : (vRecord_WTraceFifo[core]);
	vRecord_RTraceFifo[core] = (vRollOver[core] == true)													 ? (vRecord_WTraceFifo[core])	 : (&vRecord_traceFifo[core][0]);
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_RECORD_NOERR);
}

/*
 * \brief Log trace
 *
 * Call example in C:
 *
 * \code{.c}
 *    record_log(KFATAL_SYSTEM, __LINE__, __fnct__, “Privilege violation”);
 *    _xyz();
 *
 *    The macro LOG allow to write
 *    LOG(KFATAL_SYSTEM, “Privilege violation”);
 *
 * \endcode
 *
 * \param[in]	logCategory			Log category
 * \param[in]	lineNumber			Line number (__LINE__)
 * \param[in]	*function			Ptr on the function (__func__)
 * \param[in]	*message			Ptr on the message
 * \return		KERR_RECORD_NOERR	OK
 * \return		KERR_RECORD_SYCNA	System call not available
 *
 */
int32_t	record_log(recordLogCategory_t logCategory, uint32_t lineNumber, const char_t *function, const char_t *message) {
			int32_t		status;
			recordLogCategory_t	lessPrioCategory;
			uint32_t		core, i, index;
			uint64_t		timeStamp, olderTime;
	static	recordAction_t	vAction[KNB_CORES] = MCSET(KCUMULATE);
	static	uint32_t		vIndex[KNB_CORES] = MCSET(0u);

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_RECORD_NOERR) { PRIVILEGE_RESTORE; return (status); }

	INTERRUPTION_OFF;
	kern_readTickCount(&timeStamp);
	timeStamp = (timeStamp == 0u) ? (1u) : (timeStamp);
	switch (vAction[core]) {
		case KCUMULATE: {

// As long as there is place in the table, fill it

			i = vIndex[core]++;
			vAction[core] = (vIndex[core] == KRECORD_SZ_LOG_BUF) ? (KSCANN) : (KCUMULATE);
			break;
		}
		case KSCANN: {

// Scann the log table to find a less priority category
// - if no less priority category entries, then, overwrite the last position of the table
// - if less priority category entries, then, continue the scann for looking for the oldest one

			index			 = (KRECORD_SZ_LOG_BUF - 1u);
			lessPrioCategory = logCategory;
			olderTime		 = 0xFFFFFFFFFFFFFFFFu;

			for (i = 0; i < KRECORD_SZ_LOG_BUF ; i++) {
				if (vRecord_logBuffer[core][i].oLogCategory >= lessPrioCategory) {
					if (vRecord_logBuffer[core][i].oLogCategory > lessPrioCategory) {
						olderTime = 0xFFFFFFFFFFFFFFFFu;
						lessPrioCategory = vRecord_logBuffer[core][i].oLogCategory;
					}

// At least one possible slot
// - For this category, consider the older one

					if (vRecord_logBuffer[core][i].oTimeStamp < olderTime) {
						olderTime = vRecord_logBuffer[core][i].oTimeStamp;
						index = i;
					}
				}
			}
			i = index;
			break;
		}
		default: {
			i = (KRECORD_SZ_LOG_BUF - 1u);
			break;
		}
	}

	vRecord_logBuffer[core][i].oLogCategory	= logCategory;
	vRecord_logBuffer[core][i].oTimeStamp	= timeStamp;
	vRecord_logBuffer[core][i].oFunction	= function;
	vRecord_logBuffer[core][i].oMessage		= message;
	vRecord_logBuffer[core][i].oLineNumber	= lineNumber;
	vRecord_logBuffer[core][i].oIdentifier	= (IS_EXCEPTION) ? ("From ISR") : (vKern_runProc[core]->oSpecification.oIdentifier);

	vRecord_NbLogWrites[core] += (vRecord_NbLogWrites[core] < KRECORD_SZ_LOG_BUF) ? (1u) : (0u);
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (KERR_RECORD_NOERR);
}

// Local routines
// ==============

/*
 * \brief local_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
static	int32_t	local_init(void) {
			int32_t		status = KERR_RECORD_NOERR;
			uint32_t	core, i;
	static	bool		vInit[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vInit[core] == false) {
		vInit[core] = true;

		vRecord_RTraceFifo[core] = &vRecord_traceFifo[core][0];
		vRecord_WTraceFifo[core] = &vRecord_traceFifo[core][0];

		for (i = 0u; i < KRECORD_SZ_LOG_BUF; i++) {
			vRecord_logBuffer[core][i].oLogCategory	= KINFO_USER;
			vRecord_logBuffer[core][i].oMark		= false;
			vRecord_logBuffer[core][i].oTimeStamp	= 0u;
			vRecord_logBuffer[core][i].oFunction	= nullptr;
			vRecord_logBuffer[core][i].oMessage		= nullptr;
			vRecord_logBuffer[core][i].oLineNumber	= 0u;
			vRecord_logBuffer[core][i].oIdentifier	= nullptr;
		}
	}
	RETURN_INT_RESTORE(status);
}

#endif
