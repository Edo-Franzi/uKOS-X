/*
; first.
; ======

; SPDX-License-Identifier: MIT

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

#include	"tests.h"
#include	"linker.h"

// Vector table: ...
// However rather than start at zero the vector table starts at address 0x00000004,
// the first four bytes are used to store the starting address of the stack pointer.

extern	void		Reset_C0_Handler(void);
extern	void		crt0(void);

const	uintptr_t	g_pfnVectors_C0[] __attribute__ ((used, section(".isr_vector"))) = {

	(uintptr_t)linker_topStackSystem_C0,						// MSP Stack

// Cortex-M33 Processor Exceptions Numbers

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

	#if (defined(CPU_APPLICATION_S))

// nRF5340 Application specific Interrupt Numbers

	(uintptr_t)FPU_C0_IRQHandler,								// Address: 0x0000_0040
	(uintptr_t)CACHE_C0_IRQHandler,								// Address: 0x0000_0044
	(uintptr_t)0,												// Address: 0x0000_0048
	(uintptr_t)SPU_C0_IRQHandler,								// Address: 0x0000_004C
	(uintptr_t)0,												// Address: 0x0000_0050
	(uintptr_t)CLOCK_POWER_C0_IRQHandler,						// Address: 0x0000_0054
	(uintptr_t)0,												// Address: 0x0000_0058
	(uintptr_t)0,												// Address: 0x0000_005C
	(uintptr_t)SERIAL0_C0_IRQHandler,							// Address: 0x0000_0060
	(uintptr_t)SERIAL1_C0_IRQHandler,							// Address: 0x0000_0064
	(uintptr_t)SPIM4_C0_IRQHandler,								// Address: 0x0000_0068
	(uintptr_t)SERIAL2_C0_IRQHandler,							// Address: 0x0000_006C
	(uintptr_t)SERIAL3_C0_IRQHandler,							// Address: 0x0000_0070
	(uintptr_t)GPIOTE0_C0_IRQHandler,							// Address: 0x0000_0074
	(uintptr_t)SAADC_C0_IRQHandler,								// Address: 0x0000_0078
	(uintptr_t)TIMER0_C0_IRQHandler,							// Address: 0x0000_007C
	(uintptr_t)TIMER1_C0_IRQHandler,							// Address: 0x0000_0080
	(uintptr_t)TIMER2_C0_IRQHandler,							// Address: 0x0000_0084
	(uintptr_t)0,												// Address: 0x0000_0088
	(uintptr_t)0,												// Address: 0x0000_008C
	(uintptr_t)RTC0_C0_IRQHandler,								// Address: 0x0000_0090
	(uintptr_t)RTC1_C0_IRQHandler,								// Address: 0x0000_0094
	(uintptr_t)0,												// Address: 0x0000_0098
	(uintptr_t)0,												// Address: 0x0000_009C
	(uintptr_t)WDT0_C0_IRQHandler,								// Address: 0x0000_00A0
	(uintptr_t)WDT1_C0_IRQHandler,								// Address: 0x0000_00A4
	(uintptr_t)COMP_LPCOMP_C0_IRQHandler,						// Address: 0x0000_00A8
	(uintptr_t)EGU0_C0_IRQHandler,								// Address: 0x0000_00AC
	(uintptr_t)EGU1_C0_IRQHandler,								// Address: 0x0000_00B0
	(uintptr_t)EGU2_C0_IRQHandler,								// Address: 0x0000_00B4
	(uintptr_t)EGU3_C0_IRQHandler,								// Address: 0x0000_00B8
	(uintptr_t)EGU4_C0_IRQHandler,								// Address: 0x0000_00BC
	(uintptr_t)EGU5_C0_IRQHandler,								// Address: 0x0000_00C0
	(uintptr_t)PWM0_C0_IRQHandler,								// Address: 0x0000_00C4
	(uintptr_t)PWM1_C0_IRQHandler,								// Address: 0x0000_00C8
	(uintptr_t)PWM2_C0_IRQHandler,								// Address: 0x0000_00CC
	(uintptr_t)PWM3_C0_IRQHandler,								// Address: 0x0000_00D0
	(uintptr_t)0,												// Address: 0x0000_00D4
	(uintptr_t)PDM0_C0_IRQHandler,								// Address: 0x0000_00D8
	(uintptr_t)0,												// Address: 0x0000_00DC
	(uintptr_t)I2S0_C0_IRQHandler,								// Address: 0x0000_00E0
	(uintptr_t)0,												// Address: 0x0000_00E4
	(uintptr_t)IPC_C0_IRQHandler,								// Address: 0x0000_00E8
	(uintptr_t)QSPI_C0_IRQHandler,								// Address: 0x0000_00EC
	(uintptr_t)0,												// Address: 0x0000_00F0
	(uintptr_t)NFCT_C0_IRQHandler,								// Address: 0x0000_00F4
	(uintptr_t)0,												// Address: 0x0000_00F8
	(uintptr_t)GPIOTE1_C0_IRQHandler,							// Address: 0x0000_00FC
	(uintptr_t)0,												// Address: 0x0000_0100
	(uintptr_t)0,												// Address: 0x0000_0104
	(uintptr_t)0,												// Address: 0x0000_0108
	(uintptr_t)QDEC0_C0_IRQHandler,								// Address: 0x0000_010C
	(uintptr_t)QDEC1_C0_IRQHandler,								// Address: 0x0000_0110
	(uintptr_t)0,												// Address: 0x0000_0114
	(uintptr_t)USBD_C0_IRQHandler,								// Address: 0x0000_0118
	(uintptr_t)USBREGULATOR_C0_IRQHandler,						// Address: 0x0000_011C
	(uintptr_t)0,												// Address: 0x0000_0120
	(uintptr_t)KMU_C0_IRQHandler,								// Address: 0x0000_0124
	(uintptr_t)0,												// Address: 0x0000_0128
	(uintptr_t)0,												// Address: 0x0000_012C
	(uintptr_t)0,												// Address: 0x0000_0130
	(uintptr_t)0,												// Address: 0x0000_0134
	(uintptr_t)0,												// Address: 0x0000_0138
	(uintptr_t)0,												// Address: 0x0000_013C
	(uintptr_t)0,												// Address: 0x0000_0140
	(uintptr_t)0,												// Address: 0x0000_0144
	(uintptr_t)0,												// Address: 0x0000_0148
	(uintptr_t)0,												// Address: 0x0000_014C
	(uintptr_t)CRYPTOCELL_C0_IRQHandler							// Address: 0x0000_0150
};

// cppcheck-suppress-begin premium-unreadVariable
//
INTERRUPT_SPECIFIC_HANDLER(FPU_C0)
INTERRUPT_SPECIFIC_HANDLER(CACHE_C0)
INTERRUPT_SPECIFIC_HANDLER(SPU_C0)
INTERRUPT_SPECIFIC_HANDLER(CLOCK_POWER_C0)
INTERRUPT_SPECIFIC_HANDLER(SERIAL0_C0)
INTERRUPT_SPECIFIC_HANDLER(SERIAL1_C0)
INTERRUPT_SPECIFIC_HANDLER(SPIM4_C0)
INTERRUPT_SPECIFIC_HANDLER(SERIAL2_C0)
INTERRUPT_SPECIFIC_HANDLER(SERIAL3_C0)
INTERRUPT_SPECIFIC_HANDLER(GPIOTE0_C0)
INTERRUPT_SPECIFIC_HANDLER(SAADC_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER0_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER1_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER2_C0)
INTERRUPT_SPECIFIC_HANDLER(RTC0_C0)
INTERRUPT_SPECIFIC_HANDLER(RTC1_C0)
INTERRUPT_SPECIFIC_HANDLER(WDT0_C0)
INTERRUPT_SPECIFIC_HANDLER(WDT1_C0)
INTERRUPT_SPECIFIC_HANDLER(COMP_LPCOMP_C0)
INTERRUPT_SPECIFIC_HANDLER(EGU0_C0)
INTERRUPT_SPECIFIC_HANDLER(EGU1_C0)
INTERRUPT_SPECIFIC_HANDLER(EGU2_C0)
INTERRUPT_SPECIFIC_HANDLER(EGU3_C0)
INTERRUPT_SPECIFIC_HANDLER(EGU4_C0)
INTERRUPT_SPECIFIC_HANDLER(EGU5_C0)
INTERRUPT_SPECIFIC_HANDLER(PWM0_C0)
INTERRUPT_SPECIFIC_HANDLER(PWM1_C0)
INTERRUPT_SPECIFIC_HANDLER(PWM2_C0)
INTERRUPT_SPECIFIC_HANDLER(PWM3_C0)
INTERRUPT_SPECIFIC_HANDLER(PDM0_C0)
INTERRUPT_SPECIFIC_HANDLER(I2S0_C0)
INTERRUPT_SPECIFIC_HANDLER(IPC_C0)
INTERRUPT_SPECIFIC_HANDLER(QSPI_C0)
INTERRUPT_SPECIFIC_HANDLER(NFCT_C0)
INTERRUPT_SPECIFIC_HANDLER(GPIOTE1_C0)
INTERRUPT_SPECIFIC_HANDLER(QDEC0_C0)
INTERRUPT_SPECIFIC_HANDLER(QDEC1_C0)
INTERRUPT_SPECIFIC_HANDLER(USBD_C0)
INTERRUPT_SPECIFIC_HANDLER(USBREGULATOR_C0)
INTERRUPT_SPECIFIC_HANDLER(KMU_C0)
INTERRUPT_SPECIFIC_HANDLER(CRYPTOCELL_C0)

// cppcheck-suppress-end premium-unreadVariable

/*
 * \brief Reset_C0_Handler
 *
 * - Call the crt0
 *
 */
void	Reset_C0_Handler(void) {

// The Application CPU turns-on all the memory (Network CPU included_C0)

	REG(VMC)->RAM0_POWER = 0xFFFF;
	REG(VMC)->RAM1_POWER = 0xFFFF;
	REG(VMC)->RAM2_POWER = 0xFFFF;
	REG(VMC)->RAM3_POWER = 0xFFFF;
	REG(VMC)->RAM4_POWER = 0xFFFF;
	REG(VMC)->RAM5_POWER = 0xFFFF;
	REG(VMC)->RAM6_POWER = 0xFFFF;
	REG(VMC)->RAM7_POWER = 0xFFFF;

	SET_THREAD_STACK(linker_topStackFirst_C0);

	crt0();
}

#else
	(uintptr_t)0,												// Address: 0x0000_0040
	(uintptr_t)0,												// Address: 0x0000_0044
	(uintptr_t)0,												// Address: 0x0000_0048
	(uintptr_t)0,												// Address: 0x0000_004C
	(uintptr_t)0,												// Address: 0x0000_0050
	(uintptr_t)CLOCK_POWER_C0_IRQHandler,						// Address: 0x0000_0054
	(uintptr_t)0,												// Address: 0x0000_0058
	(uintptr_t)0,												// Address: 0x0000_005C
	(uintptr_t)RADIO_C0_IRQHandler,								// Address: 0x0000_0060
	(uintptr_t)RNG_C0_IRQHandler,								// Address: 0x0000_0064
	(uintptr_t)GPIOTE_C0_IRQHandler,							// Address: 0x0000_0068
	(uintptr_t)WDT_C0_IRQHandler,								// Address: 0x0000_006C
	(uintptr_t)TIMER0_C0_IRQHandler,							// Address: 0x0000_0070
	(uintptr_t)ECB_C0_IRQHandler,								// Address: 0x0000_0074
	(uintptr_t)AAR_CCM_C0_IRQHandler,							// Address: 0x0000_0078
	(uintptr_t)0,												// Address: 0x0000_007C
	(uintptr_t)TEMP_C0_IRQHandler,								// Address: 0x0000_0080
	(uintptr_t)RTC0_C0_IRQHandler,								// Address: 0x0000_0084
	(uintptr_t)IPC_C0_IRQHandler,								// Address: 0x0000_0088
	(uintptr_t)SERIAL0_C0_IRQHandler,							// Address: 0x0000_008C
	(uintptr_t)EGU0_C0_IRQHandler,								// Address: 0x0000_0090
	(uintptr_t)0,												// Address: 0x0000_0094
	(uintptr_t)RTC1_C0_IRQHandler,								// Address: 0x0000_0098
	(uintptr_t)0,												// Address: 0x0000_009C
	(uintptr_t)TIMER1_C0_IRQHandler,							// Address: 0x0000_00A0
	(uintptr_t)TIMER2_C0_IRQHandler,							// Address: 0x0000_00A4
	(uintptr_t)SWI0_C0_IRQHandler,								// Address: 0x0000_00A8
	(uintptr_t)SWI1_C0_IRQHandler,								// Address: 0x0000_00AC
	(uintptr_t)SWI2_C0_IRQHandler,								// Address: 0x0000_00B4
	(uintptr_t)SWI3_C0_IRQHandler,								// Address: 0x0000_00B8
};

// cppcheck-suppress-begin premium-unreadVariable
//
INTERRUPT_SPECIFIC_HANDLER(CLOCK_POWER_C0)
INTERRUPT_SPECIFIC_HANDLER(RADIO_C0)
INTERRUPT_SPECIFIC_HANDLER(RNG_C0)
INTERRUPT_SPECIFIC_HANDLER(GPIOTE_C0)
INTERRUPT_SPECIFIC_HANDLER(WDT_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER0_C0)
INTERRUPT_SPECIFIC_HANDLER(ECB_C0)
INTERRUPT_SPECIFIC_HANDLER(AAR_CCM_C0)
INTERRUPT_SPECIFIC_HANDLER(TEMP_C0)
INTERRUPT_SPECIFIC_HANDLER(RTC0_C0)
INTERRUPT_SPECIFIC_HANDLER(IPC_C0)
INTERRUPT_SPECIFIC_HANDLER(SERIAL0_C0)
INTERRUPT_SPECIFIC_HANDLER(EGU0_C0)
INTERRUPT_SPECIFIC_HANDLER(RTC1_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER1_C0)
INTERRUPT_SPECIFIC_HANDLER(TIMER2_C0)
INTERRUPT_SPECIFIC_HANDLER(SWI0_C0)
INTERRUPT_SPECIFIC_HANDLER(SWI1_C0)
INTERRUPT_SPECIFIC_HANDLER(SWI2_C0)
INTERRUPT_SPECIFIC_HANDLER(SWI3_C0)

// cppcheck-suppress-end premium-unreadVariable

/*
 * \brief Reset_C0_Handler
 *
 * - Call the crt0
 *
 */
void	Reset_C0_Handler(void) {

	SET_THREAD_STACK(linker_topStackFirst_C0);

	crt0();
}
#endif

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
