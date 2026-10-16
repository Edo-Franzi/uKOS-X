/*
; stm32H757_CM7_dbgmcu.
; =====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H757_CM7_dbgmcu equates.
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
	volatile	uint32_t	IDC;
	volatile	uint32_t	CR;
	volatile	uint32_t	RESERVED0[11];
	volatile	uint32_t	APB3FZ1;
	volatile	uint32_t	APB3FZ2;
	volatile	uint32_t	APB1LFZ1;
	volatile	uint32_t	APB1LFZ2;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	APB2FZ1;
	volatile	uint32_t	APB2FZ2;
	volatile	uint32_t	APB4FZ1;
	volatile	uint32_t	APB4FZ2;
} DBGMCU_TypeDef;

#if (defined(__cplusplus))
#define	DBGMCU	reinterpret_cast<DBGMCU_TypeDef *>(0x5C001000u)

#else
#define	DBGMCU	((DBGMCU_TypeDef *)0x5C001000u)
#endif

// IDC Configuration

#define	DBGMCU_IDC_REV_ID			(0xFFFFu<<16)
#define	DBGMCU_IDC_REV_ID_0			(0x1u<<16)
#define	DBGMCU_IDC_DEV_ID			(0xFFFu<<0)
#define	DBGMCU_IDC_DEV_ID_0			(0x1u<<0)

// CR Configuration

#define	DBGMCU_CR_TRGOEN			(0x1u<<28)
#define	DBGMCU_CR_D3DBGCKEN			(0x1u<<22)
#define	DBGMCU_CR_D1DBGCKEN			(0x1u<<21)
#define	DBGMCU_CR_TRACECLKEN		(0x1u<<20)
#define	DBGMCU_CR_DBGSTBD3			(0x1u<<8)
#define	DBGMCU_CR_DBGSTPD3			(0x1u<<7)
#define	DBGMCU_CR_DBGSTBD2			(0x1u<<5)
#define	DBGMCU_CR_DBGSTPD2			(0x1u<<4)
#define	DBGMCU_CR_DBGSLPD2			(0x1u<<3)
#define	DBGMCU_CR_DBGSTBD1			(0x1u<<2)
#define	DBGMCU_CR_DBGSTPD1			(0x1u<<1)
#define	DBGMCU_CR_DBGSLPD1			(0x1u<<0)

// APB3FZ1 Configuration

#define	DBGMCU_APB3FZ1_WWDG1		(0x1u<<6)

// APB3FZ2 Configuration

#define	DBGMCU_APB3FZ2_WWDG1		(0x1u<<6)

// APB1LFZ1 Configuration

#define	DBGMCU_APB1LFZ1_DBG_I2C3	(0x1u<<23)
#define	DBGMCU_APB1LFZ1_DBG_I2C2	(0x1u<<22)
#define	DBGMCU_APB1LFZ1_DBG_I2C1	(0x1u<<21)
#define	DBGMCU_APB1LFZ1_DBG_WWDG2	(0x1u<<11)
#define	DBGMCU_APB1LFZ1_DBG_LPTIM1	(0x1u<<9)
#define	DBGMCU_APB1LFZ1_DBG_TIM14	(0x1u<<8)
#define	DBGMCU_APB1LFZ1_DBG_TIM13	(0x1u<<7)
#define	DBGMCU_APB1LFZ1_DBG_TIM12	(0x1u<<6)
#define	DBGMCU_APB1LFZ1_DBG_TIM7	(0x1u<<5)
#define	DBGMCU_APB1LFZ1_DBG_TIM6	(0x1u<<4)
#define	DBGMCU_APB1LFZ1_DBG_TIM5	(0x1u<<3)
#define	DBGMCU_APB1LFZ1_DBG_TIM4	(0x1u<<2)
#define	DBGMCU_APB1LFZ1_DBG_TIM3	(0x1u<<1)
#define	DBGMCU_APB1LFZ1_DBG_TIM2	(0x1u<<0)

// APB1LFZ2 Configuration

#define	DBGMCU_APB1LFZ2_DBG_I2C3	(0x1u<<23)
#define	DBGMCU_APB1LFZ2_DBG_I2C2	(0x1u<<22)
#define	DBGMCU_APB1LFZ2_DBG_I2C1	(0x1u<<21)
#define	DBGMCU_APB1LFZ2_DBG_WWDG2	(0x1u<<11)
#define	DBGMCU_APB1LFZ2_DBG_LPTIM1	(0x1u<<9)
#define	DBGMCU_APB1LFZ2_DBG_TIM14	(0x1u<<8)
#define	DBGMCU_APB1LFZ2_DBG_TIM13	(0x1u<<7)
#define	DBGMCU_APB1LFZ2_DBG_TIM12	(0x1u<<6)
#define	DBGMCU_APB1LFZ2_DBG_TIM7	(0x1u<<5)
#define	DBGMCU_APB1LFZ2_DBG_TIM6	(0x1u<<4)
#define	DBGMCU_APB1LFZ2_DBG_TIM5	(0x1u<<3)
#define	DBGMCU_APB1LFZ2_DBG_TIM4	(0x1u<<2)
#define	DBGMCU_APB1LFZ2_DBG_TIM3	(0x1u<<1)
#define	DBGMCU_APB1LFZ2_DBG_TIM2	(0x1u<<0)

// APB2FZ1 Configuration

#define	DBGMCU_APB2FZ1_DBG_HRTIM	(0x1u<<29)
#define	DBGMCU_APB2FZ1_DBG_TIM17	(0x1u<<18)
#define	DBGMCU_APB2FZ1_DBG_TIM16	(0x1u<<17)
#define	DBGMCU_APB2FZ1_DBG_TIM15	(0x1u<<16)
#define	DBGMCU_APB2FZ1_DBG_TIM8		(0x1u<<1)
#define	DBGMCU_APB2FZ1_DBG_TIM1		(0x1u<<0)

// APB2FZ2 Configuration

#define	DBGMCU_APB2FZ2_DBG_HRTIM	(0x1u<<29)
#define	DBGMCU_APB2FZ2_DBG_TIM17	(0x1u<<18)
#define	DBGMCU_APB2FZ2_DBG_TIM16	(0x1u<<17)
#define	DBGMCU_APB2FZ2_DBG_TIM15	(0x1u<<16)
#define	DBGMCU_APB2FZ2_DBG_TIM8		(0x1u<<1)
#define	DBGMCU_APB2FZ2_DBG_TIM1		(0x1u<<0)

// APB4FZ1 Configuration

#define	DBGMCU_APB4FZ1_DBG_WDGLSD2	(0x1u<<19)
#define	DBGMCU_APB4FZ1_DBG_WDGLSD1	(0x1u<<18)
#define	DBGMCU_APB4FZ1_DBG_RTC		(0x1u<<16)
#define	DBGMCU_APB4FZ1_DBG_LPTIM5	(0x1u<<12)
#define	DBGMCU_APB4FZ1_DBG_LPTIM4	(0x1u<<11)
#define	DBGMCU_APB4FZ1_DBG_LPTIM3	(0x1u<<10)
#define	DBGMCU_APB4FZ1_DBG_LPTIM2	(0x1u<<9)
#define	DBGMCU_APB4FZ1_DBG_I2C4		(0x1u<<7)

// APB4FZ2 Configuration

#define	DBGMCU_APB4FZ2_DBG_WDGLSD2	(0x1u<<19)
#define	DBGMCU_APB4FZ2_DBG_WDGLSD1	(0x1u<<18)
#define	DBGMCU_APB4FZ2_DBG_RTC		(0x1u<<16)
#define	DBGMCU_APB4FZ2_DBG_LPTIM5	(0x1u<<12)
#define	DBGMCU_APB4FZ2_DBG_LPTIM4	(0x1u<<11)
#define	DBGMCU_APB4FZ2_DBG_LPTIM3	(0x1u<<10)
#define	DBGMCU_APB4FZ2_DBG_LPTIM2	(0x1u<<9)
#define	DBGMCU_APB4FZ2_DBG_I2C4		(0x1u<<7)
