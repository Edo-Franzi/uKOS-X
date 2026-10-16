/*
; stm32H743_wwdg.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H743_wwdg equates.
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

// WWDG address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	CFR;
	volatile	uint32_t	SR;
} WWDG_TypeDef;

#if (defined(__cplusplus))
#define	WWDG	reinterpret_cast<WWDG_TypeDef *>(0x50003000u)

#else
#define	WWDG	((WWDG_TypeDef *)0x50003000u)
#endif

// CR Configuration

#define	WWDG_CR_WDGA		(0x1u<<7)
#define	WWDG_CR_T			(0x7Fu<<0)
#define	WWDG_CR_T_0			(0x1u<<0)

// CFR Configuration

#define	WWDG_CFR_EWI		(0x1u<<9)
#define	WWDG_CFR_WDGTB		(0x3u<<11)
#define	WWDG_CFR_WDGTB_0	(0x1u<<11)
#define	WWDG_CFR_W			(0x7Fu<<0)
#define	WWDG_CFR_W_0		(0x1u<<0)

// SR Configuration

#define	WWDG_SR_EWIF		(0x1u<<0)
