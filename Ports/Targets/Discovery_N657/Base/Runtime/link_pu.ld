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

INCLUDE		STM32N657xD.ld

/* Mapping:													*/
/*															*/
/* RAM2:	stPrgmCode	(Boot)	0x34100400 (400 signature)	*/
/*			64K												*/
/* RAM1:	stPrgmCode	(Appl)	0x34000400 (400 signature)	*/
/*			(1024K - 1K)									*/
/* RAM2-6:	stPrgmData_p		0x34100000					*/
/*			96K												*/
/*			stPrgmData_u		0x34118000					*/
/*			160K											*/
/*			stUMemo				0x34140000					*/
/*			768K											*/
/*			stHeap				0x34200000					*/
/*			256K											*/
/*			Frame buffer		0x34240000					*/
/*			(1536K)				0x343C0000					*/
/*			enough: 800x480x4	1500K						*/

/* IMPORTANT:												*/
/* all the stacks have to be maintained aligned				*/
/* on a boundary of 8-bytes									*/

linker_sizeStackSystem_C0	= (8K);																	/* Length of the System stack  								*/
linker_sizeStackFirst_C0	= (8K);																	/* Length of the First stack  								*/

/* IMPORTANT:												*/
/* External memory, User (download application) and shared	*/

linker_stEXRAM				= 0;																	/* 0x00000000: EXRAM, start of the external memory			*/
linker_lnEXRAM				= (0);																	/* Length of the external memory	  						*/

/* IMPORTANT:												*/
/* uKOS OS Flash + memory									*/

linker_stPrgmCode			= (stm_stAXISRAM1 + 1K);												/* 0x34000400: PrgmCode, start of the Flash					*/
linker_lnPrgmCode			= (1024K - 1K);															/* Length of the the Flash									*/

linker_stPrgmData_p			= stm_stAXISRAM2;														/* 0x34100000: PrgmData, start of the RAM					*/
linker_lnPrgmData_p			= (96K);																/* Length of the RAM										*/

linker_stPrgmData_u			= (linker_stPrgmData_p + linker_lnPrgmData_p);							/* 0x34118000: PrgmData, start of the RAM					*/
linker_lnPrgmData_u			= (160K);																/* Length of the RAM										*/

linker_stUMemo				= (linker_stPrgmData_u + linker_lnPrgmData_u);							/* 0x34140000: UMemo, start of the user memory 				*/
linker_lnUMemo				= (768K);																/* Length of the user memory	  							*/

/* IMPORTANT:												*/
/* The heap has to be maintained aligned					*/
/* on a boundary of 8-bytes									*/

linker_stHeap				= (linker_stUMemo + linker_lnUMemo);									/* 0x34200000: start of the heap							*/
linker_lnHeap				= (256K);																/* Length of the heap										*/

linker_stLCD_F_BUFFER		= (linker_stHeap + linker_lnHeap);										/* 0x34240000: Privileged/User LCD Frame Buffer 			*/
linker_lnLCD_F_BUFFER		= (1536K);																/* Length of the RAM										*/

/* IMPORTANT:												*/
/* equates necessary for the arm_v8 MPU regions				*/
/* for the arm_v8 MPU the regions have to be 32-B aligned	*/

linker_ST_RAM_INT_1			= (stm_stAXISRAM1);														/* 0x34000000: Privileged/User RAM							*/
linker_EN_RAM_INT_1			= (stm_stAXISRAM1 + stm_lnAXISRAM1 - 1);								/* 0x340FFFFF: 1-M											*/

linker_ST_RAM_INT_2_OS		= stm_stAXISRAM2;														/* 0x34100000: Privileged/User RAM							*/
linker_EN_RAM_INT_2_OS		= (stm_stAXISRAM2 + 96K - 1);											/* 0x34117FFF: 96-K											*/

linker_ST_RAM_INT_2			= linker_stPrgmData_u;													/* 0x34118000: Privileged/User RAM							*/
linker_EN_RAM_INT_2			= (linker_stPrgmData_u + 160K + 768K + 256K - 1);						/* 0x3423FFFF: 1184-K										*/

linker_ST_RAM_INT_3			= linker_stLCD_F_BUFFER;												/* 0x34240000: Privileged/User RAM							*/
linker_EN_RAM_INT_3			= (linker_stLCD_F_BUFFER + linker_lnLCD_F_BUFFER - 1);					/* 0x343BFFFF: 1536-K									*/

linker_ST_PERIPH_SOC		= stm_stPERIPH_NS;														/* 0x40000000: Privileged PERIPHERALS						*/
linker_EN_PERIPH_SOC		= (stm_stPERIPH_NS + 524288K - 1);										/* 0x5FFFFFFF: 2 x 256-M (_S & _NS)							*/

linker_ST_PERIPH_CORE		= stm_stCORE;															/* 0xE0000000: Privileged core PERIPHERALS					*/
linker_EN_PERIPH_CORE		= (stm_stCORE + 262144K - 1);											/* 0xEFFFFFFF: 256-M										*/

MEMORY {
	prgm_code (rwx)		: ORIGIN = linker_stPrgmCode, 	LENGTH = linker_lnPrgmCode
	prgm_data_p (rwx)	: ORIGIN = linker_stPrgmData_p, LENGTH = linker_lnPrgmData_p
	prgm_data_u (rwx)	: ORIGIN = linker_stPrgmData_u, LENGTH = linker_lnPrgmData_u
}

INCLUDE		system_pu.ld
