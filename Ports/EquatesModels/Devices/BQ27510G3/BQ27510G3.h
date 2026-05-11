/*
; BQ27510G3.
; ==========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		TI BQ27510G3 equates.
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

#define	KI2C_ADD_BQ27510G3					0x55u							// I2C BQ27510G3 address

// Registers & subcommands

#define	BQ27510G3_CNTRL						0x0001u							// Control register
#define	BQ27510G3_STATUS					0x0000u							// Reports the status of DF Checksum, Hibernate, IT, etc.
#define	BQEN								0u								// Status bit indicating the bq27510 Qmax updates enabled. True when set
#define	BVOK								1u								// Status bit indicating cell voltages are OK for Qmax updates. True when set
#define	BRUP_DIS							2u								// Status bit indicating the bq27510 Ra table updates disabled. True when set
#define	BLDMD								3u								// Status bit indicating the bq27510 Impedance TrackTM algorithm using constant-power mode. True when set. Default is 0 (constant-current mode)
#define	BSLEEP								4u								// Status bit indicating the bq27510 is in SLEEP mode. True when set
#define	BHYBERNATE							6u								// Status bit indicating a request for entry into HIBERNATE from SLEEP mode. True when set. Default is 0
#define	BCA									10u								// Status bit indicating the bq27510 board calibration routine is active. Active when set
#define	BCCA								11u								// Status bit indicating the bq27510 coulomb counter calibration routine. Active when set
#define	BCSV								12u								// Status bit indicating a valid data flash checksum has been generated. Active when set
#define	BSS									13u								// Status bit indicating the bq27510 is in the SEALED State. Active when set
#define	BFAS								14u								// Status bit indicating the bq27510 is in FULL ACCESS SEALED state. Active when set

#define	BQ27510G3_TYPE						0x0001u							// Reports the device type (bq27510)
#define	BQ27510G3_VERSION					0x0002u							// Reports the firmware version on the device type
#define	BQ27510G3_MAC_WRITE					0x0007u							// Returns previous MAC command code
#define	BQ27510G3_ID						0x0008u							// Reports the chemical identifier of the Impedance TrackTM configuration
#define	BQ27510G3_CMD						0x000Cu							// Requests the fuel gauge to take an OCV measurement
#define	BQ27510G3_INSERT					0x000Du							// Forces Flags( ) [BAT_DET] bit set when OpConfig B [BIE] = 0
#define	BQ27510G3_REMOVE					0x000Eu							// Forces Flags( ) [BAT_DET] bit clear when OpConfig B [BIE] = 0
#define	BQ27510G3_SET_HIBERNATE				0x0011u							// Forces CONTROL_STATUS [HIBERNATE] to 1
#define	BQ27510G3_CLR_HIBERNATE				0x0012u							// Forces CONTROL_STATUS [HIBERNATE] to 0
#define	BQ27510G3_SUB_SEALED				0x0020u							// Places the bq27510 in SEALED access mode
#define	BQ27510G3_SUB_ENABLE				0x0021u							// Enables the Impedance TrackTM algorithm
#define	BQ27510G3_SUB_RESET					0x0041u							// Forces a full reset of the bq27510

#define	BQ27510G3_TRATE						0x0203u							//
#define	BQ27510G3_TRATE_TIME_TO_EMPTY		0x0405u							//
#define	BQ27510G3_TEMPERATURE				0x0607u							//
#define	BQ27510G3_VOLTAGE					0x0809u							//
#define	BQ27510G3_FLAGS						0x0A0Bu							//
#define	BDSG								0u								// Flag bit indicating discharging detected. True when set
#define	BSOCF								1u								// Flag bit indicating state-of-Charge-Threshold Final (SOCF Set %) reached. True when set
#define	BSOC1								2u								// Flag bit indicating state-of-Charge-Threshold 1 (SOC1 Set) reached. True when set
#define	BBAT_DET							3u								// Flag bit indicating battery detected. True when set
#define	BWAIT_ID							4u								// Flag bit indicating waiting to identify inserted battery. True when set
#define	BOCV_GD								5u								// Flag bit indicating good OCV measurement taken. True when set.
#define	BCHG								8u								// Flag bit indicating (fast) charging allowed. True when set
#define	BFC									9u								// Flag bit indicating full-charged condition reached. True when set
#define	BXCHG								10u								// Flag bit indicating charge Suspend Alert (temp outside the range [Suspend Temperature Low, Suspend Temperature High]). True when set
#define	BCHG_INH							11u								// Flag bit indicating charge Inhibit: unable to begin charging (temp outside the range [Charge Inhibit Temp Low, Charge Inhibit Temp High]). True when set
#define	BOTD								14u								// Flag bit indicating over-Temperature in discharge condition is detected. True when set
#define	BOC									15u								// Flag bit indicating over-Temperature in charge condition is detected. True when set.

#define	BQ27510G3_NOMI_AVAILABLE_CAPACITY	0x0C0Du							//
#define	BQ27510G3_FULL_AVAILABLE_CAPACITY	0x0E0Fu							//
#define	BQ27510G3_REMAINING_CAPACITY		0x1011u							//
#define	BQ27510G3_FULL_CHARGE_CAPACITY		0x1213u							//
#define	BQ27510G3_AVERAGE_CURRENT			0x1415u							//
#define	BQ27510G3_TIME_TO_EMPTY				0x1617u							//
#define	BQ27510G3_STBANDBY_CURRENT			0x1819u							//
#define	BQ27510G3_STBANDBY_TIME_TO_EMPTY	0x1A1Bu							//
#define	BQ27510G3_CYCLE_COUNT				0x1E1Fu							//
#define	BQ27510G3_STATE_OF_CHARGE			0x2021u							//
#define	BQ27510G3_ISTANTANEOUS_CURRENT		0x2223u							//
#define	BQ27510G3_INTERNAL_TEMPERATURE		0x2829u							//
#define	BQ27510G3_DESIGN_CAPACITY			0x2E2Fu							//
#define	BQ27510G3_FILTER_DRM				0x6C6Du							//
