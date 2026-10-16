/*
; stm32U5Gx_pwr.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_pwr equates.
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

// PWR address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CR1;
	volatile	uint32_t	CR2;
	volatile	uint32_t	CR3;
	volatile	uint32_t	VOSR;
	volatile	uint32_t	SVMCR;
	volatile	uint32_t	WUCR1;
	volatile	uint32_t	WUCR2;
	volatile	uint32_t	WUCR3;
	volatile	uint32_t	BDCR1;
	volatile	uint32_t	BDCR2;
	volatile	uint32_t	DBPR;
	volatile	uint32_t	UCPDR;
	volatile	uint32_t	SECCFGR;
	volatile	uint32_t	PRIVCFGR;
	volatile	uint32_t	SR;
	volatile	uint32_t	SVMSR;
	volatile	uint32_t	BDSR;
	volatile	uint32_t	WUSR;
	volatile	uint32_t	WUSCR;
	volatile	uint32_t	APCR;
	volatile	uint32_t	PUCRA;
	volatile	uint32_t	PDCRA;
	volatile	uint32_t	PUCRB;
	volatile	uint32_t	PDCRB;
	volatile	uint32_t	PUCRC;
	volatile	uint32_t	PDCRC;
	volatile	uint32_t	PUCRD;
	volatile	uint32_t	PDCRD;
	volatile	uint32_t	PUCRE;
	volatile	uint32_t	PDCRE;
	volatile	uint32_t	PUCRF;
	volatile	uint32_t	PDCRF;
	volatile	uint32_t	PUCRG;
	volatile	uint32_t	PDCRG;
	volatile	uint32_t	PUCRH;
	volatile	uint32_t	PDCRH;
	volatile	uint32_t	PUCRI;
	volatile	uint32_t	PDCRI;
	volatile	uint32_t	PUCRJ;
	volatile	uint32_t	PDCRJ;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	CR4;
} PWR_TypeDef;

#if (defined(__cplusplus))
#define	PWR_NS	reinterpret_cast<PWR_TypeDef *>(0x46020800u)
#define	PWR_S	reinterpret_cast<PWR_TypeDef *>(0x56020800u)

#else
#define	PWR_NS	((PWR_TypeDef *)0x46020800u)
#define	PWR_S	((PWR_TypeDef *)0x56020800u)
#endif

// CR1 Configuration

#define	PWR_CR1_SRAM5PD				(0x1u<<12)
#define	PWR_CR1_SRAM4PD				(0x1u<<11)
#define	PWR_CR1_SRAM3PD				(0x1u<<10)
#define	PWR_CR1_SRAM2PD				(0x1u<<9)
#define	PWR_CR1_SRAM1PD				(0x1u<<8)
#define	PWR_CR1_ULPMEN				(0x1u<<7)
#define	PWR_CR1_RRSB2				(0x1u<<6)
#define	PWR_CR1_RRSB1				(0x1u<<5)
#define	PWR_CR1_LPMS				(0x7u<<0)
#define	PWR_CR1_LPMS_0				(0x1u<<0)
#define	PWR_CR1_SRAM5PD_B_0X0		(0x0u<<12)
#define	PWR_CR1_SRAM5PD_B_0X1		(0x1u<<12)
#define	PWR_CR1_SRAM4PD_B_0X0		(0x0u<<11)
#define	PWR_CR1_SRAM4PD_B_0X1		(0x1u<<11)
#define	PWR_CR1_SRAM3PD_B_0X0		(0x0u<<10)
#define	PWR_CR1_SRAM3PD_B_0X1		(0x1u<<10)
#define	PWR_CR1_SRAM2PD_B_0X0		(0x0u<<9)
#define	PWR_CR1_SRAM2PD_B_0X1		(0x1u<<9)
#define	PWR_CR1_SRAM1PD_B_0X0		(0x0u<<8)
#define	PWR_CR1_SRAM1PD_B_0X1		(0x1u<<8)
#define	PWR_CR1_ULPMEN_B_0X0		(0x0u<<7)
#define	PWR_CR1_ULPMEN_B_0X1		(0x1u<<7)
#define	PWR_CR1_RRSB2_B_0X0			(0x0u<<6)
#define	PWR_CR1_RRSB2_B_0X1			(0x1u<<6)
#define	PWR_CR1_RRSB1_B_0X0			(0x0u<<5)
#define	PWR_CR1_RRSB1_B_0X1			(0x1u<<5)
#define	PWR_CR1_LPMS_B_0X0			(0x0u<<0)
#define	PWR_CR1_LPMS_B_0X1			(0x1u<<0)
#define	PWR_CR1_LPMS_B_0X2			(0x2u<<0)
#define	PWR_CR1_LPMS_B_0X3			(0x3u<<0)

// CR2 Configuration

#define	PWR_CR2_SRDRUN				(0x1u<<31)
#define	PWR_CR2_DSIRAMPDS			(0x1u<<25)
#define	PWR_CR2_GPRAMPDS			(0x1u<<24)
#define	PWR_CR2_SRAM3PDS8			(0x1u<<23)
#define	PWR_CR2_SRAM3PDS7			(0x1u<<22)
#define	PWR_CR2_SRAM3PDS6			(0x1u<<21)
#define	PWR_CR2_SRAM3PDS5			(0x1u<<20)
#define	PWR_CR2_SRAM3PDS4			(0x1u<<19)
#define	PWR_CR2_SRAM3PDS3			(0x1u<<18)
#define	PWR_CR2_SRAM3PDS2			(0x1u<<17)
#define	PWR_CR2_SRAM3PDS1			(0x1u<<16)
#define	PWR_CR2_FLASHFWU			(0x1u<<14)
#define	PWR_CR2_SRAM4FWU			(0x1u<<13)
#define	PWR_CR2_PKARAMPDS			(0x1u<<12)
#define	PWR_CR2_PRAMPDS				(0x1u<<11)
#define	PWR_CR2_DMA2DRAMPDS			(0x1u<<10)
#define	PWR_CR2_DC1RAMPDS			(0x1u<<9)
#define	PWR_CR2_ICRAMPDS			(0x1u<<8)
#define	PWR_CR2_DC2RAMPDS			(0x1u<<7)
#define	PWR_CR2_SRAM4PDS			(0x1u<<6)
#define	PWR_CR2_SRAM2PDS2			(0x1u<<5)
#define	PWR_CR2_SRAM2PDS1			(0x1u<<4)
#define	PWR_CR2_SRAM1PDS3			(0x1u<<2)
#define	PWR_CR2_SRAM1PDS2			(0x1u<<1)
#define	PWR_CR2_SRAM1PDS1			(0x1u<<0)
#define	PWR_CR2_SRDRUN_B_0X0		(0x0u<<31)
#define	PWR_CR2_SRDRUN_B_0X1		(0x1u<<31)
#define	PWR_CR2_DSIRAMPDS_B_0X0		(0x0u<<25)
#define	PWR_CR2_DSIRAMPDS_B_0X1		(0x1u<<25)
#define	PWR_CR2_GPRAMPDS_B_0X0		(0x0u<<24)
#define	PWR_CR2_GPRAMPDS_B_0X1		(0x1u<<24)
#define	PWR_CR2_SRAM3PDS8_B_0X0		(0x0u<<23)
#define	PWR_CR2_SRAM3PDS8_B_0X1		(0x1u<<23)
#define	PWR_CR2_SRAM3PDS7_B_0X0		(0x0u<<22)
#define	PWR_CR2_SRAM3PDS7_B_0X1		(0x1u<<22)
#define	PWR_CR2_SRAM3PDS6_B_0X0		(0x0u<<21)
#define	PWR_CR2_SRAM3PDS6_B_0X1		(0x1u<<21)
#define	PWR_CR2_SRAM3PDS5_B_0X0		(0x0u<<20)
#define	PWR_CR2_SRAM3PDS5_B_0X1		(0x1u<<20)
#define	PWR_CR2_SRAM3PDS4_B_0X0		(0x0u<<19)
#define	PWR_CR2_SRAM3PDS4_B_0X1		(0x1u<<19)
#define	PWR_CR2_SRAM3PDS3_B_0X0		(0x0u<<18)
#define	PWR_CR2_SRAM3PDS3_B_0X1		(0x1u<<18)
#define	PWR_CR2_SRAM3PDS2_B_0X0		(0x0u<<17)
#define	PWR_CR2_SRAM3PDS2_B_0X1		(0x1u<<17)
#define	PWR_CR2_SRAM3PDS1_B_0X0		(0x0u<<16)
#define	PWR_CR2_SRAM3PDS1_B_0X1		(0x1u<<16)
#define	PWR_CR2_FLASHFWU_B_0X0		(0x0u<<14)
#define	PWR_CR2_FLASHFWU_B_0X1		(0x1u<<14)
#define	PWR_CR2_SRAM4FWU_B_0X0		(0x0u<<13)
#define	PWR_CR2_SRAM4FWU_B_0X1		(0x1u<<13)
#define	PWR_CR2_PKARAMPDS_B_0X0		(0x0u<<12)
#define	PWR_CR2_PKARAMPDS_B_0X1		(0x1u<<12)
#define	PWR_CR2_PRAMPDS_B_0X0		(0x0u<<11)
#define	PWR_CR2_PRAMPDS_B_0X1		(0x1u<<11)
#define	PWR_CR2_DMA2DRAMPDS_B_0X0	(0x0u<<10)
#define	PWR_CR2_DMA2DRAMPDS_B_0X1	(0x1u<<10)
#define	PWR_CR2_DC1RAMPDS_B_0X0		(0x0u<<9)
#define	PWR_CR2_DC1RAMPDS_B_0X1		(0x1u<<9)
#define	PWR_CR2_ICRAMPDS_B_0X0		(0x0u<<8)
#define	PWR_CR2_ICRAMPDS_B_0X1		(0x1u<<8)
#define	PWR_CR2_DC2RAMPDS_B_0X0		(0x0u<<7)
#define	PWR_CR2_DC2RAMPDS_B_0X1		(0x1u<<7)
#define	PWR_CR2_SRAM4PDS_B_0X0		(0x0u<<6)
#define	PWR_CR2_SRAM4PDS_B_0X1		(0x1u<<6)
#define	PWR_CR2_SRAM2PDS2_B_0X0		(0x0u<<5)
#define	PWR_CR2_SRAM2PDS2_B_0X1		(0x1u<<5)
#define	PWR_CR2_SRAM2PDS1_B_0X0		(0x0u<<4)
#define	PWR_CR2_SRAM2PDS1_B_0X1		(0x1u<<4)
#define	PWR_CR2_SRAM1PDS3_B_0X0		(0x0u<<2)
#define	PWR_CR2_SRAM1PDS3_B_0X1		(0x1u<<2)
#define	PWR_CR2_SRAM1PDS2_B_0X0		(0x0u<<1)
#define	PWR_CR2_SRAM1PDS2_B_0X1		(0x1u<<1)
#define	PWR_CR2_SRAM1PDS1_B_0X0		(0x0u<<0)
#define	PWR_CR2_SRAM1PDS1_B_0X1		(0x1u<<0)

// CR3 Configuration

#define	PWR_CR3_FSTEN				(0x1u<<2)
#define	PWR_CR3_REGSEL				(0x1u<<1)
#define	PWR_CR3_FSTEN_B_0X0			(0x0u<<2)
#define	PWR_CR3_FSTEN_B_0X1			(0x1u<<2)
#define	PWR_CR3_REGSEL_B_0X0		(0x0u<<1)
#define	PWR_CR3_REGSEL_B_0X1		(0x1u<<1)

// VOSR Configuration

#define	PWR_VOSR_USBBOOSTEN			(0x1u<<20)
#define	PWR_VOSR_USBPWREN			(0x1u<<19)
#define	PWR_VOSR_BOOSTEN			(0x1u<<18)
#define	PWR_VOSR_VOS				(0x3u<<16)
#define	PWR_VOSR_VOS_0				(0x1u<<16)
#define	PWR_VOSR_VOSRDY				(0x1u<<15)
#define	PWR_VOSR_BOOSTRDY			(0x1u<<14)
#define	PWR_VOSR_USBBOOSTRDY		(0x1u<<13)
#define	PWR_VOSR_USBBOOSTEN_B_0X0	(0x0u<<20)
#define	PWR_VOSR_USBBOOSTEN_B_0X1	(0x1u<<20)
#define	PWR_VOSR_USBPWREN_B_0X0		(0x0u<<19)
#define	PWR_VOSR_USBPWREN_B_0X1		(0x1u<<19)
#define	PWR_VOSR_BOOSTEN_B_0X0		(0x0u<<18)
#define	PWR_VOSR_BOOSTEN_B_0X1		(0x1u<<18)
#define	PWR_VOSR_VOS_B_0X0			(0x0u<<16)
#define	PWR_VOSR_VOS_B_0X1			(0x1u<<16)
#define	PWR_VOSR_VOS_B_0X2			(0x2u<<16)
#define	PWR_VOSR_VOS_B_0X3			(0x3u<<16)
#define	PWR_VOSR_VOSRDY_B_0X0		(0x0u<<15)
#define	PWR_VOSR_VOSRDY_B_0X1		(0x1u<<15)
#define	PWR_VOSR_BOOSTRDY_B_0X0		(0x0u<<14)
#define	PWR_VOSR_BOOSTRDY_B_0X1		(0x1u<<14)
#define	PWR_VOSR_USBBOOSTRDY_B_0X0	(0x0u<<13)
#define	PWR_VOSR_USBBOOSTRDY_B_0X1	(0x1u<<13)

// SVMCR Configuration

#define	PWR_SVMCR_ASV				(0x1u<<30)
#define	PWR_SVMCR_IO2SV				(0x1u<<29)
#define	PWR_SVMCR_USV				(0x1u<<28)
#define	PWR_SVMCR_AVM2EN			(0x1u<<27)
#define	PWR_SVMCR_AVM1EN			(0x1u<<26)
#define	PWR_SVMCR_IO2VMEN			(0x1u<<25)
#define	PWR_SVMCR_UVMEN				(0x1u<<24)
#define	PWR_SVMCR_PVDLS				(0x7u<<5)
#define	PWR_SVMCR_PVDLS_0			(0x1u<<5)
#define	PWR_SVMCR_PVDE				(0x1u<<4)
#define	PWR_SVMCR_ASV_B_0X0			(0x0u<<30)
#define	PWR_SVMCR_ASV_B_0X1			(0x1u<<30)
#define	PWR_SVMCR_IO2SV_B_0X0		(0x0u<<29)
#define	PWR_SVMCR_IO2SV_B_0X1		(0x1u<<29)
#define	PWR_SVMCR_USV_B_0X0			(0x0u<<28)
#define	PWR_SVMCR_USV_B_0X1			(0x1u<<28)
#define	PWR_SVMCR_AVM2EN_B_0X0		(0x0u<<27)
#define	PWR_SVMCR_AVM2EN_B_0X1		(0x1u<<27)
#define	PWR_SVMCR_AVM1EN_B_0X0		(0x0u<<26)
#define	PWR_SVMCR_AVM1EN_B_0X1		(0x1u<<26)
#define	PWR_SVMCR_IO2VMEN_B_0X0		(0x0u<<25)
#define	PWR_SVMCR_IO2VMEN_B_0X1		(0x1u<<25)
#define	PWR_SVMCR_UVMEN_B_0X0		(0x0u<<24)
#define	PWR_SVMCR_UVMEN_B_0X1		(0x1u<<24)
#define	PWR_SVMCR_PVDLS_B_0X0		(0x0u<<5)
#define	PWR_SVMCR_PVDLS_B_0X1		(0x1u<<5)
#define	PWR_SVMCR_PVDLS_B_0X2		(0x2u<<5)
#define	PWR_SVMCR_PVDLS_B_0X3		(0x3u<<5)
#define	PWR_SVMCR_PVDLS_B_0X4		(0x4u<<5)
#define	PWR_SVMCR_PVDLS_B_0X5		(0x5u<<5)
#define	PWR_SVMCR_PVDLS_B_0X6		(0x6u<<5)
#define	PWR_SVMCR_PVDLS_B_0X7		(0x7u<<5)
#define	PWR_SVMCR_PVDE_B_0X0		(0x0u<<4)
#define	PWR_SVMCR_PVDE_B_0X1		(0x1u<<4)

// WUCR1 Configuration

#define	PWR_WUCR1_WUPEN8			(0x1u<<7)
#define	PWR_WUCR1_WUPEN7			(0x1u<<6)
#define	PWR_WUCR1_WUPEN6			(0x1u<<5)
#define	PWR_WUCR1_WUPEN5			(0x1u<<4)
#define	PWR_WUCR1_WUPEN4			(0x1u<<3)
#define	PWR_WUCR1_WUPEN3			(0x1u<<2)
#define	PWR_WUCR1_WUPEN2			(0x1u<<1)
#define	PWR_WUCR1_WUPEN1			(0x1u<<0)
#define	PWR_WUCR1_WUPEN8_B_0X0		(0x0u<<7)
#define	PWR_WUCR1_WUPEN8_B_0X1		(0x1u<<7)
#define	PWR_WUCR1_WUPEN7_B_0X0		(0x0u<<6)
#define	PWR_WUCR1_WUPEN7_B_0X1		(0x1u<<6)
#define	PWR_WUCR1_WUPEN6_B_0X0		(0x0u<<5)
#define	PWR_WUCR1_WUPEN6_B_0X1		(0x1u<<5)
#define	PWR_WUCR1_WUPEN5_B_0X0		(0x0u<<4)
#define	PWR_WUCR1_WUPEN5_B_0X1		(0x1u<<4)
#define	PWR_WUCR1_WUPEN4_B_0X0		(0x0u<<3)
#define	PWR_WUCR1_WUPEN4_B_0X1		(0x1u<<3)
#define	PWR_WUCR1_WUPEN3_B_0X0		(0x0u<<2)
#define	PWR_WUCR1_WUPEN3_B_0X1		(0x1u<<2)
#define	PWR_WUCR1_WUPEN2_B_0X0		(0x0u<<1)
#define	PWR_WUCR1_WUPEN2_B_0X1		(0x1u<<1)
#define	PWR_WUCR1_WUPEN1_B_0X0		(0x0u<<0)
#define	PWR_WUCR1_WUPEN1_B_0X1		(0x1u<<0)

// WUCR2 Configuration

#define	PWR_WUCR2_WUPP8				(0x1u<<7)
#define	PWR_WUCR2_WUPP7				(0x1u<<6)
#define	PWR_WUCR2_WUPP6				(0x1u<<5)
#define	PWR_WUCR2_WUPP5				(0x1u<<4)
#define	PWR_WUCR2_WUPP4				(0x1u<<3)
#define	PWR_WUCR2_WUPP3				(0x1u<<2)
#define	PWR_WUCR2_WUPP2				(0x1u<<1)
#define	PWR_WUCR2_WUPP1				(0x1u<<0)
#define	PWR_WUCR2_WUPP8_B_0X0		(0x0u<<7)
#define	PWR_WUCR2_WUPP8_B_0X1		(0x1u<<7)
#define	PWR_WUCR2_WUPP7_B_0X0		(0x0u<<6)
#define	PWR_WUCR2_WUPP7_B_0X1		(0x1u<<6)
#define	PWR_WUCR2_WUPP6_B_0X0		(0x0u<<5)
#define	PWR_WUCR2_WUPP6_B_0X1		(0x1u<<5)
#define	PWR_WUCR2_WUPP5_B_0X0		(0x0u<<4)
#define	PWR_WUCR2_WUPP5_B_0X1		(0x1u<<4)
#define	PWR_WUCR2_WUPP4_B_0X0		(0x0u<<3)
#define	PWR_WUCR2_WUPP4_B_0X1		(0x1u<<3)
#define	PWR_WUCR2_WUPP3_B_0X0		(0x0u<<2)
#define	PWR_WUCR2_WUPP3_B_0X1		(0x1u<<2)
#define	PWR_WUCR2_WUPP2_B_0X0		(0x0u<<1)
#define	PWR_WUCR2_WUPP2_B_0X1		(0x1u<<1)
#define	PWR_WUCR2_WUPP1_B_0X0		(0x0u<<0)
#define	PWR_WUCR2_WUPP1_B_0X1		(0x1u<<0)

// WUCR3 Configuration

#define	PWR_WUCR3_WUSEL8			(0x3u<<14)
#define	PWR_WUCR3_WUSEL8_0			(0x1u<<14)
#define	PWR_WUCR3_WUSEL7			(0x3u<<12)
#define	PWR_WUCR3_WUSEL7_0			(0x1u<<12)
#define	PWR_WUCR3_WUSEL6			(0x3u<<10)
#define	PWR_WUCR3_WUSEL6_0			(0x1u<<10)
#define	PWR_WUCR3_WUSEL5			(0x3u<<8)
#define	PWR_WUCR3_WUSEL5_0			(0x1u<<8)
#define	PWR_WUCR3_WUSEL4			(0x3u<<6)
#define	PWR_WUCR3_WUSEL4_0			(0x1u<<6)
#define	PWR_WUCR3_WUSEL3			(0x3u<<4)
#define	PWR_WUCR3_WUSEL3_0			(0x1u<<4)
#define	PWR_WUCR3_WUSEL2			(0x3u<<2)
#define	PWR_WUCR3_WUSEL2_0			(0x1u<<2)
#define	PWR_WUCR3_WUSEL1			(0x3u<<0)
#define	PWR_WUCR3_WUSEL1_0			(0x1u<<0)
#define	PWR_WUCR3_WUSEL8_B_0X0		(0x0u<<14)
#define	PWR_WUCR3_WUSEL8_B_0X1		(0x1u<<14)
#define	PWR_WUCR3_WUSEL8_B_0X2		(0x2u<<14)
#define	PWR_WUCR3_WUSEL8_B_0X3		(0x3u<<14)
#define	PWR_WUCR3_WUSEL7_B_0X0		(0x0u<<12)
#define	PWR_WUCR3_WUSEL7_B_0X1		(0x1u<<12)
#define	PWR_WUCR3_WUSEL7_B_0X2		(0x2u<<12)
#define	PWR_WUCR3_WUSEL7_B_0X3		(0x3u<<12)
#define	PWR_WUCR3_WUSEL6_B_0X0		(0x0u<<10)
#define	PWR_WUCR3_WUSEL6_B_0X1		(0x1u<<10)
#define	PWR_WUCR3_WUSEL6_B_0X2		(0x2u<<10)
#define	PWR_WUCR3_WUSEL6_B_0X3		(0x3u<<10)
#define	PWR_WUCR3_WUSEL5_B_0X0		(0x0u<<8)
#define	PWR_WUCR3_WUSEL5_B_0X1		(0x1u<<8)
#define	PWR_WUCR3_WUSEL5_B_0X2		(0x2u<<8)
#define	PWR_WUCR3_WUSEL5_B_0X3		(0x3u<<8)
#define	PWR_WUCR3_WUSEL4_B_0X0		(0x0u<<6)
#define	PWR_WUCR3_WUSEL4_B_0X1		(0x1u<<6)
#define	PWR_WUCR3_WUSEL4_B_0X2		(0x2u<<6)
#define	PWR_WUCR3_WUSEL4_B_0X3		(0x3u<<6)
#define	PWR_WUCR3_WUSEL3_B_0X0		(0x0u<<4)
#define	PWR_WUCR3_WUSEL3_B_0X1		(0x1u<<4)
#define	PWR_WUCR3_WUSEL3_B_0X2		(0x2u<<4)
#define	PWR_WUCR3_WUSEL3_B_0X3		(0x3u<<4)
#define	PWR_WUCR3_WUSEL2_B_0X0		(0x0u<<2)
#define	PWR_WUCR3_WUSEL2_B_0X1		(0x1u<<2)
#define	PWR_WUCR3_WUSEL2_B_0X2		(0x2u<<2)
#define	PWR_WUCR3_WUSEL2_B_0X3		(0x3u<<2)
#define	PWR_WUCR3_WUSEL1_B_0X0		(0x0u<<0)
#define	PWR_WUCR3_WUSEL1_B_0X1		(0x1u<<0)
#define	PWR_WUCR3_WUSEL1_B_0X2		(0x2u<<0)
#define	PWR_WUCR3_WUSEL1_B_0X3		(0x3u<<0)

// BDCR1 Configuration

#define	PWR_BDCR1_MONEN				(0x1u<<4)
#define	PWR_BDCR1_BREN				(0x1u<<0)
#define	PWR_BDCR1_MONEN_B_0X0		(0x0u<<4)
#define	PWR_BDCR1_MONEN_B_0X1		(0x1u<<4)
#define	PWR_BDCR1_BREN_B_0X0		(0x0u<<0)
#define	PWR_BDCR1_BREN_B_0X1		(0x1u<<0)

// BDCR2 Configuration

#define	PWR_BDCR2_VBRS				(0x1u<<1)
#define	PWR_BDCR2_VBE				(0x1u<<0)
#define	PWR_BDCR2_VBRS_B_0X0		(0x0u<<1)
#define	PWR_BDCR2_VBRS_B_0X1		(0x1u<<1)
#define	PWR_BDCR2_VBE_B_0X0			(0x0u<<0)
#define	PWR_BDCR2_VBE_B_0X1			(0x1u<<0)

// DBPR Configuration

#define	PWR_DBPR_DBP				(0x1u<<0)
#define	PWR_DBPR_DBP_B_0X0			(0x0u<<0)
#define	PWR_DBPR_DBP_B_0X1			(0x1u<<0)

// UCPDR Configuration

#define	PWR_UCPDR_UCPD_STBY			(0x1u<<1)
#define	PWR_UCPDR_UCPD_DBDIS		(0x1u<<0)
#define	PWR_UCPDR_UCPD_DBDIS_B_0X0	(0x0u<<0)
#define	PWR_UCPDR_UCPD_DBDIS_B_0X1	(0x1u<<0)

// SECCFGR Configuration

#define	PWR_SECCFGR_APCSEC			(0x1u<<15)
#define	PWR_SECCFGR_VBSEC			(0x1u<<14)
#define	PWR_SECCFGR_VDMSEC			(0x1u<<13)
#define	PWR_SECCFGR_LPMSEC			(0x1u<<12)
#define	PWR_SECCFGR_WUP8SEC			(0x1u<<7)
#define	PWR_SECCFGR_WUP7SEC			(0x1u<<6)
#define	PWR_SECCFGR_WUP6SEC			(0x1u<<5)
#define	PWR_SECCFGR_WUP5SEC			(0x1u<<4)
#define	PWR_SECCFGR_WUP4SEC			(0x1u<<3)
#define	PWR_SECCFGR_WUP3SEC			(0x1u<<2)
#define	PWR_SECCFGR_WUP2SEC			(0x1u<<1)
#define	PWR_SECCFGR_WUP1SEC			(0x1u<<0)
#define	PWR_SECCFGR_APCSEC_B_0X0	(0x0u<<15)
#define	PWR_SECCFGR_APCSEC_B_0X1	(0x1u<<15)
#define	PWR_SECCFGR_VBSEC_B_0X0		(0x0u<<14)
#define	PWR_SECCFGR_VBSEC_B_0X1		(0x1u<<14)
#define	PWR_SECCFGR_VDMSEC_B_0X0	(0x0u<<13)
#define	PWR_SECCFGR_VDMSEC_B_0X1	(0x1u<<13)
#define	PWR_SECCFGR_LPMSEC_B_0X0	(0x0u<<12)
#define	PWR_SECCFGR_LPMSEC_B_0X1	(0x1u<<12)
#define	PWR_SECCFGR_WUP8SEC_B_0X0	(0x0u<<7)
#define	PWR_SECCFGR_WUP8SEC_B_0X1	(0x1u<<7)
#define	PWR_SECCFGR_WUP7SEC_B_0X0	(0x0u<<6)
#define	PWR_SECCFGR_WUP7SEC_B_0X1	(0x1u<<6)
#define	PWR_SECCFGR_WUP6SEC_B_0X0	(0x0u<<5)
#define	PWR_SECCFGR_WUP6SEC_B_0X1	(0x1u<<5)
#define	PWR_SECCFGR_WUP5SEC_B_0X0	(0x0u<<4)
#define	PWR_SECCFGR_WUP5SEC_B_0X1	(0x1u<<4)
#define	PWR_SECCFGR_WUP4SEC_B_0X0	(0x0u<<3)
#define	PWR_SECCFGR_WUP4SEC_B_0X1	(0x1u<<3)
#define	PWR_SECCFGR_WUP3SEC_B_0X0	(0x0u<<2)
#define	PWR_SECCFGR_WUP3SEC_B_0X1	(0x1u<<2)
#define	PWR_SECCFGR_WUP2SEC_B_0X0	(0x0u<<1)
#define	PWR_SECCFGR_WUP2SEC_B_0X1	(0x1u<<1)
#define	PWR_SECCFGR_WUP1SEC_B_0X0	(0x0u<<0)
#define	PWR_SECCFGR_WUP1SEC_B_0X1	(0x1u<<0)

// PRIVCFGR Configuration

#define	PWR_PRIVCFGR_NSPRIV			(0x1u<<1)
#define	PWR_PRIVCFGR_SPRIV			(0x1u<<0)
#define	PWR_PRIVCFGR_NSPRIV_B_0X0	(0x0u<<1)
#define	PWR_PRIVCFGR_NSPRIV_B_0X1	(0x1u<<1)
#define	PWR_PRIVCFGR_SPRIV_B_0X0	(0x0u<<0)
#define	PWR_PRIVCFGR_SPRIV_B_0X1	(0x1u<<0)

// SR Configuration

#define	PWR_SR_SBF					(0x1u<<2)
#define	PWR_SR_STOPF				(0x1u<<1)
#define	PWR_SR_CSSF					(0x1u<<0)
#define	PWR_SR_SBF_B_0X0			(0x0u<<2)
#define	PWR_SR_SBF_B_0X1			(0x1u<<2)
#define	PWR_SR_STOPF_B_0X0			(0x0u<<1)
#define	PWR_SR_STOPF_B_0X1			(0x1u<<1)

// SVMSR Configuration

#define	PWR_SVMSR_VDDA2RDY			(0x1u<<27)
#define	PWR_SVMSR_VDDA1RDY			(0x1u<<26)
#define	PWR_SVMSR_VDDIO2RDY			(0x1u<<25)
#define	PWR_SVMSR_VDDUSBRDY			(0x1u<<24)
#define	PWR_SVMSR_ACTVOS			(0x3u<<16)
#define	PWR_SVMSR_ACTVOS_0			(0x1u<<16)
#define	PWR_SVMSR_ACTVOSRDY			(0x1u<<15)
#define	PWR_SVMSR_PVDO				(0x1u<<4)
#define	PWR_SVMSR_REGS				(0x1u<<1)
#define	PWR_SVMSR_VDDA2RDY_B_0X0	(0x0u<<27)
#define	PWR_SVMSR_VDDA2RDY_B_0X1	(0x1u<<27)
#define	PWR_SVMSR_VDDA1RDY_B_0X0	(0x0u<<26)
#define	PWR_SVMSR_VDDA1RDY_B_0X1	(0x1u<<26)
#define	PWR_SVMSR_VDDIO2RDY_B_0X0	(0x0u<<25)
#define	PWR_SVMSR_VDDIO2RDY_B_0X1	(0x1u<<25)
#define	PWR_SVMSR_VDDUSBRDY_B_0X0	(0x0u<<24)
#define	PWR_SVMSR_VDDUSBRDY_B_0X1	(0x1u<<24)
#define	PWR_SVMSR_ACTVOS_B_0X0		(0x0u<<16)
#define	PWR_SVMSR_ACTVOS_B_0X1		(0x1u<<16)
#define	PWR_SVMSR_ACTVOS_B_0X2		(0x2u<<16)
#define	PWR_SVMSR_ACTVOS_B_0X3		(0x3u<<16)
#define	PWR_SVMSR_ACTVOSRDY_B_0X0	(0x0u<<15)
#define	PWR_SVMSR_ACTVOSRDY_B_0X1	(0x1u<<15)
#define	PWR_SVMSR_PVDO_B_0X0		(0x0u<<4)
#define	PWR_SVMSR_PVDO_B_0X1		(0x1u<<4)
#define	PWR_SVMSR_REGS_B_0X0		(0x0u<<1)
#define	PWR_SVMSR_REGS_B_0X1		(0x1u<<1)

// BDSR Configuration

#define	PWR_BDSR_TEMPH				(0x1u<<3)
#define	PWR_BDSR_TEMPL				(0x1u<<2)
#define	PWR_BDSR_VBATH				(0x1u<<1)
#define	PWR_BDSR_TEMPH_B_0X0		(0x0u<<3)
#define	PWR_BDSR_TEMPH_B_0X1		(0x1u<<3)
#define	PWR_BDSR_TEMPL_B_0X0		(0x0u<<2)
#define	PWR_BDSR_TEMPL_B_0X1		(0x1u<<2)
#define	PWR_BDSR_VBATH_B_0X0		(0x0u<<1)
#define	PWR_BDSR_VBATH_B_0X1		(0x1u<<1)

// WUSR Configuration

#define	PWR_WUSR_WUF8				(0x1u<<7)
#define	PWR_WUSR_WUF7				(0x1u<<6)
#define	PWR_WUSR_WUF6				(0x1u<<5)
#define	PWR_WUSR_WUF5				(0x1u<<4)
#define	PWR_WUSR_WUF4				(0x1u<<3)
#define	PWR_WUSR_WUF3				(0x1u<<2)
#define	PWR_WUSR_WUF2				(0x1u<<1)
#define	PWR_WUSR_WUF1				(0x1u<<0)

// WUSCR Configuration

#define	PWR_WUSCR_CWUF8				(0x1u<<7)
#define	PWR_WUSCR_CWUF7				(0x1u<<6)
#define	PWR_WUSCR_CWUF6				(0x1u<<5)
#define	PWR_WUSCR_CWUF5				(0x1u<<4)
#define	PWR_WUSCR_CWUF4				(0x1u<<3)
#define	PWR_WUSCR_CWUF3				(0x1u<<2)
#define	PWR_WUSCR_CWUF2				(0x1u<<1)
#define	PWR_WUSCR_CWUF1				(0x1u<<0)

// APCR Configuration

#define	PWR_APCR_APC				(0x1u<<0)

// PUCRA Configuration

#define	PWR_PUCRA_PU15				(0x1u<<15)
#define	PWR_PUCRA_PU13				(0x1u<<13)
#define	PWR_PUCRA_PU12				(0x1u<<12)
#define	PWR_PUCRA_PU11				(0x1u<<11)
#define	PWR_PUCRA_PU10				(0x1u<<10)
#define	PWR_PUCRA_PU9				(0x1u<<9)
#define	PWR_PUCRA_PU8				(0x1u<<8)
#define	PWR_PUCRA_PU7				(0x1u<<7)
#define	PWR_PUCRA_PU6				(0x1u<<6)
#define	PWR_PUCRA_PU5				(0x1u<<5)
#define	PWR_PUCRA_PU4				(0x1u<<4)
#define	PWR_PUCRA_PU3				(0x1u<<3)
#define	PWR_PUCRA_PU2				(0x1u<<2)
#define	PWR_PUCRA_PU1				(0x1u<<1)
#define	PWR_PUCRA_PU0				(0x1u<<0)

// PDCRA Configuration

#define	PWR_PDCRA_PD14				(0x1u<<14)
#define	PWR_PDCRA_PD12				(0x1u<<12)
#define	PWR_PDCRA_PD11				(0x1u<<11)
#define	PWR_PDCRA_PD10				(0x1u<<10)
#define	PWR_PDCRA_PD9				(0x1u<<9)
#define	PWR_PDCRA_PD8				(0x1u<<8)
#define	PWR_PDCRA_PD7				(0x1u<<7)
#define	PWR_PDCRA_PD6				(0x1u<<6)
#define	PWR_PDCRA_PD5				(0x1u<<5)
#define	PWR_PDCRA_PD4				(0x1u<<4)
#define	PWR_PDCRA_PD3				(0x1u<<3)
#define	PWR_PDCRA_PD2				(0x1u<<2)
#define	PWR_PDCRA_PD1				(0x1u<<1)
#define	PWR_PDCRA_PD0				(0x1u<<0)

// PUCRB Configuration

#define	PWR_PUCRB_PU15				(0x1u<<15)
#define	PWR_PUCRB_PU14				(0x1u<<14)
#define	PWR_PUCRB_PU13				(0x1u<<13)
#define	PWR_PUCRB_PU12				(0x1u<<12)
#define	PWR_PUCRB_PU11				(0x1u<<11)
#define	PWR_PUCRB_PU10				(0x1u<<10)
#define	PWR_PUCRB_PU9				(0x1u<<9)
#define	PWR_PUCRB_PU8				(0x1u<<8)
#define	PWR_PUCRB_PU7				(0x1u<<7)
#define	PWR_PUCRB_PU6				(0x1u<<6)
#define	PWR_PUCRB_PU5				(0x1u<<5)
#define	PWR_PUCRB_PU4				(0x1u<<4)
#define	PWR_PUCRB_PU3				(0x1u<<3)
#define	PWR_PUCRB_PU2				(0x1u<<2)
#define	PWR_PUCRB_PU1				(0x1u<<1)
#define	PWR_PUCRB_PU0				(0x1u<<0)

// PDCRB Configuration

#define	PWR_PDCRB_PD15				(0x1u<<15)
#define	PWR_PDCRB_PD14				(0x1u<<14)
#define	PWR_PDCRB_PD13				(0x1u<<13)
#define	PWR_PDCRB_PD12				(0x1u<<12)
#define	PWR_PDCRB_PD11				(0x1u<<11)
#define	PWR_PDCRB_PD10				(0x1u<<10)
#define	PWR_PDCRB_PD9				(0x1u<<9)
#define	PWR_PDCRB_PD8				(0x1u<<8)
#define	PWR_PDCRB_PD7				(0x1u<<7)
#define	PWR_PDCRB_PD6				(0x1u<<6)
#define	PWR_PDCRB_PD5				(0x1u<<5)
#define	PWR_PDCRB_PD3				(0x1u<<3)
#define	PWR_PDCRB_PD2				(0x1u<<2)
#define	PWR_PDCRB_PD1				(0x1u<<1)
#define	PWR_PDCRB_PD0				(0x1u<<0)

// PUCRC Configuration

#define	PWR_PUCRC_PU15				(0x1u<<15)
#define	PWR_PUCRC_PU14				(0x1u<<14)
#define	PWR_PUCRC_PU13				(0x1u<<13)
#define	PWR_PUCRC_PU12				(0x1u<<12)
#define	PWR_PUCRC_PU11				(0x1u<<11)
#define	PWR_PUCRC_PU10				(0x1u<<10)
#define	PWR_PUCRC_PU9				(0x1u<<9)
#define	PWR_PUCRC_PU8				(0x1u<<8)
#define	PWR_PUCRC_PU7				(0x1u<<7)
#define	PWR_PUCRC_PU6				(0x1u<<6)
#define	PWR_PUCRC_PU5				(0x1u<<5)
#define	PWR_PUCRC_PU4				(0x1u<<4)
#define	PWR_PUCRC_PU3				(0x1u<<3)
#define	PWR_PUCRC_PU2				(0x1u<<2)
#define	PWR_PUCRC_PU1				(0x1u<<1)
#define	PWR_PUCRC_PU0				(0x1u<<0)

// PDCRC Configuration

#define	PWR_PDCRC_PD15				(0x1u<<15)
#define	PWR_PDCRC_PD14				(0x1u<<14)
#define	PWR_PDCRC_PD13				(0x1u<<13)
#define	PWR_PDCRC_PD12				(0x1u<<12)
#define	PWR_PDCRC_PD11				(0x1u<<11)
#define	PWR_PDCRC_PD10				(0x1u<<10)
#define	PWR_PDCRC_PD9				(0x1u<<9)
#define	PWR_PDCRC_PD8				(0x1u<<8)
#define	PWR_PDCRC_PD7				(0x1u<<7)
#define	PWR_PDCRC_PD6				(0x1u<<6)
#define	PWR_PDCRC_PD5				(0x1u<<5)
#define	PWR_PDCRC_PD4				(0x1u<<4)
#define	PWR_PDCRC_PD3				(0x1u<<3)
#define	PWR_PDCRC_PD2				(0x1u<<2)
#define	PWR_PDCRC_PD1				(0x1u<<1)
#define	PWR_PDCRC_PD0				(0x1u<<0)

// PUCRD Configuration

#define	PWR_PUCRD_PU15				(0x1u<<15)
#define	PWR_PUCRD_PU14				(0x1u<<14)
#define	PWR_PUCRD_PU13				(0x1u<<13)
#define	PWR_PUCRD_PU12				(0x1u<<12)
#define	PWR_PUCRD_PU11				(0x1u<<11)
#define	PWR_PUCRD_PU10				(0x1u<<10)
#define	PWR_PUCRD_PU9				(0x1u<<9)
#define	PWR_PUCRD_PU8				(0x1u<<8)
#define	PWR_PUCRD_PU7				(0x1u<<7)
#define	PWR_PUCRD_PU6				(0x1u<<6)
#define	PWR_PUCRD_PU5				(0x1u<<5)
#define	PWR_PUCRD_PU4				(0x1u<<4)
#define	PWR_PUCRD_PU3				(0x1u<<3)
#define	PWR_PUCRD_PU2				(0x1u<<2)
#define	PWR_PUCRD_PU1				(0x1u<<1)
#define	PWR_PUCRD_PU0				(0x1u<<0)

// PDCRD Configuration

#define	PWR_PDCRD_PD15				(0x1u<<15)
#define	PWR_PDCRD_PD14				(0x1u<<14)
#define	PWR_PDCRD_PD13				(0x1u<<13)
#define	PWR_PDCRD_PD12				(0x1u<<12)
#define	PWR_PDCRD_PD11				(0x1u<<11)
#define	PWR_PDCRD_PD10				(0x1u<<10)
#define	PWR_PDCRD_PD9				(0x1u<<9)
#define	PWR_PDCRD_PD8				(0x1u<<8)
#define	PWR_PDCRD_PD7				(0x1u<<7)
#define	PWR_PDCRD_PD6				(0x1u<<6)
#define	PWR_PDCRD_PD5				(0x1u<<5)
#define	PWR_PDCRD_PD4				(0x1u<<4)
#define	PWR_PDCRD_PD3				(0x1u<<3)
#define	PWR_PDCRD_PD2				(0x1u<<2)
#define	PWR_PDCRD_PD1				(0x1u<<1)
#define	PWR_PDCRD_PD0				(0x1u<<0)

// PUCRE Configuration

#define	PWR_PUCRE_PU15				(0x1u<<15)
#define	PWR_PUCRE_PU14				(0x1u<<14)
#define	PWR_PUCRE_PU13				(0x1u<<13)
#define	PWR_PUCRE_PU12				(0x1u<<12)
#define	PWR_PUCRE_PU11				(0x1u<<11)
#define	PWR_PUCRE_PU10				(0x1u<<10)
#define	PWR_PUCRE_PU9				(0x1u<<9)
#define	PWR_PUCRE_PU8				(0x1u<<8)
#define	PWR_PUCRE_PU7				(0x1u<<7)
#define	PWR_PUCRE_PU6				(0x1u<<6)
#define	PWR_PUCRE_PU5				(0x1u<<5)
#define	PWR_PUCRE_PU4				(0x1u<<4)
#define	PWR_PUCRE_PU3				(0x1u<<3)
#define	PWR_PUCRE_PU2				(0x1u<<2)
#define	PWR_PUCRE_PU1				(0x1u<<1)
#define	PWR_PUCRE_PU0				(0x1u<<0)

// PDCRE Configuration

#define	PWR_PDCRE_PD15				(0x1u<<15)
#define	PWR_PDCRE_PD14				(0x1u<<14)
#define	PWR_PDCRE_PD13				(0x1u<<13)
#define	PWR_PDCRE_PD12				(0x1u<<12)
#define	PWR_PDCRE_PD11				(0x1u<<11)
#define	PWR_PDCRE_PD10				(0x1u<<10)
#define	PWR_PDCRE_PD9				(0x1u<<9)
#define	PWR_PDCRE_PD8				(0x1u<<8)
#define	PWR_PDCRE_PD7				(0x1u<<7)
#define	PWR_PDCRE_PD6				(0x1u<<6)
#define	PWR_PDCRE_PD5				(0x1u<<5)
#define	PWR_PDCRE_PD4				(0x1u<<4)
#define	PWR_PDCRE_PD3				(0x1u<<3)
#define	PWR_PDCRE_PD2				(0x1u<<2)
#define	PWR_PDCRE_PD1				(0x1u<<1)
#define	PWR_PDCRE_PD0				(0x1u<<0)

// PUCRF Configuration

#define	PWR_PUCRF_PU15				(0x1u<<15)
#define	PWR_PUCRF_PU14				(0x1u<<14)
#define	PWR_PUCRF_PU13				(0x1u<<13)
#define	PWR_PUCRF_PU12				(0x1u<<12)
#define	PWR_PUCRF_PU11				(0x1u<<11)
#define	PWR_PUCRF_PU10				(0x1u<<10)
#define	PWR_PUCRF_PU9				(0x1u<<9)
#define	PWR_PUCRF_PU8				(0x1u<<8)
#define	PWR_PUCRF_PU7				(0x1u<<7)
#define	PWR_PUCRF_PU6				(0x1u<<6)
#define	PWR_PUCRF_PU5				(0x1u<<5)
#define	PWR_PUCRF_PU4				(0x1u<<4)
#define	PWR_PUCRF_PU3				(0x1u<<3)
#define	PWR_PUCRF_PU2				(0x1u<<2)
#define	PWR_PUCRF_PU1				(0x1u<<1)
#define	PWR_PUCRF_PU0				(0x1u<<0)

// PDCRF Configuration

#define	PWR_PDCRF_PD15				(0x1u<<15)
#define	PWR_PDCRF_PD14				(0x1u<<14)
#define	PWR_PDCRF_PD13				(0x1u<<13)
#define	PWR_PDCRF_PD12				(0x1u<<12)
#define	PWR_PDCRF_PD11				(0x1u<<11)
#define	PWR_PDCRF_PD10				(0x1u<<10)
#define	PWR_PDCRF_PD9				(0x1u<<9)
#define	PWR_PDCRF_PD8				(0x1u<<8)
#define	PWR_PDCRF_PD7				(0x1u<<7)
#define	PWR_PDCRF_PD6				(0x1u<<6)
#define	PWR_PDCRF_PD5				(0x1u<<5)
#define	PWR_PDCRF_PD4				(0x1u<<4)
#define	PWR_PDCRF_PD3				(0x1u<<3)
#define	PWR_PDCRF_PD2				(0x1u<<2)
#define	PWR_PDCRF_PD1				(0x1u<<1)
#define	PWR_PDCRF_PD0				(0x1u<<0)

// PUCRG Configuration

#define	PWR_PUCRG_PU15				(0x1u<<15)
#define	PWR_PUCRG_PU14				(0x1u<<14)
#define	PWR_PUCRG_PU13				(0x1u<<13)
#define	PWR_PUCRG_PU12				(0x1u<<12)
#define	PWR_PUCRG_PU11				(0x1u<<11)
#define	PWR_PUCRG_PU10				(0x1u<<10)
#define	PWR_PUCRG_PU9				(0x1u<<9)
#define	PWR_PUCRG_PU8				(0x1u<<8)
#define	PWR_PUCRG_PU7				(0x1u<<7)
#define	PWR_PUCRG_PU6				(0x1u<<6)
#define	PWR_PUCRG_PU5				(0x1u<<5)
#define	PWR_PUCRG_PU4				(0x1u<<4)
#define	PWR_PUCRG_PU3				(0x1u<<3)
#define	PWR_PUCRG_PU2				(0x1u<<2)
#define	PWR_PUCRG_PU1				(0x1u<<1)
#define	PWR_PUCRG_PU0				(0x1u<<0)

// PDCRG Configuration

#define	PWR_PDCRG_PD15				(0x1u<<15)
#define	PWR_PDCRG_PD14				(0x1u<<14)
#define	PWR_PDCRG_PD13				(0x1u<<13)
#define	PWR_PDCRG_PD12				(0x1u<<12)
#define	PWR_PDCRG_PD11				(0x1u<<11)
#define	PWR_PDCRG_PD10				(0x1u<<10)
#define	PWR_PDCRG_PD9				(0x1u<<9)
#define	PWR_PDCRG_PD8				(0x1u<<8)
#define	PWR_PDCRG_PD7				(0x1u<<7)
#define	PWR_PDCRG_PD6				(0x1u<<6)
#define	PWR_PDCRG_PD5				(0x1u<<5)
#define	PWR_PDCRG_PD4				(0x1u<<4)
#define	PWR_PDCRG_PD3				(0x1u<<3)
#define	PWR_PDCRG_PD2				(0x1u<<2)
#define	PWR_PDCRG_PD1				(0x1u<<1)
#define	PWR_PDCRG_PD0				(0x1u<<0)

// PUCRH Configuration

#define	PWR_PUCRH_PU15				(0x1u<<15)
#define	PWR_PUCRH_PU14				(0x1u<<14)
#define	PWR_PUCRH_PU13				(0x1u<<13)
#define	PWR_PUCRH_PU12				(0x1u<<12)
#define	PWR_PUCRH_PU11				(0x1u<<11)
#define	PWR_PUCRH_PU10				(0x1u<<10)
#define	PWR_PUCRH_PU9				(0x1u<<9)
#define	PWR_PUCRH_PU8				(0x1u<<8)
#define	PWR_PUCRH_PU7				(0x1u<<7)
#define	PWR_PUCRH_PU6				(0x1u<<6)
#define	PWR_PUCRH_PU5				(0x1u<<5)
#define	PWR_PUCRH_PU4				(0x1u<<4)
#define	PWR_PUCRH_PU3				(0x1u<<3)
#define	PWR_PUCRH_PU2				(0x1u<<2)
#define	PWR_PUCRH_PU1				(0x1u<<1)
#define	PWR_PUCRH_PU0				(0x1u<<0)

// PDCRH Configuration

#define	PWR_PDCRH_PD15				(0x1u<<15)
#define	PWR_PDCRH_PD14				(0x1u<<14)
#define	PWR_PDCRH_PD13				(0x1u<<13)
#define	PWR_PDCRH_PD12				(0x1u<<12)
#define	PWR_PDCRH_PD11				(0x1u<<11)
#define	PWR_PDCRH_PD10				(0x1u<<10)
#define	PWR_PDCRH_PD9				(0x1u<<9)
#define	PWR_PDCRH_PD8				(0x1u<<8)
#define	PWR_PDCRH_PD7				(0x1u<<7)
#define	PWR_PDCRH_PD6				(0x1u<<6)
#define	PWR_PDCRH_PD5				(0x1u<<5)
#define	PWR_PDCRH_PD4				(0x1u<<4)
#define	PWR_PDCRH_PD3				(0x1u<<3)
#define	PWR_PDCRH_PD2				(0x1u<<2)
#define	PWR_PDCRH_PD1				(0x1u<<1)
#define	PWR_PDCRH_PD0				(0x1u<<0)

// PUCRI Configuration

#define	PWR_PUCRI_PU15				(0x1u<<15)
#define	PWR_PUCRI_PU14				(0x1u<<14)
#define	PWR_PUCRI_PU13				(0x1u<<13)
#define	PWR_PUCRI_PU12				(0x1u<<12)
#define	PWR_PUCRI_PU11				(0x1u<<11)
#define	PWR_PUCRI_PU10				(0x1u<<10)
#define	PWR_PUCRI_PU9				(0x1u<<9)
#define	PWR_PUCRI_PU8				(0x1u<<8)
#define	PWR_PUCRI_PU7				(0x1u<<7)
#define	PWR_PUCRI_PU6				(0x1u<<6)
#define	PWR_PUCRI_PU5				(0x1u<<5)
#define	PWR_PUCRI_PU4				(0x1u<<4)
#define	PWR_PUCRI_PU3				(0x1u<<3)
#define	PWR_PUCRI_PU2				(0x1u<<2)
#define	PWR_PUCRI_PU1				(0x1u<<1)
#define	PWR_PUCRI_PU0				(0x1u<<0)

// PDCRI Configuration

#define	PWR_PDCRI_PD15				(0x1u<<15)
#define	PWR_PDCRI_PD14				(0x1u<<14)
#define	PWR_PDCRI_PD13				(0x1u<<13)
#define	PWR_PDCRI_PD12				(0x1u<<12)
#define	PWR_PDCRI_PD11				(0x1u<<11)
#define	PWR_PDCRI_PD10				(0x1u<<10)
#define	PWR_PDCRI_PD9				(0x1u<<9)
#define	PWR_PDCRI_PD8				(0x1u<<8)
#define	PWR_PDCRI_PD7				(0x1u<<7)
#define	PWR_PDCRI_PD6				(0x1u<<6)
#define	PWR_PDCRI_PD5				(0x1u<<5)
#define	PWR_PDCRI_PD4				(0x1u<<4)
#define	PWR_PDCRI_PD3				(0x1u<<3)
#define	PWR_PDCRI_PD2				(0x1u<<2)
#define	PWR_PDCRI_PD1				(0x1u<<1)
#define	PWR_PDCRI_PD0				(0x1u<<0)

// PUCRJ Configuration

#define	PWR_PUCRJ_PU11				(0x1u<<11)
#define	PWR_PUCRJ_PU10				(0x1u<<10)
#define	PWR_PUCRJ_PU9				(0x1u<<9)
#define	PWR_PUCRJ_PU8				(0x1u<<8)
#define	PWR_PUCRJ_PU7				(0x1u<<7)
#define	PWR_PUCRJ_PU6				(0x1u<<6)
#define	PWR_PUCRJ_PU5				(0x1u<<5)
#define	PWR_PUCRJ_PU4				(0x1u<<4)
#define	PWR_PUCRJ_PU3				(0x1u<<3)
#define	PWR_PUCRJ_PU2				(0x1u<<2)
#define	PWR_PUCRJ_PU1				(0x1u<<1)
#define	PWR_PUCRJ_PU0				(0x1u<<0)

// PDCRJ Configuration

#define	PWR_PDCRJ_PD11				(0x1u<<11)
#define	PWR_PDCRJ_PD10				(0x1u<<10)
#define	PWR_PDCRJ_PD9				(0x1u<<9)
#define	PWR_PDCRJ_PD8				(0x1u<<8)
#define	PWR_PDCRJ_PD7				(0x1u<<7)
#define	PWR_PDCRJ_PD6				(0x1u<<6)
#define	PWR_PDCRJ_PD5				(0x1u<<5)
#define	PWR_PDCRJ_PD4				(0x1u<<4)
#define	PWR_PDCRJ_PD3				(0x1u<<3)
#define	PWR_PDCRJ_PD2				(0x1u<<2)
#define	PWR_PDCRJ_PD1				(0x1u<<1)
#define	PWR_PDCRJ_PD0				(0x1u<<0)

// CR4 Configuration

#define	PWR_CR4_SRAM5PDS13			(0x1u<<28)
#define	PWR_CR4_SRAM5PDS12			(0x1u<<27)
#define	PWR_CR4_SRAM5PDS11			(0x1u<<26)
#define	PWR_CR4_SRAM5PDS10			(0x1u<<25)
#define	PWR_CR4_SRAM5PDS9			(0x1u<<24)
#define	PWR_CR4_SRAM5PDS8			(0x1u<<23)
#define	PWR_CR4_SRAM5PDS7			(0x1u<<22)
#define	PWR_CR4_SRAM5PDS6			(0x1u<<21)
#define	PWR_CR4_SRAM5PDS5			(0x1u<<20)
#define	PWR_CR4_SRAM5PDS4			(0x1u<<19)
#define	PWR_CR4_SRAM5PDS3			(0x1u<<18)
#define	PWR_CR4_SRAM5PDS2			(0x1u<<17)
#define	PWR_CR4_SRAM5PDS1			(0x1u<<16)
#define	PWR_CR4_SRAM3PDS13			(0x1u<<14)
#define	PWR_CR4_SRAM3PDS12			(0x1u<<13)
#define	PWR_CR4_SRAM3PDS11			(0x1u<<12)
#define	PWR_CR4_SRAM3PDS10			(0x1u<<11)
#define	PWR_CR4_SRAM3PDS9			(0x1u<<10)
#define	PWR_CR4_SRAM1PDS12			(0x1u<<8)
#define	PWR_CR4_SRAM1PDS11			(0x1u<<7)
#define	PWR_CR4_SRAM1PDS10			(0x1u<<6)
#define	PWR_CR4_SRAM1PDS9			(0x1u<<5)
#define	PWR_CR4_SRAM1PDS8			(0x1u<<4)
#define	PWR_CR4_SRAM1PDS7			(0x1u<<3)
#define	PWR_CR4_SRAM1PDS6			(0x1u<<2)
#define	PWR_CR4_SRAM1PDS5			(0x1u<<1)
#define	PWR_CR4_SRAM1PDS4			(0x1u<<0)
