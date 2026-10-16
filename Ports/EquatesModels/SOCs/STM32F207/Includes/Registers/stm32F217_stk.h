/*
; stm32F217_stk.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_stk equates.
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

// STK address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CTRL;
	volatile	uint32_t	LOAD_;
	volatile	uint32_t	VAL;
	volatile	uint32_t	CALIB;
} STK_TypeDef;

#if (defined(__cplusplus))
#define	STK	reinterpret_cast<STK_TypeDef *>(0xE000E010u)

#else
#define	STK	((STK_TypeDef *)0xE000E010u)
#endif

// CTRL Configuration

#define	STK_CTRL_COUNTFLAG	(0x1u<<16)
#define	STK_CTRL_CLKSOURCE	(0x1u<<2)
#define	STK_CTRL_TICKINT	(0x1u<<1)
#define	STK_CTRL_ENABLE		(0x1u<<0)

// LOAD_ Configuration

#define	STK_LOAD__RELOAD	(0xFFFFFFu<<0)
#define	STK_LOAD__RELOAD_0	(0x1u<<0)

// VAL Configuration

#define	STK_VAL_CURRENT		(0xFFFFFFu<<0)
#define	STK_VAL_CURRENT_0	(0x1u<<0)

// CALIB Configuration

#define	STK_CALIB_TENMS		(0xFFFFFFu<<0)
#define	STK_CALIB_TENMS_0	(0x1u<<0)
