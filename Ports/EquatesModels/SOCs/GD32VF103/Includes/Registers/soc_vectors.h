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
; Goal:		Indirect Exception Vectors for RISC-V.
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

// CORE RISC-V Processor Exceptions Numbers

	MSIP_IRQn					= 3,		// Software interrupt
	MTIP_IRQn					= 7,		// CPU Timer interrupt
	BWEI_IRQn					= 17,		// Bus Error interrupt
	PMOVI_IRQn					= 18,		// Performance Monitor

// GD32 specific Interrupt Numbers

	WWDGT_IRQn					= 19,		// window watchDog timer interrupt
	LVD_IRQn					= 20,		// LVD through EXTI line detect interrupt
	TAMPER_IRQn					= 21,		// tamper through EXTI line detect
	RTC_IRQn					= 22,		// RTC alarm interrupt
	FMC_IRQn					= 23,		// FMC interrupt
	RCU_CTC_IRQn				= 24,		// RCU and CTC interrupt
	EXTI0_IRQn					= 25,		// EXTI line 0 interrupts
	EXTI1_IRQn					= 26,		// EXTI line 1 interrupts
	EXTI2_IRQn					= 27,		// EXTI line 2 interrupts
	EXTI3_IRQn					= 28,		// EXTI line 3 interrupts
	EXTI4_IRQn					= 29,		// EXTI line 4 interrupts
	DMA0_Channel0_IRQn			= 30,		// DMA0 channel0 interrupt
	DMA0_Channel1_IRQn			= 31,		// DMA0 channel1 interrupt
	DMA0_Channel2_IRQn			= 32,		// DMA0 channel2 interrupt
	DMA0_Channel3_IRQn			= 33,		// DMA0 channel3 interrupt
	DMA0_Channel4_IRQn			= 34,		// DMA0 channel4 interrupt
	DMA0_Channel5_IRQn			= 35,		// DMA0 channel5 interrupt
	DMA0_Channel6_IRQn			= 36,		// DMA0 channel6 interrupt
	ADC0_1_IRQn					= 37,		// ADC0 and ADC1 interrupt
	CAN0_TX_IRQn				= 38,		// CAN0 TX interrupts
	CAN0_RX0_IRQn				= 39,		// CAN0 RX0 interrupts
	CAN0_RX1_IRQn				= 40,		// CAN0 RX1 interrupts
	CAN0_EWMC_IRQn				= 41,		// CAN0 EWMC interrupts
	EXTI5_9_IRQn				= 42,		// EXTI[9:5] interrupts
	TIMER0_BRK_IRQn				= 43,		// TIMER0 break interrupts
	TIMER0_UP_IRQn				= 44,		// TIMER0 update interrupts
	TIMER0_TRG_CMT_IRQn			= 45,		// TIMER0 trigger and commutation interrupts
	TIMER0_Channel_IRQn			= 46,		// TIMER0 channel capture compare interrupts
	TIMER1_IRQn					= 47,		// TIMER1 interrupt
	TIMER2_IRQn					= 48,		// TIMER2 interrupt
	TIMER3_IRQn					= 49,		// TIMER3 interrupts
	I2C0_EV_IRQn				= 50,		// I2C0 event interrupt
	I2C0_ER_IRQn				= 51,		// I2C0 error interrupt
	I2C1_EV_IRQn				= 52,		// I2C1 event interrupt
	I2C1_ER_IRQn				= 53,		// I2C1 error interrupt
	SPI0_IRQn					= 54,		// SPI0 interrupt
	SPI1_IRQn					= 55,		// SPI1 interrupt
	USART0_IRQn					= 56,		// USART0 interrupt
	USART1_IRQn					= 57,		// USART1 interrupt
	USART2_IRQn					= 58,		// USART2 interrupt
	EXTI10_15_IRQn				= 59,		// EXTI[15:10] interrupts
	RTC_Alarm_IRQn				= 60,		// RTC alarm interrupt EXTI
	USBFS_WKUP_IRQn				= 61,		// USBFS wakeup interrupt
	EXMC_IRQn					= 67,		// EXMC global interrupt
	TIMER4_IRQn					= 69,		// TIMER4 global interrupt
	SPI2_IRQn					= 70,		// SPI2 global interrupt
	UART3_IRQn					= 71,		// UART3 global interrupt
	UART4_IRQn					= 72,		// UART4 global interrupt
	TIMER5_IRQn					= 73,		// TIMER5 global interrupt
	TIMER6_IRQn					= 74,		// TIMER6 global interrupt
	DMA1_Channel0_IRQn			= 75,		// DMA1 channel0 global interrupt
	DMA1_Channel1_IRQn			= 76,		// DMA1 channel1 global interrupt
	DMA1_Channel2_IRQn			= 77,		// DMA1 channel2 global interrupt
	DMA1_Channel3_IRQn			= 78,		// DMA1 channel3 global interrupt
	DMA1_Channel4_IRQn			= 79,		// DMA1 channel3 global interrupt
	CAN1_TX_IRQn				= 82,		// CAN1 TX interrupt
	CAN1_RX0_IRQn				= 83,		// CAN1 RX0 interrupt
	CAN1_RX1_IRQn				= 84,		// CAN1 RX1 interrupt
	CAN1_EWMC_IRQn				= 85,		// CAN1 EWMC interrupt
	USBFS_IRQn					= 86		// USBFS global interrupt
} IRQn_Type;

#define	KNB_EXCEPTIONS			19u
#define	KNB_INTERRUPTIONS		87u

// For the core 0
// --------------

// RISC-V Processor Exceptions Numbers

#define	MSIP_C0_IRQn			MSIP_IRQn
#define	MTIP_C0_IRQn			MTIP_IRQn
#define	BWEI_C0_IRQn			BWEI_IRQn
#define	PMOVI_C0_IRQn			PMOVI_IRQn

// SOC Specific Interrupt Numbers

#define	WWDGT_C0_IRQn			WWDGT_IRQn
#define	LVD_C0_IRQn				LVD_IRQn
#define	TAMPER_C0_IRQn			TAMPER_IRQn
#define	RTC_C0_IRQn				RTC_IRQn
#define	FMC_C0_IRQn				FMC_IRQn
#define	RCU_CTC_C0_IRQn			RCU_CTC_IRQn
#define	EXTI0_C0_IRQn			EXTI0_IRQn
#define	EXTI1_C0_IRQn			EXTI1_IRQn
#define	EXTI2_C0_IRQn			EXTI2_IRQn
#define	EXTI3_C0_IRQn			EXTI3_IRQn
#define	EXTI4_C0_IRQn			EXTI4_IRQn
#define	DMA0_Channel0_C0_IRQn	DMA0_Channel0_IRQn
#define	DMA0_Channel1_C0_IRQn	DMA0_Channel1_IRQn
#define	DMA0_Channel2_C0_IRQn	DMA0_Channel2_IRQn
#define	DMA0_Channel3_C0_IRQn	DMA0_Channel3_IRQn
#define	DMA0_Channel4_C0_IRQn	DMA0_Channel4_IRQn
#define	DMA0_Channel5_C0_IRQn	DMA0_Channel5_IRQn
#define	DMA0_Channel6_C0_IRQn	DMA0_Channel6_IRQn
#define	ADC0_1_C0_IRQn			ADC0_1_IRQn
#define	CAN0_TX_C0_IRQn			CAN0_TX_IRQn
#define	CAN0_RX0_C0_IRQn		CAN0_RX0_IRQn
#define	CAN0_RX1_C0_IRQn		CAN0_RX1_IRQn
#define	CAN0_EWMC_C0_IRQn		CAN0_EWMC_IRQn
#define	EXTI5_9_C0_IRQn			EXTI5_9_IRQn
#define	TIMER0_BRK_C0_IRQn		TIMER0_BRK_IRQn
#define	TIMER0_UP_C0_IRQn		TIMER0_UP_IRQn
#define	TIMER0_TRG_CMT_C0_IRQn	TIMER0_TRG_CMT_IRQn
#define	TIMER0_Channel_C0_IRQn	TIMER0_Channel_IRQn
#define	TIMER1_C0_IRQn			TIMER1_IRQn
#define	TIMER2_C0_IRQn			TIMER2_IRQn
#define	TIMER3_C0_IRQn			TIMER3_IRQn
#define	I2C0_EV_C0_IRQn			I2C0_EV_IRQn
#define	I2C0_ER_C0_IRQn			I2C0_ER_IRQn
#define	I2C1_EV_C0_IRQn			I2C1_EV_IRQn
#define	I2C1_ER_C0_IRQn			I2C1_ER_IRQn
#define	SPI0_C0_IRQn			SPI0_IRQn
#define	SPI1_C0_IRQn			SPI1_IRQn
#define	USART0_C0_IRQn			USART0_IRQn
#define	USART1_C0_IRQn			USART1_IRQn
#define	USART2_C0_IRQn			USART2_IRQn
#define	EXTI10_15_C0_IRQn		EXTI10_15_IRQn
#define	RTC_Alarm_C0_IRQn		RTC_Alarm_IRQn
#define	USBFS_WKUP_C0_IRQn		USBFS_WKUP_IRQn
#define	EXMC_C0_IRQn			EXMC_IRQn
#define	TIMER4_C0_IRQn			TIMER4_IRQn
#define	SPI2_C0_IRQn			SPI2_IRQn
#define	UART3_C0_IRQn			UART3_IRQn
#define	UART4_C0_IRQn			UART4_IRQn
#define	TIMER5_C0_IRQn			TIMER5_IRQn
#define	TIMER6_C0_IRQn			TIMER6_IRQn
#define	DMA1_Channel0_C0_IRQn	DMA1_Channel0_IRQn
#define	DMA1_Channel1_C0_IRQn	DMA1_Channel1_IRQn
#define	DMA1_Channel2_C0_IRQn	DMA1_Channel2_IRQn
#define	DMA1_Channel3_C0_IRQn	DMA1_Channel3_IRQn
#define	DMA1_Channel4_C0_IRQn	DMA1_Channel4_IRQn
#define	CAN1_TX_C0_IRQn			CAN1_TX_IRQn
#define	CAN1_RX0_C0_IRQn		CAN1_RX0_IRQn
#define	CAN1_RX1_C0_IRQn		CAN1_RX1_IRQn
#define	CAN1_EWMC_C0_IRQn		CAN1_EWMC_IRQn
#define	USBFS_C0_IRQn			USBFS_IRQn

// Prototypes

#if (defined(__cplusplus))
extern	"C" {
#endif

// For the core 0
// --------------

// Exceptions

void	MSIP_C0_IRQHandler(void);
void	MTIP_C0_IRQHandler(void);
void	BWEI_C0_IRQHandler(void);
void	PMOVI_C0_IRQHandler(void);

// IRQHandler

void	WWDGT_C0_IRQHandler(void);
void	LVD_C0_IRQHandler(void);
void	TAMPER_C0_IRQHandler(void);
void	RTC_C0_IRQHandler(void);
void	FMC_C0_IRQHandler(void);
void	RCU_CTC_C0_IRQHandler(void);
void	EXTI0_C0_IRQHandler(void);
void	EXTI1_C0_IRQHandler(void);
void	EXTI2_C0_IRQHandler(void);
void	EXTI3_C0_IRQHandler(void);
void	EXTI4_C0_IRQHandler(void);
void	DMA0_Channel0_C0_IRQHandler(void);
void	DMA0_Channel1_C0_IRQHandler(void);
void	DMA0_Channel2_C0_IRQHandler(void);
void	DMA0_Channel3_C0_IRQHandler(void);
void	DMA0_Channel4_C0_IRQHandler(void);
void	DMA0_Channel5_C0_IRQHandler(void);
void	DMA0_Channel6_C0_IRQHandler(void);
void	ADC0_1_C0_IRQHandler(void);
void	CAN0_TX_C0_IRQHandler(void);
void	CAN0_RX0_C0_IRQHandler(void);
void	CAN0_RX1_C0_IRQHandler(void);
void	CAN0_EWMC_C0_IRQHandler(void);
void	EXTI5_9_C0_IRQHandler(void);
void	TIMER0_BRK_C0_IRQHandler(void);
void	TIMER0_UP_C0_IRQHandler(void);
void	TIMER0_TRG_CMT_C0_IRQHandler(void);
void	TIMER0_Channel_C0_IRQHandler(void);
void	TIMER1_C0_IRQHandler(void);
void	TIMER2_C0_IRQHandler(void);
void	TIMER3_C0_IRQHandler(void);
void	I2C0_EV_C0_IRQHandler(void);
void	I2C0_ER_C0_IRQHandler(void);
void	I2C1_EV_C0_IRQHandler(void);
void	I2C1_ER_C0_IRQHandler(void);
void	SPI0_C0_IRQHandler(void);
void	SPI1_C0_IRQHandler(void);
void	USART0_C0_IRQHandler(void);
void	USART1_C0_IRQHandler(void);
void	USART2_C0_IRQHandler(void);
void	EXTI10_15_C0_IRQHandler(void);
void	RTC_Alarm_C0_IRQHandler(void);
void	USBFS_WKUP_C0_IRQHandler(void);
void	EXMC_C0_IRQHandler(void);
void	TIMER4_C0_IRQHandler(void);
void	SPI2_C0_IRQHandler(void);
void	UART3_C0_IRQHandler(void);
void	UART4_C0_IRQHandler(void);
void	TIMER5_C0_IRQHandler(void);
void	TIMER6_C0_IRQHandler(void);
void	DMA1_Channel0_C0_IRQHandler(void);
void	DMA1_Channel1_C0_IRQHandler(void);
void	DMA1_Channel2_C0_IRQHandler(void);
void	DMA1_Channel3_C0_IRQHandler(void);
void	DMA1_Channel4_C0_IRQHandler(void);
void	CAN1_TX_C0_IRQHandler(void);
void	CAN1_RX0_C0_IRQHandler(void);
void	CAN1_RX1_C0_IRQHandler(void);
void	CAN1_EWMC_C0_IRQHandler(void);
void	USBFS_C0_IRQHandler(void);

#if (defined(__cplusplus))
}
#endif
