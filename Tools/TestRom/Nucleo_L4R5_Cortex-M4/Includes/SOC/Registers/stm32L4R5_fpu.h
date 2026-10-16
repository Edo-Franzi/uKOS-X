/*
; stm32L4R5_fpu.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_fpu equates.
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

#pragma	once

// FPU address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	FPCCR;
	volatile	uint32_t	FPCAR;
	volatile	uint32_t	FPSCR;
} FPU_TypeDef;

#if (defined(__cplusplus))
#define	FPU	reinterpret_cast<FPU_TypeDef *>(0xE000EF34u)

#else
#define	FPU	((FPU_TypeDef *)0xE000EF34u)
#endif

// FPCCR Configuration

#define	FPU_FPCCR_ASPEN		(0x1u<<31)
#define	FPU_FPCCR_LSPEN		(0x1u<<30)
#define	FPU_FPCCR_MONRDY	(0x1u<<8)
#define	FPU_FPCCR_BFRDY		(0x1u<<6)
#define	FPU_FPCCR_MMRDY		(0x1u<<5)
#define	FPU_FPCCR_HFRDY		(0x1u<<4)
#define	FPU_FPCCR_THREAD	(0x1u<<3)
#define	FPU_FPCCR_USER		(0x1u<<1)
#define	FPU_FPCCR_LSPACT	(0x1u<<0)

// FPCAR Configuration

#define	FPU_FPCAR_ADDRESS	(0x1FFFFFFFu<<3)
#define	FPU_FPCAR_ADDRESS_0	(0x1u<<3)

// FPSCR Configuration

#define	FPU_FPSCR_N			(0x1u<<31)
#define	FPU_FPSCR_Z			(0x1u<<30)
#define	FPU_FPSCR_C			(0x1u<<29)
#define	FPU_FPSCR_V			(0x1u<<28)
#define	FPU_FPSCR_AHP		(0x1u<<26)
#define	FPU_FPSCR_DN		(0x1u<<25)
#define	FPU_FPSCR_FZ		(0x1u<<24)
#define	FPU_FPSCR_RMODE		(0x3u<<22)
#define	FPU_FPSCR_RMODE_0	(0x1u<<22)
#define	FPU_FPSCR_IDC		(0x1u<<7)
#define	FPU_FPSCR_IXC		(0x1u<<4)
#define	FPU_FPSCR_UFC		(0x1u<<3)
#define	FPU_FPSCR_OFC		(0x1u<<2)
#define	FPU_FPSCR_DZC		(0x1u<<1)
#define	FPU_FPSCR_IOC		(0x1u<<0)
