/*
; stub_battery_bq27510g3.
; =======================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the connection of the "bat0" manager to the battery,
;			bq27510g3 device.
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
#include	"BQ27510G3/BQ27510G3.h"

// Connect the physical device to the logical manager
// --------------------------------------------------

#define	model_bq27510g3_init	stub_battery_init
#define	model_bq27510g3_read	stub_battery_read

enum {
		KBAT_VOLTAGE = 0u,
		KBAT_CURRENT,
		KBAT_TEMPERATURE,
		KBAT_CHARGED_CAPACITY,
		KBAT_REMAINING_CAPACITY,
		KBAT_TIME_TO_EMPTY,
		KBAT_CYCLE_COUNT
};

// Prototypes

static	bool	local_readRegister(uint16_t command, uint16_t *value);
static	bool	local_readSubRegister(uint16_t command, uint16_t subCommand, uint16_t *value);

// Model callbacks
// ---------------

/*
 * \brief cb_configure
 *
 * - Configure the battery manager
 *
 */
static	void	cb_configure(void) {
					uint16_t	value;
	static	const	i2cCnf_t	configureI2C0 = {
									.oTimeout  = 1000u,
									.oSpeed    = KI2C_100KBPS,
								};

	RESERVE(I2C0, KMODE_READ_WRITE);
	i2c_configure(KI2C0, &configureI2C0);
	RELEASE(I2C0, KMODE_READ_WRITE);

	local_readSubRegister(BQ27510G3_CNTRL, BQ27510G3_INSERT, &value);
	kern_suspendProcess(1u);
}

/*
 * \brief cb_getValue
 *
 * - Read the battery information
 *
 */
static	bool	cb_getValue(uint8_t mode, uint16_t *value) {

	switch (mode) {
		case KBAT_VOLTAGE:			  { return (local_readRegister(BQ27510G3_VOLTAGE, value));				}
		case KBAT_CURRENT:			  { return (local_readRegister(BQ27510G3_AVERAGE_CURRENT, value));		}
		case KBAT_TEMPERATURE:		  { return (local_readRegister(BQ27510G3_INTERNAL_TEMPERATURE, value));	}
		case KBAT_CHARGED_CAPACITY:	  { return (local_readRegister(BQ27510G3_FULL_CHARGE_CAPACITY, value));	}
		case KBAT_REMAINING_CAPACITY: { return (local_readRegister(BQ27510G3_REMAINING_CAPACITY, value));	}
		case KBAT_TIME_TO_EMPTY:	  { return (local_readRegister(BQ27510G3_TIME_TO_EMPTY, value));		}
		case KBAT_CYCLE_COUNT:		  { return (local_readRegister(BQ27510G3_CYCLE_COUNT, value));			}
		default: {
			*value = 0u;
			return (true);
		}
	}
}

// Local routines
// ==============

/*
 * \brief local_readRegister
 *
 * - Read a BQ27510G3 register
 *
 */
static	bool	local_readRegister(uint16_t command, uint16_t *value) {
	uint8_t		buffer[2];
	bool		status;

	buffer[0] = (uint8_t)(command>>8);

	RESERVE(I2C0, KMODE_READ_WRITE);
	status = (i2c_read(KI2C0, KI2C_ADD_BQ27510G3, &buffer[0], 2u) == KERR_I2C_NOERR) ? (false) : (true);
	kern_suspendProcess(10u);
	RELEASE(I2C0, KMODE_READ_WRITE);

	*value = (uint16_t)((buffer[1]<<8) | buffer[0]);
	return (status);
}

/*
 * \brief cb_getSubCommand
 *
 * - Read a BQ27510G3 sub command
 *
 */
static	bool	local_readSubRegister(uint16_t command, uint16_t subCommand, uint16_t *value) {
	uint8_t		buffer[3];
	bool		status;

	buffer[0] = (uint8_t)(command>>8u);
	buffer[1] = (uint8_t)(subCommand);
	buffer[2] = (uint8_t)(subCommand>>8u);

	RESERVE(I2C0, KMODE_READ_WRITE);
	status = (i2c_write(KI2C0, KI2C_ADD_BQ27510G3, &buffer[0], 3u) == KERR_I2C_NOERR) ? (false) : (true);
	kern_suspendProcess(10u);

	buffer[0] = (uint8_t)(command>>8u);
	status |= (i2c_read(KI2C0, KI2C_ADD_BQ27510G3, &buffer[0], 2u) == KERR_I2C_NOERR) ? (false) : (true);
	kern_suspendProcess(10u);
	RELEASE(I2C0, KMODE_READ_WRITE);

	*value =(uint16_t)((buffer[1]<<8u) | buffer[0]);
	return (status);
}

#include	"model_bq27510g3.c_inc"
