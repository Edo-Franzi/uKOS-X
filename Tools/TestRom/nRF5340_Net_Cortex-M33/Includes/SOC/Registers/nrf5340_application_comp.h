/*
; nrf5340_application_comp.
; =========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_comp equates.
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

// COMP address definitions
// ------------------------

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
	volatile	uint32_t	RESERVED4[63];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED5[61];
	volatile	uint32_t	RESULT;
	volatile	uint32_t	RESERVED6[63];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	PSEL;
	volatile	uint32_t	REFSEL;
	volatile	uint32_t	EXTREFSEL;
	volatile	uint32_t	RESERVED7[8];
	volatile	uint32_t	TH;
	volatile	uint32_t	MODE;
	volatile	uint32_t	HYST;
	volatile	uint32_t	ISOURCE;
} COMP_TypeDef;

#if (defined(__cplusplus))
#define	COMP_NS	reinterpret_cast<COMP_TypeDef *>(0x4001A000u)
#define	COMP_S	reinterpret_cast<COMP_TypeDef *>(0x5001A000u)

#else
#define	COMP_NS	((COMP_TypeDef *)0x4001A000u)
#define	COMP_S	((COMP_TypeDef *)0x5001A000u)
#endif

// TASKS_START Configuration

#define	COMP_TASKS_START_TASKS_START				(0x1u<<0)
#define	COMP_TASKS_START_TASKS_START_TRIGGER		(0x1u<<0)

// TASKS_STOP Configuration

#define	COMP_TASKS_STOP_TASKS_STOP					(0x1u<<0)
#define	COMP_TASKS_STOP_TASKS_STOP_TRIGGER			(0x1u<<0)

// TASKS_SAMPLE Configuration

#define	COMP_TASKS_SAMPLE_TASKS_SAMPLE				(0x1u<<0)
#define	COMP_TASKS_SAMPLE_TASKS_SAMPLE_TRIGGER		(0x1u<<0)

// SUBSCRIBE_START Configuration

#define	COMP_SUBSCRIBE_START_EN						(0x1u<<31)
#define	COMP_SUBSCRIBE_START_CHIDX					(0xFFu<<0)
#define	COMP_SUBSCRIBE_START_CHIDX_0				(0x1u<<0)
#define	COMP_SUBSCRIBE_START_EN_DISABLED			(0x0u<<31)
#define	COMP_SUBSCRIBE_START_EN_ENABLED				(0x1u<<31)

// SUBSCRIBE_STOP Configuration

#define	COMP_SUBSCRIBE_STOP_EN						(0x1u<<31)
#define	COMP_SUBSCRIBE_STOP_CHIDX					(0xFFu<<0)
#define	COMP_SUBSCRIBE_STOP_CHIDX_0					(0x1u<<0)
#define	COMP_SUBSCRIBE_STOP_EN_DISABLED				(0x0u<<31)
#define	COMP_SUBSCRIBE_STOP_EN_ENABLED				(0x1u<<31)

// SUBSCRIBE_SAMPLE Configuration

#define	COMP_SUBSCRIBE_SAMPLE_EN					(0x1u<<31)
#define	COMP_SUBSCRIBE_SAMPLE_CHIDX					(0xFFu<<0)
#define	COMP_SUBSCRIBE_SAMPLE_CHIDX_0				(0x1u<<0)
#define	COMP_SUBSCRIBE_SAMPLE_EN_DISABLED			(0x0u<<31)
#define	COMP_SUBSCRIBE_SAMPLE_EN_ENABLED			(0x1u<<31)

// EVENTS_READY Configuration

#define	COMP_EVENTS_READY_EVENTS_READY				(0x1u<<0)
#define	COMP_EVENTS_READY_EVENTS_READY_NOTGENERATED	(0x0u<<0)
#define	COMP_EVENTS_READY_EVENTS_READY_GENERATED	(0x1u<<0)

// EVENTS_DOWN Configuration

#define	COMP_EVENTS_DOWN_EVENTS_DOWN				(0x1u<<0)
#define	COMP_EVENTS_DOWN_EVENTS_DOWN_NOTGENERATED	(0x0u<<0)
#define	COMP_EVENTS_DOWN_EVENTS_DOWN_GENERATED		(0x1u<<0)

// EVENTS_UP Configuration

#define	COMP_EVENTS_UP_EVENTS_UP					(0x1u<<0)
#define	COMP_EVENTS_UP_EVENTS_UP_NOTGENERATED		(0x0u<<0)
#define	COMP_EVENTS_UP_EVENTS_UP_GENERATED			(0x1u<<0)

// EVENTS_CROSS Configuration

#define	COMP_EVENTS_CROSS_EVENTS_CROSS				(0x1u<<0)
#define	COMP_EVENTS_CROSS_EVENTS_CROSS_NOTGENERATED	(0x0u<<0)
#define	COMP_EVENTS_CROSS_EVENTS_CROSS_GENERATED	(0x1u<<0)

// PUBLISH_READY Configuration

#define	COMP_PUBLISH_READY_EN						(0x1u<<31)
#define	COMP_PUBLISH_READY_CHIDX					(0xFFu<<0)
#define	COMP_PUBLISH_READY_CHIDX_0					(0x1u<<0)
#define	COMP_PUBLISH_READY_EN_DISABLED				(0x0u<<31)
#define	COMP_PUBLISH_READY_EN_ENABLED				(0x1u<<31)

// PUBLISH_DOWN Configuration

#define	COMP_PUBLISH_DOWN_EN						(0x1u<<31)
#define	COMP_PUBLISH_DOWN_CHIDX						(0xFFu<<0)
#define	COMP_PUBLISH_DOWN_CHIDX_0					(0x1u<<0)
#define	COMP_PUBLISH_DOWN_EN_DISABLED				(0x0u<<31)
#define	COMP_PUBLISH_DOWN_EN_ENABLED				(0x1u<<31)

// PUBLISH_UP Configuration

#define	COMP_PUBLISH_UP_EN							(0x1u<<31)
#define	COMP_PUBLISH_UP_CHIDX						(0xFFu<<0)
#define	COMP_PUBLISH_UP_CHIDX_0						(0x1u<<0)
#define	COMP_PUBLISH_UP_EN_DISABLED					(0x0u<<31)
#define	COMP_PUBLISH_UP_EN_ENABLED					(0x1u<<31)

// PUBLISH_CROSS Configuration

#define	COMP_PUBLISH_CROSS_EN						(0x1u<<31)
#define	COMP_PUBLISH_CROSS_CHIDX					(0xFFu<<0)
#define	COMP_PUBLISH_CROSS_CHIDX_0					(0x1u<<0)
#define	COMP_PUBLISH_CROSS_EN_DISABLED				(0x0u<<31)
#define	COMP_PUBLISH_CROSS_EN_ENABLED				(0x1u<<31)

// SHORTS Configuration

#define	COMP_SHORTS_CROSS_STOP						(0x1u<<4)
#define	COMP_SHORTS_UP_STOP							(0x1u<<3)
#define	COMP_SHORTS_DOWN_STOP						(0x1u<<2)
#define	COMP_SHORTS_READY_STOP						(0x1u<<1)
#define	COMP_SHORTS_READY_SAMPLE					(0x1u<<0)
#define	COMP_SHORTS_CROSS_STOP_DISABLED				(0x0u<<4)
#define	COMP_SHORTS_CROSS_STOP_ENABLED				(0x1u<<4)
#define	COMP_SHORTS_UP_STOP_DISABLED				(0x0u<<3)
#define	COMP_SHORTS_UP_STOP_ENABLED					(0x1u<<3)
#define	COMP_SHORTS_DOWN_STOP_DISABLED				(0x0u<<2)
#define	COMP_SHORTS_DOWN_STOP_ENABLED				(0x1u<<2)
#define	COMP_SHORTS_READY_STOP_DISABLED				(0x0u<<1)
#define	COMP_SHORTS_READY_STOP_ENABLED				(0x1u<<1)
#define	COMP_SHORTS_READY_SAMPLE_DISABLED			(0x0u<<0)
#define	COMP_SHORTS_READY_SAMPLE_ENABLED			(0x1u<<0)

// INTEN Configuration

#define	COMP_INTEN_CROSS							(0x1u<<3)
#define	COMP_INTEN_UP								(0x1u<<2)
#define	COMP_INTEN_DOWN								(0x1u<<1)
#define	COMP_INTEN_READY							(0x1u<<0)
#define	COMP_INTEN_CROSS_DISABLED					(0x0u<<3)
#define	COMP_INTEN_CROSS_ENABLED					(0x1u<<3)
#define	COMP_INTEN_UP_DISABLED						(0x0u<<2)
#define	COMP_INTEN_UP_ENABLED						(0x1u<<2)
#define	COMP_INTEN_DOWN_DISABLED					(0x0u<<1)
#define	COMP_INTEN_DOWN_ENABLED						(0x1u<<1)
#define	COMP_INTEN_READY_DISABLED					(0x0u<<0)
#define	COMP_INTEN_READY_ENABLED					(0x1u<<0)

// INTENSET Configuration

#define	COMP_INTENSET_CROSS							(0x1u<<3)
#define	COMP_INTENSET_UP							(0x1u<<2)
#define	COMP_INTENSET_DOWN							(0x1u<<1)
#define	COMP_INTENSET_READY							(0x1u<<0)
#define	COMP_INTENSET_CROSS_DISABLED				(0x0u<<3)
#define	COMP_INTENSET_CROSS_ENABLED					(0x1u<<3)
#define	COMP_INTENSET_CROSS_SET						(0x1u<<3)
#define	COMP_INTENSET_UP_DISABLED					(0x0u<<2)
#define	COMP_INTENSET_UP_ENABLED					(0x1u<<2)
#define	COMP_INTENSET_UP_SET						(0x1u<<2)
#define	COMP_INTENSET_DOWN_DISABLED					(0x0u<<1)
#define	COMP_INTENSET_DOWN_ENABLED					(0x1u<<1)
#define	COMP_INTENSET_DOWN_SET						(0x1u<<1)
#define	COMP_INTENSET_READY_DISABLED				(0x0u<<0)
#define	COMP_INTENSET_READY_ENABLED					(0x1u<<0)
#define	COMP_INTENSET_READY_SET						(0x1u<<0)

// INTENCLR Configuration

#define	COMP_INTENCLR_CROSS							(0x1u<<3)
#define	COMP_INTENCLR_UP							(0x1u<<2)
#define	COMP_INTENCLR_DOWN							(0x1u<<1)
#define	COMP_INTENCLR_READY							(0x1u<<0)
#define	COMP_INTENCLR_CROSS_DISABLED				(0x0u<<3)
#define	COMP_INTENCLR_CROSS_ENABLED					(0x1u<<3)
#define	COMP_INTENCLR_CROSS_CLEAR					(0x1u<<3)
#define	COMP_INTENCLR_UP_DISABLED					(0x0u<<2)
#define	COMP_INTENCLR_UP_ENABLED					(0x1u<<2)
#define	COMP_INTENCLR_UP_CLEAR						(0x1u<<2)
#define	COMP_INTENCLR_DOWN_DISABLED					(0x0u<<1)
#define	COMP_INTENCLR_DOWN_ENABLED					(0x1u<<1)
#define	COMP_INTENCLR_DOWN_CLEAR					(0x1u<<1)
#define	COMP_INTENCLR_READY_DISABLED				(0x0u<<0)
#define	COMP_INTENCLR_READY_ENABLED					(0x1u<<0)
#define	COMP_INTENCLR_READY_CLEAR					(0x1u<<0)

// RESULT Configuration

#define	COMP_RESULT_RESULT							(0x1u<<0)
#define	COMP_RESULT_RESULT_BELOW					(0x0u<<0)
#define	COMP_RESULT_RESULT_ABOVE					(0x1u<<0)

// ENABLE Configuration

#define	COMP_ENABLE_ENABLE							(0x3u<<0)
#define	COMP_ENABLE_ENABLE_0						(0x1u<<0)
#define	COMP_ENABLE_ENABLE_DISABLED					(0x0u<<0)
#define	COMP_ENABLE_ENABLE_ENABLED					(0x2u<<0)

// PSEL Configuration

#define	COMP_PSEL_PSEL								(0x7u<<0)
#define	COMP_PSEL_PSEL_0							(0x1u<<0)
#define	COMP_PSEL_PSEL_ANALOGINPUT0					(0x0u<<0)
#define	COMP_PSEL_PSEL_ANALOGINPUT1					(0x1u<<0)
#define	COMP_PSEL_PSEL_ANALOGINPUT2					(0x2u<<0)
#define	COMP_PSEL_PSEL_ANALOGINPUT3					(0x3u<<0)
#define	COMP_PSEL_PSEL_ANALOGINPUT4					(0x4u<<0)
#define	COMP_PSEL_PSEL_ANALOGINPUT5					(0x5u<<0)
#define	COMP_PSEL_PSEL_ANALOGINPUT6					(0x6u<<0)
#define	COMP_PSEL_PSEL_ANALOGINPUT7					(0x7u<<0)

// REFSEL Configuration

#define	COMP_REFSEL_REFSEL							(0x7u<<0)
#define	COMP_REFSEL_REFSEL_0						(0x1u<<0)
#define	COMP_REFSEL_REFSEL_INT1V2					(0x0u<<0)
#define	COMP_REFSEL_REFSEL_INT1V8					(0x1u<<0)
#define	COMP_REFSEL_REFSEL_INT2V4					(0x2u<<0)
#define	COMP_REFSEL_REFSEL_VDD						(0x4u<<0)
#define	COMP_REFSEL_REFSEL_AREF						(0x5u<<0)

// EXTREFSEL Configuration

#define	COMP_EXTREFSEL_EXTREFSEL					(0x7u<<0)
#define	COMP_EXTREFSEL_EXTREFSEL_0					(0x1u<<0)
#define	COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE0	(0x0u<<0)
#define	COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE1	(0x1u<<0)
#define	COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE2	(0x2u<<0)
#define	COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE3	(0x3u<<0)
#define	COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE4	(0x4u<<0)
#define	COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE5	(0x5u<<0)
#define	COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE6	(0x6u<<0)
#define	COMP_EXTREFSEL_EXTREFSEL_ANALOGREFERENCE7	(0x7u<<0)

// TH Configuration

#define	COMP_TH_THUP								(0x3Fu<<8)
#define	COMP_TH_THUP_0								(0x1u<<8)
#define	COMP_TH_THDOWN								(0x3Fu<<0)
#define	COMP_TH_THDOWN_0							(0x1u<<0)

// MODE Configuration

#define	COMP_MODE_MAIN								(0x1u<<8)
#define	COMP_MODE_SP								(0x3u<<0)
#define	COMP_MODE_SP_0								(0x1u<<0)
#define	COMP_MODE_MAIN_SE							(0x0u<<8)
#define	COMP_MODE_MAIN_DIFF							(0x1u<<8)
#define	COMP_MODE_SP_LOW							(0x0u<<0)
#define	COMP_MODE_SP_NORMAL							(0x1u<<0)
#define	COMP_MODE_SP_HIGH							(0x2u<<0)

// HYST Configuration

#define	COMP_HYST_HYST								(0x1u<<0)
#define	COMP_HYST_HYST_NOHYST						(0x0u<<0)
#define	COMP_HYST_HYST_HYST50MV						(0x1u<<0)

// ISOURCE Configuration

#define	COMP_ISOURCE_ISOURCE						(0x3u<<0)
#define	COMP_ISOURCE_ISOURCE_0						(0x1u<<0)
#define	COMP_ISOURCE_ISOURCE_OFF					(0x0u<<0)
#define	COMP_ISOURCE_ISOURCE_IEN2MA5				(0x1u<<0)
#define	COMP_ISOURCE_ISOURCE_IEN5MA					(0x2u<<0)
#define	COMP_ISOURCE_ISOURCE_IEN10MA				(0x3u<<0)
