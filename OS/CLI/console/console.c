/*
; console.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Open a console prompt (multi-user).
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

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"console      Console prompt.                           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Console\n"
									"=======\n\n"

									"This function module controls the system with a\n"
									"standard ASCII protocol. Different function modules\n"
									"as well as different tool modules can be executed.\n\n"

									"Input format:  console {serialManager [urt0 | urtn | usb2 ...]}\n"
									"Output format: uKOS-X >\n\n"

									"Protocol mode\n"
									"   Input format:  ID_ORDER[,parm1,parm2,..,parmN]\n"
									"   Output format: id_order[,parm1,parm2,..,parmN]\n\n"

									"Tool mode\n"
									"   Input format:  name [parms ..]\n"
									"   Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Console,												// Module name (the first letter has to be upper case)
	KID_FAM_CLI,											// Family (defined in the module.h)
	KNUM_CONSOLE,											// Module identifier (defined in the module.h)
	nullptr,												// Address of the initialisation code (early pre-init)
	prgm,													// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,												// Address of the clean code (clean the module)
	" 1.0",													// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),						// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0														// Execution cores
);

// CLI tool specific
// =================

typedef	struct	console			console_t;
typedef	struct	consolePack		consolePack_t;

struct	console {
				serialManager_t		oSerialManager;			// Serial Communication Manager
		const	char_t				*oIdentifier;			// Ptr on the process identifier
		const	char_t				*oText;					// Ptr on the process identifier text
		};

struct	consolePack {
				serialManager_t		oSerialManager;			// Serial Communication Manager
				char_t				*oCommandLine;			// Ptr on the command line
				bool				*oReleasePack;			// Release the pack
		};

// -------------------------------------------------------I-----------------------------------------I--------------I

static	const	console_t	aTabConsole[] = {
								{ KURT0, "Console_urt0", "Process console urt0.                     (c) EFr-2026" },
								{ KURT1, "Console_urt1", "Process console urt1.                     (c) EFr-2026" },
								{ KURT2, "Console_urt2", "Process console urt2.                     (c) EFr-2026" },
								{ KURT3, "Console_urt3", "Process console urt3.                     (c) EFr-2026" },
								{ KURT4, "Console_urt4", "Process console urt4.                     (c) EFr-2026" },
								{ KCDC0, "Console_cdc0", "Process console cdc0.                     (c) EFr-2026" },
								{ KCDC1, "Console_cdc1", "Process console cdc1.                     (c) EFr-2026" },
								{ KWFI0, "Console_wfi0", "Process console wfi0.                     (c) EFr-2026" },
								{ KBLE0, "Console_ble0", "Process console ble0.                     (c) EFr-2026" }
							};

#define	KNB_CHANNELS			(sizeof(aTabConsole) / sizeof(console_t))

#define	KLN_INIT_CMD_LINE_BUF	128u						// Length of the initial command line
#define	KLN_CMD_LINE_BUF		2048u						// Length of the command line
#define	KNB_PARAMETERS			(KLN_CMD_LINE_BUF / 2u)		// It is considered a minimum parameter of "x " (2-bytes)

// Prototypes

static	int32_t		local_execute(uint32_t argc, const char_t *argv[]);
static	void		local_process(const void *argument);
static	uint16_t	local_getIndex(serialManager_t serialManager);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	enum				{ KERR_NOT, KERR_INA, KERR_PRO } error = KERR_NOT;
	int32_t				status;
	serialManager_t		serialManager = KDEF0;
	char_t				commandLine[KLN_INIT_CMD_LINE_BUF + 1u];
	consolePack_t		pack;
	bool				releasePack = false;
	uint16_t			i, index;
	proc_t				*process;

// Analyse the command line
// ------------------------
//
// Example:
//
// console urt1
// console urt1 xyz

	if (argc < 2u) {
		error = KERR_INA;
	}
	else {
		serialManager = (serialManager_t)(GET_PTR_32(argv[1]));

		switch (argc) {
			case 3: {
				text_copyAsciiBufferZ(commandLine, argv[2]);
				break;
			}
			default: {
				for (i = 0u; i < KLN_INIT_CMD_LINE_BUF; i++) {
					commandLine[i] = '\0';
				}
				break;
			}
		}
	}

	if (error == KERR_NOT) {
		pack.oCommandLine   = commandLine;
		pack.oSerialManager = serialManager;
		pack.oReleasePack   = &releasePack;

		index = local_getIndex(serialManager);

		PROCESS_STACKMALLOC(
			0,									// Index
			specification,						// Specifications (just use specification_x)
			aTabConsole[index].oText,			// Info string (nullptr if anonymous)
			KKERN_SZ_STACK_LL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
			local_process,						// Code of the process
			aTabConsole[index].oIdentifier,		// Identifier (nullptr if anonymous)
			serialManager,						// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
			KKERN_PRIORITY_NORMAL_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
		);

		if (kern_createProcess(&specification, &pack, &process) != KERR_KERN_NOERR) { error  = KERR_PRO; }
	}

	switch (error) {
		case KERR_NOT: {																					status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_PRO: { (void)dprintf(KSYST, "Console already active for this communication device.\n\n"); status = EXIT_OS_FAILURE;	  break; }
		case KERR_INA: { (void)dprintf(KSYST, "Incorrect arguments.\n\n");									status = EXIT_OS_FAILURE;     break; }
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
 * - Launch a console
 *
 */
[[noreturn]]
static	void	local_process(const void *argument) {
			char_t				*commandLine;
			bool				*releasePack;
			uint32_t			core, i, argc;
			serialManager_t		serialManager;
	const	char_t				**argv;
	const	consolePack_t		*pack;

	core = GET_RUNNING_CORE;

// Reserve the memory for the command line

	commandLine = (char_t *)memo_malloc(KMEMO_ALIGN_8, ((KLN_CMD_LINE_BUF + 1u) * sizeof(char_t)), "cmd_line");
	argv		= (const char_t **)memo_malloc(KMEMO_ALIGN_8, (KNB_PARAMETERS * sizeof(char_t *)), "argv");

	if ((commandLine == nullptr) || (argv == nullptr)) {
		(void)dprintf(KSYST, "Out of memory\n");
		if (commandLine != nullptr) { memo_free((void *)commandLine); }
		if (argv		!= nullptr) { memo_free((void *)argv);		  }
		LOG(KFATAL_SYSTEM, "console: out of memory");
		exit(EXIT_OS_FAILURE);
	}

// Initialise the command line

	for (i = 0u; i < KLN_CMD_LINE_BUF; i++) {
		commandLine[i] = '\0';
	}

// Recover the process arguments

	pack = (const consolePack_t *)argument;

	serialManager = pack->oSerialManager;
	text_copyAsciiBufferZ(commandLine, (const char_t *)pack->oCommandLine);
	serial_flush(serialManager);
	releasePack  = pack->oReleasePack;
	*releasePack = true;

// Argument passed and saved

	(void)dprintf(KSYST, "Console core %1"PRIu32".\n", core);
	(void)dprintf(KSYST, __DATE__"  "__TIME__" (c) EFr-2026\n\n");

	text_readArgs(commandLine, KLN_CMD_LINE_BUF, argv, &argc);

	if (argc != 0u) {
		local_execute(argc, argv);
	}

	while (true) {
		(void)dprintf(KSYST, "uKOS-X > ");

// Waiting for a command line
// Extract the parameters
// Execute the command

		text_waitString(KSYST, commandLine, KLN_CMD_LINE_BUF);
		text_readArgs(commandLine, KLN_CMD_LINE_BUF, argv, &argc);

		if (argc > 0u) {
			switch (local_execute(argc, argv)) {
				case EXIT_OS_SUCCESS: {
					memo_free((void *)commandLine);
					memo_free((void *)argv);
					exit(EXIT_OS_SUCCESS);
				}

				case EXIT_OS_SUCCESS_CLI:
				case EXIT_OS_FAILURE: {
					break;
				}
				case EXIT_OS_FAILURE_CRT0: {
					LOG(KFATAL_SYSTEM, "console: incompatible OS!!!");
					(void)dprintf(KSYST, "Incompatible OS!!!\nReload the latest OS inside the target.\n");
					break;
				}
				case EXIT_OS_PANIC: {
					LOG(KFATAL_SYSTEM, "console: exit panic");
					exit(EXIT_OS_PANIC);
				}

				default: {
					LOG(KFATAL_SYSTEM, "console: exit panic");
					exit(EXIT_OS_PANIC);
				}

			}
		}
	}
}

/*
 * \brief local_execute
 *
 * - Execute a module
 *
 */
static	int32_t	local_execute(uint32_t argc, const char_t *argv[]) {
			uint16_t		index;
			bool			error = false;
			int32_t			status;
	const	uKOS_module_t	*module;

// Look for the selected module; if it exists, execute it

	if (system_getModuleName(argv[0], &index, &module) != KERR_SYSTEM_NOERR) {
		error = true;
	}

	if (error != true) {
		error = ((module->oFlag & (1u<<BEXE_CONSOLE)) != 0u) ? (false) : (true);
	}

	if (error == true) {
		(void)dprintf(KSYST, "Module not found or user memory busy by a running application.\n\n");
	}

	status = (error == true) ? (EXIT_OS_FAILURE) : (module->oExecution(argc, argv));
	return (status);
}

/*
 * \brief local_getIndex
 *
 * - Get the index of the table f(serialManager)
 *
 */
static	uint16_t	local_getIndex(serialManager_t serialManager) {
	uint8_t		index;

	for (index = 0u; index < (uint8_t)KNB_CHANNELS; index++) {
		if (aTabConsole[index].oSerialManager == serialManager) {
			return (index);
		}

	}
	return (0u);
}
