/*
; nrf5340_application_vmc.
; ========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_vmc equates.
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

// VMC address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	RESERVED0[384];
	volatile	uint32_t	RAM0_POWER;
	volatile	uint32_t	RAM0_POWERSET;
	volatile	uint32_t	RAM0_POWERCLR;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	RAM1_POWER;
	volatile	uint32_t	RAM1_POWERSET;
	volatile	uint32_t	RAM1_POWERCLR;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	RAM2_POWER;
	volatile	uint32_t	RAM2_POWERSET;
	volatile	uint32_t	RAM2_POWERCLR;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	RAM3_POWER;
	volatile	uint32_t	RAM3_POWERSET;
	volatile	uint32_t	RAM3_POWERCLR;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	RAM4_POWER;
	volatile	uint32_t	RAM4_POWERSET;
	volatile	uint32_t	RAM4_POWERCLR;
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	RAM5_POWER;
	volatile	uint32_t	RAM5_POWERSET;
	volatile	uint32_t	RAM5_POWERCLR;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	RAM6_POWER;
	volatile	uint32_t	RAM6_POWERSET;
	volatile	uint32_t	RAM6_POWERCLR;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	RAM7_POWER;
	volatile	uint32_t	RAM7_POWERSET;
	volatile	uint32_t	RAM7_POWERCLR;
} VMC_TypeDef;

#if (defined(__cplusplus))
#define	VMC_NS	reinterpret_cast<VMC_TypeDef *>(0x40081000u)
#define	VMC_S	reinterpret_cast<VMC_TypeDef *>(0x50081000u)

#else
#define	VMC_NS	((VMC_TypeDef *)0x40081000u)
#define	VMC_S	((VMC_TypeDef *)0x50081000u)
#endif

// POWER Configuration

#define	VMC_RAM_POWER_S15RETENTION			(0x1u<<31)
#define	VMC_RAM_POWER_S14RETENTION			(0x1u<<30)
#define	VMC_RAM_POWER_S13RETENTION			(0x1u<<29)
#define	VMC_RAM_POWER_S12RETENTION			(0x1u<<28)
#define	VMC_RAM_POWER_S11RETENTION			(0x1u<<27)
#define	VMC_RAM_POWER_S10RETENTION			(0x1u<<26)
#define	VMC_RAM_POWER_S9RETENTION			(0x1u<<25)
#define	VMC_RAM_POWER_S8RETENTION			(0x1u<<24)
#define	VMC_RAM_POWER_S7RETENTION			(0x1u<<23)
#define	VMC_RAM_POWER_S6RETENTION			(0x1u<<22)
#define	VMC_RAM_POWER_S5RETENTION			(0x1u<<21)
#define	VMC_RAM_POWER_S4RETENTION			(0x1u<<20)
#define	VMC_RAM_POWER_S3RETENTION			(0x1u<<19)
#define	VMC_RAM_POWER_S2RETENTION			(0x1u<<18)
#define	VMC_RAM_POWER_S1RETENTION			(0x1u<<17)
#define	VMC_RAM_POWER_S0RETENTION			(0x1u<<16)
#define	VMC_RAM_POWER_S15POWER				(0x1u<<15)
#define	VMC_RAM_POWER_S14POWER				(0x1u<<14)
#define	VMC_RAM_POWER_S13POWER				(0x1u<<13)
#define	VMC_RAM_POWER_S12POWER				(0x1u<<12)
#define	VMC_RAM_POWER_S11POWER				(0x1u<<11)
#define	VMC_RAM_POWER_S10POWER				(0x1u<<10)
#define	VMC_RAM_POWER_S9POWER				(0x1u<<9)
#define	VMC_RAM_POWER_S8POWER				(0x1u<<8)
#define	VMC_RAM_POWER_S7POWER				(0x1u<<7)
#define	VMC_RAM_POWER_S6POWER				(0x1u<<6)
#define	VMC_RAM_POWER_S5POWER				(0x1u<<5)
#define	VMC_RAM_POWER_S4POWER				(0x1u<<4)
#define	VMC_RAM_POWER_S3POWER				(0x1u<<3)
#define	VMC_RAM_POWER_S2POWER				(0x1u<<2)
#define	VMC_RAM_POWER_S1POWER				(0x1u<<1)
#define	VMC_RAM_POWER_S0POWER				(0x1u<<0)
#define	VMC_RAM_POWER_S15RETENTION_OFF		(0x0u<<31)
#define	VMC_RAM_POWER_S15RETENTION_ON		(0x1u<<31)
#define	VMC_RAM_POWER_S14RETENTION_OFF		(0x0u<<30)
#define	VMC_RAM_POWER_S14RETENTION_ON		(0x1u<<30)
#define	VMC_RAM_POWER_S13RETENTION_OFF		(0x0u<<29)
#define	VMC_RAM_POWER_S13RETENTION_ON		(0x1u<<29)
#define	VMC_RAM_POWER_S12RETENTION_OFF		(0x0u<<28)
#define	VMC_RAM_POWER_S12RETENTION_ON		(0x1u<<28)
#define	VMC_RAM_POWER_S11RETENTION_OFF		(0x0u<<27)
#define	VMC_RAM_POWER_S11RETENTION_ON		(0x1u<<27)
#define	VMC_RAM_POWER_S10RETENTION_OFF		(0x0u<<26)
#define	VMC_RAM_POWER_S10RETENTION_ON		(0x1u<<26)
#define	VMC_RAM_POWER_S9RETENTION_OFF		(0x0u<<25)
#define	VMC_RAM_POWER_S9RETENTION_ON		(0x1u<<25)
#define	VMC_RAM_POWER_S8RETENTION_OFF		(0x0u<<24)
#define	VMC_RAM_POWER_S8RETENTION_ON		(0x1u<<24)
#define	VMC_RAM_POWER_S7RETENTION_OFF		(0x0u<<23)
#define	VMC_RAM_POWER_S7RETENTION_ON		(0x1u<<23)
#define	VMC_RAM_POWER_S6RETENTION_OFF		(0x0u<<22)
#define	VMC_RAM_POWER_S6RETENTION_ON		(0x1u<<22)
#define	VMC_RAM_POWER_S5RETENTION_OFF		(0x0u<<21)
#define	VMC_RAM_POWER_S5RETENTION_ON		(0x1u<<21)
#define	VMC_RAM_POWER_S4RETENTION_OFF		(0x0u<<20)
#define	VMC_RAM_POWER_S4RETENTION_ON		(0x1u<<20)
#define	VMC_RAM_POWER_S3RETENTION_OFF		(0x0u<<19)
#define	VMC_RAM_POWER_S3RETENTION_ON		(0x1u<<19)
#define	VMC_RAM_POWER_S2RETENTION_OFF		(0x0u<<18)
#define	VMC_RAM_POWER_S2RETENTION_ON		(0x1u<<18)
#define	VMC_RAM_POWER_S1RETENTION_OFF		(0x0u<<17)
#define	VMC_RAM_POWER_S1RETENTION_ON		(0x1u<<17)
#define	VMC_RAM_POWER_S0RETENTION_OFF		(0x0u<<16)
#define	VMC_RAM_POWER_S0RETENTION_ON		(0x1u<<16)
#define	VMC_RAM_POWER_S15POWER_OFF			(0x0u<<15)
#define	VMC_RAM_POWER_S15POWER_ON			(0x1u<<15)
#define	VMC_RAM_POWER_S14POWER_OFF			(0x0u<<14)
#define	VMC_RAM_POWER_S14POWER_ON			(0x1u<<14)
#define	VMC_RAM_POWER_S13POWER_OFF			(0x0u<<13)
#define	VMC_RAM_POWER_S13POWER_ON			(0x1u<<13)
#define	VMC_RAM_POWER_S12POWER_OFF			(0x0u<<12)
#define	VMC_RAM_POWER_S12POWER_ON			(0x1u<<12)
#define	VMC_RAM_POWER_S11POWER_OFF			(0x0u<<11)
#define	VMC_RAM_POWER_S11POWER_ON			(0x1u<<11)
#define	VMC_RAM_POWER_S10POWER_OFF			(0x0u<<10)
#define	VMC_RAM_POWER_S10POWER_ON			(0x1u<<10)
#define	VMC_RAM_POWER_S9POWER_OFF			(0x0u<<9)
#define	VMC_RAM_POWER_S9POWER_ON			(0x1u<<9)
#define	VMC_RAM_POWER_S8POWER_OFF			(0x0u<<8)
#define	VMC_RAM_POWER_S8POWER_ON			(0x1u<<8)
#define	VMC_RAM_POWER_S7POWER_OFF			(0x0u<<7)
#define	VMC_RAM_POWER_S7POWER_ON			(0x1u<<7)
#define	VMC_RAM_POWER_S6POWER_OFF			(0x0u<<6)
#define	VMC_RAM_POWER_S6POWER_ON			(0x1u<<6)
#define	VMC_RAM_POWER_S5POWER_OFF			(0x0u<<5)
#define	VMC_RAM_POWER_S5POWER_ON			(0x1u<<5)
#define	VMC_RAM_POWER_S4POWER_OFF			(0x0u<<4)
#define	VMC_RAM_POWER_S4POWER_ON			(0x1u<<4)
#define	VMC_RAM_POWER_S3POWER_OFF			(0x0u<<3)
#define	VMC_RAM_POWER_S3POWER_ON			(0x1u<<3)
#define	VMC_RAM_POWER_S2POWER_OFF			(0x0u<<2)
#define	VMC_RAM_POWER_S2POWER_ON			(0x1u<<2)
#define	VMC_RAM_POWER_S1POWER_OFF			(0x0u<<1)
#define	VMC_RAM_POWER_S1POWER_ON			(0x1u<<1)
#define	VMC_RAM_POWER_S0POWER_OFF			(0x0u<<0)
#define	VMC_RAM_POWER_S0POWER_ON			(0x1u<<0)

// POWERSET Configuration

#define	VMC_RAM_POWERSET_S15RETENTION		(0x1u<<31)
#define	VMC_RAM_POWERSET_S14RETENTION		(0x1u<<30)
#define	VMC_RAM_POWERSET_S13RETENTION		(0x1u<<29)
#define	VMC_RAM_POWERSET_S12RETENTION		(0x1u<<28)
#define	VMC_RAM_POWERSET_S11RETENTION		(0x1u<<27)
#define	VMC_RAM_POWERSET_S10RETENTION		(0x1u<<26)
#define	VMC_RAM_POWERSET_S9RETENTION		(0x1u<<25)
#define	VMC_RAM_POWERSET_S8RETENTION		(0x1u<<24)
#define	VMC_RAM_POWERSET_S7RETENTION		(0x1u<<23)
#define	VMC_RAM_POWERSET_S6RETENTION		(0x1u<<22)
#define	VMC_RAM_POWERSET_S5RETENTION		(0x1u<<21)
#define	VMC_RAM_POWERSET_S4RETENTION		(0x1u<<20)
#define	VMC_RAM_POWERSET_S3RETENTION		(0x1u<<19)
#define	VMC_RAM_POWERSET_S2RETENTION		(0x1u<<18)
#define	VMC_RAM_POWERSET_S1RETENTION		(0x1u<<17)
#define	VMC_RAM_POWERSET_S0RETENTION		(0x1u<<16)
#define	VMC_RAM_POWERSET_S15POWER			(0x1u<<15)
#define	VMC_RAM_POWERSET_S14POWER			(0x1u<<14)
#define	VMC_RAM_POWERSET_S13POWER			(0x1u<<13)
#define	VMC_RAM_POWERSET_S12POWER			(0x1u<<12)
#define	VMC_RAM_POWERSET_S11POWER			(0x1u<<11)
#define	VMC_RAM_POWERSET_S10POWER			(0x1u<<10)
#define	VMC_RAM_POWERSET_S9POWER			(0x1u<<9)
#define	VMC_RAM_POWERSET_S8POWER			(0x1u<<8)
#define	VMC_RAM_POWERSET_S7POWER			(0x1u<<7)
#define	VMC_RAM_POWERSET_S6POWER			(0x1u<<6)
#define	VMC_RAM_POWERSET_S5POWER			(0x1u<<5)
#define	VMC_RAM_POWERSET_S4POWER			(0x1u<<4)
#define	VMC_RAM_POWERSET_S3POWER			(0x1u<<3)
#define	VMC_RAM_POWERSET_S2POWER			(0x1u<<2)
#define	VMC_RAM_POWERSET_S1POWER			(0x1u<<1)
#define	VMC_RAM_POWERSET_S0POWER			(0x1u<<0)
#define	VMC_RAM_POWERSET_S15RETENTION_ON	(0x1u<<31)
#define	VMC_RAM_POWERSET_S14RETENTION_ON	(0x1u<<30)
#define	VMC_RAM_POWERSET_S13RETENTION_ON	(0x1u<<29)
#define	VMC_RAM_POWERSET_S12RETENTION_ON	(0x1u<<28)
#define	VMC_RAM_POWERSET_S11RETENTION_ON	(0x1u<<27)
#define	VMC_RAM_POWERSET_S10RETENTION_ON	(0x1u<<26)
#define	VMC_RAM_POWERSET_S9RETENTION_ON		(0x1u<<25)
#define	VMC_RAM_POWERSET_S8RETENTION_ON		(0x1u<<24)
#define	VMC_RAM_POWERSET_S7RETENTION_ON		(0x1u<<23)
#define	VMC_RAM_POWERSET_S6RETENTION_ON		(0x1u<<22)
#define	VMC_RAM_POWERSET_S5RETENTION_ON		(0x1u<<21)
#define	VMC_RAM_POWERSET_S4RETENTION_ON		(0x1u<<20)
#define	VMC_RAM_POWERSET_S3RETENTION_ON		(0x1u<<19)
#define	VMC_RAM_POWERSET_S2RETENTION_ON		(0x1u<<18)
#define	VMC_RAM_POWERSET_S1RETENTION_ON		(0x1u<<17)
#define	VMC_RAM_POWERSET_S0RETENTION_ON		(0x1u<<16)
#define	VMC_RAM_POWERSET_S15POWER_ON		(0x1u<<15)
#define	VMC_RAM_POWERSET_S14POWER_ON		(0x1u<<14)
#define	VMC_RAM_POWERSET_S13POWER_ON		(0x1u<<13)
#define	VMC_RAM_POWERSET_S12POWER_ON		(0x1u<<12)
#define	VMC_RAM_POWERSET_S11POWER_ON		(0x1u<<11)
#define	VMC_RAM_POWERSET_S10POWER_ON		(0x1u<<10)
#define	VMC_RAM_POWERSET_S9POWER_ON			(0x1u<<9)
#define	VMC_RAM_POWERSET_S8POWER_ON			(0x1u<<8)
#define	VMC_RAM_POWERSET_S7POWER_ON			(0x1u<<7)
#define	VMC_RAM_POWERSET_S6POWER_ON			(0x1u<<6)
#define	VMC_RAM_POWERSET_S5POWER_ON			(0x1u<<5)
#define	VMC_RAM_POWERSET_S4POWER_ON			(0x1u<<4)
#define	VMC_RAM_POWERSET_S3POWER_ON			(0x1u<<3)
#define	VMC_RAM_POWERSET_S2POWER_ON			(0x1u<<2)
#define	VMC_RAM_POWERSET_S1POWER_ON			(0x1u<<1)
#define	VMC_RAM_POWERSET_S0POWER_ON			(0x1u<<0)

// POWERCLR Configuration

#define	VMC_RAM_POWERCLR_S15RETENTION		(0x1u<<31)
#define	VMC_RAM_POWERCLR_S14RETENTION		(0x1u<<30)
#define	VMC_RAM_POWERCLR_S13RETENTION		(0x1u<<29)
#define	VMC_RAM_POWERCLR_S12RETENTION		(0x1u<<28)
#define	VMC_RAM_POWERCLR_S11RETENTION		(0x1u<<27)
#define	VMC_RAM_POWERCLR_S10RETENTION		(0x1u<<26)
#define	VMC_RAM_POWERCLR_S9RETENTION		(0x1u<<25)
#define	VMC_RAM_POWERCLR_S8RETENTION		(0x1u<<24)
#define	VMC_RAM_POWERCLR_S7RETENTION		(0x1u<<23)
#define	VMC_RAM_POWERCLR_S6RETENTION		(0x1u<<22)
#define	VMC_RAM_POWERCLR_S5RETENTION		(0x1u<<21)
#define	VMC_RAM_POWERCLR_S4RETENTION		(0x1u<<20)
#define	VMC_RAM_POWERCLR_S3RETENTION		(0x1u<<19)
#define	VMC_RAM_POWERCLR_S2RETENTION		(0x1u<<18)
#define	VMC_RAM_POWERCLR_S1RETENTION		(0x1u<<17)
#define	VMC_RAM_POWERCLR_S0RETENTION		(0x1u<<16)
#define	VMC_RAM_POWERCLR_S15POWER			(0x1u<<15)
#define	VMC_RAM_POWERCLR_S14POWER			(0x1u<<14)
#define	VMC_RAM_POWERCLR_S13POWER			(0x1u<<13)
#define	VMC_RAM_POWERCLR_S12POWER			(0x1u<<12)
#define	VMC_RAM_POWERCLR_S11POWER			(0x1u<<11)
#define	VMC_RAM_POWERCLR_S10POWER			(0x1u<<10)
#define	VMC_RAM_POWERCLR_S9POWER			(0x1u<<9)
#define	VMC_RAM_POWERCLR_S8POWER			(0x1u<<8)
#define	VMC_RAM_POWERCLR_S7POWER			(0x1u<<7)
#define	VMC_RAM_POWERCLR_S6POWER			(0x1u<<6)
#define	VMC_RAM_POWERCLR_S5POWER			(0x1u<<5)
#define	VMC_RAM_POWERCLR_S4POWER			(0x1u<<4)
#define	VMC_RAM_POWERCLR_S3POWER			(0x1u<<3)
#define	VMC_RAM_POWERCLR_S2POWER			(0x1u<<2)
#define	VMC_RAM_POWERCLR_S1POWER			(0x1u<<1)
#define	VMC_RAM_POWERCLR_S0POWER			(0x1u<<0)
#define	VMC_RAM_POWERCLR_S15RETENTION_OFF	(0x1u<<31)
#define	VMC_RAM_POWERCLR_S14RETENTION_OFF	(0x1u<<30)
#define	VMC_RAM_POWERCLR_S13RETENTION_OFF	(0x1u<<29)
#define	VMC_RAM_POWERCLR_S12RETENTION_OFF	(0x1u<<28)
#define	VMC_RAM_POWERCLR_S11RETENTION_OFF	(0x1u<<27)
#define	VMC_RAM_POWERCLR_S10RETENTION_OFF	(0x1u<<26)
#define	VMC_RAM_POWERCLR_S9RETENTION_OFF	(0x1u<<25)
#define	VMC_RAM_POWERCLR_S8RETENTION_OFF	(0x1u<<24)
#define	VMC_RAM_POWERCLR_S7RETENTION_OFF	(0x1u<<23)
#define	VMC_RAM_POWERCLR_S6RETENTION_OFF	(0x1u<<22)
#define	VMC_RAM_POWERCLR_S5RETENTION_OFF	(0x1u<<21)
#define	VMC_RAM_POWERCLR_S4RETENTION_OFF	(0x1u<<20)
#define	VMC_RAM_POWERCLR_S3RETENTION_OFF	(0x1u<<19)
#define	VMC_RAM_POWERCLR_S2RETENTION_OFF	(0x1u<<18)
#define	VMC_RAM_POWERCLR_S1RETENTION_OFF	(0x1u<<17)
#define	VMC_RAM_POWERCLR_S0RETENTION_OFF	(0x1u<<16)
#define	VMC_RAM_POWERCLR_S15POWER_OFF		(0x1u<<15)
#define	VMC_RAM_POWERCLR_S14POWER_OFF		(0x1u<<14)
#define	VMC_RAM_POWERCLR_S13POWER_OFF		(0x1u<<13)
#define	VMC_RAM_POWERCLR_S12POWER_OFF		(0x1u<<12)
#define	VMC_RAM_POWERCLR_S11POWER_OFF		(0x1u<<11)
#define	VMC_RAM_POWERCLR_S10POWER_OFF		(0x1u<<10)
#define	VMC_RAM_POWERCLR_S9POWER_OFF		(0x1u<<9)
#define	VMC_RAM_POWERCLR_S8POWER_OFF		(0x1u<<8)
#define	VMC_RAM_POWERCLR_S7POWER_OFF		(0x1u<<7)
#define	VMC_RAM_POWERCLR_S6POWER_OFF		(0x1u<<6)
#define	VMC_RAM_POWERCLR_S5POWER_OFF		(0x1u<<5)
#define	VMC_RAM_POWERCLR_S4POWER_OFF		(0x1u<<4)
#define	VMC_RAM_POWERCLR_S3POWER_OFF		(0x1u<<3)
#define	VMC_RAM_POWERCLR_S2POWER_OFF		(0x1u<<2)
#define	VMC_RAM_POWERCLR_S1POWER_OFF		(0x1u<<1)
#define	VMC_RAM_POWERCLR_S0POWER_OFF		(0x1u<<0)
