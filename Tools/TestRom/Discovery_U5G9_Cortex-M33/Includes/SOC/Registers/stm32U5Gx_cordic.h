/*
; stm32U5Gx_cordic.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_cordic equates.
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

// CORDIC address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	CSR;
	volatile	uint32_t	WDATA;
	volatile	uint32_t	RDATA;
} CORDIC_TypeDef;

#if (defined(__cplusplus))
#define	CORDIC_NS	reinterpret_cast<CORDIC_TypeDef *>(0x40021000u)
#define	CORDIC_S	reinterpret_cast<CORDIC_TypeDef *>(0x50021000u)

#else
#define	CORDIC_NS	((CORDIC_TypeDef *)0x40021000u)
#define	CORDIC_S	((CORDIC_TypeDef *)0x50021000u)
#endif

// CSR Configuration

#define	CORDIC_CSR_RRDY			(0x1u<<31)
#define	CORDIC_CSR_ARGSIZE		(0x1u<<22)
#define	CORDIC_CSR_RESSIZE		(0x1u<<21)
#define	CORDIC_CSR_NARGS		(0x1u<<20)
#define	CORDIC_CSR_NRES			(0x1u<<19)
#define	CORDIC_CSR_DMAWEN		(0x1u<<18)
#define	CORDIC_CSR_DMAREN		(0x1u<<17)
#define	CORDIC_CSR_IEN			(0x1u<<16)
#define	CORDIC_CSR_SCALE		(0x7u<<8)
#define	CORDIC_CSR_SCALE_0		(0x1u<<8)
#define	CORDIC_CSR_PRECISION	(0xFu<<4)
#define	CORDIC_CSR_PRECISION_0	(0x1u<<4)
#define	CORDIC_CSR_FUNC			(0xFu<<0)
#define	CORDIC_CSR_FUNC_0		(0x1u<<0)

// WDATA Configuration

#define	CORDIC_WDATA_ARG		(0xFFFFFFFFu<<0)
#define	CORDIC_WDATA_ARG_0		(0x1u<<0)

// RDATA Configuration

#define	CORDIC_RDATA_RES		(0xFFFFFFFFu<<0)
#define	CORDIC_RDATA_RES_0		(0x1u<<0)
