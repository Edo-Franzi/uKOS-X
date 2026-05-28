/*
; syscallDispatcher.
; ==================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
: SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Syscall dispatcher, called from vExce_indExcVectors[core][11].
;			first_dispatch_ecall() in first_riscv.c sets vMessage = a0 before calling here.
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

#include	"syscallDispatcher.h"

#include	"uKOS.h"

// Weak stubs — overridden by the RISC-V kernel model in Phase 3.3

[[gnu::weak]]
void	kernel_message_C0(void) { }

#if (KNB_CORES == 2)
[[gnu::weak]]
void	kernel_message_C1(void) { }
#endif

/*
 * \brief syscallDispatcher
 *
 * - Routes ecall to the kernel context-switch entry point based on vMessage
 * - Registered in vExce_indExcVectors[core][11] by exce_init()
 *
 */
void	syscallDispatcher(void) {

	#if (KNB_CORES == 2)
	if (GET_RUNNING_CORE == KCORE_0) {
		kernel_message_C0();
	}
	else {
		kernel_message_C1();
	}
	#else
	kernel_message_C0();
	#endif

// KPRIV_ELEVATION is a no-op on RV32IMAC (no U-mode in this build)

}
