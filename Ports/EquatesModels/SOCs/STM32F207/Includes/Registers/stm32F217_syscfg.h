/*
; stm32F217_syscfg.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_syscfg equates.
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

// SYSCFG address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	MEMRM;
	volatile	uint32_t	PMC;
	volatile	uint32_t	EXTICR1;
	volatile	uint32_t	EXTICR2;
	volatile	uint32_t	EXTICR3;
	volatile	uint32_t	EXTICR4;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	CMPCR;
} SYSCFG_TypeDef;

#if (defined(__cplusplus))
#define	SYSCFG	reinterpret_cast<SYSCFG_TypeDef *>(0x40013800u)

#else
#define	SYSCFG	((SYSCFG_TypeDef *)0x40013800u)
#endif

// MEMRM Configuration

#define	SYSCFG_MEMRM_MEM_MODE	(0x3u<<0)
#define	SYSCFG_MEMRM_MEM_MODE_0	(0x1u<<0)

// PMC Configuration

#define	SYSCFG_PMC_MII_RMII_SEL	(0x1u<<23)

// EXTICR1 Configuration

#define	SYSCFG_EXTICR1_EXTI0	(0xFu<<0)
#define	SYSCFG_EXTICR1_EXTI0_0	(0x1u<<0)
#define	SYSCFG_EXTICR1_EXTI1	(0xFu<<4)
#define	SYSCFG_EXTICR1_EXTI1_0	(0x1u<<4)
#define	SYSCFG_EXTICR1_EXTI2	(0xFu<<8)
#define	SYSCFG_EXTICR1_EXTI2_0	(0x1u<<8)
#define	SYSCFG_EXTICR1_EXTI3	(0xFu<<12)
#define	SYSCFG_EXTICR1_EXTI3_0	(0x1u<<12)

// EXTICR2 Configuration

#define	SYSCFG_EXTICR2_EXTI4	(0xFu<<0)
#define	SYSCFG_EXTICR2_EXTI4_0	(0x1u<<0)
#define	SYSCFG_EXTICR2_EXTI5	(0xFu<<4)
#define	SYSCFG_EXTICR2_EXTI5_0	(0x1u<<4)
#define	SYSCFG_EXTICR2_EXTI6	(0xFu<<8)
#define	SYSCFG_EXTICR2_EXTI6_0	(0x1u<<8)
#define	SYSCFG_EXTICR2_EXTI7	(0xFu<<12)
#define	SYSCFG_EXTICR2_EXTI7_0	(0x1u<<12)

// EXTICR3 Configuration

#define	SYSCFG_EXTICR3_EXTI8	(0xFu<<0)
#define	SYSCFG_EXTICR3_EXTI8_0	(0x1u<<0)
#define	SYSCFG_EXTICR3_EXTI9	(0xFu<<4)
#define	SYSCFG_EXTICR3_EXTI9_0	(0x1u<<4)
#define	SYSCFG_EXTICR3_EXTI10	(0xFu<<8)
#define	SYSCFG_EXTICR3_EXTI10_0	(0x1u<<8)
#define	SYSCFG_EXTICR3_EXTI11	(0xFu<<12)
#define	SYSCFG_EXTICR3_EXTI11_0	(0x1u<<12)

// EXTICR4 Configuration

#define	SYSCFG_EXTICR4_EXTI12	(0xFu<<0)
#define	SYSCFG_EXTICR4_EXTI12_0	(0x1u<<0)
#define	SYSCFG_EXTICR4_EXTI13	(0xFu<<4)
#define	SYSCFG_EXTICR4_EXTI13_0	(0x1u<<4)
#define	SYSCFG_EXTICR4_EXTI14	(0xFu<<8)
#define	SYSCFG_EXTICR4_EXTI14_0	(0x1u<<8)
#define	SYSCFG_EXTICR4_EXTI15	(0xFu<<12)
#define	SYSCFG_EXTICR4_EXTI15_0	(0x1u<<12)

// CMPCR Configuration

#define	SYSCFG_CMPCR_CMP_PD		(0x1u<<0)
#define	SYSCFG_CMPCR_READY		(0x1u<<7)
