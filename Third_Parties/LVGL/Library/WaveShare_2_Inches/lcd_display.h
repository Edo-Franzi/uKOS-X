/*
; lcd_display.
; ============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2026-06-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Equates for the lcd display
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

// LCD controller commands

#define	SLPOUT						0x11u			//
#define	INVON						0x21u			//
#define	DISPON						0x29u			//
#define	CASET						0x2Au			//
#define	RASET						0x2Bu			//
#define	MADCTL						0x36u			//
#define	COLMOD						0x3Au			//
#define	RAMCTRL						0xB0u			//
#define	PORCTRL						0xB2u			//
#define	GCTRL						0xB7u			//
#define	VCOMS						0xBBu			//
#define	LCMCTRL						0xC0u			//
#define	VDVVRHEN					0xC2u			//
#define	VRHS						0xC3u			//
#define	VDVS						0xC4u			//
#define	FRCTRL2						0xC6u			//
#define	PWCTRL1						0xD0u			//
#define	PVGAMCTRL					0xE0u			//
#define	NVGAMCTRL					0xE1u			//

// Macros for controlling the LCD controller ST7789VW

#define	CMD_PARAMETER_00(commmande)																	\
																									\
	do {																							\
		local_LCD_WriteCommand(commmande);															\
	} while (0)

#define	CMD_PARAMETER_01(commmande, d1)																\
																									\
	do {																							\
		local_LCD_WriteCommand(commmande);															\
		local_LCD_WriteData(d1);																	\
	} while (0)

#define	CMD_PARAMETER_02(commmande, d1, d2)															\
																									\
	do {																							\
		local_LCD_WriteCommand(commmande);															\
		local_LCD_WriteData(d1);																	\
		local_LCD_WriteData(d2);																	\
	} while (0)

#define	CMD_PARAMETER_04(commmande, d1, d2, d3, d4)													\
																									\
	do {																							\
		local_LCD_WriteCommand(commmande);															\
		local_LCD_WriteData(d1);																	\
		local_LCD_WriteData(d2);																	\
		local_LCD_WriteData(d3);																	\
		local_LCD_WriteData(d4);																	\
	} while (0)

#define	CMD_PARAMETER_05(commmande, d1, d2, d3, d4, d5)												\
																									\
	do {																							\
		local_LCD_WriteCommand(commmande);															\
		local_LCD_WriteData(d1);																	\
		local_LCD_WriteData(d2);																	\
		local_LCD_WriteData(d3);																	\
		local_LCD_WriteData(d4);																	\
		local_LCD_WriteData(d5);																	\
	} while (0)

#define	CMD_PARAMETER_14(commmande, d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14)	\
																									\
	do {																							\
		local_LCD_WriteCommand(commmande);															\
		local_LCD_WriteData(d1);																	\
		local_LCD_WriteData(d2);																	\
		local_LCD_WriteData(d3);																	\
		local_LCD_WriteData(d4);																	\
		local_LCD_WriteData(d5);																	\
		local_LCD_WriteData(d6);																	\
		local_LCD_WriteData(d7);																	\
		local_LCD_WriteData(d8);																	\
		local_LCD_WriteData(d9);																	\
		local_LCD_WriteData(d10);																	\
		local_LCD_WriteData(d11);																	\
		local_LCD_WriteData(d12);																	\
		local_LCD_WriteData(d13);																	\
		local_LCD_WriteData(d14);																	\
	} while (0)
