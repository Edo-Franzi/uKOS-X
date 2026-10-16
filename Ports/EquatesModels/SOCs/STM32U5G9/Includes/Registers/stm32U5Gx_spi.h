/*
; stm32U5Gx_spi.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_spi equates.
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
	volatile	uint32_t	CFG1;
	volatile	uint32_t	CFG2;
	volatile	uint32_t	IER;
	volatile	uint32_t	SR;
	volatile	uint32_t	IFCR;
	volatile	uint32_t	AUTOCR;
	volatile	uint32_t	TXDR;
	volatile	uint32_t	RESERVED0[3];
	volatile	uint32_t	RXDR;
	volatile	uint32_t	RESERVED1[3];
	volatile	uint32_t	CRCPOLY;
	volatile	uint32_t	TXCRC;
	volatile	uint32_t	RXCRC;
	volatile	uint32_t	UDRDR;
} SPI_TypeDef;

#if (defined(__cplusplus))
#define	SPI1_NS	reinterpret_cast<SPI_TypeDef *>(0x40013000u)
#define	SPI1_S	reinterpret_cast<SPI_TypeDef *>(0x50013000u)
#define	SPI2_NS	reinterpret_cast<SPI_TypeDef *>(0x40003800u)
#define	SPI2_S	reinterpret_cast<SPI_TypeDef *>(0x50003800u)
#define	SPI3_NS	reinterpret_cast<SPI_TypeDef *>(0x46002000u)
#define	SPI3_S	reinterpret_cast<SPI_TypeDef *>(0x56002000u)

#else
#define	SPI1_NS	((SPI_TypeDef *)0x40013000u)
#define	SPI1_S	((SPI_TypeDef *)0x50013000u)
#define	SPI2_NS	((SPI_TypeDef *)0x40003800u)
#define	SPI2_S	((SPI_TypeDef *)0x50003800u)
#define	SPI3_NS	((SPI_TypeDef *)0x46002000u)
#define	SPI3_S	((SPI_TypeDef *)0x56002000u)
#endif

// CR1 Configuration

#define	SPI_CR1_SPE				(0x1u<<0)
#define	SPI_CR1_MASRX			(0x1u<<8)
#define	SPI_CR1_CSTART			(0x1u<<9)
#define	SPI_CR1_CSUSP			(0x1u<<10)
#define	SPI_CR1_HDDIR			(0x1u<<11)
#define	SPI_CR1_SSI				(0x1u<<12)
#define	SPI_CR1_CRC33_17		(0x1u<<13)
#define	SPI_CR1_RCRCINI			(0x1u<<14)
#define	SPI_CR1_TCRCINI			(0x1u<<15)
#define	SPI_CR1_IOLOCK			(0x1u<<16)

// CR2 Configuration

#define	SPI_CR2_TSIZE			(0xFFFFu<<0)
#define	SPI_CR2_TSIZE_0			(0x1u<<0)

// CFG1 Configuration

#define	SPI_CFG1_DSIZE			(0x1Fu<<0)
#define	SPI_CFG1_DSIZE_0		(0x1u<<0)
#define	SPI_CFG1_FTHVL			(0xFu<<5)
#define	SPI_CFG1_FTHVL_0		(0x1u<<5)
#define	SPI_CFG1_UDRCFG			(0x1u<<9)
#define	SPI_CFG1_RXDMAEN		(0x1u<<14)
#define	SPI_CFG1_TXDMAEN		(0x1u<<15)
#define	SPI_CFG1_CRCSIZE		(0x1Fu<<16)
#define	SPI_CFG1_CRCSIZE_0		(0x1u<<16)
#define	SPI_CFG1_CRCEN			(0x1u<<22)
#define	SPI_CFG1_MBR			(0x7u<<28)
#define	SPI_CFG1_MBR_0			(0x1u<<28)
#define	SPI_CFG1_BPASS			(0x1u<<31)

// CFG2 Configuration

#define	SPI_CFG2_MSSI			(0xFu<<0)
#define	SPI_CFG2_MSSI_0			(0x1u<<0)
#define	SPI_CFG2_MIDI			(0xFu<<4)
#define	SPI_CFG2_MIDI_0			(0x1u<<4)
#define	SPI_CFG2_RDIMM			(0x1u<<13)
#define	SPI_CFG2_RDIOP			(0x1u<<14)
#define	SPI_CFG2_IOSWP			(0x1u<<15)
#define	SPI_CFG2_COMM			(0x3u<<17)
#define	SPI_CFG2_COMM_0			(0x1u<<17)
#define	SPI_CFG2_SP				(0x7u<<19)
#define	SPI_CFG2_SP_0			(0x1u<<19)
#define	SPI_CFG2_MASTER			(0x1u<<22)
#define	SPI_CFG2_LSBFRST		(0x1u<<23)
#define	SPI_CFG2_CPHA			(0x1u<<24)
#define	SPI_CFG2_CPOL			(0x1u<<25)
#define	SPI_CFG2_SSM			(0x1u<<26)
#define	SPI_CFG2_SSIOP			(0x1u<<28)
#define	SPI_CFG2_SSOE			(0x1u<<29)
#define	SPI_CFG2_SSOM			(0x1u<<30)
#define	SPI_CFG2_AFCNTR			(0x1u<<31)

// IER Configuration

#define	SPI_IER_RXPIE			(0x1u<<0)
#define	SPI_IER_TXPIE			(0x1u<<1)
#define	SPI_IER_DPXPIE			(0x1u<<2)
#define	SPI_IER_EOTIE			(0x1u<<3)
#define	SPI_IER_TXTFIE			(0x1u<<4)
#define	SPI_IER_UDRIE			(0x1u<<5)
#define	SPI_IER_OVRIE			(0x1u<<6)
#define	SPI_IER_CRCEIE			(0x1u<<7)
#define	SPI_IER_TIFREIE			(0x1u<<8)
#define	SPI_IER_MODFIE			(0x1u<<9)

// SR Configuration

#define	SPI_SR_RXP				(0x1u<<0)
#define	SPI_SR_TXP				(0x1u<<1)
#define	SPI_SR_DXP				(0x1u<<2)
#define	SPI_SR_EOT				(0x1u<<3)
#define	SPI_SR_TXTF				(0x1u<<4)
#define	SPI_SR_UDR				(0x1u<<5)
#define	SPI_SR_OVR				(0x1u<<6)
#define	SPI_SR_CRCE				(0x1u<<7)
#define	SPI_SR_TIFRE			(0x1u<<8)
#define	SPI_SR_MODF				(0x1u<<9)
#define	SPI_SR_SUSP				(0x1u<<11)
#define	SPI_SR_TXC				(0x1u<<12)
#define	SPI_SR_RXPLVL			(0x3u<<13)
#define	SPI_SR_RXPLVL_0			(0x1u<<13)
#define	SPI_SR_RXWNE			(0x1u<<15)
#define	SPI_SR_CTSIZE			(0xFFFFu<<16)
#define	SPI_SR_CTSIZE_0			(0x1u<<16)

// IFCR Configuration

#define	SPI_IFCR_EOTC			(0x1u<<3)
#define	SPI_IFCR_TXTFC			(0x1u<<4)
#define	SPI_IFCR_UDRC			(0x1u<<5)
#define	SPI_IFCR_OVRC			(0x1u<<6)
#define	SPI_IFCR_CRCEC			(0x1u<<7)
#define	SPI_IFCR_TIFREC			(0x1u<<8)
#define	SPI_IFCR_MODFC			(0x1u<<9)
#define	SPI_IFCR_SUSPC			(0x1u<<11)

// AUTOCR Configuration

#define	SPI_AUTOCR_TRIGSEL		(0xFu<<16)
#define	SPI_AUTOCR_TRIGSEL_0	(0x1u<<16)
#define	SPI_AUTOCR_TRIGPOL		(0x1u<<20)
#define	SPI_AUTOCR_TRIGEN		(0x1u<<21)

// TXDR Configuration

#define	SPI_TXDR_TXDR			(0xFFFFFFFFu<<0)
#define	SPI_TXDR_TXDR_0			(0x1u<<0)

// RXDR Configuration

#define	SPI_RXDR_RXDR			(0xFFFFFFFFu<<0)
#define	SPI_RXDR_RXDR_0			(0x1u<<0)

// CRCPOLY Configuration

#define	SPI_CRCPOLY_CRCPOLY		(0xFFFFFFFFu<<0)
#define	SPI_CRCPOLY_CRCPOLY_0	(0x1u<<0)

// TXCRC Configuration

#define	SPI_TXCRC_TXCRC			(0xFFFFFFFFu<<0)
#define	SPI_TXCRC_TXCRC_0		(0x1u<<0)

// RXCRC Configuration

#define	SPI_RXCRC_RXCRC			(0xFFFFFFFFu<<0)
#define	SPI_RXCRC_RXCRC_0		(0x1u<<0)

// UDRDR Configuration

#define	SPI_UDRDR_UDRDR			(0xFFFFFFFFu<<0)
#define	SPI_UDRDR_UDRDR_0		(0x1u<<0)
