/*
; imager_commun.
; ==============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		imager_commun equates.
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

/*!
 * \addtogroup Lib_peripherals
 */
/**@{*/

/*!
 * \defgroup imager_commun Imager_commun
 *
 * \brief Imager_commun
 *
 * Imager_commun management
 *
 * @{
 */

#define		KIMAGER_SINGLE_BUFFER	0x80u						// Single buffer
#define		KIMAGER_NB_ROWS_QVGA	240u						// Number of rows (QVGA)
#define		KIMAGER_NB_COLS_QVGA	320u						// Number of columns (QVGA)

// Configuration structure
// -----------------------

typedef	struct	imagerCnf	imagerCnf_t;

struct imagerCnf {
			uint8_t		oAcqMode;								// Acquisition mode
			uint8_t		oPixMode;								// Pixel mode
			uint16_t	oStRows;								// Start of rows
			uint16_t	oStCols;								// Start of cols
			uint16_t	oImagerNbCols;							// Number of the imager cols
			uint16_t	oImagerNbRows;							// Number of the imager rows
			uint16_t	oFrameNbCols;							// Number of the frame cols
			uint16_t	oFrameNbRows;							// Number of the frame rows
			uint8_t		oKernSync;								// uKernel synchro
			void		*oImgCnf;								// Imager configuration table
			void		(*oHSync)(void);						// Ptr on the callback HSync routine
			void		(*oFrame)(void);						// Ptr on the callback Frame routine
			void		(*oVSync)(void);						// Ptr on the callback VSync routine
			void		(*oDMAEc)(void);						// Ptr on the callback DMAEc routine
};

// Pixel mode (Bits per pixel) (oPixMode)

enum {
			KIMAGER_PIX_8_BITS = 0u,							// 8-bit resolution
			KIMAGER_PIX_10_BITS,								// 10-bit resolution
			KIMAGER_PIX_12_BITS,								// 12-bit resolution
			KIMAGER_PIX_14_BITS									// 14-bit resolution
};

// Kernel synchro semaphores

enum {
			BIMAGER_SEMAPHORE_IM = 0u,							// IM semaphore
			BIMAGER_SEMAPHORE_VS								// Vertical synchro semaphore
};

// Acquisition modes

enum {
			KIMAGER_CONT = 0u,									// Continuous mode
			KIMAGER_SNAP,										// Snapshot mode
			KIMAGER_SYNC										// Sync mode
};

// Operation modes

enum {
			KIMAGER_OPERATE = 0u,								// Imager in a normal mode (run)
			KIMAGER_STANDBY										// Imager in standby
};

/**@}*/
/**@}*/
