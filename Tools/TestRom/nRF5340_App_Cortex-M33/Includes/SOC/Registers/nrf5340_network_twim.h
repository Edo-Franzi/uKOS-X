/*
; nrf5340_network_twim.
; =====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_network_twim equates.
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

// TWIM address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	TASKS_STARTRX;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	TASKS_STARTTX;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	TASKS_SUSPEND;
	volatile	uint32_t	TASKS_RESUME;
	volatile	uint32_t	RESERVED3[23];
	volatile	uint32_t	SUBSCRIBE_STARTRX;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	SUBSCRIBE_STARTTX;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	SUBSCRIBE_SUSPEND;
	volatile	uint32_t	SUBSCRIBE_RESUME;
	volatile	uint32_t	RESERVED7[24];
	volatile	uint32_t	EVENTS_STOPPED;
	volatile	uint32_t	RESERVED8[7];
	volatile	uint32_t	EVENTS_ERROR;
	volatile	uint32_t	RESERVED9[8];
	volatile	uint32_t	EVENTS_SUSPENDED;
	volatile	uint32_t	EVENTS_RXSTARTED;
	volatile	uint32_t	EVENTS_TXSTARTED;
	volatile	uint32_t	RESERVED10[2];
	volatile	uint32_t	EVENTS_LASTRX;
	volatile	uint32_t	EVENTS_LASTTX;
	volatile	uint32_t	RESERVED11[8];
	volatile	uint32_t	PUBLISH_STOPPED;
	volatile	uint32_t	RESERVED12[7];
	volatile	uint32_t	PUBLISH_ERROR;
	volatile	uint32_t	RESERVED13[8];
	volatile	uint32_t	PUBLISH_SUSPENDED;
	volatile	uint32_t	PUBLISH_RXSTARTED;
	volatile	uint32_t	PUBLISH_TXSTARTED;
	volatile	uint32_t	RESERVED14[2];
	volatile	uint32_t	PUBLISH_LASTRX;
	volatile	uint32_t	PUBLISH_LASTTX;
	volatile	uint32_t	RESERVED15[7];
	volatile	uint32_t	SHORTS;
	volatile	uint32_t	RESERVED16[63];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED17[110];
	volatile	uint32_t	ERRORSRC;
	volatile	uint32_t	RESERVED18[14];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	RESERVED19;
	volatile	uint32_t	PSEL_SCL;
	volatile	uint32_t	PSEL_SDA;
	volatile	uint32_t	RESERVED20[5];
	volatile	uint32_t	FREQUENCY;
	volatile	uint32_t	RESERVED21[3];
	volatile	uint32_t	RXD_PTR;
	volatile	uint32_t	RXD_MAXCNT;
	volatile	uint32_t	RXD_AMOUNT;
	volatile	uint32_t	RXD_LIST;
	volatile	uint32_t	TXD_PTR;
	volatile	uint32_t	TXD_MAXCNT;
	volatile	uint32_t	TXD_AMOUNT;
	volatile	uint32_t	TXD_LIST;
	volatile	uint32_t	RESERVED22[13];
	volatile	uint32_t	ADDRESS;
} TWIM_TypeDef;

#if (defined(__cplusplus))
#define	TWIM0_NS	reinterpret_cast<TWIM_TypeDef *>(0x41013000u)

#else
#define	TWIM0_NS	((TWIM_TypeDef *)0x41013000u)
#endif

// TASKS_STARTRX Configuration

#define	TWIM_TASKS_STARTRX_TASKS_STARTRX					(0x1u<<0)
#define	TWIM_TASKS_STARTRX_TASKS_STARTRX_TRIGGER			(0x1u<<0)

// TASKS_STARTTX Configuration

#define	TWIM_TASKS_STARTTX_TASKS_STARTTX					(0x1u<<0)
#define	TWIM_TASKS_STARTTX_TASKS_STARTTX_TRIGGER			(0x1u<<0)

// TASKS_STOP Configuration

#define	TWIM_TASKS_STOP_TASKS_STOP							(0x1u<<0)
#define	TWIM_TASKS_STOP_TASKS_STOP_TRIGGER					(0x1u<<0)

// TASKS_SUSPEND Configuration

#define	TWIM_TASKS_SUSPEND_TASKS_SUSPEND					(0x1u<<0)
#define	TWIM_TASKS_SUSPEND_TASKS_SUSPEND_TRIGGER			(0x1u<<0)

// TASKS_RESUME Configuration

#define	TWIM_TASKS_RESUME_TASKS_RESUME						(0x1u<<0)
#define	TWIM_TASKS_RESUME_TASKS_RESUME_TRIGGER				(0x1u<<0)

// SUBSCRIBE_STARTRX Configuration

#define	TWIM_SUBSCRIBE_STARTRX_EN							(0x1u<<31)
#define	TWIM_SUBSCRIBE_STARTRX_CHIDX						(0xFFu<<0)
#define	TWIM_SUBSCRIBE_STARTRX_CHIDX_0						(0x1u<<0)
#define	TWIM_SUBSCRIBE_STARTRX_EN_DISABLED					(0x0u<<31)
#define	TWIM_SUBSCRIBE_STARTRX_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_STARTTX Configuration

#define	TWIM_SUBSCRIBE_STARTTX_EN							(0x1u<<31)
#define	TWIM_SUBSCRIBE_STARTTX_CHIDX						(0xFFu<<0)
#define	TWIM_SUBSCRIBE_STARTTX_CHIDX_0						(0x1u<<0)
#define	TWIM_SUBSCRIBE_STARTTX_EN_DISABLED					(0x0u<<31)
#define	TWIM_SUBSCRIBE_STARTTX_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_STOP Configuration

#define	TWIM_SUBSCRIBE_STOP_EN								(0x1u<<31)
#define	TWIM_SUBSCRIBE_STOP_CHIDX							(0xFFu<<0)
#define	TWIM_SUBSCRIBE_STOP_CHIDX_0							(0x1u<<0)
#define	TWIM_SUBSCRIBE_STOP_EN_DISABLED						(0x0u<<31)
#define	TWIM_SUBSCRIBE_STOP_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_SUSPEND Configuration

#define	TWIM_SUBSCRIBE_SUSPEND_EN							(0x1u<<31)
#define	TWIM_SUBSCRIBE_SUSPEND_CHIDX						(0xFFu<<0)
#define	TWIM_SUBSCRIBE_SUSPEND_CHIDX_0						(0x1u<<0)
#define	TWIM_SUBSCRIBE_SUSPEND_EN_DISABLED					(0x0u<<31)
#define	TWIM_SUBSCRIBE_SUSPEND_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_RESUME Configuration

#define	TWIM_SUBSCRIBE_RESUME_EN							(0x1u<<31)
#define	TWIM_SUBSCRIBE_RESUME_CHIDX							(0xFFu<<0)
#define	TWIM_SUBSCRIBE_RESUME_CHIDX_0						(0x1u<<0)
#define	TWIM_SUBSCRIBE_RESUME_EN_DISABLED					(0x0u<<31)
#define	TWIM_SUBSCRIBE_RESUME_EN_ENABLED					(0x1u<<31)

// EVENTS_STOPPED Configuration

#define	TWIM_EVENTS_STOPPED_EVENTS_STOPPED					(0x1u<<0)
#define	TWIM_EVENTS_STOPPED_EVENTS_STOPPED_NOTGENERATED		(0x0u<<0)
#define	TWIM_EVENTS_STOPPED_EVENTS_STOPPED_GENERATED		(0x1u<<0)

// EVENTS_ERROR Configuration

#define	TWIM_EVENTS_ERROR_EVENTS_ERROR						(0x1u<<0)
#define	TWIM_EVENTS_ERROR_EVENTS_ERROR_NOTGENERATED			(0x0u<<0)
#define	TWIM_EVENTS_ERROR_EVENTS_ERROR_GENERATED			(0x1u<<0)

// EVENTS_SUSPENDED Configuration

#define	TWIM_EVENTS_SUSPENDED_EVENTS_SUSPENDED				(0x1u<<0)
#define	TWIM_EVENTS_SUSPENDED_EVENTS_SUSPENDED_NOTGENERATED	(0x0u<<0)
#define	TWIM_EVENTS_SUSPENDED_EVENTS_SUSPENDED_GENERATED	(0x1u<<0)

// EVENTS_RXSTARTED Configuration

#define	TWIM_EVENTS_RXSTARTED_EVENTS_RXSTARTED				(0x1u<<0)
#define	TWIM_EVENTS_RXSTARTED_EVENTS_RXSTARTED_NOTGENERATED	(0x0u<<0)
#define	TWIM_EVENTS_RXSTARTED_EVENTS_RXSTARTED_GENERATED	(0x1u<<0)

// EVENTS_TXSTARTED Configuration

#define	TWIM_EVENTS_TXSTARTED_EVENTS_TXSTARTED				(0x1u<<0)
#define	TWIM_EVENTS_TXSTARTED_EVENTS_TXSTARTED_NOTGENERATED	(0x0u<<0)
#define	TWIM_EVENTS_TXSTARTED_EVENTS_TXSTARTED_GENERATED	(0x1u<<0)

// EVENTS_LASTRX Configuration

#define	TWIM_EVENTS_LASTRX_EVENTS_LASTRX					(0x1u<<0)
#define	TWIM_EVENTS_LASTRX_EVENTS_LASTRX_NOTGENERATED		(0x0u<<0)
#define	TWIM_EVENTS_LASTRX_EVENTS_LASTRX_GENERATED			(0x1u<<0)

// EVENTS_LASTTX Configuration

#define	TWIM_EVENTS_LASTTX_EVENTS_LASTTX					(0x1u<<0)
#define	TWIM_EVENTS_LASTTX_EVENTS_LASTTX_NOTGENERATED		(0x0u<<0)
#define	TWIM_EVENTS_LASTTX_EVENTS_LASTTX_GENERATED			(0x1u<<0)

// PUBLISH_STOPPED Configuration

#define	TWIM_PUBLISH_STOPPED_EN								(0x1u<<31)
#define	TWIM_PUBLISH_STOPPED_CHIDX							(0xFFu<<0)
#define	TWIM_PUBLISH_STOPPED_CHIDX_0						(0x1u<<0)
#define	TWIM_PUBLISH_STOPPED_EN_DISABLED					(0x0u<<31)
#define	TWIM_PUBLISH_STOPPED_EN_ENABLED						(0x1u<<31)

// PUBLISH_ERROR Configuration

#define	TWIM_PUBLISH_ERROR_EN								(0x1u<<31)
#define	TWIM_PUBLISH_ERROR_CHIDX							(0xFFu<<0)
#define	TWIM_PUBLISH_ERROR_CHIDX_0							(0x1u<<0)
#define	TWIM_PUBLISH_ERROR_EN_DISABLED						(0x0u<<31)
#define	TWIM_PUBLISH_ERROR_EN_ENABLED						(0x1u<<31)

// PUBLISH_SUSPENDED Configuration

#define	TWIM_PUBLISH_SUSPENDED_EN							(0x1u<<31)
#define	TWIM_PUBLISH_SUSPENDED_CHIDX						(0xFFu<<0)
#define	TWIM_PUBLISH_SUSPENDED_CHIDX_0						(0x1u<<0)
#define	TWIM_PUBLISH_SUSPENDED_EN_DISABLED					(0x0u<<31)
#define	TWIM_PUBLISH_SUSPENDED_EN_ENABLED					(0x1u<<31)

// PUBLISH_RXSTARTED Configuration

#define	TWIM_PUBLISH_RXSTARTED_EN							(0x1u<<31)
#define	TWIM_PUBLISH_RXSTARTED_CHIDX						(0xFFu<<0)
#define	TWIM_PUBLISH_RXSTARTED_CHIDX_0						(0x1u<<0)
#define	TWIM_PUBLISH_RXSTARTED_EN_DISABLED					(0x0u<<31)
#define	TWIM_PUBLISH_RXSTARTED_EN_ENABLED					(0x1u<<31)

// PUBLISH_TXSTARTED Configuration

#define	TWIM_PUBLISH_TXSTARTED_EN							(0x1u<<31)
#define	TWIM_PUBLISH_TXSTARTED_CHIDX						(0xFFu<<0)
#define	TWIM_PUBLISH_TXSTARTED_CHIDX_0						(0x1u<<0)
#define	TWIM_PUBLISH_TXSTARTED_EN_DISABLED					(0x0u<<31)
#define	TWIM_PUBLISH_TXSTARTED_EN_ENABLED					(0x1u<<31)

// PUBLISH_LASTRX Configuration

#define	TWIM_PUBLISH_LASTRX_EN								(0x1u<<31)
#define	TWIM_PUBLISH_LASTRX_CHIDX							(0xFFu<<0)
#define	TWIM_PUBLISH_LASTRX_CHIDX_0							(0x1u<<0)
#define	TWIM_PUBLISH_LASTRX_EN_DISABLED						(0x0u<<31)
#define	TWIM_PUBLISH_LASTRX_EN_ENABLED						(0x1u<<31)

// PUBLISH_LASTTX Configuration

#define	TWIM_PUBLISH_LASTTX_EN								(0x1u<<31)
#define	TWIM_PUBLISH_LASTTX_CHIDX							(0xFFu<<0)
#define	TWIM_PUBLISH_LASTTX_CHIDX_0							(0x1u<<0)
#define	TWIM_PUBLISH_LASTTX_EN_DISABLED						(0x0u<<31)
#define	TWIM_PUBLISH_LASTTX_EN_ENABLED						(0x1u<<31)

// SHORTS Configuration

#define	TWIM_SHORTS_LASTRX_STOP								(0x1u<<12)
#define	TWIM_SHORTS_LASTRX_STARTTX							(0x1u<<10)
#define	TWIM_SHORTS_LASTTX_STOP								(0x1u<<9)
#define	TWIM_SHORTS_LASTTX_SUSPEND							(0x1u<<8)
#define	TWIM_SHORTS_LASTTX_STARTRX							(0x1u<<7)
#define	TWIM_SHORTS_LASTRX_STOP_DISABLED					(0x0u<<12)
#define	TWIM_SHORTS_LASTRX_STOP_ENABLED						(0x1u<<12)
#define	TWIM_SHORTS_LASTRX_STARTTX_DISABLED					(0x0u<<10)
#define	TWIM_SHORTS_LASTRX_STARTTX_ENABLED					(0x1u<<10)
#define	TWIM_SHORTS_LASTTX_STOP_DISABLED					(0x0u<<9)
#define	TWIM_SHORTS_LASTTX_STOP_ENABLED						(0x1u<<9)
#define	TWIM_SHORTS_LASTTX_SUSPEND_DISABLED					(0x0u<<8)
#define	TWIM_SHORTS_LASTTX_SUSPEND_ENABLED					(0x1u<<8)
#define	TWIM_SHORTS_LASTTX_STARTRX_DISABLED					(0x0u<<7)
#define	TWIM_SHORTS_LASTTX_STARTRX_ENABLED					(0x1u<<7)

// INTEN Configuration

#define	TWIM_INTEN_LASTTX									(0x1u<<24)
#define	TWIM_INTEN_LASTRX									(0x1u<<23)
#define	TWIM_INTEN_TXSTARTED								(0x1u<<20)
#define	TWIM_INTEN_RXSTARTED								(0x1u<<19)
#define	TWIM_INTEN_SUSPENDED								(0x1u<<18)
#define	TWIM_INTEN_ERROR									(0x1u<<9)
#define	TWIM_INTEN_STOPPED									(0x1u<<1)
#define	TWIM_INTEN_LASTTX_DISABLED							(0x0u<<24)
#define	TWIM_INTEN_LASTTX_ENABLED							(0x1u<<24)
#define	TWIM_INTEN_LASTRX_DISABLED							(0x0u<<23)
#define	TWIM_INTEN_LASTRX_ENABLED							(0x1u<<23)
#define	TWIM_INTEN_TXSTARTED_DISABLED						(0x0u<<20)
#define	TWIM_INTEN_TXSTARTED_ENABLED						(0x1u<<20)
#define	TWIM_INTEN_RXSTARTED_DISABLED						(0x0u<<19)
#define	TWIM_INTEN_RXSTARTED_ENABLED						(0x1u<<19)
#define	TWIM_INTEN_SUSPENDED_DISABLED						(0x0u<<18)
#define	TWIM_INTEN_SUSPENDED_ENABLED						(0x1u<<18)
#define	TWIM_INTEN_ERROR_DISABLED							(0x0u<<9)
#define	TWIM_INTEN_ERROR_ENABLED							(0x1u<<9)
#define	TWIM_INTEN_STOPPED_DISABLED							(0x0u<<1)
#define	TWIM_INTEN_STOPPED_ENABLED							(0x1u<<1)

// INTENSET Configuration

#define	TWIM_INTENSET_LASTTX								(0x1u<<24)
#define	TWIM_INTENSET_LASTRX								(0x1u<<23)
#define	TWIM_INTENSET_TXSTARTED								(0x1u<<20)
#define	TWIM_INTENSET_RXSTARTED								(0x1u<<19)
#define	TWIM_INTENSET_SUSPENDED								(0x1u<<18)
#define	TWIM_INTENSET_ERROR									(0x1u<<9)
#define	TWIM_INTENSET_STOPPED								(0x1u<<1)
#define	TWIM_INTENSET_LASTTX_DISABLED						(0x0u<<24)
#define	TWIM_INTENSET_LASTTX_ENABLED						(0x1u<<24)
#define	TWIM_INTENSET_LASTTX_SET							(0x1u<<24)
#define	TWIM_INTENSET_LASTRX_DISABLED						(0x0u<<23)
#define	TWIM_INTENSET_LASTRX_ENABLED						(0x1u<<23)
#define	TWIM_INTENSET_LASTRX_SET							(0x1u<<23)
#define	TWIM_INTENSET_TXSTARTED_DISABLED					(0x0u<<20)
#define	TWIM_INTENSET_TXSTARTED_ENABLED						(0x1u<<20)
#define	TWIM_INTENSET_TXSTARTED_SET							(0x1u<<20)
#define	TWIM_INTENSET_RXSTARTED_DISABLED					(0x0u<<19)
#define	TWIM_INTENSET_RXSTARTED_ENABLED						(0x1u<<19)
#define	TWIM_INTENSET_RXSTARTED_SET							(0x1u<<19)
#define	TWIM_INTENSET_SUSPENDED_DISABLED					(0x0u<<18)
#define	TWIM_INTENSET_SUSPENDED_ENABLED						(0x1u<<18)
#define	TWIM_INTENSET_SUSPENDED_SET							(0x1u<<18)
#define	TWIM_INTENSET_ERROR_DISABLED						(0x0u<<9)
#define	TWIM_INTENSET_ERROR_ENABLED							(0x1u<<9)
#define	TWIM_INTENSET_ERROR_SET								(0x1u<<9)
#define	TWIM_INTENSET_STOPPED_DISABLED						(0x0u<<1)
#define	TWIM_INTENSET_STOPPED_ENABLED						(0x1u<<1)
#define	TWIM_INTENSET_STOPPED_SET							(0x1u<<1)

// INTENCLR Configuration

#define	TWIM_INTENCLR_LASTTX								(0x1u<<24)
#define	TWIM_INTENCLR_LASTRX								(0x1u<<23)
#define	TWIM_INTENCLR_TXSTARTED								(0x1u<<20)
#define	TWIM_INTENCLR_RXSTARTED								(0x1u<<19)
#define	TWIM_INTENCLR_SUSPENDED								(0x1u<<18)
#define	TWIM_INTENCLR_ERROR									(0x1u<<9)
#define	TWIM_INTENCLR_STOPPED								(0x1u<<1)
#define	TWIM_INTENCLR_LASTTX_DISABLED						(0x0u<<24)
#define	TWIM_INTENCLR_LASTTX_ENABLED						(0x1u<<24)
#define	TWIM_INTENCLR_LASTTX_CLEAR							(0x1u<<24)
#define	TWIM_INTENCLR_LASTRX_DISABLED						(0x0u<<23)
#define	TWIM_INTENCLR_LASTRX_ENABLED						(0x1u<<23)
#define	TWIM_INTENCLR_LASTRX_CLEAR							(0x1u<<23)
#define	TWIM_INTENCLR_TXSTARTED_DISABLED					(0x0u<<20)
#define	TWIM_INTENCLR_TXSTARTED_ENABLED						(0x1u<<20)
#define	TWIM_INTENCLR_TXSTARTED_CLEAR						(0x1u<<20)
#define	TWIM_INTENCLR_RXSTARTED_DISABLED					(0x0u<<19)
#define	TWIM_INTENCLR_RXSTARTED_ENABLED						(0x1u<<19)
#define	TWIM_INTENCLR_RXSTARTED_CLEAR						(0x1u<<19)
#define	TWIM_INTENCLR_SUSPENDED_DISABLED					(0x0u<<18)
#define	TWIM_INTENCLR_SUSPENDED_ENABLED						(0x1u<<18)
#define	TWIM_INTENCLR_SUSPENDED_CLEAR						(0x1u<<18)
#define	TWIM_INTENCLR_ERROR_DISABLED						(0x0u<<9)
#define	TWIM_INTENCLR_ERROR_ENABLED							(0x1u<<9)
#define	TWIM_INTENCLR_ERROR_CLEAR							(0x1u<<9)
#define	TWIM_INTENCLR_STOPPED_DISABLED						(0x0u<<1)
#define	TWIM_INTENCLR_STOPPED_ENABLED						(0x1u<<1)
#define	TWIM_INTENCLR_STOPPED_CLEAR							(0x1u<<1)

// ERRORSRC Configuration

#define	TWIM_ERRORSRC_DNACK									(0x1u<<2)
#define	TWIM_ERRORSRC_ANACK									(0x1u<<1)
#define	TWIM_ERRORSRC_OVERRUN								(0x1u<<0)
#define	TWIM_ERRORSRC_DNACK_NOTRECEIVED						(0x0u<<2)
#define	TWIM_ERRORSRC_DNACK_RECEIVED						(0x1u<<2)
#define	TWIM_ERRORSRC_ANACK_NOTRECEIVED						(0x0u<<1)
#define	TWIM_ERRORSRC_ANACK_RECEIVED						(0x1u<<1)
#define	TWIM_ERRORSRC_OVERRUN_NOTRECEIVED					(0x0u<<0)
#define	TWIM_ERRORSRC_OVERRUN_RECEIVED						(0x1u<<0)

// ENABLE Configuration

#define	TWIM_ENABLE_ENABLE									(0xFu<<0)
#define	TWIM_ENABLE_ENABLE_0								(0x1u<<0)
#define	TWIM_ENABLE_ENABLE_DISABLED							(0x0u<<0)
#define	TWIM_ENABLE_ENABLE_ENABLED							(0x6u<<0)

// SCL Configuration

#define	TWIM_PSEL_SCL_CONNECT								(0x1u<<31)
#define	TWIM_PSEL_SCL_PORT									(0x1u<<5)
#define	TWIM_PSEL_SCL_PIN									(0x1Fu<<0)
#define	TWIM_PSEL_SCL_PIN_0									(0x1u<<0)
#define	TWIM_PSEL_SCL_CONNECT_DISCONNECTED					(0x1u<<31)
#define	TWIM_PSEL_SCL_CONNECT_CONNECTED						(0x0u<<31)

// SDA Configuration

#define	TWIM_PSEL_SDA_CONNECT								(0x1u<<31)
#define	TWIM_PSEL_SDA_PORT									(0x1u<<5)
#define	TWIM_PSEL_SDA_PIN									(0x1Fu<<0)
#define	TWIM_PSEL_SDA_PIN_0									(0x1u<<0)
#define	TWIM_PSEL_SDA_CONNECT_DISCONNECTED					(0x1u<<31)
#define	TWIM_PSEL_SDA_CONNECT_CONNECTED						(0x0u<<31)

// FREQUENCY Configuration

#define	TWIM_FREQUENCY_FREQUENCY							(0xFFFFFFFFu<<0)
#define	TWIM_FREQUENCY_FREQUENCY_0							(0x1u<<0)
#define	TWIM_FREQUENCY_FREQUENCY_K100						(0x1980000u<<0)
#define	TWIM_FREQUENCY_FREQUENCY_K250						(0x4000000u<<0)
#define	TWIM_FREQUENCY_FREQUENCY_K400						(0x6400000u<<0)
#define	TWIM_FREQUENCY_FREQUENCY_K1000						(0xFF00000u<<0)

// PTR Configuration

#define	TWIM_RXD_PTR_PTR									(0xFFFFFFFFu<<0)
#define	TWIM_RXD_PTR_PTR_0									(0x1u<<0)

// MAXCNT Configuration

#define	TWIM_RXD_MAXCNT_MAXCNT								(0xFFFFu<<0)
#define	TWIM_RXD_MAXCNT_MAXCNT_0							(0x1u<<0)

// AMOUNT Configuration

#define	TWIM_RXD_AMOUNT_AMOUNT								(0xFFFFu<<0)
#define	TWIM_RXD_AMOUNT_AMOUNT_0							(0x1u<<0)

// LIST Configuration

#define	TWIM_RXD_LIST_LIST									(0x7u<<0)
#define	TWIM_RXD_LIST_LIST_0								(0x1u<<0)
#define	TWIM_RXD_LIST_LIST_DISABLED							(0x0u<<0)
#define	TWIM_RXD_LIST_LIST_ARRAYLIST						(0x1u<<0)

// PTR Configuration

#define	TWIM_TXD_PTR_PTR									(0xFFFFFFFFu<<0)
#define	TWIM_TXD_PTR_PTR_0									(0x1u<<0)

// MAXCNT Configuration

#define	TWIM_TXD_MAXCNT_MAXCNT								(0xFFFFu<<0)
#define	TWIM_TXD_MAXCNT_MAXCNT_0							(0x1u<<0)

// AMOUNT Configuration

#define	TWIM_TXD_AMOUNT_AMOUNT								(0xFFFFu<<0)
#define	TWIM_TXD_AMOUNT_AMOUNT_0							(0x1u<<0)

// LIST Configuration

#define	TWIM_TXD_LIST_LIST									(0x7u<<0)
#define	TWIM_TXD_LIST_LIST_0								(0x1u<<0)
#define	TWIM_TXD_LIST_LIST_DISABLED							(0x0u<<0)
#define	TWIM_TXD_LIST_LIST_ARRAYLIST						(0x1u<<0)

// ADDRESS Configuration

#define	TWIM_ADDRESS_ADDRESS								(0x7Fu<<0)
#define	TWIM_ADDRESS_ADDRESS_0								(0x1u<<0)
