/*
; imager.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		imager manager.
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
 * \defgroup imager Imager
 *
 * \brief Imager
 *
 * Imager management
 *
 * @{
 */

#include	"Lib_peripherals/imager_common.h"

// Semaphores
// ----------

#define	KIMAGER_SEMAPHORE_VS	"imager - V synchro"
#define	KIMAGER_SEMAPHORE_IM	"imager - imge OK"
#define	KIMAGER_MUTEX_RESERVE	"Reserve_imager"

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	IMAGER_reserve	imager_reserve
#define	IMAGER_release	imager_release

/*!
 * \brief Reserve the imager manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imager_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    imager_xyz();
 *    ....
 *    status = imager_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode			Any mode
 * \param[in]	timeout				Timeout (1-ms of resolution)
 * \param[in]	-					KWAIT_INFINITY, waiting forever
 * \param[in]	-					KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_IMAGER_NOERR	The manager is reserved
 * \return		KERR_IMAGER_GEERR	General error
 * \return		KERR_IMAGER_CHBSY	The manager is busy
 *
 */
extern	int32_t	imager_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the imager manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imager_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode			Any mode
 * \return		KERR_IMAGER_NOERR	OK
 * \return		KERR_IMAGER_GEERR	General error
 * \return		KERR_IMAGER_CAREL	Cannot release the manager
 *
 */
extern	int32_t	imager_release(reserveMode_t reserveMode);

/*!
 * \brief Configure the imager manager
 *
 * Call example in C:
 *
 * \code{.c}

 *           int32_t     status;
 *
 * // Image 60 x 60 pixels; this table concerns the Aptina MT9V032 imager
 * // Fixed exposure
 * static    const       mt9v032_t    aTab060060F[] = {
 *                                        { 1,   0x0001 }, { 2,   0x0005 }, { 3,   0x003C }, { 4,   0x003D },
 *                                        { 5,   0x026F }, { 6,   0x0032 }, { 7,   0x0388 }, { 8,   0x01E0 },
 *                                        { 9,   0x3FFE }, { 10,  0x0164 }, { 11,  0x001D }, { 16,  0x002D },
 *                                        { 21,  0x8032 }, { 32,  0x03D5 }, { 33,  0x0018 }, { 34,  0x0028 },
 *                                        { 40,  0x0016 }, { 41,  0x001C }, { 43,  0x0003 }, { 44,  0x0006 },
 *                                        { 46,  0x0004 }, { 47,  0x0003 }, { 70,  0x1606 }, { 71,  0x8081 },
 *                                        { 72,  0x007F }, { 104, 0xE5F9 }, { 105, 0x65D7 }, { 106, 0x2950 },
 *                                        { 107, 0xA040 }, { 112, 0x0032 }, { 114, 0x0001 }, { 115, 0x0307 },
 *                                        { 116, 0x0010 }, { 128, 0x00F4 }, { 129, 0x0004 }, { 130, 0x0004 },
 *                                        { 131, 0x0004 }, { 132, 0x0004 }, { 133, 0x0004 }, { 134, 0x0004 },
 *                                        { 135, 0x0004 }, { 136, 0x0004 }, { 137, 0x0004 }, { 138, 0x0004 },
 *                                        { 139, 0x0004 }, { 140, 0x0004 }, { 141, 0x0004 }, { 142, 0x0004 },
 *                                        { 143, 0x0004 }, { 144, 0x0004 }, { 145, 0x0004 }, { 146, 0x0004 },
 *                                        { 147, 0x0004 }, { 148, 0x0004 }, { 149, 0x0004 }, { 150, 0x0004 },
 *                                        { 151, 0x0004 }, { 152, 0x0004 }, { 154, 0x003B }, { 155, 0x02F0 },
 *                                        { 156, 0x02F0 }, { 157, 0x02F0 }, { 160, 0x003B }, { 161, 0x01E0 },
 *                                        { 162, 0x01E0 }, { 163, 0x01E0 }, { 165, 0x0020 }, { 166, 0x0008 },
 *                                        { 168, 0x0001 }, { 169, 0x0008 }, { 171, 0x0001 }, { 175, 0x0000 },
 *                                        { 176, 0x01B0 }, { 189, 0x006C }, { 194, 0x0850 }, { 0,   0x0000 }
 *                                    };
 * *
 * #if (defined(SINGLE_BUFFER_S))
 * const    cnfImgx_t    configure = {
 *                           .oAcqMode  = KIMAGER_CONT | KIMAGER_SINGLE_BUFFER;
 *                           .oPixMode  = KIMAGER_PIX_8_BITS;
 *                           .oNbRows   = 60;
 *                           .oNbCols   = 60;
 *                           .oKernSync = (1u<<BIMAGER_SEMAPHORE_IM) | (1u<<BIMAGER_SEMAPHORE_VS);
 *                           .oHSync    = nullptr;
 *                           .oFrame    = nullptr;
 *                           .oVSync    = nullptr;
 *                           .oDMAEc    = _myRoutine;
 *                           .oImgCnf   = (void *)aTab060060F;
 *                       };
 *
 * #else
 * const    cnfImgx_t    configure = {
 *                           .oAcqMode  = KIMAGER_CONT;
 *                           .oPixMode  = KIMAGER_PIX_8_BITS;
 *                           .oNbRows   = 60;
 *                           .oNbCols   = 60;
 *                           .oKernSync = (1u<<BIMAGER_SEMAPHORE_IM) | (1u<<BIMAGER_SEMAPHORE_VS);
 *                           .oHSync    = nullptr;
 *                           .oFrame    = nullptr;
 *                           .oVSync    = nullptr;
 *                           .oDMAEc    = _myRoutine;
 *                           .oImgCnf   = (void *)aTab060060F;
 *                       };
 * #endif
 *
 *    status = imager_configure(&configure);
 *
 * static    void    _myRoutine(void) {
 *
 * }
 * \endcode
 *
 * \param[in]	*configure			Ptr on the configuration buffer
 * \return		KERR_IMAGER_NOERR	OK
 * \return		KERR_IMAGER_GEERR	General error
 * \return		KERR_IMAGER_TIMEO	Timeout error
 * \return		KERR_IMAGER_NOMEM	Not enough memory
 *
 */
extern	int32_t	imager_configure(const imagerCnf_t *configure);

/*!
 * \brief Acquisition of an image
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imager_acquisition();
 * \endcode
 *
 * \param[in]	-
 * \return		KERR_IMAGER_NOERR	OK
 * \return		KERR_IMAGER_GEERR	General error
 * \return		KERR_IMAGER_TIMEO	Timeout error
 *
 */
extern	int32_t	imager_acquisition(void);

/*!
 * \brief Read the image pointer
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * uint8_t    *image;
 *
 *    status = imager_read(&image);
 * \endcode
 *
 * \param[out]	**image				Ptr on the image
 * \return		KERR_IMAGER_NOERR	OK
 * \return		KERR_IMAGER_GEERR	General error
 *
 */
extern	int32_t	imager_read(volatile void **image);

/*!
 * \brief Read the value of an imager register
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint16_t    value;
 *
 *    status = imager_readRegister(0x34, &value);
 * \endcode
 *
 * \param[in]	registerNb			The register number
 * \param[out]	*value				Ptr on the value
 * \return		KERR_IMAGER_NOERR	OK
 * \return		KERR_IMAGER_GEERR	General error
 * \return		KERR_IMAGER_TIMEO	Timeout error
 *
 */
extern	int32_t	imager_readRegister(uint8_t registerNb, uint16_t *value);

/*!
 * \brief Write a value into an imager register
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint16_t    value = 0x1234;
 *
 *    status = imager_writeRegister(0x34, value);
 * \endcode
 *
 * \param[in]	registerNb			The register number
 * \param[in]	value				The value
 * \return		KERR_IMAGER_NOERR	OK
 * \return		KERR_IMAGER_GEERR	General error
 * \return		KERR_IMAGER_TIMEO	Timeout error
 *
 */
extern	int32_t	imager_writeRegister(uint8_t registerNb, uint16_t value);

/*!
 * \brief Control the standby mode of the imager (only in KIMAGER_SNAP mode)
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imager_standby(KIMAGER_STANDBY);
 * \endcode
 *
 * \param[in]	mode				KIMAGER_OPERATE, standby OFF
 * \param[in]	-					KIMAGER_STANDBY, standby ON
 * \return		KERR_IMAGER_NOERR	OK
 * \return		KERR_IMAGER_GEERR	General error
 * \return		KERR_IMAGER_BDMOD	Bad mode for called function
 *
 */
extern	int32_t	imager_standby(uint8_t mode);

/*!
 * \brief Write the exposure time
 *
 * \warning	After this call it is necessary to acqure a dummy image.
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imager_exposure(15000);
 * \endcode
 *
 * \param[in]	time				Integration time (-1 = auto-exposure)
 * \return		KERR_IMAGER_NOERR	OK
 * \return		KERR_IMAGER_GEERR	General error
 * \return		KERR_IMAGER_BDMOD	Bad mode for called function
 *
 */
extern	int32_t	imager_exposure(uint32_t time);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
