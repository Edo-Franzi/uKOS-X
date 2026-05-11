/*
; STTS22H.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Florence Lorenzin

;------------------------------------------------------------------------
; Author:	Florence Lorenzin	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		ST STTS22H equates.
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

// I2c interface

#define	KI2C_ADD_STTS22H					0x3Fu							// I2C STTS22H address

#define	KSTTS22H_SCALING					100u							// Scaling of 100-lsb / Deg

// Registers

#define	STTS22H_WHO_AM_I					0x01u							// Register WHOAMI
#define	STTS22H_TEMP_H_LIMIT				0x02u							// Register of the input for the high threshold decoder
#define	STTS22H_TEMP_L_LIMIT				0x03u							// Register of the input for the high threshold decoder
#define	STTS22H_CNTRL						0x04u							// Register of control
#define	STTS22H_STATUS						0x05u							// Register of status
#define	STTS22H_TEMP_L						0x06u							// Register L of the temperature
#define	STTS22H_TEMP_H						0x07u							// Register H of the temperature

// Control register

#define	ONE_SHOT							0u								// New one-shot temperature acquisition is executed
#define	TIME_OUT_DIS						1u								// Timeout function of SMBus is disabled
#define	FREERUN								2u								// Enables freerun mode
#define	IF_ADD_INC							3u								// Automatic address increment is enabled
#define	AVG									4u								// Sampling
#define	AVG25HZ								0u								// Sampling 25-Hz
#define	AVG50HZ								1u								// Sampling 50-Hz
#define	AVG100HZ							2u								// Sampling 100-Hz
#define	AVG200HZ							3u								// Sampling 200-Hz
#define	BDU									6u								// If BDU is used, TEMP_L_OUT must be read first)
#define	LOW_ODR_START						7u								// Enables 1 Hz ODR operating mode

// Status register

#define	BUSY								1u								// The conversion is in progress
#define	OVER_THH							2u								// High limit temperature exceeded
#define	OVER_THL							3u								// Low limit temperature exceeded
