/*
; i2c.
; ====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		i2c manager.
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

#if (defined(CONFIG_MAN_I2C_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"i2c          i2c manager.                              (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "i2c manager\n"
									"===========\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	I2c,							// Module name (the first letter has to be upper case)
	KID_FAM_PERIPHERALS,			// Family (defined in the module.h)
	KNUM_I2C,						// Module identifier (defined in the module.h)
	NULL,							// Address of the initialisation code (early pre-init)
	NULL,							// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,							// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

/*
 * \brief Reserve the i2c manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = i2c_reserve(KI2C0, KMODE_READ_WRITE, 1234);
 *    ....
 *    i2c_xyz(KI2C0, );
 *    ....
 *    status = i2c_release(KI2C0, KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	manager			I2C manager
 * \param[in]	reserveMode		Any mode
 * \param[in]	timeout			Timeout (1-ms of resolution)
 * \param[in]	-				KWAIT_INFINITY, waiting forever
 * \param[in]	-				KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_I2C_XXXXX	Depends on the "xxxx" device manager
 *
 */
int32_t	i2c_reserve(i2cManager_t manager, reserveMode_t reserveMode, uint32_t timeout) {

	switch (manager) {

		#if (defined(CONFIG_MAN_I2C0_S))
		case KI2C0: { return (i2c0_reserve(reserveMode, timeout)); }
		#endif

		#if (defined(CONFIG_MAN_I2C1_S))
		case KI2C1: { return (i2c1_reserve(reserveMode, timeout)); }
		#endif

		#if (defined(CONFIG_MAN_I2C2_S))
		case KI2C2: { return (i2c2_reserve(reserveMode, timeout)); }
		#endif

		#if (defined(CONFIG_MAN_I2C3_S))
		case KI2C3: { return (i2c3_reserve(reserveMode, timeout)); }
		#endif

		default:	{ return (KERR_I2C_NODEV);					   }
	}
}

/*
 * \brief Release the i2c manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = i2c_release(KI2C0, KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	manager			I2C manager
 * \param[in]	reserveMode		Any mode
 * \return		KERR_I2C_XXXXX	Depends on the "xxxx" device manager
 *
 */
int32_t	i2c_release(i2cManager_t manager, reserveMode_t reserveMode) {

	switch (manager) {

		#if (defined(CONFIG_MAN_I2C0_S))
		case KI2C0: { return (i2c0_release(reserveMode)); }
		#endif

		#if (defined(CONFIG_MAN_I2C1_S))
		case KI2C1: { return (i2c1_release(reserveMode)); }
		#endif

		#if (defined(CONFIG_MAN_I2C2_S))
		case KI2C2: { return (i2c2_release(reserveMode)); }
		#endif

		#if (defined(CONFIG_MAN_I2C3_S))
		case KI2C3: { return (i2c3_release(reserveMode)); }
		#endif

		default:	{ return (KERR_I2C_NODEV);	  		  }
	}
}

/*
 * \brief Configure the i2c manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t       status;
 * const    i2cCnf_t     configure = {
 *                            .oTimeout  = 1000u;
 *                            .oSpeed    = KI2C_100KBPS;
 *                        };
 *
 *    status = i2c_configure(KI2C0, &configure);
 * \endcode
 *
 * \param[in]	manager			I2C manager
 * \param[in]	*configure		Ptr on the configuration buffer
 * \return		KERR_I2C_XXXXX	Depends on the "xxxx" device manager
 *
 */
int32_t	i2c_configure(i2cManager_t manager, const i2cCnf_t *configure) {

	switch (manager) {

		#if (defined(CONFIG_MAN_I2C0_S))
		case KI2C0: { return (i2c0_configure(configure)); }
		#endif

		#if (defined(CONFIG_MAN_I2C1_S))
		case KI2C1: { return (i2c1_configure(configure)); }
		#endif

		#if (defined(CONFIG_MAN_I2C2_S))
		case KI2C2: { return (i2c2_configure(configure)); }
		#endif

		#if (defined(CONFIG_MAN_I2C3_S))
		case KI2C3: { return (i2c3_configure(configure)); }
		#endif

		default:	{ return (KERR_I2C_NODEV);			  }
	}
}

/*
 * \brief Write a buffer to the i2c manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 * const    uint8_t    buffer[7] = { 1, 2, 3, 4, 5, 6, 7 };
 *
 *    status = i2c_write(KI2C0, 0x34, buffer, sizeof(buffer));
 * \endcode
 *
 * \param[in]	manager			I2C manager
 * \param[in]	address			i2c device address
 * \param[in]	*buffer			Ptr on the buffer
 * \param[in]	size			Size of the buffer
 * \return		KERR_I2C_XXXXX	Depends on the "xxxx" device manager
 *
 */
int32_t	i2c_write(i2cManager_t manager, uint8_t address, const uint8_t *buffer, uint16_t size) {

	switch (manager) {

		#if (defined(CONFIG_MAN_I2C0_S))
		case KI2C0: { return (i2c0_write(address, buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_I2C1_S))
		case KI2C1: { return (i2c1_write(address, buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_I2C2_S))
		case KI2C2: { return (i2c2_write(address, buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_I2C3_S))
		case KI2C3: { return (i2c3_write(address, buffer, size)); }
		#endif

		default:	{ return (KERR_I2C_NODEV);					  }
	}
}

/*
 * \brief Read a buffer from the i2c manager
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
 *    status = i2c_read(KI2C0, 0x34, buffer, 10);
 *
 * // Example 2: Write the register 56 and then read 2 bytes
 *
 *    buffer[0] = 56;
 *    status = i2c_read(KI2C0, 0x34, buffer, 2);
 * \endcode
 *
 * \param[in]	manager			I2C manager
 * \param[in]	address			i2c device address
 * \param[out]	*buffer			Ptr on the buffer
 * \param[in]	size			Size of the buffer
 * \return		KERR_I2C_XXXXX	Depends on the "xxxx" device manager
 *
 */
int32_t	i2c_read(i2cManager_t manager, uint8_t address, uint8_t *buffer, uint16_t size) {

	switch (manager) {

		#if (defined(CONFIG_MAN_I2C0_S))
		case KI2C0: { return (i2c0_read(address, buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_I2C1_S))
		case KI2C1: { return (i2c1_read(address, buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_I2C2_S))
		case KI2C2: { return (i2c2_read(address, buffer, size)); }
		#endif

		#if (defined(CONFIG_MAN_I2C3_S))
		case KI2C3: { return (i2c3_read(address, buffer, size)); }
		#endif

		default:	{ return (KERR_I2C_NODEV);					 }
	}
}

#endif
