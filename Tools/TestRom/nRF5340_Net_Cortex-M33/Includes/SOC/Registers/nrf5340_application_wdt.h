/*
; nrf5340_application_wdt.
; ========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_wdt equates.
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

// WDT address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	TASKS_START;
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	RESERVED0[30];
	volatile	uint32_t	SUBSCRIBE_START;
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	RESERVED1[30];
	volatile	uint32_t	EVENTS_TIMEOUT;
	volatile	uint32_t	EVENTS_STOPPED;
	volatile	uint32_t	RESERVED2[30];
	volatile	uint32_t	PUBLISH_TIMEOUT;
	volatile	uint32_t	PUBLISH_STOPPED;
	volatile	uint32_t	RESERVED3[95];
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED4[6];
	volatile	uint32_t	NMIENSET;
	volatile	uint32_t	NMIENCLR;
	volatile	uint32_t	RESERVED5[53];
	volatile	uint32_t	RUNSTATUS;
	volatile	uint32_t	REQSTATUS;
	volatile	uint32_t	RESERVED6[63];
	volatile	uint32_t	CRV;
	volatile	uint32_t	RREN;
	volatile	uint32_t	CONFIG;
	volatile	uint32_t	RESERVED7[4];
	volatile	uint32_t	TSEN;
	volatile	uint32_t	RESERVED8[55];
	volatile	uint32_t	RR[8];
} WDT_TypeDef;

#if (defined(__cplusplus))
#define	WDT0_NS	reinterpret_cast<WDT_TypeDef *>(0x40018000u)
#define	WDT0_S	reinterpret_cast<WDT_TypeDef *>(0x50018000u)
#define	WDT1_NS	reinterpret_cast<WDT_TypeDef *>(0x40019000u)
#define	WDT1_S	reinterpret_cast<WDT_TypeDef *>(0x50019000u)

#else
#define	WDT0_NS	((WDT_TypeDef *)0x40018000u)
#define	WDT0_S	((WDT_TypeDef *)0x50018000u)
#define	WDT1_NS	((WDT_TypeDef *)0x40019000u)
#define	WDT1_S	((WDT_TypeDef *)0x50019000u)
#endif

// TASKS_START Configuration

#define	WDT_TASKS_START_TASKS_START						(0x1u<<0)
#define	WDT_TASKS_START_TASKS_START_TRIGGER				(0x1u<<0)

// TASKS_STOP Configuration

#define	WDT_TASKS_STOP_TASKS_STOP						(0x1u<<0)
#define	WDT_TASKS_STOP_TASKS_STOP_TRIGGER				(0x1u<<0)

// SUBSCRIBE_START Configuration

#define	WDT_SUBSCRIBE_START_EN							(0x1u<<31)
#define	WDT_SUBSCRIBE_START_CHIDX						(0xFFu<<0)
#define	WDT_SUBSCRIBE_START_CHIDX_0						(0x1u<<0)
#define	WDT_SUBSCRIBE_START_EN_DISABLED					(0x0u<<31)
#define	WDT_SUBSCRIBE_START_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_STOP Configuration

#define	WDT_SUBSCRIBE_STOP_EN							(0x1u<<31)
#define	WDT_SUBSCRIBE_STOP_CHIDX						(0xFFu<<0)
#define	WDT_SUBSCRIBE_STOP_CHIDX_0						(0x1u<<0)
#define	WDT_SUBSCRIBE_STOP_EN_DISABLED					(0x0u<<31)
#define	WDT_SUBSCRIBE_STOP_EN_ENABLED					(0x1u<<31)

// EVENTS_TIMEOUT Configuration

#define	WDT_EVENTS_TIMEOUT_EVENTS_TIMEOUT				(0x1u<<0)
#define	WDT_EVENTS_TIMEOUT_EVENTS_TIMEOUT_NOTGENERATED	(0x0u<<0)
#define	WDT_EVENTS_TIMEOUT_EVENTS_TIMEOUT_GENERATED		(0x1u<<0)

// EVENTS_STOPPED Configuration

#define	WDT_EVENTS_STOPPED_EVENTS_STOPPED				(0x1u<<0)
#define	WDT_EVENTS_STOPPED_EVENTS_STOPPED_NOTGENERATED	(0x0u<<0)
#define	WDT_EVENTS_STOPPED_EVENTS_STOPPED_GENERATED		(0x1u<<0)

// PUBLISH_TIMEOUT Configuration

#define	WDT_PUBLISH_TIMEOUT_EN							(0x1u<<31)
#define	WDT_PUBLISH_TIMEOUT_CHIDX						(0xFFu<<0)
#define	WDT_PUBLISH_TIMEOUT_CHIDX_0						(0x1u<<0)
#define	WDT_PUBLISH_TIMEOUT_EN_DISABLED					(0x0u<<31)
#define	WDT_PUBLISH_TIMEOUT_EN_ENABLED					(0x1u<<31)

// PUBLISH_STOPPED Configuration

#define	WDT_PUBLISH_STOPPED_EN							(0x1u<<31)
#define	WDT_PUBLISH_STOPPED_CHIDX						(0xFFu<<0)
#define	WDT_PUBLISH_STOPPED_CHIDX_0						(0x1u<<0)
#define	WDT_PUBLISH_STOPPED_EN_DISABLED					(0x0u<<31)
#define	WDT_PUBLISH_STOPPED_EN_ENABLED					(0x1u<<31)

// INTENSET Configuration

#define	WDT_INTENSET_STOPPED							(0x1u<<1)
#define	WDT_INTENSET_TIMEOUT							(0x1u<<0)
#define	WDT_INTENSET_STOPPED_DISABLED					(0x0u<<1)
#define	WDT_INTENSET_STOPPED_ENABLED					(0x1u<<1)
#define	WDT_INTENSET_STOPPED_SET						(0x1u<<1)
#define	WDT_INTENSET_TIMEOUT_DISABLED					(0x0u<<0)
#define	WDT_INTENSET_TIMEOUT_ENABLED					(0x1u<<0)
#define	WDT_INTENSET_TIMEOUT_SET						(0x1u<<0)

// INTENCLR Configuration

#define	WDT_INTENCLR_STOPPED							(0x1u<<1)
#define	WDT_INTENCLR_TIMEOUT							(0x1u<<0)
#define	WDT_INTENCLR_STOPPED_DISABLED					(0x0u<<1)
#define	WDT_INTENCLR_STOPPED_ENABLED					(0x1u<<1)
#define	WDT_INTENCLR_STOPPED_CLEAR						(0x1u<<1)
#define	WDT_INTENCLR_TIMEOUT_DISABLED					(0x0u<<0)
#define	WDT_INTENCLR_TIMEOUT_ENABLED					(0x1u<<0)
#define	WDT_INTENCLR_TIMEOUT_CLEAR						(0x1u<<0)

// NMIENSET Configuration

#define	WDT_NMIENSET_STOPPED							(0x1u<<1)
#define	WDT_NMIENSET_TIMEOUT							(0x1u<<0)
#define	WDT_NMIENSET_STOPPED_DISABLED					(0x0u<<1)
#define	WDT_NMIENSET_STOPPED_ENABLED					(0x1u<<1)
#define	WDT_NMIENSET_STOPPED_SET						(0x1u<<1)
#define	WDT_NMIENSET_TIMEOUT_DISABLED					(0x0u<<0)
#define	WDT_NMIENSET_TIMEOUT_ENABLED					(0x1u<<0)
#define	WDT_NMIENSET_TIMEOUT_SET						(0x1u<<0)

// NMIENCLR Configuration

#define	WDT_NMIENCLR_STOPPED							(0x1u<<1)
#define	WDT_NMIENCLR_TIMEOUT							(0x1u<<0)
#define	WDT_NMIENCLR_STOPPED_DISABLED					(0x0u<<1)
#define	WDT_NMIENCLR_STOPPED_ENABLED					(0x1u<<1)
#define	WDT_NMIENCLR_STOPPED_CLEAR						(0x1u<<1)
#define	WDT_NMIENCLR_TIMEOUT_DISABLED					(0x0u<<0)
#define	WDT_NMIENCLR_TIMEOUT_ENABLED					(0x1u<<0)
#define	WDT_NMIENCLR_TIMEOUT_CLEAR						(0x1u<<0)

// RUNSTATUS Configuration

#define	WDT_RUNSTATUS_RUNSTATUSWDT						(0x1u<<0)
#define	WDT_RUNSTATUS_RUNSTATUSWDT_NOTRUNNING			(0x0u<<0)
#define	WDT_RUNSTATUS_RUNSTATUSWDT_RUNNING				(0x1u<<0)

// REQSTATUS Configuration

#define	WDT_REQSTATUS_RR7								(0x1u<<7)
#define	WDT_REQSTATUS_RR6								(0x1u<<6)
#define	WDT_REQSTATUS_RR5								(0x1u<<5)
#define	WDT_REQSTATUS_RR4								(0x1u<<4)
#define	WDT_REQSTATUS_RR3								(0x1u<<3)
#define	WDT_REQSTATUS_RR2								(0x1u<<2)
#define	WDT_REQSTATUS_RR1								(0x1u<<1)
#define	WDT_REQSTATUS_RR0								(0x1u<<0)
#define	WDT_REQSTATUS_RR7_DISABLEDORREQUESTED			(0x0u<<7)
#define	WDT_REQSTATUS_RR7_ENABLEDANDUNREQUESTED			(0x1u<<7)
#define	WDT_REQSTATUS_RR6_DISABLEDORREQUESTED			(0x0u<<6)
#define	WDT_REQSTATUS_RR6_ENABLEDANDUNREQUESTED			(0x1u<<6)
#define	WDT_REQSTATUS_RR5_DISABLEDORREQUESTED			(0x0u<<5)
#define	WDT_REQSTATUS_RR5_ENABLEDANDUNREQUESTED			(0x1u<<5)
#define	WDT_REQSTATUS_RR4_DISABLEDORREQUESTED			(0x0u<<4)
#define	WDT_REQSTATUS_RR4_ENABLEDANDUNREQUESTED			(0x1u<<4)
#define	WDT_REQSTATUS_RR3_DISABLEDORREQUESTED			(0x0u<<3)
#define	WDT_REQSTATUS_RR3_ENABLEDANDUNREQUESTED			(0x1u<<3)
#define	WDT_REQSTATUS_RR2_DISABLEDORREQUESTED			(0x0u<<2)
#define	WDT_REQSTATUS_RR2_ENABLEDANDUNREQUESTED			(0x1u<<2)
#define	WDT_REQSTATUS_RR1_DISABLEDORREQUESTED			(0x0u<<1)
#define	WDT_REQSTATUS_RR1_ENABLEDANDUNREQUESTED			(0x1u<<1)
#define	WDT_REQSTATUS_RR0_DISABLEDORREQUESTED			(0x0u<<0)
#define	WDT_REQSTATUS_RR0_ENABLEDANDUNREQUESTED			(0x1u<<0)

// CRV Configuration

#define	WDT_CRV_CRV										(0xFFFFFFFFu<<0)
#define	WDT_CRV_CRV_0									(0x1u<<0)

// RREN Configuration

#define	WDT_RREN_RR7									(0x1u<<7)
#define	WDT_RREN_RR6									(0x1u<<6)
#define	WDT_RREN_RR5									(0x1u<<5)
#define	WDT_RREN_RR4									(0x1u<<4)
#define	WDT_RREN_RR3									(0x1u<<3)
#define	WDT_RREN_RR2									(0x1u<<2)
#define	WDT_RREN_RR1									(0x1u<<1)
#define	WDT_RREN_RR0									(0x1u<<0)
#define	WDT_RREN_RR7_DISABLED							(0x0u<<7)
#define	WDT_RREN_RR7_ENABLED							(0x1u<<7)
#define	WDT_RREN_RR6_DISABLED							(0x0u<<6)
#define	WDT_RREN_RR6_ENABLED							(0x1u<<6)
#define	WDT_RREN_RR5_DISABLED							(0x0u<<5)
#define	WDT_RREN_RR5_ENABLED							(0x1u<<5)
#define	WDT_RREN_RR4_DISABLED							(0x0u<<4)
#define	WDT_RREN_RR4_ENABLED							(0x1u<<4)
#define	WDT_RREN_RR3_DISABLED							(0x0u<<3)
#define	WDT_RREN_RR3_ENABLED							(0x1u<<3)
#define	WDT_RREN_RR2_DISABLED							(0x0u<<2)
#define	WDT_RREN_RR2_ENABLED							(0x1u<<2)
#define	WDT_RREN_RR1_DISABLED							(0x0u<<1)
#define	WDT_RREN_RR1_ENABLED							(0x1u<<1)
#define	WDT_RREN_RR0_DISABLED							(0x0u<<0)
#define	WDT_RREN_RR0_ENABLED							(0x1u<<0)

// CONFIG Configuration

#define	WDT_CONFIG_STOPEN								(0x1u<<6)
#define	WDT_CONFIG_HALT									(0x1u<<3)
#define	WDT_CONFIG_SLEEP								(0x1u<<0)
#define	WDT_CONFIG_STOPEN_DISABLE						(0x0u<<6)
#define	WDT_CONFIG_STOPEN_ENABLE						(0x1u<<6)
#define	WDT_CONFIG_HALT_PAUSE							(0x0u<<3)
#define	WDT_CONFIG_HALT_RUN								(0x1u<<3)
#define	WDT_CONFIG_SLEEP_PAUSE							(0x0u<<0)
#define	WDT_CONFIG_SLEEP_RUN							(0x1u<<0)

// TSEN Configuration

#define	WDT_TSEN_TSEN									(0xFFFFFFFFu<<0)
#define	WDT_TSEN_TSEN_0									(0x1u<<0)
#define	WDT_TSEN_TSEN_ENABLE							(0x6E524635u<<0)

// RR Configuration

#define	WDT_RR_RR										(0xFFFFFFFFu<<0)
#define	WDT_RR_RR_0										(0x1u<<0)
#define	WDT_RR_RR_RELOAD								(0x6E524635u<<0)
