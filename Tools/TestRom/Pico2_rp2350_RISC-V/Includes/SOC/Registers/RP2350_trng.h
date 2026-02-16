/*
; RP2350_trng.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_trng equates.
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

#include	<stdint.h>

// TRNG address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	RESERVED0[64];
	volatile	uint32_t	RNG_IMR;
	volatile	uint32_t	RNG_ISR;
	volatile	uint32_t	RNG_ICR;
	volatile	uint32_t	CONFIG;
	volatile	uint32_t	VALID;
	volatile	uint32_t	EHR_DATA0;
	volatile	uint32_t	EHR_DATA1;
	volatile	uint32_t	EHR_DATA2;
	volatile	uint32_t	EHR_DATA3;
	volatile	uint32_t	EHR_DATA4;
	volatile	uint32_t	EHR_DATA5;
	volatile	uint32_t	RND_SOURCE_ENABLE;
	volatile	uint32_t	SAMPLE_CNT1;
	volatile	uint32_t	AUTOCORR_STATISTIC;
	volatile	uint32_t	DEBUG_CONTROL;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	SW_RESET;
	volatile	uint32_t	RESERVED2[28];
	volatile	uint32_t	RNG_DEBUG_EN_INPUT;
	volatile	uint32_t	BUSY;
	volatile	uint32_t	RST_BITS_COUNTER;
	volatile	uint32_t	RNG_VERSION;
	volatile	uint32_t	RESERVED3[7];
	volatile	uint32_t	RNG_BIST_CNTR_0;
	volatile	uint32_t	RNG_BIST_CNTR_1;
	volatile	uint32_t	RNG_BIST_CNTR_2;
} TRNG_TypeDef;

#ifdef __cplusplus
#define	TRNG_NS	reinterpret_cast<TRNG_TypeDef *>(0x400F0000u)
#define	TRNG_S	reinterpret_cast<TRNG_TypeDef *>(0x400F0000u)
#else
#define	TRNG_NS	((TRNG_TypeDef *)0x400F0000u)
#define	TRNG_S	((TRNG_TypeDef *)0x400F0000u)
#endif

// RNG_IMR Configuration

#define	TRNG_RNG_IMR_EHR_VALID_INT_MASK				(0x1u<<0)
#define	TRNG_RNG_IMR_AUTOCORR_ERR_INT_MASK			(0x1u<<1)
#define	TRNG_RNG_IMR_CRNGT_ERR_INT_MASK				(0x1u<<2)
#define	TRNG_RNG_IMR_VN_ERR_INT_MASK				(0x1u<<3)
#define	TRNG_RNG_IMR_RESERVED						(0xFFFFFFFu<<4)
#define	TRNG_RNG_IMR_RESERVED_0						(0x1u<<4)

// RNG_ISR Configuration

#define	TRNG_RNG_ISR_EHR_VALID						(0x1u<<0)
#define	TRNG_RNG_ISR_AUTOCORR_ERR					(0x1u<<1)
#define	TRNG_RNG_ISR_CRNGT_ERR						(0x1u<<2)
#define	TRNG_RNG_ISR_VN_ERR							(0x1u<<3)
#define	TRNG_RNG_ISR_RESERVED						(0xFFFFFFFu<<4)
#define	TRNG_RNG_ISR_RESERVED_0						(0x1u<<4)

// RNG_ICR Configuration

#define	TRNG_RNG_ICR_EHR_VALID						(0x1u<<0)
#define	TRNG_RNG_ICR_AUTOCORR_ERR					(0x1u<<1)
#define	TRNG_RNG_ICR_CRNGT_ERR						(0x1u<<2)
#define	TRNG_RNG_ICR_VN_ERR							(0x1u<<3)
#define	TRNG_RNG_ICR_RESERVED						(0xFFFFFFFu<<4)
#define	TRNG_RNG_ICR_RESERVED_0						(0x1u<<4)

// CONFIG Configuration

#define	TRNG_CONFIG_RND_SRC_SEL						(0x3u<<0)
#define	TRNG_CONFIG_RND_SRC_SEL_0					(0x1u<<0)
#define	TRNG_CONFIG_RESERVED						(0x3FFFFFFFu<<2)
#define	TRNG_CONFIG_RESERVED_0						(0x1u<<2)

// VALID Configuration

#define	TRNG_VALID_EHR_VALID						(0x1u<<0)
#define	TRNG_VALID_RESERVED							(0x7FFFFFFFu<<1)
#define	TRNG_VALID_RESERVED_0						(0x1u<<1)

// EHR_DATA0 Configuration

#define	TRNG_EHR_DATA0_EHR_DATA0					(0xFFFFFFFFu<<0)
#define	TRNG_EHR_DATA0_EHR_DATA0_0					(0x1u<<0)

// EHR_DATA1 Configuration

#define	TRNG_EHR_DATA1_EHR_DATA1					(0xFFFFFFFFu<<0)
#define	TRNG_EHR_DATA1_EHR_DATA1_0					(0x1u<<0)

// EHR_DATA2 Configuration

#define	TRNG_EHR_DATA2_EHR_DATA2					(0xFFFFFFFFu<<0)
#define	TRNG_EHR_DATA2_EHR_DATA2_0					(0x1u<<0)

// EHR_DATA3 Configuration

#define	TRNG_EHR_DATA3_EHR_DATA3					(0xFFFFFFFFu<<0)
#define	TRNG_EHR_DATA3_EHR_DATA3_0					(0x1u<<0)

// EHR_DATA4 Configuration

#define	TRNG_EHR_DATA4_EHR_DATA4					(0xFFFFFFFFu<<0)
#define	TRNG_EHR_DATA4_EHR_DATA4_0					(0x1u<<0)

// EHR_DATA5 Configuration

#define	TRNG_EHR_DATA5_EHR_DATA5					(0xFFFFFFFFu<<0)
#define	TRNG_EHR_DATA5_EHR_DATA5_0					(0x1u<<0)

// RND_SOURCE_ENABLE Configuration

#define	TRNG_RND_SOURCE_ENABLE_RND_SRC_EN			(0x1u<<0)
#define	TRNG_RND_SOURCE_ENABLE_RESERVED				(0x7FFFFFFFu<<1)
#define	TRNG_RND_SOURCE_ENABLE_RESERVED_0			(0x1u<<1)

// SAMPLE_CNT1 Configuration

#define	TRNG_SAMPLE_CNT1_SAMPLE_CNTR1				(0xFFFFFFFFu<<0)
#define	TRNG_SAMPLE_CNT1_SAMPLE_CNTR1_0				(0x1u<<0)

// AUTOCORR_STATISTIC Configuration

#define	TRNG_AUTOCORR_STATISTIC_AUTOCORR_TRYS		(0x3FFFu<<0)
#define	TRNG_AUTOCORR_STATISTIC_AUTOCORR_TRYS_0		(0x1u<<0)
#define	TRNG_AUTOCORR_STATISTIC_AUTOCORR_FAILS		(0xFFu<<14)
#define	TRNG_AUTOCORR_STATISTIC_AUTOCORR_FAILS_0	(0x1u<<14)
#define	TRNG_AUTOCORR_STATISTIC_RESERVED			(0x3FFu<<22)
#define	TRNG_AUTOCORR_STATISTIC_RESERVED_0			(0x1u<<22)

// DEBUG_CONTROL Configuration

#define	TRNG_DEBUG_CONTROL_RESERVED					(0x1u<<0)
#define	TRNG_DEBUG_CONTROL_VNC_BYPASS				(0x1u<<1)
#define	TRNG_DEBUG_CONTROL_TRNG_CRNGT_BYPASS		(0x1u<<2)
#define	TRNG_DEBUG_CONTROL_AUTO_CORRELATE_BYPASS	(0x1u<<3)

// SW_RESET Configuration

#define	TRNG_SW_RESET_TRNG_SW_RESET					(0x1u<<0)
#define	TRNG_SW_RESET_RESERVED						(0x7FFFFFFFu<<1)
#define	TRNG_SW_RESET_RESERVED_0					(0x1u<<1)

// RNG_DEBUG_EN_INPUT Configuration

#define	TRNG_RNG_DEBUG_EN_INPUT_RNG_DEBUG_EN		(0x1u<<0)
#define	TRNG_RNG_DEBUG_EN_INPUT_RESERVED			(0x7FFFFFFFu<<1)
#define	TRNG_RNG_DEBUG_EN_INPUT_RESERVED_0			(0x1u<<1)

// BUSY Configuration

#define	TRNG_BUSY_TRNG_BUSY							(0x1u<<0)
#define	TRNG_BUSY_RESERVED							(0x7FFFFFFFu<<1)
#define	TRNG_BUSY_RESERVED_0						(0x1u<<1)

// RST_BITS_COUNTER Configuration

#define	TRNG_RST_BITS_COUNTER_RST_BITS_COUNTER		(0x1u<<0)
#define	TRNG_RST_BITS_COUNTER_RESERVED				(0x7FFFFFFFu<<1)
#define	TRNG_RST_BITS_COUNTER_RESERVED_0			(0x1u<<1)

// RNG_VERSION Configuration

#define	TRNG_RNG_VERSION_EHR_WIDTH_192				(0x1u<<0)
#define	TRNG_RNG_VERSION_CRNGT_EXISTS				(0x1u<<1)
#define	TRNG_RNG_VERSION_AUTOCORR_EXISTS			(0x1u<<2)
#define	TRNG_RNG_VERSION_TRNG_TESTS_BYPASS_EN		(0x1u<<3)
#define	TRNG_RNG_VERSION_PRNG_EXISTS				(0x1u<<4)
#define	TRNG_RNG_VERSION_KAT_EXISTS					(0x1u<<5)
#define	TRNG_RNG_VERSION_RESEEDING_EXISTS			(0x1u<<6)
#define	TRNG_RNG_VERSION_RNG_USE_5_SBOXES			(0x1u<<7)
#define	TRNG_RNG_VERSION_RESERVED					(0xFFFFFFu<<8)
#define	TRNG_RNG_VERSION_RESERVED_0					(0x1u<<8)

// RNG_BIST_CNTR_0 Configuration

#define	TRNG_RNG_BIST_CNTR_0_ROSC_CNTR_VAL			(0x3FFFFFu<<0)
#define	TRNG_RNG_BIST_CNTR_0_ROSC_CNTR_VAL_0		(0x1u<<0)
#define	TRNG_RNG_BIST_CNTR_0_RESERVED				(0x3FFu<<22)
#define	TRNG_RNG_BIST_CNTR_0_RESERVED_0				(0x1u<<22)

// RNG_BIST_CNTR_1 Configuration

#define	TRNG_RNG_BIST_CNTR_1_ROSC_CNTR_VAL			(0x3FFFFFu<<0)
#define	TRNG_RNG_BIST_CNTR_1_ROSC_CNTR_VAL_0		(0x1u<<0)
#define	TRNG_RNG_BIST_CNTR_1_RESERVED				(0x3FFu<<22)
#define	TRNG_RNG_BIST_CNTR_1_RESERVED_0				(0x1u<<22)

// RNG_BIST_CNTR_2 Configuration

#define	TRNG_RNG_BIST_CNTR_2_ROSC_CNTR_VAL			(0x3FFFFFu<<0)
#define	TRNG_RNG_BIST_CNTR_2_ROSC_CNTR_VAL_0		(0x1u<<0)
#define	TRNG_RNG_BIST_CNTR_2_RESERVED				(0x3FFu<<22)
#define	TRNG_RNG_BIST_CNTR_2_RESERVED_0				(0x1u<<22)
