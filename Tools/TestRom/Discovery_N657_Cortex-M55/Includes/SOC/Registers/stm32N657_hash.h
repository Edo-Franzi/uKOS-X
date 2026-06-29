/*
; stm32N657_hash.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_hash equates.
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

// HASH address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	DIN;
	volatile	uint32_t	STR;
	volatile	uint32_t	HRA0;
	volatile	uint32_t	HRA1;
	volatile	uint32_t	HRA2;
	volatile	uint32_t	HRA3;
	volatile	uint32_t	HRA4;
	volatile	uint32_t	IMR;
	volatile	uint32_t	SR;
	volatile	uint32_t	RESERVED0[52];
	volatile	uint32_t	CSR0;
	volatile	uint32_t	CSR1;
	volatile	uint32_t	CSR2;
	volatile	uint32_t	CSR3;
	volatile	uint32_t	CSR4;
	volatile	uint32_t	CSR5;
	volatile	uint32_t	CSR6;
	volatile	uint32_t	CSR7;
	volatile	uint32_t	CSR8;
	volatile	uint32_t	CSR9;
	volatile	uint32_t	CSR10;
	volatile	uint32_t	CSR11;
	volatile	uint32_t	CSR12;
	volatile	uint32_t	CSR13;
	volatile	uint32_t	CSR14;
	volatile	uint32_t	CSR15;
	volatile	uint32_t	CSR16;
	volatile	uint32_t	CSR17;
	volatile	uint32_t	CSR18;
	volatile	uint32_t	CSR19;
	volatile	uint32_t	CSR20;
	volatile	uint32_t	CSR21;
	volatile	uint32_t	CSR22;
	volatile	uint32_t	CSR23;
	volatile	uint32_t	CSR24;
	volatile	uint32_t	CSR25;
	volatile	uint32_t	CSR26;
	volatile	uint32_t	CSR27;
	volatile	uint32_t	CSR28;
	volatile	uint32_t	CSR29;
	volatile	uint32_t	CSR30;
	volatile	uint32_t	CSR31;
	volatile	uint32_t	CSR32;
	volatile	uint32_t	CSR33;
	volatile	uint32_t	CSR34;
	volatile	uint32_t	CSR35;
	volatile	uint32_t	CSR36;
	volatile	uint32_t	CSR37;
	volatile	uint32_t	CSR38;
	volatile	uint32_t	CSR39;
	volatile	uint32_t	CSR40;
	volatile	uint32_t	CSR41;
	volatile	uint32_t	CSR42;
	volatile	uint32_t	CSR43;
	volatile	uint32_t	CSR44;
	volatile	uint32_t	CSR45;
	volatile	uint32_t	CSR46;
	volatile	uint32_t	CSR47;
	volatile	uint32_t	CSR48;
	volatile	uint32_t	CSR49;
	volatile	uint32_t	CSR50;
	volatile	uint32_t	CSR51;
	volatile	uint32_t	CSR52;
	volatile	uint32_t	CSR53;
	volatile	uint32_t	CSR54;
	volatile	uint32_t	CSR55;
	volatile	uint32_t	CSR56;
	volatile	uint32_t	CSR57;
	volatile	uint32_t	CSR58;
	volatile	uint32_t	CSR59;
	volatile	uint32_t	CSR60;
	volatile	uint32_t	CSR61;
	volatile	uint32_t	CSR62;
	volatile	uint32_t	CSR63;
	volatile	uint32_t	CSR64;
	volatile	uint32_t	CSR65;
	volatile	uint32_t	CSR66;
	volatile	uint32_t	CSR67;
	volatile	uint32_t	CSR68;
	volatile	uint32_t	CSR69;
	volatile	uint32_t	CSR70;
	volatile	uint32_t	CSR71;
	volatile	uint32_t	CSR72;
	volatile	uint32_t	CSR73;
	volatile	uint32_t	CSR74;
	volatile	uint32_t	CSR75;
	volatile	uint32_t	CSR76;
	volatile	uint32_t	CSR77;
	volatile	uint32_t	CSR78;
	volatile	uint32_t	CSR79;
	volatile	uint32_t	CSR80;
	volatile	uint32_t	CSR81;
	volatile	uint32_t	CSR82;
	volatile	uint32_t	CSR83;
	volatile	uint32_t	CSR84;
	volatile	uint32_t	CSR85;
	volatile	uint32_t	CSR86;
	volatile	uint32_t	CSR87;
	volatile	uint32_t	CSR88;
	volatile	uint32_t	CSR89;
	volatile	uint32_t	CSR90;
	volatile	uint32_t	CSR91;
	volatile	uint32_t	CSR92;
	volatile	uint32_t	CSR93;
	volatile	uint32_t	CSR94;
	volatile	uint32_t	CSR95;
	volatile	uint32_t	CSR96;
	volatile	uint32_t	CSR97;
	volatile	uint32_t	CSR98;
	volatile	uint32_t	CSR99;
	volatile	uint32_t	CSR100;
	volatile	uint32_t	CSR101;
	volatile	uint32_t	CSR102;
	volatile	uint32_t	RESERVED1[31];
	volatile	uint32_t	HR0;
	volatile	uint32_t	HR1;
	volatile	uint32_t	HR2;
	volatile	uint32_t	HR3;
	volatile	uint32_t	HR4;
	volatile	uint32_t	HR5;
	volatile	uint32_t	HR6;
	volatile	uint32_t	HR7;
	volatile	uint32_t	HR8;
	volatile	uint32_t	HR9;
	volatile	uint32_t	HR10;
	volatile	uint32_t	HR11;
	volatile	uint32_t	HR12;
	volatile	uint32_t	HR13;
	volatile	uint32_t	HR14;
	volatile	uint32_t	HR15;
} HASH_TypeDef;

#if (defined(__cplusplus))
#define	HASH_NS	reinterpret_cast<HASH_TypeDef *>(0x44020400u)
#define	HASH_S	reinterpret_cast<HASH_TypeDef *>(0x54020400u)

#else
#define	HASH_NS	((HASH_TypeDef *)0x44020400u)
#define	HASH_S	((HASH_TypeDef *)0x54020400u)
#endif

// CR Configuration

#define	HASH_CR_ALGO				(0xFu<<17)
#define	HASH_CR_ALGO_0				(0x1u<<17)
#define	HASH_CR_LKEY				(0x1u<<16)
#define	HASH_CR_MDMAT				(0x1u<<13)
#define	HASH_CR_DINNE				(0x1u<<12)
#define	HASH_CR_NBW					(0xFu<<8)
#define	HASH_CR_NBW_0				(0x1u<<8)
#define	HASH_CR_MODE				(0x1u<<6)
#define	HASH_CR_DATATYPE			(0x3u<<4)
#define	HASH_CR_DATATYPE_0			(0x1u<<4)
#define	HASH_CR_DMAE				(0x1u<<3)
#define	HASH_CR_INIT				(0x1u<<2)

#define	HASH_CR_ALGO_B_0X0			(0x0u<<17)
#define	HASH_CR_ALGO_B_0X2			(0x2u<<17)
#define	HASH_CR_ALGO_B_0X3			(0x3u<<17)
#define	HASH_CR_ALGO_B_0XC			(0xCu<<17)
#define	HASH_CR_ALGO_B_0XD			(0xDu<<17)
#define	HASH_CR_ALGO_B_0XE			(0xEu<<17)
#define	HASH_CR_ALGO_B_0XF			(0xFu<<17)
#define	HASH_CR_LKEY_B_0X0			(0x0u<<16)
#define	HASH_CR_LKEY_B_0X1			(0x1u<<16)
#define	HASH_CR_MDMAT_B_0X0			(0x0u<<13)
#define	HASH_CR_MDMAT_B_0X1			(0x1u<<13)
#define	HASH_CR_MODE_B_0X0			(0x0u<<6)
#define	HASH_CR_MODE_B_0X1			(0x1u<<6)
#define	HASH_CR_DATATYPE_B_0X0		(0x0u<<4)
#define	HASH_CR_DATATYPE_B_0X1		(0x1u<<4)
#define	HASH_CR_DATATYPE_B_0X2		(0x2u<<4)
#define	HASH_CR_DATATYPE_B_0X3		(0x3u<<4)
#define	HASH_CR_DMAE_B_0X0			(0x0u<<3)
#define	HASH_CR_DMAE_B_0X1			(0x1u<<3)

// DIN Configuration

#define	HASH_DIN_DATAIN				(0xFFFFFFFFu<<0)
#define	HASH_DIN_DATAIN_0			(0x1u<<0)

// STR Configuration

#define	HASH_STR_DCAL				(0x1u<<8)
#define	HASH_STR_NBLW				(0x1Fu<<0)
#define	HASH_STR_NBLW_0				(0x1u<<0)

#define	HASH_STR_NBLW_B_0X00		(0x0u<<0)
#define	HASH_STR_NBLW_B_0X01		(0x1u<<0)
#define	HASH_STR_NBLW_B_0X02		(0x2u<<0)
#define	HASH_STR_NBLW_B_0X03		(0x3u<<0)
#define	HASH_STR_NBLW_B_0X1F		(0x1Fu<<0)

// HRA0 Configuration

#define	HASH_HRA0_H0				(0xFFFFFFFFu<<0)
#define	HASH_HRA0_H0_0				(0x1u<<0)

// HRA1 Configuration

#define	HASH_HRA1_H1				(0xFFFFFFFFu<<0)
#define	HASH_HRA1_H1_0				(0x1u<<0)

// HRA2 Configuration

#define	HASH_HRA2_H2				(0xFFFFFFFFu<<0)
#define	HASH_HRA2_H2_0				(0x1u<<0)

// HRA3 Configuration

#define	HASH_HRA3_H3				(0xFFFFFFFFu<<0)
#define	HASH_HRA3_H3_0				(0x1u<<0)

// HRA4 Configuration

#define	HASH_HRA4_H4				(0xFFFFFFFFu<<0)
#define	HASH_HRA4_H4_0				(0x1u<<0)

// IMR Configuration

#define	HASH_IMR_DCIE				(0x1u<<1)
#define	HASH_IMR_DINIE				(0x1u<<0)

#define	HASH_IMR_DCIE_B_0X0			(0x0u<<1)
#define	HASH_IMR_DCIE_B_0X1			(0x1u<<1)
#define	HASH_IMR_DINIE_B_0X0		(0x0u<<0)
#define	HASH_IMR_DINIE_B_0X1		(0x1u<<0)

// SR Configuration

#define	HASH_SR_NBWE				(0x1Fu<<16)
#define	HASH_SR_NBWE_0				(0x1u<<16)
#define	HASH_SR_DINNE				(0x1u<<15)
#define	HASH_SR_NBWP				(0x1Fu<<9)
#define	HASH_SR_NBWP_0				(0x1u<<9)
#define	HASH_SR_BUSY				(0x1u<<3)
#define	HASH_SR_DMAS				(0x1u<<2)
#define	HASH_SR_DCIS				(0x1u<<1)
#define	HASH_SR_DINIS				(0x1u<<0)

#define	HASH_SR_DINNE_B_0X0			(0x0u<<15)
#define	HASH_SR_DINNE_B_0X1			(0x1u<<15)
#define	HASH_SR_BUSY_B_0X0			(0x0u<<3)
#define	HASH_SR_BUSY_B_0X1			(0x1u<<3)
#define	HASH_SR_DMAS_B_0X0			(0x0u<<2)
#define	HASH_SR_DMAS_B_0X1			(0x1u<<2)
#define	HASH_SR_DCIS_B_0X0			(0x0u<<1)
#define	HASH_SR_DCIS_B_0X1			(0x1u<<1)
#define	HASH_SR_DINIS_B_0X0			(0x0u<<0)
#define	HASH_SR_DINIS_B_0X1			(0x1u<<0)

// CSR0 Configuration

#define	HASH_CSR0_CS0				(0xFFFFFFFFu<<0)
#define	HASH_CSR0_CS0_0				(0x1u<<0)

// CSR1 Configuration

#define	HASH_CSR1_CS1				(0xFFFFFFFFu<<0)
#define	HASH_CSR1_CS1_0				(0x1u<<0)

// CSR2 Configuration

#define	HASH_CSR2_CS2				(0xFFFFFFFFu<<0)
#define	HASH_CSR2_CS2_0				(0x1u<<0)

// CSR3 Configuration

#define	HASH_CSR3_CS3				(0xFFFFFFFFu<<0)
#define	HASH_CSR3_CS3_0				(0x1u<<0)

// CSR4 Configuration

#define	HASH_CSR4_CS4				(0xFFFFFFFFu<<0)
#define	HASH_CSR4_CS4_0				(0x1u<<0)

// CSR5 Configuration

#define	HASH_CSR5_CS5				(0xFFFFFFFFu<<0)
#define	HASH_CSR5_CS5_0				(0x1u<<0)

// CSR6 Configuration

#define	HASH_CSR6_CS6				(0xFFFFFFFFu<<0)
#define	HASH_CSR6_CS6_0				(0x1u<<0)

// CSR7 Configuration

#define	HASH_CSR7_CS7				(0xFFFFFFFFu<<0)
#define	HASH_CSR7_CS7_0				(0x1u<<0)

// CSR8 Configuration

#define	HASH_CSR8_CS8				(0xFFFFFFFFu<<0)
#define	HASH_CSR8_CS8_0				(0x1u<<0)

// CSR9 Configuration

#define	HASH_CSR9_CS9				(0xFFFFFFFFu<<0)
#define	HASH_CSR9_CS9_0				(0x1u<<0)

// CSR10 Configuration

#define	HASH_CSR10_CS10				(0xFFFFFFFFu<<0)
#define	HASH_CSR10_CS10_0			(0x1u<<0)

// CSR11 Configuration

#define	HASH_CSR11_CS11				(0xFFFFFFFFu<<0)
#define	HASH_CSR11_CS11_0			(0x1u<<0)

// CSR12 Configuration

#define	HASH_CSR12_CS12				(0xFFFFFFFFu<<0)
#define	HASH_CSR12_CS12_0			(0x1u<<0)

// CSR13 Configuration

#define	HASH_CSR13_CS13				(0xFFFFFFFFu<<0)
#define	HASH_CSR13_CS13_0			(0x1u<<0)

// CSR14 Configuration

#define	HASH_CSR14_CS14				(0xFFFFFFFFu<<0)
#define	HASH_CSR14_CS14_0			(0x1u<<0)

// CSR15 Configuration

#define	HASH_CSR15_CS15				(0xFFFFFFFFu<<0)
#define	HASH_CSR15_CS15_0			(0x1u<<0)

// CSR16 Configuration

#define	HASH_CSR16_CS16				(0xFFFFFFFFu<<0)
#define	HASH_CSR16_CS16_0			(0x1u<<0)

// CSR17 Configuration

#define	HASH_CSR17_CS17				(0xFFFFFFFFu<<0)
#define	HASH_CSR17_CS17_0			(0x1u<<0)

// CSR18 Configuration

#define	HASH_CSR18_CS18				(0xFFFFFFFFu<<0)
#define	HASH_CSR18_CS18_0			(0x1u<<0)

// CSR19 Configuration

#define	HASH_CSR19_CS19				(0xFFFFFFFFu<<0)
#define	HASH_CSR19_CS19_0			(0x1u<<0)

// CSR20 Configuration

#define	HASH_CSR20_CS20				(0xFFFFFFFFu<<0)
#define	HASH_CSR20_CS20_0			(0x1u<<0)

// CSR21 Configuration

#define	HASH_CSR21_CS21				(0xFFFFFFFFu<<0)
#define	HASH_CSR21_CS21_0			(0x1u<<0)

// CSR22 Configuration

#define	HASH_CSR22_CS22				(0xFFFFFFFFu<<0)
#define	HASH_CSR22_CS22_0			(0x1u<<0)

// CSR23 Configuration

#define	HASH_CSR23_CS23				(0xFFFFFFFFu<<0)
#define	HASH_CSR23_CS23_0			(0x1u<<0)

// CSR24 Configuration

#define	HASH_CSR24_CS24				(0xFFFFFFFFu<<0)
#define	HASH_CSR24_CS24_0			(0x1u<<0)

// CSR25 Configuration

#define	HASH_CSR25_CS25				(0xFFFFFFFFu<<0)
#define	HASH_CSR25_CS25_0			(0x1u<<0)

// CSR26 Configuration

#define	HASH_CSR26_CS26				(0xFFFFFFFFu<<0)
#define	HASH_CSR26_CS26_0			(0x1u<<0)

// CSR27 Configuration

#define	HASH_CSR27_CS27				(0xFFFFFFFFu<<0)
#define	HASH_CSR27_CS27_0			(0x1u<<0)

// CSR28 Configuration

#define	HASH_CSR28_CS28				(0xFFFFFFFFu<<0)
#define	HASH_CSR28_CS28_0			(0x1u<<0)

// CSR29 Configuration

#define	HASH_CSR29_CS29				(0xFFFFFFFFu<<0)
#define	HASH_CSR29_CS29_0			(0x1u<<0)

// CSR30 Configuration

#define	HASH_CSR30_CS30				(0xFFFFFFFFu<<0)
#define	HASH_CSR30_CS30_0			(0x1u<<0)

// CSR31 Configuration

#define	HASH_CSR31_CS31				(0xFFFFFFFFu<<0)
#define	HASH_CSR31_CS31_0			(0x1u<<0)

// CSR32 Configuration

#define	HASH_CSR32_CS32				(0xFFFFFFFFu<<0)
#define	HASH_CSR32_CS32_0			(0x1u<<0)

// CSR33 Configuration

#define	HASH_CSR33_CS33				(0xFFFFFFFFu<<0)
#define	HASH_CSR33_CS33_0			(0x1u<<0)

// CSR34 Configuration

#define	HASH_CSR34_CS34				(0xFFFFFFFFu<<0)
#define	HASH_CSR34_CS34_0			(0x1u<<0)

// CSR35 Configuration

#define	HASH_CSR35_CS35				(0xFFFFFFFFu<<0)
#define	HASH_CSR35_CS35_0			(0x1u<<0)

// CSR36 Configuration

#define	HASH_CSR36_CS36				(0xFFFFFFFFu<<0)
#define	HASH_CSR36_CS36_0			(0x1u<<0)

// CSR37 Configuration

#define	HASH_CSR37_CS37				(0xFFFFFFFFu<<0)
#define	HASH_CSR37_CS37_0			(0x1u<<0)

// CSR38 Configuration

#define	HASH_CSR38_CS38				(0xFFFFFFFFu<<0)
#define	HASH_CSR38_CS38_0			(0x1u<<0)

// CSR39 Configuration

#define	HASH_CSR39_CS39				(0xFFFFFFFFu<<0)
#define	HASH_CSR39_CS39_0			(0x1u<<0)

// CSR40 Configuration

#define	HASH_CSR40_CS40				(0xFFFFFFFFu<<0)
#define	HASH_CSR40_CS40_0			(0x1u<<0)

// CSR41 Configuration

#define	HASH_CSR41_CS41				(0xFFFFFFFFu<<0)
#define	HASH_CSR41_CS41_0			(0x1u<<0)

// CSR42 Configuration

#define	HASH_CSR42_CS42				(0xFFFFFFFFu<<0)
#define	HASH_CSR42_CS42_0			(0x1u<<0)

// CSR43 Configuration

#define	HASH_CSR43_CS43				(0xFFFFFFFFu<<0)
#define	HASH_CSR43_CS43_0			(0x1u<<0)

// CSR44 Configuration

#define	HASH_CSR44_CS44				(0xFFFFFFFFu<<0)
#define	HASH_CSR44_CS44_0			(0x1u<<0)

// CSR45 Configuration

#define	HASH_CSR45_CS45				(0xFFFFFFFFu<<0)
#define	HASH_CSR45_CS45_0			(0x1u<<0)

// CSR46 Configuration

#define	HASH_CSR46_CS46				(0xFFFFFFFFu<<0)
#define	HASH_CSR46_CS46_0			(0x1u<<0)

// CSR47 Configuration

#define	HASH_CSR47_CS47				(0xFFFFFFFFu<<0)
#define	HASH_CSR47_CS47_0			(0x1u<<0)

// CSR48 Configuration

#define	HASH_CSR48_CS48				(0xFFFFFFFFu<<0)
#define	HASH_CSR48_CS48_0			(0x1u<<0)

// CSR49 Configuration

#define	HASH_CSR49_CS49				(0xFFFFFFFFu<<0)
#define	HASH_CSR49_CS49_0			(0x1u<<0)

// CSR50 Configuration

#define	HASH_CSR50_CS50				(0xFFFFFFFFu<<0)
#define	HASH_CSR50_CS50_0			(0x1u<<0)

// CSR51 Configuration

#define	HASH_CSR51_CS51				(0xFFFFFFFFu<<0)
#define	HASH_CSR51_CS51_0			(0x1u<<0)

// CSR52 Configuration

#define	HASH_CSR52_CS52				(0xFFFFFFFFu<<0)
#define	HASH_CSR52_CS52_0			(0x1u<<0)

// CSR53 Configuration

#define	HASH_CSR53_CS53				(0xFFFFFFFFu<<0)
#define	HASH_CSR53_CS53_0			(0x1u<<0)

// CSR54 Configuration

#define	HASH_CSR54_CS54				(0xFFFFFFFFu<<0)
#define	HASH_CSR54_CS54_0			(0x1u<<0)

// CSR55 Configuration

#define	HASH_CSR55_CS55				(0xFFFFFFFFu<<0)
#define	HASH_CSR55_CS55_0			(0x1u<<0)

// CSR56 Configuration

#define	HASH_CSR56_CS56				(0xFFFFFFFFu<<0)
#define	HASH_CSR56_CS56_0			(0x1u<<0)

// CSR57 Configuration

#define	HASH_CSR57_CS57				(0xFFFFFFFFu<<0)
#define	HASH_CSR57_CS57_0			(0x1u<<0)

// CSR58 Configuration

#define	HASH_CSR58_CS58				(0xFFFFFFFFu<<0)
#define	HASH_CSR58_CS58_0			(0x1u<<0)

// CSR59 Configuration

#define	HASH_CSR59_CS59				(0xFFFFFFFFu<<0)
#define	HASH_CSR59_CS59_0			(0x1u<<0)

// CSR60 Configuration

#define	HASH_CSR60_CS60				(0xFFFFFFFFu<<0)
#define	HASH_CSR60_CS60_0			(0x1u<<0)

// CSR61 Configuration

#define	HASH_CSR61_CS61				(0xFFFFFFFFu<<0)
#define	HASH_CSR61_CS61_0			(0x1u<<0)

// CSR62 Configuration

#define	HASH_CSR62_CS62				(0xFFFFFFFFu<<0)
#define	HASH_CSR62_CS62_0			(0x1u<<0)

// CSR63 Configuration

#define	HASH_CSR63_CS63				(0xFFFFFFFFu<<0)
#define	HASH_CSR63_CS63_0			(0x1u<<0)

// CSR64 Configuration

#define	HASH_CSR64_CS64				(0xFFFFFFFFu<<0)
#define	HASH_CSR64_CS64_0			(0x1u<<0)

// CSR65 Configuration

#define	HASH_CSR65_CS65				(0xFFFFFFFFu<<0)
#define	HASH_CSR65_CS65_0			(0x1u<<0)

// CSR66 Configuration

#define	HASH_CSR66_CS66				(0xFFFFFFFFu<<0)
#define	HASH_CSR66_CS66_0			(0x1u<<0)

// CSR67 Configuration

#define	HASH_CSR67_CS67				(0xFFFFFFFFu<<0)
#define	HASH_CSR67_CS67_0			(0x1u<<0)

// CSR68 Configuration

#define	HASH_CSR68_CS68				(0xFFFFFFFFu<<0)
#define	HASH_CSR68_CS68_0			(0x1u<<0)

// CSR69 Configuration

#define	HASH_CSR69_CS69				(0xFFFFFFFFu<<0)
#define	HASH_CSR69_CS69_0			(0x1u<<0)

// CSR70 Configuration

#define	HASH_CSR70_CS70				(0xFFFFFFFFu<<0)
#define	HASH_CSR70_CS70_0			(0x1u<<0)

// CSR71 Configuration

#define	HASH_CSR71_CS71				(0xFFFFFFFFu<<0)
#define	HASH_CSR71_CS71_0			(0x1u<<0)

// CSR72 Configuration

#define	HASH_CSR72_CS72				(0xFFFFFFFFu<<0)
#define	HASH_CSR72_CS72_0			(0x1u<<0)

// CSR73 Configuration

#define	HASH_CSR73_CS73				(0xFFFFFFFFu<<0)
#define	HASH_CSR73_CS73_0			(0x1u<<0)

// CSR74 Configuration

#define	HASH_CSR74_CS74				(0xFFFFFFFFu<<0)
#define	HASH_CSR74_CS74_0			(0x1u<<0)

// CSR75 Configuration

#define	HASH_CSR75_CS75				(0xFFFFFFFFu<<0)
#define	HASH_CSR75_CS75_0			(0x1u<<0)

// CSR76 Configuration

#define	HASH_CSR76_CS76				(0xFFFFFFFFu<<0)
#define	HASH_CSR76_CS76_0			(0x1u<<0)

// CSR77 Configuration

#define	HASH_CSR77_CS77				(0xFFFFFFFFu<<0)
#define	HASH_CSR77_CS77_0			(0x1u<<0)

// CSR78 Configuration

#define	HASH_CSR78_CS78				(0xFFFFFFFFu<<0)
#define	HASH_CSR78_CS78_0			(0x1u<<0)

// CSR79 Configuration

#define	HASH_CSR79_CS79				(0xFFFFFFFFu<<0)
#define	HASH_CSR79_CS79_0			(0x1u<<0)

// CSR80 Configuration

#define	HASH_CSR80_CS80				(0xFFFFFFFFu<<0)
#define	HASH_CSR80_CS80_0			(0x1u<<0)

// CSR81 Configuration

#define	HASH_CSR81_CS81				(0xFFFFFFFFu<<0)
#define	HASH_CSR81_CS81_0			(0x1u<<0)

// CSR82 Configuration

#define	HASH_CSR82_CS82				(0xFFFFFFFFu<<0)
#define	HASH_CSR82_CS82_0			(0x1u<<0)

// CSR83 Configuration

#define	HASH_CSR83_CS83				(0xFFFFFFFFu<<0)
#define	HASH_CSR83_CS83_0			(0x1u<<0)

// CSR84 Configuration

#define	HASH_CSR84_CS84				(0xFFFFFFFFu<<0)
#define	HASH_CSR84_CS84_0			(0x1u<<0)

// CSR85 Configuration

#define	HASH_CSR85_CS85				(0xFFFFFFFFu<<0)
#define	HASH_CSR85_CS85_0			(0x1u<<0)

// CSR86 Configuration

#define	HASH_CSR86_CS86				(0xFFFFFFFFu<<0)
#define	HASH_CSR86_CS86_0			(0x1u<<0)

// CSR87 Configuration

#define	HASH_CSR87_CS87				(0xFFFFFFFFu<<0)
#define	HASH_CSR87_CS87_0			(0x1u<<0)

// CSR88 Configuration

#define	HASH_CSR88_CS88				(0xFFFFFFFFu<<0)
#define	HASH_CSR88_CS88_0			(0x1u<<0)

// CSR89 Configuration

#define	HASH_CSR89_CS89				(0xFFFFFFFFu<<0)
#define	HASH_CSR89_CS89_0			(0x1u<<0)

// CSR90 Configuration

#define	HASH_CSR90_CS90				(0xFFFFFFFFu<<0)
#define	HASH_CSR90_CS90_0			(0x1u<<0)

// CSR91 Configuration

#define	HASH_CSR91_CS91				(0xFFFFFFFFu<<0)
#define	HASH_CSR91_CS91_0			(0x1u<<0)

// CSR92 Configuration

#define	HASH_CSR92_CS92				(0xFFFFFFFFu<<0)
#define	HASH_CSR92_CS92_0			(0x1u<<0)

// CSR93 Configuration

#define	HASH_CSR93_CS93				(0xFFFFFFFFu<<0)
#define	HASH_CSR93_CS93_0			(0x1u<<0)

// CSR94 Configuration

#define	HASH_CSR94_CS94				(0xFFFFFFFFu<<0)
#define	HASH_CSR94_CS94_0			(0x1u<<0)

// CSR95 Configuration

#define	HASH_CSR95_CS95				(0xFFFFFFFFu<<0)
#define	HASH_CSR95_CS95_0			(0x1u<<0)

// CSR96 Configuration

#define	HASH_CSR96_CS96				(0xFFFFFFFFu<<0)
#define	HASH_CSR96_CS96_0			(0x1u<<0)

// CSR97 Configuration

#define	HASH_CSR97_CS97				(0xFFFFFFFFu<<0)
#define	HASH_CSR97_CS97_0			(0x1u<<0)

// CSR98 Configuration

#define	HASH_CSR98_CS98				(0xFFFFFFFFu<<0)
#define	HASH_CSR98_CS98_0			(0x1u<<0)

// CSR99 Configuration

#define	HASH_CSR99_CS99				(0xFFFFFFFFu<<0)
#define	HASH_CSR99_CS99_0			(0x1u<<0)

// CSR100 Configuration

#define	HASH_CSR100_CS100			(0xFFFFFFFFu<<0)
#define	HASH_CSR100_CS100_0			(0x1u<<0)

// CSR101 Configuration

#define	HASH_CSR101_CS101			(0xFFFFFFFFu<<0)
#define	HASH_CSR101_CS101_0			(0x1u<<0)

// CSR102 Configuration

#define	HASH_CSR102_CS102			(0xFFFFFFFFu<<0)
#define	HASH_CSR102_CS102_0			(0x1u<<0)

// HR0 Configuration

#define	HASH_HR0_H0					(0xFFFFFFFFu<<0)
#define	HASH_HR0_H0_0				(0x1u<<0)

// HR1 Configuration

#define	HASH_HR1_H1					(0xFFFFFFFFu<<0)
#define	HASH_HR1_H1_0				(0x1u<<0)

// HR2 Configuration

#define	HASH_HR2_H2					(0xFFFFFFFFu<<0)
#define	HASH_HR2_H2_0				(0x1u<<0)

// HR3 Configuration

#define	HASH_HR3_H3					(0xFFFFFFFFu<<0)
#define	HASH_HR3_H3_0				(0x1u<<0)

// HR4 Configuration

#define	HASH_HR4_H4					(0xFFFFFFFFu<<0)
#define	HASH_HR4_H4_0				(0x1u<<0)

// HR5 Configuration

#define	HASH_HR5_H5					(0xFFFFFFFFu<<0)
#define	HASH_HR5_H5_0				(0x1u<<0)

// HR6 Configuration

#define	HASH_HR6_H6					(0xFFFFFFFFu<<0)
#define	HASH_HR6_H6_0				(0x1u<<0)

// HR7 Configuration

#define	HASH_HR7_H7					(0xFFFFFFFFu<<0)
#define	HASH_HR7_H7_0				(0x1u<<0)

// HR8 Configuration

#define	HASH_HR8_H8					(0xFFFFFFFFu<<0)
#define	HASH_HR8_H8_0				(0x1u<<0)

// HR9 Configuration

#define	HASH_HR9_H9					(0xFFFFFFFFu<<0)
#define	HASH_HR9_H9_0				(0x1u<<0)

// HR10 Configuration

#define	HASH_HR10_H10				(0xFFFFFFFFu<<0)
#define	HASH_HR10_H10_0				(0x1u<<0)

// HR11 Configuration

#define	HASH_HR11_H11				(0xFFFFFFFFu<<0)
#define	HASH_HR11_H11_0				(0x1u<<0)

// HR12 Configuration

#define	HASH_HR12_H12				(0xFFFFFFFFu<<0)
#define	HASH_HR12_H12_0				(0x1u<<0)

// HR13 Configuration

#define	HASH_HR13_H13				(0xFFFFFFFFu<<0)
#define	HASH_HR13_H13_0				(0x1u<<0)

// HR14 Configuration

#define	HASH_HR14_H14				(0xFFFFFFFFu<<0)
#define	HASH_HR14_H14_0				(0x1u<<0)

// HR15 Configuration

#define	HASH_HR15_H15				(0xFFFFFFFFu<<0)
#define	HASH_HR15_H15_0				(0x1u<<0)
