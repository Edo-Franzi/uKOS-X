/*
; GD32VF103_spi.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_spi equates.
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
	volatile	uint16_t	CTL0;
	volatile	uint16_t	RESERVED0;
	volatile	uint16_t	CTL1;
	volatile	uint16_t	RESERVED1;
	volatile	uint16_t	STAT;
	volatile	uint16_t	RESERVED2;
	volatile	uint16_t	DATA;
	volatile	uint16_t	RESERVED3;
	volatile	uint16_t	CRCPOLY;
	volatile	uint16_t	RESERVED4;
	volatile	uint16_t	RCRC;
	volatile	uint16_t	RESERVED5;
	volatile	uint16_t	TCRC;
	volatile	uint16_t	RESERVED6;
	volatile	uint16_t	I2SCTL;
	volatile	uint16_t	RESERVED7;
	volatile	uint16_t	I2SPSC;
} SPI_TypeDef;

#if (defined(__cplusplus))
#define	SPI0	reinterpret_cast<SPI_TypeDef *>(0x40013000u)
#define	SPI1	reinterpret_cast<SPI_TypeDef *>(0x40003800u)
#define	SPI2	reinterpret_cast<SPI_TypeDef *>(0x40003C00u)

#else
#define	SPI0	((SPI_TypeDef *)0x40013000u)
#define	SPI1	((SPI_TypeDef *)0x40003800u)
#define	SPI2	((SPI_TypeDef *)0x40003C00u)
#endif

// CTL0 Configuration

#define	SPI_CTL0_CKPH			(0x1u<<0)
#define	SPI_CTL0_CKPL			(0x1u<<1)
#define	SPI_CTL0_MSTMOD			(0x1u<<2)
#define	SPI_CTL0_PSC			(0x7u<<3)
#define	SPI_CTL0_PSC_0			(0x1u<<3)
#define	SPI_CTL0_SPIEN			(0x1u<<6)
#define	SPI_CTL0_LF				(0x1u<<7)
#define	SPI_CTL0_SWNSS			(0x1u<<8)
#define	SPI_CTL0_SWNSSEN		(0x1u<<9)
#define	SPI_CTL0_RO				(0x1u<<10)
#define	SPI_CTL0_FF16			(0x1u<<11)
#define	SPI_CTL0_CRCNT			(0x1u<<12)
#define	SPI_CTL0_CRCEN			(0x1u<<13)
#define	SPI_CTL0_BDOEN			(0x1u<<14)
#define	SPI_CTL0_BDEN			(0x1u<<15)

// CTL1 Configuration

#define	SPI_CTL1_DMAREN			(0x1u<<0)
#define	SPI_CTL1_DMATEN			(0x1u<<1)
#define	SPI_CTL1_NSSDRV			(0x1u<<2)
#define	SPI_CTL1_NSSP			(0x1u<<3)
#define	SPI_CTL1_TMOD			(0x1u<<4)
#define	SPI_CTL1_ERRIE			(0x1u<<5)
#define	SPI_CTL1_RBNEIE			(0x1u<<6)
#define	SPI_CTL1_TBEIE			(0x1u<<7)

// STAT Configuration

#define	SPI_STAT_RBNE			(0x1u<<0)
#define	SPI_STAT_TBE			(0x1u<<1)
#define	SPI_STAT_I2SCH			(0x1u<<2)
#define	SPI_STAT_TXURERR		(0x1u<<3)
#define	SPI_STAT_CRCERR			(0x1u<<4)
#define	SPI_STAT_CONFERR		(0x1u<<5)
#define	SPI_STAT_RXORERR		(0x1u<<6)
#define	SPI_STAT_TRANS			(0x1u<<7)
#define	SPI_STAT_FERR			(0x1u<<8)

// DATA Configuration

#define	SPI_DATA_SPI_DATA		(0xFFFFu<<0)
#define	SPI_DATA_SPI_DATA_0		(0x1u<<0)

// CRCPOLY Configuration

#define	SPI_CRCPOLY_CRCPOLY		(0xFFFFu<<0)
#define	SPI_CRCPOLY_CRCPOLY_0	(0x1u<<0)

// RCRC Configuration

#define	SPI_RCRC_RCRC			(0xFFFFu<<0)
#define	SPI_RCRC_RCRC_0			(0x1u<<0)

// TCRC Configuration

#define	SPI_TCRC_TCRC			(0xFFFFu<<0)
#define	SPI_TCRC_TCRC_0			(0x1u<<0)

// I2SCTL Configuration

#define	SPI_I2SCTL_CHLEN		(0x1u<<0)
#define	SPI_I2SCTL_DTLEN		(0x3u<<1)
#define	SPI_I2SCTL_DTLEN_0		(0x1u<<1)
#define	SPI_I2SCTL_CKPL			(0x1u<<3)
#define	SPI_I2SCTL_I2SSTD		(0x3u<<4)
#define	SPI_I2SCTL_I2SSTD_0		(0x1u<<4)
#define	SPI_I2SCTL_PCMSMOD		(0x1u<<7)
#define	SPI_I2SCTL_I2SOPMOD		(0x3u<<8)
#define	SPI_I2SCTL_I2SOPMOD_0	(0x1u<<8)
#define	SPI_I2SCTL_I2SEN		(0x1u<<10)
#define	SPI_I2SCTL_I2SSEL		(0x1u<<11)

// I2SPSC Configuration

#define	SPI_I2SPSC_DIV			(0xFFu<<0)
#define	SPI_I2SPSC_DIV_0		(0x1u<<0)
#define	SPI_I2SPSC_OF			(0x1u<<8)
#define	SPI_I2SPSC_MCKOEN		(0x1u<<9)
