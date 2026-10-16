/*
; stm32F217_dbg.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_dbg equates.
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

// DBG address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	DBGMCU_IDCODE;
	volatile	uint32_t	DBGMCU_CR;
	volatile	uint32_t	DBGMCU_APB1_FZ;
	volatile	uint32_t	DBGMCU_APB2_FZ;
} DBG_TypeDef;

#if (defined(__cplusplus))
#define	DBG	reinterpret_cast<DBG_TypeDef *>(0xE0042000u)

#else
#define	DBG	((DBG_TypeDef *)0xE0042000u)
#endif

// DBGMCU_IDCODE Configuration

#define	DBG_DBGMCU_IDCODE_REV_ID					(0xFFFFu<<16)
#define	DBG_DBGMCU_IDCODE_REV_ID_0					(0x1u<<16)
#define	DBG_DBGMCU_IDCODE_DEV_ID					(0xFFFu<<0)
#define	DBG_DBGMCU_IDCODE_DEV_ID_0					(0x1u<<0)

// DBGMCU_CR Configuration

#define	DBG_DBGMCU_CR_TRACE_MODE					(0x3u<<6)
#define	DBG_DBGMCU_CR_TRACE_MODE_0					(0x1u<<6)
#define	DBG_DBGMCU_CR_TRACE_IOEN					(0x1u<<5)
#define	DBG_DBGMCU_CR_DBG_STANDBY					(0x1u<<2)
#define	DBG_DBGMCU_CR_DBG_STOP						(0x1u<<1)
#define	DBG_DBGMCU_CR_DBG_SLEEP						(0x1u<<0)

// DBGMCU_APB1_FZ Configuration

#define	DBG_DBGMCU_APB1_FZ_DBG_CAN2_STOP			(0x1u<<26)
#define	DBG_DBGMCU_APB1_FZ_DBG_CAN1_STOP			(0x1u<<25)
#define	DBG_DBGMCU_APB1_FZ_DBG_J2C3SMBUS_TIMEOUT	(0x1u<<23)
#define	DBG_DBGMCU_APB1_FZ_DBG_J2C2_SMBUS_TIMEOUT	(0x1u<<22)
#define	DBG_DBGMCU_APB1_FZ_DBG_J2C1_SMBUS_TIMEOUT	(0x1u<<21)
#define	DBG_DBGMCU_APB1_FZ_DBG_IWDEG_STOP			(0x1u<<12)
#define	DBG_DBGMCU_APB1_FZ_DBG_WWDG_STOP			(0x1u<<11)
#define	DBG_DBGMCU_APB1_FZ_DBG_TIM14_STOP			(0x1u<<8)
#define	DBG_DBGMCU_APB1_FZ_DBG_TIM13_STOP			(0x1u<<7)
#define	DBG_DBGMCU_APB1_FZ_DBG_TIM12_STOP			(0x1u<<6)
#define	DBG_DBGMCU_APB1_FZ_DBG_TIM7_STOP			(0x1u<<5)
#define	DBG_DBGMCU_APB1_FZ_DBG_TIM6_STOP			(0x1u<<4)
#define	DBG_DBGMCU_APB1_FZ_DBG_TIM5_STOP			(0x1u<<3)
#define	DBG_DBGMCU_APB1_FZ_DBG_TIM4_STOP			(0x1u<<2)
#define	DBG_DBGMCU_APB1_FZ_DBG_TIM3_STOP			(0x1u<<1)
#define	DBG_DBGMCU_APB1_FZ_DBG_TIM2_STOP			(0x1u<<0)

// DBGMCU_APB2_FZ Configuration

#define	DBG_DBGMCU_APB2_FZ_DBG_TIM11_STOP			(0x1u<<18)
#define	DBG_DBGMCU_APB2_FZ_DBG_TIM10_STOP			(0x1u<<17)
#define	DBG_DBGMCU_APB2_FZ_DBG_TIM9_STOP			(0x1u<<16)
#define	DBG_DBGMCU_APB2_FZ_DBG_TIM8_STOP			(0x1u<<1)
#define	DBG_DBGMCU_APB2_FZ_DBG_TIM1_STOP			(0x1u<<0)
