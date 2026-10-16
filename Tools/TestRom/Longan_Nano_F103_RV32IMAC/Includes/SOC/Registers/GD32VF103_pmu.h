/*
; GD32VF103_pmu.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_pmu equates.
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

// PMU address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CTL;
	volatile	uint32_t	CS;
} PMU_TypeDef;

#if (defined(__cplusplus))
#define	PMU	reinterpret_cast<PMU_TypeDef *>(0x40007000u)

#else
#define	PMU	((PMU_TypeDef *)0x40007000u)
#endif

// CTL Configuration

#define	PMU_CTL_LDOLP	(0x1u<<0)
#define	PMU_CTL_STBMOD	(0x1u<<1)
#define	PMU_CTL_WURST	(0x1u<<2)
#define	PMU_CTL_STBRST	(0x1u<<3)
#define	PMU_CTL_LVDEN	(0x1u<<4)
#define	PMU_CTL_LVDT	(0x7u<<5)
#define	PMU_CTL_LVDT_0	(0x1u<<5)
#define	PMU_CTL_BKPWEN	(0x1u<<8)

// CS Configuration

#define	PMU_CS_WUF		(0x1u<<0)
#define	PMU_CS_STBF		(0x1u<<1)
#define	PMU_CS_LVDF		(0x1u<<2)
#define	PMU_CS_WUPEN	(0x1u<<8)
