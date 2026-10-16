/*
; GD32VF103_rtc.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_rtc equates.
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

// RTC address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	INTEN;
	volatile	uint32_t	CTL;
	volatile	uint32_t	PSCH;
	volatile	uint32_t	PSCL;
	volatile	uint32_t	DIVH;
	volatile	uint32_t	DIVL;
	volatile	uint32_t	CNTH;
	volatile	uint32_t	CNTL;
	volatile	uint32_t	ALRMH;
	volatile	uint32_t	ALRML;
} RTC_TypeDef;

#if (defined(__cplusplus))
#define	RTC	reinterpret_cast<RTC_TypeDef *>(0x40002800u)

#else
#define	RTC	((RTC_TypeDef *)0x40002800u)
#endif

// INTEN Configuration

#define	RTC_INTEN_SCIE		(0x1u<<0)
#define	RTC_INTEN_ALRMIE	(0x1u<<1)
#define	RTC_INTEN_OVIE		(0x1u<<2)

// CTL Configuration

#define	RTC_CTL_SCIF		(0x1u<<0)
#define	RTC_CTL_ALRMIF		(0x1u<<1)
#define	RTC_CTL_OVIF		(0x1u<<2)
#define	RTC_CTL_RSYNF		(0x1u<<3)
#define	RTC_CTL_CMF			(0x1u<<4)
#define	RTC_CTL_LWOFF		(0x1u<<5)

// PSCH Configuration

#define	RTC_PSCH_PSC		(0xFu<<0)
#define	RTC_PSCH_PSC_0		(0x1u<<0)

// PSCL Configuration

#define	RTC_PSCL_PSC		(0xFFFFu<<0)
#define	RTC_PSCL_PSC_0		(0x1u<<0)

// DIVH Configuration

#define	RTC_DIVH_DIV		(0xFu<<0)
#define	RTC_DIVH_DIV_0		(0x1u<<0)

// DIVL Configuration

#define	RTC_DIVL_DIV		(0xFFFFu<<0)
#define	RTC_DIVL_DIV_0		(0x1u<<0)

// CNTH Configuration

#define	RTC_CNTH_CNT		(0xFFFFu<<0)
#define	RTC_CNTH_CNT_0		(0x1u<<0)

// CNTL Configuration

#define	RTC_CNTL_CNT		(0xFFFFu<<0)
#define	RTC_CNTL_CNT_0		(0x1u<<0)

// ALRMH Configuration

#define	RTC_ALRMH_ALRM		(0xFFFFu<<0)
#define	RTC_ALRMH_ALRM_0	(0x1u<<0)

// ALRML Configuration

#define	RTC_ALRML_ALRM		(0xFFFFu<<0)
#define	RTC_ALRML_ALRM_0	(0x1u<<0)
