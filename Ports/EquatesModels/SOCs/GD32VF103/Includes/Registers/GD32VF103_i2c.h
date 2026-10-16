/*
; GD32VF103_i2c.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_i2c equates.
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

// I2C address definitions
// -----------------------

typedef struct {
	volatile	uint16_t	CTL0;
	volatile	uint16_t	RESERVED0;
	volatile	uint16_t	CTL1;
	volatile	uint16_t	RESERVED1;
	volatile	uint16_t	SADDR0;
	volatile	uint16_t	RESERVED2;
	volatile	uint16_t	SADDR1;
	volatile	uint16_t	RESERVED3;
	volatile	uint16_t	DATA;
	volatile	uint16_t	RESERVED4;
	volatile	uint16_t	STAT0;
	volatile	uint16_t	RESERVED5;
	volatile	uint16_t	STAT1;
	volatile	uint16_t	RESERVED6;
	volatile	uint16_t	CKCFG;
	volatile	uint16_t	RESERVED7;
	volatile	uint16_t	RT;
} I2C_TypeDef;

#if (defined(__cplusplus))
#define	I2C0	reinterpret_cast<I2C_TypeDef *>(0x40005400u)
#define	I2C1	reinterpret_cast<I2C_TypeDef *>(0x40005800u)

#else
#define	I2C0	((I2C_TypeDef *)0x40005400u)
#define	I2C1	((I2C_TypeDef *)0x40005800u)
#endif

// CTL0 Configuration

#define	I2C_CTL0_I2CEN			(0x1u<<0)
#define	I2C_CTL0_SMBEN			(0x1u<<1)
#define	I2C_CTL0_SMBSEL			(0x1u<<3)
#define	I2C_CTL0_ARPEN			(0x1u<<4)
#define	I2C_CTL0_PECEN			(0x1u<<5)
#define	I2C_CTL0_GCEN			(0x1u<<6)
#define	I2C_CTL0_SS				(0x1u<<7)
#define	I2C_CTL0_START			(0x1u<<8)
#define	I2C_CTL0_STOP			(0x1u<<9)
#define	I2C_CTL0_ACKEN			(0x1u<<10)
#define	I2C_CTL0_POAP			(0x1u<<11)
#define	I2C_CTL0_PECTRANS		(0x1u<<12)
#define	I2C_CTL0_SALT			(0x1u<<13)
#define	I2C_CTL0_SRESET			(0x1u<<15)

// CTL1 Configuration

#define	I2C_CTL1_I2CCLK			(0x3Fu<<0)
#define	I2C_CTL1_I2CCLK_0		(0x1u<<0)
#define	I2C_CTL1_ERRIE			(0x1u<<8)
#define	I2C_CTL1_EVIE			(0x1u<<9)
#define	I2C_CTL1_BUFIE			(0x1u<<10)
#define	I2C_CTL1_DMAON			(0x1u<<11)
#define	I2C_CTL1_DMALST			(0x1u<<12)

// SADDR0 Configuration

#define	I2C_SADDR0_ADDRESS0		(0x1u<<0)
#define	I2C_SADDR0_ADDRESS7_1	(0x7Fu<<1)
#define	I2C_SADDR0_ADDRESS7_1_0	(0x1u<<1)
#define	I2C_SADDR0_ADDRESS9_8	(0x3u<<8)
#define	I2C_SADDR0_ADDRESS9_8_0	(0x1u<<8)
#define	I2C_SADDR0_ADDFORMAT	(0x1u<<15)

// SADDR1 Configuration

#define	I2C_SADDR1_DUADEN		(0x1u<<0)
#define	I2C_SADDR1_ADDRESS2		(0x7Fu<<1)
#define	I2C_SADDR1_ADDRESS2_0	(0x1u<<1)

// DATA Configuration

#define	I2C_DATA_TRB			(0xFFu<<0)
#define	I2C_DATA_TRB_0			(0x1u<<0)

// STAT0 Configuration

#define	I2C_STAT0_SBSEND		(0x1u<<0)
#define	I2C_STAT0_ADDSEND		(0x1u<<1)
#define	I2C_STAT0_BTC			(0x1u<<2)
#define	I2C_STAT0_ADD10SEND		(0x1u<<3)
#define	I2C_STAT0_STPDET		(0x1u<<4)
#define	I2C_STAT0_RBNE			(0x1u<<6)
#define	I2C_STAT0_TBE			(0x1u<<7)
#define	I2C_STAT0_BERR			(0x1u<<8)
#define	I2C_STAT0_LOSTARB		(0x1u<<9)
#define	I2C_STAT0_AERR			(0x1u<<10)
#define	I2C_STAT0_OUERR			(0x1u<<11)
#define	I2C_STAT0_PECERR		(0x1u<<12)
#define	I2C_STAT0_SMBTO			(0x1u<<14)
#define	I2C_STAT0_SMBALT		(0x1u<<15)

// STAT1 Configuration

#define	I2C_STAT1_MASTER		(0x1u<<0)
#define	I2C_STAT1_I2CBSY		(0x1u<<1)
#define	I2C_STAT1_TR			(0x1u<<2)
#define	I2C_STAT1_RXGC			(0x1u<<4)
#define	I2C_STAT1_DEFSMB		(0x1u<<5)
#define	I2C_STAT1_HSTSMB		(0x1u<<6)
#define	I2C_STAT1_DUMODF		(0x1u<<7)
#define	I2C_STAT1_PECV			(0xFFu<<8)
#define	I2C_STAT1_PECV_0		(0x1u<<8)

// CKCFG Configuration

#define	I2C_CKCFG_CLKC			(0xFFFu<<0)
#define	I2C_CKCFG_CLKC_0		(0x1u<<0)
#define	I2C_CKCFG_DTCY			(0x1u<<14)
#define	I2C_CKCFG_FAST			(0x1u<<15)

// RT Configuration

#define	I2C_RT_RISETIME			(0x3Fu<<0)
#define	I2C_RT_RISETIME_0		(0x1u<<0)
