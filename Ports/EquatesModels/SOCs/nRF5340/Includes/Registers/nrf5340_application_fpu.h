/*
; nrf5340_application_fpu.
; ========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_fpu equates.
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

// FPU address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	RESERVED0[64];
	volatile	uint32_t	EVENTS_INVALIDOPERATION;
	volatile	uint32_t	EVENTS_DIVIDEBYZERO;
	volatile	uint32_t	EVENTS_OVERFLOW;
	volatile	uint32_t	EVENTS_UNDERFLOW;
	volatile	uint32_t	EVENTS_INEXACT;
	volatile	uint32_t	EVENTS_DENORMALINPUT;
	volatile	uint32_t	RESERVED1[122];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
} FPU_TypeDef;

#if (defined(__cplusplus))
#define	FPU_NS	reinterpret_cast<FPU_TypeDef *>(0x40000000u)
#define	FPU_S	reinterpret_cast<FPU_TypeDef *>(0x50000000u)

#else
#define	FPU_NS	((FPU_TypeDef *)0x40000000u)
#define	FPU_S	((FPU_TypeDef *)0x50000000u)
#endif

// EVENTS_INVALIDOPERATION Configuration

#define	FPU_EVENTS_INVALIDOPERATION_EVENTS_INVALIDOPERATION					(0x1u<<0)
#define	FPU_EVENTS_INVALIDOPERATION_EVENTS_INVALIDOPERATION_NOTGENERATED	(0x0u<<0)
#define	FPU_EVENTS_INVALIDOPERATION_EVENTS_INVALIDOPERATION_GENERATED		(0x1u<<0)

// EVENTS_DIVIDEBYZERO Configuration

#define	FPU_EVENTS_DIVIDEBYZERO_EVENTS_DIVIDEBYZERO							(0x1u<<0)
#define	FPU_EVENTS_DIVIDEBYZERO_EVENTS_DIVIDEBYZERO_NOTGENERATED			(0x0u<<0)
#define	FPU_EVENTS_DIVIDEBYZERO_EVENTS_DIVIDEBYZERO_GENERATED				(0x1u<<0)

// EVENTS_OVERFLOW Configuration

#define	FPU_EVENTS_OVERFLOW_EVENTS_OVERFLOW									(0x1u<<0)
#define	FPU_EVENTS_OVERFLOW_EVENTS_OVERFLOW_NOTGENERATED					(0x0u<<0)
#define	FPU_EVENTS_OVERFLOW_EVENTS_OVERFLOW_GENERATED						(0x1u<<0)

// EVENTS_UNDERFLOW Configuration

#define	FPU_EVENTS_UNDERFLOW_EVENTS_UNDERFLOW								(0x1u<<0)
#define	FPU_EVENTS_UNDERFLOW_EVENTS_UNDERFLOW_NOTGENERATED					(0x0u<<0)
#define	FPU_EVENTS_UNDERFLOW_EVENTS_UNDERFLOW_GENERATED						(0x1u<<0)

// EVENTS_INEXACT Configuration

#define	FPU_EVENTS_INEXACT_EVENTS_INEXACT									(0x1u<<0)
#define	FPU_EVENTS_INEXACT_EVENTS_INEXACT_NOTGENERATED						(0x0u<<0)
#define	FPU_EVENTS_INEXACT_EVENTS_INEXACT_GENERATED							(0x1u<<0)

// EVENTS_DENORMALINPUT Configuration

#define	FPU_EVENTS_DENORMALINPUT_EVENTS_DENORMALINPUT						(0x1u<<0)
#define	FPU_EVENTS_DENORMALINPUT_EVENTS_DENORMALINPUT_NOTGENERATED			(0x0u<<0)
#define	FPU_EVENTS_DENORMALINPUT_EVENTS_DENORMALINPUT_GENERATED				(0x1u<<0)

// INTEN Configuration

#define	FPU_INTEN_DENORMALINPUT												(0x1u<<5)
#define	FPU_INTEN_INEXACT													(0x1u<<4)
#define	FPU_INTEN_UNDERFLOW													(0x1u<<3)
#define	FPU_INTEN_OVERFLOW													(0x1u<<2)
#define	FPU_INTEN_DIVIDEBYZERO												(0x1u<<1)
#define	FPU_INTEN_INVALIDOPERATION											(0x1u<<0)
#define	FPU_INTEN_DENORMALINPUT_DISABLED									(0x0u<<5)
#define	FPU_INTEN_DENORMALINPUT_ENABLED										(0x1u<<5)
#define	FPU_INTEN_INEXACT_DISABLED											(0x0u<<4)
#define	FPU_INTEN_INEXACT_ENABLED											(0x1u<<4)
#define	FPU_INTEN_UNDERFLOW_DISABLED										(0x0u<<3)
#define	FPU_INTEN_UNDERFLOW_ENABLED											(0x1u<<3)
#define	FPU_INTEN_OVERFLOW_DISABLED											(0x0u<<2)
#define	FPU_INTEN_OVERFLOW_ENABLED											(0x1u<<2)
#define	FPU_INTEN_DIVIDEBYZERO_DISABLED										(0x0u<<1)
#define	FPU_INTEN_DIVIDEBYZERO_ENABLED										(0x1u<<1)
#define	FPU_INTEN_INVALIDOPERATION_DISABLED									(0x0u<<0)
#define	FPU_INTEN_INVALIDOPERATION_ENABLED									(0x1u<<0)

// INTENSET Configuration

#define	FPU_INTENSET_DENORMALINPUT											(0x1u<<5)
#define	FPU_INTENSET_INEXACT												(0x1u<<4)
#define	FPU_INTENSET_UNDERFLOW												(0x1u<<3)
#define	FPU_INTENSET_OVERFLOW												(0x1u<<2)
#define	FPU_INTENSET_DIVIDEBYZERO											(0x1u<<1)
#define	FPU_INTENSET_INVALIDOPERATION										(0x1u<<0)
#define	FPU_INTENSET_DENORMALINPUT_DISABLED									(0x0u<<5)
#define	FPU_INTENSET_DENORMALINPUT_ENABLED									(0x1u<<5)
#define	FPU_INTENSET_DENORMALINPUT_SET										(0x1u<<5)
#define	FPU_INTENSET_INEXACT_DISABLED										(0x0u<<4)
#define	FPU_INTENSET_INEXACT_ENABLED										(0x1u<<4)
#define	FPU_INTENSET_INEXACT_SET											(0x1u<<4)
#define	FPU_INTENSET_UNDERFLOW_DISABLED										(0x0u<<3)
#define	FPU_INTENSET_UNDERFLOW_ENABLED										(0x1u<<3)
#define	FPU_INTENSET_UNDERFLOW_SET											(0x1u<<3)
#define	FPU_INTENSET_OVERFLOW_DISABLED										(0x0u<<2)
#define	FPU_INTENSET_OVERFLOW_ENABLED										(0x1u<<2)
#define	FPU_INTENSET_OVERFLOW_SET											(0x1u<<2)
#define	FPU_INTENSET_DIVIDEBYZERO_DISABLED									(0x0u<<1)
#define	FPU_INTENSET_DIVIDEBYZERO_ENABLED									(0x1u<<1)
#define	FPU_INTENSET_DIVIDEBYZERO_SET										(0x1u<<1)
#define	FPU_INTENSET_INVALIDOPERATION_DISABLED								(0x0u<<0)
#define	FPU_INTENSET_INVALIDOPERATION_ENABLED								(0x1u<<0)
#define	FPU_INTENSET_INVALIDOPERATION_SET									(0x1u<<0)

// INTENCLR Configuration

#define	FPU_INTENCLR_DENORMALINPUT											(0x1u<<5)
#define	FPU_INTENCLR_INEXACT												(0x1u<<4)
#define	FPU_INTENCLR_UNDERFLOW												(0x1u<<3)
#define	FPU_INTENCLR_OVERFLOW												(0x1u<<2)
#define	FPU_INTENCLR_DIVIDEBYZERO											(0x1u<<1)
#define	FPU_INTENCLR_INVALIDOPERATION										(0x1u<<0)
#define	FPU_INTENCLR_DENORMALINPUT_DISABLED									(0x0u<<5)
#define	FPU_INTENCLR_DENORMALINPUT_ENABLED									(0x1u<<5)
#define	FPU_INTENCLR_DENORMALINPUT_CLEAR									(0x1u<<5)
#define	FPU_INTENCLR_INEXACT_DISABLED										(0x0u<<4)
#define	FPU_INTENCLR_INEXACT_ENABLED										(0x1u<<4)
#define	FPU_INTENCLR_INEXACT_CLEAR											(0x1u<<4)
#define	FPU_INTENCLR_UNDERFLOW_DISABLED										(0x0u<<3)
#define	FPU_INTENCLR_UNDERFLOW_ENABLED										(0x1u<<3)
#define	FPU_INTENCLR_UNDERFLOW_CLEAR										(0x1u<<3)
#define	FPU_INTENCLR_OVERFLOW_DISABLED										(0x0u<<2)
#define	FPU_INTENCLR_OVERFLOW_ENABLED										(0x1u<<2)
#define	FPU_INTENCLR_OVERFLOW_CLEAR											(0x1u<<2)
#define	FPU_INTENCLR_DIVIDEBYZERO_DISABLED									(0x0u<<1)
#define	FPU_INTENCLR_DIVIDEBYZERO_ENABLED									(0x1u<<1)
#define	FPU_INTENCLR_DIVIDEBYZERO_CLEAR										(0x1u<<1)
#define	FPU_INTENCLR_INVALIDOPERATION_DISABLED								(0x0u<<0)
#define	FPU_INTENCLR_INVALIDOPERATION_ENABLED								(0x1u<<0)
#define	FPU_INTENCLR_INVALIDOPERATION_CLEAR									(0x1u<<0)
