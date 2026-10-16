/*
; stm32U5Gx_syscfg.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_syscfg equates.
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
	volatile	uint32_t	SECCFGR;
	volatile	uint32_t	CFGR1;
	volatile	uint32_t	FPUIMR;
	volatile	uint32_t	CNSLCKR;
	volatile	uint32_t	CSLOCKR;
	volatile	uint32_t	CFGR2;
	volatile	uint32_t	MESR;
	volatile	uint32_t	CCCSR;
	volatile	uint32_t	CCVR;
	volatile	uint32_t	CCCR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	RSSCMDR;
	volatile	uint32_t	RESERVED1[17];
	volatile	uint32_t	OTGHSPHYCR;
} SYSCFG_TypeDef;

#if (defined(__cplusplus))
#define	SYSCFG_NS	reinterpret_cast<SYSCFG_TypeDef *>(0x46000400u)
#define	SYSCFG_S	reinterpret_cast<SYSCFG_TypeDef *>(0x56000400u)

#else
#define	SYSCFG_NS	((SYSCFG_TypeDef *)0x46000400u)
#define	SYSCFG_S	((SYSCFG_TypeDef *)0x56000400u)
#endif

// SECCFGR Configuration

#define	SYSCFG_SECCFGR_FPUSEC		(0x1u<<3)
#define	SYSCFG_SECCFGR_CLASSBSEC	(0x1u<<1)
#define	SYSCFG_SECCFGR_SYSCFGSEC	(0x1u<<0)

// CFGR1 Configuration

#define	SYSCFG_CFGR1_BOOSTEN		(0x1u<<8)
#define	SYSCFG_CFGR1_ANASWVDD		(0x1u<<9)
#define	SYSCFG_CFGR1_PB6_FMP		(0x1u<<16)
#define	SYSCFG_CFGR1_PB7_FMP		(0x1u<<17)
#define	SYSCFG_CFGR1_PB8_FMP		(0x1u<<18)
#define	SYSCFG_CFGR1_PB9_FMP		(0x1u<<19)
#define	SYSCFG_CFGR1_ENDCAP			(0x3u<<24)
#define	SYSCFG_CFGR1_ENDCAP_0		(0x1u<<24)

// FPUIMR Configuration

#define	SYSCFG_FPUIMR_FPU_IE		(0x3Fu<<0)
#define	SYSCFG_FPUIMR_FPU_IE_0		(0x1u<<0)

// CNSLCKR Configuration

#define	SYSCFG_CNSLCKR_LOCKNSMPU	(0x1u<<1)
#define	SYSCFG_CNSLCKR_LOCKNSVTOR	(0x1u<<0)

// CSLOCKR Configuration

#define	SYSCFG_CSLOCKR_LOCKSAU		(0x1u<<2)
#define	SYSCFG_CSLOCKR_LOCKSMPU		(0x1u<<1)
#define	SYSCFG_CSLOCKR_LOCKSVTAIRCR	(0x1u<<0)

// CFGR2 Configuration

#define	SYSCFG_CFGR2_CLL			(0x1u<<0)
#define	SYSCFG_CFGR2_SPL			(0x1u<<1)
#define	SYSCFG_CFGR2_PVDL			(0x1u<<2)
#define	SYSCFG_CFGR2_ECCL			(0x1u<<3)

// MESR Configuration

#define	SYSCFG_MESR_MCLR			(0x1u<<0)
#define	SYSCFG_MESR_IPMEE			(0x1u<<16)

// CCCSR Configuration

#define	SYSCFG_CCCSR_RDY3			(0x1u<<10)
#define	SYSCFG_CCCSR_RDY2			(0x1u<<9)
#define	SYSCFG_CCCSR_RDY1			(0x1u<<8)
#define	SYSCFG_CCCSR_CS3			(0x1u<<5)
#define	SYSCFG_CCCSR_EN3			(0x1u<<4)
#define	SYSCFG_CCCSR_CS2			(0x1u<<3)
#define	SYSCFG_CCCSR_EN2			(0x1u<<2)
#define	SYSCFG_CCCSR_CS1			(0x1u<<1)
#define	SYSCFG_CCCSR_EN1			(0x1u<<0)

// CCVR Configuration

#define	SYSCFG_CCVR_PCV3			(0xFu<<20)
#define	SYSCFG_CCVR_PCV3_0			(0x1u<<20)
#define	SYSCFG_CCVR_NCV3			(0xFu<<16)
#define	SYSCFG_CCVR_NCV3_0			(0x1u<<16)
#define	SYSCFG_CCVR_PCV2			(0xFu<<12)
#define	SYSCFG_CCVR_PCV2_0			(0x1u<<12)
#define	SYSCFG_CCVR_NCV2			(0xFu<<8)
#define	SYSCFG_CCVR_NCV2_0			(0x1u<<8)
#define	SYSCFG_CCVR_PCV1			(0xFu<<4)
#define	SYSCFG_CCVR_PCV1_0			(0x1u<<4)
#define	SYSCFG_CCVR_NCV1			(0xFu<<0)
#define	SYSCFG_CCVR_NCV1_0			(0x1u<<0)

// CCCR Configuration

#define	SYSCFG_CCCR_PCC3			(0xFu<<20)
#define	SYSCFG_CCCR_PCC3_0			(0x1u<<20)
#define	SYSCFG_CCCR_NCC3			(0xFu<<16)
#define	SYSCFG_CCCR_NCC3_0			(0x1u<<16)
#define	SYSCFG_CCCR_PCC2			(0xFu<<12)
#define	SYSCFG_CCCR_PCC2_0			(0x1u<<12)
#define	SYSCFG_CCCR_NCC2			(0xFu<<8)
#define	SYSCFG_CCCR_NCC2_0			(0x1u<<8)
#define	SYSCFG_CCCR_PCC1			(0xFu<<4)
#define	SYSCFG_CCCR_PCC1_0			(0x1u<<4)
#define	SYSCFG_CCCR_NCC1			(0xFu<<0)
#define	SYSCFG_CCCR_NCC1_0			(0x1u<<0)

// RSSCMDR Configuration

#define	SYSCFG_RSSCMDR_RSSCMD		(0xFFFFu<<0)
#define	SYSCFG_RSSCMDR_RSSCMD_0		(0x1u<<0)

// OTGHSPHYCR Configuration

#define	SYSCFG_OTGHSPHYCR_CLKSEL	(0xFu<<2)
#define	SYSCFG_OTGHSPHYCR_CLKSEL_0	(0x1u<<2)
#define	SYSCFG_OTGHSPHYCR_PDCTRL	(0x1u<<1)
#define	SYSCFG_OTGHSPHYCR_EN		(0x1u<<0)
