/*
; pmp.
; ====
;
; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2026 Laurent von Allmen
;
;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-05-29
; Modifs:
;
; Project:	uKOS-X
; Goal:		RV32IMAC / Hazard3 (RP2350) – Physical Memory Protection (PMP) programming.
;
;	RP2350 specifics (verified against the pico-sdk rvcsr.h):
;	 - 8 dynamic PMP regions (0..7); regions 8..10 are hardwired.
;	 - TOR is NOT supported (A field: OFF / NA4 / NAPOT) — every region is NAPOT.
;	 - The cfg permission bits are TRANSPOSED (erratum RP2350-E6):
;	     X = bit0, W = bit1, R = bit2, A = bits[4:3], L = bit7.
;	   A textbook macro (R=bit0, X=bit2) would be subtly wrong on this SoC.
;	 - No Smepmp/mseccfg: with no matching region, M-mode is allowed and U-mode is
;	   denied. The table is therefore a U-grant list (kernel RAM gets no region and
;	   is U-inaccessible by default). Rules are left UNLOCKED (no L), so M-mode
;	   bypasses them — until user processes actually run in U-mode.
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

#pragma once

#include    <stdint.h>

#include    "Registers/rv32_csr.h"
#include    "core.h"                // IWYU pragma: keep (core_getCSR/core_putCSR used in SET_PMP_REGION)

// PMP cfg byte – RP2350-E6 transposed permission bits.

#define KPMP_X          (1U << 0)            // execute
#define KPMP_W          (1U << 1)            // write
#define KPMP_R          (1U << 2)            // read
#define KPMP_A_NAPOT    (3U << 3)            // naturally-aligned power-of-two region
#define KPMP_L          (1U << 7)            // lock (also enforces on M-mode) – unused for now

// Composite attributes (NAPOT + permissions, no lock).

#define KPMP_RWX_ALL    (KPMP_R | KPMP_W | KPMP_X | KPMP_A_NAPOT)
#define KPMP_RW_ALL     (KPMP_R | KPMP_W | KPMP_A_NAPOT)
#define KPMP_RX_ALL     (KPMP_R | KPMP_X | KPMP_A_NAPOT)
#define KPMP_NONE       (KPMP_A_NAPOT)       // present but no access -> U denied

// Select the cfg CSR holding a region's byte (0..3 -> PMPCFG0, 4..7 -> PMPCFG1).

#define KPMP_CFG_CSR(regionNb)  (((regionNb) < 4U) ? RV_CSR_PMPCFG0 : RV_CSR_PMPCFG1)

/*
 * Program one NAPOT PMP region.
 *   regionNb    literal 0..7 (must be a compile-time constant: CSR numbers are immediates)
 *   base        linker symbol token -> linker_##base (NAPOT base, size-aligned)
 *   napotLog2   literal log2(size in bytes), >= 3
 *   attr        KPMP_* composite
 */
#define SET_PMP_REGION(regionNb, base, napotLog2, attr)                                       \
    do {                                                                                      \
        extern uint8_t  linker_##base[];                                                      \
        const uintptr_t _b   = (uintptr_t)linker_##base;                                      \
        const uintptr_t _sz  = (uintptr_t)1U << (napotLog2);                                  \
        const uintptr_t _adr = (_b | ((_sz >> 1U) - 1U)) >> 2U;       /* NAPOT encode */      \
        const uint32_t  _sh  = (uint32_t)(((regionNb) & 3U) * 8U);                            \
        uint32_t        _cfg = core_getCSR(KPMP_CFG_CSR(regionNb));                           \
        _cfg = (_cfg & ~((uint32_t)0xFFU << _sh)) | ((uint32_t)(attr) << _sh);                \
        core_putCSR(RV_CSR_PMPADDR0 + (uint32_t)(regionNb), (uint32_t)_adr);                  \
        core_putCSR(KPMP_CFG_CSR(regionNb), _cfg);                                            \
        __asm volatile ("fence" ::: "memory");                                                \
    } while (0)

// Clear all dynamic regions (cfg = 0 => OFF) before (re)programming.

#define SET_PMP_DISABLE_ALL()                                                                 \
    do {                                                                                      \
        core_putCSR(RV_CSR_PMPCFG0, 0U);                                                      \
        core_putCSR(RV_CSR_PMPCFG1, 0U);                                                      \
        __asm volatile ("fence" ::: "memory");                                                \
    } while (0)
