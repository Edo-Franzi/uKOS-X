/*
; MT9V03x.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Aptina MT9V03x imager equates.
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

#define	KI2C_ADD_MT9V03x					0x48u							// I2C Aptina address

// Imager generic

typedef	struct	mt9v03x		mt9v03x_t;

struct mt9v03x {
			uint8_t		oRegNumber;											// Register number
			uint16_t	oValue;												// Value
};

// Max image size

#define	KNB_ROWS							480u							// Max 480 rows
#define	KNB_COLS							752u							// Max 752 cols

// Constant for the temperature
//
// T = (Ta + KMT9V03x_OFFSET_TEMP) x KMT9V03x_GAIN_TEMP

#define	KMT9V03x_OFFSET_TEMP				(-26.9)							// offset
#define	KMT9V03x_GAIN_TEMP					(10.88)							// Gain

// Some imager registers

#define KMT9V03x_CTRL_REG					0x07u							// Aptina Control Register Address
#define KMT9V03x_START_COL					0x01u							// ROI horizontal offset
#define KMT9V03x_START_ROW					0x02u							// ROI vertical offset
#define KMT9V03x_ROI_H						0x03u							// ROI height
#define KMT9V03x_ROI_W						0x04u							// ROI width
#define KMT9V03x_H_BLANK					0x05u							// Horizontal blank duration in number of pixels
#define KMT9V03x_V_BLANK					0x06u							// Vertical blank duration in number of lines
#define KMT9V03x_EXPOSURE					0x0Bu							// Exposure Time
#define KMT9V03x_BINNING					0x0Du							// Binning control
#define KMT9V03x_ANALOG_GAIN				0x35u							// Analog Gain
#define KMT9V03x_BLACK_LEVEL_CORRECTION		0x47u							// Black level correction
#define KMT9V03x_V_BLACK_LEVEL				0x48u							// VBlack value for correction
#define KMT9V03x_NOISE_ACTIVATION			0x70u							// Noise correction activation
#define KMT9V03x_CONSTANT_NOISE				0x71u							// Constant for noise correction
#define KMT9V03x_AUTOMATIC_EXPOSURE			0xAFu							// Automatic exposure + gain control
#define	KMT9V03x_TEMP						0xC1u							// I2C Aptina temperature register
#define KMT9V03x_FINE_EXPOSURE				0xD5u							// Fine exposure tuning

// Reserved register (Aptina datasheet page 21)

#define	KMT9V03x_REG20						0x20u							// Reserved
#define	KMT9V03x_REG24						0x24u							// Reserved
#define	KMT9V03x_REG2B						0x2Bu							// Reserved
#define	KMT9V03x_REG2F						0x2Fu							// Reserved

// Reserved register (not documented)

#define KMT9V03x_PRODUCTION_N0				0x68u							// Production number 0
#define KMT9V03x_PRODUCTION_N1				0x69u							// Production number 1
#define KMT9V03x_PRODUCTION_N2				0x6Au							// Production number 2
#define KMT9V03x_PRODUCTION_N3				0x6Bu							// Production number 3
