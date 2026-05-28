/*
; stub_kern_kernel.
; =================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the connection of the "kern" manager to the uKernel device.
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

// Connect the physical device to the logical manager
// --------------------------------------------------

#define	TIMER_C0						REG(TIMER0)
#define	TIMER_C1						REG(TIMER1)
#define	TIMER_ALA0_VECTOR_NUMBER_C0		TIMER0_IRQ_0_C0_IRQn
#define	TIMER_ALA0_VECTOR_NUMBER_C1		TIMER1_IRQ_0_C1_IRQn
#define	TIMER_ALA1_VECTOR_NUMBER_C0		TIMER0_IRQ_1_C0_IRQn
#define	TIMER_ALA1_VECTOR_NUMBER_C1		TIMER1_IRQ_1_C1_IRQn

#if (defined(__riscv))

#include	"Registers/rv32_csr.h"
#include	"core.h"
#include	"model_kernel_tim0_ecall_C0.c_inc"
#include	"model_kernel_tim1_ecall_C1.c_inc"

#else
#define	PendSV_VECTOR_NUMBER_C0			PendSV_C0_IRQn
#define	PendSV_VECTOR_NUMBER_C1			PendSV_C1_IRQn

#include	"model_kernel_tim_0_a0_a1_svc_C0.c_inc"
#include	"model_kernel_tim_1_a0_a1_svc_C1.c_inc"
#endif

void	stub_kern_init(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;
	if (core == KCORE_0) { model_kernel_init_C0(); }
	else				 { model_kernel_init_C1(); }
}

void	stub_kern_runKernel(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	if (core == KCORE_0) { model_kernel_runKernel_C0(); }
	else				 { model_kernel_runKernel_C1(); }
}

void	stub_kern_setLowPower(uint8_t mode) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	if (core == KCORE_0) { model_kernel_setLowPower_C0(mode); }
	else				 { model_kernel_setLowPower_C1(mode); }
}

void	stub_kern_readTickCount(uint64_t *tickCount) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	if (core == KCORE_0) { model_kernel_readTickCount_C0(tickCount); }
	else				 { model_kernel_readTickCount_C1(tickCount); }
}

void	stub_kern_newProcessTimeout(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	if (core == KCORE_0) { model_kernel_newProcessTimeout_C0(); }
	else				 { model_kernel_newProcessTimeout_C1(); }
}

void	stub_kern_stopProcessTimeout(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	if (core == KCORE_0) { model_kernel_stopProcessTimeout_C0(); }
	else				 { model_kernel_stopProcessTimeout_C1(); }
}
