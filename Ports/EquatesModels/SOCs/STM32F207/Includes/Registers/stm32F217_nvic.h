/*
; stm32F217_nvic.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_nvic equates.
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

// NVIC address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	ISER0;
	volatile	uint32_t	ISER1;
	volatile	uint32_t	ISER2;
	volatile	uint32_t	RESERVED0[29];
	volatile	uint32_t	ICER0;
	volatile	uint32_t	ICER1;
	volatile	uint32_t	ICER2;
	volatile	uint32_t	RESERVED1[29];
	volatile	uint32_t	ISPR0;
	volatile	uint32_t	ISPR1;
	volatile	uint32_t	ISPR2;
	volatile	uint32_t	RESERVED2[29];
	volatile	uint32_t	ICPR0;
	volatile	uint32_t	ICPR1;
	volatile	uint32_t	ICPR2;
	volatile	uint32_t	RESERVED3[29];
	volatile	uint32_t	IABR0;
	volatile	uint32_t	IABR1;
	volatile	uint32_t	IABR2;
	volatile	uint32_t	RESERVED4[61];
	volatile	uint32_t	IPR0;
	volatile	uint32_t	IPR1;
	volatile	uint32_t	IPR2;
	volatile	uint32_t	IPR3;
	volatile	uint32_t	IPR4;
	volatile	uint32_t	IPR5;
	volatile	uint32_t	IPR6;
	volatile	uint32_t	IPR7;
	volatile	uint32_t	IPR8;
	volatile	uint32_t	IPR9;
	volatile	uint32_t	IPR10;
	volatile	uint32_t	IPR11;
	volatile	uint32_t	IPR12;
	volatile	uint32_t	IPR13;
	volatile	uint32_t	IPR14;
	volatile	uint32_t	IPR15;
	volatile	uint32_t	IPR16;
	volatile	uint32_t	IPR17;
	volatile	uint32_t	IPR18;
	volatile	uint32_t	IPR19;
	volatile	uint32_t	IPR20;
} NVIC_TypeDef;

#if (defined(__cplusplus))
#define	NVIC	reinterpret_cast<NVIC_TypeDef *>(0xE000E100u)

#else
#define	NVIC	((NVIC_TypeDef *)0xE000E100u)
#endif

// ISER0 Configuration

#define	NVIC_ISER0_SETENA		(0xFFFFFFFFu<<0)
#define	NVIC_ISER0_SETENA_0		(0x1u<<0)

// ISER1 Configuration

#define	NVIC_ISER1_SETENA		(0xFFFFFFFFu<<0)
#define	NVIC_ISER1_SETENA_0		(0x1u<<0)

// ISER2 Configuration

#define	NVIC_ISER2_SETENA		(0xFFFFFFFFu<<0)
#define	NVIC_ISER2_SETENA_0		(0x1u<<0)

// ICER0 Configuration

#define	NVIC_ICER0_CLRENA		(0xFFFFFFFFu<<0)
#define	NVIC_ICER0_CLRENA_0		(0x1u<<0)

// ICER1 Configuration

#define	NVIC_ICER1_CLRENA		(0xFFFFFFFFu<<0)
#define	NVIC_ICER1_CLRENA_0		(0x1u<<0)

// ICER2 Configuration

#define	NVIC_ICER2_CLRENA		(0xFFFFFFFFu<<0)
#define	NVIC_ICER2_CLRENA_0		(0x1u<<0)

// ISPR0 Configuration

#define	NVIC_ISPR0_SETPEND		(0xFFFFFFFFu<<0)
#define	NVIC_ISPR0_SETPEND_0	(0x1u<<0)

// ISPR1 Configuration

#define	NVIC_ISPR1_SETPEND		(0xFFFFFFFFu<<0)
#define	NVIC_ISPR1_SETPEND_0	(0x1u<<0)

// ISPR2 Configuration

#define	NVIC_ISPR2_SETPEND		(0xFFFFFFFFu<<0)
#define	NVIC_ISPR2_SETPEND_0	(0x1u<<0)

// ICPR0 Configuration

#define	NVIC_ICPR0_CLRPEND		(0xFFFFFFFFu<<0)
#define	NVIC_ICPR0_CLRPEND_0	(0x1u<<0)

// ICPR1 Configuration

#define	NVIC_ICPR1_CLRPEND		(0xFFFFFFFFu<<0)
#define	NVIC_ICPR1_CLRPEND_0	(0x1u<<0)

// ICPR2 Configuration

#define	NVIC_ICPR2_CLRPEND		(0xFFFFFFFFu<<0)
#define	NVIC_ICPR2_CLRPEND_0	(0x1u<<0)

// IABR0 Configuration

#define	NVIC_IABR0_ACTIVE		(0xFFFFFFFFu<<0)
#define	NVIC_IABR0_ACTIVE_0		(0x1u<<0)

// IABR1 Configuration

#define	NVIC_IABR1_ACTIVE		(0xFFFFFFFFu<<0)
#define	NVIC_IABR1_ACTIVE_0		(0x1u<<0)

// IABR2 Configuration

#define	NVIC_IABR2_ACTIVE		(0xFFFFFFFFu<<0)
#define	NVIC_IABR2_ACTIVE_0		(0x1u<<0)

// IPR0 Configuration

#define	NVIC_IPR0_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR0_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR0_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR0_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR0_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR0_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR0_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR0_IPR_N0_0		(0x1u<<0)

// IPR1 Configuration

#define	NVIC_IPR1_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR1_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR1_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR1_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR1_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR1_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR1_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR1_IPR_N0_0		(0x1u<<0)

// IPR2 Configuration

#define	NVIC_IPR2_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR2_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR2_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR2_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR2_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR2_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR2_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR2_IPR_N0_0		(0x1u<<0)

// IPR3 Configuration

#define	NVIC_IPR3_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR3_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR3_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR3_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR3_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR3_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR3_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR3_IPR_N0_0		(0x1u<<0)

// IPR4 Configuration

#define	NVIC_IPR4_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR4_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR4_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR4_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR4_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR4_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR4_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR4_IPR_N0_0		(0x1u<<0)

// IPR5 Configuration

#define	NVIC_IPR5_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR5_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR5_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR5_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR5_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR5_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR5_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR5_IPR_N0_0		(0x1u<<0)

// IPR6 Configuration

#define	NVIC_IPR6_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR6_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR6_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR6_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR6_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR6_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR6_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR6_IPR_N0_0		(0x1u<<0)

// IPR7 Configuration

#define	NVIC_IPR7_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR7_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR7_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR7_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR7_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR7_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR7_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR7_IPR_N0_0		(0x1u<<0)

// IPR8 Configuration

#define	NVIC_IPR8_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR8_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR8_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR8_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR8_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR8_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR8_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR8_IPR_N0_0		(0x1u<<0)

// IPR9 Configuration

#define	NVIC_IPR9_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR9_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR9_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR9_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR9_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR9_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR9_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR9_IPR_N0_0		(0x1u<<0)

// IPR10 Configuration

#define	NVIC_IPR10_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR10_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR10_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR10_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR10_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR10_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR10_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR10_IPR_N0_0		(0x1u<<0)

// IPR11 Configuration

#define	NVIC_IPR11_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR11_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR11_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR11_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR11_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR11_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR11_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR11_IPR_N0_0		(0x1u<<0)

// IPR12 Configuration

#define	NVIC_IPR12_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR12_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR12_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR12_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR12_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR12_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR12_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR12_IPR_N0_0		(0x1u<<0)

// IPR13 Configuration

#define	NVIC_IPR13_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR13_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR13_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR13_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR13_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR13_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR13_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR13_IPR_N0_0		(0x1u<<0)

// IPR14 Configuration

#define	NVIC_IPR14_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR14_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR14_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR14_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR14_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR14_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR14_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR14_IPR_N0_0		(0x1u<<0)

// IPR15 Configuration

#define	NVIC_IPR15_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR15_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR15_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR15_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR15_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR15_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR15_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR15_IPR_N0_0		(0x1u<<0)

// IPR16 Configuration

#define	NVIC_IPR16_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR16_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR16_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR16_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR16_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR16_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR16_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR16_IPR_N0_0		(0x1u<<0)

// IPR17 Configuration

#define	NVIC_IPR17_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR17_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR17_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR17_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR17_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR17_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR17_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR17_IPR_N0_0		(0x1u<<0)

// IPR18 Configuration

#define	NVIC_IPR18_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR18_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR18_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR18_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR18_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR18_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR18_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR18_IPR_N0_0		(0x1u<<0)

// IPR19 Configuration

#define	NVIC_IPR19_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR19_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR19_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR19_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR19_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR19_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR19_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR19_IPR_N0_0		(0x1u<<0)

// IPR20 Configuration

#define	NVIC_IPR20_IPR_N3		(0xFFu<<24)
#define	NVIC_IPR20_IPR_N3_0		(0x1u<<24)
#define	NVIC_IPR20_IPR_N2		(0xFFu<<16)
#define	NVIC_IPR20_IPR_N2_0		(0x1u<<16)
#define	NVIC_IPR20_IPR_N1		(0xFFu<<8)
#define	NVIC_IPR20_IPR_N1_0		(0x1u<<8)
#define	NVIC_IPR20_IPR_N0		(0xFFu<<0)
#define	NVIC_IPR20_IPR_N0_0		(0x1u<<0)
