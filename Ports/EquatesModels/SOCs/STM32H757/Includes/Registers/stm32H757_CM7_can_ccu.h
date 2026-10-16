/*
; stm32H757_CM7_can_ccu.
; ======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H757_CM7_can_ccu equates.
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

// CAN_CCU address definitions
// ---------------------------

typedef struct {
	volatile	uint32_t	CREL;
	volatile	uint32_t	CCFG;
	volatile	uint32_t	CSTAT;
	volatile	uint32_t	CWD;
	volatile	uint32_t	IR;
	volatile	uint32_t	IE;
} CAN_CCU_TypeDef;

#if (defined(__cplusplus))
#define	CAN_CCU	reinterpret_cast<CAN_CCU_TypeDef *>(0x4000A800u)

#else
#define	CAN_CCU	((CAN_CCU_TypeDef *)0x4000A800u)
#endif

// CREL Configuration

#define	CAN_CCU_CREL_REL		(0xFu<<28)
#define	CAN_CCU_CREL_REL_0		(0x1u<<28)
#define	CAN_CCU_CREL_STEP		(0xFu<<24)
#define	CAN_CCU_CREL_STEP_0		(0x1u<<24)
#define	CAN_CCU_CREL_SUBSTEP	(0xFu<<20)
#define	CAN_CCU_CREL_SUBSTEP_0	(0x1u<<20)
#define	CAN_CCU_CREL_YEAR		(0xFu<<16)
#define	CAN_CCU_CREL_YEAR_0		(0x1u<<16)
#define	CAN_CCU_CREL_MON		(0xFFu<<8)
#define	CAN_CCU_CREL_MON_0		(0x1u<<8)
#define	CAN_CCU_CREL_DAY		(0xFFu<<0)
#define	CAN_CCU_CREL_DAY_0		(0x1u<<0)

// CCFG Configuration

#define	CAN_CCU_CCFG_SWR		(0x1u<<31)
#define	CAN_CCU_CCFG_CDIV		(0xFu<<16)
#define	CAN_CCU_CCFG_CDIV_0		(0x1u<<16)
#define	CAN_CCU_CCFG_OCPM		(0xFFu<<8)
#define	CAN_CCU_CCFG_OCPM_0		(0x1u<<8)
#define	CAN_CCU_CCFG_CFL		(0x1u<<7)
#define	CAN_CCU_CCFG_BCC		(0x1u<<6)
#define	CAN_CCU_CCFG_TQBT		(0x1Fu<<0)
#define	CAN_CCU_CCFG_TQBT_0		(0x1u<<0)

// CSTAT Configuration

#define	CAN_CCU_CSTAT_CALS		(0x3u<<30)
#define	CAN_CCU_CSTAT_CALS_0	(0x1u<<30)
#define	CAN_CCU_CSTAT_TQC		(0x7FFu<<18)
#define	CAN_CCU_CSTAT_TQC_0		(0x1u<<18)
#define	CAN_CCU_CSTAT_OCPC		(0x3FFFFu<<0)
#define	CAN_CCU_CSTAT_OCPC_0	(0x1u<<0)

// CWD Configuration

#define	CAN_CCU_CWD_WDV			(0xFFFFu<<16)
#define	CAN_CCU_CWD_WDV_0		(0x1u<<16)
#define	CAN_CCU_CWD_WDC			(0xFFFFu<<0)
#define	CAN_CCU_CWD_WDC_0		(0x1u<<0)

// IR Configuration

#define	CAN_CCU_IR_CSC			(0x1u<<1)
#define	CAN_CCU_IR_CWE			(0x1u<<0)

// IE Configuration

#define	CAN_CCU_IE_CSCE			(0x1u<<1)
#define	CAN_CCU_IE_CWEE			(0x1u<<0)
