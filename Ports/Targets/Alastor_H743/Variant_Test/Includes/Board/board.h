/*
; board.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Board mapping.
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

#include	"MT9V03x/MT9V03x.h"

// GPIO settings
// -------------

#define KNB_LED				(8u + 2u)							// Number of LEDs (LEDs + BLOGICx)

// PORTs

#define	BSEL_DEBUG			4u									// PORT A 4, /CS Debug
#define	BRZ_FLASH			8u									// PORT A 8, /Rz FLASH

#define	BSEL_WROOM			0u									// PORT B 0, /CS Wroom
#define	BLED_0				1u									// PORT B 1, BLED_0
#define	BLED_1				5u									// PORT B 5, BLED_1
#define	BLED_2				7u									// PORT B 7, BLED_2
#define	BSEL_FLASH			12u									// PORT B 12, /CS FLASH

#define	BLED_3				3u									// PORT C 3, BLED_3
#define	BLED_4				4u									// PORT C 4, BLED_4
#define	BLED_5				5u									// PORT C 5, BLED_5
#define	BSEL_ACCELERO		6u									// PORT C 6, /CS accelerometer/gyroscope
#define	BLED_6				8u									// PORT C 8, BLED_6
#define	BLED_7				9u									// PORT C 9, BLED_7
#define	BSW_0				10u									// PORT C 10, SW0
#define	BSW_1				11u									// PORT C 11, SW1
#define	BSW_2				12u									// PORT C 12, SW2
#define	BSW_3				13u									// PORT C 13, SW3

#define	BESP32_X1			2u									//
#define	BESP32_RTS			BESP32_X1							// PORT D 2, ESP32_X1, GPIO14, AT.RTS
#define	BIO_W_0				2u									// PORT D 2, IO_W_0 (Wroom status)
#define	BIO_W_1				3u									// PORT D 3, IO_W_1
#define	BCTS				BIO_W_1								// PORT D 3, IO_W_1 (Wroom /CTS)
#define	BIO_W_2				4u									// PORT D 4, IO_W_2
#define	BIO_W_3				5u									// PORT D 5, IO_W_3
#define	BIO_W_4				6u									// PORT D 6, IO_W_4
#define	BIO_W_5				7u									// PORT D 7, IO_W_5
#define	BIO_W_6				11u									// PORT D 11, IO_W_6
#define	BIO_W_7				12u									// PORT D 12, IO_W_7
#define	BESP32_NDOWNLOAD	13u									// PORT D 13, ESP32_DOWNLOAD, GPIO0, low=download

#define	BESP32_ENABLE		3u									// PORT E 3, ESP32_ENABLE, CHIP_PU, low=power off
#define	BSEL_SDCARD			4u									// PORT E 4, /CS of the device

#define	BSEL_MAGNETO		10u									// PORT F 10, /CS magnetometer

#define	BESP32_X0			3u									// PORT G 3, OI_W_0, GPIO15, AT.CTX
#define	BESP32_CTS			BESP32_X0
#define	BOI_W_0				BESP32_X0							// PORT G 3, OI_W_0
#define	BRTS				BOI_W_0								// PORT G 3, OI_W_0 (Wroom /RTS)
#define	BOI_W_1				6u									// PORT G 6, OI_W_1
#define	BBOOT				BOI_W_1								// PORT G 6, OI_W_1 (Wroom /Boot)
#define	BOI_W_2				7u									// PORT G 7, OI_W_2
#define	BE					BOI_W_2								// PORT G 7, OI_W_2 (Wroom E)
#define	BOI_W_3				9u									// PORT G 9, OI_W_3
#define	BOI_W_4				10u									// PORT G 10, OI_W_4
#define	BOI_W_5				11u									// PORT G 11, OI_W_5
#define	BDBG_COM_REQ		13u									// PORT G 13, DBGCOMREQ
#define	BNO_SDCARD			14u									// PORT G 14, sdcard inside the slot

#define	BEN_CLK				2u									// PORT H 2, Enable the Aptina clock
#define	BDEN_AG				3u									// PORT H 3, BDEN_AG IMU
#define	BDBG_REQ			13u									// PORT H 13, DBGREQ

#define	BOI_W_6				0u									// PORT I 0, OI_W_6
#define	BOI_W_7				3u									// PORT I 3, OI_W_7
#define	BLOGIC_0			8u									// PORT I 8, LOGIC0
#define	BLOGIC_1			9u									// PORT I 9, LOGIC1
#define	BSTANDBY			10u									// PORT I 10, Standby imager
#define	BEXPOSURE			11u									// PORT I 11, Exposure imager
