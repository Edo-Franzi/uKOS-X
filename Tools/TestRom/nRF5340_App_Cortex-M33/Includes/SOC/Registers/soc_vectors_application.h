/*
; soc_vectors_application.
; ========================
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

	FPU_IRQn				= 0,	//
	CACHE_IRQn				= 1,	//
	SPU_IRQn				= 3,	//
	CLOCK_POWER_IRQn		= 5,	//
	SERIAL0_IRQn			= 8,	//
	SERIAL1_IRQn			= 9,	//
	SPIM4_IRQn				= 10,	//
	SERIAL2_IRQn			= 11,	//
	SERIAL3_IRQn			= 12,	//
	GPIOTE0_IRQn			= 13,	//
	SAADC_IRQn				= 14,	//
	TIMER0_IRQn				= 15,	//
	TIMER1_IRQn				= 16,	//
	TIMER2_IRQn				= 17,	//
	RTC0_IRQn				= 20,	//
	RTC1_IRQn				= 21,	//
	WDT0_IRQn				= 24,	//
	WDT1_IRQn				= 25,	//
	COMP_LPCOMP_IRQn		= 26,	//
	EGU0_IRQn				= 27,	//
	EGU1_IRQn				= 28,	//
	EGU2_IRQn				= 29,	//
	EGU3_IRQn				= 30,	//
	EGU4_IRQn				= 31,	//
	EGU5_IRQn				= 32,	//
	PWM0_IRQn				= 33,	//
	PWM1_IRQn				= 34,	//
	PWM2_IRQn				= 35,	//
	PWM3_IRQn				= 36,	//
	PDM0_IRQn				= 38,	//
	I2S0_IRQn				= 40,	//
	IPC_IRQn				= 42,	//
	QSPI_IRQn				= 43,	//
	NFCT_IRQn				= 45,	//
	GPIOTE1_IRQn			= 47,	//
	QDEC0_IRQn				= 51,	//
	QDEC1_IRQn				= 52,	//
	USBD_IRQn				= 54,	//
	USBREGULATOR_IRQn		= 55,	//
	KMU_IRQn				= 57,	//
	CRYPTOCELL_IRQn			= 68,	//
} IRQn_Type;

#define	KNB_EXCEPTIONS		14u
#define	KNB_INTERRUPTIONS	69u

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

#define	FPU_C0_IRQn					FPU_IRQn
#define	CACHE_C0_IRQn				CACHE_IRQn
#define	SPU_C0_IRQn					SPU_IRQn
#define	CLOCK_POWER_C0_IRQn			CLOCK_POWER_IRQn
#define	SERIAL0_C0_IRQn				SERIAL0_IRQn
#define	SERIAL1_C0_IRQn				SERIAL1_IRQn
#define	SPIM4_C0_IRQn				SPIM4_IRQn
#define	SERIAL2_C0_IRQn				SERIAL2_IRQn
#define	SERIAL3_C0_IRQn				SERIAL3_IRQn
#define	GPIOTE0_C0_IRQn				GPIOTE0_IRQn
#define	SAADC_C0_IRQn				SAADC_IRQn
#define	TIMER0_C0_IRQn				TIMER0_IRQn
#define	TIMER1_C0_IRQn				TIMER1_IRQn
#define	TIMER2_C0_IRQn				TIMER2_IRQn
#define	RTC0_C0_IRQn				RTC0_IRQn
#define	RTC1_C0_IRQn				RTC1_IRQn
#define	WDT0_C0_IRQn				WDT0_IRQn
#define	WDT1_C0_IRQn				WDT1_IRQn
#define	COMP_LPCOMP_C0_IRQn			COMP_LPCOMP_IRQn
#define	EGU0_C0_IRQn				EGU0_IRQn
#define	EGU1_C0_IRQn				EGU1_IRQn
#define	EGU2_C0_IRQn				EGU2_IRQn
#define	EGU3_C0_IRQn				EGU3_IRQn
#define	EGU4_C0_IRQn				EGU4_IRQn
#define	EGU5_C0_IRQn				EGU5_IRQn
#define	PWM0_C0_IRQn				PWM0_IRQn
#define	PWM1_C0_IRQn				PWM1_IRQn
#define	PWM2_C0_IRQn				PWM2_IRQn
#define	PWM3_C0_IRQn				PWM3_IRQn
#define	PDM0_C0_IRQn				PDM0_IRQn
#define	I2S0_C0_IRQn				I2S0_IRQn
#define	IPC_C0_IRQn					IPC_IRQn
#define	QSPI_C0_IRQn				QSPI_IRQn
#define	NFCT_C0_IRQn				NFCT_IRQn
#define	GPIOTE1_C0_IRQn				GPIOTE1_IRQn
#define	QDEC0_C0_IRQn				QDEC0_IRQn
#define	QDEC1_C0_IRQn				QDEC1_IRQn
#define	USBD_C0_IRQn				USBD_IRQn
#define	USBREGULATOR_C0_IRQn		USBREGULATOR_IRQn
#define	KMU_C0_IRQn					KMU_IRQn
#define	CRYPTOCELL_C0_IRQn			CRYPTOCELL_IRQn

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

void	FPU_C0_IRQHandler(void);
void	CACHE_C0_IRQHandler(void);
void	SPU_C0_IRQHandler(void);
void	CLOCK_POWER_C0_IRQHandler(void);
void	SERIAL0_C0_IRQHandler(void);
void	SERIAL1_C0_IRQHandler(void);
void	SPIM4_C0_IRQHandler(void);
void	SERIAL2_C0_IRQHandler(void);
void	SERIAL3_C0_IRQHandler(void);
void	GPIOTE0_C0_IRQHandler(void);
void	SAADC_C0_IRQHandler(void);
void	TIMER0_C0_IRQHandler(void);
void	TIMER1_C0_IRQHandler(void);
void	TIMER2_C0_IRQHandler(void);
void	RTC0_C0_IRQHandler(void);
void	RTC1_C0_IRQHandler(void);
void	WDT0_C0_IRQHandler(void);
void	WDT1_C0_IRQHandler(void);
void	COMP_LPCOMP_C0_IRQHandler(void);
void	EGU0_C0_IRQHandler(void);
void	EGU1_C0_IRQHandler(void);
void	EGU2_C0_IRQHandler(void);
void	EGU3_C0_IRQHandler(void);
void	EGU4_C0_IRQHandler(void);
void	EGU5_C0_IRQHandler(void);
void	PWM0_C0_IRQHandler(void);
void	PWM1_C0_IRQHandler(void);
void	PWM2_C0_IRQHandler(void);
void	PWM3_C0_IRQHandler(void);
void	PDM0_C0_IRQHandler(void);
void	I2S0_C0_IRQHandler(void);
void	IPC_C0_IRQHandler(void);
void	QSPI_C0_IRQHandler(void);
void	NFCT_C0_IRQHandler(void);
void	GPIOTE1_C0_IRQHandler(void);
void	QDEC0_C0_IRQHandler(void);
void	QDEC1_C0_IRQHandler(void);
void	USBD_C0_IRQHandler(void);
void	USBREGULATOR_C0_IRQHandler(void);
void	KMU_C0_IRQHandler(void);
void	CRYPTOCELL_C0_IRQHandler(void);

#if (defined(__cplusplus))
}
#endif
