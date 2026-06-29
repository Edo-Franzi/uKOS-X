/*
; stm32N657_otg.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_otg equates.
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

// OTG address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	GOTGCTL;
	volatile	uint32_t	GOTGINT;
	volatile	uint32_t	GAHBCFG;
	volatile	uint32_t	GUSBCFG;
	volatile	uint32_t	GRSTCTL;
		union {
	volatile	uint32_t	GINTSTS;
	volatile	uint32_t	GINTSTS_ALTERNATE;
		};
		union {
	volatile	uint32_t	GINTMSK;
	volatile	uint32_t	GINTMSK_ALTERNATE;
		};
		union {
	volatile	uint32_t	GRXSTSR;
	volatile	uint32_t	GRXSTSR_ALTERNATE;
		};
		union {
	volatile	uint32_t	GRXSTSP;
	volatile	uint32_t	GRXSTSP_ALTERNATE;
		};
	volatile	uint32_t	GRXFSIZ;
		union {
	volatile	uint32_t	HNPTXFSIZ;
	volatile	uint32_t	HNPTXFSIZ_ALTERNATE;
		};
	volatile	uint32_t	HNPTXSTS;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	GCCFG;
	volatile	uint32_t	CID;
	volatile	uint32_t	RESERVED1[5];
	volatile	uint32_t	GLPMCFG;
	volatile	uint32_t	RESERVED2[42];
	volatile	uint32_t	HPTXFSIZ;
	volatile	uint32_t	DIEPTXF1;
	volatile	uint32_t	DIEPTXF2;
	volatile	uint32_t	DIEPTXF3;
	volatile	uint32_t	DIEPTXF4;
	volatile	uint32_t	DIEPTXF5;
	volatile	uint32_t	DIEPTXF6;
	volatile	uint32_t	DIEPTXF7;
	volatile	uint32_t	DIEPTXF8;
	volatile	uint32_t	RESERVED3[183];
	volatile	uint32_t	HCFG;
	volatile	uint32_t	HFIR;
	volatile	uint32_t	HFNUM;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	HPTXSTS;
	volatile	uint32_t	HAINT;
	volatile	uint32_t	HAINTMSK;
	volatile	uint32_t	RESERVED5[9];
	volatile	uint32_t	HPRT;
	volatile	uint32_t	RESERVED6[47];
	volatile	uint32_t	HCCHAR0;
	volatile	uint32_t	HCSPLT0;
	volatile	uint32_t	HCINT0;
	volatile	uint32_t	HCINTMSK0;
	volatile	uint32_t	HCTSIZ0;
	volatile	uint32_t	HCDMA0;
	volatile	uint32_t	RESERVED7[2];
	volatile	uint32_t	HCCHAR1;
	volatile	uint32_t	HCSPLT1;
	volatile	uint32_t	HCINT1;
	volatile	uint32_t	HCINTMSK1;
	volatile	uint32_t	HCTSIZ1;
	volatile	uint32_t	HCDMA1;
	volatile	uint32_t	RESERVED8[2];
	volatile	uint32_t	HCCHAR2;
	volatile	uint32_t	HCSPLT2;
	volatile	uint32_t	HCINT2;
	volatile	uint32_t	HCINTMSK2;
	volatile	uint32_t	HCTSIZ2;
	volatile	uint32_t	HCDMA2;
	volatile	uint32_t	RESERVED9[2];
	volatile	uint32_t	HCCHAR3;
	volatile	uint32_t	HCSPLT3;
	volatile	uint32_t	HCINT3;
	volatile	uint32_t	HCINTMSK3;
	volatile	uint32_t	HCTSIZ3;
	volatile	uint32_t	HCDMA3;
	volatile	uint32_t	RESERVED10[2];
	volatile	uint32_t	HCCHAR4;
	volatile	uint32_t	HCSPLT4;
	volatile	uint32_t	HCINT4;
	volatile	uint32_t	HCINTMSK4;
	volatile	uint32_t	HCTSIZ4;
	volatile	uint32_t	HCDMA4;
	volatile	uint32_t	RESERVED11[2];
	volatile	uint32_t	HCCHAR5;
	volatile	uint32_t	HCSPLT5;
	volatile	uint32_t	HCINT5;
	volatile	uint32_t	HCINTMSK5;
	volatile	uint32_t	HCTSIZ5;
	volatile	uint32_t	HCDMA5;
	volatile	uint32_t	RESERVED12[2];
	volatile	uint32_t	HCCHAR6;
	volatile	uint32_t	HCSPLT6;
	volatile	uint32_t	HCINT6;
	volatile	uint32_t	HCINTMSK6;
	volatile	uint32_t	HCTSIZ6;
	volatile	uint32_t	HCDMA6;
	volatile	uint32_t	RESERVED13[2];
	volatile	uint32_t	HCCHAR7;
	volatile	uint32_t	HCSPLT7;
	volatile	uint32_t	HCINT7;
	volatile	uint32_t	HCINTMSK7;
	volatile	uint32_t	HCTSIZ7;
	volatile	uint32_t	HCDMA7;
	volatile	uint32_t	RESERVED14[2];
	volatile	uint32_t	HCCHAR8;
	volatile	uint32_t	HCSPLT8;
	volatile	uint32_t	HCINT8;
	volatile	uint32_t	HCINTMSK8;
	volatile	uint32_t	HCTSIZ8;
	volatile	uint32_t	HCDMA8;
	volatile	uint32_t	RESERVED15[2];
	volatile	uint32_t	HCCHAR9;
	volatile	uint32_t	HCSPLT9;
	volatile	uint32_t	HCINT9;
	volatile	uint32_t	HCINTMSK9;
	volatile	uint32_t	HCTSIZ9;
	volatile	uint32_t	HCDMA9;
	volatile	uint32_t	RESERVED16[2];
	volatile	uint32_t	HCCHAR10;
	volatile	uint32_t	HCSPLT10;
	volatile	uint32_t	HCINT10;
	volatile	uint32_t	HCINTMSK10;
	volatile	uint32_t	HCTSIZ10;
	volatile	uint32_t	HCDMA10;
	volatile	uint32_t	RESERVED17[2];
	volatile	uint32_t	HCCHAR11;
	volatile	uint32_t	HCSPLT11;
	volatile	uint32_t	HCINT11;
	volatile	uint32_t	HCINTMSK11;
	volatile	uint32_t	HCTSIZ11;
	volatile	uint32_t	HCDMA11;
	volatile	uint32_t	RESERVED18[2];
	volatile	uint32_t	HCCHAR12;
	volatile	uint32_t	HCSPLT12;
	volatile	uint32_t	HCINT12;
	volatile	uint32_t	HCINTMSK12;
	volatile	uint32_t	HCTSIZ12;
	volatile	uint32_t	HCDMA12;
	volatile	uint32_t	RESERVED19[2];
	volatile	uint32_t	HCCHAR13;
	volatile	uint32_t	HCSPLT13;
	volatile	uint32_t	HCINT13;
	volatile	uint32_t	HCINTMSK13;
	volatile	uint32_t	HCTSIZ13;
	volatile	uint32_t	HCDMA13;
	volatile	uint32_t	RESERVED20[2];
	volatile	uint32_t	HCCHAR14;
	volatile	uint32_t	HCSPLT14;
	volatile	uint32_t	HCINT14;
	volatile	uint32_t	HCINTMSK14;
	volatile	uint32_t	HCTSIZ14;
	volatile	uint32_t	HCDMA14;
	volatile	uint32_t	RESERVED21[2];
	volatile	uint32_t	HCCHAR15;
	volatile	uint32_t	HCSPLT15;
	volatile	uint32_t	HCINT15;
	volatile	uint32_t	HCINTMSK15;
	volatile	uint32_t	HCTSIZ15;
	volatile	uint32_t	HCDMA15;
	volatile	uint32_t	RESERVED22[66];
	volatile	uint32_t	DCFG;
	volatile	uint32_t	DCTL;
	volatile	uint32_t	DSTS;
	volatile	uint32_t	RESERVED23;
	volatile	uint32_t	DIEPMSK;
	volatile	uint32_t	DOEPMSK;
	volatile	uint32_t	DAINT;
	volatile	uint32_t	DAINTMSK;
	volatile	uint32_t	RESERVED24[4];
	volatile	uint32_t	DTHRCTL;
	volatile	uint32_t	DIEPEMPMSK;
	volatile	uint32_t	RESERVED25[50];
		union {
	volatile	uint32_t	DIEPCTL0;
	volatile	uint32_t	DIEPCTL0_ALTERNATE;
		};
	volatile	uint32_t	RESERVED26;
	volatile	uint32_t	DIEPINT0;
	volatile	uint32_t	RESERVED27;
	volatile	uint32_t	DIEPTSIZ0;
	volatile	uint32_t	DIEPDMA0;
	volatile	uint32_t	DTXFSTS0;
	volatile	uint32_t	RESERVED28;
		union {
	volatile	uint32_t	DIEPCTL1;
	volatile	uint32_t	DIEPCTL1_ALTERNATE;
		};
	volatile	uint32_t	RESERVED29;
	volatile	uint32_t	DIEPINT1;
	volatile	uint32_t	RESERVED30;
	volatile	uint32_t	DIEPTSIZ1;
	volatile	uint32_t	DIEPDMA1;
	volatile	uint32_t	DTXFSTS1;
	volatile	uint32_t	RESERVED31;
		union {
	volatile	uint32_t	DIEPCTL2;
	volatile	uint32_t	DIEPCTL2_ALTERNATE;
		};
	volatile	uint32_t	RESERVED32;
	volatile	uint32_t	DIEPINT2;
	volatile	uint32_t	RESERVED33;
	volatile	uint32_t	DIEPTSIZ2;
	volatile	uint32_t	DIEPDMA2;
	volatile	uint32_t	DTXFSTS2;
	volatile	uint32_t	RESERVED34;
		union {
	volatile	uint32_t	DIEPCTL3;
	volatile	uint32_t	DIEPCTL3_ALTERNATE;
		};
	volatile	uint32_t	RESERVED35;
	volatile	uint32_t	DIEPINT3;
	volatile	uint32_t	RESERVED36;
	volatile	uint32_t	DIEPTSIZ3;
	volatile	uint32_t	DIEPDMA3;
	volatile	uint32_t	DTXFSTS3;
	volatile	uint32_t	RESERVED37;
		union {
	volatile	uint32_t	DIEPCTL4;
	volatile	uint32_t	DIEPCTL4_ALTERNATE;
		};
	volatile	uint32_t	RESERVED38;
	volatile	uint32_t	DIEPINT4;
	volatile	uint32_t	RESERVED39;
	volatile	uint32_t	DIEPTSIZ4;
	volatile	uint32_t	DIEPDMA4;
	volatile	uint32_t	DTXFSTS4;
	volatile	uint32_t	RESERVED40;
		union {
	volatile	uint32_t	DIEPCTL5;
	volatile	uint32_t	DIEPCTL5_ALTERNATE;
		};
	volatile	uint32_t	RESERVED41;
	volatile	uint32_t	DIEPINT5;
	volatile	uint32_t	RESERVED42;
	volatile	uint32_t	DIEPTSIZ5;
	volatile	uint32_t	DIEPDMA5;
	volatile	uint32_t	DTXFSTS5;
	volatile	uint32_t	RESERVED43;
		union {
	volatile	uint32_t	DIEPCTL6;
	volatile	uint32_t	DIEPCTL6_ALTERNATE;
		};
	volatile	uint32_t	RESERVED44;
	volatile	uint32_t	DIEPINT6;
	volatile	uint32_t	RESERVED45;
	volatile	uint32_t	DIEPTSIZ6;
	volatile	uint32_t	DIEPDMA6;
	volatile	uint32_t	DTXFSTS6;
	volatile	uint32_t	RESERVED46;
		union {
	volatile	uint32_t	DIEPCTL7;
	volatile	uint32_t	DIEPCTL7_ALTERNATE;
		};
	volatile	uint32_t	RESERVED47;
	volatile	uint32_t	DIEPINT7;
	volatile	uint32_t	RESERVED48;
	volatile	uint32_t	DIEPTSIZ7;
	volatile	uint32_t	DIEPDMA7;
	volatile	uint32_t	DTXFSTS7;
	volatile	uint32_t	RESERVED49;
		union {
	volatile	uint32_t	DIEPCTL8;
	volatile	uint32_t	DIEPCTL8_ALTERNATE;
		};
	volatile	uint32_t	RESERVED50;
	volatile	uint32_t	DIEPINT8;
	volatile	uint32_t	RESERVED51;
	volatile	uint32_t	DIEPTSIZ8;
	volatile	uint32_t	DIEPDMA8;
	volatile	uint32_t	DTXFSTS8;
	volatile	uint32_t	RESERVED52[57];
	volatile	uint32_t	DOEPCTL0;
	volatile	uint32_t	RESERVED53;
	volatile	uint32_t	DOEPINT0;
	volatile	uint32_t	RESERVED54;
	volatile	uint32_t	DOEPTSIZ0;
	volatile	uint32_t	DOEPDMA0;
	volatile	uint32_t	RESERVED55[2];
		union {
	volatile	uint32_t	DOEPCTL1;
	volatile	uint32_t	DOEPCTL1_ALTERNATE;
		};
	volatile	uint32_t	RESERVED56;
	volatile	uint32_t	DOEPINT1;
	volatile	uint32_t	RESERVED57;
	volatile	uint32_t	DOEPTSIZ1;
	volatile	uint32_t	DOEPDMA1;
	volatile	uint32_t	RESERVED58[2];
		union {
	volatile	uint32_t	DOEPCTL2;
	volatile	uint32_t	DOEPCTL2_ALTERNATE;
		};
	volatile	uint32_t	RESERVED59;
	volatile	uint32_t	DOEPINT2;
	volatile	uint32_t	RESERVED60;
	volatile	uint32_t	DOEPTSIZ2;
	volatile	uint32_t	DOEPDMA2;
	volatile	uint32_t	RESERVED61[2];
		union {
	volatile	uint32_t	DOEPCTL3;
	volatile	uint32_t	DOEPCTL3_ALTERNATE;
		};
	volatile	uint32_t	RESERVED62;
	volatile	uint32_t	DOEPINT3;
	volatile	uint32_t	RESERVED63;
	volatile	uint32_t	DOEPTSIZ3;
	volatile	uint32_t	DOEPDMA3;
	volatile	uint32_t	RESERVED64[2];
		union {
	volatile	uint32_t	DOEPCTL4;
	volatile	uint32_t	DOEPCTL4_ALTERNATE;
		};
	volatile	uint32_t	RESERVED65;
	volatile	uint32_t	DOEPINT4;
	volatile	uint32_t	RESERVED66;
	volatile	uint32_t	DOEPTSIZ4;
	volatile	uint32_t	DOEPDMA4;
	volatile	uint32_t	RESERVED67[2];
		union {
	volatile	uint32_t	DOEPCTL5;
	volatile	uint32_t	DOEPCTL5_ALTERNATE;
		};
	volatile	uint32_t	RESERVED68;
	volatile	uint32_t	DOEPINT5;
	volatile	uint32_t	RESERVED69;
	volatile	uint32_t	DOEPTSIZ5;
	volatile	uint32_t	DOEPDMA5;
	volatile	uint32_t	RESERVED70[2];
		union {
	volatile	uint32_t	DOEPCTL6;
	volatile	uint32_t	DOEPCTL6_ALTERNATE;
		};
	volatile	uint32_t	RESERVED71;
	volatile	uint32_t	DOEPINT6;
	volatile	uint32_t	RESERVED72;
	volatile	uint32_t	DOEPTSIZ6;
	volatile	uint32_t	DOEPDMA6;
	volatile	uint32_t	RESERVED73[2];
		union {
	volatile	uint32_t	DOEPCTL7;
	volatile	uint32_t	DOEPCTL7_ALTERNATE;
		};
	volatile	uint32_t	RESERVED74;
	volatile	uint32_t	DOEPINT7;
	volatile	uint32_t	RESERVED75;
	volatile	uint32_t	DOEPTSIZ7;
	volatile	uint32_t	DOEPDMA7;
	volatile	uint32_t	RESERVED76[2];
		union {
	volatile	uint32_t	DOEPCTL8;
	volatile	uint32_t	DOEPCTL8_ALTERNATE;
		};
	volatile	uint32_t	RESERVED77;
	volatile	uint32_t	DOEPINT8;
	volatile	uint32_t	RESERVED78;
	volatile	uint32_t	DOEPTSIZ8;
	volatile	uint32_t	DOEPDMA8;
	volatile	uint32_t	RESERVED79[122];
	volatile	uint32_t	PCGCCTL;
	volatile	uint32_t	PCGCCTL1;
} OTG_TypeDef;

#if (defined(__cplusplus))
#define	OTG1_NS	reinterpret_cast<OTG_TypeDef *>(0x48040000u)
#define	OTG1_S	reinterpret_cast<OTG_TypeDef *>(0x58040000u)
#define	OTG2_NS	reinterpret_cast<OTG_TypeDef *>(0x48080000u)
#define	OTG2_S	reinterpret_cast<OTG_TypeDef *>(0x58080000u)

#else
#define	OTG1_NS	((OTG_TypeDef *)0x48040000u)
#define	OTG1_S	((OTG_TypeDef *)0x58040000u)
#define	OTG2_NS	((OTG_TypeDef *)0x48080000u)
#define	OTG2_S	((OTG_TypeDef *)0x58080000u)
#endif

// GOTGCTL Configuration

#define	OTG_GOTGCTL_CURMOD										(0x1u<<21)
#define	OTG_GOTGCTL_OTGVER										(0x1u<<20)
#define	OTG_GOTGCTL_BSVLD										(0x1u<<19)
#define	OTG_GOTGCTL_ASVLD										(0x1u<<18)
#define	OTG_GOTGCTL_DBCT										(0x1u<<17)
#define	OTG_GOTGCTL_CIDSTS										(0x1u<<16)
#define	OTG_GOTGCTL_EHEN										(0x1u<<12)
#define	OTG_GOTGCTL_BVALOVAL									(0x1u<<7)
#define	OTG_GOTGCTL_BVALOEN										(0x1u<<6)
#define	OTG_GOTGCTL_AVALOVAL									(0x1u<<5)
#define	OTG_GOTGCTL_AVALOEN										(0x1u<<4)
#define	OTG_GOTGCTL_VBVALOVAL									(0x1u<<3)
#define	OTG_GOTGCTL_VBVALOEN									(0x1u<<2)

#define	OTG_GOTGCTL_CURMOD_B_0X0								(0x0u<<21)
#define	OTG_GOTGCTL_CURMOD_B_0X1								(0x1u<<21)
#define	OTG_GOTGCTL_OTGVER_B_0X0								(0x0u<<20)
#define	OTG_GOTGCTL_OTGVER_B_0X1								(0x1u<<20)
#define	OTG_GOTGCTL_BSVLD_B_0X0									(0x0u<<19)
#define	OTG_GOTGCTL_BSVLD_B_0X1									(0x1u<<19)
#define	OTG_GOTGCTL_ASVLD_B_0X0									(0x0u<<18)
#define	OTG_GOTGCTL_ASVLD_B_0X1									(0x1u<<18)
#define	OTG_GOTGCTL_DBCT_B_0X0									(0x0u<<17)
#define	OTG_GOTGCTL_DBCT_B_0X1									(0x1u<<17)
#define	OTG_GOTGCTL_CIDSTS_B_0X0								(0x0u<<16)
#define	OTG_GOTGCTL_CIDSTS_B_0X1								(0x1u<<16)
#define	OTG_GOTGCTL_EHEN_B_0X0									(0x0u<<12)
#define	OTG_GOTGCTL_EHEN_B_0X1									(0x1u<<12)
#define	OTG_GOTGCTL_BVALOVAL_B_0X0								(0x0u<<7)
#define	OTG_GOTGCTL_BVALOVAL_B_0X1								(0x1u<<7)
#define	OTG_GOTGCTL_BVALOEN_B_0X0								(0x0u<<6)
#define	OTG_GOTGCTL_AVALOVAL_B_0X0								(0x0u<<5)
#define	OTG_GOTGCTL_AVALOVAL_B_0X1								(0x1u<<5)
#define	OTG_GOTGCTL_AVALOEN_B_0X0								(0x0u<<4)
#define	OTG_GOTGCTL_AVALOEN_B_0X1								(0x1u<<4)
#define	OTG_GOTGCTL_VBVALOVAL_B_0X0								(0x0u<<3)
#define	OTG_GOTGCTL_VBVALOVAL_B_0X1								(0x1u<<3)
#define	OTG_GOTGCTL_VBVALOEN_B_0X0								(0x0u<<2)
#define	OTG_GOTGCTL_VBVALOEN_B_0X1								(0x1u<<2)

// GOTGINT Configuration

#define	OTG_GOTGINT_ADTOCHG										(0x1u<<18)
#define	OTG_GOTGINT_SEDET										(0x1u<<2)

// GAHBCFG Configuration

#define	OTG_GAHBCFG_PTXFELVL									(0x1u<<8)
#define	OTG_GAHBCFG_TXFELVL										(0x1u<<7)
#define	OTG_GAHBCFG_DMAEN										(0x1u<<5)
#define	OTG_GAHBCFG_HBSTLEN										(0xFu<<1)
#define	OTG_GAHBCFG_HBSTLEN_0									(0x1u<<1)
#define	OTG_GAHBCFG_GINTMSK										(0x1u<<0)

#define	OTG_GAHBCFG_PTXFELVL_B_0X0								(0x0u<<8)
#define	OTG_GAHBCFG_PTXFELVL_B_0X1								(0x1u<<8)
#define	OTG_GAHBCFG_TXFELVL_B_0X0_DEVICE_MODE					(0x0u<<7)
#define	OTG_GAHBCFG_TXFELVL_B_0X1_DEVICE_MODE					(0x1u<<7)
#define	OTG_GAHBCFG_DMAEN_B_0X0									(0x0u<<5)
#define	OTG_GAHBCFG_DMAEN_B_0X1									(0x1u<<5)
#define	OTG_GAHBCFG_GINTMSK_B_0X0								(0x0u<<0)
#define	OTG_GAHBCFG_GINTMSK_B_0X1								(0x1u<<0)

// GUSBCFG Configuration

#define	OTG_GUSBCFG_FDMOD										(0x1u<<30)
#define	OTG_GUSBCFG_FHMOD										(0x1u<<29)
#define	OTG_GUSBCFG_TSDPS										(0x1u<<22)
#define	OTG_GUSBCFG_PHYLPC										(0x1u<<15)
#define	OTG_GUSBCFG_TRDT										(0xFu<<10)
#define	OTG_GUSBCFG_TRDT_0										(0x1u<<10)
#define	OTG_GUSBCFG_TOCAL										(0x7u<<0)
#define	OTG_GUSBCFG_TOCAL_0										(0x1u<<0)

#define	OTG_GUSBCFG_FDMOD_B_0X0									(0x0u<<30)
#define	OTG_GUSBCFG_FDMOD_B_0X1									(0x1u<<30)
#define	OTG_GUSBCFG_FHMOD_B_0X0									(0x0u<<29)
#define	OTG_GUSBCFG_FHMOD_B_0X1									(0x1u<<29)
#define	OTG_GUSBCFG_TSDPS_B_0X0									(0x0u<<22)
#define	OTG_GUSBCFG_TSDPS_B_0X1									(0x1u<<22)
#define	OTG_GUSBCFG_PHYLPC_B_0X0								(0x0u<<15)
#define	OTG_GUSBCFG_PHYLPC_B_0X1								(0x1u<<15)

// GRSTCTL Configuration

#define	OTG_GRSTCTL_AHBIDL										(0x1u<<31)
#define	OTG_GRSTCTL_DMAREQ										(0x1u<<30)
#define	OTG_GRSTCTL_TXFNUM										(0x1Fu<<6)
#define	OTG_GRSTCTL_TXFNUM_0									(0x1u<<6)
#define	OTG_GRSTCTL_TXFFLSH										(0x1u<<5)
#define	OTG_GRSTCTL_RXFFLSH										(0x1u<<4)
#define	OTG_GRSTCTL_FCRST										(0x1u<<2)
#define	OTG_GRSTCTL_PSRST										(0x1u<<1)
#define	OTG_GRSTCTL_CSRST										(0x1u<<0)

#define	OTG_GRSTCTL_TXFNUM_B_0X0_HOST_MODE						(0x0u<<6)
#define	OTG_GRSTCTL_TXFNUM_B_0X1_HOST_MODE						(0x1u<<6)
#define	OTG_GRSTCTL_TXFNUM_B_0X10_HOST_MODE						(0x10u<<6)
#define	OTG_GRSTCTL_TXFNUM_B_0X2_DEVICE_MODE					(0x2u<<6)
#define	OTG_GRSTCTL_TXFNUM_B_0XF_DEVICE_MODE					(0xFu<<6)

// GINTSTS Configuration

#define	OTG_GINTSTS_WKUPINT										(0x1u<<31)
#define	OTG_GINTSTS_SRQINT										(0x1u<<30)
#define	OTG_GINTSTS_DISCINT										(0x1u<<29)
#define	OTG_GINTSTS_CIDSCHG										(0x1u<<28)
#define	OTG_GINTSTS_LPMINT										(0x1u<<27)
#define	OTG_GINTSTS_PTXFE										(0x1u<<26)
#define	OTG_GINTSTS_HCINT										(0x1u<<25)
#define	OTG_GINTSTS_HPRTINT										(0x1u<<24)
#define	OTG_GINTSTS_RSTDET										(0x1u<<23)
#define	OTG_GINTSTS_DATAFSUSP									(0x1u<<22)
#define	OTG_GINTSTS_IPXFR										(0x1u<<21)
#define	OTG_GINTSTS_IISOIXFR									(0x1u<<20)
#define	OTG_GINTSTS_OEPINT										(0x1u<<19)
#define	OTG_GINTSTS_IEPINT										(0x1u<<18)
#define	OTG_GINTSTS_EOPF										(0x1u<<15)
#define	OTG_GINTSTS_ISOODRP										(0x1u<<14)
#define	OTG_GINTSTS_ENUMDNE										(0x1u<<13)
#define	OTG_GINTSTS_USBRST										(0x1u<<12)
#define	OTG_GINTSTS_USBSUSP										(0x1u<<11)
#define	OTG_GINTSTS_ESUSP										(0x1u<<10)
#define	OTG_GINTSTS_GONAKEFF									(0x1u<<7)
#define	OTG_GINTSTS_GINAKEFF									(0x1u<<6)
#define	OTG_GINTSTS_NPTXFE										(0x1u<<5)
#define	OTG_GINTSTS_RXFLVL										(0x1u<<4)
#define	OTG_GINTSTS_SOF											(0x1u<<3)
#define	OTG_GINTSTS_OTGINT										(0x1u<<2)
#define	OTG_GINTSTS_MMIS										(0x1u<<1)
#define	OTG_GINTSTS_CMOD										(0x1u<<0)

#define	OTG_GINTSTS_CMOD_B_0X0									(0x0u<<0)
#define	OTG_GINTSTS_CMOD_B_0X1									(0x1u<<0)

// GINTSTS_ALTERNATE Configuration

#define	OTG_GINTSTS_ALTERNATE_WKUPINT							(0x1u<<31)
#define	OTG_GINTSTS_ALTERNATE_SRQINT							(0x1u<<30)
#define	OTG_GINTSTS_ALTERNATE_DISCINT							(0x1u<<29)
#define	OTG_GINTSTS_ALTERNATE_CIDSCHG							(0x1u<<28)
#define	OTG_GINTSTS_ALTERNATE_LPMINT							(0x1u<<27)
#define	OTG_GINTSTS_ALTERNATE_PTXFE								(0x1u<<26)
#define	OTG_GINTSTS_ALTERNATE_HCINT								(0x1u<<25)
#define	OTG_GINTSTS_ALTERNATE_HPRTINT							(0x1u<<24)
#define	OTG_GINTSTS_ALTERNATE_RSTDET							(0x1u<<23)
#define	OTG_GINTSTS_ALTERNATE_DATAFSUSP							(0x1u<<22)
#define	OTG_GINTSTS_ALTERNATE_INCOMPISOOUT						(0x1u<<21)
#define	OTG_GINTSTS_ALTERNATE_IISOIXFR							(0x1u<<20)
#define	OTG_GINTSTS_ALTERNATE_OEPINT							(0x1u<<19)
#define	OTG_GINTSTS_ALTERNATE_IEPINT							(0x1u<<18)
#define	OTG_GINTSTS_ALTERNATE_EOPF								(0x1u<<15)
#define	OTG_GINTSTS_ALTERNATE_ISOODRP							(0x1u<<14)
#define	OTG_GINTSTS_ALTERNATE_ENUMDNE							(0x1u<<13)
#define	OTG_GINTSTS_ALTERNATE_USBRST							(0x1u<<12)
#define	OTG_GINTSTS_ALTERNATE_USBSUSP							(0x1u<<11)
#define	OTG_GINTSTS_ALTERNATE_ESUSP								(0x1u<<10)
#define	OTG_GINTSTS_ALTERNATE_GONAKEFF							(0x1u<<7)
#define	OTG_GINTSTS_ALTERNATE_GINAKEFF							(0x1u<<6)
#define	OTG_GINTSTS_ALTERNATE_NPTXFE							(0x1u<<5)
#define	OTG_GINTSTS_ALTERNATE_RXFLVL							(0x1u<<4)
#define	OTG_GINTSTS_ALTERNATE_SOF								(0x1u<<3)
#define	OTG_GINTSTS_ALTERNATE_OTGINT							(0x1u<<2)
#define	OTG_GINTSTS_ALTERNATE_MMIS								(0x1u<<1)
#define	OTG_GINTSTS_ALTERNATE_CMOD								(0x1u<<0)

#define	OTG_GINTSTS_ALTERNATE_CMOD_B_0X0						(0x0u<<0)
#define	OTG_GINTSTS_ALTERNATE_CMOD_B_0X1						(0x1u<<0)

// GINTMSK Configuration

#define	OTG_GINTMSK_WUIM										(0x1u<<31)
#define	OTG_GINTMSK_SRQIM										(0x1u<<30)
#define	OTG_GINTMSK_DISCINT										(0x1u<<29)
#define	OTG_GINTMSK_CIDSCHGM									(0x1u<<28)
#define	OTG_GINTMSK_LPMINTM										(0x1u<<27)
#define	OTG_GINTMSK_PTXFEM										(0x1u<<26)
#define	OTG_GINTMSK_HCIM										(0x1u<<25)
#define	OTG_GINTMSK_PRTIM										(0x1u<<24)
#define	OTG_GINTMSK_IPXFRM										(0x1u<<21)
#define	OTG_GINTMSK_NPTXFEM										(0x1u<<5)
#define	OTG_GINTMSK_RXFLVLM										(0x1u<<4)
#define	OTG_GINTMSK_SOFM										(0x1u<<3)
#define	OTG_GINTMSK_OTGINT										(0x1u<<2)
#define	OTG_GINTMSK_MMISM										(0x1u<<1)

#define	OTG_GINTMSK_WUIM_B_0X0									(0x0u<<31)
#define	OTG_GINTMSK_WUIM_B_0X1									(0x1u<<31)
#define	OTG_GINTMSK_SRQIM_B_0X0									(0x0u<<30)
#define	OTG_GINTMSK_SRQIM_B_0X1									(0x1u<<30)
#define	OTG_GINTMSK_DISCINT_B_0X0								(0x0u<<29)
#define	OTG_GINTMSK_DISCINT_B_0X1								(0x1u<<29)
#define	OTG_GINTMSK_CIDSCHGM_B_0X0								(0x0u<<28)
#define	OTG_GINTMSK_CIDSCHGM_B_0X1								(0x1u<<28)
#define	OTG_GINTMSK_LPMINTM_B_0X0								(0x0u<<27)
#define	OTG_GINTMSK_LPMINTM_B_0X1								(0x1u<<27)
#define	OTG_GINTMSK_PTXFEM_B_0X0								(0x0u<<26)
#define	OTG_GINTMSK_PTXFEM_B_0X1								(0x1u<<26)
#define	OTG_GINTMSK_HCIM_B_0X0									(0x0u<<25)
#define	OTG_GINTMSK_HCIM_B_0X1									(0x1u<<25)
#define	OTG_GINTMSK_PRTIM_B_0X0									(0x0u<<24)
#define	OTG_GINTMSK_PRTIM_B_0X1									(0x1u<<24)
#define	OTG_GINTMSK_IPXFRM_B_0X0								(0x0u<<21)
#define	OTG_GINTMSK_IPXFRM_B_0X1								(0x1u<<21)
#define	OTG_GINTMSK_NPTXFEM_B_0X0								(0x0u<<5)
#define	OTG_GINTMSK_NPTXFEM_B_0X1								(0x1u<<5)
#define	OTG_GINTMSK_RXFLVLM_B_0X0								(0x0u<<4)
#define	OTG_GINTMSK_RXFLVLM_B_0X1								(0x1u<<4)
#define	OTG_GINTMSK_SOFM_B_0X0									(0x0u<<3)
#define	OTG_GINTMSK_SOFM_B_0X1									(0x1u<<3)
#define	OTG_GINTMSK_OTGINT_B_0X0								(0x0u<<2)
#define	OTG_GINTMSK_OTGINT_B_0X1								(0x1u<<2)
#define	OTG_GINTMSK_MMISM_B_0X0									(0x0u<<1)
#define	OTG_GINTMSK_MMISM_B_0X1									(0x1u<<1)

// GINTMSK_ALTERNATE Configuration

#define	OTG_GINTMSK_ALTERNATE_WUIM								(0x1u<<31)
#define	OTG_GINTMSK_ALTERNATE_SRQIM								(0x1u<<30)
#define	OTG_GINTMSK_ALTERNATE_CIDSCHGM							(0x1u<<28)
#define	OTG_GINTMSK_ALTERNATE_LPMINTM							(0x1u<<27)
#define	OTG_GINTMSK_ALTERNATE_RSTDETM							(0x1u<<23)
#define	OTG_GINTMSK_ALTERNATE_FSUSPM							(0x1u<<22)
#define	OTG_GINTMSK_ALTERNATE_IISOOXFRM							(0x1u<<21)
#define	OTG_GINTMSK_ALTERNATE_IISOIXFRM							(0x1u<<20)
#define	OTG_GINTMSK_ALTERNATE_OEPINT							(0x1u<<19)
#define	OTG_GINTMSK_ALTERNATE_IEPINT							(0x1u<<18)
#define	OTG_GINTMSK_ALTERNATE_EOPFM								(0x1u<<15)
#define	OTG_GINTMSK_ALTERNATE_ISOODRPM							(0x1u<<14)
#define	OTG_GINTMSK_ALTERNATE_ENUMDNEM							(0x1u<<13)
#define	OTG_GINTMSK_ALTERNATE_USBRST							(0x1u<<12)
#define	OTG_GINTMSK_ALTERNATE_USBSUSPM							(0x1u<<11)
#define	OTG_GINTMSK_ALTERNATE_ESUSPM							(0x1u<<10)
#define	OTG_GINTMSK_ALTERNATE_GONAKEFFM							(0x1u<<7)
#define	OTG_GINTMSK_ALTERNATE_GINAKEFFM							(0x1u<<6)
#define	OTG_GINTMSK_ALTERNATE_RXFLVLM							(0x1u<<4)
#define	OTG_GINTMSK_ALTERNATE_SOFM								(0x1u<<3)
#define	OTG_GINTMSK_ALTERNATE_OTGINT							(0x1u<<2)
#define	OTG_GINTMSK_ALTERNATE_MMISM								(0x1u<<1)

#define	OTG_GINTMSK_ALTERNATE_WUIM_B_0X0						(0x0u<<31)
#define	OTG_GINTMSK_ALTERNATE_WUIM_B_0X1						(0x1u<<31)
#define	OTG_GINTMSK_ALTERNATE_SRQIM_B_0X0						(0x0u<<30)
#define	OTG_GINTMSK_ALTERNATE_SRQIM_B_0X1						(0x1u<<30)
#define	OTG_GINTMSK_ALTERNATE_CIDSCHGM_B_0X0					(0x0u<<28)
#define	OTG_GINTMSK_ALTERNATE_CIDSCHGM_B_0X1					(0x1u<<28)
#define	OTG_GINTMSK_ALTERNATE_LPMINTM_B_0X0						(0x0u<<27)
#define	OTG_GINTMSK_ALTERNATE_LPMINTM_B_0X1						(0x1u<<27)
#define	OTG_GINTMSK_ALTERNATE_RSTDETM_B_0X0						(0x0u<<23)
#define	OTG_GINTMSK_ALTERNATE_RSTDETM_B_0X1						(0x1u<<23)
#define	OTG_GINTMSK_ALTERNATE_FSUSPM_B_0X0						(0x0u<<22)
#define	OTG_GINTMSK_ALTERNATE_FSUSPM_B_0X1						(0x1u<<22)
#define	OTG_GINTMSK_ALTERNATE_IISOOXFRM_B_0X0					(0x0u<<21)
#define	OTG_GINTMSK_ALTERNATE_IISOOXFRM_B_0X1					(0x1u<<21)
#define	OTG_GINTMSK_ALTERNATE_IISOIXFRM_B_0X0					(0x0u<<20)
#define	OTG_GINTMSK_ALTERNATE_IISOIXFRM_B_0X1					(0x1u<<20)
#define	OTG_GINTMSK_ALTERNATE_OEPINT_B_0X0						(0x0u<<19)
#define	OTG_GINTMSK_ALTERNATE_OEPINT_B_0X1						(0x1u<<19)
#define	OTG_GINTMSK_ALTERNATE_IEPINT_B_0X0						(0x0u<<18)
#define	OTG_GINTMSK_ALTERNATE_IEPINT_B_0X1						(0x1u<<18)
#define	OTG_GINTMSK_ALTERNATE_EOPFM_B_0X0						(0x0u<<15)
#define	OTG_GINTMSK_ALTERNATE_EOPFM_B_0X1						(0x1u<<15)
#define	OTG_GINTMSK_ALTERNATE_ISOODRPM_B_0X0					(0x0u<<14)
#define	OTG_GINTMSK_ALTERNATE_ISOODRPM_B_0X1					(0x1u<<14)
#define	OTG_GINTMSK_ALTERNATE_ENUMDNEM_B_0X0					(0x0u<<13)
#define	OTG_GINTMSK_ALTERNATE_ENUMDNEM_B_0X1					(0x1u<<13)
#define	OTG_GINTMSK_ALTERNATE_USBRST_B_0X0						(0x0u<<12)
#define	OTG_GINTMSK_ALTERNATE_USBRST_B_0X1						(0x1u<<12)
#define	OTG_GINTMSK_ALTERNATE_USBSUSPM_B_0X0					(0x0u<<11)
#define	OTG_GINTMSK_ALTERNATE_USBSUSPM_B_0X1					(0x1u<<11)
#define	OTG_GINTMSK_ALTERNATE_ESUSPM_B_0X0						(0x0u<<10)
#define	OTG_GINTMSK_ALTERNATE_ESUSPM_B_0X1						(0x1u<<10)
#define	OTG_GINTMSK_ALTERNATE_GONAKEFFM_B_0X0					(0x0u<<7)
#define	OTG_GINTMSK_ALTERNATE_GONAKEFFM_B_0X1					(0x1u<<7)
#define	OTG_GINTMSK_ALTERNATE_GINAKEFFM_B_0X0					(0x0u<<6)
#define	OTG_GINTMSK_ALTERNATE_GINAKEFFM_B_0X1					(0x1u<<6)
#define	OTG_GINTMSK_ALTERNATE_RXFLVLM_B_0X0						(0x0u<<4)
#define	OTG_GINTMSK_ALTERNATE_RXFLVLM_B_0X1						(0x1u<<4)
#define	OTG_GINTMSK_ALTERNATE_SOFM_B_0X0						(0x0u<<3)
#define	OTG_GINTMSK_ALTERNATE_SOFM_B_0X1						(0x1u<<3)
#define	OTG_GINTMSK_ALTERNATE_OTGINT_B_0X0						(0x0u<<2)
#define	OTG_GINTMSK_ALTERNATE_OTGINT_B_0X1						(0x1u<<2)
#define	OTG_GINTMSK_ALTERNATE_MMISM_B_0X0						(0x0u<<1)
#define	OTG_GINTMSK_ALTERNATE_MMISM_B_0X1						(0x1u<<1)

// GRXSTSR Configuration

#define	OTG_GRXSTSR_STSPHST										(0x1u<<27)
#define	OTG_GRXSTSR_FRMNUM										(0xFu<<21)
#define	OTG_GRXSTSR_FRMNUM_0									(0x1u<<21)
#define	OTG_GRXSTSR_PKTSTS										(0xFu<<17)
#define	OTG_GRXSTSR_PKTSTS_0									(0x1u<<17)
#define	OTG_GRXSTSR_DPID										(0x3u<<15)
#define	OTG_GRXSTSR_DPID_0										(0x1u<<15)
#define	OTG_GRXSTSR_BCNT										(0x7FFu<<4)
#define	OTG_GRXSTSR_BCNT_0										(0x1u<<4)
#define	OTG_GRXSTSR_EPNUM										(0xFu<<0)
#define	OTG_GRXSTSR_EPNUM_0										(0x1u<<0)

#define	OTG_GRXSTSR_PKTSTS_B_0X1								(0x1u<<17)
#define	OTG_GRXSTSR_PKTSTS_B_0X2								(0x2u<<17)
#define	OTG_GRXSTSR_PKTSTS_B_0X3								(0x3u<<17)
#define	OTG_GRXSTSR_PKTSTS_B_0X4								(0x4u<<17)
#define	OTG_GRXSTSR_PKTSTS_B_0X6								(0x6u<<17)
#define	OTG_GRXSTSR_DPID_B_0X0									(0x0u<<15)
#define	OTG_GRXSTSR_DPID_B_0X2									(0x2u<<15)
#define	OTG_GRXSTSR_DPID_B_0X1									(0x1u<<15)
#define	OTG_GRXSTSR_DPID_B_0X3									(0x3u<<15)

// GRXSTSR_ALTERNATE Configuration

#define	OTG_GRXSTSR_ALTERNATE_PKTSTS							(0xFu<<17)
#define	OTG_GRXSTSR_ALTERNATE_PKTSTS_0							(0x1u<<17)
#define	OTG_GRXSTSR_ALTERNATE_DPID								(0x3u<<15)
#define	OTG_GRXSTSR_ALTERNATE_DPID_0							(0x1u<<15)
#define	OTG_GRXSTSR_ALTERNATE_BCNT								(0x7FFu<<4)
#define	OTG_GRXSTSR_ALTERNATE_BCNT_0							(0x1u<<4)
#define	OTG_GRXSTSR_ALTERNATE_CHNUM								(0xFu<<0)
#define	OTG_GRXSTSR_ALTERNATE_CHNUM_0							(0x1u<<0)

#define	OTG_GRXSTSR_ALTERNATE_PKTSTS_B_0X2						(0x2u<<17)
#define	OTG_GRXSTSR_ALTERNATE_PKTSTS_B_0X3						(0x3u<<17)
#define	OTG_GRXSTSR_ALTERNATE_PKTSTS_B_0X5						(0x5u<<17)
#define	OTG_GRXSTSR_ALTERNATE_PKTSTS_B_0X7						(0x7u<<17)
#define	OTG_GRXSTSR_ALTERNATE_DPID_B_0X0						(0x0u<<15)
#define	OTG_GRXSTSR_ALTERNATE_DPID_B_0X2						(0x2u<<15)
#define	OTG_GRXSTSR_ALTERNATE_DPID_B_0X1						(0x1u<<15)
#define	OTG_GRXSTSR_ALTERNATE_DPID_B_0X3						(0x3u<<15)

// GRXSTSP Configuration

#define	OTG_GRXSTSP_STSPHST										(0x1u<<27)
#define	OTG_GRXSTSP_FRMNUM										(0xFu<<21)
#define	OTG_GRXSTSP_FRMNUM_0									(0x1u<<21)
#define	OTG_GRXSTSP_PKTSTS										(0xFu<<17)
#define	OTG_GRXSTSP_PKTSTS_0									(0x1u<<17)
#define	OTG_GRXSTSP_DPID										(0x3u<<15)
#define	OTG_GRXSTSP_DPID_0										(0x1u<<15)
#define	OTG_GRXSTSP_BCNT										(0x7FFu<<4)
#define	OTG_GRXSTSP_BCNT_0										(0x1u<<4)
#define	OTG_GRXSTSP_EPNUM										(0xFu<<0)
#define	OTG_GRXSTSP_EPNUM_0										(0x1u<<0)

#define	OTG_GRXSTSP_PKTSTS_B_0X1								(0x1u<<17)
#define	OTG_GRXSTSP_PKTSTS_B_0X2								(0x2u<<17)
#define	OTG_GRXSTSP_PKTSTS_B_0X3								(0x3u<<17)
#define	OTG_GRXSTSP_PKTSTS_B_0X4								(0x4u<<17)
#define	OTG_GRXSTSP_PKTSTS_B_0X6								(0x6u<<17)
#define	OTG_GRXSTSP_DPID_B_0X0									(0x0u<<15)
#define	OTG_GRXSTSP_DPID_B_0X2									(0x2u<<15)
#define	OTG_GRXSTSP_DPID_B_0X1									(0x1u<<15)
#define	OTG_GRXSTSP_DPID_B_0X3									(0x3u<<15)

// GRXSTSP_ALTERNATE Configuration

#define	OTG_GRXSTSP_ALTERNATE_PKTSTS							(0xFu<<17)
#define	OTG_GRXSTSP_ALTERNATE_PKTSTS_0							(0x1u<<17)
#define	OTG_GRXSTSP_ALTERNATE_DPID								(0x3u<<15)
#define	OTG_GRXSTSP_ALTERNATE_DPID_0							(0x1u<<15)
#define	OTG_GRXSTSP_ALTERNATE_BCNT								(0x7FFu<<4)
#define	OTG_GRXSTSP_ALTERNATE_BCNT_0							(0x1u<<4)
#define	OTG_GRXSTSP_ALTERNATE_CHNUM								(0xFu<<0)
#define	OTG_GRXSTSP_ALTERNATE_CHNUM_0							(0x1u<<0)

#define	OTG_GRXSTSP_ALTERNATE_PKTSTS_B_0X2						(0x2u<<17)
#define	OTG_GRXSTSP_ALTERNATE_PKTSTS_B_0X3						(0x3u<<17)
#define	OTG_GRXSTSP_ALTERNATE_PKTSTS_B_0X5						(0x5u<<17)
#define	OTG_GRXSTSP_ALTERNATE_PKTSTS_B_0X7						(0x7u<<17)
#define	OTG_GRXSTSP_ALTERNATE_DPID_B_0X0						(0x0u<<15)
#define	OTG_GRXSTSP_ALTERNATE_DPID_B_0X2						(0x2u<<15)
#define	OTG_GRXSTSP_ALTERNATE_DPID_B_0X1						(0x1u<<15)
#define	OTG_GRXSTSP_ALTERNATE_DPID_B_0X3						(0x3u<<15)

// GRXFSIZ Configuration

#define	OTG_GRXFSIZ_RXFD										(0xFFFFu<<0)
#define	OTG_GRXFSIZ_RXFD_0										(0x1u<<0)

// HNPTXFSIZ Configuration

#define	OTG_HNPTXFSIZ_NPTXFD									(0xFFFFu<<16)
#define	OTG_HNPTXFSIZ_NPTXFD_0									(0x1u<<16)
#define	OTG_HNPTXFSIZ_NPTXFSA									(0xFFFFu<<0)
#define	OTG_HNPTXFSIZ_NPTXFSA_0									(0x1u<<0)

// HNPTXFSIZ_ALTERNATE Configuration

#define	OTG_HNPTXFSIZ_ALTERNATE_TX0FD							(0xFFFFu<<16)
#define	OTG_HNPTXFSIZ_ALTERNATE_TX0FD_0							(0x1u<<16)
#define	OTG_HNPTXFSIZ_ALTERNATE_TX0FSA							(0xFFFFu<<0)
#define	OTG_HNPTXFSIZ_ALTERNATE_TX0FSA_0						(0x1u<<0)

// HNPTXSTS Configuration

#define	OTG_HNPTXSTS_NPTXQTOP									(0x7Fu<<24)
#define	OTG_HNPTXSTS_NPTXQTOP_0									(0x1u<<24)
#define	OTG_HNPTXSTS_NPTQXSAV									(0xFFu<<16)
#define	OTG_HNPTXSTS_NPTQXSAV_0									(0x1u<<16)
#define	OTG_HNPTXSTS_NPTXFSAV									(0xFFFFu<<0)
#define	OTG_HNPTXSTS_NPTXFSAV_0									(0x1u<<0)

#define	OTG_HNPTXSTS_NPTQXSAV_B_0X0								(0x0u<<16)
#define	OTG_HNPTXSTS_NPTQXSAV_B_0X1								(0x1u<<16)
#define	OTG_HNPTXSTS_NPTXFSAV_B_0X0								(0x0u<<0)
#define	OTG_HNPTXSTS_NPTXFSAV_B_0X1								(0x1u<<0)

// GCCFG Configuration

#define	OTG_GCCFG_IDPULLUPDIS									(0x1u<<28)
#define	OTG_GCCFG_BCDEN											(0x1u<<26)
#define	OTG_GCCFG_FORCEHOSTPD									(0x1u<<25)
#define	OTG_GCCFG_VBVALOVAL										(0x1u<<23)
#define	OTG_GCCFG_SDEN											(0x1u<<22)
#define	OTG_GCCFG_PDEN											(0x1u<<20)
#define	OTG_GCCFG_DCDEN											(0x1u<<19)
#define	OTG_GCCFG_HVDMSRCEN										(0x1u<<18)
#define	OTG_GCCFG_HCDPDETEN										(0x1u<<17)
#define	OTG_GCCFG_HCDPEN										(0x1u<<16)
#define	OTG_GCCFG_VBUSVLD										(0x1u<<4)
#define	OTG_GCCFG_SESSVLD										(0x1u<<3)
#define	OTG_GCCFG_FSVMINUS										(0x1u<<2)
#define	OTG_GCCFG_FSVPLUS										(0x1u<<1)
#define	OTG_GCCFG_CHGDET										(0x1u<<0)

#define	OTG_GCCFG_IDPULLUPDIS_B_0X0								(0x0u<<28)
#define	OTG_GCCFG_IDPULLUPDIS_B_0X1								(0x1u<<28)
#define	OTG_GCCFG_BCDEN_B_0X0									(0x0u<<26)
#define	OTG_GCCFG_BCDEN_B_0X1									(0x1u<<26)
#define	OTG_GCCFG_FORCEHOSTPD_B_0X0								(0x0u<<25)
#define	OTG_GCCFG_FORCEHOSTPD_B_0X1								(0x1u<<25)
#define	OTG_GCCFG_VBVALOVAL_B_0X0								(0x0u<<23)
#define	OTG_GCCFG_VBVALOVAL_B_0X1								(0x1u<<23)
#define	OTG_GCCFG_SDEN_B_0X0									(0x0u<<22)
#define	OTG_GCCFG_SDEN_B_0X1									(0x1u<<22)
#define	OTG_GCCFG_PDEN_B_0X0									(0x0u<<20)
#define	OTG_GCCFG_PDEN_B_0X1									(0x1u<<20)
#define	OTG_GCCFG_DCDEN_B_0X0									(0x0u<<19)
#define	OTG_GCCFG_DCDEN_B_0X1									(0x1u<<19)
#define	OTG_GCCFG_HVDMSRCEN_B_0X0								(0x0u<<18)
#define	OTG_GCCFG_HVDMSRCEN_B_0X1								(0x1u<<18)
#define	OTG_GCCFG_HCDPDETEN_B_0X0								(0x0u<<17)
#define	OTG_GCCFG_HCDPDETEN_B_0X1								(0x1u<<17)
#define	OTG_GCCFG_HCDPEN_B_0X0									(0x0u<<16)
#define	OTG_GCCFG_HCDPEN_B_0X1									(0x1u<<16)
#define	OTG_GCCFG_VBUSVLD_B_0X0									(0x0u<<4)
#define	OTG_GCCFG_VBUSVLD_B_0X1									(0x1u<<4)
#define	OTG_GCCFG_SESSVLD_B_0X0									(0x0u<<3)
#define	OTG_GCCFG_SESSVLD_B_0X1									(0x1u<<3)
#define	OTG_GCCFG_FSVMINUS_B_0X0								(0x0u<<2)
#define	OTG_GCCFG_FSVMINUS_B_0X1								(0x1u<<2)
#define	OTG_GCCFG_FSVPLUS_B_0X0									(0x0u<<1)
#define	OTG_GCCFG_FSVPLUS_B_0X1									(0x1u<<1)
#define	OTG_GCCFG_CHGDET_B_0X0									(0x0u<<0)
#define	OTG_GCCFG_CHGDET_B_0X1									(0x1u<<0)

// CID Configuration

#define	OTG_CID_PRODUCT_ID										(0xFFFFFFFFu<<0)
#define	OTG_CID_PRODUCT_ID_0									(0x1u<<0)

// GLPMCFG Configuration

#define	OTG_GLPMCFG_ENBESL										(0x1u<<28)
#define	OTG_GLPMCFG_LPMRCNTSTS									(0x7u<<25)
#define	OTG_GLPMCFG_LPMRCNTSTS_0								(0x1u<<25)
#define	OTG_GLPMCFG_SNDLPM										(0x1u<<24)
#define	OTG_GLPMCFG_LPMRCNT										(0x7u<<21)
#define	OTG_GLPMCFG_LPMRCNT_0									(0x1u<<21)
#define	OTG_GLPMCFG_LPMCHIDX									(0xFu<<17)
#define	OTG_GLPMCFG_LPMCHIDX_0									(0x1u<<17)
#define	OTG_GLPMCFG_L1RSMOK										(0x1u<<16)
#define	OTG_GLPMCFG_SLPSTS										(0x1u<<15)
#define	OTG_GLPMCFG_LPMRSP										(0x3u<<13)
#define	OTG_GLPMCFG_LPMRSP_0									(0x1u<<13)
#define	OTG_GLPMCFG_L1DSEN										(0x1u<<12)
#define	OTG_GLPMCFG_BESLTHRS									(0xFu<<8)
#define	OTG_GLPMCFG_BESLTHRS_0									(0x1u<<8)
#define	OTG_GLPMCFG_L1SSEN										(0x1u<<7)
#define	OTG_GLPMCFG_REMWAKE										(0x1u<<6)
#define	OTG_GLPMCFG_BESL										(0xFu<<2)
#define	OTG_GLPMCFG_BESL_0										(0x1u<<2)
#define	OTG_GLPMCFG_LPMACK										(0x1u<<1)
#define	OTG_GLPMCFG_LPMEN										(0x1u<<0)

#define	OTG_GLPMCFG_ENBESL_B_0X0								(0x0u<<28)
#define	OTG_GLPMCFG_ENBESL_B_0X1								(0x1u<<28)
#define	OTG_GLPMCFG_L1RSMOK_B_0X1								(0x1u<<16)
#define	OTG_GLPMCFG_L1RSMOK_B_0X0								(0x0u<<16)
#define	OTG_GLPMCFG_SLPSTS_B_0X0								(0x0u<<15)
#define	OTG_GLPMCFG_SLPSTS_B_0X1								(0x1u<<15)
#define	OTG_GLPMCFG_LPMRSP_B_0X3								(0x3u<<13)
#define	OTG_GLPMCFG_LPMRSP_B_0X2								(0x2u<<13)
#define	OTG_GLPMCFG_LPMRSP_B_0X1								(0x1u<<13)
#define	OTG_GLPMCFG_LPMRSP_B_0X0								(0x0u<<13)
#define	OTG_GLPMCFG_BESLTHRS_B_0X0								(0x0u<<8)
#define	OTG_GLPMCFG_BESLTHRS_B_0X1								(0x1u<<8)
#define	OTG_GLPMCFG_BESLTHRS_B_0X2								(0x2u<<8)
#define	OTG_GLPMCFG_BESLTHRS_B_0X3								(0x3u<<8)
#define	OTG_GLPMCFG_BESLTHRS_B_0X4								(0x4u<<8)
#define	OTG_GLPMCFG_BESLTHRS_B_0X5								(0x5u<<8)
#define	OTG_GLPMCFG_BESLTHRS_B_0X6								(0x6u<<8)
#define	OTG_GLPMCFG_BESL_B_0X0									(0x0u<<2)
#define	OTG_GLPMCFG_BESL_B_0X1									(0x1u<<2)
#define	OTG_GLPMCFG_BESL_B_0X2									(0x2u<<2)
#define	OTG_GLPMCFG_BESL_B_0X3									(0x3u<<2)
#define	OTG_GLPMCFG_BESL_B_0X4									(0x4u<<2)
#define	OTG_GLPMCFG_BESL_B_0X5									(0x5u<<2)
#define	OTG_GLPMCFG_BESL_B_0X6									(0x6u<<2)
#define	OTG_GLPMCFG_BESL_B_0X7									(0x7u<<2)
#define	OTG_GLPMCFG_BESL_B_0X8									(0x8u<<2)
#define	OTG_GLPMCFG_BESL_B_0X9									(0x9u<<2)
#define	OTG_GLPMCFG_BESL_B_0XA									(0xAu<<2)
#define	OTG_GLPMCFG_BESL_B_0XB									(0xBu<<2)
#define	OTG_GLPMCFG_BESL_B_0XC									(0xCu<<2)
#define	OTG_GLPMCFG_BESL_B_0XD									(0xDu<<2)
#define	OTG_GLPMCFG_BESL_B_0XE									(0xEu<<2)
#define	OTG_GLPMCFG_BESL_B_0XF									(0xFu<<2)
#define	OTG_GLPMCFG_LPMACK_B_0X1								(0x1u<<1)
#define	OTG_GLPMCFG_LPMACK_B_0X0								(0x0u<<1)
#define	OTG_GLPMCFG_LPMEN_B_0X0									(0x0u<<0)
#define	OTG_GLPMCFG_LPMEN_B_0X1									(0x1u<<0)

// HPTXFSIZ Configuration

#define	OTG_HPTXFSIZ_PTXFSIZ									(0xFFFFu<<16)
#define	OTG_HPTXFSIZ_PTXFSIZ_0									(0x1u<<16)
#define	OTG_HPTXFSIZ_PTXSA										(0xFFFFu<<0)
#define	OTG_HPTXFSIZ_PTXSA_0									(0x1u<<0)

// DIEPTXF1 Configuration

#define	OTG_DIEPTXF1_INEPTXFD									(0xFFFFu<<16)
#define	OTG_DIEPTXF1_INEPTXFD_0									(0x1u<<16)
#define	OTG_DIEPTXF1_INEPTXSA									(0xFFFFu<<0)
#define	OTG_DIEPTXF1_INEPTXSA_0									(0x1u<<0)

// DIEPTXF2 Configuration

#define	OTG_DIEPTXF2_INEPTXFD									(0xFFFFu<<16)
#define	OTG_DIEPTXF2_INEPTXFD_0									(0x1u<<16)
#define	OTG_DIEPTXF2_INEPTXSA									(0xFFFFu<<0)
#define	OTG_DIEPTXF2_INEPTXSA_0									(0x1u<<0)

// DIEPTXF3 Configuration

#define	OTG_DIEPTXF3_INEPTXFD									(0xFFFFu<<16)
#define	OTG_DIEPTXF3_INEPTXFD_0									(0x1u<<16)
#define	OTG_DIEPTXF3_INEPTXSA									(0xFFFFu<<0)
#define	OTG_DIEPTXF3_INEPTXSA_0									(0x1u<<0)

// DIEPTXF4 Configuration

#define	OTG_DIEPTXF4_INEPTXFD									(0xFFFFu<<16)
#define	OTG_DIEPTXF4_INEPTXFD_0									(0x1u<<16)
#define	OTG_DIEPTXF4_INEPTXSA									(0xFFFFu<<0)
#define	OTG_DIEPTXF4_INEPTXSA_0									(0x1u<<0)

// DIEPTXF5 Configuration

#define	OTG_DIEPTXF5_INEPTXFD									(0xFFFFu<<16)
#define	OTG_DIEPTXF5_INEPTXFD_0									(0x1u<<16)
#define	OTG_DIEPTXF5_INEPTXSA									(0xFFFFu<<0)
#define	OTG_DIEPTXF5_INEPTXSA_0									(0x1u<<0)

// DIEPTXF6 Configuration

#define	OTG_DIEPTXF6_INEPTXFD									(0xFFFFu<<16)
#define	OTG_DIEPTXF6_INEPTXFD_0									(0x1u<<16)
#define	OTG_DIEPTXF6_INEPTXSA									(0xFFFFu<<0)
#define	OTG_DIEPTXF6_INEPTXSA_0									(0x1u<<0)

// DIEPTXF7 Configuration

#define	OTG_DIEPTXF7_INEPTXFD									(0xFFFFu<<16)
#define	OTG_DIEPTXF7_INEPTXFD_0									(0x1u<<16)
#define	OTG_DIEPTXF7_INEPTXSA									(0xFFFFu<<0)
#define	OTG_DIEPTXF7_INEPTXSA_0									(0x1u<<0)

// DIEPTXF8 Configuration

#define	OTG_DIEPTXF8_INEPTXFD									(0xFFFFu<<16)
#define	OTG_DIEPTXF8_INEPTXFD_0									(0x1u<<16)
#define	OTG_DIEPTXF8_INEPTXSA									(0xFFFFu<<0)
#define	OTG_DIEPTXF8_INEPTXSA_0									(0x1u<<0)

// HCFG Configuration

#define	OTG_HCFG_FSLSS											(0x1u<<2)
#define	OTG_HCFG_FSLSPCS										(0x3u<<0)
#define	OTG_HCFG_FSLSPCS_0										(0x1u<<0)

#define	OTG_HCFG_FSLSPCS_B_0X1_FS_HOST_MODE						(0x1u<<0)
#define	OTG_HCFG_FSLSPCS_B_0X2_LS_HOST_MODE						(0x2u<<0)

// HFIR Configuration

#define	OTG_HFIR_RLDCTRL										(0x1u<<16)
#define	OTG_HFIR_FRIVL											(0xFFFFu<<0)
#define	OTG_HFIR_FRIVL_0										(0x1u<<0)

#define	OTG_HFIR_RLDCTRL_B_0X0									(0x0u<<16)
#define	OTG_HFIR_RLDCTRL_B_0X1									(0x1u<<16)

// HFNUM Configuration

#define	OTG_HFNUM_FTREM											(0xFFFFu<<16)
#define	OTG_HFNUM_FTREM_0										(0x1u<<16)
#define	OTG_HFNUM_FRNUM											(0xFFFFu<<0)
#define	OTG_HFNUM_FRNUM_0										(0x1u<<0)

// HPTXSTS Configuration

#define	OTG_HPTXSTS_PTXQTOP										(0xFFu<<24)
#define	OTG_HPTXSTS_PTXQTOP_0									(0x1u<<24)
#define	OTG_HPTXSTS_PTXQSAV										(0xFFu<<16)
#define	OTG_HPTXSTS_PTXQSAV_0									(0x1u<<16)
#define	OTG_HPTXSTS_PTXFSAVL									(0xFFFFu<<0)
#define	OTG_HPTXSTS_PTXFSAVL_0									(0x1u<<0)

#define	OTG_HPTXSTS_PTXQSAV_B_0X0								(0x0u<<16)
#define	OTG_HPTXSTS_PTXQSAV_B_0X1								(0x1u<<16)
#define	OTG_HPTXSTS_PTXFSAVL_B_0X0								(0x0u<<0)
#define	OTG_HPTXSTS_PTXFSAVL_B_0X1								(0x1u<<0)

// HAINT Configuration

#define	OTG_HAINT_HAINT											(0xFFFFu<<0)
#define	OTG_HAINT_HAINT_0										(0x1u<<0)

// HAINTMSK Configuration

#define	OTG_HAINTMSK_HAINTM										(0xFFFFu<<0)
#define	OTG_HAINTMSK_HAINTM_0									(0x1u<<0)

#define	OTG_HAINTMSK_HAINTM_B_0X0								(0x0u<<0)
#define	OTG_HAINTMSK_HAINTM_B_0X1								(0x1u<<0)

// HPRT Configuration

#define	OTG_HPRT_PSPD											(0x3u<<17)
#define	OTG_HPRT_PSPD_0											(0x1u<<17)
#define	OTG_HPRT_PTCTL											(0xFu<<13)
#define	OTG_HPRT_PTCTL_0										(0x1u<<13)
#define	OTG_HPRT_PPWR											(0x1u<<12)
#define	OTG_HPRT_PLSTS											(0x3u<<10)
#define	OTG_HPRT_PLSTS_0										(0x1u<<10)
#define	OTG_HPRT_PRST											(0x1u<<8)
#define	OTG_HPRT_PSUSP											(0x1u<<7)
#define	OTG_HPRT_PRES											(0x1u<<6)
#define	OTG_HPRT_POCCHNG										(0x1u<<5)
#define	OTG_HPRT_POCA											(0x1u<<4)
#define	OTG_HPRT_PENCHNG										(0x1u<<3)
#define	OTG_HPRT_PENA											(0x1u<<2)
#define	OTG_HPRT_PCDET											(0x1u<<1)
#define	OTG_HPRT_PCSTS											(0x1u<<0)

#define	OTG_HPRT_PSPD_B_0X1										(0x1u<<17)
#define	OTG_HPRT_PSPD_B_0X2										(0x2u<<17)
#define	OTG_HPRT_PSPD_B_0X0										(0x0u<<17)
#define	OTG_HPRT_PTCTL_B_0X0									(0x0u<<13)
#define	OTG_HPRT_PTCTL_B_0X1									(0x1u<<13)
#define	OTG_HPRT_PTCTL_B_0X2									(0x2u<<13)
#define	OTG_HPRT_PTCTL_B_0X3									(0x3u<<13)
#define	OTG_HPRT_PTCTL_B_0X4									(0x4u<<13)
#define	OTG_HPRT_PTCTL_B_0X5									(0x5u<<13)
#define	OTG_HPRT_PPWR_B_0X0										(0x0u<<12)
#define	OTG_HPRT_PPWR_B_0X1										(0x1u<<12)
#define	OTG_HPRT_PRST_B_0X0										(0x0u<<8)
#define	OTG_HPRT_PRST_B_0X1										(0x1u<<8)
#define	OTG_HPRT_PSUSP_B_0X0									(0x0u<<7)
#define	OTG_HPRT_PSUSP_B_0X1									(0x1u<<7)
#define	OTG_HPRT_PRES_B_0X0										(0x0u<<6)
#define	OTG_HPRT_PRES_B_0X1										(0x1u<<6)
#define	OTG_HPRT_POCA_B_0X0										(0x0u<<4)
#define	OTG_HPRT_POCA_B_0X1										(0x1u<<4)
#define	OTG_HPRT_PENA_B_0X0										(0x0u<<2)
#define	OTG_HPRT_PENA_B_0X1										(0x1u<<2)
#define	OTG_HPRT_PCSTS_B_0X0									(0x0u<<0)
#define	OTG_HPRT_PCSTS_B_0X1									(0x1u<<0)

// HCCHAR0 Configuration

#define	OTG_HCCHAR0_CHENA										(0x1u<<31)
#define	OTG_HCCHAR0_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR0_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR0_DAD											(0x7Fu<<22)
#define	OTG_HCCHAR0_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR0_MCNT										(0x3u<<20)
#define	OTG_HCCHAR0_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR0_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR0_EPTYP_0										(0x1u<<18)
#define	OTG_HCCHAR0_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR0_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR0_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR0_EPNUM_0										(0x1u<<11)
#define	OTG_HCCHAR0_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR0_MPSIZ_0										(0x1u<<0)

#define	OTG_HCCHAR0_CHENA_B_0X0									(0x0u<<31)
#define	OTG_HCCHAR0_CHENA_B_0X1									(0x1u<<31)
#define	OTG_HCCHAR0_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR0_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR0_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR0_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR0_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR0_EPTYP_B_0X0									(0x0u<<18)
#define	OTG_HCCHAR0_EPTYP_B_0X1									(0x1u<<18)
#define	OTG_HCCHAR0_EPTYP_B_0X2									(0x2u<<18)
#define	OTG_HCCHAR0_EPTYP_B_0X3									(0x3u<<18)
#define	OTG_HCCHAR0_EPDIR_B_0X0									(0x0u<<15)
#define	OTG_HCCHAR0_EPDIR_B_0X1									(0x1u<<15)

// HCSPLT0 Configuration

#define	OTG_HCSPLT0_SPLITEN										(0x1u<<31)
#define	OTG_HCSPLT0_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT0_XACTPOS										(0x3u<<14)
#define	OTG_HCSPLT0_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT0_HUBADDR										(0x7Fu<<7)
#define	OTG_HCSPLT0_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT0_PRTADDR										(0x7Fu<<0)
#define	OTG_HCSPLT0_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT0_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT0_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT0_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT0_XACTPOS_B_0X1								(0x1u<<14)

// HCINT0 Configuration

#define	OTG_HCINT0_DTERR										(0x1u<<10)
#define	OTG_HCINT0_FRMOR										(0x1u<<9)
#define	OTG_HCINT0_BBERR										(0x1u<<8)
#define	OTG_HCINT0_TXERR										(0x1u<<7)
#define	OTG_HCINT0_NYET											(0x1u<<6)
#define	OTG_HCINT0_ACK											(0x1u<<5)
#define	OTG_HCINT0_NAK											(0x1u<<4)
#define	OTG_HCINT0_STALL										(0x1u<<3)
#define	OTG_HCINT0_AHBERR										(0x1u<<2)
#define	OTG_HCINT0_CHH											(0x1u<<1)
#define	OTG_HCINT0_XFRC											(0x1u<<0)

// HCINTMSK0 Configuration

#define	OTG_HCINTMSK0_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK0_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK0_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK0_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK0_NYET										(0x1u<<6)
#define	OTG_HCINTMSK0_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK0_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK0_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK0_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK0_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK0_XFRCM										(0x1u<<0)

#define	OTG_HCINTMSK0_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK0_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK0_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK0_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK0_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK0_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK0_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK0_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK0_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK0_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK0_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK0_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK0_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK0_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK0_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK0_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK0_AHBERRM_B_0X0								(0x0u<<2)
#define	OTG_HCINTMSK0_AHBERRM_B_0X1								(0x1u<<2)
#define	OTG_HCINTMSK0_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK0_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK0_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK0_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ0 Configuration

#define	OTG_HCTSIZ0_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ0_DPID										(0x3u<<29)
#define	OTG_HCTSIZ0_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ0_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ0_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ0_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ0_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ0_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ0_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ0_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ0_DPID_B_0X3									(0x3u<<29)

// HCDMA0 Configuration

#define	OTG_HCDMA0_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA0_DMAADDR_0									(0x1u<<0)

// HCCHAR1 Configuration

#define	OTG_HCCHAR1_CHENA										(0x1u<<31)
#define	OTG_HCCHAR1_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR1_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR1_DAD											(0x7Fu<<22)
#define	OTG_HCCHAR1_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR1_MCNT										(0x3u<<20)
#define	OTG_HCCHAR1_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR1_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR1_EPTYP_0										(0x1u<<18)
#define	OTG_HCCHAR1_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR1_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR1_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR1_EPNUM_0										(0x1u<<11)
#define	OTG_HCCHAR1_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR1_MPSIZ_0										(0x1u<<0)

#define	OTG_HCCHAR1_CHENA_B_0X0									(0x0u<<31)
#define	OTG_HCCHAR1_CHENA_B_0X1									(0x1u<<31)
#define	OTG_HCCHAR1_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR1_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR1_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR1_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR1_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR1_EPTYP_B_0X0									(0x0u<<18)
#define	OTG_HCCHAR1_EPTYP_B_0X1									(0x1u<<18)
#define	OTG_HCCHAR1_EPTYP_B_0X2									(0x2u<<18)
#define	OTG_HCCHAR1_EPTYP_B_0X3									(0x3u<<18)
#define	OTG_HCCHAR1_EPDIR_B_0X0									(0x0u<<15)
#define	OTG_HCCHAR1_EPDIR_B_0X1									(0x1u<<15)

// HCSPLT1 Configuration

#define	OTG_HCSPLT1_SPLITEN										(0x1u<<31)
#define	OTG_HCSPLT1_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT1_XACTPOS										(0x3u<<14)
#define	OTG_HCSPLT1_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT1_HUBADDR										(0x7Fu<<7)
#define	OTG_HCSPLT1_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT1_PRTADDR										(0x7Fu<<0)
#define	OTG_HCSPLT1_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT1_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT1_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT1_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT1_XACTPOS_B_0X1								(0x1u<<14)

// HCINT1 Configuration

#define	OTG_HCINT1_DTERR										(0x1u<<10)
#define	OTG_HCINT1_FRMOR										(0x1u<<9)
#define	OTG_HCINT1_BBERR										(0x1u<<8)
#define	OTG_HCINT1_TXERR										(0x1u<<7)
#define	OTG_HCINT1_NYET											(0x1u<<6)
#define	OTG_HCINT1_ACK											(0x1u<<5)
#define	OTG_HCINT1_NAK											(0x1u<<4)
#define	OTG_HCINT1_STALL										(0x1u<<3)
#define	OTG_HCINT1_AHBERR										(0x1u<<2)
#define	OTG_HCINT1_CHH											(0x1u<<1)
#define	OTG_HCINT1_XFRC											(0x1u<<0)

// HCINTMSK1 Configuration

#define	OTG_HCINTMSK1_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK1_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK1_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK1_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK1_NYET										(0x1u<<6)
#define	OTG_HCINTMSK1_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK1_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK1_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK1_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK1_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK1_XFRCM										(0x1u<<0)

#define	OTG_HCINTMSK1_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK1_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK1_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK1_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK1_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK1_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK1_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK1_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK1_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK1_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK1_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK1_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK1_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK1_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK1_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK1_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK1_AHBERRM_B_0X0								(0x0u<<2)
#define	OTG_HCINTMSK1_AHBERRM_B_0X1								(0x1u<<2)
#define	OTG_HCINTMSK1_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK1_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK1_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK1_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ1 Configuration

#define	OTG_HCTSIZ1_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ1_DPID										(0x3u<<29)
#define	OTG_HCTSIZ1_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ1_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ1_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ1_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ1_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ1_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ1_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ1_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ1_DPID_B_0X3									(0x3u<<29)

// HCDMA1 Configuration

#define	OTG_HCDMA1_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA1_DMAADDR_0									(0x1u<<0)

// HCCHAR2 Configuration

#define	OTG_HCCHAR2_CHENA										(0x1u<<31)
#define	OTG_HCCHAR2_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR2_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR2_DAD											(0x7Fu<<22)
#define	OTG_HCCHAR2_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR2_MCNT										(0x3u<<20)
#define	OTG_HCCHAR2_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR2_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR2_EPTYP_0										(0x1u<<18)
#define	OTG_HCCHAR2_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR2_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR2_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR2_EPNUM_0										(0x1u<<11)
#define	OTG_HCCHAR2_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR2_MPSIZ_0										(0x1u<<0)

#define	OTG_HCCHAR2_CHENA_B_0X0									(0x0u<<31)
#define	OTG_HCCHAR2_CHENA_B_0X1									(0x1u<<31)
#define	OTG_HCCHAR2_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR2_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR2_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR2_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR2_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR2_EPTYP_B_0X0									(0x0u<<18)
#define	OTG_HCCHAR2_EPTYP_B_0X1									(0x1u<<18)
#define	OTG_HCCHAR2_EPTYP_B_0X2									(0x2u<<18)
#define	OTG_HCCHAR2_EPTYP_B_0X3									(0x3u<<18)
#define	OTG_HCCHAR2_EPDIR_B_0X0									(0x0u<<15)
#define	OTG_HCCHAR2_EPDIR_B_0X1									(0x1u<<15)

// HCSPLT2 Configuration

#define	OTG_HCSPLT2_SPLITEN										(0x1u<<31)
#define	OTG_HCSPLT2_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT2_XACTPOS										(0x3u<<14)
#define	OTG_HCSPLT2_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT2_HUBADDR										(0x7Fu<<7)
#define	OTG_HCSPLT2_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT2_PRTADDR										(0x7Fu<<0)
#define	OTG_HCSPLT2_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT2_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT2_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT2_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT2_XACTPOS_B_0X1								(0x1u<<14)

// HCINT2 Configuration

#define	OTG_HCINT2_DTERR										(0x1u<<10)
#define	OTG_HCINT2_FRMOR										(0x1u<<9)
#define	OTG_HCINT2_BBERR										(0x1u<<8)
#define	OTG_HCINT2_TXERR										(0x1u<<7)
#define	OTG_HCINT2_NYET											(0x1u<<6)
#define	OTG_HCINT2_ACK											(0x1u<<5)
#define	OTG_HCINT2_NAK											(0x1u<<4)
#define	OTG_HCINT2_STALL										(0x1u<<3)
#define	OTG_HCINT2_AHBERR										(0x1u<<2)
#define	OTG_HCINT2_CHH											(0x1u<<1)
#define	OTG_HCINT2_XFRC											(0x1u<<0)

// HCINTMSK2 Configuration

#define	OTG_HCINTMSK2_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK2_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK2_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK2_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK2_NYET										(0x1u<<6)
#define	OTG_HCINTMSK2_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK2_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK2_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK2_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK2_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK2_XFRCM										(0x1u<<0)

#define	OTG_HCINTMSK2_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK2_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK2_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK2_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK2_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK2_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK2_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK2_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK2_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK2_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK2_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK2_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK2_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK2_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK2_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK2_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK2_AHBERRM_B_0X0								(0x0u<<2)
#define	OTG_HCINTMSK2_AHBERRM_B_0X1								(0x1u<<2)
#define	OTG_HCINTMSK2_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK2_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK2_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK2_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ2 Configuration

#define	OTG_HCTSIZ2_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ2_DPID										(0x3u<<29)
#define	OTG_HCTSIZ2_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ2_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ2_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ2_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ2_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ2_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ2_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ2_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ2_DPID_B_0X3									(0x3u<<29)

// HCDMA2 Configuration

#define	OTG_HCDMA2_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA2_DMAADDR_0									(0x1u<<0)

// HCCHAR3 Configuration

#define	OTG_HCCHAR3_CHENA										(0x1u<<31)
#define	OTG_HCCHAR3_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR3_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR3_DAD											(0x7Fu<<22)
#define	OTG_HCCHAR3_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR3_MCNT										(0x3u<<20)
#define	OTG_HCCHAR3_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR3_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR3_EPTYP_0										(0x1u<<18)
#define	OTG_HCCHAR3_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR3_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR3_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR3_EPNUM_0										(0x1u<<11)
#define	OTG_HCCHAR3_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR3_MPSIZ_0										(0x1u<<0)

#define	OTG_HCCHAR3_CHENA_B_0X0									(0x0u<<31)
#define	OTG_HCCHAR3_CHENA_B_0X1									(0x1u<<31)
#define	OTG_HCCHAR3_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR3_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR3_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR3_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR3_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR3_EPTYP_B_0X0									(0x0u<<18)
#define	OTG_HCCHAR3_EPTYP_B_0X1									(0x1u<<18)
#define	OTG_HCCHAR3_EPTYP_B_0X2									(0x2u<<18)
#define	OTG_HCCHAR3_EPTYP_B_0X3									(0x3u<<18)
#define	OTG_HCCHAR3_EPDIR_B_0X0									(0x0u<<15)
#define	OTG_HCCHAR3_EPDIR_B_0X1									(0x1u<<15)

// HCSPLT3 Configuration

#define	OTG_HCSPLT3_SPLITEN										(0x1u<<31)
#define	OTG_HCSPLT3_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT3_XACTPOS										(0x3u<<14)
#define	OTG_HCSPLT3_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT3_HUBADDR										(0x7Fu<<7)
#define	OTG_HCSPLT3_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT3_PRTADDR										(0x7Fu<<0)
#define	OTG_HCSPLT3_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT3_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT3_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT3_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT3_XACTPOS_B_0X1								(0x1u<<14)

// HCINT3 Configuration

#define	OTG_HCINT3_DTERR										(0x1u<<10)
#define	OTG_HCINT3_FRMOR										(0x1u<<9)
#define	OTG_HCINT3_BBERR										(0x1u<<8)
#define	OTG_HCINT3_TXERR										(0x1u<<7)
#define	OTG_HCINT3_NYET											(0x1u<<6)
#define	OTG_HCINT3_ACK											(0x1u<<5)
#define	OTG_HCINT3_NAK											(0x1u<<4)
#define	OTG_HCINT3_STALL										(0x1u<<3)
#define	OTG_HCINT3_AHBERR										(0x1u<<2)
#define	OTG_HCINT3_CHH											(0x1u<<1)
#define	OTG_HCINT3_XFRC											(0x1u<<0)

// HCINTMSK3 Configuration

#define	OTG_HCINTMSK3_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK3_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK3_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK3_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK3_NYET										(0x1u<<6)
#define	OTG_HCINTMSK3_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK3_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK3_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK3_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK3_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK3_XFRCM										(0x1u<<0)

#define	OTG_HCINTMSK3_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK3_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK3_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK3_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK3_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK3_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK3_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK3_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK3_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK3_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK3_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK3_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK3_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK3_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK3_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK3_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK3_AHBERRM_B_0X0								(0x0u<<2)
#define	OTG_HCINTMSK3_AHBERRM_B_0X1								(0x1u<<2)
#define	OTG_HCINTMSK3_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK3_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK3_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK3_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ3 Configuration

#define	OTG_HCTSIZ3_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ3_DPID										(0x3u<<29)
#define	OTG_HCTSIZ3_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ3_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ3_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ3_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ3_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ3_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ3_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ3_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ3_DPID_B_0X3									(0x3u<<29)

// HCDMA3 Configuration

#define	OTG_HCDMA3_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA3_DMAADDR_0									(0x1u<<0)

// HCCHAR4 Configuration

#define	OTG_HCCHAR4_CHENA										(0x1u<<31)
#define	OTG_HCCHAR4_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR4_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR4_DAD											(0x7Fu<<22)
#define	OTG_HCCHAR4_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR4_MCNT										(0x3u<<20)
#define	OTG_HCCHAR4_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR4_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR4_EPTYP_0										(0x1u<<18)
#define	OTG_HCCHAR4_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR4_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR4_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR4_EPNUM_0										(0x1u<<11)
#define	OTG_HCCHAR4_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR4_MPSIZ_0										(0x1u<<0)

#define	OTG_HCCHAR4_CHENA_B_0X0									(0x0u<<31)
#define	OTG_HCCHAR4_CHENA_B_0X1									(0x1u<<31)
#define	OTG_HCCHAR4_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR4_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR4_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR4_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR4_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR4_EPTYP_B_0X0									(0x0u<<18)
#define	OTG_HCCHAR4_EPTYP_B_0X1									(0x1u<<18)
#define	OTG_HCCHAR4_EPTYP_B_0X2									(0x2u<<18)
#define	OTG_HCCHAR4_EPTYP_B_0X3									(0x3u<<18)
#define	OTG_HCCHAR4_EPDIR_B_0X0									(0x0u<<15)
#define	OTG_HCCHAR4_EPDIR_B_0X1									(0x1u<<15)

// HCSPLT4 Configuration

#define	OTG_HCSPLT4_SPLITEN										(0x1u<<31)
#define	OTG_HCSPLT4_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT4_XACTPOS										(0x3u<<14)
#define	OTG_HCSPLT4_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT4_HUBADDR										(0x7Fu<<7)
#define	OTG_HCSPLT4_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT4_PRTADDR										(0x7Fu<<0)
#define	OTG_HCSPLT4_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT4_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT4_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT4_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT4_XACTPOS_B_0X1								(0x1u<<14)

// HCINT4 Configuration

#define	OTG_HCINT4_DTERR										(0x1u<<10)
#define	OTG_HCINT4_FRMOR										(0x1u<<9)
#define	OTG_HCINT4_BBERR										(0x1u<<8)
#define	OTG_HCINT4_TXERR										(0x1u<<7)
#define	OTG_HCINT4_NYET											(0x1u<<6)
#define	OTG_HCINT4_ACK											(0x1u<<5)
#define	OTG_HCINT4_NAK											(0x1u<<4)
#define	OTG_HCINT4_STALL										(0x1u<<3)
#define	OTG_HCINT4_AHBERR										(0x1u<<2)
#define	OTG_HCINT4_CHH											(0x1u<<1)
#define	OTG_HCINT4_XFRC											(0x1u<<0)

// HCINTMSK4 Configuration

#define	OTG_HCINTMSK4_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK4_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK4_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK4_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK4_NYET										(0x1u<<6)
#define	OTG_HCINTMSK4_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK4_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK4_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK4_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK4_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK4_XFRCM										(0x1u<<0)

#define	OTG_HCINTMSK4_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK4_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK4_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK4_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK4_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK4_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK4_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK4_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK4_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK4_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK4_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK4_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK4_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK4_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK4_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK4_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK4_AHBERRM_B_0X0								(0x0u<<2)
#define	OTG_HCINTMSK4_AHBERRM_B_0X1								(0x1u<<2)
#define	OTG_HCINTMSK4_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK4_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK4_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK4_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ4 Configuration

#define	OTG_HCTSIZ4_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ4_DPID										(0x3u<<29)
#define	OTG_HCTSIZ4_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ4_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ4_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ4_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ4_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ4_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ4_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ4_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ4_DPID_B_0X3									(0x3u<<29)

// HCDMA4 Configuration

#define	OTG_HCDMA4_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA4_DMAADDR_0									(0x1u<<0)

// HCCHAR5 Configuration

#define	OTG_HCCHAR5_CHENA										(0x1u<<31)
#define	OTG_HCCHAR5_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR5_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR5_DAD											(0x7Fu<<22)
#define	OTG_HCCHAR5_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR5_MCNT										(0x3u<<20)
#define	OTG_HCCHAR5_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR5_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR5_EPTYP_0										(0x1u<<18)
#define	OTG_HCCHAR5_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR5_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR5_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR5_EPNUM_0										(0x1u<<11)
#define	OTG_HCCHAR5_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR5_MPSIZ_0										(0x1u<<0)

#define	OTG_HCCHAR5_CHENA_B_0X0									(0x0u<<31)
#define	OTG_HCCHAR5_CHENA_B_0X1									(0x1u<<31)
#define	OTG_HCCHAR5_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR5_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR5_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR5_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR5_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR5_EPTYP_B_0X0									(0x0u<<18)
#define	OTG_HCCHAR5_EPTYP_B_0X1									(0x1u<<18)
#define	OTG_HCCHAR5_EPTYP_B_0X2									(0x2u<<18)
#define	OTG_HCCHAR5_EPTYP_B_0X3									(0x3u<<18)
#define	OTG_HCCHAR5_EPDIR_B_0X0									(0x0u<<15)
#define	OTG_HCCHAR5_EPDIR_B_0X1									(0x1u<<15)

// HCSPLT5 Configuration

#define	OTG_HCSPLT5_SPLITEN										(0x1u<<31)
#define	OTG_HCSPLT5_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT5_XACTPOS										(0x3u<<14)
#define	OTG_HCSPLT5_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT5_HUBADDR										(0x7Fu<<7)
#define	OTG_HCSPLT5_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT5_PRTADDR										(0x7Fu<<0)
#define	OTG_HCSPLT5_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT5_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT5_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT5_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT5_XACTPOS_B_0X1								(0x1u<<14)

// HCINT5 Configuration

#define	OTG_HCINT5_DTERR										(0x1u<<10)
#define	OTG_HCINT5_FRMOR										(0x1u<<9)
#define	OTG_HCINT5_BBERR										(0x1u<<8)
#define	OTG_HCINT5_TXERR										(0x1u<<7)
#define	OTG_HCINT5_NYET											(0x1u<<6)
#define	OTG_HCINT5_ACK											(0x1u<<5)
#define	OTG_HCINT5_NAK											(0x1u<<4)
#define	OTG_HCINT5_STALL										(0x1u<<3)
#define	OTG_HCINT5_AHBERR										(0x1u<<2)
#define	OTG_HCINT5_CHH											(0x1u<<1)
#define	OTG_HCINT5_XFRC											(0x1u<<0)

// HCINTMSK5 Configuration

#define	OTG_HCINTMSK5_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK5_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK5_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK5_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK5_NYET										(0x1u<<6)
#define	OTG_HCINTMSK5_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK5_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK5_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK5_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK5_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK5_XFRCM										(0x1u<<0)

#define	OTG_HCINTMSK5_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK5_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK5_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK5_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK5_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK5_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK5_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK5_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK5_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK5_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK5_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK5_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK5_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK5_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK5_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK5_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK5_AHBERRM_B_0X0								(0x0u<<2)
#define	OTG_HCINTMSK5_AHBERRM_B_0X1								(0x1u<<2)
#define	OTG_HCINTMSK5_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK5_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK5_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK5_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ5 Configuration

#define	OTG_HCTSIZ5_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ5_DPID										(0x3u<<29)
#define	OTG_HCTSIZ5_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ5_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ5_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ5_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ5_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ5_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ5_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ5_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ5_DPID_B_0X3									(0x3u<<29)

// HCDMA5 Configuration

#define	OTG_HCDMA5_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA5_DMAADDR_0									(0x1u<<0)

// HCCHAR6 Configuration

#define	OTG_HCCHAR6_CHENA										(0x1u<<31)
#define	OTG_HCCHAR6_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR6_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR6_DAD											(0x7Fu<<22)
#define	OTG_HCCHAR6_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR6_MCNT										(0x3u<<20)
#define	OTG_HCCHAR6_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR6_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR6_EPTYP_0										(0x1u<<18)
#define	OTG_HCCHAR6_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR6_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR6_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR6_EPNUM_0										(0x1u<<11)
#define	OTG_HCCHAR6_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR6_MPSIZ_0										(0x1u<<0)

#define	OTG_HCCHAR6_CHENA_B_0X0									(0x0u<<31)
#define	OTG_HCCHAR6_CHENA_B_0X1									(0x1u<<31)
#define	OTG_HCCHAR6_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR6_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR6_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR6_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR6_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR6_EPTYP_B_0X0									(0x0u<<18)
#define	OTG_HCCHAR6_EPTYP_B_0X1									(0x1u<<18)
#define	OTG_HCCHAR6_EPTYP_B_0X2									(0x2u<<18)
#define	OTG_HCCHAR6_EPTYP_B_0X3									(0x3u<<18)
#define	OTG_HCCHAR6_EPDIR_B_0X0									(0x0u<<15)
#define	OTG_HCCHAR6_EPDIR_B_0X1									(0x1u<<15)

// HCSPLT6 Configuration

#define	OTG_HCSPLT6_SPLITEN										(0x1u<<31)
#define	OTG_HCSPLT6_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT6_XACTPOS										(0x3u<<14)
#define	OTG_HCSPLT6_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT6_HUBADDR										(0x7Fu<<7)
#define	OTG_HCSPLT6_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT6_PRTADDR										(0x7Fu<<0)
#define	OTG_HCSPLT6_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT6_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT6_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT6_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT6_XACTPOS_B_0X1								(0x1u<<14)

// HCINT6 Configuration

#define	OTG_HCINT6_DTERR										(0x1u<<10)
#define	OTG_HCINT6_FRMOR										(0x1u<<9)
#define	OTG_HCINT6_BBERR										(0x1u<<8)
#define	OTG_HCINT6_TXERR										(0x1u<<7)
#define	OTG_HCINT6_NYET											(0x1u<<6)
#define	OTG_HCINT6_ACK											(0x1u<<5)
#define	OTG_HCINT6_NAK											(0x1u<<4)
#define	OTG_HCINT6_STALL										(0x1u<<3)
#define	OTG_HCINT6_AHBERR										(0x1u<<2)
#define	OTG_HCINT6_CHH											(0x1u<<1)
#define	OTG_HCINT6_XFRC											(0x1u<<0)

// HCINTMSK6 Configuration

#define	OTG_HCINTMSK6_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK6_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK6_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK6_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK6_NYET										(0x1u<<6)
#define	OTG_HCINTMSK6_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK6_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK6_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK6_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK6_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK6_XFRCM										(0x1u<<0)

#define	OTG_HCINTMSK6_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK6_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK6_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK6_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK6_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK6_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK6_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK6_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK6_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK6_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK6_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK6_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK6_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK6_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK6_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK6_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK6_AHBERRM_B_0X0								(0x0u<<2)
#define	OTG_HCINTMSK6_AHBERRM_B_0X1								(0x1u<<2)
#define	OTG_HCINTMSK6_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK6_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK6_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK6_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ6 Configuration

#define	OTG_HCTSIZ6_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ6_DPID										(0x3u<<29)
#define	OTG_HCTSIZ6_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ6_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ6_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ6_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ6_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ6_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ6_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ6_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ6_DPID_B_0X3									(0x3u<<29)

// HCDMA6 Configuration

#define	OTG_HCDMA6_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA6_DMAADDR_0									(0x1u<<0)

// HCCHAR7 Configuration

#define	OTG_HCCHAR7_CHENA										(0x1u<<31)
#define	OTG_HCCHAR7_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR7_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR7_DAD											(0x7Fu<<22)
#define	OTG_HCCHAR7_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR7_MCNT										(0x3u<<20)
#define	OTG_HCCHAR7_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR7_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR7_EPTYP_0										(0x1u<<18)
#define	OTG_HCCHAR7_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR7_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR7_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR7_EPNUM_0										(0x1u<<11)
#define	OTG_HCCHAR7_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR7_MPSIZ_0										(0x1u<<0)

#define	OTG_HCCHAR7_CHENA_B_0X0									(0x0u<<31)
#define	OTG_HCCHAR7_CHENA_B_0X1									(0x1u<<31)
#define	OTG_HCCHAR7_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR7_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR7_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR7_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR7_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR7_EPTYP_B_0X0									(0x0u<<18)
#define	OTG_HCCHAR7_EPTYP_B_0X1									(0x1u<<18)
#define	OTG_HCCHAR7_EPTYP_B_0X2									(0x2u<<18)
#define	OTG_HCCHAR7_EPTYP_B_0X3									(0x3u<<18)
#define	OTG_HCCHAR7_EPDIR_B_0X0									(0x0u<<15)
#define	OTG_HCCHAR7_EPDIR_B_0X1									(0x1u<<15)

// HCSPLT7 Configuration

#define	OTG_HCSPLT7_SPLITEN										(0x1u<<31)
#define	OTG_HCSPLT7_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT7_XACTPOS										(0x3u<<14)
#define	OTG_HCSPLT7_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT7_HUBADDR										(0x7Fu<<7)
#define	OTG_HCSPLT7_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT7_PRTADDR										(0x7Fu<<0)
#define	OTG_HCSPLT7_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT7_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT7_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT7_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT7_XACTPOS_B_0X1								(0x1u<<14)

// HCINT7 Configuration

#define	OTG_HCINT7_DTERR										(0x1u<<10)
#define	OTG_HCINT7_FRMOR										(0x1u<<9)
#define	OTG_HCINT7_BBERR										(0x1u<<8)
#define	OTG_HCINT7_TXERR										(0x1u<<7)
#define	OTG_HCINT7_NYET											(0x1u<<6)
#define	OTG_HCINT7_ACK											(0x1u<<5)
#define	OTG_HCINT7_NAK											(0x1u<<4)
#define	OTG_HCINT7_STALL										(0x1u<<3)
#define	OTG_HCINT7_AHBERR										(0x1u<<2)
#define	OTG_HCINT7_CHH											(0x1u<<1)
#define	OTG_HCINT7_XFRC											(0x1u<<0)

// HCINTMSK7 Configuration

#define	OTG_HCINTMSK7_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK7_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK7_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK7_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK7_NYET										(0x1u<<6)
#define	OTG_HCINTMSK7_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK7_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK7_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK7_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK7_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK7_XFRCM										(0x1u<<0)

#define	OTG_HCINTMSK7_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK7_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK7_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK7_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK7_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK7_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK7_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK7_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK7_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK7_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK7_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK7_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK7_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK7_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK7_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK7_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK7_AHBERRM_B_0X0								(0x0u<<2)
#define	OTG_HCINTMSK7_AHBERRM_B_0X1								(0x1u<<2)
#define	OTG_HCINTMSK7_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK7_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK7_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK7_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ7 Configuration

#define	OTG_HCTSIZ7_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ7_DPID										(0x3u<<29)
#define	OTG_HCTSIZ7_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ7_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ7_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ7_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ7_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ7_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ7_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ7_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ7_DPID_B_0X3									(0x3u<<29)

// HCDMA7 Configuration

#define	OTG_HCDMA7_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA7_DMAADDR_0									(0x1u<<0)

// HCCHAR8 Configuration

#define	OTG_HCCHAR8_CHENA										(0x1u<<31)
#define	OTG_HCCHAR8_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR8_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR8_DAD											(0x7Fu<<22)
#define	OTG_HCCHAR8_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR8_MCNT										(0x3u<<20)
#define	OTG_HCCHAR8_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR8_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR8_EPTYP_0										(0x1u<<18)
#define	OTG_HCCHAR8_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR8_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR8_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR8_EPNUM_0										(0x1u<<11)
#define	OTG_HCCHAR8_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR8_MPSIZ_0										(0x1u<<0)

#define	OTG_HCCHAR8_CHENA_B_0X0									(0x0u<<31)
#define	OTG_HCCHAR8_CHENA_B_0X1									(0x1u<<31)
#define	OTG_HCCHAR8_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR8_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR8_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR8_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR8_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR8_EPTYP_B_0X0									(0x0u<<18)
#define	OTG_HCCHAR8_EPTYP_B_0X1									(0x1u<<18)
#define	OTG_HCCHAR8_EPTYP_B_0X2									(0x2u<<18)
#define	OTG_HCCHAR8_EPTYP_B_0X3									(0x3u<<18)
#define	OTG_HCCHAR8_EPDIR_B_0X0									(0x0u<<15)
#define	OTG_HCCHAR8_EPDIR_B_0X1									(0x1u<<15)

// HCSPLT8 Configuration

#define	OTG_HCSPLT8_SPLITEN										(0x1u<<31)
#define	OTG_HCSPLT8_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT8_XACTPOS										(0x3u<<14)
#define	OTG_HCSPLT8_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT8_HUBADDR										(0x7Fu<<7)
#define	OTG_HCSPLT8_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT8_PRTADDR										(0x7Fu<<0)
#define	OTG_HCSPLT8_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT8_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT8_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT8_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT8_XACTPOS_B_0X1								(0x1u<<14)

// HCINT8 Configuration

#define	OTG_HCINT8_DTERR										(0x1u<<10)
#define	OTG_HCINT8_FRMOR										(0x1u<<9)
#define	OTG_HCINT8_BBERR										(0x1u<<8)
#define	OTG_HCINT8_TXERR										(0x1u<<7)
#define	OTG_HCINT8_NYET											(0x1u<<6)
#define	OTG_HCINT8_ACK											(0x1u<<5)
#define	OTG_HCINT8_NAK											(0x1u<<4)
#define	OTG_HCINT8_STALL										(0x1u<<3)
#define	OTG_HCINT8_AHBERR										(0x1u<<2)
#define	OTG_HCINT8_CHH											(0x1u<<1)
#define	OTG_HCINT8_XFRC											(0x1u<<0)

// HCINTMSK8 Configuration

#define	OTG_HCINTMSK8_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK8_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK8_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK8_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK8_NYET										(0x1u<<6)
#define	OTG_HCINTMSK8_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK8_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK8_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK8_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK8_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK8_XFRCM										(0x1u<<0)

#define	OTG_HCINTMSK8_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK8_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK8_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK8_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK8_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK8_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK8_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK8_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK8_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK8_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK8_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK8_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK8_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK8_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK8_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK8_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK8_AHBERRM_B_0X0								(0x0u<<2)
#define	OTG_HCINTMSK8_AHBERRM_B_0X1								(0x1u<<2)
#define	OTG_HCINTMSK8_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK8_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK8_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK8_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ8 Configuration

#define	OTG_HCTSIZ8_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ8_DPID										(0x3u<<29)
#define	OTG_HCTSIZ8_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ8_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ8_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ8_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ8_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ8_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ8_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ8_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ8_DPID_B_0X3									(0x3u<<29)

// HCDMA8 Configuration

#define	OTG_HCDMA8_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA8_DMAADDR_0									(0x1u<<0)

// HCCHAR9 Configuration

#define	OTG_HCCHAR9_CHENA										(0x1u<<31)
#define	OTG_HCCHAR9_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR9_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR9_DAD											(0x7Fu<<22)
#define	OTG_HCCHAR9_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR9_MCNT										(0x3u<<20)
#define	OTG_HCCHAR9_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR9_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR9_EPTYP_0										(0x1u<<18)
#define	OTG_HCCHAR9_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR9_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR9_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR9_EPNUM_0										(0x1u<<11)
#define	OTG_HCCHAR9_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR9_MPSIZ_0										(0x1u<<0)

#define	OTG_HCCHAR9_CHENA_B_0X0									(0x0u<<31)
#define	OTG_HCCHAR9_CHENA_B_0X1									(0x1u<<31)
#define	OTG_HCCHAR9_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR9_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR9_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR9_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR9_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR9_EPTYP_B_0X0									(0x0u<<18)
#define	OTG_HCCHAR9_EPTYP_B_0X1									(0x1u<<18)
#define	OTG_HCCHAR9_EPTYP_B_0X2									(0x2u<<18)
#define	OTG_HCCHAR9_EPTYP_B_0X3									(0x3u<<18)
#define	OTG_HCCHAR9_EPDIR_B_0X0									(0x0u<<15)
#define	OTG_HCCHAR9_EPDIR_B_0X1									(0x1u<<15)

// HCSPLT9 Configuration

#define	OTG_HCSPLT9_SPLITEN										(0x1u<<31)
#define	OTG_HCSPLT9_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT9_XACTPOS										(0x3u<<14)
#define	OTG_HCSPLT9_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT9_HUBADDR										(0x7Fu<<7)
#define	OTG_HCSPLT9_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT9_PRTADDR										(0x7Fu<<0)
#define	OTG_HCSPLT9_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT9_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT9_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT9_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT9_XACTPOS_B_0X1								(0x1u<<14)

// HCINT9 Configuration

#define	OTG_HCINT9_DTERR										(0x1u<<10)
#define	OTG_HCINT9_FRMOR										(0x1u<<9)
#define	OTG_HCINT9_BBERR										(0x1u<<8)
#define	OTG_HCINT9_TXERR										(0x1u<<7)
#define	OTG_HCINT9_NYET											(0x1u<<6)
#define	OTG_HCINT9_ACK											(0x1u<<5)
#define	OTG_HCINT9_NAK											(0x1u<<4)
#define	OTG_HCINT9_STALL										(0x1u<<3)
#define	OTG_HCINT9_AHBERR										(0x1u<<2)
#define	OTG_HCINT9_CHH											(0x1u<<1)
#define	OTG_HCINT9_XFRC											(0x1u<<0)

// HCINTMSK9 Configuration

#define	OTG_HCINTMSK9_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK9_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK9_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK9_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK9_NYET										(0x1u<<6)
#define	OTG_HCINTMSK9_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK9_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK9_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK9_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK9_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK9_XFRCM										(0x1u<<0)

#define	OTG_HCINTMSK9_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK9_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK9_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK9_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK9_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK9_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK9_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK9_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK9_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK9_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK9_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK9_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK9_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK9_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK9_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK9_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK9_AHBERRM_B_0X0								(0x0u<<2)
#define	OTG_HCINTMSK9_AHBERRM_B_0X1								(0x1u<<2)
#define	OTG_HCINTMSK9_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK9_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK9_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK9_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ9 Configuration

#define	OTG_HCTSIZ9_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ9_DPID										(0x3u<<29)
#define	OTG_HCTSIZ9_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ9_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ9_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ9_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ9_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ9_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ9_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ9_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ9_DPID_B_0X3									(0x3u<<29)

// HCDMA9 Configuration

#define	OTG_HCDMA9_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA9_DMAADDR_0									(0x1u<<0)

// HCCHAR10 Configuration

#define	OTG_HCCHAR10_CHENA										(0x1u<<31)
#define	OTG_HCCHAR10_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR10_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR10_DAD										(0x7Fu<<22)
#define	OTG_HCCHAR10_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR10_MCNT										(0x3u<<20)
#define	OTG_HCCHAR10_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR10_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR10_EPTYP_0									(0x1u<<18)
#define	OTG_HCCHAR10_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR10_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR10_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR10_EPNUM_0									(0x1u<<11)
#define	OTG_HCCHAR10_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR10_MPSIZ_0									(0x1u<<0)

#define	OTG_HCCHAR10_CHENA_B_0X0								(0x0u<<31)
#define	OTG_HCCHAR10_CHENA_B_0X1								(0x1u<<31)
#define	OTG_HCCHAR10_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR10_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR10_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR10_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR10_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR10_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_HCCHAR10_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_HCCHAR10_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_HCCHAR10_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_HCCHAR10_EPDIR_B_0X0								(0x0u<<15)
#define	OTG_HCCHAR10_EPDIR_B_0X1								(0x1u<<15)

// HCSPLT10 Configuration

#define	OTG_HCSPLT10_SPLITEN									(0x1u<<31)
#define	OTG_HCSPLT10_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT10_XACTPOS									(0x3u<<14)
#define	OTG_HCSPLT10_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT10_HUBADDR									(0x7Fu<<7)
#define	OTG_HCSPLT10_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT10_PRTADDR									(0x7Fu<<0)
#define	OTG_HCSPLT10_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT10_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT10_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT10_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT10_XACTPOS_B_0X1								(0x1u<<14)

// HCINT10 Configuration

#define	OTG_HCINT10_DTERR										(0x1u<<10)
#define	OTG_HCINT10_FRMOR										(0x1u<<9)
#define	OTG_HCINT10_BBERR										(0x1u<<8)
#define	OTG_HCINT10_TXERR										(0x1u<<7)
#define	OTG_HCINT10_NYET										(0x1u<<6)
#define	OTG_HCINT10_ACK											(0x1u<<5)
#define	OTG_HCINT10_NAK											(0x1u<<4)
#define	OTG_HCINT10_STALL										(0x1u<<3)
#define	OTG_HCINT10_AHBERR										(0x1u<<2)
#define	OTG_HCINT10_CHH											(0x1u<<1)
#define	OTG_HCINT10_XFRC										(0x1u<<0)

// HCINTMSK10 Configuration

#define	OTG_HCINTMSK10_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK10_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK10_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK10_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK10_NYET										(0x1u<<6)
#define	OTG_HCINTMSK10_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK10_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK10_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK10_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK10_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK10_XFRCM									(0x1u<<0)

#define	OTG_HCINTMSK10_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK10_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK10_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK10_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK10_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK10_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK10_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK10_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK10_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK10_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK10_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK10_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK10_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK10_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK10_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK10_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK10_AHBERRM_B_0X0							(0x0u<<2)
#define	OTG_HCINTMSK10_AHBERRM_B_0X1							(0x1u<<2)
#define	OTG_HCINTMSK10_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK10_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK10_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK10_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ10 Configuration

#define	OTG_HCTSIZ10_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ10_DPID										(0x3u<<29)
#define	OTG_HCTSIZ10_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ10_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ10_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ10_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ10_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ10_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ10_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ10_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ10_DPID_B_0X3									(0x3u<<29)

// HCDMA10 Configuration

#define	OTG_HCDMA10_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA10_DMAADDR_0									(0x1u<<0)

// HCCHAR11 Configuration

#define	OTG_HCCHAR11_CHENA										(0x1u<<31)
#define	OTG_HCCHAR11_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR11_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR11_DAD										(0x7Fu<<22)
#define	OTG_HCCHAR11_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR11_MCNT										(0x3u<<20)
#define	OTG_HCCHAR11_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR11_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR11_EPTYP_0									(0x1u<<18)
#define	OTG_HCCHAR11_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR11_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR11_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR11_EPNUM_0									(0x1u<<11)
#define	OTG_HCCHAR11_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR11_MPSIZ_0									(0x1u<<0)

#define	OTG_HCCHAR11_CHENA_B_0X0								(0x0u<<31)
#define	OTG_HCCHAR11_CHENA_B_0X1								(0x1u<<31)
#define	OTG_HCCHAR11_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR11_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR11_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR11_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR11_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR11_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_HCCHAR11_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_HCCHAR11_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_HCCHAR11_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_HCCHAR11_EPDIR_B_0X0								(0x0u<<15)
#define	OTG_HCCHAR11_EPDIR_B_0X1								(0x1u<<15)

// HCSPLT11 Configuration

#define	OTG_HCSPLT11_SPLITEN									(0x1u<<31)
#define	OTG_HCSPLT11_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT11_XACTPOS									(0x3u<<14)
#define	OTG_HCSPLT11_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT11_HUBADDR									(0x7Fu<<7)
#define	OTG_HCSPLT11_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT11_PRTADDR									(0x7Fu<<0)
#define	OTG_HCSPLT11_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT11_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT11_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT11_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT11_XACTPOS_B_0X1								(0x1u<<14)

// HCINT11 Configuration

#define	OTG_HCINT11_DTERR										(0x1u<<10)
#define	OTG_HCINT11_FRMOR										(0x1u<<9)
#define	OTG_HCINT11_BBERR										(0x1u<<8)
#define	OTG_HCINT11_TXERR										(0x1u<<7)
#define	OTG_HCINT11_NYET										(0x1u<<6)
#define	OTG_HCINT11_ACK											(0x1u<<5)
#define	OTG_HCINT11_NAK											(0x1u<<4)
#define	OTG_HCINT11_STALL										(0x1u<<3)
#define	OTG_HCINT11_AHBERR										(0x1u<<2)
#define	OTG_HCINT11_CHH											(0x1u<<1)
#define	OTG_HCINT11_XFRC										(0x1u<<0)

// HCINTMSK11 Configuration

#define	OTG_HCINTMSK11_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK11_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK11_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK11_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK11_NYET										(0x1u<<6)
#define	OTG_HCINTMSK11_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK11_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK11_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK11_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK11_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK11_XFRCM									(0x1u<<0)

#define	OTG_HCINTMSK11_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK11_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK11_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK11_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK11_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK11_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK11_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK11_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK11_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK11_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK11_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK11_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK11_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK11_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK11_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK11_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK11_AHBERRM_B_0X0							(0x0u<<2)
#define	OTG_HCINTMSK11_AHBERRM_B_0X1							(0x1u<<2)
#define	OTG_HCINTMSK11_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK11_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK11_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK11_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ11 Configuration

#define	OTG_HCTSIZ11_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ11_DPID										(0x3u<<29)
#define	OTG_HCTSIZ11_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ11_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ11_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ11_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ11_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ11_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ11_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ11_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ11_DPID_B_0X3									(0x3u<<29)

// HCDMA11 Configuration

#define	OTG_HCDMA11_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA11_DMAADDR_0									(0x1u<<0)

// HCCHAR12 Configuration

#define	OTG_HCCHAR12_CHENA										(0x1u<<31)
#define	OTG_HCCHAR12_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR12_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR12_DAD										(0x7Fu<<22)
#define	OTG_HCCHAR12_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR12_MCNT										(0x3u<<20)
#define	OTG_HCCHAR12_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR12_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR12_EPTYP_0									(0x1u<<18)
#define	OTG_HCCHAR12_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR12_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR12_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR12_EPNUM_0									(0x1u<<11)
#define	OTG_HCCHAR12_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR12_MPSIZ_0									(0x1u<<0)

#define	OTG_HCCHAR12_CHENA_B_0X0								(0x0u<<31)
#define	OTG_HCCHAR12_CHENA_B_0X1								(0x1u<<31)
#define	OTG_HCCHAR12_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR12_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR12_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR12_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR12_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR12_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_HCCHAR12_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_HCCHAR12_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_HCCHAR12_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_HCCHAR12_EPDIR_B_0X0								(0x0u<<15)
#define	OTG_HCCHAR12_EPDIR_B_0X1								(0x1u<<15)

// HCSPLT12 Configuration

#define	OTG_HCSPLT12_SPLITEN									(0x1u<<31)
#define	OTG_HCSPLT12_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT12_XACTPOS									(0x3u<<14)
#define	OTG_HCSPLT12_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT12_HUBADDR									(0x7Fu<<7)
#define	OTG_HCSPLT12_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT12_PRTADDR									(0x7Fu<<0)
#define	OTG_HCSPLT12_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT12_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT12_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT12_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT12_XACTPOS_B_0X1								(0x1u<<14)

// HCINT12 Configuration

#define	OTG_HCINT12_DTERR										(0x1u<<10)
#define	OTG_HCINT12_FRMOR										(0x1u<<9)
#define	OTG_HCINT12_BBERR										(0x1u<<8)
#define	OTG_HCINT12_TXERR										(0x1u<<7)
#define	OTG_HCINT12_NYET										(0x1u<<6)
#define	OTG_HCINT12_ACK											(0x1u<<5)
#define	OTG_HCINT12_NAK											(0x1u<<4)
#define	OTG_HCINT12_STALL										(0x1u<<3)
#define	OTG_HCINT12_AHBERR										(0x1u<<2)
#define	OTG_HCINT12_CHH											(0x1u<<1)
#define	OTG_HCINT12_XFRC										(0x1u<<0)

// HCINTMSK12 Configuration

#define	OTG_HCINTMSK12_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK12_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK12_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK12_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK12_NYET										(0x1u<<6)
#define	OTG_HCINTMSK12_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK12_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK12_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK12_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK12_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK12_XFRCM									(0x1u<<0)

#define	OTG_HCINTMSK12_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK12_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK12_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK12_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK12_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK12_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK12_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK12_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK12_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK12_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK12_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK12_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK12_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK12_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK12_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK12_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK12_AHBERRM_B_0X0							(0x0u<<2)
#define	OTG_HCINTMSK12_AHBERRM_B_0X1							(0x1u<<2)
#define	OTG_HCINTMSK12_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK12_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK12_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK12_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ12 Configuration

#define	OTG_HCTSIZ12_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ12_DPID										(0x3u<<29)
#define	OTG_HCTSIZ12_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ12_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ12_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ12_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ12_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ12_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ12_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ12_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ12_DPID_B_0X3									(0x3u<<29)

// HCDMA12 Configuration

#define	OTG_HCDMA12_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA12_DMAADDR_0									(0x1u<<0)

// HCCHAR13 Configuration

#define	OTG_HCCHAR13_CHENA										(0x1u<<31)
#define	OTG_HCCHAR13_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR13_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR13_DAD										(0x7Fu<<22)
#define	OTG_HCCHAR13_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR13_MCNT										(0x3u<<20)
#define	OTG_HCCHAR13_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR13_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR13_EPTYP_0									(0x1u<<18)
#define	OTG_HCCHAR13_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR13_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR13_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR13_EPNUM_0									(0x1u<<11)
#define	OTG_HCCHAR13_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR13_MPSIZ_0									(0x1u<<0)

#define	OTG_HCCHAR13_CHENA_B_0X0								(0x0u<<31)
#define	OTG_HCCHAR13_CHENA_B_0X1								(0x1u<<31)
#define	OTG_HCCHAR13_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR13_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR13_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR13_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR13_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR13_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_HCCHAR13_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_HCCHAR13_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_HCCHAR13_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_HCCHAR13_EPDIR_B_0X0								(0x0u<<15)
#define	OTG_HCCHAR13_EPDIR_B_0X1								(0x1u<<15)

// HCSPLT13 Configuration

#define	OTG_HCSPLT13_SPLITEN									(0x1u<<31)
#define	OTG_HCSPLT13_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT13_XACTPOS									(0x3u<<14)
#define	OTG_HCSPLT13_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT13_HUBADDR									(0x7Fu<<7)
#define	OTG_HCSPLT13_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT13_PRTADDR									(0x7Fu<<0)
#define	OTG_HCSPLT13_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT13_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT13_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT13_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT13_XACTPOS_B_0X1								(0x1u<<14)

// HCINT13 Configuration

#define	OTG_HCINT13_DTERR										(0x1u<<10)
#define	OTG_HCINT13_FRMOR										(0x1u<<9)
#define	OTG_HCINT13_BBERR										(0x1u<<8)
#define	OTG_HCINT13_TXERR										(0x1u<<7)
#define	OTG_HCINT13_NYET										(0x1u<<6)
#define	OTG_HCINT13_ACK											(0x1u<<5)
#define	OTG_HCINT13_NAK											(0x1u<<4)
#define	OTG_HCINT13_STALL										(0x1u<<3)
#define	OTG_HCINT13_AHBERR										(0x1u<<2)
#define	OTG_HCINT13_CHH											(0x1u<<1)
#define	OTG_HCINT13_XFRC										(0x1u<<0)

// HCINTMSK13 Configuration

#define	OTG_HCINTMSK13_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK13_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK13_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK13_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK13_NYET										(0x1u<<6)
#define	OTG_HCINTMSK13_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK13_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK13_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK13_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK13_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK13_XFRCM									(0x1u<<0)

#define	OTG_HCINTMSK13_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK13_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK13_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK13_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK13_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK13_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK13_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK13_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK13_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK13_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK13_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK13_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK13_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK13_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK13_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK13_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK13_AHBERRM_B_0X0							(0x0u<<2)
#define	OTG_HCINTMSK13_AHBERRM_B_0X1							(0x1u<<2)
#define	OTG_HCINTMSK13_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK13_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK13_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK13_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ13 Configuration

#define	OTG_HCTSIZ13_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ13_DPID										(0x3u<<29)
#define	OTG_HCTSIZ13_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ13_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ13_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ13_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ13_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ13_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ13_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ13_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ13_DPID_B_0X3									(0x3u<<29)

// HCDMA13 Configuration

#define	OTG_HCDMA13_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA13_DMAADDR_0									(0x1u<<0)

// HCCHAR14 Configuration

#define	OTG_HCCHAR14_CHENA										(0x1u<<31)
#define	OTG_HCCHAR14_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR14_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR14_DAD										(0x7Fu<<22)
#define	OTG_HCCHAR14_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR14_MCNT										(0x3u<<20)
#define	OTG_HCCHAR14_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR14_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR14_EPTYP_0									(0x1u<<18)
#define	OTG_HCCHAR14_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR14_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR14_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR14_EPNUM_0									(0x1u<<11)
#define	OTG_HCCHAR14_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR14_MPSIZ_0									(0x1u<<0)

#define	OTG_HCCHAR14_CHENA_B_0X0								(0x0u<<31)
#define	OTG_HCCHAR14_CHENA_B_0X1								(0x1u<<31)
#define	OTG_HCCHAR14_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR14_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR14_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR14_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR14_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR14_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_HCCHAR14_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_HCCHAR14_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_HCCHAR14_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_HCCHAR14_EPDIR_B_0X0								(0x0u<<15)
#define	OTG_HCCHAR14_EPDIR_B_0X1								(0x1u<<15)

// HCSPLT14 Configuration

#define	OTG_HCSPLT14_SPLITEN									(0x1u<<31)
#define	OTG_HCSPLT14_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT14_XACTPOS									(0x3u<<14)
#define	OTG_HCSPLT14_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT14_HUBADDR									(0x7Fu<<7)
#define	OTG_HCSPLT14_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT14_PRTADDR									(0x7Fu<<0)
#define	OTG_HCSPLT14_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT14_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT14_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT14_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT14_XACTPOS_B_0X1								(0x1u<<14)

// HCINT14 Configuration

#define	OTG_HCINT14_DTERR										(0x1u<<10)
#define	OTG_HCINT14_FRMOR										(0x1u<<9)
#define	OTG_HCINT14_BBERR										(0x1u<<8)
#define	OTG_HCINT14_TXERR										(0x1u<<7)
#define	OTG_HCINT14_NYET										(0x1u<<6)
#define	OTG_HCINT14_ACK											(0x1u<<5)
#define	OTG_HCINT14_NAK											(0x1u<<4)
#define	OTG_HCINT14_STALL										(0x1u<<3)
#define	OTG_HCINT14_AHBERR										(0x1u<<2)
#define	OTG_HCINT14_CHH											(0x1u<<1)
#define	OTG_HCINT14_XFRC										(0x1u<<0)

// HCINTMSK14 Configuration

#define	OTG_HCINTMSK14_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK14_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK14_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK14_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK14_NYET										(0x1u<<6)
#define	OTG_HCINTMSK14_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK14_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK14_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK14_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK14_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK14_XFRCM									(0x1u<<0)

#define	OTG_HCINTMSK14_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK14_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK14_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK14_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK14_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK14_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK14_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK14_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK14_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK14_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK14_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK14_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK14_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK14_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK14_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK14_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK14_AHBERRM_B_0X0							(0x0u<<2)
#define	OTG_HCINTMSK14_AHBERRM_B_0X1							(0x1u<<2)
#define	OTG_HCINTMSK14_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK14_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK14_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK14_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ14 Configuration

#define	OTG_HCTSIZ14_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ14_DPID										(0x3u<<29)
#define	OTG_HCTSIZ14_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ14_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ14_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ14_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ14_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ14_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ14_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ14_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ14_DPID_B_0X3									(0x3u<<29)

// HCDMA14 Configuration

#define	OTG_HCDMA14_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA14_DMAADDR_0									(0x1u<<0)

// HCCHAR15 Configuration

#define	OTG_HCCHAR15_CHENA										(0x1u<<31)
#define	OTG_HCCHAR15_CHDIS										(0x1u<<30)
#define	OTG_HCCHAR15_ODDFRM										(0x1u<<29)
#define	OTG_HCCHAR15_DAD										(0x7Fu<<22)
#define	OTG_HCCHAR15_DAD_0										(0x1u<<22)
#define	OTG_HCCHAR15_MCNT										(0x3u<<20)
#define	OTG_HCCHAR15_MCNT_0										(0x1u<<20)
#define	OTG_HCCHAR15_EPTYP										(0x3u<<18)
#define	OTG_HCCHAR15_EPTYP_0									(0x1u<<18)
#define	OTG_HCCHAR15_LSDEV										(0x1u<<17)
#define	OTG_HCCHAR15_EPDIR										(0x1u<<15)
#define	OTG_HCCHAR15_EPNUM										(0xFu<<11)
#define	OTG_HCCHAR15_EPNUM_0									(0x1u<<11)
#define	OTG_HCCHAR15_MPSIZ										(0x7FFu<<0)
#define	OTG_HCCHAR15_MPSIZ_0									(0x1u<<0)

#define	OTG_HCCHAR15_CHENA_B_0X0								(0x0u<<31)
#define	OTG_HCCHAR15_CHENA_B_0X1								(0x1u<<31)
#define	OTG_HCCHAR15_ODDFRM_B_0X0								(0x0u<<29)
#define	OTG_HCCHAR15_ODDFRM_B_0X1								(0x1u<<29)
#define	OTG_HCCHAR15_MCNT_B_0X1									(0x1u<<20)
#define	OTG_HCCHAR15_MCNT_B_0X2									(0x2u<<20)
#define	OTG_HCCHAR15_MCNT_B_0X3									(0x3u<<20)
#define	OTG_HCCHAR15_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_HCCHAR15_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_HCCHAR15_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_HCCHAR15_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_HCCHAR15_EPDIR_B_0X0								(0x0u<<15)
#define	OTG_HCCHAR15_EPDIR_B_0X1								(0x1u<<15)

// HCSPLT15 Configuration

#define	OTG_HCSPLT15_SPLITEN									(0x1u<<31)
#define	OTG_HCSPLT15_COMPLSPLT									(0x1u<<16)
#define	OTG_HCSPLT15_XACTPOS									(0x3u<<14)
#define	OTG_HCSPLT15_XACTPOS_0									(0x1u<<14)
#define	OTG_HCSPLT15_HUBADDR									(0x7Fu<<7)
#define	OTG_HCSPLT15_HUBADDR_0									(0x1u<<7)
#define	OTG_HCSPLT15_PRTADDR									(0x7Fu<<0)
#define	OTG_HCSPLT15_PRTADDR_0									(0x1u<<0)

#define	OTG_HCSPLT15_XACTPOS_B_0X3								(0x3u<<14)
#define	OTG_HCSPLT15_XACTPOS_B_0X2								(0x2u<<14)
#define	OTG_HCSPLT15_XACTPOS_B_0X0								(0x0u<<14)
#define	OTG_HCSPLT15_XACTPOS_B_0X1								(0x1u<<14)

// HCINT15 Configuration

#define	OTG_HCINT15_DTERR										(0x1u<<10)
#define	OTG_HCINT15_FRMOR										(0x1u<<9)
#define	OTG_HCINT15_BBERR										(0x1u<<8)
#define	OTG_HCINT15_TXERR										(0x1u<<7)
#define	OTG_HCINT15_NYET										(0x1u<<6)
#define	OTG_HCINT15_ACK											(0x1u<<5)
#define	OTG_HCINT15_NAK											(0x1u<<4)
#define	OTG_HCINT15_STALL										(0x1u<<3)
#define	OTG_HCINT15_AHBERR										(0x1u<<2)
#define	OTG_HCINT15_CHH											(0x1u<<1)
#define	OTG_HCINT15_XFRC										(0x1u<<0)

// HCINTMSK15 Configuration

#define	OTG_HCINTMSK15_DTERRM									(0x1u<<10)
#define	OTG_HCINTMSK15_FRMORM									(0x1u<<9)
#define	OTG_HCINTMSK15_BBERRM									(0x1u<<8)
#define	OTG_HCINTMSK15_TXERRM									(0x1u<<7)
#define	OTG_HCINTMSK15_NYET										(0x1u<<6)
#define	OTG_HCINTMSK15_ACKM										(0x1u<<5)
#define	OTG_HCINTMSK15_NAKM										(0x1u<<4)
#define	OTG_HCINTMSK15_STALLM									(0x1u<<3)
#define	OTG_HCINTMSK15_AHBERRM									(0x1u<<2)
#define	OTG_HCINTMSK15_CHHM										(0x1u<<1)
#define	OTG_HCINTMSK15_XFRCM									(0x1u<<0)

#define	OTG_HCINTMSK15_DTERRM_B_0X0								(0x0u<<10)
#define	OTG_HCINTMSK15_DTERRM_B_0X1								(0x1u<<10)
#define	OTG_HCINTMSK15_FRMORM_B_0X0								(0x0u<<9)
#define	OTG_HCINTMSK15_FRMORM_B_0X1								(0x1u<<9)
#define	OTG_HCINTMSK15_BBERRM_B_0X0								(0x0u<<8)
#define	OTG_HCINTMSK15_BBERRM_B_0X1								(0x1u<<8)
#define	OTG_HCINTMSK15_TXERRM_B_0X0								(0x0u<<7)
#define	OTG_HCINTMSK15_TXERRM_B_0X1								(0x1u<<7)
#define	OTG_HCINTMSK15_NYET_B_0X0								(0x0u<<6)
#define	OTG_HCINTMSK15_NYET_B_0X1								(0x1u<<6)
#define	OTG_HCINTMSK15_ACKM_B_0X0								(0x0u<<5)
#define	OTG_HCINTMSK15_ACKM_B_0X1								(0x1u<<5)
#define	OTG_HCINTMSK15_NAKM_B_0X0								(0x0u<<4)
#define	OTG_HCINTMSK15_NAKM_B_0X1								(0x1u<<4)
#define	OTG_HCINTMSK15_STALLM_B_0X0								(0x0u<<3)
#define	OTG_HCINTMSK15_STALLM_B_0X1								(0x1u<<3)
#define	OTG_HCINTMSK15_AHBERRM_B_0X0							(0x0u<<2)
#define	OTG_HCINTMSK15_AHBERRM_B_0X1							(0x1u<<2)
#define	OTG_HCINTMSK15_CHHM_B_0X0								(0x0u<<1)
#define	OTG_HCINTMSK15_CHHM_B_0X1								(0x1u<<1)
#define	OTG_HCINTMSK15_XFRCM_B_0X0								(0x0u<<0)
#define	OTG_HCINTMSK15_XFRCM_B_0X1								(0x1u<<0)

// HCTSIZ15 Configuration

#define	OTG_HCTSIZ15_DOPNG										(0x1u<<31)
#define	OTG_HCTSIZ15_DPID										(0x3u<<29)
#define	OTG_HCTSIZ15_DPID_0										(0x1u<<29)
#define	OTG_HCTSIZ15_PKTCNT										(0x3FFu<<19)
#define	OTG_HCTSIZ15_PKTCNT_0									(0x1u<<19)
#define	OTG_HCTSIZ15_XFRSIZ										(0x7FFFFu<<0)
#define	OTG_HCTSIZ15_XFRSIZ_0									(0x1u<<0)

#define	OTG_HCTSIZ15_DPID_B_0X0									(0x0u<<29)
#define	OTG_HCTSIZ15_DPID_B_0X1									(0x1u<<29)
#define	OTG_HCTSIZ15_DPID_B_0X2									(0x2u<<29)
#define	OTG_HCTSIZ15_DPID_B_0X3									(0x3u<<29)

// HCDMA15 Configuration

#define	OTG_HCDMA15_DMAADDR										(0xFFFFFFFFu<<0)
#define	OTG_HCDMA15_DMAADDR_0									(0x1u<<0)

// DCFG Configuration

#define	OTG_DCFG_PERSCHIVL										(0x3u<<24)
#define	OTG_DCFG_PERSCHIVL_0									(0x1u<<24)
#define	OTG_DCFG_ERRATIM										(0x1u<<15)
#define	OTG_DCFG_PFIVL											(0x3u<<11)
#define	OTG_DCFG_PFIVL_0										(0x1u<<11)
#define	OTG_DCFG_DAD											(0x7Fu<<4)
#define	OTG_DCFG_DAD_0											(0x1u<<4)
#define	OTG_DCFG_NZLSOHSK										(0x1u<<2)
#define	OTG_DCFG_DSPD											(0x3u<<0)
#define	OTG_DCFG_DSPD_0											(0x1u<<0)

#define	OTG_DCFG_PERSCHIVL_B_0X0								(0x0u<<24)
#define	OTG_DCFG_PERSCHIVL_B_0X1								(0x1u<<24)
#define	OTG_DCFG_PERSCHIVL_B_0X2								(0x2u<<24)
#define	OTG_DCFG_ERRATIM_B_0X1									(0x1u<<15)
#define	OTG_DCFG_ERRATIM_B_0X0									(0x0u<<15)
#define	OTG_DCFG_PFIVL_B_0X0									(0x0u<<11)
#define	OTG_DCFG_PFIVL_B_0X1									(0x1u<<11)
#define	OTG_DCFG_PFIVL_B_0X2									(0x2u<<11)
#define	OTG_DCFG_PFIVL_B_0X3									(0x3u<<11)
#define	OTG_DCFG_NZLSOHSK_B_0X1									(0x1u<<2)
#define	OTG_DCFG_NZLSOHSK_B_0X0									(0x0u<<2)
#define	OTG_DCFG_DSPD_B_0X0										(0x0u<<0)
#define	OTG_DCFG_DSPD_B_0X1										(0x1u<<0)

// DCTL Configuration

#define	OTG_DCTL_DSBESLRJCT										(0x1u<<18)
#define	OTG_DCTL_POPRGDNE										(0x1u<<11)
#define	OTG_DCTL_CGONAK											(0x1u<<10)
#define	OTG_DCTL_SGONAK											(0x1u<<9)
#define	OTG_DCTL_CGINAK											(0x1u<<8)
#define	OTG_DCTL_SGINAK											(0x1u<<7)
#define	OTG_DCTL_TCTL											(0x7u<<4)
#define	OTG_DCTL_TCTL_0											(0x1u<<4)
#define	OTG_DCTL_GONSTS											(0x1u<<3)
#define	OTG_DCTL_GINSTS											(0x1u<<2)
#define	OTG_DCTL_SDIS											(0x1u<<1)
#define	OTG_DCTL_RWUSIG											(0x1u<<0)

#define	OTG_DCTL_TCTL_B_0X0										(0x0u<<4)
#define	OTG_DCTL_TCTL_B_0X1										(0x1u<<4)
#define	OTG_DCTL_TCTL_B_0X2										(0x2u<<4)
#define	OTG_DCTL_TCTL_B_0X3										(0x3u<<4)
#define	OTG_DCTL_TCTL_B_0X4										(0x4u<<4)
#define	OTG_DCTL_TCTL_B_0X5										(0x5u<<4)
#define	OTG_DCTL_GONSTS_B_0X0									(0x0u<<3)
#define	OTG_DCTL_GONSTS_B_0X1									(0x1u<<3)
#define	OTG_DCTL_GINSTS_B_0X0									(0x0u<<2)
#define	OTG_DCTL_GINSTS_B_0X1									(0x1u<<2)
#define	OTG_DCTL_SDIS_B_0X0										(0x0u<<1)
#define	OTG_DCTL_SDIS_B_0X1										(0x1u<<1)

// DSTS Configuration

#define	OTG_DSTS_DEVLNSTS										(0x3u<<22)
#define	OTG_DSTS_DEVLNSTS_0										(0x1u<<22)
#define	OTG_DSTS_FNSOF											(0x3FFFu<<8)
#define	OTG_DSTS_FNSOF_0										(0x1u<<8)
#define	OTG_DSTS_EERR											(0x1u<<3)
#define	OTG_DSTS_ENUMSPD										(0x3u<<1)
#define	OTG_DSTS_ENUMSPD_0										(0x1u<<1)
#define	OTG_DSTS_SUSPSTS										(0x1u<<0)

#define	OTG_DSTS_ENUMSPD_B_0X0									(0x0u<<1)
#define	OTG_DSTS_ENUMSPD_B_0X1									(0x1u<<1)

// DIEPMSK Configuration

#define	OTG_DIEPMSK_NAKM										(0x1u<<13)
#define	OTG_DIEPMSK_TXFURM										(0x1u<<8)
#define	OTG_DIEPMSK_INEPNEM										(0x1u<<6)
#define	OTG_DIEPMSK_INEPNMM										(0x1u<<5)
#define	OTG_DIEPMSK_ITTXFEMSK									(0x1u<<4)
#define	OTG_DIEPMSK_TOM											(0x1u<<3)
#define	OTG_DIEPMSK_AHBERRM										(0x1u<<2)
#define	OTG_DIEPMSK_EPDM										(0x1u<<1)
#define	OTG_DIEPMSK_XFRCM										(0x1u<<0)

#define	OTG_DIEPMSK_NAKM_B_0X0									(0x0u<<13)
#define	OTG_DIEPMSK_NAKM_B_0X1									(0x1u<<13)
#define	OTG_DIEPMSK_TXFURM_B_0X0								(0x0u<<8)
#define	OTG_DIEPMSK_TXFURM_B_0X1								(0x1u<<8)
#define	OTG_DIEPMSK_INEPNEM_B_0X0								(0x0u<<6)
#define	OTG_DIEPMSK_INEPNEM_B_0X1								(0x1u<<6)
#define	OTG_DIEPMSK_INEPNMM_B_0X0								(0x0u<<5)
#define	OTG_DIEPMSK_INEPNMM_B_0X1								(0x1u<<5)
#define	OTG_DIEPMSK_ITTXFEMSK_B_0X0								(0x0u<<4)
#define	OTG_DIEPMSK_ITTXFEMSK_B_0X1								(0x1u<<4)
#define	OTG_DIEPMSK_TOM_B_0X0									(0x0u<<3)
#define	OTG_DIEPMSK_TOM_B_0X1									(0x1u<<3)
#define	OTG_DIEPMSK_AHBERRM_B_0X0								(0x0u<<2)
#define	OTG_DIEPMSK_AHBERRM_B_0X1								(0x1u<<2)
#define	OTG_DIEPMSK_EPDM_B_0X0									(0x0u<<1)
#define	OTG_DIEPMSK_EPDM_B_0X1									(0x1u<<1)
#define	OTG_DIEPMSK_XFRCM_B_0X0									(0x0u<<0)
#define	OTG_DIEPMSK_XFRCM_B_0X1									(0x1u<<0)

// DOEPMSK Configuration

#define	OTG_DOEPMSK_NYETMSK										(0x1u<<14)
#define	OTG_DOEPMSK_NAKMSK										(0x1u<<13)
#define	OTG_DOEPMSK_BERRM										(0x1u<<12)
#define	OTG_DOEPMSK_OUTPKTERRM									(0x1u<<8)
#define	OTG_DOEPMSK_B2BSTUPM									(0x1u<<6)
#define	OTG_DOEPMSK_STSPHSRXM									(0x1u<<5)
#define	OTG_DOEPMSK_OTEPDM										(0x1u<<4)
#define	OTG_DOEPMSK_STUPM										(0x1u<<3)
#define	OTG_DOEPMSK_AHBERRM										(0x1u<<2)
#define	OTG_DOEPMSK_EPDM										(0x1u<<1)
#define	OTG_DOEPMSK_XFRCM										(0x1u<<0)

#define	OTG_DOEPMSK_NYETMSK_B_0X0								(0x0u<<14)
#define	OTG_DOEPMSK_NYETMSK_B_0X1								(0x1u<<14)
#define	OTG_DOEPMSK_NAKMSK_B_0X0								(0x0u<<13)
#define	OTG_DOEPMSK_NAKMSK_B_0X1								(0x1u<<13)
#define	OTG_DOEPMSK_BERRM_B_0X0									(0x0u<<12)
#define	OTG_DOEPMSK_BERRM_B_0X1									(0x1u<<12)
#define	OTG_DOEPMSK_OUTPKTERRM_B_0X0							(0x0u<<8)
#define	OTG_DOEPMSK_OUTPKTERRM_B_0X1							(0x1u<<8)
#define	OTG_DOEPMSK_B2BSTUPM_B_0X0								(0x0u<<6)
#define	OTG_DOEPMSK_B2BSTUPM_B_0X1								(0x1u<<6)
#define	OTG_DOEPMSK_STSPHSRXM_B_0X0								(0x0u<<5)
#define	OTG_DOEPMSK_STSPHSRXM_B_0X1								(0x1u<<5)
#define	OTG_DOEPMSK_OTEPDM_B_0X0								(0x0u<<4)
#define	OTG_DOEPMSK_OTEPDM_B_0X1								(0x1u<<4)
#define	OTG_DOEPMSK_STUPM_B_0X0									(0x0u<<3)
#define	OTG_DOEPMSK_STUPM_B_0X1									(0x1u<<3)
#define	OTG_DOEPMSK_AHBERRM_B_0X0								(0x0u<<2)
#define	OTG_DOEPMSK_AHBERRM_B_0X1								(0x1u<<2)
#define	OTG_DOEPMSK_EPDM_B_0X0									(0x0u<<1)
#define	OTG_DOEPMSK_EPDM_B_0X1									(0x1u<<1)
#define	OTG_DOEPMSK_XFRCM_B_0X0									(0x0u<<0)
#define	OTG_DOEPMSK_XFRCM_B_0X1									(0x1u<<0)

// DAINT Configuration

#define	OTG_DAINT_OEPINT										(0xFFFFu<<16)
#define	OTG_DAINT_OEPINT_0										(0x1u<<16)
#define	OTG_DAINT_IEPINT										(0xFFFFu<<0)
#define	OTG_DAINT_IEPINT_0										(0x1u<<0)

// DAINTMSK Configuration

#define	OTG_DAINTMSK_OEPM										(0xFFFFu<<16)
#define	OTG_DAINTMSK_OEPM_0										(0x1u<<16)
#define	OTG_DAINTMSK_IEPM										(0xFFFFu<<0)
#define	OTG_DAINTMSK_IEPM_0										(0x1u<<0)

#define	OTG_DAINTMSK_OEPM_B_0X0									(0x0u<<16)
#define	OTG_DAINTMSK_OEPM_B_0X1									(0x1u<<16)
#define	OTG_DAINTMSK_IEPM_B_0X0									(0x0u<<0)
#define	OTG_DAINTMSK_IEPM_B_0X1									(0x1u<<0)

// DTHRCTL Configuration

#define	OTG_DTHRCTL_ARPEN										(0x1u<<27)
#define	OTG_DTHRCTL_RXTHRLEN									(0x1FFu<<17)
#define	OTG_DTHRCTL_RXTHRLEN_0									(0x1u<<17)
#define	OTG_DTHRCTL_RXTHREN										(0x1u<<16)
#define	OTG_DTHRCTL_TXTHRLEN									(0x1FFu<<2)
#define	OTG_DTHRCTL_TXTHRLEN_0									(0x1u<<2)
#define	OTG_DTHRCTL_ISOTHREN									(0x1u<<1)
#define	OTG_DTHRCTL_NONISOTHREN									(0x1u<<0)

// DIEPEMPMSK Configuration

#define	OTG_DIEPEMPMSK_INEPTXFEM								(0xFFFFu<<0)
#define	OTG_DIEPEMPMSK_INEPTXFEM_0								(0x1u<<0)

#define	OTG_DIEPEMPMSK_INEPTXFEM_B_0X0							(0x0u<<0)
#define	OTG_DIEPEMPMSK_INEPTXFEM_B_0X1							(0x1u<<0)

// DIEPCTL0 Configuration

#define	OTG_DIEPCTL0_EPENA										(0x1u<<31)
#define	OTG_DIEPCTL0_EPDIS										(0x1u<<30)
#define	OTG_DIEPCTL0_SD1PID										(0x1u<<29)
#define	OTG_DIEPCTL0_SD0PID										(0x1u<<28)
#define	OTG_DIEPCTL0_SNAK										(0x1u<<27)
#define	OTG_DIEPCTL0_CNAK										(0x1u<<26)
#define	OTG_DIEPCTL0_TXFNUM										(0xFu<<22)
#define	OTG_DIEPCTL0_TXFNUM_0									(0x1u<<22)
#define	OTG_DIEPCTL0_STALL										(0x1u<<21)
#define	OTG_DIEPCTL0_EPTYP										(0x3u<<18)
#define	OTG_DIEPCTL0_EPTYP_0									(0x1u<<18)
#define	OTG_DIEPCTL0_NAKSTS										(0x1u<<17)
#define	OTG_DIEPCTL0_DPID										(0x1u<<16)
#define	OTG_DIEPCTL0_USBAEP										(0x1u<<15)
#define	OTG_DIEPCTL0_MPSIZ										(0x7FFu<<0)
#define	OTG_DIEPCTL0_MPSIZ_0									(0x1u<<0)

#define	OTG_DIEPCTL0_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DIEPCTL0_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DIEPCTL0_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DIEPCTL0_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DIEPCTL0_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DIEPCTL0_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DIEPCTL0_DPID_B_0X0									(0x0u<<16)
#define	OTG_DIEPCTL0_DPID_B_0X1									(0x1u<<16)

// DIEPCTL0_ALTERNATE Configuration

#define	OTG_DIEPCTL0_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DIEPCTL0_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DIEPCTL0_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DIEPCTL0_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DIEPCTL0_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DIEPCTL0_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DIEPCTL0_ALTERNATE_TXFNUM							(0xFu<<22)
#define	OTG_DIEPCTL0_ALTERNATE_TXFNUM_0							(0x1u<<22)
#define	OTG_DIEPCTL0_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DIEPCTL0_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DIEPCTL0_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DIEPCTL0_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DIEPCTL0_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DIEPCTL0_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DIEPCTL0_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DIEPCTL0_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DIEPCTL0_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DIEPCTL0_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DIEPCTL0_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DIEPCTL0_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DIEPCTL0_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DIEPCTL0_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DIEPCTL0_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DIEPCTL0_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DIEPINT0 Configuration

#define	OTG_DIEPINT0_NAK										(0x1u<<13)
#define	OTG_DIEPINT0_PKTDRPSTS									(0x1u<<11)
#define	OTG_DIEPINT0_TXFIFOUDRN									(0x1u<<8)
#define	OTG_DIEPINT0_TXFE										(0x1u<<7)
#define	OTG_DIEPINT0_INEPNE										(0x1u<<6)
#define	OTG_DIEPINT0_INEPNM										(0x1u<<5)
#define	OTG_DIEPINT0_ITTXFE										(0x1u<<4)
#define	OTG_DIEPINT0_TOC										(0x1u<<3)
#define	OTG_DIEPINT0_AHBERR										(0x1u<<2)
#define	OTG_DIEPINT0_EPDISD										(0x1u<<1)
#define	OTG_DIEPINT0_XFRC										(0x1u<<0)

// DIEPTSIZ0 Configuration

#define	OTG_DIEPTSIZ0_PKTCNT									(0x3u<<19)
#define	OTG_DIEPTSIZ0_PKTCNT_0									(0x1u<<19)
#define	OTG_DIEPTSIZ0_XFRSIZ									(0x7Fu<<0)
#define	OTG_DIEPTSIZ0_XFRSIZ_0									(0x1u<<0)

// DIEPDMA0 Configuration

#define	OTG_DIEPDMA0_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DIEPDMA0_DMAADDR_0									(0x1u<<0)

// DTXFSTS0 Configuration

#define	OTG_DTXFSTS0_INEPTFSAV									(0xFFFFu<<0)
#define	OTG_DTXFSTS0_INEPTFSAV_0								(0x1u<<0)

#define	OTG_DTXFSTS0_INEPTFSAV_B_0X0							(0x0u<<0)
#define	OTG_DTXFSTS0_INEPTFSAV_B_0X1							(0x1u<<0)
#define	OTG_DTXFSTS0_INEPTFSAV_B_0X2							(0x2u<<0)

// DIEPCTL1 Configuration

#define	OTG_DIEPCTL1_EPENA										(0x1u<<31)
#define	OTG_DIEPCTL1_EPDIS										(0x1u<<30)
#define	OTG_DIEPCTL1_SD1PID										(0x1u<<29)
#define	OTG_DIEPCTL1_SD0PID										(0x1u<<28)
#define	OTG_DIEPCTL1_SNAK										(0x1u<<27)
#define	OTG_DIEPCTL1_CNAK										(0x1u<<26)
#define	OTG_DIEPCTL1_TXFNUM										(0xFu<<22)
#define	OTG_DIEPCTL1_TXFNUM_0									(0x1u<<22)
#define	OTG_DIEPCTL1_STALL										(0x1u<<21)
#define	OTG_DIEPCTL1_EPTYP										(0x3u<<18)
#define	OTG_DIEPCTL1_EPTYP_0									(0x1u<<18)
#define	OTG_DIEPCTL1_NAKSTS										(0x1u<<17)
#define	OTG_DIEPCTL1_DPID										(0x1u<<16)
#define	OTG_DIEPCTL1_USBAEP										(0x1u<<15)
#define	OTG_DIEPCTL1_MPSIZ										(0x7FFu<<0)
#define	OTG_DIEPCTL1_MPSIZ_0									(0x1u<<0)

#define	OTG_DIEPCTL1_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DIEPCTL1_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DIEPCTL1_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DIEPCTL1_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DIEPCTL1_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DIEPCTL1_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DIEPCTL1_DPID_B_0X0									(0x0u<<16)
#define	OTG_DIEPCTL1_DPID_B_0X1									(0x1u<<16)

// DIEPCTL1_ALTERNATE Configuration

#define	OTG_DIEPCTL1_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DIEPCTL1_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DIEPCTL1_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DIEPCTL1_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DIEPCTL1_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DIEPCTL1_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DIEPCTL1_ALTERNATE_TXFNUM							(0xFu<<22)
#define	OTG_DIEPCTL1_ALTERNATE_TXFNUM_0							(0x1u<<22)
#define	OTG_DIEPCTL1_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DIEPCTL1_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DIEPCTL1_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DIEPCTL1_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DIEPCTL1_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DIEPCTL1_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DIEPCTL1_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DIEPCTL1_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DIEPCTL1_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DIEPCTL1_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DIEPCTL1_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DIEPCTL1_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DIEPCTL1_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DIEPCTL1_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DIEPCTL1_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DIEPCTL1_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DIEPINT1 Configuration

#define	OTG_DIEPINT1_NAK										(0x1u<<13)
#define	OTG_DIEPINT1_PKTDRPSTS									(0x1u<<11)
#define	OTG_DIEPINT1_TXFIFOUDRN									(0x1u<<8)
#define	OTG_DIEPINT1_TXFE										(0x1u<<7)
#define	OTG_DIEPINT1_INEPNE										(0x1u<<6)
#define	OTG_DIEPINT1_INEPNM										(0x1u<<5)
#define	OTG_DIEPINT1_ITTXFE										(0x1u<<4)
#define	OTG_DIEPINT1_TOC										(0x1u<<3)
#define	OTG_DIEPINT1_AHBERR										(0x1u<<2)
#define	OTG_DIEPINT1_EPDISD										(0x1u<<1)
#define	OTG_DIEPINT1_XFRC										(0x1u<<0)

// DIEPTSIZ1 Configuration

#define	OTG_DIEPTSIZ1_MCNT										(0x3u<<29)
#define	OTG_DIEPTSIZ1_MCNT_0									(0x1u<<29)
#define	OTG_DIEPTSIZ1_PKTCNT									(0x3FFu<<19)
#define	OTG_DIEPTSIZ1_PKTCNT_0									(0x1u<<19)
#define	OTG_DIEPTSIZ1_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DIEPTSIZ1_XFRSIZ_0									(0x1u<<0)

#define	OTG_DIEPTSIZ1_MCNT_B_0X1								(0x1u<<29)
#define	OTG_DIEPTSIZ1_MCNT_B_0X2								(0x2u<<29)
#define	OTG_DIEPTSIZ1_MCNT_B_0X3								(0x3u<<29)

// DIEPDMA1 Configuration

#define	OTG_DIEPDMA1_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DIEPDMA1_DMAADDR_0									(0x1u<<0)

// DTXFSTS1 Configuration

#define	OTG_DTXFSTS1_INEPTFSAV									(0xFFFFu<<0)
#define	OTG_DTXFSTS1_INEPTFSAV_0								(0x1u<<0)

#define	OTG_DTXFSTS1_INEPTFSAV_B_0X0							(0x0u<<0)
#define	OTG_DTXFSTS1_INEPTFSAV_B_0X1							(0x1u<<0)
#define	OTG_DTXFSTS1_INEPTFSAV_B_0X2							(0x2u<<0)

// DIEPCTL2 Configuration

#define	OTG_DIEPCTL2_EPENA										(0x1u<<31)
#define	OTG_DIEPCTL2_EPDIS										(0x1u<<30)
#define	OTG_DIEPCTL2_SD1PID										(0x1u<<29)
#define	OTG_DIEPCTL2_SD0PID										(0x1u<<28)
#define	OTG_DIEPCTL2_SNAK										(0x1u<<27)
#define	OTG_DIEPCTL2_CNAK										(0x1u<<26)
#define	OTG_DIEPCTL2_TXFNUM										(0xFu<<22)
#define	OTG_DIEPCTL2_TXFNUM_0									(0x1u<<22)
#define	OTG_DIEPCTL2_STALL										(0x1u<<21)
#define	OTG_DIEPCTL2_EPTYP										(0x3u<<18)
#define	OTG_DIEPCTL2_EPTYP_0									(0x1u<<18)
#define	OTG_DIEPCTL2_NAKSTS										(0x1u<<17)
#define	OTG_DIEPCTL2_DPID										(0x1u<<16)
#define	OTG_DIEPCTL2_USBAEP										(0x1u<<15)
#define	OTG_DIEPCTL2_MPSIZ										(0x7FFu<<0)
#define	OTG_DIEPCTL2_MPSIZ_0									(0x1u<<0)

#define	OTG_DIEPCTL2_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DIEPCTL2_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DIEPCTL2_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DIEPCTL2_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DIEPCTL2_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DIEPCTL2_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DIEPCTL2_DPID_B_0X0									(0x0u<<16)
#define	OTG_DIEPCTL2_DPID_B_0X1									(0x1u<<16)

// DIEPCTL2_ALTERNATE Configuration

#define	OTG_DIEPCTL2_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DIEPCTL2_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DIEPCTL2_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DIEPCTL2_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DIEPCTL2_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DIEPCTL2_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DIEPCTL2_ALTERNATE_TXFNUM							(0xFu<<22)
#define	OTG_DIEPCTL2_ALTERNATE_TXFNUM_0							(0x1u<<22)
#define	OTG_DIEPCTL2_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DIEPCTL2_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DIEPCTL2_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DIEPCTL2_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DIEPCTL2_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DIEPCTL2_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DIEPCTL2_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DIEPCTL2_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DIEPCTL2_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DIEPCTL2_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DIEPCTL2_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DIEPCTL2_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DIEPCTL2_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DIEPCTL2_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DIEPCTL2_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DIEPCTL2_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DIEPINT2 Configuration

#define	OTG_DIEPINT2_NAK										(0x1u<<13)
#define	OTG_DIEPINT2_PKTDRPSTS									(0x1u<<11)
#define	OTG_DIEPINT2_TXFIFOUDRN									(0x1u<<8)
#define	OTG_DIEPINT2_TXFE										(0x1u<<7)
#define	OTG_DIEPINT2_INEPNE										(0x1u<<6)
#define	OTG_DIEPINT2_INEPNM										(0x1u<<5)
#define	OTG_DIEPINT2_ITTXFE										(0x1u<<4)
#define	OTG_DIEPINT2_TOC										(0x1u<<3)
#define	OTG_DIEPINT2_AHBERR										(0x1u<<2)
#define	OTG_DIEPINT2_EPDISD										(0x1u<<1)
#define	OTG_DIEPINT2_XFRC										(0x1u<<0)

// DIEPTSIZ2 Configuration

#define	OTG_DIEPTSIZ2_MCNT										(0x3u<<29)
#define	OTG_DIEPTSIZ2_MCNT_0									(0x1u<<29)
#define	OTG_DIEPTSIZ2_PKTCNT									(0x3FFu<<19)
#define	OTG_DIEPTSIZ2_PKTCNT_0									(0x1u<<19)
#define	OTG_DIEPTSIZ2_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DIEPTSIZ2_XFRSIZ_0									(0x1u<<0)

#define	OTG_DIEPTSIZ2_MCNT_B_0X1								(0x1u<<29)
#define	OTG_DIEPTSIZ2_MCNT_B_0X2								(0x2u<<29)
#define	OTG_DIEPTSIZ2_MCNT_B_0X3								(0x3u<<29)

// DIEPDMA2 Configuration

#define	OTG_DIEPDMA2_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DIEPDMA2_DMAADDR_0									(0x1u<<0)

// DTXFSTS2 Configuration

#define	OTG_DTXFSTS2_INEPTFSAV									(0xFFFFu<<0)
#define	OTG_DTXFSTS2_INEPTFSAV_0								(0x1u<<0)

#define	OTG_DTXFSTS2_INEPTFSAV_B_0X0							(0x0u<<0)
#define	OTG_DTXFSTS2_INEPTFSAV_B_0X1							(0x1u<<0)
#define	OTG_DTXFSTS2_INEPTFSAV_B_0X2							(0x2u<<0)

// DIEPCTL3 Configuration

#define	OTG_DIEPCTL3_EPENA										(0x1u<<31)
#define	OTG_DIEPCTL3_EPDIS										(0x1u<<30)
#define	OTG_DIEPCTL3_SD1PID										(0x1u<<29)
#define	OTG_DIEPCTL3_SD0PID										(0x1u<<28)
#define	OTG_DIEPCTL3_SNAK										(0x1u<<27)
#define	OTG_DIEPCTL3_CNAK										(0x1u<<26)
#define	OTG_DIEPCTL3_TXFNUM										(0xFu<<22)
#define	OTG_DIEPCTL3_TXFNUM_0									(0x1u<<22)
#define	OTG_DIEPCTL3_STALL										(0x1u<<21)
#define	OTG_DIEPCTL3_EPTYP										(0x3u<<18)
#define	OTG_DIEPCTL3_EPTYP_0									(0x1u<<18)
#define	OTG_DIEPCTL3_NAKSTS										(0x1u<<17)
#define	OTG_DIEPCTL3_DPID										(0x1u<<16)
#define	OTG_DIEPCTL3_USBAEP										(0x1u<<15)
#define	OTG_DIEPCTL3_MPSIZ										(0x7FFu<<0)
#define	OTG_DIEPCTL3_MPSIZ_0									(0x1u<<0)

#define	OTG_DIEPCTL3_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DIEPCTL3_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DIEPCTL3_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DIEPCTL3_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DIEPCTL3_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DIEPCTL3_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DIEPCTL3_DPID_B_0X0									(0x0u<<16)
#define	OTG_DIEPCTL3_DPID_B_0X1									(0x1u<<16)

// DIEPCTL3_ALTERNATE Configuration

#define	OTG_DIEPCTL3_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DIEPCTL3_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DIEPCTL3_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DIEPCTL3_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DIEPCTL3_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DIEPCTL3_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DIEPCTL3_ALTERNATE_TXFNUM							(0xFu<<22)
#define	OTG_DIEPCTL3_ALTERNATE_TXFNUM_0							(0x1u<<22)
#define	OTG_DIEPCTL3_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DIEPCTL3_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DIEPCTL3_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DIEPCTL3_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DIEPCTL3_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DIEPCTL3_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DIEPCTL3_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DIEPCTL3_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DIEPCTL3_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DIEPCTL3_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DIEPCTL3_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DIEPCTL3_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DIEPCTL3_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DIEPCTL3_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DIEPCTL3_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DIEPCTL3_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DIEPINT3 Configuration

#define	OTG_DIEPINT3_NAK										(0x1u<<13)
#define	OTG_DIEPINT3_PKTDRPSTS									(0x1u<<11)
#define	OTG_DIEPINT3_TXFIFOUDRN									(0x1u<<8)
#define	OTG_DIEPINT3_TXFE										(0x1u<<7)
#define	OTG_DIEPINT3_INEPNE										(0x1u<<6)
#define	OTG_DIEPINT3_INEPNM										(0x1u<<5)
#define	OTG_DIEPINT3_ITTXFE										(0x1u<<4)
#define	OTG_DIEPINT3_TOC										(0x1u<<3)
#define	OTG_DIEPINT3_AHBERR										(0x1u<<2)
#define	OTG_DIEPINT3_EPDISD										(0x1u<<1)
#define	OTG_DIEPINT3_XFRC										(0x1u<<0)

// DIEPTSIZ3 Configuration

#define	OTG_DIEPTSIZ3_MCNT										(0x3u<<29)
#define	OTG_DIEPTSIZ3_MCNT_0									(0x1u<<29)
#define	OTG_DIEPTSIZ3_PKTCNT									(0x3FFu<<19)
#define	OTG_DIEPTSIZ3_PKTCNT_0									(0x1u<<19)
#define	OTG_DIEPTSIZ3_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DIEPTSIZ3_XFRSIZ_0									(0x1u<<0)

#define	OTG_DIEPTSIZ3_MCNT_B_0X1								(0x1u<<29)
#define	OTG_DIEPTSIZ3_MCNT_B_0X2								(0x2u<<29)
#define	OTG_DIEPTSIZ3_MCNT_B_0X3								(0x3u<<29)

// DIEPDMA3 Configuration

#define	OTG_DIEPDMA3_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DIEPDMA3_DMAADDR_0									(0x1u<<0)

// DTXFSTS3 Configuration

#define	OTG_DTXFSTS3_INEPTFSAV									(0xFFFFu<<0)
#define	OTG_DTXFSTS3_INEPTFSAV_0								(0x1u<<0)

#define	OTG_DTXFSTS3_INEPTFSAV_B_0X0							(0x0u<<0)
#define	OTG_DTXFSTS3_INEPTFSAV_B_0X1							(0x1u<<0)
#define	OTG_DTXFSTS3_INEPTFSAV_B_0X2							(0x2u<<0)

// DIEPCTL4 Configuration

#define	OTG_DIEPCTL4_EPENA										(0x1u<<31)
#define	OTG_DIEPCTL4_EPDIS										(0x1u<<30)
#define	OTG_DIEPCTL4_SD1PID										(0x1u<<29)
#define	OTG_DIEPCTL4_SD0PID										(0x1u<<28)
#define	OTG_DIEPCTL4_SNAK										(0x1u<<27)
#define	OTG_DIEPCTL4_CNAK										(0x1u<<26)
#define	OTG_DIEPCTL4_TXFNUM										(0xFu<<22)
#define	OTG_DIEPCTL4_TXFNUM_0									(0x1u<<22)
#define	OTG_DIEPCTL4_STALL										(0x1u<<21)
#define	OTG_DIEPCTL4_EPTYP										(0x3u<<18)
#define	OTG_DIEPCTL4_EPTYP_0									(0x1u<<18)
#define	OTG_DIEPCTL4_NAKSTS										(0x1u<<17)
#define	OTG_DIEPCTL4_DPID										(0x1u<<16)
#define	OTG_DIEPCTL4_USBAEP										(0x1u<<15)
#define	OTG_DIEPCTL4_MPSIZ										(0x7FFu<<0)
#define	OTG_DIEPCTL4_MPSIZ_0									(0x1u<<0)

#define	OTG_DIEPCTL4_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DIEPCTL4_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DIEPCTL4_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DIEPCTL4_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DIEPCTL4_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DIEPCTL4_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DIEPCTL4_DPID_B_0X0									(0x0u<<16)
#define	OTG_DIEPCTL4_DPID_B_0X1									(0x1u<<16)

// DIEPCTL4_ALTERNATE Configuration

#define	OTG_DIEPCTL4_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DIEPCTL4_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DIEPCTL4_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DIEPCTL4_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DIEPCTL4_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DIEPCTL4_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DIEPCTL4_ALTERNATE_TXFNUM							(0xFu<<22)
#define	OTG_DIEPCTL4_ALTERNATE_TXFNUM_0							(0x1u<<22)
#define	OTG_DIEPCTL4_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DIEPCTL4_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DIEPCTL4_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DIEPCTL4_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DIEPCTL4_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DIEPCTL4_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DIEPCTL4_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DIEPCTL4_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DIEPCTL4_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DIEPCTL4_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DIEPCTL4_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DIEPCTL4_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DIEPCTL4_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DIEPCTL4_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DIEPCTL4_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DIEPCTL4_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DIEPINT4 Configuration

#define	OTG_DIEPINT4_NAK										(0x1u<<13)
#define	OTG_DIEPINT4_PKTDRPSTS									(0x1u<<11)
#define	OTG_DIEPINT4_TXFIFOUDRN									(0x1u<<8)
#define	OTG_DIEPINT4_TXFE										(0x1u<<7)
#define	OTG_DIEPINT4_INEPNE										(0x1u<<6)
#define	OTG_DIEPINT4_INEPNM										(0x1u<<5)
#define	OTG_DIEPINT4_ITTXFE										(0x1u<<4)
#define	OTG_DIEPINT4_TOC										(0x1u<<3)
#define	OTG_DIEPINT4_AHBERR										(0x1u<<2)
#define	OTG_DIEPINT4_EPDISD										(0x1u<<1)
#define	OTG_DIEPINT4_XFRC										(0x1u<<0)

// DIEPTSIZ4 Configuration

#define	OTG_DIEPTSIZ4_MCNT										(0x3u<<29)
#define	OTG_DIEPTSIZ4_MCNT_0									(0x1u<<29)
#define	OTG_DIEPTSIZ4_PKTCNT									(0x3FFu<<19)
#define	OTG_DIEPTSIZ4_PKTCNT_0									(0x1u<<19)
#define	OTG_DIEPTSIZ4_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DIEPTSIZ4_XFRSIZ_0									(0x1u<<0)

#define	OTG_DIEPTSIZ4_MCNT_B_0X1								(0x1u<<29)
#define	OTG_DIEPTSIZ4_MCNT_B_0X2								(0x2u<<29)
#define	OTG_DIEPTSIZ4_MCNT_B_0X3								(0x3u<<29)

// DIEPDMA4 Configuration

#define	OTG_DIEPDMA4_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DIEPDMA4_DMAADDR_0									(0x1u<<0)

// DTXFSTS4 Configuration

#define	OTG_DTXFSTS4_INEPTFSAV									(0xFFFFu<<0)
#define	OTG_DTXFSTS4_INEPTFSAV_0								(0x1u<<0)

#define	OTG_DTXFSTS4_INEPTFSAV_B_0X0							(0x0u<<0)
#define	OTG_DTXFSTS4_INEPTFSAV_B_0X1							(0x1u<<0)
#define	OTG_DTXFSTS4_INEPTFSAV_B_0X2							(0x2u<<0)

// DIEPCTL5 Configuration

#define	OTG_DIEPCTL5_EPENA										(0x1u<<31)
#define	OTG_DIEPCTL5_EPDIS										(0x1u<<30)
#define	OTG_DIEPCTL5_SD1PID										(0x1u<<29)
#define	OTG_DIEPCTL5_SD0PID										(0x1u<<28)
#define	OTG_DIEPCTL5_SNAK										(0x1u<<27)
#define	OTG_DIEPCTL5_CNAK										(0x1u<<26)
#define	OTG_DIEPCTL5_TXFNUM										(0xFu<<22)
#define	OTG_DIEPCTL5_TXFNUM_0									(0x1u<<22)
#define	OTG_DIEPCTL5_STALL										(0x1u<<21)
#define	OTG_DIEPCTL5_EPTYP										(0x3u<<18)
#define	OTG_DIEPCTL5_EPTYP_0									(0x1u<<18)
#define	OTG_DIEPCTL5_NAKSTS										(0x1u<<17)
#define	OTG_DIEPCTL5_DPID										(0x1u<<16)
#define	OTG_DIEPCTL5_USBAEP										(0x1u<<15)
#define	OTG_DIEPCTL5_MPSIZ										(0x7FFu<<0)
#define	OTG_DIEPCTL5_MPSIZ_0									(0x1u<<0)

#define	OTG_DIEPCTL5_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DIEPCTL5_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DIEPCTL5_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DIEPCTL5_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DIEPCTL5_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DIEPCTL5_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DIEPCTL5_DPID_B_0X0									(0x0u<<16)
#define	OTG_DIEPCTL5_DPID_B_0X1									(0x1u<<16)

// DIEPCTL5_ALTERNATE Configuration

#define	OTG_DIEPCTL5_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DIEPCTL5_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DIEPCTL5_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DIEPCTL5_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DIEPCTL5_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DIEPCTL5_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DIEPCTL5_ALTERNATE_TXFNUM							(0xFu<<22)
#define	OTG_DIEPCTL5_ALTERNATE_TXFNUM_0							(0x1u<<22)
#define	OTG_DIEPCTL5_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DIEPCTL5_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DIEPCTL5_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DIEPCTL5_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DIEPCTL5_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DIEPCTL5_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DIEPCTL5_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DIEPCTL5_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DIEPCTL5_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DIEPCTL5_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DIEPCTL5_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DIEPCTL5_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DIEPCTL5_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DIEPCTL5_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DIEPCTL5_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DIEPCTL5_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DIEPINT5 Configuration

#define	OTG_DIEPINT5_NAK										(0x1u<<13)
#define	OTG_DIEPINT5_PKTDRPSTS									(0x1u<<11)
#define	OTG_DIEPINT5_TXFIFOUDRN									(0x1u<<8)
#define	OTG_DIEPINT5_TXFE										(0x1u<<7)
#define	OTG_DIEPINT5_INEPNE										(0x1u<<6)
#define	OTG_DIEPINT5_INEPNM										(0x1u<<5)
#define	OTG_DIEPINT5_ITTXFE										(0x1u<<4)
#define	OTG_DIEPINT5_TOC										(0x1u<<3)
#define	OTG_DIEPINT5_AHBERR										(0x1u<<2)
#define	OTG_DIEPINT5_EPDISD										(0x1u<<1)
#define	OTG_DIEPINT5_XFRC										(0x1u<<0)

// DIEPTSIZ5 Configuration

#define	OTG_DIEPTSIZ5_MCNT										(0x3u<<29)
#define	OTG_DIEPTSIZ5_MCNT_0									(0x1u<<29)
#define	OTG_DIEPTSIZ5_PKTCNT									(0x3FFu<<19)
#define	OTG_DIEPTSIZ5_PKTCNT_0									(0x1u<<19)
#define	OTG_DIEPTSIZ5_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DIEPTSIZ5_XFRSIZ_0									(0x1u<<0)

#define	OTG_DIEPTSIZ5_MCNT_B_0X1								(0x1u<<29)
#define	OTG_DIEPTSIZ5_MCNT_B_0X2								(0x2u<<29)
#define	OTG_DIEPTSIZ5_MCNT_B_0X3								(0x3u<<29)

// DIEPDMA5 Configuration

#define	OTG_DIEPDMA5_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DIEPDMA5_DMAADDR_0									(0x1u<<0)

// DTXFSTS5 Configuration

#define	OTG_DTXFSTS5_INEPTFSAV									(0xFFFFu<<0)
#define	OTG_DTXFSTS5_INEPTFSAV_0								(0x1u<<0)

#define	OTG_DTXFSTS5_INEPTFSAV_B_0X0							(0x0u<<0)
#define	OTG_DTXFSTS5_INEPTFSAV_B_0X1							(0x1u<<0)
#define	OTG_DTXFSTS5_INEPTFSAV_B_0X2							(0x2u<<0)

// DIEPCTL6 Configuration

#define	OTG_DIEPCTL6_EPENA										(0x1u<<31)
#define	OTG_DIEPCTL6_EPDIS										(0x1u<<30)
#define	OTG_DIEPCTL6_SD1PID										(0x1u<<29)
#define	OTG_DIEPCTL6_SD0PID										(0x1u<<28)
#define	OTG_DIEPCTL6_SNAK										(0x1u<<27)
#define	OTG_DIEPCTL6_CNAK										(0x1u<<26)
#define	OTG_DIEPCTL6_TXFNUM										(0xFu<<22)
#define	OTG_DIEPCTL6_TXFNUM_0									(0x1u<<22)
#define	OTG_DIEPCTL6_STALL										(0x1u<<21)
#define	OTG_DIEPCTL6_EPTYP										(0x3u<<18)
#define	OTG_DIEPCTL6_EPTYP_0									(0x1u<<18)
#define	OTG_DIEPCTL6_NAKSTS										(0x1u<<17)
#define	OTG_DIEPCTL6_DPID										(0x1u<<16)
#define	OTG_DIEPCTL6_USBAEP										(0x1u<<15)
#define	OTG_DIEPCTL6_MPSIZ										(0x7FFu<<0)
#define	OTG_DIEPCTL6_MPSIZ_0									(0x1u<<0)

#define	OTG_DIEPCTL6_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DIEPCTL6_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DIEPCTL6_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DIEPCTL6_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DIEPCTL6_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DIEPCTL6_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DIEPCTL6_DPID_B_0X0									(0x0u<<16)
#define	OTG_DIEPCTL6_DPID_B_0X1									(0x1u<<16)

// DIEPCTL6_ALTERNATE Configuration

#define	OTG_DIEPCTL6_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DIEPCTL6_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DIEPCTL6_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DIEPCTL6_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DIEPCTL6_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DIEPCTL6_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DIEPCTL6_ALTERNATE_TXFNUM							(0xFu<<22)
#define	OTG_DIEPCTL6_ALTERNATE_TXFNUM_0							(0x1u<<22)
#define	OTG_DIEPCTL6_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DIEPCTL6_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DIEPCTL6_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DIEPCTL6_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DIEPCTL6_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DIEPCTL6_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DIEPCTL6_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DIEPCTL6_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DIEPCTL6_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DIEPCTL6_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DIEPCTL6_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DIEPCTL6_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DIEPCTL6_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DIEPCTL6_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DIEPCTL6_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DIEPCTL6_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DIEPINT6 Configuration

#define	OTG_DIEPINT6_NAK										(0x1u<<13)
#define	OTG_DIEPINT6_PKTDRPSTS									(0x1u<<11)
#define	OTG_DIEPINT6_TXFIFOUDRN									(0x1u<<8)
#define	OTG_DIEPINT6_TXFE										(0x1u<<7)
#define	OTG_DIEPINT6_INEPNE										(0x1u<<6)
#define	OTG_DIEPINT6_INEPNM										(0x1u<<5)
#define	OTG_DIEPINT6_ITTXFE										(0x1u<<4)
#define	OTG_DIEPINT6_TOC										(0x1u<<3)
#define	OTG_DIEPINT6_AHBERR										(0x1u<<2)
#define	OTG_DIEPINT6_EPDISD										(0x1u<<1)
#define	OTG_DIEPINT6_XFRC										(0x1u<<0)

// DIEPTSIZ6 Configuration

#define	OTG_DIEPTSIZ6_MCNT										(0x3u<<29)
#define	OTG_DIEPTSIZ6_MCNT_0									(0x1u<<29)
#define	OTG_DIEPTSIZ6_PKTCNT									(0x3FFu<<19)
#define	OTG_DIEPTSIZ6_PKTCNT_0									(0x1u<<19)
#define	OTG_DIEPTSIZ6_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DIEPTSIZ6_XFRSIZ_0									(0x1u<<0)

#define	OTG_DIEPTSIZ6_MCNT_B_0X1								(0x1u<<29)
#define	OTG_DIEPTSIZ6_MCNT_B_0X2								(0x2u<<29)
#define	OTG_DIEPTSIZ6_MCNT_B_0X3								(0x3u<<29)

// DIEPDMA6 Configuration

#define	OTG_DIEPDMA6_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DIEPDMA6_DMAADDR_0									(0x1u<<0)

// DTXFSTS6 Configuration

#define	OTG_DTXFSTS6_INEPTFSAV									(0xFFFFu<<0)
#define	OTG_DTXFSTS6_INEPTFSAV_0								(0x1u<<0)

#define	OTG_DTXFSTS6_INEPTFSAV_B_0X0							(0x0u<<0)
#define	OTG_DTXFSTS6_INEPTFSAV_B_0X1							(0x1u<<0)
#define	OTG_DTXFSTS6_INEPTFSAV_B_0X2							(0x2u<<0)

// DIEPCTL7 Configuration

#define	OTG_DIEPCTL7_EPENA										(0x1u<<31)
#define	OTG_DIEPCTL7_EPDIS										(0x1u<<30)
#define	OTG_DIEPCTL7_SD1PID										(0x1u<<29)
#define	OTG_DIEPCTL7_SD0PID										(0x1u<<28)
#define	OTG_DIEPCTL7_SNAK										(0x1u<<27)
#define	OTG_DIEPCTL7_CNAK										(0x1u<<26)
#define	OTG_DIEPCTL7_TXFNUM										(0xFu<<22)
#define	OTG_DIEPCTL7_TXFNUM_0									(0x1u<<22)
#define	OTG_DIEPCTL7_STALL										(0x1u<<21)
#define	OTG_DIEPCTL7_EPTYP										(0x3u<<18)
#define	OTG_DIEPCTL7_EPTYP_0									(0x1u<<18)
#define	OTG_DIEPCTL7_NAKSTS										(0x1u<<17)
#define	OTG_DIEPCTL7_DPID										(0x1u<<16)
#define	OTG_DIEPCTL7_USBAEP										(0x1u<<15)
#define	OTG_DIEPCTL7_MPSIZ										(0x7FFu<<0)
#define	OTG_DIEPCTL7_MPSIZ_0									(0x1u<<0)

#define	OTG_DIEPCTL7_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DIEPCTL7_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DIEPCTL7_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DIEPCTL7_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DIEPCTL7_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DIEPCTL7_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DIEPCTL7_DPID_B_0X0									(0x0u<<16)
#define	OTG_DIEPCTL7_DPID_B_0X1									(0x1u<<16)

// DIEPCTL7_ALTERNATE Configuration

#define	OTG_DIEPCTL7_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DIEPCTL7_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DIEPCTL7_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DIEPCTL7_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DIEPCTL7_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DIEPCTL7_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DIEPCTL7_ALTERNATE_TXFNUM							(0xFu<<22)
#define	OTG_DIEPCTL7_ALTERNATE_TXFNUM_0							(0x1u<<22)
#define	OTG_DIEPCTL7_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DIEPCTL7_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DIEPCTL7_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DIEPCTL7_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DIEPCTL7_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DIEPCTL7_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DIEPCTL7_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DIEPCTL7_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DIEPCTL7_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DIEPCTL7_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DIEPCTL7_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DIEPCTL7_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DIEPCTL7_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DIEPCTL7_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DIEPCTL7_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DIEPCTL7_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DIEPINT7 Configuration

#define	OTG_DIEPINT7_NAK										(0x1u<<13)
#define	OTG_DIEPINT7_PKTDRPSTS									(0x1u<<11)
#define	OTG_DIEPINT7_TXFIFOUDRN									(0x1u<<8)
#define	OTG_DIEPINT7_TXFE										(0x1u<<7)
#define	OTG_DIEPINT7_INEPNE										(0x1u<<6)
#define	OTG_DIEPINT7_INEPNM										(0x1u<<5)
#define	OTG_DIEPINT7_ITTXFE										(0x1u<<4)
#define	OTG_DIEPINT7_TOC										(0x1u<<3)
#define	OTG_DIEPINT7_AHBERR										(0x1u<<2)
#define	OTG_DIEPINT7_EPDISD										(0x1u<<1)
#define	OTG_DIEPINT7_XFRC										(0x1u<<0)

// DIEPTSIZ7 Configuration

#define	OTG_DIEPTSIZ7_MCNT										(0x3u<<29)
#define	OTG_DIEPTSIZ7_MCNT_0									(0x1u<<29)
#define	OTG_DIEPTSIZ7_PKTCNT									(0x3FFu<<19)
#define	OTG_DIEPTSIZ7_PKTCNT_0									(0x1u<<19)
#define	OTG_DIEPTSIZ7_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DIEPTSIZ7_XFRSIZ_0									(0x1u<<0)

#define	OTG_DIEPTSIZ7_MCNT_B_0X1								(0x1u<<29)
#define	OTG_DIEPTSIZ7_MCNT_B_0X2								(0x2u<<29)
#define	OTG_DIEPTSIZ7_MCNT_B_0X3								(0x3u<<29)

// DIEPDMA7 Configuration

#define	OTG_DIEPDMA7_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DIEPDMA7_DMAADDR_0									(0x1u<<0)

// DTXFSTS7 Configuration

#define	OTG_DTXFSTS7_INEPTFSAV									(0xFFFFu<<0)
#define	OTG_DTXFSTS7_INEPTFSAV_0								(0x1u<<0)

#define	OTG_DTXFSTS7_INEPTFSAV_B_0X0							(0x0u<<0)
#define	OTG_DTXFSTS7_INEPTFSAV_B_0X1							(0x1u<<0)
#define	OTG_DTXFSTS7_INEPTFSAV_B_0X2							(0x2u<<0)

// DIEPCTL8 Configuration

#define	OTG_DIEPCTL8_EPENA										(0x1u<<31)
#define	OTG_DIEPCTL8_EPDIS										(0x1u<<30)
#define	OTG_DIEPCTL8_SD1PID										(0x1u<<29)
#define	OTG_DIEPCTL8_SD0PID										(0x1u<<28)
#define	OTG_DIEPCTL8_SNAK										(0x1u<<27)
#define	OTG_DIEPCTL8_CNAK										(0x1u<<26)
#define	OTG_DIEPCTL8_TXFNUM										(0xFu<<22)
#define	OTG_DIEPCTL8_TXFNUM_0									(0x1u<<22)
#define	OTG_DIEPCTL8_STALL										(0x1u<<21)
#define	OTG_DIEPCTL8_EPTYP										(0x3u<<18)
#define	OTG_DIEPCTL8_EPTYP_0									(0x1u<<18)
#define	OTG_DIEPCTL8_NAKSTS										(0x1u<<17)
#define	OTG_DIEPCTL8_DPID										(0x1u<<16)
#define	OTG_DIEPCTL8_USBAEP										(0x1u<<15)
#define	OTG_DIEPCTL8_MPSIZ										(0x7FFu<<0)
#define	OTG_DIEPCTL8_MPSIZ_0									(0x1u<<0)

#define	OTG_DIEPCTL8_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DIEPCTL8_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DIEPCTL8_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DIEPCTL8_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DIEPCTL8_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DIEPCTL8_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DIEPCTL8_DPID_B_0X0									(0x0u<<16)
#define	OTG_DIEPCTL8_DPID_B_0X1									(0x1u<<16)

// DIEPCTL8_ALTERNATE Configuration

#define	OTG_DIEPCTL8_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DIEPCTL8_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DIEPCTL8_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DIEPCTL8_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DIEPCTL8_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DIEPCTL8_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DIEPCTL8_ALTERNATE_TXFNUM							(0xFu<<22)
#define	OTG_DIEPCTL8_ALTERNATE_TXFNUM_0							(0x1u<<22)
#define	OTG_DIEPCTL8_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DIEPCTL8_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DIEPCTL8_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DIEPCTL8_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DIEPCTL8_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DIEPCTL8_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DIEPCTL8_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DIEPCTL8_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DIEPCTL8_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DIEPCTL8_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DIEPCTL8_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DIEPCTL8_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DIEPCTL8_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DIEPCTL8_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DIEPCTL8_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DIEPCTL8_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DIEPINT8 Configuration

#define	OTG_DIEPINT8_NAK										(0x1u<<13)
#define	OTG_DIEPINT8_PKTDRPSTS									(0x1u<<11)
#define	OTG_DIEPINT8_TXFIFOUDRN									(0x1u<<8)
#define	OTG_DIEPINT8_TXFE										(0x1u<<7)
#define	OTG_DIEPINT8_INEPNE										(0x1u<<6)
#define	OTG_DIEPINT8_INEPNM										(0x1u<<5)
#define	OTG_DIEPINT8_ITTXFE										(0x1u<<4)
#define	OTG_DIEPINT8_TOC										(0x1u<<3)
#define	OTG_DIEPINT8_AHBERR										(0x1u<<2)
#define	OTG_DIEPINT8_EPDISD										(0x1u<<1)
#define	OTG_DIEPINT8_XFRC										(0x1u<<0)

// DIEPTSIZ8 Configuration

#define	OTG_DIEPTSIZ8_MCNT										(0x3u<<29)
#define	OTG_DIEPTSIZ8_MCNT_0									(0x1u<<29)
#define	OTG_DIEPTSIZ8_PKTCNT									(0x3FFu<<19)
#define	OTG_DIEPTSIZ8_PKTCNT_0									(0x1u<<19)
#define	OTG_DIEPTSIZ8_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DIEPTSIZ8_XFRSIZ_0									(0x1u<<0)

#define	OTG_DIEPTSIZ8_MCNT_B_0X1								(0x1u<<29)
#define	OTG_DIEPTSIZ8_MCNT_B_0X2								(0x2u<<29)
#define	OTG_DIEPTSIZ8_MCNT_B_0X3								(0x3u<<29)

// DIEPDMA8 Configuration

#define	OTG_DIEPDMA8_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DIEPDMA8_DMAADDR_0									(0x1u<<0)

// DTXFSTS8 Configuration

#define	OTG_DTXFSTS8_INEPTFSAV									(0xFFFFu<<0)
#define	OTG_DTXFSTS8_INEPTFSAV_0								(0x1u<<0)

#define	OTG_DTXFSTS8_INEPTFSAV_B_0X0							(0x0u<<0)
#define	OTG_DTXFSTS8_INEPTFSAV_B_0X1							(0x1u<<0)
#define	OTG_DTXFSTS8_INEPTFSAV_B_0X2							(0x2u<<0)

// DOEPCTL0 Configuration

#define	OTG_DOEPCTL0_EPENA										(0x1u<<31)
#define	OTG_DOEPCTL0_EPDIS										(0x1u<<30)
#define	OTG_DOEPCTL0_SNAK										(0x1u<<27)
#define	OTG_DOEPCTL0_CNAK										(0x1u<<26)
#define	OTG_DOEPCTL0_STALL										(0x1u<<21)
#define	OTG_DOEPCTL0_SNPM										(0x1u<<20)
#define	OTG_DOEPCTL0_EPTYP										(0x3u<<18)
#define	OTG_DOEPCTL0_EPTYP_0									(0x1u<<18)
#define	OTG_DOEPCTL0_NAKSTS										(0x1u<<17)
#define	OTG_DOEPCTL0_USBAEP										(0x1u<<15)
#define	OTG_DOEPCTL0_MPSIZ										(0x3u<<0)
#define	OTG_DOEPCTL0_MPSIZ_0									(0x1u<<0)

#define	OTG_DOEPCTL0_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DOEPCTL0_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DOEPCTL0_MPSIZ_B_0X0								(0x0u<<0)
#define	OTG_DOEPCTL0_MPSIZ_B_0X1								(0x1u<<0)
#define	OTG_DOEPCTL0_MPSIZ_B_0X2								(0x2u<<0)
#define	OTG_DOEPCTL0_MPSIZ_B_0X3								(0x3u<<0)

// DOEPINT0 Configuration

#define	OTG_DOEPINT0_STPKTRX									(0x1u<<15)
#define	OTG_DOEPINT0_NYET										(0x1u<<14)
#define	OTG_DOEPINT0_NAK										(0x1u<<13)
#define	OTG_DOEPINT0_BERR										(0x1u<<12)
#define	OTG_DOEPINT0_OUTPKTERR									(0x1u<<8)
#define	OTG_DOEPINT0_B2BSTUP									(0x1u<<6)
#define	OTG_DOEPINT0_STSPHSRX									(0x1u<<5)
#define	OTG_DOEPINT0_OTEPDIS									(0x1u<<4)
#define	OTG_DOEPINT0_STUP										(0x1u<<3)
#define	OTG_DOEPINT0_AHBERR										(0x1u<<2)
#define	OTG_DOEPINT0_EPDISD										(0x1u<<1)
#define	OTG_DOEPINT0_XFRC										(0x1u<<0)

// DOEPTSIZ0 Configuration

#define	OTG_DOEPTSIZ0_STUPCNT									(0x3u<<29)
#define	OTG_DOEPTSIZ0_STUPCNT_0									(0x1u<<29)
#define	OTG_DOEPTSIZ0_PKTCNT									(0x1u<<19)
#define	OTG_DOEPTSIZ0_XFRSIZ									(0x7Fu<<0)
#define	OTG_DOEPTSIZ0_XFRSIZ_0									(0x1u<<0)

#define	OTG_DOEPTSIZ0_STUPCNT_B_0X1								(0x1u<<29)
#define	OTG_DOEPTSIZ0_STUPCNT_B_0X2								(0x2u<<29)
#define	OTG_DOEPTSIZ0_STUPCNT_B_0X3								(0x3u<<29)

// DOEPDMA0 Configuration

#define	OTG_DOEPDMA0_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DOEPDMA0_DMAADDR_0									(0x1u<<0)

// DOEPCTL1 Configuration

#define	OTG_DOEPCTL1_EPENA										(0x1u<<31)
#define	OTG_DOEPCTL1_EPDIS										(0x1u<<30)
#define	OTG_DOEPCTL1_SD1PID										(0x1u<<29)
#define	OTG_DOEPCTL1_SD0PID										(0x1u<<28)
#define	OTG_DOEPCTL1_SNAK										(0x1u<<27)
#define	OTG_DOEPCTL1_CNAK										(0x1u<<26)
#define	OTG_DOEPCTL1_STALL										(0x1u<<21)
#define	OTG_DOEPCTL1_SNPM										(0x1u<<20)
#define	OTG_DOEPCTL1_EPTYP										(0x3u<<18)
#define	OTG_DOEPCTL1_EPTYP_0									(0x1u<<18)
#define	OTG_DOEPCTL1_NAKSTS										(0x1u<<17)
#define	OTG_DOEPCTL1_DPID										(0x1u<<16)
#define	OTG_DOEPCTL1_USBAEP										(0x1u<<15)
#define	OTG_DOEPCTL1_MPSIZ										(0x7FFu<<0)
#define	OTG_DOEPCTL1_MPSIZ_0									(0x1u<<0)

#define	OTG_DOEPCTL1_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DOEPCTL1_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DOEPCTL1_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DOEPCTL1_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DOEPCTL1_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DOEPCTL1_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DOEPCTL1_DPID_B_0X0									(0x0u<<16)
#define	OTG_DOEPCTL1_DPID_B_0X1									(0x1u<<16)

// DOEPCTL1_ALTERNATE Configuration

#define	OTG_DOEPCTL1_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DOEPCTL1_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DOEPCTL1_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DOEPCTL1_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DOEPCTL1_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DOEPCTL1_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DOEPCTL1_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DOEPCTL1_ALTERNATE_SNPM								(0x1u<<20)
#define	OTG_DOEPCTL1_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DOEPCTL1_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DOEPCTL1_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DOEPCTL1_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DOEPCTL1_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DOEPCTL1_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DOEPCTL1_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DOEPCTL1_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DOEPCTL1_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DOEPCTL1_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DOEPCTL1_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DOEPCTL1_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DOEPCTL1_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DOEPCTL1_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DOEPCTL1_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DOEPINT1 Configuration

#define	OTG_DOEPINT1_STPKTRX									(0x1u<<15)
#define	OTG_DOEPINT1_NYET										(0x1u<<14)
#define	OTG_DOEPINT1_NAK										(0x1u<<13)
#define	OTG_DOEPINT1_BERR										(0x1u<<12)
#define	OTG_DOEPINT1_OUTPKTERR									(0x1u<<8)
#define	OTG_DOEPINT1_B2BSTUP									(0x1u<<6)
#define	OTG_DOEPINT1_STSPHSRX									(0x1u<<5)
#define	OTG_DOEPINT1_OTEPDIS									(0x1u<<4)
#define	OTG_DOEPINT1_STUP										(0x1u<<3)
#define	OTG_DOEPINT1_AHBERR										(0x1u<<2)
#define	OTG_DOEPINT1_EPDISD										(0x1u<<1)
#define	OTG_DOEPINT1_XFRC										(0x1u<<0)

// DOEPTSIZ1 Configuration

#define	OTG_DOEPTSIZ1_RXDPID									(0x3u<<29)
#define	OTG_DOEPTSIZ1_RXDPID_0									(0x1u<<29)
#define	OTG_DOEPTSIZ1_PKTCNT									(0x3FFu<<19)
#define	OTG_DOEPTSIZ1_PKTCNT_0									(0x1u<<19)
#define	OTG_DOEPTSIZ1_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DOEPTSIZ1_XFRSIZ_0									(0x1u<<0)

#define	OTG_DOEPTSIZ1_RXDPID_B_0X0_ISOCHRONOUS_OUT_ENDPOINTS	(0x0u<<29)
#define	OTG_DOEPTSIZ1_RXDPID_B_0X1_ISOCHRONOUS_OUT_ENDPOINTS	(0x1u<<29)
#define	OTG_DOEPTSIZ1_RXDPID_B_0X2_ISOCHRONOUS_OUT_ENDPOINTS	(0x2u<<29)
#define	OTG_DOEPTSIZ1_RXDPID_B_0X3_ISOCHRONOUS_OUT_ENDPOINTS	(0x3u<<29)

// DOEPDMA1 Configuration

#define	OTG_DOEPDMA1_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DOEPDMA1_DMAADDR_0									(0x1u<<0)

// DOEPCTL2 Configuration

#define	OTG_DOEPCTL2_EPENA										(0x1u<<31)
#define	OTG_DOEPCTL2_EPDIS										(0x1u<<30)
#define	OTG_DOEPCTL2_SD1PID										(0x1u<<29)
#define	OTG_DOEPCTL2_SD0PID										(0x1u<<28)
#define	OTG_DOEPCTL2_SNAK										(0x1u<<27)
#define	OTG_DOEPCTL2_CNAK										(0x1u<<26)
#define	OTG_DOEPCTL2_STALL										(0x1u<<21)
#define	OTG_DOEPCTL2_SNPM										(0x1u<<20)
#define	OTG_DOEPCTL2_EPTYP										(0x3u<<18)
#define	OTG_DOEPCTL2_EPTYP_0									(0x1u<<18)
#define	OTG_DOEPCTL2_NAKSTS										(0x1u<<17)
#define	OTG_DOEPCTL2_DPID										(0x1u<<16)
#define	OTG_DOEPCTL2_USBAEP										(0x1u<<15)
#define	OTG_DOEPCTL2_MPSIZ										(0x7FFu<<0)
#define	OTG_DOEPCTL2_MPSIZ_0									(0x1u<<0)

#define	OTG_DOEPCTL2_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DOEPCTL2_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DOEPCTL2_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DOEPCTL2_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DOEPCTL2_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DOEPCTL2_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DOEPCTL2_DPID_B_0X0									(0x0u<<16)
#define	OTG_DOEPCTL2_DPID_B_0X1									(0x1u<<16)

// DOEPCTL2_ALTERNATE Configuration

#define	OTG_DOEPCTL2_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DOEPCTL2_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DOEPCTL2_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DOEPCTL2_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DOEPCTL2_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DOEPCTL2_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DOEPCTL2_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DOEPCTL2_ALTERNATE_SNPM								(0x1u<<20)
#define	OTG_DOEPCTL2_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DOEPCTL2_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DOEPCTL2_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DOEPCTL2_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DOEPCTL2_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DOEPCTL2_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DOEPCTL2_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DOEPCTL2_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DOEPCTL2_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DOEPCTL2_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DOEPCTL2_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DOEPCTL2_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DOEPCTL2_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DOEPCTL2_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DOEPCTL2_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DOEPINT2 Configuration

#define	OTG_DOEPINT2_STPKTRX									(0x1u<<15)
#define	OTG_DOEPINT2_NYET										(0x1u<<14)
#define	OTG_DOEPINT2_NAK										(0x1u<<13)
#define	OTG_DOEPINT2_BERR										(0x1u<<12)
#define	OTG_DOEPINT2_OUTPKTERR									(0x1u<<8)
#define	OTG_DOEPINT2_B2BSTUP									(0x1u<<6)
#define	OTG_DOEPINT2_STSPHSRX									(0x1u<<5)
#define	OTG_DOEPINT2_OTEPDIS									(0x1u<<4)
#define	OTG_DOEPINT2_STUP										(0x1u<<3)
#define	OTG_DOEPINT2_AHBERR										(0x1u<<2)
#define	OTG_DOEPINT2_EPDISD										(0x1u<<1)
#define	OTG_DOEPINT2_XFRC										(0x1u<<0)

// DOEPTSIZ2 Configuration

#define	OTG_DOEPTSIZ2_RXDPID									(0x3u<<29)
#define	OTG_DOEPTSIZ2_RXDPID_0									(0x1u<<29)
#define	OTG_DOEPTSIZ2_PKTCNT									(0x3FFu<<19)
#define	OTG_DOEPTSIZ2_PKTCNT_0									(0x1u<<19)
#define	OTG_DOEPTSIZ2_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DOEPTSIZ2_XFRSIZ_0									(0x1u<<0)

#define	OTG_DOEPTSIZ2_RXDPID_B_0X0_ISOCHRONOUS_OUT_ENDPOINTS	(0x0u<<29)
#define	OTG_DOEPTSIZ2_RXDPID_B_0X1_ISOCHRONOUS_OUT_ENDPOINTS	(0x1u<<29)
#define	OTG_DOEPTSIZ2_RXDPID_B_0X2_ISOCHRONOUS_OUT_ENDPOINTS	(0x2u<<29)
#define	OTG_DOEPTSIZ2_RXDPID_B_0X3_ISOCHRONOUS_OUT_ENDPOINTS	(0x3u<<29)

// DOEPDMA2 Configuration

#define	OTG_DOEPDMA2_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DOEPDMA2_DMAADDR_0									(0x1u<<0)

// DOEPCTL3 Configuration

#define	OTG_DOEPCTL3_EPENA										(0x1u<<31)
#define	OTG_DOEPCTL3_EPDIS										(0x1u<<30)
#define	OTG_DOEPCTL3_SD1PID										(0x1u<<29)
#define	OTG_DOEPCTL3_SD0PID										(0x1u<<28)
#define	OTG_DOEPCTL3_SNAK										(0x1u<<27)
#define	OTG_DOEPCTL3_CNAK										(0x1u<<26)
#define	OTG_DOEPCTL3_STALL										(0x1u<<21)
#define	OTG_DOEPCTL3_SNPM										(0x1u<<20)
#define	OTG_DOEPCTL3_EPTYP										(0x3u<<18)
#define	OTG_DOEPCTL3_EPTYP_0									(0x1u<<18)
#define	OTG_DOEPCTL3_NAKSTS										(0x1u<<17)
#define	OTG_DOEPCTL3_DPID										(0x1u<<16)
#define	OTG_DOEPCTL3_USBAEP										(0x1u<<15)
#define	OTG_DOEPCTL3_MPSIZ										(0x7FFu<<0)
#define	OTG_DOEPCTL3_MPSIZ_0									(0x1u<<0)

#define	OTG_DOEPCTL3_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DOEPCTL3_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DOEPCTL3_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DOEPCTL3_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DOEPCTL3_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DOEPCTL3_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DOEPCTL3_DPID_B_0X0									(0x0u<<16)
#define	OTG_DOEPCTL3_DPID_B_0X1									(0x1u<<16)

// DOEPCTL3_ALTERNATE Configuration

#define	OTG_DOEPCTL3_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DOEPCTL3_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DOEPCTL3_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DOEPCTL3_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DOEPCTL3_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DOEPCTL3_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DOEPCTL3_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DOEPCTL3_ALTERNATE_SNPM								(0x1u<<20)
#define	OTG_DOEPCTL3_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DOEPCTL3_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DOEPCTL3_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DOEPCTL3_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DOEPCTL3_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DOEPCTL3_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DOEPCTL3_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DOEPCTL3_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DOEPCTL3_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DOEPCTL3_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DOEPCTL3_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DOEPCTL3_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DOEPCTL3_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DOEPCTL3_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DOEPCTL3_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DOEPINT3 Configuration

#define	OTG_DOEPINT3_STPKTRX									(0x1u<<15)
#define	OTG_DOEPINT3_NYET										(0x1u<<14)
#define	OTG_DOEPINT3_NAK										(0x1u<<13)
#define	OTG_DOEPINT3_BERR										(0x1u<<12)
#define	OTG_DOEPINT3_OUTPKTERR									(0x1u<<8)
#define	OTG_DOEPINT3_B2BSTUP									(0x1u<<6)
#define	OTG_DOEPINT3_STSPHSRX									(0x1u<<5)
#define	OTG_DOEPINT3_OTEPDIS									(0x1u<<4)
#define	OTG_DOEPINT3_STUP										(0x1u<<3)
#define	OTG_DOEPINT3_AHBERR										(0x1u<<2)
#define	OTG_DOEPINT3_EPDISD										(0x1u<<1)
#define	OTG_DOEPINT3_XFRC										(0x1u<<0)

// DOEPTSIZ3 Configuration

#define	OTG_DOEPTSIZ3_RXDPID									(0x3u<<29)
#define	OTG_DOEPTSIZ3_RXDPID_0									(0x1u<<29)
#define	OTG_DOEPTSIZ3_PKTCNT									(0x3FFu<<19)
#define	OTG_DOEPTSIZ3_PKTCNT_0									(0x1u<<19)
#define	OTG_DOEPTSIZ3_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DOEPTSIZ3_XFRSIZ_0									(0x1u<<0)

#define	OTG_DOEPTSIZ3_RXDPID_B_0X0_ISOCHRONOUS_OUT_ENDPOINTS	(0x0u<<29)
#define	OTG_DOEPTSIZ3_RXDPID_B_0X1_ISOCHRONOUS_OUT_ENDPOINTS	(0x1u<<29)
#define	OTG_DOEPTSIZ3_RXDPID_B_0X2_ISOCHRONOUS_OUT_ENDPOINTS	(0x2u<<29)
#define	OTG_DOEPTSIZ3_RXDPID_B_0X3_ISOCHRONOUS_OUT_ENDPOINTS	(0x3u<<29)

// DOEPDMA3 Configuration

#define	OTG_DOEPDMA3_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DOEPDMA3_DMAADDR_0									(0x1u<<0)

// DOEPCTL4 Configuration

#define	OTG_DOEPCTL4_EPENA										(0x1u<<31)
#define	OTG_DOEPCTL4_EPDIS										(0x1u<<30)
#define	OTG_DOEPCTL4_SD1PID										(0x1u<<29)
#define	OTG_DOEPCTL4_SD0PID										(0x1u<<28)
#define	OTG_DOEPCTL4_SNAK										(0x1u<<27)
#define	OTG_DOEPCTL4_CNAK										(0x1u<<26)
#define	OTG_DOEPCTL4_STALL										(0x1u<<21)
#define	OTG_DOEPCTL4_SNPM										(0x1u<<20)
#define	OTG_DOEPCTL4_EPTYP										(0x3u<<18)
#define	OTG_DOEPCTL4_EPTYP_0									(0x1u<<18)
#define	OTG_DOEPCTL4_NAKSTS										(0x1u<<17)
#define	OTG_DOEPCTL4_DPID										(0x1u<<16)
#define	OTG_DOEPCTL4_USBAEP										(0x1u<<15)
#define	OTG_DOEPCTL4_MPSIZ										(0x7FFu<<0)
#define	OTG_DOEPCTL4_MPSIZ_0									(0x1u<<0)

#define	OTG_DOEPCTL4_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DOEPCTL4_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DOEPCTL4_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DOEPCTL4_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DOEPCTL4_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DOEPCTL4_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DOEPCTL4_DPID_B_0X0									(0x0u<<16)
#define	OTG_DOEPCTL4_DPID_B_0X1									(0x1u<<16)

// DOEPCTL4_ALTERNATE Configuration

#define	OTG_DOEPCTL4_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DOEPCTL4_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DOEPCTL4_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DOEPCTL4_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DOEPCTL4_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DOEPCTL4_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DOEPCTL4_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DOEPCTL4_ALTERNATE_SNPM								(0x1u<<20)
#define	OTG_DOEPCTL4_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DOEPCTL4_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DOEPCTL4_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DOEPCTL4_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DOEPCTL4_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DOEPCTL4_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DOEPCTL4_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DOEPCTL4_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DOEPCTL4_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DOEPCTL4_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DOEPCTL4_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DOEPCTL4_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DOEPCTL4_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DOEPCTL4_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DOEPCTL4_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DOEPINT4 Configuration

#define	OTG_DOEPINT4_STPKTRX									(0x1u<<15)
#define	OTG_DOEPINT4_NYET										(0x1u<<14)
#define	OTG_DOEPINT4_NAK										(0x1u<<13)
#define	OTG_DOEPINT4_BERR										(0x1u<<12)
#define	OTG_DOEPINT4_OUTPKTERR									(0x1u<<8)
#define	OTG_DOEPINT4_B2BSTUP									(0x1u<<6)
#define	OTG_DOEPINT4_STSPHSRX									(0x1u<<5)
#define	OTG_DOEPINT4_OTEPDIS									(0x1u<<4)
#define	OTG_DOEPINT4_STUP										(0x1u<<3)
#define	OTG_DOEPINT4_AHBERR										(0x1u<<2)
#define	OTG_DOEPINT4_EPDISD										(0x1u<<1)
#define	OTG_DOEPINT4_XFRC										(0x1u<<0)

// DOEPTSIZ4 Configuration

#define	OTG_DOEPTSIZ4_RXDPID									(0x3u<<29)
#define	OTG_DOEPTSIZ4_RXDPID_0									(0x1u<<29)
#define	OTG_DOEPTSIZ4_PKTCNT									(0x3FFu<<19)
#define	OTG_DOEPTSIZ4_PKTCNT_0									(0x1u<<19)
#define	OTG_DOEPTSIZ4_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DOEPTSIZ4_XFRSIZ_0									(0x1u<<0)

#define	OTG_DOEPTSIZ4_RXDPID_B_0X0_ISOCHRONOUS_OUT_ENDPOINTS	(0x0u<<29)
#define	OTG_DOEPTSIZ4_RXDPID_B_0X1_ISOCHRONOUS_OUT_ENDPOINTS	(0x1u<<29)
#define	OTG_DOEPTSIZ4_RXDPID_B_0X2_ISOCHRONOUS_OUT_ENDPOINTS	(0x2u<<29)
#define	OTG_DOEPTSIZ4_RXDPID_B_0X3_ISOCHRONOUS_OUT_ENDPOINTS	(0x3u<<29)

// DOEPDMA4 Configuration

#define	OTG_DOEPDMA4_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DOEPDMA4_DMAADDR_0									(0x1u<<0)

// DOEPCTL5 Configuration

#define	OTG_DOEPCTL5_EPENA										(0x1u<<31)
#define	OTG_DOEPCTL5_EPDIS										(0x1u<<30)
#define	OTG_DOEPCTL5_SD1PID										(0x1u<<29)
#define	OTG_DOEPCTL5_SD0PID										(0x1u<<28)
#define	OTG_DOEPCTL5_SNAK										(0x1u<<27)
#define	OTG_DOEPCTL5_CNAK										(0x1u<<26)
#define	OTG_DOEPCTL5_STALL										(0x1u<<21)
#define	OTG_DOEPCTL5_SNPM										(0x1u<<20)
#define	OTG_DOEPCTL5_EPTYP										(0x3u<<18)
#define	OTG_DOEPCTL5_EPTYP_0									(0x1u<<18)
#define	OTG_DOEPCTL5_NAKSTS										(0x1u<<17)
#define	OTG_DOEPCTL5_DPID										(0x1u<<16)
#define	OTG_DOEPCTL5_USBAEP										(0x1u<<15)
#define	OTG_DOEPCTL5_MPSIZ										(0x7FFu<<0)
#define	OTG_DOEPCTL5_MPSIZ_0									(0x1u<<0)

#define	OTG_DOEPCTL5_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DOEPCTL5_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DOEPCTL5_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DOEPCTL5_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DOEPCTL5_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DOEPCTL5_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DOEPCTL5_DPID_B_0X0									(0x0u<<16)
#define	OTG_DOEPCTL5_DPID_B_0X1									(0x1u<<16)

// DOEPCTL5_ALTERNATE Configuration

#define	OTG_DOEPCTL5_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DOEPCTL5_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DOEPCTL5_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DOEPCTL5_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DOEPCTL5_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DOEPCTL5_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DOEPCTL5_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DOEPCTL5_ALTERNATE_SNPM								(0x1u<<20)
#define	OTG_DOEPCTL5_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DOEPCTL5_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DOEPCTL5_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DOEPCTL5_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DOEPCTL5_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DOEPCTL5_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DOEPCTL5_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DOEPCTL5_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DOEPCTL5_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DOEPCTL5_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DOEPCTL5_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DOEPCTL5_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DOEPCTL5_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DOEPCTL5_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DOEPCTL5_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DOEPINT5 Configuration

#define	OTG_DOEPINT5_STPKTRX									(0x1u<<15)
#define	OTG_DOEPINT5_NYET										(0x1u<<14)
#define	OTG_DOEPINT5_NAK										(0x1u<<13)
#define	OTG_DOEPINT5_BERR										(0x1u<<12)
#define	OTG_DOEPINT5_OUTPKTERR									(0x1u<<8)
#define	OTG_DOEPINT5_B2BSTUP									(0x1u<<6)
#define	OTG_DOEPINT5_STSPHSRX									(0x1u<<5)
#define	OTG_DOEPINT5_OTEPDIS									(0x1u<<4)
#define	OTG_DOEPINT5_STUP										(0x1u<<3)
#define	OTG_DOEPINT5_AHBERR										(0x1u<<2)
#define	OTG_DOEPINT5_EPDISD										(0x1u<<1)
#define	OTG_DOEPINT5_XFRC										(0x1u<<0)

// DOEPTSIZ5 Configuration

#define	OTG_DOEPTSIZ5_RXDPID									(0x3u<<29)
#define	OTG_DOEPTSIZ5_RXDPID_0									(0x1u<<29)
#define	OTG_DOEPTSIZ5_PKTCNT									(0x3FFu<<19)
#define	OTG_DOEPTSIZ5_PKTCNT_0									(0x1u<<19)
#define	OTG_DOEPTSIZ5_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DOEPTSIZ5_XFRSIZ_0									(0x1u<<0)

#define	OTG_DOEPTSIZ5_RXDPID_B_0X0_ISOCHRONOUS_OUT_ENDPOINTS	(0x0u<<29)
#define	OTG_DOEPTSIZ5_RXDPID_B_0X1_ISOCHRONOUS_OUT_ENDPOINTS	(0x1u<<29)
#define	OTG_DOEPTSIZ5_RXDPID_B_0X2_ISOCHRONOUS_OUT_ENDPOINTS	(0x2u<<29)
#define	OTG_DOEPTSIZ5_RXDPID_B_0X3_ISOCHRONOUS_OUT_ENDPOINTS	(0x3u<<29)

// DOEPDMA5 Configuration

#define	OTG_DOEPDMA5_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DOEPDMA5_DMAADDR_0									(0x1u<<0)

// DOEPCTL6 Configuration

#define	OTG_DOEPCTL6_EPENA										(0x1u<<31)
#define	OTG_DOEPCTL6_EPDIS										(0x1u<<30)
#define	OTG_DOEPCTL6_SD1PID										(0x1u<<29)
#define	OTG_DOEPCTL6_SD0PID										(0x1u<<28)
#define	OTG_DOEPCTL6_SNAK										(0x1u<<27)
#define	OTG_DOEPCTL6_CNAK										(0x1u<<26)
#define	OTG_DOEPCTL6_STALL										(0x1u<<21)
#define	OTG_DOEPCTL6_SNPM										(0x1u<<20)
#define	OTG_DOEPCTL6_EPTYP										(0x3u<<18)
#define	OTG_DOEPCTL6_EPTYP_0									(0x1u<<18)
#define	OTG_DOEPCTL6_NAKSTS										(0x1u<<17)
#define	OTG_DOEPCTL6_DPID										(0x1u<<16)
#define	OTG_DOEPCTL6_USBAEP										(0x1u<<15)
#define	OTG_DOEPCTL6_MPSIZ										(0x7FFu<<0)
#define	OTG_DOEPCTL6_MPSIZ_0									(0x1u<<0)

#define	OTG_DOEPCTL6_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DOEPCTL6_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DOEPCTL6_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DOEPCTL6_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DOEPCTL6_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DOEPCTL6_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DOEPCTL6_DPID_B_0X0									(0x0u<<16)
#define	OTG_DOEPCTL6_DPID_B_0X1									(0x1u<<16)

// DOEPCTL6_ALTERNATE Configuration

#define	OTG_DOEPCTL6_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DOEPCTL6_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DOEPCTL6_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DOEPCTL6_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DOEPCTL6_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DOEPCTL6_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DOEPCTL6_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DOEPCTL6_ALTERNATE_SNPM								(0x1u<<20)
#define	OTG_DOEPCTL6_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DOEPCTL6_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DOEPCTL6_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DOEPCTL6_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DOEPCTL6_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DOEPCTL6_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DOEPCTL6_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DOEPCTL6_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DOEPCTL6_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DOEPCTL6_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DOEPCTL6_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DOEPCTL6_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DOEPCTL6_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DOEPCTL6_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DOEPCTL6_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DOEPINT6 Configuration

#define	OTG_DOEPINT6_STPKTRX									(0x1u<<15)
#define	OTG_DOEPINT6_NYET										(0x1u<<14)
#define	OTG_DOEPINT6_NAK										(0x1u<<13)
#define	OTG_DOEPINT6_BERR										(0x1u<<12)
#define	OTG_DOEPINT6_OUTPKTERR									(0x1u<<8)
#define	OTG_DOEPINT6_B2BSTUP									(0x1u<<6)
#define	OTG_DOEPINT6_STSPHSRX									(0x1u<<5)
#define	OTG_DOEPINT6_OTEPDIS									(0x1u<<4)
#define	OTG_DOEPINT6_STUP										(0x1u<<3)
#define	OTG_DOEPINT6_AHBERR										(0x1u<<2)
#define	OTG_DOEPINT6_EPDISD										(0x1u<<1)
#define	OTG_DOEPINT6_XFRC										(0x1u<<0)

// DOEPTSIZ6 Configuration

#define	OTG_DOEPTSIZ6_RXDPID									(0x3u<<29)
#define	OTG_DOEPTSIZ6_RXDPID_0									(0x1u<<29)
#define	OTG_DOEPTSIZ6_PKTCNT									(0x3FFu<<19)
#define	OTG_DOEPTSIZ6_PKTCNT_0									(0x1u<<19)
#define	OTG_DOEPTSIZ6_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DOEPTSIZ6_XFRSIZ_0									(0x1u<<0)

#define	OTG_DOEPTSIZ6_RXDPID_B_0X0_ISOCHRONOUS_OUT_ENDPOINTS	(0x0u<<29)
#define	OTG_DOEPTSIZ6_RXDPID_B_0X1_ISOCHRONOUS_OUT_ENDPOINTS	(0x1u<<29)
#define	OTG_DOEPTSIZ6_RXDPID_B_0X2_ISOCHRONOUS_OUT_ENDPOINTS	(0x2u<<29)
#define	OTG_DOEPTSIZ6_RXDPID_B_0X3_ISOCHRONOUS_OUT_ENDPOINTS	(0x3u<<29)

// DOEPDMA6 Configuration

#define	OTG_DOEPDMA6_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DOEPDMA6_DMAADDR_0									(0x1u<<0)

// DOEPCTL7 Configuration

#define	OTG_DOEPCTL7_EPENA										(0x1u<<31)
#define	OTG_DOEPCTL7_EPDIS										(0x1u<<30)
#define	OTG_DOEPCTL7_SD1PID										(0x1u<<29)
#define	OTG_DOEPCTL7_SD0PID										(0x1u<<28)
#define	OTG_DOEPCTL7_SNAK										(0x1u<<27)
#define	OTG_DOEPCTL7_CNAK										(0x1u<<26)
#define	OTG_DOEPCTL7_STALL										(0x1u<<21)
#define	OTG_DOEPCTL7_SNPM										(0x1u<<20)
#define	OTG_DOEPCTL7_EPTYP										(0x3u<<18)
#define	OTG_DOEPCTL7_EPTYP_0									(0x1u<<18)
#define	OTG_DOEPCTL7_NAKSTS										(0x1u<<17)
#define	OTG_DOEPCTL7_DPID										(0x1u<<16)
#define	OTG_DOEPCTL7_USBAEP										(0x1u<<15)
#define	OTG_DOEPCTL7_MPSIZ										(0x7FFu<<0)
#define	OTG_DOEPCTL7_MPSIZ_0									(0x1u<<0)

#define	OTG_DOEPCTL7_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DOEPCTL7_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DOEPCTL7_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DOEPCTL7_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DOEPCTL7_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DOEPCTL7_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DOEPCTL7_DPID_B_0X0									(0x0u<<16)
#define	OTG_DOEPCTL7_DPID_B_0X1									(0x1u<<16)

// DOEPCTL7_ALTERNATE Configuration

#define	OTG_DOEPCTL7_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DOEPCTL7_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DOEPCTL7_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DOEPCTL7_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DOEPCTL7_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DOEPCTL7_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DOEPCTL7_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DOEPCTL7_ALTERNATE_SNPM								(0x1u<<20)
#define	OTG_DOEPCTL7_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DOEPCTL7_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DOEPCTL7_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DOEPCTL7_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DOEPCTL7_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DOEPCTL7_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DOEPCTL7_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DOEPCTL7_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DOEPCTL7_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DOEPCTL7_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DOEPCTL7_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DOEPCTL7_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DOEPCTL7_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DOEPCTL7_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DOEPCTL7_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DOEPINT7 Configuration

#define	OTG_DOEPINT7_STPKTRX									(0x1u<<15)
#define	OTG_DOEPINT7_NYET										(0x1u<<14)
#define	OTG_DOEPINT7_NAK										(0x1u<<13)
#define	OTG_DOEPINT7_BERR										(0x1u<<12)
#define	OTG_DOEPINT7_OUTPKTERR									(0x1u<<8)
#define	OTG_DOEPINT7_B2BSTUP									(0x1u<<6)
#define	OTG_DOEPINT7_STSPHSRX									(0x1u<<5)
#define	OTG_DOEPINT7_OTEPDIS									(0x1u<<4)
#define	OTG_DOEPINT7_STUP										(0x1u<<3)
#define	OTG_DOEPINT7_AHBERR										(0x1u<<2)
#define	OTG_DOEPINT7_EPDISD										(0x1u<<1)
#define	OTG_DOEPINT7_XFRC										(0x1u<<0)

// DOEPTSIZ7 Configuration

#define	OTG_DOEPTSIZ7_RXDPID									(0x3u<<29)
#define	OTG_DOEPTSIZ7_RXDPID_0									(0x1u<<29)
#define	OTG_DOEPTSIZ7_PKTCNT									(0x3FFu<<19)
#define	OTG_DOEPTSIZ7_PKTCNT_0									(0x1u<<19)
#define	OTG_DOEPTSIZ7_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DOEPTSIZ7_XFRSIZ_0									(0x1u<<0)

#define	OTG_DOEPTSIZ7_RXDPID_B_0X0_ISOCHRONOUS_OUT_ENDPOINTS	(0x0u<<29)
#define	OTG_DOEPTSIZ7_RXDPID_B_0X1_ISOCHRONOUS_OUT_ENDPOINTS	(0x1u<<29)
#define	OTG_DOEPTSIZ7_RXDPID_B_0X2_ISOCHRONOUS_OUT_ENDPOINTS	(0x2u<<29)
#define	OTG_DOEPTSIZ7_RXDPID_B_0X3_ISOCHRONOUS_OUT_ENDPOINTS	(0x3u<<29)

// DOEPDMA7 Configuration

#define	OTG_DOEPDMA7_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DOEPDMA7_DMAADDR_0									(0x1u<<0)

// DOEPCTL8 Configuration

#define	OTG_DOEPCTL8_EPENA										(0x1u<<31)
#define	OTG_DOEPCTL8_EPDIS										(0x1u<<30)
#define	OTG_DOEPCTL8_SD1PID										(0x1u<<29)
#define	OTG_DOEPCTL8_SD0PID										(0x1u<<28)
#define	OTG_DOEPCTL8_SNAK										(0x1u<<27)
#define	OTG_DOEPCTL8_CNAK										(0x1u<<26)
#define	OTG_DOEPCTL8_STALL										(0x1u<<21)
#define	OTG_DOEPCTL8_SNPM										(0x1u<<20)
#define	OTG_DOEPCTL8_EPTYP										(0x3u<<18)
#define	OTG_DOEPCTL8_EPTYP_0									(0x1u<<18)
#define	OTG_DOEPCTL8_NAKSTS										(0x1u<<17)
#define	OTG_DOEPCTL8_DPID										(0x1u<<16)
#define	OTG_DOEPCTL8_USBAEP										(0x1u<<15)
#define	OTG_DOEPCTL8_MPSIZ										(0x7FFu<<0)
#define	OTG_DOEPCTL8_MPSIZ_0									(0x1u<<0)

#define	OTG_DOEPCTL8_EPTYP_B_0X0								(0x0u<<18)
#define	OTG_DOEPCTL8_EPTYP_B_0X1								(0x1u<<18)
#define	OTG_DOEPCTL8_EPTYP_B_0X2								(0x2u<<18)
#define	OTG_DOEPCTL8_EPTYP_B_0X3								(0x3u<<18)
#define	OTG_DOEPCTL8_NAKSTS_B_0X0								(0x0u<<17)
#define	OTG_DOEPCTL8_NAKSTS_B_0X1								(0x1u<<17)
#define	OTG_DOEPCTL8_DPID_B_0X0									(0x0u<<16)
#define	OTG_DOEPCTL8_DPID_B_0X1									(0x1u<<16)

// DOEPCTL8_ALTERNATE Configuration

#define	OTG_DOEPCTL8_ALTERNATE_EPENA							(0x1u<<31)
#define	OTG_DOEPCTL8_ALTERNATE_EPDIS							(0x1u<<30)
#define	OTG_DOEPCTL8_ALTERNATE_SODDFRM							(0x1u<<29)
#define	OTG_DOEPCTL8_ALTERNATE_SEVNFRM							(0x1u<<28)
#define	OTG_DOEPCTL8_ALTERNATE_SNAK								(0x1u<<27)
#define	OTG_DOEPCTL8_ALTERNATE_CNAK								(0x1u<<26)
#define	OTG_DOEPCTL8_ALTERNATE_STALL							(0x1u<<21)
#define	OTG_DOEPCTL8_ALTERNATE_SNPM								(0x1u<<20)
#define	OTG_DOEPCTL8_ALTERNATE_EPTYP							(0x3u<<18)
#define	OTG_DOEPCTL8_ALTERNATE_EPTYP_0							(0x1u<<18)
#define	OTG_DOEPCTL8_ALTERNATE_NAKSTS							(0x1u<<17)
#define	OTG_DOEPCTL8_ALTERNATE_EONUM							(0x1u<<16)
#define	OTG_DOEPCTL8_ALTERNATE_USBAEP							(0x1u<<15)
#define	OTG_DOEPCTL8_ALTERNATE_MPSIZ							(0x7FFu<<0)
#define	OTG_DOEPCTL8_ALTERNATE_MPSIZ_0							(0x1u<<0)

#define	OTG_DOEPCTL8_ALTERNATE_EPTYP_B_0X0						(0x0u<<18)
#define	OTG_DOEPCTL8_ALTERNATE_EPTYP_B_0X1						(0x1u<<18)
#define	OTG_DOEPCTL8_ALTERNATE_EPTYP_B_0X2						(0x2u<<18)
#define	OTG_DOEPCTL8_ALTERNATE_EPTYP_B_0X3						(0x3u<<18)
#define	OTG_DOEPCTL8_ALTERNATE_NAKSTS_B_0X0						(0x0u<<17)
#define	OTG_DOEPCTL8_ALTERNATE_NAKSTS_B_0X1						(0x1u<<17)
#define	OTG_DOEPCTL8_ALTERNATE_EONUM_B_0X0						(0x0u<<16)
#define	OTG_DOEPCTL8_ALTERNATE_EONUM_B_0X1						(0x1u<<16)

// DOEPINT8 Configuration

#define	OTG_DOEPINT8_STPKTRX									(0x1u<<15)
#define	OTG_DOEPINT8_NYET										(0x1u<<14)
#define	OTG_DOEPINT8_NAK										(0x1u<<13)
#define	OTG_DOEPINT8_BERR										(0x1u<<12)
#define	OTG_DOEPINT8_OUTPKTERR									(0x1u<<8)
#define	OTG_DOEPINT8_B2BSTUP									(0x1u<<6)
#define	OTG_DOEPINT8_STSPHSRX									(0x1u<<5)
#define	OTG_DOEPINT8_OTEPDIS									(0x1u<<4)
#define	OTG_DOEPINT8_STUP										(0x1u<<3)
#define	OTG_DOEPINT8_AHBERR										(0x1u<<2)
#define	OTG_DOEPINT8_EPDISD										(0x1u<<1)
#define	OTG_DOEPINT8_XFRC										(0x1u<<0)

// DOEPTSIZ8 Configuration

#define	OTG_DOEPTSIZ8_RXDPID									(0x3u<<29)
#define	OTG_DOEPTSIZ8_RXDPID_0									(0x1u<<29)
#define	OTG_DOEPTSIZ8_PKTCNT									(0x3FFu<<19)
#define	OTG_DOEPTSIZ8_PKTCNT_0									(0x1u<<19)
#define	OTG_DOEPTSIZ8_XFRSIZ									(0x7FFFFu<<0)
#define	OTG_DOEPTSIZ8_XFRSIZ_0									(0x1u<<0)

#define	OTG_DOEPTSIZ8_RXDPID_B_0X0_ISOCHRONOUS_OUT_ENDPOINTS	(0x0u<<29)
#define	OTG_DOEPTSIZ8_RXDPID_B_0X1_ISOCHRONOUS_OUT_ENDPOINTS	(0x1u<<29)
#define	OTG_DOEPTSIZ8_RXDPID_B_0X2_ISOCHRONOUS_OUT_ENDPOINTS	(0x2u<<29)
#define	OTG_DOEPTSIZ8_RXDPID_B_0X3_ISOCHRONOUS_OUT_ENDPOINTS	(0x3u<<29)

// DOEPDMA8 Configuration

#define	OTG_DOEPDMA8_DMAADDR									(0xFFFFFFFFu<<0)
#define	OTG_DOEPDMA8_DMAADDR_0									(0x1u<<0)

// PCGCCTL Configuration

#define	OTG_PCGCCTL_SUSP										(0x1u<<7)
#define	OTG_PCGCCTL_PHYSLEEP									(0x1u<<6)
#define	OTG_PCGCCTL_ENL1GTG										(0x1u<<5)
#define	OTG_PCGCCTL_PHYSUSP										(0x1u<<4)
#define	OTG_PCGCCTL_GATEHCLK									(0x1u<<1)
#define	OTG_PCGCCTL_STPPCLK										(0x1u<<0)

// PCGCCTL1 Configuration

#define	OTG_PCGCCTL1_RAMGATEEN									(0x1u<<3)
#define	OTG_PCGCCTL1_CNTGATECLK									(0x3u<<1)
#define	OTG_PCGCCTL1_CNTGATECLK_0								(0x1u<<1)
#define	OTG_PCGCCTL1_GATEEN										(0x1u<<0)

#define	OTG_PCGCCTL1_CNTGATECLK_B_0X0							(0x0u<<1)
#define	OTG_PCGCCTL1_CNTGATECLK_B_0X1							(0x1u<<1)
