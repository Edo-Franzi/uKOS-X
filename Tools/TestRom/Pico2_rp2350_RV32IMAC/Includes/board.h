/*
SPDX-License-Identifier: MIT
SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen
*/

/*
;------------------------------------------------------------------------
; board.
; ======
;
; Project:	uKOS-X
; Goal:		Board mapping.
;------------------------------------------------------------------------
*/

#pragma	once

// System identifiers
// ------------------

#define	KCPU				"RISC-V Hazard3"
#define	KCONTROLLER			"rp23450"
#define	KBOARD				"Pico2 rp2350 (Variant_Test)"
#define	KTARGET				"Pico2_rp2350"

#define	LED_SYSTEM_ON		(REG(SIO)->GPIO_OUT_SET = (1<<BLED_s))		//
#define	LED_SYSTEM_OFF		(REG(SIO)->GPIO_OUT_CLR = (1<<BLED_s))		//
#define	LED_SYSTEM_TOGGLE	(REG(SIO)->GPIO_OUT_XOR = (1<<BLED_s))		// Led macros

#define	LED_YELLOW_ON		(REG(SIO)->GPIO_OUT_SET = (1<<BLED_0))		//
#define	LED_YELLOW_OFF		(REG(SIO)->GPIO_OUT_CLR = (1<<BLED_0))		//
#define	LED_YELLOW_TOGGLE	(REG(SIO)->GPIO_OUT_XOR = (1<<BLED_0))		// Led macros

#define	LED_GREEN_ON		(REG(SIO)->GPIO_OUT_SET = (1<<BLED_1))		//
#define	LED_GREEN_OFF		(REG(SIO)->GPIO_OUT_CLR = (1<<BLED_1))		//
#define	LED_GREEN_TOGGLE	(REG(SIO)->GPIO_OUT_XOR = (1<<BLED_1))		// Led macros

#define	LED_RED_ON			(REG(SIO)->GPIO_OUT_SET = (1<<BLED_2))		//
#define	LED_RED_OFF			(REG(SIO)->GPIO_OUT_CLR = (1<<BLED_2))		//
#define	LED_RED_TOGGLE		(REG(SIO)->GPIO_OUT_XOR = (1<<BLED_2))		// Led macros

#define KNB_LED				4u											// Number of LEDs

// PORTs

#if (BOARD_Pico2 == true)
#define	BLED_s				25u											// GPIO25, LED system

#elif (BOARD_Pico2W == true)
#define	BLED_s				0u											// GPIO0, LED system
#endif

#define	BLED_0				11u											// GPIO11, LED yellow
#define	BLED_1				12u											// GPIO12, LED green
#define	BLED_2				13u											// GPIO13, LED red
