/*
; serial.
; =======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Generic serial I/O management.
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

#include	"types_unix.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<fcntl.h>
#include	<termios.h>
#include	<unistd.h>

// Baudrates not supported

#if (!defined(B460800))
#define B460800					460800
#endif

#if (!defined(B500000))
#define B500000					500000
#endif

#if (!defined(B921600))
#define B921600					921600
#endif

#if (!defined(B1000000))
#define B1000000				1000000
#endif

#if (!defined(B1843200))
#define B1843200				1843200
#endif

#if (!defined(B2000000))
#define B2000000				2000000
#endif

#if (!defined(B2500000))
#define B2500000				2500000
#endif

#if (!defined(B3000000))
#define B3000000				3000000
#endif

typedef	struct termios	termios_t;
typedef	struct timespec	timespec_t;

static	termios_t	vTTYAttr;

/*
 * \brief serial_open
 *
 * - Open the device
 *
 * \param[in]	*driverID		Ptr on the driver ID, ex "/dev/ttyw1", "/dev/tty.usbserial-uKOS_2"
 * \param[in]	baudrate		Device baudrate
 * \param[out]	*handle			Ptr on the driver handle ID
 * \return		EXIT_OS_SUCCESS	Driver open
 * \return		EXIT_OS_FAILURE	Problem
 *
 */
int32_t	serial_open(const char_t *driverID, int32_t baudrate, int32_t *handle) {
	speed_t		bd;
	termios_t	options;

	switch (baudrate) {
		case 9600:    { bd = B9600;    break; }
		case 19200:   { bd = B19200;   break; }
		case 38400:   { bd = B38400;   break; }
		case 115200:  { bd = B115200;  break; }
		case 230400:  { bd = B230400;  break; }
		case 460800:  { bd = B460800;  break; }
		case 500000:  { bd = B500000;  break; }
		case 921600:  { bd = B921600;  break; }
		case 1000000: { bd = B1000000; break; }
		case 1843200: { bd = B1843200; break; }
		case 2000000: { bd = B2000000; break; }
		case 2500000: { bd = B2500000; break; }
		case 3000000: { bd = B3000000; break; }
		default:      { bd = B460800;  break; }
	}

// Open in this modes:
//	- O_RDWR, Read and Write modes.
//	- O_NOCTTY, This program doesn't want to be the "controlling terminal" for that port.
//	- O_NDELAY, This program doesn't care what state the DCD.

	*handle = open(driverID, O_RDWR | O_NOCTTY | O_NDELAY);
	if (*handle == -1) {
		return (EXIT_OS_FAILURE);
	}

	while (true) {
		if (fcntl(*handle, F_SETFL, 0)	  == -1) break;
		if (tcgetattr(*handle, &vTTYAttr) == -1) break;

		options = vTTYAttr;

// Control options
//	- CLOCAL, Do not change "owner" of port.
//	- CREAD, Enable receiver.
//	- CS8, 8-bits.
//	- CSTOPB, 1-bits.

// Local options
// Input options
//	- IGNPAR, Ignore parity errors.
//	- IGNBRK, Ignore break condition.
//
// Character control
//	- VTIME, Time to wait for data (tenths of seconds.
//	- VMIN, Minimum number of characters to read.

		options.c_cflag		= 0;
		options.c_cflag		= (CLOCAL | CREAD);
		options.c_cflag	   |= (CS8);

		options.c_lflag		= 0;

		options.c_iflag		= (IGNPAR | IGNCR);

		options.c_oflag		= 0;

		options.c_cc[VTIME]	= 0;
		options.c_cc[VMIN]	= 1;

		if (cfsetispeed(&options, bd)             == -1) break;
		if (cfsetospeed(&options, bd)             == -1) break;
		if (tcsetattr(*handle, TCSANOW, &options) == -1) break;

		sleep(2);
		if (tcflush(*handle, TCIOFLUSH)			  == -1) break;

		usleep(10000);
		return (EXIT_OS_SUCCESS);
	}

	close(*handle);
	return (EXIT_OS_FAILURE);
}

/*
 * \brief serial_close
 *
 * - Close the device
 *
 * \param[in]	handle	Driver handle ID
 *
 * \note This function does not return a value (None).
 *
 */
void	serial_close(int32_t handle) {

	tcsetattr(handle, TCSADRAIN, &vTTYAttr);
	close(handle);
}

/*
 * \brief serial_read
 *
 * - Read bytes on the device
 *
 * \param[in]	handle		Driver handle ID
 * \param[out]	*receive	Ptr on the receive buffer
 * \param[out]	*count		Ptr on the count
 * \return		status		true -> OK
 *							false -> timeout error
 *
 */
bool	serial_read(int32_t handle, char_t *receive, int32_t *count) {

	*count = read(handle, receive, *count);
	if (*count == 1) {
		return (true);
	}

	return (false);
}

/*
 * \brief serial_write
 *
 * - Write buffers on the device
 *
 * \param[in]	handle		Driver handle ID
 * \param[out]	*transmit	Ptr on the transmit buffer
 * \param[out]	*count		Ptr on the count
 * \return		status		true -> OK
 *							false -> timeout error
 *
 */
bool	serial_write(int32_t handle, char_t *transmit, int32_t *count) {
	int32_t		result;

	result = write(handle, transmit, *count);
	if (result != *count) {
		*count = result;
		return (false);
	}

	return (true);
}

/*
 * \brief serial_flush
 *
 * - Flush the device
 *
 * \param[in]	handle	Driver handle ID
 *
 * \note This function does not return a value (None).
 *
 */
void	serial_flush(int32_t handle) {
	int32_t		nbRead;
	uint8_t		byte;

	sleep(2);
	tcflush(handle, TCIOFLUSH);
}
