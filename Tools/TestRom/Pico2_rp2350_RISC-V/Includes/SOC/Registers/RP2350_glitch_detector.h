/*
; RP2350_glitch_detector.
; =======================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_glitch_detector equates.
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

#include	<stdint.h>

// GLITCH_DETECTOR address definitions
// -----------------------------------

typedef struct {
	volatile	uint32_t	ARM;
	volatile	uint32_t	DISARM;
	volatile	uint32_t	SENSITIVITY;
	volatile	uint32_t	LOCK;
	volatile	uint32_t	TRIG_STATUS;
	volatile	uint32_t	TRIG_FORCE;
} GLITCH_DETECTOR_TypeDef;

#ifdef __cplusplus
#define	GLITCH_DETECTOR_NS	reinterpret_cast<GLITCH_DETECTOR_TypeDef *>(0x40158000u)
#define	GLITCH_DETECTOR_S	reinterpret_cast<GLITCH_DETECTOR_TypeDef *>(0x40158000u)
#else
#define	GLITCH_DETECTOR_NS	((GLITCH_DETECTOR_TypeDef *)0x40158000u)
#define	GLITCH_DETECTOR_S	((GLITCH_DETECTOR_TypeDef *)0x40158000u)
#endif

// ARM Configuration

#define	GLITCH_DETECTOR_ARM_ARM						(0xFFFFu<<0)
#define	GLITCH_DETECTOR_ARM_ARM_0					(0x1u<<0)
#define	GLITCH_DETECTOR_ARM_ARM_NO					(0x5BADu<<0)
#define	GLITCH_DETECTOR_ARM_ARM_YES					(0x0u<<0)

// DISARM Configuration

#define	GLITCH_DETECTOR_DISARM_DISARM				(0xFFFFu<<0)
#define	GLITCH_DETECTOR_DISARM_DISARM_0				(0x1u<<0)
#define	GLITCH_DETECTOR_DISARM_DISARM_NO			(0x0u<<0)
#define	GLITCH_DETECTOR_DISARM_DISARM_YES			(0xDCAFu<<0)

// SENSITIVITY Configuration

#define	GLITCH_DETECTOR_SENSITIVITY_DET0			(0x3u<<0)
#define	GLITCH_DETECTOR_SENSITIVITY_DET0_0			(0x1u<<0)
#define	GLITCH_DETECTOR_SENSITIVITY_DET1			(0x3u<<2)
#define	GLITCH_DETECTOR_SENSITIVITY_DET1_0			(0x1u<<2)
#define	GLITCH_DETECTOR_SENSITIVITY_DET2			(0x3u<<4)
#define	GLITCH_DETECTOR_SENSITIVITY_DET2_0			(0x1u<<4)
#define	GLITCH_DETECTOR_SENSITIVITY_DET3			(0x3u<<6)
#define	GLITCH_DETECTOR_SENSITIVITY_DET3_0			(0x1u<<6)
#define	GLITCH_DETECTOR_SENSITIVITY_DET0_INV		(0x3u<<8)
#define	GLITCH_DETECTOR_SENSITIVITY_DET0_INV_0		(0x1u<<8)
#define	GLITCH_DETECTOR_SENSITIVITY_DET1_INV		(0x3u<<10)
#define	GLITCH_DETECTOR_SENSITIVITY_DET1_INV_0		(0x1u<<10)
#define	GLITCH_DETECTOR_SENSITIVITY_DET2_INV		(0x3u<<12)
#define	GLITCH_DETECTOR_SENSITIVITY_DET2_INV_0		(0x1u<<12)
#define	GLITCH_DETECTOR_SENSITIVITY_DET3_INV		(0x3u<<14)
#define	GLITCH_DETECTOR_SENSITIVITY_DET3_INV_0		(0x1u<<14)
#define	GLITCH_DETECTOR_SENSITIVITY_DEFAULT			(0xFFu<<24)
#define	GLITCH_DETECTOR_SENSITIVITY_DEFAULT_0		(0x1u<<24)
#define	GLITCH_DETECTOR_SENSITIVITY_DEFAULT_YES		(0x0u<<24)
#define	GLITCH_DETECTOR_SENSITIVITY_DEFAULT_NO		(0xDEu<<24)

// LOCK Configuration

#define	GLITCH_DETECTOR_LOCK_LOCK					(0xFFu<<0)
#define	GLITCH_DETECTOR_LOCK_LOCK_0					(0x1u<<0)

// TRIG_STATUS Configuration

#define	GLITCH_DETECTOR_TRIG_STATUS_DET0			(0x1u<<0)
#define	GLITCH_DETECTOR_TRIG_STATUS_DET1			(0x1u<<1)
#define	GLITCH_DETECTOR_TRIG_STATUS_DET2			(0x1u<<2)
#define	GLITCH_DETECTOR_TRIG_STATUS_DET3			(0x1u<<3)

// TRIG_FORCE Configuration

#define	GLITCH_DETECTOR_TRIG_FORCE_TRIG_FORCE		(0xFu<<0)
#define	GLITCH_DETECTOR_TRIG_FORCE_TRIG_FORCE_0		(0x1u<<0)
