/*
; first.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		Vectors for the uKOS-X system (first) - RISC-V variant.
;
;   (c) 2025-2026, Laurent von Allmen
;   ---------------------------------
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

#include	<stdint.h>

#include	"core.h"
#include	"soc_reg.h"
#include	"macros_soc.h"
#include	"macros_core.h"
#include	"macros_core_stackFrame.h"	// IWYU pragma: keep (for INTERRUPTION_IN INTERRUPTION_OUT)

extern	void	(*vExce_indExcVectors[KNB_CORES][KNB_EXCEPTIONS])(void);
extern	void	(*vExce_indIntVectors[KNB_CORES][KNB_INTERRUPTIONS])(void);
extern	bool	vExce_isException[KNB_CORES];

// Ecall context-switch support
// These are used by the trap handler to pass the message and save/restore sp

volatile	uintptr_t	vSaveStack;
volatile	uint32_t	vMessage;

// Vector table for RISC-V
// RISC-V uses a different interrupt model than ARM - interrupts are routed through
// a Platform-Level Interrupt Controller (PLIC) rather than a direct vector table

// Prototypes

/*
 * \brief Reset_C0_Handler
 *
 * This code is called directly by the reset handler for core 0
 * - Initialise the first stack
 * - call the crt0
 *
 */
void __attribute__ ((naked, section(".text_vectors"))) Reset_C0_Handler(void) {

// Initialise the RISC-V global pointer (required for small data access)

	__asm volatile (
		".option push					\n"
		".option norelax				\n"
		"la		gp,__global_pointer$	\n"
		".option pop					\n"
	);

// Install trap handler

	__asm volatile (
		"la		t0,first_handle_trap	\n"
		"csrw   mtvec,t0				\n"
	);

// Initialise the first stack

	__asm volatile ("la	sp,linker_topStackFirst_C0");

// Continue with the crt0

	CALL_FNCT(crt0);
}

/*
 * \brief Reset_C1_Handler
 *
 * This code is called directly by the reset handler for core 1
 * - Initialise the first stack
 * - call the crt0
 *
 */
void __attribute__ ((naked)) Reset_C1_Handler(void) {

// Initialise the first stack
// Continue with the crt0

	__asm volatile ("la	sp,linker_topStackFirst_C1");

	CALL_FNCT(crt0);
}

// RISC-V exception handlers (per core)
// These are dispatched through the trap handler based on mcause

EXCEPTION_SPECIFIC_HANDLER(InstructionAddressMisaligned_C0)
EXCEPTION_SPECIFIC_HANDLER(InstructionAccessFault_C0)
EXCEPTION_SPECIFIC_HANDLER(IllegalInstruction_C0)
EXCEPTION_SPECIFIC_HANDLER(Breakpoint_C0)
EXCEPTION_SPECIFIC_HANDLER(LoadAddressMisaligned_C0)
EXCEPTION_SPECIFIC_HANDLER(LoadAccessFault_C0)
EXCEPTION_SPECIFIC_HANDLER(StoreAddressMisaligned_C0)
EXCEPTION_SPECIFIC_HANDLER(StoreAccessFault_C0)
EXCEPTION_SPECIFIC_HANDLER(ECallUser_C0)
EXCEPTION_SPECIFIC_HANDLER(ECallSupervisor_C0)
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
EXCEPTION_SPECIFIC_HANDLER(ECallSupervisor_C1)
EXCEPTION_SPECIFIC_HANDLER(ECallMachine_C1)
EXCEPTION_SPECIFIC_HANDLER(InstructionPageFault_C1)
EXCEPTION_SPECIFIC_HANDLER(LoadPageFault_C1)
EXCEPTION_SPECIFIC_HANDLER(StorePageFault_C1)

// RISC-V machine-mode timer and software interrupts (per core)
EXCEPTION_SPECIFIC_HANDLER(MSIP_C0)		// Machine Software Interrupt
EXCEPTION_SPECIFIC_HANDLER(MTIP_C0)		// Machine Timer Interrupt

EXCEPTION_SPECIFIC_HANDLER(MSIP_C1)
EXCEPTION_SPECIFIC_HANDLER(MTIP_C1)

// RP2350 peripheral interrupt handlers (Core 0)
// These are dispatched through the PLIC (Platform-Level Interrupt Controller)

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

// RP2350 peripheral interrupt handlers (Core 1)

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

/*
 * \brief first_handle_trap
 *
 * - Main RISC-V trap entry point
 * - Dispatches to exception or interrupt handlers based on mcause
 *
 * This function is called from trapEntry in vectors_rv.S
 * It reads mcause to determine the cause and dispatches to the appropriate handler
 */
void __attribute__ ((naked)) first_handle_trap(void) {
	// Save context (basic registers)
	__asm volatile (
		"	addi	sp,sp,-16*4						\n"		// Allocate stack space
		"	sw		ra,0*4(sp)						\n"		// Save return address
		"	sw		t0,1*4(sp)						\n"		// Save t0
		"	sw		t1,2*4(sp)						\n"		// Save t1
		"	sw		t2,3*4(sp)						\n"		// Save t2
		"	sw		a0,4*4(sp)						\n"		// Save a0
		"	sw		a1,5*4(sp)						\n"		// Save a1
		"	sw		a2,6*4(sp)						\n"		// Save a2
		"	sw		a3,7*4(sp)						\n"		// Save a3
		"	sw		a4,8*4(sp)						\n"		// Save a4
		"	sw		a5,9*4(sp)						\n"		// Save a5
		"	sw		a6,10*4(sp)						\n"		// Save a6
		"	sw		a7,11*4(sp)						\n"		// Save a7
		"	csrr	t0,mcause						\n"		// Read mcause
		"	sw		t0,12*4(sp)						\n"		// Save mcause
		"	csrr	t1,mepc							\n"		// Read mepc
		"	sw		t1,13*4(sp)						\n"		// Save mepc

		// Determine exception vs interrupt
		"	bltz	t0,1f							\n"		// If MSB set, it's an interrupt

		// Exception handling
		"	andi	t0,t0,0x1F						\n"		// Extract exception code (bits 0-4)
		"	li		t1,11							\n"		// Ecall from M-mode?
		"	beq		t0,t1,3f						\n"		// Yes, branch to ecall path
		"	call	first_dispatch_exception		\n"		// Call exception dispatcher
		"	j		2f								\n"

		// Ecall context-switch path
		"3:											\n"

		// Advance mepc past the ecall instruction (4 bytes)
		"	lw		t1,13*4(sp)						\n"
		"	addi	t1,t1,4							\n"
		"	sw		t1,13*4(sp)						\n"

		// Save callee-saved registers
		"	addi	sp,sp,-12*4						\n"
		"	sw		s0,0*4(sp)						\n"
		"	sw		s1,1*4(sp)						\n"
		"	sw		s2,2*4(sp)						\n"
		"	sw		s3,3*4(sp)						\n"
		"	sw		s4,4*4(sp)						\n"
		"	sw		s5,5*4(sp)						\n"
		"	sw		s6,6*4(sp)						\n"
		"	sw		s7,7*4(sp)						\n"
		"	sw		s8,8*4(sp)						\n"
		"	sw		s9,9*4(sp)						\n"
		"	sw		s10,10*4(sp)					\n"
		"	sw		s11,11*4(sp)					\n"

		// Extract message from saved a0 (at (12+4)*4(sp) = 16*4(sp))
		"	lw		t1,16*4(sp)						\n"
		"	la		t2,vMessage						\n"
		"	sw		t1,0(t2)						\n"

		// Save sp to vSaveStack
		"	la		t2,vSaveStack					\n"
		"	sw		sp,0(t2)						\n"

		// Call ecall dispatcher (may switch vSaveStack)
		"	call	first_dispatch_ecall			\n"

		// Restore sp from vSaveStack (may have been switched)
		"	la		t2,vSaveStack					\n"
		"	lw		sp,0(t2)						\n"

		// Restore callee-saved registers
		"	lw		s0,0*4(sp)						\n"
		"	lw		s1,1*4(sp)						\n"
		"	lw		s2,2*4(sp)						\n"
		"	lw		s3,3*4(sp)						\n"
		"	lw		s4,4*4(sp)						\n"
		"	lw		s5,5*4(sp)						\n"
		"	lw		s6,6*4(sp)						\n"
		"	lw		s7,7*4(sp)						\n"
		"	lw		s8,8*4(sp)						\n"
		"	lw		s9,9*4(sp)						\n"
		"	lw		s10,10*4(sp)					\n"
		"	lw		s11,11*4(sp)					\n"
		"	addi	sp,sp,12*4						\n"

		"	j		2f								\n"

		// Interrupt handling
		"1:											\n"
		"	li		t1,0x7FFFFFFF					\n"		// Mask for interrupt number
		"	and		t0,t0,t1						\n"		// Extract interrupt number
		"	call	first_dispatch_interrupt		\n"		// Call interrupt dispatcher

		// Restore context
		"2:											\n"
		"	lw		t1,13*4(sp)						\n"		// Restore mepc
		"	csrw	mepc,t1							\n"
		"	lw		a7,11*4(sp)						\n"		// Restore a7
		"	lw		a6,10*4(sp)						\n"		// Restore a6
		"	lw		a5,9*4(sp)						\n"		// Restore a5
		"	lw		a4,8*4(sp)						\n"		// Restore a4
		"	lw		a3,7*4(sp)						\n"		// Restore a3
		"	lw		a2,6*4(sp)						\n"		// Restore a2
		"	lw		a1,5*4(sp)						\n"		// Restore a1
		"	lw		a0,4*4(sp)						\n"		// Restore a0
		"	lw		t2,3*4(sp)						\n"		// Restore t2
		"	lw		t1,2*4(sp)						\n"		// Restore t1
		"	lw		t0,1*4(sp)						\n"		// Restore t0
		"	lw		ra,0*4(sp)						\n"		// Restore ra
		"	addi	sp,sp,16*4						\n"		// Deallocate stack space
		"	mret									\n"		// Return from trap
		:::
	);
}

/*
 * \brief first_dispatch_exception
 *
 * - Dispatches to exception handler based on exception code in t0
 */
void first_dispatch_exception(void) {
	uint32_t core = GET_RUNNING_CORE;
	uint32_t exception;
	__asm volatile ("mv %0,t0" : "=r"(exception));

	if (exception < KNB_EXCEPTIONS && vExce_indExcVectors[core][exception] != NULL) {
		vExce_indExcVectors[core][exception]();
	}
}

/*
 * \brief first_dispatch_interrupt
 *
 * - Dispatches to interrupt handler based on interrupt number in t0
 * - For Machine External Interrupt (MEIP, code 11), reads the Hazard3
 *   meinext CSR to determine the actual peripheral IRQ number
 */
void first_dispatch_interrupt(void) {
	uint32_t	core = GET_RUNNING_CORE;
	uint32_t	interrupt;
	__asm volatile ("mv %0,t0" : "=r"(interrupt));

	if (interrupt == 11u) {

		// Machine External Interrupt (MEIP)
		// Read meinext to get the pending peripheral IRQ number

		uint32_t	meinext = core_getNextExternalIRQ();
		if ((meinext & MEINEXT_NOIRQ) == 0u) {
			uint32_t	irqNum = meinext >> MEINEXT_IRQ_SHIFT;
			if (irqNum < KNB_INTERRUPTIONS && vExce_indIntVectors[core][irqNum] != NULL) {
				vExce_indIntVectors[core][irqNum]();
			}
		}
	}
	else if (interrupt < KNB_INTERRUPTIONS && vExce_indIntVectors[core][interrupt] != NULL) {
		vExce_indIntVectors[core][interrupt]();
	}
}

/*
 * \brief first_dispatch_ecall
 *
 * - Dispatches to the ecall exception handler (exception code 11)
 * - Called from the ecall path of first_handle_trap after saving
 *   the full process context and setting vMessage/vSaveStack
 */
void first_dispatch_ecall(void) {
	uint32_t	core = GET_RUNNING_CORE;

	if (vExce_indExcVectors[core][11u] != NULL) {
		vExce_indExcVectors[core][11u]();
	}
}
