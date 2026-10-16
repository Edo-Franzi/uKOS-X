/*
; GD32VF103_fwdgt.
; ================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_fwdgt equates.
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

// FWDGT address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	CTL;
	volatile	uint32_t	PSC;
	volatile	uint32_t	RLD;
	volatile	uint32_t	STAT;
} FWDGT_TypeDef;

#if (defined(__cplusplus))
#define	FWDGT	reinterpret_cast<FWDGT_TypeDef *>(0x40003000u)

#else
#define	FWDGT	((FWDGT_TypeDef *)0x40003000u)
#endif

// CTL Configuration

#define	FWDGT_CTL_CMD	(0xFFFFu<<0)
#define	FWDGT_CTL_CMD_0	(0x1u<<0)

// PSC Configuration

#define	FWDGT_PSC_PSC	(0x7u<<0)
#define	FWDGT_PSC_PSC_0	(0x1u<<0)

// RLD Configuration

#define	FWDGT_RLD_RLD	(0xFFFu<<0)
#define	FWDGT_RLD_RLD_0	(0x1u<<0)

// STAT Configuration

#define	FWDGT_STAT_RUD	(0x1u<<1)
#define	FWDGT_STAT_PUD	(0x1u<<0)
