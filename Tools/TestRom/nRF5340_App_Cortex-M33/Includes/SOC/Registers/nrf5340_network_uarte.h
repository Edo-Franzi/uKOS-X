/*
; nrf5340_network_uarte.
; ======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_network_uarte equates.
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

// UARTE address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	TASKS_STARTRX;
	volatile	uint32_t	TASKS_STOPRX;
	volatile	uint32_t	TASKS_STARTTX;
	volatile	uint32_t	TASKS_STOPTX;
	volatile	uint32_t	RESERVED0[7];
	volatile	uint32_t	TASKS_FLUSHRX;
	volatile	uint32_t	RESERVED1[20];
	volatile	uint32_t	SUBSCRIBE_STARTRX;
	volatile	uint32_t	SUBSCRIBE_STOPRX;
	volatile	uint32_t	SUBSCRIBE_STARTTX;
	volatile	uint32_t	SUBSCRIBE_STOPTX;
	volatile	uint32_t	RESERVED2[7];
	volatile	uint32_t	SUBSCRIBE_FLUSHRX;
	volatile	uint32_t	RESERVED3[20];
	volatile	uint32_t	EVENTS_CTS;
	volatile	uint32_t	EVENTS_NCTS;
	volatile	uint32_t	EVENTS_RXDRDY;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	EVENTS_ENDRX;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	EVENTS_TXDRDY;
	volatile	uint32_t	EVENTS_ENDTX;
	volatile	uint32_t	EVENTS_ERROR;
	volatile	uint32_t	RESERVED6[7];
	volatile	uint32_t	EVENTS_RXTO;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	EVENTS_RXSTARTED;
	volatile	uint32_t	EVENTS_TXSTARTED;
	volatile	uint32_t	RESERVED8;
	volatile	uint32_t	EVENTS_TXSTOPPED;
	volatile	uint32_t	RESERVED9[9];
	volatile	uint32_t	PUBLISH_CTS;
	volatile	uint32_t	PUBLISH_NCTS;
	volatile	uint32_t	PUBLISH_RXDRDY;
	volatile	uint32_t	RESERVED10;
	volatile	uint32_t	PUBLISH_ENDRX;
	volatile	uint32_t	RESERVED11[2];
	volatile	uint32_t	PUBLISH_TXDRDY;
	volatile	uint32_t	PUBLISH_ENDTX;
	volatile	uint32_t	PUBLISH_ERROR;
	volatile	uint32_t	RESERVED12[7];
	volatile	uint32_t	PUBLISH_RXTO;
	volatile	uint32_t	RESERVED13;
	volatile	uint32_t	PUBLISH_RXSTARTED;
	volatile	uint32_t	PUBLISH_TXSTARTED;
	volatile	uint32_t	RESERVED14;
	volatile	uint32_t	PUBLISH_TXSTOPPED;
	volatile	uint32_t	RESERVED15[9];
	volatile	uint32_t	SHORTS;
	volatile	uint32_t	RESERVED16[63];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED17[93];
	volatile	uint32_t	ERRORSRC;
	volatile	uint32_t	RESERVED18[31];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	RESERVED19;
	volatile	uint32_t	PSEL_RTS;
	volatile	uint32_t	PSEL_TXD;
	volatile	uint32_t	PSEL_CTS;
	volatile	uint32_t	PSEL_RXD;
	volatile	uint32_t	RESERVED20[3];
	volatile	uint32_t	BAUDRATE;
	volatile	uint32_t	RESERVED21[3];
	volatile	uint32_t	RXD_PTR;
	volatile	uint32_t	RXD_MAXCNT;
	volatile	uint32_t	RXD_AMOUNT;
	volatile	uint32_t	RESERVED22;
	volatile	uint32_t	TXD_PTR;
	volatile	uint32_t	TXD_MAXCNT;
	volatile	uint32_t	TXD_AMOUNT;
	volatile	uint32_t	RESERVED23[7];
	volatile	uint32_t	CONFIG;
} UARTE_TypeDef;

#if (defined(__cplusplus))
#define	UARTE0_NS	reinterpret_cast<UARTE_TypeDef *>(0x41013000u)

#else
#define	UARTE0_NS	((UARTE_TypeDef *)0x41013000u)
#endif

// TASKS_STARTRX Configuration

#define	UARTE_TASKS_STARTRX_TASKS_STARTRX						(0x1u<<0)
#define	UARTE_TASKS_STARTRX_TASKS_STARTRX_TRIGGER				(0x1u<<0)

// TASKS_STOPRX Configuration

#define	UARTE_TASKS_STOPRX_TASKS_STOPRX							(0x1u<<0)
#define	UARTE_TASKS_STOPRX_TASKS_STOPRX_TRIGGER					(0x1u<<0)

// TASKS_STARTTX Configuration

#define	UARTE_TASKS_STARTTX_TASKS_STARTTX						(0x1u<<0)
#define	UARTE_TASKS_STARTTX_TASKS_STARTTX_TRIGGER				(0x1u<<0)

// TASKS_STOPTX Configuration

#define	UARTE_TASKS_STOPTX_TASKS_STOPTX							(0x1u<<0)
#define	UARTE_TASKS_STOPTX_TASKS_STOPTX_TRIGGER					(0x1u<<0)

// TASKS_FLUSHRX Configuration

#define	UARTE_TASKS_FLUSHRX_TASKS_FLUSHRX						(0x1u<<0)
#define	UARTE_TASKS_FLUSHRX_TASKS_FLUSHRX_TRIGGER				(0x1u<<0)

// SUBSCRIBE_STARTRX Configuration

#define	UARTE_SUBSCRIBE_STARTRX_EN								(0x1u<<31)
#define	UARTE_SUBSCRIBE_STARTRX_CHIDX							(0xFFu<<0)
#define	UARTE_SUBSCRIBE_STARTRX_CHIDX_0							(0x1u<<0)
#define	UARTE_SUBSCRIBE_STARTRX_EN_DISABLED						(0x0u<<31)
#define	UARTE_SUBSCRIBE_STARTRX_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_STOPRX Configuration

#define	UARTE_SUBSCRIBE_STOPRX_EN								(0x1u<<31)
#define	UARTE_SUBSCRIBE_STOPRX_CHIDX							(0xFFu<<0)
#define	UARTE_SUBSCRIBE_STOPRX_CHIDX_0							(0x1u<<0)
#define	UARTE_SUBSCRIBE_STOPRX_EN_DISABLED						(0x0u<<31)
#define	UARTE_SUBSCRIBE_STOPRX_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_STARTTX Configuration

#define	UARTE_SUBSCRIBE_STARTTX_EN								(0x1u<<31)
#define	UARTE_SUBSCRIBE_STARTTX_CHIDX							(0xFFu<<0)
#define	UARTE_SUBSCRIBE_STARTTX_CHIDX_0							(0x1u<<0)
#define	UARTE_SUBSCRIBE_STARTTX_EN_DISABLED						(0x0u<<31)
#define	UARTE_SUBSCRIBE_STARTTX_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_STOPTX Configuration

#define	UARTE_SUBSCRIBE_STOPTX_EN								(0x1u<<31)
#define	UARTE_SUBSCRIBE_STOPTX_CHIDX							(0xFFu<<0)
#define	UARTE_SUBSCRIBE_STOPTX_CHIDX_0							(0x1u<<0)
#define	UARTE_SUBSCRIBE_STOPTX_EN_DISABLED						(0x0u<<31)
#define	UARTE_SUBSCRIBE_STOPTX_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_FLUSHRX Configuration

#define	UARTE_SUBSCRIBE_FLUSHRX_EN								(0x1u<<31)
#define	UARTE_SUBSCRIBE_FLUSHRX_CHIDX							(0xFFu<<0)
#define	UARTE_SUBSCRIBE_FLUSHRX_CHIDX_0							(0x1u<<0)
#define	UARTE_SUBSCRIBE_FLUSHRX_EN_DISABLED						(0x0u<<31)
#define	UARTE_SUBSCRIBE_FLUSHRX_EN_ENABLED						(0x1u<<31)

// EVENTS_CTS Configuration

#define	UARTE_EVENTS_CTS_EVENTS_CTS								(0x1u<<0)
#define	UARTE_EVENTS_CTS_EVENTS_CTS_NOTGENERATED				(0x0u<<0)
#define	UARTE_EVENTS_CTS_EVENTS_CTS_GENERATED					(0x1u<<0)

// EVENTS_NCTS Configuration

#define	UARTE_EVENTS_NCTS_EVENTS_NCTS							(0x1u<<0)
#define	UARTE_EVENTS_NCTS_EVENTS_NCTS_NOTGENERATED				(0x0u<<0)
#define	UARTE_EVENTS_NCTS_EVENTS_NCTS_GENERATED					(0x1u<<0)

// EVENTS_RXDRDY Configuration

#define	UARTE_EVENTS_RXDRDY_EVENTS_RXDRDY						(0x1u<<0)
#define	UARTE_EVENTS_RXDRDY_EVENTS_RXDRDY_NOTGENERATED			(0x0u<<0)
#define	UARTE_EVENTS_RXDRDY_EVENTS_RXDRDY_GENERATED				(0x1u<<0)

// EVENTS_ENDRX Configuration

#define	UARTE_EVENTS_ENDRX_EVENTS_ENDRX							(0x1u<<0)
#define	UARTE_EVENTS_ENDRX_EVENTS_ENDRX_NOTGENERATED			(0x0u<<0)
#define	UARTE_EVENTS_ENDRX_EVENTS_ENDRX_GENERATED				(0x1u<<0)

// EVENTS_TXDRDY Configuration

#define	UARTE_EVENTS_TXDRDY_EVENTS_TXDRDY						(0x1u<<0)
#define	UARTE_EVENTS_TXDRDY_EVENTS_TXDRDY_NOTGENERATED			(0x0u<<0)
#define	UARTE_EVENTS_TXDRDY_EVENTS_TXDRDY_GENERATED				(0x1u<<0)

// EVENTS_ENDTX Configuration

#define	UARTE_EVENTS_ENDTX_EVENTS_ENDTX							(0x1u<<0)
#define	UARTE_EVENTS_ENDTX_EVENTS_ENDTX_NOTGENERATED			(0x0u<<0)
#define	UARTE_EVENTS_ENDTX_EVENTS_ENDTX_GENERATED				(0x1u<<0)

// EVENTS_ERROR Configuration

#define	UARTE_EVENTS_ERROR_EVENTS_ERROR							(0x1u<<0)
#define	UARTE_EVENTS_ERROR_EVENTS_ERROR_NOTGENERATED			(0x0u<<0)
#define	UARTE_EVENTS_ERROR_EVENTS_ERROR_GENERATED				(0x1u<<0)

// EVENTS_RXTO Configuration

#define	UARTE_EVENTS_RXTO_EVENTS_RXTO							(0x1u<<0)
#define	UARTE_EVENTS_RXTO_EVENTS_RXTO_NOTGENERATED				(0x0u<<0)
#define	UARTE_EVENTS_RXTO_EVENTS_RXTO_GENERATED					(0x1u<<0)

// EVENTS_RXSTARTED Configuration

#define	UARTE_EVENTS_RXSTARTED_EVENTS_RXSTARTED					(0x1u<<0)
#define	UARTE_EVENTS_RXSTARTED_EVENTS_RXSTARTED_NOTGENERATED	(0x0u<<0)
#define	UARTE_EVENTS_RXSTARTED_EVENTS_RXSTARTED_GENERATED		(0x1u<<0)

// EVENTS_TXSTARTED Configuration

#define	UARTE_EVENTS_TXSTARTED_EVENTS_TXSTARTED					(0x1u<<0)
#define	UARTE_EVENTS_TXSTARTED_EVENTS_TXSTARTED_NOTGENERATED	(0x0u<<0)
#define	UARTE_EVENTS_TXSTARTED_EVENTS_TXSTARTED_GENERATED		(0x1u<<0)

// EVENTS_TXSTOPPED Configuration

#define	UARTE_EVENTS_TXSTOPPED_EVENTS_TXSTOPPED					(0x1u<<0)
#define	UARTE_EVENTS_TXSTOPPED_EVENTS_TXSTOPPED_NOTGENERATED	(0x0u<<0)
#define	UARTE_EVENTS_TXSTOPPED_EVENTS_TXSTOPPED_GENERATED		(0x1u<<0)

// PUBLISH_CTS Configuration

#define	UARTE_PUBLISH_CTS_EN									(0x1u<<31)
#define	UARTE_PUBLISH_CTS_CHIDX									(0xFFu<<0)
#define	UARTE_PUBLISH_CTS_CHIDX_0								(0x1u<<0)
#define	UARTE_PUBLISH_CTS_EN_DISABLED							(0x0u<<31)
#define	UARTE_PUBLISH_CTS_EN_ENABLED							(0x1u<<31)

// PUBLISH_NCTS Configuration

#define	UARTE_PUBLISH_NCTS_EN									(0x1u<<31)
#define	UARTE_PUBLISH_NCTS_CHIDX								(0xFFu<<0)
#define	UARTE_PUBLISH_NCTS_CHIDX_0								(0x1u<<0)
#define	UARTE_PUBLISH_NCTS_EN_DISABLED							(0x0u<<31)
#define	UARTE_PUBLISH_NCTS_EN_ENABLED							(0x1u<<31)

// PUBLISH_RXDRDY Configuration

#define	UARTE_PUBLISH_RXDRDY_EN									(0x1u<<31)
#define	UARTE_PUBLISH_RXDRDY_CHIDX								(0xFFu<<0)
#define	UARTE_PUBLISH_RXDRDY_CHIDX_0							(0x1u<<0)
#define	UARTE_PUBLISH_RXDRDY_EN_DISABLED						(0x0u<<31)
#define	UARTE_PUBLISH_RXDRDY_EN_ENABLED							(0x1u<<31)

// PUBLISH_ENDRX Configuration

#define	UARTE_PUBLISH_ENDRX_EN									(0x1u<<31)
#define	UARTE_PUBLISH_ENDRX_CHIDX								(0xFFu<<0)
#define	UARTE_PUBLISH_ENDRX_CHIDX_0								(0x1u<<0)
#define	UARTE_PUBLISH_ENDRX_EN_DISABLED							(0x0u<<31)
#define	UARTE_PUBLISH_ENDRX_EN_ENABLED							(0x1u<<31)

// PUBLISH_TXDRDY Configuration

#define	UARTE_PUBLISH_TXDRDY_EN									(0x1u<<31)
#define	UARTE_PUBLISH_TXDRDY_CHIDX								(0xFFu<<0)
#define	UARTE_PUBLISH_TXDRDY_CHIDX_0							(0x1u<<0)
#define	UARTE_PUBLISH_TXDRDY_EN_DISABLED						(0x0u<<31)
#define	UARTE_PUBLISH_TXDRDY_EN_ENABLED							(0x1u<<31)

// PUBLISH_ENDTX Configuration

#define	UARTE_PUBLISH_ENDTX_EN									(0x1u<<31)
#define	UARTE_PUBLISH_ENDTX_CHIDX								(0xFFu<<0)
#define	UARTE_PUBLISH_ENDTX_CHIDX_0								(0x1u<<0)
#define	UARTE_PUBLISH_ENDTX_EN_DISABLED							(0x0u<<31)
#define	UARTE_PUBLISH_ENDTX_EN_ENABLED							(0x1u<<31)

// PUBLISH_ERROR Configuration

#define	UARTE_PUBLISH_ERROR_EN									(0x1u<<31)
#define	UARTE_PUBLISH_ERROR_CHIDX								(0xFFu<<0)
#define	UARTE_PUBLISH_ERROR_CHIDX_0								(0x1u<<0)
#define	UARTE_PUBLISH_ERROR_EN_DISABLED							(0x0u<<31)
#define	UARTE_PUBLISH_ERROR_EN_ENABLED							(0x1u<<31)

// PUBLISH_RXTO Configuration

#define	UARTE_PUBLISH_RXTO_EN									(0x1u<<31)
#define	UARTE_PUBLISH_RXTO_CHIDX								(0xFFu<<0)
#define	UARTE_PUBLISH_RXTO_CHIDX_0								(0x1u<<0)
#define	UARTE_PUBLISH_RXTO_EN_DISABLED							(0x0u<<31)
#define	UARTE_PUBLISH_RXTO_EN_ENABLED							(0x1u<<31)

// PUBLISH_RXSTARTED Configuration

#define	UARTE_PUBLISH_RXSTARTED_EN								(0x1u<<31)
#define	UARTE_PUBLISH_RXSTARTED_CHIDX							(0xFFu<<0)
#define	UARTE_PUBLISH_RXSTARTED_CHIDX_0							(0x1u<<0)
#define	UARTE_PUBLISH_RXSTARTED_EN_DISABLED						(0x0u<<31)
#define	UARTE_PUBLISH_RXSTARTED_EN_ENABLED						(0x1u<<31)

// PUBLISH_TXSTARTED Configuration

#define	UARTE_PUBLISH_TXSTARTED_EN								(0x1u<<31)
#define	UARTE_PUBLISH_TXSTARTED_CHIDX							(0xFFu<<0)
#define	UARTE_PUBLISH_TXSTARTED_CHIDX_0							(0x1u<<0)
#define	UARTE_PUBLISH_TXSTARTED_EN_DISABLED						(0x0u<<31)
#define	UARTE_PUBLISH_TXSTARTED_EN_ENABLED						(0x1u<<31)

// PUBLISH_TXSTOPPED Configuration

#define	UARTE_PUBLISH_TXSTOPPED_EN								(0x1u<<31)
#define	UARTE_PUBLISH_TXSTOPPED_CHIDX							(0xFFu<<0)
#define	UARTE_PUBLISH_TXSTOPPED_CHIDX_0							(0x1u<<0)
#define	UARTE_PUBLISH_TXSTOPPED_EN_DISABLED						(0x0u<<31)
#define	UARTE_PUBLISH_TXSTOPPED_EN_ENABLED						(0x1u<<31)

// SHORTS Configuration

#define	UARTE_SHORTS_ENDRX_STOPRX								(0x1u<<6)
#define	UARTE_SHORTS_ENDRX_STARTRX								(0x1u<<5)
#define	UARTE_SHORTS_ENDRX_STOPRX_DISABLED						(0x0u<<6)
#define	UARTE_SHORTS_ENDRX_STOPRX_ENABLED						(0x1u<<6)
#define	UARTE_SHORTS_ENDRX_STARTRX_DISABLED						(0x0u<<5)
#define	UARTE_SHORTS_ENDRX_STARTRX_ENABLED						(0x1u<<5)

// INTEN Configuration

#define	UARTE_INTEN_TXSTOPPED									(0x1u<<22)
#define	UARTE_INTEN_TXSTARTED									(0x1u<<20)
#define	UARTE_INTEN_RXSTARTED									(0x1u<<19)
#define	UARTE_INTEN_RXTO										(0x1u<<17)
#define	UARTE_INTEN_ERROR										(0x1u<<9)
#define	UARTE_INTEN_ENDTX										(0x1u<<8)
#define	UARTE_INTEN_TXDRDY										(0x1u<<7)
#define	UARTE_INTEN_ENDRX										(0x1u<<4)
#define	UARTE_INTEN_RXDRDY										(0x1u<<2)
#define	UARTE_INTEN_NCTS										(0x1u<<1)
#define	UARTE_INTEN_CTS											(0x1u<<0)
#define	UARTE_INTEN_TXSTOPPED_DISABLED							(0x0u<<22)
#define	UARTE_INTEN_TXSTOPPED_ENABLED							(0x1u<<22)
#define	UARTE_INTEN_TXSTARTED_DISABLED							(0x0u<<20)
#define	UARTE_INTEN_TXSTARTED_ENABLED							(0x1u<<20)
#define	UARTE_INTEN_RXSTARTED_DISABLED							(0x0u<<19)
#define	UARTE_INTEN_RXSTARTED_ENABLED							(0x1u<<19)
#define	UARTE_INTEN_RXTO_DISABLED								(0x0u<<17)
#define	UARTE_INTEN_RXTO_ENABLED								(0x1u<<17)
#define	UARTE_INTEN_ERROR_DISABLED								(0x0u<<9)
#define	UARTE_INTEN_ERROR_ENABLED								(0x1u<<9)
#define	UARTE_INTEN_ENDTX_DISABLED								(0x0u<<8)
#define	UARTE_INTEN_ENDTX_ENABLED								(0x1u<<8)
#define	UARTE_INTEN_TXDRDY_DISABLED								(0x0u<<7)
#define	UARTE_INTEN_TXDRDY_ENABLED								(0x1u<<7)
#define	UARTE_INTEN_ENDRX_DISABLED								(0x0u<<4)
#define	UARTE_INTEN_ENDRX_ENABLED								(0x1u<<4)
#define	UARTE_INTEN_RXDRDY_DISABLED								(0x0u<<2)
#define	UARTE_INTEN_RXDRDY_ENABLED								(0x1u<<2)
#define	UARTE_INTEN_NCTS_DISABLED								(0x0u<<1)
#define	UARTE_INTEN_NCTS_ENABLED								(0x1u<<1)
#define	UARTE_INTEN_CTS_DISABLED								(0x0u<<0)
#define	UARTE_INTEN_CTS_ENABLED									(0x1u<<0)

// INTENSET Configuration

#define	UARTE_INTENSET_TXSTOPPED								(0x1u<<22)
#define	UARTE_INTENSET_TXSTARTED								(0x1u<<20)
#define	UARTE_INTENSET_RXSTARTED								(0x1u<<19)
#define	UARTE_INTENSET_RXTO										(0x1u<<17)
#define	UARTE_INTENSET_ERROR									(0x1u<<9)
#define	UARTE_INTENSET_ENDTX									(0x1u<<8)
#define	UARTE_INTENSET_TXDRDY									(0x1u<<7)
#define	UARTE_INTENSET_ENDRX									(0x1u<<4)
#define	UARTE_INTENSET_RXDRDY									(0x1u<<2)
#define	UARTE_INTENSET_NCTS										(0x1u<<1)
#define	UARTE_INTENSET_CTS										(0x1u<<0)
#define	UARTE_INTENSET_TXSTOPPED_DISABLED						(0x0u<<22)
#define	UARTE_INTENSET_TXSTOPPED_ENABLED						(0x1u<<22)
#define	UARTE_INTENSET_TXSTOPPED_SET							(0x1u<<22)
#define	UARTE_INTENSET_TXSTARTED_DISABLED						(0x0u<<20)
#define	UARTE_INTENSET_TXSTARTED_ENABLED						(0x1u<<20)
#define	UARTE_INTENSET_TXSTARTED_SET							(0x1u<<20)
#define	UARTE_INTENSET_RXSTARTED_DISABLED						(0x0u<<19)
#define	UARTE_INTENSET_RXSTARTED_ENABLED						(0x1u<<19)
#define	UARTE_INTENSET_RXSTARTED_SET							(0x1u<<19)
#define	UARTE_INTENSET_RXTO_DISABLED							(0x0u<<17)
#define	UARTE_INTENSET_RXTO_ENABLED								(0x1u<<17)
#define	UARTE_INTENSET_RXTO_SET									(0x1u<<17)
#define	UARTE_INTENSET_ERROR_DISABLED							(0x0u<<9)
#define	UARTE_INTENSET_ERROR_ENABLED							(0x1u<<9)
#define	UARTE_INTENSET_ERROR_SET								(0x1u<<9)
#define	UARTE_INTENSET_ENDTX_DISABLED							(0x0u<<8)
#define	UARTE_INTENSET_ENDTX_ENABLED							(0x1u<<8)
#define	UARTE_INTENSET_ENDTX_SET								(0x1u<<8)
#define	UARTE_INTENSET_TXDRDY_DISABLED							(0x0u<<7)
#define	UARTE_INTENSET_TXDRDY_ENABLED							(0x1u<<7)
#define	UARTE_INTENSET_TXDRDY_SET								(0x1u<<7)
#define	UARTE_INTENSET_ENDRX_DISABLED							(0x0u<<4)
#define	UARTE_INTENSET_ENDRX_ENABLED							(0x1u<<4)
#define	UARTE_INTENSET_ENDRX_SET								(0x1u<<4)
#define	UARTE_INTENSET_RXDRDY_DISABLED							(0x0u<<2)
#define	UARTE_INTENSET_RXDRDY_ENABLED							(0x1u<<2)
#define	UARTE_INTENSET_RXDRDY_SET								(0x1u<<2)
#define	UARTE_INTENSET_NCTS_DISABLED							(0x0u<<1)
#define	UARTE_INTENSET_NCTS_ENABLED								(0x1u<<1)
#define	UARTE_INTENSET_NCTS_SET									(0x1u<<1)
#define	UARTE_INTENSET_CTS_DISABLED								(0x0u<<0)
#define	UARTE_INTENSET_CTS_ENABLED								(0x1u<<0)
#define	UARTE_INTENSET_CTS_SET									(0x1u<<0)

// INTENCLR Configuration

#define	UARTE_INTENCLR_TXSTOPPED								(0x1u<<22)
#define	UARTE_INTENCLR_TXSTARTED								(0x1u<<20)
#define	UARTE_INTENCLR_RXSTARTED								(0x1u<<19)
#define	UARTE_INTENCLR_RXTO										(0x1u<<17)
#define	UARTE_INTENCLR_ERROR									(0x1u<<9)
#define	UARTE_INTENCLR_ENDTX									(0x1u<<8)
#define	UARTE_INTENCLR_TXDRDY									(0x1u<<7)
#define	UARTE_INTENCLR_ENDRX									(0x1u<<4)
#define	UARTE_INTENCLR_RXDRDY									(0x1u<<2)
#define	UARTE_INTENCLR_NCTS										(0x1u<<1)
#define	UARTE_INTENCLR_CTS										(0x1u<<0)
#define	UARTE_INTENCLR_TXSTOPPED_DISABLED						(0x0u<<22)
#define	UARTE_INTENCLR_TXSTOPPED_ENABLED						(0x1u<<22)
#define	UARTE_INTENCLR_TXSTOPPED_CLEAR							(0x1u<<22)
#define	UARTE_INTENCLR_TXSTARTED_DISABLED						(0x0u<<20)
#define	UARTE_INTENCLR_TXSTARTED_ENABLED						(0x1u<<20)
#define	UARTE_INTENCLR_TXSTARTED_CLEAR							(0x1u<<20)
#define	UARTE_INTENCLR_RXSTARTED_DISABLED						(0x0u<<19)
#define	UARTE_INTENCLR_RXSTARTED_ENABLED						(0x1u<<19)
#define	UARTE_INTENCLR_RXSTARTED_CLEAR							(0x1u<<19)
#define	UARTE_INTENCLR_RXTO_DISABLED							(0x0u<<17)
#define	UARTE_INTENCLR_RXTO_ENABLED								(0x1u<<17)
#define	UARTE_INTENCLR_RXTO_CLEAR								(0x1u<<17)
#define	UARTE_INTENCLR_ERROR_DISABLED							(0x0u<<9)
#define	UARTE_INTENCLR_ERROR_ENABLED							(0x1u<<9)
#define	UARTE_INTENCLR_ERROR_CLEAR								(0x1u<<9)
#define	UARTE_INTENCLR_ENDTX_DISABLED							(0x0u<<8)
#define	UARTE_INTENCLR_ENDTX_ENABLED							(0x1u<<8)
#define	UARTE_INTENCLR_ENDTX_CLEAR								(0x1u<<8)
#define	UARTE_INTENCLR_TXDRDY_DISABLED							(0x0u<<7)
#define	UARTE_INTENCLR_TXDRDY_ENABLED							(0x1u<<7)
#define	UARTE_INTENCLR_TXDRDY_CLEAR								(0x1u<<7)
#define	UARTE_INTENCLR_ENDRX_DISABLED							(0x0u<<4)
#define	UARTE_INTENCLR_ENDRX_ENABLED							(0x1u<<4)
#define	UARTE_INTENCLR_ENDRX_CLEAR								(0x1u<<4)
#define	UARTE_INTENCLR_RXDRDY_DISABLED							(0x0u<<2)
#define	UARTE_INTENCLR_RXDRDY_ENABLED							(0x1u<<2)
#define	UARTE_INTENCLR_RXDRDY_CLEAR								(0x1u<<2)
#define	UARTE_INTENCLR_NCTS_DISABLED							(0x0u<<1)
#define	UARTE_INTENCLR_NCTS_ENABLED								(0x1u<<1)
#define	UARTE_INTENCLR_NCTS_CLEAR								(0x1u<<1)
#define	UARTE_INTENCLR_CTS_DISABLED								(0x0u<<0)
#define	UARTE_INTENCLR_CTS_ENABLED								(0x1u<<0)
#define	UARTE_INTENCLR_CTS_CLEAR								(0x1u<<0)

// ERRORSRC Configuration

#define	UARTE_ERRORSRC_BREAK									(0x1u<<3)
#define	UARTE_ERRORSRC_FRAMING									(0x1u<<2)
#define	UARTE_ERRORSRC_PARITY									(0x1u<<1)
#define	UARTE_ERRORSRC_OVERRUN									(0x1u<<0)
#define	UARTE_ERRORSRC_BREAK_NOTPRESENT							(0x0u<<3)
#define	UARTE_ERRORSRC_BREAK_PRESENT							(0x1u<<3)
#define	UARTE_ERRORSRC_FRAMING_NOTPRESENT						(0x0u<<2)
#define	UARTE_ERRORSRC_FRAMING_PRESENT							(0x1u<<2)
#define	UARTE_ERRORSRC_PARITY_NOTPRESENT						(0x0u<<1)
#define	UARTE_ERRORSRC_PARITY_PRESENT							(0x1u<<1)
#define	UARTE_ERRORSRC_OVERRUN_NOTPRESENT						(0x0u<<0)
#define	UARTE_ERRORSRC_OVERRUN_PRESENT							(0x1u<<0)

// ENABLE Configuration

#define	UARTE_ENABLE_ENABLE										(0xFu<<0)
#define	UARTE_ENABLE_ENABLE_0									(0x1u<<0)
#define	UARTE_ENABLE_ENABLE_DISABLED							(0x0u<<0)
#define	UARTE_ENABLE_ENABLE_ENABLED								(0x8u<<0)

// RTS Configuration

#define	UARTE_PSEL_RTS_CONNECT									(0x1u<<31)
#define	UARTE_PSEL_RTS_PORT										(0x1u<<5)
#define	UARTE_PSEL_RTS_PIN										(0x1Fu<<0)
#define	UARTE_PSEL_RTS_PIN_0									(0x1u<<0)
#define	UARTE_PSEL_RTS_CONNECT_DISCONNECTED						(0x1u<<31)
#define	UARTE_PSEL_RTS_CONNECT_CONNECTED						(0x0u<<31)

// TXD Configuration

#define	UARTE_PSEL_TXD_CONNECT									(0x1u<<31)
#define	UARTE_PSEL_TXD_PORT										(0x1u<<5)
#define	UARTE_PSEL_TXD_PIN										(0x1Fu<<0)
#define	UARTE_PSEL_TXD_PIN_0									(0x1u<<0)
#define	UARTE_PSEL_TXD_CONNECT_DISCONNECTED						(0x1u<<31)
#define	UARTE_PSEL_TXD_CONNECT_CONNECTED						(0x0u<<31)

// CTS Configuration

#define	UARTE_PSEL_CTS_CONNECT									(0x1u<<31)
#define	UARTE_PSEL_CTS_PORT										(0x1u<<5)
#define	UARTE_PSEL_CTS_PIN										(0x1Fu<<0)
#define	UARTE_PSEL_CTS_PIN_0									(0x1u<<0)
#define	UARTE_PSEL_CTS_CONNECT_DISCONNECTED						(0x1u<<31)
#define	UARTE_PSEL_CTS_CONNECT_CONNECTED						(0x0u<<31)

// RXD Configuration

#define	UARTE_PSEL_RXD_CONNECT									(0x1u<<31)
#define	UARTE_PSEL_RXD_PORT										(0x1u<<5)
#define	UARTE_PSEL_RXD_PIN										(0x1Fu<<0)
#define	UARTE_PSEL_RXD_PIN_0									(0x1u<<0)
#define	UARTE_PSEL_RXD_CONNECT_DISCONNECTED						(0x1u<<31)
#define	UARTE_PSEL_RXD_CONNECT_CONNECTED						(0x0u<<31)

// BAUDRATE Configuration

#define	UARTE_BAUDRATE_BAUDRATE									(0xFFFFFFFFu<<0)
#define	UARTE_BAUDRATE_BAUDRATE_0								(0x1u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD1200						(0x4F000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD2400						(0x9D000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD4800						(0x13B000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD9600						(0x275000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD14400						(0x3AF000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD19200						(0x4EA000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD28800						(0x75C000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD31250						(0x800000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD38400						(0x9D0000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD56000						(0xE50000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD57600						(0xEB0000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD76800						(0x13A9000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD115200						(0x1D60000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD230400						(0x3B00000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD250000						(0x4000000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD460800						(0x7400000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD921600						(0xF000000u<<0)
#define	UARTE_BAUDRATE_BAUDRATE_BAUD1M							(0x10000000u<<0)

// PTR Configuration

#define	UARTE_RXD_PTR_PTR										(0xFFFFFFFFu<<0)
#define	UARTE_RXD_PTR_PTR_0										(0x1u<<0)

// MAXCNT Configuration

#define	UARTE_RXD_MAXCNT_MAXCNT									(0xFFFFu<<0)
#define	UARTE_RXD_MAXCNT_MAXCNT_0								(0x1u<<0)

// AMOUNT Configuration

#define	UARTE_RXD_AMOUNT_AMOUNT									(0xFFFFu<<0)
#define	UARTE_RXD_AMOUNT_AMOUNT_0								(0x1u<<0)

// PTR Configuration

#define	UARTE_TXD_PTR_PTR										(0xFFFFFFFFu<<0)
#define	UARTE_TXD_PTR_PTR_0										(0x1u<<0)

// MAXCNT Configuration

#define	UARTE_TXD_MAXCNT_MAXCNT									(0xFFFFu<<0)
#define	UARTE_TXD_MAXCNT_MAXCNT_0								(0x1u<<0)

// AMOUNT Configuration

#define	UARTE_TXD_AMOUNT_AMOUNT									(0xFFFFu<<0)
#define	UARTE_TXD_AMOUNT_AMOUNT_0								(0x1u<<0)

// CONFIG Configuration

#define	UARTE_CONFIG_PARITYTYPE									(0x1u<<8)
#define	UARTE_CONFIG_STOP										(0x1u<<4)
#define	UARTE_CONFIG_PARITY										(0x7u<<1)
#define	UARTE_CONFIG_PARITY_0									(0x1u<<1)
#define	UARTE_CONFIG_HWFC										(0x1u<<0)
#define	UARTE_CONFIG_PARITYTYPE_EVEN							(0x0u<<8)
#define	UARTE_CONFIG_PARITYTYPE_ODD								(0x1u<<8)
#define	UARTE_CONFIG_STOP_ONE									(0x0u<<4)
#define	UARTE_CONFIG_STOP_TWO									(0x1u<<4)
#define	UARTE_CONFIG_PARITY_EXCLUDED							(0x0u<<1)
#define	UARTE_CONFIG_PARITY_INCLUDED							(0x7u<<1)
#define	UARTE_CONFIG_HWFC_DISABLED								(0x0u<<0)
#define	UARTE_CONFIG_HWFC_ENABLED								(0x1u<<0)
