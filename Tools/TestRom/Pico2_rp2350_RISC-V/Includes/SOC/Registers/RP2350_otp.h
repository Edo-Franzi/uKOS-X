/*
; RP2350_otp.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		RP2350_otp equates.
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

// OTP address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	SW_LOCK0;
	volatile	uint32_t	SW_LOCK1;
	volatile	uint32_t	SW_LOCK2;
	volatile	uint32_t	SW_LOCK3;
	volatile	uint32_t	SW_LOCK4;
	volatile	uint32_t	SW_LOCK5;
	volatile	uint32_t	SW_LOCK6;
	volatile	uint32_t	SW_LOCK7;
	volatile	uint32_t	SW_LOCK8;
	volatile	uint32_t	SW_LOCK9;
	volatile	uint32_t	SW_LOCK10;
	volatile	uint32_t	SW_LOCK11;
	volatile	uint32_t	SW_LOCK12;
	volatile	uint32_t	SW_LOCK13;
	volatile	uint32_t	SW_LOCK14;
	volatile	uint32_t	SW_LOCK15;
	volatile	uint32_t	SW_LOCK16;
	volatile	uint32_t	SW_LOCK17;
	volatile	uint32_t	SW_LOCK18;
	volatile	uint32_t	SW_LOCK19;
	volatile	uint32_t	SW_LOCK20;
	volatile	uint32_t	SW_LOCK21;
	volatile	uint32_t	SW_LOCK22;
	volatile	uint32_t	SW_LOCK23;
	volatile	uint32_t	SW_LOCK24;
	volatile	uint32_t	SW_LOCK25;
	volatile	uint32_t	SW_LOCK26;
	volatile	uint32_t	SW_LOCK27;
	volatile	uint32_t	SW_LOCK28;
	volatile	uint32_t	SW_LOCK29;
	volatile	uint32_t	SW_LOCK30;
	volatile	uint32_t	SW_LOCK31;
	volatile	uint32_t	SW_LOCK32;
	volatile	uint32_t	SW_LOCK33;
	volatile	uint32_t	SW_LOCK34;
	volatile	uint32_t	SW_LOCK35;
	volatile	uint32_t	SW_LOCK36;
	volatile	uint32_t	SW_LOCK37;
	volatile	uint32_t	SW_LOCK38;
	volatile	uint32_t	SW_LOCK39;
	volatile	uint32_t	SW_LOCK40;
	volatile	uint32_t	SW_LOCK41;
	volatile	uint32_t	SW_LOCK42;
	volatile	uint32_t	SW_LOCK43;
	volatile	uint32_t	SW_LOCK44;
	volatile	uint32_t	SW_LOCK45;
	volatile	uint32_t	SW_LOCK46;
	volatile	uint32_t	SW_LOCK47;
	volatile	uint32_t	SW_LOCK48;
	volatile	uint32_t	SW_LOCK49;
	volatile	uint32_t	SW_LOCK50;
	volatile	uint32_t	SW_LOCK51;
	volatile	uint32_t	SW_LOCK52;
	volatile	uint32_t	SW_LOCK53;
	volatile	uint32_t	SW_LOCK54;
	volatile	uint32_t	SW_LOCK55;
	volatile	uint32_t	SW_LOCK56;
	volatile	uint32_t	SW_LOCK57;
	volatile	uint32_t	SW_LOCK58;
	volatile	uint32_t	SW_LOCK59;
	volatile	uint32_t	SW_LOCK60;
	volatile	uint32_t	SW_LOCK61;
	volatile	uint32_t	SW_LOCK62;
	volatile	uint32_t	SW_LOCK63;
	volatile	uint32_t	SBPI_INSTR;
	volatile	uint32_t	SBPI_WDATA_0;
	volatile	uint32_t	SBPI_WDATA_1;
	volatile	uint32_t	SBPI_WDATA_2;
	volatile	uint32_t	SBPI_WDATA_3;
	volatile	uint32_t	SBPI_RDATA_0;
	volatile	uint32_t	SBPI_RDATA_1;
	volatile	uint32_t	SBPI_RDATA_2;
	volatile	uint32_t	SBPI_RDATA_3;
	volatile	uint32_t	SBPI_STATUS;
	volatile	uint32_t	USR;
	volatile	uint32_t	DBG;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	BIST;
	volatile	uint32_t	CRT_KEY_W0;
	volatile	uint32_t	CRT_KEY_W1;
	volatile	uint32_t	CRT_KEY_W2;
	volatile	uint32_t	CRT_KEY_W3;
	volatile	uint32_t	CRITICAL;
	volatile	uint32_t	KEY_VALID;
	volatile	uint32_t	DEBUGEN;
	volatile	uint32_t	DEBUGEN_LOCK;
	volatile	uint32_t	ARCHSEL;
	volatile	uint32_t	ARCHSEL_STATUS;
	volatile	uint32_t	BOOTDIS;
	volatile	uint32_t	INTR;
	volatile	uint32_t	INTE;
	volatile	uint32_t	INTF;
	volatile	uint32_t	INTS;
} OTP_TypeDef;

#ifdef __cplusplus
#define	OTP_NS	reinterpret_cast<OTP_TypeDef *>(0x40120000u)
#define	OTP_S	reinterpret_cast<OTP_TypeDef *>(0x40120000u)
#else
#define	OTP_NS	((OTP_TypeDef *)0x40120000u)
#define	OTP_S	((OTP_TypeDef *)0x40120000u)
#endif

// SW_LOCK0 Configuration

#define	OTP_SW_LOCK0_SEC					(0x3u<<0)
#define	OTP_SW_LOCK0_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK0_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK0_NSEC_0					(0x1u<<2)
#define	OTP_SW_LOCK0_SEC_READ_WRITE			(0x0u<<0)
#define	OTP_SW_LOCK0_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK0_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK0_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK0_NSEC_READ_ONLY			(0x1u<<2)
#define	OTP_SW_LOCK0_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK1 Configuration

#define	OTP_SW_LOCK1_SEC					(0x3u<<0)
#define	OTP_SW_LOCK1_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK1_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK1_NSEC_0					(0x1u<<2)
#define	OTP_SW_LOCK1_SEC_READ_WRITE			(0x0u<<0)
#define	OTP_SW_LOCK1_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK1_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK1_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK1_NSEC_READ_ONLY			(0x1u<<2)
#define	OTP_SW_LOCK1_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK2 Configuration

#define	OTP_SW_LOCK2_SEC					(0x3u<<0)
#define	OTP_SW_LOCK2_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK2_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK2_NSEC_0					(0x1u<<2)
#define	OTP_SW_LOCK2_SEC_READ_WRITE			(0x0u<<0)
#define	OTP_SW_LOCK2_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK2_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK2_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK2_NSEC_READ_ONLY			(0x1u<<2)
#define	OTP_SW_LOCK2_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK3 Configuration

#define	OTP_SW_LOCK3_SEC					(0x3u<<0)
#define	OTP_SW_LOCK3_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK3_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK3_NSEC_0					(0x1u<<2)
#define	OTP_SW_LOCK3_SEC_READ_WRITE			(0x0u<<0)
#define	OTP_SW_LOCK3_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK3_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK3_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK3_NSEC_READ_ONLY			(0x1u<<2)
#define	OTP_SW_LOCK3_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK4 Configuration

#define	OTP_SW_LOCK4_SEC					(0x3u<<0)
#define	OTP_SW_LOCK4_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK4_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK4_NSEC_0					(0x1u<<2)
#define	OTP_SW_LOCK4_SEC_READ_WRITE			(0x0u<<0)
#define	OTP_SW_LOCK4_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK4_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK4_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK4_NSEC_READ_ONLY			(0x1u<<2)
#define	OTP_SW_LOCK4_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK5 Configuration

#define	OTP_SW_LOCK5_SEC					(0x3u<<0)
#define	OTP_SW_LOCK5_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK5_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK5_NSEC_0					(0x1u<<2)
#define	OTP_SW_LOCK5_SEC_READ_WRITE			(0x0u<<0)
#define	OTP_SW_LOCK5_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK5_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK5_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK5_NSEC_READ_ONLY			(0x1u<<2)
#define	OTP_SW_LOCK5_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK6 Configuration

#define	OTP_SW_LOCK6_SEC					(0x3u<<0)
#define	OTP_SW_LOCK6_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK6_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK6_NSEC_0					(0x1u<<2)
#define	OTP_SW_LOCK6_SEC_READ_WRITE			(0x0u<<0)
#define	OTP_SW_LOCK6_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK6_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK6_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK6_NSEC_READ_ONLY			(0x1u<<2)
#define	OTP_SW_LOCK6_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK7 Configuration

#define	OTP_SW_LOCK7_SEC					(0x3u<<0)
#define	OTP_SW_LOCK7_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK7_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK7_NSEC_0					(0x1u<<2)
#define	OTP_SW_LOCK7_SEC_READ_WRITE			(0x0u<<0)
#define	OTP_SW_LOCK7_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK7_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK7_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK7_NSEC_READ_ONLY			(0x1u<<2)
#define	OTP_SW_LOCK7_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK8 Configuration

#define	OTP_SW_LOCK8_SEC					(0x3u<<0)
#define	OTP_SW_LOCK8_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK8_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK8_NSEC_0					(0x1u<<2)
#define	OTP_SW_LOCK8_SEC_READ_WRITE			(0x0u<<0)
#define	OTP_SW_LOCK8_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK8_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK8_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK8_NSEC_READ_ONLY			(0x1u<<2)
#define	OTP_SW_LOCK8_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK9 Configuration

#define	OTP_SW_LOCK9_SEC					(0x3u<<0)
#define	OTP_SW_LOCK9_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK9_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK9_NSEC_0					(0x1u<<2)
#define	OTP_SW_LOCK9_SEC_READ_WRITE			(0x0u<<0)
#define	OTP_SW_LOCK9_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK9_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK9_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK9_NSEC_READ_ONLY			(0x1u<<2)
#define	OTP_SW_LOCK9_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK10 Configuration

#define	OTP_SW_LOCK10_SEC					(0x3u<<0)
#define	OTP_SW_LOCK10_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK10_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK10_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK10_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK10_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK10_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK10_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK10_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK10_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK11 Configuration

#define	OTP_SW_LOCK11_SEC					(0x3u<<0)
#define	OTP_SW_LOCK11_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK11_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK11_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK11_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK11_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK11_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK11_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK11_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK11_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK12 Configuration

#define	OTP_SW_LOCK12_SEC					(0x3u<<0)
#define	OTP_SW_LOCK12_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK12_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK12_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK12_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK12_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK12_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK12_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK12_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK12_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK13 Configuration

#define	OTP_SW_LOCK13_SEC					(0x3u<<0)
#define	OTP_SW_LOCK13_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK13_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK13_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK13_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK13_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK13_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK13_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK13_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK13_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK14 Configuration

#define	OTP_SW_LOCK14_SEC					(0x3u<<0)
#define	OTP_SW_LOCK14_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK14_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK14_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK14_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK14_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK14_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK14_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK14_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK14_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK15 Configuration

#define	OTP_SW_LOCK15_SEC					(0x3u<<0)
#define	OTP_SW_LOCK15_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK15_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK15_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK15_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK15_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK15_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK15_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK15_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK15_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK16 Configuration

#define	OTP_SW_LOCK16_SEC					(0x3u<<0)
#define	OTP_SW_LOCK16_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK16_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK16_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK16_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK16_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK16_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK16_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK16_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK16_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK17 Configuration

#define	OTP_SW_LOCK17_SEC					(0x3u<<0)
#define	OTP_SW_LOCK17_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK17_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK17_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK17_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK17_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK17_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK17_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK17_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK17_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK18 Configuration

#define	OTP_SW_LOCK18_SEC					(0x3u<<0)
#define	OTP_SW_LOCK18_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK18_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK18_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK18_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK18_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK18_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK18_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK18_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK18_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK19 Configuration

#define	OTP_SW_LOCK19_SEC					(0x3u<<0)
#define	OTP_SW_LOCK19_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK19_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK19_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK19_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK19_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK19_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK19_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK19_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK19_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK20 Configuration

#define	OTP_SW_LOCK20_SEC					(0x3u<<0)
#define	OTP_SW_LOCK20_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK20_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK20_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK20_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK20_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK20_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK20_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK20_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK20_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK21 Configuration

#define	OTP_SW_LOCK21_SEC					(0x3u<<0)
#define	OTP_SW_LOCK21_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK21_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK21_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK21_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK21_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK21_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK21_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK21_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK21_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK22 Configuration

#define	OTP_SW_LOCK22_SEC					(0x3u<<0)
#define	OTP_SW_LOCK22_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK22_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK22_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK22_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK22_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK22_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK22_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK22_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK22_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK23 Configuration

#define	OTP_SW_LOCK23_SEC					(0x3u<<0)
#define	OTP_SW_LOCK23_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK23_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK23_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK23_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK23_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK23_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK23_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK23_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK23_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK24 Configuration

#define	OTP_SW_LOCK24_SEC					(0x3u<<0)
#define	OTP_SW_LOCK24_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK24_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK24_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK24_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK24_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK24_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK24_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK24_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK24_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK25 Configuration

#define	OTP_SW_LOCK25_SEC					(0x3u<<0)
#define	OTP_SW_LOCK25_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK25_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK25_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK25_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK25_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK25_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK25_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK25_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK25_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK26 Configuration

#define	OTP_SW_LOCK26_SEC					(0x3u<<0)
#define	OTP_SW_LOCK26_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK26_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK26_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK26_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK26_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK26_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK26_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK26_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK26_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK27 Configuration

#define	OTP_SW_LOCK27_SEC					(0x3u<<0)
#define	OTP_SW_LOCK27_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK27_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK27_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK27_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK27_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK27_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK27_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK27_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK27_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK28 Configuration

#define	OTP_SW_LOCK28_SEC					(0x3u<<0)
#define	OTP_SW_LOCK28_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK28_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK28_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK28_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK28_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK28_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK28_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK28_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK28_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK29 Configuration

#define	OTP_SW_LOCK29_SEC					(0x3u<<0)
#define	OTP_SW_LOCK29_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK29_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK29_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK29_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK29_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK29_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK29_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK29_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK29_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK30 Configuration

#define	OTP_SW_LOCK30_SEC					(0x3u<<0)
#define	OTP_SW_LOCK30_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK30_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK30_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK30_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK30_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK30_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK30_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK30_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK30_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK31 Configuration

#define	OTP_SW_LOCK31_SEC					(0x3u<<0)
#define	OTP_SW_LOCK31_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK31_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK31_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK31_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK31_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK31_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK31_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK31_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK31_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK32 Configuration

#define	OTP_SW_LOCK32_SEC					(0x3u<<0)
#define	OTP_SW_LOCK32_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK32_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK32_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK32_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK32_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK32_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK32_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK32_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK32_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK33 Configuration

#define	OTP_SW_LOCK33_SEC					(0x3u<<0)
#define	OTP_SW_LOCK33_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK33_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK33_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK33_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK33_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK33_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK33_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK33_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK33_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK34 Configuration

#define	OTP_SW_LOCK34_SEC					(0x3u<<0)
#define	OTP_SW_LOCK34_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK34_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK34_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK34_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK34_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK34_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK34_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK34_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK34_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK35 Configuration

#define	OTP_SW_LOCK35_SEC					(0x3u<<0)
#define	OTP_SW_LOCK35_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK35_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK35_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK35_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK35_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK35_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK35_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK35_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK35_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK36 Configuration

#define	OTP_SW_LOCK36_SEC					(0x3u<<0)
#define	OTP_SW_LOCK36_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK36_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK36_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK36_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK36_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK36_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK36_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK36_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK36_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK37 Configuration

#define	OTP_SW_LOCK37_SEC					(0x3u<<0)
#define	OTP_SW_LOCK37_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK37_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK37_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK37_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK37_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK37_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK37_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK37_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK37_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK38 Configuration

#define	OTP_SW_LOCK38_SEC					(0x3u<<0)
#define	OTP_SW_LOCK38_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK38_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK38_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK38_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK38_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK38_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK38_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK38_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK38_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK39 Configuration

#define	OTP_SW_LOCK39_SEC					(0x3u<<0)
#define	OTP_SW_LOCK39_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK39_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK39_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK39_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK39_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK39_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK39_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK39_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK39_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK40 Configuration

#define	OTP_SW_LOCK40_SEC					(0x3u<<0)
#define	OTP_SW_LOCK40_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK40_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK40_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK40_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK40_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK40_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK40_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK40_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK40_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK41 Configuration

#define	OTP_SW_LOCK41_SEC					(0x3u<<0)
#define	OTP_SW_LOCK41_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK41_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK41_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK41_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK41_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK41_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK41_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK41_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK41_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK42 Configuration

#define	OTP_SW_LOCK42_SEC					(0x3u<<0)
#define	OTP_SW_LOCK42_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK42_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK42_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK42_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK42_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK42_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK42_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK42_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK42_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK43 Configuration

#define	OTP_SW_LOCK43_SEC					(0x3u<<0)
#define	OTP_SW_LOCK43_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK43_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK43_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK43_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK43_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK43_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK43_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK43_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK43_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK44 Configuration

#define	OTP_SW_LOCK44_SEC					(0x3u<<0)
#define	OTP_SW_LOCK44_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK44_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK44_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK44_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK44_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK44_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK44_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK44_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK44_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK45 Configuration

#define	OTP_SW_LOCK45_SEC					(0x3u<<0)
#define	OTP_SW_LOCK45_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK45_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK45_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK45_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK45_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK45_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK45_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK45_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK45_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK46 Configuration

#define	OTP_SW_LOCK46_SEC					(0x3u<<0)
#define	OTP_SW_LOCK46_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK46_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK46_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK46_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK46_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK46_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK46_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK46_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK46_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK47 Configuration

#define	OTP_SW_LOCK47_SEC					(0x3u<<0)
#define	OTP_SW_LOCK47_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK47_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK47_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK47_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK47_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK47_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK47_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK47_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK47_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK48 Configuration

#define	OTP_SW_LOCK48_SEC					(0x3u<<0)
#define	OTP_SW_LOCK48_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK48_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK48_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK48_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK48_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK48_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK48_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK48_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK48_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK49 Configuration

#define	OTP_SW_LOCK49_SEC					(0x3u<<0)
#define	OTP_SW_LOCK49_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK49_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK49_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK49_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK49_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK49_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK49_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK49_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK49_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK50 Configuration

#define	OTP_SW_LOCK50_SEC					(0x3u<<0)
#define	OTP_SW_LOCK50_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK50_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK50_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK50_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK50_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK50_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK50_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK50_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK50_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK51 Configuration

#define	OTP_SW_LOCK51_SEC					(0x3u<<0)
#define	OTP_SW_LOCK51_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK51_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK51_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK51_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK51_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK51_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK51_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK51_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK51_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK52 Configuration

#define	OTP_SW_LOCK52_SEC					(0x3u<<0)
#define	OTP_SW_LOCK52_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK52_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK52_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK52_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK52_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK52_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK52_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK52_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK52_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK53 Configuration

#define	OTP_SW_LOCK53_SEC					(0x3u<<0)
#define	OTP_SW_LOCK53_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK53_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK53_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK53_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK53_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK53_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK53_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK53_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK53_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK54 Configuration

#define	OTP_SW_LOCK54_SEC					(0x3u<<0)
#define	OTP_SW_LOCK54_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK54_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK54_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK54_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK54_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK54_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK54_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK54_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK54_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK55 Configuration

#define	OTP_SW_LOCK55_SEC					(0x3u<<0)
#define	OTP_SW_LOCK55_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK55_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK55_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK55_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK55_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK55_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK55_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK55_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK55_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK56 Configuration

#define	OTP_SW_LOCK56_SEC					(0x3u<<0)
#define	OTP_SW_LOCK56_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK56_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK56_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK56_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK56_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK56_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK56_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK56_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK56_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK57 Configuration

#define	OTP_SW_LOCK57_SEC					(0x3u<<0)
#define	OTP_SW_LOCK57_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK57_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK57_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK57_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK57_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK57_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK57_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK57_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK57_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK58 Configuration

#define	OTP_SW_LOCK58_SEC					(0x3u<<0)
#define	OTP_SW_LOCK58_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK58_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK58_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK58_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK58_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK58_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK58_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK58_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK58_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK59 Configuration

#define	OTP_SW_LOCK59_SEC					(0x3u<<0)
#define	OTP_SW_LOCK59_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK59_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK59_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK59_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK59_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK59_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK59_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK59_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK59_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK60 Configuration

#define	OTP_SW_LOCK60_SEC					(0x3u<<0)
#define	OTP_SW_LOCK60_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK60_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK60_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK60_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK60_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK60_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK60_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK60_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK60_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK61 Configuration

#define	OTP_SW_LOCK61_SEC					(0x3u<<0)
#define	OTP_SW_LOCK61_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK61_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK61_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK61_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK61_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK61_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK61_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK61_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK61_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK62 Configuration

#define	OTP_SW_LOCK62_SEC					(0x3u<<0)
#define	OTP_SW_LOCK62_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK62_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK62_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK62_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK62_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK62_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK62_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK62_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK62_NSEC_INACCESSIBLE		(0x3u<<2)

// SW_LOCK63 Configuration

#define	OTP_SW_LOCK63_SEC					(0x3u<<0)
#define	OTP_SW_LOCK63_SEC_0					(0x1u<<0)
#define	OTP_SW_LOCK63_NSEC					(0x3u<<2)
#define	OTP_SW_LOCK63_NSEC_0				(0x1u<<2)
#define	OTP_SW_LOCK63_SEC_READ_WRITE		(0x0u<<0)
#define	OTP_SW_LOCK63_SEC_READ_ONLY			(0x1u<<0)
#define	OTP_SW_LOCK63_SEC_INACCESSIBLE		(0x3u<<0)
#define	OTP_SW_LOCK63_NSEC_READ_WRITE		(0x0u<<2)
#define	OTP_SW_LOCK63_NSEC_READ_ONLY		(0x1u<<2)
#define	OTP_SW_LOCK63_NSEC_INACCESSIBLE		(0x3u<<2)

// SBPI_INSTR Configuration

#define	OTP_SBPI_INSTR_SHORT_WDATA			(0xFFu<<0)
#define	OTP_SBPI_INSTR_SHORT_WDATA_0		(0x1u<<0)
#define	OTP_SBPI_INSTR_CMD					(0xFFu<<8)
#define	OTP_SBPI_INSTR_CMD_0				(0x1u<<8)
#define	OTP_SBPI_INSTR_TARGET				(0xFFu<<16)
#define	OTP_SBPI_INSTR_TARGET_0				(0x1u<<16)
#define	OTP_SBPI_INSTR_PAYLOAD_SIZE_M1		(0xFu<<24)
#define	OTP_SBPI_INSTR_PAYLOAD_SIZE_M1_0	(0x1u<<24)
#define	OTP_SBPI_INSTR_HAS_PAYLOAD			(0x1u<<28)
#define	OTP_SBPI_INSTR_IS_WR				(0x1u<<29)
#define	OTP_SBPI_INSTR_EXEC					(0x1u<<30)

// SBPI_WDATA_0 Configuration

#define	OTP_SBPI_WDATA_0_SBPI_WDATA_0		(0xFFFFFFFFu<<0)
#define	OTP_SBPI_WDATA_0_SBPI_WDATA_0_0		(0x1u<<0)

// SBPI_WDATA_1 Configuration

#define	OTP_SBPI_WDATA_1_SBPI_WDATA_1		(0xFFFFFFFFu<<0)
#define	OTP_SBPI_WDATA_1_SBPI_WDATA_1_0		(0x1u<<0)

// SBPI_WDATA_2 Configuration

#define	OTP_SBPI_WDATA_2_SBPI_WDATA_2		(0xFFFFFFFFu<<0)
#define	OTP_SBPI_WDATA_2_SBPI_WDATA_2_0		(0x1u<<0)

// SBPI_WDATA_3 Configuration

#define	OTP_SBPI_WDATA_3_SBPI_WDATA_3		(0xFFFFFFFFu<<0)
#define	OTP_SBPI_WDATA_3_SBPI_WDATA_3_0		(0x1u<<0)

// SBPI_RDATA_0 Configuration

#define	OTP_SBPI_RDATA_0_SBPI_RDATA_0		(0xFFFFFFFFu<<0)
#define	OTP_SBPI_RDATA_0_SBPI_RDATA_0_0		(0x1u<<0)

// SBPI_RDATA_1 Configuration

#define	OTP_SBPI_RDATA_1_SBPI_RDATA_1		(0xFFFFFFFFu<<0)
#define	OTP_SBPI_RDATA_1_SBPI_RDATA_1_0		(0x1u<<0)

// SBPI_RDATA_2 Configuration

#define	OTP_SBPI_RDATA_2_SBPI_RDATA_2		(0xFFFFFFFFu<<0)
#define	OTP_SBPI_RDATA_2_SBPI_RDATA_2_0		(0x1u<<0)

// SBPI_RDATA_3 Configuration

#define	OTP_SBPI_RDATA_3_SBPI_RDATA_3		(0xFFFFFFFFu<<0)
#define	OTP_SBPI_RDATA_3_SBPI_RDATA_3_0		(0x1u<<0)

// SBPI_STATUS Configuration

#define	OTP_SBPI_STATUS_RDATA_VLD			(0x1u<<0)
#define	OTP_SBPI_STATUS_INSTR_DONE			(0x1u<<4)
#define	OTP_SBPI_STATUS_INSTR_MISS			(0x1u<<8)
#define	OTP_SBPI_STATUS_FLAG				(0x1u<<12)
#define	OTP_SBPI_STATUS_MISO				(0xFFu<<16)
#define	OTP_SBPI_STATUS_MISO_0				(0x1u<<16)

// USR Configuration

#define	OTP_USR_DCTRL						(0x1u<<0)
#define	OTP_USR_PD							(0x1u<<4)

// DBG Configuration

#define	OTP_DBG_PSM_DONE					(0x1u<<0)
#define	OTP_DBG_BOOT_DONE					(0x1u<<1)
#define	OTP_DBG_ROSC_UP_SEEN				(0x1u<<2)
#define	OTP_DBG_ROSC_UP						(0x1u<<3)
#define	OTP_DBG_PSM_STATE					(0xFu<<4)
#define	OTP_DBG_PSM_STATE_0					(0x1u<<4)
#define	OTP_DBG_CUSTOMER_RMA_FLAG			(0x1u<<12)

// BIST Configuration

#define	OTP_BIST_CNT						(0x1FFFu<<0)
#define	OTP_BIST_CNT_0						(0x1u<<0)
#define	OTP_BIST_CNT_MAX					(0xFFFu<<16)
#define	OTP_BIST_CNT_MAX_0					(0x1u<<16)
#define	OTP_BIST_CNT_ENA					(0x1u<<28)
#define	OTP_BIST_CNT_CLR					(0x1u<<29)
#define	OTP_BIST_CNT_FAIL					(0x1u<<30)

// CRT_KEY_W0 Configuration

#define	OTP_CRT_KEY_W0_CRT_KEY_W0			(0xFFFFFFFFu<<0)
#define	OTP_CRT_KEY_W0_CRT_KEY_W0_0			(0x1u<<0)

// CRT_KEY_W1 Configuration

#define	OTP_CRT_KEY_W1_CRT_KEY_W1			(0xFFFFFFFFu<<0)
#define	OTP_CRT_KEY_W1_CRT_KEY_W1_0			(0x1u<<0)

// CRT_KEY_W2 Configuration

#define	OTP_CRT_KEY_W2_CRT_KEY_W2			(0xFFFFFFFFu<<0)
#define	OTP_CRT_KEY_W2_CRT_KEY_W2_0			(0x1u<<0)

// CRT_KEY_W3 Configuration

#define	OTP_CRT_KEY_W3_CRT_KEY_W3			(0xFFFFFFFFu<<0)
#define	OTP_CRT_KEY_W3_CRT_KEY_W3_0			(0x1u<<0)

// CRITICAL Configuration

#define	OTP_CRITICAL_SECURE_BOOT_ENABLE		(0x1u<<0)
#define	OTP_CRITICAL_SECURE_DEBUG_DISABLE	(0x1u<<1)
#define	OTP_CRITICAL_DEBUG_DISABLE			(0x1u<<2)
#define	OTP_CRITICAL_DEFAULT_ARCHSEL		(0x1u<<3)
#define	OTP_CRITICAL_GLITCH_DETECTOR_ENABLE	(0x1u<<4)
#define	OTP_CRITICAL_GLITCH_DETECTOR_SENS	(0x3u<<5)
#define	OTP_CRITICAL_GLITCH_DETECTOR_SENS_0	(0x1u<<5)
#define	OTP_CRITICAL_ARM_DISABLE			(0x1u<<16)
#define	OTP_CRITICAL_RISCV_DISABLE			(0x1u<<17)

// KEY_VALID Configuration

#define	OTP_KEY_VALID_KEY_VALID				(0xFFu<<0)
#define	OTP_KEY_VALID_KEY_VALID_0			(0x1u<<0)

// DEBUGEN Configuration

#define	OTP_DEBUGEN_PROC0					(0x1u<<0)
#define	OTP_DEBUGEN_PROC0_SECURE			(0x1u<<1)
#define	OTP_DEBUGEN_PROC1					(0x1u<<2)
#define	OTP_DEBUGEN_PROC1_SECURE			(0x1u<<3)
#define	OTP_DEBUGEN_MISC					(0x1u<<8)

// DEBUGEN_LOCK Configuration

#define	OTP_DEBUGEN_LOCK_PROC0				(0x1u<<0)
#define	OTP_DEBUGEN_LOCK_PROC0_SECURE		(0x1u<<1)
#define	OTP_DEBUGEN_LOCK_PROC1				(0x1u<<2)
#define	OTP_DEBUGEN_LOCK_PROC1_SECURE		(0x1u<<3)
#define	OTP_DEBUGEN_LOCK_MISC				(0x1u<<8)

// ARCHSEL Configuration

#define	OTP_ARCHSEL_CORE0					(0x1u<<0)
#define	OTP_ARCHSEL_CORE1					(0x1u<<1)
#define	OTP_ARCHSEL_CORE0_ARM				(0x0u<<0)
#define	OTP_ARCHSEL_CORE0_RISCV				(0x1u<<0)
#define	OTP_ARCHSEL_CORE1_ARM				(0x0u<<1)
#define	OTP_ARCHSEL_CORE1_RISCV				(0x1u<<1)

// ARCHSEL_STATUS Configuration

#define	OTP_ARCHSEL_STATUS_CORE0			(0x1u<<0)
#define	OTP_ARCHSEL_STATUS_CORE1			(0x1u<<1)
#define	OTP_ARCHSEL_STATUS_CORE0_ARM		(0x0u<<0)
#define	OTP_ARCHSEL_STATUS_CORE0_RISCV		(0x1u<<0)
#define	OTP_ARCHSEL_STATUS_CORE1_ARM		(0x0u<<1)
#define	OTP_ARCHSEL_STATUS_CORE1_RISCV		(0x1u<<1)

// BOOTDIS Configuration

#define	OTP_BOOTDIS_NOW						(0x1u<<0)
#define	OTP_BOOTDIS_NEXT					(0x1u<<1)

// INTR Configuration

#define	OTP_INTR_SBPI_FLAG_N				(0x1u<<0)
#define	OTP_INTR_SBPI_WR_FAIL				(0x1u<<1)
#define	OTP_INTR_APB_DCTRL_FAIL				(0x1u<<2)
#define	OTP_INTR_APB_RD_SEC_FAIL			(0x1u<<3)
#define	OTP_INTR_APB_RD_NSEC_FAIL			(0x1u<<4)

// INTE Configuration

#define	OTP_INTE_SBPI_FLAG_N				(0x1u<<0)
#define	OTP_INTE_SBPI_WR_FAIL				(0x1u<<1)
#define	OTP_INTE_APB_DCTRL_FAIL				(0x1u<<2)
#define	OTP_INTE_APB_RD_SEC_FAIL			(0x1u<<3)
#define	OTP_INTE_APB_RD_NSEC_FAIL			(0x1u<<4)

// INTF Configuration

#define	OTP_INTF_SBPI_FLAG_N				(0x1u<<0)
#define	OTP_INTF_SBPI_WR_FAIL				(0x1u<<1)
#define	OTP_INTF_APB_DCTRL_FAIL				(0x1u<<2)
#define	OTP_INTF_APB_RD_SEC_FAIL			(0x1u<<3)
#define	OTP_INTF_APB_RD_NSEC_FAIL			(0x1u<<4)

// INTS Configuration

#define	OTP_INTS_SBPI_FLAG_N				(0x1u<<0)
#define	OTP_INTS_SBPI_WR_FAIL				(0x1u<<1)
#define	OTP_INTS_APB_DCTRL_FAIL				(0x1u<<2)
#define	OTP_INTS_APB_RD_SEC_FAIL			(0x1u<<3)
#define	OTP_INTS_APB_RD_NSEC_FAIL			(0x1u<<4)
