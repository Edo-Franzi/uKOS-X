/*
; nrf5340_application_tad.
; ========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_tad equates.
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

// TAD address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	CLOCKSTART;
	volatile	uint32_t	CLOCKSTOP;
	volatile	uint32_t	RESERVED1[317];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	PSEL_TRACECLK;
	volatile	uint32_t	PSEL_TRACEDATA0;
	volatile	uint32_t	PSEL_TRACEDATA1;
	volatile	uint32_t	PSEL_TRACEDATA2;
	volatile	uint32_t	PSEL_TRACEDATA3;
	volatile	uint32_t	TRACEPORTSPEED;
} TAD_TypeDef;

#if (defined(__cplusplus))
#define	TAD_S	reinterpret_cast<TAD_TypeDef *>(0xE0080000u)

#else
#define	TAD_S	((TAD_TypeDef *)0xE0080000u)
#endif

// CLOCKSTART Configuration

#define	TAD_CLOCKSTART_START							(0x1u<<0)
#define	TAD_CLOCKSTART_START_START						(0x1u<<0)

// CLOCKSTOP Configuration

#define	TAD_CLOCKSTOP_STOP								(0x1u<<0)
#define	TAD_CLOCKSTOP_STOP_STOP							(0x1u<<0)

// ENABLE Configuration

#define	TAD_ENABLE_ENABLE								(0x1u<<0)
#define	TAD_ENABLE_ENABLE_DISABLED						(0x0u<<0)
#define	TAD_ENABLE_ENABLE_ENABLED						(0x1u<<0)

// TRACECLK Configuration

#define	TAD_PSEL_TRACECLK_CONNECT						(0x1u<<31)
#define	TAD_PSEL_TRACECLK_PIN							(0x1Fu<<0)
#define	TAD_PSEL_TRACECLK_PIN_0							(0x1u<<0)
#define	TAD_PSEL_TRACECLK_CONNECT_DISCONNECTED			(0x1u<<31)
#define	TAD_PSEL_TRACECLK_CONNECT_CONNECTED				(0x0u<<31)
#define	TAD_PSEL_TRACECLK_PIN_TRACECLK					(0xCu<<0)

// TRACEDATA0 Configuration

#define	TAD_PSEL_TRACEDATA0_CONNECT						(0x1u<<31)
#define	TAD_PSEL_TRACEDATA0_PIN							(0x1Fu<<0)
#define	TAD_PSEL_TRACEDATA0_PIN_0						(0x1u<<0)
#define	TAD_PSEL_TRACEDATA0_CONNECT_DISCONNECTED		(0x1u<<31)
#define	TAD_PSEL_TRACEDATA0_CONNECT_CONNECTED			(0x0u<<31)
#define	TAD_PSEL_TRACEDATA0_PIN_TRACEDATA0				(0xBu<<0)

// TRACEDATA1 Configuration

#define	TAD_PSEL_TRACEDATA1_CONNECT						(0x1u<<31)
#define	TAD_PSEL_TRACEDATA1_PIN							(0x1Fu<<0)
#define	TAD_PSEL_TRACEDATA1_PIN_0						(0x1u<<0)
#define	TAD_PSEL_TRACEDATA1_CONNECT_DISCONNECTED		(0x1u<<31)
#define	TAD_PSEL_TRACEDATA1_CONNECT_CONNECTED			(0x0u<<31)
#define	TAD_PSEL_TRACEDATA1_PIN_TRACEDATA1				(0xAu<<0)

// TRACEDATA2 Configuration

#define	TAD_PSEL_TRACEDATA2_CONNECT						(0x1u<<31)
#define	TAD_PSEL_TRACEDATA2_PIN							(0x1Fu<<0)
#define	TAD_PSEL_TRACEDATA2_PIN_0						(0x1u<<0)
#define	TAD_PSEL_TRACEDATA2_CONNECT_DISCONNECTED		(0x1u<<31)
#define	TAD_PSEL_TRACEDATA2_CONNECT_CONNECTED			(0x0u<<31)
#define	TAD_PSEL_TRACEDATA2_PIN_TRACEDATA2				(0x9u<<0)

// TRACEDATA3 Configuration

#define	TAD_PSEL_TRACEDATA3_CONNECT						(0x1u<<31)
#define	TAD_PSEL_TRACEDATA3_PIN							(0x1Fu<<0)
#define	TAD_PSEL_TRACEDATA3_PIN_0						(0x1u<<0)
#define	TAD_PSEL_TRACEDATA3_CONNECT_DISCONNECTED		(0x1u<<31)
#define	TAD_PSEL_TRACEDATA3_CONNECT_CONNECTED			(0x0u<<31)
#define	TAD_PSEL_TRACEDATA3_PIN_TRACEDATA3				(0x8u<<0)

// TRACEPORTSPEED Configuration

#define	TAD_TRACEPORTSPEED_TRACEPORTSPEED				(0x3u<<0)
#define	TAD_TRACEPORTSPEED_TRACEPORTSPEED_0				(0x1u<<0)
#define	TAD_TRACEPORTSPEED_TRACEPORTSPEED_64MHZ			(0x0u<<0)
#define	TAD_TRACEPORTSPEED_TRACEPORTSPEED_32MHZ			(0x1u<<0)
#define	TAD_TRACEPORTSPEED_TRACEPORTSPEED_16MHZ			(0x2u<<0)
#define	TAD_TRACEPORTSPEED_TRACEPORTSPEED_8MHZ			(0x3u<<0)
