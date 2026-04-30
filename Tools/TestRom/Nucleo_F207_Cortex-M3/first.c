/*
; first.
; ======

; SPDX-License-Identifier: MIT

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

extern	void		Reset_C0_Handler(void);
extern	void		crt0(void);

const	uintptr_t	g_pfnVectors_C0[] __attribute__ ((used, section(".isr_vector"))) = {

	(uintptr_t)linker_topStackSystem_C0,						// MSP Stack

// Cortex-M3 Processor Exceptions Numbers

	(uintptr_t)Reset_C0_Handler,								// Address: 0x0000_0004
	(uintptr_t)NonMaskableInt_C0_IRQHandler,					// Address: 0x0000_0008
	(uintptr_t)HardFault_C0_IRQHandler,							// Address: 0x0000_000C
	(uintptr_t)MemoryManagement_C0_IRQHandler,					// Address: 0x0000_0010
	(uintptr_t)BusFault_C0_IRQHandler,							// Address: 0x0000_0014
	(uintptr_t)UsageFault_C0_IRQHandler,						// Address: 0x0000_0018
	(uintptr_t)0,												// Address: 0x0000_001C
	(uintptr_t)0,												// Address: 0x0000_0020
	(uintptr_t)0,												// Address: 0x0000_0024
	(uintptr_t)0,												// Address: 0x0000_0028
	(uintptr_t)SVCall_C0_IRQHandler,							// Address: 0x0000_002C
	(uintptr_t)DebugMonitor_C0_IRQHandler,						// Address: 0x0000_0030
	(uintptr_t)0,												// Address: 0x0000_0034
	(uintptr_t)PendSV_C0_IRQHandler,							// Address: 0x0000_0038
	(uintptr_t)SysTick_C0_IRQHandler,							// Address: 0x0000_003C

// STM32 specific Interrupt Numbers

	(uintptr_t)WWDG_C0_IRQHandler,								// Address: 0x0000_0040
	(uintptr_t)PVD_C0_IRQHandler,								// Address: 0x0000_0044
	(uintptr_t)TAMP_STAMP_C0_IRQHandler,						// Address: 0x0000_0048
	(uintptr_t)RTC_WKUP_C0_IRQHandler,							// Address: 0x0000_004C
	(uintptr_t)FLASH_C0_IRQHandler,								// Address: 0x0000_0050
	(uintptr_t)RCC_C0_IRQHandler,								// Address: 0x0000_0054
	(uintptr_t)EXTI0_C0_IRQHandler,								// Address: 0x0000_0058
	(uintptr_t)EXTI1_C0_IRQHandler,								// Address: 0x0000_005C
	(uintptr_t)EXTI2_C0_IRQHandler,								// Address: 0x0000_0060
	(uintptr_t)EXTI3_C0_IRQHandler,								// Address: 0x0000_0064
	(uintptr_t)EXTI4_C0_IRQHandler,								// Address: 0x0000_0068
	(uintptr_t)DMA1_STREAM0_C0_IRQHandler,						// Address: 0x0000_006C
	(uintptr_t)DMA1_STREAM1_C0_IRQHandler,						// Address: 0x0000_0070
	(uintptr_t)DMA1_STREAM2_C0_IRQHandler,						// Address: 0x0000_0074
	(uintptr_t)DMA1_STREAM3_C0_IRQHandler,						// Address: 0x0000_0078
	(uintptr_t)DMA1_STREAM4_C0_IRQHandler,						// Address: 0x0000_007C
	(uintptr_t)DMA1_STREAM5_C0_IRQHandler,						// Address: 0x0000_0080
	(uintptr_t)DMA1_STREAM6_C0_IRQHandler,						// Address: 0x0000_0084
	(uintptr_t)ADC_C0_IRQHandler,								// Address: 0x0000_0088
	(uintptr_t)CAN1_TX_C0_IRQHandler,							// Address: 0x0000_008C
	(uintptr_t)CAN1_RX0_C0_IRQHandler,							// Address: 0x0000_0090
	(uintptr_t)CAN1_RX1_C0_IRQHandler,							// Address: 0x0000_0094
	(uintptr_t)CAN1_SCE_C0_IRQHandler,							// Address: 0x0000_0098
	(uintptr_t)EXTI9_5_C0_IRQHandler,							// Address: 0x0000_009C
	(uintptr_t)TIM1_BRK_TIM9_C0_IRQHandler,						// Address: 0x0000_00A0
	(uintptr_t)TIM1_UP_TIM10_C0_IRQHandler,						// Address: 0x0000_00A4
	(uintptr_t)TIM1_TRG_COM_TIM11_C0_IRQHandler,				// Address: 0x0000_00A8
	(uintptr_t)TIM1_CC_C0_IRQHandler,							// Address: 0x0000_00AC
	(uintptr_t)TIM2_C0_IRQHandler,								// Address: 0x0000_00B0
	(uintptr_t)TIM3_C0_IRQHandler,								// Address: 0x0000_00B4
	(uintptr_t)TIM4_C0_IRQHandler,								// Address: 0x0000_00B8
	(uintptr_t)I2C1_EV_C0_IRQHandler,							// Address: 0x0000_00BC
	(uintptr_t)I2C1_ER_C0_IRQHandler,							// Address: 0x0000_00C0
	(uintptr_t)I2C2_EV_C0_IRQHandler,							// Address: 0x0000_00C4
	(uintptr_t)I2C2_ER_C0_IRQHandler,							// Address: 0x0000_00C8
	(uintptr_t)SPI1_C0_IRQHandler,								// Address: 0x0000_00CC
	(uintptr_t)SPI2_C0_IRQHandler,								// Address: 0x0000_00D0
	(uintptr_t)USART1_C0_IRQHandler,							// Address: 0x0000_00D4
	(uintptr_t)USART2_C0_IRQHandler,							// Address: 0x0000_00D8
	(uintptr_t)USART3_C0_IRQHandler,							// Address: 0x0000_00DC
	(uintptr_t)EXTI15_10_C0_IRQHandler,							// Address: 0x0000_00E0
	(uintptr_t)RTC_ALARM_C0_IRQHandler,							// Address: 0x0000_00E4
	(uintptr_t)OTG_FS_WKUP_C0_IRQHandler,						// Address: 0x0000_00E8
	(uintptr_t)TIM8_BRK_TIM12_C0_IRQHandler,					// Address: 0x0000_00EC
	(uintptr_t)TIM8_UP_TIM13_C0_IRQHandler,						// Address: 0x0000_00F0
	(uintptr_t)TIM8_TRG_COM_TIM14_C0_IRQHandler,				// Address: 0x0000_00F4
	(uintptr_t)TIM8_CC_C0_IRQHandler,							// Address: 0x0000_00F8
	(uintptr_t)DMA1_STREAM7_C0_IRQHandler,						// Address: 0x0000_00FC
	(uintptr_t)FSMC_C0_IRQHandler,								// Address: 0x0000_0100
	(uintptr_t)SDIO_C0_IRQHandler,								// Address: 0x0000_0104
	(uintptr_t)TIM5_C0_IRQHandler,								// Address: 0x0000_0108
	(uintptr_t)SPI3_C0_IRQHandler,								// Address: 0x0000_010C
	(uintptr_t)UART4_C0_IRQHandler,								// Address: 0x0000_0110
	(uintptr_t)UART5_C0_IRQHandler,								// Address: 0x0000_0114
	(uintptr_t)TIM6_DAC_C0_IRQHandler,							// Address: 0x0000_0118
	(uintptr_t)TIM7_C0_IRQHandler,								// Address: 0x0000_011C
	(uintptr_t)DMA2_STREAM0_C0_IRQHandler,						// Address: 0x0000_0120
	(uintptr_t)DMA2_STREAM1_C0_IRQHandler,						// Address: 0x0000_0124
	(uintptr_t)DMA2_STREAM2_C0_IRQHandler,						// Address: 0x0000_0128
	(uintptr_t)DMA2_STREAM3_C0_IRQHandler,						// Address: 0x0000_012C
	(uintptr_t)DMA2_STREAM4_C0_IRQHandler,						// Address: 0x0000_0130
	(uintptr_t)ETH_C0_IRQHandler,								// Address: 0x0000_0134
	(uintptr_t)ETH_WKUP_C0_IRQHandler,							// Address: 0x0000_0138
	(uintptr_t)CAN2_TX_C0_IRQHandler,							// Address: 0x0000_013C
	(uintptr_t)CAN2_RX0_C0_IRQHandler,							// Address: 0x0000_0140
	(uintptr_t)CAN2_RX1_C0_IRQHandler,							// Address: 0x0000_0144
	(uintptr_t)CAN2_SCE_C0_IRQHandler,							// Address: 0x0000_0148
	(uintptr_t)OTG_FS_C0_IRQHandler,							// Address: 0x0000_014C
	(uintptr_t)DMA2_STREAM5_C0_IRQHandler,						// Address: 0x0000_0150
	(uintptr_t)DMA2_STREAM6_C0_IRQHandler,						// Address: 0x0000_0154
	(uintptr_t)DMA2_STREAM7_C0_IRQHandler,						// Address: 0x0000_0158
	(uintptr_t)USART6_C0_IRQHandler,							// Address: 0x0000_015C
	(uintptr_t)I2C3_EV_C0_IRQHandler,							// Address: 0x0000_0160
	(uintptr_t)I2C3_ER_C0_IRQHandler,							// Address: 0x0000_0164
	(uintptr_t)OTG_HS_EP1_OUT_C0_IRQHandler,					// Address: 0x0000_0168
	(uintptr_t)OTG_HS_EP1_IN_C0_IRQHandler,						// Address: 0x0000_016C
	(uintptr_t)OTG_HS_WKUP_C0_IRQHandler,						// Address: 0x0000_0170
	(uintptr_t)OTG_HS_C0_IRQHandler,							// Address: 0x0000_0174
	(uintptr_t)DCMI_C0_IRQHandler,								// Address: 0x0000_0178
	(uintptr_t)CRYP_C0_IRQHandler,								// Address: 0x0000_017C
	(uintptr_t)HASH_RNG_C0_IRQHandler							// Address: 0x0000_0180
};

EXCEPTION_SPECIFIC_HANDLER(NonMaskableInt_C0)
EXCEPTION_SPECIFIC_HANDLER(HardFault_C0)
EXCEPTION_SPECIFIC_HANDLER(MemoryManagement_C0)
EXCEPTION_SPECIFIC_HANDLER(BusFault_C0)
EXCEPTION_SPECIFIC_HANDLER(UsageFault_C0)
EXCEPTION_SPECIFIC_HANDLER(SVCall_C0)
EXCEPTION_SPECIFIC_HANDLER(DebugMonitor_C0)
EXCEPTION_SPECIFIC_HANDLER(PendSV_C0)
EXCEPTION_SPECIFIC_HANDLER(SysTick_C0)

// cppcheck-suppress-begin premium-unreadVariable
//
INTERRUPT_SPECIFIC_HANDLER(WWDG_C0)
INTERRUPT_SPECIFIC_HANDLER(PVD_C0)
INTERRUPT_SPECIFIC_HANDLER(TAMP_STAMP_C0)
INTERRUPT_SPECIFIC_HANDLER(RTC_WKUP_C0)
INTERRUPT_SPECIFIC_HANDLER(FLASH_C0)
INTERRUPT_SPECIFIC_HANDLER(RCC_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI0_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI1_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI2_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI3_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI4_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA1_STREAM0_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA1_STREAM1_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA1_STREAM2_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA1_STREAM3_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA1_STREAM4_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA1_STREAM5_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA1_STREAM6_C0)
INTERRUPT_SPECIFIC_HANDLER(ADC_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN1_TX_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN1_RX0_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN1_RX1_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN1_SCE_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI9_5_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM1_BRK_TIM9_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM1_UP_TIM10_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM1_TRG_COM_TIM11_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM1_CC_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM2_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM3_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM4_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C1_EV_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C1_ER_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C2_EV_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C2_ER_C0)
INTERRUPT_SPECIFIC_HANDLER(SPI1_C0)
INTERRUPT_SPECIFIC_HANDLER(SPI2_C0)
INTERRUPT_SPECIFIC_HANDLER(USART1_C0)
INTERRUPT_SPECIFIC_HANDLER(USART2_C0)
INTERRUPT_SPECIFIC_HANDLER(USART3_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI15_10_C0)
INTERRUPT_SPECIFIC_HANDLER(RTC_ALARM_C0)
INTERRUPT_SPECIFIC_HANDLER(OTG_FS_WKUP_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM8_BRK_TIM12_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM8_UP_TIM13_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM8_TRG_COM_TIM14_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM8_CC_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA1_STREAM7_C0)
INTERRUPT_SPECIFIC_HANDLER(FSMC_C0)
INTERRUPT_SPECIFIC_HANDLER(SDIO_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM5_C0)
INTERRUPT_SPECIFIC_HANDLER(SPI3_C0)
INTERRUPT_SPECIFIC_HANDLER(UART4_C0)
INTERRUPT_SPECIFIC_HANDLER(UART5_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM6_DAC_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM7_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA2_STREAM0_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA2_STREAM1_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA2_STREAM2_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA2_STREAM3_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA2_STREAM4_C0)
INTERRUPT_SPECIFIC_HANDLER(ETH_C0)
INTERRUPT_SPECIFIC_HANDLER(ETH_WKUP_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN2_TX_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN2_RX0_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN2_RX1_C0)
INTERRUPT_SPECIFIC_HANDLER(CAN2_SCE_C0)
INTERRUPT_SPECIFIC_HANDLER(OTG_FS_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA2_STREAM5_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA2_STREAM6_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA2_STREAM7_C0)
INTERRUPT_SPECIFIC_HANDLER(USART6_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C3_EV_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C3_ER_C0)
INTERRUPT_SPECIFIC_HANDLER(OTG_HS_EP1_OUT_C0)
INTERRUPT_SPECIFIC_HANDLER(OTG_HS_EP1_IN_C0)
INTERRUPT_SPECIFIC_HANDLER(OTG_HS_WKUP_C0)
INTERRUPT_SPECIFIC_HANDLER(OTG_HS_C0)
INTERRUPT_SPECIFIC_HANDLER(DCMI_C0)
INTERRUPT_SPECIFIC_HANDLER(CRYP_C0)
INTERRUPT_SPECIFIC_HANDLER(HASH_RNG_C0)

// cppcheck-suppress-end premium-unreadVariable

/*
 * \brief Reset_C0_Handler
 *
 * - Call the crt0
 *
 */
void	Reset_C0_Handler(void) {

	RCC->AHB1ENR |= RCC_AHB1ENR_BKPSRAMEN;

	SET_THREAD_STACK(linker_topStackFirst_C0);

	crt0();
}
