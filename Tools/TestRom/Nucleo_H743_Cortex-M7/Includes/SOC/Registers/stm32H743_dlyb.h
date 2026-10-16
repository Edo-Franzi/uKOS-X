/*
; stm32H743_dlyb.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H743_dlyb equates.
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

// DLYB address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	CFGR;
} DLYB_TypeDef;

#if (defined(__cplusplus))
#define	DELAY_BLOCK_SDMMC1	reinterpret_cast<DLYB_TypeDef *>(0x52008000u)
#define	DELAY_BLOCK_QUADSPI	reinterpret_cast<DLYB_TypeDef *>(0x52006000u)
#define	DELAY_BLOCK_SDMMC2	reinterpret_cast<DLYB_TypeDef *>(0x48022800u)

#else
#define	DELAY_BLOCK_SDMMC1	((DLYB_TypeDef *)0x52008000u)
#define	DELAY_BLOCK_QUADSPI	((DLYB_TypeDef *)0x52006000u)
#define	DELAY_BLOCK_SDMMC2	((DLYB_TypeDef *)0x48022800u)
#endif

// CR Configuration

#define	DLYB_CR_SEN			(0x1u<<1)
#define	DLYB_CR_DEN			(0x1u<<0)

// CFGR Configuration

#define	DLYB_CFGR_LNGF		(0x1u<<31)
#define	DLYB_CFGR_LNG		(0xFFFu<<16)
#define	DLYB_CFGR_LNG_0		(0x1u<<16)
#define	DLYB_CFGR_UNIT		(0x7Fu<<8)
#define	DLYB_CFGR_UNIT_0	(0x1u<<8)
#define	DLYB_CFGR_SEL		(0xFu<<0)
#define	DLYB_CFGR_SEL_0		(0x1u<<0)
