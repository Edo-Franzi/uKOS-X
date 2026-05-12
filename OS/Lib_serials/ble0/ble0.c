/*
; ble0.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		ble0 manager.
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

#if (defined(CONFIG_MAN_BLE0_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"ble0         ble0 manager.                             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "ble0 manager\n"
									"============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Ble0,							// Module name (the first letter has to be upper case)
	KID_FAM_SERIALS,				// Family (defined in the module.h)
	KNUM_BLE0,						// Module identifier (defined in the module.h)
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

extern	int32_t		stub_ble0_reserve(reserveMode_t reserveMode, uint32_t timeout);
extern	int32_t		stub_ble0_release(reserveMode_t reserveMode);
extern	int32_t		stub_ble0_configure(const urtxCnf_t *configure);
extern	int32_t		stub_ble0_write(const uint8_t *buffer, uint32_t size);
extern	int32_t		stub_ble0_read(uint8_t *buffer, uint32_t *size);
extern	int32_t		stub_ble0_getIdSemaphore(uint8_t semaphore, char_t **identifier);
extern	int32_t		stub_ble0_flush(void);

/*
 * \brief Reserve the ble0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = ble0_reserve(KMODE_WRITE, 1234u);
 *    ....
 *    ble0_xyz();
 *    ....
 *    status = ble0_release(KMODE_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode			KMODE_READ, KMODE_WRITE, KMODE_READ_WRITE
 * \param[in]	timeout				Timeout (1-ms of resolution)
 *									KWAIT_INFINITY, waiting forever
 *									KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_SERIAL_NOERR	The manager is reserved
 * \return		KERR_SERIAL_GEERR	General error
 * \return		KERR_SERIAL_CHBSY	The manager is busy
 *
 */
int32_t	ble0_reserve(reserveMode_t reserveMode, uint32_t timeout) {

	return(stub_ble0_reserve(reserveMode, timeout));
}

/*
 * \brief Release the ble0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = ble0_release(KMODE_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode			KMODE_READ, KMODE_WRITE, KMODE_READ_WRITE
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_GEERR	General error
 * \return		KERR_SERIAL_CAREL	Cannot release the manager
 *
 */
int32_t	ble0_release(reserveMode_t reserveMode) {

	return(stub_ble0_release(reserveMode));
}

/*
 * \brief Configure the ble0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t       status;
 * const    urtxCnf_t    configure = {
 *                            .oBaudRate = KSERIAL_BAUDRATE_57600,
 *                            .oKernSync = (1u<<BSERIAL_SEMAPHORE_RX),
 *                            .oNBBits   = KSERIAL_NB_BITS_8,
 *                            .oStopBits = KSERIAL_STOPBITS_1,
 *                            .oParity   = KSERIAL_PARITY_NONE
 *                        };
 *
 *    status = ble0_configure(&configure);
 * \endcode
 *
 * \param[in]	*configure			Ptr on the configuration buffer
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_GEERR	General error
 * \return		KERR_SERIAL_NOCNF	The configuration does not exist
 *
 */
int32_t	ble0_configure(const urtxCnf_t *configure) {

	return(stub_ble0_configure(configure));
}

/*
 * \brief Write a buffer to the ble0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KSIZE    10
 *
 * uint8_t    buffer[KSIZE] = { 0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u };
 * int32_t    status;
 *
 *    status = ble0_write(buffer, KSIZE);
 * \endcode
 *
 * \param[in]	*buffer				Ptr on the buffer
 * \param[in]	size				Size of the buffer
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_GEERR	General error
 * \return		KERR_SERIAL_SEPRO	The sender is busy
 * \return		KERR_SERIAL_LNBUB	The buffer length is too big
 * \return		KERR_SERIAL_LNBU0	The buffer length is = 0
 *
 */
int32_t	ble0_write(const uint8_t *buffer, uint32_t size) {

	return(stub_ble0_write(buffer, size));
}

/*
 * \brief Read a buffer from the ble0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * uint8_t     buffer[1];
 * uint32_t    size;
 * int32_t     status;
 *
 *    size = 1;
 *    status = ble0_read(buffer, &size);
 * \endcode
 *
 * \param[in]		*buffer				Ptr on the buffer
 * \param[in, out]	*size				Ptr on the size
 * \return			KERR_SERIAL_NOERR	OK
 * \return			KERR_SERIAL_GEERR	General error
 * \return			KERR_SERIAL_RBUEM	The receiver buffer is empty
 * \return			KERR_SERIAL_RBFUL	The receiver buffer is full
 * \return			KERR_SERIAL_EROVR	Overrun error
 * \return			KERR_SERIAL_ERNOI	Noise error
 * \return			KERR_SERIAL_ERFRA	Framing error
 * \return			KERR_SERIAL_ERPAR	Parity error
 *
 */
int32_t	ble0_read(uint8_t *buffer, uint32_t *size) {

	return(stub_ble0_read(buffer, size));
}

/*
 * \brief Get the semaphore identifier
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * char_t     *identifier[2];
 *
 *    status = ble0_getIdSemaphore(BSERIAL_SEMAPHORE_RX, &identifier[0];
 *    status = ble0_getIdSemaphore(BSERIAL_SEMAPHORE_TX, &identifier[1];
 *
 *    (void)dprintf(KSYST, "Semaphore ids: %s, ...%s\n", identifier[0], identifier[1]);
 * \endcode
 *
 * \param[in]	semaphore			RX or TX semaphore
 * \param[out]	**identifier		Ptr on the semaphore identifier
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_GEERR	General error
 * \return		KERR_SERIAL_SENOE	The semaphore does not exist
 *
 */
int32_t	ble0_getIdSemaphore(uint8_t semaphore, char_t **identifier) {

	return(stub_ble0_getIdSemaphore(semaphore, identifier));
}

/*
 * \brief Flush the ble0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = ble0_flush();
 * \endcode
 *
 * \return		KERR_SERIAL_NOERR	OK
 * \return		KERR_SERIAL_GEERR	General error
 *
 */
int32_t	ble0_flush(void) {

	return(stub_ble0_flush());
}

#endif
