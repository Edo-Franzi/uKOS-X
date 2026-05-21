/*
; STM32F207xx.
; ============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Specs of STM32F207xx.
;			References:
;			- DS6329 Rev 17, p. 67; Datasheet
;			- RM0433 Rev 8, p. 59; STM32F205xx, STM32F207x, STM32F215xx and STM32F217xx advanced Arm®-based 32-bit MCUs
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

stm_stINTFLASH			= 0x08000000;												/* 0x08000000: starting address of internal flash of SOC	*/
stm_lnINTFLASH			= (1024K);													/* Size of internal flash									*/

stm_stSRAM1				= 0x20000000;												/* 0x20000000: Starting address of SRAM1					*/
stm_lnSRAM1				= (112K);													/* Length of internal memory SRAM1							*/

stm_stSRAM2				= 0x2001C000;												/* 0x2001C000: Starting address of SRAM2					*/
stm_lnSRAM2				= (16K);													/* Length of internal memory SRAM2							*/
stm_lnSRAM12			= (stm_lnSRAM1 + stm_lnSRAM2);

stm_stPERIPH			= 0x40000000;												/*															*/
stm_lnPERIPH			= 0x20000000;												/*															*/
stm_stCORE				= 0xE0000000;												/*															*/
stm_lnCORE				= 0x20000000;												/* Defined by the ARM cortex-M specification				*/
