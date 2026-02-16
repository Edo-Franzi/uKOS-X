/*
; RP2350_powman.
; ==============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_powman equates.
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

// POWMAN address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	BADPASSWD;
	volatile	uint32_t	VREG_CTRL;
	volatile	uint32_t	VREG_STS;
	volatile	uint32_t	VREG;
	volatile	uint32_t	VREG_LP_ENTRY;
	volatile	uint32_t	VREG_LP_EXIT;
	volatile	uint32_t	BOD_CTRL;
	volatile	uint32_t	BOD;
	volatile	uint32_t	BOD_LP_ENTRY;
	volatile	uint32_t	BOD_LP_EXIT;
	volatile	uint32_t	LPOSC;
	volatile	uint32_t	CHIP_RESET;
	volatile	uint32_t	WDSEL;
	volatile	uint32_t	SEQ_CFG;
	volatile	uint32_t	STATE;
	volatile	uint32_t	POW_FASTDIV;
	volatile	uint32_t	POW_DELAY;
	volatile	uint32_t	EXT_CTRL0;
	volatile	uint32_t	EXT_CTRL1;
	volatile	uint32_t	EXT_TIME_REF;
	volatile	uint32_t	LPOSC_FREQ_KHZ_INT;
	volatile	uint32_t	LPOSC_FREQ_KHZ_FRAC;
	volatile	uint32_t	XOSC_FREQ_KHZ_INT;
	volatile	uint32_t	XOSC_FREQ_KHZ_FRAC;
	volatile	uint32_t	SET_TIME_63TO48;
	volatile	uint32_t	SET_TIME_47TO32;
	volatile	uint32_t	SET_TIME_31TO16;
	volatile	uint32_t	SET_TIME_15TO0;
	volatile	uint32_t	READ_TIME_UPPER;
	volatile	uint32_t	READ_TIME_LOWER;
	volatile	uint32_t	ALARM_TIME_63TO48;
	volatile	uint32_t	ALARM_TIME_47TO32;
	volatile	uint32_t	ALARM_TIME_31TO16;
	volatile	uint32_t	ALARM_TIME_15TO0;
	volatile	uint32_t	TIMER;
	volatile	uint32_t	PWRUP0;
	volatile	uint32_t	PWRUP1;
	volatile	uint32_t	PWRUP2;
	volatile	uint32_t	PWRUP3;
	volatile	uint32_t	CURRENT_PWRUP_REQ;
	volatile	uint32_t	LAST_SWCORE_PWRUP;
	volatile	uint32_t	DBG_PWRCFG;
	volatile	uint32_t	BOOTDIS;
	volatile	uint32_t	DBGCONFIG;
	volatile	uint32_t	SCRATCH0;
	volatile	uint32_t	SCRATCH1;
	volatile	uint32_t	SCRATCH2;
	volatile	uint32_t	SCRATCH3;
	volatile	uint32_t	SCRATCH4;
	volatile	uint32_t	SCRATCH5;
	volatile	uint32_t	SCRATCH6;
	volatile	uint32_t	SCRATCH7;
	volatile	uint32_t	BOOT0;
	volatile	uint32_t	BOOT1;
	volatile	uint32_t	BOOT2;
	volatile	uint32_t	BOOT3;
	volatile	uint32_t	INTR;
	volatile	uint32_t	INTE;
	volatile	uint32_t	INTF;
	volatile	uint32_t	INTS;
} POWMAN_TypeDef;

#ifdef __cplusplus
#define	POWMAN_NS	reinterpret_cast<POWMAN_TypeDef *>(0x40100000u)
#define	POWMAN_S	reinterpret_cast<POWMAN_TypeDef *>(0x40100000u)
#else
#define	POWMAN_NS	((POWMAN_TypeDef *)0x40100000u)
#define	POWMAN_S	((POWMAN_TypeDef *)0x40100000u)
#endif

// BADPASSWD Configuration

#define	POWMAN_BADPASSWD_BADPASSWD							(0x1u<<0)

// VREG_CTRL Configuration

#define	POWMAN_VREG_CTRL_HT_TH								(0x7u<<4)
#define	POWMAN_VREG_CTRL_HT_TH_0							(0x1u<<4)
#define	POWMAN_VREG_CTRL_DISABLE_VOLTAGE_LIMIT				(0x1u<<8)
#define	POWMAN_VREG_CTRL_ISOLATE							(0x1u<<12)
#define	POWMAN_VREG_CTRL_UNLOCK								(0x1u<<13)
#define	POWMAN_VREG_CTRL_RST_N								(0x1u<<15)

// VREG_STS Configuration

#define	POWMAN_VREG_STS_STARTUP								(0x1u<<0)
#define	POWMAN_VREG_STS_VOUT_OK								(0x1u<<4)

// VREG Configuration

#define	POWMAN_VREG_HIZ										(0x1u<<1)
#define	POWMAN_VREG_VSEL									(0x1Fu<<4)
#define	POWMAN_VREG_VSEL_0									(0x1u<<4)
#define	POWMAN_VREG_UPDATE_IN_PROGRESS						(0x1u<<15)

// VREG_LP_ENTRY Configuration

#define	POWMAN_VREG_LP_ENTRY_HIZ							(0x1u<<1)
#define	POWMAN_VREG_LP_ENTRY_MODE							(0x1u<<2)
#define	POWMAN_VREG_LP_ENTRY_VSEL							(0x1Fu<<4)
#define	POWMAN_VREG_LP_ENTRY_VSEL_0							(0x1u<<4)

// VREG_LP_EXIT Configuration

#define	POWMAN_VREG_LP_EXIT_HIZ								(0x1u<<1)
#define	POWMAN_VREG_LP_EXIT_MODE							(0x1u<<2)
#define	POWMAN_VREG_LP_EXIT_VSEL							(0x1Fu<<4)
#define	POWMAN_VREG_LP_EXIT_VSEL_0							(0x1u<<4)

// BOD_CTRL Configuration

#define	POWMAN_BOD_CTRL_ISOLATE								(0x1u<<12)

// BOD Configuration

#define	POWMAN_BOD_EN										(0x1u<<0)
#define	POWMAN_BOD_VSEL										(0x1Fu<<4)
#define	POWMAN_BOD_VSEL_0									(0x1u<<4)

// BOD_LP_ENTRY Configuration

#define	POWMAN_BOD_LP_ENTRY_EN								(0x1u<<0)
#define	POWMAN_BOD_LP_ENTRY_VSEL							(0x1Fu<<4)
#define	POWMAN_BOD_LP_ENTRY_VSEL_0							(0x1u<<4)

// BOD_LP_EXIT Configuration

#define	POWMAN_BOD_LP_EXIT_EN								(0x1u<<0)
#define	POWMAN_BOD_LP_EXIT_VSEL								(0x1Fu<<4)
#define	POWMAN_BOD_LP_EXIT_VSEL_0							(0x1u<<4)

// LPOSC Configuration

#define	POWMAN_LPOSC_MODE									(0x3u<<0)
#define	POWMAN_LPOSC_MODE_0									(0x1u<<0)
#define	POWMAN_LPOSC_TRIM									(0x3Fu<<4)
#define	POWMAN_LPOSC_TRIM_0									(0x1u<<4)

// CHIP_RESET Configuration

#define	POWMAN_CHIP_RESET_DOUBLE_TAP						(0x1u<<0)
#define	POWMAN_CHIP_RESET_RESCUE_FLAG						(0x1u<<4)
#define	POWMAN_CHIP_RESET_HAD_POR							(0x1u<<16)
#define	POWMAN_CHIP_RESET_HAD_BOR							(0x1u<<17)
#define	POWMAN_CHIP_RESET_HAD_RUN_LOW						(0x1u<<18)
#define	POWMAN_CHIP_RESET_HAD_DP_RESET_REQ					(0x1u<<19)
#define	POWMAN_CHIP_RESET_HAD_RESCUE						(0x1u<<21)
#define	POWMAN_CHIP_RESET_HAD_WATCHDOG_RESET_POWMAN_ASYNC	(0x1u<<22)
#define	POWMAN_CHIP_RESET_HAD_WATCHDOG_RESET_POWMAN			(0x1u<<23)
#define	POWMAN_CHIP_RESET_HAD_WATCHDOG_RESET_SWCORE			(0x1u<<24)
#define	POWMAN_CHIP_RESET_HAD_SWCORE_PD						(0x1u<<25)
#define	POWMAN_CHIP_RESET_HAD_GLITCH_DETECT					(0x1u<<26)
#define	POWMAN_CHIP_RESET_HAD_HZD_SYS_RESET_REQ				(0x1u<<27)
#define	POWMAN_CHIP_RESET_HAD_WATCHDOG_RESET_RSM			(0x1u<<28)

// WDSEL Configuration

#define	POWMAN_WDSEL_RESET_POWMAN_ASYNC						(0x1u<<0)
#define	POWMAN_WDSEL_RESET_POWMAN							(0x1u<<4)
#define	POWMAN_WDSEL_RESET_SWCORE							(0x1u<<8)
#define	POWMAN_WDSEL_RESET_RSM								(0x1u<<12)

// SEQ_CFG Configuration

#define	POWMAN_SEQ_CFG_HW_PWRUP_SRAM1						(0x1u<<0)
#define	POWMAN_SEQ_CFG_HW_PWRUP_SRAM0						(0x1u<<1)
#define	POWMAN_SEQ_CFG_USE_VREG_LP							(0x1u<<4)
#define	POWMAN_SEQ_CFG_USE_VREG_HP							(0x1u<<5)
#define	POWMAN_SEQ_CFG_USE_BOD_LP							(0x1u<<6)
#define	POWMAN_SEQ_CFG_USE_BOD_HP							(0x1u<<7)
#define	POWMAN_SEQ_CFG_RUN_LPOSC_IN_LP						(0x1u<<8)
#define	POWMAN_SEQ_CFG_USE_FAST_POWCK						(0x1u<<12)
#define	POWMAN_SEQ_CFG_USING_VREG_LP						(0x1u<<16)
#define	POWMAN_SEQ_CFG_USING_BOD_LP							(0x1u<<17)
#define	POWMAN_SEQ_CFG_USING_FAST_POWCK						(0x1u<<20)

// STATE Configuration

#define	POWMAN_STATE_CURRENT								(0xFu<<0)
#define	POWMAN_STATE_CURRENT_0								(0x1u<<0)
#define	POWMAN_STATE_REQ									(0xFu<<4)
#define	POWMAN_STATE_REQ_0									(0x1u<<4)
#define	POWMAN_STATE_REQ_IGNORED							(0x1u<<8)
#define	POWMAN_STATE_PWRUP_WHILE_WAITING					(0x1u<<9)
#define	POWMAN_STATE_BAD_SW_REQ								(0x1u<<10)
#define	POWMAN_STATE_BAD_HW_REQ								(0x1u<<11)
#define	POWMAN_STATE_WAITING								(0x1u<<12)
#define	POWMAN_STATE_CHANGING								(0x1u<<13)

// POW_FASTDIV Configuration

#define	POWMAN_POW_FASTDIV_POW_FASTDIV						(0x7FFu<<0)
#define	POWMAN_POW_FASTDIV_POW_FASTDIV_0					(0x1u<<0)

// POW_DELAY Configuration

#define	POWMAN_POW_DELAY_SWCORE_STEP						(0xFu<<0)
#define	POWMAN_POW_DELAY_SWCORE_STEP_0						(0x1u<<0)
#define	POWMAN_POW_DELAY_XIP_STEP							(0xFu<<4)
#define	POWMAN_POW_DELAY_XIP_STEP_0							(0x1u<<4)
#define	POWMAN_POW_DELAY_SRAM_STEP							(0xFFu<<8)
#define	POWMAN_POW_DELAY_SRAM_STEP_0						(0x1u<<8)

// EXT_CTRL0 Configuration

#define	POWMAN_EXT_CTRL0_GPIO_SELECT						(0x3Fu<<0)
#define	POWMAN_EXT_CTRL0_GPIO_SELECT_0						(0x1u<<0)
#define	POWMAN_EXT_CTRL0_INIT								(0x1u<<8)
#define	POWMAN_EXT_CTRL0_INIT_STATE							(0x1u<<12)
#define	POWMAN_EXT_CTRL0_LP_ENTRY_STATE						(0x1u<<13)
#define	POWMAN_EXT_CTRL0_LP_EXIT_STATE						(0x1u<<14)

// EXT_CTRL1 Configuration

#define	POWMAN_EXT_CTRL1_GPIO_SELECT						(0x3Fu<<0)
#define	POWMAN_EXT_CTRL1_GPIO_SELECT_0						(0x1u<<0)
#define	POWMAN_EXT_CTRL1_INIT								(0x1u<<8)
#define	POWMAN_EXT_CTRL1_INIT_STATE							(0x1u<<12)
#define	POWMAN_EXT_CTRL1_LP_ENTRY_STATE						(0x1u<<13)
#define	POWMAN_EXT_CTRL1_LP_EXIT_STATE						(0x1u<<14)

// EXT_TIME_REF Configuration

#define	POWMAN_EXT_TIME_REF_SOURCE_SEL						(0x3u<<0)
#define	POWMAN_EXT_TIME_REF_SOURCE_SEL_0					(0x1u<<0)
#define	POWMAN_EXT_TIME_REF_DRIVE_LPCK						(0x1u<<4)

// LPOSC_FREQ_KHZ_INT Configuration

#define	POWMAN_LPOSC_FREQ_KHZ_INT_LPOSC_FREQ_KHZ_INT		(0x3Fu<<0)
#define	POWMAN_LPOSC_FREQ_KHZ_INT_LPOSC_FREQ_KHZ_INT_0		(0x1u<<0)

// LPOSC_FREQ_KHZ_FRAC Configuration

#define	POWMAN_LPOSC_FREQ_KHZ_FRAC_LPOSC_FREQ_KHZ_FRAC		(0xFFFFu<<0)
#define	POWMAN_LPOSC_FREQ_KHZ_FRAC_LPOSC_FREQ_KHZ_FRAC_0	(0x1u<<0)

// XOSC_FREQ_KHZ_INT Configuration

#define	POWMAN_XOSC_FREQ_KHZ_INT_XOSC_FREQ_KHZ_INT			(0xFFFFu<<0)
#define	POWMAN_XOSC_FREQ_KHZ_INT_XOSC_FREQ_KHZ_INT_0		(0x1u<<0)

// XOSC_FREQ_KHZ_FRAC Configuration

#define	POWMAN_XOSC_FREQ_KHZ_FRAC_XOSC_FREQ_KHZ_FRAC		(0xFFFFu<<0)
#define	POWMAN_XOSC_FREQ_KHZ_FRAC_XOSC_FREQ_KHZ_FRAC_0		(0x1u<<0)

// SET_TIME_63TO48 Configuration

#define	POWMAN_SET_TIME_63TO48_SET_TIME_63TO48				(0xFFFFu<<0)
#define	POWMAN_SET_TIME_63TO48_SET_TIME_63TO48_0			(0x1u<<0)

// SET_TIME_47TO32 Configuration

#define	POWMAN_SET_TIME_47TO32_SET_TIME_47TO32				(0xFFFFu<<0)
#define	POWMAN_SET_TIME_47TO32_SET_TIME_47TO32_0			(0x1u<<0)

// SET_TIME_31TO16 Configuration

#define	POWMAN_SET_TIME_31TO16_SET_TIME_31TO16				(0xFFFFu<<0)
#define	POWMAN_SET_TIME_31TO16_SET_TIME_31TO16_0			(0x1u<<0)

// SET_TIME_15TO0 Configuration

#define	POWMAN_SET_TIME_15TO0_SET_TIME_15TO0				(0xFFFFu<<0)
#define	POWMAN_SET_TIME_15TO0_SET_TIME_15TO0_0				(0x1u<<0)

// READ_TIME_UPPER Configuration

#define	POWMAN_READ_TIME_UPPER_READ_TIME_UPPER				(0xFFFFFFFFu<<0)
#define	POWMAN_READ_TIME_UPPER_READ_TIME_UPPER_0			(0x1u<<0)

// READ_TIME_LOWER Configuration

#define	POWMAN_READ_TIME_LOWER_READ_TIME_LOWER				(0xFFFFFFFFu<<0)
#define	POWMAN_READ_TIME_LOWER_READ_TIME_LOWER_0			(0x1u<<0)

// ALARM_TIME_63TO48 Configuration

#define	POWMAN_ALARM_TIME_63TO48_ALARM_TIME_63TO48			(0xFFFFu<<0)
#define	POWMAN_ALARM_TIME_63TO48_ALARM_TIME_63TO48_0		(0x1u<<0)

// ALARM_TIME_47TO32 Configuration

#define	POWMAN_ALARM_TIME_47TO32_ALARM_TIME_47TO32			(0xFFFFu<<0)
#define	POWMAN_ALARM_TIME_47TO32_ALARM_TIME_47TO32_0		(0x1u<<0)

// ALARM_TIME_31TO16 Configuration

#define	POWMAN_ALARM_TIME_31TO16_ALARM_TIME_31TO16			(0xFFFFu<<0)
#define	POWMAN_ALARM_TIME_31TO16_ALARM_TIME_31TO16_0		(0x1u<<0)

// ALARM_TIME_15TO0 Configuration

#define	POWMAN_ALARM_TIME_15TO0_ALARM_TIME_15TO0			(0xFFFFu<<0)
#define	POWMAN_ALARM_TIME_15TO0_ALARM_TIME_15TO0_0			(0x1u<<0)

// TIMER Configuration

#define	POWMAN_TIMER_NONSEC_WRITE							(0x1u<<0)
#define	POWMAN_TIMER_RUN									(0x1u<<1)
#define	POWMAN_TIMER_CLEAR									(0x1u<<2)
#define	POWMAN_TIMER_ALARM_ENAB								(0x1u<<4)
#define	POWMAN_TIMER_PWRUP_ON_ALARM							(0x1u<<5)
#define	POWMAN_TIMER_ALARM									(0x1u<<6)
#define	POWMAN_TIMER_USE_LPOSC								(0x1u<<8)
#define	POWMAN_TIMER_USE_XOSC								(0x1u<<9)
#define	POWMAN_TIMER_USE_GPIO_1KHZ							(0x1u<<10)
#define	POWMAN_TIMER_USE_GPIO_1HZ							(0x1u<<13)
#define	POWMAN_TIMER_USING_XOSC								(0x1u<<16)
#define	POWMAN_TIMER_USING_LPOSC							(0x1u<<17)
#define	POWMAN_TIMER_USING_GPIO_1KHZ						(0x1u<<18)
#define	POWMAN_TIMER_USING_GPIO_1HZ							(0x1u<<19)

// PWRUP0 Configuration

#define	POWMAN_PWRUP0_SOURCE								(0x3Fu<<0)
#define	POWMAN_PWRUP0_SOURCE_0								(0x1u<<0)
#define	POWMAN_PWRUP0_ENABLE								(0x1u<<6)
#define	POWMAN_PWRUP0_DIRECTION								(0x1u<<7)
#define	POWMAN_PWRUP0_MODE									(0x1u<<8)
#define	POWMAN_PWRUP0_STATUS								(0x1u<<9)
#define	POWMAN_PWRUP0_RAW_STATUS							(0x1u<<10)
#define	POWMAN_PWRUP0_DIRECTION_LOW_FALLING					(0x0u<<7)
#define	POWMAN_PWRUP0_DIRECTION_HIGH_RISING					(0x1u<<7)
#define	POWMAN_PWRUP0_MODE_LEVEL							(0x0u<<8)
#define	POWMAN_PWRUP0_MODE_EDGE								(0x1u<<8)

// PWRUP1 Configuration

#define	POWMAN_PWRUP1_SOURCE								(0x3Fu<<0)
#define	POWMAN_PWRUP1_SOURCE_0								(0x1u<<0)
#define	POWMAN_PWRUP1_ENABLE								(0x1u<<6)
#define	POWMAN_PWRUP1_DIRECTION								(0x1u<<7)
#define	POWMAN_PWRUP1_MODE									(0x1u<<8)
#define	POWMAN_PWRUP1_STATUS								(0x1u<<9)
#define	POWMAN_PWRUP1_RAW_STATUS							(0x1u<<10)
#define	POWMAN_PWRUP1_DIRECTION_LOW_FALLING					(0x0u<<7)
#define	POWMAN_PWRUP1_DIRECTION_HIGH_RISING					(0x1u<<7)
#define	POWMAN_PWRUP1_MODE_LEVEL							(0x0u<<8)
#define	POWMAN_PWRUP1_MODE_EDGE								(0x1u<<8)

// PWRUP2 Configuration

#define	POWMAN_PWRUP2_SOURCE								(0x3Fu<<0)
#define	POWMAN_PWRUP2_SOURCE_0								(0x1u<<0)
#define	POWMAN_PWRUP2_ENABLE								(0x1u<<6)
#define	POWMAN_PWRUP2_DIRECTION								(0x1u<<7)
#define	POWMAN_PWRUP2_MODE									(0x1u<<8)
#define	POWMAN_PWRUP2_STATUS								(0x1u<<9)
#define	POWMAN_PWRUP2_RAW_STATUS							(0x1u<<10)
#define	POWMAN_PWRUP2_DIRECTION_LOW_FALLING					(0x0u<<7)
#define	POWMAN_PWRUP2_DIRECTION_HIGH_RISING					(0x1u<<7)
#define	POWMAN_PWRUP2_MODE_LEVEL							(0x0u<<8)
#define	POWMAN_PWRUP2_MODE_EDGE								(0x1u<<8)

// PWRUP3 Configuration

#define	POWMAN_PWRUP3_SOURCE								(0x3Fu<<0)
#define	POWMAN_PWRUP3_SOURCE_0								(0x1u<<0)
#define	POWMAN_PWRUP3_ENABLE								(0x1u<<6)
#define	POWMAN_PWRUP3_DIRECTION								(0x1u<<7)
#define	POWMAN_PWRUP3_MODE									(0x1u<<8)
#define	POWMAN_PWRUP3_STATUS								(0x1u<<9)
#define	POWMAN_PWRUP3_RAW_STATUS							(0x1u<<10)
#define	POWMAN_PWRUP3_DIRECTION_LOW_FALLING					(0x0u<<7)
#define	POWMAN_PWRUP3_DIRECTION_HIGH_RISING					(0x1u<<7)
#define	POWMAN_PWRUP3_MODE_LEVEL							(0x0u<<8)
#define	POWMAN_PWRUP3_MODE_EDGE								(0x1u<<8)

// CURRENT_PWRUP_REQ Configuration

#define	POWMAN_CURRENT_PWRUP_REQ_CURRENT_PWRUP_REQ			(0x7Fu<<0)
#define	POWMAN_CURRENT_PWRUP_REQ_CURRENT_PWRUP_REQ_0		(0x1u<<0)

// LAST_SWCORE_PWRUP Configuration

#define	POWMAN_LAST_SWCORE_PWRUP_LAST_SWCORE_PWRUP			(0x7Fu<<0)
#define	POWMAN_LAST_SWCORE_PWRUP_LAST_SWCORE_PWRUP_0		(0x1u<<0)

// DBG_PWRCFG Configuration

#define	POWMAN_DBG_PWRCFG_IGNORE							(0x1u<<0)

// BOOTDIS Configuration

#define	POWMAN_BOOTDIS_NOW									(0x1u<<0)
#define	POWMAN_BOOTDIS_NEXT									(0x1u<<1)

// DBGCONFIG Configuration

#define	POWMAN_DBGCONFIG_DP_INSTID							(0xFu<<0)
#define	POWMAN_DBGCONFIG_DP_INSTID_0						(0x1u<<0)

// SCRATCH0 Configuration

#define	POWMAN_SCRATCH0_SCRATCH0							(0xFFFFFFFFu<<0)
#define	POWMAN_SCRATCH0_SCRATCH0_0							(0x1u<<0)

// SCRATCH1 Configuration

#define	POWMAN_SCRATCH1_SCRATCH1							(0xFFFFFFFFu<<0)
#define	POWMAN_SCRATCH1_SCRATCH1_0							(0x1u<<0)

// SCRATCH2 Configuration

#define	POWMAN_SCRATCH2_SCRATCH2							(0xFFFFFFFFu<<0)
#define	POWMAN_SCRATCH2_SCRATCH2_0							(0x1u<<0)

// SCRATCH3 Configuration

#define	POWMAN_SCRATCH3_SCRATCH3							(0xFFFFFFFFu<<0)
#define	POWMAN_SCRATCH3_SCRATCH3_0							(0x1u<<0)

// SCRATCH4 Configuration

#define	POWMAN_SCRATCH4_SCRATCH4							(0xFFFFFFFFu<<0)
#define	POWMAN_SCRATCH4_SCRATCH4_0							(0x1u<<0)

// SCRATCH5 Configuration

#define	POWMAN_SCRATCH5_SCRATCH5							(0xFFFFFFFFu<<0)
#define	POWMAN_SCRATCH5_SCRATCH5_0							(0x1u<<0)

// SCRATCH6 Configuration

#define	POWMAN_SCRATCH6_SCRATCH6							(0xFFFFFFFFu<<0)
#define	POWMAN_SCRATCH6_SCRATCH6_0							(0x1u<<0)

// SCRATCH7 Configuration

#define	POWMAN_SCRATCH7_SCRATCH7							(0xFFFFFFFFu<<0)
#define	POWMAN_SCRATCH7_SCRATCH7_0							(0x1u<<0)

// BOOT0 Configuration

#define	POWMAN_BOOT0_BOOT0									(0xFFFFFFFFu<<0)
#define	POWMAN_BOOT0_BOOT0_0								(0x1u<<0)

// BOOT1 Configuration

#define	POWMAN_BOOT1_BOOT1									(0xFFFFFFFFu<<0)
#define	POWMAN_BOOT1_BOOT1_0								(0x1u<<0)

// BOOT2 Configuration

#define	POWMAN_BOOT2_BOOT2									(0xFFFFFFFFu<<0)
#define	POWMAN_BOOT2_BOOT2_0								(0x1u<<0)

// BOOT3 Configuration

#define	POWMAN_BOOT3_BOOT3									(0xFFFFFFFFu<<0)
#define	POWMAN_BOOT3_BOOT3_0								(0x1u<<0)

// INTR Configuration

#define	POWMAN_INTR_VREG_OUTPUT_LOW							(0x1u<<0)
#define	POWMAN_INTR_TIMER									(0x1u<<1)
#define	POWMAN_INTR_STATE_REQ_IGNORED						(0x1u<<2)
#define	POWMAN_INTR_PWRUP_WHILE_WAITING						(0x1u<<3)

// INTE Configuration

#define	POWMAN_INTE_VREG_OUTPUT_LOW							(0x1u<<0)
#define	POWMAN_INTE_TIMER									(0x1u<<1)
#define	POWMAN_INTE_STATE_REQ_IGNORED						(0x1u<<2)
#define	POWMAN_INTE_PWRUP_WHILE_WAITING						(0x1u<<3)

// INTF Configuration

#define	POWMAN_INTF_VREG_OUTPUT_LOW							(0x1u<<0)
#define	POWMAN_INTF_TIMER									(0x1u<<1)
#define	POWMAN_INTF_STATE_REQ_IGNORED						(0x1u<<2)
#define	POWMAN_INTF_PWRUP_WHILE_WAITING						(0x1u<<3)

// INTS Configuration

#define	POWMAN_INTS_VREG_OUTPUT_LOW							(0x1u<<0)
#define	POWMAN_INTS_TIMER									(0x1u<<1)
#define	POWMAN_INTS_STATE_REQ_IGNORED						(0x1u<<2)
#define	POWMAN_INTS_PWRUP_WHILE_WAITING						(0x1u<<3)
