/*
; szkern.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Give the uKernel memory footprint.
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
#include	"kern/private/private_processes.h"
#include	"kern/private/private_pools.h"
#include	"kern/private/private_signals.h"
#include	"kern/private/private_mailboxes.h"
#include	"kern/private/private_semaphores.h"
#include	"kern/private/private_mutexes.h"
#include	"kern/private/private_softwareTimer.h"
#include	"kern/private/private_preciseSignals.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"szkern       Give the uKernel memory footprint.        (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Give the uKernel memory footprint\n"
									"=================================\n\n"

									"This tool displays information about the uKernel memory\n"
									"footprint.\n\n"

									"Input format:  szkern\n"
									"Output format: uKernel objects\n\n"

									"               Number of objects          m, object size n\n\n"

									"               uKernel memory footprint including the daemons stacks\n"
									"               Section text:      addr = 0x********, size = 0x********  xyz-K\n"
									"               Section rodata:    addr = 0x********, size = 0x********  xyz-K\n"
									"               Section data:      addr = 0x********, size = 0x********  xyz-K\n"
									"               section bss:       addr = 0x********, size = 0x********  xyz-K\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Szkern,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_SZ_KERN,								// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

#define local_linker_stTEXT_KERN_p		linker_stTEXT_KERN_p
#define local_linker_enTEXT_KERN_p		linker_enTEXT_KERN_p
#define local_linker_stRODATA_KERN_p	linker_stRODATA_KERN_p
#define local_linker_enRODATA_KERN_p	linker_enRODATA_KERN_p
#define local_linker_stDATA_KERN_p		linker_stDATA_KERN_p
#define local_linker_enDATA_KERN_p		linker_enDATA_KERN_p
#define local_linker_stBSS_KERN_p		linker_stBSS_KERN_p
#define local_linker_enBSS_KERN_p		linker_enBSS_KERN_p

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	uint16_t	nbDeamons = 2u;
	int32_t		szTEXT, szRODATA, szDATA, szBSS;
	float64_t	szTEXTf, szRODATAf, szDATAf, szBSSf;

	UNUSED(argc);
	UNUSED(argv);

	#if (KKERN_WITH_STATISTICS_S == true)
	nbDeamons += 1u;
	#endif

	szTEXT   = (int32_t)((uintptr_t)local_linker_enTEXT_KERN_p   - (uintptr_t)local_linker_stTEXT_KERN_p);
	szRODATA = (int32_t)((uintptr_t)local_linker_enRODATA_KERN_p - (uintptr_t)local_linker_stRODATA_KERN_p);
	szDATA   = (int32_t)((uintptr_t)local_linker_enDATA_KERN_p   - (uintptr_t)local_linker_stDATA_KERN_p);
	szBSS	 = (int32_t)((uintptr_t)local_linker_enBSS_KERN_p    - (uintptr_t)local_linker_stBSS_KERN_p) + (int32_t)(nbDeamons * (KKERN_SZ_STACK_SS * sizeof(uintptr_t)));

	szTEXTf   = (float64_t)szTEXT   / 1024.0;
	szRODATAf = (float64_t)szRODATA / 1024.0;
	szDATAf   = (float64_t)szDATA   / 1024.0;
	szBSSf    = (float64_t)szBSS    / 1024.0;

	(void)dprintf(KSYST, "uKernel memory footprint information.\n");

	#if (KKERN_WITH_STATISTICS_S == true)
	(void)dprintf(KSYST, "uKernel objects - statistics on\n\n");

	#else
	(void)dprintf(KSYST, "uKernel objects - statistics off\n\n");
	#endif

	(void)dprintf(KSYST, "Number of daemons          %3d\n", nbDeamons);
	(void)dprintf(KSYST, "Number of processes        %3d, object size %4d [Bytes]\n", (KKERN_NB_PROCESSES - nbDeamons),		  sizeof(proc_t));
	(void)dprintf(KSYST, "Number of mailboxes        %3d, object size %4d [Bytes]\n", KKERN_NB_MAILBOXES,					  sizeof(mbox_t));
	(void)dprintf(KSYST, "Number of semaphores       %3"PRIu16", object size %4"PRIu16" [Bytes]\n", KKERN_NB_SEMAPHORES,	  sizeof(sema_t));
	(void)dprintf(KSYST, "Number of mutex            %3"PRIu16", object size %4"PRIu16" [Bytes]\n", KKERN_NB_MUTEXES,		  sizeof(mutx_t));
	(void)dprintf(KSYST, "Number of signals (x32)    %3"PRIu16", object size %4"PRIu16" [Bytes]\n", KKERN_NB_SIGNALS,		  sizeof(sign_t));

	#if (KKERN_NB_SOFTWARE_TIMERS > 0)
	(void)dprintf(KSYST, "Number of software timers  %3"PRIu16", object size %4"PRIu16" [Bytes]\n", KKERN_NB_SOFTWARE_TIMERS, sizeof(stim_t));
	#endif

	#if (KKERN_NB_POOLS > 0)
	(void)dprintf(KSYST, "Number of pools            %3"PRIu16", object size %4"PRIu16" [Bytes]\n", KKERN_NB_POOLS,			  sizeof(pool_t));
	#endif

	#if (KKERN_NB_PRECISE_SIGNALS > 0)
	(void)dprintf(KSYST, "Number of precise signals  %3"PRIu16", object size %4"PRIu16" [Bytes]\n", KKERN_NB_PRECISE_SIGNALS, sizeof(prcs_t));
	#endif

	(void)dprintf(KSYST, "\nuKernel memory footprint including the daemons stacks\n");
	(void)dprintf(KSYST, "Section text:      addr = 0x%016"PRIXPTR", size = 0x%08"PRIX32" %5.2f [KBytes]\n",   (uintptr_t)local_linker_stTEXT_KERN_p,   szTEXT,   szTEXTf);
	(void)dprintf(KSYST, "Section rodata:    addr = 0x%016"PRIXPTR", size = 0x%08"PRIX32" %5.2f [KBytes]\n",   (uintptr_t)local_linker_stRODATA_KERN_p, szRODATA, szRODATAf);
	(void)dprintf(KSYST, "Section data:      addr = 0x%016"PRIXPTR", size = 0x%08"PRIX32" %5.2f [KBytes]\n",   (uintptr_t)local_linker_stDATA_KERN_p,   szDATA,   szDATAf);
	(void)dprintf(KSYST, "Section bss:       addr = 0x%016"PRIXPTR", size = 0x%08"PRIX32" %5.2f [KBytes]\n\n", (uintptr_t)local_linker_stBSS_KERN_p,    szBSS,    szBSSf);
	return (EXIT_OS_SUCCESS_CLI);
}
