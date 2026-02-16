/*
; RP2350_sysinfo.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_sysinfo equates.
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

#include	<stdint.h>

// SYSINFO address definitions
// ---------------------------

typedef struct {
	volatile	uint32_t	CHIP_ID;
	volatile	uint32_t	PACKAGE_SEL;
	volatile	uint32_t	PLATFORM;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	GITREF_RP2350;
} SYSINFO_TypeDef;

#ifdef __cplusplus
#define	SYSINFO_NS	reinterpret_cast<SYSINFO_TypeDef *>(0x40000000u)
#define	SYSINFO_S	reinterpret_cast<SYSINFO_TypeDef *>(0x40000000u)
#else
#define	SYSINFO_NS	((SYSINFO_TypeDef *)0x40000000u)
#define	SYSINFO_S	((SYSINFO_TypeDef *)0x40000000u)
#endif

// CHIP_ID Configuration

#define	SYSINFO_CHIP_ID_STOP_BIT				(0x1u<<0)
#define	SYSINFO_CHIP_ID_MANUFACTURER			(0x7FFu<<1)
#define	SYSINFO_CHIP_ID_MANUFACTURER_0			(0x1u<<1)
#define	SYSINFO_CHIP_ID_PART					(0xFFFFu<<12)
#define	SYSINFO_CHIP_ID_PART_0					(0x1u<<12)
#define	SYSINFO_CHIP_ID_REVISION				(0xFu<<28)
#define	SYSINFO_CHIP_ID_REVISION_0				(0x1u<<28)

// PACKAGE_SEL Configuration

#define	SYSINFO_PACKAGE_SEL_PACKAGE_SEL			(0x1u<<0)

// PLATFORM Configuration

#define	SYSINFO_PLATFORM_FPGA					(0x1u<<0)
#define	SYSINFO_PLATFORM_ASIC					(0x1u<<1)
#define	SYSINFO_PLATFORM_HDLSIM					(0x1u<<2)
#define	SYSINFO_PLATFORM_BATCHSIM				(0x1u<<3)
#define	SYSINFO_PLATFORM_GATESIM				(0x1u<<4)

// GITREF_RP2350 Configuration

#define	SYSINFO_GITREF_RP2350_GITREF_RP2350		(0xFFFFFFFFu<<0)
#define	SYSINFO_GITREF_RP2350_GITREF_RP2350_0	(0x1u<<0)
