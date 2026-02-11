/*
; core_addendum.
; ==============

; SPDX-License-Identifier: MIT

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

#include	"linker.h"

// System Reset
// ------------

#define CONTROL_SET_PSP_STACK			(1u<<1u)
#define CONTROL_SET_MSP_STACK			(0u<<1u)
#define CONTROL_SET_USER_MODE			(1u<<0u)
#define CONTROL_SET_PRIVILEGED_MODE		(0u<<0u)

#define	MSC_PFCR_MAX_OS_0				(1U<<7u)
#define	ICB_ACTLR_DISLOBR				(1U<<5u)

// MPU additilnal definition & macros
// ----------------------------------

// CTRL Configuration

#define	MPU_CTRL_ENABLE					(1u<<0u)
#define	MPU_CTRL_HFNMIENA				(1u<<1u)
#define	MPU_CTRL_PRIVDEFENA				(1u<<2u)

// CTRL Configuration

#define	MPU_RBAR_XN_0					(1u<<0u)
#define	KMPU_EXECUTABLE					0u
#define	KMPU_NOT_EXECUTABLE				1u

#define	MPU_RBAR_AP_0					(1u<<1u)

// AP[2:1]	Description
// 00		Read/write by privileged code only
// 01		Read/write by any privilege level
// 10		Read-only by privileged code only
// 11		Read-only by any privilege level

#define	KMPU_RW_PRI						0u
#define	KMPU_RW_ALL						1u
#define	KMPU_R_PRI						2u
#define	KMPU_R_ALL						3u

#define	MPU_RBAR_SH_0					(1u<<3u)
#define	KMPU_NOT_SHAREABLE				0u
#define	KMPU_OUTER_SHAREABLE			2u
#define	KMPU_INNER_SHAREABLE			3u

// RLAR Configuration

#define	MPU_RLAR_E_0					(1u<<0u)
#define	MPU_ATTRINDEX_0					(1u<<1u)

// Indexes

// Typically, the inner cache attribute is used by any integrated caches and
// the outer cache attributes are exported using the bus system sideband signals.
// Depending on the processor implementation, the inner cache attributes can also
// be exported to the memory system using extra sideband signals

#define	KMPU_INNER						0u
#define	KMPU_OUTER						4u

// Gathering (G/nG)
// - Determines whether multiple accesses can be merged into a single bus transaction
// - nG: Number/size of accesses on the bus = number/size of accesses in code
//
// Reordering (R/nR)
// - Determines whether accesses to the same device can be reordered
// - nR: Accesses to the same IMPLEMENTATION DEFINED block size will appear on the bus in program order
//
// Early Write Acknowledgement (E/nE)
// - Indicates to the memory system whether a buffer can send acknowledgements
// - nE: The response should come from the end slave, not buffering in the interconnect

#define	KMPU_DEVICE_nGnRnE				(0u<<2u)
#define	KMPU_DEVICE_nGnRE				(1u<<2u)
#define	KMPU_DEVICE_nGRE				(2u<<2u)
#define	KMPU_DEVICE_GRE					(3u<<2u)

// Flash:		Normal memory, Non-shareable, Write-Through
// RAM_CACHE:	Normal memory, Shareable, Write-Through
// Peripheral:	Device memory, Always Shareable (KMPU_DEVICE_nGnRnE)

#define	KMPU_FLASH_ATTR					((0xAu<<KMPU_OUTER) | (0xAu<<KMPU_INNER))
#define	KMPU_RAM_CACHE_ATTR				((0xBu<<KMPU_OUTER) | (0xBu<<KMPU_INNER))
#define	KMPU_RAM_NOT_CACHE_ATTR			((0x4u<<KMPU_OUTER) | (0x4u<<KMPU_INNER))
#define	KMPU_PERIPH_ATTR				((0x0u<<4)			| (KMPU_DEVICE_nGnRnE<<0))

#define	KMPU_INDEX0						0u
#define	KMPU_INDEX1						8u
#define	KMPU_INDEX2						16u
#define	KMPU_INDEX3						24u

#define	SET_MPU8_INDEX(idx0, idx1, idx2, idx3, idx4, idx5, idx6, idx7, idx8)										\
																													\
	MEMO_SYNC_BARRIER;																								\
	REG(MPU)->CTRL = 0x00000000u;																					\
																													\
	REG(MPU)->MAIR0 = ((idx0)<<KMPU_INDEX0)																			\
					| ((idx1)<<KMPU_INDEX1)																			\
					| ((idx2)<<KMPU_INDEX2)																			\
					| ((idx3)<<KMPU_INDEX3);																		\
	REG(MPU)->MAIR1 = ((idx4)<<KMPU_INDEX0)																			\
					| ((idx5)<<KMPU_INDEX1)																			\
					| ((idx6)<<KMPU_INDEX2)																			\
					| ((idx7)<<KMPU_INDEX3);																		\
																													\
	MEMO_SYNC_BARRIER;

// MPU

#define	SET_MPU8_REGION(regionNb, start, end, executable, access, index, sharable)									\
																													\
extern	uint8_t	linker_##start[];																					\
extern	uint8_t	linker_##end[];																						\
																													\
	MEMO_SYNC_BARRIER;																								\
	INST_SYNC_BARRIER;																								\
																													\
	REG(MPU)->CTRL = 0x00000000u;																					\
																													\
	REG(MPU)->RNR  = regionNb;																						\
	REG(MPU)->RBAR = ((uint32_t)linker_##start & 0xFFFFFFE0u)														\
				   | (executable * MPU_RBAR_XN_0)																	\
				   | (access * MPU_RBAR_AP_0)																		\
				   | (sharable * MPU_RBAR_SH_0);																	\
	REG(MPU)->RLAR = ((uint32_t)linker_##end & 0xFFFFFFE0u)															\
				   | (index * MPU_ATTRINDEX_0)																		\
				   | (1u * MPU_RLAR_E_0);																			\
																													\
	REG(MPU)->CTRL = MPU_CTRL_PRIVDEFENA | MPU_CTRL_ENABLE;															\
																													\
	MEMO_SYNC_BARRIER;																								\
	INST_SYNC_BARRIER;
