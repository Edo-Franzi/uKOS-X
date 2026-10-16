/*
; nrf5340_network_nvmc.
; =====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_network_nvmc equates.
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

// NVMC address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	RESERVED0[256];
	volatile	uint32_t	READY;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	READYNEXT;
	volatile	uint32_t	RESERVED2[62];
	volatile	uint32_t	CONFIG;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	ERASEALL;
	volatile	uint32_t	RESERVED4[3];
	volatile	uint32_t	ERASEPAGEPARTIALCFG;
	volatile	uint32_t	RESERVED5[8];
	volatile	uint32_t	ICACHECNF;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	IHIT;
	volatile	uint32_t	IMISS;
} NVMC_TypeDef;

#if (defined(__cplusplus))
#define	NVMC_NS	reinterpret_cast<NVMC_TypeDef *>(0x41080000u)

#else
#define	NVMC_NS	((NVMC_TypeDef *)0x41080000u)
#endif

// READY Configuration

#define	NVMC_READY_READY					(0x1u<<0)
#define	NVMC_READY_READY_BUSY				(0x0u<<0)
#define	NVMC_READY_READY_READY				(0x1u<<0)

// READYNEXT Configuration

#define	NVMC_READYNEXT_READYNEXT			(0x1u<<0)
#define	NVMC_READYNEXT_READYNEXT_BUSY		(0x0u<<0)
#define	NVMC_READYNEXT_READYNEXT_READY		(0x1u<<0)

// CONFIG Configuration

#define	NVMC_CONFIG_WEN						(0x7u<<0)
#define	NVMC_CONFIG_WEN_0					(0x1u<<0)
#define	NVMC_CONFIG_WEN_REN					(0x0u<<0)
#define	NVMC_CONFIG_WEN_WEN					(0x1u<<0)
#define	NVMC_CONFIG_WEN_EEN					(0x2u<<0)
#define	NVMC_CONFIG_WEN_PEEN				(0x4u<<0)

// ERASEALL Configuration

#define	NVMC_ERASEALL_ERASEALL				(0x1u<<0)
#define	NVMC_ERASEALL_ERASEALL_NOOPERATION	(0x0u<<0)
#define	NVMC_ERASEALL_ERASEALL_ERASE		(0x1u<<0)

// ERASEPAGEPARTIALCFG Configuration

#define	NVMC_ERASEPAGEPARTIALCFG_DURATION	(0x7Fu<<0)
#define	NVMC_ERASEPAGEPARTIALCFG_DURATION_0	(0x1u<<0)

// ICACHECNF Configuration

#define	NVMC_ICACHECNF_CACHEPROFEN			(0x1u<<8)
#define	NVMC_ICACHECNF_CACHEEN				(0x1u<<0)
#define	NVMC_ICACHECNF_CACHEPROFEN_DISABLED	(0x0u<<8)
#define	NVMC_ICACHECNF_CACHEPROFEN_ENABLED	(0x1u<<8)
#define	NVMC_ICACHECNF_CACHEEN_DISABLED		(0x0u<<0)
#define	NVMC_ICACHECNF_CACHEEN_ENABLED		(0x1u<<0)

// IHIT Configuration

#define	NVMC_IHIT_HITS						(0xFFFFFFFFu<<0)
#define	NVMC_IHIT_HITS_0					(0x1u<<0)

// IMISS Configuration

#define	NVMC_IMISS_MISSES					(0xFFFFFFFFu<<0)
#define	NVMC_IMISS_MISSES_0					(0x1u<<0)
