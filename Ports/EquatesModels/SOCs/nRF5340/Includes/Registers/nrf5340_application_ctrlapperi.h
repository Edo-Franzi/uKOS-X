/*
; nrf5340_application_ctrlapperi.
; ===============================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_ctrlapperi equates.
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

// CTRLAPPERI address definitions
// ------------------------------

typedef struct {
	volatile	uint32_t	RESERVED0[256];
	volatile	uint32_t	MAILBOX_RXDATA;
	volatile	uint32_t	MAILBOX_RXSTATUS;
	volatile	uint32_t	RESERVED1[30];
	volatile	uint32_t	MAILBOX_TXDATA;
	volatile	uint32_t	MAILBOX_TXSTATUS;
	volatile	uint32_t	RESERVED2[30];
	volatile	uint32_t	ERASEPROTECT_LOCK;
	volatile	uint32_t	ERASEPROTECT_DISABLE;
	volatile	uint32_t	RESERVED3[14];
	volatile	uint32_t	APPROTECT_LOCK;
	volatile	uint32_t	APPROTECT_DISABLE;
	volatile	uint32_t	SECUREAPPROTECT_LOCK;
	volatile	uint32_t	SECUREAPPROTECT_DISABLE;
	volatile	uint32_t	RESERVED4[44];
	volatile	uint32_t	STATUS;
} CTRLAPPERI_TypeDef;

#if (defined(__cplusplus))
#define	CTRLAP_NS	reinterpret_cast<CTRLAPPERI_TypeDef *>(0x40006000u)
#define	CTRLAP_S	reinterpret_cast<CTRLAPPERI_TypeDef *>(0x50006000u)

#else
#define	CTRLAP_NS	((CTRLAPPERI_TypeDef *)0x40006000u)
#define	CTRLAP_S	((CTRLAPPERI_TypeDef *)0x50006000u)
#endif

// RXDATA Configuration

#define	CTRLAPPERI_MAILBOX_RXDATA_RXDATA						(0xFFFFFFFFu<<0)
#define	CTRLAPPERI_MAILBOX_RXDATA_RXDATA_0						(0x1u<<0)

// RXSTATUS Configuration

#define	CTRLAPPERI_MAILBOX_RXSTATUS_RXSTATUS					(0x1u<<0)
#define	CTRLAPPERI_MAILBOX_RXSTATUS_RXSTATUS_NODATAPENDING		(0x0u<<0)
#define	CTRLAPPERI_MAILBOX_RXSTATUS_RXSTATUS_DATAPENDING		(0x1u<<0)

// TXDATA Configuration

#define	CTRLAPPERI_MAILBOX_TXDATA_TXDATA						(0xFFFFFFFFu<<0)
#define	CTRLAPPERI_MAILBOX_TXDATA_TXDATA_0						(0x1u<<0)

// TXSTATUS Configuration

#define	CTRLAPPERI_MAILBOX_TXSTATUS_TXSTATUS					(0x1u<<0)
#define	CTRLAPPERI_MAILBOX_TXSTATUS_TXSTATUS_NODATAPENDING		(0x0u<<0)
#define	CTRLAPPERI_MAILBOX_TXSTATUS_TXSTATUS_DATAPENDING		(0x1u<<0)

// LOCK Configuration

#define	CTRLAPPERI_ERASEPROTECT_LOCK_LOCK						(0x1u<<0)
#define	CTRLAPPERI_ERASEPROTECT_LOCK_LOCK_UNLOCKED				(0x0u<<0)
#define	CTRLAPPERI_ERASEPROTECT_LOCK_LOCK_LOCKED				(0x1u<<0)

// DISABLE Configuration

#define	CTRLAPPERI_ERASEPROTECT_DISABLE_KEY						(0xFFFFFFFFu<<0)
#define	CTRLAPPERI_ERASEPROTECT_DISABLE_KEY_0					(0x1u<<0)

// LOCK Configuration

#define	CTRLAPPERI_APPROTECT_LOCK_LOCK							(0x1u<<0)
#define	CTRLAPPERI_APPROTECT_LOCK_LOCK_UNLOCKED					(0x0u<<0)
#define	CTRLAPPERI_APPROTECT_LOCK_LOCK_LOCKED					(0x1u<<0)

// DISABLE Configuration

#define	CTRLAPPERI_APPROTECT_DISABLE_KEY						(0xFFFFFFFFu<<0)
#define	CTRLAPPERI_APPROTECT_DISABLE_KEY_0						(0x1u<<0)

// LOCK Configuration

#define	CTRLAPPERI_SECUREAPPROTECT_LOCK_LOCK					(0x1u<<0)
#define	CTRLAPPERI_SECUREAPPROTECT_LOCK_LOCK_UNLOCKED			(0x0u<<0)
#define	CTRLAPPERI_SECUREAPPROTECT_LOCK_LOCK_LOCKED				(0x1u<<0)

// DISABLE Configuration

#define	CTRLAPPERI_SECUREAPPROTECT_DISABLE_KEY					(0xFFFFFFFFu<<0)
#define	CTRLAPPERI_SECUREAPPROTECT_DISABLE_KEY_0				(0x1u<<0)

// STATUS Configuration

#define	CTRLAPPERI_STATUS_DBGIFACEMODE							(0x1u<<2)
#define	CTRLAPPERI_STATUS_UICRSECUREAPPROTECT					(0x1u<<1)
#define	CTRLAPPERI_STATUS_UICRAPPROTECT							(0x1u<<0)
#define	CTRLAPPERI_STATUS_DBGIFACEMODE_DISABLED					(0x0u<<2)
#define	CTRLAPPERI_STATUS_DBGIFACEMODE_ENABLED					(0x1u<<2)
#define	CTRLAPPERI_STATUS_UICRSECUREAPPROTECT_ENABLED			(0x0u<<1)
#define	CTRLAPPERI_STATUS_UICRSECUREAPPROTECT_DISABLED			(0x1u<<1)
#define	CTRLAPPERI_STATUS_UICRAPPROTECT_ENABLED					(0x0u<<0)
#define	CTRLAPPERI_STATUS_UICRAPPROTECT_DISABLED				(0x1u<<0)
