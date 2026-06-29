/*
; stm32N657_dcmipp.
; =================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_dcmipp equates.
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

// DCMIPP address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	IPGR1;
	volatile	uint32_t	IPGR2;
	volatile	uint32_t	IPGR3;
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	IPGR8;
	volatile	uint32_t	IPC1R1;
	volatile	uint32_t	IPC1R2;
	volatile	uint32_t	IPC1R3;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	IPC2R1;
	volatile	uint32_t	IPC2R2;
	volatile	uint32_t	IPC2R3;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	IPC3R1;
	volatile	uint32_t	IPC3R2;
	volatile	uint32_t	IPC3R3;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	IPC4R1;
	volatile	uint32_t	IPC4R2;
	volatile	uint32_t	IPC4R3;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	IPC5R1;
	volatile	uint32_t	IPC5R2;
	volatile	uint32_t	IPC5R3;
	volatile	uint32_t	RESERVED5[38];
	volatile	uint32_t	PRCR;
	volatile	uint32_t	PRESCR;
	volatile	uint32_t	PRESUR;
	volatile	uint32_t	RESERVED6[57];
	volatile	uint32_t	PRIER;
	volatile	uint32_t	PRSR;
	volatile	uint32_t	PRFCR;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	CMCR;
	volatile	uint32_t	CMFRCR;
	volatile	uint32_t	RESERVED8[121];
	volatile	uint32_t	CMIER;
	volatile	uint32_t	CMSR1;
	volatile	uint32_t	CMSR2;
	volatile	uint32_t	CMFCR;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	P0FSCR;
	volatile	uint32_t	RESERVED10[62];
	volatile	uint32_t	P0FCTCR;
	volatile	uint32_t	P0SCSTR;
	volatile	uint32_t	P0SCSZR;
	volatile	uint32_t	RESERVED11[41];
	volatile	uint32_t	P0DCCNTR;
	volatile	uint32_t	P0DCLMTR;
	volatile	uint32_t	RESERVED12[2];
	volatile	uint32_t	P0PPCR;
	volatile	uint32_t	P0PPM0AR1;
	volatile	uint32_t	P0PPM0AR2;
	volatile	uint32_t	RESERVED13;
	volatile	uint32_t	P0STM0AR;
	volatile	uint32_t	RESERVED14[8];
	volatile	uint32_t	P0IER;
	volatile	uint32_t	P0SR;
	volatile	uint32_t	P0FCR;
	volatile	uint32_t	RESERVED15;
	volatile	uint32_t	P0CFSCR;
	volatile	uint32_t	RESERVED16[62];
	volatile	uint32_t	P0CFCTCR;
	volatile	uint32_t	P0CSCSTR;
	volatile	uint32_t	P0CSCSZR;
	volatile	uint32_t	RESERVED17[45];
	volatile	uint32_t	P0CPPCR;
	volatile	uint32_t	P0CPPM0AR1;
	volatile	uint32_t	P0CPPM0AR2;
	volatile	uint32_t	RESERVED18[14];
	volatile	uint32_t	P1FSCR;
	volatile	uint32_t	RESERVED19[6];
	volatile	uint32_t	P1SRCR;
	volatile	uint32_t	P1BPRCR;
	volatile	uint32_t	P1BPRSR;
	volatile	uint32_t	RESERVED20;
	volatile	uint32_t	P1DECR;
	volatile	uint32_t	RESERVED21[3];
	volatile	uint32_t	P1BLCCR;
	volatile	uint32_t	P1EXCR1;
	volatile	uint32_t	P1EXCR2;
	volatile	uint32_t	RESERVED22;
	volatile	uint32_t	P1ST1CR;
	volatile	uint32_t	P1ST2CR;
	volatile	uint32_t	P1ST3CR;
	volatile	uint32_t	P1STSTR;
	volatile	uint32_t	P1STSZR;
	volatile	uint32_t	P1ST1SR;
	volatile	uint32_t	P1ST2SR;
	volatile	uint32_t	P1ST3SR;
	volatile	uint32_t	P1DMCR;
	volatile	uint32_t	RESERVED23[3];
	volatile	uint32_t	P1CCCR;
	volatile	uint32_t	P1CCRR1;
	volatile	uint32_t	P1CCRR2;
	volatile	uint32_t	P1CCGR1;
	volatile	uint32_t	P1CCGR2;
	volatile	uint32_t	P1CCBR1;
	volatile	uint32_t	P1CCBR2;
	volatile	uint32_t	RESERVED24;
	volatile	uint32_t	P1CTCR1;
	volatile	uint32_t	P1CTCR2;
	volatile	uint32_t	P1CTCR3;
	volatile	uint32_t	RESERVED25[21];
	volatile	uint32_t	P1FCTCR;
	volatile	uint32_t	P1CRSTR;
	volatile	uint32_t	P1CRSZR;
	volatile	uint32_t	P1DCCR;
	volatile	uint32_t	P1DSCR;
	volatile	uint32_t	P1DSRTIOR;
	volatile	uint32_t	P1DSSZR;
	volatile	uint32_t	RESERVED26;
	volatile	uint32_t	P1CMRICR;
	volatile	uint32_t	P1RI1CR1;
	volatile	uint32_t	P1RI1CR2;
	volatile	uint32_t	P1RI2CR1;
	volatile	uint32_t	P1RI2CR2;
	volatile	uint32_t	P1RI3CR1;
	volatile	uint32_t	P1RI3CR2;
	volatile	uint32_t	P1RI4CR1;
	volatile	uint32_t	P1RI4CR2;
	volatile	uint32_t	P1RI5CR1;
	volatile	uint32_t	P1RI5CR2;
	volatile	uint32_t	P1RI6CR1;
	volatile	uint32_t	P1RI6CR2;
	volatile	uint32_t	P1RI7CR1;
	volatile	uint32_t	P1RI7CR2;
	volatile	uint32_t	P1RI8CR1;
	volatile	uint32_t	P1RI8CR2;
	volatile	uint32_t	RESERVED27[3];
	volatile	uint32_t	P1GMCR;
	volatile	uint32_t	RESERVED28[3];
	volatile	uint32_t	P1YUVCR;
	volatile	uint32_t	P1YUVRR1;
	volatile	uint32_t	P1YUVRR2;
	volatile	uint32_t	P1YUVGR1;
	volatile	uint32_t	P1YUVGR2;
	volatile	uint32_t	P1YUVBR1;
	volatile	uint32_t	P1YUVBR2;
	volatile	uint32_t	RESERVED29[9];
	volatile	uint32_t	P1PPCR;
	volatile	uint32_t	P1PPM0AR1;
	volatile	uint32_t	P1PPM0AR2;
	volatile	uint32_t	P1PPM0PR;
	volatile	uint32_t	P1STM0AR;
	volatile	uint32_t	P1PPM1AR1;
	volatile	uint32_t	P1PPM1AR2;
	volatile	uint32_t	P1PPM1PR;
	volatile	uint32_t	P1STM1AR;
	volatile	uint32_t	P1PPM2AR1;
	volatile	uint32_t	P1PPM2AR2;
	volatile	uint32_t	RESERVED30;
	volatile	uint32_t	P1STM2AR;
	volatile	uint32_t	P1IER;
	volatile	uint32_t	P1SR;
	volatile	uint32_t	P1FCR;
	volatile	uint32_t	RESERVED31;
	volatile	uint32_t	P1CFSCR;
	volatile	uint32_t	RESERVED32[7];
	volatile	uint32_t	P1CBPRCR;
	volatile	uint32_t	RESERVED33[6];
	volatile	uint32_t	P1CBLCCR;
	volatile	uint32_t	P1CEXCR1;
	volatile	uint32_t	P1CEXCR2;
	volatile	uint32_t	RESERVED34;
	volatile	uint32_t	P1CST1CR;
	volatile	uint32_t	P1CST2CR;
	volatile	uint32_t	P1CST3CR;
	volatile	uint32_t	P1CSTSTR;
	volatile	uint32_t	P1CSTSZR;
	volatile	uint32_t	RESERVED35[7];
	volatile	uint32_t	P1CCCCR;
	volatile	uint32_t	P1CCCRR1;
	volatile	uint32_t	P1CCCRR2;
	volatile	uint32_t	P1CCCGR1;
	volatile	uint32_t	P1CCCGR2;
	volatile	uint32_t	P1CCCBR1;
	volatile	uint32_t	P1CCCBR2;
	volatile	uint32_t	RESERVED36;
	volatile	uint32_t	P1CCTCR1;
	volatile	uint32_t	P1CCTCR2;
	volatile	uint32_t	P1CCTCR3;
	volatile	uint32_t	RESERVED37[21];
	volatile	uint32_t	P1CFCTCR;
	volatile	uint32_t	P1CCRSTR;
	volatile	uint32_t	P1CCRSZR;
	volatile	uint32_t	P1CDCCR;
	volatile	uint32_t	P1CDSCR;
	volatile	uint32_t	P1CDSRTIOR;
	volatile	uint32_t	P1CDSSZR;
	volatile	uint32_t	RESERVED38;
	volatile	uint32_t	P1CCMRICR;
	volatile	uint32_t	P1CRI1CR1;
	volatile	uint32_t	P1CRI1CR2;
	volatile	uint32_t	P1CRI2CR1;
	volatile	uint32_t	P1CRI2CR2;
	volatile	uint32_t	P1CRI3CR1;
	volatile	uint32_t	P1CRI3CR2;
	volatile	uint32_t	P1CRI4CR1;
	volatile	uint32_t	P1CRI4CR2;
	volatile	uint32_t	P1CRI5CR1;
	volatile	uint32_t	P1CRI5CR2;
	volatile	uint32_t	P1CRI6CR1;
	volatile	uint32_t	P1CRI6CR2;
	volatile	uint32_t	P1CRI7CR1;
	volatile	uint32_t	P1CRI7CR2;
	volatile	uint32_t	P1CRI8CR1;
	volatile	uint32_t	P1CRI8CR2;
	volatile	uint32_t	RESERVED39[23];
	volatile	uint32_t	P1CPPCR;
	volatile	uint32_t	P1CPPM0AR1;
	volatile	uint32_t	P1CPPM0AR2;
	volatile	uint32_t	P1CPPM0PR;
	volatile	uint32_t	RESERVED40;
	volatile	uint32_t	P1CPPM1AR1;
	volatile	uint32_t	P1CPPM1AR2;
	volatile	uint32_t	P1CPPM1PR;
	volatile	uint32_t	RESERVED41;
	volatile	uint32_t	P1CPPM2AR1;
	volatile	uint32_t	P1CPPM2AR2;
	volatile	uint32_t	RESERVED42[6];
	volatile	uint32_t	P2FSCR;
	volatile	uint32_t	RESERVED43[62];
	volatile	uint32_t	P2FCTCR;
	volatile	uint32_t	P2CRSTR;
	volatile	uint32_t	P2CRSZR;
	volatile	uint32_t	P2DCCR;
	volatile	uint32_t	P2DSCR;
	volatile	uint32_t	P2DSRTIOR;
	volatile	uint32_t	P2DSSZR;
	volatile	uint32_t	RESERVED44;
	volatile	uint32_t	P2CMRICR;
	volatile	uint32_t	P2RI1CR1;
	volatile	uint32_t	P2RI1CR2;
	volatile	uint32_t	P2RI2CR1;
	volatile	uint32_t	P2RI2CR2;
	volatile	uint32_t	P2RI3CR1;
	volatile	uint32_t	P2RI3CR2;
	volatile	uint32_t	P2RI4CR1;
	volatile	uint32_t	P2RI4CR2;
	volatile	uint32_t	P2RI5CR1;
	volatile	uint32_t	P2RI5CR2;
	volatile	uint32_t	P2RI6CR1;
	volatile	uint32_t	P2RI6CR2;
	volatile	uint32_t	P2RI7CR1;
	volatile	uint32_t	P2RI7CR2;
	volatile	uint32_t	P2RI8CR1;
	volatile	uint32_t	P2RI8CR2;
	volatile	uint32_t	RESERVED45[3];
	volatile	uint32_t	P2GMCR;
	volatile	uint32_t	RESERVED46[19];
	volatile	uint32_t	P2PPCR;
	volatile	uint32_t	P2PPM0AR1;
	volatile	uint32_t	P2PPM0AR2;
	volatile	uint32_t	P2PPM0PR;
	volatile	uint32_t	P2STM0AR;
	volatile	uint32_t	RESERVED47[8];
	volatile	uint32_t	P2IER;
	volatile	uint32_t	P2SR;
	volatile	uint32_t	P2FCR;
	volatile	uint32_t	RESERVED48;
	volatile	uint32_t	P2CFSCR;
	volatile	uint32_t	RESERVED49[62];
	volatile	uint32_t	P2CFCTCR;
	volatile	uint32_t	P2CCRSTR;
	volatile	uint32_t	P2CCRSZR;
	volatile	uint32_t	P2CDCCR;
	volatile	uint32_t	P2CDSCR;
	volatile	uint32_t	P2CDSRTIOR;
	volatile	uint32_t	P2CDSSZR;
	volatile	uint32_t	RESERVED50;
	volatile	uint32_t	P2CCMRICR;
	volatile	uint32_t	P2CRI1CR1;
	volatile	uint32_t	P2CRI1CR2;
	volatile	uint32_t	P2CRI2CR1;
	volatile	uint32_t	P2CRI2CR2;
	volatile	uint32_t	P2CRI3CR1;
	volatile	uint32_t	P2CRI3CR2;
	volatile	uint32_t	P2CRI4CR1;
	volatile	uint32_t	P2CRI4CR2;
	volatile	uint32_t	P2CRI5CR1;
	volatile	uint32_t	P2CRI5CR2;
	volatile	uint32_t	P2CRI6CR1;
	volatile	uint32_t	P2CRI6CR2;
	volatile	uint32_t	P2CRI7CR1;
	volatile	uint32_t	P2CRI7CR2;
	volatile	uint32_t	P2CRI8CR1;
	volatile	uint32_t	P2CRI8CR2;
	volatile	uint32_t	RESERVED51[23];
	volatile	uint32_t	P2CPPCR;
	volatile	uint32_t	P2CPPM0AR1;
	volatile	uint32_t	P2CPPM0AR2;
} DCMIPP_TypeDef;

#if (defined(__cplusplus))
#define	DCMIPP_NS	reinterpret_cast<DCMIPP_TypeDef *>(0x48002000u)
#define	DCMIPP_S	reinterpret_cast<DCMIPP_TypeDef *>(0x58002000u)

#else
#define	DCMIPP_NS	((DCMIPP_TypeDef *)0x48002000u)
#define	DCMIPP_S	((DCMIPP_TypeDef *)0x58002000u)
#endif

// IPGR1 Configuration

#define	DCMIPP_IPGR1_QOS_MODE				(0x1u<<24)
#define	DCMIPP_IPGR1_MEMORYPAGE				(0x7u<<0)
#define	DCMIPP_IPGR1_MEMORYPAGE_0			(0x1u<<0)

#define	DCMIPP_IPGR1_MEMORYPAGE_B_0X0		(0x0u<<0)
#define	DCMIPP_IPGR1_MEMORYPAGE_B_0X1		(0x1u<<0)

// IPGR2 Configuration

#define	DCMIPP_IPGR2_PSTART					(0x1u<<0)

#define	DCMIPP_IPGR2_PSTART_B_0X0			(0x0u<<0)
#define	DCMIPP_IPGR2_PSTART_B_0X1			(0x1u<<0)

// IPGR3 Configuration

#define	DCMIPP_IPGR3_IDLE					(0x1u<<0)

#define	DCMIPP_IPGR3_IDLE_B_0X0				(0x0u<<0)
#define	DCMIPP_IPGR3_IDLE_B_0X1				(0x1u<<0)

// IPGR8 Configuration

#define	DCMIPP_IPGR8_IPPID					(0xFFu<<24)
#define	DCMIPP_IPGR8_IPPID_0				(0x1u<<24)
#define	DCMIPP_IPGR8_ARCHIID				(0x1Fu<<16)
#define	DCMIPP_IPGR8_ARCHIID_0				(0x1u<<16)
#define	DCMIPP_IPGR8_REVID					(0x1Fu<<8)
#define	DCMIPP_IPGR8_REVID_0				(0x1u<<8)
#define	DCMIPP_IPGR8_DID					(0x3Fu<<0)
#define	DCMIPP_IPGR8_DID_0					(0x1u<<0)

// IPC1R1 Configuration

#define	DCMIPP_IPC1R1_OTR					(0xFu<<8)
#define	DCMIPP_IPC1R1_OTR_0					(0x1u<<8)
#define	DCMIPP_IPC1R1_TRAFFIC				(0x7u<<0)
#define	DCMIPP_IPC1R1_TRAFFIC_0				(0x1u<<0)

#define	DCMIPP_IPC1R1_OTR_B_0X0				(0x0u<<8)
#define	DCMIPP_IPC1R1_OTR_B_0X1				(0x1u<<8)
#define	DCMIPP_IPC1R1_TRAFFIC_B_0X0			(0x0u<<0)
#define	DCMIPP_IPC1R1_TRAFFIC_B_0X1			(0x1u<<0)

// IPC1R2 Configuration

#define	DCMIPP_IPC1R2_WLRU					(0xFu<<16)
#define	DCMIPP_IPC1R2_WLRU_0				(0x1u<<16)
#define	DCMIPP_IPC1R2_SVCMAPPING			(0xFu<<8)
#define	DCMIPP_IPC1R2_SVCMAPPING_0			(0x1u<<8)

#define	DCMIPP_IPC1R2_WLRU_B_0X0			(0x0u<<16)
#define	DCMIPP_IPC1R2_WLRU_B_0X1			(0x1u<<16)

// IPC1R3 Configuration

#define	DCMIPP_IPC1R3_DPREGEND				(0x3FFu<<16)
#define	DCMIPP_IPC1R3_DPREGEND_0			(0x1u<<16)
#define	DCMIPP_IPC1R3_DPREGSTART			(0x3FFu<<0)
#define	DCMIPP_IPC1R3_DPREGSTART_0			(0x1u<<0)

// IPC2R1 Configuration

#define	DCMIPP_IPC2R1_OTR					(0xFu<<8)
#define	DCMIPP_IPC2R1_OTR_0					(0x1u<<8)
#define	DCMIPP_IPC2R1_TRAFFIC				(0x7u<<0)
#define	DCMIPP_IPC2R1_TRAFFIC_0				(0x1u<<0)

#define	DCMIPP_IPC2R1_OTR_B_0X0				(0x0u<<8)
#define	DCMIPP_IPC2R1_OTR_B_0X1				(0x1u<<8)
#define	DCMIPP_IPC2R1_TRAFFIC_B_0X0			(0x0u<<0)
#define	DCMIPP_IPC2R1_TRAFFIC_B_0X1			(0x1u<<0)

// IPC2R2 Configuration

#define	DCMIPP_IPC2R2_WLRU					(0xFu<<16)
#define	DCMIPP_IPC2R2_WLRU_0				(0x1u<<16)
#define	DCMIPP_IPC2R2_SVCMAPPING			(0xFu<<8)
#define	DCMIPP_IPC2R2_SVCMAPPING_0			(0x1u<<8)

#define	DCMIPP_IPC2R2_WLRU_B_0X0			(0x0u<<16)
#define	DCMIPP_IPC2R2_WLRU_B_0X1			(0x1u<<16)

// IPC2R3 Configuration

#define	DCMIPP_IPC2R3_DPREGEND				(0x3FFu<<16)
#define	DCMIPP_IPC2R3_DPREGEND_0			(0x1u<<16)
#define	DCMIPP_IPC2R3_DPREGSTART			(0x3FFu<<0)
#define	DCMIPP_IPC2R3_DPREGSTART_0			(0x1u<<0)

// IPC3R1 Configuration

#define	DCMIPP_IPC3R1_OTR					(0xFu<<8)
#define	DCMIPP_IPC3R1_OTR_0					(0x1u<<8)
#define	DCMIPP_IPC3R1_TRAFFIC				(0x7u<<0)
#define	DCMIPP_IPC3R1_TRAFFIC_0				(0x1u<<0)

#define	DCMIPP_IPC3R1_OTR_B_0X0				(0x0u<<8)
#define	DCMIPP_IPC3R1_OTR_B_0X1				(0x1u<<8)
#define	DCMIPP_IPC3R1_TRAFFIC_B_0X0			(0x0u<<0)
#define	DCMIPP_IPC3R1_TRAFFIC_B_0X1			(0x1u<<0)

// IPC3R2 Configuration

#define	DCMIPP_IPC3R2_WLRU					(0xFu<<16)
#define	DCMIPP_IPC3R2_WLRU_0				(0x1u<<16)
#define	DCMIPP_IPC3R2_SVCMAPPING			(0xFu<<8)
#define	DCMIPP_IPC3R2_SVCMAPPING_0			(0x1u<<8)

#define	DCMIPP_IPC3R2_WLRU_B_0X0			(0x0u<<16)
#define	DCMIPP_IPC3R2_WLRU_B_0X1			(0x1u<<16)

// IPC3R3 Configuration

#define	DCMIPP_IPC3R3_DPREGEND				(0x3FFu<<16)
#define	DCMIPP_IPC3R3_DPREGEND_0			(0x1u<<16)
#define	DCMIPP_IPC3R3_DPREGSTART			(0x3FFu<<0)
#define	DCMIPP_IPC3R3_DPREGSTART_0			(0x1u<<0)

// IPC4R1 Configuration

#define	DCMIPP_IPC4R1_OTR					(0xFu<<8)
#define	DCMIPP_IPC4R1_OTR_0					(0x1u<<8)
#define	DCMIPP_IPC4R1_TRAFFIC				(0x7u<<0)
#define	DCMIPP_IPC4R1_TRAFFIC_0				(0x1u<<0)

#define	DCMIPP_IPC4R1_OTR_B_0X0				(0x0u<<8)
#define	DCMIPP_IPC4R1_OTR_B_0X1				(0x1u<<8)
#define	DCMIPP_IPC4R1_TRAFFIC_B_0X0			(0x0u<<0)
#define	DCMIPP_IPC4R1_TRAFFIC_B_0X1			(0x1u<<0)

// IPC4R2 Configuration

#define	DCMIPP_IPC4R2_WLRU					(0xFu<<16)
#define	DCMIPP_IPC4R2_WLRU_0				(0x1u<<16)
#define	DCMIPP_IPC4R2_SVCMAPPING			(0xFu<<8)
#define	DCMIPP_IPC4R2_SVCMAPPING_0			(0x1u<<8)

#define	DCMIPP_IPC4R2_WLRU_B_0X0			(0x0u<<16)
#define	DCMIPP_IPC4R2_WLRU_B_0X1			(0x1u<<16)

// IPC4R3 Configuration

#define	DCMIPP_IPC4R3_DPREGEND				(0x3FFu<<16)
#define	DCMIPP_IPC4R3_DPREGEND_0			(0x1u<<16)
#define	DCMIPP_IPC4R3_DPREGSTART			(0x3FFu<<0)
#define	DCMIPP_IPC4R3_DPREGSTART_0			(0x1u<<0)

// IPC5R1 Configuration

#define	DCMIPP_IPC5R1_OTR					(0xFu<<8)
#define	DCMIPP_IPC5R1_OTR_0					(0x1u<<8)
#define	DCMIPP_IPC5R1_TRAFFIC				(0x7u<<0)
#define	DCMIPP_IPC5R1_TRAFFIC_0				(0x1u<<0)

#define	DCMIPP_IPC5R1_OTR_B_0X0				(0x0u<<8)
#define	DCMIPP_IPC5R1_OTR_B_0X1				(0x1u<<8)
#define	DCMIPP_IPC5R1_TRAFFIC_B_0X0			(0x0u<<0)
#define	DCMIPP_IPC5R1_TRAFFIC_B_0X1			(0x1u<<0)

// IPC5R2 Configuration

#define	DCMIPP_IPC5R2_WLRU					(0xFu<<16)
#define	DCMIPP_IPC5R2_WLRU_0				(0x1u<<16)
#define	DCMIPP_IPC5R2_SVCMAPPING			(0xFu<<8)
#define	DCMIPP_IPC5R2_SVCMAPPING_0			(0x1u<<8)

#define	DCMIPP_IPC5R2_WLRU_B_0X0			(0x0u<<16)
#define	DCMIPP_IPC5R2_WLRU_B_0X1			(0x1u<<16)

// IPC5R3 Configuration

#define	DCMIPP_IPC5R3_DPREGEND				(0x3FFu<<16)
#define	DCMIPP_IPC5R3_DPREGEND_0			(0x1u<<16)
#define	DCMIPP_IPC5R3_DPREGSTART			(0x3FFu<<0)
#define	DCMIPP_IPC5R3_DPREGSTART_0			(0x1u<<0)

// PRCR Configuration

#define	DCMIPP_PRCR_SWAPBITS				(0x1u<<26)
#define	DCMIPP_PRCR_SWAPCYCLES				(0x1u<<25)
#define	DCMIPP_PRCR_FORMAT					(0xFFu<<16)
#define	DCMIPP_PRCR_FORMAT_0				(0x1u<<16)
#define	DCMIPP_PRCR_ENABLE					(0x1u<<14)
#define	DCMIPP_PRCR_EDM						(0x7u<<10)
#define	DCMIPP_PRCR_EDM_0					(0x1u<<10)
#define	DCMIPP_PRCR_VSPOL					(0x1u<<7)
#define	DCMIPP_PRCR_HSPOL					(0x1u<<6)
#define	DCMIPP_PRCR_PCKPOL					(0x1u<<5)
#define	DCMIPP_PRCR_ESS						(0x1u<<4)

#define	DCMIPP_PRCR_SWAPBITS_B_0X0			(0x0u<<26)
#define	DCMIPP_PRCR_SWAPBITS_B_0X1			(0x1u<<26)
#define	DCMIPP_PRCR_SWAPCYCLES_B_0X0		(0x0u<<25)
#define	DCMIPP_PRCR_SWAPCYCLES_B_0X1		(0x1u<<25)
#define	DCMIPP_PRCR_FORMAT_B_0X1E			(0x1Eu<<16)
#define	DCMIPP_PRCR_FORMAT_B_0X22			(0x22u<<16)
#define	DCMIPP_PRCR_FORMAT_B_0X24			(0x24u<<16)
#define	DCMIPP_PRCR_FORMAT_B_0X2A			(0x2Au<<16)
#define	DCMIPP_PRCR_FORMAT_B_0X2B			(0x2Bu<<16)
#define	DCMIPP_PRCR_FORMAT_B_0X2C			(0x2Cu<<16)
#define	DCMIPP_PRCR_FORMAT_B_0X2D			(0x2Du<<16)
#define	DCMIPP_PRCR_FORMAT_B_0X4A			(0x4Au<<16)
#define	DCMIPP_PRCR_FORMAT_B_0X4B			(0x4Bu<<16)
#define	DCMIPP_PRCR_FORMAT_B_0X4C			(0x4Cu<<16)
#define	DCMIPP_PRCR_FORMAT_B_0X4D			(0x4Du<<16)
#define	DCMIPP_PRCR_FORMAT_B_0X5A			(0x5Au<<16)
#define	DCMIPP_PRCR_ENABLE_B_0X0			(0x0u<<14)
#define	DCMIPP_PRCR_ENABLE_B_0X1			(0x1u<<14)
#define	DCMIPP_PRCR_EDM_B_0X0				(0x0u<<10)
#define	DCMIPP_PRCR_EDM_B_0X1				(0x1u<<10)
#define	DCMIPP_PRCR_EDM_B_0X2				(0x2u<<10)
#define	DCMIPP_PRCR_EDM_B_0X3				(0x3u<<10)
#define	DCMIPP_PRCR_EDM_B_0X4				(0x4u<<10)
#define	DCMIPP_PRCR_VSPOL_B_0X0				(0x0u<<7)
#define	DCMIPP_PRCR_VSPOL_B_0X1				(0x1u<<7)
#define	DCMIPP_PRCR_HSPOL_B_0X0				(0x0u<<6)
#define	DCMIPP_PRCR_HSPOL_B_0X1				(0x1u<<6)
#define	DCMIPP_PRCR_PCKPOL_B_0X0			(0x0u<<5)
#define	DCMIPP_PRCR_PCKPOL_B_0X1			(0x1u<<5)
#define	DCMIPP_PRCR_ESS_B_0X0				(0x0u<<4)
#define	DCMIPP_PRCR_ESS_B_0X1				(0x1u<<4)

// PRESCR Configuration

#define	DCMIPP_PRESCR_FEC					(0xFFu<<24)
#define	DCMIPP_PRESCR_FEC_0					(0x1u<<24)
#define	DCMIPP_PRESCR_LEC					(0xFFu<<16)
#define	DCMIPP_PRESCR_LEC_0					(0x1u<<16)
#define	DCMIPP_PRESCR_LSC					(0xFFu<<8)
#define	DCMIPP_PRESCR_LSC_0					(0x1u<<8)
#define	DCMIPP_PRESCR_FSC					(0xFFu<<0)
#define	DCMIPP_PRESCR_FSC_0					(0x1u<<0)

// PRESUR Configuration

#define	DCMIPP_PRESUR_FEU					(0xFFu<<24)
#define	DCMIPP_PRESUR_FEU_0					(0x1u<<24)
#define	DCMIPP_PRESUR_LEU					(0xFFu<<16)
#define	DCMIPP_PRESUR_LEU_0					(0x1u<<16)
#define	DCMIPP_PRESUR_LSU					(0xFFu<<8)
#define	DCMIPP_PRESUR_LSU_0					(0x1u<<8)
#define	DCMIPP_PRESUR_FSU					(0xFFu<<0)
#define	DCMIPP_PRESUR_FSU_0					(0x1u<<0)

#define	DCMIPP_PRESUR_FEU_B_0X0				(0x0u<<24)
#define	DCMIPP_PRESUR_FEU_B_0X1				(0x1u<<24)
#define	DCMIPP_PRESUR_LEU_B_0X0				(0x0u<<16)
#define	DCMIPP_PRESUR_LEU_B_0X1				(0x1u<<16)
#define	DCMIPP_PRESUR_LSU_B_0X0				(0x0u<<8)
#define	DCMIPP_PRESUR_LSU_B_0X1				(0x1u<<8)
#define	DCMIPP_PRESUR_FSU_B_0X0				(0x0u<<0)
#define	DCMIPP_PRESUR_FSU_B_0X1				(0x1u<<0)

// PRIER Configuration

#define	DCMIPP_PRIER_ERRIE					(0x1u<<6)

#define	DCMIPP_PRIER_ERRIE_B_0X0			(0x0u<<6)
#define	DCMIPP_PRIER_ERRIE_B_0X1			(0x1u<<6)

// PRSR Configuration

#define	DCMIPP_PRSR_VSYNC					(0x1u<<17)
#define	DCMIPP_PRSR_HSYNC					(0x1u<<16)
#define	DCMIPP_PRSR_ERRF					(0x1u<<6)

#define	DCMIPP_PRSR_VSYNC_B_0X0				(0x0u<<17)
#define	DCMIPP_PRSR_VSYNC_B_0X1				(0x1u<<17)
#define	DCMIPP_PRSR_HSYNC_B_0X0				(0x0u<<16)
#define	DCMIPP_PRSR_HSYNC_B_0X1				(0x1u<<16)
#define	DCMIPP_PRSR_ERRF_B_0X0				(0x0u<<6)
#define	DCMIPP_PRSR_ERRF_B_0X1				(0x1u<<6)

// PRFCR Configuration

#define	DCMIPP_PRFCR_CERRF					(0x1u<<6)

// CMCR Configuration

#define	DCMIPP_CMCR_SWAPRB					(0x1u<<7)
#define	DCMIPP_CMCR_CFC						(0x1u<<4)
#define	DCMIPP_CMCR_PSFC					(0x3u<<1)
#define	DCMIPP_CMCR_PSFC_0					(0x1u<<1)
#define	DCMIPP_CMCR_INSEL					(0x1u<<0)

#define	DCMIPP_CMCR_SWAPRB_B_0X0			(0x0u<<7)
#define	DCMIPP_CMCR_SWAPRB_B_0X1			(0x1u<<7)
#define	DCMIPP_CMCR_PSFC_B_0X0				(0x0u<<1)
#define	DCMIPP_CMCR_PSFC_B_0X1				(0x1u<<1)
#define	DCMIPP_CMCR_PSFC_B_0X2				(0x2u<<1)
#define	DCMIPP_CMCR_INSEL_B_0X0				(0x0u<<0)
#define	DCMIPP_CMCR_INSEL_B_0X1				(0x1u<<0)

// CMFRCR Configuration

#define	DCMIPP_CMFRCR_FRMCNT				(0xFFFFFFFFu<<0)
#define	DCMIPP_CMFRCR_FRMCNT_0				(0x1u<<0)

// CMIER Configuration

#define	DCMIPP_CMIER_P2OVRIE				(0x1u<<31)
#define	DCMIPP_CMIER_P2VSYNCIE				(0x1u<<26)
#define	DCMIPP_CMIER_P2FRAMEIE				(0x1u<<25)
#define	DCMIPP_CMIER_P2LINEIE				(0x1u<<24)
#define	DCMIPP_CMIER_P1OVRIE				(0x1u<<23)
#define	DCMIPP_CMIER_P1VSYNCIE				(0x1u<<18)
#define	DCMIPP_CMIER_P1FRAMEIE				(0x1u<<17)
#define	DCMIPP_CMIER_P1LINEIE				(0x1u<<16)
#define	DCMIPP_CMIER_P0OVRIE				(0x1u<<15)
#define	DCMIPP_CMIER_P0LIMITIE				(0x1u<<14)
#define	DCMIPP_CMIER_P0VSYNCIE				(0x1u<<10)
#define	DCMIPP_CMIER_P0FRAMEIE				(0x1u<<9)
#define	DCMIPP_CMIER_P0LINEIE				(0x1u<<8)
#define	DCMIPP_CMIER_PRERRIE				(0x1u<<6)
#define	DCMIPP_CMIER_ATXERRIE				(0x1u<<5)

#define	DCMIPP_CMIER_P2OVRIE_B_0X0			(0x0u<<31)
#define	DCMIPP_CMIER_P2OVRIE_B_0X1			(0x1u<<31)
#define	DCMIPP_CMIER_P2VSYNCIE_B_0X0		(0x0u<<26)
#define	DCMIPP_CMIER_P2VSYNCIE_B_0X1		(0x1u<<26)
#define	DCMIPP_CMIER_P2FRAMEIE_B_0X0		(0x0u<<25)
#define	DCMIPP_CMIER_P2FRAMEIE_B_0X1		(0x1u<<25)
#define	DCMIPP_CMIER_P2LINEIE_B_0X0			(0x0u<<24)
#define	DCMIPP_CMIER_P2LINEIE_B_0X1			(0x1u<<24)
#define	DCMIPP_CMIER_P1VSYNCIE_B_0X0		(0x0u<<18)
#define	DCMIPP_CMIER_P1VSYNCIE_B_0X1		(0x1u<<18)
#define	DCMIPP_CMIER_P1FRAMEIE_B_0X0		(0x0u<<17)
#define	DCMIPP_CMIER_P1FRAMEIE_B_0X1		(0x1u<<17)
#define	DCMIPP_CMIER_P1LINEIE_B_0X0			(0x0u<<16)
#define	DCMIPP_CMIER_P1LINEIE_B_0X1			(0x1u<<16)
#define	DCMIPP_CMIER_P0OVRIE_B_0X0			(0x0u<<15)
#define	DCMIPP_CMIER_P0OVRIE_B_0X1			(0x1u<<15)
#define	DCMIPP_CMIER_P0LIMITIE_B_0X0		(0x0u<<14)
#define	DCMIPP_CMIER_P0LIMITIE_B_0X1		(0x1u<<14)
#define	DCMIPP_CMIER_P0VSYNCIE_B_0X0		(0x0u<<10)
#define	DCMIPP_CMIER_P0VSYNCIE_B_0X1		(0x1u<<10)
#define	DCMIPP_CMIER_P0FRAMEIE_B_0X0		(0x0u<<9)
#define	DCMIPP_CMIER_P0FRAMEIE_B_0X1		(0x1u<<9)
#define	DCMIPP_CMIER_P0LINEIE_B_0X0			(0x0u<<8)
#define	DCMIPP_CMIER_P0LINEIE_B_0X1			(0x1u<<8)
#define	DCMIPP_CMIER_PRERRIE_B_0X0			(0x0u<<6)
#define	DCMIPP_CMIER_PRERRIE_B_0X1			(0x1u<<6)
#define	DCMIPP_CMIER_ATXERRIE_B_0X0			(0x0u<<5)
#define	DCMIPP_CMIER_ATXERRIE_B_0X1			(0x1u<<5)

// CMSR1 Configuration

#define	DCMIPP_CMSR1_P2CPTACT				(0x1u<<31)
#define	DCMIPP_CMSR1_P2LSTFRM				(0x1u<<25)
#define	DCMIPP_CMSR1_P2LSTLINE				(0x1u<<24)
#define	DCMIPP_CMSR1_P1CPTACT				(0x1u<<23)
#define	DCMIPP_CMSR1_P1LSTFRM				(0x1u<<17)
#define	DCMIPP_CMSR1_P1LSTLINE				(0x1u<<16)
#define	DCMIPP_CMSR1_P0CPTACT				(0x1u<<15)
#define	DCMIPP_CMSR1_P0LSTFRM				(0x1u<<9)
#define	DCMIPP_CMSR1_P0LSTLINE				(0x1u<<8)
#define	DCMIPP_CMSR1_PRVSYNC				(0x1u<<1)
#define	DCMIPP_CMSR1_PRHSYNC				(0x1u<<0)

#define	DCMIPP_CMSR1_P2CPTACT_B_0X0			(0x0u<<31)
#define	DCMIPP_CMSR1_P2CPTACT_B_0X1			(0x1u<<31)
#define	DCMIPP_CMSR1_P1CPTACT_B_0X0			(0x0u<<23)
#define	DCMIPP_CMSR1_P1CPTACT_B_0X1			(0x1u<<23)
#define	DCMIPP_CMSR1_P0CPTACT_B_0X0			(0x0u<<15)
#define	DCMIPP_CMSR1_P0CPTACT_B_0X1			(0x1u<<15)
#define	DCMIPP_CMSR1_PRVSYNC_B_0X0			(0x0u<<1)
#define	DCMIPP_CMSR1_PRVSYNC_B_0X1			(0x1u<<1)
#define	DCMIPP_CMSR1_PRHSYNC_B_0X0			(0x0u<<0)
#define	DCMIPP_CMSR1_PRHSYNC_B_0X1			(0x1u<<0)

// CMSR2 Configuration

#define	DCMIPP_CMSR2_P2OVRF					(0x1u<<31)
#define	DCMIPP_CMSR2_P2VSYNCF				(0x1u<<26)
#define	DCMIPP_CMSR2_P2FRAMEF				(0x1u<<25)
#define	DCMIPP_CMSR2_P2LINEF				(0x1u<<24)
#define	DCMIPP_CMSR2_P1OVRF					(0x1u<<23)
#define	DCMIPP_CMSR2_P1VSYNCF				(0x1u<<18)
#define	DCMIPP_CMSR2_P1FRAMEF				(0x1u<<17)
#define	DCMIPP_CMSR2_P1LINEF				(0x1u<<16)
#define	DCMIPP_CMSR2_P0OVRF					(0x1u<<15)
#define	DCMIPP_CMSR2_P0LIMITF				(0x1u<<14)
#define	DCMIPP_CMSR2_P0VSYNCF				(0x1u<<10)
#define	DCMIPP_CMSR2_P0FRAMEF				(0x1u<<9)
#define	DCMIPP_CMSR2_P0LINEF				(0x1u<<8)
#define	DCMIPP_CMSR2_PRERRF					(0x1u<<6)
#define	DCMIPP_CMSR2_ATXERRF				(0x1u<<5)

#define	DCMIPP_CMSR2_P2OVRF_B_0X0			(0x0u<<31)
#define	DCMIPP_CMSR2_P2OVRF_B_0X1			(0x1u<<31)
#define	DCMIPP_CMSR2_P2FRAMEF_B_0X0			(0x0u<<25)
#define	DCMIPP_CMSR2_P2FRAMEF_B_0X1			(0x1u<<25)
#define	DCMIPP_CMSR2_P1OVRF_B_0X0			(0x0u<<23)
#define	DCMIPP_CMSR2_P1OVRF_B_0X1			(0x1u<<23)
#define	DCMIPP_CMSR2_P1FRAMEF_B_0X0			(0x0u<<17)
#define	DCMIPP_CMSR2_P1FRAMEF_B_0X1			(0x1u<<17)
#define	DCMIPP_CMSR2_P0OVRF_B_0X0			(0x0u<<15)
#define	DCMIPP_CMSR2_P0OVRF_B_0X1			(0x1u<<15)
#define	DCMIPP_CMSR2_P0FRAMEF_B_0X0			(0x0u<<9)
#define	DCMIPP_CMSR2_P0FRAMEF_B_0X1			(0x1u<<9)
#define	DCMIPP_CMSR2_PRERRF_B_0X0			(0x0u<<6)
#define	DCMIPP_CMSR2_PRERRF_B_0X1			(0x1u<<6)
#define	DCMIPP_CMSR2_ATXERRF_B_0X0			(0x0u<<5)
#define	DCMIPP_CMSR2_ATXERRF_B_0X1			(0x1u<<5)

// CMFCR Configuration

#define	DCMIPP_CMFCR_CP2OVRF				(0x1u<<31)
#define	DCMIPP_CMFCR_CP2VSYNCF				(0x1u<<26)
#define	DCMIPP_CMFCR_CP2FRAMEF				(0x1u<<25)
#define	DCMIPP_CMFCR_CP2LINEF				(0x1u<<24)
#define	DCMIPP_CMFCR_CP1OVRF				(0x1u<<23)
#define	DCMIPP_CMFCR_CP1VSYNCF				(0x1u<<18)
#define	DCMIPP_CMFCR_CP1FRAMEF				(0x1u<<17)
#define	DCMIPP_CMFCR_CP1LINEF				(0x1u<<16)
#define	DCMIPP_CMFCR_CP0OVRF				(0x1u<<15)
#define	DCMIPP_CMFCR_CP0LIMITF				(0x1u<<14)
#define	DCMIPP_CMFCR_CP0VSYNCF				(0x1u<<10)
#define	DCMIPP_CMFCR_CP0FRAMEF				(0x1u<<9)
#define	DCMIPP_CMFCR_CP0LINEF				(0x1u<<8)
#define	DCMIPP_CMFCR_CPRERRF				(0x1u<<6)
#define	DCMIPP_CMFCR_CATXERRF				(0x1u<<5)

// P0FSCR Configuration

#define	DCMIPP_P0FSCR_PIPEN					(0x1u<<31)
#define	DCMIPP_P0FSCR_VC					(0x3u<<19)
#define	DCMIPP_P0FSCR_VC_0					(0x1u<<19)
#define	DCMIPP_P0FSCR_DTMODE				(0x3u<<16)
#define	DCMIPP_P0FSCR_DTMODE_0				(0x1u<<16)
#define	DCMIPP_P0FSCR_DTIDB					(0x3Fu<<8)
#define	DCMIPP_P0FSCR_DTIDB_0				(0x1u<<8)
#define	DCMIPP_P0FSCR_DTIDA					(0x3Fu<<0)
#define	DCMIPP_P0FSCR_DTIDA_0				(0x1u<<0)

#define	DCMIPP_P0FSCR_PIPEN_B_0X0			(0x0u<<31)
#define	DCMIPP_P0FSCR_PIPEN_B_0X1			(0x1u<<31)
#define	DCMIPP_P0FSCR_DTMODE_B_0X0			(0x0u<<16)
#define	DCMIPP_P0FSCR_DTMODE_B_0X1			(0x1u<<16)
#define	DCMIPP_P0FSCR_DTMODE_B_0X2			(0x2u<<16)
#define	DCMIPP_P0FSCR_DTMODE_B_0X3			(0x3u<<16)

// P0FCTCR Configuration

#define	DCMIPP_P0FCTCR_CPTREQ				(0x1u<<3)
#define	DCMIPP_P0FCTCR_CPTMODE				(0x1u<<2)
#define	DCMIPP_P0FCTCR_FRATE				(0x3u<<0)
#define	DCMIPP_P0FCTCR_FRATE_0				(0x1u<<0)

#define	DCMIPP_P0FCTCR_CPTREQ_B_0X0			(0x0u<<3)
#define	DCMIPP_P0FCTCR_CPTREQ_B_0X1			(0x1u<<3)
#define	DCMIPP_P0FCTCR_CPTMODE_B_0X0		(0x0u<<2)
#define	DCMIPP_P0FCTCR_CPTMODE_B_0X1		(0x1u<<2)
#define	DCMIPP_P0FCTCR_FRATE_B_0X0			(0x0u<<0)
#define	DCMIPP_P0FCTCR_FRATE_B_0X1			(0x1u<<0)
#define	DCMIPP_P0FCTCR_FRATE_B_0X2			(0x2u<<0)
#define	DCMIPP_P0FCTCR_FRATE_B_0X3			(0x3u<<0)

// P0SCSTR Configuration

#define	DCMIPP_P0SCSTR_VSTART				(0xFFFu<<16)
#define	DCMIPP_P0SCSTR_VSTART_0				(0x1u<<16)
#define	DCMIPP_P0SCSTR_HSTART				(0xFFFu<<0)
#define	DCMIPP_P0SCSTR_HSTART_0				(0x1u<<0)

// P0SCSZR Configuration

#define	DCMIPP_P0SCSZR_ENABLE				(0x1u<<31)
#define	DCMIPP_P0SCSZR_POSNEG				(0x1u<<30)
#define	DCMIPP_P0SCSZR_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P0SCSZR_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P0SCSZR_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P0SCSZR_HSIZE_0				(0x1u<<0)

#define	DCMIPP_P0SCSZR_ENABLE_B_0X0			(0x0u<<31)
#define	DCMIPP_P0SCSZR_ENABLE_B_0X1			(0x1u<<31)
#define	DCMIPP_P0SCSZR_POSNEG_B_0X0			(0x0u<<30)
#define	DCMIPP_P0SCSZR_POSNEG_B_0X1			(0x1u<<30)

// P0DCCNTR Configuration

#define	DCMIPP_P0DCCNTR_CNT					(0x3FFFFFFu<<0)
#define	DCMIPP_P0DCCNTR_CNT_0				(0x1u<<0)

// P0DCLMTR Configuration

#define	DCMIPP_P0DCLMTR_ENABLE				(0x1u<<31)
#define	DCMIPP_P0DCLMTR_LIMIT				(0xFFFFFFu<<0)
#define	DCMIPP_P0DCLMTR_LIMIT_0				(0x1u<<0)

#define	DCMIPP_P0DCLMTR_ENABLE_B_0X0		(0x0u<<31)
#define	DCMIPP_P0DCLMTR_ENABLE_B_0X1		(0x1u<<31)

// P0PPCR Configuration

#define	DCMIPP_P0PPCR_DBM					(0x1u<<16)
#define	DCMIPP_P0PPCR_LINEMULT				(0x7u<<13)
#define	DCMIPP_P0PPCR_LINEMULT_0			(0x1u<<13)
#define	DCMIPP_P0PPCR_OELS					(0x1u<<11)
#define	DCMIPP_P0PPCR_LSM					(0x1u<<10)
#define	DCMIPP_P0PPCR_OEBS					(0x1u<<9)
#define	DCMIPP_P0PPCR_BSM					(0x3u<<7)
#define	DCMIPP_P0PPCR_BSM_0					(0x1u<<7)
#define	DCMIPP_P0PPCR_HEADEREN				(0x1u<<6)
#define	DCMIPP_P0PPCR_PAD					(0x1u<<5)
#define	DCMIPP_P0PPCR_SWAPYUV				(0x1u<<0)

#define	DCMIPP_P0PPCR_DBM_B_0X0				(0x0u<<16)
#define	DCMIPP_P0PPCR_DBM_B_0X1				(0x1u<<16)
#define	DCMIPP_P0PPCR_LINEMULT_B_0X0		(0x0u<<13)
#define	DCMIPP_P0PPCR_LINEMULT_B_0X1		(0x1u<<13)
#define	DCMIPP_P0PPCR_LINEMULT_B_0X2		(0x2u<<13)
#define	DCMIPP_P0PPCR_LINEMULT_B_0X3		(0x3u<<13)
#define	DCMIPP_P0PPCR_LINEMULT_B_0X4		(0x4u<<13)
#define	DCMIPP_P0PPCR_LINEMULT_B_0X5		(0x5u<<13)
#define	DCMIPP_P0PPCR_LINEMULT_B_0X6		(0x6u<<13)
#define	DCMIPP_P0PPCR_LINEMULT_B_0X7		(0x7u<<13)
#define	DCMIPP_P0PPCR_OELS_B_0X0			(0x0u<<11)
#define	DCMIPP_P0PPCR_OELS_B_0X1			(0x1u<<11)
#define	DCMIPP_P0PPCR_LSM_B_0X0				(0x0u<<10)
#define	DCMIPP_P0PPCR_LSM_B_0X1				(0x1u<<10)
#define	DCMIPP_P0PPCR_OEBS_B_0X0			(0x0u<<9)
#define	DCMIPP_P0PPCR_OEBS_B_0X1			(0x1u<<9)
#define	DCMIPP_P0PPCR_BSM_B_0X0				(0x0u<<7)
#define	DCMIPP_P0PPCR_BSM_B_0X1				(0x1u<<7)
#define	DCMIPP_P0PPCR_BSM_B_0X2				(0x2u<<7)
#define	DCMIPP_P0PPCR_BSM_B_0X3				(0x3u<<7)
#define	DCMIPP_P0PPCR_HEADEREN_B_0X0		(0x0u<<6)
#define	DCMIPP_P0PPCR_HEADEREN_B_0X1		(0x1u<<6)
#define	DCMIPP_P0PPCR_PAD_B_0X0				(0x0u<<5)
#define	DCMIPP_P0PPCR_PAD_B_0X1				(0x1u<<5)
#define	DCMIPP_P0PPCR_SWAPYUV_B_0X0			(0x0u<<0)
#define	DCMIPP_P0PPCR_SWAPYUV_B_0X1			(0x1u<<0)

// P0PPM0AR1 Configuration

#define	DCMIPP_P0PPM0AR1_M0A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P0PPM0AR1_M0A_0				(0x1u<<0)

// P0PPM0AR2 Configuration

#define	DCMIPP_P0PPM0AR2_M0A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P0PPM0AR2_M0A_0				(0x1u<<0)

// P0STM0AR Configuration

#define	DCMIPP_P0STM0AR_M0A					(0xFFFFFFFFu<<0)
#define	DCMIPP_P0STM0AR_M0A_0				(0x1u<<0)

// P0IER Configuration

#define	DCMIPP_P0IER_OVRIE					(0x1u<<7)
#define	DCMIPP_P0IER_LIMITIE				(0x1u<<6)
#define	DCMIPP_P0IER_VSYNCIE				(0x1u<<2)
#define	DCMIPP_P0IER_FRAMEIE				(0x1u<<1)
#define	DCMIPP_P0IER_LINEIE					(0x1u<<0)

#define	DCMIPP_P0IER_OVRIE_B_0X0			(0x0u<<7)
#define	DCMIPP_P0IER_OVRIE_B_0X1			(0x1u<<7)
#define	DCMIPP_P0IER_LIMITIE_B_0X0			(0x0u<<6)
#define	DCMIPP_P0IER_LIMITIE_B_0X1			(0x1u<<6)
#define	DCMIPP_P0IER_VSYNCIE_B_0X0			(0x0u<<2)
#define	DCMIPP_P0IER_VSYNCIE_B_0X1			(0x1u<<2)
#define	DCMIPP_P0IER_FRAMEIE_B_0X0			(0x0u<<1)
#define	DCMIPP_P0IER_FRAMEIE_B_0X1			(0x1u<<1)
#define	DCMIPP_P0IER_LINEIE_B_0X0			(0x0u<<0)
#define	DCMIPP_P0IER_LINEIE_B_0X1			(0x1u<<0)

// P0SR Configuration

#define	DCMIPP_P0SR_CPTACT					(0x1u<<23)
#define	DCMIPP_P0SR_LSTFRM					(0x1u<<17)
#define	DCMIPP_P0SR_LSTLINE					(0x1u<<16)
#define	DCMIPP_P0SR_OVRF					(0x1u<<7)
#define	DCMIPP_P0SR_LIMITF					(0x1u<<6)
#define	DCMIPP_P0SR_VSYNCF					(0x1u<<2)
#define	DCMIPP_P0SR_FRAMEF					(0x1u<<1)
#define	DCMIPP_P0SR_LINEF					(0x1u<<0)

#define	DCMIPP_P0SR_CPTACT_B_0X0			(0x0u<<23)
#define	DCMIPP_P0SR_CPTACT_B_0X1			(0x1u<<23)
#define	DCMIPP_P0SR_OVRF_B_0X0				(0x0u<<7)
#define	DCMIPP_P0SR_OVRF_B_0X1				(0x1u<<7)
#define	DCMIPP_P0SR_FRAMEF_B_0X0			(0x0u<<1)
#define	DCMIPP_P0SR_FRAMEF_B_0X1			(0x1u<<1)

// P0FCR Configuration

#define	DCMIPP_P0FCR_COVRF					(0x1u<<7)
#define	DCMIPP_P0FCR_CLIMITF				(0x1u<<6)
#define	DCMIPP_P0FCR_CVSYNCF				(0x1u<<2)
#define	DCMIPP_P0FCR_CFRAMEF				(0x1u<<1)
#define	DCMIPP_P0FCR_CLINEF					(0x1u<<0)

// P0CFSCR Configuration

#define	DCMIPP_P0CFSCR_PIPEN				(0x1u<<31)
#define	DCMIPP_P0CFSCR_VC					(0x3u<<19)
#define	DCMIPP_P0CFSCR_VC_0					(0x1u<<19)
#define	DCMIPP_P0CFSCR_DTMODE				(0x3u<<16)
#define	DCMIPP_P0CFSCR_DTMODE_0				(0x1u<<16)
#define	DCMIPP_P0CFSCR_DTIDB				(0x3Fu<<8)
#define	DCMIPP_P0CFSCR_DTIDB_0				(0x1u<<8)
#define	DCMIPP_P0CFSCR_DTIDA				(0x3Fu<<0)
#define	DCMIPP_P0CFSCR_DTIDA_0				(0x1u<<0)

#define	DCMIPP_P0CFSCR_PIPEN_B_0X0			(0x0u<<31)
#define	DCMIPP_P0CFSCR_PIPEN_B_0X1			(0x1u<<31)
#define	DCMIPP_P0CFSCR_DTMODE_B_0X0			(0x0u<<16)
#define	DCMIPP_P0CFSCR_DTMODE_B_0X1			(0x1u<<16)
#define	DCMIPP_P0CFSCR_DTMODE_B_0X2			(0x2u<<16)
#define	DCMIPP_P0CFSCR_DTMODE_B_0X3			(0x3u<<16)

// P0CFCTCR Configuration

#define	DCMIPP_P0CFCTCR_CPTREQ				(0x1u<<3)
#define	DCMIPP_P0CFCTCR_CPTMODE				(0x1u<<2)
#define	DCMIPP_P0CFCTCR_FRATE				(0x3u<<0)
#define	DCMIPP_P0CFCTCR_FRATE_0				(0x1u<<0)

#define	DCMIPP_P0CFCTCR_CPTREQ_B_0X0		(0x0u<<3)
#define	DCMIPP_P0CFCTCR_CPTREQ_B_0X1		(0x1u<<3)
#define	DCMIPP_P0CFCTCR_CPTMODE_B_0X0		(0x0u<<2)
#define	DCMIPP_P0CFCTCR_CPTMODE_B_0X1		(0x1u<<2)
#define	DCMIPP_P0CFCTCR_FRATE_B_0X0			(0x0u<<0)
#define	DCMIPP_P0CFCTCR_FRATE_B_0X1			(0x1u<<0)
#define	DCMIPP_P0CFCTCR_FRATE_B_0X2			(0x2u<<0)
#define	DCMIPP_P0CFCTCR_FRATE_B_0X3			(0x3u<<0)

// P0CSCSTR Configuration

#define	DCMIPP_P0CSCSTR_VSTART				(0xFFFu<<16)
#define	DCMIPP_P0CSCSTR_VSTART_0			(0x1u<<16)
#define	DCMIPP_P0CSCSTR_HSTART				(0xFFFu<<0)
#define	DCMIPP_P0CSCSTR_HSTART_0			(0x1u<<0)

// P0CSCSZR Configuration

#define	DCMIPP_P0CSCSZR_ENABLE				(0x1u<<31)
#define	DCMIPP_P0CSCSZR_POSNEG				(0x1u<<30)
#define	DCMIPP_P0CSCSZR_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P0CSCSZR_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P0CSCSZR_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P0CSCSZR_HSIZE_0				(0x1u<<0)

#define	DCMIPP_P0CSCSZR_ENABLE_B_0X0		(0x0u<<31)
#define	DCMIPP_P0CSCSZR_ENABLE_B_0X1		(0x1u<<31)
#define	DCMIPP_P0CSCSZR_POSNEG_B_0X0		(0x0u<<30)
#define	DCMIPP_P0CSCSZR_POSNEG_B_0X1		(0x1u<<30)

// P0CPPCR Configuration

#define	DCMIPP_P0CPPCR_DBM					(0x1u<<16)
#define	DCMIPP_P0CPPCR_LINEMULT				(0x7u<<13)
#define	DCMIPP_P0CPPCR_LINEMULT_0			(0x1u<<13)
#define	DCMIPP_P0CPPCR_OELS					(0x1u<<11)
#define	DCMIPP_P0CPPCR_LSM					(0x1u<<10)
#define	DCMIPP_P0CPPCR_OEBS					(0x1u<<9)
#define	DCMIPP_P0CPPCR_BSM					(0x3u<<7)
#define	DCMIPP_P0CPPCR_BSM_0				(0x1u<<7)
#define	DCMIPP_P0CPPCR_HEADEREN				(0x1u<<6)
#define	DCMIPP_P0CPPCR_PAD					(0x1u<<5)
#define	DCMIPP_P0CPPCR_SWAPYUV				(0x1u<<0)

#define	DCMIPP_P0CPPCR_DBM_B_0X0			(0x0u<<16)
#define	DCMIPP_P0CPPCR_DBM_B_0X1			(0x1u<<16)
#define	DCMIPP_P0CPPCR_LINEMULT_B_0X0		(0x0u<<13)
#define	DCMIPP_P0CPPCR_LINEMULT_B_0X1		(0x1u<<13)
#define	DCMIPP_P0CPPCR_LINEMULT_B_0X2		(0x2u<<13)
#define	DCMIPP_P0CPPCR_LINEMULT_B_0X3		(0x3u<<13)
#define	DCMIPP_P0CPPCR_LINEMULT_B_0X4		(0x4u<<13)
#define	DCMIPP_P0CPPCR_LINEMULT_B_0X5		(0x5u<<13)
#define	DCMIPP_P0CPPCR_LINEMULT_B_0X6		(0x6u<<13)
#define	DCMIPP_P0CPPCR_LINEMULT_B_0X7		(0x7u<<13)
#define	DCMIPP_P0CPPCR_OELS_B_0X0			(0x0u<<11)
#define	DCMIPP_P0CPPCR_OELS_B_0X1			(0x1u<<11)
#define	DCMIPP_P0CPPCR_LSM_B_0X0			(0x0u<<10)
#define	DCMIPP_P0CPPCR_LSM_B_0X1			(0x1u<<10)
#define	DCMIPP_P0CPPCR_OEBS_B_0X0			(0x0u<<9)
#define	DCMIPP_P0CPPCR_OEBS_B_0X1			(0x1u<<9)
#define	DCMIPP_P0CPPCR_BSM_B_0X0			(0x0u<<7)
#define	DCMIPP_P0CPPCR_BSM_B_0X1			(0x1u<<7)
#define	DCMIPP_P0CPPCR_BSM_B_0X2			(0x2u<<7)
#define	DCMIPP_P0CPPCR_BSM_B_0X3			(0x3u<<7)
#define	DCMIPP_P0CPPCR_HEADEREN_B_0X0		(0x0u<<6)
#define	DCMIPP_P0CPPCR_HEADEREN_B_0X1		(0x1u<<6)
#define	DCMIPP_P0CPPCR_PAD_B_0X0			(0x0u<<5)
#define	DCMIPP_P0CPPCR_PAD_B_0X1			(0x1u<<5)
#define	DCMIPP_P0CPPCR_SWAPYUV_B_0X0		(0x0u<<0)
#define	DCMIPP_P0CPPCR_SWAPYUV_B_0X1		(0x1u<<0)

// P0CPPM0AR1 Configuration

#define	DCMIPP_P0CPPM0AR1_M0A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P0CPPM0AR1_M0A_0				(0x1u<<0)

// P0CPPM0AR2 Configuration

#define	DCMIPP_P0CPPM0AR2_M0A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P0CPPM0AR2_M0A_0				(0x1u<<0)

// P1FSCR Configuration

#define	DCMIPP_P1FSCR_PIPEN					(0x1u<<31)
#define	DCMIPP_P1FSCR_FDTFEN				(0x1u<<30)
#define	DCMIPP_P1FSCR_FDTF					(0x3Fu<<24)
#define	DCMIPP_P1FSCR_FDTF_0				(0x1u<<24)
#define	DCMIPP_P1FSCR_VC					(0x3u<<19)
#define	DCMIPP_P1FSCR_VC_0					(0x1u<<19)
#define	DCMIPP_P1FSCR_PIPEDIFF				(0x1u<<18)
#define	DCMIPP_P1FSCR_DTMODE				(0x3u<<16)
#define	DCMIPP_P1FSCR_DTMODE_0				(0x1u<<16)
#define	DCMIPP_P1FSCR_DTIDB					(0x3Fu<<8)
#define	DCMIPP_P1FSCR_DTIDB_0				(0x1u<<8)
#define	DCMIPP_P1FSCR_DTIDA					(0x3Fu<<0)
#define	DCMIPP_P1FSCR_DTIDA_0				(0x1u<<0)

#define	DCMIPP_P1FSCR_PIPEN_B_0X0			(0x0u<<31)
#define	DCMIPP_P1FSCR_PIPEN_B_0X1			(0x1u<<31)
#define	DCMIPP_P1FSCR_FDTFEN_B_0X0			(0x0u<<30)
#define	DCMIPP_P1FSCR_PIPEDIFF_B_0X0		(0x0u<<18)
#define	DCMIPP_P1FSCR_PIPEDIFF_B_0X1		(0x1u<<18)
#define	DCMIPP_P1FSCR_DTMODE_B_0X0			(0x0u<<16)
#define	DCMIPP_P1FSCR_DTMODE_B_0X1			(0x1u<<16)

// P1SRCR Configuration

#define	DCMIPP_P1SRCR_CROPEN				(0x1u<<15)
#define	DCMIPP_P1SRCR_FIRSTLINEDEL			(0x7u<<12)
#define	DCMIPP_P1SRCR_FIRSTLINEDEL_0		(0x1u<<12)
#define	DCMIPP_P1SRCR_LASTLINE				(0xFFFu<<0)
#define	DCMIPP_P1SRCR_LASTLINE_0			(0x1u<<0)

#define	DCMIPP_P1SRCR_CROPEN_B_0X0			(0x0u<<15)
#define	DCMIPP_P1SRCR_CROPEN_B_0X1			(0x1u<<15)

// P1BPRCR Configuration

#define	DCMIPP_P1BPRCR_STRENGTH				(0x7u<<1)
#define	DCMIPP_P1BPRCR_STRENGTH_0			(0x1u<<1)
#define	DCMIPP_P1BPRCR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1BPRCR_STRENGTH_B_0X0		(0x0u<<1)
#define	DCMIPP_P1BPRCR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1BPRCR_ENABLE_B_0X1			(0x1u<<0)

// P1BPRSR Configuration

#define	DCMIPP_P1BPRSR_BADCNT				(0xFFFu<<0)
#define	DCMIPP_P1BPRSR_BADCNT_0				(0x1u<<0)

// P1DECR Configuration

#define	DCMIPP_P1DECR_VDEC					(0x3u<<3)
#define	DCMIPP_P1DECR_VDEC_0				(0x1u<<3)
#define	DCMIPP_P1DECR_HDEC					(0x3u<<1)
#define	DCMIPP_P1DECR_HDEC_0				(0x1u<<1)
#define	DCMIPP_P1DECR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1DECR_VDEC_B_0X0			(0x0u<<3)
#define	DCMIPP_P1DECR_VDEC_B_0X1			(0x1u<<3)
#define	DCMIPP_P1DECR_HDEC_B_0X0			(0x0u<<1)
#define	DCMIPP_P1DECR_HDEC_B_0X1			(0x1u<<1)
#define	DCMIPP_P1DECR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1DECR_ENABLE_B_0X1			(0x1u<<0)

// P1BLCCR Configuration

#define	DCMIPP_P1BLCCR_BLCR					(0xFFu<<24)
#define	DCMIPP_P1BLCCR_BLCR_0				(0x1u<<24)
#define	DCMIPP_P1BLCCR_BLCG					(0xFFu<<16)
#define	DCMIPP_P1BLCCR_BLCG_0				(0x1u<<16)
#define	DCMIPP_P1BLCCR_BLCB					(0xFFu<<8)
#define	DCMIPP_P1BLCCR_BLCB_0				(0x1u<<8)
#define	DCMIPP_P1BLCCR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1BLCCR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1BLCCR_ENABLE_B_0X1			(0x1u<<0)

// P1EXCR1 Configuration

#define	DCMIPP_P1EXCR1_SHFR					(0x7u<<28)
#define	DCMIPP_P1EXCR1_SHFR_0				(0x1u<<28)
#define	DCMIPP_P1EXCR1_MULTR				(0xFFu<<20)
#define	DCMIPP_P1EXCR1_MULTR_0				(0x1u<<20)
#define	DCMIPP_P1EXCR1_ENABLE				(0x1u<<0)

#define	DCMIPP_P1EXCR1_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1EXCR1_ENABLE_B_0X1			(0x1u<<0)

// P1EXCR2 Configuration

#define	DCMIPP_P1EXCR2_SHFG					(0x7u<<28)
#define	DCMIPP_P1EXCR2_SHFG_0				(0x1u<<28)
#define	DCMIPP_P1EXCR2_MULTG				(0xFFu<<20)
#define	DCMIPP_P1EXCR2_MULTG_0				(0x1u<<20)
#define	DCMIPP_P1EXCR2_SHFB					(0x7u<<12)
#define	DCMIPP_P1EXCR2_SHFB_0				(0x1u<<12)
#define	DCMIPP_P1EXCR2_MULTB				(0xFFu<<4)
#define	DCMIPP_P1EXCR2_MULTB_0				(0x1u<<4)

// P1ST1CR Configuration

#define	DCMIPP_P1ST1CR_MODE					(0x1u<<7)
#define	DCMIPP_P1ST1CR_SRC					(0x7u<<4)
#define	DCMIPP_P1ST1CR_SRC_0				(0x1u<<4)
#define	DCMIPP_P1ST1CR_BINS					(0x3u<<2)
#define	DCMIPP_P1ST1CR_BINS_0				(0x1u<<2)
#define	DCMIPP_P1ST1CR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1ST1CR_MODE_B_0X0			(0x0u<<7)
#define	DCMIPP_P1ST1CR_MODE_B_0X1			(0x1u<<7)
#define	DCMIPP_P1ST1CR_BINS_B_0X0			(0x0u<<2)
#define	DCMIPP_P1ST1CR_BINS_B_0X1			(0x1u<<2)
#define	DCMIPP_P1ST1CR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1ST1CR_ENABLE_B_0X1			(0x1u<<0)

// P1ST2CR Configuration

#define	DCMIPP_P1ST2CR_MODE					(0x1u<<7)
#define	DCMIPP_P1ST2CR_SRC					(0x7u<<4)
#define	DCMIPP_P1ST2CR_SRC_0				(0x1u<<4)
#define	DCMIPP_P1ST2CR_BINS					(0x3u<<2)
#define	DCMIPP_P1ST2CR_BINS_0				(0x1u<<2)
#define	DCMIPP_P1ST2CR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1ST2CR_MODE_B_0X0			(0x0u<<7)
#define	DCMIPP_P1ST2CR_MODE_B_0X1			(0x1u<<7)
#define	DCMIPP_P1ST2CR_BINS_B_0X0			(0x0u<<2)
#define	DCMIPP_P1ST2CR_BINS_B_0X1			(0x1u<<2)
#define	DCMIPP_P1ST2CR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1ST2CR_ENABLE_B_0X1			(0x1u<<0)

// P1ST3CR Configuration

#define	DCMIPP_P1ST3CR_MODE					(0x1u<<7)
#define	DCMIPP_P1ST3CR_SRC					(0x7u<<4)
#define	DCMIPP_P1ST3CR_SRC_0				(0x1u<<4)
#define	DCMIPP_P1ST3CR_BINS					(0x3u<<2)
#define	DCMIPP_P1ST3CR_BINS_0				(0x1u<<2)
#define	DCMIPP_P1ST3CR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1ST3CR_MODE_B_0X0			(0x0u<<7)
#define	DCMIPP_P1ST3CR_MODE_B_0X1			(0x1u<<7)
#define	DCMIPP_P1ST3CR_BINS_B_0X0			(0x0u<<2)
#define	DCMIPP_P1ST3CR_BINS_B_0X1			(0x1u<<2)
#define	DCMIPP_P1ST3CR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1ST3CR_ENABLE_B_0X1			(0x1u<<0)

// P1STSTR Configuration

#define	DCMIPP_P1STSTR_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1STSTR_VSTART_0				(0x1u<<16)
#define	DCMIPP_P1STSTR_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1STSTR_HSTART_0				(0x1u<<0)

// P1STSZR Configuration

#define	DCMIPP_P1STSZR_CROPEN				(0x1u<<31)
#define	DCMIPP_P1STSZR_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1STSZR_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P1STSZR_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1STSZR_HSIZE_0				(0x1u<<0)

#define	DCMIPP_P1STSZR_CROPEN_B_0X0			(0x0u<<31)
#define	DCMIPP_P1STSZR_CROPEN_B_0X1			(0x1u<<31)

// P1ST1SR Configuration

#define	DCMIPP_P1ST1SR_ACCU					(0xFFFFFFu<<0)
#define	DCMIPP_P1ST1SR_ACCU_0				(0x1u<<0)

// P1ST2SR Configuration

#define	DCMIPP_P1ST2SR_ACCU					(0xFFFFFFu<<0)
#define	DCMIPP_P1ST2SR_ACCU_0				(0x1u<<0)

// P1ST3SR Configuration

#define	DCMIPP_P1ST3SR_ACCU					(0xFFFFFFu<<0)
#define	DCMIPP_P1ST3SR_ACCU_0				(0x1u<<0)

// P1DMCR Configuration

#define	DCMIPP_P1DMCR_EDGE					(0x7u<<28)
#define	DCMIPP_P1DMCR_EDGE_0				(0x1u<<28)
#define	DCMIPP_P1DMCR_LINEH					(0x7u<<24)
#define	DCMIPP_P1DMCR_LINEH_0				(0x1u<<24)
#define	DCMIPP_P1DMCR_LINEV					(0x7u<<20)
#define	DCMIPP_P1DMCR_LINEV_0				(0x1u<<20)
#define	DCMIPP_P1DMCR_PEAK					(0x7u<<16)
#define	DCMIPP_P1DMCR_PEAK_0				(0x1u<<16)
#define	DCMIPP_P1DMCR_TYPE					(0x3u<<1)
#define	DCMIPP_P1DMCR_TYPE_0				(0x1u<<1)
#define	DCMIPP_P1DMCR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1DMCR_EDGE_B_0X0			(0x0u<<28)
#define	DCMIPP_P1DMCR_LINEH_B_0X0			(0x0u<<24)
#define	DCMIPP_P1DMCR_LINEV_B_0X0			(0x0u<<20)
#define	DCMIPP_P1DMCR_PEAK_B_0X0			(0x0u<<16)
#define	DCMIPP_P1DMCR_TYPE_B_0X0			(0x0u<<1)
#define	DCMIPP_P1DMCR_TYPE_B_0X1			(0x1u<<1)
#define	DCMIPP_P1DMCR_TYPE_B_0X2			(0x2u<<1)
#define	DCMIPP_P1DMCR_TYPE_B_0X3			(0x3u<<1)
#define	DCMIPP_P1DMCR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1DMCR_ENABLE_B_0X1			(0x1u<<0)

// P1CCCR Configuration

#define	DCMIPP_P1CCCR_CLAMP					(0x1u<<2)
#define	DCMIPP_P1CCCR_TYPE					(0x1u<<1)
#define	DCMIPP_P1CCCR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1CCCR_CLAMP_B_0X0			(0x0u<<2)
#define	DCMIPP_P1CCCR_CLAMP_B_0X1			(0x1u<<2)
#define	DCMIPP_P1CCCR_TYPE_B_0X0			(0x0u<<1)
#define	DCMIPP_P1CCCR_TYPE_B_0X1			(0x1u<<1)
#define	DCMIPP_P1CCCR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1CCCR_ENABLE_B_0X1			(0x1u<<0)

// P1CCRR1 Configuration

#define	DCMIPP_P1CCRR1_RG					(0x7FFu<<16)
#define	DCMIPP_P1CCRR1_RG_0					(0x1u<<16)
#define	DCMIPP_P1CCRR1_RR					(0x7FFu<<0)
#define	DCMIPP_P1CCRR1_RR_0					(0x1u<<0)

// P1CCRR2 Configuration

#define	DCMIPP_P1CCRR2_RA					(0x3FFu<<16)
#define	DCMIPP_P1CCRR2_RA_0					(0x1u<<16)
#define	DCMIPP_P1CCRR2_RB					(0x7FFu<<0)
#define	DCMIPP_P1CCRR2_RB_0					(0x1u<<0)

// P1CCGR1 Configuration

#define	DCMIPP_P1CCGR1_GG					(0x7FFu<<16)
#define	DCMIPP_P1CCGR1_GG_0					(0x1u<<16)
#define	DCMIPP_P1CCGR1_GR					(0x7FFu<<0)
#define	DCMIPP_P1CCGR1_GR_0					(0x1u<<0)

// P1CCGR2 Configuration

#define	DCMIPP_P1CCGR2_GA					(0x3FFu<<16)
#define	DCMIPP_P1CCGR2_GA_0					(0x1u<<16)
#define	DCMIPP_P1CCGR2_GB					(0x7FFu<<0)
#define	DCMIPP_P1CCGR2_GB_0					(0x1u<<0)

// P1CCBR1 Configuration

#define	DCMIPP_P1CCBR1_BG					(0x7FFu<<16)
#define	DCMIPP_P1CCBR1_BG_0					(0x1u<<16)
#define	DCMIPP_P1CCBR1_BR					(0x7FFu<<0)
#define	DCMIPP_P1CCBR1_BR_0					(0x1u<<0)

// P1CCBR2 Configuration

#define	DCMIPP_P1CCBR2_BA					(0x3FFu<<16)
#define	DCMIPP_P1CCBR2_BA_0					(0x1u<<16)
#define	DCMIPP_P1CCBR2_BB					(0x7FFu<<0)
#define	DCMIPP_P1CCBR2_BB_0					(0x1u<<0)

// P1CTCR1 Configuration

#define	DCMIPP_P1CTCR1_LUM0					(0x3Fu<<9)
#define	DCMIPP_P1CTCR1_LUM0_0				(0x1u<<9)
#define	DCMIPP_P1CTCR1_ENABLE				(0x1u<<0)

#define	DCMIPP_P1CTCR1_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1CTCR1_ENABLE_B_0X1			(0x1u<<0)

// P1CTCR2 Configuration

#define	DCMIPP_P1CTCR2_LUM1					(0x3Fu<<25)
#define	DCMIPP_P1CTCR2_LUM1_0				(0x1u<<25)
#define	DCMIPP_P1CTCR2_LUM2					(0x3Fu<<17)
#define	DCMIPP_P1CTCR2_LUM2_0				(0x1u<<17)
#define	DCMIPP_P1CTCR2_LUM3					(0x3Fu<<9)
#define	DCMIPP_P1CTCR2_LUM3_0				(0x1u<<9)
#define	DCMIPP_P1CTCR2_LUM4					(0x3Fu<<1)
#define	DCMIPP_P1CTCR2_LUM4_0				(0x1u<<1)

// P1CTCR3 Configuration

#define	DCMIPP_P1CTCR3_LUM5					(0x3Fu<<25)
#define	DCMIPP_P1CTCR3_LUM5_0				(0x1u<<25)
#define	DCMIPP_P1CTCR3_LUM6					(0x3Fu<<17)
#define	DCMIPP_P1CTCR3_LUM6_0				(0x1u<<17)
#define	DCMIPP_P1CTCR3_LUM7					(0x3Fu<<9)
#define	DCMIPP_P1CTCR3_LUM7_0				(0x1u<<9)
#define	DCMIPP_P1CTCR3_LUM8					(0x3Fu<<1)
#define	DCMIPP_P1CTCR3_LUM8_0				(0x1u<<1)

// P1FCTCR Configuration

#define	DCMIPP_P1FCTCR_CPTREQ				(0x1u<<3)
#define	DCMIPP_P1FCTCR_CPTMODE				(0x1u<<2)
#define	DCMIPP_P1FCTCR_FRATE				(0x3u<<0)
#define	DCMIPP_P1FCTCR_FRATE_0				(0x1u<<0)

#define	DCMIPP_P1FCTCR_CPTREQ_B_0X0			(0x0u<<3)
#define	DCMIPP_P1FCTCR_CPTREQ_B_0X1			(0x1u<<3)
#define	DCMIPP_P1FCTCR_CPTMODE_B_0X0		(0x0u<<2)
#define	DCMIPP_P1FCTCR_CPTMODE_B_0X1		(0x1u<<2)
#define	DCMIPP_P1FCTCR_FRATE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1FCTCR_FRATE_B_0X1			(0x1u<<0)
#define	DCMIPP_P1FCTCR_FRATE_B_0X2			(0x2u<<0)
#define	DCMIPP_P1FCTCR_FRATE_B_0X3			(0x3u<<0)

// P1CRSTR Configuration

#define	DCMIPP_P1CRSTR_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1CRSTR_VSTART_0				(0x1u<<16)
#define	DCMIPP_P1CRSTR_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1CRSTR_HSTART_0				(0x1u<<0)

// P1CRSZR Configuration

#define	DCMIPP_P1CRSZR_ENABLE				(0x1u<<31)
#define	DCMIPP_P1CRSZR_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1CRSZR_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P1CRSZR_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1CRSZR_HSIZE_0				(0x1u<<0)

#define	DCMIPP_P1CRSZR_ENABLE_B_0X0			(0x0u<<31)
#define	DCMIPP_P1CRSZR_ENABLE_B_0X1			(0x1u<<31)

// P1DCCR Configuration

#define	DCMIPP_P1DCCR_VDEC					(0x3u<<3)
#define	DCMIPP_P1DCCR_VDEC_0				(0x1u<<3)
#define	DCMIPP_P1DCCR_HDEC					(0x3u<<1)
#define	DCMIPP_P1DCCR_HDEC_0				(0x1u<<1)
#define	DCMIPP_P1DCCR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1DCCR_VDEC_B_0X0			(0x0u<<3)
#define	DCMIPP_P1DCCR_VDEC_B_0X1			(0x1u<<3)
#define	DCMIPP_P1DCCR_HDEC_B_0X0			(0x0u<<1)
#define	DCMIPP_P1DCCR_HDEC_B_0X1			(0x1u<<1)
#define	DCMIPP_P1DCCR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1DCCR_ENABLE_B_0X1			(0x1u<<0)

// P1DSCR Configuration

#define	DCMIPP_P1DSCR_ENABLE				(0x1u<<31)
#define	DCMIPP_P1DSCR_VDIV					(0x3FFu<<16)
#define	DCMIPP_P1DSCR_VDIV_0				(0x1u<<16)
#define	DCMIPP_P1DSCR_HDIV					(0x3FFu<<0)
#define	DCMIPP_P1DSCR_HDIV_0				(0x1u<<0)

#define	DCMIPP_P1DSCR_ENABLE_B_0X0			(0x0u<<31)
#define	DCMIPP_P1DSCR_ENABLE_B_0X1			(0x1u<<31)

// P1DSRTIOR Configuration

#define	DCMIPP_P1DSRTIOR_VRATIO				(0xFFFFu<<16)
#define	DCMIPP_P1DSRTIOR_VRATIO_0			(0x1u<<16)
#define	DCMIPP_P1DSRTIOR_HRATIO				(0xFFFFu<<0)
#define	DCMIPP_P1DSRTIOR_HRATIO_0			(0x1u<<0)

// P1DSSZR Configuration

#define	DCMIPP_P1DSSZR_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1DSSZR_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P1DSSZR_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1DSSZR_HSIZE_0				(0x1u<<0)

// P1CMRICR Configuration

#define	DCMIPP_P1CMRICR_ROI8EN				(0x1u<<23)
#define	DCMIPP_P1CMRICR_ROI7EN				(0x1u<<22)
#define	DCMIPP_P1CMRICR_ROI6EN				(0x1u<<21)
#define	DCMIPP_P1CMRICR_ROI5EN				(0x1u<<20)
#define	DCMIPP_P1CMRICR_ROI4EN				(0x1u<<19)
#define	DCMIPP_P1CMRICR_ROI3EN				(0x1u<<18)
#define	DCMIPP_P1CMRICR_ROI2EN				(0x1u<<17)
#define	DCMIPP_P1CMRICR_ROI1EN				(0x1u<<16)
#define	DCMIPP_P1CMRICR_ROILSZ				(0x3u<<0)
#define	DCMIPP_P1CMRICR_ROILSZ_0			(0x1u<<0)

#define	DCMIPP_P1CMRICR_ROI8EN_B_0X0		(0x0u<<23)
#define	DCMIPP_P1CMRICR_ROI8EN_B_0X1		(0x1u<<23)
#define	DCMIPP_P1CMRICR_ROI7EN_B_0X0		(0x0u<<22)
#define	DCMIPP_P1CMRICR_ROI7EN_B_0X1		(0x1u<<22)
#define	DCMIPP_P1CMRICR_ROI6EN_B_0X0		(0x0u<<21)
#define	DCMIPP_P1CMRICR_ROI6EN_B_0X1		(0x1u<<21)
#define	DCMIPP_P1CMRICR_ROI5EN_B_0X0		(0x0u<<20)
#define	DCMIPP_P1CMRICR_ROI5EN_B_0X1		(0x1u<<20)
#define	DCMIPP_P1CMRICR_ROI4EN_B_0X0		(0x0u<<19)
#define	DCMIPP_P1CMRICR_ROI4EN_B_0X1		(0x1u<<19)
#define	DCMIPP_P1CMRICR_ROI3EN_B_0X0		(0x0u<<18)
#define	DCMIPP_P1CMRICR_ROI3EN_B_0X1		(0x1u<<18)
#define	DCMIPP_P1CMRICR_ROI2EN_B_0X0		(0x0u<<17)
#define	DCMIPP_P1CMRICR_ROI2EN_B_0X1		(0x1u<<17)
#define	DCMIPP_P1CMRICR_ROI1EN_B_0X0		(0x0u<<16)
#define	DCMIPP_P1CMRICR_ROI1EN_B_0X1		(0x1u<<16)
#define	DCMIPP_P1CMRICR_ROILSZ_B_0X0		(0x0u<<0)
#define	DCMIPP_P1CMRICR_ROILSZ_B_0X1		(0x1u<<0)
#define	DCMIPP_P1CMRICR_ROILSZ_B_0X2		(0x2u<<0)
#define	DCMIPP_P1CMRICR_ROILSZ_B_0X3		(0x3u<<0)

// P1RI1CR1 Configuration

#define	DCMIPP_P1RI1CR1_CLR					(0x3u<<28)
#define	DCMIPP_P1RI1CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1RI1CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1RI1CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1RI1CR1_CLG					(0x3u<<14)
#define	DCMIPP_P1RI1CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1RI1CR1_CLB					(0x3u<<12)
#define	DCMIPP_P1RI1CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1RI1CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1RI1CR1_HSTART_0			(0x1u<<0)

// P1RI1CR2 Configuration

#define	DCMIPP_P1RI1CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1RI1CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P1RI1CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1RI1CR2_HSIZE_0				(0x1u<<0)

// P1RI2CR1 Configuration

#define	DCMIPP_P1RI2CR1_CLR					(0x3u<<28)
#define	DCMIPP_P1RI2CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1RI2CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1RI2CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1RI2CR1_CLG					(0x3u<<14)
#define	DCMIPP_P1RI2CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1RI2CR1_CLB					(0x3u<<12)
#define	DCMIPP_P1RI2CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1RI2CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1RI2CR1_HSTART_0			(0x1u<<0)

// P1RI2CR2 Configuration

#define	DCMIPP_P1RI2CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1RI2CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P1RI2CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1RI2CR2_HSIZE_0				(0x1u<<0)

// P1RI3CR1 Configuration

#define	DCMIPP_P1RI3CR1_CLR					(0x3u<<28)
#define	DCMIPP_P1RI3CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1RI3CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1RI3CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1RI3CR1_CLG					(0x3u<<14)
#define	DCMIPP_P1RI3CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1RI3CR1_CLB					(0x3u<<12)
#define	DCMIPP_P1RI3CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1RI3CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1RI3CR1_HSTART_0			(0x1u<<0)

// P1RI3CR2 Configuration

#define	DCMIPP_P1RI3CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1RI3CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P1RI3CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1RI3CR2_HSIZE_0				(0x1u<<0)

// P1RI4CR1 Configuration

#define	DCMIPP_P1RI4CR1_CLR					(0x3u<<28)
#define	DCMIPP_P1RI4CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1RI4CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1RI4CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1RI4CR1_CLG					(0x3u<<14)
#define	DCMIPP_P1RI4CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1RI4CR1_CLB					(0x3u<<12)
#define	DCMIPP_P1RI4CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1RI4CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1RI4CR1_HSTART_0			(0x1u<<0)

// P1RI4CR2 Configuration

#define	DCMIPP_P1RI4CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1RI4CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P1RI4CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1RI4CR2_HSIZE_0				(0x1u<<0)

// P1RI5CR1 Configuration

#define	DCMIPP_P1RI5CR1_CLR					(0x3u<<28)
#define	DCMIPP_P1RI5CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1RI5CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1RI5CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1RI5CR1_CLG					(0x3u<<14)
#define	DCMIPP_P1RI5CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1RI5CR1_CLB					(0x3u<<12)
#define	DCMIPP_P1RI5CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1RI5CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1RI5CR1_HSTART_0			(0x1u<<0)

// P1RI5CR2 Configuration

#define	DCMIPP_P1RI5CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1RI5CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P1RI5CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1RI5CR2_HSIZE_0				(0x1u<<0)

// P1RI6CR1 Configuration

#define	DCMIPP_P1RI6CR1_CLR					(0x3u<<28)
#define	DCMIPP_P1RI6CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1RI6CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1RI6CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1RI6CR1_CLG					(0x3u<<14)
#define	DCMIPP_P1RI6CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1RI6CR1_CLB					(0x3u<<12)
#define	DCMIPP_P1RI6CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1RI6CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1RI6CR1_HSTART_0			(0x1u<<0)

// P1RI6CR2 Configuration

#define	DCMIPP_P1RI6CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1RI6CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P1RI6CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1RI6CR2_HSIZE_0				(0x1u<<0)

// P1RI7CR1 Configuration

#define	DCMIPP_P1RI7CR1_CLR					(0x3u<<28)
#define	DCMIPP_P1RI7CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1RI7CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1RI7CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1RI7CR1_CLG					(0x3u<<14)
#define	DCMIPP_P1RI7CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1RI7CR1_CLB					(0x3u<<12)
#define	DCMIPP_P1RI7CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1RI7CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1RI7CR1_HSTART_0			(0x1u<<0)

// P1RI7CR2 Configuration

#define	DCMIPP_P1RI7CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1RI7CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P1RI7CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1RI7CR2_HSIZE_0				(0x1u<<0)

// P1RI8CR1 Configuration

#define	DCMIPP_P1RI8CR1_CLR					(0x3u<<28)
#define	DCMIPP_P1RI8CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1RI8CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1RI8CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1RI8CR1_CLG					(0x3u<<14)
#define	DCMIPP_P1RI8CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1RI8CR1_CLB					(0x3u<<12)
#define	DCMIPP_P1RI8CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1RI8CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1RI8CR1_HSTART_0			(0x1u<<0)

// P1RI8CR2 Configuration

#define	DCMIPP_P1RI8CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1RI8CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P1RI8CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1RI8CR2_HSIZE_0				(0x1u<<0)

// P1GMCR Configuration

#define	DCMIPP_P1GMCR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1GMCR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1GMCR_ENABLE_B_0X1			(0x1u<<0)

// P1YUVCR Configuration

#define	DCMIPP_P1YUVCR_CLAMP				(0x1u<<2)
#define	DCMIPP_P1YUVCR_TYPE					(0x1u<<1)
#define	DCMIPP_P1YUVCR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1YUVCR_CLAMP_B_0X0			(0x0u<<2)
#define	DCMIPP_P1YUVCR_CLAMP_B_0X1			(0x1u<<2)
#define	DCMIPP_P1YUVCR_TYPE_B_0X0			(0x0u<<1)
#define	DCMIPP_P1YUVCR_TYPE_B_0X1			(0x1u<<1)
#define	DCMIPP_P1YUVCR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1YUVCR_ENABLE_B_0X1			(0x1u<<0)

// P1YUVRR1 Configuration

#define	DCMIPP_P1YUVRR1_RG					(0x7FFu<<16)
#define	DCMIPP_P1YUVRR1_RG_0				(0x1u<<16)
#define	DCMIPP_P1YUVRR1_RR					(0x7FFu<<0)
#define	DCMIPP_P1YUVRR1_RR_0				(0x1u<<0)

// P1YUVRR2 Configuration

#define	DCMIPP_P1YUVRR2_RA					(0x3FFu<<16)
#define	DCMIPP_P1YUVRR2_RA_0				(0x1u<<16)
#define	DCMIPP_P1YUVRR2_RB					(0x7FFu<<0)
#define	DCMIPP_P1YUVRR2_RB_0				(0x1u<<0)

// P1YUVGR1 Configuration

#define	DCMIPP_P1YUVGR1_GG					(0x7FFu<<16)
#define	DCMIPP_P1YUVGR1_GG_0				(0x1u<<16)
#define	DCMIPP_P1YUVGR1_GR					(0x7FFu<<0)
#define	DCMIPP_P1YUVGR1_GR_0				(0x1u<<0)

// P1YUVGR2 Configuration

#define	DCMIPP_P1YUVGR2_GA					(0x3FFu<<16)
#define	DCMIPP_P1YUVGR2_GA_0				(0x1u<<16)
#define	DCMIPP_P1YUVGR2_GB					(0x7FFu<<0)
#define	DCMIPP_P1YUVGR2_GB_0				(0x1u<<0)

// P1YUVBR1 Configuration

#define	DCMIPP_P1YUVBR1_BG					(0x7FFu<<16)
#define	DCMIPP_P1YUVBR1_BG_0				(0x1u<<16)
#define	DCMIPP_P1YUVBR1_BR					(0x7FFu<<0)
#define	DCMIPP_P1YUVBR1_BR_0				(0x1u<<0)

// P1YUVBR2 Configuration

#define	DCMIPP_P1YUVBR2_BA					(0x3FFu<<16)
#define	DCMIPP_P1YUVBR2_BA_0				(0x1u<<16)
#define	DCMIPP_P1YUVBR2_BB					(0x7FFu<<0)
#define	DCMIPP_P1YUVBR2_BB_0				(0x1u<<0)

// P1PPCR Configuration

#define	DCMIPP_P1PPCR_LMAWE					(0x1u<<20)
#define	DCMIPP_P1PPCR_LMAWM					(0x7u<<17)
#define	DCMIPP_P1PPCR_LMAWM_0				(0x1u<<17)
#define	DCMIPP_P1PPCR_DBM					(0x1u<<16)
#define	DCMIPP_P1PPCR_LINEMULT				(0x7u<<13)
#define	DCMIPP_P1PPCR_LINEMULT_0			(0x1u<<13)
#define	DCMIPP_P1PPCR_SWAPRB				(0x1u<<4)
#define	DCMIPP_P1PPCR_FORMAT				(0xFu<<0)
#define	DCMIPP_P1PPCR_FORMAT_0				(0x1u<<0)

#define	DCMIPP_P1PPCR_LMAWE_B_0X0			(0x0u<<20)
#define	DCMIPP_P1PPCR_LMAWE_B_0X1			(0x1u<<20)
#define	DCMIPP_P1PPCR_LMAWM_B_0X0			(0x0u<<17)
#define	DCMIPP_P1PPCR_LMAWM_B_0X1			(0x1u<<17)
#define	DCMIPP_P1PPCR_LMAWM_B_0X2			(0x2u<<17)
#define	DCMIPP_P1PPCR_LMAWM_B_0X3			(0x3u<<17)
#define	DCMIPP_P1PPCR_LMAWM_B_0X4			(0x4u<<17)
#define	DCMIPP_P1PPCR_LMAWM_B_0X5			(0x5u<<17)
#define	DCMIPP_P1PPCR_LMAWM_B_0X6			(0x6u<<17)
#define	DCMIPP_P1PPCR_LMAWM_B_0X7			(0x7u<<17)
#define	DCMIPP_P1PPCR_DBM_B_0X0				(0x0u<<16)
#define	DCMIPP_P1PPCR_DBM_B_0X1				(0x1u<<16)
#define	DCMIPP_P1PPCR_LINEMULT_B_0X0		(0x0u<<13)
#define	DCMIPP_P1PPCR_LINEMULT_B_0X1		(0x1u<<13)
#define	DCMIPP_P1PPCR_LINEMULT_B_0X2		(0x2u<<13)
#define	DCMIPP_P1PPCR_LINEMULT_B_0X3		(0x3u<<13)
#define	DCMIPP_P1PPCR_LINEMULT_B_0X4		(0x4u<<13)
#define	DCMIPP_P1PPCR_LINEMULT_B_0X5		(0x5u<<13)
#define	DCMIPP_P1PPCR_LINEMULT_B_0X6		(0x6u<<13)
#define	DCMIPP_P1PPCR_LINEMULT_B_0X7		(0x7u<<13)
#define	DCMIPP_P1PPCR_SWAPRB_B_0X0			(0x0u<<4)
#define	DCMIPP_P1PPCR_SWAPRB_B_0X1			(0x1u<<4)
#define	DCMIPP_P1PPCR_FORMAT_B_0X0			(0x0u<<0)
#define	DCMIPP_P1PPCR_FORMAT_B_0X1			(0x1u<<0)
#define	DCMIPP_P1PPCR_FORMAT_B_0X2			(0x2u<<0)
#define	DCMIPP_P1PPCR_FORMAT_B_0X3			(0x3u<<0)
#define	DCMIPP_P1PPCR_FORMAT_B_0X4			(0x4u<<0)
#define	DCMIPP_P1PPCR_FORMAT_B_0X5			(0x5u<<0)
#define	DCMIPP_P1PPCR_FORMAT_B_0X6			(0x6u<<0)
#define	DCMIPP_P1PPCR_FORMAT_B_0X7			(0x7u<<0)
#define	DCMIPP_P1PPCR_FORMAT_B_0X8			(0x8u<<0)
#define	DCMIPP_P1PPCR_FORMAT_B_0X9			(0x9u<<0)
#define	DCMIPP_P1PPCR_FORMAT_B_0XA			(0xAu<<0)

// P1PPM0AR1 Configuration

#define	DCMIPP_P1PPM0AR1_M0A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P1PPM0AR1_M0A_0				(0x1u<<0)

// P1PPM0AR2 Configuration

#define	DCMIPP_P1PPM0AR2_M0A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P1PPM0AR2_M0A_0				(0x1u<<0)

// P1PPM0PR Configuration

#define	DCMIPP_P1PPM0PR_PITCH				(0x7FFFu<<0)
#define	DCMIPP_P1PPM0PR_PITCH_0				(0x1u<<0)

// P1STM0AR Configuration

#define	DCMIPP_P1STM0AR_M0A					(0xFFFFFFFFu<<0)
#define	DCMIPP_P1STM0AR_M0A_0				(0x1u<<0)

// P1PPM1AR1 Configuration

#define	DCMIPP_P1PPM1AR1_M1A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P1PPM1AR1_M1A_0				(0x1u<<0)

// P1PPM1AR2 Configuration

#define	DCMIPP_P1PPM1AR2_M1A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P1PPM1AR2_M1A_0				(0x1u<<0)

// P1PPM1PR Configuration

#define	DCMIPP_P1PPM1PR_PITCH				(0x7FFFu<<0)
#define	DCMIPP_P1PPM1PR_PITCH_0				(0x1u<<0)

// P1STM1AR Configuration

#define	DCMIPP_P1STM1AR_M1A					(0xFFFFFFFFu<<0)
#define	DCMIPP_P1STM1AR_M1A_0				(0x1u<<0)

// P1PPM2AR1 Configuration

#define	DCMIPP_P1PPM2AR1_M2A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P1PPM2AR1_M2A_0				(0x1u<<0)

// P1PPM2AR2 Configuration

#define	DCMIPP_P1PPM2AR2_M2A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P1PPM2AR2_M2A_0				(0x1u<<0)

// P1STM2AR Configuration

#define	DCMIPP_P1STM2AR_M2A					(0xFFFFFFFFu<<0)
#define	DCMIPP_P1STM2AR_M2A_0				(0x1u<<0)

// P1IER Configuration

#define	DCMIPP_P1IER_OVRIE					(0x1u<<7)
#define	DCMIPP_P1IER_VSYNCIE				(0x1u<<2)
#define	DCMIPP_P1IER_FRAMEIE				(0x1u<<1)
#define	DCMIPP_P1IER_LINEIE					(0x1u<<0)

#define	DCMIPP_P1IER_OVRIE_B_0X0			(0x0u<<7)
#define	DCMIPP_P1IER_OVRIE_B_0X1			(0x1u<<7)
#define	DCMIPP_P1IER_VSYNCIE_B_0X0			(0x0u<<2)
#define	DCMIPP_P1IER_VSYNCIE_B_0X1			(0x1u<<2)
#define	DCMIPP_P1IER_FRAMEIE_B_0X0			(0x0u<<1)
#define	DCMIPP_P1IER_FRAMEIE_B_0X1			(0x1u<<1)
#define	DCMIPP_P1IER_LINEIE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1IER_LINEIE_B_0X1			(0x1u<<0)

// P1SR Configuration

#define	DCMIPP_P1SR_CPTACT					(0x1u<<23)
#define	DCMIPP_P1SR_LSTFRM					(0x1u<<17)
#define	DCMIPP_P1SR_LSTLINE					(0x1u<<16)
#define	DCMIPP_P1SR_OVRF					(0x1u<<7)
#define	DCMIPP_P1SR_VSYNCF					(0x1u<<2)
#define	DCMIPP_P1SR_FRAMEF					(0x1u<<1)
#define	DCMIPP_P1SR_LINEF					(0x1u<<0)

#define	DCMIPP_P1SR_CPTACT_B_0X0			(0x0u<<23)
#define	DCMIPP_P1SR_CPTACT_B_0X1			(0x1u<<23)
#define	DCMIPP_P1SR_OVRF_B_0X0				(0x0u<<7)
#define	DCMIPP_P1SR_OVRF_B_0X1				(0x1u<<7)
#define	DCMIPP_P1SR_FRAMEF_B_0X0			(0x0u<<1)
#define	DCMIPP_P1SR_FRAMEF_B_0X1			(0x1u<<1)

// P1FCR Configuration

#define	DCMIPP_P1FCR_COVRF					(0x1u<<7)
#define	DCMIPP_P1FCR_CVSYNCF				(0x1u<<2)
#define	DCMIPP_P1FCR_CFRAMEF				(0x1u<<1)
#define	DCMIPP_P1FCR_CLINEF					(0x1u<<0)

// P1CFSCR Configuration

#define	DCMIPP_P1CFSCR_PIPEN				(0x1u<<31)
#define	DCMIPP_P1CFSCR_FDTFEN				(0x1u<<30)
#define	DCMIPP_P1CFSCR_FDTF					(0x3Fu<<24)
#define	DCMIPP_P1CFSCR_FDTF_0				(0x1u<<24)
#define	DCMIPP_P1CFSCR_VC					(0x3u<<19)
#define	DCMIPP_P1CFSCR_VC_0					(0x1u<<19)
#define	DCMIPP_P1CFSCR_PIPEDIFF				(0x1u<<18)
#define	DCMIPP_P1CFSCR_DTMODE				(0x3u<<16)
#define	DCMIPP_P1CFSCR_DTMODE_0				(0x1u<<16)
#define	DCMIPP_P1CFSCR_DTIDB				(0x3Fu<<8)
#define	DCMIPP_P1CFSCR_DTIDB_0				(0x1u<<8)
#define	DCMIPP_P1CFSCR_DTIDA				(0x3Fu<<0)
#define	DCMIPP_P1CFSCR_DTIDA_0				(0x1u<<0)

#define	DCMIPP_P1CFSCR_PIPEN_B_0X0			(0x0u<<31)
#define	DCMIPP_P1CFSCR_PIPEN_B_0X1			(0x1u<<31)
#define	DCMIPP_P1CFSCR_FDTFEN_B_0X0			(0x0u<<30)
#define	DCMIPP_P1CFSCR_FDTFEN_B_0X1			(0x1u<<30)
#define	DCMIPP_P1CFSCR_PIPEDIFF_B_0X0		(0x0u<<18)
#define	DCMIPP_P1CFSCR_PIPEDIFF_B_0X1		(0x1u<<18)
#define	DCMIPP_P1CFSCR_DTMODE_B_0X0			(0x0u<<16)
#define	DCMIPP_P1CFSCR_DTMODE_B_0X1			(0x1u<<16)

// P1CBPRCR Configuration

#define	DCMIPP_P1CBPRCR_STRENGTH			(0x7u<<1)
#define	DCMIPP_P1CBPRCR_STRENGTH_0			(0x1u<<1)
#define	DCMIPP_P1CBPRCR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1CBPRCR_STRENGTH_B_0X0		(0x0u<<1)
#define	DCMIPP_P1CBPRCR_ENABLE_B_0X0		(0x0u<<0)
#define	DCMIPP_P1CBPRCR_ENABLE_B_0X1		(0x1u<<0)

// P1CBLCCR Configuration

#define	DCMIPP_P1CBLCCR_BLCR				(0xFFu<<24)
#define	DCMIPP_P1CBLCCR_BLCR_0				(0x1u<<24)
#define	DCMIPP_P1CBLCCR_BLCG				(0xFFu<<16)
#define	DCMIPP_P1CBLCCR_BLCG_0				(0x1u<<16)
#define	DCMIPP_P1CBLCCR_BLCB				(0xFFu<<8)
#define	DCMIPP_P1CBLCCR_BLCB_0				(0x1u<<8)
#define	DCMIPP_P1CBLCCR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1CBLCCR_ENABLE_B_0X0		(0x0u<<0)
#define	DCMIPP_P1CBLCCR_ENABLE_B_0X1		(0x1u<<0)

// P1CEXCR1 Configuration

#define	DCMIPP_P1CEXCR1_SHFR				(0x7u<<28)
#define	DCMIPP_P1CEXCR1_SHFR_0				(0x1u<<28)
#define	DCMIPP_P1CEXCR1_MULTR				(0xFFu<<20)
#define	DCMIPP_P1CEXCR1_MULTR_0				(0x1u<<20)
#define	DCMIPP_P1CEXCR1_ENABLE				(0x1u<<0)

#define	DCMIPP_P1CEXCR1_ENABLE_B_0X0		(0x0u<<0)
#define	DCMIPP_P1CEXCR1_ENABLE_B_0X1		(0x1u<<0)

// P1CEXCR2 Configuration

#define	DCMIPP_P1CEXCR2_SHFG				(0x7u<<28)
#define	DCMIPP_P1CEXCR2_SHFG_0				(0x1u<<28)
#define	DCMIPP_P1CEXCR2_MULTG				(0xFFu<<20)
#define	DCMIPP_P1CEXCR2_MULTG_0				(0x1u<<20)
#define	DCMIPP_P1CEXCR2_SHFB				(0x7u<<12)
#define	DCMIPP_P1CEXCR2_SHFB_0				(0x1u<<12)
#define	DCMIPP_P1CEXCR2_MULTB				(0xFFu<<4)
#define	DCMIPP_P1CEXCR2_MULTB_0				(0x1u<<4)

// P1CST1CR Configuration

#define	DCMIPP_P1CST1CR_ACCU				(0xFFFFFFu<<8)
#define	DCMIPP_P1CST1CR_ACCU_0				(0x1u<<8)
#define	DCMIPP_P1CST1CR_MODE				(0x1u<<7)
#define	DCMIPP_P1CST1CR_SRC					(0x7u<<4)
#define	DCMIPP_P1CST1CR_SRC_0				(0x1u<<4)
#define	DCMIPP_P1CST1CR_BINS				(0x3u<<2)
#define	DCMIPP_P1CST1CR_BINS_0				(0x1u<<2)
#define	DCMIPP_P1CST1CR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1CST1CR_MODE_B_0X0			(0x0u<<7)
#define	DCMIPP_P1CST1CR_MODE_B_0X1			(0x1u<<7)
#define	DCMIPP_P1CST1CR_BINS_B_0X0			(0x0u<<2)
#define	DCMIPP_P1CST1CR_BINS_B_0X1			(0x1u<<2)
#define	DCMIPP_P1CST1CR_ENABLE_B_0X0		(0x0u<<0)
#define	DCMIPP_P1CST1CR_ENABLE_B_0X1		(0x1u<<0)

// P1CST2CR Configuration

#define	DCMIPP_P1CST2CR_ACCU				(0xFFFFFFu<<8)
#define	DCMIPP_P1CST2CR_ACCU_0				(0x1u<<8)
#define	DCMIPP_P1CST2CR_MODE				(0x1u<<7)
#define	DCMIPP_P1CST2CR_SRC					(0x7u<<4)
#define	DCMIPP_P1CST2CR_SRC_0				(0x1u<<4)
#define	DCMIPP_P1CST2CR_BINS				(0x3u<<2)
#define	DCMIPP_P1CST2CR_BINS_0				(0x1u<<2)
#define	DCMIPP_P1CST2CR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1CST2CR_MODE_B_0X0			(0x0u<<7)
#define	DCMIPP_P1CST2CR_MODE_B_0X1			(0x1u<<7)
#define	DCMIPP_P1CST2CR_BINS_B_0X0			(0x0u<<2)
#define	DCMIPP_P1CST2CR_BINS_B_0X1			(0x1u<<2)
#define	DCMIPP_P1CST2CR_ENABLE_B_0X0		(0x0u<<0)
#define	DCMIPP_P1CST2CR_ENABLE_B_0X1		(0x1u<<0)

// P1CST3CR Configuration

#define	DCMIPP_P1CST3CR_ACCU				(0xFFFFFFu<<8)
#define	DCMIPP_P1CST3CR_ACCU_0				(0x1u<<8)
#define	DCMIPP_P1CST3CR_MODE				(0x1u<<7)
#define	DCMIPP_P1CST3CR_SRC					(0x7u<<4)
#define	DCMIPP_P1CST3CR_SRC_0				(0x1u<<4)
#define	DCMIPP_P1CST3CR_BINS				(0x3u<<2)
#define	DCMIPP_P1CST3CR_BINS_0				(0x1u<<2)
#define	DCMIPP_P1CST3CR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1CST3CR_MODE_B_0X0			(0x0u<<7)
#define	DCMIPP_P1CST3CR_MODE_B_0X1			(0x1u<<7)
#define	DCMIPP_P1CST3CR_BINS_B_0X0			(0x0u<<2)
#define	DCMIPP_P1CST3CR_BINS_B_0X1			(0x1u<<2)
#define	DCMIPP_P1CST3CR_ENABLE_B_0X0		(0x0u<<0)
#define	DCMIPP_P1CST3CR_ENABLE_B_0X1		(0x1u<<0)

// P1CSTSTR Configuration

#define	DCMIPP_P1CSTSTR_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1CSTSTR_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1CSTSTR_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1CSTSTR_HSTART_0			(0x1u<<0)

// P1CSTSZR Configuration

#define	DCMIPP_P1CSTSZR_CROPEN				(0x1u<<31)
#define	DCMIPP_P1CSTSZR_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1CSTSZR_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P1CSTSZR_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1CSTSZR_HSIZE_0				(0x1u<<0)

#define	DCMIPP_P1CSTSZR_CROPEN_B_0X0		(0x0u<<31)
#define	DCMIPP_P1CSTSZR_CROPEN_B_0X1		(0x1u<<31)

// P1CCCCR Configuration

#define	DCMIPP_P1CCCCR_CLAMP				(0x1u<<2)
#define	DCMIPP_P1CCCCR_TYPE					(0x1u<<1)
#define	DCMIPP_P1CCCCR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1CCCCR_CLAMP_B_0X0			(0x0u<<2)
#define	DCMIPP_P1CCCCR_CLAMP_B_0X1			(0x1u<<2)
#define	DCMIPP_P1CCCCR_TYPE_B_0X0			(0x0u<<1)
#define	DCMIPP_P1CCCCR_TYPE_B_0X1			(0x1u<<1)
#define	DCMIPP_P1CCCCR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1CCCCR_ENABLE_B_0X1			(0x1u<<0)

// P1CCCRR1 Configuration

#define	DCMIPP_P1CCCRR1_RG					(0x7FFu<<16)
#define	DCMIPP_P1CCCRR1_RG_0				(0x1u<<16)
#define	DCMIPP_P1CCCRR1_RR					(0x7FFu<<0)
#define	DCMIPP_P1CCCRR1_RR_0				(0x1u<<0)

// P1CCCRR2 Configuration

#define	DCMIPP_P1CCCRR2_RA					(0x3FFu<<16)
#define	DCMIPP_P1CCCRR2_RA_0				(0x1u<<16)
#define	DCMIPP_P1CCCRR2_RB					(0x7FFu<<0)
#define	DCMIPP_P1CCCRR2_RB_0				(0x1u<<0)

// P1CCCGR1 Configuration

#define	DCMIPP_P1CCCGR1_GG					(0x7FFu<<16)
#define	DCMIPP_P1CCCGR1_GG_0				(0x1u<<16)
#define	DCMIPP_P1CCCGR1_GR					(0x7FFu<<0)
#define	DCMIPP_P1CCCGR1_GR_0				(0x1u<<0)

// P1CCCGR2 Configuration

#define	DCMIPP_P1CCCGR2_GA					(0x3FFu<<16)
#define	DCMIPP_P1CCCGR2_GA_0				(0x1u<<16)
#define	DCMIPP_P1CCCGR2_GB					(0x7FFu<<0)
#define	DCMIPP_P1CCCGR2_GB_0				(0x1u<<0)

// P1CCCBR1 Configuration

#define	DCMIPP_P1CCCBR1_BG					(0x7FFu<<16)
#define	DCMIPP_P1CCCBR1_BG_0				(0x1u<<16)
#define	DCMIPP_P1CCCBR1_BR					(0x7FFu<<0)
#define	DCMIPP_P1CCCBR1_BR_0				(0x1u<<0)

// P1CCCBR2 Configuration

#define	DCMIPP_P1CCCBR2_BA					(0x3FFu<<16)
#define	DCMIPP_P1CCCBR2_BA_0				(0x1u<<16)
#define	DCMIPP_P1CCCBR2_BB					(0x7FFu<<0)
#define	DCMIPP_P1CCCBR2_BB_0				(0x1u<<0)

// P1CCTCR1 Configuration

#define	DCMIPP_P1CCTCR1_LUM0				(0x3Fu<<9)
#define	DCMIPP_P1CCTCR1_LUM0_0				(0x1u<<9)
#define	DCMIPP_P1CCTCR1_ENABLE				(0x1u<<0)

#define	DCMIPP_P1CCTCR1_ENABLE_B_0X0		(0x0u<<0)
#define	DCMIPP_P1CCTCR1_ENABLE_B_0X1		(0x1u<<0)

// P1CCTCR2 Configuration

#define	DCMIPP_P1CCTCR2_LUM1				(0x3Fu<<25)
#define	DCMIPP_P1CCTCR2_LUM1_0				(0x1u<<25)
#define	DCMIPP_P1CCTCR2_LUM2				(0x3Fu<<17)
#define	DCMIPP_P1CCTCR2_LUM2_0				(0x1u<<17)
#define	DCMIPP_P1CCTCR2_LUM3				(0x3Fu<<9)
#define	DCMIPP_P1CCTCR2_LUM3_0				(0x1u<<9)
#define	DCMIPP_P1CCTCR2_LUM4				(0x3Fu<<1)
#define	DCMIPP_P1CCTCR2_LUM4_0				(0x1u<<1)

// P1CCTCR3 Configuration

#define	DCMIPP_P1CCTCR3_LUM5				(0x3Fu<<25)
#define	DCMIPP_P1CCTCR3_LUM5_0				(0x1u<<25)
#define	DCMIPP_P1CCTCR3_LUM6				(0x3Fu<<17)
#define	DCMIPP_P1CCTCR3_LUM6_0				(0x1u<<17)
#define	DCMIPP_P1CCTCR3_LUM7				(0x3Fu<<9)
#define	DCMIPP_P1CCTCR3_LUM7_0				(0x1u<<9)
#define	DCMIPP_P1CCTCR3_LUM8				(0x3Fu<<1)
#define	DCMIPP_P1CCTCR3_LUM8_0				(0x1u<<1)

// P1CFCTCR Configuration

#define	DCMIPP_P1CFCTCR_CPTREQ				(0x1u<<3)
#define	DCMIPP_P1CFCTCR_CPTMODE				(0x1u<<2)
#define	DCMIPP_P1CFCTCR_FRATE				(0x3u<<0)
#define	DCMIPP_P1CFCTCR_FRATE_0				(0x1u<<0)

#define	DCMIPP_P1CFCTCR_CPTREQ_B_0X0		(0x0u<<3)
#define	DCMIPP_P1CFCTCR_CPTREQ_B_0X1		(0x1u<<3)
#define	DCMIPP_P1CFCTCR_CPTMODE_B_0X0		(0x0u<<2)
#define	DCMIPP_P1CFCTCR_CPTMODE_B_0X1		(0x1u<<2)
#define	DCMIPP_P1CFCTCR_FRATE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1CFCTCR_FRATE_B_0X1			(0x1u<<0)
#define	DCMIPP_P1CFCTCR_FRATE_B_0X2			(0x2u<<0)
#define	DCMIPP_P1CFCTCR_FRATE_B_0X3			(0x3u<<0)

// P1CCRSTR Configuration

#define	DCMIPP_P1CCRSTR_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1CCRSTR_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1CCRSTR_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1CCRSTR_HSTART_0			(0x1u<<0)

// P1CCRSZR Configuration

#define	DCMIPP_P1CCRSZR_ENABLE				(0x1u<<31)
#define	DCMIPP_P1CCRSZR_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1CCRSZR_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P1CCRSZR_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1CCRSZR_HSIZE_0				(0x1u<<0)

#define	DCMIPP_P1CCRSZR_ENABLE_B_0X0		(0x0u<<31)
#define	DCMIPP_P1CCRSZR_ENABLE_B_0X1		(0x1u<<31)

// P1CDCCR Configuration

#define	DCMIPP_P1CDCCR_VDEC					(0x3u<<3)
#define	DCMIPP_P1CDCCR_VDEC_0				(0x1u<<3)
#define	DCMIPP_P1CDCCR_HDEC					(0x3u<<1)
#define	DCMIPP_P1CDCCR_HDEC_0				(0x1u<<1)
#define	DCMIPP_P1CDCCR_ENABLE				(0x1u<<0)

#define	DCMIPP_P1CDCCR_VDEC_B_0X0			(0x0u<<3)
#define	DCMIPP_P1CDCCR_VDEC_B_0X1			(0x1u<<3)
#define	DCMIPP_P1CDCCR_HDEC_B_0X0			(0x0u<<1)
#define	DCMIPP_P1CDCCR_HDEC_B_0X1			(0x1u<<1)
#define	DCMIPP_P1CDCCR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P1CDCCR_ENABLE_B_0X1			(0x1u<<0)

// P1CDSCR Configuration

#define	DCMIPP_P1CDSCR_ENABLE				(0x1u<<31)
#define	DCMIPP_P1CDSCR_VDIV					(0x3FFu<<16)
#define	DCMIPP_P1CDSCR_VDIV_0				(0x1u<<16)
#define	DCMIPP_P1CDSCR_HDIV					(0x3FFu<<0)
#define	DCMIPP_P1CDSCR_HDIV_0				(0x1u<<0)

#define	DCMIPP_P1CDSCR_ENABLE_B_0X0			(0x0u<<31)
#define	DCMIPP_P1CDSCR_ENABLE_B_0X1			(0x1u<<31)

// P1CDSRTIOR Configuration

#define	DCMIPP_P1CDSRTIOR_VRATIO			(0xFFFFu<<16)
#define	DCMIPP_P1CDSRTIOR_VRATIO_0			(0x1u<<16)
#define	DCMIPP_P1CDSRTIOR_HRATIO			(0xFFFFu<<0)
#define	DCMIPP_P1CDSRTIOR_HRATIO_0			(0x1u<<0)

// P1CDSSZR Configuration

#define	DCMIPP_P1CDSSZR_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1CDSSZR_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P1CDSSZR_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1CDSSZR_HSIZE_0				(0x1u<<0)

// P1CCMRICR Configuration

#define	DCMIPP_P1CCMRICR_ROI8EN				(0x1u<<23)
#define	DCMIPP_P1CCMRICR_ROI7EN				(0x1u<<22)
#define	DCMIPP_P1CCMRICR_ROI6EN				(0x1u<<21)
#define	DCMIPP_P1CCMRICR_ROI5EN				(0x1u<<20)
#define	DCMIPP_P1CCMRICR_ROI4EN				(0x1u<<19)
#define	DCMIPP_P1CCMRICR_ROI3EN				(0x1u<<18)
#define	DCMIPP_P1CCMRICR_ROI2EN				(0x1u<<17)
#define	DCMIPP_P1CCMRICR_ROI1EN				(0x1u<<16)
#define	DCMIPP_P1CCMRICR_ROILSZ				(0x3u<<0)
#define	DCMIPP_P1CCMRICR_ROILSZ_0			(0x1u<<0)

#define	DCMIPP_P1CCMRICR_ROI8EN_B_0X0		(0x0u<<23)
#define	DCMIPP_P1CCMRICR_ROI8EN_B_0X1		(0x1u<<23)
#define	DCMIPP_P1CCMRICR_ROI7EN_B_0X0		(0x0u<<22)
#define	DCMIPP_P1CCMRICR_ROI7EN_B_0X1		(0x1u<<22)
#define	DCMIPP_P1CCMRICR_ROI6EN_B_0X0		(0x0u<<21)
#define	DCMIPP_P1CCMRICR_ROI6EN_B_0X1		(0x1u<<21)
#define	DCMIPP_P1CCMRICR_ROI5EN_B_0X0		(0x0u<<20)
#define	DCMIPP_P1CCMRICR_ROI5EN_B_0X1		(0x1u<<20)
#define	DCMIPP_P1CCMRICR_ROI4EN_B_0X0		(0x0u<<19)
#define	DCMIPP_P1CCMRICR_ROI4EN_B_0X1		(0x1u<<19)
#define	DCMIPP_P1CCMRICR_ROI3EN_B_0X0		(0x0u<<18)
#define	DCMIPP_P1CCMRICR_ROI3EN_B_0X1		(0x1u<<18)
#define	DCMIPP_P1CCMRICR_ROI2EN_B_0X0		(0x0u<<17)
#define	DCMIPP_P1CCMRICR_ROI2EN_B_0X1		(0x1u<<17)
#define	DCMIPP_P1CCMRICR_ROI1EN_B_0X0		(0x0u<<16)
#define	DCMIPP_P1CCMRICR_ROI1EN_B_0X1		(0x1u<<16)
#define	DCMIPP_P1CCMRICR_ROILSZ_B_0X0		(0x0u<<0)
#define	DCMIPP_P1CCMRICR_ROILSZ_B_0X1		(0x1u<<0)
#define	DCMIPP_P1CCMRICR_ROILSZ_B_0X2		(0x2u<<0)
#define	DCMIPP_P1CCMRICR_ROILSZ_B_0X3		(0x3u<<0)

// P1CRI1CR1 Configuration

#define	DCMIPP_P1CRI1CR1_CLR				(0x3u<<28)
#define	DCMIPP_P1CRI1CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1CRI1CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1CRI1CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1CRI1CR1_CLG				(0x3u<<14)
#define	DCMIPP_P1CRI1CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1CRI1CR1_CLB				(0x3u<<12)
#define	DCMIPP_P1CRI1CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1CRI1CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1CRI1CR1_HSTART_0			(0x1u<<0)

// P1CRI1CR2 Configuration

#define	DCMIPP_P1CRI1CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1CRI1CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P1CRI1CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1CRI1CR2_HSIZE_0			(0x1u<<0)

// P1CRI2CR1 Configuration

#define	DCMIPP_P1CRI2CR1_CLR				(0x3u<<28)
#define	DCMIPP_P1CRI2CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1CRI2CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1CRI2CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1CRI2CR1_CLG				(0x3u<<14)
#define	DCMIPP_P1CRI2CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1CRI2CR1_CLB				(0x3u<<12)
#define	DCMIPP_P1CRI2CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1CRI2CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1CRI2CR1_HSTART_0			(0x1u<<0)

// P1CRI2CR2 Configuration

#define	DCMIPP_P1CRI2CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1CRI2CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P1CRI2CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1CRI2CR2_HSIZE_0			(0x1u<<0)

// P1CRI3CR1 Configuration

#define	DCMIPP_P1CRI3CR1_CLR				(0x3u<<28)
#define	DCMIPP_P1CRI3CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1CRI3CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1CRI3CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1CRI3CR1_CLG				(0x3u<<14)
#define	DCMIPP_P1CRI3CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1CRI3CR1_CLB				(0x3u<<12)
#define	DCMIPP_P1CRI3CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1CRI3CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1CRI3CR1_HSTART_0			(0x1u<<0)

// P1CRI3CR2 Configuration

#define	DCMIPP_P1CRI3CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1CRI3CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P1CRI3CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1CRI3CR2_HSIZE_0			(0x1u<<0)

// P1CRI4CR1 Configuration

#define	DCMIPP_P1CRI4CR1_CLR				(0x3u<<28)
#define	DCMIPP_P1CRI4CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1CRI4CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1CRI4CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1CRI4CR1_CLG				(0x3u<<14)
#define	DCMIPP_P1CRI4CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1CRI4CR1_CLB				(0x3u<<12)
#define	DCMIPP_P1CRI4CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1CRI4CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1CRI4CR1_HSTART_0			(0x1u<<0)

// P1CRI4CR2 Configuration

#define	DCMIPP_P1CRI4CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1CRI4CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P1CRI4CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1CRI4CR2_HSIZE_0			(0x1u<<0)

// P1CRI5CR1 Configuration

#define	DCMIPP_P1CRI5CR1_CLR				(0x3u<<28)
#define	DCMIPP_P1CRI5CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1CRI5CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1CRI5CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1CRI5CR1_CLG				(0x3u<<14)
#define	DCMIPP_P1CRI5CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1CRI5CR1_CLB				(0x3u<<12)
#define	DCMIPP_P1CRI5CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1CRI5CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1CRI5CR1_HSTART_0			(0x1u<<0)

// P1CRI5CR2 Configuration

#define	DCMIPP_P1CRI5CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1CRI5CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P1CRI5CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1CRI5CR2_HSIZE_0			(0x1u<<0)

// P1CRI6CR1 Configuration

#define	DCMIPP_P1CRI6CR1_CLR				(0x3u<<28)
#define	DCMIPP_P1CRI6CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1CRI6CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1CRI6CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1CRI6CR1_CLG				(0x3u<<14)
#define	DCMIPP_P1CRI6CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1CRI6CR1_CLB				(0x3u<<12)
#define	DCMIPP_P1CRI6CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1CRI6CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1CRI6CR1_HSTART_0			(0x1u<<0)

// P1CRI6CR2 Configuration

#define	DCMIPP_P1CRI6CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1CRI6CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P1CRI6CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1CRI6CR2_HSIZE_0			(0x1u<<0)

// P1CRI7CR1 Configuration

#define	DCMIPP_P1CRI7CR1_CLR				(0x3u<<28)
#define	DCMIPP_P1CRI7CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1CRI7CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1CRI7CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1CRI7CR1_CLG				(0x3u<<14)
#define	DCMIPP_P1CRI7CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1CRI7CR1_CLB				(0x3u<<12)
#define	DCMIPP_P1CRI7CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1CRI7CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1CRI7CR1_HSTART_0			(0x1u<<0)

// P1CRI7CR2 Configuration

#define	DCMIPP_P1CRI7CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1CRI7CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P1CRI7CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1CRI7CR2_HSIZE_0			(0x1u<<0)

// P1CRI8CR1 Configuration

#define	DCMIPP_P1CRI8CR1_CLR				(0x3u<<28)
#define	DCMIPP_P1CRI8CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P1CRI8CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P1CRI8CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P1CRI8CR1_CLG				(0x3u<<14)
#define	DCMIPP_P1CRI8CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P1CRI8CR1_CLB				(0x3u<<12)
#define	DCMIPP_P1CRI8CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P1CRI8CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P1CRI8CR1_HSTART_0			(0x1u<<0)

// P1CRI8CR2 Configuration

#define	DCMIPP_P1CRI8CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P1CRI8CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P1CRI8CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P1CRI8CR2_HSIZE_0			(0x1u<<0)

// P1CPPCR Configuration

#define	DCMIPP_P1CPPCR_LMAWE				(0x1u<<20)
#define	DCMIPP_P1CPPCR_LMAWM				(0x7u<<17)
#define	DCMIPP_P1CPPCR_LMAWM_0				(0x1u<<17)
#define	DCMIPP_P1CPPCR_DBM					(0x1u<<16)
#define	DCMIPP_P1CPPCR_LINEMULT				(0x7u<<13)
#define	DCMIPP_P1CPPCR_LINEMULT_0			(0x1u<<13)
#define	DCMIPP_P1CPPCR_SWAPRB				(0x1u<<4)
#define	DCMIPP_P1CPPCR_FORMAT				(0xFu<<0)
#define	DCMIPP_P1CPPCR_FORMAT_0				(0x1u<<0)

#define	DCMIPP_P1CPPCR_LMAWE_B_0X0			(0x0u<<20)
#define	DCMIPP_P1CPPCR_LMAWE_B_0X1			(0x1u<<20)
#define	DCMIPP_P1CPPCR_LMAWM_B_0X0			(0x0u<<17)
#define	DCMIPP_P1CPPCR_LMAWM_B_0X1			(0x1u<<17)
#define	DCMIPP_P1CPPCR_LMAWM_B_0X2			(0x2u<<17)
#define	DCMIPP_P1CPPCR_LMAWM_B_0X3			(0x3u<<17)
#define	DCMIPP_P1CPPCR_LMAWM_B_0X4			(0x4u<<17)
#define	DCMIPP_P1CPPCR_LMAWM_B_0X5			(0x5u<<17)
#define	DCMIPP_P1CPPCR_LMAWM_B_0X6			(0x6u<<17)
#define	DCMIPP_P1CPPCR_LMAWM_B_0X7			(0x7u<<17)
#define	DCMIPP_P1CPPCR_DBM_B_0X0			(0x0u<<16)
#define	DCMIPP_P1CPPCR_DBM_B_0X1			(0x1u<<16)
#define	DCMIPP_P1CPPCR_LINEMULT_B_0X0		(0x0u<<13)
#define	DCMIPP_P1CPPCR_LINEMULT_B_0X1		(0x1u<<13)
#define	DCMIPP_P1CPPCR_LINEMULT_B_0X2		(0x2u<<13)
#define	DCMIPP_P1CPPCR_LINEMULT_B_0X3		(0x3u<<13)
#define	DCMIPP_P1CPPCR_LINEMULT_B_0X4		(0x4u<<13)
#define	DCMIPP_P1CPPCR_LINEMULT_B_0X5		(0x5u<<13)
#define	DCMIPP_P1CPPCR_LINEMULT_B_0X6		(0x6u<<13)
#define	DCMIPP_P1CPPCR_LINEMULT_B_0X7		(0x7u<<13)
#define	DCMIPP_P1CPPCR_SWAPRB_B_0X0			(0x0u<<4)
#define	DCMIPP_P1CPPCR_SWAPRB_B_0X1			(0x1u<<4)
#define	DCMIPP_P1CPPCR_FORMAT_B_0X0			(0x0u<<0)
#define	DCMIPP_P1CPPCR_FORMAT_B_0X1			(0x1u<<0)
#define	DCMIPP_P1CPPCR_FORMAT_B_0X2			(0x2u<<0)
#define	DCMIPP_P1CPPCR_FORMAT_B_0X3			(0x3u<<0)
#define	DCMIPP_P1CPPCR_FORMAT_B_0X4			(0x4u<<0)
#define	DCMIPP_P1CPPCR_FORMAT_B_0X5			(0x5u<<0)
#define	DCMIPP_P1CPPCR_FORMAT_B_0X6			(0x6u<<0)
#define	DCMIPP_P1CPPCR_FORMAT_B_0X7			(0x7u<<0)
#define	DCMIPP_P1CPPCR_FORMAT_B_0X8			(0x8u<<0)
#define	DCMIPP_P1CPPCR_FORMAT_B_0X9			(0x9u<<0)
#define	DCMIPP_P1CPPCR_FORMAT_B_0XA			(0xAu<<0)

// P1CPPM0AR1 Configuration

#define	DCMIPP_P1CPPM0AR1_M0A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P1CPPM0AR1_M0A_0				(0x1u<<0)

// P1CPPM0AR2 Configuration

#define	DCMIPP_P1CPPM0AR2_M0A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P1CPPM0AR2_M0A_0				(0x1u<<0)

// P1CPPM0PR Configuration

#define	DCMIPP_P1CPPM0PR_PITCH				(0x7FFFu<<0)
#define	DCMIPP_P1CPPM0PR_PITCH_0			(0x1u<<0)

// P1CPPM1AR1 Configuration

#define	DCMIPP_P1CPPM1AR1_M1A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P1CPPM1AR1_M1A_0				(0x1u<<0)

// P1CPPM1AR2 Configuration

#define	DCMIPP_P1CPPM1AR2_M1A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P1CPPM1AR2_M1A_0				(0x1u<<0)

// P1CPPM1PR Configuration

#define	DCMIPP_P1CPPM1PR_PITCH				(0x7FFFu<<0)
#define	DCMIPP_P1CPPM1PR_PITCH_0			(0x1u<<0)

// P1CPPM2AR1 Configuration

#define	DCMIPP_P1CPPM2AR1_M2A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P1CPPM2AR1_M2A_0				(0x1u<<0)

// P1CPPM2AR2 Configuration

#define	DCMIPP_P1CPPM2AR2_M2A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P1CPPM2AR2_M2A_0				(0x1u<<0)

// P2FSCR Configuration

#define	DCMIPP_P2FSCR_PIPEN					(0x1u<<31)
#define	DCMIPP_P2FSCR_FDTFEN				(0x1u<<30)
#define	DCMIPP_P2FSCR_FDTF					(0x3Fu<<24)
#define	DCMIPP_P2FSCR_FDTF_0				(0x1u<<24)
#define	DCMIPP_P2FSCR_VC					(0x3u<<19)
#define	DCMIPP_P2FSCR_VC_0					(0x1u<<19)
#define	DCMIPP_P2FSCR_DTIDA					(0x3Fu<<0)
#define	DCMIPP_P2FSCR_DTIDA_0				(0x1u<<0)

#define	DCMIPP_P2FSCR_PIPEN_B_0X0			(0x0u<<31)
#define	DCMIPP_P2FSCR_PIPEN_B_0X1			(0x1u<<31)
#define	DCMIPP_P2FSCR_FDTFEN_B_0X0			(0x0u<<30)
#define	DCMIPP_P2FSCR_FDTFEN_B_0X1			(0x1u<<30)

// P2FCTCR Configuration

#define	DCMIPP_P2FCTCR_CPTREQ				(0x1u<<3)
#define	DCMIPP_P2FCTCR_CPTMODE				(0x1u<<2)
#define	DCMIPP_P2FCTCR_FRATE				(0x3u<<0)
#define	DCMIPP_P2FCTCR_FRATE_0				(0x1u<<0)

#define	DCMIPP_P2FCTCR_CPTREQ_B_0X0			(0x0u<<3)
#define	DCMIPP_P2FCTCR_CPTREQ_B_0X1			(0x1u<<3)
#define	DCMIPP_P2FCTCR_CPTMODE_B_0X0		(0x0u<<2)
#define	DCMIPP_P2FCTCR_CPTMODE_B_0X1		(0x1u<<2)
#define	DCMIPP_P2FCTCR_FRATE_B_0X0			(0x0u<<0)
#define	DCMIPP_P2FCTCR_FRATE_B_0X1			(0x1u<<0)
#define	DCMIPP_P2FCTCR_FRATE_B_0X2			(0x2u<<0)
#define	DCMIPP_P2FCTCR_FRATE_B_0X3			(0x3u<<0)

// P2CRSTR Configuration

#define	DCMIPP_P2CRSTR_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2CRSTR_VSTART_0				(0x1u<<16)
#define	DCMIPP_P2CRSTR_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2CRSTR_HSTART_0				(0x1u<<0)

// P2CRSZR Configuration

#define	DCMIPP_P2CRSZR_ENABLE				(0x1u<<31)
#define	DCMIPP_P2CRSZR_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2CRSZR_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P2CRSZR_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2CRSZR_HSIZE_0				(0x1u<<0)

#define	DCMIPP_P2CRSZR_ENABLE_B_0X0			(0x0u<<31)
#define	DCMIPP_P2CRSZR_ENABLE_B_0X1			(0x1u<<31)

// P2DCCR Configuration

#define	DCMIPP_P2DCCR_VDEC					(0x3u<<3)
#define	DCMIPP_P2DCCR_VDEC_0				(0x1u<<3)
#define	DCMIPP_P2DCCR_HDEC					(0x3u<<1)
#define	DCMIPP_P2DCCR_HDEC_0				(0x1u<<1)
#define	DCMIPP_P2DCCR_ENABLE				(0x1u<<0)

#define	DCMIPP_P2DCCR_VDEC_B_0X0			(0x0u<<3)
#define	DCMIPP_P2DCCR_VDEC_B_0X1			(0x1u<<3)
#define	DCMIPP_P2DCCR_HDEC_B_0X0			(0x0u<<1)
#define	DCMIPP_P2DCCR_HDEC_B_0X1			(0x1u<<1)
#define	DCMIPP_P2DCCR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P2DCCR_ENABLE_B_0X1			(0x1u<<0)

// P2DSCR Configuration

#define	DCMIPP_P2DSCR_ENABLE				(0x1u<<31)
#define	DCMIPP_P2DSCR_VDIV					(0x3FFu<<16)
#define	DCMIPP_P2DSCR_VDIV_0				(0x1u<<16)
#define	DCMIPP_P2DSCR_HDIV					(0x3FFu<<0)
#define	DCMIPP_P2DSCR_HDIV_0				(0x1u<<0)

#define	DCMIPP_P2DSCR_ENABLE_B_0X0			(0x0u<<31)
#define	DCMIPP_P2DSCR_ENABLE_B_0X1			(0x1u<<31)

// P2DSRTIOR Configuration

#define	DCMIPP_P2DSRTIOR_VRATIO				(0xFFFFu<<16)
#define	DCMIPP_P2DSRTIOR_VRATIO_0			(0x1u<<16)
#define	DCMIPP_P2DSRTIOR_HRATIO				(0xFFFFu<<0)
#define	DCMIPP_P2DSRTIOR_HRATIO_0			(0x1u<<0)

// P2DSSZR Configuration

#define	DCMIPP_P2DSSZR_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2DSSZR_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P2DSSZR_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2DSSZR_HSIZE_0				(0x1u<<0)

// P2CMRICR Configuration

#define	DCMIPP_P2CMRICR_ROI8EN				(0x1u<<23)
#define	DCMIPP_P2CMRICR_ROI7EN				(0x1u<<22)
#define	DCMIPP_P2CMRICR_ROI6EN				(0x1u<<21)
#define	DCMIPP_P2CMRICR_ROI5EN				(0x1u<<20)
#define	DCMIPP_P2CMRICR_ROI4EN				(0x1u<<19)
#define	DCMIPP_P2CMRICR_ROI3EN				(0x1u<<18)
#define	DCMIPP_P2CMRICR_ROI2EN				(0x1u<<17)
#define	DCMIPP_P2CMRICR_ROI1EN				(0x1u<<16)
#define	DCMIPP_P2CMRICR_ROILSZ				(0x3u<<0)
#define	DCMIPP_P2CMRICR_ROILSZ_0			(0x1u<<0)

#define	DCMIPP_P2CMRICR_ROI8EN_B_0X0		(0x0u<<23)
#define	DCMIPP_P2CMRICR_ROI8EN_B_0X1		(0x1u<<23)
#define	DCMIPP_P2CMRICR_ROI7EN_B_0X0		(0x0u<<22)
#define	DCMIPP_P2CMRICR_ROI7EN_B_0X1		(0x1u<<22)
#define	DCMIPP_P2CMRICR_ROI6EN_B_0X0		(0x0u<<21)
#define	DCMIPP_P2CMRICR_ROI6EN_B_0X1		(0x1u<<21)
#define	DCMIPP_P2CMRICR_ROI5EN_B_0X0		(0x0u<<20)
#define	DCMIPP_P2CMRICR_ROI5EN_B_0X1		(0x1u<<20)
#define	DCMIPP_P2CMRICR_ROI4EN_B_0X0		(0x0u<<19)
#define	DCMIPP_P2CMRICR_ROI4EN_B_0X1		(0x1u<<19)
#define	DCMIPP_P2CMRICR_ROI3EN_B_0X0		(0x0u<<18)
#define	DCMIPP_P2CMRICR_ROI3EN_B_0X1		(0x1u<<18)
#define	DCMIPP_P2CMRICR_ROI2EN_B_0X0		(0x0u<<17)
#define	DCMIPP_P2CMRICR_ROI2EN_B_0X1		(0x1u<<17)
#define	DCMIPP_P2CMRICR_ROI1EN_B_0X0		(0x0u<<16)
#define	DCMIPP_P2CMRICR_ROI1EN_B_0X1		(0x1u<<16)
#define	DCMIPP_P2CMRICR_ROILSZ_B_0X0		(0x0u<<0)
#define	DCMIPP_P2CMRICR_ROILSZ_B_0X1		(0x1u<<0)
#define	DCMIPP_P2CMRICR_ROILSZ_B_0X2		(0x2u<<0)
#define	DCMIPP_P2CMRICR_ROILSZ_B_0X3		(0x3u<<0)

// P2RI1CR1 Configuration

#define	DCMIPP_P2RI1CR1_CLR					(0x3u<<28)
#define	DCMIPP_P2RI1CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2RI1CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2RI1CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2RI1CR1_CLG					(0x3u<<14)
#define	DCMIPP_P2RI1CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2RI1CR1_CLB					(0x3u<<12)
#define	DCMIPP_P2RI1CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2RI1CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2RI1CR1_HSTART_0			(0x1u<<0)

// P2RI1CR2 Configuration

#define	DCMIPP_P2RI1CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2RI1CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P2RI1CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2RI1CR2_HSIZE_0				(0x1u<<0)

// P2RI2CR1 Configuration

#define	DCMIPP_P2RI2CR1_CLR					(0x3u<<28)
#define	DCMIPP_P2RI2CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2RI2CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2RI2CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2RI2CR1_CLG					(0x3u<<14)
#define	DCMIPP_P2RI2CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2RI2CR1_CLB					(0x3u<<12)
#define	DCMIPP_P2RI2CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2RI2CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2RI2CR1_HSTART_0			(0x1u<<0)

// P2RI2CR2 Configuration

#define	DCMIPP_P2RI2CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2RI2CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P2RI2CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2RI2CR2_HSIZE_0				(0x1u<<0)

// P2RI3CR1 Configuration

#define	DCMIPP_P2RI3CR1_CLR					(0x3u<<28)
#define	DCMIPP_P2RI3CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2RI3CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2RI3CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2RI3CR1_CLG					(0x3u<<14)
#define	DCMIPP_P2RI3CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2RI3CR1_CLB					(0x3u<<12)
#define	DCMIPP_P2RI3CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2RI3CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2RI3CR1_HSTART_0			(0x1u<<0)

// P2RI3CR2 Configuration

#define	DCMIPP_P2RI3CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2RI3CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P2RI3CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2RI3CR2_HSIZE_0				(0x1u<<0)

// P2RI4CR1 Configuration

#define	DCMIPP_P2RI4CR1_CLR					(0x3u<<28)
#define	DCMIPP_P2RI4CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2RI4CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2RI4CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2RI4CR1_CLG					(0x3u<<14)
#define	DCMIPP_P2RI4CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2RI4CR1_CLB					(0x3u<<12)
#define	DCMIPP_P2RI4CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2RI4CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2RI4CR1_HSTART_0			(0x1u<<0)

// P2RI4CR2 Configuration

#define	DCMIPP_P2RI4CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2RI4CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P2RI4CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2RI4CR2_HSIZE_0				(0x1u<<0)

// P2RI5CR1 Configuration

#define	DCMIPP_P2RI5CR1_CLR					(0x3u<<28)
#define	DCMIPP_P2RI5CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2RI5CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2RI5CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2RI5CR1_CLG					(0x3u<<14)
#define	DCMIPP_P2RI5CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2RI5CR1_CLB					(0x3u<<12)
#define	DCMIPP_P2RI5CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2RI5CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2RI5CR1_HSTART_0			(0x1u<<0)

// P2RI5CR2 Configuration

#define	DCMIPP_P2RI5CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2RI5CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P2RI5CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2RI5CR2_HSIZE_0				(0x1u<<0)

// P2RI6CR1 Configuration

#define	DCMIPP_P2RI6CR1_CLR					(0x3u<<28)
#define	DCMIPP_P2RI6CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2RI6CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2RI6CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2RI6CR1_CLG					(0x3u<<14)
#define	DCMIPP_P2RI6CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2RI6CR1_CLB					(0x3u<<12)
#define	DCMIPP_P2RI6CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2RI6CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2RI6CR1_HSTART_0			(0x1u<<0)

// P2RI6CR2 Configuration

#define	DCMIPP_P2RI6CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2RI6CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P2RI6CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2RI6CR2_HSIZE_0				(0x1u<<0)

// P2RI7CR1 Configuration

#define	DCMIPP_P2RI7CR1_CLR					(0x3u<<28)
#define	DCMIPP_P2RI7CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2RI7CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2RI7CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2RI7CR1_CLG					(0x3u<<14)
#define	DCMIPP_P2RI7CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2RI7CR1_CLB					(0x3u<<12)
#define	DCMIPP_P2RI7CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2RI7CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2RI7CR1_HSTART_0			(0x1u<<0)

// P2RI7CR2 Configuration

#define	DCMIPP_P2RI7CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2RI7CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P2RI7CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2RI7CR2_HSIZE_0				(0x1u<<0)

// P2RI8CR1 Configuration

#define	DCMIPP_P2RI8CR1_CLR					(0x3u<<28)
#define	DCMIPP_P2RI8CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2RI8CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2RI8CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2RI8CR1_CLG					(0x3u<<14)
#define	DCMIPP_P2RI8CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2RI8CR1_CLB					(0x3u<<12)
#define	DCMIPP_P2RI8CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2RI8CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2RI8CR1_HSTART_0			(0x1u<<0)

// P2RI8CR2 Configuration

#define	DCMIPP_P2RI8CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2RI8CR2_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P2RI8CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2RI8CR2_HSIZE_0				(0x1u<<0)

// P2GMCR Configuration

#define	DCMIPP_P2GMCR_ENABLE				(0x1u<<0)

#define	DCMIPP_P2GMCR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P2GMCR_ENABLE_B_0X1			(0x1u<<0)

// P2PPCR Configuration

#define	DCMIPP_P2PPCR_LMAWE					(0x1u<<20)
#define	DCMIPP_P2PPCR_LMAWM					(0x7u<<17)
#define	DCMIPP_P2PPCR_LMAWM_0				(0x1u<<17)
#define	DCMIPP_P2PPCR_DBM					(0x1u<<16)
#define	DCMIPP_P2PPCR_LINEMULT				(0x7u<<13)
#define	DCMIPP_P2PPCR_LINEMULT_0			(0x1u<<13)
#define	DCMIPP_P2PPCR_SWAPRB				(0x1u<<4)
#define	DCMIPP_P2PPCR_FORMAT				(0xFu<<0)
#define	DCMIPP_P2PPCR_FORMAT_0				(0x1u<<0)

#define	DCMIPP_P2PPCR_LMAWE_B_0X0			(0x0u<<20)
#define	DCMIPP_P2PPCR_LMAWE_B_0X1			(0x1u<<20)
#define	DCMIPP_P2PPCR_LMAWM_B_0X0			(0x0u<<17)
#define	DCMIPP_P2PPCR_LMAWM_B_0X1			(0x1u<<17)
#define	DCMIPP_P2PPCR_LMAWM_B_0X2			(0x2u<<17)
#define	DCMIPP_P2PPCR_LMAWM_B_0X3			(0x3u<<17)
#define	DCMIPP_P2PPCR_LMAWM_B_0X4			(0x4u<<17)
#define	DCMIPP_P2PPCR_LMAWM_B_0X5			(0x5u<<17)
#define	DCMIPP_P2PPCR_LMAWM_B_0X6			(0x6u<<17)
#define	DCMIPP_P2PPCR_LMAWM_B_0X7			(0x7u<<17)
#define	DCMIPP_P2PPCR_DBM_B_0X0				(0x0u<<16)
#define	DCMIPP_P2PPCR_DBM_B_0X1				(0x1u<<16)
#define	DCMIPP_P2PPCR_LINEMULT_B_0X0		(0x0u<<13)
#define	DCMIPP_P2PPCR_LINEMULT_B_0X1		(0x1u<<13)
#define	DCMIPP_P2PPCR_LINEMULT_B_0X2		(0x2u<<13)
#define	DCMIPP_P2PPCR_LINEMULT_B_0X3		(0x3u<<13)
#define	DCMIPP_P2PPCR_LINEMULT_B_0X4		(0x4u<<13)
#define	DCMIPP_P2PPCR_LINEMULT_B_0X5		(0x5u<<13)
#define	DCMIPP_P2PPCR_LINEMULT_B_0X6		(0x6u<<13)
#define	DCMIPP_P2PPCR_LINEMULT_B_0X7		(0x7u<<13)
#define	DCMIPP_P2PPCR_SWAPRB_B_0X0			(0x0u<<4)
#define	DCMIPP_P2PPCR_SWAPRB_B_0X1			(0x1u<<4)
#define	DCMIPP_P2PPCR_FORMAT_B_0X0			(0x0u<<0)
#define	DCMIPP_P2PPCR_FORMAT_B_0X1			(0x1u<<0)
#define	DCMIPP_P2PPCR_FORMAT_B_0X2			(0x2u<<0)
#define	DCMIPP_P2PPCR_FORMAT_B_0X3			(0x3u<<0)
#define	DCMIPP_P2PPCR_FORMAT_B_0X4			(0x4u<<0)
#define	DCMIPP_P2PPCR_FORMAT_B_0X5			(0x5u<<0)
#define	DCMIPP_P2PPCR_FORMAT_B_0X6			(0x6u<<0)

// P2PPM0AR1 Configuration

#define	DCMIPP_P2PPM0AR1_M0A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P2PPM0AR1_M0A_0				(0x1u<<0)

// P2PPM0AR2 Configuration

#define	DCMIPP_P2PPM0AR2_M0A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P2PPM0AR2_M0A_0				(0x1u<<0)

// P2PPM0PR Configuration

#define	DCMIPP_P2PPM0PR_PITCH				(0x7FFFu<<0)
#define	DCMIPP_P2PPM0PR_PITCH_0				(0x1u<<0)

// P2STM0AR Configuration

#define	DCMIPP_P2STM0AR_M0A					(0xFFFFFFFFu<<0)
#define	DCMIPP_P2STM0AR_M0A_0				(0x1u<<0)

// P2IER Configuration

#define	DCMIPP_P2IER_OVRIE					(0x1u<<7)
#define	DCMIPP_P2IER_VSYNCIE				(0x1u<<2)
#define	DCMIPP_P2IER_FRAMEIE				(0x1u<<1)
#define	DCMIPP_P2IER_LINEIE					(0x1u<<0)

#define	DCMIPP_P2IER_OVRIE_B_0X0			(0x0u<<7)
#define	DCMIPP_P2IER_OVRIE_B_0X1			(0x1u<<7)
#define	DCMIPP_P2IER_VSYNCIE_B_0X0			(0x0u<<2)
#define	DCMIPP_P2IER_VSYNCIE_B_0X1			(0x1u<<2)
#define	DCMIPP_P2IER_FRAMEIE_B_0X0			(0x0u<<1)
#define	DCMIPP_P2IER_FRAMEIE_B_0X1			(0x1u<<1)
#define	DCMIPP_P2IER_LINEIE_B_0X0			(0x0u<<0)
#define	DCMIPP_P2IER_LINEIE_B_0X1			(0x1u<<0)

// P2SR Configuration

#define	DCMIPP_P2SR_CPTACT					(0x1u<<23)
#define	DCMIPP_P2SR_LSTFRM					(0x1u<<17)
#define	DCMIPP_P2SR_LSTLINE					(0x1u<<16)
#define	DCMIPP_P2SR_OVRF					(0x1u<<7)
#define	DCMIPP_P2SR_VSYNCF					(0x1u<<2)
#define	DCMIPP_P2SR_FRAMEF					(0x1u<<1)
#define	DCMIPP_P2SR_LINEF					(0x1u<<0)

#define	DCMIPP_P2SR_CPTACT_B_0X0			(0x0u<<23)
#define	DCMIPP_P2SR_CPTACT_B_0X1			(0x1u<<23)
#define	DCMIPP_P2SR_OVRF_B_0X0				(0x0u<<7)
#define	DCMIPP_P2SR_OVRF_B_0X1				(0x1u<<7)
#define	DCMIPP_P2SR_FRAMEF_B_0X0			(0x0u<<1)
#define	DCMIPP_P2SR_FRAMEF_B_0X1			(0x1u<<1)

// P2FCR Configuration

#define	DCMIPP_P2FCR_COVRF					(0x1u<<7)
#define	DCMIPP_P2FCR_CVSYNCF				(0x1u<<2)
#define	DCMIPP_P2FCR_CFRAMEF				(0x1u<<1)
#define	DCMIPP_P2FCR_CLINEF					(0x1u<<0)

// P2CFSCR Configuration

#define	DCMIPP_P2CFSCR_PIPEN				(0x1u<<31)
#define	DCMIPP_P2CFSCR_FDTFEN				(0x1u<<30)
#define	DCMIPP_P2CFSCR_FDTF					(0x3Fu<<24)
#define	DCMIPP_P2CFSCR_FDTF_0				(0x1u<<24)
#define	DCMIPP_P2CFSCR_VC					(0x3u<<19)
#define	DCMIPP_P2CFSCR_VC_0					(0x1u<<19)
#define	DCMIPP_P2CFSCR_DTIDA				(0x3Fu<<0)
#define	DCMIPP_P2CFSCR_DTIDA_0				(0x1u<<0)

#define	DCMIPP_P2CFSCR_PIPEN_B_0X0			(0x0u<<31)
#define	DCMIPP_P2CFSCR_PIPEN_B_0X1			(0x1u<<31)
#define	DCMIPP_P2CFSCR_FDTFEN_B_0X0			(0x0u<<30)
#define	DCMIPP_P2CFSCR_FDTFEN_B_0X1			(0x1u<<30)

// P2CFCTCR Configuration

#define	DCMIPP_P2CFCTCR_CPTREQ				(0x1u<<3)
#define	DCMIPP_P2CFCTCR_CPTMODE				(0x1u<<2)
#define	DCMIPP_P2CFCTCR_FRATE				(0x3u<<0)
#define	DCMIPP_P2CFCTCR_FRATE_0				(0x1u<<0)

#define	DCMIPP_P2CFCTCR_CPTREQ_B_0X0		(0x0u<<3)
#define	DCMIPP_P2CFCTCR_CPTREQ_B_0X1		(0x1u<<3)
#define	DCMIPP_P2CFCTCR_CPTMODE_B_0X0		(0x0u<<2)
#define	DCMIPP_P2CFCTCR_CPTMODE_B_0X1		(0x1u<<2)
#define	DCMIPP_P2CFCTCR_FRATE_B_0X0			(0x0u<<0)
#define	DCMIPP_P2CFCTCR_FRATE_B_0X1			(0x1u<<0)
#define	DCMIPP_P2CFCTCR_FRATE_B_0X2			(0x2u<<0)
#define	DCMIPP_P2CFCTCR_FRATE_B_0X3			(0x3u<<0)

// P2CCRSTR Configuration

#define	DCMIPP_P2CCRSTR_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2CCRSTR_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2CCRSTR_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2CCRSTR_HSTART_0			(0x1u<<0)

// P2CCRSZR Configuration

#define	DCMIPP_P2CCRSZR_ENABLE				(0x1u<<31)
#define	DCMIPP_P2CCRSZR_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2CCRSZR_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P2CCRSZR_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2CCRSZR_HSIZE_0				(0x1u<<0)

#define	DCMIPP_P2CCRSZR_ENABLE_B_0X0		(0x0u<<31)
#define	DCMIPP_P2CCRSZR_ENABLE_B_0X1		(0x1u<<31)

// P2CDCCR Configuration

#define	DCMIPP_P2CDCCR_VDEC					(0x3u<<3)
#define	DCMIPP_P2CDCCR_VDEC_0				(0x1u<<3)
#define	DCMIPP_P2CDCCR_HDEC					(0x3u<<1)
#define	DCMIPP_P2CDCCR_HDEC_0				(0x1u<<1)
#define	DCMIPP_P2CDCCR_ENABLE				(0x1u<<0)

#define	DCMIPP_P2CDCCR_VDEC_B_0X0			(0x0u<<3)
#define	DCMIPP_P2CDCCR_VDEC_B_0X1			(0x1u<<3)
#define	DCMIPP_P2CDCCR_HDEC_B_0X0			(0x0u<<1)
#define	DCMIPP_P2CDCCR_HDEC_B_0X1			(0x1u<<1)
#define	DCMIPP_P2CDCCR_ENABLE_B_0X0			(0x0u<<0)
#define	DCMIPP_P2CDCCR_ENABLE_B_0X1			(0x1u<<0)

// P2CDSCR Configuration

#define	DCMIPP_P2CDSCR_ENABLE				(0x1u<<31)
#define	DCMIPP_P2CDSCR_VDIV					(0x3FFu<<16)
#define	DCMIPP_P2CDSCR_VDIV_0				(0x1u<<16)
#define	DCMIPP_P2CDSCR_HDIV					(0x3FFu<<0)
#define	DCMIPP_P2CDSCR_HDIV_0				(0x1u<<0)

#define	DCMIPP_P2CDSCR_ENABLE_B_0X0			(0x0u<<31)
#define	DCMIPP_P2CDSCR_ENABLE_B_0X1			(0x1u<<31)

// P2CDSRTIOR Configuration

#define	DCMIPP_P2CDSRTIOR_VRATIO			(0xFFFFu<<16)
#define	DCMIPP_P2CDSRTIOR_VRATIO_0			(0x1u<<16)
#define	DCMIPP_P2CDSRTIOR_HRATIO			(0xFFFFu<<0)
#define	DCMIPP_P2CDSRTIOR_HRATIO_0			(0x1u<<0)

// P2CDSSZR Configuration

#define	DCMIPP_P2CDSSZR_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2CDSSZR_VSIZE_0				(0x1u<<16)
#define	DCMIPP_P2CDSSZR_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2CDSSZR_HSIZE_0				(0x1u<<0)

// P2CCMRICR Configuration

#define	DCMIPP_P2CCMRICR_ROI8EN				(0x1u<<23)
#define	DCMIPP_P2CCMRICR_ROI7EN				(0x1u<<22)
#define	DCMIPP_P2CCMRICR_ROI6EN				(0x1u<<21)
#define	DCMIPP_P2CCMRICR_ROI5EN				(0x1u<<20)
#define	DCMIPP_P2CCMRICR_ROI4EN				(0x1u<<19)
#define	DCMIPP_P2CCMRICR_ROI3EN				(0x1u<<18)
#define	DCMIPP_P2CCMRICR_ROI2EN				(0x1u<<17)
#define	DCMIPP_P2CCMRICR_ROI1EN				(0x1u<<16)
#define	DCMIPP_P2CCMRICR_ROILSZ				(0x3u<<0)
#define	DCMIPP_P2CCMRICR_ROILSZ_0			(0x1u<<0)

#define	DCMIPP_P2CCMRICR_ROI8EN_B_0X0		(0x0u<<23)
#define	DCMIPP_P2CCMRICR_ROI8EN_B_0X1		(0x1u<<23)
#define	DCMIPP_P2CCMRICR_ROI7EN_B_0X0		(0x0u<<22)
#define	DCMIPP_P2CCMRICR_ROI7EN_B_0X1		(0x1u<<22)
#define	DCMIPP_P2CCMRICR_ROI6EN_B_0X0		(0x0u<<21)
#define	DCMIPP_P2CCMRICR_ROI6EN_B_0X1		(0x1u<<21)
#define	DCMIPP_P2CCMRICR_ROI5EN_B_0X0		(0x0u<<20)
#define	DCMIPP_P2CCMRICR_ROI5EN_B_0X1		(0x1u<<20)
#define	DCMIPP_P2CCMRICR_ROI4EN_B_0X0		(0x0u<<19)
#define	DCMIPP_P2CCMRICR_ROI4EN_B_0X1		(0x1u<<19)
#define	DCMIPP_P2CCMRICR_ROI3EN_B_0X0		(0x0u<<18)
#define	DCMIPP_P2CCMRICR_ROI3EN_B_0X1		(0x1u<<18)
#define	DCMIPP_P2CCMRICR_ROI2EN_B_0X0		(0x0u<<17)
#define	DCMIPP_P2CCMRICR_ROI2EN_B_0X1		(0x1u<<17)
#define	DCMIPP_P2CCMRICR_ROI1EN_B_0X0		(0x0u<<16)
#define	DCMIPP_P2CCMRICR_ROI1EN_B_0X1		(0x1u<<16)
#define	DCMIPP_P2CCMRICR_ROILSZ_B_0X0		(0x0u<<0)
#define	DCMIPP_P2CCMRICR_ROILSZ_B_0X1		(0x1u<<0)
#define	DCMIPP_P2CCMRICR_ROILSZ_B_0X2		(0x2u<<0)
#define	DCMIPP_P2CCMRICR_ROILSZ_B_0X3		(0x3u<<0)

// P2CRI1CR1 Configuration

#define	DCMIPP_P2CRI1CR1_CLR				(0x3u<<28)
#define	DCMIPP_P2CRI1CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2CRI1CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2CRI1CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2CRI1CR1_CLG				(0x3u<<14)
#define	DCMIPP_P2CRI1CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2CRI1CR1_CLB				(0x3u<<12)
#define	DCMIPP_P2CRI1CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2CRI1CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2CRI1CR1_HSTART_0			(0x1u<<0)

// P2CRI1CR2 Configuration

#define	DCMIPP_P2CRI1CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2CRI1CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P2CRI1CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2CRI1CR2_HSIZE_0			(0x1u<<0)

// P2CRI2CR1 Configuration

#define	DCMIPP_P2CRI2CR1_CLR				(0x3u<<28)
#define	DCMIPP_P2CRI2CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2CRI2CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2CRI2CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2CRI2CR1_CLG				(0x3u<<14)
#define	DCMIPP_P2CRI2CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2CRI2CR1_CLB				(0x3u<<12)
#define	DCMIPP_P2CRI2CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2CRI2CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2CRI2CR1_HSTART_0			(0x1u<<0)

// P2CRI2CR2 Configuration

#define	DCMIPP_P2CRI2CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2CRI2CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P2CRI2CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2CRI2CR2_HSIZE_0			(0x1u<<0)

// P2CRI3CR1 Configuration

#define	DCMIPP_P2CRI3CR1_CLR				(0x3u<<28)
#define	DCMIPP_P2CRI3CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2CRI3CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2CRI3CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2CRI3CR1_CLG				(0x3u<<14)
#define	DCMIPP_P2CRI3CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2CRI3CR1_CLB				(0x3u<<12)
#define	DCMIPP_P2CRI3CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2CRI3CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2CRI3CR1_HSTART_0			(0x1u<<0)

// P2CRI3CR2 Configuration

#define	DCMIPP_P2CRI3CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2CRI3CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P2CRI3CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2CRI3CR2_HSIZE_0			(0x1u<<0)

// P2CRI4CR1 Configuration

#define	DCMIPP_P2CRI4CR1_CLR				(0x3u<<28)
#define	DCMIPP_P2CRI4CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2CRI4CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2CRI4CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2CRI4CR1_CLG				(0x3u<<14)
#define	DCMIPP_P2CRI4CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2CRI4CR1_CLB				(0x3u<<12)
#define	DCMIPP_P2CRI4CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2CRI4CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2CRI4CR1_HSTART_0			(0x1u<<0)

// P2CRI4CR2 Configuration

#define	DCMIPP_P2CRI4CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2CRI4CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P2CRI4CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2CRI4CR2_HSIZE_0			(0x1u<<0)

// P2CRI5CR1 Configuration

#define	DCMIPP_P2CRI5CR1_CLR				(0x3u<<28)
#define	DCMIPP_P2CRI5CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2CRI5CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2CRI5CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2CRI5CR1_CLG				(0x3u<<14)
#define	DCMIPP_P2CRI5CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2CRI5CR1_CLB				(0x3u<<12)
#define	DCMIPP_P2CRI5CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2CRI5CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2CRI5CR1_HSTART_0			(0x1u<<0)

// P2CRI5CR2 Configuration

#define	DCMIPP_P2CRI5CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2CRI5CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P2CRI5CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2CRI5CR2_HSIZE_0			(0x1u<<0)

// P2CRI6CR1 Configuration

#define	DCMIPP_P2CRI6CR1_CLR				(0x3u<<28)
#define	DCMIPP_P2CRI6CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2CRI6CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2CRI6CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2CRI6CR1_CLG				(0x3u<<14)
#define	DCMIPP_P2CRI6CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2CRI6CR1_CLB				(0x3u<<12)
#define	DCMIPP_P2CRI6CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2CRI6CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2CRI6CR1_HSTART_0			(0x1u<<0)

// P2CRI6CR2 Configuration

#define	DCMIPP_P2CRI6CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2CRI6CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P2CRI6CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2CRI6CR2_HSIZE_0			(0x1u<<0)

// P2CRI7CR1 Configuration

#define	DCMIPP_P2CRI7CR1_CLR				(0x3u<<28)
#define	DCMIPP_P2CRI7CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2CRI7CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2CRI7CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2CRI7CR1_CLG				(0x3u<<14)
#define	DCMIPP_P2CRI7CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2CRI7CR1_CLB				(0x3u<<12)
#define	DCMIPP_P2CRI7CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2CRI7CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2CRI7CR1_HSTART_0			(0x1u<<0)

// P2CRI7CR2 Configuration

#define	DCMIPP_P2CRI7CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2CRI7CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P2CRI7CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2CRI7CR2_HSIZE_0			(0x1u<<0)

// P2CRI8CR1 Configuration

#define	DCMIPP_P2CRI8CR1_CLR				(0x3u<<28)
#define	DCMIPP_P2CRI8CR1_CLR_0				(0x1u<<28)
#define	DCMIPP_P2CRI8CR1_VSTART				(0xFFFu<<16)
#define	DCMIPP_P2CRI8CR1_VSTART_0			(0x1u<<16)
#define	DCMIPP_P2CRI8CR1_CLG				(0x3u<<14)
#define	DCMIPP_P2CRI8CR1_CLG_0				(0x1u<<14)
#define	DCMIPP_P2CRI8CR1_CLB				(0x3u<<12)
#define	DCMIPP_P2CRI8CR1_CLB_0				(0x1u<<12)
#define	DCMIPP_P2CRI8CR1_HSTART				(0xFFFu<<0)
#define	DCMIPP_P2CRI8CR1_HSTART_0			(0x1u<<0)

// P2CRI8CR2 Configuration

#define	DCMIPP_P2CRI8CR2_VSIZE				(0xFFFu<<16)
#define	DCMIPP_P2CRI8CR2_VSIZE_0			(0x1u<<16)
#define	DCMIPP_P2CRI8CR2_HSIZE				(0xFFFu<<0)
#define	DCMIPP_P2CRI8CR2_HSIZE_0			(0x1u<<0)

// P2CPPCR Configuration

#define	DCMIPP_P2CPPCR_LMAWE				(0x1u<<20)
#define	DCMIPP_P2CPPCR_LMAWM				(0x7u<<17)
#define	DCMIPP_P2CPPCR_LMAWM_0				(0x1u<<17)
#define	DCMIPP_P2CPPCR_DBM					(0x1u<<16)
#define	DCMIPP_P2CPPCR_LINEMULT				(0x7u<<13)
#define	DCMIPP_P2CPPCR_LINEMULT_0			(0x1u<<13)
#define	DCMIPP_P2CPPCR_SWAPRB				(0x1u<<4)
#define	DCMIPP_P2CPPCR_FORMAT				(0xFu<<0)
#define	DCMIPP_P2CPPCR_FORMAT_0				(0x1u<<0)

#define	DCMIPP_P2CPPCR_LMAWE_B_0X0			(0x0u<<20)
#define	DCMIPP_P2CPPCR_LMAWE_B_0X1			(0x1u<<20)
#define	DCMIPP_P2CPPCR_LMAWM_B_0X0			(0x0u<<17)
#define	DCMIPP_P2CPPCR_LMAWM_B_0X1			(0x1u<<17)
#define	DCMIPP_P2CPPCR_LMAWM_B_0X2			(0x2u<<17)
#define	DCMIPP_P2CPPCR_LMAWM_B_0X3			(0x3u<<17)
#define	DCMIPP_P2CPPCR_LMAWM_B_0X4			(0x4u<<17)
#define	DCMIPP_P2CPPCR_LMAWM_B_0X5			(0x5u<<17)
#define	DCMIPP_P2CPPCR_LMAWM_B_0X6			(0x6u<<17)
#define	DCMIPP_P2CPPCR_LMAWM_B_0X7			(0x7u<<17)
#define	DCMIPP_P2CPPCR_DBM_B_0X0			(0x0u<<16)
#define	DCMIPP_P2CPPCR_DBM_B_0X1			(0x1u<<16)
#define	DCMIPP_P2CPPCR_LINEMULT_B_0X0		(0x0u<<13)
#define	DCMIPP_P2CPPCR_LINEMULT_B_0X1		(0x1u<<13)
#define	DCMIPP_P2CPPCR_LINEMULT_B_0X2		(0x2u<<13)
#define	DCMIPP_P2CPPCR_LINEMULT_B_0X3		(0x3u<<13)
#define	DCMIPP_P2CPPCR_LINEMULT_B_0X4		(0x4u<<13)
#define	DCMIPP_P2CPPCR_LINEMULT_B_0X5		(0x5u<<13)
#define	DCMIPP_P2CPPCR_LINEMULT_B_0X6		(0x6u<<13)
#define	DCMIPP_P2CPPCR_LINEMULT_B_0X7		(0x7u<<13)
#define	DCMIPP_P2CPPCR_SWAPRB_B_0X0			(0x0u<<4)
#define	DCMIPP_P2CPPCR_SWAPRB_B_0X1			(0x1u<<4)
#define	DCMIPP_P2CPPCR_FORMAT_B_0X0			(0x0u<<0)
#define	DCMIPP_P2CPPCR_FORMAT_B_0X1			(0x1u<<0)
#define	DCMIPP_P2CPPCR_FORMAT_B_0X2			(0x2u<<0)
#define	DCMIPP_P2CPPCR_FORMAT_B_0X3			(0x3u<<0)
#define	DCMIPP_P2CPPCR_FORMAT_B_0X4			(0x4u<<0)
#define	DCMIPP_P2CPPCR_FORMAT_B_0X5			(0x5u<<0)
#define	DCMIPP_P2CPPCR_FORMAT_B_0X6			(0x6u<<0)

// P2CPPM0AR1 Configuration

#define	DCMIPP_P2CPPM0AR1_M0A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P2CPPM0AR1_M0A_0				(0x1u<<0)

// P2CPPM0AR2 Configuration

#define	DCMIPP_P2CPPM0AR2_M0A				(0xFFFFFFFFu<<0)
#define	DCMIPP_P2CPPM0AR2_M0A_0				(0x1u<<0)
