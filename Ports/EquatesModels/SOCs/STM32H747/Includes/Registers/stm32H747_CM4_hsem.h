/*
; stm32H747_CM4_hsem.
; ===================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H747_CM4_hsem equates.
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

// HSEM address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	R0;
	volatile	uint32_t	R1;
	volatile	uint32_t	R2;
	volatile	uint32_t	R3;
	volatile	uint32_t	R4;
	volatile	uint32_t	R5;
	volatile	uint32_t	R6;
	volatile	uint32_t	R7;
	volatile	uint32_t	R8;
	volatile	uint32_t	R9;
	volatile	uint32_t	R10;
	volatile	uint32_t	R11;
	volatile	uint32_t	R12;
	volatile	uint32_t	R13;
	volatile	uint32_t	R14;
	volatile	uint32_t	R15;
	volatile	uint32_t	R16;
	volatile	uint32_t	R17;
	volatile	uint32_t	R18;
	volatile	uint32_t	R19;
	volatile	uint32_t	R20;
	volatile	uint32_t	R21;
	volatile	uint32_t	R22;
	volatile	uint32_t	R23;
	volatile	uint32_t	R24;
	volatile	uint32_t	R25;
	volatile	uint32_t	R26;
	volatile	uint32_t	R27;
	volatile	uint32_t	R28;
	volatile	uint32_t	R29;
	volatile	uint32_t	R30;
	volatile	uint32_t	R31;
	volatile	uint32_t	RLR0;
	volatile	uint32_t	RLR1;
	volatile	uint32_t	RLR2;
	volatile	uint32_t	RLR3;
	volatile	uint32_t	RLR4;
	volatile	uint32_t	RLR5;
	volatile	uint32_t	RLR6;
	volatile	uint32_t	RLR7;
	volatile	uint32_t	RLR8;
	volatile	uint32_t	RLR9;
	volatile	uint32_t	RLR10;
	volatile	uint32_t	RLR11;
	volatile	uint32_t	RLR12;
	volatile	uint32_t	RLR13;
	volatile	uint32_t	RLR14;
	volatile	uint32_t	RLR15;
	volatile	uint32_t	RLR16;
	volatile	uint32_t	RLR17;
	volatile	uint32_t	RLR18;
	volatile	uint32_t	RLR19;
	volatile	uint32_t	RLR20;
	volatile	uint32_t	RLR21;
	volatile	uint32_t	RLR22;
	volatile	uint32_t	RLR23;
	volatile	uint32_t	RLR24;
	volatile	uint32_t	RLR25;
	volatile	uint32_t	RLR26;
	volatile	uint32_t	RLR27;
	volatile	uint32_t	RLR28;
	volatile	uint32_t	RLR29;
	volatile	uint32_t	RLR30;
	volatile	uint32_t	RLR31;
	volatile	uint32_t	C1IER;
	volatile	uint32_t	C1ICR;
	volatile	uint32_t	C1ISR;
	volatile	uint32_t	C1MISR;
	volatile	uint32_t	C2IER;
	volatile	uint32_t	C2ICR;
	volatile	uint32_t	C2ISR;
	volatile	uint32_t	C2MISR;
	volatile	uint32_t	RESERVED0[8];
	volatile	uint32_t	CR;
	volatile	uint32_t	KEYR;
} HSEM_TypeDef;

#if (defined(__cplusplus))
#define	HSEM	reinterpret_cast<HSEM_TypeDef *>(0x58026400u)

#else
#define	HSEM	((HSEM_TypeDef *)0x58026400u)
#endif

// R0 Configuration

#define	HSEM_R0_LOCK		(0x1u<<31)
#define	HSEM_R0_COREID		(0xFu<<8)
#define	HSEM_R0_COREID_0	(0x1u<<8)
#define	HSEM_R0_PROCID		(0xFFu<<0)
#define	HSEM_R0_PROCID_0	(0x1u<<0)

// R1 Configuration

#define	HSEM_R1_LOCK		(0x1u<<31)
#define	HSEM_R1_COREID		(0xFu<<8)
#define	HSEM_R1_COREID_0	(0x1u<<8)
#define	HSEM_R1_PROCID		(0xFFu<<0)
#define	HSEM_R1_PROCID_0	(0x1u<<0)

// R2 Configuration

#define	HSEM_R2_LOCK		(0x1u<<31)
#define	HSEM_R2_COREID		(0xFu<<8)
#define	HSEM_R2_COREID_0	(0x1u<<8)
#define	HSEM_R2_PROCID		(0xFFu<<0)
#define	HSEM_R2_PROCID_0	(0x1u<<0)

// R3 Configuration

#define	HSEM_R3_LOCK		(0x1u<<31)
#define	HSEM_R3_COREID		(0xFu<<8)
#define	HSEM_R3_COREID_0	(0x1u<<8)
#define	HSEM_R3_PROCID		(0xFFu<<0)
#define	HSEM_R3_PROCID_0	(0x1u<<0)

// R4 Configuration

#define	HSEM_R4_LOCK		(0x1u<<31)
#define	HSEM_R4_COREID		(0xFu<<8)
#define	HSEM_R4_COREID_0	(0x1u<<8)
#define	HSEM_R4_PROCID		(0xFFu<<0)
#define	HSEM_R4_PROCID_0	(0x1u<<0)

// R5 Configuration

#define	HSEM_R5_LOCK		(0x1u<<31)
#define	HSEM_R5_COREID		(0xFu<<8)
#define	HSEM_R5_COREID_0	(0x1u<<8)
#define	HSEM_R5_PROCID		(0xFFu<<0)
#define	HSEM_R5_PROCID_0	(0x1u<<0)

// R6 Configuration

#define	HSEM_R6_LOCK		(0x1u<<31)
#define	HSEM_R6_COREID		(0xFu<<8)
#define	HSEM_R6_COREID_0	(0x1u<<8)
#define	HSEM_R6_PROCID		(0xFFu<<0)
#define	HSEM_R6_PROCID_0	(0x1u<<0)

// R7 Configuration

#define	HSEM_R7_LOCK		(0x1u<<31)
#define	HSEM_R7_COREID		(0xFu<<8)
#define	HSEM_R7_COREID_0	(0x1u<<8)
#define	HSEM_R7_PROCID		(0xFFu<<0)
#define	HSEM_R7_PROCID_0	(0x1u<<0)

// R8 Configuration

#define	HSEM_R8_LOCK		(0x1u<<31)
#define	HSEM_R8_COREID		(0xFu<<8)
#define	HSEM_R8_COREID_0	(0x1u<<8)
#define	HSEM_R8_PROCID		(0xFFu<<0)
#define	HSEM_R8_PROCID_0	(0x1u<<0)

// R9 Configuration

#define	HSEM_R9_LOCK		(0x1u<<31)
#define	HSEM_R9_COREID		(0xFu<<8)
#define	HSEM_R9_COREID_0	(0x1u<<8)
#define	HSEM_R9_PROCID		(0xFFu<<0)
#define	HSEM_R9_PROCID_0	(0x1u<<0)

// R10 Configuration

#define	HSEM_R10_LOCK		(0x1u<<31)
#define	HSEM_R10_COREID		(0xFu<<8)
#define	HSEM_R10_COREID_0	(0x1u<<8)
#define	HSEM_R10_PROCID		(0xFFu<<0)
#define	HSEM_R10_PROCID_0	(0x1u<<0)

// R11 Configuration

#define	HSEM_R11_LOCK		(0x1u<<31)
#define	HSEM_R11_COREID		(0xFu<<8)
#define	HSEM_R11_COREID_0	(0x1u<<8)
#define	HSEM_R11_PROCID		(0xFFu<<0)
#define	HSEM_R11_PROCID_0	(0x1u<<0)

// R12 Configuration

#define	HSEM_R12_LOCK		(0x1u<<31)
#define	HSEM_R12_COREID		(0xFu<<8)
#define	HSEM_R12_COREID_0	(0x1u<<8)
#define	HSEM_R12_PROCID		(0xFFu<<0)
#define	HSEM_R12_PROCID_0	(0x1u<<0)

// R13 Configuration

#define	HSEM_R13_LOCK		(0x1u<<31)
#define	HSEM_R13_COREID		(0xFu<<8)
#define	HSEM_R13_COREID_0	(0x1u<<8)
#define	HSEM_R13_PROCID		(0xFFu<<0)
#define	HSEM_R13_PROCID_0	(0x1u<<0)

// R14 Configuration

#define	HSEM_R14_LOCK		(0x1u<<31)
#define	HSEM_R14_COREID		(0xFu<<8)
#define	HSEM_R14_COREID_0	(0x1u<<8)
#define	HSEM_R14_PROCID		(0xFFu<<0)
#define	HSEM_R14_PROCID_0	(0x1u<<0)

// R15 Configuration

#define	HSEM_R15_LOCK		(0x1u<<31)
#define	HSEM_R15_COREID		(0xFu<<8)
#define	HSEM_R15_COREID_0	(0x1u<<8)
#define	HSEM_R15_PROCID		(0xFFu<<0)
#define	HSEM_R15_PROCID_0	(0x1u<<0)

// R16 Configuration

#define	HSEM_R16_LOCK		(0x1u<<31)
#define	HSEM_R16_COREID		(0xFu<<8)
#define	HSEM_R16_COREID_0	(0x1u<<8)
#define	HSEM_R16_PROCID		(0xFFu<<0)
#define	HSEM_R16_PROCID_0	(0x1u<<0)

// R17 Configuration

#define	HSEM_R17_LOCK		(0x1u<<31)
#define	HSEM_R17_COREID		(0xFu<<8)
#define	HSEM_R17_COREID_0	(0x1u<<8)
#define	HSEM_R17_PROCID		(0xFFu<<0)
#define	HSEM_R17_PROCID_0	(0x1u<<0)

// R18 Configuration

#define	HSEM_R18_LOCK		(0x1u<<31)
#define	HSEM_R18_COREID		(0xFu<<8)
#define	HSEM_R18_COREID_0	(0x1u<<8)
#define	HSEM_R18_PROCID		(0xFFu<<0)
#define	HSEM_R18_PROCID_0	(0x1u<<0)

// R19 Configuration

#define	HSEM_R19_LOCK		(0x1u<<31)
#define	HSEM_R19_COREID		(0xFu<<8)
#define	HSEM_R19_COREID_0	(0x1u<<8)
#define	HSEM_R19_PROCID		(0xFFu<<0)
#define	HSEM_R19_PROCID_0	(0x1u<<0)

// R20 Configuration

#define	HSEM_R20_LOCK		(0x1u<<31)
#define	HSEM_R20_COREID		(0xFu<<8)
#define	HSEM_R20_COREID_0	(0x1u<<8)
#define	HSEM_R20_PROCID		(0xFFu<<0)
#define	HSEM_R20_PROCID_0	(0x1u<<0)

// R21 Configuration

#define	HSEM_R21_LOCK		(0x1u<<31)
#define	HSEM_R21_COREID		(0xFu<<8)
#define	HSEM_R21_COREID_0	(0x1u<<8)
#define	HSEM_R21_PROCID		(0xFFu<<0)
#define	HSEM_R21_PROCID_0	(0x1u<<0)

// R22 Configuration

#define	HSEM_R22_LOCK		(0x1u<<31)
#define	HSEM_R22_COREID		(0xFu<<8)
#define	HSEM_R22_COREID_0	(0x1u<<8)
#define	HSEM_R22_PROCID		(0xFFu<<0)
#define	HSEM_R22_PROCID_0	(0x1u<<0)

// R23 Configuration

#define	HSEM_R23_LOCK		(0x1u<<31)
#define	HSEM_R23_COREID		(0xFu<<8)
#define	HSEM_R23_COREID_0	(0x1u<<8)
#define	HSEM_R23_PROCID		(0xFFu<<0)
#define	HSEM_R23_PROCID_0	(0x1u<<0)

// R24 Configuration

#define	HSEM_R24_LOCK		(0x1u<<31)
#define	HSEM_R24_COREID		(0xFu<<8)
#define	HSEM_R24_COREID_0	(0x1u<<8)
#define	HSEM_R24_PROCID		(0xFFu<<0)
#define	HSEM_R24_PROCID_0	(0x1u<<0)

// R25 Configuration

#define	HSEM_R25_LOCK		(0x1u<<31)
#define	HSEM_R25_COREID		(0xFu<<8)
#define	HSEM_R25_COREID_0	(0x1u<<8)
#define	HSEM_R25_PROCID		(0xFFu<<0)
#define	HSEM_R25_PROCID_0	(0x1u<<0)

// R26 Configuration

#define	HSEM_R26_LOCK		(0x1u<<31)
#define	HSEM_R26_COREID		(0xFu<<8)
#define	HSEM_R26_COREID_0	(0x1u<<8)
#define	HSEM_R26_PROCID		(0xFFu<<0)
#define	HSEM_R26_PROCID_0	(0x1u<<0)

// R27 Configuration

#define	HSEM_R27_LOCK		(0x1u<<31)
#define	HSEM_R27_COREID		(0xFu<<8)
#define	HSEM_R27_COREID_0	(0x1u<<8)
#define	HSEM_R27_PROCID		(0xFFu<<0)
#define	HSEM_R27_PROCID_0	(0x1u<<0)

// R28 Configuration

#define	HSEM_R28_LOCK		(0x1u<<31)
#define	HSEM_R28_COREID		(0xFu<<8)
#define	HSEM_R28_COREID_0	(0x1u<<8)
#define	HSEM_R28_PROCID		(0xFFu<<0)
#define	HSEM_R28_PROCID_0	(0x1u<<0)

// R29 Configuration

#define	HSEM_R29_LOCK		(0x1u<<31)
#define	HSEM_R29_COREID		(0xFu<<8)
#define	HSEM_R29_COREID_0	(0x1u<<8)
#define	HSEM_R29_PROCID		(0xFFu<<0)
#define	HSEM_R29_PROCID_0	(0x1u<<0)

// R30 Configuration

#define	HSEM_R30_LOCK		(0x1u<<31)
#define	HSEM_R30_COREID		(0xFu<<8)
#define	HSEM_R30_COREID_0	(0x1u<<8)
#define	HSEM_R30_PROCID		(0xFFu<<0)
#define	HSEM_R30_PROCID_0	(0x1u<<0)

// R31 Configuration

#define	HSEM_R31_LOCK		(0x1u<<31)
#define	HSEM_R31_COREID		(0xFu<<8)
#define	HSEM_R31_COREID_0	(0x1u<<8)
#define	HSEM_R31_PROCID		(0xFFu<<0)
#define	HSEM_R31_PROCID_0	(0x1u<<0)

// RLR0 Configuration

#define	HSEM_RLR0_LOCK		(0x1u<<31)
#define	HSEM_RLR0_COREID	(0xFu<<8)
#define	HSEM_RLR0_COREID_0	(0x1u<<8)
#define	HSEM_RLR0_PROCID	(0xFFu<<0)
#define	HSEM_RLR0_PROCID_0	(0x1u<<0)

// RLR1 Configuration

#define	HSEM_RLR1_LOCK		(0x1u<<31)
#define	HSEM_RLR1_COREID	(0xFu<<8)
#define	HSEM_RLR1_COREID_0	(0x1u<<8)
#define	HSEM_RLR1_PROCID	(0xFFu<<0)
#define	HSEM_RLR1_PROCID_0	(0x1u<<0)

// RLR2 Configuration

#define	HSEM_RLR2_LOCK		(0x1u<<31)
#define	HSEM_RLR2_COREID	(0xFu<<8)
#define	HSEM_RLR2_COREID_0	(0x1u<<8)
#define	HSEM_RLR2_PROCID	(0xFFu<<0)
#define	HSEM_RLR2_PROCID_0	(0x1u<<0)

// RLR3 Configuration

#define	HSEM_RLR3_LOCK		(0x1u<<31)
#define	HSEM_RLR3_COREID	(0xFu<<8)
#define	HSEM_RLR3_COREID_0	(0x1u<<8)
#define	HSEM_RLR3_PROCID	(0xFFu<<0)
#define	HSEM_RLR3_PROCID_0	(0x1u<<0)

// RLR4 Configuration

#define	HSEM_RLR4_LOCK		(0x1u<<31)
#define	HSEM_RLR4_COREID	(0xFu<<8)
#define	HSEM_RLR4_COREID_0	(0x1u<<8)
#define	HSEM_RLR4_PROCID	(0xFFu<<0)
#define	HSEM_RLR4_PROCID_0	(0x1u<<0)

// RLR5 Configuration

#define	HSEM_RLR5_LOCK		(0x1u<<31)
#define	HSEM_RLR5_COREID	(0xFu<<8)
#define	HSEM_RLR5_COREID_0	(0x1u<<8)
#define	HSEM_RLR5_PROCID	(0xFFu<<0)
#define	HSEM_RLR5_PROCID_0	(0x1u<<0)

// RLR6 Configuration

#define	HSEM_RLR6_LOCK		(0x1u<<31)
#define	HSEM_RLR6_COREID	(0xFu<<8)
#define	HSEM_RLR6_COREID_0	(0x1u<<8)
#define	HSEM_RLR6_PROCID	(0xFFu<<0)
#define	HSEM_RLR6_PROCID_0	(0x1u<<0)

// RLR7 Configuration

#define	HSEM_RLR7_LOCK		(0x1u<<31)
#define	HSEM_RLR7_COREID	(0xFu<<8)
#define	HSEM_RLR7_COREID_0	(0x1u<<8)
#define	HSEM_RLR7_PROCID	(0xFFu<<0)
#define	HSEM_RLR7_PROCID_0	(0x1u<<0)

// RLR8 Configuration

#define	HSEM_RLR8_LOCK		(0x1u<<31)
#define	HSEM_RLR8_COREID	(0xFu<<8)
#define	HSEM_RLR8_COREID_0	(0x1u<<8)
#define	HSEM_RLR8_PROCID	(0xFFu<<0)
#define	HSEM_RLR8_PROCID_0	(0x1u<<0)

// RLR9 Configuration

#define	HSEM_RLR9_LOCK		(0x1u<<31)
#define	HSEM_RLR9_COREID	(0xFu<<8)
#define	HSEM_RLR9_COREID_0	(0x1u<<8)
#define	HSEM_RLR9_PROCID	(0xFFu<<0)
#define	HSEM_RLR9_PROCID_0	(0x1u<<0)

// RLR10 Configuration

#define	HSEM_RLR10_LOCK		(0x1u<<31)
#define	HSEM_RLR10_COREID	(0xFu<<8)
#define	HSEM_RLR10_COREID_0	(0x1u<<8)
#define	HSEM_RLR10_PROCID	(0xFFu<<0)
#define	HSEM_RLR10_PROCID_0	(0x1u<<0)

// RLR11 Configuration

#define	HSEM_RLR11_LOCK		(0x1u<<31)
#define	HSEM_RLR11_COREID	(0xFu<<8)
#define	HSEM_RLR11_COREID_0	(0x1u<<8)
#define	HSEM_RLR11_PROCID	(0xFFu<<0)
#define	HSEM_RLR11_PROCID_0	(0x1u<<0)

// RLR12 Configuration

#define	HSEM_RLR12_LOCK		(0x1u<<31)
#define	HSEM_RLR12_COREID	(0xFu<<8)
#define	HSEM_RLR12_COREID_0	(0x1u<<8)
#define	HSEM_RLR12_PROCID	(0xFFu<<0)
#define	HSEM_RLR12_PROCID_0	(0x1u<<0)

// RLR13 Configuration

#define	HSEM_RLR13_LOCK		(0x1u<<31)
#define	HSEM_RLR13_COREID	(0xFu<<8)
#define	HSEM_RLR13_COREID_0	(0x1u<<8)
#define	HSEM_RLR13_PROCID	(0xFFu<<0)
#define	HSEM_RLR13_PROCID_0	(0x1u<<0)

// RLR14 Configuration

#define	HSEM_RLR14_LOCK		(0x1u<<31)
#define	HSEM_RLR14_COREID	(0xFu<<8)
#define	HSEM_RLR14_COREID_0	(0x1u<<8)
#define	HSEM_RLR14_PROCID	(0xFFu<<0)
#define	HSEM_RLR14_PROCID_0	(0x1u<<0)

// RLR15 Configuration

#define	HSEM_RLR15_LOCK		(0x1u<<31)
#define	HSEM_RLR15_COREID	(0xFu<<8)
#define	HSEM_RLR15_COREID_0	(0x1u<<8)
#define	HSEM_RLR15_PROCID	(0xFFu<<0)
#define	HSEM_RLR15_PROCID_0	(0x1u<<0)

// RLR16 Configuration

#define	HSEM_RLR16_LOCK		(0x1u<<31)
#define	HSEM_RLR16_COREID	(0xFu<<8)
#define	HSEM_RLR16_COREID_0	(0x1u<<8)
#define	HSEM_RLR16_PROCID	(0xFFu<<0)
#define	HSEM_RLR16_PROCID_0	(0x1u<<0)

// RLR17 Configuration

#define	HSEM_RLR17_LOCK		(0x1u<<31)
#define	HSEM_RLR17_COREID	(0xFu<<8)
#define	HSEM_RLR17_COREID_0	(0x1u<<8)
#define	HSEM_RLR17_PROCID	(0xFFu<<0)
#define	HSEM_RLR17_PROCID_0	(0x1u<<0)

// RLR18 Configuration

#define	HSEM_RLR18_LOCK		(0x1u<<31)
#define	HSEM_RLR18_COREID	(0xFu<<8)
#define	HSEM_RLR18_COREID_0	(0x1u<<8)
#define	HSEM_RLR18_PROCID	(0xFFu<<0)
#define	HSEM_RLR18_PROCID_0	(0x1u<<0)

// RLR19 Configuration

#define	HSEM_RLR19_LOCK		(0x1u<<31)
#define	HSEM_RLR19_COREID	(0xFu<<8)
#define	HSEM_RLR19_COREID_0	(0x1u<<8)
#define	HSEM_RLR19_PROCID	(0xFFu<<0)
#define	HSEM_RLR19_PROCID_0	(0x1u<<0)

// RLR20 Configuration

#define	HSEM_RLR20_LOCK		(0x1u<<31)
#define	HSEM_RLR20_COREID	(0xFu<<8)
#define	HSEM_RLR20_COREID_0	(0x1u<<8)
#define	HSEM_RLR20_PROCID	(0xFFu<<0)
#define	HSEM_RLR20_PROCID_0	(0x1u<<0)

// RLR21 Configuration

#define	HSEM_RLR21_LOCK		(0x1u<<31)
#define	HSEM_RLR21_COREID	(0xFu<<8)
#define	HSEM_RLR21_COREID_0	(0x1u<<8)
#define	HSEM_RLR21_PROCID	(0xFFu<<0)
#define	HSEM_RLR21_PROCID_0	(0x1u<<0)

// RLR22 Configuration

#define	HSEM_RLR22_LOCK		(0x1u<<31)
#define	HSEM_RLR22_COREID	(0xFu<<8)
#define	HSEM_RLR22_COREID_0	(0x1u<<8)
#define	HSEM_RLR22_PROCID	(0xFFu<<0)
#define	HSEM_RLR22_PROCID_0	(0x1u<<0)

// RLR23 Configuration

#define	HSEM_RLR23_LOCK		(0x1u<<31)
#define	HSEM_RLR23_COREID	(0xFu<<8)
#define	HSEM_RLR23_COREID_0	(0x1u<<8)
#define	HSEM_RLR23_PROCID	(0xFFu<<0)
#define	HSEM_RLR23_PROCID_0	(0x1u<<0)

// RLR24 Configuration

#define	HSEM_RLR24_LOCK		(0x1u<<31)
#define	HSEM_RLR24_COREID	(0xFu<<8)
#define	HSEM_RLR24_COREID_0	(0x1u<<8)
#define	HSEM_RLR24_PROCID	(0xFFu<<0)
#define	HSEM_RLR24_PROCID_0	(0x1u<<0)

// RLR25 Configuration

#define	HSEM_RLR25_LOCK		(0x1u<<31)
#define	HSEM_RLR25_COREID	(0xFu<<8)
#define	HSEM_RLR25_COREID_0	(0x1u<<8)
#define	HSEM_RLR25_PROCID	(0xFFu<<0)
#define	HSEM_RLR25_PROCID_0	(0x1u<<0)

// RLR26 Configuration

#define	HSEM_RLR26_LOCK		(0x1u<<31)
#define	HSEM_RLR26_COREID	(0xFu<<8)
#define	HSEM_RLR26_COREID_0	(0x1u<<8)
#define	HSEM_RLR26_PROCID	(0xFFu<<0)
#define	HSEM_RLR26_PROCID_0	(0x1u<<0)

// RLR27 Configuration

#define	HSEM_RLR27_LOCK		(0x1u<<31)
#define	HSEM_RLR27_COREID	(0xFu<<8)
#define	HSEM_RLR27_COREID_0	(0x1u<<8)
#define	HSEM_RLR27_PROCID	(0xFFu<<0)
#define	HSEM_RLR27_PROCID_0	(0x1u<<0)

// RLR28 Configuration

#define	HSEM_RLR28_LOCK		(0x1u<<31)
#define	HSEM_RLR28_COREID	(0xFu<<8)
#define	HSEM_RLR28_COREID_0	(0x1u<<8)
#define	HSEM_RLR28_PROCID	(0xFFu<<0)
#define	HSEM_RLR28_PROCID_0	(0x1u<<0)

// RLR29 Configuration

#define	HSEM_RLR29_LOCK		(0x1u<<31)
#define	HSEM_RLR29_COREID	(0xFu<<8)
#define	HSEM_RLR29_COREID_0	(0x1u<<8)
#define	HSEM_RLR29_PROCID	(0xFFu<<0)
#define	HSEM_RLR29_PROCID_0	(0x1u<<0)

// RLR30 Configuration

#define	HSEM_RLR30_LOCK		(0x1u<<31)
#define	HSEM_RLR30_COREID	(0xFu<<8)
#define	HSEM_RLR30_COREID_0	(0x1u<<8)
#define	HSEM_RLR30_PROCID	(0xFFu<<0)
#define	HSEM_RLR30_PROCID_0	(0x1u<<0)

// RLR31 Configuration

#define	HSEM_RLR31_LOCK		(0x1u<<31)
#define	HSEM_RLR31_COREID	(0xFu<<8)
#define	HSEM_RLR31_COREID_0	(0x1u<<8)
#define	HSEM_RLR31_PROCID	(0xFFu<<0)
#define	HSEM_RLR31_PROCID_0	(0x1u<<0)

// C1IER Configuration

#define	HSEM_C1IER_ISE		(0xFFFFFFFFu<<0)
#define	HSEM_C1IER_ISE_0	(0x1u<<0)

// C1ICR Configuration

#define	HSEM_C1ICR_ISC		(0xFFFFFFFFu<<0)
#define	HSEM_C1ICR_ISC_0	(0x1u<<0)

// C1ISR Configuration

#define	HSEM_C1ISR_ISF		(0xFFFFFFFFu<<0)
#define	HSEM_C1ISR_ISF_0	(0x1u<<0)

// C1MISR Configuration

#define	HSEM_C1MISR_MISF	(0xFFFFFFFFu<<0)
#define	HSEM_C1MISR_MISF_0	(0x1u<<0)

// C2IER Configuration

#define	HSEM_C2IER_ISE		(0xFFFFFFFFu<<0)
#define	HSEM_C2IER_ISE_0	(0x1u<<0)

// C2ICR Configuration

#define	HSEM_C2ICR_ISC		(0xFFFFFFFFu<<0)
#define	HSEM_C2ICR_ISC_0	(0x1u<<0)

// C2ISR Configuration

#define	HSEM_C2ISR_ISF		(0xFFFFFFFFu<<0)
#define	HSEM_C2ISR_ISF_0	(0x1u<<0)

// C2MISR Configuration

#define	HSEM_C2MISR_MISF	(0xFFFFFFFFu<<0)
#define	HSEM_C2MISR_MISF_0	(0x1u<<0)

// CR Configuration

#define	HSEM_CR_KEY			(0xFFFFu<<16)
#define	HSEM_CR_KEY_0		(0x1u<<16)
#define	HSEM_CR_COREID		(0xFu<<8)
#define	HSEM_CR_COREID_0	(0x1u<<8)

// KEYR Configuration

#define	HSEM_KEYR_KEY		(0xFFFFu<<16)
#define	HSEM_KEYR_KEY_0		(0x1u<<16)
