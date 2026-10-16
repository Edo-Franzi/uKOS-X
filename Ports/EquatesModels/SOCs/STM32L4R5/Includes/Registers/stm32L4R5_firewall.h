/*
; stm32L4R5_firewall.
; ===================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_firewall equates.
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

// FIREWALL address definitions
// ----------------------------

typedef struct {
	volatile	uint32_t	CSSA;
	volatile	uint32_t	CSL;
	volatile	uint32_t	NVDSSA;
	volatile	uint32_t	NVDSL;
	volatile	uint32_t	VDSSA;
	volatile	uint32_t	VDSL;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	CR;
} FIREWALL_TypeDef;

#if (defined(__cplusplus))
#define	FIREWALL	reinterpret_cast<FIREWALL_TypeDef *>(0x40011C00u)

#else
#define	FIREWALL	((FIREWALL_TypeDef *)0x40011C00u)
#endif

// CSSA Configuration

#define	FIREWALL_CSSA_ADD		(0xFFFFu<<8)
#define	FIREWALL_CSSA_ADD_0		(0x1u<<8)

// CSL Configuration

#define	FIREWALL_CSL_LENG		(0x3FFFu<<8)
#define	FIREWALL_CSL_LENG_0		(0x1u<<8)

// NVDSSA Configuration

#define	FIREWALL_NVDSSA_ADD		(0xFFFFu<<8)
#define	FIREWALL_NVDSSA_ADD_0	(0x1u<<8)

// NVDSL Configuration

#define	FIREWALL_NVDSL_LENG		(0x3FFFu<<8)
#define	FIREWALL_NVDSL_LENG_0	(0x1u<<8)

// VDSSA Configuration

#define	FIREWALL_VDSSA_ADD		(0x3FFu<<6)
#define	FIREWALL_VDSSA_ADD_0	(0x1u<<6)

// VDSL Configuration

#define	FIREWALL_VDSL_LENG		(0x3FFu<<6)
#define	FIREWALL_VDSL_LENG_0	(0x1u<<6)

// CR Configuration

#define	FIREWALL_CR_FPA			(0x1u<<0)
#define	FIREWALL_CR_VDS			(0x1u<<1)
#define	FIREWALL_CR_VDE			(0x1u<<2)
