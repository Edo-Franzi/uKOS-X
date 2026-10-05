/*
; system_pu-riscv.
; ================
;
; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
;
;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-05-29
; Modifs:
;
; Project:	uKOS-X
; Goal:		RV32IMAC / Hazard3 (RP2350) – Common section layout for uKOS-X,
;			privileged/user (_pu) split
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
; 														| .bss            |
;														| COMMON          |
;														|                 | linker_enBSS
;														+-----------------+
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

    .vectors ALIGN(64) : {
        linker_stVECTORS = ABSOLUTE(.);
        KEEP(*(.isr_vector))
        linker_enVECTORS = ABSOLUTE(.);
    } > prgm_code

    .picobin_block ALIGN(8) : {
        KEEP(*(.picobin_block))
    } > prgm_code

    .text : {
        linker_stCODE = ABSOLUTE(.);
        linker_stTEXT = ABSOLUTE(.);
        linker_stTEXT_KERN_p = ABSOLUTE(.);
        libkern_p.a:*(.text .text.*)
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
        libkern_p.a:*(.rodata .rodata.*)
        linker_enRODATA_KERN_p = ABSOLUTE(.);
        *(.rodata .rodata.*)
        *(.srodata .srodata.*)
        *(.rdata .rdata.*)
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

    .signature : {
        . = ALIGN(4);
        linker_stSignature = ABSOLUTE(.);
        KEEP(*(.signature))
        . = ALIGN(4);
        linker_enCODE = ABSOLUTE(.);
    } > prgm_code

    /* Privileged data/bss: kernel + every lib*_p.a -> prgm_data_p */
    . = ALIGN(4);
    linker_stINDATA_p = ABSOLUTE(.);
    .data_p : AT (linker_stINDATA_p) {
        . = ALIGN(4);
        linker_stDATA_p = ABSOLUTE(.);
        linker_stDATA_KERN_p = ABSOLUTE(.);
        libkern_p.a:*(.data .data.*)
        libkern_p.a:*(.sdata .sdata.*)
        linker_enDATA_KERN_p = ABSOLUTE(.);
        lib*_p.a:*(.data .data.*)
        lib*_p.a:*(.sdata .sdata.*)
        . = ALIGN(4);
        linker_enDATA_p = ABSOLUTE(.);
    } > prgm_data_p

    .bss_p (NOLOAD) : {
        . = ALIGN(4);
        linker_stBSS_p = ABSOLUTE(.);
        KEEP(*(.privileged))
        linker_stBSS_KERN_p = ABSOLUTE(.);
        libkern_p.a:*(.bss .bss.*)
        libkern_p.a:*(.sbss .sbss.*)
        linker_enBSS_KERN_p = ABSOLUTE(.);
        lib*_p.a:*(.bss .bss.*)
        lib*_p.a:*(.sbss .sbss.*)
        . = ALIGN(4);
        linker_enBSS_p = ABSOLUTE(.);
    } > prgm_data_p AT> prgm_data_p

    /* User data/bss: everything except lib*_p.a -> prgm_data_u */
    linker_stINDATA_u = LOADADDR(.data_p) + SIZEOF(.data_p);
    .data_u : AT (linker_stINDATA_u) {
        . = ALIGN(4);
        linker_stDATA_u = ABSOLUTE(.);
        *(EXCLUDE_FILE (lib*_p.a:*) .data .data.*)
        *(EXCLUDE_FILE (lib*_p.a:*) .sdata .sdata.*)
        *(.tdata .tdata.*)
        . = ALIGN(4);
        *(vtable)
        . = ALIGN(4);
        linker_enDATA_u = ABSOLUTE(.);
    } > prgm_data_u

    .bss_u (NOLOAD) : {
        . = ALIGN(4);
        linker_stBSS_u = ABSOLUTE(.);
        KEEP(*(.user))
        *(EXCLUDE_FILE (lib*_p.a:*) .bss .bss.*)
        *(EXCLUDE_FILE (lib*_p.a:*) .sbss .sbss.*)

/* COMMON cannot be split reliably between _p and _u here. */

        *(COMMON)
        . = ALIGN(4);
        linker_enBSS_u = ABSOLUTE(.);
    } > prgm_data_u AT> prgm_data_u

    /* Thread-local storage BSS section - treated as regular BSS for bare-metal */
    .tbss (NOLOAD) : {
        linker_stTBSS = ABSOLUTE(.);
        *(.tbss .tbss.*)
        linker_enTBSS = ABSOLUTE(.);
        /* Standard symbol used by C library for heap start */
        end = ABSOLUTE(.);
        _end = ABSOLUTE(.);
    } > prgm_data_u

    /* gp: under -msmall-data-limit=0 (enforced for _pu) no .sdata/.sbss is emitted and
       the prebuilt libraries use absolute addressing, so gp is never used to reach data.
       The symbol is still referenced by the "la gp,__global_pointer$" reload in first.c. */
    __global_pointer$ = linker_stDATA_p + 0x800;

/* Fail if some BSS/DATA still escape into orphan sections */

    .orphans_check (NOLOAD) : {
        *(.bss)
        *(.bss.*)
        *(.gnu.linkonce.b.*)
        *(.sbss)
        *(.sbss.*)
        *(.data)
        *(.data.*)
        *(.gnu.linkonce.d.*)
        *(.sdata)
        *(.sdata.*)
    } > prgm_data_u

    ASSERT(SIZEOF(.orphans_check) == 0, "Unexpected orphan .bss/.data sections: _p/_u split is incomplete")
}
