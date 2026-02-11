/*
; memsys.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		MEMSYS equates.
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

// MEMSYS address definitions
// --------------------------

typedef	struct {
	volatile	uint32_t	MSCR;
	volatile	uint32_t	PFCR;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	ITCMCR;
	volatile	uint32_t	DTCMCR;
	volatile	uint32_t	PAHBCR;
	volatile	uint32_t	RESERVED1[313];
	volatile	uint32_t	ITGU_CTRL;
	volatile	uint32_t	ITGU_CFG;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	ITGU_LUT[16];
	volatile	uint32_t	RESERVED3[44];
	volatile	uint32_t	DTGU_CTRL;
	volatile	uint32_t	DTGU_CFG;
	volatile	uint32_t	RESERVED4[2];
	volatile	uint32_t	DTGU_LUT[16];
} MemSysCtrl_TypeDef;

#if (defined(__cplusplus))
#define	MEMSYSCTL_S		reinterpret_cast<MemSysCtrl_TypeDef *>(0xE001E000u)
#define	MEMSYSCTL_NS	reinterpret_cast<MemSysCtrl_TypeDef *>(0xE001E000u)

#else
#define	MEMSYSCTL_S		((MemSysCtrl_TypeDef *)0xE001E000u)
#define	MEMSYSCTL_NS	((MemSysCtrl_TypeDef *)0xE001E000u)
#endif

// MSCR register

#define	MEMSYSCTL_MSCR_CPWRDN				(0x1u<<17)
#define	MEMSYSCTL_MSCR_DCCLEAN				(0x1u<<16)
#define	MEMSYSCTL_MSCR_ICACTIVE				(0x1u<<13)
#define	MEMSYSCTL_MSCR_DCACTIVE				(0x1u<<12)
#define	MEMSYSCTL_MSCR_TECCCHKDIS			(0x1u<<4)
#define	MEMSYSCTL_MSCR_EVECCFAULT			(0x1u<<3)
#define	MEMSYSCTL_MSCR_FORCEWT				(0x1u<<2)
#define	MEMSYSCTL_MSCR_ECCEN				(0x1u<<1)
