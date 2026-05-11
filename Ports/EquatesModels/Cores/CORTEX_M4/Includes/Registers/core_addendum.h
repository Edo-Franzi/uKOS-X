/*
; core_addendum.
; ==============

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

#include	"linker.h"

// System Reset
// ------------

#define CONTROL_SET_PSP_STACK			(1u<<1u)
#define CONTROL_SET_MSP_STACK			(0u<<1u)
#define CONTROL_SET_USER_MODE			(1u<<0u)
#define CONTROL_SET_PRIVILEGED_MODE		(0u<<0u)

// MPU additilnal definition & macros
// ----------------------------------

#define	KMPU_EXECUTABLE					0u
#define	KMPU_NOT_EXECUTABLE				1u

// AP[2:0]	Privileged permissions		Unprivileged permissions	Description
// 000		No access					No access					All accesses generate a permission fault
// 001		RW							No access					(KMPU_RW_PRI) Access from privileged software only
// 010		RW							RO							(KMPU_RW_PRI_R_UNP) Writes by unprivileged software generate a permission fault
// 011		RW							RW							(KMPU_RW_ALL) Full access
// 100		Unpredictable				Unpredictable				Reserved
// 101		RO							No access					Reads by privileged software only
// 110		RO							RO							(KMPU_R_ALL) Read only, by privileged or unprivileged software
// 111		RO							RO							Read only, by privileged or unprivileged software

#define	KMPU_RW_PRI						1u
#define	KMPU_RW_PRI_R_UNP				2u
#define	KMPU_RW_ALL						3u
#define	KMPU_R_ALL						6u

#define	KMPU_TEX_LEVEL0					0u

#define	KMPU_SHAREABLE					1u
#define	KMPU_NOT_SHAREABLE				0u
#define	KMPU_CASHABLE					1u
#define	KMPU_NOT_CASHABLE				0u
#define	KMPU_BUFFERABLE					1u
#define	KMPU_NOT_BUFFERABLE				0u

#define	SET_MPU7_REGION(regionNb, subRegion, start, size, executable, access, tex, sharable, cachable, bufferable)	\
																													\
extern	uint8_t	linker_##start[];																					\
extern	uint8_t	linker_##size[];																					\
																													\
	MEMO_SYNC_BARRIER;																								\
	INST_SYNC_BARRIER;																								\
																													\
	MPU->CTRL = 0x00000000u;																						\
																													\
	MPU->RNR  = regionNb;																							\
	MPU->RBAR = ((uint32_t)linker_##start & 0xFFFFFFE0u);															\
	MPU->RASR = (executable * MPU_RASR_XN)																			\
			  | (access * MPU_RASR_AP_0)																			\
			  | (tex * MPU_RASR_TEX_0)																				\
			  | (sharable * MPU_RASR_S)																				\
			  | (cachable * MPU_RASR_C)																				\
			  | (bufferable * MPU_RASR_B)																			\
			  | (subRegion * MPU_RASR_SRD_0)																		\
			  | ((uint32_t)linker_##size<<1u)																		\
			  | MPU_RASR_ENABLE;																					\
																													\
	MPU->CTRL = MPU_CTRL_PRIVDEFENA | MPU_CTRL_ENABLE;																\
																													\
	MEMO_SYNC_BARRIER;																								\
	INST_SYNC_BARRIER;
