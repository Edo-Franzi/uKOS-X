/*
; stm32U5Gx_otg_hs.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_otg_hs equates.
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

// OTG_HS address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	GOTGCTL;
	volatile	uint32_t	GOTGINT;
	volatile	uint32_t	GAHBCFG;
	volatile	uint32_t	GUSBCFG;
	volatile	uint32_t	GRSTCTL;
	volatile	uint32_t	GINTSTS;
	volatile	uint32_t	GINTMSK;
	volatile	uint32_t	GRXSTSR;
	volatile	uint32_t	GRXSTSP;
	volatile	uint32_t	GRXFSIZ;
	volatile	uint32_t	HNPTXFSIZ;
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
	volatile	uint32_t	HCINT1_DEVICE;
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
	volatile	uint32_t	RESERVED24[2];
	volatile	uint32_t	DVBUSDIS;
	volatile	uint32_t	DVBUSPULSE;
	volatile	uint32_t	DTHRCTL;
	volatile	uint32_t	DIEPEMPMSK;
	volatile	uint32_t	RESERVED25[19];
	volatile	uint32_t	DOEPEACHMSK1;
	volatile	uint32_t	RESERVED26[30];
	volatile	uint32_t	DIEPCTL0;
	volatile	uint32_t	RESERVED27;
	volatile	uint32_t	DIEPINT0;
	volatile	uint32_t	RESERVED28;
	volatile	uint32_t	DIEPTSIZ0;
	volatile	uint32_t	RESERVED29;
	volatile	uint32_t	DTXFSTS0;
	volatile	uint32_t	RESERVED30;
	volatile	uint32_t	DIEPCTL1;
	volatile	uint32_t	RESERVED31;
	volatile	uint32_t	DIEPINT1;
	volatile	uint32_t	RESERVED32;
	volatile	uint32_t	DIEPTSIZ1;
	volatile	uint32_t	DIEPDMA1;
	volatile	uint32_t	DTXFSTS1;
	volatile	uint32_t	RESERVED33;
	volatile	uint32_t	DIEPCTL2;
	volatile	uint32_t	RESERVED34;
	volatile	uint32_t	DIEPINT2;
	volatile	uint32_t	RESERVED35;
	volatile	uint32_t	DIEPTSIZ2;
	volatile	uint32_t	DIEPDMA2;
	volatile	uint32_t	DTXFSTS2;
	volatile	uint32_t	RESERVED36;
	volatile	uint32_t	DIEPCTL3;
	volatile	uint32_t	RESERVED37;
	volatile	uint32_t	DIEPINT3;
	volatile	uint32_t	RESERVED38;
	volatile	uint32_t	DIEPTSIZ3;
	volatile	uint32_t	DIEPDMA3;
	volatile	uint32_t	DTXFSTS3;
	volatile	uint32_t	RESERVED39;
	volatile	uint32_t	DIEPCTL4;
	volatile	uint32_t	RESERVED40;
	volatile	uint32_t	DIEPINT4;
	volatile	uint32_t	RESERVED41;
	volatile	uint32_t	DIEPTSIZ4;
	volatile	uint32_t	DIEPDMA4;
	volatile	uint32_t	DTXFSTS4;
	volatile	uint32_t	RESERVED42;
	volatile	uint32_t	DIEPCTL5;
	volatile	uint32_t	RESERVED43;
	volatile	uint32_t	DIEPINT5;
	volatile	uint32_t	RESERVED44;
	volatile	uint32_t	DIEPTSIZ5;
	volatile	uint32_t	DIEPDMA5;
	volatile	uint32_t	DTXFSTS5;
	volatile	uint32_t	RESERVED45[3];
	volatile	uint32_t	DIEPINT6;
	volatile	uint32_t	RESERVED46;
	volatile	uint32_t	DIEPTSIZ6;
	volatile	uint32_t	DIEPDMA6;
	volatile	uint32_t	RESERVED47[4];
	volatile	uint32_t	DIEPINT7;
	volatile	uint32_t	RESERVED48;
	volatile	uint32_t	DIEPTSIZ7;
	volatile	uint32_t	DIEPDMA7;
	volatile	uint32_t	RESERVED49[4];
	volatile	uint32_t	DIEPINT8;
	volatile	uint32_t	RESERVED50;
	volatile	uint32_t	DIEPTSIZ8;
	volatile	uint32_t	DIEPDMA8;
	volatile	uint32_t	RESERVED51[58];
	volatile	uint32_t	DOEPCTL0;
	volatile	uint32_t	RESERVED52;
	volatile	uint32_t	DOEPINT0;
	volatile	uint32_t	RESERVED53;
	volatile	uint32_t	DOEPTSIZ0;
	volatile	uint32_t	DOEPDMA0;
	volatile	uint32_t	RESERVED54[2];
	volatile	uint32_t	DOEPCTL1;
	volatile	uint32_t	RESERVED55;
	volatile	uint32_t	DOEPINT1;
	volatile	uint32_t	RESERVED56;
	volatile	uint32_t	DOEPTSIZ1;
	volatile	uint32_t	DOEPDMA1;
	volatile	uint32_t	RESERVED57[2];
	volatile	uint32_t	DOEPCTL2;
	volatile	uint32_t	RESERVED58;
	volatile	uint32_t	DOEPINT2;
	volatile	uint32_t	RESERVED59;
	volatile	uint32_t	DOEPTSIZ2;
	volatile	uint32_t	DOEPDMA2;
	volatile	uint32_t	RESERVED60[2];
	volatile	uint32_t	DOEPCTL3;
	volatile	uint32_t	RESERVED61;
	volatile	uint32_t	DOEPINT3;
	volatile	uint32_t	RESERVED62;
	volatile	uint32_t	DOEPTSIZ3;
	volatile	uint32_t	DOEPDMA3;
	volatile	uint32_t	RESERVED63[2];
	volatile	uint32_t	DOEPCTL4;
	volatile	uint32_t	RESERVED64;
	volatile	uint32_t	DOEPINT4;
	volatile	uint32_t	RESERVED65;
	volatile	uint32_t	DOEPTSIZ4;
	volatile	uint32_t	DOEPDMA4;
	volatile	uint32_t	RESERVED66[2];
	volatile	uint32_t	DOEPCTL5;
	volatile	uint32_t	RESERVED67;
	volatile	uint32_t	DOEPINT5;
	volatile	uint32_t	RESERVED68;
	volatile	uint32_t	DOEPTSIZ5;
	volatile	uint32_t	DOEPDMA5;
	volatile	uint32_t	RESERVED69[2];
	volatile	uint32_t	DOEPCTL6;
	volatile	uint32_t	RESERVED70;
	volatile	uint32_t	DOEPINT6;
	volatile	uint32_t	RESERVED71;
	volatile	uint32_t	DOEPTSIZ6;
	volatile	uint32_t	DOEPDMA6;
	volatile	uint32_t	RESERVED72[2];
	volatile	uint32_t	DOEPCTL7;
	volatile	uint32_t	RESERVED73;
	volatile	uint32_t	DOEPINT7;
	volatile	uint32_t	RESERVED74;
	volatile	uint32_t	DOEPTSIZ7;
	volatile	uint32_t	DOEPDMA7;
	volatile	uint32_t	RESERVED75[2];
	volatile	uint32_t	DOEPCTL8;
	volatile	uint32_t	RESERVED76;
	volatile	uint32_t	DOEPINT8;
	volatile	uint32_t	RESERVED77;
	volatile	uint32_t	DOEPTSIZ8;
	volatile	uint32_t	DOEPDMA8;
	volatile	uint32_t	RESERVED78[122];
	volatile	uint32_t	PCGCCTL;
} OTG_HS_TypeDef;

#if (defined(__cplusplus))
#define	OTG_HS_NS	reinterpret_cast<OTG_HS_TypeDef *>(0x42040000u)
#define	OTG_HS_S	reinterpret_cast<OTG_HS_TypeDef *>(0x52040000u)

#else
#define	OTG_HS_NS	((OTG_HS_TypeDef *)0x42040000u)
#define	OTG_HS_S	((OTG_HS_TypeDef *)0x52040000u)
#endif

// GOTGCTL Configuration

#define	OTG_HS_GOTGCTL_CURMOD				(0x1u<<21)
#define	OTG_HS_GOTGCTL_OTGVER				(0x1u<<20)
#define	OTG_HS_GOTGCTL_BSVLD				(0x1u<<19)
#define	OTG_HS_GOTGCTL_ASVLD				(0x1u<<18)
#define	OTG_HS_GOTGCTL_DBCT					(0x1u<<17)
#define	OTG_HS_GOTGCTL_CIDSTS				(0x1u<<16)
#define	OTG_HS_GOTGCTL_EHEN					(0x1u<<12)
#define	OTG_HS_GOTGCTL_DHNPEN				(0x1u<<11)
#define	OTG_HS_GOTGCTL_HSHNPEN				(0x1u<<10)
#define	OTG_HS_GOTGCTL_HNPRQ				(0x1u<<9)
#define	OTG_HS_GOTGCTL_HNGSCS				(0x1u<<8)
#define	OTG_HS_GOTGCTL_BVALOVAL				(0x1u<<7)
#define	OTG_HS_GOTGCTL_BVALOEN				(0x1u<<6)
#define	OTG_HS_GOTGCTL_AVALOVAL				(0x1u<<5)
#define	OTG_HS_GOTGCTL_AVALOEN				(0x1u<<4)
#define	OTG_HS_GOTGCTL_VBVALOVAL			(0x1u<<3)
#define	OTG_HS_GOTGCTL_VBVALOEN				(0x1u<<2)
#define	OTG_HS_GOTGCTL_SRQ					(0x1u<<1)
#define	OTG_HS_GOTGCTL_SRQSCS				(0x1u<<0)

// GOTGINT Configuration

#define	OTG_HS_GOTGINT_DBCDNE				(0x1u<<19)
#define	OTG_HS_GOTGINT_ADTOCHG				(0x1u<<18)
#define	OTG_HS_GOTGINT_HNGDET				(0x1u<<17)
#define	OTG_HS_GOTGINT_HNSSCHG				(0x1u<<9)
#define	OTG_HS_GOTGINT_SRSSCHG				(0x1u<<8)
#define	OTG_HS_GOTGINT_SEDET				(0x1u<<2)

// GAHBCFG Configuration

#define	OTG_HS_GAHBCFG_PTXFELVL				(0x1u<<8)
#define	OTG_HS_GAHBCFG_TXFELVL				(0x1u<<7)
#define	OTG_HS_GAHBCFG_GINTMSK				(0x1u<<0)

// GUSBCFG Configuration

#define	OTG_HS_GUSBCFG_FDMOD				(0x1u<<30)
#define	OTG_HS_GUSBCFG_FHMOD				(0x1u<<29)
#define	OTG_HS_GUSBCFG_TSDPS				(0x1u<<22)
#define	OTG_HS_GUSBCFG_PHYLPC				(0x1u<<15)
#define	OTG_HS_GUSBCFG_TRDT					(0xFu<<10)
#define	OTG_HS_GUSBCFG_TRDT_0				(0x1u<<10)
#define	OTG_HS_GUSBCFG_HNPCAP				(0x1u<<9)
#define	OTG_HS_GUSBCFG_SRPCAP				(0x1u<<8)
#define	OTG_HS_GUSBCFG_PHYSEL				(0x1u<<6)
#define	OTG_HS_GUSBCFG_TOCAL				(0x7u<<0)
#define	OTG_HS_GUSBCFG_TOCAL_0				(0x1u<<0)

// GRSTCTL Configuration

#define	OTG_HS_GRSTCTL_AHBIDL				(0x1u<<31)
#define	OTG_HS_GRSTCTL_DMAREQ				(0x1u<<30)
#define	OTG_HS_GRSTCTL_TXFNUM				(0x1Fu<<6)
#define	OTG_HS_GRSTCTL_TXFNUM_0				(0x1u<<6)
#define	OTG_HS_GRSTCTL_TXFFLSH				(0x1u<<5)
#define	OTG_HS_GRSTCTL_RXFFLSH				(0x1u<<4)
#define	OTG_HS_GRSTCTL_FSRST				(0x1u<<2)
#define	OTG_HS_GRSTCTL_PSRST				(0x1u<<1)
#define	OTG_HS_GRSTCTL_CSRST				(0x1u<<0)

// GINTSTS Configuration

#define	OTG_HS_GINTSTS_WKUPINT				(0x1u<<31)
#define	OTG_HS_GINTSTS_SRQINT				(0x1u<<30)
#define	OTG_HS_GINTSTS_DISCINT				(0x1u<<29)
#define	OTG_HS_GINTSTS_CIDSCHG				(0x1u<<28)
#define	OTG_HS_GINTSTS_LPMINT				(0x1u<<27)
#define	OTG_HS_GINTSTS_PTXFE				(0x1u<<26)
#define	OTG_HS_GINTSTS_HCINT				(0x1u<<25)
#define	OTG_HS_GINTSTS_HPRTINT				(0x1u<<24)
#define	OTG_HS_GINTSTS_RSTDET				(0x1u<<23)
#define	OTG_HS_GINTSTS_DATAFSUSP			(0x1u<<22)
#define	OTG_HS_GINTSTS_IPXFR				(0x1u<<21)
#define	OTG_HS_GINTSTS_IISOIXFR				(0x1u<<20)
#define	OTG_HS_GINTSTS_OEPINT				(0x1u<<19)
#define	OTG_HS_GINTSTS_IEPINT				(0x1u<<18)
#define	OTG_HS_GINTSTS_EOPF					(0x1u<<15)
#define	OTG_HS_GINTSTS_ISOODRP				(0x1u<<14)
#define	OTG_HS_GINTSTS_ENUMDNE				(0x1u<<13)
#define	OTG_HS_GINTSTS_USBRST				(0x1u<<12)
#define	OTG_HS_GINTSTS_USBSUSP				(0x1u<<11)
#define	OTG_HS_GINTSTS_ESUSP				(0x1u<<10)
#define	OTG_HS_GINTSTS_GONAKEFF				(0x1u<<7)
#define	OTG_HS_GINTSTS_GINAKEFF				(0x1u<<6)
#define	OTG_HS_GINTSTS_NPTXFE				(0x1u<<5)
#define	OTG_HS_GINTSTS_RXFLVL				(0x1u<<4)
#define	OTG_HS_GINTSTS_SOF					(0x1u<<3)
#define	OTG_HS_GINTSTS_OTGINT				(0x1u<<2)
#define	OTG_HS_GINTSTS_MMIS					(0x1u<<1)
#define	OTG_HS_GINTSTS_CMOD					(0x1u<<0)

// GINTMSK Configuration

#define	OTG_HS_GINTMSK_WUIM					(0x1u<<31)
#define	OTG_HS_GINTMSK_SRQIM				(0x1u<<30)
#define	OTG_HS_GINTMSK_DISCINT				(0x1u<<29)
#define	OTG_HS_GINTMSK_CIDSCHGM				(0x1u<<28)
#define	OTG_HS_GINTMSK_LPMINTM				(0x1u<<27)
#define	OTG_HS_GINTMSK_PTXFEM				(0x1u<<26)
#define	OTG_HS_GINTMSK_HCIM					(0x1u<<25)
#define	OTG_HS_GINTMSK_PRTIM				(0x1u<<24)
#define	OTG_HS_GINTMSK_RSTDETM				(0x1u<<23)
#define	OTG_HS_GINTMSK_FSUSPM				(0x1u<<22)
#define	OTG_HS_GINTMSK_IPXFRM				(0x1u<<21)
#define	OTG_HS_GINTMSK_IISOIXFRM			(0x1u<<20)
#define	OTG_HS_GINTMSK_OEPINT				(0x1u<<19)
#define	OTG_HS_GINTMSK_IEPINT				(0x1u<<18)
#define	OTG_HS_GINTMSK_EOPFM				(0x1u<<15)
#define	OTG_HS_GINTMSK_ISOODRPM				(0x1u<<14)
#define	OTG_HS_GINTMSK_ENUMDNEM				(0x1u<<13)
#define	OTG_HS_GINTMSK_USBRST				(0x1u<<12)
#define	OTG_HS_GINTMSK_USBSUSPM				(0x1u<<11)
#define	OTG_HS_GINTMSK_ESUSPM				(0x1u<<10)
#define	OTG_HS_GINTMSK_GONAKEFFM			(0x1u<<7)
#define	OTG_HS_GINTMSK_GINAKEFFM			(0x1u<<6)
#define	OTG_HS_GINTMSK_NPTXFEM				(0x1u<<5)
#define	OTG_HS_GINTMSK_RXFLVLM				(0x1u<<4)
#define	OTG_HS_GINTMSK_SOFM					(0x1u<<3)
#define	OTG_HS_GINTMSK_OTGINT				(0x1u<<2)
#define	OTG_HS_GINTMSK_MMISM				(0x1u<<1)

// GRXSTSR Configuration

#define	OTG_HS_GRXSTSR_STSPHST				(0x1u<<27)
#define	OTG_HS_GRXSTSR_FRMNUM				(0xFu<<21)
#define	OTG_HS_GRXSTSR_FRMNUM_0				(0x1u<<21)
#define	OTG_HS_GRXSTSR_PKTSTS				(0xFu<<17)
#define	OTG_HS_GRXSTSR_PKTSTS_0				(0x1u<<17)
#define	OTG_HS_GRXSTSR_DPID					(0x3u<<15)
#define	OTG_HS_GRXSTSR_DPID_0				(0x1u<<15)
#define	OTG_HS_GRXSTSR_BCNT					(0x7FFu<<4)
#define	OTG_HS_GRXSTSR_BCNT_0				(0x1u<<4)
#define	OTG_HS_GRXSTSR_EPNUM				(0xFu<<0)
#define	OTG_HS_GRXSTSR_EPNUM_0				(0x1u<<0)

// GRXSTSP Configuration

#define	OTG_HS_GRXSTSP_STSPHST				(0x1u<<27)
#define	OTG_HS_GRXSTSP_FRMNUM				(0xFu<<21)
#define	OTG_HS_GRXSTSP_FRMNUM_0				(0x1u<<21)
#define	OTG_HS_GRXSTSP_PKTSTS				(0xFu<<17)
#define	OTG_HS_GRXSTSP_PKTSTS_0				(0x1u<<17)
#define	OTG_HS_GRXSTSP_DPID					(0x3u<<15)
#define	OTG_HS_GRXSTSP_DPID_0				(0x1u<<15)
#define	OTG_HS_GRXSTSP_BCNT					(0x7FFu<<4)
#define	OTG_HS_GRXSTSP_BCNT_0				(0x1u<<4)
#define	OTG_HS_GRXSTSP_EPNUM				(0xFu<<0)
#define	OTG_HS_GRXSTSP_EPNUM_0				(0x1u<<0)

// GRXFSIZ Configuration

#define	OTG_HS_GRXFSIZ_RXFD					(0xFFFFu<<0)
#define	OTG_HS_GRXFSIZ_RXFD_0				(0x1u<<0)

// HNPTXFSIZ Configuration

#define	OTG_HS_HNPTXFSIZ_NPTXFD				(0xFFFFu<<16)
#define	OTG_HS_HNPTXFSIZ_NPTXFD_0			(0x1u<<16)
#define	OTG_HS_HNPTXFSIZ_NPTXFSA			(0xFFFFu<<0)
#define	OTG_HS_HNPTXFSIZ_NPTXFSA_0			(0x1u<<0)

// HNPTXSTS Configuration

#define	OTG_HS_HNPTXSTS_NPTXQTOP			(0x7Fu<<24)
#define	OTG_HS_HNPTXSTS_NPTXQTOP_0			(0x1u<<24)
#define	OTG_HS_HNPTXSTS_NPTQXSAV			(0xFFu<<16)
#define	OTG_HS_HNPTXSTS_NPTQXSAV_0			(0x1u<<16)
#define	OTG_HS_HNPTXSTS_NPTXFSAV			(0xFFFFu<<0)
#define	OTG_HS_HNPTXSTS_NPTXFSAV_0			(0x1u<<0)

// GCCFG Configuration

#define	OTG_HS_GCCFG_VBDEN					(0x1u<<21)
#define	OTG_HS_GCCFG_SDEN					(0x1u<<20)
#define	OTG_HS_GCCFG_PDEN					(0x1u<<19)
#define	OTG_HS_GCCFG_DCDEN					(0x1u<<18)
#define	OTG_HS_GCCFG_BCDEN					(0x1u<<17)
#define	OTG_HS_GCCFG_PWRDWN					(0x1u<<16)
#define	OTG_HS_GCCFG_PS2DET					(0x1u<<3)
#define	OTG_HS_GCCFG_SDET					(0x1u<<2)
#define	OTG_HS_GCCFG_PDET					(0x1u<<1)
#define	OTG_HS_GCCFG_DCDET					(0x1u<<0)

// CID Configuration

#define	OTG_HS_CID_PRODUCT_ID				(0xFFFFFFFFu<<0)
#define	OTG_HS_CID_PRODUCT_ID_0				(0x1u<<0)

// GLPMCFG Configuration

#define	OTG_HS_GLPMCFG_ENBESL				(0x1u<<28)
#define	OTG_HS_GLPMCFG_LPMRCNTSTS			(0x7u<<25)
#define	OTG_HS_GLPMCFG_LPMRCNTSTS_0			(0x1u<<25)
#define	OTG_HS_GLPMCFG_SNDLPM				(0x1u<<24)
#define	OTG_HS_GLPMCFG_LPMRCNT				(0x7u<<21)
#define	OTG_HS_GLPMCFG_LPMRCNT_0			(0x1u<<21)
#define	OTG_HS_GLPMCFG_LPMCHIDX				(0xFu<<17)
#define	OTG_HS_GLPMCFG_LPMCHIDX_0			(0x1u<<17)
#define	OTG_HS_GLPMCFG_L1RSMOK				(0x1u<<16)
#define	OTG_HS_GLPMCFG_SLPSTS				(0x1u<<15)
#define	OTG_HS_GLPMCFG_LPMRSP				(0x3u<<13)
#define	OTG_HS_GLPMCFG_LPMRSP_0				(0x1u<<13)
#define	OTG_HS_GLPMCFG_L1DSEN				(0x1u<<12)
#define	OTG_HS_GLPMCFG_BESLTHRS				(0xFu<<8)
#define	OTG_HS_GLPMCFG_BESLTHRS_0			(0x1u<<8)
#define	OTG_HS_GLPMCFG_L1SSEN				(0x1u<<7)
#define	OTG_HS_GLPMCFG_REMWAKE				(0x1u<<6)
#define	OTG_HS_GLPMCFG_BESL					(0xFu<<2)
#define	OTG_HS_GLPMCFG_BESL_0				(0x1u<<2)
#define	OTG_HS_GLPMCFG_LPMACK				(0x1u<<1)
#define	OTG_HS_GLPMCFG_LPMEN				(0x1u<<0)

// HPTXFSIZ Configuration

#define	OTG_HS_HPTXFSIZ_PTXFSIZ				(0xFFFFu<<16)
#define	OTG_HS_HPTXFSIZ_PTXFSIZ_0			(0x1u<<16)
#define	OTG_HS_HPTXFSIZ_PTXSA				(0xFFFFu<<0)
#define	OTG_HS_HPTXFSIZ_PTXSA_0				(0x1u<<0)

// DIEPTXF1 Configuration

#define	OTG_HS_DIEPTXF1_INEPTXFD			(0xFFFFu<<16)
#define	OTG_HS_DIEPTXF1_INEPTXFD_0			(0x1u<<16)
#define	OTG_HS_DIEPTXF1_INEPTXSA			(0xFFFFu<<0)
#define	OTG_HS_DIEPTXF1_INEPTXSA_0			(0x1u<<0)

// DIEPTXF2 Configuration

#define	OTG_HS_DIEPTXF2_INEPTXFD			(0xFFFFu<<16)
#define	OTG_HS_DIEPTXF2_INEPTXFD_0			(0x1u<<16)
#define	OTG_HS_DIEPTXF2_INEPTXSA			(0xFFFFu<<0)
#define	OTG_HS_DIEPTXF2_INEPTXSA_0			(0x1u<<0)

// DIEPTXF3 Configuration

#define	OTG_HS_DIEPTXF3_INEPTXFD			(0xFFFFu<<16)
#define	OTG_HS_DIEPTXF3_INEPTXFD_0			(0x1u<<16)
#define	OTG_HS_DIEPTXF3_INEPTXSA			(0xFFFFu<<0)
#define	OTG_HS_DIEPTXF3_INEPTXSA_0			(0x1u<<0)

// DIEPTXF4 Configuration

#define	OTG_HS_DIEPTXF4_INEPTXFD			(0xFFFFu<<16)
#define	OTG_HS_DIEPTXF4_INEPTXFD_0			(0x1u<<16)
#define	OTG_HS_DIEPTXF4_INEPTXSA			(0xFFFFu<<0)
#define	OTG_HS_DIEPTXF4_INEPTXSA_0			(0x1u<<0)

// DIEPTXF5 Configuration

#define	OTG_HS_DIEPTXF5_INEPTXFD			(0xFFFFu<<16)
#define	OTG_HS_DIEPTXF5_INEPTXFD_0			(0x1u<<16)
#define	OTG_HS_DIEPTXF5_INEPTXSA			(0xFFFFu<<0)
#define	OTG_HS_DIEPTXF5_INEPTXSA_0			(0x1u<<0)

// DIEPTXF6 Configuration

#define	OTG_HS_DIEPTXF6_INEPTXFD			(0xFFFFu<<16)
#define	OTG_HS_DIEPTXF6_INEPTXFD_0			(0x1u<<16)
#define	OTG_HS_DIEPTXF6_INEPTXSA			(0xFFFFu<<0)
#define	OTG_HS_DIEPTXF6_INEPTXSA_0			(0x1u<<0)

// DIEPTXF7 Configuration

#define	OTG_HS_DIEPTXF7_INEPTXFD			(0xFFFFu<<16)
#define	OTG_HS_DIEPTXF7_INEPTXFD_0			(0x1u<<16)
#define	OTG_HS_DIEPTXF7_INEPTXSA			(0xFFFFu<<0)
#define	OTG_HS_DIEPTXF7_INEPTXSA_0			(0x1u<<0)

// DIEPTXF8 Configuration

#define	OTG_HS_DIEPTXF8_INEPTXFD			(0xFFFFu<<16)
#define	OTG_HS_DIEPTXF8_INEPTXFD_0			(0x1u<<16)
#define	OTG_HS_DIEPTXF8_INEPTXSA			(0xFFFFu<<0)
#define	OTG_HS_DIEPTXF8_INEPTXSA_0			(0x1u<<0)

// HCFG Configuration

#define	OTG_HS_HCFG_FSLSS					(0x1u<<2)
#define	OTG_HS_HCFG_FSLSPCS					(0x3u<<0)
#define	OTG_HS_HCFG_FSLSPCS_0				(0x1u<<0)

// HFIR Configuration

#define	OTG_HS_HFIR_RLDCTRL					(0x1u<<16)
#define	OTG_HS_HFIR_FRIVL					(0xFFFFu<<0)
#define	OTG_HS_HFIR_FRIVL_0					(0x1u<<0)

// HFNUM Configuration

#define	OTG_HS_HFNUM_FTREM					(0xFFFFu<<16)
#define	OTG_HS_HFNUM_FTREM_0				(0x1u<<16)
#define	OTG_HS_HFNUM_FRNUM					(0xFFFFu<<0)
#define	OTG_HS_HFNUM_FRNUM_0				(0x1u<<0)

// HPTXSTS Configuration

#define	OTG_HS_HPTXSTS_PTXQTOP				(0xFFu<<24)
#define	OTG_HS_HPTXSTS_PTXQTOP_0			(0x1u<<24)
#define	OTG_HS_HPTXSTS_PTXQSAV				(0xFFu<<16)
#define	OTG_HS_HPTXSTS_PTXQSAV_0			(0x1u<<16)
#define	OTG_HS_HPTXSTS_PTXFSAVL				(0xFFFFu<<0)
#define	OTG_HS_HPTXSTS_PTXFSAVL_0			(0x1u<<0)

// HAINT Configuration

#define	OTG_HS_HAINT_HAINT					(0xFFFFu<<0)
#define	OTG_HS_HAINT_HAINT_0				(0x1u<<0)

// HAINTMSK Configuration

#define	OTG_HS_HAINTMSK_HAINTM				(0xFFFFu<<0)
#define	OTG_HS_HAINTMSK_HAINTM_0			(0x1u<<0)

// HPRT Configuration

#define	OTG_HS_HPRT_PSPD					(0x3u<<17)
#define	OTG_HS_HPRT_PSPD_0					(0x1u<<17)
#define	OTG_HS_HPRT_PTCTL					(0xFu<<13)
#define	OTG_HS_HPRT_PTCTL_0					(0x1u<<13)
#define	OTG_HS_HPRT_PPWR					(0x1u<<12)
#define	OTG_HS_HPRT_PLSTS					(0x3u<<10)
#define	OTG_HS_HPRT_PLSTS_0					(0x1u<<10)
#define	OTG_HS_HPRT_PRST					(0x1u<<8)
#define	OTG_HS_HPRT_PSUSP					(0x1u<<7)
#define	OTG_HS_HPRT_PRES					(0x1u<<6)
#define	OTG_HS_HPRT_POCCHNG					(0x1u<<5)
#define	OTG_HS_HPRT_POCA					(0x1u<<4)
#define	OTG_HS_HPRT_PENCHNG					(0x1u<<3)
#define	OTG_HS_HPRT_PENA					(0x1u<<2)
#define	OTG_HS_HPRT_PCDET					(0x1u<<1)
#define	OTG_HS_HPRT_PCSTS					(0x1u<<0)

// HCCHAR0 Configuration

#define	OTG_HS_HCCHAR0_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR0_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR0_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR0_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR0_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR0_MCNT					(0x3u<<20)
#define	OTG_HS_HCCHAR0_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR0_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR0_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR0_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR0_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR0_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR0_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR0_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR0_MPSIZ_0				(0x1u<<0)

// HCSPLT0 Configuration

#define	OTG_HS_HCSPLT0_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT0_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT0_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT0_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT0_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT0_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT0_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT0_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT0_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT0_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT0_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT0_XACTPOS_B_0X1		(0x1u<<14)

// HCINT0 Configuration

#define	OTG_HS_HCINT0_DTERR					(0x1u<<10)
#define	OTG_HS_HCINT0_FRMOR					(0x1u<<9)
#define	OTG_HS_HCINT0_BBERR					(0x1u<<8)
#define	OTG_HS_HCINT0_TXERR					(0x1u<<7)
#define	OTG_HS_HCINT0_ACK					(0x1u<<5)
#define	OTG_HS_HCINT0_NAK					(0x1u<<4)
#define	OTG_HS_HCINT0_STALL					(0x1u<<3)
#define	OTG_HS_HCINT0_CHH					(0x1u<<1)
#define	OTG_HS_HCINT0_XFRC					(0x1u<<0)

// HCINTMSK0 Configuration

#define	OTG_HS_HCINTMSK0_DTERRM				(0x1u<<10)
#define	OTG_HS_HCINTMSK0_FRMORM				(0x1u<<9)
#define	OTG_HS_HCINTMSK0_BBERRM				(0x1u<<8)
#define	OTG_HS_HCINTMSK0_TXERRM				(0x1u<<7)
#define	OTG_HS_HCINTMSK0_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK0_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK0_STALLM				(0x1u<<3)
#define	OTG_HS_HCINTMSK0_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK0_XFRCM				(0x1u<<0)

// HCTSIZ0 Configuration

#define	OTG_HS_HCTSIZ0_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ0_DPID					(0x3u<<29)
#define	OTG_HS_HCTSIZ0_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ0_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ0_PKTCNT_0				(0x1u<<19)
#define	OTG_HS_HCTSIZ0_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ0_XFRSIZ_0				(0x1u<<0)

// HCDMA0 Configuration

#define	OTG_HS_HCDMA0_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA0_DMAADDR_0				(0x1u<<0)

// HCCHAR1 Configuration

#define	OTG_HS_HCCHAR1_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR1_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR1_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR1_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR1_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR1_MCNT					(0x3u<<20)
#define	OTG_HS_HCCHAR1_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR1_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR1_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR1_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR1_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR1_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR1_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR1_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR1_MPSIZ_0				(0x1u<<0)

// HCSPLT1 Configuration

#define	OTG_HS_HCSPLT1_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT1_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT1_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT1_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT1_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT1_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT1_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT1_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT1_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT1_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT1_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT1_XACTPOS_B_0X1		(0x1u<<14)

// HCINT1_DEVICE Configuration

#define	OTG_HS_HCINT1_DEVICE_DTERR			(0x1u<<10)
#define	OTG_HS_HCINT1_DEVICE_FRMOR			(0x1u<<9)
#define	OTG_HS_HCINT1_DEVICE_BBERR			(0x1u<<8)
#define	OTG_HS_HCINT1_DEVICE_TXERR			(0x1u<<7)
#define	OTG_HS_HCINT1_DEVICE_ACK			(0x1u<<5)
#define	OTG_HS_HCINT1_DEVICE_NAK			(0x1u<<4)
#define	OTG_HS_HCINT1_DEVICE_STALL			(0x1u<<3)
#define	OTG_HS_HCINT1_DEVICE_CHH			(0x1u<<1)
#define	OTG_HS_HCINT1_DEVICE_XFRC			(0x1u<<0)

// HCINTMSK1 Configuration

#define	OTG_HS_HCINTMSK1_DTERRM				(0x1u<<10)
#define	OTG_HS_HCINTMSK1_FRMORM				(0x1u<<9)
#define	OTG_HS_HCINTMSK1_BBERRM				(0x1u<<8)
#define	OTG_HS_HCINTMSK1_TXERRM				(0x1u<<7)
#define	OTG_HS_HCINTMSK1_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK1_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK1_STALLM				(0x1u<<3)
#define	OTG_HS_HCINTMSK1_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK1_XFRCM				(0x1u<<0)

// HCTSIZ1 Configuration

#define	OTG_HS_HCTSIZ1_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ1_DPID					(0x3u<<29)
#define	OTG_HS_HCTSIZ1_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ1_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ1_PKTCNT_0				(0x1u<<19)
#define	OTG_HS_HCTSIZ1_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ1_XFRSIZ_0				(0x1u<<0)

// HCDMA1 Configuration

#define	OTG_HS_HCDMA1_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA1_DMAADDR_0				(0x1u<<0)

// HCCHAR2 Configuration

#define	OTG_HS_HCCHAR2_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR2_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR2_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR2_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR2_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR2_MCNT					(0x3u<<20)
#define	OTG_HS_HCCHAR2_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR2_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR2_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR2_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR2_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR2_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR2_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR2_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR2_MPSIZ_0				(0x1u<<0)

// HCSPLT2 Configuration

#define	OTG_HS_HCSPLT2_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT2_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT2_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT2_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT2_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT2_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT2_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT2_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT2_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT2_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT2_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT2_XACTPOS_B_0X1		(0x1u<<14)

// HCINT2 Configuration

#define	OTG_HS_HCINT2_DTERR					(0x1u<<10)
#define	OTG_HS_HCINT2_FRMOR					(0x1u<<9)
#define	OTG_HS_HCINT2_BBERR					(0x1u<<8)
#define	OTG_HS_HCINT2_TXERR					(0x1u<<7)
#define	OTG_HS_HCINT2_ACK					(0x1u<<5)
#define	OTG_HS_HCINT2_NAK					(0x1u<<4)
#define	OTG_HS_HCINT2_STALL					(0x1u<<3)
#define	OTG_HS_HCINT2_CHH					(0x1u<<1)
#define	OTG_HS_HCINT2_XFRC					(0x1u<<0)

// HCINTMSK2 Configuration

#define	OTG_HS_HCINTMSK2_DTERRM				(0x1u<<10)
#define	OTG_HS_HCINTMSK2_FRMORM				(0x1u<<9)
#define	OTG_HS_HCINTMSK2_BBERRM				(0x1u<<8)
#define	OTG_HS_HCINTMSK2_TXERRM				(0x1u<<7)
#define	OTG_HS_HCINTMSK2_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK2_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK2_STALLM				(0x1u<<3)
#define	OTG_HS_HCINTMSK2_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK2_XFRCM				(0x1u<<0)

// HCTSIZ2 Configuration

#define	OTG_HS_HCTSIZ2_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ2_DPID					(0x3u<<29)
#define	OTG_HS_HCTSIZ2_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ2_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ2_PKTCNT_0				(0x1u<<19)
#define	OTG_HS_HCTSIZ2_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ2_XFRSIZ_0				(0x1u<<0)

// HCDMA2 Configuration

#define	OTG_HS_HCDMA2_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA2_DMAADDR_0				(0x1u<<0)

// HCCHAR3 Configuration

#define	OTG_HS_HCCHAR3_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR3_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR3_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR3_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR3_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR3_MCNT					(0x3u<<20)
#define	OTG_HS_HCCHAR3_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR3_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR3_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR3_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR3_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR3_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR3_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR3_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR3_MPSIZ_0				(0x1u<<0)

// HCSPLT3 Configuration

#define	OTG_HS_HCSPLT3_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT3_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT3_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT3_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT3_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT3_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT3_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT3_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT3_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT3_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT3_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT3_XACTPOS_B_0X1		(0x1u<<14)

// HCINT3 Configuration

#define	OTG_HS_HCINT3_DTERR					(0x1u<<10)
#define	OTG_HS_HCINT3_FRMOR					(0x1u<<9)
#define	OTG_HS_HCINT3_BBERR					(0x1u<<8)
#define	OTG_HS_HCINT3_TXERR					(0x1u<<7)
#define	OTG_HS_HCINT3_ACK					(0x1u<<5)
#define	OTG_HS_HCINT3_NAK					(0x1u<<4)
#define	OTG_HS_HCINT3_STALL					(0x1u<<3)
#define	OTG_HS_HCINT3_CHH					(0x1u<<1)
#define	OTG_HS_HCINT3_XFRC					(0x1u<<0)

// HCINTMSK3 Configuration

#define	OTG_HS_HCINTMSK3_DTERRM				(0x1u<<10)
#define	OTG_HS_HCINTMSK3_FRMORM				(0x1u<<9)
#define	OTG_HS_HCINTMSK3_BBERRM				(0x1u<<8)
#define	OTG_HS_HCINTMSK3_TXERRM				(0x1u<<7)
#define	OTG_HS_HCINTMSK3_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK3_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK3_STALLM				(0x1u<<3)
#define	OTG_HS_HCINTMSK3_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK3_XFRCM				(0x1u<<0)

// HCTSIZ3 Configuration

#define	OTG_HS_HCTSIZ3_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ3_DPID					(0x3u<<29)
#define	OTG_HS_HCTSIZ3_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ3_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ3_PKTCNT_0				(0x1u<<19)
#define	OTG_HS_HCTSIZ3_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ3_XFRSIZ_0				(0x1u<<0)

// HCDMA3 Configuration

#define	OTG_HS_HCDMA3_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA3_DMAADDR_0				(0x1u<<0)

// HCCHAR4 Configuration

#define	OTG_HS_HCCHAR4_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR4_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR4_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR4_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR4_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR4_MCNT					(0x3u<<20)
#define	OTG_HS_HCCHAR4_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR4_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR4_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR4_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR4_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR4_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR4_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR4_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR4_MPSIZ_0				(0x1u<<0)

// HCSPLT4 Configuration

#define	OTG_HS_HCSPLT4_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT4_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT4_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT4_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT4_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT4_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT4_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT4_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT4_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT4_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT4_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT4_XACTPOS_B_0X1		(0x1u<<14)

// HCINT4 Configuration

#define	OTG_HS_HCINT4_DTERR					(0x1u<<10)
#define	OTG_HS_HCINT4_FRMOR					(0x1u<<9)
#define	OTG_HS_HCINT4_BBERR					(0x1u<<8)
#define	OTG_HS_HCINT4_TXERR					(0x1u<<7)
#define	OTG_HS_HCINT4_ACK					(0x1u<<5)
#define	OTG_HS_HCINT4_NAK					(0x1u<<4)
#define	OTG_HS_HCINT4_STALL					(0x1u<<3)
#define	OTG_HS_HCINT4_CHH					(0x1u<<1)
#define	OTG_HS_HCINT4_XFRC					(0x1u<<0)

// HCINTMSK4 Configuration

#define	OTG_HS_HCINTMSK4_DTERRM				(0x1u<<10)
#define	OTG_HS_HCINTMSK4_FRMORM				(0x1u<<9)
#define	OTG_HS_HCINTMSK4_BBERRM				(0x1u<<8)
#define	OTG_HS_HCINTMSK4_TXERRM				(0x1u<<7)
#define	OTG_HS_HCINTMSK4_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK4_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK4_STALLM				(0x1u<<3)
#define	OTG_HS_HCINTMSK4_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK4_XFRCM				(0x1u<<0)

// HCTSIZ4 Configuration

#define	OTG_HS_HCTSIZ4_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ4_DPID					(0x3u<<29)
#define	OTG_HS_HCTSIZ4_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ4_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ4_PKTCNT_0				(0x1u<<19)
#define	OTG_HS_HCTSIZ4_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ4_XFRSIZ_0				(0x1u<<0)

// HCDMA4 Configuration

#define	OTG_HS_HCDMA4_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA4_DMAADDR_0				(0x1u<<0)

// HCCHAR5 Configuration

#define	OTG_HS_HCCHAR5_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR5_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR5_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR5_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR5_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR5_MCNT					(0x3u<<20)
#define	OTG_HS_HCCHAR5_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR5_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR5_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR5_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR5_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR5_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR5_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR5_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR5_MPSIZ_0				(0x1u<<0)

// HCSPLT5 Configuration

#define	OTG_HS_HCSPLT5_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT5_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT5_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT5_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT5_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT5_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT5_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT5_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT5_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT5_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT5_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT5_XACTPOS_B_0X1		(0x1u<<14)

// HCINT5 Configuration

#define	OTG_HS_HCINT5_DTERR					(0x1u<<10)
#define	OTG_HS_HCINT5_FRMOR					(0x1u<<9)
#define	OTG_HS_HCINT5_BBERR					(0x1u<<8)
#define	OTG_HS_HCINT5_TXERR					(0x1u<<7)
#define	OTG_HS_HCINT5_ACK					(0x1u<<5)
#define	OTG_HS_HCINT5_NAK					(0x1u<<4)
#define	OTG_HS_HCINT5_STALL					(0x1u<<3)
#define	OTG_HS_HCINT5_CHH					(0x1u<<1)
#define	OTG_HS_HCINT5_XFRC					(0x1u<<0)

// HCINTMSK5 Configuration

#define	OTG_HS_HCINTMSK5_DTERRM				(0x1u<<10)
#define	OTG_HS_HCINTMSK5_FRMORM				(0x1u<<9)
#define	OTG_HS_HCINTMSK5_BBERRM				(0x1u<<8)
#define	OTG_HS_HCINTMSK5_TXERRM				(0x1u<<7)
#define	OTG_HS_HCINTMSK5_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK5_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK5_STALLM				(0x1u<<3)
#define	OTG_HS_HCINTMSK5_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK5_XFRCM				(0x1u<<0)

// HCTSIZ5 Configuration

#define	OTG_HS_HCTSIZ5_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ5_DPID					(0x3u<<29)
#define	OTG_HS_HCTSIZ5_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ5_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ5_PKTCNT_0				(0x1u<<19)
#define	OTG_HS_HCTSIZ5_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ5_XFRSIZ_0				(0x1u<<0)

// HCDMA5 Configuration

#define	OTG_HS_HCDMA5_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA5_DMAADDR_0				(0x1u<<0)

// HCCHAR6 Configuration

#define	OTG_HS_HCCHAR6_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR6_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR6_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR6_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR6_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR6_MCNT					(0x3u<<20)
#define	OTG_HS_HCCHAR6_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR6_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR6_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR6_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR6_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR6_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR6_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR6_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR6_MPSIZ_0				(0x1u<<0)

// HCSPLT6 Configuration

#define	OTG_HS_HCSPLT6_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT6_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT6_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT6_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT6_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT6_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT6_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT6_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT6_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT6_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT6_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT6_XACTPOS_B_0X1		(0x1u<<14)

// HCINT6 Configuration

#define	OTG_HS_HCINT6_DTERR					(0x1u<<10)
#define	OTG_HS_HCINT6_FRMOR					(0x1u<<9)
#define	OTG_HS_HCINT6_BBERR					(0x1u<<8)
#define	OTG_HS_HCINT6_TXERR					(0x1u<<7)
#define	OTG_HS_HCINT6_ACK					(0x1u<<5)
#define	OTG_HS_HCINT6_NAK					(0x1u<<4)
#define	OTG_HS_HCINT6_STALL					(0x1u<<3)
#define	OTG_HS_HCINT6_CHH					(0x1u<<1)
#define	OTG_HS_HCINT6_XFRC					(0x1u<<0)

// HCINTMSK6 Configuration

#define	OTG_HS_HCINTMSK6_DTERRM				(0x1u<<10)
#define	OTG_HS_HCINTMSK6_FRMORM				(0x1u<<9)
#define	OTG_HS_HCINTMSK6_BBERRM				(0x1u<<8)
#define	OTG_HS_HCINTMSK6_TXERRM				(0x1u<<7)
#define	OTG_HS_HCINTMSK6_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK6_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK6_STALLM				(0x1u<<3)
#define	OTG_HS_HCINTMSK6_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK6_XFRCM				(0x1u<<0)

// HCTSIZ6 Configuration

#define	OTG_HS_HCTSIZ6_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ6_DPID					(0x3u<<29)
#define	OTG_HS_HCTSIZ6_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ6_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ6_PKTCNT_0				(0x1u<<19)
#define	OTG_HS_HCTSIZ6_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ6_XFRSIZ_0				(0x1u<<0)

// HCDMA6 Configuration

#define	OTG_HS_HCDMA6_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA6_DMAADDR_0				(0x1u<<0)

// HCCHAR7 Configuration

#define	OTG_HS_HCCHAR7_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR7_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR7_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR7_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR7_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR7_MCNT					(0x3u<<20)
#define	OTG_HS_HCCHAR7_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR7_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR7_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR7_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR7_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR7_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR7_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR7_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR7_MPSIZ_0				(0x1u<<0)

// HCSPLT7 Configuration

#define	OTG_HS_HCSPLT7_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT7_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT7_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT7_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT7_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT7_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT7_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT7_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT7_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT7_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT7_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT7_XACTPOS_B_0X1		(0x1u<<14)

// HCINT7 Configuration

#define	OTG_HS_HCINT7_DTERR					(0x1u<<10)
#define	OTG_HS_HCINT7_FRMOR					(0x1u<<9)
#define	OTG_HS_HCINT7_BBERR					(0x1u<<8)
#define	OTG_HS_HCINT7_TXERR					(0x1u<<7)
#define	OTG_HS_HCINT7_ACK					(0x1u<<5)
#define	OTG_HS_HCINT7_NAK					(0x1u<<4)
#define	OTG_HS_HCINT7_STALL					(0x1u<<3)
#define	OTG_HS_HCINT7_CHH					(0x1u<<1)
#define	OTG_HS_HCINT7_XFRC					(0x1u<<0)

// HCINTMSK7 Configuration

#define	OTG_HS_HCINTMSK7_DTERRM				(0x1u<<10)
#define	OTG_HS_HCINTMSK7_FRMORM				(0x1u<<9)
#define	OTG_HS_HCINTMSK7_BBERRM				(0x1u<<8)
#define	OTG_HS_HCINTMSK7_TXERRM				(0x1u<<7)
#define	OTG_HS_HCINTMSK7_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK7_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK7_STALLM				(0x1u<<3)
#define	OTG_HS_HCINTMSK7_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK7_XFRCM				(0x1u<<0)

// HCTSIZ7 Configuration

#define	OTG_HS_HCTSIZ7_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ7_DPID					(0x3u<<29)
#define	OTG_HS_HCTSIZ7_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ7_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ7_PKTCNT_0				(0x1u<<19)
#define	OTG_HS_HCTSIZ7_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ7_XFRSIZ_0				(0x1u<<0)

// HCDMA7 Configuration

#define	OTG_HS_HCDMA7_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA7_DMAADDR_0				(0x1u<<0)

// HCCHAR8 Configuration

#define	OTG_HS_HCCHAR8_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR8_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR8_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR8_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR8_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR8_MCNT					(0x3u<<20)
#define	OTG_HS_HCCHAR8_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR8_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR8_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR8_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR8_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR8_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR8_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR8_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR8_MPSIZ_0				(0x1u<<0)

// HCSPLT8 Configuration

#define	OTG_HS_HCSPLT8_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT8_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT8_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT8_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT8_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT8_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT8_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT8_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT8_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT8_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT8_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT8_XACTPOS_B_0X1		(0x1u<<14)

// HCINT8 Configuration

#define	OTG_HS_HCINT8_DTERR					(0x1u<<10)
#define	OTG_HS_HCINT8_FRMOR					(0x1u<<9)
#define	OTG_HS_HCINT8_BBERR					(0x1u<<8)
#define	OTG_HS_HCINT8_TXERR					(0x1u<<7)
#define	OTG_HS_HCINT8_ACK					(0x1u<<5)
#define	OTG_HS_HCINT8_NAK					(0x1u<<4)
#define	OTG_HS_HCINT8_STALL					(0x1u<<3)
#define	OTG_HS_HCINT8_CHH					(0x1u<<1)
#define	OTG_HS_HCINT8_XFRC					(0x1u<<0)

// HCINTMSK8 Configuration

#define	OTG_HS_HCINTMSK8_DTERRM				(0x1u<<10)
#define	OTG_HS_HCINTMSK8_FRMORM				(0x1u<<9)
#define	OTG_HS_HCINTMSK8_BBERRM				(0x1u<<8)
#define	OTG_HS_HCINTMSK8_TXERRM				(0x1u<<7)
#define	OTG_HS_HCINTMSK8_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK8_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK8_STALLM				(0x1u<<3)
#define	OTG_HS_HCINTMSK8_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK8_XFRCM				(0x1u<<0)

// HCTSIZ8 Configuration

#define	OTG_HS_HCTSIZ8_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ8_DPID					(0x3u<<29)
#define	OTG_HS_HCTSIZ8_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ8_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ8_PKTCNT_0				(0x1u<<19)
#define	OTG_HS_HCTSIZ8_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ8_XFRSIZ_0				(0x1u<<0)

// HCDMA8 Configuration

#define	OTG_HS_HCDMA8_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA8_DMAADDR_0				(0x1u<<0)

// HCCHAR9 Configuration

#define	OTG_HS_HCCHAR9_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR9_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR9_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR9_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR9_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR9_MCNT					(0x3u<<20)
#define	OTG_HS_HCCHAR9_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR9_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR9_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR9_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR9_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR9_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR9_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR9_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR9_MPSIZ_0				(0x1u<<0)

// HCSPLT9 Configuration

#define	OTG_HS_HCSPLT9_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT9_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT9_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT9_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT9_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT9_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT9_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT9_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT9_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT9_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT9_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT9_XACTPOS_B_0X1		(0x1u<<14)

// HCINT9 Configuration

#define	OTG_HS_HCINT9_DTERR					(0x1u<<10)
#define	OTG_HS_HCINT9_FRMOR					(0x1u<<9)
#define	OTG_HS_HCINT9_BBERR					(0x1u<<8)
#define	OTG_HS_HCINT9_TXERR					(0x1u<<7)
#define	OTG_HS_HCINT9_ACK					(0x1u<<5)
#define	OTG_HS_HCINT9_NAK					(0x1u<<4)
#define	OTG_HS_HCINT9_STALL					(0x1u<<3)
#define	OTG_HS_HCINT9_CHH					(0x1u<<1)
#define	OTG_HS_HCINT9_XFRC					(0x1u<<0)

// HCINTMSK9 Configuration

#define	OTG_HS_HCINTMSK9_DTERRM				(0x1u<<10)
#define	OTG_HS_HCINTMSK9_FRMORM				(0x1u<<9)
#define	OTG_HS_HCINTMSK9_BBERRM				(0x1u<<8)
#define	OTG_HS_HCINTMSK9_TXERRM				(0x1u<<7)
#define	OTG_HS_HCINTMSK9_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK9_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK9_STALLM				(0x1u<<3)
#define	OTG_HS_HCINTMSK9_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK9_XFRCM				(0x1u<<0)

// HCTSIZ9 Configuration

#define	OTG_HS_HCTSIZ9_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ9_DPID					(0x3u<<29)
#define	OTG_HS_HCTSIZ9_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ9_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ9_PKTCNT_0				(0x1u<<19)
#define	OTG_HS_HCTSIZ9_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ9_XFRSIZ_0				(0x1u<<0)

// HCDMA9 Configuration

#define	OTG_HS_HCDMA9_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA9_DMAADDR_0				(0x1u<<0)

// HCCHAR10 Configuration

#define	OTG_HS_HCCHAR10_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR10_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR10_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR10_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR10_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR10_MCNT				(0x3u<<20)
#define	OTG_HS_HCCHAR10_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR10_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR10_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR10_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR10_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR10_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR10_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR10_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR10_MPSIZ_0				(0x1u<<0)

// HCSPLT10 Configuration

#define	OTG_HS_HCSPLT10_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT10_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT10_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT10_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT10_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT10_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT10_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT10_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT10_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT10_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT10_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT10_XACTPOS_B_0X1		(0x1u<<14)

// HCINT10 Configuration

#define	OTG_HS_HCINT10_DTERR				(0x1u<<10)
#define	OTG_HS_HCINT10_FRMOR				(0x1u<<9)
#define	OTG_HS_HCINT10_BBERR				(0x1u<<8)
#define	OTG_HS_HCINT10_TXERR				(0x1u<<7)
#define	OTG_HS_HCINT10_ACK					(0x1u<<5)
#define	OTG_HS_HCINT10_NAK					(0x1u<<4)
#define	OTG_HS_HCINT10_STALL				(0x1u<<3)
#define	OTG_HS_HCINT10_CHH					(0x1u<<1)
#define	OTG_HS_HCINT10_XFRC					(0x1u<<0)

// HCINTMSK10 Configuration

#define	OTG_HS_HCINTMSK10_DTERRM			(0x1u<<10)
#define	OTG_HS_HCINTMSK10_FRMORM			(0x1u<<9)
#define	OTG_HS_HCINTMSK10_BBERRM			(0x1u<<8)
#define	OTG_HS_HCINTMSK10_TXERRM			(0x1u<<7)
#define	OTG_HS_HCINTMSK10_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK10_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK10_STALLM			(0x1u<<3)
#define	OTG_HS_HCINTMSK10_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK10_XFRCM				(0x1u<<0)

// HCTSIZ10 Configuration

#define	OTG_HS_HCTSIZ10_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ10_DPID				(0x3u<<29)
#define	OTG_HS_HCTSIZ10_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ10_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ10_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_HCTSIZ10_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ10_XFRSIZ_0			(0x1u<<0)

// HCDMA10 Configuration

#define	OTG_HS_HCDMA10_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA10_DMAADDR_0			(0x1u<<0)

// HCCHAR11 Configuration

#define	OTG_HS_HCCHAR11_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR11_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR11_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR11_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR11_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR11_MCNT				(0x3u<<20)
#define	OTG_HS_HCCHAR11_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR11_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR11_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR11_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR11_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR11_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR11_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR11_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR11_MPSIZ_0				(0x1u<<0)

// HCSPLT11 Configuration

#define	OTG_HS_HCSPLT11_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT11_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT11_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT11_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT11_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT11_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT11_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT11_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT11_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT11_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT11_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT11_XACTPOS_B_0X1		(0x1u<<14)

// HCINT11 Configuration

#define	OTG_HS_HCINT11_DTERR				(0x1u<<10)
#define	OTG_HS_HCINT11_FRMOR				(0x1u<<9)
#define	OTG_HS_HCINT11_BBERR				(0x1u<<8)
#define	OTG_HS_HCINT11_TXERR				(0x1u<<7)
#define	OTG_HS_HCINT11_ACK					(0x1u<<5)
#define	OTG_HS_HCINT11_NAK					(0x1u<<4)
#define	OTG_HS_HCINT11_STALL				(0x1u<<3)
#define	OTG_HS_HCINT11_CHH					(0x1u<<1)
#define	OTG_HS_HCINT11_XFRC					(0x1u<<0)

// HCINTMSK11 Configuration

#define	OTG_HS_HCINTMSK11_DTERRM			(0x1u<<10)
#define	OTG_HS_HCINTMSK11_FRMORM			(0x1u<<9)
#define	OTG_HS_HCINTMSK11_BBERRM			(0x1u<<8)
#define	OTG_HS_HCINTMSK11_TXERRM			(0x1u<<7)
#define	OTG_HS_HCINTMSK11_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK11_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK11_STALLM			(0x1u<<3)
#define	OTG_HS_HCINTMSK11_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK11_XFRCM				(0x1u<<0)

// HCTSIZ11 Configuration

#define	OTG_HS_HCTSIZ11_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ11_DPID				(0x3u<<29)
#define	OTG_HS_HCTSIZ11_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ11_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ11_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_HCTSIZ11_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ11_XFRSIZ_0			(0x1u<<0)

// HCDMA11 Configuration

#define	OTG_HS_HCDMA11_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA11_DMAADDR_0			(0x1u<<0)

// HCCHAR12 Configuration

#define	OTG_HS_HCCHAR12_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR12_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR12_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR12_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR12_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR12_MCNT				(0x3u<<20)
#define	OTG_HS_HCCHAR12_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR12_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR12_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR12_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR12_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR12_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR12_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR12_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR12_MPSIZ_0				(0x1u<<0)

// HCSPLT12 Configuration

#define	OTG_HS_HCSPLT12_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT12_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT12_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT12_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT12_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT12_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT12_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT12_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT12_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT12_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT12_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT12_XACTPOS_B_0X1		(0x1u<<14)

// HCINT12 Configuration

#define	OTG_HS_HCINT12_DTERR				(0x1u<<10)
#define	OTG_HS_HCINT12_FRMOR				(0x1u<<9)
#define	OTG_HS_HCINT12_BBERR				(0x1u<<8)
#define	OTG_HS_HCINT12_TXERR				(0x1u<<7)
#define	OTG_HS_HCINT12_ACK					(0x1u<<5)
#define	OTG_HS_HCINT12_NAK					(0x1u<<4)
#define	OTG_HS_HCINT12_STALL				(0x1u<<3)
#define	OTG_HS_HCINT12_CHH					(0x1u<<1)
#define	OTG_HS_HCINT12_XFRC					(0x1u<<0)

// HCINTMSK12 Configuration

#define	OTG_HS_HCINTMSK12_DTERRM			(0x1u<<10)
#define	OTG_HS_HCINTMSK12_FRMORM			(0x1u<<9)
#define	OTG_HS_HCINTMSK12_BBERRM			(0x1u<<8)
#define	OTG_HS_HCINTMSK12_TXERRM			(0x1u<<7)
#define	OTG_HS_HCINTMSK12_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK12_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK12_STALLM			(0x1u<<3)
#define	OTG_HS_HCINTMSK12_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK12_XFRCM				(0x1u<<0)

// HCTSIZ12 Configuration

#define	OTG_HS_HCTSIZ12_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ12_DPID				(0x3u<<29)
#define	OTG_HS_HCTSIZ12_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ12_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ12_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_HCTSIZ12_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ12_XFRSIZ_0			(0x1u<<0)

// HCDMA12 Configuration

#define	OTG_HS_HCDMA12_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA12_DMAADDR_0			(0x1u<<0)

// HCCHAR13 Configuration

#define	OTG_HS_HCCHAR13_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR13_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR13_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR13_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR13_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR13_MCNT				(0x3u<<20)
#define	OTG_HS_HCCHAR13_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR13_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR13_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR13_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR13_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR13_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR13_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR13_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR13_MPSIZ_0				(0x1u<<0)

// HCSPLT13 Configuration

#define	OTG_HS_HCSPLT13_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT13_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT13_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT13_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT13_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT13_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT13_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT13_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT13_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT13_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT13_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT13_XACTPOS_B_0X1		(0x1u<<14)

// HCINT13 Configuration

#define	OTG_HS_HCINT13_DTERR				(0x1u<<10)
#define	OTG_HS_HCINT13_FRMOR				(0x1u<<9)
#define	OTG_HS_HCINT13_BBERR				(0x1u<<8)
#define	OTG_HS_HCINT13_TXERR				(0x1u<<7)
#define	OTG_HS_HCINT13_ACK					(0x1u<<5)
#define	OTG_HS_HCINT13_NAK					(0x1u<<4)
#define	OTG_HS_HCINT13_STALL				(0x1u<<3)
#define	OTG_HS_HCINT13_CHH					(0x1u<<1)
#define	OTG_HS_HCINT13_XFRC					(0x1u<<0)

// HCINTMSK13 Configuration

#define	OTG_HS_HCINTMSK13_DTERRM			(0x1u<<10)
#define	OTG_HS_HCINTMSK13_FRMORM			(0x1u<<9)
#define	OTG_HS_HCINTMSK13_BBERRM			(0x1u<<8)
#define	OTG_HS_HCINTMSK13_TXERRM			(0x1u<<7)
#define	OTG_HS_HCINTMSK13_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK13_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK13_STALLM			(0x1u<<3)
#define	OTG_HS_HCINTMSK13_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK13_XFRCM				(0x1u<<0)

// HCTSIZ13 Configuration

#define	OTG_HS_HCTSIZ13_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ13_DPID				(0x3u<<29)
#define	OTG_HS_HCTSIZ13_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ13_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ13_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_HCTSIZ13_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ13_XFRSIZ_0			(0x1u<<0)

// HCDMA13 Configuration

#define	OTG_HS_HCDMA13_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA13_DMAADDR_0			(0x1u<<0)

// HCCHAR14 Configuration

#define	OTG_HS_HCCHAR14_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR14_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR14_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR14_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR14_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR14_MCNT				(0x3u<<20)
#define	OTG_HS_HCCHAR14_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR14_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR14_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR14_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR14_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR14_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR14_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR14_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR14_MPSIZ_0				(0x1u<<0)

// HCSPLT14 Configuration

#define	OTG_HS_HCSPLT14_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT14_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT14_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT14_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT14_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT14_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT14_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT14_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT14_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT14_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT14_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT14_XACTPOS_B_0X1		(0x1u<<14)

// HCINT14 Configuration

#define	OTG_HS_HCINT14_DTERR				(0x1u<<10)
#define	OTG_HS_HCINT14_FRMOR				(0x1u<<9)
#define	OTG_HS_HCINT14_BBERR				(0x1u<<8)
#define	OTG_HS_HCINT14_TXERR				(0x1u<<7)
#define	OTG_HS_HCINT14_ACK					(0x1u<<5)
#define	OTG_HS_HCINT14_NAK					(0x1u<<4)
#define	OTG_HS_HCINT14_STALL				(0x1u<<3)
#define	OTG_HS_HCINT14_CHH					(0x1u<<1)
#define	OTG_HS_HCINT14_XFRC					(0x1u<<0)

// HCINTMSK14 Configuration

#define	OTG_HS_HCINTMSK14_DTERRM			(0x1u<<10)
#define	OTG_HS_HCINTMSK14_FRMORM			(0x1u<<9)
#define	OTG_HS_HCINTMSK14_BBERRM			(0x1u<<8)
#define	OTG_HS_HCINTMSK14_TXERRM			(0x1u<<7)
#define	OTG_HS_HCINTMSK14_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK14_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK14_STALLM			(0x1u<<3)
#define	OTG_HS_HCINTMSK14_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK14_XFRCM				(0x1u<<0)

// HCTSIZ14 Configuration

#define	OTG_HS_HCTSIZ14_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ14_DPID				(0x3u<<29)
#define	OTG_HS_HCTSIZ14_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ14_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ14_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_HCTSIZ14_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ14_XFRSIZ_0			(0x1u<<0)

// HCDMA14 Configuration

#define	OTG_HS_HCDMA14_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA14_DMAADDR_0			(0x1u<<0)

// HCCHAR15 Configuration

#define	OTG_HS_HCCHAR15_CHENA				(0x1u<<31)
#define	OTG_HS_HCCHAR15_CHDIS				(0x1u<<30)
#define	OTG_HS_HCCHAR15_ODDFRM				(0x1u<<29)
#define	OTG_HS_HCCHAR15_DAD					(0x7Fu<<22)
#define	OTG_HS_HCCHAR15_DAD_0				(0x1u<<22)
#define	OTG_HS_HCCHAR15_MCNT				(0x3u<<20)
#define	OTG_HS_HCCHAR15_MCNT_0				(0x1u<<20)
#define	OTG_HS_HCCHAR15_EPTYP				(0x3u<<18)
#define	OTG_HS_HCCHAR15_EPTYP_0				(0x1u<<18)
#define	OTG_HS_HCCHAR15_LSDEV				(0x1u<<17)
#define	OTG_HS_HCCHAR15_EPDIR				(0x1u<<15)
#define	OTG_HS_HCCHAR15_EPNUM				(0xFu<<11)
#define	OTG_HS_HCCHAR15_EPNUM_0				(0x1u<<11)
#define	OTG_HS_HCCHAR15_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_HCCHAR15_MPSIZ_0				(0x1u<<0)

// HCSPLT15 Configuration

#define	OTG_HS_HCSPLT15_SPLITEN				(0x1u<<31)
#define	OTG_HS_HCSPLT15_COMPLSPLT			(0x1u<<16)
#define	OTG_HS_HCSPLT15_XACTPOS				(0x3u<<14)
#define	OTG_HS_HCSPLT15_XACTPOS_0			(0x1u<<14)
#define	OTG_HS_HCSPLT15_HUBADDR				(0x7Fu<<7)
#define	OTG_HS_HCSPLT15_HUBADDR_0			(0x1u<<7)
#define	OTG_HS_HCSPLT15_PRTADDR				(0x7Fu<<0)
#define	OTG_HS_HCSPLT15_PRTADDR_0			(0x1u<<0)
#define	OTG_HS_HCSPLT15_XACTPOS_B_0X3		(0x3u<<14)
#define	OTG_HS_HCSPLT15_XACTPOS_B_0X2		(0x2u<<14)
#define	OTG_HS_HCSPLT15_XACTPOS_B_0X0		(0x0u<<14)
#define	OTG_HS_HCSPLT15_XACTPOS_B_0X1		(0x1u<<14)

// HCINT15 Configuration

#define	OTG_HS_HCINT15_DTERR				(0x1u<<10)
#define	OTG_HS_HCINT15_FRMOR				(0x1u<<9)
#define	OTG_HS_HCINT15_BBERR				(0x1u<<8)
#define	OTG_HS_HCINT15_TXERR				(0x1u<<7)
#define	OTG_HS_HCINT15_ACK					(0x1u<<5)
#define	OTG_HS_HCINT15_NAK					(0x1u<<4)
#define	OTG_HS_HCINT15_STALL				(0x1u<<3)
#define	OTG_HS_HCINT15_CHH					(0x1u<<1)
#define	OTG_HS_HCINT15_XFRC					(0x1u<<0)

// HCINTMSK15 Configuration

#define	OTG_HS_HCINTMSK15_DTERRM			(0x1u<<10)
#define	OTG_HS_HCINTMSK15_FRMORM			(0x1u<<9)
#define	OTG_HS_HCINTMSK15_BBERRM			(0x1u<<8)
#define	OTG_HS_HCINTMSK15_TXERRM			(0x1u<<7)
#define	OTG_HS_HCINTMSK15_ACKM				(0x1u<<5)
#define	OTG_HS_HCINTMSK15_NAKM				(0x1u<<4)
#define	OTG_HS_HCINTMSK15_STALLM			(0x1u<<3)
#define	OTG_HS_HCINTMSK15_CHHM				(0x1u<<1)
#define	OTG_HS_HCINTMSK15_XFRCM				(0x1u<<0)

// HCTSIZ15 Configuration

#define	OTG_HS_HCTSIZ15_DOPNG				(0x1u<<31)
#define	OTG_HS_HCTSIZ15_DPID				(0x3u<<29)
#define	OTG_HS_HCTSIZ15_DPID_0				(0x1u<<29)
#define	OTG_HS_HCTSIZ15_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_HCTSIZ15_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_HCTSIZ15_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_HCTSIZ15_XFRSIZ_0			(0x1u<<0)

// HCDMA15 Configuration

#define	OTG_HS_HCDMA15_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_HCDMA15_DMAADDR_0			(0x1u<<0)

// DCFG Configuration

#define	OTG_HS_DCFG_ERRATIM					(0x1u<<15)
#define	OTG_HS_DCFG_PFIVL					(0x3u<<11)
#define	OTG_HS_DCFG_PFIVL_0					(0x1u<<11)
#define	OTG_HS_DCFG_DAD						(0x7Fu<<4)
#define	OTG_HS_DCFG_DAD_0					(0x1u<<4)
#define	OTG_HS_DCFG_NZLSOHSK				(0x1u<<2)
#define	OTG_HS_DCFG_DSPD					(0x3u<<0)
#define	OTG_HS_DCFG_DSPD_0					(0x1u<<0)

// DCTL Configuration

#define	OTG_HS_DCTL_DSBESLRJCT				(0x1u<<18)
#define	OTG_HS_DCTL_POPRGDNE				(0x1u<<11)
#define	OTG_HS_DCTL_CGONAK					(0x1u<<10)
#define	OTG_HS_DCTL_SGONAK					(0x1u<<9)
#define	OTG_HS_DCTL_CGINAK					(0x1u<<8)
#define	OTG_HS_DCTL_SGINAK					(0x1u<<7)
#define	OTG_HS_DCTL_TCTL					(0x7u<<4)
#define	OTG_HS_DCTL_TCTL_0					(0x1u<<4)
#define	OTG_HS_DCTL_GONSTS					(0x1u<<3)
#define	OTG_HS_DCTL_GINSTS					(0x1u<<2)
#define	OTG_HS_DCTL_SDIS					(0x1u<<1)
#define	OTG_HS_DCTL_RWUSIG					(0x1u<<0)

// DSTS Configuration

#define	OTG_HS_DSTS_DEVLNSTS				(0x3u<<22)
#define	OTG_HS_DSTS_DEVLNSTS_0				(0x1u<<22)
#define	OTG_HS_DSTS_FNSOF					(0x3FFFu<<8)
#define	OTG_HS_DSTS_FNSOF_0					(0x1u<<8)
#define	OTG_HS_DSTS_EERR					(0x1u<<3)
#define	OTG_HS_DSTS_ENUMSPD					(0x3u<<1)
#define	OTG_HS_DSTS_ENUMSPD_0				(0x1u<<1)
#define	OTG_HS_DSTS_SUSPSTS					(0x1u<<0)

// DIEPMSK Configuration

#define	OTG_HS_DIEPMSK_NAKM					(0x1u<<13)
#define	OTG_HS_DIEPMSK_TXFURM				(0x1u<<8)
#define	OTG_HS_DIEPMSK_INEPNEM				(0x1u<<6)
#define	OTG_HS_DIEPMSK_INEPNMM				(0x1u<<5)
#define	OTG_HS_DIEPMSK_ITTXFEMSK			(0x1u<<4)
#define	OTG_HS_DIEPMSK_TOM					(0x1u<<3)
#define	OTG_HS_DIEPMSK_AHBERRM				(0x1u<<2)
#define	OTG_HS_DIEPMSK_EPDM					(0x1u<<1)
#define	OTG_HS_DIEPMSK_XFRCM				(0x1u<<0)

// DOEPMSK Configuration

#define	OTG_HS_DOEPMSK_NYETMSK				(0x1u<<14)
#define	OTG_HS_DOEPMSK_NAKMSK				(0x1u<<13)
#define	OTG_HS_DOEPMSK_BERRM				(0x1u<<12)
#define	OTG_HS_DOEPMSK_OUTPKTERRM			(0x1u<<8)
#define	OTG_HS_DOEPMSK_B2BSTUPM				(0x1u<<6)
#define	OTG_HS_DOEPMSK_STSPHSRXM			(0x1u<<5)
#define	OTG_HS_DOEPMSK_OTEPDM				(0x1u<<4)
#define	OTG_HS_DOEPMSK_STUPM				(0x1u<<3)
#define	OTG_HS_DOEPMSK_AHBERRM				(0x1u<<2)
#define	OTG_HS_DOEPMSK_EPDM					(0x1u<<1)
#define	OTG_HS_DOEPMSK_XFRCM				(0x1u<<0)

// DAINT Configuration

#define	OTG_HS_DAINT_OEPINT					(0xFFFFu<<16)
#define	OTG_HS_DAINT_OEPINT_0				(0x1u<<16)
#define	OTG_HS_DAINT_IEPINT					(0xFFFFu<<0)
#define	OTG_HS_DAINT_IEPINT_0				(0x1u<<0)

// DAINTMSK Configuration

#define	OTG_HS_DAINTMSK_OEPM				(0xFFFFu<<16)
#define	OTG_HS_DAINTMSK_OEPM_0				(0x1u<<16)
#define	OTG_HS_DAINTMSK_IEPM				(0xFFFFu<<0)
#define	OTG_HS_DAINTMSK_IEPM_0				(0x1u<<0)

// DVBUSDIS Configuration

#define	OTG_HS_DVBUSDIS_VBUSDT				(0xFFFFu<<0)
#define	OTG_HS_DVBUSDIS_VBUSDT_0			(0x1u<<0)

// DVBUSPULSE Configuration

#define	OTG_HS_DVBUSPULSE_DVBUSP			(0xFFFFu<<0)
#define	OTG_HS_DVBUSPULSE_DVBUSP_0			(0x1u<<0)

// DTHRCTL Configuration

#define	OTG_HS_DTHRCTL_ARPEN				(0x1u<<27)
#define	OTG_HS_DTHRCTL_RXTHRLEN				(0x1FFu<<17)
#define	OTG_HS_DTHRCTL_RXTHRLEN_0			(0x1u<<17)
#define	OTG_HS_DTHRCTL_RXTHREN				(0x1u<<16)
#define	OTG_HS_DTHRCTL_TXTHRLEN				(0x1FFu<<2)
#define	OTG_HS_DTHRCTL_TXTHRLEN_0			(0x1u<<2)
#define	OTG_HS_DTHRCTL_ISOTHREN				(0x1u<<1)
#define	OTG_HS_DTHRCTL_NONISOTHREN			(0x1u<<0)

// DIEPEMPMSK Configuration

#define	OTG_HS_DIEPEMPMSK_INEPTXFEM			(0xFFFFu<<0)
#define	OTG_HS_DIEPEMPMSK_INEPTXFEM_0		(0x1u<<0)

// DOEPEACHMSK1 Configuration

#define	OTG_HS_DOEPEACHMSK1_NYETMSK			(0x1u<<14)
#define	OTG_HS_DOEPEACHMSK1_NAKMSK			(0x1u<<13)
#define	OTG_HS_DOEPEACHMSK1_BERRM			(0x1u<<12)
#define	OTG_HS_DOEPEACHMSK1_BNAM			(0x1u<<9)
#define	OTG_HS_DOEPEACHMSK1_OUTPKTERRM		(0x1u<<8)
#define	OTG_HS_DOEPEACHMSK1_B2BSTUPM		(0x1u<<6)
#define	OTG_HS_DOEPEACHMSK1_OTEPDM			(0x1u<<4)
#define	OTG_HS_DOEPEACHMSK1_STUPM			(0x1u<<3)
#define	OTG_HS_DOEPEACHMSK1_AHBERRM			(0x1u<<2)
#define	OTG_HS_DOEPEACHMSK1_EPDM			(0x1u<<1)
#define	OTG_HS_DOEPEACHMSK1_XFRCM			(0x1u<<0)

// DIEPCTL0 Configuration

#define	OTG_HS_DIEPCTL0_EPENA				(0x1u<<31)
#define	OTG_HS_DIEPCTL0_EPDIS				(0x1u<<30)
#define	OTG_HS_DIEPCTL0_SNAK				(0x1u<<27)
#define	OTG_HS_DIEPCTL0_CNAK				(0x1u<<26)
#define	OTG_HS_DIEPCTL0_TXFNUM				(0xFu<<22)
#define	OTG_HS_DIEPCTL0_TXFNUM_0			(0x1u<<22)
#define	OTG_HS_DIEPCTL0_STALL				(0x1u<<21)
#define	OTG_HS_DIEPCTL0_EPTYP				(0x3u<<18)
#define	OTG_HS_DIEPCTL0_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DIEPCTL0_NAKSTS				(0x1u<<17)
#define	OTG_HS_DIEPCTL0_USBAEP				(0x1u<<15)
#define	OTG_HS_DIEPCTL0_MPSIZ				(0x3u<<0)
#define	OTG_HS_DIEPCTL0_MPSIZ_0				(0x1u<<0)

// DIEPINT0 Configuration

#define	OTG_HS_DIEPINT0_NAK					(0x1u<<13)
#define	OTG_HS_DIEPINT0_PKTDRPSTS			(0x1u<<11)
#define	OTG_HS_DIEPINT0_TXFE				(0x1u<<7)
#define	OTG_HS_DIEPINT0_INEPNE				(0x1u<<6)
#define	OTG_HS_DIEPINT0_INEPNM				(0x1u<<5)
#define	OTG_HS_DIEPINT0_ITTXFE				(0x1u<<4)
#define	OTG_HS_DIEPINT0_TOC					(0x1u<<3)
#define	OTG_HS_DIEPINT0_EPDISD				(0x1u<<1)
#define	OTG_HS_DIEPINT0_XFRC				(0x1u<<0)

// DIEPTSIZ0 Configuration

#define	OTG_HS_DIEPTSIZ0_PKTCNT				(0x3u<<19)
#define	OTG_HS_DIEPTSIZ0_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DIEPTSIZ0_XFRSIZ				(0x7Fu<<0)
#define	OTG_HS_DIEPTSIZ0_XFRSIZ_0			(0x1u<<0)

// DTXFSTS0 Configuration

#define	OTG_HS_DTXFSTS0_INEPTFSAV			(0xFFFFu<<0)
#define	OTG_HS_DTXFSTS0_INEPTFSAV_0			(0x1u<<0)

// DIEPCTL1 Configuration

#define	OTG_HS_DIEPCTL1_EPENA				(0x1u<<31)
#define	OTG_HS_DIEPCTL1_EPDIS				(0x1u<<30)
#define	OTG_HS_DIEPCTL1_SODDFRM				(0x1u<<29)
#define	OTG_HS_DIEPCTL1_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_HS_DIEPCTL1_SNAK				(0x1u<<27)
#define	OTG_HS_DIEPCTL1_CNAK				(0x1u<<26)
#define	OTG_HS_DIEPCTL1_TXFNUM				(0xFu<<22)
#define	OTG_HS_DIEPCTL1_TXFNUM_0			(0x1u<<22)
#define	OTG_HS_DIEPCTL1_STALL				(0x1u<<21)
#define	OTG_HS_DIEPCTL1_EPTYP				(0x3u<<18)
#define	OTG_HS_DIEPCTL1_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DIEPCTL1_NAKSTS				(0x1u<<17)
#define	OTG_HS_DIEPCTL1_EONUM_DPIP			(0x1u<<16)
#define	OTG_HS_DIEPCTL1_USBAEP				(0x1u<<15)
#define	OTG_HS_DIEPCTL1_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_DIEPCTL1_MPSIZ_0				(0x1u<<0)

// DIEPINT1 Configuration

#define	OTG_HS_DIEPINT1_NAK					(0x1u<<13)
#define	OTG_HS_DIEPINT1_PKTDRPSTS			(0x1u<<11)
#define	OTG_HS_DIEPINT1_TXFE				(0x1u<<7)
#define	OTG_HS_DIEPINT1_INEPNE				(0x1u<<6)
#define	OTG_HS_DIEPINT1_INEPNM				(0x1u<<5)
#define	OTG_HS_DIEPINT1_ITTXFE				(0x1u<<4)
#define	OTG_HS_DIEPINT1_TOC					(0x1u<<3)
#define	OTG_HS_DIEPINT1_EPDISD				(0x1u<<1)
#define	OTG_HS_DIEPINT1_XFRC				(0x1u<<0)

// DIEPTSIZ1 Configuration

#define	OTG_HS_DIEPTSIZ1_MCNT				(0x3u<<29)
#define	OTG_HS_DIEPTSIZ1_MCNT_0				(0x1u<<29)
#define	OTG_HS_DIEPTSIZ1_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DIEPTSIZ1_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DIEPTSIZ1_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DIEPTSIZ1_XFRSIZ_0			(0x1u<<0)

// DIEPDMA1 Configuration

#define	OTG_HS_DIEPDMA1_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DIEPDMA1_DMAADDR_0			(0x1u<<0)

// DTXFSTS1 Configuration

#define	OTG_HS_DTXFSTS1_INEPTFSAV			(0xFFFFu<<0)
#define	OTG_HS_DTXFSTS1_INEPTFSAV_0			(0x1u<<0)

// DIEPCTL2 Configuration

#define	OTG_HS_DIEPCTL2_EPENA				(0x1u<<31)
#define	OTG_HS_DIEPCTL2_EPDIS				(0x1u<<30)
#define	OTG_HS_DIEPCTL2_SODDFRM				(0x1u<<29)
#define	OTG_HS_DIEPCTL2_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_HS_DIEPCTL2_SNAK				(0x1u<<27)
#define	OTG_HS_DIEPCTL2_CNAK				(0x1u<<26)
#define	OTG_HS_DIEPCTL2_TXFNUM				(0xFu<<22)
#define	OTG_HS_DIEPCTL2_TXFNUM_0			(0x1u<<22)
#define	OTG_HS_DIEPCTL2_STALL				(0x1u<<21)
#define	OTG_HS_DIEPCTL2_EPTYP				(0x3u<<18)
#define	OTG_HS_DIEPCTL2_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DIEPCTL2_NAKSTS				(0x1u<<17)
#define	OTG_HS_DIEPCTL2_EONUM_DPIP			(0x1u<<16)
#define	OTG_HS_DIEPCTL2_USBAEP				(0x1u<<15)
#define	OTG_HS_DIEPCTL2_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_DIEPCTL2_MPSIZ_0				(0x1u<<0)

// DIEPINT2 Configuration

#define	OTG_HS_DIEPINT2_NAK					(0x1u<<13)
#define	OTG_HS_DIEPINT2_PKTDRPSTS			(0x1u<<11)
#define	OTG_HS_DIEPINT2_TXFE				(0x1u<<7)
#define	OTG_HS_DIEPINT2_INEPNE				(0x1u<<6)
#define	OTG_HS_DIEPINT2_INEPNM				(0x1u<<5)
#define	OTG_HS_DIEPINT2_ITTXFE				(0x1u<<4)
#define	OTG_HS_DIEPINT2_TOC					(0x1u<<3)
#define	OTG_HS_DIEPINT2_EPDISD				(0x1u<<1)
#define	OTG_HS_DIEPINT2_XFRC				(0x1u<<0)

// DIEPTSIZ2 Configuration

#define	OTG_HS_DIEPTSIZ2_MCNT				(0x3u<<29)
#define	OTG_HS_DIEPTSIZ2_MCNT_0				(0x1u<<29)
#define	OTG_HS_DIEPTSIZ2_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DIEPTSIZ2_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DIEPTSIZ2_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DIEPTSIZ2_XFRSIZ_0			(0x1u<<0)

// DIEPDMA2 Configuration

#define	OTG_HS_DIEPDMA2_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DIEPDMA2_DMAADDR_0			(0x1u<<0)

// DTXFSTS2 Configuration

#define	OTG_HS_DTXFSTS2_INEPTFSAV			(0xFFFFu<<0)
#define	OTG_HS_DTXFSTS2_INEPTFSAV_0			(0x1u<<0)

// DIEPCTL3 Configuration

#define	OTG_HS_DIEPCTL3_EPENA				(0x1u<<31)
#define	OTG_HS_DIEPCTL3_EPDIS				(0x1u<<30)
#define	OTG_HS_DIEPCTL3_SODDFRM				(0x1u<<29)
#define	OTG_HS_DIEPCTL3_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_HS_DIEPCTL3_SNAK				(0x1u<<27)
#define	OTG_HS_DIEPCTL3_CNAK				(0x1u<<26)
#define	OTG_HS_DIEPCTL3_TXFNUM				(0xFu<<22)
#define	OTG_HS_DIEPCTL3_TXFNUM_0			(0x1u<<22)
#define	OTG_HS_DIEPCTL3_STALL				(0x1u<<21)
#define	OTG_HS_DIEPCTL3_EPTYP				(0x3u<<18)
#define	OTG_HS_DIEPCTL3_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DIEPCTL3_NAKSTS				(0x1u<<17)
#define	OTG_HS_DIEPCTL3_EONUM_DPIP			(0x1u<<16)
#define	OTG_HS_DIEPCTL3_USBAEP				(0x1u<<15)
#define	OTG_HS_DIEPCTL3_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_DIEPCTL3_MPSIZ_0				(0x1u<<0)

// DIEPINT3 Configuration

#define	OTG_HS_DIEPINT3_NAK					(0x1u<<13)
#define	OTG_HS_DIEPINT3_PKTDRPSTS			(0x1u<<11)
#define	OTG_HS_DIEPINT3_TXFE				(0x1u<<7)
#define	OTG_HS_DIEPINT3_INEPNE				(0x1u<<6)
#define	OTG_HS_DIEPINT3_INEPNM				(0x1u<<5)
#define	OTG_HS_DIEPINT3_ITTXFE				(0x1u<<4)
#define	OTG_HS_DIEPINT3_TOC					(0x1u<<3)
#define	OTG_HS_DIEPINT3_EPDISD				(0x1u<<1)
#define	OTG_HS_DIEPINT3_XFRC				(0x1u<<0)

// DIEPTSIZ3 Configuration

#define	OTG_HS_DIEPTSIZ3_MCNT				(0x3u<<29)
#define	OTG_HS_DIEPTSIZ3_MCNT_0				(0x1u<<29)
#define	OTG_HS_DIEPTSIZ3_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DIEPTSIZ3_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DIEPTSIZ3_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DIEPTSIZ3_XFRSIZ_0			(0x1u<<0)

// DIEPDMA3 Configuration

#define	OTG_HS_DIEPDMA3_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DIEPDMA3_DMAADDR_0			(0x1u<<0)

// DTXFSTS3 Configuration

#define	OTG_HS_DTXFSTS3_INEPTFSAV			(0xFFFFu<<0)
#define	OTG_HS_DTXFSTS3_INEPTFSAV_0			(0x1u<<0)

// DIEPCTL4 Configuration

#define	OTG_HS_DIEPCTL4_EPENA				(0x1u<<31)
#define	OTG_HS_DIEPCTL4_EPDIS				(0x1u<<30)
#define	OTG_HS_DIEPCTL4_SODDFRM				(0x1u<<29)
#define	OTG_HS_DIEPCTL4_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_HS_DIEPCTL4_SNAK				(0x1u<<27)
#define	OTG_HS_DIEPCTL4_CNAK				(0x1u<<26)
#define	OTG_HS_DIEPCTL4_TXFNUM				(0xFu<<22)
#define	OTG_HS_DIEPCTL4_TXFNUM_0			(0x1u<<22)
#define	OTG_HS_DIEPCTL4_STALL				(0x1u<<21)
#define	OTG_HS_DIEPCTL4_EPTYP				(0x3u<<18)
#define	OTG_HS_DIEPCTL4_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DIEPCTL4_NAKSTS				(0x1u<<17)
#define	OTG_HS_DIEPCTL4_EONUM_DPIP			(0x1u<<16)
#define	OTG_HS_DIEPCTL4_USBAEP				(0x1u<<15)
#define	OTG_HS_DIEPCTL4_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_DIEPCTL4_MPSIZ_0				(0x1u<<0)

// DIEPINT4 Configuration

#define	OTG_HS_DIEPINT4_NAK					(0x1u<<13)
#define	OTG_HS_DIEPINT4_PKTDRPSTS			(0x1u<<11)
#define	OTG_HS_DIEPINT4_TXFE				(0x1u<<7)
#define	OTG_HS_DIEPINT4_INEPNE				(0x1u<<6)
#define	OTG_HS_DIEPINT4_INEPNM				(0x1u<<5)
#define	OTG_HS_DIEPINT4_ITTXFE				(0x1u<<4)
#define	OTG_HS_DIEPINT4_TOC					(0x1u<<3)
#define	OTG_HS_DIEPINT4_EPDISD				(0x1u<<1)
#define	OTG_HS_DIEPINT4_XFRC				(0x1u<<0)

// DIEPTSIZ4 Configuration

#define	OTG_HS_DIEPTSIZ4_MCNT				(0x3u<<29)
#define	OTG_HS_DIEPTSIZ4_MCNT_0				(0x1u<<29)
#define	OTG_HS_DIEPTSIZ4_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DIEPTSIZ4_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DIEPTSIZ4_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DIEPTSIZ4_XFRSIZ_0			(0x1u<<0)

// DIEPDMA4 Configuration

#define	OTG_HS_DIEPDMA4_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DIEPDMA4_DMAADDR_0			(0x1u<<0)

// DTXFSTS4 Configuration

#define	OTG_HS_DTXFSTS4_INEPTFSAV			(0xFFFFu<<0)
#define	OTG_HS_DTXFSTS4_INEPTFSAV_0			(0x1u<<0)

// DIEPCTL5 Configuration

#define	OTG_HS_DIEPCTL5_EPENA				(0x1u<<31)
#define	OTG_HS_DIEPCTL5_EPDIS				(0x1u<<30)
#define	OTG_HS_DIEPCTL5_SODDFRM				(0x1u<<29)
#define	OTG_HS_DIEPCTL5_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_HS_DIEPCTL5_SNAK				(0x1u<<27)
#define	OTG_HS_DIEPCTL5_CNAK				(0x1u<<26)
#define	OTG_HS_DIEPCTL5_TXFNUM				(0xFu<<22)
#define	OTG_HS_DIEPCTL5_TXFNUM_0			(0x1u<<22)
#define	OTG_HS_DIEPCTL5_STALL				(0x1u<<21)
#define	OTG_HS_DIEPCTL5_EPTYP				(0x3u<<18)
#define	OTG_HS_DIEPCTL5_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DIEPCTL5_NAKSTS				(0x1u<<17)
#define	OTG_HS_DIEPCTL5_EONUM_DPIP			(0x1u<<16)
#define	OTG_HS_DIEPCTL5_USBAEP				(0x1u<<15)
#define	OTG_HS_DIEPCTL5_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_DIEPCTL5_MPSIZ_0				(0x1u<<0)

// DIEPINT5 Configuration

#define	OTG_HS_DIEPINT5_NAK					(0x1u<<13)
#define	OTG_HS_DIEPINT5_PKTDRPSTS			(0x1u<<11)
#define	OTG_HS_DIEPINT5_TXFE				(0x1u<<7)
#define	OTG_HS_DIEPINT5_INEPNE				(0x1u<<6)
#define	OTG_HS_DIEPINT5_INEPNM				(0x1u<<5)
#define	OTG_HS_DIEPINT5_ITTXFE				(0x1u<<4)
#define	OTG_HS_DIEPINT5_TOC					(0x1u<<3)
#define	OTG_HS_DIEPINT5_EPDISD				(0x1u<<1)
#define	OTG_HS_DIEPINT5_XFRC				(0x1u<<0)

// DIEPTSIZ5 Configuration

#define	OTG_HS_DIEPTSIZ5_MCNT				(0x3u<<29)
#define	OTG_HS_DIEPTSIZ5_MCNT_0				(0x1u<<29)
#define	OTG_HS_DIEPTSIZ5_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DIEPTSIZ5_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DIEPTSIZ5_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DIEPTSIZ5_XFRSIZ_0			(0x1u<<0)

// DIEPDMA5 Configuration

#define	OTG_HS_DIEPDMA5_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DIEPDMA5_DMAADDR_0			(0x1u<<0)

// DTXFSTS5 Configuration

#define	OTG_HS_DTXFSTS5_INEPTFSAV			(0xFFFFu<<0)
#define	OTG_HS_DTXFSTS5_INEPTFSAV_0			(0x1u<<0)

// DIEPINT6 Configuration

#define	OTG_HS_DIEPINT6_NAK					(0x1u<<13)
#define	OTG_HS_DIEPINT6_PKTDRPSTS			(0x1u<<11)
#define	OTG_HS_DIEPINT6_BNA					(0x1u<<9)
#define	OTG_HS_DIEPINT6_TXFIFOUDRN			(0x1u<<8)
#define	OTG_HS_DIEPINT6_TXFE				(0x1u<<7)
#define	OTG_HS_DIEPINT6_INEPNE				(0x1u<<6)
#define	OTG_HS_DIEPINT6_INEPNM				(0x1u<<5)
#define	OTG_HS_DIEPINT6_ITTXFE				(0x1u<<4)
#define	OTG_HS_DIEPINT6_TOC					(0x1u<<3)
#define	OTG_HS_DIEPINT6_AHBERR				(0x1u<<2)
#define	OTG_HS_DIEPINT6_EPDISD				(0x1u<<1)
#define	OTG_HS_DIEPINT6_XFRC				(0x1u<<0)

// DIEPTSIZ6 Configuration

#define	OTG_HS_DIEPTSIZ6_MCNT				(0x3u<<29)
#define	OTG_HS_DIEPTSIZ6_MCNT_0				(0x1u<<29)
#define	OTG_HS_DIEPTSIZ6_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DIEPTSIZ6_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DIEPTSIZ6_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DIEPTSIZ6_XFRSIZ_0			(0x1u<<0)

// DIEPDMA6 Configuration

#define	OTG_HS_DIEPDMA6_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DIEPDMA6_DMAADDR_0			(0x1u<<0)

// DIEPINT7 Configuration

#define	OTG_HS_DIEPINT7_NAK					(0x1u<<13)
#define	OTG_HS_DIEPINT7_PKTDRPSTS			(0x1u<<11)
#define	OTG_HS_DIEPINT7_BNA					(0x1u<<9)
#define	OTG_HS_DIEPINT7_TXFIFOUDRN			(0x1u<<8)
#define	OTG_HS_DIEPINT7_TXFE				(0x1u<<7)
#define	OTG_HS_DIEPINT7_INEPNE				(0x1u<<6)
#define	OTG_HS_DIEPINT7_INEPNM				(0x1u<<5)
#define	OTG_HS_DIEPINT7_ITTXFE				(0x1u<<4)
#define	OTG_HS_DIEPINT7_TOC					(0x1u<<3)
#define	OTG_HS_DIEPINT7_AHBERR				(0x1u<<2)
#define	OTG_HS_DIEPINT7_EPDISD				(0x1u<<1)
#define	OTG_HS_DIEPINT7_XFRC				(0x1u<<0)

// DIEPTSIZ7 Configuration

#define	OTG_HS_DIEPTSIZ7_MCNT				(0x3u<<29)
#define	OTG_HS_DIEPTSIZ7_MCNT_0				(0x1u<<29)
#define	OTG_HS_DIEPTSIZ7_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DIEPTSIZ7_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DIEPTSIZ7_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DIEPTSIZ7_XFRSIZ_0			(0x1u<<0)

// DIEPDMA7 Configuration

#define	OTG_HS_DIEPDMA7_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DIEPDMA7_DMAADDR_0			(0x1u<<0)

// DIEPINT8 Configuration

#define	OTG_HS_DIEPINT8_NAK					(0x1u<<13)
#define	OTG_HS_DIEPINT8_PKTDRPSTS			(0x1u<<11)
#define	OTG_HS_DIEPINT8_BNA					(0x1u<<9)
#define	OTG_HS_DIEPINT8_TXFIFOUDRN			(0x1u<<8)
#define	OTG_HS_DIEPINT8_TXFE				(0x1u<<7)
#define	OTG_HS_DIEPINT8_INEPNE				(0x1u<<6)
#define	OTG_HS_DIEPINT8_INEPNM				(0x1u<<5)
#define	OTG_HS_DIEPINT8_ITTXFE				(0x1u<<4)
#define	OTG_HS_DIEPINT8_TOC					(0x1u<<3)
#define	OTG_HS_DIEPINT8_AHBERR				(0x1u<<2)
#define	OTG_HS_DIEPINT8_EPDISD				(0x1u<<1)
#define	OTG_HS_DIEPINT8_XFRC				(0x1u<<0)

// DIEPTSIZ8 Configuration

#define	OTG_HS_DIEPTSIZ8_MCNT				(0x3u<<29)
#define	OTG_HS_DIEPTSIZ8_MCNT_0				(0x1u<<29)
#define	OTG_HS_DIEPTSIZ8_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DIEPTSIZ8_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DIEPTSIZ8_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DIEPTSIZ8_XFRSIZ_0			(0x1u<<0)

// DIEPDMA8 Configuration

#define	OTG_HS_DIEPDMA8_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DIEPDMA8_DMAADDR_0			(0x1u<<0)

// DOEPCTL0 Configuration

#define	OTG_HS_DOEPCTL0_EPENA				(0x1u<<31)
#define	OTG_HS_DOEPCTL0_EPDIS				(0x1u<<30)
#define	OTG_HS_DOEPCTL0_SNAK				(0x1u<<27)
#define	OTG_HS_DOEPCTL0_CNAK				(0x1u<<26)
#define	OTG_HS_DOEPCTL0_STALL				(0x1u<<21)
#define	OTG_HS_DOEPCTL0_SNPM				(0x1u<<20)
#define	OTG_HS_DOEPCTL0_EPTYP				(0x3u<<18)
#define	OTG_HS_DOEPCTL0_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DOEPCTL0_NAKSTS				(0x1u<<17)
#define	OTG_HS_DOEPCTL0_USBAEP				(0x1u<<15)
#define	OTG_HS_DOEPCTL0_MPSIZ				(0x3u<<0)
#define	OTG_HS_DOEPCTL0_MPSIZ_0				(0x1u<<0)

// DOEPINT0 Configuration

#define	OTG_HS_DOEPINT0_STPKTRX				(0x1u<<15)
#define	OTG_HS_DOEPINT0_NYET				(0x1u<<14)
#define	OTG_HS_DOEPINT0_NAK					(0x1u<<13)
#define	OTG_HS_DOEPINT0_BERR				(0x1u<<12)
#define	OTG_HS_DOEPINT0_BNA					(0x1u<<9)
#define	OTG_HS_DOEPINT0_OUTPKTERR			(0x1u<<8)
#define	OTG_HS_DOEPINT0_B2BSTUP				(0x1u<<6)
#define	OTG_HS_DOEPINT0_STSPHSRX			(0x1u<<5)
#define	OTG_HS_DOEPINT0_OTEPDIS				(0x1u<<4)
#define	OTG_HS_DOEPINT0_STUP				(0x1u<<3)
#define	OTG_HS_DOEPINT0_AHBERR				(0x1u<<2)
#define	OTG_HS_DOEPINT0_EPDISD				(0x1u<<1)
#define	OTG_HS_DOEPINT0_XFRC				(0x1u<<0)

// DOEPTSIZ0 Configuration

#define	OTG_HS_DOEPTSIZ0_STUPCNT			(0x3u<<29)
#define	OTG_HS_DOEPTSIZ0_STUPCNT_0			(0x1u<<29)
#define	OTG_HS_DOEPTSIZ0_PKTCNT				(0x1u<<19)
#define	OTG_HS_DOEPTSIZ0_XFRSIZ				(0x7Fu<<0)
#define	OTG_HS_DOEPTSIZ0_XFRSIZ_0			(0x1u<<0)

// DOEPDMA0 Configuration

#define	OTG_HS_DOEPDMA0_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DOEPDMA0_DMAADDR_0			(0x1u<<0)

// DOEPCTL1 Configuration

#define	OTG_HS_DOEPCTL1_EPENA				(0x1u<<31)
#define	OTG_HS_DOEPCTL1_EPDIS				(0x1u<<30)
#define	OTG_HS_DOEPCTL1_SD1PID_SODDFRM		(0x1u<<29)
#define	OTG_HS_DOEPCTL1_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_HS_DOEPCTL1_SNAK				(0x1u<<27)
#define	OTG_HS_DOEPCTL1_CNAK				(0x1u<<26)
#define	OTG_HS_DOEPCTL1_STALL				(0x1u<<21)
#define	OTG_HS_DOEPCTL1_SNPM				(0x1u<<20)
#define	OTG_HS_DOEPCTL1_EPTYP				(0x3u<<18)
#define	OTG_HS_DOEPCTL1_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DOEPCTL1_NAKSTS				(0x1u<<17)
#define	OTG_HS_DOEPCTL1_EONUM_DPIP			(0x1u<<16)
#define	OTG_HS_DOEPCTL1_USBAEP				(0x1u<<15)
#define	OTG_HS_DOEPCTL1_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_DOEPCTL1_MPSIZ_0				(0x1u<<0)

// DOEPINT1 Configuration

#define	OTG_HS_DOEPINT1_STPKTRX				(0x1u<<15)
#define	OTG_HS_DOEPINT1_NYET				(0x1u<<14)
#define	OTG_HS_DOEPINT1_NAK					(0x1u<<13)
#define	OTG_HS_DOEPINT1_BERR				(0x1u<<12)
#define	OTG_HS_DOEPINT1_BNA					(0x1u<<9)
#define	OTG_HS_DOEPINT1_OUTPKTERR			(0x1u<<8)
#define	OTG_HS_DOEPINT1_B2BSTUP				(0x1u<<6)
#define	OTG_HS_DOEPINT1_STSPHSRX			(0x1u<<5)
#define	OTG_HS_DOEPINT1_OTEPDIS				(0x1u<<4)
#define	OTG_HS_DOEPINT1_STUP				(0x1u<<3)
#define	OTG_HS_DOEPINT1_AHBERR				(0x1u<<2)
#define	OTG_HS_DOEPINT1_EPDISD				(0x1u<<1)
#define	OTG_HS_DOEPINT1_XFRC				(0x1u<<0)

// DOEPTSIZ1 Configuration

#define	OTG_HS_DOEPTSIZ1_RXDPID_STUPCNT		(0x3u<<29)
#define	OTG_HS_DOEPTSIZ1_RXDPID_STUPCNT_0	(0x1u<<29)
#define	OTG_HS_DOEPTSIZ1_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DOEPTSIZ1_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DOEPTSIZ1_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DOEPTSIZ1_XFRSIZ_0			(0x1u<<0)

// DOEPDMA1 Configuration

#define	OTG_HS_DOEPDMA1_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DOEPDMA1_DMAADDR_0			(0x1u<<0)

// DOEPCTL2 Configuration

#define	OTG_HS_DOEPCTL2_EPENA				(0x1u<<31)
#define	OTG_HS_DOEPCTL2_EPDIS				(0x1u<<30)
#define	OTG_HS_DOEPCTL2_SD1PID_SODDFRM		(0x1u<<29)
#define	OTG_HS_DOEPCTL2_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_HS_DOEPCTL2_SNAK				(0x1u<<27)
#define	OTG_HS_DOEPCTL2_CNAK				(0x1u<<26)
#define	OTG_HS_DOEPCTL2_STALL				(0x1u<<21)
#define	OTG_HS_DOEPCTL2_SNPM				(0x1u<<20)
#define	OTG_HS_DOEPCTL2_EPTYP				(0x3u<<18)
#define	OTG_HS_DOEPCTL2_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DOEPCTL2_NAKSTS				(0x1u<<17)
#define	OTG_HS_DOEPCTL2_EONUM_DPIP			(0x1u<<16)
#define	OTG_HS_DOEPCTL2_USBAEP				(0x1u<<15)
#define	OTG_HS_DOEPCTL2_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_DOEPCTL2_MPSIZ_0				(0x1u<<0)

// DOEPINT2 Configuration

#define	OTG_HS_DOEPINT2_STPKTRX				(0x1u<<15)
#define	OTG_HS_DOEPINT2_NYET				(0x1u<<14)
#define	OTG_HS_DOEPINT2_NAK					(0x1u<<13)
#define	OTG_HS_DOEPINT2_BERR				(0x1u<<12)
#define	OTG_HS_DOEPINT2_BNA					(0x1u<<9)
#define	OTG_HS_DOEPINT2_OUTPKTERR			(0x1u<<8)
#define	OTG_HS_DOEPINT2_B2BSTUP				(0x1u<<6)
#define	OTG_HS_DOEPINT2_STSPHSRX			(0x1u<<5)
#define	OTG_HS_DOEPINT2_OTEPDIS				(0x1u<<4)
#define	OTG_HS_DOEPINT2_STUP				(0x1u<<3)
#define	OTG_HS_DOEPINT2_AHBERR				(0x1u<<2)
#define	OTG_HS_DOEPINT2_EPDISD				(0x1u<<1)
#define	OTG_HS_DOEPINT2_XFRC				(0x1u<<0)

// DOEPTSIZ2 Configuration

#define	OTG_HS_DOEPTSIZ2_RXDPID_STUPCNT		(0x3u<<29)
#define	OTG_HS_DOEPTSIZ2_RXDPID_STUPCNT_0	(0x1u<<29)
#define	OTG_HS_DOEPTSIZ2_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DOEPTSIZ2_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DOEPTSIZ2_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DOEPTSIZ2_XFRSIZ_0			(0x1u<<0)

// DOEPDMA2 Configuration

#define	OTG_HS_DOEPDMA2_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DOEPDMA2_DMAADDR_0			(0x1u<<0)

// DOEPCTL3 Configuration

#define	OTG_HS_DOEPCTL3_EPENA				(0x1u<<31)
#define	OTG_HS_DOEPCTL3_EPDIS				(0x1u<<30)
#define	OTG_HS_DOEPCTL3_SD1PID_SODDFRM		(0x1u<<29)
#define	OTG_HS_DOEPCTL3_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_HS_DOEPCTL3_SNAK				(0x1u<<27)
#define	OTG_HS_DOEPCTL3_CNAK				(0x1u<<26)
#define	OTG_HS_DOEPCTL3_STALL				(0x1u<<21)
#define	OTG_HS_DOEPCTL3_SNPM				(0x1u<<20)
#define	OTG_HS_DOEPCTL3_EPTYP				(0x3u<<18)
#define	OTG_HS_DOEPCTL3_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DOEPCTL3_NAKSTS				(0x1u<<17)
#define	OTG_HS_DOEPCTL3_EONUM_DPIP			(0x1u<<16)
#define	OTG_HS_DOEPCTL3_USBAEP				(0x1u<<15)
#define	OTG_HS_DOEPCTL3_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_DOEPCTL3_MPSIZ_0				(0x1u<<0)

// DOEPINT3 Configuration

#define	OTG_HS_DOEPINT3_STPKTRX				(0x1u<<15)
#define	OTG_HS_DOEPINT3_NYET				(0x1u<<14)
#define	OTG_HS_DOEPINT3_NAK					(0x1u<<13)
#define	OTG_HS_DOEPINT3_BERR				(0x1u<<12)
#define	OTG_HS_DOEPINT3_BNA					(0x1u<<9)
#define	OTG_HS_DOEPINT3_OUTPKTERR			(0x1u<<8)
#define	OTG_HS_DOEPINT3_B2BSTUP				(0x1u<<6)
#define	OTG_HS_DOEPINT3_STSPHSRX			(0x1u<<5)
#define	OTG_HS_DOEPINT3_OTEPDIS				(0x1u<<4)
#define	OTG_HS_DOEPINT3_STUP				(0x1u<<3)
#define	OTG_HS_DOEPINT3_AHBERR				(0x1u<<2)
#define	OTG_HS_DOEPINT3_EPDISD				(0x1u<<1)
#define	OTG_HS_DOEPINT3_XFRC				(0x1u<<0)

// DOEPTSIZ3 Configuration

#define	OTG_HS_DOEPTSIZ3_RXDPID_STUPCNT		(0x3u<<29)
#define	OTG_HS_DOEPTSIZ3_RXDPID_STUPCNT_0	(0x1u<<29)
#define	OTG_HS_DOEPTSIZ3_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DOEPTSIZ3_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DOEPTSIZ3_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DOEPTSIZ3_XFRSIZ_0			(0x1u<<0)

// DOEPDMA3 Configuration

#define	OTG_HS_DOEPDMA3_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DOEPDMA3_DMAADDR_0			(0x1u<<0)

// DOEPCTL4 Configuration

#define	OTG_HS_DOEPCTL4_EPENA				(0x1u<<31)
#define	OTG_HS_DOEPCTL4_EPDIS				(0x1u<<30)
#define	OTG_HS_DOEPCTL4_SD1PID_SODDFRM		(0x1u<<29)
#define	OTG_HS_DOEPCTL4_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_HS_DOEPCTL4_SNAK				(0x1u<<27)
#define	OTG_HS_DOEPCTL4_CNAK				(0x1u<<26)
#define	OTG_HS_DOEPCTL4_STALL				(0x1u<<21)
#define	OTG_HS_DOEPCTL4_SNPM				(0x1u<<20)
#define	OTG_HS_DOEPCTL4_EPTYP				(0x3u<<18)
#define	OTG_HS_DOEPCTL4_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DOEPCTL4_NAKSTS				(0x1u<<17)
#define	OTG_HS_DOEPCTL4_EONUM_DPIP			(0x1u<<16)
#define	OTG_HS_DOEPCTL4_USBAEP				(0x1u<<15)
#define	OTG_HS_DOEPCTL4_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_DOEPCTL4_MPSIZ_0				(0x1u<<0)

// DOEPINT4 Configuration

#define	OTG_HS_DOEPINT4_STPKTRX				(0x1u<<15)
#define	OTG_HS_DOEPINT4_NYET				(0x1u<<14)
#define	OTG_HS_DOEPINT4_NAK					(0x1u<<13)
#define	OTG_HS_DOEPINT4_BERR				(0x1u<<12)
#define	OTG_HS_DOEPINT4_BNA					(0x1u<<9)
#define	OTG_HS_DOEPINT4_OUTPKTERR			(0x1u<<8)
#define	OTG_HS_DOEPINT4_B2BSTUP				(0x1u<<6)
#define	OTG_HS_DOEPINT4_STSPHSRX			(0x1u<<5)
#define	OTG_HS_DOEPINT4_OTEPDIS				(0x1u<<4)
#define	OTG_HS_DOEPINT4_STUP				(0x1u<<3)
#define	OTG_HS_DOEPINT4_AHBERR				(0x1u<<2)
#define	OTG_HS_DOEPINT4_EPDISD				(0x1u<<1)
#define	OTG_HS_DOEPINT4_XFRC				(0x1u<<0)

// DOEPTSIZ4 Configuration

#define	OTG_HS_DOEPTSIZ4_RXDPID_STUPCNT		(0x3u<<29)
#define	OTG_HS_DOEPTSIZ4_RXDPID_STUPCNT_0	(0x1u<<29)
#define	OTG_HS_DOEPTSIZ4_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DOEPTSIZ4_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DOEPTSIZ4_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DOEPTSIZ4_XFRSIZ_0			(0x1u<<0)

// DOEPDMA4 Configuration

#define	OTG_HS_DOEPDMA4_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DOEPDMA4_DMAADDR_0			(0x1u<<0)

// DOEPCTL5 Configuration

#define	OTG_HS_DOEPCTL5_EPENA				(0x1u<<31)
#define	OTG_HS_DOEPCTL5_EPDIS				(0x1u<<30)
#define	OTG_HS_DOEPCTL5_SD1PID_SODDFRM		(0x1u<<29)
#define	OTG_HS_DOEPCTL5_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_HS_DOEPCTL5_SNAK				(0x1u<<27)
#define	OTG_HS_DOEPCTL5_CNAK				(0x1u<<26)
#define	OTG_HS_DOEPCTL5_STALL				(0x1u<<21)
#define	OTG_HS_DOEPCTL5_SNPM				(0x1u<<20)
#define	OTG_HS_DOEPCTL5_EPTYP				(0x3u<<18)
#define	OTG_HS_DOEPCTL5_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DOEPCTL5_NAKSTS				(0x1u<<17)
#define	OTG_HS_DOEPCTL5_EONUM_DPIP			(0x1u<<16)
#define	OTG_HS_DOEPCTL5_USBAEP				(0x1u<<15)
#define	OTG_HS_DOEPCTL5_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_DOEPCTL5_MPSIZ_0				(0x1u<<0)

// DOEPINT5 Configuration

#define	OTG_HS_DOEPINT5_STPKTRX				(0x1u<<15)
#define	OTG_HS_DOEPINT5_NYET				(0x1u<<14)
#define	OTG_HS_DOEPINT5_NAK					(0x1u<<13)
#define	OTG_HS_DOEPINT5_BERR				(0x1u<<12)
#define	OTG_HS_DOEPINT5_BNA					(0x1u<<9)
#define	OTG_HS_DOEPINT5_OUTPKTERR			(0x1u<<8)
#define	OTG_HS_DOEPINT5_B2BSTUP				(0x1u<<6)
#define	OTG_HS_DOEPINT5_STSPHSRX			(0x1u<<5)
#define	OTG_HS_DOEPINT5_OTEPDIS				(0x1u<<4)
#define	OTG_HS_DOEPINT5_STUP				(0x1u<<3)
#define	OTG_HS_DOEPINT5_AHBERR				(0x1u<<2)
#define	OTG_HS_DOEPINT5_EPDISD				(0x1u<<1)
#define	OTG_HS_DOEPINT5_XFRC				(0x1u<<0)

// DOEPTSIZ5 Configuration

#define	OTG_HS_DOEPTSIZ5_RXDPID_STUPCNT		(0x3u<<29)
#define	OTG_HS_DOEPTSIZ5_RXDPID_STUPCNT_0	(0x1u<<29)
#define	OTG_HS_DOEPTSIZ5_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DOEPTSIZ5_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DOEPTSIZ5_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DOEPTSIZ5_XFRSIZ_0			(0x1u<<0)

// DOEPDMA5 Configuration

#define	OTG_HS_DOEPDMA5_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DOEPDMA5_DMAADDR_0			(0x1u<<0)

// DOEPCTL6 Configuration

#define	OTG_HS_DOEPCTL6_EPENA				(0x1u<<31)
#define	OTG_HS_DOEPCTL6_EPDIS				(0x1u<<30)
#define	OTG_HS_DOEPCTL6_SD1PID_SODDFRM		(0x1u<<29)
#define	OTG_HS_DOEPCTL6_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_HS_DOEPCTL6_SNAK				(0x1u<<27)
#define	OTG_HS_DOEPCTL6_CNAK				(0x1u<<26)
#define	OTG_HS_DOEPCTL6_STALL				(0x1u<<21)
#define	OTG_HS_DOEPCTL6_SNPM				(0x1u<<20)
#define	OTG_HS_DOEPCTL6_EPTYP				(0x3u<<18)
#define	OTG_HS_DOEPCTL6_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DOEPCTL6_NAKSTS				(0x1u<<17)
#define	OTG_HS_DOEPCTL6_EONUM_DPIP			(0x1u<<16)
#define	OTG_HS_DOEPCTL6_USBAEP				(0x1u<<15)
#define	OTG_HS_DOEPCTL6_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_DOEPCTL6_MPSIZ_0				(0x1u<<0)

// DOEPINT6 Configuration

#define	OTG_HS_DOEPINT6_STPKTRX				(0x1u<<15)
#define	OTG_HS_DOEPINT6_NYET				(0x1u<<14)
#define	OTG_HS_DOEPINT6_NAK					(0x1u<<13)
#define	OTG_HS_DOEPINT6_BERR				(0x1u<<12)
#define	OTG_HS_DOEPINT6_BNA					(0x1u<<9)
#define	OTG_HS_DOEPINT6_OUTPKTERR			(0x1u<<8)
#define	OTG_HS_DOEPINT6_B2BSTUP				(0x1u<<6)
#define	OTG_HS_DOEPINT6_STSPHSRX			(0x1u<<5)
#define	OTG_HS_DOEPINT6_OTEPDIS				(0x1u<<4)
#define	OTG_HS_DOEPINT6_STUP				(0x1u<<3)
#define	OTG_HS_DOEPINT6_AHBERR				(0x1u<<2)
#define	OTG_HS_DOEPINT6_EPDISD				(0x1u<<1)
#define	OTG_HS_DOEPINT6_XFRC				(0x1u<<0)

// DOEPTSIZ6 Configuration

#define	OTG_HS_DOEPTSIZ6_RXDPID_STUPCNT		(0x3u<<29)
#define	OTG_HS_DOEPTSIZ6_RXDPID_STUPCNT_0	(0x1u<<29)
#define	OTG_HS_DOEPTSIZ6_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DOEPTSIZ6_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DOEPTSIZ6_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DOEPTSIZ6_XFRSIZ_0			(0x1u<<0)

// DOEPDMA6 Configuration

#define	OTG_HS_DOEPDMA6_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DOEPDMA6_DMAADDR_0			(0x1u<<0)

// DOEPCTL7 Configuration

#define	OTG_HS_DOEPCTL7_EPENA				(0x1u<<31)
#define	OTG_HS_DOEPCTL7_EPDIS				(0x1u<<30)
#define	OTG_HS_DOEPCTL7_SD1PID_SODDFRM		(0x1u<<29)
#define	OTG_HS_DOEPCTL7_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_HS_DOEPCTL7_SNAK				(0x1u<<27)
#define	OTG_HS_DOEPCTL7_CNAK				(0x1u<<26)
#define	OTG_HS_DOEPCTL7_STALL				(0x1u<<21)
#define	OTG_HS_DOEPCTL7_SNPM				(0x1u<<20)
#define	OTG_HS_DOEPCTL7_EPTYP				(0x3u<<18)
#define	OTG_HS_DOEPCTL7_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DOEPCTL7_NAKSTS				(0x1u<<17)
#define	OTG_HS_DOEPCTL7_EONUM_DPIP			(0x1u<<16)
#define	OTG_HS_DOEPCTL7_USBAEP				(0x1u<<15)
#define	OTG_HS_DOEPCTL7_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_DOEPCTL7_MPSIZ_0				(0x1u<<0)

// DOEPINT7 Configuration

#define	OTG_HS_DOEPINT7_STPKTRX				(0x1u<<15)
#define	OTG_HS_DOEPINT7_NYET				(0x1u<<14)
#define	OTG_HS_DOEPINT7_NAK					(0x1u<<13)
#define	OTG_HS_DOEPINT7_BERR				(0x1u<<12)
#define	OTG_HS_DOEPINT7_BNA					(0x1u<<9)
#define	OTG_HS_DOEPINT7_OUTPKTERR			(0x1u<<8)
#define	OTG_HS_DOEPINT7_B2BSTUP				(0x1u<<6)
#define	OTG_HS_DOEPINT7_STSPHSRX			(0x1u<<5)
#define	OTG_HS_DOEPINT7_OTEPDIS				(0x1u<<4)
#define	OTG_HS_DOEPINT7_STUP				(0x1u<<3)
#define	OTG_HS_DOEPINT7_AHBERR				(0x1u<<2)
#define	OTG_HS_DOEPINT7_EPDISD				(0x1u<<1)
#define	OTG_HS_DOEPINT7_XFRC				(0x1u<<0)

// DOEPTSIZ7 Configuration

#define	OTG_HS_DOEPTSIZ7_RXDPID_STUPCNT		(0x3u<<29)
#define	OTG_HS_DOEPTSIZ7_RXDPID_STUPCNT_0	(0x1u<<29)
#define	OTG_HS_DOEPTSIZ7_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DOEPTSIZ7_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DOEPTSIZ7_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DOEPTSIZ7_XFRSIZ_0			(0x1u<<0)

// DOEPDMA7 Configuration

#define	OTG_HS_DOEPDMA7_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DOEPDMA7_DMAADDR_0			(0x1u<<0)

// DOEPCTL8 Configuration

#define	OTG_HS_DOEPCTL8_EPENA				(0x1u<<31)
#define	OTG_HS_DOEPCTL8_EPDIS				(0x1u<<30)
#define	OTG_HS_DOEPCTL8_SD1PID_SODDFRM		(0x1u<<29)
#define	OTG_HS_DOEPCTL8_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_HS_DOEPCTL8_SNAK				(0x1u<<27)
#define	OTG_HS_DOEPCTL8_CNAK				(0x1u<<26)
#define	OTG_HS_DOEPCTL8_STALL				(0x1u<<21)
#define	OTG_HS_DOEPCTL8_SNPM				(0x1u<<20)
#define	OTG_HS_DOEPCTL8_EPTYP				(0x3u<<18)
#define	OTG_HS_DOEPCTL8_EPTYP_0				(0x1u<<18)
#define	OTG_HS_DOEPCTL8_NAKSTS				(0x1u<<17)
#define	OTG_HS_DOEPCTL8_EONUM_DPIP			(0x1u<<16)
#define	OTG_HS_DOEPCTL8_USBAEP				(0x1u<<15)
#define	OTG_HS_DOEPCTL8_MPSIZ				(0x7FFu<<0)
#define	OTG_HS_DOEPCTL8_MPSIZ_0				(0x1u<<0)

// DOEPINT8 Configuration

#define	OTG_HS_DOEPINT8_STPKTRX				(0x1u<<15)
#define	OTG_HS_DOEPINT8_NYET				(0x1u<<14)
#define	OTG_HS_DOEPINT8_NAK					(0x1u<<13)
#define	OTG_HS_DOEPINT8_BERR				(0x1u<<12)
#define	OTG_HS_DOEPINT8_BNA					(0x1u<<9)
#define	OTG_HS_DOEPINT8_OUTPKTERR			(0x1u<<8)
#define	OTG_HS_DOEPINT8_B2BSTUP				(0x1u<<6)
#define	OTG_HS_DOEPINT8_STSPHSRX			(0x1u<<5)
#define	OTG_HS_DOEPINT8_OTEPDIS				(0x1u<<4)
#define	OTG_HS_DOEPINT8_STUP				(0x1u<<3)
#define	OTG_HS_DOEPINT8_AHBERR				(0x1u<<2)
#define	OTG_HS_DOEPINT8_EPDISD				(0x1u<<1)
#define	OTG_HS_DOEPINT8_XFRC				(0x1u<<0)

// DOEPTSIZ8 Configuration

#define	OTG_HS_DOEPTSIZ8_RXDPID_STUPCNT		(0x3u<<29)
#define	OTG_HS_DOEPTSIZ8_RXDPID_STUPCNT_0	(0x1u<<29)
#define	OTG_HS_DOEPTSIZ8_PKTCNT				(0x3FFu<<19)
#define	OTG_HS_DOEPTSIZ8_PKTCNT_0			(0x1u<<19)
#define	OTG_HS_DOEPTSIZ8_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_HS_DOEPTSIZ8_XFRSIZ_0			(0x1u<<0)

// DOEPDMA8 Configuration

#define	OTG_HS_DOEPDMA8_DMAADDR				(0xFFFFFFFFu<<0)
#define	OTG_HS_DOEPDMA8_DMAADDR_0			(0x1u<<0)

// PCGCCTL Configuration

#define	OTG_HS_PCGCCTL_SUSP					(0x1u<<7)
#define	OTG_HS_PCGCCTL_PHYSLEEP				(0x1u<<6)
#define	OTG_HS_PCGCCTL_ENL1GTG				(0x1u<<5)
#define	OTG_HS_PCGCCTL_PHYSUSP				(0x1u<<4)
#define	OTG_HS_PCGCCTL_GATEHCLK				(0x1u<<1)
#define	OTG_HS_PCGCCTL_STPPCLK				(0x1u<<0)
