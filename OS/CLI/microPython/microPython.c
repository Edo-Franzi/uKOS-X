/*
; microPython.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
;			uKOS-X interface for MicroPython (www.micropython.com).
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

#if (defined(CONFIG_MAN_MICROPYTHON_S))

#include	"uKOS.h"
#include	"MicroPython/Construction/System/microPython.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"microPython  MicroPython for uKOS-X.                   (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "MicroPython Embedded for uKOS-X\n"
									"=================================\n\n"

									"This tool allows to use MicroPython\n"
									" (www.micropython.com) in the uKOS-X workspace.\n\n"

									"Input format:  microPython {serialManager [urt0 | ... ] memorySize}\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	MicroPython,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,										// Family (defined in the module.h)
	KNUM_WK_MICROPYTHON,								// Module identifier (defined in the module.h)
	nullptr,											// Address of the initialisation code (early pre-init)
	prgm,												// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,											// Address of the clean code (clean the module)
	" 1.0",												// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0													// Execution cores
);

// CLI tool specific
// =================

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Process_MicroPython";
STRG_LOC_CONST(aStrText[]) = "Process MicroPython (micropython.com)     (c) EFr-2026";

typedef	struct	microPythonPack	microPythonPack_t;

struct	microPythonPack {
			serialManager_t		oCLISerialManager;		// Serial Communication Manager (CLI process)
			serialManager_t		oMPYSerialManager;		// Serial Communication Manager (MPY process)
			uint32_t			oMPYSize;				// Size of the mpy memory
			uint8_t				*oMPYMemory;			// Ptr on the memory location for mpy
			bool				*oReleasePack;			// Release the pack
		};

// Prototypes

static	void	local_process(const void *argument);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	char_t				*dummy;
	uint8_t				*MPYMemory = nullptr;
	int32_t				status;
	uint32_t			MPYSize;
	serialManager_t		MPYSerialManager = KSYST, CLISerialManager = KSYST;
	enum				{ KERR_NOT, KERR_INA, KERR_NME, KERR_LOK } error = KERR_NOT;
	microPythonPack_t	pack;
	bool				releasePack = false;
	proc_t				*MPYProcess, *CLIProcess;

	(void)dprintf(KSYST, "MicroPython launcher.\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// microPython urt1 62000	use the urt1 for the prompt
//							microPython workspace of 62000-byte

	switch (argc) {
		case 3u: {
			MPYSerialManager = (serialManager_t)(GET_PTR_32(argv[1]));
			break;
		}
		default: {
			error = KERR_INA;
			break;
		}
	}

// Only 1 microPython session at time
// Try to reserve the MPY memory segment

	if (error == KERR_NOT) {
		MPYSize   = (uint32_t)strtoul(argv[2], &dummy, 10u);
		MPYMemory = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (MPYSize * sizeof(uint8_t)), "mpy");
		error = (MPYMemory == nullptr) ? (KERR_NME) : (error);

		kern_getProcessRun(&CLIProcess);
		kern_getSerialForProcess(CLIProcess, &CLISerialManager);

		pack.oCLISerialManager	= CLISerialManager;
		pack.oMPYSerialManager	= MPYSerialManager;
		pack.oMPYSize			= MPYSize;
		pack.oMPYMemory			= MPYMemory;
		pack.oReleasePack		= &releasePack;

		PROCESS_STACKMALLOC(
			0,									// Index
			specification,						// Specifications (just use specification_x)
			aStrText,							// Info string (nullptr if anonymous)
			KKERN_SZ_STACK_MPY,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
			local_process,						// Code of the process
			aStrIden,							// Identifier (nullptr if anonymous)
			MPYSerialManager,					// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
			KKERN_PRIORITY_HIGH_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
		);

		if (kern_createProcess(&specification, &pack, &MPYProcess) != KERR_KERN_NOERR) { error = KERR_LOK; }
	}

	switch (error) {
		case KERR_NOT: {																					status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_LOK: { memo_free(MPYMemory); (void)dprintf(KSYST, "microPython session is running.\n\n"); status = EXIT_OS_FAILURE;     break; }
		case KERR_INA: {					   (void)dprintf(KSYST, "Incorrect arguments.\n\n");			status = EXIT_OS_FAILURE;     break; }
		case KERR_NME: {					   (void)dprintf(KSYST, "Not enough memory.\n\n");				status = EXIT_OS_FAILURE;     break; }
		default:	   {																					status = EXIT_OS_FAILURE;     break; }
	}

// Let the time to the process "local_process" to run

	do { kern_suspendProcess(1u); } while ((releasePack == false) && (error == KERR_NOT));
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - Process_MicroPython: - until "quit"
 *  					  - Analyse the command line
 *						  - Execute the command
 *
 */
static void __attribute__ ((noreturn)) local_process(const void *argument) {
			microPythonCnf_t	configure;
			bool				*releasePack;
			serialManager_t		MPYSerialManager = KSYST, CLISerialManager = KSYST;
			proc_t				*process;
	const	microPythonPack_t	*pack;

	kern_getProcessRun(&process);

// Recover the process arguments

	pack = (const microPythonPack_t *)argument;

	CLISerialManager  = pack->oCLISerialManager;
	MPYSerialManager  = pack->oMPYSerialManager;
	configure.oSize	  = pack->oMPYSize;
	configure.oMemory = pack->oMPYMemory;
	releasePack		  = pack->oReleasePack;

// If the serialManager of the microPython is the same of the serialManager of the console,
// then, do not release the console (to avoid to have a mix between microPython and console).
// In this case, the release will be done when we leave microPython

	*releasePack = (CLISerialManager != MPYSerialManager) ? (true) : (false);

	kern_setSerialForProcess(process, MPYSerialManager);

	microPython_configure(&configure);

// Management of the Command Input Line (until "quit")

	MICROPYTHON_CMDLINE;

	(void)dprintf(KSYST, "Terminated\n");
	memo_free(configure.oMemory);

// Eventually, release the console

	if (CLISerialManager == MPYSerialManager) {
		*releasePack = true;
	}
	exit(EXIT_OS_SUCCESS);
}
#endif
