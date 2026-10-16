/*
; nrf5340_application_qdec.
; =========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_qdec equates.
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

// QDEC address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	TASKS_START;
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	TASKS_READCLRACC;
	volatile	uint32_t	TASKS_RDCLRACC;
	volatile	uint32_t	TASKS_RDCLRDBL;
	volatile	uint32_t	RESERVED0[27];
	volatile	uint32_t	SUBSCRIBE_START;
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	SUBSCRIBE_READCLRACC;
	volatile	uint32_t	SUBSCRIBE_RDCLRACC;
	volatile	uint32_t	SUBSCRIBE_RDCLRDBL;
	volatile	uint32_t	RESERVED1[27];
	volatile	uint32_t	EVENTS_SAMPLERDY;
	volatile	uint32_t	EVENTS_REPORTRDY;
	volatile	uint32_t	EVENTS_ACCOF;
	volatile	uint32_t	EVENTS_DBLRDY;
	volatile	uint32_t	EVENTS_STOPPED;
	volatile	uint32_t	RESERVED2[27];
	volatile	uint32_t	PUBLISH_SAMPLERDY;
	volatile	uint32_t	PUBLISH_REPORTRDY;
	volatile	uint32_t	PUBLISH_ACCOF;
	volatile	uint32_t	PUBLISH_DBLRDY;
	volatile	uint32_t	PUBLISH_STOPPED;
	volatile	uint32_t	RESERVED3[27];
	volatile	uint32_t	SHORTS;
	volatile	uint32_t	RESERVED4[64];
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED5[125];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	LEDPOL;
	volatile	uint32_t	SAMPLEPER;
	volatile	uint32_t	SAMPLE;
	volatile	uint32_t	REPORTPER;
	volatile	uint32_t	ACC;
	volatile	uint32_t	ACCREAD;
	volatile	uint32_t	PSEL_LED;
	volatile	uint32_t	PSEL_A;
	volatile	uint32_t	PSEL_B;
	volatile	uint32_t	DBFEN;
	volatile	uint32_t	RESERVED6[5];
	volatile	uint32_t	LEDPRE;
	volatile	uint32_t	ACCDBL;
	volatile	uint32_t	ACCDBLREAD;
} QDEC_TypeDef;

#if (defined(__cplusplus))
#define	QDEC0_NS	reinterpret_cast<QDEC_TypeDef *>(0x40033000u)
#define	QDEC0_S		reinterpret_cast<QDEC_TypeDef *>(0x50033000u)
#define	QDEC1_NS	reinterpret_cast<QDEC_TypeDef *>(0x40034000u)
#define	QDEC1_S		reinterpret_cast<QDEC_TypeDef *>(0x50034000u)

#else
#define	QDEC0_NS	((QDEC_TypeDef *)0x40033000u)
#define	QDEC0_S		((QDEC_TypeDef *)0x50033000u)
#define	QDEC1_NS	((QDEC_TypeDef *)0x40034000u)
#define	QDEC1_S		((QDEC_TypeDef *)0x50034000u)
#endif

// TASKS_START Configuration

#define	QDEC_TASKS_START_TASKS_START						(0x1u<<0)
#define	QDEC_TASKS_START_TASKS_START_TRIGGER				(0x1u<<0)

// TASKS_STOP Configuration

#define	QDEC_TASKS_STOP_TASKS_STOP							(0x1u<<0)
#define	QDEC_TASKS_STOP_TASKS_STOP_TRIGGER					(0x1u<<0)

// TASKS_READCLRACC Configuration

#define	QDEC_TASKS_READCLRACC_TASKS_READCLRACC				(0x1u<<0)
#define	QDEC_TASKS_READCLRACC_TASKS_READCLRACC_TRIGGER		(0x1u<<0)

// TASKS_RDCLRACC Configuration

#define	QDEC_TASKS_RDCLRACC_TASKS_RDCLRACC					(0x1u<<0)
#define	QDEC_TASKS_RDCLRACC_TASKS_RDCLRACC_TRIGGER			(0x1u<<0)

// TASKS_RDCLRDBL Configuration

#define	QDEC_TASKS_RDCLRDBL_TASKS_RDCLRDBL					(0x1u<<0)
#define	QDEC_TASKS_RDCLRDBL_TASKS_RDCLRDBL_TRIGGER			(0x1u<<0)

// SUBSCRIBE_START Configuration

#define	QDEC_SUBSCRIBE_START_EN								(0x1u<<31)
#define	QDEC_SUBSCRIBE_START_CHIDX							(0xFFu<<0)
#define	QDEC_SUBSCRIBE_START_CHIDX_0						(0x1u<<0)
#define	QDEC_SUBSCRIBE_START_EN_DISABLED					(0x0u<<31)
#define	QDEC_SUBSCRIBE_START_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_STOP Configuration

#define	QDEC_SUBSCRIBE_STOP_EN								(0x1u<<31)
#define	QDEC_SUBSCRIBE_STOP_CHIDX							(0xFFu<<0)
#define	QDEC_SUBSCRIBE_STOP_CHIDX_0							(0x1u<<0)
#define	QDEC_SUBSCRIBE_STOP_EN_DISABLED						(0x0u<<31)
#define	QDEC_SUBSCRIBE_STOP_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_READCLRACC Configuration

#define	QDEC_SUBSCRIBE_READCLRACC_EN						(0x1u<<31)
#define	QDEC_SUBSCRIBE_READCLRACC_CHIDX						(0xFFu<<0)
#define	QDEC_SUBSCRIBE_READCLRACC_CHIDX_0					(0x1u<<0)
#define	QDEC_SUBSCRIBE_READCLRACC_EN_DISABLED				(0x0u<<31)
#define	QDEC_SUBSCRIBE_READCLRACC_EN_ENABLED				(0x1u<<31)

// SUBSCRIBE_RDCLRACC Configuration

#define	QDEC_SUBSCRIBE_RDCLRACC_EN							(0x1u<<31)
#define	QDEC_SUBSCRIBE_RDCLRACC_CHIDX						(0xFFu<<0)
#define	QDEC_SUBSCRIBE_RDCLRACC_CHIDX_0						(0x1u<<0)
#define	QDEC_SUBSCRIBE_RDCLRACC_EN_DISABLED					(0x0u<<31)
#define	QDEC_SUBSCRIBE_RDCLRACC_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_RDCLRDBL Configuration

#define	QDEC_SUBSCRIBE_RDCLRDBL_EN							(0x1u<<31)
#define	QDEC_SUBSCRIBE_RDCLRDBL_CHIDX						(0xFFu<<0)
#define	QDEC_SUBSCRIBE_RDCLRDBL_CHIDX_0						(0x1u<<0)
#define	QDEC_SUBSCRIBE_RDCLRDBL_EN_DISABLED					(0x0u<<31)
#define	QDEC_SUBSCRIBE_RDCLRDBL_EN_ENABLED					(0x1u<<31)

// EVENTS_SAMPLERDY Configuration

#define	QDEC_EVENTS_SAMPLERDY_EVENTS_SAMPLERDY				(0x1u<<0)
#define	QDEC_EVENTS_SAMPLERDY_EVENTS_SAMPLERDY_NOTGENERATED	(0x0u<<0)
#define	QDEC_EVENTS_SAMPLERDY_EVENTS_SAMPLERDY_GENERATED	(0x1u<<0)

// EVENTS_REPORTRDY Configuration

#define	QDEC_EVENTS_REPORTRDY_EVENTS_REPORTRDY				(0x1u<<0)
#define	QDEC_EVENTS_REPORTRDY_EVENTS_REPORTRDY_NOTGENERATED	(0x0u<<0)
#define	QDEC_EVENTS_REPORTRDY_EVENTS_REPORTRDY_GENERATED	(0x1u<<0)

// EVENTS_ACCOF Configuration

#define	QDEC_EVENTS_ACCOF_EVENTS_ACCOF						(0x1u<<0)
#define	QDEC_EVENTS_ACCOF_EVENTS_ACCOF_NOTGENERATED			(0x0u<<0)
#define	QDEC_EVENTS_ACCOF_EVENTS_ACCOF_GENERATED			(0x1u<<0)

// EVENTS_DBLRDY Configuration

#define	QDEC_EVENTS_DBLRDY_EVENTS_DBLRDY					(0x1u<<0)
#define	QDEC_EVENTS_DBLRDY_EVENTS_DBLRDY_NOTGENERATED		(0x0u<<0)
#define	QDEC_EVENTS_DBLRDY_EVENTS_DBLRDY_GENERATED			(0x1u<<0)

// EVENTS_STOPPED Configuration

#define	QDEC_EVENTS_STOPPED_EVENTS_STOPPED					(0x1u<<0)
#define	QDEC_EVENTS_STOPPED_EVENTS_STOPPED_NOTGENERATED		(0x0u<<0)
#define	QDEC_EVENTS_STOPPED_EVENTS_STOPPED_GENERATED		(0x1u<<0)

// PUBLISH_SAMPLERDY Configuration

#define	QDEC_PUBLISH_SAMPLERDY_EN							(0x1u<<31)
#define	QDEC_PUBLISH_SAMPLERDY_CHIDX						(0xFFu<<0)
#define	QDEC_PUBLISH_SAMPLERDY_CHIDX_0						(0x1u<<0)
#define	QDEC_PUBLISH_SAMPLERDY_EN_DISABLED					(0x0u<<31)
#define	QDEC_PUBLISH_SAMPLERDY_EN_ENABLED					(0x1u<<31)

// PUBLISH_REPORTRDY Configuration

#define	QDEC_PUBLISH_REPORTRDY_EN							(0x1u<<31)
#define	QDEC_PUBLISH_REPORTRDY_CHIDX						(0xFFu<<0)
#define	QDEC_PUBLISH_REPORTRDY_CHIDX_0						(0x1u<<0)
#define	QDEC_PUBLISH_REPORTRDY_EN_DISABLED					(0x0u<<31)
#define	QDEC_PUBLISH_REPORTRDY_EN_ENABLED					(0x1u<<31)

// PUBLISH_ACCOF Configuration

#define	QDEC_PUBLISH_ACCOF_EN								(0x1u<<31)
#define	QDEC_PUBLISH_ACCOF_CHIDX							(0xFFu<<0)
#define	QDEC_PUBLISH_ACCOF_CHIDX_0							(0x1u<<0)
#define	QDEC_PUBLISH_ACCOF_EN_DISABLED						(0x0u<<31)
#define	QDEC_PUBLISH_ACCOF_EN_ENABLED						(0x1u<<31)

// PUBLISH_DBLRDY Configuration

#define	QDEC_PUBLISH_DBLRDY_EN								(0x1u<<31)
#define	QDEC_PUBLISH_DBLRDY_CHIDX							(0xFFu<<0)
#define	QDEC_PUBLISH_DBLRDY_CHIDX_0							(0x1u<<0)
#define	QDEC_PUBLISH_DBLRDY_EN_DISABLED						(0x0u<<31)
#define	QDEC_PUBLISH_DBLRDY_EN_ENABLED						(0x1u<<31)

// PUBLISH_STOPPED Configuration

#define	QDEC_PUBLISH_STOPPED_EN								(0x1u<<31)
#define	QDEC_PUBLISH_STOPPED_CHIDX							(0xFFu<<0)
#define	QDEC_PUBLISH_STOPPED_CHIDX_0						(0x1u<<0)
#define	QDEC_PUBLISH_STOPPED_EN_DISABLED					(0x0u<<31)
#define	QDEC_PUBLISH_STOPPED_EN_ENABLED						(0x1u<<31)

// SHORTS Configuration

#define	QDEC_SHORTS_SAMPLERDY_READCLRACC					(0x1u<<6)
#define	QDEC_SHORTS_DBLRDY_STOP								(0x1u<<5)
#define	QDEC_SHORTS_DBLRDY_RDCLRDBL							(0x1u<<4)
#define	QDEC_SHORTS_REPORTRDY_STOP							(0x1u<<3)
#define	QDEC_SHORTS_REPORTRDY_RDCLRACC						(0x1u<<2)
#define	QDEC_SHORTS_SAMPLERDY_STOP							(0x1u<<1)
#define	QDEC_SHORTS_REPORTRDY_READCLRACC					(0x1u<<0)
#define	QDEC_SHORTS_SAMPLERDY_READCLRACC_DISABLED			(0x0u<<6)
#define	QDEC_SHORTS_SAMPLERDY_READCLRACC_ENABLED			(0x1u<<6)
#define	QDEC_SHORTS_DBLRDY_STOP_DISABLED					(0x0u<<5)
#define	QDEC_SHORTS_DBLRDY_STOP_ENABLED						(0x1u<<5)
#define	QDEC_SHORTS_DBLRDY_RDCLRDBL_DISABLED				(0x0u<<4)
#define	QDEC_SHORTS_DBLRDY_RDCLRDBL_ENABLED					(0x1u<<4)
#define	QDEC_SHORTS_REPORTRDY_STOP_DISABLED					(0x0u<<3)
#define	QDEC_SHORTS_REPORTRDY_STOP_ENABLED					(0x1u<<3)
#define	QDEC_SHORTS_REPORTRDY_RDCLRACC_DISABLED				(0x0u<<2)
#define	QDEC_SHORTS_REPORTRDY_RDCLRACC_ENABLED				(0x1u<<2)
#define	QDEC_SHORTS_SAMPLERDY_STOP_DISABLED					(0x0u<<1)
#define	QDEC_SHORTS_SAMPLERDY_STOP_ENABLED					(0x1u<<1)
#define	QDEC_SHORTS_REPORTRDY_READCLRACC_DISABLED			(0x0u<<0)
#define	QDEC_SHORTS_REPORTRDY_READCLRACC_ENABLED			(0x1u<<0)

// INTENSET Configuration

#define	QDEC_INTENSET_STOPPED								(0x1u<<4)
#define	QDEC_INTENSET_DBLRDY								(0x1u<<3)
#define	QDEC_INTENSET_ACCOF									(0x1u<<2)
#define	QDEC_INTENSET_REPORTRDY								(0x1u<<1)
#define	QDEC_INTENSET_SAMPLERDY								(0x1u<<0)
#define	QDEC_INTENSET_STOPPED_DISABLED						(0x0u<<4)
#define	QDEC_INTENSET_STOPPED_ENABLED						(0x1u<<4)
#define	QDEC_INTENSET_STOPPED_SET							(0x1u<<4)
#define	QDEC_INTENSET_DBLRDY_DISABLED						(0x0u<<3)
#define	QDEC_INTENSET_DBLRDY_ENABLED						(0x1u<<3)
#define	QDEC_INTENSET_DBLRDY_SET							(0x1u<<3)
#define	QDEC_INTENSET_ACCOF_DISABLED						(0x0u<<2)
#define	QDEC_INTENSET_ACCOF_ENABLED							(0x1u<<2)
#define	QDEC_INTENSET_ACCOF_SET								(0x1u<<2)
#define	QDEC_INTENSET_REPORTRDY_DISABLED					(0x0u<<1)
#define	QDEC_INTENSET_REPORTRDY_ENABLED						(0x1u<<1)
#define	QDEC_INTENSET_REPORTRDY_SET							(0x1u<<1)
#define	QDEC_INTENSET_SAMPLERDY_DISABLED					(0x0u<<0)
#define	QDEC_INTENSET_SAMPLERDY_ENABLED						(0x1u<<0)
#define	QDEC_INTENSET_SAMPLERDY_SET							(0x1u<<0)

// INTENCLR Configuration

#define	QDEC_INTENCLR_STOPPED								(0x1u<<4)
#define	QDEC_INTENCLR_DBLRDY								(0x1u<<3)
#define	QDEC_INTENCLR_ACCOF									(0x1u<<2)
#define	QDEC_INTENCLR_REPORTRDY								(0x1u<<1)
#define	QDEC_INTENCLR_SAMPLERDY								(0x1u<<0)
#define	QDEC_INTENCLR_STOPPED_DISABLED						(0x0u<<4)
#define	QDEC_INTENCLR_STOPPED_ENABLED						(0x1u<<4)
#define	QDEC_INTENCLR_STOPPED_CLEAR							(0x1u<<4)
#define	QDEC_INTENCLR_DBLRDY_DISABLED						(0x0u<<3)
#define	QDEC_INTENCLR_DBLRDY_ENABLED						(0x1u<<3)
#define	QDEC_INTENCLR_DBLRDY_CLEAR							(0x1u<<3)
#define	QDEC_INTENCLR_ACCOF_DISABLED						(0x0u<<2)
#define	QDEC_INTENCLR_ACCOF_ENABLED							(0x1u<<2)
#define	QDEC_INTENCLR_ACCOF_CLEAR							(0x1u<<2)
#define	QDEC_INTENCLR_REPORTRDY_DISABLED					(0x0u<<1)
#define	QDEC_INTENCLR_REPORTRDY_ENABLED						(0x1u<<1)
#define	QDEC_INTENCLR_REPORTRDY_CLEAR						(0x1u<<1)
#define	QDEC_INTENCLR_SAMPLERDY_DISABLED					(0x0u<<0)
#define	QDEC_INTENCLR_SAMPLERDY_ENABLED						(0x1u<<0)
#define	QDEC_INTENCLR_SAMPLERDY_CLEAR						(0x1u<<0)

// ENABLE Configuration

#define	QDEC_ENABLE_ENABLE									(0x1u<<0)
#define	QDEC_ENABLE_ENABLE_DISABLED							(0x0u<<0)
#define	QDEC_ENABLE_ENABLE_ENABLED							(0x1u<<0)

// LEDPOL Configuration

#define	QDEC_LEDPOL_LEDPOL									(0x1u<<0)
#define	QDEC_LEDPOL_LEDPOL_ACTIVELOW						(0x0u<<0)
#define	QDEC_LEDPOL_LEDPOL_ACTIVEHIGH						(0x1u<<0)

// SAMPLEPER Configuration

#define	QDEC_SAMPLEPER_SAMPLEPER							(0xFu<<0)
#define	QDEC_SAMPLEPER_SAMPLEPER_0							(0x1u<<0)
#define	QDEC_SAMPLEPER_SAMPLEPER_128US						(0x0u<<0)
#define	QDEC_SAMPLEPER_SAMPLEPER_256US						(0x1u<<0)
#define	QDEC_SAMPLEPER_SAMPLEPER_512US						(0x2u<<0)
#define	QDEC_SAMPLEPER_SAMPLEPER_1024US						(0x3u<<0)
#define	QDEC_SAMPLEPER_SAMPLEPER_2048US						(0x4u<<0)
#define	QDEC_SAMPLEPER_SAMPLEPER_4096US						(0x5u<<0)
#define	QDEC_SAMPLEPER_SAMPLEPER_8192US						(0x6u<<0)
#define	QDEC_SAMPLEPER_SAMPLEPER_16384US					(0x7u<<0)
#define	QDEC_SAMPLEPER_SAMPLEPER_32MS						(0x8u<<0)
#define	QDEC_SAMPLEPER_SAMPLEPER_65MS						(0x9u<<0)
#define	QDEC_SAMPLEPER_SAMPLEPER_131MS						(0xAu<<0)

// SAMPLE Configuration

#define	QDEC_SAMPLE_SAMPLE									(0xFFFFFFFFu<<0)
#define	QDEC_SAMPLE_SAMPLE_0								(0x1u<<0)

// REPORTPER Configuration

#define	QDEC_REPORTPER_REPORTPER							(0xFu<<0)
#define	QDEC_REPORTPER_REPORTPER_0							(0x1u<<0)
#define	QDEC_REPORTPER_REPORTPER_10SMPL						(0x0u<<0)
#define	QDEC_REPORTPER_REPORTPER_40SMPL						(0x1u<<0)
#define	QDEC_REPORTPER_REPORTPER_80SMPL						(0x2u<<0)
#define	QDEC_REPORTPER_REPORTPER_120SMPL					(0x3u<<0)
#define	QDEC_REPORTPER_REPORTPER_160SMPL					(0x4u<<0)
#define	QDEC_REPORTPER_REPORTPER_200SMPL					(0x5u<<0)
#define	QDEC_REPORTPER_REPORTPER_240SMPL					(0x6u<<0)
#define	QDEC_REPORTPER_REPORTPER_280SMPL					(0x7u<<0)
#define	QDEC_REPORTPER_REPORTPER_1SMPL						(0x8u<<0)

// ACC Configuration

#define	QDEC_ACC_ACC										(0xFFFFFFFFu<<0)
#define	QDEC_ACC_ACC_0										(0x1u<<0)

// ACCREAD Configuration

#define	QDEC_ACCREAD_ACCREAD								(0xFFFFFFFFu<<0)
#define	QDEC_ACCREAD_ACCREAD_0								(0x1u<<0)

// LED Configuration

#define	QDEC_PSEL_LED_CONNECT								(0x1u<<31)
#define	QDEC_PSEL_LED_PORT									(0x1u<<5)
#define	QDEC_PSEL_LED_PIN									(0x1Fu<<0)
#define	QDEC_PSEL_LED_PIN_0									(0x1u<<0)
#define	QDEC_PSEL_LED_CONNECT_DISCONNECTED					(0x1u<<31)
#define	QDEC_PSEL_LED_CONNECT_CONNECTED						(0x0u<<31)

// A Configuration

#define	QDEC_PSEL_A_CONNECT									(0x1u<<31)
#define	QDEC_PSEL_A_PORT									(0x1u<<5)
#define	QDEC_PSEL_A_PIN										(0x1Fu<<0)
#define	QDEC_PSEL_A_PIN_0									(0x1u<<0)
#define	QDEC_PSEL_A_CONNECT_DISCONNECTED					(0x1u<<31)
#define	QDEC_PSEL_A_CONNECT_CONNECTED						(0x0u<<31)

// B Configuration

#define	QDEC_PSEL_B_CONNECT									(0x1u<<31)
#define	QDEC_PSEL_B_PORT									(0x1u<<5)
#define	QDEC_PSEL_B_PIN										(0x1Fu<<0)
#define	QDEC_PSEL_B_PIN_0									(0x1u<<0)
#define	QDEC_PSEL_B_CONNECT_DISCONNECTED					(0x1u<<31)
#define	QDEC_PSEL_B_CONNECT_CONNECTED						(0x0u<<31)

// DBFEN Configuration

#define	QDEC_DBFEN_DBFEN									(0x1u<<0)
#define	QDEC_DBFEN_DBFEN_DISABLED							(0x0u<<0)
#define	QDEC_DBFEN_DBFEN_ENABLED							(0x1u<<0)

// LEDPRE Configuration

#define	QDEC_LEDPRE_LEDPRE									(0x1FFu<<0)
#define	QDEC_LEDPRE_LEDPRE_0								(0x1u<<0)

// ACCDBL Configuration

#define	QDEC_ACCDBL_ACCDBL									(0xFu<<0)
#define	QDEC_ACCDBL_ACCDBL_0								(0x1u<<0)

// ACCDBLREAD Configuration

#define	QDEC_ACCDBLREAD_ACCDBLREAD							(0xFu<<0)
#define	QDEC_ACCDBLREAD_ACCDBLREAD_0						(0x1u<<0)
