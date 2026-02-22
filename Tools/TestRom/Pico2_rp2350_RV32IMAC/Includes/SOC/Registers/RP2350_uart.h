/*
; RP2350_uart.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_uart equates.
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

// UART address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	UARTDR;
	volatile	uint32_t	UARTRSR;
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	UARTFR;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	UARTILPR;
	volatile	uint32_t	UARTIBRD;
	volatile	uint32_t	UARTFBRD;
	volatile	uint32_t	UARTLCR_H;
	volatile	uint32_t	UARTCR;
	volatile	uint32_t	UARTIFLS;
	volatile	uint32_t	UARTIMSC;
	volatile	uint32_t	UARTRIS;
	volatile	uint32_t	UARTMIS;
	volatile	uint32_t	UARTICR;
	volatile	uint32_t	UARTDMACR;
	volatile	uint32_t	RESERVED2[997];
	volatile	uint32_t	UARTPERIPHID0;
	volatile	uint32_t	UARTPERIPHID1;
	volatile	uint32_t	UARTPERIPHID2;
	volatile	uint32_t	UARTPERIPHID3;
	volatile	uint32_t	UARTPCELLID0;
	volatile	uint32_t	UARTPCELLID1;
	volatile	uint32_t	UARTPCELLID2;
	volatile	uint32_t	UARTPCELLID3;
} UART_TypeDef;

#ifdef __cplusplus
#define	UART0_NS	reinterpret_cast<UART_TypeDef *>(0x40070000u)
#define	UART0_S		reinterpret_cast<UART_TypeDef *>(0x40070000u)
#define	UART1_NS	reinterpret_cast<UART_TypeDef *>(0x40078000u)
#define	UART1_S		reinterpret_cast<UART_TypeDef *>(0x40078000u)
#else
#define	UART0_NS	((UART_TypeDef *)0x40070000u)
#define	UART0_S		((UART_TypeDef *)0x40070000u)
#define	UART1_NS	((UART_TypeDef *)0x40078000u)
#define	UART1_S		((UART_TypeDef *)0x40078000u)
#endif

// UARTDR Configuration

#define	UART_UARTDR_DATA					(0xFFu<<0)
#define	UART_UARTDR_DATA_0					(0x1u<<0)
#define	UART_UARTDR_FE						(0x1u<<8)
#define	UART_UARTDR_PE						(0x1u<<9)
#define	UART_UARTDR_BE						(0x1u<<10)
#define	UART_UARTDR_OE						(0x1u<<11)

// UARTRSR Configuration

#define	UART_UARTRSR_FE						(0x1u<<0)
#define	UART_UARTRSR_PE						(0x1u<<1)
#define	UART_UARTRSR_BE						(0x1u<<2)
#define	UART_UARTRSR_OE						(0x1u<<3)

// UARTFR Configuration

#define	UART_UARTFR_CTS						(0x1u<<0)
#define	UART_UARTFR_DSR						(0x1u<<1)
#define	UART_UARTFR_DCD						(0x1u<<2)
#define	UART_UARTFR_BUSY					(0x1u<<3)
#define	UART_UARTFR_RXFE					(0x1u<<4)
#define	UART_UARTFR_TXFF					(0x1u<<5)
#define	UART_UARTFR_RXFF					(0x1u<<6)
#define	UART_UARTFR_TXFE					(0x1u<<7)
#define	UART_UARTFR_RI						(0x1u<<8)

// UARTILPR Configuration

#define	UART_UARTILPR_ILPDVSR				(0xFFu<<0)
#define	UART_UARTILPR_ILPDVSR_0				(0x1u<<0)

// UARTIBRD Configuration

#define	UART_UARTIBRD_BAUD_DIVINT			(0xFFFFu<<0)
#define	UART_UARTIBRD_BAUD_DIVINT_0			(0x1u<<0)

// UARTFBRD Configuration

#define	UART_UARTFBRD_BAUD_DIVFRAC			(0x3Fu<<0)
#define	UART_UARTFBRD_BAUD_DIVFRAC_0		(0x1u<<0)

// UARTLCR_H Configuration

#define	UART_UARTLCR_H_BRK					(0x1u<<0)
#define	UART_UARTLCR_H_PEN					(0x1u<<1)
#define	UART_UARTLCR_H_EPS					(0x1u<<2)
#define	UART_UARTLCR_H_STP2					(0x1u<<3)
#define	UART_UARTLCR_H_FEN					(0x1u<<4)
#define	UART_UARTLCR_H_WLEN					(0x3u<<5)
#define	UART_UARTLCR_H_WLEN_0				(0x1u<<5)
#define	UART_UARTLCR_H_SPS					(0x1u<<7)

// UARTCR Configuration

#define	UART_UARTCR_UARTEN					(0x1u<<0)
#define	UART_UARTCR_SIREN					(0x1u<<1)
#define	UART_UARTCR_SIRLP					(0x1u<<2)
#define	UART_UARTCR_LBE						(0x1u<<7)
#define	UART_UARTCR_TXE						(0x1u<<8)
#define	UART_UARTCR_RXE						(0x1u<<9)
#define	UART_UARTCR_DTR						(0x1u<<10)
#define	UART_UARTCR_RTS						(0x1u<<11)
#define	UART_UARTCR_OUT1					(0x1u<<12)
#define	UART_UARTCR_OUT2					(0x1u<<13)
#define	UART_UARTCR_RTSEN					(0x1u<<14)
#define	UART_UARTCR_CTSEN					(0x1u<<15)

// UARTIFLS Configuration

#define	UART_UARTIFLS_TXIFLSEL				(0x7u<<0)
#define	UART_UARTIFLS_TXIFLSEL_0			(0x1u<<0)
#define	UART_UARTIFLS_RXIFLSEL				(0x7u<<3)
#define	UART_UARTIFLS_RXIFLSEL_0			(0x1u<<3)

// UARTIMSC Configuration

#define	UART_UARTIMSC_RIMIM					(0x1u<<0)
#define	UART_UARTIMSC_CTSMIM				(0x1u<<1)
#define	UART_UARTIMSC_DCDMIM				(0x1u<<2)
#define	UART_UARTIMSC_DSRMIM				(0x1u<<3)
#define	UART_UARTIMSC_RXIM					(0x1u<<4)
#define	UART_UARTIMSC_TXIM					(0x1u<<5)
#define	UART_UARTIMSC_RTIM					(0x1u<<6)
#define	UART_UARTIMSC_FEIM					(0x1u<<7)
#define	UART_UARTIMSC_PEIM					(0x1u<<8)
#define	UART_UARTIMSC_BEIM					(0x1u<<9)
#define	UART_UARTIMSC_OEIM					(0x1u<<10)

// UARTRIS Configuration

#define	UART_UARTRIS_RIRMIS					(0x1u<<0)
#define	UART_UARTRIS_CTSRMIS				(0x1u<<1)
#define	UART_UARTRIS_DCDRMIS				(0x1u<<2)
#define	UART_UARTRIS_DSRRMIS				(0x1u<<3)
#define	UART_UARTRIS_RXRIS					(0x1u<<4)
#define	UART_UARTRIS_TXRIS					(0x1u<<5)
#define	UART_UARTRIS_RTRIS					(0x1u<<6)
#define	UART_UARTRIS_FERIS					(0x1u<<7)
#define	UART_UARTRIS_PERIS					(0x1u<<8)
#define	UART_UARTRIS_BERIS					(0x1u<<9)
#define	UART_UARTRIS_OERIS					(0x1u<<10)

// UARTMIS Configuration

#define	UART_UARTMIS_RIMMIS					(0x1u<<0)
#define	UART_UARTMIS_CTSMMIS				(0x1u<<1)
#define	UART_UARTMIS_DCDMMIS				(0x1u<<2)
#define	UART_UARTMIS_DSRMMIS				(0x1u<<3)
#define	UART_UARTMIS_RXMIS					(0x1u<<4)
#define	UART_UARTMIS_TXMIS					(0x1u<<5)
#define	UART_UARTMIS_RTMIS					(0x1u<<6)
#define	UART_UARTMIS_FEMIS					(0x1u<<7)
#define	UART_UARTMIS_PEMIS					(0x1u<<8)
#define	UART_UARTMIS_BEMIS					(0x1u<<9)
#define	UART_UARTMIS_OEMIS					(0x1u<<10)

// UARTICR Configuration

#define	UART_UARTICR_RIMIC					(0x1u<<0)
#define	UART_UARTICR_CTSMIC					(0x1u<<1)
#define	UART_UARTICR_DCDMIC					(0x1u<<2)
#define	UART_UARTICR_DSRMIC					(0x1u<<3)
#define	UART_UARTICR_RXIC					(0x1u<<4)
#define	UART_UARTICR_TXIC					(0x1u<<5)
#define	UART_UARTICR_RTIC					(0x1u<<6)
#define	UART_UARTICR_FEIC					(0x1u<<7)
#define	UART_UARTICR_PEIC					(0x1u<<8)
#define	UART_UARTICR_BEIC					(0x1u<<9)
#define	UART_UARTICR_OEIC					(0x1u<<10)

// UARTDMACR Configuration

#define	UART_UARTDMACR_RXDMAE				(0x1u<<0)
#define	UART_UARTDMACR_TXDMAE				(0x1u<<1)
#define	UART_UARTDMACR_DMAONERR				(0x1u<<2)

// UARTPERIPHID0 Configuration

#define	UART_UARTPERIPHID0_PARTNUMBER0		(0xFFu<<0)
#define	UART_UARTPERIPHID0_PARTNUMBER0_0	(0x1u<<0)

// UARTPERIPHID1 Configuration

#define	UART_UARTPERIPHID1_PARTNUMBER1		(0xFu<<0)
#define	UART_UARTPERIPHID1_PARTNUMBER1_0	(0x1u<<0)
#define	UART_UARTPERIPHID1_DESIGNER0		(0xFu<<4)
#define	UART_UARTPERIPHID1_DESIGNER0_0		(0x1u<<4)

// UARTPERIPHID2 Configuration

#define	UART_UARTPERIPHID2_DESIGNER1		(0xFu<<0)
#define	UART_UARTPERIPHID2_DESIGNER1_0		(0x1u<<0)
#define	UART_UARTPERIPHID2_REVISION			(0xFu<<4)
#define	UART_UARTPERIPHID2_REVISION_0		(0x1u<<4)

// UARTPERIPHID3 Configuration

#define	UART_UARTPERIPHID3_CONFIGURATION	(0xFFu<<0)
#define	UART_UARTPERIPHID3_CONFIGURATION_0	(0x1u<<0)

// UARTPCELLID0 Configuration

#define	UART_UARTPCELLID0_UARTPCELLID0		(0xFFu<<0)
#define	UART_UARTPCELLID0_UARTPCELLID0_0	(0x1u<<0)

// UARTPCELLID1 Configuration

#define	UART_UARTPCELLID1_UARTPCELLID1		(0xFFu<<0)
#define	UART_UARTPCELLID1_UARTPCELLID1_0	(0x1u<<0)

// UARTPCELLID2 Configuration

#define	UART_UARTPCELLID2_UARTPCELLID2		(0xFFu<<0)
#define	UART_UARTPCELLID2_UARTPCELLID2_0	(0x1u<<0)

// UARTPCELLID3 Configuration

#define	UART_UARTPCELLID3_UARTPCELLID3		(0xFFu<<0)
#define	UART_UARTPCELLID3_UARTPCELLID3_0	(0x1u<<0)
