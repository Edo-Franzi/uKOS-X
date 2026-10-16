/*
; nrf5340_application_ipc.
; ========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_ipc equates.
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

// IPC address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	TASKS_SEND[16];
	volatile	uint32_t	RESERVED0[16];
	volatile	uint32_t	SUBSCRIBE_SEND[16];
	volatile	uint32_t	RESERVED1[16];
	volatile	uint32_t	EVENTS_RECEIVE[16];
	volatile	uint32_t	RESERVED2[16];
	volatile	uint32_t	PUBLISH_RECEIVE[16];
	volatile	uint32_t	RESERVED3[80];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	INTPEND;
	volatile	uint32_t	RESERVED4[128];
	volatile	uint32_t	SEND_CNF[16];
	volatile	uint32_t	RESERVED5[16];
	volatile	uint32_t	RECEIVE_CNF[16];
	volatile	uint32_t	RESERVED6[16];
	volatile	uint32_t	GPMEM[2];
} IPC_TypeDef;

#if (defined(__cplusplus))
#define	IPC_NS	reinterpret_cast<IPC_TypeDef *>(0x4002A000u)
#define	IPC_S	reinterpret_cast<IPC_TypeDef *>(0x5002A000u)

#else
#define	IPC_NS	((IPC_TypeDef *)0x4002A000u)
#define	IPC_S	((IPC_TypeDef *)0x5002A000u)
#endif

// TASKS_SEND Configuration

#define	IPC_TASKS_SEND_TASKS_SEND						(0x1u<<0)
#define	IPC_TASKS_SEND_TASKS_SEND_TRIGGER				(0x1u<<0)

// SUBSCRIBE_SEND Configuration

#define	IPC_SUBSCRIBE_SEND_EN							(0x1u<<31)
#define	IPC_SUBSCRIBE_SEND_CHIDX						(0xFFu<<0)
#define	IPC_SUBSCRIBE_SEND_CHIDX_0						(0x1u<<0)
#define	IPC_SUBSCRIBE_SEND_EN_DISABLED					(0x0u<<31)
#define	IPC_SUBSCRIBE_SEND_EN_ENABLED					(0x1u<<31)

// EVENTS_RECEIVE Configuration

#define	IPC_EVENTS_RECEIVE_EVENTS_RECEIVE				(0x1u<<0)
#define	IPC_EVENTS_RECEIVE_EVENTS_RECEIVE_NOTGENERATED	(0x0u<<0)
#define	IPC_EVENTS_RECEIVE_EVENTS_RECEIVE_GENERATED		(0x1u<<0)

// PUBLISH_RECEIVE Configuration

#define	IPC_PUBLISH_RECEIVE_EN							(0x1u<<31)
#define	IPC_PUBLISH_RECEIVE_CHIDX						(0xFFu<<0)
#define	IPC_PUBLISH_RECEIVE_CHIDX_0						(0x1u<<0)
#define	IPC_PUBLISH_RECEIVE_EN_DISABLED					(0x0u<<31)
#define	IPC_PUBLISH_RECEIVE_EN_ENABLED					(0x1u<<31)

// INTEN Configuration

#define	IPC_INTEN_RECEIVE15								(0x1u<<15)
#define	IPC_INTEN_RECEIVE14								(0x1u<<14)
#define	IPC_INTEN_RECEIVE13								(0x1u<<13)
#define	IPC_INTEN_RECEIVE12								(0x1u<<12)
#define	IPC_INTEN_RECEIVE11								(0x1u<<11)
#define	IPC_INTEN_RECEIVE10								(0x1u<<10)
#define	IPC_INTEN_RECEIVE9								(0x1u<<9)
#define	IPC_INTEN_RECEIVE8								(0x1u<<8)
#define	IPC_INTEN_RECEIVE7								(0x1u<<7)
#define	IPC_INTEN_RECEIVE6								(0x1u<<6)
#define	IPC_INTEN_RECEIVE5								(0x1u<<5)
#define	IPC_INTEN_RECEIVE4								(0x1u<<4)
#define	IPC_INTEN_RECEIVE3								(0x1u<<3)
#define	IPC_INTEN_RECEIVE2								(0x1u<<2)
#define	IPC_INTEN_RECEIVE1								(0x1u<<1)
#define	IPC_INTEN_RECEIVE0								(0x1u<<0)
#define	IPC_INTEN_RECEIVE15_DISABLED					(0x0u<<15)
#define	IPC_INTEN_RECEIVE15_ENABLED						(0x1u<<15)
#define	IPC_INTEN_RECEIVE14_DISABLED					(0x0u<<14)
#define	IPC_INTEN_RECEIVE14_ENABLED						(0x1u<<14)
#define	IPC_INTEN_RECEIVE13_DISABLED					(0x0u<<13)
#define	IPC_INTEN_RECEIVE13_ENABLED						(0x1u<<13)
#define	IPC_INTEN_RECEIVE12_DISABLED					(0x0u<<12)
#define	IPC_INTEN_RECEIVE12_ENABLED						(0x1u<<12)
#define	IPC_INTEN_RECEIVE11_DISABLED					(0x0u<<11)
#define	IPC_INTEN_RECEIVE11_ENABLED						(0x1u<<11)
#define	IPC_INTEN_RECEIVE10_DISABLED					(0x0u<<10)
#define	IPC_INTEN_RECEIVE10_ENABLED						(0x1u<<10)
#define	IPC_INTEN_RECEIVE9_DISABLED						(0x0u<<9)
#define	IPC_INTEN_RECEIVE9_ENABLED						(0x1u<<9)
#define	IPC_INTEN_RECEIVE8_DISABLED						(0x0u<<8)
#define	IPC_INTEN_RECEIVE8_ENABLED						(0x1u<<8)
#define	IPC_INTEN_RECEIVE7_DISABLED						(0x0u<<7)
#define	IPC_INTEN_RECEIVE7_ENABLED						(0x1u<<7)
#define	IPC_INTEN_RECEIVE6_DISABLED						(0x0u<<6)
#define	IPC_INTEN_RECEIVE6_ENABLED						(0x1u<<6)
#define	IPC_INTEN_RECEIVE5_DISABLED						(0x0u<<5)
#define	IPC_INTEN_RECEIVE5_ENABLED						(0x1u<<5)
#define	IPC_INTEN_RECEIVE4_DISABLED						(0x0u<<4)
#define	IPC_INTEN_RECEIVE4_ENABLED						(0x1u<<4)
#define	IPC_INTEN_RECEIVE3_DISABLED						(0x0u<<3)
#define	IPC_INTEN_RECEIVE3_ENABLED						(0x1u<<3)
#define	IPC_INTEN_RECEIVE2_DISABLED						(0x0u<<2)
#define	IPC_INTEN_RECEIVE2_ENABLED						(0x1u<<2)
#define	IPC_INTEN_RECEIVE1_DISABLED						(0x0u<<1)
#define	IPC_INTEN_RECEIVE1_ENABLED						(0x1u<<1)
#define	IPC_INTEN_RECEIVE0_DISABLED						(0x0u<<0)
#define	IPC_INTEN_RECEIVE0_ENABLED						(0x1u<<0)

// INTENSET Configuration

#define	IPC_INTENSET_RECEIVE15							(0x1u<<15)
#define	IPC_INTENSET_RECEIVE14							(0x1u<<14)
#define	IPC_INTENSET_RECEIVE13							(0x1u<<13)
#define	IPC_INTENSET_RECEIVE12							(0x1u<<12)
#define	IPC_INTENSET_RECEIVE11							(0x1u<<11)
#define	IPC_INTENSET_RECEIVE10							(0x1u<<10)
#define	IPC_INTENSET_RECEIVE9							(0x1u<<9)
#define	IPC_INTENSET_RECEIVE8							(0x1u<<8)
#define	IPC_INTENSET_RECEIVE7							(0x1u<<7)
#define	IPC_INTENSET_RECEIVE6							(0x1u<<6)
#define	IPC_INTENSET_RECEIVE5							(0x1u<<5)
#define	IPC_INTENSET_RECEIVE4							(0x1u<<4)
#define	IPC_INTENSET_RECEIVE3							(0x1u<<3)
#define	IPC_INTENSET_RECEIVE2							(0x1u<<2)
#define	IPC_INTENSET_RECEIVE1							(0x1u<<1)
#define	IPC_INTENSET_RECEIVE0							(0x1u<<0)
#define	IPC_INTENSET_RECEIVE15_DISABLED					(0x0u<<15)
#define	IPC_INTENSET_RECEIVE15_ENABLED					(0x1u<<15)
#define	IPC_INTENSET_RECEIVE15_SET						(0x1u<<15)
#define	IPC_INTENSET_RECEIVE14_DISABLED					(0x0u<<14)
#define	IPC_INTENSET_RECEIVE14_ENABLED					(0x1u<<14)
#define	IPC_INTENSET_RECEIVE14_SET						(0x1u<<14)
#define	IPC_INTENSET_RECEIVE13_DISABLED					(0x0u<<13)
#define	IPC_INTENSET_RECEIVE13_ENABLED					(0x1u<<13)
#define	IPC_INTENSET_RECEIVE13_SET						(0x1u<<13)
#define	IPC_INTENSET_RECEIVE12_DISABLED					(0x0u<<12)
#define	IPC_INTENSET_RECEIVE12_ENABLED					(0x1u<<12)
#define	IPC_INTENSET_RECEIVE12_SET						(0x1u<<12)
#define	IPC_INTENSET_RECEIVE11_DISABLED					(0x0u<<11)
#define	IPC_INTENSET_RECEIVE11_ENABLED					(0x1u<<11)
#define	IPC_INTENSET_RECEIVE11_SET						(0x1u<<11)
#define	IPC_INTENSET_RECEIVE10_DISABLED					(0x0u<<10)
#define	IPC_INTENSET_RECEIVE10_ENABLED					(0x1u<<10)
#define	IPC_INTENSET_RECEIVE10_SET						(0x1u<<10)
#define	IPC_INTENSET_RECEIVE9_DISABLED					(0x0u<<9)
#define	IPC_INTENSET_RECEIVE9_ENABLED					(0x1u<<9)
#define	IPC_INTENSET_RECEIVE9_SET						(0x1u<<9)
#define	IPC_INTENSET_RECEIVE8_DISABLED					(0x0u<<8)
#define	IPC_INTENSET_RECEIVE8_ENABLED					(0x1u<<8)
#define	IPC_INTENSET_RECEIVE8_SET						(0x1u<<8)
#define	IPC_INTENSET_RECEIVE7_DISABLED					(0x0u<<7)
#define	IPC_INTENSET_RECEIVE7_ENABLED					(0x1u<<7)
#define	IPC_INTENSET_RECEIVE7_SET						(0x1u<<7)
#define	IPC_INTENSET_RECEIVE6_DISABLED					(0x0u<<6)
#define	IPC_INTENSET_RECEIVE6_ENABLED					(0x1u<<6)
#define	IPC_INTENSET_RECEIVE6_SET						(0x1u<<6)
#define	IPC_INTENSET_RECEIVE5_DISABLED					(0x0u<<5)
#define	IPC_INTENSET_RECEIVE5_ENABLED					(0x1u<<5)
#define	IPC_INTENSET_RECEIVE5_SET						(0x1u<<5)
#define	IPC_INTENSET_RECEIVE4_DISABLED					(0x0u<<4)
#define	IPC_INTENSET_RECEIVE4_ENABLED					(0x1u<<4)
#define	IPC_INTENSET_RECEIVE4_SET						(0x1u<<4)
#define	IPC_INTENSET_RECEIVE3_DISABLED					(0x0u<<3)
#define	IPC_INTENSET_RECEIVE3_ENABLED					(0x1u<<3)
#define	IPC_INTENSET_RECEIVE3_SET						(0x1u<<3)
#define	IPC_INTENSET_RECEIVE2_DISABLED					(0x0u<<2)
#define	IPC_INTENSET_RECEIVE2_ENABLED					(0x1u<<2)
#define	IPC_INTENSET_RECEIVE2_SET						(0x1u<<2)
#define	IPC_INTENSET_RECEIVE1_DISABLED					(0x0u<<1)
#define	IPC_INTENSET_RECEIVE1_ENABLED					(0x1u<<1)
#define	IPC_INTENSET_RECEIVE1_SET						(0x1u<<1)
#define	IPC_INTENSET_RECEIVE0_DISABLED					(0x0u<<0)
#define	IPC_INTENSET_RECEIVE0_ENABLED					(0x1u<<0)
#define	IPC_INTENSET_RECEIVE0_SET						(0x1u<<0)

// INTENCLR Configuration

#define	IPC_INTENCLR_RECEIVE15							(0x1u<<15)
#define	IPC_INTENCLR_RECEIVE14							(0x1u<<14)
#define	IPC_INTENCLR_RECEIVE13							(0x1u<<13)
#define	IPC_INTENCLR_RECEIVE12							(0x1u<<12)
#define	IPC_INTENCLR_RECEIVE11							(0x1u<<11)
#define	IPC_INTENCLR_RECEIVE10							(0x1u<<10)
#define	IPC_INTENCLR_RECEIVE9							(0x1u<<9)
#define	IPC_INTENCLR_RECEIVE8							(0x1u<<8)
#define	IPC_INTENCLR_RECEIVE7							(0x1u<<7)
#define	IPC_INTENCLR_RECEIVE6							(0x1u<<6)
#define	IPC_INTENCLR_RECEIVE5							(0x1u<<5)
#define	IPC_INTENCLR_RECEIVE4							(0x1u<<4)
#define	IPC_INTENCLR_RECEIVE3							(0x1u<<3)
#define	IPC_INTENCLR_RECEIVE2							(0x1u<<2)
#define	IPC_INTENCLR_RECEIVE1							(0x1u<<1)
#define	IPC_INTENCLR_RECEIVE0							(0x1u<<0)
#define	IPC_INTENCLR_RECEIVE15_DISABLED					(0x0u<<15)
#define	IPC_INTENCLR_RECEIVE15_ENABLED					(0x1u<<15)
#define	IPC_INTENCLR_RECEIVE15_CLEAR					(0x1u<<15)
#define	IPC_INTENCLR_RECEIVE14_DISABLED					(0x0u<<14)
#define	IPC_INTENCLR_RECEIVE14_ENABLED					(0x1u<<14)
#define	IPC_INTENCLR_RECEIVE14_CLEAR					(0x1u<<14)
#define	IPC_INTENCLR_RECEIVE13_DISABLED					(0x0u<<13)
#define	IPC_INTENCLR_RECEIVE13_ENABLED					(0x1u<<13)
#define	IPC_INTENCLR_RECEIVE13_CLEAR					(0x1u<<13)
#define	IPC_INTENCLR_RECEIVE12_DISABLED					(0x0u<<12)
#define	IPC_INTENCLR_RECEIVE12_ENABLED					(0x1u<<12)
#define	IPC_INTENCLR_RECEIVE12_CLEAR					(0x1u<<12)
#define	IPC_INTENCLR_RECEIVE11_DISABLED					(0x0u<<11)
#define	IPC_INTENCLR_RECEIVE11_ENABLED					(0x1u<<11)
#define	IPC_INTENCLR_RECEIVE11_CLEAR					(0x1u<<11)
#define	IPC_INTENCLR_RECEIVE10_DISABLED					(0x0u<<10)
#define	IPC_INTENCLR_RECEIVE10_ENABLED					(0x1u<<10)
#define	IPC_INTENCLR_RECEIVE10_CLEAR					(0x1u<<10)
#define	IPC_INTENCLR_RECEIVE9_DISABLED					(0x0u<<9)
#define	IPC_INTENCLR_RECEIVE9_ENABLED					(0x1u<<9)
#define	IPC_INTENCLR_RECEIVE9_CLEAR						(0x1u<<9)
#define	IPC_INTENCLR_RECEIVE8_DISABLED					(0x0u<<8)
#define	IPC_INTENCLR_RECEIVE8_ENABLED					(0x1u<<8)
#define	IPC_INTENCLR_RECEIVE8_CLEAR						(0x1u<<8)
#define	IPC_INTENCLR_RECEIVE7_DISABLED					(0x0u<<7)
#define	IPC_INTENCLR_RECEIVE7_ENABLED					(0x1u<<7)
#define	IPC_INTENCLR_RECEIVE7_CLEAR						(0x1u<<7)
#define	IPC_INTENCLR_RECEIVE6_DISABLED					(0x0u<<6)
#define	IPC_INTENCLR_RECEIVE6_ENABLED					(0x1u<<6)
#define	IPC_INTENCLR_RECEIVE6_CLEAR						(0x1u<<6)
#define	IPC_INTENCLR_RECEIVE5_DISABLED					(0x0u<<5)
#define	IPC_INTENCLR_RECEIVE5_ENABLED					(0x1u<<5)
#define	IPC_INTENCLR_RECEIVE5_CLEAR						(0x1u<<5)
#define	IPC_INTENCLR_RECEIVE4_DISABLED					(0x0u<<4)
#define	IPC_INTENCLR_RECEIVE4_ENABLED					(0x1u<<4)
#define	IPC_INTENCLR_RECEIVE4_CLEAR						(0x1u<<4)
#define	IPC_INTENCLR_RECEIVE3_DISABLED					(0x0u<<3)
#define	IPC_INTENCLR_RECEIVE3_ENABLED					(0x1u<<3)
#define	IPC_INTENCLR_RECEIVE3_CLEAR						(0x1u<<3)
#define	IPC_INTENCLR_RECEIVE2_DISABLED					(0x0u<<2)
#define	IPC_INTENCLR_RECEIVE2_ENABLED					(0x1u<<2)
#define	IPC_INTENCLR_RECEIVE2_CLEAR						(0x1u<<2)
#define	IPC_INTENCLR_RECEIVE1_DISABLED					(0x0u<<1)
#define	IPC_INTENCLR_RECEIVE1_ENABLED					(0x1u<<1)
#define	IPC_INTENCLR_RECEIVE1_CLEAR						(0x1u<<1)
#define	IPC_INTENCLR_RECEIVE0_DISABLED					(0x0u<<0)
#define	IPC_INTENCLR_RECEIVE0_ENABLED					(0x1u<<0)
#define	IPC_INTENCLR_RECEIVE0_CLEAR						(0x1u<<0)

// INTPEND Configuration

#define	IPC_INTPEND_RECEIVE15							(0x1u<<15)
#define	IPC_INTPEND_RECEIVE14							(0x1u<<14)
#define	IPC_INTPEND_RECEIVE13							(0x1u<<13)
#define	IPC_INTPEND_RECEIVE12							(0x1u<<12)
#define	IPC_INTPEND_RECEIVE11							(0x1u<<11)
#define	IPC_INTPEND_RECEIVE10							(0x1u<<10)
#define	IPC_INTPEND_RECEIVE9							(0x1u<<9)
#define	IPC_INTPEND_RECEIVE8							(0x1u<<8)
#define	IPC_INTPEND_RECEIVE7							(0x1u<<7)
#define	IPC_INTPEND_RECEIVE6							(0x1u<<6)
#define	IPC_INTPEND_RECEIVE5							(0x1u<<5)
#define	IPC_INTPEND_RECEIVE4							(0x1u<<4)
#define	IPC_INTPEND_RECEIVE3							(0x1u<<3)
#define	IPC_INTPEND_RECEIVE2							(0x1u<<2)
#define	IPC_INTPEND_RECEIVE1							(0x1u<<1)
#define	IPC_INTPEND_RECEIVE0							(0x1u<<0)
#define	IPC_INTPEND_RECEIVE15_NOTPENDING				(0x0u<<15)
#define	IPC_INTPEND_RECEIVE15_PENDING					(0x1u<<15)
#define	IPC_INTPEND_RECEIVE14_NOTPENDING				(0x0u<<14)
#define	IPC_INTPEND_RECEIVE14_PENDING					(0x1u<<14)
#define	IPC_INTPEND_RECEIVE13_NOTPENDING				(0x0u<<13)
#define	IPC_INTPEND_RECEIVE13_PENDING					(0x1u<<13)
#define	IPC_INTPEND_RECEIVE12_NOTPENDING				(0x0u<<12)
#define	IPC_INTPEND_RECEIVE12_PENDING					(0x1u<<12)
#define	IPC_INTPEND_RECEIVE11_NOTPENDING				(0x0u<<11)
#define	IPC_INTPEND_RECEIVE11_PENDING					(0x1u<<11)
#define	IPC_INTPEND_RECEIVE10_NOTPENDING				(0x0u<<10)
#define	IPC_INTPEND_RECEIVE10_PENDING					(0x1u<<10)
#define	IPC_INTPEND_RECEIVE9_NOTPENDING					(0x0u<<9)
#define	IPC_INTPEND_RECEIVE9_PENDING					(0x1u<<9)
#define	IPC_INTPEND_RECEIVE8_NOTPENDING					(0x0u<<8)
#define	IPC_INTPEND_RECEIVE8_PENDING					(0x1u<<8)
#define	IPC_INTPEND_RECEIVE7_NOTPENDING					(0x0u<<7)
#define	IPC_INTPEND_RECEIVE7_PENDING					(0x1u<<7)
#define	IPC_INTPEND_RECEIVE6_NOTPENDING					(0x0u<<6)
#define	IPC_INTPEND_RECEIVE6_PENDING					(0x1u<<6)
#define	IPC_INTPEND_RECEIVE5_NOTPENDING					(0x0u<<5)
#define	IPC_INTPEND_RECEIVE5_PENDING					(0x1u<<5)
#define	IPC_INTPEND_RECEIVE4_NOTPENDING					(0x0u<<4)
#define	IPC_INTPEND_RECEIVE4_PENDING					(0x1u<<4)
#define	IPC_INTPEND_RECEIVE3_NOTPENDING					(0x0u<<3)
#define	IPC_INTPEND_RECEIVE3_PENDING					(0x1u<<3)
#define	IPC_INTPEND_RECEIVE2_NOTPENDING					(0x0u<<2)
#define	IPC_INTPEND_RECEIVE2_PENDING					(0x1u<<2)
#define	IPC_INTPEND_RECEIVE1_NOTPENDING					(0x0u<<1)
#define	IPC_INTPEND_RECEIVE1_PENDING					(0x1u<<1)
#define	IPC_INTPEND_RECEIVE0_NOTPENDING					(0x0u<<0)
#define	IPC_INTPEND_RECEIVE0_PENDING					(0x1u<<0)

// SEND_CNF Configuration

#define	IPC_SEND_CNF_CHEN15								(0x1u<<15)
#define	IPC_SEND_CNF_CHEN14								(0x1u<<14)
#define	IPC_SEND_CNF_CHEN13								(0x1u<<13)
#define	IPC_SEND_CNF_CHEN12								(0x1u<<12)
#define	IPC_SEND_CNF_CHEN11								(0x1u<<11)
#define	IPC_SEND_CNF_CHEN10								(0x1u<<10)
#define	IPC_SEND_CNF_CHEN9								(0x1u<<9)
#define	IPC_SEND_CNF_CHEN8								(0x1u<<8)
#define	IPC_SEND_CNF_CHEN7								(0x1u<<7)
#define	IPC_SEND_CNF_CHEN6								(0x1u<<6)
#define	IPC_SEND_CNF_CHEN5								(0x1u<<5)
#define	IPC_SEND_CNF_CHEN4								(0x1u<<4)
#define	IPC_SEND_CNF_CHEN3								(0x1u<<3)
#define	IPC_SEND_CNF_CHEN2								(0x1u<<2)
#define	IPC_SEND_CNF_CHEN1								(0x1u<<1)
#define	IPC_SEND_CNF_CHEN0								(0x1u<<0)
#define	IPC_SEND_CNF_CHEN15_DISABLE						(0x0u<<15)
#define	IPC_SEND_CNF_CHEN15_ENABLE						(0x1u<<15)
#define	IPC_SEND_CNF_CHEN14_DISABLE						(0x0u<<14)
#define	IPC_SEND_CNF_CHEN14_ENABLE						(0x1u<<14)
#define	IPC_SEND_CNF_CHEN13_DISABLE						(0x0u<<13)
#define	IPC_SEND_CNF_CHEN13_ENABLE						(0x1u<<13)
#define	IPC_SEND_CNF_CHEN12_DISABLE						(0x0u<<12)
#define	IPC_SEND_CNF_CHEN12_ENABLE						(0x1u<<12)
#define	IPC_SEND_CNF_CHEN11_DISABLE						(0x0u<<11)
#define	IPC_SEND_CNF_CHEN11_ENABLE						(0x1u<<11)
#define	IPC_SEND_CNF_CHEN10_DISABLE						(0x0u<<10)
#define	IPC_SEND_CNF_CHEN10_ENABLE						(0x1u<<10)
#define	IPC_SEND_CNF_CHEN9_DISABLE						(0x0u<<9)
#define	IPC_SEND_CNF_CHEN9_ENABLE						(0x1u<<9)
#define	IPC_SEND_CNF_CHEN8_DISABLE						(0x0u<<8)
#define	IPC_SEND_CNF_CHEN8_ENABLE						(0x1u<<8)
#define	IPC_SEND_CNF_CHEN7_DISABLE						(0x0u<<7)
#define	IPC_SEND_CNF_CHEN7_ENABLE						(0x1u<<7)
#define	IPC_SEND_CNF_CHEN6_DISABLE						(0x0u<<6)
#define	IPC_SEND_CNF_CHEN6_ENABLE						(0x1u<<6)
#define	IPC_SEND_CNF_CHEN5_DISABLE						(0x0u<<5)
#define	IPC_SEND_CNF_CHEN5_ENABLE						(0x1u<<5)
#define	IPC_SEND_CNF_CHEN4_DISABLE						(0x0u<<4)
#define	IPC_SEND_CNF_CHEN4_ENABLE						(0x1u<<4)
#define	IPC_SEND_CNF_CHEN3_DISABLE						(0x0u<<3)
#define	IPC_SEND_CNF_CHEN3_ENABLE						(0x1u<<3)
#define	IPC_SEND_CNF_CHEN2_DISABLE						(0x0u<<2)
#define	IPC_SEND_CNF_CHEN2_ENABLE						(0x1u<<2)
#define	IPC_SEND_CNF_CHEN1_DISABLE						(0x0u<<1)
#define	IPC_SEND_CNF_CHEN1_ENABLE						(0x1u<<1)
#define	IPC_SEND_CNF_CHEN0_DISABLE						(0x0u<<0)
#define	IPC_SEND_CNF_CHEN0_ENABLE						(0x1u<<0)

// RECEIVE_CNF Configuration

#define	IPC_RECEIVE_CNF_CHEN15							(0x1u<<15)
#define	IPC_RECEIVE_CNF_CHEN14							(0x1u<<14)
#define	IPC_RECEIVE_CNF_CHEN13							(0x1u<<13)
#define	IPC_RECEIVE_CNF_CHEN12							(0x1u<<12)
#define	IPC_RECEIVE_CNF_CHEN11							(0x1u<<11)
#define	IPC_RECEIVE_CNF_CHEN10							(0x1u<<10)
#define	IPC_RECEIVE_CNF_CHEN9							(0x1u<<9)
#define	IPC_RECEIVE_CNF_CHEN8							(0x1u<<8)
#define	IPC_RECEIVE_CNF_CHEN7							(0x1u<<7)
#define	IPC_RECEIVE_CNF_CHEN6							(0x1u<<6)
#define	IPC_RECEIVE_CNF_CHEN5							(0x1u<<5)
#define	IPC_RECEIVE_CNF_CHEN4							(0x1u<<4)
#define	IPC_RECEIVE_CNF_CHEN3							(0x1u<<3)
#define	IPC_RECEIVE_CNF_CHEN2							(0x1u<<2)
#define	IPC_RECEIVE_CNF_CHEN1							(0x1u<<1)
#define	IPC_RECEIVE_CNF_CHEN0							(0x1u<<0)
#define	IPC_RECEIVE_CNF_CHEN15_DISABLE					(0x0u<<15)
#define	IPC_RECEIVE_CNF_CHEN15_ENABLE					(0x1u<<15)
#define	IPC_RECEIVE_CNF_CHEN14_DISABLE					(0x0u<<14)
#define	IPC_RECEIVE_CNF_CHEN14_ENABLE					(0x1u<<14)
#define	IPC_RECEIVE_CNF_CHEN13_DISABLE					(0x0u<<13)
#define	IPC_RECEIVE_CNF_CHEN13_ENABLE					(0x1u<<13)
#define	IPC_RECEIVE_CNF_CHEN12_DISABLE					(0x0u<<12)
#define	IPC_RECEIVE_CNF_CHEN12_ENABLE					(0x1u<<12)
#define	IPC_RECEIVE_CNF_CHEN11_DISABLE					(0x0u<<11)
#define	IPC_RECEIVE_CNF_CHEN11_ENABLE					(0x1u<<11)
#define	IPC_RECEIVE_CNF_CHEN10_DISABLE					(0x0u<<10)
#define	IPC_RECEIVE_CNF_CHEN10_ENABLE					(0x1u<<10)
#define	IPC_RECEIVE_CNF_CHEN9_DISABLE					(0x0u<<9)
#define	IPC_RECEIVE_CNF_CHEN9_ENABLE					(0x1u<<9)
#define	IPC_RECEIVE_CNF_CHEN8_DISABLE					(0x0u<<8)
#define	IPC_RECEIVE_CNF_CHEN8_ENABLE					(0x1u<<8)
#define	IPC_RECEIVE_CNF_CHEN7_DISABLE					(0x0u<<7)
#define	IPC_RECEIVE_CNF_CHEN7_ENABLE					(0x1u<<7)
#define	IPC_RECEIVE_CNF_CHEN6_DISABLE					(0x0u<<6)
#define	IPC_RECEIVE_CNF_CHEN6_ENABLE					(0x1u<<6)
#define	IPC_RECEIVE_CNF_CHEN5_DISABLE					(0x0u<<5)
#define	IPC_RECEIVE_CNF_CHEN5_ENABLE					(0x1u<<5)
#define	IPC_RECEIVE_CNF_CHEN4_DISABLE					(0x0u<<4)
#define	IPC_RECEIVE_CNF_CHEN4_ENABLE					(0x1u<<4)
#define	IPC_RECEIVE_CNF_CHEN3_DISABLE					(0x0u<<3)
#define	IPC_RECEIVE_CNF_CHEN3_ENABLE					(0x1u<<3)
#define	IPC_RECEIVE_CNF_CHEN2_DISABLE					(0x0u<<2)
#define	IPC_RECEIVE_CNF_CHEN2_ENABLE					(0x1u<<2)
#define	IPC_RECEIVE_CNF_CHEN1_DISABLE					(0x0u<<1)
#define	IPC_RECEIVE_CNF_CHEN1_ENABLE					(0x1u<<1)
#define	IPC_RECEIVE_CNF_CHEN0_DISABLE					(0x0u<<0)
#define	IPC_RECEIVE_CNF_CHEN0_ENABLE					(0x1u<<0)

// GPMEM Configuration

#define	IPC_GPMEM_GPMEM									(0xFFFFFFFFu<<0)
#define	IPC_GPMEM_GPMEM_0								(0x1u<<0)
