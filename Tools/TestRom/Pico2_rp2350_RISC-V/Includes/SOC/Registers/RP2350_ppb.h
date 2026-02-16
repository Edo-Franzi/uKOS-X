/*
; RP2350_ppb.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_ppb equates.
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

#include	<stdint.h>

// PPB address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	ITM_STIM0;
	volatile	uint32_t	ITM_STIM1;
	volatile	uint32_t	ITM_STIM2;
	volatile	uint32_t	ITM_STIM3;
	volatile	uint32_t	ITM_STIM4;
	volatile	uint32_t	ITM_STIM5;
	volatile	uint32_t	ITM_STIM6;
	volatile	uint32_t	ITM_STIM7;
	volatile	uint32_t	ITM_STIM8;
	volatile	uint32_t	ITM_STIM9;
	volatile	uint32_t	ITM_STIM10;
	volatile	uint32_t	ITM_STIM11;
	volatile	uint32_t	ITM_STIM12;
	volatile	uint32_t	ITM_STIM13;
	volatile	uint32_t	ITM_STIM14;
	volatile	uint32_t	ITM_STIM15;
	volatile	uint32_t	ITM_STIM16;
	volatile	uint32_t	ITM_STIM17;
	volatile	uint32_t	ITM_STIM18;
	volatile	uint32_t	ITM_STIM19;
	volatile	uint32_t	ITM_STIM20;
	volatile	uint32_t	ITM_STIM21;
	volatile	uint32_t	ITM_STIM22;
	volatile	uint32_t	ITM_STIM23;
	volatile	uint32_t	ITM_STIM24;
	volatile	uint32_t	ITM_STIM25;
	volatile	uint32_t	ITM_STIM26;
	volatile	uint32_t	ITM_STIM27;
	volatile	uint32_t	ITM_STIM28;
	volatile	uint32_t	ITM_STIM29;
	volatile	uint32_t	ITM_STIM30;
	volatile	uint32_t	ITM_STIM31;
	volatile	uint32_t	RESERVED0[864];
	volatile	uint32_t	ITM_TER0;
	volatile	uint32_t	RESERVED1[15];
	volatile	uint32_t	ITM_TPR;
	volatile	uint32_t	RESERVED2[15];
	volatile	uint32_t	ITM_TCR;
	volatile	uint32_t	RESERVED3[27];
	volatile	uint32_t	INT_ATREADY;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	INT_ATVALID;
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	ITM_ITCTRL;
	volatile	uint32_t	RESERVED6[46];
	volatile	uint32_t	ITM_DEVARCH;
	volatile	uint32_t	RESERVED7[3];
	volatile	uint32_t	ITM_DEVTYPE;
	volatile	uint32_t	ITM_PIDR4;
	volatile	uint32_t	ITM_PIDR5;
	volatile	uint32_t	ITM_PIDR6;
	volatile	uint32_t	ITM_PIDR7;
	volatile	uint32_t	ITM_PIDR0;
	volatile	uint32_t	ITM_PIDR1;
	volatile	uint32_t	ITM_PIDR2;
	volatile	uint32_t	ITM_PIDR3;
	volatile	uint32_t	ITM_CIDR0;
	volatile	uint32_t	ITM_CIDR1;
	volatile	uint32_t	ITM_CIDR2;
	volatile	uint32_t	ITM_CIDR3;
	volatile	uint32_t	DWT_CTRL;
	volatile	uint32_t	DWT_CYCCNT;
	volatile	uint32_t	RESERVED8;
	volatile	uint32_t	DWT_EXCCNT;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	DWT_LSUCNT;
	volatile	uint32_t	DWT_FOLDCNT;
	volatile	uint32_t	RESERVED10;
	volatile	uint32_t	DWT_COMP0;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	DWT_FUNCTION0;
	volatile	uint32_t	RESERVED12;
	volatile	uint32_t	DWT_COMP1;
	volatile	uint32_t	RESERVED13;
	volatile	uint32_t	DWT_FUNCTION1;
	volatile	uint32_t	RESERVED14;
	volatile	uint32_t	DWT_COMP2;
	volatile	uint32_t	RESERVED15;
	volatile	uint32_t	DWT_FUNCTION2;
	volatile	uint32_t	RESERVED16;
	volatile	uint32_t	DWT_COMP3;
	volatile	uint32_t	RESERVED17;
	volatile	uint32_t	DWT_FUNCTION3;
	volatile	uint32_t	RESERVED18[984];
	volatile	uint32_t	DWT_DEVARCH;
	volatile	uint32_t	RESERVED19[3];
	volatile	uint32_t	DWT_DEVTYPE;
	volatile	uint32_t	DWT_PIDR4;
	volatile	uint32_t	DWT_PIDR5;
	volatile	uint32_t	DWT_PIDR6;
	volatile	uint32_t	DWT_PIDR7;
	volatile	uint32_t	DWT_PIDR0;
	volatile	uint32_t	DWT_PIDR1;
	volatile	uint32_t	DWT_PIDR2;
	volatile	uint32_t	DWT_PIDR3;
	volatile	uint32_t	DWT_CIDR0;
	volatile	uint32_t	DWT_CIDR1;
	volatile	uint32_t	DWT_CIDR2;
	volatile	uint32_t	DWT_CIDR3;
	volatile	uint32_t	FP_CTRL;
	volatile	uint32_t	FP_REMAP;
	volatile	uint32_t	FP_COMP0;
	volatile	uint32_t	FP_COMP1;
	volatile	uint32_t	FP_COMP2;
	volatile	uint32_t	FP_COMP3;
	volatile	uint32_t	FP_COMP4;
	volatile	uint32_t	FP_COMP5;
	volatile	uint32_t	FP_COMP6;
	volatile	uint32_t	FP_COMP7;
	volatile	uint32_t	RESERVED20[997];
	volatile	uint32_t	FP_DEVARCH;
	volatile	uint32_t	RESERVED21[3];
	volatile	uint32_t	FP_DEVTYPE;
	volatile	uint32_t	FP_PIDR4;
	volatile	uint32_t	FP_PIDR5;
	volatile	uint32_t	FP_PIDR6;
	volatile	uint32_t	FP_PIDR7;
	volatile	uint32_t	FP_PIDR0;
	volatile	uint32_t	FP_PIDR1;
	volatile	uint32_t	FP_PIDR2;
	volatile	uint32_t	FP_PIDR3;
	volatile	uint32_t	FP_CIDR0;
	volatile	uint32_t	FP_CIDR1;
	volatile	uint32_t	FP_CIDR2;
	volatile	uint32_t	FP_CIDR3;
	volatile	uint32_t	RESERVED22[11265];
	volatile	uint32_t	ICTR;
	volatile	uint32_t	ACTLR;
	volatile	uint32_t	RESERVED23;
	volatile	uint32_t	SYST_CSR;
	volatile	uint32_t	SYST_RVR;
	volatile	uint32_t	SYST_CVR;
	volatile	uint32_t	SYST_CALIB;
	volatile	uint32_t	RESERVED24[56];
	volatile	uint32_t	NVIC_ISER0;
	volatile	uint32_t	NVIC_ISER1;
	volatile	uint32_t	RESERVED25[30];
	volatile	uint32_t	NVIC_ICER0;
	volatile	uint32_t	NVIC_ICER1;
	volatile	uint32_t	RESERVED26[30];
	volatile	uint32_t	NVIC_ISPR0;
	volatile	uint32_t	NVIC_ISPR1;
	volatile	uint32_t	RESERVED27[30];
	volatile	uint32_t	NVIC_ICPR0;
	volatile	uint32_t	NVIC_ICPR1;
	volatile	uint32_t	RESERVED28[30];
	volatile	uint32_t	NVIC_IABR0;
	volatile	uint32_t	NVIC_IABR1;
	volatile	uint32_t	RESERVED29[30];
	volatile	uint32_t	NVIC_ITNS0;
	volatile	uint32_t	NVIC_ITNS1;
	volatile	uint32_t	RESERVED30[30];
	volatile	uint32_t	NVIC_IPR0;
	volatile	uint32_t	NVIC_IPR1;
	volatile	uint32_t	NVIC_IPR2;
	volatile	uint32_t	NVIC_IPR3;
	volatile	uint32_t	NVIC_IPR4;
	volatile	uint32_t	NVIC_IPR5;
	volatile	uint32_t	NVIC_IPR6;
	volatile	uint32_t	NVIC_IPR7;
	volatile	uint32_t	NVIC_IPR8;
	volatile	uint32_t	NVIC_IPR9;
	volatile	uint32_t	NVIC_IPR10;
	volatile	uint32_t	NVIC_IPR11;
	volatile	uint32_t	NVIC_IPR12;
	volatile	uint32_t	NVIC_IPR13;
	volatile	uint32_t	NVIC_IPR14;
	volatile	uint32_t	NVIC_IPR15;
	volatile	uint32_t	RESERVED31[560];
	volatile	uint32_t	CPUID;
	volatile	uint32_t	ICSR;
	volatile	uint32_t	VTOR;
	volatile	uint32_t	AIRCR;
	volatile	uint32_t	SCR;
	volatile	uint32_t	CCR;
	volatile	uint32_t	SHPR1;
	volatile	uint32_t	SHPR2;
	volatile	uint32_t	SHPR3;
	volatile	uint32_t	SHCSR;
	volatile	uint32_t	CFSR;
	volatile	uint32_t	HFSR;
	volatile	uint32_t	DFSR;
	volatile	uint32_t	MMFAR;
	volatile	uint32_t	BFAR;
	volatile	uint32_t	RESERVED32;
	volatile	uint32_t	ID_PFR0;
	volatile	uint32_t	ID_PFR1;
	volatile	uint32_t	ID_DFR0;
	volatile	uint32_t	ID_AFR0;
	volatile	uint32_t	ID_MMFR0;
	volatile	uint32_t	ID_MMFR1;
	volatile	uint32_t	ID_MMFR2;
	volatile	uint32_t	ID_MMFR3;
	volatile	uint32_t	ID_ISAR0;
	volatile	uint32_t	ID_ISAR1;
	volatile	uint32_t	ID_ISAR2;
	volatile	uint32_t	ID_ISAR3;
	volatile	uint32_t	ID_ISAR4;
	volatile	uint32_t	ID_ISAR5;
	volatile	uint32_t	RESERVED33;
	volatile	uint32_t	CTR;
	volatile	uint32_t	RESERVED34[2];
	volatile	uint32_t	CPACR;
	volatile	uint32_t	NSACR;
	volatile	uint32_t	MPU_TYPE;
	volatile	uint32_t	MPU_CTRL;
	volatile	uint32_t	MPU_RNR;
	volatile	uint32_t	MPU_RBAR;
	volatile	uint32_t	MPU_RLAR;
	volatile	uint32_t	MPU_RBAR_A1;
	volatile	uint32_t	MPU_RLAR_A1;
	volatile	uint32_t	MPU_RBAR_A2;
	volatile	uint32_t	MPU_RLAR_A2;
	volatile	uint32_t	MPU_RBAR_A3;
	volatile	uint32_t	MPU_RLAR_A3;
	volatile	uint32_t	RESERVED35;
	volatile	uint32_t	MPU_MAIR0;
	volatile	uint32_t	MPU_MAIR1;
	volatile	uint32_t	RESERVED36[2];
	volatile	uint32_t	SAU_CTRL;
	volatile	uint32_t	SAU_TYPE;
	volatile	uint32_t	SAU_RNR;
	volatile	uint32_t	SAU_RBAR;
	volatile	uint32_t	SAU_RLAR;
	volatile	uint32_t	SFSR;
	volatile	uint32_t	SFAR;
	volatile	uint32_t	RESERVED37;
	volatile	uint32_t	DHCSR;
	volatile	uint32_t	DCRSR;
	volatile	uint32_t	DCRDR;
	volatile	uint32_t	DEMCR;
	volatile	uint32_t	RESERVED38[2];
	volatile	uint32_t	DSCSR;
	volatile	uint32_t	RESERVED39[61];
	volatile	uint32_t	STIR;
	volatile	uint32_t	RESERVED40[12];
	volatile	uint32_t	FPCCR;
	volatile	uint32_t	FPCAR;
	volatile	uint32_t	FPDSCR;
	volatile	uint32_t	MVFR0;
	volatile	uint32_t	MVFR1;
	volatile	uint32_t	MVFR2;
	volatile	uint32_t	RESERVED41[28];
	volatile	uint32_t	DDEVARCH;
	volatile	uint32_t	RESERVED42[3];
	volatile	uint32_t	DDEVTYPE;
	volatile	uint32_t	DPIDR4;
	volatile	uint32_t	DPIDR5;
	volatile	uint32_t	DPIDR6;
	volatile	uint32_t	DPIDR7;
	volatile	uint32_t	DPIDR0;
	volatile	uint32_t	DPIDR1;
	volatile	uint32_t	DPIDR2;
	volatile	uint32_t	DPIDR3;
	volatile	uint32_t	DCIDR0;
	volatile	uint32_t	DCIDR1;
	volatile	uint32_t	DCIDR2;
	volatile	uint32_t	DCIDR3;
	volatile	uint32_t	RESERVED43[51201];
	volatile	uint32_t	TRCPRGCTLR;
	volatile	uint32_t	RESERVED44;
	volatile	uint32_t	TRCSTATR;
	volatile	uint32_t	TRCCONFIGR;
	volatile	uint32_t	RESERVED45[3];
	volatile	uint32_t	TRCEVENTCTL0R;
	volatile	uint32_t	TRCEVENTCTL1R;
	volatile	uint32_t	RESERVED46;
	volatile	uint32_t	TRCSTALLCTLR;
	volatile	uint32_t	TRCTSCTLR;
	volatile	uint32_t	TRCSYNCPR;
	volatile	uint32_t	TRCCCCTLR;
	volatile	uint32_t	RESERVED47[17];
	volatile	uint32_t	TRCVICTLR;
	volatile	uint32_t	RESERVED48[47];
	volatile	uint32_t	TRCCNTRLDVR0;
	volatile	uint32_t	RESERVED49[15];
	volatile	uint32_t	TRCIDR8;
	volatile	uint32_t	TRCIDR9;
	volatile	uint32_t	TRCIDR10;
	volatile	uint32_t	TRCIDR11;
	volatile	uint32_t	TRCIDR12;
	volatile	uint32_t	TRCIDR13;
	volatile	uint32_t	RESERVED50[10];
	volatile	uint32_t	TRCIMSPEC;
	volatile	uint32_t	RESERVED51[7];
	volatile	uint32_t	TRCIDR0;
	volatile	uint32_t	TRCIDR1;
	volatile	uint32_t	TRCIDR2;
	volatile	uint32_t	TRCIDR3;
	volatile	uint32_t	TRCIDR4;
	volatile	uint32_t	TRCIDR5;
	volatile	uint32_t	TRCIDR6;
	volatile	uint32_t	TRCIDR7;
	volatile	uint32_t	RESERVED52[2];
	volatile	uint32_t	TRCRSCTLR2;
	volatile	uint32_t	TRCRSCTLR3;
	volatile	uint32_t	RESERVED53[36];
	volatile	uint32_t	TRCSSCSR;
	volatile	uint32_t	RESERVED54[7];
	volatile	uint32_t	TRCSSPCICR;
	volatile	uint32_t	RESERVED55[19];
	volatile	uint32_t	TRCPDCR;
	volatile	uint32_t	TRCPDSR;
	volatile	uint32_t	RESERVED56[755];
	volatile	uint32_t	TRCITATBIDR;
	volatile	uint32_t	RESERVED57[3];
	volatile	uint32_t	TRCITIATBINR;
	volatile	uint32_t	RESERVED58;
	volatile	uint32_t	TRCITIATBOUTR;
	volatile	uint32_t	RESERVED59[40];
	volatile	uint32_t	TRCCLAIMSET;
	volatile	uint32_t	TRCCLAIMCLR;
	volatile	uint32_t	RESERVED60[4];
	volatile	uint32_t	TRCAUTHSTATUS;
	volatile	uint32_t	TRCDEVARCH;
	volatile	uint32_t	RESERVED61[2];
	volatile	uint32_t	TRCDEVID;
	volatile	uint32_t	TRCDEVTYPE;
	volatile	uint32_t	TRCPIDR4;
	volatile	uint32_t	TRCPIDR5;
	volatile	uint32_t	TRCPIDR6;
	volatile	uint32_t	TRCPIDR7;
	volatile	uint32_t	TRCPIDR0;
	volatile	uint32_t	TRCPIDR1;
	volatile	uint32_t	TRCPIDR2;
	volatile	uint32_t	TRCPIDR3;
	volatile	uint32_t	TRCCIDR0;
	volatile	uint32_t	TRCCIDR1;
	volatile	uint32_t	TRCCIDR2;
	volatile	uint32_t	TRCCIDR3;
	volatile	uint32_t	CTICONTROL;
	volatile	uint32_t	RESERVED62[3];
	volatile	uint32_t	CTIINTACK;
	volatile	uint32_t	CTIAPPSET;
	volatile	uint32_t	CTIAPPCLEAR;
	volatile	uint32_t	CTIAPPPULSE;
	volatile	uint32_t	CTIINEN0;
	volatile	uint32_t	CTIINEN1;
	volatile	uint32_t	CTIINEN2;
	volatile	uint32_t	CTIINEN3;
	volatile	uint32_t	CTIINEN4;
	volatile	uint32_t	CTIINEN5;
	volatile	uint32_t	CTIINEN6;
	volatile	uint32_t	CTIINEN7;
	volatile	uint32_t	RESERVED63[24];
	volatile	uint32_t	CTIOUTEN0;
	volatile	uint32_t	CTIOUTEN1;
	volatile	uint32_t	CTIOUTEN2;
	volatile	uint32_t	CTIOUTEN3;
	volatile	uint32_t	CTIOUTEN4;
	volatile	uint32_t	CTIOUTEN5;
	volatile	uint32_t	CTIOUTEN6;
	volatile	uint32_t	CTIOUTEN7;
	volatile	uint32_t	RESERVED64[28];
	volatile	uint32_t	CTITRIGINSTATUS;
	volatile	uint32_t	CTITRIGOUTSTATUS;
	volatile	uint32_t	CTICHINSTATUS;
	volatile	uint32_t	RESERVED65;
	volatile	uint32_t	CTIGATE;
	volatile	uint32_t	ASICCTL;
	volatile	uint32_t	RESERVED66[871];
	volatile	uint32_t	ITCHOUT;
	volatile	uint32_t	ITTRIGOUT;
	volatile	uint32_t	RESERVED67[2];
	volatile	uint32_t	ITCHIN;
	volatile	uint32_t	RESERVED68[2];
	volatile	uint32_t	ITCTRL;
	volatile	uint32_t	RESERVED69[46];
	volatile	uint32_t	DEVARCH;
	volatile	uint32_t	RESERVED70[2];
	volatile	uint32_t	DEVID;
	volatile	uint32_t	DEVTYPE;
	volatile	uint32_t	PIDR4;
	volatile	uint32_t	PIDR5;
	volatile	uint32_t	PIDR6;
	volatile	uint32_t	PIDR7;
	volatile	uint32_t	PIDR0;
	volatile	uint32_t	PIDR1;
	volatile	uint32_t	PIDR2;
	volatile	uint32_t	PIDR3;
	volatile	uint32_t	CIDR0;
	volatile	uint32_t	CIDR1;
	volatile	uint32_t	CIDR2;
	volatile	uint32_t	CIDR3;
} PPB_TypeDef;

#ifdef __cplusplus
#define	PPB_NS	reinterpret_cast<PPB_TypeDef *>(0xE0020000u)
#define	PPB_S	reinterpret_cast<PPB_TypeDef *>(0xE0000000u)
#else
#define	PPB_NS	((PPB_TypeDef *)0xE0020000u)
#define	PPB_S	((PPB_TypeDef *)0xE0000000u)
#endif

// ITM_STIM0 Configuration

#define	PPB_ITM_STIM0_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM0_STIMULUS_0				(0x1u<<0)

// ITM_STIM1 Configuration

#define	PPB_ITM_STIM1_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM1_STIMULUS_0				(0x1u<<0)

// ITM_STIM2 Configuration

#define	PPB_ITM_STIM2_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM2_STIMULUS_0				(0x1u<<0)

// ITM_STIM3 Configuration

#define	PPB_ITM_STIM3_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM3_STIMULUS_0				(0x1u<<0)

// ITM_STIM4 Configuration

#define	PPB_ITM_STIM4_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM4_STIMULUS_0				(0x1u<<0)

// ITM_STIM5 Configuration

#define	PPB_ITM_STIM5_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM5_STIMULUS_0				(0x1u<<0)

// ITM_STIM6 Configuration

#define	PPB_ITM_STIM6_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM6_STIMULUS_0				(0x1u<<0)

// ITM_STIM7 Configuration

#define	PPB_ITM_STIM7_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM7_STIMULUS_0				(0x1u<<0)

// ITM_STIM8 Configuration

#define	PPB_ITM_STIM8_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM8_STIMULUS_0				(0x1u<<0)

// ITM_STIM9 Configuration

#define	PPB_ITM_STIM9_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM9_STIMULUS_0				(0x1u<<0)

// ITM_STIM10 Configuration

#define	PPB_ITM_STIM10_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM10_STIMULUS_0				(0x1u<<0)

// ITM_STIM11 Configuration

#define	PPB_ITM_STIM11_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM11_STIMULUS_0				(0x1u<<0)

// ITM_STIM12 Configuration

#define	PPB_ITM_STIM12_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM12_STIMULUS_0				(0x1u<<0)

// ITM_STIM13 Configuration

#define	PPB_ITM_STIM13_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM13_STIMULUS_0				(0x1u<<0)

// ITM_STIM14 Configuration

#define	PPB_ITM_STIM14_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM14_STIMULUS_0				(0x1u<<0)

// ITM_STIM15 Configuration

#define	PPB_ITM_STIM15_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM15_STIMULUS_0				(0x1u<<0)

// ITM_STIM16 Configuration

#define	PPB_ITM_STIM16_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM16_STIMULUS_0				(0x1u<<0)

// ITM_STIM17 Configuration

#define	PPB_ITM_STIM17_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM17_STIMULUS_0				(0x1u<<0)

// ITM_STIM18 Configuration

#define	PPB_ITM_STIM18_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM18_STIMULUS_0				(0x1u<<0)

// ITM_STIM19 Configuration

#define	PPB_ITM_STIM19_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM19_STIMULUS_0				(0x1u<<0)

// ITM_STIM20 Configuration

#define	PPB_ITM_STIM20_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM20_STIMULUS_0				(0x1u<<0)

// ITM_STIM21 Configuration

#define	PPB_ITM_STIM21_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM21_STIMULUS_0				(0x1u<<0)

// ITM_STIM22 Configuration

#define	PPB_ITM_STIM22_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM22_STIMULUS_0				(0x1u<<0)

// ITM_STIM23 Configuration

#define	PPB_ITM_STIM23_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM23_STIMULUS_0				(0x1u<<0)

// ITM_STIM24 Configuration

#define	PPB_ITM_STIM24_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM24_STIMULUS_0				(0x1u<<0)

// ITM_STIM25 Configuration

#define	PPB_ITM_STIM25_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM25_STIMULUS_0				(0x1u<<0)

// ITM_STIM26 Configuration

#define	PPB_ITM_STIM26_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM26_STIMULUS_0				(0x1u<<0)

// ITM_STIM27 Configuration

#define	PPB_ITM_STIM27_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM27_STIMULUS_0				(0x1u<<0)

// ITM_STIM28 Configuration

#define	PPB_ITM_STIM28_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM28_STIMULUS_0				(0x1u<<0)

// ITM_STIM29 Configuration

#define	PPB_ITM_STIM29_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM29_STIMULUS_0				(0x1u<<0)

// ITM_STIM30 Configuration

#define	PPB_ITM_STIM30_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM30_STIMULUS_0				(0x1u<<0)

// ITM_STIM31 Configuration

#define	PPB_ITM_STIM31_STIMULUS					(0xFFFFFFFFu<<0)
#define	PPB_ITM_STIM31_STIMULUS_0				(0x1u<<0)

// ITM_TER0 Configuration

#define	PPB_ITM_TER0_STIMENA					(0xFFFFFFFFu<<0)
#define	PPB_ITM_TER0_STIMENA_0					(0x1u<<0)

// ITM_TPR Configuration

#define	PPB_ITM_TPR_PRIVMASK					(0xFu<<0)
#define	PPB_ITM_TPR_PRIVMASK_0					(0x1u<<0)

// ITM_TCR Configuration

#define	PPB_ITM_TCR_ITMENA						(0x1u<<0)
#define	PPB_ITM_TCR_TSENA						(0x1u<<1)
#define	PPB_ITM_TCR_SYNCENA						(0x1u<<2)
#define	PPB_ITM_TCR_TXENA						(0x1u<<3)
#define	PPB_ITM_TCR_SWOENA						(0x1u<<4)
#define	PPB_ITM_TCR_STALLENA					(0x1u<<5)
#define	PPB_ITM_TCR_TSPRESCALE					(0x3u<<8)
#define	PPB_ITM_TCR_TSPRESCALE_0				(0x1u<<8)
#define	PPB_ITM_TCR_GTSFREQ						(0x3u<<10)
#define	PPB_ITM_TCR_GTSFREQ_0					(0x1u<<10)
#define	PPB_ITM_TCR_TRACEBUSID					(0x7Fu<<16)
#define	PPB_ITM_TCR_TRACEBUSID_0				(0x1u<<16)
#define	PPB_ITM_TCR_BUSY						(0x1u<<23)

// INT_ATREADY Configuration

#define	PPB_INT_ATREADY_ATREADY					(0x1u<<0)
#define	PPB_INT_ATREADY_AFVALID					(0x1u<<1)

// INT_ATVALID Configuration

#define	PPB_INT_ATVALID_ATREADY					(0x1u<<0)
#define	PPB_INT_ATVALID_AFREADY					(0x1u<<1)

// ITM_ITCTRL Configuration

#define	PPB_ITM_ITCTRL_IME						(0x1u<<0)

// ITM_DEVARCH Configuration

#define	PPB_ITM_DEVARCH_ARCHPART				(0xFFFu<<0)
#define	PPB_ITM_DEVARCH_ARCHPART_0				(0x1u<<0)
#define	PPB_ITM_DEVARCH_ARCHVER					(0xFu<<12)
#define	PPB_ITM_DEVARCH_ARCHVER_0				(0x1u<<12)
#define	PPB_ITM_DEVARCH_REVISION				(0xFu<<16)
#define	PPB_ITM_DEVARCH_REVISION_0				(0x1u<<16)
#define	PPB_ITM_DEVARCH_PRESENT					(0x1u<<20)
#define	PPB_ITM_DEVARCH_ARCHITECT				(0x7FFu<<21)
#define	PPB_ITM_DEVARCH_ARCHITECT_0				(0x1u<<21)

// ITM_DEVTYPE Configuration

#define	PPB_ITM_DEVTYPE_MAJOR					(0xFu<<0)
#define	PPB_ITM_DEVTYPE_MAJOR_0					(0x1u<<0)
#define	PPB_ITM_DEVTYPE_SUB						(0xFu<<4)
#define	PPB_ITM_DEVTYPE_SUB_0					(0x1u<<4)

// ITM_PIDR4 Configuration

#define	PPB_ITM_PIDR4_DES_2						(0xFu<<0)
#define	PPB_ITM_PIDR4_DES_2_0					(0x1u<<0)
#define	PPB_ITM_PIDR4_SIZE						(0xFu<<4)
#define	PPB_ITM_PIDR4_SIZE_0					(0x1u<<4)

// ITM_PIDR5 Configuration

#define	PPB_ITM_PIDR5_ITM_PIDR5					(0xFFFFFFFFu<<0)
#define	PPB_ITM_PIDR5_ITM_PIDR5_0				(0x1u<<0)

// ITM_PIDR6 Configuration

#define	PPB_ITM_PIDR6_ITM_PIDR6					(0xFFFFFFFFu<<0)
#define	PPB_ITM_PIDR6_ITM_PIDR6_0				(0x1u<<0)

// ITM_PIDR7 Configuration

#define	PPB_ITM_PIDR7_ITM_PIDR7					(0xFFFFFFFFu<<0)
#define	PPB_ITM_PIDR7_ITM_PIDR7_0				(0x1u<<0)

// ITM_PIDR0 Configuration

#define	PPB_ITM_PIDR0_PART_0					(0xFFu<<0)
#define	PPB_ITM_PIDR0_PART_0_0					(0x1u<<0)

// ITM_PIDR1 Configuration

#define	PPB_ITM_PIDR1_PART_1					(0xFu<<0)
#define	PPB_ITM_PIDR1_PART_1_0					(0x1u<<0)
#define	PPB_ITM_PIDR1_DES_0						(0xFu<<4)
#define	PPB_ITM_PIDR1_DES_0_0					(0x1u<<4)

// ITM_PIDR2 Configuration

#define	PPB_ITM_PIDR2_DES_1						(0x7u<<0)
#define	PPB_ITM_PIDR2_DES_1_0					(0x1u<<0)
#define	PPB_ITM_PIDR2_JEDEC						(0x1u<<3)
#define	PPB_ITM_PIDR2_REVISION					(0xFu<<4)
#define	PPB_ITM_PIDR2_REVISION_0				(0x1u<<4)

// ITM_PIDR3 Configuration

#define	PPB_ITM_PIDR3_CMOD						(0xFu<<0)
#define	PPB_ITM_PIDR3_CMOD_0					(0x1u<<0)
#define	PPB_ITM_PIDR3_REVAND					(0xFu<<4)
#define	PPB_ITM_PIDR3_REVAND_0					(0x1u<<4)

// ITM_CIDR0 Configuration

#define	PPB_ITM_CIDR0_PRMBL_0					(0xFFu<<0)
#define	PPB_ITM_CIDR0_PRMBL_0_0					(0x1u<<0)

// ITM_CIDR1 Configuration

#define	PPB_ITM_CIDR1_PRMBL_1					(0xFu<<0)
#define	PPB_ITM_CIDR1_PRMBL_1_0					(0x1u<<0)
#define	PPB_ITM_CIDR1_CLASS						(0xFu<<4)
#define	PPB_ITM_CIDR1_CLASS_0					(0x1u<<4)

// ITM_CIDR2 Configuration

#define	PPB_ITM_CIDR2_PRMBL_2					(0xFFu<<0)
#define	PPB_ITM_CIDR2_PRMBL_2_0					(0x1u<<0)

// ITM_CIDR3 Configuration

#define	PPB_ITM_CIDR3_PRMBL_3					(0xFFu<<0)
#define	PPB_ITM_CIDR3_PRMBL_3_0					(0x1u<<0)

// DWT_CTRL Configuration

#define	PPB_DWT_CTRL_CYCCNTENA					(0x1u<<0)
#define	PPB_DWT_CTRL_POSTPRESET					(0xFu<<1)
#define	PPB_DWT_CTRL_POSTPRESET_0				(0x1u<<1)
#define	PPB_DWT_CTRL_POSTINIT					(0xFu<<5)
#define	PPB_DWT_CTRL_POSTINIT_0					(0x1u<<5)
#define	PPB_DWT_CTRL_CYCTAP						(0x1u<<9)
#define	PPB_DWT_CTRL_SYNCTAP					(0x3u<<10)
#define	PPB_DWT_CTRL_SYNCTAP_0					(0x1u<<10)
#define	PPB_DWT_CTRL_PCSAMPLENA					(0x1u<<12)
#define	PPB_DWT_CTRL_EXTTRCENA					(0x1u<<16)
#define	PPB_DWT_CTRL_CPIEVTENA					(0x1u<<17)
#define	PPB_DWT_CTRL_EXCEVTENA					(0x1u<<18)
#define	PPB_DWT_CTRL_SLEEPEVTENA				(0x1u<<19)
#define	PPB_DWT_CTRL_LSUEVTENA					(0x1u<<20)
#define	PPB_DWT_CTRL_FOLDEVTENA					(0x1u<<21)
#define	PPB_DWT_CTRL_CYCEVTENA					(0x1u<<22)
#define	PPB_DWT_CTRL_CYCDISS					(0x1u<<23)
#define	PPB_DWT_CTRL_NOPRFCNT					(0x1u<<24)
#define	PPB_DWT_CTRL_NOCYCCNT					(0x1u<<25)
#define	PPB_DWT_CTRL_NOEXTTRIG					(0x1u<<26)
#define	PPB_DWT_CTRL_NOTRCPKT					(0x1u<<27)
#define	PPB_DWT_CTRL_NUMCOMP					(0xFu<<28)
#define	PPB_DWT_CTRL_NUMCOMP_0					(0x1u<<28)

// DWT_CYCCNT Configuration

#define	PPB_DWT_CYCCNT_CYCCNT					(0xFFFFFFFFu<<0)
#define	PPB_DWT_CYCCNT_CYCCNT_0					(0x1u<<0)

// DWT_EXCCNT Configuration

#define	PPB_DWT_EXCCNT_EXCCNT					(0xFFu<<0)
#define	PPB_DWT_EXCCNT_EXCCNT_0					(0x1u<<0)

// DWT_LSUCNT Configuration

#define	PPB_DWT_LSUCNT_LSUCNT					(0xFFu<<0)
#define	PPB_DWT_LSUCNT_LSUCNT_0					(0x1u<<0)

// DWT_FOLDCNT Configuration

#define	PPB_DWT_FOLDCNT_FOLDCNT					(0xFFu<<0)
#define	PPB_DWT_FOLDCNT_FOLDCNT_0				(0x1u<<0)

// DWT_COMP0 Configuration

#define	PPB_DWT_COMP0_DWT_COMP0					(0xFFFFFFFFu<<0)
#define	PPB_DWT_COMP0_DWT_COMP0_0				(0x1u<<0)

// DWT_FUNCTION0 Configuration

#define	PPB_DWT_FUNCTION0_MATCH					(0xFu<<0)
#define	PPB_DWT_FUNCTION0_MATCH_0				(0x1u<<0)
#define	PPB_DWT_FUNCTION0_ACTION				(0x3u<<4)
#define	PPB_DWT_FUNCTION0_ACTION_0				(0x1u<<4)
#define	PPB_DWT_FUNCTION0_DATAVSIZE				(0x3u<<10)
#define	PPB_DWT_FUNCTION0_DATAVSIZE_0			(0x1u<<10)
#define	PPB_DWT_FUNCTION0_MATCHED				(0x1u<<24)
#define	PPB_DWT_FUNCTION0_ID					(0x1Fu<<27)
#define	PPB_DWT_FUNCTION0_ID_0					(0x1u<<27)

// DWT_COMP1 Configuration

#define	PPB_DWT_COMP1_DWT_COMP1					(0xFFFFFFFFu<<0)
#define	PPB_DWT_COMP1_DWT_COMP1_0				(0x1u<<0)

// DWT_FUNCTION1 Configuration

#define	PPB_DWT_FUNCTION1_MATCH					(0xFu<<0)
#define	PPB_DWT_FUNCTION1_MATCH_0				(0x1u<<0)
#define	PPB_DWT_FUNCTION1_ACTION				(0x3u<<4)
#define	PPB_DWT_FUNCTION1_ACTION_0				(0x1u<<4)
#define	PPB_DWT_FUNCTION1_DATAVSIZE				(0x3u<<10)
#define	PPB_DWT_FUNCTION1_DATAVSIZE_0			(0x1u<<10)
#define	PPB_DWT_FUNCTION1_MATCHED				(0x1u<<24)
#define	PPB_DWT_FUNCTION1_ID					(0x1Fu<<27)
#define	PPB_DWT_FUNCTION1_ID_0					(0x1u<<27)

// DWT_COMP2 Configuration

#define	PPB_DWT_COMP2_DWT_COMP2					(0xFFFFFFFFu<<0)
#define	PPB_DWT_COMP2_DWT_COMP2_0				(0x1u<<0)

// DWT_FUNCTION2 Configuration

#define	PPB_DWT_FUNCTION2_MATCH					(0xFu<<0)
#define	PPB_DWT_FUNCTION2_MATCH_0				(0x1u<<0)
#define	PPB_DWT_FUNCTION2_ACTION				(0x3u<<4)
#define	PPB_DWT_FUNCTION2_ACTION_0				(0x1u<<4)
#define	PPB_DWT_FUNCTION2_DATAVSIZE				(0x3u<<10)
#define	PPB_DWT_FUNCTION2_DATAVSIZE_0			(0x1u<<10)
#define	PPB_DWT_FUNCTION2_MATCHED				(0x1u<<24)
#define	PPB_DWT_FUNCTION2_ID					(0x1Fu<<27)
#define	PPB_DWT_FUNCTION2_ID_0					(0x1u<<27)

// DWT_COMP3 Configuration

#define	PPB_DWT_COMP3_DWT_COMP3					(0xFFFFFFFFu<<0)
#define	PPB_DWT_COMP3_DWT_COMP3_0				(0x1u<<0)

// DWT_FUNCTION3 Configuration

#define	PPB_DWT_FUNCTION3_MATCH					(0xFu<<0)
#define	PPB_DWT_FUNCTION3_MATCH_0				(0x1u<<0)
#define	PPB_DWT_FUNCTION3_ACTION				(0x3u<<4)
#define	PPB_DWT_FUNCTION3_ACTION_0				(0x1u<<4)
#define	PPB_DWT_FUNCTION3_DATAVSIZE				(0x3u<<10)
#define	PPB_DWT_FUNCTION3_DATAVSIZE_0			(0x1u<<10)
#define	PPB_DWT_FUNCTION3_MATCHED				(0x1u<<24)
#define	PPB_DWT_FUNCTION3_ID					(0x1Fu<<27)
#define	PPB_DWT_FUNCTION3_ID_0					(0x1u<<27)

// DWT_DEVARCH Configuration

#define	PPB_DWT_DEVARCH_ARCHPART				(0xFFFu<<0)
#define	PPB_DWT_DEVARCH_ARCHPART_0				(0x1u<<0)
#define	PPB_DWT_DEVARCH_ARCHVER					(0xFu<<12)
#define	PPB_DWT_DEVARCH_ARCHVER_0				(0x1u<<12)
#define	PPB_DWT_DEVARCH_REVISION				(0xFu<<16)
#define	PPB_DWT_DEVARCH_REVISION_0				(0x1u<<16)
#define	PPB_DWT_DEVARCH_PRESENT					(0x1u<<20)
#define	PPB_DWT_DEVARCH_ARCHITECT				(0x7FFu<<21)
#define	PPB_DWT_DEVARCH_ARCHITECT_0				(0x1u<<21)

// DWT_DEVTYPE Configuration

#define	PPB_DWT_DEVTYPE_MAJOR					(0xFu<<0)
#define	PPB_DWT_DEVTYPE_MAJOR_0					(0x1u<<0)
#define	PPB_DWT_DEVTYPE_SUB						(0xFu<<4)
#define	PPB_DWT_DEVTYPE_SUB_0					(0x1u<<4)

// DWT_PIDR4 Configuration

#define	PPB_DWT_PIDR4_DES_2						(0xFu<<0)
#define	PPB_DWT_PIDR4_DES_2_0					(0x1u<<0)
#define	PPB_DWT_PIDR4_SIZE						(0xFu<<4)
#define	PPB_DWT_PIDR4_SIZE_0					(0x1u<<4)

// DWT_PIDR5 Configuration

#define	PPB_DWT_PIDR5_DWT_PIDR5					(0xFFFFFFFFu<<0)
#define	PPB_DWT_PIDR5_DWT_PIDR5_0				(0x1u<<0)

// DWT_PIDR6 Configuration

#define	PPB_DWT_PIDR6_DWT_PIDR6					(0xFFFFFFFFu<<0)
#define	PPB_DWT_PIDR6_DWT_PIDR6_0				(0x1u<<0)

// DWT_PIDR7 Configuration

#define	PPB_DWT_PIDR7_DWT_PIDR7					(0xFFFFFFFFu<<0)
#define	PPB_DWT_PIDR7_DWT_PIDR7_0				(0x1u<<0)

// DWT_PIDR0 Configuration

#define	PPB_DWT_PIDR0_PART_0					(0xFFu<<0)
#define	PPB_DWT_PIDR0_PART_0_0					(0x1u<<0)

// DWT_PIDR1 Configuration

#define	PPB_DWT_PIDR1_PART_1					(0xFu<<0)
#define	PPB_DWT_PIDR1_PART_1_0					(0x1u<<0)
#define	PPB_DWT_PIDR1_DES_0						(0xFu<<4)
#define	PPB_DWT_PIDR1_DES_0_0					(0x1u<<4)

// DWT_PIDR2 Configuration

#define	PPB_DWT_PIDR2_DES_1						(0x7u<<0)
#define	PPB_DWT_PIDR2_DES_1_0					(0x1u<<0)
#define	PPB_DWT_PIDR2_JEDEC						(0x1u<<3)
#define	PPB_DWT_PIDR2_REVISION					(0xFu<<4)
#define	PPB_DWT_PIDR2_REVISION_0				(0x1u<<4)

// DWT_PIDR3 Configuration

#define	PPB_DWT_PIDR3_CMOD						(0xFu<<0)
#define	PPB_DWT_PIDR3_CMOD_0					(0x1u<<0)
#define	PPB_DWT_PIDR3_REVAND					(0xFu<<4)
#define	PPB_DWT_PIDR3_REVAND_0					(0x1u<<4)

// DWT_CIDR0 Configuration

#define	PPB_DWT_CIDR0_PRMBL_0					(0xFFu<<0)
#define	PPB_DWT_CIDR0_PRMBL_0_0					(0x1u<<0)

// DWT_CIDR1 Configuration

#define	PPB_DWT_CIDR1_PRMBL_1					(0xFu<<0)
#define	PPB_DWT_CIDR1_PRMBL_1_0					(0x1u<<0)
#define	PPB_DWT_CIDR1_CLASS						(0xFu<<4)
#define	PPB_DWT_CIDR1_CLASS_0					(0x1u<<4)

// DWT_CIDR2 Configuration

#define	PPB_DWT_CIDR2_PRMBL_2					(0xFFu<<0)
#define	PPB_DWT_CIDR2_PRMBL_2_0					(0x1u<<0)

// DWT_CIDR3 Configuration

#define	PPB_DWT_CIDR3_PRMBL_3					(0xFFu<<0)
#define	PPB_DWT_CIDR3_PRMBL_3_0					(0x1u<<0)

// FP_CTRL Configuration

#define	PPB_FP_CTRL_ENABLE						(0x1u<<0)
#define	PPB_FP_CTRL_KEY							(0x1u<<1)
#define	PPB_FP_CTRL_NUM_CODE_7_4_				(0xFu<<4)
#define	PPB_FP_CTRL_NUM_CODE_7_4__0				(0x1u<<4)
#define	PPB_FP_CTRL_NUM_LIT						(0xFu<<8)
#define	PPB_FP_CTRL_NUM_LIT_0					(0x1u<<8)
#define	PPB_FP_CTRL_NUM_CODE_14_12_				(0x7u<<12)
#define	PPB_FP_CTRL_NUM_CODE_14_12__0			(0x1u<<12)
#define	PPB_FP_CTRL_REV							(0xFu<<28)
#define	PPB_FP_CTRL_REV_0						(0x1u<<28)

// FP_REMAP Configuration

#define	PPB_FP_REMAP_REMAP						(0xFFFFFFu<<5)
#define	PPB_FP_REMAP_REMAP_0					(0x1u<<5)
#define	PPB_FP_REMAP_RMPSPT						(0x1u<<29)

// FP_COMP0 Configuration

#define	PPB_FP_COMP0_BE							(0x1u<<0)

// FP_COMP1 Configuration

#define	PPB_FP_COMP1_BE							(0x1u<<0)

// FP_COMP2 Configuration

#define	PPB_FP_COMP2_BE							(0x1u<<0)

// FP_COMP3 Configuration

#define	PPB_FP_COMP3_BE							(0x1u<<0)

// FP_COMP4 Configuration

#define	PPB_FP_COMP4_BE							(0x1u<<0)

// FP_COMP5 Configuration

#define	PPB_FP_COMP5_BE							(0x1u<<0)

// FP_COMP6 Configuration

#define	PPB_FP_COMP6_BE							(0x1u<<0)

// FP_COMP7 Configuration

#define	PPB_FP_COMP7_BE							(0x1u<<0)

// FP_DEVARCH Configuration

#define	PPB_FP_DEVARCH_ARCHPART					(0xFFFu<<0)
#define	PPB_FP_DEVARCH_ARCHPART_0				(0x1u<<0)
#define	PPB_FP_DEVARCH_ARCHVER					(0xFu<<12)
#define	PPB_FP_DEVARCH_ARCHVER_0				(0x1u<<12)
#define	PPB_FP_DEVARCH_REVISION					(0xFu<<16)
#define	PPB_FP_DEVARCH_REVISION_0				(0x1u<<16)
#define	PPB_FP_DEVARCH_PRESENT					(0x1u<<20)
#define	PPB_FP_DEVARCH_ARCHITECT				(0x7FFu<<21)
#define	PPB_FP_DEVARCH_ARCHITECT_0				(0x1u<<21)

// FP_DEVTYPE Configuration

#define	PPB_FP_DEVTYPE_MAJOR					(0xFu<<0)
#define	PPB_FP_DEVTYPE_MAJOR_0					(0x1u<<0)
#define	PPB_FP_DEVTYPE_SUB						(0xFu<<4)
#define	PPB_FP_DEVTYPE_SUB_0					(0x1u<<4)

// FP_PIDR4 Configuration

#define	PPB_FP_PIDR4_DES_2						(0xFu<<0)
#define	PPB_FP_PIDR4_DES_2_0					(0x1u<<0)
#define	PPB_FP_PIDR4_SIZE						(0xFu<<4)
#define	PPB_FP_PIDR4_SIZE_0						(0x1u<<4)

// FP_PIDR5 Configuration

#define	PPB_FP_PIDR5_FP_PIDR5					(0xFFFFFFFFu<<0)
#define	PPB_FP_PIDR5_FP_PIDR5_0					(0x1u<<0)

// FP_PIDR6 Configuration

#define	PPB_FP_PIDR6_FP_PIDR6					(0xFFFFFFFFu<<0)
#define	PPB_FP_PIDR6_FP_PIDR6_0					(0x1u<<0)

// FP_PIDR7 Configuration

#define	PPB_FP_PIDR7_FP_PIDR7					(0xFFFFFFFFu<<0)
#define	PPB_FP_PIDR7_FP_PIDR7_0					(0x1u<<0)

// FP_PIDR0 Configuration

#define	PPB_FP_PIDR0_PART_0						(0xFFu<<0)
#define	PPB_FP_PIDR0_PART_0_0					(0x1u<<0)

// FP_PIDR1 Configuration

#define	PPB_FP_PIDR1_PART_1						(0xFu<<0)
#define	PPB_FP_PIDR1_PART_1_0					(0x1u<<0)
#define	PPB_FP_PIDR1_DES_0						(0xFu<<4)
#define	PPB_FP_PIDR1_DES_0_0					(0x1u<<4)

// FP_PIDR2 Configuration

#define	PPB_FP_PIDR2_DES_1						(0x7u<<0)
#define	PPB_FP_PIDR2_DES_1_0					(0x1u<<0)
#define	PPB_FP_PIDR2_JEDEC						(0x1u<<3)
#define	PPB_FP_PIDR2_REVISION					(0xFu<<4)
#define	PPB_FP_PIDR2_REVISION_0					(0x1u<<4)

// FP_PIDR3 Configuration

#define	PPB_FP_PIDR3_CMOD						(0xFu<<0)
#define	PPB_FP_PIDR3_CMOD_0						(0x1u<<0)
#define	PPB_FP_PIDR3_REVAND						(0xFu<<4)
#define	PPB_FP_PIDR3_REVAND_0					(0x1u<<4)

// FP_CIDR0 Configuration

#define	PPB_FP_CIDR0_PRMBL_0					(0xFFu<<0)
#define	PPB_FP_CIDR0_PRMBL_0_0					(0x1u<<0)

// FP_CIDR1 Configuration

#define	PPB_FP_CIDR1_PRMBL_1					(0xFu<<0)
#define	PPB_FP_CIDR1_PRMBL_1_0					(0x1u<<0)
#define	PPB_FP_CIDR1_CLASS						(0xFu<<4)
#define	PPB_FP_CIDR1_CLASS_0					(0x1u<<4)

// FP_CIDR2 Configuration

#define	PPB_FP_CIDR2_PRMBL_2					(0xFFu<<0)
#define	PPB_FP_CIDR2_PRMBL_2_0					(0x1u<<0)

// FP_CIDR3 Configuration

#define	PPB_FP_CIDR3_PRMBL_3					(0xFFu<<0)
#define	PPB_FP_CIDR3_PRMBL_3_0					(0x1u<<0)

// ICTR Configuration

#define	PPB_ICTR_INTLINESNUM					(0xFu<<0)
#define	PPB_ICTR_INTLINESNUM_0					(0x1u<<0)

// ACTLR Configuration

#define	PPB_ACTLR_DISMCYCINT					(0x1u<<0)
#define	PPB_ACTLR_DISFOLD						(0x1u<<2)
#define	PPB_ACTLR_DISOOFP						(0x1u<<9)
#define	PPB_ACTLR_FPEXCODIS						(0x1u<<10)
#define	PPB_ACTLR_DISITMATBFLUSH				(0x1u<<12)
#define	PPB_ACTLR_EXTEXCLALL					(0x1u<<29)

// SYST_CSR Configuration

#define	PPB_SYST_CSR_ENABLE						(0x1u<<0)
#define	PPB_SYST_CSR_TICKINT					(0x1u<<1)
#define	PPB_SYST_CSR_CLKSOURCE					(0x1u<<2)
#define	PPB_SYST_CSR_COUNTFLAG					(0x1u<<16)

// SYST_RVR Configuration

#define	PPB_SYST_RVR_RELOAD						(0xFFFFFFu<<0)
#define	PPB_SYST_RVR_RELOAD_0					(0x1u<<0)

// SYST_CVR Configuration

#define	PPB_SYST_CVR_CURRENT					(0xFFFFFFu<<0)
#define	PPB_SYST_CVR_CURRENT_0					(0x1u<<0)

// SYST_CALIB Configuration

#define	PPB_SYST_CALIB_TENMS					(0xFFFFFFu<<0)
#define	PPB_SYST_CALIB_TENMS_0					(0x1u<<0)
#define	PPB_SYST_CALIB_SKEW						(0x1u<<30)
#define	PPB_SYST_CALIB_NOREF					(0x1u<<31)

// NVIC_ISER0 Configuration

#define	PPB_NVIC_ISER0_SETENA					(0xFFFFFFFFu<<0)
#define	PPB_NVIC_ISER0_SETENA_0					(0x1u<<0)

// NVIC_ISER1 Configuration

#define	PPB_NVIC_ISER1_SETENA					(0xFFFFFFFFu<<0)
#define	PPB_NVIC_ISER1_SETENA_0					(0x1u<<0)

// NVIC_ICER0 Configuration

#define	PPB_NVIC_ICER0_CLRENA					(0xFFFFFFFFu<<0)
#define	PPB_NVIC_ICER0_CLRENA_0					(0x1u<<0)

// NVIC_ICER1 Configuration

#define	PPB_NVIC_ICER1_CLRENA					(0xFFFFFFFFu<<0)
#define	PPB_NVIC_ICER1_CLRENA_0					(0x1u<<0)

// NVIC_ISPR0 Configuration

#define	PPB_NVIC_ISPR0_SETPEND					(0xFFFFFFFFu<<0)
#define	PPB_NVIC_ISPR0_SETPEND_0				(0x1u<<0)

// NVIC_ISPR1 Configuration

#define	PPB_NVIC_ISPR1_SETPEND					(0xFFFFFFFFu<<0)
#define	PPB_NVIC_ISPR1_SETPEND_0				(0x1u<<0)

// NVIC_ICPR0 Configuration

#define	PPB_NVIC_ICPR0_CLRPEND					(0xFFFFFFFFu<<0)
#define	PPB_NVIC_ICPR0_CLRPEND_0				(0x1u<<0)

// NVIC_ICPR1 Configuration

#define	PPB_NVIC_ICPR1_CLRPEND					(0xFFFFFFFFu<<0)
#define	PPB_NVIC_ICPR1_CLRPEND_0				(0x1u<<0)

// NVIC_IABR0 Configuration

#define	PPB_NVIC_IABR0_ACTIVE					(0xFFFFFFFFu<<0)
#define	PPB_NVIC_IABR0_ACTIVE_0					(0x1u<<0)

// NVIC_IABR1 Configuration

#define	PPB_NVIC_IABR1_ACTIVE					(0xFFFFFFFFu<<0)
#define	PPB_NVIC_IABR1_ACTIVE_0					(0x1u<<0)

// NVIC_ITNS0 Configuration

#define	PPB_NVIC_ITNS0_ITNS						(0xFFFFFFFFu<<0)
#define	PPB_NVIC_ITNS0_ITNS_0					(0x1u<<0)

// NVIC_ITNS1 Configuration

#define	PPB_NVIC_ITNS1_ITNS						(0xFFFFFFFFu<<0)
#define	PPB_NVIC_ITNS1_ITNS_0					(0x1u<<0)

// NVIC_IPR0 Configuration

#define	PPB_NVIC_IPR0_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR0_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR0_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR0_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR0_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR0_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR0_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR0_PRI_N3_0					(0x1u<<28)

// NVIC_IPR1 Configuration

#define	PPB_NVIC_IPR1_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR1_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR1_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR1_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR1_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR1_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR1_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR1_PRI_N3_0					(0x1u<<28)

// NVIC_IPR2 Configuration

#define	PPB_NVIC_IPR2_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR2_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR2_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR2_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR2_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR2_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR2_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR2_PRI_N3_0					(0x1u<<28)

// NVIC_IPR3 Configuration

#define	PPB_NVIC_IPR3_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR3_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR3_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR3_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR3_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR3_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR3_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR3_PRI_N3_0					(0x1u<<28)

// NVIC_IPR4 Configuration

#define	PPB_NVIC_IPR4_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR4_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR4_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR4_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR4_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR4_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR4_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR4_PRI_N3_0					(0x1u<<28)

// NVIC_IPR5 Configuration

#define	PPB_NVIC_IPR5_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR5_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR5_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR5_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR5_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR5_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR5_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR5_PRI_N3_0					(0x1u<<28)

// NVIC_IPR6 Configuration

#define	PPB_NVIC_IPR6_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR6_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR6_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR6_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR6_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR6_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR6_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR6_PRI_N3_0					(0x1u<<28)

// NVIC_IPR7 Configuration

#define	PPB_NVIC_IPR7_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR7_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR7_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR7_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR7_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR7_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR7_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR7_PRI_N3_0					(0x1u<<28)

// NVIC_IPR8 Configuration

#define	PPB_NVIC_IPR8_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR8_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR8_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR8_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR8_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR8_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR8_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR8_PRI_N3_0					(0x1u<<28)

// NVIC_IPR9 Configuration

#define	PPB_NVIC_IPR9_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR9_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR9_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR9_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR9_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR9_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR9_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR9_PRI_N3_0					(0x1u<<28)

// NVIC_IPR10 Configuration

#define	PPB_NVIC_IPR10_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR10_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR10_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR10_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR10_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR10_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR10_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR10_PRI_N3_0					(0x1u<<28)

// NVIC_IPR11 Configuration

#define	PPB_NVIC_IPR11_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR11_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR11_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR11_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR11_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR11_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR11_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR11_PRI_N3_0					(0x1u<<28)

// NVIC_IPR12 Configuration

#define	PPB_NVIC_IPR12_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR12_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR12_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR12_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR12_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR12_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR12_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR12_PRI_N3_0					(0x1u<<28)

// NVIC_IPR13 Configuration

#define	PPB_NVIC_IPR13_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR13_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR13_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR13_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR13_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR13_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR13_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR13_PRI_N3_0					(0x1u<<28)

// NVIC_IPR14 Configuration

#define	PPB_NVIC_IPR14_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR14_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR14_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR14_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR14_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR14_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR14_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR14_PRI_N3_0					(0x1u<<28)

// NVIC_IPR15 Configuration

#define	PPB_NVIC_IPR15_PRI_N0					(0xFu<<4)
#define	PPB_NVIC_IPR15_PRI_N0_0					(0x1u<<4)
#define	PPB_NVIC_IPR15_PRI_N1					(0xFu<<12)
#define	PPB_NVIC_IPR15_PRI_N1_0					(0x1u<<12)
#define	PPB_NVIC_IPR15_PRI_N2					(0xFu<<20)
#define	PPB_NVIC_IPR15_PRI_N2_0					(0x1u<<20)
#define	PPB_NVIC_IPR15_PRI_N3					(0xFu<<28)
#define	PPB_NVIC_IPR15_PRI_N3_0					(0x1u<<28)

// CPUID Configuration

#define	PPB_CPUID_REVISION						(0xFu<<0)
#define	PPB_CPUID_REVISION_0					(0x1u<<0)
#define	PPB_CPUID_PARTNO						(0xFFFu<<4)
#define	PPB_CPUID_PARTNO_0						(0x1u<<4)
#define	PPB_CPUID_ARCHITECTURE					(0xFu<<16)
#define	PPB_CPUID_ARCHITECTURE_0				(0x1u<<16)
#define	PPB_CPUID_VARIANT						(0xFu<<20)
#define	PPB_CPUID_VARIANT_0						(0x1u<<20)
#define	PPB_CPUID_IMPLEMENTER					(0xFFu<<24)
#define	PPB_CPUID_IMPLEMENTER_0					(0x1u<<24)

// ICSR Configuration

#define	PPB_ICSR_VECTACTIVE						(0x1FFu<<0)
#define	PPB_ICSR_VECTACTIVE_0					(0x1u<<0)
#define	PPB_ICSR_RETTOBASE						(0x1u<<11)
#define	PPB_ICSR_VECTPENDING					(0x1FFu<<12)
#define	PPB_ICSR_VECTPENDING_0					(0x1u<<12)
#define	PPB_ICSR_ISRPENDING						(0x1u<<22)
#define	PPB_ICSR_ISRPREEMPT						(0x1u<<23)
#define	PPB_ICSR_STTNS							(0x1u<<24)
#define	PPB_ICSR_PENDSTCLR						(0x1u<<25)
#define	PPB_ICSR_PENDSTSET						(0x1u<<26)
#define	PPB_ICSR_PENDSVCLR						(0x1u<<27)
#define	PPB_ICSR_PENDSVSET						(0x1u<<28)
#define	PPB_ICSR_PENDNMICLR						(0x1u<<30)
#define	PPB_ICSR_PENDNMISET						(0x1u<<31)

// VTOR Configuration

#define	PPB_VTOR_TBLOFF							(0x1FFFFFFu<<7)
#define	PPB_VTOR_TBLOFF_0						(0x1u<<7)

// AIRCR Configuration

#define	PPB_AIRCR_VECTCLRACTIVE					(0x1u<<1)
#define	PPB_AIRCR_SYSRESETREQ					(0x1u<<2)
#define	PPB_AIRCR_SYSRESETREQS					(0x1u<<3)
#define	PPB_AIRCR_PRIGROUP						(0x7u<<8)
#define	PPB_AIRCR_PRIGROUP_0					(0x1u<<8)
#define	PPB_AIRCR_BFHFNMINS						(0x1u<<13)
#define	PPB_AIRCR_PRIS							(0x1u<<14)
#define	PPB_AIRCR_ENDIANESS						(0x1u<<15)
#define	PPB_AIRCR_VECTKEY						(0xFFFFu<<16)
#define	PPB_AIRCR_VECTKEY_0						(0x1u<<16)

// SCR Configuration

#define	PPB_SCR_SLEEPONEXIT						(0x1u<<1)
#define	PPB_SCR_SLEEPDEEP						(0x1u<<2)
#define	PPB_SCR_SLEEPDEEPS						(0x1u<<3)
#define	PPB_SCR_SEVONPEND						(0x1u<<4)

// CCR Configuration

#define	PPB_CCR_RES1_1							(0x1u<<0)
#define	PPB_CCR_USERSETMPEND					(0x1u<<1)
#define	PPB_CCR_UNALIGN_TRP						(0x1u<<3)
#define	PPB_CCR_DIV_0_TRP						(0x1u<<4)
#define	PPB_CCR_BFHFNMIGN						(0x1u<<8)
#define	PPB_CCR_RES1							(0x1u<<9)
#define	PPB_CCR_STKOFHFNMIGN					(0x1u<<10)
#define	PPB_CCR_DC								(0x1u<<16)
#define	PPB_CCR_IC								(0x1u<<17)
#define	PPB_CCR_BP								(0x1u<<18)

// SHPR1 Configuration

#define	PPB_SHPR1_PRI_4_3						(0x7u<<5)
#define	PPB_SHPR1_PRI_4_3_0						(0x1u<<5)
#define	PPB_SHPR1_PRI_5_3						(0x7u<<13)
#define	PPB_SHPR1_PRI_5_3_0						(0x1u<<13)
#define	PPB_SHPR1_PRI_6_3						(0x7u<<21)
#define	PPB_SHPR1_PRI_6_3_0						(0x1u<<21)
#define	PPB_SHPR1_PRI_7_3						(0x7u<<29)
#define	PPB_SHPR1_PRI_7_3_0						(0x1u<<29)

// SHPR2 Configuration

#define	PPB_SHPR2_PRI_8							(0xFFu<<0)
#define	PPB_SHPR2_PRI_8_0						(0x1u<<0)
#define	PPB_SHPR2_PRI_9							(0xFFu<<8)
#define	PPB_SHPR2_PRI_9_0						(0x1u<<8)
#define	PPB_SHPR2_PRI_10						(0xFFu<<16)
#define	PPB_SHPR2_PRI_10_0						(0x1u<<16)
#define	PPB_SHPR2_PRI_11_3						(0x7u<<29)
#define	PPB_SHPR2_PRI_11_3_0					(0x1u<<29)

// SHPR3 Configuration

#define	PPB_SHPR3_PRI_12_3						(0x7u<<5)
#define	PPB_SHPR3_PRI_12_3_0					(0x1u<<5)
#define	PPB_SHPR3_PRI_13						(0xFFu<<8)
#define	PPB_SHPR3_PRI_13_0						(0x1u<<8)
#define	PPB_SHPR3_PRI_14_3						(0x7u<<21)
#define	PPB_SHPR3_PRI_14_3_0					(0x1u<<21)
#define	PPB_SHPR3_PRI_15_3						(0x7u<<29)
#define	PPB_SHPR3_PRI_15_3_0					(0x1u<<29)

// SHCSR Configuration

#define	PPB_SHCSR_MEMFAULTACT					(0x1u<<0)
#define	PPB_SHCSR_BUSFAULTACT					(0x1u<<1)
#define	PPB_SHCSR_HARDFAULTACT					(0x1u<<2)
#define	PPB_SHCSR_USGFAULTACT					(0x1u<<3)
#define	PPB_SHCSR_SECUREFAULTACT				(0x1u<<4)
#define	PPB_SHCSR_NMIACT						(0x1u<<5)
#define	PPB_SHCSR_SVCALLACT						(0x1u<<7)
#define	PPB_SHCSR_MONITORACT					(0x1u<<8)
#define	PPB_SHCSR_PENDSVACT						(0x1u<<10)
#define	PPB_SHCSR_SYSTICKACT					(0x1u<<11)
#define	PPB_SHCSR_USGFAULTPENDED				(0x1u<<12)
#define	PPB_SHCSR_MEMFAULTPENDED				(0x1u<<13)
#define	PPB_SHCSR_BUSFAULTPENDED				(0x1u<<14)
#define	PPB_SHCSR_SVCALLPENDED					(0x1u<<15)
#define	PPB_SHCSR_MEMFAULTENA					(0x1u<<16)
#define	PPB_SHCSR_BUSFAULTENA					(0x1u<<17)
#define	PPB_SHCSR_USGFAULTENA					(0x1u<<18)
#define	PPB_SHCSR_SECUREFAULTENA				(0x1u<<19)
#define	PPB_SHCSR_SECUREFAULTPENDED				(0x1u<<20)
#define	PPB_SHCSR_HARDFAULTPENDED				(0x1u<<21)

// CFSR Configuration

#define	PPB_CFSR_MMFSR							(0xFFu<<0)
#define	PPB_CFSR_MMFSR_0						(0x1u<<0)
#define	PPB_CFSR_BFSR_IBUSERR					(0x1u<<8)
#define	PPB_CFSR_BFSR_PRECISERR					(0x1u<<9)
#define	PPB_CFSR_BFSR_IMPRECISERR				(0x1u<<10)
#define	PPB_CFSR_BFSR_UNSTKERR					(0x1u<<11)
#define	PPB_CFSR_BFSR_STKERR					(0x1u<<12)
#define	PPB_CFSR_BFSR_LSPERR					(0x1u<<13)
#define	PPB_CFSR_BFSR_BFARVALID					(0x1u<<15)
#define	PPB_CFSR_UFSR_UNDEFINSTR				(0x1u<<16)
#define	PPB_CFSR_UFSR_INVSTATE					(0x1u<<17)
#define	PPB_CFSR_UFSR_INVPC						(0x1u<<18)
#define	PPB_CFSR_UFSR_NOCP						(0x1u<<19)
#define	PPB_CFSR_UFSR_STKOF						(0x1u<<20)
#define	PPB_CFSR_UFSR_UNALIGNED					(0x1u<<24)
#define	PPB_CFSR_UFSR_DIVBYZERO					(0x1u<<25)

// HFSR Configuration

#define	PPB_HFSR_VECTTBL						(0x1u<<1)
#define	PPB_HFSR_FORCED							(0x1u<<30)
#define	PPB_HFSR_DEBUGEVT						(0x1u<<31)

// DFSR Configuration

#define	PPB_DFSR_HALTED							(0x1u<<0)
#define	PPB_DFSR_BKPT							(0x1u<<1)
#define	PPB_DFSR_DWTTRAP						(0x1u<<2)
#define	PPB_DFSR_VCATCH							(0x1u<<3)
#define	PPB_DFSR_EXTERNAL						(0x1u<<4)

// MMFAR Configuration

#define	PPB_MMFAR_ADDRESS						(0xFFFFFFFFu<<0)
#define	PPB_MMFAR_ADDRESS_0						(0x1u<<0)

// BFAR Configuration

#define	PPB_BFAR_ADDRESS						(0xFFFFFFFFu<<0)
#define	PPB_BFAR_ADDRESS_0						(0x1u<<0)

// ID_PFR0 Configuration

#define	PPB_ID_PFR0_STATE0						(0xFu<<0)
#define	PPB_ID_PFR0_STATE0_0					(0x1u<<0)
#define	PPB_ID_PFR0_STATE1						(0xFu<<4)
#define	PPB_ID_PFR0_STATE1_0					(0x1u<<4)

// ID_PFR1 Configuration

#define	PPB_ID_PFR1_SECURITY					(0xFu<<4)
#define	PPB_ID_PFR1_SECURITY_0					(0x1u<<4)
#define	PPB_ID_PFR1_MPROGMOD					(0xFu<<8)
#define	PPB_ID_PFR1_MPROGMOD_0					(0x1u<<8)

// ID_DFR0 Configuration

#define	PPB_ID_DFR0_MPROFDBG					(0xFu<<20)
#define	PPB_ID_DFR0_MPROFDBG_0					(0x1u<<20)

// ID_AFR0 Configuration

#define	PPB_ID_AFR0_IMPDEF0						(0xFu<<0)
#define	PPB_ID_AFR0_IMPDEF0_0					(0x1u<<0)
#define	PPB_ID_AFR0_IMPDEF1						(0xFu<<4)
#define	PPB_ID_AFR0_IMPDEF1_0					(0x1u<<4)
#define	PPB_ID_AFR0_IMPDEF2						(0xFu<<8)
#define	PPB_ID_AFR0_IMPDEF2_0					(0x1u<<8)
#define	PPB_ID_AFR0_IMPDEF3						(0xFu<<12)
#define	PPB_ID_AFR0_IMPDEF3_0					(0x1u<<12)

// ID_MMFR0 Configuration

#define	PPB_ID_MMFR0_PMSA						(0xFu<<4)
#define	PPB_ID_MMFR0_PMSA_0						(0x1u<<4)
#define	PPB_ID_MMFR0_OUTERSHR					(0xFu<<8)
#define	PPB_ID_MMFR0_OUTERSHR_0					(0x1u<<8)
#define	PPB_ID_MMFR0_SHARELVL					(0xFu<<12)
#define	PPB_ID_MMFR0_SHARELVL_0					(0x1u<<12)
#define	PPB_ID_MMFR0_TCM						(0xFu<<16)
#define	PPB_ID_MMFR0_TCM_0						(0x1u<<16)
#define	PPB_ID_MMFR0_AUXREG						(0xFu<<20)
#define	PPB_ID_MMFR0_AUXREG_0					(0x1u<<20)

// ID_MMFR1 Configuration

#define	PPB_ID_MMFR1_ID_MMFR1					(0xFFFFFFFFu<<0)
#define	PPB_ID_MMFR1_ID_MMFR1_0					(0x1u<<0)

// ID_MMFR2 Configuration

#define	PPB_ID_MMFR2_WFISTALL					(0xFu<<24)
#define	PPB_ID_MMFR2_WFISTALL_0					(0x1u<<24)

// ID_MMFR3 Configuration

#define	PPB_ID_MMFR3_CMAINTVA					(0xFu<<0)
#define	PPB_ID_MMFR3_CMAINTVA_0					(0x1u<<0)
#define	PPB_ID_MMFR3_CMAINTSW					(0xFu<<4)
#define	PPB_ID_MMFR3_CMAINTSW_0					(0x1u<<4)
#define	PPB_ID_MMFR3_BPMAINT					(0xFu<<8)
#define	PPB_ID_MMFR3_BPMAINT_0					(0x1u<<8)

// ID_ISAR0 Configuration

#define	PPB_ID_ISAR0_BITCOUNT					(0xFu<<4)
#define	PPB_ID_ISAR0_BITCOUNT_0					(0x1u<<4)
#define	PPB_ID_ISAR0_BITFIELD					(0xFu<<8)
#define	PPB_ID_ISAR0_BITFIELD_0					(0x1u<<8)
#define	PPB_ID_ISAR0_CMPBRANCH					(0xFu<<12)
#define	PPB_ID_ISAR0_CMPBRANCH_0				(0x1u<<12)
#define	PPB_ID_ISAR0_COPROC						(0xFu<<16)
#define	PPB_ID_ISAR0_COPROC_0					(0x1u<<16)
#define	PPB_ID_ISAR0_DEBUG						(0xFu<<20)
#define	PPB_ID_ISAR0_DEBUG_0					(0x1u<<20)
#define	PPB_ID_ISAR0_DIVIDE						(0xFu<<24)
#define	PPB_ID_ISAR0_DIVIDE_0					(0x1u<<24)

// ID_ISAR1 Configuration

#define	PPB_ID_ISAR1_EXTEND						(0xFu<<12)
#define	PPB_ID_ISAR1_EXTEND_0					(0x1u<<12)
#define	PPB_ID_ISAR1_IFTHEN						(0xFu<<16)
#define	PPB_ID_ISAR1_IFTHEN_0					(0x1u<<16)
#define	PPB_ID_ISAR1_IMMEDIATE					(0xFu<<20)
#define	PPB_ID_ISAR1_IMMEDIATE_0				(0x1u<<20)
#define	PPB_ID_ISAR1_INTERWORK					(0xFu<<24)
#define	PPB_ID_ISAR1_INTERWORK_0				(0x1u<<24)

// ID_ISAR2 Configuration

#define	PPB_ID_ISAR2_LOADSTORE					(0xFu<<0)
#define	PPB_ID_ISAR2_LOADSTORE_0				(0x1u<<0)
#define	PPB_ID_ISAR2_MEMHINT					(0xFu<<4)
#define	PPB_ID_ISAR2_MEMHINT_0					(0x1u<<4)
#define	PPB_ID_ISAR2_MULTIACCESSINT				(0xFu<<8)
#define	PPB_ID_ISAR2_MULTIACCESSINT_0			(0x1u<<8)
#define	PPB_ID_ISAR2_MULT						(0xFu<<12)
#define	PPB_ID_ISAR2_MULT_0						(0x1u<<12)
#define	PPB_ID_ISAR2_MULTS						(0xFu<<16)
#define	PPB_ID_ISAR2_MULTS_0					(0x1u<<16)
#define	PPB_ID_ISAR2_MULTU						(0xFu<<20)
#define	PPB_ID_ISAR2_MULTU_0					(0x1u<<20)
#define	PPB_ID_ISAR2_REVERSAL					(0xFu<<28)
#define	PPB_ID_ISAR2_REVERSAL_0					(0x1u<<28)

// ID_ISAR3 Configuration

#define	PPB_ID_ISAR3_SATURATE					(0xFu<<0)
#define	PPB_ID_ISAR3_SATURATE_0					(0x1u<<0)
#define	PPB_ID_ISAR3_SIMD						(0xFu<<4)
#define	PPB_ID_ISAR3_SIMD_0						(0x1u<<4)
#define	PPB_ID_ISAR3_SVC						(0xFu<<8)
#define	PPB_ID_ISAR3_SVC_0						(0x1u<<8)
#define	PPB_ID_ISAR3_SYNCHPRIM					(0xFu<<12)
#define	PPB_ID_ISAR3_SYNCHPRIM_0				(0x1u<<12)
#define	PPB_ID_ISAR3_TABBRANCH					(0xFu<<16)
#define	PPB_ID_ISAR3_TABBRANCH_0				(0x1u<<16)
#define	PPB_ID_ISAR3_T32COPY					(0xFu<<20)
#define	PPB_ID_ISAR3_T32COPY_0					(0x1u<<20)
#define	PPB_ID_ISAR3_TRUENOP					(0xFu<<24)
#define	PPB_ID_ISAR3_TRUENOP_0					(0x1u<<24)

// ID_ISAR4 Configuration

#define	PPB_ID_ISAR4_UNPRIV						(0xFu<<0)
#define	PPB_ID_ISAR4_UNPRIV_0					(0x1u<<0)
#define	PPB_ID_ISAR4_WITHSHIFTS					(0xFu<<4)
#define	PPB_ID_ISAR4_WITHSHIFTS_0				(0x1u<<4)
#define	PPB_ID_ISAR4_WRITEBACK					(0xFu<<8)
#define	PPB_ID_ISAR4_WRITEBACK_0				(0x1u<<8)
#define	PPB_ID_ISAR4_BARRIER					(0xFu<<16)
#define	PPB_ID_ISAR4_BARRIER_0					(0x1u<<16)
#define	PPB_ID_ISAR4_SYNCPRIM_FRAC				(0xFu<<20)
#define	PPB_ID_ISAR4_SYNCPRIM_FRAC_0			(0x1u<<20)
#define	PPB_ID_ISAR4_PSR_M						(0xFu<<24)
#define	PPB_ID_ISAR4_PSR_M_0					(0x1u<<24)

// ID_ISAR5 Configuration

#define	PPB_ID_ISAR5_ID_ISAR5					(0xFFFFFFFFu<<0)
#define	PPB_ID_ISAR5_ID_ISAR5_0					(0x1u<<0)

// CTR Configuration

#define	PPB_CTR_IMINLINE						(0xFu<<0)
#define	PPB_CTR_IMINLINE_0						(0x1u<<0)
#define	PPB_CTR_RES1_1							(0x3u<<14)
#define	PPB_CTR_RES1_1_0						(0x1u<<14)
#define	PPB_CTR_DMINLINE						(0xFu<<16)
#define	PPB_CTR_DMINLINE_0						(0x1u<<16)
#define	PPB_CTR_ERG								(0xFu<<20)
#define	PPB_CTR_ERG_0							(0x1u<<20)
#define	PPB_CTR_CWG								(0xFu<<24)
#define	PPB_CTR_CWG_0							(0x1u<<24)
#define	PPB_CTR_RES1							(0x1u<<31)

// CPACR Configuration

#define	PPB_CPACR_CP0							(0x3u<<0)
#define	PPB_CPACR_CP0_0							(0x1u<<0)
#define	PPB_CPACR_CP1							(0x3u<<2)
#define	PPB_CPACR_CP1_0							(0x1u<<2)
#define	PPB_CPACR_CP2							(0x3u<<4)
#define	PPB_CPACR_CP2_0							(0x1u<<4)
#define	PPB_CPACR_CP3							(0x3u<<6)
#define	PPB_CPACR_CP3_0							(0x1u<<6)
#define	PPB_CPACR_CP4							(0x3u<<8)
#define	PPB_CPACR_CP4_0							(0x1u<<8)
#define	PPB_CPACR_CP5							(0x3u<<10)
#define	PPB_CPACR_CP5_0							(0x1u<<10)
#define	PPB_CPACR_CP6							(0x3u<<12)
#define	PPB_CPACR_CP6_0							(0x1u<<12)
#define	PPB_CPACR_CP7							(0x3u<<14)
#define	PPB_CPACR_CP7_0							(0x1u<<14)
#define	PPB_CPACR_CP10							(0x3u<<20)
#define	PPB_CPACR_CP10_0						(0x1u<<20)
#define	PPB_CPACR_CP11							(0x3u<<22)
#define	PPB_CPACR_CP11_0						(0x1u<<22)

// NSACR Configuration

#define	PPB_NSACR_CP0							(0x1u<<0)
#define	PPB_NSACR_CP1							(0x1u<<1)
#define	PPB_NSACR_CP2							(0x1u<<2)
#define	PPB_NSACR_CP3							(0x1u<<3)
#define	PPB_NSACR_CP4							(0x1u<<4)
#define	PPB_NSACR_CP5							(0x1u<<5)
#define	PPB_NSACR_CP6							(0x1u<<6)
#define	PPB_NSACR_CP7							(0x1u<<7)
#define	PPB_NSACR_CP10							(0x1u<<10)
#define	PPB_NSACR_CP11							(0x1u<<11)

// MPU_TYPE Configuration

#define	PPB_MPU_TYPE_SEPARATE					(0x1u<<0)
#define	PPB_MPU_TYPE_DREGION					(0xFFu<<8)
#define	PPB_MPU_TYPE_DREGION_0					(0x1u<<8)

// MPU_CTRL Configuration

#define	PPB_MPU_CTRL_ENABLE						(0x1u<<0)
#define	PPB_MPU_CTRL_HFNMIENA					(0x1u<<1)
#define	PPB_MPU_CTRL_PRIVDEFENA					(0x1u<<2)

// MPU_RNR Configuration

#define	PPB_MPU_RNR_REGION						(0x7u<<0)
#define	PPB_MPU_RNR_REGION_0					(0x1u<<0)

// MPU_RBAR Configuration

#define	PPB_MPU_RBAR_XN							(0x1u<<0)
#define	PPB_MPU_RBAR_AP							(0x3u<<1)
#define	PPB_MPU_RBAR_AP_0						(0x1u<<1)
#define	PPB_MPU_RBAR_SH							(0x3u<<3)
#define	PPB_MPU_RBAR_SH_0						(0x1u<<3)
#define	PPB_MPU_RBAR_BASE						(0x7FFFFFFu<<5)
#define	PPB_MPU_RBAR_BASE_0						(0x1u<<5)

// MPU_RLAR Configuration

#define	PPB_MPU_RLAR_EN							(0x1u<<0)
#define	PPB_MPU_RLAR_ATTRINDX					(0x7u<<1)
#define	PPB_MPU_RLAR_ATTRINDX_0					(0x1u<<1)
#define	PPB_MPU_RLAR_LIMIT						(0x7FFFFFFu<<5)
#define	PPB_MPU_RLAR_LIMIT_0					(0x1u<<5)

// MPU_RBAR_A1 Configuration

#define	PPB_MPU_RBAR_A1_XN						(0x1u<<0)
#define	PPB_MPU_RBAR_A1_AP						(0x3u<<1)
#define	PPB_MPU_RBAR_A1_AP_0					(0x1u<<1)
#define	PPB_MPU_RBAR_A1_SH						(0x3u<<3)
#define	PPB_MPU_RBAR_A1_SH_0					(0x1u<<3)
#define	PPB_MPU_RBAR_A1_BASE					(0x7FFFFFFu<<5)
#define	PPB_MPU_RBAR_A1_BASE_0					(0x1u<<5)

// MPU_RLAR_A1 Configuration

#define	PPB_MPU_RLAR_A1_EN						(0x1u<<0)
#define	PPB_MPU_RLAR_A1_ATTRINDX				(0x7u<<1)
#define	PPB_MPU_RLAR_A1_ATTRINDX_0				(0x1u<<1)
#define	PPB_MPU_RLAR_A1_LIMIT					(0x7FFFFFFu<<5)
#define	PPB_MPU_RLAR_A1_LIMIT_0					(0x1u<<5)

// MPU_RBAR_A2 Configuration

#define	PPB_MPU_RBAR_A2_XN						(0x1u<<0)
#define	PPB_MPU_RBAR_A2_AP						(0x3u<<1)
#define	PPB_MPU_RBAR_A2_AP_0					(0x1u<<1)
#define	PPB_MPU_RBAR_A2_SH						(0x3u<<3)
#define	PPB_MPU_RBAR_A2_SH_0					(0x1u<<3)
#define	PPB_MPU_RBAR_A2_BASE					(0x7FFFFFFu<<5)
#define	PPB_MPU_RBAR_A2_BASE_0					(0x1u<<5)

// MPU_RLAR_A2 Configuration

#define	PPB_MPU_RLAR_A2_EN						(0x1u<<0)
#define	PPB_MPU_RLAR_A2_ATTRINDX				(0x7u<<1)
#define	PPB_MPU_RLAR_A2_ATTRINDX_0				(0x1u<<1)
#define	PPB_MPU_RLAR_A2_LIMIT					(0x7FFFFFFu<<5)
#define	PPB_MPU_RLAR_A2_LIMIT_0					(0x1u<<5)

// MPU_RBAR_A3 Configuration

#define	PPB_MPU_RBAR_A3_XN						(0x1u<<0)
#define	PPB_MPU_RBAR_A3_AP						(0x3u<<1)
#define	PPB_MPU_RBAR_A3_AP_0					(0x1u<<1)
#define	PPB_MPU_RBAR_A3_SH						(0x3u<<3)
#define	PPB_MPU_RBAR_A3_SH_0					(0x1u<<3)
#define	PPB_MPU_RBAR_A3_BASE					(0x7FFFFFFu<<5)
#define	PPB_MPU_RBAR_A3_BASE_0					(0x1u<<5)

// MPU_RLAR_A3 Configuration

#define	PPB_MPU_RLAR_A3_EN						(0x1u<<0)
#define	PPB_MPU_RLAR_A3_ATTRINDX				(0x7u<<1)
#define	PPB_MPU_RLAR_A3_ATTRINDX_0				(0x1u<<1)
#define	PPB_MPU_RLAR_A3_LIMIT					(0x7FFFFFFu<<5)
#define	PPB_MPU_RLAR_A3_LIMIT_0					(0x1u<<5)

// MPU_MAIR0 Configuration

#define	PPB_MPU_MAIR0_ATTR0						(0xFFu<<0)
#define	PPB_MPU_MAIR0_ATTR0_0					(0x1u<<0)
#define	PPB_MPU_MAIR0_ATTR1						(0xFFu<<8)
#define	PPB_MPU_MAIR0_ATTR1_0					(0x1u<<8)
#define	PPB_MPU_MAIR0_ATTR2						(0xFFu<<16)
#define	PPB_MPU_MAIR0_ATTR2_0					(0x1u<<16)
#define	PPB_MPU_MAIR0_ATTR3						(0xFFu<<24)
#define	PPB_MPU_MAIR0_ATTR3_0					(0x1u<<24)

// MPU_MAIR1 Configuration

#define	PPB_MPU_MAIR1_ATTR4						(0xFFu<<0)
#define	PPB_MPU_MAIR1_ATTR4_0					(0x1u<<0)
#define	PPB_MPU_MAIR1_ATTR5						(0xFFu<<8)
#define	PPB_MPU_MAIR1_ATTR5_0					(0x1u<<8)
#define	PPB_MPU_MAIR1_ATTR6						(0xFFu<<16)
#define	PPB_MPU_MAIR1_ATTR6_0					(0x1u<<16)
#define	PPB_MPU_MAIR1_ATTR7						(0xFFu<<24)
#define	PPB_MPU_MAIR1_ATTR7_0					(0x1u<<24)

// SAU_CTRL Configuration

#define	PPB_SAU_CTRL_ENABLE						(0x1u<<0)
#define	PPB_SAU_CTRL_ALLNS						(0x1u<<1)

// SAU_TYPE Configuration

#define	PPB_SAU_TYPE_SREGION					(0xFFu<<0)
#define	PPB_SAU_TYPE_SREGION_0					(0x1u<<0)

// SAU_RNR Configuration

#define	PPB_SAU_RNR_REGION						(0xFFu<<0)
#define	PPB_SAU_RNR_REGION_0					(0x1u<<0)

// SAU_RBAR Configuration

#define	PPB_SAU_RBAR_BADDR						(0x7FFFFFFu<<5)
#define	PPB_SAU_RBAR_BADDR_0					(0x1u<<5)

// SAU_RLAR Configuration

#define	PPB_SAU_RLAR_ENABLE						(0x1u<<0)
#define	PPB_SAU_RLAR_NSC						(0x1u<<1)
#define	PPB_SAU_RLAR_LADDR						(0x7FFFFFFu<<5)
#define	PPB_SAU_RLAR_LADDR_0					(0x1u<<5)

// SFSR Configuration

#define	PPB_SFSR_INVEP							(0x1u<<0)
#define	PPB_SFSR_INVIS							(0x1u<<1)
#define	PPB_SFSR_INVER							(0x1u<<2)
#define	PPB_SFSR_AUVIOL							(0x1u<<3)
#define	PPB_SFSR_INVTRAN						(0x1u<<4)
#define	PPB_SFSR_LSPERR							(0x1u<<5)
#define	PPB_SFSR_SFARVALID						(0x1u<<6)
#define	PPB_SFSR_LSERR							(0x1u<<7)

// SFAR Configuration

#define	PPB_SFAR_ADDRESS						(0xFFFFFFFFu<<0)
#define	PPB_SFAR_ADDRESS_0						(0x1u<<0)

// DHCSR Configuration

#define	PPB_DHCSR_C_DEBUGEN						(0x1u<<0)
#define	PPB_DHCSR_C_HALT						(0x1u<<1)
#define	PPB_DHCSR_C_STEP						(0x1u<<2)
#define	PPB_DHCSR_C_MASKINTS					(0x1u<<3)
#define	PPB_DHCSR_C_SNAPSTALL					(0x1u<<5)
#define	PPB_DHCSR_S_REGRDY						(0x1u<<16)
#define	PPB_DHCSR_S_HALT						(0x1u<<17)
#define	PPB_DHCSR_S_SLEEP						(0x1u<<18)
#define	PPB_DHCSR_S_LOCKUP						(0x1u<<19)
#define	PPB_DHCSR_S_SDE							(0x1u<<20)
#define	PPB_DHCSR_S_RETIRE_ST					(0x1u<<24)
#define	PPB_DHCSR_S_RESET_ST					(0x1u<<25)
#define	PPB_DHCSR_S_RESTART_ST					(0x1u<<26)

// DCRSR Configuration

#define	PPB_DCRSR_REGSEL						(0x7Fu<<0)
#define	PPB_DCRSR_REGSEL_0						(0x1u<<0)
#define	PPB_DCRSR_REGWNR						(0x1u<<16)

// DCRDR Configuration

#define	PPB_DCRDR_DBGTMP						(0xFFFFFFFFu<<0)
#define	PPB_DCRDR_DBGTMP_0						(0x1u<<0)

// DEMCR Configuration

#define	PPB_DEMCR_VC_CORERESET					(0x1u<<0)
#define	PPB_DEMCR_VC_MMERR						(0x1u<<4)
#define	PPB_DEMCR_VC_NOCPERR					(0x1u<<5)
#define	PPB_DEMCR_VC_CHKERR						(0x1u<<6)
#define	PPB_DEMCR_VC_STATERR					(0x1u<<7)
#define	PPB_DEMCR_VC_BUSERR						(0x1u<<8)
#define	PPB_DEMCR_VC_INTERR						(0x1u<<9)
#define	PPB_DEMCR_VC_HARDERR					(0x1u<<10)
#define	PPB_DEMCR_VC_SFERR						(0x1u<<11)
#define	PPB_DEMCR_MON_EN						(0x1u<<16)
#define	PPB_DEMCR_MON_PEND						(0x1u<<17)
#define	PPB_DEMCR_MON_STEP						(0x1u<<18)
#define	PPB_DEMCR_MON_REQ						(0x1u<<19)
#define	PPB_DEMCR_SDME							(0x1u<<20)
#define	PPB_DEMCR_TRCENA						(0x1u<<24)

// DSCSR Configuration

#define	PPB_DSCSR_SBRSELEN						(0x1u<<0)
#define	PPB_DSCSR_SBRSEL						(0x1u<<1)
#define	PPB_DSCSR_CDS							(0x1u<<16)
#define	PPB_DSCSR_CDSKEY						(0x1u<<17)

// STIR Configuration

#define	PPB_STIR_INTID							(0x1FFu<<0)
#define	PPB_STIR_INTID_0						(0x1u<<0)

// FPCCR Configuration

#define	PPB_FPCCR_LSPACT						(0x1u<<0)
#define	PPB_FPCCR_USER							(0x1u<<1)
#define	PPB_FPCCR_S								(0x1u<<2)
#define	PPB_FPCCR_THREAD						(0x1u<<3)
#define	PPB_FPCCR_HFRDY							(0x1u<<4)
#define	PPB_FPCCR_MMRDY							(0x1u<<5)
#define	PPB_FPCCR_BFRDY							(0x1u<<6)
#define	PPB_FPCCR_SFRDY							(0x1u<<7)
#define	PPB_FPCCR_MONRDY						(0x1u<<8)
#define	PPB_FPCCR_SPLIMVIOL						(0x1u<<9)
#define	PPB_FPCCR_UFRDY							(0x1u<<10)
#define	PPB_FPCCR_TS							(0x1u<<26)
#define	PPB_FPCCR_CLRONRETS						(0x1u<<27)
#define	PPB_FPCCR_CLRONRET						(0x1u<<28)
#define	PPB_FPCCR_LSPENS						(0x1u<<29)
#define	PPB_FPCCR_LSPEN							(0x1u<<30)
#define	PPB_FPCCR_ASPEN							(0x1u<<31)

// FPCAR Configuration

#define	PPB_FPCAR_ADDRESS						(0x1FFFFFFFu<<3)
#define	PPB_FPCAR_ADDRESS_0						(0x1u<<3)

// FPDSCR Configuration

#define	PPB_FPDSCR_RMODE						(0x3u<<22)
#define	PPB_FPDSCR_RMODE_0						(0x1u<<22)
#define	PPB_FPDSCR_FZ							(0x1u<<24)
#define	PPB_FPDSCR_DN							(0x1u<<25)
#define	PPB_FPDSCR_AHP							(0x1u<<26)

// MVFR0 Configuration

#define	PPB_MVFR0_SIMDREG						(0xFu<<0)
#define	PPB_MVFR0_SIMDREG_0						(0x1u<<0)
#define	PPB_MVFR0_FPSP							(0xFu<<4)
#define	PPB_MVFR0_FPSP_0						(0x1u<<4)
#define	PPB_MVFR0_FPDP							(0xFu<<8)
#define	PPB_MVFR0_FPDP_0						(0x1u<<8)
#define	PPB_MVFR0_FPDIVIDE						(0xFu<<16)
#define	PPB_MVFR0_FPDIVIDE_0					(0x1u<<16)
#define	PPB_MVFR0_FPSQRT						(0xFu<<20)
#define	PPB_MVFR0_FPSQRT_0						(0x1u<<20)
#define	PPB_MVFR0_FPROUND						(0xFu<<28)
#define	PPB_MVFR0_FPROUND_0						(0x1u<<28)

// MVFR1 Configuration

#define	PPB_MVFR1_FPFTZ							(0xFu<<0)
#define	PPB_MVFR1_FPFTZ_0						(0x1u<<0)
#define	PPB_MVFR1_FPDNAN						(0xFu<<4)
#define	PPB_MVFR1_FPDNAN_0						(0x1u<<4)
#define	PPB_MVFR1_FPHP							(0xFu<<24)
#define	PPB_MVFR1_FPHP_0						(0x1u<<24)
#define	PPB_MVFR1_FMAC							(0xFu<<28)
#define	PPB_MVFR1_FMAC_0						(0x1u<<28)

// MVFR2 Configuration

#define	PPB_MVFR2_FPMISC						(0xFu<<4)
#define	PPB_MVFR2_FPMISC_0						(0x1u<<4)

// DDEVARCH Configuration

#define	PPB_DDEVARCH_ARCHPART					(0xFFFu<<0)
#define	PPB_DDEVARCH_ARCHPART_0					(0x1u<<0)
#define	PPB_DDEVARCH_ARCHVER					(0xFu<<12)
#define	PPB_DDEVARCH_ARCHVER_0					(0x1u<<12)
#define	PPB_DDEVARCH_REVISION					(0xFu<<16)
#define	PPB_DDEVARCH_REVISION_0					(0x1u<<16)
#define	PPB_DDEVARCH_PRESENT					(0x1u<<20)
#define	PPB_DDEVARCH_ARCHITECT					(0x7FFu<<21)
#define	PPB_DDEVARCH_ARCHITECT_0				(0x1u<<21)

// DDEVTYPE Configuration

#define	PPB_DDEVTYPE_MAJOR						(0xFu<<0)
#define	PPB_DDEVTYPE_MAJOR_0					(0x1u<<0)
#define	PPB_DDEVTYPE_SUB						(0xFu<<4)
#define	PPB_DDEVTYPE_SUB_0						(0x1u<<4)

// DPIDR4 Configuration

#define	PPB_DPIDR4_DES_2						(0xFu<<0)
#define	PPB_DPIDR4_DES_2_0						(0x1u<<0)
#define	PPB_DPIDR4_SIZE							(0xFu<<4)
#define	PPB_DPIDR4_SIZE_0						(0x1u<<4)

// DPIDR5 Configuration

#define	PPB_DPIDR5_DPIDR5						(0xFFFFFFFFu<<0)
#define	PPB_DPIDR5_DPIDR5_0						(0x1u<<0)

// DPIDR6 Configuration

#define	PPB_DPIDR6_DPIDR6						(0xFFFFFFFFu<<0)
#define	PPB_DPIDR6_DPIDR6_0						(0x1u<<0)

// DPIDR7 Configuration

#define	PPB_DPIDR7_DPIDR7						(0xFFFFFFFFu<<0)
#define	PPB_DPIDR7_DPIDR7_0						(0x1u<<0)

// DPIDR0 Configuration

#define	PPB_DPIDR0_PART_0						(0xFFu<<0)
#define	PPB_DPIDR0_PART_0_0						(0x1u<<0)

// DPIDR1 Configuration

#define	PPB_DPIDR1_PART_1						(0xFu<<0)
#define	PPB_DPIDR1_PART_1_0						(0x1u<<0)
#define	PPB_DPIDR1_DES_0						(0xFu<<4)
#define	PPB_DPIDR1_DES_0_0						(0x1u<<4)

// DPIDR2 Configuration

#define	PPB_DPIDR2_DES_1						(0x7u<<0)
#define	PPB_DPIDR2_DES_1_0						(0x1u<<0)
#define	PPB_DPIDR2_JEDEC						(0x1u<<3)
#define	PPB_DPIDR2_REVISION						(0xFu<<4)
#define	PPB_DPIDR2_REVISION_0					(0x1u<<4)

// DPIDR3 Configuration

#define	PPB_DPIDR3_CMOD							(0xFu<<0)
#define	PPB_DPIDR3_CMOD_0						(0x1u<<0)
#define	PPB_DPIDR3_REVAND						(0xFu<<4)
#define	PPB_DPIDR3_REVAND_0						(0x1u<<4)

// DCIDR0 Configuration

#define	PPB_DCIDR0_PRMBL_0						(0xFFu<<0)
#define	PPB_DCIDR0_PRMBL_0_0					(0x1u<<0)

// DCIDR1 Configuration

#define	PPB_DCIDR1_PRMBL_1						(0xFu<<0)
#define	PPB_DCIDR1_PRMBL_1_0					(0x1u<<0)
#define	PPB_DCIDR1_CLASS						(0xFu<<4)
#define	PPB_DCIDR1_CLASS_0						(0x1u<<4)

// DCIDR2 Configuration

#define	PPB_DCIDR2_PRMBL_2						(0xFFu<<0)
#define	PPB_DCIDR2_PRMBL_2_0					(0x1u<<0)

// DCIDR3 Configuration

#define	PPB_DCIDR3_PRMBL_3						(0xFFu<<0)
#define	PPB_DCIDR3_PRMBL_3_0					(0x1u<<0)

// TRCPRGCTLR Configuration

#define	PPB_TRCPRGCTLR_EN						(0x1u<<0)

// TRCSTATR Configuration

#define	PPB_TRCSTATR_IDLE						(0x1u<<0)
#define	PPB_TRCSTATR_PMSTABLE					(0x1u<<1)

// TRCCONFIGR Configuration

#define	PPB_TRCCONFIGR_BB						(0x1u<<3)
#define	PPB_TRCCONFIGR_CCI						(0x1u<<4)
#define	PPB_TRCCONFIGR_COND						(0x3Fu<<5)
#define	PPB_TRCCONFIGR_COND_0					(0x1u<<5)
#define	PPB_TRCCONFIGR_TS						(0x1u<<11)
#define	PPB_TRCCONFIGR_RS						(0x1u<<12)

// TRCEVENTCTL0R Configuration

#define	PPB_TRCEVENTCTL0R_SEL0					(0x7u<<0)
#define	PPB_TRCEVENTCTL0R_SEL0_0				(0x1u<<0)
#define	PPB_TRCEVENTCTL0R_TYPE0					(0x1u<<7)
#define	PPB_TRCEVENTCTL0R_SEL1					(0x7u<<8)
#define	PPB_TRCEVENTCTL0R_SEL1_0				(0x1u<<8)
#define	PPB_TRCEVENTCTL0R_TYPE1					(0x1u<<15)

// TRCEVENTCTL1R Configuration

#define	PPB_TRCEVENTCTL1R_INSTEN0				(0x1u<<0)
#define	PPB_TRCEVENTCTL1R_INSTEN1				(0x1u<<1)
#define	PPB_TRCEVENTCTL1R_ATB					(0x1u<<11)
#define	PPB_TRCEVENTCTL1R_LPOVERRIDE			(0x1u<<12)

// TRCSTALLCTLR Configuration

#define	PPB_TRCSTALLCTLR_LEVEL					(0x3u<<2)
#define	PPB_TRCSTALLCTLR_LEVEL_0				(0x1u<<2)
#define	PPB_TRCSTALLCTLR_ISTALL					(0x1u<<8)
#define	PPB_TRCSTALLCTLR_INSTPRIORITY			(0x1u<<10)

// TRCTSCTLR Configuration

#define	PPB_TRCTSCTLR_SEL0						(0x3u<<0)
#define	PPB_TRCTSCTLR_SEL0_0					(0x1u<<0)
#define	PPB_TRCTSCTLR_TYPE0						(0x1u<<7)

// TRCSYNCPR Configuration

#define	PPB_TRCSYNCPR_PERIOD					(0x1Fu<<0)
#define	PPB_TRCSYNCPR_PERIOD_0					(0x1u<<0)

// TRCCCCTLR Configuration

#define	PPB_TRCCCCTLR_THRESHOLD					(0xFFFu<<0)
#define	PPB_TRCCCCTLR_THRESHOLD_0				(0x1u<<0)

// TRCVICTLR Configuration

#define	PPB_TRCVICTLR_SEL0						(0x3u<<0)
#define	PPB_TRCVICTLR_SEL0_0					(0x1u<<0)
#define	PPB_TRCVICTLR_TYPE0						(0x1u<<7)
#define	PPB_TRCVICTLR_SSSTATUS					(0x1u<<9)
#define	PPB_TRCVICTLR_TRCRESET					(0x1u<<10)
#define	PPB_TRCVICTLR_TRCERR					(0x1u<<11)
#define	PPB_TRCVICTLR_EXLEVEL_S0				(0x1u<<16)
#define	PPB_TRCVICTLR_EXLEVEL_S3				(0x1u<<19)

// TRCCNTRLDVR0 Configuration

#define	PPB_TRCCNTRLDVR0_VALUE					(0xFFFFu<<0)
#define	PPB_TRCCNTRLDVR0_VALUE_0				(0x1u<<0)

// TRCIDR8 Configuration

#define	PPB_TRCIDR8_MAXSPEC						(0xFFFFFFFFu<<0)
#define	PPB_TRCIDR8_MAXSPEC_0					(0x1u<<0)

// TRCIDR9 Configuration

#define	PPB_TRCIDR9_NUMP0KEY					(0xFFFFFFFFu<<0)
#define	PPB_TRCIDR9_NUMP0KEY_0					(0x1u<<0)

// TRCIDR10 Configuration

#define	PPB_TRCIDR10_NUMP1KEY					(0xFFFFFFFFu<<0)
#define	PPB_TRCIDR10_NUMP1KEY_0					(0x1u<<0)

// TRCIDR11 Configuration

#define	PPB_TRCIDR11_NUMP1SPC					(0xFFFFFFFFu<<0)
#define	PPB_TRCIDR11_NUMP1SPC_0					(0x1u<<0)

// TRCIDR12 Configuration

#define	PPB_TRCIDR12_NUMCONDKEY					(0xFFFFFFFFu<<0)
#define	PPB_TRCIDR12_NUMCONDKEY_0				(0x1u<<0)

// TRCIDR13 Configuration

#define	PPB_TRCIDR13_NUMCONDSPC					(0xFFFFFFFFu<<0)
#define	PPB_TRCIDR13_NUMCONDSPC_0				(0x1u<<0)

// TRCIMSPEC Configuration

#define	PPB_TRCIMSPEC_SUPPORT					(0xFu<<0)
#define	PPB_TRCIMSPEC_SUPPORT_0					(0x1u<<0)

// TRCIDR0 Configuration

#define	PPB_TRCIDR0_RES1						(0x1u<<0)
#define	PPB_TRCIDR0_INSTP0						(0x3u<<1)
#define	PPB_TRCIDR0_INSTP0_0					(0x1u<<1)
#define	PPB_TRCIDR0_TRCDATA						(0x3u<<3)
#define	PPB_TRCIDR0_TRCDATA_0					(0x1u<<3)
#define	PPB_TRCIDR0_TRCBB						(0x1u<<5)
#define	PPB_TRCIDR0_TRCCOND						(0x1u<<6)
#define	PPB_TRCIDR0_TRCCCI						(0x1u<<7)
#define	PPB_TRCIDR0_RETSTACK					(0x1u<<9)
#define	PPB_TRCIDR0_NUMEVENT					(0x3u<<10)
#define	PPB_TRCIDR0_NUMEVENT_0					(0x1u<<10)
#define	PPB_TRCIDR0_CONDTYPE					(0x3u<<12)
#define	PPB_TRCIDR0_CONDTYPE_0					(0x1u<<12)
#define	PPB_TRCIDR0_QFILT						(0x1u<<14)
#define	PPB_TRCIDR0_QSUPP						(0x3u<<15)
#define	PPB_TRCIDR0_QSUPP_0						(0x1u<<15)
#define	PPB_TRCIDR0_TRCEXDATA					(0x1u<<17)
#define	PPB_TRCIDR0_TSSIZE						(0x1Fu<<24)
#define	PPB_TRCIDR0_TSSIZE_0					(0x1u<<24)
#define	PPB_TRCIDR0_COMMOPT						(0x1u<<29)

// TRCIDR1 Configuration

#define	PPB_TRCIDR1_REVISION					(0xFu<<0)
#define	PPB_TRCIDR1_REVISION_0					(0x1u<<0)
#define	PPB_TRCIDR1_TRCARCHMIN					(0xFu<<4)
#define	PPB_TRCIDR1_TRCARCHMIN_0				(0x1u<<4)
#define	PPB_TRCIDR1_TRCARCHMAJ					(0xFu<<8)
#define	PPB_TRCIDR1_TRCARCHMAJ_0				(0x1u<<8)
#define	PPB_TRCIDR1_RES1						(0xFu<<12)
#define	PPB_TRCIDR1_RES1_0						(0x1u<<12)
#define	PPB_TRCIDR1_DESIGNER					(0xFFu<<24)
#define	PPB_TRCIDR1_DESIGNER_0					(0x1u<<24)

// TRCIDR2 Configuration

#define	PPB_TRCIDR2_IASIZE						(0x1Fu<<0)
#define	PPB_TRCIDR2_IASIZE_0					(0x1u<<0)
#define	PPB_TRCIDR2_CIDSIZE						(0x1Fu<<5)
#define	PPB_TRCIDR2_CIDSIZE_0					(0x1u<<5)
#define	PPB_TRCIDR2_VMIDSIZE					(0x1Fu<<10)
#define	PPB_TRCIDR2_VMIDSIZE_0					(0x1u<<10)
#define	PPB_TRCIDR2_DASIZE						(0x1Fu<<15)
#define	PPB_TRCIDR2_DASIZE_0					(0x1u<<15)
#define	PPB_TRCIDR2_DVSIZE						(0x1Fu<<20)
#define	PPB_TRCIDR2_DVSIZE_0					(0x1u<<20)
#define	PPB_TRCIDR2_CCSIZE						(0xFu<<25)
#define	PPB_TRCIDR2_CCSIZE_0					(0x1u<<25)

// TRCIDR3 Configuration

#define	PPB_TRCIDR3_CCITMIN						(0xFFFu<<0)
#define	PPB_TRCIDR3_CCITMIN_0					(0x1u<<0)
#define	PPB_TRCIDR3_EXLEVEL_S					(0xFu<<16)
#define	PPB_TRCIDR3_EXLEVEL_S_0					(0x1u<<16)
#define	PPB_TRCIDR3_EXLEVEL_NS					(0xFu<<20)
#define	PPB_TRCIDR3_EXLEVEL_NS_0				(0x1u<<20)
#define	PPB_TRCIDR3_TRCERR						(0x1u<<24)
#define	PPB_TRCIDR3_SYNCPR						(0x1u<<25)
#define	PPB_TRCIDR3_STALLCTL					(0x1u<<26)
#define	PPB_TRCIDR3_SYSSTALL					(0x1u<<27)
#define	PPB_TRCIDR3_NUMPROC						(0x7u<<28)
#define	PPB_TRCIDR3_NUMPROC_0					(0x1u<<28)
#define	PPB_TRCIDR3_NOOVERFLOW					(0x1u<<31)

// TRCIDR4 Configuration

#define	PPB_TRCIDR4_NUMACPAIRS					(0xFu<<0)
#define	PPB_TRCIDR4_NUMACPAIRS_0				(0x1u<<0)
#define	PPB_TRCIDR4_NUMDVC						(0xFu<<4)
#define	PPB_TRCIDR4_NUMDVC_0					(0x1u<<4)
#define	PPB_TRCIDR4_SUPPDAC						(0x1u<<8)
#define	PPB_TRCIDR4_NUMPC						(0xFu<<12)
#define	PPB_TRCIDR4_NUMPC_0						(0x1u<<12)
#define	PPB_TRCIDR4_NUMRSPAIR					(0xFu<<16)
#define	PPB_TRCIDR4_NUMRSPAIR_0					(0x1u<<16)
#define	PPB_TRCIDR4_NUMSSCC						(0xFu<<20)
#define	PPB_TRCIDR4_NUMSSCC_0					(0x1u<<20)
#define	PPB_TRCIDR4_NUMCIDC						(0xFu<<24)
#define	PPB_TRCIDR4_NUMCIDC_0					(0x1u<<24)
#define	PPB_TRCIDR4_NUMVMIDC					(0xFu<<28)
#define	PPB_TRCIDR4_NUMVMIDC_0					(0x1u<<28)

// TRCIDR5 Configuration

#define	PPB_TRCIDR5_NUMEXTIN					(0x1FFu<<0)
#define	PPB_TRCIDR5_NUMEXTIN_0					(0x1u<<0)
#define	PPB_TRCIDR5_NUMEXTINSEL					(0x7u<<9)
#define	PPB_TRCIDR5_NUMEXTINSEL_0				(0x1u<<9)
#define	PPB_TRCIDR5_TRACEIDSIZE					(0x3Fu<<16)
#define	PPB_TRCIDR5_TRACEIDSIZE_0				(0x1u<<16)
#define	PPB_TRCIDR5_ATBTRIG						(0x1u<<22)
#define	PPB_TRCIDR5_LPOVERRIDE					(0x1u<<23)
#define	PPB_TRCIDR5_NUMSEQSTATE					(0x7u<<25)
#define	PPB_TRCIDR5_NUMSEQSTATE_0				(0x1u<<25)
#define	PPB_TRCIDR5_NUMCNTR						(0x7u<<28)
#define	PPB_TRCIDR5_NUMCNTR_0					(0x1u<<28)
#define	PPB_TRCIDR5_REDFUNCNTR					(0x1u<<31)

// TRCIDR6 Configuration

#define	PPB_TRCIDR6_TRCIDR6						(0xFFFFFFFFu<<0)
#define	PPB_TRCIDR6_TRCIDR6_0					(0x1u<<0)

// TRCIDR7 Configuration

#define	PPB_TRCIDR7_TRCIDR7						(0xFFFFFFFFu<<0)
#define	PPB_TRCIDR7_TRCIDR7_0					(0x1u<<0)

// TRCRSCTLR2 Configuration

#define	PPB_TRCRSCTLR2_SELECT					(0xFFu<<0)
#define	PPB_TRCRSCTLR2_SELECT_0					(0x1u<<0)
#define	PPB_TRCRSCTLR2_GROUP					(0x7u<<16)
#define	PPB_TRCRSCTLR2_GROUP_0					(0x1u<<16)
#define	PPB_TRCRSCTLR2_INV						(0x1u<<20)
#define	PPB_TRCRSCTLR2_PAIRINV					(0x1u<<21)

// TRCRSCTLR3 Configuration

#define	PPB_TRCRSCTLR3_SELECT					(0xFFu<<0)
#define	PPB_TRCRSCTLR3_SELECT_0					(0x1u<<0)
#define	PPB_TRCRSCTLR3_GROUP					(0x7u<<16)
#define	PPB_TRCRSCTLR3_GROUP_0					(0x1u<<16)
#define	PPB_TRCRSCTLR3_INV						(0x1u<<20)
#define	PPB_TRCRSCTLR3_PAIRINV					(0x1u<<21)

// TRCSSCSR Configuration

#define	PPB_TRCSSCSR_INST						(0x1u<<0)
#define	PPB_TRCSSCSR_DA							(0x1u<<1)
#define	PPB_TRCSSCSR_DV							(0x1u<<2)
#define	PPB_TRCSSCSR_PC							(0x1u<<3)
#define	PPB_TRCSSCSR_STATUS						(0x1u<<31)

// TRCSSPCICR Configuration

#define	PPB_TRCSSPCICR_PC						(0xFu<<0)
#define	PPB_TRCSSPCICR_PC_0						(0x1u<<0)

// TRCPDCR Configuration

#define	PPB_TRCPDCR_PU							(0x1u<<3)

// TRCPDSR Configuration

#define	PPB_TRCPDSR_POWER						(0x1u<<0)
#define	PPB_TRCPDSR_STICKYPD					(0x1u<<1)
#define	PPB_TRCPDSR_OSLK						(0x1u<<5)

// TRCITATBIDR Configuration

#define	PPB_TRCITATBIDR_ID						(0x7Fu<<0)
#define	PPB_TRCITATBIDR_ID_0					(0x1u<<0)

// TRCITIATBINR Configuration

#define	PPB_TRCITIATBINR_ATREADYM				(0x1u<<0)
#define	PPB_TRCITIATBINR_AFVALIDM				(0x1u<<1)

// TRCITIATBOUTR Configuration

#define	PPB_TRCITIATBOUTR_ATVALID				(0x1u<<0)
#define	PPB_TRCITIATBOUTR_AFREADY				(0x1u<<1)

// TRCCLAIMSET Configuration

#define	PPB_TRCCLAIMSET_SET0					(0x1u<<0)
#define	PPB_TRCCLAIMSET_SET1					(0x1u<<1)
#define	PPB_TRCCLAIMSET_SET2					(0x1u<<2)
#define	PPB_TRCCLAIMSET_SET3					(0x1u<<3)

// TRCCLAIMCLR Configuration

#define	PPB_TRCCLAIMCLR_CLR0					(0x1u<<0)
#define	PPB_TRCCLAIMCLR_CLR1					(0x1u<<1)
#define	PPB_TRCCLAIMCLR_CLR2					(0x1u<<2)
#define	PPB_TRCCLAIMCLR_CLR3					(0x1u<<3)

// TRCAUTHSTATUS Configuration

#define	PPB_TRCAUTHSTATUS_NSID					(0x3u<<0)
#define	PPB_TRCAUTHSTATUS_NSID_0				(0x1u<<0)
#define	PPB_TRCAUTHSTATUS_NSNID					(0x3u<<2)
#define	PPB_TRCAUTHSTATUS_NSNID_0				(0x1u<<2)
#define	PPB_TRCAUTHSTATUS_SID					(0x3u<<4)
#define	PPB_TRCAUTHSTATUS_SID_0					(0x1u<<4)
#define	PPB_TRCAUTHSTATUS_SNID					(0x3u<<6)
#define	PPB_TRCAUTHSTATUS_SNID_0				(0x1u<<6)

// TRCDEVARCH Configuration

#define	PPB_TRCDEVARCH_ARCHID					(0xFFFFu<<0)
#define	PPB_TRCDEVARCH_ARCHID_0					(0x1u<<0)
#define	PPB_TRCDEVARCH_REVISION					(0xFu<<16)
#define	PPB_TRCDEVARCH_REVISION_0				(0x1u<<16)
#define	PPB_TRCDEVARCH_PRESENT					(0x1u<<20)
#define	PPB_TRCDEVARCH_ARCHITECT				(0x7FFu<<21)
#define	PPB_TRCDEVARCH_ARCHITECT_0				(0x1u<<21)

// TRCDEVID Configuration

#define	PPB_TRCDEVID_TRCDEVID					(0xFFFFFFFFu<<0)
#define	PPB_TRCDEVID_TRCDEVID_0					(0x1u<<0)

// TRCDEVTYPE Configuration

#define	PPB_TRCDEVTYPE_MAJOR					(0xFu<<0)
#define	PPB_TRCDEVTYPE_MAJOR_0					(0x1u<<0)
#define	PPB_TRCDEVTYPE_SUB						(0xFu<<4)
#define	PPB_TRCDEVTYPE_SUB_0					(0x1u<<4)

// TRCPIDR4 Configuration

#define	PPB_TRCPIDR4_DES_2						(0xFu<<0)
#define	PPB_TRCPIDR4_DES_2_0					(0x1u<<0)
#define	PPB_TRCPIDR4_SIZE						(0xFu<<4)
#define	PPB_TRCPIDR4_SIZE_0						(0x1u<<4)

// TRCPIDR5 Configuration

#define	PPB_TRCPIDR5_TRCPIDR5					(0xFFFFFFFFu<<0)
#define	PPB_TRCPIDR5_TRCPIDR5_0					(0x1u<<0)

// TRCPIDR6 Configuration

#define	PPB_TRCPIDR6_TRCPIDR6					(0xFFFFFFFFu<<0)
#define	PPB_TRCPIDR6_TRCPIDR6_0					(0x1u<<0)

// TRCPIDR7 Configuration

#define	PPB_TRCPIDR7_TRCPIDR7					(0xFFFFFFFFu<<0)
#define	PPB_TRCPIDR7_TRCPIDR7_0					(0x1u<<0)

// TRCPIDR0 Configuration

#define	PPB_TRCPIDR0_PART_0						(0xFFu<<0)
#define	PPB_TRCPIDR0_PART_0_0					(0x1u<<0)

// TRCPIDR1 Configuration

#define	PPB_TRCPIDR1_PART_0						(0xFu<<0)
#define	PPB_TRCPIDR1_PART_0_0					(0x1u<<0)
#define	PPB_TRCPIDR1_DES_0						(0xFu<<4)
#define	PPB_TRCPIDR1_DES_0_0					(0x1u<<4)

// TRCPIDR2 Configuration

#define	PPB_TRCPIDR2_DES_0						(0x7u<<0)
#define	PPB_TRCPIDR2_DES_0_0					(0x1u<<0)
#define	PPB_TRCPIDR2_JEDEC						(0x1u<<3)
#define	PPB_TRCPIDR2_REVISION					(0xFu<<4)
#define	PPB_TRCPIDR2_REVISION_0					(0x1u<<4)

// TRCPIDR3 Configuration

#define	PPB_TRCPIDR3_CMOD						(0xFu<<0)
#define	PPB_TRCPIDR3_CMOD_0						(0x1u<<0)
#define	PPB_TRCPIDR3_REVAND						(0xFu<<4)
#define	PPB_TRCPIDR3_REVAND_0					(0x1u<<4)

// TRCCIDR0 Configuration

#define	PPB_TRCCIDR0_PRMBL_0					(0xFFu<<0)
#define	PPB_TRCCIDR0_PRMBL_0_0					(0x1u<<0)

// TRCCIDR1 Configuration

#define	PPB_TRCCIDR1_PRMBL_1					(0xFu<<0)
#define	PPB_TRCCIDR1_PRMBL_1_0					(0x1u<<0)
#define	PPB_TRCCIDR1_CLASS						(0xFu<<4)
#define	PPB_TRCCIDR1_CLASS_0					(0x1u<<4)

// TRCCIDR2 Configuration

#define	PPB_TRCCIDR2_PRMBL_2					(0xFFu<<0)
#define	PPB_TRCCIDR2_PRMBL_2_0					(0x1u<<0)

// TRCCIDR3 Configuration

#define	PPB_TRCCIDR3_PRMBL_3					(0xFFu<<0)
#define	PPB_TRCCIDR3_PRMBL_3_0					(0x1u<<0)

// CTICONTROL Configuration

#define	PPB_CTICONTROL_GLBEN					(0x1u<<0)

// CTIINTACK Configuration

#define	PPB_CTIINTACK_INTACK					(0xFFu<<0)
#define	PPB_CTIINTACK_INTACK_0					(0x1u<<0)

// CTIAPPSET Configuration

#define	PPB_CTIAPPSET_APPSET					(0xFu<<0)
#define	PPB_CTIAPPSET_APPSET_0					(0x1u<<0)

// CTIAPPCLEAR Configuration

#define	PPB_CTIAPPCLEAR_APPCLEAR				(0xFu<<0)
#define	PPB_CTIAPPCLEAR_APPCLEAR_0				(0x1u<<0)

// CTIAPPPULSE Configuration

#define	PPB_CTIAPPPULSE_APPULSE					(0xFu<<0)
#define	PPB_CTIAPPPULSE_APPULSE_0				(0x1u<<0)

// CTIINEN0 Configuration

#define	PPB_CTIINEN0_TRIGINEN					(0xFu<<0)
#define	PPB_CTIINEN0_TRIGINEN_0					(0x1u<<0)

// CTIINEN1 Configuration

#define	PPB_CTIINEN1_TRIGINEN					(0xFu<<0)
#define	PPB_CTIINEN1_TRIGINEN_0					(0x1u<<0)

// CTIINEN2 Configuration

#define	PPB_CTIINEN2_TRIGINEN					(0xFu<<0)
#define	PPB_CTIINEN2_TRIGINEN_0					(0x1u<<0)

// CTIINEN3 Configuration

#define	PPB_CTIINEN3_TRIGINEN					(0xFu<<0)
#define	PPB_CTIINEN3_TRIGINEN_0					(0x1u<<0)

// CTIINEN4 Configuration

#define	PPB_CTIINEN4_TRIGINEN					(0xFu<<0)
#define	PPB_CTIINEN4_TRIGINEN_0					(0x1u<<0)

// CTIINEN5 Configuration

#define	PPB_CTIINEN5_TRIGINEN					(0xFu<<0)
#define	PPB_CTIINEN5_TRIGINEN_0					(0x1u<<0)

// CTIINEN6 Configuration

#define	PPB_CTIINEN6_TRIGINEN					(0xFu<<0)
#define	PPB_CTIINEN6_TRIGINEN_0					(0x1u<<0)

// CTIINEN7 Configuration

#define	PPB_CTIINEN7_TRIGINEN					(0xFu<<0)
#define	PPB_CTIINEN7_TRIGINEN_0					(0x1u<<0)

// CTIOUTEN0 Configuration

#define	PPB_CTIOUTEN0_TRIGOUTEN					(0xFu<<0)
#define	PPB_CTIOUTEN0_TRIGOUTEN_0				(0x1u<<0)

// CTIOUTEN1 Configuration

#define	PPB_CTIOUTEN1_TRIGOUTEN					(0xFu<<0)
#define	PPB_CTIOUTEN1_TRIGOUTEN_0				(0x1u<<0)

// CTIOUTEN2 Configuration

#define	PPB_CTIOUTEN2_TRIGOUTEN					(0xFu<<0)
#define	PPB_CTIOUTEN2_TRIGOUTEN_0				(0x1u<<0)

// CTIOUTEN3 Configuration

#define	PPB_CTIOUTEN3_TRIGOUTEN					(0xFu<<0)
#define	PPB_CTIOUTEN3_TRIGOUTEN_0				(0x1u<<0)

// CTIOUTEN4 Configuration

#define	PPB_CTIOUTEN4_TRIGOUTEN					(0xFu<<0)
#define	PPB_CTIOUTEN4_TRIGOUTEN_0				(0x1u<<0)

// CTIOUTEN5 Configuration

#define	PPB_CTIOUTEN5_TRIGOUTEN					(0xFu<<0)
#define	PPB_CTIOUTEN5_TRIGOUTEN_0				(0x1u<<0)

// CTIOUTEN6 Configuration

#define	PPB_CTIOUTEN6_TRIGOUTEN					(0xFu<<0)
#define	PPB_CTIOUTEN6_TRIGOUTEN_0				(0x1u<<0)

// CTIOUTEN7 Configuration

#define	PPB_CTIOUTEN7_TRIGOUTEN					(0xFu<<0)
#define	PPB_CTIOUTEN7_TRIGOUTEN_0				(0x1u<<0)

// CTITRIGINSTATUS Configuration

#define	PPB_CTITRIGINSTATUS_TRIGINSTATUS		(0xFFu<<0)
#define	PPB_CTITRIGINSTATUS_TRIGINSTATUS_0		(0x1u<<0)

// CTITRIGOUTSTATUS Configuration

#define	PPB_CTITRIGOUTSTATUS_TRIGOUTSTATUS		(0xFFu<<0)
#define	PPB_CTITRIGOUTSTATUS_TRIGOUTSTATUS_0	(0x1u<<0)

// CTICHINSTATUS Configuration

#define	PPB_CTICHINSTATUS_CTICHOUTSTATUS		(0xFu<<0)
#define	PPB_CTICHINSTATUS_CTICHOUTSTATUS_0		(0x1u<<0)

// CTIGATE Configuration

#define	PPB_CTIGATE_CTIGATEEN0					(0x1u<<0)
#define	PPB_CTIGATE_CTIGATEEN1					(0x1u<<1)
#define	PPB_CTIGATE_CTIGATEEN2					(0x1u<<2)
#define	PPB_CTIGATE_CTIGATEEN3					(0x1u<<3)

// ASICCTL Configuration

#define	PPB_ASICCTL_ASICCTL						(0xFFFFFFFFu<<0)
#define	PPB_ASICCTL_ASICCTL_0					(0x1u<<0)

// ITCHOUT Configuration

#define	PPB_ITCHOUT_CTCHOUT						(0xFu<<0)
#define	PPB_ITCHOUT_CTCHOUT_0					(0x1u<<0)

// ITTRIGOUT Configuration

#define	PPB_ITTRIGOUT_CTTRIGOUT					(0xFFu<<0)
#define	PPB_ITTRIGOUT_CTTRIGOUT_0				(0x1u<<0)

// ITCHIN Configuration

#define	PPB_ITCHIN_CTCHIN						(0xFu<<0)
#define	PPB_ITCHIN_CTCHIN_0						(0x1u<<0)

// ITCTRL Configuration

#define	PPB_ITCTRL_IME							(0x1u<<0)

// DEVARCH Configuration

#define	PPB_DEVARCH_ARCHID						(0xFFFFu<<0)
#define	PPB_DEVARCH_ARCHID_0					(0x1u<<0)
#define	PPB_DEVARCH_REVISION					(0xFu<<16)
#define	PPB_DEVARCH_REVISION_0					(0x1u<<16)
#define	PPB_DEVARCH_PRESENT						(0x1u<<20)
#define	PPB_DEVARCH_ARCHITECT					(0x7FFu<<21)
#define	PPB_DEVARCH_ARCHITECT_0					(0x1u<<21)

// DEVID Configuration

#define	PPB_DEVID_EXTMUXNUM						(0x1Fu<<0)
#define	PPB_DEVID_EXTMUXNUM_0					(0x1u<<0)
#define	PPB_DEVID_NUMTRIG						(0xFFu<<8)
#define	PPB_DEVID_NUMTRIG_0						(0x1u<<8)
#define	PPB_DEVID_NUMCH							(0xFu<<16)
#define	PPB_DEVID_NUMCH_0						(0x1u<<16)

// DEVTYPE Configuration

#define	PPB_DEVTYPE_MAJOR						(0xFu<<0)
#define	PPB_DEVTYPE_MAJOR_0						(0x1u<<0)
#define	PPB_DEVTYPE_SUB							(0xFu<<4)
#define	PPB_DEVTYPE_SUB_0						(0x1u<<4)

// PIDR4 Configuration

#define	PPB_PIDR4_DES_2							(0xFu<<0)
#define	PPB_PIDR4_DES_2_0						(0x1u<<0)
#define	PPB_PIDR4_SIZE							(0xFu<<4)
#define	PPB_PIDR4_SIZE_0						(0x1u<<4)

// PIDR5 Configuration

#define	PPB_PIDR5_PIDR5							(0xFFFFFFFFu<<0)
#define	PPB_PIDR5_PIDR5_0						(0x1u<<0)

// PIDR6 Configuration

#define	PPB_PIDR6_PIDR6							(0xFFFFFFFFu<<0)
#define	PPB_PIDR6_PIDR6_0						(0x1u<<0)

// PIDR7 Configuration

#define	PPB_PIDR7_PIDR7							(0xFFFFFFFFu<<0)
#define	PPB_PIDR7_PIDR7_0						(0x1u<<0)

// PIDR0 Configuration

#define	PPB_PIDR0_PART_0						(0xFFu<<0)
#define	PPB_PIDR0_PART_0_0						(0x1u<<0)

// PIDR1 Configuration

#define	PPB_PIDR1_PART_1						(0xFu<<0)
#define	PPB_PIDR1_PART_1_0						(0x1u<<0)
#define	PPB_PIDR1_DES_0							(0xFu<<4)
#define	PPB_PIDR1_DES_0_0						(0x1u<<4)

// PIDR2 Configuration

#define	PPB_PIDR2_DES_1							(0x7u<<0)
#define	PPB_PIDR2_DES_1_0						(0x1u<<0)
#define	PPB_PIDR2_JEDEC							(0x1u<<3)
#define	PPB_PIDR2_REVISION						(0xFu<<4)
#define	PPB_PIDR2_REVISION_0					(0x1u<<4)

// PIDR3 Configuration

#define	PPB_PIDR3_CMOD							(0xFu<<0)
#define	PPB_PIDR3_CMOD_0						(0x1u<<0)
#define	PPB_PIDR3_REVAND						(0xFu<<4)
#define	PPB_PIDR3_REVAND_0						(0x1u<<4)

// CIDR0 Configuration

#define	PPB_CIDR0_PRMBL_0						(0xFFu<<0)
#define	PPB_CIDR0_PRMBL_0_0						(0x1u<<0)

// CIDR1 Configuration

#define	PPB_CIDR1_PRMBL_1						(0xFu<<0)
#define	PPB_CIDR1_PRMBL_1_0						(0x1u<<0)
#define	PPB_CIDR1_CLASS							(0xFu<<4)
#define	PPB_CIDR1_CLASS_0						(0x1u<<4)

// CIDR2 Configuration

#define	PPB_CIDR2_PRMBL_2						(0xFFu<<0)
#define	PPB_CIDR2_PRMBL_2_0						(0x1u<<0)

// CIDR3 Configuration

#define	PPB_CIDR3_PRMBL_3						(0xFFu<<0)
#define	PPB_CIDR3_PRMBL_3_0						(0x1u<<0)
