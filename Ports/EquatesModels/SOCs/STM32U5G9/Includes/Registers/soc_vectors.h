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

	WWDG_IRQn				= 0,	// Window Watchdog interrupt
	PVD_PVM_IRQn			= 1,	// Power voltage monitor/Analog voltage monitor
	RTC_IRQn				= 2,	// RTC global non-secure interrupts
	RTC_S_IRQn				= 3,	// RTC global secure interrupts
	TAMP_IRQn				= 4,	// Tamper global interrupts
	RAMCFG_IRQn				= 5,	// RAM configuration global interrupt
	FLASH_IRQn				= 6,	// Flash memory non-secure global interrupt
	FLASH_S_IRQn			= 7,	// Flash memory secure global interrupt
	GTZC_IRQn				= 8,	// GTZC1/GTZC2 global interrupt
	RCC_IRQn				= 9,	// RCC non-secure global interrupt
	RCC_S_IRQn				= 10,	// RCC secure global interrupt
	EXTI0_IRQn				= 11,	// EXTI line0 interrupt
	EXTI1_IRQn				= 12,	// EXTI line1 interrupt
	EXTI2_IRQn				= 13,	// EXTI line2 interrupt
	EXTI3_IRQn				= 14,	// EXTI line3 interrupt
	EXTI4_IRQn				= 15,	// EXTI line4 interrupt
	EXTI5_IRQn				= 16,	// EXTI line5 interrupt
	EXTI6_IRQn				= 17,	// EXTI line6 interrupt
	EXTI7_IRQn				= 18,	// EXTI line7 interrupt
	EXTI8_IRQn				= 19,	// EXTI line8 interrupt
	EXTI9_IRQn				= 20,	// EXTI line9 interrupt
	EXTI10_IRQn				= 21,	// EXTI line10 interrupt
	EXTI11_IRQn				= 22,	// EXTI line11 interrupt
	EXTI12_IRQn				= 23,	// EXTI line12 interrupt
	EXTI13_IRQn				= 24,	// EXTI line13 interrupt
	EXTI14_IRQn				= 25,	// EXTI line14 interrupt
	EXTI15_IRQn				= 26,	// EXTI line15 interrupt
	IWDG_IRQn				= 27,	// Independent watchdog interrupt
	SAES_IRQn				= 28,	// Secure AES
	GPDMA1_CH0_IRQn			= 29,	// GPDMA1 channel 0 global interrupt
	GPDMA1_CH1_IRQn			= 30,	// GPDMA1 channel 1 global interrupt
	GPDMA1_CH2_IRQn			= 31,	// GPDMA1 channel 2 global interrupt
	GPDMA1_CH3_IRQn			= 32,	// GPDMA1 channel 3 global interrupt
	GPDMA1_CH4_IRQn			= 33,	// GPDMA1 channel 4 global interrupt
	GPDMA1_CH5_IRQn			= 34,	// GPDMA1 channel 5 global interrupt
	GPDMA1_CH6_IRQn			= 35,	// GPDMA1 channel 6 global interrupt
	GPDMA1_CH7_IRQn			= 36,	// GPDMA1 channel 7 global interrupt
	ADC12_IRQn				= 37,	// ADC1 (14 bits) global interrupt
	DAC1_IRQn				= 38,	// DAC1 global interrupt
	FDCAN1_IT0_IRQn			= 39,	// FDCAN1 Interrupt 0
	FDCAN1_IT1_IRQn			= 40,	// FDCAN1 Interrupt 1
	TIM1_BRK_IRQn			= 41,	// TIM1 Break - transition error -index error
	TIM1_UP_IRQn			= 42,	// TIM1 Update
	TIM1_TRG_COM_IRQn		= 43,	// TIM1 Trigger and Commutation - direction change interrupt -index
	TIM1_CC_IRQn			= 44,	// TIM1 Capture Compare interrupt
	TIM2_IRQn				= 45,	// TIM2 global interrupt
	TIM3_IRQn				= 46,	// TIM3 global interrupt
	TIM4_IRQn				= 47,	// TIM4 global interrupt
	TIM5_IRQn				= 48,	// TIM5 global interrupt
	TIM6_IRQn				= 49,	// TIM6 global interrupt
	TIM7_IRQn				= 50,	// TIM7 global interrupt
	TIM8_BRK_IRQn			= 51,	// TIM8 Break Interrupt
	TIM8_UP_IRQn			= 52,	// TIM8 Update Interrupt
	TIM8_TRG_COM_IRQn		= 53,	// TIM8 Trigger and Commutation Interrupt
	TIM8_CC_IRQn			= 54,	// TIM8 Capture Compare Interrupt
	I2C1_EV_IRQn			= 55,	// I2C1 event interrupt
	I2C1_ER_IRQn			= 56,	// I2C1 error interrupt
	I2C2_EV_IRQn			= 57,	// I2C2 event interrupt
	I2C2_ER_IRQn			= 58,	// I2C2 error interrupt
	SPI1_IRQn				= 59,	// SPI1 global interrupt
	SPI2_IRQn				= 60,	// SPI2 global interrupt
	USART1_IRQn				= 61,	// USART1 global interrupt
	USART2_IRQn				= 62,	// USART2 global interrupt
	USART3_IRQn				= 63,	// USART3 global interrupt
	UART4_IRQn				= 64,	// UART4 global interrupt
	UART5_IRQn				= 65,	// UART5 global interrupt
	LPUART1_IRQn			= 66,	// LPUART1 global interrupt
	LPTIM1_IRQn				= 67,	// LPTIM1 global interrupt
	LPTIM2_IRQn				= 68,	// LPTIM2 global interrupt
	TIM15_IRQn				= 69,	// TIM15 global interrupt
	TIM16_IRQn				= 70,	// TIM16 global interrupt
	TIM17_IRQn				= 71,	// TIM17 global interrupt
	COMP_IRQn				= 72,	// COMP1 and COMP2 interrupts
	OTG_HS_IRQn				= 73,	// USB OTG global interrupt
	CRS_IRQn				= 74,	// Clock recovery system global interrupt
	FMC_IRQn				= 75,	// FMC global interrupt
	OCTOSPI1_IRQn			= 76,	// OCTOSPI1 global interrupt
	PWR_S3WU_IRQn			= 77,	// PWR wakeup from Stop 3 interrupt
	SDMMC1_IRQn				= 78,	// SDMMC1 global interrupt
	SDMMC2_IRQn				= 79,	// SDMMC2 global interrupt
	GPDMA1_CH8_IRQn			= 80,	// GPDMA1 channel 8 global interrupt
	GPDMA1_CH9_IRQn			= 81,	// GPDMA1 channel 9 global interrupt
	GPDMA1_CH10_IRQn		= 82,	// GPDMA1 channel 10 global interrupt
	GPDMA1_CH11_IRQn		= 83,	// GPDMA1 channel 11 global interrupt
	GPDMA1_CH12_IRQn		= 84,	// GPDMA1 channel 12 global interrupt
	GPDMA1_CH13_IRQn		= 85,	// GPDMA1 channel 13 global interrupt
	GPDMA1_CH14_IRQn		= 86,	// GPDMA1 channel 14 global interrupt
	GPDMA1_CH15_IRQn		= 87,	// GPDMA1 channel 15 global interrupt
	I2C3_EV_IRQn			= 88,	// I2C3 event interrupt
	I2C3_ER_IRQn			= 89,	// I2C3 error interrupt
	SAI1_IRQn				= 90,	// SAI1 global interrupt
	SAI2_IRQn				= 91,	// SAI2 global interrupt
	TSC_IRQn				= 92,	// TSC global interrupt
	AES_IRQn				= 93,	// AES global interrupt
	RNG_IRQn				= 94,	// RNG global interrupt
	FPU_IRQn				= 95,	// Floating point interrupt
	HASH_IRQn				= 96,	// HASH interrupt
	PKA_IRQn				= 97,	// PKA global interrupt
	LPTIM3_IRQn				= 98,	// LPTIM3 global interrupt
	SPI3_IRQn				= 99,	// SPI3 global interrupt
	I2C4_ER_IRQn			= 100,	// I2C4 error interrupt
	I2C4_EV_IRQn			= 101,	// I2C4 event interrupt
	MDF1_FLT0_IRQn			= 102,	// MDF1 filter 0 global interrupt
	MDF1_FLT1_IRQn			= 103,	// MDF1 filter 1 global interrupt
	MDF1_FLT2_IRQn			= 104,	// MDF1 filter 2 global interrupt
	MDF1_FLT3_IRQn			= 105,	// MDF1 filter 3 global interrupt
	UCPD1_IRQn				= 106,	// UCPD1 global interrupt
	ICACHE_IRQn				= 107,	// Instruction cache global interrupt
	OTFDEC1_IRQn			= 108,	// OTFDEC1 secure global interrupt
	OTFDEC2_IRQn			= 109,	// OTFDEC2 secure global interrupt
	LPTIM4_IRQn				= 110,	// LPTIM4 global interrupt
	DCACHE1_IRQn			= 111,	// Data cache global interrupt
	ADF1_FLT0_IRQn			= 112,	// ADF1 filter 0 global interrupt
	ADC4_IRQn				= 113,	// ADC4 (12 bits) global interrupt
	LPDMA1_CH0_IRQn			= 114,	// LPDMA1 SmartRun channel 0 global interrupt
	LPDMA1_CH1_IRQn			= 115,	// LPDMA1 SmartRun channel 1 global interrupt
	LPDMA1_CH2_IRQn			= 116,	// LPDMA1 SmartRun channel 2 global interrupt
	LPDMA1_CH3_IRQn			= 117,	// LPDMA1 SmartRun channel 3 global interrupt
	DMA2D_IRQn				= 118,	// DMA2D global interrupt
	DCMI_PSSI_IRQn			= 119,	// DCMI/PSSI global interrupt
	OCTOSPI2_IRQn			= 120,	// OCTOSPI2 global interrupt
	MDF1_FLT4_IRQn			= 121,	// MDF1 filter 4 global interrupt
	MDF1_FLT5_IRQn			= 122,	// MDF1 filter 5 global interrupt
	CORDIC_IRQn				= 123,	// CORDIC interrupt
	FMAC_IRQn				= 124,	// FMAC interrupt
	LSECSSD_IRQn			= 125,	// LSECSSD interrupt
	USART6_IRQn				= 126,	// USART6 global interrupt
	I2C5_ER_IRQn			= 127,	// I2C5 error interrupt
	I2C5_EV_IRQn			= 128,	// I2C5 event interrupt
	I2C6_ER_IRQn			= 129,	// I2C6 error interrupt
	I2C6_EV_IRQn			= 130,	// I2C6 event interrupt
	HSPI1_IRQn				= 131,	// Hexadeca-SPI1 global interrupt
	GPU2D_IRQ_IRQn			= 132,	// GPU2D interrupt
	GPU2D_IRQSYS_IRQn		= 133,	// GPU2D system interrupt
	GFXMMU_IRQn				= 134,	// GFXMMU global error interrupt
	LCD_TFT_IRQn			= 135,	// LTDC global interrupt
	LCD_TFT_ERR_IRQn		= 136,	// LTDC global error interrupt
	DSIHOST_IRQn			= 137,	// DSI global interrupt
	DCACHE2_IRQn			= 138,	// Data cache 2 global interrupt
	GFXTIM_IRQn				= 139,	// GFXTIM global interrupt
	JPEG_IRQn				= 140,	// JPEG sync interrupt
} IRQn_Type;

#define	KNB_EXCEPTIONS		14u
#define	KNB_INTERRUPTIONS	141u

// For the core 0
// --------------

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

#define	WWDG_C0_IRQn				WWDG_IRQn
#define	PVD_PVM_C0_IRQn				PVD_PVM_IRQn
#define	RTC_C0_IRQn					RTC_IRQn
#define	RTC_S_C0_IRQn				RTC_S_IRQn
#define	TAMP_C0_IRQn				TAMP_IRQn
#define	RAMCFG_C0_IRQn				RAMCFG_IRQn
#define	FLASH_C0_IRQn				FLASH_IRQn
#define	FLASH_S_C0_IRQn				FLASH_S_IRQn
#define	GTZC_C0_IRQn				GTZC_IRQn
#define	RCC_C0_IRQn					RCC_IRQn
#define	RCC_S_C0_IRQn				RCC_S_IRQn
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
#define	IWDG_C0_IRQn				IWDG_IRQn
#define	SAES_C0_IRQn				SAES_IRQn
#define	GPDMA1_CH0_C0_IRQn			GPDMA1_CH0_IRQn
#define	GPDMA1_CH1_C0_IRQn			GPDMA1_CH1_IRQn
#define	GPDMA1_CH2_C0_IRQn			GPDMA1_CH2_IRQn
#define	GPDMA1_CH3_C0_IRQn			GPDMA1_CH3_IRQn
#define	GPDMA1_CH4_C0_IRQn			GPDMA1_CH4_IRQn
#define	GPDMA1_CH5_C0_IRQn			GPDMA1_CH5_IRQn
#define	GPDMA1_CH6_C0_IRQn			GPDMA1_CH6_IRQn
#define	GPDMA1_CH7_C0_IRQn			GPDMA1_CH7_IRQn
#define	ADC12_C0_IRQn				ADC12_IRQn
#define	DAC1_C0_IRQn				DAC1_IRQn
#define	FDCAN1_IT0_C0_IRQn			FDCAN1_IT0_IRQn
#define	FDCAN1_IT1_C0_IRQn			FDCAN1_IT1_IRQn
#define	TIM1_BRK_C0_IRQn			TIM1_BRK_IRQn
#define	TIM1_UP_C0_IRQn				TIM1_UP_IRQn
#define	TIM1_TRG_COM_C0_IRQn		TIM1_TRG_COM_IRQn
#define	TIM1_CC_C0_IRQn				TIM1_CC_IRQn
#define	TIM2_C0_IRQn				TIM2_IRQn
#define	TIM3_C0_IRQn				TIM3_IRQn
#define	TIM4_C0_IRQn				TIM4_IRQn
#define	TIM5_C0_IRQn				TIM5_IRQn
#define	TIM6_C0_IRQn				TIM6_IRQn
#define	TIM7_C0_IRQn				TIM7_IRQn
#define	TIM8_BRK_C0_IRQn			TIM8_BRK_IRQn
#define	TIM8_UP_C0_IRQn				TIM8_UP_IRQn
#define	TIM8_TRG_COM_C0_IRQn		TIM8_TRG_COM_IRQn
#define	TIM8_CC_C0_IRQn				TIM8_CC_IRQn
#define	I2C1_EV_C0_IRQn				I2C1_EV_IRQn
#define	I2C1_ER_C0_IRQn				I2C1_ER_IRQn
#define	I2C2_EV_C0_IRQn				I2C2_EV_IRQn
#define	I2C2_ER_C0_IRQn				I2C2_ER_IRQn
#define	SPI1_C0_IRQn				SPI1_IRQn
#define	SPI2_C0_IRQn				SPI2_IRQn
#define	USART1_C0_IRQn				USART1_IRQn
#define	USART2_C0_IRQn				USART2_IRQn
#define	USART3_C0_IRQn				USART3_IRQn
#define	UART4_C0_IRQn				UART4_IRQn
#define	UART5_C0_IRQn				UART5_IRQn
#define	LPUART1_C0_IRQn				LPUART1_IRQn
#define	LPTIM1_C0_IRQn				LPTIM1_IRQn
#define	LPTIM2_C0_IRQn				LPTIM2_IRQn
#define	TIM15_C0_IRQn				TIM15_IRQn
#define	TIM16_C0_IRQn				TIM16_IRQn
#define	TIM17_C0_IRQn				TIM17_IRQn
#define	COMP_C0_IRQn				COMP_IRQn
#define	OTG_HS_C0_IRQn				OTG_HS_IRQn
#define	CRS_C0_IRQn					CRS_IRQn
#define	FMC_C0_IRQn					FMC_IRQn
#define	OCTOSPI1_C0_IRQn			OCTOSPI1_IRQn
#define	PWR_S3WU_C0_IRQn			PWR_S3WU_IRQn
#define	SDMMC1_C0_IRQn				SDMMC1_IRQn
#define	SDMMC2_C0_IRQn				SDMMC2_IRQn
#define	GPDMA1_CH8_C0_IRQn			GPDMA1_CH8_IRQn
#define	GPDMA1_CH9_C0_IRQn			GPDMA1_CH9_IRQn
#define	GPDMA1_CH10_C0_IRQn			GPDMA1_CH10_IRQn
#define	GPDMA1_CH11_C0_IRQn			GPDMA1_CH11_IRQn
#define	GPDMA1_CH12_C0_IRQn			GPDMA1_CH12_IRQn
#define	GPDMA1_CH13_C0_IRQn			GPDMA1_CH13_IRQn
#define	GPDMA1_CH14_C0_IRQn			GPDMA1_CH14_IRQn
#define	GPDMA1_CH15_C0_IRQn			GPDMA1_CH15_IRQn
#define	I2C3_EV_C0_IRQn				I2C3_EV_IRQn
#define	I2C3_ER_C0_IRQn				I2C3_ER_IRQn
#define	SAI1_C0_IRQn				SAI1_IRQn
#define	SAI2_C0_IRQn				SAI2_IRQn
#define	TSC_C0_IRQn					TSC_IRQn
#define	AES_C0_IRQn					AES_IRQn
#define	RNG_C0_IRQn					RNG_IRQn
#define	FPU_C0_IRQn					FPU_IRQn
#define	HASH_C0_IRQn				HASH_IRQn
#define	PKA_C0_IRQn					PKA_IRQn
#define	LPTIM3_C0_IRQn				LPTIM3_IRQn
#define	SPI3_C0_IRQn				SPI3_IRQn
#define	I2C4_ER_C0_IRQn				I2C4_ER_IRQn
#define	I2C4_EV_C0_IRQn				I2C4_EV_IRQn
#define	MDF1_FLT0_C0_IRQn			MDF1_FLT0_IRQn
#define	MDF1_FLT1_C0_IRQn			MDF1_FLT1_IRQn
#define	MDF1_FLT2_C0_IRQn			MDF1_FLT2_IRQn
#define	MDF1_FLT3_C0_IRQn			MDF1_FLT3_IRQn
#define	UCPD1_C0_IRQn				UCPD1_IRQn
#define	ICACHE_C0_IRQn				ICACHE_IRQn
#define	OTFDEC1_C0_IRQn				OTFDEC1_IRQn
#define	OTFDEC2_C0_IRQn				OTFDEC2_IRQn
#define	LPTIM4_C0_IRQn				LPTIM4_IRQn
#define	DCACHE1_C0_IRQn				DCACHE1_IRQn
#define	ADF1_FLT0_C0_IRQn			ADF1_FLT0_IRQn
#define	ADC4_C0_IRQn				ADC4_IRQn
#define	LPDMA1_CH0_C0_IRQn			LPDMA1_CH0_IRQn
#define	LPDMA1_CH1_C0_IRQn			LPDMA1_CH1_IRQn
#define	LPDMA1_CH2_C0_IRQn			LPDMA1_CH2_IRQn
#define	LPDMA1_CH3_C0_IRQn			LPDMA1_CH3_IRQn
#define	DMA2D_C0_IRQn				DMA2D_IRQn
#define	DCMI_PSSI_C0_IRQn			DCMI_PSSI_IRQn
#define	OCTOSPI2_C0_IRQn			OCTOSPI2_IRQn
#define	MDF1_FLT4_C0_IRQn			MDF1_FLT4_IRQn
#define	MDF1_FLT5_C0_IRQn			MDF1_FLT5_IRQn
#define	CORDIC_C0_IRQn				CORDIC_IRQn
#define	FMAC_C0_IRQn				FMAC_IRQn
#define	LSECSSD_C0_IRQn				LSECSSD_IRQn
#define	USART6_C0_IRQn				USART6_IRQn
#define	I2C5_ER_C0_IRQn				I2C5_ER_IRQn
#define	I2C5_EV_C0_IRQn				I2C5_EV_IRQn
#define	I2C6_ER_C0_IRQn				I2C6_ER_IRQn
#define	I2C6_EV_C0_IRQn				I2C6_EV_IRQn
#define	HSPI1_C0_IRQn				HSPI1_IRQn
#define	GPU2D_IRQ_C0_IRQn			GPU2D_IRQ_IRQn
#define	GPU2D_IRQSYS_C0_IRQn		GPU2D_IRQSYS_IRQn
#define	GFXMMU_C0_IRQn				GFXMMU_IRQn
#define	LCD_TFT_C0_IRQn				LCD_TFT_IRQn
#define	LCD_TFT_ERR_C0_IRQn			LCD_TFT_ERR_IRQn
#define	DSIHOST_C0_IRQn				DSIHOST_IRQn
#define	DCACHE2_C0_IRQn				DCACHE2_IRQn
#define	GFXTIM_C0_IRQn				GFXTIM_IRQn
#define	JPEG_C0_IRQn				JPEG_IRQn

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
void	SecureFault_C0_IRQHandler(void);
void	SVCall_C0_IRQHandler(void);
void	DebugMonitor_C0_IRQHandler(void);
void	PendSV_C0_IRQHandler(void);
void	SysTick_C0_IRQHandler(void);

// IRQHandler

void	WWDG_C0_IRQHandler(void);
void	PVD_PVM_C0_IRQHandler(void);
void	RTC_C0_IRQHandler(void);
void	RTC_S_C0_IRQHandler(void);
void	TAMP_C0_IRQHandler(void);
void	RAMCFG_C0_IRQHandler(void);
void	FLASH_C0_IRQHandler(void);
void	FLASH_S_C0_IRQHandler(void);
void	GTZC_C0_IRQHandler(void);
void	RCC_C0_IRQHandler(void);
void	RCC_S_C0_IRQHandler(void);
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
void	IWDG_C0_IRQHandler(void);
void	SAES_C0_IRQHandler(void);
void	GPDMA1_CH0_C0_IRQHandler(void);
void	GPDMA1_CH1_C0_IRQHandler(void);
void	GPDMA1_CH2_C0_IRQHandler(void);
void	GPDMA1_CH3_C0_IRQHandler(void);
void	GPDMA1_CH4_C0_IRQHandler(void);
void	GPDMA1_CH5_C0_IRQHandler(void);
void	GPDMA1_CH6_C0_IRQHandler(void);
void	GPDMA1_CH7_C0_IRQHandler(void);
void	ADC12_C0_IRQHandler(void);
void	DAC1_C0_IRQHandler(void);
void	FDCAN1_IT0_C0_IRQHandler(void);
void	FDCAN1_IT1_C0_IRQHandler(void);
void	TIM1_BRK_C0_IRQHandler(void);
void	TIM1_UP_C0_IRQHandler(void);
void	TIM1_TRG_COM_C0_IRQHandler(void);
void	TIM1_CC_C0_IRQHandler(void);
void	TIM2_C0_IRQHandler(void);
void	TIM3_C0_IRQHandler(void);
void	TIM4_C0_IRQHandler(void);
void	TIM5_C0_IRQHandler(void);
void	TIM6_C0_IRQHandler(void);
void	TIM7_C0_IRQHandler(void);
void	TIM8_BRK_C0_IRQHandler(void);
void	TIM8_UP_C0_IRQHandler(void);
void	TIM8_TRG_COM_C0_IRQHandler(void);
void	TIM8_CC_C0_IRQHandler(void);
void	I2C1_EV_C0_IRQHandler(void);
void	I2C1_ER_C0_IRQHandler(void);
void	I2C2_EV_C0_IRQHandler(void);
void	I2C2_ER_C0_IRQHandler(void);
void	SPI1_C0_IRQHandler(void);
void	SPI2_C0_IRQHandler(void);
void	USART1_C0_IRQHandler(void);
void	USART2_C0_IRQHandler(void);
void	USART3_C0_IRQHandler(void);
void	UART4_C0_IRQHandler(void);
void	UART5_C0_IRQHandler(void);
void	LPUART1_C0_IRQHandler(void);
void	LPTIM1_C0_IRQHandler(void);
void	LPTIM2_C0_IRQHandler(void);
void	TIM15_C0_IRQHandler(void);
void	TIM16_C0_IRQHandler(void);
void	TIM17_C0_IRQHandler(void);
void	COMP_C0_IRQHandler(void);
void	OTG_HS_C0_IRQHandler(void);
void	CRS_C0_IRQHandler(void);
void	FMC_C0_IRQHandler(void);
void	OCTOSPI1_C0_IRQHandler(void);
void	PWR_S3WU_C0_IRQHandler(void);
void	SDMMC1_C0_IRQHandler(void);
void	SDMMC2_C0_IRQHandler(void);
void	GPDMA1_CH8_C0_IRQHandler(void);
void	GPDMA1_CH9_C0_IRQHandler(void);
void	GPDMA1_CH10_C0_IRQHandler(void);
void	GPDMA1_CH11_C0_IRQHandler(void);
void	GPDMA1_CH12_C0_IRQHandler(void);
void	GPDMA1_CH13_C0_IRQHandler(void);
void	GPDMA1_CH14_C0_IRQHandler(void);
void	GPDMA1_CH15_C0_IRQHandler(void);
void	I2C3_EV_C0_IRQHandler(void);
void	I2C3_ER_C0_IRQHandler(void);
void	SAI1_C0_IRQHandler(void);
void	SAI2_C0_IRQHandler(void);
void	TSC_C0_IRQHandler(void);
void	AES_C0_IRQHandler(void);
void	RNG_C0_IRQHandler(void);
void	FPU_C0_IRQHandler(void);
void	HASH_C0_IRQHandler(void);
void	PKA_C0_IRQHandler(void);
void	LPTIM3_C0_IRQHandler(void);
void	SPI3_C0_IRQHandler(void);
void	I2C4_ER_C0_IRQHandler(void);
void	I2C4_EV_C0_IRQHandler(void);
void	MDF1_FLT0_C0_IRQHandler(void);
void	MDF1_FLT1_C0_IRQHandler(void);
void	MDF1_FLT2_C0_IRQHandler(void);
void	MDF1_FLT3_C0_IRQHandler(void);
void	UCPD1_C0_IRQHandler(void);
void	ICACHE_C0_IRQHandler(void);
void	OTFDEC1_C0_IRQHandler(void);
void	OTFDEC2_C0_IRQHandler(void);
void	LPTIM4_C0_IRQHandler(void);
void	DCACHE1_C0_IRQHandler(void);
void	ADF1_FLT0_C0_IRQHandler(void);
void	ADC4_C0_IRQHandler(void);
void	LPDMA1_CH0_C0_IRQHandler(void);
void	LPDMA1_CH1_C0_IRQHandler(void);
void	LPDMA1_CH2_C0_IRQHandler(void);
void	LPDMA1_CH3_C0_IRQHandler(void);
void	DMA2D_C0_IRQHandler(void);
void	DCMI_PSSI_C0_IRQHandler(void);
void	OCTOSPI2_C0_IRQHandler(void);
void	MDF1_FLT4_C0_IRQHandler(void);
void	MDF1_FLT5_C0_IRQHandler(void);
void	CORDIC_C0_IRQHandler(void);
void	FMAC_C0_IRQHandler(void);
void	LSECSSD_C0_IRQHandler(void);
void	USART6_C0_IRQHandler(void);
void	I2C5_ER_C0_IRQHandler(void);
void	I2C5_EV_C0_IRQHandler(void);
void	I2C6_ER_C0_IRQHandler(void);
void	I2C6_EV_C0_IRQHandler(void);
void	HSPI1_C0_IRQHandler(void);
void	GPU2D_IRQ_C0_IRQHandler(void);
void	GPU2D_IRQSYS_C0_IRQHandler(void);
void	GFXMMU_C0_IRQHandler(void);
void	LCD_TFT_C0_IRQHandler(void);
void	LCD_TFT_ERR_C0_IRQHandler(void);
void	DSIHOST_C0_IRQHandler(void);
void	DCACHE2_C0_IRQHandler(void);
void	GFXTIM_C0_IRQHandler(void);
void	JPEG_C0_IRQHandler(void);

#if (defined(__cplusplus))
}
#endif
