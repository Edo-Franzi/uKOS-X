/*
; nrf5340_application_nfct.
; =========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_nfct equates.
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

// NFCT address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	TASKS_ACTIVATE;
	volatile	uint32_t	TASKS_DISABLE;
	volatile	uint32_t	TASKS_SENSE;
	volatile	uint32_t	TASKS_STARTTX;
	volatile	uint32_t	RESERVED0[3];
	volatile	uint32_t	TASKS_ENABLERXDATA;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	TASKS_GOIDLE;
	volatile	uint32_t	TASKS_GOSLEEP;
	volatile	uint32_t	RESERVED2[21];
	volatile	uint32_t	SUBSCRIBE_ACTIVATE;
	volatile	uint32_t	SUBSCRIBE_DISABLE;
	volatile	uint32_t	SUBSCRIBE_SENSE;
	volatile	uint32_t	SUBSCRIBE_STARTTX;
	volatile	uint32_t	RESERVED3[3];
	volatile	uint32_t	SUBSCRIBE_ENABLERXDATA;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	SUBSCRIBE_GOIDLE;
	volatile	uint32_t	SUBSCRIBE_GOSLEEP;
	volatile	uint32_t	RESERVED5[21];
	volatile	uint32_t	EVENTS_READY;
	volatile	uint32_t	EVENTS_FIELDDETECTED;
	volatile	uint32_t	EVENTS_FIELDLOST;
	volatile	uint32_t	EVENTS_TXFRAMESTART;
	volatile	uint32_t	EVENTS_TXFRAMEEND;
	volatile	uint32_t	EVENTS_RXFRAMESTART;
	volatile	uint32_t	EVENTS_RXFRAMEEND;
	volatile	uint32_t	EVENTS_ERROR;
	volatile	uint32_t	RESERVED6[2];
	volatile	uint32_t	EVENTS_RXERROR;
	volatile	uint32_t	EVENTS_ENDRX;
	volatile	uint32_t	EVENTS_ENDTX;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	EVENTS_AUTOCOLRESSTARTED;
	volatile	uint32_t	RESERVED8[3];
	volatile	uint32_t	EVENTS_COLLISION;
	volatile	uint32_t	EVENTS_SELECTED;
	volatile	uint32_t	EVENTS_STARTED;
	volatile	uint32_t	RESERVED9[11];
	volatile	uint32_t	PUBLISH_READY;
	volatile	uint32_t	PUBLISH_FIELDDETECTED;
	volatile	uint32_t	PUBLISH_FIELDLOST;
	volatile	uint32_t	PUBLISH_TXFRAMESTART;
	volatile	uint32_t	PUBLISH_TXFRAMEEND;
	volatile	uint32_t	PUBLISH_RXFRAMESTART;
	volatile	uint32_t	PUBLISH_RXFRAMEEND;
	volatile	uint32_t	PUBLISH_ERROR;
	volatile	uint32_t	RESERVED10[2];
	volatile	uint32_t	PUBLISH_RXERROR;
	volatile	uint32_t	PUBLISH_ENDRX;
	volatile	uint32_t	PUBLISH_ENDTX;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	PUBLISH_AUTOCOLRESSTARTED;
	volatile	uint32_t	RESERVED12[3];
	volatile	uint32_t	PUBLISH_COLLISION;
	volatile	uint32_t	PUBLISH_SELECTED;
	volatile	uint32_t	PUBLISH_STARTED;
	volatile	uint32_t	RESERVED13[11];
	volatile	uint32_t	SHORTS;
	volatile	uint32_t	RESERVED14[63];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED15[62];
	volatile	uint32_t	ERRORSTATUS;
	volatile	uint32_t	RESERVED16;
	volatile	uint32_t	FRAMESTATUS_RX;
	volatile	uint32_t	NFCTAGSTATE;
	volatile	uint32_t	RESERVED17[3];
	volatile	uint32_t	SLEEPSTATE;
	volatile	uint32_t	RESERVED18[6];
	volatile	uint32_t	FIELDPRESENT;
	volatile	uint32_t	RESERVED19[49];
	volatile	uint32_t	FRAMEDELAYMIN;
	volatile	uint32_t	FRAMEDELAYMAX;
	volatile	uint32_t	FRAMEDELAYMODE;
	volatile	uint32_t	PACKETPTR;
	volatile	uint32_t	MAXLEN;
	volatile	uint32_t	TXD_FRAMECONFIG;
	volatile	uint32_t	TXD_AMOUNT;
	volatile	uint32_t	RXD_FRAMECONFIG;
	volatile	uint32_t	RXD_AMOUNT;
	volatile	uint32_t	RESERVED20;
	volatile	uint32_t	MODULATIONCTRL;
	volatile	uint32_t	RESERVED21[2];
	volatile	uint32_t	MODULATIONPSEL;
	volatile	uint32_t	RESERVED22[21];
	volatile	uint32_t	NFCID1_LAST;
	volatile	uint32_t	NFCID1_2ND_LAST;
	volatile	uint32_t	NFCID1_3RD_LAST;
	volatile	uint32_t	AUTOCOLRESCONFIG;
	volatile	uint32_t	SENSRES;
	volatile	uint32_t	SELRES;
} NFCT_TypeDef;

#if (defined(__cplusplus))
#define	NFCT_NS	reinterpret_cast<NFCT_TypeDef *>(0x4002D000u)
#define	NFCT_S	reinterpret_cast<NFCT_TypeDef *>(0x5002D000u)

#else
#define	NFCT_NS	((NFCT_TypeDef *)0x4002D000u)
#define	NFCT_S	((NFCT_TypeDef *)0x5002D000u)
#endif

// TASKS_ACTIVATE Configuration

#define	NFCT_TASKS_ACTIVATE_TASKS_ACTIVATE												(0x1u<<0)
#define	NFCT_TASKS_ACTIVATE_TASKS_ACTIVATE_TRIGGER										(0x1u<<0)

// TASKS_DISABLE Configuration

#define	NFCT_TASKS_DISABLE_TASKS_DISABLE												(0x1u<<0)
#define	NFCT_TASKS_DISABLE_TASKS_DISABLE_TRIGGER										(0x1u<<0)

// TASKS_SENSE Configuration

#define	NFCT_TASKS_SENSE_TASKS_SENSE													(0x1u<<0)
#define	NFCT_TASKS_SENSE_TASKS_SENSE_TRIGGER											(0x1u<<0)

// TASKS_STARTTX Configuration

#define	NFCT_TASKS_STARTTX_TASKS_STARTTX												(0x1u<<0)
#define	NFCT_TASKS_STARTTX_TASKS_STARTTX_TRIGGER										(0x1u<<0)

// TASKS_ENABLERXDATA Configuration

#define	NFCT_TASKS_ENABLERXDATA_TASKS_ENABLERXDATA										(0x1u<<0)
#define	NFCT_TASKS_ENABLERXDATA_TASKS_ENABLERXDATA_TRIGGER								(0x1u<<0)

// TASKS_GOIDLE Configuration

#define	NFCT_TASKS_GOIDLE_TASKS_GOIDLE													(0x1u<<0)
#define	NFCT_TASKS_GOIDLE_TASKS_GOIDLE_TRIGGER											(0x1u<<0)

// TASKS_GOSLEEP Configuration

#define	NFCT_TASKS_GOSLEEP_TASKS_GOSLEEP												(0x1u<<0)
#define	NFCT_TASKS_GOSLEEP_TASKS_GOSLEEP_TRIGGER										(0x1u<<0)

// SUBSCRIBE_ACTIVATE Configuration

#define	NFCT_SUBSCRIBE_ACTIVATE_EN														(0x1u<<31)
#define	NFCT_SUBSCRIBE_ACTIVATE_CHIDX													(0xFFu<<0)
#define	NFCT_SUBSCRIBE_ACTIVATE_CHIDX_0													(0x1u<<0)
#define	NFCT_SUBSCRIBE_ACTIVATE_EN_DISABLED												(0x0u<<31)
#define	NFCT_SUBSCRIBE_ACTIVATE_EN_ENABLED												(0x1u<<31)

// SUBSCRIBE_DISABLE Configuration

#define	NFCT_SUBSCRIBE_DISABLE_EN														(0x1u<<31)
#define	NFCT_SUBSCRIBE_DISABLE_CHIDX													(0xFFu<<0)
#define	NFCT_SUBSCRIBE_DISABLE_CHIDX_0													(0x1u<<0)
#define	NFCT_SUBSCRIBE_DISABLE_EN_DISABLED												(0x0u<<31)
#define	NFCT_SUBSCRIBE_DISABLE_EN_ENABLED												(0x1u<<31)

// SUBSCRIBE_SENSE Configuration

#define	NFCT_SUBSCRIBE_SENSE_EN															(0x1u<<31)
#define	NFCT_SUBSCRIBE_SENSE_CHIDX														(0xFFu<<0)
#define	NFCT_SUBSCRIBE_SENSE_CHIDX_0													(0x1u<<0)
#define	NFCT_SUBSCRIBE_SENSE_EN_DISABLED												(0x0u<<31)
#define	NFCT_SUBSCRIBE_SENSE_EN_ENABLED													(0x1u<<31)

// SUBSCRIBE_STARTTX Configuration

#define	NFCT_SUBSCRIBE_STARTTX_EN														(0x1u<<31)
#define	NFCT_SUBSCRIBE_STARTTX_CHIDX													(0xFFu<<0)
#define	NFCT_SUBSCRIBE_STARTTX_CHIDX_0													(0x1u<<0)
#define	NFCT_SUBSCRIBE_STARTTX_EN_DISABLED												(0x0u<<31)
#define	NFCT_SUBSCRIBE_STARTTX_EN_ENABLED												(0x1u<<31)

// SUBSCRIBE_ENABLERXDATA Configuration

#define	NFCT_SUBSCRIBE_ENABLERXDATA_EN													(0x1u<<31)
#define	NFCT_SUBSCRIBE_ENABLERXDATA_CHIDX												(0xFFu<<0)
#define	NFCT_SUBSCRIBE_ENABLERXDATA_CHIDX_0												(0x1u<<0)
#define	NFCT_SUBSCRIBE_ENABLERXDATA_EN_DISABLED											(0x0u<<31)
#define	NFCT_SUBSCRIBE_ENABLERXDATA_EN_ENABLED											(0x1u<<31)

// SUBSCRIBE_GOIDLE Configuration

#define	NFCT_SUBSCRIBE_GOIDLE_EN														(0x1u<<31)
#define	NFCT_SUBSCRIBE_GOIDLE_CHIDX														(0xFFu<<0)
#define	NFCT_SUBSCRIBE_GOIDLE_CHIDX_0													(0x1u<<0)
#define	NFCT_SUBSCRIBE_GOIDLE_EN_DISABLED												(0x0u<<31)
#define	NFCT_SUBSCRIBE_GOIDLE_EN_ENABLED												(0x1u<<31)

// SUBSCRIBE_GOSLEEP Configuration

#define	NFCT_SUBSCRIBE_GOSLEEP_EN														(0x1u<<31)
#define	NFCT_SUBSCRIBE_GOSLEEP_CHIDX													(0xFFu<<0)
#define	NFCT_SUBSCRIBE_GOSLEEP_CHIDX_0													(0x1u<<0)
#define	NFCT_SUBSCRIBE_GOSLEEP_EN_DISABLED												(0x0u<<31)
#define	NFCT_SUBSCRIBE_GOSLEEP_EN_ENABLED												(0x1u<<31)

// EVENTS_READY Configuration

#define	NFCT_EVENTS_READY_EVENTS_READY													(0x1u<<0)
#define	NFCT_EVENTS_READY_EVENTS_READY_NOTGENERATED										(0x0u<<0)
#define	NFCT_EVENTS_READY_EVENTS_READY_GENERATED										(0x1u<<0)

// EVENTS_FIELDDETECTED Configuration

#define	NFCT_EVENTS_FIELDDETECTED_EVENTS_FIELDDETECTED									(0x1u<<0)
#define	NFCT_EVENTS_FIELDDETECTED_EVENTS_FIELDDETECTED_NOTGENERATED						(0x0u<<0)
#define	NFCT_EVENTS_FIELDDETECTED_EVENTS_FIELDDETECTED_GENERATED						(0x1u<<0)

// EVENTS_FIELDLOST Configuration

#define	NFCT_EVENTS_FIELDLOST_EVENTS_FIELDLOST											(0x1u<<0)
#define	NFCT_EVENTS_FIELDLOST_EVENTS_FIELDLOST_NOTGENERATED								(0x0u<<0)
#define	NFCT_EVENTS_FIELDLOST_EVENTS_FIELDLOST_GENERATED								(0x1u<<0)

// EVENTS_TXFRAMESTART Configuration

#define	NFCT_EVENTS_TXFRAMESTART_EVENTS_TXFRAMESTART									(0x1u<<0)
#define	NFCT_EVENTS_TXFRAMESTART_EVENTS_TXFRAMESTART_NOTGENERATED						(0x0u<<0)
#define	NFCT_EVENTS_TXFRAMESTART_EVENTS_TXFRAMESTART_GENERATED							(0x1u<<0)

// EVENTS_TXFRAMEEND Configuration

#define	NFCT_EVENTS_TXFRAMEEND_EVENTS_TXFRAMEEND										(0x1u<<0)
#define	NFCT_EVENTS_TXFRAMEEND_EVENTS_TXFRAMEEND_NOTGENERATED							(0x0u<<0)
#define	NFCT_EVENTS_TXFRAMEEND_EVENTS_TXFRAMEEND_GENERATED								(0x1u<<0)

// EVENTS_RXFRAMESTART Configuration

#define	NFCT_EVENTS_RXFRAMESTART_EVENTS_RXFRAMESTART									(0x1u<<0)
#define	NFCT_EVENTS_RXFRAMESTART_EVENTS_RXFRAMESTART_NOTGENERATED						(0x0u<<0)
#define	NFCT_EVENTS_RXFRAMESTART_EVENTS_RXFRAMESTART_GENERATED							(0x1u<<0)

// EVENTS_RXFRAMEEND Configuration

#define	NFCT_EVENTS_RXFRAMEEND_EVENTS_RXFRAMEEND										(0x1u<<0)
#define	NFCT_EVENTS_RXFRAMEEND_EVENTS_RXFRAMEEND_NOTGENERATED							(0x0u<<0)
#define	NFCT_EVENTS_RXFRAMEEND_EVENTS_RXFRAMEEND_GENERATED								(0x1u<<0)

// EVENTS_ERROR Configuration

#define	NFCT_EVENTS_ERROR_EVENTS_ERROR													(0x1u<<0)
#define	NFCT_EVENTS_ERROR_EVENTS_ERROR_NOTGENERATED										(0x0u<<0)
#define	NFCT_EVENTS_ERROR_EVENTS_ERROR_GENERATED										(0x1u<<0)

// EVENTS_RXERROR Configuration

#define	NFCT_EVENTS_RXERROR_EVENTS_RXERROR												(0x1u<<0)
#define	NFCT_EVENTS_RXERROR_EVENTS_RXERROR_NOTGENERATED									(0x0u<<0)
#define	NFCT_EVENTS_RXERROR_EVENTS_RXERROR_GENERATED									(0x1u<<0)

// EVENTS_ENDRX Configuration

#define	NFCT_EVENTS_ENDRX_EVENTS_ENDRX													(0x1u<<0)
#define	NFCT_EVENTS_ENDRX_EVENTS_ENDRX_NOTGENERATED										(0x0u<<0)
#define	NFCT_EVENTS_ENDRX_EVENTS_ENDRX_GENERATED										(0x1u<<0)

// EVENTS_ENDTX Configuration

#define	NFCT_EVENTS_ENDTX_EVENTS_ENDTX													(0x1u<<0)
#define	NFCT_EVENTS_ENDTX_EVENTS_ENDTX_NOTGENERATED										(0x0u<<0)
#define	NFCT_EVENTS_ENDTX_EVENTS_ENDTX_GENERATED										(0x1u<<0)

// EVENTS_AUTOCOLRESSTARTED Configuration

#define	NFCT_EVENTS_AUTOCOLRESSTARTED_EVENTS_AUTOCOLRESSTARTED							(0x1u<<0)
#define	NFCT_EVENTS_AUTOCOLRESSTARTED_EVENTS_AUTOCOLRESSTARTED_NOTGENERATED				(0x0u<<0)
#define	NFCT_EVENTS_AUTOCOLRESSTARTED_EVENTS_AUTOCOLRESSTARTED_GENERATED				(0x1u<<0)

// EVENTS_COLLISION Configuration

#define	NFCT_EVENTS_COLLISION_EVENTS_COLLISION											(0x1u<<0)
#define	NFCT_EVENTS_COLLISION_EVENTS_COLLISION_NOTGENERATED								(0x0u<<0)
#define	NFCT_EVENTS_COLLISION_EVENTS_COLLISION_GENERATED								(0x1u<<0)

// EVENTS_SELECTED Configuration

#define	NFCT_EVENTS_SELECTED_EVENTS_SELECTED											(0x1u<<0)
#define	NFCT_EVENTS_SELECTED_EVENTS_SELECTED_NOTGENERATED								(0x0u<<0)
#define	NFCT_EVENTS_SELECTED_EVENTS_SELECTED_GENERATED									(0x1u<<0)

// EVENTS_STARTED Configuration

#define	NFCT_EVENTS_STARTED_EVENTS_STARTED												(0x1u<<0)
#define	NFCT_EVENTS_STARTED_EVENTS_STARTED_NOTGENERATED									(0x0u<<0)
#define	NFCT_EVENTS_STARTED_EVENTS_STARTED_GENERATED									(0x1u<<0)

// PUBLISH_READY Configuration

#define	NFCT_PUBLISH_READY_EN															(0x1u<<31)
#define	NFCT_PUBLISH_READY_CHIDX														(0xFFu<<0)
#define	NFCT_PUBLISH_READY_CHIDX_0														(0x1u<<0)
#define	NFCT_PUBLISH_READY_EN_DISABLED													(0x0u<<31)
#define	NFCT_PUBLISH_READY_EN_ENABLED													(0x1u<<31)

// PUBLISH_FIELDDETECTED Configuration

#define	NFCT_PUBLISH_FIELDDETECTED_EN													(0x1u<<31)
#define	NFCT_PUBLISH_FIELDDETECTED_CHIDX												(0xFFu<<0)
#define	NFCT_PUBLISH_FIELDDETECTED_CHIDX_0												(0x1u<<0)
#define	NFCT_PUBLISH_FIELDDETECTED_EN_DISABLED											(0x0u<<31)
#define	NFCT_PUBLISH_FIELDDETECTED_EN_ENABLED											(0x1u<<31)

// PUBLISH_FIELDLOST Configuration

#define	NFCT_PUBLISH_FIELDLOST_EN														(0x1u<<31)
#define	NFCT_PUBLISH_FIELDLOST_CHIDX													(0xFFu<<0)
#define	NFCT_PUBLISH_FIELDLOST_CHIDX_0													(0x1u<<0)
#define	NFCT_PUBLISH_FIELDLOST_EN_DISABLED												(0x0u<<31)
#define	NFCT_PUBLISH_FIELDLOST_EN_ENABLED												(0x1u<<31)

// PUBLISH_TXFRAMESTART Configuration

#define	NFCT_PUBLISH_TXFRAMESTART_EN													(0x1u<<31)
#define	NFCT_PUBLISH_TXFRAMESTART_CHIDX													(0xFFu<<0)
#define	NFCT_PUBLISH_TXFRAMESTART_CHIDX_0												(0x1u<<0)
#define	NFCT_PUBLISH_TXFRAMESTART_EN_DISABLED											(0x0u<<31)
#define	NFCT_PUBLISH_TXFRAMESTART_EN_ENABLED											(0x1u<<31)

// PUBLISH_TXFRAMEEND Configuration

#define	NFCT_PUBLISH_TXFRAMEEND_EN														(0x1u<<31)
#define	NFCT_PUBLISH_TXFRAMEEND_CHIDX													(0xFFu<<0)
#define	NFCT_PUBLISH_TXFRAMEEND_CHIDX_0													(0x1u<<0)
#define	NFCT_PUBLISH_TXFRAMEEND_EN_DISABLED												(0x0u<<31)
#define	NFCT_PUBLISH_TXFRAMEEND_EN_ENABLED												(0x1u<<31)

// PUBLISH_RXFRAMESTART Configuration

#define	NFCT_PUBLISH_RXFRAMESTART_EN													(0x1u<<31)
#define	NFCT_PUBLISH_RXFRAMESTART_CHIDX													(0xFFu<<0)
#define	NFCT_PUBLISH_RXFRAMESTART_CHIDX_0												(0x1u<<0)
#define	NFCT_PUBLISH_RXFRAMESTART_EN_DISABLED											(0x0u<<31)
#define	NFCT_PUBLISH_RXFRAMESTART_EN_ENABLED											(0x1u<<31)

// PUBLISH_RXFRAMEEND Configuration

#define	NFCT_PUBLISH_RXFRAMEEND_EN														(0x1u<<31)
#define	NFCT_PUBLISH_RXFRAMEEND_CHIDX													(0xFFu<<0)
#define	NFCT_PUBLISH_RXFRAMEEND_CHIDX_0													(0x1u<<0)
#define	NFCT_PUBLISH_RXFRAMEEND_EN_DISABLED												(0x0u<<31)
#define	NFCT_PUBLISH_RXFRAMEEND_EN_ENABLED												(0x1u<<31)

// PUBLISH_ERROR Configuration

#define	NFCT_PUBLISH_ERROR_EN															(0x1u<<31)
#define	NFCT_PUBLISH_ERROR_CHIDX														(0xFFu<<0)
#define	NFCT_PUBLISH_ERROR_CHIDX_0														(0x1u<<0)
#define	NFCT_PUBLISH_ERROR_EN_DISABLED													(0x0u<<31)
#define	NFCT_PUBLISH_ERROR_EN_ENABLED													(0x1u<<31)

// PUBLISH_RXERROR Configuration

#define	NFCT_PUBLISH_RXERROR_EN															(0x1u<<31)
#define	NFCT_PUBLISH_RXERROR_CHIDX														(0xFFu<<0)
#define	NFCT_PUBLISH_RXERROR_CHIDX_0													(0x1u<<0)
#define	NFCT_PUBLISH_RXERROR_EN_DISABLED												(0x0u<<31)
#define	NFCT_PUBLISH_RXERROR_EN_ENABLED													(0x1u<<31)

// PUBLISH_ENDRX Configuration

#define	NFCT_PUBLISH_ENDRX_EN															(0x1u<<31)
#define	NFCT_PUBLISH_ENDRX_CHIDX														(0xFFu<<0)
#define	NFCT_PUBLISH_ENDRX_CHIDX_0														(0x1u<<0)
#define	NFCT_PUBLISH_ENDRX_EN_DISABLED													(0x0u<<31)
#define	NFCT_PUBLISH_ENDRX_EN_ENABLED													(0x1u<<31)

// PUBLISH_ENDTX Configuration

#define	NFCT_PUBLISH_ENDTX_EN															(0x1u<<31)
#define	NFCT_PUBLISH_ENDTX_CHIDX														(0xFFu<<0)
#define	NFCT_PUBLISH_ENDTX_CHIDX_0														(0x1u<<0)
#define	NFCT_PUBLISH_ENDTX_EN_DISABLED													(0x0u<<31)
#define	NFCT_PUBLISH_ENDTX_EN_ENABLED													(0x1u<<31)

// PUBLISH_AUTOCOLRESSTARTED Configuration

#define	NFCT_PUBLISH_AUTOCOLRESSTARTED_EN												(0x1u<<31)
#define	NFCT_PUBLISH_AUTOCOLRESSTARTED_CHIDX											(0xFFu<<0)
#define	NFCT_PUBLISH_AUTOCOLRESSTARTED_CHIDX_0											(0x1u<<0)
#define	NFCT_PUBLISH_AUTOCOLRESSTARTED_EN_DISABLED										(0x0u<<31)
#define	NFCT_PUBLISH_AUTOCOLRESSTARTED_EN_ENABLED										(0x1u<<31)

// PUBLISH_COLLISION Configuration

#define	NFCT_PUBLISH_COLLISION_EN														(0x1u<<31)
#define	NFCT_PUBLISH_COLLISION_CHIDX													(0xFFu<<0)
#define	NFCT_PUBLISH_COLLISION_CHIDX_0													(0x1u<<0)
#define	NFCT_PUBLISH_COLLISION_EN_DISABLED												(0x0u<<31)
#define	NFCT_PUBLISH_COLLISION_EN_ENABLED												(0x1u<<31)

// PUBLISH_SELECTED Configuration

#define	NFCT_PUBLISH_SELECTED_EN														(0x1u<<31)
#define	NFCT_PUBLISH_SELECTED_CHIDX														(0xFFu<<0)
#define	NFCT_PUBLISH_SELECTED_CHIDX_0													(0x1u<<0)
#define	NFCT_PUBLISH_SELECTED_EN_DISABLED												(0x0u<<31)
#define	NFCT_PUBLISH_SELECTED_EN_ENABLED												(0x1u<<31)

// PUBLISH_STARTED Configuration

#define	NFCT_PUBLISH_STARTED_EN															(0x1u<<31)
#define	NFCT_PUBLISH_STARTED_CHIDX														(0xFFu<<0)
#define	NFCT_PUBLISH_STARTED_CHIDX_0													(0x1u<<0)
#define	NFCT_PUBLISH_STARTED_EN_DISABLED												(0x0u<<31)
#define	NFCT_PUBLISH_STARTED_EN_ENABLED													(0x1u<<31)

// SHORTS Configuration

#define	NFCT_SHORTS_TXFRAMEEND_ENABLERXDATA												(0x1u<<5)
#define	NFCT_SHORTS_FIELDLOST_SENSE														(0x1u<<1)
#define	NFCT_SHORTS_FIELDDETECTED_ACTIVATE												(0x1u<<0)
#define	NFCT_SHORTS_TXFRAMEEND_ENABLERXDATA_DISABLED									(0x0u<<5)
#define	NFCT_SHORTS_TXFRAMEEND_ENABLERXDATA_ENABLED										(0x1u<<5)
#define	NFCT_SHORTS_FIELDLOST_SENSE_DISABLED											(0x0u<<1)
#define	NFCT_SHORTS_FIELDLOST_SENSE_ENABLED												(0x1u<<1)
#define	NFCT_SHORTS_FIELDDETECTED_ACTIVATE_DISABLED										(0x0u<<0)
#define	NFCT_SHORTS_FIELDDETECTED_ACTIVATE_ENABLED										(0x1u<<0)

// INTEN Configuration

#define	NFCT_INTEN_STARTED																(0x1u<<20)
#define	NFCT_INTEN_SELECTED																(0x1u<<19)
#define	NFCT_INTEN_COLLISION															(0x1u<<18)
#define	NFCT_INTEN_AUTOCOLRESSTARTED													(0x1u<<14)
#define	NFCT_INTEN_ENDTX																(0x1u<<12)
#define	NFCT_INTEN_ENDRX																(0x1u<<11)
#define	NFCT_INTEN_RXERROR																(0x1u<<10)
#define	NFCT_INTEN_ERROR																(0x1u<<7)
#define	NFCT_INTEN_RXFRAMEEND															(0x1u<<6)
#define	NFCT_INTEN_RXFRAMESTART															(0x1u<<5)
#define	NFCT_INTEN_TXFRAMEEND															(0x1u<<4)
#define	NFCT_INTEN_TXFRAMESTART															(0x1u<<3)
#define	NFCT_INTEN_FIELDLOST															(0x1u<<2)
#define	NFCT_INTEN_FIELDDETECTED														(0x1u<<1)
#define	NFCT_INTEN_READY																(0x1u<<0)
#define	NFCT_INTEN_STARTED_DISABLED														(0x0u<<20)
#define	NFCT_INTEN_STARTED_ENABLED														(0x1u<<20)
#define	NFCT_INTEN_SELECTED_DISABLED													(0x0u<<19)
#define	NFCT_INTEN_SELECTED_ENABLED														(0x1u<<19)
#define	NFCT_INTEN_COLLISION_DISABLED													(0x0u<<18)
#define	NFCT_INTEN_COLLISION_ENABLED													(0x1u<<18)
#define	NFCT_INTEN_AUTOCOLRESSTARTED_DISABLED											(0x0u<<14)
#define	NFCT_INTEN_AUTOCOLRESSTARTED_ENABLED											(0x1u<<14)
#define	NFCT_INTEN_ENDTX_DISABLED														(0x0u<<12)
#define	NFCT_INTEN_ENDTX_ENABLED														(0x1u<<12)
#define	NFCT_INTEN_ENDRX_DISABLED														(0x0u<<11)
#define	NFCT_INTEN_ENDRX_ENABLED														(0x1u<<11)
#define	NFCT_INTEN_RXERROR_DISABLED														(0x0u<<10)
#define	NFCT_INTEN_RXERROR_ENABLED														(0x1u<<10)
#define	NFCT_INTEN_ERROR_DISABLED														(0x0u<<7)
#define	NFCT_INTEN_ERROR_ENABLED														(0x1u<<7)
#define	NFCT_INTEN_RXFRAMEEND_DISABLED													(0x0u<<6)
#define	NFCT_INTEN_RXFRAMEEND_ENABLED													(0x1u<<6)
#define	NFCT_INTEN_RXFRAMESTART_DISABLED												(0x0u<<5)
#define	NFCT_INTEN_RXFRAMESTART_ENABLED													(0x1u<<5)
#define	NFCT_INTEN_TXFRAMEEND_DISABLED													(0x0u<<4)
#define	NFCT_INTEN_TXFRAMEEND_ENABLED													(0x1u<<4)
#define	NFCT_INTEN_TXFRAMESTART_DISABLED												(0x0u<<3)
#define	NFCT_INTEN_TXFRAMESTART_ENABLED													(0x1u<<3)
#define	NFCT_INTEN_FIELDLOST_DISABLED													(0x0u<<2)
#define	NFCT_INTEN_FIELDLOST_ENABLED													(0x1u<<2)
#define	NFCT_INTEN_FIELDDETECTED_DISABLED												(0x0u<<1)
#define	NFCT_INTEN_FIELDDETECTED_ENABLED												(0x1u<<1)
#define	NFCT_INTEN_READY_DISABLED														(0x0u<<0)
#define	NFCT_INTEN_READY_ENABLED														(0x1u<<0)

// INTENSET Configuration

#define	NFCT_INTENSET_STARTED															(0x1u<<20)
#define	NFCT_INTENSET_SELECTED															(0x1u<<19)
#define	NFCT_INTENSET_COLLISION															(0x1u<<18)
#define	NFCT_INTENSET_AUTOCOLRESSTARTED													(0x1u<<14)
#define	NFCT_INTENSET_ENDTX																(0x1u<<12)
#define	NFCT_INTENSET_ENDRX																(0x1u<<11)
#define	NFCT_INTENSET_RXERROR															(0x1u<<10)
#define	NFCT_INTENSET_ERROR																(0x1u<<7)
#define	NFCT_INTENSET_RXFRAMEEND														(0x1u<<6)
#define	NFCT_INTENSET_RXFRAMESTART														(0x1u<<5)
#define	NFCT_INTENSET_TXFRAMEEND														(0x1u<<4)
#define	NFCT_INTENSET_TXFRAMESTART														(0x1u<<3)
#define	NFCT_INTENSET_FIELDLOST															(0x1u<<2)
#define	NFCT_INTENSET_FIELDDETECTED														(0x1u<<1)
#define	NFCT_INTENSET_READY																(0x1u<<0)
#define	NFCT_INTENSET_STARTED_DISABLED													(0x0u<<20)
#define	NFCT_INTENSET_STARTED_ENABLED													(0x1u<<20)
#define	NFCT_INTENSET_STARTED_SET														(0x1u<<20)
#define	NFCT_INTENSET_SELECTED_DISABLED													(0x0u<<19)
#define	NFCT_INTENSET_SELECTED_ENABLED													(0x1u<<19)
#define	NFCT_INTENSET_SELECTED_SET														(0x1u<<19)
#define	NFCT_INTENSET_COLLISION_DISABLED												(0x0u<<18)
#define	NFCT_INTENSET_COLLISION_ENABLED													(0x1u<<18)
#define	NFCT_INTENSET_COLLISION_SET														(0x1u<<18)
#define	NFCT_INTENSET_AUTOCOLRESSTARTED_DISABLED										(0x0u<<14)
#define	NFCT_INTENSET_AUTOCOLRESSTARTED_ENABLED											(0x1u<<14)
#define	NFCT_INTENSET_AUTOCOLRESSTARTED_SET												(0x1u<<14)
#define	NFCT_INTENSET_ENDTX_DISABLED													(0x0u<<12)
#define	NFCT_INTENSET_ENDTX_ENABLED														(0x1u<<12)
#define	NFCT_INTENSET_ENDTX_SET															(0x1u<<12)
#define	NFCT_INTENSET_ENDRX_DISABLED													(0x0u<<11)
#define	NFCT_INTENSET_ENDRX_ENABLED														(0x1u<<11)
#define	NFCT_INTENSET_ENDRX_SET															(0x1u<<11)
#define	NFCT_INTENSET_RXERROR_DISABLED													(0x0u<<10)
#define	NFCT_INTENSET_RXERROR_ENABLED													(0x1u<<10)
#define	NFCT_INTENSET_RXERROR_SET														(0x1u<<10)
#define	NFCT_INTENSET_ERROR_DISABLED													(0x0u<<7)
#define	NFCT_INTENSET_ERROR_ENABLED														(0x1u<<7)
#define	NFCT_INTENSET_ERROR_SET															(0x1u<<7)
#define	NFCT_INTENSET_RXFRAMEEND_DISABLED												(0x0u<<6)
#define	NFCT_INTENSET_RXFRAMEEND_ENABLED												(0x1u<<6)
#define	NFCT_INTENSET_RXFRAMEEND_SET													(0x1u<<6)
#define	NFCT_INTENSET_RXFRAMESTART_DISABLED												(0x0u<<5)
#define	NFCT_INTENSET_RXFRAMESTART_ENABLED												(0x1u<<5)
#define	NFCT_INTENSET_RXFRAMESTART_SET													(0x1u<<5)
#define	NFCT_INTENSET_TXFRAMEEND_DISABLED												(0x0u<<4)
#define	NFCT_INTENSET_TXFRAMEEND_ENABLED												(0x1u<<4)
#define	NFCT_INTENSET_TXFRAMEEND_SET													(0x1u<<4)
#define	NFCT_INTENSET_TXFRAMESTART_DISABLED												(0x0u<<3)
#define	NFCT_INTENSET_TXFRAMESTART_ENABLED												(0x1u<<3)
#define	NFCT_INTENSET_TXFRAMESTART_SET													(0x1u<<3)
#define	NFCT_INTENSET_FIELDLOST_DISABLED												(0x0u<<2)
#define	NFCT_INTENSET_FIELDLOST_ENABLED													(0x1u<<2)
#define	NFCT_INTENSET_FIELDLOST_SET														(0x1u<<2)
#define	NFCT_INTENSET_FIELDDETECTED_DISABLED											(0x0u<<1)
#define	NFCT_INTENSET_FIELDDETECTED_ENABLED												(0x1u<<1)
#define	NFCT_INTENSET_FIELDDETECTED_SET													(0x1u<<1)
#define	NFCT_INTENSET_READY_DISABLED													(0x0u<<0)
#define	NFCT_INTENSET_READY_ENABLED														(0x1u<<0)
#define	NFCT_INTENSET_READY_SET															(0x1u<<0)

// INTENCLR Configuration

#define	NFCT_INTENCLR_STARTED															(0x1u<<20)
#define	NFCT_INTENCLR_SELECTED															(0x1u<<19)
#define	NFCT_INTENCLR_COLLISION															(0x1u<<18)
#define	NFCT_INTENCLR_AUTOCOLRESSTARTED													(0x1u<<14)
#define	NFCT_INTENCLR_ENDTX																(0x1u<<12)
#define	NFCT_INTENCLR_ENDRX																(0x1u<<11)
#define	NFCT_INTENCLR_RXERROR															(0x1u<<10)
#define	NFCT_INTENCLR_ERROR																(0x1u<<7)
#define	NFCT_INTENCLR_RXFRAMEEND														(0x1u<<6)
#define	NFCT_INTENCLR_RXFRAMESTART														(0x1u<<5)
#define	NFCT_INTENCLR_TXFRAMEEND														(0x1u<<4)
#define	NFCT_INTENCLR_TXFRAMESTART														(0x1u<<3)
#define	NFCT_INTENCLR_FIELDLOST															(0x1u<<2)
#define	NFCT_INTENCLR_FIELDDETECTED														(0x1u<<1)
#define	NFCT_INTENCLR_READY																(0x1u<<0)
#define	NFCT_INTENCLR_STARTED_DISABLED													(0x0u<<20)
#define	NFCT_INTENCLR_STARTED_ENABLED													(0x1u<<20)
#define	NFCT_INTENCLR_STARTED_CLEAR														(0x1u<<20)
#define	NFCT_INTENCLR_SELECTED_DISABLED													(0x0u<<19)
#define	NFCT_INTENCLR_SELECTED_ENABLED													(0x1u<<19)
#define	NFCT_INTENCLR_SELECTED_CLEAR													(0x1u<<19)
#define	NFCT_INTENCLR_COLLISION_DISABLED												(0x0u<<18)
#define	NFCT_INTENCLR_COLLISION_ENABLED													(0x1u<<18)
#define	NFCT_INTENCLR_COLLISION_CLEAR													(0x1u<<18)
#define	NFCT_INTENCLR_AUTOCOLRESSTARTED_DISABLED										(0x0u<<14)
#define	NFCT_INTENCLR_AUTOCOLRESSTARTED_ENABLED											(0x1u<<14)
#define	NFCT_INTENCLR_AUTOCOLRESSTARTED_CLEAR											(0x1u<<14)
#define	NFCT_INTENCLR_ENDTX_DISABLED													(0x0u<<12)
#define	NFCT_INTENCLR_ENDTX_ENABLED														(0x1u<<12)
#define	NFCT_INTENCLR_ENDTX_CLEAR														(0x1u<<12)
#define	NFCT_INTENCLR_ENDRX_DISABLED													(0x0u<<11)
#define	NFCT_INTENCLR_ENDRX_ENABLED														(0x1u<<11)
#define	NFCT_INTENCLR_ENDRX_CLEAR														(0x1u<<11)
#define	NFCT_INTENCLR_RXERROR_DISABLED													(0x0u<<10)
#define	NFCT_INTENCLR_RXERROR_ENABLED													(0x1u<<10)
#define	NFCT_INTENCLR_RXERROR_CLEAR														(0x1u<<10)
#define	NFCT_INTENCLR_ERROR_DISABLED													(0x0u<<7)
#define	NFCT_INTENCLR_ERROR_ENABLED														(0x1u<<7)
#define	NFCT_INTENCLR_ERROR_CLEAR														(0x1u<<7)
#define	NFCT_INTENCLR_RXFRAMEEND_DISABLED												(0x0u<<6)
#define	NFCT_INTENCLR_RXFRAMEEND_ENABLED												(0x1u<<6)
#define	NFCT_INTENCLR_RXFRAMEEND_CLEAR													(0x1u<<6)
#define	NFCT_INTENCLR_RXFRAMESTART_DISABLED												(0x0u<<5)
#define	NFCT_INTENCLR_RXFRAMESTART_ENABLED												(0x1u<<5)
#define	NFCT_INTENCLR_RXFRAMESTART_CLEAR												(0x1u<<5)
#define	NFCT_INTENCLR_TXFRAMEEND_DISABLED												(0x0u<<4)
#define	NFCT_INTENCLR_TXFRAMEEND_ENABLED												(0x1u<<4)
#define	NFCT_INTENCLR_TXFRAMEEND_CLEAR													(0x1u<<4)
#define	NFCT_INTENCLR_TXFRAMESTART_DISABLED												(0x0u<<3)
#define	NFCT_INTENCLR_TXFRAMESTART_ENABLED												(0x1u<<3)
#define	NFCT_INTENCLR_TXFRAMESTART_CLEAR												(0x1u<<3)
#define	NFCT_INTENCLR_FIELDLOST_DISABLED												(0x0u<<2)
#define	NFCT_INTENCLR_FIELDLOST_ENABLED													(0x1u<<2)
#define	NFCT_INTENCLR_FIELDLOST_CLEAR													(0x1u<<2)
#define	NFCT_INTENCLR_FIELDDETECTED_DISABLED											(0x0u<<1)
#define	NFCT_INTENCLR_FIELDDETECTED_ENABLED												(0x1u<<1)
#define	NFCT_INTENCLR_FIELDDETECTED_CLEAR												(0x1u<<1)
#define	NFCT_INTENCLR_READY_DISABLED													(0x0u<<0)
#define	NFCT_INTENCLR_READY_ENABLED														(0x1u<<0)
#define	NFCT_INTENCLR_READY_CLEAR														(0x1u<<0)

// ERRORSTATUS Configuration

#define	NFCT_ERRORSTATUS_FRAMEDELAYTIMEOUT												(0x1u<<0)

// RX Configuration

#define	NFCT_FRAMESTATUS_RX_OVERRUN														(0x1u<<3)
#define	NFCT_FRAMESTATUS_RX_PARITYSTATUS												(0x1u<<2)
#define	NFCT_FRAMESTATUS_RX_CRCERROR													(0x1u<<0)
#define	NFCT_FRAMESTATUS_RX_OVERRUN_NOOVERRUN											(0x0u<<3)
#define	NFCT_FRAMESTATUS_RX_OVERRUN_OVERRUN												(0x1u<<3)
#define	NFCT_FRAMESTATUS_RX_PARITYSTATUS_PARITYOK										(0x0u<<2)
#define	NFCT_FRAMESTATUS_RX_PARITYSTATUS_PARITYERROR									(0x1u<<2)
#define	NFCT_FRAMESTATUS_RX_CRCERROR_CRCCORRECT											(0x0u<<0)
#define	NFCT_FRAMESTATUS_RX_CRCERROR_CRCERROR											(0x1u<<0)

// NFCTAGSTATE Configuration

#define	NFCT_NFCTAGSTATE_NFCTAGSTATE													(0x7u<<0)
#define	NFCT_NFCTAGSTATE_NFCTAGSTATE_0													(0x1u<<0)
#define	NFCT_NFCTAGSTATE_NFCTAGSTATE_DISABLED											(0x0u<<0)
#define	NFCT_NFCTAGSTATE_NFCTAGSTATE_RAMPUP												(0x2u<<0)
#define	NFCT_NFCTAGSTATE_NFCTAGSTATE_IDLE												(0x3u<<0)
#define	NFCT_NFCTAGSTATE_NFCTAGSTATE_RECEIVE											(0x4u<<0)
#define	NFCT_NFCTAGSTATE_NFCTAGSTATE_FRAMEDELAY											(0x5u<<0)
#define	NFCT_NFCTAGSTATE_NFCTAGSTATE_TRANSMIT											(0x6u<<0)

// SLEEPSTATE Configuration

#define	NFCT_SLEEPSTATE_SLEEPSTATE														(0x1u<<0)
#define	NFCT_SLEEPSTATE_SLEEPSTATE_IDLE													(0x0u<<0)
#define	NFCT_SLEEPSTATE_SLEEPSTATE_SLEEPA												(0x1u<<0)

// FIELDPRESENT Configuration

#define	NFCT_FIELDPRESENT_LOCKDETECT													(0x1u<<1)
#define	NFCT_FIELDPRESENT_FIELDPRESENT													(0x1u<<0)
#define	NFCT_FIELDPRESENT_LOCKDETECT_NOTLOCKED											(0x0u<<1)
#define	NFCT_FIELDPRESENT_LOCKDETECT_LOCKED												(0x1u<<1)
#define	NFCT_FIELDPRESENT_FIELDPRESENT_NOFIELD											(0x0u<<0)
#define	NFCT_FIELDPRESENT_FIELDPRESENT_FIELDPRESENT										(0x1u<<0)

// FRAMEDELAYMIN Configuration

#define	NFCT_FRAMEDELAYMIN_FRAMEDELAYMIN												(0xFFFFu<<0)
#define	NFCT_FRAMEDELAYMIN_FRAMEDELAYMIN_0												(0x1u<<0)

// FRAMEDELAYMAX Configuration

#define	NFCT_FRAMEDELAYMAX_FRAMEDELAYMAX												(0xFFFFFu<<0)
#define	NFCT_FRAMEDELAYMAX_FRAMEDELAYMAX_0												(0x1u<<0)

// FRAMEDELAYMODE Configuration

#define	NFCT_FRAMEDELAYMODE_FRAMEDELAYMODE												(0x3u<<0)
#define	NFCT_FRAMEDELAYMODE_FRAMEDELAYMODE_0											(0x1u<<0)
#define	NFCT_FRAMEDELAYMODE_FRAMEDELAYMODE_FREERUN										(0x0u<<0)
#define	NFCT_FRAMEDELAYMODE_FRAMEDELAYMODE_WINDOW										(0x1u<<0)
#define	NFCT_FRAMEDELAYMODE_FRAMEDELAYMODE_EXACTVAL										(0x2u<<0)
#define	NFCT_FRAMEDELAYMODE_FRAMEDELAYMODE_WINDOWGRID									(0x3u<<0)

// PACKETPTR Configuration

#define	NFCT_PACKETPTR_PTR																(0xFFFFFFFFu<<0)
#define	NFCT_PACKETPTR_PTR_0															(0x1u<<0)

// MAXLEN Configuration

#define	NFCT_MAXLEN_MAXLEN																(0x1FFu<<0)
#define	NFCT_MAXLEN_MAXLEN_0															(0x1u<<0)

// FRAMECONFIG Configuration

#define	NFCT_TXD_FRAMECONFIG_CRCMODETX													(0x1u<<4)
#define	NFCT_TXD_FRAMECONFIG_SOF														(0x1u<<2)
#define	NFCT_TXD_FRAMECONFIG_DISCARDMODE												(0x1u<<1)
#define	NFCT_TXD_FRAMECONFIG_PARITY														(0x1u<<0)
#define	NFCT_TXD_FRAMECONFIG_CRCMODETX_NOCRCTX											(0x0u<<4)
#define	NFCT_TXD_FRAMECONFIG_CRCMODETX_CRC16TX											(0x1u<<4)
#define	NFCT_TXD_FRAMECONFIG_SOF_NOSOF													(0x0u<<2)
#define	NFCT_TXD_FRAMECONFIG_SOF_SOF													(0x1u<<2)
#define	NFCT_TXD_FRAMECONFIG_DISCARDMODE_DISCARDEND										(0x0u<<1)
#define	NFCT_TXD_FRAMECONFIG_DISCARDMODE_DISCARDSTART									(0x1u<<1)
#define	NFCT_TXD_FRAMECONFIG_PARITY_NOPARITY											(0x0u<<0)
#define	NFCT_TXD_FRAMECONFIG_PARITY_PARITY												(0x1u<<0)

// AMOUNT Configuration

#define	NFCT_TXD_AMOUNT_TXDATABYTES														(0x1FFu<<3)
#define	NFCT_TXD_AMOUNT_TXDATABYTES_0													(0x1u<<3)
#define	NFCT_TXD_AMOUNT_TXDATABITS														(0x7u<<0)
#define	NFCT_TXD_AMOUNT_TXDATABITS_0													(0x1u<<0)

// FRAMECONFIG Configuration

#define	NFCT_RXD_FRAMECONFIG_CRCMODERX													(0x1u<<4)
#define	NFCT_RXD_FRAMECONFIG_SOF														(0x1u<<2)
#define	NFCT_RXD_FRAMECONFIG_PARITY														(0x1u<<0)
#define	NFCT_RXD_FRAMECONFIG_CRCMODERX_NOCRCRX											(0x0u<<4)
#define	NFCT_RXD_FRAMECONFIG_CRCMODERX_CRC16RX											(0x1u<<4)
#define	NFCT_RXD_FRAMECONFIG_SOF_NOSOF													(0x0u<<2)
#define	NFCT_RXD_FRAMECONFIG_SOF_SOF													(0x1u<<2)
#define	NFCT_RXD_FRAMECONFIG_PARITY_NOPARITY											(0x0u<<0)
#define	NFCT_RXD_FRAMECONFIG_PARITY_PARITY												(0x1u<<0)

// AMOUNT Configuration

#define	NFCT_RXD_AMOUNT_RXDATABYTES														(0x1FFu<<3)
#define	NFCT_RXD_AMOUNT_RXDATABYTES_0													(0x1u<<3)
#define	NFCT_RXD_AMOUNT_RXDATABITS														(0x7u<<0)
#define	NFCT_RXD_AMOUNT_RXDATABITS_0													(0x1u<<0)

// MODULATIONCTRL Configuration

#define	NFCT_MODULATIONCTRL_MODULATIONCTRL												(0x3u<<0)
#define	NFCT_MODULATIONCTRL_MODULATIONCTRL_0											(0x1u<<0)
#define	NFCT_MODULATIONCTRL_MODULATIONCTRL_INVALID										(0x0u<<0)
#define	NFCT_MODULATIONCTRL_MODULATIONCTRL_INTERNAL										(0x1u<<0)
#define	NFCT_MODULATIONCTRL_MODULATIONCTRL_MODTOGPIO									(0x2u<<0)
#define	NFCT_MODULATIONCTRL_MODULATIONCTRL_INTERNALANDMODTOGPIO							(0x3u<<0)

// MODULATIONPSEL Configuration

#define	NFCT_MODULATIONPSEL_CONNECT														(0x1u<<31)
#define	NFCT_MODULATIONPSEL_PORT														(0x1u<<5)
#define	NFCT_MODULATIONPSEL_PIN															(0x1Fu<<0)
#define	NFCT_MODULATIONPSEL_PIN_0														(0x1u<<0)
#define	NFCT_MODULATIONPSEL_CONNECT_DISCONNECTED										(0x1u<<31)
#define	NFCT_MODULATIONPSEL_CONNECT_CONNECTED											(0x0u<<31)

// NFCID1_LAST Configuration

#define	NFCT_NFCID1_LAST_NFCID1_W														(0xFFu<<24)
#define	NFCT_NFCID1_LAST_NFCID1_W_0														(0x1u<<24)
#define	NFCT_NFCID1_LAST_NFCID1_X														(0xFFu<<16)
#define	NFCT_NFCID1_LAST_NFCID1_X_0														(0x1u<<16)
#define	NFCT_NFCID1_LAST_NFCID1_Y														(0xFFu<<8)
#define	NFCT_NFCID1_LAST_NFCID1_Y_0														(0x1u<<8)
#define	NFCT_NFCID1_LAST_NFCID1_Z														(0xFFu<<0)
#define	NFCT_NFCID1_LAST_NFCID1_Z_0														(0x1u<<0)

// NFCID1_2ND_LAST Configuration

#define	NFCT_NFCID1_2ND_LAST_NFCID1_T													(0xFFu<<16)
#define	NFCT_NFCID1_2ND_LAST_NFCID1_T_0													(0x1u<<16)
#define	NFCT_NFCID1_2ND_LAST_NFCID1_U													(0xFFu<<8)
#define	NFCT_NFCID1_2ND_LAST_NFCID1_U_0													(0x1u<<8)
#define	NFCT_NFCID1_2ND_LAST_NFCID1_V													(0xFFu<<0)
#define	NFCT_NFCID1_2ND_LAST_NFCID1_V_0													(0x1u<<0)

// NFCID1_3RD_LAST Configuration

#define	NFCT_NFCID1_3RD_LAST_NFCID1_Q													(0xFFu<<16)
#define	NFCT_NFCID1_3RD_LAST_NFCID1_Q_0													(0x1u<<16)
#define	NFCT_NFCID1_3RD_LAST_NFCID1_R													(0xFFu<<8)
#define	NFCT_NFCID1_3RD_LAST_NFCID1_R_0													(0x1u<<8)
#define	NFCT_NFCID1_3RD_LAST_NFCID1_S													(0xFFu<<0)
#define	NFCT_NFCID1_3RD_LAST_NFCID1_S_0													(0x1u<<0)

// AUTOCOLRESCONFIG Configuration

#define	NFCT_AUTOCOLRESCONFIG_MODE														(0x1u<<0)
#define	NFCT_AUTOCOLRESCONFIG_MODE_ENABLED												(0x0u<<0)
#define	NFCT_AUTOCOLRESCONFIG_MODE_DISABLED												(0x1u<<0)

// SENSRES Configuration

#define	NFCT_SENSRES_RFU74																(0xFu<<12)
#define	NFCT_SENSRES_RFU74_0															(0x1u<<12)
#define	NFCT_SENSRES_PLATFCONFIG														(0xFu<<8)
#define	NFCT_SENSRES_PLATFCONFIG_0														(0x1u<<8)
#define	NFCT_SENSRES_NFCIDSIZE															(0x3u<<6)
#define	NFCT_SENSRES_NFCIDSIZE_0														(0x1u<<6)
#define	NFCT_SENSRES_RFU5																(0x1u<<5)
#define	NFCT_SENSRES_BITFRAMESDD														(0x1Fu<<0)
#define	NFCT_SENSRES_BITFRAMESDD_0														(0x1u<<0)
#define	NFCT_SENSRES_NFCIDSIZE_NFCID1SINGLE												(0x0u<<6)
#define	NFCT_SENSRES_NFCIDSIZE_NFCID1DOUBLE												(0x1u<<6)
#define	NFCT_SENSRES_NFCIDSIZE_NFCID1TRIPLE												(0x2u<<6)
#define	NFCT_SENSRES_BITFRAMESDD_SDD00000												(0x0u<<0)
#define	NFCT_SENSRES_BITFRAMESDD_SDD00001												(0x1u<<0)
#define	NFCT_SENSRES_BITFRAMESDD_SDD00010												(0x2u<<0)
#define	NFCT_SENSRES_BITFRAMESDD_SDD00100												(0x4u<<0)
#define	NFCT_SENSRES_BITFRAMESDD_SDD01000												(0x8u<<0)
#define	NFCT_SENSRES_BITFRAMESDD_SDD10000												(0x10u<<0)

// SELRES Configuration

#define	NFCT_SELRES_RFU7																(0x1u<<7)
#define	NFCT_SELRES_PROTOCOL															(0x3u<<5)
#define	NFCT_SELRES_PROTOCOL_0															(0x1u<<5)
#define	NFCT_SELRES_RFU43																(0x3u<<3)
#define	NFCT_SELRES_RFU43_0																(0x1u<<3)
#define	NFCT_SELRES_CASCADE																(0x1u<<2)
#define	NFCT_SELRES_RFU10																(0x3u<<0)
#define	NFCT_SELRES_RFU10_0																(0x1u<<0)
