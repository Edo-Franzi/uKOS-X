/*
; shared_spi0.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		For the shared_spi0 manager module.
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
#include	"shared_spi0.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"shared_spi0  Sharing of the spi0 device.               (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "spi0 shared device\n"
									"==================\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	Shared_spi0,					// Module name (the first letter has to be upper case)
	KID_FAM_SHARED,					// Family (defined in the module.h)
	KNUM_SHARED_SPI_0,				// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Prototypes

static	void	local_spi0_imu_init(void);
static	void	local_spi0_flash_init(void);

/*
 * \brief Reserve the shared spi0 device
 *
 * \param[in]	manager				The manager identifier
 * \param[in]	timeout				Timeout in ms (KWAIT_INFINITY = infinite time)
 * \return		KSHARED_SPI0_NOERR	OK
 * \return		KSHARED_SPI0_GEERR	General error
 * \return		KSHARED_SPI0_CHBSY 	The shared spi0 device is busy
 *
 */
int32_t	shared_spi0_reserve(uint32_t manager, uint32_t timeout) {
			int32_t		status;
	static	uint32_t	preManager = KNOMANAGER;

	switch (spi_reserve(KSPI0, KMODE_READ_WRITE, timeout)) {
		case KERR_SPI_NOERR: {
			if (manager != preManager) {
				preManager = manager;

				switch (manager) {
					case KIMU:
					case KIMUA:
					case KIMUM:
					case KTEMPERATURE: { local_spi0_imu_init();   break; }
					case KFLASH:	   { local_spi0_flash_init(); break; }
					default: {

// Make MISRA happy :-)

						break;
					}
				}
			}
			status = KSHARED_SPI0_NOERR;
			break;
		}
		case KERR_SPI_CHBSY: {
			status = KSHARED_SPI0_CHBSY;
			break;
		}
		case KERR_SPI_GEERR:
		default: {
			status = KSHARED_SPI0_GEERR;
			break;
		}
	}
	return (status);
}

/*
 * \brief Release the shared spi0 device
 *
 * \return		KSHARED_SPI0_NOERR	OK
 * \return		KSHARED_SPI0_GEERR	General error
 * \return		KSHARED_SPI0_CAREL	Cannot release the manager
 *
 */
int32_t	shared_spi0_release(void) {
	int32_t		status;

	switch (spi_release(KSPI0, KMODE_READ_WRITE)) {
		case KERR_SPI_NOERR: {
			status = KSHARED_SPI0_NOERR;
			break;
		}
		case KERR_SPI_CAREL: {
			status = KSHARED_SPI0_CAREL;
			break;
		}
		case KERR_SPI_GEERR:
		default: {
			status = KSHARED_SPI0_GEERR;
			break;
		}
	}
	return (status);
}

/*
 * \brief Select the shared spi0 manager
 *
 * \param[in]	manager				The manager identifier
 * \return		KSHARED_SPI0_NOERR	OK
 *
 */
int32_t	shared_spi0_select(uint32_t manager) {

	PRIVILEGE_ELEVATE;
	switch (manager) {
		case KTEMPERATURE:
		case KIMUA:  { GPIOC->ODR &= (uint32_t)~(1u<<BSEL_ACCELERO); break; }
		case KIMUM:  { GPIOF->ODR &= (uint32_t)~(1u<<BSEL_MAGNETO);  break; }
		case KFLASH: { GPIOB->ODR &= (uint32_t)~(1u<<BSEL_FLASH);	 break; }
		default: {

// Make MISRA happy :-)

			break;
		}
	}
	PRIVILEGE_RESTORE;
	return (KSHARED_SPI0_NOERR);
}

/*
 * \brief Deselect the shared spi0 manager
 *
 * \param[in]	manager				The manager identifier
 * \return		KSHARED_SPI0_NOERR	OK
 *
 */
int32_t	shared_spi0_deselect(uint32_t manager) {

	PRIVILEGE_ELEVATE;
	switch (manager) {
		case KTEMPERATURE:
		case KIMUA: { GPIOC->ODR |= (1u<<BSEL_ACCELERO);								   break; }
		case KIMUM: { GPIOF->ODR |= (1u<<BSEL_MAGNETO);									   break; }
		case KIMU:  { GPIOC->ODR |= (1u<<BSEL_ACCELERO); GPIOF->ODR |= (1u<<BSEL_MAGNETO); break; }
		case KFLASH: { GPIOB->ODR |= (1u<<BSEL_FLASH);									   break; }
		default: {

// Make MISRA happy :-)

			break;
		}
	}
	PRIVILEGE_RESTORE;
	return (KSHARED_SPI0_NOERR);
}

/*
 * \brief Write/Read to/from the shared spi0 manager
 *
 * \param[in, out]	*data				Ptr on the data
 * \return			KSHARED_SPI0_NOERR	OK
 * \return			KSHARED_SPI0_TIMEO	Timeout error
 *
 */
int32_t	shared_spi0_writeRead(uint8_t *data) {

	spi_writeRead(KSPI0, data);
	return (KSHARED_SPI0_NOERR);
}

// Local routines
// ==============

/*
 * \brief local_spi0_imu_init
 *
 * - Master, POL = PHA = 1
 * - Speed accesses ~5-Mbit/s
 *
 */
static	void	local_spi0_imu_init(void) {
	static	const	spiCnf_t	configure = {
									.oSpeed    = 5000000u,
									.oMode     = (uint8_t)KSPI_MASTER,
									.oClock    = (1u<<(uint8_t)BSPI_POL) | (1u<<(uint8_t)BSPI_PHA)
								};

	spi_configure(KSPI0, &configure);
}

/*
 * \brief local_spi0_flash_init
 *
 * - Master, POL = PHA = 0
 * - Speed accesses ~20-Mbit/s
 *
 */
static	void	local_spi0_flash_init(void) {
	static	const	spiCnf_t	configure = {
									.oSpeed    = 20000000u,
									.oMode     = (uint8_t)KSPI_MASTER,
									.oClock    = 0u
								};

	spi_configure(KSPI0, &configure);
}
