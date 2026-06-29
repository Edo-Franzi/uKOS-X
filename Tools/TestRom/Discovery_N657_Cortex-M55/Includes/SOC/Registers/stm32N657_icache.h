/*
; stm32N657_icache.
; =================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_icache equates.
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
} ICACHE_TypeDef;

#if (defined(__cplusplus))
#define	ICACHE_NS	reinterpret_cast<ICACHE_TypeDef *>(0x48035000u)
#define	ICACHE_S	reinterpret_cast<ICACHE_TypeDef *>(0x58035000u)

#else
#define	ICACHE_NS	((ICACHE_TypeDef *)0x48035000u)
#define	ICACHE_S	((ICACHE_TypeDef *)0x58035000u)
#endif

// CR Configuration

#define	ICACHE_CR_MISSMRST			(0x1u<<19)
#define	ICACHE_CR_HITMRST			(0x1u<<18)
#define	ICACHE_CR_MISSMEN			(0x1u<<17)
#define	ICACHE_CR_HITMEN			(0x1u<<16)
#define	ICACHE_CR_WAYSEL			(0x1u<<2)
#define	ICACHE_CR_CACHEINV			(0x1u<<1)
#define	ICACHE_CR_EN				(0x1u<<0)

#define	ICACHE_CR_MISSMRST_B_0X0	(0x0u<<19)
#define	ICACHE_CR_MISSMRST_B_0X1	(0x1u<<19)
#define	ICACHE_CR_HITMRST_B_0X0		(0x0u<<18)
#define	ICACHE_CR_HITMRST_B_0X1		(0x1u<<18)
#define	ICACHE_CR_MISSMEN_B_0X0		(0x0u<<17)
#define	ICACHE_CR_MISSMEN_B_0X1		(0x1u<<17)
#define	ICACHE_CR_HITMEN_B_0X0		(0x0u<<16)
#define	ICACHE_CR_HITMEN_B_0X1		(0x1u<<16)
#define	ICACHE_CR_WAYSEL_B_0X0		(0x0u<<2)
#define	ICACHE_CR_WAYSEL_B_0X1		(0x1u<<2)
#define	ICACHE_CR_CACHEINV_B_0X0	(0x0u<<1)
#define	ICACHE_CR_CACHEINV_B_0X1	(0x1u<<1)
#define	ICACHE_CR_EN_B_0X0			(0x0u<<0)
#define	ICACHE_CR_EN_B_0X1			(0x1u<<0)

// SR Configuration

#define	ICACHE_SR_ERRF				(0x1u<<2)
#define	ICACHE_SR_BSYENDF			(0x1u<<1)
#define	ICACHE_SR_BUSYF				(0x1u<<0)

#define	ICACHE_SR_ERRF_B_0X0		(0x0u<<2)
#define	ICACHE_SR_ERRF_B_0X1		(0x1u<<2)
#define	ICACHE_SR_BSYENDF_B_0X0		(0x0u<<1)
#define	ICACHE_SR_BSYENDF_B_0X1		(0x1u<<1)
#define	ICACHE_SR_BUSYF_B_0X0		(0x0u<<0)
#define	ICACHE_SR_BUSYF_B_0X1		(0x1u<<0)

// IER Configuration

#define	ICACHE_IER_ERRIE			(0x1u<<2)
#define	ICACHE_IER_BSYENDIE			(0x1u<<1)

#define	ICACHE_IER_ERRIE_B_0X0		(0x0u<<2)
#define	ICACHE_IER_ERRIE_B_0X1		(0x1u<<2)
#define	ICACHE_IER_BSYENDIE_B_0X0	(0x0u<<1)
#define	ICACHE_IER_BSYENDIE_B_0X1	(0x1u<<1)

// FCR Configuration

#define	ICACHE_FCR_CERRF			(0x1u<<2)
#define	ICACHE_FCR_CBSYENDF			(0x1u<<1)

#define	ICACHE_FCR_CERRF_B_0X0		(0x0u<<2)
#define	ICACHE_FCR_CERRF_B_0X1		(0x1u<<2)
#define	ICACHE_FCR_CBSYENDF_B_0X0	(0x0u<<1)
#define	ICACHE_FCR_CBSYENDF_B_0X1	(0x1u<<1)

// HMONR Configuration

#define	ICACHE_HMONR_HITMON			(0xFFFFFFFFu<<0)
#define	ICACHE_HMONR_HITMON_0		(0x1u<<0)

// MMONR Configuration

#define	ICACHE_MMONR_MISSMON		(0xFFFFu<<0)
#define	ICACHE_MMONR_MISSMON_0		(0x1u<<0)
