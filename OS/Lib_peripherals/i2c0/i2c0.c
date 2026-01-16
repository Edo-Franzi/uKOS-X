/*
; i2c0.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		i2c0 manager.
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

#if (defined(CONFIG_MAN_I2C0_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"i2c0         i2c0 manager.                             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "i2c0 manager\n"
									"============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	I2c0,							// Module name (the first letter has to be upper case)
	KID_FAM_PERIPHERALS,			// Family (defined in the module.h)
	KNUM_I2C0,						// Module identifier (defined in the module.h)
	NULL,							// Address of the initialisation code (early pre-init)
	NULL,							// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,							// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

static	mutx_t		*vMutex_Reserve[KNB_CORES];

// Prototypes

static	int32_t		local_init(void);
extern	void		stub_i2c0_init(void);
extern	int32_t		stub_i2c0_configure(const i2cCnf_t *configure);
extern	int32_t		stub_i2c0_write(uint8_t address, const uint8_t *buffer, uint16_t size);
extern	int32_t		stub_i2c0_read(uint8_t address, uint8_t *buffer, uint16_t size);
extern	int32_t		stub_i2c0_flush(void);

/*
 * \brief Reserve the i2c0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = i2c0_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    i2c0_xyz();
 *    ....
 *    status = i2c0_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \param[in]	timeout			Timeout (1-ms of resolution)
 * \param[in]	-				KWAIT_INFINITY, waiting forever
 * \param[in]	-				KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_I2C_NOERR	The manager is reserved
 * \return		KERR_I2C_GEERR	General error
 * \return		KERR_I2C_CHBSY	The manager is busy
 *
 */
int32_t	i2c0_reserve(reserveMode_t reserveMode, uint32_t timeout) {
	uint32_t	core;
	int32_t		status;

	UNUSED(reserveMode);

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_I2C_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = kern_lockMutex(vMutex_Reserve[core], timeout);
	if (status != KERR_KERN_NOERR) {
		PRIVILEGE_RESTORE;
		return (KERR_I2C_CHBSY);
	}

	PRIVILEGE_RESTORE;
	return (KERR_I2C_NOERR);
}

/*
 * \brief Release the i2c0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = i2c0_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode		Any mode
 * \return		KERR_I2C_NOERR	OK
 * \return		KERR_I2C_GEERR	General error
 * \return		KERR_I2C_CAREL	Cannot release the manager
 *
 */
int32_t	i2c0_release(reserveMode_t reserveMode) {
	uint32_t	core;
	int32_t		status;

	UNUSED(reserveMode);

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_I2C_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = kern_unlockMutex(vMutex_Reserve[core]);
	if (status != KERR_KERN_NOERR) {
		PRIVILEGE_RESTORE;
		return (KERR_I2C_CAREL);
	}

	PRIVILEGE_RESTORE;
	return (KERR_I2C_NOERR);
}

/*
 * \brief Configure the i2c0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t       status;
 * const    i2cCnf_t    configure = {
 *                            .oTimeout  = 1000u;
 *                            .oSpeed    = KI2C_100KBPS;
 *                        };
 *
 *    status = i2c0_configure(&configure);
 * \endcode
 *
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_I2C_NOERR	OK
 * \return		KERR_I2C_GEERR	General error
 *
 */
int32_t	i2c0_configure(const i2cCnf_t *configure) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_I2C_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_i2c0_configure(configure);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Write a buffer to the i2c0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 * const    uint8_t    buffer[7] = { 1, 2, 3, 4, 5, 6, 7 };
 *
 *    status = i2c0_write(0x34, buffer, sizeof(buffer));
 * \endcode
 *
 * \param[in]	address			i2c device address
 * \param[in]	*buffer			Ptr on the buffer
 * \param[in]	size			Size of the buffer
 * \return		KERR_I2C_NOERR	OK
 * \return		KERR_I2C_GEERR	General error
 * \return		KERR_I2C_TIMEO	Timeout error
 *
 */
int32_t	i2c0_write(uint8_t address, const uint8_t *buffer, uint16_t size) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_I2C_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_i2c0_write(address, buffer, size);
	PRIVILEGE_RESTORE;
	return (status);
}

/*
 * \brief Read a buffer from the i2c0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * uint8_t    buffer[10];
 *
 * // Example 1: Read 10 bytes
 *
 *    buffer[0] = 0xFF;
 *    status = i2c0_read(0x34, buffer, 10);
 *
 * // Example 2: Write the register 56 and then read 2 bytes
 *
 *    buffer[0] = 56;
 *    status = i2c0_read(0x34, buffer, 2);
 * \endcode
 *
 * \param[in]	address			i2c device address
 * \param[out]	*buffer			Ptr on the buffer
 * \param[in]	size			Size of the buffer
 * \return		KERR_I2C_NOERR	OK
 * \return		KERR_I2C_GEERR	General error
 * \return		KERR_I2C_TIMEO	Timeout error
 *
 */
int32_t	i2c0_read(uint8_t address, uint8_t *buffer, uint16_t size) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_I2C_NOERR) { PRIVILEGE_RESTORE; return (status); }

	status = stub_i2c0_read(address, buffer, size);
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
			uint32_t	core;
	static	bool		vInit[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vInit[core] == false) {
		vInit[core] = true;

		if (kern_createMutex(KI2C0_MUTEX_RESERVE, &vMutex_Reserve[core]) != KERR_KERN_NOERR) { LOG(KFATAL_MANAGER, "i2c0: create mutx"); exit(EXIT_OS_PANIC); }

		stub_i2c0_init();
	}
	RETURN_INT_RESTORE(KERR_I2C_NOERR);
}

#endif
