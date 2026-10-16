/*
; stm32L4R5_syscfg.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_syscfg equates.
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
	volatile	uint32_t	MEMRMP;
	volatile	uint32_t	CFGR1;
	volatile	uint32_t	EXTICR1;
	volatile	uint32_t	EXTICR2;
	volatile	uint32_t	EXTICR3;
	volatile	uint32_t	EXTICR4;
	volatile	uint32_t	SCSR;
	volatile	uint32_t	CFGR2;
	volatile	uint32_t	SWPR;
	volatile	uint32_t	SKR;
} SYSCFG_TypeDef;

#if (defined(__cplusplus))
#define	SYSCFG	reinterpret_cast<SYSCFG_TypeDef *>(0x40010000u)

#else
#define	SYSCFG	((SYSCFG_TypeDef *)0x40010000u)
#endif

// MEMRMP Configuration

#define	SYSCFG_MEMRMP_MEM_MODE		(0x7u<<0)
#define	SYSCFG_MEMRMP_MEM_MODE_0	(0x1u<<0)
#define	SYSCFG_MEMRMP_QFS			(0x1u<<3)
#define	SYSCFG_MEMRMP_FB_MODE		(0x1u<<8)

// CFGR1 Configuration

#define	SYSCFG_CFGR1_FWDIS			(0x1u<<0)
#define	SYSCFG_CFGR1_BOOSTEN		(0x1u<<8)
#define	SYSCFG_CFGR1_I2C_PB6_FMP	(0x1u<<16)
#define	SYSCFG_CFGR1_I2C_PB7_FMP	(0x1u<<17)
#define	SYSCFG_CFGR1_I2C_PB8_FMP	(0x1u<<18)
#define	SYSCFG_CFGR1_I2C_PB9_FMP	(0x1u<<19)
#define	SYSCFG_CFGR1_I2C1_FMP		(0x1u<<20)
#define	SYSCFG_CFGR1_I2C2_FMP		(0x1u<<21)
#define	SYSCFG_CFGR1_I2C3_FMP		(0x1u<<22)
#define	SYSCFG_CFGR1_FPU_IE			(0x3Fu<<26)
#define	SYSCFG_CFGR1_FPU_IE_0		(0x1u<<26)

// EXTICR1 Configuration

#define	SYSCFG_EXTICR1_EXTI0		(0x7u<<0)
#define	SYSCFG_EXTICR1_EXTI0_0		(0x1u<<0)
#define	SYSCFG_EXTICR1_EXTI1		(0x7u<<4)
#define	SYSCFG_EXTICR1_EXTI1_0		(0x1u<<4)
#define	SYSCFG_EXTICR1_EXTI2		(0x7u<<8)
#define	SYSCFG_EXTICR1_EXTI2_0		(0x1u<<8)
#define	SYSCFG_EXTICR1_EXTI3		(0x7u<<12)
#define	SYSCFG_EXTICR1_EXTI3_0		(0x1u<<12)

// EXTICR2 Configuration

#define	SYSCFG_EXTICR2_EXTI4		(0x7u<<0)
#define	SYSCFG_EXTICR2_EXTI4_0		(0x1u<<0)
#define	SYSCFG_EXTICR2_EXTI5		(0x7u<<4)
#define	SYSCFG_EXTICR2_EXTI5_0		(0x1u<<4)
#define	SYSCFG_EXTICR2_EXTI6		(0x7u<<8)
#define	SYSCFG_EXTICR2_EXTI6_0		(0x1u<<8)
#define	SYSCFG_EXTICR2_EXTI7		(0x7u<<12)
#define	SYSCFG_EXTICR2_EXTI7_0		(0x1u<<12)

// EXTICR3 Configuration

#define	SYSCFG_EXTICR3_EXTI8		(0x7u<<0)
#define	SYSCFG_EXTICR3_EXTI8_0		(0x1u<<0)
#define	SYSCFG_EXTICR3_EXTI9		(0x7u<<4)
#define	SYSCFG_EXTICR3_EXTI9_0		(0x1u<<4)
#define	SYSCFG_EXTICR3_EXTI10		(0x7u<<8)
#define	SYSCFG_EXTICR3_EXTI10_0		(0x1u<<8)
#define	SYSCFG_EXTICR3_EXTI11		(0x7u<<12)
#define	SYSCFG_EXTICR3_EXTI11_0		(0x1u<<12)

// EXTICR4 Configuration

#define	SYSCFG_EXTICR4_EXTI12		(0x7u<<0)
#define	SYSCFG_EXTICR4_EXTI12_0		(0x1u<<0)
#define	SYSCFG_EXTICR4_EXTI13		(0x7u<<4)
#define	SYSCFG_EXTICR4_EXTI13_0		(0x1u<<4)
#define	SYSCFG_EXTICR4_EXTI14		(0x7u<<8)
#define	SYSCFG_EXTICR4_EXTI14_0		(0x1u<<8)
#define	SYSCFG_EXTICR4_EXTI15		(0x7u<<12)
#define	SYSCFG_EXTICR4_EXTI15_0		(0x1u<<12)

// SCSR Configuration

#define	SYSCFG_SCSR_SRAM2ER			(0x1u<<0)
#define	SYSCFG_SCSR_SRAM2BSY		(0x1u<<1)

// CFGR2 Configuration

#define	SYSCFG_CFGR2_CLL			(0x1u<<0)
#define	SYSCFG_CFGR2_SPL			(0x1u<<1)
#define	SYSCFG_CFGR2_PVDL			(0x1u<<2)
#define	SYSCFG_CFGR2_ECCL			(0x1u<<3)
#define	SYSCFG_CFGR2_SPF			(0x1u<<8)

// SWPR Configuration

#define	SYSCFG_SWPR_P0WP			(0x1u<<0)
#define	SYSCFG_SWPR_P1WP			(0x1u<<1)
#define	SYSCFG_SWPR_P2WP			(0x1u<<2)
#define	SYSCFG_SWPR_P3WP			(0x1u<<3)
#define	SYSCFG_SWPR_P4WP			(0x1u<<4)
#define	SYSCFG_SWPR_P5WP			(0x1u<<5)
#define	SYSCFG_SWPR_P6WP			(0x1u<<6)
#define	SYSCFG_SWPR_P7WP			(0x1u<<7)
#define	SYSCFG_SWPR_P8WP			(0x1u<<8)
#define	SYSCFG_SWPR_P9WP			(0x1u<<9)
#define	SYSCFG_SWPR_P10WP			(0x1u<<10)
#define	SYSCFG_SWPR_P11WP			(0x1u<<11)
#define	SYSCFG_SWPR_P12WP			(0x1u<<12)
#define	SYSCFG_SWPR_P13WP			(0x1u<<13)
#define	SYSCFG_SWPR_P14WP			(0x1u<<14)
#define	SYSCFG_SWPR_P15WP			(0x1u<<15)
#define	SYSCFG_SWPR_P16WP			(0x1u<<16)
#define	SYSCFG_SWPR_P17WP			(0x1u<<17)
#define	SYSCFG_SWPR_P18WP			(0x1u<<18)
#define	SYSCFG_SWPR_P19WP			(0x1u<<19)
#define	SYSCFG_SWPR_P20WP			(0x1u<<20)
#define	SYSCFG_SWPR_P21WP			(0x1u<<21)
#define	SYSCFG_SWPR_P22WP			(0x1u<<22)
#define	SYSCFG_SWPR_P23WP			(0x1u<<23)
#define	SYSCFG_SWPR_P24WP			(0x1u<<24)
#define	SYSCFG_SWPR_P25WP			(0x1u<<25)
#define	SYSCFG_SWPR_P26WP			(0x1u<<26)
#define	SYSCFG_SWPR_P27WP			(0x1u<<27)
#define	SYSCFG_SWPR_P28WP			(0x1u<<28)
#define	SYSCFG_SWPR_P29WP			(0x1u<<29)
#define	SYSCFG_SWPR_P30WP			(0x1u<<30)
#define	SYSCFG_SWPR_P31WP			(0x1u<<31)

// SKR Configuration

#define	SYSCFG_SKR_KEY				(0xFFu<<0)
#define	SYSCFG_SKR_KEY_0			(0x1u<<0)
