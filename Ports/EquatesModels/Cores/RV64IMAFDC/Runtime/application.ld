/*
; application.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Commun Linker description for uKOS-X applications.
;			User only support
;
;                   	CODE
; linker_stTEXT			+-----------------+
;						|                 |
;						| .header         |
;						| .text           |
; linker_stInitArray	+-----------------+
;						| .init_array     |
; linker_enInitArray	+-----------------+
; linker_stFiniArray	+-----------------+
;						| .fini_array     |
; linker_enFiniArray	+-----------------+
; linker_stRODATA		+-----------------+
;						|                 |
;						| .rodata         |
; linker_enRODATA		|                 |
; linker_stDATA			+-----------------+
;						|                 |
;						| .data           |
; linker_enDATA			|                 |
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

_lnApplication	= (linker_enDATA - linker_stTEXT);	/* Length of the application 	*/

SECTIONS {
	.text : {
		linker_stTEXT = ABSOLUTE(.);
		KEEP(*(.header))
		*(.text .text.*)
        *(.gnu.linkonce.t.*)
		linker_enTEXT = ABSOLUTE(.);
	} > prgm_code

	.init_array : {
		. = ALIGN(8);
		linker_stInitArray = ABSOLUTE(.);
		KEEP(*(SORT_BY_INIT_PRIORITY(.init_array.*)))
		KEEP(*(.init_array))
		linker_enInitArray = ABSOLUTE(.);
	} > prgm_code

	.fini_array : {
		. = ALIGN(8);
		linker_stFiniArray = ABSOLUTE(.);
		KEEP(*(SORT_BY_INIT_PRIORITY(.fini_array.*)))
		KEEP(*(.fini_array))
		linker_enFiniArray = ABSOLUTE(.);
	} > prgm_code

	.rodata : {
		. = ALIGN(8);
		linker_stRODATA = ABSOLUTE(.);
		*(.rodata .rodata.*)
		*(.rdata .rdata.*)
		*(.srodata .srodata.*)
		*(.gnu.linkonce.r.*)
		. = ALIGN(8);
		linker_enRODATA = ABSOLUTE(.);
	} > prgm_code

/* C++ / unwind support for RISC-V */

	.eh_frame_hdr : {
		. = ALIGN(8);
		*(.eh_frame_hdr)
		*(.eh_frame_hdr.*)
		. = ALIGN(8);
	} > prgm_code

	.eh_frame : {
		. = ALIGN(8);
		KEEP(*(.eh_frame))
		KEEP(*(.eh_frame.*))
		. = ALIGN(8);
	} > prgm_code

	.gcc_except_table : {
		. = ALIGN(8);
		*(.gcc_except_table)
		*(.gcc_except_table.*)
		. = ALIGN(8);
	} > prgm_code

	.data : {
		. = ALIGN(8);
		linker_stDATA = ABSOLUTE(.);
		*(.data .data.*)
		*(.sdata .sdata.*)
		*(.gnu.linkonce.d.*)
		. = ALIGN(8);
		linker_enDATA = ABSOLUTE(.);
	} > prgm_code

	.bss (NOLOAD) : {
		. = ALIGN(8);
		linker_stBSS = ABSOLUTE(.);
		KEEP(*(.user))
		*(.bss .bss.*)
		*(.sbss .sbss.*)
		*(.scommon)
		. = ALIGN(8);
		*(COMMON)
		. = ALIGN(8);
		linker_enBSS = ABSOLUTE(.);
	} > prgm_data

	_end = ABSOLUTE(.);

	/DISCARD/ : {
		*(.note .note.*)
		*(.comment)
		*(.comment.*)
		*(.riscv.attributes)
	}

}
