/*
; stm32N657_xspim.
; ================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_xspim equates.
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

// XSPIM address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	CR;
} XSPIM_TypeDef;

#if (defined(__cplusplus))
#define	XSPIM_NS	reinterpret_cast<XSPIM_TypeDef *>(0x4802B400u)
#define	XSPIM_S		reinterpret_cast<XSPIM_TypeDef *>(0x5802B400u)

#else
#define	XSPIM_NS	((XSPIM_TypeDef *)0x4802B400u)
#define	XSPIM_S		((XSPIM_TypeDef *)0x5802B400u)
#endif

// CR Configuration

#define	XSPIM_CR_REQ2ACK_TIME		(0xFFu<<16)
#define	XSPIM_CR_REQ2ACK_TIME_0		(0x1u<<16)
#define	XSPIM_CR_CSSEL_OVR_O2		(0x1u<<6)
#define	XSPIM_CR_CSSEL_OVR_O1		(0x1u<<5)
#define	XSPIM_CR_CSSEL_OVR_EN		(0x1u<<4)
#define	XSPIM_CR_MODE				(0x1u<<1)
#define	XSPIM_CR_MUXEN				(0x1u<<0)

#define	XSPIM_CR_CSSEL_OVR_O2_B_0X0	(0x0u<<6)
#define	XSPIM_CR_CSSEL_OVR_O2_B_0X1	(0x1u<<6)
#define	XSPIM_CR_CSSEL_OVR_O1_B_0X0	(0x0u<<5)
#define	XSPIM_CR_CSSEL_OVR_O1_B_0X1	(0x1u<<5)
#define	XSPIM_CR_CSSEL_OVR_EN_B_0X0	(0x0u<<4)
#define	XSPIM_CR_CSSEL_OVR_EN_B_0X1	(0x1u<<4)
#define	XSPIM_CR_MODE_B_0X0			(0x0u<<1)
#define	XSPIM_CR_MODE_B_0X1			(0x1u<<1)
#define	XSPIM_CR_MUXEN_B_0X0		(0x0u<<0)
#define	XSPIM_CR_MUXEN_B_0X1		(0x1u<<0)
