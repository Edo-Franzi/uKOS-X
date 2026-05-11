/*
; tft0.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		tft0 manager (for nt35310).
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
 * \defgroup tftx Tft0
 *
 * \brief Tft0
 *
 * Tft0 management
 *
 * @{
 */

#define	KTFT0_NUM	(((uint32_t)'_'<<8u) + (uint32_t)'1')
#define	KTFT0MAN	(KTFT0_NUM<<8u)

// NT35310 TFT controller commands

#define KNO_OPERATION				0x00u
#define KSOFTWARE_RESET				0x01u
#define KREAD_ID					0x04u
#define KREAD_STATUS				0x09u
#define KREAD_POWER_MODE			0x0Au
#define KREAD_MADCTL				0x0Bu
#define KREAD_PIXEL_FORMAT			0x0Cu
#define KREAD_IMAGE_FORMAT			0x0Du
#define KREAD_SIGNAL_MODE			0x0Eu
#define KREAD_SELT_DIAG_RESULT		0x0Fu
#define KSLEEP_ON					0x10u
#define KSLEEP_OFF					0x11u
#define KPARTIAL_DISPALY_ON			0x12u
#define KNORMAL_DISPALY_ON			0x13u
#define KINVERSION_DISPALY_OFF		0x20u
#define KINVERSION_DISPALY_ON		0x21u
#define KGAMMA_SET					0x26u
#define KDISPALY_OFF				0x28u
#define KDISPALY_ON					0x29u
#define KHORIZONTAL_ADDRESS_SET		0x2Au
#define KVERTICAL_ADDRESS_SET		0x2Bu
#define KMEMORY_WRITE				0x2Cu
#define KCOLOR_SET					0x2Du
#define KMEMORY_READ				0x2Eu
#define KPARTIAL_AREA				0x30u
#define KVERTICAL_SCROL_DEFINE		0x33u
#define KTEAR_EFFECT_LINE_OFF		0x34u
#define KTEAR_EFFECT_LINE_ON		0x35u
#define KMEMORY_ACCESS_CTL			0x36u
#define KVERTICAL_SCROL_S_ADD		0x37u
#define KIDLE_MODE_OFF				0x38u
#define KIDLE_MODE_ON				0x39u
#define KPIXEL_FORMAT_SET			0x3Au
#define KWRITE_MEMORY_CONTINUE		0x3Cu
#define KREAD_MEMORY_CONTINUE		0x3Eu
#define KSET_TEAR_SCANLINE			0x44u
#define KGET_SCANLINE				0x45u
#define KWRITE_BRIGHTNESS			0x51u
#define KREAD_BRIGHTNESS			0x52u
#define KWRITE_CTRL_DISPALY			0x53u
#define KREAD_CTRL_DISPALY			0x54u
#define KWRITE_BRIGHTNESS_CTL		0x55u
#define KREAD_BRIGHTNESS_CTL		0x56u
#define KWRITE_MIN_BRIGHTNESS		0x5Eu
#define KREAD_MIN_BRIGHTNESS		0x5Fu
#define KREAD_ID1					0xDAu
#define KREAD_ID2					0xDBu
#define KREAD_ID3					0xDCu
#define KRGB_IF_SIGNAL_CTL			0xB0u
#define KNORMAL_FRAME_CTL			0xB1u
#define KIDLE_FRAME_CTL				0xB2u
#define KPARTIAL_FRAME_CTL			0xB3u
#define KINVERSION_CTL				0xB4u
#define KBLANK_PORCH_CTL			0xB5u
#define KDISPALY_FUNCTION_CTL		0xB6u
#define KENTRY_MODE_SET				0xB7u
#define KBACKLIGHT_CTL1				0xB8u
#define KBACKLIGHT_CTL2				0xB9u
#define KBACKLIGHT_CTL3				0xBAu
#define KBACKLIGHT_CTL4				0xBBu
#define KBACKLIGHT_CTL5				0xBCu
#define KBACKLIGHT_CTL7				0xBEu
#define KBACKLIGHT_CTL8				0xBFu
#define KPOWER_CTL1					0xC0u
#define KPOWER_CTL2					0xC1u
#define KVCOM_CTL1					0xC5u
#define KVCOM_CTL2					0xC7u
#define KNV_MEMORY_WRITE			0xD0u
#define KNV_MEMORY_PROTECT_KEY		0xD1u
#define KNV_MEMORY_STATUS_READ		0xD2u
#define KREAD_ID4					0xD3u
#define KPOSITIVE_GAMMA_CORRECT		0xE0u
#define KNEGATIVE_GAMMA_CORRECT		0xE1u
#define KDIGITAL_GAMMA_CTL1			0xE2u
#define KDIGITAL_GAMMA_CTL2			0xE3u
#define KINTERFACE_CTL				0xF6u

#define SPI_CHANNEL					0u
#define SPI_SLAVE_SELECT			3u

/*!
 * \brief Initialise the tft0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = tft0_init(void);
 * \endcode
 *
 * \return		KOTFT0NOERR	OK
 * \return		KOTFT0GEERR	General error
 *
 */
extern	int32_t	tft0_init(void);

/*
 * \brief Write command to the tft0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint8_t     command =  COLOR_SET;
 * uint32_t    xferMode = FILL;
 *
 *    status = tft0_writeCommand(command);
 * \endcode
 *
 * \param[in]	command			The command
 * \return		KERR_TFT0_NOERR	OK
 * \return		KERR_TFT0_GEERR	General error
 *
 */
extern	int32_t	tft0_writeCommand(uint8_t command);

/*
 * \brief Write a byte to the tft0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint8_t     buffer[23] =  { 0, 1, 2 };
 *
 *    status = tft0_write8(buffer, 23);
 * \endcode
 *
 * \param[in]	*buffer			Ptr on the buffer to write
 * \param[in]	szBuffer		Size of the buffer
 * \return		KERR_TFT0_NOERR	OK
 * \return		KERR_TFT0_GEERR	General error
 *
 */
extern	int32_t	tft0_write8(const uint8_t *buffer, uint32_t szBuffer);

/*
 * \brief Write a word to the tft0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint16_t    buffer[23] =  { 0, 1, 2 };
 *
 *    status = tft0_write16(buffer, 23);
 * \endcode
 *
 * \param[in]	*buffer			Ptr on the buffer to write
 * \param[in]	szBuffer		Size of the buffer
 * \return		KERR_TFT0_NOERR	OK
 * \return		KERR_TFT0_GEERR	General error
 *
 */
extern	int32_t	tft0_write16(const uint16_t *buffer, uint32_t szBuffer);

/*
 * \brief Fill a word to the tft0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint16_t    color =  KMAGENTA;
 *
 *    status = tft0_fill16(buffer, 23);
 * \endcode
 *
 * \param[in]	*buffer			Ptr on the buffer to write
 * \param[in]	szBuffer		Size of the buffer
 * \return		KERR_TFT0_NOERR	OK
 * \return		KERR_TFT0_GEERR	General error
 *
 */
extern	int32_t	tft0_fill16(const uint16_t *buffer, uint32_t szBuffer);

#if (defined(__cplusplus))
}
#endif

// tft0 manager errors
// -------------------

//					Negative				 Family Lib Id							Lib Id xx (error)
#define	KTFT0ERR	((uint32_t)0x80000000u | ((uint32_t)KID_FAM_PERIPHERALS<<24u) | KTFT0MAN)

enum : int32_t {
	KERR_TFT0_NOERR = 0,							// No error
	KERR_TFT0_SYCNA = (int32_t)(KTFT0ERR + 1u),		// System call not available
	KERR_TFT0_GEERR									// General error
};

/**@}*/
/**@}*/
