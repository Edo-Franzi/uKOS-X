/*
; stm32U5Gx_fmac.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_fmac equates.
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

// FMAC address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	X1BUFCFG;
	volatile	uint32_t	X2BUFCFG;
	volatile	uint32_t	YBUFCFG;
	volatile	uint32_t	PARAM;
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	WDATA;
	volatile	uint32_t	RDATA;
} FMAC_TypeDef;

#if (defined(__cplusplus))
#define	FMAC_NS	reinterpret_cast<FMAC_TypeDef *>(0x40021400u)
#define	FMAC_S	reinterpret_cast<FMAC_TypeDef *>(0x50021400u)

#else
#define	FMAC_NS	((FMAC_TypeDef *)0x40021400u)
#define	FMAC_S	((FMAC_TypeDef *)0x50021400u)
#endif

// X1BUFCFG Configuration

#define	FMAC_X1BUFCFG_FULL_WM		(0x3u<<24)
#define	FMAC_X1BUFCFG_FULL_WM_0		(0x1u<<24)
#define	FMAC_X1BUFCFG_X1_BUF_SIZE	(0xFFu<<8)
#define	FMAC_X1BUFCFG_X1_BUF_SIZE_0	(0x1u<<8)
#define	FMAC_X1BUFCFG_X1_BASE		(0xFFu<<0)
#define	FMAC_X1BUFCFG_X1_BASE_0		(0x1u<<0)

// X2BUFCFG Configuration

#define	FMAC_X2BUFCFG_X2_BUF_SIZE	(0xFFu<<8)
#define	FMAC_X2BUFCFG_X2_BUF_SIZE_0	(0x1u<<8)
#define	FMAC_X2BUFCFG_X2_BASE		(0xFFu<<0)
#define	FMAC_X2BUFCFG_X2_BASE_0		(0x1u<<0)

// YBUFCFG Configuration

#define	FMAC_YBUFCFG_EMPTY_WM		(0x3u<<24)
#define	FMAC_YBUFCFG_EMPTY_WM_0		(0x1u<<24)
#define	FMAC_YBUFCFG_Y_BUF_SIZE		(0xFFu<<8)
#define	FMAC_YBUFCFG_Y_BUF_SIZE_0	(0x1u<<8)
#define	FMAC_YBUFCFG_Y_BASE			(0xFFu<<0)
#define	FMAC_YBUFCFG_Y_BASE_0		(0x1u<<0)

// PARAM Configuration

#define	FMAC_PARAM_P				(0xFFu<<0)
#define	FMAC_PARAM_P_0				(0x1u<<0)
#define	FMAC_PARAM_Q				(0xFFu<<8)
#define	FMAC_PARAM_Q_0				(0x1u<<8)
#define	FMAC_PARAM_R				(0xFFu<<16)
#define	FMAC_PARAM_R_0				(0x1u<<16)
#define	FMAC_PARAM_FUNC				(0x7Fu<<24)
#define	FMAC_PARAM_FUNC_0			(0x1u<<24)
#define	FMAC_PARAM_START			(0x1u<<31)

// CR Configuration

#define	FMAC_CR_RIEN				(0x1u<<0)
#define	FMAC_CR_WIEN				(0x1u<<1)
#define	FMAC_CR_OVFLIEN				(0x1u<<2)
#define	FMAC_CR_UNFLIEN				(0x1u<<3)
#define	FMAC_CR_SATIEN				(0x1u<<4)
#define	FMAC_CR_DMAREN				(0x1u<<8)
#define	FMAC_CR_DMAWEN				(0x1u<<9)
#define	FMAC_CR_CLIPEN				(0x1u<<15)
#define	FMAC_CR_RESET				(0x1u<<16)

// SR Configuration

#define	FMAC_SR_SAT					(0x1u<<10)
#define	FMAC_SR_UNFL				(0x1u<<9)
#define	FMAC_SR_OVFL				(0x1u<<8)
#define	FMAC_SR_X1FULL				(0x1u<<1)
#define	FMAC_SR_YEMPTY				(0x1u<<0)

// WDATA Configuration

#define	FMAC_WDATA_WDATA			(0xFFFFu<<0)
#define	FMAC_WDATA_WDATA_0			(0x1u<<0)

// RDATA Configuration

#define	FMAC_RDATA_RDATA			(0xFFFFu<<0)
#define	FMAC_RDATA_RDATA_0			(0x1u<<0)
