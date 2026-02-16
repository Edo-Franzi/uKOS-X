/*
; RP2350_hstx_ctrl.
; =================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_hstx_ctrl equates.
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

// HSTX_CTRL address definitions
// -----------------------------

typedef struct {
	volatile	uint32_t	CSR;
	volatile	uint32_t	BIT0;
	volatile	uint32_t	BIT1;
	volatile	uint32_t	BIT2;
	volatile	uint32_t	BIT3;
	volatile	uint32_t	BIT4;
	volatile	uint32_t	BIT5;
	volatile	uint32_t	BIT6;
	volatile	uint32_t	BIT7;
	volatile	uint32_t	EXPAND_SHIFT;
	volatile	uint32_t	EXPAND_TMDS;
} HSTX_CTRL_TypeDef;

#ifdef __cplusplus
#define	HSTX_CTRL_NS	reinterpret_cast<HSTX_CTRL_TypeDef *>(0x400C0000u)
#define	HSTX_CTRL_S		reinterpret_cast<HSTX_CTRL_TypeDef *>(0x400C0000u)
#else
#define	HSTX_CTRL_NS	((HSTX_CTRL_TypeDef *)0x400C0000u)
#define	HSTX_CTRL_S		((HSTX_CTRL_TypeDef *)0x400C0000u)
#endif

// CSR Configuration

#define	HSTX_CTRL_CSR_EN						(0x1u<<0)
#define	HSTX_CTRL_CSR_EXPAND_EN					(0x1u<<1)
#define	HSTX_CTRL_CSR_COUPLED_MODE				(0x1u<<4)
#define	HSTX_CTRL_CSR_COUPLED_SEL				(0x3u<<5)
#define	HSTX_CTRL_CSR_COUPLED_SEL_0				(0x1u<<5)
#define	HSTX_CTRL_CSR_SHIFT						(0x1Fu<<8)
#define	HSTX_CTRL_CSR_SHIFT_0					(0x1u<<8)
#define	HSTX_CTRL_CSR_N_SHIFTS					(0x1Fu<<16)
#define	HSTX_CTRL_CSR_N_SHIFTS_0				(0x1u<<16)
#define	HSTX_CTRL_CSR_CLKPHASE					(0xFu<<24)
#define	HSTX_CTRL_CSR_CLKPHASE_0				(0x1u<<24)
#define	HSTX_CTRL_CSR_CLKDIV					(0xFu<<28)
#define	HSTX_CTRL_CSR_CLKDIV_0					(0x1u<<28)

// BIT0 Configuration

#define	HSTX_CTRL_BIT0_SEL_P					(0x1Fu<<0)
#define	HSTX_CTRL_BIT0_SEL_P_0					(0x1u<<0)
#define	HSTX_CTRL_BIT0_SEL_N					(0x1Fu<<8)
#define	HSTX_CTRL_BIT0_SEL_N_0					(0x1u<<8)
#define	HSTX_CTRL_BIT0_INV						(0x1u<<16)
#define	HSTX_CTRL_BIT0_CLK						(0x1u<<17)

// BIT1 Configuration

#define	HSTX_CTRL_BIT1_SEL_P					(0x1Fu<<0)
#define	HSTX_CTRL_BIT1_SEL_P_0					(0x1u<<0)
#define	HSTX_CTRL_BIT1_SEL_N					(0x1Fu<<8)
#define	HSTX_CTRL_BIT1_SEL_N_0					(0x1u<<8)
#define	HSTX_CTRL_BIT1_INV						(0x1u<<16)
#define	HSTX_CTRL_BIT1_CLK						(0x1u<<17)

// BIT2 Configuration

#define	HSTX_CTRL_BIT2_SEL_P					(0x1Fu<<0)
#define	HSTX_CTRL_BIT2_SEL_P_0					(0x1u<<0)
#define	HSTX_CTRL_BIT2_SEL_N					(0x1Fu<<8)
#define	HSTX_CTRL_BIT2_SEL_N_0					(0x1u<<8)
#define	HSTX_CTRL_BIT2_INV						(0x1u<<16)
#define	HSTX_CTRL_BIT2_CLK						(0x1u<<17)

// BIT3 Configuration

#define	HSTX_CTRL_BIT3_SEL_P					(0x1Fu<<0)
#define	HSTX_CTRL_BIT3_SEL_P_0					(0x1u<<0)
#define	HSTX_CTRL_BIT3_SEL_N					(0x1Fu<<8)
#define	HSTX_CTRL_BIT3_SEL_N_0					(0x1u<<8)
#define	HSTX_CTRL_BIT3_INV						(0x1u<<16)
#define	HSTX_CTRL_BIT3_CLK						(0x1u<<17)

// BIT4 Configuration

#define	HSTX_CTRL_BIT4_SEL_P					(0x1Fu<<0)
#define	HSTX_CTRL_BIT4_SEL_P_0					(0x1u<<0)
#define	HSTX_CTRL_BIT4_SEL_N					(0x1Fu<<8)
#define	HSTX_CTRL_BIT4_SEL_N_0					(0x1u<<8)
#define	HSTX_CTRL_BIT4_INV						(0x1u<<16)
#define	HSTX_CTRL_BIT4_CLK						(0x1u<<17)

// BIT5 Configuration

#define	HSTX_CTRL_BIT5_SEL_P					(0x1Fu<<0)
#define	HSTX_CTRL_BIT5_SEL_P_0					(0x1u<<0)
#define	HSTX_CTRL_BIT5_SEL_N					(0x1Fu<<8)
#define	HSTX_CTRL_BIT5_SEL_N_0					(0x1u<<8)
#define	HSTX_CTRL_BIT5_INV						(0x1u<<16)
#define	HSTX_CTRL_BIT5_CLK						(0x1u<<17)

// BIT6 Configuration

#define	HSTX_CTRL_BIT6_SEL_P					(0x1Fu<<0)
#define	HSTX_CTRL_BIT6_SEL_P_0					(0x1u<<0)
#define	HSTX_CTRL_BIT6_SEL_N					(0x1Fu<<8)
#define	HSTX_CTRL_BIT6_SEL_N_0					(0x1u<<8)
#define	HSTX_CTRL_BIT6_INV						(0x1u<<16)
#define	HSTX_CTRL_BIT6_CLK						(0x1u<<17)

// BIT7 Configuration

#define	HSTX_CTRL_BIT7_SEL_P					(0x1Fu<<0)
#define	HSTX_CTRL_BIT7_SEL_P_0					(0x1u<<0)
#define	HSTX_CTRL_BIT7_SEL_N					(0x1Fu<<8)
#define	HSTX_CTRL_BIT7_SEL_N_0					(0x1u<<8)
#define	HSTX_CTRL_BIT7_INV						(0x1u<<16)
#define	HSTX_CTRL_BIT7_CLK						(0x1u<<17)

// EXPAND_SHIFT Configuration

#define	HSTX_CTRL_EXPAND_SHIFT_RAW_SHIFT		(0x1Fu<<0)
#define	HSTX_CTRL_EXPAND_SHIFT_RAW_SHIFT_0		(0x1u<<0)
#define	HSTX_CTRL_EXPAND_SHIFT_RAW_N_SHIFTS		(0x1Fu<<8)
#define	HSTX_CTRL_EXPAND_SHIFT_RAW_N_SHIFTS_0	(0x1u<<8)
#define	HSTX_CTRL_EXPAND_SHIFT_ENC_SHIFT		(0x1Fu<<16)
#define	HSTX_CTRL_EXPAND_SHIFT_ENC_SHIFT_0		(0x1u<<16)
#define	HSTX_CTRL_EXPAND_SHIFT_ENC_N_SHIFTS		(0x1Fu<<24)
#define	HSTX_CTRL_EXPAND_SHIFT_ENC_N_SHIFTS_0	(0x1u<<24)

// EXPAND_TMDS Configuration

#define	HSTX_CTRL_EXPAND_TMDS_L0_ROT			(0x1Fu<<0)
#define	HSTX_CTRL_EXPAND_TMDS_L0_ROT_0			(0x1u<<0)
#define	HSTX_CTRL_EXPAND_TMDS_L0_NBITS			(0x7u<<5)
#define	HSTX_CTRL_EXPAND_TMDS_L0_NBITS_0		(0x1u<<5)
#define	HSTX_CTRL_EXPAND_TMDS_L1_ROT			(0x1Fu<<8)
#define	HSTX_CTRL_EXPAND_TMDS_L1_ROT_0			(0x1u<<8)
#define	HSTX_CTRL_EXPAND_TMDS_L1_NBITS			(0x7u<<13)
#define	HSTX_CTRL_EXPAND_TMDS_L1_NBITS_0		(0x1u<<13)
#define	HSTX_CTRL_EXPAND_TMDS_L2_ROT			(0x1Fu<<16)
#define	HSTX_CTRL_EXPAND_TMDS_L2_ROT_0			(0x1u<<16)
#define	HSTX_CTRL_EXPAND_TMDS_L2_NBITS			(0x7u<<21)
#define	HSTX_CTRL_EXPAND_TMDS_L2_NBITS_0		(0x1u<<21)
