/*
; nrf5340_application_twis.
; =========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_twis equates.
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

// TWIS address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	RESERVED0[5];
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	TASKS_SUSPEND;
	volatile	uint32_t	TASKS_RESUME;
	volatile	uint32_t	RESERVED2[3];
	volatile	uint32_t	TASKS_PREPARERX;
	volatile	uint32_t	TASKS_PREPARETX;
	volatile	uint32_t	RESERVED3[23];
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	SUBSCRIBE_SUSPEND;
	volatile	uint32_t	SUBSCRIBE_RESUME;
	volatile	uint32_t	RESERVED5[3];
	volatile	uint32_t	SUBSCRIBE_PREPARERX;
	volatile	uint32_t	SUBSCRIBE_PREPARETX;
	volatile	uint32_t	RESERVED6[19];
	volatile	uint32_t	EVENTS_STOPPED;
	volatile	uint32_t	RESERVED7[7];
	volatile	uint32_t	EVENTS_ERROR;
	volatile	uint32_t	RESERVED8[9];
	volatile	uint32_t	EVENTS_RXSTARTED;
	volatile	uint32_t	EVENTS_TXSTARTED;
	volatile	uint32_t	RESERVED9[4];
	volatile	uint32_t	EVENTS_WRITE;
	volatile	uint32_t	EVENTS_READ;
	volatile	uint32_t	RESERVED10[6];
	volatile	uint32_t	PUBLISH_STOPPED;
	volatile	uint32_t	RESERVED11[7];
	volatile	uint32_t	PUBLISH_ERROR;
	volatile	uint32_t	RESERVED12[9];
	volatile	uint32_t	PUBLISH_RXSTARTED;
	volatile	uint32_t	PUBLISH_TXSTARTED;
	volatile	uint32_t	RESERVED13[4];
	volatile	uint32_t	PUBLISH_WRITE;
	volatile	uint32_t	PUBLISH_READ;
	volatile	uint32_t	RESERVED14[5];
	volatile	uint32_t	SHORTS;
	volatile	uint32_t	RESERVED15[63];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED16[113];
	volatile	uint32_t	ERRORSRC;
	volatile	uint32_t	MATCH;
	volatile	uint32_t	RESERVED17[10];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	RESERVED18;
	volatile	uint32_t	PSEL_SCL;
	volatile	uint32_t	PSEL_SDA;
	volatile	uint32_t	RESERVED19[9];
	volatile	uint32_t	RXD_PTR;
	volatile	uint32_t	RXD_MAXCNT;
	volatile	uint32_t	RXD_AMOUNT;
	volatile	uint32_t	RXD_LIST;
	volatile	uint32_t	TXD_PTR;
	volatile	uint32_t	TXD_MAXCNT;
	volatile	uint32_t	TXD_AMOUNT;
	volatile	uint32_t	TXD_LIST;
	volatile	uint32_t	RESERVED20[13];
	volatile	uint32_t	ADDRESS[2];
	volatile	uint32_t	RESERVED21;
	volatile	uint32_t	CONFIG;
	volatile	uint32_t	RESERVED22[10];
	volatile	uint32_t	ORC;
} TWIS_TypeDef;

#if (defined(__cplusplus))
#define	TWIS0_NS	reinterpret_cast<TWIS_TypeDef *>(0x40008000u)
#define	TWIS0_S		reinterpret_cast<TWIS_TypeDef *>(0x50008000u)
#define	TWIS1_NS	reinterpret_cast<TWIS_TypeDef *>(0x40009000u)
#define	TWIS1_S		reinterpret_cast<TWIS_TypeDef *>(0x50009000u)
#define	TWIS2_NS	reinterpret_cast<TWIS_TypeDef *>(0x4000B000u)
#define	TWIS2_S		reinterpret_cast<TWIS_TypeDef *>(0x5000B000u)
#define	TWIS3_NS	reinterpret_cast<TWIS_TypeDef *>(0x4000C000u)
#define	TWIS3_S		reinterpret_cast<TWIS_TypeDef *>(0x5000C000u)

#else
#define	TWIS0_NS	((TWIS_TypeDef *)0x40008000u)
#define	TWIS0_S		((TWIS_TypeDef *)0x50008000u)
#define	TWIS1_NS	((TWIS_TypeDef *)0x40009000u)
#define	TWIS1_S		((TWIS_TypeDef *)0x50009000u)
#define	TWIS2_NS	((TWIS_TypeDef *)0x4000B000u)
#define	TWIS2_S		((TWIS_TypeDef *)0x5000B000u)
#define	TWIS3_NS	((TWIS_TypeDef *)0x4000C000u)
#define	TWIS3_S		((TWIS_TypeDef *)0x5000C000u)
#endif

// TASKS_STOP Configuration

#define	TWIS_TASKS_STOP_TASKS_STOP							(0x1u<<0)
#define	TWIS_TASKS_STOP_TASKS_STOP_TRIGGER					(0x1u<<0)

// TASKS_SUSPEND Configuration

#define	TWIS_TASKS_SUSPEND_TASKS_SUSPEND					(0x1u<<0)
#define	TWIS_TASKS_SUSPEND_TASKS_SUSPEND_TRIGGER			(0x1u<<0)

// TASKS_RESUME Configuration

#define	TWIS_TASKS_RESUME_TASKS_RESUME						(0x1u<<0)
#define	TWIS_TASKS_RESUME_TASKS_RESUME_TRIGGER				(0x1u<<0)

// TASKS_PREPARERX Configuration

#define	TWIS_TASKS_PREPARERX_TASKS_PREPARERX				(0x1u<<0)
#define	TWIS_TASKS_PREPARERX_TASKS_PREPARERX_TRIGGER		(0x1u<<0)

// TASKS_PREPARETX Configuration

#define	TWIS_TASKS_PREPARETX_TASKS_PREPARETX				(0x1u<<0)
#define	TWIS_TASKS_PREPARETX_TASKS_PREPARETX_TRIGGER		(0x1u<<0)

// SUBSCRIBE_STOP Configuration

#define	TWIS_SUBSCRIBE_STOP_EN								(0x1u<<31)
#define	TWIS_SUBSCRIBE_STOP_CHIDX							(0xFFu<<0)
#define	TWIS_SUBSCRIBE_STOP_CHIDX_0							(0x1u<<0)
#define	TWIS_SUBSCRIBE_STOP_EN_DISABLED						(0x0u<<31)
#define	TWIS_SUBSCRIBE_STOP_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_SUSPEND Configuration

#define	TWIS_SUBSCRIBE_SUSPEND_EN							(0x1u<<31)
#define	TWIS_SUBSCRIBE_SUSPEND_CHIDX						(0xFFu<<0)
#define	TWIS_SUBSCRIBE_SUSPEND_CHIDX_0						(0x1u<<0)
#define	TWIS_SUBSCRIBE_SUSPEND_EN_DISABLED					(0x0u<<31)
#define	TWIS_SUBSCRIBE_SUSPEND_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_RESUME Configuration

#define	TWIS_SUBSCRIBE_RESUME_EN							(0x1u<<31)
#define	TWIS_SUBSCRIBE_RESUME_CHIDX							(0xFFu<<0)
#define	TWIS_SUBSCRIBE_RESUME_CHIDX_0						(0x1u<<0)
#define	TWIS_SUBSCRIBE_RESUME_EN_DISABLED					(0x0u<<31)
#define	TWIS_SUBSCRIBE_RESUME_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_PREPARERX Configuration

#define	TWIS_SUBSCRIBE_PREPARERX_EN							(0x1u<<31)
#define	TWIS_SUBSCRIBE_PREPARERX_CHIDX						(0xFFu<<0)
#define	TWIS_SUBSCRIBE_PREPARERX_CHIDX_0					(0x1u<<0)
#define	TWIS_SUBSCRIBE_PREPARERX_EN_DISABLED				(0x0u<<31)
#define	TWIS_SUBSCRIBE_PREPARERX_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_PREPARETX Configuration

#define	TWIS_SUBSCRIBE_PREPARETX_EN							(0x1u<<31)
#define	TWIS_SUBSCRIBE_PREPARETX_CHIDX						(0xFFu<<0)
#define	TWIS_SUBSCRIBE_PREPARETX_CHIDX_0					(0x1u<<0)
#define	TWIS_SUBSCRIBE_PREPARETX_EN_DISABLED				(0x0u<<31)
#define	TWIS_SUBSCRIBE_PREPARETX_EN_ENABLED					(0x1u<<31)

// EVENTS_STOPPED Configuration

#define	TWIS_EVENTS_STOPPED_EVENTS_STOPPED					(0x1u<<0)
#define	TWIS_EVENTS_STOPPED_EVENTS_STOPPED_NOTGENERATED		(0x0u<<0)
#define	TWIS_EVENTS_STOPPED_EVENTS_STOPPED_GENERATED		(0x1u<<0)

// EVENTS_ERROR Configuration

#define	TWIS_EVENTS_ERROR_EVENTS_ERROR						(0x1u<<0)
#define	TWIS_EVENTS_ERROR_EVENTS_ERROR_NOTGENERATED			(0x0u<<0)
#define	TWIS_EVENTS_ERROR_EVENTS_ERROR_GENERATED			(0x1u<<0)

// EVENTS_RXSTARTED Configuration

#define	TWIS_EVENTS_RXSTARTED_EVENTS_RXSTARTED				(0x1u<<0)
#define	TWIS_EVENTS_RXSTARTED_EVENTS_RXSTARTED_NOTGENERATED	(0x0u<<0)
#define	TWIS_EVENTS_RXSTARTED_EVENTS_RXSTARTED_GENERATED	(0x1u<<0)

// EVENTS_TXSTARTED Configuration

#define	TWIS_EVENTS_TXSTARTED_EVENTS_TXSTARTED				(0x1u<<0)
#define	TWIS_EVENTS_TXSTARTED_EVENTS_TXSTARTED_NOTGENERATED	(0x0u<<0)
#define	TWIS_EVENTS_TXSTARTED_EVENTS_TXSTARTED_GENERATED	(0x1u<<0)

// EVENTS_WRITE Configuration

#define	TWIS_EVENTS_WRITE_EVENTS_WRITE						(0x1u<<0)
#define	TWIS_EVENTS_WRITE_EVENTS_WRITE_NOTGENERATED			(0x0u<<0)
#define	TWIS_EVENTS_WRITE_EVENTS_WRITE_GENERATED			(0x1u<<0)

// EVENTS_READ Configuration

#define	TWIS_EVENTS_READ_EVENTS_READ						(0x1u<<0)
#define	TWIS_EVENTS_READ_EVENTS_READ_NOTGENERATED			(0x0u<<0)
#define	TWIS_EVENTS_READ_EVENTS_READ_GENERATED				(0x1u<<0)

// PUBLISH_STOPPED Configuration

#define	TWIS_PUBLISH_STOPPED_EN								(0x1u<<31)
#define	TWIS_PUBLISH_STOPPED_CHIDX							(0xFFu<<0)
#define	TWIS_PUBLISH_STOPPED_CHIDX_0						(0x1u<<0)
#define	TWIS_PUBLISH_STOPPED_EN_DISABLED					(0x0u<<31)
#define	TWIS_PUBLISH_STOPPED_EN_ENABLED						(0x1u<<31)

// PUBLISH_ERROR Configuration

#define	TWIS_PUBLISH_ERROR_EN								(0x1u<<31)
#define	TWIS_PUBLISH_ERROR_CHIDX							(0xFFu<<0)
#define	TWIS_PUBLISH_ERROR_CHIDX_0							(0x1u<<0)
#define	TWIS_PUBLISH_ERROR_EN_DISABLED						(0x0u<<31)
#define	TWIS_PUBLISH_ERROR_EN_ENABLED						(0x1u<<31)

// PUBLISH_RXSTARTED Configuration

#define	TWIS_PUBLISH_RXSTARTED_EN							(0x1u<<31)
#define	TWIS_PUBLISH_RXSTARTED_CHIDX						(0xFFu<<0)
#define	TWIS_PUBLISH_RXSTARTED_CHIDX_0						(0x1u<<0)
#define	TWIS_PUBLISH_RXSTARTED_EN_DISABLED					(0x0u<<31)
#define	TWIS_PUBLISH_RXSTARTED_EN_ENABLED					(0x1u<<31)

// PUBLISH_TXSTARTED Configuration

#define	TWIS_PUBLISH_TXSTARTED_EN							(0x1u<<31)
#define	TWIS_PUBLISH_TXSTARTED_CHIDX						(0xFFu<<0)
#define	TWIS_PUBLISH_TXSTARTED_CHIDX_0						(0x1u<<0)
#define	TWIS_PUBLISH_TXSTARTED_EN_DISABLED					(0x0u<<31)
#define	TWIS_PUBLISH_TXSTARTED_EN_ENABLED					(0x1u<<31)

// PUBLISH_WRITE Configuration

#define	TWIS_PUBLISH_WRITE_EN								(0x1u<<31)
#define	TWIS_PUBLISH_WRITE_CHIDX							(0xFFu<<0)
#define	TWIS_PUBLISH_WRITE_CHIDX_0							(0x1u<<0)
#define	TWIS_PUBLISH_WRITE_EN_DISABLED						(0x0u<<31)
#define	TWIS_PUBLISH_WRITE_EN_ENABLED						(0x1u<<31)

// PUBLISH_READ Configuration

#define	TWIS_PUBLISH_READ_EN								(0x1u<<31)
#define	TWIS_PUBLISH_READ_CHIDX								(0xFFu<<0)
#define	TWIS_PUBLISH_READ_CHIDX_0							(0x1u<<0)
#define	TWIS_PUBLISH_READ_EN_DISABLED						(0x0u<<31)
#define	TWIS_PUBLISH_READ_EN_ENABLED						(0x1u<<31)

// SHORTS Configuration

#define	TWIS_SHORTS_READ_SUSPEND							(0x1u<<14)
#define	TWIS_SHORTS_WRITE_SUSPEND							(0x1u<<13)
#define	TWIS_SHORTS_READ_SUSPEND_DISABLED					(0x0u<<14)
#define	TWIS_SHORTS_READ_SUSPEND_ENABLED					(0x1u<<14)
#define	TWIS_SHORTS_WRITE_SUSPEND_DISABLED					(0x0u<<13)
#define	TWIS_SHORTS_WRITE_SUSPEND_ENABLED					(0x1u<<13)

// INTEN Configuration

#define	TWIS_INTEN_READ										(0x1u<<26)
#define	TWIS_INTEN_WRITE									(0x1u<<25)
#define	TWIS_INTEN_TXSTARTED								(0x1u<<20)
#define	TWIS_INTEN_RXSTARTED								(0x1u<<19)
#define	TWIS_INTEN_ERROR									(0x1u<<9)
#define	TWIS_INTEN_STOPPED									(0x1u<<1)
#define	TWIS_INTEN_READ_DISABLED							(0x0u<<26)
#define	TWIS_INTEN_READ_ENABLED								(0x1u<<26)
#define	TWIS_INTEN_WRITE_DISABLED							(0x0u<<25)
#define	TWIS_INTEN_WRITE_ENABLED							(0x1u<<25)
#define	TWIS_INTEN_TXSTARTED_DISABLED						(0x0u<<20)
#define	TWIS_INTEN_TXSTARTED_ENABLED						(0x1u<<20)
#define	TWIS_INTEN_RXSTARTED_DISABLED						(0x0u<<19)
#define	TWIS_INTEN_RXSTARTED_ENABLED						(0x1u<<19)
#define	TWIS_INTEN_ERROR_DISABLED							(0x0u<<9)
#define	TWIS_INTEN_ERROR_ENABLED							(0x1u<<9)
#define	TWIS_INTEN_STOPPED_DISABLED							(0x0u<<1)
#define	TWIS_INTEN_STOPPED_ENABLED							(0x1u<<1)

// INTENSET Configuration

#define	TWIS_INTENSET_READ									(0x1u<<26)
#define	TWIS_INTENSET_WRITE									(0x1u<<25)
#define	TWIS_INTENSET_TXSTARTED								(0x1u<<20)
#define	TWIS_INTENSET_RXSTARTED								(0x1u<<19)
#define	TWIS_INTENSET_ERROR									(0x1u<<9)
#define	TWIS_INTENSET_STOPPED								(0x1u<<1)
#define	TWIS_INTENSET_READ_DISABLED							(0x0u<<26)
#define	TWIS_INTENSET_READ_ENABLED							(0x1u<<26)
#define	TWIS_INTENSET_READ_SET								(0x1u<<26)
#define	TWIS_INTENSET_WRITE_DISABLED						(0x0u<<25)
#define	TWIS_INTENSET_WRITE_ENABLED							(0x1u<<25)
#define	TWIS_INTENSET_WRITE_SET								(0x1u<<25)
#define	TWIS_INTENSET_TXSTARTED_DISABLED					(0x0u<<20)
#define	TWIS_INTENSET_TXSTARTED_ENABLED						(0x1u<<20)
#define	TWIS_INTENSET_TXSTARTED_SET							(0x1u<<20)
#define	TWIS_INTENSET_RXSTARTED_DISABLED					(0x0u<<19)
#define	TWIS_INTENSET_RXSTARTED_ENABLED						(0x1u<<19)
#define	TWIS_INTENSET_RXSTARTED_SET							(0x1u<<19)
#define	TWIS_INTENSET_ERROR_DISABLED						(0x0u<<9)
#define	TWIS_INTENSET_ERROR_ENABLED							(0x1u<<9)
#define	TWIS_INTENSET_ERROR_SET								(0x1u<<9)
#define	TWIS_INTENSET_STOPPED_DISABLED						(0x0u<<1)
#define	TWIS_INTENSET_STOPPED_ENABLED						(0x1u<<1)
#define	TWIS_INTENSET_STOPPED_SET							(0x1u<<1)

// INTENCLR Configuration

#define	TWIS_INTENCLR_READ									(0x1u<<26)
#define	TWIS_INTENCLR_WRITE									(0x1u<<25)
#define	TWIS_INTENCLR_TXSTARTED								(0x1u<<20)
#define	TWIS_INTENCLR_RXSTARTED								(0x1u<<19)
#define	TWIS_INTENCLR_ERROR									(0x1u<<9)
#define	TWIS_INTENCLR_STOPPED								(0x1u<<1)
#define	TWIS_INTENCLR_READ_DISABLED							(0x0u<<26)
#define	TWIS_INTENCLR_READ_ENABLED							(0x1u<<26)
#define	TWIS_INTENCLR_READ_CLEAR							(0x1u<<26)
#define	TWIS_INTENCLR_WRITE_DISABLED						(0x0u<<25)
#define	TWIS_INTENCLR_WRITE_ENABLED							(0x1u<<25)
#define	TWIS_INTENCLR_WRITE_CLEAR							(0x1u<<25)
#define	TWIS_INTENCLR_TXSTARTED_DISABLED					(0x0u<<20)
#define	TWIS_INTENCLR_TXSTARTED_ENABLED						(0x1u<<20)
#define	TWIS_INTENCLR_TXSTARTED_CLEAR						(0x1u<<20)
#define	TWIS_INTENCLR_RXSTARTED_DISABLED					(0x0u<<19)
#define	TWIS_INTENCLR_RXSTARTED_ENABLED						(0x1u<<19)
#define	TWIS_INTENCLR_RXSTARTED_CLEAR						(0x1u<<19)
#define	TWIS_INTENCLR_ERROR_DISABLED						(0x0u<<9)
#define	TWIS_INTENCLR_ERROR_ENABLED							(0x1u<<9)
#define	TWIS_INTENCLR_ERROR_CLEAR							(0x1u<<9)
#define	TWIS_INTENCLR_STOPPED_DISABLED						(0x0u<<1)
#define	TWIS_INTENCLR_STOPPED_ENABLED						(0x1u<<1)
#define	TWIS_INTENCLR_STOPPED_CLEAR							(0x1u<<1)

// ERRORSRC Configuration

#define	TWIS_ERRORSRC_OVERREAD								(0x1u<<3)
#define	TWIS_ERRORSRC_DNACK									(0x1u<<2)
#define	TWIS_ERRORSRC_OVERFLOW								(0x1u<<0)
#define	TWIS_ERRORSRC_OVERREAD_NOTDETECTED					(0x0u<<3)
#define	TWIS_ERRORSRC_OVERREAD_DETECTED						(0x1u<<3)
#define	TWIS_ERRORSRC_DNACK_NOTRECEIVED						(0x0u<<2)
#define	TWIS_ERRORSRC_DNACK_RECEIVED						(0x1u<<2)
#define	TWIS_ERRORSRC_OVERFLOW_NOTDETECTED					(0x0u<<0)
#define	TWIS_ERRORSRC_OVERFLOW_DETECTED						(0x1u<<0)

// MATCH Configuration

#define	TWIS_MATCH_MATCH									(0x1u<<0)

// ENABLE Configuration

#define	TWIS_ENABLE_ENABLE									(0xFu<<0)
#define	TWIS_ENABLE_ENABLE_0								(0x1u<<0)
#define	TWIS_ENABLE_ENABLE_DISABLED							(0x0u<<0)
#define	TWIS_ENABLE_ENABLE_ENABLED							(0x9u<<0)

// SCL Configuration

#define	TWIS_PSEL_SCL_CONNECT								(0x1u<<31)
#define	TWIS_PSEL_SCL_PORT									(0x1u<<5)
#define	TWIS_PSEL_SCL_PIN									(0x1Fu<<0)
#define	TWIS_PSEL_SCL_PIN_0									(0x1u<<0)
#define	TWIS_PSEL_SCL_CONNECT_DISCONNECTED					(0x1u<<31)
#define	TWIS_PSEL_SCL_CONNECT_CONNECTED						(0x0u<<31)

// SDA Configuration

#define	TWIS_PSEL_SDA_CONNECT								(0x1u<<31)
#define	TWIS_PSEL_SDA_PORT									(0x1u<<5)
#define	TWIS_PSEL_SDA_PIN									(0x1Fu<<0)
#define	TWIS_PSEL_SDA_PIN_0									(0x1u<<0)
#define	TWIS_PSEL_SDA_CONNECT_DISCONNECTED					(0x1u<<31)
#define	TWIS_PSEL_SDA_CONNECT_CONNECTED						(0x0u<<31)

// PTR Configuration

#define	TWIS_RXD_PTR_PTR									(0xFFFFFFFFu<<0)
#define	TWIS_RXD_PTR_PTR_0									(0x1u<<0)

// MAXCNT Configuration

#define	TWIS_RXD_MAXCNT_MAXCNT								(0xFFFFu<<0)
#define	TWIS_RXD_MAXCNT_MAXCNT_0							(0x1u<<0)

// AMOUNT Configuration

#define	TWIS_RXD_AMOUNT_AMOUNT								(0xFFFFu<<0)
#define	TWIS_RXD_AMOUNT_AMOUNT_0							(0x1u<<0)

// LIST Configuration

#define	TWIS_RXD_LIST_LIST									(0x3u<<0)
#define	TWIS_RXD_LIST_LIST_0								(0x1u<<0)
#define	TWIS_RXD_LIST_LIST_DISABLED							(0x0u<<0)
#define	TWIS_RXD_LIST_LIST_ARRAYLIST						(0x1u<<0)

// PTR Configuration

#define	TWIS_TXD_PTR_PTR									(0xFFFFFFFFu<<0)
#define	TWIS_TXD_PTR_PTR_0									(0x1u<<0)

// MAXCNT Configuration

#define	TWIS_TXD_MAXCNT_MAXCNT								(0xFFFFu<<0)
#define	TWIS_TXD_MAXCNT_MAXCNT_0							(0x1u<<0)

// AMOUNT Configuration

#define	TWIS_TXD_AMOUNT_AMOUNT								(0xFFFFu<<0)
#define	TWIS_TXD_AMOUNT_AMOUNT_0							(0x1u<<0)

// LIST Configuration

#define	TWIS_TXD_LIST_LIST									(0x3u<<0)
#define	TWIS_TXD_LIST_LIST_0								(0x1u<<0)
#define	TWIS_TXD_LIST_LIST_DISABLED							(0x0u<<0)
#define	TWIS_TXD_LIST_LIST_ARRAYLIST						(0x1u<<0)

// ADDRESS Configuration

#define	TWIS_ADDRESS_ADDRESS								(0x7Fu<<0)
#define	TWIS_ADDRESS_ADDRESS_0								(0x1u<<0)

// CONFIG Configuration

#define	TWIS_CONFIG_ADDRESS1								(0x1u<<1)
#define	TWIS_CONFIG_ADDRESS0								(0x1u<<0)
#define	TWIS_CONFIG_ADDRESS1_DISABLED						(0x0u<<1)
#define	TWIS_CONFIG_ADDRESS1_ENABLED						(0x1u<<1)
#define	TWIS_CONFIG_ADDRESS0_DISABLED						(0x0u<<0)
#define	TWIS_CONFIG_ADDRESS0_ENABLED						(0x1u<<0)

// ORC Configuration

#define	TWIS_ORC_ORC										(0xFFu<<0)
#define	TWIS_ORC_ORC_0										(0x1u<<0)
