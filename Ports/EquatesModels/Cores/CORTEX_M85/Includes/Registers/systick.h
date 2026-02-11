/*
; systick.
; ========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		SYSTICK equates.
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

// SYSTICK address definitions
// ---------------------------

typedef struct {
	volatile			uint32_t	CTRL;
	volatile			uint32_t	LOAD;
	volatile			uint32_t	VAL;
	volatile	const	uint32_t	CALIB;
} SysTick_TypeDef;

#if (defined(__cplusplus))
#define	SysTick_S	reinterpret_cast<SysTick_TypeDef *>(0xE000E010u)
#define	SysTick_NS	reinterpret_cast<SysTick_TypeDef *>(0xE002E010u)

#else
#define	SysTick_S	((SysTick_TypeDef *)0xE000E010u)
#define	SysTick_NS	((SysTick_TypeDef *)0xE002E010u)
#endif

// SysTick_CTRL register

#define	SysTick_CTRL_ENABLE			0x00000001u
#define	SysTick_CTRL_TICKINT		0x00000002u
#define	SysTick_CTRL_CLKSOURCE		0x00000004u
#define	SysTick_CTRL_COUNTFLAG		0x00010000u
