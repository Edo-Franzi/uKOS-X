/*
; system.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		system manager.
;
; 			Management of the User RAM
;
;			The User RAM is used for these purposes:
;			1. Download and execute a programm or a tool
;			2. Download without the excecution of a program
;				- For a later excecution
;				- For burning the programm in a Mass Storage device
;
;			3. Excecution from a Mass Storage device (load the User RAM and execute)
;
;			Logic for the management of the User RAM
;
;			Download (cases 1 and 2)		lock the User RAM forever (until a restart)
;			Excecution from MEME1 (case 4)	lock the User RAM forever (until a restart)
;			Listing (case 3)				lock the User RAM during the usage and then, unlock
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

/*!
 * \addtogroup Lib_generics
 */
/**@{*/

/*!
 * \defgroup system System
 *
 * \brief System
 *
 * System management
 *
 * @{
 */

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

#define	SYSTEM_reserve	system_reserve
#define	SYSTEM_release	system_release

/*!
 * \brief Reserve the system manager (only for the User RAM)
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = system_reserve(KMODE_READ_WRITE, 1234);
 *    ....
 *    system_xyz();
 *    ....
 *    status = system_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode			Any mode
 * \param[in]	timeout				Timeout (1-ms of resolution)
 *									KWAIT_INFINITY, waiting forever
 *									KWAIT_REMAINING_TIMEOUT, waiting for the remaining timeout
 * \return		KERR_SYSTEM_NOERR	The manager is reserved
 * \return		KERR_SYSTEM_GEERR	General error
 * \return		KERR_SYSTEM_CHBSY	The manager is busy
 *
 */
extern	int32_t	system_reserve(reserveMode_t reserveMode, uint32_t timeout);

/*!
 * \brief Release the system manager (only for the User RAM)
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 *
 *    status = system_release(KMODE_READ_WRITE);
 * \endcode
 *
 * \param[in]	reserveMode			Any mode
 * \return		KERR_SYSTEM_NOERR	OK
 * \return		KERR_SYSTEM_GEERR	General error
 * \return		KERR_SYSTEM_CAREL	Cannot release the manager
 *
 */
extern	int32_t	system_release(reserveMode_t reserveMode);

/*!
 * \brief Get the module handle by its identifier (short)
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KIDMODULE    ((KID_FAM_PROCESSES<<16) | KNUM_STARTUP)
 *
 * int32_t          status;
 * uKOS_module_t    *module;
 * uint16_t         index;
 *
 * // Automatic reservation of the User RAM, never release
 *
 *    status = system_getModuleId(KIDMODULE, &index, &module);
 *    if (status == KERR_SYSTEM_NOERR) {
 *        module->oExecution(0, 0);
 *    }
 *
 * // Automatic reservation of the User RAM, manual release
 *
 *    status = system_getModuleId(KIDMODULE, &index, &module);
 *    if (status == KERR_SYSTEM_NOERR) {
 *        (void)dprintf(KSYST, "%s\n",module->oStrApplication);
 *        system_release(KMODE_READ_WRITE);
 *    }
 * \endcode
 *
 * \param[in]	idModule			The module identifier
 * \param[out]	*index				Ptr on the filer index
 * \param[out]	**module			Ptr on the module
 * \return		KERR_SYSTEM_NOERR	OK
 * \return		KERR_SYSTEM_GEERR	General error
 * \return		KERR_SYSTEM_NOMEM	The memory unit does not exist
 * \return		KERR_SYSTEM_NOMOD	The module does not exist
 * \return		KERR_SYSTEM_CHBSY	The manager is busy
 *
 */
extern	int32_t	system_getModuleId(uint32_t idModule, uint16_t *index, const uKOS_module_t **module);

/*!
 * \brief Get the identifier of the system family
 *
 * Call example in C:
 *
 * \code{.c}
 *          int32_t    status;
 * const    char_t     *family
 *
 *    status = system_getFamilyId(&family);
 * \endcode
 *
 * \param[out]	**family			Ptr on the family identifier
 * \return		KERR_SYSTEM_NOERR	OK
 *
 */
extern	int32_t	system_getFamilyId(const char_t **family);

/*!
 * \brief Get the module handle by its name
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t          status;
 * uKOS_module_t    *module;
 * uint16_t         index;
 *
 * // Automatic reservation of the User RAM, never release
 *
 *    status = system_getModuleName(“sloader”, &index, &module);
 *    if (status == KERR_SYSTEM_NOERR) {
 *        module->oExecution(0, 0);
 *    }
 *
 * // Automatic reservation of the User RAM, manual release
 *
 *    status = system_getModuleName(“sloader”, &index, &module);
 *    if (status == KERR_SYSTEM_NOERR) {
 *        (void)dprintf(KSYST, "%s/n",module->oStrApplication);
 *    }
 * \endcode
 *
 * \param[in]	*name				Ptr on the module name
 * \param[out]	*index				Ptr on the filer index
 * \param[out]	**module			Ptr on the module
 * \return		KERR_SYSTEM_NOERR	OK
 * \return		KERR_SYSTEM_GEERR	General error
 * \return		KERR_SYSTEM_NOMEM	The memory unit does not exist
 * \return		KERR_SYSTEM_NOMOD	The module does not exist
 * \return		KERR_SYSTEM_CHBSY	The manager is busy
 *
 */
extern	int32_t	system_getModuleName(const char_t *name, uint16_t *index, const uKOS_module_t **module);

/*!
 * \brief Get a module handle by its family and index
 *
 * Call example in C:
 *
 * \code{.c}
 * #define    KIDPRC    KID_FAM_PROCESSES
 *
 * int32_t          status;
 * uint32_t         idModule;
 * uKOS_module_t    *module;
 * uint16_t         index;
 *
 * // Automatic reservation of the User RAM, never release
 *
 *    index = 0;
 *    while (system_getModuleFamily(KIDPRC, &idModule, &index, &module) == KERR_SYSTEM_NOERR) {
 *        if (status == KERR_SYSTEM_NOERR) {
 *            module->oExecution(0, 0);
 *        }
 *    index++;
 *    }
 *
 * // Automatic reservation of the User RAM, manual release
 *
 *    index = 0;
 *    while (system_getModuleFamily(KIDPRC, &idModule, &index, &module) == KERR_SYSTEM_NOERR) {
 *        if (status == KERR_SYSTEM_NOERR) {
 *            (void)dprintf(KSYST, "%s\n",module->oStrApplication);
 *        }
 *    index++;
 *    }
 * \endcode
 *
 * \param[in]	family				The module family
 * \param[out]	*idModule			Ptr on the module identifier
 * \param[out]	*index				Ptr on the filer index
 * \param[out]	**module			Ptr on the module
 * \return		KERR_SYSTEM_NOERR	OK
 * \return		KERR_SYSTEM_GEERR	General error
 * \return		KERR_SYSTEM_NOMEM	The memory unit does not exist
 * \return		KERR_SYSTEM_NOFAM	The family does not exist
 * \return		KERR_SYSTEM_CHBSY	The manager is busy
 *
 */
extern	int32_t	system_getModuleFamily(uint8_t family, uint32_t *idModule, uint16_t *index, const uKOS_module_t **module);

/*!
 * \brief Get the system ASCII identifier Ptr
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * char_t     *identifier
 *
 *    status = system_getSystemId(&identifier);
 * \endcode
 *
 * - This function returns a char Ptr on the application string
 *
 * \param[out]	**identifier		Ptr on the identifier string
 * \return		KERR_SYSTEM_NOERR	OK
 *
 */
extern	int32_t	system_getSystemId(const char_t **identifier);

/*!
 * \brief Get the uKOS-X signature
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * char_t     *signature
 *
 *    status = system_getSystemSignature(&signature);
 * \endcode
 *
 * - This function returns a char Ptr on the signature string
 *
 * \param[out]	**signature			Ptr on the signature string
 * \return		KERR_SYSTEM_NOERR	OK
 *
 */
extern	int32_t	system_getSystemSignature(const char_t **signature);

/*!
 * \brief Get the system version
 *
 * Call example in C:
 *
 * \code{.c}
 * int32_t    status;
 * char_t     *version
 *
 *    status = system_getSystemVersion(&version);
 * \endcode
 *
 * \param[out]	**version			Ptr on the OS version string
 * \return		KERR_SYSTEM_NOERR	OK
 *
 */
extern	int32_t	system_getSystemVersion(const char_t **version);

/*!
 * \brief Set the downloaded code address
 *
 * Call example in C:
 *
 * \code{.c}
 * void    *address;
 *
 *    address = 0x12345678;
 *    status = system_setDownloadCodeAddress(address);
 * \endcode
 *
 * \param[in]	*address			Ptr on the downloaded code
 * \return		KERR_SYSTEM_NOERR	OK
 *
 */
extern	int32_t	system_setDownloadCodeAddress(void *address);

/*!
 * \brief Get the downloaded code address
 *
 * Call example in C:
 *
 * \code{.c}
 * void    *address;
 *
 *    status = system_getDownloadCodeAddress(&address);
 * \endcode
 *
 * \param[out]	**address			Ptr on the downloaded code
 * \return		KERR_SYSTEM_NOERR	OK
 *
 */
extern	int32_t	system_getDownloadCodeAddress(void **address);

#if (defined(__cplusplus))
}
#endif

/**@}*/
/**@}*/
