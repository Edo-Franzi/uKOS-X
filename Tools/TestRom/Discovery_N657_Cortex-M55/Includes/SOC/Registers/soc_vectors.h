/*
; soc_vectors.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Indirect Exception Vectors for Cortex_M55.
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

typedef enum IRQn {

// Cortex_M55 Processor Exceptions Numbers

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

	PVD_PVM_IRQn			= 0,	// PVDOUT through the EXTI line
	DTS_IRQn				= 2,	// Thermal sensor interruption
	RCC_IRQn				= 3,	// RCC global interrupt
	LOCKUP_IRQn				= 4,	// LOCKUP - no overstack in Cortex-M55
	CACHE_ECC_IRQn			= 5,	// Cache ECC error
	TCM_ECC_IRQn			= 6,	// TCM ECC error
	BCK_ECC_IRQn			= 7,	// Backup RAM interrupts (SEC and DED)
	FPU_IRQn				= 8,	// FPU safety flag
	RTC_S_IRQn				= 10,	// RTC secure interrupt
	TAMP_IRQn				= 11,	// TAMP secure and non-secure synchronous interrupt line
	RIFSC_TAMPER_IRQn		= 12,	// RIF can generate an interrupt when a laser attack is detected
	IAC_IRQn				= 13,	// IAC global interrupt
	RCC_S_IRQn				= 14,	// RCC global secure interrupt
	RTC_IRQn				= 16,	// RTC interrupt
	WDGLS_EARLY_IRQn		= 18,	// Independent watchdog interrupt
	WWDG_EARLY_IRQn			= 19,	// Window watchdog interrupt
	EXTI0_IRQn				= 20,	// EXTI Line 0 interrupt through the EXTI line
	EXTI1_IRQn				= 21,	// EXTI Line 1 interrupt through the EXTI line
	EXTI2_IRQn				= 22,	// EXTI Line 2 interrupt through the EXTI line
	EXTI3_IRQn				= 23,	// EXTI Line 3 interrupt through the EXTI line
	EXTI4_IRQn				= 24,	// EXTI Line 4 interrupt through the EXTI line
	EXTI5_IRQn				= 25,	// EXTI Line 5 interrupt through the EXTI line
	EXTI6_IRQn				= 26,	// EXTI Line 6 interrupt through the EXTI line
	EXTI7_IRQn				= 27,	// EXTI Line 7 interrupt through the EXTI line
	EXTI8_IRQn				= 28,	// EXTI Line 8 interrupt through the EXTI line
	EXTI9_IRQn				= 29,	// EXTI Line 9 interrupt
	EXTI10_IRQn				= 30,	// EXTI Line 10 interrupt
	EXTI11_IRQn				= 31,	// EXTI Line 11 interrupt
	EXTI12_IRQn				= 32,	// EXTI Line 12 interrupt
	EXTI13_IRQn				= 33,	// EXTI Line 13 interrupt
	EXTI14_IRQn				= 34,	// EXTI Line 14 interrupt
	EXTI15_IRQn				= 35,	// EXTI Line 15 interrupt
	SAES_IRQn				= 36,	// SAES global interrupt
	CRYP_IRQn				= 37,	// CRYP global interrupt
	PKA_IRQn				= 38,	// PKA global interrupt
	HASH_IRQn				= 39,	// HASH global interrupt
	RNG_IRQn				= 40,	// RNG global interrupt
	MCE1_IRQn				= 42,	// MCE1 global interrupt
	MCE2_IRQn				= 43,	// MCE2 global interrupt
	MCE3_IRQn				= 44,	// MCE3 global interrupt
	MCE4_IRQn				= 45,	// MCE4 global interrupt
	ADC12_IRQn				= 46,	// ADC1/ADC2 global interrupt
	CSI_DBG_IRQn			= 47,	// CSI global interrupt
	DCMIPP_IRQn				= 48,	// DCMIPP global interrupt
	PAHB_ERR_IRQn			= 52,	// Write posting errors on Cortex-M55 PAHB interface
	NPU_END_OF_EPOCH_IRQn	= 53,	// NPU mst_ints[0] line
	NPU1_IRQn				= 54,	// NPU mst_ints[1] line
	NPU2_IRQn				= 55,	// NPU mst_ints[2] line
	NPU3_IRQn				= 56,	// NPU mst_ints[3] line
	NPUCACHE_IRQn			= 57,	// ATON interrupt cache
	LTDC_LO_IRQn			= 58,	// LCD low-layer global interrupt
	LTDC_LO_ERR_IRQn		= 59,	// LCD low-layer error interrupt
	DMA2D_IRQn				= 60,	// DMA2D global interrupt
	JPEG_IRQn				= 61,	// JPEG global interrupt
	VENC_IRQn				= 62,	// VENC global interrupt
	GFXMMU_IRQn				= 63,	// GFXMMU global interrupt
	GFXTIM_IRQn				= 64,	// GFXTIM global interrupt
	GPU2D_IRQn				= 65,	// GPU2D global interrupt
	GPU2D_ERROR_IRQn		= 66,	// GPU2D global interrupt
	GPU_CACHE_IRQn			= 67,	// GPU cache interrupt
	HPDMA1_CH0_IRQn			= 68,	// HPDMA1 Channel 0 interrupt
	HPDMA1_CH1_IRQn			= 69,	// HPDMA1 Channel 1 interrupt
	HPDMA1_CH2_IRQn			= 70,	// HPDMA1 Channel 2 interrupt
	HPDMA1_CH3_IRQn			= 71,	// HPDMA1 Channel 3 interrupt
	HPDMA1_CH4_IRQn			= 72,	// HPDMA1 Channel 4 interrupt
	HPDMA1_CH5_IRQn			= 73,	// HPDMA1 Channel 5 interrupt
	HPDMA1_CH6_IRQn			= 74,	// HPDMA1 Channel 6 interrupt
	HPDMA1_CH7_IRQn			= 75,	// HPDMA1 Channel 7 interrupt
	HPDMA1_CH8_IRQn			= 76,	// HPDMA1 Channel 8 interrupt
	HPDMA1_CH9_IRQn			= 77,	// HPDMA1 Channel 9 interrupt
	HPDMA1_CH10_IRQn		= 78,	// HPDMA1 Channel 10 interrupt
	HPDMA1_CH11_IRQn		= 79,	// HPDMA1 Channel 11 interrupt
	HPDMA1_CH12_IRQn		= 80,	// HPDMA1 Channel 12 interrupt
	HPDMA1_CH13_IRQn		= 81,	// HPDMA1 Channel 13 interrupt
	HPDMA1_CH14_IRQn		= 82,	// HPDMA1 Channel 14 interrupt
	HPDMA1_CH15_IRQn		= 83,	// HPDMA1 Channel 15 interrupt
	GPDMA1_CH0_IRQn			= 84,	// GPDMA1 channel 0 interrupt
	GPDMA1_CH1_IRQn			= 85,	// GPDMA1 channel 1 interrupt
	GPDMA1_CH2_IRQn			= 86,	// GPDMA1 channel 2 interrupt
	GPDMA1_CH3_IRQn			= 87,	// GPDMA1 channel 3 interrupt
	GPDMA1_CH4_IRQn			= 88,	// GPDMA1 channel 4 interrupt
	GPDMA1_CH5_IRQn			= 89,	// GPDMA1 channel 5 interrupt
	GPDMA1_CH6_IRQn			= 90,	// GPDMA1 channel 6 interrupt
	GPDMA1_CH7_IRQn			= 91,	// GPDMA1 channel 7 interrupt
	GPDMA1_CH8_IRQn			= 92,	// GPDMA1 channel 8 interrupt
	GPDMA1_CH9_IRQn			= 93,	// GPDMA1 channel 9 interrupt
	GPDMA1_CH10_IRQn		= 94,	// GPDMA1 channel 10 interrupt
	GPDMA1_CH11_IRQn		= 95,	// GPDMA1 channel 11 interrupt
	GPDMA1_CH12_IRQn		= 96,	// GPDMA1 channel 12 interrupt
	GPDMA1_CH13_IRQn		= 97,	// GPDMA1 channel 13 interrupt
	GPDMA1_CH14_IRQn		= 98,	// GPDMA1 channel 14 interrupt
	GPDMA1_CH15_IRQn		= 99,	// GPDMA1 channel 15 interrupt
	I2C1_EV_IRQn			= 100,	// I2C1 event interrupt
	I2C1_ER_IRQn			= 101,	// I2C1 error interrupt
	I2C2_EV_IRQn			= 102,	// I2C2 event interrupt
	I2C2_ER_IRQn			= 103,	// I2C2 error interrupt
	I2C3_EV_IRQn			= 104,	// I2C3 event interrupt
	I2C3_ER_IRQn			= 105,	// I2C3 error interrupt
	I2C4_EV_IRQn			= 106,	// I2C4 event interrupt
	I2C4_ER_IRQn			= 107,	// I2C4 error interrupt
	I3C1_EV_IRQn			= 108,	// I3C1 event interrupt
	I3C1_ER_IRQn			= 109,	// I3C1 error interrupt
	I3C2_EV_IRQn			= 110,	// I3C2 event interrupt
	I3C2_ER_IRQn			= 111,	// I3C2 error interrupt
	TIM1_BRK_IRQn			= 112,	// TIM1 Break interrupt
	TIM1_UP_IRQn			= 113,	// TIM1 Update interrupt
	TIM1_TRG_CCU_IRQn		= 114,	// TIM1 Trigger and Commutation interrupts
	TIM1_CC_IRQn			= 115,	// TIM1 Capture Compare interrupt
	TIM2_IRQn				= 116,	// TIM2 global interrupt
	TIM3_IRQn				= 117,	// TIM3 global interrupt
	TIM4_IRQn				= 118,	// TIM4 global interrupt
	TIM5_IRQn				= 119,	// TIM5 global interrupt
	TIM6_IRQn				= 120,	// TIM6 Global interrupt
	TIM7_IRQn				= 121,	// TIM7 Global interrupt
	TIM8_BRK_IRQn			= 122,	// TIM8 Break interrupt
	TIM8_UP_IRQn			= 123,	// TIM8 Update interrupt
	TIM8_TRG_CCU_IRQn		= 124,	// TIM8 Trigger and Commutation interrupts
	TIM8_CC_IRQn			= 125,	// TIM8 Capture Compare interrupt
	TIM9_IRQn				= 126,	// TIM9 Global interrupt
	TIM10_IRQn				= 127,	// TIM10 Global interrupt
	TIM11_IRQn				= 128,	// TIM11 Global interrupt
	TIM12_IRQn				= 129,	// TIM12 Global interrupt
	TIM13_IRQn				= 130,	// TIM13 Global interrupt
	TIM14_IRQn				= 131,	// TIM14 Global interrupt
	TIM15_IRQn				= 132,	// TIM15 global interrupt
	TIM16_IRQn				= 133,	// TIM16 global interrupt
	TIM17_IRQn				= 134,	// TIM17 global interrupt
	TIM18_IRQn				= 135,	// TIM18 Global interrupt
	LPTIM1_IRQn				= 136,	// LPTIM1 global interrupt
	LPTIM2_IRQn				= 137,	// LPTIM2 global interrupt
	LPTIM3_IRQn				= 138,	// LPTIM3 global interrupt
	LPTIM4_IRQn				= 139,	// LPTIM4 global interrupt
	LPTIM5_IRQn				= 140,	// LPTIM5 global interrupt
	ADF1_FLT0_IRQn			= 141,	// ADF1 filter 0 global interrupt
	MDF1_FLT0_IRQn			= 142,	// MDF global Interrupt for Filter0
	MDF1_FLT1_IRQn			= 143,	// MDF global Interrupt for Filter1
	MDF1_FLT2_IRQn			= 144,	// MDF global Interrupt for Filter2
	MDF1_FLT3_IRQn			= 145,	// MDF global Interrupt for Filter3
	MDF1_FLT4_IRQn			= 146,	// MDF global Interrupt for Filter4
	MDF1_FLT5_IRQn			= 147,	// MDF global Interrupt for Filter5
	SAI1_A_IRQn				= 148,	// SAI1 global interrupt A
	SAI1_B_IRQn				= 149,	// SAI1 global interrupt B
	SAI2_A_IRQn				= 150,	// SAI2 global interrupt A
	SAI2_GLOBAL_B_IRQn		= 151,	// SAI2 global interrupt B
	SPDIFRX_IRQn			= 152,	// SPDIFRX global interrupt
	SPI1_IRQn				= 153,	// SPI1 global interrupt A
	SPI2_IRQn				= 154,	// SPI2 global interrupt A
	SPI3_IRQn				= 155,	// SPI3 global interrupt A
	SPI4_IRQn				= 156,	// SPI4 global interrupt A
	SPI5_IRQn				= 157,	// SPI5 global interrupt A
	SPI6_IRQn				= 158,	// SPI6 global interrupt A
	USART1_IRQn				= 159,	// USART1 Global interrupt
	USART2_IRQn				= 160,	// USART2 Global interrupt
	USART3_IRQn				= 161,	// USART3 Global interrupt
	UART4_IRQn				= 162,	// UART4 Global interrupt
	UART5_IRQn				= 163,	// UART5 Global interrupt
	USART6_IRQn				= 164,	// USART6 Global interrupt
	UART7_IRQn				= 165,	// UART7 Global interrupt
	UART8_IRQn				= 166,	// UART8 Global interrupt
	UART9_IRQn				= 167,	// UART9 Global interrupt
	USART10_IRQn			= 168,	// USART10 Global interrupt
	LPUART1_IRQn			= 169,	// LPUART1 global interrupt
	XSPI1_IRQn				= 170,	// XSPI1 global interrupt
	XSPI2_IRQn				= 171,	// XSPI2 global interrupt
	XSPI3_IRQn				= 172,	// XSPI3 global interrupt
	FMC_IRQn				= 173,	// FMC global interrupt
	SDMMC1_IRQn				= 174,	// SDMMC1 global interrupt
	SDMMC2_IRQn				= 175,	// SDMMC2 global interrupt
	UCPD_IRQn				= 176,	// UCPD global interrupt
	OTG1_IRQn				= 177,	// USB OTG1 HS global interrupt
	OTG2_IRQn				= 178,	// USB OTG2 HS global interrupt
	ETH1_IRQn				= 179,	// Ethernet global interrupt
	FDCAN1_IT0_IRQn			= 180,	// FDCAN1 interrupt 0
	FDCAN1_IT1_IRQn			= 181,	// FDCAN1 interrupt 1
	FDCAN2_IT0_IRQn			= 182,	// FDCAN2 interrupt 0
	FDCAN2_IT1_IRQn			= 183,	// FDCAN2 interrupt 1
	FDCAN3_IT0_IRQn			= 184,	// FDCAN3 interrupt 0
	FDCAN3_IT1_IRQn			= 185,	// FDCAN3 interrupt 1
	FDCAN_CU_IRQn			= 186,	// Clock calibration unit interrupt line(FDCAN1 only)
	MDIOS_IRQn				= 187,	// MDIOS global Interrupt
	DCMI_PSSI_IRQn			= 188,	// DCMI/PSSI global interrupt
	WAKEUP_PIN_IRQn			= 189,	// Wake-up pin interrupts
	CTI0_IRQn				= 190,	// Debug monitor (Cortex-M55 related)
	CTI1_IRQn				= 191,	// Debug monitor (Cortex-M55 related)
	LTDC_UP_IRQn			= 193,	// LCD up-layer global interrupt
	LTDC_UP_ERR_IRQn		= 194,	// LCD up-layer error interrupt
} IRQn_Type;

#define	KNB_EXCEPTIONS		14u
#define	KNB_INTERRUPTIONS	195u

// For the core 0
// --------------

// Cortex_M55 Processor Exceptions Numbers

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

#define	PVD_PVM_C0_IRQn				PVD_PVM_IRQn
#define	DTS_C0_IRQn					DTS_IRQn
#define	RCC_C0_IRQn					RCC_IRQn
#define	LOCKUP_C0_IRQn				LOCKUP_IRQn
#define	CACHE_ECC_C0_IRQn			CACHE_ECC_IRQn
#define	TCM_ECC_C0_IRQn				TCM_ECC_IRQn
#define	BCK_ECC_C0_IRQn				BCK_ECC_IRQn
#define	FPU_C0_IRQn					FPU_IRQn
#define	RTC_S_C0_IRQn				RTC_S_IRQn
#define	TAMP_C0_IRQn				TAMP_IRQn
#define	RIFSC_TAMPER_C0_IRQn		RIFSC_TAMPER_IRQn
#define	IAC_C0_IRQn					IAC_IRQn
#define	RCC_S_C0_IRQn				RCC_S_IRQn
#define	RTC_C0_IRQn					RTC_IRQn
#define	WDGLS_EARLY_C0_IRQn			WDGLS_EARLY_IRQn
#define	WWDG_EARLY_C0_IRQn			WWDG_EARLY_IRQn
#define	EXTI0_C0_IRQn				EXTI0_IRQn
#define	EXTI1_C0_IRQn				EXTI1_IRQn
#define	EXTI2_C0_IRQn				EXTI2_IRQn
#define	EXTI3_C0_IRQn				EXTI3_IRQn
#define	EXTI4_C0_IRQn				EXTI4_IRQn
#define	EXTI5_C0_IRQn				EXTI5_IRQn
#define	EXTI6_C0_IRQn				EXTI6_IRQn
#define	EXTI7_C0_IRQn				EXTI7_IRQn
#define	EXTI8_C0_IRQn				EXTI8_IRQn
#define	EXTI9_C0_IRQn				EXTI9_IRQn
#define	EXTI10_C0_IRQn				EXTI10_IRQn
#define	EXTI11_C0_IRQn				EXTI11_IRQn
#define	EXTI12_C0_IRQn				EXTI12_IRQn
#define	EXTI13_C0_IRQn				EXTI13_IRQn
#define	EXTI14_C0_IRQn				EXTI14_IRQn
#define	EXTI15_C0_IRQn				EXTI15_IRQn
#define	SAES_C0_IRQn				SAES_IRQn
#define	CRYP_C0_IRQn				CRYP_IRQn
#define	PKA_C0_IRQn					PKA_IRQn
#define	HASH_C0_IRQn				HASH_IRQn
#define	RNG_C0_IRQn					RNG_IRQn
#define	MCE1_C0_IRQn				MCE1_IRQn
#define	MCE2_C0_IRQn				MCE2_IRQn
#define	MCE3_C0_IRQn				MCE3_IRQn
#define	MCE4_C0_IRQn				MCE4_IRQn
#define	ADC12_C0_IRQn				ADC12_IRQn
#define	CSI_DBG_C0_IRQn				CSI_DBG_IRQn
#define	DCMIPP_C0_IRQn				DCMIPP_IRQn
#define	PAHB_ERR_C0_IRQn			PAHB_ERR_IRQn
#define	NPU_END_OF_EPOCH_C0_IRQn	NPU_END_OF_EPOCH_IRQn
#define	NPU1_C0_IRQn				NPU1_IRQn
#define	NPU2_C0_IRQn				NPU2_IRQn
#define	NPU3_C0_IRQn				NPU3_IRQn
#define	NPUCACHE_C0_IRQn			NPUCACHE_IRQn
#define	LTDC_LO_C0_IRQn				LTDC_LO_IRQn
#define	LTDC_LO_ERR_C0_IRQn			LTDC_LO_ERR_IRQn
#define	DMA2D_C0_IRQn				DMA2D_IRQn
#define	JPEG_C0_IRQn				JPEG_IRQn
#define	VENC_C0_IRQn				VENC_IRQn
#define	GFXMMU_C0_IRQn				GFXMMU_IRQn
#define	GFXTIM_C0_IRQn				GFXTIM_IRQn
#define	GPU2D_C0_IRQn				GPU2D_IRQn
#define	GPU2D_ERROR_C0_IRQn			GPU2D_ERROR_IRQn
#define	GPU_CACHE_C0_IRQn			GPU_CACHE_IRQn
#define	HPDMA1_CH0_C0_IRQn			HPDMA1_CH0_IRQn
#define	HPDMA1_CH1_C0_IRQn			HPDMA1_CH1_IRQn
#define	HPDMA1_CH2_C0_IRQn			HPDMA1_CH2_IRQn
#define	HPDMA1_CH3_C0_IRQn			HPDMA1_CH3_IRQn
#define	HPDMA1_CH4_C0_IRQn			HPDMA1_CH4_IRQn
#define	HPDMA1_CH5_C0_IRQn			HPDMA1_CH5_IRQn
#define	HPDMA1_CH6_C0_IRQn			HPDMA1_CH6_IRQn
#define	HPDMA1_CH7_C0_IRQn			HPDMA1_CH7_IRQn
#define	HPDMA1_CH8_C0_IRQn			HPDMA1_CH8_IRQn
#define	HPDMA1_CH9_C0_IRQn			HPDMA1_CH9_IRQn
#define	HPDMA1_CH10_C0_IRQn			HPDMA1_CH10_IRQn
#define	HPDMA1_CH11_C0_IRQn			HPDMA1_CH11_IRQn
#define	HPDMA1_CH12_C0_IRQn			HPDMA1_CH12_IRQn
#define	HPDMA1_CH13_C0_IRQn			HPDMA1_CH13_IRQn
#define	HPDMA1_CH14_C0_IRQn			HPDMA1_CH14_IRQn
#define	HPDMA1_CH15_C0_IRQn			HPDMA1_CH15_IRQn
#define	GPDMA1_CH0_C0_IRQn			GPDMA1_CH0_IRQn
#define	GPDMA1_CH1_C0_IRQn			GPDMA1_CH1_IRQn
#define	GPDMA1_CH2_C0_IRQn			GPDMA1_CH2_IRQn
#define	GPDMA1_CH3_C0_IRQn			GPDMA1_CH3_IRQn
#define	GPDMA1_CH4_C0_IRQn			GPDMA1_CH4_IRQn
#define	GPDMA1_CH5_C0_IRQn			GPDMA1_CH5_IRQn
#define	GPDMA1_CH6_C0_IRQn			GPDMA1_CH6_IRQn
#define	GPDMA1_CH7_C0_IRQn			GPDMA1_CH7_IRQn
#define	GPDMA1_CH8_C0_IRQn			GPDMA1_CH8_IRQn
#define	GPDMA1_CH9_C0_IRQn			GPDMA1_CH9_IRQn
#define	GPDMA1_CH10_C0_IRQn			GPDMA1_CH10_IRQn
#define	GPDMA1_CH11_C0_IRQn			GPDMA1_CH11_IRQn
#define	GPDMA1_CH12_C0_IRQn			GPDMA1_CH12_IRQn
#define	GPDMA1_CH13_C0_IRQn			GPDMA1_CH13_IRQn
#define	GPDMA1_CH14_C0_IRQn			GPDMA1_CH14_IRQn
#define	GPDMA1_CH15_C0_IRQn			GPDMA1_CH15_IRQn
#define	I2C1_EV_C0_IRQn				I2C1_EV_IRQn
#define	I2C1_ER_C0_IRQn				I2C1_ER_IRQn
#define	I2C2_EV_C0_IRQn				I2C2_EV_IRQn
#define	I2C2_ER_C0_IRQn				I2C2_ER_IRQn
#define	I2C3_EV_C0_IRQn				I2C3_EV_IRQn
#define	I2C3_ER_C0_IRQn				I2C3_ER_IRQn
#define	I2C4_EV_C0_IRQn				I2C4_EV_IRQn
#define	I2C4_ER_C0_IRQn				I2C4_ER_IRQn
#define	I3C1_EV_C0_IRQn				I3C1_EV_IRQn
#define	I3C1_ER_C0_IRQn				I3C1_ER_IRQn
#define	I3C2_EV_C0_IRQn				I3C2_EV_IRQn
#define	I3C2_ER_C0_IRQn				I3C2_ER_IRQn
#define	TIM1_BRK_C0_IRQn			TIM1_BRK_IRQn
#define	TIM1_UP_C0_IRQn				TIM1_UP_IRQn
#define	TIM1_TRG_CCU_C0_IRQn		TIM1_TRG_CCU_IRQn
#define	TIM1_CC_C0_IRQn				TIM1_CC_IRQn
#define	TIM2_C0_IRQn				TIM2_IRQn
#define	TIM3_C0_IRQn				TIM3_IRQn
#define	TIM4_C0_IRQn				TIM4_IRQn
#define	TIM5_C0_IRQn				TIM5_IRQn
#define	TIM6_C0_IRQn				TIM6_IRQn
#define	TIM7_C0_IRQn				TIM7_IRQn
#define	TIM8_BRK_C0_IRQn			TIM8_BRK_IRQn
#define	TIM8_UP_C0_IRQn				TIM8_UP_IRQn
#define	TIM8_TRG_CCU_C0_IRQn		TIM8_TRG_CCU_IRQn
#define	TIM8_CC_C0_IRQn				TIM8_CC_IRQn
#define	TIM9_C0_IRQn				TIM9_IRQn
#define	TIM10_C0_IRQn				TIM10_IRQn
#define	TIM11_C0_IRQn				TIM11_IRQn
#define	TIM12_C0_IRQn				TIM12_IRQn
#define	TIM13_C0_IRQn				TIM13_IRQn
#define	TIM14_C0_IRQn				TIM14_IRQn
#define	TIM15_C0_IRQn				TIM15_IRQn
#define	TIM16_C0_IRQn				TIM16_IRQn
#define	TIM17_C0_IRQn				TIM17_IRQn
#define	TIM18_C0_IRQn				TIM18_IRQn
#define	LPTIM1_C0_IRQn				LPTIM1_IRQn
#define	LPTIM2_C0_IRQn				LPTIM2_IRQn
#define	LPTIM3_C0_IRQn				LPTIM3_IRQn
#define	LPTIM4_C0_IRQn				LPTIM4_IRQn
#define	LPTIM5_C0_IRQn				LPTIM5_IRQn
#define	ADF1_FLT0_C0_IRQn			ADF1_FLT0_IRQn
#define	MDF1_FLT0_C0_IRQn			MDF1_FLT0_IRQn
#define	MDF1_FLT1_C0_IRQn			MDF1_FLT1_IRQn
#define	MDF1_FLT2_C0_IRQn			MDF1_FLT2_IRQn
#define	MDF1_FLT3_C0_IRQn			MDF1_FLT3_IRQn
#define	MDF1_FLT4_C0_IRQn			MDF1_FLT4_IRQn
#define	MDF1_FLT5_C0_IRQn			MDF1_FLT5_IRQn
#define	SAI1_A_C0_IRQn				SAI1_A_IRQn
#define	SAI1_B_C0_IRQn				SAI1_B_IRQn
#define	SAI2_A_C0_IRQn				SAI2_A_IRQn
#define	SAI2_GLOBAL_B_C0_IRQn		SAI2_GLOBAL_B_IRQn
#define	SPDIFRX_C0_IRQn				SPDIFRX_IRQn
#define	SPI1_C0_IRQn				SPI1_IRQn
#define	SPI2_C0_IRQn				SPI2_IRQn
#define	SPI3_C0_IRQn				SPI3_IRQn
#define	SPI4_C0_IRQn				SPI4_IRQn
#define	SPI5_C0_IRQn				SPI5_IRQn
#define	SPI6_C0_IRQn				SPI6_IRQn
#define	USART1_C0_IRQn				USART1_IRQn
#define	USART2_C0_IRQn				USART2_IRQn
#define	USART3_C0_IRQn				USART3_IRQn
#define	UART4_C0_IRQn				UART4_IRQn
#define	UART5_C0_IRQn				UART5_IRQn
#define	USART6_C0_IRQn				USART6_IRQn
#define	UART7_C0_IRQn				UART7_IRQn
#define	UART8_C0_IRQn				UART8_IRQn
#define	UART9_C0_IRQn				UART9_IRQn
#define	USART10_C0_IRQn				USART10_IRQn
#define	LPUART1_C0_IRQn				LPUART1_IRQn
#define	XSPI1_C0_IRQn				XSPI1_IRQn
#define	XSPI2_C0_IRQn				XSPI2_IRQn
#define	XSPI3_C0_IRQn				XSPI3_IRQn
#define	FMC_C0_IRQn					FMC_IRQn
#define	SDMMC1_C0_IRQn				SDMMC1_IRQn
#define	SDMMC2_C0_IRQn				SDMMC2_IRQn
#define	UCPD_C0_IRQn				UCPD_IRQn
#define	OTG1_C0_IRQn				OTG1_IRQn
#define	OTG2_C0_IRQn				OTG2_IRQn
#define	ETH1_C0_IRQn				ETH1_IRQn
#define	FDCAN1_IT0_C0_IRQn			FDCAN1_IT0_IRQn
#define	FDCAN1_IT1_C0_IRQn			FDCAN1_IT1_IRQn
#define	FDCAN2_IT0_C0_IRQn			FDCAN2_IT0_IRQn
#define	FDCAN2_IT1_C0_IRQn			FDCAN2_IT1_IRQn
#define	FDCAN3_IT0_C0_IRQn			FDCAN3_IT0_IRQn
#define	FDCAN3_IT1_C0_IRQn			FDCAN3_IT1_IRQn
#define	FDCAN_CU_C0_IRQn			FDCAN_CU_IRQn
#define	MDIOS_C0_IRQn				MDIOS_IRQn
#define	DCMI_PSSI_C0_IRQn			DCMI_PSSI_IRQn
#define	WAKEUP_PIN_C0_IRQn			WAKEUP_PIN_IRQn
#define	CTI0_C0_IRQn				CTI0_IRQn
#define	CTI1_C0_IRQn				CTI1_IRQn
#define	LTDC_UP_C0_IRQn				LTDC_UP_IRQn
#define	LTDC_UP_ERR_C0_IRQn			LTDC_UP_ERR_IRQn

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

// Exceptions

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

// IRQHandler

void	PVD_PVM_C0_IRQHandler(void);
void	DTS_C0_IRQHandler(void);
void	RCC_C0_IRQHandler(void);
void	LOCKUP_C0_IRQHandler(void);
void	CACHE_ECC_C0_IRQHandler(void);
void	TCM_ECC_C0_IRQHandler(void);
void	BCK_ECC_C0_IRQHandler(void);
void	FPU_C0_IRQHandler(void);
void	RTC_S_C0_IRQHandler(void);
void	TAMP_C0_IRQHandler(void);
void	RIFSC_TAMPER_C0_IRQHandler(void);
void	IAC_C0_IRQHandler(void);
void	RCC_S_C0_IRQHandler(void);
void	RTC_C0_IRQHandler(void);
void	WDGLS_EARLY_C0_IRQHandler(void);
void	WWDG_EARLY_C0_IRQHandler(void);
void	EXTI0_C0_IRQHandler(void);
void	EXTI1_C0_IRQHandler(void);
void	EXTI2_C0_IRQHandler(void);
void	EXTI3_C0_IRQHandler(void);
void	EXTI4_C0_IRQHandler(void);
void	EXTI5_C0_IRQHandler(void);
void	EXTI6_C0_IRQHandler(void);
void	EXTI7_C0_IRQHandler(void);
void	EXTI8_C0_IRQHandler(void);
void	EXTI9_C0_IRQHandler(void);
void	EXTI10_C0_IRQHandler(void);
void	EXTI11_C0_IRQHandler(void);
void	EXTI12_C0_IRQHandler(void);
void	EXTI13_C0_IRQHandler(void);
void	EXTI14_C0_IRQHandler(void);
void	EXTI15_C0_IRQHandler(void);
void	SAES_C0_IRQHandler(void);
void	CRYP_C0_IRQHandler(void);
void	PKA_C0_IRQHandler(void);
void	HASH_C0_IRQHandler(void);
void	RNG_C0_IRQHandler(void);
void	MCE1_C0_IRQHandler(void);
void	MCE2_C0_IRQHandler(void);
void	MCE3_C0_IRQHandler(void);
void	MCE4_C0_IRQHandler(void);
void	ADC12_C0_IRQHandler(void);
void	CSI_DBG_C0_IRQHandler(void);
void	DCMIPP_C0_IRQHandler(void);
void	PAHB_ERR_C0_IRQHandler(void);
void	NPU_END_OF_EPOCH_C0_IRQHandler(void);
void	NPU1_C0_IRQHandler(void);
void	NPU2_C0_IRQHandler(void);
void	NPU3_C0_IRQHandler(void);
void	NPUCACHE_C0_IRQHandler(void);
void	LTDC_LO_C0_IRQHandler(void);
void	LTDC_LO_ERR_C0_IRQHandler(void);
void	DMA2D_C0_IRQHandler(void);
void	JPEG_C0_IRQHandler(void);
void	VENC_C0_IRQHandler(void);
void	GFXMMU_C0_IRQHandler(void);
void	GFXTIM_C0_IRQHandler(void);
void	GPU2D_C0_IRQHandler(void);
void	GPU2D_ERROR_C0_IRQHandler(void);
void	GPU_CACHE_C0_IRQHandler(void);
void	HPDMA1_CH0_C0_IRQHandler(void);
void	HPDMA1_CH1_C0_IRQHandler(void);
void	HPDMA1_CH2_C0_IRQHandler(void);
void	HPDMA1_CH3_C0_IRQHandler(void);
void	HPDMA1_CH4_C0_IRQHandler(void);
void	HPDMA1_CH5_C0_IRQHandler(void);
void	HPDMA1_CH6_C0_IRQHandler(void);
void	HPDMA1_CH7_C0_IRQHandler(void);
void	HPDMA1_CH8_C0_IRQHandler(void);
void	HPDMA1_CH9_C0_IRQHandler(void);
void	HPDMA1_CH10_C0_IRQHandler(void);
void	HPDMA1_CH11_C0_IRQHandler(void);
void	HPDMA1_CH12_C0_IRQHandler(void);
void	HPDMA1_CH13_C0_IRQHandler(void);
void	HPDMA1_CH14_C0_IRQHandler(void);
void	HPDMA1_CH15_C0_IRQHandler(void);
void	GPDMA1_CH0_C0_IRQHandler(void);
void	GPDMA1_CH1_C0_IRQHandler(void);
void	GPDMA1_CH2_C0_IRQHandler(void);
void	GPDMA1_CH3_C0_IRQHandler(void);
void	GPDMA1_CH4_C0_IRQHandler(void);
void	GPDMA1_CH5_C0_IRQHandler(void);
void	GPDMA1_CH6_C0_IRQHandler(void);
void	GPDMA1_CH7_C0_IRQHandler(void);
void	GPDMA1_CH8_C0_IRQHandler(void);
void	GPDMA1_CH9_C0_IRQHandler(void);
void	GPDMA1_CH10_C0_IRQHandler(void);
void	GPDMA1_CH11_C0_IRQHandler(void);
void	GPDMA1_CH12_C0_IRQHandler(void);
void	GPDMA1_CH13_C0_IRQHandler(void);
void	GPDMA1_CH14_C0_IRQHandler(void);
void	GPDMA1_CH15_C0_IRQHandler(void);
void	I2C1_EV_C0_IRQHandler(void);
void	I2C1_ER_C0_IRQHandler(void);
void	I2C2_EV_C0_IRQHandler(void);
void	I2C2_ER_C0_IRQHandler(void);
void	I2C3_EV_C0_IRQHandler(void);
void	I2C3_ER_C0_IRQHandler(void);
void	I2C4_EV_C0_IRQHandler(void);
void	I2C4_ER_C0_IRQHandler(void);
void	I3C1_EV_C0_IRQHandler(void);
void	I3C1_ER_C0_IRQHandler(void);
void	I3C2_EV_C0_IRQHandler(void);
void	I3C2_ER_C0_IRQHandler(void);
void	TIM1_BRK_C0_IRQHandler(void);
void	TIM1_UP_C0_IRQHandler(void);
void	TIM1_TRG_CCU_C0_IRQHandler(void);
void	TIM1_CC_C0_IRQHandler(void);
void	TIM2_C0_IRQHandler(void);
void	TIM3_C0_IRQHandler(void);
void	TIM4_C0_IRQHandler(void);
void	TIM5_C0_IRQHandler(void);
void	TIM6_C0_IRQHandler(void);
void	TIM7_C0_IRQHandler(void);
void	TIM8_BRK_C0_IRQHandler(void);
void	TIM8_UP_C0_IRQHandler(void);
void	TIM8_TRG_CCU_C0_IRQHandler(void);
void	TIM8_CC_C0_IRQHandler(void);
void	TIM9_C0_IRQHandler(void);
void	TIM10_C0_IRQHandler(void);
void	TIM11_C0_IRQHandler(void);
void	TIM12_C0_IRQHandler(void);
void	TIM13_C0_IRQHandler(void);
void	TIM14_C0_IRQHandler(void);
void	TIM15_C0_IRQHandler(void);
void	TIM16_C0_IRQHandler(void);
void	TIM17_C0_IRQHandler(void);
void	TIM18_C0_IRQHandler(void);
void	LPTIM1_C0_IRQHandler(void);
void	LPTIM2_C0_IRQHandler(void);
void	LPTIM3_C0_IRQHandler(void);
void	LPTIM4_C0_IRQHandler(void);
void	LPTIM5_C0_IRQHandler(void);
void	ADF1_FLT0_C0_IRQHandler(void);
void	MDF1_FLT0_C0_IRQHandler(void);
void	MDF1_FLT1_C0_IRQHandler(void);
void	MDF1_FLT2_C0_IRQHandler(void);
void	MDF1_FLT3_C0_IRQHandler(void);
void	MDF1_FLT4_C0_IRQHandler(void);
void	MDF1_FLT5_C0_IRQHandler(void);
void	SAI1_A_C0_IRQHandler(void);
void	SAI1_B_C0_IRQHandler(void);
void	SAI2_A_C0_IRQHandler(void);
void	SAI2_GLOBAL_B_C0_IRQHandler(void);
void	SPDIFRX_C0_IRQHandler(void);
void	SPI1_C0_IRQHandler(void);
void	SPI2_C0_IRQHandler(void);
void	SPI3_C0_IRQHandler(void);
void	SPI4_C0_IRQHandler(void);
void	SPI5_C0_IRQHandler(void);
void	SPI6_C0_IRQHandler(void);
void	USART1_C0_IRQHandler(void);
void	USART2_C0_IRQHandler(void);
void	USART3_C0_IRQHandler(void);
void	UART4_C0_IRQHandler(void);
void	UART5_C0_IRQHandler(void);
void	USART6_C0_IRQHandler(void);
void	UART7_C0_IRQHandler(void);
void	UART8_C0_IRQHandler(void);
void	UART9_C0_IRQHandler(void);
void	USART10_C0_IRQHandler(void);
void	LPUART1_C0_IRQHandler(void);
void	XSPI1_C0_IRQHandler(void);
void	XSPI2_C0_IRQHandler(void);
void	XSPI3_C0_IRQHandler(void);
void	FMC_C0_IRQHandler(void);
void	SDMMC1_C0_IRQHandler(void);
void	SDMMC2_C0_IRQHandler(void);
void	UCPD_C0_IRQHandler(void);
void	OTG1_C0_IRQHandler(void);
void	OTG2_C0_IRQHandler(void);
void	ETH1_C0_IRQHandler(void);
void	FDCAN1_IT0_C0_IRQHandler(void);
void	FDCAN1_IT1_C0_IRQHandler(void);
void	FDCAN2_IT0_C0_IRQHandler(void);
void	FDCAN2_IT1_C0_IRQHandler(void);
void	FDCAN3_IT0_C0_IRQHandler(void);
void	FDCAN3_IT1_C0_IRQHandler(void);
void	FDCAN_CU_C0_IRQHandler(void);
void	MDIOS_C0_IRQHandler(void);
void	DCMI_PSSI_C0_IRQHandler(void);
void	WAKEUP_PIN_C0_IRQHandler(void);
void	CTI0_C0_IRQHandler(void);
void	CTI1_C0_IRQHandler(void);
void	LTDC_UP_C0_IRQHandler(void);
void	LTDC_UP_ERR_C0_IRQHandler(void);

#if (defined(__cplusplus))
}
#endif
