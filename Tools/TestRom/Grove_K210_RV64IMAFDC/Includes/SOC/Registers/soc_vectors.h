/*
; soc_vectors.
; ============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Indirect Exception Vectors for RISC-V.
;			The "reset" exception is not considered. The indirect table
;			is reserved in the first.s file.
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

//			Internal interruptions				Internal exceptions
//
// 0		User Software Interrupt				Instruction Address Misaligned
// 1		Supervisor Software Interrupt		Instruction Access Fault
// 2		Reserved							Illegal Instruction
// 3		Machine Software Interrupt			Breakpoint
// 4		User Timer Interrupt				Load Address Misaligned
// 5		Supervisor Timer Interrupt			Load Access Fault
// 6		Reserved							Store/AMO Address Misaligned
// 7		Machine Timer Interrupt				Store/AMO Access Fault
// 8		User External Interrupt				Environment Call from U-mode
// 9		Supervisor External Interrupt		Environment Call from S-mode
// 10		Reserved							Reserved
// 11		Machine External Interrupt			Environment Call from M-mode
// 12		Reserved							Instruction Page Fault
// 13		Reserved							Load Page Fault
// 14		Reserved							Reserved
// 15		Reserved							Store/AMO Page Fault

//			PLIC interruptions
//
// 0		The non-existent interrupt
// 1		SPI0 interrupt
// 2		SPI1 interrupt
// 3		SPI_SLAVE interrupt
// 4		SPI3 interrupt
// 5		I2S0 interrupt
// 6		I2S1 interrupt
// 7		I2S2 interrupt
// 8		I2C0 interrupt
// 9		I2C1 interrupt
// 10		I2C2 interrupt
// 11		UART1 interrupt
// 12		UART2 interrupt
// 13		UART3 interrupt
// 14		TIMER0 channel 0 or 1 interrupt
// 15		TIMER0 channel 2 or 3 interrupt
// 16		TIMER1 channel 0 or 1 interrupt
// 17		TIMER1 channel 2 or 3 interrupt
// 18		TIMER2 channel 0 or 1 interrupt
// 19		TIMER2 channel 2 or 3 interrupt
// 20		RTC tick and alarm interrupt
// 21		Watching dog timer0 interrupt
// 22		Watching dog timer1 interrupt
// 23		APB GPIO interrupt
// 24		Digital video port interrupt
// 25		AI accelerator interrupt
// 26		FFT accelerator interrupt
// 27		DMA channel0 interrupt
// 28		DMA channel1 interrupt
// 29		DMA channel2 interrupt
// 30		DMA channel3 interrupt
// 31		DMA channel4 interrupt
// 32		DMA channel5 interrupt
// 33		Hi-speed UART0 interrupt
// 34		Hi-speed GPIO0 interrupt
// 35		Hi-speed GPIO1 interrupt
// 36		Hi-speed GPIO2 interrupt
// 37		Hi-speed GPIO3 interrupt
// 38		Hi-speed GPIO4 interrupt
// 39		Hi-speed GPIO5 interrupt
// 40		Hi-speed GPIO6 interrupt
// 41		Hi-speed GPIO7 interrupt
// 42		Hi-speed GPIO8 interrupt
// 43		Hi-speed GPIO9 interrupt
// 44		Hi-speed GPIO10 interrupt
// 45		Hi-speed GPIO11 interrupt
// 46		Hi-speed GPIO12 interrupt
// 47		Hi-speed GPIO13 interrupt
// 48		Hi-speed GPIO14 interrupt
// 49		Hi-speed GPIO15 interrupt
// 50		Hi-speed GPIO16 interrupt
// 51		Hi-speed GPIO17 interrupt
// 52		Hi-speed GPIO18 interrupt
// 53		Hi-speed GPIO19 interrupt
// 54		Hi-speed GPIO20 interrupt
// 55		Hi-speed GPIO21 interrupt
// 56		Hi-speed GPIO22 interrupt
// 57		Hi-speed GPIO23 interrupt
// 58		Hi-speed GPIO24 interrupt
// 59		Hi-speed GPIO25 interrupt
// 60		Hi-speed GPIO26 interrupt
// 61		Hi-speed GPIO27 interrupt
// 62		Hi-speed GPIO28 interrupt
// 63		Hi-speed GPIO29 interrupt
// 64		Hi-speed GPIO30 interrupt
// 65		Hi-speed GPIO31 interrupt

typedef	enum	_internalInterruption {
	IINT_USER_SOFTWARE = 0,									// User Software Interrupt
	IINT_SUPERVISOR_SOFTWARE,								// Supervisor Software Interrupt
	IINT_RESERVED_1,										// Reserved
	IINT_MACHINE_SOFTWARE,									// Machine Software Interrupt
	IINT_USER_TIMER,										// User Timer Interrupt
	IINT_SUPERVISOR_TIMER,									// Supervisor Timer Interrupt
	IINT_RESERVED_2,										// Reserved
	IINT_MACHINE_TIMER,										// Machine Timer Interrupt
	IINT_USER_EXTERNAL,										// User External Interrupt
	IINT_SUPERVISOR_EXTERNAL,								// Supervisor External Interrupt
	IINT_RESERVED_3,										// Reserved
	IINT_MACHINE_EXTERNAL,									// Machine External Interrupt
	IINT_MAX												// Number of interruptions
} internalInterruption_t;

typedef	enum	_internalException {
	IEXC_INSTRUCTION_ADDRESS_MISALIGNED = 0,				// Instruction Address Misaligned
	IEXC_INSTRUCTION_ACCESS_FAULT,							// Instruction Access Fault
	IEXC_ILLEGAL_INSTRUCTION,								// Illegal Instruction
	IEXC_BREAKPOINT,										// Breakpoint
	IEXC_LOAD_ADDRESS_MISALIGNED,							// Load Address Misaligned
	IEXC_LOAD_ACCESS_FAULT,									// Load Access Fault
	IEXC_STORE_ADDRESS_MISALIGNED,							// Store/AMO Address Misaligned
	IEXC_STORE_ADDRESS_FAULT,								// Store/AMO Access Fault
	IEXC_ENVIRONMENTAL_CALL_U_MODE,							// Environment Call from U-mode
	IEXC_ENVIRONMENTAL_CALL_S_MODE,							// Environment Call from S-mode
	IEXC_RESERVED_1,										// Reserved
	IEXC_ENVIRONMENTAL_CALL_M_MODE,							// Environment Call from M-mode
	IEXC_INSTRUCTION_PAGE_FAULT,							// Instruction Page Fault
	IEXC_LOAD_PAGE_FAULT,									// Load Page Fault
	IEXC_RESERVED_2,										// Reserved
	IEXC_STORE_PAGE_FAULT,									// Store/AMO Page Fault
	IEXC_MAX												// Number of exceptions
} internalException_t;

typedef	enum	_external_Interruption {
	EINT_NO_INTERRUPT = 0,									// 0  EINT_NO_INTERRUPT
	EINT_SPI0_INTERRUPT,									// 1  EINT_SPI0_INTERRUPT
	EINT_SPI1_INTERRUPT,									// 2  EINT_SPI1_INTERRUPT
	EINT_SPI_SLAVE_INTERRUPT,								// 3  EINT_SPI_SLAVE_INTERRUP
	EINT_SPI3_INTERRUPT,									// 4  EINT_SPI3_INTERRUPT
	EINT_I2S0_INTERRUPT,									// 5  EINT_I2S0_INTERRUPT
	EINT_I2S1_INTERRUPT,									// 6  EINT_I2S1_INTERRUPT
	EINT_I2S2_INTERRUPT,									// 7  EINT_I2S2_INTERRUPT
	EINT_I2C0_INTERRUPT,									// 8  EINT_I2C0_INTERRUPT
	EINT_I2C1_INTERRUPT,									// 9  EINT_I2C1_INTERRUPT
	EINT_I2C2_INTERRUPT,									// 10 EINT_I2C2_INTERRUPT
	EINT_UART1_INTERRUPT,									// 11 EINT_UART1_INTERRUPT
	EINT_UART2_INTERRUPT,									// 12 EINT_UART2_INTERRUPT
	EINT_UART3_INTERRUPT,									// 13 EINT_UART3_INTERRUPT
	EINT_TIMER0A_INTERRUPT,									// 14 EINT_TIMER0A_INTERRUPT
	EINT_TIMER0B_INTERRUPT,									// 15 EINT_TIMER0B_INTERRUPT
	EINT_TIMER1A_INTERRUPT,									// 16 EINT_TIMER1A_INTERRUPT
	EINT_TIMER1B_INTERRUPT,									// 17 EINT_TIMER1B_INTERRUPT
	EINT_TIMER2A_INTERRUPT,									// 18 EINT_TIMER2A_INTERRUPT
	EINT_TIMER2B_INTERRUPT,									// 19 EINT_TIMER2B_INTERRUPT
	EINT_RTC_INTERRUPT,										// 20 EINT_RTC_INTERRUPT
	EINT_WDT0_INTERRUPT,									// 21 EINT_WDT0_INTERRUPT
	EINT_WDT1_INTERRUPT,									// 22 EINT_WDT1_INTERRUPT
	EINT_APB_GPIO_INTERRUPT,								// 23 EINT_APB_GPIO_INTERRUPT
	EINT_DVP_INTERRUPT,										// 24 EINT_DVP_INTERRUPT
	EINT_AI_INTERRUPT,										// 25 EINT_AI_INTERRUPT
	EINT_FFT_INTERRUPT,										// 26 EINT_FFT_INTERRUPT
	EINT_DMA0_INTERRUPT,									// 27 EINT_DMA0_INTERRUPT
	EINT_DMA1_INTERRUPT,									// 28 EINT_DMA1_INTERRUPT
	EINT_DMA2_INTERRUPT,									// 29 EINT_DMA2_INTERRUPT
	EINT_DMA3_INTERRUPT,									// 30 EINT_DMA3_INTERRUPT
	EINT_DMA4_INTERRUPT,									// 31 EINT_DMA4_INTERRUPT
	EINT_DMA5_INTERRUPT,									// 32 EINT_DMA5_INTERRUPT
	EINT_UARTHS_INTERRUPT,									// 33 EINT_UARTHS_INTERRUPT
	EINT_GPIOHS0_INTERRUPT,									// 34 EINT_GPIOHS0_INTERRUPT
	EINT_GPIOHS1_INTERRUPT,									// 35 EINT_GPIOHS1_INTERRUPT
	EINT_GPIOHS2_INTERRUPT,									// 36 EINT_GPIOHS2_INTERRUPT
	EINT_GPIOHS3_INTERRUPT,									// 37 EINT_GPIOHS3_INTERRUPT
	EINT_GPIOHS4_INTERRUPT,									// 38 EINT_GPIOHS4_INTERRUPT
	EINT_GPIOHS5_INTERRUPT,									// 39 EINT_GPIOHS5_INTERRUPT
	EINT_GPIOHS6_INTERRUPT,									// 40 EINT_GPIOHS6_INTERRUPT
	EINT_GPIOHS7_INTERRUPT,									// 41 EINT_GPIOHS7_INTERRUPT
	EINT_GPIOHS8_INTERRUPT,									// 42 EINT_GPIOHS8_INTERRUPT
	EINT_GPIOHS9_INTERRUPT,									// 43 EINT_GPIOHS9_INTERRUPT
	EINT_GPIOHS10_INTERRUPT,								// 44 EINT_GPIOHS10_INTERRUPT
	EINT_GPIOHS11_INTERRUPT,								// 45 EINT_GPIOHS11_INTERRUPT
	EINT_GPIOHS12_INTERRUPT,								// 46 EINT_GPIOHS12_INTERRUPT
	EINT_GPIOHS13_INTERRUPT,								// 47 EINT_GPIOHS13_INTERRUPT
	EINT_GPIOHS14_INTERRUPT,								// 48 EINT_GPIOHS14_INTERRUPT
	EINT_GPIOHS15_INTERRUPT,								// 49 EINT_GPIOHS15_INTERRUPT
	EINT_GPIOHS16_INTERRUPT,								// 50 EINT_GPIOHS16_INTERRUPT
	EINT_GPIOHS17_INTERRUPT,								// 51 EINT_GPIOHS17_INTERRUPT
	EINT_GPIOHS18_INTERRUPT,								// 52 EINT_GPIOHS18_INTERRUPT
	EINT_GPIOHS19_INTERRUPT,								// 53 EINT_GPIOHS19_INTERRUPT
	EINT_GPIOHS20_INTERRUPT,								// 54 EINT_GPIOHS20_INTERRUPT
	EINT_GPIOHS21_INTERRUPT,								// 55 EINT_GPIOHS21_INTERRUPT
	EINT_GPIOHS22_INTERRUPT,								// 56 EINT_GPIOHS22_INTERRUPT
	EINT_GPIOHS23_INTERRUPT,								// 57 EINT_GPIOHS23_INTERRUPT
	EINT_GPIOHS24_INTERRUPT,								// 58 EINT_GPIOHS24_INTERRUPT
	EINT_GPIOHS25_INTERRUPT,								// 59 EINT_GPIOHS25_INTERRUPT
	EINT_GPIOHS26_INTERRUPT,								// 60 EINT_GPIOHS26_INTERRUPT
	EINT_GPIOHS27_INTERRUPT,								// 61 EINT_GPIOHS27_INTERRUPT
	EINT_GPIOHS28_INTERRUPT,								// 62 EINT_GPIOHS28_INTERRUPT
	EINT_GPIOHS29_INTERRUPT,								// 63 EINT_GPIOHS29_INTERRUPT
	EINT_GPIOHS30_INTERRUPT,								// 64 EINT_GPIOHS30_INTERRUPT
	EINT_GPIOHS31_INTERRUPT,								// 65 EINT_GPIOHS31_INTERRUPT
	EINT_MAX												// Number of periph interruptions
} external_Interruption_t;

#define	KNB_INT_INTERRUPTIONS	IINT_MAX
#define	KNB_INT_EXCEPTIONS		IEXC_MAX
#define	KNB_EXT_INTERRUPTIONS	EINT_MAX
