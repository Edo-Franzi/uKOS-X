/*
; stm32L4R5_otg_fs_device.
; ========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_otg_fs_device equates.
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

// OTG_FS_DEVICE address definitions
// ---------------------------------

typedef struct {
	volatile	uint32_t	FS_DCFG;
	volatile	uint32_t	FS_DCTL;
	volatile	uint32_t	FS_DSTS;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	FS_DIEPMSK;
	volatile	uint32_t	FS_DOEPMSK;
	volatile	uint32_t	FS_DAINT;
	volatile	uint32_t	FS_DAINTMSK;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	DVBUSDIS;
	volatile	uint32_t	DVBUSPULSE;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	DIEPEMPMSK;
	volatile	uint32_t	RESERVED3[50];
	volatile	uint32_t	FS_DIEPCTL0;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	DIEPINT0;
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	DIEPTSIZ0;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	DTXFSTS0;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	DIEPCTL1;
	volatile	uint32_t	RESERVED8;
	volatile	uint32_t	DIEPINT1;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	DIEPTSIZ1;
	volatile	uint32_t	RESERVED10;
	volatile	uint32_t	DTXFSTS1;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	DIEPCTL2;
	volatile	uint32_t	RESERVED12;
	volatile	uint32_t	DIEPINT2;
	volatile	uint32_t	RESERVED13;
	volatile	uint32_t	DIEPTSIZ2;
	volatile	uint32_t	RESERVED14;
	volatile	uint32_t	DTXFSTS2;
	volatile	uint32_t	RESERVED15;
	volatile	uint32_t	DIEPCTL3;
	volatile	uint32_t	RESERVED16;
	volatile	uint32_t	DIEPINT3;
	volatile	uint32_t	RESERVED17;
	volatile	uint32_t	DIEPTSIZ3;
	volatile	uint32_t	RESERVED18;
	volatile	uint32_t	DTXFSTS3;
	volatile	uint32_t	RESERVED19[97];
	volatile	uint32_t	DOEPCTL0;
	volatile	uint32_t	RESERVED20;
	volatile	uint32_t	DOEPINT0;
	volatile	uint32_t	RESERVED21;
	volatile	uint32_t	DOEPTSIZ0;
	volatile	uint32_t	RESERVED22[3];
	volatile	uint32_t	DOEPCTL1;
	volatile	uint32_t	RESERVED23;
	volatile	uint32_t	DOEPINT1;
	volatile	uint32_t	RESERVED24;
	volatile	uint32_t	DOEPTSIZ1;
	volatile	uint32_t	RESERVED25[3];
	volatile	uint32_t	DOEPCTL2;
	volatile	uint32_t	RESERVED26;
	volatile	uint32_t	DOEPINT2;
	volatile	uint32_t	RESERVED27;
	volatile	uint32_t	DOEPTSIZ2;
	volatile	uint32_t	RESERVED28[3];
	volatile	uint32_t	DOEPCTL3;
	volatile	uint32_t	RESERVED29;
	volatile	uint32_t	DOEPINT3;
	volatile	uint32_t	RESERVED30;
	volatile	uint32_t	DOEPTSIZ3;
} OTG_FS_DEVICE_TypeDef;

#if (defined(__cplusplus))
#define	OTG_FS_DEVICE	reinterpret_cast<OTG_FS_DEVICE_TypeDef *>(0x50000800u)

#else
#define	OTG_FS_DEVICE	((OTG_FS_DEVICE_TypeDef *)0x50000800u)
#endif

// FS_DCFG Configuration

#define	OTG_FS_DEVICE_FS_DCFG_PFIVL					(0x3u<<11)
#define	OTG_FS_DEVICE_FS_DCFG_PFIVL_0				(0x1u<<11)
#define	OTG_FS_DEVICE_FS_DCFG_DAD					(0x7Fu<<4)
#define	OTG_FS_DEVICE_FS_DCFG_DAD_0					(0x1u<<4)
#define	OTG_FS_DEVICE_FS_DCFG_NZLSOHSK				(0x1u<<2)
#define	OTG_FS_DEVICE_FS_DCFG_DSPD					(0x3u<<0)
#define	OTG_FS_DEVICE_FS_DCFG_DSPD_0				(0x1u<<0)

// FS_DCTL Configuration

#define	OTG_FS_DEVICE_FS_DCTL_POPRGDNE				(0x1u<<11)
#define	OTG_FS_DEVICE_FS_DCTL_CGONAK				(0x1u<<10)
#define	OTG_FS_DEVICE_FS_DCTL_SGONAK				(0x1u<<9)
#define	OTG_FS_DEVICE_FS_DCTL_CGINAK				(0x1u<<8)
#define	OTG_FS_DEVICE_FS_DCTL_SGINAK				(0x1u<<7)
#define	OTG_FS_DEVICE_FS_DCTL_TCTL					(0x7u<<4)
#define	OTG_FS_DEVICE_FS_DCTL_TCTL_0				(0x1u<<4)
#define	OTG_FS_DEVICE_FS_DCTL_GONSTS				(0x1u<<3)
#define	OTG_FS_DEVICE_FS_DCTL_GINSTS				(0x1u<<2)
#define	OTG_FS_DEVICE_FS_DCTL_SDIS					(0x1u<<1)
#define	OTG_FS_DEVICE_FS_DCTL_RWUSIG				(0x1u<<0)

// FS_DSTS Configuration

#define	OTG_FS_DEVICE_FS_DSTS_FNSOF					(0x3FFFu<<8)
#define	OTG_FS_DEVICE_FS_DSTS_FNSOF_0				(0x1u<<8)
#define	OTG_FS_DEVICE_FS_DSTS_EERR					(0x1u<<3)
#define	OTG_FS_DEVICE_FS_DSTS_ENUMSPD				(0x3u<<1)
#define	OTG_FS_DEVICE_FS_DSTS_ENUMSPD_0				(0x1u<<1)
#define	OTG_FS_DEVICE_FS_DSTS_SUSPSTS				(0x1u<<0)

// FS_DIEPMSK Configuration

#define	OTG_FS_DEVICE_FS_DIEPMSK_INEPNEM			(0x1u<<6)
#define	OTG_FS_DEVICE_FS_DIEPMSK_INEPNMM			(0x1u<<5)
#define	OTG_FS_DEVICE_FS_DIEPMSK_ITTXFEMSK			(0x1u<<4)
#define	OTG_FS_DEVICE_FS_DIEPMSK_TOM				(0x1u<<3)
#define	OTG_FS_DEVICE_FS_DIEPMSK_EPDM				(0x1u<<1)
#define	OTG_FS_DEVICE_FS_DIEPMSK_XFRCM				(0x1u<<0)

// FS_DOEPMSK Configuration

#define	OTG_FS_DEVICE_FS_DOEPMSK_OTEPDM				(0x1u<<4)
#define	OTG_FS_DEVICE_FS_DOEPMSK_STUPM				(0x1u<<3)
#define	OTG_FS_DEVICE_FS_DOEPMSK_EPDM				(0x1u<<1)
#define	OTG_FS_DEVICE_FS_DOEPMSK_XFRCM				(0x1u<<0)

// FS_DAINT Configuration

#define	OTG_FS_DEVICE_FS_DAINT_OEPINT				(0xFFFFu<<16)
#define	OTG_FS_DEVICE_FS_DAINT_OEPINT_0				(0x1u<<16)
#define	OTG_FS_DEVICE_FS_DAINT_IEPINT				(0xFFFFu<<0)
#define	OTG_FS_DEVICE_FS_DAINT_IEPINT_0				(0x1u<<0)

// FS_DAINTMSK Configuration

#define	OTG_FS_DEVICE_FS_DAINTMSK_OEPINT			(0xFFFFu<<16)
#define	OTG_FS_DEVICE_FS_DAINTMSK_OEPINT_0			(0x1u<<16)
#define	OTG_FS_DEVICE_FS_DAINTMSK_IEPM				(0xFFFFu<<0)
#define	OTG_FS_DEVICE_FS_DAINTMSK_IEPM_0			(0x1u<<0)

// DVBUSDIS Configuration

#define	OTG_FS_DEVICE_DVBUSDIS_VBUSDT				(0xFFFFu<<0)
#define	OTG_FS_DEVICE_DVBUSDIS_VBUSDT_0				(0x1u<<0)

// DVBUSPULSE Configuration

#define	OTG_FS_DEVICE_DVBUSPULSE_DVBUSP				(0xFFFu<<0)
#define	OTG_FS_DEVICE_DVBUSPULSE_DVBUSP_0			(0x1u<<0)

// DIEPEMPMSK Configuration

#define	OTG_FS_DEVICE_DIEPEMPMSK_INEPTXFEM			(0xFFFFu<<0)
#define	OTG_FS_DEVICE_DIEPEMPMSK_INEPTXFEM_0		(0x1u<<0)

// FS_DIEPCTL0 Configuration

#define	OTG_FS_DEVICE_FS_DIEPCTL0_EPENA				(0x1u<<31)
#define	OTG_FS_DEVICE_FS_DIEPCTL0_EPDIS				(0x1u<<30)
#define	OTG_FS_DEVICE_FS_DIEPCTL0_SNAK				(0x1u<<27)
#define	OTG_FS_DEVICE_FS_DIEPCTL0_CNAK				(0x1u<<26)
#define	OTG_FS_DEVICE_FS_DIEPCTL0_TXFNUM			(0xFu<<22)
#define	OTG_FS_DEVICE_FS_DIEPCTL0_TXFNUM_0			(0x1u<<22)
#define	OTG_FS_DEVICE_FS_DIEPCTL0_STALL				(0x1u<<21)
#define	OTG_FS_DEVICE_FS_DIEPCTL0_EPTYP				(0x3u<<18)
#define	OTG_FS_DEVICE_FS_DIEPCTL0_EPTYP_0			(0x1u<<18)
#define	OTG_FS_DEVICE_FS_DIEPCTL0_NAKSTS			(0x1u<<17)
#define	OTG_FS_DEVICE_FS_DIEPCTL0_USBAEP			(0x1u<<15)
#define	OTG_FS_DEVICE_FS_DIEPCTL0_MPSIZ				(0x3u<<0)
#define	OTG_FS_DEVICE_FS_DIEPCTL0_MPSIZ_0			(0x1u<<0)

// DIEPINT0 Configuration

#define	OTG_FS_DEVICE_DIEPINT0_XFRC					(0x1u<<0)
#define	OTG_FS_DEVICE_DIEPINT0_EPDISD				(0x1u<<1)
#define	OTG_FS_DEVICE_DIEPINT0_TOC					(0x1u<<3)
#define	OTG_FS_DEVICE_DIEPINT0_ITTXFE				(0x1u<<4)
#define	OTG_FS_DEVICE_DIEPINT0_INEPNE				(0x1u<<6)
#define	OTG_FS_DEVICE_DIEPINT0_TXFE					(0x1u<<7)

// DIEPTSIZ0 Configuration

#define	OTG_FS_DEVICE_DIEPTSIZ0_XFRSIZ				(0x7Fu<<0)
#define	OTG_FS_DEVICE_DIEPTSIZ0_XFRSIZ_0			(0x1u<<0)
#define	OTG_FS_DEVICE_DIEPTSIZ0_PKTCNT				(0x3u<<19)
#define	OTG_FS_DEVICE_DIEPTSIZ0_PKTCNT_0			(0x1u<<19)

// DTXFSTS0 Configuration

#define	OTG_FS_DEVICE_DTXFSTS0_INEPTFSAV			(0xFFFFu<<0)
#define	OTG_FS_DEVICE_DTXFSTS0_INEPTFSAV_0			(0x1u<<0)

// DIEPCTL1 Configuration

#define	OTG_FS_DEVICE_DIEPCTL1_MPSIZ				(0x7FFu<<0)
#define	OTG_FS_DEVICE_DIEPCTL1_MPSIZ_0				(0x1u<<0)
#define	OTG_FS_DEVICE_DIEPCTL1_USBAEP				(0x1u<<15)
#define	OTG_FS_DEVICE_DIEPCTL1_EONUM_DPID			(0x1u<<16)
#define	OTG_FS_DEVICE_DIEPCTL1_NAKSTS				(0x1u<<17)
#define	OTG_FS_DEVICE_DIEPCTL1_EPTYP				(0x3u<<18)
#define	OTG_FS_DEVICE_DIEPCTL1_EPTYP_0				(0x1u<<18)
#define	OTG_FS_DEVICE_DIEPCTL1_STALL				(0x1u<<21)
#define	OTG_FS_DEVICE_DIEPCTL1_TXFNUM				(0xFu<<22)
#define	OTG_FS_DEVICE_DIEPCTL1_TXFNUM_0				(0x1u<<22)
#define	OTG_FS_DEVICE_DIEPCTL1_CNAK					(0x1u<<26)
#define	OTG_FS_DEVICE_DIEPCTL1_SNAK					(0x1u<<27)
#define	OTG_FS_DEVICE_DIEPCTL1_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_FS_DEVICE_DIEPCTL1_SODDFRM_SD1PID		(0x1u<<29)
#define	OTG_FS_DEVICE_DIEPCTL1_EPDIS				(0x1u<<30)
#define	OTG_FS_DEVICE_DIEPCTL1_EPENA				(0x1u<<31)

// DIEPINT1 Configuration

#define	OTG_FS_DEVICE_DIEPINT1_XFRC					(0x1u<<0)
#define	OTG_FS_DEVICE_DIEPINT1_EPDISD				(0x1u<<1)
#define	OTG_FS_DEVICE_DIEPINT1_TOC					(0x1u<<3)
#define	OTG_FS_DEVICE_DIEPINT1_ITTXFE				(0x1u<<4)
#define	OTG_FS_DEVICE_DIEPINT1_INEPNE				(0x1u<<6)
#define	OTG_FS_DEVICE_DIEPINT1_TXFE					(0x1u<<7)

// DIEPTSIZ1 Configuration

#define	OTG_FS_DEVICE_DIEPTSIZ1_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_FS_DEVICE_DIEPTSIZ1_XFRSIZ_0			(0x1u<<0)
#define	OTG_FS_DEVICE_DIEPTSIZ1_PKTCNT				(0x3FFu<<19)
#define	OTG_FS_DEVICE_DIEPTSIZ1_PKTCNT_0			(0x1u<<19)
#define	OTG_FS_DEVICE_DIEPTSIZ1_MCNT				(0x3u<<29)
#define	OTG_FS_DEVICE_DIEPTSIZ1_MCNT_0				(0x1u<<29)

// DTXFSTS1 Configuration

#define	OTG_FS_DEVICE_DTXFSTS1_INEPTFSAV			(0xFFFFu<<0)
#define	OTG_FS_DEVICE_DTXFSTS1_INEPTFSAV_0			(0x1u<<0)

// DIEPCTL2 Configuration

#define	OTG_FS_DEVICE_DIEPCTL2_MPSIZ				(0x7FFu<<0)
#define	OTG_FS_DEVICE_DIEPCTL2_MPSIZ_0				(0x1u<<0)
#define	OTG_FS_DEVICE_DIEPCTL2_USBAEP				(0x1u<<15)
#define	OTG_FS_DEVICE_DIEPCTL2_EONUM_DPID			(0x1u<<16)
#define	OTG_FS_DEVICE_DIEPCTL2_NAKSTS				(0x1u<<17)
#define	OTG_FS_DEVICE_DIEPCTL2_EPTYP				(0x3u<<18)
#define	OTG_FS_DEVICE_DIEPCTL2_EPTYP_0				(0x1u<<18)
#define	OTG_FS_DEVICE_DIEPCTL2_STALL				(0x1u<<21)
#define	OTG_FS_DEVICE_DIEPCTL2_TXFNUM				(0xFu<<22)
#define	OTG_FS_DEVICE_DIEPCTL2_TXFNUM_0				(0x1u<<22)
#define	OTG_FS_DEVICE_DIEPCTL2_CNAK					(0x1u<<26)
#define	OTG_FS_DEVICE_DIEPCTL2_SNAK					(0x1u<<27)
#define	OTG_FS_DEVICE_DIEPCTL2_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_FS_DEVICE_DIEPCTL2_SODDFRM				(0x1u<<29)
#define	OTG_FS_DEVICE_DIEPCTL2_EPDIS				(0x1u<<30)
#define	OTG_FS_DEVICE_DIEPCTL2_EPENA				(0x1u<<31)

// DIEPINT2 Configuration

#define	OTG_FS_DEVICE_DIEPINT2_XFRC					(0x1u<<0)
#define	OTG_FS_DEVICE_DIEPINT2_EPDISD				(0x1u<<1)
#define	OTG_FS_DEVICE_DIEPINT2_TOC					(0x1u<<3)
#define	OTG_FS_DEVICE_DIEPINT2_ITTXFE				(0x1u<<4)
#define	OTG_FS_DEVICE_DIEPINT2_INEPNE				(0x1u<<6)
#define	OTG_FS_DEVICE_DIEPINT2_TXFE					(0x1u<<7)

// DIEPTSIZ2 Configuration

#define	OTG_FS_DEVICE_DIEPTSIZ2_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_FS_DEVICE_DIEPTSIZ2_XFRSIZ_0			(0x1u<<0)
#define	OTG_FS_DEVICE_DIEPTSIZ2_PKTCNT				(0x3FFu<<19)
#define	OTG_FS_DEVICE_DIEPTSIZ2_PKTCNT_0			(0x1u<<19)
#define	OTG_FS_DEVICE_DIEPTSIZ2_MCNT				(0x3u<<29)
#define	OTG_FS_DEVICE_DIEPTSIZ2_MCNT_0				(0x1u<<29)

// DTXFSTS2 Configuration

#define	OTG_FS_DEVICE_DTXFSTS2_INEPTFSAV			(0xFFFFu<<0)
#define	OTG_FS_DEVICE_DTXFSTS2_INEPTFSAV_0			(0x1u<<0)

// DIEPCTL3 Configuration

#define	OTG_FS_DEVICE_DIEPCTL3_MPSIZ				(0x7FFu<<0)
#define	OTG_FS_DEVICE_DIEPCTL3_MPSIZ_0				(0x1u<<0)
#define	OTG_FS_DEVICE_DIEPCTL3_USBAEP				(0x1u<<15)
#define	OTG_FS_DEVICE_DIEPCTL3_EONUM_DPID			(0x1u<<16)
#define	OTG_FS_DEVICE_DIEPCTL3_NAKSTS				(0x1u<<17)
#define	OTG_FS_DEVICE_DIEPCTL3_EPTYP				(0x3u<<18)
#define	OTG_FS_DEVICE_DIEPCTL3_EPTYP_0				(0x1u<<18)
#define	OTG_FS_DEVICE_DIEPCTL3_STALL				(0x1u<<21)
#define	OTG_FS_DEVICE_DIEPCTL3_TXFNUM				(0xFu<<22)
#define	OTG_FS_DEVICE_DIEPCTL3_TXFNUM_0				(0x1u<<22)
#define	OTG_FS_DEVICE_DIEPCTL3_CNAK					(0x1u<<26)
#define	OTG_FS_DEVICE_DIEPCTL3_SNAK					(0x1u<<27)
#define	OTG_FS_DEVICE_DIEPCTL3_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_FS_DEVICE_DIEPCTL3_SODDFRM				(0x1u<<29)
#define	OTG_FS_DEVICE_DIEPCTL3_EPDIS				(0x1u<<30)
#define	OTG_FS_DEVICE_DIEPCTL3_EPENA				(0x1u<<31)

// DIEPINT3 Configuration

#define	OTG_FS_DEVICE_DIEPINT3_XFRC					(0x1u<<0)
#define	OTG_FS_DEVICE_DIEPINT3_EPDISD				(0x1u<<1)
#define	OTG_FS_DEVICE_DIEPINT3_TOC					(0x1u<<3)
#define	OTG_FS_DEVICE_DIEPINT3_ITTXFE				(0x1u<<4)
#define	OTG_FS_DEVICE_DIEPINT3_INEPNE				(0x1u<<6)
#define	OTG_FS_DEVICE_DIEPINT3_TXFE					(0x1u<<7)

// DIEPTSIZ3 Configuration

#define	OTG_FS_DEVICE_DIEPTSIZ3_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_FS_DEVICE_DIEPTSIZ3_XFRSIZ_0			(0x1u<<0)
#define	OTG_FS_DEVICE_DIEPTSIZ3_PKTCNT				(0x3FFu<<19)
#define	OTG_FS_DEVICE_DIEPTSIZ3_PKTCNT_0			(0x1u<<19)
#define	OTG_FS_DEVICE_DIEPTSIZ3_MCNT				(0x3u<<29)
#define	OTG_FS_DEVICE_DIEPTSIZ3_MCNT_0				(0x1u<<29)

// DTXFSTS3 Configuration

#define	OTG_FS_DEVICE_DTXFSTS3_INEPTFSAV			(0xFFFFu<<0)
#define	OTG_FS_DEVICE_DTXFSTS3_INEPTFSAV_0			(0x1u<<0)

// DOEPCTL0 Configuration

#define	OTG_FS_DEVICE_DOEPCTL0_MPSIZ				(0x3u<<0)
#define	OTG_FS_DEVICE_DOEPCTL0_MPSIZ_0				(0x1u<<0)
#define	OTG_FS_DEVICE_DOEPCTL0_USBAEP				(0x1u<<15)
#define	OTG_FS_DEVICE_DOEPCTL0_NAKSTS				(0x1u<<17)
#define	OTG_FS_DEVICE_DOEPCTL0_EPTYP				(0x3u<<18)
#define	OTG_FS_DEVICE_DOEPCTL0_EPTYP_0				(0x1u<<18)
#define	OTG_FS_DEVICE_DOEPCTL0_SNPM					(0x1u<<20)
#define	OTG_FS_DEVICE_DOEPCTL0_STALL				(0x1u<<21)
#define	OTG_FS_DEVICE_DOEPCTL0_CNAK					(0x1u<<26)
#define	OTG_FS_DEVICE_DOEPCTL0_SNAK					(0x1u<<27)
#define	OTG_FS_DEVICE_DOEPCTL0_EPDIS				(0x1u<<30)
#define	OTG_FS_DEVICE_DOEPCTL0_EPENA				(0x1u<<31)

// DOEPINT0 Configuration

#define	OTG_FS_DEVICE_DOEPINT0_XFRC					(0x1u<<0)
#define	OTG_FS_DEVICE_DOEPINT0_EPDISD				(0x1u<<1)
#define	OTG_FS_DEVICE_DOEPINT0_STUP					(0x1u<<3)
#define	OTG_FS_DEVICE_DOEPINT0_OTEPDIS				(0x1u<<4)
#define	OTG_FS_DEVICE_DOEPINT0_B2BSTUP				(0x1u<<6)

// DOEPTSIZ0 Configuration

#define	OTG_FS_DEVICE_DOEPTSIZ0_XFRSIZ				(0x7Fu<<0)
#define	OTG_FS_DEVICE_DOEPTSIZ0_XFRSIZ_0			(0x1u<<0)
#define	OTG_FS_DEVICE_DOEPTSIZ0_PKTCNT				(0x1u<<19)
#define	OTG_FS_DEVICE_DOEPTSIZ0_STUPCNT				(0x3u<<29)
#define	OTG_FS_DEVICE_DOEPTSIZ0_STUPCNT_0			(0x1u<<29)

// DOEPCTL1 Configuration

#define	OTG_FS_DEVICE_DOEPCTL1_MPSIZ				(0x7FFu<<0)
#define	OTG_FS_DEVICE_DOEPCTL1_MPSIZ_0				(0x1u<<0)
#define	OTG_FS_DEVICE_DOEPCTL1_USBAEP				(0x1u<<15)
#define	OTG_FS_DEVICE_DOEPCTL1_EONUM_DPID			(0x1u<<16)
#define	OTG_FS_DEVICE_DOEPCTL1_NAKSTS				(0x1u<<17)
#define	OTG_FS_DEVICE_DOEPCTL1_EPTYP				(0x3u<<18)
#define	OTG_FS_DEVICE_DOEPCTL1_EPTYP_0				(0x1u<<18)
#define	OTG_FS_DEVICE_DOEPCTL1_SNPM					(0x1u<<20)
#define	OTG_FS_DEVICE_DOEPCTL1_STALL				(0x1u<<21)
#define	OTG_FS_DEVICE_DOEPCTL1_CNAK					(0x1u<<26)
#define	OTG_FS_DEVICE_DOEPCTL1_SNAK					(0x1u<<27)
#define	OTG_FS_DEVICE_DOEPCTL1_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_FS_DEVICE_DOEPCTL1_SODDFRM				(0x1u<<29)
#define	OTG_FS_DEVICE_DOEPCTL1_EPDIS				(0x1u<<30)
#define	OTG_FS_DEVICE_DOEPCTL1_EPENA				(0x1u<<31)

// DOEPINT1 Configuration

#define	OTG_FS_DEVICE_DOEPINT1_XFRC					(0x1u<<0)
#define	OTG_FS_DEVICE_DOEPINT1_EPDISD				(0x1u<<1)
#define	OTG_FS_DEVICE_DOEPINT1_STUP					(0x1u<<3)
#define	OTG_FS_DEVICE_DOEPINT1_OTEPDIS				(0x1u<<4)
#define	OTG_FS_DEVICE_DOEPINT1_B2BSTUP				(0x1u<<6)

// DOEPTSIZ1 Configuration

#define	OTG_FS_DEVICE_DOEPTSIZ1_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_FS_DEVICE_DOEPTSIZ1_XFRSIZ_0			(0x1u<<0)
#define	OTG_FS_DEVICE_DOEPTSIZ1_PKTCNT				(0x3FFu<<19)
#define	OTG_FS_DEVICE_DOEPTSIZ1_PKTCNT_0			(0x1u<<19)
#define	OTG_FS_DEVICE_DOEPTSIZ1_RXDPID_STUPCNT		(0x3u<<29)
#define	OTG_FS_DEVICE_DOEPTSIZ1_RXDPID_STUPCNT_0	(0x1u<<29)

// DOEPCTL2 Configuration

#define	OTG_FS_DEVICE_DOEPCTL2_MPSIZ				(0x7FFu<<0)
#define	OTG_FS_DEVICE_DOEPCTL2_MPSIZ_0				(0x1u<<0)
#define	OTG_FS_DEVICE_DOEPCTL2_USBAEP				(0x1u<<15)
#define	OTG_FS_DEVICE_DOEPCTL2_EONUM_DPID			(0x1u<<16)
#define	OTG_FS_DEVICE_DOEPCTL2_NAKSTS				(0x1u<<17)
#define	OTG_FS_DEVICE_DOEPCTL2_EPTYP				(0x3u<<18)
#define	OTG_FS_DEVICE_DOEPCTL2_EPTYP_0				(0x1u<<18)
#define	OTG_FS_DEVICE_DOEPCTL2_SNPM					(0x1u<<20)
#define	OTG_FS_DEVICE_DOEPCTL2_STALL				(0x1u<<21)
#define	OTG_FS_DEVICE_DOEPCTL2_CNAK					(0x1u<<26)
#define	OTG_FS_DEVICE_DOEPCTL2_SNAK					(0x1u<<27)
#define	OTG_FS_DEVICE_DOEPCTL2_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_FS_DEVICE_DOEPCTL2_SODDFRM				(0x1u<<29)
#define	OTG_FS_DEVICE_DOEPCTL2_EPDIS				(0x1u<<30)
#define	OTG_FS_DEVICE_DOEPCTL2_EPENA				(0x1u<<31)

// DOEPINT2 Configuration

#define	OTG_FS_DEVICE_DOEPINT2_XFRC					(0x1u<<0)
#define	OTG_FS_DEVICE_DOEPINT2_EPDISD				(0x1u<<1)
#define	OTG_FS_DEVICE_DOEPINT2_STUP					(0x1u<<3)
#define	OTG_FS_DEVICE_DOEPINT2_OTEPDIS				(0x1u<<4)
#define	OTG_FS_DEVICE_DOEPINT2_B2BSTUP				(0x1u<<6)

// DOEPTSIZ2 Configuration

#define	OTG_FS_DEVICE_DOEPTSIZ2_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_FS_DEVICE_DOEPTSIZ2_XFRSIZ_0			(0x1u<<0)
#define	OTG_FS_DEVICE_DOEPTSIZ2_PKTCNT				(0x3FFu<<19)
#define	OTG_FS_DEVICE_DOEPTSIZ2_PKTCNT_0			(0x1u<<19)
#define	OTG_FS_DEVICE_DOEPTSIZ2_RXDPID_STUPCNT		(0x3u<<29)
#define	OTG_FS_DEVICE_DOEPTSIZ2_RXDPID_STUPCNT_0	(0x1u<<29)

// DOEPCTL3 Configuration

#define	OTG_FS_DEVICE_DOEPCTL3_MPSIZ				(0x7FFu<<0)
#define	OTG_FS_DEVICE_DOEPCTL3_MPSIZ_0				(0x1u<<0)
#define	OTG_FS_DEVICE_DOEPCTL3_USBAEP				(0x1u<<15)
#define	OTG_FS_DEVICE_DOEPCTL3_EONUM_DPID			(0x1u<<16)
#define	OTG_FS_DEVICE_DOEPCTL3_NAKSTS				(0x1u<<17)
#define	OTG_FS_DEVICE_DOEPCTL3_EPTYP				(0x3u<<18)
#define	OTG_FS_DEVICE_DOEPCTL3_EPTYP_0				(0x1u<<18)
#define	OTG_FS_DEVICE_DOEPCTL3_SNPM					(0x1u<<20)
#define	OTG_FS_DEVICE_DOEPCTL3_STALL				(0x1u<<21)
#define	OTG_FS_DEVICE_DOEPCTL3_CNAK					(0x1u<<26)
#define	OTG_FS_DEVICE_DOEPCTL3_SNAK					(0x1u<<27)
#define	OTG_FS_DEVICE_DOEPCTL3_SD0PID_SEVNFRM		(0x1u<<28)
#define	OTG_FS_DEVICE_DOEPCTL3_SODDFRM				(0x1u<<29)
#define	OTG_FS_DEVICE_DOEPCTL3_EPDIS				(0x1u<<30)
#define	OTG_FS_DEVICE_DOEPCTL3_EPENA				(0x1u<<31)

// DOEPINT3 Configuration

#define	OTG_FS_DEVICE_DOEPINT3_XFRC					(0x1u<<0)
#define	OTG_FS_DEVICE_DOEPINT3_EPDISD				(0x1u<<1)
#define	OTG_FS_DEVICE_DOEPINT3_STUP					(0x1u<<3)
#define	OTG_FS_DEVICE_DOEPINT3_OTEPDIS				(0x1u<<4)
#define	OTG_FS_DEVICE_DOEPINT3_B2BSTUP				(0x1u<<6)

// DOEPTSIZ3 Configuration

#define	OTG_FS_DEVICE_DOEPTSIZ3_XFRSIZ				(0x7FFFFu<<0)
#define	OTG_FS_DEVICE_DOEPTSIZ3_XFRSIZ_0			(0x1u<<0)
#define	OTG_FS_DEVICE_DOEPTSIZ3_PKTCNT				(0x3FFu<<19)
#define	OTG_FS_DEVICE_DOEPTSIZ3_PKTCNT_0			(0x1u<<19)
#define	OTG_FS_DEVICE_DOEPTSIZ3_RXDPID_STUPCNT		(0x3u<<29)
#define	OTG_FS_DEVICE_DOEPTSIZ3_RXDPID_STUPCNT_0	(0x1u<<29)
