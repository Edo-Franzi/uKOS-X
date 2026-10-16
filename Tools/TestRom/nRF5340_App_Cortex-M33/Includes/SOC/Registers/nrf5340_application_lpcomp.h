/*
; nrf5340_application_lpcomp.
; ===========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_lpcomp equates.
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

// LPCOMP address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	TASKS_START;
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	TASKS_SAMPLE;
	volatile	uint32_t	RESERVED0[29];
	volatile	uint32_t	SUBSCRIBE_START;
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	SUBSCRIBE_SAMPLE;
	volatile	uint32_t	RESERVED1[29];
	volatile	uint32_t	EVENTS_READY;
	volatile	uint32_t	EVENTS_DOWN;
	volatile	uint32_t	EVENTS_UP;
	volatile	uint32_t	EVENTS_CROSS;
	volatile	uint32_t	RESERVED2[28];
	volatile	uint32_t	PUBLISH_READY;
	volatile	uint32_t	PUBLISH_DOWN;
	volatile	uint32_t	PUBLISH_UP;
	volatile	uint32_t	PUBLISH_CROSS;
	volatile	uint32_t	RESERVED3[28];
	volatile	uint32_t	SHORTS;
	volatile	uint32_t	RESERVED4[64];
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED5[61];
	volatile	uint32_t	RESULT;
	volatile	uint32_t	RESERVED6[63];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	PSEL;
	volatile	uint32_t	REFSEL;
	volatile	uint32_t	EXTREFSEL;
	volatile	uint32_t	RESERVED7[4];
	volatile	uint32_t	ANADETECT;
	volatile	uint32_t	RESERVED8[5];
	volatile	uint32_t	HYST;
} LPCOMP_TypeDef;

#if (defined(__cplusplus))
#define	LPCOMP_NS	reinterpret_cast<LPCOMP_TypeDef *>(0x4001A000u)
#define	LPCOMP_S	reinterpret_cast<LPCOMP_TypeDef *>(0x5001A000u)

#else
#define	LPCOMP_NS	((LPCOMP_TypeDef *)0x4001A000u)
#define	LPCOMP_S	((LPCOMP_TypeDef *)0x5001A000u)
#endif

// TASKS_START Configuration

#define	LPCOMP_TASKS_START_TASKS_START					(0x1u<<0)
#define	LPCOMP_TASKS_START_TASKS_START_TRIGGER			(0x1u<<0)

// TASKS_STOP Configuration

#define	LPCOMP_TASKS_STOP_TASKS_STOP					(0x1u<<0)
#define	LPCOMP_TASKS_STOP_TASKS_STOP_TRIGGER			(0x1u<<0)

// TASKS_SAMPLE Configuration

#define	LPCOMP_TASKS_SAMPLE_TASKS_SAMPLE				(0x1u<<0)
#define	LPCOMP_TASKS_SAMPLE_TASKS_SAMPLE_TRIGGER		(0x1u<<0)

// SUBSCRIBE_START Configuration

#define	LPCOMP_SUBSCRIBE_START_EN						(0x1u<<31)
#define	LPCOMP_SUBSCRIBE_START_CHIDX					(0xFFu<<0)
#define	LPCOMP_SUBSCRIBE_START_CHIDX_0					(0x1u<<0)
#define	LPCOMP_SUBSCRIBE_START_EN_DISABLED				(0x0u<<31)
#define	LPCOMP_SUBSCRIBE_START_EN_ENABLED				(0x1u<<31)

// SUBSCRIBE_STOP Configuration

#define	LPCOMP_SUBSCRIBE_STOP_EN						(0x1u<<31)
#define	LPCOMP_SUBSCRIBE_STOP_CHIDX						(0xFFu<<0)
#define	LPCOMP_SUBSCRIBE_STOP_CHIDX_0					(0x1u<<0)
#define	LPCOMP_SUBSCRIBE_STOP_EN_DISABLED				(0x0u<<31)
#define	LPCOMP_SUBSCRIBE_STOP_EN_ENABLED				(0x1u<<31)

// SUBSCRIBE_SAMPLE Configuration

#define	LPCOMP_SUBSCRIBE_SAMPLE_EN						(0x1u<<31)
#define	LPCOMP_SUBSCRIBE_SAMPLE_CHIDX					(0xFFu<<0)
#define	LPCOMP_SUBSCRIBE_SAMPLE_CHIDX_0					(0x1u<<0)
#define	LPCOMP_SUBSCRIBE_SAMPLE_EN_DISABLED				(0x0u<<31)
#define	LPCOMP_SUBSCRIBE_SAMPLE_EN_ENABLED				(0x1u<<31)

// EVENTS_READY Configuration

#define	LPCOMP_EVENTS_READY_EVENTS_READY				(0x1u<<0)
#define	LPCOMP_EVENTS_READY_EVENTS_READY_NOTGENERATED	(0x0u<<0)
#define	LPCOMP_EVENTS_READY_EVENTS_READY_GENERATED		(0x1u<<0)

// EVENTS_DOWN Configuration

#define	LPCOMP_EVENTS_DOWN_EVENTS_DOWN					(0x1u<<0)
#define	LPCOMP_EVENTS_DOWN_EVENTS_DOWN_NOTGENERATED		(0x0u<<0)
#define	LPCOMP_EVENTS_DOWN_EVENTS_DOWN_GENERATED		(0x1u<<0)

// EVENTS_UP Configuration

#define	LPCOMP_EVENTS_UP_EVENTS_UP						(0x1u<<0)
#define	LPCOMP_EVENTS_UP_EVENTS_UP_NOTGENERATED			(0x0u<<0)
#define	LPCOMP_EVENTS_UP_EVENTS_UP_GENERATED			(0x1u<<0)

// EVENTS_CROSS Configuration

#define	LPCOMP_EVENTS_CROSS_EVENTS_CROSS				(0x1u<<0)
#define	LPCOMP_EVENTS_CROSS_EVENTS_CROSS_NOTGENERATED	(0x0u<<0)
#define	LPCOMP_EVENTS_CROSS_EVENTS_CROSS_GENERATED		(0x1u<<0)

// PUBLISH_READY Configuration

#define	LPCOMP_PUBLISH_READY_EN							(0x1u<<31)
#define	LPCOMP_PUBLISH_READY_CHIDX						(0xFFu<<0)
#define	LPCOMP_PUBLISH_READY_CHIDX_0					(0x1u<<0)
#define	LPCOMP_PUBLISH_READY_EN_DISABLED				(0x0u<<31)
#define	LPCOMP_PUBLISH_READY_EN_ENABLED					(0x1u<<31)

// PUBLISH_DOWN Configuration

#define	LPCOMP_PUBLISH_DOWN_EN							(0x1u<<31)
#define	LPCOMP_PUBLISH_DOWN_CHIDX						(0xFFu<<0)
#define	LPCOMP_PUBLISH_DOWN_CHIDX_0						(0x1u<<0)
#define	LPCOMP_PUBLISH_DOWN_EN_DISABLED					(0x0u<<31)
#define	LPCOMP_PUBLISH_DOWN_EN_ENABLED					(0x1u<<31)

// PUBLISH_UP Configuration

#define	LPCOMP_PUBLISH_UP_EN							(0x1u<<31)
#define	LPCOMP_PUBLISH_UP_CHIDX							(0xFFu<<0)
#define	LPCOMP_PUBLISH_UP_CHIDX_0						(0x1u<<0)
#define	LPCOMP_PUBLISH_UP_EN_DISABLED					(0x0u<<31)
#define	LPCOMP_PUBLISH_UP_EN_ENABLED					(0x1u<<31)

// PUBLISH_CROSS Configuration

#define	LPCOMP_PUBLISH_CROSS_EN							(0x1u<<31)
#define	LPCOMP_PUBLISH_CROSS_CHIDX						(0xFFu<<0)
#define	LPCOMP_PUBLISH_CROSS_CHIDX_0					(0x1u<<0)
#define	LPCOMP_PUBLISH_CROSS_EN_DISABLED				(0x0u<<31)
#define	LPCOMP_PUBLISH_CROSS_EN_ENABLED					(0x1u<<31)

// SHORTS Configuration

#define	LPCOMP_SHORTS_CROSS_STOP						(0x1u<<4)
#define	LPCOMP_SHORTS_UP_STOP							(0x1u<<3)
#define	LPCOMP_SHORTS_DOWN_STOP							(0x1u<<2)
#define	LPCOMP_SHORTS_READY_STOP						(0x1u<<1)
#define	LPCOMP_SHORTS_READY_SAMPLE						(0x1u<<0)
#define	LPCOMP_SHORTS_CROSS_STOP_DISABLED				(0x0u<<4)
#define	LPCOMP_SHORTS_CROSS_STOP_ENABLED				(0x1u<<4)
#define	LPCOMP_SHORTS_UP_STOP_DISABLED					(0x0u<<3)
#define	LPCOMP_SHORTS_UP_STOP_ENABLED					(0x1u<<3)
#define	LPCOMP_SHORTS_DOWN_STOP_DISABLED				(0x0u<<2)
#define	LPCOMP_SHORTS_DOWN_STOP_ENABLED					(0x1u<<2)
#define	LPCOMP_SHORTS_READY_STOP_DISABLED				(0x0u<<1)
#define	LPCOMP_SHORTS_READY_STOP_ENABLED				(0x1u<<1)
#define	LPCOMP_SHORTS_READY_SAMPLE_DISABLED				(0x0u<<0)
#define	LPCOMP_SHORTS_READY_SAMPLE_ENABLED				(0x1u<<0)

// INTENSET Configuration

#define	LPCOMP_INTENSET_CROSS							(0x1u<<3)
#define	LPCOMP_INTENSET_UP								(0x1u<<2)
#define	LPCOMP_INTENSET_DOWN							(0x1u<<1)
#define	LPCOMP_INTENSET_READY							(0x1u<<0)
#define	LPCOMP_INTENSET_CROSS_DISABLED					(0x0u<<3)
#define	LPCOMP_INTENSET_CROSS_ENABLED					(0x1u<<3)
#define	LPCOMP_INTENSET_CROSS_SET						(0x1u<<3)
#define	LPCOMP_INTENSET_UP_DISABLED						(0x0u<<2)
#define	LPCOMP_INTENSET_UP_ENABLED						(0x1u<<2)
#define	LPCOMP_INTENSET_UP_SET							(0x1u<<2)
#define	LPCOMP_INTENSET_DOWN_DISABLED					(0x0u<<1)
#define	LPCOMP_INTENSET_DOWN_ENABLED					(0x1u<<1)
#define	LPCOMP_INTENSET_DOWN_SET						(0x1u<<1)
#define	LPCOMP_INTENSET_READY_DISABLED					(0x0u<<0)
#define	LPCOMP_INTENSET_READY_ENABLED					(0x1u<<0)
#define	LPCOMP_INTENSET_READY_SET						(0x1u<<0)

// INTENCLR Configuration

#define	LPCOMP_INTENCLR_CROSS							(0x1u<<3)
#define	LPCOMP_INTENCLR_UP								(0x1u<<2)
#define	LPCOMP_INTENCLR_DOWN							(0x1u<<1)
#define	LPCOMP_INTENCLR_READY							(0x1u<<0)
#define	LPCOMP_INTENCLR_CROSS_DISABLED					(0x0u<<3)
#define	LPCOMP_INTENCLR_CROSS_ENABLED					(0x1u<<3)
#define	LPCOMP_INTENCLR_CROSS_CLEAR						(0x1u<<3)
#define	LPCOMP_INTENCLR_UP_DISABLED						(0x0u<<2)
#define	LPCOMP_INTENCLR_UP_ENABLED						(0x1u<<2)
#define	LPCOMP_INTENCLR_UP_CLEAR						(0x1u<<2)
#define	LPCOMP_INTENCLR_DOWN_DISABLED					(0x0u<<1)
#define	LPCOMP_INTENCLR_DOWN_ENABLED					(0x1u<<1)
#define	LPCOMP_INTENCLR_DOWN_CLEAR						(0x1u<<1)
#define	LPCOMP_INTENCLR_READY_DISABLED					(0x0u<<0)
#define	LPCOMP_INTENCLR_READY_ENABLED					(0x1u<<0)
#define	LPCOMP_INTENCLR_READY_CLEAR						(0x1u<<0)

// RESULT Configuration

#define	LPCOMP_RESULT_RESULT							(0x1u<<0)
#define	LPCOMP_RESULT_RESULT_BELOW						(0x0u<<0)
#define	LPCOMP_RESULT_RESULT_ABOVE						(0x1u<<0)

// ENABLE Configuration

#define	LPCOMP_ENABLE_ENABLE							(0x3u<<0)
#define	LPCOMP_ENABLE_ENABLE_0							(0x1u<<0)
#define	LPCOMP_ENABLE_ENABLE_DISABLED					(0x0u<<0)
#define	LPCOMP_ENABLE_ENABLE_ENABLED					(0x1u<<0)

// PSEL Configuration

#define	LPCOMP_PSEL_PSEL								(0x7u<<0)
#define	LPCOMP_PSEL_PSEL_0								(0x1u<<0)
#define	LPCOMP_PSEL_PSEL_ANALOGINPUT0					(0x0u<<0)
#define	LPCOMP_PSEL_PSEL_ANALOGINPUT1					(0x1u<<0)
#define	LPCOMP_PSEL_PSEL_ANALOGINPUT2					(0x2u<<0)
#define	LPCOMP_PSEL_PSEL_ANALOGINPUT3					(0x3u<<0)
#define	LPCOMP_PSEL_PSEL_ANALOGINPUT4					(0x4u<<0)
#define	LPCOMP_PSEL_PSEL_ANALOGINPUT5					(0x5u<<0)
#define	LPCOMP_PSEL_PSEL_ANALOGINPUT6					(0x6u<<0)
#define	LPCOMP_PSEL_PSEL_ANALOGINPUT7					(0x7u<<0)

// REFSEL Configuration

#define	LPCOMP_REFSEL_REFSEL							(0xFu<<0)
#define	LPCOMP_REFSEL_REFSEL_0							(0x1u<<0)
#define	LPCOMP_REFSEL_REFSEL_REF1_8VDD					(0x0u<<0)
#define	LPCOMP_REFSEL_REFSEL_REF2_8VDD					(0x1u<<0)
#define	LPCOMP_REFSEL_REFSEL_REF3_8VDD					(0x2u<<0)
#define	LPCOMP_REFSEL_REFSEL_REF4_8VDD					(0x3u<<0)
#define	LPCOMP_REFSEL_REFSEL_REF5_8VDD					(0x4u<<0)
#define	LPCOMP_REFSEL_REFSEL_REF6_8VDD					(0x5u<<0)
#define	LPCOMP_REFSEL_REFSEL_REF7_8VDD					(0x6u<<0)
#define	LPCOMP_REFSEL_REFSEL_AREF						(0x7u<<0)
#define	LPCOMP_REFSEL_REFSEL_REF1_16VDD					(0x8u<<0)
#define	LPCOMP_REFSEL_REFSEL_REF3_16VDD					(0x9u<<0)
#define	LPCOMP_REFSEL_REFSEL_REF5_16VDD					(0xAu<<0)
#define	LPCOMP_REFSEL_REFSEL_REF7_16VDD					(0xBu<<0)
#define	LPCOMP_REFSEL_REFSEL_REF9_16VDD					(0xCu<<0)
#define	LPCOMP_REFSEL_REFSEL_REF11_16VDD				(0xDu<<0)
#define	LPCOMP_REFSEL_REFSEL_REF13_16VDD				(0xEu<<0)
#define	LPCOMP_REFSEL_REFSEL_REF15_16VDD				(0xFu<<0)

// EXTREFSEL Configuration

#define	LPCOMP_EXTREFSEL_EXTREFSEL						(0x1u<<0)
#define	LPCOMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE0		(0x0u<<0)
#define	LPCOMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE1		(0x1u<<0)

// ANADETECT Configuration

#define	LPCOMP_ANADETECT_ANADETECT						(0x3u<<0)
#define	LPCOMP_ANADETECT_ANADETECT_0					(0x1u<<0)
#define	LPCOMP_ANADETECT_ANADETECT_CROSS				(0x0u<<0)
#define	LPCOMP_ANADETECT_ANADETECT_UP					(0x1u<<0)
#define	LPCOMP_ANADETECT_ANADETECT_DOWN					(0x2u<<0)

// HYST Configuration

#define	LPCOMP_HYST_HYST								(0x1u<<0)
#define	LPCOMP_HYST_HYST_DISABLED						(0x0u<<0)
#define	LPCOMP_HYST_HYST_ENABLED						(0x1u<<0)
