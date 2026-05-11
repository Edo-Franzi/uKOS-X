/*
; soc_addendum.
; =============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		addendum equates.
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

// FWDGT address definitions
// -------------------------

// CTL register

#define	FWDGT_CTL_DISABLE					0x5555u
#define	FWDGT_CTL_START						0xCCCCu
#define	FWDGT_CTL_RELOAD					0xAAAAu

// PSC register

#define	FWDGT_PSC_1_4						0x0000u
#define	FWDGT_PSC_1_8						0x0001u
#define	FWDGT_PSC_1_16						0x0002u
#define	FWDGT_PSC_1_32						0x0003u
#define	FWDGT_PSC_1_64						0x0004u
#define	FWDGT_PSC_1_128						0x0005u
#define	FWDGT_PSC_1_256						0x0006u

// ECLIC address definitions
// -------------------------

struct cint {
	volatile			uint8_t		IP;
	volatile			uint8_t		IE;
	volatile			uint8_t		ATTR;
	volatile			uint8_t		CTL;
};

typedef struct {
	volatile			uint8_t		CLICCFG;
	volatile			uint8_t		RESERVED0[3];
	volatile	const	uint32_t	CLICINFO;
	volatile			uint8_t		RESERVED1[3];
	volatile			uint8_t		MTH;
	volatile			uint32_t	RESERVED2;
	volatile			uint32_t	RESERVED3[(0x1000 - 0x0010) / sizeof(uint32_t)];
				struct	cint		CLICINT[4096];
} ECLIC_Type;

#define	ECLIC	((ECLIC_Type *)0xD2000000u)

// CFG register

#define	ECLIC_CFG_NLBITS_MASK				0x1Eu			//
#define	ECLIC_CFG_NLBITS_LSB				1u				//

// INT register

#define	ECLIC_INT_ATTR_SHV					1u
#define	ECLIC_INT_ATTR_TRIG_LEVEL			(0u<<1u)		//
#define	ECLIC_INT_ATTR_TRIG_EDGE			(1u<<1u)		//
#define	ECLIC_INT_ATTR_TRIG_EDGE_RISING		(2u<<1u)		//
#define	ECLIC_INT_ATTR_TRIG_EDGE_FALLING	(3u<<1u)		//

#define	ECLIC_INT_ATTR_TRIG_POS				0u				//
#define	ECLIC_INT_ATTR_TRIG_NEG				4u				//

// GROUP register

#define	ECLIC_GROUP_LEVEL0_PRIO4			(0u<<1u)		//
#define	ECLIC_GROUP_LEVEL1_PRIO3			(1u<<1u)		//
#define	ECLIC_GROUP_LEVEL2_PRIO2			(2u<<1u)		//
#define	ECLIC_GROUP_LEVEL3_PRIO1			(3u<<1u)		//
#define	ECLIC_GROUP_LEVEL4_PRIO0			(4u<<1u)		//

// gpio additional definitions
// ---------------------------

// Ports PA, PB, PC

enum {
	PA00 = 0u, PA01, PA02, PA03, PA04, PA05, PA06, PA07,
	PA08,      PA09, PA10, PA11, PA12, PA13, PA14, PA15
};

enum {
	PB00 = 20u, PB01, PB02, PB03, PB04, PB05, PB06, PB07,
	PB08,       PB09, PB10, PB11, PB12, PB13, PB14, PB15
};

enum {
	PC00 = 40u, PC01, PC02, PC03, PC04, PC05, PC06, PC07,
	PC08,       PC09, PC10, PC11, PC12, PC13, PC14, PC15
};

// GPIO configuration modes

enum {
	KIN_ANAOG = 0u,								// Input analog
	KIN_FLOAT,									// Input floating
	KIN_PULLD,									// Input with pull down
	KIN_PULLU,									// Input with pull up
	KOU_PUSHP_02,								// Output push-pull 2-MHz
	KOU_OPEND_02,								// Output open-drain 2-MHz
	KOU_PUSHP_10,								// Output push-pull 10-MHz
	KOU_OPEND_10,								// Output open-drain 10-MHz
	KOU_PUSHP_50,								// Output push-pull 50-MHz
	KOU_OPEND_50,								// Output open-drain 50-MHz
	KAF_PUSHP_02,								// Output AF push-pull 2-MHz
	KAF_OPEND_02,								// Output AF open-drain 2-MHz
	KAF_PUSHP_10,								// Output AF push-pull 10-MHz
	KAF_OPEND_10,								// Output AF open-drain 10-MHz
	KAF_PUSHP_50,								// Output AF push-pull 50-MHz
	KAF_OPEND_50								// Output AF open-drain 50-MHz
};

enum {
	GPIO_CTL0_MD_INPUT				= (0u<<0u),
	GPIO_CTL0_MD_OUTPUT_10MHZ		= (1u<<0u),
	GPIO_CTL0_MD_OUTPUT_2MHZ		= (2u<<0u),
	GPIO_CTL0_MD_OUTPUT_50MHZ		= (3u<<0u)
};

enum {
	GPIO_CTL0_CTL_INPUT_ANALOG		= (0u<<2u),
	GPIO_CTL0_CTL_INPUT_FLOATING	= (1u<<2u),
	GPIO_CTL0_CTL_INPUT_PULL		= (2u<<2u)
};

enum {
	GPIO_CTL0_CTL_OUTPUT_GPIO_PP	= (0u<<2u),
	GPIO_CTL0_CTL_OUTPUT_GPIO_OD	= (1u<<2u),
	GPIO_CTL0_CTL_OUTPUT_AFIO_PP	= (2u<<2u),
	GPIO_CTL0_CTL_OUTPUT_AFIO_OD	= (3u<<2u)
};
