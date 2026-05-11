/*
; serial_commun.
; ==============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		serial_commun equates.
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
 * \addtogroup Lib_serials
 */
/**@{*/

/*!
 * \defgroup serial_commun Serial_commun
 *
 * \brief Serial_commun
 *
 * Serial_commun management
 *
 * @{
 */

// Configuration structure
// -----------------------

typedef	struct	urtxCnf		urtxCnf_t;
typedef	struct	cdcxCnf		cdcxCnf_t;

struct urtxCnf {
			uint8_t		oNBBits;								// Number of bits
			uint8_t		oStopBits;								// Number of stop bits
			uint8_t		oParity;								// Parity
			uint8_t		oBaudRate;								// Baudrate
			uint8_t		oKernSync;								// uKernel synchro
};

struct cdcxCnf {
			uint8_t		oKernSync;								// uKernel synchro
};

// Number of bits (oNBBits)

enum {
			KSERIAL_NB_BITS_7 = 0u,								// Word of 7-bits
			KSERIAL_NB_BITS_8									// Word of 8-bits
};

// Number of stop bits (oStopBits)

enum {
			KSERIAL_STOPBITS_1 = 0u,							// 1-stop bits
			KSERIAL_STOPBITS_2									// 2-stop bits
};

// Parity (oParity)

enum {
			KSERIAL_PARITY_NONE = 0u,							// No Parity
			KSERIAL_PARITY_EVEN,								// Parity even
			KSERIAL_PARITY_ODD									// Parity odd

};

// Baudrates (oBaudRate)

enum {
			KSERIAL_BAUDRATE_DEFAULT = 0u,						// Default baudrate
			KSERIAL_BAUDRATE_2400,								// 2400-bit/s
			KSERIAL_BAUDRATE_4800,								// 4800-bit/s
			KSERIAL_BAUDRATE_9600,								// 9600-bit/s
			KSERIAL_BAUDRATE_19200,								// 19200-bit/s
			KSERIAL_BAUDRATE_38400,								// 38400-bit/s
			KSERIAL_BAUDRATE_57600,								// 57600-bit/s
			KSERIAL_BAUDRATE_115200,							// 115200-bit/s
			KSERIAL_BAUDRATE_230400,							// 230400-bit/s
			KSERIAL_BAUDRATE_460800,							// 460800-bit/s
			KSERIAL_BAUDRATE_500000,							// 500000-bit/s
			KSERIAL_BAUDRATE_921600,							// 921600-bit/s
			KSERIAL_BAUDRATE_1000000,							// 1000000-bit/s
			KSERIAL_BAUDRATE_1500000,							// 1500000-bit/s
			KSERIAL_BAUDRATE_1843200,							// 1843200-bit/s
			KSERIAL_BAUDRATE_2000000,							// 2000000-bit/s
			KSERIAL_BAUDRATE_2500000,							// 2500000-bit/s
			KSERIAL_BAUDRATE_3000000							// 3000000-bit/s
};

// Kernel synchro semaphores (oKernSync)

enum {
			BSERIAL_SEMAPHORE_RX = 0u,							// RX semaphore
			BSERIAL_SEMAPHORE_TX								// TX semaphore
};

/**@}*/
/**@}*/
