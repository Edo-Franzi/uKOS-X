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

// Unique device ID register base address
// --------------------------------------

#define UID_BASE					0x0BFA0700u

// iwdg additional definitions
// ---------------------------

// KR Configuration

#define	IWDG_KR_DISABLE				0x5555u
#define	IWDG_KR_START				0xCCCCu
#define	IWDG_KR_RELOAD				0xAAAAu

// PR Configuration

#define	IWDG_PR_1_4					0x0000u
#define	IWDG_PR_1_8					0x0001u
#define	IWDG_PR_1_16				0x0002u
#define	IWDG_PR_1_32				0x0003u
#define	IWDG_PR_1_64				0x0004u
#define	IWDG_PR_1_128				0x0005u
#define	IWDG_PR_1_256				0x0006u
#define	IWDG_PR_1_512				0x0007u

// otg additional definitions
// --------------------------

#define	OTG_HS_GCCFG_VBVALEXTOEN	(0x1u<<24)
#define	OTG_HS_GCCFG_VBVALOVAL		(0x1u<<23)
#define	USB_OTG_HS_BASE				(uintptr_t)OTG_HS_S

// gpio additional definitions
// ---------------------------

// GPIO for MODE configuration
// - Input (reset state)
// - General purpose output
// - Alternate function
// - Analog function

#define	KIN							0x0u
#define	KOU							0x1u
#define	KAL							0x2u
#define	KAN							0x3u

// GPIO for OTYPER configuration
// - Output Push-pull
// - Output Open Drain

#define	KPP							0x0u
#define	KOD							0x1u

// GPIO for OSPEEDR configuration
// - Low speed 2-MHz
// - Medium speed 25-MHz
// - Fast speed 50-MHz
// - High speed 100-MHz

#define	K02							0x0u
#define	K25							0x1u
#define	K50							0x2u
#define	K99							0x3u

// GPIO for PUPDR configuration
// - No pull-up, pull-down
// - Pull-up
// - Pull-down
// - Reserved

#define	KNO							0x0u
#define	KPU							0x1u
#define	KPD							0x2u
#define	KRE							0x3u

// GPIO for AFR[x] configuration

#define	A00							0u
#define	A01							1u
#define	A02							2u
#define	A03							3u
#define	A04							4u
#define	A05							5u
#define	A06							6u
#define	A07							7u
#define	A08							8u
#define	A09							9u
#define	A10							10u
#define	A11							11u
#define	A12							12u
#define	A13							13u
#define	A14							14u
#define	A15							15u

// GPIO configure macro

#if (defined(SECURE_S))
#define	CNFGPIO(port, \
				a15, a14, a13, a12, a11, a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0, \
				b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, \
				c15, c14, c13, c12, c11, c10, c9, c8, c7, c6, c5, c4, c3, c2, c1, c0, \
				d15, d14, d13, d12, d11, d10, d9, d8, d7, d6, d5, d4, d3, d2, d1, d0, \
				e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0, \
				f15, f14, f13, f12, f11, f10, f9, f8, f7, f6, f5, f4, f3, f2, f1, f0, \
				g15, g14, g13, g12, g11, g10, g9, g8, g7, g6, g5, g4, g3, g2, g1, g0) \
				GPIO##port##_S->AFRH =		(d15<<28) | (d14<<24) | (d13<<20) | (d12<<16) |	\
											(d11<<12) | (d10<<8)  | (d9<<4)   | (d8<<0); \
				GPIO##port##_S->AFRL =		(d7<<28)  | (d6<<24)  | (d5<<20)  | (d4<<16)  |	\
											(d3<<12)  | (d2<<8)   | (d1<<4)   | (d0<<0); \
				GPIO##port##_S->OSPEEDR =	(b15<<30) | (b14<<28) | (b13<<26) | (b12<<24) |	\
											(b11<<22) | (b10<<20) | (b9<<18)  | (b8<<16)  |	\
											(b7<<14)  | (b6<<12)  | (b5<<10)  | (b4<<8)   |	\
											(b3<<6)   | (b2<<4)   | (b1<<2)   | (b0<<0); \
				GPIO##port##_S->OTYPER =	(e15<<15) | (e14<<14) | (e13<<13) | (e12<<12) |	\
											(e11<<11) | (e10<<10) | (e9<<9)   | (e8<<8)   |	\
											(e7<<7)   | (e6<<6)   | (e5<<5)   | (e4<<4)   |	\
											(e3<<3)   | (e2<<2)   | (e1<<1)   | (e0<<0); \
				GPIO##port##_S->MODER =		(a15<<30) | (a14<<28) | (a13<<26) | (a12<<24) |	\
											(a11<<22) | (a10<<20) | (a9<<18)  | (a8<<16)  |	\
											(a7<<14)  | (a6<<12)  | (a5<<10)  | (a4<<8)   |	\
											(a3<<6)   | (a2<<4)   | (a1<<2)   | (a0<<0); \
				GPIO##port##_S->PUPDR =		(c15<<30) | (c14<<28) | (c13<<26) | (c12<<24) |	\
											(c11<<22) | (c10<<20) | (c9<<18)  | (c8<<16)  |	\
											(c7<<14)  | (c6<<12)  | (c5<<10)  | (c4<<8)   |	\
											(c3<<6)   | (c2<<4)   | (c1<<2)   | (c0<<0); \
				GPIO##port##_S->ODR |=		(f15<<15) | (f14<<14) | (f13<<13) | (f12<<12) |	\
											(f11<<11) | (f10<<10) | (f9<<9)   | (f8<<8)   |	\
											(f7<<7)   | (f6<<6)   | (f5<<5)   | (f4<<4)   |	\
											(f3<<3)   | (f2<<2)   | (f1<<1)   | (f0<<0); \
				GPIO##port##_S->HSLVR |=	(g15<<15) | (g14<<14) | (g13<<13) | (g12<<12) |	\
											(g11<<11) | (g10<<10) | (g9<<9)   | (g8<<8)   |	\
											(g7<<7)   | (g6<<6)   | (g5<<5)   | (g4<<4)   |	\
											(g3<<3)   | (g2<<2)   | (g1<<1)   | (g0<<0);

#else
#define	CNFGPIO(port, \
				a15, a14, a13, a12, a11, a10, a9, a8, a7, a6, a5, a4, a3, a2, a1, a0, \
				b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0, \
				c15, c14, c13, c12, c11, c10, c9, c8, c7, c6, c5, c4, c3, c2, c1, c0, \
				d15, d14, d13, d12, d11, d10, d9, d8, d7, d6, d5, d4, d3, d2, d1, d0, \
				e15, e14, e13, e12, e11, e10, e9, e8, e7, e6, e5, e4, e3, e2, e1, e0, \
				f15, f14, f13, f12, f11, f10, f9, f8, f7, f6, f5, f4, f3, f2, f1, f0, \
				g15, g14, g13, g12, g11, g10, g9, g8, g7, g6, g5, g4, g3, g2, g1, g0) \
				GPIO##port##_NS->AFRH =		(d15<<28) | (d14<<24) | (d13<<20) | (d12<<16) |	\
											(d11<<12) | (d10<<8)  | (d9<<4)   | (d8<<0); \
				GPIO##port##_NS->AFRL =		(d7<<28)  | (d6<<24)  | (d5<<20)  | (d4<<16)  |	\
											(d3<<12)  | (d2<<8)   | (d1<<4)   | (d0<<0); \
				GPIO##port##_NS->OSPEEDR =	(b15<<30) | (b14<<28) | (b13<<26) | (b12<<24) |	\
											(b11<<22) | (b10<<20) | (b9<<18)  | (b8<<16)  |	\
											(b7<<14)  | (b6<<12)  | (b5<<10)  | (b4<<8)   |	\
											(b3<<6)   | (b2<<4)   | (b1<<2)   | (b0<<0); \
				GPIO##port##_NS->OTYPER =	(e15<<15) | (e14<<14) | (e13<<13) | (e12<<12) |	\
											(e11<<11) | (e10<<10) | (e9<<9)   | (e8<<8)   |	\
											(e7<<7)   | (e6<<6)   | (e5<<5)   | (e4<<4)   |	\
											(e3<<3)   | (e2<<2)   | (e1<<1)   | (e0<<0); \
				GPIO##port##_NS->MODER =	(a15<<30) | (a14<<28) | (a13<<26) | (a12<<24) |	\
											(a11<<22) | (a10<<20) | (a9<<18)  | (a8<<16)  |	\
											(a7<<14)  | (a6<<12)  | (a5<<10)  | (a4<<8)   |	\
											(a3<<6)   | (a2<<4)   | (a1<<2)   | (a0<<0); \
				GPIO##port##_NS->PUPDR =	(c15<<30) | (c14<<28) | (c13<<26) | (c12<<24) |	\
											(c11<<22) | (c10<<20) | (c9<<18)  | (c8<<16)  |	\
											(c7<<14)  | (c6<<12)  | (c5<<10)  | (c4<<8)   |	\
											(c3<<6)   | (c2<<4)   | (c1<<2)   | (c0<<0); \
				GPIO##port##_NS->ODR |=		(f15<<15) | (f14<<14) | (f13<<13) | (f12<<12) |	\
											(f11<<11) | (f10<<10) | (f9<<9)   | (f8<<8)   |	\
											(f7<<7)   | (f6<<6)   | (f5<<5)   | (f4<<4)   |	\
											(f3<<3)   | (f2<<2)   | (f1<<1)   | (f0<<0); \
				GPIO##port##_S->HSLVR |=	(g15<<15) | (g14<<14) | (g13<<13) | (g12<<12) |	\
											(g11<<11) | (g10<<10) | (g9<<9)   | (g8<<8)   |	\
											(g7<<7)   | (g6<<6)   | (g5<<5)   | (g4<<4)   |	\
											(g3<<3)   | (g2<<2)   | (g1<<1)   | (g0<<0);
#endif

// DSI additional definitions
// --------------------------

// With #define, the DSI register structure is replaced

#define	ADDITIONAL_DSI_S

#if (defined(ADDITIONAL_DSI_S))
typedef struct {
	volatile	uint32_t	VR;
	volatile	uint32_t	CR;
	volatile	uint32_t	CCR;
	volatile	uint32_t	LVCIDR;
	volatile	uint32_t	LCOLCR;
	volatile	uint32_t	LPCR;
	volatile	uint32_t	LPMCR;
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	PCR;
	volatile	uint32_t	GVCIDR;
	volatile	uint32_t	MCR;
	volatile	uint32_t	VMCR;
	volatile	uint32_t	VPCR;
	volatile	uint32_t	VCCR;
	volatile	uint32_t	VNPCR;
	volatile	uint32_t	VHSACR;
	volatile	uint32_t	VHBPCR;
	volatile	uint32_t	VLCR;
	volatile	uint32_t	VVSACR;
	volatile	uint32_t	VVBPCR;
	volatile	uint32_t	VVFPCR;
	volatile	uint32_t	VVACR;
	volatile	uint32_t	LCCR;
	volatile	uint32_t	CMCR;
	volatile	uint32_t	GHCR;
	volatile	uint32_t	GPDR;
	volatile	uint32_t	GPSR;
	volatile	uint32_t	TCCR0;
	volatile	uint32_t	TCCR1;
	volatile	uint32_t	TCCR2;
	volatile	uint32_t	TCCR3;
	volatile	uint32_t	TCCR4;
	volatile	uint32_t	TCCR5;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	CLCR;
	volatile	uint32_t	CLTCR;
	volatile	uint32_t	DLTCR;
	volatile	uint32_t	PCTLR;
	volatile	uint32_t	PCONFR;
	volatile	uint32_t	PUCR;
	volatile	uint32_t	PTTCR;
	volatile	uint32_t	PSR;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	ISR0;
	volatile	uint32_t	ISR1;
	volatile	uint32_t	IER0;
	volatile	uint32_t	IER1;
	volatile	uint32_t	RESERVED3[3];
	volatile	uint32_t	FIR0;
	volatile	uint32_t	FIR1;
	volatile	uint32_t	RESERVED4[5];
	volatile	uint32_t	DLTRCR;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	VSCR;
	volatile	uint32_t	RESERVED6[2];
	volatile	uint32_t	LCVCIDR;
	volatile	uint32_t	LCCCR;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	LPMCCR;
	volatile	uint32_t	RESERVED8[7];
	volatile	uint32_t	VMCCR;
	volatile	uint32_t	VPCCR;
	volatile	uint32_t	VCCCR;
	volatile	uint32_t	VNPCCR;
	volatile	uint32_t	VHSACCR;
	volatile	uint32_t	VHBPCCR;
	volatile	uint32_t	VLCCR;
	volatile	uint32_t	VVSACCR;
	volatile	uint32_t	VVBPCCR;
	volatile	uint32_t	VVFPCCR;
	volatile	uint32_t	VVACCR;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	FBSR;
	volatile	uint32_t	RESERVED10[165];
	volatile	uint32_t	WCFGR;
	volatile	uint32_t	WCR;
	volatile	uint32_t	WIER;
	volatile	uint32_t	WISR;
	volatile	uint32_t	WIFCR;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	WPCR0;
	volatile	uint32_t	RESERVED12[5];
	volatile	uint32_t	WRPCR;
	volatile	uint32_t	WPTR;
	volatile	uint32_t	RESERVED13[244];
	volatile	uint32_t	BCFGR;
	volatile	uint32_t	RESERVED14[254];
	volatile	uint32_t	DPCBCR;
	volatile	uint32_t	RESERVED15[11];
	volatile	uint32_t	DPCSRCR;
	volatile	uint32_t	RESERVED16[9];
	volatile	uint32_t	DPDL0HSOCR;
	volatile	uint32_t	DPDL0LPXOCR;
	volatile	uint32_t	RESERVED17[3];
	volatile	uint32_t	DPDL0BCR;
	volatile	uint32_t	RESERVED18[11];
	volatile	uint32_t	DPDL0SRCR;
	volatile	uint32_t	RESERVED19[20];
	volatile	uint32_t	DPDL1HSOCR;
	volatile	uint32_t	DPDL1LPXOCR;
	volatile	uint32_t	RESERVED20[3];
	volatile	uint32_t	DPDL1BCR;
	volatile	uint32_t	RESERVED21[11];
	volatile	uint32_t	DPDL1SRCR;
} DSI_TypeDef;

#define	DSI_NS	((DSI_TypeDef *)0x40016C00u)
#define	DSI_S	((DSI_TypeDef *)0x50016C00u)
#endif

// WRPCR Configuration

#define	DSI_WRPCR_BC			(0x3u<<29)
#define	DSI_WRPCR_BC_0			(0x1u<<29)

// WPTR Configuration

#define	DSI_WPTR_CP				(0xFu<<8)
#define	DSI_WPTR_CP_0			(0x1u<<8)
#define	DSI_WPTR_LPF			(0xFu<<12)
#define	DSI_WPTR_LPF_0			(0x1u<<12)

// DPDL0HSOCR Configuration

#define	DSI_DPDL0HSOCR			(0xFu<<4)
#define	DSI_DPDL0HSOCR_0		(0x1u<<4)

// DPDL0LPXOCR Configuration

#define	DSI_DPDL0LPXOCR			(0xFu<<0)
#define	DDSI_DPDL0LPXOCR_0		(0x1u<<0)

// DSI_DPDL1HSOCR Configuration

#define	DSI_DSI_DPDL1HSOCR		(0xFu<<4)
#define	DDSI_DSI_DPDL1HSOCR_0	(0x1u<<4)

// DSI_DPDL1LPXOCR Configuration

#define	DSI_DSI_DPDL1LPXOCR		(0xFu<<0)
#define	DDSI_DSI_DPDL1LPXOCR_0	(0x1u<<0)

// LTDC additional definitions
// ---------------------------

// With #define, the LTDC register structure is replaced

#define	ADDITIONAL_LTDC_S

#if (defined(ADDITIONAL_LTDC_S))
typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	WHPCR;
	volatile	uint32_t	WVPCR;
	volatile	uint32_t	CKCR;
	volatile	uint32_t	PFCR;
	volatile	uint32_t	CACR;
	volatile	uint32_t	DCCR;
	volatile	uint32_t	BFCR;
	const		uint32_t	RESERVED0[2];
	volatile	uint32_t	CFBAR;
	volatile	uint32_t	CFBLR;
	volatile	uint32_t	CFBLNR;
	const		uint32_t	RESERVED1[3];
	volatile	uint32_t	CLUTWR;
} LTDC_Layer_TypeDef;

typedef struct {
	const		uint32_t	RESERVED0[2];
	volatile	uint32_t	SSCR;
	volatile	uint32_t	BPCR;
	volatile	uint32_t	AWCR;
	volatile	uint32_t	TWCR;
	volatile	uint32_t	GCR;
	const		uint32_t	RESERVED1[2];
	volatile	uint32_t	SRCR;
	const		uint32_t	RESERVED2[1];
	volatile	uint32_t	BCCR;
	const		uint32_t	RESERVED3[1];
	volatile	uint32_t	IER;
	volatile	uint32_t	ISR;
	volatile	uint32_t	ICR;
	volatile	uint32_t	LIPCR;
	volatile	uint32_t	CPSR;
	volatile	uint32_t	CDSR;
	const		uint32_t	RESERVED4[(0x84-0x4c)/4];
	LTDC_Layer_TypeDef		L1;
	const		uint32_t	RESERVED5[(0x104-0xc8)/4];
	LTDC_Layer_TypeDef		L2;
} LTDC_TypeDef;

#define	LTDC_NS			((LTDC_TypeDef *)0x40016800u)
#define	LTDC_S			((LTDC_TypeDef *)0x50016800u)
#define	LTDC_Layer1_NS	((LTDC_Layer_TypeDef *)0x40016884u)
#define	LTDC_Layer1_S	((LTDC_Layer_TypeDef *)0x50016884u)
#define	LTDC_Layer2_NS	((LTDC_Layer_TypeDef *)0x40016904u)
#define	LTDC_Layer2_S	((LTDC_Layer_TypeDef *)0x50016904u)
#endif

// LxCR Configuration

#define	LTDC_LxCR_CLUTEN		LTDC_L1CR_CLUTEN
#define	LTDC_LxCR_COLKEN		LTDC_L1CR_COLKEN
#define	LTDC_LxCR_LEN			LTDC_L1CR_LEN

// LxWHPCR Configuration

#define	LTDC_LxWHPCR_WHSPPOS	LTDC_L1WHPCR_WHSPPOS
#define	LTDC_LxWHPCR_WHSPPOS_0	LTDC_L1WHPCR_WHSPPOS_0
#define	LTDC_LxWHPCR_WHSTPOS	LTDC_L1WHPCR_WHSTPOS
#define	LTDC_LxWHPCR_WHSTPOS_0	LTDC_L1WHPCR_WHSTPOS_0

// LxWVPCR Configuration

#define	LTDC_LxWVPCR_WVSPPOS	LTDC_L1WVPCR_WVSPPOS
#define	LTDC_LxWVPCR_WVSPPOS_0	LTDC_L1WVPCR_WVSPPOS_0
#define	LTDC_LxWVPCR_WVSTPOS	LTDC_L1WVPCR_WVSTPOS
#define	LTDC_LxWVPCR_WVSTPOS_0	LTDC_L1WVPCR_WVSTPOS_0

// LxCKCR Configuration

#define	LTDC_LxCKCR_CKRED		LTDC_L1CKCR_CKRED
#define	LTDC_LxCKCR_CKRED_0		LTDC_L1CKCR_CKRED_0
#define	LTDC_LxCKCR_CKGREEN		LTDC_L1CKCR_CKGREEN
#define	LTDC_LxCKCR_CKGREEN_0	LTDC_L1CKCR_CKGREEN_0
#define	LTDC_LxCKCR_CKBLUE		LTDC_L1CKCR_CKBLUE
#define	LTDC_LxCKCR_CKBLUE_0	LTDC_L1CKCR_CKBLUE_0

// LxPFCR Configuration

#define	LTDC_LxPFCR_PF			LTDC_L1PFCR_PF
#define	LTDC_LxPFCR_PF_0		(0x1u<<0)
#define	LTDC_LxPFCR_PF_1		(0x1u<<1)
#define	LTDC_LxPFCR_PF_2		(0x1u<<2)

enum : uint32_t {
	LTDC_LxPFCR_PF_ARGB8888				= 0,
	LTDC_LxPFCR_PF_RGB888				= LTDC_LxPFCR_PF_0,
	LTDC_LxPFCR_PF_RGB565				= LTDC_LxPFCR_PF_1,
	LTDC_LxPFCR_PF_ARGB1555				= LTDC_LxPFCR_PF_1 | LTDC_LxPFCR_PF_0,
	LTDC_LxPFCR_PF_ARGB4444				= LTDC_LxPFCR_PF_2,
	LTDC_LxPFCR_PF_L8					= LTDC_LxPFCR_PF_2 | LTDC_LxPFCR_PF_0,
	LTDC_LxPFCR_PF_AL44					= LTDC_LxPFCR_PF_2 | LTDC_LxPFCR_PF_1,
	LTDC_LxPFCR_PF_AL88					= LTDC_LxPFCR_PF_2 | LTDC_LxPFCR_PF_1 | LTDC_LxPFCR_PF_0
};

// LxCACR Configuration

#define	LTDC_LxCACR_CONSTA		LTDC_L1CACR_CONSTA
#define	LTDC_LxCACR_CONSTA_0	LTDC_L1CACR_CONSTA_0

// LxDCCR Configuration

#define	LTDC_LxDCCR_DCALPHA		LTDC_L1DCCR_DCALPHA
#define	LTDC_LxDCCR_DCALPHA_0	LTDC_L1DCCR_DCALPHA_0
#define	LTDC_LxDCCR_DCRED		LTDC_L1DCCR_DCRED
#define	LTDC_LxDCCR_DCRED_0		LTDC_L1DCCR_DCRED_0
#define	LTDC_LxDCCR_DCGREEN		LTDC_L1DCCR_DCGREEN
#define	LTDC_LxDCCR_DCGREEN_0	LTDC_L1DCCR_DCGREEN_0
#define	LTDC_LxDCCR_DCBLUE		LTDC_L1DCCR_DCBLUE
#define	LTDC_LxDCCR_DCBLUE_0	LTDC_L1DCCR_DCBLUE_0

// LxBFCR Configuration

#define	LTDC_LxBFCR_BF1			LTDC_L1BFCR_BF1
#define	LTDC_LxBFCR_BF1_0		(0x1u<<8)
#define	LTDC_LxBFCR_BF1_1		(0x1u<<9)
#define	LTDC_LxBFCR_BF1_2		(0x1u<<10)
#define	LTDC_LxBFCR_BF2			LTDC_L1BFCR_BF2
#define	LTDC_LxBFCR_BF2_0		(0x1u<<0)
#define	LTDC_LxBFCR_BF2_1		(0x1u<<1)
#define	LTDC_LxBFCR_BF2_2		(0x1u<<2)

enum : uint32_t {
	LTDC_LxBFCR_BF1_CONSTANT_ALPHA						= LTDC_LxBFCR_BF1_2,
	LTDC_LxBFCR_BF1_PIXEL_PIXEL_ALPHA_CONSTANT_ALPHA	= LTDC_LxBFCR_BF1_2 | LTDC_LxBFCR_BF1_1
};

enum : uint32_t {
	LTDC_LxBFCR_BF2_CONSTANT_ALPHA						= LTDC_LxBFCR_BF2_2 | LTDC_LxBFCR_BF2_0,
	LTDC_LxBFCR_BF2_PIXEL_PIXEL_ALPHA_CONSTANT_ALPHA	= LTDC_LxBFCR_BF2_2 | LTDC_LxBFCR_BF2_1 | LTDC_LxBFCR_BF2_0
};

// LxCFBAR Configuration

#define	LTDC_LxCFBAR_CFBADD		LTDC_L1CFBAR_CFBADD
#define	LTDC_LxCFBAR_CFBADD_0	LTDC_L1CFBAR_CFBADD_0

// LxCFBLR Configuration

#define	LTDC_LxCFBLR_CFBP		LTDC_L1CFBLR_CFBP
#define	LTDC_LxCFBLR_CFBP_0		LTDC_L1CFBLR_CFBP_0
#define	LTDC_LxCFBLR_CFBLL		LTDC_L1CFBLR_CFBLL
#define	LTDC_LxCFBLR_CFBLL_0	LTDC_L1CFBLR_CFBLL_0

// LxCFBLNR Configuration

#define	LTDC_LxCFBLNR_CFBLNBR	LTDC_L1CFBLNR_CFBLNBR
#define	LTDC_LxCFBLNR_CFBLNBR_0	LTDC_L1CFBLNR_CFBLNBR_0

// LxCLUTWR Configuration

#define	LTDC_LxCLUTWR_CLUTADD	LTDC_L1CLUTWR_CLUTADD
#define	LTDC_LxCLUTWR_CLUTADD_0	LTDC_L1CLUTWR_CLUTADD_0
#define	LTDC_LxCLUTWR_RED		LTDC_L1CLUTWR_RED
#define	LTDC_LxCLUTWR_RED_0		LTDC_L1CLUTWR_RED_0
#define	LTDC_LxCLUTWR_GREEN		LTDC_L1CLUTWR_GREEN
#define	LTDC_LxCLUTWR_GREEN_0	LTDC_L1CLUTWR_GREEN_0
#define	LTDC_LxCLUTWR_BLUE		LTDC_L1CLUTWR_BLUE
#define	LTDC_LxCLUTWR_BLUE_0	LTDC_L1CLUTWR_BLUE_0

// RTC additional definitions
// --------------------------

// WPR Configuration (Write Protection Register)

#define	RTC_WPR_UNLOCK_KEY1		0x000000CAu
#define	RTC_WPR_UNLOCK_KEY2		0x00000053u
#define	RTC_WPR_LOCK_KEY		0x000000FFu
