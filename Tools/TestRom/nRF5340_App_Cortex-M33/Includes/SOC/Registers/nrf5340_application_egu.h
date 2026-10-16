/*
; nrf5340_application_egu.
; ========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_egu equates.
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

// EGU address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	TASKS_TRIGGER[16];
	volatile	uint32_t	RESERVED0[16];
	volatile	uint32_t	SUBSCRIBE_TRIGGER[16];
	volatile	uint32_t	RESERVED1[16];
	volatile	uint32_t	EVENTS_TRIGGERED[16];
	volatile	uint32_t	RESERVED2[16];
	volatile	uint32_t	PUBLISH_TRIGGERED[16];
	volatile	uint32_t	RESERVED3[80];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
} EGU_TypeDef;

#if (defined(__cplusplus))
#define	EGU0_NS	reinterpret_cast<EGU_TypeDef *>(0x4001B000u)
#define	EGU0_S	reinterpret_cast<EGU_TypeDef *>(0x5001B000u)
#define	EGU1_NS	reinterpret_cast<EGU_TypeDef *>(0x4001C000u)
#define	EGU1_S	reinterpret_cast<EGU_TypeDef *>(0x5001C000u)
#define	EGU2_NS	reinterpret_cast<EGU_TypeDef *>(0x4001D000u)
#define	EGU2_S	reinterpret_cast<EGU_TypeDef *>(0x5001D000u)
#define	EGU3_NS	reinterpret_cast<EGU_TypeDef *>(0x4001E000u)
#define	EGU3_S	reinterpret_cast<EGU_TypeDef *>(0x5001E000u)
#define	EGU4_NS	reinterpret_cast<EGU_TypeDef *>(0x4001F000u)
#define	EGU4_S	reinterpret_cast<EGU_TypeDef *>(0x5001F000u)
#define	EGU5_NS	reinterpret_cast<EGU_TypeDef *>(0x40020000u)
#define	EGU5_S	reinterpret_cast<EGU_TypeDef *>(0x50020000u)

#else
#define	EGU0_NS	((EGU_TypeDef *)0x4001B000u)
#define	EGU0_S	((EGU_TypeDef *)0x5001B000u)
#define	EGU1_NS	((EGU_TypeDef *)0x4001C000u)
#define	EGU1_S	((EGU_TypeDef *)0x5001C000u)
#define	EGU2_NS	((EGU_TypeDef *)0x4001D000u)
#define	EGU2_S	((EGU_TypeDef *)0x5001D000u)
#define	EGU3_NS	((EGU_TypeDef *)0x4001E000u)
#define	EGU3_S	((EGU_TypeDef *)0x5001E000u)
#define	EGU4_NS	((EGU_TypeDef *)0x4001F000u)
#define	EGU4_S	((EGU_TypeDef *)0x5001F000u)
#define	EGU5_NS	((EGU_TypeDef *)0x40020000u)
#define	EGU5_S	((EGU_TypeDef *)0x50020000u)
#endif

// TASKS_TRIGGER Configuration

#define	EGU_TASKS_TRIGGER_TASKS_TRIGGER						(0x1u<<0)
#define	EGU_TASKS_TRIGGER_TASKS_TRIGGER_TRIGGER				(0x1u<<0)

// SUBSCRIBE_TRIGGER Configuration

#define	EGU_SUBSCRIBE_TRIGGER_EN							(0x1u<<31)
#define	EGU_SUBSCRIBE_TRIGGER_CHIDX							(0xFFu<<0)
#define	EGU_SUBSCRIBE_TRIGGER_CHIDX_0						(0x1u<<0)
#define	EGU_SUBSCRIBE_TRIGGER_EN_DISABLED					(0x0u<<31)
#define	EGU_SUBSCRIBE_TRIGGER_EN_ENABLED					(0x1u<<31)

// EVENTS_TRIGGERED Configuration

#define	EGU_EVENTS_TRIGGERED_EVENTS_TRIGGERED				(0x1u<<0)
#define	EGU_EVENTS_TRIGGERED_EVENTS_TRIGGERED_NOTGENERATED	(0x0u<<0)
#define	EGU_EVENTS_TRIGGERED_EVENTS_TRIGGERED_GENERATED		(0x1u<<0)

// PUBLISH_TRIGGERED Configuration

#define	EGU_PUBLISH_TRIGGERED_EN							(0x1u<<31)
#define	EGU_PUBLISH_TRIGGERED_CHIDX							(0xFFu<<0)
#define	EGU_PUBLISH_TRIGGERED_CHIDX_0						(0x1u<<0)
#define	EGU_PUBLISH_TRIGGERED_EN_DISABLED					(0x0u<<31)
#define	EGU_PUBLISH_TRIGGERED_EN_ENABLED					(0x1u<<31)

// INTEN Configuration

#define	EGU_INTEN_TRIGGERED15								(0x1u<<15)
#define	EGU_INTEN_TRIGGERED14								(0x1u<<14)
#define	EGU_INTEN_TRIGGERED13								(0x1u<<13)
#define	EGU_INTEN_TRIGGERED12								(0x1u<<12)
#define	EGU_INTEN_TRIGGERED11								(0x1u<<11)
#define	EGU_INTEN_TRIGGERED10								(0x1u<<10)
#define	EGU_INTEN_TRIGGERED9								(0x1u<<9)
#define	EGU_INTEN_TRIGGERED8								(0x1u<<8)
#define	EGU_INTEN_TRIGGERED7								(0x1u<<7)
#define	EGU_INTEN_TRIGGERED6								(0x1u<<6)
#define	EGU_INTEN_TRIGGERED5								(0x1u<<5)
#define	EGU_INTEN_TRIGGERED4								(0x1u<<4)
#define	EGU_INTEN_TRIGGERED3								(0x1u<<3)
#define	EGU_INTEN_TRIGGERED2								(0x1u<<2)
#define	EGU_INTEN_TRIGGERED1								(0x1u<<1)
#define	EGU_INTEN_TRIGGERED0								(0x1u<<0)
#define	EGU_INTEN_TRIGGERED15_DISABLED						(0x0u<<15)
#define	EGU_INTEN_TRIGGERED15_ENABLED						(0x1u<<15)
#define	EGU_INTEN_TRIGGERED14_DISABLED						(0x0u<<14)
#define	EGU_INTEN_TRIGGERED14_ENABLED						(0x1u<<14)
#define	EGU_INTEN_TRIGGERED13_DISABLED						(0x0u<<13)
#define	EGU_INTEN_TRIGGERED13_ENABLED						(0x1u<<13)
#define	EGU_INTEN_TRIGGERED12_DISABLED						(0x0u<<12)
#define	EGU_INTEN_TRIGGERED12_ENABLED						(0x1u<<12)
#define	EGU_INTEN_TRIGGERED11_DISABLED						(0x0u<<11)
#define	EGU_INTEN_TRIGGERED11_ENABLED						(0x1u<<11)
#define	EGU_INTEN_TRIGGERED10_DISABLED						(0x0u<<10)
#define	EGU_INTEN_TRIGGERED10_ENABLED						(0x1u<<10)
#define	EGU_INTEN_TRIGGERED9_DISABLED						(0x0u<<9)
#define	EGU_INTEN_TRIGGERED9_ENABLED						(0x1u<<9)
#define	EGU_INTEN_TRIGGERED8_DISABLED						(0x0u<<8)
#define	EGU_INTEN_TRIGGERED8_ENABLED						(0x1u<<8)
#define	EGU_INTEN_TRIGGERED7_DISABLED						(0x0u<<7)
#define	EGU_INTEN_TRIGGERED7_ENABLED						(0x1u<<7)
#define	EGU_INTEN_TRIGGERED6_DISABLED						(0x0u<<6)
#define	EGU_INTEN_TRIGGERED6_ENABLED						(0x1u<<6)
#define	EGU_INTEN_TRIGGERED5_DISABLED						(0x0u<<5)
#define	EGU_INTEN_TRIGGERED5_ENABLED						(0x1u<<5)
#define	EGU_INTEN_TRIGGERED4_DISABLED						(0x0u<<4)
#define	EGU_INTEN_TRIGGERED4_ENABLED						(0x1u<<4)
#define	EGU_INTEN_TRIGGERED3_DISABLED						(0x0u<<3)
#define	EGU_INTEN_TRIGGERED3_ENABLED						(0x1u<<3)
#define	EGU_INTEN_TRIGGERED2_DISABLED						(0x0u<<2)
#define	EGU_INTEN_TRIGGERED2_ENABLED						(0x1u<<2)
#define	EGU_INTEN_TRIGGERED1_DISABLED						(0x0u<<1)
#define	EGU_INTEN_TRIGGERED1_ENABLED						(0x1u<<1)
#define	EGU_INTEN_TRIGGERED0_DISABLED						(0x0u<<0)
#define	EGU_INTEN_TRIGGERED0_ENABLED						(0x1u<<0)

// INTENSET Configuration

#define	EGU_INTENSET_TRIGGERED15							(0x1u<<15)
#define	EGU_INTENSET_TRIGGERED14							(0x1u<<14)
#define	EGU_INTENSET_TRIGGERED13							(0x1u<<13)
#define	EGU_INTENSET_TRIGGERED12							(0x1u<<12)
#define	EGU_INTENSET_TRIGGERED11							(0x1u<<11)
#define	EGU_INTENSET_TRIGGERED10							(0x1u<<10)
#define	EGU_INTENSET_TRIGGERED9								(0x1u<<9)
#define	EGU_INTENSET_TRIGGERED8								(0x1u<<8)
#define	EGU_INTENSET_TRIGGERED7								(0x1u<<7)
#define	EGU_INTENSET_TRIGGERED6								(0x1u<<6)
#define	EGU_INTENSET_TRIGGERED5								(0x1u<<5)
#define	EGU_INTENSET_TRIGGERED4								(0x1u<<4)
#define	EGU_INTENSET_TRIGGERED3								(0x1u<<3)
#define	EGU_INTENSET_TRIGGERED2								(0x1u<<2)
#define	EGU_INTENSET_TRIGGERED1								(0x1u<<1)
#define	EGU_INTENSET_TRIGGERED0								(0x1u<<0)
#define	EGU_INTENSET_TRIGGERED15_DISABLED					(0x0u<<15)
#define	EGU_INTENSET_TRIGGERED15_ENABLED					(0x1u<<15)
#define	EGU_INTENSET_TRIGGERED15_SET						(0x1u<<15)
#define	EGU_INTENSET_TRIGGERED14_DISABLED					(0x0u<<14)
#define	EGU_INTENSET_TRIGGERED14_ENABLED					(0x1u<<14)
#define	EGU_INTENSET_TRIGGERED14_SET						(0x1u<<14)
#define	EGU_INTENSET_TRIGGERED13_DISABLED					(0x0u<<13)
#define	EGU_INTENSET_TRIGGERED13_ENABLED					(0x1u<<13)
#define	EGU_INTENSET_TRIGGERED13_SET						(0x1u<<13)
#define	EGU_INTENSET_TRIGGERED12_DISABLED					(0x0u<<12)
#define	EGU_INTENSET_TRIGGERED12_ENABLED					(0x1u<<12)
#define	EGU_INTENSET_TRIGGERED12_SET						(0x1u<<12)
#define	EGU_INTENSET_TRIGGERED11_DISABLED					(0x0u<<11)
#define	EGU_INTENSET_TRIGGERED11_ENABLED					(0x1u<<11)
#define	EGU_INTENSET_TRIGGERED11_SET						(0x1u<<11)
#define	EGU_INTENSET_TRIGGERED10_DISABLED					(0x0u<<10)
#define	EGU_INTENSET_TRIGGERED10_ENABLED					(0x1u<<10)
#define	EGU_INTENSET_TRIGGERED10_SET						(0x1u<<10)
#define	EGU_INTENSET_TRIGGERED9_DISABLED					(0x0u<<9)
#define	EGU_INTENSET_TRIGGERED9_ENABLED						(0x1u<<9)
#define	EGU_INTENSET_TRIGGERED9_SET							(0x1u<<9)
#define	EGU_INTENSET_TRIGGERED8_DISABLED					(0x0u<<8)
#define	EGU_INTENSET_TRIGGERED8_ENABLED						(0x1u<<8)
#define	EGU_INTENSET_TRIGGERED8_SET							(0x1u<<8)
#define	EGU_INTENSET_TRIGGERED7_DISABLED					(0x0u<<7)
#define	EGU_INTENSET_TRIGGERED7_ENABLED						(0x1u<<7)
#define	EGU_INTENSET_TRIGGERED7_SET							(0x1u<<7)
#define	EGU_INTENSET_TRIGGERED6_DISABLED					(0x0u<<6)
#define	EGU_INTENSET_TRIGGERED6_ENABLED						(0x1u<<6)
#define	EGU_INTENSET_TRIGGERED6_SET							(0x1u<<6)
#define	EGU_INTENSET_TRIGGERED5_DISABLED					(0x0u<<5)
#define	EGU_INTENSET_TRIGGERED5_ENABLED						(0x1u<<5)
#define	EGU_INTENSET_TRIGGERED5_SET							(0x1u<<5)
#define	EGU_INTENSET_TRIGGERED4_DISABLED					(0x0u<<4)
#define	EGU_INTENSET_TRIGGERED4_ENABLED						(0x1u<<4)
#define	EGU_INTENSET_TRIGGERED4_SET							(0x1u<<4)
#define	EGU_INTENSET_TRIGGERED3_DISABLED					(0x0u<<3)
#define	EGU_INTENSET_TRIGGERED3_ENABLED						(0x1u<<3)
#define	EGU_INTENSET_TRIGGERED3_SET							(0x1u<<3)
#define	EGU_INTENSET_TRIGGERED2_DISABLED					(0x0u<<2)
#define	EGU_INTENSET_TRIGGERED2_ENABLED						(0x1u<<2)
#define	EGU_INTENSET_TRIGGERED2_SET							(0x1u<<2)
#define	EGU_INTENSET_TRIGGERED1_DISABLED					(0x0u<<1)
#define	EGU_INTENSET_TRIGGERED1_ENABLED						(0x1u<<1)
#define	EGU_INTENSET_TRIGGERED1_SET							(0x1u<<1)
#define	EGU_INTENSET_TRIGGERED0_DISABLED					(0x0u<<0)
#define	EGU_INTENSET_TRIGGERED0_ENABLED						(0x1u<<0)
#define	EGU_INTENSET_TRIGGERED0_SET							(0x1u<<0)

// INTENCLR Configuration

#define	EGU_INTENCLR_TRIGGERED15							(0x1u<<15)
#define	EGU_INTENCLR_TRIGGERED14							(0x1u<<14)
#define	EGU_INTENCLR_TRIGGERED13							(0x1u<<13)
#define	EGU_INTENCLR_TRIGGERED12							(0x1u<<12)
#define	EGU_INTENCLR_TRIGGERED11							(0x1u<<11)
#define	EGU_INTENCLR_TRIGGERED10							(0x1u<<10)
#define	EGU_INTENCLR_TRIGGERED9								(0x1u<<9)
#define	EGU_INTENCLR_TRIGGERED8								(0x1u<<8)
#define	EGU_INTENCLR_TRIGGERED7								(0x1u<<7)
#define	EGU_INTENCLR_TRIGGERED6								(0x1u<<6)
#define	EGU_INTENCLR_TRIGGERED5								(0x1u<<5)
#define	EGU_INTENCLR_TRIGGERED4								(0x1u<<4)
#define	EGU_INTENCLR_TRIGGERED3								(0x1u<<3)
#define	EGU_INTENCLR_TRIGGERED2								(0x1u<<2)
#define	EGU_INTENCLR_TRIGGERED1								(0x1u<<1)
#define	EGU_INTENCLR_TRIGGERED0								(0x1u<<0)
#define	EGU_INTENCLR_TRIGGERED15_DISABLED					(0x0u<<15)
#define	EGU_INTENCLR_TRIGGERED15_ENABLED					(0x1u<<15)
#define	EGU_INTENCLR_TRIGGERED15_CLEAR						(0x1u<<15)
#define	EGU_INTENCLR_TRIGGERED14_DISABLED					(0x0u<<14)
#define	EGU_INTENCLR_TRIGGERED14_ENABLED					(0x1u<<14)
#define	EGU_INTENCLR_TRIGGERED14_CLEAR						(0x1u<<14)
#define	EGU_INTENCLR_TRIGGERED13_DISABLED					(0x0u<<13)
#define	EGU_INTENCLR_TRIGGERED13_ENABLED					(0x1u<<13)
#define	EGU_INTENCLR_TRIGGERED13_CLEAR						(0x1u<<13)
#define	EGU_INTENCLR_TRIGGERED12_DISABLED					(0x0u<<12)
#define	EGU_INTENCLR_TRIGGERED12_ENABLED					(0x1u<<12)
#define	EGU_INTENCLR_TRIGGERED12_CLEAR						(0x1u<<12)
#define	EGU_INTENCLR_TRIGGERED11_DISABLED					(0x0u<<11)
#define	EGU_INTENCLR_TRIGGERED11_ENABLED					(0x1u<<11)
#define	EGU_INTENCLR_TRIGGERED11_CLEAR						(0x1u<<11)
#define	EGU_INTENCLR_TRIGGERED10_DISABLED					(0x0u<<10)
#define	EGU_INTENCLR_TRIGGERED10_ENABLED					(0x1u<<10)
#define	EGU_INTENCLR_TRIGGERED10_CLEAR						(0x1u<<10)
#define	EGU_INTENCLR_TRIGGERED9_DISABLED					(0x0u<<9)
#define	EGU_INTENCLR_TRIGGERED9_ENABLED						(0x1u<<9)
#define	EGU_INTENCLR_TRIGGERED9_CLEAR						(0x1u<<9)
#define	EGU_INTENCLR_TRIGGERED8_DISABLED					(0x0u<<8)
#define	EGU_INTENCLR_TRIGGERED8_ENABLED						(0x1u<<8)
#define	EGU_INTENCLR_TRIGGERED8_CLEAR						(0x1u<<8)
#define	EGU_INTENCLR_TRIGGERED7_DISABLED					(0x0u<<7)
#define	EGU_INTENCLR_TRIGGERED7_ENABLED						(0x1u<<7)
#define	EGU_INTENCLR_TRIGGERED7_CLEAR						(0x1u<<7)
#define	EGU_INTENCLR_TRIGGERED6_DISABLED					(0x0u<<6)
#define	EGU_INTENCLR_TRIGGERED6_ENABLED						(0x1u<<6)
#define	EGU_INTENCLR_TRIGGERED6_CLEAR						(0x1u<<6)
#define	EGU_INTENCLR_TRIGGERED5_DISABLED					(0x0u<<5)
#define	EGU_INTENCLR_TRIGGERED5_ENABLED						(0x1u<<5)
#define	EGU_INTENCLR_TRIGGERED5_CLEAR						(0x1u<<5)
#define	EGU_INTENCLR_TRIGGERED4_DISABLED					(0x0u<<4)
#define	EGU_INTENCLR_TRIGGERED4_ENABLED						(0x1u<<4)
#define	EGU_INTENCLR_TRIGGERED4_CLEAR						(0x1u<<4)
#define	EGU_INTENCLR_TRIGGERED3_DISABLED					(0x0u<<3)
#define	EGU_INTENCLR_TRIGGERED3_ENABLED						(0x1u<<3)
#define	EGU_INTENCLR_TRIGGERED3_CLEAR						(0x1u<<3)
#define	EGU_INTENCLR_TRIGGERED2_DISABLED					(0x0u<<2)
#define	EGU_INTENCLR_TRIGGERED2_ENABLED						(0x1u<<2)
#define	EGU_INTENCLR_TRIGGERED2_CLEAR						(0x1u<<2)
#define	EGU_INTENCLR_TRIGGERED1_DISABLED					(0x0u<<1)
#define	EGU_INTENCLR_TRIGGERED1_ENABLED						(0x1u<<1)
#define	EGU_INTENCLR_TRIGGERED1_CLEAR						(0x1u<<1)
#define	EGU_INTENCLR_TRIGGERED0_DISABLED					(0x0u<<0)
#define	EGU_INTENCLR_TRIGGERED0_ENABLED						(0x1u<<0)
#define	EGU_INTENCLR_TRIGGERED0_CLEAR						(0x1u<<0)
