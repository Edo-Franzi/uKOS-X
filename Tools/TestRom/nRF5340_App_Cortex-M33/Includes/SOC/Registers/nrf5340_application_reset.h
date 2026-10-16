/*
; nrf5340_application_reset.
; ==========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_reset equates.
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

// RESET address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	RESERVED0[256];
	volatile	uint32_t	RESETREAS;
	volatile	uint32_t	RESERVED1[131];
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	NETWORK_FORCEOFF;
} RESET_TypeDef;

#if (defined(__cplusplus))
#define	RESET_NS	reinterpret_cast<RESET_TypeDef *>(0x40005000u)
#define	RESET_S		reinterpret_cast<RESET_TypeDef *>(0x50005000u)

#else
#define	RESET_NS	((RESET_TypeDef *)0x40005000u)
#define	RESET_S		((RESET_TypeDef *)0x50005000u)
#endif

// RESETREAS Configuration

#define	RESET_RESETREAS_VBUS					(0x1u<<26)
#define	RESET_RESETREAS_DOG1					(0x1u<<25)
#define	RESET_RESETREAS_NFC						(0x1u<<24)
#define	RESET_RESETREAS_DIF						(0x1u<<7)
#define	RESET_RESETREAS_LPCOMP					(0x1u<<6)
#define	RESET_RESETREAS_OFF						(0x1u<<5)
#define	RESET_RESETREAS_LOCKUP					(0x1u<<4)
#define	RESET_RESETREAS_SREQ					(0x1u<<3)
#define	RESET_RESETREAS_CTRLAP					(0x1u<<2)
#define	RESET_RESETREAS_DOG0					(0x1u<<1)
#define	RESET_RESETREAS_RESETPIN				(0x1u<<0)
#define	RESET_RESETREAS_VBUS_NOTDETECTED		(0x0u<<26)
#define	RESET_RESETREAS_VBUS_DETECTED			(0x1u<<26)
#define	RESET_RESETREAS_DOG1_NOTDETECTED		(0x0u<<25)
#define	RESET_RESETREAS_DOG1_DETECTED			(0x1u<<25)
#define	RESET_RESETREAS_NFC_NOTDETECTED			(0x0u<<24)
#define	RESET_RESETREAS_NFC_DETECTED			(0x1u<<24)
#define	RESET_RESETREAS_DIF_NOTDETECTED			(0x0u<<7)
#define	RESET_RESETREAS_DIF_DETECTED			(0x1u<<7)
#define	RESET_RESETREAS_LPCOMP_NOTDETECTED		(0x0u<<6)
#define	RESET_RESETREAS_LPCOMP_DETECTED			(0x1u<<6)
#define	RESET_RESETREAS_OFF_NOTDETECTED			(0x0u<<5)
#define	RESET_RESETREAS_OFF_DETECTED			(0x1u<<5)
#define	RESET_RESETREAS_LOCKUP_NOTDETECTED		(0x0u<<4)
#define	RESET_RESETREAS_LOCKUP_DETECTED			(0x1u<<4)
#define	RESET_RESETREAS_SREQ_NOTDETECTED		(0x0u<<3)
#define	RESET_RESETREAS_SREQ_DETECTED			(0x1u<<3)
#define	RESET_RESETREAS_CTRLAP_NOTDETECTED		(0x0u<<2)
#define	RESET_RESETREAS_CTRLAP_DETECTED			(0x1u<<2)
#define	RESET_RESETREAS_DOG0_NOTDETECTED		(0x0u<<1)
#define	RESET_RESETREAS_DOG0_DETECTED			(0x1u<<1)
#define	RESET_RESETREAS_RESETPIN_NOTDETECTED	(0x0u<<0)
#define	RESET_RESETREAS_RESETPIN_DETECTED		(0x1u<<0)

// FORCEOFF Configuration

#define	RESET_NETWORK_FORCEOFF_FORCEOFF			(0x1u<<0)
#define	RESET_NETWORK_FORCEOFF_FORCEOFF_RELEASE	(0x0u<<0)
#define	RESET_NETWORK_FORCEOFF_FORCEOFF_HOLD	(0x1u<<0)
