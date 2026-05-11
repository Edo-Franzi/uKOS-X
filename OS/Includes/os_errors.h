/*
; os_errors.
; ==========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		System errors.
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

#include	"modules.h"

// Lib_kernels managers
// ====================

// kern manager errors
// -------------------

// Coding
//                  0x80 ff mm ee
//					0x80	Negative, error flag
//					ff		Family Lib
//					mm		Manager
//					ee		error code
//
//							Negative				Family Lib Id	       			   Manager Id
#define	KKERN_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_KERNELS<<16u) | ((uint32_t)KNUM_KERN<<8u))

enum : int32_t {
	KERR_KERN_NOERR = 0,										// No error
	KERR_KERN_SYCNA = (int32_t)(KKERN_ERR + 1u),				// System call not available
	KERR_KERN_GEERR,											// General error
	KERR_KERN_TIMEO,											// Timeout error
	KERR_KERN_FRISR,											// Execution from ISR
	KERR_KERN_BADCO,											// Bad core

	KERR_KERN_LIFUL,											// No more process
	KERR_KERN_NOPRO,											// The process does not exist
	KERR_KERN_IDPRO,											// The process identifier is already used
	KERR_KERN_REFRS,											// The first cannot be removed
	KERR_KERN_RESDE,											// The system daemons cannot be removed
	KERR_KERN_NOSTK,											// No memory for the stack
	KERR_KERN_PRIVI,											// Privilege violation

	KERR_KERN_SEFUL,											// No more semaphore
	KERR_KERN_NOSEM,											// The semaphore does not exist
	KERR_KERN_IDSEM,											// The semaphore identifier is already used
	KERR_KERN_SETME,											// The semaphore counts too many events
	KERR_KERN_SEKIL,											// The semaphore has been killed (with processes in its list)
	KERR_KERN_SENOW,											// The process is not the owner of the semaphore

	KERR_KERN_MUFUL,											// No more mutex
	KERR_KERN_NOMUT,											// The mutex does not exist
	KERR_KERN_IDMUT,											// The mutex identifier is already used
	KERR_KERN_MUTME,											// The mutex counts too many events
	KERR_KERN_MUKIL,											// The mutex has been killed (with processes in its list)
	KERR_KERN_MUNOW,											// The process is not the owner of the mutex

	KERR_KERN_MBFUL,											// No more mailbox
	KERR_KERN_NOMBO,											// The mailbox does not exist
	KERR_KERN_IDMBO,											// The mailbox identifier is already used
	KERR_KERN_MBNCF,											// The mailbox is not configured
	KERR_KERN_MBCNF,											// The mailbox configuration is not possible
	KERR_KERN_MBKIL,											// The mailbox has been killed (with processes in its list)
	KERR_KERN_MBSIZ,											// The mailbox write in copy mode is larger than the configured data size

	KERR_KERN_SIFUL,											// No more signal group
	KERR_KERN_NOSIG,											// No more bitSignal
	KERR_KERN_NOGRO,											// The signal group does not exist
	KERR_KERN_IDSIO,											// The signal group identifier is already used
	KERR_KERN_SIKIL,											// The signal group has been killed (with processes in its list)

	KERR_KERN_FLFUL,											// No more flag group
	KERR_KERN_NOFLG,											// The flag group does not exist
	KERR_KERN_IDFLO,											// The flag group identifier is already used
	KERR_KERN_FLKIL,											// The signal group has been killed (with processes in its list)

	KERR_KERN_TIFMT,											// The absolute time has a wrong format

	KERR_KERN_DBGER,											// The process is not (or already) in the debug list
	KERR_KERN_DBNOS,											// The process is attached to a sensitive list and cannot be stopped

	KERR_KERN_STFUL,											// No more software timer
	KERR_KERN_NOSTI,											// The software timer does not exist
	KERR_KERN_IDSTI,											// The software timer identifier is already used
	KERR_KERN_CFSTI,											// The software timer cannot be configured

	KERR_KERN_POFUL,											// No more memory pool
	KERR_KERN_BKFUL,											// No more block
	KERR_KERN_NOPOI,											// The memory pool does not exist
	KERR_KERN_IDPOI,											// The memory pool identifier is already used
	KERR_KERN_PONCF,											// The memory pool is not configured
	KERR_KERN_POCNF,											// The memory pool configuration is not possible
	KERR_KERN_NOBKI,											// The block does not exist

	KERR_KERN_PRFUL,											// No more precise signal
	KERR_KERN_NOPRC,											// The precise signal does not exist
	KERR_KERN_IDPRC												// The precise signal identifier is already used
};

// Lib_serials managers
// ====================

// serial manager errors
// ---------------------

//							Negative				 Family Lib Id		   			   	Manager Id
#define	KSERIAL_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_SERIALS<<16u) | ((uint32_t)KNUM_SERIAL<<8u))

enum : int32_t {
	KERR_SERIAL_NOERR = 0,										// No error
	KERR_SERIAL_SYCNA = (int32_t)(KSERIAL_ERR + 1u),			// System call not available
	KERR_SERIAL_GEERR,											// General error
	KERR_SERIAL_NODEV,											// The device does not exist
	KERR_SERIAL_NOCHA,											// The channel does not exist
	KERR_SERIAL_CHBSY,											// The manager is busy

	KERR_SERIAL_LNBU0,											// The buffer length is = 0
	KERR_SERIAL_LNBUB,											// The buffer length is too big
	KERR_SERIAL_SBUEM,											// The sender buffer is empty
	KERR_SERIAL_SBUNE,											// The sender buffer is not empty
	KERR_SERIAL_SBFUL,											// The sender buffer is full
	KERR_SERIAL_SEPRO,											// the sender is busy

	KERR_SERIAL_RBUEM,											// The receiver buffer is empty
	KERR_SERIAL_RBFUL,											// The receiver buffer is full
	KERR_SERIAL_EROVR,											// Overrun error
	KERR_SERIAL_ERNOI,											// Noise error
	KERR_SERIAL_ERFRA,											// Framing error
	KERR_SERIAL_ERPAR,											// Parity error

	KERR_SERIAL_NOCNF,											// The configuration does not exist
	KERR_SERIAL_NOHAR,											// Hardware problem
	KERR_SERIAL_TIMEO,											// Timeout error
	KERR_SERIAL_SENOE,											// The semaphore does not exist
	KERR_SERIAL_CAREL,											// Cannot release the manager
};

// Lib_generics managers
// =====================

// asmp manager errors
// -------------------

//							Negative				 Family Lib Id						 Manager Id
#define	KASMP_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_GENERICS<<16u) | ((uint32_t)KNUM_ASMP<<8u))

enum : int32_t {
	KERR_ASMP_NOERR = 0,										// No error
	KERR_ASMP_SYCNA = (int32_t)(KASMP_ERR + 1u),				// System call not available
	KERR_ASMP_GEERR,											// General error
	KERR_ASMP_SBFUL,											// The sender buffer is full
	KERR_ASMP_RBUEM,											// The receiver buffer is empty
	KERR_ASMP_CORNA,											// The core number is not not allowed
	KERR_ASMP_NORDY,											// The ASMP is not ready
	KERR_ASMP_LNBUB												// The buffer length is too big
};

// memo manager errors
// -------------------

//							Negative				 Family Lib Id						 Manager Id
#define	KMEMO_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_GENERICS<<16u) | ((uint32_t)KNUM_MEMO<<8u))

enum : int32_t {
	KERR_MEMO_NOERR = 0,										// No error
	KERR_MEMO_SYCNA = (int32_t)(KMEMO_ERR + 1u),				// System call not available
	KERR_MEMO_GEERR,											// General error
	KERR_MEMO_NOBKI												// The block does not exist
};

// record manager errors
// ---------------------

//							Negative				 Family Lib Id						 Manager Id
#define	KRECORD_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_GENERICS<<16u) | ((uint32_t)KNUM_RECORD<<8u))

enum : int32_t {
	KERR_RECORD_NOERR = 0,										// No error
	KERR_RECORD_SYCNA = (int32_t)(KRECORD_ERR + 1u),			// System call not available
	KERR_RECORD_GEERR											// General error
};

// system manager errors
// ---------------------

//							Negative				 Family Lib Id						 Manager Id
#define	KSYSTEM_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_GENERICS<<16u) | ((uint32_t)KNUM_SYSTEM<<8u))

enum : int32_t {
	KERR_SYSTEM_NOERR = 0,										// No error
	KERR_SYSTEM_SYCNA = (int32_t)(KSYSTEM_ERR + 1u),			// System call not available
	KERR_SYSTEM_GEERR,											// General error
	KERR_SYSTEM_NOMOD,											// The module does not exist
	KERR_SYSTEM_NOFAM,											// The family does not exist
	KERR_SYSTEM_NOMEM,											// The memory unit does not exist
	KERR_SYSTEM_NOBLK,											// The memory block does not exist
	KERR_SYSTEM_SZBLK,											// The size of the block is too small
	KERR_SYSTEM_CHBSY,											// The manager is busy
	KERR_SYSTEM_CAREL											// Cannot release the manager
};

// machine manager errors
// ---------------------

//							Negative				 Family Lib Id						 Manager Id
#define	KMACHINE_ERR		((uint32_t)0x80000000u | ((uint32_t)KID_FAM_GENERICS<<16u) | ((uint32_t)KNUM_MACHINE<<8u))

enum : int32_t {
	KERR_MACHINE_NOERR = 0,										// No error
	KERR_MACHINE_SYCNA = (int32_t)(KMACHINE_ERR + 1u),			// System call not available
	KERR_MACHINE_GEERR											// General error
};

// text manager errors
// -------------------

//							Negative				 Family Lib Id						 Manager Id
#define	KTEXT_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_GENERICS<<16u) | ((uint32_t)KNUM_TEXT<<8u))

enum : int32_t {
	KERR_TEXT_NOERR = 0,										// No error
	KERR_TEXT_SYCNA = (int32_t)(KTEXT_ERR + 1u),				// System call not available
	KERR_TEXT_GEERR												// General error
};

// calendar manager errors
// -----------------------

//							Negative				 Family Lib Id						 Manager Id
#define	KCALENDAR_ERR		((uint32_t)0x80000000u | ((uint32_t)KID_FAM_GENERICS<<16u) | ((uint32_t)KNUM_CALENDAR<<8u))

enum : int32_t {
	KERR_CALENDAR_NOERR = 0,									// No error
	KERR_CALENDAR_SYCNA = (int32_t)(KCALENDAR_ERR + 1u),		// System call not available
	KERR_CALENDAR_GEERR											// General error
};

// newlib manager errors
// ---------------------

//							Negative				 Family Lib Id						 Manager Id
#define	KNEWLIB_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_GENERICS<<16u) | ((uint32_t)KNUM_NEWLIB<<8u))

enum : int32_t {
	KERR_NEWLIB_NOERR = 0										// No error
};

// Lib_neurals managers
// ====================

// mlpn manager errors
// -------------------

//							Negative				 Family Lib Id					    Manager Id
#define	KMLPN_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_NEURALS<<16u) | ((uint32_t)KNUM_MLPN<<8u))

enum : int32_t {
	KERR_MLPN_NOERR = 0,										// No error
	KERR_MLPN_SYCNA = (int32_t)(KMLPN_ERR + 1u),				// System call not available
	KERR_MLPN_GEERR,											// General error
	KERR_MLPN_CNERR,											// Configuration error
	KERR_MLPN_TIMEO,											// Timeout error
	KERR_MLPN_CHBSY,											// The manager is busy
	KERR_MLPN_NOMEM,											// Not enough memory
	KERR_MLPN_CAREL												// Cannot release the manager
};

// Lib_peripherals managers
// ========================

// adc manager errors
// ------------------

//							Negative				 Family Lib Id						    Manager Id
#define	KADC_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_PERIPHERALS<<16u) | ((uint32_t)KNUM_ADC<<8u))

enum : int32_t {
	KERR_ADC_NOERR = 0,											// No error
	KERR_ADC_SYCNA = (int32_t)(KADC_ERR + 1u),					// System call not available
	KERR_ADC_GEERR,												// General error
	KERR_ADC_CHBSY,												// The manager is busy
	KERR_ADC_NODEV,												// The device does not exist
	KERR_ADC_CAREL												// Cannot release the manager
};

// battery manager errors
// ----------------------

//							Negative				 Family Lib Id						    Manager Id
#define	KBATTERY_ERR		((uint32_t)0x80000000u | ((uint32_t)KID_FAM_PERIPHERALS<<16u) | ((uint32_t)KNUM_BATTERY<<8u))

enum : int32_t {
	KERR_BATTERY_NOERR = 0,										// No error
	KERR_BATTERY_SYCNA = (int32_t)(KBATTERY_ERR + 1u),			// System call not available
	KERR_BATTERY_GEERR,											// General error
	KERR_BATTERY_CHBSY,											// The manager is busy
	KERR_BATTERY_CAREL											// Cannot release the manager
};

// i2c manager errors
// ------------------

//							Negative				 Family Lib Id						    Manager Id
#define	KI2C_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_PERIPHERALS<<16u) | ((uint32_t)KNUM_I2C<<8u))

enum : int32_t {
	KERR_I2C_NOERR = 0,											// No error
	KERR_I2C_SYCNA = (int32_t)(KI2C_ERR + 1u),					// System call not available
	KERR_I2C_GEERR,												// General error
	KERR_I2C_NODEV,												// The device does not exist
	KERR_I2C_CHBSY,												// The manager is busy
	KERR_I2C_TIMEO,												// Timeout error
	KERR_I2C_SENOE,												// The semaphore does not exist
	KERR_I2C_CAREL												// Cannot release the manager
};

// imager manager errors
// ---------------------

//							Negative				 Family Lib Id						    Manager Id
#define	KIMAGER_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_PERIPHERALS<<16u) | ((uint32_t)KNUM_IMAGER<<8u))

enum : int32_t {
	KERR_IMAGER_NOERR = 0,										// No error
	KERR_IMAGER_SYCNA = (int32_t)(KIMAGER_ERR + 1u),			// System call not available
	KERR_IMAGER_GEERR,											// General error
	KERR_IMAGER_CNERR,											// Configuration error
	KERR_IMAGER_TIMEO,											// Timeout error
	KERR_IMAGER_CHBSY,											// The manager is busy
	KERR_IMAGER_PGNOE,											// The image page does not exist
	KERR_IMAGER_BDMOD,											// Bad mode for called function
	KERR_IMAGER_NOMEM,											// Not enough memory
	KERR_IMAGER_CAREL											// Cannot release the manager
};

// imu manager errors
// ------------------

//							Negative				 Family Lib Id						    Manager Id
#define	KIMU_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_PERIPHERALS<<16u) | ((uint32_t)KNUM_IMU<<8u))

enum : int32_t {
	KERR_IMU_NOERR = 0,											// No error
	KERR_IMU_SYCNA = (int32_t)(KIMU_ERR + 1u),					// System call not available
	KERR_IMU_GEERR,												// General error
	KERR_IMU_CHBSY,												// The manager is busy
	KERR_IMU_CAREL												// Cannot release the manager
};

// spi manager errors
// ------------------

//							Negative				 Family Lib Id						    Manager Id
#define	KSPI_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_PERIPHERALS<<16u) | ((uint32_t)KNUM_SPI<<8u))

enum : int32_t {
	KERR_SPI_NOERR = 0,											// No error
	KERR_SPI_SYCNA = (int32_t)(KSPI_ERR + 1u),					// System call not available
	KERR_SPI_GEERR,												// General error
	KERR_SPI_NODEV,												// The device does not exist
	KERR_SPI_CHBSY,												// The manager is busy
	KERR_SPI_TIMEO,												// Timeout error
	KERR_SPI_SENOE,												// The semaphore does not exist
	KERR_SPI_CAREL												// Cannot release the manager
};

// temperature manager errors
// --------------------------

//							Negative				 Family Lib Id						    Manager Id
#define	KTEMPERATURE_ERR	((uint32_t)0x80000000u | ((uint32_t)KID_FAM_PERIPHERALS<<16u) | ((uint32_t)KNUM_TEMPERATURE<<8u))

enum : int32_t {
	KERR_TEMPERATURE_NOERR = 0,									// No error
	KERR_TEMPERATURE_SYCNA = (int32_t)(KTEMPERATURE_ERR + 1u),	// System call not available
	KERR_TEMPERATURE_GEERR,										// General error
	KERR_TEMPERATURE_CHBSY,										// The manager is busy
	KERR_TEMPERATURE_CAREL										// Cannot release the manager
};

// wdog manager errors
// -------------------

//							Negative				 Family Lib Id						    Manager Id
#define	KWATCHDOG_ERR		((uint32_t)0x80000000u | ((uint32_t)KID_FAM_PERIPHERALS<<16u) | ((uint32_t)KNUM_WATCHDOG<<8u))

enum : int32_t {
	KERR_WATCHDOG_NOERR = 0										// No error
};

// led manager errors
// ------------------

//							Negative				 Family Lib Id						    Manager Id
#define	KLED_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_PERIPHERALS<<16u) | ((uint32_t)KNUM_LED<<8u))

enum : int32_t {
	KERR_LED_NOERR = 0,											// No error
	KERR_LED_SYCNA = (int32_t)(KLED_ERR + 1u),					// System call not available
	KERR_LED_GEERR,												// General error
	KERR_LED_NODEV												// The device does not exist
};

// switch manager errors
// ---------------------

//							Negative				 Family Lib Id						    Manager Id
#define	KSWITCH_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_PERIPHERALS<<16u) | ((uint32_t)KNUM_SWITCH<<8u))

enum : int32_t {
	KERR_SWITCH_NOERR = 0,										// No error
	KERR_SWITCH_SYCNA = (int32_t)(KSWITCH_ERR + 1u),			// System call not available
	KERR_SWITCH_GEERR											// General error
};

// Lib_cryptographics managers
// ===========================

// rand manager errors
// -------------------

//							Negative				 Family Lib Id							   Manager Id
#define	KRANDOM_ERR			((uint32_t)0x80000000u | ((uint32_t)KID_FAM_CRYPTOGRAPHICS<<16u) | ((uint32_t)KNUM_RANDOM<<8u))

enum : int32_t {
	KERR_RANDOM_NOERR = 0,										// No error
	KERR_RANDOM_SYCNA = (int32_t)(KRANDOM_ERR + 1u),			// System call not available
	KERR_RANDOM_GEERR,											// General error
};

// Lib_storages managers
// =====================

// storage manager errors
// ----------------------

//							Negative				 Family Lib Id					    Manager Id
#define	KSTORAGE_ERR		((uint32_t)0x80000000u | ((uint32_t)KID_FAM_STORAGE<<16u) | ((uint32_t)KNUM_STORAGE<<8u))

enum : int32_t {
	KERR_STORAGE_NOERR = 0,										// No error
	KERR_STORAGE_SYCNA = (int32_t)(KSTORAGE_ERR + 1u),			// System call not available
	KERR_STORAGE_GEERR,											// General error
	KERR_STORAGE_CHBSY,											// The manager is busy
	KERR_STORAGE_NODEV,											// The device does not exist
	KERR_STORAGE_CANRE,											// Device not recognised
	KERR_STORAGE_LNBU0,											// The number of sectors is = 0
	KERR_STORAGE_TRANT,											// Transfer not terminated
	KERR_STORAGE_CAREL,											// Cannot release the manager
	KERR_STORAGE_NOEMP											// the device is not empty
};

// Third parties libraries
// =======================

// micropython library errors
// --------------------------

//							Negative				 Family Lib Id							  Manager Id
#define	KMICROPYTHON_ERR	((uint32_t)0x80000000u | ((uint32_t)KID_FAM_THIRD_PARTIES<<16u) | ((uint32_t)KNUM_MICROPYTHON<<8u))

enum : int32_t {
	KERR_MICROPYTHON_NOERR = 0,									// No error
	KERR_MICROPYTHON_SYCNA = (int32_t)(KMICROPYTHON_ERR + 1u),	// System call not available
	KERR_MICROPYTHON_GEERR										// General error
};
