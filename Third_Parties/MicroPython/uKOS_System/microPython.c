/*
; microPython.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		mpyt library.
;			uKOS-X interface for MicroPython (www.MicroPython.com).
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

// Needed to support dprintf

#define		_POSIX_C_SOURCE		200809L

#include	"macros.h"
#include	"types.h"
#include	"modules.h"
#include	"os_errors.h"
#include	"ip.h"
#include	"crt0.h"
#include	"microPython.h"
#include	"serial/serial.h"
#include	"text/text.h"
#include	"kern/kern.h"
#include	"py/nlr.h"
#include	"py/compile.h"
#include	"py/runtime.h"
#include	"py/repl.h"
#include	"py/gc.h"
#include	"py/mperrno.h"
#include	"extmod/vfs.h"
#include	"shared/runtime/pyexec.h"
#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>

// Library specific
// ================

#define	KSZ_INPUT		256u		// Size of the MicroPython input buffer

STRG_LOC_CONST(aStrTerminated[]) = "quit";

// Prototypes

static	void	local_init(void);
static	void	local_commandLine(const char_t *src, mp_parse_input_kind_t input_kind);

/*
 * \brief Configure the microPython manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t              status;
 * microPythonCnf_t    configure;
 *
 *    configure.oSize = 90000;
 *    configure.oMemory = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, configure.oSize, "mpyt");
 *    if (configure.oMemory == 0) {
 *        exit(EXIT_OS_FAILURE);
 *    }
 *
 *    status = microPython_configure(&configure);
 * \endcode
 *
 * \param[in]	*configure				Ptr on the configuration buffer
 * \return		KERR_MYCROPYTHON_NOERR	OK
 *
 */
int32_t	microPython_configure(microPythonCnf_t *configure) {

	local_init();

	(void)dprintf(KSYST, "\nuKOS interface for MicroPython (www.MicroPython.com)\n");
	(void)dprintf(KSYST, "%s\n", UKOS_PACK_NAME);
	(void)dprintf(KSYST, "Built with %s and %s\n\n", UKOS_INT_BUILD, UKOS_FLOAT_BUILD);

// Initialise the MPTY session

	gc_init(configure->oMemory, (uint8_t *)((uintptr_t)configure->oMemory + (uintptr_t)configure->oSize));
	mp_init();

	return (KERR_MICROPYTHON_NOERR);
}

/*
 * \brief Exchange data with the microPython manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 * const    char_t     myRoutine [] = "def plus(a,b):\n"
 *                                    "    return a + b\n";
 *
 *    status = microPython_exchangeData(nullptr);
 *    status = microPython_exchangeData(myRoutine);
 * \endcode
 *
 * \param[in]	*pyProgram				nullptr = Command line interpreter mode
 * \param[in]	-						Ptr on the ascii script / program
 * \return		KERR_MICROPYTHON_NOERR	OK
 *
 */
int32_t	microPython_exchangeData(const char_t *pyProgram) {
	char_t				ascii[KSZ_INPUT + 1];
	uint32_t			i, size;
	serialManager_t		serialManager;
	bool				terminate = false;
	proc_t				*process;

	local_init();

	kern_getProcessRun(&process);
	kern_getSerialForProcess(process, &serialManager);

	if (pyProgram == nullptr) {

// Command line interpreter
// ------------------------

		while (terminate == false) {
			(void)dprintf(KSYST, ">>> ");
			text_waitString(serialManager, ascii, (KSZ_INPUT - 4));

			size = strlen(ascii);
			ascii[size] = '\r'; ascii[size + 1] = '\n'; ascii[size + 2] = '\0';

// Check the "quit"

			terminate = true;
			for (i = 0u; i < (uint32_t)(size - 1u); i++) {
				if (ascii[i] != aStrTerminated[i]) {
					terminate = false;
					local_commandLine(ascii, MP_PARSE_SINGLE_INPUT);
					break;
				}
			}
		}
		mp_deinit();
		return (KERR_MICROPYTHON_NOERR);
	}

// Script / program interpreter
// ----------------------------

	local_commandLine(pyProgram, MP_PARSE_FILE_INPUT);
	return (KERR_MICROPYTHON_NOERR);
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
static	void	local_init(void) {

	kern_setPrivilegeMode(KPROC_PRIVILEGED);
}

/*
 * \brief local_commandLine
 *
 * \param[in]	*ascii		Ptr on the input line
 * \param[in]	input_kind	Input kind (MP_PARSE_SINGLE_INPUT, MP_PARSE_FILE_INPUT)
 *
 * \note This function does not return a value (None).
 *
 */
static	void	local_commandLine(const char_t *ascii, mp_parse_input_kind_t input_kind) {
	nlr_buf_t		nlr;
	mp_lexer_t		*lex;
	qstr			sourceName;
	mp_parse_tree_t	parseTree;
	mp_obj_t		moduleFun;

	if (nlr_push(&nlr) == 0) {
		lex = mp_lexer_new_from_str_len(MP_QSTR__lt_stdin_gt_, ascii, strlen(ascii), 0);
		sourceName = lex->source_name;
		parseTree = mp_parse(lex, input_kind);
		moduleFun = mp_compile(&parseTree, sourceName, true);
		mp_call_function_0(moduleFun);
		nlr_pop();
	}
	else {
		mp_obj_print_exception(&mp_plat_print, (mp_obj_t)nlr.ret_val);
	}
}

/*
 * \brief mp_hal_stdout_tx_strn
 *
 * \param[in]	*ascii	Ptr on the input line
 * \param[in]	size	Size f the ascii
 *
 * \note This function does not return a value (None).
 *
 */
void	mp_hal_stdout_tx_strn(const uint8_t *ascii, mp_uint_t size) {
	int16_t				i;
	serialManager_t		serialManager;
	proc_t				*process;

	kern_getProcessRun(&process);
	kern_getSerialForProcess(process, &serialManager);

	for (i = 0u; i < size; i++) {
		(void)dprintf(serialManager, "%c", ascii[i]);
	}
}

/*
 * \brief mp_hal_stdin_rx_chr
 *
 * \param[in]	-
 * \return		char	The read char
 *
 */
char_t	mp_hal_stdin_rx_chr(void) {
	uint8_t				byte;
	int32_t				status;
	uint32_t			size;
	serialManager_t		serialManager;
	proc_t				*process;

	kern_getProcessRun(&process);
	kern_getSerialForProcess(process, &serialManager);

	do {
		kern_suspendProcess(1u);
		size = 1u;
		status = serial_read(serialManager, &byte, &size);
	} while ((status != KERR_SERIAL_NOERR) && (size != 1u));
	return ((char_t)byte);
}

// Needed by the package
// ---------------------

// !!! Not clear how the garbage collector works !!!
// !!! Just follow some implementation examples  !!!

void	gc_collect(void) {
	uintptr_t	*stack;
	uintptr_t	stackEnd, usedStack, stackSize;
	proc_t		*process;

	kern_getProcessRun(&process);

// Stack pointer
// Stack size in bytes = oStackSize * 4
// Stack end  = stack start + Stack size
// Used stack = (Stack end - stack) / 4

	stack	  = process->oSpecification.oStack;
	stackSize = ((uintptr_t)process->oSpecification.oStackSize * 4u);
	stackEnd  = ((uintptr_t)process->oSpecification.oStackStart + (uintptr_t)stackSize);
	usedStack = (stackEnd - (uintptr_t)stack) / sizeof(uintptr_t);

	gc_collect_start();

// Trace the stack, including the registers (since they live on the stack in this function)
// Not sure what is the purpose of this function

	gc_collect_root((void *)stack, usedStack);
	gc_collect_end();
	gc_dump_info(&mp_plat_print);
}

mp_lexer_t	*mp_lexer_new_from_file(qstr filename) {

	UNUSED(filename);

	mp_raise_OSError(MP_ENOENT);
}

mp_import_stat_t	mp_import_stat(const char_t *path) {

	UNUSED(path);

	return (MP_IMPORT_STAT_NO_EXIST);
}

mp_obj_t	mp_builtin_open(uint n_args, const mp_obj_t *args, mp_map_t *kwargs) {

	UNUSED(n_args);
	UNUSED(args);
	UNUSED(kwargs);

	return (mp_const_none);
}
MP_DEFINE_CONST_FUN_OBJ_KW(mp_builtin_open_obj, 1, mp_builtin_open);

void NORETURN nlr_jump_fail(void *val) {

	UNUSED(val);

	(void)dprintf(KSYST, "MicroPython fatal error\n");
	(void)dprintf(KSYST, "Leave the MicroPython process!\n");
	exit(EXIT_OS_FAILURE);
}

void NORETURN __fatal_error(const char_t *msg) {

	(void)dprintf(KSYST, "MicroPython fatal error\n");
	(void)dprintf(KSYST, "%s\n", msg);
	(void)dprintf(KSYST, "Leave the MicroPython process!\n");
	exit(EXIT_OS_FAILURE);
}

#if (!defined(NDEBUG))
void	MP_WEAK __assert_func(const char_t *file, int line, const char_t *func, const char_t *expr) {

	UNUSED(func);

	(void)dprintf(KSYST, "Assertion '%s' failed, at file %s:%d\n", expr, file, line);
	__fatal_error("Assertion failed");
}
#endif
