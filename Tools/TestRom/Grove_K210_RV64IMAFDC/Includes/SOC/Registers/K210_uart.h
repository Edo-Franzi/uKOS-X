/*
; K210_uart.
; ==========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		K210_uart equates.
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

// UART FCR Register
// -----------------

#define	UART_FCR_SEND_FIFO_0		(0u<<4)			//
#define	UART_FCR_SEND_FIFO_2		(1u<<4)			//
#define	UART_FCR_SEND_FIFO_4		(2u<<4)			//
#define	UART_FCR_SEND_FIFO_8		(3u<<4)			//

#define	UART_FCR_RECEIVE_FIFO_1		(0u<<6)			//
#define	UART_FCR_RECEIVE_FIFO_4		(1u<<6)			//
#define	UART_FCR_RECEIVE_FIFO_8		(2u<<6)			//
#define	UART_FCR_RECEIVE_FIFO_14	(3u<<6)			//

// UART LCR Register
// -----------------

#define	UART_LCR_NBBITSMSK			(3u<<0)			//
#define	UART_LCR_NBBIT8				(3u<<0)			//
#define	UART_LCR_NBBIT7				(2u<<0)			//

#define	UART_LCR_STBITSMSK			(1u<<2)			//
#define	UART_LCR_STBIT1				(0u<<2)			//
#define	UART_LCR_STBIT15			(1u<<2)			//

#define	UART_LCR_PARITYSMSK			(3u<<3)			//
#define	UART_LCR_PARITYNONE			(0u<<3)			//
#define	UART_LCR_PARITYODD			(1u<<3)			//
#define	UART_LCR_PARITYEVEN			(3u<<3)			//

// UART LSR Register
// -----------------

#define	UART_LSR_DATAREADY			(1u<<0)			//
#define	UART_LSR_TEMT				(1u<<5)			//

// UART IER Register
// -----------------

#define	UART_IER_ERBFI				(1u<<0)			//
#define	UART_IER_ETBEI				(1u<<1)			//

// UART IIR Register
// -----------------

#define	UART_IIR_ERBFI				(1u<<2)			//
#define	UART_IIR_ETBEI				(1u<<1)			//

// The UART address map
// --------------------

typedef	struct	_uart {
	union {
		volatile	uint32_t	RBR;				//
		volatile	uint32_t	DLL;				//
		volatile	uint32_t	THR;				//
	};
	union {
		volatile	uint32_t	DLH;				//
		volatile	uint32_t	IER;				//
	};
	union {
		volatile	uint32_t	FCR;				//
		volatile	uint32_t	IIR;				//
	};
	volatile	uint32_t	LCR;					//
	volatile	uint32_t	MCR;					//
	volatile	uint32_t	LSR;					//
	volatile	uint32_t	MSR;					//
	volatile	uint32_t	SCR;					//
	volatile	uint32_t	LPDLL;					//
	volatile	uint32_t	LPDLH;					//
	volatile	uint32_t	reserved1[2];			//
	union {
		volatile	uint32_t	SRBR[16];			//
		volatile	uint32_t	STHR[16];			//
	};
	volatile	uint32_t	FAR;					//
	volatile	uint32_t	TFR;					//
	volatile	uint32_t	RFW;					//
	volatile	uint32_t	USR;					//
	volatile	uint32_t	TFL;					//
	volatile	uint32_t	RFL;					//
	volatile	uint32_t	SRR;					//
	volatile	uint32_t	SRTS;					//
	volatile	uint32_t	SBCR;					//
	volatile	uint32_t	SDMAM;					//
	volatile	uint32_t	SFE;					//
	volatile	uint32_t	SRT;					//
	volatile	uint32_t	STET;					//
	volatile	uint32_t	HTX;					//
	volatile	uint32_t	DMASA;					//
	volatile	uint32_t	TCR;					//
	volatile	uint32_t	DE_EN;					//
	volatile	uint32_t	RE_EN;					//
	volatile	uint32_t	DET;					//
	volatile	uint32_t	TAT;					//
	volatile	uint32_t	DLF;					//
	volatile	uint32_t	RAR;					//
	volatile	uint32_t	TAR;					//
	volatile	uint32_t	LCR_EXT;				//
	volatile	uint32_t	reserved2[9];			//
	volatile	uint32_t	CPR;					//
	volatile	uint32_t	UCV;					//
	volatile	uint32_t	CTR;					//
} uart_t;

#define	uart1	((volatile	uart_t *)0x50210000u)
#define	uart2	((volatile	uart_t *)0x50220000u)
#define	uart3	((volatile	uart_t *)0x50230000u)
