/*
; stub_ble0_urt1.
; ===============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2026-05-12
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the connection of the "ble0" manager to the "urt1" manager.
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

// Connect the manager ble0 to the manager urt1
// --------------------------------------------

int32_t	stub_ble0_reserve(reserveMode_t reserveMode, uint32_t timeout) {

	return(urt1_reserve(reserveMode, timeout));
}

int32_t	stub_ble0_release(reserveMode_t reserveMode) {

	return(urt1_release(reserveMode));
}

int32_t	stub_ble0_configure(const urtxCnf_t *configure) {

	return(urt1_configure(configure));
}

int32_t	stub_ble0_write(const uint8_t *buffer, uint32_t size) {

	return(urt1_write(buffer, size));
}

int32_t	stub_ble0_read(uint8_t *buffer, uint32_t *size) {

	return(urt1_read(buffer, size));
}

int32_t	stub_ble0_getIdSemaphore(uint8_t semaphore, char_t **identifier) {

	return(urt1_getIdSemaphore(semaphore, identifier));
}

int32_t	stub_ble0_flush(void) {

	return(urt1_flush());
}
