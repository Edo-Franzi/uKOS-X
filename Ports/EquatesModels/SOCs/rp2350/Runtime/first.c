/*
; first.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Vectors for the uKOS-X system (first).
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

#if (defined(__riscv))
#include	"first.h"

#include	<stdint.h>

#include	"core.h"
#include	"soc_reg.h"
#include	"macros_soc.h"
#include	"macros_core.h"
#include	"macros_core_stackFrame.h"	// IWYU pragma: keep (for INTERRUPTION_IN INTERRUPTION_OUT)

extern	void	(*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
extern	void	(*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
extern	bool	vExce_isException[KNB_CORES];

// File-scoped suppression: every external symbol below is referenced either
// from the boot vector table, from inline asm in this TU, or via a weak
// override pattern in another TU (main_C1). clang-tidy cannot see those
// references, so misc-use-internal-linkage produces false positives here.
// NOLINTBEGIN(misc-use-internal-linkage)

// Ecall context-switch support
// These are used by the trap handler to pass the message and save/restore sp.
// Per-hart arrays: each core stores its own ecall state, indexed by mhartid,
// so concurrent ecalls from the two cores cannot corrupt each other's frame.

volatile	uintptr_t	vSaveStack[KNB_CORES];
volatile	uint32_t	vMessage[KNB_CORES];

// Trap handling for RP2350 Hazard3 (RV32IMAC)
// Hazard3 has no PLIC: peripheral IRQs arrive as machine external interrupts
// (mcause = 11) and are demuxed via the Xh3irq custom CSRs (MEIEA, MEIPA,
// MEIFA, MEIPRA, MEINEXT). The trap handler reads MEINEXT to find the
// pending peripheral IRQ number and dispatches it through the indirection
// table vExce_indIntVectors[core][irq].

// Prototypes

/*
 * \brief Reset_C0_Handler
 *
 * This code is called directly by the reset handler for core 0
 * - Initialise the first stack
 * - call the crt0
 *
 */
[[gnu::naked, gnu::section(".isr_vector")]]
void	Reset_C0_Handler(void) {

// Initialise the RISC-V global pointer (required for small data access)

	__asm volatile (
		".option push								\n"
		".option norelax							\n"
		"la		gp,__global_pointer$				\n"
		".option pop								\n"
	);

// Install trap handler

	__asm volatile (
		"la		t0,first_handle_trap				\n"
		"csrw	mtvec,t0							\n"
	);

// Initialise the first stack

	__asm volatile ("la sp,linker_topStackFirst_C0");

// Continue with the crt0

	CALL_FNCT(crt0);
}

/*
 * \brief Reset_C1_Handler
 *
 * This code is called directly by the reset handler for core 1
 * - Initialise the global pointer (per-hart on RISC-V)
 * - Install the trap handler (mtvec is a per-hart CSR)
 * - Initialise the first stack for core 1
 * - Jump to the core 1 entry point
 *
 * Core 1 must NOT call crt0: BSS clearing, .data copy and ctors have
 * already been performed by core 0 and re-running them would clobber
 * state core 0 has set up before launching core 1.
 */
[[gnu::naked]]
void	Reset_C1_Handler(void) {

// Initialise the RISC-V global pointer (per-hart)

	__asm volatile (
		".option push								\n"
		".option norelax							\n"
		"la		gp,__global_pointer$				\n"
		".option pop								\n"
	);

// Install trap handler

	__asm volatile (
		"la		t0,first_handle_trap				\n"
		"csrw	mtvec,t0							\n"
	);

// Initialise the first stack for core 1

	__asm volatile ("la sp,linker_topStackFirst_C1");

// Jump to the core 1 entry point (NOT crt0)

	CALL_FNCT(main_C1);
}

/*
 * \brief main_C1
 *
 * Weak default core 1 entry point. Tests that bring core 1 online
 * provide their own strong definition; for single-core tests core 1
 * is never released by the bootrom, but the symbol must still resolve
 * at link time.
 */
[[gnu::weak]]
void	main_C1(void) {
	while (true) {
		__asm volatile ("wfi");
	}
}

// RISC-V exception handlers (per core)
// These are dispatched through the trap handler based on mcause

// RP2350 Hazard3 has no S-mode, so mcause = 9 (ECallSupervisor) is never raised.
// Page-fault causes (12, 13, 15) require an MMU which Hazard3 lacks; they are
// kept in the table for spec completeness but cannot fire on this SoC.

EXCEPTION_SPECIFIC_HANDLER(InstructionAddressMisaligned_C0)
EXCEPTION_SPECIFIC_HANDLER(InstructionAccessFault_C0)
EXCEPTION_SPECIFIC_HANDLER(IllegalInstruction_C0)
EXCEPTION_SPECIFIC_HANDLER(Breakpoint_C0)
EXCEPTION_SPECIFIC_HANDLER(LoadAddressMisaligned_C0)
EXCEPTION_SPECIFIC_HANDLER(LoadAccessFault_C0)
EXCEPTION_SPECIFIC_HANDLER(StoreAddressMisaligned_C0)
EXCEPTION_SPECIFIC_HANDLER(StoreAccessFault_C0)
EXCEPTION_SPECIFIC_HANDLER(ECallUser_C0)
EXCEPTION_SPECIFIC_HANDLER(ECallMachine_C0)
EXCEPTION_SPECIFIC_HANDLER(InstructionPageFault_C0)
EXCEPTION_SPECIFIC_HANDLER(LoadPageFault_C0)
EXCEPTION_SPECIFIC_HANDLER(StorePageFault_C0)

EXCEPTION_SPECIFIC_HANDLER(InstructionAddressMisaligned_C1)
EXCEPTION_SPECIFIC_HANDLER(InstructionAccessFault_C1)
EXCEPTION_SPECIFIC_HANDLER(IllegalInstruction_C1)
EXCEPTION_SPECIFIC_HANDLER(Breakpoint_C1)
EXCEPTION_SPECIFIC_HANDLER(LoadAddressMisaligned_C1)
EXCEPTION_SPECIFIC_HANDLER(LoadAccessFault_C1)
EXCEPTION_SPECIFIC_HANDLER(StoreAddressMisaligned_C1)
EXCEPTION_SPECIFIC_HANDLER(StoreAccessFault_C1)
EXCEPTION_SPECIFIC_HANDLER(ECallUser_C1)
EXCEPTION_SPECIFIC_HANDLER(ECallMachine_C1)
EXCEPTION_SPECIFIC_HANDLER(InstructionPageFault_C1)
EXCEPTION_SPECIFIC_HANDLER(LoadPageFault_C1)
EXCEPTION_SPECIFIC_HANDLER(StorePageFault_C1)

// RISC-V machine-mode timer and software interrupts (per core)

EXCEPTION_SPECIFIC_HANDLER(MSIP_C0)		// Machine Software Interrupt
EXCEPTION_SPECIFIC_HANDLER(MTIP_C0)		// Machine Timer Interrupt
EXCEPTION_SPECIFIC_HANDLER(MSIP_C1)
EXCEPTION_SPECIFIC_HANDLER(MTIP_C1)

/*
 * \brief first_handle_trap
 *
 * - Main RISC-V trap entry point
 * - Dispatches to exception or interrupt handlers based on mcause
 *
 * This function is called from trapEntry in vectors_rv.S
 * It reads mcause to determine the cause and dispatches to the appropriate handler
 */
[[gnu::naked, gnu::aligned(4)]]
void	first_handle_trap(void) {

// Save context (basic registers)

	__asm volatile (
		"	addi	sp,sp,-16*4						\n"			// Allocate stack space
		"	sw		ra,0*4(sp)						\n"			// Save return address
		"	sw		t0,1*4(sp)						\n"			// Save t0
		"	sw		t1,2*4(sp)						\n"			// Save t1
		"	sw		t2,3*4(sp)						\n"			// Save t2
		"	sw		a0,4*4(sp)						\n"			// Save a0
		"	sw		a1,5*4(sp)						\n"			// Save a1
		"	sw		a2,6*4(sp)						\n"			// Save a2
		"	sw		a3,7*4(sp)						\n"			// Save a3
		"	sw		a4,8*4(sp)						\n"			// Save a4
		"	sw		a5,9*4(sp)						\n"			// Save a5
		"	sw		a6,10*4(sp)						\n"			// Save a6
		"	sw		a7,11*4(sp)						\n"			// Save a7
		"	csrr	t0,mcause						\n"			// Read mcause
		"	sw		t0,12*4(sp)						\n"			// Save mcause
		"	csrr	t1,mepc							\n"			// Read mepc
		"	sw		t1,13*4(sp)						\n"			// Save mepc

// Determine exception vs interrupt

		"	bltz	t0,1f							\n"			// If MSB set, it's an interrupt

// Exception handling

		"	andi	t0,t0,0x1F						\n"			// Extract exception code (bits 0-4)
		"	li		t1,11							\n"			// Ecall from M-mode?
		"	beq		t0,t1,3f						\n"			// Yes, branch to ecall path
		"	call	first_dispatch_exception		\n"			// Call exception dispatcher
		"	j		2f								\n"

// Ecall context-switch path – use full 35-word KERN_SAVE_FRAME layout so
// KERN_NEW_FRAME (and KERN_PREPARE_FRAME for new processes) restores correctly

		"3:											\n"			//

// t0/t1 were overwritten by the mcause/mepc reads above; recover
// the original register values from the partial 16-word frame

		"	lw		t0,1*4(sp)						\n"			//
		"	lw		t1,2*4(sp)						\n"			//

// Undo the partial 16-word save – back to the original trap-entry sp

		"	addi	sp,sp,16*4						\n"			//

// Build the full 35-word frame (matches KERN_SAVE_FRAME / KERN_PREPARE_FRAME)

		"	addi	sp,sp,-(35*4)					\n"			//
		"	sw		ra,34*4(sp)						\n"			//
		"	sw		t0,33*4(sp)						\n"			//
		"	sw		t1,32*4(sp)						\n"			//
		"	sw		t2,31*4(sp)						\n"			//
		"	sw		s0,30*4(sp)						\n"			//
		"	sw		a0,29*4(sp)						\n"			//
		"	sw		a1,28*4(sp)						\n"			//
		"	sw		a2,27*4(sp)						\n"			//
		"	sw		a3,26*4(sp)						\n"			//
		"	sw		a4,25*4(sp)						\n"			//
		"	sw		a5,24*4(sp)						\n"			//
		"	sw		a6,23*4(sp)						\n"			//
		"	sw		a7,22*4(sp)						\n"			//
		"	sw		t3,21*4(sp)						\n"			//
		"	sw		t4,20*4(sp)						\n"			//
		"	sw		t5,19*4(sp)						\n"			//
		"	sw		t6,18*4(sp)						\n"			//
		"	sw		gp,16*4(sp)						\n"			//
		"	sw		tp,15*4(sp)						\n"			//
		"	sw		s1,14*4(sp)						\n"			//
		"	sw		s2,13*4(sp)						\n"			//
		"	sw		s3,12*4(sp)						\n"			//
		"	sw		s4,11*4(sp)						\n"			//
		"	sw		s5,10*4(sp)						\n"			//
		"	sw		s6,9*4(sp)						\n"			//
		"	sw		s7,8*4(sp)						\n"			//
		"	sw		s8,7*4(sp)						\n"			//
		"	sw		s9,6*4(sp)						\n"			//
		"	sw		s10,5*4(sp)						\n"			//
		"	sw		s11,4*4(sp)						\n"			//
		"	csrr	t0,mstatus						\n"			//
		"	sw		t0,2*4(sp)						\n"			//
		"	csrr	t0,mcause						\n"			//
		"	sw		t0,1*4(sp)						\n"			//
		"	csrr	t0,mepc							\n"			//
		"	addi	t0,t0,4							\n"			//
		"	sw		t0,0*4(sp)						\n"			//
		"	csrw	mepc,t0							\n"			//

// Compute per-hart array offset (mhartid * 4) into t3.

		"	csrr	t3,mhartid						\n"			//
		"	slli	t3,t3,2							\n"			//

// a0 at entry held the kernel message (SET_MESSAGE: lw a0,0(sp); ecall).
// It is now saved at sp[29]; copy it to vMessage[hart] for first_dispatch_ecall

		"	lw		t1,29*4(sp)						\n"			//
		"	la		t2,vMessage						\n"			//
		"	add		t2,t2,t3						\n"			//
		"	sw		t1,0(t2)						\n"			//

// Save current process sp to vSaveStack[hart]

		"	la		t2,vSaveStack					\n"			//
		"	add		t2,t2,t3						\n"			//
		"	sw		sp,0(t2)						\n"			//

// Dispatch – kernel_message_C{0,1} may switch vSaveStack[hart] to a new frame

		"	call	first_dispatch_ecall			\n"			//

// Recompute per-hart offset (call may have used t3) and load new sp

		"	csrr	t3,mhartid						\n"			//
		"	slli	t3,t3,2							\n"			//
		"	la		t2,vSaveStack					\n"			//
		"	add		t2,t2,t3						\n"			//
		"	lw		sp,0(t2)						\n"			//

// Restore full context (inline KERN_NEW_FRAME)

		"	lw		t0,0*4(sp)						\n"			//
		"	csrw	mepc,t0							\n"			//
		"	lw		t0,2*4(sp)						\n"			//
		"	csrw	mstatus,t0						\n"			//
		"	lw		s11,4*4(sp)						\n"			//
		"	lw		s10,5*4(sp)						\n"			//
		"	lw		s9,6*4(sp)						\n"			//
		"	lw		s8,7*4(sp)						\n"			//
		"	lw		s7,8*4(sp)						\n"			//
		"	lw		s6,9*4(sp)						\n"			//
		"	lw		s5,10*4(sp)						\n"			//
		"	lw		s4,11*4(sp)						\n"			//
		"	lw		s3,12*4(sp)						\n"			//
		"	lw		s2,13*4(sp)						\n"			//
		"	lw		s1,14*4(sp)						\n"			//
		"	lw		tp,15*4(sp)						\n"			//

// KERN_PREPARE_FRAME stores 0x03030303 as gp fill – always reload the
// real global pointer so gp-relative accesses work in the new process

		"	.option push							\n"			//
		"	.option norelax							\n"			//
		"	la		gp,__global_pointer$			\n"			//
		"	.option pop								\n"			//

		"	lw		t6,18*4(sp)						\n"			//
		"	lw		t5,19*4(sp)						\n"			//
		"	lw		t4,20*4(sp)						\n"			//
		"	lw		t3,21*4(sp)						\n"			//
		"	lw		a7,22*4(sp)						\n"			//
		"	lw		a6,23*4(sp)						\n"			//
		"	lw		a5,24*4(sp)						\n"			//
		"	lw		a4,25*4(sp)						\n"			//
		"	lw		a3,26*4(sp)						\n"			//
		"	lw		a2,27*4(sp)						\n"			//
		"	lw		a1,28*4(sp)						\n"			//
		"	lw		a0,29*4(sp)						\n"			//
		"	lw		s0,30*4(sp)						\n"			//
		"	lw		t2,31*4(sp)						\n"			//
		"	lw		t1,32*4(sp)						\n"			//
		"	lw		t0,33*4(sp)						\n"			//
		"	lw		ra,34*4(sp)						\n"			//
		"	addi	sp,sp,(35*4)					\n"			//
		"	mret									\n"			//

// Interrupt handling

		"1:											\n"			//
		"	li		t1,0x7FFFFFFF					\n"			// Mask for interrupt number
		"	and		t0,t0,t1						\n"			// Extract interrupt number
		"	call	first_dispatch_interrupt		\n"			// Call interrupt dispatcher

// Restore context

		"2:											\n"			//
		"	lw		t1,13*4(sp)						\n"			// Restore mepc
		"	csrw	mepc,t1							\n"			//
		"	lw		a7,11*4(sp)						\n"			// Restore a7
		"	lw		a6,10*4(sp)						\n"			// Restore a6
		"	lw		a5,9*4(sp)						\n"			// Restore a5
		"	lw		a4,8*4(sp)						\n"			// Restore a4
		"	lw		a3,7*4(sp)						\n"			// Restore a3
		"	lw		a2,6*4(sp)						\n"			// Restore a2
		"	lw		a1,5*4(sp)						\n"			// Restore a1
		"	lw		a0,4*4(sp)						\n"			// Restore a0
		"	lw		t2,3*4(sp)						\n"			// Restore t2
		"	lw		t1,2*4(sp)						\n"			// Restore t1
		"	lw		t0,1*4(sp)						\n"			// Restore t0
		"	lw		ra,0*4(sp)						\n"			// Restore ra
		"	addi	sp,sp,16*4						\n"			// Deallocate stack space
		"	mret									\n"			// Return from trap
		:::
	);
}

/*
 * \brief first_dispatch_exception
 *
 * - Dispatches to exception handler based on exception code in t0
 */
void first_dispatch_exception(void) {
	uint32_t	core;
	uint32_t	exception;

	core = GET_RUNNING_CORE;

	__asm volatile ("mv %0,t0" : "=r"(exception));

	if (exception < KNB_EXCEPTIONS && vExce_indExcVectors[core][exception] != nullptr) {
		vExce_indExcVectors[core][exception]();
	}
}

/*
 * \brief first_dispatch_interrupt
 *
 * - Dispatches to interrupt handler based on interrupt number in t0
 * - For Machine External Interrupt (MEIP, code 11), reads the Hazard3
 *	 meinext CSR to determine the actual peripheral IRQ number
 */
void first_dispatch_interrupt(void) {
	uint32_t	core;
	uint32_t	interrupt;

	core = GET_RUNNING_CORE;

	__asm volatile ("mv %0,t0" : "=r"(interrupt));

	if (interrupt == 11u) {

// Machine External Interrupt (MEIP)
// Read meinext to get the pending peripheral IRQ number

		uint32_t	meinext = core_getNextExternalIRQ();
		if ((meinext & MEINEXT_NOIRQ) == 0u) {
			uint32_t	irqNum = (meinext & MEINEXT_IRQ_MASK) >> MEINEXT_IRQ_SHIFT;
			if (irqNum < KNB_INTERRUPTIONS && vExce_indIntVectors[core][irqNum] != nullptr) {
				vExce_indIntVectors[core][irqNum]();
			}
		}
	}
	else if (interrupt < KNB_INTERRUPTIONS && vExce_indIntVectors[core][interrupt] != nullptr) {
		vExce_indIntVectors[core][interrupt]();
	}
}

/*
 * \brief first_dispatch_ecall
 *
 * - Dispatches to the ecall exception handler (exception code 11)
 * - Called from the ecall path of first_handle_trap after saving
 *	 the full process context and setting vMessage/vSaveStack
 */
void first_dispatch_ecall(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	if (vExce_indExcVectors[core][11u] != nullptr) {
		vExce_indExcVectors[core][11u]();
	}
}

/*
 * \brief default_handler
 *
 * - Catch-all handler for unused vector slots (exceptions, MSI, MTI)
 * - Spins so the failure is visible under a debugger
 *
 */
[[gnu::interrupt("machine"), gnu::aligned(4), gnu::used]]
void	default_handler(void) {

	while (true) {
		NOP;
	}
}

[[gnu::interrupt("machine"), gnu::weak, gnu::alias("default_handler")]]
void	MTVEC_EXCEPTION_Handler_C0(void);

[[gnu::interrupt("machine"), gnu::weak, gnu::alias("default_handler")]]
void	MTVEC_MSI_Handler_C0(void);

[[gnu::interrupt("machine"), gnu::weak, gnu::alias("default_handler")]]
void	MTVEC_MTI_Handler_C0(void);

/*
 * \brief MTVEC_MEI_Handler_C0
 *
 * - Vectored-mode handler for the Machine External Interrupt (mcause = 11)
 * - Drains the Hazard3 meinext queue and dispatches each pending peripheral
 *	 IRQ through the project's vExce_indIntVectors table
 *
 */
[[gnu::interrupt("machine"), gnu::aligned(4), gnu::used]]
static	void	MTVEC_MEI_Handler_C0(void) {
	uint32_t	core;
	uint32_t	meinext;

	core	= GET_RUNNING_CORE;
	meinext = core_getNextExternalIRQ();

	while ((meinext & MEINEXT_NOIRQ) == 0u) {
		uint32_t	irqNum = (meinext & MEINEXT_IRQ_MASK) >> MEINEXT_IRQ_SHIFT;

		if ((irqNum < KNB_INTERRUPTIONS) && (vExce_indIntVectors[core][irqNum] != nullptr)) {
			vExce_indIntVectors[core][irqNum]();
		}
		meinext = core_getNextExternalIRQ();
	}
}

/*
 * \brief vector_table_C0
 *
 * - Hazard3 vectored-mode trap table (mtvec.MODE = 1)
 * - Must be aligned on 64 bytes (RP2350 Hazard3 requirement)
 * - One 4-byte slot per cause; .option norvc keeps the C extension from
 *	 compressing the j instructions to 2 bytes and corrupting the layout
 *
 *	 offset	 0 : synchronous exception
 *	 offset 12 : Machine Software Interrupt	  (cause 3)
 *	 offset 28 : Machine Timer Interrupt	  (cause 7)
 *	 offset 44 : Machine External Interrupt	  (cause 11)
 *
 */
[[gnu::naked, gnu::aligned(64), gnu::section(".isr_vector"), gnu::used]]
void	vector_table_C0(void) {
	__asm__ volatile (
		".option push								\n"			//
		".option norvc								\n"			//
		"j		MTVEC_EXCEPTION_Handler_C0			\n"			// 0 : exception
		".word	0									\n"			// 4
		".word	0									\n"			// 8
		"j		MTVEC_MSI_Handler_C0				\n"			// 12: MSI
		".word	0									\n"			// 16
		".word	0									\n"			// 20
		".word	0									\n"			// 24
		"j		MTVEC_MTI_Handler_C0				\n"			// 28: MTI
		".word	0									\n"			// 32
		".word	0									\n"			// 36
		".word	0									\n"			// 40
		"j		MTVEC_MEI_Handler_C0				\n"			// 44: MEI
		".option pop								\n"			//
	);
}

// NOLINTEND(misc-use-internal-linkage)

#else		// ARM
#include	"uKOS.h"
#include	"linker.h"
#include	"kern/private/private_temporal.h"

// Vector table: ...
// However rather than start at zero the vector table starts at address 0x00000004,
// the first four bytes are used to store the starting address of the stack pointer.

		void		Reset_C0_Handler(void);
extern	void		crt0(void);
extern	void		cmns_wait(uint32_t time);

[[gnu::used, gnu::section(".isr_vector")]]
const	uintptr_t	g_pfnVectors_C0[] = {

	(uintptr_t)linker_topStackSystem_C0,						// MSP Stack

// Cortex-M33 Processor Exceptions Numbers

	(uintptr_t)Reset_C0_Handler,								// Address: 0x0000_0004
	(uintptr_t)NonMaskableInt_C0_IRQHandler,					// Address: 0x0000_0008
	(uintptr_t)HardFault_C0_IRQHandler,							// Address: 0x0000_000C
	(uintptr_t)MemoryManagement_C0_IRQHandler,					// Address: 0x0000_0010
	(uintptr_t)BusFault_C0_IRQHandler,							// Address: 0x0000_0014
	(uintptr_t)UsageFault_C0_IRQHandler,						// Address: 0x0000_0018
	(uintptr_t)SecureFault_C0_IRQHandler,						// Address: 0x0000_001C
	(uintptr_t)0,												// Address: 0x0000_0020
	(uintptr_t)0,												// Address: 0x0000_0024
	(uintptr_t)0,												// Address: 0x0000_0028
	(uintptr_t)SVCall_C0_IRQHandler,							// Address: 0x0000_002C
	(uintptr_t)DebugMonitor_C0_IRQHandler,						// Address: 0x0000_0030
	(uintptr_t)0,												// Address: 0x0000_0034
	(uintptr_t)PendSV_C0_IRQHandler,							// Address: 0x0000_0038
	(uintptr_t)SysTick_C0_IRQHandler,							// Address: 0x0000_003C

// rp2350 specific Interrupt Numbers

	(uintptr_t)TIMER0_IRQ_0_C0_IRQHandler,						// Address: 0x0000_0040
	(uintptr_t)TIMER0_IRQ_1_C0_IRQHandler,						// Address: 0x0000_0044
	(uintptr_t)TIMER0_IRQ_2_C0_IRQHandler,						// Address: 0x0000_0048
	(uintptr_t)TIMER0_IRQ_3_C0_IRQHandler,						// Address: 0x0000_004C
	(uintptr_t)TIMER1_IRQ_0_C0_IRQHandler,						// Address: 0x0000_0050
	(uintptr_t)TIMER1_IRQ_1_C0_IRQHandler,						// Address: 0x0000_0054
	(uintptr_t)TIMER1_IRQ_2_C0_IRQHandler,						// Address: 0x0000_0058
	(uintptr_t)TIMER1_IRQ_3_C0_IRQHandler,						// Address: 0x0000_005C
	(uintptr_t)PWM_IRQ_WRAP_0_C0_IRQHandler,					// Address: 0x0000_0060
	(uintptr_t)PWM_IRQ_WRAP_1_C0_IRQHandler,					// Address: 0x0000_0064
	(uintptr_t)DMA_IRQ_0_C0_IRQHandler,							// Address: 0x0000_0068
	(uintptr_t)DMA_IRQ_1_C0_IRQHandler,							// Address: 0x0000_006C
	(uintptr_t)DMA_IRQ_2_C0_IRQHandler,							// Address: 0x0000_0070
	(uintptr_t)DMA_IRQ_3_C0_IRQHandler,							// Address: 0x0000_0074
	(uintptr_t)USBCTRL_IRQ_C0_IRQHandler,						// Address: 0x0000_0078
	(uintptr_t)PIO0_IRQ_0_C0_IRQHandler,						// Address: 0x0000_007C
	(uintptr_t)PIO0_IRQ_1_C0_IRQHandler,						// Address: 0x0000_0080
	(uintptr_t)PIO1_IRQ_0_C0_IRQHandler,						// Address: 0x0000_0084
	(uintptr_t)PIO1_IRQ_1_C0_IRQHandler,						// Address: 0x0000_0088
	(uintptr_t)PIO2_IRQ_0_C0_IRQHandler,						// Address: 0x0000_008C
	(uintptr_t)PIO2_IRQ_1_C0_IRQHandler,						// Address: 0x0000_0090
	(uintptr_t)IO_IRQ_BANK0_C0_IRQHandler,						// Address: 0x0000_0094
	(uintptr_t)IO_IRQ_BANK0_NS_C0_IRQHandler,					// Address: 0x0000_0098
	(uintptr_t)IO_IRQ_QSPI_C0_IRQHandler,						// Address: 0x0000_009C
	(uintptr_t)IO_IRQ_QSPI_NS_C0_IRQHandler,					// Address: 0x0000_00A0
	(uintptr_t)SIO_IRQ_FIFO_C0_IRQHandler,						// Address: 0x0000_00A4
	(uintptr_t)SIO_IRQ_BELL_C0_IRQHandler,						// Address: 0x0000_00A8
	(uintptr_t)SIO_IRQ_FIFO_NS_C0_IRQHandler,					// Address: 0x0000_00AC
	(uintptr_t)SIO_IRQ_BELL_NS_C0_IRQHandler,					// Address: 0x0000_00B0
	(uintptr_t)SIO_IRQ_MTIMECMP_C0_IRQHandler,					// Address: 0x0000_00B4
	(uintptr_t)CLOCKS_IRQ_C0_IRQHandler,						// Address: 0x0000_00B8
	(uintptr_t)SPI0_IRQ_C0_IRQHandler,							// Address: 0x0000_00BC
	(uintptr_t)SPI1_IRQ_C0_IRQHandler,							// Address: 0x0000_00C0
	(uintptr_t)UART0_IRQ_C0_IRQHandler,							// Address: 0x0000_00C4
	(uintptr_t)UART1_IRQ_C0_IRQHandler,							// Address: 0x0000_00C8
	(uintptr_t)ADC_IRQ_FIFO_C0_IRQHandler,						// Address: 0x0000_00CC
	(uintptr_t)I2C0_IRQ_C0_IRQHandler,							// Address: 0x0000_00D0
	(uintptr_t)I2C1_IRQ_C0_IRQHandler,							// Address: 0x0000_00D4
	(uintptr_t)OTP_IRQ_C0_IRQHandler,							// Address: 0x0000_00D8
	(uintptr_t)TRNG_IRQ_C0_IRQHandler,							// Address: 0x0000_00DC
	(uintptr_t)0,												// Address: 0x0000_00E0
	(uintptr_t)0,												// Address: 0x0000_00E4
	(uintptr_t)PLL_SYS_IRQ_C0_IRQHandler,						// Address: 0x0000_00E8
	(uintptr_t)PLL_USB_IRQ_C0_IRQHandler,						// Address: 0x0000_00EC
	(uintptr_t)POWMAN_IRQ_POW_C0_IRQHandler,					// Address: 0x0000_00F0
	(uintptr_t)POWMAN_IRQ_TIMER_C0_IRQHandler					// Address: 0x0000_00F4
};

EXCEPTION_SPECIFIC_HANDLER(NonMaskableInt_C0)
EXCEPTION_SPECIFIC_HANDLER(HardFault_C0)
EXCEPTION_SPECIFIC_HANDLER(MemoryManagement_C0)
EXCEPTION_SPECIFIC_HANDLER(BusFault_C0)
EXCEPTION_SPECIFIC_HANDLER(UsageFault_C0)
EXCEPTION_SPECIFIC_HANDLER(SVCall_C0)
EXCEPTION_SPECIFIC_HANDLER(SecureFault_C0)
EXCEPTION_SPECIFIC_HANDLER(DebugMonitor_C0)
EXCEPTION_SPECIFIC_HANDLER(PendSV_C0)
EXCEPTION_SPECIFIC_HANDLER(SysTick_C0)

// cppcheck-suppress-end premium-unreadVariable

[[gnu::used, gnu::aligned(512)]]
const	uintptr_t	g_pfnVectors_C1[] = {

	(uintptr_t)linker_topStackSystem_C1,						// MSP Stack

// Cortex-M33 Processor Exceptions Numbers

	(uintptr_t)0,												// Address: 0x0000_0004
	(uintptr_t)NonMaskableInt_C1_IRQHandler,					// Address: 0x0000_0008
	(uintptr_t)HardFault_C1_IRQHandler,							// Address: 0x0000_000C
	(uintptr_t)MemoryManagement_C1_IRQHandler,					// Address: 0x0000_0010
	(uintptr_t)BusFault_C1_IRQHandler,							// Address: 0x0000_0014
	(uintptr_t)UsageFault_C1_IRQHandler,						// Address: 0x0000_0018
	(uintptr_t)SecureFault_C1_IRQHandler,						// Address: 0x0000_001C
	(uintptr_t)0,												// Address: 0x0000_0020
	(uintptr_t)0,												// Address: 0x0000_0024
	(uintptr_t)0,												// Address: 0x0000_0028
	(uintptr_t)SVCall_C1_IRQHandler,							// Address: 0x0000_002C
	(uintptr_t)DebugMonitor_C1_IRQHandler,						// Address: 0x0000_0030
	(uintptr_t)0,												// Address: 0x0000_0034
	(uintptr_t)PendSV_C1_IRQHandler,							// Address: 0x0000_0038
	(uintptr_t)SysTick_C1_IRQHandler,							// Address: 0x0000_003C

// rp2350 specific Interrupt Numbers

	(uintptr_t)TIMER0_IRQ_0_C1_IRQHandler,						// Address: 0x0000_0040
	(uintptr_t)TIMER0_IRQ_1_C1_IRQHandler,						// Address: 0x0000_0044
	(uintptr_t)TIMER0_IRQ_2_C1_IRQHandler,						// Address: 0x0000_0048
	(uintptr_t)TIMER0_IRQ_3_C1_IRQHandler,						// Address: 0x0000_004C
	(uintptr_t)TIMER1_IRQ_0_C1_IRQHandler,						// Address: 0x0000_0050
	(uintptr_t)TIMER1_IRQ_1_C1_IRQHandler,						// Address: 0x0000_0054
	(uintptr_t)TIMER1_IRQ_2_C1_IRQHandler,						// Address: 0x0000_0058
	(uintptr_t)TIMER1_IRQ_3_C1_IRQHandler,						// Address: 0x0000_005C
	(uintptr_t)PWM_IRQ_WRAP_0_C1_IRQHandler,					// Address: 0x0000_0060
	(uintptr_t)PWM_IRQ_WRAP_1_C1_IRQHandler,					// Address: 0x0000_0064
	(uintptr_t)DMA_IRQ_0_C1_IRQHandler,							// Address: 0x0000_0068
	(uintptr_t)DMA_IRQ_1_C1_IRQHandler,							// Address: 0x0000_006C
	(uintptr_t)DMA_IRQ_2_C1_IRQHandler,							// Address: 0x0000_0070
	(uintptr_t)DMA_IRQ_3_C1_IRQHandler,							// Address: 0x0000_0074
	(uintptr_t)USBCTRL_IRQ_C1_IRQHandler,						// Address: 0x0000_0078
	(uintptr_t)PIO0_IRQ_0_C1_IRQHandler,						// Address: 0x0000_007C
	(uintptr_t)PIO0_IRQ_1_C1_IRQHandler,						// Address: 0x0000_0080
	(uintptr_t)PIO1_IRQ_0_C1_IRQHandler,						// Address: 0x0000_0084
	(uintptr_t)PIO1_IRQ_1_C1_IRQHandler,						// Address: 0x0000_0088
	(uintptr_t)PIO2_IRQ_0_C1_IRQHandler,						// Address: 0x0000_008C
	(uintptr_t)PIO2_IRQ_1_C1_IRQHandler,						// Address: 0x0000_0090
	(uintptr_t)IO_IRQ_BANK0_C1_IRQHandler,						// Address: 0x0000_0094
	(uintptr_t)IO_IRQ_BANK0_NS_C1_IRQHandler,					// Address: 0x0000_0098
	(uintptr_t)IO_IRQ_QSPI_C1_IRQHandler,						// Address: 0x0000_009C
	(uintptr_t)IO_IRQ_QSPI_NS_C1_IRQHandler,					// Address: 0x0000_00A0
	(uintptr_t)SIO_IRQ_FIFO_C1_IRQHandler,						// Address: 0x0000_00A4
	(uintptr_t)SIO_IRQ_BELL_C1_IRQHandler,						// Address: 0x0000_00A8
	(uintptr_t)SIO_IRQ_FIFO_NS_C1_IRQHandler,					// Address: 0x0000_00AC
	(uintptr_t)SIO_IRQ_BELL_NS_C1_IRQHandler,					// Address: 0x0000_00B0
	(uintptr_t)SIO_IRQ_MTIMECMP_C1_IRQHandler,					// Address: 0x0000_00B4
	(uintptr_t)CLOCKS_IRQ_C1_IRQHandler,						// Address: 0x0000_00B8
	(uintptr_t)SPI0_IRQ_C1_IRQHandler,							// Address: 0x0000_00BC
	(uintptr_t)SPI1_IRQ_C1_IRQHandler,							// Address: 0x0000_00C0
	(uintptr_t)UART0_IRQ_C1_IRQHandler,							// Address: 0x0000_00C4
	(uintptr_t)UART1_IRQ_C1_IRQHandler,							// Address: 0x0000_00C8
	(uintptr_t)ADC_IRQ_FIFO_C1_IRQHandler,						// Address: 0x0000_00CC
	(uintptr_t)I2C0_IRQ_C1_IRQHandler,							// Address: 0x0000_00D0
	(uintptr_t)I2C1_IRQ_C1_IRQHandler,							// Address: 0x0000_00D4
	(uintptr_t)OTP_IRQ_C1_IRQHandler,							// Address: 0x0000_00D8
	(uintptr_t)TRNG_IRQ_C1_IRQHandler,							// Address: 0x0000_00DC
	(uintptr_t)0,												// Address: 0x0000_00E0
	(uintptr_t)0,												// Address: 0x0000_00E4
	(uintptr_t)PLL_SYS_IRQ_C1_IRQHandler,						// Address: 0x0000_00E8
	(uintptr_t)PLL_USB_IRQ_C1_IRQHandler,						// Address: 0x0000_00EC
	(uintptr_t)POWMAN_IRQ_POW_C1_IRQHandler,					// Address: 0x0000_00F0
	(uintptr_t)POWMAN_IRQ_TIMER_C1_IRQHandler					// Address: 0x0000_00F4
};

EXCEPTION_SPECIFIC_HANDLER(NonMaskableInt_C1)
EXCEPTION_SPECIFIC_HANDLER(HardFault_C1)
EXCEPTION_SPECIFIC_HANDLER(MemoryManagement_C1)
EXCEPTION_SPECIFIC_HANDLER(BusFault_C1)
EXCEPTION_SPECIFIC_HANDLER(UsageFault_C1)
EXCEPTION_SPECIFIC_HANDLER(SVCall_C1)
EXCEPTION_SPECIFIC_HANDLER(SecureFault_C1)
EXCEPTION_SPECIFIC_HANDLER(DebugMonitor_C1)
EXCEPTION_SPECIFIC_HANDLER(PendSV_C1)
EXCEPTION_SPECIFIC_HANDLER(SysTick_C1)

/*
 * \brief Reset_C0_Handler
 *
 * - Call the crt0
 *
 */
void	Reset_C0_Handler(void) {

	SET_THREAD_STACK(linker_topStackFirst_C0);

	crt0();
}

/*
 * \brief Reset_C1_Handler
 *
 * - Call the crt0
 *
 */
void	Reset_C1_Handler(void) {

	cmns_wait(1000000u);

	SET_MSP_STACK(linker_topStackSystem_C1);
	SET_THREAD_STACK(linker_topStackFirst_C1);

	crt0();
}

#endif

// Peripheral interrupt handlers (Core 0)
// RP2350: All arrive on Hazard3 as mcause = 11 (MEIP) and are demuxed via MEINEXT.

// cppcheck-suppress-begin premium-unreadVariable
//
INTERRUPT_SPECIFIC_HANDLER(TIMER0_IRQ_0_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER0_IRQ_1_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER0_IRQ_2_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER0_IRQ_3_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER1_IRQ_0_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER1_IRQ_1_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER1_IRQ_2_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER1_IRQ_3_C0)
INTERRUPT_SPECIFIC_HANDLER(PWM_IRQ_WRAP_0_C0)
INTERRUPT_SPECIFIC_HANDLER(PWM_IRQ_WRAP_1_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA_IRQ_0_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA_IRQ_1_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA_IRQ_2_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA_IRQ_3_C0)
INTERRUPT_SPECIFIC_HANDLER(USBCTRL_IRQ_C0)
INTERRUPT_SPECIFIC_HANDLER(PIO0_IRQ_0_C0)
INTERRUPT_SPECIFIC_HANDLER(PIO0_IRQ_1_C0)
INTERRUPT_SPECIFIC_HANDLER(PIO1_IRQ_0_C0)
INTERRUPT_SPECIFIC_HANDLER(PIO1_IRQ_1_C0)
INTERRUPT_SPECIFIC_HANDLER(PIO2_IRQ_0_C0)
INTERRUPT_SPECIFIC_HANDLER(PIO2_IRQ_1_C0)
INTERRUPT_SPECIFIC_HANDLER(IO_IRQ_BANK0_C0)
INTERRUPT_SPECIFIC_HANDLER(IO_IRQ_BANK0_NS_C0)
INTERRUPT_SPECIFIC_HANDLER(IO_IRQ_QSPI_C0)
INTERRUPT_SPECIFIC_HANDLER(IO_IRQ_QSPI_NS_C0)
INTERRUPT_SPECIFIC_HANDLER(SIO_IRQ_FIFO_C0)
INTERRUPT_SPECIFIC_HANDLER(SIO_IRQ_BELL_C0)
INTERRUPT_SPECIFIC_HANDLER(SIO_IRQ_FIFO_NS_C0)
INTERRUPT_SPECIFIC_HANDLER(SIO_IRQ_BELL_NS_C0)
INTERRUPT_SPECIFIC_HANDLER(SIO_IRQ_MTIMECMP_C0)
INTERRUPT_SPECIFIC_HANDLER(CLOCKS_IRQ_C0)
INTERRUPT_SPECIFIC_HANDLER(SPI0_IRQ_C0)
INTERRUPT_SPECIFIC_HANDLER(SPI1_IRQ_C0)
INTERRUPT_SPECIFIC_HANDLER(UART0_IRQ_C0)
INTERRUPT_SPECIFIC_HANDLER(UART1_IRQ_C0)
INTERRUPT_SPECIFIC_HANDLER(ADC_IRQ_FIFO_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C0_IRQ_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C1_IRQ_C0)
INTERRUPT_SPECIFIC_HANDLER(OTP_IRQ_C0)
INTERRUPT_SPECIFIC_HANDLER(TRNG_IRQ_C0)
INTERRUPT_SPECIFIC_HANDLER(PLL_SYS_IRQ_C0)
INTERRUPT_SPECIFIC_HANDLER(PLL_USB_IRQ_C0)
INTERRUPT_SPECIFIC_HANDLER(POWMAN_IRQ_POW_C0)
INTERRUPT_SPECIFIC_HANDLER(POWMAN_IRQ_TIMER_C0)

// Peripheral interrupt handlers (Core 1)

INTERRUPT_SPECIFIC_HANDLER(TIMER0_IRQ_0_C1)
INTERRUPT_SPECIFIC_HANDLER(TIMER0_IRQ_1_C1)
INTERRUPT_SPECIFIC_HANDLER(TIMER0_IRQ_2_C1)
INTERRUPT_SPECIFIC_HANDLER(TIMER0_IRQ_3_C1)
INTERRUPT_SPECIFIC_HANDLER(TIMER1_IRQ_0_C1)
INTERRUPT_SPECIFIC_HANDLER(TIMER1_IRQ_1_C1)
INTERRUPT_SPECIFIC_HANDLER(TIMER1_IRQ_2_C1)
INTERRUPT_SPECIFIC_HANDLER(TIMER1_IRQ_3_C1)
INTERRUPT_SPECIFIC_HANDLER(PWM_IRQ_WRAP_0_C1)
INTERRUPT_SPECIFIC_HANDLER(PWM_IRQ_WRAP_1_C1)
INTERRUPT_SPECIFIC_HANDLER(DMA_IRQ_0_C1)
INTERRUPT_SPECIFIC_HANDLER(DMA_IRQ_1_C1)
INTERRUPT_SPECIFIC_HANDLER(DMA_IRQ_2_C1)
INTERRUPT_SPECIFIC_HANDLER(DMA_IRQ_3_C1)
INTERRUPT_SPECIFIC_HANDLER(USBCTRL_IRQ_C1)
INTERRUPT_SPECIFIC_HANDLER(PIO0_IRQ_0_C1)
INTERRUPT_SPECIFIC_HANDLER(PIO0_IRQ_1_C1)
INTERRUPT_SPECIFIC_HANDLER(PIO1_IRQ_0_C1)
INTERRUPT_SPECIFIC_HANDLER(PIO1_IRQ_1_C1)
INTERRUPT_SPECIFIC_HANDLER(PIO2_IRQ_0_C1)
INTERRUPT_SPECIFIC_HANDLER(PIO2_IRQ_1_C1)
INTERRUPT_SPECIFIC_HANDLER(IO_IRQ_BANK0_C1)
INTERRUPT_SPECIFIC_HANDLER(IO_IRQ_BANK0_NS_C1)
INTERRUPT_SPECIFIC_HANDLER(IO_IRQ_QSPI_C1)
INTERRUPT_SPECIFIC_HANDLER(IO_IRQ_QSPI_NS_C1)
INTERRUPT_SPECIFIC_HANDLER(SIO_IRQ_FIFO_C1)
INTERRUPT_SPECIFIC_HANDLER(SIO_IRQ_BELL_C1)
INTERRUPT_SPECIFIC_HANDLER(SIO_IRQ_FIFO_NS_C1)
INTERRUPT_SPECIFIC_HANDLER(SIO_IRQ_BELL_NS_C1)
INTERRUPT_SPECIFIC_HANDLER(SIO_IRQ_MTIMECMP_C1)
INTERRUPT_SPECIFIC_HANDLER(CLOCKS_IRQ_C1)
INTERRUPT_SPECIFIC_HANDLER(SPI0_IRQ_C1)
INTERRUPT_SPECIFIC_HANDLER(SPI1_IRQ_C1)
INTERRUPT_SPECIFIC_HANDLER(UART0_IRQ_C1)
INTERRUPT_SPECIFIC_HANDLER(UART1_IRQ_C1)
INTERRUPT_SPECIFIC_HANDLER(ADC_IRQ_FIFO_C1)
INTERRUPT_SPECIFIC_HANDLER(I2C0_IRQ_C1)
INTERRUPT_SPECIFIC_HANDLER(I2C1_IRQ_C1)
INTERRUPT_SPECIFIC_HANDLER(OTP_IRQ_C1)
INTERRUPT_SPECIFIC_HANDLER(TRNG_IRQ_C1)
INTERRUPT_SPECIFIC_HANDLER(PLL_SYS_IRQ_C1)
INTERRUPT_SPECIFIC_HANDLER(PLL_USB_IRQ_C1)
INTERRUPT_SPECIFIC_HANDLER(POWMAN_IRQ_POW_C1)
INTERRUPT_SPECIFIC_HANDLER(POWMAN_IRQ_TIMER_C1)

// cppcheck-suppress-end premium-unreadVariable
