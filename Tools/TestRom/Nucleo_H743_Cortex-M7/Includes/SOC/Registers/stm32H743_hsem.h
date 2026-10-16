/*
; stm32H743_hsem.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H743_hsem equates.
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
	volatile	uint32_t	IER;
	volatile	uint32_t	ICR;
	volatile	uint32_t	ISR;
	volatile	uint32_t	MISR;
	volatile	uint32_t	RESERVED0[12];
	volatile	uint32_t	CR;
	volatile	uint32_t	KEYR;
} HSEM_TypeDef;

#if (defined(__cplusplus))
#define	HSEM	reinterpret_cast<HSEM_TypeDef *>(0x58026400u)

#else
#define	HSEM	((HSEM_TypeDef *)0x58026400u)
#endif

// R0 Configuration

#define	HSEM_R0_LOCK			(0x1u<<31)
#define	HSEM_R0_MASTERID		(0xFFu<<8)
#define	HSEM_R0_MASTERID_0		(0x1u<<8)
#define	HSEM_R0_PROCID			(0xFFu<<0)
#define	HSEM_R0_PROCID_0		(0x1u<<0)

// R1 Configuration

#define	HSEM_R1_LOCK			(0x1u<<31)
#define	HSEM_R1_MASTERID		(0xFFu<<8)
#define	HSEM_R1_MASTERID_0		(0x1u<<8)
#define	HSEM_R1_PROCID			(0xFFu<<0)
#define	HSEM_R1_PROCID_0		(0x1u<<0)

// R2 Configuration

#define	HSEM_R2_LOCK			(0x1u<<31)
#define	HSEM_R2_MASTERID		(0xFFu<<8)
#define	HSEM_R2_MASTERID_0		(0x1u<<8)
#define	HSEM_R2_PROCID			(0xFFu<<0)
#define	HSEM_R2_PROCID_0		(0x1u<<0)

// R3 Configuration

#define	HSEM_R3_LOCK			(0x1u<<31)
#define	HSEM_R3_MASTERID		(0xFFu<<8)
#define	HSEM_R3_MASTERID_0		(0x1u<<8)
#define	HSEM_R3_PROCID			(0xFFu<<0)
#define	HSEM_R3_PROCID_0		(0x1u<<0)

// R4 Configuration

#define	HSEM_R4_LOCK			(0x1u<<31)
#define	HSEM_R4_MASTERID		(0xFFu<<8)
#define	HSEM_R4_MASTERID_0		(0x1u<<8)
#define	HSEM_R4_PROCID			(0xFFu<<0)
#define	HSEM_R4_PROCID_0		(0x1u<<0)

// R5 Configuration

#define	HSEM_R5_LOCK			(0x1u<<31)
#define	HSEM_R5_MASTERID		(0xFFu<<8)
#define	HSEM_R5_MASTERID_0		(0x1u<<8)
#define	HSEM_R5_PROCID			(0xFFu<<0)
#define	HSEM_R5_PROCID_0		(0x1u<<0)

// R6 Configuration

#define	HSEM_R6_LOCK			(0x1u<<31)
#define	HSEM_R6_MASTERID		(0xFFu<<8)
#define	HSEM_R6_MASTERID_0		(0x1u<<8)
#define	HSEM_R6_PROCID			(0xFFu<<0)
#define	HSEM_R6_PROCID_0		(0x1u<<0)

// R7 Configuration

#define	HSEM_R7_LOCK			(0x1u<<31)
#define	HSEM_R7_MASTERID		(0xFFu<<8)
#define	HSEM_R7_MASTERID_0		(0x1u<<8)
#define	HSEM_R7_PROCID			(0xFFu<<0)
#define	HSEM_R7_PROCID_0		(0x1u<<0)

// R8 Configuration

#define	HSEM_R8_LOCK			(0x1u<<31)
#define	HSEM_R8_MASTERID		(0xFFu<<8)
#define	HSEM_R8_MASTERID_0		(0x1u<<8)
#define	HSEM_R8_PROCID			(0xFFu<<0)
#define	HSEM_R8_PROCID_0		(0x1u<<0)

// R9 Configuration

#define	HSEM_R9_LOCK			(0x1u<<31)
#define	HSEM_R9_MASTERID		(0xFFu<<8)
#define	HSEM_R9_MASTERID_0		(0x1u<<8)
#define	HSEM_R9_PROCID			(0xFFu<<0)
#define	HSEM_R9_PROCID_0		(0x1u<<0)

// R10 Configuration

#define	HSEM_R10_LOCK			(0x1u<<31)
#define	HSEM_R10_MASTERID		(0xFFu<<8)
#define	HSEM_R10_MASTERID_0		(0x1u<<8)
#define	HSEM_R10_PROCID			(0xFFu<<0)
#define	HSEM_R10_PROCID_0		(0x1u<<0)

// R11 Configuration

#define	HSEM_R11_LOCK			(0x1u<<31)
#define	HSEM_R11_MASTERID		(0xFFu<<8)
#define	HSEM_R11_MASTERID_0		(0x1u<<8)
#define	HSEM_R11_PROCID			(0xFFu<<0)
#define	HSEM_R11_PROCID_0		(0x1u<<0)

// R12 Configuration

#define	HSEM_R12_LOCK			(0x1u<<31)
#define	HSEM_R12_MASTERID		(0xFFu<<8)
#define	HSEM_R12_MASTERID_0		(0x1u<<8)
#define	HSEM_R12_PROCID			(0xFFu<<0)
#define	HSEM_R12_PROCID_0		(0x1u<<0)

// R13 Configuration

#define	HSEM_R13_LOCK			(0x1u<<31)
#define	HSEM_R13_MASTERID		(0xFFu<<8)
#define	HSEM_R13_MASTERID_0		(0x1u<<8)
#define	HSEM_R13_PROCID			(0xFFu<<0)
#define	HSEM_R13_PROCID_0		(0x1u<<0)

// R14 Configuration

#define	HSEM_R14_LOCK			(0x1u<<31)
#define	HSEM_R14_MASTERID		(0xFFu<<8)
#define	HSEM_R14_MASTERID_0		(0x1u<<8)
#define	HSEM_R14_PROCID			(0xFFu<<0)
#define	HSEM_R14_PROCID_0		(0x1u<<0)

// R15 Configuration

#define	HSEM_R15_LOCK			(0x1u<<31)
#define	HSEM_R15_MASTERID		(0xFFu<<8)
#define	HSEM_R15_MASTERID_0		(0x1u<<8)
#define	HSEM_R15_PROCID			(0xFFu<<0)
#define	HSEM_R15_PROCID_0		(0x1u<<0)

// R16 Configuration

#define	HSEM_R16_LOCK			(0x1u<<31)
#define	HSEM_R16_MASTERID		(0xFFu<<8)
#define	HSEM_R16_MASTERID_0		(0x1u<<8)
#define	HSEM_R16_PROCID			(0xFFu<<0)
#define	HSEM_R16_PROCID_0		(0x1u<<0)

// R17 Configuration

#define	HSEM_R17_LOCK			(0x1u<<31)
#define	HSEM_R17_MASTERID		(0xFFu<<8)
#define	HSEM_R17_MASTERID_0		(0x1u<<8)
#define	HSEM_R17_PROCID			(0xFFu<<0)
#define	HSEM_R17_PROCID_0		(0x1u<<0)

// R18 Configuration

#define	HSEM_R18_LOCK			(0x1u<<31)
#define	HSEM_R18_MASTERID		(0xFFu<<8)
#define	HSEM_R18_MASTERID_0		(0x1u<<8)
#define	HSEM_R18_PROCID			(0xFFu<<0)
#define	HSEM_R18_PROCID_0		(0x1u<<0)

// R19 Configuration

#define	HSEM_R19_LOCK			(0x1u<<31)
#define	HSEM_R19_MASTERID		(0xFFu<<8)
#define	HSEM_R19_MASTERID_0		(0x1u<<8)
#define	HSEM_R19_PROCID			(0xFFu<<0)
#define	HSEM_R19_PROCID_0		(0x1u<<0)

// R20 Configuration

#define	HSEM_R20_LOCK			(0x1u<<31)
#define	HSEM_R20_MASTERID		(0xFFu<<8)
#define	HSEM_R20_MASTERID_0		(0x1u<<8)
#define	HSEM_R20_PROCID			(0xFFu<<0)
#define	HSEM_R20_PROCID_0		(0x1u<<0)

// R21 Configuration

#define	HSEM_R21_LOCK			(0x1u<<31)
#define	HSEM_R21_MASTERID		(0xFFu<<8)
#define	HSEM_R21_MASTERID_0		(0x1u<<8)
#define	HSEM_R21_PROCID			(0xFFu<<0)
#define	HSEM_R21_PROCID_0		(0x1u<<0)

// R22 Configuration

#define	HSEM_R22_LOCK			(0x1u<<31)
#define	HSEM_R22_MASTERID		(0xFFu<<8)
#define	HSEM_R22_MASTERID_0		(0x1u<<8)
#define	HSEM_R22_PROCID			(0xFFu<<0)
#define	HSEM_R22_PROCID_0		(0x1u<<0)

// R23 Configuration

#define	HSEM_R23_LOCK			(0x1u<<31)
#define	HSEM_R23_MASTERID		(0xFFu<<8)
#define	HSEM_R23_MASTERID_0		(0x1u<<8)
#define	HSEM_R23_PROCID			(0xFFu<<0)
#define	HSEM_R23_PROCID_0		(0x1u<<0)

// R24 Configuration

#define	HSEM_R24_LOCK			(0x1u<<31)
#define	HSEM_R24_MASTERID		(0xFFu<<8)
#define	HSEM_R24_MASTERID_0		(0x1u<<8)
#define	HSEM_R24_PROCID			(0xFFu<<0)
#define	HSEM_R24_PROCID_0		(0x1u<<0)

// R25 Configuration

#define	HSEM_R25_LOCK			(0x1u<<31)
#define	HSEM_R25_MASTERID		(0xFFu<<8)
#define	HSEM_R25_MASTERID_0		(0x1u<<8)
#define	HSEM_R25_PROCID			(0xFFu<<0)
#define	HSEM_R25_PROCID_0		(0x1u<<0)

// R26 Configuration

#define	HSEM_R26_LOCK			(0x1u<<31)
#define	HSEM_R26_MASTERID		(0xFFu<<8)
#define	HSEM_R26_MASTERID_0		(0x1u<<8)
#define	HSEM_R26_PROCID			(0xFFu<<0)
#define	HSEM_R26_PROCID_0		(0x1u<<0)

// R27 Configuration

#define	HSEM_R27_LOCK			(0x1u<<31)
#define	HSEM_R27_MASTERID		(0xFFu<<8)
#define	HSEM_R27_MASTERID_0		(0x1u<<8)
#define	HSEM_R27_PROCID			(0xFFu<<0)
#define	HSEM_R27_PROCID_0		(0x1u<<0)

// R28 Configuration

#define	HSEM_R28_LOCK			(0x1u<<31)
#define	HSEM_R28_MASTERID		(0xFFu<<8)
#define	HSEM_R28_MASTERID_0		(0x1u<<8)
#define	HSEM_R28_PROCID			(0xFFu<<0)
#define	HSEM_R28_PROCID_0		(0x1u<<0)

// R29 Configuration

#define	HSEM_R29_LOCK			(0x1u<<31)
#define	HSEM_R29_MASTERID		(0xFFu<<8)
#define	HSEM_R29_MASTERID_0		(0x1u<<8)
#define	HSEM_R29_PROCID			(0xFFu<<0)
#define	HSEM_R29_PROCID_0		(0x1u<<0)

// R30 Configuration

#define	HSEM_R30_LOCK			(0x1u<<31)
#define	HSEM_R30_MASTERID		(0xFFu<<8)
#define	HSEM_R30_MASTERID_0		(0x1u<<8)
#define	HSEM_R30_PROCID			(0xFFu<<0)
#define	HSEM_R30_PROCID_0		(0x1u<<0)

// R31 Configuration

#define	HSEM_R31_LOCK			(0x1u<<31)
#define	HSEM_R31_MASTERID		(0xFFu<<8)
#define	HSEM_R31_MASTERID_0		(0x1u<<8)
#define	HSEM_R31_PROCID			(0xFFu<<0)
#define	HSEM_R31_PROCID_0		(0x1u<<0)

// RLR0 Configuration

#define	HSEM_RLR0_LOCK			(0x1u<<31)
#define	HSEM_RLR0_MASTERID		(0xFFu<<8)
#define	HSEM_RLR0_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR0_PROCID		(0xFFu<<0)
#define	HSEM_RLR0_PROCID_0		(0x1u<<0)

// RLR1 Configuration

#define	HSEM_RLR1_LOCK			(0x1u<<31)
#define	HSEM_RLR1_MASTERID		(0xFFu<<8)
#define	HSEM_RLR1_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR1_PROCID		(0xFFu<<0)
#define	HSEM_RLR1_PROCID_0		(0x1u<<0)

// RLR2 Configuration

#define	HSEM_RLR2_LOCK			(0x1u<<31)
#define	HSEM_RLR2_MASTERID		(0xFFu<<8)
#define	HSEM_RLR2_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR2_PROCID		(0xFFu<<0)
#define	HSEM_RLR2_PROCID_0		(0x1u<<0)

// RLR3 Configuration

#define	HSEM_RLR3_LOCK			(0x1u<<31)
#define	HSEM_RLR3_MASTERID		(0xFFu<<8)
#define	HSEM_RLR3_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR3_PROCID		(0xFFu<<0)
#define	HSEM_RLR3_PROCID_0		(0x1u<<0)

// RLR4 Configuration

#define	HSEM_RLR4_LOCK			(0x1u<<31)
#define	HSEM_RLR4_MASTERID		(0xFFu<<8)
#define	HSEM_RLR4_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR4_PROCID		(0xFFu<<0)
#define	HSEM_RLR4_PROCID_0		(0x1u<<0)

// RLR5 Configuration

#define	HSEM_RLR5_LOCK			(0x1u<<31)
#define	HSEM_RLR5_MASTERID		(0xFFu<<8)
#define	HSEM_RLR5_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR5_PROCID		(0xFFu<<0)
#define	HSEM_RLR5_PROCID_0		(0x1u<<0)

// RLR6 Configuration

#define	HSEM_RLR6_LOCK			(0x1u<<31)
#define	HSEM_RLR6_MASTERID		(0xFFu<<8)
#define	HSEM_RLR6_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR6_PROCID		(0xFFu<<0)
#define	HSEM_RLR6_PROCID_0		(0x1u<<0)

// RLR7 Configuration

#define	HSEM_RLR7_LOCK			(0x1u<<31)
#define	HSEM_RLR7_MASTERID		(0xFFu<<8)
#define	HSEM_RLR7_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR7_PROCID		(0xFFu<<0)
#define	HSEM_RLR7_PROCID_0		(0x1u<<0)

// RLR8 Configuration

#define	HSEM_RLR8_LOCK			(0x1u<<31)
#define	HSEM_RLR8_MASTERID		(0xFFu<<8)
#define	HSEM_RLR8_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR8_PROCID		(0xFFu<<0)
#define	HSEM_RLR8_PROCID_0		(0x1u<<0)

// RLR9 Configuration

#define	HSEM_RLR9_LOCK			(0x1u<<31)
#define	HSEM_RLR9_MASTERID		(0xFFu<<8)
#define	HSEM_RLR9_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR9_PROCID		(0xFFu<<0)
#define	HSEM_RLR9_PROCID_0		(0x1u<<0)

// RLR10 Configuration

#define	HSEM_RLR10_LOCK			(0x1u<<31)
#define	HSEM_RLR10_MASTERID		(0xFFu<<8)
#define	HSEM_RLR10_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR10_PROCID		(0xFFu<<0)
#define	HSEM_RLR10_PROCID_0		(0x1u<<0)

// RLR11 Configuration

#define	HSEM_RLR11_LOCK			(0x1u<<31)
#define	HSEM_RLR11_MASTERID		(0xFFu<<8)
#define	HSEM_RLR11_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR11_PROCID		(0xFFu<<0)
#define	HSEM_RLR11_PROCID_0		(0x1u<<0)

// RLR12 Configuration

#define	HSEM_RLR12_LOCK			(0x1u<<31)
#define	HSEM_RLR12_MASTERID		(0xFFu<<8)
#define	HSEM_RLR12_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR12_PROCID		(0xFFu<<0)
#define	HSEM_RLR12_PROCID_0		(0x1u<<0)

// RLR13 Configuration

#define	HSEM_RLR13_LOCK			(0x1u<<31)
#define	HSEM_RLR13_MASTERID		(0xFFu<<8)
#define	HSEM_RLR13_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR13_PROCID		(0xFFu<<0)
#define	HSEM_RLR13_PROCID_0		(0x1u<<0)

// RLR14 Configuration

#define	HSEM_RLR14_LOCK			(0x1u<<31)
#define	HSEM_RLR14_MASTERID		(0xFFu<<8)
#define	HSEM_RLR14_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR14_PROCID		(0xFFu<<0)
#define	HSEM_RLR14_PROCID_0		(0x1u<<0)

// RLR15 Configuration

#define	HSEM_RLR15_LOCK			(0x1u<<31)
#define	HSEM_RLR15_MASTERID		(0xFFu<<8)
#define	HSEM_RLR15_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR15_PROCID		(0xFFu<<0)
#define	HSEM_RLR15_PROCID_0		(0x1u<<0)

// RLR16 Configuration

#define	HSEM_RLR16_LOCK			(0x1u<<31)
#define	HSEM_RLR16_MASTERID		(0xFFu<<8)
#define	HSEM_RLR16_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR16_PROCID		(0xFFu<<0)
#define	HSEM_RLR16_PROCID_0		(0x1u<<0)

// RLR17 Configuration

#define	HSEM_RLR17_LOCK			(0x1u<<31)
#define	HSEM_RLR17_MASTERID		(0xFFu<<8)
#define	HSEM_RLR17_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR17_PROCID		(0xFFu<<0)
#define	HSEM_RLR17_PROCID_0		(0x1u<<0)

// RLR18 Configuration

#define	HSEM_RLR18_LOCK			(0x1u<<31)
#define	HSEM_RLR18_MASTERID		(0xFFu<<8)
#define	HSEM_RLR18_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR18_PROCID		(0xFFu<<0)
#define	HSEM_RLR18_PROCID_0		(0x1u<<0)

// RLR19 Configuration

#define	HSEM_RLR19_LOCK			(0x1u<<31)
#define	HSEM_RLR19_MASTERID		(0xFFu<<8)
#define	HSEM_RLR19_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR19_PROCID		(0xFFu<<0)
#define	HSEM_RLR19_PROCID_0		(0x1u<<0)

// RLR20 Configuration

#define	HSEM_RLR20_LOCK			(0x1u<<31)
#define	HSEM_RLR20_MASTERID		(0xFFu<<8)
#define	HSEM_RLR20_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR20_PROCID		(0xFFu<<0)
#define	HSEM_RLR20_PROCID_0		(0x1u<<0)

// RLR21 Configuration

#define	HSEM_RLR21_LOCK			(0x1u<<31)
#define	HSEM_RLR21_MASTERID		(0xFFu<<8)
#define	HSEM_RLR21_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR21_PROCID		(0xFFu<<0)
#define	HSEM_RLR21_PROCID_0		(0x1u<<0)

// RLR22 Configuration

#define	HSEM_RLR22_LOCK			(0x1u<<31)
#define	HSEM_RLR22_MASTERID		(0xFFu<<8)
#define	HSEM_RLR22_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR22_PROCID		(0xFFu<<0)
#define	HSEM_RLR22_PROCID_0		(0x1u<<0)

// RLR23 Configuration

#define	HSEM_RLR23_LOCK			(0x1u<<31)
#define	HSEM_RLR23_MASTERID		(0xFFu<<8)
#define	HSEM_RLR23_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR23_PROCID		(0xFFu<<0)
#define	HSEM_RLR23_PROCID_0		(0x1u<<0)

// RLR24 Configuration

#define	HSEM_RLR24_LOCK			(0x1u<<31)
#define	HSEM_RLR24_MASTERID		(0xFFu<<8)
#define	HSEM_RLR24_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR24_PROCID		(0xFFu<<0)
#define	HSEM_RLR24_PROCID_0		(0x1u<<0)

// RLR25 Configuration

#define	HSEM_RLR25_LOCK			(0x1u<<31)
#define	HSEM_RLR25_MASTERID		(0xFFu<<8)
#define	HSEM_RLR25_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR25_PROCID		(0xFFu<<0)
#define	HSEM_RLR25_PROCID_0		(0x1u<<0)

// RLR26 Configuration

#define	HSEM_RLR26_LOCK			(0x1u<<31)
#define	HSEM_RLR26_MASTERID		(0xFFu<<8)
#define	HSEM_RLR26_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR26_PROCID		(0xFFu<<0)
#define	HSEM_RLR26_PROCID_0		(0x1u<<0)

// RLR27 Configuration

#define	HSEM_RLR27_LOCK			(0x1u<<31)
#define	HSEM_RLR27_MASTERID		(0xFFu<<8)
#define	HSEM_RLR27_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR27_PROCID		(0xFFu<<0)
#define	HSEM_RLR27_PROCID_0		(0x1u<<0)

// RLR28 Configuration

#define	HSEM_RLR28_LOCK			(0x1u<<31)
#define	HSEM_RLR28_MASTERID		(0xFFu<<8)
#define	HSEM_RLR28_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR28_PROCID		(0xFFu<<0)
#define	HSEM_RLR28_PROCID_0		(0x1u<<0)

// RLR29 Configuration

#define	HSEM_RLR29_LOCK			(0x1u<<31)
#define	HSEM_RLR29_MASTERID		(0xFFu<<8)
#define	HSEM_RLR29_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR29_PROCID		(0xFFu<<0)
#define	HSEM_RLR29_PROCID_0		(0x1u<<0)

// RLR30 Configuration

#define	HSEM_RLR30_LOCK			(0x1u<<31)
#define	HSEM_RLR30_MASTERID		(0xFFu<<8)
#define	HSEM_RLR30_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR30_PROCID		(0xFFu<<0)
#define	HSEM_RLR30_PROCID_0		(0x1u<<0)

// RLR31 Configuration

#define	HSEM_RLR31_LOCK			(0x1u<<31)
#define	HSEM_RLR31_MASTERID		(0xFFu<<8)
#define	HSEM_RLR31_MASTERID_0	(0x1u<<8)
#define	HSEM_RLR31_PROCID		(0xFFu<<0)
#define	HSEM_RLR31_PROCID_0		(0x1u<<0)

// IER Configuration

#define	HSEM_IER_ISEM31			(0x1u<<31)
#define	HSEM_IER_ISEM30			(0x1u<<30)
#define	HSEM_IER_ISEM29			(0x1u<<29)
#define	HSEM_IER_ISEM28			(0x1u<<28)
#define	HSEM_IER_ISEM27			(0x1u<<27)
#define	HSEM_IER_ISEM26			(0x1u<<26)
#define	HSEM_IER_ISEM25			(0x1u<<25)
#define	HSEM_IER_ISEM24			(0x1u<<24)
#define	HSEM_IER_ISEM23			(0x1u<<23)
#define	HSEM_IER_ISEM22			(0x1u<<22)
#define	HSEM_IER_ISEM21			(0x1u<<21)
#define	HSEM_IER_ISEM20			(0x1u<<20)
#define	HSEM_IER_ISEM19			(0x1u<<19)
#define	HSEM_IER_ISEM18			(0x1u<<18)
#define	HSEM_IER_ISEM17			(0x1u<<17)
#define	HSEM_IER_ISEM16			(0x1u<<16)
#define	HSEM_IER_ISEM15			(0x1u<<15)
#define	HSEM_IER_ISEM14			(0x1u<<14)
#define	HSEM_IER_ISEM13			(0x1u<<13)
#define	HSEM_IER_ISEM12			(0x1u<<12)
#define	HSEM_IER_ISEM11			(0x1u<<11)
#define	HSEM_IER_ISEM10			(0x1u<<10)
#define	HSEM_IER_ISEM9			(0x1u<<9)
#define	HSEM_IER_ISEM8			(0x1u<<8)
#define	HSEM_IER_ISEM7			(0x1u<<7)
#define	HSEM_IER_ISEM6			(0x1u<<6)
#define	HSEM_IER_ISEM5			(0x1u<<5)
#define	HSEM_IER_ISEM4			(0x1u<<4)
#define	HSEM_IER_ISEM3			(0x1u<<3)
#define	HSEM_IER_ISEM2			(0x1u<<2)
#define	HSEM_IER_ISEM1			(0x1u<<1)
#define	HSEM_IER_ISEM0			(0x1u<<0)

// ICR Configuration

#define	HSEM_ICR_ISEM31			(0x1u<<31)
#define	HSEM_ICR_ISEM30			(0x1u<<30)
#define	HSEM_ICR_ISEM29			(0x1u<<29)
#define	HSEM_ICR_ISEM28			(0x1u<<28)
#define	HSEM_ICR_ISEM27			(0x1u<<27)
#define	HSEM_ICR_ISEM26			(0x1u<<26)
#define	HSEM_ICR_ISEM25			(0x1u<<25)
#define	HSEM_ICR_ISEM24			(0x1u<<24)
#define	HSEM_ICR_ISEM23			(0x1u<<23)
#define	HSEM_ICR_ISEM22			(0x1u<<22)
#define	HSEM_ICR_ISEM21			(0x1u<<21)
#define	HSEM_ICR_ISEM20			(0x1u<<20)
#define	HSEM_ICR_ISEM19			(0x1u<<19)
#define	HSEM_ICR_ISEM18			(0x1u<<18)
#define	HSEM_ICR_ISEM17			(0x1u<<17)
#define	HSEM_ICR_ISEM16			(0x1u<<16)
#define	HSEM_ICR_ISEM15			(0x1u<<15)
#define	HSEM_ICR_ISEM14			(0x1u<<14)
#define	HSEM_ICR_ISEM13			(0x1u<<13)
#define	HSEM_ICR_ISEM12			(0x1u<<12)
#define	HSEM_ICR_ISEM11			(0x1u<<11)
#define	HSEM_ICR_ISEM10			(0x1u<<10)
#define	HSEM_ICR_ISEM9			(0x1u<<9)
#define	HSEM_ICR_ISEM8			(0x1u<<8)
#define	HSEM_ICR_ISEM7			(0x1u<<7)
#define	HSEM_ICR_ISEM6			(0x1u<<6)
#define	HSEM_ICR_ISEM5			(0x1u<<5)
#define	HSEM_ICR_ISEM4			(0x1u<<4)
#define	HSEM_ICR_ISEM3			(0x1u<<3)
#define	HSEM_ICR_ISEM2			(0x1u<<2)
#define	HSEM_ICR_ISEM1			(0x1u<<1)
#define	HSEM_ICR_ISEM0			(0x1u<<0)

// ISR Configuration

#define	HSEM_ISR_ISEM31			(0x1u<<31)
#define	HSEM_ISR_ISEM30			(0x1u<<30)
#define	HSEM_ISR_ISEM29			(0x1u<<29)
#define	HSEM_ISR_ISEM28			(0x1u<<28)
#define	HSEM_ISR_ISEM27			(0x1u<<27)
#define	HSEM_ISR_ISEM26			(0x1u<<26)
#define	HSEM_ISR_ISEM25			(0x1u<<25)
#define	HSEM_ISR_ISEM24			(0x1u<<24)
#define	HSEM_ISR_ISEM23			(0x1u<<23)
#define	HSEM_ISR_ISEM22			(0x1u<<22)
#define	HSEM_ISR_ISEM21			(0x1u<<21)
#define	HSEM_ISR_ISEM20			(0x1u<<20)
#define	HSEM_ISR_ISEM19			(0x1u<<19)
#define	HSEM_ISR_ISEM18			(0x1u<<18)
#define	HSEM_ISR_ISEM17			(0x1u<<17)
#define	HSEM_ISR_ISEM16			(0x1u<<16)
#define	HSEM_ISR_ISEM15			(0x1u<<15)
#define	HSEM_ISR_ISEM14			(0x1u<<14)
#define	HSEM_ISR_ISEM13			(0x1u<<13)
#define	HSEM_ISR_ISEM12			(0x1u<<12)
#define	HSEM_ISR_ISEM11			(0x1u<<11)
#define	HSEM_ISR_ISEM10			(0x1u<<10)
#define	HSEM_ISR_ISEM9			(0x1u<<9)
#define	HSEM_ISR_ISEM8			(0x1u<<8)
#define	HSEM_ISR_ISEM7			(0x1u<<7)
#define	HSEM_ISR_ISEM6			(0x1u<<6)
#define	HSEM_ISR_ISEM5			(0x1u<<5)
#define	HSEM_ISR_ISEM4			(0x1u<<4)
#define	HSEM_ISR_ISEM3			(0x1u<<3)
#define	HSEM_ISR_ISEM2			(0x1u<<2)
#define	HSEM_ISR_ISEM1			(0x1u<<1)
#define	HSEM_ISR_ISEM0			(0x1u<<0)

// MISR Configuration

#define	HSEM_MISR_ISEM31		(0x1u<<31)
#define	HSEM_MISR_ISEM30		(0x1u<<30)
#define	HSEM_MISR_ISEM29		(0x1u<<29)
#define	HSEM_MISR_ISEM28		(0x1u<<28)
#define	HSEM_MISR_ISEM27		(0x1u<<27)
#define	HSEM_MISR_ISEM26		(0x1u<<26)
#define	HSEM_MISR_ISEM25		(0x1u<<25)
#define	HSEM_MISR_ISEM24		(0x1u<<24)
#define	HSEM_MISR_ISEM23		(0x1u<<23)
#define	HSEM_MISR_ISEM22		(0x1u<<22)
#define	HSEM_MISR_ISEM21		(0x1u<<21)
#define	HSEM_MISR_ISEM20		(0x1u<<20)
#define	HSEM_MISR_ISEM19		(0x1u<<19)
#define	HSEM_MISR_ISEM18		(0x1u<<18)
#define	HSEM_MISR_ISEM17		(0x1u<<17)
#define	HSEM_MISR_ISEM16		(0x1u<<16)
#define	HSEM_MISR_ISEM15		(0x1u<<15)
#define	HSEM_MISR_ISEM14		(0x1u<<14)
#define	HSEM_MISR_ISEM13		(0x1u<<13)
#define	HSEM_MISR_ISEM12		(0x1u<<12)
#define	HSEM_MISR_ISEM11		(0x1u<<11)
#define	HSEM_MISR_ISEM10		(0x1u<<10)
#define	HSEM_MISR_ISEM9			(0x1u<<9)
#define	HSEM_MISR_ISEM8			(0x1u<<8)
#define	HSEM_MISR_ISEM7			(0x1u<<7)
#define	HSEM_MISR_ISEM6			(0x1u<<6)
#define	HSEM_MISR_ISEM5			(0x1u<<5)
#define	HSEM_MISR_ISEM4			(0x1u<<4)
#define	HSEM_MISR_ISEM3			(0x1u<<3)
#define	HSEM_MISR_ISEM2			(0x1u<<2)
#define	HSEM_MISR_ISEM1			(0x1u<<1)
#define	HSEM_MISR_ISEM0			(0x1u<<0)

// CR Configuration

#define	HSEM_CR_KEY				(0xFFFFu<<16)
#define	HSEM_CR_KEY_0			(0x1u<<16)
#define	HSEM_CR_MASTERID		(0xFFu<<8)
#define	HSEM_CR_MASTERID_0		(0x1u<<8)

// KEYR Configuration

#define	HSEM_KEYR_KEY			(0xFFFFu<<16)
#define	HSEM_KEYR_KEY_0			(0x1u<<16)
