/*
; nrf5340_application_spim.
; =========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_spim equates.
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

// SPIM address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	TASKS_START;
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	TASKS_SUSPEND;
	volatile	uint32_t	TASKS_RESUME;
	volatile	uint32_t	RESERVED2[27];
	volatile	uint32_t	SUBSCRIBE_START;
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	SUBSCRIBE_SUSPEND;
	volatile	uint32_t	SUBSCRIBE_RESUME;
	volatile	uint32_t	RESERVED4[24];
	volatile	uint32_t	EVENTS_STOPPED;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	EVENTS_ENDRX;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	EVENTS_END;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	EVENTS_ENDTX;
	volatile	uint32_t	RESERVED8[10];
	volatile	uint32_t	EVENTS_STARTED;
	volatile	uint32_t	RESERVED9[13];
	volatile	uint32_t	PUBLISH_STOPPED;
	volatile	uint32_t	RESERVED10[2];
	volatile	uint32_t	PUBLISH_ENDRX;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	PUBLISH_END;
	volatile	uint32_t	RESERVED12;
	volatile	uint32_t	PUBLISH_ENDTX;
	volatile	uint32_t	RESERVED13[10];
	volatile	uint32_t	PUBLISH_STARTED;
	volatile	uint32_t	RESERVED14[12];
	volatile	uint32_t	SHORTS;
	volatile	uint32_t	RESERVED15[64];
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED16[61];
	volatile	uint32_t	STALLSTAT;
	volatile	uint32_t	RESERVED17[63];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	RESERVED18;
	volatile	uint32_t	PSEL_SCK;
	volatile	uint32_t	PSEL_MOSI;
	volatile	uint32_t	PSEL_MISO;
	volatile	uint32_t	PSEL_CSN;
	volatile	uint32_t	RESERVED19[3];
	volatile	uint32_t	FREQUENCY;
	volatile	uint32_t	RESERVED20[3];
	volatile	uint32_t	RXD_PTR;
	volatile	uint32_t	RXD_MAXCNT;
	volatile	uint32_t	RXD_AMOUNT;
	volatile	uint32_t	RXD_LIST;
	volatile	uint32_t	TXD_PTR;
	volatile	uint32_t	TXD_MAXCNT;
	volatile	uint32_t	TXD_AMOUNT;
	volatile	uint32_t	TXD_LIST;
	volatile	uint32_t	CONFIG;
	volatile	uint32_t	RESERVED21[2];
	volatile	uint32_t	IFTIMING_RXDELAY;
	volatile	uint32_t	IFTIMING_CSNDUR;
	volatile	uint32_t	CSNPOL;
	volatile	uint32_t	PSELDCX;
	volatile	uint32_t	DCXCNT;
	volatile	uint32_t	RESERVED22[19];
	volatile	uint32_t	ORC;
} SPIM_TypeDef;

#if (defined(__cplusplus))
#define	SPIM0_NS	reinterpret_cast<SPIM_TypeDef *>(0x40008000u)
#define	SPIM0_S		reinterpret_cast<SPIM_TypeDef *>(0x50008000u)
#define	SPIM1_NS	reinterpret_cast<SPIM_TypeDef *>(0x40009000u)
#define	SPIM1_S		reinterpret_cast<SPIM_TypeDef *>(0x50009000u)
#define	SPIM4_NS	reinterpret_cast<SPIM_TypeDef *>(0x4000A000u)
#define	SPIM4_S		reinterpret_cast<SPIM_TypeDef *>(0x5000A000u)
#define	SPIM2_NS	reinterpret_cast<SPIM_TypeDef *>(0x4000B000u)
#define	SPIM2_S		reinterpret_cast<SPIM_TypeDef *>(0x5000B000u)
#define	SPIM3_NS	reinterpret_cast<SPIM_TypeDef *>(0x4000C000u)
#define	SPIM3_S		reinterpret_cast<SPIM_TypeDef *>(0x5000C000u)

#else
#define	SPIM0_NS	((SPIM_TypeDef *)0x40008000u)
#define	SPIM0_S		((SPIM_TypeDef *)0x50008000u)
#define	SPIM1_NS	((SPIM_TypeDef *)0x40009000u)
#define	SPIM1_S		((SPIM_TypeDef *)0x50009000u)
#define	SPIM4_NS	((SPIM_TypeDef *)0x4000A000u)
#define	SPIM4_S		((SPIM_TypeDef *)0x5000A000u)
#define	SPIM2_NS	((SPIM_TypeDef *)0x4000B000u)
#define	SPIM2_S		((SPIM_TypeDef *)0x5000B000u)
#define	SPIM3_NS	((SPIM_TypeDef *)0x4000C000u)
#define	SPIM3_S		((SPIM_TypeDef *)0x5000C000u)
#endif

// TASKS_START Configuration

#define	SPIM_TASKS_START_TASKS_START							(0x1u<<0)
#define	SPIM_TASKS_START_TASKS_START_TRIGGER					(0x1u<<0)

// TASKS_STOP Configuration

#define	SPIM_TASKS_STOP_TASKS_STOP								(0x1u<<0)
#define	SPIM_TASKS_STOP_TASKS_STOP_TRIGGER						(0x1u<<0)

// TASKS_SUSPEND Configuration

#define	SPIM_TASKS_SUSPEND_TASKS_SUSPEND						(0x1u<<0)
#define	SPIM_TASKS_SUSPEND_TASKS_SUSPEND_TRIGGER				(0x1u<<0)

// TASKS_RESUME Configuration

#define	SPIM_TASKS_RESUME_TASKS_RESUME							(0x1u<<0)
#define	SPIM_TASKS_RESUME_TASKS_RESUME_TRIGGER					(0x1u<<0)

// SUBSCRIBE_START Configuration

#define	SPIM_SUBSCRIBE_START_EN									(0x1u<<31)
#define	SPIM_SUBSCRIBE_START_CHIDX								(0xFFu<<0)
#define	SPIM_SUBSCRIBE_START_CHIDX_0							(0x1u<<0)
#define	SPIM_SUBSCRIBE_START_EN_DISABLED						(0x0u<<31)
#define	SPIM_SUBSCRIBE_START_EN_ENABLED							(0x1u<<31)

// SUBSCRIBE_STOP Configuration

#define	SPIM_SUBSCRIBE_STOP_EN									(0x1u<<31)
#define	SPIM_SUBSCRIBE_STOP_CHIDX								(0xFFu<<0)
#define	SPIM_SUBSCRIBE_STOP_CHIDX_0								(0x1u<<0)
#define	SPIM_SUBSCRIBE_STOP_EN_DISABLED							(0x0u<<31)
#define	SPIM_SUBSCRIBE_STOP_EN_ENABLED							(0x1u<<31)

// SUBSCRIBE_SUSPEND Configuration

#define	SPIM_SUBSCRIBE_SUSPEND_EN								(0x1u<<31)
#define	SPIM_SUBSCRIBE_SUSPEND_CHIDX							(0xFFu<<0)
#define	SPIM_SUBSCRIBE_SUSPEND_CHIDX_0							(0x1u<<0)
#define	SPIM_SUBSCRIBE_SUSPEND_EN_DISABLED						(0x0u<<31)
#define	SPIM_SUBSCRIBE_SUSPEND_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_RESUME Configuration

#define	SPIM_SUBSCRIBE_RESUME_EN								(0x1u<<31)
#define	SPIM_SUBSCRIBE_RESUME_CHIDX								(0xFFu<<0)
#define	SPIM_SUBSCRIBE_RESUME_CHIDX_0							(0x1u<<0)
#define	SPIM_SUBSCRIBE_RESUME_EN_DISABLED						(0x0u<<31)
#define	SPIM_SUBSCRIBE_RESUME_EN_ENABLED						(0x1u<<31)

// EVENTS_STOPPED Configuration

#define	SPIM_EVENTS_STOPPED_EVENTS_STOPPED						(0x1u<<0)
#define	SPIM_EVENTS_STOPPED_EVENTS_STOPPED_NOTGENERATED			(0x0u<<0)
#define	SPIM_EVENTS_STOPPED_EVENTS_STOPPED_GENERATED			(0x1u<<0)

// EVENTS_ENDRX Configuration

#define	SPIM_EVENTS_ENDRX_EVENTS_ENDRX							(0x1u<<0)
#define	SPIM_EVENTS_ENDRX_EVENTS_ENDRX_NOTGENERATED				(0x0u<<0)
#define	SPIM_EVENTS_ENDRX_EVENTS_ENDRX_GENERATED				(0x1u<<0)

// EVENTS_END Configuration

#define	SPIM_EVENTS_END_EVENTS_END								(0x1u<<0)
#define	SPIM_EVENTS_END_EVENTS_END_NOTGENERATED					(0x0u<<0)
#define	SPIM_EVENTS_END_EVENTS_END_GENERATED					(0x1u<<0)

// EVENTS_ENDTX Configuration

#define	SPIM_EVENTS_ENDTX_EVENTS_ENDTX							(0x1u<<0)
#define	SPIM_EVENTS_ENDTX_EVENTS_ENDTX_NOTGENERATED				(0x0u<<0)
#define	SPIM_EVENTS_ENDTX_EVENTS_ENDTX_GENERATED				(0x1u<<0)

// EVENTS_STARTED Configuration

#define	SPIM_EVENTS_STARTED_EVENTS_STARTED						(0x1u<<0)
#define	SPIM_EVENTS_STARTED_EVENTS_STARTED_NOTGENERATED			(0x0u<<0)
#define	SPIM_EVENTS_STARTED_EVENTS_STARTED_GENERATED			(0x1u<<0)

// PUBLISH_STOPPED Configuration

#define	SPIM_PUBLISH_STOPPED_EN									(0x1u<<31)
#define	SPIM_PUBLISH_STOPPED_CHIDX								(0xFFu<<0)
#define	SPIM_PUBLISH_STOPPED_CHIDX_0							(0x1u<<0)
#define	SPIM_PUBLISH_STOPPED_EN_DISABLED						(0x0u<<31)
#define	SPIM_PUBLISH_STOPPED_EN_ENABLED							(0x1u<<31)

// PUBLISH_ENDRX Configuration

#define	SPIM_PUBLISH_ENDRX_EN									(0x1u<<31)
#define	SPIM_PUBLISH_ENDRX_CHIDX								(0xFFu<<0)
#define	SPIM_PUBLISH_ENDRX_CHIDX_0								(0x1u<<0)
#define	SPIM_PUBLISH_ENDRX_EN_DISABLED							(0x0u<<31)
#define	SPIM_PUBLISH_ENDRX_EN_ENABLED							(0x1u<<31)

// PUBLISH_END Configuration

#define	SPIM_PUBLISH_END_EN										(0x1u<<31)
#define	SPIM_PUBLISH_END_CHIDX									(0xFFu<<0)
#define	SPIM_PUBLISH_END_CHIDX_0								(0x1u<<0)
#define	SPIM_PUBLISH_END_EN_DISABLED							(0x0u<<31)
#define	SPIM_PUBLISH_END_EN_ENABLED								(0x1u<<31)

// PUBLISH_ENDTX Configuration

#define	SPIM_PUBLISH_ENDTX_EN									(0x1u<<31)
#define	SPIM_PUBLISH_ENDTX_CHIDX								(0xFFu<<0)
#define	SPIM_PUBLISH_ENDTX_CHIDX_0								(0x1u<<0)
#define	SPIM_PUBLISH_ENDTX_EN_DISABLED							(0x0u<<31)
#define	SPIM_PUBLISH_ENDTX_EN_ENABLED							(0x1u<<31)

// PUBLISH_STARTED Configuration

#define	SPIM_PUBLISH_STARTED_EN									(0x1u<<31)
#define	SPIM_PUBLISH_STARTED_CHIDX								(0xFFu<<0)
#define	SPIM_PUBLISH_STARTED_CHIDX_0							(0x1u<<0)
#define	SPIM_PUBLISH_STARTED_EN_DISABLED						(0x0u<<31)
#define	SPIM_PUBLISH_STARTED_EN_ENABLED							(0x1u<<31)

// SHORTS Configuration

#define	SPIM_SHORTS_END_START									(0x1u<<17)
#define	SPIM_SHORTS_END_START_DISABLED							(0x0u<<17)
#define	SPIM_SHORTS_END_START_ENABLED							(0x1u<<17)

// INTENSET Configuration

#define	SPIM_INTENSET_STARTED									(0x1u<<19)
#define	SPIM_INTENSET_ENDTX										(0x1u<<8)
#define	SPIM_INTENSET_END										(0x1u<<6)
#define	SPIM_INTENSET_ENDRX										(0x1u<<4)
#define	SPIM_INTENSET_STOPPED									(0x1u<<1)
#define	SPIM_INTENSET_STARTED_DISABLED							(0x0u<<19)
#define	SPIM_INTENSET_STARTED_ENABLED							(0x1u<<19)
#define	SPIM_INTENSET_STARTED_SET								(0x1u<<19)
#define	SPIM_INTENSET_ENDTX_DISABLED							(0x0u<<8)
#define	SPIM_INTENSET_ENDTX_ENABLED								(0x1u<<8)
#define	SPIM_INTENSET_ENDTX_SET									(0x1u<<8)
#define	SPIM_INTENSET_END_DISABLED								(0x0u<<6)
#define	SPIM_INTENSET_END_ENABLED								(0x1u<<6)
#define	SPIM_INTENSET_END_SET									(0x1u<<6)
#define	SPIM_INTENSET_ENDRX_DISABLED							(0x0u<<4)
#define	SPIM_INTENSET_ENDRX_ENABLED								(0x1u<<4)
#define	SPIM_INTENSET_ENDRX_SET									(0x1u<<4)
#define	SPIM_INTENSET_STOPPED_DISABLED							(0x0u<<1)
#define	SPIM_INTENSET_STOPPED_ENABLED							(0x1u<<1)
#define	SPIM_INTENSET_STOPPED_SET								(0x1u<<1)

// INTENCLR Configuration

#define	SPIM_INTENCLR_STARTED									(0x1u<<19)
#define	SPIM_INTENCLR_ENDTX										(0x1u<<8)
#define	SPIM_INTENCLR_END										(0x1u<<6)
#define	SPIM_INTENCLR_ENDRX										(0x1u<<4)
#define	SPIM_INTENCLR_STOPPED									(0x1u<<1)
#define	SPIM_INTENCLR_STARTED_DISABLED							(0x0u<<19)
#define	SPIM_INTENCLR_STARTED_ENABLED							(0x1u<<19)
#define	SPIM_INTENCLR_STARTED_CLEAR								(0x1u<<19)
#define	SPIM_INTENCLR_ENDTX_DISABLED							(0x0u<<8)
#define	SPIM_INTENCLR_ENDTX_ENABLED								(0x1u<<8)
#define	SPIM_INTENCLR_ENDTX_CLEAR								(0x1u<<8)
#define	SPIM_INTENCLR_END_DISABLED								(0x0u<<6)
#define	SPIM_INTENCLR_END_ENABLED								(0x1u<<6)
#define	SPIM_INTENCLR_END_CLEAR									(0x1u<<6)
#define	SPIM_INTENCLR_ENDRX_DISABLED							(0x0u<<4)
#define	SPIM_INTENCLR_ENDRX_ENABLED								(0x1u<<4)
#define	SPIM_INTENCLR_ENDRX_CLEAR								(0x1u<<4)
#define	SPIM_INTENCLR_STOPPED_DISABLED							(0x0u<<1)
#define	SPIM_INTENCLR_STOPPED_ENABLED							(0x1u<<1)
#define	SPIM_INTENCLR_STOPPED_CLEAR								(0x1u<<1)

// STALLSTAT Configuration

#define	SPIM_STALLSTAT_RX										(0x1u<<1)
#define	SPIM_STALLSTAT_TX										(0x1u<<0)
#define	SPIM_STALLSTAT_RX_NOSTALL								(0x0u<<1)
#define	SPIM_STALLSTAT_RX_STALL									(0x1u<<1)
#define	SPIM_STALLSTAT_TX_NOSTALL								(0x0u<<0)
#define	SPIM_STALLSTAT_TX_STALL									(0x1u<<0)

// ENABLE Configuration

#define	SPIM_ENABLE_ENABLE										(0xFu<<0)
#define	SPIM_ENABLE_ENABLE_0									(0x1u<<0)
#define	SPIM_ENABLE_ENABLE_DISABLED								(0x0u<<0)
#define	SPIM_ENABLE_ENABLE_ENABLED								(0x7u<<0)

// SCK Configuration

#define	SPIM_PSEL_SCK_CONNECT									(0x1u<<31)
#define	SPIM_PSEL_SCK_PORT										(0x1u<<5)
#define	SPIM_PSEL_SCK_PIN										(0x1Fu<<0)
#define	SPIM_PSEL_SCK_PIN_0										(0x1u<<0)
#define	SPIM_PSEL_SCK_CONNECT_DISCONNECTED						(0x1u<<31)
#define	SPIM_PSEL_SCK_CONNECT_CONNECTED							(0x0u<<31)

// MOSI Configuration

#define	SPIM_PSEL_MOSI_CONNECT									(0x1u<<31)
#define	SPIM_PSEL_MOSI_PORT										(0x1u<<5)
#define	SPIM_PSEL_MOSI_PIN										(0x1Fu<<0)
#define	SPIM_PSEL_MOSI_PIN_0									(0x1u<<0)
#define	SPIM_PSEL_MOSI_CONNECT_DISCONNECTED						(0x1u<<31)
#define	SPIM_PSEL_MOSI_CONNECT_CONNECTED						(0x0u<<31)

// MISO Configuration

#define	SPIM_PSEL_MISO_CONNECT									(0x1u<<31)
#define	SPIM_PSEL_MISO_PORT										(0x1u<<5)
#define	SPIM_PSEL_MISO_PIN										(0x1Fu<<0)
#define	SPIM_PSEL_MISO_PIN_0									(0x1u<<0)
#define	SPIM_PSEL_MISO_CONNECT_DISCONNECTED						(0x1u<<31)
#define	SPIM_PSEL_MISO_CONNECT_CONNECTED						(0x0u<<31)

// CSN Configuration

#define	SPIM_PSEL_CSN_CONNECT									(0x1u<<31)
#define	SPIM_PSEL_CSN_PORT										(0x1u<<5)
#define	SPIM_PSEL_CSN_PIN										(0x1Fu<<0)
#define	SPIM_PSEL_CSN_PIN_0										(0x1u<<0)
#define	SPIM_PSEL_CSN_CONNECT_DISCONNECTED						(0x1u<<31)
#define	SPIM_PSEL_CSN_CONNECT_CONNECTED							(0x0u<<31)

// FREQUENCY Configuration

#define	SPIM_FREQUENCY_FREQUENCY								(0xFFFFFFFFu<<0)
#define	SPIM_FREQUENCY_FREQUENCY_0								(0x1u<<0)
#define	SPIM_FREQUENCY_FREQUENCY_K125							(0x2000000u<<0)
#define	SPIM_FREQUENCY_FREQUENCY_K250							(0x4000000u<<0)
#define	SPIM_FREQUENCY_FREQUENCY_K500							(0x8000000u<<0)
#define	SPIM_FREQUENCY_FREQUENCY_M1								(0x10000000u<<0)
#define	SPIM_FREQUENCY_FREQUENCY_M2								(0x20000000u<<0)
#define	SPIM_FREQUENCY_FREQUENCY_M4								(0x40000000u<<0)
#define	SPIM_FREQUENCY_FREQUENCY_M8								(0x80000000u<<0)
#define	SPIM_FREQUENCY_FREQUENCY_M16							(0xA000000u<<0)
#define	SPIM_FREQUENCY_FREQUENCY_M32							(0x14000000u<<0)

// PTR Configuration

#define	SPIM_RXD_PTR_PTR										(0xFFFFFFFFu<<0)
#define	SPIM_RXD_PTR_PTR_0										(0x1u<<0)

// MAXCNT Configuration

#define	SPIM_RXD_MAXCNT_MAXCNT									(0xFFFFu<<0)
#define	SPIM_RXD_MAXCNT_MAXCNT_0								(0x1u<<0)

// AMOUNT Configuration

#define	SPIM_RXD_AMOUNT_AMOUNT									(0xFFFFu<<0)
#define	SPIM_RXD_AMOUNT_AMOUNT_0								(0x1u<<0)

// LIST Configuration

#define	SPIM_RXD_LIST_LIST										(0x3u<<0)
#define	SPIM_RXD_LIST_LIST_0									(0x1u<<0)
#define	SPIM_RXD_LIST_LIST_DISABLED								(0x0u<<0)
#define	SPIM_RXD_LIST_LIST_ARRAYLIST							(0x1u<<0)

// PTR Configuration

#define	SPIM_TXD_PTR_PTR										(0xFFFFFFFFu<<0)
#define	SPIM_TXD_PTR_PTR_0										(0x1u<<0)

// MAXCNT Configuration

#define	SPIM_TXD_MAXCNT_MAXCNT									(0xFFFFu<<0)
#define	SPIM_TXD_MAXCNT_MAXCNT_0								(0x1u<<0)

// AMOUNT Configuration

#define	SPIM_TXD_AMOUNT_AMOUNT									(0xFFFFu<<0)
#define	SPIM_TXD_AMOUNT_AMOUNT_0								(0x1u<<0)

// LIST Configuration

#define	SPIM_TXD_LIST_LIST										(0x3u<<0)
#define	SPIM_TXD_LIST_LIST_0									(0x1u<<0)
#define	SPIM_TXD_LIST_LIST_DISABLED								(0x0u<<0)
#define	SPIM_TXD_LIST_LIST_ARRAYLIST							(0x1u<<0)

// CONFIG Configuration

#define	SPIM_CONFIG_CPOL										(0x1u<<2)
#define	SPIM_CONFIG_CPHA										(0x1u<<1)
#define	SPIM_CONFIG_ORDER										(0x1u<<0)
#define	SPIM_CONFIG_CPOL_ACTIVEHIGH								(0x0u<<2)
#define	SPIM_CONFIG_CPOL_ACTIVELOW								(0x1u<<2)
#define	SPIM_CONFIG_CPHA_LEADING								(0x0u<<1)
#define	SPIM_CONFIG_CPHA_TRAILING								(0x1u<<1)
#define	SPIM_CONFIG_ORDER_MSBFIRST								(0x0u<<0)
#define	SPIM_CONFIG_ORDER_LSBFIRST								(0x1u<<0)

// RXDELAY Configuration

#define	SPIM_IFTIMING_RXDELAY_RXDELAY							(0x7u<<0)
#define	SPIM_IFTIMING_RXDELAY_RXDELAY_0							(0x1u<<0)

// CSNDUR Configuration

#define	SPIM_IFTIMING_CSNDUR_CSNDUR								(0xFFu<<0)
#define	SPIM_IFTIMING_CSNDUR_CSNDUR_0							(0x1u<<0)

// CSNPOL Configuration

#define	SPIM_CSNPOL_CSNPOL										(0x1u<<0)
#define	SPIM_CSNPOL_CSNPOL_LOW									(0x0u<<0)
#define	SPIM_CSNPOL_CSNPOL_HIGH									(0x1u<<0)

// PSELDCX Configuration

#define	SPIM_PSELDCX_CONNECT									(0x1u<<31)
#define	SPIM_PSELDCX_PORT										(0x1u<<5)
#define	SPIM_PSELDCX_PIN										(0x1Fu<<0)
#define	SPIM_PSELDCX_PIN_0										(0x1u<<0)
#define	SPIM_PSELDCX_CONNECT_DISCONNECTED						(0x1u<<31)
#define	SPIM_PSELDCX_CONNECT_CONNECTED							(0x0u<<31)

// DCXCNT Configuration

#define	SPIM_DCXCNT_DCXCNT										(0xFu<<0)
#define	SPIM_DCXCNT_DCXCNT_0									(0x1u<<0)

// ORC Configuration

#define	SPIM_ORC_ORC											(0xFFu<<0)
#define	SPIM_ORC_ORC_0											(0x1u<<0)
