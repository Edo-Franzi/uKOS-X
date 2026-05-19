/*
; link_p.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2026-05-14
; Modifs:
;
; Project:	uKOS-X
; Goal:		Linker description for the uKOS-X system.
;			Privileged only support
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
;						+-----------------+ ........... +-----------------+ linker_stDATA
; linker_stINDATA		|                 |				|                 |
;						| .data           |				| .data           |
;						|                 |				|                 | linker_enDATA
;						+-----------------+ ........... +-----------------+
;														|                 | linker_stBSS
;														| .bss            |
;														| COMMON          |
;														|                 | linker_enBSS
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

INCLUDE		STM32H743xI.ld

/* Mapping:													*/
/*															*/
/* RAM1:	stPrgmData			0x30000000					*/
/*			(128 + 128 + 32)K								*/
/* EXT:		stHeap				0x70000000					*/
/*			8192K											*/
/*			stUMemo				0x70800000					*/
/*			8192K											*/
/*			stFrameBuffer		0x71000000					*/
/*			16384K											*/

/* IMPORTANT:												*/
/* all the stacks have to be maintained aligned				*/
/* on a boundary of 8-bytes									*/

linker_sizeStackSystem_C0	= (4K);													/* Length of the System stack  								*/
linker_sizeStackFirst_C0	= (2K);													/* Length of the First stack  								*/

/* IMPORTANT:												*/
/* External memory, User (download application) and shared	*/

linker_stEXRAM				= 0x70000000;											/* 0x70000000: EXRAM, start of the external memory			*/
linker_lnEXRAM				= (32768K);												/* Length of the external memory	  						*/

linker_stFrameBuffer		= 0x71000000;											/* 0x71000000: FrameBuffer, start of the graphic memory 	*/
linker_lnFrameBuffer		= (16384K);												/* Length of the graphic memory	  							*/

linker_stUMemo				= 0x70800000;											/* 0x70800000: UMemo, start of the user memory 				*/
linker_lnUMemo				= (8192K);												/* Length of the user memory	  							*/

/* IMPORTANT:												*/
/* The heap has to be maintained aligned					*/
/* on a boundary of 8-bytes									*/

linker_stHeap				= 0x70000000;											/* 0x70000000: start of the heap							*/
linker_lnHeap				= (8192K);												/* Length of the heap										*/

/* IMPORTANT:												*/
/* uKOS OS Flash + memory									*/

linker_stPrgmCode			= stm_stINTFLASH;										/* 0x08000000: PrgmCode, start of the Flash					*/
linker_lnPrgmCode			= stm_lnINTFLASH;										/* Length of the the Flash									*/

linker_stPrgmData			= stm_stSRAM1;											/* 0x30000000: PrgmData, start of the RAM					*/
linker_lnPrgmData			= stm_lnSRAM123;										/* Length of the RAM										*/

/* IMPORTANT:												*/
/* equates necessary for the arm_v7 MPU regions				*/
/* for the arm_v7 MPU the regions have to be 32-B aligned	*/

linker_ST_FLASH_INT_0		= stm_stINTFLASH;										/* 0x08000000: Privileged/User FLASH						*/
linker_SZ_FLASH_INT_0		= 20;													/* 2-M = 2^(SZ + 1), SZ = log2(2-M) - 1						*/

linker_ST_RAM_INT_0			= stm_stAXISRAM;										/* 0x24000000: Privileged/User RAM							*/
linker_SZ_RAM_INT_0			= 18;													/* 512-K = 2^(SZ + 1), SZ = log2(512-K) - 1					*/

linker_ST_RAM_INT_1			= stm_stSRAM1;											/* 0x30000000: Privileged/User RAM							*/
linker_SZ_RAM_INT_1			= 18;													/* 512-K = 2^(SZ + 1), SZ = log2(512-K) - 1					*/

linker_ST_RAM_INT_2			= stm_stSRAM4;											/* 0x38000000: Privileged/User RAM							*/
linker_SZ_RAM_INT_2			= 15;													/* 64-K = 2^(SZ + 1), SZ = log2(64-K) - 1					*/

linker_ST_RAM_EXT_0			= linker_stEXRAM;										/* 0x70000000: Privileged/User RAM							*/
linker_SZ_RAM_EXT_0			= 23;													/* 32-M = 2^(SZ + 1), SZ = log2(32-M) - 1					*/

linker_ST_RAM_EXT_1			= linker_stFrameBuffer;									/* 0x71000000: Privileged/User RAM (no cache)				*/
linker_SZ_RAM_EXT_1			= 23;													/* 16-M = 2^(SZ + 1), SZ = log2(16-M) - 1					*/

MEMORY {
	prgm_code (rx)	: ORIGIN = linker_stPrgmCode, LENGTH = linker_lnPrgmCode
	prgm_data (rwx)	: ORIGIN = linker_stPrgmData, LENGTH = linker_lnPrgmData
}

INCLUDE		system_p.ld
