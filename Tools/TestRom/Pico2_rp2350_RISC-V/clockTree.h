/*
; clockTree.
; ==========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Laurent von Allmen		The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		Clock tree definitions for RISC-V RP2350.
;
;   (c) 2025-2026, Laurent von Allmen
;   ---------------------------------
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
;------------------------------------------------------------------------
*/

#pragma	once

// Main system clocks for RISC-V RP2350
// -------------------------------------

#define KCRYSTAL			12000000u		// Quartz crystal resonator (12 MHz)
#define KFREQUENCY_AHB		150000000u		// AHB bus frequency (150 MHz)
#define KFREQUENCY_TIM		1000000u		// Timers frequency (1 MHz)
#define KFREQUENCY_1GHz		1000000000u		// Reference: 1 GHz
#define KFREQUENCY_1MHz		1000000u		// Reference: 1 MHz
#define KFREQUENCY_1KHz		1000u			// Reference: 1 KHz
#define KFREQUENCY_CORE		KFREQUENCY_AHB	// RISC-V core frequency = 150 MHz
