/*
; stm32N657_cacheaxi.
; ===================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_cacheaxi equates.
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

// CACHEAXI address definitions
// ----------------------------

typedef struct {
	volatile	uint32_t	CR1;
	volatile	uint32_t	SR;
	volatile	uint32_t	IER;
	volatile	uint32_t	FCR;
	volatile	uint32_t	RHMONR;
	volatile	uint32_t	RMMONR;
	volatile	uint32_t	RAMMONR;
	volatile	uint32_t	EVIMONR;
	volatile	uint32_t	WHMONR;
	volatile	uint32_t	WMMONR;
	volatile	uint32_t	WAMMONR;
	volatile	uint32_t	WTMONR;
	volatile	uint32_t	RESERVED0[52];
	volatile	uint32_t	CR2;
	volatile	uint32_t	CMDRSADDRR;
	volatile	uint32_t	CMDREADDRR;
} CACHEAXI_TypeDef;

#if (defined(__cplusplus))
#define	CACHEAXI_NS	reinterpret_cast<CACHEAXI_TypeDef *>(0x480DFC00u)
#define	CACHEAXI_S	reinterpret_cast<CACHEAXI_TypeDef *>(0x580DFC00u)

#else
#define	CACHEAXI_NS	((CACHEAXI_TypeDef *)0x480DFC00u)
#define	CACHEAXI_S	((CACHEAXI_TypeDef *)0x580DFC00u)
#endif

// CR1 Configuration

#define	CACHEAXI_CR1_EVIMRST				(0x1u<<31)
#define	CACHEAXI_CR1_WTMRST					(0x1u<<30)
#define	CACHEAXI_CR1_EVIMEN					(0x1u<<29)
#define	CACHEAXI_CR1_WTMEN					(0x1u<<28)
#define	CACHEAXI_CR1_WAMMRST				(0x1u<<27)
#define	CACHEAXI_CR1_RAMMRST				(0x1u<<26)
#define	CACHEAXI_CR1_WAMMEN					(0x1u<<25)
#define	CACHEAXI_CR1_RAMMEN					(0x1u<<24)
#define	CACHEAXI_CR1_WMISSMRST				(0x1u<<23)
#define	CACHEAXI_CR1_WHITMRST				(0x1u<<22)
#define	CACHEAXI_CR1_WMISSMEN				(0x1u<<21)
#define	CACHEAXI_CR1_WHITMEN				(0x1u<<20)
#define	CACHEAXI_CR1_RMISSMRST				(0x1u<<19)
#define	CACHEAXI_CR1_RHITMRST				(0x1u<<18)
#define	CACHEAXI_CR1_RMISSMEN				(0x1u<<17)
#define	CACHEAXI_CR1_RHITMEN				(0x1u<<16)
#define	CACHEAXI_CR1_CACHEINV				(0x1u<<1)
#define	CACHEAXI_CR1_EN						(0x1u<<0)

#define	CACHEAXI_CR1_EVIMRST_B_0X0			(0x0u<<31)
#define	CACHEAXI_CR1_EVIMRST_B_0X1			(0x1u<<31)
#define	CACHEAXI_CR1_WTMRST_B_0X0			(0x0u<<30)
#define	CACHEAXI_CR1_WTMRST_B_0X1			(0x1u<<30)
#define	CACHEAXI_CR1_EVIMEN_B_0X0			(0x0u<<29)
#define	CACHEAXI_CR1_EVIMEN_B_0X1			(0x1u<<29)
#define	CACHEAXI_CR1_WTMEN_B_0X0			(0x0u<<28)
#define	CACHEAXI_CR1_WTMEN_B_0X1			(0x1u<<28)
#define	CACHEAXI_CR1_WAMMRST_B_0X0			(0x0u<<27)
#define	CACHEAXI_CR1_WAMMRST_B_0X1			(0x1u<<27)
#define	CACHEAXI_CR1_RAMMRST_B_0X0			(0x0u<<26)
#define	CACHEAXI_CR1_RAMMRST_B_0X1			(0x1u<<26)
#define	CACHEAXI_CR1_WAMMEN_B_0X0			(0x0u<<25)
#define	CACHEAXI_CR1_WAMMEN_B_0X1			(0x1u<<25)
#define	CACHEAXI_CR1_RAMMEN_B_0X0			(0x0u<<24)
#define	CACHEAXI_CR1_RAMMEN_B_0X1			(0x1u<<24)
#define	CACHEAXI_CR1_WMISSMRST_B_0X0		(0x0u<<23)
#define	CACHEAXI_CR1_WMISSMRST_B_0X1		(0x1u<<23)
#define	CACHEAXI_CR1_WHITMRST_B_0X0			(0x0u<<22)
#define	CACHEAXI_CR1_WHITMRST_B_0X1			(0x1u<<22)
#define	CACHEAXI_CR1_WMISSMEN_B_0X0			(0x0u<<21)
#define	CACHEAXI_CR1_WMISSMEN_B_0X1			(0x1u<<21)
#define	CACHEAXI_CR1_WHITMEN_B_0X0			(0x0u<<20)
#define	CACHEAXI_CR1_WHITMEN_B_0X1			(0x1u<<20)
#define	CACHEAXI_CR1_RMISSMRST_B_0X0		(0x0u<<19)
#define	CACHEAXI_CR1_RMISSMRST_B_0X1		(0x1u<<19)
#define	CACHEAXI_CR1_RHITMRST_B_0X0			(0x0u<<18)
#define	CACHEAXI_CR1_RHITMRST_B_0X1			(0x1u<<18)
#define	CACHEAXI_CR1_RMISSMEN_B_0X0			(0x0u<<17)
#define	CACHEAXI_CR1_RMISSMEN_B_0X1			(0x1u<<17)
#define	CACHEAXI_CR1_RHITMEN_B_0X0			(0x0u<<16)
#define	CACHEAXI_CR1_RHITMEN_B_0X1			(0x1u<<16)
#define	CACHEAXI_CR1_CACHEINV_B_0X0			(0x0u<<1)
#define	CACHEAXI_CR1_CACHEINV_B_0X1			(0x1u<<1)
#define	CACHEAXI_CR1_EN_B_0X0				(0x0u<<0)
#define	CACHEAXI_CR1_EN_B_0X1				(0x1u<<0)

// SR Configuration

#define	CACHEAXI_SR_CMDENDF					(0x1u<<4)
#define	CACHEAXI_SR_BUSYCMDF				(0x1u<<3)
#define	CACHEAXI_SR_ERRF					(0x1u<<2)
#define	CACHEAXI_SR_BSYENDF					(0x1u<<1)
#define	CACHEAXI_SR_BUSYF					(0x1u<<0)

#define	CACHEAXI_SR_CMDENDF_B_0X0			(0x0u<<4)
#define	CACHEAXI_SR_CMDENDF_B_0X1			(0x1u<<4)
#define	CACHEAXI_SR_BUSYCMDF_B_0X0			(0x0u<<3)
#define	CACHEAXI_SR_BUSYCMDF_B_0X1			(0x1u<<3)
#define	CACHEAXI_SR_ERRF_B_0X0				(0x0u<<2)
#define	CACHEAXI_SR_ERRF_B_0X1				(0x1u<<2)
#define	CACHEAXI_SR_BSYENDF_B_0X0			(0x0u<<1)
#define	CACHEAXI_SR_BSYENDF_B_0X1			(0x1u<<1)
#define	CACHEAXI_SR_BUSYF_B_0X0				(0x0u<<0)
#define	CACHEAXI_SR_BUSYF_B_0X1				(0x1u<<0)

// IER Configuration

#define	CACHEAXI_IER_CMDENDIE				(0x1u<<4)
#define	CACHEAXI_IER_ERRIE					(0x1u<<2)
#define	CACHEAXI_IER_BSYENDIE				(0x1u<<1)

#define	CACHEAXI_IER_CMDENDIE_B_0X0			(0x0u<<4)
#define	CACHEAXI_IER_CMDENDIE_B_0X1			(0x1u<<4)
#define	CACHEAXI_IER_ERRIE_B_0X0			(0x0u<<2)
#define	CACHEAXI_IER_ERRIE_B_0X1			(0x1u<<2)
#define	CACHEAXI_IER_BSYENDIE_B_0X0			(0x0u<<1)
#define	CACHEAXI_IER_BSYENDIE_B_0X1			(0x1u<<1)

// FCR Configuration

#define	CACHEAXI_FCR_CCMDENDF				(0x1u<<4)
#define	CACHEAXI_FCR_CERRF					(0x1u<<2)
#define	CACHEAXI_FCR_CBSYENDF				(0x1u<<1)

#define	CACHEAXI_FCR_CCMDENDF_B_0X0			(0x0u<<4)
#define	CACHEAXI_FCR_CCMDENDF_B_0X1			(0x1u<<4)
#define	CACHEAXI_FCR_CERRF_B_0X0			(0x0u<<2)
#define	CACHEAXI_FCR_CERRF_B_0X1			(0x1u<<2)
#define	CACHEAXI_FCR_CBSYENDF_B_0X0			(0x0u<<1)
#define	CACHEAXI_FCR_CBSYENDF_B_0X1			(0x1u<<1)

// RHMONR Configuration

#define	CACHEAXI_RHMONR_RHITMON				(0xFFFFFFFFu<<0)
#define	CACHEAXI_RHMONR_RHITMON_0			(0x1u<<0)

// RMMONR Configuration

#define	CACHEAXI_RMMONR_RMISSMON			(0xFFFFFFFFu<<0)
#define	CACHEAXI_RMMONR_RMISSMON_0			(0x1u<<0)

// RAMMONR Configuration

#define	CACHEAXI_RAMMONR_RAMMON				(0xFFFFFFFFu<<0)
#define	CACHEAXI_RAMMONR_RAMMON_0			(0x1u<<0)

// EVIMONR Configuration

#define	CACHEAXI_EVIMONR_EVIMON				(0xFFFFFFFFu<<0)
#define	CACHEAXI_EVIMONR_EVIMON_0			(0x1u<<0)

// WHMONR Configuration

#define	CACHEAXI_WHMONR_WHITMON				(0xFFFFFFFFu<<0)
#define	CACHEAXI_WHMONR_WHITMON_0			(0x1u<<0)

// WMMONR Configuration

#define	CACHEAXI_WMMONR_WMISSMON			(0xFFFFFFFFu<<0)
#define	CACHEAXI_WMMONR_WMISSMON_0			(0x1u<<0)

// WAMMONR Configuration

#define	CACHEAXI_WAMMONR_WAMMON				(0xFFFFFFFFu<<0)
#define	CACHEAXI_WAMMONR_WAMMON_0			(0x1u<<0)

// WTMONR Configuration

#define	CACHEAXI_WTMONR_WTMON				(0xFFFFFFFFu<<0)
#define	CACHEAXI_WTMONR_WTMON_0				(0x1u<<0)

// CR2 Configuration

#define	CACHEAXI_CR2_CACHECMD				(0x3u<<1)
#define	CACHEAXI_CR2_CACHECMD_0				(0x1u<<1)
#define	CACHEAXI_CR2_STARTCMD				(0x1u<<0)

#define	CACHEAXI_CR2_CACHECMD_B_0X0			(0x0u<<1)
#define	CACHEAXI_CR2_CACHECMD_B_0X1			(0x1u<<1)
#define	CACHEAXI_CR2_CACHECMD_B_0X3			(0x3u<<1)
#define	CACHEAXI_CR2_STARTCMD_B_0X0			(0x0u<<0)
#define	CACHEAXI_CR2_STARTCMD_B_0X1			(0x1u<<0)

// CMDRSADDRR Configuration

#define	CACHEAXI_CMDRSADDRR_CMDSTARTADDR	(0x3FFFFFFu<<6)
#define	CACHEAXI_CMDRSADDRR_CMDSTARTADDR_0	(0x1u<<6)

// CMDREADDRR Configuration

#define	CACHEAXI_CMDREADDRR_CMDENDADDR		(0x3FFFFFFu<<6)
#define	CACHEAXI_CMDREADDRR_CMDENDADDR_0	(0x1u<<6)
