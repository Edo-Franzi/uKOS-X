/*
; RP2350_pads_bank0.
; ==================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_pads_bank0 equates.
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

// PADS_BANK0 address definitions
// ------------------------------

typedef struct {
	volatile	uint32_t	VOLTAGE_SELECT;
	volatile	uint32_t	GPIO0;
	volatile	uint32_t	GPIO1;
	volatile	uint32_t	GPIO2;
	volatile	uint32_t	GPIO3;
	volatile	uint32_t	GPIO4;
	volatile	uint32_t	GPIO5;
	volatile	uint32_t	GPIO6;
	volatile	uint32_t	GPIO7;
	volatile	uint32_t	GPIO8;
	volatile	uint32_t	GPIO9;
	volatile	uint32_t	GPIO10;
	volatile	uint32_t	GPIO11;
	volatile	uint32_t	GPIO12;
	volatile	uint32_t	GPIO13;
	volatile	uint32_t	GPIO14;
	volatile	uint32_t	GPIO15;
	volatile	uint32_t	GPIO16;
	volatile	uint32_t	GPIO17;
	volatile	uint32_t	GPIO18;
	volatile	uint32_t	GPIO19;
	volatile	uint32_t	GPIO20;
	volatile	uint32_t	GPIO21;
	volatile	uint32_t	GPIO22;
	volatile	uint32_t	GPIO23;
	volatile	uint32_t	GPIO24;
	volatile	uint32_t	GPIO25;
	volatile	uint32_t	GPIO26;
	volatile	uint32_t	GPIO27;
	volatile	uint32_t	GPIO28;
	volatile	uint32_t	GPIO29;
	volatile	uint32_t	GPIO30;
	volatile	uint32_t	GPIO31;
	volatile	uint32_t	GPIO32;
	volatile	uint32_t	GPIO33;
	volatile	uint32_t	GPIO34;
	volatile	uint32_t	GPIO35;
	volatile	uint32_t	GPIO36;
	volatile	uint32_t	GPIO37;
	volatile	uint32_t	GPIO38;
	volatile	uint32_t	GPIO39;
	volatile	uint32_t	GPIO40;
	volatile	uint32_t	GPIO41;
	volatile	uint32_t	GPIO42;
	volatile	uint32_t	GPIO43;
	volatile	uint32_t	GPIO44;
	volatile	uint32_t	GPIO45;
	volatile	uint32_t	GPIO46;
	volatile	uint32_t	GPIO47;
	volatile	uint32_t	SWCLK;
	volatile	uint32_t	SWD;
} PADS_BANK0_TypeDef;

#ifdef __cplusplus
#define	PADS_BANK0_NS	reinterpret_cast<PADS_BANK0_TypeDef *>(0x40038000u)
#define	PADS_BANK0_S	reinterpret_cast<PADS_BANK0_TypeDef *>(0x40038000u)
#else
#define	PADS_BANK0_NS	((PADS_BANK0_TypeDef *)0x40038000u)
#define	PADS_BANK0_S	((PADS_BANK0_TypeDef *)0x40038000u)
#endif

// VOLTAGE_SELECT Configuration

#define	PADS_BANK0_VOLTAGE_SELECT_VOLTAGE_SELECT		(0x1u<<0)
#define	PADS_BANK0_VOLTAGE_SELECT_VOLTAGE_SELECT_3V3	(0x0u<<0)
#define	PADS_BANK0_VOLTAGE_SELECT_VOLTAGE_SELECT_1V8	(0x1u<<0)

// GPIO0 Configuration

#define	PADS_BANK0_GPIO0_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO0_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO0_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO0_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO0_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO0_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO0_IE								(0x1u<<6)
#define	PADS_BANK0_GPIO0_OD								(0x1u<<7)
#define	PADS_BANK0_GPIO0_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO0_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO0_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO0_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO0_DRIVE_12MA						(0x3u<<4)

// GPIO1 Configuration

#define	PADS_BANK0_GPIO1_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO1_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO1_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO1_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO1_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO1_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO1_IE								(0x1u<<6)
#define	PADS_BANK0_GPIO1_OD								(0x1u<<7)
#define	PADS_BANK0_GPIO1_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO1_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO1_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO1_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO1_DRIVE_12MA						(0x3u<<4)

// GPIO2 Configuration

#define	PADS_BANK0_GPIO2_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO2_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO2_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO2_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO2_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO2_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO2_IE								(0x1u<<6)
#define	PADS_BANK0_GPIO2_OD								(0x1u<<7)
#define	PADS_BANK0_GPIO2_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO2_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO2_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO2_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO2_DRIVE_12MA						(0x3u<<4)

// GPIO3 Configuration

#define	PADS_BANK0_GPIO3_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO3_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO3_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO3_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO3_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO3_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO3_IE								(0x1u<<6)
#define	PADS_BANK0_GPIO3_OD								(0x1u<<7)
#define	PADS_BANK0_GPIO3_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO3_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO3_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO3_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO3_DRIVE_12MA						(0x3u<<4)

// GPIO4 Configuration

#define	PADS_BANK0_GPIO4_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO4_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO4_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO4_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO4_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO4_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO4_IE								(0x1u<<6)
#define	PADS_BANK0_GPIO4_OD								(0x1u<<7)
#define	PADS_BANK0_GPIO4_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO4_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO4_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO4_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO4_DRIVE_12MA						(0x3u<<4)

// GPIO5 Configuration

#define	PADS_BANK0_GPIO5_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO5_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO5_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO5_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO5_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO5_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO5_IE								(0x1u<<6)
#define	PADS_BANK0_GPIO5_OD								(0x1u<<7)
#define	PADS_BANK0_GPIO5_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO5_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO5_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO5_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO5_DRIVE_12MA						(0x3u<<4)

// GPIO6 Configuration

#define	PADS_BANK0_GPIO6_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO6_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO6_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO6_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO6_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO6_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO6_IE								(0x1u<<6)
#define	PADS_BANK0_GPIO6_OD								(0x1u<<7)
#define	PADS_BANK0_GPIO6_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO6_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO6_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO6_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO6_DRIVE_12MA						(0x3u<<4)

// GPIO7 Configuration

#define	PADS_BANK0_GPIO7_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO7_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO7_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO7_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO7_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO7_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO7_IE								(0x1u<<6)
#define	PADS_BANK0_GPIO7_OD								(0x1u<<7)
#define	PADS_BANK0_GPIO7_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO7_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO7_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO7_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO7_DRIVE_12MA						(0x3u<<4)

// GPIO8 Configuration

#define	PADS_BANK0_GPIO8_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO8_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO8_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO8_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO8_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO8_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO8_IE								(0x1u<<6)
#define	PADS_BANK0_GPIO8_OD								(0x1u<<7)
#define	PADS_BANK0_GPIO8_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO8_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO8_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO8_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO8_DRIVE_12MA						(0x3u<<4)

// GPIO9 Configuration

#define	PADS_BANK0_GPIO9_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO9_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO9_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO9_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO9_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO9_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO9_IE								(0x1u<<6)
#define	PADS_BANK0_GPIO9_OD								(0x1u<<7)
#define	PADS_BANK0_GPIO9_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO9_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO9_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO9_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO9_DRIVE_12MA						(0x3u<<4)

// GPIO10 Configuration

#define	PADS_BANK0_GPIO10_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO10_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO10_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO10_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO10_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO10_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO10_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO10_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO10_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO10_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO10_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO10_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO10_DRIVE_12MA					(0x3u<<4)

// GPIO11 Configuration

#define	PADS_BANK0_GPIO11_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO11_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO11_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO11_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO11_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO11_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO11_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO11_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO11_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO11_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO11_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO11_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO11_DRIVE_12MA					(0x3u<<4)

// GPIO12 Configuration

#define	PADS_BANK0_GPIO12_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO12_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO12_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO12_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO12_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO12_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO12_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO12_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO12_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO12_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO12_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO12_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO12_DRIVE_12MA					(0x3u<<4)

// GPIO13 Configuration

#define	PADS_BANK0_GPIO13_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO13_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO13_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO13_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO13_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO13_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO13_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO13_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO13_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO13_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO13_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO13_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO13_DRIVE_12MA					(0x3u<<4)

// GPIO14 Configuration

#define	PADS_BANK0_GPIO14_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO14_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO14_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO14_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO14_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO14_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO14_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO14_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO14_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO14_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO14_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO14_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO14_DRIVE_12MA					(0x3u<<4)

// GPIO15 Configuration

#define	PADS_BANK0_GPIO15_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO15_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO15_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO15_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO15_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO15_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO15_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO15_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO15_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO15_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO15_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO15_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO15_DRIVE_12MA					(0x3u<<4)

// GPIO16 Configuration

#define	PADS_BANK0_GPIO16_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO16_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO16_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO16_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO16_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO16_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO16_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO16_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO16_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO16_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO16_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO16_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO16_DRIVE_12MA					(0x3u<<4)

// GPIO17 Configuration

#define	PADS_BANK0_GPIO17_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO17_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO17_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO17_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO17_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO17_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO17_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO17_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO17_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO17_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO17_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO17_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO17_DRIVE_12MA					(0x3u<<4)

// GPIO18 Configuration

#define	PADS_BANK0_GPIO18_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO18_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO18_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO18_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO18_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO18_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO18_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO18_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO18_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO18_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO18_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO18_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO18_DRIVE_12MA					(0x3u<<4)

// GPIO19 Configuration

#define	PADS_BANK0_GPIO19_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO19_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO19_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO19_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO19_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO19_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO19_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO19_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO19_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO19_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO19_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO19_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO19_DRIVE_12MA					(0x3u<<4)

// GPIO20 Configuration

#define	PADS_BANK0_GPIO20_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO20_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO20_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO20_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO20_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO20_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO20_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO20_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO20_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO20_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO20_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO20_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO20_DRIVE_12MA					(0x3u<<4)

// GPIO21 Configuration

#define	PADS_BANK0_GPIO21_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO21_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO21_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO21_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO21_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO21_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO21_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO21_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO21_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO21_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO21_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO21_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO21_DRIVE_12MA					(0x3u<<4)

// GPIO22 Configuration

#define	PADS_BANK0_GPIO22_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO22_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO22_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO22_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO22_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO22_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO22_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO22_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO22_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO22_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO22_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO22_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO22_DRIVE_12MA					(0x3u<<4)

// GPIO23 Configuration

#define	PADS_BANK0_GPIO23_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO23_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO23_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO23_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO23_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO23_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO23_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO23_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO23_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO23_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO23_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO23_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO23_DRIVE_12MA					(0x3u<<4)

// GPIO24 Configuration

#define	PADS_BANK0_GPIO24_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO24_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO24_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO24_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO24_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO24_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO24_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO24_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO24_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO24_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO24_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO24_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO24_DRIVE_12MA					(0x3u<<4)

// GPIO25 Configuration

#define	PADS_BANK0_GPIO25_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO25_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO25_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO25_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO25_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO25_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO25_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO25_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO25_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO25_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO25_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO25_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO25_DRIVE_12MA					(0x3u<<4)

// GPIO26 Configuration

#define	PADS_BANK0_GPIO26_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO26_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO26_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO26_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO26_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO26_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO26_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO26_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO26_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO26_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO26_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO26_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO26_DRIVE_12MA					(0x3u<<4)

// GPIO27 Configuration

#define	PADS_BANK0_GPIO27_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO27_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO27_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO27_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO27_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO27_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO27_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO27_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO27_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO27_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO27_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO27_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO27_DRIVE_12MA					(0x3u<<4)

// GPIO28 Configuration

#define	PADS_BANK0_GPIO28_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO28_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO28_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO28_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO28_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO28_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO28_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO28_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO28_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO28_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO28_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO28_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO28_DRIVE_12MA					(0x3u<<4)

// GPIO29 Configuration

#define	PADS_BANK0_GPIO29_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO29_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO29_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO29_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO29_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO29_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO29_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO29_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO29_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO29_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO29_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO29_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO29_DRIVE_12MA					(0x3u<<4)

// GPIO30 Configuration

#define	PADS_BANK0_GPIO30_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO30_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO30_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO30_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO30_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO30_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO30_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO30_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO30_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO30_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO30_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO30_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO30_DRIVE_12MA					(0x3u<<4)

// GPIO31 Configuration

#define	PADS_BANK0_GPIO31_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO31_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO31_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO31_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO31_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO31_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO31_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO31_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO31_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO31_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO31_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO31_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO31_DRIVE_12MA					(0x3u<<4)

// GPIO32 Configuration

#define	PADS_BANK0_GPIO32_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO32_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO32_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO32_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO32_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO32_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO32_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO32_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO32_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO32_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO32_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO32_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO32_DRIVE_12MA					(0x3u<<4)

// GPIO33 Configuration

#define	PADS_BANK0_GPIO33_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO33_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO33_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO33_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO33_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO33_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO33_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO33_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO33_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO33_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO33_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO33_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO33_DRIVE_12MA					(0x3u<<4)

// GPIO34 Configuration

#define	PADS_BANK0_GPIO34_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO34_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO34_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO34_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO34_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO34_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO34_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO34_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO34_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO34_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO34_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO34_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO34_DRIVE_12MA					(0x3u<<4)

// GPIO35 Configuration

#define	PADS_BANK0_GPIO35_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO35_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO35_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO35_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO35_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO35_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO35_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO35_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO35_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO35_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO35_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO35_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO35_DRIVE_12MA					(0x3u<<4)

// GPIO36 Configuration

#define	PADS_BANK0_GPIO36_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO36_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO36_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO36_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO36_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO36_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO36_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO36_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO36_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO36_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO36_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO36_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO36_DRIVE_12MA					(0x3u<<4)

// GPIO37 Configuration

#define	PADS_BANK0_GPIO37_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO37_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO37_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO37_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO37_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO37_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO37_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO37_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO37_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO37_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO37_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO37_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO37_DRIVE_12MA					(0x3u<<4)

// GPIO38 Configuration

#define	PADS_BANK0_GPIO38_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO38_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO38_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO38_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO38_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO38_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO38_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO38_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO38_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO38_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO38_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO38_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO38_DRIVE_12MA					(0x3u<<4)

// GPIO39 Configuration

#define	PADS_BANK0_GPIO39_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO39_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO39_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO39_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO39_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO39_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO39_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO39_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO39_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO39_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO39_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO39_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO39_DRIVE_12MA					(0x3u<<4)

// GPIO40 Configuration

#define	PADS_BANK0_GPIO40_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO40_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO40_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO40_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO40_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO40_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO40_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO40_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO40_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO40_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO40_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO40_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO40_DRIVE_12MA					(0x3u<<4)

// GPIO41 Configuration

#define	PADS_BANK0_GPIO41_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO41_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO41_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO41_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO41_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO41_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO41_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO41_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO41_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO41_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO41_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO41_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO41_DRIVE_12MA					(0x3u<<4)

// GPIO42 Configuration

#define	PADS_BANK0_GPIO42_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO42_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO42_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO42_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO42_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO42_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO42_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO42_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO42_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO42_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO42_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO42_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO42_DRIVE_12MA					(0x3u<<4)

// GPIO43 Configuration

#define	PADS_BANK0_GPIO43_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO43_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO43_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO43_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO43_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO43_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO43_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO43_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO43_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO43_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO43_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO43_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO43_DRIVE_12MA					(0x3u<<4)

// GPIO44 Configuration

#define	PADS_BANK0_GPIO44_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO44_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO44_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO44_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO44_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO44_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO44_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO44_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO44_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO44_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO44_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO44_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO44_DRIVE_12MA					(0x3u<<4)

// GPIO45 Configuration

#define	PADS_BANK0_GPIO45_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO45_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO45_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO45_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO45_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO45_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO45_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO45_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO45_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO45_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO45_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO45_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO45_DRIVE_12MA					(0x3u<<4)

// GPIO46 Configuration

#define	PADS_BANK0_GPIO46_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO46_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO46_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO46_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO46_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO46_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO46_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO46_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO46_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO46_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO46_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO46_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO46_DRIVE_12MA					(0x3u<<4)

// GPIO47 Configuration

#define	PADS_BANK0_GPIO47_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_GPIO47_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_GPIO47_PDE							(0x1u<<2)
#define	PADS_BANK0_GPIO47_PUE							(0x1u<<3)
#define	PADS_BANK0_GPIO47_DRIVE							(0x3u<<4)
#define	PADS_BANK0_GPIO47_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_GPIO47_IE							(0x1u<<6)
#define	PADS_BANK0_GPIO47_OD							(0x1u<<7)
#define	PADS_BANK0_GPIO47_ISO							(0x1u<<8)
#define	PADS_BANK0_GPIO47_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_GPIO47_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_GPIO47_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_GPIO47_DRIVE_12MA					(0x3u<<4)

// SWCLK Configuration

#define	PADS_BANK0_SWCLK_SLEWFAST						(0x1u<<0)
#define	PADS_BANK0_SWCLK_SCHMITT						(0x1u<<1)
#define	PADS_BANK0_SWCLK_PDE							(0x1u<<2)
#define	PADS_BANK0_SWCLK_PUE							(0x1u<<3)
#define	PADS_BANK0_SWCLK_DRIVE							(0x3u<<4)
#define	PADS_BANK0_SWCLK_DRIVE_0						(0x1u<<4)
#define	PADS_BANK0_SWCLK_IE								(0x1u<<6)
#define	PADS_BANK0_SWCLK_OD								(0x1u<<7)
#define	PADS_BANK0_SWCLK_ISO							(0x1u<<8)
#define	PADS_BANK0_SWCLK_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_SWCLK_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_SWCLK_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_SWCLK_DRIVE_12MA						(0x3u<<4)

// SWD Configuration

#define	PADS_BANK0_SWD_SLEWFAST							(0x1u<<0)
#define	PADS_BANK0_SWD_SCHMITT							(0x1u<<1)
#define	PADS_BANK0_SWD_PDE								(0x1u<<2)
#define	PADS_BANK0_SWD_PUE								(0x1u<<3)
#define	PADS_BANK0_SWD_DRIVE							(0x3u<<4)
#define	PADS_BANK0_SWD_DRIVE_0							(0x1u<<4)
#define	PADS_BANK0_SWD_IE								(0x1u<<6)
#define	PADS_BANK0_SWD_OD								(0x1u<<7)
#define	PADS_BANK0_SWD_ISO								(0x1u<<8)
#define	PADS_BANK0_SWD_DRIVE_2MA						(0x0u<<4)
#define	PADS_BANK0_SWD_DRIVE_4MA						(0x1u<<4)
#define	PADS_BANK0_SWD_DRIVE_8MA						(0x2u<<4)
#define	PADS_BANK0_SWD_DRIVE_12MA						(0x3u<<4)
