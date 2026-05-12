/*
; stub_wfi0_urt2.
; ===============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2026-05-12
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the connection of the "wfi0" manager to the "urt2" manager.
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

// Connect the manager wfi0 to the manager urt2
// --------------------------------------------

int32_t	stub_wfi0_reserve(reserveMode_t reserveMode, uint32_t timeout) {

	return(urt2_reserve(reserveMode, timeout));
}

int32_t	stub_wfi0_release(reserveMode_t reserveMode) {

	return(urt2_release(reserveMode));
}

int32_t	stub_wfi0_configure(const urtxCnf_t *configure) {

	return(urt2_configure(configure));
}

int32_t	stub_wfi0_write(const uint8_t *buffer, uint32_t size) {

	return(urt2_write(buffer, size));
}

int32_t	stub_wfi0_read(uint8_t *buffer, uint32_t *size) {

	return(urt2_read(buffer, size));
}

int32_t	stub_wfi0_getIdSemaphore(uint8_t semaphore, char_t **identifier) {

	return(urt2_getIdSemaphore(semaphore, identifier));
}

int32_t	stub_wfi0_flush(void) {

	return(urt2_flush());
}
