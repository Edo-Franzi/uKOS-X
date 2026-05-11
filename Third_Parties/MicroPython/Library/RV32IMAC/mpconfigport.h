/*
; mpconfigport.
; =============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Configuration port for MicroPython.
;
;   (c) 2025-2026, Laurent von Allmen
;   ---------------------------------
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

#include	"py/mpconfig.h"
#include	<stdint.h>

// Options to control how MicroPython is built

// You can disable the built-in MicroPython compiler by setting the following
// config option to 0.  If you do this then you won't get a REPL prompt, but you
// will still be able to execute pre-compiled scripts, compiled with mpy-cross.

#define	MICROPY_ENABLE_COMPILER					(1)
#define	MICROPY_QSTR_BYTES_IN_HASH				(1)
//#define MICROPY_QSTR_EXTRA_POOL				(0)
#define	MICROPY_ALLOC_PATH_MAX					(256)
#define	MICROPY_ALLOC_PARSE_CHUNK_INIT			(16)
#define	MICROPY_EMIT_X64						(0)
#define	MICROPY_EMIT_THUMB						(0)
#define	MICROPY_EMIT_INLINE_THUMB				(0)
#define	MICROPY_COMP_MODULE_CONST				(0)
#define	MICROPY_COMP_CONST						(0)
#define	MICROPY_COMP_DOUBLE_TUPLE_ASSIGN		(0)
#define	MICROPY_COMP_TRIPLE_TUPLE_ASSIGN		(0)
#define	MICROPY_MEM_STATS						(0)
#define	MICROPY_DEBUG_PRINTERS					(0)
#define	MICROPY_ENABLE_GC						(1)
#define	MICROPY_GC_ALLOC_THRESHOLD				(0)
#define	MICROPY_REPL_EVENT_DRIVEN				(0)
#define	MICROPY_HELPER_REPL						(1)
#define	MICROPY_HELPER_LEXER_UNIX				(0)
#define	MICROPY_ENABLE_SOURCE_LINE				(0)
#define	MICROPY_ENABLE_DOC_STRING				(0)
#define	MICROPY_ERROR_REPORTING					(MICROPY_ERROR_REPORTING_TERSE)
#define	MICROPY_BUILTIN_METHOD_CHECK_SELF_ARG	(0)
#define	MICROPY_PY_ASYNC_AWAIT					(0)
#define	MICROPY_PY_BUILTINS_BYTEARRAY			(1)
#define	MICROPY_PY_BUILTINS_MEMORYVIEW			(1)
#define	MICROPY_PY_BUILTINS_ENUMERATE			(1)
#define	MICROPY_PY_BUILTINS_FILTER				(1)
#define	MICROPY_PY_BUILTINS_FROZENSET			(0)
#define	MICROPY_PY_BUILTINS_REVERSED			(1)
#define	MICROPY_PY_BUILTINS_SET					(1)
#define	MICROPY_PY_BUILTINS_SLICE				(1)
#define	MICROPY_PY_BUILTINS_PROPERTY			(1)
#define	MICROPY_PY_BUILTINS_MIN_MAX				(1)
#define	MICROPY_PY_BUILTINS_HELP				(1)
#define	MICROPY_PY_BUILTINS_HELP_TEXT			aUKOSHELP
#define	MICROPY_PY___FILE__						(0)
#define	MICROPY_PY_GC							(0)
#define	MICROPY_PY_ARRAY						(1)
#define	MICROPY_PY_ATTRTUPLE					(0)
#define	MICROPY_PY_COLLECTIONS					(0)
#define	MICROPY_PY_MATH							(1)
#define	MICROPY_PY_CMATH						(1)
#define	MICROPY_PY_IO							(0)
#define	MICROPY_PY_STRUCT						(0)
#define	MICROPY_PY_SYS							(1)
#define	MICROPY_MODULE_FROZEN_MPY				(0)
#define	MICROPY_CPYTHON_COMPAT					(0)
#define	MICROPY_LONGINT_IMPL					(MICROPY_LONGINT_IMPL_LONGLONG)
#define	MICROPY_FLOAT_IMPL						(MICROPY_FLOAT_IMPL_FLOAT)
#define	MICROPY_PY_UBINASCII					(1)
#define	MICROPY_PY_BUILTINS_HELP_MODULES		(1)
#define	MICROPY_PY_UTIME						(1)
#define	MICROPY_PY_MACHINE						(1)

// Type definitions for the specific machine

// RV32IMAC has no Thumb mode; function pointers need no bit-0 tag.
#define	MICROPY_MAKE_POINTER_CALLABLE(p)		((void *)(p))

// Custom uKOS extensions

#define	MODULE_EXAMPLE_ENABLED					(1)
#define	MODULE_UKOS_MISC_ENABLED				(1)
#define	MODULE_UKOS_SERIAL_ENABLED				(1)

// This port is intended to be 32-bit, but unfortunately, int32_t for
// different targets may be defined in different ways - either as int
// or as long. This requires different printf formatting specifiers
// to print such value. So, we avoid int32_t and use int directly.

#define	UINT_FMT	"%u"
#define	INT_FMT		"%d"

// must be pointer size

typedef	int			mp_int_t;
typedef	unsigned	mp_uint_t;
typedef	long		mp_off_t;

#define	MP_PLAT_PRINT_STRN(str, len) mp_hal_stdout_tx_strn_cooked(str, len)

// extra built in names to add to the global namespace

#define	MICROPY_PORT_BUILTINS					{ MP_OBJ_NEW_QSTR(MP_QSTR_open), (mp_obj_t)&mp_builtin_open_obj },

// We need to provide a declaration/definition of alloca()

#include	<alloca.h>

#define	MICROPY_HW_BOARD_NAME					"uKOS-X uKernel"

#define	MICROPY_HW_MCU_NAME						"RV32IMAC"
#define	UKOS_INT_BUILD							"int on 64-bits"
#define	UKOS_FLOAT_BUILD						"float on simple precision"
#define	UKOS_PACK_NAME							"Package "MICROPY_VERSION_STRING" for uKOS-X (RV32IMAC)"

#if (defined(__riscv))
#define	MICROPY_MIN_USE_RISCV_CPU				(1)
#endif

#define	MP_STATE_PORT MP_STATE_VM

#define	MICROPY_PORT_ROOT_POINTERS				const char *readline_hist[8];
