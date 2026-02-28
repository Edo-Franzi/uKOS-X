/*
; list.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		List the system modules.
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

STRG_LOC_CONST(aStrApplication[]) =	"list         List the system modules.                  (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "List the system modules\n"
									"=======================\n\n"

									"This tool displays the modules of the system.\n"
									"All the family modules will be displayed.\n\n"

									"Input format:  list [IDfamily]\n"
									"Output format: IDfamily    name    comment    revision \n\n"

									"IDfamily:\n"
									"   'C' for Communication Manager family\n"
									"   'D' for Daemon family\n"
									"   'F' for Company family\n"
									"   'G' for Shared manager family\n"
									"   'K' for Kernel manager family\n"
									"   'L' for Generic manager family\n"
									"   'M' for Storage family\n"
									"   'N' for Neural manager family\n"
									"   'P' for Peripheral manager family\n"
									"   'Q' for Cryptographic manager family\n"
									"   'S' for StartUp family\n"
									"   'T' for Process family\n"
									"   'U' for Application family\n"
									"   'X' for CLI family\n"
									"   'Z' for Third Party family\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	bool		local_listModule(uint8_t idFamily);

MODULE(
	List,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_LIST,									// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
					uint8_t		i, idModule;
					int32_t		status;
					bool		error = false;
			const	char_t		*str;
	static	const	uint8_t		aFamilies[] = {
									KID_FAM_STARTUPS, KID_FAM_DAEMONS, KID_FAM_PROCESSES,
									KID_FAM_CLI, KID_FAM_KERNELS,
									KID_FAM_CRYPTOGRAPHICS, KID_FAM_NEURALS, KID_FAM_GENERICS, KID_FAM_STORAGE, KID_FAM_PERIPHERALS,
									KID_FAM_SERIALS, KID_FAM_COMPANY, KID_FAM_SHARED,
									KID_FAM_THIRD_PARTIES
								};

	(void)dprintf(KSYST, "uKOS-X module list.\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// list
// list P

	if (argc == 2u) {

// List of the selected family module

		str = argv[1];
		idModule = (uint8_t)(str[0]);
		error = (local_listModule(idModule) == true) ? (false) : (true);
	}

// List of all the module families

	else {
		for (i = 0u; i < (uint8_t)(sizeof(aFamilies) / sizeof(uint8_t)); i++) {
			local_listModule(aFamilies[i]);
		}
	}

	if (error == false) {  				 										   status = EXIT_OS_SUCCESS_CLI; }
	else				{ (void)dprintf(KSYST, "This family does not exist.\n\n"); status = EXIT_OS_FAILURE;	 }
	return (status);
}

// Local routines
// ==============

/*
 * \brief local_listModule
 *
 * - List a family modules
 *
 */
static	bool	local_listModule(uint8_t idFamily) {
			uint16_t		i, index = 0u;
			uint32_t		idModule;
			bool			found = false;
			char_t			bufIdent[4 + 1];
	const	char_t			*idIdentifier;
	const	uKOS_module_t	*module;

// List inside memx

	while (system_getModuleFamily(idFamily, &idModule, &index, &module) == KERR_SYSTEM_NOERR) {
		if ((module->oFlag & (1u<<BCONFIDENTIAL)) == 0) {
			found = true;

// Find a family code; display its identifier
//   The format is:
//   FLASH___nn___XYZT__rev__name_________Comment

			idIdentifier = (char_t *)&idModule;

			#if (defined(BIG_ENDIAN_S))
			for (i = 0u; i < 4u; i++) { bufIdent[i] = *(idIdentifier + i);		  }

			#else
			for (i = 0u; i < 4u; i++) { bufIdent[i] = *(idIdentifier + (3u - i)); }
			#endif

			bufIdent[4] = '\0';

			(void)dprintf(KSYST, "%s %3d  %s  v%s   %s\n", "FLASH", index, bufIdent, module->oStrRevision, module->oStrApplication);
		}
		index++;
	}
	if (found == true) { (void)dprintf(KSYST, "\n"); }
	return (found);
}
