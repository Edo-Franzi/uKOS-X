/*
; first.
; ======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

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

// cppcheck-suppress-begin premium-unreadVariable
//
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

	cmns_wait(1000000);

	SET_MSP_STACK(linker_topStackSystem_C1);
	SET_THREAD_STACK(linker_topStackFirst_C1);

	crt0();
}
