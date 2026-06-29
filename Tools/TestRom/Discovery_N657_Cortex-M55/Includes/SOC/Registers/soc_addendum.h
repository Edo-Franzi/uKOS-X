/*
; soc_addendum.
; =============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		addendum equates.
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

// tim1 additional definitions
// ---------------------------

// CCMR1 Configuration

#define	TIM1_CCMR1_OC2M_3			(0x1u<<24)
#define	TIM1_CCMR1_OC1M_3			(0x1u<<16)
#define	TIM1_CCMR1_OC2CE			(0x1u<<15)
#define	TIM1_CCMR1_OC2M				(0x7u<<12)
#define	TIM1_CCMR1_OC2M_0			(0x1u<<12)
#define	TIM1_CCMR1_OC2PE			(0x1u<<11)
#define	TIM1_CCMR1_OC2FE			(0x1u<<10)
#define	TIM1_CCMR1_OC1CE			(0x1u<<7)
#define	TIM1_CCMR1_OC1M				(0x7u<<4)
#define	TIM1_CCMR1_OC1M_0			(0x1u<<4)
#define	TIM1_CCMR1_OC1PE			(0x1u<<3)
#define	TIM1_CCMR1_OC1FE			(0x1u<<2)

// CCMR2 Configuration

#define	TIM1_CCMR2_OC4M_4			(0x1u<<24)
#define	TIM1_CCMR2_OC3M_3			(0x1u<<16)
#define	TIM1_CCMR2_OC4CE			(0x1u<<15)
#define	TIM1_CCMR2_OC4M				(0x7u<<12)
#define	TIM1_CCMR2_OC4M_0			(0x1u<<12)
#define	TIM1_CCMR2_OC4PE			(0x1u<<11)
#define	TIM1_CCMR2_OC4FE			(0x1u<<10)
#define	TIM1_CCMR2_OC3CE			(0x1u<<7)
#define	TIM1_CCMR2_OC3M				(0x7u<<4)
#define	TIM1_CCMR2_OC3M_0			(0x1u<<4)
#define	TIM1_CCMR2_OC3PE			(0x1u<<3)
#define	TIM1_CCMR2_OC3FE			(0x1u<<2)

// tim15 additional definitions
// ----------------------------

// CCMR1 Configuration

#define	TIM15_CCMR1_OC2M_3			(0x1u<<24)
#define	TIM15_CCMR1_OC1M_3			(0x1u<<16)
#define	TIM15_CCMR1_OC2M			(0x7u<<12)
#define	TIM15_CCMR1_OC2M_0			(0x1u<<12)
#define	TIM15_CCMR1_OC2PE			(0x1u<<11)
#define	TIM15_CCMR1_OC2FE			(0x1u<<10)
#define	TIM15_CCMR1_OC1M			(0x7u<<4)
#define	TIM15_CCMR1_OC1M_0			(0x1u<<4)
#define	TIM15_CCMR1_OC1PE			(0x1u<<3)
#define	TIM15_CCMR1_OC1FE			(0x1u<<2)

// iwdg additional definitions
// ---------------------------

// KR Configuration

#define	IWDG_KR_DISABLE				0x5555u
#define	IWDG_KR_START				0xCCCCu
#define	IWDG_KR_RELOAD				0xAAAAu

// PR Configuration

#define	IWDG_PR_1_4					0x0000u
#define	IWDG_PR_1_8					0x0001u
#define	IWDG_PR_1_16				0x0002u
#define	IWDG_PR_1_32				0x0003u
#define	IWDG_PR_1_64				0x0004u
#define	IWDG_PR_1_128				0x0005u
#define	IWDG_PR_1_256				0x0006u
#define	IWDG_PR_1_512				0x0007u

// otg additional definitions
// --------------------------

#define	USB1_OTG_HS_IRQn			OTG1_IRQn
#define	OTG1_HS_S					(uintptr_t)OTG1_S
#define	USB1_OTG_HS_BASE			(uintptr_t)OTG1_HS_S

#define	USB2_OTG_HS_IRQn			OTG2_IRQn
#define	OTG2_HS_S					(uintptr_t)OTG2_S
#define	USB2_OTG_HS_BASE			(uintptr_t)OTG2_HS_S

// usbphy additional definitions
// -----------------------------

typedef struct {
	volatile	uint32_t	USBPHYC_CR;
	volatile	uint32_t	USBPHYC_TRIM1CR;
	volatile	uint32_t	USBPHYC_TRIM2CR;
} USB_HS_PHYC_GlobalTypeDef;

#if (defined(__cplusplus))
#define	USB1_HS_PHYC_NS	reinterpret_cast<USB_HS_PHYC_GlobalTypeDef *>(0x4803FC00u)
#define	USB1_HS_PHYC_S	reinterpret_cast<USB_HS_PHYC_GlobalTypeDef *>(0x5803FC00u)

#else
#define	USB1_HS_PHYC_NS	((USB_HS_PHYC_GlobalTypeDef *)0x4803FC00u)
#define	USB1_HS_PHYC_S	((USB_HS_PHYC_GlobalTypeDef *)0x5803FC00u)
#endif

// gpio additional definitions
// ---------------------------

// GPIO for MODE configuration
// - Input (reset state)
// - General purpose output
// - Alternate function
// - Analog function

#define	KIN							0x0u
#define	KOU							0x1u
#define	KAL							0x2u
#define	KAN							0x3u

// GPIO for OTYPER configuration
// - Output Push-pull
// - Output Open Drain

#define	KPP							0x0u
#define	KOD							0x1u

// GPIO for OSPEEDR configuration
// - Low speed 2-MHz
// - Medium speed 25-MHz
// - Fast speed 50-MHz
// - High speed 100-MHz

#define	K02							0x0u
#define	K25							0x1u
#define	K50							0x2u
#define	K99							0x3u

// GPIO for PUPDR configuration
// - No pull-up, pull-down
// - Pull-up
// - Pull-down
// - Reserved

#define	KNO							0x0u
#define	KPU							0x1u
#define	KPD							0x2u
#define	KRE							0x3u

// GPIO for AFR[x] configuration

#define	A00							0u
#define	A01							1u
#define	A02							2u
#define	A03							3u
#define	A04							4u
#define	A05							5u
#define	A06							6u
#define	A07							7u
#define	A08							8u
#define	A09							9u
#define	A10							10u
#define	A11							11u
#define	A12							12u
#define	A13							13u
#define	A14							14u
#define	A15							15u

// GPIO configure macro

#if (defined(SECURE_S))
#define	CNFGPIO(port, \
				a15, a14, a13, a12, a11, a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0, \
				b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, \
				c15, c14, c13, c12, c11, c10, c9, c8, c7, c6, c5, c4, c3, c2, c1, c0, \
				d15, d14, d13, d12, d11, d10, d9, d8, d7, d6, d5, d4, d3, d2, d1, d0, \
				e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0, \
				f15, f14, f13, f12, f11, f10, f9, f8, f7, f6, f5, f4, f3, f2, f1, f0) \
				GPIO##port##_S->AFRH =		(d15<<28) | (d14<<24) | (d13<<20) | (d12<<16) |	\
											(d11<<12) | (d10<<8)  | (d9<<4)   | (d8<<0);	\
				GPIO##port##_S->AFRL =		(d7<<28)  | (d6<<24)  | (d5<<20)  | (d4<<16)  |	\
											(d3<<12)  | (d2<<8)   | (d1<<4)   | (d0<<0);	\
				GPIO##port##_S->OSPEEDR =	(b15<<30) | (b14<<28) | (b13<<26) | (b12<<24) |	\
											(b11<<22) | (b10<<20) | (b9<<18)  | (b8<<16)  |	\
											(b7<<14)  | (b6<<12)  | (b5<<10)  | (b4<<8)   |	\
											(b3<<6)   | (b2<<4)   | (b1<<2)   | (b0<<0);	\
				GPIO##port##_S->OTYPER =	(e15<<15) | (e14<<14) | (e13<<13) | (e12<<12) |	\
											(e11<<11) | (e10<<10) | (e9<<9)   | (e8<<8)   |	\
											(e7<<7)   | (e6<<6)   | (e5<<5)   | (e4<<4)   |	\
											(e3<<3)   | (e2<<2)   | (e1<<1)   | (e0<<0);	\
				GPIO##port##_S->MODER =		(a15<<30) | (a14<<28) | (a13<<26) | (a12<<24) |	\
											(a11<<22) | (a10<<20) | (a9<<18)  | (a8<<16)  |	\
											(a7<<14)  | (a6<<12)  | (a5<<10)  | (a4<<8)   |	\
											(a3<<6)   | (a2<<4)   | (a1<<2)   | (a0<<0);	\
				GPIO##port##_S->PUPDR =		(c15<<30) | (c14<<28) | (c13<<26) | (c12<<24) |	\
											(c11<<22) | (c10<<20) | (c9<<18)  | (c8<<16)  |	\
											(c7<<14)  | (c6<<12)  | (c5<<10)  | (c4<<8)   |	\
											(c3<<6)   | (c2<<4)   | (c1<<2)   | (c0<<0);	\
				GPIO##port##_S->ODR |=		(f15<<15) | (f14<<14) | (f13<<13) | (f12<<12) |	\
											(f11<<11) | (f10<<10) | (f9<<9)   | (f8<<8)   |	\
											(f7<<7)   | (f6<<6)   | (f5<<5)   | (f4<<4)   |	\
											(f3<<3)   | (f2<<2)   | (f1<<1)   | (f0<<0);

#else
#define	CNFGPIO(port, \
				a15, a14, a13, a12, a11, a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0, \
				b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, \
				c15, c14, c13, c12, c11, c10, c9, c8, c7, c6, c5, c4, c3, c2, c1, c0, \
				d15, d14, d13, d12, d11, d10, d9, d8, d7, d6, d5, d4, d3, d2, d1, d0, \
				e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0, \
				f15, f14, f13, f12, f11, f10, f9, f8, f7, f6, f5, f4, f3, f2, f1, f0) \
				GPIO##port##_NS->AFRH =		(d15<<28) | (d14<<24) | (d13<<20) | (d12<<16) |	\
											(d11<<12) | (d10<<8)  | (d9<<4)   | (d8<<0);	\
				GPIO##port##_NS->AFRL =		(d7<<28)  | (d6<<24)  | (d5<<20)  | (d4<<16)  |	\
											(d3<<12)  | (d2<<8)   | (d1<<4)   | (d0<<0);	\
				GPIO##port##_NS->OSPEEDR =	(b15<<30) | (b14<<28) | (b13<<26) | (b12<<24) |	\
											(b11<<22) | (b10<<20) | (b9<<18)  | (b8<<16)  |	\
											(b7<<14)  | (b6<<12)  | (b5<<10)  | (b4<<8)   |	\
											(b3<<6)   | (b2<<4)   | (b1<<2)   | (b0<<0);	\
				GPIO##port##_NS->OTYPER =	(e15<<15) | (e14<<14) | (e13<<13) | (e12<<12) |	\
											(e11<<11) | (e10<<10) | (e9<<9)   | (e8<<8)   |	\
											(e7<<7)   | (e6<<6)   | (e5<<5)   | (e4<<4)   |	\
											(e3<<3)   | (e2<<2)   | (e1<<1)   | (e0<<0);	\
				GPIO##port##_NS->MODER =	(a15<<30) | (a14<<28) | (a13<<26) | (a12<<24) |	\
											(a11<<22) | (a10<<20) | (a9<<18)  | (a8<<16)  |	\
											(a7<<14)  | (a6<<12)  | (a5<<10)  | (a4<<8)   |	\
											(a3<<6)   | (a2<<4)   | (a1<<2)   | (a0<<0);	\
				GPIO##port##_NS->PUPDR =	(c15<<30) | (c14<<28) | (c13<<26) | (c12<<24) |	\
											(c11<<22) | (c10<<20) | (c9<<18)  | (c8<<16)  |	\
											(c7<<14)  | (c6<<12)  | (c5<<10)  | (c4<<8)   |	\
											(c3<<6)   | (c2<<4)   | (c1<<2)   | (c0<<0);	\
				GPIO##port##_NS->ODR |=		(f15<<15) | (f14<<14) | (f13<<13) | (f12<<12) |	\
											(f11<<11) | (f10<<10) | (f9<<9)   | (f8<<8)   |	\
											(f7<<7)   | (f6<<6)   | (f5<<5)   | (f4<<4)   |	\
											(f3<<3)   | (f2<<2)   | (f1<<1)   | (f0<<0);
#endif

// RTC additional definitions
// --------------------------

// WPR Configuration (Write Protection Register)

#define	RTC_WPR_UNLOCK_KEY1		0x000000CAu
#define	RTC_WPR_UNLOCK_KEY2		0x00000053u
#define	RTC_WPR_LOCK_KEY		0x000000FFu

