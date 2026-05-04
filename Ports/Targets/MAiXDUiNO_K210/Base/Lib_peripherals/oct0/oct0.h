/*
; oct0.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Octo SPI manager (for lcd).
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
 * \defgroup oct0 Oct0
 *
 * \brief Oct0
 *
 * Oct0 management
 *
 * @{
 */

#define	KOCT0_NUM	(((uint32_t)'_'<<8) + (uint32_t)'0')
#define	KOCT0MAN	(KOCT0_NUM<<8u)

#define	KFILL		0u													// Fill without auto-incrementation
#define	KXFER8		1u													// Xfer 8-bits with auto-incrementation
#define	KXFER16		2u													// Xfer 16-bits with auto-incrementation

// Configuration structure
// -----------------------

typedef	struct	cnfOctx		cnfOctx_t;

struct cnfOctx {
			uint8_t		oMode;											// Mode
			#define		KDUAL			0u								// Dual spi
			#define		KQUAD			1u								// Quad spi
			#define		KOCTAL			2u								// Octo spi

			uint8_t		oNbBits;										// Number of bits

			uint8_t		oXfer;											// Xfer
			#define		K8BITSAINC		0u								// 8-bits with auto-incrementation
			#define		K16BITSAINC		1u								// 16-bits with auto-incrementation
			#define		K16BITSFILL		2u								// 16-bits without auto-incrementation

			uint8_t		oDevider;										// Clock divider
			#define		KCLKDIV2		0u								// Fclk / 2
			#define		KCLKDIV4		1u								// Fclk / 4
			#define		KCLKDIV8		2u								// Fclk / 8
			#define		KCLKDIV16		3u								// Fclk / 16
			#define		KCLKDIV32		4u								// Fclk / 32
			#define		KCLKDIV64		5u								// Fclk / 64
			#define		KCLKDIV128		6u								// Fclk / 128
			#define		KCLKDIV256		7u								// Fclk / 256
};

/*!
 * \brief Initialise the oct0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = oct0_init(void);
 * \endcode
 *
 * \return		KERR_OCT0_NOERR	OK
 * \return		KERR_OCT0_GEERR	General error
 *
 */
extern	int32_t	oct0_init(void);

/*!
 * \brief Configure the oct0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * const      cnfOctx_t    configure = {
 *                             .oMode     = KOCTAL,
 *                             .oNbBits   = 8,
 *                             .oXfer     = K8BITSAINC,
 *                             .oDevider  = KCLKDIV128,
 *                         };
 *
 *    status = oct0_configure(&configure);
 * \endcode
 *
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_OCT0_NOERR	OK
 * \return		KERR_OCT0_GEERR	General error
 *
 */
extern	int32_t	oct0_configure(const cnfOctx_t *configure);

/*!
 * \brief Write data to the oct0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint32_t    chipSelect = 1;
 * uint8_t     buffer[3] =  { 0, 1, 2 };
 * uint32_t    xferMode = FILL;
 *
 *    status = oct0_write(chipSelect, buffer, 3, xferMode);
 * \endcode
 *
 * \param[in]	chipSelect		The chip select
 * \param[in]	*buffer			Ptr on the buffer to write
 * \param[in]	szBuffer		Size of the buffer
 * \param[in]	xferMode		Xfer mode (KFILL, KXFER8, KXFER16)
 * \return		KERR_OCT0_NOERR	OK
 * \return		KERR_OCT0_GEERR	General error
 *
 */
extern	int32_t	oct0_write(uint32_t chipSelect, const void *buffer, uint32_t szBuffer, uint32_t xferMode);

#if (defined(__cplusplus))
}
#endif

// oct0 manager errors
// -------------------

//					Negative				 Family Lib Id							Lib Id xx (error)
#define	KOCT0ERR	((uint32_t)0x80000000u | ((uint32_t)KID_FAM_PERIPHERALS<<24u) | KOCT0MAN)

enum : int32_t {
	KERR_OCT0_NOERR = 0,							// No error
	KERR_OCT0_SYCNA = (int32_t)(KOCT0ERR + 1u),		// System call not available
	KERR_OCT0_GEERR									// General error
};

/**@}*/
/**@}*/
