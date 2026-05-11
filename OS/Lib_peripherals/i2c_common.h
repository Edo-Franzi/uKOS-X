/*
; i2c_commun.
; ===========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		i2c_commun equates.
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
 * \addtogroup Lib_peripherals
 */
/**@{*/

/*!
 * \defgroup i2c_commun I2c_commun
 *
 * \brief I2c_commun
 *
 * I2c_commun management
 *
 * @{
 */

// Configuration structure
// -----------------------

typedef	struct	i2cCnf	i2cCnf_t;

struct i2cCnf {
			uint32_t	oTimeout;								// I2C bus timeout in ms
			uint32_t	oSpeed;									// I2C speed in bit/s
};

// Speed (oSpeed)

enum {
			KI2C_100KBPS =	100000u,							// Sm, bus at 100-Kbit/s
			KI2C_400KBPS =	400000u,							// Fm, bus at 400-Kbit/s
			KI2C_1MBPS	 =	1000000u,							// Fm+, bus at 1-Mbit/s
			KI2C_17MBPS  =	1700000u,							// Hs, bus at 1.7-Mbit/s
			KI2C_34MBPS  =	3400000u,							// Hs, bus at 3.4-Mbit/s
			KI2C_5MBPS	 =	5000000u							// UFm, bus at 5-Mbit/s
};

/**@}*/
/**@}*/
