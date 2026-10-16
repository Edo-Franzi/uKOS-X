/*
; GD32VF103_usbfs_device.
; =======================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_usbfs_device equates.
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

// USBFS_DEVICE address definitions
// --------------------------------

typedef struct {
	volatile	uint32_t	DCFG;
	volatile	uint32_t	DCTL;
	volatile	uint32_t	DSTAT;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	DIEPINTEN;
	volatile	uint32_t	DOEPINTEN;
	volatile	uint32_t	DAEPINT;
	volatile	uint32_t	DAEPINTEN;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	DVBUSDT;
	volatile	uint32_t	DVBUSPT;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	DIEPFEINTEN;
	volatile	uint32_t	RESERVED3[50];
	volatile	uint32_t	DIEP0CTL;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	DIEP0INTF;
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	DIEP0LEN;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	DIEP0TFSTAT;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	DIEP1CTL;
	volatile	uint32_t	RESERVED8;
	volatile	uint32_t	DIEP1INTF;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	DIEP1LEN;
	volatile	uint32_t	RESERVED10;
	volatile	uint32_t	DIEP1TFSTAT;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	DIEP2CTL;
	volatile	uint32_t	RESERVED12;
	volatile	uint32_t	DIEP2INTF;
	volatile	uint32_t	RESERVED13;
	volatile	uint32_t	DIEP2LEN;
	volatile	uint32_t	RESERVED14;
	volatile	uint32_t	DIEP2TFSTAT;
	volatile	uint32_t	RESERVED15;
	volatile	uint32_t	DIEP3CTL;
	volatile	uint32_t	RESERVED16;
	volatile	uint32_t	DIEP3INTF;
	volatile	uint32_t	RESERVED17;
	volatile	uint32_t	DIEP3LEN;
	volatile	uint32_t	RESERVED18;
	volatile	uint32_t	DIEP3TFSTAT;
	volatile	uint32_t	RESERVED19[97];
	volatile	uint32_t	DOEP0CTL;
	volatile	uint32_t	RESERVED20;
	volatile	uint32_t	DOEP0INTF;
	volatile	uint32_t	RESERVED21;
	volatile	uint32_t	DOEP0LEN;
	volatile	uint32_t	RESERVED22[3];
	volatile	uint32_t	DOEP1CTL;
	volatile	uint32_t	RESERVED23;
	volatile	uint32_t	DOEP1INTF;
	volatile	uint32_t	RESERVED24;
	volatile	uint32_t	DOEP1LEN;
	volatile	uint32_t	RESERVED25[3];
	volatile	uint32_t	DOEP2CTL;
	volatile	uint32_t	RESERVED26;
	volatile	uint32_t	DOEP2INTF;
	volatile	uint32_t	RESERVED27;
	volatile	uint32_t	DOEP2LEN;
	volatile	uint32_t	RESERVED28[3];
	volatile	uint32_t	DOEP3CTL;
	volatile	uint32_t	RESERVED29;
	volatile	uint32_t	DOEP3INTF;
	volatile	uint32_t	RESERVED30;
	volatile	uint32_t	DOEP3LEN;
} USBFS_DEVICE_TypeDef;

#if (defined(__cplusplus))
#define	USBFS_DEVICE	reinterpret_cast<USBFS_DEVICE_TypeDef *>(0x50000800u)

#else
#define	USBFS_DEVICE	((USBFS_DEVICE_TypeDef *)0x50000800u)
#endif

// DCFG Configuration

#define	USBFS_DEVICE_DCFG_EOPFT					(0x3u<<11)
#define	USBFS_DEVICE_DCFG_EOPFT_0				(0x1u<<11)
#define	USBFS_DEVICE_DCFG_DAR					(0x7Fu<<4)
#define	USBFS_DEVICE_DCFG_DAR_0					(0x1u<<4)
#define	USBFS_DEVICE_DCFG_NZLSOH				(0x1u<<2)
#define	USBFS_DEVICE_DCFG_DS					(0x3u<<0)
#define	USBFS_DEVICE_DCFG_DS_0					(0x1u<<0)

// DCTL Configuration

#define	USBFS_DEVICE_DCTL_POIF					(0x1u<<11)
#define	USBFS_DEVICE_DCTL_CGONAK				(0x1u<<10)
#define	USBFS_DEVICE_DCTL_SGONAK				(0x1u<<9)
#define	USBFS_DEVICE_DCTL_CGINAK				(0x1u<<8)
#define	USBFS_DEVICE_DCTL_SGINAK				(0x1u<<7)
#define	USBFS_DEVICE_DCTL_GONS					(0x1u<<3)
#define	USBFS_DEVICE_DCTL_GINS					(0x1u<<2)
#define	USBFS_DEVICE_DCTL_SD					(0x1u<<1)
#define	USBFS_DEVICE_DCTL_RWKUP					(0x1u<<0)

// DSTAT Configuration

#define	USBFS_DEVICE_DSTAT_FNRSOF				(0x3FFFu<<8)
#define	USBFS_DEVICE_DSTAT_FNRSOF_0				(0x1u<<8)
#define	USBFS_DEVICE_DSTAT_ES					(0x3u<<1)
#define	USBFS_DEVICE_DSTAT_ES_0					(0x1u<<1)
#define	USBFS_DEVICE_DSTAT_SPST					(0x1u<<0)

// DIEPINTEN Configuration

#define	USBFS_DEVICE_DIEPINTEN_IEPNEEN			(0x1u<<6)
#define	USBFS_DEVICE_DIEPINTEN_EPTXFUDEN		(0x1u<<4)
#define	USBFS_DEVICE_DIEPINTEN_CITOEN			(0x1u<<3)
#define	USBFS_DEVICE_DIEPINTEN_EPDISEN			(0x1u<<1)
#define	USBFS_DEVICE_DIEPINTEN_TFEN				(0x1u<<0)

// DOEPINTEN Configuration

#define	USBFS_DEVICE_DOEPINTEN_BTBSTPEN			(0x1u<<6)
#define	USBFS_DEVICE_DOEPINTEN_EPRXFOVREN		(0x1u<<4)
#define	USBFS_DEVICE_DOEPINTEN_STPFEN			(0x1u<<3)
#define	USBFS_DEVICE_DOEPINTEN_EPDISEN			(0x1u<<1)
#define	USBFS_DEVICE_DOEPINTEN_TFEN				(0x1u<<0)

// DAEPINT Configuration

#define	USBFS_DEVICE_DAEPINT_OEPITB				(0xFu<<16)
#define	USBFS_DEVICE_DAEPINT_OEPITB_0			(0x1u<<16)
#define	USBFS_DEVICE_DAEPINT_IEPITB				(0xFu<<0)
#define	USBFS_DEVICE_DAEPINT_IEPITB_0			(0x1u<<0)

// DAEPINTEN Configuration

#define	USBFS_DEVICE_DAEPINTEN_OEPIE			(0xFu<<16)
#define	USBFS_DEVICE_DAEPINTEN_OEPIE_0			(0x1u<<16)
#define	USBFS_DEVICE_DAEPINTEN_IEPIE			(0xFu<<0)
#define	USBFS_DEVICE_DAEPINTEN_IEPIE_0			(0x1u<<0)

// DVBUSDT Configuration

#define	USBFS_DEVICE_DVBUSDT_DVBUSDT			(0xFFFFu<<0)
#define	USBFS_DEVICE_DVBUSDT_DVBUSDT_0			(0x1u<<0)

// DVBUSPT Configuration

#define	USBFS_DEVICE_DVBUSPT_DVBUSPT			(0xFFFu<<0)
#define	USBFS_DEVICE_DVBUSPT_DVBUSPT_0			(0x1u<<0)

// DIEPFEINTEN Configuration

#define	USBFS_DEVICE_DIEPFEINTEN_IEPTXFEIE		(0xFu<<0)
#define	USBFS_DEVICE_DIEPFEINTEN_IEPTXFEIE_0	(0x1u<<0)

// DIEP0CTL Configuration

#define	USBFS_DEVICE_DIEP0CTL_EPEN				(0x1u<<31)
#define	USBFS_DEVICE_DIEP0CTL_EPD				(0x1u<<30)
#define	USBFS_DEVICE_DIEP0CTL_SNAK				(0x1u<<27)
#define	USBFS_DEVICE_DIEP0CTL_CNAK				(0x1u<<26)
#define	USBFS_DEVICE_DIEP0CTL_TXFNUM			(0xFu<<22)
#define	USBFS_DEVICE_DIEP0CTL_TXFNUM_0			(0x1u<<22)
#define	USBFS_DEVICE_DIEP0CTL_STALL				(0x1u<<21)
#define	USBFS_DEVICE_DIEP0CTL_EPTYPE			(0x3u<<18)
#define	USBFS_DEVICE_DIEP0CTL_EPTYPE_0			(0x1u<<18)
#define	USBFS_DEVICE_DIEP0CTL_NAKS				(0x1u<<17)
#define	USBFS_DEVICE_DIEP0CTL_EPACT				(0x1u<<15)
#define	USBFS_DEVICE_DIEP0CTL_MPL				(0x3u<<0)
#define	USBFS_DEVICE_DIEP0CTL_MPL_0				(0x1u<<0)

// DIEP0INTF Configuration

#define	USBFS_DEVICE_DIEP0INTF_TF				(0x1u<<0)
#define	USBFS_DEVICE_DIEP0INTF_EPDIS			(0x1u<<1)
#define	USBFS_DEVICE_DIEP0INTF_CITO				(0x1u<<3)
#define	USBFS_DEVICE_DIEP0INTF_EPTXFUD			(0x1u<<4)
#define	USBFS_DEVICE_DIEP0INTF_IEPNE			(0x1u<<6)
#define	USBFS_DEVICE_DIEP0INTF_TXFE				(0x1u<<7)

// DIEP0LEN Configuration

#define	USBFS_DEVICE_DIEP0LEN_TLEN				(0x7Fu<<0)
#define	USBFS_DEVICE_DIEP0LEN_TLEN_0			(0x1u<<0)
#define	USBFS_DEVICE_DIEP0LEN_PCNT				(0x3u<<19)
#define	USBFS_DEVICE_DIEP0LEN_PCNT_0			(0x1u<<19)

// DIEP0TFSTAT Configuration

#define	USBFS_DEVICE_DIEP0TFSTAT_IEPTFS			(0xFFFFu<<0)
#define	USBFS_DEVICE_DIEP0TFSTAT_IEPTFS_0		(0x1u<<0)

// DIEP1CTL Configuration

#define	USBFS_DEVICE_DIEP1CTL_MPL				(0x7FFu<<0)
#define	USBFS_DEVICE_DIEP1CTL_MPL_0				(0x1u<<0)
#define	USBFS_DEVICE_DIEP1CTL_EPACT				(0x1u<<15)
#define	USBFS_DEVICE_DIEP1CTL_EOFRM_DPID		(0x1u<<16)
#define	USBFS_DEVICE_DIEP1CTL_NAKS				(0x1u<<17)
#define	USBFS_DEVICE_DIEP1CTL_EPTYPE			(0x3u<<18)
#define	USBFS_DEVICE_DIEP1CTL_EPTYPE_0			(0x1u<<18)
#define	USBFS_DEVICE_DIEP1CTL_STALL				(0x1u<<21)
#define	USBFS_DEVICE_DIEP1CTL_TXFNUM			(0xFu<<22)
#define	USBFS_DEVICE_DIEP1CTL_TXFNUM_0			(0x1u<<22)
#define	USBFS_DEVICE_DIEP1CTL_CNAK				(0x1u<<26)
#define	USBFS_DEVICE_DIEP1CTL_SNAK				(0x1u<<27)
#define	USBFS_DEVICE_DIEP1CTL_SD0PID_SEVENFRM	(0x1u<<28)
#define	USBFS_DEVICE_DIEP1CTL_SD1PID_SODDFRM	(0x1u<<29)
#define	USBFS_DEVICE_DIEP1CTL_EPD				(0x1u<<30)
#define	USBFS_DEVICE_DIEP1CTL_EPEN				(0x1u<<31)

// DIEP1INTF Configuration

#define	USBFS_DEVICE_DIEP1INTF_TF				(0x1u<<0)
#define	USBFS_DEVICE_DIEP1INTF_EPDIS			(0x1u<<1)
#define	USBFS_DEVICE_DIEP1INTF_CITO				(0x1u<<3)
#define	USBFS_DEVICE_DIEP1INTF_EPTXFUD			(0x1u<<4)
#define	USBFS_DEVICE_DIEP1INTF_IEPNE			(0x1u<<6)
#define	USBFS_DEVICE_DIEP1INTF_TXFE				(0x1u<<7)

// DIEP1LEN Configuration

#define	USBFS_DEVICE_DIEP1LEN_TLEN				(0x7FFFFu<<0)
#define	USBFS_DEVICE_DIEP1LEN_TLEN_0			(0x1u<<0)
#define	USBFS_DEVICE_DIEP1LEN_PCNT				(0x3FFu<<19)
#define	USBFS_DEVICE_DIEP1LEN_PCNT_0			(0x1u<<19)
#define	USBFS_DEVICE_DIEP1LEN_MCPF				(0x3u<<29)
#define	USBFS_DEVICE_DIEP1LEN_MCPF_0			(0x1u<<29)

// DIEP1TFSTAT Configuration

#define	USBFS_DEVICE_DIEP1TFSTAT_IEPTFS			(0xFFFFu<<0)
#define	USBFS_DEVICE_DIEP1TFSTAT_IEPTFS_0		(0x1u<<0)

// DIEP2CTL Configuration

#define	USBFS_DEVICE_DIEP2CTL_MPL				(0x7FFu<<0)
#define	USBFS_DEVICE_DIEP2CTL_MPL_0				(0x1u<<0)
#define	USBFS_DEVICE_DIEP2CTL_EPACT				(0x1u<<15)
#define	USBFS_DEVICE_DIEP2CTL_EOFRM_DPID		(0x1u<<16)
#define	USBFS_DEVICE_DIEP2CTL_NAKS				(0x1u<<17)
#define	USBFS_DEVICE_DIEP2CTL_EPTYPE			(0x3u<<18)
#define	USBFS_DEVICE_DIEP2CTL_EPTYPE_0			(0x1u<<18)
#define	USBFS_DEVICE_DIEP2CTL_STALL				(0x1u<<21)
#define	USBFS_DEVICE_DIEP2CTL_TXFNUM			(0xFu<<22)
#define	USBFS_DEVICE_DIEP2CTL_TXFNUM_0			(0x1u<<22)
#define	USBFS_DEVICE_DIEP2CTL_CNAK				(0x1u<<26)
#define	USBFS_DEVICE_DIEP2CTL_SNAK				(0x1u<<27)
#define	USBFS_DEVICE_DIEP2CTL_SD0PID_SEVENFRM	(0x1u<<28)
#define	USBFS_DEVICE_DIEP2CTL_SD1PID_SODDFRM	(0x1u<<29)
#define	USBFS_DEVICE_DIEP2CTL_EPD				(0x1u<<30)
#define	USBFS_DEVICE_DIEP2CTL_EPEN				(0x1u<<31)

// DIEP2INTF Configuration

#define	USBFS_DEVICE_DIEP2INTF_TF				(0x1u<<0)
#define	USBFS_DEVICE_DIEP2INTF_EPDIS			(0x1u<<1)
#define	USBFS_DEVICE_DIEP2INTF_CITO				(0x1u<<3)
#define	USBFS_DEVICE_DIEP2INTF_EPTXFUD			(0x1u<<4)
#define	USBFS_DEVICE_DIEP2INTF_IEPNE			(0x1u<<6)
#define	USBFS_DEVICE_DIEP2INTF_TXFE				(0x1u<<7)

// DIEP2LEN Configuration

#define	USBFS_DEVICE_DIEP2LEN_TLEN				(0x7FFFFu<<0)
#define	USBFS_DEVICE_DIEP2LEN_TLEN_0			(0x1u<<0)
#define	USBFS_DEVICE_DIEP2LEN_PCNT				(0x3FFu<<19)
#define	USBFS_DEVICE_DIEP2LEN_PCNT_0			(0x1u<<19)
#define	USBFS_DEVICE_DIEP2LEN_MCPF				(0x3u<<29)
#define	USBFS_DEVICE_DIEP2LEN_MCPF_0			(0x1u<<29)

// DIEP2TFSTAT Configuration

#define	USBFS_DEVICE_DIEP2TFSTAT_IEPTFS			(0xFFFFu<<0)
#define	USBFS_DEVICE_DIEP2TFSTAT_IEPTFS_0		(0x1u<<0)

// DIEP3CTL Configuration

#define	USBFS_DEVICE_DIEP3CTL_MPL				(0x7FFu<<0)
#define	USBFS_DEVICE_DIEP3CTL_MPL_0				(0x1u<<0)
#define	USBFS_DEVICE_DIEP3CTL_EPACT				(0x1u<<15)
#define	USBFS_DEVICE_DIEP3CTL_EOFRM_DPID		(0x1u<<16)
#define	USBFS_DEVICE_DIEP3CTL_NAKS				(0x1u<<17)
#define	USBFS_DEVICE_DIEP3CTL_EPTYPE			(0x3u<<18)
#define	USBFS_DEVICE_DIEP3CTL_EPTYPE_0			(0x1u<<18)
#define	USBFS_DEVICE_DIEP3CTL_STALL				(0x1u<<21)
#define	USBFS_DEVICE_DIEP3CTL_TXFNUM			(0xFu<<22)
#define	USBFS_DEVICE_DIEP3CTL_TXFNUM_0			(0x1u<<22)
#define	USBFS_DEVICE_DIEP3CTL_CNAK				(0x1u<<26)
#define	USBFS_DEVICE_DIEP3CTL_SNAK				(0x1u<<27)
#define	USBFS_DEVICE_DIEP3CTL_SD0PID_SEVENFRM	(0x1u<<28)
#define	USBFS_DEVICE_DIEP3CTL_SD1PID_SODDFRM	(0x1u<<29)
#define	USBFS_DEVICE_DIEP3CTL_EPD				(0x1u<<30)
#define	USBFS_DEVICE_DIEP3CTL_EPEN				(0x1u<<31)

// DIEP3INTF Configuration

#define	USBFS_DEVICE_DIEP3INTF_TF				(0x1u<<0)
#define	USBFS_DEVICE_DIEP3INTF_EPDIS			(0x1u<<1)
#define	USBFS_DEVICE_DIEP3INTF_CITO				(0x1u<<3)
#define	USBFS_DEVICE_DIEP3INTF_EPTXFUD			(0x1u<<4)
#define	USBFS_DEVICE_DIEP3INTF_IEPNE			(0x1u<<6)
#define	USBFS_DEVICE_DIEP3INTF_TXFE				(0x1u<<7)

// DIEP3LEN Configuration

#define	USBFS_DEVICE_DIEP3LEN_TLEN				(0x7FFFFu<<0)
#define	USBFS_DEVICE_DIEP3LEN_TLEN_0			(0x1u<<0)
#define	USBFS_DEVICE_DIEP3LEN_PCNT				(0x3FFu<<19)
#define	USBFS_DEVICE_DIEP3LEN_PCNT_0			(0x1u<<19)
#define	USBFS_DEVICE_DIEP3LEN_MCPF				(0x3u<<29)
#define	USBFS_DEVICE_DIEP3LEN_MCPF_0			(0x1u<<29)

// DIEP3TFSTAT Configuration

#define	USBFS_DEVICE_DIEP3TFSTAT_IEPTFS			(0xFFFFu<<0)
#define	USBFS_DEVICE_DIEP3TFSTAT_IEPTFS_0		(0x1u<<0)

// DOEP0CTL Configuration

#define	USBFS_DEVICE_DOEP0CTL_MPL				(0x3u<<0)
#define	USBFS_DEVICE_DOEP0CTL_MPL_0				(0x1u<<0)
#define	USBFS_DEVICE_DOEP0CTL_EPACT				(0x1u<<15)
#define	USBFS_DEVICE_DOEP0CTL_NAKS				(0x1u<<17)
#define	USBFS_DEVICE_DOEP0CTL_EPTYPE			(0x3u<<18)
#define	USBFS_DEVICE_DOEP0CTL_EPTYPE_0			(0x1u<<18)
#define	USBFS_DEVICE_DOEP0CTL_SNOOP				(0x1u<<20)
#define	USBFS_DEVICE_DOEP0CTL_STALL				(0x1u<<21)
#define	USBFS_DEVICE_DOEP0CTL_CNAK				(0x1u<<26)
#define	USBFS_DEVICE_DOEP0CTL_SNAK				(0x1u<<27)
#define	USBFS_DEVICE_DOEP0CTL_EPD				(0x1u<<30)
#define	USBFS_DEVICE_DOEP0CTL_EPEN				(0x1u<<31)

// DOEP0INTF Configuration

#define	USBFS_DEVICE_DOEP0INTF_TF				(0x1u<<0)
#define	USBFS_DEVICE_DOEP0INTF_EPDIS			(0x1u<<1)
#define	USBFS_DEVICE_DOEP0INTF_STPF				(0x1u<<3)
#define	USBFS_DEVICE_DOEP0INTF_EPRXFOVR			(0x1u<<4)
#define	USBFS_DEVICE_DOEP0INTF_BTBSTP			(0x1u<<6)

// DOEP0LEN Configuration

#define	USBFS_DEVICE_DOEP0LEN_TLEN				(0x7Fu<<0)
#define	USBFS_DEVICE_DOEP0LEN_TLEN_0			(0x1u<<0)
#define	USBFS_DEVICE_DOEP0LEN_PCNT				(0x1u<<19)
#define	USBFS_DEVICE_DOEP0LEN_STPCNT			(0x3u<<29)
#define	USBFS_DEVICE_DOEP0LEN_STPCNT_0			(0x1u<<29)

// DOEP1CTL Configuration

#define	USBFS_DEVICE_DOEP1CTL_MPL				(0x7FFu<<0)
#define	USBFS_DEVICE_DOEP1CTL_MPL_0				(0x1u<<0)
#define	USBFS_DEVICE_DOEP1CTL_EPACT				(0x1u<<15)
#define	USBFS_DEVICE_DOEP1CTL_EOFRM_DPID		(0x1u<<16)
#define	USBFS_DEVICE_DOEP1CTL_NAKS				(0x1u<<17)
#define	USBFS_DEVICE_DOEP1CTL_EPTYPE			(0x3u<<18)
#define	USBFS_DEVICE_DOEP1CTL_EPTYPE_0			(0x1u<<18)
#define	USBFS_DEVICE_DOEP1CTL_SNOOP				(0x1u<<20)
#define	USBFS_DEVICE_DOEP1CTL_STALL				(0x1u<<21)
#define	USBFS_DEVICE_DOEP1CTL_CNAK				(0x1u<<26)
#define	USBFS_DEVICE_DOEP1CTL_SNAK				(0x1u<<27)
#define	USBFS_DEVICE_DOEP1CTL_SD0PID_SEVENFRM	(0x1u<<28)
#define	USBFS_DEVICE_DOEP1CTL_SD1PID_SODDFRM	(0x1u<<29)
#define	USBFS_DEVICE_DOEP1CTL_EPD				(0x1u<<30)
#define	USBFS_DEVICE_DOEP1CTL_EPEN				(0x1u<<31)

// DOEP1INTF Configuration

#define	USBFS_DEVICE_DOEP1INTF_TF				(0x1u<<0)
#define	USBFS_DEVICE_DOEP1INTF_EPDIS			(0x1u<<1)
#define	USBFS_DEVICE_DOEP1INTF_STPF				(0x1u<<3)
#define	USBFS_DEVICE_DOEP1INTF_EPRXFOVR			(0x1u<<4)
#define	USBFS_DEVICE_DOEP1INTF_BTBSTP			(0x1u<<6)

// DOEP1LEN Configuration

#define	USBFS_DEVICE_DOEP1LEN_TLEN				(0x7FFFFu<<0)
#define	USBFS_DEVICE_DOEP1LEN_TLEN_0			(0x1u<<0)
#define	USBFS_DEVICE_DOEP1LEN_PCNT				(0x3FFu<<19)
#define	USBFS_DEVICE_DOEP1LEN_PCNT_0			(0x1u<<19)
#define	USBFS_DEVICE_DOEP1LEN_STPCNT_RXDPID		(0x3u<<29)
#define	USBFS_DEVICE_DOEP1LEN_STPCNT_RXDPID_0	(0x1u<<29)

// DOEP2CTL Configuration

#define	USBFS_DEVICE_DOEP2CTL_MPL				(0x7FFu<<0)
#define	USBFS_DEVICE_DOEP2CTL_MPL_0				(0x1u<<0)
#define	USBFS_DEVICE_DOEP2CTL_EPACT				(0x1u<<15)
#define	USBFS_DEVICE_DOEP2CTL_EOFRM_DPID		(0x1u<<16)
#define	USBFS_DEVICE_DOEP2CTL_NAKS				(0x1u<<17)
#define	USBFS_DEVICE_DOEP2CTL_EPTYPE			(0x3u<<18)
#define	USBFS_DEVICE_DOEP2CTL_EPTYPE_0			(0x1u<<18)
#define	USBFS_DEVICE_DOEP2CTL_SNOOP				(0x1u<<20)
#define	USBFS_DEVICE_DOEP2CTL_STALL				(0x1u<<21)
#define	USBFS_DEVICE_DOEP2CTL_CNAK				(0x1u<<26)
#define	USBFS_DEVICE_DOEP2CTL_SNAK				(0x1u<<27)
#define	USBFS_DEVICE_DOEP2CTL_SD0PID_SEVENFRM	(0x1u<<28)
#define	USBFS_DEVICE_DOEP2CTL_SD1PID_SODDFRM	(0x1u<<29)
#define	USBFS_DEVICE_DOEP2CTL_EPD				(0x1u<<30)
#define	USBFS_DEVICE_DOEP2CTL_EPEN				(0x1u<<31)

// DOEP2INTF Configuration

#define	USBFS_DEVICE_DOEP2INTF_TF				(0x1u<<0)
#define	USBFS_DEVICE_DOEP2INTF_EPDIS			(0x1u<<1)
#define	USBFS_DEVICE_DOEP2INTF_STPF				(0x1u<<3)
#define	USBFS_DEVICE_DOEP2INTF_EPRXFOVR			(0x1u<<4)
#define	USBFS_DEVICE_DOEP2INTF_BTBSTP			(0x1u<<6)

// DOEP2LEN Configuration

#define	USBFS_DEVICE_DOEP2LEN_TLEN				(0x7FFFFu<<0)
#define	USBFS_DEVICE_DOEP2LEN_TLEN_0			(0x1u<<0)
#define	USBFS_DEVICE_DOEP2LEN_PCNT				(0x3FFu<<19)
#define	USBFS_DEVICE_DOEP2LEN_PCNT_0			(0x1u<<19)
#define	USBFS_DEVICE_DOEP2LEN_STPCNT_RXDPID		(0x3u<<29)
#define	USBFS_DEVICE_DOEP2LEN_STPCNT_RXDPID_0	(0x1u<<29)

// DOEP3CTL Configuration

#define	USBFS_DEVICE_DOEP3CTL_MPL				(0x7FFu<<0)
#define	USBFS_DEVICE_DOEP3CTL_MPL_0				(0x1u<<0)
#define	USBFS_DEVICE_DOEP3CTL_EPACT				(0x1u<<15)
#define	USBFS_DEVICE_DOEP3CTL_EOFRM_DPID		(0x1u<<16)
#define	USBFS_DEVICE_DOEP3CTL_NAKS				(0x1u<<17)
#define	USBFS_DEVICE_DOEP3CTL_EPTYPE			(0x3u<<18)
#define	USBFS_DEVICE_DOEP3CTL_EPTYPE_0			(0x1u<<18)
#define	USBFS_DEVICE_DOEP3CTL_SNOOP				(0x1u<<20)
#define	USBFS_DEVICE_DOEP3CTL_STALL				(0x1u<<21)
#define	USBFS_DEVICE_DOEP3CTL_CNAK				(0x1u<<26)
#define	USBFS_DEVICE_DOEP3CTL_SNAK				(0x1u<<27)
#define	USBFS_DEVICE_DOEP3CTL_SD0PID_SEVENFRM	(0x1u<<28)
#define	USBFS_DEVICE_DOEP3CTL_SD1PID_SODDFRM	(0x1u<<29)
#define	USBFS_DEVICE_DOEP3CTL_EPD				(0x1u<<30)
#define	USBFS_DEVICE_DOEP3CTL_EPEN				(0x1u<<31)

// DOEP3INTF Configuration

#define	USBFS_DEVICE_DOEP3INTF_TF				(0x1u<<0)
#define	USBFS_DEVICE_DOEP3INTF_EPDIS			(0x1u<<1)
#define	USBFS_DEVICE_DOEP3INTF_STPF				(0x1u<<3)
#define	USBFS_DEVICE_DOEP3INTF_EPRXFOVR			(0x1u<<4)
#define	USBFS_DEVICE_DOEP3INTF_BTBSTP			(0x1u<<6)

// DOEP3LEN Configuration

#define	USBFS_DEVICE_DOEP3LEN_TLEN				(0x7FFFFu<<0)
#define	USBFS_DEVICE_DOEP3LEN_TLEN_0			(0x1u<<0)
#define	USBFS_DEVICE_DOEP3LEN_PCNT				(0x3FFu<<19)
#define	USBFS_DEVICE_DOEP3LEN_PCNT_0			(0x1u<<19)
#define	USBFS_DEVICE_DOEP3LEN_STPCNT_RXDPID		(0x3u<<29)
#define	USBFS_DEVICE_DOEP3LEN_STPCNT_RXDPID_0	(0x1u<<29)
