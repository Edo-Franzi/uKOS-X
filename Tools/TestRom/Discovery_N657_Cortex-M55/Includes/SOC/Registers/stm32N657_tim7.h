/*
; stm32N657_tim7.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_tim7 equates.
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

// TIM7 address definitions
// ------------------------

typedef struct {
	volatile	uint16_t	CR1;
	volatile	uint16_t	RESERVED0;
	volatile	uint32_t	CR2;
	volatile	uint32_t	RESERVED1;
	volatile	uint16_t	DIER;
	volatile	uint16_t	RESERVED2;
	volatile	uint16_t	SR;
	volatile	uint16_t	RESERVED3;
	volatile	uint16_t	EGR;
	volatile	uint16_t	RESERVED4[7];
	volatile	uint32_t	CNT;
	volatile	uint16_t	PSC;
	volatile	uint16_t	RESERVED5;
	volatile	uint32_t	ARR;
} TIM7_TypeDef;

#if (defined(__cplusplus))
#define	TIM7_S	reinterpret_cast<TIM7_TypeDef *>(0x50001400u)

#else
#define	TIM7_S	((TIM7_TypeDef *)0x50001400u)
#endif

// CR1 Configuration

#define	TIM7_CR1_DITHEN			(0x1u<<12)
#define	TIM7_CR1_UIFREMAP		(0x1u<<11)
#define	TIM7_CR1_ARPE			(0x1u<<7)
#define	TIM7_CR1_OPM			(0x1u<<3)
#define	TIM7_CR1_URS			(0x1u<<2)
#define	TIM7_CR1_UDIS			(0x1u<<1)
#define	TIM7_CR1_CEN			(0x1u<<0)

#define	TIM7_CR1_DITHEN_B_0X0	(0x0u<<12)
#define	TIM7_CR1_DITHEN_B_0X1	(0x1u<<12)
#define	TIM7_CR1_UIFREMAP_B_0X0	(0x0u<<11)
#define	TIM7_CR1_UIFREMAP_B_0X1	(0x1u<<11)
#define	TIM7_CR1_ARPE_B_0X0		(0x0u<<7)
#define	TIM7_CR1_ARPE_B_0X1		(0x1u<<7)
#define	TIM7_CR1_OPM_B_0X0		(0x0u<<3)
#define	TIM7_CR1_OPM_B_0X1		(0x1u<<3)
#define	TIM7_CR1_URS_B_0X0		(0x0u<<2)
#define	TIM7_CR1_URS_B_0X1		(0x1u<<2)
#define	TIM7_CR1_UDIS_B_0X0		(0x0u<<1)
#define	TIM7_CR1_UDIS_B_0X1		(0x1u<<1)
#define	TIM7_CR1_CEN_B_0X0		(0x0u<<0)
#define	TIM7_CR1_CEN_B_0X1		(0x1u<<0)

// CR2 Configuration

#define	TIM7_CR2_ADSYNC			(0x1u<<28)
#define	TIM7_CR2_MMS			(0x7u<<4)
#define	TIM7_CR2_MMS_0			(0x1u<<4)

#define	TIM7_CR2_ADSYNC_B_0X0	(0x0u<<28)
#define	TIM7_CR2_ADSYNC_B_0X1	(0x1u<<28)
#define	TIM7_CR2_MMS_B_0X0		(0x0u<<4)
#define	TIM7_CR2_MMS_B_0X1		(0x1u<<4)
#define	TIM7_CR2_MMS_B_0X2		(0x2u<<4)

// DIER Configuration

#define	TIM7_DIER_UDE			(0x1u<<8)
#define	TIM7_DIER_UIE			(0x1u<<0)

#define	TIM7_DIER_UDE_B_0X0		(0x0u<<8)
#define	TIM7_DIER_UDE_B_0X1		(0x1u<<8)
#define	TIM7_DIER_UIE_B_0X0		(0x0u<<0)
#define	TIM7_DIER_UIE_B_0X1		(0x1u<<0)

// SR Configuration

#define	TIM7_SR_UIF				(0x1u<<0)

#define	TIM7_SR_UIF_B_0X0		(0x0u<<0)
#define	TIM7_SR_UIF_B_0X1		(0x1u<<0)

// EGR Configuration

#define	TIM7_EGR_UG				(0x1u<<0)

#define	TIM7_EGR_UG_B_0X0		(0x0u<<0)
#define	TIM7_EGR_UG_B_0X1		(0x1u<<0)

// CNT Configuration

#define	TIM7_CNT_UIFCPY			(0x1u<<31)
#define	TIM7_CNT_CNT			(0xFFFFu<<0)
#define	TIM7_CNT_CNT_0			(0x1u<<0)

// PSC Configuration

#define	TIM7_PSC_PSC			(0xFFFFu<<0)
#define	TIM7_PSC_PSC_0			(0x1u<<0)

// ARR Configuration

#define	TIM7_ARR_ARR			(0xFFFFFu<<0)
#define	TIM7_ARR_ARR_0			(0x1u<<0)
