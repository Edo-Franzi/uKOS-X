/*
; stm32U5Gx_dbgmcu.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_dbgmcu equates.
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
	volatile	uint32_t	APB1LFZR;
	volatile	uint32_t	APB1HFZR;
	volatile	uint32_t	APB2FZR;
	volatile	uint32_t	APB3FZR;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	AHB1FZR;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	AHB3FZR;
	volatile	uint32_t	RESERVED2[52];
	volatile	uint32_t	SR;
	volatile	uint32_t	DBG_AUTH_HOST;
	volatile	uint32_t	DBG_AUTH_DEVICE;
	volatile	uint32_t	RESERVED3[946];
	volatile	uint32_t	PIDR4;
	volatile	uint32_t	RESERVED4[3];
	volatile	uint32_t	PIDR0;
	volatile	uint32_t	PIDR1;
	volatile	uint32_t	PIDR2;
	volatile	uint32_t	PIDR3;
	volatile	uint32_t	CIDR0;
	volatile	uint32_t	CIDR1;
	volatile	uint32_t	CIDR2;
	volatile	uint32_t	CIDR3;
} DBGMCU_TypeDef;

#if (defined(__cplusplus))
#define	DBGMCU_NS	reinterpret_cast<DBGMCU_TypeDef *>(0xE0044000u)

#else
#define	DBGMCU_NS	((DBGMCU_TypeDef *)0xE0044000u)
#endif

// IDCODE Configuration

#define	DBGMCU_IDCODE_REV_ID				(0xFFFFu<<16)
#define	DBGMCU_IDCODE_REV_ID_0				(0x1u<<16)
#define	DBGMCU_IDCODE_DEV_ID				(0xFFFu<<0)
#define	DBGMCU_IDCODE_DEV_ID_0				(0x1u<<0)

// CR Configuration

#define	DBGMCU_CR_TRACE_MODE				(0x3u<<6)
#define	DBGMCU_CR_TRACE_MODE_0				(0x1u<<6)
#define	DBGMCU_CR_TRACE_EN					(0x1u<<5)
#define	DBGMCU_CR_TRACE_IOEN				(0x1u<<4)
#define	DBGMCU_CR_DBG_STANDBY				(0x1u<<2)
#define	DBGMCU_CR_DBG_STOP					(0x1u<<1)

// APB1LFZR Configuration

#define	DBGMCU_APB1LFZR_DBG_I2C2_STOP		(0x1u<<22)
#define	DBGMCU_APB1LFZR_DBG_I2C1_STOP		(0x1u<<21)
#define	DBGMCU_APB1LFZR_DBG_IWDG_STOP		(0x1u<<12)
#define	DBGMCU_APB1LFZR_DBG_WWDG_STOP		(0x1u<<11)
#define	DBGMCU_APB1LFZR_DBG_TIM7_STOP		(0x1u<<5)
#define	DBGMCU_APB1LFZR_DBG_TIM6_STOP		(0x1u<<4)
#define	DBGMCU_APB1LFZR_DBG_TIM5_STOP		(0x1u<<3)
#define	DBGMCU_APB1LFZR_DBG_TIM4_STOP		(0x1u<<2)
#define	DBGMCU_APB1LFZR_DBG_TIM3_STOP		(0x1u<<1)
#define	DBGMCU_APB1LFZR_DBG_TIM2_STOP		(0x1u<<0)

// APB1HFZR Configuration

#define	DBGMCU_APB1HFZR_DBG_LPTIM2_STOP		(0x1u<<5)
#define	DBGMCU_APB1HFZR_DBG_I2C4_STOP		(0x1u<<1)

// APB2FZR Configuration

#define	DBGMCU_APB2FZR_DBG_TIM17_STOP		(0x1u<<18)
#define	DBGMCU_APB2FZR_DBG_TIM16_STOP		(0x1u<<17)
#define	DBGMCU_APB2FZR_DBG_TIM15_STOP		(0x1u<<16)
#define	DBGMCU_APB2FZR_DBG_TIM8_STOP		(0x1u<<13)
#define	DBGMCU_APB2FZR_DBG_TIM1_STOP		(0x1u<<11)

// APB3FZR Configuration

#define	DBGMCU_APB3FZR_DBG_RTC_STOP			(0x1u<<30)
#define	DBGMCU_APB3FZR_DBG_LPTIM4_STOP		(0x1u<<19)
#define	DBGMCU_APB3FZR_DBG_LPTIM3_STOP		(0x1u<<18)
#define	DBGMCU_APB3FZR_DBG_LPTIM1_STOP		(0x1u<<17)
#define	DBGMCU_APB3FZR_DBG_I2C3_STOP		(0x1u<<10)

// AHB1FZR Configuration

#define	DBGMCU_AHB1FZR_DBG_GPDMA15_STOP		(0x1u<<15)
#define	DBGMCU_AHB1FZR_DBG_GPDMA14_STOP		(0x1u<<14)
#define	DBGMCU_AHB1FZR_DBG_GPDMA13_STOP		(0x1u<<13)
#define	DBGMCU_AHB1FZR_DBG_GPDMA12_STOP		(0x1u<<12)
#define	DBGMCU_AHB1FZR_DBG_GPDMA11_STOP		(0x1u<<11)
#define	DBGMCU_AHB1FZR_DBG_GPDMA10_STOP		(0x1u<<10)
#define	DBGMCU_AHB1FZR_DBG_GPDMA9_STOP		(0x1u<<9)
#define	DBGMCU_AHB1FZR_DBG_GPDMA8_STOP		(0x1u<<8)
#define	DBGMCU_AHB1FZR_DBG_GPDMA7_STOP		(0x1u<<7)
#define	DBGMCU_AHB1FZR_DBG_GPDMA6_STOP		(0x1u<<6)
#define	DBGMCU_AHB1FZR_DBG_GPDMA5_STOP		(0x1u<<5)
#define	DBGMCU_AHB1FZR_DBG_GPDMA4_STOP		(0x1u<<4)
#define	DBGMCU_AHB1FZR_DBG_GPDMA3_STOP		(0x1u<<3)
#define	DBGMCU_AHB1FZR_DBG_GPDMA2_STOP		(0x1u<<2)
#define	DBGMCU_AHB1FZR_DBG_GPDMA1_STOP		(0x1u<<1)
#define	DBGMCU_AHB1FZR_DBG_GPDMA0_STOP		(0x1u<<0)

// AHB3FZR Configuration

#define	DBGMCU_AHB3FZR_DBG_LPDMA3_STOP		(0x1u<<3)
#define	DBGMCU_AHB3FZR_DBG_LPDMA2_STOP		(0x1u<<2)
#define	DBGMCU_AHB3FZR_DBG_LPDMA1_STOP		(0x1u<<1)
#define	DBGMCU_AHB3FZR_DBG_LPDMA0_STOP		(0x1u<<0)

// SR Configuration

#define	DBGMCU_SR_AP_LOCKED					(0xFFu<<8)
#define	DBGMCU_SR_AP_LOCKED_0				(0x1u<<8)
#define	DBGMCU_SR_AP_PRESENT				(0xFFu<<0)
#define	DBGMCU_SR_AP_PRESENT_0				(0x1u<<0)

// DBG_AUTH_HOST Configuration

#define	DBGMCU_DBG_AUTH_HOST_AUTH_KEY		(0xFFFFFFFFu<<0)
#define	DBGMCU_DBG_AUTH_HOST_AUTH_KEY_0		(0x1u<<0)

// DBG_AUTH_DEVICE Configuration

#define	DBGMCU_DBG_AUTH_DEVICE_AUTH_ID		(0xFFFFu<<0)
#define	DBGMCU_DBG_AUTH_DEVICE_AUTH_ID_0	(0x1u<<0)

// PIDR4 Configuration

#define	DBGMCU_PIDR4_KCOUNT_4				(0xFu<<4)
#define	DBGMCU_PIDR4_KCOUNT_4_0				(0x1u<<4)
#define	DBGMCU_PIDR4_JEP106CON				(0xFu<<0)
#define	DBGMCU_PIDR4_JEP106CON_0			(0x1u<<0)

// PIDR0 Configuration

#define	DBGMCU_PIDR0_PARTNUM				(0xFFu<<0)
#define	DBGMCU_PIDR0_PARTNUM_0				(0x1u<<0)

// PIDR1 Configuration

#define	DBGMCU_PIDR1_JEP106ID				(0xFu<<4)
#define	DBGMCU_PIDR1_JEP106ID_0				(0x1u<<4)
#define	DBGMCU_PIDR1_PARTNUM				(0xFu<<0)
#define	DBGMCU_PIDR1_PARTNUM_0				(0x1u<<0)

// PIDR2 Configuration

#define	DBGMCU_PIDR2_REVISION				(0xFu<<4)
#define	DBGMCU_PIDR2_REVISION_0				(0x1u<<4)
#define	DBGMCU_PIDR2_JEDEC					(0x1u<<3)
#define	DBGMCU_PIDR2_JEP106ID				(0x7u<<0)
#define	DBGMCU_PIDR2_JEP106ID_0				(0x1u<<0)

// PIDR3 Configuration

#define	DBGMCU_PIDR3_REVAND					(0xFu<<4)
#define	DBGMCU_PIDR3_REVAND_0				(0x1u<<4)
#define	DBGMCU_PIDR3_CMOD					(0xFu<<0)
#define	DBGMCU_PIDR3_CMOD_0					(0x1u<<0)

// CIDR0 Configuration

#define	DBGMCU_CIDR0_PREAMBLE				(0xFFu<<0)
#define	DBGMCU_CIDR0_PREAMBLE_0				(0x1u<<0)

// CIDR1 Configuration

#define	DBGMCU_CIDR1_CLASS					(0xFu<<4)
#define	DBGMCU_CIDR1_CLASS_0				(0x1u<<4)
#define	DBGMCU_CIDR1_PREAMBLE				(0xFu<<0)
#define	DBGMCU_CIDR1_PREAMBLE_0				(0x1u<<0)

// CIDR2 Configuration

#define	DBGMCU_CIDR2_PREAMBLE				(0xFFu<<0)
#define	DBGMCU_CIDR2_PREAMBLE_0				(0x1u<<0)

// CIDR3 Configuration

#define	DBGMCU_CIDR3_PREAMBLE				(0xFFu<<0)
#define	DBGMCU_CIDR3_PREAMBLE_0				(0x1u<<0)
