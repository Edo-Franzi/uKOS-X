/*
; sloader.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Motorola S1-9, S2-8, S3-7 loader.
;			This tool allows to download a S format binary to the memory
;			and to execute it.
;			Here are the S format definitions:
;
;			- Everything is represented in ASCII.
;
;			- Block format:
;				Block type:				2 chars.
;				Length of the block:	an hex. number of 2 chars.
;				Address:				an hex. number of 4, 6 or 8 chars.
;				Data:					an hex. 2n chars.
;				Checksum:				an hex. number of 2 chars.
;
;			- Block type:
;				"S1" data block for addresses coded over 16-bits
;				"S2" data block for addresses coded over 24-bits
;				"S3" data block for addresses coded over 32-bits
;				"S7" end block for addresses coded over 32-bits
;				"S8" end block for addresses coded over 24-bits
;				"S9" end block for addresses coded over 16-bits
;				!!! S0 & S5 are not supported but tolerated.
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
#include	"linker.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"sloader      Motorola S1-9, S2-8, S3-7 loader.         (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Motorola S1-9, S2-8, S3-7 loader\n"
									"================================\n\n"

									"This tool downloads an executable code.\n"
									"The implementation of this loader does not support\n"
									"(but it tolerates) the S0 and S5 labels.\n\n"

									"Input format:  sloader [-run | -norun]\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Sloader,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_S_LOADER,								// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

#define	KNB_CHAR_BLINK	20u

enum {
		KERR_S_LOADER_NOT = 0u,
		KERR_S_LOADER_CHK,
		KERR_S_LOADER_BFU,
		KERR_S_LOADER_NOI,
		KERR_S_LOADER_FRA,
		KERR_S_LOADER_PAR,
		KERR_S_LOADER_OUM
};

enum {
		KRUN = 0u,
		KRUN_NO
};

// Prototypes

static	int32_t		local_getCounter(uint8_t *counter, uint8_t *checksum);
static	int32_t		local_getAddress(uint8_t **address, uint8_t *counter, uint8_t *checksum, uint8_t sType);
static	int32_t		local_getData(const uint8_t *counter, uint8_t *checksum, uint8_t *address, uint32_t *size);
static	int32_t		local_getHexValue(uint8_t *value);
static	int32_t		local_getByte(uint8_t *byte);
static	bool		local_checkSignature(void);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	char_t			*dummy;
	uint8_t			*address = nullptr, byte = 0u, checksum, counter;
	int32_t			error = KERR_S_LOADER_NOT, (*code)(uint32_t argc, const char_t *argv[]);
	bool			terminate = false, equals;
	uint8_t			run = KRUN;
	uint32_t		size = 0u;
	uKOS_header_t	ramHeader;

	UNUSED(dummy);

	(void)dprintf(KSYST, "S format Motorola loader mode; waiting for the code.\n");

// Verify if the user memory is available
// --------------------------------------

	if (system_reserve(KMODE_READ_WRITE, 0u) != KERR_SYSTEM_NOERR) {
		(void)dprintf(KSYST, "\nS: The user memory is busy.\n\n");
		return (EXIT_OS_FAILURE);
	}

	RESERVE_SERIAL(KSYST, KMODE_READ);

// Analyse the command line
// ------------------------
//
// Example:
//
// sloader
// sloader -run
// sloader -norun
// sloader -sdcard sectorNumber (it is also -norun)
// sloader p0 p1 p2 ... px

	switch (argc) {
		case 2u: {
			text_checkAsciiBuffer(argv[1], "-norun",  &equals); if (equals == true) { run = KRUN_NO; }
			text_checkAsciiBuffer(argv[1], "-run",    &equals); if (equals == true) { run = KRUN;	 }
			break;
		}

		default: {

// Make MISRA happy :-)

			break;
		}
	}

	while (terminate == false) {

// Waiting for a header S1, S2, S3 or S7, S8, S9

		do { local_getByte(&byte); } while (byte != 'S');
		local_getByte(&byte);

		switch (byte) {
			case '1':
			case '2':
			case '3': {
				error = local_getCounter(&counter, &checksum);                 if (error != KERR_S_LOADER_NOT) { terminate = true; break; }
				error = local_getAddress(&address, &counter, &checksum, byte); if (error != KERR_S_LOADER_NOT) { terminate = true; break; }
				error = local_getData(&counter, &checksum, address, &size);    if (error != KERR_S_LOADER_NOT) { terminate = true; break; }
				break;
			}
			case '7':
			case '8':
			case '9': {
				error = local_getCounter(&counter, &checksum);                 if (error != KERR_S_LOADER_NOT) { terminate = true; break; }
				error = local_getAddress(&address, &counter, &checksum, byte); if (error != KERR_S_LOADER_NOT) { terminate = true; break; }
				error = local_getData(&counter, &checksum, address, &size);	   if (error != KERR_S_LOADER_NOT) { terminate = true; break; }
				terminate = true;
				break;
			}
			default: {

// Make MISRA happy :-)

				break;
			}
		}
	}

// Terminated
// Waiting a bit to be sure that the flush
// operates when all the chars are received

	led_off(KLED_1);
	kern_suspendProcess(500u);
	serial_flush(KSYST);

	RELEASE_SERIAL(KSYST, KMODE_READ);

	switch (error) {
		case KERR_S_LOADER_NOT: {
			(void)dprintf(KSYST, "\nS: download terminated.\n\n");
			system_setDownloadCodeAddress(address);
			system_getDownloadCodeAddress((void **)&code);
			if (run == KRUN) {

// Invalidate the header to prevent another execution, like after the reset
// if the automatic execution from a debugger is installed.

				if (local_checkSignature() == true) {
					ramHeader.oMemLocation	  = KNO_MEM;
					ramHeader.oStart		  = nullptr;
					ramHeader.oLnApplication  = 0u;
					ramHeader.oModule		  = nullptr;
					memcpy((void *)linker_stUMemo, (const void *)&ramHeader, sizeof(ramHeader));

					return ((*code)(argc, argv));
				}

				(void)dprintf(KSYST, "\nS: failed to find the application signature!\n");
			}
			return (EXIT_OS_SUCCESS_CLI);

		}
		case KERR_S_LOADER_OUM: { (void)dprintf(KSYST, "\nS: Download address out of memory.\n\n"); return (EXIT_OS_FAILURE); }
		case KERR_S_LOADER_CHK: { (void)dprintf(KSYST, "\nS: wrong checksum.\n\n");					return (EXIT_OS_FAILURE); }
		case KERR_S_LOADER_BFU: { (void)dprintf(KSYST, "\nS: buffer full error.\n\n");				return (EXIT_OS_FAILURE); }
		case KERR_S_LOADER_NOI: { (void)dprintf(KSYST, "\nS: noise error.\n\n");					return (EXIT_OS_FAILURE); }
		case KERR_S_LOADER_FRA: { (void)dprintf(KSYST, "\nS: framing error.\n\n");					return (EXIT_OS_FAILURE); }
		case KERR_S_LOADER_PAR: { (void)dprintf(KSYST, "\nS: parity error.\n\n");					return (EXIT_OS_FAILURE); }
		default:				{																	return (EXIT_OS_FAILURE); }
	}
}

// Local routines
// ==============

/*
 * \brief local_getByte
 *
 * - Read a Byte
 * - Try to read a burst of KSZ_BUFFER Bytes
 *
 */
static	int32_t	local_getByte(uint8_t *byte) {
	#define	KSZ_BUFFER	32u
			uint32_t	core;
	static	uint8_t		vBuffer[KNB_CORES][KSZ_BUFFER], vCptBlinkLED[KNB_CORES] = MCSET(0u);
	static	uint32_t	vI[KNB_CORES] = MCSET(0u), vSize[KNB_CORES] = MCSET(0u);

	core = GET_RUNNING_CORE;
	*byte = 0u;

	if (vSize[core] == 0u) {
		vI[core] = 0u;
		do {
			kern_switchFast();
			vSize[core] = KSZ_BUFFER;

			switch (serial_read(KSYST, &vBuffer[core][0], &vSize[core])) {
				case KERR_SERIAL_RBFUL: { return (KERR_S_LOADER_BFU); }
				case KERR_SERIAL_ERNOI: { return (KERR_S_LOADER_NOI); }
				case KERR_SERIAL_ERFRA: { return (KERR_S_LOADER_FRA); }
				case KERR_SERIAL_ERPAR: { return (KERR_S_LOADER_PAR); }
				default: {

// Make MISRA happy :-)

					break;
				}
			}
		} while (vSize[core] == 0u);
	}

	if (vCptBlinkLED[core]++ >= KNB_CHAR_BLINK) {
		vCptBlinkLED[core] = 0u;
		led_toggle(KLED_1);
	}
	vSize[core]--;
	*byte = vBuffer[core][vI[core]];
	vI[core]++;
	return (KERR_S_LOADER_NOT);
}

/*
 * \brief local_getHexValue
 *
 * - Read a hexa value (2 chars)
 * - Ex. 31 is read as '3' (0x33) and '1' (0x31) 2-bytes
 *
 */
static	int32_t	local_getHexValue(uint8_t *value) {
					uint8_t		byte;
					int32_t		status;
	static	const	uint8_t		aTabAB[] = {
									0u,   1u,  2u,  3u,		// '0' '1' '2' '3'
									4u,   5u,  6u,  7u,		// '4' '5' '6' '7'
									8u,   9u,  0u,  0u,		// '8' '9' ':' ';'
									0u,   0u,  0u,  0u,		// '<' '=' '>' '?'
									0u,  10u, 11u, 12u,		// '@' 'A' 'B' 'C'
								   13u,  14u, 15u			// 'D' 'E' 'F'
								};

	*value = 0u;
	status = local_getByte(&byte);
	if (status != KERR_S_LOADER_NOT) {
		return (status);
	}

	if       ((byte >= '0') && (byte <= '9'))									   { *value = (uint8_t)(aTabAB[byte - (uint8_t)'0']<<4u);							 }
	else if (((byte >= 'A') && (byte <= 'F')) || ((byte >= 'a') && (byte <= 'f'))) { *value = (uint8_t)(aTabAB[(byte & (uint8_t)(~0x20u)) - (uint8_t)'0']<<4u);		 }
	else { ; }

	status = local_getByte(&byte);  if (status != KERR_S_LOADER_NOT) { return (status); }
	if       ((byte >= '0') && (byte <= '9'))									   { *value = *value + (uint8_t)(aTabAB[byte - (uint8_t)'0']);						 }
	else if (((byte >= 'A') && (byte <= 'F')) || ((byte >= 'a') && (byte <= 'f'))) { *value = *value + (uint8_t)(aTabAB[(byte & (uint8_t)(~0x20u)) - (uint8_t)'0']); }
	else { ; }

	return (KERR_S_LOADER_NOT);
}

/*
 * \brief local_getCounter
 *
 * - Read the counter field
 *
 */
static	int32_t	local_getCounter(uint8_t *counter, uint8_t *checksum) {
	int32_t		status;

	status = local_getHexValue(counter);
	if (status != KERR_S_LOADER_NOT) {
		return (status);
	}

	*checksum = *counter;
	return (KERR_S_LOADER_NOT);
}

/*
 * \brief local_getAddress
 *
 * - Read the address field
 *
 */
static	int32_t	local_getAddress(uint8_t **address, uint8_t *counter, uint8_t *checksum, uint8_t sType) {
	uint8_t		i, wide = 2, hexValue;
	int32_t		status;
	uintptr_t	stSegment, enSegment, offset = 0u;

	stSegment = (uintptr_t)linker_stUMemo;
	enSegment = (uintptr_t)linker_stUMemo + (uintptr_t)linker_lnUMemo;

	switch (sType) {
		case '1':
		case '9': { wide = 2u; break; }
		case '2':
		case '8': { wide = 3u; break; }
		case '3':
		case '7': { wide = 4u; break; }
		default: {

// Make MISRA happy :-)

			break;
		}
	}

// Build the address 16, 24 or 32-bit wide

	for (i = 0u; i < wide; i++) {
		status = local_getHexValue(&hexValue);
		if (status != KERR_S_LOADER_NOT) {
			return (status);
		}

		offset = (offset<<8u) + (uintptr_t)hexValue;
		*checksum = (uint8_t)(*checksum + hexValue);
		(*counter)--;
	}

// Verify the "offset" is inside the UMemo
// - stSegment <= offset <= enSegment -> address = offset
// - stSegment >  offset >  enSegment -> address = stSegment + offset

	if ((offset >= stSegment) && (offset <= enSegment)) { *address = (uint8_t *)offset;				  }
	else											    { *address = (uint8_t *)(stSegment + offset); }

	status = (((uintptr_t)*address < stSegment) || ((uintptr_t)*address > enSegment)) ? (KERR_S_LOADER_OUM) : (KERR_S_LOADER_NOT);
	return (status);
}

/*
 * \brief local_getData
 *
 * - Read the data field
 *
 */
static	int32_t	local_getData(const uint8_t *counter, uint8_t *checksum, uint8_t *address, uint32_t *size) {
	uint8_t		i, notChecksum, hexValue, *load;
	int32_t		status;

	load = address;
	for (i = 0u; i < (*counter - 1u); i++) {
		status = local_getHexValue(&hexValue);
		if (status != KERR_S_LOADER_NOT) {
			return (status);
		}

		*load = hexValue;
		load++;
		*size = *size + 1u;
		*checksum = (uint8_t)(*checksum + hexValue);
	}

	status = local_getHexValue(&hexValue);
	if (status != KERR_S_LOADER_NOT) {
		return (status);
	}

	notChecksum = (uint8_t)~(*checksum);
	if (hexValue != notChecksum) {
		return (KERR_S_LOADER_CHK);
	}

	return (KERR_S_LOADER_NOT);
}

/*
 * \brief local_checkSignature
 *
 * Search for the signature string, which should also be within the loaded application.
 * If the application has the same signature, launching it may be dangerous, as the
 * function entry-points will no longer be matching.
 *
 */
static	bool	local_checkSignature(void) {
			size_t		ln, i = 0u;
	const	uint8_t		*ptr = (uint8_t *)linker_stUMemo;
	const	char_t		*signature;

	system_getSystemSignature(&signature);

	for (ln = (size_t)linker_lnUMemo; ln > 0u; --ln ) {
		if (*ptr == signature[i]) {
			i++;
			if (*ptr == 0u) {
				return (true);
			}

		}
		else {
			i = 0u;
		}
		ptr++;
	}
	return (false);
}
