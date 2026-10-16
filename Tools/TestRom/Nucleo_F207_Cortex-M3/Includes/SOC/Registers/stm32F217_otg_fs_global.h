/*
; stm32F217_otg_fs_global.
; ========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_otg_fs_global equates.
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

// OTG_FS_GLOBAL address definitions
// ---------------------------------

typedef struct {
	volatile	uint32_t	FS_GOTGCTL;
	volatile	uint32_t	FS_GOTGINT;
	volatile	uint32_t	FS_GAHBCFG;
	volatile	uint32_t	FS_GUSBCFG;
	volatile	uint32_t	FS_GRSTCTL;
	volatile	uint32_t	FS_GINTSTS;
	volatile	uint32_t	FS_GINTMSK;
	volatile	uint32_t	FS_GRXSTSR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	FS_GRXFSIZ;
	volatile	uint32_t	FS_GNPTXFSIZ;
	volatile	uint32_t	FS_GNPTXSTS;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	FS_GCCFG;
	volatile	uint32_t	FS_CID;
	volatile	uint32_t	RESERVED2[48];
	volatile	uint32_t	FS_HPTXFSIZ;
	volatile	uint32_t	FS_DIEPTXF1;
	volatile	uint32_t	FS_DIEPTXF2;
	volatile	uint32_t	FS_DIEPTXF3;
} OTG_FS_GLOBAL_TypeDef;

#if (defined(__cplusplus))
#define	OTG_FS_GLOBAL	reinterpret_cast<OTG_FS_GLOBAL_TypeDef *>(0x50000000u)

#else
#define	OTG_FS_GLOBAL	((OTG_FS_GLOBAL_TypeDef *)0x50000000u)
#endif

// FS_GOTGCTL Configuration

#define	OTG_FS_GLOBAL_FS_GOTGCTL_BSVLD				(0x1u<<19)
#define	OTG_FS_GLOBAL_FS_GOTGCTL_ASVLD				(0x1u<<18)
#define	OTG_FS_GLOBAL_FS_GOTGCTL_DBCT				(0x1u<<17)
#define	OTG_FS_GLOBAL_FS_GOTGCTL_CIDSTS				(0x1u<<16)
#define	OTG_FS_GLOBAL_FS_GOTGCTL_DHNPEN				(0x1u<<11)
#define	OTG_FS_GLOBAL_FS_GOTGCTL_HSHNPEN			(0x1u<<10)
#define	OTG_FS_GLOBAL_FS_GOTGCTL_HNPRQ				(0x1u<<9)
#define	OTG_FS_GLOBAL_FS_GOTGCTL_HNGSCS				(0x1u<<8)
#define	OTG_FS_GLOBAL_FS_GOTGCTL_SRQ				(0x1u<<1)
#define	OTG_FS_GLOBAL_FS_GOTGCTL_SRQSCS				(0x1u<<0)

// FS_GOTGINT Configuration

#define	OTG_FS_GLOBAL_FS_GOTGINT_DBCDNE				(0x1u<<19)
#define	OTG_FS_GLOBAL_FS_GOTGINT_ADTOCHG			(0x1u<<18)
#define	OTG_FS_GLOBAL_FS_GOTGINT_HNGDET				(0x1u<<17)
#define	OTG_FS_GLOBAL_FS_GOTGINT_HNSSCHG			(0x1u<<9)
#define	OTG_FS_GLOBAL_FS_GOTGINT_SRSSCHG			(0x1u<<8)
#define	OTG_FS_GLOBAL_FS_GOTGINT_SEDET				(0x1u<<2)

// FS_GAHBCFG Configuration

#define	OTG_FS_GLOBAL_FS_GAHBCFG_PTXFELVL			(0x1u<<8)
#define	OTG_FS_GLOBAL_FS_GAHBCFG_TXFELVL			(0x1u<<7)
#define	OTG_FS_GLOBAL_FS_GAHBCFG_GINT				(0x1u<<0)

// FS_GUSBCFG Configuration

#define	OTG_FS_GLOBAL_FS_GUSBCFG_CTXPKT				(0x1u<<31)
#define	OTG_FS_GLOBAL_FS_GUSBCFG_FDMOD				(0x1u<<30)
#define	OTG_FS_GLOBAL_FS_GUSBCFG_FHMOD				(0x1u<<29)
#define	OTG_FS_GLOBAL_FS_GUSBCFG_TRDT				(0xFu<<10)
#define	OTG_FS_GLOBAL_FS_GUSBCFG_TRDT_0				(0x1u<<10)
#define	OTG_FS_GLOBAL_FS_GUSBCFG_HNPCAP				(0x1u<<9)
#define	OTG_FS_GLOBAL_FS_GUSBCFG_SRPCAP				(0x1u<<8)
#define	OTG_FS_GLOBAL_FS_GUSBCFG_PHYSEL				(0x1u<<6)
#define	OTG_FS_GLOBAL_FS_GUSBCFG_TOCAL				(0x7u<<0)
#define	OTG_FS_GLOBAL_FS_GUSBCFG_TOCAL_0			(0x1u<<0)

// FS_GRSTCTL Configuration

#define	OTG_FS_GLOBAL_FS_GRSTCTL_AHBIDL				(0x1u<<31)
#define	OTG_FS_GLOBAL_FS_GRSTCTL_TXFNUM				(0x1Fu<<6)
#define	OTG_FS_GLOBAL_FS_GRSTCTL_TXFNUM_0			(0x1u<<6)
#define	OTG_FS_GLOBAL_FS_GRSTCTL_TXFFLSH			(0x1u<<5)
#define	OTG_FS_GLOBAL_FS_GRSTCTL_RXFFLSH			(0x1u<<4)
#define	OTG_FS_GLOBAL_FS_GRSTCTL_FCRST				(0x1u<<2)
#define	OTG_FS_GLOBAL_FS_GRSTCTL_HSRST				(0x1u<<1)
#define	OTG_FS_GLOBAL_FS_GRSTCTL_CSRST				(0x1u<<0)

// FS_GINTSTS Configuration

#define	OTG_FS_GLOBAL_FS_GINTSTS_WKUPINT			(0x1u<<31)
#define	OTG_FS_GLOBAL_FS_GINTSTS_SRQINT				(0x1u<<30)
#define	OTG_FS_GLOBAL_FS_GINTSTS_DISCINT			(0x1u<<29)
#define	OTG_FS_GLOBAL_FS_GINTSTS_CIDSCHG			(0x1u<<28)
#define	OTG_FS_GLOBAL_FS_GINTSTS_PTXFE				(0x1u<<26)
#define	OTG_FS_GLOBAL_FS_GINTSTS_HCINT				(0x1u<<25)
#define	OTG_FS_GLOBAL_FS_GINTSTS_HPRTINT			(0x1u<<24)
#define	OTG_FS_GLOBAL_FS_GINTSTS_IPXFR_INCOMPISOOUT	(0x1u<<21)
#define	OTG_FS_GLOBAL_FS_GINTSTS_IISOIXFR			(0x1u<<20)
#define	OTG_FS_GLOBAL_FS_GINTSTS_OEPINT				(0x1u<<19)
#define	OTG_FS_GLOBAL_FS_GINTSTS_IEPINT				(0x1u<<18)
#define	OTG_FS_GLOBAL_FS_GINTSTS_EOPF				(0x1u<<15)
#define	OTG_FS_GLOBAL_FS_GINTSTS_ISOODRP			(0x1u<<14)
#define	OTG_FS_GLOBAL_FS_GINTSTS_ENUMDNE			(0x1u<<13)
#define	OTG_FS_GLOBAL_FS_GINTSTS_USBRST				(0x1u<<12)
#define	OTG_FS_GLOBAL_FS_GINTSTS_USBSUSP			(0x1u<<11)
#define	OTG_FS_GLOBAL_FS_GINTSTS_ESUSP				(0x1u<<10)
#define	OTG_FS_GLOBAL_FS_GINTSTS_GOUTNAKEFF			(0x1u<<7)
#define	OTG_FS_GLOBAL_FS_GINTSTS_GINAKEFF			(0x1u<<6)
#define	OTG_FS_GLOBAL_FS_GINTSTS_NPTXFE				(0x1u<<5)
#define	OTG_FS_GLOBAL_FS_GINTSTS_RXFLVL				(0x1u<<4)
#define	OTG_FS_GLOBAL_FS_GINTSTS_SOF				(0x1u<<3)
#define	OTG_FS_GLOBAL_FS_GINTSTS_OTGINT				(0x1u<<2)
#define	OTG_FS_GLOBAL_FS_GINTSTS_MMIS				(0x1u<<1)
#define	OTG_FS_GLOBAL_FS_GINTSTS_CMOD				(0x1u<<0)

// FS_GINTMSK Configuration

#define	OTG_FS_GLOBAL_FS_GINTMSK_WUIM				(0x1u<<31)
#define	OTG_FS_GLOBAL_FS_GINTMSK_SRQIM				(0x1u<<30)
#define	OTG_FS_GLOBAL_FS_GINTMSK_DISCINT			(0x1u<<29)
#define	OTG_FS_GLOBAL_FS_GINTMSK_CIDSCHGM			(0x1u<<28)
#define	OTG_FS_GLOBAL_FS_GINTMSK_PTXFEM				(0x1u<<26)
#define	OTG_FS_GLOBAL_FS_GINTMSK_HCIM				(0x1u<<25)
#define	OTG_FS_GLOBAL_FS_GINTMSK_PRTIM				(0x1u<<24)
#define	OTG_FS_GLOBAL_FS_GINTMSK_IPXFRM_IISOOXFRM	(0x1u<<21)
#define	OTG_FS_GLOBAL_FS_GINTMSK_IISOIXFRM			(0x1u<<20)
#define	OTG_FS_GLOBAL_FS_GINTMSK_OEPINT				(0x1u<<19)
#define	OTG_FS_GLOBAL_FS_GINTMSK_IEPINT				(0x1u<<18)
#define	OTG_FS_GLOBAL_FS_GINTMSK_EPMISM				(0x1u<<17)
#define	OTG_FS_GLOBAL_FS_GINTMSK_EOPFM				(0x1u<<15)
#define	OTG_FS_GLOBAL_FS_GINTMSK_ISOODRPM			(0x1u<<14)
#define	OTG_FS_GLOBAL_FS_GINTMSK_ENUMDNEM			(0x1u<<13)
#define	OTG_FS_GLOBAL_FS_GINTMSK_USBRST				(0x1u<<12)
#define	OTG_FS_GLOBAL_FS_GINTMSK_USBSUSPM			(0x1u<<11)
#define	OTG_FS_GLOBAL_FS_GINTMSK_ESUSPM				(0x1u<<10)
#define	OTG_FS_GLOBAL_FS_GINTMSK_GONAKEFFM			(0x1u<<7)
#define	OTG_FS_GLOBAL_FS_GINTMSK_GINAKEFFM			(0x1u<<6)
#define	OTG_FS_GLOBAL_FS_GINTMSK_NPTXFEM			(0x1u<<5)
#define	OTG_FS_GLOBAL_FS_GINTMSK_RXFLVLM			(0x1u<<4)
#define	OTG_FS_GLOBAL_FS_GINTMSK_SOFM				(0x1u<<3)
#define	OTG_FS_GLOBAL_FS_GINTMSK_OTGINT				(0x1u<<2)
#define	OTG_FS_GLOBAL_FS_GINTMSK_MMISM				(0x1u<<1)

// FS_GRXSTSR Configuration

#define	OTG_FS_GLOBAL_FS_GRXSTSR_FRMNUM				(0xFu<<21)
#define	OTG_FS_GLOBAL_FS_GRXSTSR_FRMNUM_0			(0x1u<<21)
#define	OTG_FS_GLOBAL_FS_GRXSTSR_PKTSTS				(0xFu<<17)
#define	OTG_FS_GLOBAL_FS_GRXSTSR_PKTSTS_0			(0x1u<<17)
#define	OTG_FS_GLOBAL_FS_GRXSTSR_DPID				(0x3u<<15)
#define	OTG_FS_GLOBAL_FS_GRXSTSR_DPID_0				(0x1u<<15)
#define	OTG_FS_GLOBAL_FS_GRXSTSR_BCNT				(0x7FFu<<4)
#define	OTG_FS_GLOBAL_FS_GRXSTSR_BCNT_0				(0x1u<<4)
#define	OTG_FS_GLOBAL_FS_GRXSTSR_EPNUM				(0xFu<<0)
#define	OTG_FS_GLOBAL_FS_GRXSTSR_EPNUM_0			(0x1u<<0)

// FS_GRXFSIZ Configuration

#define	OTG_FS_GLOBAL_FS_GRXFSIZ_RXFD				(0xFFFFu<<0)
#define	OTG_FS_GLOBAL_FS_GRXFSIZ_RXFD_0				(0x1u<<0)

// FS_GNPTXFSIZ Configuration

#define	OTG_FS_GLOBAL_FS_GNPTXFSIZ_TX0FD			(0xFFFFu<<16)
#define	OTG_FS_GLOBAL_FS_GNPTXFSIZ_TX0FD_0			(0x1u<<16)
#define	OTG_FS_GLOBAL_FS_GNPTXFSIZ_TX0FSA			(0xFFFFu<<0)
#define	OTG_FS_GLOBAL_FS_GNPTXFSIZ_TX0FSA_0			(0x1u<<0)

// FS_GNPTXSTS Configuration

#define	OTG_FS_GLOBAL_FS_GNPTXSTS_NPTXQTOP			(0x7Fu<<24)
#define	OTG_FS_GLOBAL_FS_GNPTXSTS_NPTXQTOP_0		(0x1u<<24)
#define	OTG_FS_GLOBAL_FS_GNPTXSTS_NPTQXSAV			(0xFFu<<16)
#define	OTG_FS_GLOBAL_FS_GNPTXSTS_NPTQXSAV_0		(0x1u<<16)
#define	OTG_FS_GLOBAL_FS_GNPTXSTS_NPTXFSAV			(0xFFFFu<<0)
#define	OTG_FS_GLOBAL_FS_GNPTXSTS_NPTXFSAV_0		(0x1u<<0)

// FS_GCCFG Configuration

#define	OTG_FS_GLOBAL_FS_GCCFG_SOFOUTEN				(0x1u<<20)
#define	OTG_FS_GLOBAL_FS_GCCFG_VBUSBSEN				(0x1u<<19)
#define	OTG_FS_GLOBAL_FS_GCCFG_VBUSASEN				(0x1u<<18)
#define	OTG_FS_GLOBAL_FS_GCCFG_PWRDWN				(0x1u<<16)

// FS_CID Configuration

#define	OTG_FS_GLOBAL_FS_CID_PRODUCT_ID				(0xFFFFFFFFu<<0)
#define	OTG_FS_GLOBAL_FS_CID_PRODUCT_ID_0			(0x1u<<0)

// FS_HPTXFSIZ Configuration

#define	OTG_FS_GLOBAL_FS_HPTXFSIZ_PTXFSIZ			(0xFFFFu<<16)
#define	OTG_FS_GLOBAL_FS_HPTXFSIZ_PTXFSIZ_0			(0x1u<<16)
#define	OTG_FS_GLOBAL_FS_HPTXFSIZ_PTXSA				(0xFFFFu<<0)
#define	OTG_FS_GLOBAL_FS_HPTXFSIZ_PTXSA_0			(0x1u<<0)

// FS_DIEPTXF1 Configuration

#define	OTG_FS_GLOBAL_FS_DIEPTXF1_INEPTXFD			(0xFFFFu<<16)
#define	OTG_FS_GLOBAL_FS_DIEPTXF1_INEPTXFD_0		(0x1u<<16)
#define	OTG_FS_GLOBAL_FS_DIEPTXF1_INEPTXSA			(0xFFFFu<<0)
#define	OTG_FS_GLOBAL_FS_DIEPTXF1_INEPTXSA_0		(0x1u<<0)

// FS_DIEPTXF2 Configuration

#define	OTG_FS_GLOBAL_FS_DIEPTXF2_INEPTXFD			(0xFFFFu<<16)
#define	OTG_FS_GLOBAL_FS_DIEPTXF2_INEPTXFD_0		(0x1u<<16)
#define	OTG_FS_GLOBAL_FS_DIEPTXF2_INEPTXSA			(0xFFFFu<<0)
#define	OTG_FS_GLOBAL_FS_DIEPTXF2_INEPTXSA_0		(0x1u<<0)

// FS_DIEPTXF3 Configuration

#define	OTG_FS_GLOBAL_FS_DIEPTXF3_INEPTXFD			(0xFFFFu<<16)
#define	OTG_FS_GLOBAL_FS_DIEPTXF3_INEPTXFD_0		(0x1u<<16)
#define	OTG_FS_GLOBAL_FS_DIEPTXF3_INEPTXSA			(0xFFFFu<<0)
#define	OTG_FS_GLOBAL_FS_DIEPTXF3_INEPTXSA_0		(0x1u<<0)
