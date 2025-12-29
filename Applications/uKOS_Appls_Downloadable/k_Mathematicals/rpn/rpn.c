/*
; rpn.
; ====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application shows how to operate with the uKOS-X uKernel.
;
;			Preliminary rpn hp25 calculator.
;			Usage:
;
;			35
;			ENTER
;			5
;			+
;			10
;			/
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

/*!
 * \file
 * \ingroup app_mathematic
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 1 processes:
 *
 *			- P0: Initialise the decnumber math library
 *				  Until quit
 *					- Waiting for numbers or commands
 *					- Display the result
 *
 */

#include	"uKOS.h"
#include	"decNumber.h"
#include	"decContext.h"
#include	"bid/decimal64.h"
#include	<math.h>
#include	<string.h>

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"rpn          Example of a simplified RPN hp25          (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  rpn\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

MODULE(
	UserAppl,							// Module name (the first letter has to be upper case)
	KID_FAM_APPLICATIONS,				// Family (defined in the module.h)
	KNUM_APPLICATION,					// Module identifier (defined in the module.h)
	NULL,								// Address of the initialisation code (early pre-init)
	aStart,								// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,								// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);

// Application specific
// ====================

#define	KLN_CMD_LINE_BUF	256u		// Length of the command line
#define	KNB_PARAMETERS		10u			// Nb of parameters
#define	KDIGIT_PRECISION	16u			// 16 digits for decimal 64-bits
#define	KNO_TRAP			0u			// No trap

typedef	struct	command			command_t;
typedef	struct	machineStack	machineStack_t;

struct command {
		const	char_t		*oCommand;
				void		(*oOrder)(uint32_t argc, const char_t *argv[]);
};

struct machineStack {
				decNumber	oX;
				decNumber	oY;
				decNumber	oZ;
				decNumber	oT;
};

static	machineStack_t	vRpnStack;
static	char_t			vResult[256];
static	bool			vEnter = false;
static	bool			vTerminate = false;
static	decContext		vSet;

// Prototypes

static	void	local_getCommand(uint32_t argc, const char_t *argv[]);
static	void	local_printStatus(uint8_t n, decContext *set);
static	void	local_printStack(void);
static	void	local_push(void);
static	void	local_pop(void);
static	void	local_quit(uint32_t argc, const char_t *argv[]);
static	void	local_enter(uint32_t argc, const char_t *argv[]);
static	void	local_sum(uint32_t argc, const char_t *argv[]);
static	void	local_sub(uint32_t argc, const char_t *argv[]);
static	void	local_mul(uint32_t argc, const char_t *argv[]);
static	void	local_div(uint32_t argc, const char_t *argv[]);
static	void	local_pow(uint32_t argc, const char_t *argv[]);

/*
 * \brief aProcess
 *
 * - P0: Initialise the decnumber math library
 *		 Until quit
 *			- Waiting for numbers or commands
 *			- Display the result
 *
 */
static void __attribute__ ((noreturn)) aProcess(const void *argument) {
	decNumber		x;
	uint32_t		argc = 0u;

// Reserve the memory for the command line

		  char_t *commandLine = (char_t *)memo_malloc(KMEMO_ALIGN_8, ((KLN_CMD_LINE_BUF + 1u) * sizeof(char_t)), "cmd_line");
		  char_t **parameters = (char_t **)memo_malloc(KMEMO_ALIGN_8, (KNB_PARAMETERS * sizeof(char_t *)), "parameters");
	const char_t **argv		  = (const char_t **)memo_malloc(KMEMO_ALIGN_8, (KNB_PARAMETERS * sizeof(char_t *)), "argv");

	if (commandLine == NULL) { LOG(KFATAL_USER, "memo_malloc commandLine"); exit(EXIT_OS_FAILURE); }
	if (parameters == NULL)	 { LOG(KFATAL_USER, "memo_malloc parameters");	exit(EXIT_OS_FAILURE); }
	if (argv == NULL)		 { LOG(KFATAL_USER, "memo_malloc argv");		exit(EXIT_OS_FAILURE); }

	UNUSED(argument);

	(void)dprintf(KSYST, "\n");

	decContextDefault(&vSet, DEC_INIT_DECIMAL64);
	vSet.traps  = KNO_TRAP;
	vSet.digits = KDIGIT_PRECISION;

	decNumberFromString(&vRpnStack.oX, "0", &vSet);
	decNumberFromString(&vRpnStack.oY, "0", &vSet);
	decNumberFromString(&vRpnStack.oZ, "0", &vSet);
	decNumberFromString(&vRpnStack.oT, "0", &vSet);

	while (vTerminate == false) {
		text_waitString(KSYST, commandLine, KLN_CMD_LINE_BUF);
		text_readArgs(commandLine, KLN_CMD_LINE_BUF, argv, &argc);

		memcpy((void *)parameters, (const void *)argv, KNB_PARAMETERS);

		vSet.status = 0u;
		decNumberFromString(&x, parameters[0], &vSet);

// The commandLine could be a decimal number or an order.
// If decNumberFromString returns a problem, the command line
// could be a command. If no, indicate a syntax error.

		if ((vSet.status & DEC_Errors) == 0u)  {
			if (vEnter == true) {				vRpnStack.oX = x; local_printStack(); vEnter = false; }
			else				{ local_push(); vRpnStack.oX = x; local_printStack(); vEnter = false; }
		}
		else {
			local_getCommand(argc, argv);
		}
	}

	memo_free(commandLine);
	memo_free((void *)parameters);
	memo_free((void *)argv);

	kern_suspendProcess(1000u);
	exit(EXIT_OS_SUCCESS);
}

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
int		main(int argc, const char *argv[]) {
	proc_t	*process;

// -------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden[]) = "Process_User";
	STRG_LOC_CONST(aStrText[]) = "Process user.                             (c) EFr-2025";

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess,							// Code of the process
		aStrIden,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification, NULL, &process) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS);
}

// Local routines
// ==============

#define	X_Y_OPERATIONS(op, argc, argv)															\
			do {																				\
				decNumber	x, y, r;															\
				decimal64	rd64;																\
																								\
				UNUSED(argc);																	\
				UNUSED(argv);																	\
																								\
				(x) = vRpnStack.oX;																\
				(y) = vRpnStack.oY;																\
																								\
				vSet.status = 0u;																\
				decNumber##op(&(r), &(y), &(x), &(vSet));										\
				local_printStatus(1u, &(vSet));													\
				vSet.status = 0u;																\
				decimal64FromNumber(&(rd64), &(r), &(vSet));									\
				local_printStatus(2u, &(vSet));													\
				vSet.status = 0u;																\
				decimal64ToString(&(rd64), (vResult));											\
				local_printStatus(3u, &(vSet));													\
																								\
				(void)dprintf(KSYST, "Result = %s\n\n", (vResult));								\
																								\
				if (((vSet.status) & DEC_Errors) == 0u) { local_pop(); vRpnStack.oX = (r); }	\
			} while (0)

/*
 * \brief local_printStatus
 *
 * - Display the status of the operation
 *
 */
static	void	local_printStatus(uint8_t n, decContext *set) {

	if ((set->status & DEC_Errors) == 0u) { return; }

	set->status &= DEC_Errors;

	(void)dprintf(KSYST, "Problem: n = %d %s\n", n, decContextStatusToString(set));
}

/*
 * \brief local_getCommand
 *
 * - Try to execute the command
 *
 */
static	void	local_getCommand(uint32_t argc, const char_t *argv[]) {
			bool		equal;
	const	command_t	aTabCommand[] = {
							{ (const char_t *)"ENTER",	local_enter	},
							{ (const char_t *)"+",		local_sum	},
							{ (const char_t *)"-",		local_sub	},
							{ (const char_t *)"*",		local_mul	},
							{ (const char_t *)"/",		local_div	},
							{ (const char_t *)"POW",	local_pow	},
							{ (const char_t *)"quit",	local_quit	},
							{  NULL,					NULL		}
						};
	const command_t		*table = &aTabCommand[0];

	while (table->oCommand != NULL) {
		text_checkAsciiBuffer(argv[0], table->oCommand, &equal);
		if (equal == true) {
			table->oOrder(argc, argv);
			local_printStack();
			break;
		}

		table++;
	}
}

/*
 * \brief local_printStack
 *
 * - Display the stack
 *
 */
static	void	local_printStack(void) {
	decNumber	x, y, z, t;
	decimal64	rd64;


	(void)dprintf(KSYST, "\nMachine stack\n");
	(void)dprintf(KSYST, "-------------\n\n");

	t = vRpnStack.oT;
	decimal64FromNumber(&rd64, &t, &vSet);
	decimal64ToString(&rd64, vResult);
	(void)dprintf(KSYST, "T = %s\n", vResult);

	z = vRpnStack.oZ;
	decimal64FromNumber(&rd64, &z, &vSet);
	decimal64ToString(&rd64, vResult);
	(void)dprintf(KSYST, "Z = %s\n", vResult);

	y = vRpnStack.oY;
	decimal64FromNumber(&rd64, &y, &vSet);
	decimal64ToString(&rd64, vResult);
	(void)dprintf(KSYST, "Y = %s\n", vResult);

	x = vRpnStack.oX;
	decimal64FromNumber(&rd64, &x, &vSet);
	decimal64ToString(&rd64, vResult);
	(void)dprintf(KSYST, "X = %s\n", vResult);
}

/*
 * \brief local_push
 *
 * - Push into the stack
 *		- T = Z, Z = Y, Y = X
 *
 */
static	void	local_push(void) {

	vRpnStack.oT = vRpnStack.oZ;
	vRpnStack.oZ = vRpnStack.oY;
	vRpnStack.oY = vRpnStack.oX;
}

/*
 * \brief local_pop
 *
 * - Pop from the stack
 *		- X = Y, Y = Z, Z = T
 *
 */
static	void	local_pop(void) {

	vRpnStack.oX = vRpnStack.oY;
	vRpnStack.oY = vRpnStack.oZ;
	vRpnStack.oZ = vRpnStack.oT;
}

/*
 * \brief local_quit
 *
 * - quit
 *
 */
static	void	local_quit(uint32_t argc, const char_t *argv[]) {

	UNUSED(argc);
	UNUSED(argv);

	vTerminate = true;
}

/*
 * \brief local_enter
 *
 * - "ENTER"
 *		- push
 *
 */
static	void	local_enter(uint32_t argc, const char_t *argv[]) {

	UNUSED(argc);
	UNUSED(argv);

	vEnter = true;
	local_push();
}

/*
 * \brief local_sum
 *
 * - "+"
 *		- Y + X -> X
 *		- pop (if no error)
 *
 */
static	void	local_sum(uint32_t argc, const char_t *argv[]) {

	X_Y_OPERATIONS(Add, argc, argv);
}

/*
 * \brief local_sub
 *
 * - "-"
 *		- Y - X -> X
 *		- pop (if no error)
 *
 */
static	void	local_sub(uint32_t argc, const char_t *argv[]) {

	X_Y_OPERATIONS(Subtract, argc, argv);
}

/*
 * \brief local_mul
 *
 * - "*"
 *		- Y * X -> X
 *		- pop (if no error)
 *
 */
static	void	local_mul(uint32_t argc, const char_t *argv[]) {

	X_Y_OPERATIONS(Multiply, argc, argv);
}

/*
 * \brief local_div
 *
 * - "*"
 *		- Y / X -> X
 *		- pop (if no error)
 *
 */
static	void	local_div(uint32_t argc, const char_t *argv[]) {

	X_Y_OPERATIONS(Divide, argc, argv);
}

/*
 * \brief local_pow
 *
 * - "*"
 *		- Y ^ X -> X
 *		- pop (if no error)
 *
 */
static	void	local_pow(uint32_t argc, const char_t *argv[]) {

	X_Y_OPERATIONS(Power, argc, argv);
}
