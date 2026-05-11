/*
; PF1550.
; =======

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		NXP PF1550 equates.
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

// I2c interface

#define	KI2C_ADD_PF1550						0x08u							// I2C PF1550 address

// PF1550 initialisation table

typedef	struct	pf1550	pf1550_t;

struct	pf1550 {
			uint8_t		oRegister;											// I2C register
			uint8_t		oData;												// I2C data
			uint32_t	oDelay;												// Delay
		};

#define	KPF1550_NB_MONO						2u								//

// I2c interface


// PF1550 registers

#define	PF1550_DEVICE_ID					0x00u							//
#define	PF1550_OTP_FLAVOR					0x01u							//
#define	PF1550_SILICON_REV					0x02u							//
#define	PF1550_INT_CATEGORY					0x06u							//
#define	PF1550_SW_INT_STAT0					0x08u							//
#define	PF1550_SW_INT_MASK0					0x09u							//
#define	PF1550_SW_INT_SENSE0				0x0Au							//
#define	PF1550_SW_INT_STAT1					0x0Bu							//
#define	PF1550_SW_INT_MASK1					0x0Cu							//
#define	PF1550_SW_INT_SENSE1				0x0Du							//
#define	PF1550_SW_INT_STAT2					0x0Eu							//
#define	PF1550_SW_INT_MASK2					0x0Fu							//
#define	PF1550_SW_INT_SENSE2				0x10u							//
#define	PF1550_LDO_INT_STAT0				0x18u							//
#define	PF1550_LDO_INT_MASK0				0x19u							//
#define	PF1550_LDO_INT_SENSE0				0x1Au							//
#define	PF1550_TEMP_INT_STAT0				0x20u							//
#define	PF1550_TEMP_INT_MASK0				0x21u							//
#define	PF1550_TEMP_INT_SENSE0				0x22u							//
#define	PF1550_ONKEY_INT_STAT0				0x24u							//
#define	PF1550_ONKEY_INT_MASK0				0x25u							//
#define	PF1550_ONKEY_INT_SENSE0				0x26u							//
#define	PF1550_MISC_INT_STAT0				0x28u							//
#define	PF1550_MISC_INT_MASK0				0x29u							//
#define	PF1550_MISC_INT_SENSE0				0x2Au							//
#define	PF1550_COINCELL_CONTROL				0x30u							//
#define	PF1550_SW1_VOLT						0x32u							//
#define	PF1550_SW1_STBY_VOLT				0x33u							//
#define	PF1550_SW1_SLP_VOLT					0x34u							//
#define	PF1550_SW1_CTRL						0x35u							//
#define	PF1550_SW1_CTRL1					0x36u							//
#define	PF1550_SW2_VOLT						0x38u							//
#define	PF1550_SW2_STBY_VOLT				0x39u							//
#define	PF1550_SW2_SLP_VOLT					0x3Au							//
#define	PF1550_SW2_CTRL						0x3Bu							//
#define	PF1550_SW2_CTRL1					0x3Cu							//
#define	PF1550_SW3_VOLT						0x3Eu							//
#define	PF1550_SW3_STBY_VOLT				0x3Fu							//
#define	PF1550_SW3_SLP_VOLT					0x40u							//
#define	PF1550_SW3_CTRL						0x41u							//
#define	PF1550_SW3_CTRL1					0x42u							//
#define	PF1550_VSNVS_CTRL					0x48u							//
#define	PF1550_VREFDDR_CTRL					0x4Au							//
#define	PF1550_LDO1_VOLT					0x4Cu							//
#define	PF1550_LDO1_CTRL					0x4Du							//
#define	PF1550_LDO2_VOLT					0x4Fu							//
#define	PF1550_LDO2_CTRL					0x50u							//
#define	PF1550_LDO3_VOLT					0x52u							//
#define	PF1550_LDO3_CTRL					0x53u							//
#define	PF1550_PWRCTRL0						0x58u							//
#define	PF1550_PWRCTRL1						0x59u							//
#define	PF1550_PWRCTRL2						0x5Au							//
#define	PF1550_PWRCTRL3						0x5Bu							//
#define	PF1550_SW1_PWRDN_SEQ				0x5Fu							//
#define	PF1550_SW2_PWRDN_SEQ				0x60u							//
#define	PF1550_LDO1_PWRDN_SEQ				0x62u							//
#define	PF1550_LDO2_PWRDN_SEQ				0x63u							//
#define	PF1550_LDO3_PWRDN_SEQ				0x64u							//
#define	PF1550_VREFDDR_PWRDN_SEQ			0x65u							//
#define	PF1550_STATE_INFO					0x67u							//
#define	PF1550_I2C_ADDR						0x68u							//
#define	PF1550_RC_16MHZ						0x6Bu							//
#define	PF1550_KEY1							0x6Bu							//
#define	PF1550_CHG_INT						(0x80u + 0x00u)					//
#define	PF1550_CHG_INT_MASK					(0x80u + 0x02u)					//
#define	PF1550_CHG_INT_OK					(0x80u + 0x04u)					//
#define	PF1550_VBUS_SNS						(0x80u + 0x06u)					//
#define	PF1550_CHG_SNS						(0x80u + 0x07u)					//
#define	PF1550_BATT_SNS						(0x80u + 0x08u)					//
#define	PF1550_CHG_OPER						(0x80u + 0x09u)					//
#define	PF1550_CHG_TMR						(0x80u + 0x0Au)					//
#define	PF1550_CHG_EOC_CNFG					(0x80u + 0x0Du)					//
#define	PF1550_CHG_CURR_CNFG				(0x80u + 0x0Eu)					//
#define	PF1550_BATT_REG						(0x80u + 0x0Fu)					//
#define	PF1550_BATFET_CNFG					(0x80u + 0x11u)					//
#define	PF1550_THM_REG_CNFG					(0x80u + 0x12u)					//
#define	PF1550_VBUS_INLIM_CNFG				(0x80u + 0x14u)					//
#define	PF1550_VBUS_LIN_DPM					(0x80u + 0x15u)					//
#define	PF1550_USB_PHY_LDO_CNFG				(0x80u + 0x16u)					//
#define	PF1550_DBNC_DELAY_TIME				(0x80u + 0x18u)					//
#define	PF1550_CHG_INT_CNFG					(0x80u + 0x19u)					//
#define	PF1550_THM_ADJ_SETTING				(0x80u + 0x1Au)					//
#define	PF1550_VBUS2SYS_CNFG				(0x80u + 0x1Bu)					//
#define	PF1550_LED_PWM						(0x80u + 0x1Cu)					//
#define	PF1550_FAULT_BATFET_CNFG			(0x80u + 0x1Du)					//
#define	PF1550_LED_CNFG						(0x80u + 0x1Eu)					//
#define	PF1550_LED_CNFG2					(0x80u + 0x1Fu)					//
