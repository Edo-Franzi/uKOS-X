/*
; stm32N657_i3c.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_i3c equates.
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

// I3C address definitions
// -----------------------

typedef struct {
		union {
	volatile	uint32_t	CR;
	volatile	uint32_t	CR_ALTERNATE;
		};
	volatile	uint32_t	CFGR;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	RDR;
	volatile	uint32_t	RDWR;
	volatile	uint32_t	TDR;
	volatile	uint32_t	TDWR;
	volatile	uint32_t	IBIDR;
	volatile	uint32_t	TGTTDR;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	SR;
	volatile	uint32_t	SER;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	RMR;
	volatile	uint32_t	RESERVED3[3];
	volatile	uint32_t	EVR;
	volatile	uint32_t	IER;
	volatile	uint32_t	CEVR;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	DEVR0;
	volatile	uint32_t	DEVR1;
	volatile	uint32_t	DEVR2;
	volatile	uint32_t	DEVR3;
	volatile	uint32_t	DEVR4;
	volatile	uint32_t	RESERVED5[7];
	volatile	uint32_t	MAXRLR;
	volatile	uint32_t	MAXWLR;
	volatile	uint32_t	RESERVED6[2];
	volatile	uint32_t	TIMINGR0;
	volatile	uint32_t	TIMINGR1;
	volatile	uint32_t	TIMINGR2;
	volatile	uint32_t	RESERVED7[5];
	volatile	uint32_t	BCR;
	volatile	uint32_t	DCR;
	volatile	uint32_t	GETCAPR;
	volatile	uint32_t	CRCAPR;
	volatile	uint32_t	GETMXDSR;
	volatile	uint32_t	EPIDR;
} I3C_TypeDef;

#if (defined(__cplusplus))
#define	I3C1_NS	reinterpret_cast<I3C_TypeDef *>(0x40006000u)
#define	I3C1_S	reinterpret_cast<I3C_TypeDef *>(0x50006000u)
#define	I3C2_NS	reinterpret_cast<I3C_TypeDef *>(0x40006400u)
#define	I3C2_S	reinterpret_cast<I3C_TypeDef *>(0x50006400u)

#else
#define	I3C1_NS	((I3C_TypeDef *)0x40006000u)
#define	I3C1_S	((I3C_TypeDef *)0x50006000u)
#define	I3C2_NS	((I3C_TypeDef *)0x40006400u)
#define	I3C2_S	((I3C_TypeDef *)0x50006400u)
#endif

// CR Configuration

#define	I3C_CR_MEND														(0x1u<<31)
#define	I3C_CR_MTYPE													(0xFu<<27)
#define	I3C_CR_MTYPE_0													(0x1u<<27)
#define	I3C_CR_ADD														(0x7Fu<<17)
#define	I3C_CR_ADD_0													(0x1u<<17)
#define	I3C_CR_RNW														(0x1u<<16)
#define	I3C_CR_DCNT														(0xFFFFu<<0)
#define	I3C_CR_DCNT_0													(0x1u<<0)

#define	I3C_CR_MEND_B_0X0												(0x0u<<31)
#define	I3C_CR_MEND_B_0X1												(0x1u<<31)
#define	I3C_CR_MTYPE_B_0X0_WHEN_I3C_ACTS_AS_I3C_CONTROLLER				(0x0u<<27)
#define	I3C_CR_MTYPE_B_0X1_WHEN_I3C_ACTS_AS_I3C_CONTROLLER				(0x1u<<27)
#define	I3C_CR_MTYPE_B_0X2_WHEN_I3C_ACTS_AS_I3C_CONTROLLER				(0x2u<<27)
#define	I3C_CR_MTYPE_B_0X3_WHEN_I3C_ACTS_AS_I3C_CONTROLLER				(0x3u<<27)
#define	I3C_CR_MTYPE_B_0X4_WHEN_I3C_ACTS_AS_I3C_CONTROLLER				(0x4u<<27)
#define	I3C_CR_MTYPE_B_0X8_WHEN_I3C_ACTS_AS_I3C_TARGET					(0x8u<<27)
#define	I3C_CR_MTYPE_B_0X9_WHEN_I3C_ACTS_AS_I3C_TARGET					(0x9u<<27)
#define	I3C_CR_MTYPE_B_0XA_WHEN_I3C_ACTS_AS_I3C_TARGET					(0xAu<<27)
#define	I3C_CR_RNW_B_0X0												(0x0u<<16)
#define	I3C_CR_RNW_B_0X1												(0x1u<<16)
#define	I3C_CR_DCNT_B_0X0000											(0x0u<<0)
#define	I3C_CR_DCNT_B_0X0001											(0x1u<<0)
#define	I3C_CR_DCNT_B_0X0002											(0x2u<<0)
#define	I3C_CR_DCNT_B_0XFFFF											(0xFFFFu<<0)

// CR_ALTERNATE Configuration

#define	I3C_CR_ALTERNATE_MEND											(0x1u<<31)
#define	I3C_CR_ALTERNATE_MTYPE											(0xFu<<27)
#define	I3C_CR_ALTERNATE_MTYPE_0										(0x1u<<27)
#define	I3C_CR_ALTERNATE_CCC											(0xFFu<<16)
#define	I3C_CR_ALTERNATE_CCC_0											(0x1u<<16)
#define	I3C_CR_ALTERNATE_DCNT											(0xFFFFu<<0)
#define	I3C_CR_ALTERNATE_DCNT_0											(0x1u<<0)

#define	I3C_CR_ALTERNATE_MEND_B_0X0										(0x0u<<31)
#define	I3C_CR_ALTERNATE_MEND_B_0X1										(0x1u<<31)
#define	I3C_CR_ALTERNATE_MTYPE_B_0X6_WHEN_I3C_ACTS_AS_I3C_CONTROLLER	(0x6u<<27)
#define	I3C_CR_ALTERNATE_DCNT_B_0X0000									(0x0u<<0)
#define	I3C_CR_ALTERNATE_DCNT_B_0X0001									(0x1u<<0)
#define	I3C_CR_ALTERNATE_DCNT_B_0X0002									(0x2u<<0)
#define	I3C_CR_ALTERNATE_DCNT_B_0XFFFF									(0xFFFFu<<0)

// CFGR Configuration

#define	I3C_CFGR_TSFSET													(0x1u<<30)
#define	I3C_CFGR_CFLUSH													(0x1u<<21)
#define	I3C_CFGR_CDMAEN													(0x1u<<20)
#define	I3C_CFGR_TMODE													(0x1u<<19)
#define	I3C_CFGR_SMODE													(0x1u<<18)
#define	I3C_CFGR_SFLUSH													(0x1u<<17)
#define	I3C_CFGR_SDMAEN													(0x1u<<16)
#define	I3C_CFGR_TXTHRES												(0x1u<<14)
#define	I3C_CFGR_TXFLUSH												(0x1u<<13)
#define	I3C_CFGR_TXDMAEN												(0x1u<<12)
#define	I3C_CFGR_RXTHRES												(0x1u<<10)
#define	I3C_CFGR_RXFLUSH												(0x1u<<9)
#define	I3C_CFGR_RXDMAEN												(0x1u<<8)
#define	I3C_CFGR_HJACK													(0x1u<<7)
#define	I3C_CFGR_HKSDAEN												(0x1u<<5)
#define	I3C_CFGR_EXITPTRN												(0x1u<<4)
#define	I3C_CFGR_RSTPTRN												(0x1u<<3)
#define	I3C_CFGR_NOARBH													(0x1u<<2)
#define	I3C_CFGR_CRINIT													(0x1u<<1)
#define	I3C_CFGR_EN														(0x1u<<0)

#define	I3C_CFGR_TSFSET_B_0X0											(0x0u<<30)
#define	I3C_CFGR_TSFSET_B_0X1											(0x1u<<30)
#define	I3C_CFGR_CFLUSH_B_0X0											(0x0u<<21)
#define	I3C_CFGR_CFLUSH_B_0X1											(0x1u<<21)
#define	I3C_CFGR_CDMAEN_B_0X0											(0x0u<<20)
#define	I3C_CFGR_CDMAEN_B_0X1											(0x1u<<20)
#define	I3C_CFGR_TMODE_B_0X0											(0x0u<<19)
#define	I3C_CFGR_TMODE_B_0X1											(0x1u<<19)
#define	I3C_CFGR_SMODE_B_0X0											(0x0u<<18)
#define	I3C_CFGR_SMODE_B_0X1											(0x1u<<18)
#define	I3C_CFGR_SFLUSH_B_0X0											(0x0u<<17)
#define	I3C_CFGR_SFLUSH_B_0X1											(0x1u<<17)
#define	I3C_CFGR_SDMAEN_B_0X0											(0x0u<<16)
#define	I3C_CFGR_SDMAEN_B_0X1											(0x1u<<16)
#define	I3C_CFGR_TXTHRES_B_0X0											(0x0u<<14)
#define	I3C_CFGR_TXTHRES_B_0X1											(0x1u<<14)
#define	I3C_CFGR_TXFLUSH_B_0X0											(0x0u<<13)
#define	I3C_CFGR_TXFLUSH_B_0X1											(0x1u<<13)
#define	I3C_CFGR_TXDMAEN_B_0X0											(0x0u<<12)
#define	I3C_CFGR_TXDMAEN_B_0X1											(0x1u<<12)
#define	I3C_CFGR_RXTHRES_B_0X0											(0x0u<<10)
#define	I3C_CFGR_RXTHRES_B_0X1											(0x1u<<10)
#define	I3C_CFGR_RXFLUSH_B_0X0											(0x0u<<9)
#define	I3C_CFGR_RXFLUSH_B_0X1											(0x1u<<9)
#define	I3C_CFGR_RXDMAEN_B_0X0											(0x0u<<8)
#define	I3C_CFGR_RXDMAEN_B_0X1											(0x1u<<8)
#define	I3C_CFGR_HJACK_B_0X0											(0x0u<<7)
#define	I3C_CFGR_HJACK_B_0X1											(0x1u<<7)
#define	I3C_CFGR_HKSDAEN_B_0X0											(0x0u<<5)
#define	I3C_CFGR_HKSDAEN_B_0X1											(0x1u<<5)
#define	I3C_CFGR_EXITPTRN_B_0X0											(0x0u<<4)
#define	I3C_CFGR_EXITPTRN_B_0X1											(0x1u<<4)
#define	I3C_CFGR_RSTPTRN_B_0X0											(0x0u<<3)
#define	I3C_CFGR_RSTPTRN_B_0X1											(0x1u<<3)
#define	I3C_CFGR_NOARBH_B_0X0											(0x0u<<2)
#define	I3C_CFGR_NOARBH_B_0X1											(0x1u<<2)
#define	I3C_CFGR_CRINIT_B_0X0											(0x0u<<1)
#define	I3C_CFGR_CRINIT_B_0X1											(0x1u<<1)
#define	I3C_CFGR_EN_B_0X0												(0x0u<<0)
#define	I3C_CFGR_EN_B_0X1												(0x1u<<0)

// RDR Configuration

#define	I3C_RDR_RDB0													(0xFFu<<0)
#define	I3C_RDR_RDB0_0													(0x1u<<0)

// RDWR Configuration

#define	I3C_RDWR_RDB3													(0xFFu<<24)
#define	I3C_RDWR_RDB3_0													(0x1u<<24)
#define	I3C_RDWR_RDB2													(0xFFu<<16)
#define	I3C_RDWR_RDB2_0													(0x1u<<16)
#define	I3C_RDWR_RDB1													(0xFFu<<8)
#define	I3C_RDWR_RDB1_0													(0x1u<<8)
#define	I3C_RDWR_RDB0													(0xFFu<<0)
#define	I3C_RDWR_RDB0_0													(0x1u<<0)

// TDR Configuration

#define	I3C_TDR_TDB0													(0xFFu<<0)
#define	I3C_TDR_TDB0_0													(0x1u<<0)

// TDWR Configuration

#define	I3C_TDWR_TDB3													(0xFFu<<24)
#define	I3C_TDWR_TDB3_0													(0x1u<<24)
#define	I3C_TDWR_TDB2													(0xFFu<<16)
#define	I3C_TDWR_TDB2_0													(0x1u<<16)
#define	I3C_TDWR_TDB1													(0xFFu<<8)
#define	I3C_TDWR_TDB1_0													(0x1u<<8)
#define	I3C_TDWR_TDB0													(0xFFu<<0)
#define	I3C_TDWR_TDB0_0													(0x1u<<0)

// IBIDR Configuration

#define	I3C_IBIDR_IBIDB3												(0xFFu<<24)
#define	I3C_IBIDR_IBIDB3_0												(0x1u<<24)
#define	I3C_IBIDR_IBIDB2												(0xFFu<<16)
#define	I3C_IBIDR_IBIDB2_0												(0x1u<<16)
#define	I3C_IBIDR_IBIDB1												(0xFFu<<8)
#define	I3C_IBIDR_IBIDB1_0												(0x1u<<8)
#define	I3C_IBIDR_IBIDB0												(0xFFu<<0)
#define	I3C_IBIDR_IBIDB0_0												(0x1u<<0)

// TGTTDR Configuration

#define	I3C_TGTTDR_PRELOAD												(0x1u<<16)
#define	I3C_TGTTDR_TGTTDCNT												(0xFFFFu<<0)
#define	I3C_TGTTDR_TGTTDCNT_0											(0x1u<<0)

#define	I3C_TGTTDR_PRELOAD_B_0X0										(0x0u<<16)
#define	I3C_TGTTDR_PRELOAD_B_0X1										(0x1u<<16)

// SR Configuration

#define	I3C_SR_MID														(0xFFu<<24)
#define	I3C_SR_MID_0													(0x1u<<24)
#define	I3C_SR_DIR														(0x1u<<18)
#define	I3C_SR_ABT														(0x1u<<17)
#define	I3C_SR_XDCNT													(0xFFFFu<<0)
#define	I3C_SR_XDCNT_0													(0x1u<<0)

#define	I3C_SR_DIR_B_0X0												(0x0u<<18)
#define	I3C_SR_DIR_B_0X1												(0x1u<<18)
#define	I3C_SR_ABT_B_0X0												(0x0u<<17)
#define	I3C_SR_ABT_B_0X1												(0x1u<<17)

// SER Configuration

#define	I3C_SER_DERR													(0x1u<<10)
#define	I3C_SER_DNACK													(0x1u<<9)
#define	I3C_SER_ANACK													(0x1u<<8)
#define	I3C_SER_COVR													(0x1u<<7)
#define	I3C_SER_DOVR													(0x1u<<6)
#define	I3C_SER_STALL													(0x1u<<5)
#define	I3C_SER_PERR													(0x1u<<4)
#define	I3C_SER_CODERR													(0xFu<<0)
#define	I3C_SER_CODERR_0												(0x1u<<0)

#define	I3C_SER_DERR_B_0X0												(0x0u<<10)
#define	I3C_SER_DERR_B_0X1												(0x1u<<10)
#define	I3C_SER_DNACK_B_0X0												(0x0u<<9)
#define	I3C_SER_DNACK_B_0X1												(0x1u<<9)
#define	I3C_SER_ANACK_B_0X0												(0x0u<<8)
#define	I3C_SER_ANACK_B_0X1												(0x1u<<8)
#define	I3C_SER_COVR_B_0X0												(0x0u<<7)
#define	I3C_SER_COVR_B_0X1												(0x1u<<7)
#define	I3C_SER_DOVR_B_0X0												(0x0u<<6)
#define	I3C_SER_DOVR_B_0X1												(0x1u<<6)
#define	I3C_SER_STALL_B_0X0												(0x0u<<5)
#define	I3C_SER_STALL_B_0X1												(0x1u<<5)
#define	I3C_SER_PERR_B_0X0												(0x0u<<4)
#define	I3C_SER_PERR_B_0X1												(0x1u<<4)
#define	I3C_SER_CODERR_B_0X0											(0x0u<<0)
#define	I3C_SER_CODERR_B_0X1											(0x1u<<0)
#define	I3C_SER_CODERR_B_0X2											(0x2u<<0)
#define	I3C_SER_CODERR_B_0X3											(0x3u<<0)
#define	I3C_SER_CODERR_B_0X8											(0x8u<<0)
#define	I3C_SER_CODERR_B_0X9											(0x9u<<0)
#define	I3C_SER_CODERR_B_0XA											(0xAu<<0)
#define	I3C_SER_CODERR_B_0XB											(0xBu<<0)
#define	I3C_SER_CODERR_B_0XC											(0xCu<<0)
#define	I3C_SER_CODERR_B_0XD											(0xDu<<0)
#define	I3C_SER_CODERR_B_0XE											(0xEu<<0)

// RMR Configuration

#define	I3C_RMR_RADD													(0x7Fu<<17)
#define	I3C_RMR_RADD_0													(0x1u<<17)
#define	I3C_RMR_RCODE													(0xFFu<<8)
#define	I3C_RMR_RCODE_0													(0x1u<<8)
#define	I3C_RMR_IBIRDCNT												(0x7u<<0)
#define	I3C_RMR_IBIRDCNT_0												(0x1u<<0)

// EVR Configuration

#define	I3C_EVR_GRPF													(0x1u<<31)
#define	I3C_EVR_DEFF													(0x1u<<30)
#define	I3C_EVR_INTUPDF													(0x1u<<29)
#define	I3C_EVR_ASUPDF													(0x1u<<28)
#define	I3C_EVR_RSTF													(0x1u<<27)
#define	I3C_EVR_MRLUPDF													(0x1u<<26)
#define	I3C_EVR_MWLUPDF													(0x1u<<25)
#define	I3C_EVR_DAUPDF													(0x1u<<24)
#define	I3C_EVR_STAF													(0x1u<<23)
#define	I3C_EVR_GETF													(0x1u<<22)
#define	I3C_EVR_WKPF													(0x1u<<21)
#define	I3C_EVR_HJF														(0x1u<<19)
#define	I3C_EVR_CRUPDF													(0x1u<<18)
#define	I3C_EVR_CRF														(0x1u<<17)
#define	I3C_EVR_IBIENDF													(0x1u<<16)
#define	I3C_EVR_IBIF													(0x1u<<15)
#define	I3C_EVR_ERRF													(0x1u<<11)
#define	I3C_EVR_RXTGTENDF												(0x1u<<10)
#define	I3C_EVR_FCF														(0x1u<<9)
#define	I3C_EVR_RXLASTF													(0x1u<<7)
#define	I3C_EVR_TXLASTF													(0x1u<<6)
#define	I3C_EVR_RXFNEF													(0x1u<<5)
#define	I3C_EVR_TXFNFF													(0x1u<<4)
#define	I3C_EVR_SFNEF													(0x1u<<3)
#define	I3C_EVR_CFNFF													(0x1u<<2)
#define	I3C_EVR_TXFEF													(0x1u<<1)
#define	I3C_EVR_CFEF													(0x1u<<0)

// IER Configuration

#define	I3C_IER_GRPIE													(0x1u<<31)
#define	I3C_IER_DEFIE													(0x1u<<30)
#define	I3C_IER_INTUPDIE												(0x1u<<29)
#define	I3C_IER_ASUPDIE													(0x1u<<28)
#define	I3C_IER_RSTIE													(0x1u<<27)
#define	I3C_IER_MRLUPDIE												(0x1u<<26)
#define	I3C_IER_MWLUPDIE												(0x1u<<25)
#define	I3C_IER_DAUPDIE													(0x1u<<24)
#define	I3C_IER_STAIE													(0x1u<<23)
#define	I3C_IER_GETIE													(0x1u<<22)
#define	I3C_IER_WKPIE													(0x1u<<21)
#define	I3C_IER_HJIE													(0x1u<<19)
#define	I3C_IER_CRUPDIE													(0x1u<<18)
#define	I3C_IER_CRIE													(0x1u<<17)
#define	I3C_IER_IBIENDIE												(0x1u<<16)
#define	I3C_IER_IBIIE													(0x1u<<15)
#define	I3C_IER_ERRIE													(0x1u<<11)
#define	I3C_IER_RXTGTENDIE												(0x1u<<10)
#define	I3C_IER_FCIE													(0x1u<<9)
#define	I3C_IER_RXFNEIE													(0x1u<<5)
#define	I3C_IER_TXFNFIE													(0x1u<<4)
#define	I3C_IER_SFNEIE													(0x1u<<3)
#define	I3C_IER_CFNFIE													(0x1u<<2)

#define	I3C_IER_GRPIE_B_0X0												(0x0u<<31)
#define	I3C_IER_GRPIE_B_0X1												(0x1u<<31)
#define	I3C_IER_DEFIE_B_0X0												(0x0u<<30)
#define	I3C_IER_DEFIE_B_0X1												(0x1u<<30)
#define	I3C_IER_INTUPDIE_B_0X0											(0x0u<<29)
#define	I3C_IER_INTUPDIE_B_0X1											(0x1u<<29)
#define	I3C_IER_ASUPDIE_B_0X0											(0x0u<<28)
#define	I3C_IER_ASUPDIE_B_0X1											(0x1u<<28)
#define	I3C_IER_RSTIE_B_0X0												(0x0u<<27)
#define	I3C_IER_RSTIE_B_0X1												(0x1u<<27)
#define	I3C_IER_MRLUPDIE_B_0X0											(0x0u<<26)
#define	I3C_IER_MRLUPDIE_B_0X1											(0x1u<<26)
#define	I3C_IER_MWLUPDIE_B_0X0											(0x0u<<25)
#define	I3C_IER_MWLUPDIE_B_0X1											(0x1u<<25)
#define	I3C_IER_DAUPDIE_B_0X0											(0x0u<<24)
#define	I3C_IER_DAUPDIE_B_0X1											(0x1u<<24)
#define	I3C_IER_STAIE_B_0X0												(0x0u<<23)
#define	I3C_IER_STAIE_B_0X1												(0x1u<<23)
#define	I3C_IER_GETIE_B_0X0												(0x0u<<22)
#define	I3C_IER_GETIE_B_0X1												(0x1u<<22)
#define	I3C_IER_WKPIE_B_0X0												(0x0u<<21)
#define	I3C_IER_WKPIE_B_0X1												(0x1u<<21)
#define	I3C_IER_HJIE_B_0X0												(0x0u<<19)
#define	I3C_IER_HJIE_B_0X1												(0x1u<<19)
#define	I3C_IER_CRUPDIE_B_0X0											(0x0u<<18)
#define	I3C_IER_CRUPDIE_B_0X1											(0x1u<<18)
#define	I3C_IER_CRIE_B_0X0												(0x0u<<17)
#define	I3C_IER_CRIE_B_0X1												(0x1u<<17)
#define	I3C_IER_IBIENDIE_B_0X0											(0x0u<<16)
#define	I3C_IER_IBIENDIE_B_0X1											(0x1u<<16)
#define	I3C_IER_IBIIE_B_0X0												(0x0u<<15)
#define	I3C_IER_IBIIE_B_0X1												(0x1u<<15)
#define	I3C_IER_ERRIE_B_0X0												(0x0u<<11)
#define	I3C_IER_ERRIE_B_0X1												(0x1u<<11)
#define	I3C_IER_RXTGTENDIE_B_0X0										(0x0u<<10)
#define	I3C_IER_RXTGTENDIE_B_0X1										(0x1u<<10)
#define	I3C_IER_FCIE_B_0X0												(0x0u<<9)
#define	I3C_IER_FCIE_B_0X1												(0x1u<<9)
#define	I3C_IER_RXFNEIE_B_0X0											(0x0u<<5)
#define	I3C_IER_RXFNEIE_B_0X1											(0x1u<<5)
#define	I3C_IER_TXFNFIE_B_0X0											(0x0u<<4)
#define	I3C_IER_TXFNFIE_B_0X1											(0x1u<<4)
#define	I3C_IER_SFNEIE_B_0X0											(0x0u<<3)
#define	I3C_IER_SFNEIE_B_0X1											(0x1u<<3)
#define	I3C_IER_CFNFIE_B_0X0											(0x0u<<2)
#define	I3C_IER_CFNFIE_B_0X1											(0x1u<<2)

// CEVR Configuration

#define	I3C_CEVR_CGRPF													(0x1u<<31)
#define	I3C_CEVR_CDEFF													(0x1u<<30)
#define	I3C_CEVR_CINTUPDF												(0x1u<<29)
#define	I3C_CEVR_CASUPDF												(0x1u<<28)
#define	I3C_CEVR_CRSTF													(0x1u<<27)
#define	I3C_CEVR_CMRLUPDF												(0x1u<<26)
#define	I3C_CEVR_CMWLUPDF												(0x1u<<25)
#define	I3C_CEVR_CDAUPDF												(0x1u<<24)
#define	I3C_CEVR_CSTAF													(0x1u<<23)
#define	I3C_CEVR_CGETF													(0x1u<<22)
#define	I3C_CEVR_CWKPF													(0x1u<<21)
#define	I3C_CEVR_CHJF													(0x1u<<19)
#define	I3C_CEVR_CCRUPDF												(0x1u<<18)
#define	I3C_CEVR_CCRF													(0x1u<<17)
#define	I3C_CEVR_CIBIENDF												(0x1u<<16)
#define	I3C_CEVR_CIBIF													(0x1u<<15)
#define	I3C_CEVR_CERRF													(0x1u<<11)
#define	I3C_CEVR_CRXTGTENDF												(0x1u<<10)
#define	I3C_CEVR_CFCF													(0x1u<<9)

#define	I3C_CEVR_CGRPF_B_0X0											(0x0u<<31)
#define	I3C_CEVR_CGRPF_B_0X1											(0x1u<<31)
#define	I3C_CEVR_CDEFF_B_0X0											(0x0u<<30)
#define	I3C_CEVR_CDEFF_B_0X1											(0x1u<<30)
#define	I3C_CEVR_CINTUPDF_B_0X0											(0x0u<<29)
#define	I3C_CEVR_CINTUPDF_B_0X1											(0x1u<<29)
#define	I3C_CEVR_CASUPDF_B_0X0											(0x0u<<28)
#define	I3C_CEVR_CASUPDF_B_0X1											(0x1u<<28)
#define	I3C_CEVR_CRSTF_B_0X0											(0x0u<<27)
#define	I3C_CEVR_CRSTF_B_0X1											(0x1u<<27)
#define	I3C_CEVR_CMRLUPDF_B_0X0											(0x0u<<26)
#define	I3C_CEVR_CMRLUPDF_B_0X1											(0x1u<<26)
#define	I3C_CEVR_CMWLUPDF_B_0X0											(0x0u<<25)
#define	I3C_CEVR_CMWLUPDF_B_0X1											(0x1u<<25)
#define	I3C_CEVR_CDAUPDF_B_0X0											(0x0u<<24)
#define	I3C_CEVR_CDAUPDF_B_0X1											(0x1u<<24)
#define	I3C_CEVR_CSTAF_B_0X0											(0x0u<<23)
#define	I3C_CEVR_CSTAF_B_0X1											(0x1u<<23)
#define	I3C_CEVR_CGETF_B_0X0											(0x0u<<22)
#define	I3C_CEVR_CGETF_B_0X1											(0x1u<<22)
#define	I3C_CEVR_CWKPF_B_0X0											(0x0u<<21)
#define	I3C_CEVR_CWKPF_B_0X1											(0x1u<<21)
#define	I3C_CEVR_CHJF_B_0X0												(0x0u<<19)
#define	I3C_CEVR_CHJF_B_0X1												(0x1u<<19)
#define	I3C_CEVR_CCRUPDF_B_0X0											(0x0u<<18)
#define	I3C_CEVR_CCRUPDF_B_0X1											(0x1u<<18)
#define	I3C_CEVR_CCRF_B_0X0												(0x0u<<17)
#define	I3C_CEVR_CCRF_B_0X1												(0x1u<<17)
#define	I3C_CEVR_CIBIENDF_B_0X0											(0x0u<<16)
#define	I3C_CEVR_CIBIENDF_B_0X1											(0x1u<<16)
#define	I3C_CEVR_CIBIF_B_0X0											(0x0u<<15)
#define	I3C_CEVR_CIBIF_B_0X1											(0x1u<<15)
#define	I3C_CEVR_CERRF_B_0X0											(0x0u<<11)
#define	I3C_CEVR_CERRF_B_0X1											(0x1u<<11)
#define	I3C_CEVR_CRXTGTENDF_B_0X0										(0x0u<<10)
#define	I3C_CEVR_CRXTGTENDF_B_0X1										(0x1u<<10)
#define	I3C_CEVR_CFCF_B_0X0												(0x0u<<9)
#define	I3C_CEVR_CFCF_B_0X1												(0x1u<<9)

// DEVR0 Configuration

#define	I3C_DEVR0_RSTVAL												(0x1u<<24)
#define	I3C_DEVR0_RSTACT												(0x3u<<22)
#define	I3C_DEVR0_RSTACT_0												(0x1u<<22)
#define	I3C_DEVR0_AS													(0x3u<<20)
#define	I3C_DEVR0_AS_0													(0x1u<<20)
#define	I3C_DEVR0_HJEN													(0x1u<<19)
#define	I3C_DEVR0_CREN													(0x1u<<17)
#define	I3C_DEVR0_IBIEN													(0x1u<<16)
#define	I3C_DEVR0_DA													(0x7Fu<<1)
#define	I3C_DEVR0_DA_0													(0x1u<<1)
#define	I3C_DEVR0_DAVAL													(0x1u<<0)

#define	I3C_DEVR0_RSTACT_B_0X0											(0x0u<<22)
#define	I3C_DEVR0_RSTACT_B_0X1											(0x1u<<22)
#define	I3C_DEVR0_RSTACT_B_0X2											(0x2u<<22)
#define	I3C_DEVR0_RSTACT_B_0X3											(0x3u<<22)
#define	I3C_DEVR0_AS_B_0X0												(0x0u<<20)
#define	I3C_DEVR0_AS_B_0X1												(0x1u<<20)
#define	I3C_DEVR0_AS_B_0X2												(0x2u<<20)
#define	I3C_DEVR0_AS_B_0X3												(0x3u<<20)
#define	I3C_DEVR0_HJEN_B_0X0											(0x0u<<19)
#define	I3C_DEVR0_HJEN_B_0X1											(0x1u<<19)
#define	I3C_DEVR0_CREN_B_0X0											(0x0u<<17)
#define	I3C_DEVR0_CREN_B_0X1											(0x1u<<17)
#define	I3C_DEVR0_IBIEN_B_0X0											(0x0u<<16)
#define	I3C_DEVR0_IBIEN_B_0X1											(0x1u<<16)

// DEVR1 Configuration

#define	I3C_DEVR1_DIS													(0x1u<<31)
#define	I3C_DEVR1_SUSP													(0x1u<<19)
#define	I3C_DEVR1_IBIDEN												(0x1u<<18)
#define	I3C_DEVR1_CRACK													(0x1u<<17)
#define	I3C_DEVR1_IBIACK												(0x1u<<16)
#define	I3C_DEVR1_DA													(0x7Fu<<1)
#define	I3C_DEVR1_DA_0													(0x1u<<1)

#define	I3C_DEVR1_DIS_B_0X0												(0x0u<<31)
#define	I3C_DEVR1_DIS_B_0X1												(0x1u<<31)
#define	I3C_DEVR1_SUSP_B_0X0											(0x0u<<19)
#define	I3C_DEVR1_SUSP_B_0X1											(0x1u<<19)
#define	I3C_DEVR1_IBIDEN_B_0X0											(0x0u<<18)
#define	I3C_DEVR1_IBIDEN_B_0X1											(0x1u<<18)
#define	I3C_DEVR1_CRACK_B_0X0											(0x0u<<17)
#define	I3C_DEVR1_CRACK_B_0X1											(0x1u<<17)
#define	I3C_DEVR1_IBIACK_B_0X0											(0x0u<<16)
#define	I3C_DEVR1_IBIACK_B_0X1											(0x1u<<16)

// DEVR2 Configuration

#define	I3C_DEVR2_DIS													(0x1u<<31)
#define	I3C_DEVR2_SUSP													(0x1u<<19)
#define	I3C_DEVR2_IBIDEN												(0x1u<<18)
#define	I3C_DEVR2_CRACK													(0x1u<<17)
#define	I3C_DEVR2_IBIACK												(0x1u<<16)
#define	I3C_DEVR2_DA													(0x7Fu<<1)
#define	I3C_DEVR2_DA_0													(0x1u<<1)

#define	I3C_DEVR2_DIS_B_0X0												(0x0u<<31)
#define	I3C_DEVR2_DIS_B_0X1												(0x1u<<31)
#define	I3C_DEVR2_SUSP_B_0X0											(0x0u<<19)
#define	I3C_DEVR2_SUSP_B_0X1											(0x1u<<19)
#define	I3C_DEVR2_IBIDEN_B_0X0											(0x0u<<18)
#define	I3C_DEVR2_IBIDEN_B_0X1											(0x1u<<18)
#define	I3C_DEVR2_CRACK_B_0X0											(0x0u<<17)
#define	I3C_DEVR2_CRACK_B_0X1											(0x1u<<17)
#define	I3C_DEVR2_IBIACK_B_0X0											(0x0u<<16)
#define	I3C_DEVR2_IBIACK_B_0X1											(0x1u<<16)

// DEVR3 Configuration

#define	I3C_DEVR3_DIS													(0x1u<<31)
#define	I3C_DEVR3_SUSP													(0x1u<<19)
#define	I3C_DEVR3_IBIDEN												(0x1u<<18)
#define	I3C_DEVR3_CRACK													(0x1u<<17)
#define	I3C_DEVR3_IBIACK												(0x1u<<16)
#define	I3C_DEVR3_DA													(0x7Fu<<1)
#define	I3C_DEVR3_DA_0													(0x1u<<1)

#define	I3C_DEVR3_DIS_B_0X0												(0x0u<<31)
#define	I3C_DEVR3_DIS_B_0X1												(0x1u<<31)
#define	I3C_DEVR3_SUSP_B_0X0											(0x0u<<19)
#define	I3C_DEVR3_SUSP_B_0X1											(0x1u<<19)
#define	I3C_DEVR3_IBIDEN_B_0X0											(0x0u<<18)
#define	I3C_DEVR3_IBIDEN_B_0X1											(0x1u<<18)
#define	I3C_DEVR3_CRACK_B_0X0											(0x0u<<17)
#define	I3C_DEVR3_CRACK_B_0X1											(0x1u<<17)
#define	I3C_DEVR3_IBIACK_B_0X0											(0x0u<<16)
#define	I3C_DEVR3_IBIACK_B_0X1											(0x1u<<16)

// DEVR4 Configuration

#define	I3C_DEVR4_DIS													(0x1u<<31)
#define	I3C_DEVR4_SUSP													(0x1u<<19)
#define	I3C_DEVR4_IBIDEN												(0x1u<<18)
#define	I3C_DEVR4_CRACK													(0x1u<<17)
#define	I3C_DEVR4_IBIACK												(0x1u<<16)
#define	I3C_DEVR4_DA													(0x7Fu<<1)
#define	I3C_DEVR4_DA_0													(0x1u<<1)

#define	I3C_DEVR4_DIS_B_0X0												(0x0u<<31)
#define	I3C_DEVR4_DIS_B_0X1												(0x1u<<31)
#define	I3C_DEVR4_SUSP_B_0X0											(0x0u<<19)
#define	I3C_DEVR4_SUSP_B_0X1											(0x1u<<19)
#define	I3C_DEVR4_IBIDEN_B_0X0											(0x0u<<18)
#define	I3C_DEVR4_IBIDEN_B_0X1											(0x1u<<18)
#define	I3C_DEVR4_CRACK_B_0X0											(0x0u<<17)
#define	I3C_DEVR4_CRACK_B_0X1											(0x1u<<17)
#define	I3C_DEVR4_IBIACK_B_0X0											(0x0u<<16)
#define	I3C_DEVR4_IBIACK_B_0X1											(0x1u<<16)

// MAXRLR Configuration

#define	I3C_MAXRLR_IBIP													(0x7u<<16)
#define	I3C_MAXRLR_IBIP_0												(0x1u<<16)
#define	I3C_MAXRLR_MRL													(0xFFFFu<<0)
#define	I3C_MAXRLR_MRL_0												(0x1u<<0)

#define	I3C_MAXRLR_IBIP_B_0X0											(0x0u<<16)
#define	I3C_MAXRLR_IBIP_B_0X1											(0x1u<<16)
#define	I3C_MAXRLR_IBIP_B_0X2											(0x2u<<16)
#define	I3C_MAXRLR_IBIP_B_0X3											(0x3u<<16)
#define	I3C_MAXRLR_IBIP_B_0X4											(0x4u<<16)

// MAXWLR Configuration

#define	I3C_MAXWLR_MWL													(0xFFFFu<<0)
#define	I3C_MAXWLR_MWL_0												(0x1u<<0)

// TIMINGR0 Configuration

#define	I3C_TIMINGR0_SCLH_I2C											(0xFFu<<24)
#define	I3C_TIMINGR0_SCLH_I2C_0											(0x1u<<24)
#define	I3C_TIMINGR0_SCLL_OD											(0xFFu<<16)
#define	I3C_TIMINGR0_SCLL_OD_0											(0x1u<<16)
#define	I3C_TIMINGR0_SCLH_I3C											(0xFFu<<8)
#define	I3C_TIMINGR0_SCLH_I3C_0											(0x1u<<8)
#define	I3C_TIMINGR0_SCLL_PP											(0xFFu<<0)
#define	I3C_TIMINGR0_SCLL_PP_0											(0x1u<<0)

// TIMINGR1 Configuration

#define	I3C_TIMINGR1_SDA_HD												(0x1u<<28)
#define	I3C_TIMINGR1_FREE												(0x7Fu<<16)
#define	I3C_TIMINGR1_FREE_0												(0x1u<<16)
#define	I3C_TIMINGR1_ASNCR												(0x3u<<8)
#define	I3C_TIMINGR1_ASNCR_0											(0x1u<<8)
#define	I3C_TIMINGR1_AVAL												(0xFFu<<0)
#define	I3C_TIMINGR1_AVAL_0												(0x1u<<0)

// TIMINGR2 Configuration

#define	I3C_TIMINGR2_STALL												(0xFFu<<8)
#define	I3C_TIMINGR2_STALL_0											(0x1u<<8)
#define	I3C_TIMINGR2_STALLA												(0x1u<<3)
#define	I3C_TIMINGR2_STALLC												(0x1u<<2)
#define	I3C_TIMINGR2_STALLD												(0x1u<<1)
#define	I3C_TIMINGR2_STALLT												(0x1u<<0)

#define	I3C_TIMINGR2_STALLA_B_0X0										(0x0u<<3)
#define	I3C_TIMINGR2_STALLA_B_0X1										(0x1u<<3)
#define	I3C_TIMINGR2_STALLC_B_0X0										(0x0u<<2)
#define	I3C_TIMINGR2_STALLC_B_0X1										(0x1u<<2)
#define	I3C_TIMINGR2_STALLD_B_0X0										(0x0u<<1)
#define	I3C_TIMINGR2_STALLD_B_0X1										(0x1u<<1)
#define	I3C_TIMINGR2_STALLT_B_0X0										(0x0u<<0)
#define	I3C_TIMINGR2_STALLT_B_0X1										(0x1u<<0)

// BCR Configuration

#define	I3C_BCR_BCR6													(0x1u<<6)
#define	I3C_BCR_BCR2													(0x1u<<2)
#define	I3C_BCR_BCR0													(0x1u<<0)

#define	I3C_BCR_BCR6_B_0X0												(0x0u<<6)
#define	I3C_BCR_BCR6_B_0X1												(0x1u<<6)
#define	I3C_BCR_BCR2_B_0X0												(0x0u<<2)
#define	I3C_BCR_BCR2_B_0X1												(0x1u<<2)
#define	I3C_BCR_BCR0_B_0X0												(0x0u<<0)
#define	I3C_BCR_BCR0_B_0X1												(0x1u<<0)

// DCR Configuration

#define	I3C_DCR_DCR														(0xFFu<<0)
#define	I3C_DCR_DCR_0													(0x1u<<0)

#define	I3C_DCR_DCR_B_0X00												(0x0u<<0)

// GETCAPR Configuration

#define	I3C_GETCAPR_CAPPEND												(0x1u<<14)

#define	I3C_GETCAPR_CAPPEND_B_0X0										(0x0u<<14)
#define	I3C_GETCAPR_CAPPEND_B_0X1										(0x1u<<14)

// CRCAPR Configuration

#define	I3C_CRCAPR_CAPGRP												(0x1u<<9)
#define	I3C_CRCAPR_CAPDHOFF												(0x1u<<3)

#define	I3C_CRCAPR_CAPGRP_B_0X0											(0x0u<<9)
#define	I3C_CRCAPR_CAPGRP_B_0X1											(0x1u<<9)
#define	I3C_CRCAPR_CAPDHOFF_B_0X0										(0x0u<<3)
#define	I3C_CRCAPR_CAPDHOFF_B_0X1										(0x1u<<3)

// GETMXDSR Configuration

#define	I3C_GETMXDSR_TSCO												(0x1u<<24)
#define	I3C_GETMXDSR_RDTURN												(0xFFu<<16)
#define	I3C_GETMXDSR_RDTURN_0											(0x1u<<16)
#define	I3C_GETMXDSR_FMT												(0x3u<<8)
#define	I3C_GETMXDSR_FMT_0												(0x1u<<8)
#define	I3C_GETMXDSR_HOFFAS												(0x3u<<0)
#define	I3C_GETMXDSR_HOFFAS_0											(0x1u<<0)

#define	I3C_GETMXDSR_TSCO_B_0X0											(0x0u<<24)
#define	I3C_GETMXDSR_TSCO_B_0X1											(0x1u<<24)
#define	I3C_GETMXDSR_FMT_B_0X0											(0x0u<<8)
#define	I3C_GETMXDSR_FMT_B_0X1											(0x1u<<8)
#define	I3C_GETMXDSR_FMT_B_0X2											(0x2u<<8)
#define	I3C_GETMXDSR_FMT_B_0X3											(0x3u<<8)
#define	I3C_GETMXDSR_HOFFAS_B_0X0										(0x0u<<0)
#define	I3C_GETMXDSR_HOFFAS_B_0X1										(0x1u<<0)
#define	I3C_GETMXDSR_HOFFAS_B_0X2										(0x2u<<0)
#define	I3C_GETMXDSR_HOFFAS_B_0X3										(0x3u<<0)

// EPIDR Configuration

#define	I3C_EPIDR_MIPIMID												(0x7FFFu<<17)
#define	I3C_EPIDR_MIPIMID_0												(0x1u<<17)
#define	I3C_EPIDR_IDTSEL												(0x1u<<16)
#define	I3C_EPIDR_MIPIID												(0xFu<<12)
#define	I3C_EPIDR_MIPIID_0												(0x1u<<12)
