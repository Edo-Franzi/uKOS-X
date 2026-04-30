/*
; esp32.
; ======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		This tool allows to control the ESP32 Alastor chip.
;			!!! This tool is Alastor specific.
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

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"esp32        Control of the ESP32 processor.           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Initial control of the ESP32 device\n"
									"===================================\n\n"

									"This tool allows to control the Alastor ESP32\n"
									"To quit the connected mode, type ++++\n\n"

									"Input format:  esp32 {-disable | -reset | -boot | -srts | -rrts | -connect baudrate}\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Esp32,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_ESP32,									// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

#define	KSZ_BUFFER		128u

// Prototypes

static	bool	local_getByte(serialManager_t serialManager, uint8_t *buffer, uint32_t *nbBytes);
static	void	local_putByte(serialManager_t serialManager, const uint8_t *buffer, const uint32_t *nbBytes);
static	bool	local_checkExit(const char_t *buffer);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	char_t		*dummy;
	uint8_t		data[KSZ_BUFFER], bdValue;
	int32_t		binary;
	uint32_t	nbBytes;
	int32_t		status;
	bool		equals, terminate = false;
	enum		{ KERR_NOT, KERR_INA } error = KERR_NOT;
	urtxCnf_t	configureURTx = {
					.oNBBits   = KSERIAL_NB_BITS_8,
					.oStopBits = KSERIAL_STOPBITS_1,
					.oParity   = KSERIAL_PARITY_NONE,
					.oBaudRate = KSERIAL_BAUDRATE_DEFAULT,
					.oKernSync = ((uint32_t)1u<<(uint32_t)BSERIAL_SEMAPHORE_RX)
				};

	(void)dprintf(KSYST, "Control of the ESP32 chip.\n");

// Analyse the command line
// ------------------------
//
// Examples:
//
//	esp32 -disable	Disable the ESP32 chip
//	esp32 -reset	Initialise the ESP32 chip
//	esp32 -boot		Enable the boot mode
//	esp32 -srts		Set the RTS
//	esp32 -rrts		Reset the RTS
//	esp32 -connect	Connect the KURT2 to the ESP32 uart

	PRIVILEGE_ELEVATE;
	switch (argc) {
		case 1u: {
			error = KERR_INA;
			break;
		}
		case 2u: {
			error = KERR_NOT;

// Disable the ESP32

			text_checkAsciiBuffer(argv[1], "-disable", &equals);
			if (equals == true) {
				GPIOE->ODR &= (uint32_t)~(1u<<BESP32_ENABLE);
				break;
			}

// Reset of the ESP32
// BE ---\____/---

			text_checkAsciiBuffer(argv[1], "-reset", &equals);
			if (equals == true) {
				GPIOD->ODR |=			 (1u<<BESP32_NDOWNLOAD);
				GPIOE->ODR &= (uint32_t)~(1u<<BESP32_ENABLE);	 kern_suspendProcess(10u);
				GPIOE->ODR |=			 (1u<<BESP32_ENABLE);
				break;
			}

// Set the boot mode
// BOOT ---\____________/---
// BE   -------\____/-------

			text_checkAsciiBuffer(argv[1], "-boot", &equals);
			if (equals == true) {
				GPIOD->ODR &= (uint32_t)~(1u<<BESP32_NDOWNLOAD); kern_suspendProcess(10u);
				GPIOE->ODR &= (uint32_t)~(1u<<BESP32_ENABLE);	 kern_suspendProcess(10u);
				GPIOE->ODR |=			 (1u<<BESP32_ENABLE);	 kern_suspendProcess(10u);
				GPIOD->ODR |=			 (1u<<BESP32_NDOWNLOAD);

				(void)dprintf(KSYST, "ESP32 bootloader is active!\n");
				break;
			}

// Set RTS
// RTS _______/---

			text_checkAsciiBuffer(argv[1], "-srts", &equals);
			if (equals == true) {
				GPIOG->ODR |= (1u<<BESP32_CTS);
				break;
			}

// Reset RTS
// RTS ---\_____

			text_checkAsciiBuffer(argv[1], "-rrts", &equals);
			if (equals == true) {
				GPIOG->ODR &= (uint32_t)~(1u<<BESP32_CTS);
				break;
			}
			error = KERR_INA;
			break;
		}
		case 3u: {

// Connect the KURT0 to the KURT2
// Terminate when KURT0 receives ++++

			text_checkAsciiBuffer(argv[1], "-connect", &equals);
			if (equals == true) {
				binary = (int32_t)strtoul(argv[2], &dummy, 10u);

				switch (binary) {
					case 2400u:		{ bdValue = KSERIAL_BAUDRATE_2400;    break; }
					case 4800u:		{ bdValue = KSERIAL_BAUDRATE_4800;    break; }
					case 9600u:		{ bdValue = KSERIAL_BAUDRATE_9600;    break; }
					case 19200u:	{ bdValue = KSERIAL_BAUDRATE_19200;   break; }
					case 38400u:	{ bdValue = KSERIAL_BAUDRATE_38400;   break; }
					case 57600u:	{ bdValue = KSERIAL_BAUDRATE_57600;   break; }
					case 115200u:	{ bdValue = KSERIAL_BAUDRATE_115200;  break; }
					case 230400u:	{ bdValue = KSERIAL_BAUDRATE_230400;  break; }
					case 460800u:	{ bdValue = KSERIAL_BAUDRATE_460800;  break; }
					case 500000u:	{ bdValue = KSERIAL_BAUDRATE_500000;  break; }
					case 921600u:	{ bdValue = KSERIAL_BAUDRATE_921600;  break; }
					case 1000000u:	{ bdValue = KSERIAL_BAUDRATE_1000000; break; }
					case 1500000u:	{ bdValue = KSERIAL_BAUDRATE_1500000; break; }
					case 1843200u:	{ bdValue = KSERIAL_BAUDRATE_1843200; break; }
					case 2000000u:	{ bdValue = KSERIAL_BAUDRATE_2000000; break; }
					case 2500000u:	{ bdValue = KSERIAL_BAUDRATE_2500000; break; }
					case 3000000u:	{ bdValue = KSERIAL_BAUDRATE_3000000; break; }
					default:		{ bdValue = KSERIAL_BAUDRATE_460800;  break; }
				}

				RESERVE_SERIAL(KURT2, KMODE_READ_WRITE);
				configureURTx.oBaudRate = bdValue;
				serial_configure(KURT2, &configureURTx);

				while (terminate == false) {

// Read a buffer on the KURT0 and write it on the KURT2
// Buffer per buffer operation

					nbBytes = KSZ_BUFFER;
					if (local_getByte(KURT0, &data[0], &nbBytes) == true) {
						if (nbBytes >= 4u) {
							if (local_checkExit((const char_t *)&data[0]) == true) {
								terminate = true;
							}
						}
						local_putByte(KURT2, &data[0], &nbBytes);
					}

// Read a buffer on the KURT2 and write it on the KURT0
// Buffer per buffer operation

					nbBytes = KSZ_BUFFER;
					if (local_getByte(KURT2, &data[0], &nbBytes) == true) {
						local_putByte(KURT0, &data[0], &nbBytes);
					}

// A pack every 1-ms

					kern_suspendProcess(1u);
				}
				RELEASE_SERIAL(KURT2, KMODE_READ_WRITE);

				(void)dprintf(KSYST, "End connection.\n\n");
				break;
			}
			error = KERR_INA;
			break;
		}
		default: {
			error = KERR_INA;
			break;
		}
	}
	PRIVILEGE_RESTORE;

	switch (error) {
		case KERR_NOT: {												   status = EXIT_OS_SUCCESS_CLI; break; }
		case KERR_INA: { (void)dprintf(KSYST, "Incorrect arguments.\n\n"); status = EXIT_OS_FAILURE;     break; }
		default:	   {												   status = EXIT_OS_FAILURE;     break; }
	}
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_getByte
 *
 * - Read a Byte
 *
 */
static	bool	local_getByte(serialManager_t serialManager, uint8_t *buffer, uint32_t *nbBytes) {
	bool	status;

	status = (serial_read(serialManager, buffer, nbBytes) == KERR_SERIAL_NOERR) ? (true) : (false);
	led_toggle(KLED_0);
	return (status);
}

/*
 * \brief local_putByte
 *
 * - Write a Byte
 *
 */
static	void	local_putByte(serialManager_t serialManager, const uint8_t *buffer, const uint32_t *nbBytes) {
	int32_t		status;

	do {
		kern_switchFast();

		status = serial_write(serialManager, buffer, *nbBytes);
	} while (status != KERR_SERIAL_NOERR);
}

/*
 * \brief local_checkExit
 *
 * - Test of the exit condition ("++++")
 *
 */
static	bool	local_checkExit(const char_t *buffer) {
	const	char_t	exitPatter[] = "++++";

	if (exitPatter[0] != buffer[0]) { return (false); }
	if (exitPatter[1] != buffer[1]) { return (false); }
	if (exitPatter[2] != buffer[2]) { return (false); }
	if (exitPatter[3] != buffer[3]) { return (false); }
	return (true);
}
