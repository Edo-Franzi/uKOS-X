/*
; nrf5340_application_cacheinfo.
; ==============================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_cacheinfo equates.
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

// CACHEINFO address definitions
// -----------------------------

typedef struct {
	volatile	uint32_t	SET0_WAY[2];
	volatile	uint32_t	SET1_WAY[2];
	volatile	uint32_t	SET2_WAY[2];
	volatile	uint32_t	SET3_WAY[2];
	volatile	uint32_t	SET4_WAY[2];
	volatile	uint32_t	SET5_WAY[2];
	volatile	uint32_t	SET6_WAY[2];
	volatile	uint32_t	SET7_WAY[2];
	volatile	uint32_t	SET8_WAY[2];
	volatile	uint32_t	SET9_WAY[2];
	volatile	uint32_t	SET10_WAY[2];
	volatile	uint32_t	SET11_WAY[2];
	volatile	uint32_t	SET12_WAY[2];
	volatile	uint32_t	SET13_WAY[2];
	volatile	uint32_t	SET14_WAY[2];
	volatile	uint32_t	SET15_WAY[2];
	volatile	uint32_t	SET16_WAY[2];
	volatile	uint32_t	SET17_WAY[2];
	volatile	uint32_t	SET18_WAY[2];
	volatile	uint32_t	SET19_WAY[2];
	volatile	uint32_t	SET20_WAY[2];
	volatile	uint32_t	SET21_WAY[2];
	volatile	uint32_t	SET22_WAY[2];
	volatile	uint32_t	SET23_WAY[2];
	volatile	uint32_t	SET24_WAY[2];
	volatile	uint32_t	SET25_WAY[2];
	volatile	uint32_t	SET26_WAY[2];
	volatile	uint32_t	SET27_WAY[2];
	volatile	uint32_t	SET28_WAY[2];
	volatile	uint32_t	SET29_WAY[2];
	volatile	uint32_t	SET30_WAY[2];
	volatile	uint32_t	SET31_WAY[2];
	volatile	uint32_t	SET32_WAY[2];
	volatile	uint32_t	SET33_WAY[2];
	volatile	uint32_t	SET34_WAY[2];
	volatile	uint32_t	SET35_WAY[2];
	volatile	uint32_t	SET36_WAY[2];
	volatile	uint32_t	SET37_WAY[2];
	volatile	uint32_t	SET38_WAY[2];
	volatile	uint32_t	SET39_WAY[2];
	volatile	uint32_t	SET40_WAY[2];
	volatile	uint32_t	SET41_WAY[2];
	volatile	uint32_t	SET42_WAY[2];
	volatile	uint32_t	SET43_WAY[2];
	volatile	uint32_t	SET44_WAY[2];
	volatile	uint32_t	SET45_WAY[2];
	volatile	uint32_t	SET46_WAY[2];
	volatile	uint32_t	SET47_WAY[2];
	volatile	uint32_t	SET48_WAY[2];
	volatile	uint32_t	SET49_WAY[2];
	volatile	uint32_t	SET50_WAY[2];
	volatile	uint32_t	SET51_WAY[2];
	volatile	uint32_t	SET52_WAY[2];
	volatile	uint32_t	SET53_WAY[2];
	volatile	uint32_t	SET54_WAY[2];
	volatile	uint32_t	SET55_WAY[2];
	volatile	uint32_t	SET56_WAY[2];
	volatile	uint32_t	SET57_WAY[2];
	volatile	uint32_t	SET58_WAY[2];
	volatile	uint32_t	SET59_WAY[2];
	volatile	uint32_t	SET60_WAY[2];
	volatile	uint32_t	SET61_WAY[2];
	volatile	uint32_t	SET62_WAY[2];
	volatile	uint32_t	SET63_WAY[2];
	volatile	uint32_t	SET64_WAY[2];
	volatile	uint32_t	SET65_WAY[2];
	volatile	uint32_t	SET66_WAY[2];
	volatile	uint32_t	SET67_WAY[2];
	volatile	uint32_t	SET68_WAY[2];
	volatile	uint32_t	SET69_WAY[2];
	volatile	uint32_t	SET70_WAY[2];
	volatile	uint32_t	SET71_WAY[2];
	volatile	uint32_t	SET72_WAY[2];
	volatile	uint32_t	SET73_WAY[2];
	volatile	uint32_t	SET74_WAY[2];
	volatile	uint32_t	SET75_WAY[2];
	volatile	uint32_t	SET76_WAY[2];
	volatile	uint32_t	SET77_WAY[2];
	volatile	uint32_t	SET78_WAY[2];
	volatile	uint32_t	SET79_WAY[2];
	volatile	uint32_t	SET80_WAY[2];
	volatile	uint32_t	SET81_WAY[2];
	volatile	uint32_t	SET82_WAY[2];
	volatile	uint32_t	SET83_WAY[2];
	volatile	uint32_t	SET84_WAY[2];
	volatile	uint32_t	SET85_WAY[2];
	volatile	uint32_t	SET86_WAY[2];
	volatile	uint32_t	SET87_WAY[2];
	volatile	uint32_t	SET88_WAY[2];
	volatile	uint32_t	SET89_WAY[2];
	volatile	uint32_t	SET90_WAY[2];
	volatile	uint32_t	SET91_WAY[2];
	volatile	uint32_t	SET92_WAY[2];
	volatile	uint32_t	SET93_WAY[2];
	volatile	uint32_t	SET94_WAY[2];
	volatile	uint32_t	SET95_WAY[2];
	volatile	uint32_t	SET96_WAY[2];
	volatile	uint32_t	SET97_WAY[2];
	volatile	uint32_t	SET98_WAY[2];
	volatile	uint32_t	SET99_WAY[2];
	volatile	uint32_t	SET100_WAY[2];
	volatile	uint32_t	SET101_WAY[2];
	volatile	uint32_t	SET102_WAY[2];
	volatile	uint32_t	SET103_WAY[2];
	volatile	uint32_t	SET104_WAY[2];
	volatile	uint32_t	SET105_WAY[2];
	volatile	uint32_t	SET106_WAY[2];
	volatile	uint32_t	SET107_WAY[2];
	volatile	uint32_t	SET108_WAY[2];
	volatile	uint32_t	SET109_WAY[2];
	volatile	uint32_t	SET110_WAY[2];
	volatile	uint32_t	SET111_WAY[2];
	volatile	uint32_t	SET112_WAY[2];
	volatile	uint32_t	SET113_WAY[2];
	volatile	uint32_t	SET114_WAY[2];
	volatile	uint32_t	SET115_WAY[2];
	volatile	uint32_t	SET116_WAY[2];
	volatile	uint32_t	SET117_WAY[2];
	volatile	uint32_t	SET118_WAY[2];
	volatile	uint32_t	SET119_WAY[2];
	volatile	uint32_t	SET120_WAY[2];
	volatile	uint32_t	SET121_WAY[2];
	volatile	uint32_t	SET122_WAY[2];
	volatile	uint32_t	SET123_WAY[2];
	volatile	uint32_t	SET124_WAY[2];
	volatile	uint32_t	SET125_WAY[2];
	volatile	uint32_t	SET126_WAY[2];
	volatile	uint32_t	SET127_WAY[2];
	volatile	uint32_t	SET128_WAY[2];
	volatile	uint32_t	SET129_WAY[2];
	volatile	uint32_t	SET130_WAY[2];
	volatile	uint32_t	SET131_WAY[2];
	volatile	uint32_t	SET132_WAY[2];
	volatile	uint32_t	SET133_WAY[2];
	volatile	uint32_t	SET134_WAY[2];
	volatile	uint32_t	SET135_WAY[2];
	volatile	uint32_t	SET136_WAY[2];
	volatile	uint32_t	SET137_WAY[2];
	volatile	uint32_t	SET138_WAY[2];
	volatile	uint32_t	SET139_WAY[2];
	volatile	uint32_t	SET140_WAY[2];
	volatile	uint32_t	SET141_WAY[2];
	volatile	uint32_t	SET142_WAY[2];
	volatile	uint32_t	SET143_WAY[2];
	volatile	uint32_t	SET144_WAY[2];
	volatile	uint32_t	SET145_WAY[2];
	volatile	uint32_t	SET146_WAY[2];
	volatile	uint32_t	SET147_WAY[2];
	volatile	uint32_t	SET148_WAY[2];
	volatile	uint32_t	SET149_WAY[2];
	volatile	uint32_t	SET150_WAY[2];
	volatile	uint32_t	SET151_WAY[2];
	volatile	uint32_t	SET152_WAY[2];
	volatile	uint32_t	SET153_WAY[2];
	volatile	uint32_t	SET154_WAY[2];
	volatile	uint32_t	SET155_WAY[2];
	volatile	uint32_t	SET156_WAY[2];
	volatile	uint32_t	SET157_WAY[2];
	volatile	uint32_t	SET158_WAY[2];
	volatile	uint32_t	SET159_WAY[2];
	volatile	uint32_t	SET160_WAY[2];
	volatile	uint32_t	SET161_WAY[2];
	volatile	uint32_t	SET162_WAY[2];
	volatile	uint32_t	SET163_WAY[2];
	volatile	uint32_t	SET164_WAY[2];
	volatile	uint32_t	SET165_WAY[2];
	volatile	uint32_t	SET166_WAY[2];
	volatile	uint32_t	SET167_WAY[2];
	volatile	uint32_t	SET168_WAY[2];
	volatile	uint32_t	SET169_WAY[2];
	volatile	uint32_t	SET170_WAY[2];
	volatile	uint32_t	SET171_WAY[2];
	volatile	uint32_t	SET172_WAY[2];
	volatile	uint32_t	SET173_WAY[2];
	volatile	uint32_t	SET174_WAY[2];
	volatile	uint32_t	SET175_WAY[2];
	volatile	uint32_t	SET176_WAY[2];
	volatile	uint32_t	SET177_WAY[2];
	volatile	uint32_t	SET178_WAY[2];
	volatile	uint32_t	SET179_WAY[2];
	volatile	uint32_t	SET180_WAY[2];
	volatile	uint32_t	SET181_WAY[2];
	volatile	uint32_t	SET182_WAY[2];
	volatile	uint32_t	SET183_WAY[2];
	volatile	uint32_t	SET184_WAY[2];
	volatile	uint32_t	SET185_WAY[2];
	volatile	uint32_t	SET186_WAY[2];
	volatile	uint32_t	SET187_WAY[2];
	volatile	uint32_t	SET188_WAY[2];
	volatile	uint32_t	SET189_WAY[2];
	volatile	uint32_t	SET190_WAY[2];
	volatile	uint32_t	SET191_WAY[2];
	volatile	uint32_t	SET192_WAY[2];
	volatile	uint32_t	SET193_WAY[2];
	volatile	uint32_t	SET194_WAY[2];
	volatile	uint32_t	SET195_WAY[2];
	volatile	uint32_t	SET196_WAY[2];
	volatile	uint32_t	SET197_WAY[2];
	volatile	uint32_t	SET198_WAY[2];
	volatile	uint32_t	SET199_WAY[2];
	volatile	uint32_t	SET200_WAY[2];
	volatile	uint32_t	SET201_WAY[2];
	volatile	uint32_t	SET202_WAY[2];
	volatile	uint32_t	SET203_WAY[2];
	volatile	uint32_t	SET204_WAY[2];
	volatile	uint32_t	SET205_WAY[2];
	volatile	uint32_t	SET206_WAY[2];
	volatile	uint32_t	SET207_WAY[2];
	volatile	uint32_t	SET208_WAY[2];
	volatile	uint32_t	SET209_WAY[2];
	volatile	uint32_t	SET210_WAY[2];
	volatile	uint32_t	SET211_WAY[2];
	volatile	uint32_t	SET212_WAY[2];
	volatile	uint32_t	SET213_WAY[2];
	volatile	uint32_t	SET214_WAY[2];
	volatile	uint32_t	SET215_WAY[2];
	volatile	uint32_t	SET216_WAY[2];
	volatile	uint32_t	SET217_WAY[2];
	volatile	uint32_t	SET218_WAY[2];
	volatile	uint32_t	SET219_WAY[2];
	volatile	uint32_t	SET220_WAY[2];
	volatile	uint32_t	SET221_WAY[2];
	volatile	uint32_t	SET222_WAY[2];
	volatile	uint32_t	SET223_WAY[2];
	volatile	uint32_t	SET224_WAY[2];
	volatile	uint32_t	SET225_WAY[2];
	volatile	uint32_t	SET226_WAY[2];
	volatile	uint32_t	SET227_WAY[2];
	volatile	uint32_t	SET228_WAY[2];
	volatile	uint32_t	SET229_WAY[2];
	volatile	uint32_t	SET230_WAY[2];
	volatile	uint32_t	SET231_WAY[2];
	volatile	uint32_t	SET232_WAY[2];
	volatile	uint32_t	SET233_WAY[2];
	volatile	uint32_t	SET234_WAY[2];
	volatile	uint32_t	SET235_WAY[2];
	volatile	uint32_t	SET236_WAY[2];
	volatile	uint32_t	SET237_WAY[2];
	volatile	uint32_t	SET238_WAY[2];
	volatile	uint32_t	SET239_WAY[2];
	volatile	uint32_t	SET240_WAY[2];
	volatile	uint32_t	SET241_WAY[2];
	volatile	uint32_t	SET242_WAY[2];
	volatile	uint32_t	SET243_WAY[2];
	volatile	uint32_t	SET244_WAY[2];
	volatile	uint32_t	SET245_WAY[2];
	volatile	uint32_t	SET246_WAY[2];
	volatile	uint32_t	SET247_WAY[2];
	volatile	uint32_t	SET248_WAY[2];
	volatile	uint32_t	SET249_WAY[2];
	volatile	uint32_t	SET250_WAY[2];
	volatile	uint32_t	SET251_WAY[2];
	volatile	uint32_t	SET252_WAY[2];
	volatile	uint32_t	SET253_WAY[2];
	volatile	uint32_t	SET254_WAY[2];
	volatile	uint32_t	SET255_WAY[2];
} CACHEINFO_TypeDef;

#if (defined(__cplusplus))
#define	CACHEINFO_S	reinterpret_cast<CACHEINFO_TypeDef *>(0x00F08000u)

#else
#define	CACHEINFO_S	((CACHEINFO_TypeDef *)0x00F08000u)
#endif

// WAY Configuration

#define	CACHEINFO_SET_WAY_MRU		(0x1u<<31)
#define	CACHEINFO_SET_WAY_V			(0x1u<<30)
#define	CACHEINFO_SET_WAY_TAG		(0x1FFFFu<<0)
#define	CACHEINFO_SET_WAY_TAG_0		(0x1u<<0)
#define	CACHEINFO_SET_WAY_MRU_WAY0	(0x0u<<31)
#define	CACHEINFO_SET_WAY_MRU_WAY1	(0x1u<<31)
#define	CACHEINFO_SET_WAY_V_INVALID	(0x0u<<30)
#define	CACHEINFO_SET_WAY_V_VALID	(0x1u<<30)
