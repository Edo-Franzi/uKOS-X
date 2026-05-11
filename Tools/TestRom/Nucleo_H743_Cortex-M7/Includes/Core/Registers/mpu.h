/*
; mpu.
; ====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		MPU equates.
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

// MPU address definitions
// -----------------------

typedef struct {
	volatile	const	uint32_t	TYPE;
	volatile			uint32_t	CTRL;
	volatile			uint32_t	RNR;
	volatile			uint32_t	RBAR;
	volatile			uint32_t	RASR;
	volatile			uint32_t	RBAR_A1;
	volatile			uint32_t	RASR_A1;
	volatile			uint32_t	RBAR_A2;
	volatile			uint32_t	RASR_A2;
	volatile			uint32_t	RBAR_A3;
	volatile			uint32_t	RASR_A3;
} MPU_TypeDef;

#if (defined(__cplusplus))
#define	MPU		reinterpret_cast<MPU_TypeDef *>(0xE000ED90u)

#else
#define	MPU		((MPU_TypeDef *)0xE000ED90u)
#endif

// TYPER Configuration

#define	MPU_TYPER_IREGION		(0xFFu<<16)
#define	MPU_TYPER_IREGION_0		(0x1u<<16)
#define	MPU_TYPER_DREGION		(0xFFu<<8)
#define	MPU_TYPER_DREGION_0		(0x1u<<8)
#define	MPU_TYPER_SEPARATE		(0x1u<<0)

// CTRL Configuration

#define	MPU_CTRL_PRIVDEFENA		(0x1u<<2)
#define	MPU_CTRL_HFNMIENA		(0x1u<<1)
#define	MPU_CTRL_ENABLE			(0x1u<<0)

// RNR Configuration

#define	MPU_RNR_REGION			(0xFFu<<0)
#define	MPU_RNR_REGION_0		(0x1u<<0)

// RBAR Configuration

#define	MPU_RBAR_ADDR			(0x7FFFFFFu<<5)
#define	MPU_RBAR_ADDR_0			(0x1u<<5)
#define	MPU_RBAR_VALID			(0x1u<<4)
#define	MPU_RBAR_REGION			(0xFu<<0)
#define	MPU_RBAR_REGION_0		(0x1u<<0)

// RASR Configuration

#define	MPU_RASR_XN				(0x1u<<28)
#define	MPU_RASR_AP				(0x7u<<24)
#define	MPU_RASR_AP_0			(0x1u<<24)
#define	MPU_RASR_TEX			(0x7u<<19)
#define	MPU_RASR_TEX_0			(0x1u<<19)
#define	MPU_RASR_S				(0x1u<<18)
#define	MPU_RASR_C				(0x1u<<17)
#define	MPU_RASR_B				(0x1u<<16)
#define	MPU_RASR_SRD			(0xFFu<<8)
#define	MPU_RASR_SRD_0			(0x1u<<8)
#define	MPU_RASR_SIZE			(0x1Fu<<1)
#define	MPU_RASR_SIZE_0			(0x1u<<1)
#define	MPU_RASR_ENABLE			(0x1u<<0)
