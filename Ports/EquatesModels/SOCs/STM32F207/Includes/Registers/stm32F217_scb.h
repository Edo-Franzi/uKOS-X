/*
; stm32F217_scb.
; ==============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_scb equates.
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

// SCB address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CPUID;
	volatile	uint32_t	ICSR;
	volatile	uint32_t	VTOR;
	volatile	uint32_t	AIRCR;
	volatile	uint32_t	SCR;
	volatile	uint32_t	CCR;
	volatile	uint32_t	SHPR1;
	volatile	uint32_t	SHPR2;
	volatile	uint32_t	SHPR3;
	volatile	uint32_t	SHCRS;
	volatile	uint32_t	CFSR_UFSR_BFSR_MMFSR;
	volatile	uint32_t	HFSR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	MMFAR;
	volatile	uint32_t	BFAR;
} SCB_TypeDef;

#if (defined(__cplusplus))
#define	SCB	reinterpret_cast<SCB_TypeDef *>(0xE000ED00u)

#else
#define	SCB	((SCB_TypeDef *)0xE000ED00u)
#endif

// CPUID Configuration

#define	SCB_CPUID_IMPLEMENTER					(0xFFu<<24)
#define	SCB_CPUID_IMPLEMENTER_0					(0x1u<<24)
#define	SCB_CPUID_VARIANT						(0xFu<<20)
#define	SCB_CPUID_VARIANT_0						(0x1u<<20)
#define	SCB_CPUID_CONSTANT						(0xFu<<16)
#define	SCB_CPUID_CONSTANT_0					(0x1u<<16)
#define	SCB_CPUID_PARTNO						(0xFFFu<<4)
#define	SCB_CPUID_PARTNO_0						(0x1u<<4)
#define	SCB_CPUID_REVISION						(0xFu<<0)
#define	SCB_CPUID_REVISION_0					(0x1u<<0)

// ICSR Configuration

#define	SCB_ICSR_NMIPENDSET						(0x1u<<31)
#define	SCB_ICSR_PENDSVSET						(0x1u<<28)
#define	SCB_ICSR_PENDSVCLR						(0x1u<<27)
#define	SCB_ICSR_PENDSTSET						(0x1u<<26)
#define	SCB_ICSR_PENDSTCLR						(0x1u<<25)
#define	SCB_ICSR_ISRPENDING						(0x1u<<22)
#define	SCB_ICSR_VECTPENDING					(0x7Fu<<12)
#define	SCB_ICSR_VECTPENDING_0					(0x1u<<12)
#define	SCB_ICSR_RETTOBASE						(0x1u<<11)
#define	SCB_ICSR_VECTACTIVE						(0x1FFu<<0)
#define	SCB_ICSR_VECTACTIVE_0					(0x1u<<0)

// VTOR Configuration

#define	SCB_VTOR_TBLOFF							(0x1FFFFFu<<9)
#define	SCB_VTOR_TBLOFF_0						(0x1u<<9)

// AIRCR Configuration

#define	SCB_AIRCR_VECTKEYSTAT					(0xFFFFu<<16)
#define	SCB_AIRCR_VECTKEYSTAT_0					(0x1u<<16)
#define	SCB_AIRCR_ENDIANESS						(0x1u<<15)
#define	SCB_AIRCR_PRIGROUP						(0x7u<<8)
#define	SCB_AIRCR_PRIGROUP_0					(0x1u<<8)
#define	SCB_AIRCR_SYSRESETREQ					(0x1u<<2)
#define	SCB_AIRCR_VECTCLRACTIVE					(0x1u<<1)
#define	SCB_AIRCR_VECTRESET						(0x1u<<0)

// SCR Configuration

#define	SCB_SCR_SEVEONPEND						(0x1u<<4)
#define	SCB_SCR_SLEEPDEEP						(0x1u<<2)
#define	SCB_SCR_SLEEPONEXIT						(0x1u<<1)

// CCR Configuration

#define	SCB_CCR_STKALIGN						(0x1u<<9)
#define	SCB_CCR_BFHFNMIGN						(0x1u<<8)
#define	SCB_CCR_DIV_0_TRP						(0x1u<<4)
#define	SCB_CCR_UNALIGN__TRP					(0x1u<<3)
#define	SCB_CCR_USERSETMPEND					(0x1u<<1)
#define	SCB_CCR_NONBASETHRDENA					(0x1u<<0)

// SHPR1 Configuration

#define	SCB_SHPR1_PRI_6							(0xFFu<<16)
#define	SCB_SHPR1_PRI_6_0						(0x1u<<16)
#define	SCB_SHPR1_PRI_5							(0xFFu<<8)
#define	SCB_SHPR1_PRI_5_0						(0x1u<<8)
#define	SCB_SHPR1_PRI_4							(0xFFu<<0)
#define	SCB_SHPR1_PRI_4_0						(0x1u<<0)

// SHPR2 Configuration

#define	SCB_SHPR2_PRI_11						(0xFFu<<24)
#define	SCB_SHPR2_PRI_11_0						(0x1u<<24)

// SHPR3 Configuration

#define	SCB_SHPR3_PRI_15						(0xFFu<<24)
#define	SCB_SHPR3_PRI_15_0						(0x1u<<24)
#define	SCB_SHPR3_PRI_14						(0xFFu<<16)
#define	SCB_SHPR3_PRI_14_0						(0x1u<<16)

// SHCRS Configuration

#define	SCB_SHCRS_USGFAULTENA					(0x1u<<18)
#define	SCB_SHCRS_BUSFAULTENA					(0x1u<<17)
#define	SCB_SHCRS_MEMFAULTENA					(0x1u<<16)
#define	SCB_SHCRS_SVCALLPENDED					(0x1u<<15)
#define	SCB_SHCRS_BUSFAULTPENDED				(0x1u<<14)
#define	SCB_SHCRS_MEMFAULTPENDED				(0x1u<<13)
#define	SCB_SHCRS_USGFAULTPENDED				(0x1u<<12)
#define	SCB_SHCRS_SYSTICKACT					(0x1u<<11)
#define	SCB_SHCRS_PENDSVACT						(0x1u<<10)
#define	SCB_SHCRS_MONITORACT					(0x1u<<8)
#define	SCB_SHCRS_SVCALLACT						(0x1u<<7)
#define	SCB_SHCRS_USGFAULTACT					(0x1u<<3)
#define	SCB_SHCRS_BUSFAULTACT					(0x1u<<1)
#define	SCB_SHCRS_MEMFAULTACT					(0x1u<<0)

// CFSR_UFSR_BFSR_MMFSR Configuration

#define	SCB_CFSR_UFSR_BFSR_MMFSR_DIVBYZERO		(0x1u<<25)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_UNALIGNED		(0x1u<<24)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_NOCP			(0x1u<<19)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_INVPC			(0x1u<<18)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_INVSTATE		(0x1u<<17)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_UNDEFINSTR		(0x1u<<16)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_BFARVALID		(0x1u<<15)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_LSPERR			(0x1u<<13)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_STKERR			(0x1u<<12)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_UNSTKERR		(0x1u<<11)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_IMPRECISERR	(0x1u<<10)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_PRECISERR		(0x1u<<9)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_IBUSERR		(0x1u<<8)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_MMARVALID		(0x1u<<7)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_MLSPERR		(0x1u<<5)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_MSTKERR		(0x1u<<4)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_MUNSTKERR		(0x1u<<3)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_DACCVIOL		(0x1u<<1)
#define	SCB_CFSR_UFSR_BFSR_MMFSR_IACCVIOL		(0x1u<<0)

// HFSR Configuration

#define	SCB_HFSR_DEBUG_VT						(0x1u<<31)
#define	SCB_HFSR_FORCED							(0x1u<<30)
#define	SCB_HFSR_VECTTBL						(0x1u<<1)

// MMFAR Configuration

#define	SCB_MMFAR_MMFAR							(0xFFFFFFFFu<<0)
#define	SCB_MMFAR_MMFAR_0						(0x1u<<0)

// BFAR Configuration

#define	SCB_BFAR_BFAR							(0xFFFFFFFFu<<0)
#define	SCB_BFAR_BFAR_0							(0x1u<<0)
