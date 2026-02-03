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
	SCB->AIRCR = SCB_AIRCR_VECTKEY_MASK | SCB_AIRCR_SYSRESETREQ;
	while (true) { ; }

	return (KERR_SYSTEM_NOERR);
}

/*
 * \brief stub_machine_readPC
 *
 * - Return the PC of the selected process
 *
 */
void	stub_machine_readPC(const uintptr_t *stackProcess, uintptr_t *pc) {
	uint8_t		pcOffset = 0u;
	uintptr_t	lr;

// uKOS-X stack frame:
//
//	xPSR
//	s15..s0
//	pc
//	lr (old)						-> pcOffset += 1
//	r12								-> pcOffset += 1
//	r3..r0							-> pcOffset += ((3 - 0) + 1)
//	r11..r4							-> pcOffset += ((11 - 4) + 1)
//	basepri							-> pcOffset += 1
//	s31..s16 (if FPU)				-> pcOffset += ((31 - 16) + 1)
//	lr (new)						-> pcOffset  = 0

	lr = stackProcess[0];

// If the FPU was used         			      s31 to s16
//										      -----------
	if ((lr & (1u<<4u)) == 0u) { pcOffset += ((31u-16u)+1u); }

//               lr (new) basepri       r11..r4         r3..r0      r12  lr (old)
//               -------- -------    -------------   -------------  ---  --------
	pcOffset +=      +1u    +1u      +((11u-4u)+1u)  +((3u-0u)+1u)  +1u    +1u;

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

	#if (!defined(__clang__))
			intptr_t	offset, nameLen;
	const	uintptr_t	*ptr;

	ptr = (const uintptr_t *)((pc + 2u) & (~0x3u));

	for (offset = 1; (offset < (intptr_t)(16u * 1024u)) && ((uintptr_t)&ptr[-offset] > (uintptr_t)0x0u); ++offset) {
		if ((ptr[-offset] & (uintptr_t)0xFFFFFF00u) == (uintptr_t)0xFF000000u) {
			nameLen = (intptr_t)(ptr[-offset] & (uintptr_t)0xFFu);
			*function = &((const char_t *)&ptr[-offset])[-nameLen];
			return;
		}
	}
	#endif

	*function = NULL;
}
