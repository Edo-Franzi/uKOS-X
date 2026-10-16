/*
; nrf5340_application_saadc.
; ==========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_saadc equates.
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

// SAADC address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	TASKS_START;
	volatile	uint32_t	TASKS_SAMPLE;
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	TASKS_CALIBRATEOFFSET;
	volatile	uint32_t	RESERVED0[28];
	volatile	uint32_t	SUBSCRIBE_START;
	volatile	uint32_t	SUBSCRIBE_SAMPLE;
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	SUBSCRIBE_CALIBRATEOFFSET;
	volatile	uint32_t	RESERVED1[28];
	volatile	uint32_t	EVENTS_STARTED;
	volatile	uint32_t	EVENTS_END;
	volatile	uint32_t	EVENTS_DONE;
	volatile	uint32_t	EVENTS_RESULTDONE;
	volatile	uint32_t	EVENTS_CALIBRATEDONE;
	volatile	uint32_t	EVENTS_STOPPED;
	volatile	uint32_t	EVENTS_CH0_LIMITH;
	volatile	uint32_t	EVENTS_CH0_LIMITL;
	volatile	uint32_t	EVENTS_CH1_LIMITH;
	volatile	uint32_t	EVENTS_CH1_LIMITL;
	volatile	uint32_t	EVENTS_CH2_LIMITH;
	volatile	uint32_t	EVENTS_CH2_LIMITL;
	volatile	uint32_t	EVENTS_CH3_LIMITH;
	volatile	uint32_t	EVENTS_CH3_LIMITL;
	volatile	uint32_t	EVENTS_CH4_LIMITH;
	volatile	uint32_t	EVENTS_CH4_LIMITL;
	volatile	uint32_t	EVENTS_CH5_LIMITH;
	volatile	uint32_t	EVENTS_CH5_LIMITL;
	volatile	uint32_t	EVENTS_CH6_LIMITH;
	volatile	uint32_t	EVENTS_CH6_LIMITL;
	volatile	uint32_t	EVENTS_CH7_LIMITH;
	volatile	uint32_t	EVENTS_CH7_LIMITL;
	volatile	uint32_t	RESERVED2[10];
	volatile	uint32_t	PUBLISH_STARTED;
	volatile	uint32_t	PUBLISH_END;
	volatile	uint32_t	PUBLISH_DONE;
	volatile	uint32_t	PUBLISH_RESULTDONE;
	volatile	uint32_t	PUBLISH_CALIBRATEDONE;
	volatile	uint32_t	PUBLISH_STOPPED;
	volatile	uint32_t	PUBLISH_CH0_LIMITH;
	volatile	uint32_t	PUBLISH_CH0_LIMITL;
	volatile	uint32_t	PUBLISH_CH1_LIMITH;
	volatile	uint32_t	PUBLISH_CH1_LIMITL;
	volatile	uint32_t	PUBLISH_CH2_LIMITH;
	volatile	uint32_t	PUBLISH_CH2_LIMITL;
	volatile	uint32_t	PUBLISH_CH3_LIMITH;
	volatile	uint32_t	PUBLISH_CH3_LIMITL;
	volatile	uint32_t	PUBLISH_CH4_LIMITH;
	volatile	uint32_t	PUBLISH_CH4_LIMITL;
	volatile	uint32_t	PUBLISH_CH5_LIMITH;
	volatile	uint32_t	PUBLISH_CH5_LIMITL;
	volatile	uint32_t	PUBLISH_CH6_LIMITH;
	volatile	uint32_t	PUBLISH_CH6_LIMITL;
	volatile	uint32_t	PUBLISH_CH7_LIMITH;
	volatile	uint32_t	PUBLISH_CH7_LIMITL;
	volatile	uint32_t	RESERVED3[74];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED4[61];
	volatile	uint32_t	STATUS;
	volatile	uint32_t	RESERVED5[63];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	RESERVED6[3];
	volatile	uint32_t	CH0_PSELP;
	volatile	uint32_t	CH0_PSELN;
	volatile	uint32_t	CH0_CONFIG;
	volatile	uint32_t	CH0_LIMIT;
	volatile	uint32_t	CH1_PSELP;
	volatile	uint32_t	CH1_PSELN;
	volatile	uint32_t	CH1_CONFIG;
	volatile	uint32_t	CH1_LIMIT;
	volatile	uint32_t	CH2_PSELP;
	volatile	uint32_t	CH2_PSELN;
	volatile	uint32_t	CH2_CONFIG;
	volatile	uint32_t	CH2_LIMIT;
	volatile	uint32_t	CH3_PSELP;
	volatile	uint32_t	CH3_PSELN;
	volatile	uint32_t	CH3_CONFIG;
	volatile	uint32_t	CH3_LIMIT;
	volatile	uint32_t	CH4_PSELP;
	volatile	uint32_t	CH4_PSELN;
	volatile	uint32_t	CH4_CONFIG;
	volatile	uint32_t	CH4_LIMIT;
	volatile	uint32_t	CH5_PSELP;
	volatile	uint32_t	CH5_PSELN;
	volatile	uint32_t	CH5_CONFIG;
	volatile	uint32_t	CH5_LIMIT;
	volatile	uint32_t	CH6_PSELP;
	volatile	uint32_t	CH6_PSELN;
	volatile	uint32_t	CH6_CONFIG;
	volatile	uint32_t	CH6_LIMIT;
	volatile	uint32_t	CH7_PSELP;
	volatile	uint32_t	CH7_PSELN;
	volatile	uint32_t	CH7_CONFIG;
	volatile	uint32_t	CH7_LIMIT;
	volatile	uint32_t	RESERVED7[24];
	volatile	uint32_t	RESOLUTION;
	volatile	uint32_t	OVERSAMPLE;
	volatile	uint32_t	SAMPLERATE;
	volatile	uint32_t	RESERVED8[12];
	volatile	uint32_t	RESULT_PTR;
	volatile	uint32_t	RESULT_MAXCNT;
	volatile	uint32_t	RESULT_AMOUNT;
} SAADC_TypeDef;

#if (defined(__cplusplus))
#define	SAADC_NS	reinterpret_cast<SAADC_TypeDef *>(0x4000E000u)
#define	SAADC_S		reinterpret_cast<SAADC_TypeDef *>(0x5000E000u)

#else
#define	SAADC_NS	((SAADC_TypeDef *)0x4000E000u)
#define	SAADC_S		((SAADC_TypeDef *)0x5000E000u)
#endif

// TASKS_START Configuration

#define	SAADC_TASKS_START_TASKS_START									(0x1u<<0)
#define	SAADC_TASKS_START_TASKS_START_TRIGGER							(0x1u<<0)

// TASKS_SAMPLE Configuration

#define	SAADC_TASKS_SAMPLE_TASKS_SAMPLE									(0x1u<<0)
#define	SAADC_TASKS_SAMPLE_TASKS_SAMPLE_TRIGGER							(0x1u<<0)

// TASKS_STOP Configuration

#define	SAADC_TASKS_STOP_TASKS_STOP										(0x1u<<0)
#define	SAADC_TASKS_STOP_TASKS_STOP_TRIGGER								(0x1u<<0)

// TASKS_CALIBRATEOFFSET Configuration

#define	SAADC_TASKS_CALIBRATEOFFSET_TASKS_CALIBRATEOFFSET				(0x1u<<0)
#define	SAADC_TASKS_CALIBRATEOFFSET_TASKS_CALIBRATEOFFSET_TRIGGER		(0x1u<<0)

// SUBSCRIBE_START Configuration

#define	SAADC_SUBSCRIBE_START_EN										(0x1u<<31)
#define	SAADC_SUBSCRIBE_START_CHIDX										(0xFFu<<0)
#define	SAADC_SUBSCRIBE_START_CHIDX_0									(0x1u<<0)
#define	SAADC_SUBSCRIBE_START_EN_DISABLED								(0x0u<<31)
#define	SAADC_SUBSCRIBE_START_EN_ENABLED								(0x1u<<31)

// SUBSCRIBE_SAMPLE Configuration

#define	SAADC_SUBSCRIBE_SAMPLE_EN										(0x1u<<31)
#define	SAADC_SUBSCRIBE_SAMPLE_CHIDX									(0xFFu<<0)
#define	SAADC_SUBSCRIBE_SAMPLE_CHIDX_0									(0x1u<<0)
#define	SAADC_SUBSCRIBE_SAMPLE_EN_DISABLED								(0x0u<<31)
#define	SAADC_SUBSCRIBE_SAMPLE_EN_ENABLED								(0x1u<<31)

// SUBSCRIBE_STOP Configuration

#define	SAADC_SUBSCRIBE_STOP_EN											(0x1u<<31)
#define	SAADC_SUBSCRIBE_STOP_CHIDX										(0xFFu<<0)
#define	SAADC_SUBSCRIBE_STOP_CHIDX_0									(0x1u<<0)
#define	SAADC_SUBSCRIBE_STOP_EN_DISABLED								(0x0u<<31)
#define	SAADC_SUBSCRIBE_STOP_EN_ENABLED									(0x1u<<31)

// SUBSCRIBE_CALIBRATEOFFSET Configuration

#define	SAADC_SUBSCRIBE_CALIBRATEOFFSET_EN								(0x1u<<31)
#define	SAADC_SUBSCRIBE_CALIBRATEOFFSET_CHIDX							(0xFFu<<0)
#define	SAADC_SUBSCRIBE_CALIBRATEOFFSET_CHIDX_0							(0x1u<<0)
#define	SAADC_SUBSCRIBE_CALIBRATEOFFSET_EN_DISABLED						(0x0u<<31)
#define	SAADC_SUBSCRIBE_CALIBRATEOFFSET_EN_ENABLED						(0x1u<<31)

// EVENTS_STARTED Configuration

#define	SAADC_EVENTS_STARTED_EVENTS_STARTED								(0x1u<<0)
#define	SAADC_EVENTS_STARTED_EVENTS_STARTED_NOTGENERATED				(0x0u<<0)
#define	SAADC_EVENTS_STARTED_EVENTS_STARTED_GENERATED					(0x1u<<0)

// EVENTS_END Configuration

#define	SAADC_EVENTS_END_EVENTS_END										(0x1u<<0)
#define	SAADC_EVENTS_END_EVENTS_END_NOTGENERATED						(0x0u<<0)
#define	SAADC_EVENTS_END_EVENTS_END_GENERATED							(0x1u<<0)

// EVENTS_DONE Configuration

#define	SAADC_EVENTS_DONE_EVENTS_DONE									(0x1u<<0)
#define	SAADC_EVENTS_DONE_EVENTS_DONE_NOTGENERATED						(0x0u<<0)
#define	SAADC_EVENTS_DONE_EVENTS_DONE_GENERATED							(0x1u<<0)

// EVENTS_RESULTDONE Configuration

#define	SAADC_EVENTS_RESULTDONE_EVENTS_RESULTDONE						(0x1u<<0)
#define	SAADC_EVENTS_RESULTDONE_EVENTS_RESULTDONE_NOTGENERATED			(0x0u<<0)
#define	SAADC_EVENTS_RESULTDONE_EVENTS_RESULTDONE_GENERATED				(0x1u<<0)

// EVENTS_CALIBRATEDONE Configuration

#define	SAADC_EVENTS_CALIBRATEDONE_EVENTS_CALIBRATEDONE					(0x1u<<0)
#define	SAADC_EVENTS_CALIBRATEDONE_EVENTS_CALIBRATEDONE_NOTGENERATED	(0x0u<<0)
#define	SAADC_EVENTS_CALIBRATEDONE_EVENTS_CALIBRATEDONE_GENERATED		(0x1u<<0)

// EVENTS_STOPPED Configuration

#define	SAADC_EVENTS_STOPPED_EVENTS_STOPPED								(0x1u<<0)
#define	SAADC_EVENTS_STOPPED_EVENTS_STOPPED_NOTGENERATED				(0x0u<<0)
#define	SAADC_EVENTS_STOPPED_EVENTS_STOPPED_GENERATED					(0x1u<<0)

// LIMITH Configuration

#define	SAADC_EVENTS_CH_LIMITH_LIMITH									(0x1u<<0)
#define	SAADC_EVENTS_CH_LIMITH_LIMITH_NOTGENERATED						(0x0u<<0)
#define	SAADC_EVENTS_CH_LIMITH_LIMITH_GENERATED							(0x1u<<0)

// LIMITL Configuration

#define	SAADC_EVENTS_CH_LIMITL_LIMITL									(0x1u<<0)
#define	SAADC_EVENTS_CH_LIMITL_LIMITL_NOTGENERATED						(0x0u<<0)
#define	SAADC_EVENTS_CH_LIMITL_LIMITL_GENERATED							(0x1u<<0)

// PUBLISH_STARTED Configuration

#define	SAADC_PUBLISH_STARTED_EN										(0x1u<<31)
#define	SAADC_PUBLISH_STARTED_CHIDX										(0xFFu<<0)
#define	SAADC_PUBLISH_STARTED_CHIDX_0									(0x1u<<0)
#define	SAADC_PUBLISH_STARTED_EN_DISABLED								(0x0u<<31)
#define	SAADC_PUBLISH_STARTED_EN_ENABLED								(0x1u<<31)

// PUBLISH_END Configuration

#define	SAADC_PUBLISH_END_EN											(0x1u<<31)
#define	SAADC_PUBLISH_END_CHIDX											(0xFFu<<0)
#define	SAADC_PUBLISH_END_CHIDX_0										(0x1u<<0)
#define	SAADC_PUBLISH_END_EN_DISABLED									(0x0u<<31)
#define	SAADC_PUBLISH_END_EN_ENABLED									(0x1u<<31)

// PUBLISH_DONE Configuration

#define	SAADC_PUBLISH_DONE_EN											(0x1u<<31)
#define	SAADC_PUBLISH_DONE_CHIDX										(0xFFu<<0)
#define	SAADC_PUBLISH_DONE_CHIDX_0										(0x1u<<0)
#define	SAADC_PUBLISH_DONE_EN_DISABLED									(0x0u<<31)
#define	SAADC_PUBLISH_DONE_EN_ENABLED									(0x1u<<31)

// PUBLISH_RESULTDONE Configuration

#define	SAADC_PUBLISH_RESULTDONE_EN										(0x1u<<31)
#define	SAADC_PUBLISH_RESULTDONE_CHIDX									(0xFFu<<0)
#define	SAADC_PUBLISH_RESULTDONE_CHIDX_0								(0x1u<<0)
#define	SAADC_PUBLISH_RESULTDONE_EN_DISABLED							(0x0u<<31)
#define	SAADC_PUBLISH_RESULTDONE_EN_ENABLED								(0x1u<<31)

// PUBLISH_CALIBRATEDONE Configuration

#define	SAADC_PUBLISH_CALIBRATEDONE_EN									(0x1u<<31)
#define	SAADC_PUBLISH_CALIBRATEDONE_CHIDX								(0xFFu<<0)
#define	SAADC_PUBLISH_CALIBRATEDONE_CHIDX_0								(0x1u<<0)
#define	SAADC_PUBLISH_CALIBRATEDONE_EN_DISABLED							(0x0u<<31)
#define	SAADC_PUBLISH_CALIBRATEDONE_EN_ENABLED							(0x1u<<31)

// PUBLISH_STOPPED Configuration

#define	SAADC_PUBLISH_STOPPED_EN										(0x1u<<31)
#define	SAADC_PUBLISH_STOPPED_CHIDX										(0xFFu<<0)
#define	SAADC_PUBLISH_STOPPED_CHIDX_0									(0x1u<<0)
#define	SAADC_PUBLISH_STOPPED_EN_DISABLED								(0x0u<<31)
#define	SAADC_PUBLISH_STOPPED_EN_ENABLED								(0x1u<<31)

// LIMITH Configuration

#define	SAADC_PUBLISH_CH_LIMITH_EN										(0x1u<<31)
#define	SAADC_PUBLISH_CH_LIMITH_CHIDX									(0xFFu<<0)
#define	SAADC_PUBLISH_CH_LIMITH_CHIDX_0									(0x1u<<0)
#define	SAADC_PUBLISH_CH_LIMITH_EN_DISABLED								(0x0u<<31)
#define	SAADC_PUBLISH_CH_LIMITH_EN_ENABLED								(0x1u<<31)

// LIMITL Configuration

#define	SAADC_PUBLISH_CH_LIMITL_EN										(0x1u<<31)
#define	SAADC_PUBLISH_CH_LIMITL_CHIDX									(0xFFu<<0)
#define	SAADC_PUBLISH_CH_LIMITL_CHIDX_0									(0x1u<<0)
#define	SAADC_PUBLISH_CH_LIMITL_EN_DISABLED								(0x0u<<31)
#define	SAADC_PUBLISH_CH_LIMITL_EN_ENABLED								(0x1u<<31)

// INTEN Configuration

#define	SAADC_INTEN_CH7LIMITL											(0x1u<<21)
#define	SAADC_INTEN_CH7LIMITH											(0x1u<<20)
#define	SAADC_INTEN_CH6LIMITL											(0x1u<<19)
#define	SAADC_INTEN_CH6LIMITH											(0x1u<<18)
#define	SAADC_INTEN_CH5LIMITL											(0x1u<<17)
#define	SAADC_INTEN_CH5LIMITH											(0x1u<<16)
#define	SAADC_INTEN_CH4LIMITL											(0x1u<<15)
#define	SAADC_INTEN_CH4LIMITH											(0x1u<<14)
#define	SAADC_INTEN_CH3LIMITL											(0x1u<<13)
#define	SAADC_INTEN_CH3LIMITH											(0x1u<<12)
#define	SAADC_INTEN_CH2LIMITL											(0x1u<<11)
#define	SAADC_INTEN_CH2LIMITH											(0x1u<<10)
#define	SAADC_INTEN_CH1LIMITL											(0x1u<<9)
#define	SAADC_INTEN_CH1LIMITH											(0x1u<<8)
#define	SAADC_INTEN_CH0LIMITL											(0x1u<<7)
#define	SAADC_INTEN_CH0LIMITH											(0x1u<<6)
#define	SAADC_INTEN_STOPPED												(0x1u<<5)
#define	SAADC_INTEN_CALIBRATEDONE										(0x1u<<4)
#define	SAADC_INTEN_RESULTDONE											(0x1u<<3)
#define	SAADC_INTEN_DONE												(0x1u<<2)
#define	SAADC_INTEN_END													(0x1u<<1)
#define	SAADC_INTEN_STARTED												(0x1u<<0)
#define	SAADC_INTEN_CH7LIMITL_DISABLED									(0x0u<<21)
#define	SAADC_INTEN_CH7LIMITL_ENABLED									(0x1u<<21)
#define	SAADC_INTEN_CH7LIMITH_DISABLED									(0x0u<<20)
#define	SAADC_INTEN_CH7LIMITH_ENABLED									(0x1u<<20)
#define	SAADC_INTEN_CH6LIMITL_DISABLED									(0x0u<<19)
#define	SAADC_INTEN_CH6LIMITL_ENABLED									(0x1u<<19)
#define	SAADC_INTEN_CH6LIMITH_DISABLED									(0x0u<<18)
#define	SAADC_INTEN_CH6LIMITH_ENABLED									(0x1u<<18)
#define	SAADC_INTEN_CH5LIMITL_DISABLED									(0x0u<<17)
#define	SAADC_INTEN_CH5LIMITL_ENABLED									(0x1u<<17)
#define	SAADC_INTEN_CH5LIMITH_DISABLED									(0x0u<<16)
#define	SAADC_INTEN_CH5LIMITH_ENABLED									(0x1u<<16)
#define	SAADC_INTEN_CH4LIMITL_DISABLED									(0x0u<<15)
#define	SAADC_INTEN_CH4LIMITL_ENABLED									(0x1u<<15)
#define	SAADC_INTEN_CH4LIMITH_DISABLED									(0x0u<<14)
#define	SAADC_INTEN_CH4LIMITH_ENABLED									(0x1u<<14)
#define	SAADC_INTEN_CH3LIMITL_DISABLED									(0x0u<<13)
#define	SAADC_INTEN_CH3LIMITL_ENABLED									(0x1u<<13)
#define	SAADC_INTEN_CH3LIMITH_DISABLED									(0x0u<<12)
#define	SAADC_INTEN_CH3LIMITH_ENABLED									(0x1u<<12)
#define	SAADC_INTEN_CH2LIMITL_DISABLED									(0x0u<<11)
#define	SAADC_INTEN_CH2LIMITL_ENABLED									(0x1u<<11)
#define	SAADC_INTEN_CH2LIMITH_DISABLED									(0x0u<<10)
#define	SAADC_INTEN_CH2LIMITH_ENABLED									(0x1u<<10)
#define	SAADC_INTEN_CH1LIMITL_DISABLED									(0x0u<<9)
#define	SAADC_INTEN_CH1LIMITL_ENABLED									(0x1u<<9)
#define	SAADC_INTEN_CH1LIMITH_DISABLED									(0x0u<<8)
#define	SAADC_INTEN_CH1LIMITH_ENABLED									(0x1u<<8)
#define	SAADC_INTEN_CH0LIMITL_DISABLED									(0x0u<<7)
#define	SAADC_INTEN_CH0LIMITL_ENABLED									(0x1u<<7)
#define	SAADC_INTEN_CH0LIMITH_DISABLED									(0x0u<<6)
#define	SAADC_INTEN_CH0LIMITH_ENABLED									(0x1u<<6)
#define	SAADC_INTEN_STOPPED_DISABLED									(0x0u<<5)
#define	SAADC_INTEN_STOPPED_ENABLED										(0x1u<<5)
#define	SAADC_INTEN_CALIBRATEDONE_DISABLED								(0x0u<<4)
#define	SAADC_INTEN_CALIBRATEDONE_ENABLED								(0x1u<<4)
#define	SAADC_INTEN_RESULTDONE_DISABLED									(0x0u<<3)
#define	SAADC_INTEN_RESULTDONE_ENABLED									(0x1u<<3)
#define	SAADC_INTEN_DONE_DISABLED										(0x0u<<2)
#define	SAADC_INTEN_DONE_ENABLED										(0x1u<<2)
#define	SAADC_INTEN_END_DISABLED										(0x0u<<1)
#define	SAADC_INTEN_END_ENABLED											(0x1u<<1)
#define	SAADC_INTEN_STARTED_DISABLED									(0x0u<<0)
#define	SAADC_INTEN_STARTED_ENABLED										(0x1u<<0)

// INTENSET Configuration

#define	SAADC_INTENSET_CH7LIMITL										(0x1u<<21)
#define	SAADC_INTENSET_CH7LIMITH										(0x1u<<20)
#define	SAADC_INTENSET_CH6LIMITL										(0x1u<<19)
#define	SAADC_INTENSET_CH6LIMITH										(0x1u<<18)
#define	SAADC_INTENSET_CH5LIMITL										(0x1u<<17)
#define	SAADC_INTENSET_CH5LIMITH										(0x1u<<16)
#define	SAADC_INTENSET_CH4LIMITL										(0x1u<<15)
#define	SAADC_INTENSET_CH4LIMITH										(0x1u<<14)
#define	SAADC_INTENSET_CH3LIMITL										(0x1u<<13)
#define	SAADC_INTENSET_CH3LIMITH										(0x1u<<12)
#define	SAADC_INTENSET_CH2LIMITL										(0x1u<<11)
#define	SAADC_INTENSET_CH2LIMITH										(0x1u<<10)
#define	SAADC_INTENSET_CH1LIMITL										(0x1u<<9)
#define	SAADC_INTENSET_CH1LIMITH										(0x1u<<8)
#define	SAADC_INTENSET_CH0LIMITL										(0x1u<<7)
#define	SAADC_INTENSET_CH0LIMITH										(0x1u<<6)
#define	SAADC_INTENSET_STOPPED											(0x1u<<5)
#define	SAADC_INTENSET_CALIBRATEDONE									(0x1u<<4)
#define	SAADC_INTENSET_RESULTDONE										(0x1u<<3)
#define	SAADC_INTENSET_DONE												(0x1u<<2)
#define	SAADC_INTENSET_END												(0x1u<<1)
#define	SAADC_INTENSET_STARTED											(0x1u<<0)
#define	SAADC_INTENSET_CH7LIMITL_DISABLED								(0x0u<<21)
#define	SAADC_INTENSET_CH7LIMITL_ENABLED								(0x1u<<21)
#define	SAADC_INTENSET_CH7LIMITL_SET									(0x1u<<21)
#define	SAADC_INTENSET_CH7LIMITH_DISABLED								(0x0u<<20)
#define	SAADC_INTENSET_CH7LIMITH_ENABLED								(0x1u<<20)
#define	SAADC_INTENSET_CH7LIMITH_SET									(0x1u<<20)
#define	SAADC_INTENSET_CH6LIMITL_DISABLED								(0x0u<<19)
#define	SAADC_INTENSET_CH6LIMITL_ENABLED								(0x1u<<19)
#define	SAADC_INTENSET_CH6LIMITL_SET									(0x1u<<19)
#define	SAADC_INTENSET_CH6LIMITH_DISABLED								(0x0u<<18)
#define	SAADC_INTENSET_CH6LIMITH_ENABLED								(0x1u<<18)
#define	SAADC_INTENSET_CH6LIMITH_SET									(0x1u<<18)
#define	SAADC_INTENSET_CH5LIMITL_DISABLED								(0x0u<<17)
#define	SAADC_INTENSET_CH5LIMITL_ENABLED								(0x1u<<17)
#define	SAADC_INTENSET_CH5LIMITL_SET									(0x1u<<17)
#define	SAADC_INTENSET_CH5LIMITH_DISABLED								(0x0u<<16)
#define	SAADC_INTENSET_CH5LIMITH_ENABLED								(0x1u<<16)
#define	SAADC_INTENSET_CH5LIMITH_SET									(0x1u<<16)
#define	SAADC_INTENSET_CH4LIMITL_DISABLED								(0x0u<<15)
#define	SAADC_INTENSET_CH4LIMITL_ENABLED								(0x1u<<15)
#define	SAADC_INTENSET_CH4LIMITL_SET									(0x1u<<15)
#define	SAADC_INTENSET_CH4LIMITH_DISABLED								(0x0u<<14)
#define	SAADC_INTENSET_CH4LIMITH_ENABLED								(0x1u<<14)
#define	SAADC_INTENSET_CH4LIMITH_SET									(0x1u<<14)
#define	SAADC_INTENSET_CH3LIMITL_DISABLED								(0x0u<<13)
#define	SAADC_INTENSET_CH3LIMITL_ENABLED								(0x1u<<13)
#define	SAADC_INTENSET_CH3LIMITL_SET									(0x1u<<13)
#define	SAADC_INTENSET_CH3LIMITH_DISABLED								(0x0u<<12)
#define	SAADC_INTENSET_CH3LIMITH_ENABLED								(0x1u<<12)
#define	SAADC_INTENSET_CH3LIMITH_SET									(0x1u<<12)
#define	SAADC_INTENSET_CH2LIMITL_DISABLED								(0x0u<<11)
#define	SAADC_INTENSET_CH2LIMITL_ENABLED								(0x1u<<11)
#define	SAADC_INTENSET_CH2LIMITL_SET									(0x1u<<11)
#define	SAADC_INTENSET_CH2LIMITH_DISABLED								(0x0u<<10)
#define	SAADC_INTENSET_CH2LIMITH_ENABLED								(0x1u<<10)
#define	SAADC_INTENSET_CH2LIMITH_SET									(0x1u<<10)
#define	SAADC_INTENSET_CH1LIMITL_DISABLED								(0x0u<<9)
#define	SAADC_INTENSET_CH1LIMITL_ENABLED								(0x1u<<9)
#define	SAADC_INTENSET_CH1LIMITL_SET									(0x1u<<9)
#define	SAADC_INTENSET_CH1LIMITH_DISABLED								(0x0u<<8)
#define	SAADC_INTENSET_CH1LIMITH_ENABLED								(0x1u<<8)
#define	SAADC_INTENSET_CH1LIMITH_SET									(0x1u<<8)
#define	SAADC_INTENSET_CH0LIMITL_DISABLED								(0x0u<<7)
#define	SAADC_INTENSET_CH0LIMITL_ENABLED								(0x1u<<7)
#define	SAADC_INTENSET_CH0LIMITL_SET									(0x1u<<7)
#define	SAADC_INTENSET_CH0LIMITH_DISABLED								(0x0u<<6)
#define	SAADC_INTENSET_CH0LIMITH_ENABLED								(0x1u<<6)
#define	SAADC_INTENSET_CH0LIMITH_SET									(0x1u<<6)
#define	SAADC_INTENSET_STOPPED_DISABLED									(0x0u<<5)
#define	SAADC_INTENSET_STOPPED_ENABLED									(0x1u<<5)
#define	SAADC_INTENSET_STOPPED_SET										(0x1u<<5)
#define	SAADC_INTENSET_CALIBRATEDONE_DISABLED							(0x0u<<4)
#define	SAADC_INTENSET_CALIBRATEDONE_ENABLED							(0x1u<<4)
#define	SAADC_INTENSET_CALIBRATEDONE_SET								(0x1u<<4)
#define	SAADC_INTENSET_RESULTDONE_DISABLED								(0x0u<<3)
#define	SAADC_INTENSET_RESULTDONE_ENABLED								(0x1u<<3)
#define	SAADC_INTENSET_RESULTDONE_SET									(0x1u<<3)
#define	SAADC_INTENSET_DONE_DISABLED									(0x0u<<2)
#define	SAADC_INTENSET_DONE_ENABLED										(0x1u<<2)
#define	SAADC_INTENSET_DONE_SET											(0x1u<<2)
#define	SAADC_INTENSET_END_DISABLED										(0x0u<<1)
#define	SAADC_INTENSET_END_ENABLED										(0x1u<<1)
#define	SAADC_INTENSET_END_SET											(0x1u<<1)
#define	SAADC_INTENSET_STARTED_DISABLED									(0x0u<<0)
#define	SAADC_INTENSET_STARTED_ENABLED									(0x1u<<0)
#define	SAADC_INTENSET_STARTED_SET										(0x1u<<0)

// INTENCLR Configuration

#define	SAADC_INTENCLR_CH7LIMITL										(0x1u<<21)
#define	SAADC_INTENCLR_CH7LIMITH										(0x1u<<20)
#define	SAADC_INTENCLR_CH6LIMITL										(0x1u<<19)
#define	SAADC_INTENCLR_CH6LIMITH										(0x1u<<18)
#define	SAADC_INTENCLR_CH5LIMITL										(0x1u<<17)
#define	SAADC_INTENCLR_CH5LIMITH										(0x1u<<16)
#define	SAADC_INTENCLR_CH4LIMITL										(0x1u<<15)
#define	SAADC_INTENCLR_CH4LIMITH										(0x1u<<14)
#define	SAADC_INTENCLR_CH3LIMITL										(0x1u<<13)
#define	SAADC_INTENCLR_CH3LIMITH										(0x1u<<12)
#define	SAADC_INTENCLR_CH2LIMITL										(0x1u<<11)
#define	SAADC_INTENCLR_CH2LIMITH										(0x1u<<10)
#define	SAADC_INTENCLR_CH1LIMITL										(0x1u<<9)
#define	SAADC_INTENCLR_CH1LIMITH										(0x1u<<8)
#define	SAADC_INTENCLR_CH0LIMITL										(0x1u<<7)
#define	SAADC_INTENCLR_CH0LIMITH										(0x1u<<6)
#define	SAADC_INTENCLR_STOPPED											(0x1u<<5)
#define	SAADC_INTENCLR_CALIBRATEDONE									(0x1u<<4)
#define	SAADC_INTENCLR_RESULTDONE										(0x1u<<3)
#define	SAADC_INTENCLR_DONE												(0x1u<<2)
#define	SAADC_INTENCLR_END												(0x1u<<1)
#define	SAADC_INTENCLR_STARTED											(0x1u<<0)
#define	SAADC_INTENCLR_CH7LIMITL_DISABLED								(0x0u<<21)
#define	SAADC_INTENCLR_CH7LIMITL_ENABLED								(0x1u<<21)
#define	SAADC_INTENCLR_CH7LIMITL_CLEAR									(0x1u<<21)
#define	SAADC_INTENCLR_CH7LIMITH_DISABLED								(0x0u<<20)
#define	SAADC_INTENCLR_CH7LIMITH_ENABLED								(0x1u<<20)
#define	SAADC_INTENCLR_CH7LIMITH_CLEAR									(0x1u<<20)
#define	SAADC_INTENCLR_CH6LIMITL_DISABLED								(0x0u<<19)
#define	SAADC_INTENCLR_CH6LIMITL_ENABLED								(0x1u<<19)
#define	SAADC_INTENCLR_CH6LIMITL_CLEAR									(0x1u<<19)
#define	SAADC_INTENCLR_CH6LIMITH_DISABLED								(0x0u<<18)
#define	SAADC_INTENCLR_CH6LIMITH_ENABLED								(0x1u<<18)
#define	SAADC_INTENCLR_CH6LIMITH_CLEAR									(0x1u<<18)
#define	SAADC_INTENCLR_CH5LIMITL_DISABLED								(0x0u<<17)
#define	SAADC_INTENCLR_CH5LIMITL_ENABLED								(0x1u<<17)
#define	SAADC_INTENCLR_CH5LIMITL_CLEAR									(0x1u<<17)
#define	SAADC_INTENCLR_CH5LIMITH_DISABLED								(0x0u<<16)
#define	SAADC_INTENCLR_CH5LIMITH_ENABLED								(0x1u<<16)
#define	SAADC_INTENCLR_CH5LIMITH_CLEAR									(0x1u<<16)
#define	SAADC_INTENCLR_CH4LIMITL_DISABLED								(0x0u<<15)
#define	SAADC_INTENCLR_CH4LIMITL_ENABLED								(0x1u<<15)
#define	SAADC_INTENCLR_CH4LIMITL_CLEAR									(0x1u<<15)
#define	SAADC_INTENCLR_CH4LIMITH_DISABLED								(0x0u<<14)
#define	SAADC_INTENCLR_CH4LIMITH_ENABLED								(0x1u<<14)
#define	SAADC_INTENCLR_CH4LIMITH_CLEAR									(0x1u<<14)
#define	SAADC_INTENCLR_CH3LIMITL_DISABLED								(0x0u<<13)
#define	SAADC_INTENCLR_CH3LIMITL_ENABLED								(0x1u<<13)
#define	SAADC_INTENCLR_CH3LIMITL_CLEAR									(0x1u<<13)
#define	SAADC_INTENCLR_CH3LIMITH_DISABLED								(0x0u<<12)
#define	SAADC_INTENCLR_CH3LIMITH_ENABLED								(0x1u<<12)
#define	SAADC_INTENCLR_CH3LIMITH_CLEAR									(0x1u<<12)
#define	SAADC_INTENCLR_CH2LIMITL_DISABLED								(0x0u<<11)
#define	SAADC_INTENCLR_CH2LIMITL_ENABLED								(0x1u<<11)
#define	SAADC_INTENCLR_CH2LIMITL_CLEAR									(0x1u<<11)
#define	SAADC_INTENCLR_CH2LIMITH_DISABLED								(0x0u<<10)
#define	SAADC_INTENCLR_CH2LIMITH_ENABLED								(0x1u<<10)
#define	SAADC_INTENCLR_CH2LIMITH_CLEAR									(0x1u<<10)
#define	SAADC_INTENCLR_CH1LIMITL_DISABLED								(0x0u<<9)
#define	SAADC_INTENCLR_CH1LIMITL_ENABLED								(0x1u<<9)
#define	SAADC_INTENCLR_CH1LIMITL_CLEAR									(0x1u<<9)
#define	SAADC_INTENCLR_CH1LIMITH_DISABLED								(0x0u<<8)
#define	SAADC_INTENCLR_CH1LIMITH_ENABLED								(0x1u<<8)
#define	SAADC_INTENCLR_CH1LIMITH_CLEAR									(0x1u<<8)
#define	SAADC_INTENCLR_CH0LIMITL_DISABLED								(0x0u<<7)
#define	SAADC_INTENCLR_CH0LIMITL_ENABLED								(0x1u<<7)
#define	SAADC_INTENCLR_CH0LIMITL_CLEAR									(0x1u<<7)
#define	SAADC_INTENCLR_CH0LIMITH_DISABLED								(0x0u<<6)
#define	SAADC_INTENCLR_CH0LIMITH_ENABLED								(0x1u<<6)
#define	SAADC_INTENCLR_CH0LIMITH_CLEAR									(0x1u<<6)
#define	SAADC_INTENCLR_STOPPED_DISABLED									(0x0u<<5)
#define	SAADC_INTENCLR_STOPPED_ENABLED									(0x1u<<5)
#define	SAADC_INTENCLR_STOPPED_CLEAR									(0x1u<<5)
#define	SAADC_INTENCLR_CALIBRATEDONE_DISABLED							(0x0u<<4)
#define	SAADC_INTENCLR_CALIBRATEDONE_ENABLED							(0x1u<<4)
#define	SAADC_INTENCLR_CALIBRATEDONE_CLEAR								(0x1u<<4)
#define	SAADC_INTENCLR_RESULTDONE_DISABLED								(0x0u<<3)
#define	SAADC_INTENCLR_RESULTDONE_ENABLED								(0x1u<<3)
#define	SAADC_INTENCLR_RESULTDONE_CLEAR									(0x1u<<3)
#define	SAADC_INTENCLR_DONE_DISABLED									(0x0u<<2)
#define	SAADC_INTENCLR_DONE_ENABLED										(0x1u<<2)
#define	SAADC_INTENCLR_DONE_CLEAR										(0x1u<<2)
#define	SAADC_INTENCLR_END_DISABLED										(0x0u<<1)
#define	SAADC_INTENCLR_END_ENABLED										(0x1u<<1)
#define	SAADC_INTENCLR_END_CLEAR										(0x1u<<1)
#define	SAADC_INTENCLR_STARTED_DISABLED									(0x0u<<0)
#define	SAADC_INTENCLR_STARTED_ENABLED									(0x1u<<0)
#define	SAADC_INTENCLR_STARTED_CLEAR									(0x1u<<0)

// STATUS Configuration

#define	SAADC_STATUS_STATUS												(0x1u<<0)
#define	SAADC_STATUS_STATUS_READY										(0x0u<<0)
#define	SAADC_STATUS_STATUS_BUSY										(0x1u<<0)

// ENABLE Configuration

#define	SAADC_ENABLE_ENABLE												(0x1u<<0)
#define	SAADC_ENABLE_ENABLE_DISABLED									(0x0u<<0)
#define	SAADC_ENABLE_ENABLE_ENABLED										(0x1u<<0)

// PSELP Configuration

#define	SAADC_CH_PSELP_PSELP											(0x1Fu<<0)
#define	SAADC_CH_PSELP_PSELP_0											(0x1u<<0)
#define	SAADC_CH_PSELP_PSELP_NC											(0x0u<<0)
#define	SAADC_CH_PSELP_PSELP_ANALOGINPUT0								(0x1u<<0)
#define	SAADC_CH_PSELP_PSELP_ANALOGINPUT1								(0x2u<<0)
#define	SAADC_CH_PSELP_PSELP_ANALOGINPUT2								(0x3u<<0)
#define	SAADC_CH_PSELP_PSELP_ANALOGINPUT3								(0x4u<<0)
#define	SAADC_CH_PSELP_PSELP_ANALOGINPUT4								(0x5u<<0)
#define	SAADC_CH_PSELP_PSELP_ANALOGINPUT5								(0x6u<<0)
#define	SAADC_CH_PSELP_PSELP_ANALOGINPUT6								(0x7u<<0)
#define	SAADC_CH_PSELP_PSELP_ANALOGINPUT7								(0x8u<<0)
#define	SAADC_CH_PSELP_PSELP_VDD										(0x9u<<0)
#define	SAADC_CH_PSELP_PSELP_VDDHDIV5									(0xDu<<0)

// PSELN Configuration

#define	SAADC_CH_PSELN_PSELN											(0x1Fu<<0)
#define	SAADC_CH_PSELN_PSELN_0											(0x1u<<0)
#define	SAADC_CH_PSELN_PSELN_NC											(0x0u<<0)
#define	SAADC_CH_PSELN_PSELN_ANALOGINPUT0								(0x1u<<0)
#define	SAADC_CH_PSELN_PSELN_ANALOGINPUT1								(0x2u<<0)
#define	SAADC_CH_PSELN_PSELN_ANALOGINPUT2								(0x3u<<0)
#define	SAADC_CH_PSELN_PSELN_ANALOGINPUT3								(0x4u<<0)
#define	SAADC_CH_PSELN_PSELN_ANALOGINPUT4								(0x5u<<0)
#define	SAADC_CH_PSELN_PSELN_ANALOGINPUT5								(0x6u<<0)
#define	SAADC_CH_PSELN_PSELN_ANALOGINPUT6								(0x7u<<0)
#define	SAADC_CH_PSELN_PSELN_ANALOGINPUT7								(0x8u<<0)
#define	SAADC_CH_PSELN_PSELN_VDD										(0x9u<<0)
#define	SAADC_CH_PSELN_PSELN_VDDHDIV5									(0xDu<<0)

// CONFIG Configuration

#define	SAADC_CH_CONFIG_BURST											(0x1u<<24)
#define	SAADC_CH_CONFIG_MODE											(0x1u<<20)
#define	SAADC_CH_CONFIG_TACQ											(0x7u<<16)
#define	SAADC_CH_CONFIG_TACQ_0											(0x1u<<16)
#define	SAADC_CH_CONFIG_REFSEL											(0x1u<<12)
#define	SAADC_CH_CONFIG_GAIN											(0x7u<<8)
#define	SAADC_CH_CONFIG_GAIN_0											(0x1u<<8)
#define	SAADC_CH_CONFIG_RESN											(0x3u<<4)
#define	SAADC_CH_CONFIG_RESN_0											(0x1u<<4)
#define	SAADC_CH_CONFIG_RESP											(0x3u<<0)
#define	SAADC_CH_CONFIG_RESP_0											(0x1u<<0)
#define	SAADC_CH_CONFIG_BURST_DISABLED									(0x0u<<24)
#define	SAADC_CH_CONFIG_BURST_ENABLED									(0x1u<<24)
#define	SAADC_CH_CONFIG_MODE_SE											(0x0u<<20)
#define	SAADC_CH_CONFIG_MODE_DIFF										(0x1u<<20)
#define	SAADC_CH_CONFIG_TACQ_3US										(0x0u<<16)
#define	SAADC_CH_CONFIG_TACQ_5US										(0x1u<<16)
#define	SAADC_CH_CONFIG_TACQ_10US										(0x2u<<16)
#define	SAADC_CH_CONFIG_TACQ_15US										(0x3u<<16)
#define	SAADC_CH_CONFIG_TACQ_20US										(0x4u<<16)
#define	SAADC_CH_CONFIG_TACQ_40US										(0x5u<<16)
#define	SAADC_CH_CONFIG_REFSEL_INTERNAL									(0x0u<<12)
#define	SAADC_CH_CONFIG_REFSEL_VDD1_4									(0x1u<<12)
#define	SAADC_CH_CONFIG_GAIN_GAIN1_6									(0x0u<<8)
#define	SAADC_CH_CONFIG_GAIN_GAIN1_5									(0x1u<<8)
#define	SAADC_CH_CONFIG_GAIN_GAIN1_4									(0x2u<<8)
#define	SAADC_CH_CONFIG_GAIN_GAIN1_3									(0x3u<<8)
#define	SAADC_CH_CONFIG_GAIN_GAIN1_2									(0x4u<<8)
#define	SAADC_CH_CONFIG_GAIN_GAIN1										(0x5u<<8)
#define	SAADC_CH_CONFIG_GAIN_GAIN2										(0x6u<<8)
#define	SAADC_CH_CONFIG_GAIN_GAIN4										(0x7u<<8)
#define	SAADC_CH_CONFIG_RESN_BYPASS										(0x0u<<4)
#define	SAADC_CH_CONFIG_RESN_PULLDOWN									(0x1u<<4)
#define	SAADC_CH_CONFIG_RESN_PULLUP										(0x2u<<4)
#define	SAADC_CH_CONFIG_RESN_VDD1_2										(0x3u<<4)
#define	SAADC_CH_CONFIG_RESP_BYPASS										(0x0u<<0)
#define	SAADC_CH_CONFIG_RESP_PULLDOWN									(0x1u<<0)
#define	SAADC_CH_CONFIG_RESP_PULLUP										(0x2u<<0)
#define	SAADC_CH_CONFIG_RESP_VDD1_2										(0x3u<<0)

// LIMIT Configuration

#define	SAADC_CH_LIMIT_HIGH												(0xFFFFu<<16)
#define	SAADC_CH_LIMIT_HIGH_0											(0x1u<<16)
#define	SAADC_CH_LIMIT_LOW												(0xFFFFu<<0)
#define	SAADC_CH_LIMIT_LOW_0											(0x1u<<0)

// RESOLUTION Configuration

#define	SAADC_RESOLUTION_VAL											(0x7u<<0)
#define	SAADC_RESOLUTION_VAL_0											(0x1u<<0)
#define	SAADC_RESOLUTION_VAL_8BIT										(0x0u<<0)
#define	SAADC_RESOLUTION_VAL_10BIT										(0x1u<<0)
#define	SAADC_RESOLUTION_VAL_12BIT										(0x2u<<0)
#define	SAADC_RESOLUTION_VAL_14BIT										(0x3u<<0)

// OVERSAMPLE Configuration

#define	SAADC_OVERSAMPLE_OVERSAMPLE										(0xFu<<0)
#define	SAADC_OVERSAMPLE_OVERSAMPLE_0									(0x1u<<0)
#define	SAADC_OVERSAMPLE_OVERSAMPLE_BYPASS								(0x0u<<0)
#define	SAADC_OVERSAMPLE_OVERSAMPLE_OVER2X								(0x1u<<0)
#define	SAADC_OVERSAMPLE_OVERSAMPLE_OVER4X								(0x2u<<0)
#define	SAADC_OVERSAMPLE_OVERSAMPLE_OVER8X								(0x3u<<0)
#define	SAADC_OVERSAMPLE_OVERSAMPLE_OVER16X								(0x4u<<0)
#define	SAADC_OVERSAMPLE_OVERSAMPLE_OVER32X								(0x5u<<0)
#define	SAADC_OVERSAMPLE_OVERSAMPLE_OVER64X								(0x6u<<0)
#define	SAADC_OVERSAMPLE_OVERSAMPLE_OVER128X							(0x7u<<0)
#define	SAADC_OVERSAMPLE_OVERSAMPLE_OVER256X							(0x8u<<0)

// SAMPLERATE Configuration

#define	SAADC_SAMPLERATE_MODE											(0x1u<<12)
#define	SAADC_SAMPLERATE_CC												(0x7FFu<<0)
#define	SAADC_SAMPLERATE_CC_0											(0x1u<<0)
#define	SAADC_SAMPLERATE_MODE_TASK										(0x0u<<12)
#define	SAADC_SAMPLERATE_MODE_TIMERS									(0x1u<<12)

// PTR Configuration

#define	SAADC_RESULT_PTR_PTR											(0xFFFFFFFFu<<0)
#define	SAADC_RESULT_PTR_PTR_0											(0x1u<<0)

// MAXCNT Configuration

#define	SAADC_RESULT_MAXCNT_MAXCNT										(0x7FFFu<<0)
#define	SAADC_RESULT_MAXCNT_MAXCNT_0									(0x1u<<0)

// AMOUNT Configuration

#define	SAADC_RESULT_AMOUNT_AMOUNT										(0x7FFFu<<0)
#define	SAADC_RESULT_AMOUNT_AMOUNT_0									(0x1u<<0)
