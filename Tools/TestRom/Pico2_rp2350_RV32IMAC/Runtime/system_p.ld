/*
; system_p.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		RISC-V system linker script for TestROM.
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

SECTIONS {
	. = ORIGIN(prgm_code);

	/* RISC-V vector table and startup code */
	.text_vectors ALIGN(4) : {
		linker_stVECTORS = ABSOLUTE(.);
		KEEP(*(.text_vectors))
		linker_enVECTORS = ABSOLUTE(.);
	} > prgm_code

	/* Picobin block for RISC-V boot */
	.picobin_block ALIGN(8) : {
		KEEP(*(.picobin_block))
	} > prgm_code

	/* Code section */
	.text : {
		linker_stTEXT = ABSOLUTE(.);
		*(.text .text.*)
		linker_enTEXT = ABSOLUTE(.);
	} > prgm_code

	/* Read-only data */
	.rodata : {
		. = ALIGN(4);
		linker_stRODATA = ABSOLUTE(.);
		*(.rodata .rodata.*)
		*(.srodata .srodata.*)  /* RISC-V small read-only data */
		. = ALIGN(4);
		linker_enRODATA = ABSOLUTE(.);
	} > prgm_code

	/* Initialized data (copied from flash to RAM at startup) */
	. = ALIGN(4);
	linker_stINDATA = ABSOLUTE(.);
	.data : AT (linker_stINDATA) {
		linker_stDATA = ABSOLUTE(.);
		*(.sdata .sdata.*)  /* RISC-V small data */
		*(.data .data.*)
		. = ALIGN(4);
		linker_enDATA = ABSOLUTE(.);
	} > prgm_data

	/* Uninitialized data (zeroed at startup) */
	.bss (NOLOAD) : {
		. = ALIGN(4);
		linker_stBSS = ABSOLUTE(.);
		*(.sbss .sbss.*)  /* RISC-V small BSS */
		*(.bss .bss.* COMMON)
		. = ALIGN(4);
		linker_enBSS = ABSOLUTE(.);
	} > prgm_data

	/* Global pointer for RISC-V (optional) */
	__global_pointer$ = MIN(linker_stDATA + 0x800, MAX(linker_stDATA + 0x800, linker_enBSS - 0x800));
}
