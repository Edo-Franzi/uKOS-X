/*
; RP2350_pio.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_pio equates.
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

#include	<stdint.h>

// PIO0 address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CTRL;
	volatile	uint32_t	FSTAT;
	volatile	uint32_t	FDEBUG;
	volatile	uint32_t	FLEVEL;
	volatile	uint32_t	TXF0;
	volatile	uint32_t	TXF1;
	volatile	uint32_t	TXF2;
	volatile	uint32_t	TXF3;
	volatile	uint32_t	RXF0;
	volatile	uint32_t	RXF1;
	volatile	uint32_t	RXF2;
	volatile	uint32_t	RXF3;
	volatile	uint32_t	IRQ;
	volatile	uint32_t	IRQ_FORCE;
	volatile	uint32_t	INPUT_SYNC_BYPASS;
	volatile	uint32_t	DBG_PADOUT;
	volatile	uint32_t	DBG_PADOE;
	volatile	uint32_t	DBG_CFGINFO;
	volatile	uint32_t	INSTR_MEM0;
	volatile	uint32_t	INSTR_MEM1;
	volatile	uint32_t	INSTR_MEM2;
	volatile	uint32_t	INSTR_MEM3;
	volatile	uint32_t	INSTR_MEM4;
	volatile	uint32_t	INSTR_MEM5;
	volatile	uint32_t	INSTR_MEM6;
	volatile	uint32_t	INSTR_MEM7;
	volatile	uint32_t	INSTR_MEM8;
	volatile	uint32_t	INSTR_MEM9;
	volatile	uint32_t	INSTR_MEM10;
	volatile	uint32_t	INSTR_MEM11;
	volatile	uint32_t	INSTR_MEM12;
	volatile	uint32_t	INSTR_MEM13;
	volatile	uint32_t	INSTR_MEM14;
	volatile	uint32_t	INSTR_MEM15;
	volatile	uint32_t	INSTR_MEM16;
	volatile	uint32_t	INSTR_MEM17;
	volatile	uint32_t	INSTR_MEM18;
	volatile	uint32_t	INSTR_MEM19;
	volatile	uint32_t	INSTR_MEM20;
	volatile	uint32_t	INSTR_MEM21;
	volatile	uint32_t	INSTR_MEM22;
	volatile	uint32_t	INSTR_MEM23;
	volatile	uint32_t	INSTR_MEM24;
	volatile	uint32_t	INSTR_MEM25;
	volatile	uint32_t	INSTR_MEM26;
	volatile	uint32_t	INSTR_MEM27;
	volatile	uint32_t	INSTR_MEM28;
	volatile	uint32_t	INSTR_MEM29;
	volatile	uint32_t	INSTR_MEM30;
	volatile	uint32_t	INSTR_MEM31;
	volatile	uint32_t	SM0_CLKDIV;
	volatile	uint32_t	SM0_EXECCTRL;
	volatile	uint32_t	SM0_SHIFTCTRL;
	volatile	uint32_t	SM0_ADDR;
	volatile	uint32_t	SM0_INSTR;
	volatile	uint32_t	SM0_PINCTRL;
	volatile	uint32_t	SM1_CLKDIV;
	volatile	uint32_t	SM1_EXECCTRL;
	volatile	uint32_t	SM1_SHIFTCTRL;
	volatile	uint32_t	SM1_ADDR;
	volatile	uint32_t	SM1_INSTR;
	volatile	uint32_t	SM1_PINCTRL;
	volatile	uint32_t	SM2_CLKDIV;
	volatile	uint32_t	SM2_EXECCTRL;
	volatile	uint32_t	SM2_SHIFTCTRL;
	volatile	uint32_t	SM2_ADDR;
	volatile	uint32_t	SM2_INSTR;
	volatile	uint32_t	SM2_PINCTRL;
	volatile	uint32_t	SM3_CLKDIV;
	volatile	uint32_t	SM3_EXECCTRL;
	volatile	uint32_t	SM3_SHIFTCTRL;
	volatile	uint32_t	SM3_ADDR;
	volatile	uint32_t	SM3_INSTR;
	volatile	uint32_t	SM3_PINCTRL;
	volatile	uint32_t	RXF0_PUTGET0;
	volatile	uint32_t	RXF0_PUTGET1;
	volatile	uint32_t	RXF0_PUTGET2;
	volatile	uint32_t	RXF0_PUTGET3;
	volatile	uint32_t	RXF1_PUTGET0;
	volatile	uint32_t	RXF1_PUTGET1;
	volatile	uint32_t	RXF1_PUTGET2;
	volatile	uint32_t	RXF1_PUTGET3;
	volatile	uint32_t	RXF2_PUTGET0;
	volatile	uint32_t	RXF2_PUTGET1;
	volatile	uint32_t	RXF2_PUTGET2;
	volatile	uint32_t	RXF2_PUTGET3;
	volatile	uint32_t	RXF3_PUTGET0;
	volatile	uint32_t	RXF3_PUTGET1;
	volatile	uint32_t	RXF3_PUTGET2;
	volatile	uint32_t	RXF3_PUTGET3;
	volatile	uint32_t	GPIOBASE;
	volatile	uint32_t	INTR;
	volatile	uint32_t	IRQ0_INTE;
	volatile	uint32_t	IRQ0_INTF;
	volatile	uint32_t	IRQ0_INTS;
	volatile	uint32_t	IRQ1_INTE;
	volatile	uint32_t	IRQ1_INTF;
	volatile	uint32_t	IRQ1_INTS;
} PIO_TypeDef;

#ifdef __cplusplus
#define	PIO0_NS	reinterpret_cast<PIO_TypeDef *>(0x50200000u)
#define	PIO0_S	reinterpret_cast<PIO_TypeDef *>(0x50200000u)
#define	PIO1_NS	reinterpret_cast<PIO_TypeDef *>(0x50300000u)
#define	PIO1_S	reinterpret_cast<PIO_TypeDef *>(0x50300000u)
#define	PIO2_NS	reinterpret_cast<PIO_TypeDef *>(0x50400000u)
#define	PIO2_S	reinterpret_cast<PIO_TypeDef *>(0x50400000u)
#else
#define	PIO0_NS	((PIO_TypeDef *)0x50200000u)
#define	PIO0_S	((PIO_TypeDef *)0x50200000u)
#define	PIO1_NS	((PIO_TypeDef *)0x50300000u)
#define	PIO1_S	((PIO_TypeDef *)0x50300000u)
#define	PIO2_NS	((PIO_TypeDef *)0x50400000u)
#define	PIO2_S	((PIO_TypeDef *)0x50400000u)
#endif

// CTRL Configuration

#define	PIO_CTRL_SM_ENABLE							(0xFu<<0)
#define	PIO_CTRL_SM_ENABLE_0						(0x1u<<0)
#define	PIO_CTRL_SM_RESTART							(0xFu<<4)
#define	PIO_CTRL_SM_RESTART_0						(0x1u<<4)
#define	PIO_CTRL_CLKDIV_RESTART						(0xFu<<8)
#define	PIO_CTRL_CLKDIV_RESTART_0					(0x1u<<8)
#define	PIO_CTRL_PREV_PIO_MASK						(0xFu<<16)
#define	PIO_CTRL_PREV_PIO_MASK_0					(0x1u<<16)
#define	PIO_CTRL_NEXT_PIO_MASK						(0xFu<<20)
#define	PIO_CTRL_NEXT_PIO_MASK_0					(0x1u<<20)
#define	PIO_CTRL_NEXTPREV_SM_ENABLE					(0x1u<<24)
#define	PIO_CTRL_NEXTPREV_SM_DISABLE				(0x1u<<25)
#define	PIO_CTRL_NEXTPREV_CLKDIV_RESTART			(0x1u<<26)

// FSTAT Configuration

#define	PIO_FSTAT_RXFULL							(0xFu<<0)
#define	PIO_FSTAT_RXFULL_0							(0x1u<<0)
#define	PIO_FSTAT_RXEMPTY							(0xFu<<8)
#define	PIO_FSTAT_RXEMPTY_0							(0x1u<<8)
#define	PIO_FSTAT_TXFULL							(0xFu<<16)
#define	PIO_FSTAT_TXFULL_0							(0x1u<<16)
#define	PIO_FSTAT_TXEMPTY							(0xFu<<24)
#define	PIO_FSTAT_TXEMPTY_0							(0x1u<<24)

// FDEBUG Configuration

#define	PIO_FDEBUG_RXSTALL							(0xFu<<0)
#define	PIO_FDEBUG_RXSTALL_0						(0x1u<<0)
#define	PIO_FDEBUG_RXUNDER							(0xFu<<8)
#define	PIO_FDEBUG_RXUNDER_0						(0x1u<<8)
#define	PIO_FDEBUG_TXOVER							(0xFu<<16)
#define	PIO_FDEBUG_TXOVER_0							(0x1u<<16)
#define	PIO_FDEBUG_TXSTALL							(0xFu<<24)
#define	PIO_FDEBUG_TXSTALL_0						(0x1u<<24)

// FLEVEL Configuration

#define	PIO_FLEVEL_TX0								(0xFu<<0)
#define	PIO_FLEVEL_TX0_0							(0x1u<<0)
#define	PIO_FLEVEL_RX0								(0xFu<<4)
#define	PIO_FLEVEL_RX0_0							(0x1u<<4)
#define	PIO_FLEVEL_TX1								(0xFu<<8)
#define	PIO_FLEVEL_TX1_0							(0x1u<<8)
#define	PIO_FLEVEL_RX1								(0xFu<<12)
#define	PIO_FLEVEL_RX1_0							(0x1u<<12)
#define	PIO_FLEVEL_TX2								(0xFu<<16)
#define	PIO_FLEVEL_TX2_0							(0x1u<<16)
#define	PIO_FLEVEL_RX2								(0xFu<<20)
#define	PIO_FLEVEL_RX2_0							(0x1u<<20)
#define	PIO_FLEVEL_TX3								(0xFu<<24)
#define	PIO_FLEVEL_TX3_0							(0x1u<<24)
#define	PIO_FLEVEL_RX3								(0xFu<<28)
#define	PIO_FLEVEL_RX3_0							(0x1u<<28)

// TXF0 Configuration

#define	PIO_TXF0_TXF0								(0xFFFFFFFFu<<0)
#define	PIO_TXF0_TXF0_0								(0x1u<<0)

// TXF1 Configuration

#define	PIO_TXF1_TXF1								(0xFFFFFFFFu<<0)
#define	PIO_TXF1_TXF1_0								(0x1u<<0)

// TXF2 Configuration

#define	PIO_TXF2_TXF2								(0xFFFFFFFFu<<0)
#define	PIO_TXF2_TXF2_0								(0x1u<<0)

// TXF3 Configuration

#define	PIO_TXF3_TXF3								(0xFFFFFFFFu<<0)
#define	PIO_TXF3_TXF3_0								(0x1u<<0)

// RXF0 Configuration

#define	PIO_RXF0_RXF0								(0xFFFFFFFFu<<0)
#define	PIO_RXF0_RXF0_0								(0x1u<<0)

// RXF1 Configuration

#define	PIO_RXF1_RXF1								(0xFFFFFFFFu<<0)
#define	PIO_RXF1_RXF1_0								(0x1u<<0)

// RXF2 Configuration

#define	PIO_RXF2_RXF2								(0xFFFFFFFFu<<0)
#define	PIO_RXF2_RXF2_0								(0x1u<<0)

// RXF3 Configuration

#define	PIO_RXF3_RXF3								(0xFFFFFFFFu<<0)
#define	PIO_RXF3_RXF3_0								(0x1u<<0)

// IRQ Configuration

#define	PIO_IRQ_IRQ									(0xFFu<<0)
#define	PIO_IRQ_IRQ_0								(0x1u<<0)

// IRQ_FORCE Configuration

#define	PIO_IRQ_FORCE_IRQ_FORCE						(0xFFu<<0)
#define	PIO_IRQ_FORCE_IRQ_FORCE_0					(0x1u<<0)

// INPUT_SYNC_BYPASS Configuration

#define	PIO_INPUT_SYNC_BYPASS_INPUT_SYNC_BYPASS		(0xFFFFFFFFu<<0)
#define	PIO_INPUT_SYNC_BYPASS_INPUT_SYNC_BYPASS_0	(0x1u<<0)

// DBG_PADOUT Configuration

#define	PIO_DBG_PADOUT_DBG_PADOUT					(0xFFFFFFFFu<<0)
#define	PIO_DBG_PADOUT_DBG_PADOUT_0					(0x1u<<0)

// DBG_PADOE Configuration

#define	PIO_DBG_PADOE_DBG_PADOE						(0xFFFFFFFFu<<0)
#define	PIO_DBG_PADOE_DBG_PADOE_0					(0x1u<<0)

// DBG_CFGINFO Configuration

#define	PIO_DBG_CFGINFO_FIFO_DEPTH					(0x3Fu<<0)
#define	PIO_DBG_CFGINFO_FIFO_DEPTH_0				(0x1u<<0)
#define	PIO_DBG_CFGINFO_SM_COUNT					(0xFu<<8)
#define	PIO_DBG_CFGINFO_SM_COUNT_0					(0x1u<<8)
#define	PIO_DBG_CFGINFO_IMEM_SIZE					(0x3Fu<<16)
#define	PIO_DBG_CFGINFO_IMEM_SIZE_0					(0x1u<<16)
#define	PIO_DBG_CFGINFO_VERSION						(0xFu<<28)
#define	PIO_DBG_CFGINFO_VERSION_0					(0x1u<<28)
#define	PIO_DBG_CFGINFO_VERSION_V0					(0x0u<<28)
#define	PIO_DBG_CFGINFO_VERSION_V1					(0x1u<<28)

// INSTR_MEM0 Configuration

#define	PIO_INSTR_MEM0_INSTR_MEM0					(0xFFFFu<<0)
#define	PIO_INSTR_MEM0_INSTR_MEM0_0					(0x1u<<0)

// INSTR_MEM1 Configuration

#define	PIO_INSTR_MEM1_INSTR_MEM1					(0xFFFFu<<0)
#define	PIO_INSTR_MEM1_INSTR_MEM1_0					(0x1u<<0)

// INSTR_MEM2 Configuration

#define	PIO_INSTR_MEM2_INSTR_MEM2					(0xFFFFu<<0)
#define	PIO_INSTR_MEM2_INSTR_MEM2_0					(0x1u<<0)

// INSTR_MEM3 Configuration

#define	PIO_INSTR_MEM3_INSTR_MEM3					(0xFFFFu<<0)
#define	PIO_INSTR_MEM3_INSTR_MEM3_0					(0x1u<<0)

// INSTR_MEM4 Configuration

#define	PIO_INSTR_MEM4_INSTR_MEM4					(0xFFFFu<<0)
#define	PIO_INSTR_MEM4_INSTR_MEM4_0					(0x1u<<0)

// INSTR_MEM5 Configuration

#define	PIO_INSTR_MEM5_INSTR_MEM5					(0xFFFFu<<0)
#define	PIO_INSTR_MEM5_INSTR_MEM5_0					(0x1u<<0)

// INSTR_MEM6 Configuration

#define	PIO_INSTR_MEM6_INSTR_MEM6					(0xFFFFu<<0)
#define	PIO_INSTR_MEM6_INSTR_MEM6_0					(0x1u<<0)

// INSTR_MEM7 Configuration

#define	PIO_INSTR_MEM7_INSTR_MEM7					(0xFFFFu<<0)
#define	PIO_INSTR_MEM7_INSTR_MEM7_0					(0x1u<<0)

// INSTR_MEM8 Configuration

#define	PIO_INSTR_MEM8_INSTR_MEM8					(0xFFFFu<<0)
#define	PIO_INSTR_MEM8_INSTR_MEM8_0					(0x1u<<0)

// INSTR_MEM9 Configuration

#define	PIO_INSTR_MEM9_INSTR_MEM9					(0xFFFFu<<0)
#define	PIO_INSTR_MEM9_INSTR_MEM9_0					(0x1u<<0)

// INSTR_MEM10 Configuration

#define	PIO_INSTR_MEM10_INSTR_MEM10					(0xFFFFu<<0)
#define	PIO_INSTR_MEM10_INSTR_MEM10_0				(0x1u<<0)

// INSTR_MEM11 Configuration

#define	PIO_INSTR_MEM11_INSTR_MEM11					(0xFFFFu<<0)
#define	PIO_INSTR_MEM11_INSTR_MEM11_0				(0x1u<<0)

// INSTR_MEM12 Configuration

#define	PIO_INSTR_MEM12_INSTR_MEM12					(0xFFFFu<<0)
#define	PIO_INSTR_MEM12_INSTR_MEM12_0				(0x1u<<0)

// INSTR_MEM13 Configuration

#define	PIO_INSTR_MEM13_INSTR_MEM13					(0xFFFFu<<0)
#define	PIO_INSTR_MEM13_INSTR_MEM13_0				(0x1u<<0)

// INSTR_MEM14 Configuration

#define	PIO_INSTR_MEM14_INSTR_MEM14					(0xFFFFu<<0)
#define	PIO_INSTR_MEM14_INSTR_MEM14_0				(0x1u<<0)

// INSTR_MEM15 Configuration

#define	PIO_INSTR_MEM15_INSTR_MEM15					(0xFFFFu<<0)
#define	PIO_INSTR_MEM15_INSTR_MEM15_0				(0x1u<<0)

// INSTR_MEM16 Configuration

#define	PIO_INSTR_MEM16_INSTR_MEM16					(0xFFFFu<<0)
#define	PIO_INSTR_MEM16_INSTR_MEM16_0				(0x1u<<0)

// INSTR_MEM17 Configuration

#define	PIO_INSTR_MEM17_INSTR_MEM17					(0xFFFFu<<0)
#define	PIO_INSTR_MEM17_INSTR_MEM17_0				(0x1u<<0)

// INSTR_MEM18 Configuration

#define	PIO_INSTR_MEM18_INSTR_MEM18					(0xFFFFu<<0)
#define	PIO_INSTR_MEM18_INSTR_MEM18_0				(0x1u<<0)

// INSTR_MEM19 Configuration

#define	PIO_INSTR_MEM19_INSTR_MEM19					(0xFFFFu<<0)
#define	PIO_INSTR_MEM19_INSTR_MEM19_0				(0x1u<<0)

// INSTR_MEM20 Configuration

#define	PIO_INSTR_MEM20_INSTR_MEM20					(0xFFFFu<<0)
#define	PIO_INSTR_MEM20_INSTR_MEM20_0				(0x1u<<0)

// INSTR_MEM21 Configuration

#define	PIO_INSTR_MEM21_INSTR_MEM21					(0xFFFFu<<0)
#define	PIO_INSTR_MEM21_INSTR_MEM21_0				(0x1u<<0)

// INSTR_MEM22 Configuration

#define	PIO_INSTR_MEM22_INSTR_MEM22					(0xFFFFu<<0)
#define	PIO_INSTR_MEM22_INSTR_MEM22_0				(0x1u<<0)

// INSTR_MEM23 Configuration

#define	PIO_INSTR_MEM23_INSTR_MEM23					(0xFFFFu<<0)
#define	PIO_INSTR_MEM23_INSTR_MEM23_0				(0x1u<<0)

// INSTR_MEM24 Configuration

#define	PIO_INSTR_MEM24_INSTR_MEM24					(0xFFFFu<<0)
#define	PIO_INSTR_MEM24_INSTR_MEM24_0				(0x1u<<0)

// INSTR_MEM25 Configuration

#define	PIO_INSTR_MEM25_INSTR_MEM25					(0xFFFFu<<0)
#define	PIO_INSTR_MEM25_INSTR_MEM25_0				(0x1u<<0)

// INSTR_MEM26 Configuration

#define	PIO_INSTR_MEM26_INSTR_MEM26					(0xFFFFu<<0)
#define	PIO_INSTR_MEM26_INSTR_MEM26_0				(0x1u<<0)

// INSTR_MEM27 Configuration

#define	PIO_INSTR_MEM27_INSTR_MEM27					(0xFFFFu<<0)
#define	PIO_INSTR_MEM27_INSTR_MEM27_0				(0x1u<<0)

// INSTR_MEM28 Configuration

#define	PIO_INSTR_MEM28_INSTR_MEM28					(0xFFFFu<<0)
#define	PIO_INSTR_MEM28_INSTR_MEM28_0				(0x1u<<0)

// INSTR_MEM29 Configuration

#define	PIO_INSTR_MEM29_INSTR_MEM29					(0xFFFFu<<0)
#define	PIO_INSTR_MEM29_INSTR_MEM29_0				(0x1u<<0)

// INSTR_MEM30 Configuration

#define	PIO_INSTR_MEM30_INSTR_MEM30					(0xFFFFu<<0)
#define	PIO_INSTR_MEM30_INSTR_MEM30_0				(0x1u<<0)

// INSTR_MEM31 Configuration

#define	PIO_INSTR_MEM31_INSTR_MEM31					(0xFFFFu<<0)
#define	PIO_INSTR_MEM31_INSTR_MEM31_0				(0x1u<<0)

// SM0_CLKDIV Configuration

#define	PIO_SM0_CLKDIV_FRAC							(0xFFu<<8)
#define	PIO_SM0_CLKDIV_FRAC_0						(0x1u<<8)
#define	PIO_SM0_CLKDIV_INT							(0xFFFFu<<16)
#define	PIO_SM0_CLKDIV_INT_0						(0x1u<<16)

// SM0_EXECCTRL Configuration

#define	PIO_SM0_EXECCTRL_STATUS_N					(0x1Fu<<0)
#define	PIO_SM0_EXECCTRL_STATUS_N_0					(0x1u<<0)
#define	PIO_SM0_EXECCTRL_STATUS_SEL					(0x3u<<5)
#define	PIO_SM0_EXECCTRL_STATUS_SEL_0				(0x1u<<5)
#define	PIO_SM0_EXECCTRL_WRAP_BOTTOM				(0x1Fu<<7)
#define	PIO_SM0_EXECCTRL_WRAP_BOTTOM_0				(0x1u<<7)
#define	PIO_SM0_EXECCTRL_WRAP_TOP					(0x1Fu<<12)
#define	PIO_SM0_EXECCTRL_WRAP_TOP_0					(0x1u<<12)
#define	PIO_SM0_EXECCTRL_OUT_STICKY					(0x1u<<17)
#define	PIO_SM0_EXECCTRL_INLINE_OUT_EN				(0x1u<<18)
#define	PIO_SM0_EXECCTRL_OUT_EN_SEL					(0x1Fu<<19)
#define	PIO_SM0_EXECCTRL_OUT_EN_SEL_0				(0x1u<<19)
#define	PIO_SM0_EXECCTRL_JMP_PIN					(0x1Fu<<24)
#define	PIO_SM0_EXECCTRL_JMP_PIN_0					(0x1u<<24)
#define	PIO_SM0_EXECCTRL_SIDE_PINDIR				(0x1u<<29)
#define	PIO_SM0_EXECCTRL_SIDE_EN					(0x1u<<30)
#define	PIO_SM0_EXECCTRL_EXEC_STALLED				(0x1u<<31)
#define	PIO_SM0_EXECCTRL_STATUS_N_IRQ				(0x0u<<0)
#define	PIO_SM0_EXECCTRL_STATUS_N_IRQ_PREVPIO		(0x8u<<0)
#define	PIO_SM0_EXECCTRL_STATUS_N_IRQ_NEXTPIO		(0x10u<<0)
#define	PIO_SM0_EXECCTRL_STATUS_SEL_TXLEVEL			(0x0u<<5)
#define	PIO_SM0_EXECCTRL_STATUS_SEL_RXLEVEL			(0x1u<<5)
#define	PIO_SM0_EXECCTRL_STATUS_SEL_IRQ				(0x2u<<5)

// SM0_SHIFTCTRL Configuration

#define	PIO_SM0_SHIFTCTRL_IN_COUNT					(0x1Fu<<0)
#define	PIO_SM0_SHIFTCTRL_IN_COUNT_0				(0x1u<<0)
#define	PIO_SM0_SHIFTCTRL_FJOIN_RX_GET				(0x1u<<14)
#define	PIO_SM0_SHIFTCTRL_FJOIN_RX_PUT				(0x1u<<15)
#define	PIO_SM0_SHIFTCTRL_AUTOPUSH					(0x1u<<16)
#define	PIO_SM0_SHIFTCTRL_AUTOPULL					(0x1u<<17)
#define	PIO_SM0_SHIFTCTRL_IN_SHIFTDIR				(0x1u<<18)
#define	PIO_SM0_SHIFTCTRL_OUT_SHIFTDIR				(0x1u<<19)
#define	PIO_SM0_SHIFTCTRL_PUSH_THRESH				(0x1Fu<<20)
#define	PIO_SM0_SHIFTCTRL_PUSH_THRESH_0				(0x1u<<20)
#define	PIO_SM0_SHIFTCTRL_PULL_THRESH				(0x1Fu<<25)
#define	PIO_SM0_SHIFTCTRL_PULL_THRESH_0				(0x1u<<25)
#define	PIO_SM0_SHIFTCTRL_FJOIN_TX					(0x1u<<30)
#define	PIO_SM0_SHIFTCTRL_FJOIN_RX					(0x1u<<31)

// SM0_ADDR Configuration

#define	PIO_SM0_ADDR_SM0_ADDR						(0x1Fu<<0)
#define	PIO_SM0_ADDR_SM0_ADDR_0						(0x1u<<0)

// SM0_INSTR Configuration

#define	PIO_SM0_INSTR_SM0_INSTR						(0xFFFFu<<0)
#define	PIO_SM0_INSTR_SM0_INSTR_0					(0x1u<<0)

// SM0_PINCTRL Configuration

#define	PIO_SM0_PINCTRL_OUT_BASE					(0x1Fu<<0)
#define	PIO_SM0_PINCTRL_OUT_BASE_0					(0x1u<<0)
#define	PIO_SM0_PINCTRL_SET_BASE					(0x1Fu<<5)
#define	PIO_SM0_PINCTRL_SET_BASE_0					(0x1u<<5)
#define	PIO_SM0_PINCTRL_SIDESET_BASE				(0x1Fu<<10)
#define	PIO_SM0_PINCTRL_SIDESET_BASE_0				(0x1u<<10)
#define	PIO_SM0_PINCTRL_IN_BASE						(0x1Fu<<15)
#define	PIO_SM0_PINCTRL_IN_BASE_0					(0x1u<<15)
#define	PIO_SM0_PINCTRL_OUT_COUNT					(0x3Fu<<20)
#define	PIO_SM0_PINCTRL_OUT_COUNT_0					(0x1u<<20)
#define	PIO_SM0_PINCTRL_SET_COUNT					(0x7u<<26)
#define	PIO_SM0_PINCTRL_SET_COUNT_0					(0x1u<<26)
#define	PIO_SM0_PINCTRL_SIDESET_COUNT				(0x7u<<29)
#define	PIO_SM0_PINCTRL_SIDESET_COUNT_0				(0x1u<<29)

// SM1_CLKDIV Configuration

#define	PIO_SM1_CLKDIV_FRAC							(0xFFu<<8)
#define	PIO_SM1_CLKDIV_FRAC_0						(0x1u<<8)
#define	PIO_SM1_CLKDIV_INT							(0xFFFFu<<16)
#define	PIO_SM1_CLKDIV_INT_0						(0x1u<<16)

// SM1_EXECCTRL Configuration

#define	PIO_SM1_EXECCTRL_STATUS_N					(0x1Fu<<0)
#define	PIO_SM1_EXECCTRL_STATUS_N_0					(0x1u<<0)
#define	PIO_SM1_EXECCTRL_STATUS_SEL					(0x3u<<5)
#define	PIO_SM1_EXECCTRL_STATUS_SEL_0				(0x1u<<5)
#define	PIO_SM1_EXECCTRL_WRAP_BOTTOM				(0x1Fu<<7)
#define	PIO_SM1_EXECCTRL_WRAP_BOTTOM_0				(0x1u<<7)
#define	PIO_SM1_EXECCTRL_WRAP_TOP					(0x1Fu<<12)
#define	PIO_SM1_EXECCTRL_WRAP_TOP_0					(0x1u<<12)
#define	PIO_SM1_EXECCTRL_OUT_STICKY					(0x1u<<17)
#define	PIO_SM1_EXECCTRL_INLINE_OUT_EN				(0x1u<<18)
#define	PIO_SM1_EXECCTRL_OUT_EN_SEL					(0x1Fu<<19)
#define	PIO_SM1_EXECCTRL_OUT_EN_SEL_0				(0x1u<<19)
#define	PIO_SM1_EXECCTRL_JMP_PIN					(0x1Fu<<24)
#define	PIO_SM1_EXECCTRL_JMP_PIN_0					(0x1u<<24)
#define	PIO_SM1_EXECCTRL_SIDE_PINDIR				(0x1u<<29)
#define	PIO_SM1_EXECCTRL_SIDE_EN					(0x1u<<30)
#define	PIO_SM1_EXECCTRL_EXEC_STALLED				(0x1u<<31)
#define	PIO_SM1_EXECCTRL_STATUS_N_IRQ				(0x0u<<0)
#define	PIO_SM1_EXECCTRL_STATUS_N_IRQ_PREVPIO		(0x8u<<0)
#define	PIO_SM1_EXECCTRL_STATUS_N_IRQ_NEXTPIO		(0x10u<<0)
#define	PIO_SM1_EXECCTRL_STATUS_SEL_TXLEVEL			(0x0u<<5)
#define	PIO_SM1_EXECCTRL_STATUS_SEL_RXLEVEL			(0x1u<<5)
#define	PIO_SM1_EXECCTRL_STATUS_SEL_IRQ				(0x2u<<5)

// SM1_SHIFTCTRL Configuration

#define	PIO_SM1_SHIFTCTRL_IN_COUNT					(0x1Fu<<0)
#define	PIO_SM1_SHIFTCTRL_IN_COUNT_0				(0x1u<<0)
#define	PIO_SM1_SHIFTCTRL_FJOIN_RX_GET				(0x1u<<14)
#define	PIO_SM1_SHIFTCTRL_FJOIN_RX_PUT				(0x1u<<15)
#define	PIO_SM1_SHIFTCTRL_AUTOPUSH					(0x1u<<16)
#define	PIO_SM1_SHIFTCTRL_AUTOPULL					(0x1u<<17)
#define	PIO_SM1_SHIFTCTRL_IN_SHIFTDIR				(0x1u<<18)
#define	PIO_SM1_SHIFTCTRL_OUT_SHIFTDIR				(0x1u<<19)
#define	PIO_SM1_SHIFTCTRL_PUSH_THRESH				(0x1Fu<<20)
#define	PIO_SM1_SHIFTCTRL_PUSH_THRESH_0				(0x1u<<20)
#define	PIO_SM1_SHIFTCTRL_PULL_THRESH				(0x1Fu<<25)
#define	PIO_SM1_SHIFTCTRL_PULL_THRESH_0				(0x1u<<25)
#define	PIO_SM1_SHIFTCTRL_FJOIN_TX					(0x1u<<30)
#define	PIO_SM1_SHIFTCTRL_FJOIN_RX					(0x1u<<31)

// SM1_ADDR Configuration

#define	PIO_SM1_ADDR_SM1_ADDR						(0x1Fu<<0)
#define	PIO_SM1_ADDR_SM1_ADDR_0						(0x1u<<0)

// SM1_INSTR Configuration

#define	PIO_SM1_INSTR_SM1_INSTR						(0xFFFFu<<0)
#define	PIO_SM1_INSTR_SM1_INSTR_0					(0x1u<<0)

// SM1_PINCTRL Configuration

#define	PIO_SM1_PINCTRL_OUT_BASE					(0x1Fu<<0)
#define	PIO_SM1_PINCTRL_OUT_BASE_0					(0x1u<<0)
#define	PIO_SM1_PINCTRL_SET_BASE					(0x1Fu<<5)
#define	PIO_SM1_PINCTRL_SET_BASE_0					(0x1u<<5)
#define	PIO_SM1_PINCTRL_SIDESET_BASE				(0x1Fu<<10)
#define	PIO_SM1_PINCTRL_SIDESET_BASE_0				(0x1u<<10)
#define	PIO_SM1_PINCTRL_IN_BASE						(0x1Fu<<15)
#define	PIO_SM1_PINCTRL_IN_BASE_0					(0x1u<<15)
#define	PIO_SM1_PINCTRL_OUT_COUNT					(0x3Fu<<20)
#define	PIO_SM1_PINCTRL_OUT_COUNT_0					(0x1u<<20)
#define	PIO_SM1_PINCTRL_SET_COUNT					(0x7u<<26)
#define	PIO_SM1_PINCTRL_SET_COUNT_0					(0x1u<<26)
#define	PIO_SM1_PINCTRL_SIDESET_COUNT				(0x7u<<29)
#define	PIO_SM1_PINCTRL_SIDESET_COUNT_0				(0x1u<<29)

// SM2_CLKDIV Configuration

#define	PIO_SM2_CLKDIV_FRAC							(0xFFu<<8)
#define	PIO_SM2_CLKDIV_FRAC_0						(0x1u<<8)
#define	PIO_SM2_CLKDIV_INT							(0xFFFFu<<16)
#define	PIO_SM2_CLKDIV_INT_0						(0x1u<<16)

// SM2_EXECCTRL Configuration

#define	PIO_SM2_EXECCTRL_STATUS_N					(0x1Fu<<0)
#define	PIO_SM2_EXECCTRL_STATUS_N_0					(0x1u<<0)
#define	PIO_SM2_EXECCTRL_STATUS_SEL					(0x3u<<5)
#define	PIO_SM2_EXECCTRL_STATUS_SEL_0				(0x1u<<5)
#define	PIO_SM2_EXECCTRL_WRAP_BOTTOM				(0x1Fu<<7)
#define	PIO_SM2_EXECCTRL_WRAP_BOTTOM_0				(0x1u<<7)
#define	PIO_SM2_EXECCTRL_WRAP_TOP					(0x1Fu<<12)
#define	PIO_SM2_EXECCTRL_WRAP_TOP_0					(0x1u<<12)
#define	PIO_SM2_EXECCTRL_OUT_STICKY					(0x1u<<17)
#define	PIO_SM2_EXECCTRL_INLINE_OUT_EN				(0x1u<<18)
#define	PIO_SM2_EXECCTRL_OUT_EN_SEL					(0x1Fu<<19)
#define	PIO_SM2_EXECCTRL_OUT_EN_SEL_0				(0x1u<<19)
#define	PIO_SM2_EXECCTRL_JMP_PIN					(0x1Fu<<24)
#define	PIO_SM2_EXECCTRL_JMP_PIN_0					(0x1u<<24)
#define	PIO_SM2_EXECCTRL_SIDE_PINDIR				(0x1u<<29)
#define	PIO_SM2_EXECCTRL_SIDE_EN					(0x1u<<30)
#define	PIO_SM2_EXECCTRL_EXEC_STALLED				(0x1u<<31)
#define	PIO_SM2_EXECCTRL_STATUS_N_IRQ				(0x0u<<0)
#define	PIO_SM2_EXECCTRL_STATUS_N_IRQ_PREVPIO		(0x8u<<0)
#define	PIO_SM2_EXECCTRL_STATUS_N_IRQ_NEXTPIO		(0x10u<<0)
#define	PIO_SM2_EXECCTRL_STATUS_SEL_TXLEVEL			(0x0u<<5)
#define	PIO_SM2_EXECCTRL_STATUS_SEL_RXLEVEL			(0x1u<<5)
#define	PIO_SM2_EXECCTRL_STATUS_SEL_IRQ				(0x2u<<5)

// SM2_SHIFTCTRL Configuration

#define	PIO_SM2_SHIFTCTRL_IN_COUNT					(0x1Fu<<0)
#define	PIO_SM2_SHIFTCTRL_IN_COUNT_0				(0x1u<<0)
#define	PIO_SM2_SHIFTCTRL_FJOIN_RX_GET				(0x1u<<14)
#define	PIO_SM2_SHIFTCTRL_FJOIN_RX_PUT				(0x1u<<15)
#define	PIO_SM2_SHIFTCTRL_AUTOPUSH					(0x1u<<16)
#define	PIO_SM2_SHIFTCTRL_AUTOPULL					(0x1u<<17)
#define	PIO_SM2_SHIFTCTRL_IN_SHIFTDIR				(0x1u<<18)
#define	PIO_SM2_SHIFTCTRL_OUT_SHIFTDIR				(0x1u<<19)
#define	PIO_SM2_SHIFTCTRL_PUSH_THRESH				(0x1Fu<<20)
#define	PIO_SM2_SHIFTCTRL_PUSH_THRESH_0				(0x1u<<20)
#define	PIO_SM2_SHIFTCTRL_PULL_THRESH				(0x1Fu<<25)
#define	PIO_SM2_SHIFTCTRL_PULL_THRESH_0				(0x1u<<25)
#define	PIO_SM2_SHIFTCTRL_FJOIN_TX					(0x1u<<30)
#define	PIO_SM2_SHIFTCTRL_FJOIN_RX					(0x1u<<31)

// SM2_ADDR Configuration

#define	PIO_SM2_ADDR_SM2_ADDR						(0x1Fu<<0)
#define	PIO_SM2_ADDR_SM2_ADDR_0						(0x1u<<0)

// SM2_INSTR Configuration

#define	PIO_SM2_INSTR_SM2_INSTR						(0xFFFFu<<0)
#define	PIO_SM2_INSTR_SM2_INSTR_0					(0x1u<<0)

// SM2_PINCTRL Configuration

#define	PIO_SM2_PINCTRL_OUT_BASE					(0x1Fu<<0)
#define	PIO_SM2_PINCTRL_OUT_BASE_0					(0x1u<<0)
#define	PIO_SM2_PINCTRL_SET_BASE					(0x1Fu<<5)
#define	PIO_SM2_PINCTRL_SET_BASE_0					(0x1u<<5)
#define	PIO_SM2_PINCTRL_SIDESET_BASE				(0x1Fu<<10)
#define	PIO_SM2_PINCTRL_SIDESET_BASE_0				(0x1u<<10)
#define	PIO_SM2_PINCTRL_IN_BASE						(0x1Fu<<15)
#define	PIO_SM2_PINCTRL_IN_BASE_0					(0x1u<<15)
#define	PIO_SM2_PINCTRL_OUT_COUNT					(0x3Fu<<20)
#define	PIO_SM2_PINCTRL_OUT_COUNT_0					(0x1u<<20)
#define	PIO_SM2_PINCTRL_SET_COUNT					(0x7u<<26)
#define	PIO_SM2_PINCTRL_SET_COUNT_0					(0x1u<<26)
#define	PIO_SM2_PINCTRL_SIDESET_COUNT				(0x7u<<29)
#define	PIO_SM2_PINCTRL_SIDESET_COUNT_0				(0x1u<<29)

// SM3_CLKDIV Configuration

#define	PIO_SM3_CLKDIV_FRAC							(0xFFu<<8)
#define	PIO_SM3_CLKDIV_FRAC_0						(0x1u<<8)
#define	PIO_SM3_CLKDIV_INT							(0xFFFFu<<16)
#define	PIO_SM3_CLKDIV_INT_0						(0x1u<<16)

// SM3_EXECCTRL Configuration

#define	PIO_SM3_EXECCTRL_STATUS_N					(0x1Fu<<0)
#define	PIO_SM3_EXECCTRL_STATUS_N_0					(0x1u<<0)
#define	PIO_SM3_EXECCTRL_STATUS_SEL					(0x3u<<5)
#define	PIO_SM3_EXECCTRL_STATUS_SEL_0				(0x1u<<5)
#define	PIO_SM3_EXECCTRL_WRAP_BOTTOM				(0x1Fu<<7)
#define	PIO_SM3_EXECCTRL_WRAP_BOTTOM_0				(0x1u<<7)
#define	PIO_SM3_EXECCTRL_WRAP_TOP					(0x1Fu<<12)
#define	PIO_SM3_EXECCTRL_WRAP_TOP_0					(0x1u<<12)
#define	PIO_SM3_EXECCTRL_OUT_STICKY					(0x1u<<17)
#define	PIO_SM3_EXECCTRL_INLINE_OUT_EN				(0x1u<<18)
#define	PIO_SM3_EXECCTRL_OUT_EN_SEL					(0x1Fu<<19)
#define	PIO_SM3_EXECCTRL_OUT_EN_SEL_0				(0x1u<<19)
#define	PIO_SM3_EXECCTRL_JMP_PIN					(0x1Fu<<24)
#define	PIO_SM3_EXECCTRL_JMP_PIN_0					(0x1u<<24)
#define	PIO_SM3_EXECCTRL_SIDE_PINDIR				(0x1u<<29)
#define	PIO_SM3_EXECCTRL_SIDE_EN					(0x1u<<30)
#define	PIO_SM3_EXECCTRL_EXEC_STALLED				(0x1u<<31)
#define	PIO_SM3_EXECCTRL_STATUS_N_IRQ				(0x0u<<0)
#define	PIO_SM3_EXECCTRL_STATUS_N_IRQ_PREVPIO		(0x8u<<0)
#define	PIO_SM3_EXECCTRL_STATUS_N_IRQ_NEXTPIO		(0x10u<<0)
#define	PIO_SM3_EXECCTRL_STATUS_SEL_TXLEVEL			(0x0u<<5)
#define	PIO_SM3_EXECCTRL_STATUS_SEL_RXLEVEL			(0x1u<<5)
#define	PIO_SM3_EXECCTRL_STATUS_SEL_IRQ				(0x2u<<5)

// SM3_SHIFTCTRL Configuration

#define	PIO_SM3_SHIFTCTRL_IN_COUNT					(0x1Fu<<0)
#define	PIO_SM3_SHIFTCTRL_IN_COUNT_0				(0x1u<<0)
#define	PIO_SM3_SHIFTCTRL_FJOIN_RX_GET				(0x1u<<14)
#define	PIO_SM3_SHIFTCTRL_FJOIN_RX_PUT				(0x1u<<15)
#define	PIO_SM3_SHIFTCTRL_AUTOPUSH					(0x1u<<16)
#define	PIO_SM3_SHIFTCTRL_AUTOPULL					(0x1u<<17)
#define	PIO_SM3_SHIFTCTRL_IN_SHIFTDIR				(0x1u<<18)
#define	PIO_SM3_SHIFTCTRL_OUT_SHIFTDIR				(0x1u<<19)
#define	PIO_SM3_SHIFTCTRL_PUSH_THRESH				(0x1Fu<<20)
#define	PIO_SM3_SHIFTCTRL_PUSH_THRESH_0				(0x1u<<20)
#define	PIO_SM3_SHIFTCTRL_PULL_THRESH				(0x1Fu<<25)
#define	PIO_SM3_SHIFTCTRL_PULL_THRESH_0				(0x1u<<25)
#define	PIO_SM3_SHIFTCTRL_FJOIN_TX					(0x1u<<30)
#define	PIO_SM3_SHIFTCTRL_FJOIN_RX					(0x1u<<31)

// SM3_ADDR Configuration

#define	PIO_SM3_ADDR_SM3_ADDR						(0x1Fu<<0)
#define	PIO_SM3_ADDR_SM3_ADDR_0						(0x1u<<0)

// SM3_INSTR Configuration

#define	PIO_SM3_INSTR_SM3_INSTR						(0xFFFFu<<0)
#define	PIO_SM3_INSTR_SM3_INSTR_0					(0x1u<<0)

// SM3_PINCTRL Configuration

#define	PIO_SM3_PINCTRL_OUT_BASE					(0x1Fu<<0)
#define	PIO_SM3_PINCTRL_OUT_BASE_0					(0x1u<<0)
#define	PIO_SM3_PINCTRL_SET_BASE					(0x1Fu<<5)
#define	PIO_SM3_PINCTRL_SET_BASE_0					(0x1u<<5)
#define	PIO_SM3_PINCTRL_SIDESET_BASE				(0x1Fu<<10)
#define	PIO_SM3_PINCTRL_SIDESET_BASE_0				(0x1u<<10)
#define	PIO_SM3_PINCTRL_IN_BASE						(0x1Fu<<15)
#define	PIO_SM3_PINCTRL_IN_BASE_0					(0x1u<<15)
#define	PIO_SM3_PINCTRL_OUT_COUNT					(0x3Fu<<20)
#define	PIO_SM3_PINCTRL_OUT_COUNT_0					(0x1u<<20)
#define	PIO_SM3_PINCTRL_SET_COUNT					(0x7u<<26)
#define	PIO_SM3_PINCTRL_SET_COUNT_0					(0x1u<<26)
#define	PIO_SM3_PINCTRL_SIDESET_COUNT				(0x7u<<29)
#define	PIO_SM3_PINCTRL_SIDESET_COUNT_0				(0x1u<<29)

// RXF0_PUTGET0 Configuration

#define	PIO_RXF0_PUTGET0_RXF0_PUTGET0				(0xFFFFFFFFu<<0)
#define	PIO_RXF0_PUTGET0_RXF0_PUTGET0_0				(0x1u<<0)

// RXF0_PUTGET1 Configuration

#define	PIO_RXF0_PUTGET1_RXF0_PUTGET1				(0xFFFFFFFFu<<0)
#define	PIO_RXF0_PUTGET1_RXF0_PUTGET1_0				(0x1u<<0)

// RXF0_PUTGET2 Configuration

#define	PIO_RXF0_PUTGET2_RXF0_PUTGET2				(0xFFFFFFFFu<<0)
#define	PIO_RXF0_PUTGET2_RXF0_PUTGET2_0				(0x1u<<0)

// RXF0_PUTGET3 Configuration

#define	PIO_RXF0_PUTGET3_RXF0_PUTGET3				(0xFFFFFFFFu<<0)
#define	PIO_RXF0_PUTGET3_RXF0_PUTGET3_0				(0x1u<<0)

// RXF1_PUTGET0 Configuration

#define	PIO_RXF1_PUTGET0_RXF1_PUTGET0				(0xFFFFFFFFu<<0)
#define	PIO_RXF1_PUTGET0_RXF1_PUTGET0_0				(0x1u<<0)

// RXF1_PUTGET1 Configuration

#define	PIO_RXF1_PUTGET1_RXF1_PUTGET1				(0xFFFFFFFFu<<0)
#define	PIO_RXF1_PUTGET1_RXF1_PUTGET1_0				(0x1u<<0)

// RXF1_PUTGET2 Configuration

#define	PIO_RXF1_PUTGET2_RXF1_PUTGET2				(0xFFFFFFFFu<<0)
#define	PIO_RXF1_PUTGET2_RXF1_PUTGET2_0				(0x1u<<0)

// RXF1_PUTGET3 Configuration

#define	PIO_RXF1_PUTGET3_RXF1_PUTGET3				(0xFFFFFFFFu<<0)
#define	PIO_RXF1_PUTGET3_RXF1_PUTGET3_0				(0x1u<<0)

// RXF2_PUTGET0 Configuration

#define	PIO_RXF2_PUTGET0_RXF2_PUTGET0				(0xFFFFFFFFu<<0)
#define	PIO_RXF2_PUTGET0_RXF2_PUTGET0_0				(0x1u<<0)

// RXF2_PUTGET1 Configuration

#define	PIO_RXF2_PUTGET1_RXF2_PUTGET1				(0xFFFFFFFFu<<0)
#define	PIO_RXF2_PUTGET1_RXF2_PUTGET1_0				(0x1u<<0)

// RXF2_PUTGET2 Configuration

#define	PIO_RXF2_PUTGET2_RXF2_PUTGET2				(0xFFFFFFFFu<<0)
#define	PIO_RXF2_PUTGET2_RXF2_PUTGET2_0				(0x1u<<0)

// RXF2_PUTGET3 Configuration

#define	PIO_RXF2_PUTGET3_RXF2_PUTGET3				(0xFFFFFFFFu<<0)
#define	PIO_RXF2_PUTGET3_RXF2_PUTGET3_0				(0x1u<<0)

// RXF3_PUTGET0 Configuration

#define	PIO_RXF3_PUTGET0_RXF3_PUTGET0				(0xFFFFFFFFu<<0)
#define	PIO_RXF3_PUTGET0_RXF3_PUTGET0_0				(0x1u<<0)

// RXF3_PUTGET1 Configuration

#define	PIO_RXF3_PUTGET1_RXF3_PUTGET1				(0xFFFFFFFFu<<0)
#define	PIO_RXF3_PUTGET1_RXF3_PUTGET1_0				(0x1u<<0)

// RXF3_PUTGET2 Configuration

#define	PIO_RXF3_PUTGET2_RXF3_PUTGET2				(0xFFFFFFFFu<<0)
#define	PIO_RXF3_PUTGET2_RXF3_PUTGET2_0				(0x1u<<0)

// RXF3_PUTGET3 Configuration

#define	PIO_RXF3_PUTGET3_RXF3_PUTGET3				(0xFFFFFFFFu<<0)
#define	PIO_RXF3_PUTGET3_RXF3_PUTGET3_0				(0x1u<<0)

// GPIOBASE Configuration

#define	PIO_GPIOBASE_GPIOBASE						(0x1u<<4)

// INTR Configuration

#define	PIO_INTR_SM0_RXNEMPTY						(0x1u<<0)
#define	PIO_INTR_SM1_RXNEMPTY						(0x1u<<1)
#define	PIO_INTR_SM2_RXNEMPTY						(0x1u<<2)
#define	PIO_INTR_SM3_RXNEMPTY						(0x1u<<3)
#define	PIO_INTR_SM0_TXNFULL						(0x1u<<4)
#define	PIO_INTR_SM1_TXNFULL						(0x1u<<5)
#define	PIO_INTR_SM2_TXNFULL						(0x1u<<6)
#define	PIO_INTR_SM3_TXNFULL						(0x1u<<7)
#define	PIO_INTR_SM0								(0x1u<<8)
#define	PIO_INTR_SM1								(0x1u<<9)
#define	PIO_INTR_SM2								(0x1u<<10)
#define	PIO_INTR_SM3								(0x1u<<11)
#define	PIO_INTR_SM4								(0x1u<<12)
#define	PIO_INTR_SM5								(0x1u<<13)
#define	PIO_INTR_SM6								(0x1u<<14)
#define	PIO_INTR_SM7								(0x1u<<15)

// IRQ0_INTE Configuration

#define	PIO_IRQ0_INTE_SM0_RXNEMPTY					(0x1u<<0)
#define	PIO_IRQ0_INTE_SM1_RXNEMPTY					(0x1u<<1)
#define	PIO_IRQ0_INTE_SM2_RXNEMPTY					(0x1u<<2)
#define	PIO_IRQ0_INTE_SM3_RXNEMPTY					(0x1u<<3)
#define	PIO_IRQ0_INTE_SM0_TXNFULL					(0x1u<<4)
#define	PIO_IRQ0_INTE_SM1_TXNFULL					(0x1u<<5)
#define	PIO_IRQ0_INTE_SM2_TXNFULL					(0x1u<<6)
#define	PIO_IRQ0_INTE_SM3_TXNFULL					(0x1u<<7)
#define	PIO_IRQ0_INTE_SM0							(0x1u<<8)
#define	PIO_IRQ0_INTE_SM1							(0x1u<<9)
#define	PIO_IRQ0_INTE_SM2							(0x1u<<10)
#define	PIO_IRQ0_INTE_SM3							(0x1u<<11)
#define	PIO_IRQ0_INTE_SM4							(0x1u<<12)
#define	PIO_IRQ0_INTE_SM5							(0x1u<<13)
#define	PIO_IRQ0_INTE_SM6							(0x1u<<14)
#define	PIO_IRQ0_INTE_SM7							(0x1u<<15)

// IRQ0_INTF Configuration

#define	PIO_IRQ0_INTF_SM0_RXNEMPTY					(0x1u<<0)
#define	PIO_IRQ0_INTF_SM1_RXNEMPTY					(0x1u<<1)
#define	PIO_IRQ0_INTF_SM2_RXNEMPTY					(0x1u<<2)
#define	PIO_IRQ0_INTF_SM3_RXNEMPTY					(0x1u<<3)
#define	PIO_IRQ0_INTF_SM0_TXNFULL					(0x1u<<4)
#define	PIO_IRQ0_INTF_SM1_TXNFULL					(0x1u<<5)
#define	PIO_IRQ0_INTF_SM2_TXNFULL					(0x1u<<6)
#define	PIO_IRQ0_INTF_SM3_TXNFULL					(0x1u<<7)
#define	PIO_IRQ0_INTF_SM0							(0x1u<<8)
#define	PIO_IRQ0_INTF_SM1							(0x1u<<9)
#define	PIO_IRQ0_INTF_SM2							(0x1u<<10)
#define	PIO_IRQ0_INTF_SM3							(0x1u<<11)
#define	PIO_IRQ0_INTF_SM4							(0x1u<<12)
#define	PIO_IRQ0_INTF_SM5							(0x1u<<13)
#define	PIO_IRQ0_INTF_SM6							(0x1u<<14)
#define	PIO_IRQ0_INTF_SM7							(0x1u<<15)

// IRQ0_INTS Configuration

#define	PIO_IRQ0_INTS_SM0_RXNEMPTY					(0x1u<<0)
#define	PIO_IRQ0_INTS_SM1_RXNEMPTY					(0x1u<<1)
#define	PIO_IRQ0_INTS_SM2_RXNEMPTY					(0x1u<<2)
#define	PIO_IRQ0_INTS_SM3_RXNEMPTY					(0x1u<<3)
#define	PIO_IRQ0_INTS_SM0_TXNFULL					(0x1u<<4)
#define	PIO_IRQ0_INTS_SM1_TXNFULL					(0x1u<<5)
#define	PIO_IRQ0_INTS_SM2_TXNFULL					(0x1u<<6)
#define	PIO_IRQ0_INTS_SM3_TXNFULL					(0x1u<<7)
#define	PIO_IRQ0_INTS_SM0							(0x1u<<8)
#define	PIO_IRQ0_INTS_SM1							(0x1u<<9)
#define	PIO_IRQ0_INTS_SM2							(0x1u<<10)
#define	PIO_IRQ0_INTS_SM3							(0x1u<<11)
#define	PIO_IRQ0_INTS_SM4							(0x1u<<12)
#define	PIO_IRQ0_INTS_SM5							(0x1u<<13)
#define	PIO_IRQ0_INTS_SM6							(0x1u<<14)
#define	PIO_IRQ0_INTS_SM7							(0x1u<<15)

// IRQ1_INTE Configuration

#define	PIO_IRQ1_INTE_SM0_RXNEMPTY					(0x1u<<0)
#define	PIO_IRQ1_INTE_SM1_RXNEMPTY					(0x1u<<1)
#define	PIO_IRQ1_INTE_SM2_RXNEMPTY					(0x1u<<2)
#define	PIO_IRQ1_INTE_SM3_RXNEMPTY					(0x1u<<3)
#define	PIO_IRQ1_INTE_SM0_TXNFULL					(0x1u<<4)
#define	PIO_IRQ1_INTE_SM1_TXNFULL					(0x1u<<5)
#define	PIO_IRQ1_INTE_SM2_TXNFULL					(0x1u<<6)
#define	PIO_IRQ1_INTE_SM3_TXNFULL					(0x1u<<7)
#define	PIO_IRQ1_INTE_SM0							(0x1u<<8)
#define	PIO_IRQ1_INTE_SM1							(0x1u<<9)
#define	PIO_IRQ1_INTE_SM2							(0x1u<<10)
#define	PIO_IRQ1_INTE_SM3							(0x1u<<11)
#define	PIO_IRQ1_INTE_SM4							(0x1u<<12)
#define	PIO_IRQ1_INTE_SM5							(0x1u<<13)
#define	PIO_IRQ1_INTE_SM6							(0x1u<<14)
#define	PIO_IRQ1_INTE_SM7							(0x1u<<15)

// IRQ1_INTF Configuration

#define	PIO_IRQ1_INTF_SM0_RXNEMPTY					(0x1u<<0)
#define	PIO_IRQ1_INTF_SM1_RXNEMPTY					(0x1u<<1)
#define	PIO_IRQ1_INTF_SM2_RXNEMPTY					(0x1u<<2)
#define	PIO_IRQ1_INTF_SM3_RXNEMPTY					(0x1u<<3)
#define	PIO_IRQ1_INTF_SM0_TXNFULL					(0x1u<<4)
#define	PIO_IRQ1_INTF_SM1_TXNFULL					(0x1u<<5)
#define	PIO_IRQ1_INTF_SM2_TXNFULL					(0x1u<<6)
#define	PIO_IRQ1_INTF_SM3_TXNFULL					(0x1u<<7)
#define	PIO_IRQ1_INTF_SM0							(0x1u<<8)
#define	PIO_IRQ1_INTF_SM1							(0x1u<<9)
#define	PIO_IRQ1_INTF_SM2							(0x1u<<10)
#define	PIO_IRQ1_INTF_SM3							(0x1u<<11)
#define	PIO_IRQ1_INTF_SM4							(0x1u<<12)
#define	PIO_IRQ1_INTF_SM5							(0x1u<<13)
#define	PIO_IRQ1_INTF_SM6							(0x1u<<14)
#define	PIO_IRQ1_INTF_SM7							(0x1u<<15)

// IRQ1_INTS Configuration

#define	PIO_IRQ1_INTS_SM0_RXNEMPTY					(0x1u<<0)
#define	PIO_IRQ1_INTS_SM1_RXNEMPTY					(0x1u<<1)
#define	PIO_IRQ1_INTS_SM2_RXNEMPTY					(0x1u<<2)
#define	PIO_IRQ1_INTS_SM3_RXNEMPTY					(0x1u<<3)
#define	PIO_IRQ1_INTS_SM0_TXNFULL					(0x1u<<4)
#define	PIO_IRQ1_INTS_SM1_TXNFULL					(0x1u<<5)
#define	PIO_IRQ1_INTS_SM2_TXNFULL					(0x1u<<6)
#define	PIO_IRQ1_INTS_SM3_TXNFULL					(0x1u<<7)
#define	PIO_IRQ1_INTS_SM0							(0x1u<<8)
#define	PIO_IRQ1_INTS_SM1							(0x1u<<9)
#define	PIO_IRQ1_INTS_SM2							(0x1u<<10)
#define	PIO_IRQ1_INTS_SM3							(0x1u<<11)
#define	PIO_IRQ1_INTS_SM4							(0x1u<<12)
#define	PIO_IRQ1_INTS_SM5							(0x1u<<13)
#define	PIO_IRQ1_INTS_SM6							(0x1u<<14)
#define	PIO_IRQ1_INTS_SM7							(0x1u<<15)
