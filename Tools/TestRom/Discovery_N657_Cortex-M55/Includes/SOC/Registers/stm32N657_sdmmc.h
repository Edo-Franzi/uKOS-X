/*
; stm32N657_sdmmc.
; ================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_sdmmc equates.
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

// SDMMC address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	POWER;
	volatile	uint32_t	CLKCR;
	volatile	uint32_t	ARGR;
	volatile	uint32_t	CMDR;
	volatile	uint32_t	RESPCMDR;
	volatile	uint32_t	RESP1R;
	volatile	uint32_t	RESP2R;
	volatile	uint32_t	RESP3R;
	volatile	uint32_t	RESP4R;
	volatile	uint32_t	DTIMER;
	volatile	uint32_t	DLENR;
	volatile	uint32_t	DCTRL;
	volatile	uint32_t	DCNTR;
	volatile	uint32_t	STAR;
	volatile	uint32_t	ICR;
	volatile	uint32_t	MASKR;
	volatile	uint32_t	ACKTIMER;
	volatile	uint32_t	FIFOTHRR;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	IDMACTRLR;
	volatile	uint32_t	IDMABSIZER;
	volatile	uint32_t	IDMABASER;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	IDMALAR;
	volatile	uint32_t	IDMABAR;
	volatile	uint32_t	RESERVED2[5];
	volatile	uint32_t	FIFOR0;
	volatile	uint32_t	FIFOR1;
	volatile	uint32_t	FIFOR2;
	volatile	uint32_t	FIFOR3;
	volatile	uint32_t	FIFOR4;
	volatile	uint32_t	FIFOR5;
	volatile	uint32_t	FIFOR6;
	volatile	uint32_t	FIFOR7;
	volatile	uint32_t	FIFOR8;
	volatile	uint32_t	FIFOR9;
	volatile	uint32_t	FIFOR10;
	volatile	uint32_t	FIFOR11;
	volatile	uint32_t	FIFOR12;
	volatile	uint32_t	FIFOR13;
	volatile	uint32_t	FIFOR14;
	volatile	uint32_t	FIFOR15;
} SDMMC_TypeDef;

#if (defined(__cplusplus))
#define	SDMMC1_NS	reinterpret_cast<SDMMC_TypeDef *>(0x48027000u)
#define	SDMMC1_S	reinterpret_cast<SDMMC_TypeDef *>(0x58027000u)
#define	SDMMC2_NS	reinterpret_cast<SDMMC_TypeDef *>(0x48026800u)
#define	SDMMC2_S	reinterpret_cast<SDMMC_TypeDef *>(0x58026800u)

#else
#define	SDMMC1_NS	((SDMMC_TypeDef *)0x48027000u)
#define	SDMMC1_S	((SDMMC_TypeDef *)0x58027000u)
#define	SDMMC2_NS	((SDMMC_TypeDef *)0x48026800u)
#define	SDMMC2_S	((SDMMC_TypeDef *)0x58026800u)
#endif

// POWER Configuration

#define	SDMMC_POWER_DIRPOL				(0x1u<<4)
#define	SDMMC_POWER_VSWITCHEN			(0x1u<<3)
#define	SDMMC_POWER_VSWITCH				(0x1u<<2)
#define	SDMMC_POWER_PWRCTRL				(0x3u<<0)
#define	SDMMC_POWER_PWRCTRL_0			(0x1u<<0)

#define	SDMMC_POWER_DIRPOL_B_0X0		(0x0u<<4)
#define	SDMMC_POWER_DIRPOL_B_0X1		(0x1u<<4)
#define	SDMMC_POWER_VSWITCHEN_B_0X0		(0x0u<<3)
#define	SDMMC_POWER_VSWITCHEN_B_0X1		(0x1u<<3)
#define	SDMMC_POWER_VSWITCH_B_0X0		(0x0u<<2)
#define	SDMMC_POWER_VSWITCH_B_0X1		(0x1u<<2)
#define	SDMMC_POWER_PWRCTRL_B_0X0		(0x0u<<0)
#define	SDMMC_POWER_PWRCTRL_B_0X2		(0x2u<<0)
#define	SDMMC_POWER_PWRCTRL_B_0X3		(0x3u<<0)

// CLKCR Configuration

#define	SDMMC_CLKCR_SELCLKRX			(0x3u<<20)
#define	SDMMC_CLKCR_SELCLKRX_0			(0x1u<<20)
#define	SDMMC_CLKCR_BUSSPEED			(0x1u<<19)
#define	SDMMC_CLKCR_DDR					(0x1u<<18)
#define	SDMMC_CLKCR_HWFC_EN				(0x1u<<17)
#define	SDMMC_CLKCR_NEGEDGE				(0x1u<<16)
#define	SDMMC_CLKCR_WIDBUS				(0x3u<<14)
#define	SDMMC_CLKCR_WIDBUS_0			(0x1u<<14)
#define	SDMMC_CLKCR_PWRSAV				(0x1u<<12)
#define	SDMMC_CLKCR_CLKDIV				(0x3FFu<<0)
#define	SDMMC_CLKCR_CLKDIV_0			(0x1u<<0)

#define	SDMMC_CLKCR_SELCLKRX_B_0X0		(0x0u<<20)
#define	SDMMC_CLKCR_SELCLKRX_B_0X1		(0x1u<<20)
#define	SDMMC_CLKCR_SELCLKRX_B_0X2		(0x2u<<20)
#define	SDMMC_CLKCR_BUSSPEED_B_0X0		(0x0u<<19)
#define	SDMMC_CLKCR_BUSSPEED_B_0X1		(0x1u<<19)
#define	SDMMC_CLKCR_DDR_B_0X0			(0x0u<<18)
#define	SDMMC_CLKCR_DDR_B_0X1			(0x1u<<18)
#define	SDMMC_CLKCR_HWFC_EN_B_0X0		(0x0u<<17)
#define	SDMMC_CLKCR_HWFC_EN_B_0X1		(0x1u<<17)
#define	SDMMC_CLKCR_NEGEDGE_B_0X0		(0x0u<<16)
#define	SDMMC_CLKCR_NEGEDGE_B_0X1		(0x1u<<16)
#define	SDMMC_CLKCR_WIDBUS_B_0X0		(0x0u<<14)
#define	SDMMC_CLKCR_WIDBUS_B_0X1		(0x1u<<14)
#define	SDMMC_CLKCR_WIDBUS_B_0X2		(0x2u<<14)
#define	SDMMC_CLKCR_PWRSAV_B_0X0		(0x0u<<12)
#define	SDMMC_CLKCR_PWRSAV_B_0X1		(0x1u<<12)
#define	SDMMC_CLKCR_CLKDIV_B_0X000		(0x0u<<0)
#define	SDMMC_CLKCR_CLKDIV_B_0X001		(0x1u<<0)
#define	SDMMC_CLKCR_CLKDIV_B_0X002		(0x2u<<0)
#define	SDMMC_CLKCR_CLKDIV_B_0X080		(0x80u<<0)
#define	SDMMC_CLKCR_CLKDIV_B_0X3FF		(0x3FFu<<0)

// ARGR Configuration

#define	SDMMC_ARGR_CMDARG				(0xFFFFFFFFu<<0)
#define	SDMMC_ARGR_CMDARG_0				(0x1u<<0)

// CMDR Configuration

#define	SDMMC_CMDR_CMDSUSPEND			(0x1u<<16)
#define	SDMMC_CMDR_BOOTEN				(0x1u<<15)
#define	SDMMC_CMDR_BOOTMODE				(0x1u<<14)
#define	SDMMC_CMDR_DTHOLD				(0x1u<<13)
#define	SDMMC_CMDR_CPSMEN				(0x1u<<12)
#define	SDMMC_CMDR_WAITPEND				(0x1u<<11)
#define	SDMMC_CMDR_WAITINT				(0x1u<<10)
#define	SDMMC_CMDR_WAITRESP				(0x3u<<8)
#define	SDMMC_CMDR_WAITRESP_0			(0x1u<<8)
#define	SDMMC_CMDR_CMDSTOP				(0x1u<<7)
#define	SDMMC_CMDR_CMDTRANS				(0x1u<<6)
#define	SDMMC_CMDR_CMDINDEX				(0x3Fu<<0)
#define	SDMMC_CMDR_CMDINDEX_0			(0x1u<<0)

#define	SDMMC_CMDR_BOOTEN_B_0X0			(0x0u<<15)
#define	SDMMC_CMDR_BOOTEN_B_0X1			(0x1u<<15)
#define	SDMMC_CMDR_BOOTMODE_B_0X0		(0x0u<<14)
#define	SDMMC_CMDR_BOOTMODE_B_0X1		(0x1u<<14)
#define	SDMMC_CMDR_WAITRESP_B_0X0		(0x0u<<8)
#define	SDMMC_CMDR_WAITRESP_B_0X1		(0x1u<<8)
#define	SDMMC_CMDR_WAITRESP_B_0X2		(0x2u<<8)
#define	SDMMC_CMDR_WAITRESP_B_0X3		(0x3u<<8)

// RESPCMDR Configuration

#define	SDMMC_RESPCMDR_RESPCMD			(0x3Fu<<0)
#define	SDMMC_RESPCMDR_RESPCMD_0		(0x1u<<0)

// RESP1R Configuration

#define	SDMMC_RESP1R_CARDSTATUS			(0xFFFFFFFFu<<0)
#define	SDMMC_RESP1R_CARDSTATUS_0		(0x1u<<0)

// RESP2R Configuration

#define	SDMMC_RESP2R_CARDSTATUS			(0xFFFFFFFFu<<0)
#define	SDMMC_RESP2R_CARDSTATUS_0		(0x1u<<0)

// RESP3R Configuration

#define	SDMMC_RESP3R_CARDSTATUS			(0xFFFFFFFFu<<0)
#define	SDMMC_RESP3R_CARDSTATUS_0		(0x1u<<0)

// RESP4R Configuration

#define	SDMMC_RESP4R_CARDSTATUS			(0xFFFFFFFFu<<0)
#define	SDMMC_RESP4R_CARDSTATUS_0		(0x1u<<0)

// DTIMER Configuration

#define	SDMMC_DTIMER_DATATIME			(0xFFFFFFFFu<<0)
#define	SDMMC_DTIMER_DATATIME_0			(0x1u<<0)

// DLENR Configuration

#define	SDMMC_DLENR_DATALENGTH			(0x1FFFFFFu<<0)
#define	SDMMC_DLENR_DATALENGTH_0		(0x1u<<0)

// DCTRL Configuration

#define	SDMMC_DCTRL_FIFORST				(0x1u<<13)
#define	SDMMC_DCTRL_BOOTACKEN			(0x1u<<12)
#define	SDMMC_DCTRL_SDIOEN				(0x1u<<11)
#define	SDMMC_DCTRL_RWMOD				(0x1u<<10)
#define	SDMMC_DCTRL_RWSTOP				(0x1u<<9)
#define	SDMMC_DCTRL_RWSTART				(0x1u<<8)
#define	SDMMC_DCTRL_DBLOCKSIZE			(0xFu<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_0		(0x1u<<4)
#define	SDMMC_DCTRL_DTMODE				(0x3u<<2)
#define	SDMMC_DCTRL_DTMODE_0			(0x1u<<2)
#define	SDMMC_DCTRL_DTDIR				(0x1u<<1)
#define	SDMMC_DCTRL_DTEN				(0x1u<<0)

#define	SDMMC_DCTRL_FIFORST_B_0X0		(0x0u<<13)
#define	SDMMC_DCTRL_FIFORST_B_0X1		(0x1u<<13)
#define	SDMMC_DCTRL_BOOTACKEN_B_0X0		(0x0u<<12)
#define	SDMMC_DCTRL_BOOTACKEN_B_0X1		(0x1u<<12)
#define	SDMMC_DCTRL_RWMOD_B_0X0			(0x0u<<10)
#define	SDMMC_DCTRL_RWMOD_B_0X1			(0x1u<<10)
#define	SDMMC_DCTRL_RWSTOP_B_0X0		(0x0u<<9)
#define	SDMMC_DCTRL_RWSTOP_B_0X1		(0x1u<<9)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0X0	(0x0u<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0X1	(0x1u<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0X2	(0x2u<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0X3	(0x3u<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0X4	(0x4u<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0X5	(0x5u<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0X6	(0x6u<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0X7	(0x7u<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0X8	(0x8u<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0X9	(0x9u<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0XA	(0xAu<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0XB	(0xBu<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0XC	(0xCu<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0XD	(0xDu<<4)
#define	SDMMC_DCTRL_DBLOCKSIZE_B_0XE	(0xEu<<4)
#define	SDMMC_DCTRL_DTMODE_B_0X0		(0x0u<<2)
#define	SDMMC_DCTRL_DTMODE_B_0X1		(0x1u<<2)
#define	SDMMC_DCTRL_DTMODE_B_0X2		(0x2u<<2)
#define	SDMMC_DCTRL_DTMODE_B_0X3		(0x3u<<2)
#define	SDMMC_DCTRL_DTDIR_B_0X0			(0x0u<<1)
#define	SDMMC_DCTRL_DTDIR_B_0X1			(0x1u<<1)
#define	SDMMC_DCTRL_DTEN_B_0X0			(0x0u<<0)
#define	SDMMC_DCTRL_DTEN_B_0X1			(0x1u<<0)

// DCNTR Configuration

#define	SDMMC_DCNTR_DATACOUNT			(0x1FFFFFFu<<0)
#define	SDMMC_DCNTR_DATACOUNT_0			(0x1u<<0)

// STAR Configuration

#define	SDMMC_STAR_IDMABTC				(0x1u<<28)
#define	SDMMC_STAR_IDMATE				(0x1u<<27)
#define	SDMMC_STAR_CKSTOP				(0x1u<<26)
#define	SDMMC_STAR_VSWEND				(0x1u<<25)
#define	SDMMC_STAR_ACKTIMEOUT			(0x1u<<24)
#define	SDMMC_STAR_ACKFAIL				(0x1u<<23)
#define	SDMMC_STAR_SDIOIT				(0x1u<<22)
#define	SDMMC_STAR_BUSYD0END			(0x1u<<21)
#define	SDMMC_STAR_BUSYD0				(0x1u<<20)
#define	SDMMC_STAR_RXFIFOE				(0x1u<<19)
#define	SDMMC_STAR_TXFIFOE				(0x1u<<18)
#define	SDMMC_STAR_RXFIFOF				(0x1u<<17)
#define	SDMMC_STAR_TXFIFOF				(0x1u<<16)
#define	SDMMC_STAR_RXFIFOHF				(0x1u<<15)
#define	SDMMC_STAR_TXFIFOHE				(0x1u<<14)
#define	SDMMC_STAR_CPSMACT				(0x1u<<13)
#define	SDMMC_STAR_DPSMACT				(0x1u<<12)
#define	SDMMC_STAR_DABORT				(0x1u<<11)
#define	SDMMC_STAR_DBCKEND				(0x1u<<10)
#define	SDMMC_STAR_DHOLD				(0x1u<<9)
#define	SDMMC_STAR_DATAEND				(0x1u<<8)
#define	SDMMC_STAR_CMDSENT				(0x1u<<7)
#define	SDMMC_STAR_CMDREND				(0x1u<<6)
#define	SDMMC_STAR_RXOVERR				(0x1u<<5)
#define	SDMMC_STAR_TXUNDERR				(0x1u<<4)
#define	SDMMC_STAR_DTIMEOUT				(0x1u<<3)
#define	SDMMC_STAR_CTIMEOUT				(0x1u<<2)
#define	SDMMC_STAR_DCRCFAIL				(0x1u<<1)
#define	SDMMC_STAR_CCRCFAIL				(0x1u<<0)

#define	SDMMC_STAR_BUSYD0END_B_0X0		(0x0u<<21)
#define	SDMMC_STAR_BUSYD0END_B_0X1		(0x1u<<21)
#define	SDMMC_STAR_BUSYD0_B_0X0			(0x0u<<20)
#define	SDMMC_STAR_BUSYD0_B_0X1			(0x1u<<20)

// ICR Configuration

#define	SDMMC_ICR_IDMABTCC				(0x1u<<28)
#define	SDMMC_ICR_IDMATEC				(0x1u<<27)
#define	SDMMC_ICR_CKSTOPC				(0x1u<<26)
#define	SDMMC_ICR_VSWENDC				(0x1u<<25)
#define	SDMMC_ICR_ACKTIMEOUTC			(0x1u<<24)
#define	SDMMC_ICR_ACKFAILC				(0x1u<<23)
#define	SDMMC_ICR_SDIOITC				(0x1u<<22)
#define	SDMMC_ICR_BUSYD0ENDC			(0x1u<<21)
#define	SDMMC_ICR_DABORTC				(0x1u<<11)
#define	SDMMC_ICR_DBCKENDC				(0x1u<<10)
#define	SDMMC_ICR_DHOLDC				(0x1u<<9)
#define	SDMMC_ICR_DATAENDC				(0x1u<<8)
#define	SDMMC_ICR_CMDSENTC				(0x1u<<7)
#define	SDMMC_ICR_CMDRENDC				(0x1u<<6)
#define	SDMMC_ICR_RXOVERRC				(0x1u<<5)
#define	SDMMC_ICR_TXUNDERRC				(0x1u<<4)
#define	SDMMC_ICR_DTIMEOUTC				(0x1u<<3)
#define	SDMMC_ICR_CTIMEOUTC				(0x1u<<2)
#define	SDMMC_ICR_DCRCFAILC				(0x1u<<1)
#define	SDMMC_ICR_CCRCFAILC				(0x1u<<0)

#define	SDMMC_ICR_IDMABTCC_B_0X0		(0x0u<<28)
#define	SDMMC_ICR_IDMABTCC_B_0X1		(0x1u<<28)
#define	SDMMC_ICR_IDMATEC_B_0X0			(0x0u<<27)
#define	SDMMC_ICR_IDMATEC_B_0X1			(0x1u<<27)
#define	SDMMC_ICR_CKSTOPC_B_0X0			(0x0u<<26)
#define	SDMMC_ICR_CKSTOPC_B_0X1			(0x1u<<26)
#define	SDMMC_ICR_VSWENDC_B_0X0			(0x0u<<25)
#define	SDMMC_ICR_VSWENDC_B_0X1			(0x1u<<25)
#define	SDMMC_ICR_ACKTIMEOUTC_B_0X0		(0x0u<<24)
#define	SDMMC_ICR_ACKTIMEOUTC_B_0X1		(0x1u<<24)
#define	SDMMC_ICR_ACKFAILC_B_0X0		(0x0u<<23)
#define	SDMMC_ICR_ACKFAILC_B_0X1		(0x1u<<23)
#define	SDMMC_ICR_SDIOITC_B_0X0			(0x0u<<22)
#define	SDMMC_ICR_SDIOITC_B_0X1			(0x1u<<22)
#define	SDMMC_ICR_BUSYD0ENDC_B_0X0		(0x0u<<21)
#define	SDMMC_ICR_BUSYD0ENDC_B_0X1		(0x1u<<21)
#define	SDMMC_ICR_DABORTC_B_0X0			(0x0u<<11)
#define	SDMMC_ICR_DABORTC_B_0X1			(0x1u<<11)
#define	SDMMC_ICR_DBCKENDC_B_0X0		(0x0u<<10)
#define	SDMMC_ICR_DBCKENDC_B_0X1		(0x1u<<10)
#define	SDMMC_ICR_DHOLDC_B_0X0			(0x0u<<9)
#define	SDMMC_ICR_DHOLDC_B_0X1			(0x1u<<9)
#define	SDMMC_ICR_DATAENDC_B_0X0		(0x0u<<8)
#define	SDMMC_ICR_DATAENDC_B_0X1		(0x1u<<8)
#define	SDMMC_ICR_CMDSENTC_B_0X0		(0x0u<<7)
#define	SDMMC_ICR_CMDSENTC_B_0X1		(0x1u<<7)
#define	SDMMC_ICR_CMDRENDC_B_0X0		(0x0u<<6)
#define	SDMMC_ICR_CMDRENDC_B_0X1		(0x1u<<6)
#define	SDMMC_ICR_RXOVERRC_B_0X0		(0x0u<<5)
#define	SDMMC_ICR_RXOVERRC_B_0X1		(0x1u<<5)
#define	SDMMC_ICR_TXUNDERRC_B_0X0		(0x0u<<4)
#define	SDMMC_ICR_TXUNDERRC_B_0X1		(0x1u<<4)
#define	SDMMC_ICR_DTIMEOUTC_B_0X0		(0x0u<<3)
#define	SDMMC_ICR_DTIMEOUTC_B_0X1		(0x1u<<3)
#define	SDMMC_ICR_CTIMEOUTC_B_0X0		(0x0u<<2)
#define	SDMMC_ICR_CTIMEOUTC_B_0X1		(0x1u<<2)
#define	SDMMC_ICR_DCRCFAILC_B_0X0		(0x0u<<1)
#define	SDMMC_ICR_DCRCFAILC_B_0X1		(0x1u<<1)
#define	SDMMC_ICR_CCRCFAILC_B_0X0		(0x0u<<0)
#define	SDMMC_ICR_CCRCFAILC_B_0X1		(0x1u<<0)

// MASKR Configuration

#define	SDMMC_MASKR_IDMABTCIE			(0x1u<<28)
#define	SDMMC_MASKR_CKSTOPIE			(0x1u<<26)
#define	SDMMC_MASKR_VSWENDIE			(0x1u<<25)
#define	SDMMC_MASKR_ACKTIMEOUTIE		(0x1u<<24)
#define	SDMMC_MASKR_ACKFAILIE			(0x1u<<23)
#define	SDMMC_MASKR_SDIOITIE			(0x1u<<22)
#define	SDMMC_MASKR_BUSYD0ENDIE			(0x1u<<21)
#define	SDMMC_MASKR_TXFIFOEIE			(0x1u<<18)
#define	SDMMC_MASKR_RXFIFOFIE			(0x1u<<17)
#define	SDMMC_MASKR_RXFIFOHFIE			(0x1u<<15)
#define	SDMMC_MASKR_TXFIFOHEIE			(0x1u<<14)
#define	SDMMC_MASKR_DABORTIE			(0x1u<<11)
#define	SDMMC_MASKR_DBCKENDIE			(0x1u<<10)
#define	SDMMC_MASKR_DHOLDIE				(0x1u<<9)
#define	SDMMC_MASKR_DATAENDIE			(0x1u<<8)
#define	SDMMC_MASKR_CMDSENTIE			(0x1u<<7)
#define	SDMMC_MASKR_CMDRENDIE			(0x1u<<6)
#define	SDMMC_MASKR_RXOVERRIE			(0x1u<<5)
#define	SDMMC_MASKR_TXUNDERRIE			(0x1u<<4)
#define	SDMMC_MASKR_DTIMEOUTIE			(0x1u<<3)
#define	SDMMC_MASKR_CTIMEOUTIE			(0x1u<<2)
#define	SDMMC_MASKR_DCRCFAILIE			(0x1u<<1)
#define	SDMMC_MASKR_CCRCFAILIE			(0x1u<<0)

#define	SDMMC_MASKR_IDMABTCIE_B_0X0		(0x0u<<28)
#define	SDMMC_MASKR_IDMABTCIE_B_0X1		(0x1u<<28)
#define	SDMMC_MASKR_CKSTOPIE_B_0X0		(0x0u<<26)
#define	SDMMC_MASKR_CKSTOPIE_B_0X1		(0x1u<<26)
#define	SDMMC_MASKR_VSWENDIE_B_0X0		(0x0u<<25)
#define	SDMMC_MASKR_VSWENDIE_B_0X1		(0x1u<<25)
#define	SDMMC_MASKR_ACKTIMEOUTIE_B_0X0	(0x0u<<24)
#define	SDMMC_MASKR_ACKTIMEOUTIE_B_0X1	(0x1u<<24)
#define	SDMMC_MASKR_ACKFAILIE_B_0X0		(0x0u<<23)
#define	SDMMC_MASKR_ACKFAILIE_B_0X1		(0x1u<<23)
#define	SDMMC_MASKR_SDIOITIE_B_0X0		(0x0u<<22)
#define	SDMMC_MASKR_SDIOITIE_B_0X1		(0x1u<<22)
#define	SDMMC_MASKR_BUSYD0ENDIE_B_0X0	(0x0u<<21)
#define	SDMMC_MASKR_BUSYD0ENDIE_B_0X1	(0x1u<<21)
#define	SDMMC_MASKR_TXFIFOEIE_B_0X0		(0x0u<<18)
#define	SDMMC_MASKR_TXFIFOEIE_B_0X1		(0x1u<<18)
#define	SDMMC_MASKR_RXFIFOFIE_B_0X0		(0x0u<<17)
#define	SDMMC_MASKR_RXFIFOFIE_B_0X1		(0x1u<<17)
#define	SDMMC_MASKR_RXFIFOHFIE_B_0X0	(0x0u<<15)
#define	SDMMC_MASKR_RXFIFOHFIE_B_0X1	(0x1u<<15)
#define	SDMMC_MASKR_TXFIFOHEIE_B_0X0	(0x0u<<14)
#define	SDMMC_MASKR_TXFIFOHEIE_B_0X1	(0x1u<<14)
#define	SDMMC_MASKR_DABORTIE_B_0X0		(0x0u<<11)
#define	SDMMC_MASKR_DABORTIE_B_0X1		(0x1u<<11)
#define	SDMMC_MASKR_DBCKENDIE_B_0X0		(0x0u<<10)
#define	SDMMC_MASKR_DBCKENDIE_B_0X1		(0x1u<<10)
#define	SDMMC_MASKR_DHOLDIE_B_0X0		(0x0u<<9)
#define	SDMMC_MASKR_DHOLDIE_B_0X1		(0x1u<<9)
#define	SDMMC_MASKR_DATAENDIE_B_0X0		(0x0u<<8)
#define	SDMMC_MASKR_DATAENDIE_B_0X1		(0x1u<<8)
#define	SDMMC_MASKR_CMDSENTIE_B_0X0		(0x0u<<7)
#define	SDMMC_MASKR_CMDSENTIE_B_0X1		(0x1u<<7)
#define	SDMMC_MASKR_CMDRENDIE_B_0X0		(0x0u<<6)
#define	SDMMC_MASKR_CMDRENDIE_B_0X1		(0x1u<<6)
#define	SDMMC_MASKR_RXOVERRIE_B_0X0		(0x0u<<5)
#define	SDMMC_MASKR_RXOVERRIE_B_0X1		(0x1u<<5)
#define	SDMMC_MASKR_TXUNDERRIE_B_0X0	(0x0u<<4)
#define	SDMMC_MASKR_TXUNDERRIE_B_0X1	(0x1u<<4)
#define	SDMMC_MASKR_DTIMEOUTIE_B_0X0	(0x0u<<3)
#define	SDMMC_MASKR_DTIMEOUTIE_B_0X1	(0x1u<<3)
#define	SDMMC_MASKR_CTIMEOUTIE_B_0X0	(0x0u<<2)
#define	SDMMC_MASKR_CTIMEOUTIE_B_0X1	(0x1u<<2)
#define	SDMMC_MASKR_DCRCFAILIE_B_0X0	(0x0u<<1)
#define	SDMMC_MASKR_DCRCFAILIE_B_0X1	(0x1u<<1)
#define	SDMMC_MASKR_CCRCFAILIE_B_0X0	(0x0u<<0)
#define	SDMMC_MASKR_CCRCFAILIE_B_0X1	(0x1u<<0)

// ACKTIMER Configuration

#define	SDMMC_ACKTIMER_ACKTIME			(0x1FFFFFFu<<0)
#define	SDMMC_ACKTIMER_ACKTIME_0		(0x1u<<0)

// FIFOTHRR Configuration

#define	SDMMC_FIFOTHRR_THR				(0xFu<<0)
#define	SDMMC_FIFOTHRR_THR_0			(0x1u<<0)

#define	SDMMC_FIFOTHRR_THR_B_0X0		(0x0u<<0)

// IDMACTRLR Configuration

#define	SDMMC_IDMACTRLR_IDMABMODE		(0x1u<<1)
#define	SDMMC_IDMACTRLR_IDMAEN			(0x1u<<0)

#define	SDMMC_IDMACTRLR_IDMABMODE_B_0X0	(0x0u<<1)
#define	SDMMC_IDMACTRLR_IDMABMODE_B_0X1	(0x1u<<1)
#define	SDMMC_IDMACTRLR_IDMAEN_B_0X0	(0x0u<<0)
#define	SDMMC_IDMACTRLR_IDMAEN_B_0X1	(0x1u<<0)

// IDMABSIZER Configuration

#define	SDMMC_IDMABSIZER_IDMABNDT		(0x7FFu<<6)
#define	SDMMC_IDMABSIZER_IDMABNDT_0		(0x1u<<6)

// IDMABASER Configuration

#define	SDMMC_IDMABASER_IDMABASE		(0xFFFFFFFFu<<0)
#define	SDMMC_IDMABASER_IDMABASE_0		(0x1u<<0)

// IDMALAR Configuration

#define	SDMMC_IDMALAR_ULA				(0x1u<<31)
#define	SDMMC_IDMALAR_ULS				(0x1u<<30)
#define	SDMMC_IDMALAR_ABR				(0x1u<<29)
#define	SDMMC_IDMALAR_IDMALA			(0x3FFFu<<2)
#define	SDMMC_IDMALAR_IDMALA_0			(0x1u<<2)

#define	SDMMC_IDMALAR_ULA_B_0X0			(0x0u<<31)
#define	SDMMC_IDMALAR_ULA_B_0X1			(0x1u<<31)
#define	SDMMC_IDMALAR_ULS_B_0X0			(0x0u<<30)
#define	SDMMC_IDMALAR_ULS_B_0X1			(0x1u<<30)
#define	SDMMC_IDMALAR_ABR_B_0X0			(0x0u<<29)
#define	SDMMC_IDMALAR_ABR_B_0X1			(0x1u<<29)

// IDMABAR Configuration

#define	SDMMC_IDMABAR_IDMABA			(0x3FFFFFFFu<<2)
#define	SDMMC_IDMABAR_IDMABA_0			(0x1u<<2)

// FIFOR0 Configuration

#define	SDMMC_FIFOR0_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR0_FIFODATA_0			(0x1u<<0)

// FIFOR1 Configuration

#define	SDMMC_FIFOR1_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR1_FIFODATA_0			(0x1u<<0)

// FIFOR2 Configuration

#define	SDMMC_FIFOR2_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR2_FIFODATA_0			(0x1u<<0)

// FIFOR3 Configuration

#define	SDMMC_FIFOR3_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR3_FIFODATA_0			(0x1u<<0)

// FIFOR4 Configuration

#define	SDMMC_FIFOR4_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR4_FIFODATA_0			(0x1u<<0)

// FIFOR5 Configuration

#define	SDMMC_FIFOR5_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR5_FIFODATA_0			(0x1u<<0)

// FIFOR6 Configuration

#define	SDMMC_FIFOR6_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR6_FIFODATA_0			(0x1u<<0)

// FIFOR7 Configuration

#define	SDMMC_FIFOR7_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR7_FIFODATA_0			(0x1u<<0)

// FIFOR8 Configuration

#define	SDMMC_FIFOR8_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR8_FIFODATA_0			(0x1u<<0)

// FIFOR9 Configuration

#define	SDMMC_FIFOR9_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR9_FIFODATA_0			(0x1u<<0)

// FIFOR10 Configuration

#define	SDMMC_FIFOR10_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR10_FIFODATA_0		(0x1u<<0)

// FIFOR11 Configuration

#define	SDMMC_FIFOR11_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR11_FIFODATA_0		(0x1u<<0)

// FIFOR12 Configuration

#define	SDMMC_FIFOR12_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR12_FIFODATA_0		(0x1u<<0)

// FIFOR13 Configuration

#define	SDMMC_FIFOR13_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR13_FIFODATA_0		(0x1u<<0)

// FIFOR14 Configuration

#define	SDMMC_FIFOR14_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR14_FIFODATA_0		(0x1u<<0)

// FIFOR15 Configuration

#define	SDMMC_FIFOR15_FIFODATA			(0xFFFFFFFFu<<0)
#define	SDMMC_FIFOR15_FIFODATA_0		(0x1u<<0)
