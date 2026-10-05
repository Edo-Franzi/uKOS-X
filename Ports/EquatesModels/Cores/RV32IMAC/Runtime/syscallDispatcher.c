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
	uint32_t	core = GET_RUNNING_CORE;

	#ifdef PRIVILEGED_USER_S

// Privilege elevation / restoration (R5). RISC-V ecall carries no immediate (unlike ARM's
// svc #N), so the RIGHTS_ELEVATION / SET_USER_MODE ecalls in kern_setPrivilegeMode() are
// distinguished from kernel-message ecalls by the saved return address (mepc, frame word
// [0]), which equals the sanctioned priv_returnElevation / priv_returnRestore label (the
// label sits right after the ecall). Edit the saved frame's mstatus (word [2]) MPP field
// and return to the SAME process — no scheduler, no context switch; first_handle_trap then
// mret's back to it with the new privilege.

	extern	volatile	uintptr_t	vSaveStack[KNB_CORES];
	extern	uint8_t					priv_returnElevation[];
	extern	uint8_t					priv_returnRestore[];

			uint32_t				*frame = (uint32_t *)vSaveStack[core];
			uintptr_t				mepc   = (uintptr_t)frame[0];

	if (mepc == (uintptr_t)priv_returnElevation) {

// elevate: MPP = 3 (M-mode)
			
		frame[2] |= (uint32_t)MSTATUS_MPP;
		return;
	}

	if (mepc == (uintptr_t)priv_returnRestore) {

// restore: MPP = 0 (U-mode)

		frame[2] &= ~(uint32_t)MSTATUS_MPP;
		return;
	}
	#endif

	#if (KNB_CORES == 2)
	if (core == KCORE_0) {
		kernel_message_C0();
	}
	else {
		kernel_message_C1();
	}
	#else
	kernel_message_C0();
	#endif
}
