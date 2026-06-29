/*
; stm32N657_dts.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_dts equates.
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

// DTS address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	PVTREG_LOCKR;
	volatile	uint32_t	PVTLOCK_SR;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	PVTTMR_CR;
	volatile	uint32_t	PVTTMR_SR;
	volatile	uint32_t	RESERVED2[6];
	volatile	uint32_t	PVT_IER;
	volatile	uint32_t	RESERVED3[3];
	volatile	uint32_t	PVTIRQTRMASKR;
	volatile	uint32_t	TS_MR;
	volatile	uint32_t	RESERVED4[2];
	volatile	uint32_t	PVTTR_SR;
	volatile	uint32_t	TS_ISR;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	PVTTMRRAW_ISR;
	volatile	uint32_t	TSRAW_ISR;
	volatile	uint32_t	RESERVED6[2];
	volatile	uint32_t	TSCCLKSYNTHR;
	volatile	uint32_t	TSCSDIFDISABLER;
	volatile	uint32_t	TSCSDIF_SR;
	volatile	uint32_t	TSCSDIF_CR;
	volatile	uint32_t	TSCSDIFHALTR;
	volatile	uint32_t	TSCSDIF_CFGR;
	volatile	uint32_t	RESERVED7[2];
	volatile	uint32_t	TSCSMPL_CR;
	volatile	uint32_t	TSCSDIFSMPLCLRR;
	volatile	uint32_t	TSCSMPLCNTR;
	volatile	uint32_t	RESERVED8[5];
	volatile	uint32_t	TS0_IER;
	volatile	uint32_t	TS0_ISR;
	volatile	uint32_t	TS0_ICR;
	volatile	uint32_t	TS0IRQTESTR;
	volatile	uint32_t	TS0SDIFRDATAR;
	volatile	uint32_t	TS0SDIFDONER;
	volatile	uint32_t	TS0SDIFDATAR;
	volatile	uint32_t	RESERVED9;
	volatile	uint32_t	TS0ALARMA_CFGR;
	volatile	uint32_t	TS0ALARMB_CFGR;
	volatile	uint32_t	TS0HLSAMPLER;
	volatile	uint32_t	TS0HILORESETR;
	volatile	uint32_t	RESERVED10[4];
	volatile	uint32_t	TS1_IER;
	volatile	uint32_t	TS1_ISR;
	volatile	uint32_t	TS1_ICR;
	volatile	uint32_t	TS1IRQTESTR;
	volatile	uint32_t	TS1SDIFRDATAR;
	volatile	uint32_t	TS1SDIFDONER;
	volatile	uint32_t	TS1SDIFDATAR;
	volatile	uint32_t	RESERVED11;
	volatile	uint32_t	TS1ALARMA_CFGR;
	volatile	uint32_t	TS1ALARMB_CFGR;
	volatile	uint32_t	TS1HLSAMPLER;
	volatile	uint32_t	TS1HILORESETR;
} DTS_TypeDef;

#if (defined(__cplusplus))
#define	DTS_NS	reinterpret_cast<DTS_TypeDef *>(0x4600A000u)
#define	DTS_S	reinterpret_cast<DTS_TypeDef *>(0x5600A000u)

#else
#define	DTS_NS	((DTS_TypeDef *)0x4600A000u)
#define	DTS_S	((DTS_TypeDef *)0x5600A000u)
#endif

// PVTREG_LOCKR Configuration

#define	DTS_PVTREG_LOCKR_LOCK						(0xFFFFFFFFu<<0)
#define	DTS_PVTREG_LOCKR_LOCK_0						(0x1u<<0)

// PVTLOCK_SR Configuration

#define	DTS_PVTLOCK_SR_HW_LOCK_STATUS				(0x1u<<1)
#define	DTS_PVTLOCK_SR_SW_LOCK_STATUS				(0x1u<<0)

// PVTTMR_CR Configuration

#define	DTS_PVTTMR_CR_TMR_RUN						(0x1u<<16)
#define	DTS_PVTTMR_CR_TMR_DELAY						(0xFFFFu<<0)
#define	DTS_PVTTMR_CR_TMR_DELAY_0					(0x1u<<0)

// PVTTMR_SR Configuration

#define	DTS_PVTTMR_SR_TMR_DONE						(0x1u<<1)
#define	DTS_PVTTMR_SR_TMR_BUSY						(0x1u<<0)

// PVT_IER Configuration

#define	DTS_PVT_IER_TS_IRQ_ENABLE					(0x1u<<1)
#define	DTS_PVT_IER_TMR_IRQ_ENABLE					(0x1u<<0)

// PVTIRQTRMASKR Configuration

#define	DTS_PVTIRQTRMASKR_TMR_IRQ_MASK				(0x1u<<0)

// TS_MR Configuration

#define	DTS_TS_MR_TS1_IRQ_MASK						(0x1u<<1)
#define	DTS_TS_MR_TS0_IRQ_MASK						(0x1u<<0)

// PVTTR_SR Configuration

#define	DTS_PVTTR_SR_TMR_IRQ_STATUS					(0x1u<<0)

// TS_ISR Configuration

#define	DTS_TS_ISR_TS1_IRQ_STATUS					(0x1u<<1)
#define	DTS_TS_ISR_TS0_IRQ_STATUS					(0x1u<<0)

// PVTTMRRAW_ISR Configuration

#define	DTS_PVTTMRRAW_ISR_TMR_IRQ_RAW_STATUS		(0x1u<<0)

// TSRAW_ISR Configuration

#define	DTS_TSRAW_ISR_TS1_IRQ_RAW_STATUS			(0x1u<<1)
#define	DTS_TSRAW_ISR_TS0_IRQ_RAW_STATUS			(0x1u<<0)

// TSCCLKSYNTHR Configuration

#define	DTS_TSCCLKSYNTHR_CLK_SYTH_EN				(0x1u<<24)
#define	DTS_TSCCLKSYNTHR_CLK_SYNTH_HOLD				(0xFu<<16)
#define	DTS_TSCCLKSYNTHR_CLK_SYNTH_HOLD_0			(0x1u<<16)
#define	DTS_TSCCLKSYNTHR_CLK_SYNTH_HI				(0xFFu<<8)
#define	DTS_TSCCLKSYNTHR_CLK_SYNTH_HI_0				(0x1u<<8)
#define	DTS_TSCCLKSYNTHR_CLK_SYNTH_LO				(0xFFu<<0)
#define	DTS_TSCCLKSYNTHR_CLK_SYNTH_LO_0				(0x1u<<0)

#define	DTS_TSCCLKSYNTHR_CLK_SYTH_EN_B_0X0			(0x0u<<24)
#define	DTS_TSCCLKSYNTHR_CLK_SYTH_EN_B_0X1			(0x1u<<24)

// TSCSDIFDISABLER Configuration

#define	DTS_TSCSDIFDISABLER_TS1_SDIF_DISABLE		(0x1u<<1)
#define	DTS_TSCSDIFDISABLER_TS0_SDIF_DISABLE		(0x1u<<0)

#define	DTS_TSCSDIFDISABLER_TS1_SDIF_DISABLE_B_0X0	(0x0u<<1)
#define	DTS_TSCSDIFDISABLER_TS1_SDIF_DISABLE_B_0X1	(0x1u<<1)
#define	DTS_TSCSDIFDISABLER_TS0_SDIF_DISABLE_B_0X0	(0x0u<<0)
#define	DTS_TSCSDIFDISABLER_TS0_SDIF_DISABLE_B_0X1	(0x1u<<0)

// TSCSDIF_SR Configuration

#define	DTS_TSCSDIF_SR_SDIF_LOCK					(0x1u<<1)
#define	DTS_TSCSDIF_SR_SDIF_BUSY					(0x1u<<0)

#define	DTS_TSCSDIF_SR_SDIF_LOCK_B_0X0				(0x0u<<1)
#define	DTS_TSCSDIF_SR_SDIF_LOCK_B_0X1				(0x1u<<1)
#define	DTS_TSCSDIF_SR_SDIF_BUSY_B_0X0				(0x0u<<0)
#define	DTS_TSCSDIF_SR_SDIF_BUSY_B_0X1				(0x1u<<0)

// TSCSDIF_CR Configuration

#define	DTS_TSCSDIF_CR_SDIF_PROG					(0x1u<<31)
#define	DTS_TSCSDIF_CR_SDIF_WRN						(0x1u<<27)
#define	DTS_TSCSDIF_CR_SDIF_ADDR					(0x7u<<24)
#define	DTS_TSCSDIF_CR_SDIF_ADDR_0					(0x1u<<24)
#define	DTS_TSCSDIF_CR_SDIF_WDATA					(0xFFFFFFu<<0)
#define	DTS_TSCSDIF_CR_SDIF_WDATA_0					(0x1u<<0)

#define	DTS_TSCSDIF_CR_SDIF_PROG_B_0X0				(0x0u<<31)
#define	DTS_TSCSDIF_CR_SDIF_PROG_B_0X1				(0x1u<<31)
#define	DTS_TSCSDIF_CR_SDIF_WRN_B_0X0				(0x0u<<27)
#define	DTS_TSCSDIF_CR_SDIF_WRN_B_0X1				(0x1u<<27)

// TSCSDIFHALTR Configuration

#define	DTS_TSCSDIFHALTR_SDIF_STOP					(0x1u<<0)

#define	DTS_TSCSDIFHALTR_SDIF_STOP_B_0X0			(0x0u<<0)
#define	DTS_TSCSDIFHALTR_SDIF_STOP_B_0X1			(0x1u<<0)

// TSCSDIF_CFGR Configuration

#define	DTS_TSCSDIF_CFGR_SDIF_INHIBIT				(0x3u<<0)
#define	DTS_TSCSDIF_CFGR_SDIF_INHIBIT_0				(0x1u<<0)

#define	DTS_TSCSDIF_CFGR_SDIF_INHIBIT_B_0X0			(0x0u<<0)
#define	DTS_TSCSDIF_CFGR_SDIF_INHIBIT_B_0X1			(0x1u<<0)
#define	DTS_TSCSDIF_CFGR_SDIF_INHIBIT_B_0X2			(0x2u<<0)
#define	DTS_TSCSDIF_CFGR_SDIF_INHIBIT_B_0X3			(0x3u<<0)

// TSCSMPL_CR Configuration

#define	DTS_TSCSMPL_CR_SMPL_DISCARD					(0x1u<<2)
#define	DTS_TSCSMPL_CR_SMPL_CTR_HOLD				(0x1u<<1)
#define	DTS_TSCSMPL_CR_SMPL_CTR_DISABLE				(0x1u<<0)

#define	DTS_TSCSMPL_CR_SMPL_DISCARD_B_0X0			(0x0u<<2)
#define	DTS_TSCSMPL_CR_SMPL_DISCARD_B_0X1			(0x1u<<2)
#define	DTS_TSCSMPL_CR_SMPL_CTR_HOLD_B_0X0			(0x0u<<1)
#define	DTS_TSCSMPL_CR_SMPL_CTR_HOLD_B_0X1			(0x1u<<1)
#define	DTS_TSCSMPL_CR_SMPL_CTR_DISABLE_B_0X0		(0x0u<<0)
#define	DTS_TSCSMPL_CR_SMPL_CTR_DISABLE_B_0X1		(0x1u<<0)

// TSCSDIFSMPLCLRR Configuration

#define	DTS_TSCSDIFSMPLCLRR_SMPL_CNTER_CLEAR		(0x1u<<0)

#define	DTS_TSCSDIFSMPLCLRR_SMPL_CNTER_CLEAR_B_0X0	(0x0u<<0)
#define	DTS_TSCSDIFSMPLCLRR_SMPL_CNTER_CLEAR_B_0X1	(0x1u<<0)

// TSCSMPLCNTR Configuration

#define	DTS_TSCSMPLCNTR_SMPL_COUNT					(0xFFFFu<<0)
#define	DTS_TSCSMPLCNTR_SMPL_COUNT_0				(0x1u<<0)

// TS0_IER Configuration

#define	DTS_TS0_IER_IRQ_EN_ALARMB					(0x1u<<4)
#define	DTS_TS0_IER_IRQ_EN_ALARMA					(0x1u<<3)
#define	DTS_TS0_IER_IRQ_EN_DONE						(0x1u<<1)
#define	DTS_TS0_IER_IRQ_EN_FAULT					(0x1u<<0)

// TS0_ISR Configuration

#define	DTS_TS0_ISR_IRQ_STATUS_ALARMB				(0x1u<<4)
#define	DTS_TS0_ISR_IRQ_STATUS_ALARMA				(0x1u<<3)
#define	DTS_TS0_ISR_IRQ_STATUS_DONE					(0x1u<<1)
#define	DTS_TS0_ISR_IRQ_STATUS_FAULT				(0x1u<<0)

// TS0_ICR Configuration

#define	DTS_TS0_ICR_IRQ_CLEAR_ALARMB				(0x1u<<4)
#define	DTS_TS0_ICR_IRQ_CLEAR_ALARMA				(0x1u<<3)
#define	DTS_TS0_ICR_IRQ_CLEAR_DONE					(0x1u<<1)
#define	DTS_TS0_ICR_IRQ_CLEAR_FAULT					(0x1u<<0)

// TS0IRQTESTR Configuration

#define	DTS_TS0IRQTESTR_IRQ_TEST_ALARMB				(0x1u<<4)
#define	DTS_TS0IRQTESTR_IRQ_TEST_ALARMA				(0x1u<<3)
#define	DTS_TS0IRQTESTR_IRQ_TEST_DONE				(0x1u<<1)
#define	DTS_TS0IRQTESTR_IRQ_TEST_FAULT				(0x1u<<0)

// TS0SDIFRDATAR Configuration

#define	DTS_TS0SDIFRDATAR_SDIF_RDATA				(0xFFFFFFu<<0)
#define	DTS_TS0SDIFRDATAR_SDIF_RDATA_0				(0x1u<<0)

// TS0SDIFDONER Configuration

#define	DTS_TS0SDIFDONER_SDIF_SMPL_DONE				(0x1u<<0)

#define	DTS_TS0SDIFDONER_SDIF_SMPL_DONE_B_0X0		(0x0u<<0)
#define	DTS_TS0SDIFDONER_SDIF_SMPL_DONE_B_0X1		(0x1u<<0)

// TS0SDIFDATAR Configuration

#define	DTS_TS0SDIFDATAR_SAMPLE_FAULT				(0x1u<<17)
#define	DTS_TS0SDIFDATAR_SAMPLE_TYPE				(0x1u<<16)
#define	DTS_TS0SDIFDATAR_SAMPLE_DATA				(0xFFFFu<<0)
#define	DTS_TS0SDIFDATAR_SAMPLE_DATA_0				(0x1u<<0)

#define	DTS_TS0SDIFDATAR_SAMPLE_TYPE_B_0X0			(0x0u<<16)
#define	DTS_TS0SDIFDATAR_SAMPLE_TYPE_B_0X1			(0x1u<<16)

// TS0ALARMA_CFGR Configuration

#define	DTS_TS0ALARMA_CFGR_ALARMA_THRESH			(0xFFFFu<<16)
#define	DTS_TS0ALARMA_CFGR_ALARMA_THRESH_0			(0x1u<<16)
#define	DTS_TS0ALARMA_CFGR_HYSTA_THRESH				(0xFFFFu<<0)
#define	DTS_TS0ALARMA_CFGR_HYSTA_THRESH_0			(0x1u<<0)

// TS0ALARMB_CFGR Configuration

#define	DTS_TS0ALARMB_CFGR_ALARMB_THRESH			(0xFFFFu<<16)
#define	DTS_TS0ALARMB_CFGR_ALARMB_THRESH_0			(0x1u<<16)
#define	DTS_TS0ALARMB_CFGR_HYSTB_THRESH				(0xFFFFu<<0)
#define	DTS_TS0ALARMB_CFGR_HYSTB_THRESH_0			(0x1u<<0)

// TS0HLSAMPLER Configuration

#define	DTS_TS0HLSAMPLER_SMPL_HI					(0xFFFFu<<16)
#define	DTS_TS0HLSAMPLER_SMPL_HI_0					(0x1u<<16)
#define	DTS_TS0HLSAMPLER_SMPL_LO					(0xFFFFu<<0)
#define	DTS_TS0HLSAMPLER_SMPL_LO_0					(0x1u<<0)

// TS0HILORESETR Configuration

#define	DTS_TS0HILORESETR_SMPL_HI_CLR				(0x1u<<1)
#define	DTS_TS0HILORESETR_SMPL_LO_SET				(0x1u<<0)

// TS1_IER Configuration

#define	DTS_TS1_IER_IRQ_EN_ALARMB					(0x1u<<4)
#define	DTS_TS1_IER_IRQ_EN_ALARMA					(0x1u<<3)
#define	DTS_TS1_IER_IRQ_EN_DONE						(0x1u<<1)
#define	DTS_TS1_IER_IRQ_EN_FAULT					(0x1u<<0)

// TS1_ISR Configuration

#define	DTS_TS1_ISR_IRQ_STATUS_ALARMB				(0x1u<<4)
#define	DTS_TS1_ISR_IRQ_STATUS_ALARMA				(0x1u<<3)
#define	DTS_TS1_ISR_IRQ_STATUS_DONE					(0x1u<<1)
#define	DTS_TS1_ISR_IRQ_STATUS_FAULT				(0x1u<<0)

// TS1_ICR Configuration

#define	DTS_TS1_ICR_IRQ_CLEAR_ALARMB				(0x1u<<4)
#define	DTS_TS1_ICR_IRQ_CLEAR_ALARMA				(0x1u<<3)
#define	DTS_TS1_ICR_IRQ_CLEAR_DONE					(0x1u<<1)
#define	DTS_TS1_ICR_IRQ_CLEAR_FAULT					(0x1u<<0)

// TS1IRQTESTR Configuration

#define	DTS_TS1IRQTESTR_IRQ_TEST_ALARMB				(0x1u<<4)
#define	DTS_TS1IRQTESTR_IRQ_TEST_ALARMA				(0x1u<<3)
#define	DTS_TS1IRQTESTR_IRQ_TEST_DONE				(0x1u<<1)
#define	DTS_TS1IRQTESTR_IRQ_TEST_FAULT				(0x1u<<0)

// TS1SDIFRDATAR Configuration

#define	DTS_TS1SDIFRDATAR_SDIF_RDATA				(0xFFFFFFu<<0)
#define	DTS_TS1SDIFRDATAR_SDIF_RDATA_0				(0x1u<<0)

// TS1SDIFDONER Configuration

#define	DTS_TS1SDIFDONER_SDIF_SMPL_DONE				(0x1u<<0)

#define	DTS_TS1SDIFDONER_SDIF_SMPL_DONE_B_0X0		(0x0u<<0)
#define	DTS_TS1SDIFDONER_SDIF_SMPL_DONE_B_0X1		(0x1u<<0)

// TS1SDIFDATAR Configuration

#define	DTS_TS1SDIFDATAR_SAMPLE_FAULT				(0x1u<<17)
#define	DTS_TS1SDIFDATAR_SAMPLE_TYPE				(0x1u<<16)
#define	DTS_TS1SDIFDATAR_SAMPLE_DATA				(0xFFFFu<<0)
#define	DTS_TS1SDIFDATAR_SAMPLE_DATA_0				(0x1u<<0)

#define	DTS_TS1SDIFDATAR_SAMPLE_TYPE_B_0X0			(0x0u<<16)
#define	DTS_TS1SDIFDATAR_SAMPLE_TYPE_B_0X1			(0x1u<<16)

// TS1ALARMA_CFGR Configuration

#define	DTS_TS1ALARMA_CFGR_ALARMA_THRESH			(0xFFFFu<<16)
#define	DTS_TS1ALARMA_CFGR_ALARMA_THRESH_0			(0x1u<<16)
#define	DTS_TS1ALARMA_CFGR_HYSTA_THRESH				(0xFFFFu<<0)
#define	DTS_TS1ALARMA_CFGR_HYSTA_THRESH_0			(0x1u<<0)

// TS1ALARMB_CFGR Configuration

#define	DTS_TS1ALARMB_CFGR_ALARMB_THRESH			(0xFFFFu<<16)
#define	DTS_TS1ALARMB_CFGR_ALARMB_THRESH_0			(0x1u<<16)
#define	DTS_TS1ALARMB_CFGR_HYSTB_THRESH				(0xFFFFu<<0)
#define	DTS_TS1ALARMB_CFGR_HYSTB_THRESH_0			(0x1u<<0)

// TS1HLSAMPLER Configuration

#define	DTS_TS1HLSAMPLER_SMPL_HI					(0xFFFFu<<16)
#define	DTS_TS1HLSAMPLER_SMPL_HI_0					(0x1u<<16)
#define	DTS_TS1HLSAMPLER_SMPL_LO					(0xFFFFu<<0)
#define	DTS_TS1HLSAMPLER_SMPL_LO_0					(0x1u<<0)

// TS1HILORESETR Configuration

#define	DTS_TS1HILORESETR_SMPL_HI_CLR				(0x1u<<1)
#define	DTS_TS1HILORESETR_SMPL_LO_SET				(0x1u<<0)
