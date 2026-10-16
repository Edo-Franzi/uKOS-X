/*
; stm32F217_flash.
; ================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_flash equates.
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

// FLASH address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	ACR;
	volatile	uint32_t	KEYR;
	volatile	uint32_t	OPTKEYR;
	volatile	uint32_t	SR;
	volatile	uint32_t	CR;
	volatile	uint32_t	OPTCR;
} FLASH_TypeDef;

#if (defined(__cplusplus))
#define	FLASH	reinterpret_cast<FLASH_TypeDef *>(0x40023C00u)

#else
#define	FLASH	((FLASH_TypeDef *)0x40023C00u)
#endif

// ACR Configuration

#define	FLASH_ACR_DCRST			(0x1u<<12)
#define	FLASH_ACR_ICRST			(0x1u<<11)
#define	FLASH_ACR_DCEN			(0x1u<<10)
#define	FLASH_ACR_ICEN			(0x1u<<9)
#define	FLASH_ACR_PRFTEN		(0x1u<<8)
#define	FLASH_ACR_LATENCY		(0x7u<<0)
#define	FLASH_ACR_LATENCY_0		(0x1u<<0)

// KEYR Configuration

#define	FLASH_KEYR_KEY			(0xFFFFFFFFu<<0)
#define	FLASH_KEYR_KEY_0		(0x1u<<0)

// OPTKEYR Configuration

#define	FLASH_OPTKEYR_OPTKEY	(0xFFFFFFFFu<<0)
#define	FLASH_OPTKEYR_OPTKEY_0	(0x1u<<0)

// SR Configuration

#define	FLASH_SR_BSY			(0x1u<<16)
#define	FLASH_SR_PGSERR			(0x1u<<7)
#define	FLASH_SR_PGPERR			(0x1u<<6)
#define	FLASH_SR_PGAERR			(0x1u<<5)
#define	FLASH_SR_WRPERR			(0x1u<<4)
#define	FLASH_SR_OPERR			(0x1u<<1)
#define	FLASH_SR_EOP			(0x1u<<0)

// CR Configuration

#define	FLASH_CR_LOCK			(0x1u<<31)
#define	FLASH_CR_ERRIE			(0x1u<<25)
#define	FLASH_CR_EOPIE			(0x1u<<24)
#define	FLASH_CR_STRT			(0x1u<<16)
#define	FLASH_CR_PSIZE			(0x3u<<8)
#define	FLASH_CR_PSIZE_0		(0x1u<<8)
#define	FLASH_CR_SNB			(0xFu<<3)
#define	FLASH_CR_SNB_0			(0x1u<<3)
#define	FLASH_CR_MER			(0x1u<<2)
#define	FLASH_CR_SER			(0x1u<<1)
#define	FLASH_CR_PG				(0x1u<<0)

// OPTCR Configuration

#define	FLASH_OPTCR_NWRP		(0xFFFu<<16)
#define	FLASH_OPTCR_NWRP_0		(0x1u<<16)
#define	FLASH_OPTCR_RDP			(0xFFu<<8)
#define	FLASH_OPTCR_RDP_0		(0x1u<<8)
#define	FLASH_OPTCR_NRST_STDBY	(0x1u<<7)
#define	FLASH_OPTCR_NRST_STOP	(0x1u<<6)
#define	FLASH_OPTCR_WDG_SW		(0x1u<<5)
#define	FLASH_OPTCR_BOR_LEV		(0x3u<<2)
#define	FLASH_OPTCR_BOR_LEV_0	(0x1u<<2)
#define	FLASH_OPTCR_OPTSTRT		(0x1u<<1)
#define	FLASH_OPTCR_OPTLOCK		(0x1u<<0)
