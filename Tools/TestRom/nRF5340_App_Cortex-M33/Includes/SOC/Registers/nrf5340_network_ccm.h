/*
; nrf5340_network_ccm.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_network_ccm equates.
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

// CCM address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	TASKS_KSGEN;
	volatile	uint32_t	TASKS_CRYPT;
	volatile	uint32_t	TASKS_STOP;
	volatile	uint32_t	TASKS_RATEOVERRIDE;
	volatile	uint32_t	RESERVED0[28];
	volatile	uint32_t	SUBSCRIBE_KSGEN;
	volatile	uint32_t	SUBSCRIBE_CRYPT;
	volatile	uint32_t	SUBSCRIBE_STOP;
	volatile	uint32_t	SUBSCRIBE_RATEOVERRIDE;
	volatile	uint32_t	RESERVED1[28];
	volatile	uint32_t	EVENTS_ENDKSGEN;
	volatile	uint32_t	EVENTS_ENDCRYPT;
	volatile	uint32_t	EVENTS_ERROR;
	volatile	uint32_t	RESERVED2[29];
	volatile	uint32_t	PUBLISH_ENDKSGEN;
	volatile	uint32_t	PUBLISH_ENDCRYPT;
	volatile	uint32_t	PUBLISH_ERROR;
	volatile	uint32_t	RESERVED3[29];
	volatile	uint32_t	SHORTS;
	volatile	uint32_t	RESERVED4[64];
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED5[61];
	volatile	uint32_t	MICSTATUS;
	volatile	uint32_t	RESERVED6[63];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	MODE;
	volatile	uint32_t	CNFPTR;
	volatile	uint32_t	INPTR;
	volatile	uint32_t	OUTPTR;
	volatile	uint32_t	SCRATCHPTR;
	volatile	uint32_t	MAXPACKETSIZE;
	volatile	uint32_t	RATEOVERRIDE;
	volatile	uint32_t	HEADERMASK;
} CCM_TypeDef;

#if (defined(__cplusplus))
#define	CCM_NS	reinterpret_cast<CCM_TypeDef *>(0x4100E000u)

#else
#define	CCM_NS	((CCM_TypeDef *)0x4100E000u)
#endif

// TASKS_KSGEN Configuration

#define	CCM_TASKS_KSGEN_TASKS_KSGEN							(0x1u<<0)
#define	CCM_TASKS_KSGEN_TASKS_KSGEN_TRIGGER					(0x1u<<0)

// TASKS_CRYPT Configuration

#define	CCM_TASKS_CRYPT_TASKS_CRYPT							(0x1u<<0)
#define	CCM_TASKS_CRYPT_TASKS_CRYPT_TRIGGER					(0x1u<<0)

// TASKS_STOP Configuration

#define	CCM_TASKS_STOP_TASKS_STOP							(0x1u<<0)
#define	CCM_TASKS_STOP_TASKS_STOP_TRIGGER					(0x1u<<0)

// TASKS_RATEOVERRIDE Configuration

#define	CCM_TASKS_RATEOVERRIDE_TASKS_RATEOVERRIDE			(0x1u<<0)
#define	CCM_TASKS_RATEOVERRIDE_TASKS_RATEOVERRIDE_TRIGGER	(0x1u<<0)

// SUBSCRIBE_KSGEN Configuration

#define	CCM_SUBSCRIBE_KSGEN_EN								(0x1u<<31)
#define	CCM_SUBSCRIBE_KSGEN_CHIDX							(0xFFu<<0)
#define	CCM_SUBSCRIBE_KSGEN_CHIDX_0							(0x1u<<0)
#define	CCM_SUBSCRIBE_KSGEN_EN_DISABLED						(0x0u<<31)
#define	CCM_SUBSCRIBE_KSGEN_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_CRYPT Configuration

#define	CCM_SUBSCRIBE_CRYPT_EN								(0x1u<<31)
#define	CCM_SUBSCRIBE_CRYPT_CHIDX							(0xFFu<<0)
#define	CCM_SUBSCRIBE_CRYPT_CHIDX_0							(0x1u<<0)
#define	CCM_SUBSCRIBE_CRYPT_EN_DISABLED						(0x0u<<31)
#define	CCM_SUBSCRIBE_CRYPT_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_STOP Configuration

#define	CCM_SUBSCRIBE_STOP_EN								(0x1u<<31)
#define	CCM_SUBSCRIBE_STOP_CHIDX							(0xFFu<<0)
#define	CCM_SUBSCRIBE_STOP_CHIDX_0							(0x1u<<0)
#define	CCM_SUBSCRIBE_STOP_EN_DISABLED						(0x0u<<31)
#define	CCM_SUBSCRIBE_STOP_EN_ENABLED						(0x1u<<31)

// SUBSCRIBE_RATEOVERRIDE Configuration

#define	CCM_SUBSCRIBE_RATEOVERRIDE_EN						(0x1u<<31)
#define	CCM_SUBSCRIBE_RATEOVERRIDE_CHIDX					(0xFFu<<0)
#define	CCM_SUBSCRIBE_RATEOVERRIDE_CHIDX_0					(0x1u<<0)
#define	CCM_SUBSCRIBE_RATEOVERRIDE_EN_DISABLED				(0x0u<<31)
#define	CCM_SUBSCRIBE_RATEOVERRIDE_EN_ENABLED				(0x1u<<31)

// EVENTS_ENDKSGEN Configuration

#define	CCM_EVENTS_ENDKSGEN_EVENTS_ENDKSGEN					(0x1u<<0)
#define	CCM_EVENTS_ENDKSGEN_EVENTS_ENDKSGEN_NOTGENERATED	(0x0u<<0)
#define	CCM_EVENTS_ENDKSGEN_EVENTS_ENDKSGEN_GENERATED		(0x1u<<0)

// EVENTS_ENDCRYPT Configuration

#define	CCM_EVENTS_ENDCRYPT_EVENTS_ENDCRYPT					(0x1u<<0)
#define	CCM_EVENTS_ENDCRYPT_EVENTS_ENDCRYPT_NOTGENERATED	(0x0u<<0)
#define	CCM_EVENTS_ENDCRYPT_EVENTS_ENDCRYPT_GENERATED		(0x1u<<0)

// EVENTS_ERROR Configuration

#define	CCM_EVENTS_ERROR_EVENTS_ERROR						(0x1u<<0)
#define	CCM_EVENTS_ERROR_EVENTS_ERROR_NOTGENERATED			(0x0u<<0)
#define	CCM_EVENTS_ERROR_EVENTS_ERROR_GENERATED				(0x1u<<0)

// PUBLISH_ENDKSGEN Configuration

#define	CCM_PUBLISH_ENDKSGEN_EN								(0x1u<<31)
#define	CCM_PUBLISH_ENDKSGEN_CHIDX							(0xFFu<<0)
#define	CCM_PUBLISH_ENDKSGEN_CHIDX_0						(0x1u<<0)
#define	CCM_PUBLISH_ENDKSGEN_EN_DISABLED					(0x0u<<31)
#define	CCM_PUBLISH_ENDKSGEN_EN_ENABLED						(0x1u<<31)

// PUBLISH_ENDCRYPT Configuration

#define	CCM_PUBLISH_ENDCRYPT_EN								(0x1u<<31)
#define	CCM_PUBLISH_ENDCRYPT_CHIDX							(0xFFu<<0)
#define	CCM_PUBLISH_ENDCRYPT_CHIDX_0						(0x1u<<0)
#define	CCM_PUBLISH_ENDCRYPT_EN_DISABLED					(0x0u<<31)
#define	CCM_PUBLISH_ENDCRYPT_EN_ENABLED						(0x1u<<31)

// PUBLISH_ERROR Configuration

#define	CCM_PUBLISH_ERROR_EN								(0x1u<<31)
#define	CCM_PUBLISH_ERROR_CHIDX								(0xFFu<<0)
#define	CCM_PUBLISH_ERROR_CHIDX_0							(0x1u<<0)
#define	CCM_PUBLISH_ERROR_EN_DISABLED						(0x0u<<31)
#define	CCM_PUBLISH_ERROR_EN_ENABLED						(0x1u<<31)

// SHORTS Configuration

#define	CCM_SHORTS_ENDKSGEN_CRYPT							(0x1u<<0)
#define	CCM_SHORTS_ENDKSGEN_CRYPT_DISABLED					(0x0u<<0)
#define	CCM_SHORTS_ENDKSGEN_CRYPT_ENABLED					(0x1u<<0)

// INTENSET Configuration

#define	CCM_INTENSET_ERROR									(0x1u<<2)
#define	CCM_INTENSET_ENDCRYPT								(0x1u<<1)
#define	CCM_INTENSET_ENDKSGEN								(0x1u<<0)
#define	CCM_INTENSET_ERROR_DISABLED							(0x0u<<2)
#define	CCM_INTENSET_ERROR_ENABLED							(0x1u<<2)
#define	CCM_INTENSET_ERROR_SET								(0x1u<<2)
#define	CCM_INTENSET_ENDCRYPT_DISABLED						(0x0u<<1)
#define	CCM_INTENSET_ENDCRYPT_ENABLED						(0x1u<<1)
#define	CCM_INTENSET_ENDCRYPT_SET							(0x1u<<1)
#define	CCM_INTENSET_ENDKSGEN_DISABLED						(0x0u<<0)
#define	CCM_INTENSET_ENDKSGEN_ENABLED						(0x1u<<0)
#define	CCM_INTENSET_ENDKSGEN_SET							(0x1u<<0)

// INTENCLR Configuration

#define	CCM_INTENCLR_ERROR									(0x1u<<2)
#define	CCM_INTENCLR_ENDCRYPT								(0x1u<<1)
#define	CCM_INTENCLR_ENDKSGEN								(0x1u<<0)
#define	CCM_INTENCLR_ERROR_DISABLED							(0x0u<<2)
#define	CCM_INTENCLR_ERROR_ENABLED							(0x1u<<2)
#define	CCM_INTENCLR_ERROR_CLEAR							(0x1u<<2)
#define	CCM_INTENCLR_ENDCRYPT_DISABLED						(0x0u<<1)
#define	CCM_INTENCLR_ENDCRYPT_ENABLED						(0x1u<<1)
#define	CCM_INTENCLR_ENDCRYPT_CLEAR							(0x1u<<1)
#define	CCM_INTENCLR_ENDKSGEN_DISABLED						(0x0u<<0)
#define	CCM_INTENCLR_ENDKSGEN_ENABLED						(0x1u<<0)
#define	CCM_INTENCLR_ENDKSGEN_CLEAR							(0x1u<<0)

// MICSTATUS Configuration

#define	CCM_MICSTATUS_MICSTATUS								(0x1u<<0)
#define	CCM_MICSTATUS_MICSTATUS_CHECKFAILED					(0x0u<<0)
#define	CCM_MICSTATUS_MICSTATUS_CHECKPASSED					(0x1u<<0)

// ENABLE Configuration

#define	CCM_ENABLE_ENABLE									(0x3u<<0)
#define	CCM_ENABLE_ENABLE_0									(0x1u<<0)
#define	CCM_ENABLE_ENABLE_DISABLED							(0x0u<<0)
#define	CCM_ENABLE_ENABLE_ENABLED							(0x2u<<0)

// MODE Configuration

#define	CCM_MODE_LENGTH										(0x1u<<24)
#define	CCM_MODE_DATARATE									(0x3u<<16)
#define	CCM_MODE_DATARATE_0									(0x1u<<16)
#define	CCM_MODE_MODE										(0x1u<<0)
#define	CCM_MODE_LENGTH_DEFAULT								(0x0u<<24)
#define	CCM_MODE_LENGTH_EXTENDED							(0x1u<<24)
#define	CCM_MODE_DATARATE_1MBIT								(0x0u<<16)
#define	CCM_MODE_DATARATE_2MBIT								(0x1u<<16)
#define	CCM_MODE_DATARATE_125KBPS							(0x2u<<16)
#define	CCM_MODE_DATARATE_500KBPS							(0x3u<<16)
#define	CCM_MODE_MODE_ENCRYPTION							(0x0u<<0)
#define	CCM_MODE_MODE_DECRYPTION							(0x1u<<0)

// CNFPTR Configuration

#define	CCM_CNFPTR_CNFPTR									(0xFFFFFFFFu<<0)
#define	CCM_CNFPTR_CNFPTR_0									(0x1u<<0)

// INPTR Configuration

#define	CCM_INPTR_INPTR										(0xFFFFFFFFu<<0)
#define	CCM_INPTR_INPTR_0									(0x1u<<0)

// OUTPTR Configuration

#define	CCM_OUTPTR_OUTPTR									(0xFFFFFFFFu<<0)
#define	CCM_OUTPTR_OUTPTR_0									(0x1u<<0)

// SCRATCHPTR Configuration

#define	CCM_SCRATCHPTR_SCRATCHPTR							(0xFFFFFFFFu<<0)
#define	CCM_SCRATCHPTR_SCRATCHPTR_0							(0x1u<<0)

// MAXPACKETSIZE Configuration

#define	CCM_MAXPACKETSIZE_MAXPACKETSIZE						(0xFFu<<0)
#define	CCM_MAXPACKETSIZE_MAXPACKETSIZE_0					(0x1u<<0)

// RATEOVERRIDE Configuration

#define	CCM_RATEOVERRIDE_RATEOVERRIDE						(0x3u<<0)
#define	CCM_RATEOVERRIDE_RATEOVERRIDE_0						(0x1u<<0)
#define	CCM_RATEOVERRIDE_RATEOVERRIDE_1MBIT					(0x0u<<0)
#define	CCM_RATEOVERRIDE_RATEOVERRIDE_2MBIT					(0x1u<<0)
#define	CCM_RATEOVERRIDE_RATEOVERRIDE_125KBPS				(0x2u<<0)
#define	CCM_RATEOVERRIDE_RATEOVERRIDE_500KBPS				(0x3u<<0)

// HEADERMASK Configuration

#define	CCM_HEADERMASK_HEADERMASK							(0xFFu<<0)
#define	CCM_HEADERMASK_HEADERMASK_0							(0x1u<<0)
