/*
; stub_sdcard.
; ============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the connection of the "sdcard" manager with the SDMMC1 device.
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

#undef	WITH_SD_INSERTED_S

// Connect the physical device to the logical manager
// --------------------------------------------------

#define	SDMMC						SDMMC1
#define	SDMMC_FREQUENCY				KFREQUENCY_PLL1Q

#define	model_sdcard_init			stub_sdcard_init
#define	model_sdcard_readStatus		stub_sdcard_readStatus
#define	model_sdcard_initialise		stub_sdcard_initialise
#define	model_sdcard_read			stub_sdcard_read
#define	model_sdcard_write			stub_sdcard_write
#define	model_sdcard_ioctl			stub_sdcard_ioctl

enum {
		KSDCARD_INIT = 0u,
};

// Model callbacks
// ---------------

/*
 * \brief cb_control
 *
 * - Control of the SDMMC interface
 *   - Initialise
 *
 */
static	void	cb_control(uint8_t mode) {

	UNUSED(mode);

	RCC->AHB3ENR |= RCC_AHB3ENR_SDMMC1EN;
}

#include	"model_sdcard_SDMMC.c_inc"
