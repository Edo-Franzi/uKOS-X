/*
; system_p.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi			The 2025-01-01
; Modifs:	Laurent von Allmen	The 2025-01-01	libkern_p.a*(...) to libkern_p.a(...)
; Modifs:	Edo. Franzi			The 2025-01-01	Added the directory section
;
; Project:	uKOS-X
; Goal:		Common Linker description for uKOS-X systems.
;			Privileged only support
;
;                       CODE
; linker_stTEXT			+-----------------+
;						|                 |
;						| .restart        |
;						| .vectors        |
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
; 														| .bss            |
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

SECTIONS {
	.text : {
		KEEP(*(.restart))
		linker_stVECTORS = ABSOLUTE(.);
		KEEP(*(.vectors))
		linker_enVECTORS = ABSOLUTE(.);

		linker_stTEXT = ABSOLUTE(.);
		linker_stTEXT_KERN_p = ABSOLUTE(.);
		libkern_p.a:*(.text .text.* .text*)
		linker_enTEXT_KERN_p = ABSOLUTE(.);
		*(.text .text.*)
		. = ALIGN(4);
		linker_enTEXT = ABSOLUTE(.);
	} > prgm_code

	.directory : {
		. = ALIGN(4);
		linker_stDirectory = ABSOLUTE(.);
		KEEP(*(.directory))
		LONG(0x00000000)
		LONG(0x00000000)
		. = ALIGN(4);
		linker_enDirectory = ABSOLUTE(.);
	} > prgm_code

	.init_array : {
		. = ALIGN(4);
		linker_stInitArray = ABSOLUTE(.);
		KEEP(*(SORT_BY_INIT_PRIORITY(.init_array.*)))
		KEEP(*(.init_array))
		. = ALIGN(4);
		linker_enInitArray = ABSOLUTE(.);
	} > prgm_code

	.fini_array : {
		. = ALIGN(4);
		linker_stFiniArray = ABSOLUTE(.);
		KEEP(*(SORT_BY_INIT_PRIORITY(.fini_array.*)))
		KEEP(*(.fini_array))
		. = ALIGN(4);
		linker_enFiniArray = ABSOLUTE(.);
	} > prgm_code

	.rodata : {
		. = ALIGN(4);
		linker_stRODATA = ABSOLUTE(.);
		linker_stRODATA_KERN_p = ABSOLUTE(.);
		libkern_p.a:*(.rodata .rodata.* .rodata*)
		linker_enRODATA_KERN_p = ABSOLUTE(.);
		*(.rodata .rodata.*)
		*(.srodata .srodata.*)
		*(.rdata .rdata.*)
		KEEP(*(.eh_frame))
		. = ALIGN(4);
		linker_enRODATA = ABSOLUTE(.);
	} > prgm_code

	.widget : {
		. = ALIGN(4);
		linker_stWIDGET = ABSOLUTE(.);
		KEEP(*(.widget))
		. = ALIGN(4);
		linker_enWIDGET = ABSOLUTE(.);
	} > prgm_code

	. = ALIGN(4);
	linker_stINDATA = ABSOLUTE(.);

	.stacks (NOLOAD) : {
		. = ALIGN(16);
		linker_lowStackFirst_C0 = ABSOLUTE(.);
		. += linker_sizeStackFirst_C0;
		. = ALIGN(16);
		linker_topStackFirst_C0 = ABSOLUTE(.) - 16;

		. = ALIGN(16);
		linker_lowStackSystem_C0 = ABSOLUTE(.);
		. += linker_sizeStackSystem_C0;
		. = ALIGN(16);
		linker_topStackSystem_C0 = ABSOLUTE(.) - 16;
	} > prgm_data

	.data : AT (linker_stINDATA) {
		. = ALIGN(4);
		linker_stDATA = ABSOLUTE(.);
		linker_stDATA_KERN_p = ABSOLUTE(.);
		libkern_p.a:*(.data .data.* .data*)
		linker_enDATA_KERN_p = ABSOLUTE(.);
		*(.sdata .sdata.*)
		*(.data .data.*)
		. = ALIGN(4);
		linker_enDATA = ABSOLUTE(.);
	} > prgm_data

	.signature (LOADADDR(.data) + SIZEOF(.data)) : {
		. = ALIGN(4);
		linker_stSignature = ABSOLUTE(.);
		KEEP(*(.signature))
		. = ALIGN(4);
		linker_enCODE = ABSOLUTE(.);
	} > prgm_code

	.bss (NOLOAD) : {
		. = ALIGN(4);
		linker_stBSS = ABSOLUTE(.);
		KEEP(*(.user))
		linker_stBSS_KERN_p = ABSOLUTE(.);
		libkern_p.a:*(.bss .bss.*)
		linker_enBSS_KERN_p = ABSOLUTE(.);
		*(.sbss*)
		*(.bss .bss.*)
		*(COMMON)
		. = ALIGN(4);
		linker_enBSS = ABSOLUTE(.);
	} > prgm_data

	_end = ABSOLUTE(.);
}
