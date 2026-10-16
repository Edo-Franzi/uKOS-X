/*
; nrf5340_network_temp.
; =====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_network_temp equates.
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

// TEMP address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	TASKS_START;
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	RESERVED0[30];
	volatile	uint32_t	SUBSCRIBE_START;
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	RESERVED1[30];
	volatile	uint32_t	EVENTS_DATARDY;
	volatile	uint32_t	RESERVED2[31];
	volatile	uint32_t	PUBLISH_DATARDY;
	volatile	uint32_t	RESERVED3[96];
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED4[127];
	volatile	uint32_t	TEMP;
	volatile	uint32_t	RESERVED5[5];
	volatile	uint32_t	A0;
	volatile	uint32_t	A1;
	volatile	uint32_t	A2;
	volatile	uint32_t	A3;
	volatile	uint32_t	A4;
	volatile	uint32_t	A5;
	volatile	uint32_t	RESERVED6[2];
	volatile	uint32_t	B0;
	volatile	uint32_t	B1;
	volatile	uint32_t	B2;
	volatile	uint32_t	B3;
	volatile	uint32_t	B4;
	volatile	uint32_t	B5;
	volatile	uint32_t	RESERVED7[2];
	volatile	uint32_t	T0;
	volatile	uint32_t	T1;
	volatile	uint32_t	T2;
	volatile	uint32_t	T3;
	volatile	uint32_t	T4;
} TEMP_TypeDef;

#if (defined(__cplusplus))
#define	TEMP_NS	reinterpret_cast<TEMP_TypeDef *>(0x41010000u)

#else
#define	TEMP_NS	((TEMP_TypeDef *)0x41010000u)
#endif

// TASKS_START Configuration

#define	TEMP_TASKS_START_TASKS_START					(0x1u<<0)
#define	TEMP_TASKS_START_TASKS_START_TRIGGER			(0x1u<<0)

// TASKS_STOP Configuration

#define	TEMP_TASKS_STOP_TASKS_STOP						(0x1u<<0)
#define	TEMP_TASKS_STOP_TASKS_STOP_TRIGGER				(0x1u<<0)

// SUBSCRIBE_START Configuration

#define	TEMP_SUBSCRIBE_START_EN							(0x1u<<31)
#define	TEMP_SUBSCRIBE_START_CHIDX						(0xFFu<<0)
#define	TEMP_SUBSCRIBE_START_CHIDX_0					(0x1u<<0)
#define	TEMP_SUBSCRIBE_START_EN_DISABLED				(0x0u<<31)
#define	TEMP_SUBSCRIBE_START_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_STOP Configuration

#define	TEMP_SUBSCRIBE_STOP_EN							(0x1u<<31)
#define	TEMP_SUBSCRIBE_STOP_CHIDX						(0xFFu<<0)
#define	TEMP_SUBSCRIBE_STOP_CHIDX_0						(0x1u<<0)
#define	TEMP_SUBSCRIBE_STOP_EN_DISABLED					(0x0u<<31)
#define	TEMP_SUBSCRIBE_STOP_EN_ENABLED					(0x1u<<31)

// EVENTS_DATARDY Configuration

#define	TEMP_EVENTS_DATARDY_EVENTS_DATARDY				(0x1u<<0)
#define	TEMP_EVENTS_DATARDY_EVENTS_DATARDY_NOTGENERATED	(0x0u<<0)
#define	TEMP_EVENTS_DATARDY_EVENTS_DATARDY_GENERATED	(0x1u<<0)

// PUBLISH_DATARDY Configuration

#define	TEMP_PUBLISH_DATARDY_EN							(0x1u<<31)
#define	TEMP_PUBLISH_DATARDY_CHIDX						(0xFFu<<0)
#define	TEMP_PUBLISH_DATARDY_CHIDX_0					(0x1u<<0)
#define	TEMP_PUBLISH_DATARDY_EN_DISABLED				(0x0u<<31)
#define	TEMP_PUBLISH_DATARDY_EN_ENABLED					(0x1u<<31)

// INTENSET Configuration

#define	TEMP_INTENSET_DATARDY							(0x1u<<0)
#define	TEMP_INTENSET_DATARDY_DISABLED					(0x0u<<0)
#define	TEMP_INTENSET_DATARDY_ENABLED					(0x1u<<0)
#define	TEMP_INTENSET_DATARDY_SET						(0x1u<<0)

// INTENCLR Configuration

#define	TEMP_INTENCLR_DATARDY							(0x1u<<0)
#define	TEMP_INTENCLR_DATARDY_DISABLED					(0x0u<<0)
#define	TEMP_INTENCLR_DATARDY_ENABLED					(0x1u<<0)
#define	TEMP_INTENCLR_DATARDY_CLEAR						(0x1u<<0)

// TEMP Configuration

#define	TEMP_TEMP_TEMP									(0xFFFFFFFFu<<0)
#define	TEMP_TEMP_TEMP_0								(0x1u<<0)

// A0 Configuration

#define	TEMP_A0_A0										(0xFFFu<<0)
#define	TEMP_A0_A0_0									(0x1u<<0)

// A1 Configuration

#define	TEMP_A1_A1										(0xFFFu<<0)
#define	TEMP_A1_A1_0									(0x1u<<0)

// A2 Configuration

#define	TEMP_A2_A2										(0xFFFu<<0)
#define	TEMP_A2_A2_0									(0x1u<<0)

// A3 Configuration

#define	TEMP_A3_A3										(0xFFFu<<0)
#define	TEMP_A3_A3_0									(0x1u<<0)

// A4 Configuration

#define	TEMP_A4_A4										(0xFFFu<<0)
#define	TEMP_A4_A4_0									(0x1u<<0)

// A5 Configuration

#define	TEMP_A5_A5										(0xFFFu<<0)
#define	TEMP_A5_A5_0									(0x1u<<0)

// B0 Configuration

#define	TEMP_B0_B0										(0xFFFu<<0)
#define	TEMP_B0_B0_0									(0x1u<<0)

// B1 Configuration

#define	TEMP_B1_B1										(0xFFFu<<0)
#define	TEMP_B1_B1_0									(0x1u<<0)

// B2 Configuration

#define	TEMP_B2_B2										(0xFFFu<<0)
#define	TEMP_B2_B2_0									(0x1u<<0)

// B3 Configuration

#define	TEMP_B3_B3										(0xFFFu<<0)
#define	TEMP_B3_B3_0									(0x1u<<0)

// B4 Configuration

#define	TEMP_B4_B4										(0xFFFu<<0)
#define	TEMP_B4_B4_0									(0x1u<<0)

// B5 Configuration

#define	TEMP_B5_B5										(0xFFFu<<0)
#define	TEMP_B5_B5_0									(0x1u<<0)

// T0 Configuration

#define	TEMP_T0_T0										(0xFFu<<0)
#define	TEMP_T0_T0_0									(0x1u<<0)

// T1 Configuration

#define	TEMP_T1_T1										(0xFFu<<0)
#define	TEMP_T1_T1_0									(0x1u<<0)

// T2 Configuration

#define	TEMP_T2_T2										(0xFFu<<0)
#define	TEMP_T2_T2_0									(0x1u<<0)

// T3 Configuration

#define	TEMP_T3_T3										(0xFFu<<0)
#define	TEMP_T3_T3_0									(0x1u<<0)

// T4 Configuration

#define	TEMP_T4_T4										(0xFFu<<0)
#define	TEMP_T4_T4_0									(0x1u<<0)
