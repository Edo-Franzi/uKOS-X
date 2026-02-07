/*
; dumplog.
; ========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Display the log fifo captured with LOG().
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

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"dumplog      Dump the log buffer.                      (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Dump the log buffer\n"
									"===================\n\n"

									"This tool display the content of the log buffer\n\n"

									"Input format:  dumplog{[core]}\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	void		local_compose(const char_t *identifier, const char_t **idSpacer);

MODULE(
	Dumplog,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_DUMP_LOG,								// Module identifier (defined in the module.h)
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
			char_t				*dummy;
			uint64_t			olderTime;
			uint32_t			i;
			uint32_t			core;
			recordLogging_t		*logBuffer, *rLogBuffer, *rOldLogBuffer;
			bool				terminate = false;
	const	char_t				*category, *idSpacerI, *idSpacerF;

	UNUSED(argc);
	UNUSED(argv);

	(void)dprintf(KSYST, "Log dump.\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// dumptlog
// dumptlog 0
// dumptlog n

	switch (argc) {
		case 1u: {
			core = 0u;
			break;
		}
		case 2u: {
			core = (uint32_t)strtol(argv[1], &dummy, 10u);
			if (core >= KNB_CORES) {
				core = 0u;
			}
			break;
		}
		default: {
			core = 0u;
			break;
		}
	}

	PRIVILEGE_ELEVATE;

// Reserve the necessary memory

	logBuffer = (recordLogging_t *)memo_malloc(KMEMO_ALIGN_8, (KRECORD_SZ_LOG_BUF * sizeof(recordLogging_t)), "dumplog");
	if (logBuffer == nullptr) {
		(void)dprintf(KSYST, "Not enough memory.\n");
		PRIVILEGE_RESTORE;

		return (EXIT_OS_FAILURE);
	}

// Copy the buffer into a memory (to ensure the coherence between the buffer & the parameter)

	rLogBuffer = logBuffer;
	for (i = 0u; i < KRECORD_SZ_LOG_BUF; i++) {
		rLogBuffer->oLogCategory = KINFO_USER;
		rLogBuffer->oMark		 = false;
		rLogBuffer->oTimeStamp   = 0u;
		rLogBuffer->oFunction    = nullptr;
		rLogBuffer->oMessage     = nullptr;
		rLogBuffer->oLineNumber  = 0u;
		rLogBuffer->oIdentifier  = nullptr;
		rLogBuffer++;
	}

	kern_criticalSection(KENTER_CRITICAL);
	memcpy(logBuffer, vRecord_logBuffer[core], (KRECORD_SZ_LOG_BUF * sizeof(recordLogging_t)));
	kern_criticalSection(KEXIT_CRITICAL);

	(void)dprintf(KSYST, "Log provided by the core %"PRIu32"\n\n", core);
	(void)dprintf(KSYST, "      Time [us]  Category          Process or ISR identifier            Function                              Line   Information\n\n");

	if (logBuffer->oTimeStamp > 0u) {
		while (terminate == false) {
			rLogBuffer    = logBuffer;
			olderTime     = 0xFFFFFFFFFFFFFFFFu;
			rOldLogBuffer = nullptr;

			for (i = 0; i < KRECORD_SZ_LOG_BUF; i++) {

// Case where the buffer is not full

				if (rLogBuffer->oTimeStamp == 0u) {
					break;
				}

// If there is an older table entry not marked yet

				if ((rLogBuffer->oTimeStamp < olderTime) && (rLogBuffer->oMark == false)) {
					olderTime = rLogBuffer->oTimeStamp;
					rOldLogBuffer = rLogBuffer;
				}
				rLogBuffer++;
			}

// Verify if there is an entry to print
// Or terminate

			if (rOldLogBuffer != nullptr) {

				category = "Unknown         ";
				category = (rOldLogBuffer->oLogCategory == KFATAL_SYSTEM)    ? ("Fatal system    ") : (category);
				category = (rOldLogBuffer->oLogCategory == KFATAL_KERNEL)    ? ("Fatal kernel    ") : (category);
				category = (rOldLogBuffer->oLogCategory == KFATAL_MANAGER)   ? ("Fatal manager   ") : (category);
				category = (rOldLogBuffer->oLogCategory == KFATAL_USER)      ? ("Fatal user      ") : (category);

				category = (rOldLogBuffer->oLogCategory == KERROR_SYSTEM)    ? ("Error system    ") : (category);
				category = (rOldLogBuffer->oLogCategory == KERROR_KERNEL)    ? ("Error kernel    ") : (category);
				category = (rOldLogBuffer->oLogCategory == KERROR_MANAGER)   ? ("Error manager   ") : (category);
				category = (rOldLogBuffer->oLogCategory == KERROR_USER)      ? ("Error user      ") : (category);

				category = (rOldLogBuffer->oLogCategory == KWARNING_SYSTEM)  ? ("Warning system  ") : (category);
				category = (rOldLogBuffer->oLogCategory == KWARNING_KERNEL)  ? ("Warning kernel  ") : (category);
				category = (rOldLogBuffer->oLogCategory == KWARNING_MANAGER) ? ("Warning manager ") : (category);
				category = (rOldLogBuffer->oLogCategory == KWARNING_USER)    ? ("Warning user    ") : (category);

				category = (rOldLogBuffer->oLogCategory == KINFO_SYSTEM)     ? ("Info system     ") : (category);
				category = (rOldLogBuffer->oLogCategory == KINFO_KERNEL)     ? ("Info kernel     ") : (category);
				category = (rOldLogBuffer->oLogCategory == KINFO_MANAGER)    ? ("Info manager    ") : (category);
				category = (rOldLogBuffer->oLogCategory == KINFO_USER)       ? ("Info user       ") : (category);

				local_compose(rOldLogBuffer->oIdentifier, &idSpacerI);
				local_compose(rOldLogBuffer->oFunction,   &idSpacerF);

				(void)dprintf(KSYST, "%12"PRIu64"-us  %s  %s  %s  %s  %s  %5"PRIu32"   %s\n", rOldLogBuffer->oTimeStamp,	\
																							  category,						\
																							  rOldLogBuffer->oIdentifier,	\
																							  idSpacerI,					\
																							  rOldLogBuffer->oFunction,		\
																							  idSpacerF,					\
																							  rOldLogBuffer->oLineNumber,	\
																							  rOldLogBuffer->oMessage);

				rOldLogBuffer->oMark = true;
			}
			else {
				terminate = true;
			}
		}
		(void)dprintf(KSYST, "\n");
	}

	memo_delayedFree(logBuffer);
	PRIVILEGE_RESTORE;

	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

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

// --------------------------------------|-------------------------------|---
//                                      "Process_to_count_the_number_xyztu";
	static	const	char_t	aSpacer[] = "                                 ";

	len = strlen(identifier);
	*idSpacer = (len <= (sizeof(aSpacer) - 1u)) ? (&aSpacer[len]) : (&aSpacer[0]);
}
