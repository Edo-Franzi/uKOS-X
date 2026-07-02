/*
; stub_startUp.
; =============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2026-07-02
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
		const	char_t				*oFunction;			// Ptr on the function
				serialManager_t		oSerialManager;		// Default Serial Communication Manager
		const	char_t				**oArgV;			// Ptr on the arguments
				uint8_t				oArgC;				// Number of arguments
				uint8_t				oSW;				// Switch value
				uint8_t				oBaudrate;			// Baudrate
		};

static	const	char_t	*argv_cnsUrt0[] = { "console",	   "urt0"			};
static	const	char_t	*argv_mpyUrt0[] = { "microPython", "urt0", "100000" };

static	const	boot_t	aFunction[] = {
							{ "console",	 KURT0, argv_cnsUrt0, 2u, 0x00u, KSERIAL_BAUDRATE_460800 },
							{ "microPython", KURT0, argv_mpyUrt0, 3u, 0x01u, KSERIAL_BAUDRATE_460800 }
						};

#define	KDEF_COMM		KURT0
#define	KNB_FUNCTIONS	(sizeof(aFunction) / sizeof(boot_t))

// Module strings

STRG_GLB_CONST(aStartUp_StrHelp[]) = "StartUp process\n"
									 "===============\n\n"

									 "StartUp switch action. The default settings are:\n"
									 "460800-bit/s, 8-bits, 2-stop-bits, no parity.\n\n"

									 "   SW3\n"
									 "    0   KURT0, console     (460800-bit/s).\n"
									 "    1   KURT0, microPython (460800-bit/s).\n\n";

STRG_LOC_CONST(aStrLogo[]) = STRG_LOGO;

/*
 * \brief stub_startUp_launch
 *
 */
void	stub_startUp_launch(void) {
			uint8_t			i;
			uint16_t		index;
			uint32_t		mode;
			bool			error = false;
			urtxCnf_t		configureURTx;
			cdcxCnf_t		configureCDCx;
			proc_t			*process;
	const	uKOS_module_t	*module;
	const	char_t			*identifier, *signature;

// Configure by default all the Serial Communication Managers
// Set the default communication device (KSYST)

	switch_read(&mode);
	if (mode >= KNB_FUNCTIONS) {
		mode = 0u;
	}

	serial_setDefSerialManager(KDEF_COMM);

	configureURTx.oNBBits   = KSERIAL_NB_BITS_8;
	configureURTx.oStopBits = KSERIAL_STOPBITS_1;
	configureURTx.oParity   = KSERIAL_PARITY_NONE;
	configureURTx.oBaudRate = aFunction[mode].oBaudrate;
	configureURTx.oKernSync = ((uint32_t)1u<<(uint32_t)BSERIAL_SEMAPHORE_RX);
	configureCDCx.oKernSync = ((uint32_t)1u<<(uint32_t)BSERIAL_SEMAPHORE_RX);
	serial_configure(KURT0, &configureURTx);
	serial_configure(KCDC0, &configureCDCx);

// Bootstrap ...
// -------------

// Launch all the possible applications
// Determine the "i" index on the function table

	kern_getProcessRun(&process);
	for (i = 0u; i < (uint8_t)KNB_FUNCTIONS; i++) {
		if (aFunction[i].oSW == mode) {
			kern_setSerialForProcess(process, aFunction[i].oSerialManager);
		}
	}

	system_getSystemId(&identifier);
	system_getSystemSignature(&signature);

	(void)dprintf(KSYST, "%s", aStrLogo);
	(void)dprintf(KSYST, "Signature:\n%s\n\n", signature);
	(void)dprintf(KSYST, "%ssw = %"PRIu32"\n\n", identifier, mode);
	kern_suspendProcess(500u);

	for (i = 0u; i < (uint8_t)KNB_FUNCTIONS; i++) {
		if (aFunction[i].oSW == mode) {

// The communication

			switch (aFunction[i].oSerialManager) {

// If the serial device is already configured,
// do not reconfigure it again.
// This avoids corrupting ongoing transfers.
//
//				case KURT0: { configureURTx.oBaudRate = aFunction[i].oBaudrate; serial_configure(KURT0, &configureURTx); break; }
				default: {

// Make MISRA happy :-)

					break;
				}
			}

// The mode exist
// Found a module; execute it or error

			if (system_getModuleName(aFunction[i].oFunction, &index, &module) != KERR_SYSTEM_NOERR) {
				error = true;
			}

			if (error == true) {
				(void)dprintf(KSYST, "Module not found or user memory busy by a running application.\n\n");
				while (true) { kern_suspendProcess(1u); }
			}
			else {

				switch (module->oExecution(aFunction[i].oArgC, aFunction[i].oArgV)) {
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
