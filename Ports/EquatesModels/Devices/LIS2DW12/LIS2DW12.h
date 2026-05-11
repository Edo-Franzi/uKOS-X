/*
; LIS2DW12.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		ST LIS2DW12 accelerometer equates.
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

// Accelerometer registers

#define	LIS2DW12_OUT_TEMP_L					0x0Du							//
#define	LIS2DW12_OUT_TEMP_H					0x0Eu							//
#define	LIS2DW12_WHO_AM_I					0x0Fu							//
#define	LIS2DW12_CTRL1						0x20u							//
#define	LIS2DW12_CTRL2						0x21u							//
#define	LIS2DW12_CTRL3						0x22u							//
#define	LIS2DW12_CTRL4						0x23u							//
#define	LIS2DW12_CTRL5						0x24u							//
#define	LIS2DW12_CTRL6						0x25u							//
#define	LIS2DW12_OUT_T						0x26u							//
#define	LIS2DW12_STATUS						0x27u							//
#define	LIS2DW12_OUT_X_L					0x28u							//
#define	LIS2DW12_OUT_X_H					0x29u							//
#define	LIS2DW12_OUT_Y_L					0x2Au							//
#define	LIS2DW12_OUT_Y_H					0x2Bu							//
#define	LIS2DW12_OUT_Z_L					0x2Cu							//
#define	LIS2DW12_OUT_Z_H					0x2Du							//
#define	LIS2DW12_FIFO_CTRL					0x2Eu							//
#define	LIS2DW12_FIFO_SAMPLES				0x2Fu							//
#define	LIS2DW12_TAP_THS_X					0x30u							//
#define	LIS2DW12_TAP_THS_Y					0x31u							//
#define	LIS2DW12_TAP_THS_Z					0x32u							//
#define	LIS2DW12_INT_DUR					0x33u							//
#define	LIS2DW12_WAKE_UP_THS				0x34u							//
#define	LIS2DW12_WAKE_UP_DUR				0x35u							//
#define	LIS2DW12_FREE_FALL					0x36u							//
#define	LIS2DW12_STATUS_DUP					0x37u							//
#define	LIS2DW12_WAKE_UP_SRC				0x38u							//
#define	LIS2DW12_TAP_SRC					0x39u							//
#define	LIS2DW12_SIXD_SRC					0x3Au							//
#define	LIS2DW12_ALL_INT_SRC				0x3Bu							//
#define	LIS2DW12_X_OFS_USR					0x3Cu							//
#define	LIS2DW12_Y_OFS_USR					0x3Du							//
#define	LIS2DW12_Z_OFS_USR					0x3Eu							//
#define	LIS2DW12_CTRL7						0x3Fu							//
