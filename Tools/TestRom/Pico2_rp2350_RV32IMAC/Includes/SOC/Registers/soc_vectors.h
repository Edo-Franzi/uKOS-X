/*
; soc_vectors.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Indirect Exception Vectors for Cortex_M33.
;			The "reset" exception is not considered. The indirect table
;			is reserved in the first.c file.
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

#pragma	once

#if defined(__riscv)

// RISC-V Exception Numbers (mcause exception codes)
typedef enum IRQn {

// RISC-V Processor Exceptions Numbers

	InstructionAddressMisaligned_IRQn	= 0,	// Instruction address misaligned
	InstructionAccessFault_IRQn			= 1,	// Instruction access fault
	IllegalInstruction_IRQn				= 2,	// Illegal instruction
	Breakpoint_IRQn						= 3,	// Breakpoint
	LoadAddressMisaligned_IRQn			= 4,	// Load address misaligned
	LoadAccessFault_IRQn				= 5,	// Load access fault
	StoreAddressMisaligned_IRQn			= 6,	// Store/AMO address misaligned
	StoreAccessFault_IRQn				= 7,	// Store/AMO access fault
	ECallUser_IRQn						= 8,	// Environment call from U-mode
	ECallSupervisor_IRQn				= 9,	// Environment call from S-mode
	ECallMachine_IRQn					= 11,	// Environment call from M-mode
	InstructionPageFault_IRQn			= 12,	// Instruction page fault
	LoadPageFault_IRQn					= 13,	// Load page fault
	StorePageFault_IRQn					= 15,	// Store/AMO page fault

// RISC-V Machine-mode Interrupt Numbers (mcause interrupt codes)

	MSIP_IRQn							= 3,	// Machine software interrupt
	MTIP_IRQn							= 7,	// Machine timer interrupt
	MEIP_IRQn							= 11,	// Machine external interrupt

// SOC Specific Interrupt Numbers (via PLIC/NVIC)

	TIMER0_IRQ_0_IRQn		= 0,	//
	TIMER0_IRQ_1_IRQn		= 1,	//
	TIMER0_IRQ_2_IRQn		= 2,	//
	TIMER0_IRQ_3_IRQn		= 3,	//
	TIMER1_IRQ_0_IRQn		= 4,	//
	TIMER1_IRQ_1_IRQn		= 5,	//
	TIMER1_IRQ_2_IRQn		= 6,	//
	TIMER1_IRQ_3_IRQn		= 7,	//
	PWM_IRQ_WRAP_0_IRQn		= 8,	//
	PWM_IRQ_WRAP_1_IRQn		= 9,	//
	DMA_IRQ_0_IRQn			= 10,	//
	DMA_IRQ_1_IRQn			= 11,	//
	DMA_IRQ_2_IRQn			= 12,	//
	DMA_IRQ_3_IRQn			= 13,	//
	USBCTRL_IRQ_IRQn		= 14,	//
	PIO0_IRQ_0_IRQn			= 15,	//
	PIO0_IRQ_1_IRQn			= 16,	//
	PIO1_IRQ_0_IRQn			= 17,	//
	PIO1_IRQ_1_IRQn			= 18,	//
	PIO2_IRQ_0_IRQn			= 19,	//
	PIO2_IRQ_1_IRQn			= 20,	//
	IO_IRQ_BANK0_IRQn		= 21,	//
	IO_IRQ_BANK0_NS_IRQn	= 22,	//
	IO_IRQ_QSPI_IRQn		= 23,	//
	IO_IRQ_QSPI_NS_IRQn		= 24,	//
	SIO_IRQ_FIFO_IRQn		= 25,	//
	SIO_IRQ_BELL_IRQn		= 26,	//
	SIO_IRQ_FIFO_NS_IRQn	= 27,	//
	SIO_IRQ_BELL_NS_IRQn	= 28,	//
	SIO_IRQ_MTIMECMP_IRQn	= 29,	//
	CLOCKS_IRQ_IRQn			= 30,	//
	SPI0_IRQ_IRQn			= 31,	//
	SPI1_IRQ_IRQn			= 32,	//
	UART0_IRQ_IRQn			= 33,	//
	UART1_IRQ_IRQn			= 34,	//
	ADC_IRQ_FIFO_IRQn		= 35,	//
	I2C0_IRQ_IRQn			= 36,	//
	I2C1_IRQ_IRQn			= 37,	//
	OTP_IRQ_IRQn			= 38,	//
	TRNG_IRQ_IRQn			= 39,	//
	PLL_SYS_IRQ_IRQn		= 42,	//
	PLL_USB_IRQ_IRQn		= 43,	//
	POWMAN_IRQ_POW_IRQn		= 44,	//
	POWMAN_IRQ_TIMER_IRQn	= 45,	//
} IRQn_Type;

#define	KNB_EXCEPTIONS		16u		// RISC-V: exception codes 0-15
#define	KNB_INTERRUPTIONS	46u		// RP2350: 46 peripheral interrupts (same for ARM and RISC-V)

#else // ARM Cortex-M33

typedef enum IRQn {

// Cortex_M33 Processor Exceptions Numbers

	NonMaskableInt_IRQn		= -14,	// Non Maskable Interrupt
	HardFault_IRQn			= -13,	// Hard Fault Interrupt
	MemoryManagement_IRQn	= -12,	// Memory Management Interrupt
	BusFault_IRQn			= -11,	// Bus Fault Interrupt
	UsageFault_IRQn			= -10,	// Usage Fault Interrupt
	SecureFault_IRQn		= -9,	// Secure Fault
	SVCall_IRQn				= -5,	// SV Call Interrupt
	DebugMonitor_IRQn		= -4,	// Debug Monitor Interrupt
	PendSV_IRQn				= -2,	// Pend SV Interrupt
	SysTick_IRQn			= -1,	// System Tick Interrupt

// SOC Specific Interrupt Numbers

	TIMER0_IRQ_0_IRQn		= 0,	//
	TIMER0_IRQ_1_IRQn		= 1,	//
	TIMER0_IRQ_2_IRQn		= 2,	//
	TIMER0_IRQ_3_IRQn		= 3,	//
	TIMER1_IRQ_0_IRQn		= 4,	//
	TIMER1_IRQ_1_IRQn		= 5,	//
	TIMER1_IRQ_2_IRQn		= 6,	//
	TIMER1_IRQ_3_IRQn		= 7,	//
	PWM_IRQ_WRAP_0_IRQn		= 8,	//
	PWM_IRQ_WRAP_1_IRQn		= 9,	//
	DMA_IRQ_0_IRQn			= 10,	//
	DMA_IRQ_1_IRQn			= 11,	//
	DMA_IRQ_2_IRQn			= 12,	//
	DMA_IRQ_3_IRQn			= 13,	//
	USBCTRL_IRQ_IRQn		= 14,	//
	PIO0_IRQ_0_IRQn			= 15,	//
	PIO0_IRQ_1_IRQn			= 16,	//
	PIO1_IRQ_0_IRQn			= 17,	//
	PIO1_IRQ_1_IRQn			= 18,	//
	PIO2_IRQ_0_IRQn			= 19,	//
	PIO2_IRQ_1_IRQn			= 20,	//
	IO_IRQ_BANK0_IRQn		= 21,	//
	IO_IRQ_BANK0_NS_IRQn	= 22,	//
	IO_IRQ_QSPI_IRQn		= 23,	//
	IO_IRQ_QSPI_NS_IRQn		= 24,	//
	SIO_IRQ_FIFO_IRQn		= 25,	//
	SIO_IRQ_BELL_IRQn		= 26,	//
	SIO_IRQ_FIFO_NS_IRQn	= 27,	//
	SIO_IRQ_BELL_NS_IRQn	= 28,	//
	SIO_IRQ_MTIMECMP_IRQn	= 29,	//
	CLOCKS_IRQ_IRQn			= 30,	//
	SPI0_IRQ_IRQn			= 31,	//
	SPI1_IRQ_IRQn			= 32,	//
	UART0_IRQ_IRQn			= 33,	//
	UART1_IRQ_IRQn			= 34,	//
	ADC_IRQ_FIFO_IRQn		= 35,	//
	I2C0_IRQ_IRQn			= 36,	//
	I2C1_IRQ_IRQn			= 37,	//
	OTP_IRQ_IRQn			= 38,	//
	TRNG_IRQ_IRQn			= 39,	//
	PLL_SYS_IRQ_IRQn		= 42,	//
	PLL_USB_IRQ_IRQn		= 43,	//
	POWMAN_IRQ_POW_IRQn		= 44,	//
	POWMAN_IRQ_TIMER_IRQn	= 45,	//
} IRQn_Type;

#define	KNB_EXCEPTIONS		14u		// ARM Cortex-M33: 14 exception vectors
#define	KNB_INTERRUPTIONS	46u		// RP2350: 46 peripheral interrupts

#endif // __riscv

// For the core 0
// --------------

#if defined(__riscv)

// RISC-V Processor Exceptions Numbers

#define	InstructionAddressMisaligned_C0_IRQn	InstructionAddressMisaligned_IRQn
#define	InstructionAccessFault_C0_IRQn			InstructionAccessFault_IRQn
#define	IllegalInstruction_C0_IRQn				IllegalInstruction_IRQn
#define	Breakpoint_C0_IRQn						Breakpoint_IRQn
#define	LoadAddressMisaligned_C0_IRQn			LoadAddressMisaligned_IRQn
#define	LoadAccessFault_C0_IRQn					LoadAccessFault_IRQn
#define	StoreAddressMisaligned_C0_IRQn			StoreAddressMisaligned_IRQn
#define	StoreAccessFault_C0_IRQn				StoreAccessFault_IRQn
#define	ECallUser_C0_IRQn						ECallUser_IRQn
#define	ECallSupervisor_C0_IRQn					ECallSupervisor_IRQn
#define	ECallMachine_C0_IRQn					ECallMachine_IRQn
#define	InstructionPageFault_C0_IRQn			InstructionPageFault_IRQn
#define	LoadPageFault_C0_IRQn					LoadPageFault_IRQn
#define	StorePageFault_C0_IRQn					StorePageFault_IRQn

// RISC-V Machine-mode Interrupts

#define	MSIP_C0_IRQn							MSIP_IRQn
#define	MTIP_C0_IRQn							MTIP_IRQn
#define	MEIP_C0_IRQn							MEIP_IRQn

// SOC Specific Interrupt Numbers

#define	TIMER0_IRQ_0_C0_IRQn		TIMER0_IRQ_0_IRQn
#define	TIMER0_IRQ_1_C0_IRQn		TIMER0_IRQ_1_IRQn
#define	TIMER0_IRQ_2_C0_IRQn		TIMER0_IRQ_2_IRQn
#define	TIMER0_IRQ_3_C0_IRQn		TIMER0_IRQ_3_IRQn
#define	TIMER1_IRQ_0_C0_IRQn		TIMER1_IRQ_0_IRQn
#define	TIMER1_IRQ_1_C0_IRQn		TIMER1_IRQ_1_IRQn
#define	TIMER1_IRQ_2_C0_IRQn		TIMER1_IRQ_2_IRQn
#define	TIMER1_IRQ_3_C0_IRQn		TIMER1_IRQ_3_IRQn
#define	PWM_IRQ_WRAP_0_C0_IRQn		PWM_IRQ_WRAP_0_IRQn
#define	PWM_IRQ_WRAP_1_C0_IRQn		PWM_IRQ_WRAP_1_IRQn
#define	DMA_IRQ_0_C0_IRQn			DMA_IRQ_0_IRQn
#define	DMA_IRQ_1_C0_IRQn			DMA_IRQ_1_IRQn
#define	DMA_IRQ_2_C0_IRQn			DMA_IRQ_2_IRQn
#define	DMA_IRQ_3_C0_IRQn			DMA_IRQ_3_IRQn
#define	USBCTRL_IRQ_C0_IRQn			USBCTRL_IRQ_IRQn
#define	PIO0_IRQ_0_C0_IRQn			PIO0_IRQ_0_IRQn
#define	PIO0_IRQ_1_C0_IRQn			PIO0_IRQ_1_IRQn
#define	PIO1_IRQ_0_C0_IRQn			PIO1_IRQ_0_IRQn
#define	PIO1_IRQ_1_C0_IRQn			PIO1_IRQ_1_IRQn
#define	PIO2_IRQ_0_C0_IRQn			PIO2_IRQ_0_IRQn
#define	PIO2_IRQ_1_C0_IRQn			PIO2_IRQ_1_IRQn
#define	IO_IRQ_BANK0_C0_IRQn		IO_IRQ_BANK0_IRQn
#define	IO_IRQ_BANK0_NS_C0_IRQn		IO_IRQ_BANK0_NS_IRQn
#define	IO_IRQ_QSPI_C0_IRQn			IO_IRQ_QSPI_IRQn
#define	IO_IRQ_QSPI_NS_C0_IRQn		IO_IRQ_QSPI_NS_IRQn
#define	SIO_IRQ_FIFO_C0_IRQn		SIO_IRQ_FIFO_IRQn
#define	SIO_IRQ_BELL_C0_IRQn		SIO_IRQ_BELL_IRQn
#define	SIO_IRQ_FIFO_NS_C0_IRQn		SIO_IRQ_FIFO_NS_IRQn
#define	SIO_IRQ_BELL_NS_C0_IRQn		SIO_IRQ_BELL_NS_IRQn
#define	SIO_IRQ_MTIMECMP_C0_IRQn	SIO_IRQ_MTIMECMP_IRQn
#define	CLOCKS_IRQ_C0_IRQn			CLOCKS_IRQ_IRQn
#define	SPI0_IRQ_C0_IRQn			SPI0_IRQ_IRQn
#define	SPI1_IRQ_C0_IRQn			SPI1_IRQ_IRQn
#define	UART0_IRQ_C0_IRQn			UART0_IRQ_IRQn
#define	UART1_IRQ_C0_IRQn			UART1_IRQ_IRQn
#define	ADC_IRQ_FIFO_C0_IRQn		ADC_IRQ_FIFO_IRQn
#define	I2C0_IRQ_C0_IRQn			I2C0_IRQ_IRQn
#define	I2C1_IRQ_C0_IRQn			I2C1_IRQ_IRQn
#define	OTP_IRQ_C0_IRQn				OTP_IRQ_IRQn
#define	TRNG_IRQ_C0_IRQn			TRNG_IRQ_IRQn
#define	PLL_SYS_IRQ_C0_IRQn			PLL_SYS_IRQ_IRQn
#define	PLL_USB_IRQ_C0_IRQn			PLL_USB_IRQ_IRQn
#define	POWMAN_IRQ_POW_C0_IRQn		POWMAN_IRQ_POW_IRQn
#define	POWMAN_IRQ_TIMER_C0_IRQn	POWMAN_IRQ_TIMER_IRQn

#else // ARM

// Cortex_M33 Processor Exceptions Numbers

#define	NonMaskableInt_C0_IRQn		NonMaskableInt_IRQn
#define	HardFault_C0_IRQn			HardFault_IRQn
#define	MemoryManagement_C0_IRQn	MemoryManagement_IRQn
#define	BusFault_C0_IRQn			BusFault_IRQn
#define	UsageFault_C0_IRQn			UsageFault_IRQn
#define	SecureFault_C0_IRQn			SecureFault_IRQn
#define	SVCall_C0_IRQn				SVCall_IRQn
#define	DebugMonitor_C0_IRQn		DebugMonitor_IRQn
#define	PendSV_C0_IRQn				PendSV_IRQn
#define	SysTick_C0_IRQn				SysTick_IRQn

// SOC Specific Interrupt Numbers

#define	TIMER0_IRQ_0_C0_IRQn		TIMER0_IRQ_0_IRQn
#define	TIMER0_IRQ_1_C0_IRQn		TIMER0_IRQ_1_IRQn
#define	TIMER0_IRQ_2_C0_IRQn		TIMER0_IRQ_2_IRQn
#define	TIMER0_IRQ_3_C0_IRQn		TIMER0_IRQ_3_IRQn
#define	TIMER1_IRQ_0_C0_IRQn		TIMER1_IRQ_0_IRQn
#define	TIMER1_IRQ_1_C0_IRQn		TIMER1_IRQ_1_IRQn
#define	TIMER1_IRQ_2_C0_IRQn		TIMER1_IRQ_2_IRQn
#define	TIMER1_IRQ_3_C0_IRQn		TIMER1_IRQ_3_IRQn
#define	PWM_IRQ_WRAP_0_C0_IRQn		PWM_IRQ_WRAP_0_IRQn
#define	PWM_IRQ_WRAP_1_C0_IRQn		PWM_IRQ_WRAP_1_IRQn
#define	DMA_IRQ_0_C0_IRQn			DMA_IRQ_0_IRQn
#define	DMA_IRQ_1_C0_IRQn			DMA_IRQ_1_IRQn
#define	DMA_IRQ_2_C0_IRQn			DMA_IRQ_2_IRQn
#define	DMA_IRQ_3_C0_IRQn			DMA_IRQ_3_IRQn
#define	USBCTRL_IRQ_C0_IRQn			USBCTRL_IRQ_IRQn
#define	PIO0_IRQ_0_C0_IRQn			PIO0_IRQ_0_IRQn
#define	PIO0_IRQ_1_C0_IRQn			PIO0_IRQ_1_IRQn
#define	PIO1_IRQ_0_C0_IRQn			PIO1_IRQ_0_IRQn
#define	PIO1_IRQ_1_C0_IRQn			PIO1_IRQ_1_IRQn
#define	PIO2_IRQ_0_C0_IRQn			PIO2_IRQ_0_IRQn
#define	PIO2_IRQ_1_C0_IRQn			PIO2_IRQ_1_IRQn
#define	IO_IRQ_BANK0_C0_IRQn		IO_IRQ_BANK0_IRQn
#define	IO_IRQ_BANK0_NS_C0_IRQn		IO_IRQ_BANK0_NS_IRQn
#define	IO_IRQ_QSPI_C0_IRQn			IO_IRQ_QSPI_IRQn
#define	IO_IRQ_QSPI_NS_C0_IRQn		IO_IRQ_QSPI_NS_IRQn
#define	SIO_IRQ_FIFO_C0_IRQn		SIO_IRQ_FIFO_IRQn
#define	SIO_IRQ_BELL_C0_IRQn		SIO_IRQ_BELL_IRQn
#define	SIO_IRQ_FIFO_NS_C0_IRQn		SIO_IRQ_FIFO_NS_IRQn
#define	SIO_IRQ_BELL_NS_C0_IRQn		SIO_IRQ_BELL_NS_IRQn
#define	SIO_IRQ_MTIMECMP_C0_IRQn	SIO_IRQ_MTIMECMP_IRQn
#define	CLOCKS_IRQ_C0_IRQn			CLOCKS_IRQ_IRQn
#define	SPI0_IRQ_C0_IRQn			SPI0_IRQ_IRQn
#define	SPI1_IRQ_C0_IRQn			SPI1_IRQ_IRQn
#define	UART0_IRQ_C0_IRQn			UART0_IRQ_IRQn
#define	UART1_IRQ_C0_IRQn			UART1_IRQ_IRQn
#define	ADC_IRQ_FIFO_C0_IRQn		ADC_IRQ_FIFO_IRQn
#define	I2C0_IRQ_C0_IRQn			I2C0_IRQ_IRQn
#define	I2C1_IRQ_C0_IRQn			I2C1_IRQ_IRQn
#define	OTP_IRQ_C0_IRQn				OTP_IRQ_IRQn
#define	TRNG_IRQ_C0_IRQn			TRNG_IRQ_IRQn
#define	PLL_SYS_IRQ_C0_IRQn			PLL_SYS_IRQ_IRQn
#define	PLL_USB_IRQ_C0_IRQn			PLL_USB_IRQ_IRQn
#define	POWMAN_IRQ_POW_C0_IRQn		POWMAN_IRQ_POW_IRQn
#define	POWMAN_IRQ_TIMER_C0_IRQn	POWMAN_IRQ_TIMER_IRQn

#endif // __riscv

// For the core 1
// --------------

#if defined(__riscv)

// RISC-V Processor Exceptions Numbers

#define	InstructionAddressMisaligned_C1_IRQn	InstructionAddressMisaligned_IRQn
#define	InstructionAccessFault_C1_IRQn			InstructionAccessFault_IRQn
#define	IllegalInstruction_C1_IRQn				IllegalInstruction_IRQn
#define	Breakpoint_C1_IRQn						Breakpoint_IRQn
#define	LoadAddressMisaligned_C1_IRQn			LoadAddressMisaligned_IRQn
#define	LoadAccessFault_C1_IRQn					LoadAccessFault_IRQn
#define	StoreAddressMisaligned_C1_IRQn			StoreAddressMisaligned_IRQn
#define	StoreAccessFault_C1_IRQn				StoreAccessFault_IRQn
#define	ECallUser_C1_IRQn						ECallUser_IRQn
#define	ECallSupervisor_C1_IRQn					ECallSupervisor_IRQn
#define	ECallMachine_C1_IRQn					ECallMachine_IRQn
#define	InstructionPageFault_C1_IRQn			InstructionPageFault_IRQn
#define	LoadPageFault_C1_IRQn					LoadPageFault_IRQn
#define	StorePageFault_C1_IRQn					StorePageFault_IRQn

// RISC-V Machine-mode Interrupts

#define	MSIP_C1_IRQn							MSIP_IRQn
#define	MTIP_C1_IRQn							MTIP_IRQn
#define	MEIP_C1_IRQn							MEIP_IRQn

// SOC Specific Interrupt Numbers (same for RISC-V and ARM)

#define	TIMER0_IRQ_0_C1_IRQn		TIMER0_IRQ_0_IRQn
#define	TIMER0_IRQ_1_C1_IRQn		TIMER0_IRQ_1_IRQn
#define	TIMER0_IRQ_2_C1_IRQn		TIMER0_IRQ_2_IRQn
#define	TIMER0_IRQ_3_C1_IRQn		TIMER0_IRQ_3_IRQn
#define	TIMER1_IRQ_0_C1_IRQn		TIMER1_IRQ_0_IRQn
#define	TIMER1_IRQ_1_C1_IRQn		TIMER1_IRQ_1_IRQn
#define	TIMER1_IRQ_2_C1_IRQn		TIMER1_IRQ_2_IRQn
#define	TIMER1_IRQ_3_C1_IRQn		TIMER1_IRQ_3_IRQn
#define	PWM_IRQ_WRAP_0_C1_IRQn		PWM_IRQ_WRAP_0_IRQn
#define	PWM_IRQ_WRAP_1_C1_IRQn		PWM_IRQ_WRAP_1_IRQn
#define	DMA_IRQ_0_C1_IRQn			DMA_IRQ_0_IRQn
#define	DMA_IRQ_1_C1_IRQn			DMA_IRQ_1_IRQn
#define	DMA_IRQ_2_C1_IRQn			DMA_IRQ_2_IRQn
#define	DMA_IRQ_3_C1_IRQn			DMA_IRQ_3_IRQn
#define	USBCTRL_IRQ_C1_IRQn			USBCTRL_IRQ_IRQn
#define	PIO0_IRQ_0_C1_IRQn			PIO0_IRQ_0_IRQn
#define	PIO0_IRQ_1_C1_IRQn			PIO0_IRQ_1_IRQn
#define	PIO1_IRQ_0_C1_IRQn			PIO1_IRQ_0_IRQn
#define	PIO1_IRQ_1_C1_IRQn			PIO1_IRQ_1_IRQn
#define	PIO2_IRQ_0_C1_IRQn			PIO2_IRQ_0_IRQn
#define	PIO2_IRQ_1_C1_IRQn			PIO2_IRQ_1_IRQn
#define	IO_IRQ_BANK0_C1_IRQn		IO_IRQ_BANK0_IRQn
#define	IO_IRQ_BANK0_NS_C1_IRQn		IO_IRQ_BANK0_NS_IRQn
#define	IO_IRQ_QSPI_C1_IRQn			IO_IRQ_QSPI_IRQn
#define	IO_IRQ_QSPI_NS_C1_IRQn		IO_IRQ_QSPI_NS_IRQn
#define	SIO_IRQ_FIFO_C1_IRQn		SIO_IRQ_FIFO_IRQn
#define	SIO_IRQ_BELL_C1_IRQn		SIO_IRQ_BELL_IRQn
#define	SIO_IRQ_FIFO_NS_C1_IRQn		SIO_IRQ_FIFO_NS_IRQn
#define	SIO_IRQ_BELL_NS_C1_IRQn		SIO_IRQ_BELL_NS_IRQn
#define	SIO_IRQ_MTIMECMP_C1_IRQn	SIO_IRQ_MTIMECMP_IRQn
#define	CLOCKS_IRQ_C1_IRQn			CLOCKS_IRQ_IRQn
#define	SPI0_IRQ_C1_IRQn			SPI0_IRQ_IRQn
#define	SPI1_IRQ_C1_IRQn			SPI1_IRQ_IRQn
#define	UART0_IRQ_C1_IRQn			UART0_IRQ_IRQn
#define	UART1_IRQ_C1_IRQn			UART1_IRQ_IRQn
#define	ADC_IRQ_FIFO_C1_IRQn		ADC_IRQ_FIFO_IRQn
#define	I2C0_IRQ_C1_IRQn			I2C0_IRQ_IRQn
#define	I2C1_IRQ_C1_IRQn			I2C1_IRQ_IRQn
#define	OTP_IRQ_C1_IRQn				OTP_IRQ_IRQn
#define	TRNG_IRQ_C1_IRQn			TRNG_IRQ_IRQn
#define	PLL_SYS_IRQ_C1_IRQn			PLL_SYS_IRQ_IRQn
#define	PLL_USB_IRQ_C1_IRQn			PLL_USB_IRQ_IRQn
#define	POWMAN_IRQ_POW_C1_IRQn		POWMAN_IRQ_POW_IRQn
#define	POWMAN_IRQ_TIMER_C1_IRQn	POWMAN_IRQ_TIMER_IRQn

#else // ARM

// Cortex_M33 Processor Exceptions Numbers

#define	NonMaskableInt_C1_IRQn		NonMaskableInt_IRQn
#define	HardFault_C1_IRQn			HardFault_IRQn
#define	MemoryManagement_C1_IRQn	MemoryManagement_IRQn
#define	BusFault_C1_IRQn			BusFault_IRQn
#define	UsageFault_C1_IRQn			UsageFault_IRQn
#define	SecureFault_C1_IRQn			SecureFault_IRQn
#define	SVCall_C1_IRQn				SVCall_IRQn
#define	DebugMonitor_C1_IRQn		DebugMonitor_IRQn
#define	PendSV_C1_IRQn				PendSV_IRQn
#define	SysTick_C1_IRQn				SysTick_IRQn

// SOC Specific Interrupt Numbers

#define	TIMER0_IRQ_0_C1_IRQn		TIMER0_IRQ_0_IRQn
#define	TIMER0_IRQ_1_C1_IRQn		TIMER0_IRQ_1_IRQn
#define	TIMER0_IRQ_2_C1_IRQn		TIMER0_IRQ_2_IRQn
#define	TIMER0_IRQ_3_C1_IRQn		TIMER0_IRQ_3_IRQn
#define	TIMER1_IRQ_0_C1_IRQn		TIMER1_IRQ_0_IRQn
#define	TIMER1_IRQ_1_C1_IRQn		TIMER1_IRQ_1_IRQn
#define	TIMER1_IRQ_2_C1_IRQn		TIMER1_IRQ_2_IRQn
#define	TIMER1_IRQ_3_C1_IRQn		TIMER1_IRQ_3_IRQn
#define	PWM_IRQ_WRAP_0_C1_IRQn		PWM_IRQ_WRAP_0_IRQn
#define	PWM_IRQ_WRAP_1_C1_IRQn		PWM_IRQ_WRAP_1_IRQn
#define	DMA_IRQ_0_C1_IRQn			DMA_IRQ_0_IRQn
#define	DMA_IRQ_1_C1_IRQn			DMA_IRQ_1_IRQn
#define	DMA_IRQ_2_C1_IRQn			DMA_IRQ_2_IRQn
#define	DMA_IRQ_3_C1_IRQn			DMA_IRQ_3_IRQn
#define	USBCTRL_IRQ_C1_IRQn			USBCTRL_IRQ_IRQn
#define	PIO0_IRQ_0_C1_IRQn			PIO0_IRQ_0_IRQn
#define	PIO0_IRQ_1_C1_IRQn			PIO0_IRQ_1_IRQn
#define	PIO1_IRQ_0_C1_IRQn			PIO1_IRQ_0_IRQn
#define	PIO1_IRQ_1_C1_IRQn			PIO1_IRQ_1_IRQn
#define	PIO2_IRQ_0_C1_IRQn			PIO2_IRQ_0_IRQn
#define	PIO2_IRQ_1_C1_IRQn			PIO2_IRQ_1_IRQn
#define	IO_IRQ_BANK0_C1_IRQn		IO_IRQ_BANK0_IRQn
#define	IO_IRQ_BANK0_NS_C1_IRQn		IO_IRQ_BANK0_NS_IRQn
#define	IO_IRQ_QSPI_C1_IRQn			IO_IRQ_QSPI_IRQn
#define	IO_IRQ_QSPI_NS_C1_IRQn		IO_IRQ_QSPI_NS_IRQn
#define	SIO_IRQ_FIFO_C1_IRQn		SIO_IRQ_FIFO_IRQn
#define	SIO_IRQ_BELL_C1_IRQn		SIO_IRQ_BELL_IRQn
#define	SIO_IRQ_FIFO_NS_C1_IRQn		SIO_IRQ_FIFO_NS_IRQn
#define	SIO_IRQ_BELL_NS_C1_IRQn		SIO_IRQ_BELL_NS_IRQn
#define	SIO_IRQ_MTIMECMP_C1_IRQn	SIO_IRQ_MTIMECMP_IRQn
#define	CLOCKS_IRQ_C1_IRQn			CLOCKS_IRQ_IRQn
#define	SPI0_IRQ_C1_IRQn			SPI0_IRQ_IRQn
#define	SPI1_IRQ_C1_IRQn			SPI1_IRQ_IRQn
#define	UART0_IRQ_C1_IRQn			UART0_IRQ_IRQn
#define	UART1_IRQ_C1_IRQn			UART1_IRQ_IRQn
#define	ADC_IRQ_FIFO_C1_IRQn		ADC_IRQ_FIFO_IRQn
#define	I2C0_IRQ_C1_IRQn			I2C0_IRQ_IRQn
#define	I2C1_IRQ_C1_IRQn			I2C1_IRQ_IRQn
#define	OTP_IRQ_C1_IRQn				OTP_IRQ_IRQn
#define	TRNG_IRQ_C1_IRQn			TRNG_IRQ_IRQn
#define	PLL_SYS_IRQ_C1_IRQn			PLL_SYS_IRQ_IRQn
#define	PLL_USB_IRQ_C1_IRQn			PLL_USB_IRQ_IRQn
#define	POWMAN_IRQ_POW_C1_IRQn		POWMAN_IRQ_POW_IRQn
#define	POWMAN_IRQ_TIMER_C1_IRQn	POWMAN_IRQ_TIMER_IRQn

#endif // __riscv

// Prototypes

#ifdef __cplusplus
extern	"C" {
#endif

// For the core 0
// --------------

#if defined(__riscv)

// RISC-V Exceptions

void	InstructionAddressMisaligned_C0_IRQHandler(void);
void	InstructionAccessFault_C0_IRQHandler(void);
void	IllegalInstruction_C0_IRQHandler(void);
void	Breakpoint_C0_IRQHandler(void);
void	LoadAddressMisaligned_C0_IRQHandler(void);
void	LoadAccessFault_C0_IRQHandler(void);
void	StoreAddressMisaligned_C0_IRQHandler(void);
void	StoreAccessFault_C0_IRQHandler(void);
void	ECallUser_C0_IRQHandler(void);
void	ECallSupervisor_C0_IRQHandler(void);
void	ECallMachine_C0_IRQHandler(void);
void	InstructionPageFault_C0_IRQHandler(void);
void	LoadPageFault_C0_IRQHandler(void);
void	StorePageFault_C0_IRQHandler(void);

// RISC-V Machine-mode Interrupts

void	MSIP_C0_IRQHandler(void);
void	MTIP_C0_IRQHandler(void);
void	MEIP_C0_IRQHandler(void);

#else // ARM

// ARM Exceptions

void	NonMaskableInt_C0_IRQHandler(void);
void	HardFault_C0_IRQHandler(void);
void	MemoryManagement_C0_IRQHandler(void);
void	BusFault_C0_IRQHandler(void);
void	UsageFault_C0_IRQHandler(void);
void	SecureFault_C0_IRQHandler(void);
void	SVCall_C0_IRQHandler(void);
void	DebugMonitor_C0_IRQHandler(void);
void	PendSV_C0_IRQHandler(void);
void	SysTick_C0_IRQHandler(void);

#endif // __riscv

// Peripheral IRQHandlers (same for ARM and RISC-V)

void	TIMER0_IRQ_0_C0_IRQHandler(void);
void	TIMER0_IRQ_1_C0_IRQHandler(void);
void	TIMER0_IRQ_2_C0_IRQHandler(void);
void	TIMER0_IRQ_3_C0_IRQHandler(void);
void	TIMER1_IRQ_0_C0_IRQHandler(void);
void	TIMER1_IRQ_1_C0_IRQHandler(void);
void	TIMER1_IRQ_2_C0_IRQHandler(void);
void	TIMER1_IRQ_3_C0_IRQHandler(void);
void	PWM_IRQ_WRAP_0_C0_IRQHandler(void);
void	PWM_IRQ_WRAP_1_C0_IRQHandler(void);
void	DMA_IRQ_0_C0_IRQHandler(void);
void	DMA_IRQ_1_C0_IRQHandler(void);
void	DMA_IRQ_2_C0_IRQHandler(void);
void	DMA_IRQ_3_C0_IRQHandler(void);
void	USBCTRL_IRQ_C0_IRQHandler(void);
void	PIO0_IRQ_0_C0_IRQHandler(void);
void	PIO0_IRQ_1_C0_IRQHandler(void);
void	PIO1_IRQ_0_C0_IRQHandler(void);
void	PIO1_IRQ_1_C0_IRQHandler(void);
void	PIO2_IRQ_0_C0_IRQHandler(void);
void	PIO2_IRQ_1_C0_IRQHandler(void);
void	IO_IRQ_BANK0_C0_IRQHandler(void);
void	IO_IRQ_BANK0_NS_C0_IRQHandler(void);
void	IO_IRQ_QSPI_C0_IRQHandler(void);
void	IO_IRQ_QSPI_NS_C0_IRQHandler(void);
void	SIO_IRQ_FIFO_C0_IRQHandler(void);
void	SIO_IRQ_BELL_C0_IRQHandler(void);
void	SIO_IRQ_FIFO_NS_C0_IRQHandler(void);
void	SIO_IRQ_BELL_NS_C0_IRQHandler(void);
void	SIO_IRQ_MTIMECMP_C0_IRQHandler(void);
void	CLOCKS_IRQ_C0_IRQHandler(void);
void	SPI0_IRQ_C0_IRQHandler(void);
void	SPI1_IRQ_C0_IRQHandler(void);
void	UART0_IRQ_C0_IRQHandler(void);
void	UART1_IRQ_C0_IRQHandler(void);
void	ADC_IRQ_FIFO_C0_IRQHandler(void);
void	I2C0_IRQ_C0_IRQHandler(void);
void	I2C1_IRQ_C0_IRQHandler(void);
void	OTP_IRQ_C0_IRQHandler(void);
void	TRNG_IRQ_C0_IRQHandler(void);
void	PLL_SYS_IRQ_C0_IRQHandler(void);
void	PLL_USB_IRQ_C0_IRQHandler(void);
void	POWMAN_IRQ_POW_C0_IRQHandler(void);
void	POWMAN_IRQ_TIMER_C0_IRQHandler(void);

// For the core 1
// --------------

#if defined(__riscv)

// RISC-V Exceptions

void	InstructionAddressMisaligned_C1_IRQHandler(void);
void	InstructionAccessFault_C1_IRQHandler(void);
void	IllegalInstruction_C1_IRQHandler(void);
void	Breakpoint_C1_IRQHandler(void);
void	LoadAddressMisaligned_C1_IRQHandler(void);
void	LoadAccessFault_C1_IRQHandler(void);
void	StoreAddressMisaligned_C1_IRQHandler(void);
void	StoreAccessFault_C1_IRQHandler(void);
void	ECallUser_C1_IRQHandler(void);
void	ECallSupervisor_C1_IRQHandler(void);
void	ECallMachine_C1_IRQHandler(void);
void	InstructionPageFault_C1_IRQHandler(void);
void	LoadPageFault_C1_IRQHandler(void);
void	StorePageFault_C1_IRQHandler(void);

// RISC-V Machine-mode Interrupts

void	MSIP_C1_IRQHandler(void);
void	MTIP_C1_IRQHandler(void);
void	MEIP_C1_IRQHandler(void);

#else // ARM

// ARM Exceptions

void	NonMaskableInt_C1_IRQHandler(void);
void	HardFault_C1_IRQHandler(void);
void	MemoryManagement_C1_IRQHandler(void);
void	BusFault_C1_IRQHandler(void);
void	UsageFault_C1_IRQHandler(void);
void	SecureFault_C1_IRQHandler(void);
void	SVCall_C1_IRQHandler(void);
void	DebugMonitor_C1_IRQHandler(void);
void	PendSV_C1_IRQHandler(void);
void	SysTick_C1_IRQHandler(void);

#endif // __riscv

// Peripheral IRQHandlers (same for ARM and RISC-V)

void	TIMER0_IRQ_0_C1_IRQHandler(void);
void	TIMER0_IRQ_1_C1_IRQHandler(void);
void	TIMER0_IRQ_2_C1_IRQHandler(void);
void	TIMER0_IRQ_3_C1_IRQHandler(void);
void	TIMER1_IRQ_0_C1_IRQHandler(void);
void	TIMER1_IRQ_1_C1_IRQHandler(void);
void	TIMER1_IRQ_2_C1_IRQHandler(void);
void	TIMER1_IRQ_3_C1_IRQHandler(void);
void	PWM_IRQ_WRAP_0_C1_IRQHandler(void);
void	PWM_IRQ_WRAP_1_C1_IRQHandler(void);
void	DMA_IRQ_0_C1_IRQHandler(void);
void	DMA_IRQ_1_C1_IRQHandler(void);
void	DMA_IRQ_2_C1_IRQHandler(void);
void	DMA_IRQ_3_C1_IRQHandler(void);
void	USBCTRL_IRQ_C1_IRQHandler(void);
void	PIO0_IRQ_0_C1_IRQHandler(void);
void	PIO0_IRQ_1_C1_IRQHandler(void);
void	PIO1_IRQ_0_C1_IRQHandler(void);
void	PIO1_IRQ_1_C1_IRQHandler(void);
void	PIO2_IRQ_0_C1_IRQHandler(void);
void	PIO2_IRQ_1_C1_IRQHandler(void);
void	IO_IRQ_BANK0_C1_IRQHandler(void);
void	IO_IRQ_BANK0_NS_C1_IRQHandler(void);
void	IO_IRQ_QSPI_C1_IRQHandler(void);
void	IO_IRQ_QSPI_NS_C1_IRQHandler(void);
void	SIO_IRQ_FIFO_C1_IRQHandler(void);
void	SIO_IRQ_BELL_C1_IRQHandler(void);
void	SIO_IRQ_FIFO_NS_C1_IRQHandler(void);
void	SIO_IRQ_BELL_NS_C1_IRQHandler(void);
void	SIO_IRQ_MTIMECMP_C1_IRQHandler(void);
void	CLOCKS_IRQ_C1_IRQHandler(void);
void	SPI0_IRQ_C1_IRQHandler(void);
void	SPI1_IRQ_C1_IRQHandler(void);
void	UART0_IRQ_C1_IRQHandler(void);
void	UART1_IRQ_C1_IRQHandler(void);
void	ADC_IRQ_FIFO_C1_IRQHandler(void);
void	I2C0_IRQ_C1_IRQHandler(void);
void	I2C1_IRQ_C1_IRQHandler(void);
void	OTP_IRQ_C1_IRQHandler(void);
void	TRNG_IRQ_C1_IRQHandler(void);
void	PLL_SYS_IRQ_C1_IRQHandler(void);
void	PLL_USB_IRQ_C1_IRQHandler(void);
void	POWMAN_IRQ_POW_C1_IRQHandler(void);
void	POWMAN_IRQ_TIMER_C1_IRQHandler(void);

#ifdef __cplusplus
}
#endif
