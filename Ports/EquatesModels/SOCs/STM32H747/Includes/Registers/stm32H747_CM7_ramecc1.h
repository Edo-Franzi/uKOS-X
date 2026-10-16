/*
; stm32H747_CM7_ramecc1.
; ======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM7_ramecc1 equates.
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

// RAMECC1 address definitions
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
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	M3CR;
	volatile	uint32_t	M3SR;
	volatile	uint32_t	M3FAR;
	volatile	uint32_t	M3FDRL;
	volatile	uint32_t	M3FDRH;
	volatile	uint32_t	RESERVED4[2];
	volatile	uint32_t	M3FECR;
	volatile	uint32_t	M4CR;
	volatile	uint32_t	M4SR;
	volatile	uint32_t	M4FAR;
	volatile	uint32_t	M4FDRL;
		union {
	volatile	uint32_t	M4FDRH;
	volatile	uint32_t	M4FECR;
		};
	volatile	uint32_t	RESERVED5[3];
	volatile	uint32_t	M5CR;
	volatile	uint32_t	M5SR;
	volatile	uint32_t	M5FAR;
	volatile	uint32_t	M5FDRL;
	volatile	uint32_t	M5FDRH;
	volatile	uint32_t	M5FECR;
} RAMECC1_TypeDef;

#if (defined(__cplusplus))
#define	RAMECC1	reinterpret_cast<RAMECC1_TypeDef *>(0x52009000u)

#else
#define	RAMECC1	((RAMECC1_TypeDef *)0x52009000u)
#endif

// IER Configuration

#define	RAMECC1_IER_GECCDEBWIE		(0x1u<<3)
#define	RAMECC1_IER_GECCDEIE		(0x1u<<2)
#define	RAMECC1_IER_GECCSEIE_		(0x1u<<1)
#define	RAMECC1_IER_GIE				(0x1u<<0)

// M1CR Configuration

#define	RAMECC1_M1CR_ECCELEN		(0x1u<<5)
#define	RAMECC1_M1CR_ECCDEBWIE		(0x1u<<4)
#define	RAMECC1_M1CR_ECCDEIE		(0x1u<<3)
#define	RAMECC1_M1CR_ECCSEIE		(0x1u<<2)

// M1SR Configuration

#define	RAMECC1_M1SR_ECCELEN		(0x1u<<5)
#define	RAMECC1_M1SR_ECCDEBWIE		(0x1u<<4)
#define	RAMECC1_M1SR_ECCDEIE		(0x1u<<3)
#define	RAMECC1_M1SR_ECCSEIE		(0x1u<<2)

// M1FAR Configuration

#define	RAMECC1_M1FAR_ECCELEN		(0x1u<<5)
#define	RAMECC1_M1FAR_ECCDEBWIE		(0x1u<<4)
#define	RAMECC1_M1FAR_ECCDEIE		(0x1u<<3)
#define	RAMECC1_M1FAR_ECCSEIE		(0x1u<<2)

// M1FDRL Configuration

#define	RAMECC1_M1FDRL_ECCELEN		(0x1u<<5)
#define	RAMECC1_M1FDRL_ECCDEBWIE	(0x1u<<4)
#define	RAMECC1_M1FDRL_ECCDEIE		(0x1u<<3)
#define	RAMECC1_M1FDRL_ECCSEIE		(0x1u<<2)

// M1FDRH Configuration

#define	RAMECC1_M1FDRH_ECCELEN		(0x1u<<5)
#define	RAMECC1_M1FDRH_ECCDEBWIE	(0x1u<<4)
#define	RAMECC1_M1FDRH_ECCDEIE		(0x1u<<3)
#define	RAMECC1_M1FDRH_ECCSEIE		(0x1u<<2)

// M1FECR Configuration

#define	RAMECC1_M1FECR_DEBWDF		(0x1u<<2)
#define	RAMECC1_M1FECR_DEDF			(0x1u<<1)
#define	RAMECC1_M1FECR_SEDCF		(0x1u<<0)

// M2CR Configuration

#define	RAMECC1_M2CR_DEBWDF			(0x1u<<2)
#define	RAMECC1_M2CR_DEDF			(0x1u<<1)
#define	RAMECC1_M2CR_SEDCF			(0x1u<<0)

// M2SR Configuration

#define	RAMECC1_M2SR_DEBWDF			(0x1u<<2)
#define	RAMECC1_M2SR_DEDF			(0x1u<<1)
#define	RAMECC1_M2SR_SEDCF			(0x1u<<0)

// M2FAR Configuration

#define	RAMECC1_M2FAR_DEBWDF		(0x1u<<2)
#define	RAMECC1_M2FAR_DEDF			(0x1u<<1)
#define	RAMECC1_M2FAR_SEDCF			(0x1u<<0)

// M2FDRL Configuration

#define	RAMECC1_M2FDRL_DEBWDF		(0x1u<<2)
#define	RAMECC1_M2FDRL_DEDF			(0x1u<<1)
#define	RAMECC1_M2FDRL_SEDCF		(0x1u<<0)

// M2FDRH Configuration

#define	RAMECC1_M2FDRH_FADD			(0xFFFFFFFFu<<0)
#define	RAMECC1_M2FDRH_FADD_0		(0x1u<<0)

// M2FECR Configuration

#define	RAMECC1_M2FECR_FADD			(0xFFFFFFFFu<<0)
#define	RAMECC1_M2FECR_FADD_0		(0x1u<<0)

// M3CR Configuration

#define	RAMECC1_M3CR_FADD			(0xFFFFFFFFu<<0)
#define	RAMECC1_M3CR_FADD_0			(0x1u<<0)

// M3SR Configuration

#define	RAMECC1_M3SR_FADD			(0xFFFFFFFFu<<0)
#define	RAMECC1_M3SR_FADD_0			(0x1u<<0)

// M3FAR Configuration

#define	RAMECC1_M3FAR_FADD			(0xFFFFFFFFu<<0)
#define	RAMECC1_M3FAR_FADD_0		(0x1u<<0)

// M3FDRL Configuration

#define	RAMECC1_M3FDRL_FDATAL		(0xFFFFFFFFu<<0)
#define	RAMECC1_M3FDRL_FDATAL_0		(0x1u<<0)

// M3FDRH Configuration

#define	RAMECC1_M3FDRH_FDATAL		(0xFFFFFFFFu<<0)
#define	RAMECC1_M3FDRH_FDATAL_0		(0x1u<<0)

// M3FECR Configuration

#define	RAMECC1_M3FECR_FDATAL		(0xFFFFFFFFu<<0)
#define	RAMECC1_M3FECR_FDATAL_0		(0x1u<<0)

// M4CR Configuration

#define	RAMECC1_M4CR_FDATAL			(0xFFFFFFFFu<<0)
#define	RAMECC1_M4CR_FDATAL_0		(0x1u<<0)

// M4SR Configuration

#define	RAMECC1_M4SR_FDATAL			(0xFFFFFFFFu<<0)
#define	RAMECC1_M4SR_FDATAL_0		(0x1u<<0)

// M4FAR Configuration

#define	RAMECC1_M4FAR_FDATAH		(0xFFFFFFFFu<<0)
#define	RAMECC1_M4FAR_FDATAH_0		(0x1u<<0)

// M4FDRL Configuration

#define	RAMECC1_M4FDRL_FDATAH		(0xFFFFFFFFu<<0)
#define	RAMECC1_M4FDRL_FDATAH_0		(0x1u<<0)

// M4FDRH Configuration

#define	RAMECC1_M4FDRH_FDATAH		(0xFFFFFFFFu<<0)
#define	RAMECC1_M4FDRH_FDATAH_0		(0x1u<<0)

// M4FECR Configuration

#define	RAMECC1_M4FECR_FDATAH		(0xFFFFFFFFu<<0)
#define	RAMECC1_M4FECR_FDATAH_0		(0x1u<<0)

// M5CR Configuration

#define	RAMECC1_M5CR_FEC			(0xFFFFFFFFu<<0)
#define	RAMECC1_M5CR_FEC_0			(0x1u<<0)

// M5SR Configuration

#define	RAMECC1_M5SR_FEC			(0xFFFFFFFFu<<0)
#define	RAMECC1_M5SR_FEC_0			(0x1u<<0)

// M5FAR Configuration

#define	RAMECC1_M5FAR_FEC			(0xFFFFFFFFu<<0)
#define	RAMECC1_M5FAR_FEC_0			(0x1u<<0)

// M5FDRL Configuration

#define	RAMECC1_M5FDRL_FEC			(0xFFFFFFFFu<<0)
#define	RAMECC1_M5FDRL_FEC_0		(0x1u<<0)

// M5FDRH Configuration

#define	RAMECC1_M5FDRH_FEC			(0xFFFFFFFFu<<0)
#define	RAMECC1_M5FDRH_FEC_0		(0x1u<<0)

// M5FECR Configuration

#define	RAMECC1_M5FECR_FEC			(0xFFFFFFFFu<<0)
#define	RAMECC1_M5FECR_FEC_0		(0x1u<<0)
