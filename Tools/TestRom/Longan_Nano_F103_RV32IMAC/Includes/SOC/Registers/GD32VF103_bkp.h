/*
; GD32VF103_bkp.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		GD32VF103_bkp equates.
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

// BKP address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	RESERVED0;
	volatile	uint16_t	DATA0;
	volatile	uint16_t	RESERVED1;
	volatile	uint16_t	DATA1;
	volatile	uint16_t	RESERVED2;
	volatile	uint16_t	DATA2;
	volatile	uint16_t	RESERVED3;
	volatile	uint16_t	DATA3;
	volatile	uint16_t	RESERVED4;
	volatile	uint16_t	DATA4;
	volatile	uint16_t	RESERVED5;
	volatile	uint16_t	DATA5;
	volatile	uint16_t	RESERVED6;
	volatile	uint16_t	DATA6;
	volatile	uint16_t	RESERVED7;
	volatile	uint16_t	DATA7;
	volatile	uint16_t	RESERVED8;
	volatile	uint16_t	DATA8;
	volatile	uint16_t	RESERVED9;
	volatile	uint16_t	DATA9;
	volatile	uint16_t	RESERVED10;
	volatile	uint16_t	OCTL;
	volatile	uint16_t	RESERVED11;
	volatile	uint16_t	TPCTL;
	volatile	uint16_t	RESERVED12;
	volatile	uint16_t	TPCS;
	volatile	uint16_t	RESERVED13[5];
	volatile	uint16_t	DATA10;
	volatile	uint16_t	RESERVED14;
	volatile	uint16_t	DATA11;
	volatile	uint16_t	RESERVED15;
	volatile	uint16_t	DATA12;
	volatile	uint16_t	RESERVED16;
	volatile	uint16_t	DATA13;
	volatile	uint16_t	RESERVED17;
	volatile	uint16_t	DATA14;
	volatile	uint16_t	RESERVED18;
	volatile	uint16_t	DATA15;
	volatile	uint16_t	RESERVED19;
	volatile	uint16_t	DATA16;
	volatile	uint16_t	RESERVED20;
	volatile	uint16_t	DATA17;
	volatile	uint16_t	RESERVED21;
	volatile	uint16_t	DATA18;
	volatile	uint16_t	RESERVED22;
	volatile	uint16_t	DATA19;
	volatile	uint16_t	RESERVED23;
	volatile	uint16_t	DATA20;
	volatile	uint16_t	RESERVED24;
	volatile	uint16_t	DATA21;
	volatile	uint16_t	RESERVED25;
	volatile	uint16_t	DATA22;
	volatile	uint16_t	RESERVED26;
	volatile	uint16_t	DATA23;
	volatile	uint16_t	RESERVED27;
	volatile	uint16_t	DATA24;
	volatile	uint16_t	RESERVED28;
	volatile	uint16_t	DATA25;
	volatile	uint16_t	RESERVED29;
	volatile	uint16_t	DATA26;
	volatile	uint16_t	RESERVED30;
	volatile	uint16_t	DATA27;
	volatile	uint16_t	RESERVED31;
	volatile	uint16_t	DATA28;
	volatile	uint16_t	RESERVED32;
	volatile	uint16_t	DATA29;
	volatile	uint16_t	RESERVED33;
	volatile	uint16_t	DATA30;
	volatile	uint16_t	RESERVED34;
	volatile	uint16_t	DATA31;
	volatile	uint16_t	RESERVED35;
	volatile	uint16_t	DATA32;
	volatile	uint16_t	RESERVED36;
	volatile	uint16_t	DATA33;
	volatile	uint16_t	RESERVED37;
	volatile	uint16_t	DATA34;
	volatile	uint16_t	RESERVED38;
	volatile	uint16_t	DATA35;
	volatile	uint16_t	RESERVED39;
	volatile	uint16_t	DATA36;
	volatile	uint16_t	RESERVED40;
	volatile	uint16_t	DATA37;
	volatile	uint16_t	RESERVED41;
	volatile	uint16_t	DATA38;
	volatile	uint16_t	RESERVED42;
	volatile	uint16_t	DATA39;
	volatile	uint16_t	RESERVED43;
	volatile	uint16_t	DATA40;
	volatile	uint16_t	RESERVED44;
	volatile	uint16_t	DATA41;
} BKP_TypeDef;

#if (defined(__cplusplus))
#define	BKP	reinterpret_cast<BKP_TypeDef *>(0x40006C00u)

#else
#define	BKP	((BKP_TypeDef *)0x40006C00u)
#endif

// DATA0 Configuration

#define	BKP_DATA0_DATA		(0xFFFFu<<0)
#define	BKP_DATA0_DATA_0	(0x1u<<0)

// DATA1 Configuration

#define	BKP_DATA1_DATA		(0xFFFFu<<0)
#define	BKP_DATA1_DATA_0	(0x1u<<0)

// DATA2 Configuration

#define	BKP_DATA2_DATA		(0xFFFFu<<0)
#define	BKP_DATA2_DATA_0	(0x1u<<0)

// DATA3 Configuration

#define	BKP_DATA3_DATA		(0xFFFFu<<0)
#define	BKP_DATA3_DATA_0	(0x1u<<0)

// DATA4 Configuration

#define	BKP_DATA4_DATA		(0xFFFFu<<0)
#define	BKP_DATA4_DATA_0	(0x1u<<0)

// DATA5 Configuration

#define	BKP_DATA5_DATA		(0xFFFFu<<0)
#define	BKP_DATA5_DATA_0	(0x1u<<0)

// DATA6 Configuration

#define	BKP_DATA6_DATA		(0xFFFFu<<0)
#define	BKP_DATA6_DATA_0	(0x1u<<0)

// DATA7 Configuration

#define	BKP_DATA7_DATA		(0xFFFFu<<0)
#define	BKP_DATA7_DATA_0	(0x1u<<0)

// DATA8 Configuration

#define	BKP_DATA8_DATA		(0xFFFFu<<0)
#define	BKP_DATA8_DATA_0	(0x1u<<0)

// DATA9 Configuration

#define	BKP_DATA9_DATA		(0xFFFFu<<0)
#define	BKP_DATA9_DATA_0	(0x1u<<0)

// OCTL Configuration

#define	BKP_OCTL_RCCV		(0x7Fu<<0)
#define	BKP_OCTL_RCCV_0		(0x1u<<0)
#define	BKP_OCTL_COEN		(0x1u<<7)
#define	BKP_OCTL_ASOEN		(0x1u<<8)
#define	BKP_OCTL_ROSEL		(0x1u<<9)

// TPCTL Configuration

#define	BKP_TPCTL_TPEN		(0x1u<<0)
#define	BKP_TPCTL_TPAL		(0x1u<<1)

// TPCS Configuration

#define	BKP_TPCS_TER		(0x1u<<0)
#define	BKP_TPCS_TIR		(0x1u<<1)
#define	BKP_TPCS_TPIE		(0x1u<<2)
#define	BKP_TPCS_TEF		(0x1u<<8)
#define	BKP_TPCS_TIF		(0x1u<<9)

// DATA10 Configuration

#define	BKP_DATA10_DATA		(0xFFFFu<<0)
#define	BKP_DATA10_DATA_0	(0x1u<<0)

// DATA11 Configuration

#define	BKP_DATA11_DATA		(0xFFFFu<<0)
#define	BKP_DATA11_DATA_0	(0x1u<<0)

// DATA12 Configuration

#define	BKP_DATA12_DATA		(0xFFFFu<<0)
#define	BKP_DATA12_DATA_0	(0x1u<<0)

// DATA13 Configuration

#define	BKP_DATA13_DATA		(0xFFFFu<<0)
#define	BKP_DATA13_DATA_0	(0x1u<<0)

// DATA14 Configuration

#define	BKP_DATA14_DATA		(0xFFFFu<<0)
#define	BKP_DATA14_DATA_0	(0x1u<<0)

// DATA15 Configuration

#define	BKP_DATA15_DATA		(0xFFFFu<<0)
#define	BKP_DATA15_DATA_0	(0x1u<<0)

// DATA16 Configuration

#define	BKP_DATA16_DATA		(0xFFFFu<<0)
#define	BKP_DATA16_DATA_0	(0x1u<<0)

// DATA17 Configuration

#define	BKP_DATA17_DATA		(0xFFFFu<<0)
#define	BKP_DATA17_DATA_0	(0x1u<<0)

// DATA18 Configuration

#define	BKP_DATA18_DATA		(0xFFFFu<<0)
#define	BKP_DATA18_DATA_0	(0x1u<<0)

// DATA19 Configuration

#define	BKP_DATA19_DATA		(0xFFFFu<<0)
#define	BKP_DATA19_DATA_0	(0x1u<<0)

// DATA20 Configuration

#define	BKP_DATA20_DATA		(0xFFFFu<<0)
#define	BKP_DATA20_DATA_0	(0x1u<<0)

// DATA21 Configuration

#define	BKP_DATA21_DATA		(0xFFFFu<<0)
#define	BKP_DATA21_DATA_0	(0x1u<<0)

// DATA22 Configuration

#define	BKP_DATA22_DATA		(0xFFFFu<<0)
#define	BKP_DATA22_DATA_0	(0x1u<<0)

// DATA23 Configuration

#define	BKP_DATA23_DATA		(0xFFFFu<<0)
#define	BKP_DATA23_DATA_0	(0x1u<<0)

// DATA24 Configuration

#define	BKP_DATA24_DATA		(0xFFFFu<<0)
#define	BKP_DATA24_DATA_0	(0x1u<<0)

// DATA25 Configuration

#define	BKP_DATA25_DATA		(0xFFFFu<<0)
#define	BKP_DATA25_DATA_0	(0x1u<<0)

// DATA26 Configuration

#define	BKP_DATA26_DATA		(0xFFFFu<<0)
#define	BKP_DATA26_DATA_0	(0x1u<<0)

// DATA27 Configuration

#define	BKP_DATA27_DATA		(0xFFFFu<<0)
#define	BKP_DATA27_DATA_0	(0x1u<<0)

// DATA28 Configuration

#define	BKP_DATA28_DATA		(0xFFFFu<<0)
#define	BKP_DATA28_DATA_0	(0x1u<<0)

// DATA29 Configuration

#define	BKP_DATA29_DATA		(0xFFFFu<<0)
#define	BKP_DATA29_DATA_0	(0x1u<<0)

// DATA30 Configuration

#define	BKP_DATA30_DATA		(0xFFFFu<<0)
#define	BKP_DATA30_DATA_0	(0x1u<<0)

// DATA31 Configuration

#define	BKP_DATA31_DATA		(0xFFFFu<<0)
#define	BKP_DATA31_DATA_0	(0x1u<<0)

// DATA32 Configuration

#define	BKP_DATA32_DATA		(0xFFFFu<<0)
#define	BKP_DATA32_DATA_0	(0x1u<<0)

// DATA33 Configuration

#define	BKP_DATA33_DATA		(0xFFFFu<<0)
#define	BKP_DATA33_DATA_0	(0x1u<<0)

// DATA34 Configuration

#define	BKP_DATA34_DATA		(0xFFFFu<<0)
#define	BKP_DATA34_DATA_0	(0x1u<<0)

// DATA35 Configuration

#define	BKP_DATA35_DATA		(0xFFFFu<<0)
#define	BKP_DATA35_DATA_0	(0x1u<<0)

// DATA36 Configuration

#define	BKP_DATA36_DATA		(0xFFFFu<<0)
#define	BKP_DATA36_DATA_0	(0x1u<<0)

// DATA37 Configuration

#define	BKP_DATA37_DATA		(0xFFFFu<<0)
#define	BKP_DATA37_DATA_0	(0x1u<<0)

// DATA38 Configuration

#define	BKP_DATA38_DATA		(0xFFFFu<<0)
#define	BKP_DATA38_DATA_0	(0x1u<<0)

// DATA39 Configuration

#define	BKP_DATA39_DATA		(0xFFFFu<<0)
#define	BKP_DATA39_DATA_0	(0x1u<<0)

// DATA40 Configuration

#define	BKP_DATA40_DATA		(0xFFFFu<<0)
#define	BKP_DATA40_DATA_0	(0x1u<<0)

// DATA41 Configuration

#define	BKP_DATA41_DATA		(0xFFFFu<<0)
#define	BKP_DATA41_DATA_0	(0x1u<<0)
