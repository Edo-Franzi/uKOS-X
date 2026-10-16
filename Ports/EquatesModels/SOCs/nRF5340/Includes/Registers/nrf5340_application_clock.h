/*
; nrf5340_application_clock.
; ==========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_clock equates.
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

// CLOCK address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	TASKS_HFCLKSTART;
	volatile	uint32_t	TASKS_HFCLKSTOP;
	volatile	uint32_t	TASKS_LFCLKSTART;
	volatile	uint32_t	TASKS_LFCLKSTOP;
	volatile	uint32_t	TASKS_CAL;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	TASKS_HFCLKAUDIOSTART;
	volatile	uint32_t	TASKS_HFCLKAUDIOSTOP;
	volatile	uint32_t	TASKS_HFCLK192MSTART;
	volatile	uint32_t	TASKS_HFCLK192MSTOP;
	volatile	uint32_t	RESERVED1[22];
	volatile	uint32_t	SUBSCRIBE_HFCLKSTART;
	volatile	uint32_t	SUBSCRIBE_HFCLKSTOP;
	volatile	uint32_t	SUBSCRIBE_LFCLKSTART;
	volatile	uint32_t	SUBSCRIBE_LFCLKSTOP;
	volatile	uint32_t	SUBSCRIBE_CAL;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	SUBSCRIBE_HFCLKAUDIOSTART;
	volatile	uint32_t	SUBSCRIBE_HFCLKAUDIOSTOP;
	volatile	uint32_t	SUBSCRIBE_HFCLK192MSTART;
	volatile	uint32_t	SUBSCRIBE_HFCLK192MSTOP;
	volatile	uint32_t	RESERVED3[22];
	volatile	uint32_t	EVENTS_HFCLKSTARTED;
	volatile	uint32_t	EVENTS_LFCLKSTARTED;
	volatile	uint32_t	RESERVED4[5];
	volatile	uint32_t	EVENTS_DONE;
	volatile	uint32_t	EVENTS_HFCLKAUDIOSTARTED;
	volatile	uint32_t	EVENTS_HFCLK192MSTARTED;
	volatile	uint32_t	RESERVED5[22];
	volatile	uint32_t	PUBLISH_HFCLKSTARTED;
	volatile	uint32_t	PUBLISH_LFCLKSTARTED;
	volatile	uint32_t	RESERVED6[5];
	volatile	uint32_t	PUBLISH_DONE;
	volatile	uint32_t	PUBLISH_HFCLKAUDIOSTARTED;
	volatile	uint32_t	PUBLISH_HFCLK192MSTARTED;
	volatile	uint32_t	RESERVED7[86];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	INTPEND;
	volatile	uint32_t	RESERVED8[62];
	volatile	uint32_t	HFCLKRUN;
	volatile	uint32_t	HFCLKSTAT;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	LFCLKRUN;
	volatile	uint32_t	LFCLKSTAT;
	volatile	uint32_t	LFCLKSRCCOPY;
	volatile	uint32_t	RESERVED10[12];
	volatile	uint32_t	HFCLKAUDIORUN;
	volatile	uint32_t	HFCLKAUDIOSTAT;
	volatile	uint32_t	HFCLK192MRUN;
	volatile	uint32_t	HFCLK192MSTAT;
	volatile	uint32_t	RESERVED11[45];
	volatile	uint32_t	HFCLKSRC;
	volatile	uint32_t	LFCLKSRC;
	volatile	uint32_t	RESERVED12[15];
	volatile	uint32_t	HFCLKCTRL;
	volatile	uint32_t	HFCLKAUDIO_FREQUENCY;
	volatile	uint32_t	RESERVED13[4];
	volatile	uint32_t	HFCLKALWAYSRUN;
	volatile	uint32_t	LFCLKALWAYSRUN;
	volatile	uint32_t	RESERVED14;
	volatile	uint32_t	HFCLKAUDIOALWAYSRUN;
	volatile	uint32_t	HFCLK192MSRC;
	volatile	uint32_t	HFCLK192MALWAYSRUN;
	volatile	uint32_t	RESERVED15[12];
	volatile	uint32_t	HFCLK192MCTRL;
} CLOCK_TypeDef;

#if (defined(__cplusplus))
#define	CLOCK_NS	reinterpret_cast<CLOCK_TypeDef *>(0x40005000u)
#define	CLOCK_S		reinterpret_cast<CLOCK_TypeDef *>(0x50005000u)

#else
#define	CLOCK_NS	((CLOCK_TypeDef *)0x40005000u)
#define	CLOCK_S		((CLOCK_TypeDef *)0x50005000u)
#endif

// TASKS_HFCLKSTART Configuration

#define	CLOCK_TASKS_HFCLKSTART_TASKS_HFCLKSTART									(0x1u<<0)
#define	CLOCK_TASKS_HFCLKSTART_TASKS_HFCLKSTART_TRIGGER							(0x1u<<0)

// TASKS_HFCLKSTOP Configuration

#define	CLOCK_TASKS_HFCLKSTOP_TASKS_HFCLKSTOP									(0x1u<<0)
#define	CLOCK_TASKS_HFCLKSTOP_TASKS_HFCLKSTOP_TRIGGER							(0x1u<<0)

// TASKS_LFCLKSTART Configuration

#define	CLOCK_TASKS_LFCLKSTART_TASKS_LFCLKSTART									(0x1u<<0)
#define	CLOCK_TASKS_LFCLKSTART_TASKS_LFCLKSTART_TRIGGER							(0x1u<<0)

// TASKS_LFCLKSTOP Configuration

#define	CLOCK_TASKS_LFCLKSTOP_TASKS_LFCLKSTOP									(0x1u<<0)
#define	CLOCK_TASKS_LFCLKSTOP_TASKS_LFCLKSTOP_TRIGGER							(0x1u<<0)

// TASKS_CAL Configuration

#define	CLOCK_TASKS_CAL_TASKS_CAL												(0x1u<<0)
#define	CLOCK_TASKS_CAL_TASKS_CAL_TRIGGER										(0x1u<<0)

// TASKS_HFCLKAUDIOSTART Configuration

#define	CLOCK_TASKS_HFCLKAUDIOSTART_TASKS_HFCLKAUDIOSTART						(0x1u<<0)
#define	CLOCK_TASKS_HFCLKAUDIOSTART_TASKS_HFCLKAUDIOSTART_TRIGGER				(0x1u<<0)

// TASKS_HFCLKAUDIOSTOP Configuration

#define	CLOCK_TASKS_HFCLKAUDIOSTOP_TASKS_HFCLKAUDIOSTOP							(0x1u<<0)
#define	CLOCK_TASKS_HFCLKAUDIOSTOP_TASKS_HFCLKAUDIOSTOP_TRIGGER					(0x1u<<0)

// TASKS_HFCLK192MSTART Configuration

#define	CLOCK_TASKS_HFCLK192MSTART_TASKS_HFCLK192MSTART							(0x1u<<0)
#define	CLOCK_TASKS_HFCLK192MSTART_TASKS_HFCLK192MSTART_TRIGGER					(0x1u<<0)

// TASKS_HFCLK192MSTOP Configuration

#define	CLOCK_TASKS_HFCLK192MSTOP_TASKS_HFCLK192MSTOP							(0x1u<<0)
#define	CLOCK_TASKS_HFCLK192MSTOP_TASKS_HFCLK192MSTOP_TRIGGER					(0x1u<<0)

// SUBSCRIBE_HFCLKSTART Configuration

#define	CLOCK_SUBSCRIBE_HFCLKSTART_EN											(0x1u<<31)
#define	CLOCK_SUBSCRIBE_HFCLKSTART_CHIDX										(0xFFu<<0)
#define	CLOCK_SUBSCRIBE_HFCLKSTART_CHIDX_0										(0x1u<<0)
#define	CLOCK_SUBSCRIBE_HFCLKSTART_EN_DISABLED									(0x0u<<31)
#define	CLOCK_SUBSCRIBE_HFCLKSTART_EN_ENABLED									(0x1u<<31)

// SUBSCRIBE_HFCLKSTOP Configuration

#define	CLOCK_SUBSCRIBE_HFCLKSTOP_EN											(0x1u<<31)
#define	CLOCK_SUBSCRIBE_HFCLKSTOP_CHIDX											(0xFFu<<0)
#define	CLOCK_SUBSCRIBE_HFCLKSTOP_CHIDX_0										(0x1u<<0)
#define	CLOCK_SUBSCRIBE_HFCLKSTOP_EN_DISABLED									(0x0u<<31)
#define	CLOCK_SUBSCRIBE_HFCLKSTOP_EN_ENABLED									(0x1u<<31)

// SUBSCRIBE_LFCLKSTART Configuration

#define	CLOCK_SUBSCRIBE_LFCLKSTART_EN											(0x1u<<31)
#define	CLOCK_SUBSCRIBE_LFCLKSTART_CHIDX										(0xFFu<<0)
#define	CLOCK_SUBSCRIBE_LFCLKSTART_CHIDX_0										(0x1u<<0)
#define	CLOCK_SUBSCRIBE_LFCLKSTART_EN_DISABLED									(0x0u<<31)
#define	CLOCK_SUBSCRIBE_LFCLKSTART_EN_ENABLED									(0x1u<<31)

// SUBSCRIBE_LFCLKSTOP Configuration

#define	CLOCK_SUBSCRIBE_LFCLKSTOP_EN											(0x1u<<31)
#define	CLOCK_SUBSCRIBE_LFCLKSTOP_CHIDX											(0xFFu<<0)
#define	CLOCK_SUBSCRIBE_LFCLKSTOP_CHIDX_0										(0x1u<<0)
#define	CLOCK_SUBSCRIBE_LFCLKSTOP_EN_DISABLED									(0x0u<<31)
#define	CLOCK_SUBSCRIBE_LFCLKSTOP_EN_ENABLED									(0x1u<<31)

// SUBSCRIBE_CAL Configuration

#define	CLOCK_SUBSCRIBE_CAL_EN													(0x1u<<31)
#define	CLOCK_SUBSCRIBE_CAL_CHIDX												(0xFFu<<0)
#define	CLOCK_SUBSCRIBE_CAL_CHIDX_0												(0x1u<<0)
#define	CLOCK_SUBSCRIBE_CAL_EN_DISABLED											(0x0u<<31)
#define	CLOCK_SUBSCRIBE_CAL_EN_ENABLED											(0x1u<<31)

// SUBSCRIBE_HFCLKAUDIOSTART Configuration

#define	CLOCK_SUBSCRIBE_HFCLKAUDIOSTART_EN										(0x1u<<31)
#define	CLOCK_SUBSCRIBE_HFCLKAUDIOSTART_CHIDX									(0xFFu<<0)
#define	CLOCK_SUBSCRIBE_HFCLKAUDIOSTART_CHIDX_0									(0x1u<<0)
#define	CLOCK_SUBSCRIBE_HFCLKAUDIOSTART_EN_DISABLED								(0x0u<<31)
#define	CLOCK_SUBSCRIBE_HFCLKAUDIOSTART_EN_ENABLED								(0x1u<<31)

// SUBSCRIBE_HFCLKAUDIOSTOP Configuration

#define	CLOCK_SUBSCRIBE_HFCLKAUDIOSTOP_EN										(0x1u<<31)
#define	CLOCK_SUBSCRIBE_HFCLKAUDIOSTOP_CHIDX									(0xFFu<<0)
#define	CLOCK_SUBSCRIBE_HFCLKAUDIOSTOP_CHIDX_0									(0x1u<<0)
#define	CLOCK_SUBSCRIBE_HFCLKAUDIOSTOP_EN_DISABLED								(0x0u<<31)
#define	CLOCK_SUBSCRIBE_HFCLKAUDIOSTOP_EN_ENABLED								(0x1u<<31)

// SUBSCRIBE_HFCLK192MSTART Configuration

#define	CLOCK_SUBSCRIBE_HFCLK192MSTART_EN										(0x1u<<31)
#define	CLOCK_SUBSCRIBE_HFCLK192MSTART_CHIDX									(0xFFu<<0)
#define	CLOCK_SUBSCRIBE_HFCLK192MSTART_CHIDX_0									(0x1u<<0)
#define	CLOCK_SUBSCRIBE_HFCLK192MSTART_EN_DISABLED								(0x0u<<31)
#define	CLOCK_SUBSCRIBE_HFCLK192MSTART_EN_ENABLED								(0x1u<<31)

// SUBSCRIBE_HFCLK192MSTOP Configuration

#define	CLOCK_SUBSCRIBE_HFCLK192MSTOP_EN										(0x1u<<31)
#define	CLOCK_SUBSCRIBE_HFCLK192MSTOP_CHIDX										(0xFFu<<0)
#define	CLOCK_SUBSCRIBE_HFCLK192MSTOP_CHIDX_0									(0x1u<<0)
#define	CLOCK_SUBSCRIBE_HFCLK192MSTOP_EN_DISABLED								(0x0u<<31)
#define	CLOCK_SUBSCRIBE_HFCLK192MSTOP_EN_ENABLED								(0x1u<<31)

// EVENTS_HFCLKSTARTED Configuration

#define	CLOCK_EVENTS_HFCLKSTARTED_EVENTS_HFCLKSTARTED							(0x1u<<0)
#define	CLOCK_EVENTS_HFCLKSTARTED_EVENTS_HFCLKSTARTED_NOTGENERATED				(0x0u<<0)
#define	CLOCK_EVENTS_HFCLKSTARTED_EVENTS_HFCLKSTARTED_GENERATED					(0x1u<<0)

// EVENTS_LFCLKSTARTED Configuration

#define	CLOCK_EVENTS_LFCLKSTARTED_EVENTS_LFCLKSTARTED							(0x1u<<0)
#define	CLOCK_EVENTS_LFCLKSTARTED_EVENTS_LFCLKSTARTED_NOTGENERATED				(0x0u<<0)
#define	CLOCK_EVENTS_LFCLKSTARTED_EVENTS_LFCLKSTARTED_GENERATED					(0x1u<<0)

// EVENTS_DONE Configuration

#define	CLOCK_EVENTS_DONE_EVENTS_DONE											(0x1u<<0)
#define	CLOCK_EVENTS_DONE_EVENTS_DONE_NOTGENERATED								(0x0u<<0)
#define	CLOCK_EVENTS_DONE_EVENTS_DONE_GENERATED									(0x1u<<0)

// EVENTS_HFCLKAUDIOSTARTED Configuration

#define	CLOCK_EVENTS_HFCLKAUDIOSTARTED_EVENTS_HFCLKAUDIOSTARTED					(0x1u<<0)
#define	CLOCK_EVENTS_HFCLKAUDIOSTARTED_EVENTS_HFCLKAUDIOSTARTED_NOTGENERATED	(0x0u<<0)
#define	CLOCK_EVENTS_HFCLKAUDIOSTARTED_EVENTS_HFCLKAUDIOSTARTED_GENERATED		(0x1u<<0)

// EVENTS_HFCLK192MSTARTED Configuration

#define	CLOCK_EVENTS_HFCLK192MSTARTED_EVENTS_HFCLK192MSTARTED					(0x1u<<0)
#define	CLOCK_EVENTS_HFCLK192MSTARTED_EVENTS_HFCLK192MSTARTED_NOTGENERATED		(0x0u<<0)
#define	CLOCK_EVENTS_HFCLK192MSTARTED_EVENTS_HFCLK192MSTARTED_GENERATED			(0x1u<<0)

// PUBLISH_HFCLKSTARTED Configuration

#define	CLOCK_PUBLISH_HFCLKSTARTED_EN											(0x1u<<31)
#define	CLOCK_PUBLISH_HFCLKSTARTED_CHIDX										(0xFFu<<0)
#define	CLOCK_PUBLISH_HFCLKSTARTED_CHIDX_0										(0x1u<<0)
#define	CLOCK_PUBLISH_HFCLKSTARTED_EN_DISABLED									(0x0u<<31)
#define	CLOCK_PUBLISH_HFCLKSTARTED_EN_ENABLED									(0x1u<<31)

// PUBLISH_LFCLKSTARTED Configuration

#define	CLOCK_PUBLISH_LFCLKSTARTED_EN											(0x1u<<31)
#define	CLOCK_PUBLISH_LFCLKSTARTED_CHIDX										(0xFFu<<0)
#define	CLOCK_PUBLISH_LFCLKSTARTED_CHIDX_0										(0x1u<<0)
#define	CLOCK_PUBLISH_LFCLKSTARTED_EN_DISABLED									(0x0u<<31)
#define	CLOCK_PUBLISH_LFCLKSTARTED_EN_ENABLED									(0x1u<<31)

// PUBLISH_DONE Configuration

#define	CLOCK_PUBLISH_DONE_EN													(0x1u<<31)
#define	CLOCK_PUBLISH_DONE_CHIDX												(0xFFu<<0)
#define	CLOCK_PUBLISH_DONE_CHIDX_0												(0x1u<<0)
#define	CLOCK_PUBLISH_DONE_EN_DISABLED											(0x0u<<31)
#define	CLOCK_PUBLISH_DONE_EN_ENABLED											(0x1u<<31)

// PUBLISH_HFCLKAUDIOSTARTED Configuration

#define	CLOCK_PUBLISH_HFCLKAUDIOSTARTED_EN										(0x1u<<31)
#define	CLOCK_PUBLISH_HFCLKAUDIOSTARTED_CHIDX									(0xFFu<<0)
#define	CLOCK_PUBLISH_HFCLKAUDIOSTARTED_CHIDX_0									(0x1u<<0)
#define	CLOCK_PUBLISH_HFCLKAUDIOSTARTED_EN_DISABLED								(0x0u<<31)
#define	CLOCK_PUBLISH_HFCLKAUDIOSTARTED_EN_ENABLED								(0x1u<<31)

// PUBLISH_HFCLK192MSTARTED Configuration

#define	CLOCK_PUBLISH_HFCLK192MSTARTED_EN										(0x1u<<31)
#define	CLOCK_PUBLISH_HFCLK192MSTARTED_CHIDX									(0xFFu<<0)
#define	CLOCK_PUBLISH_HFCLK192MSTARTED_CHIDX_0									(0x1u<<0)
#define	CLOCK_PUBLISH_HFCLK192MSTARTED_EN_DISABLED								(0x0u<<31)
#define	CLOCK_PUBLISH_HFCLK192MSTARTED_EN_ENABLED								(0x1u<<31)

// INTEN Configuration

#define	CLOCK_INTEN_HFCLK192MSTARTED											(0x1u<<9)
#define	CLOCK_INTEN_HFCLKAUDIOSTARTED											(0x1u<<8)
#define	CLOCK_INTEN_DONE														(0x1u<<7)
#define	CLOCK_INTEN_LFCLKSTARTED												(0x1u<<1)
#define	CLOCK_INTEN_HFCLKSTARTED												(0x1u<<0)
#define	CLOCK_INTEN_HFCLK192MSTARTED_DISABLED									(0x0u<<9)
#define	CLOCK_INTEN_HFCLK192MSTARTED_ENABLED									(0x1u<<9)
#define	CLOCK_INTEN_HFCLKAUDIOSTARTED_DISABLED									(0x0u<<8)
#define	CLOCK_INTEN_HFCLKAUDIOSTARTED_ENABLED									(0x1u<<8)
#define	CLOCK_INTEN_DONE_DISABLED												(0x0u<<7)
#define	CLOCK_INTEN_DONE_ENABLED												(0x1u<<7)
#define	CLOCK_INTEN_LFCLKSTARTED_DISABLED										(0x0u<<1)
#define	CLOCK_INTEN_LFCLKSTARTED_ENABLED										(0x1u<<1)
#define	CLOCK_INTEN_HFCLKSTARTED_DISABLED										(0x0u<<0)
#define	CLOCK_INTEN_HFCLKSTARTED_ENABLED										(0x1u<<0)

// INTENSET Configuration

#define	CLOCK_INTENSET_HFCLK192MSTARTED											(0x1u<<9)
#define	CLOCK_INTENSET_HFCLKAUDIOSTARTED										(0x1u<<8)
#define	CLOCK_INTENSET_DONE														(0x1u<<7)
#define	CLOCK_INTENSET_LFCLKSTARTED												(0x1u<<1)
#define	CLOCK_INTENSET_HFCLKSTARTED												(0x1u<<0)
#define	CLOCK_INTENSET_HFCLK192MSTARTED_DISABLED								(0x0u<<9)
#define	CLOCK_INTENSET_HFCLK192MSTARTED_ENABLED									(0x1u<<9)
#define	CLOCK_INTENSET_HFCLK192MSTARTED_SET										(0x1u<<9)
#define	CLOCK_INTENSET_HFCLKAUDIOSTARTED_DISABLED								(0x0u<<8)
#define	CLOCK_INTENSET_HFCLKAUDIOSTARTED_ENABLED								(0x1u<<8)
#define	CLOCK_INTENSET_HFCLKAUDIOSTARTED_SET									(0x1u<<8)
#define	CLOCK_INTENSET_DONE_DISABLED											(0x0u<<7)
#define	CLOCK_INTENSET_DONE_ENABLED												(0x1u<<7)
#define	CLOCK_INTENSET_DONE_SET													(0x1u<<7)
#define	CLOCK_INTENSET_LFCLKSTARTED_DISABLED									(0x0u<<1)
#define	CLOCK_INTENSET_LFCLKSTARTED_ENABLED										(0x1u<<1)
#define	CLOCK_INTENSET_LFCLKSTARTED_SET											(0x1u<<1)
#define	CLOCK_INTENSET_HFCLKSTARTED_DISABLED									(0x0u<<0)
#define	CLOCK_INTENSET_HFCLKSTARTED_ENABLED										(0x1u<<0)
#define	CLOCK_INTENSET_HFCLKSTARTED_SET											(0x1u<<0)

// INTENCLR Configuration

#define	CLOCK_INTENCLR_HFCLK192MSTARTED											(0x1u<<9)
#define	CLOCK_INTENCLR_HFCLKAUDIOSTARTED										(0x1u<<8)
#define	CLOCK_INTENCLR_DONE														(0x1u<<7)
#define	CLOCK_INTENCLR_LFCLKSTARTED												(0x1u<<1)
#define	CLOCK_INTENCLR_HFCLKSTARTED												(0x1u<<0)
#define	CLOCK_INTENCLR_HFCLK192MSTARTED_DISABLED								(0x0u<<9)
#define	CLOCK_INTENCLR_HFCLK192MSTARTED_ENABLED									(0x1u<<9)
#define	CLOCK_INTENCLR_HFCLK192MSTARTED_CLEAR									(0x1u<<9)
#define	CLOCK_INTENCLR_HFCLKAUDIOSTARTED_DISABLED								(0x0u<<8)
#define	CLOCK_INTENCLR_HFCLKAUDIOSTARTED_ENABLED								(0x1u<<8)
#define	CLOCK_INTENCLR_HFCLKAUDIOSTARTED_CLEAR									(0x1u<<8)
#define	CLOCK_INTENCLR_DONE_DISABLED											(0x0u<<7)
#define	CLOCK_INTENCLR_DONE_ENABLED												(0x1u<<7)
#define	CLOCK_INTENCLR_DONE_CLEAR												(0x1u<<7)
#define	CLOCK_INTENCLR_LFCLKSTARTED_DISABLED									(0x0u<<1)
#define	CLOCK_INTENCLR_LFCLKSTARTED_ENABLED										(0x1u<<1)
#define	CLOCK_INTENCLR_LFCLKSTARTED_CLEAR										(0x1u<<1)
#define	CLOCK_INTENCLR_HFCLKSTARTED_DISABLED									(0x0u<<0)
#define	CLOCK_INTENCLR_HFCLKSTARTED_ENABLED										(0x1u<<0)
#define	CLOCK_INTENCLR_HFCLKSTARTED_CLEAR										(0x1u<<0)

// INTPEND Configuration

#define	CLOCK_INTPEND_HFCLK192MSTARTED											(0x1u<<9)
#define	CLOCK_INTPEND_HFCLKAUDIOSTARTED											(0x1u<<8)
#define	CLOCK_INTPEND_DONE														(0x1u<<7)
#define	CLOCK_INTPEND_LFCLKSTARTED												(0x1u<<1)
#define	CLOCK_INTPEND_HFCLKSTARTED												(0x1u<<0)
#define	CLOCK_INTPEND_HFCLK192MSTARTED_NOTPENDING								(0x0u<<9)
#define	CLOCK_INTPEND_HFCLK192MSTARTED_PENDING									(0x1u<<9)
#define	CLOCK_INTPEND_HFCLKAUDIOSTARTED_NOTPENDING								(0x0u<<8)
#define	CLOCK_INTPEND_HFCLKAUDIOSTARTED_PENDING									(0x1u<<8)
#define	CLOCK_INTPEND_DONE_NOTPENDING											(0x0u<<7)
#define	CLOCK_INTPEND_DONE_PENDING												(0x1u<<7)
#define	CLOCK_INTPEND_LFCLKSTARTED_NOTPENDING									(0x0u<<1)
#define	CLOCK_INTPEND_LFCLKSTARTED_PENDING										(0x1u<<1)
#define	CLOCK_INTPEND_HFCLKSTARTED_NOTPENDING									(0x0u<<0)
#define	CLOCK_INTPEND_HFCLKSTARTED_PENDING										(0x1u<<0)

// HFCLKRUN Configuration

#define	CLOCK_HFCLKRUN_STATUS													(0x1u<<0)
#define	CLOCK_HFCLKRUN_STATUS_NOTTRIGGERED										(0x0u<<0)
#define	CLOCK_HFCLKRUN_STATUS_TRIGGERED											(0x1u<<0)

// HFCLKSTAT Configuration

#define	CLOCK_HFCLKSTAT_STATE													(0x1u<<16)
#define	CLOCK_HFCLKSTAT_ALWAYSRUNNING											(0x1u<<4)
#define	CLOCK_HFCLKSTAT_SRC														(0x1u<<0)
#define	CLOCK_HFCLKSTAT_STATE_NOTRUNNING										(0x0u<<16)
#define	CLOCK_HFCLKSTAT_STATE_RUNNING											(0x1u<<16)
#define	CLOCK_HFCLKSTAT_ALWAYSRUNNING_NOTRUNNING								(0x0u<<4)
#define	CLOCK_HFCLKSTAT_ALWAYSRUNNING_RUNNING									(0x1u<<4)
#define	CLOCK_HFCLKSTAT_SRC_HFINT												(0x0u<<0)
#define	CLOCK_HFCLKSTAT_SRC_HFXO												(0x1u<<0)

// LFCLKRUN Configuration

#define	CLOCK_LFCLKRUN_STATUS													(0x1u<<0)
#define	CLOCK_LFCLKRUN_STATUS_NOTTRIGGERED										(0x0u<<0)
#define	CLOCK_LFCLKRUN_STATUS_TRIGGERED											(0x1u<<0)

// LFCLKSTAT Configuration

#define	CLOCK_LFCLKSTAT_STATE													(0x1u<<16)
#define	CLOCK_LFCLKSTAT_ALWAYSRUNNING											(0x1u<<4)
#define	CLOCK_LFCLKSTAT_SRC														(0x3u<<0)
#define	CLOCK_LFCLKSTAT_SRC_0													(0x1u<<0)
#define	CLOCK_LFCLKSTAT_STATE_NOTRUNNING										(0x0u<<16)
#define	CLOCK_LFCLKSTAT_STATE_RUNNING											(0x1u<<16)
#define	CLOCK_LFCLKSTAT_ALWAYSRUNNING_NOTRUNNING								(0x0u<<4)
#define	CLOCK_LFCLKSTAT_ALWAYSRUNNING_RUNNING									(0x1u<<4)
#define	CLOCK_LFCLKSTAT_SRC_LFRC												(0x1u<<0)
#define	CLOCK_LFCLKSTAT_SRC_LFXO												(0x2u<<0)
#define	CLOCK_LFCLKSTAT_SRC_LFSYNT												(0x3u<<0)

// LFCLKSRCCOPY Configuration

#define	CLOCK_LFCLKSRCCOPY_SRC													(0x3u<<0)
#define	CLOCK_LFCLKSRCCOPY_SRC_0												(0x1u<<0)
#define	CLOCK_LFCLKSRCCOPY_SRC_LFRC												(0x1u<<0)
#define	CLOCK_LFCLKSRCCOPY_SRC_LFXO												(0x2u<<0)
#define	CLOCK_LFCLKSRCCOPY_SRC_LFSYNT											(0x3u<<0)

// HFCLKAUDIORUN Configuration

#define	CLOCK_HFCLKAUDIORUN_STATUS												(0x1u<<0)
#define	CLOCK_HFCLKAUDIORUN_STATUS_NOTTRIGGERED									(0x0u<<0)
#define	CLOCK_HFCLKAUDIORUN_STATUS_TRIGGERED									(0x1u<<0)

// HFCLKAUDIOSTAT Configuration

#define	CLOCK_HFCLKAUDIOSTAT_STATE												(0x1u<<16)
#define	CLOCK_HFCLKAUDIOSTAT_ALWAYSRUNNING										(0x1u<<4)
#define	CLOCK_HFCLKAUDIOSTAT_STATE_NOTRUNNING									(0x0u<<16)
#define	CLOCK_HFCLKAUDIOSTAT_STATE_RUNNING										(0x1u<<16)
#define	CLOCK_HFCLKAUDIOSTAT_ALWAYSRUNNING_NOTRUNNING							(0x0u<<4)
#define	CLOCK_HFCLKAUDIOSTAT_ALWAYSRUNNING_RUNNING								(0x1u<<4)

// HFCLK192MRUN Configuration

#define	CLOCK_HFCLK192MRUN_STATUS												(0x1u<<0)
#define	CLOCK_HFCLK192MRUN_STATUS_NOTTRIGGERED									(0x0u<<0)
#define	CLOCK_HFCLK192MRUN_STATUS_TRIGGERED										(0x1u<<0)

// HFCLK192MSTAT Configuration

#define	CLOCK_HFCLK192MSTAT_STATE												(0x1u<<16)
#define	CLOCK_HFCLK192MSTAT_ALWAYSRUNNING										(0x1u<<4)
#define	CLOCK_HFCLK192MSTAT_SRC													(0x1u<<0)
#define	CLOCK_HFCLK192MSTAT_STATE_NOTRUNNING									(0x0u<<16)
#define	CLOCK_HFCLK192MSTAT_STATE_RUNNING										(0x1u<<16)
#define	CLOCK_HFCLK192MSTAT_ALWAYSRUNNING_NOTRUNNING							(0x0u<<4)
#define	CLOCK_HFCLK192MSTAT_ALWAYSRUNNING_RUNNING								(0x1u<<4)
#define	CLOCK_HFCLK192MSTAT_SRC_HFINT											(0x0u<<0)
#define	CLOCK_HFCLK192MSTAT_SRC_HFXO											(0x1u<<0)

// HFCLKSRC Configuration

#define	CLOCK_HFCLKSRC_SRC														(0x1u<<0)
#define	CLOCK_HFCLKSRC_SRC_HFINT												(0x0u<<0)
#define	CLOCK_HFCLKSRC_SRC_HFXO													(0x1u<<0)

// LFCLKSRC Configuration

#define	CLOCK_LFCLKSRC_SRC														(0x3u<<0)
#define	CLOCK_LFCLKSRC_SRC_0													(0x1u<<0)
#define	CLOCK_LFCLKSRC_SRC_LFRC													(0x1u<<0)
#define	CLOCK_LFCLKSRC_SRC_LFXO													(0x2u<<0)
#define	CLOCK_LFCLKSRC_SRC_LFSYNT												(0x3u<<0)

// HFCLKCTRL Configuration

#define	CLOCK_HFCLKCTRL_HCLK													(0x3u<<0)
#define	CLOCK_HFCLKCTRL_HCLK_0													(0x1u<<0)
#define	CLOCK_HFCLKCTRL_HCLK_DIV1												(0x0u<<0)
#define	CLOCK_HFCLKCTRL_HCLK_DIV2												(0x1u<<0)

// FREQUENCY Configuration

#define	CLOCK_HFCLKAUDIO_FREQUENCY_FREQUENCY									(0xFFFFu<<0)
#define	CLOCK_HFCLKAUDIO_FREQUENCY_FREQUENCY_0									(0x1u<<0)

// HFCLKALWAYSRUN Configuration

#define	CLOCK_HFCLKALWAYSRUN_ALWAYSRUN											(0x1u<<0)
#define	CLOCK_HFCLKALWAYSRUN_ALWAYSRUN_AUTOMATIC								(0x0u<<0)
#define	CLOCK_HFCLKALWAYSRUN_ALWAYSRUN_ALWAYSRUN								(0x1u<<0)

// LFCLKALWAYSRUN Configuration

#define	CLOCK_LFCLKALWAYSRUN_ALWAYSRUN											(0x1u<<0)
#define	CLOCK_LFCLKALWAYSRUN_ALWAYSRUN_AUTOMATIC								(0x0u<<0)
#define	CLOCK_LFCLKALWAYSRUN_ALWAYSRUN_ALWAYSRUN								(0x1u<<0)

// HFCLKAUDIOALWAYSRUN Configuration

#define	CLOCK_HFCLKAUDIOALWAYSRUN_ALWAYSRUN										(0x1u<<0)
#define	CLOCK_HFCLKAUDIOALWAYSRUN_ALWAYSRUN_AUTOMATIC							(0x0u<<0)
#define	CLOCK_HFCLKAUDIOALWAYSRUN_ALWAYSRUN_ALWAYSRUN							(0x1u<<0)

// HFCLK192MSRC Configuration

#define	CLOCK_HFCLK192MSRC_SRC													(0x1u<<0)
#define	CLOCK_HFCLK192MSRC_SRC_HFINT											(0x0u<<0)
#define	CLOCK_HFCLK192MSRC_SRC_HFXO												(0x1u<<0)

// HFCLK192MALWAYSRUN Configuration

#define	CLOCK_HFCLK192MALWAYSRUN_ALWAYSRUN										(0x1u<<0)
#define	CLOCK_HFCLK192MALWAYSRUN_ALWAYSRUN_AUTOMATIC							(0x0u<<0)
#define	CLOCK_HFCLK192MALWAYSRUN_ALWAYSRUN_ALWAYSRUN							(0x1u<<0)

// HFCLK192MCTRL Configuration

#define	CLOCK_HFCLK192MCTRL_HCLK192M											(0x3u<<0)
#define	CLOCK_HFCLK192MCTRL_HCLK192M_0											(0x1u<<0)
#define	CLOCK_HFCLK192MCTRL_HCLK192M_DIV1										(0x0u<<0)
#define	CLOCK_HFCLK192MCTRL_HCLK192M_DIV2										(0x1u<<0)
#define	CLOCK_HFCLK192MCTRL_HCLK192M_DIV4										(0x2u<<0)
