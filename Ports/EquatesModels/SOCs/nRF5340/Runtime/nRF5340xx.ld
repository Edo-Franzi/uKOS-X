/*
; nRF5340xx.
; ==========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Specs of STM32U5A5xJ.
;			References:
;			- nRF5340 Rev 1.3, p. 21; Product Specification
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

nrf_stINTFLASH_APP		= 0x00000000;												/* 0x00000000: Starting address of internal flash APP		*/
nrf_lnINTFLASH_APP		= (1024K);													/* Size of memory bank APP									*/
nrf_stINTFLASH_NET		= 0x01000000;												/* 0x01000000: Starting address of internal flash NET		*/
nrf_lnINTFLASH_NET		= (256K);													/* Size of memory bank NET									*/

nrf_stSRAM				= 0x20000000;												/* 0x20000000: Starting address of SRAM (APP + NET)			*/
nrf_lnSRAM				= (512K);													/* Length of internal memory SRAM							*/

nrf_stSRAM_NET			= 0x21000000;												/* 0x21000000: Starting address of SRAM_NET					*/
nrf_lnSRAM_NET			= (64K);													/* Length of internal memory SRAM_NET						*/

nrf_stPERIPH_NS			= 0x40000000;												/*															*/
nrf_stPERIPH_S			= 0x50000000;												/*															*/
nrf_lnPERIPH			= 0x10000000;												/*															*/
nrf_stCORE				= 0xE0000000;												/*															*/
nrf_lnCORE				= 0x20000000;												/* Defined by the ARM cortex-M specification				*/
