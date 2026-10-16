/*
; stm32U5Gx_otfdec.
; =================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32U5Gx_otfdec equates.
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

// OTFDEC address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	RESERVED0[3];
	volatile	uint32_t	PRIVCFGR;
	volatile	uint32_t	RESERVED1[3];
	volatile	uint32_t	R1CFGR;
	volatile	uint32_t	R1STARTADDR;
	volatile	uint32_t	R1ENDADDR;
	volatile	uint32_t	R1NONCER0;
	volatile	uint32_t	R1NONCER1;
	volatile	uint32_t	R1KEYR0;
	volatile	uint32_t	R1KEYR1;
	volatile	uint32_t	R1KEYR2;
	volatile	uint32_t	R1KEYR3;
	volatile	uint32_t	RESERVED2[3];
	volatile	uint32_t	R2CFGR;
	volatile	uint32_t	R2STARTADDR;
	volatile	uint32_t	R2ENDADDR;
	volatile	uint32_t	R2NONCER0;
	volatile	uint32_t	R2NONCER1;
	volatile	uint32_t	R2KEYR0;
	volatile	uint32_t	R2KEYR1;
	volatile	uint32_t	R2KEYR2;
	volatile	uint32_t	R2KEYR3;
	volatile	uint32_t	RESERVED3[3];
	volatile	uint32_t	R3CFGR;
	volatile	uint32_t	R3STARTADDR;
	volatile	uint32_t	R3ENDADDR;
	volatile	uint32_t	R3NONCER0;
	volatile	uint32_t	R3NONCER1;
	volatile	uint32_t	R3KEYR0;
	volatile	uint32_t	R3KEYR1;
	volatile	uint32_t	R3KEYR2;
	volatile	uint32_t	R3KEYR3;
	volatile	uint32_t	RESERVED4[3];
	volatile	uint32_t	R4CFGR;
	volatile	uint32_t	R4STARTADDR;
	volatile	uint32_t	R4ENDADDR;
	volatile	uint32_t	R4NONCER0;
	volatile	uint32_t	R4NONCER1;
	volatile	uint32_t	R4KEYR0;
	volatile	uint32_t	R4KEYR1;
	volatile	uint32_t	R4KEYR2;
	volatile	uint32_t	R4KEYR3;
	volatile	uint32_t	RESERVED5[139];
	volatile	uint32_t	ISR;
	volatile	uint32_t	ICR;
	volatile	uint32_t	IER;
} OTFDEC_TypeDef;

#if (defined(__cplusplus))
#define	OTFDEC1_NS	reinterpret_cast<OTFDEC_TypeDef *>(0x420C5000u)
#define	OTFDEC1_S	reinterpret_cast<OTFDEC_TypeDef *>(0x520C5000u)
#define	OTFDEC2_NS	reinterpret_cast<OTFDEC_TypeDef *>(0x420C5400u)
#define	OTFDEC2_S	reinterpret_cast<OTFDEC_TypeDef *>(0x520C5400u)

#else
#define	OTFDEC1_NS	((OTFDEC_TypeDef *)0x420C5000u)
#define	OTFDEC1_S	((OTFDEC_TypeDef *)0x520C5000u)
#define	OTFDEC2_NS	((OTFDEC_TypeDef *)0x420C5400u)
#define	OTFDEC2_S	((OTFDEC_TypeDef *)0x520C5400u)
#endif

// CR Configuration

#define	OTFDEC_CR_ENC							(0x1u<<0)

// PRIVCFGR Configuration

#define	OTFDEC_PRIVCFGR_PRIV					(0x1u<<0)

// R1CFGR Configuration

#define	OTFDEC_R1CFGR_REG1_VERSION				(0xFFFFu<<16)
#define	OTFDEC_R1CFGR_REG1_VERSION_0			(0x1u<<16)
#define	OTFDEC_R1CFGR_KEYCRC					(0xFFu<<8)
#define	OTFDEC_R1CFGR_KEYCRC_0					(0x1u<<8)
#define	OTFDEC_R1CFGR_MODE						(0x3u<<4)
#define	OTFDEC_R1CFGR_MODE_0					(0x1u<<4)
#define	OTFDEC_R1CFGR_KEYLOCK					(0x1u<<2)
#define	OTFDEC_R1CFGR_CONFIGLOCK				(0x1u<<1)
#define	OTFDEC_R1CFGR_REG_EN					(0x1u<<0)

// R1STARTADDR Configuration

#define	OTFDEC_R1STARTADDR_REG1_START_ADDR		(0xFFFFFFFFu<<0)
#define	OTFDEC_R1STARTADDR_REG1_START_ADDR_0	(0x1u<<0)

// R1ENDADDR Configuration

#define	OTFDEC_R1ENDADDR_REG1_END_ADDR			(0xFFFFFFFFu<<0)
#define	OTFDEC_R1ENDADDR_REG1_END_ADDR_0		(0x1u<<0)

// R1NONCER0 Configuration

#define	OTFDEC_R1NONCER0_REG1_NONCE				(0xFFFFFFFFu<<0)
#define	OTFDEC_R1NONCER0_REG1_NONCE_0			(0x1u<<0)

// R1NONCER1 Configuration

#define	OTFDEC_R1NONCER1_REG1_NONCE				(0xFFFFFFFFu<<0)
#define	OTFDEC_R1NONCER1_REG1_NONCE_0			(0x1u<<0)

// R1KEYR0 Configuration

#define	OTFDEC_R1KEYR0_REG1_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R1KEYR0_REG1_KEY_0				(0x1u<<0)

// R1KEYR1 Configuration

#define	OTFDEC_R1KEYR1_REG1_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R1KEYR1_REG1_KEY_0				(0x1u<<0)

// R1KEYR2 Configuration

#define	OTFDEC_R1KEYR2_REG1_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R1KEYR2_REG1_KEY_0				(0x1u<<0)

// R1KEYR3 Configuration

#define	OTFDEC_R1KEYR3_REG1_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R1KEYR3_REG1_KEY_0				(0x1u<<0)

// R2CFGR Configuration

#define	OTFDEC_R2CFGR_REG2_VERSION				(0xFFFFu<<16)
#define	OTFDEC_R2CFGR_REG2_VERSION_0			(0x1u<<16)
#define	OTFDEC_R2CFGR_KEYCRC					(0xFFu<<8)
#define	OTFDEC_R2CFGR_KEYCRC_0					(0x1u<<8)
#define	OTFDEC_R2CFGR_MODE						(0x3u<<4)
#define	OTFDEC_R2CFGR_MODE_0					(0x1u<<4)
#define	OTFDEC_R2CFGR_KEYLOCK					(0x1u<<2)
#define	OTFDEC_R2CFGR_CONFIGLOCK				(0x1u<<1)
#define	OTFDEC_R2CFGR_REG_EN					(0x1u<<0)

// R2STARTADDR Configuration

#define	OTFDEC_R2STARTADDR_REG2_START_ADDR		(0xFFFFFFFFu<<0)
#define	OTFDEC_R2STARTADDR_REG2_START_ADDR_0	(0x1u<<0)

// R2ENDADDR Configuration

#define	OTFDEC_R2ENDADDR_REG2_END_ADDR			(0xFFFFFFFFu<<0)
#define	OTFDEC_R2ENDADDR_REG2_END_ADDR_0		(0x1u<<0)

// R2NONCER0 Configuration

#define	OTFDEC_R2NONCER0_REG2_NONCE				(0xFFFFFFFFu<<0)
#define	OTFDEC_R2NONCER0_REG2_NONCE_0			(0x1u<<0)

// R2NONCER1 Configuration

#define	OTFDEC_R2NONCER1_REG2_NONCE				(0xFFFFFFFFu<<0)
#define	OTFDEC_R2NONCER1_REG2_NONCE_0			(0x1u<<0)

// R2KEYR0 Configuration

#define	OTFDEC_R2KEYR0_REG2_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R2KEYR0_REG2_KEY_0				(0x1u<<0)

// R2KEYR1 Configuration

#define	OTFDEC_R2KEYR1_REG2_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R2KEYR1_REG2_KEY_0				(0x1u<<0)

// R2KEYR2 Configuration

#define	OTFDEC_R2KEYR2_REG2_KEY_				(0xFFFFFFFFu<<0)
#define	OTFDEC_R2KEYR2_REG2_KEY__0				(0x1u<<0)

// R2KEYR3 Configuration

#define	OTFDEC_R2KEYR3_REG2_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R2KEYR3_REG2_KEY_0				(0x1u<<0)

// R3CFGR Configuration

#define	OTFDEC_R3CFGR_REG3_VERSION				(0xFFFFu<<16)
#define	OTFDEC_R3CFGR_REG3_VERSION_0			(0x1u<<16)
#define	OTFDEC_R3CFGR_KEYCRC					(0xFFu<<8)
#define	OTFDEC_R3CFGR_KEYCRC_0					(0x1u<<8)
#define	OTFDEC_R3CFGR_MODE						(0x3u<<4)
#define	OTFDEC_R3CFGR_MODE_0					(0x1u<<4)
#define	OTFDEC_R3CFGR_KEYLOCK					(0x1u<<2)
#define	OTFDEC_R3CFGR_CONFIGLOCK				(0x1u<<1)
#define	OTFDEC_R3CFGR_REG_EN					(0x1u<<0)

// R3STARTADDR Configuration

#define	OTFDEC_R3STARTADDR_REG3_START_ADDR		(0xFFFFFFFFu<<0)
#define	OTFDEC_R3STARTADDR_REG3_START_ADDR_0	(0x1u<<0)

// R3ENDADDR Configuration

#define	OTFDEC_R3ENDADDR_REG3_END_ADDR			(0xFFFFFFFFu<<0)
#define	OTFDEC_R3ENDADDR_REG3_END_ADDR_0		(0x1u<<0)

// R3NONCER0 Configuration

#define	OTFDEC_R3NONCER0_REG3_NONCE				(0xFFFFFFFFu<<0)
#define	OTFDEC_R3NONCER0_REG3_NONCE_0			(0x1u<<0)

// R3NONCER1 Configuration

#define	OTFDEC_R3NONCER1_REG3_NONCE				(0xFFFFFFFFu<<0)
#define	OTFDEC_R3NONCER1_REG3_NONCE_0			(0x1u<<0)

// R3KEYR0 Configuration

#define	OTFDEC_R3KEYR0_REG3_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R3KEYR0_REG3_KEY_0				(0x1u<<0)

// R3KEYR1 Configuration

#define	OTFDEC_R3KEYR1_REG3_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R3KEYR1_REG3_KEY_0				(0x1u<<0)

// R3KEYR2 Configuration

#define	OTFDEC_R3KEYR2_REG3_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R3KEYR2_REG3_KEY_0				(0x1u<<0)

// R3KEYR3 Configuration

#define	OTFDEC_R3KEYR3_REG3_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R3KEYR3_REG3_KEY_0				(0x1u<<0)

// R4CFGR Configuration

#define	OTFDEC_R4CFGR_REG4_VERSION				(0xFFFFu<<16)
#define	OTFDEC_R4CFGR_REG4_VERSION_0			(0x1u<<16)
#define	OTFDEC_R4CFGR_KEYCRC					(0xFFu<<8)
#define	OTFDEC_R4CFGR_KEYCRC_0					(0x1u<<8)
#define	OTFDEC_R4CFGR_MODE						(0x3u<<4)
#define	OTFDEC_R4CFGR_MODE_0					(0x1u<<4)
#define	OTFDEC_R4CFGR_KEYLOCK					(0x1u<<2)
#define	OTFDEC_R4CFGR_CONFIGLOCK				(0x1u<<1)
#define	OTFDEC_R4CFGR_REG_EN					(0x1u<<0)

// R4STARTADDR Configuration

#define	OTFDEC_R4STARTADDR_REG4_START_ADDR		(0xFFFFFFFFu<<0)
#define	OTFDEC_R4STARTADDR_REG4_START_ADDR_0	(0x1u<<0)

// R4ENDADDR Configuration

#define	OTFDEC_R4ENDADDR_REG4_END_ADDR			(0xFFFFFFFFu<<0)
#define	OTFDEC_R4ENDADDR_REG4_END_ADDR_0		(0x1u<<0)

// R4NONCER0 Configuration

#define	OTFDEC_R4NONCER0_REG4_NONCE				(0xFFFFFFFFu<<0)
#define	OTFDEC_R4NONCER0_REG4_NONCE_0			(0x1u<<0)

// R4NONCER1 Configuration

#define	OTFDEC_R4NONCER1_REG4_NONCE				(0xFFFFFFFFu<<0)
#define	OTFDEC_R4NONCER1_REG4_NONCE_0			(0x1u<<0)

// R4KEYR0 Configuration

#define	OTFDEC_R4KEYR0_REG4_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R4KEYR0_REG4_KEY_0				(0x1u<<0)

// R4KEYR1 Configuration

#define	OTFDEC_R4KEYR1_REG4_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R4KEYR1_REG4_KEY_0				(0x1u<<0)

// R4KEYR2 Configuration

#define	OTFDEC_R4KEYR2_REG4_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R4KEYR2_REG4_KEY_0				(0x1u<<0)

// R4KEYR3 Configuration

#define	OTFDEC_R4KEYR3_REG4_KEY					(0xFFFFFFFFu<<0)
#define	OTFDEC_R4KEYR3_REG4_KEY_0				(0x1u<<0)

// ISR Configuration

#define	OTFDEC_ISR_KEIF							(0x1u<<2)
#define	OTFDEC_ISR_XONEIF						(0x1u<<1)
#define	OTFDEC_ISR_SEIF							(0x1u<<0)

// ICR Configuration

#define	OTFDEC_ICR_KEIF							(0x1u<<2)
#define	OTFDEC_ICR_XONEIF						(0x1u<<1)
#define	OTFDEC_ICR_SEIF							(0x1u<<0)

// IER Configuration

#define	OTFDEC_IER_KEIE							(0x1u<<2)
#define	OTFDEC_IER_XONEIE						(0x1u<<1)
#define	OTFDEC_IER_SEIE							(0x1u<<0)
