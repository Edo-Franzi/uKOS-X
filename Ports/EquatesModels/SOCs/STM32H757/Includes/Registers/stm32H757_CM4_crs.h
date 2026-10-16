/*
; stm32H757_CM4_crs.
; ==================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H757_CM4_crs equates.
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

// CRS address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	CFGR;
	volatile	uint32_t	ISR;
	volatile	uint32_t	ICR;
} CRS_TypeDef;

#if (defined(__cplusplus))
#define	CRS	reinterpret_cast<CRS_TypeDef *>(0x40008400u)

#else
#define	CRS	((CRS_TypeDef *)0x40008400u)
#endif

// CR Configuration

#define	CRS_CR_TRIM			(0x3Fu<<8)
#define	CRS_CR_TRIM_0		(0x1u<<8)
#define	CRS_CR_SWSYNC		(0x1u<<7)
#define	CRS_CR_AUTOTRIMEN	(0x1u<<6)
#define	CRS_CR_CEN			(0x1u<<5)
#define	CRS_CR_ESYNCIE		(0x1u<<3)
#define	CRS_CR_ERRIE		(0x1u<<2)
#define	CRS_CR_SYNCWARNIE	(0x1u<<1)
#define	CRS_CR_SYNCOKIE		(0x1u<<0)

// CFGR Configuration

#define	CRS_CFGR_SYNCPOL	(0x1u<<31)
#define	CRS_CFGR_SYNCSRC	(0x3u<<28)
#define	CRS_CFGR_SYNCSRC_0	(0x1u<<28)
#define	CRS_CFGR_SYNCDIV	(0x7u<<24)
#define	CRS_CFGR_SYNCDIV_0	(0x1u<<24)
#define	CRS_CFGR_FELIM		(0xFFu<<16)
#define	CRS_CFGR_FELIM_0	(0x1u<<16)
#define	CRS_CFGR_RELOAD		(0xFFFFu<<0)
#define	CRS_CFGR_RELOAD_0	(0x1u<<0)

// ISR Configuration

#define	CRS_ISR_FECAP		(0xFFFFu<<16)
#define	CRS_ISR_FECAP_0		(0x1u<<16)
#define	CRS_ISR_FEDIR		(0x1u<<15)
#define	CRS_ISR_TRIMOVF		(0x1u<<10)
#define	CRS_ISR_SYNCMISS	(0x1u<<9)
#define	CRS_ISR_SYNCERR		(0x1u<<8)
#define	CRS_ISR_ESYNCF		(0x1u<<3)
#define	CRS_ISR_ERRF		(0x1u<<2)
#define	CRS_ISR_SYNCWARNF	(0x1u<<1)
#define	CRS_ISR_SYNCOKF		(0x1u<<0)

// ICR Configuration

#define	CRS_ICR_ESYNCC		(0x1u<<3)
#define	CRS_ICR_ERRC		(0x1u<<2)
#define	CRS_ICR_SYNCWARNC	(0x1u<<1)
#define	CRS_ICR_SYNCOKC		(0x1u<<0)
