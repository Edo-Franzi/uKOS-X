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

INCLUDE		STM32N657xD.ld

/* Mapping:													*/
/*															*/
/* RAM2:	stPrgmCode	(Boot)	0x34100400 (400 signature)	*/
/*			64K	(just for the first boot)					*/
/* RAM1:	stPrgmCode	(Appl)	0x34000400 (400 signature)	*/
/*			(1800K - 1K)									*/
/* RAM2-6:	stPrgmData			0x341C2000					*/
/*			256K											*/
/*			stHeap				0x34202000					*/
/*			256K											*/
/*			Frame buffer		0x34242000					*/
/*			(1500K)				0x343BFFFF					*/
/*			enough: 800x480x4	1500K						*/
/* APSRAM:	stUMemo				0x90000000					*/
/*			32M												*/

/* IMPORTANT:												*/
/* all the stacks have to be maintained aligned				*/
/* on a boundary of 8-bytes									*/

linker_sizeStackSystem_C0	= (8K);																	/* Length of the System stack  								*/
linker_sizeStackFirst_C0	= (8K);																	/* Length of the First stack  								*/

/* IMPORTANT:												*/
/* External memory, User (download application) and shared	*/

linker_stEXRAM				= 0x90000000;															/* 0x90000000: EXRAM, start of the external memory			*/
linker_lnEXRAM				= (32 * 1024K);															/* Length of the external memory	  						*/

/* IMPORTANT:												*/
/* uKOS OS Flash + memory									*/

linker_stPrgmCode			= (stm_stAXISRAM1 + 1K);												/* 0x34000400: PrgmCode, start of the Flash					*/
linker_lnPrgmCode			= (1800K - 1K);															/* Length of the the Flash									*/

linker_stPrgmData			= (linker_stPrgmCode + linker_lnPrgmCode);								/* 0x341C2000: PrgmData, start of the RAM					*/
linker_lnPrgmData			= (256K);																/* Length of the RAM										*/

linker_stUMemo				= 0x90000000;															/* 0x90000000: UMemo, start of the user memory 				*/
linker_lnUMemo				= (32 * 1024K);															/* Length of the user memory	  							*/

linker_stExtFlash			= 0x70000000;															/* 0x70000000: ExtFlash, start of the external flash memory	*/
linker_lnExtFlash			= (128 * 1024K);														/* Length of the external flash memory						*/

/* IMPORTANT:												*/
/* The heap has to be maintained aligned					*/
/* on a boundary of 8-bytes									*/

linker_stHeap				= (linker_stPrgmData + linker_lnPrgmData);								/* 0x34202000: start of the heap							*/
linker_lnHeap				= (256K);																/* Length of the heap										*/

linker_stLCD_F_BUFFER		= (linker_stHeap + linker_lnHeap);										/* 0x34242000: Privileged/User LCD Frame Buffer 			*/
linker_lnLCD_F_BUFFER		= (1500K);																/* Length of the RAM										*/

/* IMPORTANT:												*/
/* equates necessary for the arm_v8 MPU regions				*/
/* for the arm_v8 MPU the regions have to be 32-B aligned	*/

linker_ST_RAM_INT_1			= stm_stAXISRAM1;														/* 0x34000000: Privileged/User RAM							*/
linker_EN_RAM_INT_1			= (stm_stAXISRAM1 + stm_lnAXISRAM1 - 1);								/* 0x341C1FFF: 1800-K										*/

linker_ST_RAM_INT_2			= (linker_stPrgmData);													/* 0x341C2000: Privileged/User RAM							*/
linker_EN_RAM_INT_2			= (stm_stAXISRAM2 + 256K + 256K - 1);									/* 0x34241FFF: 512-K										*/

linker_ST_RAM_INT_3			= linker_stLCD_F_BUFFER;												/* 0x34242000: Privileged/User RAM							*/
linker_EN_RAM_INT_3			= (linker_stLCD_F_BUFFER + 1500K - 1);									/* 0x343BFFFF: 1500-K										*/

linker_ST_APSRAM			= linker_stUMemo;														/* 0x90000000: Privileged/User RAM							*/
linker_EN_APSRAM			= (linker_stUMemo + linker_lnUMemo - 1);								/* 0x91FFFFFF: 32-M											*/

linker_ST_OCTOFLASH			= linker_stExtFlash;													/* 0x70000000: Privileged/User RAM							*/
linker_EN_OCTOFLASH			= (linker_stExtFlash + linker_lnExtFlash - 1);							/* 0x77FFFFFF: 128-M										*/

MEMORY {
	prgm_code (rwx)	: ORIGIN = linker_stPrgmCode, LENGTH = linker_lnPrgmCode
	prgm_data (rwx)	: ORIGIN = linker_stPrgmData, LENGTH = linker_lnPrgmData
}

INCLUDE		system_p.ld
