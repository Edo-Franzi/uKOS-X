/*
; nrf5340_network_vmc.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_network_vmc equates.
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
} VMC_TypeDef;

#if (defined(__cplusplus))
#define	VMC_NS	reinterpret_cast<VMC_TypeDef *>(0x41081000u)

#else
#define	VMC_NS	((VMC_TypeDef *)0x41081000u)
#endif

// POWER Configuration

#define	VMC_RAM_POWER_S3RETENTION			(0x1u<<19)
#define	VMC_RAM_POWER_S2RETENTION			(0x1u<<18)
#define	VMC_RAM_POWER_S1RETENTION			(0x1u<<17)
#define	VMC_RAM_POWER_S0RETENTION			(0x1u<<16)
#define	VMC_RAM_POWER_S3POWER				(0x1u<<3)
#define	VMC_RAM_POWER_S2POWER				(0x1u<<2)
#define	VMC_RAM_POWER_S1POWER				(0x1u<<1)
#define	VMC_RAM_POWER_S0POWER				(0x1u<<0)
#define	VMC_RAM_POWER_S3RETENTION_OFF		(0x0u<<19)
#define	VMC_RAM_POWER_S3RETENTION_ON		(0x1u<<19)
#define	VMC_RAM_POWER_S2RETENTION_OFF		(0x0u<<18)
#define	VMC_RAM_POWER_S2RETENTION_ON		(0x1u<<18)
#define	VMC_RAM_POWER_S1RETENTION_OFF		(0x0u<<17)
#define	VMC_RAM_POWER_S1RETENTION_ON		(0x1u<<17)
#define	VMC_RAM_POWER_S0RETENTION_OFF		(0x0u<<16)
#define	VMC_RAM_POWER_S0RETENTION_ON		(0x1u<<16)
#define	VMC_RAM_POWER_S3POWER_OFF			(0x0u<<3)
#define	VMC_RAM_POWER_S3POWER_ON			(0x1u<<3)
#define	VMC_RAM_POWER_S2POWER_OFF			(0x0u<<2)
#define	VMC_RAM_POWER_S2POWER_ON			(0x1u<<2)
#define	VMC_RAM_POWER_S1POWER_OFF			(0x0u<<1)
#define	VMC_RAM_POWER_S1POWER_ON			(0x1u<<1)
#define	VMC_RAM_POWER_S0POWER_OFF			(0x0u<<0)
#define	VMC_RAM_POWER_S0POWER_ON			(0x1u<<0)

// POWERSET Configuration

#define	VMC_RAM_POWERSET_S3RETENTION		(0x1u<<19)
#define	VMC_RAM_POWERSET_S2RETENTION		(0x1u<<18)
#define	VMC_RAM_POWERSET_S1RETENTION		(0x1u<<17)
#define	VMC_RAM_POWERSET_S0RETENTION		(0x1u<<16)
#define	VMC_RAM_POWERSET_S3POWER			(0x1u<<3)
#define	VMC_RAM_POWERSET_S2POWER			(0x1u<<2)
#define	VMC_RAM_POWERSET_S1POWER			(0x1u<<1)
#define	VMC_RAM_POWERSET_S0POWER			(0x1u<<0)
#define	VMC_RAM_POWERSET_S3RETENTION_ON		(0x1u<<19)
#define	VMC_RAM_POWERSET_S2RETENTION_ON		(0x1u<<18)
#define	VMC_RAM_POWERSET_S1RETENTION_ON		(0x1u<<17)
#define	VMC_RAM_POWERSET_S0RETENTION_ON		(0x1u<<16)
#define	VMC_RAM_POWERSET_S3POWER_ON			(0x1u<<3)
#define	VMC_RAM_POWERSET_S2POWER_ON			(0x1u<<2)
#define	VMC_RAM_POWERSET_S1POWER_ON			(0x1u<<1)
#define	VMC_RAM_POWERSET_S0POWER_ON			(0x1u<<0)

// POWERCLR Configuration

#define	VMC_RAM_POWERCLR_S3RETENTION		(0x1u<<19)
#define	VMC_RAM_POWERCLR_S2RETENTION		(0x1u<<18)
#define	VMC_RAM_POWERCLR_S1RETENTION		(0x1u<<17)
#define	VMC_RAM_POWERCLR_S0RETENTION		(0x1u<<16)
#define	VMC_RAM_POWERCLR_S3POWER			(0x1u<<3)
#define	VMC_RAM_POWERCLR_S2POWER			(0x1u<<2)
#define	VMC_RAM_POWERCLR_S1POWER			(0x1u<<1)
#define	VMC_RAM_POWERCLR_S0POWER			(0x1u<<0)
#define	VMC_RAM_POWERCLR_S3RETENTION_OFF	(0x1u<<19)
#define	VMC_RAM_POWERCLR_S2RETENTION_OFF	(0x1u<<18)
#define	VMC_RAM_POWERCLR_S1RETENTION_OFF	(0x1u<<17)
#define	VMC_RAM_POWERCLR_S0RETENTION_OFF	(0x1u<<16)
#define	VMC_RAM_POWERCLR_S3POWER_OFF		(0x1u<<3)
#define	VMC_RAM_POWERCLR_S2POWER_OFF		(0x1u<<2)
#define	VMC_RAM_POWERCLR_S1POWER_OFF		(0x1u<<1)
#define	VMC_RAM_POWERCLR_S0POWER_OFF		(0x1u<<0)
