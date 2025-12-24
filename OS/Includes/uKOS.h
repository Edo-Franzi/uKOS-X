/*
; uKOS.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi			The 2025-01-01
; Modifs:   Laurent von Allmen	The 2025-01-01
;
; Project:	uKOS-X
; Goal:		Universal h file for uKOS-X systems.
;
;   (c) 2025-20xx, Edo. Franzi
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

#pragma	once

// IWYU pragma: begin_exports

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<inttypes.h>

#include	"types.h"
#include	"os_errors.h"
#include	"board.h"
#include	"clockTree.h"
#include	"ip.h"
#include	"core_reg.h"
#include	"soc_reg.h"
#include	"syscallDispatcher.h"
#include	"macros.h"
#include	"macros_soc.h"
#include	"macros_core.h"
#include	"macros_runtime.h"
#include	"core.h"
#include	"modules.h"
#include	"crt0.h"
#include	"spin.h"
#include	"lib_kernels.h"
#include	"lib_generics.h"
#include	"lib_serials.h"
#include	"lib_peripherals.h"
#include	"lib_neurals.h"
#include	"lib_cryptographics.h"
#include	"lib_storages.h"
#include	"debug.h"

// IWYU pragma: end_exports

// uKOS-X main constants
// -----------------------

#define	uKOS_VERSION_OS			10
#define	uKOS_VERSION_NUMBER		"0.1.214"
#define	uKOS_VERSION_MAJOR		0
#define	uKOS_VERSION_MINOR		1
#define	uKOS_VERSION_PATCH		214
#define	uKOS_VERSION			uKOS_VERSION_NUMBER " " STRG(uKOS_NAME) "\n" STRG(uKOS_OWNER)
