/*
; ftdiSPI.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		FTDI - SPI primitives.
;
;			It is mandatory to consult these FTDI documents:
;			- Application Note AN_108
;			- Application Note AN_114
;			- Application Note AN_135
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

#include	"types.h"
#include	"ftd2xx.h"

// FTDI commands
// -------------

#define	MODE_RESET				0x00			// Mode Reset
#define	MODE_A_BITBANG			0x01			// Mode asynchronous bit bang
#define	MODE_MPSSE				0x02			// Mode MPSSE
#define	MODE_S_BITBANG			0x04			// Mode synchronous bit bang
#define	MODE_FAST_OPTO			0x10			// Mode fast Opto-Isolated Serial
#define	MODE_CBUS				0x20			// Mode CBUS Bit Bang
#define	MODE_SINGLE				0x40			// Mode single Channel Synchronous

#define	CMD_24					0x24			// Clock Data Bytes In on -ve clock edge MSB first (valueL, valueH)

#define	CMD_80					0x80			// Set Data bits LowByte (gpio3, gpio2, gpio1, gpio0, cs, tdi, tdo, clk | direction)
#define	VAL_QUITE				0xC8			// Quite                  1      1      0      0      1   0    0    0
#define	DIR_QUITE				0xFB			// Quite                                                                | 1 1 1 1 1 0 1 1
#define	VAL_CSENA				0xC0			// Enable CS              1      1      0      0      0   0    0    0

#define	CMD_86					0x86			// Set clk divisor (valueL, valueH)
#define	CMD_8A					0x8A			// Disables the clk divide by 5 to allow for a 60MHz master clock
#define	CMD_87					0x87			// Send Immediate
#define	CMD_97					0x97			// Disable adaptive clocking

#define	KUSB_INPUT_BUFFER_SIZE	65536			// Size of the USB input buffer
#define	KUSB_OUTPUT_BUFFER_SIZE	65536			// Size of the USB output buffer
#define	KDISABLE_EVENT			0				// Disable event
#define	KDISABLE_CHAR			0				// Disable char

#define	KXFER_NB_PACKETS		80				// Number of packets (has to be divisible by 2). See xfer.h

// ftdiSPI manager errors
// ----------------------

#define	KFTDINOERR	0					// No error
#define	KFTDIGEERR	(-1)				// General error

/*!
 * \brief Get the number of devices
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    nbDevices;
 *
 *    status = ftdiSPI_getNbDevices(&nbDevices);
 * \endcode
 *
 * \param[in]	*nbDevices		Ptr on the device number
 * \return		KFTDINOERR		OK
 * \return		KFTDIGEERR		Problem
 *
 */
int32_t	ftdiSPI_getNbDevices(uint32_t *nbDevices);

/*!
 * \brief Get the device Id
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * uintptr_t    deviceNb;
 * char_t       deviceId[64];
 *
 *    status = ftdiSPI_getDeviceId(deviceNb, deviceId);
 * \endcode
 *
 * \param[in]	deviceNb		Device number
 * \param[in]	deviceId		Ptr on the device Id
 * \return		KFTDINOERR		OK
 * \return		KFTDIGEERR		Problem
 *
 */
int32_t	ftdiSPI_getDeviceId(uintptr_t deviceNb, char_t *deviceId);

/*!
 * \brief Open the device
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * FT_HANDLE    ftHandle;
 * uintptr_t    deviceNb;
 *
 *    status = ftdiSPI_openDevice(&ftHandle, deviceNb);
 * \endcode
 *
 * \param[in]	ftHandle		Ptr on the device handle
 * \param[in]	deviceNb		Device number
 * \return		KFTDINOERR		OK
 * \return		KFTDIGEERR		Problem
 *
 */
int32_t	ftdiSPI_openDevice(FT_HANDLE *ftHandle, uintptr_t deviceNb);

/*!
 * \brief Close the device
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * FT_HANDLE    ftHandle;
 *
 *    status = ftdiSPI_closeDevice(ftHandle);
 * \endcode
 *
 * \param[in]	ftHandle		The device handle
 * \return		KFTDINOERR		OK
 * \return		KFTDIGEERR		Problem
 *
 */
int32_t	ftdiSPI_closeDevice(FT_HANDLE ftHandle);

/*
 * \brief Get the data
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t      status;
 * FT_HANDLE    ftHandle;
 * uint8_t      buffer[752 * 480];
 * uint32_t	    size = 752 * 480;
 *
 *    status = ftdiSPI_getData(ftHandle, buffer, size);
 * \endcode
 *
 * \param[in]	ftHandle		The device handle
 * \param[in]	buffer			Ptr on the buffer
 * \param[in]	size			Size of the buffer
 * \param[in]	delay			Delay in [us] between packs
 * \param[in]	modeBuffer		Big / small transfer buffers
 * \return		KFTDINOERR		OK
 * \return		KFTDIGEERR		Problem
 *
 */
int32_t	ftdiSPI_getData(FT_HANDLE ftHandle, uint8_t *buffer, uint32_t size, uint32_t delay, uint32_t modeBuffer);
