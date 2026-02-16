/*
; RP2350_coresight_trace.
; =======================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_coresight_trace equates.
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

// CORESIGHT_TRACE address definitions
// -----------------------------------

typedef struct {
	volatile	uint32_t	CTRL_STATUS;
	volatile	uint32_t	CAPTURE_FIFO;
} CORESIGHT_TRACE_TypeDef;

#ifdef __cplusplus
#define	CORESIGHT_TRACE_NS	reinterpret_cast<CORESIGHT_TRACE_TypeDef *>(0x50700000u)
#define	CORESIGHT_TRACE_S	reinterpret_cast<CORESIGHT_TRACE_TypeDef *>(0x50700000u)
#else
#define	CORESIGHT_TRACE_NS	((CORESIGHT_TRACE_TypeDef *)0x50700000u)
#define	CORESIGHT_TRACE_S	((CORESIGHT_TRACE_TypeDef *)0x50700000u)
#endif

// CTRL_STATUS Configuration

#define	CORESIGHT_TRACE_CTRL_STATUS_TRACE_CAPTURE_FIFO_FLUSH	(0x1u<<0)
#define	CORESIGHT_TRACE_CTRL_STATUS_TRACE_CAPTURE_FIFO_OVERFLOW	(0x1u<<1)

// CAPTURE_FIFO Configuration

#define	CORESIGHT_TRACE_CAPTURE_FIFO_RDATA						(0xFFFFFFFFu<<0)
#define	CORESIGHT_TRACE_CAPTURE_FIFO_RDATA_0					(0x1u<<0)
