/*
; text.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:	Edo. Franzi		The 2025-01-01	Correct for matching some MISRA recommendations
;
; Project:	uKOS-X
; Goal:		text manager.
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

#if (defined(CONFIG_MAN_TEXT_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"text         text manager.                             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "text manager\n"
									"============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Text,							// Module name (the first letter has to be upper case)
	KID_FAM_GENERICS,				// Family (defined in the module.h)
	KNUM_TEXT,						// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

// Prototypes

static	void	local_waitOrder(serialManager_t serialManager, char_t *ascii, uint32_t size);
static	void	local_getChar(serialManager_t serialManager, char_t *c, sema_t *semaphore);

/*
 * \brief Get the arguments from a command line
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KNBARGS    16
 *
 *          char_t      *argv[KNBARGS];
 *          uint32_t    argc;
 *          int32_t     status;
 * const    char_t      commandLine[KLNINPBUF] = ”Line: 3224.5 test 123”;
 *
 *    status = text_readArgs(commandLine, KLNINPBUF, argv, KNBARGS, &argc);
 *
 *    (void)dprintf(KSYST, “%d\n”, argc);     // --> 4
 *    (void)dprintf(KSYST, “%d\n”, argv[0]);  // --> line
 *    (void)dprintf(KSYST, “%d\n”, argv[1]);  // --> 4.5
 *    (void)dprintf(KSYST, “%d\n”, argv[2]);  // --> test
 *    (void)dprintf(KSYST, “%d\n”, argv[3]);  // --> 123
 * \endcode
 *
 * - The char "_" is used for space!
 *   - Ex. buffer1 R________
 *         buffer2 RXYZCRLF\0
 *
 * - Leading blanks are skipped: argv[0] is the first word, and a line of
 *   blanks yields no argument (argc = 0)
 *
 * - A line with more arguments than argv can hold stores only the first
 *   nbArgs of them and returns KERR_TEXT_TMARG: the line is not the one the
 *   user typed, so a caller should refuse it rather than act on it
 *
 * \param[in]	*ascii			Ptr on the ASCII buffer
 * \param[in]	size			Size of the buffer
 * \param[out]	*argv			Ptr on the ASCII argument buffer
 * \param[in]	nbArgs			Capacity of argv (number of pointers)
 * \param[out]	*argc			Ptr on the number of ASCII arguments
 * \return		KERR_TEXT_NOERR	OK
 * \return		KERR_TEXT_TMARG	Too many arguments
 *
 */
int32_t	text_readArgs(char_t *ascii, uint32_t size, const char_t *argv[], uint32_t nbArgs, uint32_t *argc) {
	uint32_t	i, j = 0u;
	bool		terminate = false, start = false, quote = false;

// First char is \0

	if (ascii[0] == '\0') {
		*argc = 0u;
		return (KERR_TEXT_NOERR);
	}

// 1st pass; replace the ' ' with '\0'
// Ex. in:  abc def   werw0wer rtz rtzrz0
//     out: abc0def000werw000000000000000

	for (i = 0u; i < size; i++) {
		if (terminate == true) {
			ascii[i] = '\0';
		}
		else {
			if ( ascii[i] == '\0')   { terminate = true;   }
			if ( ascii[i] == '\r')   { ascii[i]  = '\0';   }
			if ( ascii[i] == '\n')   { ascii[i]  = '\0';   }
			if ( ascii[i] == '"' )   { quote	 = !quote; }

			if ((quote    == false) &&
				(ascii[i] == ' ' ))	 { ascii[i]  = '\0';   }
		}
	}

// 2nd pass; determine the argument pointers
// Ex. in:  abc0def000werw000000000000000
//     out: |   |     |
//          0   1     2 --> vArg
//
// Never more than nbArgs pointers: argv is the caller's array, and a line with
// more tokens than it holds used to write past its end.
// The walk starts as if after a separator, so argv[0] is the first non-blank
// character: leading blanks are skipped, and a line of blanks has no argument.
// argv[0] used to be the buffer itself, an empty string after a leading blank,
// so "   uKOS" at the console answered "Module not found"

	*argc = 0u;
	start = true;

	for (i = 0u; i < size; i++) {
		if (ascii[i] == '\0') {
			start = true;
		}
		else {
			if ((start == true) && (ascii[i] != '\0')) {
				if (j == nbArgs) {
					return (KERR_TEXT_TMARG);
				}

				argv[j] = (ascii + i);
				j++;
				*argc += 1u;
				start = false;
			}
		}
	}
	return (KERR_TEXT_NOERR);
}

/*
 * \brief Copy 2 ASCII buffers (\0 is copied)
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KSIZE    256
 *
 *          char_t     asciiD[KSIZE];
 *          int32_t    status;
 * const    char_t     asciiS[] = ”This is the buffer 2”;
 *
 *    status = text_copyAsciiBufferZ(asciiD, KSIZE, asciiS);
 * \endcode
 *
 * - The char "_" is used for space!
 *   - Ex. buffer1 R________
 *         buffer2 RXYZCRLF\0
 *
 * - sizeD is the size of asciiD, terminator included. A source that does not
 *   fit is truncated to sizeD - 1 characters, still terminated, and
 *   KERR_TEXT_TOLNG is returned; with sizeD == 0 nothing is written
 *
 * \param[out]	*asciiD			Ptr on the ASCII destination buffer
 * \param[in]	sizeD			Size of the destination buffer (terminator included)
 * \param[in]	*asciiS			Ptr on the ASCII source buffer
 * \return		KERR_TEXT_NOERR	OK
 * \return		KERR_TEXT_TOLNG	Text too long
 *
 */
int32_t	text_copyAsciiBufferZ(char_t *asciiD, uint32_t sizeD, const char_t *asciiS) {
			size_t		i, size;
			int32_t		status = KERR_TEXT_NOERR;
			char_t		*wkAsciiD = asciiD;
	const	char_t		*wkAsciiS = asciiS;

	if (sizeD == 0u) {
		return (KERR_TEXT_TOLNG);
	}

// A source that does not fit is truncated, and the destination still ends with
// its terminator. An empty source still gets its terminator: returning early
// here used to leave the previous contents of asciiD in place

	size = strlen(wkAsciiS);
	if (size >= sizeD) {
		size   = sizeD - 1u;
		status = KERR_TEXT_TOLNG;
	}

	for (i = 0u; i < size; i++) {
		*wkAsciiD = *wkAsciiS;
		wkAsciiD++;
		wkAsciiS++;
	}
	*wkAsciiD = '\0';
	return (status);
}

/*
 * \brief Copy 2 ASCII buffers (\0 is not copied)
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KSIZE    256
 *
 *          char_t     asciiD[KSIZE];
 *          int32_t    status;
 * const    char_t     asciiS[] = ”This is the buffer 2”;
 *
 *    status = text_copyAsciiBufferN(asciiD, KSIZE, asciiS);
 * \endcode
 *
 * - At most sizeD characters are written. A longer source is truncated and
 *   KERR_TEXT_TOLNG is returned
 *
 * \param[out]	*asciiD			Ptr on the ASCII destination buffer
 * \param[in]	sizeD			Number of characters asciiD can take
 * \param[in]	*asciiS			Ptr on the ASCII source buffer
 * \return		KERR_TEXT_NOERR	OK
 * \return		KERR_TEXT_TOLNG	Text too long
 *
 */
int32_t	text_copyAsciiBufferN(char_t *asciiD, uint32_t sizeD, const char_t *asciiS) {
			size_t		i, size;
			int32_t		status = KERR_TEXT_NOERR;
			char_t		*wkAsciiD = asciiD;
	const	char_t		*wkAsciiS = asciiS;

	size = strlen(wkAsciiS);
	if (size > sizeD) {
		size   = sizeD;
		status = KERR_TEXT_TOLNG;
	}

	for (i = 0u; i < size; i++) {
		*wkAsciiD = *wkAsciiS;
		wkAsciiD++;
		wkAsciiS++;
	}
	return (status);
}

/*
 * \brief Check if 2 ASCII buffers are identical
 *
 * Call example in C:
 *
 * \code{.c}
 *          boolc      *equal;
 *          int32_t    status;
 * const    char_t     ascii1[] = ”This is the buffer 1”;
 * const    char_t     ascii2[] = ”This is the buffer 2”;
 *
 *    status = text_checkAsciiBuffer(ascii1, ascii2, equals);
 * \endcode
 *
 * \param[in]	*ascii1			Ptr on the ASCII buffer 1
 * \param[in]	*ascii2			Ptr on the ASCII buffer 2
 * \param[out]	*equals			The 2 ASCII buffers are identical (true) or not (false)
 * \return		KERR_TEXT_NOERR	OK
 *
 */
int32_t	text_checkAsciiBuffer(const char_t *ascii1, const char_t *ascii2, bool *equals) {
	const	char_t	*wkAscii1 = ascii1;
	const	char_t	*wkAscii2 = ascii2;

	do {
		if (*wkAscii1 != *wkAscii2) {
			*equals = false;
			return (KERR_TEXT_NOERR);
		}

		wkAscii1++;
		wkAscii2++;
	} while ((*wkAscii1 != ' ') && (*wkAscii1 != '\0'));

	switch (*wkAscii2) {
		case ',':
		case ' ':
		case '\n':
		case '\r':
		case '\0': {
			*equals = true;
			return (KERR_TEXT_NOERR);
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}
	*equals = false;
	return (KERR_TEXT_NOERR);
}

/*
 * \brief Waiting for an ASCII string from a Serial Communication Manager
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KSIZE    256
 *
 * int32_t    status;
 * char_t     ascii[KSIZE];
 *
 *    status = text_waitString(KDEF0, ascii, KSIZE);
 * \endcode
 *
 * - Format of the order:
 *   - string\0 char is added at the end
 *     The CR or LF at the end are skipped
 *
 * \param[in]	serialManager	Serial Communication Manager
 * \param[in]	*ascii			Ptr on the ASCII buffer
 * \param[in]	size			Size of the ASCII buffer
 * \return		KERR_TEXT_NOERR	OK
 *
 */
int32_t	text_waitString(serialManager_t serialManager, char_t *ascii, uint32_t size) {
	serialManager_t		manager;
	proc_t				*process;

	switch (serialManager) {

// KNOTR: use the default Serial Communication Manager without to reserve it

		case KNOTR: {
			serial_flush(KDEF0);
			local_waitOrder(KDEF0, ascii, size);
			break;
		}

// KSYST: use the process specified Serial Communication Manager with its reservation

		case KSYST: {
			kern_getProcessRun(&process);
			kern_getSerialForProcess(process, &manager);

			RESERVE_SERIAL(manager, KMODE_READ);

			serial_flush(manager);
			local_waitOrder(manager, ascii, size);
			RELEASE_SERIAL(manager, KMODE_READ);

			break;
		}

// KXXX: use the specified Serial Communication Manager with its reservation

		default: {
			manager = serialManager;

			RESERVE_SERIAL(manager, KMODE_READ);

			serial_flush(manager);
			local_waitOrder(manager, ascii, size);
			RELEASE_SERIAL(manager, KMODE_READ);

			break;
		}
	}
	return (KERR_TEXT_NOERR);
}

// Local routines
// ==============

/*
 * \brief local_waitOrder
 *
 */
static	void	local_waitOrder(serialManager_t serialManager, char_t *ascii, uint32_t size) {
	char_t		aChar;
	uint32_t	nbChars = 0u;
	char_t		*identifier;
	sema_t		*semaphore;

	serial_getIdSemaphore(serialManager, BSERIAL_SEMAPHORE_RX, &identifier);
	kern_getSemaphoreById((const char_t *)identifier, &semaphore);

	while (true) {
		local_getChar(serialManager, &aChar, semaphore);

// Skip leading CR/LF (avoid returning empty lines due to leftover \n after \r\n)

		if ((nbChars == 0u) && ((aChar == '\r') || (aChar == '\n'))) {
			continue;
		}

// End-of-line

		if ((aChar == '\r') || (aChar == '\n')) {
			ascii[nbChars] = '\0';
			return;
		}

// Backspace

		if (aChar == '\b') {
			if (nbChars > 0u) {
				nbChars--;
			}
			continue;
		}

// Store char if room (keep 1 byte for '\0')

		if (nbChars < (size - 1u)) {
			ascii[nbChars++] = aChar;
		}
	}
}

/*
 * \brief local_getChar
 *
 */
static	void	local_getChar(serialManager_t serialManager, char_t *c, sema_t *semaphore) {
	uint32_t	size;

	switch ((uint32_t)serialManager & 0xFFFFFF00u) {

// The serialManager is a WFI0; the WFI0 is redirected to URTx
// The serialManager is a BLE0; the BLE0 is redirected to URTx
// The serialManager is a URTx

		case (KWFI0 & 0xFFFFFF00u):
		case (KBLE0 & 0xFFFFFF00u):
		case (KURT0 & 0xFFFFFF00u): {
			while (true) {
				size = 1u;
				if (serial_read(serialManager, (uint8_t *)c, &size) == KERR_SERIAL_NOERR) {
					return;
				}

				kern_waitSemaphore(semaphore, KWAIT_INFINITY);
			}
			break;
		}

// ... or any other managers

		case (KCDC0 & 0xFFFFFF00u):
		default: {
			while (true) {
				size = 1u;
				if (serial_read(serialManager, (uint8_t *)c, &size) == KERR_SERIAL_NOERR) {
					return;
				}

				kern_suspendProcess(2u);
			}
			break;
		}
	}
}

#endif
