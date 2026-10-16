/*
; nrf5340_application_uicr.
; =========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_uicr equates.
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

// UICR address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	APPROTECT;
	volatile	uint32_t	RESERVED0[3];
	volatile	uint32_t	VREGHVOUT;
	volatile	uint32_t	HFXOCNT;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	SECUREAPPROTECT;
	volatile	uint32_t	ERASEPROTECT;
	volatile	uint32_t	TINSTANCE;
	volatile	uint32_t	NFCPINS;
	volatile	uint32_t	RESERVED2[53];
	volatile	uint32_t	OTP[192];
	volatile	uint32_t	KEYSLOT_CONFIG0_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG0_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG1_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG1_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG2_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG2_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG3_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG3_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG4_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG4_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG5_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG5_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG6_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG6_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG7_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG7_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG8_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG8_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG9_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG9_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG10_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG10_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG11_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG11_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG12_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG12_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG13_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG13_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG14_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG14_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG15_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG15_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG16_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG16_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG17_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG17_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG18_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG18_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG19_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG19_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG20_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG20_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG21_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG21_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG22_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG22_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG23_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG23_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG24_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG24_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG25_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG25_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG26_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG26_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG27_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG27_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG28_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG28_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG29_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG29_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG30_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG30_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG31_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG31_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG32_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG32_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG33_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG33_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG34_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG34_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG35_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG35_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG36_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG36_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG37_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG37_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG38_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG38_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG39_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG39_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG40_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG40_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG41_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG41_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG42_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG42_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG43_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG43_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG44_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG44_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG45_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG45_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG46_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG46_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG47_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG47_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG48_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG48_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG49_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG49_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG50_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG50_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG51_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG51_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG52_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG52_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG53_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG53_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG54_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG54_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG55_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG55_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG56_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG56_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG57_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG57_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG58_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG58_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG59_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG59_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG60_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG60_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG61_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG61_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG62_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG62_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG63_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG63_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG64_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG64_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG65_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG65_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG66_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG66_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG67_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG67_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG68_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG68_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG69_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG69_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG70_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG70_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG71_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG71_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG72_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG72_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG73_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG73_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG74_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG74_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG75_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG75_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG76_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG76_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG77_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG77_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG78_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG78_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG79_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG79_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG80_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG80_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG81_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG81_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG82_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG82_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG83_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG83_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG84_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG84_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG85_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG85_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG86_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG86_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG87_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG87_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG88_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG88_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG89_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG89_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG90_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG90_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG91_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG91_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG92_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG92_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG93_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG93_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG94_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG94_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG95_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG95_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG96_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG96_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG97_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG97_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG98_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG98_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG99_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG99_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG100_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG100_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG101_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG101_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG102_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG102_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG103_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG103_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG104_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG104_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG105_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG105_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG106_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG106_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG107_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG107_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG108_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG108_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG109_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG109_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG110_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG110_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG111_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG111_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG112_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG112_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG113_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG113_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG114_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG114_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG115_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG115_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG116_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG116_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG117_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG117_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG118_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG118_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG119_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG119_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG120_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG120_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG121_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG121_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG122_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG122_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG123_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG123_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG124_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG124_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG125_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG125_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG126_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG126_PERM;
	volatile	uint32_t	KEYSLOT_CONFIG127_DEST;
	volatile	uint32_t	KEYSLOT_CONFIG127_PERM;
	volatile	uint32_t	KEYSLOT_KEY0_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY1_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY2_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY3_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY4_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY5_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY6_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY7_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY8_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY9_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY10_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY11_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY12_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY13_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY14_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY15_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY16_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY17_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY18_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY19_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY20_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY21_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY22_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY23_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY24_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY25_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY26_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY27_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY28_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY29_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY30_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY31_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY32_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY33_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY34_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY35_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY36_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY37_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY38_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY39_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY40_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY41_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY42_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY43_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY44_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY45_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY46_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY47_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY48_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY49_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY50_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY51_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY52_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY53_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY54_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY55_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY56_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY57_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY58_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY59_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY60_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY61_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY62_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY63_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY64_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY65_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY66_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY67_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY68_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY69_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY70_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY71_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY72_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY73_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY74_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY75_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY76_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY77_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY78_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY79_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY80_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY81_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY82_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY83_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY84_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY85_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY86_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY87_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY88_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY89_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY90_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY91_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY92_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY93_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY94_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY95_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY96_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY97_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY98_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY99_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY100_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY101_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY102_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY103_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY104_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY105_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY106_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY107_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY108_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY109_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY110_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY111_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY112_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY113_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY114_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY115_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY116_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY117_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY118_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY119_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY120_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY121_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY122_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY123_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY124_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY125_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY126_VALUE[4];
	volatile	uint32_t	KEYSLOT_KEY127_VALUE[4];
} UICR_TypeDef;

#if (defined(__cplusplus))
#define	UICR_S	reinterpret_cast<UICR_TypeDef *>(0x00FF8000u)

#else
#define	UICR_S	((UICR_TypeDef *)0x00FF8000u)
#endif

// APPROTECT Configuration

#define	UICR_APPROTECT_PALL							(0xFFFFFFFFu<<0)
#define	UICR_APPROTECT_PALL_0						(0x1u<<0)
#define	UICR_APPROTECT_PALL_UNPROTECTED				(0x50FA50FAu<<0)
#define	UICR_APPROTECT_PALL_PROTECTED				(0x0u<<0)

// VREGHVOUT Configuration

#define	UICR_VREGHVOUT_VREGHVOUT					(0x7u<<0)
#define	UICR_VREGHVOUT_VREGHVOUT_0					(0x1u<<0)
#define	UICR_VREGHVOUT_VREGHVOUT_1V8				(0x0u<<0)
#define	UICR_VREGHVOUT_VREGHVOUT_2V1				(0x1u<<0)
#define	UICR_VREGHVOUT_VREGHVOUT_2V4				(0x2u<<0)
#define	UICR_VREGHVOUT_VREGHVOUT_2V7				(0x3u<<0)
#define	UICR_VREGHVOUT_VREGHVOUT_3V0				(0x4u<<0)
#define	UICR_VREGHVOUT_VREGHVOUT_3V3				(0x5u<<0)
#define	UICR_VREGHVOUT_VREGHVOUT_DEFAULT			(0x7u<<0)

// HFXOCNT Configuration

#define	UICR_HFXOCNT_HFXOCNT						(0xFFu<<0)
#define	UICR_HFXOCNT_HFXOCNT_0						(0x1u<<0)
#define	UICR_HFXOCNT_HFXOCNT_MINDEBOUNCETIME		(0x0u<<0)
#define	UICR_HFXOCNT_HFXOCNT_MAXDEBOUNCETIME		(0xFEu<<0)
#define	UICR_HFXOCNT_HFXOCNT_DEFAULTDEBOUNCETIME	(0xFFu<<0)

// SECUREAPPROTECT Configuration

#define	UICR_SECUREAPPROTECT_PALL					(0xFFFFFFFFu<<0)
#define	UICR_SECUREAPPROTECT_PALL_0					(0x1u<<0)
#define	UICR_SECUREAPPROTECT_PALL_UNPROTECTED		(0x50FA50FAu<<0)
#define	UICR_SECUREAPPROTECT_PALL_PROTECTED			(0x0u<<0)

// ERASEPROTECT Configuration

#define	UICR_ERASEPROTECT_PALL						(0xFFFFFFFFu<<0)
#define	UICR_ERASEPROTECT_PALL_0					(0x1u<<0)
#define	UICR_ERASEPROTECT_PALL_UNPROTECTED			(0xFFFFFFFFu<<0)
#define	UICR_ERASEPROTECT_PALL_PROTECTED			(0x0u<<0)

// TINSTANCE Configuration

#define	UICR_TINSTANCE_TINSTANCE					(0xFu<<28)
#define	UICR_TINSTANCE_TINSTANCE_0					(0x1u<<28)

// NFCPINS Configuration

#define	UICR_NFCPINS_PROTECT						(0x1u<<0)
#define	UICR_NFCPINS_PROTECT_DISABLED				(0x0u<<0)
#define	UICR_NFCPINS_PROTECT_NFC					(0x1u<<0)

// OTP Configuration

#define	UICR_OTP_UPPER								(0xFFFFu<<16)
#define	UICR_OTP_UPPER_0							(0x1u<<16)
#define	UICR_OTP_LOWER								(0xFFFFu<<0)
#define	UICR_OTP_LOWER_0							(0x1u<<0)

// DEST Configuration

#define	UICR_KEYSLOT_CONFIG_DEST_DEST				(0xFFFFFFFFu<<0)
#define	UICR_KEYSLOT_CONFIG_DEST_DEST_0				(0x1u<<0)

// PERM Configuration

#define	UICR_KEYSLOT_CONFIG_PERM_STATE				(0x1u<<16)
#define	UICR_KEYSLOT_CONFIG_PERM_PUSH				(0x1u<<2)
#define	UICR_KEYSLOT_CONFIG_PERM_READ				(0x1u<<1)
#define	UICR_KEYSLOT_CONFIG_PERM_WRITE				(0x1u<<0)
#define	UICR_KEYSLOT_CONFIG_PERM_STATE_REVOKED		(0x0u<<16)
#define	UICR_KEYSLOT_CONFIG_PERM_STATE_ACTIVE		(0x1u<<16)
#define	UICR_KEYSLOT_CONFIG_PERM_PUSH_DISABLED		(0x0u<<2)
#define	UICR_KEYSLOT_CONFIG_PERM_PUSH_ENABLED		(0x1u<<2)
#define	UICR_KEYSLOT_CONFIG_PERM_READ_DISABLED		(0x0u<<1)
#define	UICR_KEYSLOT_CONFIG_PERM_READ_ENABLED		(0x1u<<1)
#define	UICR_KEYSLOT_CONFIG_PERM_WRITE_DISABLED		(0x0u<<0)
#define	UICR_KEYSLOT_CONFIG_PERM_WRITE_ENABLED		(0x1u<<0)

// VALUE Configuration

#define	UICR_KEYSLOT_KEY_VALUE_VALUE				(0xFFFFFFFFu<<0)
#define	UICR_KEYSLOT_KEY_VALUE_VALUE_0				(0x1u<<0)
