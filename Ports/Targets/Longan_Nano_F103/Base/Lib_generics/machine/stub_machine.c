/*
; stub_machine.
; =============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the "machine" manager module.
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

/*
 * \brief stub_machine_restart
 *
 * - Disable all the system interruption
 * - Restart
 *
 */
int32_t	stub_machine_restart(void) {

// Stop all the interruptions and restart

	INTERRUPTION_OFF;
	while (true) { ; }

	return (KERR_MACHINE_NOERR);
}

/*
 * \brief stub_machine_readPC
 *
 * - Return the PC of the selected process
 *
 */
void	stub_machine_readPC(const uintptr_t *stackProcess, uintptr_t *pc) {
	uint8_t		pcOffset = 0u;

// uKOS-X stack frame:
//
//	mepc							-> pcOffset += 1
//	mcause							-> pcOffset += 1
//	mstatus							-> pcOffset += 1
//	ECLIC-mth						-> pcOffset += 1
//	t6..t3							-> pcOffset += ((6 - 3) + 1)
//	s11..s2							-> pcOffset += ((11 - 2) + 1)
//	a6..a0							-> pcOffset += ((6 - 0) + 1)
//	s1..s0							-> pcOffset += ((1 - 0) + 1)
//	tp2..tp0						-> pcOffset += ((2 - 0) + 1)
//	tp								-> pcOffset += 1
//	gp								-> pcOffset += 1
//	ra								-> pcOffset += 1
//	x0 (void)						-> pcOffset  = 0

//               x0   ra   gp   tp     tp2..tp0        s1..s0         a6..a0         s11..s2        t6..t3      ECLIC  mstatus   mcause     mepc
//               --   --   --   --    ----------     ----------     ----------     -----------     ----------   -----  -------   ------     ----
	pcOffset +=  +1u  +1u  +1u  +1u  +((2u-0u)+1u)  +((1u-0u)+1u)  +((6u-0u)+1u)  +((11u-2u)+1u)  +((6u-3u)+1u)  +1u     +1u       +1u      +1u;

	*pc = (stackProcess[pcOffset]);
}

/*
 * \brief stub_machine_readFunctionName
 *
 * - Return the function name that belong to a given PC
 *
 */
void	stub_machine_readFunctionName(const uintptr_t pc, const char_t **function) {

	UNUSED(pc);

	*function = NULL;
}
