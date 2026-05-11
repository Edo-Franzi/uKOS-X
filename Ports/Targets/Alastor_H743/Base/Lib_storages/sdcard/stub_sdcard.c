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
; Goal:		stub for the connection of the "sdcard" manager with the spi1 device.
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

// Connect the physical device to the logical manager
// --------------------------------------------------

#define	model_sdcard_init			stub_sdcard_init
#define	model_sdcard_readStatus		stub_sdcard_readStatus
#define	model_sdcard_initialise		stub_sdcard_initialise
#define	model_sdcard_read			stub_sdcard_read
#define	model_sdcard_write			stub_sdcard_write
#define	model_sdcard_ioctl			stub_sdcard_ioctl

enum {
		KSDCARD_INIT = 0u,
		KSDCARD_RELEASE,
		KSDCARD_SELECT,
		KSDCARD_DESELECT
};

// Model callbacks
// ---------------

/*
 * \brief cb_control
 *
 * - Control of the SPI interface
 *   - Initialise
 *   - Reserve
 *   - Release
 *   - Select
 *   - Deselect
 *
 */
static	void	cb_control(uint8_t mode) {
	static	const	spiCnf_t	configure = {
									.oSpeed	   = 400000u,
									.oMode     = (uint8_t)KSPI_MASTER,
									.oClock    = 0u
								};

	switch (mode) {
		case KSDCARD_INIT: {
			GPIOE->ODR |= (1u<<BSEL_SDCARD);

// Master, POL = PHA = 0
// Speed accesses ~400-Kbit/s

			spi_configure(KSPI1, &configure);
			break;
		}
		case KSDCARD_RELEASE: {
			break;
		}
		case KSDCARD_SELECT: {
			GPIOE->ODR &= (uint32_t)~(1u<<BSEL_SDCARD);
			break;
		}
		case KSDCARD_DESELECT:
		default: {
			GPIOE->ODR |= (1u<<BSEL_SDCARD);
			break;
		}
	}
}

/*
 * \brief cb_speed
 *
 * - Control of the SPI speed
 *
 */
static	void	cb_speed(uint32_t speed) {
	static	spiCnf_t	configure = {
							.oMode     = (uint8_t)KSPI_MASTER,
							.oClock    = 0u,
							.oSpeed	   = 0u
						};

	configure.oSpeed = speed;
	spi_configure(KSPI1, &configure);
}

/*
 * \brief cb_cardInserted
 *
 * - Verify if the sdcard is inserted
 *
 */
static	bool	cb_cardInserted(void) {

	if ((GPIOG->IDR & (1u<<BNO_SDCARD)) != 0u) {
		return (false);
	}

	return (true);
}

/*
 * \brief cb_writeRead
 *
 * - Write/Read on the SPI
 *
 */
static	uint8_t	cb_writeRead(uint8_t data) {
	uint8_t		wRData;

	wRData = data;
	spi_writeRead(KSPI1, &wRData);
	return (wRData);
}

/*
 * \brief cb_write
 *
 * - Write on the SPI
 *
 */
static	void	cb_write(const uint8_t *source, uint16_t size) {

	spi_multipleWriteRead(KSPI1, source, size, nullptr, 0u, KWAIT_INFINITY);
}

/*
 * \brief cb_readSPI
 *
 * - Read from the SPI
 *
 */
static	void	cb_readSPI(uint8_t *destination, uint16_t size) {

	spi_multipleWriteRead(KSPI1, nullptr, 0u, destination, size, KWAIT_INFINITY);
}

#include	"model_sdcard_spi.c_inc"
