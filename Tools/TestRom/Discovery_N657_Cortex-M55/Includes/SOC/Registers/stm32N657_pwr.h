/*
; stm32N657_pwr.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_pwr equates.
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
	volatile	uint32_t	CR4;
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	VOSCR;
	volatile	uint32_t	BDCR1;
	volatile	uint32_t	BDCR2;
	volatile	uint32_t	DBPCR;
	volatile	uint32_t	CPUCR;
	volatile	uint32_t	SVMCR1;
	volatile	uint32_t	SVMCR2;
	volatile	uint32_t	SVMCR3;
	volatile	uint32_t	RESERVED1[4];
	volatile	uint32_t	WKUPCR;
	volatile	uint32_t	WKUPSR;
	volatile	uint32_t	WKUPEPR;
	volatile	uint32_t	RESERVED2[5];
	volatile	uint32_t	SECCFGR;
	volatile	uint32_t	PRIVCFGR;
} PWR_TypeDef;

#if (defined(__cplusplus))
#define	PWR_NS	reinterpret_cast<PWR_TypeDef *>(0x46024800u)
#define	PWR_S	reinterpret_cast<PWR_TypeDef *>(0x56024800u)

#else
#define	PWR_NS	((PWR_TypeDef *)0x46024800u)
#define	PWR_S	((PWR_TypeDef *)0x56024800u)
#endif

// CR1 Configuration

#define	PWR_CR1_POPL					(0x1Fu<<16)
#define	PWR_CR1_POPL_0					(0x1u<<16)
#define	PWR_CR1_LPDS08V					(0x1u<<5)
#define	PWR_CR1_MODE_PDN				(0x1u<<4)
#define	PWR_CR1_SDEN					(0x1u<<2)

#define	PWR_CR1_POPL_B_0X0				(0x0u<<16)
#define	PWR_CR1_POPL_B_0X1				(0x1u<<16)
#define	PWR_CR1_POPL_B_0X2				(0x2u<<16)
#define	PWR_CR1_POPL_B_0X1F				(0x1Fu<<16)
#define	PWR_CR1_LPDS08V_B_0X0			(0x0u<<5)
#define	PWR_CR1_LPDS08V_B_0X1			(0x1u<<5)
#define	PWR_CR1_MODE_PDN_B_0X0			(0x0u<<4)
#define	PWR_CR1_MODE_PDN_B_0X1			(0x1u<<4)
#define	PWR_CR1_SDEN_B_0X0				(0x0u<<2)
#define	PWR_CR1_SDEN_B_0X1				(0x1u<<2)

// CR2 Configuration

#define	PWR_CR2_PVDO					(0x1u<<8)
#define	PWR_CR2_PVDEN					(0x1u<<0)

#define	PWR_CR2_PVDO_B_0X0				(0x0u<<8)
#define	PWR_CR2_PVDO_B_0X1				(0x1u<<8)
#define	PWR_CR2_PVDEN_B_0X0				(0x0u<<0)
#define	PWR_CR2_PVDEN_B_0X1				(0x1u<<0)

// CR3 Configuration

#define	PWR_CR3_VCOREH					(0x1u<<9)
#define	PWR_CR3_VCOREL					(0x1u<<8)
#define	PWR_CR3_VCORELLS				(0x1u<<4)
#define	PWR_CR3_VCOREMONEN				(0x1u<<0)

#define	PWR_CR3_VCOREH_B_0X0			(0x0u<<9)
#define	PWR_CR3_VCOREH_B_0X1			(0x1u<<9)
#define	PWR_CR3_VCOREL_B_0X0			(0x0u<<8)
#define	PWR_CR3_VCOREL_B_0X1			(0x1u<<8)
#define	PWR_CR3_VCORELLS_B_0X0			(0x0u<<4)
#define	PWR_CR3_VCORELLS_B_0X1			(0x1u<<4)
#define	PWR_CR3_VCOREMONEN_B_0X0		(0x0u<<0)
#define	PWR_CR3_VCOREMONEN_B_0X1		(0x1u<<0)

// CR4 Configuration

#define	PWR_CR4_TCMFLXRBSEN				(0x1u<<4)
#define	PWR_CR4_TCMRBSEN				(0x1u<<0)

#define	PWR_CR4_TCMFLXRBSEN_B_0X0		(0x0u<<4)
#define	PWR_CR4_TCMFLXRBSEN_B_0X1		(0x1u<<4)
#define	PWR_CR4_TCMRBSEN_B_0X0			(0x0u<<0)
#define	PWR_CR4_TCMRBSEN_B_0X1			(0x1u<<0)

// VOSCR Configuration

#define	PWR_VOSCR_ACTVOSRDY				(0x1u<<17)
#define	PWR_VOSCR_ACTVOS				(0x1u<<16)
#define	PWR_VOSCR_VOSRDY				(0x1u<<1)
#define	PWR_VOSCR_VOS					(0x1u<<0)

#define	PWR_VOSCR_ACTVOSRDY_B_0X0		(0x0u<<17)
#define	PWR_VOSCR_ACTVOSRDY_B_0X1		(0x1u<<17)
#define	PWR_VOSCR_VOSRDY_B_0X0			(0x0u<<1)
#define	PWR_VOSCR_VOSRDY_B_0X1			(0x1u<<1)
#define	PWR_VOSCR_VOS_B_0X0				(0x0u<<0)
#define	PWR_VOSCR_VOS_B_0X1				(0x1u<<0)

// BDCR1 Configuration

#define	PWR_BDCR1_TEMPH					(0x1u<<19)
#define	PWR_BDCR1_TEMPL					(0x1u<<18)
#define	PWR_BDCR1_VBATH					(0x1u<<17)
#define	PWR_BDCR1_VBATL					(0x1u<<16)
#define	PWR_BDCR1_MONEN					(0x1u<<0)

#define	PWR_BDCR1_TEMPH_B_0X0			(0x0u<<19)
#define	PWR_BDCR1_TEMPH_B_0X1			(0x1u<<19)
#define	PWR_BDCR1_TEMPL_B_0X0			(0x0u<<18)
#define	PWR_BDCR1_TEMPL_B_0X1			(0x1u<<18)
#define	PWR_BDCR1_VBATH_B_0X0			(0x0u<<17)
#define	PWR_BDCR1_VBATH_B_0X1			(0x1u<<17)
#define	PWR_BDCR1_VBATL_B_0X0			(0x0u<<16)
#define	PWR_BDCR1_VBATL_B_0X1			(0x1u<<16)
#define	PWR_BDCR1_MONEN_B_0X0			(0x0u<<0)
#define	PWR_BDCR1_MONEN_B_0X1			(0x1u<<0)

// BDCR2 Configuration

#define	PWR_BDCR2_BKPRBSEN				(0x1u<<0)

#define	PWR_BDCR2_BKPRBSEN_B_0X0		(0x0u<<0)
#define	PWR_BDCR2_BKPRBSEN_B_0X1		(0x1u<<0)

// DBPCR Configuration

#define	PWR_DBPCR_DBP					(0x1u<<0)

#define	PWR_DBPCR_DBP_B_0X0				(0x0u<<0)
#define	PWR_DBPCR_DBP_B_0X1				(0x1u<<0)

// CPUCR Configuration

#define	PWR_CPUCR_SVOS					(0x1u<<16)
#define	PWR_CPUCR_SBF					(0x1u<<9)
#define	PWR_CPUCR_STOPF					(0x1u<<8)
#define	PWR_CPUCR_CSSF					(0x1u<<1)
#define	PWR_CPUCR_PDDS					(0x1u<<0)

#define	PWR_CPUCR_SVOS_B_0X0			(0x0u<<16)
#define	PWR_CPUCR_SVOS_B_0X1			(0x1u<<16)
#define	PWR_CPUCR_SBF_B_0X0				(0x0u<<9)
#define	PWR_CPUCR_SBF_B_0X1				(0x1u<<9)
#define	PWR_CPUCR_STOPF_B_0X0			(0x0u<<8)
#define	PWR_CPUCR_STOPF_B_0X1			(0x1u<<8)
#define	PWR_CPUCR_CSSF_B_0X0			(0x0u<<1)
#define	PWR_CPUCR_CSSF_B_0X1			(0x1u<<1)
#define	PWR_CPUCR_PDDS_B_0X0			(0x0u<<0)
#define	PWR_CPUCR_PDDS_B_0X1			(0x1u<<0)

// SVMCR1 Configuration

#define	PWR_SVMCR1_VDDIO4VRSTBY			(0x1u<<25)
#define	PWR_SVMCR1_VDDIO4VRSEL			(0x1u<<24)
#define	PWR_SVMCR1_VDDIO4RDY			(0x1u<<16)
#define	PWR_SVMCR1_VDDIO4SV				(0x1u<<8)
#define	PWR_SVMCR1_VDDIO4VMEN			(0x1u<<0)

#define	PWR_SVMCR1_VDDIO4VRSTBY_B_0X0	(0x0u<<25)
#define	PWR_SVMCR1_VDDIO4VRSTBY_B_0X1	(0x1u<<25)
#define	PWR_SVMCR1_VDDIO4VRSEL_B_0X0	(0x0u<<24)
#define	PWR_SVMCR1_VDDIO4VRSEL_B_0X1	(0x1u<<24)
#define	PWR_SVMCR1_VDDIO4RDY_B_0X0		(0x0u<<16)
#define	PWR_SVMCR1_VDDIO4RDY_B_0X1		(0x1u<<16)
#define	PWR_SVMCR1_VDDIO4SV_B_0X0		(0x0u<<8)
#define	PWR_SVMCR1_VDDIO4SV_B_0X1		(0x1u<<8)
#define	PWR_SVMCR1_VDDIO4VMEN_B_0X0		(0x0u<<0)
#define	PWR_SVMCR1_VDDIO4VMEN_B_0X1		(0x1u<<0)

// SVMCR2 Configuration

#define	PWR_SVMCR2_VDDIO5VRSTBY			(0x1u<<25)
#define	PWR_SVMCR2_VDDIO5VRSEL			(0x1u<<24)
#define	PWR_SVMCR2_VDDIO5RDY			(0x1u<<16)
#define	PWR_SVMCR2_VDDIO5SV				(0x1u<<8)
#define	PWR_SVMCR2_VDDIO5VMEN			(0x1u<<0)

#define	PWR_SVMCR2_VDDIO5VRSTBY_B_0X0	(0x0u<<25)
#define	PWR_SVMCR2_VDDIO5VRSTBY_B_0X1	(0x1u<<25)
#define	PWR_SVMCR2_VDDIO5VRSEL_B_0X0	(0x0u<<24)
#define	PWR_SVMCR2_VDDIO5VRSEL_B_0X1	(0x1u<<24)
#define	PWR_SVMCR2_VDDIO5RDY_B_0X0		(0x0u<<16)
#define	PWR_SVMCR2_VDDIO5RDY_B_0X1		(0x1u<<16)
#define	PWR_SVMCR2_VDDIO5SV_B_0X0		(0x0u<<8)
#define	PWR_SVMCR2_VDDIO5SV_B_0X1		(0x1u<<8)
#define	PWR_SVMCR2_VDDIO5VMEN_B_0X0		(0x0u<<0)
#define	PWR_SVMCR2_VDDIO5VMEN_B_0X1		(0x1u<<0)

// SVMCR3 Configuration

#define	PWR_SVMCR3_VDDIO3VRSEL			(0x1u<<26)
#define	PWR_SVMCR3_VDDIO2VRSEL			(0x1u<<25)
#define	PWR_SVMCR3_VDDIOVRSEL			(0x1u<<24)
#define	PWR_SVMCR3_ARDY					(0x1u<<20)
#define	PWR_SVMCR3_USB33RDY				(0x1u<<18)
#define	PWR_SVMCR3_VDDIO3RDY			(0x1u<<17)
#define	PWR_SVMCR3_VDDIO2RDY			(0x1u<<16)
#define	PWR_SVMCR3_ASV					(0x1u<<12)
#define	PWR_SVMCR3_USB33SV				(0x1u<<10)
#define	PWR_SVMCR3_VDDIO3SV				(0x1u<<9)
#define	PWR_SVMCR3_VDDIO2SV				(0x1u<<8)
#define	PWR_SVMCR3_AVMEN				(0x1u<<4)
#define	PWR_SVMCR3_USB33VMEN			(0x1u<<2)
#define	PWR_SVMCR3_VDDIO3VMEN			(0x1u<<1)
#define	PWR_SVMCR3_VDDIO2VMEN			(0x1u<<0)

#define	PWR_SVMCR3_VDDIO3VRSEL_B_0X0	(0x0u<<26)
#define	PWR_SVMCR3_VDDIO3VRSEL_B_0X1	(0x1u<<26)
#define	PWR_SVMCR3_VDDIO2VRSEL_B_0X0	(0x0u<<25)
#define	PWR_SVMCR3_VDDIO2VRSEL_B_0X1	(0x1u<<25)
#define	PWR_SVMCR3_VDDIOVRSEL_B_0X0		(0x0u<<24)
#define	PWR_SVMCR3_VDDIOVRSEL_B_0X1		(0x1u<<24)
#define	PWR_SVMCR3_ARDY_B_0X0			(0x0u<<20)
#define	PWR_SVMCR3_ARDY_B_0X1			(0x1u<<20)
#define	PWR_SVMCR3_USB33RDY_B_0X0		(0x0u<<18)
#define	PWR_SVMCR3_USB33RDY_B_0X1		(0x1u<<18)
#define	PWR_SVMCR3_VDDIO3RDY_B_0X0		(0x0u<<17)
#define	PWR_SVMCR3_VDDIO3RDY_B_0X1		(0x1u<<17)
#define	PWR_SVMCR3_VDDIO2RDY_B_0X0		(0x0u<<16)
#define	PWR_SVMCR3_VDDIO2RDY_B_0X1		(0x1u<<16)
#define	PWR_SVMCR3_ASV_B_0X0			(0x0u<<12)
#define	PWR_SVMCR3_ASV_B_0X1			(0x1u<<12)
#define	PWR_SVMCR3_USB33SV_B_0X0		(0x0u<<10)
#define	PWR_SVMCR3_USB33SV_B_0X1		(0x1u<<10)
#define	PWR_SVMCR3_VDDIO3SV_B_0X0		(0x0u<<9)
#define	PWR_SVMCR3_VDDIO3SV_B_0X1		(0x1u<<9)
#define	PWR_SVMCR3_VDDIO2SV_B_0X0		(0x0u<<8)
#define	PWR_SVMCR3_VDDIO2SV_B_0X1		(0x1u<<8)
#define	PWR_SVMCR3_AVMEN_B_0X0			(0x0u<<4)
#define	PWR_SVMCR3_AVMEN_B_0X1			(0x1u<<4)
#define	PWR_SVMCR3_USB33VMEN_B_0X0		(0x0u<<2)
#define	PWR_SVMCR3_USB33VMEN_B_0X1		(0x1u<<2)
#define	PWR_SVMCR3_VDDIO3VMEN_B_0X0		(0x0u<<1)
#define	PWR_SVMCR3_VDDIO3VMEN_B_0X1		(0x1u<<1)
#define	PWR_SVMCR3_VDDIO2VMEN_B_0X0		(0x0u<<0)
#define	PWR_SVMCR3_VDDIO2VMEN_B_0X1		(0x1u<<0)

// WKUPCR Configuration

#define	PWR_WKUPCR_WKUPC4				(0x1u<<3)
#define	PWR_WKUPCR_WKUPC3				(0x1u<<2)
#define	PWR_WKUPCR_WKUPC2				(0x1u<<1)
#define	PWR_WKUPCR_WKUPC1				(0x1u<<0)

#define	PWR_WKUPCR_WKUPC4_B_0X0			(0x0u<<3)
#define	PWR_WKUPCR_WKUPC4_B_0X1			(0x1u<<3)
#define	PWR_WKUPCR_WKUPC3_B_0X0			(0x0u<<2)
#define	PWR_WKUPCR_WKUPC3_B_0X1			(0x1u<<2)
#define	PWR_WKUPCR_WKUPC2_B_0X0			(0x0u<<1)
#define	PWR_WKUPCR_WKUPC2_B_0X1			(0x1u<<1)
#define	PWR_WKUPCR_WKUPC1_B_0X0			(0x0u<<0)
#define	PWR_WKUPCR_WKUPC1_B_0X1			(0x1u<<0)

// WKUPSR Configuration

#define	PWR_WKUPSR_WKUPF4				(0x1u<<3)
#define	PWR_WKUPSR_WKUPF3				(0x1u<<2)
#define	PWR_WKUPSR_WKUPF2				(0x1u<<1)
#define	PWR_WKUPSR_WKUPF1				(0x1u<<0)

#define	PWR_WKUPSR_WKUPF4_B_0X0			(0x0u<<3)
#define	PWR_WKUPSR_WKUPF4_B_0X1			(0x1u<<3)
#define	PWR_WKUPSR_WKUPF3_B_0X0			(0x0u<<2)
#define	PWR_WKUPSR_WKUPF3_B_0X1			(0x1u<<2)
#define	PWR_WKUPSR_WKUPF2_B_0X0			(0x0u<<1)
#define	PWR_WKUPSR_WKUPF2_B_0X1			(0x1u<<1)
#define	PWR_WKUPSR_WKUPF1_B_0X0			(0x0u<<0)
#define	PWR_WKUPSR_WKUPF1_B_0X1			(0x1u<<0)

// WKUPEPR Configuration

#define	PWR_WKUPEPR_WKUPPUPD4			(0x3u<<22)
#define	PWR_WKUPEPR_WKUPPUPD4_0			(0x1u<<22)
#define	PWR_WKUPEPR_WKUPPUPD3			(0x3u<<20)
#define	PWR_WKUPEPR_WKUPPUPD3_0			(0x1u<<20)
#define	PWR_WKUPEPR_WKUPPUPD2			(0x3u<<18)
#define	PWR_WKUPEPR_WKUPPUPD2_0			(0x1u<<18)
#define	PWR_WKUPEPR_WKUPPUPD1			(0x3u<<16)
#define	PWR_WKUPEPR_WKUPPUPD1_0			(0x1u<<16)
#define	PWR_WKUPEPR_WKUPP4				(0x1u<<11)
#define	PWR_WKUPEPR_WKUPP3				(0x1u<<10)
#define	PWR_WKUPEPR_WKUPP2				(0x1u<<9)
#define	PWR_WKUPEPR_WKUPP1				(0x1u<<8)
#define	PWR_WKUPEPR_WKUPEN4				(0x1u<<3)
#define	PWR_WKUPEPR_WKUPEN3				(0x1u<<2)
#define	PWR_WKUPEPR_WKUPEN2				(0x1u<<1)
#define	PWR_WKUPEPR_WKUPEN1				(0x1u<<0)

#define	PWR_WKUPEPR_WKUPPUPD4_B_0X0		(0x0u<<22)
#define	PWR_WKUPEPR_WKUPPUPD4_B_0X1		(0x1u<<22)
#define	PWR_WKUPEPR_WKUPPUPD4_B_0X2		(0x2u<<22)
#define	PWR_WKUPEPR_WKUPPUPD3_B_0X0		(0x0u<<20)
#define	PWR_WKUPEPR_WKUPPUPD3_B_0X1		(0x1u<<20)
#define	PWR_WKUPEPR_WKUPPUPD3_B_0X2		(0x2u<<20)
#define	PWR_WKUPEPR_WKUPPUPD2_B_0X0		(0x0u<<18)
#define	PWR_WKUPEPR_WKUPPUPD2_B_0X1		(0x1u<<18)
#define	PWR_WKUPEPR_WKUPPUPD2_B_0X2		(0x2u<<18)
#define	PWR_WKUPEPR_WKUPPUPD1_B_0X0		(0x0u<<16)
#define	PWR_WKUPEPR_WKUPPUPD1_B_0X1		(0x1u<<16)
#define	PWR_WKUPEPR_WKUPPUPD1_B_0X2		(0x2u<<16)
#define	PWR_WKUPEPR_WKUPP4_B_0X0		(0x0u<<11)
#define	PWR_WKUPEPR_WKUPP4_B_0X1		(0x1u<<11)
#define	PWR_WKUPEPR_WKUPP3_B_0X0		(0x0u<<10)
#define	PWR_WKUPEPR_WKUPP3_B_0X1		(0x1u<<10)
#define	PWR_WKUPEPR_WKUPP2_B_0X0		(0x0u<<9)
#define	PWR_WKUPEPR_WKUPP2_B_0X1		(0x1u<<9)
#define	PWR_WKUPEPR_WKUPP1_B_0X0		(0x0u<<8)
#define	PWR_WKUPEPR_WKUPP1_B_0X1		(0x1u<<8)
#define	PWR_WKUPEPR_WKUPEN4_B_0X0		(0x0u<<3)
#define	PWR_WKUPEPR_WKUPEN4_B_0X1		(0x1u<<3)
#define	PWR_WKUPEPR_WKUPEN3_B_0X0		(0x0u<<2)
#define	PWR_WKUPEPR_WKUPEN3_B_0X1		(0x1u<<2)
#define	PWR_WKUPEPR_WKUPEN2_B_0X0		(0x0u<<1)
#define	PWR_WKUPEPR_WKUPEN2_B_0X1		(0x1u<<1)
#define	PWR_WKUPEPR_WKUPEN1_B_0X0		(0x0u<<0)
#define	PWR_WKUPEPR_WKUPEN1_B_0X1		(0x1u<<0)

// SECCFGR Configuration

#define	PWR_SECCFGR_WKUPSEC4			(0x1u<<19)
#define	PWR_SECCFGR_WKUPSEC3			(0x1u<<18)
#define	PWR_SECCFGR_WKUPSEC2			(0x1u<<17)
#define	PWR_SECCFGR_WKUPSEC1			(0x1u<<16)
#define	PWR_SECCFGR_SEC7				(0x1u<<7)
#define	PWR_SECCFGR_SEC6				(0x1u<<6)
#define	PWR_SECCFGR_SEC5				(0x1u<<5)
#define	PWR_SECCFGR_SEC4				(0x1u<<4)
#define	PWR_SECCFGR_SEC3				(0x1u<<3)
#define	PWR_SECCFGR_SEC2				(0x1u<<2)
#define	PWR_SECCFGR_SEC1				(0x1u<<1)
#define	PWR_SECCFGR_SEC0				(0x1u<<0)

#define	PWR_SECCFGR_WKUPSEC4_B_0X0		(0x0u<<19)
#define	PWR_SECCFGR_WKUPSEC4_B_0X1		(0x1u<<19)
#define	PWR_SECCFGR_WKUPSEC3_B_0X0		(0x0u<<18)
#define	PWR_SECCFGR_WKUPSEC3_B_0X1		(0x1u<<18)
#define	PWR_SECCFGR_WKUPSEC2_B_0X0		(0x0u<<17)
#define	PWR_SECCFGR_WKUPSEC2_B_0X1		(0x1u<<17)
#define	PWR_SECCFGR_WKUPSEC1_B_0X0		(0x0u<<16)
#define	PWR_SECCFGR_WKUPSEC1_B_0X1		(0x1u<<16)
#define	PWR_SECCFGR_SEC7_B_0X0			(0x0u<<7)
#define	PWR_SECCFGR_SEC7_B_0X1			(0x1u<<7)
#define	PWR_SECCFGR_SEC6_B_0X0			(0x0u<<6)
#define	PWR_SECCFGR_SEC6_B_0X1			(0x1u<<6)
#define	PWR_SECCFGR_SEC5_B_0X0			(0x0u<<5)
#define	PWR_SECCFGR_SEC5_B_0X1			(0x1u<<5)
#define	PWR_SECCFGR_SEC4_B_0X0			(0x0u<<4)
#define	PWR_SECCFGR_SEC4_B_0X1			(0x1u<<4)
#define	PWR_SECCFGR_SEC3_B_0X0			(0x0u<<3)
#define	PWR_SECCFGR_SEC3_B_0X1			(0x1u<<3)
#define	PWR_SECCFGR_SEC2_B_0X0			(0x0u<<2)
#define	PWR_SECCFGR_SEC2_B_0X1			(0x1u<<2)
#define	PWR_SECCFGR_SEC1_B_0X0			(0x0u<<1)
#define	PWR_SECCFGR_SEC1_B_0X1			(0x1u<<1)
#define	PWR_SECCFGR_SEC0_B_0X0			(0x0u<<0)
#define	PWR_SECCFGR_SEC0_B_0X1			(0x1u<<0)

// PRIVCFGR Configuration

#define	PWR_PRIVCFGR_WKUPPRIV4			(0x1u<<19)
#define	PWR_PRIVCFGR_WKUPPRIV3			(0x1u<<18)
#define	PWR_PRIVCFGR_WKUPPRIV2			(0x1u<<17)
#define	PWR_PRIVCFGR_WKUPPRIV1			(0x1u<<16)
#define	PWR_PRIVCFGR_PRIV7				(0x1u<<7)
#define	PWR_PRIVCFGR_PRIV6				(0x1u<<6)
#define	PWR_PRIVCFGR_PRIV5				(0x1u<<5)
#define	PWR_PRIVCFGR_PRIV4				(0x1u<<4)
#define	PWR_PRIVCFGR_PRIV3				(0x1u<<3)
#define	PWR_PRIVCFGR_PRIV2				(0x1u<<2)
#define	PWR_PRIVCFGR_PRIV1				(0x1u<<1)
#define	PWR_PRIVCFGR_PRIV0				(0x1u<<0)

#define	PWR_PRIVCFGR_WKUPPRIV4_B_0X0	(0x0u<<19)
#define	PWR_PRIVCFGR_WKUPPRIV4_B_0X1	(0x1u<<19)
#define	PWR_PRIVCFGR_WKUPPRIV3_B_0X0	(0x0u<<18)
#define	PWR_PRIVCFGR_WKUPPRIV3_B_0X1	(0x1u<<18)
#define	PWR_PRIVCFGR_WKUPPRIV2_B_0X0	(0x0u<<17)
#define	PWR_PRIVCFGR_WKUPPRIV2_B_0X1	(0x1u<<17)
#define	PWR_PRIVCFGR_WKUPPRIV1_B_0X0	(0x0u<<16)
#define	PWR_PRIVCFGR_WKUPPRIV1_B_0X1	(0x1u<<16)
#define	PWR_PRIVCFGR_PRIV7_B_0X0		(0x0u<<7)
#define	PWR_PRIVCFGR_PRIV7_B_0X1		(0x1u<<7)
#define	PWR_PRIVCFGR_PRIV6_B_0X0		(0x0u<<6)
#define	PWR_PRIVCFGR_PRIV6_B_0X1		(0x1u<<6)
#define	PWR_PRIVCFGR_PRIV5_B_0X0		(0x0u<<5)
#define	PWR_PRIVCFGR_PRIV5_B_0X1		(0x1u<<5)
#define	PWR_PRIVCFGR_PRIV4_B_0X0		(0x0u<<4)
#define	PWR_PRIVCFGR_PRIV4_B_0X1		(0x1u<<4)
#define	PWR_PRIVCFGR_PRIV3_B_0X0		(0x0u<<3)
#define	PWR_PRIVCFGR_PRIV3_B_0X1		(0x1u<<3)
#define	PWR_PRIVCFGR_PRIV2_B_0X0		(0x0u<<2)
#define	PWR_PRIVCFGR_PRIV2_B_0X1		(0x1u<<2)
#define	PWR_PRIVCFGR_PRIV1_B_0X0		(0x0u<<1)
#define	PWR_PRIVCFGR_PRIV1_B_0X1		(0x1u<<1)
#define	PWR_PRIVCFGR_PRIV0_B_0X0		(0x0u<<0)
#define	PWR_PRIVCFGR_PRIV0_B_0X1		(0x1u<<0)
