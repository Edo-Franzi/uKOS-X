/*
; W25X80L.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		EEPROM W25X80L equates.
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

// Memory structure

#define	KSPIM_SZ_SECTOR						4096u							// Sector size
#define	KSPIM_SZ_PAGE						256u							// Page size
#define	KSPIM_NB_SECTOR_BLOC				16u								// Number of sector by block
#define	KSPIM_NB_BLOC						16u								// Number of blocks
#define	KSPIM_SZ_FLASH						(KSZBLOC * KSPIM_NB_BLOC)		// EEPROM size

// Commands for the chip W25X80L

#define	KCMD_WR_STATUS						0x01u							// EEPROM write status command
#define	KCMD_WRITE							0x02u							// EEPROM write command
#define	KCMD_READ							0x03u							// EEPROM read command
#define	KCMD_WR_DISABLE						0x04u							// EEPROM write disable command
#define	KCMD_RD_STATUS						0x05u							// EEPROM read status command
#define	KCMD_WR_ENABLE						0x06u							// EEPROM write enable command
#define	KCMD_ERASE_SECTOR					0x20u							// EEPROM erase sector command
#define	KCMD_BULK_ERASE						0xC7u							// EEPROM bulk erase command

// Status bits for the chip W25X80L

#define	BBUSY								0u								// Erase or write in progress
#define	BWEL								1u								// Write enable latch
#define	BBP0								2u								// Block protect block 0
#define	BBP1								3u								// Block protect block 1
#define	BBP2								4u								// Block protect block 2
#define	BTB									5u								// Top/Bottom write protect
#define	BSRP								7u								// Status register protect
