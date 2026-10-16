/*
; nrf5340_application_spu.
; ========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_spu equates.
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

// SPU address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	RESERVED0[64];
	volatile	uint32_t	EVENTS_RAMACCERR;
	volatile	uint32_t	EVENTS_FLASHACCERR;
	volatile	uint32_t	EVENTS_PERIPHACCERR;
	volatile	uint32_t	RESERVED1[29];
	volatile	uint32_t	PUBLISH_RAMACCERR;
	volatile	uint32_t	PUBLISH_FLASHACCERR;
	volatile	uint32_t	PUBLISH_PERIPHACCERR;
	volatile	uint32_t	RESERVED2[93];
	volatile	uint32_t	INTEN;
	volatile	uint32_t	INTENSET;
	volatile	uint32_t	INTENCLR;
	volatile	uint32_t	RESERVED3[61];
	volatile	uint32_t	CAP;
	volatile	uint32_t	CPULOCK;
	volatile	uint32_t	RESERVED4[14];
	volatile	uint32_t	EXTDOMAIN0_PERM;
	volatile	uint32_t	RESERVED5[15];
	volatile	uint32_t	DPPI0_PERM;
	volatile	uint32_t	DPPI0_LOCK;
	volatile	uint32_t	RESERVED6[14];
	volatile	uint32_t	GPIOPORT0_PERM;
	volatile	uint32_t	GPIOPORT0_LOCK;
	volatile	uint32_t	GPIOPORT1_PERM;
	volatile	uint32_t	GPIOPORT1_LOCK;
	volatile	uint32_t	RESERVED7[12];
	volatile	uint32_t	FLASHNSC0_REGION;
	volatile	uint32_t	FLASHNSC0_SIZE;
	volatile	uint32_t	FLASHNSC1_REGION;
	volatile	uint32_t	FLASHNSC1_SIZE;
	volatile	uint32_t	RESERVED8[12];
	volatile	uint32_t	RAMNSC0_REGION;
	volatile	uint32_t	RAMNSC0_SIZE;
	volatile	uint32_t	RAMNSC1_REGION;
	volatile	uint32_t	RAMNSC1_SIZE;
	volatile	uint32_t	RESERVED9[44];
	volatile	uint32_t	FLASHREGION0_PERM;
	volatile	uint32_t	FLASHREGION1_PERM;
	volatile	uint32_t	FLASHREGION2_PERM;
	volatile	uint32_t	FLASHREGION3_PERM;
	volatile	uint32_t	FLASHREGION4_PERM;
	volatile	uint32_t	FLASHREGION5_PERM;
	volatile	uint32_t	FLASHREGION6_PERM;
	volatile	uint32_t	FLASHREGION7_PERM;
	volatile	uint32_t	FLASHREGION8_PERM;
	volatile	uint32_t	FLASHREGION9_PERM;
	volatile	uint32_t	FLASHREGION10_PERM;
	volatile	uint32_t	FLASHREGION11_PERM;
	volatile	uint32_t	FLASHREGION12_PERM;
	volatile	uint32_t	FLASHREGION13_PERM;
	volatile	uint32_t	FLASHREGION14_PERM;
	volatile	uint32_t	FLASHREGION15_PERM;
	volatile	uint32_t	FLASHREGION16_PERM;
	volatile	uint32_t	FLASHREGION17_PERM;
	volatile	uint32_t	FLASHREGION18_PERM;
	volatile	uint32_t	FLASHREGION19_PERM;
	volatile	uint32_t	FLASHREGION20_PERM;
	volatile	uint32_t	FLASHREGION21_PERM;
	volatile	uint32_t	FLASHREGION22_PERM;
	volatile	uint32_t	FLASHREGION23_PERM;
	volatile	uint32_t	FLASHREGION24_PERM;
	volatile	uint32_t	FLASHREGION25_PERM;
	volatile	uint32_t	FLASHREGION26_PERM;
	volatile	uint32_t	FLASHREGION27_PERM;
	volatile	uint32_t	FLASHREGION28_PERM;
	volatile	uint32_t	FLASHREGION29_PERM;
	volatile	uint32_t	FLASHREGION30_PERM;
	volatile	uint32_t	FLASHREGION31_PERM;
	volatile	uint32_t	FLASHREGION32_PERM;
	volatile	uint32_t	FLASHREGION33_PERM;
	volatile	uint32_t	FLASHREGION34_PERM;
	volatile	uint32_t	FLASHREGION35_PERM;
	volatile	uint32_t	FLASHREGION36_PERM;
	volatile	uint32_t	FLASHREGION37_PERM;
	volatile	uint32_t	FLASHREGION38_PERM;
	volatile	uint32_t	FLASHREGION39_PERM;
	volatile	uint32_t	FLASHREGION40_PERM;
	volatile	uint32_t	FLASHREGION41_PERM;
	volatile	uint32_t	FLASHREGION42_PERM;
	volatile	uint32_t	FLASHREGION43_PERM;
	volatile	uint32_t	FLASHREGION44_PERM;
	volatile	uint32_t	FLASHREGION45_PERM;
	volatile	uint32_t	FLASHREGION46_PERM;
	volatile	uint32_t	FLASHREGION47_PERM;
	volatile	uint32_t	FLASHREGION48_PERM;
	volatile	uint32_t	FLASHREGION49_PERM;
	volatile	uint32_t	FLASHREGION50_PERM;
	volatile	uint32_t	FLASHREGION51_PERM;
	volatile	uint32_t	FLASHREGION52_PERM;
	volatile	uint32_t	FLASHREGION53_PERM;
	volatile	uint32_t	FLASHREGION54_PERM;
	volatile	uint32_t	FLASHREGION55_PERM;
	volatile	uint32_t	FLASHREGION56_PERM;
	volatile	uint32_t	FLASHREGION57_PERM;
	volatile	uint32_t	FLASHREGION58_PERM;
	volatile	uint32_t	FLASHREGION59_PERM;
	volatile	uint32_t	FLASHREGION60_PERM;
	volatile	uint32_t	FLASHREGION61_PERM;
	volatile	uint32_t	FLASHREGION62_PERM;
	volatile	uint32_t	FLASHREGION63_PERM;
	volatile	uint32_t	RAMREGION0_PERM;
	volatile	uint32_t	RAMREGION1_PERM;
	volatile	uint32_t	RAMREGION2_PERM;
	volatile	uint32_t	RAMREGION3_PERM;
	volatile	uint32_t	RAMREGION4_PERM;
	volatile	uint32_t	RAMREGION5_PERM;
	volatile	uint32_t	RAMREGION6_PERM;
	volatile	uint32_t	RAMREGION7_PERM;
	volatile	uint32_t	RAMREGION8_PERM;
	volatile	uint32_t	RAMREGION9_PERM;
	volatile	uint32_t	RAMREGION10_PERM;
	volatile	uint32_t	RAMREGION11_PERM;
	volatile	uint32_t	RAMREGION12_PERM;
	volatile	uint32_t	RAMREGION13_PERM;
	volatile	uint32_t	RAMREGION14_PERM;
	volatile	uint32_t	RAMREGION15_PERM;
	volatile	uint32_t	RAMREGION16_PERM;
	volatile	uint32_t	RAMREGION17_PERM;
	volatile	uint32_t	RAMREGION18_PERM;
	volatile	uint32_t	RAMREGION19_PERM;
	volatile	uint32_t	RAMREGION20_PERM;
	volatile	uint32_t	RAMREGION21_PERM;
	volatile	uint32_t	RAMREGION22_PERM;
	volatile	uint32_t	RAMREGION23_PERM;
	volatile	uint32_t	RAMREGION24_PERM;
	volatile	uint32_t	RAMREGION25_PERM;
	volatile	uint32_t	RAMREGION26_PERM;
	volatile	uint32_t	RAMREGION27_PERM;
	volatile	uint32_t	RAMREGION28_PERM;
	volatile	uint32_t	RAMREGION29_PERM;
	volatile	uint32_t	RAMREGION30_PERM;
	volatile	uint32_t	RAMREGION31_PERM;
	volatile	uint32_t	RAMREGION32_PERM;
	volatile	uint32_t	RAMREGION33_PERM;
	volatile	uint32_t	RAMREGION34_PERM;
	volatile	uint32_t	RAMREGION35_PERM;
	volatile	uint32_t	RAMREGION36_PERM;
	volatile	uint32_t	RAMREGION37_PERM;
	volatile	uint32_t	RAMREGION38_PERM;
	volatile	uint32_t	RAMREGION39_PERM;
	volatile	uint32_t	RAMREGION40_PERM;
	volatile	uint32_t	RAMREGION41_PERM;
	volatile	uint32_t	RAMREGION42_PERM;
	volatile	uint32_t	RAMREGION43_PERM;
	volatile	uint32_t	RAMREGION44_PERM;
	volatile	uint32_t	RAMREGION45_PERM;
	volatile	uint32_t	RAMREGION46_PERM;
	volatile	uint32_t	RAMREGION47_PERM;
	volatile	uint32_t	RAMREGION48_PERM;
	volatile	uint32_t	RAMREGION49_PERM;
	volatile	uint32_t	RAMREGION50_PERM;
	volatile	uint32_t	RAMREGION51_PERM;
	volatile	uint32_t	RAMREGION52_PERM;
	volatile	uint32_t	RAMREGION53_PERM;
	volatile	uint32_t	RAMREGION54_PERM;
	volatile	uint32_t	RAMREGION55_PERM;
	volatile	uint32_t	RAMREGION56_PERM;
	volatile	uint32_t	RAMREGION57_PERM;
	volatile	uint32_t	RAMREGION58_PERM;
	volatile	uint32_t	RAMREGION59_PERM;
	volatile	uint32_t	RAMREGION60_PERM;
	volatile	uint32_t	RAMREGION61_PERM;
	volatile	uint32_t	RAMREGION62_PERM;
	volatile	uint32_t	RAMREGION63_PERM;
	volatile	uint32_t	PERIPHID0_PERM;
	volatile	uint32_t	PERIPHID1_PERM;
	volatile	uint32_t	PERIPHID2_PERM;
	volatile	uint32_t	PERIPHID3_PERM;
	volatile	uint32_t	PERIPHID4_PERM;
	volatile	uint32_t	PERIPHID5_PERM;
	volatile	uint32_t	PERIPHID6_PERM;
	volatile	uint32_t	PERIPHID7_PERM;
	volatile	uint32_t	PERIPHID8_PERM;
	volatile	uint32_t	PERIPHID9_PERM;
	volatile	uint32_t	PERIPHID10_PERM;
	volatile	uint32_t	PERIPHID11_PERM;
	volatile	uint32_t	PERIPHID12_PERM;
	volatile	uint32_t	PERIPHID13_PERM;
	volatile	uint32_t	PERIPHID14_PERM;
	volatile	uint32_t	PERIPHID15_PERM;
	volatile	uint32_t	PERIPHID16_PERM;
	volatile	uint32_t	PERIPHID17_PERM;
	volatile	uint32_t	PERIPHID18_PERM;
	volatile	uint32_t	PERIPHID19_PERM;
	volatile	uint32_t	PERIPHID20_PERM;
	volatile	uint32_t	PERIPHID21_PERM;
	volatile	uint32_t	PERIPHID22_PERM;
	volatile	uint32_t	PERIPHID23_PERM;
	volatile	uint32_t	PERIPHID24_PERM;
	volatile	uint32_t	PERIPHID25_PERM;
	volatile	uint32_t	PERIPHID26_PERM;
	volatile	uint32_t	PERIPHID27_PERM;
	volatile	uint32_t	PERIPHID28_PERM;
	volatile	uint32_t	PERIPHID29_PERM;
	volatile	uint32_t	PERIPHID30_PERM;
	volatile	uint32_t	PERIPHID31_PERM;
	volatile	uint32_t	PERIPHID32_PERM;
	volatile	uint32_t	PERIPHID33_PERM;
	volatile	uint32_t	PERIPHID34_PERM;
	volatile	uint32_t	PERIPHID35_PERM;
	volatile	uint32_t	PERIPHID36_PERM;
	volatile	uint32_t	PERIPHID37_PERM;
	volatile	uint32_t	PERIPHID38_PERM;
	volatile	uint32_t	PERIPHID39_PERM;
	volatile	uint32_t	PERIPHID40_PERM;
	volatile	uint32_t	PERIPHID41_PERM;
	volatile	uint32_t	PERIPHID42_PERM;
	volatile	uint32_t	PERIPHID43_PERM;
	volatile	uint32_t	PERIPHID44_PERM;
	volatile	uint32_t	PERIPHID45_PERM;
	volatile	uint32_t	PERIPHID46_PERM;
	volatile	uint32_t	PERIPHID47_PERM;
	volatile	uint32_t	PERIPHID48_PERM;
	volatile	uint32_t	PERIPHID49_PERM;
	volatile	uint32_t	PERIPHID50_PERM;
	volatile	uint32_t	PERIPHID51_PERM;
	volatile	uint32_t	PERIPHID52_PERM;
	volatile	uint32_t	PERIPHID53_PERM;
	volatile	uint32_t	PERIPHID54_PERM;
	volatile	uint32_t	PERIPHID55_PERM;
	volatile	uint32_t	PERIPHID56_PERM;
	volatile	uint32_t	PERIPHID57_PERM;
	volatile	uint32_t	PERIPHID58_PERM;
	volatile	uint32_t	PERIPHID59_PERM;
	volatile	uint32_t	PERIPHID60_PERM;
	volatile	uint32_t	PERIPHID61_PERM;
	volatile	uint32_t	PERIPHID62_PERM;
	volatile	uint32_t	PERIPHID63_PERM;
	volatile	uint32_t	PERIPHID64_PERM;
	volatile	uint32_t	PERIPHID65_PERM;
	volatile	uint32_t	PERIPHID66_PERM;
	volatile	uint32_t	PERIPHID67_PERM;
	volatile	uint32_t	PERIPHID68_PERM;
	volatile	uint32_t	PERIPHID69_PERM;
	volatile	uint32_t	PERIPHID70_PERM;
	volatile	uint32_t	PERIPHID71_PERM;
	volatile	uint32_t	PERIPHID72_PERM;
	volatile	uint32_t	PERIPHID73_PERM;
	volatile	uint32_t	PERIPHID74_PERM;
	volatile	uint32_t	PERIPHID75_PERM;
	volatile	uint32_t	PERIPHID76_PERM;
	volatile	uint32_t	PERIPHID77_PERM;
	volatile	uint32_t	PERIPHID78_PERM;
	volatile	uint32_t	PERIPHID79_PERM;
	volatile	uint32_t	PERIPHID80_PERM;
	volatile	uint32_t	PERIPHID81_PERM;
	volatile	uint32_t	PERIPHID82_PERM;
	volatile	uint32_t	PERIPHID83_PERM;
	volatile	uint32_t	PERIPHID84_PERM;
	volatile	uint32_t	PERIPHID85_PERM;
	volatile	uint32_t	PERIPHID86_PERM;
	volatile	uint32_t	PERIPHID87_PERM;
	volatile	uint32_t	PERIPHID88_PERM;
	volatile	uint32_t	PERIPHID89_PERM;
	volatile	uint32_t	PERIPHID90_PERM;
	volatile	uint32_t	PERIPHID91_PERM;
	volatile	uint32_t	PERIPHID92_PERM;
	volatile	uint32_t	PERIPHID93_PERM;
	volatile	uint32_t	PERIPHID94_PERM;
	volatile	uint32_t	PERIPHID95_PERM;
	volatile	uint32_t	PERIPHID96_PERM;
	volatile	uint32_t	PERIPHID97_PERM;
	volatile	uint32_t	PERIPHID98_PERM;
	volatile	uint32_t	PERIPHID99_PERM;
	volatile	uint32_t	PERIPHID100_PERM;
	volatile	uint32_t	PERIPHID101_PERM;
	volatile	uint32_t	PERIPHID102_PERM;
	volatile	uint32_t	PERIPHID103_PERM;
	volatile	uint32_t	PERIPHID104_PERM;
	volatile	uint32_t	PERIPHID105_PERM;
	volatile	uint32_t	PERIPHID106_PERM;
	volatile	uint32_t	PERIPHID107_PERM;
	volatile	uint32_t	PERIPHID108_PERM;
	volatile	uint32_t	PERIPHID109_PERM;
	volatile	uint32_t	PERIPHID110_PERM;
	volatile	uint32_t	PERIPHID111_PERM;
	volatile	uint32_t	PERIPHID112_PERM;
	volatile	uint32_t	PERIPHID113_PERM;
	volatile	uint32_t	PERIPHID114_PERM;
	volatile	uint32_t	PERIPHID115_PERM;
	volatile	uint32_t	PERIPHID116_PERM;
	volatile	uint32_t	PERIPHID117_PERM;
	volatile	uint32_t	PERIPHID118_PERM;
	volatile	uint32_t	PERIPHID119_PERM;
	volatile	uint32_t	PERIPHID120_PERM;
	volatile	uint32_t	PERIPHID121_PERM;
	volatile	uint32_t	PERIPHID122_PERM;
	volatile	uint32_t	PERIPHID123_PERM;
	volatile	uint32_t	PERIPHID124_PERM;
	volatile	uint32_t	PERIPHID125_PERM;
	volatile	uint32_t	PERIPHID126_PERM;
	volatile	uint32_t	PERIPHID127_PERM;
	volatile	uint32_t	PERIPHID128_PERM;
	volatile	uint32_t	PERIPHID129_PERM;
	volatile	uint32_t	PERIPHID130_PERM;
	volatile	uint32_t	PERIPHID131_PERM;
	volatile	uint32_t	PERIPHID132_PERM;
	volatile	uint32_t	PERIPHID133_PERM;
	volatile	uint32_t	PERIPHID134_PERM;
	volatile	uint32_t	PERIPHID135_PERM;
	volatile	uint32_t	PERIPHID136_PERM;
	volatile	uint32_t	PERIPHID137_PERM;
	volatile	uint32_t	PERIPHID138_PERM;
	volatile	uint32_t	PERIPHID139_PERM;
	volatile	uint32_t	PERIPHID140_PERM;
	volatile	uint32_t	PERIPHID141_PERM;
	volatile	uint32_t	PERIPHID142_PERM;
	volatile	uint32_t	PERIPHID143_PERM;
	volatile	uint32_t	PERIPHID144_PERM;
	volatile	uint32_t	PERIPHID145_PERM;
	volatile	uint32_t	PERIPHID146_PERM;
	volatile	uint32_t	PERIPHID147_PERM;
	volatile	uint32_t	PERIPHID148_PERM;
	volatile	uint32_t	PERIPHID149_PERM;
	volatile	uint32_t	PERIPHID150_PERM;
	volatile	uint32_t	PERIPHID151_PERM;
	volatile	uint32_t	PERIPHID152_PERM;
	volatile	uint32_t	PERIPHID153_PERM;
	volatile	uint32_t	PERIPHID154_PERM;
	volatile	uint32_t	PERIPHID155_PERM;
	volatile	uint32_t	PERIPHID156_PERM;
	volatile	uint32_t	PERIPHID157_PERM;
	volatile	uint32_t	PERIPHID158_PERM;
	volatile	uint32_t	PERIPHID159_PERM;
	volatile	uint32_t	PERIPHID160_PERM;
	volatile	uint32_t	PERIPHID161_PERM;
	volatile	uint32_t	PERIPHID162_PERM;
	volatile	uint32_t	PERIPHID163_PERM;
	volatile	uint32_t	PERIPHID164_PERM;
	volatile	uint32_t	PERIPHID165_PERM;
	volatile	uint32_t	PERIPHID166_PERM;
	volatile	uint32_t	PERIPHID167_PERM;
	volatile	uint32_t	PERIPHID168_PERM;
	volatile	uint32_t	PERIPHID169_PERM;
	volatile	uint32_t	PERIPHID170_PERM;
	volatile	uint32_t	PERIPHID171_PERM;
	volatile	uint32_t	PERIPHID172_PERM;
	volatile	uint32_t	PERIPHID173_PERM;
	volatile	uint32_t	PERIPHID174_PERM;
	volatile	uint32_t	PERIPHID175_PERM;
	volatile	uint32_t	PERIPHID176_PERM;
	volatile	uint32_t	PERIPHID177_PERM;
	volatile	uint32_t	PERIPHID178_PERM;
	volatile	uint32_t	PERIPHID179_PERM;
	volatile	uint32_t	PERIPHID180_PERM;
	volatile	uint32_t	PERIPHID181_PERM;
	volatile	uint32_t	PERIPHID182_PERM;
	volatile	uint32_t	PERIPHID183_PERM;
	volatile	uint32_t	PERIPHID184_PERM;
	volatile	uint32_t	PERIPHID185_PERM;
	volatile	uint32_t	PERIPHID186_PERM;
	volatile	uint32_t	PERIPHID187_PERM;
	volatile	uint32_t	PERIPHID188_PERM;
	volatile	uint32_t	PERIPHID189_PERM;
	volatile	uint32_t	PERIPHID190_PERM;
	volatile	uint32_t	PERIPHID191_PERM;
	volatile	uint32_t	PERIPHID192_PERM;
	volatile	uint32_t	PERIPHID193_PERM;
	volatile	uint32_t	PERIPHID194_PERM;
	volatile	uint32_t	PERIPHID195_PERM;
	volatile	uint32_t	PERIPHID196_PERM;
	volatile	uint32_t	PERIPHID197_PERM;
	volatile	uint32_t	PERIPHID198_PERM;
	volatile	uint32_t	PERIPHID199_PERM;
	volatile	uint32_t	PERIPHID200_PERM;
	volatile	uint32_t	PERIPHID201_PERM;
	volatile	uint32_t	PERIPHID202_PERM;
	volatile	uint32_t	PERIPHID203_PERM;
	volatile	uint32_t	PERIPHID204_PERM;
	volatile	uint32_t	PERIPHID205_PERM;
	volatile	uint32_t	PERIPHID206_PERM;
	volatile	uint32_t	PERIPHID207_PERM;
	volatile	uint32_t	PERIPHID208_PERM;
	volatile	uint32_t	PERIPHID209_PERM;
	volatile	uint32_t	PERIPHID210_PERM;
	volatile	uint32_t	PERIPHID211_PERM;
	volatile	uint32_t	PERIPHID212_PERM;
	volatile	uint32_t	PERIPHID213_PERM;
	volatile	uint32_t	PERIPHID214_PERM;
	volatile	uint32_t	PERIPHID215_PERM;
	volatile	uint32_t	PERIPHID216_PERM;
	volatile	uint32_t	PERIPHID217_PERM;
	volatile	uint32_t	PERIPHID218_PERM;
	volatile	uint32_t	PERIPHID219_PERM;
	volatile	uint32_t	PERIPHID220_PERM;
	volatile	uint32_t	PERIPHID221_PERM;
	volatile	uint32_t	PERIPHID222_PERM;
	volatile	uint32_t	PERIPHID223_PERM;
	volatile	uint32_t	PERIPHID224_PERM;
	volatile	uint32_t	PERIPHID225_PERM;
	volatile	uint32_t	PERIPHID226_PERM;
	volatile	uint32_t	PERIPHID227_PERM;
	volatile	uint32_t	PERIPHID228_PERM;
	volatile	uint32_t	PERIPHID229_PERM;
	volatile	uint32_t	PERIPHID230_PERM;
	volatile	uint32_t	PERIPHID231_PERM;
	volatile	uint32_t	PERIPHID232_PERM;
	volatile	uint32_t	PERIPHID233_PERM;
	volatile	uint32_t	PERIPHID234_PERM;
	volatile	uint32_t	PERIPHID235_PERM;
	volatile	uint32_t	PERIPHID236_PERM;
	volatile	uint32_t	PERIPHID237_PERM;
	volatile	uint32_t	PERIPHID238_PERM;
	volatile	uint32_t	PERIPHID239_PERM;
	volatile	uint32_t	PERIPHID240_PERM;
	volatile	uint32_t	PERIPHID241_PERM;
	volatile	uint32_t	PERIPHID242_PERM;
	volatile	uint32_t	PERIPHID243_PERM;
	volatile	uint32_t	PERIPHID244_PERM;
	volatile	uint32_t	PERIPHID245_PERM;
	volatile	uint32_t	PERIPHID246_PERM;
	volatile	uint32_t	PERIPHID247_PERM;
	volatile	uint32_t	PERIPHID248_PERM;
	volatile	uint32_t	PERIPHID249_PERM;
	volatile	uint32_t	PERIPHID250_PERM;
	volatile	uint32_t	PERIPHID251_PERM;
	volatile	uint32_t	PERIPHID252_PERM;
	volatile	uint32_t	PERIPHID253_PERM;
	volatile	uint32_t	PERIPHID254_PERM;
	volatile	uint32_t	PERIPHID255_PERM;
} SPU_TypeDef;

#if (defined(__cplusplus))
#define	SPU_S	reinterpret_cast<SPU_TypeDef *>(0x50003000u)

#else
#define	SPU_S	((SPU_TypeDef *)0x50003000u)
#endif

// EVENTS_RAMACCERR Configuration

#define	SPU_EVENTS_RAMACCERR_EVENTS_RAMACCERR							(0x1u<<0)
#define	SPU_EVENTS_RAMACCERR_EVENTS_RAMACCERR_NOTGENERATED				(0x0u<<0)
#define	SPU_EVENTS_RAMACCERR_EVENTS_RAMACCERR_GENERATED					(0x1u<<0)

// EVENTS_FLASHACCERR Configuration

#define	SPU_EVENTS_FLASHACCERR_EVENTS_FLASHACCERR						(0x1u<<0)
#define	SPU_EVENTS_FLASHACCERR_EVENTS_FLASHACCERR_NOTGENERATED			(0x0u<<0)
#define	SPU_EVENTS_FLASHACCERR_EVENTS_FLASHACCERR_GENERATED				(0x1u<<0)

// EVENTS_PERIPHACCERR Configuration

#define	SPU_EVENTS_PERIPHACCERR_EVENTS_PERIPHACCERR						(0x1u<<0)
#define	SPU_EVENTS_PERIPHACCERR_EVENTS_PERIPHACCERR_NOTGENERATED		(0x0u<<0)
#define	SPU_EVENTS_PERIPHACCERR_EVENTS_PERIPHACCERR_GENERATED			(0x1u<<0)

// PUBLISH_RAMACCERR Configuration

#define	SPU_PUBLISH_RAMACCERR_EN										(0x1u<<31)
#define	SPU_PUBLISH_RAMACCERR_CHIDX										(0xFFu<<0)
#define	SPU_PUBLISH_RAMACCERR_CHIDX_0									(0x1u<<0)
#define	SPU_PUBLISH_RAMACCERR_EN_DISABLED								(0x0u<<31)
#define	SPU_PUBLISH_RAMACCERR_EN_ENABLED								(0x1u<<31)

// PUBLISH_FLASHACCERR Configuration

#define	SPU_PUBLISH_FLASHACCERR_EN										(0x1u<<31)
#define	SPU_PUBLISH_FLASHACCERR_CHIDX									(0xFFu<<0)
#define	SPU_PUBLISH_FLASHACCERR_CHIDX_0									(0x1u<<0)
#define	SPU_PUBLISH_FLASHACCERR_EN_DISABLED								(0x0u<<31)
#define	SPU_PUBLISH_FLASHACCERR_EN_ENABLED								(0x1u<<31)

// PUBLISH_PERIPHACCERR Configuration

#define	SPU_PUBLISH_PERIPHACCERR_EN										(0x1u<<31)
#define	SPU_PUBLISH_PERIPHACCERR_CHIDX									(0xFFu<<0)
#define	SPU_PUBLISH_PERIPHACCERR_CHIDX_0								(0x1u<<0)
#define	SPU_PUBLISH_PERIPHACCERR_EN_DISABLED							(0x0u<<31)
#define	SPU_PUBLISH_PERIPHACCERR_EN_ENABLED								(0x1u<<31)

// INTEN Configuration

#define	SPU_INTEN_PERIPHACCERR											(0x1u<<2)
#define	SPU_INTEN_FLASHACCERR											(0x1u<<1)
#define	SPU_INTEN_RAMACCERR												(0x1u<<0)
#define	SPU_INTEN_PERIPHACCERR_DISABLED									(0x0u<<2)
#define	SPU_INTEN_PERIPHACCERR_ENABLED									(0x1u<<2)
#define	SPU_INTEN_FLASHACCERR_DISABLED									(0x0u<<1)
#define	SPU_INTEN_FLASHACCERR_ENABLED									(0x1u<<1)
#define	SPU_INTEN_RAMACCERR_DISABLED									(0x0u<<0)
#define	SPU_INTEN_RAMACCERR_ENABLED										(0x1u<<0)

// INTENSET Configuration

#define	SPU_INTENSET_PERIPHACCERR										(0x1u<<2)
#define	SPU_INTENSET_FLASHACCERR										(0x1u<<1)
#define	SPU_INTENSET_RAMACCERR											(0x1u<<0)
#define	SPU_INTENSET_PERIPHACCERR_DISABLED								(0x0u<<2)
#define	SPU_INTENSET_PERIPHACCERR_ENABLED								(0x1u<<2)
#define	SPU_INTENSET_PERIPHACCERR_SET									(0x1u<<2)
#define	SPU_INTENSET_FLASHACCERR_DISABLED								(0x0u<<1)
#define	SPU_INTENSET_FLASHACCERR_ENABLED								(0x1u<<1)
#define	SPU_INTENSET_FLASHACCERR_SET									(0x1u<<1)
#define	SPU_INTENSET_RAMACCERR_DISABLED									(0x0u<<0)
#define	SPU_INTENSET_RAMACCERR_ENABLED									(0x1u<<0)
#define	SPU_INTENSET_RAMACCERR_SET										(0x1u<<0)

// INTENCLR Configuration

#define	SPU_INTENCLR_PERIPHACCERR										(0x1u<<2)
#define	SPU_INTENCLR_FLASHACCERR										(0x1u<<1)
#define	SPU_INTENCLR_RAMACCERR											(0x1u<<0)
#define	SPU_INTENCLR_PERIPHACCERR_DISABLED								(0x0u<<2)
#define	SPU_INTENCLR_PERIPHACCERR_ENABLED								(0x1u<<2)
#define	SPU_INTENCLR_PERIPHACCERR_CLEAR									(0x1u<<2)
#define	SPU_INTENCLR_FLASHACCERR_DISABLED								(0x0u<<1)
#define	SPU_INTENCLR_FLASHACCERR_ENABLED								(0x1u<<1)
#define	SPU_INTENCLR_FLASHACCERR_CLEAR									(0x1u<<1)
#define	SPU_INTENCLR_RAMACCERR_DISABLED									(0x0u<<0)
#define	SPU_INTENCLR_RAMACCERR_ENABLED									(0x1u<<0)
#define	SPU_INTENCLR_RAMACCERR_CLEAR									(0x1u<<0)

// CAP Configuration

#define	SPU_CAP_TZM														(0x1u<<0)
#define	SPU_CAP_TZM_NOTAVAILABLE										(0x0u<<0)
#define	SPU_CAP_TZM_ENABLED												(0x1u<<0)

// CPULOCK Configuration

#define	SPU_CPULOCK_LOCKSAU												(0x1u<<4)
#define	SPU_CPULOCK_LOCKNSMPU											(0x1u<<3)
#define	SPU_CPULOCK_LOCKSMPU											(0x1u<<2)
#define	SPU_CPULOCK_LOCKNSVTOR											(0x1u<<1)
#define	SPU_CPULOCK_LOCKSVTAIRCR										(0x1u<<0)
#define	SPU_CPULOCK_LOCKSAU_LOCKED										(0x1u<<4)
#define	SPU_CPULOCK_LOCKSAU_UNLOCKED									(0x0u<<4)
#define	SPU_CPULOCK_LOCKNSMPU_LOCKED									(0x1u<<3)
#define	SPU_CPULOCK_LOCKNSMPU_UNLOCKED									(0x0u<<3)
#define	SPU_CPULOCK_LOCKSMPU_LOCKED										(0x1u<<2)
#define	SPU_CPULOCK_LOCKSMPU_UNLOCKED									(0x0u<<2)
#define	SPU_CPULOCK_LOCKNSVTOR_LOCKED									(0x1u<<1)
#define	SPU_CPULOCK_LOCKNSVTOR_UNLOCKED									(0x0u<<1)
#define	SPU_CPULOCK_LOCKSVTAIRCR_LOCKED									(0x1u<<0)
#define	SPU_CPULOCK_LOCKSVTAIRCR_UNLOCKED								(0x0u<<0)

// PERM Configuration

#define	SPU_EXTDOMAIN_PERM_LOCK											(0x1u<<8)
#define	SPU_EXTDOMAIN_PERM_SECATTR										(0x1u<<4)
#define	SPU_EXTDOMAIN_PERM_SECUREMAPPING								(0x3u<<0)
#define	SPU_EXTDOMAIN_PERM_SECUREMAPPING_0								(0x1u<<0)
#define	SPU_EXTDOMAIN_PERM_LOCK_UNLOCKED								(0x0u<<8)
#define	SPU_EXTDOMAIN_PERM_LOCK_LOCKED									(0x1u<<8)
#define	SPU_EXTDOMAIN_PERM_SECATTR_NONSECURE							(0x0u<<4)
#define	SPU_EXTDOMAIN_PERM_SECATTR_SECURE								(0x1u<<4)
#define	SPU_EXTDOMAIN_PERM_SECUREMAPPING_NONSECURE						(0x0u<<0)
#define	SPU_EXTDOMAIN_PERM_SECUREMAPPING_SECURE							(0x1u<<0)
#define	SPU_EXTDOMAIN_PERM_SECUREMAPPING_USERSELECTABLE					(0x2u<<0)

// PERM Configuration

#define	SPU_DPPI_PERM_CHANNEL31											(0x1u<<31)
#define	SPU_DPPI_PERM_CHANNEL30											(0x1u<<30)
#define	SPU_DPPI_PERM_CHANNEL29											(0x1u<<29)
#define	SPU_DPPI_PERM_CHANNEL28											(0x1u<<28)
#define	SPU_DPPI_PERM_CHANNEL27											(0x1u<<27)
#define	SPU_DPPI_PERM_CHANNEL26											(0x1u<<26)
#define	SPU_DPPI_PERM_CHANNEL25											(0x1u<<25)
#define	SPU_DPPI_PERM_CHANNEL24											(0x1u<<24)
#define	SPU_DPPI_PERM_CHANNEL23											(0x1u<<23)
#define	SPU_DPPI_PERM_CHANNEL22											(0x1u<<22)
#define	SPU_DPPI_PERM_CHANNEL21											(0x1u<<21)
#define	SPU_DPPI_PERM_CHANNEL20											(0x1u<<20)
#define	SPU_DPPI_PERM_CHANNEL19											(0x1u<<19)
#define	SPU_DPPI_PERM_CHANNEL18											(0x1u<<18)
#define	SPU_DPPI_PERM_CHANNEL17											(0x1u<<17)
#define	SPU_DPPI_PERM_CHANNEL16											(0x1u<<16)
#define	SPU_DPPI_PERM_CHANNEL15											(0x1u<<15)
#define	SPU_DPPI_PERM_CHANNEL14											(0x1u<<14)
#define	SPU_DPPI_PERM_CHANNEL13											(0x1u<<13)
#define	SPU_DPPI_PERM_CHANNEL12											(0x1u<<12)
#define	SPU_DPPI_PERM_CHANNEL11											(0x1u<<11)
#define	SPU_DPPI_PERM_CHANNEL10											(0x1u<<10)
#define	SPU_DPPI_PERM_CHANNEL9											(0x1u<<9)
#define	SPU_DPPI_PERM_CHANNEL8											(0x1u<<8)
#define	SPU_DPPI_PERM_CHANNEL7											(0x1u<<7)
#define	SPU_DPPI_PERM_CHANNEL6											(0x1u<<6)
#define	SPU_DPPI_PERM_CHANNEL5											(0x1u<<5)
#define	SPU_DPPI_PERM_CHANNEL4											(0x1u<<4)
#define	SPU_DPPI_PERM_CHANNEL3											(0x1u<<3)
#define	SPU_DPPI_PERM_CHANNEL2											(0x1u<<2)
#define	SPU_DPPI_PERM_CHANNEL1											(0x1u<<1)
#define	SPU_DPPI_PERM_CHANNEL0											(0x1u<<0)
#define	SPU_DPPI_PERM_CHANNEL31_SECURE									(0x1u<<31)
#define	SPU_DPPI_PERM_CHANNEL31_NONSECURE								(0x0u<<31)
#define	SPU_DPPI_PERM_CHANNEL30_SECURE									(0x1u<<30)
#define	SPU_DPPI_PERM_CHANNEL30_NONSECURE								(0x0u<<30)
#define	SPU_DPPI_PERM_CHANNEL29_SECURE									(0x1u<<29)
#define	SPU_DPPI_PERM_CHANNEL29_NONSECURE								(0x0u<<29)
#define	SPU_DPPI_PERM_CHANNEL28_SECURE									(0x1u<<28)
#define	SPU_DPPI_PERM_CHANNEL28_NONSECURE								(0x0u<<28)
#define	SPU_DPPI_PERM_CHANNEL27_SECURE									(0x1u<<27)
#define	SPU_DPPI_PERM_CHANNEL27_NONSECURE								(0x0u<<27)
#define	SPU_DPPI_PERM_CHANNEL26_SECURE									(0x1u<<26)
#define	SPU_DPPI_PERM_CHANNEL26_NONSECURE								(0x0u<<26)
#define	SPU_DPPI_PERM_CHANNEL25_SECURE									(0x1u<<25)
#define	SPU_DPPI_PERM_CHANNEL25_NONSECURE								(0x0u<<25)
#define	SPU_DPPI_PERM_CHANNEL24_SECURE									(0x1u<<24)
#define	SPU_DPPI_PERM_CHANNEL24_NONSECURE								(0x0u<<24)
#define	SPU_DPPI_PERM_CHANNEL23_SECURE									(0x1u<<23)
#define	SPU_DPPI_PERM_CHANNEL23_NONSECURE								(0x0u<<23)
#define	SPU_DPPI_PERM_CHANNEL22_SECURE									(0x1u<<22)
#define	SPU_DPPI_PERM_CHANNEL22_NONSECURE								(0x0u<<22)
#define	SPU_DPPI_PERM_CHANNEL21_SECURE									(0x1u<<21)
#define	SPU_DPPI_PERM_CHANNEL21_NONSECURE								(0x0u<<21)
#define	SPU_DPPI_PERM_CHANNEL20_SECURE									(0x1u<<20)
#define	SPU_DPPI_PERM_CHANNEL20_NONSECURE								(0x0u<<20)
#define	SPU_DPPI_PERM_CHANNEL19_SECURE									(0x1u<<19)
#define	SPU_DPPI_PERM_CHANNEL19_NONSECURE								(0x0u<<19)
#define	SPU_DPPI_PERM_CHANNEL18_SECURE									(0x1u<<18)
#define	SPU_DPPI_PERM_CHANNEL18_NONSECURE								(0x0u<<18)
#define	SPU_DPPI_PERM_CHANNEL17_SECURE									(0x1u<<17)
#define	SPU_DPPI_PERM_CHANNEL17_NONSECURE								(0x0u<<17)
#define	SPU_DPPI_PERM_CHANNEL16_SECURE									(0x1u<<16)
#define	SPU_DPPI_PERM_CHANNEL16_NONSECURE								(0x0u<<16)
#define	SPU_DPPI_PERM_CHANNEL15_SECURE									(0x1u<<15)
#define	SPU_DPPI_PERM_CHANNEL15_NONSECURE								(0x0u<<15)
#define	SPU_DPPI_PERM_CHANNEL14_SECURE									(0x1u<<14)
#define	SPU_DPPI_PERM_CHANNEL14_NONSECURE								(0x0u<<14)
#define	SPU_DPPI_PERM_CHANNEL13_SECURE									(0x1u<<13)
#define	SPU_DPPI_PERM_CHANNEL13_NONSECURE								(0x0u<<13)
#define	SPU_DPPI_PERM_CHANNEL12_SECURE									(0x1u<<12)
#define	SPU_DPPI_PERM_CHANNEL12_NONSECURE								(0x0u<<12)
#define	SPU_DPPI_PERM_CHANNEL11_SECURE									(0x1u<<11)
#define	SPU_DPPI_PERM_CHANNEL11_NONSECURE								(0x0u<<11)
#define	SPU_DPPI_PERM_CHANNEL10_SECURE									(0x1u<<10)
#define	SPU_DPPI_PERM_CHANNEL10_NONSECURE								(0x0u<<10)
#define	SPU_DPPI_PERM_CHANNEL9_SECURE									(0x1u<<9)
#define	SPU_DPPI_PERM_CHANNEL9_NONSECURE								(0x0u<<9)
#define	SPU_DPPI_PERM_CHANNEL8_SECURE									(0x1u<<8)
#define	SPU_DPPI_PERM_CHANNEL8_NONSECURE								(0x0u<<8)
#define	SPU_DPPI_PERM_CHANNEL7_SECURE									(0x1u<<7)
#define	SPU_DPPI_PERM_CHANNEL7_NONSECURE								(0x0u<<7)
#define	SPU_DPPI_PERM_CHANNEL6_SECURE									(0x1u<<6)
#define	SPU_DPPI_PERM_CHANNEL6_NONSECURE								(0x0u<<6)
#define	SPU_DPPI_PERM_CHANNEL5_SECURE									(0x1u<<5)
#define	SPU_DPPI_PERM_CHANNEL5_NONSECURE								(0x0u<<5)
#define	SPU_DPPI_PERM_CHANNEL4_SECURE									(0x1u<<4)
#define	SPU_DPPI_PERM_CHANNEL4_NONSECURE								(0x0u<<4)
#define	SPU_DPPI_PERM_CHANNEL3_SECURE									(0x1u<<3)
#define	SPU_DPPI_PERM_CHANNEL3_NONSECURE								(0x0u<<3)
#define	SPU_DPPI_PERM_CHANNEL2_SECURE									(0x1u<<2)
#define	SPU_DPPI_PERM_CHANNEL2_NONSECURE								(0x0u<<2)
#define	SPU_DPPI_PERM_CHANNEL1_SECURE									(0x1u<<1)
#define	SPU_DPPI_PERM_CHANNEL1_NONSECURE								(0x0u<<1)
#define	SPU_DPPI_PERM_CHANNEL0_SECURE									(0x1u<<0)
#define	SPU_DPPI_PERM_CHANNEL0_NONSECURE								(0x0u<<0)

// LOCK Configuration

#define	SPU_DPPI_LOCK_LOCK												(0x1u<<0)
#define	SPU_DPPI_LOCK_LOCK_LOCKED										(0x1u<<0)
#define	SPU_DPPI_LOCK_LOCK_UNLOCKED										(0x0u<<0)

// PERM Configuration

#define	SPU_GPIOPORT_PERM_PIN31											(0x1u<<31)
#define	SPU_GPIOPORT_PERM_PIN30											(0x1u<<30)
#define	SPU_GPIOPORT_PERM_PIN29											(0x1u<<29)
#define	SPU_GPIOPORT_PERM_PIN28											(0x1u<<28)
#define	SPU_GPIOPORT_PERM_PIN27											(0x1u<<27)
#define	SPU_GPIOPORT_PERM_PIN26											(0x1u<<26)
#define	SPU_GPIOPORT_PERM_PIN25											(0x1u<<25)
#define	SPU_GPIOPORT_PERM_PIN24											(0x1u<<24)
#define	SPU_GPIOPORT_PERM_PIN23											(0x1u<<23)
#define	SPU_GPIOPORT_PERM_PIN22											(0x1u<<22)
#define	SPU_GPIOPORT_PERM_PIN21											(0x1u<<21)
#define	SPU_GPIOPORT_PERM_PIN20											(0x1u<<20)
#define	SPU_GPIOPORT_PERM_PIN19											(0x1u<<19)
#define	SPU_GPIOPORT_PERM_PIN18											(0x1u<<18)
#define	SPU_GPIOPORT_PERM_PIN17											(0x1u<<17)
#define	SPU_GPIOPORT_PERM_PIN16											(0x1u<<16)
#define	SPU_GPIOPORT_PERM_PIN15											(0x1u<<15)
#define	SPU_GPIOPORT_PERM_PIN14											(0x1u<<14)
#define	SPU_GPIOPORT_PERM_PIN13											(0x1u<<13)
#define	SPU_GPIOPORT_PERM_PIN12											(0x1u<<12)
#define	SPU_GPIOPORT_PERM_PIN11											(0x1u<<11)
#define	SPU_GPIOPORT_PERM_PIN10											(0x1u<<10)
#define	SPU_GPIOPORT_PERM_PIN9											(0x1u<<9)
#define	SPU_GPIOPORT_PERM_PIN8											(0x1u<<8)
#define	SPU_GPIOPORT_PERM_PIN7											(0x1u<<7)
#define	SPU_GPIOPORT_PERM_PIN6											(0x1u<<6)
#define	SPU_GPIOPORT_PERM_PIN5											(0x1u<<5)
#define	SPU_GPIOPORT_PERM_PIN4											(0x1u<<4)
#define	SPU_GPIOPORT_PERM_PIN3											(0x1u<<3)
#define	SPU_GPIOPORT_PERM_PIN2											(0x1u<<2)
#define	SPU_GPIOPORT_PERM_PIN1											(0x1u<<1)
#define	SPU_GPIOPORT_PERM_PIN0											(0x1u<<0)
#define	SPU_GPIOPORT_PERM_PIN31_SECURE									(0x1u<<31)
#define	SPU_GPIOPORT_PERM_PIN31_NONSECURE								(0x0u<<31)
#define	SPU_GPIOPORT_PERM_PIN30_SECURE									(0x1u<<30)
#define	SPU_GPIOPORT_PERM_PIN30_NONSECURE								(0x0u<<30)
#define	SPU_GPIOPORT_PERM_PIN29_SECURE									(0x1u<<29)
#define	SPU_GPIOPORT_PERM_PIN29_NONSECURE								(0x0u<<29)
#define	SPU_GPIOPORT_PERM_PIN28_SECURE									(0x1u<<28)
#define	SPU_GPIOPORT_PERM_PIN28_NONSECURE								(0x0u<<28)
#define	SPU_GPIOPORT_PERM_PIN27_SECURE									(0x1u<<27)
#define	SPU_GPIOPORT_PERM_PIN27_NONSECURE								(0x0u<<27)
#define	SPU_GPIOPORT_PERM_PIN26_SECURE									(0x1u<<26)
#define	SPU_GPIOPORT_PERM_PIN26_NONSECURE								(0x0u<<26)
#define	SPU_GPIOPORT_PERM_PIN25_SECURE									(0x1u<<25)
#define	SPU_GPIOPORT_PERM_PIN25_NONSECURE								(0x0u<<25)
#define	SPU_GPIOPORT_PERM_PIN24_SECURE									(0x1u<<24)
#define	SPU_GPIOPORT_PERM_PIN24_NONSECURE								(0x0u<<24)
#define	SPU_GPIOPORT_PERM_PIN23_SECURE									(0x1u<<23)
#define	SPU_GPIOPORT_PERM_PIN23_NONSECURE								(0x0u<<23)
#define	SPU_GPIOPORT_PERM_PIN22_SECURE									(0x1u<<22)
#define	SPU_GPIOPORT_PERM_PIN22_NONSECURE								(0x0u<<22)
#define	SPU_GPIOPORT_PERM_PIN21_SECURE									(0x1u<<21)
#define	SPU_GPIOPORT_PERM_PIN21_NONSECURE								(0x0u<<21)
#define	SPU_GPIOPORT_PERM_PIN20_SECURE									(0x1u<<20)
#define	SPU_GPIOPORT_PERM_PIN20_NONSECURE								(0x0u<<20)
#define	SPU_GPIOPORT_PERM_PIN19_SECURE									(0x1u<<19)
#define	SPU_GPIOPORT_PERM_PIN19_NONSECURE								(0x0u<<19)
#define	SPU_GPIOPORT_PERM_PIN18_SECURE									(0x1u<<18)
#define	SPU_GPIOPORT_PERM_PIN18_NONSECURE								(0x0u<<18)
#define	SPU_GPIOPORT_PERM_PIN17_SECURE									(0x1u<<17)
#define	SPU_GPIOPORT_PERM_PIN17_NONSECURE								(0x0u<<17)
#define	SPU_GPIOPORT_PERM_PIN16_SECURE									(0x1u<<16)
#define	SPU_GPIOPORT_PERM_PIN16_NONSECURE								(0x0u<<16)
#define	SPU_GPIOPORT_PERM_PIN15_SECURE									(0x1u<<15)
#define	SPU_GPIOPORT_PERM_PIN15_NONSECURE								(0x0u<<15)
#define	SPU_GPIOPORT_PERM_PIN14_SECURE									(0x1u<<14)
#define	SPU_GPIOPORT_PERM_PIN14_NONSECURE								(0x0u<<14)
#define	SPU_GPIOPORT_PERM_PIN13_SECURE									(0x1u<<13)
#define	SPU_GPIOPORT_PERM_PIN13_NONSECURE								(0x0u<<13)
#define	SPU_GPIOPORT_PERM_PIN12_SECURE									(0x1u<<12)
#define	SPU_GPIOPORT_PERM_PIN12_NONSECURE								(0x0u<<12)
#define	SPU_GPIOPORT_PERM_PIN11_SECURE									(0x1u<<11)
#define	SPU_GPIOPORT_PERM_PIN11_NONSECURE								(0x0u<<11)
#define	SPU_GPIOPORT_PERM_PIN10_SECURE									(0x1u<<10)
#define	SPU_GPIOPORT_PERM_PIN10_NONSECURE								(0x0u<<10)
#define	SPU_GPIOPORT_PERM_PIN9_SECURE									(0x1u<<9)
#define	SPU_GPIOPORT_PERM_PIN9_NONSECURE								(0x0u<<9)
#define	SPU_GPIOPORT_PERM_PIN8_SECURE									(0x1u<<8)
#define	SPU_GPIOPORT_PERM_PIN8_NONSECURE								(0x0u<<8)
#define	SPU_GPIOPORT_PERM_PIN7_SECURE									(0x1u<<7)
#define	SPU_GPIOPORT_PERM_PIN7_NONSECURE								(0x0u<<7)
#define	SPU_GPIOPORT_PERM_PIN6_SECURE									(0x1u<<6)
#define	SPU_GPIOPORT_PERM_PIN6_NONSECURE								(0x0u<<6)
#define	SPU_GPIOPORT_PERM_PIN5_SECURE									(0x1u<<5)
#define	SPU_GPIOPORT_PERM_PIN5_NONSECURE								(0x0u<<5)
#define	SPU_GPIOPORT_PERM_PIN4_SECURE									(0x1u<<4)
#define	SPU_GPIOPORT_PERM_PIN4_NONSECURE								(0x0u<<4)
#define	SPU_GPIOPORT_PERM_PIN3_SECURE									(0x1u<<3)
#define	SPU_GPIOPORT_PERM_PIN3_NONSECURE								(0x0u<<3)
#define	SPU_GPIOPORT_PERM_PIN2_SECURE									(0x1u<<2)
#define	SPU_GPIOPORT_PERM_PIN2_NONSECURE								(0x0u<<2)
#define	SPU_GPIOPORT_PERM_PIN1_SECURE									(0x1u<<1)
#define	SPU_GPIOPORT_PERM_PIN1_NONSECURE								(0x0u<<1)
#define	SPU_GPIOPORT_PERM_PIN0_SECURE									(0x1u<<0)
#define	SPU_GPIOPORT_PERM_PIN0_NONSECURE								(0x0u<<0)

// LOCK Configuration

#define	SPU_GPIOPORT_LOCK_LOCK											(0x1u<<0)
#define	SPU_GPIOPORT_LOCK_LOCK_LOCKED									(0x1u<<0)
#define	SPU_GPIOPORT_LOCK_LOCK_UNLOCKED									(0x0u<<0)

// REGION Configuration

#define	SPU_FLASHNSC_REGION_LOCK										(0x1u<<8)
#define	SPU_FLASHNSC_REGION_REGION										(0x3Fu<<0)
#define	SPU_FLASHNSC_REGION_REGION_0									(0x1u<<0)
#define	SPU_FLASHNSC_REGION_LOCK_UNLOCKED								(0x0u<<8)
#define	SPU_FLASHNSC_REGION_LOCK_LOCKED									(0x1u<<8)

// SIZE Configuration

#define	SPU_FLASHNSC_SIZE_LOCK											(0x1u<<8)
#define	SPU_FLASHNSC_SIZE_SIZE											(0xFu<<0)
#define	SPU_FLASHNSC_SIZE_SIZE_0										(0x1u<<0)
#define	SPU_FLASHNSC_SIZE_LOCK_UNLOCKED									(0x0u<<8)
#define	SPU_FLASHNSC_SIZE_LOCK_LOCKED									(0x1u<<8)
#define	SPU_FLASHNSC_SIZE_SIZE_DISABLED									(0x0u<<0)
#define	SPU_FLASHNSC_SIZE_SIZE_32										(0x1u<<0)
#define	SPU_FLASHNSC_SIZE_SIZE_64										(0x2u<<0)
#define	SPU_FLASHNSC_SIZE_SIZE_128										(0x3u<<0)
#define	SPU_FLASHNSC_SIZE_SIZE_256										(0x4u<<0)
#define	SPU_FLASHNSC_SIZE_SIZE_512										(0x5u<<0)
#define	SPU_FLASHNSC_SIZE_SIZE_1024										(0x6u<<0)
#define	SPU_FLASHNSC_SIZE_SIZE_2048										(0x7u<<0)
#define	SPU_FLASHNSC_SIZE_SIZE_4096										(0x8u<<0)

// REGION Configuration

#define	SPU_RAMNSC_REGION_LOCK											(0x1u<<8)
#define	SPU_RAMNSC_REGION_REGION										(0x3Fu<<0)
#define	SPU_RAMNSC_REGION_REGION_0										(0x1u<<0)
#define	SPU_RAMNSC_REGION_LOCK_UNLOCKED									(0x0u<<8)
#define	SPU_RAMNSC_REGION_LOCK_LOCKED									(0x1u<<8)

// SIZE Configuration

#define	SPU_RAMNSC_SIZE_LOCK											(0x1u<<8)
#define	SPU_RAMNSC_SIZE_SIZE											(0xFu<<0)
#define	SPU_RAMNSC_SIZE_SIZE_0											(0x1u<<0)
#define	SPU_RAMNSC_SIZE_LOCK_UNLOCKED									(0x0u<<8)
#define	SPU_RAMNSC_SIZE_LOCK_LOCKED										(0x1u<<8)
#define	SPU_RAMNSC_SIZE_SIZE_DISABLED									(0x0u<<0)
#define	SPU_RAMNSC_SIZE_SIZE_32											(0x1u<<0)
#define	SPU_RAMNSC_SIZE_SIZE_64											(0x2u<<0)
#define	SPU_RAMNSC_SIZE_SIZE_128										(0x3u<<0)
#define	SPU_RAMNSC_SIZE_SIZE_256										(0x4u<<0)
#define	SPU_RAMNSC_SIZE_SIZE_512										(0x5u<<0)
#define	SPU_RAMNSC_SIZE_SIZE_1024										(0x6u<<0)
#define	SPU_RAMNSC_SIZE_SIZE_2048										(0x7u<<0)
#define	SPU_RAMNSC_SIZE_SIZE_4096										(0x8u<<0)

// PERM Configuration

#define	SPU_FLASHREGION_PERM_LOCK										(0x1u<<8)
#define	SPU_FLASHREGION_PERM_SECATTR									(0x1u<<4)
#define	SPU_FLASHREGION_PERM_READ										(0x1u<<2)
#define	SPU_FLASHREGION_PERM_WRITE										(0x1u<<1)
#define	SPU_FLASHREGION_PERM_EXECUTE									(0x1u<<0)
#define	SPU_FLASHREGION_PERM_LOCK_UNLOCKED								(0x0u<<8)
#define	SPU_FLASHREGION_PERM_LOCK_LOCKED								(0x1u<<8)
#define	SPU_FLASHREGION_PERM_SECATTR_NON_SECURE							(0x0u<<4)
#define	SPU_FLASHREGION_PERM_SECATTR_SECURE								(0x1u<<4)
#define	SPU_FLASHREGION_PERM_READ_ENABLE								(0x1u<<2)
#define	SPU_FLASHREGION_PERM_READ_DISABLE								(0x0u<<2)
#define	SPU_FLASHREGION_PERM_WRITE_ENABLE								(0x1u<<1)
#define	SPU_FLASHREGION_PERM_WRITE_DISABLE								(0x0u<<1)
#define	SPU_FLASHREGION_PERM_EXECUTE_ENABLE								(0x1u<<0)
#define	SPU_FLASHREGION_PERM_EXECUTE_DISABLE							(0x0u<<0)

// PERM Configuration

#define	SPU_RAMREGION_PERM_LOCK											(0x1u<<8)
#define	SPU_RAMREGION_PERM_SECATTR										(0x1u<<4)
#define	SPU_RAMREGION_PERM_READ											(0x1u<<2)
#define	SPU_RAMREGION_PERM_WRITE										(0x1u<<1)
#define	SPU_RAMREGION_PERM_EXECUTE										(0x1u<<0)
#define	SPU_RAMREGION_PERM_LOCK_UNLOCKED								(0x0u<<8)
#define	SPU_RAMREGION_PERM_LOCK_LOCKED									(0x1u<<8)
#define	SPU_RAMREGION_PERM_SECATTR_NON_SECURE							(0x0u<<4)
#define	SPU_RAMREGION_PERM_SECATTR_SECURE								(0x1u<<4)
#define	SPU_RAMREGION_PERM_READ_ENABLE									(0x1u<<2)
#define	SPU_RAMREGION_PERM_READ_DISABLE									(0x0u<<2)
#define	SPU_RAMREGION_PERM_WRITE_ENABLE									(0x1u<<1)
#define	SPU_RAMREGION_PERM_WRITE_DISABLE								(0x0u<<1)
#define	SPU_RAMREGION_PERM_EXECUTE_ENABLE								(0x1u<<0)
#define	SPU_RAMREGION_PERM_EXECUTE_DISABLE								(0x0u<<0)

// PERM Configuration

#define	SPU_PERIPHID_PERM_PRESENT										(0x1u<<31)
#define	SPU_PERIPHID_PERM_LOCK											(0x1u<<8)
#define	SPU_PERIPHID_PERM_DMASEC										(0x1u<<5)
#define	SPU_PERIPHID_PERM_SECATTR										(0x1u<<4)
#define	SPU_PERIPHID_PERM_DMA											(0x3u<<2)
#define	SPU_PERIPHID_PERM_DMA_0											(0x1u<<2)
#define	SPU_PERIPHID_PERM_SECUREMAPPING									(0x3u<<0)
#define	SPU_PERIPHID_PERM_SECUREMAPPING_0								(0x1u<<0)
#define	SPU_PERIPHID_PERM_PRESENT_NOTPRESENT							(0x0u<<31)
#define	SPU_PERIPHID_PERM_PRESENT_ISPRESENT								(0x1u<<31)
#define	SPU_PERIPHID_PERM_LOCK_UNLOCKED									(0x0u<<8)
#define	SPU_PERIPHID_PERM_LOCK_LOCKED									(0x1u<<8)
#define	SPU_PERIPHID_PERM_DMASEC_SECURE									(0x1u<<5)
#define	SPU_PERIPHID_PERM_DMASEC_NONSECURE								(0x0u<<5)
#define	SPU_PERIPHID_PERM_SECATTR_SECURE								(0x1u<<4)
#define	SPU_PERIPHID_PERM_SECATTR_NONSECURE								(0x0u<<4)
#define	SPU_PERIPHID_PERM_DMA_NODMA										(0x0u<<2)
#define	SPU_PERIPHID_PERM_DMA_NOSEPARATEATTRIBUTE						(0x1u<<2)
#define	SPU_PERIPHID_PERM_DMA_SEPARATEATTRIBUTE							(0x2u<<2)
#define	SPU_PERIPHID_PERM_SECUREMAPPING_NONSECURE						(0x0u<<0)
#define	SPU_PERIPHID_PERM_SECUREMAPPING_SECURE							(0x1u<<0)
#define	SPU_PERIPHID_PERM_SECUREMAPPING_USERSELECTABLE					(0x2u<<0)
#define	SPU_PERIPHID_PERM_SECUREMAPPING_SPLIT							(0x3u<<0)
