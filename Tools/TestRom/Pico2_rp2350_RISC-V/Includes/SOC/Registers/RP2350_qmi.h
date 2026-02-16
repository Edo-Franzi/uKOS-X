/*
; RP2350_qmi.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_qmi equates.
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

// QMI address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	DIRECT_CSR;
	volatile	uint32_t	DIRECT_TX;
	volatile	uint32_t	DIRECT_RX;
	volatile	uint32_t	M0_TIMING;
	volatile	uint32_t	M0_RFMT;
	volatile	uint32_t	M0_RCMD;
	volatile	uint32_t	M0_WFMT;
	volatile	uint32_t	M0_WCMD;
	volatile	uint32_t	M1_TIMING;
	volatile	uint32_t	M1_RFMT;
	volatile	uint32_t	M1_RCMD;
	volatile	uint32_t	M1_WFMT;
	volatile	uint32_t	M1_WCMD;
	volatile	uint32_t	ATRANS0;
	volatile	uint32_t	ATRANS1;
	volatile	uint32_t	ATRANS2;
	volatile	uint32_t	ATRANS3;
	volatile	uint32_t	ATRANS4;
	volatile	uint32_t	ATRANS5;
	volatile	uint32_t	ATRANS6;
	volatile	uint32_t	ATRANS7;
} QMI_TypeDef;

#ifdef __cplusplus
#define	QMI_NS	reinterpret_cast<QMI_TypeDef *>(0x400D0000u)
#define	QMI_S	reinterpret_cast<QMI_TypeDef *>(0x400D0000u)
#else
#define	QMI_NS	((QMI_TypeDef *)0x400D0000u)
#define	QMI_S	((QMI_TypeDef *)0x400D0000u)
#endif

// DIRECT_CSR Configuration

#define	QMI_DIRECT_CSR_EN				(0x1u<<0)
#define	QMI_DIRECT_CSR_BUSY				(0x1u<<1)
#define	QMI_DIRECT_CSR_ASSERT_CS0N		(0x1u<<2)
#define	QMI_DIRECT_CSR_ASSERT_CS1N		(0x1u<<3)
#define	QMI_DIRECT_CSR_AUTO_CS0N		(0x1u<<6)
#define	QMI_DIRECT_CSR_AUTO_CS1N		(0x1u<<7)
#define	QMI_DIRECT_CSR_TXFULL			(0x1u<<10)
#define	QMI_DIRECT_CSR_TXEMPTY			(0x1u<<11)
#define	QMI_DIRECT_CSR_TXLEVEL			(0x7u<<12)
#define	QMI_DIRECT_CSR_TXLEVEL_0		(0x1u<<12)
#define	QMI_DIRECT_CSR_RXEMPTY			(0x1u<<16)
#define	QMI_DIRECT_CSR_RXFULL			(0x1u<<17)
#define	QMI_DIRECT_CSR_RXLEVEL			(0x7u<<18)
#define	QMI_DIRECT_CSR_RXLEVEL_0		(0x1u<<18)
#define	QMI_DIRECT_CSR_CLKDIV			(0xFFu<<22)
#define	QMI_DIRECT_CSR_CLKDIV_0			(0x1u<<22)
#define	QMI_DIRECT_CSR_RXDELAY			(0x3u<<30)
#define	QMI_DIRECT_CSR_RXDELAY_0		(0x1u<<30)

// DIRECT_TX Configuration

#define	QMI_DIRECT_TX_DATA				(0xFFFFu<<0)
#define	QMI_DIRECT_TX_DATA_0			(0x1u<<0)
#define	QMI_DIRECT_TX_IWIDTH			(0x3u<<16)
#define	QMI_DIRECT_TX_IWIDTH_0			(0x1u<<16)
#define	QMI_DIRECT_TX_DWIDTH			(0x1u<<18)
#define	QMI_DIRECT_TX_OE				(0x1u<<19)
#define	QMI_DIRECT_TX_NOPUSH			(0x1u<<20)
#define	QMI_DIRECT_TX_IWIDTH_S			(0x0u<<16)
#define	QMI_DIRECT_TX_IWIDTH_D			(0x1u<<16)
#define	QMI_DIRECT_TX_IWIDTH_Q			(0x2u<<16)

// DIRECT_RX Configuration

#define	QMI_DIRECT_RX_DIRECT_RX			(0xFFFFu<<0)
#define	QMI_DIRECT_RX_DIRECT_RX_0		(0x1u<<0)

// M0_TIMING Configuration

#define	QMI_M0_TIMING_CLKDIV			(0xFFu<<0)
#define	QMI_M0_TIMING_CLKDIV_0			(0x1u<<0)
#define	QMI_M0_TIMING_RXDELAY			(0x7u<<8)
#define	QMI_M0_TIMING_RXDELAY_0			(0x1u<<8)
#define	QMI_M0_TIMING_MIN_DESELECT		(0x1Fu<<12)
#define	QMI_M0_TIMING_MIN_DESELECT_0	(0x1u<<12)
#define	QMI_M0_TIMING_MAX_SELECT		(0x3Fu<<17)
#define	QMI_M0_TIMING_MAX_SELECT_0		(0x1u<<17)
#define	QMI_M0_TIMING_SELECT_HOLD		(0x3u<<23)
#define	QMI_M0_TIMING_SELECT_HOLD_0		(0x1u<<23)
#define	QMI_M0_TIMING_SELECT_SETUP		(0x1u<<25)
#define	QMI_M0_TIMING_PAGEBREAK			(0x3u<<28)
#define	QMI_M0_TIMING_PAGEBREAK_0		(0x1u<<28)
#define	QMI_M0_TIMING_COOLDOWN			(0x3u<<30)
#define	QMI_M0_TIMING_COOLDOWN_0		(0x1u<<30)
#define	QMI_M0_TIMING_PAGEBREAK_NONE	(0x0u<<28)
#define	QMI_M0_TIMING_PAGEBREAK_256		(0x1u<<28)
#define	QMI_M0_TIMING_PAGEBREAK_1024	(0x2u<<28)
#define	QMI_M0_TIMING_PAGEBREAK_4096	(0x3u<<28)

// M0_RFMT Configuration

#define	QMI_M0_RFMT_PREFIX_WIDTH		(0x3u<<0)
#define	QMI_M0_RFMT_PREFIX_WIDTH_0		(0x1u<<0)
#define	QMI_M0_RFMT_ADDR_WIDTH			(0x3u<<2)
#define	QMI_M0_RFMT_ADDR_WIDTH_0		(0x1u<<2)
#define	QMI_M0_RFMT_SUFFIX_WIDTH		(0x3u<<4)
#define	QMI_M0_RFMT_SUFFIX_WIDTH_0		(0x1u<<4)
#define	QMI_M0_RFMT_DUMMY_WIDTH			(0x3u<<6)
#define	QMI_M0_RFMT_DUMMY_WIDTH_0		(0x1u<<6)
#define	QMI_M0_RFMT_DATA_WIDTH			(0x3u<<8)
#define	QMI_M0_RFMT_DATA_WIDTH_0		(0x1u<<8)
#define	QMI_M0_RFMT_PREFIX_LEN			(0x1u<<12)
#define	QMI_M0_RFMT_SUFFIX_LEN			(0x3u<<14)
#define	QMI_M0_RFMT_SUFFIX_LEN_0		(0x1u<<14)
#define	QMI_M0_RFMT_DUMMY_LEN			(0x7u<<16)
#define	QMI_M0_RFMT_DUMMY_LEN_0			(0x1u<<16)
#define	QMI_M0_RFMT_DTR					(0x1u<<28)
#define	QMI_M0_RFMT_PREFIX_WIDTH_S		(0x0u<<0)
#define	QMI_M0_RFMT_PREFIX_WIDTH_D		(0x1u<<0)
#define	QMI_M0_RFMT_PREFIX_WIDTH_Q		(0x2u<<0)
#define	QMI_M0_RFMT_ADDR_WIDTH_S		(0x0u<<2)
#define	QMI_M0_RFMT_ADDR_WIDTH_D		(0x1u<<2)
#define	QMI_M0_RFMT_ADDR_WIDTH_Q		(0x2u<<2)
#define	QMI_M0_RFMT_SUFFIX_WIDTH_S		(0x0u<<4)
#define	QMI_M0_RFMT_SUFFIX_WIDTH_D		(0x1u<<4)
#define	QMI_M0_RFMT_SUFFIX_WIDTH_Q		(0x2u<<4)
#define	QMI_M0_RFMT_DUMMY_WIDTH_S		(0x0u<<6)
#define	QMI_M0_RFMT_DUMMY_WIDTH_D		(0x1u<<6)
#define	QMI_M0_RFMT_DUMMY_WIDTH_Q		(0x2u<<6)
#define	QMI_M0_RFMT_DATA_WIDTH_S		(0x0u<<8)
#define	QMI_M0_RFMT_DATA_WIDTH_D		(0x1u<<8)
#define	QMI_M0_RFMT_DATA_WIDTH_Q		(0x2u<<8)
#define	QMI_M0_RFMT_PREFIX_LEN_NONE		(0x0u<<12)
#define	QMI_M0_RFMT_PREFIX_LEN_8		(0x1u<<12)
#define	QMI_M0_RFMT_SUFFIX_LEN_NONE		(0x0u<<14)
#define	QMI_M0_RFMT_SUFFIX_LEN_8		(0x2u<<14)
#define	QMI_M0_RFMT_DUMMY_LEN_NONE		(0x0u<<16)
#define	QMI_M0_RFMT_DUMMY_LEN_4			(0x1u<<16)
#define	QMI_M0_RFMT_DUMMY_LEN_8			(0x2u<<16)
#define	QMI_M0_RFMT_DUMMY_LEN_12		(0x3u<<16)
#define	QMI_M0_RFMT_DUMMY_LEN_16		(0x4u<<16)
#define	QMI_M0_RFMT_DUMMY_LEN_20		(0x5u<<16)
#define	QMI_M0_RFMT_DUMMY_LEN_24		(0x6u<<16)
#define	QMI_M0_RFMT_DUMMY_LEN_28		(0x7u<<16)

// M0_RCMD Configuration

#define	QMI_M0_RCMD_PREFIX				(0xFFu<<0)
#define	QMI_M0_RCMD_PREFIX_0			(0x1u<<0)
#define	QMI_M0_RCMD_SUFFIX				(0xFFu<<8)
#define	QMI_M0_RCMD_SUFFIX_0			(0x1u<<8)

// M0_WFMT Configuration

#define	QMI_M0_WFMT_PREFIX_WIDTH		(0x3u<<0)
#define	QMI_M0_WFMT_PREFIX_WIDTH_0		(0x1u<<0)
#define	QMI_M0_WFMT_ADDR_WIDTH			(0x3u<<2)
#define	QMI_M0_WFMT_ADDR_WIDTH_0		(0x1u<<2)
#define	QMI_M0_WFMT_SUFFIX_WIDTH		(0x3u<<4)
#define	QMI_M0_WFMT_SUFFIX_WIDTH_0		(0x1u<<4)
#define	QMI_M0_WFMT_DUMMY_WIDTH			(0x3u<<6)
#define	QMI_M0_WFMT_DUMMY_WIDTH_0		(0x1u<<6)
#define	QMI_M0_WFMT_DATA_WIDTH			(0x3u<<8)
#define	QMI_M0_WFMT_DATA_WIDTH_0		(0x1u<<8)
#define	QMI_M0_WFMT_PREFIX_LEN			(0x1u<<12)
#define	QMI_M0_WFMT_SUFFIX_LEN			(0x3u<<14)
#define	QMI_M0_WFMT_SUFFIX_LEN_0		(0x1u<<14)
#define	QMI_M0_WFMT_DUMMY_LEN			(0x7u<<16)
#define	QMI_M0_WFMT_DUMMY_LEN_0			(0x1u<<16)
#define	QMI_M0_WFMT_DTR					(0x1u<<28)
#define	QMI_M0_WFMT_PREFIX_WIDTH_S		(0x0u<<0)
#define	QMI_M0_WFMT_PREFIX_WIDTH_D		(0x1u<<0)
#define	QMI_M0_WFMT_PREFIX_WIDTH_Q		(0x2u<<0)
#define	QMI_M0_WFMT_ADDR_WIDTH_S		(0x0u<<2)
#define	QMI_M0_WFMT_ADDR_WIDTH_D		(0x1u<<2)
#define	QMI_M0_WFMT_ADDR_WIDTH_Q		(0x2u<<2)
#define	QMI_M0_WFMT_SUFFIX_WIDTH_S		(0x0u<<4)
#define	QMI_M0_WFMT_SUFFIX_WIDTH_D		(0x1u<<4)
#define	QMI_M0_WFMT_SUFFIX_WIDTH_Q		(0x2u<<4)
#define	QMI_M0_WFMT_DUMMY_WIDTH_S		(0x0u<<6)
#define	QMI_M0_WFMT_DUMMY_WIDTH_D		(0x1u<<6)
#define	QMI_M0_WFMT_DUMMY_WIDTH_Q		(0x2u<<6)
#define	QMI_M0_WFMT_DATA_WIDTH_S		(0x0u<<8)
#define	QMI_M0_WFMT_DATA_WIDTH_D		(0x1u<<8)
#define	QMI_M0_WFMT_DATA_WIDTH_Q		(0x2u<<8)
#define	QMI_M0_WFMT_PREFIX_LEN_NONE		(0x0u<<12)
#define	QMI_M0_WFMT_PREFIX_LEN_8		(0x1u<<12)
#define	QMI_M0_WFMT_SUFFIX_LEN_NONE		(0x0u<<14)
#define	QMI_M0_WFMT_SUFFIX_LEN_8		(0x2u<<14)
#define	QMI_M0_WFMT_DUMMY_LEN_NONE		(0x0u<<16)
#define	QMI_M0_WFMT_DUMMY_LEN_4			(0x1u<<16)
#define	QMI_M0_WFMT_DUMMY_LEN_8			(0x2u<<16)
#define	QMI_M0_WFMT_DUMMY_LEN_12		(0x3u<<16)
#define	QMI_M0_WFMT_DUMMY_LEN_16		(0x4u<<16)
#define	QMI_M0_WFMT_DUMMY_LEN_20		(0x5u<<16)
#define	QMI_M0_WFMT_DUMMY_LEN_24		(0x6u<<16)
#define	QMI_M0_WFMT_DUMMY_LEN_28		(0x7u<<16)

// M0_WCMD Configuration

#define	QMI_M0_WCMD_PREFIX				(0xFFu<<0)
#define	QMI_M0_WCMD_PREFIX_0			(0x1u<<0)
#define	QMI_M0_WCMD_SUFFIX				(0xFFu<<8)
#define	QMI_M0_WCMD_SUFFIX_0			(0x1u<<8)

// M1_TIMING Configuration

#define	QMI_M1_TIMING_CLKDIV			(0xFFu<<0)
#define	QMI_M1_TIMING_CLKDIV_0			(0x1u<<0)
#define	QMI_M1_TIMING_RXDELAY			(0x7u<<8)
#define	QMI_M1_TIMING_RXDELAY_0			(0x1u<<8)
#define	QMI_M1_TIMING_MIN_DESELECT		(0x1Fu<<12)
#define	QMI_M1_TIMING_MIN_DESELECT_0	(0x1u<<12)
#define	QMI_M1_TIMING_MAX_SELECT		(0x3Fu<<17)
#define	QMI_M1_TIMING_MAX_SELECT_0		(0x1u<<17)
#define	QMI_M1_TIMING_SELECT_HOLD		(0x3u<<23)
#define	QMI_M1_TIMING_SELECT_HOLD_0		(0x1u<<23)
#define	QMI_M1_TIMING_SELECT_SETUP		(0x1u<<25)
#define	QMI_M1_TIMING_PAGEBREAK			(0x3u<<28)
#define	QMI_M1_TIMING_PAGEBREAK_0		(0x1u<<28)
#define	QMI_M1_TIMING_COOLDOWN			(0x3u<<30)
#define	QMI_M1_TIMING_COOLDOWN_0		(0x1u<<30)
#define	QMI_M1_TIMING_PAGEBREAK_NONE	(0x0u<<28)
#define	QMI_M1_TIMING_PAGEBREAK_256		(0x1u<<28)
#define	QMI_M1_TIMING_PAGEBREAK_1024	(0x2u<<28)
#define	QMI_M1_TIMING_PAGEBREAK_4096	(0x3u<<28)

// M1_RFMT Configuration

#define	QMI_M1_RFMT_PREFIX_WIDTH		(0x3u<<0)
#define	QMI_M1_RFMT_PREFIX_WIDTH_0		(0x1u<<0)
#define	QMI_M1_RFMT_ADDR_WIDTH			(0x3u<<2)
#define	QMI_M1_RFMT_ADDR_WIDTH_0		(0x1u<<2)
#define	QMI_M1_RFMT_SUFFIX_WIDTH		(0x3u<<4)
#define	QMI_M1_RFMT_SUFFIX_WIDTH_0		(0x1u<<4)
#define	QMI_M1_RFMT_DUMMY_WIDTH			(0x3u<<6)
#define	QMI_M1_RFMT_DUMMY_WIDTH_0		(0x1u<<6)
#define	QMI_M1_RFMT_DATA_WIDTH			(0x3u<<8)
#define	QMI_M1_RFMT_DATA_WIDTH_0		(0x1u<<8)
#define	QMI_M1_RFMT_PREFIX_LEN			(0x1u<<12)
#define	QMI_M1_RFMT_SUFFIX_LEN			(0x3u<<14)
#define	QMI_M1_RFMT_SUFFIX_LEN_0		(0x1u<<14)
#define	QMI_M1_RFMT_DUMMY_LEN			(0x7u<<16)
#define	QMI_M1_RFMT_DUMMY_LEN_0			(0x1u<<16)
#define	QMI_M1_RFMT_DTR					(0x1u<<28)
#define	QMI_M1_RFMT_PREFIX_WIDTH_S		(0x0u<<0)
#define	QMI_M1_RFMT_PREFIX_WIDTH_D		(0x1u<<0)
#define	QMI_M1_RFMT_PREFIX_WIDTH_Q		(0x2u<<0)
#define	QMI_M1_RFMT_ADDR_WIDTH_S		(0x0u<<2)
#define	QMI_M1_RFMT_ADDR_WIDTH_D		(0x1u<<2)
#define	QMI_M1_RFMT_ADDR_WIDTH_Q		(0x2u<<2)
#define	QMI_M1_RFMT_SUFFIX_WIDTH_S		(0x0u<<4)
#define	QMI_M1_RFMT_SUFFIX_WIDTH_D		(0x1u<<4)
#define	QMI_M1_RFMT_SUFFIX_WIDTH_Q		(0x2u<<4)
#define	QMI_M1_RFMT_DUMMY_WIDTH_S		(0x0u<<6)
#define	QMI_M1_RFMT_DUMMY_WIDTH_D		(0x1u<<6)
#define	QMI_M1_RFMT_DUMMY_WIDTH_Q		(0x2u<<6)
#define	QMI_M1_RFMT_DATA_WIDTH_S		(0x0u<<8)
#define	QMI_M1_RFMT_DATA_WIDTH_D		(0x1u<<8)
#define	QMI_M1_RFMT_DATA_WIDTH_Q		(0x2u<<8)
#define	QMI_M1_RFMT_PREFIX_LEN_NONE		(0x0u<<12)
#define	QMI_M1_RFMT_PREFIX_LEN_8		(0x1u<<12)
#define	QMI_M1_RFMT_SUFFIX_LEN_NONE		(0x0u<<14)
#define	QMI_M1_RFMT_SUFFIX_LEN_8		(0x2u<<14)
#define	QMI_M1_RFMT_DUMMY_LEN_NONE		(0x0u<<16)
#define	QMI_M1_RFMT_DUMMY_LEN_4			(0x1u<<16)
#define	QMI_M1_RFMT_DUMMY_LEN_8			(0x2u<<16)
#define	QMI_M1_RFMT_DUMMY_LEN_12		(0x3u<<16)
#define	QMI_M1_RFMT_DUMMY_LEN_16		(0x4u<<16)
#define	QMI_M1_RFMT_DUMMY_LEN_20		(0x5u<<16)
#define	QMI_M1_RFMT_DUMMY_LEN_24		(0x6u<<16)
#define	QMI_M1_RFMT_DUMMY_LEN_28		(0x7u<<16)

// M1_RCMD Configuration

#define	QMI_M1_RCMD_PREFIX				(0xFFu<<0)
#define	QMI_M1_RCMD_PREFIX_0			(0x1u<<0)
#define	QMI_M1_RCMD_SUFFIX				(0xFFu<<8)
#define	QMI_M1_RCMD_SUFFIX_0			(0x1u<<8)

// M1_WFMT Configuration

#define	QMI_M1_WFMT_PREFIX_WIDTH		(0x3u<<0)
#define	QMI_M1_WFMT_PREFIX_WIDTH_0		(0x1u<<0)
#define	QMI_M1_WFMT_ADDR_WIDTH			(0x3u<<2)
#define	QMI_M1_WFMT_ADDR_WIDTH_0		(0x1u<<2)
#define	QMI_M1_WFMT_SUFFIX_WIDTH		(0x3u<<4)
#define	QMI_M1_WFMT_SUFFIX_WIDTH_0		(0x1u<<4)
#define	QMI_M1_WFMT_DUMMY_WIDTH			(0x3u<<6)
#define	QMI_M1_WFMT_DUMMY_WIDTH_0		(0x1u<<6)
#define	QMI_M1_WFMT_DATA_WIDTH			(0x3u<<8)
#define	QMI_M1_WFMT_DATA_WIDTH_0		(0x1u<<8)
#define	QMI_M1_WFMT_PREFIX_LEN			(0x1u<<12)
#define	QMI_M1_WFMT_SUFFIX_LEN			(0x3u<<14)
#define	QMI_M1_WFMT_SUFFIX_LEN_0		(0x1u<<14)
#define	QMI_M1_WFMT_DUMMY_LEN			(0x7u<<16)
#define	QMI_M1_WFMT_DUMMY_LEN_0			(0x1u<<16)
#define	QMI_M1_WFMT_DTR					(0x1u<<28)
#define	QMI_M1_WFMT_PREFIX_WIDTH_S		(0x0u<<0)
#define	QMI_M1_WFMT_PREFIX_WIDTH_D		(0x1u<<0)
#define	QMI_M1_WFMT_PREFIX_WIDTH_Q		(0x2u<<0)
#define	QMI_M1_WFMT_ADDR_WIDTH_S		(0x0u<<2)
#define	QMI_M1_WFMT_ADDR_WIDTH_D		(0x1u<<2)
#define	QMI_M1_WFMT_ADDR_WIDTH_Q		(0x2u<<2)
#define	QMI_M1_WFMT_SUFFIX_WIDTH_S		(0x0u<<4)
#define	QMI_M1_WFMT_SUFFIX_WIDTH_D		(0x1u<<4)
#define	QMI_M1_WFMT_SUFFIX_WIDTH_Q		(0x2u<<4)
#define	QMI_M1_WFMT_DUMMY_WIDTH_S		(0x0u<<6)
#define	QMI_M1_WFMT_DUMMY_WIDTH_D		(0x1u<<6)
#define	QMI_M1_WFMT_DUMMY_WIDTH_Q		(0x2u<<6)
#define	QMI_M1_WFMT_DATA_WIDTH_S		(0x0u<<8)
#define	QMI_M1_WFMT_DATA_WIDTH_D		(0x1u<<8)
#define	QMI_M1_WFMT_DATA_WIDTH_Q		(0x2u<<8)
#define	QMI_M1_WFMT_PREFIX_LEN_NONE		(0x0u<<12)
#define	QMI_M1_WFMT_PREFIX_LEN_8		(0x1u<<12)
#define	QMI_M1_WFMT_SUFFIX_LEN_NONE		(0x0u<<14)
#define	QMI_M1_WFMT_SUFFIX_LEN_8		(0x2u<<14)
#define	QMI_M1_WFMT_DUMMY_LEN_NONE		(0x0u<<16)
#define	QMI_M1_WFMT_DUMMY_LEN_4			(0x1u<<16)
#define	QMI_M1_WFMT_DUMMY_LEN_8			(0x2u<<16)
#define	QMI_M1_WFMT_DUMMY_LEN_12		(0x3u<<16)
#define	QMI_M1_WFMT_DUMMY_LEN_16		(0x4u<<16)
#define	QMI_M1_WFMT_DUMMY_LEN_20		(0x5u<<16)
#define	QMI_M1_WFMT_DUMMY_LEN_24		(0x6u<<16)
#define	QMI_M1_WFMT_DUMMY_LEN_28		(0x7u<<16)

// M1_WCMD Configuration

#define	QMI_M1_WCMD_PREFIX				(0xFFu<<0)
#define	QMI_M1_WCMD_PREFIX_0			(0x1u<<0)
#define	QMI_M1_WCMD_SUFFIX				(0xFFu<<8)
#define	QMI_M1_WCMD_SUFFIX_0			(0x1u<<8)

// ATRANS0 Configuration

#define	QMI_ATRANS0_BASE				(0xFFFu<<0)
#define	QMI_ATRANS0_BASE_0				(0x1u<<0)
#define	QMI_ATRANS0_SIZE				(0x7FFu<<16)
#define	QMI_ATRANS0_SIZE_0				(0x1u<<16)

// ATRANS1 Configuration

#define	QMI_ATRANS1_BASE				(0xFFFu<<0)
#define	QMI_ATRANS1_BASE_0				(0x1u<<0)
#define	QMI_ATRANS1_SIZE				(0x7FFu<<16)
#define	QMI_ATRANS1_SIZE_0				(0x1u<<16)

// ATRANS2 Configuration

#define	QMI_ATRANS2_BASE				(0xFFFu<<0)
#define	QMI_ATRANS2_BASE_0				(0x1u<<0)
#define	QMI_ATRANS2_SIZE				(0x7FFu<<16)
#define	QMI_ATRANS2_SIZE_0				(0x1u<<16)

// ATRANS3 Configuration

#define	QMI_ATRANS3_BASE				(0xFFFu<<0)
#define	QMI_ATRANS3_BASE_0				(0x1u<<0)
#define	QMI_ATRANS3_SIZE				(0x7FFu<<16)
#define	QMI_ATRANS3_SIZE_0				(0x1u<<16)

// ATRANS4 Configuration

#define	QMI_ATRANS4_BASE				(0xFFFu<<0)
#define	QMI_ATRANS4_BASE_0				(0x1u<<0)
#define	QMI_ATRANS4_SIZE				(0x7FFu<<16)
#define	QMI_ATRANS4_SIZE_0				(0x1u<<16)

// ATRANS5 Configuration

#define	QMI_ATRANS5_BASE				(0xFFFu<<0)
#define	QMI_ATRANS5_BASE_0				(0x1u<<0)
#define	QMI_ATRANS5_SIZE				(0x7FFu<<16)
#define	QMI_ATRANS5_SIZE_0				(0x1u<<16)

// ATRANS6 Configuration

#define	QMI_ATRANS6_BASE				(0xFFFu<<0)
#define	QMI_ATRANS6_BASE_0				(0x1u<<0)
#define	QMI_ATRANS6_SIZE				(0x7FFu<<16)
#define	QMI_ATRANS6_SIZE_0				(0x1u<<16)

// ATRANS7 Configuration

#define	QMI_ATRANS7_BASE				(0xFFFu<<0)
#define	QMI_ATRANS7_BASE_0				(0x1u<<0)
#define	QMI_ATRANS7_SIZE				(0x7FFu<<16)
#define	QMI_ATRANS7_SIZE_0				(0x1u<<16)
