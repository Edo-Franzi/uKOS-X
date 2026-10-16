/*
; nrf5340_application_usbd.
; =========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_usbd equates.
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

// USBD address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	TASKS_STARTEPIN[8];
	volatile	uint32_t	TASKS_STARTISOIN;
	volatile	uint32_t	TASKS_STARTEPOUT[8];
	volatile	uint32_t	TASKS_STARTISOOUT;
	volatile	uint32_t	TASKS_EP0RCVOUT;
	volatile	uint32_t	TASKS_EP0STATUS;
	volatile	uint32_t	TASKS_EP0STALL;
	volatile	uint32_t	TASKS_DPDMDRIVE;
	volatile	uint32_t	TASKS_DPDMNODRIVE;
	volatile	uint32_t	RESERVED1[9];
	volatile	uint32_t	SUBSCRIBE_STARTEPIN[8];
	volatile	uint32_t	SUBSCRIBE_STARTISOIN;
	volatile	uint32_t	SUBSCRIBE_STARTEPOUT[8];
	volatile	uint32_t	SUBSCRIBE_STARTISOOUT;
	volatile	uint32_t	SUBSCRIBE_EP0RCVOUT;
	volatile	uint32_t	SUBSCRIBE_EP0STATUS;
	volatile	uint32_t	SUBSCRIBE_EP0STALL;
	volatile	uint32_t	SUBSCRIBE_DPDMDRIVE;
	volatile	uint32_t	SUBSCRIBE_DPDMNODRIVE;
	volatile	uint32_t	RESERVED2[8];
	volatile	uint32_t	EVENTS_USBRESET;
	volatile	uint32_t	EVENTS_STARTED;
	volatile	uint32_t	EVENTS_ENDEPIN[8];
	volatile	uint32_t	EVENTS_EP0DATADONE;
	volatile	uint32_t	EVENTS_ENDISOIN;
	volatile	uint32_t	EVENTS_ENDEPOUT[8];
	volatile	uint32_t	EVENTS_ENDISOOUT;
	volatile	uint32_t	EVENTS_SOF;
	volatile	uint32_t	EVENTS_USBEVENT;
	volatile	uint32_t	EVENTS_EP0SETUP;
	volatile	uint32_t	EVENTS_EPDATA;
	volatile	uint32_t	RESERVED3[7];
	volatile	uint32_t	PUBLISH_USBRESET;
	volatile	uint32_t	PUBLISH_STARTED;
	volatile	uint32_t	PUBLISH_ENDEPIN[8];
	volatile	uint32_t	PUBLISH_EP0DATADONE;
	volatile	uint32_t	PUBLISH_ENDISOIN;
	volatile	uint32_t	PUBLISH_ENDEPOUT[8];
	volatile	uint32_t	PUBLISH_ENDISOOUT;
	volatile	uint32_t	PUBLISH_SOF;
	volatile	uint32_t	PUBLISH_USBEVENT;
	volatile	uint32_t	PUBLISH_EP0SETUP;
	volatile	uint32_t	PUBLISH_EPDATA;
	volatile	uint32_t	RESERVED4[7];
	volatile	uint32_t	SHORTS;
	volatile	uint32_t	RESERVED5[63];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED6[61];
	volatile	uint32_t	EVENTCAUSE;
	volatile	uint32_t	RESERVED7[7];
	volatile	uint32_t	HALTED_EPIN[8];
	volatile	uint32_t	RESERVED8;
	volatile	uint32_t	HALTED_EPOUT[8];
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	EPSTATUS;
	volatile	uint32_t	EPDATASTATUS;
	volatile	uint32_t	USBADDR;
	volatile	uint32_t	RESERVED10[3];
	volatile	uint32_t	BMREQUESTTYPE;
	volatile	uint32_t	BREQUEST;
	volatile	uint32_t	WVALUEL;
	volatile	uint32_t	WVALUEH;
	volatile	uint32_t	WINDEXL;
	volatile	uint32_t	WINDEXH;
	volatile	uint32_t	WLENGTHL;
	volatile	uint32_t	WLENGTHH;
	volatile	uint32_t	SIZE_EPOUT[8];
	volatile	uint32_t	SIZE_ISOOUT;
	volatile	uint32_t	RESERVED11[15];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	USBPULLUP;
	volatile	uint32_t	DPDMVALUE;
	volatile	uint32_t	DTOGGLE;
	volatile	uint32_t	EPINEN;
	volatile	uint32_t	EPOUTEN;
	volatile	uint32_t	EPSTALL;
	volatile	uint32_t	ISOSPLIT;
	volatile	uint32_t	FRAMECNTR;
	volatile	uint32_t	RESERVED12[2];
	volatile	uint32_t	LOWPOWER;
	volatile	uint32_t	ISOINCONFIG;
	volatile	uint32_t	RESERVED13[51];
	volatile	uint32_t	EPIN0_PTR;
	volatile	uint32_t	EPIN0_MAXCNT;
	volatile	uint32_t	EPIN0_AMOUNT;
	volatile	uint32_t	RESERVED14[2];
	volatile	uint32_t	EPIN1_PTR;
	volatile	uint32_t	EPIN1_MAXCNT;
	volatile	uint32_t	EPIN1_AMOUNT;
	volatile	uint32_t	RESERVED15[2];
	volatile	uint32_t	EPIN2_PTR;
	volatile	uint32_t	EPIN2_MAXCNT;
	volatile	uint32_t	EPIN2_AMOUNT;
	volatile	uint32_t	RESERVED16[2];
	volatile	uint32_t	EPIN3_PTR;
	volatile	uint32_t	EPIN3_MAXCNT;
	volatile	uint32_t	EPIN3_AMOUNT;
	volatile	uint32_t	RESERVED17[2];
	volatile	uint32_t	EPIN4_PTR;
	volatile	uint32_t	EPIN4_MAXCNT;
	volatile	uint32_t	EPIN4_AMOUNT;
	volatile	uint32_t	RESERVED18[2];
	volatile	uint32_t	EPIN5_PTR;
	volatile	uint32_t	EPIN5_MAXCNT;
	volatile	uint32_t	EPIN5_AMOUNT;
	volatile	uint32_t	RESERVED19[2];
	volatile	uint32_t	EPIN6_PTR;
	volatile	uint32_t	EPIN6_MAXCNT;
	volatile	uint32_t	EPIN6_AMOUNT;
	volatile	uint32_t	RESERVED20[2];
	volatile	uint32_t	EPIN7_PTR;
	volatile	uint32_t	EPIN7_MAXCNT;
	volatile	uint32_t	EPIN7_AMOUNT;
	volatile	uint32_t	RESERVED21[2];
	volatile	uint32_t	ISOIN_PTR;
	volatile	uint32_t	ISOIN_MAXCNT;
	volatile	uint32_t	ISOIN_AMOUNT;
	volatile	uint32_t	RESERVED22[21];
	volatile	uint32_t	EPOUT0_PTR;
	volatile	uint32_t	EPOUT0_MAXCNT;
	volatile	uint32_t	EPOUT0_AMOUNT;
	volatile	uint32_t	RESERVED23[2];
	volatile	uint32_t	EPOUT1_PTR;
	volatile	uint32_t	EPOUT1_MAXCNT;
	volatile	uint32_t	EPOUT1_AMOUNT;
	volatile	uint32_t	RESERVED24[2];
	volatile	uint32_t	EPOUT2_PTR;
	volatile	uint32_t	EPOUT2_MAXCNT;
	volatile	uint32_t	EPOUT2_AMOUNT;
	volatile	uint32_t	RESERVED25[2];
	volatile	uint32_t	EPOUT3_PTR;
	volatile	uint32_t	EPOUT3_MAXCNT;
	volatile	uint32_t	EPOUT3_AMOUNT;
	volatile	uint32_t	RESERVED26[2];
	volatile	uint32_t	EPOUT4_PTR;
	volatile	uint32_t	EPOUT4_MAXCNT;
	volatile	uint32_t	EPOUT4_AMOUNT;
	volatile	uint32_t	RESERVED27[2];
	volatile	uint32_t	EPOUT5_PTR;
	volatile	uint32_t	EPOUT5_MAXCNT;
	volatile	uint32_t	EPOUT5_AMOUNT;
	volatile	uint32_t	RESERVED28[2];
	volatile	uint32_t	EPOUT6_PTR;
	volatile	uint32_t	EPOUT6_MAXCNT;
	volatile	uint32_t	EPOUT6_AMOUNT;
	volatile	uint32_t	RESERVED29[2];
	volatile	uint32_t	EPOUT7_PTR;
	volatile	uint32_t	EPOUT7_MAXCNT;
	volatile	uint32_t	EPOUT7_AMOUNT;
	volatile	uint32_t	RESERVED30[2];
	volatile	uint32_t	ISOOUT_PTR;
	volatile	uint32_t	ISOOUT_MAXCNT;
	volatile	uint32_t	ISOOUT_AMOUNT;
} USBD_TypeDef;

#if (defined(__cplusplus))
#define	USBD_NS	reinterpret_cast<USBD_TypeDef *>(0x40036000u)
#define	USBD_S	reinterpret_cast<USBD_TypeDef *>(0x50036000u)

#else
#define	USBD_NS	((USBD_TypeDef *)0x40036000u)
#define	USBD_S	((USBD_TypeDef *)0x50036000u)
#endif

// TASKS_STARTEPIN Configuration

#define	USBD_TASKS_STARTEPIN_TASKS_STARTEPIN						(0x1u<<0)
#define	USBD_TASKS_STARTEPIN_TASKS_STARTEPIN_TRIGGER				(0x1u<<0)

// TASKS_STARTISOIN Configuration

#define	USBD_TASKS_STARTISOIN_TASKS_STARTISOIN						(0x1u<<0)
#define	USBD_TASKS_STARTISOIN_TASKS_STARTISOIN_TRIGGER				(0x1u<<0)

// TASKS_STARTEPOUT Configuration

#define	USBD_TASKS_STARTEPOUT_TASKS_STARTEPOUT						(0x1u<<0)
#define	USBD_TASKS_STARTEPOUT_TASKS_STARTEPOUT_TRIGGER				(0x1u<<0)

// TASKS_STARTISOOUT Configuration

#define	USBD_TASKS_STARTISOOUT_TASKS_STARTISOOUT					(0x1u<<0)
#define	USBD_TASKS_STARTISOOUT_TASKS_STARTISOOUT_TRIGGER			(0x1u<<0)

// TASKS_EP0RCVOUT Configuration

#define	USBD_TASKS_EP0RCVOUT_TASKS_EP0RCVOUT						(0x1u<<0)
#define	USBD_TASKS_EP0RCVOUT_TASKS_EP0RCVOUT_TRIGGER				(0x1u<<0)

// TASKS_EP0STATUS Configuration

#define	USBD_TASKS_EP0STATUS_TASKS_EP0STATUS						(0x1u<<0)
#define	USBD_TASKS_EP0STATUS_TASKS_EP0STATUS_TRIGGER				(0x1u<<0)

// TASKS_EP0STALL Configuration

#define	USBD_TASKS_EP0STALL_TASKS_EP0STALL							(0x1u<<0)
#define	USBD_TASKS_EP0STALL_TASKS_EP0STALL_TRIGGER					(0x1u<<0)

// TASKS_DPDMDRIVE Configuration

#define	USBD_TASKS_DPDMDRIVE_TASKS_DPDMDRIVE						(0x1u<<0)
#define	USBD_TASKS_DPDMDRIVE_TASKS_DPDMDRIVE_TRIGGER				(0x1u<<0)

// TASKS_DPDMNODRIVE Configuration

#define	USBD_TASKS_DPDMNODRIVE_TASKS_DPDMNODRIVE					(0x1u<<0)
#define	USBD_TASKS_DPDMNODRIVE_TASKS_DPDMNODRIVE_TRIGGER			(0x1u<<0)

// SUBSCRIBE_STARTEPIN Configuration

#define	USBD_SUBSCRIBE_STARTEPIN_EN									(0x1u<<31)
#define	USBD_SUBSCRIBE_STARTEPIN_CHIDX								(0xFFu<<0)
#define	USBD_SUBSCRIBE_STARTEPIN_CHIDX_0							(0x1u<<0)
#define	USBD_SUBSCRIBE_STARTEPIN_EN_DISABLED						(0x0u<<31)
#define	USBD_SUBSCRIBE_STARTEPIN_EN_ENABLED							(0x1u<<31)

// SUBSCRIBE_STARTISOIN Configuration

#define	USBD_SUBSCRIBE_STARTISOIN_EN								(0x1u<<31)
#define	USBD_SUBSCRIBE_STARTISOIN_CHIDX								(0xFFu<<0)
#define	USBD_SUBSCRIBE_STARTISOIN_CHIDX_0							(0x1u<<0)
#define	USBD_SUBSCRIBE_STARTISOIN_EN_DISABLED						(0x0u<<31)
#define	USBD_SUBSCRIBE_STARTISOIN_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_STARTEPOUT Configuration

#define	USBD_SUBSCRIBE_STARTEPOUT_EN								(0x1u<<31)
#define	USBD_SUBSCRIBE_STARTEPOUT_CHIDX								(0xFFu<<0)
#define	USBD_SUBSCRIBE_STARTEPOUT_CHIDX_0							(0x1u<<0)
#define	USBD_SUBSCRIBE_STARTEPOUT_EN_DISABLED						(0x0u<<31)
#define	USBD_SUBSCRIBE_STARTEPOUT_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_STARTISOOUT Configuration

#define	USBD_SUBSCRIBE_STARTISOOUT_EN								(0x1u<<31)
#define	USBD_SUBSCRIBE_STARTISOOUT_CHIDX							(0xFFu<<0)
#define	USBD_SUBSCRIBE_STARTISOOUT_CHIDX_0							(0x1u<<0)
#define	USBD_SUBSCRIBE_STARTISOOUT_EN_DISABLED						(0x0u<<31)
#define	USBD_SUBSCRIBE_STARTISOOUT_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_EP0RCVOUT Configuration

#define	USBD_SUBSCRIBE_EP0RCVOUT_EN									(0x1u<<31)
#define	USBD_SUBSCRIBE_EP0RCVOUT_CHIDX								(0xFFu<<0)
#define	USBD_SUBSCRIBE_EP0RCVOUT_CHIDX_0							(0x1u<<0)
#define	USBD_SUBSCRIBE_EP0RCVOUT_EN_DISABLED						(0x0u<<31)
#define	USBD_SUBSCRIBE_EP0RCVOUT_EN_ENABLED							(0x1u<<31)

// SUBSCRIBE_EP0STATUS Configuration

#define	USBD_SUBSCRIBE_EP0STATUS_EN									(0x1u<<31)
#define	USBD_SUBSCRIBE_EP0STATUS_CHIDX								(0xFFu<<0)
#define	USBD_SUBSCRIBE_EP0STATUS_CHIDX_0							(0x1u<<0)
#define	USBD_SUBSCRIBE_EP0STATUS_EN_DISABLED						(0x0u<<31)
#define	USBD_SUBSCRIBE_EP0STATUS_EN_ENABLED							(0x1u<<31)

// SUBSCRIBE_EP0STALL Configuration

#define	USBD_SUBSCRIBE_EP0STALL_EN									(0x1u<<31)
#define	USBD_SUBSCRIBE_EP0STALL_CHIDX								(0xFFu<<0)
#define	USBD_SUBSCRIBE_EP0STALL_CHIDX_0								(0x1u<<0)
#define	USBD_SUBSCRIBE_EP0STALL_EN_DISABLED							(0x0u<<31)
#define	USBD_SUBSCRIBE_EP0STALL_EN_ENABLED							(0x1u<<31)

// SUBSCRIBE_DPDMDRIVE Configuration

#define	USBD_SUBSCRIBE_DPDMDRIVE_EN									(0x1u<<31)
#define	USBD_SUBSCRIBE_DPDMDRIVE_CHIDX								(0xFFu<<0)
#define	USBD_SUBSCRIBE_DPDMDRIVE_CHIDX_0							(0x1u<<0)
#define	USBD_SUBSCRIBE_DPDMDRIVE_EN_DISABLED						(0x0u<<31)
#define	USBD_SUBSCRIBE_DPDMDRIVE_EN_ENABLED							(0x1u<<31)

// SUBSCRIBE_DPDMNODRIVE Configuration

#define	USBD_SUBSCRIBE_DPDMNODRIVE_EN								(0x1u<<31)
#define	USBD_SUBSCRIBE_DPDMNODRIVE_CHIDX							(0xFFu<<0)
#define	USBD_SUBSCRIBE_DPDMNODRIVE_CHIDX_0							(0x1u<<0)
#define	USBD_SUBSCRIBE_DPDMNODRIVE_EN_DISABLED						(0x0u<<31)
#define	USBD_SUBSCRIBE_DPDMNODRIVE_EN_ENABLED						(0x1u<<31)

// EVENTS_USBRESET Configuration

#define	USBD_EVENTS_USBRESET_EVENTS_USBRESET						(0x1u<<0)
#define	USBD_EVENTS_USBRESET_EVENTS_USBRESET_NOTGENERATED			(0x0u<<0)
#define	USBD_EVENTS_USBRESET_EVENTS_USBRESET_GENERATED				(0x1u<<0)

// EVENTS_STARTED Configuration

#define	USBD_EVENTS_STARTED_EVENTS_STARTED							(0x1u<<0)
#define	USBD_EVENTS_STARTED_EVENTS_STARTED_NOTGENERATED				(0x0u<<0)
#define	USBD_EVENTS_STARTED_EVENTS_STARTED_GENERATED				(0x1u<<0)

// EVENTS_ENDEPIN Configuration

#define	USBD_EVENTS_ENDEPIN_EVENTS_ENDEPIN							(0x1u<<0)
#define	USBD_EVENTS_ENDEPIN_EVENTS_ENDEPIN_NOTGENERATED				(0x0u<<0)
#define	USBD_EVENTS_ENDEPIN_EVENTS_ENDEPIN_GENERATED				(0x1u<<0)

// EVENTS_EP0DATADONE Configuration

#define	USBD_EVENTS_EP0DATADONE_EVENTS_EP0DATADONE					(0x1u<<0)
#define	USBD_EVENTS_EP0DATADONE_EVENTS_EP0DATADONE_NOTGENERATED		(0x0u<<0)
#define	USBD_EVENTS_EP0DATADONE_EVENTS_EP0DATADONE_GENERATED		(0x1u<<0)

// EVENTS_ENDISOIN Configuration

#define	USBD_EVENTS_ENDISOIN_EVENTS_ENDISOIN						(0x1u<<0)
#define	USBD_EVENTS_ENDISOIN_EVENTS_ENDISOIN_NOTGENERATED			(0x0u<<0)
#define	USBD_EVENTS_ENDISOIN_EVENTS_ENDISOIN_GENERATED				(0x1u<<0)

// EVENTS_ENDEPOUT Configuration

#define	USBD_EVENTS_ENDEPOUT_EVENTS_ENDEPOUT						(0x1u<<0)
#define	USBD_EVENTS_ENDEPOUT_EVENTS_ENDEPOUT_NOTGENERATED			(0x0u<<0)
#define	USBD_EVENTS_ENDEPOUT_EVENTS_ENDEPOUT_GENERATED				(0x1u<<0)

// EVENTS_ENDISOOUT Configuration

#define	USBD_EVENTS_ENDISOOUT_EVENTS_ENDISOOUT						(0x1u<<0)
#define	USBD_EVENTS_ENDISOOUT_EVENTS_ENDISOOUT_NOTGENERATED			(0x0u<<0)
#define	USBD_EVENTS_ENDISOOUT_EVENTS_ENDISOOUT_GENERATED			(0x1u<<0)

// EVENTS_SOF Configuration

#define	USBD_EVENTS_SOF_EVENTS_SOF									(0x1u<<0)
#define	USBD_EVENTS_SOF_EVENTS_SOF_NOTGENERATED						(0x0u<<0)
#define	USBD_EVENTS_SOF_EVENTS_SOF_GENERATED						(0x1u<<0)

// EVENTS_USBEVENT Configuration

#define	USBD_EVENTS_USBEVENT_EVENTS_USBEVENT						(0x1u<<0)
#define	USBD_EVENTS_USBEVENT_EVENTS_USBEVENT_NOTGENERATED			(0x0u<<0)
#define	USBD_EVENTS_USBEVENT_EVENTS_USBEVENT_GENERATED				(0x1u<<0)

// EVENTS_EP0SETUP Configuration

#define	USBD_EVENTS_EP0SETUP_EVENTS_EP0SETUP						(0x1u<<0)
#define	USBD_EVENTS_EP0SETUP_EVENTS_EP0SETUP_NOTGENERATED			(0x0u<<0)
#define	USBD_EVENTS_EP0SETUP_EVENTS_EP0SETUP_GENERATED				(0x1u<<0)

// EVENTS_EPDATA Configuration

#define	USBD_EVENTS_EPDATA_EVENTS_EPDATA							(0x1u<<0)
#define	USBD_EVENTS_EPDATA_EVENTS_EPDATA_NOTGENERATED				(0x0u<<0)
#define	USBD_EVENTS_EPDATA_EVENTS_EPDATA_GENERATED					(0x1u<<0)

// PUBLISH_USBRESET Configuration

#define	USBD_PUBLISH_USBRESET_EN									(0x1u<<31)
#define	USBD_PUBLISH_USBRESET_CHIDX									(0xFFu<<0)
#define	USBD_PUBLISH_USBRESET_CHIDX_0								(0x1u<<0)
#define	USBD_PUBLISH_USBRESET_EN_DISABLED							(0x0u<<31)
#define	USBD_PUBLISH_USBRESET_EN_ENABLED							(0x1u<<31)

// PUBLISH_STARTED Configuration

#define	USBD_PUBLISH_STARTED_EN										(0x1u<<31)
#define	USBD_PUBLISH_STARTED_CHIDX									(0xFFu<<0)
#define	USBD_PUBLISH_STARTED_CHIDX_0								(0x1u<<0)
#define	USBD_PUBLISH_STARTED_EN_DISABLED							(0x0u<<31)
#define	USBD_PUBLISH_STARTED_EN_ENABLED								(0x1u<<31)

// PUBLISH_ENDEPIN Configuration

#define	USBD_PUBLISH_ENDEPIN_EN										(0x1u<<31)
#define	USBD_PUBLISH_ENDEPIN_CHIDX									(0xFFu<<0)
#define	USBD_PUBLISH_ENDEPIN_CHIDX_0								(0x1u<<0)
#define	USBD_PUBLISH_ENDEPIN_EN_DISABLED							(0x0u<<31)
#define	USBD_PUBLISH_ENDEPIN_EN_ENABLED								(0x1u<<31)

// PUBLISH_EP0DATADONE Configuration

#define	USBD_PUBLISH_EP0DATADONE_EN									(0x1u<<31)
#define	USBD_PUBLISH_EP0DATADONE_CHIDX								(0xFFu<<0)
#define	USBD_PUBLISH_EP0DATADONE_CHIDX_0							(0x1u<<0)
#define	USBD_PUBLISH_EP0DATADONE_EN_DISABLED						(0x0u<<31)
#define	USBD_PUBLISH_EP0DATADONE_EN_ENABLED							(0x1u<<31)

// PUBLISH_ENDISOIN Configuration

#define	USBD_PUBLISH_ENDISOIN_EN									(0x1u<<31)
#define	USBD_PUBLISH_ENDISOIN_CHIDX									(0xFFu<<0)
#define	USBD_PUBLISH_ENDISOIN_CHIDX_0								(0x1u<<0)
#define	USBD_PUBLISH_ENDISOIN_EN_DISABLED							(0x0u<<31)
#define	USBD_PUBLISH_ENDISOIN_EN_ENABLED							(0x1u<<31)

// PUBLISH_ENDEPOUT Configuration

#define	USBD_PUBLISH_ENDEPOUT_EN									(0x1u<<31)
#define	USBD_PUBLISH_ENDEPOUT_CHIDX									(0xFFu<<0)
#define	USBD_PUBLISH_ENDEPOUT_CHIDX_0								(0x1u<<0)
#define	USBD_PUBLISH_ENDEPOUT_EN_DISABLED							(0x0u<<31)
#define	USBD_PUBLISH_ENDEPOUT_EN_ENABLED							(0x1u<<31)

// PUBLISH_ENDISOOUT Configuration

#define	USBD_PUBLISH_ENDISOOUT_EN									(0x1u<<31)
#define	USBD_PUBLISH_ENDISOOUT_CHIDX								(0xFFu<<0)
#define	USBD_PUBLISH_ENDISOOUT_CHIDX_0								(0x1u<<0)
#define	USBD_PUBLISH_ENDISOOUT_EN_DISABLED							(0x0u<<31)
#define	USBD_PUBLISH_ENDISOOUT_EN_ENABLED							(0x1u<<31)

// PUBLISH_SOF Configuration

#define	USBD_PUBLISH_SOF_EN											(0x1u<<31)
#define	USBD_PUBLISH_SOF_CHIDX										(0xFFu<<0)
#define	USBD_PUBLISH_SOF_CHIDX_0									(0x1u<<0)
#define	USBD_PUBLISH_SOF_EN_DISABLED								(0x0u<<31)
#define	USBD_PUBLISH_SOF_EN_ENABLED									(0x1u<<31)

// PUBLISH_USBEVENT Configuration

#define	USBD_PUBLISH_USBEVENT_EN									(0x1u<<31)
#define	USBD_PUBLISH_USBEVENT_CHIDX									(0xFFu<<0)
#define	USBD_PUBLISH_USBEVENT_CHIDX_0								(0x1u<<0)
#define	USBD_PUBLISH_USBEVENT_EN_DISABLED							(0x0u<<31)
#define	USBD_PUBLISH_USBEVENT_EN_ENABLED							(0x1u<<31)

// PUBLISH_EP0SETUP Configuration

#define	USBD_PUBLISH_EP0SETUP_EN									(0x1u<<31)
#define	USBD_PUBLISH_EP0SETUP_CHIDX									(0xFFu<<0)
#define	USBD_PUBLISH_EP0SETUP_CHIDX_0								(0x1u<<0)
#define	USBD_PUBLISH_EP0SETUP_EN_DISABLED							(0x0u<<31)
#define	USBD_PUBLISH_EP0SETUP_EN_ENABLED							(0x1u<<31)

// PUBLISH_EPDATA Configuration

#define	USBD_PUBLISH_EPDATA_EN										(0x1u<<31)
#define	USBD_PUBLISH_EPDATA_CHIDX									(0xFFu<<0)
#define	USBD_PUBLISH_EPDATA_CHIDX_0									(0x1u<<0)
#define	USBD_PUBLISH_EPDATA_EN_DISABLED								(0x0u<<31)
#define	USBD_PUBLISH_EPDATA_EN_ENABLED								(0x1u<<31)

// SHORTS Configuration

#define	USBD_SHORTS_ENDEPOUT0_EP0RCVOUT								(0x1u<<4)
#define	USBD_SHORTS_ENDEPOUT0_EP0STATUS								(0x1u<<3)
#define	USBD_SHORTS_EP0DATADONE_EP0STATUS							(0x1u<<2)
#define	USBD_SHORTS_EP0DATADONE_STARTEPOUT0							(0x1u<<1)
#define	USBD_SHORTS_EP0DATADONE_STARTEPIN0							(0x1u<<0)
#define	USBD_SHORTS_ENDEPOUT0_EP0RCVOUT_DISABLED					(0x0u<<4)
#define	USBD_SHORTS_ENDEPOUT0_EP0RCVOUT_ENABLED						(0x1u<<4)
#define	USBD_SHORTS_ENDEPOUT0_EP0STATUS_DISABLED					(0x0u<<3)
#define	USBD_SHORTS_ENDEPOUT0_EP0STATUS_ENABLED						(0x1u<<3)
#define	USBD_SHORTS_EP0DATADONE_EP0STATUS_DISABLED					(0x0u<<2)
#define	USBD_SHORTS_EP0DATADONE_EP0STATUS_ENABLED					(0x1u<<2)
#define	USBD_SHORTS_EP0DATADONE_STARTEPOUT0_DISABLED				(0x0u<<1)
#define	USBD_SHORTS_EP0DATADONE_STARTEPOUT0_ENABLED					(0x1u<<1)
#define	USBD_SHORTS_EP0DATADONE_STARTEPIN0_DISABLED					(0x0u<<0)
#define	USBD_SHORTS_EP0DATADONE_STARTEPIN0_ENABLED					(0x1u<<0)

// INTEN Configuration

#define	USBD_INTEN_EPDATA											(0x1u<<24)
#define	USBD_INTEN_EP0SETUP											(0x1u<<23)
#define	USBD_INTEN_USBEVENT											(0x1u<<22)
#define	USBD_INTEN_SOF												(0x1u<<21)
#define	USBD_INTEN_ENDISOOUT										(0x1u<<20)
#define	USBD_INTEN_ENDEPOUT7										(0x1u<<19)
#define	USBD_INTEN_ENDEPOUT6										(0x1u<<18)
#define	USBD_INTEN_ENDEPOUT5										(0x1u<<17)
#define	USBD_INTEN_ENDEPOUT4										(0x1u<<16)
#define	USBD_INTEN_ENDEPOUT3										(0x1u<<15)
#define	USBD_INTEN_ENDEPOUT2										(0x1u<<14)
#define	USBD_INTEN_ENDEPOUT1										(0x1u<<13)
#define	USBD_INTEN_ENDEPOUT0										(0x1u<<12)
#define	USBD_INTEN_ENDISOIN											(0x1u<<11)
#define	USBD_INTEN_EP0DATADONE										(0x1u<<10)
#define	USBD_INTEN_ENDEPIN7											(0x1u<<9)
#define	USBD_INTEN_ENDEPIN6											(0x1u<<8)
#define	USBD_INTEN_ENDEPIN5											(0x1u<<7)
#define	USBD_INTEN_ENDEPIN4											(0x1u<<6)
#define	USBD_INTEN_ENDEPIN3											(0x1u<<5)
#define	USBD_INTEN_ENDEPIN2											(0x1u<<4)
#define	USBD_INTEN_ENDEPIN1											(0x1u<<3)
#define	USBD_INTEN_ENDEPIN0											(0x1u<<2)
#define	USBD_INTEN_STARTED											(0x1u<<1)
#define	USBD_INTEN_USBRESET											(0x1u<<0)
#define	USBD_INTEN_EPDATA_DISABLED									(0x0u<<24)
#define	USBD_INTEN_EPDATA_ENABLED									(0x1u<<24)
#define	USBD_INTEN_EP0SETUP_DISABLED								(0x0u<<23)
#define	USBD_INTEN_EP0SETUP_ENABLED									(0x1u<<23)
#define	USBD_INTEN_USBEVENT_DISABLED								(0x0u<<22)
#define	USBD_INTEN_USBEVENT_ENABLED									(0x1u<<22)
#define	USBD_INTEN_SOF_DISABLED										(0x0u<<21)
#define	USBD_INTEN_SOF_ENABLED										(0x1u<<21)
#define	USBD_INTEN_ENDISOOUT_DISABLED								(0x0u<<20)
#define	USBD_INTEN_ENDISOOUT_ENABLED								(0x1u<<20)
#define	USBD_INTEN_ENDEPOUT7_DISABLED								(0x0u<<19)
#define	USBD_INTEN_ENDEPOUT7_ENABLED								(0x1u<<19)
#define	USBD_INTEN_ENDEPOUT6_DISABLED								(0x0u<<18)
#define	USBD_INTEN_ENDEPOUT6_ENABLED								(0x1u<<18)
#define	USBD_INTEN_ENDEPOUT5_DISABLED								(0x0u<<17)
#define	USBD_INTEN_ENDEPOUT5_ENABLED								(0x1u<<17)
#define	USBD_INTEN_ENDEPOUT4_DISABLED								(0x0u<<16)
#define	USBD_INTEN_ENDEPOUT4_ENABLED								(0x1u<<16)
#define	USBD_INTEN_ENDEPOUT3_DISABLED								(0x0u<<15)
#define	USBD_INTEN_ENDEPOUT3_ENABLED								(0x1u<<15)
#define	USBD_INTEN_ENDEPOUT2_DISABLED								(0x0u<<14)
#define	USBD_INTEN_ENDEPOUT2_ENABLED								(0x1u<<14)
#define	USBD_INTEN_ENDEPOUT1_DISABLED								(0x0u<<13)
#define	USBD_INTEN_ENDEPOUT1_ENABLED								(0x1u<<13)
#define	USBD_INTEN_ENDEPOUT0_DISABLED								(0x0u<<12)
#define	USBD_INTEN_ENDEPOUT0_ENABLED								(0x1u<<12)
#define	USBD_INTEN_ENDISOIN_DISABLED								(0x0u<<11)
#define	USBD_INTEN_ENDISOIN_ENABLED									(0x1u<<11)
#define	USBD_INTEN_EP0DATADONE_DISABLED								(0x0u<<10)
#define	USBD_INTEN_EP0DATADONE_ENABLED								(0x1u<<10)
#define	USBD_INTEN_ENDEPIN7_DISABLED								(0x0u<<9)
#define	USBD_INTEN_ENDEPIN7_ENABLED									(0x1u<<9)
#define	USBD_INTEN_ENDEPIN6_DISABLED								(0x0u<<8)
#define	USBD_INTEN_ENDEPIN6_ENABLED									(0x1u<<8)
#define	USBD_INTEN_ENDEPIN5_DISABLED								(0x0u<<7)
#define	USBD_INTEN_ENDEPIN5_ENABLED									(0x1u<<7)
#define	USBD_INTEN_ENDEPIN4_DISABLED								(0x0u<<6)
#define	USBD_INTEN_ENDEPIN4_ENABLED									(0x1u<<6)
#define	USBD_INTEN_ENDEPIN3_DISABLED								(0x0u<<5)
#define	USBD_INTEN_ENDEPIN3_ENABLED									(0x1u<<5)
#define	USBD_INTEN_ENDEPIN2_DISABLED								(0x0u<<4)
#define	USBD_INTEN_ENDEPIN2_ENABLED									(0x1u<<4)
#define	USBD_INTEN_ENDEPIN1_DISABLED								(0x0u<<3)
#define	USBD_INTEN_ENDEPIN1_ENABLED									(0x1u<<3)
#define	USBD_INTEN_ENDEPIN0_DISABLED								(0x0u<<2)
#define	USBD_INTEN_ENDEPIN0_ENABLED									(0x1u<<2)
#define	USBD_INTEN_STARTED_DISABLED									(0x0u<<1)
#define	USBD_INTEN_STARTED_ENABLED									(0x1u<<1)
#define	USBD_INTEN_USBRESET_DISABLED								(0x0u<<0)
#define	USBD_INTEN_USBRESET_ENABLED									(0x1u<<0)

// INTENSET Configuration

#define	USBD_INTENSET_EPDATA										(0x1u<<24)
#define	USBD_INTENSET_EP0SETUP										(0x1u<<23)
#define	USBD_INTENSET_USBEVENT										(0x1u<<22)
#define	USBD_INTENSET_SOF											(0x1u<<21)
#define	USBD_INTENSET_ENDISOOUT										(0x1u<<20)
#define	USBD_INTENSET_ENDEPOUT7										(0x1u<<19)
#define	USBD_INTENSET_ENDEPOUT6										(0x1u<<18)
#define	USBD_INTENSET_ENDEPOUT5										(0x1u<<17)
#define	USBD_INTENSET_ENDEPOUT4										(0x1u<<16)
#define	USBD_INTENSET_ENDEPOUT3										(0x1u<<15)
#define	USBD_INTENSET_ENDEPOUT2										(0x1u<<14)
#define	USBD_INTENSET_ENDEPOUT1										(0x1u<<13)
#define	USBD_INTENSET_ENDEPOUT0										(0x1u<<12)
#define	USBD_INTENSET_ENDISOIN										(0x1u<<11)
#define	USBD_INTENSET_EP0DATADONE									(0x1u<<10)
#define	USBD_INTENSET_ENDEPIN7										(0x1u<<9)
#define	USBD_INTENSET_ENDEPIN6										(0x1u<<8)
#define	USBD_INTENSET_ENDEPIN5										(0x1u<<7)
#define	USBD_INTENSET_ENDEPIN4										(0x1u<<6)
#define	USBD_INTENSET_ENDEPIN3										(0x1u<<5)
#define	USBD_INTENSET_ENDEPIN2										(0x1u<<4)
#define	USBD_INTENSET_ENDEPIN1										(0x1u<<3)
#define	USBD_INTENSET_ENDEPIN0										(0x1u<<2)
#define	USBD_INTENSET_STARTED										(0x1u<<1)
#define	USBD_INTENSET_USBRESET										(0x1u<<0)
#define	USBD_INTENSET_EPDATA_DISABLED								(0x0u<<24)
#define	USBD_INTENSET_EPDATA_ENABLED								(0x1u<<24)
#define	USBD_INTENSET_EPDATA_SET									(0x1u<<24)
#define	USBD_INTENSET_EP0SETUP_DISABLED								(0x0u<<23)
#define	USBD_INTENSET_EP0SETUP_ENABLED								(0x1u<<23)
#define	USBD_INTENSET_EP0SETUP_SET									(0x1u<<23)
#define	USBD_INTENSET_USBEVENT_DISABLED								(0x0u<<22)
#define	USBD_INTENSET_USBEVENT_ENABLED								(0x1u<<22)
#define	USBD_INTENSET_USBEVENT_SET									(0x1u<<22)
#define	USBD_INTENSET_SOF_DISABLED									(0x0u<<21)
#define	USBD_INTENSET_SOF_ENABLED									(0x1u<<21)
#define	USBD_INTENSET_SOF_SET										(0x1u<<21)
#define	USBD_INTENSET_ENDISOOUT_DISABLED							(0x0u<<20)
#define	USBD_INTENSET_ENDISOOUT_ENABLED								(0x1u<<20)
#define	USBD_INTENSET_ENDISOOUT_SET									(0x1u<<20)
#define	USBD_INTENSET_ENDEPOUT7_DISABLED							(0x0u<<19)
#define	USBD_INTENSET_ENDEPOUT7_ENABLED								(0x1u<<19)
#define	USBD_INTENSET_ENDEPOUT7_SET									(0x1u<<19)
#define	USBD_INTENSET_ENDEPOUT6_DISABLED							(0x0u<<18)
#define	USBD_INTENSET_ENDEPOUT6_ENABLED								(0x1u<<18)
#define	USBD_INTENSET_ENDEPOUT6_SET									(0x1u<<18)
#define	USBD_INTENSET_ENDEPOUT5_DISABLED							(0x0u<<17)
#define	USBD_INTENSET_ENDEPOUT5_ENABLED								(0x1u<<17)
#define	USBD_INTENSET_ENDEPOUT5_SET									(0x1u<<17)
#define	USBD_INTENSET_ENDEPOUT4_DISABLED							(0x0u<<16)
#define	USBD_INTENSET_ENDEPOUT4_ENABLED								(0x1u<<16)
#define	USBD_INTENSET_ENDEPOUT4_SET									(0x1u<<16)
#define	USBD_INTENSET_ENDEPOUT3_DISABLED							(0x0u<<15)
#define	USBD_INTENSET_ENDEPOUT3_ENABLED								(0x1u<<15)
#define	USBD_INTENSET_ENDEPOUT3_SET									(0x1u<<15)
#define	USBD_INTENSET_ENDEPOUT2_DISABLED							(0x0u<<14)
#define	USBD_INTENSET_ENDEPOUT2_ENABLED								(0x1u<<14)
#define	USBD_INTENSET_ENDEPOUT2_SET									(0x1u<<14)
#define	USBD_INTENSET_ENDEPOUT1_DISABLED							(0x0u<<13)
#define	USBD_INTENSET_ENDEPOUT1_ENABLED								(0x1u<<13)
#define	USBD_INTENSET_ENDEPOUT1_SET									(0x1u<<13)
#define	USBD_INTENSET_ENDEPOUT0_DISABLED							(0x0u<<12)
#define	USBD_INTENSET_ENDEPOUT0_ENABLED								(0x1u<<12)
#define	USBD_INTENSET_ENDEPOUT0_SET									(0x1u<<12)
#define	USBD_INTENSET_ENDISOIN_DISABLED								(0x0u<<11)
#define	USBD_INTENSET_ENDISOIN_ENABLED								(0x1u<<11)
#define	USBD_INTENSET_ENDISOIN_SET									(0x1u<<11)
#define	USBD_INTENSET_EP0DATADONE_DISABLED							(0x0u<<10)
#define	USBD_INTENSET_EP0DATADONE_ENABLED							(0x1u<<10)
#define	USBD_INTENSET_EP0DATADONE_SET								(0x1u<<10)
#define	USBD_INTENSET_ENDEPIN7_DISABLED								(0x0u<<9)
#define	USBD_INTENSET_ENDEPIN7_ENABLED								(0x1u<<9)
#define	USBD_INTENSET_ENDEPIN7_SET									(0x1u<<9)
#define	USBD_INTENSET_ENDEPIN6_DISABLED								(0x0u<<8)
#define	USBD_INTENSET_ENDEPIN6_ENABLED								(0x1u<<8)
#define	USBD_INTENSET_ENDEPIN6_SET									(0x1u<<8)
#define	USBD_INTENSET_ENDEPIN5_DISABLED								(0x0u<<7)
#define	USBD_INTENSET_ENDEPIN5_ENABLED								(0x1u<<7)
#define	USBD_INTENSET_ENDEPIN5_SET									(0x1u<<7)
#define	USBD_INTENSET_ENDEPIN4_DISABLED								(0x0u<<6)
#define	USBD_INTENSET_ENDEPIN4_ENABLED								(0x1u<<6)
#define	USBD_INTENSET_ENDEPIN4_SET									(0x1u<<6)
#define	USBD_INTENSET_ENDEPIN3_DISABLED								(0x0u<<5)
#define	USBD_INTENSET_ENDEPIN3_ENABLED								(0x1u<<5)
#define	USBD_INTENSET_ENDEPIN3_SET									(0x1u<<5)
#define	USBD_INTENSET_ENDEPIN2_DISABLED								(0x0u<<4)
#define	USBD_INTENSET_ENDEPIN2_ENABLED								(0x1u<<4)
#define	USBD_INTENSET_ENDEPIN2_SET									(0x1u<<4)
#define	USBD_INTENSET_ENDEPIN1_DISABLED								(0x0u<<3)
#define	USBD_INTENSET_ENDEPIN1_ENABLED								(0x1u<<3)
#define	USBD_INTENSET_ENDEPIN1_SET									(0x1u<<3)
#define	USBD_INTENSET_ENDEPIN0_DISABLED								(0x0u<<2)
#define	USBD_INTENSET_ENDEPIN0_ENABLED								(0x1u<<2)
#define	USBD_INTENSET_ENDEPIN0_SET									(0x1u<<2)
#define	USBD_INTENSET_STARTED_DISABLED								(0x0u<<1)
#define	USBD_INTENSET_STARTED_ENABLED								(0x1u<<1)
#define	USBD_INTENSET_STARTED_SET									(0x1u<<1)
#define	USBD_INTENSET_USBRESET_DISABLED								(0x0u<<0)
#define	USBD_INTENSET_USBRESET_ENABLED								(0x1u<<0)
#define	USBD_INTENSET_USBRESET_SET									(0x1u<<0)

// INTENCLR Configuration

#define	USBD_INTENCLR_EPDATA										(0x1u<<24)
#define	USBD_INTENCLR_EP0SETUP										(0x1u<<23)
#define	USBD_INTENCLR_USBEVENT										(0x1u<<22)
#define	USBD_INTENCLR_SOF											(0x1u<<21)
#define	USBD_INTENCLR_ENDISOOUT										(0x1u<<20)
#define	USBD_INTENCLR_ENDEPOUT7										(0x1u<<19)
#define	USBD_INTENCLR_ENDEPOUT6										(0x1u<<18)
#define	USBD_INTENCLR_ENDEPOUT5										(0x1u<<17)
#define	USBD_INTENCLR_ENDEPOUT4										(0x1u<<16)
#define	USBD_INTENCLR_ENDEPOUT3										(0x1u<<15)
#define	USBD_INTENCLR_ENDEPOUT2										(0x1u<<14)
#define	USBD_INTENCLR_ENDEPOUT1										(0x1u<<13)
#define	USBD_INTENCLR_ENDEPOUT0										(0x1u<<12)
#define	USBD_INTENCLR_ENDISOIN										(0x1u<<11)
#define	USBD_INTENCLR_EP0DATADONE									(0x1u<<10)
#define	USBD_INTENCLR_ENDEPIN7										(0x1u<<9)
#define	USBD_INTENCLR_ENDEPIN6										(0x1u<<8)
#define	USBD_INTENCLR_ENDEPIN5										(0x1u<<7)
#define	USBD_INTENCLR_ENDEPIN4										(0x1u<<6)
#define	USBD_INTENCLR_ENDEPIN3										(0x1u<<5)
#define	USBD_INTENCLR_ENDEPIN2										(0x1u<<4)
#define	USBD_INTENCLR_ENDEPIN1										(0x1u<<3)
#define	USBD_INTENCLR_ENDEPIN0										(0x1u<<2)
#define	USBD_INTENCLR_STARTED										(0x1u<<1)
#define	USBD_INTENCLR_USBRESET										(0x1u<<0)
#define	USBD_INTENCLR_EPDATA_DISABLED								(0x0u<<24)
#define	USBD_INTENCLR_EPDATA_ENABLED								(0x1u<<24)
#define	USBD_INTENCLR_EPDATA_CLEAR									(0x1u<<24)
#define	USBD_INTENCLR_EP0SETUP_DISABLED								(0x0u<<23)
#define	USBD_INTENCLR_EP0SETUP_ENABLED								(0x1u<<23)
#define	USBD_INTENCLR_EP0SETUP_CLEAR								(0x1u<<23)
#define	USBD_INTENCLR_USBEVENT_DISABLED								(0x0u<<22)
#define	USBD_INTENCLR_USBEVENT_ENABLED								(0x1u<<22)
#define	USBD_INTENCLR_USBEVENT_CLEAR								(0x1u<<22)
#define	USBD_INTENCLR_SOF_DISABLED									(0x0u<<21)
#define	USBD_INTENCLR_SOF_ENABLED									(0x1u<<21)
#define	USBD_INTENCLR_SOF_CLEAR										(0x1u<<21)
#define	USBD_INTENCLR_ENDISOOUT_DISABLED							(0x0u<<20)
#define	USBD_INTENCLR_ENDISOOUT_ENABLED								(0x1u<<20)
#define	USBD_INTENCLR_ENDISOOUT_CLEAR								(0x1u<<20)
#define	USBD_INTENCLR_ENDEPOUT7_DISABLED							(0x0u<<19)
#define	USBD_INTENCLR_ENDEPOUT7_ENABLED								(0x1u<<19)
#define	USBD_INTENCLR_ENDEPOUT7_CLEAR								(0x1u<<19)
#define	USBD_INTENCLR_ENDEPOUT6_DISABLED							(0x0u<<18)
#define	USBD_INTENCLR_ENDEPOUT6_ENABLED								(0x1u<<18)
#define	USBD_INTENCLR_ENDEPOUT6_CLEAR								(0x1u<<18)
#define	USBD_INTENCLR_ENDEPOUT5_DISABLED							(0x0u<<17)
#define	USBD_INTENCLR_ENDEPOUT5_ENABLED								(0x1u<<17)
#define	USBD_INTENCLR_ENDEPOUT5_CLEAR								(0x1u<<17)
#define	USBD_INTENCLR_ENDEPOUT4_DISABLED							(0x0u<<16)
#define	USBD_INTENCLR_ENDEPOUT4_ENABLED								(0x1u<<16)
#define	USBD_INTENCLR_ENDEPOUT4_CLEAR								(0x1u<<16)
#define	USBD_INTENCLR_ENDEPOUT3_DISABLED							(0x0u<<15)
#define	USBD_INTENCLR_ENDEPOUT3_ENABLED								(0x1u<<15)
#define	USBD_INTENCLR_ENDEPOUT3_CLEAR								(0x1u<<15)
#define	USBD_INTENCLR_ENDEPOUT2_DISABLED							(0x0u<<14)
#define	USBD_INTENCLR_ENDEPOUT2_ENABLED								(0x1u<<14)
#define	USBD_INTENCLR_ENDEPOUT2_CLEAR								(0x1u<<14)
#define	USBD_INTENCLR_ENDEPOUT1_DISABLED							(0x0u<<13)
#define	USBD_INTENCLR_ENDEPOUT1_ENABLED								(0x1u<<13)
#define	USBD_INTENCLR_ENDEPOUT1_CLEAR								(0x1u<<13)
#define	USBD_INTENCLR_ENDEPOUT0_DISABLED							(0x0u<<12)
#define	USBD_INTENCLR_ENDEPOUT0_ENABLED								(0x1u<<12)
#define	USBD_INTENCLR_ENDEPOUT0_CLEAR								(0x1u<<12)
#define	USBD_INTENCLR_ENDISOIN_DISABLED								(0x0u<<11)
#define	USBD_INTENCLR_ENDISOIN_ENABLED								(0x1u<<11)
#define	USBD_INTENCLR_ENDISOIN_CLEAR								(0x1u<<11)
#define	USBD_INTENCLR_EP0DATADONE_DISABLED							(0x0u<<10)
#define	USBD_INTENCLR_EP0DATADONE_ENABLED							(0x1u<<10)
#define	USBD_INTENCLR_EP0DATADONE_CLEAR								(0x1u<<10)
#define	USBD_INTENCLR_ENDEPIN7_DISABLED								(0x0u<<9)
#define	USBD_INTENCLR_ENDEPIN7_ENABLED								(0x1u<<9)
#define	USBD_INTENCLR_ENDEPIN7_CLEAR								(0x1u<<9)
#define	USBD_INTENCLR_ENDEPIN6_DISABLED								(0x0u<<8)
#define	USBD_INTENCLR_ENDEPIN6_ENABLED								(0x1u<<8)
#define	USBD_INTENCLR_ENDEPIN6_CLEAR								(0x1u<<8)
#define	USBD_INTENCLR_ENDEPIN5_DISABLED								(0x0u<<7)
#define	USBD_INTENCLR_ENDEPIN5_ENABLED								(0x1u<<7)
#define	USBD_INTENCLR_ENDEPIN5_CLEAR								(0x1u<<7)
#define	USBD_INTENCLR_ENDEPIN4_DISABLED								(0x0u<<6)
#define	USBD_INTENCLR_ENDEPIN4_ENABLED								(0x1u<<6)
#define	USBD_INTENCLR_ENDEPIN4_CLEAR								(0x1u<<6)
#define	USBD_INTENCLR_ENDEPIN3_DISABLED								(0x0u<<5)
#define	USBD_INTENCLR_ENDEPIN3_ENABLED								(0x1u<<5)
#define	USBD_INTENCLR_ENDEPIN3_CLEAR								(0x1u<<5)
#define	USBD_INTENCLR_ENDEPIN2_DISABLED								(0x0u<<4)
#define	USBD_INTENCLR_ENDEPIN2_ENABLED								(0x1u<<4)
#define	USBD_INTENCLR_ENDEPIN2_CLEAR								(0x1u<<4)
#define	USBD_INTENCLR_ENDEPIN1_DISABLED								(0x0u<<3)
#define	USBD_INTENCLR_ENDEPIN1_ENABLED								(0x1u<<3)
#define	USBD_INTENCLR_ENDEPIN1_CLEAR								(0x1u<<3)
#define	USBD_INTENCLR_ENDEPIN0_DISABLED								(0x0u<<2)
#define	USBD_INTENCLR_ENDEPIN0_ENABLED								(0x1u<<2)
#define	USBD_INTENCLR_ENDEPIN0_CLEAR								(0x1u<<2)
#define	USBD_INTENCLR_STARTED_DISABLED								(0x0u<<1)
#define	USBD_INTENCLR_STARTED_ENABLED								(0x1u<<1)
#define	USBD_INTENCLR_STARTED_CLEAR									(0x1u<<1)
#define	USBD_INTENCLR_USBRESET_DISABLED								(0x0u<<0)
#define	USBD_INTENCLR_USBRESET_ENABLED								(0x1u<<0)
#define	USBD_INTENCLR_USBRESET_CLEAR								(0x1u<<0)

// EVENTCAUSE Configuration

#define	USBD_EVENTCAUSE_READY										(0x1u<<11)
#define	USBD_EVENTCAUSE_USBWUALLOWED								(0x1u<<10)
#define	USBD_EVENTCAUSE_RESUME										(0x1u<<9)
#define	USBD_EVENTCAUSE_SUSPEND										(0x1u<<8)
#define	USBD_EVENTCAUSE_ISOOUTCRC									(0x1u<<0)
#define	USBD_EVENTCAUSE_READY_NOTDETECTED							(0x0u<<11)
#define	USBD_EVENTCAUSE_READY_READY									(0x1u<<11)
#define	USBD_EVENTCAUSE_USBWUALLOWED_NOTALLOWED						(0x0u<<10)
#define	USBD_EVENTCAUSE_USBWUALLOWED_ALLOWED						(0x1u<<10)
#define	USBD_EVENTCAUSE_RESUME_NOTDETECTED							(0x0u<<9)
#define	USBD_EVENTCAUSE_RESUME_DETECTED								(0x1u<<9)
#define	USBD_EVENTCAUSE_SUSPEND_NOTDETECTED							(0x0u<<8)
#define	USBD_EVENTCAUSE_SUSPEND_DETECTED							(0x1u<<8)
#define	USBD_EVENTCAUSE_ISOOUTCRC_NOTDETECTED						(0x0u<<0)
#define	USBD_EVENTCAUSE_ISOOUTCRC_DETECTED							(0x1u<<0)

// EPIN Configuration

#define	USBD_HALTED_EPIN_GETSTATUS									(0xFFFFu<<0)
#define	USBD_HALTED_EPIN_GETSTATUS_0								(0x1u<<0)
#define	USBD_HALTED_EPIN_GETSTATUS_NOTHALTED						(0x0u<<0)
#define	USBD_HALTED_EPIN_GETSTATUS_HALTED							(0x1u<<0)

// EPOUT Configuration

#define	USBD_HALTED_EPOUT_GETSTATUS									(0xFFFFu<<0)
#define	USBD_HALTED_EPOUT_GETSTATUS_0								(0x1u<<0)
#define	USBD_HALTED_EPOUT_GETSTATUS_NOTHALTED						(0x0u<<0)
#define	USBD_HALTED_EPOUT_GETSTATUS_HALTED							(0x1u<<0)

// EPSTATUS Configuration

#define	USBD_EPSTATUS_EPOUT8										(0x1u<<24)
#define	USBD_EPSTATUS_EPOUT7										(0x1u<<23)
#define	USBD_EPSTATUS_EPOUT6										(0x1u<<22)
#define	USBD_EPSTATUS_EPOUT5										(0x1u<<21)
#define	USBD_EPSTATUS_EPOUT4										(0x1u<<20)
#define	USBD_EPSTATUS_EPOUT3										(0x1u<<19)
#define	USBD_EPSTATUS_EPOUT2										(0x1u<<18)
#define	USBD_EPSTATUS_EPOUT1										(0x1u<<17)
#define	USBD_EPSTATUS_EPOUT0										(0x1u<<16)
#define	USBD_EPSTATUS_EPIN8											(0x1u<<8)
#define	USBD_EPSTATUS_EPIN7											(0x1u<<7)
#define	USBD_EPSTATUS_EPIN6											(0x1u<<6)
#define	USBD_EPSTATUS_EPIN5											(0x1u<<5)
#define	USBD_EPSTATUS_EPIN4											(0x1u<<4)
#define	USBD_EPSTATUS_EPIN3											(0x1u<<3)
#define	USBD_EPSTATUS_EPIN2											(0x1u<<2)
#define	USBD_EPSTATUS_EPIN1											(0x1u<<1)
#define	USBD_EPSTATUS_EPIN0											(0x1u<<0)
#define	USBD_EPSTATUS_EPOUT8_NODATA									(0x0u<<24)
#define	USBD_EPSTATUS_EPOUT8_DATADONE								(0x1u<<24)
#define	USBD_EPSTATUS_EPOUT7_NODATA									(0x0u<<23)
#define	USBD_EPSTATUS_EPOUT7_DATADONE								(0x1u<<23)
#define	USBD_EPSTATUS_EPOUT6_NODATA									(0x0u<<22)
#define	USBD_EPSTATUS_EPOUT6_DATADONE								(0x1u<<22)
#define	USBD_EPSTATUS_EPOUT5_NODATA									(0x0u<<21)
#define	USBD_EPSTATUS_EPOUT5_DATADONE								(0x1u<<21)
#define	USBD_EPSTATUS_EPOUT4_NODATA									(0x0u<<20)
#define	USBD_EPSTATUS_EPOUT4_DATADONE								(0x1u<<20)
#define	USBD_EPSTATUS_EPOUT3_NODATA									(0x0u<<19)
#define	USBD_EPSTATUS_EPOUT3_DATADONE								(0x1u<<19)
#define	USBD_EPSTATUS_EPOUT2_NODATA									(0x0u<<18)
#define	USBD_EPSTATUS_EPOUT2_DATADONE								(0x1u<<18)
#define	USBD_EPSTATUS_EPOUT1_NODATA									(0x0u<<17)
#define	USBD_EPSTATUS_EPOUT1_DATADONE								(0x1u<<17)
#define	USBD_EPSTATUS_EPOUT0_NODATA									(0x0u<<16)
#define	USBD_EPSTATUS_EPOUT0_DATADONE								(0x1u<<16)
#define	USBD_EPSTATUS_EPIN8_NODATA									(0x0u<<8)
#define	USBD_EPSTATUS_EPIN8_DATADONE								(0x1u<<8)
#define	USBD_EPSTATUS_EPIN7_NODATA									(0x0u<<7)
#define	USBD_EPSTATUS_EPIN7_DATADONE								(0x1u<<7)
#define	USBD_EPSTATUS_EPIN6_NODATA									(0x0u<<6)
#define	USBD_EPSTATUS_EPIN6_DATADONE								(0x1u<<6)
#define	USBD_EPSTATUS_EPIN5_NODATA									(0x0u<<5)
#define	USBD_EPSTATUS_EPIN5_DATADONE								(0x1u<<5)
#define	USBD_EPSTATUS_EPIN4_NODATA									(0x0u<<4)
#define	USBD_EPSTATUS_EPIN4_DATADONE								(0x1u<<4)
#define	USBD_EPSTATUS_EPIN3_NODATA									(0x0u<<3)
#define	USBD_EPSTATUS_EPIN3_DATADONE								(0x1u<<3)
#define	USBD_EPSTATUS_EPIN2_NODATA									(0x0u<<2)
#define	USBD_EPSTATUS_EPIN2_DATADONE								(0x1u<<2)
#define	USBD_EPSTATUS_EPIN1_NODATA									(0x0u<<1)
#define	USBD_EPSTATUS_EPIN1_DATADONE								(0x1u<<1)
#define	USBD_EPSTATUS_EPIN0_NODATA									(0x0u<<0)
#define	USBD_EPSTATUS_EPIN0_DATADONE								(0x1u<<0)

// EPDATASTATUS Configuration

#define	USBD_EPDATASTATUS_EPOUT7									(0x1u<<23)
#define	USBD_EPDATASTATUS_EPOUT6									(0x1u<<22)
#define	USBD_EPDATASTATUS_EPOUT5									(0x1u<<21)
#define	USBD_EPDATASTATUS_EPOUT4									(0x1u<<20)
#define	USBD_EPDATASTATUS_EPOUT3									(0x1u<<19)
#define	USBD_EPDATASTATUS_EPOUT2									(0x1u<<18)
#define	USBD_EPDATASTATUS_EPOUT1									(0x1u<<17)
#define	USBD_EPDATASTATUS_EPIN7										(0x1u<<7)
#define	USBD_EPDATASTATUS_EPIN6										(0x1u<<6)
#define	USBD_EPDATASTATUS_EPIN5										(0x1u<<5)
#define	USBD_EPDATASTATUS_EPIN4										(0x1u<<4)
#define	USBD_EPDATASTATUS_EPIN3										(0x1u<<3)
#define	USBD_EPDATASTATUS_EPIN2										(0x1u<<2)
#define	USBD_EPDATASTATUS_EPIN1										(0x1u<<1)
#define	USBD_EPDATASTATUS_EPOUT7_NOTSTARTED							(0x0u<<23)
#define	USBD_EPDATASTATUS_EPOUT7_STARTED							(0x1u<<23)
#define	USBD_EPDATASTATUS_EPOUT6_NOTSTARTED							(0x0u<<22)
#define	USBD_EPDATASTATUS_EPOUT6_STARTED							(0x1u<<22)
#define	USBD_EPDATASTATUS_EPOUT5_NOTSTARTED							(0x0u<<21)
#define	USBD_EPDATASTATUS_EPOUT5_STARTED							(0x1u<<21)
#define	USBD_EPDATASTATUS_EPOUT4_NOTSTARTED							(0x0u<<20)
#define	USBD_EPDATASTATUS_EPOUT4_STARTED							(0x1u<<20)
#define	USBD_EPDATASTATUS_EPOUT3_NOTSTARTED							(0x0u<<19)
#define	USBD_EPDATASTATUS_EPOUT3_STARTED							(0x1u<<19)
#define	USBD_EPDATASTATUS_EPOUT2_NOTSTARTED							(0x0u<<18)
#define	USBD_EPDATASTATUS_EPOUT2_STARTED							(0x1u<<18)
#define	USBD_EPDATASTATUS_EPOUT1_NOTSTARTED							(0x0u<<17)
#define	USBD_EPDATASTATUS_EPOUT1_STARTED							(0x1u<<17)
#define	USBD_EPDATASTATUS_EPIN7_NOTDONE								(0x0u<<7)
#define	USBD_EPDATASTATUS_EPIN7_DATADONE							(0x1u<<7)
#define	USBD_EPDATASTATUS_EPIN6_NOTDONE								(0x0u<<6)
#define	USBD_EPDATASTATUS_EPIN6_DATADONE							(0x1u<<6)
#define	USBD_EPDATASTATUS_EPIN5_NOTDONE								(0x0u<<5)
#define	USBD_EPDATASTATUS_EPIN5_DATADONE							(0x1u<<5)
#define	USBD_EPDATASTATUS_EPIN4_NOTDONE								(0x0u<<4)
#define	USBD_EPDATASTATUS_EPIN4_DATADONE							(0x1u<<4)
#define	USBD_EPDATASTATUS_EPIN3_NOTDONE								(0x0u<<3)
#define	USBD_EPDATASTATUS_EPIN3_DATADONE							(0x1u<<3)
#define	USBD_EPDATASTATUS_EPIN2_NOTDONE								(0x0u<<2)
#define	USBD_EPDATASTATUS_EPIN2_DATADONE							(0x1u<<2)
#define	USBD_EPDATASTATUS_EPIN1_NOTDONE								(0x0u<<1)
#define	USBD_EPDATASTATUS_EPIN1_DATADONE							(0x1u<<1)

// USBADDR Configuration

#define	USBD_USBADDR_ADDR											(0x7Fu<<0)
#define	USBD_USBADDR_ADDR_0											(0x1u<<0)

// BMREQUESTTYPE Configuration

#define	USBD_BMREQUESTTYPE_DIRECTION								(0x1u<<7)
#define	USBD_BMREQUESTTYPE_TYPE										(0x3u<<5)
#define	USBD_BMREQUESTTYPE_TYPE_0									(0x1u<<5)
#define	USBD_BMREQUESTTYPE_RECIPIENT								(0x1Fu<<0)
#define	USBD_BMREQUESTTYPE_RECIPIENT_0								(0x1u<<0)
#define	USBD_BMREQUESTTYPE_DIRECTION_HOSTTODEVICE					(0x0u<<7)
#define	USBD_BMREQUESTTYPE_DIRECTION_DEVICETOHOST					(0x1u<<7)
#define	USBD_BMREQUESTTYPE_TYPE_STANDARD							(0x0u<<5)
#define	USBD_BMREQUESTTYPE_TYPE_CLASS								(0x1u<<5)
#define	USBD_BMREQUESTTYPE_TYPE_VENDOR								(0x2u<<5)
#define	USBD_BMREQUESTTYPE_RECIPIENT_DEVICE							(0x0u<<0)
#define	USBD_BMREQUESTTYPE_RECIPIENT_INTERFACE						(0x1u<<0)
#define	USBD_BMREQUESTTYPE_RECIPIENT_ENDPOINT						(0x2u<<0)
#define	USBD_BMREQUESTTYPE_RECIPIENT_OTHER							(0x3u<<0)

// BREQUEST Configuration

#define	USBD_BREQUEST_BREQUEST										(0xFFu<<0)
#define	USBD_BREQUEST_BREQUEST_0									(0x1u<<0)
#define	USBD_BREQUEST_BREQUEST_STD_GET_STATUS						(0x0u<<0)
#define	USBD_BREQUEST_BREQUEST_STD_CLEAR_FEATURE					(0x1u<<0)
#define	USBD_BREQUEST_BREQUEST_STD_SET_FEATURE						(0x3u<<0)
#define	USBD_BREQUEST_BREQUEST_STD_SET_ADDRESS						(0x5u<<0)
#define	USBD_BREQUEST_BREQUEST_STD_GET_DESCRIPTOR					(0x6u<<0)
#define	USBD_BREQUEST_BREQUEST_STD_SET_DESCRIPTOR					(0x7u<<0)
#define	USBD_BREQUEST_BREQUEST_STD_GET_CONFIGURATION				(0x8u<<0)
#define	USBD_BREQUEST_BREQUEST_STD_SET_CONFIGURATION				(0x9u<<0)
#define	USBD_BREQUEST_BREQUEST_STD_GET_INTERFACE					(0xAu<<0)
#define	USBD_BREQUEST_BREQUEST_STD_SET_INTERFACE					(0xBu<<0)
#define	USBD_BREQUEST_BREQUEST_STD_SYNCH_FRAME						(0xCu<<0)

// WVALUEL Configuration

#define	USBD_WVALUEL_WVALUEL										(0xFFu<<0)
#define	USBD_WVALUEL_WVALUEL_0										(0x1u<<0)

// WVALUEH Configuration

#define	USBD_WVALUEH_WVALUEH										(0xFFu<<0)
#define	USBD_WVALUEH_WVALUEH_0										(0x1u<<0)

// WINDEXL Configuration

#define	USBD_WINDEXL_WINDEXL										(0xFFu<<0)
#define	USBD_WINDEXL_WINDEXL_0										(0x1u<<0)

// WINDEXH Configuration

#define	USBD_WINDEXH_WINDEXH										(0xFFu<<0)
#define	USBD_WINDEXH_WINDEXH_0										(0x1u<<0)

// WLENGTHL Configuration

#define	USBD_WLENGTHL_WLENGTHL										(0xFFu<<0)
#define	USBD_WLENGTHL_WLENGTHL_0									(0x1u<<0)

// WLENGTHH Configuration

#define	USBD_WLENGTHH_WLENGTHH										(0xFFu<<0)
#define	USBD_WLENGTHH_WLENGTHH_0									(0x1u<<0)

// EPOUT Configuration

#define	USBD_SIZE_EPOUT_SIZE										(0x7Fu<<0)
#define	USBD_SIZE_EPOUT_SIZE_0										(0x1u<<0)

// ISOOUT Configuration

#define	USBD_SIZE_ISOOUT_ZERO										(0x1u<<16)
#define	USBD_SIZE_ISOOUT_SIZE										(0x3FFu<<0)
#define	USBD_SIZE_ISOOUT_SIZE_0										(0x1u<<0)
#define	USBD_SIZE_ISOOUT_ZERO_NORMAL								(0x0u<<16)
#define	USBD_SIZE_ISOOUT_ZERO_ZERODATA								(0x1u<<16)

// ENABLE Configuration

#define	USBD_ENABLE_ENABLE											(0x1u<<0)
#define	USBD_ENABLE_ENABLE_DISABLED									(0x0u<<0)
#define	USBD_ENABLE_ENABLE_ENABLED									(0x1u<<0)

// USBPULLUP Configuration

#define	USBD_USBPULLUP_CONNECT										(0x1u<<0)
#define	USBD_USBPULLUP_CONNECT_DISABLED								(0x0u<<0)
#define	USBD_USBPULLUP_CONNECT_ENABLED								(0x1u<<0)

// DPDMVALUE Configuration

#define	USBD_DPDMVALUE_STATE										(0x1Fu<<0)
#define	USBD_DPDMVALUE_STATE_0										(0x1u<<0)
#define	USBD_DPDMVALUE_STATE_RESUME									(0x1u<<0)
#define	USBD_DPDMVALUE_STATE_J										(0x2u<<0)
#define	USBD_DPDMVALUE_STATE_K										(0x4u<<0)

// DTOGGLE Configuration

#define	USBD_DTOGGLE_VALUE											(0x3u<<8)
#define	USBD_DTOGGLE_VALUE_0										(0x1u<<8)
#define	USBD_DTOGGLE_IO												(0x1u<<7)
#define	USBD_DTOGGLE_EP												(0x7u<<0)
#define	USBD_DTOGGLE_EP_0											(0x1u<<0)
#define	USBD_DTOGGLE_VALUE_NOP										(0x0u<<8)
#define	USBD_DTOGGLE_VALUE_DATA0									(0x1u<<8)
#define	USBD_DTOGGLE_VALUE_DATA1									(0x2u<<8)
#define	USBD_DTOGGLE_IO_OUT											(0x0u<<7)
#define	USBD_DTOGGLE_IO_IN											(0x1u<<7)

// EPINEN Configuration

#define	USBD_EPINEN_ISOIN											(0x1u<<8)
#define	USBD_EPINEN_IN7												(0x1u<<7)
#define	USBD_EPINEN_IN6												(0x1u<<6)
#define	USBD_EPINEN_IN5												(0x1u<<5)
#define	USBD_EPINEN_IN4												(0x1u<<4)
#define	USBD_EPINEN_IN3												(0x1u<<3)
#define	USBD_EPINEN_IN2												(0x1u<<2)
#define	USBD_EPINEN_IN1												(0x1u<<1)
#define	USBD_EPINEN_IN0												(0x1u<<0)
#define	USBD_EPINEN_ISOIN_DISABLE									(0x0u<<8)
#define	USBD_EPINEN_ISOIN_ENABLE									(0x1u<<8)
#define	USBD_EPINEN_IN7_DISABLE										(0x0u<<7)
#define	USBD_EPINEN_IN7_ENABLE										(0x1u<<7)
#define	USBD_EPINEN_IN6_DISABLE										(0x0u<<6)
#define	USBD_EPINEN_IN6_ENABLE										(0x1u<<6)
#define	USBD_EPINEN_IN5_DISABLE										(0x0u<<5)
#define	USBD_EPINEN_IN5_ENABLE										(0x1u<<5)
#define	USBD_EPINEN_IN4_DISABLE										(0x0u<<4)
#define	USBD_EPINEN_IN4_ENABLE										(0x1u<<4)
#define	USBD_EPINEN_IN3_DISABLE										(0x0u<<3)
#define	USBD_EPINEN_IN3_ENABLE										(0x1u<<3)
#define	USBD_EPINEN_IN2_DISABLE										(0x0u<<2)
#define	USBD_EPINEN_IN2_ENABLE										(0x1u<<2)
#define	USBD_EPINEN_IN1_DISABLE										(0x0u<<1)
#define	USBD_EPINEN_IN1_ENABLE										(0x1u<<1)
#define	USBD_EPINEN_IN0_DISABLE										(0x0u<<0)
#define	USBD_EPINEN_IN0_ENABLE										(0x1u<<0)

// EPOUTEN Configuration

#define	USBD_EPOUTEN_ISOOUT											(0x1u<<8)
#define	USBD_EPOUTEN_OUT7											(0x1u<<7)
#define	USBD_EPOUTEN_OUT6											(0x1u<<6)
#define	USBD_EPOUTEN_OUT5											(0x1u<<5)
#define	USBD_EPOUTEN_OUT4											(0x1u<<4)
#define	USBD_EPOUTEN_OUT3											(0x1u<<3)
#define	USBD_EPOUTEN_OUT2											(0x1u<<2)
#define	USBD_EPOUTEN_OUT1											(0x1u<<1)
#define	USBD_EPOUTEN_OUT0											(0x1u<<0)
#define	USBD_EPOUTEN_ISOOUT_DISABLE									(0x0u<<8)
#define	USBD_EPOUTEN_ISOOUT_ENABLE									(0x1u<<8)
#define	USBD_EPOUTEN_OUT7_DISABLE									(0x0u<<7)
#define	USBD_EPOUTEN_OUT7_ENABLE									(0x1u<<7)
#define	USBD_EPOUTEN_OUT6_DISABLE									(0x0u<<6)
#define	USBD_EPOUTEN_OUT6_ENABLE									(0x1u<<6)
#define	USBD_EPOUTEN_OUT5_DISABLE									(0x0u<<5)
#define	USBD_EPOUTEN_OUT5_ENABLE									(0x1u<<5)
#define	USBD_EPOUTEN_OUT4_DISABLE									(0x0u<<4)
#define	USBD_EPOUTEN_OUT4_ENABLE									(0x1u<<4)
#define	USBD_EPOUTEN_OUT3_DISABLE									(0x0u<<3)
#define	USBD_EPOUTEN_OUT3_ENABLE									(0x1u<<3)
#define	USBD_EPOUTEN_OUT2_DISABLE									(0x0u<<2)
#define	USBD_EPOUTEN_OUT2_ENABLE									(0x1u<<2)
#define	USBD_EPOUTEN_OUT1_DISABLE									(0x0u<<1)
#define	USBD_EPOUTEN_OUT1_ENABLE									(0x1u<<1)
#define	USBD_EPOUTEN_OUT0_DISABLE									(0x0u<<0)
#define	USBD_EPOUTEN_OUT0_ENABLE									(0x1u<<0)

// EPSTALL Configuration

#define	USBD_EPSTALL_STALL											(0x1u<<8)
#define	USBD_EPSTALL_IO												(0x1u<<7)
#define	USBD_EPSTALL_EP												(0x7u<<0)
#define	USBD_EPSTALL_EP_0											(0x1u<<0)
#define	USBD_EPSTALL_STALL_UNSTALL									(0x0u<<8)
#define	USBD_EPSTALL_STALL_STALL									(0x1u<<8)
#define	USBD_EPSTALL_IO_OUT											(0x0u<<7)
#define	USBD_EPSTALL_IO_IN											(0x1u<<7)

// ISOSPLIT Configuration

#define	USBD_ISOSPLIT_SPLIT											(0xFFFFu<<0)
#define	USBD_ISOSPLIT_SPLIT_0										(0x1u<<0)
#define	USBD_ISOSPLIT_SPLIT_ONEDIR									(0x0u<<0)
#define	USBD_ISOSPLIT_SPLIT_HALFIN									(0x80u<<0)

// FRAMECNTR Configuration

#define	USBD_FRAMECNTR_FRAMECNTR									(0x7FFu<<0)
#define	USBD_FRAMECNTR_FRAMECNTR_0									(0x1u<<0)

// LOWPOWER Configuration

#define	USBD_LOWPOWER_LOWPOWER										(0x1u<<0)
#define	USBD_LOWPOWER_LOWPOWER_FORCENORMAL							(0x0u<<0)
#define	USBD_LOWPOWER_LOWPOWER_LOWPOWER								(0x1u<<0)

// ISOINCONFIG Configuration

#define	USBD_ISOINCONFIG_RESPONSE									(0x1u<<0)
#define	USBD_ISOINCONFIG_RESPONSE_NORESP							(0x0u<<0)
#define	USBD_ISOINCONFIG_RESPONSE_ZERODATA							(0x1u<<0)

// PTR Configuration

#define	USBD_EPIN_PTR_PTR											(0xFFFFFFFFu<<0)
#define	USBD_EPIN_PTR_PTR_0											(0x1u<<0)

// MAXCNT Configuration

#define	USBD_EPIN_MAXCNT_MAXCNT										(0x7Fu<<0)
#define	USBD_EPIN_MAXCNT_MAXCNT_0									(0x1u<<0)

// AMOUNT Configuration

#define	USBD_EPIN_AMOUNT_AMOUNT										(0x7Fu<<0)
#define	USBD_EPIN_AMOUNT_AMOUNT_0									(0x1u<<0)

// PTR Configuration

#define	USBD_ISOIN_PTR_PTR											(0xFFFFFFFFu<<0)
#define	USBD_ISOIN_PTR_PTR_0										(0x1u<<0)

// MAXCNT Configuration

#define	USBD_ISOIN_MAXCNT_MAXCNT									(0x3FFu<<0)
#define	USBD_ISOIN_MAXCNT_MAXCNT_0									(0x1u<<0)

// AMOUNT Configuration

#define	USBD_ISOIN_AMOUNT_AMOUNT									(0x3FFu<<0)
#define	USBD_ISOIN_AMOUNT_AMOUNT_0									(0x1u<<0)

// PTR Configuration

#define	USBD_EPOUT_PTR_PTR											(0xFFFFFFFFu<<0)
#define	USBD_EPOUT_PTR_PTR_0										(0x1u<<0)

// MAXCNT Configuration

#define	USBD_EPOUT_MAXCNT_MAXCNT									(0x7Fu<<0)
#define	USBD_EPOUT_MAXCNT_MAXCNT_0									(0x1u<<0)

// AMOUNT Configuration

#define	USBD_EPOUT_AMOUNT_AMOUNT									(0x7Fu<<0)
#define	USBD_EPOUT_AMOUNT_AMOUNT_0									(0x1u<<0)

// PTR Configuration

#define	USBD_ISOOUT_PTR_PTR											(0xFFFFFFFFu<<0)
#define	USBD_ISOOUT_PTR_PTR_0										(0x1u<<0)

// MAXCNT Configuration

#define	USBD_ISOOUT_MAXCNT_MAXCNT									(0x3FFu<<0)
#define	USBD_ISOOUT_MAXCNT_MAXCNT_0									(0x1u<<0)

// AMOUNT Configuration

#define	USBD_ISOOUT_AMOUNT_AMOUNT									(0x3FFu<<0)
#define	USBD_ISOOUT_AMOUNT_AMOUNT_0									(0x1u<<0)
