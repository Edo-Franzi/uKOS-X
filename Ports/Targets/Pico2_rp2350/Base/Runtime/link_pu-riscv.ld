/*
; link_pu-riscv.
; ==============
;
; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2026 Laurent von Allmen
;
;------------------------------------------------------------------------
; Author:	Laurent von Allmen		The 2026-05-29
; Modifs:
;
; Project:	uKOS-X
; Goal:		Linker description for the uKOS-X system.
;			RISC-V (RV32IMAC/Hazard3) linker memory regions, privileged/user mode.
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

INCLUDE     rp2350.ld

/* Mapping:                                                 */
/*                                                          */
/* SRAM:     Stack System        0x20000000  (Privileged)   */
/*            └ 8K                                          */
/*           Program Data        0x20002000  (Privileged)   */
/*            └ 120K                                        */
/*           Stack First         0x20020000  (User)         */
/*            └ 4K                                          */
/*           Program Data        0x20021000  (User)         */
/*            └ 60K                                         */
/*           Heap                0x20030000  (User)         */
/*            └ 128K                                        */
/*           User Memory         0x20050000  (User)         */
/*            └ 136K                                        */
/*           Share               0x20072000  (User)         */
/*            └ 64K                                         */

linker_sizeStackSystem_C0   = (4K);                                                         /* Length of the System stack                               */
linker_sizeStackFirst_C0    = (2K);                                                         /* Length of the First stack                                */
linker_sizeStackSystem_C1   = (4K);                                                         /* Length of the System stack                               */
linker_sizeStackFirst_C1    = (2K);                                                         /* Length of the First stack                                */
config_sizeData_p           = (120K);
config_sizeData_u           = (60K);
config_sizeHeap             = (128K);
config_sizeUserMemory       = (136K);
config_sizeShare            = (64K);

/* PMP NAPOT domain split (consumed by the PMP setup). */
config_sizePrivDomain       = (128K);

/* Privileged domain: System stacks (M-mode trap stacks) then prgm_data_p. */

linker_lowStackSystem_C0    = rp_stSRAM;                                                    /* 0x20000000: start of the System stack                    */
linker_topStackSystem_C0    = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0 - 8;     /* 0x20000ff8                                               */

linker_lowStackSystem_C1    = linker_lowStackSystem_C0 + linker_sizeStackSystem_C0;         /* 0x20001000: start of the System stack                    */
linker_topStackSystem_C1    = linker_lowStackSystem_C1 + linker_sizeStackSystem_C1 - 8;     /* 0x20001ff8                                               */

/* User domain: First stacks then prgm_data_u, heap, user memory, shared. */

linker_lowStackFirst_C0     = linker_lowStackSystem_C1 + linker_sizeStackSystem_C1
                                + config_sizeData_p;                                        /* 0x20020000: start of the First stack                     */
linker_topStackFirst_C0     = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0 - 8;       /* 0x200207f8                                               */

linker_lowStackFirst_C1     = linker_lowStackFirst_C0 + linker_sizeStackFirst_C0;           /* 0x20020800: start of the First stack                     */
linker_topStackFirst_C1     = linker_lowStackFirst_C1 + linker_sizeStackFirst_C1 - 8;       /* 0x20020ff8                                               */

ASSERT((linker_lowStackSystem_C0 & 7) == 0, "System stack must be 8-byte aligned")
ASSERT((linker_topStackSystem_C0 & 7) == 0, "System stack must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C0 & 7)  == 0, "First stack must be 8-byte aligned")
ASSERT((linker_topStackFirst_C0 & 7)  == 0, "First stack must be 8-byte aligned")
ASSERT((linker_lowStackSystem_C1 & 7) == 0, "System stack must be 8-byte aligned")
ASSERT((linker_topStackSystem_C1 & 7) == 0, "System stack must be 8-byte aligned")
ASSERT((linker_lowStackFirst_C1 & 7)  == 0, "First stack must be 8-byte aligned")
ASSERT((linker_topStackFirst_C1 & 7)  == 0, "First stack must be 8-byte aligned")

/* External memory, user (download application) and shared. */

linker_stEXRAM              = 0;                                                            /* No external memory                                       */
linker_lnEXRAM              = (0);

linker_stUMemo              = (linker_stHeap + linker_lnHeap);                              /* 0x20050000: UMemo, start of the user memory              */
linker_lnUMemo              = config_sizeUserMemory;                                        /* 0x00022000: Length of the user memory                    */

linker_stShare              = (linker_stUMemo + linker_lnUMemo);                            /* 0x20072000: Share, start of the multicore shared memory  */
linker_lnShare              = config_sizeShare;                                             /* 0x00010000: Length of the user multicore shared memory   */

linker_stHeap               = linker_stPrgmData_u + config_sizeData_u;                      /* 0x20030000: start of the heap                            */
linker_lnHeap               = config_sizeHeap;                                              /* 0x00020000: Length of the heap                           */

/* IMPORTANT:                                               */
/* uKOS OS Flash + memory                                   */

linker_stPrgmCode           = rp_stINTFLASH;                                                /* 0x10000000: PrgmCode, start of the Flash                 */
linker_lnPrgmCode           = rp_lnINTFLASH;                                                /* 0x00400000: Length of the the Flash                      */

linker_stPrgmData_p         = linker_lowStackSystem_C1 + linker_sizeStackSystem_C1;         /* 0x20002000: start of protected program data              */
linker_lnPrgmData_p         = config_sizeData_p;                                            /* 120K -> 0x2001FFFF                                       */

linker_stPrgmData_u         = linker_lowStackFirst_C1 + linker_sizeStackFirst_C1;           /* 0x20021000: start of unprotected program data            */
linker_lnPrgmData_u         = config_sizeData_u;                                            /* 60K -> 0x2002FFFF                                        */

/* PMP NAPOT region bases (PMP partition). The user domain (392 KiB) is covered by
   three NAPOT regions; flash is one. Kernel RAM (0x20000000..0x2001FFFF) is granted no
   region and is U-inaccessible by default. */

linker_ST_USER_RAM_0        = linker_lowStackFirst_C0;                                      /* 0x20020000: 128 KiB */
linker_ST_USER_RAM_1        = linker_lowStackFirst_C0 + (128K);                             /* 0x20040000: 256 KiB */
linker_ST_USER_RAM_2        = linker_lowStackFirst_C0 + (384K);                             /* 0x20080000: 8 KiB   */
linker_ST_FLASH_INT_0       = rp_stINTFLASH;                                                /* 0x10000000: 4 MiB   */

ASSERT((linker_ST_USER_RAM_0 & (128K - 1)) == 0, "PMP user region 0 must be 128K NAPOT-aligned")
ASSERT((linker_ST_USER_RAM_1 & (256K - 1)) == 0, "PMP user region 1 must be 256K NAPOT-aligned")
ASSERT((linker_ST_USER_RAM_2 & (8K - 1))   == 0, "PMP user region 2 must be 8K NAPOT-aligned")
ASSERT((linker_ST_FLASH_INT_0 & (4M - 1))  == 0, "PMP flash region must be 4M NAPOT-aligned")
ASSERT((linker_ST_USER_RAM_0) == (linker_stPrgmData_p + linker_lnPrgmData_p), "PMP user regions must start at the user-domain boundary")
ASSERT((linker_ST_USER_RAM_2 + (8K)) == (rp_stSRAM + rp_lnSRAM1), "PMP user regions must cover the user domain up to end of SRAM")

MEMORY {
    prgm_code   (rx)    : ORIGIN = linker_stPrgmCode,   LENGTH = linker_lnPrgmCode
    prgm_data_p (rwx)   : ORIGIN = linker_stPrgmData_p, LENGTH = linker_lnPrgmData_p
    prgm_data_u (rwx)   : ORIGIN = linker_stPrgmData_u, LENGTH = linker_lnPrgmData_u
}

/* PMP NAPOT requires each region naturally aligned to its (power-of-two) size.
   The privileged domain is one 128 KiB NAPOT region; the user domain begins on the
   next 128 KiB boundary so it can be covered by NAPOT regions in R3. */

ASSERT((rp_stSRAM & (config_sizePrivDomain - 1)) == 0, "Privileged domain base must be 128K NAPOT-aligned")
ASSERT((linker_lowStackFirst_C0 & (config_sizePrivDomain - 1)) == 0, "User domain must start on a 128K NAPOT boundary")
ASSERT((linker_stPrgmData_p + linker_lnPrgmData_p) == linker_lowStackFirst_C0, "prgm_data_p must fill the privileged domain up to the user boundary")

INCLUDE     system_pu-riscv.ld
