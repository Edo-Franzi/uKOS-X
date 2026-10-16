/*
; nrf5340_network_aar.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_network_aar equates.
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

// AAR address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	TASKS_START;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	RESERVED1[29];
	volatile	uint32_t	SUBSCRIBE_START;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	RESERVED3[29];
	volatile	uint32_t	EVENTS_END;
	volatile	uint32_t	EVENTS_RESOLVED;
	volatile	uint32_t	EVENTS_NOTRESOLVED;
	volatile	uint32_t	RESERVED4[29];
	volatile	uint32_t	PUBLISH_END;
	volatile	uint32_t	PUBLISH_RESOLVED;
	volatile	uint32_t	PUBLISH_NOTRESOLVED;
	volatile	uint32_t	RESERVED5[94];
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED6[61];
	volatile	uint32_t	STATUS;
	volatile	uint32_t	RESERVED7[63];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	NIRK;
	volatile	uint32_t	IRKPTR;
	volatile	uint32_t	RESERVED8;
	volatile	uint32_t	ADDRPTR;
	volatile	uint32_t	SCRATCHPTR;
} AAR_TypeDef;

#if (defined(__cplusplus))
#define	AAR_NS	reinterpret_cast<AAR_TypeDef *>(0x4100E000u)

#else
#define	AAR_NS	((AAR_TypeDef *)0x4100E000u)
#endif

// TASKS_START Configuration

#define	AAR_TASKS_START_TASKS_START								(0x1u<<0)
#define	AAR_TASKS_START_TASKS_START_TRIGGER						(0x1u<<0)

// TASKS_STOP Configuration

#define	AAR_TASKS_STOP_TASKS_STOP								(0x1u<<0)
#define	AAR_TASKS_STOP_TASKS_STOP_TRIGGER						(0x1u<<0)

// SUBSCRIBE_START Configuration

#define	AAR_SUBSCRIBE_START_EN									(0x1u<<31)
#define	AAR_SUBSCRIBE_START_CHIDX								(0xFFu<<0)
#define	AAR_SUBSCRIBE_START_CHIDX_0								(0x1u<<0)
#define	AAR_SUBSCRIBE_START_EN_DISABLED							(0x0u<<31)
#define	AAR_SUBSCRIBE_START_EN_ENABLED							(0x1u<<31)

// SUBSCRIBE_STOP Configuration

#define	AAR_SUBSCRIBE_STOP_EN									(0x1u<<31)
#define	AAR_SUBSCRIBE_STOP_CHIDX								(0xFFu<<0)
#define	AAR_SUBSCRIBE_STOP_CHIDX_0								(0x1u<<0)
#define	AAR_SUBSCRIBE_STOP_EN_DISABLED							(0x0u<<31)
#define	AAR_SUBSCRIBE_STOP_EN_ENABLED							(0x1u<<31)

// EVENTS_END Configuration

#define	AAR_EVENTS_END_EVENTS_END								(0x1u<<0)
#define	AAR_EVENTS_END_EVENTS_END_NOTGENERATED					(0x0u<<0)
#define	AAR_EVENTS_END_EVENTS_END_GENERATED						(0x1u<<0)

// EVENTS_RESOLVED Configuration

#define	AAR_EVENTS_RESOLVED_EVENTS_RESOLVED						(0x1u<<0)
#define	AAR_EVENTS_RESOLVED_EVENTS_RESOLVED_NOTGENERATED		(0x0u<<0)
#define	AAR_EVENTS_RESOLVED_EVENTS_RESOLVED_GENERATED			(0x1u<<0)

// EVENTS_NOTRESOLVED Configuration

#define	AAR_EVENTS_NOTRESOLVED_EVENTS_NOTRESOLVED				(0x1u<<0)
#define	AAR_EVENTS_NOTRESOLVED_EVENTS_NOTRESOLVED_NOTGENERATED	(0x0u<<0)
#define	AAR_EVENTS_NOTRESOLVED_EVENTS_NOTRESOLVED_GENERATED		(0x1u<<0)

// PUBLISH_END Configuration

#define	AAR_PUBLISH_END_EN										(0x1u<<31)
#define	AAR_PUBLISH_END_CHIDX									(0xFFu<<0)
#define	AAR_PUBLISH_END_CHIDX_0									(0x1u<<0)
#define	AAR_PUBLISH_END_EN_DISABLED								(0x0u<<31)
#define	AAR_PUBLISH_END_EN_ENABLED								(0x1u<<31)

// PUBLISH_RESOLVED Configuration

#define	AAR_PUBLISH_RESOLVED_EN									(0x1u<<31)
#define	AAR_PUBLISH_RESOLVED_CHIDX								(0xFFu<<0)
#define	AAR_PUBLISH_RESOLVED_CHIDX_0							(0x1u<<0)
#define	AAR_PUBLISH_RESOLVED_EN_DISABLED						(0x0u<<31)
#define	AAR_PUBLISH_RESOLVED_EN_ENABLED							(0x1u<<31)

// PUBLISH_NOTRESOLVED Configuration

#define	AAR_PUBLISH_NOTRESOLVED_EN								(0x1u<<31)
#define	AAR_PUBLISH_NOTRESOLVED_CHIDX							(0xFFu<<0)
#define	AAR_PUBLISH_NOTRESOLVED_CHIDX_0							(0x1u<<0)
#define	AAR_PUBLISH_NOTRESOLVED_EN_DISABLED						(0x0u<<31)
#define	AAR_PUBLISH_NOTRESOLVED_EN_ENABLED						(0x1u<<31)

// INTENSET Configuration

#define	AAR_INTENSET_NOTRESOLVED								(0x1u<<2)
#define	AAR_INTENSET_RESOLVED									(0x1u<<1)
#define	AAR_INTENSET_END										(0x1u<<0)
#define	AAR_INTENSET_NOTRESOLVED_DISABLED						(0x0u<<2)
#define	AAR_INTENSET_NOTRESOLVED_ENABLED						(0x1u<<2)
#define	AAR_INTENSET_NOTRESOLVED_SET							(0x1u<<2)
#define	AAR_INTENSET_RESOLVED_DISABLED							(0x0u<<1)
#define	AAR_INTENSET_RESOLVED_ENABLED							(0x1u<<1)
#define	AAR_INTENSET_RESOLVED_SET								(0x1u<<1)
#define	AAR_INTENSET_END_DISABLED								(0x0u<<0)
#define	AAR_INTENSET_END_ENABLED								(0x1u<<0)
#define	AAR_INTENSET_END_SET									(0x1u<<0)

// INTENCLR Configuration

#define	AAR_INTENCLR_NOTRESOLVED								(0x1u<<2)
#define	AAR_INTENCLR_RESOLVED									(0x1u<<1)
#define	AAR_INTENCLR_END										(0x1u<<0)
#define	AAR_INTENCLR_NOTRESOLVED_DISABLED						(0x0u<<2)
#define	AAR_INTENCLR_NOTRESOLVED_ENABLED						(0x1u<<2)
#define	AAR_INTENCLR_NOTRESOLVED_CLEAR							(0x1u<<2)
#define	AAR_INTENCLR_RESOLVED_DISABLED							(0x0u<<1)
#define	AAR_INTENCLR_RESOLVED_ENABLED							(0x1u<<1)
#define	AAR_INTENCLR_RESOLVED_CLEAR								(0x1u<<1)
#define	AAR_INTENCLR_END_DISABLED								(0x0u<<0)
#define	AAR_INTENCLR_END_ENABLED								(0x1u<<0)
#define	AAR_INTENCLR_END_CLEAR									(0x1u<<0)

// STATUS Configuration

#define	AAR_STATUS_STATUS										(0xFu<<0)
#define	AAR_STATUS_STATUS_0										(0x1u<<0)

// ENABLE Configuration

#define	AAR_ENABLE_ENABLE										(0x3u<<0)
#define	AAR_ENABLE_ENABLE_0										(0x1u<<0)
#define	AAR_ENABLE_ENABLE_DISABLED								(0x0u<<0)
#define	AAR_ENABLE_ENABLE_ENABLED								(0x3u<<0)

// NIRK Configuration

#define	AAR_NIRK_NIRK											(0x1Fu<<0)
#define	AAR_NIRK_NIRK_0											(0x1u<<0)

// IRKPTR Configuration

#define	AAR_IRKPTR_IRKPTR										(0xFFFFFFFFu<<0)
#define	AAR_IRKPTR_IRKPTR_0										(0x1u<<0)

// ADDRPTR Configuration

#define	AAR_ADDRPTR_ADDRPTR										(0xFFFFFFFFu<<0)
#define	AAR_ADDRPTR_ADDRPTR_0									(0x1u<<0)

// SCRATCHPTR Configuration

#define	AAR_SCRATCHPTR_SCRATCHPTR								(0xFFFFFFFFu<<0)
#define	AAR_SCRATCHPTR_SCRATCHPTR_0								(0x1u<<0)
