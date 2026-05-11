/*
; system.
; =======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

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

#include	"uKOS.h"
#include	"linker.h"
#include	"version.h"
#include	"kern/private/private_processes.h"

#if (defined(CONFIG_MAN_SYSTEM_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"system       system manager.                           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "system manager\n"
									"==============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	System,							// Module name (the first letter has to be upper case)
	KID_FAM_GENERICS,				// Family (defined in the module.h)
	KNUM_SYSTEM,					// Module identifier (defined in the module.h)
	nullptr,						// Address of the initialisation code (early pre-init)
	nullptr,						// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,						// Address of the clean code (clean the module)
	" 1.0",							// Revision string (major . minor)
	(1u<<BSHOW),					// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0								// Execution cores
);

// Library specific
// ================

STRG_LOC_CONST(aStrApp[]) = uKOS_KBOARD", V."uKOS_VERSION", "__DATE__"  "__TIME__"\n"uKOS_COMPILER", "VERSIONING_TOOL" "SW_VERSION"\n";
STRG_LOC_CONST(aStrRev[]) = uKOS_VERSION_NUMBER;
STRG_LOC_CONST(KFAMILY[]) = KTARGET;

static	void	*vDoLoCode[KNB_CORES]	= MCSET(nullptr);		// Ptr on the execution code after the download
static	bool	vUserRamBusy[KNB_CORES] = MCSET(false);		// Availability of the User Ram

// Prototypes

static	int32_t	local_init(void);

/*
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
int32_t	system_reserve(reserveMode_t reserveMode, uint32_t timeout) {
	int32_t		status;
	uint32_t	core;

	UNUSED(reserveMode);
	UNUSED(timeout);

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SYSTEM_NOERR) { PRIVILEGE_RESTORE; return (status); }

// The User RAM is available, so, reserve it
// The User RAM is busy, so, indicate busy

	INTERRUPTION_OFF;
	status = KERR_SYSTEM_CHBSY;

	if (vUserRamBusy[core] == false) {
		vUserRamBusy[core] = true;
		status = KERR_SYSTEM_NOERR;
	}
	INTERRUPTION_RESTORE;
	PRIVILEGE_RESTORE;
	return (status);
}

/*
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
int32_t	system_release(reserveMode_t reserveMode) {
	int32_t		status;
	uint32_t	core;

	UNUSED(reserveMode);

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SYSTEM_NOERR) { PRIVILEGE_RESTORE; return (status); }

	vUserRamBusy[core] = false;
	PRIVILEGE_RESTORE;
	return (KERR_SYSTEM_NOERR);
}

/*
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
 *        (void)dprintf(KSYST, "%s\n", module->oStrApplication);
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
int32_t	system_getModuleId(uint32_t idModule, uint16_t *index, const uKOS_module_t **module) {
	int32_t		status;
	const		uKOS_directory_t	*aDirectory;

	aDirectory = ALIGNED_PTR(uKOS_directory_t, linker_stDirectory);

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SYSTEM_NOERR) { PRIVILEGE_RESTORE; return (status); }

	*module	= nullptr;
	*index	= 0u;
	while (aDirectory[*index].oModuleLocation != KNO_MODULE) {
		if (aDirectory[*index].oModule->oIdModule == idModule) {
			*module = aDirectory[*index].oModule;
			PRIVILEGE_RESTORE;
			return (KERR_SYSTEM_NOERR);
		}

		*index = (uint16_t)(*index + 1u);
	}
	PRIVILEGE_RESTORE;
	return (KERR_SYSTEM_NOMOD);
}

/*
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
int32_t	system_getFamilyId(const char_t **family) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SYSTEM_NOERR) { PRIVILEGE_RESTORE; return (status); }

	*family = KFAMILY;
	PRIVILEGE_RESTORE;
	return (KERR_SYSTEM_NOERR);
}

/*
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
 *        (void)dprintf(KSYST, "%s/n", module->oStrApplication);
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
int32_t	system_getModuleName(const char_t *name, uint16_t *index, const uKOS_module_t **module) {
			int32_t				status;
			bool				equals;
	const	uKOS_directory_t	*aDirectory;

	aDirectory = ALIGNED_PTR(uKOS_directory_t, linker_stDirectory);

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SYSTEM_NOERR) { PRIVILEGE_RESTORE; return (status); }

	*module	= nullptr;
	*index	= 0u;
	while (aDirectory[*index].oModuleLocation != KNO_MODULE) {
		text_checkAsciiBuffer(aDirectory[*index].oModule->oStrApplication, name, &equals);
		if (equals == true) {
			*module = aDirectory[*index].oModule;
			PRIVILEGE_RESTORE;
			return (KERR_SYSTEM_NOERR);
		}

		*index = (uint16_t)(*index + 1u);
	}
	PRIVILEGE_RESTORE;
	return (KERR_SYSTEM_NOMOD);
}

/*
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
 *            (void)dprintf(KSYST, "%s\n", module->oStrApplication);
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
int32_t	system_getModuleFamily(uint8_t family, uint32_t *idModule, uint16_t *index, const uKOS_module_t **module) {
	int32_t		status;
	const		uKOS_directory_t	*aDirectory;

	aDirectory = ALIGNED_PTR(uKOS_directory_t, linker_stDirectory);

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SYSTEM_NOERR) { PRIVILEGE_RESTORE; return (status); }

	*module	= nullptr;
	while (aDirectory[*index].oModuleLocation != KNO_MODULE) {
		if (((aDirectory[*index].oModule->oIdModule>>24u) == family) || (family == KID_FAM_ALL_FAMILIES)) {
			*idModule = aDirectory[*index].oModule->oIdModule;
			*module = aDirectory[*index].oModule;
			PRIVILEGE_RESTORE;
			return (KERR_SYSTEM_NOERR);
		}

		*index = (uint16_t)(*index + 1u);
	}
	PRIVILEGE_RESTORE;
	return (KERR_SYSTEM_NOFAM);
}

/*
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
int32_t	system_getSystemId(const char_t **identifier) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SYSTEM_NOERR) { PRIVILEGE_RESTORE; return (status); }

	*identifier = aStrApp;
	PRIVILEGE_RESTORE;
	return (KERR_SYSTEM_NOERR);
}

/*
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
int32_t	system_getSystemSignature(const char_t **signature) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SYSTEM_NOERR) { PRIVILEGE_RESTORE; return (status); }

	*signature = ALIGNED_PTR(const char_t, linker_stSignature);

	PRIVILEGE_RESTORE;
	return (KERR_SYSTEM_NOERR);
}

/*
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
int32_t	system_getSystemVersion(const char_t **version) {
	int32_t		status;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SYSTEM_NOERR) { PRIVILEGE_RESTORE; return (status); }

	*version = aStrRev;
	PRIVILEGE_RESTORE;
	return (KERR_SYSTEM_NOERR);
}

/*
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
int32_t	system_setDownloadCodeAddress(void *address) {
	int32_t		status;
	uint32_t	core;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SYSTEM_NOERR) { PRIVILEGE_RESTORE; return (status); }

	vDoLoCode[core] = address;
	PRIVILEGE_RESTORE;
	return (KERR_SYSTEM_NOERR);
}

/*
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
int32_t	system_getDownloadCodeAddress(void **address) {
	int32_t		status;
	uint32_t	core;

	core = GET_RUNNING_CORE;

	PRIVILEGE_ELEVATE;
	status = local_init();
	if (status != KERR_SYSTEM_NOERR) { PRIVILEGE_RESTORE; return (status); }

	*address = vDoLoCode[core];
	PRIVILEGE_RESTORE;
	return (KERR_SYSTEM_NOERR);
}

// Local routines
// ==============

/*
 * \brief local_init
 *
 * - This function initialises the manager and
 *   has to be called at least once
 *
 */
static	int32_t	local_init(void) {
			int32_t		status = KERR_SYSTEM_NOERR;
			uint32_t	core;
	static	bool		vInit[KNB_CORES] = MCSET(false);

	core = GET_RUNNING_CORE;

	INTERRUPTION_OFF;
	if (vInit[core] == false) {
		vInit[core] = true;
	}
	RETURN_INT_RESTORE(status);
}

#endif
