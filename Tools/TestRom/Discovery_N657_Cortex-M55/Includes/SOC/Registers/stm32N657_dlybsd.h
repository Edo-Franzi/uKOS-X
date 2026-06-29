/*
; stm32N657_dlybsd.
; =================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_dlybsd equates.
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

// DLYBSD address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	CFG;
	volatile	uint32_t	STATUS;
} DLYBSD_TypeDef;

#if (defined(__cplusplus))
#define	DLYBSD_NS	reinterpret_cast<DLYBSD_TypeDef *>(0x48028000u)
#define	DLYBSD_S	reinterpret_cast<DLYBSD_TypeDef *>(0x58028000u)
#define	DLYBSD2_NS	reinterpret_cast<DLYBSD_TypeDef *>(0x48026C00u)
#define	DLYBSD2_S	reinterpret_cast<DLYBSD_TypeDef *>(0x58026C00u)

#else
#define	DLYBSD_NS	((DLYBSD_TypeDef *)0x48028000u)
#define	DLYBSD_S	((DLYBSD_TypeDef *)0x58028000u)
#define	DLYBSD2_NS	((DLYBSD_TypeDef *)0x48026C00u)
#define	DLYBSD2_S	((DLYBSD_TypeDef *)0x58026C00u)
#endif

// CFG Configuration

#define	DLYBSD_CFG_SDMMC_DLL_ANTIGLITCH_EN	(0x1u<<22)
#define	DLYBSD_CFG_SDMMC_DLL_BYP_CMD		(0x1Fu<<17)
#define	DLYBSD_CFG_SDMMC_DLL_BYP_CMD_0		(0x1u<<17)
#define	DLYBSD_CFG_SDMMC_DLL_BYP_EN			(0x1u<<16)
#define	DLYBSD_CFG_SDMMC_RX_TAP_SEL			(0x3Fu<<1)
#define	DLYBSD_CFG_SDMMC_RX_TAP_SEL_0		(0x1u<<1)
#define	DLYBSD_CFG_SDMMC_DLL_EN				(0x1u<<0)

#define	DLYBSD_CFG_SDMMC_DLL_BYP_EN_B_0X0	(0x0u<<16)
#define	DLYBSD_CFG_SDMMC_DLL_BYP_EN_B_0X1	(0x1u<<16)

// STATUS Configuration

#define	DLYBSD_STATUS_SDMMC_RX_TAP_SEL_ACK	(0x1u<<1)
#define	DLYBSD_STATUS_SDMMC_DLL_LOCK		(0x1u<<0)
