/*
; RP2350_spi.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_spi equates.
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

// SPI address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	SSPCR0;
	volatile	uint32_t	SSPCR1;
	volatile	uint32_t	SSPDR;
	volatile	uint32_t	SSPSR;
	volatile	uint32_t	SSPCPSR;
	volatile	uint32_t	SSPIMSC;
	volatile	uint32_t	SSPRIS;
	volatile	uint32_t	SSPMIS;
	volatile	uint32_t	SSPICR;
	volatile	uint32_t	SSPDMACR;
	volatile	uint32_t	RESERVED0[1006];
	volatile	uint32_t	SSPPERIPHID0;
	volatile	uint32_t	SSPPERIPHID1;
	volatile	uint32_t	SSPPERIPHID2;
	volatile	uint32_t	SSPPERIPHID3;
	volatile	uint32_t	SSPPCELLID0;
	volatile	uint32_t	SSPPCELLID1;
	volatile	uint32_t	SSPPCELLID2;
	volatile	uint32_t	SSPPCELLID3;
} SPI_TypeDef;

#ifdef __cplusplus
#define	SPI0_NS	reinterpret_cast<SPI_TypeDef *>(0x40080000u)
#define	SPI0_S	reinterpret_cast<SPI_TypeDef *>(0x40080000u)
#define	SPI1_NS	reinterpret_cast<SPI_TypeDef *>(0x40088000u)
#define	SPI1_S	reinterpret_cast<SPI_TypeDef *>(0x40088000u)
#else
#define	SPI0_NS	((SPI_TypeDef *)0x40080000u)
#define	SPI0_S	((SPI_TypeDef *)0x40080000u)
#define	SPI1_NS	((SPI_TypeDef *)0x40088000u)
#define	SPI1_S	((SPI_TypeDef *)0x40088000u)
#endif

// SSPCR0 Configuration

#define	SPI_SSPCR0_DSS						(0xFu<<0)
#define	SPI_SSPCR0_DSS_0					(0x1u<<0)
#define	SPI_SSPCR0_FRF						(0x3u<<4)
#define	SPI_SSPCR0_FRF_0					(0x1u<<4)
#define	SPI_SSPCR0_SPO						(0x1u<<6)
#define	SPI_SSPCR0_SPH						(0x1u<<7)
#define	SPI_SSPCR0_SCR						(0xFFu<<8)
#define	SPI_SSPCR0_SCR_0					(0x1u<<8)

// SSPCR1 Configuration

#define	SPI_SSPCR1_LBM						(0x1u<<0)
#define	SPI_SSPCR1_SSE						(0x1u<<1)
#define	SPI_SSPCR1_MS						(0x1u<<2)
#define	SPI_SSPCR1_SOD						(0x1u<<3)

// SSPDR Configuration

#define	SPI_SSPDR_DATA						(0xFFFFu<<0)
#define	SPI_SSPDR_DATA_0					(0x1u<<0)

// SSPSR Configuration

#define	SPI_SSPSR_TFE						(0x1u<<0)
#define	SPI_SSPSR_TNF						(0x1u<<1)
#define	SPI_SSPSR_RNE						(0x1u<<2)
#define	SPI_SSPSR_RFF						(0x1u<<3)
#define	SPI_SSPSR_BSY						(0x1u<<4)

// SSPCPSR Configuration

#define	SPI_SSPCPSR_CPSDVSR					(0xFFu<<0)
#define	SPI_SSPCPSR_CPSDVSR_0				(0x1u<<0)

// SSPIMSC Configuration

#define	SPI_SSPIMSC_RORIM					(0x1u<<0)
#define	SPI_SSPIMSC_RTIM					(0x1u<<1)
#define	SPI_SSPIMSC_RXIM					(0x1u<<2)
#define	SPI_SSPIMSC_TXIM					(0x1u<<3)

// SSPRIS Configuration

#define	SPI_SSPRIS_RORRIS					(0x1u<<0)
#define	SPI_SSPRIS_RTRIS					(0x1u<<1)
#define	SPI_SSPRIS_RXRIS					(0x1u<<2)
#define	SPI_SSPRIS_TXRIS					(0x1u<<3)

// SSPMIS Configuration

#define	SPI_SSPMIS_RORMIS					(0x1u<<0)
#define	SPI_SSPMIS_RTMIS					(0x1u<<1)
#define	SPI_SSPMIS_RXMIS					(0x1u<<2)
#define	SPI_SSPMIS_TXMIS					(0x1u<<3)

// SSPICR Configuration

#define	SPI_SSPICR_RORIC					(0x1u<<0)
#define	SPI_SSPICR_RTIC						(0x1u<<1)

// SSPDMACR Configuration

#define	SPI_SSPDMACR_RXDMAE					(0x1u<<0)
#define	SPI_SSPDMACR_TXDMAE					(0x1u<<1)

// SSPPERIPHID0 Configuration

#define	SPI_SSPPERIPHID0_PARTNUMBER0		(0xFFu<<0)
#define	SPI_SSPPERIPHID0_PARTNUMBER0_0		(0x1u<<0)

// SSPPERIPHID1 Configuration

#define	SPI_SSPPERIPHID1_PARTNUMBER1		(0xFu<<0)
#define	SPI_SSPPERIPHID1_PARTNUMBER1_0		(0x1u<<0)
#define	SPI_SSPPERIPHID1_DESIGNER0			(0xFu<<4)
#define	SPI_SSPPERIPHID1_DESIGNER0_0		(0x1u<<4)

// SSPPERIPHID2 Configuration

#define	SPI_SSPPERIPHID2_DESIGNER1			(0xFu<<0)
#define	SPI_SSPPERIPHID2_DESIGNER1_0		(0x1u<<0)
#define	SPI_SSPPERIPHID2_REVISION			(0xFu<<4)
#define	SPI_SSPPERIPHID2_REVISION_0			(0x1u<<4)

// SSPPERIPHID3 Configuration

#define	SPI_SSPPERIPHID3_CONFIGURATION		(0xFFu<<0)
#define	SPI_SSPPERIPHID3_CONFIGURATION_0	(0x1u<<0)

// SSPPCELLID0 Configuration

#define	SPI_SSPPCELLID0_SSPPCELLID0			(0xFFu<<0)
#define	SPI_SSPPCELLID0_SSPPCELLID0_0		(0x1u<<0)

// SSPPCELLID1 Configuration

#define	SPI_SSPPCELLID1_SSPPCELLID1			(0xFFu<<0)
#define	SPI_SSPPCELLID1_SSPPCELLID1_0		(0x1u<<0)

// SSPPCELLID2 Configuration

#define	SPI_SSPPCELLID2_SSPPCELLID2			(0xFFu<<0)
#define	SPI_SSPPCELLID2_SSPPCELLID2_0		(0x1u<<0)

// SSPPCELLID3 Configuration

#define	SPI_SSPPCELLID3_SSPPCELLID3			(0xFFu<<0)
#define	SPI_SSPPCELLID3_SSPPCELLID3_0		(0x1u<<0)
