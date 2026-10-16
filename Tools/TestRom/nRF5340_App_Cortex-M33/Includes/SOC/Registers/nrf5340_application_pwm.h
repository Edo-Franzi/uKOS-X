/*
; nrf5340_application_pwm.
; ========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_pwm equates.
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

// PWM address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	TASKS_SEQSTART[2];
	volatile	uint32_t	TASKS_NEXTSTEP;
	volatile	uint32_t	RESERVED1[28];
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	SUBSCRIBE_SEQSTART[2];
	volatile	uint32_t	SUBSCRIBE_NEXTSTEP;
	volatile	uint32_t	RESERVED2[28];
	volatile	uint32_t	EVENTS_STOPPED;
	volatile	uint32_t	EVENTS_SEQSTARTED[2];
	volatile	uint32_t	EVENTS_SEQEND[2];
	volatile	uint32_t	EVENTS_PWMPERIODEND;
	volatile	uint32_t	EVENTS_LOOPSDONE;
	volatile	uint32_t	RESERVED3[25];
	volatile	uint32_t	PUBLISH_STOPPED;
	volatile	uint32_t	PUBLISH_SEQSTARTED[2];
	volatile	uint32_t	PUBLISH_SEQEND[2];
	volatile	uint32_t	PUBLISH_PWMPERIODEND;
	volatile	uint32_t	PUBLISH_LOOPSDONE;
	volatile	uint32_t	RESERVED4[24];
	volatile	uint32_t	SHORTS;
	volatile	uint32_t	RESERVED5[63];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED6[125];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	MODE;
	volatile	uint32_t	COUNTERTOP;
	volatile	uint32_t	PRESCALER;
	volatile	uint32_t	DECODER;
	volatile	uint32_t	LOOP;
	volatile	uint32_t	RESERVED7[2];
	volatile	uint32_t	SEQ0_PTR;
	volatile	uint32_t	SEQ0_CNT;
	volatile	uint32_t	SEQ0_REFRESH;
	volatile	uint32_t	SEQ0_ENDDELAY;
	volatile	uint32_t	RESERVED8[4];
	volatile	uint32_t	SEQ1_PTR;
	volatile	uint32_t	SEQ1_CNT;
	volatile	uint32_t	SEQ1_REFRESH;
	volatile	uint32_t	SEQ1_ENDDELAY;
	volatile	uint32_t	RESERVED9[4];
	volatile	uint32_t	PSEL_OUT[4];
} PWM_TypeDef;

#if (defined(__cplusplus))
#define	PWM0_NS	reinterpret_cast<PWM_TypeDef *>(0x40021000u)
#define	PWM0_S	reinterpret_cast<PWM_TypeDef *>(0x50021000u)
#define	PWM1_NS	reinterpret_cast<PWM_TypeDef *>(0x40022000u)
#define	PWM1_S	reinterpret_cast<PWM_TypeDef *>(0x50022000u)
#define	PWM2_NS	reinterpret_cast<PWM_TypeDef *>(0x40023000u)
#define	PWM2_S	reinterpret_cast<PWM_TypeDef *>(0x50023000u)
#define	PWM3_NS	reinterpret_cast<PWM_TypeDef *>(0x40024000u)
#define	PWM3_S	reinterpret_cast<PWM_TypeDef *>(0x50024000u)

#else
#define	PWM0_NS	((PWM_TypeDef *)0x40021000u)
#define	PWM0_S	((PWM_TypeDef *)0x50021000u)
#define	PWM1_NS	((PWM_TypeDef *)0x40022000u)
#define	PWM1_S	((PWM_TypeDef *)0x50022000u)
#define	PWM2_NS	((PWM_TypeDef *)0x40023000u)
#define	PWM2_S	((PWM_TypeDef *)0x50023000u)
#define	PWM3_NS	((PWM_TypeDef *)0x40024000u)
#define	PWM3_S	((PWM_TypeDef *)0x50024000u)
#endif

// TASKS_STOP Configuration

#define	PWM_TASKS_STOP_TASKS_STOP									(0x1u<<0)
#define	PWM_TASKS_STOP_TASKS_STOP_TRIGGER							(0x1u<<0)

// TASKS_SEQSTART Configuration

#define	PWM_TASKS_SEQSTART_TASKS_SEQSTART							(0x1u<<0)
#define	PWM_TASKS_SEQSTART_TASKS_SEQSTART_TRIGGER					(0x1u<<0)

// TASKS_NEXTSTEP Configuration

#define	PWM_TASKS_NEXTSTEP_TASKS_NEXTSTEP							(0x1u<<0)
#define	PWM_TASKS_NEXTSTEP_TASKS_NEXTSTEP_TRIGGER					(0x1u<<0)

// SUBSCRIBE_STOP Configuration

#define	PWM_SUBSCRIBE_STOP_EN										(0x1u<<31)
#define	PWM_SUBSCRIBE_STOP_CHIDX									(0xFFu<<0)
#define	PWM_SUBSCRIBE_STOP_CHIDX_0									(0x1u<<0)
#define	PWM_SUBSCRIBE_STOP_EN_DISABLED								(0x0u<<31)
#define	PWM_SUBSCRIBE_STOP_EN_ENABLED								(0x1u<<31)

// SUBSCRIBE_SEQSTART Configuration

#define	PWM_SUBSCRIBE_SEQSTART_EN									(0x1u<<31)
#define	PWM_SUBSCRIBE_SEQSTART_CHIDX								(0xFFu<<0)
#define	PWM_SUBSCRIBE_SEQSTART_CHIDX_0								(0x1u<<0)
#define	PWM_SUBSCRIBE_SEQSTART_EN_DISABLED							(0x0u<<31)
#define	PWM_SUBSCRIBE_SEQSTART_EN_ENABLED							(0x1u<<31)

// SUBSCRIBE_NEXTSTEP Configuration

#define	PWM_SUBSCRIBE_NEXTSTEP_EN									(0x1u<<31)
#define	PWM_SUBSCRIBE_NEXTSTEP_CHIDX								(0xFFu<<0)
#define	PWM_SUBSCRIBE_NEXTSTEP_CHIDX_0								(0x1u<<0)
#define	PWM_SUBSCRIBE_NEXTSTEP_EN_DISABLED							(0x0u<<31)
#define	PWM_SUBSCRIBE_NEXTSTEP_EN_ENABLED							(0x1u<<31)

// EVENTS_STOPPED Configuration

#define	PWM_EVENTS_STOPPED_EVENTS_STOPPED							(0x1u<<0)
#define	PWM_EVENTS_STOPPED_EVENTS_STOPPED_NOTGENERATED				(0x0u<<0)
#define	PWM_EVENTS_STOPPED_EVENTS_STOPPED_GENERATED					(0x1u<<0)

// EVENTS_SEQSTARTED Configuration

#define	PWM_EVENTS_SEQSTARTED_EVENTS_SEQSTARTED						(0x1u<<0)
#define	PWM_EVENTS_SEQSTARTED_EVENTS_SEQSTARTED_NOTGENERATED		(0x0u<<0)
#define	PWM_EVENTS_SEQSTARTED_EVENTS_SEQSTARTED_GENERATED			(0x1u<<0)

// EVENTS_SEQEND Configuration

#define	PWM_EVENTS_SEQEND_EVENTS_SEQEND								(0x1u<<0)
#define	PWM_EVENTS_SEQEND_EVENTS_SEQEND_NOTGENERATED				(0x0u<<0)
#define	PWM_EVENTS_SEQEND_EVENTS_SEQEND_GENERATED					(0x1u<<0)

// EVENTS_PWMPERIODEND Configuration

#define	PWM_EVENTS_PWMPERIODEND_EVENTS_PWMPERIODEND					(0x1u<<0)
#define	PWM_EVENTS_PWMPERIODEND_EVENTS_PWMPERIODEND_NOTGENERATED	(0x0u<<0)
#define	PWM_EVENTS_PWMPERIODEND_EVENTS_PWMPERIODEND_GENERATED		(0x1u<<0)

// EVENTS_LOOPSDONE Configuration

#define	PWM_EVENTS_LOOPSDONE_EVENTS_LOOPSDONE						(0x1u<<0)
#define	PWM_EVENTS_LOOPSDONE_EVENTS_LOOPSDONE_NOTGENERATED			(0x0u<<0)
#define	PWM_EVENTS_LOOPSDONE_EVENTS_LOOPSDONE_GENERATED				(0x1u<<0)

// PUBLISH_STOPPED Configuration

#define	PWM_PUBLISH_STOPPED_EN										(0x1u<<31)
#define	PWM_PUBLISH_STOPPED_CHIDX									(0xFFu<<0)
#define	PWM_PUBLISH_STOPPED_CHIDX_0									(0x1u<<0)
#define	PWM_PUBLISH_STOPPED_EN_DISABLED								(0x0u<<31)
#define	PWM_PUBLISH_STOPPED_EN_ENABLED								(0x1u<<31)

// PUBLISH_SEQSTARTED Configuration

#define	PWM_PUBLISH_SEQSTARTED_EN									(0x1u<<31)
#define	PWM_PUBLISH_SEQSTARTED_CHIDX								(0xFFu<<0)
#define	PWM_PUBLISH_SEQSTARTED_CHIDX_0								(0x1u<<0)
#define	PWM_PUBLISH_SEQSTARTED_EN_DISABLED							(0x0u<<31)
#define	PWM_PUBLISH_SEQSTARTED_EN_ENABLED							(0x1u<<31)

// PUBLISH_SEQEND Configuration

#define	PWM_PUBLISH_SEQEND_EN										(0x1u<<31)
#define	PWM_PUBLISH_SEQEND_CHIDX									(0xFFu<<0)
#define	PWM_PUBLISH_SEQEND_CHIDX_0									(0x1u<<0)
#define	PWM_PUBLISH_SEQEND_EN_DISABLED								(0x0u<<31)
#define	PWM_PUBLISH_SEQEND_EN_ENABLED								(0x1u<<31)

// PUBLISH_PWMPERIODEND Configuration

#define	PWM_PUBLISH_PWMPERIODEND_EN									(0x1u<<31)
#define	PWM_PUBLISH_PWMPERIODEND_CHIDX								(0xFFu<<0)
#define	PWM_PUBLISH_PWMPERIODEND_CHIDX_0							(0x1u<<0)
#define	PWM_PUBLISH_PWMPERIODEND_EN_DISABLED						(0x0u<<31)
#define	PWM_PUBLISH_PWMPERIODEND_EN_ENABLED							(0x1u<<31)

// PUBLISH_LOOPSDONE Configuration

#define	PWM_PUBLISH_LOOPSDONE_EN									(0x1u<<31)
#define	PWM_PUBLISH_LOOPSDONE_CHIDX									(0xFFu<<0)
#define	PWM_PUBLISH_LOOPSDONE_CHIDX_0								(0x1u<<0)
#define	PWM_PUBLISH_LOOPSDONE_EN_DISABLED							(0x0u<<31)
#define	PWM_PUBLISH_LOOPSDONE_EN_ENABLED							(0x1u<<31)

// SHORTS Configuration

#define	PWM_SHORTS_LOOPSDONE_STOP									(0x1u<<4)
#define	PWM_SHORTS_LOOPSDONE_SEQSTART1								(0x1u<<3)
#define	PWM_SHORTS_LOOPSDONE_SEQSTART0								(0x1u<<2)
#define	PWM_SHORTS_SEQEND1_STOP										(0x1u<<1)
#define	PWM_SHORTS_SEQEND0_STOP										(0x1u<<0)
#define	PWM_SHORTS_LOOPSDONE_STOP_DISABLED							(0x0u<<4)
#define	PWM_SHORTS_LOOPSDONE_STOP_ENABLED							(0x1u<<4)
#define	PWM_SHORTS_LOOPSDONE_SEQSTART1_DISABLED						(0x0u<<3)
#define	PWM_SHORTS_LOOPSDONE_SEQSTART1_ENABLED						(0x1u<<3)
#define	PWM_SHORTS_LOOPSDONE_SEQSTART0_DISABLED						(0x0u<<2)
#define	PWM_SHORTS_LOOPSDONE_SEQSTART0_ENABLED						(0x1u<<2)
#define	PWM_SHORTS_SEQEND1_STOP_DISABLED							(0x0u<<1)
#define	PWM_SHORTS_SEQEND1_STOP_ENABLED								(0x1u<<1)
#define	PWM_SHORTS_SEQEND0_STOP_DISABLED							(0x0u<<0)
#define	PWM_SHORTS_SEQEND0_STOP_ENABLED								(0x1u<<0)

// INTEN Configuration

#define	PWM_INTEN_LOOPSDONE											(0x1u<<7)
#define	PWM_INTEN_PWMPERIODEND										(0x1u<<6)
#define	PWM_INTEN_SEQEND1											(0x1u<<5)
#define	PWM_INTEN_SEQEND0											(0x1u<<4)
#define	PWM_INTEN_SEQSTARTED1										(0x1u<<3)
#define	PWM_INTEN_SEQSTARTED0										(0x1u<<2)
#define	PWM_INTEN_STOPPED											(0x1u<<1)
#define	PWM_INTEN_LOOPSDONE_DISABLED								(0x0u<<7)
#define	PWM_INTEN_LOOPSDONE_ENABLED									(0x1u<<7)
#define	PWM_INTEN_PWMPERIODEND_DISABLED								(0x0u<<6)
#define	PWM_INTEN_PWMPERIODEND_ENABLED								(0x1u<<6)
#define	PWM_INTEN_SEQEND1_DISABLED									(0x0u<<5)
#define	PWM_INTEN_SEQEND1_ENABLED									(0x1u<<5)
#define	PWM_INTEN_SEQEND0_DISABLED									(0x0u<<4)
#define	PWM_INTEN_SEQEND0_ENABLED									(0x1u<<4)
#define	PWM_INTEN_SEQSTARTED1_DISABLED								(0x0u<<3)
#define	PWM_INTEN_SEQSTARTED1_ENABLED								(0x1u<<3)
#define	PWM_INTEN_SEQSTARTED0_DISABLED								(0x0u<<2)
#define	PWM_INTEN_SEQSTARTED0_ENABLED								(0x1u<<2)
#define	PWM_INTEN_STOPPED_DISABLED									(0x0u<<1)
#define	PWM_INTEN_STOPPED_ENABLED									(0x1u<<1)

// INTENSET Configuration

#define	PWM_INTENSET_LOOPSDONE										(0x1u<<7)
#define	PWM_INTENSET_PWMPERIODEND									(0x1u<<6)
#define	PWM_INTENSET_SEQEND1										(0x1u<<5)
#define	PWM_INTENSET_SEQEND0										(0x1u<<4)
#define	PWM_INTENSET_SEQSTARTED1									(0x1u<<3)
#define	PWM_INTENSET_SEQSTARTED0									(0x1u<<2)
#define	PWM_INTENSET_STOPPED										(0x1u<<1)
#define	PWM_INTENSET_LOOPSDONE_DISABLED								(0x0u<<7)
#define	PWM_INTENSET_LOOPSDONE_ENABLED								(0x1u<<7)
#define	PWM_INTENSET_LOOPSDONE_SET									(0x1u<<7)
#define	PWM_INTENSET_PWMPERIODEND_DISABLED							(0x0u<<6)
#define	PWM_INTENSET_PWMPERIODEND_ENABLED							(0x1u<<6)
#define	PWM_INTENSET_PWMPERIODEND_SET								(0x1u<<6)
#define	PWM_INTENSET_SEQEND1_DISABLED								(0x0u<<5)
#define	PWM_INTENSET_SEQEND1_ENABLED								(0x1u<<5)
#define	PWM_INTENSET_SEQEND1_SET									(0x1u<<5)
#define	PWM_INTENSET_SEQEND0_DISABLED								(0x0u<<4)
#define	PWM_INTENSET_SEQEND0_ENABLED								(0x1u<<4)
#define	PWM_INTENSET_SEQEND0_SET									(0x1u<<4)
#define	PWM_INTENSET_SEQSTARTED1_DISABLED							(0x0u<<3)
#define	PWM_INTENSET_SEQSTARTED1_ENABLED							(0x1u<<3)
#define	PWM_INTENSET_SEQSTARTED1_SET								(0x1u<<3)
#define	PWM_INTENSET_SEQSTARTED0_DISABLED							(0x0u<<2)
#define	PWM_INTENSET_SEQSTARTED0_ENABLED							(0x1u<<2)
#define	PWM_INTENSET_SEQSTARTED0_SET								(0x1u<<2)
#define	PWM_INTENSET_STOPPED_DISABLED								(0x0u<<1)
#define	PWM_INTENSET_STOPPED_ENABLED								(0x1u<<1)
#define	PWM_INTENSET_STOPPED_SET									(0x1u<<1)

// INTENCLR Configuration

#define	PWM_INTENCLR_LOOPSDONE										(0x1u<<7)
#define	PWM_INTENCLR_PWMPERIODEND									(0x1u<<6)
#define	PWM_INTENCLR_SEQEND1										(0x1u<<5)
#define	PWM_INTENCLR_SEQEND0										(0x1u<<4)
#define	PWM_INTENCLR_SEQSTARTED1									(0x1u<<3)
#define	PWM_INTENCLR_SEQSTARTED0									(0x1u<<2)
#define	PWM_INTENCLR_STOPPED										(0x1u<<1)
#define	PWM_INTENCLR_LOOPSDONE_DISABLED								(0x0u<<7)
#define	PWM_INTENCLR_LOOPSDONE_ENABLED								(0x1u<<7)
#define	PWM_INTENCLR_LOOPSDONE_CLEAR								(0x1u<<7)
#define	PWM_INTENCLR_PWMPERIODEND_DISABLED							(0x0u<<6)
#define	PWM_INTENCLR_PWMPERIODEND_ENABLED							(0x1u<<6)
#define	PWM_INTENCLR_PWMPERIODEND_CLEAR								(0x1u<<6)
#define	PWM_INTENCLR_SEQEND1_DISABLED								(0x0u<<5)
#define	PWM_INTENCLR_SEQEND1_ENABLED								(0x1u<<5)
#define	PWM_INTENCLR_SEQEND1_CLEAR									(0x1u<<5)
#define	PWM_INTENCLR_SEQEND0_DISABLED								(0x0u<<4)
#define	PWM_INTENCLR_SEQEND0_ENABLED								(0x1u<<4)
#define	PWM_INTENCLR_SEQEND0_CLEAR									(0x1u<<4)
#define	PWM_INTENCLR_SEQSTARTED1_DISABLED							(0x0u<<3)
#define	PWM_INTENCLR_SEQSTARTED1_ENABLED							(0x1u<<3)
#define	PWM_INTENCLR_SEQSTARTED1_CLEAR								(0x1u<<3)
#define	PWM_INTENCLR_SEQSTARTED0_DISABLED							(0x0u<<2)
#define	PWM_INTENCLR_SEQSTARTED0_ENABLED							(0x1u<<2)
#define	PWM_INTENCLR_SEQSTARTED0_CLEAR								(0x1u<<2)
#define	PWM_INTENCLR_STOPPED_DISABLED								(0x0u<<1)
#define	PWM_INTENCLR_STOPPED_ENABLED								(0x1u<<1)
#define	PWM_INTENCLR_STOPPED_CLEAR									(0x1u<<1)

// ENABLE Configuration

#define	PWM_ENABLE_ENABLE											(0x1u<<0)
#define	PWM_ENABLE_ENABLE_DISABLED									(0x0u<<0)
#define	PWM_ENABLE_ENABLE_ENABLED									(0x1u<<0)

// MODE Configuration

#define	PWM_MODE_UPDOWN												(0x1u<<0)
#define	PWM_MODE_UPDOWN_UP											(0x0u<<0)
#define	PWM_MODE_UPDOWN_UPANDDOWN									(0x1u<<0)

// COUNTERTOP Configuration

#define	PWM_COUNTERTOP_COUNTERTOP									(0x7FFFu<<0)
#define	PWM_COUNTERTOP_COUNTERTOP_0									(0x1u<<0)

// PRESCALER Configuration

#define	PWM_PRESCALER_PRESCALER										(0x7u<<0)
#define	PWM_PRESCALER_PRESCALER_0									(0x1u<<0)
#define	PWM_PRESCALER_PRESCALER_DIV_1								(0x0u<<0)
#define	PWM_PRESCALER_PRESCALER_DIV_2								(0x1u<<0)
#define	PWM_PRESCALER_PRESCALER_DIV_4								(0x2u<<0)
#define	PWM_PRESCALER_PRESCALER_DIV_8								(0x3u<<0)
#define	PWM_PRESCALER_PRESCALER_DIV_16								(0x4u<<0)
#define	PWM_PRESCALER_PRESCALER_DIV_32								(0x5u<<0)
#define	PWM_PRESCALER_PRESCALER_DIV_64								(0x6u<<0)
#define	PWM_PRESCALER_PRESCALER_DIV_128								(0x7u<<0)

// DECODER Configuration

#define	PWM_DECODER_MODE											(0x1u<<8)
#define	PWM_DECODER_LOAD											(0x3u<<0)
#define	PWM_DECODER_LOAD_0											(0x1u<<0)
#define	PWM_DECODER_MODE_REFRESHCOUNT								(0x0u<<8)
#define	PWM_DECODER_MODE_NEXTSTEP									(0x1u<<8)
#define	PWM_DECODER_LOAD_COMMON										(0x0u<<0)
#define	PWM_DECODER_LOAD_GROUPED									(0x1u<<0)
#define	PWM_DECODER_LOAD_INDIVIDUAL									(0x2u<<0)
#define	PWM_DECODER_LOAD_WAVEFORM									(0x3u<<0)

// LOOP Configuration

#define	PWM_LOOP_CNT												(0xFFFFu<<0)
#define	PWM_LOOP_CNT_0												(0x1u<<0)
#define	PWM_LOOP_CNT_DISABLED										(0x0u<<0)

// PTR Configuration

#define	PWM_SEQ_PTR_PTR												(0xFFFFFFFFu<<0)
#define	PWM_SEQ_PTR_PTR_0											(0x1u<<0)

// CNT Configuration

#define	PWM_SEQ_CNT_CNT												(0x7FFFu<<0)
#define	PWM_SEQ_CNT_CNT_0											(0x1u<<0)
#define	PWM_SEQ_CNT_CNT_DISABLED									(0x0u<<0)

// REFRESH Configuration

#define	PWM_SEQ_REFRESH_CNT											(0xFFFFFFu<<0)
#define	PWM_SEQ_REFRESH_CNT_0										(0x1u<<0)
#define	PWM_SEQ_REFRESH_CNT_CONTINUOUS								(0x0u<<0)

// ENDDELAY Configuration

#define	PWM_SEQ_ENDDELAY_CNT										(0xFFFFFFu<<0)
#define	PWM_SEQ_ENDDELAY_CNT_0										(0x1u<<0)

// OUT Configuration

#define	PWM_PSEL_OUT_CONNECT										(0x1u<<31)
#define	PWM_PSEL_OUT_PORT											(0x1u<<5)
#define	PWM_PSEL_OUT_PIN											(0x1Fu<<0)
#define	PWM_PSEL_OUT_PIN_0											(0x1u<<0)
#define	PWM_PSEL_OUT_CONNECT_DISCONNECTED							(0x1u<<31)
#define	PWM_PSEL_OUT_CONNECT_CONNECTED								(0x0u<<31)
