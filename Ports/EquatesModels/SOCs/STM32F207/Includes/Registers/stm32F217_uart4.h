/*
; stm32F217_uart4.
; ================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_uart4 equates.
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

// UART4 address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	SR;
	volatile	uint32_t	DR;
	volatile	uint32_t	BRR;
	volatile	uint32_t	CR1;
	volatile	uint32_t	CR2;
	volatile	uint32_t	CR3;
} UART4_TypeDef;

#if (defined(__cplusplus))
#define	UART4	reinterpret_cast<UART4_TypeDef *>(0x40004C00u)

#else
#define	UART4	((UART4_TypeDef *)0x40004C00u)
#endif

// SR Configuration

#define	UART4_SR_PE					(0x1u<<0)
#define	UART4_SR_FE					(0x1u<<1)
#define	UART4_SR_NF					(0x1u<<2)
#define	UART4_SR_ORE				(0x1u<<3)
#define	UART4_SR_IDLE				(0x1u<<4)
#define	UART4_SR_RXNE				(0x1u<<5)
#define	UART4_SR_TC					(0x1u<<6)
#define	UART4_SR_TXE				(0x1u<<7)
#define	UART4_SR_LBD				(0x1u<<8)

// DR Configuration

#define	UART4_DR_DR					(0x1FFu<<0)
#define	UART4_DR_DR_0				(0x1u<<0)

// BRR Configuration

#define	UART4_BRR_DIV_FRACTION		(0xFu<<0)
#define	UART4_BRR_DIV_FRACTION_0	(0x1u<<0)
#define	UART4_BRR_DIV_MANTISSA		(0xFFFu<<4)
#define	UART4_BRR_DIV_MANTISSA_0	(0x1u<<4)

// CR1 Configuration

#define	UART4_CR1_SBK				(0x1u<<0)
#define	UART4_CR1_RWU				(0x1u<<1)
#define	UART4_CR1_RE				(0x1u<<2)
#define	UART4_CR1_TE				(0x1u<<3)
#define	UART4_CR1_IDLEIE			(0x1u<<4)
#define	UART4_CR1_RXNEIE			(0x1u<<5)
#define	UART4_CR1_TCIE				(0x1u<<6)
#define	UART4_CR1_TXEIE				(0x1u<<7)
#define	UART4_CR1_PEIE				(0x1u<<8)
#define	UART4_CR1_PS				(0x1u<<9)
#define	UART4_CR1_PCE				(0x1u<<10)
#define	UART4_CR1_WAKE				(0x1u<<11)
#define	UART4_CR1_M					(0x1u<<12)
#define	UART4_CR1_UE				(0x1u<<13)
#define	UART4_CR1_OVER8				(0x1u<<15)

// CR2 Configuration

#define	UART4_CR2_ADD				(0xFu<<0)
#define	UART4_CR2_ADD_0				(0x1u<<0)
#define	UART4_CR2_LBDL				(0x1u<<5)
#define	UART4_CR2_LBDIE				(0x1u<<6)
#define	UART4_CR2_STOP				(0x3u<<12)
#define	UART4_CR2_STOP_0			(0x1u<<12)
#define	UART4_CR2_LINEN				(0x1u<<14)

// CR3 Configuration

#define	UART4_CR3_EIE				(0x1u<<0)
#define	UART4_CR3_IREN				(0x1u<<1)
#define	UART4_CR3_IRLP				(0x1u<<2)
#define	UART4_CR3_HDSEL				(0x1u<<3)
#define	UART4_CR3_DMAR				(0x1u<<6)
#define	UART4_CR3_DMAT				(0x1u<<7)
#define	UART4_CR3_ONEBIT			(0x1u<<11)
