/*
; stub_temperature_stts22h.
; =========================

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the connection of the "temperature" manager to the stts22h
;			via the i2c1 device.
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
#include	"STTS22H/STTS22H.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define	model_stts22h_init		stub_temperature_init
#define	model_stts22h_read		stub_temperature_read
#define	model_stts22h_write		stub_temperature_write

static	void	cb_readI2C(uint8_t address, uint8_t *buffer, uint16_t number);
static	void	cb_writeI2C(uint8_t address, const uint8_t *buffer, uint16_t number);

// Model callbacks
// ---------------

/*
 * \brief cb_configure
 *
 * - Configure of the I2C & the stts22h
 *
 */
static	void	cb_configure(void) {
	static	bool		vInit = false;
	const	i2cCnf_t	configureI2C1 = {
							.oTimeout  = 1000u,
							.oSpeed    = KI2C_400KBPS,
						};

	if (vInit == false) {
		vInit = true;

		RESERVE(I2C1, KMODE_READ_WRITE);
		i2c_configure(KI2C1, &configureI2C1);
		RELEASE(I2C1, KMODE_READ_WRITE);
	}
}

/*
 * \brief cb_writeI2C
 *
 * - Write to the i2c
 *
 */
static	void	cb_writeI2C(uint8_t address, const uint8_t *buffer, uint16_t number) {

	RESERVE(I2C1, KMODE_READ_WRITE);
	i2c_write(KI2C1, address, buffer, number);
	RELEASE(I2C1, KMODE_READ_WRITE);
}

/*
 * \brief cb_readI2C
 *
 * - Read from the i2c
 *
 */
static	void	cb_readI2C(uint8_t address, uint8_t *buffer, uint16_t number) {

	RESERVE(I2C1, KMODE_READ_WRITE);
	i2c_read(KI2C1, address, buffer, number);
	RELEASE(I2C1, KMODE_READ_WRITE);
}

#include	"model_stts22h.c_inc"
