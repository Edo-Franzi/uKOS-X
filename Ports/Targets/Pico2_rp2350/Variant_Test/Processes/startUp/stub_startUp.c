/*
; stub_startUp.
; =============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		startUp process; execute some important initialisations
;			before jumping to the selected function.
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

// Bootstrap function table
// ------------------------

typedef	struct	boot	boot_t;

struct	boot {
				uint8_t				oSW;				// Switch value
		const	char_t				*oFunction;			// Ptr on the function
				uint8_t				oBaudrate;			// Baudrate
				serialManager_t		oSerialManager;		// Default Serial Communication Manager
				uint8_t				oArgC;				// Number of arguments
		const	char_t				**oArgV;			// Ptr on the arguments
		};

#if (CONFIG_DIFFERENT_SERIAL_PER_CORE_S == true)

// Core 0 & 1 use different communication channels
// -----------------------------------------------

static	const	char_t	*argv_cnsCdc0_C0[] = { "console", "cdc0" };
static	const	char_t	*argv_cnsUrt0_C1[] = { "console", "urt0" };

static	const	boot_t	aFunction_C0[] = {
							{ 0x00u, "console", KSERIAL_BAUDRATE_460800, KCDC0, 2u, argv_cnsCdc0_C0 },
						};
static	const	boot_t	aFunction_C1[] = {
							{ 0x00u, "console", KSERIAL_BAUDRATE_460800, KURT0, 2u, argv_cnsUrt0_C1 },
						};

#define	KDEF_COMM_C0		KCDC0
#define	KDEF_COMM_C1		KURT0
#define	KNB_FUNCTIONS_C0	(sizeof(aFunction_C0) / sizeof(boot_t))
#define	KNB_FUNCTIONS_C1	(sizeof(aFunction_C1) / sizeof(boot_t))

STRG_GLB_CONST(aStartUp_StrHelp[]) = "StartUp process\n"
									 "================\n\n"

									 "StartUp switch action. The default settings are:\n"
									 "460800-bit/s, 8-bits, 2-stop-bits, no parity.\n\n"

									 "   SW1\n"
									 "    0   KCDC0, console (460800-bit/s) for core 0\n"
									 "    0   KURT0, console (460800-bit/s) for core 1\n\n";

#else

// Core 0 & 1 use the same communication channel
// ---------------------------------------------

static	const	char_t	*argv_cnsUrt0_Cx[] = { "console", "urt0" };

static	const	boot_t	aFunction_Cx[] = {
							{ 0x00u, "console", KSERIAL_BAUDRATE_460800, KURT0, 2u, argv_cnsUrt0_Cx },
						};

#define	KDEF_COMM_Cx		KURT0
#define	KNB_FUNCTIONS_Cx	(sizeof(aFunction_Cx) / sizeof(boot_t))

STRG_GLB_CONST(aStartUp_StrHelp[]) = "StartUp process\n"
									 "================\n\n"

									 "StartUp switch action. The default settings are:\n"
									 "460800-bit/s, 8-bits, 2-stop-bits, no parity.\n\n"

									 "   SW1\n"
									 "    0   KURT0, console (460800-bit/s) for core 0 & 1\n\n";
#endif

// Module strings


STRG_LOC_CONST(aStrLogo[]) = STRG_LOGO;

/*
 * \brief stub_startUp_launch
 *
 */
void	stub_startUp_launch(void) {
			uint8_t			i, nbFunctions;
			uint16_t		index;
			uint32_t		mode;
			bool			error = false;
			urtxCnf_t		configureURTx;
			urtxCnf_t		configureCDCx;
			proc_t			*process;
	const	boot_t			*functions;
	const	uKOS_module_t	*module;
	const	char_t			*identifier, *signature;


// Configure by default all the Serial Communication Managers
// Set the default communication device (KSYST)

	mode = 0;

	#if (CONFIG_DIFFERENT_SERIAL_PER_CORE_S == true)
	uint32_t	core;

	core = GET_RUNNING_CORE;

	switch (core) {
		default:
		case KCORE_0: {
			nbFunctions = (uint8_t)KNB_FUNCTIONS_C0;
			functions	= &aFunction_C0[0];

			serial_setDefSerialManager(KDEF_COMM_C0);
			kern_suspendProcess(500u);

			configureURTx.oNBBits   = KSERIAL_NB_BITS_8;
			configureURTx.oStopBits = KSERIAL_STOPBITS_1;
			configureURTx.oParity   = KSERIAL_PARITY_NONE;
			configureURTx.oBaudRate = functions[mode].oBaudrate;
			configureURTx.oKernSync = ((uint32_t)1u<<(uint32_t)BSERIAL_SEMAPHORE_RX);
			serial_configure(KURT0, &configureURTx);

			configureCDCx.oNBBits   = KSERIAL_NB_BITS_8;
			configureCDCx.oStopBits = KSERIAL_STOPBITS_1;
			configureCDCx.oParity   = KSERIAL_PARITY_NONE;
			configureCDCx.oBaudRate = functions[mode].oBaudrate;
			configureCDCx.oKernSync = ((uint32_t)1u<<(uint32_t)BSERIAL_SEMAPHORE_RX);
			serial_configure(KCDC0, &configureCDCx);
			break;
		}
		case KCORE_1: {
			nbFunctions = (uint8_t)KNB_FUNCTIONS_C1;
			functions	= &aFunction_C1[0];

			serial_setDefSerialManager(KDEF_COMM_C1);
			kern_suspendProcess(500u);

			configureURTx.oNBBits   = KSERIAL_NB_BITS_8;
			configureURTx.oStopBits = KSERIAL_STOPBITS_1;
			configureURTx.oParity   = KSERIAL_PARITY_NONE;
			configureURTx.oBaudRate = functions[mode].oBaudrate;
			configureURTx.oKernSync = ((uint32_t)1u<<(uint32_t)BSERIAL_SEMAPHORE_RX);
			serial_configure(KURT0, &configureURTx);
			break;
		}
	}

	#else
	nbFunctions = (uint8_t)KNB_FUNCTIONS_Cx;
	functions	= &aFunction_Cx[0];

	serial_setDefSerialManager(KDEF_COMM_Cx);
	kern_suspendProcess(500u);

	configureURTx.oNBBits   = KSERIAL_NB_BITS_8;
	configureURTx.oStopBits = KSERIAL_STOPBITS_1;
	configureURTx.oParity   = KSERIAL_PARITY_NONE;
	configureURTx.oBaudRate = functions[mode].oBaudrate;
	configureURTx.oKernSync = ((uint32_t)1u<<(uint32_t)BSERIAL_SEMAPHORE_RX);
	serial_configure(KURT0, &configureURTx);
	#endif

// Bootstrap ...
// -------------

// Launch all the possible applications
// Determine the "i" index on the function table

	kern_getProcessRun(&process);
	for (i = 0u; i < nbFunctions; i++) {
		if (functions[i].oSW == mode) {
			kern_setSerialForProcess(process, functions[i].oSerialManager);
		}
	}

	system_getSystemId(&identifier);
	system_getSystemSignature(&signature);

	(void)dprintf(KSYST, "%s", aStrLogo);
	(void)dprintf(KSYST, "Signature:\n%s\n\n", signature);
	(void)dprintf(KSYST, "%ssw = %"PRIX32"\n", identifier, mode);

	kern_suspendProcess(500u);

	for (i = 0u; i < nbFunctions; i++) {
		if (functions[i].oSW == mode) {

// The communication

			switch (functions[i].oSerialManager) {
				case KURT0: { configureURTx.oBaudRate = functions[i].oBaudrate; serial_configure(KURT0, &configureURTx); break; }
				case KCDC0: { configureCDCx.oBaudRate = functions[i].oBaudrate; serial_configure(KCDC0, &configureCDCx); break; }
				default: {

// Make MISRA happy :-)

					break;
				}
			}

// The mode exist
// Found a module; execute it or error

			if (system_getModuleName(functions[i].oFunction, &index, &module) != KERR_SYSTEM_NOERR) {
				error = true;
			}

			if (error == true) {
				(void)dprintf(KSYST, "Module not found or user memory busy by a running application.\n\n");
				while (true) { kern_suspendProcess(1u); }
			}
			else {

				switch (module->oExecution(functions[i].oArgC, functions[i].oArgV)) {
					case EXIT_OS_FAILURE_CRT0: {
						(void)dprintf(KSYST, "Incompatible OS!!!\nReload the latest OS inside the target.\n");
						break;
					}
					default: {

// Make MISRA happy :-)

						break;
					}
				}
			}
		}
	}
}
