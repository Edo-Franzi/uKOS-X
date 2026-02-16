/*
; RP2350_adc.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_adc equates.
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

// ADC address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CS;
	volatile	uint32_t	RESULT;
	volatile	uint32_t	FCS;
	volatile	uint32_t	FIFO;
	volatile	uint32_t	DIV;
	volatile	uint32_t	INTR;
	volatile	uint32_t	INTE;
	volatile	uint32_t	INTF;
	volatile	uint32_t	INTS;
} ADC_TypeDef;

#ifdef __cplusplus
#define	ADC_NS	reinterpret_cast<ADC_TypeDef *>(0x400A0000u)
#define	ADC_S	reinterpret_cast<ADC_TypeDef *>(0x400A0000u)
#else
#define	ADC_NS	((ADC_TypeDef *)0x400A0000u)
#define	ADC_S	((ADC_TypeDef *)0x400A0000u)
#endif

// CS Configuration

#define	ADC_CS_EN			(0x1u<<0)
#define	ADC_CS_TS_EN		(0x1u<<1)
#define	ADC_CS_START_ONCE	(0x1u<<2)
#define	ADC_CS_START_MANY	(0x1u<<3)
#define	ADC_CS_READY		(0x1u<<8)
#define	ADC_CS_ERR			(0x1u<<9)
#define	ADC_CS_ERR_STICKY	(0x1u<<10)
#define	ADC_CS_AINSEL		(0xFu<<12)
#define	ADC_CS_AINSEL_0		(0x1u<<12)
#define	ADC_CS_RROBIN		(0x1FFu<<16)
#define	ADC_CS_RROBIN_0		(0x1u<<16)

// RESULT Configuration

#define	ADC_RESULT_RESULT	(0xFFFu<<0)
#define	ADC_RESULT_RESULT_0	(0x1u<<0)

// FCS Configuration

#define	ADC_FCS_EN			(0x1u<<0)
#define	ADC_FCS_SHIFT		(0x1u<<1)
#define	ADC_FCS_ERR			(0x1u<<2)
#define	ADC_FCS_DREQ_EN		(0x1u<<3)
#define	ADC_FCS_EMPTY		(0x1u<<8)
#define	ADC_FCS_FULL		(0x1u<<9)
#define	ADC_FCS_UNDER		(0x1u<<10)
#define	ADC_FCS_OVER		(0x1u<<11)
#define	ADC_FCS_LEVEL		(0xFu<<16)
#define	ADC_FCS_LEVEL_0		(0x1u<<16)
#define	ADC_FCS_THRESH		(0xFu<<24)
#define	ADC_FCS_THRESH_0	(0x1u<<24)

// FIFO Configuration

#define	ADC_FIFO_VAL		(0xFFFu<<0)
#define	ADC_FIFO_VAL_0		(0x1u<<0)
#define	ADC_FIFO_ERR		(0x1u<<15)

// DIV Configuration

#define	ADC_DIV_FRAC		(0xFFu<<0)
#define	ADC_DIV_FRAC_0		(0x1u<<0)
#define	ADC_DIV_INT			(0xFFFFu<<8)
#define	ADC_DIV_INT_0		(0x1u<<8)

// INTR Configuration

#define	ADC_INTR_FIFO		(0x1u<<0)

// INTE Configuration

#define	ADC_INTE_FIFO		(0x1u<<0)

// INTF Configuration

#define	ADC_INTF_FIFO		(0x1u<<0)

// INTS Configuration

#define	ADC_INTS_FIFO		(0x1u<<0)
