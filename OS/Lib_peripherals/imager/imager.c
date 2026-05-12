/*
; img0.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		img0 manager.
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

#if (defined(CONFIG_MAN_IMAGER_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"imager       imager manager.                           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "imager manager\n"
									"==============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Imager,							// Module name (the first letter has to be upper case)
	KID_FAM_PERIPHERALS,			// Family (defined in the module.h)
	KNUM_IMAGER,					// Module identifier (defined in the module.h)
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
extern	int32_t		stub_imager_init(void);
extern	int32_t		stub_imager_configure(const imagerCnf_t *configure);
extern	int32_t		stub_imager_acquisition(void);
extern	int32_t		stub_imager_read(volatile void **image);
extern	int32_t		stub_imager_getSerialNumber(uint64_t *serialNumber);
extern	int32_t		stub_imager_readRegister(uint8_t registerNb, uint16_t *value);
extern	int32_t		stub_imager_writeRegister(uint8_t registerNb, uint16_t value);
extern  int32_t		stub_imager_standby(uint8_t mode);
extern  int32_t		stub_imager_exposure(uint32_t time);

/*
 * \brief Reserve the imager manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = imager_reserve(KMODE_READ_WRITE, 1234u);
 *    ....
 *    imager_xyz();
 *    ....
 *    status = imager_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode			Any mode
 * \param[in]	timeout				Timeout (1-ms of resolution)
 *									KWAIT_INFINITY, waiting forever
 *									KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_IMAGER_NOERR	The manager is reserved
 * \return		KERR_IMAGER_GEERR	General error
 * \return		KERR_IMAGER_CHBSY	The manager is busy
 *
 */
int32_t	imager_reserve(reserveMode_t reserveMode, uint32_t timeout) {
	int32_t		status;
	uint32_t	core;

	UNUSED(reserveMode);

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_IMAGER_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = kern_lockMutex(vMutex_Reserve[core], timeout);
	if (status != KERR_KERN_NOERR) {
		PRIVILEGE_RESTORE;
		return (KERR_IMAGER_CHBSY);
	}

	PRIVILEGE_RESTORE;
	return (KERR_IMAGER_NOERR);
}

/*
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
int32_t	imager_release(reserveMode_t reserveMode) {
	int32_t		status;
	uint32_t	core;

	UNUSED(reserveMode);

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_IMAGER_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = kern_unlockMutex(vMutex_Reserve[core]);
	if (status != KERR_KERN_NOERR) {
		PRIVILEGE_RESTORE;
		return (KERR_IMAGER_CAREL);
	}

	PRIVILEGE_RESTORE;
	return (KERR_IMAGER_NOERR);
}

/*
 * \brief Configure the imager manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
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
int32_t	imager_configure(const imagerCnf_t *configure) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_IMAGER_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_imager_configure(configure);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
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
 * \return		KERR_IMAGER_NOERR	OK
 * \return		KERR_IMAGER_GEERR	General error
 * \return		KERR_IMAGER_TIMEO	Timeout error
 *
 */
int32_t	imager_acquisition(void) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_IMAGER_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_imager_acquisition();
	PRIVILEGE_RESTORE;
	return (status);
}

/*
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
int32_t	imager_read(volatile void **image) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_IMAGER_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_imager_read(image);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
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
int32_t	imager_readRegister(uint8_t registerNb, uint16_t *value) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_IMAGER_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_imager_readRegister(registerNb, value);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
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
int32_t	imager_writeRegister(uint8_t registerNb, uint16_t value) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_IMAGER_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_imager_writeRegister(registerNb, value);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
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
 *									KIMAGER_STANDBY, standby ON
 * \return		KERR_IMAGER_NOERR	OK
 * \return		KERR_IMAGER_GEERR	General error
 * \return		KERR_IMAGER_BDMOD	Bad mode for called function
 *
 */
int32_t	imager_standby(uint8_t mode) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_IMAGER_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_imager_standby(mode);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
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
int32_t	imager_exposure(uint32_t time) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_IMAGER_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_imager_exposure(time);
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
			int32_t		status = KERR_IMAGER_NOERR;
			uint32_t	core;
	static	bool		vInit[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vInit[core] == false) {
		vInit[core] = true;

		if (kern_createMutex(KIMAGER_MUTEX_RESERVE, &vMutex_Reserve[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "imager: create mutx"); exit(EXIT_OS_PANIC); }

		status = stub_imager_init();
	}
	RETURN_INT_RESTORE(status);
}

#endif
