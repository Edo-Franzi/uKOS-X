/*
; vcp.
; ====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		VCP I/O management.
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

#include	"ftd2xx.h"
#include	"types_unix.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<fcntl.h>
#include	<termios.h>
#include	<time.h>
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

#define	KINITIOREC				3000000									// Initial timeout reception of 30s
#define	KNORTIOREC				200000									// Normal timeout reception of 2s (for stopping the process)

typedef	struct termios	termios_t;
typedef	struct timespec	timespec_t;

static	termios_t	vTTYAttr;

/*
 * \brief vcp_list
 *
 * - List of the devices
 *
 */
void	vcp_list(void) {
	FT_STATUS	status;
	DWORD		nbDevices;
	uint32_t	device;
	char_t		buffer[64];

	status = FT_ListDevices(&nbDevices, nullptr, FT_LIST_NUMBER_ONLY);
	if (status == FT_OK) { fprintf(stdout, "Number of device: %0d\n", nbDevices);           }
	else				 { fprintf(stdout, "Error: FT_ListDevices status = %0d\n", status); }

	for (device = 0; device < nbDevices; device++) {
		status = FT_ListDevices((PVOID)((intptr_t)device), buffer, FT_LIST_BY_INDEX | FT_OPEN_BY_SERIAL_NUMBER);
		if (status == FT_OK) { fprintf(stdout, "Driver ID: %s\n", buffer);                      }
		else				 { fprintf(stdout, "Error: FT_ListDevices status = %0d\n", status); }
	}
}

/*
 * \brief vcp_open
 *
 * - Open the device
 *
 * \param[in]	*driverID	Ptr on the driver ID "FTXG86D7D"
 * \param[in]	baudrate	Device baudrate
 * \return		handle		Driver handle ID
 *
 */
int32_t	vcp_open(const char_t *driverID, int32_t baudrate) {
	int32_t		handle;
	speed_t		bd;
	termios_t	options;
	char_t		driver[50] = "/dev/tty.usbserial-";

	strcat(driver, driverID);
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

	handle = open(driver, O_RDONLY | O_NOCTTY | O_NDELAY);
	if (handle == -1) {
		return (EXIT_OS_FAILURE);
	}

	while (true) {
	    if (fcntl(handle, F_SETFL, 0)            == -1) break;
	    if (tcgetattr(handle, &vTTYAttr)         == -1) break;

	    options 			=  vTTYAttr;
	    options.c_cflag 	|= (CLOCAL | CREAD);
	    options.c_lflag 	&= ~(ICANON | ECHO | ECHOE | ISIG);
	    options.c_oflag 	&= ~OPOST;
	    options.c_cc[VMIN]	=  0;
	    options.c_cc[VTIME]	=  5;
		options.c_cflag		&= ~(CSIZE | PARENB);
	    options.c_cflag		|= (CS8);

		if (cfsetispeed(&options, bd)            == -1) break;
		if (cfsetospeed(&options, bd)            == -1) break;
	 if (tcsetattr(handle, TCSANOW, &options) == -1) break;

	    return (handle);
	}

	close(handle);
	return (EXIT_OS_FAILURE);
}

/*
 * \brief vcp_close
 *
 * - Close the device
 *
 * \param[in]	handle	Driver handle ID
 *
 * \note This function does not return a value (None).
 *
 */
void	vcp_close(int32_t handle) {

	tcsetattr(handle, TCSADRAIN, &vTTYAttr);
	close(handle);
}

/*
 * \brief vcp_readAByte
 *
 * - Read a byte on the device
 *
 * \param[in]	handle		Driver handle ID
 * \param[out]	*receive	Ptr on the receive buffer
 * \return		status		true -> OK
 *							false -> timeout error
 *
 */
bool	vcp_readAByte(int32_t handle, uint8_t *receive) {
			int32_t		nbRead;
			uint32_t	timeout = 0;
			timespec_t	time;
	static	uint32_t	vTimeoutLimit = KINITIOREC;

	while (true) {
		nbRead = read(handle, receive, 1);
		if (nbRead > 0) {
			vTimeoutLimit = KNORTIOREC;
			break;
		}
		time.tv_sec  = 0;
		time.tv_nsec = 10000;
		nanosleep(&time, nullptr);
		if (timeout++ > vTimeoutLimit) {
			return (false);
		}
	}
	return (true);
}

/*
 * \brief vcp_read
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
bool	vcp_read(int32_t handle, uint8_t *receive, uint32_t *count) {
			int32_t		nbRead;
			uint32_t	timeout = 0;
			timespec_t	time;
	static	uint32_t	vTimeoutLimit = KINITIOREC;

	while (true) {
		nbRead = read(handle, receive, 100);
  		if (nbRead > 0) {
			vTimeoutLimit = KNORTIOREC;
   			break;
   		}
		time.tv_sec  = 0;
		time.tv_nsec = 10000;
		nanosleep(&time, nullptr);
		if (timeout++ > vTimeoutLimit) {
			return (false);
		}
	}
	*count = nbRead;
	return (true);
}

/*
 * \brief vcp_flush
 *
 * - Flush the device
 *
 * \param[in]	handle	Driver handle ID
 *
 * \note This function does not return a value (None).
 *
 */
void	vcp_flush(int32_t handle) {
	int32_t		nbRead;
	uint8_t		byte;

	do {
		nbRead = read(handle, &byte, 1);
	} while (nbRead == 1);
}
