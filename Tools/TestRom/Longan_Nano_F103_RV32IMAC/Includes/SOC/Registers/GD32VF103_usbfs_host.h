/*
; GD32VF103_usbfs_host.
; =====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_usbfs_host equates.
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

// USBFS_HOST address definitions
// ------------------------------

typedef struct {
	volatile	uint32_t	HCTL;
	volatile	uint32_t	HFT;
	volatile	uint32_t	HFINFR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	HPTFQSTAT;
	volatile	uint32_t	HACHINT;
	volatile	uint32_t	HACHINTEN;
	volatile	uint32_t	RESERVED1[9];
	volatile	uint32_t	HPCS;
	volatile	uint32_t	RESERVED2[47];
	volatile	uint32_t	HCH0CTL;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	HCH0INTF;
	volatile	uint32_t	HCH0INTEN;
	volatile	uint32_t	HCH0LEN;
	volatile	uint32_t	RESERVED4[3];
	volatile	uint32_t	HCH1CTL;
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	HCH1INTF;
	volatile	uint32_t	HCH1INTEN;
	volatile	uint32_t	HCH1LEN;
	volatile	uint32_t	RESERVED6[3];
	volatile	uint32_t	HCH2CTL;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	HCH2INTF;
	volatile	uint32_t	HCH2INTEN;
	volatile	uint32_t	HCH2LEN;
	volatile	uint32_t	RESERVED8[3];
	volatile	uint32_t	HCH3CTL;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	HCH3INTF;
	volatile	uint32_t	HCH3INTEN;
	volatile	uint32_t	HCH3LEN;
	volatile	uint32_t	RESERVED10[3];
	volatile	uint32_t	HCH4CTL;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	HCH4INTF;
	volatile	uint32_t	HCH4INTEN;
	volatile	uint32_t	HCH4LEN;
	volatile	uint32_t	RESERVED12[3];
	volatile	uint32_t	HCH5CTL;
	volatile	uint32_t	RESERVED13;
	volatile	uint32_t	HCH5INTF;
	volatile	uint32_t	HCH5INTEN;
	volatile	uint32_t	HCH5LEN;
	volatile	uint32_t	RESERVED14[3];
	volatile	uint32_t	HCH6CTL;
	volatile	uint32_t	RESERVED15;
	volatile	uint32_t	HCH6INTF;
	volatile	uint32_t	HCH6INTEN;
	volatile	uint32_t	HCH6LEN;
	volatile	uint32_t	RESERVED16[3];
	volatile	uint32_t	HCH7CTL;
	volatile	uint32_t	RESERVED17;
	volatile	uint32_t	HCH7INTF;
	volatile	uint32_t	HCH7INTEN;
	volatile	uint32_t	HCH7LEN;
} USBFS_HOST_TypeDef;

#if (defined(__cplusplus))
#define	USBFS_HOST	reinterpret_cast<USBFS_HOST_TypeDef *>(0x50000400u)

#else
#define	USBFS_HOST	((USBFS_HOST_TypeDef *)0x50000400u)
#endif

// HCTL Configuration

#define	USBFS_HOST_HCTL_CLKSEL			(0x3u<<0)
#define	USBFS_HOST_HCTL_CLKSEL_0		(0x1u<<0)

// HFT Configuration

#define	USBFS_HOST_HFT_FRI				(0xFFFFu<<0)
#define	USBFS_HOST_HFT_FRI_0			(0x1u<<0)

// HFINFR Configuration

#define	USBFS_HOST_HFINFR_FRT			(0xFFFFu<<16)
#define	USBFS_HOST_HFINFR_FRT_0			(0x1u<<16)
#define	USBFS_HOST_HFINFR_FRNUM			(0xFFFFu<<0)
#define	USBFS_HOST_HFINFR_FRNUM_0		(0x1u<<0)

// HPTFQSTAT Configuration

#define	USBFS_HOST_HPTFQSTAT_PTXREQT	(0xFFu<<24)
#define	USBFS_HOST_HPTFQSTAT_PTXREQT_0	(0x1u<<24)
#define	USBFS_HOST_HPTFQSTAT_PTXREQS	(0xFFu<<16)
#define	USBFS_HOST_HPTFQSTAT_PTXREQS_0	(0x1u<<16)
#define	USBFS_HOST_HPTFQSTAT_PTXFS		(0xFFFFu<<0)
#define	USBFS_HOST_HPTFQSTAT_PTXFS_0	(0x1u<<0)

// HACHINT Configuration

#define	USBFS_HOST_HACHINT_HACHINT		(0xFFu<<0)
#define	USBFS_HOST_HACHINT_HACHINT_0	(0x1u<<0)

// HACHINTEN Configuration

#define	USBFS_HOST_HACHINTEN_CINTEN		(0xFFu<<0)
#define	USBFS_HOST_HACHINTEN_CINTEN_0	(0x1u<<0)

// HPCS Configuration

#define	USBFS_HOST_HPCS_PS				(0x3u<<17)
#define	USBFS_HOST_HPCS_PS_0			(0x1u<<17)
#define	USBFS_HOST_HPCS_PP				(0x1u<<12)
#define	USBFS_HOST_HPCS_PLST			(0x3u<<10)
#define	USBFS_HOST_HPCS_PLST_0			(0x1u<<10)
#define	USBFS_HOST_HPCS_PRST			(0x1u<<8)
#define	USBFS_HOST_HPCS_PSP				(0x1u<<7)
#define	USBFS_HOST_HPCS_PREM			(0x1u<<6)
#define	USBFS_HOST_HPCS_PEDC			(0x1u<<3)
#define	USBFS_HOST_HPCS_PE				(0x1u<<2)
#define	USBFS_HOST_HPCS_PCD				(0x1u<<1)
#define	USBFS_HOST_HPCS_PCST			(0x1u<<0)

// HCH0CTL Configuration

#define	USBFS_HOST_HCH0CTL_CEN			(0x1u<<31)
#define	USBFS_HOST_HCH0CTL_CDIS			(0x1u<<30)
#define	USBFS_HOST_HCH0CTL_ODDFRM		(0x1u<<29)
#define	USBFS_HOST_HCH0CTL_DAR			(0x7Fu<<22)
#define	USBFS_HOST_HCH0CTL_DAR_0		(0x1u<<22)
#define	USBFS_HOST_HCH0CTL_EPTYPE		(0x3u<<18)
#define	USBFS_HOST_HCH0CTL_EPTYPE_0		(0x1u<<18)
#define	USBFS_HOST_HCH0CTL_LSD			(0x1u<<17)
#define	USBFS_HOST_HCH0CTL_EPDIR		(0x1u<<15)
#define	USBFS_HOST_HCH0CTL_EPNUM		(0xFu<<11)
#define	USBFS_HOST_HCH0CTL_EPNUM_0		(0x1u<<11)
#define	USBFS_HOST_HCH0CTL_MPL			(0x7FFu<<0)
#define	USBFS_HOST_HCH0CTL_MPL_0		(0x1u<<0)

// HCH0INTF Configuration

#define	USBFS_HOST_HCH0INTF_DTER		(0x1u<<10)
#define	USBFS_HOST_HCH0INTF_REQOVR		(0x1u<<9)
#define	USBFS_HOST_HCH0INTF_BBER		(0x1u<<8)
#define	USBFS_HOST_HCH0INTF_USBER		(0x1u<<7)
#define	USBFS_HOST_HCH0INTF_ACK			(0x1u<<5)
#define	USBFS_HOST_HCH0INTF_NAK			(0x1u<<4)
#define	USBFS_HOST_HCH0INTF_STALL		(0x1u<<3)
#define	USBFS_HOST_HCH0INTF_CH			(0x1u<<1)
#define	USBFS_HOST_HCH0INTF_TF			(0x1u<<0)

// HCH0INTEN Configuration

#define	USBFS_HOST_HCH0INTEN_DTERIE		(0x1u<<10)
#define	USBFS_HOST_HCH0INTEN_REQOVRIE	(0x1u<<9)
#define	USBFS_HOST_HCH0INTEN_BBERIE		(0x1u<<8)
#define	USBFS_HOST_HCH0INTEN_USBERIE	(0x1u<<7)
#define	USBFS_HOST_HCH0INTEN_ACKIE		(0x1u<<5)
#define	USBFS_HOST_HCH0INTEN_NAKIE		(0x1u<<4)
#define	USBFS_HOST_HCH0INTEN_STALLIE	(0x1u<<3)
#define	USBFS_HOST_HCH0INTEN_CHIE		(0x1u<<1)
#define	USBFS_HOST_HCH0INTEN_TFIE		(0x1u<<0)

// HCH0LEN Configuration

#define	USBFS_HOST_HCH0LEN_DPID			(0x3u<<29)
#define	USBFS_HOST_HCH0LEN_DPID_0		(0x1u<<29)
#define	USBFS_HOST_HCH0LEN_PCNT			(0x3FFu<<19)
#define	USBFS_HOST_HCH0LEN_PCNT_0		(0x1u<<19)
#define	USBFS_HOST_HCH0LEN_TLEN			(0x7FFFFu<<0)
#define	USBFS_HOST_HCH0LEN_TLEN_0		(0x1u<<0)

// HCH1CTL Configuration

#define	USBFS_HOST_HCH1CTL_CEN			(0x1u<<31)
#define	USBFS_HOST_HCH1CTL_CDIS			(0x1u<<30)
#define	USBFS_HOST_HCH1CTL_ODDFRM		(0x1u<<29)
#define	USBFS_HOST_HCH1CTL_DAR			(0x7Fu<<22)
#define	USBFS_HOST_HCH1CTL_DAR_0		(0x1u<<22)
#define	USBFS_HOST_HCH1CTL_EPTYPE		(0x3u<<18)
#define	USBFS_HOST_HCH1CTL_EPTYPE_0		(0x1u<<18)
#define	USBFS_HOST_HCH1CTL_LSD			(0x1u<<17)
#define	USBFS_HOST_HCH1CTL_EPDIR		(0x1u<<15)
#define	USBFS_HOST_HCH1CTL_EPNUM		(0xFu<<11)
#define	USBFS_HOST_HCH1CTL_EPNUM_0		(0x1u<<11)
#define	USBFS_HOST_HCH1CTL_MPL			(0x7FFu<<0)
#define	USBFS_HOST_HCH1CTL_MPL_0		(0x1u<<0)

// HCH1INTF Configuration

#define	USBFS_HOST_HCH1INTF_DTER		(0x1u<<10)
#define	USBFS_HOST_HCH1INTF_REQOVR		(0x1u<<9)
#define	USBFS_HOST_HCH1INTF_BBER		(0x1u<<8)
#define	USBFS_HOST_HCH1INTF_USBER		(0x1u<<7)
#define	USBFS_HOST_HCH1INTF_ACK			(0x1u<<5)
#define	USBFS_HOST_HCH1INTF_NAK			(0x1u<<4)
#define	USBFS_HOST_HCH1INTF_STALL		(0x1u<<3)
#define	USBFS_HOST_HCH1INTF_CH			(0x1u<<1)
#define	USBFS_HOST_HCH1INTF_TF			(0x1u<<0)

// HCH1INTEN Configuration

#define	USBFS_HOST_HCH1INTEN_DTERIE		(0x1u<<10)
#define	USBFS_HOST_HCH1INTEN_REQOVRIE	(0x1u<<9)
#define	USBFS_HOST_HCH1INTEN_BBERIE		(0x1u<<8)
#define	USBFS_HOST_HCH1INTEN_USBERIE	(0x1u<<7)
#define	USBFS_HOST_HCH1INTEN_ACKIE		(0x1u<<5)
#define	USBFS_HOST_HCH1INTEN_NAKIE		(0x1u<<4)
#define	USBFS_HOST_HCH1INTEN_STALLIE	(0x1u<<3)
#define	USBFS_HOST_HCH1INTEN_CHIE		(0x1u<<1)
#define	USBFS_HOST_HCH1INTEN_TFIE		(0x1u<<0)

// HCH1LEN Configuration

#define	USBFS_HOST_HCH1LEN_DPID			(0x3u<<29)
#define	USBFS_HOST_HCH1LEN_DPID_0		(0x1u<<29)
#define	USBFS_HOST_HCH1LEN_PCNT			(0x3FFu<<19)
#define	USBFS_HOST_HCH1LEN_PCNT_0		(0x1u<<19)
#define	USBFS_HOST_HCH1LEN_TLEN			(0x7FFFFu<<0)
#define	USBFS_HOST_HCH1LEN_TLEN_0		(0x1u<<0)

// HCH2CTL Configuration

#define	USBFS_HOST_HCH2CTL_CEN			(0x1u<<31)
#define	USBFS_HOST_HCH2CTL_CDIS			(0x1u<<30)
#define	USBFS_HOST_HCH2CTL_ODDFRM		(0x1u<<29)
#define	USBFS_HOST_HCH2CTL_DAR			(0x7Fu<<22)
#define	USBFS_HOST_HCH2CTL_DAR_0		(0x1u<<22)
#define	USBFS_HOST_HCH2CTL_EPTYPE		(0x3u<<18)
#define	USBFS_HOST_HCH2CTL_EPTYPE_0		(0x1u<<18)
#define	USBFS_HOST_HCH2CTL_LSD			(0x1u<<17)
#define	USBFS_HOST_HCH2CTL_EPDIR		(0x1u<<15)
#define	USBFS_HOST_HCH2CTL_EPNUM		(0xFu<<11)
#define	USBFS_HOST_HCH2CTL_EPNUM_0		(0x1u<<11)
#define	USBFS_HOST_HCH2CTL_MPL			(0x7FFu<<0)
#define	USBFS_HOST_HCH2CTL_MPL_0		(0x1u<<0)

// HCH2INTF Configuration

#define	USBFS_HOST_HCH2INTF_DTER		(0x1u<<10)
#define	USBFS_HOST_HCH2INTF_REQOVR		(0x1u<<9)
#define	USBFS_HOST_HCH2INTF_BBER		(0x1u<<8)
#define	USBFS_HOST_HCH2INTF_USBER		(0x1u<<7)
#define	USBFS_HOST_HCH2INTF_ACK			(0x1u<<5)
#define	USBFS_HOST_HCH2INTF_NAK			(0x1u<<4)
#define	USBFS_HOST_HCH2INTF_STALL		(0x1u<<3)
#define	USBFS_HOST_HCH2INTF_CH			(0x1u<<1)
#define	USBFS_HOST_HCH2INTF_TF			(0x1u<<0)

// HCH2INTEN Configuration

#define	USBFS_HOST_HCH2INTEN_DTERIE		(0x1u<<10)
#define	USBFS_HOST_HCH2INTEN_REQOVRIE	(0x1u<<9)
#define	USBFS_HOST_HCH2INTEN_BBERIE		(0x1u<<8)
#define	USBFS_HOST_HCH2INTEN_USBERIE	(0x1u<<7)
#define	USBFS_HOST_HCH2INTEN_ACKIE		(0x1u<<5)
#define	USBFS_HOST_HCH2INTEN_NAKIE		(0x1u<<4)
#define	USBFS_HOST_HCH2INTEN_STALLIE	(0x1u<<3)
#define	USBFS_HOST_HCH2INTEN_CHIE		(0x1u<<1)
#define	USBFS_HOST_HCH2INTEN_TFIE		(0x1u<<0)

// HCH2LEN Configuration

#define	USBFS_HOST_HCH2LEN_DPID			(0x3u<<29)
#define	USBFS_HOST_HCH2LEN_DPID_0		(0x1u<<29)
#define	USBFS_HOST_HCH2LEN_PCNT			(0x3FFu<<19)
#define	USBFS_HOST_HCH2LEN_PCNT_0		(0x1u<<19)
#define	USBFS_HOST_HCH2LEN_TLEN			(0x7FFFFu<<0)
#define	USBFS_HOST_HCH2LEN_TLEN_0		(0x1u<<0)

// HCH3CTL Configuration

#define	USBFS_HOST_HCH3CTL_CEN			(0x1u<<31)
#define	USBFS_HOST_HCH3CTL_CDIS			(0x1u<<30)
#define	USBFS_HOST_HCH3CTL_ODDFRM		(0x1u<<29)
#define	USBFS_HOST_HCH3CTL_DAR			(0x7Fu<<22)
#define	USBFS_HOST_HCH3CTL_DAR_0		(0x1u<<22)
#define	USBFS_HOST_HCH3CTL_EPTYPE		(0x3u<<18)
#define	USBFS_HOST_HCH3CTL_EPTYPE_0		(0x1u<<18)
#define	USBFS_HOST_HCH3CTL_LSD			(0x1u<<17)
#define	USBFS_HOST_HCH3CTL_EPDIR		(0x1u<<15)
#define	USBFS_HOST_HCH3CTL_EPNUM		(0xFu<<11)
#define	USBFS_HOST_HCH3CTL_EPNUM_0		(0x1u<<11)
#define	USBFS_HOST_HCH3CTL_MPL			(0x7FFu<<0)
#define	USBFS_HOST_HCH3CTL_MPL_0		(0x1u<<0)

// HCH3INTF Configuration

#define	USBFS_HOST_HCH3INTF_DTER		(0x1u<<10)
#define	USBFS_HOST_HCH3INTF_REQOVR		(0x1u<<9)
#define	USBFS_HOST_HCH3INTF_BBER		(0x1u<<8)
#define	USBFS_HOST_HCH3INTF_USBER		(0x1u<<7)
#define	USBFS_HOST_HCH3INTF_ACK			(0x1u<<5)
#define	USBFS_HOST_HCH3INTF_NAK			(0x1u<<4)
#define	USBFS_HOST_HCH3INTF_STALL		(0x1u<<3)
#define	USBFS_HOST_HCH3INTF_CH			(0x1u<<1)
#define	USBFS_HOST_HCH3INTF_TF			(0x1u<<0)

// HCH3INTEN Configuration

#define	USBFS_HOST_HCH3INTEN_DTERIE		(0x1u<<10)
#define	USBFS_HOST_HCH3INTEN_REQOVRIE	(0x1u<<9)
#define	USBFS_HOST_HCH3INTEN_BBERIE		(0x1u<<8)
#define	USBFS_HOST_HCH3INTEN_USBERIE	(0x1u<<7)
#define	USBFS_HOST_HCH3INTEN_ACKIE		(0x1u<<5)
#define	USBFS_HOST_HCH3INTEN_NAKIE		(0x1u<<4)
#define	USBFS_HOST_HCH3INTEN_STALLIE	(0x1u<<3)
#define	USBFS_HOST_HCH3INTEN_CHIE		(0x1u<<1)
#define	USBFS_HOST_HCH3INTEN_TFIE		(0x1u<<0)

// HCH3LEN Configuration

#define	USBFS_HOST_HCH3LEN_DPID			(0x3u<<29)
#define	USBFS_HOST_HCH3LEN_DPID_0		(0x1u<<29)
#define	USBFS_HOST_HCH3LEN_PCNT			(0x3FFu<<19)
#define	USBFS_HOST_HCH3LEN_PCNT_0		(0x1u<<19)
#define	USBFS_HOST_HCH3LEN_TLEN			(0x7FFFFu<<0)
#define	USBFS_HOST_HCH3LEN_TLEN_0		(0x1u<<0)

// HCH4CTL Configuration

#define	USBFS_HOST_HCH4CTL_CEN			(0x1u<<31)
#define	USBFS_HOST_HCH4CTL_CDIS			(0x1u<<30)
#define	USBFS_HOST_HCH4CTL_ODDFRM		(0x1u<<29)
#define	USBFS_HOST_HCH4CTL_DAR			(0x7Fu<<22)
#define	USBFS_HOST_HCH4CTL_DAR_0		(0x1u<<22)
#define	USBFS_HOST_HCH4CTL_EPTYPE		(0x3u<<18)
#define	USBFS_HOST_HCH4CTL_EPTYPE_0		(0x1u<<18)
#define	USBFS_HOST_HCH4CTL_LSD			(0x1u<<17)
#define	USBFS_HOST_HCH4CTL_EPDIR		(0x1u<<15)
#define	USBFS_HOST_HCH4CTL_EPNUM		(0xFu<<11)
#define	USBFS_HOST_HCH4CTL_EPNUM_0		(0x1u<<11)
#define	USBFS_HOST_HCH4CTL_MPL			(0x7FFu<<0)
#define	USBFS_HOST_HCH4CTL_MPL_0		(0x1u<<0)

// HCH4INTF Configuration

#define	USBFS_HOST_HCH4INTF_DTER		(0x1u<<10)
#define	USBFS_HOST_HCH4INTF_REQOVR		(0x1u<<9)
#define	USBFS_HOST_HCH4INTF_BBER		(0x1u<<8)
#define	USBFS_HOST_HCH4INTF_USBER		(0x1u<<7)
#define	USBFS_HOST_HCH4INTF_ACK			(0x1u<<5)
#define	USBFS_HOST_HCH4INTF_NAK			(0x1u<<4)
#define	USBFS_HOST_HCH4INTF_STALL		(0x1u<<3)
#define	USBFS_HOST_HCH4INTF_CH			(0x1u<<1)
#define	USBFS_HOST_HCH4INTF_TF			(0x1u<<0)

// HCH4INTEN Configuration

#define	USBFS_HOST_HCH4INTEN_DTERIE		(0x1u<<10)
#define	USBFS_HOST_HCH4INTEN_REQOVRIE	(0x1u<<9)
#define	USBFS_HOST_HCH4INTEN_BBERIE		(0x1u<<8)
#define	USBFS_HOST_HCH4INTEN_USBERIE	(0x1u<<7)
#define	USBFS_HOST_HCH4INTEN_ACKIE		(0x1u<<5)
#define	USBFS_HOST_HCH4INTEN_NAKIE		(0x1u<<4)
#define	USBFS_HOST_HCH4INTEN_STALLIE	(0x1u<<3)
#define	USBFS_HOST_HCH4INTEN_CHIE		(0x1u<<1)
#define	USBFS_HOST_HCH4INTEN_TFIE		(0x1u<<0)

// HCH4LEN Configuration

#define	USBFS_HOST_HCH4LEN_DPID			(0x3u<<29)
#define	USBFS_HOST_HCH4LEN_DPID_0		(0x1u<<29)
#define	USBFS_HOST_HCH4LEN_PCNT			(0x3FFu<<19)
#define	USBFS_HOST_HCH4LEN_PCNT_0		(0x1u<<19)
#define	USBFS_HOST_HCH4LEN_TLEN			(0x7FFFFu<<0)
#define	USBFS_HOST_HCH4LEN_TLEN_0		(0x1u<<0)

// HCH5CTL Configuration

#define	USBFS_HOST_HCH5CTL_CEN			(0x1u<<31)
#define	USBFS_HOST_HCH5CTL_CDIS			(0x1u<<30)
#define	USBFS_HOST_HCH5CTL_ODDFRM		(0x1u<<29)
#define	USBFS_HOST_HCH5CTL_DAR			(0x7Fu<<22)
#define	USBFS_HOST_HCH5CTL_DAR_0		(0x1u<<22)
#define	USBFS_HOST_HCH5CTL_EPTYPE		(0x3u<<18)
#define	USBFS_HOST_HCH5CTL_EPTYPE_0		(0x1u<<18)
#define	USBFS_HOST_HCH5CTL_LSD			(0x1u<<17)
#define	USBFS_HOST_HCH5CTL_EPDIR		(0x1u<<15)
#define	USBFS_HOST_HCH5CTL_EPNUM		(0xFu<<11)
#define	USBFS_HOST_HCH5CTL_EPNUM_0		(0x1u<<11)
#define	USBFS_HOST_HCH5CTL_MPL			(0x7FFu<<0)
#define	USBFS_HOST_HCH5CTL_MPL_0		(0x1u<<0)

// HCH5INTF Configuration

#define	USBFS_HOST_HCH5INTF_DTER		(0x1u<<10)
#define	USBFS_HOST_HCH5INTF_REQOVR		(0x1u<<9)
#define	USBFS_HOST_HCH5INTF_BBER		(0x1u<<8)
#define	USBFS_HOST_HCH5INTF_USBER		(0x1u<<7)
#define	USBFS_HOST_HCH5INTF_ACK			(0x1u<<5)
#define	USBFS_HOST_HCH5INTF_NAK			(0x1u<<4)
#define	USBFS_HOST_HCH5INTF_STALL		(0x1u<<3)
#define	USBFS_HOST_HCH5INTF_CH			(0x1u<<1)
#define	USBFS_HOST_HCH5INTF_TF			(0x1u<<0)

// HCH5INTEN Configuration

#define	USBFS_HOST_HCH5INTEN_DTERIE		(0x1u<<10)
#define	USBFS_HOST_HCH5INTEN_REQOVRIE	(0x1u<<9)
#define	USBFS_HOST_HCH5INTEN_BBERIE		(0x1u<<8)
#define	USBFS_HOST_HCH5INTEN_USBERIE	(0x1u<<7)
#define	USBFS_HOST_HCH5INTEN_ACKIE		(0x1u<<5)
#define	USBFS_HOST_HCH5INTEN_NAKIE		(0x1u<<4)
#define	USBFS_HOST_HCH5INTEN_STALLIE	(0x1u<<3)
#define	USBFS_HOST_HCH5INTEN_CHIE		(0x1u<<1)
#define	USBFS_HOST_HCH5INTEN_TFIE		(0x1u<<0)

// HCH5LEN Configuration

#define	USBFS_HOST_HCH5LEN_DPID			(0x3u<<29)
#define	USBFS_HOST_HCH5LEN_DPID_0		(0x1u<<29)
#define	USBFS_HOST_HCH5LEN_PCNT			(0x3FFu<<19)
#define	USBFS_HOST_HCH5LEN_PCNT_0		(0x1u<<19)
#define	USBFS_HOST_HCH5LEN_TLEN			(0x7FFFFu<<0)
#define	USBFS_HOST_HCH5LEN_TLEN_0		(0x1u<<0)

// HCH6CTL Configuration

#define	USBFS_HOST_HCH6CTL_CEN			(0x1u<<31)
#define	USBFS_HOST_HCH6CTL_CDIS			(0x1u<<30)
#define	USBFS_HOST_HCH6CTL_ODDFRM		(0x1u<<29)
#define	USBFS_HOST_HCH6CTL_DAR			(0x7Fu<<22)
#define	USBFS_HOST_HCH6CTL_DAR_0		(0x1u<<22)
#define	USBFS_HOST_HCH6CTL_EPTYPE		(0x3u<<18)
#define	USBFS_HOST_HCH6CTL_EPTYPE_0		(0x1u<<18)
#define	USBFS_HOST_HCH6CTL_LSD			(0x1u<<17)
#define	USBFS_HOST_HCH6CTL_EPDIR		(0x1u<<15)
#define	USBFS_HOST_HCH6CTL_EPNUM		(0xFu<<11)
#define	USBFS_HOST_HCH6CTL_EPNUM_0		(0x1u<<11)
#define	USBFS_HOST_HCH6CTL_MPL			(0x7FFu<<0)
#define	USBFS_HOST_HCH6CTL_MPL_0		(0x1u<<0)

// HCH6INTF Configuration

#define	USBFS_HOST_HCH6INTF_DTER		(0x1u<<10)
#define	USBFS_HOST_HCH6INTF_REQOVR		(0x1u<<9)
#define	USBFS_HOST_HCH6INTF_BBER		(0x1u<<8)
#define	USBFS_HOST_HCH6INTF_USBER		(0x1u<<7)
#define	USBFS_HOST_HCH6INTF_ACK			(0x1u<<5)
#define	USBFS_HOST_HCH6INTF_NAK			(0x1u<<4)
#define	USBFS_HOST_HCH6INTF_STALL		(0x1u<<3)
#define	USBFS_HOST_HCH6INTF_CH			(0x1u<<1)
#define	USBFS_HOST_HCH6INTF_TF			(0x1u<<0)

// HCH6INTEN Configuration

#define	USBFS_HOST_HCH6INTEN_DTERIE		(0x1u<<10)
#define	USBFS_HOST_HCH6INTEN_REQOVRIE	(0x1u<<9)
#define	USBFS_HOST_HCH6INTEN_BBERIE		(0x1u<<8)
#define	USBFS_HOST_HCH6INTEN_USBERIE	(0x1u<<7)
#define	USBFS_HOST_HCH6INTEN_ACKIE		(0x1u<<5)
#define	USBFS_HOST_HCH6INTEN_NAKIE		(0x1u<<4)
#define	USBFS_HOST_HCH6INTEN_STALLIE	(0x1u<<3)
#define	USBFS_HOST_HCH6INTEN_CHIE		(0x1u<<1)
#define	USBFS_HOST_HCH6INTEN_TFIE		(0x1u<<0)

// HCH6LEN Configuration

#define	USBFS_HOST_HCH6LEN_DPID			(0x3u<<29)
#define	USBFS_HOST_HCH6LEN_DPID_0		(0x1u<<29)
#define	USBFS_HOST_HCH6LEN_PCNT			(0x3FFu<<19)
#define	USBFS_HOST_HCH6LEN_PCNT_0		(0x1u<<19)
#define	USBFS_HOST_HCH6LEN_TLEN			(0x7FFFFu<<0)
#define	USBFS_HOST_HCH6LEN_TLEN_0		(0x1u<<0)

// HCH7CTL Configuration

#define	USBFS_HOST_HCH7CTL_CEN			(0x1u<<31)
#define	USBFS_HOST_HCH7CTL_CDIS			(0x1u<<30)
#define	USBFS_HOST_HCH7CTL_ODDFRM		(0x1u<<29)
#define	USBFS_HOST_HCH7CTL_DAR			(0x7Fu<<22)
#define	USBFS_HOST_HCH7CTL_DAR_0		(0x1u<<22)
#define	USBFS_HOST_HCH7CTL_EPTYPE		(0x3u<<18)
#define	USBFS_HOST_HCH7CTL_EPTYPE_0		(0x1u<<18)
#define	USBFS_HOST_HCH7CTL_LSD			(0x1u<<17)
#define	USBFS_HOST_HCH7CTL_EPDIR		(0x1u<<15)
#define	USBFS_HOST_HCH7CTL_EPNUM		(0xFu<<11)
#define	USBFS_HOST_HCH7CTL_EPNUM_0		(0x1u<<11)
#define	USBFS_HOST_HCH7CTL_MPL			(0x7FFu<<0)
#define	USBFS_HOST_HCH7CTL_MPL_0		(0x1u<<0)

// HCH7INTF Configuration

#define	USBFS_HOST_HCH7INTF_DTER		(0x1u<<10)
#define	USBFS_HOST_HCH7INTF_REQOVR		(0x1u<<9)
#define	USBFS_HOST_HCH7INTF_BBER		(0x1u<<8)
#define	USBFS_HOST_HCH7INTF_USBER		(0x1u<<7)
#define	USBFS_HOST_HCH7INTF_ACK			(0x1u<<5)
#define	USBFS_HOST_HCH7INTF_NAK			(0x1u<<4)
#define	USBFS_HOST_HCH7INTF_STALL		(0x1u<<3)
#define	USBFS_HOST_HCH7INTF_CH			(0x1u<<1)
#define	USBFS_HOST_HCH7INTF_TF			(0x1u<<0)

// HCH7INTEN Configuration

#define	USBFS_HOST_HCH7INTEN_DTERIE		(0x1u<<10)
#define	USBFS_HOST_HCH7INTEN_REQOVRIE	(0x1u<<9)
#define	USBFS_HOST_HCH7INTEN_BBERIE		(0x1u<<8)
#define	USBFS_HOST_HCH7INTEN_USBERIE	(0x1u<<7)
#define	USBFS_HOST_HCH7INTEN_ACKIE		(0x1u<<5)
#define	USBFS_HOST_HCH7INTEN_NAKIE		(0x1u<<4)
#define	USBFS_HOST_HCH7INTEN_STALLIE	(0x1u<<3)
#define	USBFS_HOST_HCH7INTEN_CHIE		(0x1u<<1)
#define	USBFS_HOST_HCH7INTEN_TFIE		(0x1u<<0)

// HCH7LEN Configuration

#define	USBFS_HOST_HCH7LEN_DPID			(0x3u<<29)
#define	USBFS_HOST_HCH7LEN_DPID_0		(0x1u<<29)
#define	USBFS_HOST_HCH7LEN_PCNT			(0x3FFu<<19)
#define	USBFS_HOST_HCH7LEN_PCNT_0		(0x1u<<19)
#define	USBFS_HOST_HCH7LEN_TLEN			(0x7FFFFu<<0)
#define	USBFS_HOST_HCH7LEN_TLEN_0		(0x1u<<0)
