/*
; RP2350_pwm.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_pwm equates.
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

// PWM address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CH0_CSR;
	volatile	uint32_t	CH0_DIV;
	volatile	uint32_t	CH0_CTR;
	volatile	uint32_t	CH0_CC;
	volatile	uint32_t	CH0_TOP;
	volatile	uint32_t	CH1_CSR;
	volatile	uint32_t	CH1_DIV;
	volatile	uint32_t	CH1_CTR;
	volatile	uint32_t	CH1_CC;
	volatile	uint32_t	CH1_TOP;
	volatile	uint32_t	CH2_CSR;
	volatile	uint32_t	CH2_DIV;
	volatile	uint32_t	CH2_CTR;
	volatile	uint32_t	CH2_CC;
	volatile	uint32_t	CH2_TOP;
	volatile	uint32_t	CH3_CSR;
	volatile	uint32_t	CH3_DIV;
	volatile	uint32_t	CH3_CTR;
	volatile	uint32_t	CH3_CC;
	volatile	uint32_t	CH3_TOP;
	volatile	uint32_t	CH4_CSR;
	volatile	uint32_t	CH4_DIV;
	volatile	uint32_t	CH4_CTR;
	volatile	uint32_t	CH4_CC;
	volatile	uint32_t	CH4_TOP;
	volatile	uint32_t	CH5_CSR;
	volatile	uint32_t	CH5_DIV;
	volatile	uint32_t	CH5_CTR;
	volatile	uint32_t	CH5_CC;
	volatile	uint32_t	CH5_TOP;
	volatile	uint32_t	CH6_CSR;
	volatile	uint32_t	CH6_DIV;
	volatile	uint32_t	CH6_CTR;
	volatile	uint32_t	CH6_CC;
	volatile	uint32_t	CH6_TOP;
	volatile	uint32_t	CH7_CSR;
	volatile	uint32_t	CH7_DIV;
	volatile	uint32_t	CH7_CTR;
	volatile	uint32_t	CH7_CC;
	volatile	uint32_t	CH7_TOP;
	volatile	uint32_t	CH8_CSR;
	volatile	uint32_t	CH8_DIV;
	volatile	uint32_t	CH8_CTR;
	volatile	uint32_t	CH8_CC;
	volatile	uint32_t	CH8_TOP;
	volatile	uint32_t	CH9_CSR;
	volatile	uint32_t	CH9_DIV;
	volatile	uint32_t	CH9_CTR;
	volatile	uint32_t	CH9_CC;
	volatile	uint32_t	CH9_TOP;
	volatile	uint32_t	CH10_CSR;
	volatile	uint32_t	CH10_DIV;
	volatile	uint32_t	CH10_CTR;
	volatile	uint32_t	CH10_CC;
	volatile	uint32_t	CH10_TOP;
	volatile	uint32_t	CH11_CSR;
	volatile	uint32_t	CH11_DIV;
	volatile	uint32_t	CH11_CTR;
	volatile	uint32_t	CH11_CC;
	volatile	uint32_t	CH11_TOP;
	volatile	uint32_t	EN;
	volatile	uint32_t	INTR;
	volatile	uint32_t	IRQ0_INTE;
	volatile	uint32_t	IRQ0_INTF;
	volatile	uint32_t	IRQ0_INTS;
	volatile	uint32_t	IRQ1_INTE;
	volatile	uint32_t	IRQ1_INTF;
	volatile	uint32_t	IRQ1_INTS;
} PWM_TypeDef;

#ifdef __cplusplus
#define	PWM_NS	reinterpret_cast<PWM_TypeDef *>(0x400A8000u)
#define	PWM_S	reinterpret_cast<PWM_TypeDef *>(0x400A8000u)
#else
#define	PWM_NS	((PWM_TypeDef *)0x400A8000u)
#define	PWM_S	((PWM_TypeDef *)0x400A8000u)
#endif

// CH0_CSR Configuration

#define	PWM_CH0_CSR_EN					(0x1u<<0)
#define	PWM_CH0_CSR_PH_CORRECT			(0x1u<<1)
#define	PWM_CH0_CSR_A_INV				(0x1u<<2)
#define	PWM_CH0_CSR_B_INV				(0x1u<<3)
#define	PWM_CH0_CSR_DIVMODE				(0x3u<<4)
#define	PWM_CH0_CSR_DIVMODE_0			(0x1u<<4)
#define	PWM_CH0_CSR_PH_RET				(0x1u<<6)
#define	PWM_CH0_CSR_PH_ADV				(0x1u<<7)
#define	PWM_CH0_CSR_DIVMODE_DIV			(0x0u<<4)
#define	PWM_CH0_CSR_DIVMODE_LEVEL		(0x1u<<4)
#define	PWM_CH0_CSR_DIVMODE_RISE		(0x2u<<4)
#define	PWM_CH0_CSR_DIVMODE_FALL		(0x3u<<4)

// CH0_DIV Configuration

#define	PWM_CH0_DIV_FRAC				(0xFu<<0)
#define	PWM_CH0_DIV_FRAC_0				(0x1u<<0)
#define	PWM_CH0_DIV_INT					(0xFFu<<4)
#define	PWM_CH0_DIV_INT_0				(0x1u<<4)

// CH0_CTR Configuration

#define	PWM_CH0_CTR_CH0_CTR				(0xFFFFu<<0)
#define	PWM_CH0_CTR_CH0_CTR_0			(0x1u<<0)

// CH0_CC Configuration

#define	PWM_CH0_CC_A					(0xFFFFu<<0)
#define	PWM_CH0_CC_A_0					(0x1u<<0)
#define	PWM_CH0_CC_B					(0xFFFFu<<16)
#define	PWM_CH0_CC_B_0					(0x1u<<16)

// CH0_TOP Configuration

#define	PWM_CH0_TOP_CH0_TOP				(0xFFFFu<<0)
#define	PWM_CH0_TOP_CH0_TOP_0			(0x1u<<0)

// CH1_CSR Configuration

#define	PWM_CH1_CSR_EN					(0x1u<<0)
#define	PWM_CH1_CSR_PH_CORRECT			(0x1u<<1)
#define	PWM_CH1_CSR_A_INV				(0x1u<<2)
#define	PWM_CH1_CSR_B_INV				(0x1u<<3)
#define	PWM_CH1_CSR_DIVMODE				(0x3u<<4)
#define	PWM_CH1_CSR_DIVMODE_0			(0x1u<<4)
#define	PWM_CH1_CSR_PH_RET				(0x1u<<6)
#define	PWM_CH1_CSR_PH_ADV				(0x1u<<7)
#define	PWM_CH1_CSR_DIVMODE_DIV			(0x0u<<4)
#define	PWM_CH1_CSR_DIVMODE_LEVEL		(0x1u<<4)
#define	PWM_CH1_CSR_DIVMODE_RISE		(0x2u<<4)
#define	PWM_CH1_CSR_DIVMODE_FALL		(0x3u<<4)

// CH1_DIV Configuration

#define	PWM_CH1_DIV_FRAC				(0xFu<<0)
#define	PWM_CH1_DIV_FRAC_0				(0x1u<<0)
#define	PWM_CH1_DIV_INT					(0xFFu<<4)
#define	PWM_CH1_DIV_INT_0				(0x1u<<4)

// CH1_CTR Configuration

#define	PWM_CH1_CTR_CH1_CTR				(0xFFFFu<<0)
#define	PWM_CH1_CTR_CH1_CTR_0			(0x1u<<0)

// CH1_CC Configuration

#define	PWM_CH1_CC_A					(0xFFFFu<<0)
#define	PWM_CH1_CC_A_0					(0x1u<<0)
#define	PWM_CH1_CC_B					(0xFFFFu<<16)
#define	PWM_CH1_CC_B_0					(0x1u<<16)

// CH1_TOP Configuration

#define	PWM_CH1_TOP_CH1_TOP				(0xFFFFu<<0)
#define	PWM_CH1_TOP_CH1_TOP_0			(0x1u<<0)

// CH2_CSR Configuration

#define	PWM_CH2_CSR_EN					(0x1u<<0)
#define	PWM_CH2_CSR_PH_CORRECT			(0x1u<<1)
#define	PWM_CH2_CSR_A_INV				(0x1u<<2)
#define	PWM_CH2_CSR_B_INV				(0x1u<<3)
#define	PWM_CH2_CSR_DIVMODE				(0x3u<<4)
#define	PWM_CH2_CSR_DIVMODE_0			(0x1u<<4)
#define	PWM_CH2_CSR_PH_RET				(0x1u<<6)
#define	PWM_CH2_CSR_PH_ADV				(0x1u<<7)
#define	PWM_CH2_CSR_DIVMODE_DIV			(0x0u<<4)
#define	PWM_CH2_CSR_DIVMODE_LEVEL		(0x1u<<4)
#define	PWM_CH2_CSR_DIVMODE_RISE		(0x2u<<4)
#define	PWM_CH2_CSR_DIVMODE_FALL		(0x3u<<4)

// CH2_DIV Configuration

#define	PWM_CH2_DIV_FRAC				(0xFu<<0)
#define	PWM_CH2_DIV_FRAC_0				(0x1u<<0)
#define	PWM_CH2_DIV_INT					(0xFFu<<4)
#define	PWM_CH2_DIV_INT_0				(0x1u<<4)

// CH2_CTR Configuration

#define	PWM_CH2_CTR_CH2_CTR				(0xFFFFu<<0)
#define	PWM_CH2_CTR_CH2_CTR_0			(0x1u<<0)

// CH2_CC Configuration

#define	PWM_CH2_CC_A					(0xFFFFu<<0)
#define	PWM_CH2_CC_A_0					(0x1u<<0)
#define	PWM_CH2_CC_B					(0xFFFFu<<16)
#define	PWM_CH2_CC_B_0					(0x1u<<16)

// CH2_TOP Configuration

#define	PWM_CH2_TOP_CH2_TOP				(0xFFFFu<<0)
#define	PWM_CH2_TOP_CH2_TOP_0			(0x1u<<0)

// CH3_CSR Configuration

#define	PWM_CH3_CSR_EN					(0x1u<<0)
#define	PWM_CH3_CSR_PH_CORRECT			(0x1u<<1)
#define	PWM_CH3_CSR_A_INV				(0x1u<<2)
#define	PWM_CH3_CSR_B_INV				(0x1u<<3)
#define	PWM_CH3_CSR_DIVMODE				(0x3u<<4)
#define	PWM_CH3_CSR_DIVMODE_0			(0x1u<<4)
#define	PWM_CH3_CSR_PH_RET				(0x1u<<6)
#define	PWM_CH3_CSR_PH_ADV				(0x1u<<7)
#define	PWM_CH3_CSR_DIVMODE_DIV			(0x0u<<4)
#define	PWM_CH3_CSR_DIVMODE_LEVEL		(0x1u<<4)
#define	PWM_CH3_CSR_DIVMODE_RISE		(0x2u<<4)
#define	PWM_CH3_CSR_DIVMODE_FALL		(0x3u<<4)

// CH3_DIV Configuration

#define	PWM_CH3_DIV_FRAC				(0xFu<<0)
#define	PWM_CH3_DIV_FRAC_0				(0x1u<<0)
#define	PWM_CH3_DIV_INT					(0xFFu<<4)
#define	PWM_CH3_DIV_INT_0				(0x1u<<4)

// CH3_CTR Configuration

#define	PWM_CH3_CTR_CH3_CTR				(0xFFFFu<<0)
#define	PWM_CH3_CTR_CH3_CTR_0			(0x1u<<0)

// CH3_CC Configuration

#define	PWM_CH3_CC_A					(0xFFFFu<<0)
#define	PWM_CH3_CC_A_0					(0x1u<<0)
#define	PWM_CH3_CC_B					(0xFFFFu<<16)
#define	PWM_CH3_CC_B_0					(0x1u<<16)

// CH3_TOP Configuration

#define	PWM_CH3_TOP_CH3_TOP				(0xFFFFu<<0)
#define	PWM_CH3_TOP_CH3_TOP_0			(0x1u<<0)

// CH4_CSR Configuration

#define	PWM_CH4_CSR_EN					(0x1u<<0)
#define	PWM_CH4_CSR_PH_CORRECT			(0x1u<<1)
#define	PWM_CH4_CSR_A_INV				(0x1u<<2)
#define	PWM_CH4_CSR_B_INV				(0x1u<<3)
#define	PWM_CH4_CSR_DIVMODE				(0x3u<<4)
#define	PWM_CH4_CSR_DIVMODE_0			(0x1u<<4)
#define	PWM_CH4_CSR_PH_RET				(0x1u<<6)
#define	PWM_CH4_CSR_PH_ADV				(0x1u<<7)
#define	PWM_CH4_CSR_DIVMODE_DIV			(0x0u<<4)
#define	PWM_CH4_CSR_DIVMODE_LEVEL		(0x1u<<4)
#define	PWM_CH4_CSR_DIVMODE_RISE		(0x2u<<4)
#define	PWM_CH4_CSR_DIVMODE_FALL		(0x3u<<4)

// CH4_DIV Configuration

#define	PWM_CH4_DIV_FRAC				(0xFu<<0)
#define	PWM_CH4_DIV_FRAC_0				(0x1u<<0)
#define	PWM_CH4_DIV_INT					(0xFFu<<4)
#define	PWM_CH4_DIV_INT_0				(0x1u<<4)

// CH4_CTR Configuration

#define	PWM_CH4_CTR_CH4_CTR				(0xFFFFu<<0)
#define	PWM_CH4_CTR_CH4_CTR_0			(0x1u<<0)

// CH4_CC Configuration

#define	PWM_CH4_CC_A					(0xFFFFu<<0)
#define	PWM_CH4_CC_A_0					(0x1u<<0)
#define	PWM_CH4_CC_B					(0xFFFFu<<16)
#define	PWM_CH4_CC_B_0					(0x1u<<16)

// CH4_TOP Configuration

#define	PWM_CH4_TOP_CH4_TOP				(0xFFFFu<<0)
#define	PWM_CH4_TOP_CH4_TOP_0			(0x1u<<0)

// CH5_CSR Configuration

#define	PWM_CH5_CSR_EN					(0x1u<<0)
#define	PWM_CH5_CSR_PH_CORRECT			(0x1u<<1)
#define	PWM_CH5_CSR_A_INV				(0x1u<<2)
#define	PWM_CH5_CSR_B_INV				(0x1u<<3)
#define	PWM_CH5_CSR_DIVMODE				(0x3u<<4)
#define	PWM_CH5_CSR_DIVMODE_0			(0x1u<<4)
#define	PWM_CH5_CSR_PH_RET				(0x1u<<6)
#define	PWM_CH5_CSR_PH_ADV				(0x1u<<7)
#define	PWM_CH5_CSR_DIVMODE_DIV			(0x0u<<4)
#define	PWM_CH5_CSR_DIVMODE_LEVEL		(0x1u<<4)
#define	PWM_CH5_CSR_DIVMODE_RISE		(0x2u<<4)
#define	PWM_CH5_CSR_DIVMODE_FALL		(0x3u<<4)

// CH5_DIV Configuration

#define	PWM_CH5_DIV_FRAC				(0xFu<<0)
#define	PWM_CH5_DIV_FRAC_0				(0x1u<<0)
#define	PWM_CH5_DIV_INT					(0xFFu<<4)
#define	PWM_CH5_DIV_INT_0				(0x1u<<4)

// CH5_CTR Configuration

#define	PWM_CH5_CTR_CH5_CTR				(0xFFFFu<<0)
#define	PWM_CH5_CTR_CH5_CTR_0			(0x1u<<0)

// CH5_CC Configuration

#define	PWM_CH5_CC_A					(0xFFFFu<<0)
#define	PWM_CH5_CC_A_0					(0x1u<<0)
#define	PWM_CH5_CC_B					(0xFFFFu<<16)
#define	PWM_CH5_CC_B_0					(0x1u<<16)

// CH5_TOP Configuration

#define	PWM_CH5_TOP_CH5_TOP				(0xFFFFu<<0)
#define	PWM_CH5_TOP_CH5_TOP_0			(0x1u<<0)

// CH6_CSR Configuration

#define	PWM_CH6_CSR_EN					(0x1u<<0)
#define	PWM_CH6_CSR_PH_CORRECT			(0x1u<<1)
#define	PWM_CH6_CSR_A_INV				(0x1u<<2)
#define	PWM_CH6_CSR_B_INV				(0x1u<<3)
#define	PWM_CH6_CSR_DIVMODE				(0x3u<<4)
#define	PWM_CH6_CSR_DIVMODE_0			(0x1u<<4)
#define	PWM_CH6_CSR_PH_RET				(0x1u<<6)
#define	PWM_CH6_CSR_PH_ADV				(0x1u<<7)
#define	PWM_CH6_CSR_DIVMODE_DIV			(0x0u<<4)
#define	PWM_CH6_CSR_DIVMODE_LEVEL		(0x1u<<4)
#define	PWM_CH6_CSR_DIVMODE_RISE		(0x2u<<4)
#define	PWM_CH6_CSR_DIVMODE_FALL		(0x3u<<4)

// CH6_DIV Configuration

#define	PWM_CH6_DIV_FRAC				(0xFu<<0)
#define	PWM_CH6_DIV_FRAC_0				(0x1u<<0)
#define	PWM_CH6_DIV_INT					(0xFFu<<4)
#define	PWM_CH6_DIV_INT_0				(0x1u<<4)

// CH6_CTR Configuration

#define	PWM_CH6_CTR_CH6_CTR				(0xFFFFu<<0)
#define	PWM_CH6_CTR_CH6_CTR_0			(0x1u<<0)

// CH6_CC Configuration

#define	PWM_CH6_CC_A					(0xFFFFu<<0)
#define	PWM_CH6_CC_A_0					(0x1u<<0)
#define	PWM_CH6_CC_B					(0xFFFFu<<16)
#define	PWM_CH6_CC_B_0					(0x1u<<16)

// CH6_TOP Configuration

#define	PWM_CH6_TOP_CH6_TOP				(0xFFFFu<<0)
#define	PWM_CH6_TOP_CH6_TOP_0			(0x1u<<0)

// CH7_CSR Configuration

#define	PWM_CH7_CSR_EN					(0x1u<<0)
#define	PWM_CH7_CSR_PH_CORRECT			(0x1u<<1)
#define	PWM_CH7_CSR_A_INV				(0x1u<<2)
#define	PWM_CH7_CSR_B_INV				(0x1u<<3)
#define	PWM_CH7_CSR_DIVMODE				(0x3u<<4)
#define	PWM_CH7_CSR_DIVMODE_0			(0x1u<<4)
#define	PWM_CH7_CSR_PH_RET				(0x1u<<6)
#define	PWM_CH7_CSR_PH_ADV				(0x1u<<7)
#define	PWM_CH7_CSR_DIVMODE_DIV			(0x0u<<4)
#define	PWM_CH7_CSR_DIVMODE_LEVEL		(0x1u<<4)
#define	PWM_CH7_CSR_DIVMODE_RISE		(0x2u<<4)
#define	PWM_CH7_CSR_DIVMODE_FALL		(0x3u<<4)

// CH7_DIV Configuration

#define	PWM_CH7_DIV_FRAC				(0xFu<<0)
#define	PWM_CH7_DIV_FRAC_0				(0x1u<<0)
#define	PWM_CH7_DIV_INT					(0xFFu<<4)
#define	PWM_CH7_DIV_INT_0				(0x1u<<4)

// CH7_CTR Configuration

#define	PWM_CH7_CTR_CH7_CTR				(0xFFFFu<<0)
#define	PWM_CH7_CTR_CH7_CTR_0			(0x1u<<0)

// CH7_CC Configuration

#define	PWM_CH7_CC_A					(0xFFFFu<<0)
#define	PWM_CH7_CC_A_0					(0x1u<<0)
#define	PWM_CH7_CC_B					(0xFFFFu<<16)
#define	PWM_CH7_CC_B_0					(0x1u<<16)

// CH7_TOP Configuration

#define	PWM_CH7_TOP_CH7_TOP				(0xFFFFu<<0)
#define	PWM_CH7_TOP_CH7_TOP_0			(0x1u<<0)

// CH8_CSR Configuration

#define	PWM_CH8_CSR_EN					(0x1u<<0)
#define	PWM_CH8_CSR_PH_CORRECT			(0x1u<<1)
#define	PWM_CH8_CSR_A_INV				(0x1u<<2)
#define	PWM_CH8_CSR_B_INV				(0x1u<<3)
#define	PWM_CH8_CSR_DIVMODE				(0x3u<<4)
#define	PWM_CH8_CSR_DIVMODE_0			(0x1u<<4)
#define	PWM_CH8_CSR_PH_RET				(0x1u<<6)
#define	PWM_CH8_CSR_PH_ADV				(0x1u<<7)
#define	PWM_CH8_CSR_DIVMODE_DIV			(0x0u<<4)
#define	PWM_CH8_CSR_DIVMODE_LEVEL		(0x1u<<4)
#define	PWM_CH8_CSR_DIVMODE_RISE		(0x2u<<4)
#define	PWM_CH8_CSR_DIVMODE_FALL		(0x3u<<4)

// CH8_DIV Configuration

#define	PWM_CH8_DIV_FRAC				(0xFu<<0)
#define	PWM_CH8_DIV_FRAC_0				(0x1u<<0)
#define	PWM_CH8_DIV_INT					(0xFFu<<4)
#define	PWM_CH8_DIV_INT_0				(0x1u<<4)

// CH8_CTR Configuration

#define	PWM_CH8_CTR_CH8_CTR				(0xFFFFu<<0)
#define	PWM_CH8_CTR_CH8_CTR_0			(0x1u<<0)

// CH8_CC Configuration

#define	PWM_CH8_CC_A					(0xFFFFu<<0)
#define	PWM_CH8_CC_A_0					(0x1u<<0)
#define	PWM_CH8_CC_B					(0xFFFFu<<16)
#define	PWM_CH8_CC_B_0					(0x1u<<16)

// CH8_TOP Configuration

#define	PWM_CH8_TOP_CH8_TOP				(0xFFFFu<<0)
#define	PWM_CH8_TOP_CH8_TOP_0			(0x1u<<0)

// CH9_CSR Configuration

#define	PWM_CH9_CSR_EN					(0x1u<<0)
#define	PWM_CH9_CSR_PH_CORRECT			(0x1u<<1)
#define	PWM_CH9_CSR_A_INV				(0x1u<<2)
#define	PWM_CH9_CSR_B_INV				(0x1u<<3)
#define	PWM_CH9_CSR_DIVMODE				(0x3u<<4)
#define	PWM_CH9_CSR_DIVMODE_0			(0x1u<<4)
#define	PWM_CH9_CSR_PH_RET				(0x1u<<6)
#define	PWM_CH9_CSR_PH_ADV				(0x1u<<7)
#define	PWM_CH9_CSR_DIVMODE_DIV			(0x0u<<4)
#define	PWM_CH9_CSR_DIVMODE_LEVEL		(0x1u<<4)
#define	PWM_CH9_CSR_DIVMODE_RISE		(0x2u<<4)
#define	PWM_CH9_CSR_DIVMODE_FALL		(0x3u<<4)

// CH9_DIV Configuration

#define	PWM_CH9_DIV_FRAC				(0xFu<<0)
#define	PWM_CH9_DIV_FRAC_0				(0x1u<<0)
#define	PWM_CH9_DIV_INT					(0xFFu<<4)
#define	PWM_CH9_DIV_INT_0				(0x1u<<4)

// CH9_CTR Configuration

#define	PWM_CH9_CTR_CH9_CTR				(0xFFFFu<<0)
#define	PWM_CH9_CTR_CH9_CTR_0			(0x1u<<0)

// CH9_CC Configuration

#define	PWM_CH9_CC_A					(0xFFFFu<<0)
#define	PWM_CH9_CC_A_0					(0x1u<<0)
#define	PWM_CH9_CC_B					(0xFFFFu<<16)
#define	PWM_CH9_CC_B_0					(0x1u<<16)

// CH9_TOP Configuration

#define	PWM_CH9_TOP_CH9_TOP				(0xFFFFu<<0)
#define	PWM_CH9_TOP_CH9_TOP_0			(0x1u<<0)

// CH10_CSR Configuration

#define	PWM_CH10_CSR_EN					(0x1u<<0)
#define	PWM_CH10_CSR_PH_CORRECT			(0x1u<<1)
#define	PWM_CH10_CSR_A_INV				(0x1u<<2)
#define	PWM_CH10_CSR_B_INV				(0x1u<<3)
#define	PWM_CH10_CSR_DIVMODE			(0x3u<<4)
#define	PWM_CH10_CSR_DIVMODE_0			(0x1u<<4)
#define	PWM_CH10_CSR_PH_RET				(0x1u<<6)
#define	PWM_CH10_CSR_PH_ADV				(0x1u<<7)
#define	PWM_CH10_CSR_DIVMODE_DIV		(0x0u<<4)
#define	PWM_CH10_CSR_DIVMODE_LEVEL		(0x1u<<4)
#define	PWM_CH10_CSR_DIVMODE_RISE		(0x2u<<4)
#define	PWM_CH10_CSR_DIVMODE_FALL		(0x3u<<4)

// CH10_DIV Configuration

#define	PWM_CH10_DIV_FRAC				(0xFu<<0)
#define	PWM_CH10_DIV_FRAC_0				(0x1u<<0)
#define	PWM_CH10_DIV_INT				(0xFFu<<4)
#define	PWM_CH10_DIV_INT_0				(0x1u<<4)

// CH10_CTR Configuration

#define	PWM_CH10_CTR_CH10_CTR			(0xFFFFu<<0)
#define	PWM_CH10_CTR_CH10_CTR_0			(0x1u<<0)

// CH10_CC Configuration

#define	PWM_CH10_CC_A					(0xFFFFu<<0)
#define	PWM_CH10_CC_A_0					(0x1u<<0)
#define	PWM_CH10_CC_B					(0xFFFFu<<16)
#define	PWM_CH10_CC_B_0					(0x1u<<16)

// CH10_TOP Configuration

#define	PWM_CH10_TOP_CH10_TOP			(0xFFFFu<<0)
#define	PWM_CH10_TOP_CH10_TOP_0			(0x1u<<0)

// CH11_CSR Configuration

#define	PWM_CH11_CSR_EN					(0x1u<<0)
#define	PWM_CH11_CSR_PH_CORRECT			(0x1u<<1)
#define	PWM_CH11_CSR_A_INV				(0x1u<<2)
#define	PWM_CH11_CSR_B_INV				(0x1u<<3)
#define	PWM_CH11_CSR_DIVMODE			(0x3u<<4)
#define	PWM_CH11_CSR_DIVMODE_0			(0x1u<<4)
#define	PWM_CH11_CSR_PH_RET				(0x1u<<6)
#define	PWM_CH11_CSR_PH_ADV				(0x1u<<7)
#define	PWM_CH11_CSR_DIVMODE_DIV		(0x0u<<4)
#define	PWM_CH11_CSR_DIVMODE_LEVEL		(0x1u<<4)
#define	PWM_CH11_CSR_DIVMODE_RISE		(0x2u<<4)
#define	PWM_CH11_CSR_DIVMODE_FALL		(0x3u<<4)

// CH11_DIV Configuration

#define	PWM_CH11_DIV_FRAC				(0xFu<<0)
#define	PWM_CH11_DIV_FRAC_0				(0x1u<<0)
#define	PWM_CH11_DIV_INT				(0xFFu<<4)
#define	PWM_CH11_DIV_INT_0				(0x1u<<4)

// CH11_CTR Configuration

#define	PWM_CH11_CTR_CH11_CTR			(0xFFFFu<<0)
#define	PWM_CH11_CTR_CH11_CTR_0			(0x1u<<0)

// CH11_CC Configuration

#define	PWM_CH11_CC_A					(0xFFFFu<<0)
#define	PWM_CH11_CC_A_0					(0x1u<<0)
#define	PWM_CH11_CC_B					(0xFFFFu<<16)
#define	PWM_CH11_CC_B_0					(0x1u<<16)

// CH11_TOP Configuration

#define	PWM_CH11_TOP_CH11_TOP			(0xFFFFu<<0)
#define	PWM_CH11_TOP_CH11_TOP_0			(0x1u<<0)

// EN Configuration

#define	PWM_EN_CH0						(0x1u<<0)
#define	PWM_EN_CH1						(0x1u<<1)
#define	PWM_EN_CH2						(0x1u<<2)
#define	PWM_EN_CH3						(0x1u<<3)
#define	PWM_EN_CH4						(0x1u<<4)
#define	PWM_EN_CH5						(0x1u<<5)
#define	PWM_EN_CH6						(0x1u<<6)
#define	PWM_EN_CH7						(0x1u<<7)
#define	PWM_EN_CH8						(0x1u<<8)
#define	PWM_EN_CH9						(0x1u<<9)
#define	PWM_EN_CH10						(0x1u<<10)
#define	PWM_EN_CH11						(0x1u<<11)

// INTR Configuration

#define	PWM_INTR_CH0					(0x1u<<0)
#define	PWM_INTR_CH1					(0x1u<<1)
#define	PWM_INTR_CH2					(0x1u<<2)
#define	PWM_INTR_CH3					(0x1u<<3)
#define	PWM_INTR_CH4					(0x1u<<4)
#define	PWM_INTR_CH5					(0x1u<<5)
#define	PWM_INTR_CH6					(0x1u<<6)
#define	PWM_INTR_CH7					(0x1u<<7)
#define	PWM_INTR_CH8					(0x1u<<8)
#define	PWM_INTR_CH9					(0x1u<<9)
#define	PWM_INTR_CH10					(0x1u<<10)
#define	PWM_INTR_CH11					(0x1u<<11)

// IRQ0_INTE Configuration

#define	PWM_IRQ0_INTE_CH0				(0x1u<<0)
#define	PWM_IRQ0_INTE_CH1				(0x1u<<1)
#define	PWM_IRQ0_INTE_CH2				(0x1u<<2)
#define	PWM_IRQ0_INTE_CH3				(0x1u<<3)
#define	PWM_IRQ0_INTE_CH4				(0x1u<<4)
#define	PWM_IRQ0_INTE_CH5				(0x1u<<5)
#define	PWM_IRQ0_INTE_CH6				(0x1u<<6)
#define	PWM_IRQ0_INTE_CH7				(0x1u<<7)
#define	PWM_IRQ0_INTE_CH8				(0x1u<<8)
#define	PWM_IRQ0_INTE_CH9				(0x1u<<9)
#define	PWM_IRQ0_INTE_CH10				(0x1u<<10)
#define	PWM_IRQ0_INTE_CH11				(0x1u<<11)

// IRQ0_INTF Configuration

#define	PWM_IRQ0_INTF_CH0				(0x1u<<0)
#define	PWM_IRQ0_INTF_CH1				(0x1u<<1)
#define	PWM_IRQ0_INTF_CH2				(0x1u<<2)
#define	PWM_IRQ0_INTF_CH3				(0x1u<<3)
#define	PWM_IRQ0_INTF_CH4				(0x1u<<4)
#define	PWM_IRQ0_INTF_CH5				(0x1u<<5)
#define	PWM_IRQ0_INTF_CH6				(0x1u<<6)
#define	PWM_IRQ0_INTF_CH7				(0x1u<<7)
#define	PWM_IRQ0_INTF_CH8				(0x1u<<8)
#define	PWM_IRQ0_INTF_CH9				(0x1u<<9)
#define	PWM_IRQ0_INTF_CH10				(0x1u<<10)
#define	PWM_IRQ0_INTF_CH11				(0x1u<<11)

// IRQ0_INTS Configuration

#define	PWM_IRQ0_INTS_CH0				(0x1u<<0)
#define	PWM_IRQ0_INTS_CH1				(0x1u<<1)
#define	PWM_IRQ0_INTS_CH2				(0x1u<<2)
#define	PWM_IRQ0_INTS_CH3				(0x1u<<3)
#define	PWM_IRQ0_INTS_CH4				(0x1u<<4)
#define	PWM_IRQ0_INTS_CH5				(0x1u<<5)
#define	PWM_IRQ0_INTS_CH6				(0x1u<<6)
#define	PWM_IRQ0_INTS_CH7				(0x1u<<7)
#define	PWM_IRQ0_INTS_CH8				(0x1u<<8)
#define	PWM_IRQ0_INTS_CH9				(0x1u<<9)
#define	PWM_IRQ0_INTS_CH10				(0x1u<<10)
#define	PWM_IRQ0_INTS_CH11				(0x1u<<11)

// IRQ1_INTE Configuration

#define	PWM_IRQ1_INTE_CH0				(0x1u<<0)
#define	PWM_IRQ1_INTE_CH1				(0x1u<<1)
#define	PWM_IRQ1_INTE_CH2				(0x1u<<2)
#define	PWM_IRQ1_INTE_CH3				(0x1u<<3)
#define	PWM_IRQ1_INTE_CH4				(0x1u<<4)
#define	PWM_IRQ1_INTE_CH5				(0x1u<<5)
#define	PWM_IRQ1_INTE_CH6				(0x1u<<6)
#define	PWM_IRQ1_INTE_CH7				(0x1u<<7)
#define	PWM_IRQ1_INTE_CH8				(0x1u<<8)
#define	PWM_IRQ1_INTE_CH9				(0x1u<<9)
#define	PWM_IRQ1_INTE_CH10				(0x1u<<10)
#define	PWM_IRQ1_INTE_CH11				(0x1u<<11)

// IRQ1_INTF Configuration

#define	PWM_IRQ1_INTF_CH0				(0x1u<<0)
#define	PWM_IRQ1_INTF_CH1				(0x1u<<1)
#define	PWM_IRQ1_INTF_CH2				(0x1u<<2)
#define	PWM_IRQ1_INTF_CH3				(0x1u<<3)
#define	PWM_IRQ1_INTF_CH4				(0x1u<<4)
#define	PWM_IRQ1_INTF_CH5				(0x1u<<5)
#define	PWM_IRQ1_INTF_CH6				(0x1u<<6)
#define	PWM_IRQ1_INTF_CH7				(0x1u<<7)
#define	PWM_IRQ1_INTF_CH8				(0x1u<<8)
#define	PWM_IRQ1_INTF_CH9				(0x1u<<9)
#define	PWM_IRQ1_INTF_CH10				(0x1u<<10)
#define	PWM_IRQ1_INTF_CH11				(0x1u<<11)

// IRQ1_INTS Configuration

#define	PWM_IRQ1_INTS_CH0				(0x1u<<0)
#define	PWM_IRQ1_INTS_CH1				(0x1u<<1)
#define	PWM_IRQ1_INTS_CH2				(0x1u<<2)
#define	PWM_IRQ1_INTS_CH3				(0x1u<<3)
#define	PWM_IRQ1_INTS_CH4				(0x1u<<4)
#define	PWM_IRQ1_INTS_CH5				(0x1u<<5)
#define	PWM_IRQ1_INTS_CH6				(0x1u<<6)
#define	PWM_IRQ1_INTS_CH7				(0x1u<<7)
#define	PWM_IRQ1_INTS_CH8				(0x1u<<8)
#define	PWM_IRQ1_INTS_CH9				(0x1u<<9)
#define	PWM_IRQ1_INTS_CH10				(0x1u<<10)
#define	PWM_IRQ1_INTS_CH11				(0x1u<<11)
