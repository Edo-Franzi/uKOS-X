/*
; vectors.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Vectors of the machine.
;			See the link.ld file
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

.section		.restart, "ax", %progbits
start_base:		j			Reset_C0_Handler
				.fill		(512-4), 1, 0x55

.section		.vectors
vector_base:	.word		0
				.word		0
				.word		0
				.word		MSIP_C0_IRQHandler
				.word		0
				.word		0
				.word		0
				.word		MTIP_C0_IRQHandler
				.word		0
				.word		0
				.word		0
				.word		0
				.word		0
				.word		0
				.word		0
				.word		0
				.word		0
				.word		BWEI_C0_IRQHandler
				.word		PMOVI_C0_IRQHandler

				.word		WWDGT_C0_IRQHandler
				.word		LVD_C0_IRQHandler
				.word		TAMPER_C0_IRQHandler
				.word		RTC_C0_IRQHandler
				.word		FMC_C0_IRQHandler
				.word		RCU_CTC_C0_IRQHandler
				.word		EXTI0_C0_IRQHandler
				.word		EXTI1_C0_IRQHandler
				.word		EXTI2_C0_IRQHandler
				.word		EXTI3_C0_IRQHandler
				.word		EXTI4_C0_IRQHandler
				.word		DMA0_Channel0_C0_IRQHandler
				.word		DMA0_Channel1_C0_IRQHandler
				.word		DMA0_Channel2_C0_IRQHandler
				.word		DMA0_Channel3_C0_IRQHandler
				.word		DMA0_Channel4_C0_IRQHandler
				.word		DMA0_Channel5_C0_IRQHandler
				.word		DMA0_Channel6_C0_IRQHandler
				.word		ADC0_1_C0_IRQHandler
				.word		CAN0_TX_C0_IRQHandler
				.word		CAN0_RX0_C0_IRQHandler
				.word		CAN0_RX1_C0_IRQHandler
				.word		CAN0_EWMC_C0_IRQHandler
				.word		EXTI5_9_C0_IRQHandler
				.word		TIMER0_BRK_C0_IRQHandler
				.word		TIMER0_UP_C0_IRQHandler
				.word		TIMER0_TRG_CMT_C0_IRQHandler
				.word		TIMER0_Channel_C0_IRQHandler
				.word		TIMER1_C0_IRQHandler
				.word		TIMER2_C0_IRQHandler
				.word		TIMER3_C0_IRQHandler
				.word		I2C0_EV_C0_IRQHandler
				.word		I2C0_ER_C0_IRQHandler
				.word		I2C1_EV_C0_IRQHandler
				.word		I2C1_ER_C0_IRQHandler
				.word		SPI0_C0_IRQHandler
				.word		SPI1_C0_IRQHandler
				.word		USART0_C0_IRQHandler
				.word		USART1_C0_IRQHandler
				.word		USART2_C0_IRQHandler
				.word		EXTI10_15_C0_IRQHandler
				.word		RTC_Alarm_C0_IRQHandler
				.word		USBFS_WKUP_C0_IRQHandler
				.word		0
				.word		0
				.word		0
				.word		0
				.word		0
				.word		EXMC_C0_IRQHandler
				.word		0
				.word		TIMER4_C0_IRQHandler
				.word		SPI2_C0_IRQHandler
				.word		UART3_C0_IRQHandler
				.word		UART4_C0_IRQHandler
				.word		TIMER5_C0_IRQHandler
				.word		TIMER6_C0_IRQHandler
				.word		DMA1_Channel0_C0_IRQHandler
				.word		DMA1_Channel1_C0_IRQHandler
				.word		DMA1_Channel2_C0_IRQHandler
				.word		DMA1_Channel3_C0_IRQHandler
				.word		DMA1_Channel4_C0_IRQHandler
				.word		0
				.word		0
				.word		CAN1_TX_C0_IRQHandler
				.word		CAN1_RX0_C0_IRQHandler
				.word		CAN1_RX1_C0_IRQHandler
				.word		CAN1_EWMC_C0_IRQHandler
				.word		USBFS_C0_IRQHandler
