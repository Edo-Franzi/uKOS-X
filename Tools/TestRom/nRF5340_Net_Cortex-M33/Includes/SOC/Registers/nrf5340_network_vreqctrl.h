/*
; nrf5340_network_vreqctrl.
; =========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_network_vreqctrl equates.
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

// VREQCTRL address definitions
// ----------------------------

typedef struct {
	volatile	uint32_t	RESERVED0[320];
	volatile	uint32_t	VREGRADIO_VREQH;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	VREGRADIO_VREQHREADY;
} VREQCTRL_TypeDef;

#if (defined(__cplusplus))
#define	VREQCTRL_NS	reinterpret_cast<VREQCTRL_TypeDef *>(0x41004000u)

#else
#define	VREQCTRL_NS	((VREQCTRL_TypeDef *)0x41004000u)
#endif

// VREQH Configuration

#define	VREQCTRL_VREGRADIO_VREQH_VREQH					(0x1u<<0)
#define	VREQCTRL_VREGRADIO_VREQH_VREQH_DISABLED			(0x0u<<0)
#define	VREQCTRL_VREGRADIO_VREQH_VREQH_ENABLED			(0x1u<<0)

// VREQHREADY Configuration

#define	VREQCTRL_VREGRADIO_VREQHREADY_READY				(0x1u<<0)
#define	VREQCTRL_VREGRADIO_VREQHREADY_READY_NOTREADY	(0x0u<<0)
#define	VREQCTRL_VREGRADIO_VREQHREADY_READY_READY		(0x1u<<0)
