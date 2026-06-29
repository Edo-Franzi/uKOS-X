/*
; stm32N657_rng.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_rng equates.
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

// RNG address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	DR;
	volatile	uint32_t	NSCR;
	volatile	uint32_t	HTCR;
} RNG_TypeDef;

#if (defined(__cplusplus))
#define	RNG_NS	reinterpret_cast<RNG_TypeDef *>(0x44020000u)
#define	RNG_S	reinterpret_cast<RNG_TypeDef *>(0x54020000u)

#else
#define	RNG_NS	((RNG_TypeDef *)0x44020000u)
#define	RNG_S	((RNG_TypeDef *)0x54020000u)
#endif

// CR Configuration

#define	RNG_CR_CONFIGLOCK		(0x1u<<31)
#define	RNG_CR_CONDRST			(0x1u<<30)
#define	RNG_CR_RNG_CONFIG1		(0x3Fu<<20)
#define	RNG_CR_RNG_CONFIG1_0	(0x1u<<20)
#define	RNG_CR_CLKDIV			(0xFu<<16)
#define	RNG_CR_CLKDIV_0			(0x1u<<16)
#define	RNG_CR_RNG_CONFIG2		(0x7u<<13)
#define	RNG_CR_RNG_CONFIG2_0	(0x1u<<13)
#define	RNG_CR_NISTC			(0x1u<<12)
#define	RNG_CR_RNG_CONFIG3		(0xFu<<8)
#define	RNG_CR_RNG_CONFIG3_0	(0x1u<<8)
#define	RNG_CR_ARDIS			(0x1u<<7)
#define	RNG_CR_CED				(0x1u<<5)
#define	RNG_CR_IE				(0x1u<<3)
#define	RNG_CR_RNGEN			(0x1u<<2)

#define	RNG_CR_CONFIGLOCK_B_0X0	(0x0u<<31)
#define	RNG_CR_CONFIGLOCK_B_0X1	(0x1u<<31)
#define	RNG_CR_CLKDIV_B_0X0		(0x0u<<16)
#define	RNG_CR_CLKDIV_B_0X1		(0x1u<<16)
#define	RNG_CR_CLKDIV_B_0X2		(0x2u<<16)
#define	RNG_CR_CLKDIV_B_0XF		(0xFu<<16)
#define	RNG_CR_NISTC_B_0X0		(0x0u<<12)
#define	RNG_CR_NISTC_B_0X1		(0x1u<<12)
#define	RNG_CR_ARDIS_B_0X0		(0x0u<<7)
#define	RNG_CR_ARDIS_B_0X1		(0x1u<<7)
#define	RNG_CR_CED_B_0X0		(0x0u<<5)
#define	RNG_CR_CED_B_0X1		(0x1u<<5)
#define	RNG_CR_IE_B_0X0			(0x0u<<3)
#define	RNG_CR_IE_B_0X1			(0x1u<<3)
#define	RNG_CR_RNGEN_B_0X0		(0x0u<<2)
#define	RNG_CR_RNGEN_B_0X1		(0x1u<<2)

// SR Configuration

#define	RNG_SR_SEIS				(0x1u<<6)
#define	RNG_SR_CEIS				(0x1u<<5)
#define	RNG_SR_SECS				(0x1u<<2)
#define	RNG_SR_CECS				(0x1u<<1)
#define	RNG_SR_DRDY				(0x1u<<0)

#define	RNG_SR_SEIS_B_0X0		(0x0u<<6)
#define	RNG_SR_SEIS_B_0X1		(0x1u<<6)
#define	RNG_SR_CEIS_B_0X0		(0x0u<<5)
#define	RNG_SR_CEIS_B_0X1		(0x1u<<5)
#define	RNG_SR_SECS_B_0X0		(0x0u<<2)
#define	RNG_SR_SECS_B_0X1		(0x1u<<2)
#define	RNG_SR_CECS_B_0X0		(0x0u<<1)
#define	RNG_SR_CECS_B_0X1		(0x1u<<1)
#define	RNG_SR_DRDY_B_0X0		(0x0u<<0)
#define	RNG_SR_DRDY_B_0X1		(0x1u<<0)

// DR Configuration

#define	RNG_DR_RNDATA			(0xFFFFFFFFu<<0)
#define	RNG_DR_RNDATA_0			(0x1u<<0)

// NSCR Configuration

#define	RNG_NSCR_EN_OSC6		(0x7u<<15)
#define	RNG_NSCR_EN_OSC6_0		(0x1u<<15)
#define	RNG_NSCR_EN_OSC5		(0x7u<<12)
#define	RNG_NSCR_EN_OSC5_0		(0x1u<<12)
#define	RNG_NSCR_EN_OSC4		(0x7u<<9)
#define	RNG_NSCR_EN_OSC4_0		(0x1u<<9)
#define	RNG_NSCR_EN_OSC3		(0x7u<<6)
#define	RNG_NSCR_EN_OSC3_0		(0x1u<<6)
#define	RNG_NSCR_EN_OSC2		(0x7u<<3)
#define	RNG_NSCR_EN_OSC2_0		(0x1u<<3)
#define	RNG_NSCR_EN_OSC1		(0x7u<<0)
#define	RNG_NSCR_EN_OSC1_0		(0x1u<<0)

// HTCR Configuration

#define	RNG_HTCR_HTCFG			(0xFFFFFFFFu<<0)
#define	RNG_HTCR_HTCFG_0		(0x1u<<0)
