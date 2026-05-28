/*
; rv32_csr.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		rv32_csr equates.
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

// User level CSR addresses
// ------------------------

// User Trap Setup

#define	RV_CSR_USTATUS									0x000u				//
#define	RV_CSR_UIE										0x004u				//
#define	RV_CSR_UTVEC									0x005u				//

// User Trap Handling

#define	RV_CSR_USCRATCH									0x040u				//
#define	RV_CSR_UEPC										0x041u				//
#define	RV_CSR_UCAUSE									0x042u				//
#define	RV_CSR_UTVAL									0x043u				//
#define	RV_CSR_UIP										0x044u				//

// User Floating-point CSR

#define	RV_CSR_FFLAGS									0x001u				//
#define	RV_CSR_FRM										0x002u				//
#define	RV_CSR_FCSR										0x003u				//

// User Counter/Timers

#define	RV_CSR_CYCLE									0xC00u				//
#define	RV_CSR_TIME										0xC01u				//
#define	RV_CSR_INSTRET									0xC02u				//
#define	RV_CSR_HPMCOUNTER3								0xC03u				//
#define	RV_CSR_HPMCOUNTER4								0xC04u				//
#define	RV_CSR_HPMCOUNTER5								0xC05u				//
#define	RV_CSR_HPMCOUNTER6								0xC06u				//
#define	RV_CSR_HPMCOUNTER7								0xC07u				//
#define	RV_CSR_HPMCOUNTER8								0xC08u				//
#define	RV_CSR_HPMCOUNTER9								0xC09u				//
#define	RV_CSR_HPMCOUNTER10								0xC0Au				//
#define	RV_CSR_HPMCOUNTER11								0xC0Bu				//
#define	RV_CSR_HPMCOUNTER12								0xC0Cu				//
#define	RV_CSR_HPMCOUNTER13								0xC0Du				//
#define	RV_CSR_HPMCOUNTER14								0xC0Eu				//
#define	RV_CSR_HPMCOUNTER15								0xC0Fu				//
#define	RV_CSR_HPMCOUNTER16								0xC10u				//
#define	RV_CSR_HPMCOUNTER17								0xC11u				//
#define	RV_CSR_HPMCOUNTER18								0xC12u				//
#define	RV_CSR_HPMCOUNTER19								0xC13u				//
#define	RV_CSR_HPMCOUNTER20								0xC14u				//
#define	RV_CSR_HPMCOUNTER21								0xC15u				//
#define	RV_CSR_HPMCOUNTER22								0xC16u				//
#define	RV_CSR_HPMCOUNTER23								0xC17u				//
#define	RV_CSR_HPMCOUNTER24								0xC18u				//
#define	RV_CSR_HPMCOUNTER25								0xC19u				//
#define	RV_CSR_HPMCOUNTER26								0xC1Au				//
#define	RV_CSR_HPMCOUNTER27								0xC1Bu				//
#define	RV_CSR_HPMCOUNTER28								0xC1Cu				//
#define	RV_CSR_HPMCOUNTER29								0xC1Du				//
#define	RV_CSR_HPMCOUNTER30								0xC1Eu				//
#define	RV_CSR_HPMCOUNTER31								0xC1Fu				//
#define	RV_CSR_CYCLEH									0xC80u				//
#define	RV_CSR_TIMEH									0xC81u				//
#define	RV_CSR_INSTRETH									0xC82u				//
#define	RV_CSR_HPMCOUNTER3H								0xC83u				//
#define	RV_CSR_HPMCOUNTER4H								0xC84u				//
#define	RV_CSR_HPMCOUNTER5H								0xC85u				//
#define	RV_CSR_HPMCOUNTER6H								0xC86u				//
#define	RV_CSR_HPMCOUNTER7H								0xC87u				//
#define	RV_CSR_HPMCOUNTER8H								0xC88u				//
#define	RV_CSR_HPMCOUNTER9H								0xC89u				//
#define	RV_CSR_HPMCOUNTER10H							0xC8Au				//
#define	RV_CSR_HPMCOUNTER11H							0xC8Bu				//
#define	RV_CSR_HPMCOUNTER12H							0xC8Cu				//
#define	RV_CSR_HPMCOUNTER13H							0xC8Du				//
#define	RV_CSR_HPMCOUNTER14H							0xC8Eu				//
#define	RV_CSR_HPMCOUNTER15H							0xC8Fu				//
#define	RV_CSR_HPMCOUNTER16H							0xC90u				//
#define	RV_CSR_HPMCOUNTER17H							0xC91u				//
#define	RV_CSR_HPMCOUNTER18H							0xC92u				//
#define	RV_CSR_HPMCOUNTER19H							0xC93u				//
#define	RV_CSR_HPMCOUNTER20H							0xC94u				//
#define	RV_CSR_HPMCOUNTER21H							0xC95u				//
#define	RV_CSR_HPMCOUNTER22H							0xC96u				//
#define	RV_CSR_HPMCOUNTER23H							0xC97u				//
#define	RV_CSR_HPMCOUNTER24H							0xC98u				//
#define	RV_CSR_HPMCOUNTER25H							0xC99u				//
#define	RV_CSR_HPMCOUNTER26H							0xC9Au				//
#define	RV_CSR_HPMCOUNTER27H							0xC9Bu				//
#define	RV_CSR_HPMCOUNTER28H							0xC9Cu				//
#define	RV_CSR_HPMCOUNTER29H							0xC9Du				//
#define	RV_CSR_HPMCOUNTER30H							0xC9Eu				//
#define	RV_CSR_HPMCOUNTER31H							0xC9Fu				//

// Supervisor level CSR addresses
// ------------------------------

// Supervisor Trap Setup

#define	RV_CSR_SSTATUS									0x100u				//
#define	RV_CSR_SEDELEG									0x102u				//
#define	RV_CSR_SIDELEG									0x103u				//
#define	RV_CSR_SIE										0x104u				//
#define	RV_CSR_STVEC									0x105u				//
#define	RV_CSR_SCOUNTEREN								0x106u				//

// Supervisor Trap Handling

#define	RV_CSR_SSCRATCH									0x140u				//
#define	RV_CSR_SEPC										0x141u				//
#define	RV_CSR_SCAUSE									0x142u				//
#define	RV_CSR_SBADADDR									0x143u				//
#define	RV_CSR_SIP										0x144u				//

// Supervisor Protection and Translation

#define	RV_CSR_SPTBR									0x180u				//

// Hypervisor level CSR addresses
// ------------------------------

// Hypervisor Trap Setup

#define	RV_CSR_HSTATUS									0x600u				//
#define	RV_CSR_HEDELEG									0x602u				//
#define	RV_CSR_HIDELEG									0x603u				//
#define	RV_CSR_HIE										0x604u				//
#define	RV_CSR_HCOUNTEREN								0x606u				//
#define	RV_CSR_HGEIE									0x607u				//

// Hypervisor Trap Handling

#define	RV_CSR_HTVAL									0x643u				//
#define	RV_CSR_HIP										0x644u				//
#define	RV_CSR_HTINST									0x64Au				//
#define	RV_CSR_HGEIP									0xE07u				//

// Hypervisor Protection and Translation

#define	RV_CSR_HGATP									0x680u				//

// HypervisorCounter/Timers Visualization registers

#define	RV_CSR_HTIMEDELTA								0x605u				//
#define	RV_CSR_HTIMEDELTAH								0x615u				//

// Virtual Supervisor Registers

#define	RV_CSR_VSTATUS									0x200u				//
#define	RV_CSR_VSIE										0x204u				//
#define	RV_CSR_VSTVEC									0x205u				//
#define	RV_CSR_VSSCRATCH								0x240u				//
#define	RV_CSR_VSEPC									0x241u				//
#define	RV_CSR_VSCAUSE									0x242u				//
#define	RV_CSR_VSTVAL									0x243u				//
#define	RV_CSR_VSIP										0x244u				//
#define	RV_CSR_VSATP									0x280u				//

// Machine level CSR addresses
// ---------------------------

// Machine Information Registers

#define	RV_CSR_MVENDORID								0xF11u				//
#define	RV_CSR_MARCHID									0xF12u				//
#define	RV_CSR_MIMPID									0xF13u				//
#define	RV_CSR_MHARTID									0xF14u				//

// Machine Trap Setup

#define	RV_CSR_MSTATUS									0x300u				//
#define	RV_CSR_MISA										0x301u				//
#define	RV_CSR_MEDELEG									0x302u				//
#define	RV_CSR_MIDELEG									0x303u				//
#define RV_CSR_MIE										0x304u				//
#define MIE_MSIE										(1u<<3u)			//
#define MIE_MTIE										(1u<<7u)			//
#define MIE_MEIE										(1u<<11u)			//
#define RV_CSR_MTVEC									0x305u				//
#define	RV_CSR_MCOUNTEREN								0x306u				//
#define	RV_CSR_MSTATUSH									0x310u				//

// Machine Trap Handling

#define	RV_CSR_MSCRATCH									0x340u				//
#define	RV_CSR_MEPC										0x341u				//
#define	RV_CSR_MCAUSE									0x342u				//
#define	RV_CSR_MBADADDR									0x343u				//
#define	RV_CSR_MIP										0x344u				//
#define	RV_CSR_MTINST									0x34Au				//
#define	RV_CSR_MTVAL2									0x34Bu				//

// Machine MEMORY Protection

#define	RV_CSR_PMPCFG0									0x3A0u				//
#define	RV_CSR_PMPCFG1									0x3A1u				//
#define	RV_CSR_PMPCFG2									0x3A2u				//
#define	RV_CSR_PMPCFG3									0x3A3u				//
#define	RV_CSR_PMPADDR0									0x3B0u				//
#define	RV_CSR_PMPADDR1									0x3B1u				//
#define	RV_CSR_PMPADDR2									0x3B2u				//
#define	RV_CSR_PMPADDR3									0x3B3u				//
#define	RV_CSR_PMPADDR4									0x3B4u				//
#define	RV_CSR_PMPADDR5									0x3B5u				//
#define	RV_CSR_PMPADDR6									0x3B6u				//
#define	RV_CSR_PMPADDR7									0x3B7u				//
#define	RV_CSR_PMPADDR8									0x3B8u				//
#define	RV_CSR_PMPADDR9									0x3B9u				//
#define	RV_CSR_PMPADDR10								0x3BAu				//
#define	RV_CSR_PMPADDR11								0x3BBu				//
#define	RV_CSR_PMPADDR12								0x3BCu				//
#define	RV_CSR_PMPADDR13								0x3BDu				//
#define	RV_CSR_PMPADDR14								0x3BEu				//
#define	RV_CSR_PMPADDR15								0x3BFu				//

// Machine level CSR addresses
// ---------------------------

// Machine Counter/Timers

#define	RV_CSR_MCYCLE									0xB00u				//
#define	RV_CSR_MINSTRET									0xB02u				//
#define	RV_CSR_MHPMCOUNTER3								0xB03u				//
#define	RV_CSR_MHPMCOUNTER4								0xB04u				//
#define	RV_CSR_MHPMCOUNTER5								0xB05u				//
#define	RV_CSR_MHPMCOUNTER6								0xB06u				//
#define	RV_CSR_MHPMCOUNTER7								0xB07u				//
#define	RV_CSR_MHPMCOUNTER8								0xB08u				//
#define	RV_CSR_MHPMCOUNTER9								0xB09u				//
#define	RV_CSR_MHPMCOUNTER10							0xB0Au				//
#define	RV_CSR_MHPMCOUNTER11							0xB0Bu				//
#define	RV_CSR_MHPMCOUNTER12							0xB0Cu				//
#define	RV_CSR_MHPMCOUNTER13							0xB0Du				//
#define	RV_CSR_MHPMCOUNTER14							0xB0Eu				//
#define	RV_CSR_MHPMCOUNTER15							0xB0Fu				//
#define	RV_CSR_MHPMCOUNTER16							0xB10u				//
#define	RV_CSR_MHPMCOUNTER17							0xB11u				//
#define	RV_CSR_MHPMCOUNTER18							0xB12u				//
#define	RV_CSR_MHPMCOUNTER19							0xB13u				//
#define	RV_CSR_MHPMCOUNTER20							0xB14u				//
#define	RV_CSR_MHPMCOUNTER21							0xB15u				//
#define	RV_CSR_MHPMCOUNTER22							0xB16u				//
#define	RV_CSR_MHPMCOUNTER23							0xB17u				//
#define	RV_CSR_MHPMCOUNTER24							0xB18u				//
#define	RV_CSR_MHPMCOUNTER25							0xB19u				//
#define	RV_CSR_MHPMCOUNTER26							0xB1Au				//
#define	RV_CSR_MHPMCOUNTER27							0xB1Bu				//
#define	RV_CSR_MHPMCOUNTER28							0xB1Cu				//
#define	RV_CSR_MHPMCOUNTER29							0xB1Du				//
#define	RV_CSR_MHPMCOUNTER30							0xB1Eu				//
#define	RV_CSR_MHPMCOUNTER31							0xB1Fu				//
#define	RV_CSR_MCYCLEH									0xB80u				//
#define	RV_CSR_MINSTRETH								0xB82u				//
#define	RV_CSR_MHPMCOUNTER3H							0xB83u				//
#define	RV_CSR_MHPMCOUNTER4H							0xB84u				//
#define	RV_CSR_MHPMCOUNTER5H							0xB85u				//
#define	RV_CSR_MHPMCOUNTER6H							0xB86u				//
#define	RV_CSR_MHPMCOUNTER7H							0xB87u				//
#define	RV_CSR_MHPMCOUNTER8H							0xB88u				//
#define	RV_CSR_MHPMCOUNTER9H							0xB89u				//
#define	RV_CSR_MHPMCOUNTER10H							0xB8Au				//
#define	RV_CSR_MHPMCOUNTER11H							0xB8Bu				//
#define	RV_CSR_MHPMCOUNTER12H							0xB8Cu				//
#define	RV_CSR_MHPMCOUNTER13H							0xB8Du				//
#define	RV_CSR_MHPMCOUNTER14H							0xB8Eu				//
#define	RV_CSR_MHPMCOUNTER15H							0xB8Fu				//
#define	RV_CSR_MHPMCOUNTER16H							0xB90u				//
#define	RV_CSR_MHPMCOUNTER17H							0xB91u				//
#define	RV_CSR_MHPMCOUNTER18H							0xB92u				//
#define	RV_CSR_MHPMCOUNTER19H							0xB93u				//
#define	RV_CSR_MHPMCOUNTER20H							0xB94u				//
#define	RV_CSR_MHPMCOUNTER21H							0xB95u				//
#define	RV_CSR_MHPMCOUNTER22H							0xB96u				//
#define	RV_CSR_MHPMCOUNTER23H							0xB97u				//
#define	RV_CSR_MHPMCOUNTER24H							0xB98u				//
#define	RV_CSR_MHPMCOUNTER25H							0xB99u				//
#define	RV_CSR_MHPMCOUNTER26H							0xB9Au				//
#define	RV_CSR_MHPMCOUNTER27H							0xB9Bu				//
#define	RV_CSR_MHPMCOUNTER28H							0xB9Cu				//
#define	RV_CSR_MHPMCOUNTER29H							0xB9Du				//
#define	RV_CSR_MHPMCOUNTER30H							0xB9Eu				//
#define	RV_CSR_MHPMCOUNTER31H							0xB9Fu				//

// Machine Counter Setup

#define	RV_CSR_MUCOUNTEREN								0x320u				//
#define	RV_CSR_MSCOUNTEREN								0x321u				//
#define	RV_CSR_MHPMEVENT3								0x323u				//
#define	RV_CSR_MHPMEVENT4								0x324u				//
#define	RV_CSR_MHPMEVENT5								0x325u				//
#define	RV_CSR_MHPMEVENT6								0x326u				//
#define	RV_CSR_MHPMEVENT7								0x327u				//
#define	RV_CSR_MHPMEVENT8								0x328u				//
#define	RV_CSR_MHPMEVENT9								0x329u				//
#define	RV_CSR_MHPMEVENT10								0x32Au				//
#define	RV_CSR_MHPMEVENT11								0x32Bu				//
#define	RV_CSR_MHPMEVENT12								0x32Cu				//
#define	RV_CSR_MHPMEVENT13								0x32Du				//
#define	RV_CSR_MHPMEVENT14								0x32Eu				//
#define	RV_CSR_MHPMEVENT15								0x32Fu				//
#define	RV_CSR_MHPMEVENT16								0x330u				//
#define	RV_CSR_MHPMEVENT17								0x331u				//
#define	RV_CSR_MHPMEVENT18								0x332u				//
#define	RV_CSR_MHPMEVENT19								0x333u				//
#define	RV_CSR_MHPMEVENT20								0x334u				//
#define	RV_CSR_MHPMEVENT21								0x335u				//
#define	RV_CSR_MHPMEVENT22								0x336u				//
#define	RV_CSR_MHPMEVENT23								0x337u				//
#define	RV_CSR_MHPMEVENT24								0x338u				//
#define	RV_CSR_MHPMEVENT25								0x339u				//
#define	RV_CSR_MHPMEVENT26								0x33Au				//
#define	RV_CSR_MHPMEVENT27								0x33Bu				//
#define	RV_CSR_MHPMEVENT28								0x33Cu				//
#define	RV_CSR_MHPMEVENT29								0x33Du				//
#define	RV_CSR_MHPMEVENT30								0x33Eu				//
#define	RV_CSR_MHPMEVENT31								0x33Fu				//

// Debug/Trace Registers (shared with Debug Mode)

#define	RV_CSR_TSELECT									0x7A0u				//
#define	RV_CSR_TDATA1									0x7A1u				//
#define	RV_CSR_TDATA2									0x7A2u				//
#define	RV_CSR_TDATA3									0x7A3u				//

// Debug Modee Register

#define	RV_CSR_DCSR										0x7B0u				//
#define	RV_CSR_DPC										0x7B1u				//
#define	RV_CSR_DSCRATCH									0x7B2u				//

// Bits in registers
// -----------------

#define	MSTATUS_UIE										(1u<<0)				//
#define	MSTATUS_SIE										(1u<<1)				//
#define	MSTATUS_HIE										(1u<<2)				//
#define	MSTATUS_MIE										(1u<<3)				//
#define	MSTATUS_UPIE									(1u<<4)				//
#define	MSTATUS_SPIE									(1u<<5)				//
#define	MSTATUS_HPIE									(1u<<6)				//
#define	MSTATUS_MPIE									(1u<<7)				//
#define	MSTATUS_SPP										(1u<<8)				//
#define	MSTATUS_MPP										(3u<<11)			//
#define	MSTATUS_FS										(3u<<13)			//
#define	MSTATUS_XS										(3u<<15)			//
#define	MSTATUS_MPRV									(1u<<17)			//
#define	MSTATUS_PUM										(1u<<18)			//
#define	MSTATUS_MXR										(1u<<19)			//
#define	MSTATUS_VM										0x1F000000u			//
#define	MSTATUS32_SD									0x80000000u			//
#define	MSTATUS64_SD									0x8000000000000000u	//

#define	SSTATUS_UIE										0x00000001u			//
#define	SSTATUS_SIE										0x00000002u			//
#define	SSTATUS_UPIE									0x00000010u			//
#define	SSTATUS_SPIE									0x00000020u			//
#define	SSTATUS_SPP										0x00000100u			//
#define	SSTATUS_FS										0x00006000u			//
#define	SSTATUS_XS										0x00018000u			//
#define	SSTATUS_PUM										0x00040000u			//
#define	SSTATUS32_SD									0x80000000u			//
#define	SSTATUS64_SD									0x8000000000000000u	//

#define	MCAUSE_INTERRUPT								0x80000000u			//
#define	MCAUSE_CAUSE									0x7FFFFFFFu			//

#define	MCAUSE_EXC_CODE_INSTRUCTION_ADDRESS_MISALIGNED	0u					//
#define	MCAUSE_EXC_CODE_INSTRUCTION_ACCESS_FAULT		1u					//
#define	MCAUSE_EXC_CODE_ILLEGAL_INSTRUCTION				2u					//
#define	MCAUSE_EXC_CODE_BREAKPOINT						3u					//
#define	MCAUSE_EXC_CODE_LOAD_ADDRESS_MISALIGNED			4u					//
#define	MCAUSE_EXC_CODE_LOAD_ACCESS_FAULT				5u					//
#define	MCAUSE_EXC_CODE_STORE_AMO_ADDRESS_MISALIGNED	6u					//
#define	MCAUSE_EXC_CODE_STORE_AMO_ACCESS_FAULT			7u					//
#define	MCAUSE_EXC_CODE_ENV_CALL_FROM_U_MODE			8u					//
#define	MCAUSE_EXC_CODE_ENV_CALL_FROM_S_MODE			9u					//
#define	MCAUSE_EXC_CODE_ENV_CALL_FROM_M_MODE			11u					//
#define	MCAUSE_EXC_CODE_INSTRUCTION_PAGE_FAULT			12u					//
#define	MCAUSE_EXC_CODE_LOAD_PAGE_FAULT					13u					//
#define	MCAUSE_EXC_CODE_STORE_AMO_PAGE_FAULT			15u					//

#define	CSR_SETBITS(reg, mask) \
	({ \
		uint32_t	__tmp; \
		if (__builtin_constant_p(mask) && ((uint32_t)(mask) < 32)) { \
			__asm volatile ("csrrs %0, " #reg ", %1" : "=r" (__tmp) : "i" (mask)); \
		} \
		else { \
			__asm volatile ("csrrs %0, " #reg ", %1" : "=r" (__tmp) : "r" (mask)); \
		} \
		__tmp; \
	})

#define	CSR_CLEARBITS(reg, mask) \
	({ \
		uint32_t	__tmp; \
		if (__builtin_constant_p(mask) && ((uint32_t)(mask) < 32)) { \
			__asm volatile ("csrrc %0, " #reg ", %1" : "=r" (__tmp) : "i" (mask)); \
		} \
		else { \
			__asm volatile ("csrrc %0, " #reg ", %1" : "=r" (__tmp) : "r" (mask)); \
		} \
		__tmp; \
	})

#define	CSR_WRITE(reg, value) \
	({ \
		if (__builtin_constant_p(value) && ((uint32_t)(value) < 32)) { \
			__asm volatile ("csrw " #reg ", %0" :: "i" (value)); \
		} \
		else { \
			__asm volatile ("csrw " #reg ", %0" :: "r" (value)); \
		} \
	})

#define	CSR_READ(reg) \
	({ \
		uint32_t	__tmp;	\
		__asm volatile ("csrr %0, " #reg : "=r" (__tmp)); \
		__tmp; \
	})
