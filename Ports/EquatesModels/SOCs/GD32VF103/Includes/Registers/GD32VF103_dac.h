/*
; GD32VF103_dac.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_dac equates.
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

// DAC address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CTL;
	volatile	uint32_t	SWT;
	volatile	uint32_t	DAC0_R12DH;
	volatile	uint32_t	DAC0_L12DH;
	volatile	uint32_t	DAC0_R8DH;
	volatile	uint32_t	DAC1_R12DH;
	volatile	uint32_t	DAC1_L12DH;
	volatile	uint32_t	DAC1_R8DH;
	volatile	uint32_t	DACC_R12DH;
	volatile	uint32_t	DACC_L12DH;
	volatile	uint32_t	DACC_R8DH;
	volatile	uint32_t	DAC0_DO;
	volatile	uint32_t	DAC1_DO;
} DAC_TypeDef;

#if (defined(__cplusplus))
#define	DAC	reinterpret_cast<DAC_TypeDef *>(0x40007400u)

#else
#define	DAC	((DAC_TypeDef *)0x40007400u)
#endif

// CTL Configuration

#define	DAC_CTL_DDMAEN1				(0x1u<<28)
#define	DAC_CTL_DWBW1				(0xFu<<24)
#define	DAC_CTL_DWBW1_0				(0x1u<<24)
#define	DAC_CTL_DWM1				(0x3u<<22)
#define	DAC_CTL_DWM1_0				(0x1u<<22)
#define	DAC_CTL_DTSEL1				(0x7u<<19)
#define	DAC_CTL_DTSEL1_0			(0x1u<<19)
#define	DAC_CTL_DTEN1				(0x1u<<18)
#define	DAC_CTL_DBOFF1				(0x1u<<17)
#define	DAC_CTL_DEN1				(0x1u<<16)
#define	DAC_CTL_DDMAEN0				(0x1u<<12)
#define	DAC_CTL_DWBW0				(0xFu<<8)
#define	DAC_CTL_DWBW0_0				(0x1u<<8)
#define	DAC_CTL_DWM0				(0x3u<<6)
#define	DAC_CTL_DWM0_0				(0x1u<<6)
#define	DAC_CTL_DTSEL0				(0x7u<<3)
#define	DAC_CTL_DTSEL0_0			(0x1u<<3)
#define	DAC_CTL_DTEN0				(0x1u<<2)
#define	DAC_CTL_DBOFF0				(0x1u<<1)
#define	DAC_CTL_DEN0				(0x1u<<0)

// SWT Configuration

#define	DAC_SWT_SWTR1				(0x1u<<1)
#define	DAC_SWT_SWTR0				(0x1u<<0)

// DAC0_R12DH Configuration

#define	DAC_DAC0_R12DH_DAC0_DH		(0xFFFu<<0)
#define	DAC_DAC0_R12DH_DAC0_DH_0	(0x1u<<0)

// DAC0_L12DH Configuration

#define	DAC_DAC0_L12DH_DAC0_DH		(0xFFFu<<4)
#define	DAC_DAC0_L12DH_DAC0_DH_0	(0x1u<<4)

// DAC0_R8DH Configuration

#define	DAC_DAC0_R8DH_DAC0_DH		(0xFFu<<0)
#define	DAC_DAC0_R8DH_DAC0_DH_0		(0x1u<<0)

// DAC1_R12DH Configuration

#define	DAC_DAC1_R12DH_DAC1_DH		(0xFFFu<<0)
#define	DAC_DAC1_R12DH_DAC1_DH_0	(0x1u<<0)

// DAC1_L12DH Configuration

#define	DAC_DAC1_L12DH_DAC1_DH		(0xFFFu<<4)
#define	DAC_DAC1_L12DH_DAC1_DH_0	(0x1u<<4)

// DAC1_R8DH Configuration

#define	DAC_DAC1_R8DH_DAC1_DH		(0xFFu<<0)
#define	DAC_DAC1_R8DH_DAC1_DH_0		(0x1u<<0)

// DACC_R12DH Configuration

#define	DAC_DACC_R12DH_DAC1_DH		(0xFFFu<<16)
#define	DAC_DACC_R12DH_DAC1_DH_0	(0x1u<<16)
#define	DAC_DACC_R12DH_DAC0_DH		(0xFFFu<<0)
#define	DAC_DACC_R12DH_DAC0_DH_0	(0x1u<<0)

// DACC_L12DH Configuration

#define	DAC_DACC_L12DH_DAC1_DH		(0xFFFu<<20)
#define	DAC_DACC_L12DH_DAC1_DH_0	(0x1u<<20)
#define	DAC_DACC_L12DH_DAC0_DH		(0xFFFu<<4)
#define	DAC_DACC_L12DH_DAC0_DH_0	(0x1u<<4)

// DACC_R8DH Configuration

#define	DAC_DACC_R8DH_DAC1_DH		(0xFFu<<8)
#define	DAC_DACC_R8DH_DAC1_DH_0		(0x1u<<8)
#define	DAC_DACC_R8DH_DAC0_DH		(0xFFu<<0)
#define	DAC_DACC_R8DH_DAC0_DH_0		(0x1u<<0)

// DAC0_DO Configuration

#define	DAC_DAC0_DO_DAC0_DO			(0xFFFu<<0)
#define	DAC_DAC0_DO_DAC0_DO_0		(0x1u<<0)

// DAC1_DO Configuration

#define	DAC_DAC1_DO_DAC1_DO			(0xFFFu<<0)
#define	DAC_DAC1_DO_DAC1_DO_0		(0x1u<<0)
