/*
; lib_serials.
; ============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		lib_serials system call interface module.
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

/*!
 * \defgroup Lib_serials Library for Serial Communication Manager
 *
 * \brief Serial manager system calls
 *
 * The Lib_serials library offers managers for communication across many
 * channels. It unifies serial links and ensures that data flows with order.
 *
 * The serial manager provides a common foundation. It abstracts details,
 * so that higher layers may send and receive bytes without confusion.
 *
 * The urtx manager controls UART lines. It enables traditional serial I/O,
 * still essential in embedded design, debugging, and configuration.
 *
 * The cdcx manager extends serial links through USB CDC. By appearing as a
 * virtual port, it joins the flexibility of USB with the clarity of UART.
 *
 * The wfi0 manager opens the path to wireless. Using the ESP32 module, it
 * delivers Wi-Fi connectivity, bringing networks into embedded systems.
 *
 * Together these managers make Lib_serials a bridge between machines and
 * their environment. From a simple cable to a wireless link, all is aligned.
 *
 * @{
 */

// IWYU pragma: begin_exports

#if (defined(CONFIG_MAN_SERIAL_S))
#include	"serial/serial.h"
#else
#define	KDEF0	0
#endif
#if (defined(CONFIG_MAN_URT0_S))
#include	"urt0/urt0.h"
#endif
#if (defined(CONFIG_MAN_URT1_S))
#include	"urt1/urt1.h"
#endif
#if (defined(CONFIG_MAN_URT2_S))
#include	"urt2/urt2.h"
#endif
#if (defined(CONFIG_MAN_URT3_S))
#include	"urt3/urt3.h"
#endif
#if (defined(CONFIG_MAN_URT4_S))
#include	"urt4/urt4.h"
#endif
#if (defined(CONFIG_MAN_CDC0_S))
#include	"cdc0/cdc0.h"
#endif
#if (defined(CONFIG_MAN_CDC1_S))
#include	"cdc1/cdc1.h"
#endif
#if (defined(CONFIG_MAN_WFI0_S))
#include	"wfi0/wfi0.h"
#endif
#if (defined(CONFIG_MAN_BLE0_S))
#include	"ble0/ble0.h"
#endif

// IWYU pragma: end_exports

/**!@}*/
