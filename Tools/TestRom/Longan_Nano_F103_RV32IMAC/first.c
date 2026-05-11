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

#include	"tests.h"
#include	"linker.h"

// Vector table: ...
// However rather than start at zero the vector table starts at address 0x00000004,
// the first four bytes are used to store the starting address of the stack pointer.

// Prototypes

extern	void	crt0(void);

/*
 * \brief Reset_C0_Handler
 *
 * This code is called directly by the reset handler
 * - Correct the return address if it is not located inside the FLASH area
 * - Initialise the first stack
 * - call the crt0
 *
 */
[[gnu::noinline]]
void	local_fixPC(void) {
	register	uint32_t	regRa;

	__asm volatile ("add	%0,ra,zero" : "=r" (regRa));

// Check if the return address is below the flash
// Move the return address into the flash area

	if (regRa < 0x08000000) {
		regRa |= 0x08000000;

		__asm volatile ("add	ra,%0,zero" : : "r" (regRa));
	}
}

[[gnu::naked]]
void	Reset_C0_Handler(void) {

	CALL_FNCT(local_fixPC);

// Initialise the first stack
// Continue with the crt0

	__asm volatile ("la	sp,linker_topStackFirst_C0");

	CALL_FNCT(crt0);
}

EXCEPTION_SPECIFIC_HANDLER(MSIP_C0)
EXCEPTION_SPECIFIC_HANDLER(MTIP_C0)
EXCEPTION_SPECIFIC_HANDLER(BWEI_C0)
EXCEPTION_SPECIFIC_HANDLER(PMOVI_C0)

// cppcheck-suppress-begin premium-unreadVariable
//
INTERRUPT_SPECIFIC_HANDLER(WWDGT_C0)
INTERRUPT_SPECIFIC_HANDLER(LVD_C0)
INTERRUPT_SPECIFIC_HANDLER(TAMPER_C0)
INTERRUPT_SPECIFIC_HANDLER(RTC_C0)
INTERRUPT_SPECIFIC_HANDLER(FMC_C0)
INTERRUPT_SPECIFIC_HANDLER(RCU_CTC_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI0_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI1_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI2_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI3_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI4_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA0_Channel0_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA0_Channel1_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA0_Channel2_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA0_Channel3_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA0_Channel4_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA0_Channel5_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA0_Channel6_C0)
INTERRUPT_SPECIFIC_HANDLER(ADC0_1_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN0_TX_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN0_RX0_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN0_RX1_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN0_EWMC_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI5_9_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER0_BRK_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER0_UP_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER0_TRG_CMT_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER0_Channel_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER1_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER2_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER3_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C0_EV_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C0_ER_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C1_EV_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C1_ER_C0)
INTERRUPT_SPECIFIC_HANDLER(SPI0_C0)
INTERRUPT_SPECIFIC_HANDLER(SPI1_C0)
INTERRUPT_SPECIFIC_HANDLER(USART0_C0)
INTERRUPT_SPECIFIC_HANDLER(USART1_C0)
INTERRUPT_SPECIFIC_HANDLER(USART2_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI10_15_C0)
INTERRUPT_SPECIFIC_HANDLER(RTC_Alarm_C0)
INTERRUPT_SPECIFIC_HANDLER(USBFS_WKUP_C0)
INTERRUPT_SPECIFIC_HANDLER(EXMC_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER4_C0)
INTERRUPT_SPECIFIC_HANDLER(SPI2_C0)
INTERRUPT_SPECIFIC_HANDLER(UART3_C0)
INTERRUPT_SPECIFIC_HANDLER(UART4_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER5_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER6_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA1_Channel0_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA1_Channel1_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA1_Channel2_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA1_Channel3_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA1_Channel4_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN1_TX_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN1_RX0_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN1_RX1_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN1_EWMC_C0)
INTERRUPT_SPECIFIC_HANDLER(USBFS_C0)

// cppcheck-suppress-end premium-unreadVariable
