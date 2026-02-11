/*
; system_pu.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi			The 2025-01-01
; Modifs:	Laurent von Allmen	The 2025-01-01	Improved the section management
; Modifs:	Edo. Franzi			The 2025-01-01	Added the directory section
;
; Project:	uKOS-X
; Goal:		Commun Linker description for uKOS-X systems.
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

SECTIONS {
	.text : {
		linker_stCODE = ABSOLUTE(.);
		linker_stPRIV = ABSOLUTE(.);
		linker_stVECTORS = ABSOLUTE(.);
		KEEP(*(.isr_vector))
		linker_enVECTORS = ABSOLUTE(.);

		linker_stTEXT = ABSOLUTE(.);
		lib*_p.a(.text .text.* .text*)
		linker_stTEXT_KERN_p = ABSOLUTE(.);
		libkern_p.a(.text .text.* .text*)
		linker_enTEXT_KERN_p = ABSOLUTE(.);
		linker_enPRIV = ABSOLUTE(.);
		*(.text .text.*)
		linker_enTEXT = ABSOLUTE(.);
	} > prgm_code

	.directory : {
		linker_stDirectory = ABSOLUTE(.);
		KEEP(*(.directory))
		LONG(0x00000000)
		LONG(0x00000000)
	} > prgm_code

	.init_array : {
		. = ALIGN(8);
		linker_stInitArray = ABSOLUTE(.);
		KEEP(*(.init .init.* .init*))
		linker_enInitArray = ABSOLUTE(.);
	} > prgm_code

	.fini_array : {
		. = ALIGN(8);
		linker_stFiniArray = ABSOLUTE(.);
		KEEP(*(.fini .fini.* .fini*))
		linker_enFiniArray = ABSOLUTE(.);
	} > prgm_code

	/* New dedicated sections for ARM exception handling */
	.ARM.extab : {
		*(.ARM.extab*)
	} > prgm_code

	.ARM.exidx : {
		__exidx_start = .;
		*(.ARM.exidx*)
		__exidx_end = .;
	} > prgm_code

	.rodata : {
		. = ALIGN(8);
		linker_stRODATA = ABSOLUTE(.);
		linker_stRODATA_KERN_p = ABSOLUTE(.);
		libkern_p.a(.rodata .rodata.* .rodata*)
		linker_enRODATA_KERN_p = ABSOLUTE(.);
		*(.rodata .rodata.*)
		. = ALIGN(8);
		linker_enRODATA = ABSOLUTE(.);
	} > prgm_code

	. = ALIGN(8);
	linker_stINDATA_p = ABSOLUTE(.);
	.data_p : AT (linker_stINDATA_p) {
		linker_stDATA_p = ABSOLUTE(.);
		lib*_p.a(.data .data.* .data*)
		linker_stDATA_KERN_p = ABSOLUTE(.);
		libkern_p.a(.data .data.* .data*)
		linker_enDATA_KERN_p = ABSOLUTE(.);
		linker_enDATA_p = ABSOLUTE(.);
	} > prgm_data_p

	.bss_p (NOLOAD) : {
		. = ALIGN(8);
		linker_stBSS_p = ABSOLUTE(.);
		KEEP(*(.privileged))
		lib*_p.a(.bss .bss.* COMMON)
		linker_stBSS_KERN_p = ABSOLUTE(.);
		libkern_p.a(.bss .bss.* COMMON)
		linker_enBSS_KERN_p = ABSOLUTE(.);
		linker_enBSS_p = ABSOLUTE(.);
	} > prgm_data_p

	.stacks_p (NOLOAD) : {
		. = ALIGN(8);
		linker_lowStackSystem_C0 = ABSOLUTE(.);
		. += linker_sizeStackSystem_C0;
		. = ALIGN(8);
		linker_topStackSystem_C0 = ABSOLUTE(.) - 8;
	} > prgm_data_p

	linker_stINDATA_u = linker_stINDATA_p + SIZEOF(.data_p);
	. = ALIGN(8);
	.data_u : AT (linker_stINDATA_u) {
		linker_stDATA_u = ABSOLUTE(.);
		*(.data .data.* .data*)
		. = ALIGN(8);
		*(vtable)
		. = ALIGN(8);
		KEEP(*(.eh_frame))
		linker_enDATA_u = ABSOLUTE(.);
	} > prgm_data_u

	. = ALIGN(8);
	.signature (linker_enRODATA + (linker_enDATA_p - linker_stDATA_p) + (linker_enDATA_u - linker_stDATA_u)) : {
		linker_stSignature = ABSOLUTE(.);
		KEEP(*(.signature))
		linker_enCODE = ABSOLUTE(.);
	} > prgm_code

	.bss_u (NOLOAD) : {
		. = ALIGN(8);
		linker_stBSS_u = ABSOLUTE(.);
		KEEP(*(.user))
		*(.bss .bss.* COMMON)
		linker_enBSS_u = ABSOLUTE(.);
	} > prgm_data_u

	.stacks_u (NOLOAD) : {
		. = ALIGN(8);
		linker_lowStackFirst_C0 = ABSOLUTE(.);
		. += linker_sizeStackFirst_C0;
		. = ALIGN(8);
		linker_topStackFirst_C0 = ABSOLUTE(.) - 8;
	} > prgm_data_u

}
