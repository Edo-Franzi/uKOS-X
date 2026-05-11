/*
; soc_addendum_application.
; =========================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		addendum equates.
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

#pragma	once

// gpio additional definitions
// ---------------------------

#define	KPIN_APPCPU							GPIO_PIN_CNF_MCUSEL_APPMCU
#define	KPIN_NETCPU							GPIO_PIN_CNF_MCUSEL_NETWORKMCU
#define	KPIN_PERIPH							GPIO_PIN_CNF_MCUSEL_PERIPHERAL
#define	KPIN_TND							GPIO_PIN_CNF_MCUSEL_TND

#define	KSENS_DISABLE						GPIO_PIN_CNF_SENSE_DISABLED
#define	KSENS_HIGH							GPIO_PIN_CNF_SENSE_HIGH
#define	KSENS_LOW							GPIO_PIN_CNF_SENSE_LOW

#define	KDRIVE_S0S1							GPIO_PIN_CNF_DRIVE_S0S1
#define	KDRIVE_H0S1							GPIO_PIN_CNF_DRIVE_H0S1
#define	KDRIVE_S0H1							GPIO_PIN_CNF_DRIVE_S0H1
#define	KDRIVE_H0H1							GPIO_PIN_CNF_DRIVE_H0H1
#define	KDRIVE_D0S1							GPIO_PIN_CNF_DRIVE_D0S1
#define	KDRIVE_D0H1							GPIO_PIN_CNF_DRIVE_D0H1
#define	KDRIVE_S0D1							GPIO_PIN_CNF_DRIVE_S0D1
#define	KDRIVE_H0D1							GPIO_PIN_CNF_DRIVE_H0D1
#define	KDRIVE_E0E1							GPIO_PIN_CNF_DRIVE_E0E1

#define	KPULL_DISABLE						GPIO_PIN_CNF_PULL_DISABLED
#define	KPULL_DOWN							GPIO_PIN_CNF_PULL_PULLDOWN
#define	KPULL_UP							GPIO_PIN_CNF_PULL_PULLUP

#define	KINPUT_CONNECT						GPIO_PIN_CNF_INPUT_CONNECT
#define	KINPUT_DISCONNECT					GPIO_PIN_CNF_INPUT_DISCONNECT

#define	KDIR_INPUT							GPIO_PIN_CNF_DIR_INPUT
#define	KDIR_OUTPUT							GPIO_PIN_CNF_DIR_OUTPUT
