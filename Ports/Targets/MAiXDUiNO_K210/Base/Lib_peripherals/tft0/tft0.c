/*
; tft0.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		tft0 manager (for nt35310).
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
#include	"../tft0/tft0.h"
#include	"../oct0/oct0.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"tft0         tft0 manager.                             (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "tft0 manager\n"
									"============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Tft0,							// Module name (the first letter has to be upper case)
	KID_FAM_PERIPHERALS,			// Family (defined in the module.h)
	KTFT0_NUM,						// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

/*
 * \brief Initialise the tft0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *    status = tft0_init(void);
 * \endcode
 *
 * \param[in]	-
 * \return		KOTFT0NOERR	OK
 * \return		KOTFT0GEERR	General error
 *
 */
int32_t	tft0_init(void) {
	cnfOctx_t	configure = {
					.oMode    = KOCTAL,
					.oNbBits  = 8u,
					.oXfer    = K8BITSAINC,
					.oDevider = KCLKDIV64
				};

	gpiohs->output_val.u32[0] |= (1u<<BLCD_DCX);
	oct0_init();

	gpiohs->output_val.u32[0] &= (uint32_t)~(1u<<BLCD_RST);
	kern_suspendProcess(100u);
	gpiohs->output_val.u32[0] |= (1u<<BLCD_RST);
	kern_suspendProcess(100u);

	oct0_configure(&configure);
	return (KERR_TFT0_NOERR);
}

/*
 * \brief Write command to the tft0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint8_t     command =  COLOR_SET;
 * uint32_t    xferMode = FILL;
 *
 *    status = tft0_writeCommand(command);
 * \endcode
 *
 * \param[in]	command			The command
 * \return		KERR_TFT0_NOERR	OK
 * \return		KERR_TFT0_GEERR	General error
 *
 */
int32_t	tft0_writeCommand(uint8_t command) {
	cnfOctx_t	configure = {
					.oMode    = KOCTAL,
					.oNbBits  = 8u,
					.oXfer    = K8BITSAINC,
					.oDevider = KCLKDIV64
				};

	oct0_configure(&configure);

	gpiohs->output_val.u32[0] &= (uint32_t)~(1u<<BLCD_DCX);
	oct0_write(SPI_SLAVE_SELECT, &command, 1u, KXFER8);
	return (KERR_TFT0_NOERR);
}

/*
 * \brief Write a byte to the tft0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint8_t     buffer[23] =  { 0, 1, 2 };
 *
 *    status = tft0_write8(buffer, 23);
 * \endcode
 *
 * \param[in]	*buffer			Ptr on the buffer to write
 * \param[in]	szBuffer		Size of the buffer
 * \return		KERR_TFT0_NOERR	OK
 * \return		KERR_TFT0_GEERR	General error
 *
 */
int32_t	tft0_write8(const uint8_t *buffer, uint32_t szBuffer) {
	cnfOctx_t	configure = {
					.oMode    = KOCTAL,
					.oNbBits  = 8u,
					.oXfer    = K8BITSAINC,
					.oDevider = KCLKDIV64
				};

	oct0_configure(&configure);

	gpiohs->output_val.u32[0] |= (1u<<BLCD_DCX);
	oct0_write(SPI_SLAVE_SELECT, buffer, szBuffer, KXFER8);
	return (KERR_TFT0_NOERR);
}

/*
 * \brief Write a word to the tft0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint16_t    buffer[23] =  { 0, 1, 2 };
 *
 *    status = tft0_write16(buffer, 23);
 * \endcode
 *
 * \param[in]	*buffer			Ptr on the buffer to write
 * \param[in]	szBuffer		Size of the buffer
 * \return		KERR_TFT0_NOERR	OK
 * \return		KERR_TFT0_GEERR	General error
 *
 */
int32_t	tft0_write16(const uint16_t *buffer, uint32_t szBuffer) {
	cnfOctx_t	configure = {
					.oMode    = KOCTAL,
					.oNbBits  = 16u,
					.oXfer    = K16BITSAINC,
					.oDevider = KCLKDIV64
				};

	oct0_configure(&configure);

	gpiohs->output_val.u32[0] |= (1u<<BLCD_DCX);
	oct0_write(SPI_SLAVE_SELECT, buffer, szBuffer, KXFER16);
	return (KERR_TFT0_NOERR);
}

/*
 * \brief Fill a word to the tft0 manager
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t     status;
 * uint16_t    color =  KMAGENTA;
 *
 *    status = tft0_fill16(buffer, 23);
 * \endcode
 *
 * \param[in]	*buffer			Ptr on the buffer to write
 * \param[in]	szBuffer		Size of the buffer
 * \return		KERR_TFT0_NOERR	OK
 * \return		KERR_TFT0_GEERR	General error
 *
 */
int32_t	tft0_fill16(const uint16_t *buffer, uint32_t szBuffer) {
	cnfOctx_t	configure = {
					.oMode    = KOCTAL,
					.oNbBits  = 16u,
					.oXfer    = K16BITSFILL,
					.oDevider = KCLKDIV64
				};

	oct0_configure(&configure);

	gpiohs->output_val.u32[0] |= (1u<<BLCD_DCX);
	oct0_write(SPI_SLAVE_SELECT, buffer, szBuffer, KFILL);
	return (KERR_TFT0_NOERR);
}
