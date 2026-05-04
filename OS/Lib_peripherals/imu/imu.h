/*
; imu.
; ====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		imu manager.
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
 * \defgroup imu Imu
 *
 * \brief Imu
 *
 * Imu management
 *
 * @{
 */

// Semaphores
// ----------

#define	KIMU_MUTEX_RESERVE	"Reserve_imu"

// Configuration structure
// -----------------------

typedef	struct	imuCnf			imuCnf_t;
typedef	struct	imuAccePack		imuAccePack_t;
typedef	struct	imuGyroPack		imuGyroPack_t;
typedef	struct	imuMagnPack		imuMagnPack_t;

struct imuCnf {
			uint8_t		oAcceMode;								// Acceleration mode
			uint8_t		oGyroMode;								// Gyroscope mode
			uint8_t		oMagnMode;								// Magnetometer mode
};

// Data access

struct imuAccePack {
			float64_t	oAcce_X;								// X Accelerometer
			float64_t	oAcce_Y;								// Y Accelerometer
			float64_t	oAcce_Z;								// Z Accelerometer
};

struct imuGyroPack {
			float64_t	oGyro_X;								// X gyroscope
			float64_t	oGyro_Y;								// Y gyroscope
			float64_t	oGyro_Z;								// Z gyroscope
};

struct imuMagnPack {
			float64_t	oMagn_X;								// X magnetometer
			float64_t	oMagn_Y;								// Y magnetometer
			float64_t	oMagn_Z;								// Z magnetometer
};

// Acceleration mode

enum {
			KIMU_MAX_2G = 0u,									// +/- 2-g
			KIMU_MAX_4G,										// +/- 4-g
			KIMU_MAX_8G,										// +/- 8-g
			KIMU_MAX_16G										// +/- 16-g
};

// Giroscope mode

enum {
			KIMU_MAX_245DPS = 0u,								// +/- 245-dps
			KIMU_MAX_500DPS,									// +/- 500-dps
			KIMU_MAX_2000DPS									// +/- 2000-dps
};

//  Magnetometer mode

enum {
			KIMU_MAX_4GAUSS = 0u,								// +/- 4-gauss
			KIMU_MAX_8GAUSS,									// +/- 8-gauss
			KIMU_MAX_12GAUSS,									// +/- 12-gauss
			KIMU_MAX_16GAUSS									// +/- 16-gauss
};

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	IMU_reserve		imu_reserve
#define	IMU_release		imu_release

/*!
 * \brief Reserve the imu manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imu_reserve(KMODE_READ_WRITEL, 1234);
 *    ....
 *    imu_xyz();
 *    ....
 *    status = imu_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \param[in]	timeout			Timeout (1-ms of resolution)
 *								KWAIT_INFINITY, waiting forever
 *								KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_IMU_NOERR	The manager is reserved
 * \return		KERR_IMU_GEERR	General error
 * \return		KERR_IMU_CHBSY	The manager is busy
 *
 */
extern	int32_t	imu_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the imu manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imu_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \return		KERR_IMU_NOERR	OK
 * \return		KERR_IMU_GEERR	General error
 * \return		KERR_IMU_CAREL	Cannot release the manager
 *
 */
extern	int32_t	imu_release(reserveMode_t reserveMode);

/*!
 * \brief Configure the imu manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t      status;
 * const    cnfImux_t    configure = {
 *                           .oAcceMode = KIMU_MAX_4G;
 *                           .oGyroMode = KIMU_MAX_2000DPS;
 *                           .oMagnMode = KIMU_MAX_8GAUSS;
 *                       };
 *
 *    status = imu_configure(&configure);
 * \endcode
 *
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_IMU_NOERR	OK
 * \return		KERR_IMU_GEERR	General error
 *
 */
extern	int32_t	imu_configure(const imuCnf_t *configure);

/*!
 * \brief Read the imu pack
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t           status;
 * imuAccePack_t    accelerometer;
 * imuGyroPack_t    gyroscope;
 * imuMagnPack_t    magnetometer;
 *
 *    status = imu_read(&accelerometer, &gyroscope, &magnetometer);
 *    dprintf(KSYST, “%3f %3f %3f,   %3f %3f %3f,   %3f %3f %3f\n”, \
 *                                                                  accelerometer.oAcce_X, \
 *                                                                  accelerometer.oAcce_Y, \
 *                                                                  accelerometer.oAcce_Z, \
 *                                                                  gyroscope.oGyro_X, \
 *                                                                  gyroscope.oGyro_Y, \
 *                                                                  gyroscope.oGyro_Z, \
 *                                                                  magnetometer.oMagn_X, \
 *                                                                  magnetometer.oMagn_Y, \
 *                                                                  magnetometer.oMagn_Z);
 * \endcode
 *
 * \param[out]	*accelerometer	Ptr on the accelerometer pack
 * \param[out]	*gyroscope		Ptr on the gyroscope pack
 * \param[out]	*magnetometer	Ptr on the magnetometer pack
 * \return		KERR_IMU_NOERR	OK
 * \return		KERR_IMU_GEERR	General error
 *
 */
extern	int32_t	imu_read(imuAccePack_t *accelerometer, imuGyroPack_t *gyroscope, imuMagnPack_t *magnetometer);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
