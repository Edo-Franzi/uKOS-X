/*
; imu.
; ====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

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

#include	"uKOS.h"

#if (defined(CONFIG_MAN_IMU_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"imu          imu manager.                              (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "imu manager\n"
									"===========\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Imu,							// Module name (the first letter has to be upper case)
	KID_FAM_PERIPHERALS,			// Family (defined in the module.h)
	KNUM_IMU,						// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

static	mutx_t		*vMutex_Reserve[KNB_CORES];

// Prototypes

static	int32_t		local_init(void);
extern	int32_t		stub_imu_init(void);
extern	int32_t		stub_imu_configure(const imuCnf_t *configure);
extern	int32_t		stub_imu_read(imuAccePack_t *accelerometer, imuGyroPack_t *gyroscope, imuMagnPack_t *magnetometer);

/*
 * \brief Reserve the imu manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imu_reserve(KMODE_READ_WRITEL, 1234u);
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
int32_t	imu_reserve(reserveMode_t reserveMode, uint32_t timeout) {
	int32_t		status;
	uint32_t	core;

	UNUSED(reserveMode);

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_IMU_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = kern_lockMutex(vMutex_Reserve[core], timeout);
	if (status != KERR_KERN_NOERR) {
		PRIVILEGE_RESTORE;
		return (KERR_IMU_CHBSY);
	}

	PRIVILEGE_RESTORE;
	return (KERR_IMU_NOERR);
}

/*
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
int32_t	imu_release(reserveMode_t reserveMode) {
	int32_t		status;
	uint32_t	core;

	UNUSED(reserveMode);

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_IMU_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = kern_unlockMutex(vMutex_Reserve[core]);
	if (status != KERR_KERN_NOERR) {
		PRIVILEGE_RESTORE;
		return (KERR_IMU_CAREL);
	}

	PRIVILEGE_RESTORE;
	return (KERR_IMU_NOERR);
}

/*
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
int32_t	imu_configure(const imuCnf_t *configure) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_IMU_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_imu_configure(configure);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Read the imu pack
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t            status;
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
int32_t	imu_read(imuAccePack_t *accelerometer, imuGyroPack_t *gyroscope, imuMagnPack_t *magnetometer) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_IMU_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_imu_read(accelerometer, gyroscope, magnetometer);
	PRIVILEGE_RESTORE;
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
static	int32_t	local_init(void) {
			int32_t		status = KERR_IMU_NOERR;
			uint32_t	core;
	static	bool		vInit[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vInit[core] == false) {
		vInit[core] = true;

		if (kern_createMutex(KIMU_MUTEX_RESERVE, &vMutex_Reserve[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "imu: create mutx"); exit(EXIT_OS_PANIC); }

		status = stub_imu_init();
	}
	RETURN_INT_RESTORE(status);
}

#endif
