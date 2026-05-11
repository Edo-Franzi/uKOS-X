/*
; crt0_b.
; =======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		crt0 for the uKOS-X system with an initial bootstrap.
;			Privileged only support
;
;                       CODE
; linker_stTEXT			+-----------------+
;						|                 |
;						| .isr_vector     |
;						| .text           |
;						| .rodata         |
; linker_enRODATA		|                 |                   DATA
;						+-----------------+ ........... +-----------------+ linker_stDATA
; linker_stINDATA		|                 |				|                 |
;						| .data           |				| .data           |
;						|                 |				|                 | linker_enDATA
;						+-----------------+ ........... +-----------------+
; linker_stSignature	|				  |				|                 | linker_stBSS
;						+-----------------+				| .bss            |
;														| COMMON          |
;														|                 | linker_enBSS
;														+-----------------+
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

#include	"tests.h"
#include	"linker.h"
#include	<string.h>

// Runtime specific
// ================

		uint32_t	vCrt0_randomSeed;

		[[gnu::aligned(2048)]]
		uintptr_t	vVectors[KNB_EXCEPTIONS + KNB_INTERRUPTIONS];
extern	void		(* const g_pfnVectors_C0[])(void);

// Prototypes

extern	void	init_init(void);
extern	int		main(int argc, const char_t *argv[]);

/*
 * \brief crt0
 *
 * - Copy the initialised data from the CODE to the DATA region
 * - Initialise the BSS region
 * - Call the main
 *
 */
void	crt0(void) {
	uint32_t	*regionSeed, seed;
	intptr_t	nbWords;

// Initialise the LOW level (!!! No static variables !!!)

	init_init();

	#if (defined(CONFIG_MAN_SERIAL_S))
	cmns_init();
	#endif

// Before to initialise the system RAM, we use its random content
// @ the power-on for generating a random seed usable for the software
// Random Number Generators
//
// seed = seed[k - 1] + memory[k]

	regionSeed = (uint32_t *)linker_stPrgmData;
	nbWords    = (intptr_t)(((uintptr_t)linker_lnPrgmData) / 4u);
	seed       = 0u;
	while (nbWords-- > 0u) {
		seed += *regionSeed;
		regionSeed++;
	}

// Copy the initialised data from the CODE region to the DATA one
// Initialise the BSS region

	memcpy(linker_stDATA, linker_stINDATA, (size_t)((uintptr_t)linker_enDATA - (uintptr_t)linker_stDATA));
	memset(linker_stBSS,  0x00u,		   (size_t)((uintptr_t)linker_enBSS  - (uintptr_t)linker_stBSS));

// Initialise the Heap regions

	memset(linker_stHeap, 0x00u, (size_t)linker_lnHeap);

// Relocate the vectors (VTOR)

	memcpy(&vVectors[0], &g_pfnVectors_C0[0], (size_t)((KNB_EXCEPTIONS + KNB_INTERRUPTIONS) * sizeof(uintptr_t)));

	REG(SCB)->VTOR = (uint32_t)&vVectors[0];
	INST_SYNC_BARRIER;

	vCrt0_randomSeed = seed;

	main(0u, nullptr);
}
