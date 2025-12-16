/*
; memory.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Give the memory information.
;
;   (c) 2025-20xx, Edo. Franzi
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
#include	"memo/private/private_memo.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"memory       Give the memory section information.      (c) EFr-2025";

#if (defined(PRIVILEGED_USER_S))
STRG_LOC_CONST(aStrHelp[])		  = "Give the memory information\n"
									"===========================\n\n"

									"This tool displays information about the memory\n"
									"section (DATA/CODE) of the system.\n\n"

									"Input format:  memory\n"
									"Output format: Section text:      address: 0x********, length: 0x********\n"
									"               Section rodata     address: 0x********, length: 0x********\n"
									"               Section data_p:    address: 0x********, length: 0x********\n"
									"               Section data_u:    address: 0x********, length: 0x********\n"
									"               section bss_p:     address: 0x********, length: 0x********\n"
									"               section bss_u:     address: 0x********, length: 0x********\n\n"

									"               heap:              address: 0x********, used: x.y%\nn"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";


#else
STRG_LOC_CONST(aStrHelp[])		  = "Give the memory information\n"
									"===========================\n\n"

									"This tool displays information about the memory\n"
									"section (DATA/CODE) of the system.\n\n"

									"Input format:  memory\n"
									"Output format: Section text:      address: 0x********, length: 0x********\n"
									"               Section rodata:    address: 0x********, length: 0x********\n"
									"               Section data:      address: 0x********, length: 0x********\n"
									"               section bss:       address: 0x********, length: 0x********\n\n"

									"               heap:              address: 0x********, used: x.y%\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

#endif

// Prototypes

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	void		local_displayHeap(uint8_t *stHeap, uint32_t blocks, uint32_t used, intptr_t heapSize);

MODULE(
	Memory,										// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_MEMORY,								// Module identifier (defined in the module.h)
	NULL,										// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,										// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

extern	spinlock_t		vMemo;

#if (KNB_CORES == 1)
size_t	size_first		= (size_t)linker_sizeStackFirst_C0;
size_t	size_system		= (size_t)linker_sizeStackSystem_C0;

#elif (KNB_CORES == 2)
size_t	size_first_C0	= (size_t)linker_sizeStackFirst_C0;
size_t	size_system_C0	= (size_t)linker_sizeStackSystem_C0;
size_t	size_first_C1	= (size_t)linker_sizeStackFirst_C1;
size_t	size_system_C1	= (size_t)linker_sizeStackSystem_C1;

#else
#error	"*** The number of cores (KNB_CORES) exceed 2"
#endif

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	uint32_t	usdMemory, nbBlocks;
	intptr_t	length;

	UNUSED(argc);
	UNUSED(argv);

	(void)dprintf(KSYST, "Memory information.\n");

// This because of a gcc bug
// !!! Never use this
//     ... if ((int32_t)linker_lnHeapI0 > 0)
//
//     but use this
//     ... int32_t var
//     ... var = (int32_t)linker_lnHeapI0
//     ... if (var > 0)

	length = (intptr_t)linker_lnHeap;

	kern_criticalSection(KENTER_CRITICAL);

	SPIN_LOCK(vMemo);
	usdMemory = vMemo_heapInfo.oUsdMemory;
	nbBlocks  = vMemo_heapInfo.oNbBlocks;
	SPIN_UNLOCK(vMemo);

	kern_criticalSection(KEXIT_CRITICAL);

	#if (defined(PRIVILEGED_USER_S))
	uint32_t	usedPrgmCode, usedPrgmData_p, usedPrgmData_u;
	float64_t	usedPrgmCodef, usedPrgmData_pf, usedPrgmData_uf;

	usedPrgmCode    = (uint32_t)((uintptr_t)linker_enTEXT   - (uintptr_t)linker_stTEXT)		\
					+ (uint32_t)((uintptr_t)linker_enRODATA - (uintptr_t)linker_stRODATA)	\
					+ (uint32_t)((uintptr_t)linker_enDATA_p - (uintptr_t)linker_stDATA_p)	\
					+ (uint32_t)((uintptr_t)linker_enDATA_u - (uintptr_t)linker_stDATA_u);

	usedPrgmData_p  = (uint32_t)((uintptr_t)linker_enDATA_p - (uintptr_t)linker_stDATA_p)	\
					+ (uint32_t)((uintptr_t)linker_enBSS_p  - (uintptr_t)linker_stBSS_p);

	usedPrgmData_u  = (uint32_t)((uintptr_t)linker_enDATA_u - (uintptr_t)linker_stDATA_u)	\
					+ (uint32_t)((uintptr_t)linker_enBSS_u  - (uintptr_t)linker_stBSS_u);

	usedPrgmCodef   = ((float64_t)usedPrgmCode   / (float64_t)(uintptr_t)linker_lnPrgmCode)   * 100.0;
	usedPrgmData_pf = ((float64_t)usedPrgmData_p / (float64_t)(uintptr_t)linker_lnPrgmData_p) * 100.0;
	usedPrgmData_uf = ((float64_t)usedPrgmData_u / (float64_t)(uintptr_t)linker_lnPrgmData_u) * 100.0;

	(void)dprintf(KSYST, "uKOS code:         addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes], used: %5.2f [%%]\n", (uintptr_t)linker_stPrgmCode,        (uintptr_t)linker_lnPrgmCode,   usedPrgmCodef);
	(void)dprintf(KSYST, "uKOS data_p:       addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes], used: %5.2f [%%]\n", (uintptr_t)linker_stPrgmData_p,      (uintptr_t)linker_lnPrgmData_p, usedPrgmData_pf);
	(void)dprintf(KSYST, "uKOS data_u:       addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes], used: %5.2f [%%]\n", (uintptr_t)linker_stPrgmData_u,      (uintptr_t)linker_lnPrgmData_u, usedPrgmData_uf);

	#else
	uint32_t	usedPrgmCode, usedPrgmData;
	float64_t	usedPrgmCodef, usedPrgmDataf;

	usedPrgmCode  = (uint32_t)((uintptr_t)linker_enTEXT   - (uintptr_t)linker_stTEXT)		\
				  + (uint32_t)((uintptr_t)linker_enRODATA - (uintptr_t)linker_stRODATA)		\
				  + (uint32_t)((uintptr_t)linker_enDATA   - (uintptr_t)linker_stDATA);

	usedPrgmData  = (uint32_t)((uintptr_t)linker_enDATA   - (uintptr_t)linker_stDATA)		\
				  + (uint32_t)((uintptr_t)linker_enBSS    - (uintptr_t)linker_stBSS);

	usedPrgmCodef = ((float64_t)usedPrgmCode / (float64_t)((uintptr_t)linker_lnPrgmCode)) * 100.0;
	usedPrgmDataf = ((float64_t)usedPrgmData / (float64_t)((uintptr_t)linker_lnPrgmData)) * 100.0;

	(void)dprintf(KSYST, "uKOS code:         addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes], used: %5.2f [%%]\n", (uintptr_t)linker_stPrgmCode, (uintptr_t)linker_lnPrgmCode, usedPrgmCodef);
	(void)dprintf(KSYST, "uKOS data:         addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes], used: %5.2f [%%]\n", (uintptr_t)linker_stPrgmData, (uintptr_t)linker_lnPrgmData, usedPrgmDataf);
	#endif

	#if (KNB_CORES == 1)
	(void)dprintf(KSYST, "Stack first:       addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes]\n",	  (uintptr_t)linker_lowStackFirst_C0,  size_first);
	(void)dprintf(KSYST, "Stack system:      addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes]\n\n", (uintptr_t)linker_lowStackSystem_C0, size_system);

	#elif (KNB_CORES == 2)
	(void)dprintf(KSYST, "C0 Stack first:    addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes]\n",	  (uintptr_t)linker_lowStackFirst_C0,  size_first_C0);
	(void)dprintf(KSYST, "C0 Stack system:   addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes]\n",	  (uintptr_t)linker_lowStackSystem_C0, size_system_C0);
	(void)dprintf(KSYST, "C1 Stack first:    addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes]\n",	  (uintptr_t)linker_lowStackFirst_C1,  size_first_C1);
	(void)dprintf(KSYST, "C1 Stack system:   addr = 0x%016"PRIXPTR", size = 0x%016"PRIXPTR" [Bytes]\n\n", (uintptr_t)linker_lowStackSystem_C1, size_system_C1);

	#else
	#error	"*** The number of cores (KNB_CORES) exceed 4"
	#endif

	#if (defined(PRIVILEGED_USER_S))
	(void)dprintf(KSYST, "Section text:      addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stTEXT,	  ((uintptr_t)linker_enTEXT   - (uintptr_t)linker_stTEXT));
	(void)dprintf(KSYST, "Section rodata:    addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stRODATA, ((uintptr_t)linker_enRODATA - (uintptr_t)linker_stRODATA));
	(void)dprintf(KSYST, "Section data_p:    addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stDATA_p, ((uintptr_t)linker_enDATA_p - (uintptr_t)linker_stDATA_p));
	(void)dprintf(KSYST, "Section data_u:    addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stDATA_u, ((uintptr_t)linker_enDATA_u - (uintptr_t)linker_stDATA_u));
	(void)dprintf(KSYST, "Section bss_p:     addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stBSS_p,  ((uintptr_t)linker_enBSS_p  - (uintptr_t)linker_stBSS_p));
	(void)dprintf(KSYST, "Section bss_u:     addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n\n", (uintptr_t)linker_stBSS_u,  ((uintptr_t)linker_enBSS_u  - (uintptr_t)linker_stBSS_u));

	#else
	(void)dprintf(KSYST, "Section text:      addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stTEXT,	  ((uintptr_t)linker_enTEXT   - (uintptr_t)linker_stTEXT));
	(void)dprintf(KSYST, "Section rodata:    addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stRODATA, ((uintptr_t)linker_enRODATA - (uintptr_t)linker_stRODATA));
	(void)dprintf(KSYST, "Section data:      addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n",   (uintptr_t)linker_stDATA,	  ((uintptr_t)linker_enDATA   - (uintptr_t)linker_stDATA));
	(void)dprintf(KSYST, "Section bss:       addr = 0x%016"PRIXPTR", used = 0x%016"PRIXPTR" [Bytes]\n\n", (uintptr_t)linker_stBSS,	  ((uintptr_t)linker_enBSS    - (uintptr_t)linker_stBSS));
	#endif

	local_displayHeap(linker_stHeap, nbBlocks, usdMemory, length);
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_displayHeap
 *
 * - Display the memory segment characteristics
 *
 */
static	void	local_displayHeap(uint8_t *stHeap, uint32_t blocks, uint32_t used, intptr_t heapSize) {

	(void)dprintf(KSYST, "Heap:              addr = 0x%016"PRIXPTR"\n", (uintptr_t)stHeap);

	(void)dprintf(KSYST, "                   total size                          %16"PRIdPTR" [Bytes]\n",   heapSize);
	(void)dprintf(KSYST, "                   total used memory:                  %16"PRIu32" [Bytes]\n",	used);
	(void)dprintf(KSYST, "                   total used blocks:                  %16"PRIu32" [-]\n\n",		blocks);
}
