/*
; rv32_bumblebee.
; ===============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-02-13
; Modifs:
;
; Project:	uKOS-X
; Goal:		rv32_bumblebee equates.
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

#define	RVBB_CSR_MTVT			0x307u					//
#define	RVBB_CSR_MNVEC			0x7C3u					//
#define	RVBB_CSR_MSUBM			0x7C4u					//
#define	RVBB_CSR_MMISC_CTL		0x7D0u					//
#define	RVBB_CSR_MSAVESTATUS	0x7D6u					//
#define	RVBB_CSR_MSAVEEPC1		0x7D7u					//
#define	RVBB_CSR_MSAVECAUSE1	0x7D8u					//
#define	RVBB_CSR_MSAVEEPC2		0x7D9u					//
#define	RVBB_CSR_MSAVECAUSE2	0x7DAu					//
#define	RVBB_CSR_PUSHMSUBM		0x7EBu					//
#define	RVBB_CSR_MTVT2			0x7ECu					//
#define	RVBB_CSR_JALMNXTI		0x7EDu					//
#define	RVBB_CSR_PUSHMCAUSE		0x7EEu					//
#define	RVBB_CSR_PUSHMEPC		0x7EFu					//
#define	RVBB_CSR_WFE			0x810u					//
#define	RVBB_CSR_SLEEPVALUE		0x811u					//
#define	RVBB_CSR_TXEVT			0x812u					//

#define	RVBB_MCAUSE_MINHV		(1U<<30)				//
#define	RVBB_MCAUSE_MPP(m)		((((m) & 0x3u)<<28))	//
#define	RVBB_MCAUSE_MPIE		(1U<<27)				//
