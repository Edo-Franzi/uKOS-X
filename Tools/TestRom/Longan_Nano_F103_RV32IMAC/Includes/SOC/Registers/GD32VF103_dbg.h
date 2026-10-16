/*
; GD32VF103_dbg.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_dbg equates.
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

// DBG address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	ID;
	volatile	uint32_t	CTL;
} DBG_TypeDef;

#if (defined(__cplusplus))
#define	DBG	reinterpret_cast<DBG_TypeDef *>(0xE0042000u)

#else
#define	DBG	((DBG_TypeDef *)0xE0042000u)
#endif

// ID Configuration

#define	DBG_ID_ID_CODE		(0xFFFFFFFFu<<0)
#define	DBG_ID_ID_CODE_0	(0x1u<<0)

// CTL Configuration

#define	DBG_CTL_CAN1_HOLD	(0x1u<<21)
#define	DBG_CTL_TIMER6_HOLD	(0x1u<<20)
#define	DBG_CTL_TIMER5_HOLD	(0x1u<<19)
#define	DBG_CTL_TIMER4_HOLD	(0x1u<<18)
#define	DBG_CTL_I2C1_HOLD	(0x1u<<16)
#define	DBG_CTL_I2C0_HOLD	(0x1u<<15)
#define	DBG_CTL_CAN0_HOLD	(0x1u<<14)
#define	DBG_CTL_TIMER3_HOLD	(0x1u<<13)
#define	DBG_CTL_TIMER2_HOLD	(0x1u<<12)
#define	DBG_CTL_TIMER1_HOLD	(0x1u<<11)
#define	DBG_CTL_TIMER0_HOLD	(0x1u<<10)
#define	DBG_CTL_WWDGT_HOLD	(0x1u<<9)
#define	DBG_CTL_FWDGT_HOLD	(0x1u<<8)
#define	DBG_CTL_STB_HOLD	(0x1u<<2)
#define	DBG_CTL_DSLP_HOLD	(0x1u<<1)
#define	DBG_CTL_SLP_HOLD	(0x1u<<0)
