/*
; stm32N657_iwdg.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_iwdg equates.
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

// IWDG address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	KR;
	volatile	uint32_t	PR;
	volatile	uint32_t	RLR;
	volatile	uint32_t	SR;
	volatile	uint32_t	WINR;
	volatile	uint32_t	EWCR;
	volatile	uint32_t	ICR;
} IWDG_TypeDef;

#if (defined(__cplusplus))
#define	IWDG_NS	reinterpret_cast<IWDG_TypeDef *>(0x46004800u)
#define	IWDG_S	reinterpret_cast<IWDG_TypeDef *>(0x56004800u)

#else
#define	IWDG_NS	((IWDG_TypeDef *)0x46004800u)
#define	IWDG_S	((IWDG_TypeDef *)0x56004800u)
#endif

// KR Configuration

#define	IWDG_KR_KEY				(0xFFFFu<<0)
#define	IWDG_KR_KEY_0			(0x1u<<0)

// PR Configuration

#define	IWDG_PR_PR				(0xFu<<0)
#define	IWDG_PR_PR_0			(0x1u<<0)

#define	IWDG_PR_PR_B_0X0		(0x0u<<0)
#define	IWDG_PR_PR_B_0X1		(0x1u<<0)
#define	IWDG_PR_PR_B_0X2		(0x2u<<0)
#define	IWDG_PR_PR_B_0X3		(0x3u<<0)
#define	IWDG_PR_PR_B_0X4		(0x4u<<0)
#define	IWDG_PR_PR_B_0X5		(0x5u<<0)
#define	IWDG_PR_PR_B_0X6		(0x6u<<0)
#define	IWDG_PR_PR_B_0X7		(0x7u<<0)

// RLR Configuration

#define	IWDG_RLR_RL				(0xFFFu<<0)
#define	IWDG_RLR_RL_0			(0x1u<<0)

// SR Configuration

#define	IWDG_SR_EWIF			(0x1u<<15)
#define	IWDG_SR_ONF				(0x1u<<8)
#define	IWDG_SR_EWU				(0x1u<<3)
#define	IWDG_SR_WVU				(0x1u<<2)
#define	IWDG_SR_RVU				(0x1u<<1)
#define	IWDG_SR_PVU				(0x1u<<0)

#define	IWDG_SR_ONF_B_0X0		(0x0u<<8)
#define	IWDG_SR_ONF_B_0X1		(0x1u<<8)

// WINR Configuration

#define	IWDG_WINR_WIN			(0xFFFu<<0)
#define	IWDG_WINR_WIN_0			(0x1u<<0)

// EWCR Configuration

#define	IWDG_EWCR_EWIE			(0x1u<<15)
#define	IWDG_EWCR_EWIT			(0xFFFu<<0)
#define	IWDG_EWCR_EWIT_0		(0x1u<<0)

#define	IWDG_EWCR_EWIE_B_0X0	(0x0u<<15)
#define	IWDG_EWCR_EWIE_B_0X1	(0x1u<<15)

// ICR Configuration

#define	IWDG_ICR_EWIC			(0x1u<<15)
