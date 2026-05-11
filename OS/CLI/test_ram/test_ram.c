/*
; test_ram.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Minimal test of the RAM (hardware).
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

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"test_ram     Minimal test of the RAM (hardware).       (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Minimal test of the hardware\n"
									"============================\n\n"

									"This tool tests the following hardware parts:\n"
									"- Leds.\n"
									"- External memory.\n\n"

									"Input format:  test_ram {numberOfTests}\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Test_ram,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_TEST_RAM,								// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

enum {
		KERR_NOT = 0u,
		KERR_PRE,
		KERR_008,
		KERR_016,
		KERR_032
};

#define	KSTART		0u
#define	KEND		((uintptr_t)linker_lnEXRAM)

// Prototypes

static	void	local_display(int32_t error, void *add, uint32_t expe, uint32_t read);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
			char_t		*dummy;
			uint32_t	add, nb32Dots;
			uint8_t		led, pattern_08, expe_08, read_08, *memory_08;
			uint16_t	pattern_16, expe_16, read_16, *memory_16;
			uint32_t	pattern_32, expe_32, read_32, *memory_32;
			int32_t		tests, nbTests;
	const	char_t		*dot;

	(void)dprintf(KSYST, "System tests.\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// test 1000

	if (argc == 2u) {
		nbTests = (int32_t)strtoul(argv[1], &dummy, 10u);

// Test 1: LEDs
// ------------

		(void)dprintf(KSYST, "Test LEDs\n\n");

		#if (KNB_LED > 0)
		for (led = 0u; led < KNB_LED; led++) { led_off(led);						   }
		for (led = 0u; led < KNB_LED; led++) { led_on(led); kern_suspendProcess(100u); }
		for (led = 0u; led < KNB_LED; led++) { led_off(led);						   }
		#endif

// Test 2: Memory 8-bits
// ---------------------

// Test a: fill the memory with (uint8_t)0xAA - (uint8_t)0x55 and verify

		memory_08 = ALIGNED_PTR(uint8_t, linker_stEXRAM);

		(void)dprintf(KSYST, "8-bits:    Test Memory: fill 0xAA - 0x55\n");
		nb32Dots = 32u;
		for (tests = 0u; tests < nbTests; tests++) {
			nb32Dots--;
			dot      = (nb32Dots > 0u) ? (".")      : (".\n");
			nb32Dots = (nb32Dots > 0u) ? (nb32Dots) : (32u);
			(void)dprintf(KSYST, "%s", dot);

			for (add = KSTART; add < (KEND / 1u); add++) {
				*(memory_08 + add) = 0xAAu;
			}

			for (add = KSTART; add < (KEND / 1u); add++) {
				if (*(memory_08 + add) != 0xAAu) {
					expe_08 = 0xAAu;
					read_08 = *(memory_08 + add);
					local_display(KERR_008, (memory_08 + add), (uint32_t)expe_08, (uint32_t)read_08);
					return (EXIT_OS_FAILURE);
				}

			}

			for (add = KSTART; add < (KEND / 1u); add++) {
				*(memory_08 + add) = 0x55u;
			}

			for (add = KSTART; add < (KEND / 1u); add++) {
				if (*(memory_08 + add) != 0x55u) {
					expe_08 = 0x55u;
					read_08 = *(memory_08 + add);
					local_display(KERR_008, (memory_08 + add), (uint32_t)expe_08, (uint32_t)read_08);
					return (EXIT_OS_FAILURE);
				}

			}
		}
		dot = (nb32Dots == 32u) ? ("\n") : ("\n\n");
		(void)dprintf(KSYST, "%s", dot);

// Test b: circular; fill the memory with an incremental pattern and verify

		(void)dprintf(KSYST, "8-bits:    Test Memory: fill with an incremental pattern\n");
		nb32Dots = 32u;
		for (tests = 0u; tests < nbTests; tests++) {
			nb32Dots--;
			dot      = (nb32Dots > 0u) ? (".")      : (".\n");
			nb32Dots = (nb32Dots > 0u) ? (nb32Dots) : (32u);
			(void)dprintf(KSYST, "%s", dot);

			pattern_08 = 0u;
			for (add = KSTART; add < (KEND / 1u); add++) {
				*(memory_08 + add) = pattern_08;
				pattern_08++;
			}

			pattern_08 = 0u;
			for (add = KSTART; add < (KEND / 1u); add++) {
				if (*(memory_08 + add) != pattern_08) {
					expe_08 = pattern_08;
					read_08 = *(memory_08 + add);
					local_display(KERR_008, (memory_08 + add), (uint32_t)expe_08, (uint32_t)read_08);
					return (EXIT_OS_FAILURE);
				}

				pattern_08++;
			}
		}
		dot = (nb32Dots == 32u) ? ("\n") : ("\n\n");
		(void)dprintf(KSYST, "%s", dot);

// Test 3: Memory 16-bits
// ----------------------

// Test a: fill the memory with (uint8_t)0xAA55 - (uint8_t)0x55AA and verify

		memory_16 = ALIGNED_PTR(uint16_t, linker_stEXRAM);

		(void)dprintf(KSYST, "16-bits:   Test Memory: fill 0xAA55 - 0x55AA\n");
		nb32Dots = 32u;
		for (tests = 0u; tests < nbTests; tests++) {
			nb32Dots--;
			dot      = (nb32Dots > 0u) ? (".")      : (".\n");
			nb32Dots = (nb32Dots > 0u) ? (nb32Dots) : (32u);
			(void)dprintf(KSYST, "%s", dot);

			for (add = KSTART; add < (KEND / 2u); add++) {
				*(memory_16 + add) = 0xAA55u;
			}

			for (add = KSTART; add < (KEND / 2u); add++) {
				if (*(memory_16 + add) != 0xAA55u) {
					expe_16 = 0xAA55u;
					read_16 = *(memory_16 + add);
					local_display(KERR_016, (memory_16 + add), (uint32_t)expe_16, (uint32_t)read_16);
					return (EXIT_OS_FAILURE);
				}

			}

			for (add = KSTART; add < (KEND / 2u); add++) {
				*(memory_16 + add) = 0x55AAu;
			}

			for (add = KSTART; add < (KEND / 2u); add++) {
				if (*(memory_16 + add) != 0x55AAu) {
					expe_16 = 0x55AAu;
					read_16 = *(memory_16 + add);
					local_display(KERR_016, (memory_16 + add), (uint32_t)expe_16, (uint32_t)read_16);
					return (EXIT_OS_FAILURE);
				}

			}
		}
		dot = (nb32Dots == 32u) ? ("\n") : ("\n\n");
		(void)dprintf(KSYST, "%s", dot);

// Test b: circular; fill the memory with an incremental pattern and verify

		(void)dprintf(KSYST, "16-bits:   Test Memory: fill with an incremental pattern\n");
		nb32Dots = 32u;
		for (tests = 0u; tests < nbTests; tests++) {
			nb32Dots--;
			dot      = (nb32Dots > 0u) ? (".")      : (".\n");
			nb32Dots = (nb32Dots > 0u) ? (nb32Dots) : (32u);
			(void)dprintf(KSYST, "%s", dot);

			pattern_16 = 0;
			for (add = KSTART; add < (KEND / 2u); add++) {
				*(memory_16 + add) = pattern_16;
				pattern_16++;
			}

			pattern_16 = 0u;
			for (add = KSTART; add < (KEND / 2u); add++) {
				if (*(memory_16 + add) != pattern_16) {
					expe_16 = pattern_16;
					read_16 = *(memory_16 + add);
					local_display(KERR_016, (memory_16 + add), (uint32_t)expe_16, (uint32_t)read_16);
					return (EXIT_OS_FAILURE);
				}

				pattern_16++;
			}
		}
		dot = (nb32Dots == 32u) ? ("\n") : ("\n\n");
		(void)dprintf(KSYST, "%s", dot);

// Test 4: Memory 32-bits
// ----------------------

// Test a: fill the memory with (uint8_t)0xAA55AA55 - (uint8_t)0x55AA55AA and verify

		memory_32 = ALIGNED_PTR(uint32_t, linker_stEXRAM);

		(void)dprintf(KSYST, "32-bits:   Test Memory: fill 0xAA55AA55 - 0x55AA55AA\n");
		nb32Dots = 32u;
		for (tests = 0u; tests < nbTests; tests++) {
			nb32Dots--;
			dot      = (nb32Dots > 0u) ? (".")      : (".\n");
			nb32Dots = (nb32Dots > 0u) ? (nb32Dots) : (32u);
			(void)dprintf(KSYST, "%s", dot);

			for (add = KSTART; add < (KEND / 4u); add++) {
				 *(memory_32 + add) = 0xAA55AA55u;
			}

			for (add = KSTART; add < (KEND / 4u); add++) {
				if (*(memory_32 + add) != 0xAA55AA55u)	{
					expe_32 = 0xAA55AA55u;
					read_32 = *(memory_32 + add);
					local_display(KERR_032, (memory_32 + add), expe_32, read_32);
					return (EXIT_OS_FAILURE);
				}

			}

			for (add = KSTART; add < (KEND / 4u); add++) {
				*(memory_32 + add) = 0x55AA55AAu;
			}

			for (add = KSTART; add < (KEND / 4u); add++) {
				if (*(memory_32 + add) != 0x55AA55AAu)	{
					expe_32 = 0x55AA55AAu;
					read_32 = *(memory_32 + add);
					local_display(KERR_032, (memory_32 + add), expe_32, read_32);
					return (EXIT_OS_FAILURE);
				}

			}
		}
		dot = (nb32Dots == 32u) ? ("\n") : ("\n\n");
		(void)dprintf(KSYST, "%s", dot);

// Test b: circular; fill the memory with an incremental pattern and verify

		(void)dprintf(KSYST, "32-bits:   Test Memory: fill with an incremental pattern\n");
		nb32Dots = 32u;
		for (tests = 0u; tests < nbTests; tests++) {
			nb32Dots--;
			dot      = (nb32Dots > 0u) ? (".")      : (".\n");
			nb32Dots = (nb32Dots > 0u) ? (nb32Dots) : (32u);
			(void)dprintf(KSYST, "%s", dot);

			pattern_32 = 0u;
			for (add = KSTART; add < (KEND / 4u); add++) {
				*(memory_32 + add) = pattern_32;
				pattern_32++;
			}

			pattern_32 = 0u;
			for (add = KSTART; add < (KEND / 4u); add++) {
				if (*(memory_32 + add) != pattern_32) {
					expe_32 = pattern_32;
					read_32 = *(memory_32 + add);
					local_display(KERR_032, (memory_32 + add), expe_32, read_32);
					return (EXIT_OS_FAILURE);
				}

				pattern_32++;
			}
		}
		dot = (nb32Dots == 32u) ? ("\n") : ("\n\n");
		(void)dprintf(KSYST, "%s", dot);

// Test 5: Memory retention
// ------------------------

// Test: retention: fill the memory with an incremental pattern waiting for 60-s and verify

		memory_08 = ALIGNED_PTR(uint8_t, linker_stEXRAM);

		(void)dprintf(KSYST, "Retention: Test Memory: fill with an incremental pattern, waiting for 60-s and verify\n");
		nb32Dots = 32u;
		for (tests = 0u; tests < nbTests; tests++) {
			nb32Dots--;
			dot      = (nb32Dots > 0u) ? (".")      : (".\n");
			nb32Dots = (nb32Dots > 0u) ? (nb32Dots) : (32u);
			(void)dprintf(KSYST, "%s", dot);

			pattern_08 = 0u;
			for (add = KSTART; add < (KEND / 1u); add++) {
				*(memory_08 + add) = pattern_08;
				pattern_08++;
			}

			kern_suspendProcess(60000u);

			pattern_08 = 0;
			for (add = KSTART; add < (KEND / 1); add++) {
				if (*(memory_08 + add) != pattern_08) {
					expe_08 = pattern_08;
					read_08 = *(memory_08 + add);
					local_display(KERR_008, (memory_08 + add), (uint32_t)expe_08, (uint32_t)read_08);
					return (EXIT_OS_FAILURE);
				}

				pattern_08++;
			}
		}
		dot = (nb32Dots == 32u) ? ("\n") : ("\n\n");
		(void)dprintf(KSYST, "%s", dot);

// Test passed

		local_display(KERR_NOT, nullptr, 0u, 0u);
		return (EXIT_OS_SUCCESS_CLI);
	}

// Protocol error

	local_display(KERR_PRE, nullptr, 0u, 0u);
	return (EXIT_OS_FAILURE);
}

// Local routines
// ==============

/*
 * \brief local_display
 *
 */
static	void	local_display(int32_t error, void *add, uint32_t expe, uint32_t read) {

	switch (error) {
		case KERR_NOT: { (void)dprintf(KSYST, "Test passed\n");																													break; }
		case KERR_PRE: { (void)dprintf(KSYST, "Protocol error.\n\n");																											break; }
		case KERR_008: { (void)dprintf(KSYST, "\nMemory error: address 0x%016"PRIXPTR", Data expected 0x%02"PRIX32", Data read 0x%02"PRIX32"\n\n", (uintptr_t)add, expe, read); break; }
		case KERR_016: { (void)dprintf(KSYST, "\nMemory error: address 0x%016"PRIXPTR", Data expected 0x%04"PRIX32", Data read 0x%04"PRIX32"\n\n", (uintptr_t)add, expe, read); break; }
		case KERR_032: { (void)dprintf(KSYST, "\nMemory error: address 0x%016"PRIXPTR", Data expected 0x%08"PRIX32", Data read 0x%08"PRIX32"\n\n", (uintptr_t)add, expe, read); break; }
		default:	   { (void)dprintf(KSYST, "\nHardware problem.\n\n");																										break; }
	}
}
