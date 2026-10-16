/*
; stm32U5Gx_gtzc2_tzsc.
; =====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_gtzc2_tzsc equates.
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

// GTZC2_TZSC address definitions
// ------------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	RESERVED0[3];
	volatile	uint32_t	SECCFGR1;
	volatile	uint32_t	RESERVED1[3];
	volatile	uint32_t	PRIVCFGR1;
} GTZC2_TZSC_TypeDef;

#if (defined(__cplusplus))
#define	GTZC2_TZSC_NS	reinterpret_cast<GTZC2_TZSC_TypeDef *>(0x46023000u)
#define	GTZC2_TZSC_S	reinterpret_cast<GTZC2_TZSC_TypeDef *>(0x56023000u)

#else
#define	GTZC2_TZSC_NS	((GTZC2_TZSC_TypeDef *)0x46023000u)
#define	GTZC2_TZSC_S	((GTZC2_TZSC_TypeDef *)0x56023000u)
#endif

// CR Configuration

#define	GTZC2_TZSC_CR_LCK					(0x1u<<0)

// SECCFGR1 Configuration

#define	GTZC2_TZSC_SECCFGR1_ADF1SEC			(0x1u<<12)
#define	GTZC2_TZSC_SECCFGR1_DAC1SEC			(0x1u<<11)
#define	GTZC2_TZSC_SECCFGR1_VREFBUFSEC		(0x1u<<9)
#define	GTZC2_TZSC_SECCFGR1_ADC2SEC			(0x1u<<8)
#define	GTZC2_TZSC_SECCFGR1_COMPSEC			(0x1u<<7)
#define	GTZC2_TZSC_SECCFGR1_OPAMPSEC		(0x1u<<6)
#define	GTZC2_TZSC_SECCFGR1_LPTIM4SEC		(0x1u<<5)
#define	GTZC2_TZSC_SECCFGR1_LPTIM3SEC		(0x1u<<4)
#define	GTZC2_TZSC_SECCFGR1_LPTIM1SEC		(0x1u<<3)
#define	GTZC2_TZSC_SECCFGR1_I2C3SEC			(0x1u<<2)
#define	GTZC2_TZSC_SECCFGR1_LPUART1SEC		(0x1u<<1)
#define	GTZC2_TZSC_SECCFGR1_SPI3SEC			(0x1u<<0)

// PRIVCFGR1 Configuration

#define	GTZC2_TZSC_PRIVCFGR1_ADF1PRIV		(0x1u<<12)
#define	GTZC2_TZSC_PRIVCFGR1_DAC1PRIV		(0x1u<<11)
#define	GTZC2_TZSC_PRIVCFGR1_VREFBUFPRIV	(0x1u<<9)
#define	GTZC2_TZSC_PRIVCFGR1_ADC2PRIV		(0x1u<<8)
#define	GTZC2_TZSC_PRIVCFGR1_COMPPRIV		(0x1u<<7)
#define	GTZC2_TZSC_PRIVCFGR1_OPAMPPRIV		(0x1u<<6)
#define	GTZC2_TZSC_PRIVCFGR1_LPTIM4PRIV		(0x1u<<5)
#define	GTZC2_TZSC_PRIVCFGR1_LPTIM3PRIV		(0x1u<<4)
#define	GTZC2_TZSC_PRIVCFGR1_LPTIM1PRIV		(0x1u<<3)
#define	GTZC2_TZSC_PRIVCFGR1_I2C3PRIV		(0x1u<<2)
#define	GTZC2_TZSC_PRIVCFGR1_LPUART1PRIV	(0x1u<<1)
#define	GTZC2_TZSC_PRIVCFGR1_SPI3PRIV		(0x1u<<0)
