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

#include	"ftdiSPI.h"
#include	<stdio.h>
#include	<unistd.h>

#define		KFULL_SPEED_S			// define:	SPI master clocked @ 30-MHz
									// undef: 	SPI master clocked @ 15-MHz
/*
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
int32_t	ftdiSPI_getNbDevices(uint32_t *nbDevices) {

	if (FT_ListDevices(nbDevices, nullptr, FT_LIST_NUMBER_ONLY) != FT_OK) { return (KFTDIGEERR); }

	return (KFTDINOERR);
}

/*
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
int32_t	ftdiSPI_getDeviceId(uintptr_t deviceNb, char_t *deviceId) {

	if (FT_ListDevices((void *)deviceNb, deviceId, (FT_LIST_BY_INDEX | FT_OPEN_BY_SERIAL_NUMBER)) != FT_OK) { return (KFTDIGEERR); }

	return (KFTDINOERR);
}

/*
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
int32_t	ftdiSPI_openDevice(FT_HANDLE *ftHandle, uintptr_t deviceNb) {
	char_t		*deviceId_0, *deviceId_1;
	uint8_t		clockDividePrm[1]      = { CMD_8A };
	uint8_t		adaptiveClockingPrm[1] = { CMD_97 };

// TCK = 60MHz /((1 + [(1 + ValueH * 256) OR ValueL]) * 2)

	#if (defined(KFULL_SPEED_S))
//												   ValueL	  ValueH
	uint8_t		clockFrequencyPrm[3]   = { CMD_86, 0x00,      0x00      };

	#else
	uint8_t		clockFrequencyPrm[3]   = { CMD_86, 0x01,      0x00      };
	#endif

	uint8_t		setDataBitsLbPrm[3]    = { CMD_80, VAL_QUITE, DIR_QUITE };
	uint32_t	nbWrite;

// Determine the device Id

	switch (deviceNb) {
		case 0: { deviceId_0 = "A"; deviceId_1 = "uKOS-A"; break; }
		case 1: { deviceId_0 = "B"; deviceId_1 = "uKOS-B"; break; }
		case 2: { deviceId_0 = "C"; deviceId_1 = "uKOS-C"; break; }
		case 3: { deviceId_0 = "D"; deviceId_1 = "uKOS-D"; break; }
		default:																				  {								   return (KFTDIGEERR); }
	}

// Open and configure the device
// - First, try without the serial (e.g. A, B, C, D)
// - if it fails, try with the serial (e.g. uKOS-A, uKOS-B, uKOS-C, uKOS-D)

	if (FT_OpenEx(deviceId_0, FT_OPEN_BY_SERIAL_NUMBER, ftHandle) != FT_OK) {
		if (FT_OpenEx(deviceId_1, FT_OPEN_BY_SERIAL_NUMBER, ftHandle) != FT_OK)					  { 							   return (KFTDIGEERR); }
	}

	if (FT_ResetDevice(*ftHandle) != FT_OK)														  { ftdiSPI_closeDevice(ftHandle); return (KFTDIGEERR); }
	if (FT_SetUSBParameters(*ftHandle, KUSB_INPUT_BUFFER_SIZE, KUSB_OUTPUT_BUFFER_SIZE) != FT_OK) { ftdiSPI_closeDevice(ftHandle); return (KFTDIGEERR); }
	if (FT_SetChars(*ftHandle, false, KDISABLE_EVENT, false, KDISABLE_CHAR) != FT_OK)			  { ftdiSPI_closeDevice(ftHandle); return (KFTDIGEERR); }
	if (FT_SetTimeouts(*ftHandle, 5000, 5000) != FT_OK)											  { ftdiSPI_closeDevice(ftHandle); return (KFTDIGEERR); }
	if (FT_SetLatencyTimer(*ftHandle, 2) != FT_OK)											  	  { ftdiSPI_closeDevice(ftHandle); return (KFTDIGEERR); }
	if (FT_SetBitMode(*ftHandle, 0x00, MODE_RESET) != FT_OK)									  { ftdiSPI_closeDevice(ftHandle); return (KFTDIGEERR); }
	if (FT_SetBitMode(*ftHandle, 0x00, MODE_MPSSE) != FT_OK)									  { ftdiSPI_closeDevice(ftHandle); return (KFTDIGEERR); }
	usleep(50000);

	if (FT_Write(*ftHandle, clockDividePrm,      sizeof(clockDividePrm), &nbWrite) != FT_OK)	  { ftdiSPI_closeDevice(ftHandle); return (KFTDIGEERR); }
	if (FT_Write(*ftHandle, adaptiveClockingPrm, sizeof(adaptiveClockingPrm), &nbWrite) != FT_OK) { ftdiSPI_closeDevice(ftHandle); return (KFTDIGEERR); }
	if (FT_Write(*ftHandle, clockFrequencyPrm,   sizeof(clockFrequencyPrm), &nbWrite) != FT_OK)	  { ftdiSPI_closeDevice(ftHandle); return (KFTDIGEERR); }
	usleep(20000);

	if (FT_Write(*ftHandle, setDataBitsLbPrm, sizeof(setDataBitsLbPrm), &nbWrite) != FT_OK)		  { ftdiSPI_closeDevice(ftHandle); return (KFTDIGEERR); }
	if (FT_Purge(*ftHandle, (FT_PURGE_RX | FT_PURGE_TX)) != FT_OK)								  { ftdiSPI_closeDevice(ftHandle); return (KFTDIGEERR); }

	return (KFTDINOERR);
}

/*
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
int32_t	ftdiSPI_closeDevice(FT_HANDLE ftHandle) {

	if (FT_Purge(ftHandle, (FT_PURGE_RX | FT_PURGE_TX)) != FT_OK) { return (KFTDIGEERR); }
	if (FT_Close(ftHandle) != FT_OK)							  { return (KFTDIGEERR); }

	return (KFTDINOERR);
}

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
 * uint32_t	    delay = 1000;
 * uint32_t	    modeBuffer = 1;
 *
 *    status = ftdiSPI_getData(ftHandle, buffer, size, delay, modeBuffer);
 * \endcode
 *
 * \param[in]	ftHandle		The device handle
 * \param[in]	buffer			Ptr on the buffer
 * \param[in]	size			Size of the buffer
 * \param[in]	delay			Delay in [us] between packets
 * \param[in]	modeBuffer		Big / small transfer buffers
 * \return		KFTDINOERR		OK
 * \return		KFTDIGEERR		Problem
 *
 */
int32_t	ftdiSPI_getData(FT_HANDLE ftHandle, uint8_t *buffer, uint32_t size, uint32_t delay, uint32_t modeBuffer) {
	uint32_t	i, nbRead, nbWrite, nbPackets, szPacket;
	uint8_t		csL[3]		  = { CMD_80, VAL_CSENA, DIR_QUITE		   };
	uint8_t		csH[3]		  = { CMD_80, VAL_QUITE, DIR_QUITE		   };
	uint8_t		readPacket[4] = { CMD_24, 0x00,      0x00,      CMD_87 };

// Mode small transfer buffers
// Transfer a fixed number of packets (KXFER_NB_PACKETS)

	if (modeBuffer == 0) {
		nbPackets = KXFER_NB_PACKETS;
		szPacket  = size / KXFER_NB_PACKETS;
	}

// Mode big transfer buffers
// Transfer of a minimum number of big packets

	else {
		nbPackets = ((size % 65536) != 0) ? ((size / 65536) + 1) : (size / 65536);
		szPacket  = size / nbPackets;
	}
	readPacket[1] = (uint8_t)(szPacket - 1);
	readPacket[2] = (uint8_t)((szPacket - 1)>>8) & 0xFF;

// For all the packets
// CS enable
//	- Read the packet
//	- 1-ms between each packet
// CS disable

	if (FT_Write(ftHandle, csL, sizeof(csL), &nbWrite) != FT_OK)					{ return (KFTDIGEERR); }
	usleep(10);
	for (i = 0; i < nbPackets; i++) {

		if (FT_Write(ftHandle, readPacket, sizeof(readPacket), &nbWrite) != FT_OK)	{ return (KFTDIGEERR); }
		if (FT_Read(ftHandle, buffer, szPacket, &nbRead) != FT_OK)					{ return (KFTDIGEERR); }
		buffer += nbRead;

		usleep(delay);
	}
	usleep(10);
	if (FT_Write(ftHandle, csH, sizeof(csH), &nbWrite) != FT_OK)					{ return (KFTDIGEERR); }

	return (KFTDINOERR);
}
