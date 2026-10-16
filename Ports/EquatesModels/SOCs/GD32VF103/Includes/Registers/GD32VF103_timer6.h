/*
; GD32VF103_timer6.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_timer6 equates.
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

// TIMER6 address definitions
// --------------------------

typedef struct {
	volatile	uint16_t	CTL0;
	volatile	uint16_t	RESERVED0;
	volatile	uint16_t	CTL1;
	volatile	uint16_t	RESERVED1[3];
	volatile	uint16_t	DMAINTEN;
	volatile	uint16_t	RESERVED2;
	volatile	uint16_t	INTF;
	volatile	uint16_t	RESERVED3;
	volatile	uint16_t	SWEVG;
	volatile	uint16_t	RESERVED4[7];
	volatile	uint16_t	CNT;
	volatile	uint16_t	RESERVED5;
	volatile	uint16_t	PSC;
	volatile	uint16_t	RESERVED6;
	volatile	uint16_t	CAR;
} TIMER6_TypeDef;

#if (defined(__cplusplus))
#define	TIMER6	reinterpret_cast<TIMER6_TypeDef *>(0x40001400u)

#else
#define	TIMER6	((TIMER6_TypeDef *)0x40001400u)
#endif

// CTL0 Configuration

#define	TIMER6_CTL0_CEN			(0x1u<<0)
#define	TIMER6_CTL0_UPDIS		(0x1u<<1)
#define	TIMER6_CTL0_UPS			(0x1u<<2)
#define	TIMER6_CTL0_SPM			(0x1u<<3)
#define	TIMER6_CTL0_ARSE		(0x1u<<7)

// CTL1 Configuration

#define	TIMER6_CTL1_MMC			(0x7u<<4)
#define	TIMER6_CTL1_MMC_0		(0x1u<<4)

// DMAINTEN Configuration

#define	TIMER6_DMAINTEN_UPIE	(0x1u<<0)
#define	TIMER6_DMAINTEN_UPDEN	(0x1u<<8)

// INTF Configuration

#define	TIMER6_INTF_UPIF		(0x1u<<0)

// SWEVG Configuration

#define	TIMER6_SWEVG_UPG		(0x1u<<0)

// CNT Configuration

#define	TIMER6_CNT_CNT			(0xFFFFu<<0)
#define	TIMER6_CNT_CNT_0		(0x1u<<0)

// PSC Configuration

#define	TIMER6_PSC_PSC			(0xFFFFu<<0)
#define	TIMER6_PSC_PSC_0		(0x1u<<0)

// CAR Configuration

#define	TIMER6_CAR_CARL			(0xFFFFu<<0)
#define	TIMER6_CAR_CARL_0		(0x1u<<0)
