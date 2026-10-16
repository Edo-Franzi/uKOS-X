/*
; soc_vectors_network.
; ====================
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

	CLOCK_POWER_IRQn		= 5,	//
	RADIO_IRQn				= 8,	//
	RNG_IRQn				= 9,	//
	GPIOTE_IRQn				= 10,	//
	WDT_IRQn				= 11,	//
	TIMER0_IRQn				= 12,	//
	ECB_IRQn				= 13,	//
	AAR_CCM_IRQn			= 14,	//
	TEMP_IRQn				= 16,	//
	RTC0_IRQn				= 17,	//
	IPC_IRQn				= 18,	//
	SERIAL0_IRQn			= 19,	//
	EGU0_IRQn				= 20,	//
	RTC1_IRQn				= 22,	//
	TIMER1_IRQn				= 24,	//
	TIMER2_IRQn				= 25,	//
	SWI0_IRQn				= 26,	//
	SWI1_IRQn				= 27,	//
	SWI2_IRQn				= 28,	//
	SWI3_IRQn				= 29,	//
} IRQn_Type;

#define	KNB_EXCEPTIONS		14u
#define	KNB_INTERRUPTIONS	30u

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

#define	CLOCK_POWER_C0_IRQn			CLOCK_POWER_IRQn
#define	RADIO_C0_IRQn				RADIO_IRQn
#define	RNG_C0_IRQn					RNG_IRQn
#define	GPIOTE_C0_IRQn				GPIOTE_IRQn
#define	WDT_C0_IRQn					WDT_IRQn
#define	TIMER0_C0_IRQn				TIMER0_IRQn
#define	ECB_C0_IRQn					ECB_IRQn
#define	AAR_CCM_C0_IRQn				AAR_CCM_IRQn
#define	TEMP_C0_IRQn				TEMP_IRQn
#define	RTC0_C0_IRQn				RTC0_IRQn
#define	IPC_C0_IRQn					IPC_IRQn
#define	SERIAL0_C0_IRQn				SERIAL0_IRQn
#define	EGU0_C0_IRQn				EGU0_IRQn
#define	RTC1_C0_IRQn				RTC1_IRQn
#define	TIMER1_C0_IRQn				TIMER1_IRQn
#define	TIMER2_C0_IRQn				TIMER2_IRQn
#define	SWI0_C0_IRQn				SWI0_IRQn
#define	SWI1_C0_IRQn				SWI1_IRQn
#define	SWI2_C0_IRQn				SWI2_IRQn
#define	SWI3_C0_IRQn				SWI3_IRQn

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

void	CLOCK_POWER_C0_IRQHandler(void);
void	RADIO_C0_IRQHandler(void);
void	RNG_C0_IRQHandler(void);
void	GPIOTE_C0_IRQHandler(void);
void	WDT_C0_IRQHandler(void);
void	TIMER0_C0_IRQHandler(void);
void	ECB_C0_IRQHandler(void);
void	AAR_CCM_C0_IRQHandler(void);
void	TEMP_C0_IRQHandler(void);
void	RTC0_C0_IRQHandler(void);
void	IPC_C0_IRQHandler(void);
void	SERIAL0_C0_IRQHandler(void);
void	EGU0_C0_IRQHandler(void);
void	RTC1_C0_IRQHandler(void);
void	TIMER1_C0_IRQHandler(void);
void	TIMER2_C0_IRQHandler(void);
void	SWI0_C0_IRQHandler(void);
void	SWI1_C0_IRQHandler(void);
void	SWI2_C0_IRQHandler(void);
void	SWI3_C0_IRQHandler(void);

#if (defined(__cplusplus))
}
#endif
