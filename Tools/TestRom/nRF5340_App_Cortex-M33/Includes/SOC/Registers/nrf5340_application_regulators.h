/*
; nrf5340_application_regulators.
; ===============================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_regulators equates.
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

// REGULATORS address definitions
// ------------------------------

typedef struct {
	volatile	uint32_t	RESERVED0[266];
	volatile	uint32_t	MAINREGSTATUS;
	volatile	uint32_t	RESERVED1[53];
	volatile	uint32_t	SYSTEMOFF;
	volatile	uint32_t	RESERVED2[3];
	volatile	uint32_t	POFCON;
	volatile	uint32_t	RESERVED3[124];
	volatile	uint32_t	VREGMAIN_DCDCEN;
	volatile	uint32_t	RESERVED4[126];
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	VREGRADIO_DCDCEN;
	volatile	uint32_t	RESERVED6[126];
	volatile	uint32_t	VREGH_DCDCEN;
} REGULATORS_TypeDef;

#if (defined(__cplusplus))
#define	REGULATORS_NS	reinterpret_cast<REGULATORS_TypeDef *>(0x40004000u)
#define	REGULATORS_S	reinterpret_cast<REGULATORS_TypeDef *>(0x50004000u)

#else
#define	REGULATORS_NS	((REGULATORS_TypeDef *)0x40004000u)
#define	REGULATORS_S	((REGULATORS_TypeDef *)0x50004000u)
#endif

// MAINREGSTATUS Configuration

#define	REGULATORS_MAINREGSTATUS_VREGH					(0x1u<<0)
#define	REGULATORS_MAINREGSTATUS_VREGH_INACTIVE			(0x0u<<0)
#define	REGULATORS_MAINREGSTATUS_VREGH_ACTIVE			(0x1u<<0)

// SYSTEMOFF Configuration

#define	REGULATORS_SYSTEMOFF_SYSTEMOFF					(0x1u<<0)
#define	REGULATORS_SYSTEMOFF_SYSTEMOFF_ENTER			(0x1u<<0)

// POFCON Configuration

#define	REGULATORS_POFCON_THRESHOLDVDDH					(0xFu<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_0				(0x1u<<8)
#define	REGULATORS_POFCON_THRESHOLD						(0xFu<<1)
#define	REGULATORS_POFCON_THRESHOLD_0					(0x1u<<1)
#define	REGULATORS_POFCON_POF							(0x1u<<0)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V27				(0x0u<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V28				(0x1u<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V29				(0x2u<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V30				(0x3u<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V31				(0x4u<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V32				(0x5u<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V33				(0x6u<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V34				(0x7u<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V35				(0x8u<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V36				(0x9u<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V37				(0xAu<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V38				(0xBu<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V39				(0xCu<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V40				(0xDu<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V41				(0xEu<<8)
#define	REGULATORS_POFCON_THRESHOLDVDDH_V42				(0xFu<<8)
#define	REGULATORS_POFCON_THRESHOLD_V19					(0x6u<<1)
#define	REGULATORS_POFCON_THRESHOLD_V20					(0x7u<<1)
#define	REGULATORS_POFCON_THRESHOLD_V21					(0x8u<<1)
#define	REGULATORS_POFCON_THRESHOLD_V22					(0x9u<<1)
#define	REGULATORS_POFCON_THRESHOLD_V23					(0xAu<<1)
#define	REGULATORS_POFCON_THRESHOLD_V24					(0xBu<<1)
#define	REGULATORS_POFCON_THRESHOLD_V25					(0xCu<<1)
#define	REGULATORS_POFCON_THRESHOLD_V26					(0xDu<<1)
#define	REGULATORS_POFCON_THRESHOLD_V27					(0xEu<<1)
#define	REGULATORS_POFCON_THRESHOLD_V28					(0xFu<<1)
#define	REGULATORS_POFCON_POF_DISABLED					(0x0u<<0)
#define	REGULATORS_POFCON_POF_ENABLED					(0x1u<<0)

// DCDCEN Configuration

#define	REGULATORS_VREGMAIN_DCDCEN_DCDCEN				(0x1u<<0)
#define	REGULATORS_VREGMAIN_DCDCEN_DCDCEN_DISABLED		(0x0u<<0)
#define	REGULATORS_VREGMAIN_DCDCEN_DCDCEN_ENABLED		(0x1u<<0)

// DCDCEN Configuration

#define	REGULATORS_VREGRADIO_DCDCEN_DCDCEN				(0x1u<<0)
#define	REGULATORS_VREGRADIO_DCDCEN_DCDCEN_DISABLED		(0x0u<<0)
#define	REGULATORS_VREGRADIO_DCDCEN_DCDCEN_ENABLED		(0x1u<<0)

// DCDCEN Configuration

#define	REGULATORS_VREGH_DCDCEN_DCDCEN					(0x1u<<0)
#define	REGULATORS_VREGH_DCDCEN_DCDCEN_DISABLED			(0x0u<<0)
#define	REGULATORS_VREGH_DCDCEN_DCDCEN_ENABLED			(0x1u<<0)
