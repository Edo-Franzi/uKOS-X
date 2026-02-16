/*
; RP2350_xip_ctrl.
; ================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_xip_ctrl equates.
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

// XIP_CTRL address definitions
// ----------------------------

typedef struct {
	volatile	uint32_t	CTRL;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	STAT;
	volatile	uint32_t	CTR_HIT;
	volatile	uint32_t	CTR_ACC;
	volatile	uint32_t	STREAM_ADDR;
	volatile	uint32_t	STREAM_CTR;
	volatile	uint32_t	STREAM_FIFO;
} XIP_CTRL_TypeDef;

#ifdef __cplusplus
#define	XIP_CTRL_NS	reinterpret_cast<XIP_CTRL_TypeDef *>(0x400C8000u)
#define	XIP_CTRL_S	reinterpret_cast<XIP_CTRL_TypeDef *>(0x400C8000u)
#else
#define	XIP_CTRL_NS	((XIP_CTRL_TypeDef *)0x400C8000u)
#define	XIP_CTRL_S	((XIP_CTRL_TypeDef *)0x400C8000u)
#endif

// CTRL Configuration

#define	XIP_CTRL_CTRL_EN_SECURE					(0x1u<<0)
#define	XIP_CTRL_CTRL_EN_NONSECURE				(0x1u<<1)
#define	XIP_CTRL_CTRL_POWER_DOWN				(0x1u<<3)
#define	XIP_CTRL_CTRL_NO_UNCACHED_SEC			(0x1u<<4)
#define	XIP_CTRL_CTRL_NO_UNCACHED_NONSEC		(0x1u<<5)
#define	XIP_CTRL_CTRL_NO_UNTRANSLATED_SEC		(0x1u<<6)
#define	XIP_CTRL_CTRL_NO_UNTRANSLATED_NONSEC	(0x1u<<7)
#define	XIP_CTRL_CTRL_MAINT_NONSEC				(0x1u<<8)
#define	XIP_CTRL_CTRL_SPLIT_WAYS				(0x1u<<9)
#define	XIP_CTRL_CTRL_WRITABLE_M0				(0x1u<<10)
#define	XIP_CTRL_CTRL_WRITABLE_M1				(0x1u<<11)

// STAT Configuration

#define	XIP_CTRL_STAT_FIFO_EMPTY				(0x1u<<1)
#define	XIP_CTRL_STAT_FIFO_FULL					(0x1u<<2)

// CTR_HIT Configuration

#define	XIP_CTRL_CTR_HIT_CTR_HIT				(0xFFFFFFFFu<<0)
#define	XIP_CTRL_CTR_HIT_CTR_HIT_0				(0x1u<<0)

// CTR_ACC Configuration

#define	XIP_CTRL_CTR_ACC_CTR_ACC				(0xFFFFFFFFu<<0)
#define	XIP_CTRL_CTR_ACC_CTR_ACC_0				(0x1u<<0)

// STREAM_ADDR Configuration

#define	XIP_CTRL_STREAM_ADDR_STREAM_ADDR		(0x3FFFFFFFu<<2)
#define	XIP_CTRL_STREAM_ADDR_STREAM_ADDR_0		(0x1u<<2)

// STREAM_CTR Configuration

#define	XIP_CTRL_STREAM_CTR_STREAM_CTR			(0x3FFFFFu<<0)
#define	XIP_CTRL_STREAM_CTR_STREAM_CTR_0		(0x1u<<0)

// STREAM_FIFO Configuration

#define	XIP_CTRL_STREAM_FIFO_STREAM_FIFO		(0xFFFFFFFFu<<0)
#define	XIP_CTRL_STREAM_FIFO_STREAM_FIFO_0		(0x1u<<0)
