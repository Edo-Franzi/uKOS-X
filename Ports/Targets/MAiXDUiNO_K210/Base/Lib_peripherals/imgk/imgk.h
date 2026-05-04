/*
; imgk.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		imgk manager.
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
 * \defgroup imgk Imgk
 *
 * \brief Imgk
 *
 * Imgk management
 *
 * @{
 */

#define	KIMGK_NUM	(((uint32_t)'_'<<8u) + (uint32_t)'3')
#define	KIMGKMAN	(KIMGK_NUM<<8u)

// Configuration structure
// -----------------------

typedef	struct	cnfImgk	cnfImgk_t;

struct cnfImgk {
			uint8_t		oPixMode;										// Pixel mode
			#define		KPIX_8_BITS				0u						// KPIX_8_BITS  = 8-bit resolution

			uint16_t	oStRows;										// Start of rows
			uint16_t	oNbRows;										// Number of rows
			#define		KIMAGER_NB_ROWS_QVGA	240u					// Number of rows (QVGA)

			uint16_t	oStCols;										// Start of cols
			uint16_t	oNbCols;										// Number of cols
			#define		KIMAGER_NB_COLS_QVGA	320u					// Number of columns (QVGA)
};

// Semaphores
// ----------

#define	KIMGK_SEMAPHORE_AQ		"imgk - Acquisition"
#define	KIMGK_SEMAPHORE_IM		"imgk - img OK"
#define	KIMGK_MUTEX_RESERVE		"Reserve_imgk"

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	IMGK_reserve	imgk_reserve
#define	IMGK_release	imgk_release

/*!
 * \brief Reserve the imgk manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imgk_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    imgk_xyz();
 *    ....
 *    status = imgk_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \param[in]	timeout			Timeout (1-ms of resolution)
 * \return		KERR_IMGK_NOERR	The manager is reserved
 * \return		KERR_IMGK_GEERR	General error
 * \return	  	KERR_IMGK_CHBSY	The manager is busy
 *
 */
extern	int32_t	imgk_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the imgk manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imgk_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \return		KERR_IMGK_NOERR	OK
 * \return		KERR_IMGK_GEERR	General error
 * \return		KERR_IMGK_CAREL	Cannot release the manager
 *
 */
extern	int32_t	imgk_release(reserveMode_t reserveMode);

/*!
 * \brief Configure the imgk manager
 *
 * Call example in C:
 *
 * \code{.c}
 * // Example of table concerns the OV2640 imager
 * // See tables 12-13 of the OV2640
 * // Initialisation table proposed in the document OV2640 Camera Module
 * // Software Application Note, chapter 13.2 RGB 565 Referce setting
 * // Mclk = 24-MHz, SVGA RGB565, output 25-fps
 *
 * static    const    ov2640_t    aOV2640_Cnf[] = {
 *                                      { 0xFF, 0x01 }, { 0x12, 0x80 }, { 0xFF, 0x00 }, { 0x2C, 0xFF }, { 0x2E, 0xDF }, { 0xFF, 0x01 }, { 0x3C, 0x32 }, { 0x11, 0x00 },
 *                                      { 0x09, 0x02 }, { 0x04, 0x28 }, { 0x13, 0xE5 }, { 0x14, 0x48 }, { 0x2C, 0x0C }, { 0x33, 0x78 }, { 0x3A, 0x33 }, { 0x3B, 0xFB },
 *                                      { 0x3E, 0x00 }, { 0x43, 0x11 }, { 0x16, 0x10 }, { 0x39, 0x92 }, { 0x35, 0xDA }, { 0x22, 0x1A }, { 0x37, 0xC3 }, { 0x23, 0x00 },
 *                                      { 0x34, 0xC0 }, { 0x36, 0x1A }, { 0x06, 0x88 }, { 0x07, 0xC0 }, { 0x0D, 0x87 }, { 0x0E, 0x41 }, { 0x4C, 0x00 }, { 0x48, 0x00 },
 *                                      { 0x5B, 0x00 }, { 0x42, 0x03 }, { 0x4A, 0x81 }, { 0x21, 0x99 }, { 0x24, 0x40 }, { 0x25, 0x38 }, { 0x26, 0x82 }, { 0x5C, 0x00 },
 *                                      { 0x63, 0x00 }, { 0x46, 0x22 }, { 0x0C, 0x3C }, { 0x61, 0x70 }, { 0x62, 0x80 }, { 0x7C, 0x05 }, { 0x20, 0x80 }, { 0x28, 0x30 },
 *                                      { 0x6C, 0x00 }, { 0x6D, 0x80 }, { 0x6E, 0x00 }, { 0x70, 0x02 }, { 0x71, 0x94 }, { 0x73, 0xC1 }, { 0x12, 0x40 }, { 0x17, 0x11 },
 *                                      { 0x18, 0x43 }, { 0x19, 0x00 }, { 0x1A, 0x4B }, { 0x32, 0x09 }, { 0x37, 0xC0 }, { 0x4F, 0xCA }, { 0x50, 0xA8 }, { 0x5A, 0x23 },
 *                                      { 0x6D, 0x00 }, { 0x3D, 0x38 }, { 0xFF, 0x00 }, { 0xE5, 0x7F }, { 0xF9, 0xC0 }, { 0x41, 0x24 }, { 0xE0, 0x14 }, { 0x76, 0xFF },
 *                                      { 0x33, 0xA0 }, { 0x42, 0x20 }, { 0x43, 0x18 }, { 0x4C, 0x00 }, { 0x87, 0xD5 }, { 0x88, 0x3F }, { 0xD7, 0x03 }, { 0xD9, 0x10 },
 *                                      { 0xD3, 0x82 }, { 0xC8, 0x08 }, { 0xC9, 0x80 }, { 0x7C, 0x00 }, { 0x7D, 0x00 }, { 0x7C, 0x03 }, { 0x7D, 0x48 }, { 0x7D, 0x48 },
 *                                      { 0x7C, 0x08 }, { 0x7D, 0x20 }, { 0x7D, 0x10 }, { 0x7D, 0x0E }, { 0x90, 0x00 }, { 0x91, 0x0E }, { 0x91, 0x1A }, { 0x91, 0x31 },
 *                                      { 0x91, 0x5A }, { 0x91, 0x69 }, { 0x91, 0x75 }, { 0x91, 0x7E }, { 0x91, 0x88 }, { 0x91, 0x8F }, { 0x91, 0x96 }, { 0x91, 0xA3 },
 *                                      { 0x91, 0xAF }, { 0x91, 0xC4 }, { 0x91, 0xD7 }, { 0x91, 0xE8 }, { 0x91, 0x20 }, { 0x92, 0x00 }, { 0x93, 0x06 }, { 0x93, 0xE3 },
 *                                      { 0x93, 0x05 }, { 0x93, 0x05 }, { 0x93, 0x00 }, { 0x93, 0x04 }, { 0x93, 0x00 }, { 0x93, 0x00 }, { 0x93, 0x00 }, { 0x93, 0x00 },
 *                                      { 0x93, 0x00 }, { 0x93, 0x00 }, { 0x93, 0x00 }, { 0x96, 0x00 }, { 0x97, 0x08 }, { 0x97, 0x19 }, { 0x97, 0x02 }, { 0x97, 0x0C },
 *                                      { 0x97, 0x24 }, { 0x97, 0x30 }, { 0x97, 0x28 }, { 0x97, 0x26 }, { 0x97, 0x02 }, { 0x97, 0x98 }, { 0x97, 0x80 }, { 0x97, 0x00 },
 *                                      { 0x97, 0x00 }, { 0xC3, 0xED }, { 0xA4, 0x00 }, { 0xA8, 0x00 }, { 0xC5, 0x11 }, { 0xC6, 0x51 }, { 0xBF, 0x80 }, { 0xC7, 0x10 },
 *                                      { 0xB6, 0x66 }, { 0xB8, 0xA5 }, { 0xB7, 0x64 }, { 0xB9, 0x7C }, { 0xB3, 0xAF }, { 0xB4, 0x97 }, { 0xB5, 0xFF }, { 0xB0, 0xC5 },
 *                                      { 0xB1, 0x94 }, { 0xB2, 0x0F }, { 0xC4, 0x5C }, { 0xC0, 0x64 }, { 0xC1, 0x4B }, { 0x8C, 0x00 }, { 0x86, 0x3D }, { 0x50, 0x00 },
 *                                      { 0x51, 0xC8 }, { 0x52, 0x96 }, { 0x53, 0x00 }, { 0x54, 0x00 }, { 0x55, 0x00 }, { 0x5A, 0xC8 }, { 0x5B, 0x96 }, { 0x5C, 0x00 },
 *                                      { 0xD3, 0x82 }, { 0xC3, 0xED }, { 0x7F, 0x00 }, { 0xDA, 0x08 }, { 0xE5, 0x1F }, { 0xE1, 0x67 }, { 0xE0, 0x00 }, { 0xDD, 0x7F },
 *                                      { 0x05, 0x00 }
 *                                 };
 *
 * int32_t    status;
 * const      cnfImgk_t    configure = {
 *                             .oPixMode  = PIX8BITS;
 *                             .oNbRows   = 60;
 *                             .oNbCols   = 60;
 *                         };
 *
 *    status = imgk_configure(&configure);
 *
 * static    void    _myRoutine(void) {
 *
 * }
 * \endcode
 *
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_IMGK_NOERR	OK
 * \return		KERR_IMGK_GEERR	General error
 * \return		KERR_IMGK_TIMEO	Timeout error
 * \return		KERR_IMGK_NOMEM	Not enough memory
 *
 */
extern	int32_t	imgk_configure(const cnfImgk_t *configure);

/*!
 * \brief Acquisition of an image
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imgk_acquisition();
 * \endcode
 *
 * \return		KERR_IMGK_NOERR	OK
 * \return		KERR_IMGK_GEERR	General error
 * \return		KERR_IMGK_TIMEO	Timeout error
 *
 */
extern	int32_t	imgk_acquisition(void);

/*!
 * \brief Get the image pointer
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * uint8_t    *image;
 *
 *    status = imgk_getImage(&image);
 * \endcode
 *
 * \param[out]	**image			Ptr on the image
 * \return		KERR_IMGK_NOERR	OK
 * \return		KERR_IMGK_GEERR	General error
 *
 */
extern	int32_t	imgk_getImage(volatile void **image);

#if (defined(__cplusplus))
}
#endif

// imgk manager errors
// -------------------

//					Negative				 Family Lib Id							Lib Id xx (error)
#define	KIMGKERR	((uint32_t)0x80000000u | ((uint32_t)KID_FAM_PERIPHERALS<<24u) | KIMGKMAN)

enum : int32_t {
	KERR_IMGK_NOERR = 0, 							// No error
	KERR_IMGK_SYCNA = (int32_t)(KIMGKERR + 1u),		// System call not available
	KERR_IMGK_GEERR,								// General error
	KERR_IMGK_CNERR,								// Configuration error
	KERR_IMGK_TIMEO,								// Timeout error
	KERR_IMGK_CHBSY,								// The manager is busy
	KERR_IMGK_PGNOE,								// The image page does not exist
	KERR_IMGK_BDMOD,								// Bad mode for called function
	KERR_IMGK_NOMEM,								// Not enough memory
	KERR_IMGK_CAREL									// Cannot release the manager
};

/**@}*/
/**@}*/
