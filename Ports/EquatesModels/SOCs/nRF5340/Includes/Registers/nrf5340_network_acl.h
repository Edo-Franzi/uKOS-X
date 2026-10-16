/*
; nrf5340_network_acl.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_network_acl equates.
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

// ACL address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	RESERVED0[512];
	volatile	uint32_t	ACL0_ADDR;
	volatile	uint32_t	ACL0_SIZE;
	volatile	uint32_t	ACL0_PERM;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	ACL1_ADDR;
	volatile	uint32_t	ACL1_SIZE;
	volatile	uint32_t	ACL1_PERM;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	ACL2_ADDR;
	volatile	uint32_t	ACL2_SIZE;
	volatile	uint32_t	ACL2_PERM;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	ACL3_ADDR;
	volatile	uint32_t	ACL3_SIZE;
	volatile	uint32_t	ACL3_PERM;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	ACL4_ADDR;
	volatile	uint32_t	ACL4_SIZE;
	volatile	uint32_t	ACL4_PERM;
	volatile	uint32_t	RESERVED5;
	volatile	uint32_t	ACL5_ADDR;
	volatile	uint32_t	ACL5_SIZE;
	volatile	uint32_t	ACL5_PERM;
	volatile	uint32_t	RESERVED6;
	volatile	uint32_t	ACL6_ADDR;
	volatile	uint32_t	ACL6_SIZE;
	volatile	uint32_t	ACL6_PERM;
	volatile	uint32_t	RESERVED7;
	volatile	uint32_t	ACL7_ADDR;
	volatile	uint32_t	ACL7_SIZE;
	volatile	uint32_t	ACL7_PERM;
} ACL_TypeDef;

#if (defined(__cplusplus))
#define	ACL_NS	reinterpret_cast<ACL_TypeDef *>(0x41080000u)

#else
#define	ACL_NS	((ACL_TypeDef *)0x41080000u)
#endif

// ADDR Configuration

#define	ACL_ACL_ADDR_ADDR			(0xFFFFFFFFu<<0)
#define	ACL_ACL_ADDR_ADDR_0			(0x1u<<0)

// SIZE Configuration

#define	ACL_ACL_SIZE_SIZE			(0xFFFFFFFFu<<0)
#define	ACL_ACL_SIZE_SIZE_0			(0x1u<<0)

// PERM Configuration

#define	ACL_ACL_PERM_READ			(0x1u<<2)
#define	ACL_ACL_PERM_WRITE			(0x1u<<1)
#define	ACL_ACL_PERM_READ_ENABLE	(0x0u<<2)
#define	ACL_ACL_PERM_READ_DISABLE	(0x1u<<2)
#define	ACL_ACL_PERM_WRITE_ENABLE	(0x0u<<1)
#define	ACL_ACL_PERM_WRITE_DISABLE	(0x1u<<1)
