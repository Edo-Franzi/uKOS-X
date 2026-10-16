/*
; soc_vectors.
; ============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Indirect Exception Vectors for Cortex_M7.
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

// Cortex_M7 Processor Exceptions Numbers

	NonMaskableInt_IRQn			= -14,	// Non Maskable Interrupt
	HardFault_IRQn				= -13,	// Hard Fault Interrupt
	MemoryManagement_IRQn		= -12,	// Memory Management Interrupt
	BusFault_IRQn				= -11,	// Bus Fault Interrupt
	UsageFault_IRQn				= -10,	// Usage Fault Interrupt
	SVCall_IRQn					= -5,	// SV Call Interrupt
	DebugMonitor_IRQn			= -4,	// Debug Monitor Interrupt
	PendSV_IRQn					= -2,	// Pend SV Interrupt
	SysTick_IRQn				= -1,	// System Tick Interrupt

// SOC Specific Interrupt Numbers

	WWDG1_IRQn					= 0,	// Window Watchdog interrupt
	PVD_PVM_IRQn				= 1,	// PVD through EXTI line
	RTC_TAMP_STAMP_CSS_LSE_IRQn	= 2,	// RTC tamper, timestamp
	RTC_WKUP_IRQn				= 3,	// RTC Wakeup interrupt
	FLASH_IRQn					= 4,	// Flash memory
	RCC_IRQn					= 5,	// RCC global interrupt
	EXTI0_IRQn					= 6,	// EXTI Line 0 interrupt
	EXTI1_IRQn					= 7,	// EXTI Line 1 interrupt
	EXTI2_IRQn					= 8,	// EXTI Line 2 interrupt
	EXTI3_IRQn					= 9,	// EXTI Line 3interrupt
	EXTI4_IRQn					= 10,	// EXTI Line 4interrupt
	DMA1_STR0_IRQn				= 11,	// DMA1 Stream0
	DMA1_STR1_IRQn				= 12,	// DMA1 Stream1
	DMA1_STR2_IRQn				= 13,	// DMA1 Stream2
	DMA1_STR3_IRQn				= 14,	// DMA1 Stream3
	DMA1_STR4_IRQn				= 15,	// DMA1 Stream4
	DMA1_STR5_IRQn				= 16,	// DMA1 Stream5
	DMA1_STR6_IRQn				= 17,	// DMA1 Stream6
	ADC1_2_IRQn					= 18,	// ADC1 and ADC2
	FDCAN1_IT0_IRQn				= 19,	// FDCAN1 Interrupt 0
	FDCAN2_IT0_IRQn				= 20,	// FDCAN2 Interrupt 0
	FDCAN1_IT1_IRQn				= 21,	// FDCAN1 Interrupt 1
	FDCAN2_IT1_IRQn				= 22,	// FDCAN2 Interrupt 1
	EXTI9_5_IRQn				= 23,	// EXTI Line[9:5] interrupts
	TIM1_BRK_IRQn				= 24,	// TIM1 break interrupt
	TIM1_UP_IRQn				= 25,	// TIM1 update interrupt
	TIM1_TRG_COM_IRQn			= 26,	// TIM1 trigger and commutation
	TIM1_CC_IRQn				= 27,	// TIM1 capture / compare
	TIM2_IRQn					= 28,	// TIM2 global interrupt
	TIM3_IRQn					= 29,	// TIM3 global interrupt
	TIM4_IRQn					= 30,	// TIM4 global interrupt
	I2C1_EV_IRQn				= 31,	// I2C1 event interrupt
	I2C1_ER_IRQn				= 32,	// I2C1 error interrupt
	I2C2_EV_IRQn				= 33,	// I2C2 event interrupt
	I2C2_ER_IRQn				= 34,	// I2C2 error interrupt
	SPI1_IRQn					= 35,	// SPI1 global interrupt
	SPI2_IRQn					= 36,	// SPI2 global interrupt
	USART1_IRQn					= 37,	// USART1 global interrupt
	USART2_IRQn					= 38,	// USART2 global interrupt
	USART3_IRQn					= 39,	// USART3 global interrupt
	EXTI15_10_IRQn				= 40,	// EXTI Line[15:10] interrupts
	RTC_ALARM_IRQn				= 41,	// RTC alarms (A and B)
	TIM8_BRK_TIM12_IRQn			= 43,	// TIM8 break and TIM12 global interrupts
	TIM8_UP_TIM13_IRQn			= 44,	// TIM8 update and TIM13 global interrupts
	TIM8_TRG_COM_TIM14_IRQn		= 45,	// TIM8 trigger /commutation and TIM14 global interrupts
	TIM8_CC_IRQn				= 46,	// TIM8 capture / compare
	DMA1_STR7_IRQn				= 47,	// DMA1 Stream7
	FMC_IRQn					= 48,	// FMC global interrupt
	SDMMC1_IRQn					= 49,	// SDMMC global interrupt
	TIM5_IRQn					= 50,	// TIM5 global interrupt
	SPI3_IRQn					= 51,	// SPI3 global interrupt
	UART4_IRQn					= 52,	// UART4 global interrupt
	UART5_IRQn					= 53,	// UART5 global interrupt
	TIM6_DAC_IRQn				= 54,	// TIM6 global interrupt
	TIM7_IRQn					= 55,	// TIM7 global interrupt
	DMA2_STR0_IRQn				= 56,	// DMA2 Stream0 interrupt
	DMA2_STR1_IRQn				= 57,	// DMA2 Stream1 interrupt
	DMA2_STR2_IRQn				= 58,	// DMA2 Stream2 interrupt
	DMA2_STR3_IRQn				= 59,	// DMA2 Stream3 interrupt
	DMA2_STR4_IRQn				= 60,	// DMA2 Stream4 interrupt
	ETH_IRQn					= 61,	// Ethernet global interrupt
	ETH_WKUP_IRQn				= 62,	// Ethernet wakeup through EXTI
	FDCAN_CAL_IRQn				= 63,	// CAN2TX interrupts
	DMA2_STR5_IRQn				= 68,	// DMA2 Stream5 interrupt
	DMA2_STR6_IRQn				= 69,	// DMA2 Stream6 interrupt
	DMA2_STR7_IRQn				= 70,	// DMA2 Stream7 interrupt
	USART6_IRQn					= 71,	// USART6 global interrupt
	I2C3_EV_IRQn				= 72,	// I2C3 event interrupt
	I2C3_ER_IRQn				= 73,	// I2C3 error interrupt
	OTG_HS_EP1_OUT_IRQn			= 74,	// OTG_HS out global interrupt
	OTG_HS_EP1_IN_IRQn			= 75,	// OTG_HS in global interrupt
	OTG_HS_WKUP_IRQn			= 76,	// OTG_HS wakeup interrupt
	OTG_HS_IRQn					= 77,	// OTG_HS global interrupt
	DCMI_IRQn					= 78,	// DCMI global interrupt
	HASH_RNG_IRQn				= 80,	// HASH OR RNG interrupt
	FPU_IRQn					= 81,	//  CPU FPU interrupt
	UART7_IRQn					= 82,	// UART7 global interrupt
	UART8_IRQn					= 83,	// UART8 global interrupt
	SPI4_IRQn					= 84,	// SPI4 global interrupt
	SPI5_IRQn					= 85,	// SPI5 global interrupt
	SPI6_IRQn					= 86,	// SPI6 global interrupt
	SAI1_IRQn					= 87,	// SAI1 global interrupt
	LTDC_IRQn					= 88,	// LCD-TFT global interrupt
	LTDC_ER_IRQn				= 89,	// LCD-TFT error interrupt
	DMA2D_IRQn					= 90,	// DMA2D global interrupt
	SAI2_IRQn					= 91,	// SAI2 global interrupt
	QUADSPI_IRQn				= 92,	// QuadSPI global interrupt
	LPTIM1_IRQn					= 93,	// LPTIM1 global interrupt
	CEC_IRQn					= 94,	// HDMI-CEC global interrupt
	I2C4_EV_IRQn				= 95,	// I2C4 event interrupt
	I2C4_ER_IRQn				= 96,	// I2C4 error interrupt
	SPDIF_IRQn					= 97,	// SPDIFRX global interrupt
	OTG_FS_EP1_OUT_IRQn			= 98,	// OTG_FS out global interrupt
	OTG_FS_EP1_IN_IRQn			= 99,	// OTG_FS in global interrupt
	OTG_FS_WKUP_IRQn			= 100,	// OTG_FS wakeup
	OTG_FS_IRQn					= 101,	// OTG_FS global interrupt
	DMAMUX1_OV_IRQn				= 102,	// DMAMUX1 overrun interrupt
	HRTIM1_MST_IRQn				= 103,	// HRTIM1 master timer interrupt
	HRTIM1_TIMA_IRQn			= 104,	// HRTIM1 timer A interrupt
	HRTIM1_TIMB_IRQn			= 105,	// HRTIM1 timer B interrupt
	HRTIM1_TIMC_IRQn			= 106,	// HRTIM1 timer C interrupt
	HRTIM1_TIMD_IRQn			= 107,	// HRTIM1 timer D interrupt
	HRTIM1_TIME_IRQn			= 108,	// HRTIM1 timer E interrupt
	HRTIM1_FLT_IRQn				= 109,	// HRTIM1 fault interrupt
	DFSDM1_FLT0_IRQn			= 110,	// DFSDM1 filter 0 interrupt
	DFSDM1_FLT1_IRQn			= 111,	// DFSDM1 filter 1 interrupt
	DFSDM1_FLT2_IRQn			= 112,	// DFSDM1 filter 2 interrupt
	DFSDM1_FLT3_IRQn			= 113,	// DFSDM1 filter 3 interrupt
	SAI3_IRQn					= 114,	// SAI3 global interrupt
	SWPMI1_IRQn					= 115,	// SWPMI global interrupt
	TIM15_IRQn					= 116,	// TIM15 global interrupt
	TIM16_IRQn					= 117,	// TIM16 global interrupt
	TIM17_IRQn					= 118,	// TIM17 global interrupt
	MDIOS_WKUP_IRQn				= 119,	// MDIOS wakeup
	MDIOS_IRQn					= 120,	// MDIOS global interrupt
	JPEG_IRQn					= 121,	// JPEG global interrupt
	MDMA_IRQn					= 122,	// MDMA
	SDMMC_IRQn					= 124,	// SDMMC global interrupt
	HSEM0_IRQn					= 125,	// HSEM global interrupt 1
	ADC3_IRQn					= 127,	// ADC3 global interrupt
	DMAMUX2_OVR_IRQn			= 128,	// DMAMUX2 overrun interrupt
	BDMA_CH0_IRQn				= 129,	// BDMA channel 0 interrupt
	BDMA_CH1_IRQn				= 130,	// BDMA channel 1 interrupt
	BDMA_CH2_IRQn				= 131,	// BDMA channel 2 interrupt
	BDMA_CH3_IRQn				= 132,	// BDMA channel 3 interrupt
	BDMA_CH4_IRQn				= 133,	// BDMA channel 4 interrupt
	BDMA_CH5_IRQn				= 134,	// BDMA channel 5 interrupt
	BDMA_CH6_IRQn				= 135,	// BDMA channel 6 interrupt
	BDMA_CH7_IRQn				= 136,	// BDMA channel 7 interrupt
	COMP_IRQn					= 137,	// COMP1 and COMP2
	LPTIM2_IRQn					= 138,	// LPTIM2 timer interrupt
	LPTIM3_IRQn					= 139,	// LPTIM2 timer interrupt
	LPTIM4_IRQn					= 140,	// LPTIM2 timer interrupt
	LPTIM5_IRQn					= 141,	// LPTIM2 timer interrupt
	LPUART_IRQn					= 142,	// LPUART global interrupt
	WWDG1_RST_IRQn				= 143,	// Window Watchdog interrupt
	CRS_IRQn					= 144,	// Clock Recovery System globa
	SAI4_IRQn					= 146,	// SAI4 global interrupt
	WKUP_IRQn					= 149,	// WKUP1 to WKUP6 pins
} IRQn_Type;

#define	KNB_EXCEPTIONS		14u
#define	KNB_INTERRUPTIONS	150u

// For the core 0
// --------------

// Cortex_M7 Processor Exceptions Numbers

#define	NonMaskableInt_C0_IRQn			NonMaskableInt_IRQn
#define	HardFault_C0_IRQn				HardFault_IRQn
#define	MemoryManagement_C0_IRQn		MemoryManagement_IRQn
#define	BusFault_C0_IRQn				BusFault_IRQn
#define	UsageFault_C0_IRQn				UsageFault_IRQn
#define	SVCall_C0_IRQn					SVCall_IRQn
#define	DebugMonitor_C0_IRQn			DebugMonitor_IRQn
#define	PendSV_C0_IRQn					PendSV_IRQn
#define	SysTick_C0_IRQn					SysTick_IRQn

// SOC Specific Interrupt Numbers

#define	WWDG1_C0_IRQn					WWDG1_IRQn
#define	PVD_PVM_C0_IRQn					PVD_PVM_IRQn
#define	RTC_TAMP_STAMP_CSS_LSE_C0_IRQn	RTC_TAMP_STAMP_CSS_LSE_IRQn
#define	RTC_WKUP_C0_IRQn				RTC_WKUP_IRQn
#define	FLASH_C0_IRQn					FLASH_IRQn
#define	RCC_C0_IRQn						RCC_IRQn
#define	EXTI0_C0_IRQn					EXTI0_IRQn
#define	EXTI1_C0_IRQn					EXTI1_IRQn
#define	EXTI2_C0_IRQn					EXTI2_IRQn
#define	EXTI3_C0_IRQn					EXTI3_IRQn
#define	EXTI4_C0_IRQn					EXTI4_IRQn
#define	DMA1_STR0_C0_IRQn				DMA1_STR0_IRQn
#define	DMA1_STR1_C0_IRQn				DMA1_STR1_IRQn
#define	DMA1_STR2_C0_IRQn				DMA1_STR2_IRQn
#define	DMA1_STR3_C0_IRQn				DMA1_STR3_IRQn
#define	DMA1_STR4_C0_IRQn				DMA1_STR4_IRQn
#define	DMA1_STR5_C0_IRQn				DMA1_STR5_IRQn
#define	DMA1_STR6_C0_IRQn				DMA1_STR6_IRQn
#define	ADC1_2_C0_IRQn					ADC1_2_IRQn
#define	FDCAN1_IT0_C0_IRQn				FDCAN1_IT0_IRQn
#define	FDCAN2_IT0_C0_IRQn				FDCAN2_IT0_IRQn
#define	FDCAN1_IT1_C0_IRQn				FDCAN1_IT1_IRQn
#define	FDCAN2_IT1_C0_IRQn				FDCAN2_IT1_IRQn
#define	EXTI9_5_C0_IRQn					EXTI9_5_IRQn
#define	TIM1_BRK_C0_IRQn				TIM1_BRK_IRQn
#define	TIM1_UP_C0_IRQn					TIM1_UP_IRQn
#define	TIM1_TRG_COM_C0_IRQn			TIM1_TRG_COM_IRQn
#define	TIM1_CC_C0_IRQn					TIM1_CC_IRQn
#define	TIM2_C0_IRQn					TIM2_IRQn
#define	TIM3_C0_IRQn					TIM3_IRQn
#define	TIM4_C0_IRQn					TIM4_IRQn
#define	I2C1_EV_C0_IRQn					I2C1_EV_IRQn
#define	I2C1_ER_C0_IRQn					I2C1_ER_IRQn
#define	I2C2_EV_C0_IRQn					I2C2_EV_IRQn
#define	I2C2_ER_C0_IRQn					I2C2_ER_IRQn
#define	SPI1_C0_IRQn					SPI1_IRQn
#define	SPI2_C0_IRQn					SPI2_IRQn
#define	USART1_C0_IRQn					USART1_IRQn
#define	USART2_C0_IRQn					USART2_IRQn
#define	USART3_C0_IRQn					USART3_IRQn
#define	EXTI15_10_C0_IRQn				EXTI15_10_IRQn
#define	RTC_ALARM_C0_IRQn				RTC_ALARM_IRQn
#define	TIM8_BRK_TIM12_C0_IRQn			TIM8_BRK_TIM12_IRQn
#define	TIM8_UP_TIM13_C0_IRQn			TIM8_UP_TIM13_IRQn
#define	TIM8_TRG_COM_TIM14_C0_IRQn		TIM8_TRG_COM_TIM14_IRQn
#define	TIM8_CC_C0_IRQn					TIM8_CC_IRQn
#define	DMA1_STR7_C0_IRQn				DMA1_STR7_IRQn
#define	FMC_C0_IRQn						FMC_IRQn
#define	SDMMC1_C0_IRQn					SDMMC1_IRQn
#define	TIM5_C0_IRQn					TIM5_IRQn
#define	SPI3_C0_IRQn					SPI3_IRQn
#define	UART4_C0_IRQn					UART4_IRQn
#define	UART5_C0_IRQn					UART5_IRQn
#define	TIM6_DAC_C0_IRQn				TIM6_DAC_IRQn
#define	TIM7_C0_IRQn					TIM7_IRQn
#define	DMA2_STR0_C0_IRQn				DMA2_STR0_IRQn
#define	DMA2_STR1_C0_IRQn				DMA2_STR1_IRQn
#define	DMA2_STR2_C0_IRQn				DMA2_STR2_IRQn
#define	DMA2_STR3_C0_IRQn				DMA2_STR3_IRQn
#define	DMA2_STR4_C0_IRQn				DMA2_STR4_IRQn
#define	ETH_C0_IRQn						ETH_IRQn
#define	ETH_WKUP_C0_IRQn				ETH_WKUP_IRQn
#define	FDCAN_CAL_C0_IRQn				FDCAN_CAL_IRQn
#define	DMA2_STR5_C0_IRQn				DMA2_STR5_IRQn
#define	DMA2_STR6_C0_IRQn				DMA2_STR6_IRQn
#define	DMA2_STR7_C0_IRQn				DMA2_STR7_IRQn
#define	USART6_C0_IRQn					USART6_IRQn
#define	I2C3_EV_C0_IRQn					I2C3_EV_IRQn
#define	I2C3_ER_C0_IRQn					I2C3_ER_IRQn
#define	OTG_HS_EP1_OUT_C0_IRQn			OTG_HS_EP1_OUT_IRQn
#define	OTG_HS_EP1_IN_C0_IRQn			OTG_HS_EP1_IN_IRQn
#define	OTG_HS_WKUP_C0_IRQn				OTG_HS_WKUP_IRQn
#define	OTG_HS_C0_IRQn					OTG_HS_IRQn
#define	DCMI_C0_IRQn					DCMI_IRQn
#define	HASH_RNG_C0_IRQn				HASH_RNG_IRQn
#define	FPU_C0_IRQn						FPU_IRQn
#define	UART7_C0_IRQn					UART7_IRQn
#define	UART8_C0_IRQn					UART8_IRQn
#define	SPI4_C0_IRQn					SPI4_IRQn
#define	SPI5_C0_IRQn					SPI5_IRQn
#define	SPI6_C0_IRQn					SPI6_IRQn
#define	SAI1_C0_IRQn					SAI1_IRQn
#define	LTDC_C0_IRQn					LTDC_IRQn
#define	LTDC_ER_C0_IRQn					LTDC_ER_IRQn
#define	DMA2D_C0_IRQn					DMA2D_IRQn
#define	SAI2_C0_IRQn					SAI2_IRQn
#define	QUADSPI_C0_IRQn					QUADSPI_IRQn
#define	LPTIM1_C0_IRQn					LPTIM1_IRQn
#define	CEC_C0_IRQn						CEC_IRQn
#define	I2C4_EV_C0_IRQn					I2C4_EV_IRQn
#define	I2C4_ER_C0_IRQn					I2C4_ER_IRQn
#define	SPDIF_C0_IRQn					SPDIF_IRQn
#define	OTG_FS_EP1_OUT_C0_IRQn			OTG_FS_EP1_OUT_IRQn
#define	OTG_FS_EP1_IN_C0_IRQn			OTG_FS_EP1_IN_IRQn
#define	OTG_FS_WKUP_C0_IRQn				OTG_FS_WKUP_IRQn
#define	OTG_FS_C0_IRQn					OTG_FS_IRQn
#define	DMAMUX1_OV_C0_IRQn				DMAMUX1_OV_IRQn
#define	HRTIM1_MST_C0_IRQn				HRTIM1_MST_IRQn
#define	HRTIM1_TIMA_C0_IRQn				HRTIM1_TIMA_IRQn
#define	HRTIM1_TIMB_C0_IRQn				HRTIM1_TIMB_IRQn
#define	HRTIM1_TIMC_C0_IRQn				HRTIM1_TIMC_IRQn
#define	HRTIM1_TIMD_C0_IRQn				HRTIM1_TIMD_IRQn
#define	HRTIM1_TIME_C0_IRQn				HRTIM1_TIME_IRQn
#define	HRTIM1_FLT_C0_IRQn				HRTIM1_FLT_IRQn
#define	DFSDM1_FLT0_C0_IRQn				DFSDM1_FLT0_IRQn
#define	DFSDM1_FLT1_C0_IRQn				DFSDM1_FLT1_IRQn
#define	DFSDM1_FLT2_C0_IRQn				DFSDM1_FLT2_IRQn
#define	DFSDM1_FLT3_C0_IRQn				DFSDM1_FLT3_IRQn
#define	SAI3_C0_IRQn					SAI3_IRQn
#define	SWPMI1_C0_IRQn					SWPMI1_IRQn
#define	TIM15_C0_IRQn					TIM15_IRQn
#define	TIM16_C0_IRQn					TIM16_IRQn
#define	TIM17_C0_IRQn					TIM17_IRQn
#define	MDIOS_WKUP_C0_IRQn				MDIOS_WKUP_IRQn
#define	MDIOS_C0_IRQn					MDIOS_IRQn
#define	JPEG_C0_IRQn					JPEG_IRQn
#define	MDMA_C0_IRQn					MDMA_IRQn
#define	SDMMC_C0_IRQn					SDMMC_IRQn
#define	HSEM0_C0_IRQn					HSEM0_IRQn
#define	ADC3_C0_IRQn					ADC3_IRQn
#define	DMAMUX2_OVR_C0_IRQn				DMAMUX2_OVR_IRQn
#define	BDMA_CH0_C0_IRQn				BDMA_CH0_IRQn
#define	BDMA_CH1_C0_IRQn				BDMA_CH1_IRQn
#define	BDMA_CH2_C0_IRQn				BDMA_CH2_IRQn
#define	BDMA_CH3_C0_IRQn				BDMA_CH3_IRQn
#define	BDMA_CH4_C0_IRQn				BDMA_CH4_IRQn
#define	BDMA_CH5_C0_IRQn				BDMA_CH5_IRQn
#define	BDMA_CH6_C0_IRQn				BDMA_CH6_IRQn
#define	BDMA_CH7_C0_IRQn				BDMA_CH7_IRQn
#define	COMP_C0_IRQn					COMP_IRQn
#define	LPTIM2_C0_IRQn					LPTIM2_IRQn
#define	LPTIM3_C0_IRQn					LPTIM3_IRQn
#define	LPTIM4_C0_IRQn					LPTIM4_IRQn
#define	LPTIM5_C0_IRQn					LPTIM5_IRQn
#define	LPUART_C0_IRQn					LPUART_IRQn
#define	WWDG1_RST_C0_IRQn				WWDG1_RST_IRQn
#define	CRS_C0_IRQn						CRS_IRQn
#define	SAI4_C0_IRQn					SAI4_IRQn
#define	WKUP_C0_IRQn					WKUP_IRQn

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

// For the core 0
// --------------

// Exceptions

void	NonMaskableInt_C0_IRQHandler(void);
void	HardFault_C0_IRQHandler(void);
void	MemoryManagement_C0_IRQHandler(void);
void	BusFault_C0_IRQHandler(void);
void	UsageFault_C0_IRQHandler(void);
void	SVCall_C0_IRQHandler(void);
void	DebugMonitor_C0_IRQHandler(void);
void	PendSV_C0_IRQHandler(void);
void	SysTick_C0_IRQHandler(void);

// IRQHandler

void	WWDG1_C0_IRQHandler(void);
void	PVD_PVM_C0_IRQHandler(void);
void	RTC_TAMP_STAMP_CSS_LSE_C0_IRQHandler(void);
void	RTC_WKUP_C0_IRQHandler(void);
void	FLASH_C0_IRQHandler(void);
void	RCC_C0_IRQHandler(void);
void	EXTI0_C0_IRQHandler(void);
void	EXTI1_C0_IRQHandler(void);
void	EXTI2_C0_IRQHandler(void);
void	EXTI3_C0_IRQHandler(void);
void	EXTI4_C0_IRQHandler(void);
void	DMA1_STR0_C0_IRQHandler(void);
void	DMA1_STR1_C0_IRQHandler(void);
void	DMA1_STR2_C0_IRQHandler(void);
void	DMA1_STR3_C0_IRQHandler(void);
void	DMA1_STR4_C0_IRQHandler(void);
void	DMA1_STR5_C0_IRQHandler(void);
void	DMA1_STR6_C0_IRQHandler(void);
void	ADC1_2_C0_IRQHandler(void);
void	FDCAN1_IT0_C0_IRQHandler(void);
void	FDCAN2_IT0_C0_IRQHandler(void);
void	FDCAN1_IT1_C0_IRQHandler(void);
void	FDCAN2_IT1_C0_IRQHandler(void);
void	EXTI9_5_C0_IRQHandler(void);
void	TIM1_BRK_C0_IRQHandler(void);
void	TIM1_UP_C0_IRQHandler(void);
void	TIM1_TRG_COM_C0_IRQHandler(void);
void	TIM1_CC_C0_IRQHandler(void);
void	TIM2_C0_IRQHandler(void);
void	TIM3_C0_IRQHandler(void);
void	TIM4_C0_IRQHandler(void);
void	I2C1_EV_C0_IRQHandler(void);
void	I2C1_ER_C0_IRQHandler(void);
void	I2C2_EV_C0_IRQHandler(void);
void	I2C2_ER_C0_IRQHandler(void);
void	SPI1_C0_IRQHandler(void);
void	SPI2_C0_IRQHandler(void);
void	USART1_C0_IRQHandler(void);
void	USART2_C0_IRQHandler(void);
void	USART3_C0_IRQHandler(void);
void	EXTI15_10_C0_IRQHandler(void);
void	RTC_ALARM_C0_IRQHandler(void);
void	TIM8_BRK_TIM12_C0_IRQHandler(void);
void	TIM8_UP_TIM13_C0_IRQHandler(void);
void	TIM8_TRG_COM_TIM14_C0_IRQHandler(void);
void	TIM8_CC_C0_IRQHandler(void);
void	DMA1_STR7_C0_IRQHandler(void);
void	FMC_C0_IRQHandler(void);
void	SDMMC1_C0_IRQHandler(void);
void	TIM5_C0_IRQHandler(void);
void	SPI3_C0_IRQHandler(void);
void	UART4_C0_IRQHandler(void);
void	UART5_C0_IRQHandler(void);
void	TIM6_DAC_C0_IRQHandler(void);
void	TIM7_C0_IRQHandler(void);
void	DMA2_STR0_C0_IRQHandler(void);
void	DMA2_STR1_C0_IRQHandler(void);
void	DMA2_STR2_C0_IRQHandler(void);
void	DMA2_STR3_C0_IRQHandler(void);
void	DMA2_STR4_C0_IRQHandler(void);
void	ETH_C0_IRQHandler(void);
void	ETH_WKUP_C0_IRQHandler(void);
void	FDCAN_CAL_C0_IRQHandler(void);
void	DMA2_STR5_C0_IRQHandler(void);
void	DMA2_STR6_C0_IRQHandler(void);
void	DMA2_STR7_C0_IRQHandler(void);
void	USART6_C0_IRQHandler(void);
void	I2C3_EV_C0_IRQHandler(void);
void	I2C3_ER_C0_IRQHandler(void);
void	OTG_HS_EP1_OUT_C0_IRQHandler(void);
void	OTG_HS_EP1_IN_C0_IRQHandler(void);
void	OTG_HS_WKUP_C0_IRQHandler(void);
void	OTG_HS_C0_IRQHandler(void);
void	DCMI_C0_IRQHandler(void);
void	HASH_RNG_C0_IRQHandler(void);
void	FPU_C0_IRQHandler(void);
void	UART7_C0_IRQHandler(void);
void	UART8_C0_IRQHandler(void);
void	SPI4_C0_IRQHandler(void);
void	SPI5_C0_IRQHandler(void);
void	SPI6_C0_IRQHandler(void);
void	SAI1_C0_IRQHandler(void);
void	LTDC_C0_IRQHandler(void);
void	LTDC_ER_C0_IRQHandler(void);
void	DMA2D_C0_IRQHandler(void);
void	SAI2_C0_IRQHandler(void);
void	QUADSPI_C0_IRQHandler(void);
void	LPTIM1_C0_IRQHandler(void);
void	CEC_C0_IRQHandler(void);
void	I2C4_EV_C0_IRQHandler(void);
void	I2C4_ER_C0_IRQHandler(void);
void	SPDIF_C0_IRQHandler(void);
void	OTG_FS_EP1_OUT_C0_IRQHandler(void);
void	OTG_FS_EP1_IN_C0_IRQHandler(void);
void	OTG_FS_WKUP_C0_IRQHandler(void);
void	OTG_FS_C0_IRQHandler(void);
void	DMAMUX1_OV_C0_IRQHandler(void);
void	HRTIM1_MST_C0_IRQHandler(void);
void	HRTIM1_TIMA_C0_IRQHandler(void);
void	HRTIM1_TIMB_C0_IRQHandler(void);
void	HRTIM1_TIMC_C0_IRQHandler(void);
void	HRTIM1_TIMD_C0_IRQHandler(void);
void	HRTIM1_TIME_C0_IRQHandler(void);
void	HRTIM1_FLT_C0_IRQHandler(void);
void	DFSDM1_FLT0_C0_IRQHandler(void);
void	DFSDM1_FLT1_C0_IRQHandler(void);
void	DFSDM1_FLT2_C0_IRQHandler(void);
void	DFSDM1_FLT3_C0_IRQHandler(void);
void	SAI3_C0_IRQHandler(void);
void	SWPMI1_C0_IRQHandler(void);
void	TIM15_C0_IRQHandler(void);
void	TIM16_C0_IRQHandler(void);
void	TIM17_C0_IRQHandler(void);
void	MDIOS_WKUP_C0_IRQHandler(void);
void	MDIOS_C0_IRQHandler(void);
void	JPEG_C0_IRQHandler(void);
void	MDMA_C0_IRQHandler(void);
void	SDMMC_C0_IRQHandler(void);
void	HSEM0_C0_IRQHandler(void);
void	ADC3_C0_IRQHandler(void);
void	DMAMUX2_OVR_C0_IRQHandler(void);
void	BDMA_CH0_C0_IRQHandler(void);
void	BDMA_CH1_C0_IRQHandler(void);
void	BDMA_CH2_C0_IRQHandler(void);
void	BDMA_CH3_C0_IRQHandler(void);
void	BDMA_CH4_C0_IRQHandler(void);
void	BDMA_CH5_C0_IRQHandler(void);
void	BDMA_CH6_C0_IRQHandler(void);
void	BDMA_CH7_C0_IRQHandler(void);
void	COMP_C0_IRQHandler(void);
void	LPTIM2_C0_IRQHandler(void);
void	LPTIM3_C0_IRQHandler(void);
void	LPTIM4_C0_IRQHandler(void);
void	LPTIM5_C0_IRQHandler(void);
void	LPUART_C0_IRQHandler(void);
void	WWDG1_RST_C0_IRQHandler(void);
void	CRS_C0_IRQHandler(void);
void	SAI4_C0_IRQHandler(void);
void	WKUP_C0_IRQHandler(void);

#if (defined(__cplusplus))
}
#endif
