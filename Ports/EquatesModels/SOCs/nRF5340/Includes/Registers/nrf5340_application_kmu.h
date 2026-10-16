/*
; nrf5340_application_kmu.
; ========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_kmu equates.
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

// KMU address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	TASKS_PUSH_KEYSLOT;
	volatile	uint32_t	RESERVED0[63];
	volatile	uint32_t	EVENTS_KEYSLOT_PUSHED;
	volatile	uint32_t	EVENTS_KEYSLOT_REVOKED;
	volatile	uint32_t	EVENTS_KEYSLOT_ERROR;
	volatile	uint32_t	RESERVED1[125];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	INTPEND;
	volatile	uint32_t	RESERVED2[63];
	volatile	uint32_t	STATUS;
	volatile	uint32_t	RESERVED3[60];
	volatile	uint32_t	SELECTKEYSLOT;
} KMU_TypeDef;

#if (defined(__cplusplus))
#define	KMU_NS	reinterpret_cast<KMU_TypeDef *>(0x40039000u)
#define	KMU_S	reinterpret_cast<KMU_TypeDef *>(0x50039000u)

#else
#define	KMU_NS	((KMU_TypeDef *)0x40039000u)
#define	KMU_S	((KMU_TypeDef *)0x50039000u)
#endif

// TASKS_PUSH_KEYSLOT Configuration

#define	KMU_TASKS_PUSH_KEYSLOT_TASKS_PUSH_KEYSLOT						(0x1u<<0)
#define	KMU_TASKS_PUSH_KEYSLOT_TASKS_PUSH_KEYSLOT_TRIGGER				(0x1u<<0)

// EVENTS_KEYSLOT_PUSHED Configuration

#define	KMU_EVENTS_KEYSLOT_PUSHED_EVENTS_KEYSLOT_PUSHED					(0x1u<<0)
#define	KMU_EVENTS_KEYSLOT_PUSHED_EVENTS_KEYSLOT_PUSHED_NOTGENERATED	(0x0u<<0)
#define	KMU_EVENTS_KEYSLOT_PUSHED_EVENTS_KEYSLOT_PUSHED_GENERATED		(0x1u<<0)

// EVENTS_KEYSLOT_REVOKED Configuration

#define	KMU_EVENTS_KEYSLOT_REVOKED_EVENTS_KEYSLOT_REVOKED				(0x1u<<0)
#define	KMU_EVENTS_KEYSLOT_REVOKED_EVENTS_KEYSLOT_REVOKED_NOTGENERATED	(0x0u<<0)
#define	KMU_EVENTS_KEYSLOT_REVOKED_EVENTS_KEYSLOT_REVOKED_GENERATED		(0x1u<<0)

// EVENTS_KEYSLOT_ERROR Configuration

#define	KMU_EVENTS_KEYSLOT_ERROR_EVENTS_KEYSLOT_ERROR					(0x1u<<0)
#define	KMU_EVENTS_KEYSLOT_ERROR_EVENTS_KEYSLOT_ERROR_NOTGENERATED		(0x0u<<0)
#define	KMU_EVENTS_KEYSLOT_ERROR_EVENTS_KEYSLOT_ERROR_GENERATED			(0x1u<<0)

// INTEN Configuration

#define	KMU_INTEN_KEYSLOT_ERROR											(0x1u<<2)
#define	KMU_INTEN_KEYSLOT_REVOKED										(0x1u<<1)
#define	KMU_INTEN_KEYSLOT_PUSHED										(0x1u<<0)
#define	KMU_INTEN_KEYSLOT_ERROR_DISABLED								(0x0u<<2)
#define	KMU_INTEN_KEYSLOT_ERROR_ENABLED									(0x1u<<2)
#define	KMU_INTEN_KEYSLOT_REVOKED_DISABLED								(0x0u<<1)
#define	KMU_INTEN_KEYSLOT_REVOKED_ENABLED								(0x1u<<1)
#define	KMU_INTEN_KEYSLOT_PUSHED_DISABLED								(0x0u<<0)
#define	KMU_INTEN_KEYSLOT_PUSHED_ENABLED								(0x1u<<0)

// INTENSET Configuration

#define	KMU_INTENSET_KEYSLOT_ERROR										(0x1u<<2)
#define	KMU_INTENSET_KEYSLOT_REVOKED									(0x1u<<1)
#define	KMU_INTENSET_KEYSLOT_PUSHED										(0x1u<<0)
#define	KMU_INTENSET_KEYSLOT_ERROR_DISABLED								(0x0u<<2)
#define	KMU_INTENSET_KEYSLOT_ERROR_ENABLED								(0x1u<<2)
#define	KMU_INTENSET_KEYSLOT_ERROR_SET									(0x1u<<2)
#define	KMU_INTENSET_KEYSLOT_REVOKED_DISABLED							(0x0u<<1)
#define	KMU_INTENSET_KEYSLOT_REVOKED_ENABLED							(0x1u<<1)
#define	KMU_INTENSET_KEYSLOT_REVOKED_SET								(0x1u<<1)
#define	KMU_INTENSET_KEYSLOT_PUSHED_DISABLED							(0x0u<<0)
#define	KMU_INTENSET_KEYSLOT_PUSHED_ENABLED								(0x1u<<0)
#define	KMU_INTENSET_KEYSLOT_PUSHED_SET									(0x1u<<0)

// INTENCLR Configuration

#define	KMU_INTENCLR_KEYSLOT_ERROR										(0x1u<<2)
#define	KMU_INTENCLR_KEYSLOT_REVOKED									(0x1u<<1)
#define	KMU_INTENCLR_KEYSLOT_PUSHED										(0x1u<<0)
#define	KMU_INTENCLR_KEYSLOT_ERROR_DISABLED								(0x0u<<2)
#define	KMU_INTENCLR_KEYSLOT_ERROR_ENABLED								(0x1u<<2)
#define	KMU_INTENCLR_KEYSLOT_ERROR_CLEAR								(0x1u<<2)
#define	KMU_INTENCLR_KEYSLOT_REVOKED_DISABLED							(0x0u<<1)
#define	KMU_INTENCLR_KEYSLOT_REVOKED_ENABLED							(0x1u<<1)
#define	KMU_INTENCLR_KEYSLOT_REVOKED_CLEAR								(0x1u<<1)
#define	KMU_INTENCLR_KEYSLOT_PUSHED_DISABLED							(0x0u<<0)
#define	KMU_INTENCLR_KEYSLOT_PUSHED_ENABLED								(0x1u<<0)
#define	KMU_INTENCLR_KEYSLOT_PUSHED_CLEAR								(0x1u<<0)

// INTPEND Configuration

#define	KMU_INTPEND_KEYSLOT_ERROR										(0x1u<<2)
#define	KMU_INTPEND_KEYSLOT_REVOKED										(0x1u<<1)
#define	KMU_INTPEND_KEYSLOT_PUSHED										(0x1u<<0)
#define	KMU_INTPEND_KEYSLOT_ERROR_NOTPENDING							(0x0u<<2)
#define	KMU_INTPEND_KEYSLOT_ERROR_PENDING								(0x1u<<2)
#define	KMU_INTPEND_KEYSLOT_REVOKED_NOTPENDING							(0x0u<<1)
#define	KMU_INTPEND_KEYSLOT_REVOKED_PENDING								(0x1u<<1)
#define	KMU_INTPEND_KEYSLOT_PUSHED_NOTPENDING							(0x0u<<0)
#define	KMU_INTPEND_KEYSLOT_PUSHED_PENDING								(0x1u<<0)

// STATUS Configuration

#define	KMU_STATUS_BLOCKED												(0x1u<<1)
#define	KMU_STATUS_SELECTED												(0x1u<<0)
#define	KMU_STATUS_BLOCKED_DISABLED										(0x0u<<1)
#define	KMU_STATUS_BLOCKED_ENABLED										(0x1u<<1)
#define	KMU_STATUS_SELECTED_DISABLED									(0x0u<<0)
#define	KMU_STATUS_SELECTED_ENABLED										(0x1u<<0)

// SELECTKEYSLOT Configuration

#define	KMU_SELECTKEYSLOT_ID											(0xFFu<<0)
#define	KMU_SELECTKEYSLOT_ID_0											(0x1u<<0)
