/*
; stm32U5Gx_icache.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_icache equates.
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

// ICACHE address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	IER;
	volatile	uint32_t	FCR;
	volatile	uint32_t	HMONR;
	volatile	uint32_t	MMONR;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	CRR0;
	volatile	uint32_t	CRR1;
	volatile	uint32_t	CRR2;
	volatile	uint32_t	CRR3;
} ICACHE_TypeDef;

#if (defined(__cplusplus))
#define	ICACHE_NS	reinterpret_cast<ICACHE_TypeDef *>(0x40030400u)
#define	ICACHE_S	reinterpret_cast<ICACHE_TypeDef *>(0x50030400u)

#else
#define	ICACHE_NS	((ICACHE_TypeDef *)0x40030400u)
#define	ICACHE_S	((ICACHE_TypeDef *)0x50030400u)
#endif

// CR Configuration

#define	ICACHE_CR_MISSMRST		(0x1u<<19)
#define	ICACHE_CR_HITMRST		(0x1u<<18)
#define	ICACHE_CR_MISSMEN		(0x1u<<17)
#define	ICACHE_CR_HITMEN		(0x1u<<16)
#define	ICACHE_CR_WAYSEL		(0x1u<<2)
#define	ICACHE_CR_CACHEINV		(0x1u<<1)
#define	ICACHE_CR_EN			(0x1u<<0)

// SR Configuration

#define	ICACHE_SR_ERRF			(0x1u<<2)
#define	ICACHE_SR_BSYENDF		(0x1u<<1)
#define	ICACHE_SR_BUSYF			(0x1u<<0)

// IER Configuration

#define	ICACHE_IER_ERRIE		(0x1u<<2)
#define	ICACHE_IER_BSYENDIE		(0x1u<<1)

// FCR Configuration

#define	ICACHE_FCR_CERRF		(0x1u<<2)
#define	ICACHE_FCR_CBSYENDF		(0x1u<<1)

// HMONR Configuration

#define	ICACHE_HMONR_HITMON		(0xFFFFFFFFu<<0)
#define	ICACHE_HMONR_HITMON_0	(0x1u<<0)

// MMONR Configuration

#define	ICACHE_MMONR_MISSMON	(0xFFFFu<<0)
#define	ICACHE_MMONR_MISSMON_0	(0x1u<<0)

// CRR0 Configuration

#define	ICACHE_CRR0_HBURST		(0x1u<<31)
#define	ICACHE_CRR0_MSTSEL		(0x1u<<28)
#define	ICACHE_CRR0_REMAPADDR	(0x7FFu<<16)
#define	ICACHE_CRR0_REMAPADDR_0	(0x1u<<16)
#define	ICACHE_CRR0_REN			(0x1u<<15)
#define	ICACHE_CRR0_RSIZE		(0x7u<<9)
#define	ICACHE_CRR0_RSIZE_0		(0x1u<<9)
#define	ICACHE_CRR0_BASEADDR	(0xFFu<<0)
#define	ICACHE_CRR0_BASEADDR_0	(0x1u<<0)

// CRR1 Configuration

#define	ICACHE_CRR1_HBURST		(0x1u<<31)
#define	ICACHE_CRR1_MSTSEL		(0x1u<<28)
#define	ICACHE_CRR1_REMAPADDR	(0x7FFu<<16)
#define	ICACHE_CRR1_REMAPADDR_0	(0x1u<<16)
#define	ICACHE_CRR1_REN			(0x1u<<15)
#define	ICACHE_CRR1_RSIZE		(0x7u<<9)
#define	ICACHE_CRR1_RSIZE_0		(0x1u<<9)
#define	ICACHE_CRR1_BASEADDR	(0xFFu<<0)
#define	ICACHE_CRR1_BASEADDR_0	(0x1u<<0)

// CRR2 Configuration

#define	ICACHE_CRR2_HBURST		(0x1u<<31)
#define	ICACHE_CRR2_MSTSEL		(0x1u<<28)
#define	ICACHE_CRR2_REMAPADDR	(0x7FFu<<16)
#define	ICACHE_CRR2_REMAPADDR_0	(0x1u<<16)
#define	ICACHE_CRR2_REN			(0x1u<<15)
#define	ICACHE_CRR2_RSIZE		(0x7u<<9)
#define	ICACHE_CRR2_RSIZE_0		(0x1u<<9)
#define	ICACHE_CRR2_BASEADDR	(0xFFu<<0)
#define	ICACHE_CRR2_BASEADDR_0	(0x1u<<0)

// CRR3 Configuration

#define	ICACHE_CRR3_HBURST		(0x1u<<31)
#define	ICACHE_CRR3_MSTSEL		(0x1u<<28)
#define	ICACHE_CRR3_REMAPADDR	(0x7FFu<<16)
#define	ICACHE_CRR3_REMAPADDR_0	(0x1u<<16)
#define	ICACHE_CRR3_REN			(0x1u<<15)
#define	ICACHE_CRR3_RSIZE		(0x7u<<9)
#define	ICACHE_CRR3_RSIZE_0		(0x1u<<9)
#define	ICACHE_CRR3_BASEADDR	(0xFFu<<0)
#define	ICACHE_CRR3_BASEADDR_0	(0x1u<<0)
