/*
; link_p.
; =======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Linker description for the uKOS-X system.
;			Privileged only support
;
;                       CODE
; linker_stTEXT			+-----------------+
;						|                 |
;						| .text           |
; linker_enTEXT			|                 |
; linker_stRODATA		+-----------------+
;						|                 |
;						| .rodata         |
; linker_enRODATA		|                 |
; linker_stDATA			+-----------------+
;						|                 |
;						| .data           |
; linker_enDATA			|                 |
;						+-----------------+
; linker_stSignature	|				  |
; linker_stBSS			+-----------------+
;						|                 |
;						| .bss            |
; linker_enBSS			| COMMON          |
;						|                 |
; _end					+-----------------+
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

OUTPUT_ARCH( "riscv" )
ENTRY(Reset_Handler)

INCLUDE		K210.ld

/* Mapping:													*/
/*															*/
/* RAM:		stPrgmCode			0x80000000					*/
/*			2M												*/
/*			stPrgmData			0x80200000					*/
/*			512K											*/
/*			stHeap				0x80300000					*/
/*			1M												*/
/*			stUMemo				0x80400000					*/
/*			1M - 64K										*/
/*			stShare				0x804F0000					*/
/*			64K												*/

/* IMPORTANT:												*/
/* all the stacks have to be maintained aligned				*/
/* on a boundary of 16-bytes								*/

linker_sizeStackSystem_C0	= (0);													/* Length of the System stack  								*/
linker_sizeStackSystem_C1	= (0);													/* Length of the System stack  								*/
linker_sizeStackFirst_C0	= (4K);													/* Length of the First stack  								*/
linker_sizeStackFirst_C1	= (4K);													/* Length of the First stack  								*/

/* IMPORTANT:												*/
/* External memory, User (download application) and shared	*/

linker_stEXRAM				= 0;													/* 0x00000000: EXRAM, start of the external memory			*/
linker_lnEXRAM				= (0);													/* Length of the external memory	  						*/

linker_stUMemo				= (k210_stSRAM_Cache + 4M);								/* 0x80400000: UMemo, start of the user memory 				*/
linker_lnUMemo				= (1M - 64K);											/* Length of the user memory	  							*/

linker_stShare				= (k210_stSRAM_Cache + 4M + linker_lnUMemo);			/* 0x804F0000: Share, start of the multicore shared memory	*/
linker_lnShare				= (64K);												/* Length of the user multicore shared memory				*/

/* IMPORTANT:												*/
/* The heap has to be maintained aligned					*/
/* on a boundary of 8-bytes									*/

linker_stHeap				= (k210_stSRAM_Cache + 3M);								/* 0x80300000: start of the heap							*/
linker_lnHeap				= (1M);													/* Length of the heap										*/

/* IMPORTANT:												*/
/* uKOS OS Flash + memory									*/

linker_stPrgmCode			= k210_stSRAM_Cache;									/* 0x80000000: PrgmCode, start of the Flash					*/
linker_lnPrgmCode			= (2M);													/* Length of the the Flash									*/

linker_stPrgmData			= (k210_stSRAM_Cache + linker_lnPrgmCode);				/* 0x80200000: PrgmData, start of the RAM					*/
linker_lnPrgmData			= (512K);												/* Length of the RAM										*/

MEMORY {
	prgm_code (rx)	: ORIGIN = linker_stPrgmCode, LENGTH = linker_lnPrgmCode
	prgm_data (rwx)	: ORIGIN = linker_stPrgmData, LENGTH = linker_lnPrgmData
}

INCLUDE		system_p.ld
