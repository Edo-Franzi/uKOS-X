/*
; stm32H757_CM4_ramecc3.
; ======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H757_CM4_ramecc3 equates.
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

// RAMECC3 address definitions
// ---------------------------

typedef struct {
	volatile	uint32_t	IER;
	volatile	uint32_t	RESERVED0[7];
	volatile	uint32_t	M1CR;
	volatile	uint32_t	M1SR;
	volatile	uint32_t	M1FAR;
	volatile	uint32_t	M1FDRL;
	volatile	uint32_t	M1FDRH;
	volatile	uint32_t	M1FECR;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	M2CR;
	volatile	uint32_t	M2SR;
	volatile	uint32_t	M2FAR;
	volatile	uint32_t	M2FDRL;
	volatile	uint32_t	M2FDRH;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	M2FECR;
} RAMECC3_TypeDef;

#if (defined(__cplusplus))
#define	RAMECC3	reinterpret_cast<RAMECC3_TypeDef *>(0x58027000u)

#else
#define	RAMECC3	((RAMECC3_TypeDef *)0x58027000u)
#endif

// IER Configuration

#define	RAMECC3_IER_GECCDEBWIE	(0x1u<<3)
#define	RAMECC3_IER_GECCDEIE	(0x1u<<2)
#define	RAMECC3_IER_GECCSEIE_	(0x1u<<1)
#define	RAMECC3_IER_GIE			(0x1u<<0)

// M1CR Configuration

#define	RAMECC3_M1CR_ECCELEN	(0x1u<<5)
#define	RAMECC3_M1CR_ECCDEBWIE	(0x1u<<4)
#define	RAMECC3_M1CR_ECCDEIE	(0x1u<<3)
#define	RAMECC3_M1CR_ECCSEIE	(0x1u<<2)

// M1SR Configuration

#define	RAMECC3_M1SR_DEBWDF		(0x1u<<2)
#define	RAMECC3_M1SR_DEDF		(0x1u<<1)
#define	RAMECC3_M1SR_SEDCF		(0x1u<<0)

// M1FAR Configuration

#define	RAMECC3_M1FAR_FADD		(0xFFFFFFFFu<<0)
#define	RAMECC3_M1FAR_FADD_0	(0x1u<<0)

// M1FDRL Configuration

#define	RAMECC3_M1FDRL_FDATAL	(0xFFFFFFFFu<<0)
#define	RAMECC3_M1FDRL_FDATAL_0	(0x1u<<0)

// M1FDRH Configuration

#define	RAMECC3_M1FDRH_FDATAH	(0xFFFFFFFFu<<0)
#define	RAMECC3_M1FDRH_FDATAH_0	(0x1u<<0)

// M1FECR Configuration

#define	RAMECC3_M1FECR_FEC		(0xFFFFFFFFu<<0)
#define	RAMECC3_M1FECR_FEC_0	(0x1u<<0)

// M2CR Configuration

#define	RAMECC3_M2CR_ECCELEN	(0x1u<<5)
#define	RAMECC3_M2CR_ECCDEBWIE	(0x1u<<4)
#define	RAMECC3_M2CR_ECCDEIE	(0x1u<<3)
#define	RAMECC3_M2CR_ECCSEIE	(0x1u<<2)

// M2SR Configuration

#define	RAMECC3_M2SR_DEBWDF		(0x1u<<2)
#define	RAMECC3_M2SR_DEDF		(0x1u<<1)
#define	RAMECC3_M2SR_SEDCF		(0x1u<<0)

// M2FAR Configuration

#define	RAMECC3_M2FAR_FADD		(0xFFFFFFFFu<<0)
#define	RAMECC3_M2FAR_FADD_0	(0x1u<<0)

// M2FDRL Configuration

#define	RAMECC3_M2FDRL_FDATAL	(0xFFFFFFFFu<<0)
#define	RAMECC3_M2FDRL_FDATAL_0	(0x1u<<0)

// M2FDRH Configuration

#define	RAMECC3_M2FDRH_FDATAH	(0xFFFFFFFFu<<0)
#define	RAMECC3_M2FDRH_FDATAH_0	(0x1u<<0)

// M2FECR Configuration

#define	RAMECC3_M2FECR_FEC		(0xFFFFFFFFu<<0)
#define	RAMECC3_M2FECR_FEC_0	(0x1u<<0)
