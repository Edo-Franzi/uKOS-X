/*
; stm32L4R5_dbgmcu.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_dbgmcu equates.
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

// DBGMCU address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	IDCODE;
	volatile	uint32_t	CR;
	volatile	uint32_t	APB1_FZR1;
	volatile	uint32_t	APB1_FZR2;
	volatile	uint32_t	APB2_FZR;
} DBGMCU_TypeDef;

#if (defined(__cplusplus))
#define	DBGMCU	reinterpret_cast<DBGMCU_TypeDef *>(0xE0042000u)

#else
#define	DBGMCU	((DBGMCU_TypeDef *)0xE0042000u)
#endif

// IDCODE Configuration

#define	DBGMCU_IDCODE_REV_ID				(0xFFFFu<<16)
#define	DBGMCU_IDCODE_REV_ID_0				(0x1u<<16)
#define	DBGMCU_IDCODE_DEV_ID				(0xFFFFu<<0)
#define	DBGMCU_IDCODE_DEV_ID_0				(0x1u<<0)

// CR Configuration

#define	DBGMCU_CR_TRACE_MODE				(0x3u<<6)
#define	DBGMCU_CR_TRACE_MODE_0				(0x1u<<6)
#define	DBGMCU_CR_TRACE_IOEN				(0x1u<<5)
#define	DBGMCU_CR_DBG_STANDBY				(0x1u<<2)
#define	DBGMCU_CR_DBG_STOP					(0x1u<<1)
#define	DBGMCU_CR_DBG_SLEEP					(0x1u<<0)

// APB1_FZR1 Configuration

#define	DBGMCU_APB1_FZR1_DBG_LPTIMER_STOP	(0x1u<<31)
#define	DBGMCU_APB1_FZR1_DBG_CAN_STOP		(0x1u<<25)
#define	DBGMCU_APB1_FZR1_DBG_I2C3_STOP		(0x1u<<23)
#define	DBGMCU_APB1_FZR1_DBG_I2C2_STOP		(0x1u<<22)
#define	DBGMCU_APB1_FZR1_DBG_I2C1_STOP		(0x1u<<21)
#define	DBGMCU_APB1_FZR1_DBG_IWDG_STOP		(0x1u<<12)
#define	DBGMCU_APB1_FZR1_DBG_WWDG_STOP		(0x1u<<11)
#define	DBGMCU_APB1_FZR1_DBG_RTC_STOP		(0x1u<<10)
#define	DBGMCU_APB1_FZR1_DBG_TIM7_STOP		(0x1u<<5)
#define	DBGMCU_APB1_FZR1_DBG_TIMER6_STOP	(0x1u<<4)
#define	DBGMCU_APB1_FZR1_DBG_TIM5_STOP		(0x1u<<3)
#define	DBGMCU_APB1_FZR1_DBG_TIM4_STOP		(0x1u<<2)
#define	DBGMCU_APB1_FZR1_DBG_TIM3_STOP		(0x1u<<1)
#define	DBGMCU_APB1_FZR1_DBG_TIMER2_STOP	(0x1u<<0)

// APB1_FZR2 Configuration

#define	DBGMCU_APB1_FZR2_DBG_LPTIM2_STOP	(0x1u<<5)

// APB2_FZR Configuration

#define	DBGMCU_APB2_FZR_DBG_TIM17_STOP		(0x1u<<18)
#define	DBGMCU_APB2_FZR_DBG_TIM16_STOP		(0x1u<<17)
#define	DBGMCU_APB2_FZR_DBG_TIM15_STOP		(0x1u<<16)
#define	DBGMCU_APB2_FZR_DBG_TIM8_STOP		(0x1u<<13)
#define	DBGMCU_APB2_FZR_DBG_TIM1_STOP		(0x1u<<11)
