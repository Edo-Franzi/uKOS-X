/*
; stm32N657_hdp.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_hdp equates.
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

// HDP address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CTRL;
	volatile	uint32_t	MUX;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	VAL;
	volatile	uint32_t	GPOSET;
	volatile	uint32_t	GPOCLR;
	volatile	uint32_t	GPOVAL;
} HDP_TypeDef;

#if (defined(__cplusplus))
#define	HDP_NS	reinterpret_cast<HDP_TypeDef *>(0x46000800u)
#define	HDP_S	reinterpret_cast<HDP_TypeDef *>(0x56000800u)

#else
#define	HDP_NS	((HDP_TypeDef *)0x46000800u)
#define	HDP_S	((HDP_TypeDef *)0x56000800u)
#endif

// CTRL Configuration

#define	HDP_CTRL_EN				(0x1u<<0)

// MUX Configuration

#define	HDP_MUX_MUX7			(0xFu<<28)
#define	HDP_MUX_MUX7_0			(0x1u<<28)
#define	HDP_MUX_MUX6			(0xFu<<24)
#define	HDP_MUX_MUX6_0			(0x1u<<24)
#define	HDP_MUX_MUX5			(0xFu<<20)
#define	HDP_MUX_MUX5_0			(0x1u<<20)
#define	HDP_MUX_MUX4			(0xFu<<16)
#define	HDP_MUX_MUX4_0			(0x1u<<16)
#define	HDP_MUX_MUX3			(0xFu<<12)
#define	HDP_MUX_MUX3_0			(0x1u<<12)
#define	HDP_MUX_MUX2			(0xFu<<8)
#define	HDP_MUX_MUX2_0			(0x1u<<8)
#define	HDP_MUX_MUX1			(0xFu<<4)
#define	HDP_MUX_MUX1_0			(0x1u<<4)
#define	HDP_MUX_MUX0			(0xFu<<0)
#define	HDP_MUX_MUX0_0			(0x1u<<0)

// VAL Configuration

#define	HDP_VAL_HDPVAL			(0xFFu<<0)
#define	HDP_VAL_HDPVAL_0		(0x1u<<0)

// GPOSET Configuration

#define	HDP_GPOSET_HDPGPOSET	(0xFFu<<0)
#define	HDP_GPOSET_HDPGPOSET_0	(0x1u<<0)

// GPOCLR Configuration

#define	HDP_GPOCLR_HDPGPOCLR	(0xFFu<<0)
#define	HDP_GPOCLR_HDPGPOCLR_0	(0x1u<<0)

// GPOVAL Configuration

#define	HDP_GPOVAL_HDPGPOVAL	(0xFFu<<0)
#define	HDP_GPOVAL_HDPGPOVAL_0	(0x1u<<0)
