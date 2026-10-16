/*
; nrf5340_application_pdm.
; ========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_pdm equates.
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

// PDM address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	TASKS_START;
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	RESERVED0[30];
	volatile	uint32_t	SUBSCRIBE_START;
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	RESERVED1[30];
	volatile	uint32_t	EVENTS_STARTED;
	volatile	uint32_t	EVENTS_STOPPED;
	volatile	uint32_t	EVENTS_END;
	volatile	uint32_t	RESERVED2[29];
	volatile	uint32_t	PUBLISH_STARTED;
	volatile	uint32_t	PUBLISH_STOPPED;
	volatile	uint32_t	PUBLISH_END;
	volatile	uint32_t	RESERVED3[93];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED4[125];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	PDMCLKCTRL;
	volatile	uint32_t	MODE;
	volatile	uint32_t	RESERVED5[3];
	volatile	uint32_t	GAINL;
	volatile	uint32_t	GAINR;
	volatile	uint32_t	RATIO;
	volatile	uint32_t	RESERVED6[7];
	volatile	uint32_t	PSEL_CLK;
	volatile	uint32_t	PSEL_DIN;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	MCLKCONFIG;
	volatile	uint32_t	RESERVED8[4];
	volatile	uint32_t	SAMPLE_PTR;
	volatile	uint32_t	SAMPLE_MAXCNT;
} PDM_TypeDef;

#if (defined(__cplusplus))
#define	PDM0_NS	reinterpret_cast<PDM_TypeDef *>(0x40026000u)
#define	PDM0_S	reinterpret_cast<PDM_TypeDef *>(0x50026000u)

#else
#define	PDM0_NS	((PDM_TypeDef *)0x40026000u)
#define	PDM0_S	((PDM_TypeDef *)0x50026000u)
#endif

// TASKS_START Configuration

#define	PDM_TASKS_START_TASKS_START						(0x1u<<0)
#define	PDM_TASKS_START_TASKS_START_TRIGGER				(0x1u<<0)

// TASKS_STOP Configuration

#define	PDM_TASKS_STOP_TASKS_STOP						(0x1u<<0)
#define	PDM_TASKS_STOP_TASKS_STOP_TRIGGER				(0x1u<<0)

// SUBSCRIBE_START Configuration

#define	PDM_SUBSCRIBE_START_EN							(0x1u<<31)
#define	PDM_SUBSCRIBE_START_CHIDX						(0xFFu<<0)
#define	PDM_SUBSCRIBE_START_CHIDX_0						(0x1u<<0)
#define	PDM_SUBSCRIBE_START_EN_DISABLED					(0x0u<<31)
#define	PDM_SUBSCRIBE_START_EN_ENABLED					(0x1u<<31)

// SUBSCRIBE_STOP Configuration

#define	PDM_SUBSCRIBE_STOP_EN							(0x1u<<31)
#define	PDM_SUBSCRIBE_STOP_CHIDX						(0xFFu<<0)
#define	PDM_SUBSCRIBE_STOP_CHIDX_0						(0x1u<<0)
#define	PDM_SUBSCRIBE_STOP_EN_DISABLED					(0x0u<<31)
#define	PDM_SUBSCRIBE_STOP_EN_ENABLED					(0x1u<<31)

// EVENTS_STARTED Configuration

#define	PDM_EVENTS_STARTED_EVENTS_STARTED				(0x1u<<0)
#define	PDM_EVENTS_STARTED_EVENTS_STARTED_NOTGENERATED	(0x0u<<0)
#define	PDM_EVENTS_STARTED_EVENTS_STARTED_GENERATED		(0x1u<<0)

// EVENTS_STOPPED Configuration

#define	PDM_EVENTS_STOPPED_EVENTS_STOPPED				(0x1u<<0)
#define	PDM_EVENTS_STOPPED_EVENTS_STOPPED_NOTGENERATED	(0x0u<<0)
#define	PDM_EVENTS_STOPPED_EVENTS_STOPPED_GENERATED		(0x1u<<0)

// EVENTS_END Configuration

#define	PDM_EVENTS_END_EVENTS_END						(0x1u<<0)
#define	PDM_EVENTS_END_EVENTS_END_NOTGENERATED			(0x0u<<0)
#define	PDM_EVENTS_END_EVENTS_END_GENERATED				(0x1u<<0)

// PUBLISH_STARTED Configuration

#define	PDM_PUBLISH_STARTED_EN							(0x1u<<31)
#define	PDM_PUBLISH_STARTED_CHIDX						(0xFFu<<0)
#define	PDM_PUBLISH_STARTED_CHIDX_0						(0x1u<<0)
#define	PDM_PUBLISH_STARTED_EN_DISABLED					(0x0u<<31)
#define	PDM_PUBLISH_STARTED_EN_ENABLED					(0x1u<<31)

// PUBLISH_STOPPED Configuration

#define	PDM_PUBLISH_STOPPED_EN							(0x1u<<31)
#define	PDM_PUBLISH_STOPPED_CHIDX						(0xFFu<<0)
#define	PDM_PUBLISH_STOPPED_CHIDX_0						(0x1u<<0)
#define	PDM_PUBLISH_STOPPED_EN_DISABLED					(0x0u<<31)
#define	PDM_PUBLISH_STOPPED_EN_ENABLED					(0x1u<<31)

// PUBLISH_END Configuration

#define	PDM_PUBLISH_END_EN								(0x1u<<31)
#define	PDM_PUBLISH_END_CHIDX							(0xFFu<<0)
#define	PDM_PUBLISH_END_CHIDX_0							(0x1u<<0)
#define	PDM_PUBLISH_END_EN_DISABLED						(0x0u<<31)
#define	PDM_PUBLISH_END_EN_ENABLED						(0x1u<<31)

// INTEN Configuration

#define	PDM_INTEN_END									(0x1u<<2)
#define	PDM_INTEN_STOPPED								(0x1u<<1)
#define	PDM_INTEN_STARTED								(0x1u<<0)
#define	PDM_INTEN_END_DISABLED							(0x0u<<2)
#define	PDM_INTEN_END_ENABLED							(0x1u<<2)
#define	PDM_INTEN_STOPPED_DISABLED						(0x0u<<1)
#define	PDM_INTEN_STOPPED_ENABLED						(0x1u<<1)
#define	PDM_INTEN_STARTED_DISABLED						(0x0u<<0)
#define	PDM_INTEN_STARTED_ENABLED						(0x1u<<0)

// INTENSET Configuration

#define	PDM_INTENSET_END								(0x1u<<2)
#define	PDM_INTENSET_STOPPED							(0x1u<<1)
#define	PDM_INTENSET_STARTED							(0x1u<<0)
#define	PDM_INTENSET_END_DISABLED						(0x0u<<2)
#define	PDM_INTENSET_END_ENABLED						(0x1u<<2)
#define	PDM_INTENSET_END_SET							(0x1u<<2)
#define	PDM_INTENSET_STOPPED_DISABLED					(0x0u<<1)
#define	PDM_INTENSET_STOPPED_ENABLED					(0x1u<<1)
#define	PDM_INTENSET_STOPPED_SET						(0x1u<<1)
#define	PDM_INTENSET_STARTED_DISABLED					(0x0u<<0)
#define	PDM_INTENSET_STARTED_ENABLED					(0x1u<<0)
#define	PDM_INTENSET_STARTED_SET						(0x1u<<0)

// INTENCLR Configuration

#define	PDM_INTENCLR_END								(0x1u<<2)
#define	PDM_INTENCLR_STOPPED							(0x1u<<1)
#define	PDM_INTENCLR_STARTED							(0x1u<<0)
#define	PDM_INTENCLR_END_DISABLED						(0x0u<<2)
#define	PDM_INTENCLR_END_ENABLED						(0x1u<<2)
#define	PDM_INTENCLR_END_CLEAR							(0x1u<<2)
#define	PDM_INTENCLR_STOPPED_DISABLED					(0x0u<<1)
#define	PDM_INTENCLR_STOPPED_ENABLED					(0x1u<<1)
#define	PDM_INTENCLR_STOPPED_CLEAR						(0x1u<<1)
#define	PDM_INTENCLR_STARTED_DISABLED					(0x0u<<0)
#define	PDM_INTENCLR_STARTED_ENABLED					(0x1u<<0)
#define	PDM_INTENCLR_STARTED_CLEAR						(0x1u<<0)

// ENABLE Configuration

#define	PDM_ENABLE_ENABLE								(0x1u<<0)
#define	PDM_ENABLE_ENABLE_DISABLED						(0x0u<<0)
#define	PDM_ENABLE_ENABLE_ENABLED						(0x1u<<0)

// PDMCLKCTRL Configuration

#define	PDM_PDMCLKCTRL_FREQ								(0xFFFFFFFFu<<0)
#define	PDM_PDMCLKCTRL_FREQ_0							(0x1u<<0)
#define	PDM_PDMCLKCTRL_FREQ_1000K						(0x8000000u<<0)
#define	PDM_PDMCLKCTRL_FREQ_DEFAULT						(0x8400000u<<0)
#define	PDM_PDMCLKCTRL_FREQ_1067K						(0x8800000u<<0)
#define	PDM_PDMCLKCTRL_FREQ_1231K						(0x9800000u<<0)
#define	PDM_PDMCLKCTRL_FREQ_1280K						(0xA000000u<<0)
#define	PDM_PDMCLKCTRL_FREQ_1333K						(0xA800000u<<0)

// MODE Configuration

#define	PDM_MODE_EDGE									(0x1u<<1)
#define	PDM_MODE_OPERATION								(0x1u<<0)
#define	PDM_MODE_EDGE_LEFTFALLING						(0x0u<<1)
#define	PDM_MODE_EDGE_LEFTRISING						(0x1u<<1)
#define	PDM_MODE_OPERATION_STEREO						(0x0u<<0)
#define	PDM_MODE_OPERATION_MONO							(0x1u<<0)

// GAINL Configuration

#define	PDM_GAINL_GAINL									(0x7Fu<<0)
#define	PDM_GAINL_GAINL_0								(0x1u<<0)
#define	PDM_GAINL_GAINL_MINGAIN							(0x0u<<0)
#define	PDM_GAINL_GAINL_DEFAULTGAIN						(0x28u<<0)
#define	PDM_GAINL_GAINL_MAXGAIN							(0x50u<<0)

// GAINR Configuration

#define	PDM_GAINR_GAINR									(0x7Fu<<0)
#define	PDM_GAINR_GAINR_0								(0x1u<<0)
#define	PDM_GAINR_GAINR_MINGAIN							(0x0u<<0)
#define	PDM_GAINR_GAINR_DEFAULTGAIN						(0x28u<<0)
#define	PDM_GAINR_GAINR_MAXGAIN							(0x50u<<0)

// RATIO Configuration

#define	PDM_RATIO_RATIO									(0x1u<<0)
#define	PDM_RATIO_RATIO_RATIO64							(0x0u<<0)
#define	PDM_RATIO_RATIO_RATIO80							(0x1u<<0)

// CLK Configuration

#define	PDM_PSEL_CLK_CONNECT							(0x1u<<31)
#define	PDM_PSEL_CLK_PORT								(0x1u<<5)
#define	PDM_PSEL_CLK_PIN								(0x1Fu<<0)
#define	PDM_PSEL_CLK_PIN_0								(0x1u<<0)
#define	PDM_PSEL_CLK_CONNECT_DISCONNECTED				(0x1u<<31)
#define	PDM_PSEL_CLK_CONNECT_CONNECTED					(0x0u<<31)

// DIN Configuration

#define	PDM_PSEL_DIN_CONNECT							(0x1u<<31)
#define	PDM_PSEL_DIN_PORT								(0x1u<<5)
#define	PDM_PSEL_DIN_PIN								(0x1Fu<<0)
#define	PDM_PSEL_DIN_PIN_0								(0x1u<<0)
#define	PDM_PSEL_DIN_CONNECT_DISCONNECTED				(0x1u<<31)
#define	PDM_PSEL_DIN_CONNECT_CONNECTED					(0x0u<<31)

// MCLKCONFIG Configuration

#define	PDM_MCLKCONFIG_SRC								(0x1u<<0)
#define	PDM_MCLKCONFIG_SRC_PCLK32M						(0x0u<<0)
#define	PDM_MCLKCONFIG_SRC_ACLK							(0x1u<<0)

// PTR Configuration

#define	PDM_SAMPLE_PTR_SAMPLEPTR						(0xFFFFFFFFu<<0)
#define	PDM_SAMPLE_PTR_SAMPLEPTR_0						(0x1u<<0)

// MAXCNT Configuration

#define	PDM_SAMPLE_MAXCNT_BUFFSIZE						(0x7FFFu<<0)
#define	PDM_SAMPLE_MAXCNT_BUFFSIZE_0					(0x1u<<0)
