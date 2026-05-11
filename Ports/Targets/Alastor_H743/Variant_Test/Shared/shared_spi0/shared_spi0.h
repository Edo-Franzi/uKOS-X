/*
; shared_spi0.
; ============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		For the shared_spi0 manager module.
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

// Served managers
// ---------------

enum {
		KNOMANAGER = 0u,						// No manager
		KIMU,									// imu manager
		KIMUA,									// Accelerometer imu manager
		KIMUM,									// Magnetometer imu manager
		KTEMPERATURE,							// Temperature temperature manager
		KFLASH									// flash manager
};

// Peripheral macro
// ----------------

#define	RESERVE_SHARED_SPI0(manager)	shared_spi0_reserve(manager, KWAIT_INFINITY);
#define	RELEASE_SHARED_SPI0				shared_spi0_release();

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

extern	int32_t	shared_spi0_reserve(uint32_t manager, uint32_t timeout);
extern	int32_t	shared_spi0_release(void);
extern	int32_t	shared_spi0_select(uint32_t manager);
extern	int32_t	shared_spi0_deselect(uint32_t manager);
extern	int32_t	shared_spi0_writeRead(uint8_t *data);

#if (defined(__cplusplus))
}
#endif

// Shared spi0 device errors & status
// ----------------------------------

#define	KSHARED_SPI0_NOERR	KERR_SPI_NOERR		// No error
#define	KSHARED_SPI0_CHBSY	KERR_SPI_CHBSY		// The manager is busy
#define	KSHARED_SPI0_GEERR	KERR_SPI_GEERR		// General error
#define	KSHARED_SPI0_TIMEO	KERR_SPI_TIMEO		// Timeout error
#define	KSHARED_SPI0_SENOE	KERR_SPI_SENOE		// The semaphore does not exist
#define	KSHARED_SPI0_CAREL	KERR_SPI_CAREL		// Cannot release the manager
