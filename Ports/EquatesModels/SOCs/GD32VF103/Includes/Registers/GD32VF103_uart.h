/*
; GD32VF103_uart.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_uart equates.
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

// UART address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	STAT;
	volatile	uint32_t	DATA;
	volatile	uint32_t	BAUD;
	volatile	uint32_t	CTL0;
	volatile	uint32_t	CTL1;
	volatile	uint32_t	CTL2;
	volatile	uint32_t	GP;
} UART_TypeDef;

#if (defined(__cplusplus))
#define	UART3	reinterpret_cast<UART_TypeDef *>(0x40004C00u)
#define	UART4	reinterpret_cast<UART_TypeDef *>(0x40005000u)

#else
#define	UART3	((UART_TypeDef *)0x40004C00u)
#define	UART4	((UART_TypeDef *)0x40005000u)
#endif

// STAT Configuration

#define	UART_STAT_PERR		(0x1u<<0)
#define	UART_STAT_FERR		(0x1u<<1)
#define	UART_STAT_NERR		(0x1u<<2)
#define	UART_STAT_ORERR		(0x1u<<3)
#define	UART_STAT_IDLEF		(0x1u<<4)
#define	UART_STAT_RBNE		(0x1u<<5)
#define	UART_STAT_TC		(0x1u<<6)
#define	UART_STAT_TBE		(0x1u<<7)
#define	UART_STAT_LBDF		(0x1u<<8)

// DATA Configuration

#define	UART_DATA_DATA		(0x1FFu<<0)
#define	UART_DATA_DATA_0	(0x1u<<0)

// BAUD Configuration

#define	UART_BAUD_FRADIV	(0xFu<<0)
#define	UART_BAUD_FRADIV_0	(0x1u<<0)
#define	UART_BAUD_INTDIV	(0xFFFu<<4)
#define	UART_BAUD_INTDIV_0	(0x1u<<4)

// CTL0 Configuration

#define	UART_CTL0_SBKCMD	(0x1u<<0)
#define	UART_CTL0_RWU		(0x1u<<1)
#define	UART_CTL0_REN		(0x1u<<2)
#define	UART_CTL0_TEN		(0x1u<<3)
#define	UART_CTL0_IDLEIE	(0x1u<<4)
#define	UART_CTL0_RBNEIE	(0x1u<<5)
#define	UART_CTL0_TCIE		(0x1u<<6)
#define	UART_CTL0_TBEIE		(0x1u<<7)
#define	UART_CTL0_PERRIE	(0x1u<<8)
#define	UART_CTL0_PM		(0x1u<<9)
#define	UART_CTL0_PCEN		(0x1u<<10)
#define	UART_CTL0_WM		(0x1u<<11)
#define	UART_CTL0_WL		(0x1u<<12)
#define	UART_CTL0_UEN		(0x1u<<13)

// CTL1 Configuration

#define	UART_CTL1_ADDR		(0xFu<<0)
#define	UART_CTL1_ADDR_0	(0x1u<<0)
#define	UART_CTL1_LBLEN		(0x1u<<5)
#define	UART_CTL1_LBDIE		(0x1u<<6)
#define	UART_CTL1_STB		(0x3u<<12)
#define	UART_CTL1_STB_0		(0x1u<<12)
#define	UART_CTL1_LMEN		(0x1u<<14)

// CTL2 Configuration

#define	UART_CTL2_ERRIE		(0x1u<<0)
#define	UART_CTL2_IREN		(0x1u<<1)
#define	UART_CTL2_IRLP		(0x1u<<2)
#define	UART_CTL2_HDEN		(0x1u<<3)
#define	UART_CTL2_DENR		(0x1u<<6)
#define	UART_CTL2_DENT		(0x1u<<7)

// GP Configuration

#define	UART_GP_PSC			(0xFFu<<0)
#define	UART_GP_PSC_0		(0x1u<<0)
