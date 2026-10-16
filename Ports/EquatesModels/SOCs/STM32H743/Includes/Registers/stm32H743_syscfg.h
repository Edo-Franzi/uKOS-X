/*
; stm32H743_syscfg.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H743_syscfg equates.
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
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	PMCR;
	volatile	uint32_t	EXTICR1;
	volatile	uint32_t	EXTICR2;
	volatile	uint32_t	EXTICR3;
	volatile	uint32_t	EXTICR4;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	CCCSR;
	volatile	uint32_t	CCVR;
	volatile	uint32_t	CCCR;
	volatile	uint32_t	PWRCR;
	volatile	uint32_t	RESERVED2[61];
	volatile	uint32_t	PKGR;
	volatile	uint32_t	RESERVED3[118];
	volatile	uint32_t	UR0;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	UR2;
	volatile	uint32_t	UR3;
	volatile	uint32_t	UR4;
	volatile	uint32_t	UR5;
	volatile	uint32_t	UR6;
	volatile	uint32_t	UR7;
	volatile	uint32_t	UR8;
	volatile	uint32_t	UR9;
	volatile	uint32_t	UR10;
	volatile	uint32_t	UR11;
	volatile	uint32_t	UR12;
	volatile	uint32_t	UR13;
	volatile	uint32_t	UR14;
	volatile	uint32_t	UR15;
	volatile	uint32_t	UR16;
	volatile	uint32_t	UR17;
} SYSCFG_TypeDef;

#if (defined(__cplusplus))
#define	SYSCFG	reinterpret_cast<SYSCFG_TypeDef *>(0x58000400u)

#else
#define	SYSCFG	((SYSCFG_TypeDef *)0x58000400u)
#endif

// PMCR Configuration

#define	SYSCFG_PMCR_PC3SO		(0x1u<<27)
#define	SYSCFG_PMCR_PC2SO		(0x1u<<26)
#define	SYSCFG_PMCR_PA1SO		(0x1u<<25)
#define	SYSCFG_PMCR_PA0SO		(0x1u<<24)
#define	SYSCFG_PMCR_EPIS		(0x7u<<21)
#define	SYSCFG_PMCR_EPIS_0		(0x1u<<21)
#define	SYSCFG_PMCR_BOOSTVDDSEL	(0x1u<<9)
#define	SYSCFG_PMCR_BOOSTE		(0x1u<<8)
#define	SYSCFG_PMCR_PB9FMP		(0x1u<<7)
#define	SYSCFG_PMCR_PB8FMP		(0x1u<<6)
#define	SYSCFG_PMCR_PB7FMP		(0x1u<<5)
#define	SYSCFG_PMCR_PB6FMP		(0x1u<<4)
#define	SYSCFG_PMCR_I2C4FMP		(0x1u<<3)
#define	SYSCFG_PMCR_I2C3FMP		(0x1u<<2)
#define	SYSCFG_PMCR_I2C2FMP		(0x1u<<1)
#define	SYSCFG_PMCR_I2C1FMP		(0x1u<<0)

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

// CCCSR Configuration

#define	SYSCFG_CCCSR_HSLV		(0x1u<<16)
#define	SYSCFG_CCCSR_READY		(0x1u<<8)
#define	SYSCFG_CCCSR_CS			(0x1u<<1)
#define	SYSCFG_CCCSR_EN			(0x1u<<0)

// CCVR Configuration

#define	SYSCFG_CCVR_PCV			(0xFu<<4)
#define	SYSCFG_CCVR_PCV_0		(0x1u<<4)
#define	SYSCFG_CCVR_NCV			(0xFu<<0)
#define	SYSCFG_CCVR_NCV_0		(0x1u<<0)

// CCCR Configuration

#define	SYSCFG_CCCR_PCC			(0xFu<<4)
#define	SYSCFG_CCCR_PCC_0		(0x1u<<4)
#define	SYSCFG_CCCR_NCC			(0xFu<<0)
#define	SYSCFG_CCCR_NCC_0		(0x1u<<0)

// PWRCR Configuration

#define	SYSCFG_PWRCR_ODEN		(0xFu<<0)
#define	SYSCFG_PWRCR_ODEN_0		(0x1u<<0)

// PKGR Configuration

#define	SYSCFG_PKGR_PKG			(0xFu<<0)
#define	SYSCFG_PKGR_PKG_0		(0x1u<<0)

// UR0 Configuration

#define	SYSCFG_UR0_RDP			(0xFFu<<16)
#define	SYSCFG_UR0_RDP_0		(0x1u<<16)
#define	SYSCFG_UR0_BKS			(0x1u<<0)

// UR2 Configuration

#define	SYSCFG_UR2_BOOT_ADD0	(0xFFFFu<<16)
#define	SYSCFG_UR2_BOOT_ADD0_0	(0x1u<<16)
#define	SYSCFG_UR2_BORH			(0x3u<<0)
#define	SYSCFG_UR2_BORH_0		(0x1u<<0)

// UR3 Configuration

#define	SYSCFG_UR3_BOOT_ADD1	(0xFFFFu<<16)
#define	SYSCFG_UR3_BOOT_ADD1_0	(0x1u<<16)

// UR4 Configuration

#define	SYSCFG_UR4_MEPAD_1		(0x1u<<16)

// UR5 Configuration

#define	SYSCFG_UR5_WRPN_1		(0xFFu<<16)
#define	SYSCFG_UR5_WRPN_1_0		(0x1u<<16)
#define	SYSCFG_UR5_MESAD_1		(0x1u<<0)

// UR6 Configuration

#define	SYSCFG_UR6_PA_END_1		(0xFFFu<<16)
#define	SYSCFG_UR6_PA_END_1_0	(0x1u<<16)
#define	SYSCFG_UR6_PA_BEG_1		(0xFFFu<<0)
#define	SYSCFG_UR6_PA_BEG_1_0	(0x1u<<0)

// UR7 Configuration

#define	SYSCFG_UR7_SA_END_1		(0xFFFu<<16)
#define	SYSCFG_UR7_SA_END_1_0	(0x1u<<16)
#define	SYSCFG_UR7_SA_BEG_1		(0xFFFu<<0)
#define	SYSCFG_UR7_SA_BEG_1_0	(0x1u<<0)

// UR8 Configuration

#define	SYSCFG_UR8_MESAD_2		(0x1u<<16)
#define	SYSCFG_UR8_MEPAD_2		(0x1u<<0)

// UR9 Configuration

#define	SYSCFG_UR9_PA_BEG_2		(0xFFFu<<16)
#define	SYSCFG_UR9_PA_BEG_2_0	(0x1u<<16)
#define	SYSCFG_UR9_WRPN_2		(0xFFu<<0)
#define	SYSCFG_UR9_WRPN_2_0		(0x1u<<0)

// UR10 Configuration

#define	SYSCFG_UR10_SA_BEG_2	(0xFFFu<<16)
#define	SYSCFG_UR10_SA_BEG_2_0	(0x1u<<16)
#define	SYSCFG_UR10_PA_END_2	(0xFFFu<<0)
#define	SYSCFG_UR10_PA_END_2_0	(0x1u<<0)

// UR11 Configuration

#define	SYSCFG_UR11_IWDG1M		(0x1u<<16)
#define	SYSCFG_UR11_SA_END_2	(0xFFFu<<0)
#define	SYSCFG_UR11_SA_END_2_0	(0x1u<<0)

// UR12 Configuration

#define	SYSCFG_UR12_SECURE		(0x1u<<16)

// UR13 Configuration

#define	SYSCFG_UR13_D1SBRST		(0x1u<<16)
#define	SYSCFG_UR13_SDRS		(0x3u<<0)
#define	SYSCFG_UR13_SDRS_0		(0x1u<<0)

// UR14 Configuration

#define	SYSCFG_UR14_D1STPRST	(0x1u<<0)

// UR15 Configuration

#define	SYSCFG_UR15_FZIWDGSTB	(0x1u<<16)

// UR16 Configuration

#define	SYSCFG_UR16_PKP			(0x1u<<16)
#define	SYSCFG_UR16_FZIWDGSTP	(0x1u<<0)

// UR17 Configuration

#define	SYSCFG_UR17_IO_HSLV		(0x1u<<0)
