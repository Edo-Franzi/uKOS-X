/*
; linker.
; =======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Linker equates for all the uKOS-X project.
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

// Necessary for basic C (code, rodata, data, initialised, bss)
// ------------------------------------------------------------

extern	uint8_t	linker_stVECTORS[];

extern	uint8_t	linker_stTEXT[];
extern	uint8_t	linker_enTEXT[];

extern	uint8_t	linker_stRODATA[];
extern	uint8_t	linker_enRODATA[];

extern	uint8_t	linker_stInitArray[];
extern	uint8_t	linker_enInitArray[];

extern	uint8_t	linker_stFiniArray[];
extern	uint8_t	linker_enFiniArray[];

extern	uint8_t	linker_stDATA_p[];
extern	uint8_t	linker_enDATA_p[];
extern	uint8_t	linker_stINDATA_p[];

extern	uint8_t	linker_stDATA_u[];
extern	uint8_t	linker_enDATA_u[];
extern	uint8_t	linker_stINDATA_u[];

extern	uint8_t	linker_stDATA[];
extern	uint8_t	linker_enDATA[];
extern	uint8_t	linker_stINDATA[];

extern	uint8_t	linker_stBSS_p[];
extern	uint8_t	linker_enBSS_p[];

extern	uint8_t	linker_stBSS_u[];
extern	uint8_t	linker_enBSS_u[];

extern	uint8_t	linker_stBSS[];
extern	uint8_t	linker_enBSS[];

// Necessary for all the targets
// -----------------------------

extern	uint8_t	linker_stCODE[];
extern	uint8_t	linker_enCODE[];

extern	uint8_t	linker_stEXRAM[];
extern	uint8_t	linker_lnEXRAM[];

extern	uint8_t	linker_stUMemo[];
extern	uint8_t	linker_lnUMemo[];

extern	uint8_t	linker_stHeap[];
extern	uint8_t	linker_lnHeap[];

extern	uint8_t	linker_stShare[];
extern	uint8_t	linker_lnShare[];

// Necessary for all the systems
// -----------------------------

extern	uint8_t	linker_stPrgmCode[];
extern	uint8_t	linker_lnPrgmCode[];

extern	uint8_t	linker_stPrgmData_p[];
extern	uint8_t	linker_lnPrgmData_p[];

extern	uint8_t	linker_stPrgmData_u[];
extern	uint8_t	linker_lnPrgmData_u[];

extern	uint8_t	linker_stPrgmData[];
extern	uint8_t	linker_lnPrgmData[];

extern	uint8_t	linker_stSignature[];
extern	uint8_t	linker_stDirectory[];

extern	uint8_t	linker_stSCode[];
extern	uint8_t	linker_lnSCode[];

// Necessary for all the uKernel
// -----------------------------

extern	uint8_t	linker_stTEXT_KERN_p[];
extern	uint8_t	linker_enTEXT_KERN_p[];

extern	uint8_t	linker_stRODATA_KERN_p[];
extern	uint8_t	linker_enRODATA_KERN_p[];

extern	uint8_t	linker_stDATA_KERN_p[];
extern	uint8_t	linker_enDATA_KERN_p[];

extern	uint8_t	linker_stBSS_KERN_p[];
extern	uint8_t	linker_enBSS_KERN_p[];

// Necessary for all the stacks
// ----------------------------

extern	uint8_t	linker_lowStackFirst_C0[];
extern	uint8_t	linker_sizeStackFirst_C0[];
extern	uint8_t	linker_topStackFirst_C0[];

extern	uint8_t	linker_lowStackSystem_C0[];
extern	uint8_t	linker_sizeStackSystem_C0[];
extern	uint8_t	linker_topStackSystem_C0[];

extern	uint8_t	linker_lowStackFirst_C1[];
extern	uint8_t	linker_sizeStackFirst_C1[];
extern	uint8_t	linker_topStackFirst_C1[];

extern	uint8_t	linker_lowStackSystem_C1[];
extern	uint8_t	linker_sizeStackSystem_C1[];
extern	uint8_t	linker_topStackSystem_C1[];
