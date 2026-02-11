/*
; fpe.
; ====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		FPE equates.
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

// FPE address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	FPCCR;
	volatile	uint32_t	FPCAR;
	volatile	uint32_t	FPDSCR;
	volatile	uint32_t	MVFR0;
	volatile	uint32_t	MVFR1;
	volatile	uint32_t	MVFR2;
} FPE_TypeDef;

#if (defined(__cplusplus))
#define	FPE_S	reinterpret_cast<FPE_TypeDef *>(0xE000EF30u)
#define	FPE_NS	reinterpret_cast<FPE_TypeDef *>(0xE002EF30u)

#else
#define	FPE_S	((FPE_TypeDef *)0xE000EF30u)
#define	FPE_NS	((FPE_TypeDef *)0xE002EF30u)
#endif

// FPCCR Configuration

#define	FPE_FPCCR_LSPACT		(0x1u<<0)
#define	FPE_FPCCR_USER			(0x1u<<1)
#define	FPE_FPCCR_S				(0x1u<<2)
#define	FPE_FPCCR_THREAD		(0x1u<<3)
#define	FPE_FPCCR_HFRDY			(0x1u<<4)
#define	FPE_FPCCR_MMRDY			(0x1u<<5)
#define	FPE_FPCCR_BFRDY			(0x1u<<6)
#define	FPE_FPCCR_SFRDY			(0x1u<<7)
#define	FPE_FPCCR_MONRDY		(0x1u<<8)
#define	FPE_FPCCR_SPLIMVIOL		(0x1u<<9)
#define	FPE_FPCCR_UFRDY			(0x1u<<10)
#define	FPE_FPCCR_TS			(0x1u<<26)
#define	FPE_FPCCR_CLRONRETS		(0x1u<<27)
#define	FPE_FPCCR_CLRONRET		(0x1u<<28)
#define	FPE_FPCCR_LSPENS		(0x1u<<29)
#define	FPE_FPCCR_LSPEN			(0x1u<<30)
#define	FPE_FPCCR_ASPEN			(0x1u<<31)

// FPCAR Configuration

#define	FPE_FPCAR_ADDRESS		(0x1FFFFFFFu<<3)
#define	FPE_FPCAR_ADDRESS_0		(0x1u<<3)

// FPDSCR Configuration

#define	FPE_FPDSCR_RMODE		(0x3u<<22)
#define	FPE_FPDSCR_RMODE_0		(0x1u<<22)
#define	FPE_FPDSCR_FZ			(0x1u<<24)
#define	FPE_FPDSCR_DN			(0x1u<<25)
#define	FPE_FPDSCR_AHP			(0x1u<<26)

// MVFR0 Configuration

#define	FPE_MVFR0_SIMDREG		(0xFu<<0)
#define	FPE_MVFR0_SIMDREG_0		(0x1u<<0)
#define	FPE_MVFR0_FPSP			(0xFu<<4)
#define	FPE_MVFR0_FPSP_0		(0x1u<<4)
#define	FPE_MVFR0_FPDP			(0xFu<<8)
#define	FPE_MVFR0_FPDP_0		(0x1u<<8)
#define	FPE_MVFR0_FPDIVIDE		(0xFu<<16)
#define	FPE_MVFR0_FPDIVIDE_0	(0x1u<<16)
#define	FPE_MVFR0_FPSQRT		(0xFu<<20)
#define	FPE_MVFR0_FPSQRT_0		(0x1u<<20)
#define	FPE_MVFR0_FPROUND		(0xFu<<28)
#define	FPE_MVFR0_FPROUND_0		(0x1u<<28)

// MVFR1 Configuration

#define	FPE_MVFR1_FPFTZ			(0xFu<<0)
#define	FPE_MVFR1_FPFTZ_0		(0x1u<<0)
#define	FPE_MVFR1_FPDNAN		(0xFu<<4)
#define	FPE_MVFR1_FPDNAN_0		(0x1u<<4)
#define	FPE_MVFR1_FPHP			(0xFu<<24)
#define	FPE_MVFR1_FPHP_0		(0x1u<<24)
#define	FPE_MVFR1_FMAC			(0xFu<<28)
#define	FPE_MVFR1_FMAC_0		(0x1u<<28)

// MVFR2 Configuration

#define	FPE_MVFR2_FPMISC		(0xFu<<4)
#define	FPE_MVFR2_FPMISC_0		(0x1u<<4)
