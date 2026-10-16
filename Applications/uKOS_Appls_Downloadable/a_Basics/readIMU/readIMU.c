/*
; readIMU.
; ========
;
; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
;
;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application shows how to operate with the uKOS-X uKernel.
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

/*!
 * \file
 * \ingroup app_basic
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 2 processes:
 *
 *			- P0: Every 1000-ms
 *					- Toggle LED 1
 *
 *			- P1: Every 10-ms
 *					- Read the IMU (acc, gyro, magneto)
 *					- Filter the data
 *					- Display the values
 *
 *			Used for the scope observation.
 *
 *			If CoolTerm
 *			1. #define DISP_COOLTERM_S
 *			2. Use CoolTerm to display the results (using the Arduino format)
 *			3. Download a uKOS-X application (e.g. readIMU)
 *
 */

#include	"uKOS.h"
#include	<fcntl.h>
#include	<math.h>

#define		DISP_COOLTERM_S				// Display on the CoolTerm
										// Display on Sysquake

#if (defined(Alastor_H743_S))
#define		KCHANNEL	KURT1
#endif

#if (defined(Asmodee_H747_S))
#define		KCHANNEL	KCDC0
#endif

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"readIMU      Example of how to use the imu.            (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  readIMU\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

#if (defined(ROMABLE_S))

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	ReadIMU,							// Module name (the first letter has to be upper case)
	KID_FAM_CLI,						// Family (defined in the module.h)
	KNUM_ROMABLE_0,						// Module identifier (defined in the module.h)
	nullptr,							// Address of the initialisation code (early pre-init)
	prgm,								// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,							// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);

#else
MODULE(
	UserAppl,							// Module name (the first letter has to be upper case)
	KID_FAM_APPLICATIONS,				// Family (defined in the module.h)
	KNUM_APPLICATION,					// Module identifier (defined in the module.h)
	nullptr,							// Address of the initialisation code (early pre-init)
	aStart,								// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,							// Address of the clean code (clean the module)
	" 1.0",								// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),	// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0									// Execution cores
);
#endif

enum {
		KX_AXIS = 0u,
		KY_AXIS,
		KZ_AXIS,
		KNB_AXIS
};

#define	KDISPLAY_ACC		0u			// Display the acceleration
#define	KDISPLAY_GYRO		1u			// Display the gyroscope
#define	KDISPLAY_MAGNETO	2u			// Display the magetometer


// Prototypes

static	void	local_filter(float64_t ax_f,   float64_t ay_f,    float64_t az_f,
							 float64_t gx_f,   float64_t gy_f,    float64_t gz_f,
							 float64_t mx_f,   float64_t my_f,    float64_t mz_f,
							 float64_t *mAx_f, float64_t *mAy_f,  float64_t *mAz_f,
							 float64_t *mGx_f, float64_t *mGy_f,  float64_t *mGz_f,
							 float64_t *mMx_f, float64_t *mMy_f,  float64_t *mMz_f);

static	void	local_display(int32_t fpPrint,
							 uint8_t  mode,
							 float64_t mAx_f, float64_t mAy_f,  float64_t mAz_f,
							 float64_t mGx_f, float64_t mGy_f,  float64_t mGz_f,
							 float64_t mMx_f, float64_t mMy_f,  float64_t mMz_f);

/*
 * \brief aProcess 0
 *
 * - P0: Every 1000-ms
 *			- Toggle LED 1
 *
 */
[[noreturn]]
static	void	aProcess_0([[maybe_unused]] const void *argument) {

	while (true) {
		kern_suspendProcess(1000u);
		led_toggle(KLED_1);
	}
}

/*
 * \brief aProcess 1
 *
 * - P1: Every 10-ms
 *			- Read the IMU (acc, gyro, magneto)
 *			- Filter the data
 *			- Display the values
 *
 */
[[noreturn]]
static	void	aProcess_1([[maybe_unused]] const void *argument) {
					float64_t			mAcce_X_f, mAcce_Y_f, mAcce_Z_f;
					float64_t			mGyro_X_f, mGyro_Y_f, mGyro_Z_f;
					float64_t			mMagn_X_f, mMagn_Y_f, mMagn_Z_f;
					imuAccePack_t		accelerometer;
					imuGyroPack_t		gyroscope;
					imuMagnPack_t		magnetometer;
	static	const	imuCnf_t			configureIMU0 = {
											.oAcceMode = KIMU_MAX_8G,
											.oGyroMode = KIMU_MAX_2000DPS,
											.oMagnMode = KIMU_MAX_8GAUSS
										};

// Open and reserve a comm channel for write operations

	imu_configure(&configureIMU0);

	while (true) {
		kern_suspendProcess(10u);

		imu_read(&accelerometer, &gyroscope, &magnetometer);

		local_filter(accelerometer.oAcce_X_f, accelerometer.oAcce_Y_f, accelerometer.oAcce_Z_f,
					 gyroscope.oGyro_X_f,     gyroscope.oGyro_Y_f,     gyroscope.oGyro_Z_f,
					 magnetometer.oMagn_X_f,  magnetometer.oMagn_Y_f,  magnetometer.oMagn_Z_f,
					 &mAcce_X_f,			  &mAcce_Y_f,			   &mAcce_Z_f,
					 &mGyro_X_f,			  &mGyro_Y_f,			   &mGyro_Z_f,
					 &mMagn_X_f,			  &mMagn_Y_f,			   &mMagn_Z_f);

		local_display(KCHANNEL,
					  KDISPLAY_ACC,
					  mAcce_X_f, mAcce_Y_f, mAcce_Z_f,
					  mGyro_X_f, mGyro_Y_f, mGyro_Z_f,
					  mMagn_X_f, mMagn_Y_f, mMagn_Z_f);
	}
}

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
MAIN_ENTRY(argc, argv[]) {
	proc_t	*process_0, *process_1;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2026";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
	STRG_LOC_CONST(aStrText_1[]) = "Process user 1.                           (c) EFr-2026";

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use specification_x)
		aStrText_0,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_XLIB,				// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		aStrIden_0,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		1,									// Index
		specification_1,					// Specifications (just use specification_x)
		aStrText_1,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_XLIB,				// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_1,							// Code of the process
		aStrIden_1,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_MEDIUM_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, nullptr, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, nullptr, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_filter
 *
 * - Window filtering for the acceleration, the gyro and the magnetometer
 *
 */
#define	KFILTER		16u

static	void	local_filter(float64_t ax_f,   float64_t ay_f,    float64_t az_f,
							 float64_t gx_f,   float64_t gy_f,    float64_t gz_f,
							 float64_t mx_f,   float64_t my_f,    float64_t mz_f,
							 float64_t *mAx_f, float64_t *mAy_f,  float64_t *mAz_f,
							 float64_t *mGx_f, float64_t *mGy_f,  float64_t *mGz_f,
							 float64_t *mMx_f, float64_t *mMy_f,  float64_t *mMz_f) {

	static	uint8_t		i, k = 0u;
	static	float64_t	aFilter_f[KNB_AXIS][KFILTER];
	static	float64_t	gFilter_f[KNB_AXIS][KFILTER];
	static	float64_t	mFilter_f[KNB_AXIS][KFILTER];

// Window filtering

	aFilter_f[KX_AXIS][k] = ax_f; aFilter_f[KY_AXIS][k] = ay_f; aFilter_f[KZ_AXIS][k] = az_f;
	gFilter_f[KX_AXIS][k] = gx_f; gFilter_f[KY_AXIS][k] = gy_f; gFilter_f[KZ_AXIS][k] = gz_f;
	mFilter_f[KX_AXIS][k] = mx_f; mFilter_f[KY_AXIS][k] = my_f; mFilter_f[KZ_AXIS][k] = mz_f;

	*mAx_f = *mAy_f = *mAz_f = 0.0;
	*mGx_f = *mGy_f = *mGz_f = 0.0;
	*mMx_f = *mMy_f = *mMz_f = 0.0;

	for (i = 0u; i < KFILTER; i++) {
		*mAx_f += aFilter_f[KX_AXIS][i]; *mAy_f += aFilter_f[KY_AXIS][i]; *mAz_f += aFilter_f[KZ_AXIS][i];
		*mGx_f += gFilter_f[KX_AXIS][i]; *mGy_f += gFilter_f[KY_AXIS][i]; *mGz_f += gFilter_f[KZ_AXIS][i];
		*mMx_f += mFilter_f[KX_AXIS][i]; *mMy_f += mFilter_f[KY_AXIS][i]; *mMz_f += mFilter_f[KZ_AXIS][i];
	}
	*mAx_f = *mAx_f / KFILTER; *mAy_f = *mAy_f / KFILTER; *mAz_f = *mAz_f / KFILTER;
	*mGx_f = *mGx_f / KFILTER; *mGy_f = *mGy_f / KFILTER; *mGz_f = *mGz_f / KFILTER;
	*mMx_f = *mMx_f / KFILTER; *mMy_f = *mMy_f / KFILTER; *mMz_f = *mMz_f / KFILTER;

	k++; if (k == KFILTER) { k = 0u; };
}

/*
 * \brief local_display
 *
 * - Display the acceleration, the gyro or the magnetometer
 *
 */
static	void	local_display(int32_t fpPrint,
							  uint8_t  mode,
							  float64_t mAx_f, float64_t mAy_f,  float64_t mAz_f,
							  float64_t mGx_f, float64_t mGy_f,  float64_t mGz_f,
							  float64_t mMx_f, float64_t mMy_f,  float64_t mMz_f) {

	float64_t	x_f, y_f, z_f;

	switch (mode) {
		case KDISPLAY_ACC:	   { x_f = mAx_f; y_f = mAy_f; z_f = mAz_f; break; }
		case KDISPLAY_GYRO:	   { x_f = mGx_f; y_f = mGy_f; z_f = mGz_f; break; }
		case KDISPLAY_MAGNETO: { x_f = mMx_f; y_f = mMy_f; z_f = mMz_f; break; }
		default:			   { x_f = mAx_f; y_f = mAy_f; z_f = mAz_f; break; }
	}

// Print the results

	#if (defined(DISP_COOLTERM_S))
	(void)dprintf(fpPrint, "%f\t%f\t%f\n", x_f, y_f, z_f);
	#else

	uint32_t	sample = 0u;
	(void)dprintf(fpPrint, "%"PRIu32" %f %f %f\n", ++sample, x_f, y_f, z_f);
	#endif
}
