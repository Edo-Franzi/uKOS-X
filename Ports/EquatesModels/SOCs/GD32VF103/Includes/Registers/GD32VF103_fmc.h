/*
; GD32VF103_fmc.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_fmc equates.
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

// FMC address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	WS;
	volatile	uint32_t	KEY0;
	volatile	uint32_t	OBKEY;
	volatile	uint32_t	STAT0;
	volatile	uint32_t	CTL0;
	volatile	uint32_t	ADDR0;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	OBSTAT;
	volatile	uint32_t	WP;
	volatile	uint32_t	RESERVED1[55];
	volatile	uint32_t	PID;
} FMC_TypeDef;

#if (defined(__cplusplus))
#define	FMC	reinterpret_cast<FMC_TypeDef *>(0x40022000u)

#else
#define	FMC	((FMC_TypeDef *)0x40022000u)
#endif

// WS Configuration

#define	FMC_WS_WSCNT		(0x7u<<0)
#define	FMC_WS_WSCNT_0		(0x1u<<0)

// KEY0 Configuration

#define	FMC_KEY0_KEY		(0xFFFFFFFFu<<0)
#define	FMC_KEY0_KEY_0		(0x1u<<0)

// OBKEY Configuration

#define	FMC_OBKEY_OBKEY		(0xFFFFFFFFu<<0)
#define	FMC_OBKEY_OBKEY_0	(0x1u<<0)

// STAT0 Configuration

#define	FMC_STAT0_BUSY		(0x1u<<0)
#define	FMC_STAT0_PGERR		(0x1u<<2)
#define	FMC_STAT0_WPERR		(0x1u<<4)
#define	FMC_STAT0_ENDF		(0x1u<<5)

// CTL0 Configuration

#define	FMC_CTL0_PG			(0x1u<<0)
#define	FMC_CTL0_PER		(0x1u<<1)
#define	FMC_CTL0_MER		(0x1u<<2)
#define	FMC_CTL0_OBPG		(0x1u<<4)
#define	FMC_CTL0_OBER		(0x1u<<5)
#define	FMC_CTL0_START		(0x1u<<6)
#define	FMC_CTL0_LK			(0x1u<<7)
#define	FMC_CTL0_OBWEN		(0x1u<<9)
#define	FMC_CTL0_ERRIE		(0x1u<<10)
#define	FMC_CTL0_ENDIE		(0x1u<<12)

// ADDR0 Configuration

#define	FMC_ADDR0_ADDR		(0xFFFFFFFFu<<0)
#define	FMC_ADDR0_ADDR_0	(0x1u<<0)

// OBSTAT Configuration

#define	FMC_OBSTAT_DATA		(0xFFFFu<<10)
#define	FMC_OBSTAT_DATA_0	(0x1u<<10)
#define	FMC_OBSTAT_USER		(0xFFu<<2)
#define	FMC_OBSTAT_USER_0	(0x1u<<2)
#define	FMC_OBSTAT_SPC		(0x1u<<1)
#define	FMC_OBSTAT_OBERR	(0x1u<<0)

// WP Configuration

#define	FMC_WP_WP			(0xFFFFFFFFu<<0)
#define	FMC_WP_WP_0			(0x1u<<0)

// PID Configuration

#define	FMC_PID_PID			(0xFFFFFFFFu<<0)
#define	FMC_PID_PID_0		(0x1u<<0)
