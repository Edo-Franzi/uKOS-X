/*
; GD32VF103_exmc.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_exmc equates.
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

// EXMC address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	SNCTL0;
	volatile	uint32_t	SNTCFG0;
	volatile	uint32_t	SNCTL1;
} EXMC_TypeDef;

#if (defined(__cplusplus))
#define	EXMC	reinterpret_cast<EXMC_TypeDef *>(0xA0000000u)

#else
#define	EXMC	((EXMC_TypeDef *)0xA0000000u)
#endif

// SNCTL0 Configuration

#define	EXMC_SNCTL0_NRBKEN		(0x1u<<0)
#define	EXMC_SNCTL0_NRMUX		(0x1u<<1)
#define	EXMC_SNCTL0_NRTP		(0x3u<<2)
#define	EXMC_SNCTL0_NRTP_0		(0x1u<<2)
#define	EXMC_SNCTL0_NRW			(0x3u<<4)
#define	EXMC_SNCTL0_NRW_0		(0x1u<<4)
#define	EXMC_SNCTL0_NREN		(0x1u<<6)
#define	EXMC_SNCTL0_NRWTPOL		(0x1u<<9)
#define	EXMC_SNCTL0_WREN		(0x1u<<12)
#define	EXMC_SNCTL0_NRWTEN		(0x1u<<13)
#define	EXMC_SNCTL0_ASYNCWAIT	(0x1u<<15)

// SNTCFG0 Configuration

#define	EXMC_SNTCFG0_ASET		(0xFu<<0)
#define	EXMC_SNTCFG0_ASET_0		(0x1u<<0)
#define	EXMC_SNTCFG0_AHLD		(0xFu<<4)
#define	EXMC_SNTCFG0_AHLD_0		(0x1u<<4)
#define	EXMC_SNTCFG0_DSET		(0xFFu<<8)
#define	EXMC_SNTCFG0_DSET_0		(0x1u<<8)
#define	EXMC_SNTCFG0_BUSLAT		(0xFu<<16)
#define	EXMC_SNTCFG0_BUSLAT_0	(0x1u<<16)

// SNCTL1 Configuration

#define	EXMC_SNCTL1_NRBKEN		(0x1u<<0)
#define	EXMC_SNCTL1_NRMUX		(0x1u<<1)
#define	EXMC_SNCTL1_NRTP		(0x3u<<2)
#define	EXMC_SNCTL1_NRTP_0		(0x1u<<2)
#define	EXMC_SNCTL1_NRW			(0x3u<<4)
#define	EXMC_SNCTL1_NRW_0		(0x1u<<4)
#define	EXMC_SNCTL1_NREN		(0x1u<<6)
#define	EXMC_SNCTL1_NRWTPOL		(0x1u<<9)
#define	EXMC_SNCTL1_WREN		(0x1u<<12)
#define	EXMC_SNCTL1_NRWTEN		(0x1u<<13)
#define	EXMC_SNCTL1_ASYNCWAIT	(0x1u<<15)
