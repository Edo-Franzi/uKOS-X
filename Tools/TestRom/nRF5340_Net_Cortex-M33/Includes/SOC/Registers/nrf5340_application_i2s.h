/*
; nrf5340_application_i2s.
; ========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_i2s equates.
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

// I2S address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	TASKS_START;
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	RESERVED0[30];
	volatile	uint32_t	SUBSCRIBE_START;
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	RESERVED1[31];
	volatile	uint32_t	EVENTS_RXPTRUPD;
	volatile	uint32_t	EVENTS_STOPPED;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	EVENTS_TXPTRUPD;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	EVENTS_FRAMESTART;
	volatile	uint32_t	RESERVED4[25];
	volatile	uint32_t	PUBLISH_RXPTRUPD;
	volatile	uint32_t	PUBLISH_STOPPED;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	PUBLISH_TXPTRUPD;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	PUBLISH_FRAMESTART;
	volatile	uint32_t	RESERVED7[88];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED8[125];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	CONFIG_MODE;
	volatile	uint32_t	CONFIG_RXEN;
	volatile	uint32_t	CONFIG_TXEN;
	volatile	uint32_t	CONFIG_MCKEN;
	volatile	uint32_t	CONFIG_MCKFREQ;
	volatile	uint32_t	CONFIG_RATIO;
	volatile	uint32_t	CONFIG_SWIDTH;
	volatile	uint32_t	CONFIG_ALIGN;
	volatile	uint32_t	CONFIG_FORMAT;
	volatile	uint32_t	CONFIG_CHANNELS;
	volatile	uint32_t	CONFIG_CLKCONFIG;
	volatile	uint32_t	RESERVED9[2];
	volatile	uint32_t	RXD_PTR;
	volatile	uint32_t	RESERVED10;
	volatile	uint32_t	TXD_PTR;
	volatile	uint32_t	RESERVED11[3];
	volatile	uint32_t	RXTXD_MAXCNT;
	volatile	uint32_t	RESERVED12[3];
	volatile	uint32_t	PSEL_MCK;
	volatile	uint32_t	PSEL_SCK;
	volatile	uint32_t	PSEL_LRCK;
	volatile	uint32_t	PSEL_SDIN;
	volatile	uint32_t	PSEL_SDOUT;
} I2S_TypeDef;

#if (defined(__cplusplus))
#define	I2S0_NS	reinterpret_cast<I2S_TypeDef *>(0x40028000u)
#define	I2S0_S	reinterpret_cast<I2S_TypeDef *>(0x50028000u)

#else
#define	I2S0_NS	((I2S_TypeDef *)0x40028000u)
#define	I2S0_S	((I2S_TypeDef *)0x50028000u)
#endif

// TASKS_START Configuration

#define	I2S_TASKS_START_TASKS_START									(0x1u<<0)
#define	I2S_TASKS_START_TASKS_START_TRIGGER							(0x1u<<0)

// TASKS_STOP Configuration

#define	I2S_TASKS_STOP_TASKS_STOP									(0x1u<<0)
#define	I2S_TASKS_STOP_TASKS_STOP_TRIGGER							(0x1u<<0)

// SUBSCRIBE_START Configuration

#define	I2S_SUBSCRIBE_START_EN										(0x1u<<31)
#define	I2S_SUBSCRIBE_START_CHIDX									(0xFFu<<0)
#define	I2S_SUBSCRIBE_START_CHIDX_0									(0x1u<<0)
#define	I2S_SUBSCRIBE_START_EN_DISABLED								(0x0u<<31)
#define	I2S_SUBSCRIBE_START_EN_ENABLED								(0x1u<<31)

// SUBSCRIBE_STOP Configuration

#define	I2S_SUBSCRIBE_STOP_EN										(0x1u<<31)
#define	I2S_SUBSCRIBE_STOP_CHIDX									(0xFFu<<0)
#define	I2S_SUBSCRIBE_STOP_CHIDX_0									(0x1u<<0)
#define	I2S_SUBSCRIBE_STOP_EN_DISABLED								(0x0u<<31)
#define	I2S_SUBSCRIBE_STOP_EN_ENABLED								(0x1u<<31)

// EVENTS_RXPTRUPD Configuration

#define	I2S_EVENTS_RXPTRUPD_EVENTS_RXPTRUPD							(0x1u<<0)
#define	I2S_EVENTS_RXPTRUPD_EVENTS_RXPTRUPD_NOTGENERATED			(0x0u<<0)
#define	I2S_EVENTS_RXPTRUPD_EVENTS_RXPTRUPD_GENERATED				(0x1u<<0)

// EVENTS_STOPPED Configuration

#define	I2S_EVENTS_STOPPED_EVENTS_STOPPED							(0x1u<<0)
#define	I2S_EVENTS_STOPPED_EVENTS_STOPPED_NOTGENERATED				(0x0u<<0)
#define	I2S_EVENTS_STOPPED_EVENTS_STOPPED_GENERATED					(0x1u<<0)

// EVENTS_TXPTRUPD Configuration

#define	I2S_EVENTS_TXPTRUPD_EVENTS_TXPTRUPD							(0x1u<<0)
#define	I2S_EVENTS_TXPTRUPD_EVENTS_TXPTRUPD_NOTGENERATED			(0x0u<<0)
#define	I2S_EVENTS_TXPTRUPD_EVENTS_TXPTRUPD_GENERATED				(0x1u<<0)

// EVENTS_FRAMESTART Configuration

#define	I2S_EVENTS_FRAMESTART_EVENTS_FRAMESTART						(0x1u<<0)
#define	I2S_EVENTS_FRAMESTART_EVENTS_FRAMESTART_NOTGENERATED		(0x0u<<0)
#define	I2S_EVENTS_FRAMESTART_EVENTS_FRAMESTART_GENERATED			(0x1u<<0)

// PUBLISH_RXPTRUPD Configuration

#define	I2S_PUBLISH_RXPTRUPD_EN										(0x1u<<31)
#define	I2S_PUBLISH_RXPTRUPD_CHIDX									(0xFFu<<0)
#define	I2S_PUBLISH_RXPTRUPD_CHIDX_0								(0x1u<<0)
#define	I2S_PUBLISH_RXPTRUPD_EN_DISABLED							(0x0u<<31)
#define	I2S_PUBLISH_RXPTRUPD_EN_ENABLED								(0x1u<<31)

// PUBLISH_STOPPED Configuration

#define	I2S_PUBLISH_STOPPED_EN										(0x1u<<31)
#define	I2S_PUBLISH_STOPPED_CHIDX									(0xFFu<<0)
#define	I2S_PUBLISH_STOPPED_CHIDX_0									(0x1u<<0)
#define	I2S_PUBLISH_STOPPED_EN_DISABLED								(0x0u<<31)
#define	I2S_PUBLISH_STOPPED_EN_ENABLED								(0x1u<<31)

// PUBLISH_TXPTRUPD Configuration

#define	I2S_PUBLISH_TXPTRUPD_EN										(0x1u<<31)
#define	I2S_PUBLISH_TXPTRUPD_CHIDX									(0xFFu<<0)
#define	I2S_PUBLISH_TXPTRUPD_CHIDX_0								(0x1u<<0)
#define	I2S_PUBLISH_TXPTRUPD_EN_DISABLED							(0x0u<<31)
#define	I2S_PUBLISH_TXPTRUPD_EN_ENABLED								(0x1u<<31)

// PUBLISH_FRAMESTART Configuration

#define	I2S_PUBLISH_FRAMESTART_EN									(0x1u<<31)
#define	I2S_PUBLISH_FRAMESTART_CHIDX								(0xFFu<<0)
#define	I2S_PUBLISH_FRAMESTART_CHIDX_0								(0x1u<<0)
#define	I2S_PUBLISH_FRAMESTART_EN_DISABLED							(0x0u<<31)
#define	I2S_PUBLISH_FRAMESTART_EN_ENABLED							(0x1u<<31)

// INTEN Configuration

#define	I2S_INTEN_FRAMESTART										(0x1u<<7)
#define	I2S_INTEN_TXPTRUPD											(0x1u<<5)
#define	I2S_INTEN_STOPPED											(0x1u<<2)
#define	I2S_INTEN_RXPTRUPD											(0x1u<<1)
#define	I2S_INTEN_FRAMESTART_DISABLED								(0x0u<<7)
#define	I2S_INTEN_FRAMESTART_ENABLED								(0x1u<<7)
#define	I2S_INTEN_TXPTRUPD_DISABLED									(0x0u<<5)
#define	I2S_INTEN_TXPTRUPD_ENABLED									(0x1u<<5)
#define	I2S_INTEN_STOPPED_DISABLED									(0x0u<<2)
#define	I2S_INTEN_STOPPED_ENABLED									(0x1u<<2)
#define	I2S_INTEN_RXPTRUPD_DISABLED									(0x0u<<1)
#define	I2S_INTEN_RXPTRUPD_ENABLED									(0x1u<<1)

// INTENSET Configuration

#define	I2S_INTENSET_FRAMESTART										(0x1u<<7)
#define	I2S_INTENSET_TXPTRUPD										(0x1u<<5)
#define	I2S_INTENSET_STOPPED										(0x1u<<2)
#define	I2S_INTENSET_RXPTRUPD										(0x1u<<1)
#define	I2S_INTENSET_FRAMESTART_DISABLED							(0x0u<<7)
#define	I2S_INTENSET_FRAMESTART_ENABLED								(0x1u<<7)
#define	I2S_INTENSET_FRAMESTART_SET									(0x1u<<7)
#define	I2S_INTENSET_TXPTRUPD_DISABLED								(0x0u<<5)
#define	I2S_INTENSET_TXPTRUPD_ENABLED								(0x1u<<5)
#define	I2S_INTENSET_TXPTRUPD_SET									(0x1u<<5)
#define	I2S_INTENSET_STOPPED_DISABLED								(0x0u<<2)
#define	I2S_INTENSET_STOPPED_ENABLED								(0x1u<<2)
#define	I2S_INTENSET_STOPPED_SET									(0x1u<<2)
#define	I2S_INTENSET_RXPTRUPD_DISABLED								(0x0u<<1)
#define	I2S_INTENSET_RXPTRUPD_ENABLED								(0x1u<<1)
#define	I2S_INTENSET_RXPTRUPD_SET									(0x1u<<1)

// INTENCLR Configuration

#define	I2S_INTENCLR_FRAMESTART										(0x1u<<7)
#define	I2S_INTENCLR_TXPTRUPD										(0x1u<<5)
#define	I2S_INTENCLR_STOPPED										(0x1u<<2)
#define	I2S_INTENCLR_RXPTRUPD										(0x1u<<1)
#define	I2S_INTENCLR_FRAMESTART_DISABLED							(0x0u<<7)
#define	I2S_INTENCLR_FRAMESTART_ENABLED								(0x1u<<7)
#define	I2S_INTENCLR_FRAMESTART_CLEAR								(0x1u<<7)
#define	I2S_INTENCLR_TXPTRUPD_DISABLED								(0x0u<<5)
#define	I2S_INTENCLR_TXPTRUPD_ENABLED								(0x1u<<5)
#define	I2S_INTENCLR_TXPTRUPD_CLEAR									(0x1u<<5)
#define	I2S_INTENCLR_STOPPED_DISABLED								(0x0u<<2)
#define	I2S_INTENCLR_STOPPED_ENABLED								(0x1u<<2)
#define	I2S_INTENCLR_STOPPED_CLEAR									(0x1u<<2)
#define	I2S_INTENCLR_RXPTRUPD_DISABLED								(0x0u<<1)
#define	I2S_INTENCLR_RXPTRUPD_ENABLED								(0x1u<<1)
#define	I2S_INTENCLR_RXPTRUPD_CLEAR									(0x1u<<1)

// ENABLE Configuration

#define	I2S_ENABLE_ENABLE											(0x1u<<0)
#define	I2S_ENABLE_ENABLE_DISABLED									(0x0u<<0)
#define	I2S_ENABLE_ENABLE_ENABLED									(0x1u<<0)

// MODE Configuration

#define	I2S_CONFIG_MODE_MODE										(0x1u<<0)
#define	I2S_CONFIG_MODE_MODE_MASTER									(0x0u<<0)
#define	I2S_CONFIG_MODE_MODE_SLAVE									(0x1u<<0)

// RXEN Configuration

#define	I2S_CONFIG_RXEN_RXEN										(0x1u<<0)
#define	I2S_CONFIG_RXEN_RXEN_DISABLED								(0x0u<<0)
#define	I2S_CONFIG_RXEN_RXEN_ENABLED								(0x1u<<0)

// TXEN Configuration

#define	I2S_CONFIG_TXEN_TXEN										(0x1u<<0)
#define	I2S_CONFIG_TXEN_TXEN_DISABLED								(0x0u<<0)
#define	I2S_CONFIG_TXEN_TXEN_ENABLED								(0x1u<<0)

// MCKEN Configuration

#define	I2S_CONFIG_MCKEN_MCKEN										(0x1u<<0)
#define	I2S_CONFIG_MCKEN_MCKEN_DISABLED								(0x0u<<0)
#define	I2S_CONFIG_MCKEN_MCKEN_ENABLED								(0x1u<<0)

// MCKFREQ Configuration

#define	I2S_CONFIG_MCKFREQ_MCKFREQ									(0xFFFFFFFFu<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_0								(0x1u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV2							(0x80000000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV3							(0x50000000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV4							(0x40000000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV5							(0x30000000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV6							(0x28000000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV8							(0x20000000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV10							(0x18000000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV11							(0x16000000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV15							(0x11000000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV16							(0x10000000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV21							(0xC000000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV23							(0xB000000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV30							(0x8800000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV31							(0x8400000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV32							(0x8000000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV42							(0x6000000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV63							(0x4100000u<<0)
#define	I2S_CONFIG_MCKFREQ_MCKFREQ_32MDIV125						(0x20C0000u<<0)

// RATIO Configuration

#define	I2S_CONFIG_RATIO_RATIO										(0xFu<<0)
#define	I2S_CONFIG_RATIO_RATIO_0									(0x1u<<0)
#define	I2S_CONFIG_RATIO_RATIO_32X									(0x0u<<0)
#define	I2S_CONFIG_RATIO_RATIO_48X									(0x1u<<0)
#define	I2S_CONFIG_RATIO_RATIO_64X									(0x2u<<0)
#define	I2S_CONFIG_RATIO_RATIO_96X									(0x3u<<0)
#define	I2S_CONFIG_RATIO_RATIO_128X									(0x4u<<0)
#define	I2S_CONFIG_RATIO_RATIO_192X									(0x5u<<0)
#define	I2S_CONFIG_RATIO_RATIO_256X									(0x6u<<0)
#define	I2S_CONFIG_RATIO_RATIO_384X									(0x7u<<0)
#define	I2S_CONFIG_RATIO_RATIO_512X									(0x8u<<0)

// SWIDTH Configuration

#define	I2S_CONFIG_SWIDTH_SWIDTH									(0x7u<<0)
#define	I2S_CONFIG_SWIDTH_SWIDTH_0									(0x1u<<0)
#define	I2S_CONFIG_SWIDTH_SWIDTH_8BIT								(0x0u<<0)
#define	I2S_CONFIG_SWIDTH_SWIDTH_16BIT								(0x1u<<0)
#define	I2S_CONFIG_SWIDTH_SWIDTH_24BIT								(0x2u<<0)
#define	I2S_CONFIG_SWIDTH_SWIDTH_32BIT								(0x3u<<0)
#define	I2S_CONFIG_SWIDTH_SWIDTH_8BITIN16							(0x4u<<0)
#define	I2S_CONFIG_SWIDTH_SWIDTH_8BITIN32							(0x5u<<0)
#define	I2S_CONFIG_SWIDTH_SWIDTH_16BITIN32							(0x6u<<0)
#define	I2S_CONFIG_SWIDTH_SWIDTH_24BITIN32							(0x7u<<0)

// ALIGN Configuration

#define	I2S_CONFIG_ALIGN_ALIGN										(0x1u<<0)
#define	I2S_CONFIG_ALIGN_ALIGN_LEFT									(0x0u<<0)
#define	I2S_CONFIG_ALIGN_ALIGN_RIGHT								(0x1u<<0)

// FORMAT Configuration

#define	I2S_CONFIG_FORMAT_FORMAT									(0x1u<<0)
#define	I2S_CONFIG_FORMAT_FORMAT_I2S								(0x0u<<0)
#define	I2S_CONFIG_FORMAT_FORMAT_ALIGNED							(0x1u<<0)

// CHANNELS Configuration

#define	I2S_CONFIG_CHANNELS_CHANNELS								(0x3u<<0)
#define	I2S_CONFIG_CHANNELS_CHANNELS_0								(0x1u<<0)
#define	I2S_CONFIG_CHANNELS_CHANNELS_STEREO							(0x0u<<0)
#define	I2S_CONFIG_CHANNELS_CHANNELS_LEFT							(0x1u<<0)
#define	I2S_CONFIG_CHANNELS_CHANNELS_RIGHT							(0x2u<<0)

// CLKCONFIG Configuration

#define	I2S_CONFIG_CLKCONFIG_BYPASS									(0x1u<<8)
#define	I2S_CONFIG_CLKCONFIG_CLKSRC									(0x1u<<0)
#define	I2S_CONFIG_CLKCONFIG_BYPASS_DISABLE							(0x0u<<8)
#define	I2S_CONFIG_CLKCONFIG_BYPASS_ENABLE							(0x1u<<8)
#define	I2S_CONFIG_CLKCONFIG_CLKSRC_PCLK32M							(0x0u<<0)
#define	I2S_CONFIG_CLKCONFIG_CLKSRC_ACLK							(0x1u<<0)

// PTR Configuration

#define	I2S_RXD_PTR_PTR												(0xFFFFFFFFu<<0)
#define	I2S_RXD_PTR_PTR_0											(0x1u<<0)

// PTR Configuration

#define	I2S_TXD_PTR_PTR												(0xFFFFFFFFu<<0)
#define	I2S_TXD_PTR_PTR_0											(0x1u<<0)

// MAXCNT Configuration

#define	I2S_RXTXD_MAXCNT_MAXCNT										(0x3FFFu<<0)
#define	I2S_RXTXD_MAXCNT_MAXCNT_0									(0x1u<<0)

// MCK Configuration

#define	I2S_PSEL_MCK_CONNECT										(0x1u<<31)
#define	I2S_PSEL_MCK_PORT											(0x1u<<5)
#define	I2S_PSEL_MCK_PIN											(0x1Fu<<0)
#define	I2S_PSEL_MCK_PIN_0											(0x1u<<0)
#define	I2S_PSEL_MCK_CONNECT_DISCONNECTED							(0x1u<<31)
#define	I2S_PSEL_MCK_CONNECT_CONNECTED								(0x0u<<31)

// SCK Configuration

#define	I2S_PSEL_SCK_CONNECT										(0x1u<<31)
#define	I2S_PSEL_SCK_PORT											(0x1u<<5)
#define	I2S_PSEL_SCK_PIN											(0x1Fu<<0)
#define	I2S_PSEL_SCK_PIN_0											(0x1u<<0)
#define	I2S_PSEL_SCK_CONNECT_DISCONNECTED							(0x1u<<31)
#define	I2S_PSEL_SCK_CONNECT_CONNECTED								(0x0u<<31)

// LRCK Configuration

#define	I2S_PSEL_LRCK_CONNECT										(0x1u<<31)
#define	I2S_PSEL_LRCK_PORT											(0x1u<<5)
#define	I2S_PSEL_LRCK_PIN											(0x1Fu<<0)
#define	I2S_PSEL_LRCK_PIN_0											(0x1u<<0)
#define	I2S_PSEL_LRCK_CONNECT_DISCONNECTED							(0x1u<<31)
#define	I2S_PSEL_LRCK_CONNECT_CONNECTED								(0x0u<<31)

// SDIN Configuration

#define	I2S_PSEL_SDIN_CONNECT										(0x1u<<31)
#define	I2S_PSEL_SDIN_PORT											(0x1u<<5)
#define	I2S_PSEL_SDIN_PIN											(0x1Fu<<0)
#define	I2S_PSEL_SDIN_PIN_0											(0x1u<<0)
#define	I2S_PSEL_SDIN_CONNECT_DISCONNECTED							(0x1u<<31)
#define	I2S_PSEL_SDIN_CONNECT_CONNECTED								(0x0u<<31)

// SDOUT Configuration

#define	I2S_PSEL_SDOUT_CONNECT										(0x1u<<31)
#define	I2S_PSEL_SDOUT_PORT											(0x1u<<5)
#define	I2S_PSEL_SDOUT_PIN											(0x1Fu<<0)
#define	I2S_PSEL_SDOUT_PIN_0										(0x1u<<0)
#define	I2S_PSEL_SDOUT_CONNECT_DISCONNECTED							(0x1u<<31)
#define	I2S_PSEL_SDOUT_CONNECT_CONNECTED							(0x0u<<31)
