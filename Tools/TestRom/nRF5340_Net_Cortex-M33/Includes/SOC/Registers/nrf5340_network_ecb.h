/*
; nrf5340_network_ecb.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_network_ecb equates.
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

// ECB address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	TASKS_STARTECB;
	volatile	uint32_t	TASKS_STOPECB;
	volatile	uint32_t	RESERVED0[30];
	volatile	uint32_t	SUBSCRIBE_STARTECB;
	volatile	uint32_t	SUBSCRIBE_STOPECB;
	volatile	uint32_t	RESERVED1[30];
	volatile	uint32_t	EVENTS_ENDECB;
	volatile	uint32_t	EVENTS_ERRORECB;
	volatile	uint32_t	RESERVED2[30];
	volatile	uint32_t	PUBLISH_ENDECB;
	volatile	uint32_t	PUBLISH_ERRORECB;
	volatile	uint32_t	RESERVED3[95];
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED4[126];
	volatile	uint32_t	ECBDATAPTR;
} ECB_TypeDef;

#if (defined(__cplusplus))
#define	ECB_NS	reinterpret_cast<ECB_TypeDef *>(0x4100D000u)

#else
#define	ECB_NS	((ECB_TypeDef *)0x4100D000u)
#endif

// TASKS_STARTECB Configuration

#define	ECB_TASKS_STARTECB_TASKS_STARTECB					(0x1u<<0)
#define	ECB_TASKS_STARTECB_TASKS_STARTECB_TRIGGER			(0x1u<<0)

// TASKS_STOPECB Configuration

#define	ECB_TASKS_STOPECB_TASKS_STOPECB						(0x1u<<0)
#define	ECB_TASKS_STOPECB_TASKS_STOPECB_TRIGGER				(0x1u<<0)

// SUBSCRIBE_STARTECB Configuration

#define	ECB_SUBSCRIBE_STARTECB_EN							(0x1u<<31)
#define	ECB_SUBSCRIBE_STARTECB_CHIDX						(0xFFu<<0)
#define	ECB_SUBSCRIBE_STARTECB_CHIDX_0						(0x1u<<0)
#define	ECB_SUBSCRIBE_STARTECB_EN_DISABLED					(0x0u<<31)
#define	ECB_SUBSCRIBE_STARTECB_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_STOPECB Configuration

#define	ECB_SUBSCRIBE_STOPECB_EN							(0x1u<<31)
#define	ECB_SUBSCRIBE_STOPECB_CHIDX							(0xFFu<<0)
#define	ECB_SUBSCRIBE_STOPECB_CHIDX_0						(0x1u<<0)
#define	ECB_SUBSCRIBE_STOPECB_EN_DISABLED					(0x0u<<31)
#define	ECB_SUBSCRIBE_STOPECB_EN_ENABLED					(0x1u<<31)

// EVENTS_ENDECB Configuration

#define	ECB_EVENTS_ENDECB_EVENTS_ENDECB						(0x1u<<0)
#define	ECB_EVENTS_ENDECB_EVENTS_ENDECB_NOTGENERATED		(0x0u<<0)
#define	ECB_EVENTS_ENDECB_EVENTS_ENDECB_GENERATED			(0x1u<<0)

// EVENTS_ERRORECB Configuration

#define	ECB_EVENTS_ERRORECB_EVENTS_ERRORECB					(0x1u<<0)
#define	ECB_EVENTS_ERRORECB_EVENTS_ERRORECB_NOTGENERATED	(0x0u<<0)
#define	ECB_EVENTS_ERRORECB_EVENTS_ERRORECB_GENERATED		(0x1u<<0)

// PUBLISH_ENDECB Configuration

#define	ECB_PUBLISH_ENDECB_EN								(0x1u<<31)
#define	ECB_PUBLISH_ENDECB_CHIDX							(0xFFu<<0)
#define	ECB_PUBLISH_ENDECB_CHIDX_0							(0x1u<<0)
#define	ECB_PUBLISH_ENDECB_EN_DISABLED						(0x0u<<31)
#define	ECB_PUBLISH_ENDECB_EN_ENABLED						(0x1u<<31)

// PUBLISH_ERRORECB Configuration

#define	ECB_PUBLISH_ERRORECB_EN								(0x1u<<31)
#define	ECB_PUBLISH_ERRORECB_CHIDX							(0xFFu<<0)
#define	ECB_PUBLISH_ERRORECB_CHIDX_0						(0x1u<<0)
#define	ECB_PUBLISH_ERRORECB_EN_DISABLED					(0x0u<<31)
#define	ECB_PUBLISH_ERRORECB_EN_ENABLED						(0x1u<<31)

// INTENSET Configuration

#define	ECB_INTENSET_ERRORECB								(0x1u<<1)
#define	ECB_INTENSET_ENDECB									(0x1u<<0)
#define	ECB_INTENSET_ERRORECB_DISABLED						(0x0u<<1)
#define	ECB_INTENSET_ERRORECB_ENABLED						(0x1u<<1)
#define	ECB_INTENSET_ERRORECB_SET							(0x1u<<1)
#define	ECB_INTENSET_ENDECB_DISABLED						(0x0u<<0)
#define	ECB_INTENSET_ENDECB_ENABLED							(0x1u<<0)
#define	ECB_INTENSET_ENDECB_SET								(0x1u<<0)

// INTENCLR Configuration

#define	ECB_INTENCLR_ERRORECB								(0x1u<<1)
#define	ECB_INTENCLR_ENDECB									(0x1u<<0)
#define	ECB_INTENCLR_ERRORECB_DISABLED						(0x0u<<1)
#define	ECB_INTENCLR_ERRORECB_ENABLED						(0x1u<<1)
#define	ECB_INTENCLR_ERRORECB_CLEAR							(0x1u<<1)
#define	ECB_INTENCLR_ENDECB_DISABLED						(0x0u<<0)
#define	ECB_INTENCLR_ENDECB_ENABLED							(0x1u<<0)
#define	ECB_INTENCLR_ENDECB_CLEAR							(0x1u<<0)

// ECBDATAPTR Configuration

#define	ECB_ECBDATAPTR_ECBDATAPTR							(0xFFFFFFFFu<<0)
#define	ECB_ECBDATAPTR_ECBDATAPTR_0							(0x1u<<0)
