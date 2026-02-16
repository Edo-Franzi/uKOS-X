/*
; RP2350_xip_aux.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_xip_aux equates.
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

// XIP_AUX address definitions
// ---------------------------

typedef struct {
	volatile	uint32_t	STREAM;
	volatile	uint32_t	QMI_DIRECT_TX;
	volatile	uint32_t	QMI_DIRECT_RX;
} XIP_AUX_TypeDef;

#ifdef __cplusplus
#define	XIP_AUX_NS	reinterpret_cast<XIP_AUX_TypeDef *>(0x50500000u)
#define	XIP_AUX_S	reinterpret_cast<XIP_AUX_TypeDef *>(0x50500000u)
#else
#define	XIP_AUX_NS	((XIP_AUX_TypeDef *)0x50500000u)
#define	XIP_AUX_S	((XIP_AUX_TypeDef *)0x50500000u)
#endif

// STREAM Configuration

#define	XIP_AUX_STREAM_STREAM					(0xFFFFFFFFu<<0)
#define	XIP_AUX_STREAM_STREAM_0					(0x1u<<0)

// QMI_DIRECT_TX Configuration

#define	XIP_AUX_QMI_DIRECT_TX_DATA				(0xFFFFu<<0)
#define	XIP_AUX_QMI_DIRECT_TX_DATA_0			(0x1u<<0)
#define	XIP_AUX_QMI_DIRECT_TX_IWIDTH			(0x3u<<16)
#define	XIP_AUX_QMI_DIRECT_TX_IWIDTH_0			(0x1u<<16)
#define	XIP_AUX_QMI_DIRECT_TX_DWIDTH			(0x1u<<18)
#define	XIP_AUX_QMI_DIRECT_TX_OE				(0x1u<<19)
#define	XIP_AUX_QMI_DIRECT_TX_NOPUSH			(0x1u<<20)
#define	XIP_AUX_QMI_DIRECT_TX_IWIDTH_S			(0x0u<<16)
#define	XIP_AUX_QMI_DIRECT_TX_IWIDTH_D			(0x1u<<16)
#define	XIP_AUX_QMI_DIRECT_TX_IWIDTH_Q			(0x2u<<16)

// QMI_DIRECT_RX Configuration

#define	XIP_AUX_QMI_DIRECT_RX_QMI_DIRECT_RX		(0xFFFFu<<0)
#define	XIP_AUX_QMI_DIRECT_RX_QMI_DIRECT_RX_0	(0x1u<<0)
