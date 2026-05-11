/*
; link_p.
; =======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		Linker description for RISC-V TestROM.
;			Privileged only support
;
;   (c) 2025-2026, Laurent von Allmen
;   ---------------------------------
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

ENTRY(Reset_C0_Handler)

INCLUDE		Runtime/rp2350.ld

/* Memory Mapping for RISC-V TestROM */

linker_sizeStackSystem_C0	= (4K);		/* System stack for core 0 */
linker_sizeStackFirst_C0	= (2K);		/* Application stack for core 0 */

linker_sizeStackSystem_C1	= (4K);		/* System stack for core 1 */
linker_sizeStackFirst_C1	= (2K);		/* Application stack for core 1 */

linker_lowStackSystem_C0	= rp_stSRAM;
linker_topStackSystem_C0	= linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8,

linker_lowStackFirst_C0		= linker_lowStackSystem_C0 + linker_sizeStackSystem_C0;
linker_topStackFirst_C0		= linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;

linker_lowStackSystem_C1	= linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;
linker_topStackSystem_C1	= linker_lowStackSystem_C1 + linker_sizeStackSystem_C1 - 8;

linker_lowStackFirst_C1		= linker_lowStackSystem_C1 + linker_sizeStackSystem_C1;
linker_topStackFirst_C1		= linker_lowStackFirst_C1 + linker_sizeStackFirst_C1 - 8;

/* IMPORTANT:												*/
/* The heap has to be maintained aligned					*/
/* on a boundary of 8-bytes									*/

linker_stHeap				= (rp_stSRAM + 128K);					/* 0x20020000: start of the heap							*/
linker_lnHeap				= (128K);								/* Length of the heap										*/

/* IMPORTANT:												*/
/* External memory, User (download application) and shared	*/

linker_stUMemo				= (linker_stHeap + linker_lnHeap);		/* 0x20040000: UMemo, start of the user memory 				*/
linker_lnUMemo				= (128K);								/* Length of the user memory	  							*/

/* Flash and RAM configuration */

linker_stPrgmCode			= rp_stINTFLASH;						/* 0x10000000: Flash start 									*/
linker_lnPrgmCode			= rp_lnINTFLASH;						/* 4MB Flash 												*/

linker_stPrgmData			= rp_stSRAM + 12K;						/* 0x20000000: RAM start 									*/
linker_lnPrgmData			= (116K);								/* 128KB RAM for test 										*/

MEMORY {
	prgm_code (rx)	: ORIGIN = linker_stPrgmCode, LENGTH = linker_lnPrgmCode
	prgm_data (rwx)	: ORIGIN = linker_stPrgmData, LENGTH = linker_lnPrgmData
}

INCLUDE		Runtime/system_p.ld
