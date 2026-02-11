/*
; nvic.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		NVIC equates.
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

// NVIC address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	ISER[16];
	volatile	uint32_t	RESERVED0[16];
	volatile	uint32_t	ICER[16];
	volatile	uint32_t	RSERVED1[16];
	volatile	uint32_t	ISPR[16];
	volatile	uint32_t	RESERVED2[16];
	volatile	uint32_t	ICPR[16];
	volatile	uint32_t	RESERVED3[16];
	volatile	uint32_t	IABR[16];
	volatile	uint32_t	RESERVED4[16];
	volatile	uint32_t	ITNS[16];
	volatile	uint32_t	RESERVED5[16];
	volatile	uint8_t		IP[496];
	volatile	uint32_t	RESERVED6[580];
	volatile	uint32_t	STIR;
} NVIC_TypeDef;

#if (defined(__cplusplus))
#define	NVIC_S	reinterpret_cast<NVIC_TypeDef *>(0xE000E100u)
#define	NVIC_NS	reinterpret_cast<NVIC_TypeDef *>(0xE002E100u)

#else
#define	NVIC_S	((NVIC_TypeDef *)0xE000E100u)
#define	NVIC_NS	((NVIC_TypeDef *)0xE002E100u)
#endif

// System Reset

#define NVIC_VECTRESET				0u
#define NVIC_SYSRESETREQ			2u
#define NVIC_AIRCR_VECTKEY			(0x5FAu<<16)
#define NVIC_AIRCR_ENDIANESS		15u

// NVIC macros

#define	NVIC_EnableIRQ(IRQn) \
		REG(NVIC)->ISER[((uint32_t)IRQn) / 32u] = (((uint32_t)1u)<<(((uint32_t)(IRQn)) % 32u))

#define	NVIC_DisableIRQ(IRQn) \
		REG(NVIC)->ICER[((uint32_t)IRQn) / 32u] = (((uint32_t)1u)<<(((uint32_t)(IRQn)) % 32u))

#define	NVIC_SetPendingIRQ(IRQn) \
		REG(NVIC)->ISPR[((uint32_t)IRQn) / 32u] = (((uint32_t)1u)<<(((uint32_t)(IRQn)) % 32u))

#define	NVIC_ClearPendingIRQ(IRQn) \
		REG(NVIC)->ICPR[((uint32_t)IRQn) / 32u] = (((uint32_t)1u)<<(((uint32_t)(IRQn)) % 32u))

#define	NVIC_SetPriority(IRQn, priority) \
		if (IRQn >= 0) { REG(NVIC)->IP[(uint32_t)IRQn] = (uint32_t)(((uint32_t)priority)<<(uint32_t)KNVIC_PRIORITY_SHIFT); } \
		else		   { REG(SCB)->SHP[((uint32_t)IRQn & 0xFu) - 4u] = ((uint32_t)priority<<(uint32_t)KNVIC_PRIORITY_SHIFT); }
