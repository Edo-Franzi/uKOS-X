/*
; sau.
; ====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		sau equates.
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

// SAU address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CTRL;
	volatile	uint32_t	TYPE;
	volatile	uint32_t	RNR;
	volatile	uint32_t	RBAR;
	volatile	uint32_t	RLAR;
	volatile	uint32_t	SFSR;
	volatile	uint32_t	SFAR;
} SAU_TypeDef;

#if (defined(__cplusplus))
#define	SAU_S	reinterpret_cast<SAU_TypeDef *>(0xE000EDD0u)
#define	SAU_NS	reinterpret_cast<SAU_TypeDef *>(0xE000EDD0u)

#else
#define	SAU_S	((SAU_TypeDef *)0xE000EDD0u)
#define	SAU_NS	((SAU_TypeDef *)0xE000EDD0u)
#endif

// CTRL Configuration

#define	SAU_CTRL_ENABLE		(0x1u<<0)
#define	SAU_CTRL_ALLNS		(0x1u<<1)

// TYPE Configuration

#define	SAU_TYPE_SREGION	(0xFFu<<0)
#define	SAU_TYPE_SREGION_0	(0x1u<<0)

// RNR Configuration

#define	SAU_RNR_REGION		(0xFFu<<0)
#define	SAU_RNR_REGION_0	(0x1u<<0)

// RBAR Configuration

#define	SAU_RBAR_BADDR		(0x7FFFFFFu<<5)
#define	SAU_RBAR_BADDR_0	(0x1u<<5)

// RLAR Configuration

#define	SAU_RLAR_ENABLE		(0x1u<<0)
#define	SAU_RLAR_NSC		(0x1u<<1)
#define	SAU_RLAR_LADDR		(0x7FFFFFFu<<5)
#define	SAU_RLAR_LADDR_0	(0x1u<<5)

// SFSR Configuration

#define	SAU_SFSR_INVEP		(0x1u<<0)
#define	SAU_SFSR_INVIS		(0x1u<<1)
#define	SAU_SFSR_INVER		(0x1u<<2)
#define	SAU_SFSR_AUVIOL		(0x1u<<3)
#define	SAU_SFSR_INVTRAN	(0x1u<<4)
#define	SAU_SFSR_LSPERR		(0x1u<<5)
#define	SAU_SFSR_SFARVALID	(0x1u<<6)
#define	SAU_SFSR_LSERR		(0x1u<<7)

// SFAR Configuration

#define	SAU_SFAR_ADDRESS	(0xFFFFFFFFu<<0)
#define	SAU_SFAR_ADDRESS_0	(0x1u<<0)
