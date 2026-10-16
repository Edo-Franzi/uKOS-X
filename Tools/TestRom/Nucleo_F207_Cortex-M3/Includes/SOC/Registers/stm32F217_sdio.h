/*
; stm32F217_sdio.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_sdio equates.
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

// SDIO address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	POWER;
	volatile	uint32_t	CLKCR;
	volatile	uint32_t	ARG;
	volatile	uint32_t	CMD;
	volatile	uint32_t	RESPCMD;
	volatile	uint32_t	RESP1;
	volatile	uint32_t	RESP2;
	volatile	uint32_t	RESP3;
	volatile	uint32_t	RESP4;
	volatile	uint32_t	DTIMER;
	volatile	uint32_t	DLEN;
	volatile	uint32_t	DCTRL;
	volatile	uint32_t	DCOUNT;
	volatile	uint32_t	STA;
	volatile	uint32_t	ICR;
	volatile	uint32_t	MASK;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	FIFOCNT;
	volatile	uint32_t	RESERVED1[13];
	volatile	uint32_t	FIFO;
} SDIO_TypeDef;

#if (defined(__cplusplus))
#define	SDIO	reinterpret_cast<SDIO_TypeDef *>(0x40012C00u)

#else
#define	SDIO	((SDIO_TypeDef *)0x40012C00u)
#endif

// POWER Configuration

#define	SDIO_POWER_PWRCTRL			(0x3u<<0)
#define	SDIO_POWER_PWRCTRL_0		(0x1u<<0)

// CLKCR Configuration

#define	SDIO_CLKCR_CLKDIV			(0xFFu<<0)
#define	SDIO_CLKCR_CLKDIV_0			(0x1u<<0)
#define	SDIO_CLKCR_CLKEN			(0x1u<<8)
#define	SDIO_CLKCR_PWRSAV			(0x1u<<9)
#define	SDIO_CLKCR_BYPASS			(0x1u<<10)
#define	SDIO_CLKCR_WIDBUS			(0x3u<<11)
#define	SDIO_CLKCR_WIDBUS_0			(0x1u<<11)
#define	SDIO_CLKCR_NEGEDGE			(0x1u<<13)
#define	SDIO_CLKCR_HWFC_EN			(0x1u<<14)

// ARG Configuration

#define	SDIO_ARG_CMDARG				(0xFFFFFFFFu<<0)
#define	SDIO_ARG_CMDARG_0			(0x1u<<0)

// CMD Configuration

#define	SDIO_CMD_CMDINDEX			(0x3Fu<<0)
#define	SDIO_CMD_CMDINDEX_0			(0x1u<<0)
#define	SDIO_CMD_WAITRESP			(0x3u<<6)
#define	SDIO_CMD_WAITRESP_0			(0x1u<<6)
#define	SDIO_CMD_WAITINT			(0x1u<<8)
#define	SDIO_CMD_WAITPEND			(0x1u<<9)
#define	SDIO_CMD_CPSMEN				(0x1u<<10)
#define	SDIO_CMD_SDIOSUSPEND		(0x1u<<11)
#define	SDIO_CMD_ENCMDCOMPL			(0x1u<<12)
#define	SDIO_CMD_NIEN				(0x1u<<13)
#define	SDIO_CMD_CE_ATACMD			(0x1u<<14)

// RESPCMD Configuration

#define	SDIO_RESPCMD_RESPCMD		(0x3Fu<<0)
#define	SDIO_RESPCMD_RESPCMD_0		(0x1u<<0)

// RESP1 Configuration

#define	SDIO_RESP1_CARDSTATUS1		(0xFFFFFFFFu<<0)
#define	SDIO_RESP1_CARDSTATUS1_0	(0x1u<<0)

// RESP2 Configuration

#define	SDIO_RESP2_CARDSTATUS2		(0xFFFFFFFFu<<0)
#define	SDIO_RESP2_CARDSTATUS2_0	(0x1u<<0)

// RESP3 Configuration

#define	SDIO_RESP3_CARDSTATUS3		(0xFFFFFFFFu<<0)
#define	SDIO_RESP3_CARDSTATUS3_0	(0x1u<<0)

// RESP4 Configuration

#define	SDIO_RESP4_CARDSTATUS4		(0xFFFFFFFFu<<0)
#define	SDIO_RESP4_CARDSTATUS4_0	(0x1u<<0)

// DTIMER Configuration

#define	SDIO_DTIMER_DATATIME		(0xFFFFFFFFu<<0)
#define	SDIO_DTIMER_DATATIME_0		(0x1u<<0)

// DLEN Configuration

#define	SDIO_DLEN_DATALENGTH		(0x1FFFFFFu<<0)
#define	SDIO_DLEN_DATALENGTH_0		(0x1u<<0)

// DCTRL Configuration

#define	SDIO_DCTRL_DTEN				(0x1u<<0)
#define	SDIO_DCTRL_DTDIR			(0x1u<<1)
#define	SDIO_DCTRL_DTMODE			(0x1u<<2)
#define	SDIO_DCTRL_DMAEN			(0x1u<<3)
#define	SDIO_DCTRL_DBLOCKSIZE		(0xFu<<4)
#define	SDIO_DCTRL_DBLOCKSIZE_0		(0x1u<<4)
#define	SDIO_DCTRL_RWSTART			(0x1u<<8)
#define	SDIO_DCTRL_RWSTOP			(0x1u<<9)
#define	SDIO_DCTRL_RWMOD			(0x1u<<10)
#define	SDIO_DCTRL_SDIOEN			(0x1u<<11)

// DCOUNT Configuration

#define	SDIO_DCOUNT_DATACOUNT		(0x1FFFFFFu<<0)
#define	SDIO_DCOUNT_DATACOUNT_0		(0x1u<<0)

// STA Configuration

#define	SDIO_STA_CCRCFAIL			(0x1u<<0)
#define	SDIO_STA_DCRCFAIL			(0x1u<<1)
#define	SDIO_STA_CTIMEOUT			(0x1u<<2)
#define	SDIO_STA_DTIMEOUT			(0x1u<<3)
#define	SDIO_STA_TXUNDERR			(0x1u<<4)
#define	SDIO_STA_RXOVERR			(0x1u<<5)
#define	SDIO_STA_CMDREND			(0x1u<<6)
#define	SDIO_STA_CMDSENT			(0x1u<<7)
#define	SDIO_STA_DATAEND			(0x1u<<8)
#define	SDIO_STA_STBITERR			(0x1u<<9)
#define	SDIO_STA_DBCKEND			(0x1u<<10)
#define	SDIO_STA_CMDACT				(0x1u<<11)
#define	SDIO_STA_TXACT				(0x1u<<12)
#define	SDIO_STA_RXACT				(0x1u<<13)
#define	SDIO_STA_TXFIFOHE			(0x1u<<14)
#define	SDIO_STA_RXFIFOHF			(0x1u<<15)
#define	SDIO_STA_TXFIFOF			(0x1u<<16)
#define	SDIO_STA_RXFIFOF			(0x1u<<17)
#define	SDIO_STA_TXFIFOE			(0x1u<<18)
#define	SDIO_STA_RXFIFOE			(0x1u<<19)
#define	SDIO_STA_TXDAVL				(0x1u<<20)
#define	SDIO_STA_RXDAVL				(0x1u<<21)
#define	SDIO_STA_SDIOIT				(0x1u<<22)
#define	SDIO_STA_CEATAEND			(0x1u<<23)

// ICR Configuration

#define	SDIO_ICR_CCRCFAILC			(0x1u<<0)
#define	SDIO_ICR_DCRCFAILC			(0x1u<<1)
#define	SDIO_ICR_CTIMEOUTC			(0x1u<<2)
#define	SDIO_ICR_DTIMEOUTC			(0x1u<<3)
#define	SDIO_ICR_TXUNDERRC			(0x1u<<4)
#define	SDIO_ICR_RXOVERRC			(0x1u<<5)
#define	SDIO_ICR_CMDRENDC			(0x1u<<6)
#define	SDIO_ICR_CMDSENTC			(0x1u<<7)
#define	SDIO_ICR_DATAENDC			(0x1u<<8)
#define	SDIO_ICR_STBITERRC			(0x1u<<9)
#define	SDIO_ICR_DBCKENDC			(0x1u<<10)
#define	SDIO_ICR_SDIOITC			(0x1u<<22)
#define	SDIO_ICR_CEATAENDC			(0x1u<<23)

// MASK Configuration

#define	SDIO_MASK_CCRCFAILIE		(0x1u<<0)
#define	SDIO_MASK_DCRCFAILIE		(0x1u<<1)
#define	SDIO_MASK_CTIMEOUTIE		(0x1u<<2)
#define	SDIO_MASK_DTIMEOUTIE		(0x1u<<3)
#define	SDIO_MASK_TXUNDERRIE		(0x1u<<4)
#define	SDIO_MASK_RXOVERRIE			(0x1u<<5)
#define	SDIO_MASK_CMDRENDIE			(0x1u<<6)
#define	SDIO_MASK_CMDSENTIE			(0x1u<<7)
#define	SDIO_MASK_DATAENDIE			(0x1u<<8)
#define	SDIO_MASK_STBITERRIE		(0x1u<<9)
#define	SDIO_MASK_DBCKENDIE			(0x1u<<10)
#define	SDIO_MASK_CMDACTIE			(0x1u<<11)
#define	SDIO_MASK_TXACTIE			(0x1u<<12)
#define	SDIO_MASK_RXACTIE			(0x1u<<13)
#define	SDIO_MASK_TXFIFOHEIE		(0x1u<<14)
#define	SDIO_MASK_RXFIFOHFIE		(0x1u<<15)
#define	SDIO_MASK_TXFIFOFIE			(0x1u<<16)
#define	SDIO_MASK_RXFIFOFIE			(0x1u<<17)
#define	SDIO_MASK_TXFIFOEIE			(0x1u<<18)
#define	SDIO_MASK_RXFIFOEIE			(0x1u<<19)
#define	SDIO_MASK_TXDAVLIE			(0x1u<<20)
#define	SDIO_MASK_RXDAVLIE			(0x1u<<21)
#define	SDIO_MASK_SDIOITIE			(0x1u<<22)
#define	SDIO_MASK_CEATAENDIE		(0x1u<<23)

// FIFOCNT Configuration

#define	SDIO_FIFOCNT_FIFOCOUNT		(0xFFFFFFu<<0)
#define	SDIO_FIFOCNT_FIFOCOUNT_0	(0x1u<<0)

// FIFO Configuration

#define	SDIO_FIFO_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDIO_FIFO_FIFODATA_0		(0x1u<<0)
