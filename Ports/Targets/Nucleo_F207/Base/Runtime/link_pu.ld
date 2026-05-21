/*
; link_pu.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Linker description for the uKOS-X system.
;			Privileged / user support
;
;                       CODE
; linker_stTEXT			+-----------------+
;						|                 |
;						| .isr_vector     |
;						| .text           |
;						| .rodata         |
; linker_enRODATA		|                 |
;						+-----------------+
; linker_stSignature	|				  |             DATA
;						+-----------------+ ........... +-----------------+ linker_stDATA_p
; linker_stINDATA_p		|                 |				|                 |
;						| .data_p         |				| .data_p         |
;						|                 |				|                 | linker_enDATA_p
; linker_stINDATA_u		|                 |				|                 | linker_stDATA_u
;						| .data_u         |				| .data_u         |
;						|                 |				|                 | linker_enDATA_u
;						+-----------------+ ........... +-----------------+
;														|                 | linker_stBSS_p
;														| .bss_p          |
;														| COMMON          |
;														|                 | linker_enBSS_p
;														|                 | linker_stBSS_u
;														| .bss_u          |
;														|                 | linker_enBSS_u
;														+-----------------+
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

ENTRY(Reset_C0_Handler)

INCLUDE		STM32F207xx.ld

/* Mapping:													*/
/*															*/
/* RAM1:	stPrgmData_p		0x20000000					*/
/*			32K												*/
/* 			stPrgmData_u		0x20000800					*/
/*			48K												*/
/*			stHeap				0x20014000					*/
/*			26K												*/
/*			stUMemo				0x2001A800					*/
/*			22K												*/

/* IMPORTANT:												*/
/* all the stacks have to be maintained aligned				*/
/* on a boundary of 8-bytes									*/

linker_sizeStackSystem_C0	= (4K);													/* Length of the System stack  								*/
linker_sizeStackFirst_C0	= (2K);													/* Length of the First stack  								*/

/* IMPORTANT:												*/
/* External memory, User (download application) and shared	*/

linker_stEXRAM				= 0;													/* 0x00000000: EXRAM, start of the external memory			*/
linker_lnEXRAM				= (0);													/* Length of the external memory	  						*/

linker_stUMemo				= (linker_stHeap + linker_lnHeap);						/* 0x2001A800: UMemo, start of the user memory 				*/
linker_lnUMemo				= (22K);												/* Length of the user memory	  							*/

/* IMPORTANT:												*/
/* The heap has to be maintained aligned					*/
/* on a boundary of 8-bytes									*/

linker_stHeap				= (linker_stPrgmData_u + linker_lnPrgmData_u);			/* 0x20014000: start of the heap							*/
linker_lnHeap				= (26K);												/* Length of the heap										*/

/* IMPORTANT:												*/
/* uKOS OS Flash + memory									*/

linker_stPrgmCode			= stm_stINTFLASH;										/* 0x08000000: PrgmCode, start of the Flash					*/
linker_lnPrgmCode			= stm_lnINTFLASH;										/* Length of the the Flash									*/

linker_stPrgmData_p			= stm_stSRAM1;											/* 0x20000000: PrgmData_p, start of the RAM					*/
linker_lnPrgmData_p			= (32K);												/* Length_p of the RAM										*/

linker_stPrgmData_u			= (linker_stPrgmData_p + linker_lnPrgmData_p);			/* 0x20008000: PrgmData_p, start of the RAM					*/
linker_lnPrgmData_u			= (48K);												/* Length_p of the RAM										*/

/* IMPORTANT:												*/
/* equates necessary for the arm_v7 MPU regions				*/
/* for the arm_v7 MPU the regions have to be 32-B aligned	*/

linker_ST_FLASH_INT_0		= stm_stINTFLASH;										/* 0x08000000: Privileged/User FLASH						*/
linker_SZ_FLASH_INT_0		= 19;													/* 1-M = 2^(SZ + 1), SZ = log2(1-M) - 1						*/

linker_ST_RAM_INT_0			= stm_stSRAM1;											/* 0x20000000: Privileged/User RAM							*/
linker_SZ_RAM_INT_0			= 16;													/* 128-K = 2^(SZ + 1), SZ = log2(128-K) - 1					*/

linker_ST_RAM_INT_0_OS		= stm_stSRAM1;											/* 0x20000000: Privileged RAM								*/
linker_SZ_RAM_INT_0_OS		= 14;													/* 32-K = 2^(SZ + 1), SZ = log2(32-K) - 1					*/

linker_ST_PERIPH_SOC		= stm_stPERIPH;											/* 0x40000000: Privileged PERIPHERALS						*/
linker_SZ_PERIPH_SOC		= 28;													/* 512-M = 2^(SZ + 1), SZ = log2(512-M) - 1					*/

linker_ST_PERIPH_CORE		= stm_stCORE;											/* 0xE0000000: Privileged PERIPHERALS						*/
linker_SZ_PERIPH_CORE		= 27;													/* 256-M = 2^(SZ + 1), SZ = log2(256-M) - 1					*/

MEMORY {
	prgm_code (rx)		: ORIGIN = linker_stPrgmCode,   LENGTH = linker_lnPrgmCode
	prgm_data_p (rwx)	: ORIGIN = linker_stPrgmData_p, LENGTH = linker_lnPrgmData_p
	prgm_data_u (rwx)	: ORIGIN = linker_stPrgmData_u, LENGTH = linker_lnPrgmData_u
}

INCLUDE		system_pu.ld
