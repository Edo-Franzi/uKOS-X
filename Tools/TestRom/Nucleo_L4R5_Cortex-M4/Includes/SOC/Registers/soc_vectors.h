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
; Goal:		Indirect Exception Vectors for Cortex_M4.
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

// Cortex_M4 Processor Exceptions Numbers

	NonMaskableInt_IRQn		= -14,	// Non Maskable Interrupt
	HardFault_IRQn			= -13,	// Hard Fault Interrupt
	MemoryManagement_IRQn	= -12,	// Memory Management Interrupt
	BusFault_IRQn			= -11,	// Bus Fault Interrupt
	UsageFault_IRQn			= -10,	// Usage Fault Interrupt
	SVCall_IRQn				= -5,	// SV Call Interrupt
	DebugMonitor_IRQn		= -4,	// Debug Monitor Interrupt
	PendSV_IRQn				= -2,	// Pend SV Interrupt
	SysTick_IRQn			= -1,	// System Tick Interrupt


// SOC Specific Interrupt Numbers

	WWDG_IRQn				= 0,	// Window Watchdog interrupt
	PVD_PVM_IRQn			= 1,	// PVD through EXTI line detection
	TAMP_STAMP_IRQn			= 2,	// Tamper and TimeStamp interrupts
	RTC_WKUP_IRQn			= 3,	// RTC Tamper or TimeStamp /CSS on LSE through EXTI line 19 interrupts
	FLASH_IRQn				= 4,	// Flash global interrupt
	RCC_IRQn				= 5,	// RCC global interrupt
	EXTI0_IRQn				= 6,	// EXTI Line 0 interrupt
	EXTI1_IRQn				= 7,	// EXTI Line 1 interrupt
	EXTI2_IRQn				= 8,	// EXTI Line 2 interrupt
	EXTI3_IRQn				= 9,	// EXTI Line 3 interrupt
	EXTI4_IRQn				= 10,	// EXTI Line 4 interrupt
	DMA1_CH1_IRQn			= 11,	// DMA1 Channel1 global interrupt
	DMA1_CH2_IRQn			= 12,	// DMA1 Channel2 global interrupt
	DMA1_CH3_IRQn			= 13,	// DMA1 Channel3 interrupt
	DMA1_CH4_IRQn			= 14,	// DMA1 Channel4 interrupt
	DMA1_CH5_IRQn			= 15,	// DMA1 Channel5 interrupt
	DMA1_CH6_IRQn			= 16,	// DMA1 Channel6 interrupt
	DMA1_CH7_IRQn			= 17,	// DMA1 Channel 7 interrupt
	ADC1_IRQn				= 18,	// ADC1 and ADC2 global interrupt
	CAN1_TX_IRQn			= 19,	// CAN1 TX interrupts
	CAN1_RX0_IRQn			= 20,	// CAN1 RX0 interrupts
	CAN1_RX1_IRQn			= 21,	// CAN1 RX1 interrupts
	CAN1_SCE_IRQn			= 22,	// CAN1 SCE interrupt
	EXTI9_5_IRQn			= 23,	// EXTI Line5 to Line9 interrupts
	TIM1_BRK_TIM15_IRQn		= 24,	// TIM1 Break/TIM15 global interrupts
	TIM1_UP_TIM16_IRQn		= 25,	// TIM1 Update/TIM16 global interrupts
	TIM1_TRG_COM_TIM17_IRQn	= 26,	// TIM1 Trigger and Commutation interrupts and TIM17 global interrupt
	TIM1_CC_IRQn			= 27,	// TIM1 Capture Compare interrupt
	TIM2_IRQn				= 28,	// TIM2 global interrupt
	TIM3_IRQn				= 29,	// TIM3 global interrupt
	TIM4_IRQn				= 30,	// TIM4 global interrupt
	I2C1_EV_IRQn			= 31,	// I2C1 event interrupt
	I2C1_ER_IRQn			= 32,	// I2C1 error interrupt
	I2C2_EV_IRQn			= 33,	// I2C2 event interrupt
	I2C2_ER_IRQn			= 34,	// I2C2 error interrupt
	SPI1_IRQn				= 35,	// SPI1 global interrupt
	SPI2_IRQn				= 36,	// SPI2 global interrupt
	USART1_IRQn				= 37,	// USART1 global interrupt
	USART2_IRQn				= 38,	// USART2 global interrupt
	USART3_IRQn				= 39,	// USART3 global interrupt
	EXTI15_10_IRQn			= 40,	// EXTI Lines 10 to 15 interrupts
	RTC_ALARM_IRQn			= 41,	// RTC alarms through EXTI line 18 interrupts
	DFSDM1_FLT3_IRQn		= 42,	// DFSDM1_FLT3 global interrupt
	TIM8_BRK_IRQn			= 43,	// TIM8 Break Interrupt
	TIM8_UP_IRQn			= 44,	// TIM8 Update Interrupt
	TIM8_TRG_COM_IRQn		= 45,	// TIM8 Trigger and Commutation Interrupt
	TIM8_CC_IRQn			= 46,	// TIM8 Capture Compare Interrupt
	ADC3_IRQn				= 47,	// ADC3 global interrupt
	FMC_IRQn				= 48,	// FMC global Interrupt
	SDMMC1_IRQn				= 49,	// SDMMC global Interrupt
	TIM5_IRQn				= 50,	// TIM5 global Interrupt
	SPI3_IRQn				= 51,	// SPI3 global Interrupt
	UART4_IRQn				= 52,	// UART4 global Interrupt
	UART5_IRQn				= 53,	// UART5 global Interrupt
	TIM6_DACUNDER_IRQn		= 54,	// TIM6 global and DAC1 and 2 underrun error interrupts
	TIM7_IRQn				= 55,	// TIM7 global interrupt
	DMA2_CH1_IRQn			= 56,	// DMA2 Channel 1 global Interrupt
	DMA2_CH2_IRQn			= 57,	// DMA2 Channel 2 global Interrupt
	DMA2_CH3_IRQn			= 58,	// DMA2 Channel 3 global Interrupt
	DMA2_CH4_IRQn			= 59,	// DMA2 Channel 4 global Interrupt
	DMA2_CH5_IRQn			= 60,	// DMA2 Channel 5 global Interrupt
	DFSDM1_FLT0_IRQn		= 61,	// DFSDM1_FLT0 global interrupt
	DFSDM1_FLT1_IRQn		= 62,	// DFSDM1_FLT1 global interrupt
	DFSDM1_FLT2_IRQn		= 63,	// DFSDM1_FLT2 global interrupt
	COMP_IRQn				= 64,	// COMP1 and COMP2 interrupts
	LPTIM1_IRQn				= 65,	// LP TIM1 interrupt
	LPTIM2_IRQn				= 66,	// LP TIM2 interrupt
	OTG_FS_IRQn				= 67,	// USB OTG FS global Interrupt
	DMA2_CH6_IRQn			= 68,	// DMA2 Channel 6 global Interrupt
	DMA2_CH7_IRQn			= 69,	// DMA2 Channel 7 global Interrupt
	LPUART1_IRQn			= 70,	// LPUART1 global interrupt
	OCTOSPI1_IRQn			= 71,	// OCTOSPI1 global interrupt
	I2C3_EV_IRQn			= 72,	// I2C3 event interrupt
	I2C3_ER_IRQn			= 73,	// I2C3 error interrupt
	SAI1_IRQn				= 74,	// SAI1 global interrupt
	SAI2_IRQn				= 75,	// SAI2 global interrupt
	OCTOSPI2_IRQn			= 76,	// OCTOSPI2 global interrupt
	TSC_IRQn				= 77,	// TSC global interrupt
	AES_IRQn				= 79,	// AES global interrupt
	RNG_HASH_IRQn			= 80,	// RNG and HASH global interrupt
	FPU_IRQn				= 81,	// Floating point interrupt
	CRS_IRQn				= 82,	// CRS global interrupt
	I2C4_ER_IRQn			= 83,	// I2C4 error interrupt
	I2C4_EV_IRQn			= 84,	// I2C4 event interrupt
	DCMI_IRQn				= 85,	// DCMI global interrupt
	DMA2D_IRQn				= 90,	// DMA2D global interrupt
	LCD_TFT_IRQn			= 91,	// LTDC global interrupt
	LCD_TFT_ER_IRQn			= 92,	// LTDC global error interrupt
	GFXMMU_IRQn				= 93,	// GFXMMU global error interrupt
	DMAMUX1_OVR_IRQn		= 94,	// DMAMUX Overrun interrupt
} IRQn_Type;

#define	KNB_EXCEPTIONS		14u
#define	KNB_INTERRUPTIONS	95u

// For the core 0
// --------------

// Cortex_M3 Processor Exceptions Numbers

#define	NonMaskableInt_C0_IRQn		NonMaskableInt_IRQn
#define	HardFault_C0_IRQn			HardFault_IRQn
#define	MemoryManagement_C0_IRQn	MemoryManagement_IRQn
#define	BusFault_C0_IRQn			BusFault_IRQn
#define	UsageFault_C0_IRQn			UsageFault_IRQn
#define	SVCall_C0_IRQn				SVCall_IRQn
#define	DebugMonitor_C0_IRQn		DebugMonitor_IRQn
#define	PendSV_C0_IRQn				PendSV_IRQn
#define	SysTick_C0_IRQn				SysTick_IRQn

// SOC Specific Interrupt Numbers

#define	WWDG_C0_IRQn				WWDG_IRQn
#define	PVD_PVM_C0_IRQn				PVD_PVM_IRQn
#define	TAMP_STAMP_C0_IRQn			TAMP_STAMP_IRQn
#define	RTC_WKUP_C0_IRQn			RTC_WKUP_IRQn
#define	FLASH_C0_IRQn				FLASH_IRQn
#define	RCC_C0_IRQn					RCC_IRQn
#define	EXTI0_C0_IRQn				EXTI0_IRQn
#define	EXTI1_C0_IRQn				EXTI1_IRQn
#define	EXTI2_C0_IRQn				EXTI2_IRQn
#define	EXTI3_C0_IRQn				EXTI3_IRQn
#define	EXTI4_C0_IRQn				EXTI4_IRQn
#define	DMA1_CH1_C0_IRQn			DMA1_CH1_IRQn
#define	DMA1_CH2_C0_IRQn			DMA1_CH2_IRQn
#define	DMA1_CH3_C0_IRQn			DMA1_CH3_IRQn
#define	DMA1_CH4_C0_IRQn			DMA1_CH4_IRQn
#define	DMA1_CH5_C0_IRQn			DMA1_CH5_IRQn
#define	DMA1_CH6_C0_IRQn			DMA1_CH6_IRQn
#define	DMA1_CH7_C0_IRQn			DMA1_CH7_IRQn
#define	ADC1_C0_IRQn				ADC1_IRQn
#define	CAN1_TX_C0_IRQn				CAN1_TX_IRQn
#define	CAN1_RX0_C0_IRQn			CAN1_RX0_IRQn
#define	CAN1_RX1_C0_IRQn			CAN1_RX1_IRQn
#define	CAN1_SCE_C0_IRQn			CAN1_SCE_IRQn
#define	EXTI9_5_C0_IRQn				EXTI9_5_IRQn
#define	TIM1_BRK_TIM15_C0_IRQn		TIM1_BRK_TIM15_IRQn
#define	TIM1_UP_TIM16_C0_IRQn		TIM1_UP_TIM16_IRQn
#define	TIM1_TRG_COM_TIM17_C0_IRQn	TIM1_TRG_COM_TIM17_IRQn
#define	TIM1_CC_C0_IRQn				TIM1_CC_IRQn
#define	TIM2_C0_IRQn				TIM2_IRQn
#define	TIM3_C0_IRQn				TIM3_IRQn
#define	TIM4_C0_IRQn				TIM4_IRQn
#define	I2C1_EV_C0_IRQn				I2C1_EV_IRQn
#define	I2C1_ER_C0_IRQn				I2C1_ER_IRQn
#define	I2C2_EV_C0_IRQn				I2C2_EV_IRQn
#define	I2C2_ER_C0_IRQn				I2C2_ER_IRQn
#define	SPI1_C0_IRQn				SPI1_IRQn
#define	SPI2_C0_IRQn				SPI2_IRQn
#define	USART1_C0_IRQn				USART1_IRQn
#define	USART2_C0_IRQn				USART2_IRQn
#define	USART3_C0_IRQn				USART3_IRQn
#define	EXTI15_10_C0_IRQn			EXTI15_10_IRQn
#define	RTC_ALARM_C0_IRQn			RTC_ALARM_IRQn
#define	DFSDM1_FLT3_C0_IRQn			DFSDM1_FLT3_IRQn
#define	TIM8_BRK_C0_IRQn			TIM8_BRK_IRQn
#define	TIM8_UP_C0_IRQn				TIM8_UP_IRQn
#define	TIM8_TRG_COM_C0_IRQn		TIM8_TRG_COM_IRQn
#define	TIM8_CC_C0_IRQn				TIM8_CC_IRQn
#define	ADC3_C0_IRQn				ADC3_IRQn
#define	FMC_C0_IRQn					FMC_IRQn
#define	SDMMC1_C0_IRQn				SDMMC1_IRQn
#define	TIM5_C0_IRQn				TIM5_IRQn
#define	SPI3_C0_IRQn				SPI3_IRQn
#define	UART4_C0_IRQn				UART4_IRQn
#define	UART5_C0_IRQn				UART5_IRQn
#define	TIM6_DACUNDER_C0_IRQn		TIM6_DACUNDER_IRQn
#define	TIM7_C0_IRQn				TIM7_IRQn
#define	DMA2_CH1_C0_IRQn			DMA2_CH1_IRQn
#define	DMA2_CH2_C0_IRQn			DMA2_CH2_IRQn
#define	DMA2_CH3_C0_IRQn			DMA2_CH3_IRQn
#define	DMA2_CH4_C0_IRQn			DMA2_CH4_IRQn
#define	DMA2_CH5_C0_IRQn			DMA2_CH5_IRQn
#define	DFSDM1_FLT0_C0_IRQn			DFSDM1_FLT0_IRQn
#define	DFSDM1_FLT1_C0_IRQn			DFSDM1_FLT1_IRQn
#define	DFSDM1_FLT2_C0_IRQn			DFSDM1_FLT2_IRQn
#define	COMP_C0_IRQn				COMP_IRQn
#define	LPTIM1_C0_IRQn				LPTIM1_IRQn
#define	LPTIM2_C0_IRQn				LPTIM2_IRQn
#define	OTG_FS_C0_IRQn				OTG_FS_IRQn
#define	DMA2_CH6_C0_IRQn			DMA2_CH6_IRQn
#define	DMA2_CH7_C0_IRQn			DMA2_CH7_IRQn
#define	LPUART1_C0_IRQn				LPUART1_IRQn
#define	OCTOSPI1_C0_IRQn			OCTOSPI1_IRQn
#define	I2C3_EV_C0_IRQn				I2C3_EV_IRQn
#define	I2C3_ER_C0_IRQn				I2C3_ER_IRQn
#define	SAI1_C0_IRQn				SAI1_IRQn
#define	SAI2_C0_IRQn				SAI2_IRQn
#define	OCTOSPI2_C0_IRQn			OCTOSPI2_IRQn
#define	TSC_C0_IRQn					TSC_IRQn
#define	AES_C0_IRQn					AES_IRQn
#define	RNG_HASH_C0_IRQn			RNG_HASH_IRQn
#define	FPU_C0_IRQn					FPU_IRQn
#define	CRS_C0_IRQn					CRS_IRQn
#define	I2C4_ER_C0_IRQn				I2C4_ER_IRQn
#define	I2C4_EV_C0_IRQn				I2C4_EV_IRQn
#define	DCMI_C0_IRQn				DCMI_IRQn
#define	DMA2D_C0_IRQn				DMA2D_IRQn
#define	LCD_TFT_C0_IRQn				LCD_TFT_IRQn
#define	LCD_TFT_ER_C0_IRQn			LCD_TFT_ER_IRQn
#define	GFXMMU_C0_IRQn				GFXMMU_IRQn
#define	DMAMUX1_OVR_C0_IRQn			DMAMUX1_OVR_IRQn

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

void	WWDG_C0_IRQHandler(void);
void	PVD_PVM_C0_IRQHandler(void);
void	TAMP_STAMP_C0_IRQHandler(void);
void	RTC_WKUP_C0_IRQHandler(void);
void	FLASH_C0_IRQHandler(void);
void	RCC_C0_IRQHandler(void);
void	EXTI0_C0_IRQHandler(void);
void	EXTI1_C0_IRQHandler(void);
void	EXTI2_C0_IRQHandler(void);
void	EXTI3_C0_IRQHandler(void);
void	EXTI4_C0_IRQHandler(void);
void	DMA1_CH1_C0_IRQHandler(void);
void	DMA1_CH2_C0_IRQHandler(void);
void	DMA1_CH3_C0_IRQHandler(void);
void	DMA1_CH4_C0_IRQHandler(void);
void	DMA1_CH5_C0_IRQHandler(void);
void	DMA1_CH6_C0_IRQHandler(void);
void	DMA1_CH7_C0_IRQHandler(void);
void	ADC1_C0_IRQHandler(void);
void	CAN1_TX_C0_IRQHandler(void);
void	CAN1_RX0_C0_IRQHandler(void);
void	CAN1_RX1_C0_IRQHandler(void);
void	CAN1_SCE_C0_IRQHandler(void);
void	EXTI9_5_C0_IRQHandler(void);
void	TIM1_BRK_TIM15_C0_IRQHandler(void);
void	TIM1_UP_TIM16_C0_IRQHandler(void);
void	TIM1_TRG_COM_TIM17_C0_IRQHandler(void);
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
void	DFSDM1_FLT3_C0_IRQHandler(void);
void	TIM8_BRK_C0_IRQHandler(void);
void	TIM8_UP_C0_IRQHandler(void);
void	TIM8_TRG_COM_C0_IRQHandler(void);
void	TIM8_CC_C0_IRQHandler(void);
void	ADC3_C0_IRQHandler(void);
void	FMC_C0_IRQHandler(void);
void	SDMMC1_C0_IRQHandler(void);
void	TIM5_C0_IRQHandler(void);
void	SPI3_C0_IRQHandler(void);
void	UART4_C0_IRQHandler(void);
void	UART5_C0_IRQHandler(void);
void	TIM6_DACUNDER_C0_IRQHandler(void);
void	TIM7_C0_IRQHandler(void);
void	DMA2_CH1_C0_IRQHandler(void);
void	DMA2_CH2_C0_IRQHandler(void);
void	DMA2_CH3_C0_IRQHandler(void);
void	DMA2_CH4_C0_IRQHandler(void);
void	DMA2_CH5_C0_IRQHandler(void);
void	DFSDM1_FLT0_C0_IRQHandler(void);
void	DFSDM1_FLT1_C0_IRQHandler(void);
void	DFSDM1_FLT2_C0_IRQHandler(void);
void	COMP_C0_IRQHandler(void);
void	LPTIM1_C0_IRQHandler(void);
void	LPTIM2_C0_IRQHandler(void);
void	OTG_FS_C0_IRQHandler(void);
void	DMA2_CH6_C0_IRQHandler(void);
void	DMA2_CH7_C0_IRQHandler(void);
void	LPUART1_C0_IRQHandler(void);
void	OCTOSPI1_C0_IRQHandler(void);
void	I2C3_EV_C0_IRQHandler(void);
void	I2C3_ER_C0_IRQHandler(void);
void	SAI1_C0_IRQHandler(void);
void	SAI2_C0_IRQHandler(void);
void	OCTOSPI2_C0_IRQHandler(void);
void	TSC_C0_IRQHandler(void);
void	AES_C0_IRQHandler(void);
void	RNG_HASH_C0_IRQHandler(void);
void	FPU_C0_IRQHandler(void);
void	CRS_C0_IRQHandler(void);
void	I2C4_ER_C0_IRQHandler(void);
void	I2C4_EV_C0_IRQHandler(void);
void	DCMI_C0_IRQHandler(void);
void	DMA2D_C0_IRQHandler(void);
void	LCD_TFT_C0_IRQHandler(void);
void	LCD_TFT_ER_C0_IRQHandler(void);
void	GFXMMU_C0_IRQHandler(void);
void	DMAMUX1_OVR_C0_IRQHandler(void);

#if (defined(__cplusplus))
}
#endif
