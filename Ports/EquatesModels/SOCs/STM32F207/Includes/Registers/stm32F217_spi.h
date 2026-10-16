/*
; stm32F217_spi.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_spi equates.
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

// SPI address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CR1;
	volatile	uint32_t	CR2;
	volatile	uint32_t	SR;
	volatile	uint32_t	DR;
	volatile	uint32_t	CRCPR;
	volatile	uint32_t	RXCRCR;
	volatile	uint32_t	TXCRCR;
	volatile	uint32_t	I2SCFGR;
	volatile	uint32_t	I2SPR;
} SPI_TypeDef;

#if (defined(__cplusplus))
#define	SPI1	reinterpret_cast<SPI_TypeDef *>(0x40013000u)
#define	SPI3	reinterpret_cast<SPI_TypeDef *>(0x40003C00u)
#define	SPI2	reinterpret_cast<SPI_TypeDef *>(0x40003800u)

#else
#define	SPI1	((SPI_TypeDef *)0x40013000u)
#define	SPI3	((SPI_TypeDef *)0x40003C00u)
#define	SPI2	((SPI_TypeDef *)0x40003800u)
#endif

// CR1 Configuration

#define	SPI_CR1_CPHA			(0x1u<<0)
#define	SPI_CR1_CPOL			(0x1u<<1)
#define	SPI_CR1_MSTR			(0x1u<<2)
#define	SPI_CR1_BR				(0x7u<<3)
#define	SPI_CR1_BR_0			(0x1u<<3)
#define	SPI_CR1_SPE				(0x1u<<6)
#define	SPI_CR1_LSBFIRST		(0x1u<<7)
#define	SPI_CR1_SSI				(0x1u<<8)
#define	SPI_CR1_SSM				(0x1u<<9)
#define	SPI_CR1_RXONLY			(0x1u<<10)
#define	SPI_CR1_DFF				(0x1u<<11)
#define	SPI_CR1_CRCNEXT			(0x1u<<12)
#define	SPI_CR1_CRCEN			(0x1u<<13)
#define	SPI_CR1_BIDIOE			(0x1u<<14)
#define	SPI_CR1_BIDIMODE		(0x1u<<15)

// CR2 Configuration

#define	SPI_CR2_RXDMAEN			(0x1u<<0)
#define	SPI_CR2_TXDMAEN			(0x1u<<1)
#define	SPI_CR2_SSOE			(0x1u<<2)
#define	SPI_CR2_FRF				(0x1u<<4)
#define	SPI_CR2_ERRIE			(0x1u<<5)
#define	SPI_CR2_RXNEIE			(0x1u<<6)
#define	SPI_CR2_TXEIE			(0x1u<<7)

// SR Configuration

#define	SPI_SR_RXNE				(0x1u<<0)
#define	SPI_SR_TXE				(0x1u<<1)
#define	SPI_SR_CHSIDE			(0x1u<<2)
#define	SPI_SR_UDR				(0x1u<<3)
#define	SPI_SR_CRCERR			(0x1u<<4)
#define	SPI_SR_MODF				(0x1u<<5)
#define	SPI_SR_OVR				(0x1u<<6)
#define	SPI_SR_BSY				(0x1u<<7)
#define	SPI_SR_TIFRFE			(0x1u<<8)

// DR Configuration

#define	SPI_DR_DR				(0xFFFFu<<0)
#define	SPI_DR_DR_0				(0x1u<<0)

// CRCPR Configuration

#define	SPI_CRCPR_CRCPOLY		(0xFFFFu<<0)
#define	SPI_CRCPR_CRCPOLY_0		(0x1u<<0)

// RXCRCR Configuration

#define	SPI_RXCRCR_RXCRC		(0xFFFFu<<0)
#define	SPI_RXCRCR_RXCRC_0		(0x1u<<0)

// TXCRCR Configuration

#define	SPI_TXCRCR_TXCRC		(0xFFFFu<<0)
#define	SPI_TXCRCR_TXCRC_0		(0x1u<<0)

// I2SCFGR Configuration

#define	SPI_I2SCFGR_CHLEN		(0x1u<<0)
#define	SPI_I2SCFGR_DATLEN		(0x3u<<1)
#define	SPI_I2SCFGR_DATLEN_0	(0x1u<<1)
#define	SPI_I2SCFGR_CKPOL		(0x1u<<3)
#define	SPI_I2SCFGR_I2SSTD		(0x3u<<4)
#define	SPI_I2SCFGR_I2SSTD_0	(0x1u<<4)
#define	SPI_I2SCFGR_PCMSYNC		(0x1u<<7)
#define	SPI_I2SCFGR_I2SCFG		(0x3u<<8)
#define	SPI_I2SCFGR_I2SCFG_0	(0x1u<<8)
#define	SPI_I2SCFGR_I2SE		(0x1u<<10)
#define	SPI_I2SCFGR_I2SMOD		(0x1u<<11)

// I2SPR Configuration

#define	SPI_I2SPR_I2SDIV		(0xFFu<<0)
#define	SPI_I2SPR_I2SDIV_0		(0x1u<<0)
#define	SPI_I2SPR_ODD			(0x1u<<8)
#define	SPI_I2SPR_MCKOE			(0x1u<<9)
