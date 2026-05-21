/*
; STM32U5G9xJ.
; ============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Specs of STM32U5G9xJ.
;			References:
;			- DS14102 Rev 1, p. 27; Datasheet
;			- RM0456 Rev 5, p. 143; STM32U5 Series Arm®-based 32-bit MCUs
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

stm_stINTFLASH			= 0x0C000000;												/* 0x0C000000: Starting address of internal flash of SOC	*/
stm_lnINTFLASH			= (4096K);													/* Size of internal flash									*/

/* Six SRAMs are embedded, each with specific features.		*/
/* SRAM1, SRAM2, SRAM3 and SRAM5 are the main SRAMs.		*/
/* SRAM4 is in the SRAM used for peripherals LPBAM			*/
/* (low-power background autonomous mode) in Stop 2 mode.	*/

stm_stSRAM1				= 0x30000000;												/* 0x30000000: Starting address of SRAM1					*/
stm_lnSRAM1				= (768K);													/* Length of internal memory SRAM1							*/

stm_stSRAM2				= (stm_stSRAM1 + stm_lnSRAM1);								/* 0x300C0000: Starting address of SRAM2					*/
stm_lnSRAM2				= (64K);													/* Length of internal memory SRAM2							*/
stm_lnSRAM12			= (stm_lnSRAM1 + stm_lnSRAM2);

stm_stSRAM3				= (stm_stSRAM2 + stm_lnSRAM2);								/* 0x300D0000: Starting address of SRAM3					*/
stm_lnSRAM3				= (832K);													/* Length of internal memory SRAM3							*/
stm_lnSRAM123			= (stm_lnSRAM12 + stm_lnSRAM3);

stm_stSRAM4				= 0x38000000;												/* 0x38000000: Starting address of SRAM4					*/
stm_lnSRAM4				= (16K);													/* Length of internal memory SRAM4							*/

stm_stSRAM5				= (stm_stSRAM3 + stm_lnSRAM3);								/* 0x301A0000: Starting address of SRAM5					*/
stm_lnSRAM5				= (832K);													/* Length of internal memory SRAM5							*/

stm_stSRAM6				= (stm_stSRAM5 + stm_lnSRAM5);								/* 0x30270000: Starting address of SRAM6					*/
stm_lnSRAM6				= (512K);													/* Length of internal memory SRAM6							*/

stm_stPERIPH_NS			= 0x40000000;												/*															*/
stm_stPERIPH_S			= 0x50000000;												/*															*/
stm_lnPERIPH			= 0x10000000;												/*															*/
stm_stCORE				= 0xE0000000;												/*															*/
stm_lnCORE				= 0x20000000;												/* Defined by the ARM cortex-M specification				*/
