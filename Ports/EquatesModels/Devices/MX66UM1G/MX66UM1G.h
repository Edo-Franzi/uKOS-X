/*
; MX66UM1G.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Flash MX66UM1G equates.
;
;			Notes: _xSPI_	usually available for spi, quad spi, octo spi, hexa spi
;				   _QSPI_	available for quad spi
;				   _OSPI_	available for octo spi
;				   _HSPI_	available for hexa spi
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

#define	KFLASH_xSPI_SZ_FLASH				(128u * 1024u * 1024u)							// FLASH size
#define	KFLASH_xSPI_SZ_SECTOR				4096u											// Sector size
#define	KFLASH_xSPI_NB_SECTOR				(KFLASH_xSPI_SZ_FLASH / KFLASH_xSPI_SZ_SECTOR)	// Number of sectors
#define	KFLASH_xSPI_SZ_PAGE					256u											// Page size
#define	KFLASH_xSPI_NB_PAGE					(KFLASH_xSPI_SZ_FLASH / KFLASH_xSPI_SZ_PAGE)	// Number of pages
#define	KFLASH_xSPI_SZ_BLOC					65536u											// Bloc size
#define	KFLASH_xSPI_NB_BLOC					(KFLASH_xSPI_SZ_FLASH / KFLASH_xSPI_SZ_BLOC)	// Number of blocs

// Commands for the chip MX66UM1G

#define	KFLASH_xSPI_CMD_WRITE_STATUS		0x01u											// FLASH write status command
#define	KFLASH_xSPI_CMD_WRITE				0x02u											// FLASH write command (pages of 256 bytes)
#define	KFLASH_xSPI_CMD_READ				0x03u											// FLASH read command
#define	KFLASH_xSPI_CMD_WRITE_DISABLE		0x04u											// FLASH write disable command
#define	KFLASH_xSPI_CMD_READ_STATUS			0x05u											// FLASH read status command
#define	KFLASH_xSPI_CMD_WRITE_ENABLE		0x06u											// FLASH write enable command
#define	KFLASH_xSPI_CMD_ERASE_SECTOR		0x20u											// FLASH erase sector command
#define	KFLASH_xSPI_CMD_ERASE_BLOC			0xD8u											// FLASH erase bloc command
#define	KFLASH_xSPI_CMD_ERASE_BULK			0xC7u											// FLASH bulk erase command

// Extension OCTO

#define	KFLASH_OSPI_CMD_READ_STATUS			0x05FAu											// FLASH read status 2 command
#define	KFLASH_OSPI_CMD_WRITE_STATUS		0x01FEu											// FLASH write status 2 command
#define	KFLASH_OSPI_CMD_READ				0xEC13u											// FLASH read quad command
#define	KFLASH_OSPI_CMD_WRITE				0x12EDu											// FLASH write quad command (pages of 256 bytes)
#define	KFLASH_OSPI_CMD_WRITE_ENABLE		0x06F9u											// FLASH write enable command
#define	KFLASH_OSPI_CMD_ERASE_SECTOR		0x21DEu											// FLASH erase sector command

// Status bits for the chip MX66UM1G

#define	BFLASH_xSPI_BUSY					0u												// Erase or write in progress
#define	BFLASH_xSPI_WEL						1u												// Write enable latch
#define	BFLASH_xSPI_BP0						2u												// Block protect block 0
#define	BFLASH_xSPI_BP1						3u												// Block protect block 1
#define	BFLASH_xSPI_BP2						4u												// Block protect block 2
#define	BFLASH_xSPI_BP2						5u												// Block protect block 2
