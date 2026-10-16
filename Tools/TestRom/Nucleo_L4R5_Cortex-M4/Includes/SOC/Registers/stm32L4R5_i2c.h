/*
; stm32L4R5_i2c.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_i2c equates.
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
	volatile	uint32_t	CR1;
	volatile	uint32_t	CR2;
	volatile	uint32_t	OAR1;
	volatile	uint32_t	OAR2;
	volatile	uint32_t	TIMINGR;
	volatile	uint32_t	TIMEOUTR;
	volatile	uint32_t	ISR;
	volatile	uint32_t	ICR;
	volatile	uint32_t	PECR;
	volatile	uint32_t	RXDR;
	volatile	uint32_t	TXDR;
} I2C_TypeDef;

#if (defined(__cplusplus))
#define	I2C1	reinterpret_cast<I2C_TypeDef *>(0x40005400u)
#define	I2C2	reinterpret_cast<I2C_TypeDef *>(0x40005800u)
#define	I2C3	reinterpret_cast<I2C_TypeDef *>(0x40005C00u)
#define	I2C4	reinterpret_cast<I2C_TypeDef *>(0x40008400u)

#else
#define	I2C1	((I2C_TypeDef *)0x40005400u)
#define	I2C2	((I2C_TypeDef *)0x40005800u)
#define	I2C3	((I2C_TypeDef *)0x40005C00u)
#define	I2C4	((I2C_TypeDef *)0x40008400u)
#endif

// CR1 Configuration

#define	I2C_CR1_PECEN			(0x1u<<23)
#define	I2C_CR1_ALERTEN			(0x1u<<22)
#define	I2C_CR1_SMBDEN			(0x1u<<21)
#define	I2C_CR1_SMBHEN			(0x1u<<20)
#define	I2C_CR1_GCEN			(0x1u<<19)
#define	I2C_CR1_WUPEN			(0x1u<<18)
#define	I2C_CR1_NOSTRETCH		(0x1u<<17)
#define	I2C_CR1_SBC				(0x1u<<16)
#define	I2C_CR1_RXDMAEN			(0x1u<<15)
#define	I2C_CR1_TXDMAEN			(0x1u<<14)
#define	I2C_CR1_ANFOFF			(0x1u<<12)
#define	I2C_CR1_DNF				(0xFu<<8)
#define	I2C_CR1_DNF_0			(0x1u<<8)
#define	I2C_CR1_ERRIE			(0x1u<<7)
#define	I2C_CR1_TCIE			(0x1u<<6)
#define	I2C_CR1_STOPIE			(0x1u<<5)
#define	I2C_CR1_NACKIE			(0x1u<<4)
#define	I2C_CR1_ADDRIE			(0x1u<<3)
#define	I2C_CR1_RXIE			(0x1u<<2)
#define	I2C_CR1_TXIE			(0x1u<<1)
#define	I2C_CR1_PE				(0x1u<<0)

// CR2 Configuration

#define	I2C_CR2_SADD			(0x3FFu<<0)
#define	I2C_CR2_SADD_0			(0x1u<<0)
#define	I2C_CR2_RD_WRN			(0x1u<<10)
#define	I2C_CR2_ADD10			(0x1u<<11)
#define	I2C_CR2_HEAD10R			(0x1u<<12)
#define	I2C_CR2_START			(0x1u<<13)
#define	I2C_CR2_STOP			(0x1u<<14)
#define	I2C_CR2_NACK			(0x1u<<15)
#define	I2C_CR2_NBYTES			(0xFFu<<16)
#define	I2C_CR2_NBYTES_0		(0x1u<<16)
#define	I2C_CR2_RELOAD			(0x1u<<24)
#define	I2C_CR2_AUTOEND			(0x1u<<25)
#define	I2C_CR2_PECBYTE			(0x1u<<26)

// OAR1 Configuration

#define	I2C_OAR1_OA1EN			(0x1u<<15)
#define	I2C_OAR1_OA1MODE		(0x1u<<10)
#define	I2C_OAR1_OA1			(0x3FFu<<0)
#define	I2C_OAR1_OA1_0			(0x1u<<0)

// OAR2 Configuration

#define	I2C_OAR2_OA2EN			(0x1u<<15)
#define	I2C_OAR2_OA2MSK			(0x7u<<8)
#define	I2C_OAR2_OA2MSK_0		(0x1u<<8)
#define	I2C_OAR2_OA2			(0x7Fu<<1)
#define	I2C_OAR2_OA2_0			(0x1u<<1)

// TIMINGR Configuration

#define	I2C_TIMINGR_PRESC		(0xFu<<28)
#define	I2C_TIMINGR_PRESC_0		(0x1u<<28)
#define	I2C_TIMINGR_SCLDEL		(0xFu<<20)
#define	I2C_TIMINGR_SCLDEL_0	(0x1u<<20)
#define	I2C_TIMINGR_SDADEL		(0xFu<<16)
#define	I2C_TIMINGR_SDADEL_0	(0x1u<<16)
#define	I2C_TIMINGR_SCLH		(0xFFu<<8)
#define	I2C_TIMINGR_SCLH_0		(0x1u<<8)
#define	I2C_TIMINGR_SCLL		(0xFFu<<0)
#define	I2C_TIMINGR_SCLL_0		(0x1u<<0)

// TIMEOUTR Configuration

#define	I2C_TIMEOUTR_TEXTEN		(0x1u<<31)
#define	I2C_TIMEOUTR_TIMEOUTB	(0xFFFu<<16)
#define	I2C_TIMEOUTR_TIMEOUTB_0	(0x1u<<16)
#define	I2C_TIMEOUTR_TIMOUTEN	(0x1u<<15)
#define	I2C_TIMEOUTR_TIDLE		(0x1u<<12)
#define	I2C_TIMEOUTR_TIMEOUTA	(0xFFFu<<0)
#define	I2C_TIMEOUTR_TIMEOUTA_0	(0x1u<<0)

// ISR Configuration

#define	I2C_ISR_TXE				(0x1u<<0)
#define	I2C_ISR_TXIS			(0x1u<<1)
#define	I2C_ISR_RXNE			(0x1u<<2)
#define	I2C_ISR_ADDR			(0x1u<<3)
#define	I2C_ISR_NACKF			(0x1u<<4)
#define	I2C_ISR_STOPF			(0x1u<<5)
#define	I2C_ISR_TC				(0x1u<<6)
#define	I2C_ISR_TCR				(0x1u<<7)
#define	I2C_ISR_BERR			(0x1u<<8)
#define	I2C_ISR_ARLO			(0x1u<<9)
#define	I2C_ISR_OVR				(0x1u<<10)
#define	I2C_ISR_PECERR			(0x1u<<11)
#define	I2C_ISR_TIMEOUT			(0x1u<<12)
#define	I2C_ISR_ALERT			(0x1u<<13)
#define	I2C_ISR_BUSY			(0x1u<<15)
#define	I2C_ISR_DIR				(0x1u<<16)
#define	I2C_ISR_ADDCODE			(0x7Fu<<17)
#define	I2C_ISR_ADDCODE_0		(0x1u<<17)

// ICR Configuration

#define	I2C_ICR_ADDRCF			(0x1u<<3)
#define	I2C_ICR_NACKCF			(0x1u<<4)
#define	I2C_ICR_STOPCF			(0x1u<<5)
#define	I2C_ICR_BERRCF			(0x1u<<8)
#define	I2C_ICR_ARLOCF			(0x1u<<9)
#define	I2C_ICR_OVRCF			(0x1u<<10)
#define	I2C_ICR_PECCF			(0x1u<<11)
#define	I2C_ICR_TIMOUTCF		(0x1u<<12)
#define	I2C_ICR_ALERTCF			(0x1u<<13)

// PECR Configuration

#define	I2C_PECR_PEC			(0xFFu<<0)
#define	I2C_PECR_PEC_0			(0x1u<<0)

// RXDR Configuration

#define	I2C_RXDR_RXDATA			(0xFFu<<0)
#define	I2C_RXDR_RXDATA_0		(0x1u<<0)

// TXDR Configuration

#define	I2C_TXDR_TXDATA			(0xFFu<<0)
#define	I2C_TXDR_TXDATA_0		(0x1u<<0)
