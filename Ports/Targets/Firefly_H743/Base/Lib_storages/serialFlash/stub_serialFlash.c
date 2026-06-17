/*
; stub_serialFlash.
; =================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2026-06-16
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the connection of the "serialFlash" manager device by qspi device.
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

#include	"uKOS.h"
#include	"W25Q128J/W25Q128J.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define	model_flash_qspi_init			stub_serialFlash_init
#define	model_flash_qspi_readStatus		stub_serialFlash_readStatus
#define	model_flash_qspi_initialise		stub_serialFlash_initialise
#define	model_flash_qspi_read			stub_serialFlash_read
#define	model_flash_qspi_write			stub_serialFlash_write
#define	model_flash_qspi_ioctl			stub_serialFlash_ioctl

#define	QSPI							QUADSPI
#define	KQSPI_SPEED						50000000u
#define	KQSPI_FREQUENCY					KFREQUENCY_AHB3
#define	KQSPI_READ_CHUNK				1024u

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the qspi
 *
 */
static	void	cb_enable(void) {

	RCC->AHB3ENR |= RCC_AHB3ENR_QSPIEN;
}

#include	"model_flash_qspi.c_inc"
