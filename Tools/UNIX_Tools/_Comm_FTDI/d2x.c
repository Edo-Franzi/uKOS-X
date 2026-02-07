/*
; d2X.
; ====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		D2XX uart I/O management.
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
#include	<time.h>
#include	<unistd.h>

#define	KINITIOREC	3000000				// Initial timeout reception of 30s
#define	KNORTIOREC	500000				// Normal timeout reception of 5s (for stopping the process)

typedef	struct timespec	timespec_t;

/*
 * \brief d2x_list
 *
 * - List of the devices
 *
 */
void	d2x_list(void) {
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
 * \brief d2x_open
 *
 * - Open the device
 *
 * \param[in]	*driverID	Ptr on the driver ID "FTXG86D7D"
 * \return		handle		Driver handle ID
 *
 */
FT_HANDLE	d2x_open(const char_t *driverID, int32_t baudrate) {
	FT_STATUS	status;
	FT_HANDLE	handle;

	status = FT_OpenEx((PVOID)driverID, FT_OPEN_BY_SERIAL_NUMBER, &handle);
	status = FT_SetBaudRate(handle, baudrate);
	return (handle);
}

/*
 * \brief d2x_close
 *
 * - Close the device
 *
 * \param[in]	handle	Driver handle ID
 *
 * \note This function does not return a value (None).
 *
 */
void	d2x_close(FT_HANDLE handle) {

	FT_Close(handle);
}

/*
 * \brief d2x_readAByte
 *
 * - Read a byte on the device
 *
 * \param[in]	handle		Driver handle ID
 * \param[in]	*receive	Ptr on the receive buffer
 * \return		status		true -> OK
 *							false -> timeout error
 *
 */
bool	d2x_readAByte(FT_HANDLE handle, uint8_t *receive) {
			FT_STATUS	status;
			DWORD		eventDWord;
			DWORD		txBytes;
			DWORD		rxBytes;
			DWORD		bytesReceived;
			uint32_t	timeout = 0;
			timespec_t	time;
	static	uint32_t	vTimeoutLimit = KINITIOREC;

	while (true) {
		FT_GetStatus(handle, &rxBytes, &txBytes, &eventDWord);
		if (rxBytes > 0) {
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
	status = FT_Read(handle, receive, 1, &bytesReceived);
	return (true);
}

/*
 * \brief d2x_read
 *
 * - Read bytes on the device
 *
 * \param[in]	handle		Driver handle ID
 * \param[in]	*receive	Ptr on the receive buffer
 * \param[in]	*count		Ptr on the count
 * \return		status		true -> OK
 *							false -> timeout error
 *
 */
bool	d2x_read(FT_HANDLE handle, uint8_t *receive, uint32_t *count) {
			FT_STATUS	status;
			DWORD		eventDWord;
			DWORD		txBytes;
			DWORD		rxBytes;
			DWORD		bytesReceived;
			uint32_t	timeout = 0;
			timespec_t	time;
	static	uint32_t	vTimeoutLimit = KINITIOREC;

	while (true) {
		FT_GetStatus(handle, &rxBytes, &txBytes, &eventDWord);
		if (rxBytes > 0) {
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
	status = FT_Read(handle, receive, rxBytes, &bytesReceived);
	*count = (uint32_t)rxBytes;
	return (true);
}

/*
 * \brief d2x_flush
 *
 * - Flush the device
 *
 * \param[in]	handle	Driver handle ID
 *
 * \note This function does not return a value (None).
 *
 */
void	d2x_flush(FT_HANDLE handle) {
	uint8_t		byte;
	DWORD		eventDWord;
	DWORD		txBytes;
	DWORD		rxBytes;
	DWORD		bytesReceived;

	while (true) {
		FT_GetStatus(handle, &rxBytes, &txBytes, &eventDWord);
		if (rxBytes > 0) {
			FT_Read(handle, &byte, 1, &bytesReceived);
		}
		else {
			return;
		}
	}
}
