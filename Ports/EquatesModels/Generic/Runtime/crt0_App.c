/*
; crt0_App.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		crt0 for the uKOS-X applications.
;			User only support
;
;                       CODE
; linker_stTEXT			+-----------------+
;						|                 |
;						| .text           |
; linker_enTEXT			|                 |
; linker_stRODATA		+-----------------+
;						|                 |
;						| .rodata         |
; linker_enRODATA		|                 |
; linker_stDATA			+-----------------+
;						|                 |
;						| .data           |
; linker_enDATA			|                 |
; linker_stBSS			+-----------------+
;						|                 |
;						| .bss            |
; linker_enBSS			|                 |
; _end					+-----------------+
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
#include	"FLASH.ck"

#ifndef	KSYSTEM_CRT0_CHECK_OS_VERSION_S
#define	KSYSTEM_CRT0_CHECK_OS_VERSION_S		true
#endif

#define	SKIP_CXX_DESTRUCTORS_S	// Do not call the C++ destructor;
								// Some processes can still be in execution
								// at the output of the main

// Runtime specific
// ================

extern	uint8_t		linker_stBSS[];
extern	uint8_t		linker_enBSS[];
extern	uint8_t		linker_stInitArray[];
extern	uint8_t		linker_enInitArray[];
extern	uint8_t		linker_stFiniArray[];
extern	uint8_t		linker_enFiniArray[];

extern	char_t		aFLASH_signature[];
extern	uint32_t	vKern_nbIntImbrications;

// For the stack guard, only 32 and 64-bit machines are considered

extern	uintptr_t	__stack_chk_guard;

#if (UINTPTR_MAX == 0xFFFFFFFFu)
#define	KSTACK_GUARD_VALUE	0xDeadBeefu

#else
#define	KSTACK_GUARD_VALUE	0xDeadBeeffeeBdaeDu
#endif

/*
 * \brief aStart
 *
 * - Initialise the BSS region
 * - Call C/C++ constructors
 * - Call main
 * - Optionally call C++ destructors
 *
 */
int32_t		aStart(uint32_t argc, const char_t *argv[]) {
	int32_t		status;
	bool		gdb;
	uintptr_t	*ptrStInitArray;
	uintptr_t	*ptrEnInitArray;

	#if (!defined(SKIP_CXX_DESTRUCTORS_S))
	uintptr_t	*ptrStFiniArray;
	uintptr_t	*ptrEnFiniArray;
	#endif

	PRIVILEGE_ELEVATE;
	gdb = (vKern_nbIntImbrications != 0u) ? (true) : (false);
	if (gdb == true) {
		kern_criticalSection(KEXIT_CRITICAL);
	}

// Initialise the BSS region

	memset(linker_stBSS, 0x00u, (size_t)((uintptr_t)linker_enBSS - (uintptr_t)linker_stBSS));

// Verify if the application is compatible with the burned OS

	#if (KSYSTEM_CRT0_CHECK_OS_VERSION_S == true)
	uint32_t	i;

	for (i = 0u; i < 64u; i++) {
		if (aFLASH_signature[i] != aSignature[i]) {

			PRIVILEGE_RESTORE;
			return (EXIT_OS_FAILURE_CRT0);
		}

	}
	#endif

// Call all constructors from .init_array

	ptrStInitArray = ALIGNED_PTR(uintptr_t, linker_stInitArray);
	ptrEnInitArray = ALIGNED_PTR(uintptr_t, linker_enInitArray);

	while (ptrStInitArray < ptrEnInitArray) {
		((void (*)(void))*ptrStInitArray)();
		ptrStInitArray++;
	}

	__stack_chk_guard = KSTACK_GUARD_VALUE;

	PRIVILEGE_RESTORE;

	RESERVE(SYSTEM, KMODE_READ_WRITE);
	status = (int32_t)main((int)argc, (const char **)argv);

// Call all destructors from .fini_array

	#if (!defined(SKIP_CXX_DESTRUCTORS_S))
	ptrStFiniArray = ALIGNED_PTR(uintptr_t, linker_stFiniArray);
	ptrEnFiniArray = ALIGNED_PTR(uintptr_t, linker_enFiniArray);

	while (ptrStFiniArray < ptrEnFiniArray) {
		((void (*)(void))*ptrStFiniArray)();
		ptrStFiniArray++;
	}
	#endif

	if (gdb == true) {
		exit(EXIT_OS_SUCCESS);
	}

	return (status);
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
#if (!defined(__clang__))
void	__attribute__ ((noreturn)) __wrap___stack_chk_fail(void) {

	PRIVILEGE_ELEVATE;
	INTERRUPTION_OFF;
	cmns_send(KSYST, "\nStack smashing!");
	exit(EXIT_OS_PANIC);
}
#endif
