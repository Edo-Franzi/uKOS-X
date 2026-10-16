/*
; stm32U5Gx_hspi.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_hspi equates.
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

// HSPI address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	DCR1;
	volatile	uint32_t	DCR2;
	volatile	uint32_t	DCR3;
	volatile	uint32_t	DCR4;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	SR;
	volatile	uint32_t	FCR;
	volatile	uint32_t	RESERVED2[6];
	volatile	uint32_t	DLR;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	AR;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	DR;
	volatile	uint32_t	RESERVED5[11];
	volatile	uint32_t	PSMKR;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	PSMAR;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	PIR;
	volatile	uint32_t	RESERVED8[27];
	volatile	uint32_t	CCR;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	TCR;
	volatile	uint32_t	RESERVED10;
	volatile	uint32_t	IR;
	volatile	uint32_t	RESERVED11[3];
	volatile	uint32_t	ABR;
	volatile	uint32_t	RESERVED12[3];
	volatile	uint32_t	LPTR;
	volatile	uint32_t	RESERVED13[3];
	volatile	uint32_t	WPCCR;
	volatile	uint32_t	RESERVED14;
	volatile	uint32_t	WPTCR;
	volatile	uint32_t	RESERVED15;
	volatile	uint32_t	WPIR;
	volatile	uint32_t	RESERVED16[3];
	volatile	uint32_t	WPABR;
	volatile	uint32_t	RESERVED17[7];
	volatile	uint32_t	WCCR;
	volatile	uint32_t	RESERVED18;
	volatile	uint32_t	WTCR;
	volatile	uint32_t	RESERVED19;
	volatile	uint32_t	WIR;
	volatile	uint32_t	RESERVED20[3];
	volatile	uint32_t	WABR;
	volatile	uint32_t	RESERVED21[23];
	volatile	uint32_t	HLCR;
	volatile	uint32_t	RESERVED22[3];
	volatile	uint32_t	CALFCR;
	volatile	uint32_t	RESERVED23;
	volatile	uint32_t	CALMR;
	volatile	uint32_t	RESERVED24;
	volatile	uint32_t	CALSOR;
	volatile	uint32_t	RESERVED25;
	volatile	uint32_t	CALSIR;
} HSPI_TypeDef;

#if (defined(__cplusplus))
#define	HSPI1_NS	reinterpret_cast<HSPI_TypeDef *>(0x420D3400u)
#define	HSPI1_S		reinterpret_cast<HSPI_TypeDef *>(0x520D3400u)

#else
#define	HSPI1_NS	((HSPI_TypeDef *)0x420D3400u)
#define	HSPI1_S		((HSPI_TypeDef *)0x520D3400u)
#endif

// CR Configuration

#define	HSPI_CR_MSEL				(0x3u<<30)
#define	HSPI_CR_MSEL_0				(0x1u<<30)
#define	HSPI_CR_FMODE				(0x3u<<28)
#define	HSPI_CR_FMODE_0				(0x1u<<28)
#define	HSPI_CR_PMM					(0x1u<<23)
#define	HSPI_CR_APMS				(0x1u<<22)
#define	HSPI_CR_TOIE				(0x1u<<20)
#define	HSPI_CR_SMIE				(0x1u<<19)
#define	HSPI_CR_FTIE				(0x1u<<18)
#define	HSPI_CR_TCIE				(0x1u<<17)
#define	HSPI_CR_TEIE				(0x1u<<16)
#define	HSPI_CR_FTHRES				(0x3Fu<<8)
#define	HSPI_CR_FTHRES_0			(0x1u<<8)
#define	HSPI_CR_FSEL				(0x1u<<7)
#define	HSPI_CR_DMM					(0x1u<<6)
#define	HSPI_CR_TCEN				(0x1u<<3)
#define	HSPI_CR_DMAEN				(0x1u<<2)
#define	HSPI_CR_ABORT				(0x1u<<1)
#define	HSPI_CR_EN					(0x1u<<0)
#define	HSPI_CR_MSEL_B_0X0			(0x0u<<30)
#define	HSPI_CR_MSEL_B_0X1			(0x1u<<30)
#define	HSPI_CR_MSEL_B_0X2			(0x2u<<30)
#define	HSPI_CR_MSEL_B_0X3			(0x3u<<30)
#define	HSPI_CR_FMODE_B_0X0			(0x0u<<28)
#define	HSPI_CR_FMODE_B_0X1			(0x1u<<28)
#define	HSPI_CR_FMODE_B_0X2			(0x2u<<28)
#define	HSPI_CR_FMODE_B_0X3			(0x3u<<28)
#define	HSPI_CR_PMM_B_0X0			(0x0u<<23)
#define	HSPI_CR_PMM_B_0X1			(0x1u<<23)
#define	HSPI_CR_APMS_B_0X0			(0x0u<<22)
#define	HSPI_CR_APMS_B_0X1			(0x1u<<22)
#define	HSPI_CR_TOIE_B_0X0			(0x0u<<20)
#define	HSPI_CR_TOIE_B_0X1			(0x1u<<20)
#define	HSPI_CR_SMIE_B_0X0			(0x0u<<19)
#define	HSPI_CR_SMIE_B_0X1			(0x1u<<19)
#define	HSPI_CR_FTIE_B_0X0			(0x0u<<18)
#define	HSPI_CR_FTIE_B_0X1			(0x1u<<18)
#define	HSPI_CR_TCIE_B_0X0			(0x0u<<17)
#define	HSPI_CR_TCIE_B_0X1			(0x1u<<17)
#define	HSPI_CR_TEIE_B_0X0			(0x0u<<16)
#define	HSPI_CR_TEIE_B_0X1			(0x1u<<16)
#define	HSPI_CR_FTHRES_B_0X0		(0x0u<<8)
#define	HSPI_CR_FTHRES_B_0X1		(0x1u<<8)
#define	HSPI_CR_FTHRES_B_0X3F		(0x3Fu<<8)
#define	HSPI_CR_DMM_B_0X0			(0x0u<<6)
#define	HSPI_CR_DMM_B_0X1			(0x1u<<6)
#define	HSPI_CR_TCEN_B_0X0			(0x0u<<3)
#define	HSPI_CR_TCEN_B_0X1			(0x1u<<3)
#define	HSPI_CR_DMAEN_B_0X0			(0x0u<<2)
#define	HSPI_CR_DMAEN_B_0X1			(0x1u<<2)
#define	HSPI_CR_ABORT_B_0X0			(0x0u<<1)
#define	HSPI_CR_ABORT_B_0X1			(0x1u<<1)
#define	HSPI_CR_EN_B_0X0			(0x0u<<0)
#define	HSPI_CR_EN_B_0X1			(0x1u<<0)

// DCR1 Configuration

#define	HSPI_DCR1_MTYP				(0x7u<<24)
#define	HSPI_DCR1_MTYP_0			(0x1u<<24)
#define	HSPI_DCR1_DEVSIZE			(0x1Fu<<16)
#define	HSPI_DCR1_DEVSIZE_0			(0x1u<<16)
#define	HSPI_DCR1_CSHT				(0x3Fu<<8)
#define	HSPI_DCR1_CSHT_0			(0x1u<<8)
#define	HSPI_DCR1_DLYBYP			(0x1u<<3)
#define	HSPI_DCR1_FRCK				(0x1u<<1)
#define	HSPI_DCR1_CKMODE			(0x1u<<0)
#define	HSPI_DCR1_MTYP_B_0X0		(0x0u<<24)
#define	HSPI_DCR1_MTYP_B_0X1		(0x1u<<24)
#define	HSPI_DCR1_MTYP_B_0X2		(0x2u<<24)
#define	HSPI_DCR1_MTYP_B_0X3		(0x3u<<24)
#define	HSPI_DCR1_MTYP_B_0X4		(0x4u<<24)
#define	HSPI_DCR1_MTYP_B_0X5		(0x5u<<24)
#define	HSPI_DCR1_CSHT_B_0X0		(0x0u<<8)
#define	HSPI_DCR1_CSHT_B_0X1		(0x1u<<8)
#define	HSPI_DCR1_DLYBYP_B_0X0		(0x0u<<3)
#define	HSPI_DCR1_DLYBYP_B_0X1		(0x1u<<3)
#define	HSPI_DCR1_FRCK_B_0X0		(0x0u<<1)
#define	HSPI_DCR1_FRCK_B_0X1		(0x1u<<1)
#define	HSPI_DCR1_CKMODE_B_0X0		(0x0u<<0)
#define	HSPI_DCR1_CKMODE_B_0X1		(0x1u<<0)

// DCR2 Configuration

#define	HSPI_DCR2_WRAPSIZE			(0x7u<<16)
#define	HSPI_DCR2_WRAPSIZE_0		(0x1u<<16)
#define	HSPI_DCR2_PRESCALER			(0xFFu<<0)
#define	HSPI_DCR2_PRESCALER_0		(0x1u<<0)
#define	HSPI_DCR2_WRAPSIZE_B_0X0	(0x0u<<16)
#define	HSPI_DCR2_WRAPSIZE_B_0X2	(0x2u<<16)
#define	HSPI_DCR2_WRAPSIZE_B_0X3	(0x3u<<16)
#define	HSPI_DCR2_WRAPSIZE_B_0X4	(0x4u<<16)
#define	HSPI_DCR2_WRAPSIZE_B_0X5	(0x5u<<16)
#define	HSPI_DCR2_PRESCALER_B_0X0	(0x0u<<0)
#define	HSPI_DCR2_PRESCALER_B_0X1	(0x1u<<0)

// DCR3 Configuration

#define	HSPI_DCR3_CSBOUND			(0x1Fu<<16)
#define	HSPI_DCR3_CSBOUND_0			(0x1u<<16)
#define	HSPI_DCR3_MAXTRAN			(0xFFu<<0)
#define	HSPI_DCR3_MAXTRAN_0			(0x1u<<0)
#define	HSPI_DCR3_CSBOUND_B_0X0		(0x0u<<16)
#define	HSPI_DCR3_MAXTRAN_B_0X0		(0x0u<<0)

// DCR4 Configuration

#define	HSPI_DCR4_REFRESH			(0xFFFFFFFFu<<0)
#define	HSPI_DCR4_REFRESH_0			(0x1u<<0)
#define	HSPI_DCR4_REFRESH_B_0X0		(0x0u<<0)

// SR Configuration

#define	HSPI_SR_FLEVEL				(0x7Fu<<8)
#define	HSPI_SR_FLEVEL_0			(0x1u<<8)
#define	HSPI_SR_BUSY				(0x1u<<5)
#define	HSPI_SR_TOF					(0x1u<<4)
#define	HSPI_SR_SMF					(0x1u<<3)
#define	HSPI_SR_FTF					(0x1u<<2)
#define	HSPI_SR_TCF					(0x1u<<1)
#define	HSPI_SR_TEF					(0x1u<<0)

// FCR Configuration

#define	HSPI_FCR_CTOF				(0x1u<<4)
#define	HSPI_FCR_CSMF				(0x1u<<3)
#define	HSPI_FCR_CTCF				(0x1u<<1)
#define	HSPI_FCR_CTEF				(0x1u<<0)

// DLR Configuration

#define	HSPI_DLR_DL					(0xFFFFFFFFu<<0)
#define	HSPI_DLR_DL_0				(0x1u<<0)

// AR Configuration

#define	HSPI_AR_ADDRESS				(0xFFFFFFFFu<<0)
#define	HSPI_AR_ADDRESS_0			(0x1u<<0)

// DR Configuration

#define	HSPI_DR_DATA				(0xFFFFFFFFu<<0)
#define	HSPI_DR_DATA_0				(0x1u<<0)

// PSMKR Configuration

#define	HSPI_PSMKR_MASK				(0xFFFFFFFFu<<0)
#define	HSPI_PSMKR_MASK_0			(0x1u<<0)
#define	HSPI_PSMKR_MASK_B_0X0		(0x0u<<0)
#define	HSPI_PSMKR_MASK_B_0X1		(0x1u<<0)

// PSMAR Configuration

#define	HSPI_PSMAR_MATCH			(0xFFFFFFFFu<<0)
#define	HSPI_PSMAR_MATCH_0			(0x1u<<0)

// PIR Configuration

#define	HSPI_PIR_INTERVAL			(0xFFFFu<<0)
#define	HSPI_PIR_INTERVAL_0			(0x1u<<0)

// CCR Configuration

#define	HSPI_CCR_SIOO				(0x1u<<31)
#define	HSPI_CCR_DQSE				(0x1u<<29)
#define	HSPI_CCR_DDTR				(0x1u<<27)
#define	HSPI_CCR_DMODE				(0x7u<<24)
#define	HSPI_CCR_DMODE_0			(0x1u<<24)
#define	HSPI_CCR_ABSIZE				(0x3u<<20)
#define	HSPI_CCR_ABSIZE_0			(0x1u<<20)
#define	HSPI_CCR_ABDTR				(0x1u<<19)
#define	HSPI_CCR_ABMODE				(0x7u<<16)
#define	HSPI_CCR_ABMODE_0			(0x1u<<16)
#define	HSPI_CCR_ADSIZE				(0x3u<<12)
#define	HSPI_CCR_ADSIZE_0			(0x1u<<12)
#define	HSPI_CCR_ADDTR				(0x1u<<11)
#define	HSPI_CCR_ADMODE				(0x7u<<8)
#define	HSPI_CCR_ADMODE_0			(0x1u<<8)
#define	HSPI_CCR_ISIZE				(0x3u<<4)
#define	HSPI_CCR_ISIZE_0			(0x1u<<4)
#define	HSPI_CCR_IDTR				(0x1u<<3)
#define	HSPI_CCR_IMODE				(0x7u<<0)
#define	HSPI_CCR_IMODE_0			(0x1u<<0)
#define	HSPI_CCR_SIOO_B_0X0			(0x0u<<31)
#define	HSPI_CCR_SIOO_B_0X1			(0x1u<<31)
#define	HSPI_CCR_DQSE_B_0X0			(0x0u<<29)
#define	HSPI_CCR_DQSE_B_0X1			(0x1u<<29)
#define	HSPI_CCR_DDTR_B_0X0			(0x0u<<27)
#define	HSPI_CCR_DDTR_B_0X1			(0x1u<<27)
#define	HSPI_CCR_DMODE_B_0X0		(0x0u<<24)
#define	HSPI_CCR_DMODE_B_0X1		(0x1u<<24)
#define	HSPI_CCR_DMODE_B_0X2		(0x2u<<24)
#define	HSPI_CCR_DMODE_B_0X3		(0x3u<<24)
#define	HSPI_CCR_DMODE_B_0X4		(0x4u<<24)
#define	HSPI_CCR_DMODE_B_0X5		(0x5u<<24)
#define	HSPI_CCR_ABSIZE_B_0X0		(0x0u<<20)
#define	HSPI_CCR_ABSIZE_B_0X1		(0x1u<<20)
#define	HSPI_CCR_ABSIZE_B_0X2		(0x2u<<20)
#define	HSPI_CCR_ABSIZE_B_0X3		(0x3u<<20)
#define	HSPI_CCR_ABDTR_B_0X0		(0x0u<<19)
#define	HSPI_CCR_ABDTR_B_0X1		(0x1u<<19)
#define	HSPI_CCR_ABMODE_B_0X0		(0x0u<<16)
#define	HSPI_CCR_ABMODE_B_0X1		(0x1u<<16)
#define	HSPI_CCR_ABMODE_B_0X2		(0x2u<<16)
#define	HSPI_CCR_ABMODE_B_0X3		(0x3u<<16)
#define	HSPI_CCR_ADSIZE_B_0X0		(0x0u<<12)
#define	HSPI_CCR_ADSIZE_B_0X1		(0x1u<<12)
#define	HSPI_CCR_ADSIZE_B_0X2		(0x2u<<12)
#define	HSPI_CCR_ADSIZE_B_0X3		(0x3u<<12)
#define	HSPI_CCR_ADDTR_B_0X0		(0x0u<<11)
#define	HSPI_CCR_ADDTR_B_0X1		(0x1u<<11)
#define	HSPI_CCR_ADMODE_B_0X0		(0x0u<<8)
#define	HSPI_CCR_ADMODE_B_0X1		(0x1u<<8)
#define	HSPI_CCR_ADMODE_B_0X2		(0x2u<<8)
#define	HSPI_CCR_ADMODE_B_0X3		(0x3u<<8)
#define	HSPI_CCR_ADMODE_B_0X4		(0x4u<<8)
#define	HSPI_CCR_ISIZE_B_0X0		(0x0u<<4)
#define	HSPI_CCR_ISIZE_B_0X1		(0x1u<<4)
#define	HSPI_CCR_ISIZE_B_0X2		(0x2u<<4)
#define	HSPI_CCR_ISIZE_B_0X3		(0x3u<<4)
#define	HSPI_CCR_IDTR_B_0X0			(0x0u<<3)
#define	HSPI_CCR_IDTR_B_0X1			(0x1u<<3)
#define	HSPI_CCR_IMODE_B_0X0		(0x0u<<0)
#define	HSPI_CCR_IMODE_B_0X1		(0x1u<<0)
#define	HSPI_CCR_IMODE_B_0X2		(0x2u<<0)
#define	HSPI_CCR_IMODE_B_0X3		(0x3u<<0)
#define	HSPI_CCR_IMODE_B_0X4		(0x4u<<0)

// TCR Configuration

#define	HSPI_TCR_SSHIFT				(0x1u<<30)
#define	HSPI_TCR_DHQC				(0x1u<<28)
#define	HSPI_TCR_DCYC				(0x1Fu<<0)
#define	HSPI_TCR_DCYC_0				(0x1u<<0)
#define	HSPI_TCR_SSHIFT_B_0X0		(0x0u<<30)
#define	HSPI_TCR_SSHIFT_B_0X1		(0x1u<<30)
#define	HSPI_TCR_DHQC_B_0X0			(0x0u<<28)
#define	HSPI_TCR_DHQC_B_0X1			(0x1u<<28)

// IR Configuration

#define	HSPI_IR_INSTRUCTION			(0xFFFFFFFFu<<0)
#define	HSPI_IR_INSTRUCTION_0		(0x1u<<0)

// ABR Configuration

#define	HSPI_ABR_ALTERNATE			(0xFFFFFFFFu<<0)
#define	HSPI_ABR_ALTERNATE_0		(0x1u<<0)

// LPTR Configuration

#define	HSPI_LPTR_TIMEOUT			(0xFFFFu<<0)
#define	HSPI_LPTR_TIMEOUT_0			(0x1u<<0)

// WPCCR Configuration

#define	HSPI_WPCCR_DQSE				(0x1u<<29)
#define	HSPI_WPCCR_DDTR				(0x1u<<27)
#define	HSPI_WPCCR_DMODE			(0x7u<<24)
#define	HSPI_WPCCR_DMODE_0			(0x1u<<24)
#define	HSPI_WPCCR_ABSIZE			(0x3u<<20)
#define	HSPI_WPCCR_ABSIZE_0			(0x1u<<20)
#define	HSPI_WPCCR_ABDTR			(0x1u<<19)
#define	HSPI_WPCCR_ABMODE			(0x7u<<16)
#define	HSPI_WPCCR_ABMODE_0			(0x1u<<16)
#define	HSPI_WPCCR_ADSIZE			(0x3u<<12)
#define	HSPI_WPCCR_ADSIZE_0			(0x1u<<12)
#define	HSPI_WPCCR_ADDTR			(0x1u<<11)
#define	HSPI_WPCCR_ADMODE			(0x7u<<8)
#define	HSPI_WPCCR_ADMODE_0			(0x1u<<8)
#define	HSPI_WPCCR_ISIZE			(0x3u<<4)
#define	HSPI_WPCCR_ISIZE_0			(0x1u<<4)
#define	HSPI_WPCCR_IDTR				(0x1u<<3)
#define	HSPI_WPCCR_IMODE			(0x7u<<0)
#define	HSPI_WPCCR_IMODE_0			(0x1u<<0)
#define	HSPI_WPCCR_DQSE_B_0X0		(0x0u<<29)
#define	HSPI_WPCCR_DQSE_B_0X1		(0x1u<<29)
#define	HSPI_WPCCR_DDTR_B_0X0		(0x0u<<27)
#define	HSPI_WPCCR_DDTR_B_0X1		(0x1u<<27)
#define	HSPI_WPCCR_DMODE_B_0X0		(0x0u<<24)
#define	HSPI_WPCCR_DMODE_B_0X1		(0x1u<<24)
#define	HSPI_WPCCR_DMODE_B_0X2		(0x2u<<24)
#define	HSPI_WPCCR_DMODE_B_0X3		(0x3u<<24)
#define	HSPI_WPCCR_DMODE_B_0X4		(0x4u<<24)
#define	HSPI_WPCCR_ABSIZE_B_0X0		(0x0u<<20)
#define	HSPI_WPCCR_ABSIZE_B_0X1		(0x1u<<20)
#define	HSPI_WPCCR_ABSIZE_B_0X2		(0x2u<<20)
#define	HSPI_WPCCR_ABSIZE_B_0X3		(0x3u<<20)
#define	HSPI_WPCCR_ABDTR_B_0X0		(0x0u<<19)
#define	HSPI_WPCCR_ABDTR_B_0X1		(0x1u<<19)
#define	HSPI_WPCCR_ABMODE_B_0X0		(0x0u<<16)
#define	HSPI_WPCCR_ABMODE_B_0X1		(0x1u<<16)
#define	HSPI_WPCCR_ABMODE_B_0X2		(0x2u<<16)
#define	HSPI_WPCCR_ABMODE_B_0X3		(0x3u<<16)
#define	HSPI_WPCCR_ABMODE_B_0X4		(0x4u<<16)
#define	HSPI_WPCCR_ABMODE_B_0X5		(0x5u<<16)
#define	HSPI_WPCCR_ADSIZE_B_0X0		(0x0u<<12)
#define	HSPI_WPCCR_ADSIZE_B_0X1		(0x1u<<12)
#define	HSPI_WPCCR_ADSIZE_B_0X2		(0x2u<<12)
#define	HSPI_WPCCR_ADSIZE_B_0X3		(0x3u<<12)
#define	HSPI_WPCCR_ADDTR_B_0X0		(0x0u<<11)
#define	HSPI_WPCCR_ADDTR_B_0X1		(0x1u<<11)
#define	HSPI_WPCCR_ADMODE_B_0X0		(0x0u<<8)
#define	HSPI_WPCCR_ADMODE_B_0X1		(0x1u<<8)
#define	HSPI_WPCCR_ADMODE_B_0X2		(0x2u<<8)
#define	HSPI_WPCCR_ADMODE_B_0X3		(0x3u<<8)
#define	HSPI_WPCCR_ADMODE_B_0X4		(0x4u<<8)
#define	HSPI_WPCCR_ISIZE_B_0X0		(0x0u<<4)
#define	HSPI_WPCCR_ISIZE_B_0X1		(0x1u<<4)
#define	HSPI_WPCCR_ISIZE_B_0X2		(0x2u<<4)
#define	HSPI_WPCCR_ISIZE_B_0X3		(0x3u<<4)
#define	HSPI_WPCCR_IDTR_B_0X0		(0x0u<<3)
#define	HSPI_WPCCR_IDTR_B_0X1		(0x1u<<3)
#define	HSPI_WPCCR_IMODE_B_0X0		(0x0u<<0)
#define	HSPI_WPCCR_IMODE_B_0X1		(0x1u<<0)
#define	HSPI_WPCCR_IMODE_B_0X2		(0x2u<<0)
#define	HSPI_WPCCR_IMODE_B_0X3		(0x3u<<0)
#define	HSPI_WPCCR_IMODE_B_0X4		(0x4u<<0)

// WPTCR Configuration

#define	HSPI_WPTCR_SSHIFT			(0x1u<<30)
#define	HSPI_WPTCR_DHQC				(0x1u<<28)
#define	HSPI_WPTCR_DCYC				(0x1Fu<<0)
#define	HSPI_WPTCR_DCYC_0			(0x1u<<0)
#define	HSPI_WPTCR_SSHIFT_B_0X0		(0x0u<<30)
#define	HSPI_WPTCR_SSHIFT_B_0X1		(0x1u<<30)
#define	HSPI_WPTCR_DHQC_B_0X0		(0x0u<<28)
#define	HSPI_WPTCR_DHQC_B_0X1		(0x1u<<28)

// WPIR Configuration

#define	HSPI_WPIR_INSTRUCTION		(0xFFFFFFFFu<<0)
#define	HSPI_WPIR_INSTRUCTION_0		(0x1u<<0)

// WPABR Configuration

#define	HSPI_WPABR_ALTERNATE		(0xFFFFFFFFu<<0)
#define	HSPI_WPABR_ALTERNATE_0		(0x1u<<0)

// WCCR Configuration

#define	HSPI_WCCR_DQSE				(0x1u<<29)
#define	HSPI_WCCR_DDTR				(0x1u<<27)
#define	HSPI_WCCR_DMODE				(0x7u<<24)
#define	HSPI_WCCR_DMODE_0			(0x1u<<24)
#define	HSPI_WCCR_ABSIZE			(0x3u<<20)
#define	HSPI_WCCR_ABSIZE_0			(0x1u<<20)
#define	HSPI_WCCR_ABDTR				(0x1u<<19)
#define	HSPI_WCCR_ABMODE			(0x7u<<16)
#define	HSPI_WCCR_ABMODE_0			(0x1u<<16)
#define	HSPI_WCCR_ADSIZE			(0x3u<<12)
#define	HSPI_WCCR_ADSIZE_0			(0x1u<<12)
#define	HSPI_WCCR_ADDTR				(0x1u<<11)
#define	HSPI_WCCR_ADMODE			(0x7u<<8)
#define	HSPI_WCCR_ADMODE_0			(0x1u<<8)
#define	HSPI_WCCR_ISIZE				(0x3u<<4)
#define	HSPI_WCCR_ISIZE_0			(0x1u<<4)
#define	HSPI_WCCR_IDTR				(0x1u<<3)
#define	HSPI_WCCR_IMODE				(0x7u<<0)
#define	HSPI_WCCR_IMODE_0			(0x1u<<0)
#define	HSPI_WCCR_DQSE_B_0X0		(0x0u<<29)
#define	HSPI_WCCR_DQSE_B_0X1		(0x1u<<29)
#define	HSPI_WCCR_DDTR_B_0X0		(0x0u<<27)
#define	HSPI_WCCR_DDTR_B_0X1		(0x1u<<27)
#define	HSPI_WCCR_DMODE_B_0X0		(0x0u<<24)
#define	HSPI_WCCR_DMODE_B_0X1		(0x1u<<24)
#define	HSPI_WCCR_DMODE_B_0X2		(0x2u<<24)
#define	HSPI_WCCR_DMODE_B_0X3		(0x3u<<24)
#define	HSPI_WCCR_DMODE_B_0X4		(0x4u<<24)
#define	HSPI_WCCR_DMODE_B_0X5		(0x5u<<24)
#define	HSPI_WCCR_ABSIZE_B_0X0		(0x0u<<20)
#define	HSPI_WCCR_ABSIZE_B_0X1		(0x1u<<20)
#define	HSPI_WCCR_ABSIZE_B_0X2		(0x2u<<20)
#define	HSPI_WCCR_ABSIZE_B_0X3		(0x3u<<20)
#define	HSPI_WCCR_ABDTR_B_0X0		(0x0u<<19)
#define	HSPI_WCCR_ABDTR_B_0X1		(0x1u<<19)
#define	HSPI_WCCR_ABMODE_B_0X0		(0x0u<<16)
#define	HSPI_WCCR_ABMODE_B_0X1		(0x1u<<16)
#define	HSPI_WCCR_ABMODE_B_0X2		(0x2u<<16)
#define	HSPI_WCCR_ABMODE_B_0X3		(0x3u<<16)
#define	HSPI_WCCR_ABMODE_B_0X4		(0x4u<<16)
#define	HSPI_WCCR_ADSIZE_B_0X0		(0x0u<<12)
#define	HSPI_WCCR_ADSIZE_B_0X1		(0x1u<<12)
#define	HSPI_WCCR_ADSIZE_B_0X2		(0x2u<<12)
#define	HSPI_WCCR_ADSIZE_B_0X3		(0x3u<<12)
#define	HSPI_WCCR_ADDTR_B_0X0		(0x0u<<11)
#define	HSPI_WCCR_ADDTR_B_0X1		(0x1u<<11)
#define	HSPI_WCCR_ADMODE_B_0X0		(0x0u<<8)
#define	HSPI_WCCR_ADMODE_B_0X1		(0x1u<<8)
#define	HSPI_WCCR_ADMODE_B_0X2		(0x2u<<8)
#define	HSPI_WCCR_ADMODE_B_0X3		(0x3u<<8)
#define	HSPI_WCCR_ADMODE_B_0X4		(0x4u<<8)
#define	HSPI_WCCR_ISIZE_B_0X0		(0x0u<<4)
#define	HSPI_WCCR_ISIZE_B_0X1		(0x1u<<4)
#define	HSPI_WCCR_ISIZE_B_0X2		(0x2u<<4)
#define	HSPI_WCCR_ISIZE_B_0X3		(0x3u<<4)
#define	HSPI_WCCR_IDTR_B_0X0		(0x0u<<3)
#define	HSPI_WCCR_IDTR_B_0X1		(0x1u<<3)
#define	HSPI_WCCR_IMODE_B_0X0		(0x0u<<0)
#define	HSPI_WCCR_IMODE_B_0X1		(0x1u<<0)
#define	HSPI_WCCR_IMODE_B_0X2		(0x2u<<0)
#define	HSPI_WCCR_IMODE_B_0X3		(0x3u<<0)
#define	HSPI_WCCR_IMODE_B_0X4		(0x4u<<0)

// WTCR Configuration

#define	HSPI_WTCR_DCYC				(0x1Fu<<0)
#define	HSPI_WTCR_DCYC_0			(0x1u<<0)

// WIR Configuration

#define	HSPI_WIR_INSTRUCTION		(0xFFFFFFFFu<<0)
#define	HSPI_WIR_INSTRUCTION_0		(0x1u<<0)

// WABR Configuration

#define	HSPI_WABR_ALTERNATE			(0xFFFFFFFFu<<0)
#define	HSPI_WABR_ALTERNATE_0		(0x1u<<0)

// HLCR Configuration

#define	HSPI_HLCR_TRWR				(0xFFu<<16)
#define	HSPI_HLCR_TRWR_0			(0x1u<<16)
#define	HSPI_HLCR_TACC				(0xFFu<<8)
#define	HSPI_HLCR_TACC_0			(0x1u<<8)
#define	HSPI_HLCR_WZL				(0x1u<<1)
#define	HSPI_HLCR_LM				(0x1u<<0)
#define	HSPI_HLCR_WZL_B_0X0			(0x0u<<1)
#define	HSPI_HLCR_WZL_B_0X1			(0x1u<<1)
#define	HSPI_HLCR_LM_B_0X0			(0x0u<<0)
#define	HSPI_HLCR_LM_B_0X1			(0x1u<<0)

// CALFCR Configuration

#define	HSPI_CALFCR_CALMAX			(0x1u<<31)
#define	HSPI_CALFCR_COARSE			(0x1Fu<<16)
#define	HSPI_CALFCR_COARSE_0		(0x1u<<16)
#define	HSPI_CALFCR_FINE			(0x7Fu<<0)
#define	HSPI_CALFCR_FINE_0			(0x1u<<0)

// CALMR Configuration

#define	HSPI_CALMR_COARSE			(0x1Fu<<16)
#define	HSPI_CALMR_COARSE_0			(0x1u<<16)
#define	HSPI_CALMR_FINE				(0x7Fu<<0)
#define	HSPI_CALMR_FINE_0			(0x1u<<0)

// CALSOR Configuration

#define	HSPI_CALSOR_COARSE			(0x1Fu<<16)
#define	HSPI_CALSOR_COARSE_0		(0x1u<<16)
#define	HSPI_CALSOR_FINE			(0x7Fu<<0)
#define	HSPI_CALSOR_FINE_0			(0x1u<<0)

// CALSIR Configuration

#define	HSPI_CALSIR_COARSE			(0x1Fu<<16)
#define	HSPI_CALSIR_COARSE_0		(0x1u<<16)
#define	HSPI_CALSIR_FINE			(0x7Fu<<0)
#define	HSPI_CALSIR_FINE_0			(0x1u<<0)
