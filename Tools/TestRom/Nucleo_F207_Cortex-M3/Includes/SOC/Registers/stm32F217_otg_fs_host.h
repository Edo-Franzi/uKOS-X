/*
; stm32F217_otg_fs_host.
; ======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_otg_fs_host equates.
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

// OTG_FS_HOST address definitions
// -------------------------------

typedef struct {
	volatile	uint32_t	FS_HCFG;
	volatile	uint32_t	HFIR;
	volatile	uint32_t	FS_HFNUM;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	FS_HPTXSTS;
	volatile	uint32_t	HAINT;
	volatile	uint32_t	HAINTMSK;
	volatile	uint32_t	RESERVED1[9];
	volatile	uint32_t	FS_HPRT;
	volatile	uint32_t	RESERVED2[47];
	volatile	uint32_t	FS_HCCHAR0;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	FS_HCINT0;
	volatile	uint32_t	FS_HCINTMSK0;
	volatile	uint32_t	FS_HCTSIZ0;
	volatile	uint32_t	RESERVED4[3];
	volatile	uint32_t	FS_HCCHAR1;
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	FS_HCINT1;
	volatile	uint32_t	FS_HCINTMSK1;
	volatile	uint32_t	FS_HCTSIZ1;
	volatile	uint32_t	RESERVED6[3];
	volatile	uint32_t	FS_HCCHAR2;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	FS_HCINT2;
	volatile	uint32_t	FS_HCINTMSK2;
	volatile	uint32_t	FS_HCTSIZ2;
	volatile	uint32_t	RESERVED8[3];
	volatile	uint32_t	FS_HCCHAR3;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	FS_HCINT3;
	volatile	uint32_t	FS_HCINTMSK3;
	volatile	uint32_t	FS_HCTSIZ3;
	volatile	uint32_t	RESERVED10[3];
	volatile	uint32_t	FS_HCCHAR4;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	FS_HCINT4;
	volatile	uint32_t	FS_HCINTMSK4;
	volatile	uint32_t	FS_HCTSIZ4;
	volatile	uint32_t	RESERVED12[3];
	volatile	uint32_t	FS_HCCHAR5;
	volatile	uint32_t	RESERVED13;
	volatile	uint32_t	FS_HCINT5;
	volatile	uint32_t	FS_HCINTMSK5;
	volatile	uint32_t	FS_HCTSIZ5;
	volatile	uint32_t	RESERVED14[3];
	volatile	uint32_t	FS_HCCHAR6;
	volatile	uint32_t	RESERVED15;
	volatile	uint32_t	FS_HCINT6;
	volatile	uint32_t	FS_HCINTMSK6;
	volatile	uint32_t	FS_HCTSIZ6;
	volatile	uint32_t	RESERVED16[3];
	volatile	uint32_t	FS_HCCHAR7;
	volatile	uint32_t	RESERVED17;
	volatile	uint32_t	FS_HCINT7;
	volatile	uint32_t	FS_HCINTMSK7;
	volatile	uint32_t	FS_HCTSIZ7;
} OTG_FS_HOST_TypeDef;

#if (defined(__cplusplus))
#define	OTG_FS_HOST	reinterpret_cast<OTG_FS_HOST_TypeDef *>(0x50000400u)

#else
#define	OTG_FS_HOST	((OTG_FS_HOST_TypeDef *)0x50000400u)
#endif

// FS_HCFG Configuration

#define	OTG_FS_HOST_FS_HCFG_FSLSS			(0x1u<<2)
#define	OTG_FS_HOST_FS_HCFG_FSLSPCS			(0x3u<<0)
#define	OTG_FS_HOST_FS_HCFG_FSLSPCS_0		(0x1u<<0)

// HFIR Configuration

#define	OTG_FS_HOST_HFIR_FRIVL				(0xFFFFu<<0)
#define	OTG_FS_HOST_HFIR_FRIVL_0			(0x1u<<0)

// FS_HFNUM Configuration

#define	OTG_FS_HOST_FS_HFNUM_FTREM			(0xFFFFu<<16)
#define	OTG_FS_HOST_FS_HFNUM_FTREM_0		(0x1u<<16)
#define	OTG_FS_HOST_FS_HFNUM_FRNUM			(0xFFFFu<<0)
#define	OTG_FS_HOST_FS_HFNUM_FRNUM_0		(0x1u<<0)

// FS_HPTXSTS Configuration

#define	OTG_FS_HOST_FS_HPTXSTS_PTXQTOP		(0xFFu<<24)
#define	OTG_FS_HOST_FS_HPTXSTS_PTXQTOP_0	(0x1u<<24)
#define	OTG_FS_HOST_FS_HPTXSTS_PTXQSAV		(0xFFu<<16)
#define	OTG_FS_HOST_FS_HPTXSTS_PTXQSAV_0	(0x1u<<16)
#define	OTG_FS_HOST_FS_HPTXSTS_PTXFSAVL		(0xFFFFu<<0)
#define	OTG_FS_HOST_FS_HPTXSTS_PTXFSAVL_0	(0x1u<<0)

// HAINT Configuration

#define	OTG_FS_HOST_HAINT_HAINT				(0xFFFFu<<0)
#define	OTG_FS_HOST_HAINT_HAINT_0			(0x1u<<0)

// HAINTMSK Configuration

#define	OTG_FS_HOST_HAINTMSK_HAINTM			(0xFFFFu<<0)
#define	OTG_FS_HOST_HAINTMSK_HAINTM_0		(0x1u<<0)

// FS_HPRT Configuration

#define	OTG_FS_HOST_FS_HPRT_PSPD			(0x3u<<17)
#define	OTG_FS_HOST_FS_HPRT_PSPD_0			(0x1u<<17)
#define	OTG_FS_HOST_FS_HPRT_PTCTL			(0xFu<<13)
#define	OTG_FS_HOST_FS_HPRT_PTCTL_0			(0x1u<<13)
#define	OTG_FS_HOST_FS_HPRT_PPWR			(0x1u<<12)
#define	OTG_FS_HOST_FS_HPRT_PLSTS			(0x3u<<10)
#define	OTG_FS_HOST_FS_HPRT_PLSTS_0			(0x1u<<10)
#define	OTG_FS_HOST_FS_HPRT_PRST			(0x1u<<8)
#define	OTG_FS_HOST_FS_HPRT_PSUSP			(0x1u<<7)
#define	OTG_FS_HOST_FS_HPRT_PRES			(0x1u<<6)
#define	OTG_FS_HOST_FS_HPRT_POCCHNG			(0x1u<<5)
#define	OTG_FS_HOST_FS_HPRT_POCA			(0x1u<<4)
#define	OTG_FS_HOST_FS_HPRT_PENCHNG			(0x1u<<3)
#define	OTG_FS_HOST_FS_HPRT_PENA			(0x1u<<2)
#define	OTG_FS_HOST_FS_HPRT_PCDET			(0x1u<<1)
#define	OTG_FS_HOST_FS_HPRT_PCSTS			(0x1u<<0)

// FS_HCCHAR0 Configuration

#define	OTG_FS_HOST_FS_HCCHAR0_CHENA		(0x1u<<31)
#define	OTG_FS_HOST_FS_HCCHAR0_CHDIS		(0x1u<<30)
#define	OTG_FS_HOST_FS_HCCHAR0_ODDFRM		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCCHAR0_DAD			(0x7Fu<<22)
#define	OTG_FS_HOST_FS_HCCHAR0_DAD_0		(0x1u<<22)
#define	OTG_FS_HOST_FS_HCCHAR0_MCNT			(0x3u<<20)
#define	OTG_FS_HOST_FS_HCCHAR0_MCNT_0		(0x1u<<20)
#define	OTG_FS_HOST_FS_HCCHAR0_EPTYP		(0x3u<<18)
#define	OTG_FS_HOST_FS_HCCHAR0_EPTYP_0		(0x1u<<18)
#define	OTG_FS_HOST_FS_HCCHAR0_LSDEV		(0x1u<<17)
#define	OTG_FS_HOST_FS_HCCHAR0_EPDIR		(0x1u<<15)
#define	OTG_FS_HOST_FS_HCCHAR0_EPNUM		(0xFu<<11)
#define	OTG_FS_HOST_FS_HCCHAR0_EPNUM_0		(0x1u<<11)
#define	OTG_FS_HOST_FS_HCCHAR0_MPSIZ		(0x7FFu<<0)
#define	OTG_FS_HOST_FS_HCCHAR0_MPSIZ_0		(0x1u<<0)

// FS_HCINT0 Configuration

#define	OTG_FS_HOST_FS_HCINT0_DTERR			(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINT0_FRMOR			(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINT0_BBERR			(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINT0_TXERR			(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINT0_ACK			(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINT0_NAK			(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINT0_STALL			(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINT0_CHH			(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINT0_XFRC			(0x1u<<0)

// FS_HCINTMSK0 Configuration

#define	OTG_FS_HOST_FS_HCINTMSK0_DTERRM		(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINTMSK0_FRMORM		(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINTMSK0_BBERRM		(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINTMSK0_TXERRM		(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINTMSK0_NYET		(0x1u<<6)
#define	OTG_FS_HOST_FS_HCINTMSK0_ACKM		(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINTMSK0_NAKM		(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINTMSK0_STALLM		(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINTMSK0_CHHM		(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINTMSK0_XFRCM		(0x1u<<0)

// FS_HCTSIZ0 Configuration

#define	OTG_FS_HOST_FS_HCTSIZ0_DPID			(0x3u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ0_DPID_0		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ0_PKTCNT		(0x3FFu<<19)
#define	OTG_FS_HOST_FS_HCTSIZ0_PKTCNT_0		(0x1u<<19)
#define	OTG_FS_HOST_FS_HCTSIZ0_XFRSIZ		(0x7FFFFu<<0)
#define	OTG_FS_HOST_FS_HCTSIZ0_XFRSIZ_0		(0x1u<<0)

// FS_HCCHAR1 Configuration

#define	OTG_FS_HOST_FS_HCCHAR1_CHENA		(0x1u<<31)
#define	OTG_FS_HOST_FS_HCCHAR1_CHDIS		(0x1u<<30)
#define	OTG_FS_HOST_FS_HCCHAR1_ODDFRM		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCCHAR1_DAD			(0x7Fu<<22)
#define	OTG_FS_HOST_FS_HCCHAR1_DAD_0		(0x1u<<22)
#define	OTG_FS_HOST_FS_HCCHAR1_MCNT			(0x3u<<20)
#define	OTG_FS_HOST_FS_HCCHAR1_MCNT_0		(0x1u<<20)
#define	OTG_FS_HOST_FS_HCCHAR1_EPTYP		(0x3u<<18)
#define	OTG_FS_HOST_FS_HCCHAR1_EPTYP_0		(0x1u<<18)
#define	OTG_FS_HOST_FS_HCCHAR1_LSDEV		(0x1u<<17)
#define	OTG_FS_HOST_FS_HCCHAR1_EPDIR		(0x1u<<15)
#define	OTG_FS_HOST_FS_HCCHAR1_EPNUM		(0xFu<<11)
#define	OTG_FS_HOST_FS_HCCHAR1_EPNUM_0		(0x1u<<11)
#define	OTG_FS_HOST_FS_HCCHAR1_MPSIZ		(0x7FFu<<0)
#define	OTG_FS_HOST_FS_HCCHAR1_MPSIZ_0		(0x1u<<0)

// FS_HCINT1 Configuration

#define	OTG_FS_HOST_FS_HCINT1_DTERR			(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINT1_FRMOR			(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINT1_BBERR			(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINT1_TXERR			(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINT1_ACK			(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINT1_NAK			(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINT1_STALL			(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINT1_CHH			(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINT1_XFRC			(0x1u<<0)

// FS_HCINTMSK1 Configuration

#define	OTG_FS_HOST_FS_HCINTMSK1_DTERRM		(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINTMSK1_FRMORM		(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINTMSK1_BBERRM		(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINTMSK1_TXERRM		(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINTMSK1_NYET		(0x1u<<6)
#define	OTG_FS_HOST_FS_HCINTMSK1_ACKM		(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINTMSK1_NAKM		(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINTMSK1_STALLM		(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINTMSK1_CHHM		(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINTMSK1_XFRCM		(0x1u<<0)

// FS_HCTSIZ1 Configuration

#define	OTG_FS_HOST_FS_HCTSIZ1_DPID			(0x3u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ1_DPID_0		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ1_PKTCNT		(0x3FFu<<19)
#define	OTG_FS_HOST_FS_HCTSIZ1_PKTCNT_0		(0x1u<<19)
#define	OTG_FS_HOST_FS_HCTSIZ1_XFRSIZ		(0x7FFFFu<<0)
#define	OTG_FS_HOST_FS_HCTSIZ1_XFRSIZ_0		(0x1u<<0)

// FS_HCCHAR2 Configuration

#define	OTG_FS_HOST_FS_HCCHAR2_CHENA		(0x1u<<31)
#define	OTG_FS_HOST_FS_HCCHAR2_CHDIS		(0x1u<<30)
#define	OTG_FS_HOST_FS_HCCHAR2_ODDFRM		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCCHAR2_DAD			(0x7Fu<<22)
#define	OTG_FS_HOST_FS_HCCHAR2_DAD_0		(0x1u<<22)
#define	OTG_FS_HOST_FS_HCCHAR2_MCNT			(0x3u<<20)
#define	OTG_FS_HOST_FS_HCCHAR2_MCNT_0		(0x1u<<20)
#define	OTG_FS_HOST_FS_HCCHAR2_EPTYP		(0x3u<<18)
#define	OTG_FS_HOST_FS_HCCHAR2_EPTYP_0		(0x1u<<18)
#define	OTG_FS_HOST_FS_HCCHAR2_LSDEV		(0x1u<<17)
#define	OTG_FS_HOST_FS_HCCHAR2_EPDIR		(0x1u<<15)
#define	OTG_FS_HOST_FS_HCCHAR2_EPNUM		(0xFu<<11)
#define	OTG_FS_HOST_FS_HCCHAR2_EPNUM_0		(0x1u<<11)
#define	OTG_FS_HOST_FS_HCCHAR2_MPSIZ		(0x7FFu<<0)
#define	OTG_FS_HOST_FS_HCCHAR2_MPSIZ_0		(0x1u<<0)

// FS_HCINT2 Configuration

#define	OTG_FS_HOST_FS_HCINT2_DTERR			(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINT2_FRMOR			(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINT2_BBERR			(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINT2_TXERR			(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINT2_ACK			(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINT2_NAK			(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINT2_STALL			(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINT2_CHH			(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINT2_XFRC			(0x1u<<0)

// FS_HCINTMSK2 Configuration

#define	OTG_FS_HOST_FS_HCINTMSK2_DTERRM		(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINTMSK2_FRMORM		(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINTMSK2_BBERRM		(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINTMSK2_TXERRM		(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINTMSK2_NYET		(0x1u<<6)
#define	OTG_FS_HOST_FS_HCINTMSK2_ACKM		(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINTMSK2_NAKM		(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINTMSK2_STALLM		(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINTMSK2_CHHM		(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINTMSK2_XFRCM		(0x1u<<0)

// FS_HCTSIZ2 Configuration

#define	OTG_FS_HOST_FS_HCTSIZ2_DPID			(0x3u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ2_DPID_0		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ2_PKTCNT		(0x3FFu<<19)
#define	OTG_FS_HOST_FS_HCTSIZ2_PKTCNT_0		(0x1u<<19)
#define	OTG_FS_HOST_FS_HCTSIZ2_XFRSIZ		(0x7FFFFu<<0)
#define	OTG_FS_HOST_FS_HCTSIZ2_XFRSIZ_0		(0x1u<<0)

// FS_HCCHAR3 Configuration

#define	OTG_FS_HOST_FS_HCCHAR3_CHENA		(0x1u<<31)
#define	OTG_FS_HOST_FS_HCCHAR3_CHDIS		(0x1u<<30)
#define	OTG_FS_HOST_FS_HCCHAR3_ODDFRM		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCCHAR3_DAD			(0x7Fu<<22)
#define	OTG_FS_HOST_FS_HCCHAR3_DAD_0		(0x1u<<22)
#define	OTG_FS_HOST_FS_HCCHAR3_MCNT			(0x3u<<20)
#define	OTG_FS_HOST_FS_HCCHAR3_MCNT_0		(0x1u<<20)
#define	OTG_FS_HOST_FS_HCCHAR3_EPTYP		(0x3u<<18)
#define	OTG_FS_HOST_FS_HCCHAR3_EPTYP_0		(0x1u<<18)
#define	OTG_FS_HOST_FS_HCCHAR3_LSDEV		(0x1u<<17)
#define	OTG_FS_HOST_FS_HCCHAR3_EPDIR		(0x1u<<15)
#define	OTG_FS_HOST_FS_HCCHAR3_EPNUM		(0xFu<<11)
#define	OTG_FS_HOST_FS_HCCHAR3_EPNUM_0		(0x1u<<11)
#define	OTG_FS_HOST_FS_HCCHAR3_MPSIZ		(0x7FFu<<0)
#define	OTG_FS_HOST_FS_HCCHAR3_MPSIZ_0		(0x1u<<0)

// FS_HCINT3 Configuration

#define	OTG_FS_HOST_FS_HCINT3_DTERR			(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINT3_FRMOR			(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINT3_BBERR			(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINT3_TXERR			(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINT3_ACK			(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINT3_NAK			(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINT3_STALL			(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINT3_CHH			(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINT3_XFRC			(0x1u<<0)

// FS_HCINTMSK3 Configuration

#define	OTG_FS_HOST_FS_HCINTMSK3_DTERRM		(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINTMSK3_FRMORM		(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINTMSK3_BBERRM		(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINTMSK3_TXERRM		(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINTMSK3_NYET		(0x1u<<6)
#define	OTG_FS_HOST_FS_HCINTMSK3_ACKM		(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINTMSK3_NAKM		(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINTMSK3_STALLM		(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINTMSK3_CHHM		(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINTMSK3_XFRCM		(0x1u<<0)

// FS_HCTSIZ3 Configuration

#define	OTG_FS_HOST_FS_HCTSIZ3_DPID			(0x3u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ3_DPID_0		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ3_PKTCNT		(0x3FFu<<19)
#define	OTG_FS_HOST_FS_HCTSIZ3_PKTCNT_0		(0x1u<<19)
#define	OTG_FS_HOST_FS_HCTSIZ3_XFRSIZ		(0x7FFFFu<<0)
#define	OTG_FS_HOST_FS_HCTSIZ3_XFRSIZ_0		(0x1u<<0)

// FS_HCCHAR4 Configuration

#define	OTG_FS_HOST_FS_HCCHAR4_CHENA		(0x1u<<31)
#define	OTG_FS_HOST_FS_HCCHAR4_CHDIS		(0x1u<<30)
#define	OTG_FS_HOST_FS_HCCHAR4_ODDFRM		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCCHAR4_DAD			(0x7Fu<<22)
#define	OTG_FS_HOST_FS_HCCHAR4_DAD_0		(0x1u<<22)
#define	OTG_FS_HOST_FS_HCCHAR4_MCNT			(0x3u<<20)
#define	OTG_FS_HOST_FS_HCCHAR4_MCNT_0		(0x1u<<20)
#define	OTG_FS_HOST_FS_HCCHAR4_EPTYP		(0x3u<<18)
#define	OTG_FS_HOST_FS_HCCHAR4_EPTYP_0		(0x1u<<18)
#define	OTG_FS_HOST_FS_HCCHAR4_LSDEV		(0x1u<<17)
#define	OTG_FS_HOST_FS_HCCHAR4_EPDIR		(0x1u<<15)
#define	OTG_FS_HOST_FS_HCCHAR4_EPNUM		(0xFu<<11)
#define	OTG_FS_HOST_FS_HCCHAR4_EPNUM_0		(0x1u<<11)
#define	OTG_FS_HOST_FS_HCCHAR4_MPSIZ		(0x7FFu<<0)
#define	OTG_FS_HOST_FS_HCCHAR4_MPSIZ_0		(0x1u<<0)

// FS_HCINT4 Configuration

#define	OTG_FS_HOST_FS_HCINT4_DTERR			(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINT4_FRMOR			(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINT4_BBERR			(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINT4_TXERR			(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINT4_ACK			(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINT4_NAK			(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINT4_STALL			(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINT4_CHH			(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINT4_XFRC			(0x1u<<0)

// FS_HCINTMSK4 Configuration

#define	OTG_FS_HOST_FS_HCINTMSK4_DTERRM		(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINTMSK4_FRMORM		(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINTMSK4_BBERRM		(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINTMSK4_TXERRM		(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINTMSK4_NYET		(0x1u<<6)
#define	OTG_FS_HOST_FS_HCINTMSK4_ACKM		(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINTMSK4_NAKM		(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINTMSK4_STALLM		(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINTMSK4_CHHM		(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINTMSK4_XFRCM		(0x1u<<0)

// FS_HCTSIZ4 Configuration

#define	OTG_FS_HOST_FS_HCTSIZ4_DPID			(0x3u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ4_DPID_0		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ4_PKTCNT		(0x3FFu<<19)
#define	OTG_FS_HOST_FS_HCTSIZ4_PKTCNT_0		(0x1u<<19)
#define	OTG_FS_HOST_FS_HCTSIZ4_XFRSIZ		(0x7FFFFu<<0)
#define	OTG_FS_HOST_FS_HCTSIZ4_XFRSIZ_0		(0x1u<<0)

// FS_HCCHAR5 Configuration

#define	OTG_FS_HOST_FS_HCCHAR5_CHENA		(0x1u<<31)
#define	OTG_FS_HOST_FS_HCCHAR5_CHDIS		(0x1u<<30)
#define	OTG_FS_HOST_FS_HCCHAR5_ODDFRM		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCCHAR5_DAD			(0x7Fu<<22)
#define	OTG_FS_HOST_FS_HCCHAR5_DAD_0		(0x1u<<22)
#define	OTG_FS_HOST_FS_HCCHAR5_MCNT			(0x3u<<20)
#define	OTG_FS_HOST_FS_HCCHAR5_MCNT_0		(0x1u<<20)
#define	OTG_FS_HOST_FS_HCCHAR5_EPTYP		(0x3u<<18)
#define	OTG_FS_HOST_FS_HCCHAR5_EPTYP_0		(0x1u<<18)
#define	OTG_FS_HOST_FS_HCCHAR5_LSDEV		(0x1u<<17)
#define	OTG_FS_HOST_FS_HCCHAR5_EPDIR		(0x1u<<15)
#define	OTG_FS_HOST_FS_HCCHAR5_EPNUM		(0xFu<<11)
#define	OTG_FS_HOST_FS_HCCHAR5_EPNUM_0		(0x1u<<11)
#define	OTG_FS_HOST_FS_HCCHAR5_MPSIZ		(0x7FFu<<0)
#define	OTG_FS_HOST_FS_HCCHAR5_MPSIZ_0		(0x1u<<0)

// FS_HCINT5 Configuration

#define	OTG_FS_HOST_FS_HCINT5_DTERR			(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINT5_FRMOR			(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINT5_BBERR			(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINT5_TXERR			(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINT5_ACK			(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINT5_NAK			(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINT5_STALL			(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINT5_CHH			(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINT5_XFRC			(0x1u<<0)

// FS_HCINTMSK5 Configuration

#define	OTG_FS_HOST_FS_HCINTMSK5_DTERRM		(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINTMSK5_FRMORM		(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINTMSK5_BBERRM		(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINTMSK5_TXERRM		(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINTMSK5_NYET		(0x1u<<6)
#define	OTG_FS_HOST_FS_HCINTMSK5_ACKM		(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINTMSK5_NAKM		(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINTMSK5_STALLM		(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINTMSK5_CHHM		(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINTMSK5_XFRCM		(0x1u<<0)

// FS_HCTSIZ5 Configuration

#define	OTG_FS_HOST_FS_HCTSIZ5_DPID			(0x3u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ5_DPID_0		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ5_PKTCNT		(0x3FFu<<19)
#define	OTG_FS_HOST_FS_HCTSIZ5_PKTCNT_0		(0x1u<<19)
#define	OTG_FS_HOST_FS_HCTSIZ5_XFRSIZ		(0x7FFFFu<<0)
#define	OTG_FS_HOST_FS_HCTSIZ5_XFRSIZ_0		(0x1u<<0)

// FS_HCCHAR6 Configuration

#define	OTG_FS_HOST_FS_HCCHAR6_CHENA		(0x1u<<31)
#define	OTG_FS_HOST_FS_HCCHAR6_CHDIS		(0x1u<<30)
#define	OTG_FS_HOST_FS_HCCHAR6_ODDFRM		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCCHAR6_DAD			(0x7Fu<<22)
#define	OTG_FS_HOST_FS_HCCHAR6_DAD_0		(0x1u<<22)
#define	OTG_FS_HOST_FS_HCCHAR6_MCNT			(0x3u<<20)
#define	OTG_FS_HOST_FS_HCCHAR6_MCNT_0		(0x1u<<20)
#define	OTG_FS_HOST_FS_HCCHAR6_EPTYP		(0x3u<<18)
#define	OTG_FS_HOST_FS_HCCHAR6_EPTYP_0		(0x1u<<18)
#define	OTG_FS_HOST_FS_HCCHAR6_LSDEV		(0x1u<<17)
#define	OTG_FS_HOST_FS_HCCHAR6_EPDIR		(0x1u<<15)
#define	OTG_FS_HOST_FS_HCCHAR6_EPNUM		(0xFu<<11)
#define	OTG_FS_HOST_FS_HCCHAR6_EPNUM_0		(0x1u<<11)
#define	OTG_FS_HOST_FS_HCCHAR6_MPSIZ		(0x7FFu<<0)
#define	OTG_FS_HOST_FS_HCCHAR6_MPSIZ_0		(0x1u<<0)

// FS_HCINT6 Configuration

#define	OTG_FS_HOST_FS_HCINT6_DTERR			(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINT6_FRMOR			(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINT6_BBERR			(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINT6_TXERR			(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINT6_ACK			(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINT6_NAK			(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINT6_STALL			(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINT6_CHH			(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINT6_XFRC			(0x1u<<0)

// FS_HCINTMSK6 Configuration

#define	OTG_FS_HOST_FS_HCINTMSK6_DTERRM		(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINTMSK6_FRMORM		(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINTMSK6_BBERRM		(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINTMSK6_TXERRM		(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINTMSK6_NYET		(0x1u<<6)
#define	OTG_FS_HOST_FS_HCINTMSK6_ACKM		(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINTMSK6_NAKM		(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINTMSK6_STALLM		(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINTMSK6_CHHM		(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINTMSK6_XFRCM		(0x1u<<0)

// FS_HCTSIZ6 Configuration

#define	OTG_FS_HOST_FS_HCTSIZ6_DPID			(0x3u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ6_DPID_0		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ6_PKTCNT		(0x3FFu<<19)
#define	OTG_FS_HOST_FS_HCTSIZ6_PKTCNT_0		(0x1u<<19)
#define	OTG_FS_HOST_FS_HCTSIZ6_XFRSIZ		(0x7FFFFu<<0)
#define	OTG_FS_HOST_FS_HCTSIZ6_XFRSIZ_0		(0x1u<<0)

// FS_HCCHAR7 Configuration

#define	OTG_FS_HOST_FS_HCCHAR7_CHENA		(0x1u<<31)
#define	OTG_FS_HOST_FS_HCCHAR7_CHDIS		(0x1u<<30)
#define	OTG_FS_HOST_FS_HCCHAR7_ODDFRM		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCCHAR7_DAD			(0x7Fu<<22)
#define	OTG_FS_HOST_FS_HCCHAR7_DAD_0		(0x1u<<22)
#define	OTG_FS_HOST_FS_HCCHAR7_MCNT			(0x3u<<20)
#define	OTG_FS_HOST_FS_HCCHAR7_MCNT_0		(0x1u<<20)
#define	OTG_FS_HOST_FS_HCCHAR7_EPTYP		(0x3u<<18)
#define	OTG_FS_HOST_FS_HCCHAR7_EPTYP_0		(0x1u<<18)
#define	OTG_FS_HOST_FS_HCCHAR7_LSDEV		(0x1u<<17)
#define	OTG_FS_HOST_FS_HCCHAR7_EPDIR		(0x1u<<15)
#define	OTG_FS_HOST_FS_HCCHAR7_EPNUM		(0xFu<<11)
#define	OTG_FS_HOST_FS_HCCHAR7_EPNUM_0		(0x1u<<11)
#define	OTG_FS_HOST_FS_HCCHAR7_MPSIZ		(0x7FFu<<0)
#define	OTG_FS_HOST_FS_HCCHAR7_MPSIZ_0		(0x1u<<0)

// FS_HCINT7 Configuration

#define	OTG_FS_HOST_FS_HCINT7_DTERR			(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINT7_FRMOR			(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINT7_BBERR			(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINT7_TXERR			(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINT7_ACK			(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINT7_NAK			(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINT7_STALL			(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINT7_CHH			(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINT7_XFRC			(0x1u<<0)

// FS_HCINTMSK7 Configuration

#define	OTG_FS_HOST_FS_HCINTMSK7_DTERRM		(0x1u<<10)
#define	OTG_FS_HOST_FS_HCINTMSK7_FRMORM		(0x1u<<9)
#define	OTG_FS_HOST_FS_HCINTMSK7_BBERRM		(0x1u<<8)
#define	OTG_FS_HOST_FS_HCINTMSK7_TXERRM		(0x1u<<7)
#define	OTG_FS_HOST_FS_HCINTMSK7_NYET		(0x1u<<6)
#define	OTG_FS_HOST_FS_HCINTMSK7_ACKM		(0x1u<<5)
#define	OTG_FS_HOST_FS_HCINTMSK7_NAKM		(0x1u<<4)
#define	OTG_FS_HOST_FS_HCINTMSK7_STALLM		(0x1u<<3)
#define	OTG_FS_HOST_FS_HCINTMSK7_CHHM		(0x1u<<1)
#define	OTG_FS_HOST_FS_HCINTMSK7_XFRCM		(0x1u<<0)

// FS_HCTSIZ7 Configuration

#define	OTG_FS_HOST_FS_HCTSIZ7_DPID			(0x3u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ7_DPID_0		(0x1u<<29)
#define	OTG_FS_HOST_FS_HCTSIZ7_PKTCNT		(0x3FFu<<19)
#define	OTG_FS_HOST_FS_HCTSIZ7_PKTCNT_0		(0x1u<<19)
#define	OTG_FS_HOST_FS_HCTSIZ7_XFRSIZ		(0x7FFFFu<<0)
#define	OTG_FS_HOST_FS_HCTSIZ7_XFRSIZ_0		(0x1u<<0)
