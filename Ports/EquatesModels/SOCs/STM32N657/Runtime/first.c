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

extern	void		Reset_C0_Handler(void);
extern	void		crt0(void);

[[gnu::used, gnu::section(".isr_vector")]]
const	uintptr_t	g_pfnVectors_C0[] = {


	(uintptr_t)linker_topStackSystem_C0,						// MSP Stack

// Cortex-M55 Processor Exceptions Numbers

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

// STM32 specific Interrupt Numbers

	(uintptr_t)PVD_PVM_C0_IRQHandler,							// Address: 0x0000_0040
	(uintptr_t)0,												// Address: 0x0000_0044
	(uintptr_t)DTS_C0_IRQHandler,								// Address: 0x0000_0048
	(uintptr_t)RCC_C0_IRQHandler,								// Address: 0x0000_004C
	(uintptr_t)LOCKUP_C0_IRQHandler,							// Address: 0x0000_0050
	(uintptr_t)CACHE_ECC_C0_IRQHandler,							// Address: 0x0000_0054
	(uintptr_t)TCM_ECC_C0_IRQHandler,							// Address: 0x0000_0058
	(uintptr_t)BCK_ECC_C0_IRQHandler,							// Address: 0x0000_005C
	(uintptr_t)FPU_C0_IRQHandler,								// Address: 0x0000_0060
	(uintptr_t)0,												// Address: 0x0000_0064
	(uintptr_t)RTC_S_C0_IRQHandler,								// Address: 0x0000_0068
	(uintptr_t)TAMP_C0_IRQHandler,								// Address: 0x0000_006C
	(uintptr_t)RIFSC_TAMPER_C0_IRQHandler,						// Address: 0x0000_0070
	(uintptr_t)IAC_C0_IRQHandler,								// Address: 0x0000_0074
	(uintptr_t)RCC_S_C0_IRQHandler,								// Address: 0x0000_0078
	(uintptr_t)0,												// Address: 0x0000_007C
	(uintptr_t)RTC_C0_IRQHandler,								// Address: 0x0000_0080
	(uintptr_t)0,												// Address: 0x0000_0084
	(uintptr_t)WDGLS_EARLY_C0_IRQHandler,						// Address: 0x0000_0088
	(uintptr_t)WWDG_EARLY_C0_IRQHandler,						// Address: 0x0000_008C
	(uintptr_t)EXTI0_C0_IRQHandler,								// Address: 0x0000_0090
	(uintptr_t)EXTI1_C0_IRQHandler,								// Address: 0x0000_0094
	(uintptr_t)EXTI2_C0_IRQHandler,								// Address: 0x0000_0098
	(uintptr_t)EXTI3_C0_IRQHandler,								// Address: 0x0000_009C
	(uintptr_t)EXTI4_C0_IRQHandler,								// Address: 0x0000_00A0
	(uintptr_t)EXTI5_C0_IRQHandler,								// Address: 0x0000_00A4
	(uintptr_t)EXTI6_C0_IRQHandler,								// Address: 0x0000_00A8
	(uintptr_t)EXTI7_C0_IRQHandler,								// Address: 0x0000_00AC
	(uintptr_t)EXTI8_C0_IRQHandler,								// Address: 0x0000_00B0
	(uintptr_t)EXTI9_C0_IRQHandler,								// Address: 0x0000_00B4
	(uintptr_t)EXTI10_C0_IRQHandler,							// Address: 0x0000_00B8
	(uintptr_t)EXTI11_C0_IRQHandler,							// Address: 0x0000_00BC
	(uintptr_t)EXTI12_C0_IRQHandler,							// Address: 0x0000_00C0
	(uintptr_t)EXTI13_C0_IRQHandler,							// Address: 0x0000_00C4
	(uintptr_t)EXTI14_C0_IRQHandler,							// Address: 0x0000_00C8
	(uintptr_t)EXTI15_C0_IRQHandler,							// Address: 0x0000_00CC
	(uintptr_t)SAES_C0_IRQHandler,								// Address: 0x0000_00D0
	(uintptr_t)CRYP_C0_IRQHandler,								// Address: 0x0000_00D4
	(uintptr_t)PKA_C0_IRQHandler,								// Address: 0x0000_00D8
	(uintptr_t)HASH_C0_IRQHandler,								// Address: 0x0000_00DC
	(uintptr_t)RNG_C0_IRQHandler,								// Address: 0x0000_00E0
	(uintptr_t)0,												// Address: 0x0000_00E4
	(uintptr_t)MCE1_C0_IRQHandler,								// Address: 0x0000_00E8
	(uintptr_t)MCE2_C0_IRQHandler,								// Address: 0x0000_00EC
	(uintptr_t)MCE3_C0_IRQHandler,								// Address: 0x0000_00F0
	(uintptr_t)MCE4_C0_IRQHandler,								// Address: 0x0000_00F4
	(uintptr_t)ADC12_C0_IRQHandler,								// Address: 0x0000_00F8
	(uintptr_t)CSI_DBG_C0_IRQHandler,							// Address: 0x0000_00FC
	(uintptr_t)DCMIPP_C0_IRQHandler,							// Address: 0x0000_0100
	(uintptr_t)0,												// Address: 0x0000_0104
	(uintptr_t)0,												// Address: 0x0000_0108
	(uintptr_t)0,												// Address: 0x0000_010C
	(uintptr_t)PAHB_ERR_C0_IRQHandler,							// Address: 0x0000_0110
	(uintptr_t)NPU_END_OF_EPOCH_C0_IRQHandler,					// Address: 0x0000_0114
	(uintptr_t)NPU1_C0_IRQHandler,								// Address: 0x0000_0118
	(uintptr_t)NPU2_C0_IRQHandler,								// Address: 0x0000_011C
	(uintptr_t)NPU3_C0_IRQHandler,								// Address: 0x0000_0120
	(uintptr_t)NPUCACHE_C0_IRQHandler,							// Address: 0x0000_0124
	(uintptr_t)LTDC_LO_C0_IRQHandler,							// Address: 0x0000_0128
	(uintptr_t)LTDC_LO_ERR_C0_IRQHandler,						// Address: 0x0000_012C
	(uintptr_t)DMA2D_C0_IRQHandler,								// Address: 0x0000_0130
	(uintptr_t)JPEG_C0_IRQHandler,								// Address: 0x0000_0134
	(uintptr_t)VENC_C0_IRQHandler,								// Address: 0x0000_0138
	(uintptr_t)GFXMMU_C0_IRQHandler,							// Address: 0x0000_013C
	(uintptr_t)GFXTIM_C0_IRQHandler,							// Address: 0x0000_0140
	(uintptr_t)GPU2D_C0_IRQHandler,								// Address: 0x0000_0144
	(uintptr_t)GPU2D_ERROR_C0_IRQHandler,						// Address: 0x0000_0148
	(uintptr_t)GPU_CACHE_C0_IRQHandler,							// Address: 0x0000_014C
	(uintptr_t)HPDMA1_CH0_C0_IRQHandler,						// Address: 0x0000_0150
	(uintptr_t)HPDMA1_CH1_C0_IRQHandler,						// Address: 0x0000_0154
	(uintptr_t)HPDMA1_CH2_C0_IRQHandler,						// Address: 0x0000_0158
	(uintptr_t)HPDMA1_CH3_C0_IRQHandler,						// Address: 0x0000_015C
	(uintptr_t)HPDMA1_CH4_C0_IRQHandler,						// Address: 0x0000_0160
	(uintptr_t)HPDMA1_CH5_C0_IRQHandler,						// Address: 0x0000_0164
	(uintptr_t)HPDMA1_CH6_C0_IRQHandler,						// Address: 0x0000_0168
	(uintptr_t)HPDMA1_CH7_C0_IRQHandler,						// Address: 0x0000_016C
	(uintptr_t)HPDMA1_CH8_C0_IRQHandler,						// Address: 0x0000_0170
	(uintptr_t)HPDMA1_CH9_C0_IRQHandler,						// Address: 0x0000_0174
	(uintptr_t)HPDMA1_CH10_C0_IRQHandler,						// Address: 0x0000_0178
	(uintptr_t)HPDMA1_CH11_C0_IRQHandler,						// Address: 0x0000_017C
	(uintptr_t)HPDMA1_CH12_C0_IRQHandler,						// Address: 0x0000_0180
	(uintptr_t)HPDMA1_CH13_C0_IRQHandler,						// Address: 0x0000_0184
	(uintptr_t)HPDMA1_CH14_C0_IRQHandler,						// Address: 0x0000_0188
	(uintptr_t)HPDMA1_CH15_C0_IRQHandler,						// Address: 0x0000_018C
	(uintptr_t)GPDMA1_CH0_C0_IRQHandler,						// Address: 0x0000_0190
	(uintptr_t)GPDMA1_CH1_C0_IRQHandler,						// Address: 0x0000_0194
	(uintptr_t)GPDMA1_CH2_C0_IRQHandler,						// Address: 0x0000_0198
	(uintptr_t)GPDMA1_CH3_C0_IRQHandler,						// Address: 0x0000_019C
	(uintptr_t)GPDMA1_CH4_C0_IRQHandler,						// Address: 0x0000_01A0
	(uintptr_t)GPDMA1_CH5_C0_IRQHandler,						// Address: 0x0000_01A4
	(uintptr_t)GPDMA1_CH6_C0_IRQHandler,						// Address: 0x0000_01A8
	(uintptr_t)GPDMA1_CH7_C0_IRQHandler,						// Address: 0x0000_01AC
	(uintptr_t)GPDMA1_CH8_C0_IRQHandler,						// Address: 0x0000_01B0
	(uintptr_t)GPDMA1_CH9_C0_IRQHandler,						// Address: 0x0000_01B4
	(uintptr_t)GPDMA1_CH10_C0_IRQHandler,						// Address: 0x0000_01B8
	(uintptr_t)GPDMA1_CH11_C0_IRQHandler,						// Address: 0x0000_01BC
	(uintptr_t)GPDMA1_CH12_C0_IRQHandler,						// Address: 0x0000_01C0
	(uintptr_t)GPDMA1_CH13_C0_IRQHandler,						// Address: 0x0000_01C4
	(uintptr_t)GPDMA1_CH14_C0_IRQHandler,						// Address: 0x0000_01C8
	(uintptr_t)GPDMA1_CH15_C0_IRQHandler,						// Address: 0x0000_01CC
	(uintptr_t)I2C1_EV_C0_IRQHandler,							// Address: 0x0000_01D0
	(uintptr_t)I2C1_ER_C0_IRQHandler,							// Address: 0x0000_01D4
	(uintptr_t)I2C2_EV_C0_IRQHandler,							// Address: 0x0000_01D8
	(uintptr_t)I2C2_ER_C0_IRQHandler,							// Address: 0x0000_01DC
	(uintptr_t)I2C3_EV_C0_IRQHandler,							// Address: 0x0000_01E0
	(uintptr_t)I2C3_ER_C0_IRQHandler,							// Address: 0x0000_01E4
	(uintptr_t)I2C4_EV_C0_IRQHandler,							// Address: 0x0000_01E8
	(uintptr_t)I2C4_ER_C0_IRQHandler,							// Address: 0x0000_01EC
	(uintptr_t)I3C1_EV_C0_IRQHandler,							// Address: 0x0000_01F0
	(uintptr_t)I3C1_ER_C0_IRQHandler,							// Address: 0x0000_01F4
	(uintptr_t)I3C2_EV_C0_IRQHandler,							// Address: 0x0000_01F8
	(uintptr_t)I3C2_ER_C0_IRQHandler,							// Address: 0x0000_01FC
	(uintptr_t)TIM1_BRK_C0_IRQHandler,							// Address: 0x0000_0200
	(uintptr_t)TIM1_UP_C0_IRQHandler,							// Address: 0x0000_0204
	(uintptr_t)TIM1_TRG_CCU_C0_IRQHandler,						// Address: 0x0000_0208
	(uintptr_t)TIM1_CC_C0_IRQHandler,							// Address: 0x0000_020C
	(uintptr_t)TIM2_C0_IRQHandler,								// Address: 0x0000_0210
	(uintptr_t)TIM3_C0_IRQHandler,								// Address: 0x0000_0214
	(uintptr_t)TIM4_C0_IRQHandler,								// Address: 0x0000_0218
	(uintptr_t)TIM5_C0_IRQHandler,								// Address: 0x0000_021C
	(uintptr_t)TIM6_C0_IRQHandler,								// Address: 0x0000_0220
	(uintptr_t)TIM7_C0_IRQHandler,								// Address: 0x0000_0224
	(uintptr_t)TIM8_BRK_C0_IRQHandler,							// Address: 0x0000_0228
	(uintptr_t)TIM8_UP_C0_IRQHandler,							// Address: 0x0000_022C
	(uintptr_t)TIM8_TRG_CCU_C0_IRQHandler,						// Address: 0x0000_0230
	(uintptr_t)TIM8_CC_C0_IRQHandler,							// Address: 0x0000_0234
	(uintptr_t)TIM9_C0_IRQHandler,								// Address: 0x0000_0238
	(uintptr_t)TIM10_C0_IRQHandler,								// Address: 0x0000_023C
	(uintptr_t)TIM11_C0_IRQHandler,								// Address: 0x0000_0240
	(uintptr_t)TIM12_C0_IRQHandler,								// Address: 0x0000_0244
	(uintptr_t)TIM13_C0_IRQHandler,								// Address: 0x0000_0248
	(uintptr_t)TIM14_C0_IRQHandler,								// Address: 0x0000_024C
	(uintptr_t)TIM15_C0_IRQHandler,								// Address: 0x0000_0250
	(uintptr_t)TIM16_C0_IRQHandler,								// Address: 0x0000_0254
	(uintptr_t)TIM17_C0_IRQHandler,								// Address: 0x0000_0258
	(uintptr_t)TIM18_C0_IRQHandler,								// Address: 0x0000_025C
	(uintptr_t)LPTIM1_C0_IRQHandler,							// Address: 0x0000_0260
	(uintptr_t)LPTIM2_C0_IRQHandler,							// Address: 0x0000_0264
	(uintptr_t)LPTIM3_C0_IRQHandler,							// Address: 0x0000_0268
	(uintptr_t)LPTIM4_C0_IRQHandler,							// Address: 0x0000_026C
	(uintptr_t)LPTIM5_C0_IRQHandler,							// Address: 0x0000_0270
	(uintptr_t)ADF1_FLT0_C0_IRQHandler,							// Address: 0x0000_0274
	(uintptr_t)MDF1_FLT0_C0_IRQHandler,							// Address: 0x0000_0278
	(uintptr_t)MDF1_FLT1_C0_IRQHandler,							// Address: 0x0000_027C
	(uintptr_t)MDF1_FLT2_C0_IRQHandler,							// Address: 0x0000_0280
	(uintptr_t)MDF1_FLT3_C0_IRQHandler,							// Address: 0x0000_0284
	(uintptr_t)MDF1_FLT4_C0_IRQHandler,							// Address: 0x0000_0288
	(uintptr_t)MDF1_FLT5_C0_IRQHandler,							// Address: 0x0000_028C
	(uintptr_t)SAI1_A_C0_IRQHandler,							// Address: 0x0000_0290
	(uintptr_t)SAI1_B_C0_IRQHandler,							// Address: 0x0000_0294
	(uintptr_t)SAI2_A_C0_IRQHandler,							// Address: 0x0000_0298
	(uintptr_t)SAI2_GLOBAL_B_C0_IRQHandler,						// Address: 0x0000_029C
	(uintptr_t)SPDIFRX_C0_IRQHandler,							// Address: 0x0000_02A0
	(uintptr_t)SPI1_C0_IRQHandler,								// Address: 0x0000_02A4
	(uintptr_t)SPI2_C0_IRQHandler,								// Address: 0x0000_02A8
	(uintptr_t)SPI3_C0_IRQHandler,								// Address: 0x0000_02AC
	(uintptr_t)SPI4_C0_IRQHandler,								// Address: 0x0000_02B0
	(uintptr_t)SPI5_C0_IRQHandler,								// Address: 0x0000_02B4
	(uintptr_t)SPI6_C0_IRQHandler,								// Address: 0x0000_02B8
	(uintptr_t)USART1_C0_IRQHandler,							// Address: 0x0000_02BC
	(uintptr_t)USART2_C0_IRQHandler,							// Address: 0x0000_02C0
	(uintptr_t)USART3_C0_IRQHandler,							// Address: 0x0000_02C4
	(uintptr_t)UART4_C0_IRQHandler,								// Address: 0x0000_02C8
	(uintptr_t)UART5_C0_IRQHandler,								// Address: 0x0000_02CC
	(uintptr_t)USART6_C0_IRQHandler,							// Address: 0x0000_02D0
	(uintptr_t)UART7_C0_IRQHandler,								// Address: 0x0000_02D4
	(uintptr_t)UART8_C0_IRQHandler,								// Address: 0x0000_02D8
	(uintptr_t)UART9_C0_IRQHandler,								// Address: 0x0000_02DC
	(uintptr_t)USART10_C0_IRQHandler,							// Address: 0x0000_02E0
	(uintptr_t)LPUART1_C0_IRQHandler,							// Address: 0x0000_02E4
	(uintptr_t)XSPI1_C0_IRQHandler,								// Address: 0x0000_02E8
	(uintptr_t)XSPI2_C0_IRQHandler,								// Address: 0x0000_02EC
	(uintptr_t)XSPI3_C0_IRQHandler,								// Address: 0x0000_02F0
	(uintptr_t)FMC_C0_IRQHandler,								// Address: 0x0000_02F4
	(uintptr_t)SDMMC1_C0_IRQHandler,							// Address: 0x0000_02F8
	(uintptr_t)SDMMC2_C0_IRQHandler,							// Address: 0x0000_02FC
	(uintptr_t)UCPD_C0_IRQHandler,								// Address: 0x0000_0300
	(uintptr_t)OTG1_C0_IRQHandler,								// Address: 0x0000_0304
	(uintptr_t)OTG2_C0_IRQHandler,								// Address: 0x0000_0308
	(uintptr_t)ETH1_C0_IRQHandler,								// Address: 0x0000_030C
	(uintptr_t)FDCAN1_IT0_C0_IRQHandler,						// Address: 0x0000_0310
	(uintptr_t)FDCAN1_IT1_C0_IRQHandler,						// Address: 0x0000_0314
	(uintptr_t)FDCAN2_IT0_C0_IRQHandler,						// Address: 0x0000_0318
	(uintptr_t)FDCAN2_IT1_C0_IRQHandler,						// Address: 0x0000_031C
	(uintptr_t)FDCAN3_IT0_C0_IRQHandler,						// Address: 0x0000_0320
	(uintptr_t)FDCAN3_IT1_C0_IRQHandler,						// Address: 0x0000_0324
	(uintptr_t)FDCAN_CU_C0_IRQHandler,							// Address: 0x0000_0328
	(uintptr_t)MDIOS_C0_IRQHandler,								// Address: 0x0000_032C
	(uintptr_t)DCMI_PSSI_C0_IRQHandler,							// Address: 0x0000_0330
	(uintptr_t)WAKEUP_PIN_C0_IRQHandler,						// Address: 0x0000_0334
	(uintptr_t)CTI0_C0_IRQHandler,								// Address: 0x0000_0338
	(uintptr_t)CTI1_C0_IRQHandler,								// Address: 0x0000_033C
	(uintptr_t)0,												// Address: 0x0000_0340
	(uintptr_t)LTDC_UP_C0_IRQHandler,							// Address: 0x0000_0344
	(uintptr_t)LTDC_UP_ERR_C0_IRQHandler						// Address: 0x0000_0348
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
INTERRUPT_SPECIFIC_HANDLER(PVD_PVM_C0)
INTERRUPT_SPECIFIC_HANDLER(DTS_C0)
INTERRUPT_SPECIFIC_HANDLER(RCC_C0)
INTERRUPT_SPECIFIC_HANDLER(LOCKUP_C0)
INTERRUPT_SPECIFIC_HANDLER(CACHE_ECC_C0)
INTERRUPT_SPECIFIC_HANDLER(TCM_ECC_C0)
INTERRUPT_SPECIFIC_HANDLER(BCK_ECC_C0)
INTERRUPT_SPECIFIC_HANDLER(FPU_C0)
INTERRUPT_SPECIFIC_HANDLER(RTC_S_C0)
INTERRUPT_SPECIFIC_HANDLER(TAMP_C0)
INTERRUPT_SPECIFIC_HANDLER(RIFSC_TAMPER_C0)
INTERRUPT_SPECIFIC_HANDLER(IAC_C0)
INTERRUPT_SPECIFIC_HANDLER(RCC_S_C0)
INTERRUPT_SPECIFIC_HANDLER(RTC_C0)
INTERRUPT_SPECIFIC_HANDLER(WDGLS_EARLY_C0)
INTERRUPT_SPECIFIC_HANDLER(WWDG_EARLY_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI0_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI1_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI2_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI3_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI4_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI5_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI6_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI7_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI8_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI9_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI10_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI11_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI12_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI13_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI14_C0)
INTERRUPT_SPECIFIC_HANDLER(EXTI15_C0)
INTERRUPT_SPECIFIC_HANDLER(SAES_C0)
INTERRUPT_SPECIFIC_HANDLER(CRYP_C0)
INTERRUPT_SPECIFIC_HANDLER(PKA_C0)
INTERRUPT_SPECIFIC_HANDLER(HASH_C0)
INTERRUPT_SPECIFIC_HANDLER(RNG_C0)
INTERRUPT_SPECIFIC_HANDLER(MCE1_C0)
INTERRUPT_SPECIFIC_HANDLER(MCE2_C0)
INTERRUPT_SPECIFIC_HANDLER(MCE3_C0)
INTERRUPT_SPECIFIC_HANDLER(MCE4_C0)
INTERRUPT_SPECIFIC_HANDLER(ADC12_C0)
INTERRUPT_SPECIFIC_HANDLER(CSI_DBG_C0)
INTERRUPT_SPECIFIC_HANDLER(DCMIPP_C0)
INTERRUPT_SPECIFIC_HANDLER(PAHB_ERR_C0)
INTERRUPT_SPECIFIC_HANDLER(NPU_END_OF_EPOCH_C0)
INTERRUPT_SPECIFIC_HANDLER(NPU1_C0)
INTERRUPT_SPECIFIC_HANDLER(NPU2_C0)
INTERRUPT_SPECIFIC_HANDLER(NPU3_C0)
INTERRUPT_SPECIFIC_HANDLER(NPUCACHE_C0)
INTERRUPT_SPECIFIC_HANDLER(LTDC_LO_C0)
INTERRUPT_SPECIFIC_HANDLER(LTDC_LO_ERR_C0)
INTERRUPT_SPECIFIC_HANDLER(DMA2D_C0)
INTERRUPT_SPECIFIC_HANDLER(JPEG_C0)
INTERRUPT_SPECIFIC_HANDLER(VENC_C0)
INTERRUPT_SPECIFIC_HANDLER(GFXMMU_C0)
INTERRUPT_SPECIFIC_HANDLER(GFXTIM_C0)
INTERRUPT_SPECIFIC_HANDLER(GPU2D_C0)
INTERRUPT_SPECIFIC_HANDLER(GPU2D_ERROR_C0)
INTERRUPT_SPECIFIC_HANDLER(GPU_CACHE_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH0_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH1_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH2_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH3_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH4_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH5_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH6_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH7_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH8_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH9_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH10_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH11_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH12_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH13_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH14_C0)
INTERRUPT_SPECIFIC_HANDLER(HPDMA1_CH15_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH0_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH1_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH2_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH3_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH4_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH5_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH6_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH7_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH8_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH9_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH10_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH11_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH12_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH13_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH14_C0)
INTERRUPT_SPECIFIC_HANDLER(GPDMA1_CH15_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C1_EV_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C1_ER_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C2_EV_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C2_ER_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C3_EV_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C3_ER_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C4_EV_C0)
INTERRUPT_SPECIFIC_HANDLER(I2C4_ER_C0)
INTERRUPT_SPECIFIC_HANDLER(I3C1_EV_C0)
INTERRUPT_SPECIFIC_HANDLER(I3C1_ER_C0)
INTERRUPT_SPECIFIC_HANDLER(I3C2_EV_C0)
INTERRUPT_SPECIFIC_HANDLER(I3C2_ER_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM1_BRK_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM1_UP_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM1_TRG_CCU_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM1_CC_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM2_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM3_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM4_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM5_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM6_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM7_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM8_BRK_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM8_UP_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM8_TRG_CCU_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM8_CC_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM9_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM10_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM11_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM12_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM13_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM14_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM15_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM16_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM17_C0)
INTERRUPT_SPECIFIC_HANDLER(TIM18_C0)
INTERRUPT_SPECIFIC_HANDLER(LPTIM1_C0)
INTERRUPT_SPECIFIC_HANDLER(LPTIM2_C0)
INTERRUPT_SPECIFIC_HANDLER(LPTIM3_C0)
INTERRUPT_SPECIFIC_HANDLER(LPTIM4_C0)
INTERRUPT_SPECIFIC_HANDLER(LPTIM5_C0)
INTERRUPT_SPECIFIC_HANDLER(ADF1_FLT0_C0)
INTERRUPT_SPECIFIC_HANDLER(MDF1_FLT0_C0)
INTERRUPT_SPECIFIC_HANDLER(MDF1_FLT1_C0)
INTERRUPT_SPECIFIC_HANDLER(MDF1_FLT2_C0)
INTERRUPT_SPECIFIC_HANDLER(MDF1_FLT3_C0)
INTERRUPT_SPECIFIC_HANDLER(MDF1_FLT4_C0)
INTERRUPT_SPECIFIC_HANDLER(MDF1_FLT5_C0)
INTERRUPT_SPECIFIC_HANDLER(SAI1_A_C0)
INTERRUPT_SPECIFIC_HANDLER(SAI1_B_C0)
INTERRUPT_SPECIFIC_HANDLER(SAI2_A_C0)
INTERRUPT_SPECIFIC_HANDLER(SAI2_GLOBAL_B_C0)
INTERRUPT_SPECIFIC_HANDLER(SPDIFRX_C0)
INTERRUPT_SPECIFIC_HANDLER(SPI1_C0)
INTERRUPT_SPECIFIC_HANDLER(SPI2_C0)
INTERRUPT_SPECIFIC_HANDLER(SPI3_C0)
INTERRUPT_SPECIFIC_HANDLER(SPI4_C0)
INTERRUPT_SPECIFIC_HANDLER(SPI5_C0)
INTERRUPT_SPECIFIC_HANDLER(SPI6_C0)
INTERRUPT_SPECIFIC_HANDLER(USART1_C0)
INTERRUPT_SPECIFIC_HANDLER(USART2_C0)
INTERRUPT_SPECIFIC_HANDLER(USART3_C0)
INTERRUPT_SPECIFIC_HANDLER(UART4_C0)
INTERRUPT_SPECIFIC_HANDLER(UART5_C0)
INTERRUPT_SPECIFIC_HANDLER(USART6_C0)
INTERRUPT_SPECIFIC_HANDLER(UART7_C0)
INTERRUPT_SPECIFIC_HANDLER(UART8_C0)
INTERRUPT_SPECIFIC_HANDLER(UART9_C0)
INTERRUPT_SPECIFIC_HANDLER(USART10_C0)
INTERRUPT_SPECIFIC_HANDLER(LPUART1_C0)
INTERRUPT_SPECIFIC_HANDLER(XSPI1_C0)
INTERRUPT_SPECIFIC_HANDLER(XSPI2_C0)
INTERRUPT_SPECIFIC_HANDLER(XSPI3_C0)
INTERRUPT_SPECIFIC_HANDLER(FMC_C0)
INTERRUPT_SPECIFIC_HANDLER(SDMMC1_C0)
INTERRUPT_SPECIFIC_HANDLER(SDMMC2_C0)
INTERRUPT_SPECIFIC_HANDLER(UCPD_C0)
INTERRUPT_SPECIFIC_HANDLER(OTG1_C0)
INTERRUPT_SPECIFIC_HANDLER(OTG2_C0)
INTERRUPT_SPECIFIC_HANDLER(ETH1_C0)
INTERRUPT_SPECIFIC_HANDLER(FDCAN1_IT0_C0)
INTERRUPT_SPECIFIC_HANDLER(FDCAN1_IT1_C0)
INTERRUPT_SPECIFIC_HANDLER(FDCAN2_IT0_C0)
INTERRUPT_SPECIFIC_HANDLER(FDCAN2_IT1_C0)
INTERRUPT_SPECIFIC_HANDLER(FDCAN3_IT0_C0)
INTERRUPT_SPECIFIC_HANDLER(FDCAN3_IT1_C0)
INTERRUPT_SPECIFIC_HANDLER(FDCAN_CU_C0)
INTERRUPT_SPECIFIC_HANDLER(MDIOS_C0)
INTERRUPT_SPECIFIC_HANDLER(DCMI_PSSI_C0)
INTERRUPT_SPECIFIC_HANDLER(WAKEUP_PIN_C0)
INTERRUPT_SPECIFIC_HANDLER(CTI0_C0)
INTERRUPT_SPECIFIC_HANDLER(CTI1_C0)
INTERRUPT_SPECIFIC_HANDLER(LTDC_UP_C0)
INTERRUPT_SPECIFIC_HANDLER(LTDC_UP_ERR_C0)

// cppcheck-suppress-end premium-unreadVariable

#undef	OZONE_S

/*
 * \brief Reset_C0_Handler
 *
 * - Call the crt0
 *
 */
void	Reset_C0_Handler(void) {

	#if defined(OZONE_S)
	register	volatile	uint32_t	wait = 1u;
	while (wait) { NOP; }
	#endif

	INST_SYNC_BARRIER;

// Activate all the SRAM
// Activation of LP RAM is important for correctly handle
// RAM DMA accesses during WFI

	REG(RCC)->MEMENR   |= (RCC_MEMENR_FLEXRAMEN		 | RCC_MEMENR_BKPSRAMEN		 | \
						   RCC_MEMENR_AHBSRAM1EN	 | RCC_MEMENR_AHBSRAM2EN	 | \
						   RCC_MEMENR_AXISRAM1EN	 | RCC_MEMENR_AXISRAM2EN	 | \
						   RCC_MEMENR_AXISRAM3EN	 | RCC_MEMENR_AXISRAM4EN	 | \
						   RCC_MEMENR_AXISRAM5EN	 | RCC_MEMENR_AXISRAM6EN);

	REG(RCC)->MEMLPENR |= (RCC_MEMLPENR_FLEXRAMLPEN  | RCC_MEMLPENR_BKPSRAMLPEN  | \
						   RCC_MEMLPENR_AHBSRAM1LPEN | RCC_MEMLPENR_AHBSRAM2LPEN | \
						   RCC_MEMLPENR_AXISRAM1LPEN | RCC_MEMLPENR_AXISRAM2LPEN | \
						   RCC_MEMLPENR_AXISRAM3LPEN | RCC_MEMLPENR_AXISRAM4LPEN | \
						   RCC_MEMLPENR_AXISRAM5LPEN | RCC_MEMLPENR_AXISRAM6LPEN);

	REG(RCC)->AHB2ENR |= RCC_AHB2ENR_RAMCFGEN;

	REG(RAMCFG)->AXISRAM1CR = 0u;
	REG(RAMCFG)->AXISRAM2CR = 0u;
	REG(RAMCFG)->AXISRAM3CR = 0u;
	REG(RAMCFG)->AXISRAM4CR = 0u;
	REG(RAMCFG)->AXISRAM5CR = 0u;
	REG(RAMCFG)->AXISRAM6CR = 0u;

// Disable the stack limits (xyzLIM)
// The FSBL boot set these registers

	core_setPSPLIM(0u);
	core_setMSPLIM(0u);
	INST_SYNC_BARRIER;

	SET_THREAD_STACK(linker_topStackFirst_C0);

	crt0();
}
