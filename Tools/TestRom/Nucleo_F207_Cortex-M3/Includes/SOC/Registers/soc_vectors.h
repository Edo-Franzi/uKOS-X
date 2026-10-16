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
; Goal:		Indirect Exception Vectors for Cortex_M3.
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

// Cortex_M3 Processor Exceptions Numbers

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
	PVD_IRQn				= 1,	// PVD through EXTI line detection interrupt
	TAMP_STAMP_IRQn			= 2,	// Tamper and TimeStamp interrupts through the EXTI line
	RTC_WKUP_IRQn			= 3,	// RTC Wakeup interrupt through the EXTI        line
	FLASH_IRQn				= 4,	// FlASH global interrupt
	RCC_IRQn				= 5,	// RCC global interrupt
	EXTI0_IRQn				= 6,	// EXTI Line0 interrupt
	EXTI1_IRQn				= 7,	// EXTI Line1 interrupt
	EXTI2_IRQn				= 8,	// EXTI Line2 interrupt
	EXTI3_IRQn				= 9,	// EXTI Line3 interrupt
	EXTI4_IRQn				= 10,	// EXTI Line4 interrupt
	DMA1_STREAM0_IRQn		= 11,	// DMA1 Stream0 global interrupt
	DMA1_STREAM1_IRQn		= 12,	// DMA1 Stream1 global interrupt
	DMA1_STREAM2_IRQn		= 13,	// DMA1 Stream2 global interrupt
	DMA1_STREAM3_IRQn		= 14,	// DMA1 Stream3 global interrupt
	DMA1_STREAM4_IRQn		= 15,	// DMA1 Stream4 global interrupt
	DMA1_STREAM5_IRQn		= 16,	// DMA1 Stream5 global interrupt
	DMA1_STREAM6_IRQn		= 17,	// DMA1 Stream6 global interrupt
	ADC_IRQn				= 18,	// ADC1 global interrupt
	CAN1_TX_IRQn			= 19,	// CAN1 TX interrupts
	CAN1_RX0_IRQn			= 20,	// CAN1 RX0 interrupts
	CAN1_RX1_IRQn			= 21,	// CAN1 RX1 interrupts
	CAN1_SCE_IRQn			= 22,	// CAN1 SCE interrupt
	EXTI9_5_IRQn			= 23,	// EXTI Line[9:5] interrupts
	TIM1_BRK_TIM9_IRQn		= 24,	// TIM1 Break interrupt and TIM9 global interrupt
	TIM1_UP_TIM10_IRQn		= 25,	// TIM1 Update interrupt and TIM10 global interrupt
	TIM1_TRG_COM_TIM11_IRQn	= 26,	// TIM1 Trigger and Commutation interrupts and TIM11 global interrupt
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
	EXTI15_10_IRQn			= 40,	// EXTI Line[15:10] interrupts
	RTC_ALARM_IRQn			= 41,	// RTC Alarms (A and B) through EXTI line interrupt
	OTG_FS_WKUP_IRQn		= 42,	// USB On-The-Go FS Wakeup through EXTI line interrupt
	TIM8_BRK_TIM12_IRQn		= 43,	// TIM8 Break interrupt and TIM12 global interrupt
	TIM8_UP_TIM13_IRQn		= 44,	// TIM8 Update interrupt and TIM13 global interrupt
	TIM8_TRG_COM_TIM14_IRQn	= 45,	// TIM8 Trigger and Commutation interrupts and TIM14 global interrupt
	TIM8_CC_IRQn			= 46,	// TIM8 Capture Compare interrupt
	DMA1_STREAM7_IRQn		= 47,	// DMA1 Stream7 global interrupt
	FSMC_IRQn				= 48,	// FSMC global interrupt
	SDIO_IRQn				= 49,	// SDIO global interrupt
	TIM5_IRQn				= 50,	// TIM5 global interrupt
	SPI3_IRQn				= 51,	// SPI3 global interrupt
	UART4_IRQn				= 52,	// UART4 global interrupt
	UART5_IRQn				= 53,	// UART5 global interrupt
	TIM6_DAC_IRQn			= 54,	// TIM6 global interrupt, DAC1 and DAC2 underrun error interrupt
	TIM7_IRQn				= 55,	// TIM7 global interrupt
	DMA2_STREAM0_IRQn		= 56,	// DMA2 Stream0 global interrupt
	DMA2_STREAM1_IRQn		= 57,	// DMA2 Stream1 global interrupt
	DMA2_STREAM2_IRQn		= 58,	// DMA2 Stream2 global interrupt
	DMA2_STREAM3_IRQn		= 59,	// DMA2 Stream3 global interrupt
	DMA2_STREAM4_IRQn		= 60,	// DMA2 Stream4 global interrupt
	ETH_IRQn				= 61,	// Ethernet global interrupt
	ETH_WKUP_IRQn			= 62,	// Ethernet Wakeup through EXTI line interrupt
	CAN2_TX_IRQn			= 63,	// CAN2 TX interrupts
	CAN2_RX0_IRQn			= 64,	// CAN2 RX0 interrupts
	CAN2_RX1_IRQn			= 65,	// CAN2 RX1 interrupts
	CAN2_SCE_IRQn			= 66,	// CAN2 SCE interrupt
	OTG_FS_IRQn				= 67,	// USB On The Go FS global interrupt
	DMA2_STREAM5_IRQn		= 68,	// DMA2 Stream5 global interrupt
	DMA2_STREAM6_IRQn		= 69,	// DMA2 Stream6 global interrupt
	DMA2_STREAM7_IRQn		= 70,	// DMA2 Stream7 global interrupt
	USART6_IRQn				= 71,	// USART6 global interrupt
	I2C3_EV_IRQn			= 72,	// I2C3 event interrupt
	I2C3_ER_IRQn			= 73,	// I2C3 error interrupt
	OTG_HS_EP1_OUT_IRQn		= 74,	// USB On The Go HS End Point 1 Out global interrupt
	OTG_HS_EP1_IN_IRQn		= 75,	// USB On The Go HS End Point 1 In global interrupt
	OTG_HS_WKUP_IRQn		= 76,	// USB On The Go HS Wakeup through EXTI interrupt
	OTG_HS_IRQn				= 77,	// USB On The Go HS global interrupt
	DCMI_IRQn				= 78,	// DCMI global interrupt
	CRYP_IRQn				= 79,	// CRYP crypto global interrupt
	HASH_RNG_IRQn			= 80,	// Hash and Rng global interrupt
} IRQn_Type;

#define	KNB_EXCEPTIONS		14u
#define	KNB_INTERRUPTIONS	81u

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
#define	PVD_C0_IRQn					PVD_IRQn
#define	TAMP_STAMP_C0_IRQn			TAMP_STAMP_IRQn
#define	RTC_WKUP_C0_IRQn			RTC_WKUP_IRQn
#define	FLASH_C0_IRQn				FLASH_IRQn
#define	RCC_C0_IRQn					RCC_IRQn
#define	EXTI0_C0_IRQn				EXTI0_IRQn
#define	EXTI1_C0_IRQn				EXTI1_IRQn
#define	EXTI2_C0_IRQn				EXTI2_IRQn
#define	EXTI3_C0_IRQn				EXTI3_IRQn
#define	EXTI4_C0_IRQn				EXTI4_IRQn
#define	DMA1_STREAM0_C0_IRQn		DMA1_STREAM0_IRQn
#define	DMA1_STREAM1_C0_IRQn		DMA1_STREAM1_IRQn
#define	DMA1_STREAM2_C0_IRQn		DMA1_STREAM2_IRQn
#define	DMA1_STREAM3_C0_IRQn		DMA1_STREAM3_IRQn
#define	DMA1_STREAM4_C0_IRQn		DMA1_STREAM4_IRQn
#define	DMA1_STREAM5_C0_IRQn		DMA1_STREAM5_IRQn
#define	DMA1_STREAM6_C0_IRQn		DMA1_STREAM6_IRQn
#define	ADC_C0_IRQn					ADC_IRQn
#define	CAN1_TX_C0_IRQn				CAN1_TX_IRQn
#define	CAN1_RX0_C0_IRQn			CAN1_RX0_IRQn
#define	CAN1_RX1_C0_IRQn			CAN1_RX1_IRQn
#define	CAN1_SCE_C0_IRQn			CAN1_SCE_IRQn
#define	EXTI9_5_C0_IRQn				EXTI9_5_IRQn
#define	TIM1_BRK_TIM9_C0_IRQn		TIM1_BRK_TIM9_IRQn
#define	TIM1_UP_TIM10_C0_IRQn		TIM1_UP_TIM10_IRQn
#define	TIM1_TRG_COM_TIM11_C0_IRQn	TIM1_TRG_COM_TIM11_IRQn
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
#define	OTG_FS_WKUP_C0_IRQn			OTG_FS_WKUP_IRQn
#define	TIM8_BRK_TIM12_C0_IRQn		TIM8_BRK_TIM12_IRQn
#define	TIM8_UP_TIM13_C0_IRQn		TIM8_UP_TIM13_IRQn
#define	TIM8_TRG_COM_TIM14_C0_IRQn	TIM8_TRG_COM_TIM14_IRQn
#define	TIM8_CC_C0_IRQn				TIM8_CC_IRQn
#define	DMA1_STREAM7_C0_IRQn		DMA1_STREAM7_IRQn
#define	FSMC_C0_IRQn				FSMC_IRQn
#define	SDIO_C0_IRQn				SDIO_IRQn
#define	TIM5_C0_IRQn				TIM5_IRQn
#define	SPI3_C0_IRQn				SPI3_IRQn
#define	UART4_C0_IRQn				UART4_IRQn
#define	UART5_C0_IRQn				UART5_IRQn
#define	TIM6_DAC_C0_IRQn			TIM6_DAC_IRQn
#define	TIM7_C0_IRQn				TIM7_IRQn
#define	DMA2_STREAM0_C0_IRQn		DMA2_STREAM0_IRQn
#define	DMA2_STREAM1_C0_IRQn		DMA2_STREAM1_IRQn
#define	DMA2_STREAM2_C0_IRQn		DMA2_STREAM2_IRQn
#define	DMA2_STREAM3_C0_IRQn		DMA2_STREAM3_IRQn
#define	DMA2_STREAM4_C0_IRQn		DMA2_STREAM4_IRQn
#define	ETH_C0_IRQn					ETH_IRQn
#define	ETH_WKUP_C0_IRQn			ETH_WKUP_IRQn
#define	CAN2_TX_C0_IRQn				CAN2_TX_IRQn
#define	CAN2_RX0_C0_IRQn			CAN2_RX0_IRQn
#define	CAN2_RX1_C0_IRQn			CAN2_RX1_IRQn
#define	CAN2_SCE_C0_IRQn			CAN2_SCE_IRQn
#define	OTG_FS_C0_IRQn				OTG_FS_IRQn
#define	DMA2_STREAM5_C0_IRQn		DMA2_STREAM5_IRQn
#define	DMA2_STREAM6_C0_IRQn		DMA2_STREAM6_IRQn
#define	DMA2_STREAM7_C0_IRQn		DMA2_STREAM7_IRQn
#define	USART6_C0_IRQn				USART6_IRQn
#define	I2C3_EV_C0_IRQn				I2C3_EV_IRQn
#define	I2C3_ER_C0_IRQn				I2C3_ER_IRQn
#define	OTG_HS_EP1_OUT_C0_IRQn		OTG_HS_EP1_OUT_IRQn
#define	OTG_HS_EP1_IN_C0_IRQn		OTG_HS_EP1_IN_IRQn
#define	OTG_HS_WKUP_C0_IRQn			OTG_HS_WKUP_IRQn
#define	OTG_HS_C0_IRQn				OTG_HS_IRQn
#define	DCMI_C0_IRQn				DCMI_IRQn
#define	CRYP_C0_IRQn				CRYP_IRQn
#define	HASH_RNG_C0_IRQn			HASH_RNG_IRQn

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
void	PVD_C0_IRQHandler(void);
void	TAMP_STAMP_C0_IRQHandler(void);
void	RTC_WKUP_C0_IRQHandler(void);
void	FLASH_C0_IRQHandler(void);
void	RCC_C0_IRQHandler(void);
void	EXTI0_C0_IRQHandler(void);
void	EXTI1_C0_IRQHandler(void);
void	EXTI2_C0_IRQHandler(void);
void	EXTI3_C0_IRQHandler(void);
void	EXTI4_C0_IRQHandler(void);
void	DMA1_STREAM0_C0_IRQHandler(void);
void	DMA1_STREAM1_C0_IRQHandler(void);
void	DMA1_STREAM2_C0_IRQHandler(void);
void	DMA1_STREAM3_C0_IRQHandler(void);
void	DMA1_STREAM4_C0_IRQHandler(void);
void	DMA1_STREAM5_C0_IRQHandler(void);
void	DMA1_STREAM6_C0_IRQHandler(void);
void	ADC_C0_IRQHandler(void);
void	CAN1_TX_C0_IRQHandler(void);
void	CAN1_RX0_C0_IRQHandler(void);
void	CAN1_RX1_C0_IRQHandler(void);
void	CAN1_SCE_C0_IRQHandler(void);
void	EXTI9_5_C0_IRQHandler(void);
void	TIM1_BRK_TIM9_C0_IRQHandler(void);
void	TIM1_UP_TIM10_C0_IRQHandler(void);
void	TIM1_TRG_COM_TIM11_C0_IRQHandler(void);
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
void	OTG_FS_WKUP_C0_IRQHandler(void);
void	TIM8_BRK_TIM12_C0_IRQHandler(void);
void	TIM8_UP_TIM13_C0_IRQHandler(void);
void	TIM8_TRG_COM_TIM14_C0_IRQHandler(void);
void	TIM8_CC_C0_IRQHandler(void);
void	DMA1_STREAM7_C0_IRQHandler(void);
void	FSMC_C0_IRQHandler(void);
void	SDIO_C0_IRQHandler(void);
void	TIM5_C0_IRQHandler(void);
void	SPI3_C0_IRQHandler(void);
void	UART4_C0_IRQHandler(void);
void	UART5_C0_IRQHandler(void);
void	TIM6_DAC_C0_IRQHandler(void);
void	TIM7_C0_IRQHandler(void);
void	DMA2_STREAM0_C0_IRQHandler(void);
void	DMA2_STREAM1_C0_IRQHandler(void);
void	DMA2_STREAM2_C0_IRQHandler(void);
void	DMA2_STREAM3_C0_IRQHandler(void);
void	DMA2_STREAM4_C0_IRQHandler(void);
void	ETH_C0_IRQHandler(void);
void	ETH_WKUP_C0_IRQHandler(void);
void	CAN2_TX_C0_IRQHandler(void);
void	CAN2_RX0_C0_IRQHandler(void);
void	CAN2_RX1_C0_IRQHandler(void);
void	CAN2_SCE_C0_IRQHandler(void);
void	OTG_FS_C0_IRQHandler(void);
void	DMA2_STREAM5_C0_IRQHandler(void);
void	DMA2_STREAM6_C0_IRQHandler(void);
void	DMA2_STREAM7_C0_IRQHandler(void);
void	USART6_C0_IRQHandler(void);
void	I2C3_EV_C0_IRQHandler(void);
void	I2C3_ER_C0_IRQHandler(void);
void	OTG_HS_EP1_OUT_C0_IRQHandler(void);
void	OTG_HS_EP1_IN_C0_IRQHandler(void);
void	OTG_HS_WKUP_C0_IRQHandler(void);
void	OTG_HS_C0_IRQHandler(void);
void	DCMI_C0_IRQHandler(void);
void	CRYP_C0_IRQHandler(void);
void	HASH_RNG_C0_IRQHandler(void);

#if (defined(__cplusplus))
}
#endif
