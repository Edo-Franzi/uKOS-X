/*
; stm32N657_pssi.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_pssi equates.
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

// PSSI address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	RIS;
	volatile	uint32_t	IER;
	volatile	uint32_t	MIS;
	volatile	uint32_t	ICR;
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	DR;
} PSSI_TypeDef;

#if (defined(__cplusplus))
#define	PSSI_NS	reinterpret_cast<PSSI_TypeDef *>(0x48026400u)
#define	PSSI_S	reinterpret_cast<PSSI_TypeDef *>(0x58026400u)

#else
#define	PSSI_NS	((PSSI_TypeDef *)0x48026400u)
#define	PSSI_S	((PSSI_TypeDef *)0x58026400u)
#endif

// CR Configuration

#define	PSSI_CR_OUTEN				(0x1u<<31)
#define	PSSI_CR_DMAEN				(0x1u<<30)
#define	PSSI_CR_CKSRC				(0x1u<<29)
#define	PSSI_CR_DERDYCFG			(0x7u<<18)
#define	PSSI_CR_DERDYCFG_0			(0x1u<<18)
#define	PSSI_CR_ENABLE				(0x1u<<14)
#define	PSSI_CR_EDM					(0x3u<<10)
#define	PSSI_CR_EDM_0				(0x1u<<10)
#define	PSSI_CR_RDYPOL				(0x1u<<8)
#define	PSSI_CR_DEPOL				(0x1u<<6)
#define	PSSI_CR_CKPOL				(0x1u<<5)

#define	PSSI_CR_OUTEN_B_0X0			(0x0u<<31)
#define	PSSI_CR_OUTEN_B_0X1			(0x1u<<31)
#define	PSSI_CR_DMAEN_B_0X0			(0x0u<<30)
#define	PSSI_CR_DMAEN_B_0X1			(0x1u<<30)
#define	PSSI_CR_CKSRC_B_0X0			(0x0u<<29)
#define	PSSI_CR_CKSRC_B_0X1			(0x1u<<29)
#define	PSSI_CR_DERDYCFG_B_0X0		(0x0u<<18)
#define	PSSI_CR_DERDYCFG_B_0X1		(0x1u<<18)
#define	PSSI_CR_DERDYCFG_B_0X2		(0x2u<<18)
#define	PSSI_CR_DERDYCFG_B_0X3		(0x3u<<18)
#define	PSSI_CR_DERDYCFG_B_0X4		(0x4u<<18)
#define	PSSI_CR_DERDYCFG_B_0X5		(0x5u<<18)
#define	PSSI_CR_DERDYCFG_B_0X6		(0x6u<<18)
#define	PSSI_CR_DERDYCFG_B_0X7		(0x7u<<18)
#define	PSSI_CR_ENABLE_B_0X0		(0x0u<<14)
#define	PSSI_CR_ENABLE_B_0X1		(0x1u<<14)
#define	PSSI_CR_EDM_B_0X0			(0x0u<<10)
#define	PSSI_CR_EDM_B_0X3			(0x3u<<10)
#define	PSSI_CR_RDYPOL_B_0X0		(0x0u<<8)
#define	PSSI_CR_RDYPOL_B_0X1		(0x1u<<8)
#define	PSSI_CR_DEPOL_B_0X0			(0x0u<<6)
#define	PSSI_CR_DEPOL_B_0X1			(0x1u<<6)
#define	PSSI_CR_CKPOL_B_0X0			(0x0u<<5)
#define	PSSI_CR_CKPOL_B_0X1			(0x1u<<5)

// SR Configuration

#define	PSSI_SR_RTT1B				(0x1u<<3)
#define	PSSI_SR_RTT4B				(0x1u<<2)

#define	PSSI_SR_RTT1B_B_0X1			(0x1u<<3)
#define	PSSI_SR_RTT1B_B_0X0			(0x0u<<3)
#define	PSSI_SR_RTT4B_B_0X1			(0x1u<<2)
#define	PSSI_SR_RTT4B_B_0X0			(0x0u<<2)

// RIS Configuration

#define	PSSI_RIS_OVR_RIS			(0x1u<<1)

#define	PSSI_RIS_OVR_RIS_B_0X0		(0x0u<<1)
#define	PSSI_RIS_OVR_RIS_B_0X1		(0x1u<<1)

// IER Configuration

#define	PSSI_IER_OVR_IE				(0x1u<<1)

#define	PSSI_IER_OVR_IE_B_0X0		(0x0u<<1)
#define	PSSI_IER_OVR_IE_B_0X1		(0x1u<<1)

// MIS Configuration

#define	PSSI_MIS_OVR_MIS			(0x1u<<1)

#define	PSSI_MIS_OVR_MIS_B_0X0		(0x0u<<1)
#define	PSSI_MIS_OVR_MIS_B_0X1		(0x1u<<1)

// ICR Configuration

#define	PSSI_ICR_OVR_ISC			(0x1u<<1)

// DR Configuration

#define	PSSI_DR_BYTE3				(0xFFu<<24)
#define	PSSI_DR_BYTE3_0				(0x1u<<24)
#define	PSSI_DR_BYTE2				(0xFFu<<16)
#define	PSSI_DR_BYTE2_0				(0x1u<<16)
#define	PSSI_DR_BYTE1				(0xFFu<<8)
#define	PSSI_DR_BYTE1_0				(0x1u<<8)
#define	PSSI_DR_BYTE0				(0xFFu<<0)
#define	PSSI_DR_BYTE0_0				(0x1u<<0)
