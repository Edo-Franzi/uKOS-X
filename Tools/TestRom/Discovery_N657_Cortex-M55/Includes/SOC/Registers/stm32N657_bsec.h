/*
; stm32N657_bsec.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_bsec equates.
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

// BSEC address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	FVR0;
	volatile	uint32_t	FVR1;
	volatile	uint32_t	FVR2;
	volatile	uint32_t	FVR3;
	volatile	uint32_t	FVR4;
	volatile	uint32_t	FVR5;
	volatile	uint32_t	FVR6;
	volatile	uint32_t	FVR7;
	volatile	uint32_t	FVR8;
	volatile	uint32_t	FVR9;
	volatile	uint32_t	FVR10;
	volatile	uint32_t	FVR11;
	volatile	uint32_t	FVR12;
	volatile	uint32_t	FVR13;
	volatile	uint32_t	FVR14;
	volatile	uint32_t	FVR15;
	volatile	uint32_t	FVR16;
	volatile	uint32_t	FVR17;
	volatile	uint32_t	FVR18;
	volatile	uint32_t	FVR19;
	volatile	uint32_t	FVR20;
	volatile	uint32_t	FVR21;
	volatile	uint32_t	FVR22;
	volatile	uint32_t	FVR23;
	volatile	uint32_t	FVR24;
	volatile	uint32_t	FVR25;
	volatile	uint32_t	FVR26;
	volatile	uint32_t	FVR27;
	volatile	uint32_t	FVR28;
	volatile	uint32_t	FVR29;
	volatile	uint32_t	FVR30;
	volatile	uint32_t	FVR31;
	volatile	uint32_t	FVR32;
	volatile	uint32_t	FVR33;
	volatile	uint32_t	FVR34;
	volatile	uint32_t	FVR35;
	volatile	uint32_t	FVR36;
	volatile	uint32_t	FVR37;
	volatile	uint32_t	FVR38;
	volatile	uint32_t	FVR39;
	volatile	uint32_t	FVR40;
	volatile	uint32_t	FVR41;
	volatile	uint32_t	FVR42;
	volatile	uint32_t	FVR43;
	volatile	uint32_t	FVR44;
	volatile	uint32_t	FVR45;
	volatile	uint32_t	FVR46;
	volatile	uint32_t	FVR47;
	volatile	uint32_t	FVR48;
	volatile	uint32_t	FVR49;
	volatile	uint32_t	FVR50;
	volatile	uint32_t	FVR51;
	volatile	uint32_t	FVR52;
	volatile	uint32_t	FVR53;
	volatile	uint32_t	FVR54;
	volatile	uint32_t	FVR55;
	volatile	uint32_t	FVR56;
	volatile	uint32_t	FVR57;
	volatile	uint32_t	FVR58;
	volatile	uint32_t	FVR59;
	volatile	uint32_t	FVR60;
	volatile	uint32_t	FVR61;
	volatile	uint32_t	FVR62;
	volatile	uint32_t	FVR63;
	volatile	uint32_t	FVR64;
	volatile	uint32_t	FVR65;
	volatile	uint32_t	FVR66;
	volatile	uint32_t	FVR67;
	volatile	uint32_t	FVR68;
	volatile	uint32_t	FVR69;
	volatile	uint32_t	FVR70;
	volatile	uint32_t	FVR71;
	volatile	uint32_t	FVR72;
	volatile	uint32_t	FVR73;
	volatile	uint32_t	FVR74;
	volatile	uint32_t	FVR75;
	volatile	uint32_t	FVR76;
	volatile	uint32_t	FVR77;
	volatile	uint32_t	FVR78;
	volatile	uint32_t	FVR79;
	volatile	uint32_t	FVR80;
	volatile	uint32_t	FVR81;
	volatile	uint32_t	FVR82;
	volatile	uint32_t	FVR83;
	volatile	uint32_t	FVR84;
	volatile	uint32_t	FVR85;
	volatile	uint32_t	FVR86;
	volatile	uint32_t	FVR87;
	volatile	uint32_t	FVR88;
	volatile	uint32_t	FVR89;
	volatile	uint32_t	FVR90;
	volatile	uint32_t	FVR91;
	volatile	uint32_t	FVR92;
	volatile	uint32_t	FVR93;
	volatile	uint32_t	FVR94;
	volatile	uint32_t	FVR95;
	volatile	uint32_t	FVR96;
	volatile	uint32_t	FVR97;
	volatile	uint32_t	FVR98;
	volatile	uint32_t	FVR99;
	volatile	uint32_t	FVR100;
	volatile	uint32_t	FVR101;
	volatile	uint32_t	FVR102;
	volatile	uint32_t	FVR103;
	volatile	uint32_t	FVR104;
	volatile	uint32_t	FVR105;
	volatile	uint32_t	FVR106;
	volatile	uint32_t	FVR107;
	volatile	uint32_t	FVR108;
	volatile	uint32_t	FVR109;
	volatile	uint32_t	FVR110;
	volatile	uint32_t	FVR111;
	volatile	uint32_t	FVR112;
	volatile	uint32_t	FVR113;
	volatile	uint32_t	FVR114;
	volatile	uint32_t	FVR115;
	volatile	uint32_t	FVR116;
	volatile	uint32_t	FVR117;
	volatile	uint32_t	FVR118;
	volatile	uint32_t	FVR119;
	volatile	uint32_t	FVR120;
	volatile	uint32_t	FVR121;
	volatile	uint32_t	FVR122;
	volatile	uint32_t	FVR123;
	volatile	uint32_t	FVR124;
	volatile	uint32_t	FVR125;
	volatile	uint32_t	FVR126;
	volatile	uint32_t	FVR127;
	volatile	uint32_t	FVR128;
	volatile	uint32_t	FVR129;
	volatile	uint32_t	FVR130;
	volatile	uint32_t	FVR131;
	volatile	uint32_t	FVR132;
	volatile	uint32_t	FVR133;
	volatile	uint32_t	FVR134;
	volatile	uint32_t	FVR135;
	volatile	uint32_t	FVR136;
	volatile	uint32_t	FVR137;
	volatile	uint32_t	FVR138;
	volatile	uint32_t	FVR139;
	volatile	uint32_t	FVR140;
	volatile	uint32_t	FVR141;
	volatile	uint32_t	FVR142;
	volatile	uint32_t	FVR143;
	volatile	uint32_t	FVR144;
	volatile	uint32_t	FVR145;
	volatile	uint32_t	FVR146;
	volatile	uint32_t	FVR147;
	volatile	uint32_t	FVR148;
	volatile	uint32_t	FVR149;
	volatile	uint32_t	FVR150;
	volatile	uint32_t	FVR151;
	volatile	uint32_t	FVR152;
	volatile	uint32_t	FVR153;
	volatile	uint32_t	FVR154;
	volatile	uint32_t	FVR155;
	volatile	uint32_t	FVR156;
	volatile	uint32_t	FVR157;
	volatile	uint32_t	FVR158;
	volatile	uint32_t	FVR159;
	volatile	uint32_t	FVR160;
	volatile	uint32_t	FVR161;
	volatile	uint32_t	FVR162;
	volatile	uint32_t	FVR163;
	volatile	uint32_t	FVR164;
	volatile	uint32_t	FVR165;
	volatile	uint32_t	FVR166;
	volatile	uint32_t	FVR167;
	volatile	uint32_t	FVR168;
	volatile	uint32_t	FVR169;
	volatile	uint32_t	FVR170;
	volatile	uint32_t	FVR171;
	volatile	uint32_t	FVR172;
	volatile	uint32_t	FVR173;
	volatile	uint32_t	FVR174;
	volatile	uint32_t	FVR175;
	volatile	uint32_t	FVR176;
	volatile	uint32_t	FVR177;
	volatile	uint32_t	FVR178;
	volatile	uint32_t	FVR179;
	volatile	uint32_t	FVR180;
	volatile	uint32_t	FVR181;
	volatile	uint32_t	FVR182;
	volatile	uint32_t	FVR183;
	volatile	uint32_t	FVR184;
	volatile	uint32_t	FVR185;
	volatile	uint32_t	FVR186;
	volatile	uint32_t	FVR187;
	volatile	uint32_t	FVR188;
	volatile	uint32_t	FVR189;
	volatile	uint32_t	FVR190;
	volatile	uint32_t	FVR191;
	volatile	uint32_t	FVR192;
	volatile	uint32_t	FVR193;
	volatile	uint32_t	FVR194;
	volatile	uint32_t	FVR195;
	volatile	uint32_t	FVR196;
	volatile	uint32_t	FVR197;
	volatile	uint32_t	FVR198;
	volatile	uint32_t	FVR199;
	volatile	uint32_t	FVR200;
	volatile	uint32_t	FVR201;
	volatile	uint32_t	FVR202;
	volatile	uint32_t	FVR203;
	volatile	uint32_t	FVR204;
	volatile	uint32_t	FVR205;
	volatile	uint32_t	FVR206;
	volatile	uint32_t	FVR207;
	volatile	uint32_t	FVR208;
	volatile	uint32_t	FVR209;
	volatile	uint32_t	FVR210;
	volatile	uint32_t	FVR211;
	volatile	uint32_t	FVR212;
	volatile	uint32_t	FVR213;
	volatile	uint32_t	FVR214;
	volatile	uint32_t	FVR215;
	volatile	uint32_t	FVR216;
	volatile	uint32_t	FVR217;
	volatile	uint32_t	FVR218;
	volatile	uint32_t	FVR219;
	volatile	uint32_t	FVR220;
	volatile	uint32_t	FVR221;
	volatile	uint32_t	FVR222;
	volatile	uint32_t	FVR223;
	volatile	uint32_t	FVR224;
	volatile	uint32_t	FVR225;
	volatile	uint32_t	FVR226;
	volatile	uint32_t	FVR227;
	volatile	uint32_t	FVR228;
	volatile	uint32_t	FVR229;
	volatile	uint32_t	FVR230;
	volatile	uint32_t	FVR231;
	volatile	uint32_t	FVR232;
	volatile	uint32_t	FVR233;
	volatile	uint32_t	FVR234;
	volatile	uint32_t	FVR235;
	volatile	uint32_t	FVR236;
	volatile	uint32_t	FVR237;
	volatile	uint32_t	FVR238;
	volatile	uint32_t	FVR239;
	volatile	uint32_t	FVR240;
	volatile	uint32_t	FVR241;
	volatile	uint32_t	FVR242;
	volatile	uint32_t	FVR243;
	volatile	uint32_t	FVR244;
	volatile	uint32_t	FVR245;
	volatile	uint32_t	FVR246;
	volatile	uint32_t	FVR247;
	volatile	uint32_t	FVR248;
	volatile	uint32_t	FVR249;
	volatile	uint32_t	FVR250;
	volatile	uint32_t	FVR251;
	volatile	uint32_t	FVR252;
	volatile	uint32_t	FVR253;
	volatile	uint32_t	FVR254;
	volatile	uint32_t	FVR255;
	volatile	uint32_t	FVR256;
	volatile	uint32_t	FVR257;
	volatile	uint32_t	FVR258;
	volatile	uint32_t	FVR259;
	volatile	uint32_t	FVR260;
	volatile	uint32_t	FVR261;
	volatile	uint32_t	FVR262;
	volatile	uint32_t	FVR263;
	volatile	uint32_t	FVR264;
	volatile	uint32_t	FVR265;
	volatile	uint32_t	FVR266;
	volatile	uint32_t	FVR267;
	volatile	uint32_t	FVR268;
	volatile	uint32_t	FVR269;
	volatile	uint32_t	FVR270;
	volatile	uint32_t	FVR271;
	volatile	uint32_t	FVR272;
	volatile	uint32_t	FVR273;
	volatile	uint32_t	FVR274;
	volatile	uint32_t	FVR275;
	volatile	uint32_t	FVR276;
	volatile	uint32_t	FVR277;
	volatile	uint32_t	FVR278;
	volatile	uint32_t	FVR279;
	volatile	uint32_t	FVR280;
	volatile	uint32_t	FVR281;
	volatile	uint32_t	FVR282;
	volatile	uint32_t	FVR283;
	volatile	uint32_t	FVR284;
	volatile	uint32_t	FVR285;
	volatile	uint32_t	FVR286;
	volatile	uint32_t	FVR287;
	volatile	uint32_t	FVR288;
	volatile	uint32_t	FVR289;
	volatile	uint32_t	FVR290;
	volatile	uint32_t	FVR291;
	volatile	uint32_t	FVR292;
	volatile	uint32_t	FVR293;
	volatile	uint32_t	FVR294;
	volatile	uint32_t	FVR295;
	volatile	uint32_t	FVR296;
	volatile	uint32_t	FVR297;
	volatile	uint32_t	FVR298;
	volatile	uint32_t	FVR299;
	volatile	uint32_t	FVR300;
	volatile	uint32_t	FVR301;
	volatile	uint32_t	FVR302;
	volatile	uint32_t	FVR303;
	volatile	uint32_t	FVR304;
	volatile	uint32_t	FVR305;
	volatile	uint32_t	FVR306;
	volatile	uint32_t	FVR307;
	volatile	uint32_t	FVR308;
	volatile	uint32_t	FVR309;
	volatile	uint32_t	FVR310;
	volatile	uint32_t	FVR311;
	volatile	uint32_t	FVR312;
	volatile	uint32_t	FVR313;
	volatile	uint32_t	FVR314;
	volatile	uint32_t	FVR315;
	volatile	uint32_t	FVR316;
	volatile	uint32_t	FVR317;
	volatile	uint32_t	FVR318;
	volatile	uint32_t	FVR319;
	volatile	uint32_t	FVR320;
	volatile	uint32_t	FVR321;
	volatile	uint32_t	FVR322;
	volatile	uint32_t	FVR323;
	volatile	uint32_t	FVR324;
	volatile	uint32_t	FVR325;
	volatile	uint32_t	FVR326;
	volatile	uint32_t	FVR327;
	volatile	uint32_t	FVR328;
	volatile	uint32_t	FVR329;
	volatile	uint32_t	FVR330;
	volatile	uint32_t	FVR331;
	volatile	uint32_t	FVR332;
	volatile	uint32_t	FVR333;
	volatile	uint32_t	FVR334;
	volatile	uint32_t	FVR335;
	volatile	uint32_t	FVR336;
	volatile	uint32_t	FVR337;
	volatile	uint32_t	FVR338;
	volatile	uint32_t	FVR339;
	volatile	uint32_t	FVR340;
	volatile	uint32_t	FVR341;
	volatile	uint32_t	FVR342;
	volatile	uint32_t	FVR343;
	volatile	uint32_t	FVR344;
	volatile	uint32_t	FVR345;
	volatile	uint32_t	FVR346;
	volatile	uint32_t	FVR347;
	volatile	uint32_t	FVR348;
	volatile	uint32_t	FVR349;
	volatile	uint32_t	FVR350;
	volatile	uint32_t	FVR351;
	volatile	uint32_t	FVR352;
	volatile	uint32_t	FVR353;
	volatile	uint32_t	FVR354;
	volatile	uint32_t	FVR355;
	volatile	uint32_t	FVR356;
	volatile	uint32_t	FVR357;
	volatile	uint32_t	FVR358;
	volatile	uint32_t	FVR359;
	volatile	uint32_t	FVR360;
	volatile	uint32_t	FVR361;
	volatile	uint32_t	FVR362;
	volatile	uint32_t	FVR363;
	volatile	uint32_t	FVR364;
	volatile	uint32_t	FVR365;
	volatile	uint32_t	FVR366;
	volatile	uint32_t	FVR367;
	volatile	uint32_t	FVR368;
	volatile	uint32_t	FVR369;
	volatile	uint32_t	FVR370;
	volatile	uint32_t	FVR371;
	volatile	uint32_t	FVR372;
	volatile	uint32_t	FVR373;
	volatile	uint32_t	FVR374;
	volatile	uint32_t	FVR375;
	volatile	uint32_t	RESERVED0[136];
	volatile	uint32_t	SPLOCK0;
	volatile	uint32_t	SPLOCK1;
	volatile	uint32_t	SPLOCK2;
	volatile	uint32_t	SPLOCK3;
	volatile	uint32_t	SPLOCK4;
	volatile	uint32_t	SPLOCK5;
	volatile	uint32_t	SPLOCK6;
	volatile	uint32_t	SPLOCK7;
	volatile	uint32_t	SPLOCK8;
	volatile	uint32_t	SPLOCK9;
	volatile	uint32_t	SPLOCK10;
	volatile	uint32_t	SPLOCK11;
	volatile	uint32_t	RESERVED1[4];
	volatile	uint32_t	SWLOCK0;
	volatile	uint32_t	SWLOCK1;
	volatile	uint32_t	SWLOCK2;
	volatile	uint32_t	SWLOCK3;
	volatile	uint32_t	SWLOCK4;
	volatile	uint32_t	SWLOCK5;
	volatile	uint32_t	SWLOCK6;
	volatile	uint32_t	SWLOCK7;
	volatile	uint32_t	SWLOCK8;
	volatile	uint32_t	SWLOCK9;
	volatile	uint32_t	SWLOCK10;
	volatile	uint32_t	SWLOCK11;
	volatile	uint32_t	RESERVED2[4];
	volatile	uint32_t	SRLOCK0;
	volatile	uint32_t	SRLOCK1;
	volatile	uint32_t	SRLOCK2;
	volatile	uint32_t	SRLOCK3;
	volatile	uint32_t	SRLOCK4;
	volatile	uint32_t	SRLOCK5;
	volatile	uint32_t	SRLOCK6;
	volatile	uint32_t	SRLOCK7;
	volatile	uint32_t	SRLOCK8;
	volatile	uint32_t	SRLOCK9;
	volatile	uint32_t	SRLOCK10;
	volatile	uint32_t	SRLOCK11;
	volatile	uint32_t	RESERVED3[4];
	volatile	uint32_t	OTPVLDR0;
	volatile	uint32_t	OTPVLDR1;
	volatile	uint32_t	OTPVLDR2;
	volatile	uint32_t	OTPVLDR3;
	volatile	uint32_t	OTPVLDR4;
	volatile	uint32_t	OTPVLDR5;
	volatile	uint32_t	OTPVLDR6;
	volatile	uint32_t	OTPVLDR7;
	volatile	uint32_t	OTPVLDR8;
	volatile	uint32_t	OTPVLDR9;
	volatile	uint32_t	OTPVLDR10;
	volatile	uint32_t	OTPVLDR11;
	volatile	uint32_t	RESERVED4[20];
	volatile	uint32_t	SFSR0;
	volatile	uint32_t	SFSR1;
	volatile	uint32_t	SFSR2;
	volatile	uint32_t	SFSR3;
	volatile	uint32_t	SFSR4;
	volatile	uint32_t	SFSR5;
	volatile	uint32_t	SFSR6;
	volatile	uint32_t	SFSR7;
	volatile	uint32_t	SFSR8;
	volatile	uint32_t	SFSR9;
	volatile	uint32_t	SFSR10;
	volatile	uint32_t	SFSR11;
	volatile	uint32_t	RESERVED5[165];
	volatile	uint32_t	OTPCR;
	volatile	uint32_t	WDR;
	volatile	uint32_t	RESERVED6[125];
	volatile	uint32_t	SCRATCHR0;
	volatile	uint32_t	SCRATCHR1;
	volatile	uint32_t	SCRATCHR2;
	volatile	uint32_t	SCRATCHR3;
	volatile	uint32_t	LOCKR;
	volatile	uint32_t	JTAGINR;
	volatile	uint32_t	JTAGOUTR;
	volatile	uint32_t	RESERVED7[2];
	volatile	uint32_t	UNMAPR;
	volatile	uint32_t	RESERVED8[6];
	volatile	uint32_t	SR;
	volatile	uint32_t	OTPSR;
	volatile	uint32_t	RESERVED9[14];
	volatile	uint32_t	EPOCHR0;
	volatile	uint32_t	EPOCHR1;
	volatile	uint32_t	EPOCH_SELR;
	volatile	uint32_t	DBGCR;
	volatile	uint32_t	AP_UNLOCK;
	volatile	uint32_t	HDPLSR;
	volatile	uint32_t	HDPLCR;
	volatile	uint32_t	NEXTLR;
	volatile	uint32_t	RESERVED10[40];
	volatile	uint32_t	WOSCR0;
	volatile	uint32_t	WOSCR1;
	volatile	uint32_t	WOSCR2;
	volatile	uint32_t	WOSCR3;
	volatile	uint32_t	WOSCR4;
	volatile	uint32_t	WOSCR5;
	volatile	uint32_t	WOSCR6;
	volatile	uint32_t	WOSCR7;
	volatile	uint32_t	RESERVED11[34];
	volatile	uint32_t	HRCR;
	volatile	uint32_t	WRCR;
} BSEC_TypeDef;

#if (defined(__cplusplus))
#define	BSEC_NS	reinterpret_cast<BSEC_TypeDef *>(0x46009000u)
#define	BSEC_S	reinterpret_cast<BSEC_TypeDef *>(0x56009000u)

#else
#define	BSEC_NS	((BSEC_TypeDef *)0x46009000u)
#define	BSEC_S	((BSEC_TypeDef *)0x56009000u)
#endif

// FVR0 Configuration

#define	BSEC_FVR0_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR0_FV_0					(0x1u<<0)

// FVR1 Configuration

#define	BSEC_FVR1_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR1_FV_0					(0x1u<<0)

// FVR2 Configuration

#define	BSEC_FVR2_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR2_FV_0					(0x1u<<0)

// FVR3 Configuration

#define	BSEC_FVR3_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR3_FV_0					(0x1u<<0)

// FVR4 Configuration

#define	BSEC_FVR4_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR4_FV_0					(0x1u<<0)

// FVR5 Configuration

#define	BSEC_FVR5_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR5_FV_0					(0x1u<<0)

// FVR6 Configuration

#define	BSEC_FVR6_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR6_FV_0					(0x1u<<0)

// FVR7 Configuration

#define	BSEC_FVR7_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR7_FV_0					(0x1u<<0)

// FVR8 Configuration

#define	BSEC_FVR8_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR8_FV_0					(0x1u<<0)

// FVR9 Configuration

#define	BSEC_FVR9_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR9_FV_0					(0x1u<<0)

// FVR10 Configuration

#define	BSEC_FVR10_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR10_FV_0					(0x1u<<0)

// FVR11 Configuration

#define	BSEC_FVR11_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR11_FV_0					(0x1u<<0)

// FVR12 Configuration

#define	BSEC_FVR12_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR12_FV_0					(0x1u<<0)

// FVR13 Configuration

#define	BSEC_FVR13_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR13_FV_0					(0x1u<<0)

// FVR14 Configuration

#define	BSEC_FVR14_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR14_FV_0					(0x1u<<0)

// FVR15 Configuration

#define	BSEC_FVR15_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR15_FV_0					(0x1u<<0)

// FVR16 Configuration

#define	BSEC_FVR16_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR16_FV_0					(0x1u<<0)

// FVR17 Configuration

#define	BSEC_FVR17_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR17_FV_0					(0x1u<<0)

// FVR18 Configuration

#define	BSEC_FVR18_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR18_FV_0					(0x1u<<0)

// FVR19 Configuration

#define	BSEC_FVR19_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR19_FV_0					(0x1u<<0)

// FVR20 Configuration

#define	BSEC_FVR20_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR20_FV_0					(0x1u<<0)

// FVR21 Configuration

#define	BSEC_FVR21_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR21_FV_0					(0x1u<<0)

// FVR22 Configuration

#define	BSEC_FVR22_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR22_FV_0					(0x1u<<0)

// FVR23 Configuration

#define	BSEC_FVR23_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR23_FV_0					(0x1u<<0)

// FVR24 Configuration

#define	BSEC_FVR24_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR24_FV_0					(0x1u<<0)

// FVR25 Configuration

#define	BSEC_FVR25_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR25_FV_0					(0x1u<<0)

// FVR26 Configuration

#define	BSEC_FVR26_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR26_FV_0					(0x1u<<0)

// FVR27 Configuration

#define	BSEC_FVR27_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR27_FV_0					(0x1u<<0)

// FVR28 Configuration

#define	BSEC_FVR28_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR28_FV_0					(0x1u<<0)

// FVR29 Configuration

#define	BSEC_FVR29_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR29_FV_0					(0x1u<<0)

// FVR30 Configuration

#define	BSEC_FVR30_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR30_FV_0					(0x1u<<0)

// FVR31 Configuration

#define	BSEC_FVR31_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR31_FV_0					(0x1u<<0)

// FVR32 Configuration

#define	BSEC_FVR32_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR32_FV_0					(0x1u<<0)

// FVR33 Configuration

#define	BSEC_FVR33_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR33_FV_0					(0x1u<<0)

// FVR34 Configuration

#define	BSEC_FVR34_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR34_FV_0					(0x1u<<0)

// FVR35 Configuration

#define	BSEC_FVR35_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR35_FV_0					(0x1u<<0)

// FVR36 Configuration

#define	BSEC_FVR36_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR36_FV_0					(0x1u<<0)

// FVR37 Configuration

#define	BSEC_FVR37_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR37_FV_0					(0x1u<<0)

// FVR38 Configuration

#define	BSEC_FVR38_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR38_FV_0					(0x1u<<0)

// FVR39 Configuration

#define	BSEC_FVR39_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR39_FV_0					(0x1u<<0)

// FVR40 Configuration

#define	BSEC_FVR40_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR40_FV_0					(0x1u<<0)

// FVR41 Configuration

#define	BSEC_FVR41_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR41_FV_0					(0x1u<<0)

// FVR42 Configuration

#define	BSEC_FVR42_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR42_FV_0					(0x1u<<0)

// FVR43 Configuration

#define	BSEC_FVR43_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR43_FV_0					(0x1u<<0)

// FVR44 Configuration

#define	BSEC_FVR44_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR44_FV_0					(0x1u<<0)

// FVR45 Configuration

#define	BSEC_FVR45_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR45_FV_0					(0x1u<<0)

// FVR46 Configuration

#define	BSEC_FVR46_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR46_FV_0					(0x1u<<0)

// FVR47 Configuration

#define	BSEC_FVR47_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR47_FV_0					(0x1u<<0)

// FVR48 Configuration

#define	BSEC_FVR48_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR48_FV_0					(0x1u<<0)

// FVR49 Configuration

#define	BSEC_FVR49_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR49_FV_0					(0x1u<<0)

// FVR50 Configuration

#define	BSEC_FVR50_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR50_FV_0					(0x1u<<0)

// FVR51 Configuration

#define	BSEC_FVR51_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR51_FV_0					(0x1u<<0)

// FVR52 Configuration

#define	BSEC_FVR52_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR52_FV_0					(0x1u<<0)

// FVR53 Configuration

#define	BSEC_FVR53_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR53_FV_0					(0x1u<<0)

// FVR54 Configuration

#define	BSEC_FVR54_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR54_FV_0					(0x1u<<0)

// FVR55 Configuration

#define	BSEC_FVR55_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR55_FV_0					(0x1u<<0)

// FVR56 Configuration

#define	BSEC_FVR56_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR56_FV_0					(0x1u<<0)

// FVR57 Configuration

#define	BSEC_FVR57_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR57_FV_0					(0x1u<<0)

// FVR58 Configuration

#define	BSEC_FVR58_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR58_FV_0					(0x1u<<0)

// FVR59 Configuration

#define	BSEC_FVR59_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR59_FV_0					(0x1u<<0)

// FVR60 Configuration

#define	BSEC_FVR60_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR60_FV_0					(0x1u<<0)

// FVR61 Configuration

#define	BSEC_FVR61_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR61_FV_0					(0x1u<<0)

// FVR62 Configuration

#define	BSEC_FVR62_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR62_FV_0					(0x1u<<0)

// FVR63 Configuration

#define	BSEC_FVR63_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR63_FV_0					(0x1u<<0)

// FVR64 Configuration

#define	BSEC_FVR64_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR64_FV_0					(0x1u<<0)

// FVR65 Configuration

#define	BSEC_FVR65_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR65_FV_0					(0x1u<<0)

// FVR66 Configuration

#define	BSEC_FVR66_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR66_FV_0					(0x1u<<0)

// FVR67 Configuration

#define	BSEC_FVR67_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR67_FV_0					(0x1u<<0)

// FVR68 Configuration

#define	BSEC_FVR68_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR68_FV_0					(0x1u<<0)

// FVR69 Configuration

#define	BSEC_FVR69_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR69_FV_0					(0x1u<<0)

// FVR70 Configuration

#define	BSEC_FVR70_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR70_FV_0					(0x1u<<0)

// FVR71 Configuration

#define	BSEC_FVR71_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR71_FV_0					(0x1u<<0)

// FVR72 Configuration

#define	BSEC_FVR72_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR72_FV_0					(0x1u<<0)

// FVR73 Configuration

#define	BSEC_FVR73_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR73_FV_0					(0x1u<<0)

// FVR74 Configuration

#define	BSEC_FVR74_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR74_FV_0					(0x1u<<0)

// FVR75 Configuration

#define	BSEC_FVR75_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR75_FV_0					(0x1u<<0)

// FVR76 Configuration

#define	BSEC_FVR76_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR76_FV_0					(0x1u<<0)

// FVR77 Configuration

#define	BSEC_FVR77_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR77_FV_0					(0x1u<<0)

// FVR78 Configuration

#define	BSEC_FVR78_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR78_FV_0					(0x1u<<0)

// FVR79 Configuration

#define	BSEC_FVR79_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR79_FV_0					(0x1u<<0)

// FVR80 Configuration

#define	BSEC_FVR80_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR80_FV_0					(0x1u<<0)

// FVR81 Configuration

#define	BSEC_FVR81_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR81_FV_0					(0x1u<<0)

// FVR82 Configuration

#define	BSEC_FVR82_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR82_FV_0					(0x1u<<0)

// FVR83 Configuration

#define	BSEC_FVR83_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR83_FV_0					(0x1u<<0)

// FVR84 Configuration

#define	BSEC_FVR84_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR84_FV_0					(0x1u<<0)

// FVR85 Configuration

#define	BSEC_FVR85_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR85_FV_0					(0x1u<<0)

// FVR86 Configuration

#define	BSEC_FVR86_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR86_FV_0					(0x1u<<0)

// FVR87 Configuration

#define	BSEC_FVR87_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR87_FV_0					(0x1u<<0)

// FVR88 Configuration

#define	BSEC_FVR88_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR88_FV_0					(0x1u<<0)

// FVR89 Configuration

#define	BSEC_FVR89_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR89_FV_0					(0x1u<<0)

// FVR90 Configuration

#define	BSEC_FVR90_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR90_FV_0					(0x1u<<0)

// FVR91 Configuration

#define	BSEC_FVR91_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR91_FV_0					(0x1u<<0)

// FVR92 Configuration

#define	BSEC_FVR92_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR92_FV_0					(0x1u<<0)

// FVR93 Configuration

#define	BSEC_FVR93_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR93_FV_0					(0x1u<<0)

// FVR94 Configuration

#define	BSEC_FVR94_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR94_FV_0					(0x1u<<0)

// FVR95 Configuration

#define	BSEC_FVR95_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR95_FV_0					(0x1u<<0)

// FVR96 Configuration

#define	BSEC_FVR96_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR96_FV_0					(0x1u<<0)

// FVR97 Configuration

#define	BSEC_FVR97_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR97_FV_0					(0x1u<<0)

// FVR98 Configuration

#define	BSEC_FVR98_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR98_FV_0					(0x1u<<0)

// FVR99 Configuration

#define	BSEC_FVR99_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR99_FV_0					(0x1u<<0)

// FVR100 Configuration

#define	BSEC_FVR100_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR100_FV_0				(0x1u<<0)

// FVR101 Configuration

#define	BSEC_FVR101_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR101_FV_0				(0x1u<<0)

// FVR102 Configuration

#define	BSEC_FVR102_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR102_FV_0				(0x1u<<0)

// FVR103 Configuration

#define	BSEC_FVR103_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR103_FV_0				(0x1u<<0)

// FVR104 Configuration

#define	BSEC_FVR104_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR104_FV_0				(0x1u<<0)

// FVR105 Configuration

#define	BSEC_FVR105_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR105_FV_0				(0x1u<<0)

// FVR106 Configuration

#define	BSEC_FVR106_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR106_FV_0				(0x1u<<0)

// FVR107 Configuration

#define	BSEC_FVR107_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR107_FV_0				(0x1u<<0)

// FVR108 Configuration

#define	BSEC_FVR108_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR108_FV_0				(0x1u<<0)

// FVR109 Configuration

#define	BSEC_FVR109_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR109_FV_0				(0x1u<<0)

// FVR110 Configuration

#define	BSEC_FVR110_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR110_FV_0				(0x1u<<0)

// FVR111 Configuration

#define	BSEC_FVR111_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR111_FV_0				(0x1u<<0)

// FVR112 Configuration

#define	BSEC_FVR112_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR112_FV_0				(0x1u<<0)

// FVR113 Configuration

#define	BSEC_FVR113_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR113_FV_0				(0x1u<<0)

// FVR114 Configuration

#define	BSEC_FVR114_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR114_FV_0				(0x1u<<0)

// FVR115 Configuration

#define	BSEC_FVR115_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR115_FV_0				(0x1u<<0)

// FVR116 Configuration

#define	BSEC_FVR116_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR116_FV_0				(0x1u<<0)

// FVR117 Configuration

#define	BSEC_FVR117_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR117_FV_0				(0x1u<<0)

// FVR118 Configuration

#define	BSEC_FVR118_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR118_FV_0				(0x1u<<0)

// FVR119 Configuration

#define	BSEC_FVR119_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR119_FV_0				(0x1u<<0)

// FVR120 Configuration

#define	BSEC_FVR120_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR120_FV_0				(0x1u<<0)

// FVR121 Configuration

#define	BSEC_FVR121_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR121_FV_0				(0x1u<<0)

// FVR122 Configuration

#define	BSEC_FVR122_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR122_FV_0				(0x1u<<0)

// FVR123 Configuration

#define	BSEC_FVR123_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR123_FV_0				(0x1u<<0)

// FVR124 Configuration

#define	BSEC_FVR124_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR124_FV_0				(0x1u<<0)

// FVR125 Configuration

#define	BSEC_FVR125_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR125_FV_0				(0x1u<<0)

// FVR126 Configuration

#define	BSEC_FVR126_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR126_FV_0				(0x1u<<0)

// FVR127 Configuration

#define	BSEC_FVR127_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR127_FV_0				(0x1u<<0)

// FVR128 Configuration

#define	BSEC_FVR128_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR128_FV_0				(0x1u<<0)

// FVR129 Configuration

#define	BSEC_FVR129_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR129_FV_0				(0x1u<<0)

// FVR130 Configuration

#define	BSEC_FVR130_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR130_FV_0				(0x1u<<0)

// FVR131 Configuration

#define	BSEC_FVR131_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR131_FV_0				(0x1u<<0)

// FVR132 Configuration

#define	BSEC_FVR132_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR132_FV_0				(0x1u<<0)

// FVR133 Configuration

#define	BSEC_FVR133_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR133_FV_0				(0x1u<<0)

// FVR134 Configuration

#define	BSEC_FVR134_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR134_FV_0				(0x1u<<0)

// FVR135 Configuration

#define	BSEC_FVR135_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR135_FV_0				(0x1u<<0)

// FVR136 Configuration

#define	BSEC_FVR136_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR136_FV_0				(0x1u<<0)

// FVR137 Configuration

#define	BSEC_FVR137_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR137_FV_0				(0x1u<<0)

// FVR138 Configuration

#define	BSEC_FVR138_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR138_FV_0				(0x1u<<0)

// FVR139 Configuration

#define	BSEC_FVR139_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR139_FV_0				(0x1u<<0)

// FVR140 Configuration

#define	BSEC_FVR140_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR140_FV_0				(0x1u<<0)

// FVR141 Configuration

#define	BSEC_FVR141_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR141_FV_0				(0x1u<<0)

// FVR142 Configuration

#define	BSEC_FVR142_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR142_FV_0				(0x1u<<0)

// FVR143 Configuration

#define	BSEC_FVR143_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR143_FV_0				(0x1u<<0)

// FVR144 Configuration

#define	BSEC_FVR144_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR144_FV_0				(0x1u<<0)

// FVR145 Configuration

#define	BSEC_FVR145_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR145_FV_0				(0x1u<<0)

// FVR146 Configuration

#define	BSEC_FVR146_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR146_FV_0				(0x1u<<0)

// FVR147 Configuration

#define	BSEC_FVR147_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR147_FV_0				(0x1u<<0)

// FVR148 Configuration

#define	BSEC_FVR148_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR148_FV_0				(0x1u<<0)

// FVR149 Configuration

#define	BSEC_FVR149_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR149_FV_0				(0x1u<<0)

// FVR150 Configuration

#define	BSEC_FVR150_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR150_FV_0				(0x1u<<0)

// FVR151 Configuration

#define	BSEC_FVR151_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR151_FV_0				(0x1u<<0)

// FVR152 Configuration

#define	BSEC_FVR152_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR152_FV_0				(0x1u<<0)

// FVR153 Configuration

#define	BSEC_FVR153_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR153_FV_0				(0x1u<<0)

// FVR154 Configuration

#define	BSEC_FVR154_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR154_FV_0				(0x1u<<0)

// FVR155 Configuration

#define	BSEC_FVR155_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR155_FV_0				(0x1u<<0)

// FVR156 Configuration

#define	BSEC_FVR156_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR156_FV_0				(0x1u<<0)

// FVR157 Configuration

#define	BSEC_FVR157_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR157_FV_0				(0x1u<<0)

// FVR158 Configuration

#define	BSEC_FVR158_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR158_FV_0				(0x1u<<0)

// FVR159 Configuration

#define	BSEC_FVR159_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR159_FV_0				(0x1u<<0)

// FVR160 Configuration

#define	BSEC_FVR160_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR160_FV_0				(0x1u<<0)

// FVR161 Configuration

#define	BSEC_FVR161_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR161_FV_0				(0x1u<<0)

// FVR162 Configuration

#define	BSEC_FVR162_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR162_FV_0				(0x1u<<0)

// FVR163 Configuration

#define	BSEC_FVR163_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR163_FV_0				(0x1u<<0)

// FVR164 Configuration

#define	BSEC_FVR164_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR164_FV_0				(0x1u<<0)

// FVR165 Configuration

#define	BSEC_FVR165_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR165_FV_0				(0x1u<<0)

// FVR166 Configuration

#define	BSEC_FVR166_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR166_FV_0				(0x1u<<0)

// FVR167 Configuration

#define	BSEC_FVR167_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR167_FV_0				(0x1u<<0)

// FVR168 Configuration

#define	BSEC_FVR168_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR168_FV_0				(0x1u<<0)

// FVR169 Configuration

#define	BSEC_FVR169_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR169_FV_0				(0x1u<<0)

// FVR170 Configuration

#define	BSEC_FVR170_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR170_FV_0				(0x1u<<0)

// FVR171 Configuration

#define	BSEC_FVR171_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR171_FV_0				(0x1u<<0)

// FVR172 Configuration

#define	BSEC_FVR172_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR172_FV_0				(0x1u<<0)

// FVR173 Configuration

#define	BSEC_FVR173_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR173_FV_0				(0x1u<<0)

// FVR174 Configuration

#define	BSEC_FVR174_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR174_FV_0				(0x1u<<0)

// FVR175 Configuration

#define	BSEC_FVR175_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR175_FV_0				(0x1u<<0)

// FVR176 Configuration

#define	BSEC_FVR176_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR176_FV_0				(0x1u<<0)

// FVR177 Configuration

#define	BSEC_FVR177_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR177_FV_0				(0x1u<<0)

// FVR178 Configuration

#define	BSEC_FVR178_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR178_FV_0				(0x1u<<0)

// FVR179 Configuration

#define	BSEC_FVR179_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR179_FV_0				(0x1u<<0)

// FVR180 Configuration

#define	BSEC_FVR180_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR180_FV_0				(0x1u<<0)

// FVR181 Configuration

#define	BSEC_FVR181_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR181_FV_0				(0x1u<<0)

// FVR182 Configuration

#define	BSEC_FVR182_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR182_FV_0				(0x1u<<0)

// FVR183 Configuration

#define	BSEC_FVR183_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR183_FV_0				(0x1u<<0)

// FVR184 Configuration

#define	BSEC_FVR184_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR184_FV_0				(0x1u<<0)

// FVR185 Configuration

#define	BSEC_FVR185_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR185_FV_0				(0x1u<<0)

// FVR186 Configuration

#define	BSEC_FVR186_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR186_FV_0				(0x1u<<0)

// FVR187 Configuration

#define	BSEC_FVR187_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR187_FV_0				(0x1u<<0)

// FVR188 Configuration

#define	BSEC_FVR188_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR188_FV_0				(0x1u<<0)

// FVR189 Configuration

#define	BSEC_FVR189_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR189_FV_0				(0x1u<<0)

// FVR190 Configuration

#define	BSEC_FVR190_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR190_FV_0				(0x1u<<0)

// FVR191 Configuration

#define	BSEC_FVR191_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR191_FV_0				(0x1u<<0)

// FVR192 Configuration

#define	BSEC_FVR192_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR192_FV_0				(0x1u<<0)

// FVR193 Configuration

#define	BSEC_FVR193_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR193_FV_0				(0x1u<<0)

// FVR194 Configuration

#define	BSEC_FVR194_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR194_FV_0				(0x1u<<0)

// FVR195 Configuration

#define	BSEC_FVR195_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR195_FV_0				(0x1u<<0)

// FVR196 Configuration

#define	BSEC_FVR196_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR196_FV_0				(0x1u<<0)

// FVR197 Configuration

#define	BSEC_FVR197_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR197_FV_0				(0x1u<<0)

// FVR198 Configuration

#define	BSEC_FVR198_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR198_FV_0				(0x1u<<0)

// FVR199 Configuration

#define	BSEC_FVR199_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR199_FV_0				(0x1u<<0)

// FVR200 Configuration

#define	BSEC_FVR200_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR200_FV_0				(0x1u<<0)

// FVR201 Configuration

#define	BSEC_FVR201_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR201_FV_0				(0x1u<<0)

// FVR202 Configuration

#define	BSEC_FVR202_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR202_FV_0				(0x1u<<0)

// FVR203 Configuration

#define	BSEC_FVR203_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR203_FV_0				(0x1u<<0)

// FVR204 Configuration

#define	BSEC_FVR204_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR204_FV_0				(0x1u<<0)

// FVR205 Configuration

#define	BSEC_FVR205_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR205_FV_0				(0x1u<<0)

// FVR206 Configuration

#define	BSEC_FVR206_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR206_FV_0				(0x1u<<0)

// FVR207 Configuration

#define	BSEC_FVR207_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR207_FV_0				(0x1u<<0)

// FVR208 Configuration

#define	BSEC_FVR208_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR208_FV_0				(0x1u<<0)

// FVR209 Configuration

#define	BSEC_FVR209_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR209_FV_0				(0x1u<<0)

// FVR210 Configuration

#define	BSEC_FVR210_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR210_FV_0				(0x1u<<0)

// FVR211 Configuration

#define	BSEC_FVR211_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR211_FV_0				(0x1u<<0)

// FVR212 Configuration

#define	BSEC_FVR212_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR212_FV_0				(0x1u<<0)

// FVR213 Configuration

#define	BSEC_FVR213_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR213_FV_0				(0x1u<<0)

// FVR214 Configuration

#define	BSEC_FVR214_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR214_FV_0				(0x1u<<0)

// FVR215 Configuration

#define	BSEC_FVR215_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR215_FV_0				(0x1u<<0)

// FVR216 Configuration

#define	BSEC_FVR216_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR216_FV_0				(0x1u<<0)

// FVR217 Configuration

#define	BSEC_FVR217_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR217_FV_0				(0x1u<<0)

// FVR218 Configuration

#define	BSEC_FVR218_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR218_FV_0				(0x1u<<0)

// FVR219 Configuration

#define	BSEC_FVR219_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR219_FV_0				(0x1u<<0)

// FVR220 Configuration

#define	BSEC_FVR220_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR220_FV_0				(0x1u<<0)

// FVR221 Configuration

#define	BSEC_FVR221_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR221_FV_0				(0x1u<<0)

// FVR222 Configuration

#define	BSEC_FVR222_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR222_FV_0				(0x1u<<0)

// FVR223 Configuration

#define	BSEC_FVR223_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR223_FV_0				(0x1u<<0)

// FVR224 Configuration

#define	BSEC_FVR224_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR224_FV_0				(0x1u<<0)

// FVR225 Configuration

#define	BSEC_FVR225_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR225_FV_0				(0x1u<<0)

// FVR226 Configuration

#define	BSEC_FVR226_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR226_FV_0				(0x1u<<0)

// FVR227 Configuration

#define	BSEC_FVR227_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR227_FV_0				(0x1u<<0)

// FVR228 Configuration

#define	BSEC_FVR228_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR228_FV_0				(0x1u<<0)

// FVR229 Configuration

#define	BSEC_FVR229_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR229_FV_0				(0x1u<<0)

// FVR230 Configuration

#define	BSEC_FVR230_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR230_FV_0				(0x1u<<0)

// FVR231 Configuration

#define	BSEC_FVR231_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR231_FV_0				(0x1u<<0)

// FVR232 Configuration

#define	BSEC_FVR232_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR232_FV_0				(0x1u<<0)

// FVR233 Configuration

#define	BSEC_FVR233_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR233_FV_0				(0x1u<<0)

// FVR234 Configuration

#define	BSEC_FVR234_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR234_FV_0				(0x1u<<0)

// FVR235 Configuration

#define	BSEC_FVR235_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR235_FV_0				(0x1u<<0)

// FVR236 Configuration

#define	BSEC_FVR236_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR236_FV_0				(0x1u<<0)

// FVR237 Configuration

#define	BSEC_FVR237_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR237_FV_0				(0x1u<<0)

// FVR238 Configuration

#define	BSEC_FVR238_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR238_FV_0				(0x1u<<0)

// FVR239 Configuration

#define	BSEC_FVR239_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR239_FV_0				(0x1u<<0)

// FVR240 Configuration

#define	BSEC_FVR240_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR240_FV_0				(0x1u<<0)

// FVR241 Configuration

#define	BSEC_FVR241_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR241_FV_0				(0x1u<<0)

// FVR242 Configuration

#define	BSEC_FVR242_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR242_FV_0				(0x1u<<0)

// FVR243 Configuration

#define	BSEC_FVR243_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR243_FV_0				(0x1u<<0)

// FVR244 Configuration

#define	BSEC_FVR244_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR244_FV_0				(0x1u<<0)

// FVR245 Configuration

#define	BSEC_FVR245_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR245_FV_0				(0x1u<<0)

// FVR246 Configuration

#define	BSEC_FVR246_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR246_FV_0				(0x1u<<0)

// FVR247 Configuration

#define	BSEC_FVR247_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR247_FV_0				(0x1u<<0)

// FVR248 Configuration

#define	BSEC_FVR248_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR248_FV_0				(0x1u<<0)

// FVR249 Configuration

#define	BSEC_FVR249_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR249_FV_0				(0x1u<<0)

// FVR250 Configuration

#define	BSEC_FVR250_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR250_FV_0				(0x1u<<0)

// FVR251 Configuration

#define	BSEC_FVR251_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR251_FV_0				(0x1u<<0)

// FVR252 Configuration

#define	BSEC_FVR252_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR252_FV_0				(0x1u<<0)

// FVR253 Configuration

#define	BSEC_FVR253_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR253_FV_0				(0x1u<<0)

// FVR254 Configuration

#define	BSEC_FVR254_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR254_FV_0				(0x1u<<0)

// FVR255 Configuration

#define	BSEC_FVR255_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR255_FV_0				(0x1u<<0)

// FVR256 Configuration

#define	BSEC_FVR256_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR256_FV_0				(0x1u<<0)

// FVR257 Configuration

#define	BSEC_FVR257_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR257_FV_0				(0x1u<<0)

// FVR258 Configuration

#define	BSEC_FVR258_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR258_FV_0				(0x1u<<0)

// FVR259 Configuration

#define	BSEC_FVR259_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR259_FV_0				(0x1u<<0)

// FVR260 Configuration

#define	BSEC_FVR260_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR260_FV_0				(0x1u<<0)

// FVR261 Configuration

#define	BSEC_FVR261_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR261_FV_0				(0x1u<<0)

// FVR262 Configuration

#define	BSEC_FVR262_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR262_FV_0				(0x1u<<0)

// FVR263 Configuration

#define	BSEC_FVR263_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR263_FV_0				(0x1u<<0)

// FVR264 Configuration

#define	BSEC_FVR264_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR264_FV_0				(0x1u<<0)

// FVR265 Configuration

#define	BSEC_FVR265_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR265_FV_0				(0x1u<<0)

// FVR266 Configuration

#define	BSEC_FVR266_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR266_FV_0				(0x1u<<0)

// FVR267 Configuration

#define	BSEC_FVR267_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR267_FV_0				(0x1u<<0)

// FVR268 Configuration

#define	BSEC_FVR268_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR268_FV_0				(0x1u<<0)

// FVR269 Configuration

#define	BSEC_FVR269_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR269_FV_0				(0x1u<<0)

// FVR270 Configuration

#define	BSEC_FVR270_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR270_FV_0				(0x1u<<0)

// FVR271 Configuration

#define	BSEC_FVR271_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR271_FV_0				(0x1u<<0)

// FVR272 Configuration

#define	BSEC_FVR272_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR272_FV_0				(0x1u<<0)

// FVR273 Configuration

#define	BSEC_FVR273_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR273_FV_0				(0x1u<<0)

// FVR274 Configuration

#define	BSEC_FVR274_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR274_FV_0				(0x1u<<0)

// FVR275 Configuration

#define	BSEC_FVR275_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR275_FV_0				(0x1u<<0)

// FVR276 Configuration

#define	BSEC_FVR276_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR276_FV_0				(0x1u<<0)

// FVR277 Configuration

#define	BSEC_FVR277_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR277_FV_0				(0x1u<<0)

// FVR278 Configuration

#define	BSEC_FVR278_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR278_FV_0				(0x1u<<0)

// FVR279 Configuration

#define	BSEC_FVR279_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR279_FV_0				(0x1u<<0)

// FVR280 Configuration

#define	BSEC_FVR280_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR280_FV_0				(0x1u<<0)

// FVR281 Configuration

#define	BSEC_FVR281_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR281_FV_0				(0x1u<<0)

// FVR282 Configuration

#define	BSEC_FVR282_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR282_FV_0				(0x1u<<0)

// FVR283 Configuration

#define	BSEC_FVR283_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR283_FV_0				(0x1u<<0)

// FVR284 Configuration

#define	BSEC_FVR284_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR284_FV_0				(0x1u<<0)

// FVR285 Configuration

#define	BSEC_FVR285_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR285_FV_0				(0x1u<<0)

// FVR286 Configuration

#define	BSEC_FVR286_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR286_FV_0				(0x1u<<0)

// FVR287 Configuration

#define	BSEC_FVR287_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR287_FV_0				(0x1u<<0)

// FVR288 Configuration

#define	BSEC_FVR288_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR288_FV_0				(0x1u<<0)

// FVR289 Configuration

#define	BSEC_FVR289_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR289_FV_0				(0x1u<<0)

// FVR290 Configuration

#define	BSEC_FVR290_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR290_FV_0				(0x1u<<0)

// FVR291 Configuration

#define	BSEC_FVR291_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR291_FV_0				(0x1u<<0)

// FVR292 Configuration

#define	BSEC_FVR292_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR292_FV_0				(0x1u<<0)

// FVR293 Configuration

#define	BSEC_FVR293_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR293_FV_0				(0x1u<<0)

// FVR294 Configuration

#define	BSEC_FVR294_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR294_FV_0				(0x1u<<0)

// FVR295 Configuration

#define	BSEC_FVR295_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR295_FV_0				(0x1u<<0)

// FVR296 Configuration

#define	BSEC_FVR296_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR296_FV_0				(0x1u<<0)

// FVR297 Configuration

#define	BSEC_FVR297_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR297_FV_0				(0x1u<<0)

// FVR298 Configuration

#define	BSEC_FVR298_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR298_FV_0				(0x1u<<0)

// FVR299 Configuration

#define	BSEC_FVR299_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR299_FV_0				(0x1u<<0)

// FVR300 Configuration

#define	BSEC_FVR300_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR300_FV_0				(0x1u<<0)

// FVR301 Configuration

#define	BSEC_FVR301_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR301_FV_0				(0x1u<<0)

// FVR302 Configuration

#define	BSEC_FVR302_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR302_FV_0				(0x1u<<0)

// FVR303 Configuration

#define	BSEC_FVR303_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR303_FV_0				(0x1u<<0)

// FVR304 Configuration

#define	BSEC_FVR304_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR304_FV_0				(0x1u<<0)

// FVR305 Configuration

#define	BSEC_FVR305_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR305_FV_0				(0x1u<<0)

// FVR306 Configuration

#define	BSEC_FVR306_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR306_FV_0				(0x1u<<0)

// FVR307 Configuration

#define	BSEC_FVR307_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR307_FV_0				(0x1u<<0)

// FVR308 Configuration

#define	BSEC_FVR308_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR308_FV_0				(0x1u<<0)

// FVR309 Configuration

#define	BSEC_FVR309_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR309_FV_0				(0x1u<<0)

// FVR310 Configuration

#define	BSEC_FVR310_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR310_FV_0				(0x1u<<0)

// FVR311 Configuration

#define	BSEC_FVR311_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR311_FV_0				(0x1u<<0)

// FVR312 Configuration

#define	BSEC_FVR312_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR312_FV_0				(0x1u<<0)

// FVR313 Configuration

#define	BSEC_FVR313_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR313_FV_0				(0x1u<<0)

// FVR314 Configuration

#define	BSEC_FVR314_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR314_FV_0				(0x1u<<0)

// FVR315 Configuration

#define	BSEC_FVR315_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR315_FV_0				(0x1u<<0)

// FVR316 Configuration

#define	BSEC_FVR316_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR316_FV_0				(0x1u<<0)

// FVR317 Configuration

#define	BSEC_FVR317_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR317_FV_0				(0x1u<<0)

// FVR318 Configuration

#define	BSEC_FVR318_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR318_FV_0				(0x1u<<0)

// FVR319 Configuration

#define	BSEC_FVR319_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR319_FV_0				(0x1u<<0)

// FVR320 Configuration

#define	BSEC_FVR320_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR320_FV_0				(0x1u<<0)

// FVR321 Configuration

#define	BSEC_FVR321_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR321_FV_0				(0x1u<<0)

// FVR322 Configuration

#define	BSEC_FVR322_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR322_FV_0				(0x1u<<0)

// FVR323 Configuration

#define	BSEC_FVR323_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR323_FV_0				(0x1u<<0)

// FVR324 Configuration

#define	BSEC_FVR324_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR324_FV_0				(0x1u<<0)

// FVR325 Configuration

#define	BSEC_FVR325_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR325_FV_0				(0x1u<<0)

// FVR326 Configuration

#define	BSEC_FVR326_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR326_FV_0				(0x1u<<0)

// FVR327 Configuration

#define	BSEC_FVR327_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR327_FV_0				(0x1u<<0)

// FVR328 Configuration

#define	BSEC_FVR328_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR328_FV_0				(0x1u<<0)

// FVR329 Configuration

#define	BSEC_FVR329_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR329_FV_0				(0x1u<<0)

// FVR330 Configuration

#define	BSEC_FVR330_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR330_FV_0				(0x1u<<0)

// FVR331 Configuration

#define	BSEC_FVR331_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR331_FV_0				(0x1u<<0)

// FVR332 Configuration

#define	BSEC_FVR332_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR332_FV_0				(0x1u<<0)

// FVR333 Configuration

#define	BSEC_FVR333_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR333_FV_0				(0x1u<<0)

// FVR334 Configuration

#define	BSEC_FVR334_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR334_FV_0				(0x1u<<0)

// FVR335 Configuration

#define	BSEC_FVR335_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR335_FV_0				(0x1u<<0)

// FVR336 Configuration

#define	BSEC_FVR336_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR336_FV_0				(0x1u<<0)

// FVR337 Configuration

#define	BSEC_FVR337_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR337_FV_0				(0x1u<<0)

// FVR338 Configuration

#define	BSEC_FVR338_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR338_FV_0				(0x1u<<0)

// FVR339 Configuration

#define	BSEC_FVR339_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR339_FV_0				(0x1u<<0)

// FVR340 Configuration

#define	BSEC_FVR340_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR340_FV_0				(0x1u<<0)

// FVR341 Configuration

#define	BSEC_FVR341_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR341_FV_0				(0x1u<<0)

// FVR342 Configuration

#define	BSEC_FVR342_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR342_FV_0				(0x1u<<0)

// FVR343 Configuration

#define	BSEC_FVR343_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR343_FV_0				(0x1u<<0)

// FVR344 Configuration

#define	BSEC_FVR344_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR344_FV_0				(0x1u<<0)

// FVR345 Configuration

#define	BSEC_FVR345_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR345_FV_0				(0x1u<<0)

// FVR346 Configuration

#define	BSEC_FVR346_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR346_FV_0				(0x1u<<0)

// FVR347 Configuration

#define	BSEC_FVR347_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR347_FV_0				(0x1u<<0)

// FVR348 Configuration

#define	BSEC_FVR348_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR348_FV_0				(0x1u<<0)

// FVR349 Configuration

#define	BSEC_FVR349_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR349_FV_0				(0x1u<<0)

// FVR350 Configuration

#define	BSEC_FVR350_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR350_FV_0				(0x1u<<0)

// FVR351 Configuration

#define	BSEC_FVR351_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR351_FV_0				(0x1u<<0)

// FVR352 Configuration

#define	BSEC_FVR352_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR352_FV_0				(0x1u<<0)

// FVR353 Configuration

#define	BSEC_FVR353_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR353_FV_0				(0x1u<<0)

// FVR354 Configuration

#define	BSEC_FVR354_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR354_FV_0				(0x1u<<0)

// FVR355 Configuration

#define	BSEC_FVR355_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR355_FV_0				(0x1u<<0)

// FVR356 Configuration

#define	BSEC_FVR356_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR356_FV_0				(0x1u<<0)

// FVR357 Configuration

#define	BSEC_FVR357_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR357_FV_0				(0x1u<<0)

// FVR358 Configuration

#define	BSEC_FVR358_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR358_FV_0				(0x1u<<0)

// FVR359 Configuration

#define	BSEC_FVR359_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR359_FV_0				(0x1u<<0)

// FVR360 Configuration

#define	BSEC_FVR360_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR360_FV_0				(0x1u<<0)

// FVR361 Configuration

#define	BSEC_FVR361_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR361_FV_0				(0x1u<<0)

// FVR362 Configuration

#define	BSEC_FVR362_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR362_FV_0				(0x1u<<0)

// FVR363 Configuration

#define	BSEC_FVR363_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR363_FV_0				(0x1u<<0)

// FVR364 Configuration

#define	BSEC_FVR364_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR364_FV_0				(0x1u<<0)

// FVR365 Configuration

#define	BSEC_FVR365_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR365_FV_0				(0x1u<<0)

// FVR366 Configuration

#define	BSEC_FVR366_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR366_FV_0				(0x1u<<0)

// FVR367 Configuration

#define	BSEC_FVR367_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR367_FV_0				(0x1u<<0)

// FVR368 Configuration

#define	BSEC_FVR368_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR368_FV_0				(0x1u<<0)

// FVR369 Configuration

#define	BSEC_FVR369_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR369_FV_0				(0x1u<<0)

// FVR370 Configuration

#define	BSEC_FVR370_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR370_FV_0				(0x1u<<0)

// FVR371 Configuration

#define	BSEC_FVR371_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR371_FV_0				(0x1u<<0)

// FVR372 Configuration

#define	BSEC_FVR372_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR372_FV_0				(0x1u<<0)

// FVR373 Configuration

#define	BSEC_FVR373_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR373_FV_0				(0x1u<<0)

// FVR374 Configuration

#define	BSEC_FVR374_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR374_FV_0				(0x1u<<0)

// FVR375 Configuration

#define	BSEC_FVR375_FV					(0xFFFFFFFFu<<0)
#define	BSEC_FVR375_FV_0				(0x1u<<0)

// SPLOCK0 Configuration

#define	BSEC_SPLOCK0_SPLOCK31			(0x1u<<31)
#define	BSEC_SPLOCK0_SPLOCK30			(0x1u<<30)
#define	BSEC_SPLOCK0_SPLOCK29			(0x1u<<29)
#define	BSEC_SPLOCK0_SPLOCK28			(0x1u<<28)
#define	BSEC_SPLOCK0_SPLOCK27			(0x1u<<27)
#define	BSEC_SPLOCK0_SPLOCK26			(0x1u<<26)
#define	BSEC_SPLOCK0_SPLOCK25			(0x1u<<25)
#define	BSEC_SPLOCK0_SPLOCK24			(0x1u<<24)
#define	BSEC_SPLOCK0_SPLOCK23			(0x1u<<23)
#define	BSEC_SPLOCK0_SPLOCK22			(0x1u<<22)
#define	BSEC_SPLOCK0_SPLOCK21			(0x1u<<21)
#define	BSEC_SPLOCK0_SPLOCK20			(0x1u<<20)
#define	BSEC_SPLOCK0_SPLOCK19			(0x1u<<19)
#define	BSEC_SPLOCK0_SPLOCK18			(0x1u<<18)
#define	BSEC_SPLOCK0_SPLOCK17			(0x1u<<17)
#define	BSEC_SPLOCK0_SPLOCK16			(0x1u<<16)
#define	BSEC_SPLOCK0_SPLOCK15			(0x1u<<15)
#define	BSEC_SPLOCK0_SPLOCK14			(0x1u<<14)
#define	BSEC_SPLOCK0_SPLOCK13			(0x1u<<13)
#define	BSEC_SPLOCK0_SPLOCK12			(0x1u<<12)
#define	BSEC_SPLOCK0_SPLOCK11			(0x1u<<11)
#define	BSEC_SPLOCK0_SPLOCK10			(0x1u<<10)
#define	BSEC_SPLOCK0_SPLOCK9			(0x1u<<9)
#define	BSEC_SPLOCK0_SPLOCK8			(0x1u<<8)
#define	BSEC_SPLOCK0_SPLOCK7			(0x1u<<7)
#define	BSEC_SPLOCK0_SPLOCK6			(0x1u<<6)
#define	BSEC_SPLOCK0_SPLOCK5			(0x1u<<5)
#define	BSEC_SPLOCK0_SPLOCK4			(0x1u<<4)
#define	BSEC_SPLOCK0_SPLOCK3			(0x1u<<3)
#define	BSEC_SPLOCK0_SPLOCK2			(0x1u<<2)
#define	BSEC_SPLOCK0_SPLOCK1			(0x1u<<1)
#define	BSEC_SPLOCK0_SPLOCK0			(0x1u<<0)

#define	BSEC_SPLOCK0_SPLOCK31_B_0X0		(0x0u<<31)
#define	BSEC_SPLOCK0_SPLOCK31_B_0X1		(0x1u<<31)
#define	BSEC_SPLOCK0_SPLOCK30_B_0X0		(0x0u<<30)
#define	BSEC_SPLOCK0_SPLOCK30_B_0X1		(0x1u<<30)
#define	BSEC_SPLOCK0_SPLOCK29_B_0X0		(0x0u<<29)
#define	BSEC_SPLOCK0_SPLOCK29_B_0X1		(0x1u<<29)
#define	BSEC_SPLOCK0_SPLOCK28_B_0X0		(0x0u<<28)
#define	BSEC_SPLOCK0_SPLOCK28_B_0X1		(0x1u<<28)
#define	BSEC_SPLOCK0_SPLOCK27_B_0X0		(0x0u<<27)
#define	BSEC_SPLOCK0_SPLOCK27_B_0X1		(0x1u<<27)
#define	BSEC_SPLOCK0_SPLOCK26_B_0X0		(0x0u<<26)
#define	BSEC_SPLOCK0_SPLOCK26_B_0X1		(0x1u<<26)
#define	BSEC_SPLOCK0_SPLOCK25_B_0X0		(0x0u<<25)
#define	BSEC_SPLOCK0_SPLOCK25_B_0X1		(0x1u<<25)
#define	BSEC_SPLOCK0_SPLOCK24_B_0X0		(0x0u<<24)
#define	BSEC_SPLOCK0_SPLOCK24_B_0X1		(0x1u<<24)
#define	BSEC_SPLOCK0_SPLOCK23_B_0X0		(0x0u<<23)
#define	BSEC_SPLOCK0_SPLOCK23_B_0X1		(0x1u<<23)
#define	BSEC_SPLOCK0_SPLOCK22_B_0X0		(0x0u<<22)
#define	BSEC_SPLOCK0_SPLOCK22_B_0X1		(0x1u<<22)
#define	BSEC_SPLOCK0_SPLOCK21_B_0X0		(0x0u<<21)
#define	BSEC_SPLOCK0_SPLOCK21_B_0X1		(0x1u<<21)
#define	BSEC_SPLOCK0_SPLOCK20_B_0X0		(0x0u<<20)
#define	BSEC_SPLOCK0_SPLOCK20_B_0X1		(0x1u<<20)
#define	BSEC_SPLOCK0_SPLOCK19_B_0X0		(0x0u<<19)
#define	BSEC_SPLOCK0_SPLOCK19_B_0X1		(0x1u<<19)
#define	BSEC_SPLOCK0_SPLOCK18_B_0X0		(0x0u<<18)
#define	BSEC_SPLOCK0_SPLOCK18_B_0X1		(0x1u<<18)
#define	BSEC_SPLOCK0_SPLOCK17_B_0X0		(0x0u<<17)
#define	BSEC_SPLOCK0_SPLOCK17_B_0X1		(0x1u<<17)
#define	BSEC_SPLOCK0_SPLOCK16_B_0X0		(0x0u<<16)
#define	BSEC_SPLOCK0_SPLOCK16_B_0X1		(0x1u<<16)
#define	BSEC_SPLOCK0_SPLOCK15_B_0X0		(0x0u<<15)
#define	BSEC_SPLOCK0_SPLOCK15_B_0X1		(0x1u<<15)
#define	BSEC_SPLOCK0_SPLOCK14_B_0X0		(0x0u<<14)
#define	BSEC_SPLOCK0_SPLOCK14_B_0X1		(0x1u<<14)
#define	BSEC_SPLOCK0_SPLOCK13_B_0X0		(0x0u<<13)
#define	BSEC_SPLOCK0_SPLOCK13_B_0X1		(0x1u<<13)
#define	BSEC_SPLOCK0_SPLOCK12_B_0X0		(0x0u<<12)
#define	BSEC_SPLOCK0_SPLOCK12_B_0X1		(0x1u<<12)
#define	BSEC_SPLOCK0_SPLOCK11_B_0X0		(0x0u<<11)
#define	BSEC_SPLOCK0_SPLOCK11_B_0X1		(0x1u<<11)
#define	BSEC_SPLOCK0_SPLOCK10_B_0X0		(0x0u<<10)
#define	BSEC_SPLOCK0_SPLOCK10_B_0X1		(0x1u<<10)
#define	BSEC_SPLOCK0_SPLOCK9_B_0X0		(0x0u<<9)
#define	BSEC_SPLOCK0_SPLOCK9_B_0X1		(0x1u<<9)
#define	BSEC_SPLOCK0_SPLOCK8_B_0X0		(0x0u<<8)
#define	BSEC_SPLOCK0_SPLOCK8_B_0X1		(0x1u<<8)
#define	BSEC_SPLOCK0_SPLOCK7_B_0X0		(0x0u<<7)
#define	BSEC_SPLOCK0_SPLOCK7_B_0X1		(0x1u<<7)
#define	BSEC_SPLOCK0_SPLOCK6_B_0X0		(0x0u<<6)
#define	BSEC_SPLOCK0_SPLOCK6_B_0X1		(0x1u<<6)
#define	BSEC_SPLOCK0_SPLOCK5_B_0X0		(0x0u<<5)
#define	BSEC_SPLOCK0_SPLOCK5_B_0X1		(0x1u<<5)
#define	BSEC_SPLOCK0_SPLOCK4_B_0X0		(0x0u<<4)
#define	BSEC_SPLOCK0_SPLOCK4_B_0X1		(0x1u<<4)
#define	BSEC_SPLOCK0_SPLOCK3_B_0X0		(0x0u<<3)
#define	BSEC_SPLOCK0_SPLOCK3_B_0X1		(0x1u<<3)
#define	BSEC_SPLOCK0_SPLOCK2_B_0X0		(0x0u<<2)
#define	BSEC_SPLOCK0_SPLOCK2_B_0X1		(0x1u<<2)
#define	BSEC_SPLOCK0_SPLOCK1_B_0X0		(0x0u<<1)
#define	BSEC_SPLOCK0_SPLOCK1_B_0X1		(0x1u<<1)
#define	BSEC_SPLOCK0_SPLOCK0_B_0X0		(0x0u<<0)
#define	BSEC_SPLOCK0_SPLOCK0_B_0X1		(0x1u<<0)

// SPLOCK1 Configuration

#define	BSEC_SPLOCK1_SPLOCK63			(0x1u<<31)
#define	BSEC_SPLOCK1_SPLOCK62			(0x1u<<30)
#define	BSEC_SPLOCK1_SPLOCK61			(0x1u<<29)
#define	BSEC_SPLOCK1_SPLOCK60			(0x1u<<28)
#define	BSEC_SPLOCK1_SPLOCK59			(0x1u<<27)
#define	BSEC_SPLOCK1_SPLOCK58			(0x1u<<26)
#define	BSEC_SPLOCK1_SPLOCK57			(0x1u<<25)
#define	BSEC_SPLOCK1_SPLOCK56			(0x1u<<24)
#define	BSEC_SPLOCK1_SPLOCK55			(0x1u<<23)
#define	BSEC_SPLOCK1_SPLOCK54			(0x1u<<22)
#define	BSEC_SPLOCK1_SPLOCK53			(0x1u<<21)
#define	BSEC_SPLOCK1_SPLOCK52			(0x1u<<20)
#define	BSEC_SPLOCK1_SPLOCK51			(0x1u<<19)
#define	BSEC_SPLOCK1_SPLOCK50			(0x1u<<18)
#define	BSEC_SPLOCK1_SPLOCK49			(0x1u<<17)
#define	BSEC_SPLOCK1_SPLOCK48			(0x1u<<16)
#define	BSEC_SPLOCK1_SPLOCK47			(0x1u<<15)
#define	BSEC_SPLOCK1_SPLOCK46			(0x1u<<14)
#define	BSEC_SPLOCK1_SPLOCK45			(0x1u<<13)
#define	BSEC_SPLOCK1_SPLOCK44			(0x1u<<12)
#define	BSEC_SPLOCK1_SPLOCK43			(0x1u<<11)
#define	BSEC_SPLOCK1_SPLOCK42			(0x1u<<10)
#define	BSEC_SPLOCK1_SPLOCK41			(0x1u<<9)
#define	BSEC_SPLOCK1_SPLOCK40			(0x1u<<8)
#define	BSEC_SPLOCK1_SPLOCK39			(0x1u<<7)
#define	BSEC_SPLOCK1_SPLOCK38			(0x1u<<6)
#define	BSEC_SPLOCK1_SPLOCK37			(0x1u<<5)
#define	BSEC_SPLOCK1_SPLOCK36			(0x1u<<4)
#define	BSEC_SPLOCK1_SPLOCK35			(0x1u<<3)
#define	BSEC_SPLOCK1_SPLOCK34			(0x1u<<2)
#define	BSEC_SPLOCK1_SPLOCK33			(0x1u<<1)
#define	BSEC_SPLOCK1_SPLOCK32			(0x1u<<0)

#define	BSEC_SPLOCK1_SPLOCK63_B_0X0		(0x0u<<31)
#define	BSEC_SPLOCK1_SPLOCK63_B_0X1		(0x1u<<31)
#define	BSEC_SPLOCK1_SPLOCK62_B_0X0		(0x0u<<30)
#define	BSEC_SPLOCK1_SPLOCK62_B_0X1		(0x1u<<30)
#define	BSEC_SPLOCK1_SPLOCK61_B_0X0		(0x0u<<29)
#define	BSEC_SPLOCK1_SPLOCK61_B_0X1		(0x1u<<29)
#define	BSEC_SPLOCK1_SPLOCK60_B_0X0		(0x0u<<28)
#define	BSEC_SPLOCK1_SPLOCK60_B_0X1		(0x1u<<28)
#define	BSEC_SPLOCK1_SPLOCK59_B_0X0		(0x0u<<27)
#define	BSEC_SPLOCK1_SPLOCK59_B_0X1		(0x1u<<27)
#define	BSEC_SPLOCK1_SPLOCK58_B_0X0		(0x0u<<26)
#define	BSEC_SPLOCK1_SPLOCK58_B_0X1		(0x1u<<26)
#define	BSEC_SPLOCK1_SPLOCK57_B_0X0		(0x0u<<25)
#define	BSEC_SPLOCK1_SPLOCK57_B_0X1		(0x1u<<25)
#define	BSEC_SPLOCK1_SPLOCK56_B_0X0		(0x0u<<24)
#define	BSEC_SPLOCK1_SPLOCK56_B_0X1		(0x1u<<24)
#define	BSEC_SPLOCK1_SPLOCK55_B_0X0		(0x0u<<23)
#define	BSEC_SPLOCK1_SPLOCK55_B_0X1		(0x1u<<23)
#define	BSEC_SPLOCK1_SPLOCK54_B_0X0		(0x0u<<22)
#define	BSEC_SPLOCK1_SPLOCK54_B_0X1		(0x1u<<22)
#define	BSEC_SPLOCK1_SPLOCK53_B_0X0		(0x0u<<21)
#define	BSEC_SPLOCK1_SPLOCK53_B_0X1		(0x1u<<21)
#define	BSEC_SPLOCK1_SPLOCK52_B_0X0		(0x0u<<20)
#define	BSEC_SPLOCK1_SPLOCK52_B_0X1		(0x1u<<20)
#define	BSEC_SPLOCK1_SPLOCK51_B_0X0		(0x0u<<19)
#define	BSEC_SPLOCK1_SPLOCK51_B_0X1		(0x1u<<19)
#define	BSEC_SPLOCK1_SPLOCK50_B_0X0		(0x0u<<18)
#define	BSEC_SPLOCK1_SPLOCK50_B_0X1		(0x1u<<18)
#define	BSEC_SPLOCK1_SPLOCK49_B_0X0		(0x0u<<17)
#define	BSEC_SPLOCK1_SPLOCK49_B_0X1		(0x1u<<17)
#define	BSEC_SPLOCK1_SPLOCK48_B_0X0		(0x0u<<16)
#define	BSEC_SPLOCK1_SPLOCK48_B_0X1		(0x1u<<16)
#define	BSEC_SPLOCK1_SPLOCK47_B_0X0		(0x0u<<15)
#define	BSEC_SPLOCK1_SPLOCK47_B_0X1		(0x1u<<15)
#define	BSEC_SPLOCK1_SPLOCK46_B_0X0		(0x0u<<14)
#define	BSEC_SPLOCK1_SPLOCK46_B_0X1		(0x1u<<14)
#define	BSEC_SPLOCK1_SPLOCK45_B_0X0		(0x0u<<13)
#define	BSEC_SPLOCK1_SPLOCK45_B_0X1		(0x1u<<13)
#define	BSEC_SPLOCK1_SPLOCK44_B_0X0		(0x0u<<12)
#define	BSEC_SPLOCK1_SPLOCK44_B_0X1		(0x1u<<12)
#define	BSEC_SPLOCK1_SPLOCK43_B_0X0		(0x0u<<11)
#define	BSEC_SPLOCK1_SPLOCK43_B_0X1		(0x1u<<11)
#define	BSEC_SPLOCK1_SPLOCK42_B_0X0		(0x0u<<10)
#define	BSEC_SPLOCK1_SPLOCK42_B_0X1		(0x1u<<10)
#define	BSEC_SPLOCK1_SPLOCK41_B_0X0		(0x0u<<9)
#define	BSEC_SPLOCK1_SPLOCK41_B_0X1		(0x1u<<9)
#define	BSEC_SPLOCK1_SPLOCK40_B_0X0		(0x0u<<8)
#define	BSEC_SPLOCK1_SPLOCK40_B_0X1		(0x1u<<8)
#define	BSEC_SPLOCK1_SPLOCK39_B_0X0		(0x0u<<7)
#define	BSEC_SPLOCK1_SPLOCK39_B_0X1		(0x1u<<7)
#define	BSEC_SPLOCK1_SPLOCK38_B_0X0		(0x0u<<6)
#define	BSEC_SPLOCK1_SPLOCK38_B_0X1		(0x1u<<6)
#define	BSEC_SPLOCK1_SPLOCK37_B_0X0		(0x0u<<5)
#define	BSEC_SPLOCK1_SPLOCK37_B_0X1		(0x1u<<5)
#define	BSEC_SPLOCK1_SPLOCK36_B_0X0		(0x0u<<4)
#define	BSEC_SPLOCK1_SPLOCK36_B_0X1		(0x1u<<4)
#define	BSEC_SPLOCK1_SPLOCK35_B_0X0		(0x0u<<3)
#define	BSEC_SPLOCK1_SPLOCK35_B_0X1		(0x1u<<3)
#define	BSEC_SPLOCK1_SPLOCK34_B_0X0		(0x0u<<2)
#define	BSEC_SPLOCK1_SPLOCK34_B_0X1		(0x1u<<2)
#define	BSEC_SPLOCK1_SPLOCK33_B_0X0		(0x0u<<1)
#define	BSEC_SPLOCK1_SPLOCK33_B_0X1		(0x1u<<1)
#define	BSEC_SPLOCK1_SPLOCK32_B_0X0		(0x0u<<0)
#define	BSEC_SPLOCK1_SPLOCK32_B_0X1		(0x1u<<0)

// SPLOCK2 Configuration

#define	BSEC_SPLOCK2_SPLOCK95			(0x1u<<31)
#define	BSEC_SPLOCK2_SPLOCK94			(0x1u<<30)
#define	BSEC_SPLOCK2_SPLOCK93			(0x1u<<29)
#define	BSEC_SPLOCK2_SPLOCK92			(0x1u<<28)
#define	BSEC_SPLOCK2_SPLOCK91			(0x1u<<27)
#define	BSEC_SPLOCK2_SPLOCK90			(0x1u<<26)
#define	BSEC_SPLOCK2_SPLOCK89			(0x1u<<25)
#define	BSEC_SPLOCK2_SPLOCK88			(0x1u<<24)
#define	BSEC_SPLOCK2_SPLOCK87			(0x1u<<23)
#define	BSEC_SPLOCK2_SPLOCK86			(0x1u<<22)
#define	BSEC_SPLOCK2_SPLOCK85			(0x1u<<21)
#define	BSEC_SPLOCK2_SPLOCK84			(0x1u<<20)
#define	BSEC_SPLOCK2_SPLOCK83			(0x1u<<19)
#define	BSEC_SPLOCK2_SPLOCK82			(0x1u<<18)
#define	BSEC_SPLOCK2_SPLOCK81			(0x1u<<17)
#define	BSEC_SPLOCK2_SPLOCK80			(0x1u<<16)
#define	BSEC_SPLOCK2_SPLOCK79			(0x1u<<15)
#define	BSEC_SPLOCK2_SPLOCK78			(0x1u<<14)
#define	BSEC_SPLOCK2_SPLOCK77			(0x1u<<13)
#define	BSEC_SPLOCK2_SPLOCK76			(0x1u<<12)
#define	BSEC_SPLOCK2_SPLOCK75			(0x1u<<11)
#define	BSEC_SPLOCK2_SPLOCK74			(0x1u<<10)
#define	BSEC_SPLOCK2_SPLOCK73			(0x1u<<9)
#define	BSEC_SPLOCK2_SPLOCK72			(0x1u<<8)
#define	BSEC_SPLOCK2_SPLOCK71			(0x1u<<7)
#define	BSEC_SPLOCK2_SPLOCK70			(0x1u<<6)
#define	BSEC_SPLOCK2_SPLOCK69			(0x1u<<5)
#define	BSEC_SPLOCK2_SPLOCK68			(0x1u<<4)
#define	BSEC_SPLOCK2_SPLOCK67			(0x1u<<3)
#define	BSEC_SPLOCK2_SPLOCK66			(0x1u<<2)
#define	BSEC_SPLOCK2_SPLOCK65			(0x1u<<1)
#define	BSEC_SPLOCK2_SPLOCK64			(0x1u<<0)

#define	BSEC_SPLOCK2_SPLOCK95_B_0X0		(0x0u<<31)
#define	BSEC_SPLOCK2_SPLOCK95_B_0X1		(0x1u<<31)
#define	BSEC_SPLOCK2_SPLOCK94_B_0X0		(0x0u<<30)
#define	BSEC_SPLOCK2_SPLOCK94_B_0X1		(0x1u<<30)
#define	BSEC_SPLOCK2_SPLOCK93_B_0X0		(0x0u<<29)
#define	BSEC_SPLOCK2_SPLOCK93_B_0X1		(0x1u<<29)
#define	BSEC_SPLOCK2_SPLOCK92_B_0X0		(0x0u<<28)
#define	BSEC_SPLOCK2_SPLOCK92_B_0X1		(0x1u<<28)
#define	BSEC_SPLOCK2_SPLOCK91_B_0X0		(0x0u<<27)
#define	BSEC_SPLOCK2_SPLOCK91_B_0X1		(0x1u<<27)
#define	BSEC_SPLOCK2_SPLOCK90_B_0X0		(0x0u<<26)
#define	BSEC_SPLOCK2_SPLOCK90_B_0X1		(0x1u<<26)
#define	BSEC_SPLOCK2_SPLOCK89_B_0X0		(0x0u<<25)
#define	BSEC_SPLOCK2_SPLOCK89_B_0X1		(0x1u<<25)
#define	BSEC_SPLOCK2_SPLOCK88_B_0X0		(0x0u<<24)
#define	BSEC_SPLOCK2_SPLOCK88_B_0X1		(0x1u<<24)
#define	BSEC_SPLOCK2_SPLOCK87_B_0X0		(0x0u<<23)
#define	BSEC_SPLOCK2_SPLOCK87_B_0X1		(0x1u<<23)
#define	BSEC_SPLOCK2_SPLOCK86_B_0X0		(0x0u<<22)
#define	BSEC_SPLOCK2_SPLOCK86_B_0X1		(0x1u<<22)
#define	BSEC_SPLOCK2_SPLOCK85_B_0X0		(0x0u<<21)
#define	BSEC_SPLOCK2_SPLOCK85_B_0X1		(0x1u<<21)
#define	BSEC_SPLOCK2_SPLOCK84_B_0X0		(0x0u<<20)
#define	BSEC_SPLOCK2_SPLOCK84_B_0X1		(0x1u<<20)
#define	BSEC_SPLOCK2_SPLOCK83_B_0X0		(0x0u<<19)
#define	BSEC_SPLOCK2_SPLOCK83_B_0X1		(0x1u<<19)
#define	BSEC_SPLOCK2_SPLOCK82_B_0X0		(0x0u<<18)
#define	BSEC_SPLOCK2_SPLOCK82_B_0X1		(0x1u<<18)
#define	BSEC_SPLOCK2_SPLOCK81_B_0X0		(0x0u<<17)
#define	BSEC_SPLOCK2_SPLOCK81_B_0X1		(0x1u<<17)
#define	BSEC_SPLOCK2_SPLOCK80_B_0X0		(0x0u<<16)
#define	BSEC_SPLOCK2_SPLOCK80_B_0X1		(0x1u<<16)
#define	BSEC_SPLOCK2_SPLOCK79_B_0X0		(0x0u<<15)
#define	BSEC_SPLOCK2_SPLOCK79_B_0X1		(0x1u<<15)
#define	BSEC_SPLOCK2_SPLOCK78_B_0X0		(0x0u<<14)
#define	BSEC_SPLOCK2_SPLOCK78_B_0X1		(0x1u<<14)
#define	BSEC_SPLOCK2_SPLOCK77_B_0X0		(0x0u<<13)
#define	BSEC_SPLOCK2_SPLOCK77_B_0X1		(0x1u<<13)
#define	BSEC_SPLOCK2_SPLOCK76_B_0X0		(0x0u<<12)
#define	BSEC_SPLOCK2_SPLOCK76_B_0X1		(0x1u<<12)
#define	BSEC_SPLOCK2_SPLOCK75_B_0X0		(0x0u<<11)
#define	BSEC_SPLOCK2_SPLOCK75_B_0X1		(0x1u<<11)
#define	BSEC_SPLOCK2_SPLOCK74_B_0X0		(0x0u<<10)
#define	BSEC_SPLOCK2_SPLOCK74_B_0X1		(0x1u<<10)
#define	BSEC_SPLOCK2_SPLOCK73_B_0X0		(0x0u<<9)
#define	BSEC_SPLOCK2_SPLOCK73_B_0X1		(0x1u<<9)
#define	BSEC_SPLOCK2_SPLOCK72_B_0X0		(0x0u<<8)
#define	BSEC_SPLOCK2_SPLOCK72_B_0X1		(0x1u<<8)
#define	BSEC_SPLOCK2_SPLOCK71_B_0X0		(0x0u<<7)
#define	BSEC_SPLOCK2_SPLOCK71_B_0X1		(0x1u<<7)
#define	BSEC_SPLOCK2_SPLOCK70_B_0X0		(0x0u<<6)
#define	BSEC_SPLOCK2_SPLOCK70_B_0X1		(0x1u<<6)
#define	BSEC_SPLOCK2_SPLOCK69_B_0X0		(0x0u<<5)
#define	BSEC_SPLOCK2_SPLOCK69_B_0X1		(0x1u<<5)
#define	BSEC_SPLOCK2_SPLOCK68_B_0X0		(0x0u<<4)
#define	BSEC_SPLOCK2_SPLOCK68_B_0X1		(0x1u<<4)
#define	BSEC_SPLOCK2_SPLOCK67_B_0X0		(0x0u<<3)
#define	BSEC_SPLOCK2_SPLOCK67_B_0X1		(0x1u<<3)
#define	BSEC_SPLOCK2_SPLOCK66_B_0X0		(0x0u<<2)
#define	BSEC_SPLOCK2_SPLOCK66_B_0X1		(0x1u<<2)
#define	BSEC_SPLOCK2_SPLOCK65_B_0X0		(0x0u<<1)
#define	BSEC_SPLOCK2_SPLOCK65_B_0X1		(0x1u<<1)
#define	BSEC_SPLOCK2_SPLOCK64_B_0X0		(0x0u<<0)
#define	BSEC_SPLOCK2_SPLOCK64_B_0X1		(0x1u<<0)

// SPLOCK3 Configuration

#define	BSEC_SPLOCK3_SPLOCK127			(0x1u<<31)
#define	BSEC_SPLOCK3_SPLOCK126			(0x1u<<30)
#define	BSEC_SPLOCK3_SPLOCK125			(0x1u<<29)
#define	BSEC_SPLOCK3_SPLOCK124			(0x1u<<28)
#define	BSEC_SPLOCK3_SPLOCK123			(0x1u<<27)
#define	BSEC_SPLOCK3_SPLOCK122			(0x1u<<26)
#define	BSEC_SPLOCK3_SPLOCK121			(0x1u<<25)
#define	BSEC_SPLOCK3_SPLOCK120			(0x1u<<24)
#define	BSEC_SPLOCK3_SPLOCK119			(0x1u<<23)
#define	BSEC_SPLOCK3_SPLOCK118			(0x1u<<22)
#define	BSEC_SPLOCK3_SPLOCK117			(0x1u<<21)
#define	BSEC_SPLOCK3_SPLOCK116			(0x1u<<20)
#define	BSEC_SPLOCK3_SPLOCK115			(0x1u<<19)
#define	BSEC_SPLOCK3_SPLOCK114			(0x1u<<18)
#define	BSEC_SPLOCK3_SPLOCK113			(0x1u<<17)
#define	BSEC_SPLOCK3_SPLOCK112			(0x1u<<16)
#define	BSEC_SPLOCK3_SPLOCK111			(0x1u<<15)
#define	BSEC_SPLOCK3_SPLOCK110			(0x1u<<14)
#define	BSEC_SPLOCK3_SPLOCK109			(0x1u<<13)
#define	BSEC_SPLOCK3_SPLOCK108			(0x1u<<12)
#define	BSEC_SPLOCK3_SPLOCK107			(0x1u<<11)
#define	BSEC_SPLOCK3_SPLOCK106			(0x1u<<10)
#define	BSEC_SPLOCK3_SPLOCK105			(0x1u<<9)
#define	BSEC_SPLOCK3_SPLOCK104			(0x1u<<8)
#define	BSEC_SPLOCK3_SPLOCK103			(0x1u<<7)
#define	BSEC_SPLOCK3_SPLOCK102			(0x1u<<6)
#define	BSEC_SPLOCK3_SPLOCK101			(0x1u<<5)
#define	BSEC_SPLOCK3_SPLOCK100			(0x1u<<4)
#define	BSEC_SPLOCK3_SPLOCK99			(0x1u<<3)
#define	BSEC_SPLOCK3_SPLOCK98			(0x1u<<2)
#define	BSEC_SPLOCK3_SPLOCK97			(0x1u<<1)
#define	BSEC_SPLOCK3_SPLOCK96			(0x1u<<0)

#define	BSEC_SPLOCK3_SPLOCK127_B_0X0	(0x0u<<31)
#define	BSEC_SPLOCK3_SPLOCK127_B_0X1	(0x1u<<31)
#define	BSEC_SPLOCK3_SPLOCK126_B_0X0	(0x0u<<30)
#define	BSEC_SPLOCK3_SPLOCK126_B_0X1	(0x1u<<30)
#define	BSEC_SPLOCK3_SPLOCK125_B_0X0	(0x0u<<29)
#define	BSEC_SPLOCK3_SPLOCK125_B_0X1	(0x1u<<29)
#define	BSEC_SPLOCK3_SPLOCK124_B_0X0	(0x0u<<28)
#define	BSEC_SPLOCK3_SPLOCK124_B_0X1	(0x1u<<28)
#define	BSEC_SPLOCK3_SPLOCK123_B_0X0	(0x0u<<27)
#define	BSEC_SPLOCK3_SPLOCK123_B_0X1	(0x1u<<27)
#define	BSEC_SPLOCK3_SPLOCK122_B_0X0	(0x0u<<26)
#define	BSEC_SPLOCK3_SPLOCK122_B_0X1	(0x1u<<26)
#define	BSEC_SPLOCK3_SPLOCK121_B_0X0	(0x0u<<25)
#define	BSEC_SPLOCK3_SPLOCK121_B_0X1	(0x1u<<25)
#define	BSEC_SPLOCK3_SPLOCK120_B_0X0	(0x0u<<24)
#define	BSEC_SPLOCK3_SPLOCK120_B_0X1	(0x1u<<24)
#define	BSEC_SPLOCK3_SPLOCK119_B_0X0	(0x0u<<23)
#define	BSEC_SPLOCK3_SPLOCK119_B_0X1	(0x1u<<23)
#define	BSEC_SPLOCK3_SPLOCK118_B_0X0	(0x0u<<22)
#define	BSEC_SPLOCK3_SPLOCK118_B_0X1	(0x1u<<22)
#define	BSEC_SPLOCK3_SPLOCK117_B_0X0	(0x0u<<21)
#define	BSEC_SPLOCK3_SPLOCK117_B_0X1	(0x1u<<21)
#define	BSEC_SPLOCK3_SPLOCK116_B_0X0	(0x0u<<20)
#define	BSEC_SPLOCK3_SPLOCK116_B_0X1	(0x1u<<20)
#define	BSEC_SPLOCK3_SPLOCK115_B_0X0	(0x0u<<19)
#define	BSEC_SPLOCK3_SPLOCK115_B_0X1	(0x1u<<19)
#define	BSEC_SPLOCK3_SPLOCK114_B_0X0	(0x0u<<18)
#define	BSEC_SPLOCK3_SPLOCK114_B_0X1	(0x1u<<18)
#define	BSEC_SPLOCK3_SPLOCK113_B_0X0	(0x0u<<17)
#define	BSEC_SPLOCK3_SPLOCK113_B_0X1	(0x1u<<17)
#define	BSEC_SPLOCK3_SPLOCK112_B_0X0	(0x0u<<16)
#define	BSEC_SPLOCK3_SPLOCK112_B_0X1	(0x1u<<16)
#define	BSEC_SPLOCK3_SPLOCK111_B_0X0	(0x0u<<15)
#define	BSEC_SPLOCK3_SPLOCK111_B_0X1	(0x1u<<15)
#define	BSEC_SPLOCK3_SPLOCK110_B_0X0	(0x0u<<14)
#define	BSEC_SPLOCK3_SPLOCK110_B_0X1	(0x1u<<14)
#define	BSEC_SPLOCK3_SPLOCK109_B_0X0	(0x0u<<13)
#define	BSEC_SPLOCK3_SPLOCK109_B_0X1	(0x1u<<13)
#define	BSEC_SPLOCK3_SPLOCK108_B_0X0	(0x0u<<12)
#define	BSEC_SPLOCK3_SPLOCK108_B_0X1	(0x1u<<12)
#define	BSEC_SPLOCK3_SPLOCK107_B_0X0	(0x0u<<11)
#define	BSEC_SPLOCK3_SPLOCK107_B_0X1	(0x1u<<11)
#define	BSEC_SPLOCK3_SPLOCK106_B_0X0	(0x0u<<10)
#define	BSEC_SPLOCK3_SPLOCK106_B_0X1	(0x1u<<10)
#define	BSEC_SPLOCK3_SPLOCK105_B_0X0	(0x0u<<9)
#define	BSEC_SPLOCK3_SPLOCK105_B_0X1	(0x1u<<9)
#define	BSEC_SPLOCK3_SPLOCK104_B_0X0	(0x0u<<8)
#define	BSEC_SPLOCK3_SPLOCK104_B_0X1	(0x1u<<8)
#define	BSEC_SPLOCK3_SPLOCK103_B_0X0	(0x0u<<7)
#define	BSEC_SPLOCK3_SPLOCK103_B_0X1	(0x1u<<7)
#define	BSEC_SPLOCK3_SPLOCK102_B_0X0	(0x0u<<6)
#define	BSEC_SPLOCK3_SPLOCK102_B_0X1	(0x1u<<6)
#define	BSEC_SPLOCK3_SPLOCK101_B_0X0	(0x0u<<5)
#define	BSEC_SPLOCK3_SPLOCK101_B_0X1	(0x1u<<5)
#define	BSEC_SPLOCK3_SPLOCK100_B_0X0	(0x0u<<4)
#define	BSEC_SPLOCK3_SPLOCK100_B_0X1	(0x1u<<4)
#define	BSEC_SPLOCK3_SPLOCK99_B_0X0		(0x0u<<3)
#define	BSEC_SPLOCK3_SPLOCK99_B_0X1		(0x1u<<3)
#define	BSEC_SPLOCK3_SPLOCK98_B_0X0		(0x0u<<2)
#define	BSEC_SPLOCK3_SPLOCK98_B_0X1		(0x1u<<2)
#define	BSEC_SPLOCK3_SPLOCK97_B_0X0		(0x0u<<1)
#define	BSEC_SPLOCK3_SPLOCK97_B_0X1		(0x1u<<1)
#define	BSEC_SPLOCK3_SPLOCK96_B_0X0		(0x0u<<0)
#define	BSEC_SPLOCK3_SPLOCK96_B_0X1		(0x1u<<0)

// SPLOCK4 Configuration

#define	BSEC_SPLOCK4_SPLOCK159			(0x1u<<31)
#define	BSEC_SPLOCK4_SPLOCK158			(0x1u<<30)
#define	BSEC_SPLOCK4_SPLOCK157			(0x1u<<29)
#define	BSEC_SPLOCK4_SPLOCK156			(0x1u<<28)
#define	BSEC_SPLOCK4_SPLOCK155			(0x1u<<27)
#define	BSEC_SPLOCK4_SPLOCK154			(0x1u<<26)
#define	BSEC_SPLOCK4_SPLOCK153			(0x1u<<25)
#define	BSEC_SPLOCK4_SPLOCK152			(0x1u<<24)
#define	BSEC_SPLOCK4_SPLOCK151			(0x1u<<23)
#define	BSEC_SPLOCK4_SPLOCK150			(0x1u<<22)
#define	BSEC_SPLOCK4_SPLOCK149			(0x1u<<21)
#define	BSEC_SPLOCK4_SPLOCK148			(0x1u<<20)
#define	BSEC_SPLOCK4_SPLOCK147			(0x1u<<19)
#define	BSEC_SPLOCK4_SPLOCK146			(0x1u<<18)
#define	BSEC_SPLOCK4_SPLOCK145			(0x1u<<17)
#define	BSEC_SPLOCK4_SPLOCK144			(0x1u<<16)
#define	BSEC_SPLOCK4_SPLOCK143			(0x1u<<15)
#define	BSEC_SPLOCK4_SPLOCK142			(0x1u<<14)
#define	BSEC_SPLOCK4_SPLOCK141			(0x1u<<13)
#define	BSEC_SPLOCK4_SPLOCK140			(0x1u<<12)
#define	BSEC_SPLOCK4_SPLOCK139			(0x1u<<11)
#define	BSEC_SPLOCK4_SPLOCK138			(0x1u<<10)
#define	BSEC_SPLOCK4_SPLOCK137			(0x1u<<9)
#define	BSEC_SPLOCK4_SPLOCK136			(0x1u<<8)
#define	BSEC_SPLOCK4_SPLOCK135			(0x1u<<7)
#define	BSEC_SPLOCK4_SPLOCK134			(0x1u<<6)
#define	BSEC_SPLOCK4_SPLOCK133			(0x1u<<5)
#define	BSEC_SPLOCK4_SPLOCK132			(0x1u<<4)
#define	BSEC_SPLOCK4_SPLOCK131			(0x1u<<3)
#define	BSEC_SPLOCK4_SPLOCK130			(0x1u<<2)
#define	BSEC_SPLOCK4_SPLOCK129			(0x1u<<1)
#define	BSEC_SPLOCK4_SPLOCK128			(0x1u<<0)

#define	BSEC_SPLOCK4_SPLOCK159_B_0X0	(0x0u<<31)
#define	BSEC_SPLOCK4_SPLOCK159_B_0X1	(0x1u<<31)
#define	BSEC_SPLOCK4_SPLOCK158_B_0X0	(0x0u<<30)
#define	BSEC_SPLOCK4_SPLOCK158_B_0X1	(0x1u<<30)
#define	BSEC_SPLOCK4_SPLOCK157_B_0X0	(0x0u<<29)
#define	BSEC_SPLOCK4_SPLOCK157_B_0X1	(0x1u<<29)
#define	BSEC_SPLOCK4_SPLOCK156_B_0X0	(0x0u<<28)
#define	BSEC_SPLOCK4_SPLOCK156_B_0X1	(0x1u<<28)
#define	BSEC_SPLOCK4_SPLOCK155_B_0X0	(0x0u<<27)
#define	BSEC_SPLOCK4_SPLOCK155_B_0X1	(0x1u<<27)
#define	BSEC_SPLOCK4_SPLOCK154_B_0X0	(0x0u<<26)
#define	BSEC_SPLOCK4_SPLOCK154_B_0X1	(0x1u<<26)
#define	BSEC_SPLOCK4_SPLOCK153_B_0X0	(0x0u<<25)
#define	BSEC_SPLOCK4_SPLOCK153_B_0X1	(0x1u<<25)
#define	BSEC_SPLOCK4_SPLOCK152_B_0X0	(0x0u<<24)
#define	BSEC_SPLOCK4_SPLOCK152_B_0X1	(0x1u<<24)
#define	BSEC_SPLOCK4_SPLOCK151_B_0X0	(0x0u<<23)
#define	BSEC_SPLOCK4_SPLOCK151_B_0X1	(0x1u<<23)
#define	BSEC_SPLOCK4_SPLOCK150_B_0X0	(0x0u<<22)
#define	BSEC_SPLOCK4_SPLOCK150_B_0X1	(0x1u<<22)
#define	BSEC_SPLOCK4_SPLOCK149_B_0X0	(0x0u<<21)
#define	BSEC_SPLOCK4_SPLOCK149_B_0X1	(0x1u<<21)
#define	BSEC_SPLOCK4_SPLOCK148_B_0X0	(0x0u<<20)
#define	BSEC_SPLOCK4_SPLOCK148_B_0X1	(0x1u<<20)
#define	BSEC_SPLOCK4_SPLOCK147_B_0X0	(0x0u<<19)
#define	BSEC_SPLOCK4_SPLOCK147_B_0X1	(0x1u<<19)
#define	BSEC_SPLOCK4_SPLOCK146_B_0X0	(0x0u<<18)
#define	BSEC_SPLOCK4_SPLOCK146_B_0X1	(0x1u<<18)
#define	BSEC_SPLOCK4_SPLOCK145_B_0X0	(0x0u<<17)
#define	BSEC_SPLOCK4_SPLOCK145_B_0X1	(0x1u<<17)
#define	BSEC_SPLOCK4_SPLOCK144_B_0X0	(0x0u<<16)
#define	BSEC_SPLOCK4_SPLOCK144_B_0X1	(0x1u<<16)
#define	BSEC_SPLOCK4_SPLOCK143_B_0X0	(0x0u<<15)
#define	BSEC_SPLOCK4_SPLOCK143_B_0X1	(0x1u<<15)
#define	BSEC_SPLOCK4_SPLOCK142_B_0X0	(0x0u<<14)
#define	BSEC_SPLOCK4_SPLOCK142_B_0X1	(0x1u<<14)
#define	BSEC_SPLOCK4_SPLOCK141_B_0X0	(0x0u<<13)
#define	BSEC_SPLOCK4_SPLOCK141_B_0X1	(0x1u<<13)
#define	BSEC_SPLOCK4_SPLOCK140_B_0X0	(0x0u<<12)
#define	BSEC_SPLOCK4_SPLOCK140_B_0X1	(0x1u<<12)
#define	BSEC_SPLOCK4_SPLOCK139_B_0X0	(0x0u<<11)
#define	BSEC_SPLOCK4_SPLOCK139_B_0X1	(0x1u<<11)
#define	BSEC_SPLOCK4_SPLOCK138_B_0X0	(0x0u<<10)
#define	BSEC_SPLOCK4_SPLOCK138_B_0X1	(0x1u<<10)
#define	BSEC_SPLOCK4_SPLOCK137_B_0X0	(0x0u<<9)
#define	BSEC_SPLOCK4_SPLOCK137_B_0X1	(0x1u<<9)
#define	BSEC_SPLOCK4_SPLOCK136_B_0X0	(0x0u<<8)
#define	BSEC_SPLOCK4_SPLOCK136_B_0X1	(0x1u<<8)
#define	BSEC_SPLOCK4_SPLOCK135_B_0X0	(0x0u<<7)
#define	BSEC_SPLOCK4_SPLOCK135_B_0X1	(0x1u<<7)
#define	BSEC_SPLOCK4_SPLOCK134_B_0X0	(0x0u<<6)
#define	BSEC_SPLOCK4_SPLOCK134_B_0X1	(0x1u<<6)
#define	BSEC_SPLOCK4_SPLOCK133_B_0X0	(0x0u<<5)
#define	BSEC_SPLOCK4_SPLOCK133_B_0X1	(0x1u<<5)
#define	BSEC_SPLOCK4_SPLOCK132_B_0X0	(0x0u<<4)
#define	BSEC_SPLOCK4_SPLOCK132_B_0X1	(0x1u<<4)
#define	BSEC_SPLOCK4_SPLOCK131_B_0X0	(0x0u<<3)
#define	BSEC_SPLOCK4_SPLOCK131_B_0X1	(0x1u<<3)
#define	BSEC_SPLOCK4_SPLOCK130_B_0X0	(0x0u<<2)
#define	BSEC_SPLOCK4_SPLOCK130_B_0X1	(0x1u<<2)
#define	BSEC_SPLOCK4_SPLOCK129_B_0X0	(0x0u<<1)
#define	BSEC_SPLOCK4_SPLOCK129_B_0X1	(0x1u<<1)
#define	BSEC_SPLOCK4_SPLOCK128_B_0X0	(0x0u<<0)
#define	BSEC_SPLOCK4_SPLOCK128_B_0X1	(0x1u<<0)

// SPLOCK5 Configuration

#define	BSEC_SPLOCK5_SPLOCK191			(0x1u<<31)
#define	BSEC_SPLOCK5_SPLOCK190			(0x1u<<30)
#define	BSEC_SPLOCK5_SPLOCK189			(0x1u<<29)
#define	BSEC_SPLOCK5_SPLOCK188			(0x1u<<28)
#define	BSEC_SPLOCK5_SPLOCK187			(0x1u<<27)
#define	BSEC_SPLOCK5_SPLOCK186			(0x1u<<26)
#define	BSEC_SPLOCK5_SPLOCK185			(0x1u<<25)
#define	BSEC_SPLOCK5_SPLOCK184			(0x1u<<24)
#define	BSEC_SPLOCK5_SPLOCK183			(0x1u<<23)
#define	BSEC_SPLOCK5_SPLOCK182			(0x1u<<22)
#define	BSEC_SPLOCK5_SPLOCK181			(0x1u<<21)
#define	BSEC_SPLOCK5_SPLOCK180			(0x1u<<20)
#define	BSEC_SPLOCK5_SPLOCK179			(0x1u<<19)
#define	BSEC_SPLOCK5_SPLOCK178			(0x1u<<18)
#define	BSEC_SPLOCK5_SPLOCK177			(0x1u<<17)
#define	BSEC_SPLOCK5_SPLOCK176			(0x1u<<16)
#define	BSEC_SPLOCK5_SPLOCK175			(0x1u<<15)
#define	BSEC_SPLOCK5_SPLOCK174			(0x1u<<14)
#define	BSEC_SPLOCK5_SPLOCK173			(0x1u<<13)
#define	BSEC_SPLOCK5_SPLOCK172			(0x1u<<12)
#define	BSEC_SPLOCK5_SPLOCK171			(0x1u<<11)
#define	BSEC_SPLOCK5_SPLOCK170			(0x1u<<10)
#define	BSEC_SPLOCK5_SPLOCK169			(0x1u<<9)
#define	BSEC_SPLOCK5_SPLOCK168			(0x1u<<8)
#define	BSEC_SPLOCK5_SPLOCK167			(0x1u<<7)
#define	BSEC_SPLOCK5_SPLOCK166			(0x1u<<6)
#define	BSEC_SPLOCK5_SPLOCK165			(0x1u<<5)
#define	BSEC_SPLOCK5_SPLOCK164			(0x1u<<4)
#define	BSEC_SPLOCK5_SPLOCK163			(0x1u<<3)
#define	BSEC_SPLOCK5_SPLOCK162			(0x1u<<2)
#define	BSEC_SPLOCK5_SPLOCK161			(0x1u<<1)
#define	BSEC_SPLOCK5_SPLOCK160			(0x1u<<0)

#define	BSEC_SPLOCK5_SPLOCK191_B_0X0	(0x0u<<31)
#define	BSEC_SPLOCK5_SPLOCK191_B_0X1	(0x1u<<31)
#define	BSEC_SPLOCK5_SPLOCK190_B_0X0	(0x0u<<30)
#define	BSEC_SPLOCK5_SPLOCK190_B_0X1	(0x1u<<30)
#define	BSEC_SPLOCK5_SPLOCK189_B_0X0	(0x0u<<29)
#define	BSEC_SPLOCK5_SPLOCK189_B_0X1	(0x1u<<29)
#define	BSEC_SPLOCK5_SPLOCK188_B_0X0	(0x0u<<28)
#define	BSEC_SPLOCK5_SPLOCK188_B_0X1	(0x1u<<28)
#define	BSEC_SPLOCK5_SPLOCK187_B_0X0	(0x0u<<27)
#define	BSEC_SPLOCK5_SPLOCK187_B_0X1	(0x1u<<27)
#define	BSEC_SPLOCK5_SPLOCK186_B_0X0	(0x0u<<26)
#define	BSEC_SPLOCK5_SPLOCK186_B_0X1	(0x1u<<26)
#define	BSEC_SPLOCK5_SPLOCK185_B_0X0	(0x0u<<25)
#define	BSEC_SPLOCK5_SPLOCK185_B_0X1	(0x1u<<25)
#define	BSEC_SPLOCK5_SPLOCK184_B_0X0	(0x0u<<24)
#define	BSEC_SPLOCK5_SPLOCK184_B_0X1	(0x1u<<24)
#define	BSEC_SPLOCK5_SPLOCK183_B_0X0	(0x0u<<23)
#define	BSEC_SPLOCK5_SPLOCK183_B_0X1	(0x1u<<23)
#define	BSEC_SPLOCK5_SPLOCK182_B_0X0	(0x0u<<22)
#define	BSEC_SPLOCK5_SPLOCK182_B_0X1	(0x1u<<22)
#define	BSEC_SPLOCK5_SPLOCK181_B_0X0	(0x0u<<21)
#define	BSEC_SPLOCK5_SPLOCK181_B_0X1	(0x1u<<21)
#define	BSEC_SPLOCK5_SPLOCK180_B_0X0	(0x0u<<20)
#define	BSEC_SPLOCK5_SPLOCK180_B_0X1	(0x1u<<20)
#define	BSEC_SPLOCK5_SPLOCK179_B_0X0	(0x0u<<19)
#define	BSEC_SPLOCK5_SPLOCK179_B_0X1	(0x1u<<19)
#define	BSEC_SPLOCK5_SPLOCK178_B_0X0	(0x0u<<18)
#define	BSEC_SPLOCK5_SPLOCK178_B_0X1	(0x1u<<18)
#define	BSEC_SPLOCK5_SPLOCK177_B_0X0	(0x0u<<17)
#define	BSEC_SPLOCK5_SPLOCK177_B_0X1	(0x1u<<17)
#define	BSEC_SPLOCK5_SPLOCK176_B_0X0	(0x0u<<16)
#define	BSEC_SPLOCK5_SPLOCK176_B_0X1	(0x1u<<16)
#define	BSEC_SPLOCK5_SPLOCK175_B_0X0	(0x0u<<15)
#define	BSEC_SPLOCK5_SPLOCK175_B_0X1	(0x1u<<15)
#define	BSEC_SPLOCK5_SPLOCK174_B_0X0	(0x0u<<14)
#define	BSEC_SPLOCK5_SPLOCK174_B_0X1	(0x1u<<14)
#define	BSEC_SPLOCK5_SPLOCK173_B_0X0	(0x0u<<13)
#define	BSEC_SPLOCK5_SPLOCK173_B_0X1	(0x1u<<13)
#define	BSEC_SPLOCK5_SPLOCK172_B_0X0	(0x0u<<12)
#define	BSEC_SPLOCK5_SPLOCK172_B_0X1	(0x1u<<12)
#define	BSEC_SPLOCK5_SPLOCK171_B_0X0	(0x0u<<11)
#define	BSEC_SPLOCK5_SPLOCK171_B_0X1	(0x1u<<11)
#define	BSEC_SPLOCK5_SPLOCK170_B_0X0	(0x0u<<10)
#define	BSEC_SPLOCK5_SPLOCK170_B_0X1	(0x1u<<10)
#define	BSEC_SPLOCK5_SPLOCK169_B_0X0	(0x0u<<9)
#define	BSEC_SPLOCK5_SPLOCK169_B_0X1	(0x1u<<9)
#define	BSEC_SPLOCK5_SPLOCK168_B_0X0	(0x0u<<8)
#define	BSEC_SPLOCK5_SPLOCK168_B_0X1	(0x1u<<8)
#define	BSEC_SPLOCK5_SPLOCK167_B_0X0	(0x0u<<7)
#define	BSEC_SPLOCK5_SPLOCK167_B_0X1	(0x1u<<7)
#define	BSEC_SPLOCK5_SPLOCK166_B_0X0	(0x0u<<6)
#define	BSEC_SPLOCK5_SPLOCK166_B_0X1	(0x1u<<6)
#define	BSEC_SPLOCK5_SPLOCK165_B_0X0	(0x0u<<5)
#define	BSEC_SPLOCK5_SPLOCK165_B_0X1	(0x1u<<5)
#define	BSEC_SPLOCK5_SPLOCK164_B_0X0	(0x0u<<4)
#define	BSEC_SPLOCK5_SPLOCK164_B_0X1	(0x1u<<4)
#define	BSEC_SPLOCK5_SPLOCK163_B_0X0	(0x0u<<3)
#define	BSEC_SPLOCK5_SPLOCK163_B_0X1	(0x1u<<3)
#define	BSEC_SPLOCK5_SPLOCK162_B_0X0	(0x0u<<2)
#define	BSEC_SPLOCK5_SPLOCK162_B_0X1	(0x1u<<2)
#define	BSEC_SPLOCK5_SPLOCK161_B_0X0	(0x0u<<1)
#define	BSEC_SPLOCK5_SPLOCK161_B_0X1	(0x1u<<1)
#define	BSEC_SPLOCK5_SPLOCK160_B_0X0	(0x0u<<0)
#define	BSEC_SPLOCK5_SPLOCK160_B_0X1	(0x1u<<0)

// SPLOCK6 Configuration

#define	BSEC_SPLOCK6_SPLOCK223			(0x1u<<31)
#define	BSEC_SPLOCK6_SPLOCK222			(0x1u<<30)
#define	BSEC_SPLOCK6_SPLOCK221			(0x1u<<29)
#define	BSEC_SPLOCK6_SPLOCK220			(0x1u<<28)
#define	BSEC_SPLOCK6_SPLOCK219			(0x1u<<27)
#define	BSEC_SPLOCK6_SPLOCK218			(0x1u<<26)
#define	BSEC_SPLOCK6_SPLOCK217			(0x1u<<25)
#define	BSEC_SPLOCK6_SPLOCK216			(0x1u<<24)
#define	BSEC_SPLOCK6_SPLOCK215			(0x1u<<23)
#define	BSEC_SPLOCK6_SPLOCK214			(0x1u<<22)
#define	BSEC_SPLOCK6_SPLOCK213			(0x1u<<21)
#define	BSEC_SPLOCK6_SPLOCK212			(0x1u<<20)
#define	BSEC_SPLOCK6_SPLOCK211			(0x1u<<19)
#define	BSEC_SPLOCK6_SPLOCK210			(0x1u<<18)
#define	BSEC_SPLOCK6_SPLOCK209			(0x1u<<17)
#define	BSEC_SPLOCK6_SPLOCK208			(0x1u<<16)
#define	BSEC_SPLOCK6_SPLOCK207			(0x1u<<15)
#define	BSEC_SPLOCK6_SPLOCK206			(0x1u<<14)
#define	BSEC_SPLOCK6_SPLOCK205			(0x1u<<13)
#define	BSEC_SPLOCK6_SPLOCK204			(0x1u<<12)
#define	BSEC_SPLOCK6_SPLOCK203			(0x1u<<11)
#define	BSEC_SPLOCK6_SPLOCK202			(0x1u<<10)
#define	BSEC_SPLOCK6_SPLOCK201			(0x1u<<9)
#define	BSEC_SPLOCK6_SPLOCK200			(0x1u<<8)
#define	BSEC_SPLOCK6_SPLOCK199			(0x1u<<7)
#define	BSEC_SPLOCK6_SPLOCK198			(0x1u<<6)
#define	BSEC_SPLOCK6_SPLOCK197			(0x1u<<5)
#define	BSEC_SPLOCK6_SPLOCK196			(0x1u<<4)
#define	BSEC_SPLOCK6_SPLOCK195			(0x1u<<3)
#define	BSEC_SPLOCK6_SPLOCK194			(0x1u<<2)
#define	BSEC_SPLOCK6_SPLOCK193			(0x1u<<1)
#define	BSEC_SPLOCK6_SPLOCK192			(0x1u<<0)

#define	BSEC_SPLOCK6_SPLOCK223_B_0X0	(0x0u<<31)
#define	BSEC_SPLOCK6_SPLOCK223_B_0X1	(0x1u<<31)
#define	BSEC_SPLOCK6_SPLOCK222_B_0X0	(0x0u<<30)
#define	BSEC_SPLOCK6_SPLOCK222_B_0X1	(0x1u<<30)
#define	BSEC_SPLOCK6_SPLOCK221_B_0X0	(0x0u<<29)
#define	BSEC_SPLOCK6_SPLOCK221_B_0X1	(0x1u<<29)
#define	BSEC_SPLOCK6_SPLOCK220_B_0X0	(0x0u<<28)
#define	BSEC_SPLOCK6_SPLOCK220_B_0X1	(0x1u<<28)
#define	BSEC_SPLOCK6_SPLOCK219_B_0X0	(0x0u<<27)
#define	BSEC_SPLOCK6_SPLOCK219_B_0X1	(0x1u<<27)
#define	BSEC_SPLOCK6_SPLOCK218_B_0X0	(0x0u<<26)
#define	BSEC_SPLOCK6_SPLOCK218_B_0X1	(0x1u<<26)
#define	BSEC_SPLOCK6_SPLOCK217_B_0X0	(0x0u<<25)
#define	BSEC_SPLOCK6_SPLOCK217_B_0X1	(0x1u<<25)
#define	BSEC_SPLOCK6_SPLOCK216_B_0X0	(0x0u<<24)
#define	BSEC_SPLOCK6_SPLOCK216_B_0X1	(0x1u<<24)
#define	BSEC_SPLOCK6_SPLOCK215_B_0X0	(0x0u<<23)
#define	BSEC_SPLOCK6_SPLOCK215_B_0X1	(0x1u<<23)
#define	BSEC_SPLOCK6_SPLOCK214_B_0X0	(0x0u<<22)
#define	BSEC_SPLOCK6_SPLOCK214_B_0X1	(0x1u<<22)
#define	BSEC_SPLOCK6_SPLOCK213_B_0X0	(0x0u<<21)
#define	BSEC_SPLOCK6_SPLOCK213_B_0X1	(0x1u<<21)
#define	BSEC_SPLOCK6_SPLOCK212_B_0X0	(0x0u<<20)
#define	BSEC_SPLOCK6_SPLOCK212_B_0X1	(0x1u<<20)
#define	BSEC_SPLOCK6_SPLOCK211_B_0X0	(0x0u<<19)
#define	BSEC_SPLOCK6_SPLOCK211_B_0X1	(0x1u<<19)
#define	BSEC_SPLOCK6_SPLOCK210_B_0X0	(0x0u<<18)
#define	BSEC_SPLOCK6_SPLOCK210_B_0X1	(0x1u<<18)
#define	BSEC_SPLOCK6_SPLOCK209_B_0X0	(0x0u<<17)
#define	BSEC_SPLOCK6_SPLOCK209_B_0X1	(0x1u<<17)
#define	BSEC_SPLOCK6_SPLOCK208_B_0X0	(0x0u<<16)
#define	BSEC_SPLOCK6_SPLOCK208_B_0X1	(0x1u<<16)
#define	BSEC_SPLOCK6_SPLOCK207_B_0X0	(0x0u<<15)
#define	BSEC_SPLOCK6_SPLOCK207_B_0X1	(0x1u<<15)
#define	BSEC_SPLOCK6_SPLOCK206_B_0X0	(0x0u<<14)
#define	BSEC_SPLOCK6_SPLOCK206_B_0X1	(0x1u<<14)
#define	BSEC_SPLOCK6_SPLOCK205_B_0X0	(0x0u<<13)
#define	BSEC_SPLOCK6_SPLOCK205_B_0X1	(0x1u<<13)
#define	BSEC_SPLOCK6_SPLOCK204_B_0X0	(0x0u<<12)
#define	BSEC_SPLOCK6_SPLOCK204_B_0X1	(0x1u<<12)
#define	BSEC_SPLOCK6_SPLOCK203_B_0X0	(0x0u<<11)
#define	BSEC_SPLOCK6_SPLOCK203_B_0X1	(0x1u<<11)
#define	BSEC_SPLOCK6_SPLOCK202_B_0X0	(0x0u<<10)
#define	BSEC_SPLOCK6_SPLOCK202_B_0X1	(0x1u<<10)
#define	BSEC_SPLOCK6_SPLOCK201_B_0X0	(0x0u<<9)
#define	BSEC_SPLOCK6_SPLOCK201_B_0X1	(0x1u<<9)
#define	BSEC_SPLOCK6_SPLOCK200_B_0X0	(0x0u<<8)
#define	BSEC_SPLOCK6_SPLOCK200_B_0X1	(0x1u<<8)
#define	BSEC_SPLOCK6_SPLOCK199_B_0X0	(0x0u<<7)
#define	BSEC_SPLOCK6_SPLOCK199_B_0X1	(0x1u<<7)
#define	BSEC_SPLOCK6_SPLOCK198_B_0X0	(0x0u<<6)
#define	BSEC_SPLOCK6_SPLOCK198_B_0X1	(0x1u<<6)
#define	BSEC_SPLOCK6_SPLOCK197_B_0X0	(0x0u<<5)
#define	BSEC_SPLOCK6_SPLOCK197_B_0X1	(0x1u<<5)
#define	BSEC_SPLOCK6_SPLOCK196_B_0X0	(0x0u<<4)
#define	BSEC_SPLOCK6_SPLOCK196_B_0X1	(0x1u<<4)
#define	BSEC_SPLOCK6_SPLOCK195_B_0X0	(0x0u<<3)
#define	BSEC_SPLOCK6_SPLOCK195_B_0X1	(0x1u<<3)
#define	BSEC_SPLOCK6_SPLOCK194_B_0X0	(0x0u<<2)
#define	BSEC_SPLOCK6_SPLOCK194_B_0X1	(0x1u<<2)
#define	BSEC_SPLOCK6_SPLOCK193_B_0X0	(0x0u<<1)
#define	BSEC_SPLOCK6_SPLOCK193_B_0X1	(0x1u<<1)
#define	BSEC_SPLOCK6_SPLOCK192_B_0X0	(0x0u<<0)
#define	BSEC_SPLOCK6_SPLOCK192_B_0X1	(0x1u<<0)

// SPLOCK7 Configuration

#define	BSEC_SPLOCK7_SPLOCK255			(0x1u<<31)
#define	BSEC_SPLOCK7_SPLOCK254			(0x1u<<30)
#define	BSEC_SPLOCK7_SPLOCK253			(0x1u<<29)
#define	BSEC_SPLOCK7_SPLOCK252			(0x1u<<28)
#define	BSEC_SPLOCK7_SPLOCK251			(0x1u<<27)
#define	BSEC_SPLOCK7_SPLOCK250			(0x1u<<26)
#define	BSEC_SPLOCK7_SPLOCK249			(0x1u<<25)
#define	BSEC_SPLOCK7_SPLOCK248			(0x1u<<24)
#define	BSEC_SPLOCK7_SPLOCK247			(0x1u<<23)
#define	BSEC_SPLOCK7_SPLOCK246			(0x1u<<22)
#define	BSEC_SPLOCK7_SPLOCK245			(0x1u<<21)
#define	BSEC_SPLOCK7_SPLOCK244			(0x1u<<20)
#define	BSEC_SPLOCK7_SPLOCK243			(0x1u<<19)
#define	BSEC_SPLOCK7_SPLOCK242			(0x1u<<18)
#define	BSEC_SPLOCK7_SPLOCK241			(0x1u<<17)
#define	BSEC_SPLOCK7_SPLOCK240			(0x1u<<16)
#define	BSEC_SPLOCK7_SPLOCK239			(0x1u<<15)
#define	BSEC_SPLOCK7_SPLOCK238			(0x1u<<14)
#define	BSEC_SPLOCK7_SPLOCK237			(0x1u<<13)
#define	BSEC_SPLOCK7_SPLOCK236			(0x1u<<12)
#define	BSEC_SPLOCK7_SPLOCK235			(0x1u<<11)
#define	BSEC_SPLOCK7_SPLOCK234			(0x1u<<10)
#define	BSEC_SPLOCK7_SPLOCK233			(0x1u<<9)
#define	BSEC_SPLOCK7_SPLOCK232			(0x1u<<8)
#define	BSEC_SPLOCK7_SPLOCK231			(0x1u<<7)
#define	BSEC_SPLOCK7_SPLOCK230			(0x1u<<6)
#define	BSEC_SPLOCK7_SPLOCK229			(0x1u<<5)
#define	BSEC_SPLOCK7_SPLOCK228			(0x1u<<4)
#define	BSEC_SPLOCK7_SPLOCK227			(0x1u<<3)
#define	BSEC_SPLOCK7_SPLOCK226			(0x1u<<2)
#define	BSEC_SPLOCK7_SPLOCK225			(0x1u<<1)
#define	BSEC_SPLOCK7_SPLOCK224			(0x1u<<0)

#define	BSEC_SPLOCK7_SPLOCK255_B_0X0	(0x0u<<31)
#define	BSEC_SPLOCK7_SPLOCK255_B_0X1	(0x1u<<31)
#define	BSEC_SPLOCK7_SPLOCK254_B_0X0	(0x0u<<30)
#define	BSEC_SPLOCK7_SPLOCK254_B_0X1	(0x1u<<30)
#define	BSEC_SPLOCK7_SPLOCK253_B_0X0	(0x0u<<29)
#define	BSEC_SPLOCK7_SPLOCK253_B_0X1	(0x1u<<29)
#define	BSEC_SPLOCK7_SPLOCK252_B_0X0	(0x0u<<28)
#define	BSEC_SPLOCK7_SPLOCK252_B_0X1	(0x1u<<28)
#define	BSEC_SPLOCK7_SPLOCK251_B_0X0	(0x0u<<27)
#define	BSEC_SPLOCK7_SPLOCK251_B_0X1	(0x1u<<27)
#define	BSEC_SPLOCK7_SPLOCK250_B_0X0	(0x0u<<26)
#define	BSEC_SPLOCK7_SPLOCK250_B_0X1	(0x1u<<26)
#define	BSEC_SPLOCK7_SPLOCK249_B_0X0	(0x0u<<25)
#define	BSEC_SPLOCK7_SPLOCK249_B_0X1	(0x1u<<25)
#define	BSEC_SPLOCK7_SPLOCK248_B_0X0	(0x0u<<24)
#define	BSEC_SPLOCK7_SPLOCK248_B_0X1	(0x1u<<24)
#define	BSEC_SPLOCK7_SPLOCK247_B_0X0	(0x0u<<23)
#define	BSEC_SPLOCK7_SPLOCK247_B_0X1	(0x1u<<23)
#define	BSEC_SPLOCK7_SPLOCK246_B_0X0	(0x0u<<22)
#define	BSEC_SPLOCK7_SPLOCK246_B_0X1	(0x1u<<22)
#define	BSEC_SPLOCK7_SPLOCK245_B_0X0	(0x0u<<21)
#define	BSEC_SPLOCK7_SPLOCK245_B_0X1	(0x1u<<21)
#define	BSEC_SPLOCK7_SPLOCK244_B_0X0	(0x0u<<20)
#define	BSEC_SPLOCK7_SPLOCK244_B_0X1	(0x1u<<20)
#define	BSEC_SPLOCK7_SPLOCK243_B_0X0	(0x0u<<19)
#define	BSEC_SPLOCK7_SPLOCK243_B_0X1	(0x1u<<19)
#define	BSEC_SPLOCK7_SPLOCK242_B_0X0	(0x0u<<18)
#define	BSEC_SPLOCK7_SPLOCK242_B_0X1	(0x1u<<18)
#define	BSEC_SPLOCK7_SPLOCK241_B_0X0	(0x0u<<17)
#define	BSEC_SPLOCK7_SPLOCK241_B_0X1	(0x1u<<17)
#define	BSEC_SPLOCK7_SPLOCK240_B_0X0	(0x0u<<16)
#define	BSEC_SPLOCK7_SPLOCK240_B_0X1	(0x1u<<16)
#define	BSEC_SPLOCK7_SPLOCK239_B_0X0	(0x0u<<15)
#define	BSEC_SPLOCK7_SPLOCK239_B_0X1	(0x1u<<15)
#define	BSEC_SPLOCK7_SPLOCK238_B_0X0	(0x0u<<14)
#define	BSEC_SPLOCK7_SPLOCK238_B_0X1	(0x1u<<14)
#define	BSEC_SPLOCK7_SPLOCK237_B_0X0	(0x0u<<13)
#define	BSEC_SPLOCK7_SPLOCK237_B_0X1	(0x1u<<13)
#define	BSEC_SPLOCK7_SPLOCK236_B_0X0	(0x0u<<12)
#define	BSEC_SPLOCK7_SPLOCK236_B_0X1	(0x1u<<12)
#define	BSEC_SPLOCK7_SPLOCK235_B_0X0	(0x0u<<11)
#define	BSEC_SPLOCK7_SPLOCK235_B_0X1	(0x1u<<11)
#define	BSEC_SPLOCK7_SPLOCK234_B_0X0	(0x0u<<10)
#define	BSEC_SPLOCK7_SPLOCK234_B_0X1	(0x1u<<10)
#define	BSEC_SPLOCK7_SPLOCK233_B_0X0	(0x0u<<9)
#define	BSEC_SPLOCK7_SPLOCK233_B_0X1	(0x1u<<9)
#define	BSEC_SPLOCK7_SPLOCK232_B_0X0	(0x0u<<8)
#define	BSEC_SPLOCK7_SPLOCK232_B_0X1	(0x1u<<8)
#define	BSEC_SPLOCK7_SPLOCK231_B_0X0	(0x0u<<7)
#define	BSEC_SPLOCK7_SPLOCK231_B_0X1	(0x1u<<7)
#define	BSEC_SPLOCK7_SPLOCK230_B_0X0	(0x0u<<6)
#define	BSEC_SPLOCK7_SPLOCK230_B_0X1	(0x1u<<6)
#define	BSEC_SPLOCK7_SPLOCK229_B_0X0	(0x0u<<5)
#define	BSEC_SPLOCK7_SPLOCK229_B_0X1	(0x1u<<5)
#define	BSEC_SPLOCK7_SPLOCK228_B_0X0	(0x0u<<4)
#define	BSEC_SPLOCK7_SPLOCK228_B_0X1	(0x1u<<4)
#define	BSEC_SPLOCK7_SPLOCK227_B_0X0	(0x0u<<3)
#define	BSEC_SPLOCK7_SPLOCK227_B_0X1	(0x1u<<3)
#define	BSEC_SPLOCK7_SPLOCK226_B_0X0	(0x0u<<2)
#define	BSEC_SPLOCK7_SPLOCK226_B_0X1	(0x1u<<2)
#define	BSEC_SPLOCK7_SPLOCK225_B_0X0	(0x0u<<1)
#define	BSEC_SPLOCK7_SPLOCK225_B_0X1	(0x1u<<1)
#define	BSEC_SPLOCK7_SPLOCK224_B_0X0	(0x0u<<0)
#define	BSEC_SPLOCK7_SPLOCK224_B_0X1	(0x1u<<0)

// SPLOCK8 Configuration

#define	BSEC_SPLOCK8_SPLOCK287			(0x1u<<31)
#define	BSEC_SPLOCK8_SPLOCK286			(0x1u<<30)
#define	BSEC_SPLOCK8_SPLOCK285			(0x1u<<29)
#define	BSEC_SPLOCK8_SPLOCK284			(0x1u<<28)
#define	BSEC_SPLOCK8_SPLOCK283			(0x1u<<27)
#define	BSEC_SPLOCK8_SPLOCK282			(0x1u<<26)
#define	BSEC_SPLOCK8_SPLOCK281			(0x1u<<25)
#define	BSEC_SPLOCK8_SPLOCK280			(0x1u<<24)
#define	BSEC_SPLOCK8_SPLOCK279			(0x1u<<23)
#define	BSEC_SPLOCK8_SPLOCK278			(0x1u<<22)
#define	BSEC_SPLOCK8_SPLOCK277			(0x1u<<21)
#define	BSEC_SPLOCK8_SPLOCK276			(0x1u<<20)
#define	BSEC_SPLOCK8_SPLOCK275			(0x1u<<19)
#define	BSEC_SPLOCK8_SPLOCK274			(0x1u<<18)
#define	BSEC_SPLOCK8_SPLOCK273			(0x1u<<17)
#define	BSEC_SPLOCK8_SPLOCK272			(0x1u<<16)
#define	BSEC_SPLOCK8_SPLOCK271			(0x1u<<15)
#define	BSEC_SPLOCK8_SPLOCK270			(0x1u<<14)
#define	BSEC_SPLOCK8_SPLOCK269			(0x1u<<13)
#define	BSEC_SPLOCK8_SPLOCK268			(0x1u<<12)
#define	BSEC_SPLOCK8_SPLOCK267			(0x1u<<11)
#define	BSEC_SPLOCK8_SPLOCK266			(0x1u<<10)
#define	BSEC_SPLOCK8_SPLOCK265			(0x1u<<9)
#define	BSEC_SPLOCK8_SPLOCK264			(0x1u<<8)
#define	BSEC_SPLOCK8_SPLOCK263			(0x1u<<7)
#define	BSEC_SPLOCK8_SPLOCK262			(0x1u<<6)
#define	BSEC_SPLOCK8_SPLOCK261			(0x1u<<5)
#define	BSEC_SPLOCK8_SPLOCK260			(0x1u<<4)
#define	BSEC_SPLOCK8_SPLOCK259			(0x1u<<3)
#define	BSEC_SPLOCK8_SPLOCK258			(0x1u<<2)
#define	BSEC_SPLOCK8_SPLOCK257			(0x1u<<1)
#define	BSEC_SPLOCK8_SPLOCK256			(0x1u<<0)

#define	BSEC_SPLOCK8_SPLOCK287_B_0X0	(0x0u<<31)
#define	BSEC_SPLOCK8_SPLOCK287_B_0X1	(0x1u<<31)
#define	BSEC_SPLOCK8_SPLOCK286_B_0X0	(0x0u<<30)
#define	BSEC_SPLOCK8_SPLOCK286_B_0X1	(0x1u<<30)
#define	BSEC_SPLOCK8_SPLOCK285_B_0X0	(0x0u<<29)
#define	BSEC_SPLOCK8_SPLOCK285_B_0X1	(0x1u<<29)
#define	BSEC_SPLOCK8_SPLOCK284_B_0X0	(0x0u<<28)
#define	BSEC_SPLOCK8_SPLOCK284_B_0X1	(0x1u<<28)
#define	BSEC_SPLOCK8_SPLOCK283_B_0X0	(0x0u<<27)
#define	BSEC_SPLOCK8_SPLOCK283_B_0X1	(0x1u<<27)
#define	BSEC_SPLOCK8_SPLOCK282_B_0X0	(0x0u<<26)
#define	BSEC_SPLOCK8_SPLOCK282_B_0X1	(0x1u<<26)
#define	BSEC_SPLOCK8_SPLOCK281_B_0X0	(0x0u<<25)
#define	BSEC_SPLOCK8_SPLOCK281_B_0X1	(0x1u<<25)
#define	BSEC_SPLOCK8_SPLOCK280_B_0X0	(0x0u<<24)
#define	BSEC_SPLOCK8_SPLOCK280_B_0X1	(0x1u<<24)
#define	BSEC_SPLOCK8_SPLOCK279_B_0X0	(0x0u<<23)
#define	BSEC_SPLOCK8_SPLOCK279_B_0X1	(0x1u<<23)
#define	BSEC_SPLOCK8_SPLOCK278_B_0X0	(0x0u<<22)
#define	BSEC_SPLOCK8_SPLOCK278_B_0X1	(0x1u<<22)
#define	BSEC_SPLOCK8_SPLOCK277_B_0X0	(0x0u<<21)
#define	BSEC_SPLOCK8_SPLOCK277_B_0X1	(0x1u<<21)
#define	BSEC_SPLOCK8_SPLOCK276_B_0X0	(0x0u<<20)
#define	BSEC_SPLOCK8_SPLOCK276_B_0X1	(0x1u<<20)
#define	BSEC_SPLOCK8_SPLOCK275_B_0X0	(0x0u<<19)
#define	BSEC_SPLOCK8_SPLOCK275_B_0X1	(0x1u<<19)
#define	BSEC_SPLOCK8_SPLOCK274_B_0X0	(0x0u<<18)
#define	BSEC_SPLOCK8_SPLOCK274_B_0X1	(0x1u<<18)
#define	BSEC_SPLOCK8_SPLOCK273_B_0X0	(0x0u<<17)
#define	BSEC_SPLOCK8_SPLOCK273_B_0X1	(0x1u<<17)
#define	BSEC_SPLOCK8_SPLOCK272_B_0X0	(0x0u<<16)
#define	BSEC_SPLOCK8_SPLOCK272_B_0X1	(0x1u<<16)
#define	BSEC_SPLOCK8_SPLOCK271_B_0X0	(0x0u<<15)
#define	BSEC_SPLOCK8_SPLOCK271_B_0X1	(0x1u<<15)
#define	BSEC_SPLOCK8_SPLOCK270_B_0X0	(0x0u<<14)
#define	BSEC_SPLOCK8_SPLOCK270_B_0X1	(0x1u<<14)
#define	BSEC_SPLOCK8_SPLOCK269_B_0X0	(0x0u<<13)
#define	BSEC_SPLOCK8_SPLOCK269_B_0X1	(0x1u<<13)
#define	BSEC_SPLOCK8_SPLOCK268_B_0X0	(0x0u<<12)
#define	BSEC_SPLOCK8_SPLOCK268_B_0X1	(0x1u<<12)
#define	BSEC_SPLOCK8_SPLOCK267_B_0X0	(0x0u<<11)
#define	BSEC_SPLOCK8_SPLOCK267_B_0X1	(0x1u<<11)
#define	BSEC_SPLOCK8_SPLOCK266_B_0X0	(0x0u<<10)
#define	BSEC_SPLOCK8_SPLOCK266_B_0X1	(0x1u<<10)
#define	BSEC_SPLOCK8_SPLOCK265_B_0X0	(0x0u<<9)
#define	BSEC_SPLOCK8_SPLOCK265_B_0X1	(0x1u<<9)
#define	BSEC_SPLOCK8_SPLOCK264_B_0X0	(0x0u<<8)
#define	BSEC_SPLOCK8_SPLOCK264_B_0X1	(0x1u<<8)
#define	BSEC_SPLOCK8_SPLOCK263_B_0X0	(0x0u<<7)
#define	BSEC_SPLOCK8_SPLOCK263_B_0X1	(0x1u<<7)
#define	BSEC_SPLOCK8_SPLOCK262_B_0X0	(0x0u<<6)
#define	BSEC_SPLOCK8_SPLOCK262_B_0X1	(0x1u<<6)
#define	BSEC_SPLOCK8_SPLOCK261_B_0X0	(0x0u<<5)
#define	BSEC_SPLOCK8_SPLOCK261_B_0X1	(0x1u<<5)
#define	BSEC_SPLOCK8_SPLOCK260_B_0X0	(0x0u<<4)
#define	BSEC_SPLOCK8_SPLOCK260_B_0X1	(0x1u<<4)
#define	BSEC_SPLOCK8_SPLOCK259_B_0X0	(0x0u<<3)
#define	BSEC_SPLOCK8_SPLOCK259_B_0X1	(0x1u<<3)
#define	BSEC_SPLOCK8_SPLOCK258_B_0X0	(0x0u<<2)
#define	BSEC_SPLOCK8_SPLOCK258_B_0X1	(0x1u<<2)
#define	BSEC_SPLOCK8_SPLOCK257_B_0X0	(0x0u<<1)
#define	BSEC_SPLOCK8_SPLOCK257_B_0X1	(0x1u<<1)
#define	BSEC_SPLOCK8_SPLOCK256_B_0X0	(0x0u<<0)
#define	BSEC_SPLOCK8_SPLOCK256_B_0X1	(0x1u<<0)

// SPLOCK9 Configuration

#define	BSEC_SPLOCK9_SPLOCK319			(0x1u<<31)
#define	BSEC_SPLOCK9_SPLOCK318			(0x1u<<30)
#define	BSEC_SPLOCK9_SPLOCK317			(0x1u<<29)
#define	BSEC_SPLOCK9_SPLOCK316			(0x1u<<28)
#define	BSEC_SPLOCK9_SPLOCK315			(0x1u<<27)
#define	BSEC_SPLOCK9_SPLOCK314			(0x1u<<26)
#define	BSEC_SPLOCK9_SPLOCK313			(0x1u<<25)
#define	BSEC_SPLOCK9_SPLOCK312			(0x1u<<24)
#define	BSEC_SPLOCK9_SPLOCK311			(0x1u<<23)
#define	BSEC_SPLOCK9_SPLOCK310			(0x1u<<22)
#define	BSEC_SPLOCK9_SPLOCK309			(0x1u<<21)
#define	BSEC_SPLOCK9_SPLOCK308			(0x1u<<20)
#define	BSEC_SPLOCK9_SPLOCK307			(0x1u<<19)
#define	BSEC_SPLOCK9_SPLOCK306			(0x1u<<18)
#define	BSEC_SPLOCK9_SPLOCK305			(0x1u<<17)
#define	BSEC_SPLOCK9_SPLOCK304			(0x1u<<16)
#define	BSEC_SPLOCK9_SPLOCK303			(0x1u<<15)
#define	BSEC_SPLOCK9_SPLOCK302			(0x1u<<14)
#define	BSEC_SPLOCK9_SPLOCK301			(0x1u<<13)
#define	BSEC_SPLOCK9_SPLOCK300			(0x1u<<12)
#define	BSEC_SPLOCK9_SPLOCK299			(0x1u<<11)
#define	BSEC_SPLOCK9_SPLOCK298			(0x1u<<10)
#define	BSEC_SPLOCK9_SPLOCK297			(0x1u<<9)
#define	BSEC_SPLOCK9_SPLOCK296			(0x1u<<8)
#define	BSEC_SPLOCK9_SPLOCK295			(0x1u<<7)
#define	BSEC_SPLOCK9_SPLOCK294			(0x1u<<6)
#define	BSEC_SPLOCK9_SPLOCK293			(0x1u<<5)
#define	BSEC_SPLOCK9_SPLOCK292			(0x1u<<4)
#define	BSEC_SPLOCK9_SPLOCK291			(0x1u<<3)
#define	BSEC_SPLOCK9_SPLOCK290			(0x1u<<2)
#define	BSEC_SPLOCK9_SPLOCK289			(0x1u<<1)
#define	BSEC_SPLOCK9_SPLOCK288			(0x1u<<0)

#define	BSEC_SPLOCK9_SPLOCK319_B_0X0	(0x0u<<31)
#define	BSEC_SPLOCK9_SPLOCK319_B_0X1	(0x1u<<31)
#define	BSEC_SPLOCK9_SPLOCK318_B_0X0	(0x0u<<30)
#define	BSEC_SPLOCK9_SPLOCK318_B_0X1	(0x1u<<30)
#define	BSEC_SPLOCK9_SPLOCK317_B_0X0	(0x0u<<29)
#define	BSEC_SPLOCK9_SPLOCK317_B_0X1	(0x1u<<29)
#define	BSEC_SPLOCK9_SPLOCK316_B_0X0	(0x0u<<28)
#define	BSEC_SPLOCK9_SPLOCK316_B_0X1	(0x1u<<28)
#define	BSEC_SPLOCK9_SPLOCK315_B_0X0	(0x0u<<27)
#define	BSEC_SPLOCK9_SPLOCK315_B_0X1	(0x1u<<27)
#define	BSEC_SPLOCK9_SPLOCK314_B_0X0	(0x0u<<26)
#define	BSEC_SPLOCK9_SPLOCK314_B_0X1	(0x1u<<26)
#define	BSEC_SPLOCK9_SPLOCK313_B_0X0	(0x0u<<25)
#define	BSEC_SPLOCK9_SPLOCK313_B_0X1	(0x1u<<25)
#define	BSEC_SPLOCK9_SPLOCK312_B_0X0	(0x0u<<24)
#define	BSEC_SPLOCK9_SPLOCK312_B_0X1	(0x1u<<24)
#define	BSEC_SPLOCK9_SPLOCK311_B_0X0	(0x0u<<23)
#define	BSEC_SPLOCK9_SPLOCK311_B_0X1	(0x1u<<23)
#define	BSEC_SPLOCK9_SPLOCK310_B_0X0	(0x0u<<22)
#define	BSEC_SPLOCK9_SPLOCK310_B_0X1	(0x1u<<22)
#define	BSEC_SPLOCK9_SPLOCK309_B_0X0	(0x0u<<21)
#define	BSEC_SPLOCK9_SPLOCK309_B_0X1	(0x1u<<21)
#define	BSEC_SPLOCK9_SPLOCK308_B_0X0	(0x0u<<20)
#define	BSEC_SPLOCK9_SPLOCK308_B_0X1	(0x1u<<20)
#define	BSEC_SPLOCK9_SPLOCK307_B_0X0	(0x0u<<19)
#define	BSEC_SPLOCK9_SPLOCK307_B_0X1	(0x1u<<19)
#define	BSEC_SPLOCK9_SPLOCK306_B_0X0	(0x0u<<18)
#define	BSEC_SPLOCK9_SPLOCK306_B_0X1	(0x1u<<18)
#define	BSEC_SPLOCK9_SPLOCK305_B_0X0	(0x0u<<17)
#define	BSEC_SPLOCK9_SPLOCK305_B_0X1	(0x1u<<17)
#define	BSEC_SPLOCK9_SPLOCK304_B_0X0	(0x0u<<16)
#define	BSEC_SPLOCK9_SPLOCK304_B_0X1	(0x1u<<16)
#define	BSEC_SPLOCK9_SPLOCK303_B_0X0	(0x0u<<15)
#define	BSEC_SPLOCK9_SPLOCK303_B_0X1	(0x1u<<15)
#define	BSEC_SPLOCK9_SPLOCK302_B_0X0	(0x0u<<14)
#define	BSEC_SPLOCK9_SPLOCK302_B_0X1	(0x1u<<14)
#define	BSEC_SPLOCK9_SPLOCK301_B_0X0	(0x0u<<13)
#define	BSEC_SPLOCK9_SPLOCK301_B_0X1	(0x1u<<13)
#define	BSEC_SPLOCK9_SPLOCK300_B_0X0	(0x0u<<12)
#define	BSEC_SPLOCK9_SPLOCK300_B_0X1	(0x1u<<12)
#define	BSEC_SPLOCK9_SPLOCK299_B_0X0	(0x0u<<11)
#define	BSEC_SPLOCK9_SPLOCK299_B_0X1	(0x1u<<11)
#define	BSEC_SPLOCK9_SPLOCK298_B_0X0	(0x0u<<10)
#define	BSEC_SPLOCK9_SPLOCK298_B_0X1	(0x1u<<10)
#define	BSEC_SPLOCK9_SPLOCK297_B_0X0	(0x0u<<9)
#define	BSEC_SPLOCK9_SPLOCK297_B_0X1	(0x1u<<9)
#define	BSEC_SPLOCK9_SPLOCK296_B_0X0	(0x0u<<8)
#define	BSEC_SPLOCK9_SPLOCK296_B_0X1	(0x1u<<8)
#define	BSEC_SPLOCK9_SPLOCK295_B_0X0	(0x0u<<7)
#define	BSEC_SPLOCK9_SPLOCK295_B_0X1	(0x1u<<7)
#define	BSEC_SPLOCK9_SPLOCK294_B_0X0	(0x0u<<6)
#define	BSEC_SPLOCK9_SPLOCK294_B_0X1	(0x1u<<6)
#define	BSEC_SPLOCK9_SPLOCK293_B_0X0	(0x0u<<5)
#define	BSEC_SPLOCK9_SPLOCK293_B_0X1	(0x1u<<5)
#define	BSEC_SPLOCK9_SPLOCK292_B_0X0	(0x0u<<4)
#define	BSEC_SPLOCK9_SPLOCK292_B_0X1	(0x1u<<4)
#define	BSEC_SPLOCK9_SPLOCK291_B_0X0	(0x0u<<3)
#define	BSEC_SPLOCK9_SPLOCK291_B_0X1	(0x1u<<3)
#define	BSEC_SPLOCK9_SPLOCK290_B_0X0	(0x0u<<2)
#define	BSEC_SPLOCK9_SPLOCK290_B_0X1	(0x1u<<2)
#define	BSEC_SPLOCK9_SPLOCK289_B_0X0	(0x0u<<1)
#define	BSEC_SPLOCK9_SPLOCK289_B_0X1	(0x1u<<1)
#define	BSEC_SPLOCK9_SPLOCK288_B_0X0	(0x0u<<0)
#define	BSEC_SPLOCK9_SPLOCK288_B_0X1	(0x1u<<0)

// SPLOCK10 Configuration

#define	BSEC_SPLOCK10_SPLOCK351			(0x1u<<31)
#define	BSEC_SPLOCK10_SPLOCK350			(0x1u<<30)
#define	BSEC_SPLOCK10_SPLOCK349			(0x1u<<29)
#define	BSEC_SPLOCK10_SPLOCK348			(0x1u<<28)
#define	BSEC_SPLOCK10_SPLOCK347			(0x1u<<27)
#define	BSEC_SPLOCK10_SPLOCK346			(0x1u<<26)
#define	BSEC_SPLOCK10_SPLOCK345			(0x1u<<25)
#define	BSEC_SPLOCK10_SPLOCK344			(0x1u<<24)
#define	BSEC_SPLOCK10_SPLOCK343			(0x1u<<23)
#define	BSEC_SPLOCK10_SPLOCK342			(0x1u<<22)
#define	BSEC_SPLOCK10_SPLOCK341			(0x1u<<21)
#define	BSEC_SPLOCK10_SPLOCK340			(0x1u<<20)
#define	BSEC_SPLOCK10_SPLOCK339			(0x1u<<19)
#define	BSEC_SPLOCK10_SPLOCK338			(0x1u<<18)
#define	BSEC_SPLOCK10_SPLOCK337			(0x1u<<17)
#define	BSEC_SPLOCK10_SPLOCK336			(0x1u<<16)
#define	BSEC_SPLOCK10_SPLOCK335			(0x1u<<15)
#define	BSEC_SPLOCK10_SPLOCK334			(0x1u<<14)
#define	BSEC_SPLOCK10_SPLOCK333			(0x1u<<13)
#define	BSEC_SPLOCK10_SPLOCK332			(0x1u<<12)
#define	BSEC_SPLOCK10_SPLOCK331			(0x1u<<11)
#define	BSEC_SPLOCK10_SPLOCK330			(0x1u<<10)
#define	BSEC_SPLOCK10_SPLOCK329			(0x1u<<9)
#define	BSEC_SPLOCK10_SPLOCK328			(0x1u<<8)
#define	BSEC_SPLOCK10_SPLOCK327			(0x1u<<7)
#define	BSEC_SPLOCK10_SPLOCK326			(0x1u<<6)
#define	BSEC_SPLOCK10_SPLOCK325			(0x1u<<5)
#define	BSEC_SPLOCK10_SPLOCK324			(0x1u<<4)
#define	BSEC_SPLOCK10_SPLOCK323			(0x1u<<3)
#define	BSEC_SPLOCK10_SPLOCK322			(0x1u<<2)
#define	BSEC_SPLOCK10_SPLOCK321			(0x1u<<1)
#define	BSEC_SPLOCK10_SPLOCK320			(0x1u<<0)

#define	BSEC_SPLOCK10_SPLOCK351_B_0X0	(0x0u<<31)
#define	BSEC_SPLOCK10_SPLOCK351_B_0X1	(0x1u<<31)
#define	BSEC_SPLOCK10_SPLOCK350_B_0X0	(0x0u<<30)
#define	BSEC_SPLOCK10_SPLOCK350_B_0X1	(0x1u<<30)
#define	BSEC_SPLOCK10_SPLOCK349_B_0X0	(0x0u<<29)
#define	BSEC_SPLOCK10_SPLOCK349_B_0X1	(0x1u<<29)
#define	BSEC_SPLOCK10_SPLOCK348_B_0X0	(0x0u<<28)
#define	BSEC_SPLOCK10_SPLOCK348_B_0X1	(0x1u<<28)
#define	BSEC_SPLOCK10_SPLOCK347_B_0X0	(0x0u<<27)
#define	BSEC_SPLOCK10_SPLOCK347_B_0X1	(0x1u<<27)
#define	BSEC_SPLOCK10_SPLOCK346_B_0X0	(0x0u<<26)
#define	BSEC_SPLOCK10_SPLOCK346_B_0X1	(0x1u<<26)
#define	BSEC_SPLOCK10_SPLOCK345_B_0X0	(0x0u<<25)
#define	BSEC_SPLOCK10_SPLOCK345_B_0X1	(0x1u<<25)
#define	BSEC_SPLOCK10_SPLOCK344_B_0X0	(0x0u<<24)
#define	BSEC_SPLOCK10_SPLOCK344_B_0X1	(0x1u<<24)
#define	BSEC_SPLOCK10_SPLOCK343_B_0X0	(0x0u<<23)
#define	BSEC_SPLOCK10_SPLOCK343_B_0X1	(0x1u<<23)
#define	BSEC_SPLOCK10_SPLOCK342_B_0X0	(0x0u<<22)
#define	BSEC_SPLOCK10_SPLOCK342_B_0X1	(0x1u<<22)
#define	BSEC_SPLOCK10_SPLOCK341_B_0X0	(0x0u<<21)
#define	BSEC_SPLOCK10_SPLOCK341_B_0X1	(0x1u<<21)
#define	BSEC_SPLOCK10_SPLOCK340_B_0X0	(0x0u<<20)
#define	BSEC_SPLOCK10_SPLOCK340_B_0X1	(0x1u<<20)
#define	BSEC_SPLOCK10_SPLOCK339_B_0X0	(0x0u<<19)
#define	BSEC_SPLOCK10_SPLOCK339_B_0X1	(0x1u<<19)
#define	BSEC_SPLOCK10_SPLOCK338_B_0X0	(0x0u<<18)
#define	BSEC_SPLOCK10_SPLOCK338_B_0X1	(0x1u<<18)
#define	BSEC_SPLOCK10_SPLOCK337_B_0X0	(0x0u<<17)
#define	BSEC_SPLOCK10_SPLOCK337_B_0X1	(0x1u<<17)
#define	BSEC_SPLOCK10_SPLOCK336_B_0X0	(0x0u<<16)
#define	BSEC_SPLOCK10_SPLOCK336_B_0X1	(0x1u<<16)
#define	BSEC_SPLOCK10_SPLOCK335_B_0X0	(0x0u<<15)
#define	BSEC_SPLOCK10_SPLOCK335_B_0X1	(0x1u<<15)
#define	BSEC_SPLOCK10_SPLOCK334_B_0X0	(0x0u<<14)
#define	BSEC_SPLOCK10_SPLOCK334_B_0X1	(0x1u<<14)
#define	BSEC_SPLOCK10_SPLOCK333_B_0X0	(0x0u<<13)
#define	BSEC_SPLOCK10_SPLOCK333_B_0X1	(0x1u<<13)
#define	BSEC_SPLOCK10_SPLOCK332_B_0X0	(0x0u<<12)
#define	BSEC_SPLOCK10_SPLOCK332_B_0X1	(0x1u<<12)
#define	BSEC_SPLOCK10_SPLOCK331_B_0X0	(0x0u<<11)
#define	BSEC_SPLOCK10_SPLOCK331_B_0X1	(0x1u<<11)
#define	BSEC_SPLOCK10_SPLOCK330_B_0X0	(0x0u<<10)
#define	BSEC_SPLOCK10_SPLOCK330_B_0X1	(0x1u<<10)
#define	BSEC_SPLOCK10_SPLOCK329_B_0X0	(0x0u<<9)
#define	BSEC_SPLOCK10_SPLOCK329_B_0X1	(0x1u<<9)
#define	BSEC_SPLOCK10_SPLOCK328_B_0X0	(0x0u<<8)
#define	BSEC_SPLOCK10_SPLOCK328_B_0X1	(0x1u<<8)
#define	BSEC_SPLOCK10_SPLOCK327_B_0X0	(0x0u<<7)
#define	BSEC_SPLOCK10_SPLOCK327_B_0X1	(0x1u<<7)
#define	BSEC_SPLOCK10_SPLOCK326_B_0X0	(0x0u<<6)
#define	BSEC_SPLOCK10_SPLOCK326_B_0X1	(0x1u<<6)
#define	BSEC_SPLOCK10_SPLOCK325_B_0X0	(0x0u<<5)
#define	BSEC_SPLOCK10_SPLOCK325_B_0X1	(0x1u<<5)
#define	BSEC_SPLOCK10_SPLOCK324_B_0X0	(0x0u<<4)
#define	BSEC_SPLOCK10_SPLOCK324_B_0X1	(0x1u<<4)
#define	BSEC_SPLOCK10_SPLOCK323_B_0X0	(0x0u<<3)
#define	BSEC_SPLOCK10_SPLOCK323_B_0X1	(0x1u<<3)
#define	BSEC_SPLOCK10_SPLOCK322_B_0X0	(0x0u<<2)
#define	BSEC_SPLOCK10_SPLOCK322_B_0X1	(0x1u<<2)
#define	BSEC_SPLOCK10_SPLOCK321_B_0X0	(0x0u<<1)
#define	BSEC_SPLOCK10_SPLOCK321_B_0X1	(0x1u<<1)
#define	BSEC_SPLOCK10_SPLOCK320_B_0X0	(0x0u<<0)
#define	BSEC_SPLOCK10_SPLOCK320_B_0X1	(0x1u<<0)

// SPLOCK11 Configuration

#define	BSEC_SPLOCK11_SPLOCK383			(0x1u<<31)
#define	BSEC_SPLOCK11_SPLOCK382			(0x1u<<30)
#define	BSEC_SPLOCK11_SPLOCK381			(0x1u<<29)
#define	BSEC_SPLOCK11_SPLOCK380			(0x1u<<28)
#define	BSEC_SPLOCK11_SPLOCK379			(0x1u<<27)
#define	BSEC_SPLOCK11_SPLOCK378			(0x1u<<26)
#define	BSEC_SPLOCK11_SPLOCK377			(0x1u<<25)
#define	BSEC_SPLOCK11_SPLOCK376			(0x1u<<24)
#define	BSEC_SPLOCK11_SPLOCK375			(0x1u<<23)
#define	BSEC_SPLOCK11_SPLOCK374			(0x1u<<22)
#define	BSEC_SPLOCK11_SPLOCK373			(0x1u<<21)
#define	BSEC_SPLOCK11_SPLOCK372			(0x1u<<20)
#define	BSEC_SPLOCK11_SPLOCK371			(0x1u<<19)
#define	BSEC_SPLOCK11_SPLOCK370			(0x1u<<18)
#define	BSEC_SPLOCK11_SPLOCK369			(0x1u<<17)
#define	BSEC_SPLOCK11_SPLOCK368			(0x1u<<16)
#define	BSEC_SPLOCK11_SPLOCK367			(0x1u<<15)
#define	BSEC_SPLOCK11_SPLOCK366			(0x1u<<14)
#define	BSEC_SPLOCK11_SPLOCK365			(0x1u<<13)
#define	BSEC_SPLOCK11_SPLOCK364			(0x1u<<12)
#define	BSEC_SPLOCK11_SPLOCK363			(0x1u<<11)
#define	BSEC_SPLOCK11_SPLOCK362			(0x1u<<10)
#define	BSEC_SPLOCK11_SPLOCK361			(0x1u<<9)
#define	BSEC_SPLOCK11_SPLOCK360			(0x1u<<8)
#define	BSEC_SPLOCK11_SPLOCK359			(0x1u<<7)
#define	BSEC_SPLOCK11_SPLOCK358			(0x1u<<6)
#define	BSEC_SPLOCK11_SPLOCK357			(0x1u<<5)
#define	BSEC_SPLOCK11_SPLOCK356			(0x1u<<4)
#define	BSEC_SPLOCK11_SPLOCK355			(0x1u<<3)
#define	BSEC_SPLOCK11_SPLOCK354			(0x1u<<2)
#define	BSEC_SPLOCK11_SPLOCK353			(0x1u<<1)
#define	BSEC_SPLOCK11_SPLOCK352			(0x1u<<0)

#define	BSEC_SPLOCK11_SPLOCK383_B_0X0	(0x0u<<31)
#define	BSEC_SPLOCK11_SPLOCK383_B_0X1	(0x1u<<31)
#define	BSEC_SPLOCK11_SPLOCK382_B_0X0	(0x0u<<30)
#define	BSEC_SPLOCK11_SPLOCK382_B_0X1	(0x1u<<30)
#define	BSEC_SPLOCK11_SPLOCK381_B_0X0	(0x0u<<29)
#define	BSEC_SPLOCK11_SPLOCK381_B_0X1	(0x1u<<29)
#define	BSEC_SPLOCK11_SPLOCK380_B_0X0	(0x0u<<28)
#define	BSEC_SPLOCK11_SPLOCK380_B_0X1	(0x1u<<28)
#define	BSEC_SPLOCK11_SPLOCK379_B_0X0	(0x0u<<27)
#define	BSEC_SPLOCK11_SPLOCK379_B_0X1	(0x1u<<27)
#define	BSEC_SPLOCK11_SPLOCK378_B_0X0	(0x0u<<26)
#define	BSEC_SPLOCK11_SPLOCK378_B_0X1	(0x1u<<26)
#define	BSEC_SPLOCK11_SPLOCK377_B_0X0	(0x0u<<25)
#define	BSEC_SPLOCK11_SPLOCK377_B_0X1	(0x1u<<25)
#define	BSEC_SPLOCK11_SPLOCK376_B_0X0	(0x0u<<24)
#define	BSEC_SPLOCK11_SPLOCK376_B_0X1	(0x1u<<24)
#define	BSEC_SPLOCK11_SPLOCK375_B_0X0	(0x0u<<23)
#define	BSEC_SPLOCK11_SPLOCK375_B_0X1	(0x1u<<23)
#define	BSEC_SPLOCK11_SPLOCK374_B_0X0	(0x0u<<22)
#define	BSEC_SPLOCK11_SPLOCK374_B_0X1	(0x1u<<22)
#define	BSEC_SPLOCK11_SPLOCK373_B_0X0	(0x0u<<21)
#define	BSEC_SPLOCK11_SPLOCK373_B_0X1	(0x1u<<21)
#define	BSEC_SPLOCK11_SPLOCK372_B_0X0	(0x0u<<20)
#define	BSEC_SPLOCK11_SPLOCK372_B_0X1	(0x1u<<20)
#define	BSEC_SPLOCK11_SPLOCK371_B_0X0	(0x0u<<19)
#define	BSEC_SPLOCK11_SPLOCK371_B_0X1	(0x1u<<19)
#define	BSEC_SPLOCK11_SPLOCK370_B_0X0	(0x0u<<18)
#define	BSEC_SPLOCK11_SPLOCK370_B_0X1	(0x1u<<18)
#define	BSEC_SPLOCK11_SPLOCK369_B_0X0	(0x0u<<17)
#define	BSEC_SPLOCK11_SPLOCK369_B_0X1	(0x1u<<17)
#define	BSEC_SPLOCK11_SPLOCK368_B_0X0	(0x0u<<16)
#define	BSEC_SPLOCK11_SPLOCK368_B_0X1	(0x1u<<16)
#define	BSEC_SPLOCK11_SPLOCK367_B_0X0	(0x0u<<15)
#define	BSEC_SPLOCK11_SPLOCK367_B_0X1	(0x1u<<15)
#define	BSEC_SPLOCK11_SPLOCK366_B_0X0	(0x0u<<14)
#define	BSEC_SPLOCK11_SPLOCK366_B_0X1	(0x1u<<14)
#define	BSEC_SPLOCK11_SPLOCK365_B_0X0	(0x0u<<13)
#define	BSEC_SPLOCK11_SPLOCK365_B_0X1	(0x1u<<13)
#define	BSEC_SPLOCK11_SPLOCK364_B_0X0	(0x0u<<12)
#define	BSEC_SPLOCK11_SPLOCK364_B_0X1	(0x1u<<12)
#define	BSEC_SPLOCK11_SPLOCK363_B_0X0	(0x0u<<11)
#define	BSEC_SPLOCK11_SPLOCK363_B_0X1	(0x1u<<11)
#define	BSEC_SPLOCK11_SPLOCK362_B_0X0	(0x0u<<10)
#define	BSEC_SPLOCK11_SPLOCK362_B_0X1	(0x1u<<10)
#define	BSEC_SPLOCK11_SPLOCK361_B_0X0	(0x0u<<9)
#define	BSEC_SPLOCK11_SPLOCK361_B_0X1	(0x1u<<9)
#define	BSEC_SPLOCK11_SPLOCK360_B_0X0	(0x0u<<8)
#define	BSEC_SPLOCK11_SPLOCK360_B_0X1	(0x1u<<8)
#define	BSEC_SPLOCK11_SPLOCK359_B_0X0	(0x0u<<7)
#define	BSEC_SPLOCK11_SPLOCK359_B_0X1	(0x1u<<7)
#define	BSEC_SPLOCK11_SPLOCK358_B_0X0	(0x0u<<6)
#define	BSEC_SPLOCK11_SPLOCK358_B_0X1	(0x1u<<6)
#define	BSEC_SPLOCK11_SPLOCK357_B_0X0	(0x0u<<5)
#define	BSEC_SPLOCK11_SPLOCK357_B_0X1	(0x1u<<5)
#define	BSEC_SPLOCK11_SPLOCK356_B_0X0	(0x0u<<4)
#define	BSEC_SPLOCK11_SPLOCK356_B_0X1	(0x1u<<4)
#define	BSEC_SPLOCK11_SPLOCK355_B_0X0	(0x0u<<3)
#define	BSEC_SPLOCK11_SPLOCK355_B_0X1	(0x1u<<3)
#define	BSEC_SPLOCK11_SPLOCK354_B_0X0	(0x0u<<2)
#define	BSEC_SPLOCK11_SPLOCK354_B_0X1	(0x1u<<2)
#define	BSEC_SPLOCK11_SPLOCK353_B_0X0	(0x0u<<1)
#define	BSEC_SPLOCK11_SPLOCK353_B_0X1	(0x1u<<1)
#define	BSEC_SPLOCK11_SPLOCK352_B_0X0	(0x0u<<0)
#define	BSEC_SPLOCK11_SPLOCK352_B_0X1	(0x1u<<0)

// SWLOCK0 Configuration

#define	BSEC_SWLOCK0_SWLOCK31			(0x1u<<31)
#define	BSEC_SWLOCK0_SWLOCK30			(0x1u<<30)
#define	BSEC_SWLOCK0_SWLOCK29			(0x1u<<29)
#define	BSEC_SWLOCK0_SWLOCK28			(0x1u<<28)
#define	BSEC_SWLOCK0_SWLOCK27			(0x1u<<27)
#define	BSEC_SWLOCK0_SWLOCK26			(0x1u<<26)
#define	BSEC_SWLOCK0_SWLOCK25			(0x1u<<25)
#define	BSEC_SWLOCK0_SWLOCK24			(0x1u<<24)
#define	BSEC_SWLOCK0_SWLOCK23			(0x1u<<23)
#define	BSEC_SWLOCK0_SWLOCK22			(0x1u<<22)
#define	BSEC_SWLOCK0_SWLOCK21			(0x1u<<21)
#define	BSEC_SWLOCK0_SWLOCK20			(0x1u<<20)
#define	BSEC_SWLOCK0_SWLOCK19			(0x1u<<19)
#define	BSEC_SWLOCK0_SWLOCK18			(0x1u<<18)
#define	BSEC_SWLOCK0_SWLOCK17			(0x1u<<17)
#define	BSEC_SWLOCK0_SWLOCK16			(0x1u<<16)
#define	BSEC_SWLOCK0_SWLOCK15			(0x1u<<15)
#define	BSEC_SWLOCK0_SWLOCK14			(0x1u<<14)
#define	BSEC_SWLOCK0_SWLOCK13			(0x1u<<13)
#define	BSEC_SWLOCK0_SWLOCK12			(0x1u<<12)
#define	BSEC_SWLOCK0_SWLOCK11			(0x1u<<11)
#define	BSEC_SWLOCK0_SWLOCK10			(0x1u<<10)
#define	BSEC_SWLOCK0_SWLOCK9			(0x1u<<9)
#define	BSEC_SWLOCK0_SWLOCK8			(0x1u<<8)
#define	BSEC_SWLOCK0_SWLOCK7			(0x1u<<7)
#define	BSEC_SWLOCK0_SWLOCK6			(0x1u<<6)
#define	BSEC_SWLOCK0_SWLOCK5			(0x1u<<5)
#define	BSEC_SWLOCK0_SWLOCK4			(0x1u<<4)
#define	BSEC_SWLOCK0_SWLOCK3			(0x1u<<3)
#define	BSEC_SWLOCK0_SWLOCK2			(0x1u<<2)
#define	BSEC_SWLOCK0_SWLOCK1			(0x1u<<1)
#define	BSEC_SWLOCK0_SWLOCK0			(0x1u<<0)

#define	BSEC_SWLOCK0_SWLOCK31_B_0X0		(0x0u<<31)
#define	BSEC_SWLOCK0_SWLOCK31_B_0X1		(0x1u<<31)
#define	BSEC_SWLOCK0_SWLOCK30_B_0X0		(0x0u<<30)
#define	BSEC_SWLOCK0_SWLOCK30_B_0X1		(0x1u<<30)
#define	BSEC_SWLOCK0_SWLOCK29_B_0X0		(0x0u<<29)
#define	BSEC_SWLOCK0_SWLOCK29_B_0X1		(0x1u<<29)
#define	BSEC_SWLOCK0_SWLOCK28_B_0X0		(0x0u<<28)
#define	BSEC_SWLOCK0_SWLOCK28_B_0X1		(0x1u<<28)
#define	BSEC_SWLOCK0_SWLOCK27_B_0X0		(0x0u<<27)
#define	BSEC_SWLOCK0_SWLOCK27_B_0X1		(0x1u<<27)
#define	BSEC_SWLOCK0_SWLOCK26_B_0X0		(0x0u<<26)
#define	BSEC_SWLOCK0_SWLOCK26_B_0X1		(0x1u<<26)
#define	BSEC_SWLOCK0_SWLOCK25_B_0X0		(0x0u<<25)
#define	BSEC_SWLOCK0_SWLOCK25_B_0X1		(0x1u<<25)
#define	BSEC_SWLOCK0_SWLOCK24_B_0X0		(0x0u<<24)
#define	BSEC_SWLOCK0_SWLOCK24_B_0X1		(0x1u<<24)
#define	BSEC_SWLOCK0_SWLOCK23_B_0X0		(0x0u<<23)
#define	BSEC_SWLOCK0_SWLOCK23_B_0X1		(0x1u<<23)
#define	BSEC_SWLOCK0_SWLOCK22_B_0X0		(0x0u<<22)
#define	BSEC_SWLOCK0_SWLOCK22_B_0X1		(0x1u<<22)
#define	BSEC_SWLOCK0_SWLOCK21_B_0X0		(0x0u<<21)
#define	BSEC_SWLOCK0_SWLOCK21_B_0X1		(0x1u<<21)
#define	BSEC_SWLOCK0_SWLOCK20_B_0X0		(0x0u<<20)
#define	BSEC_SWLOCK0_SWLOCK20_B_0X1		(0x1u<<20)
#define	BSEC_SWLOCK0_SWLOCK19_B_0X0		(0x0u<<19)
#define	BSEC_SWLOCK0_SWLOCK19_B_0X1		(0x1u<<19)
#define	BSEC_SWLOCK0_SWLOCK18_B_0X0		(0x0u<<18)
#define	BSEC_SWLOCK0_SWLOCK18_B_0X1		(0x1u<<18)
#define	BSEC_SWLOCK0_SWLOCK17_B_0X0		(0x0u<<17)
#define	BSEC_SWLOCK0_SWLOCK17_B_0X1		(0x1u<<17)
#define	BSEC_SWLOCK0_SWLOCK16_B_0X0		(0x0u<<16)
#define	BSEC_SWLOCK0_SWLOCK16_B_0X1		(0x1u<<16)
#define	BSEC_SWLOCK0_SWLOCK15_B_0X0		(0x0u<<15)
#define	BSEC_SWLOCK0_SWLOCK15_B_0X1		(0x1u<<15)
#define	BSEC_SWLOCK0_SWLOCK14_B_0X0		(0x0u<<14)
#define	BSEC_SWLOCK0_SWLOCK14_B_0X1		(0x1u<<14)
#define	BSEC_SWLOCK0_SWLOCK13_B_0X0		(0x0u<<13)
#define	BSEC_SWLOCK0_SWLOCK13_B_0X1		(0x1u<<13)
#define	BSEC_SWLOCK0_SWLOCK12_B_0X0		(0x0u<<12)
#define	BSEC_SWLOCK0_SWLOCK12_B_0X1		(0x1u<<12)
#define	BSEC_SWLOCK0_SWLOCK11_B_0X0		(0x0u<<11)
#define	BSEC_SWLOCK0_SWLOCK11_B_0X1		(0x1u<<11)
#define	BSEC_SWLOCK0_SWLOCK10_B_0X0		(0x0u<<10)
#define	BSEC_SWLOCK0_SWLOCK10_B_0X1		(0x1u<<10)
#define	BSEC_SWLOCK0_SWLOCK9_B_0X0		(0x0u<<9)
#define	BSEC_SWLOCK0_SWLOCK9_B_0X1		(0x1u<<9)
#define	BSEC_SWLOCK0_SWLOCK8_B_0X0		(0x0u<<8)
#define	BSEC_SWLOCK0_SWLOCK8_B_0X1		(0x1u<<8)
#define	BSEC_SWLOCK0_SWLOCK7_B_0X0		(0x0u<<7)
#define	BSEC_SWLOCK0_SWLOCK7_B_0X1		(0x1u<<7)
#define	BSEC_SWLOCK0_SWLOCK6_B_0X0		(0x0u<<6)
#define	BSEC_SWLOCK0_SWLOCK6_B_0X1		(0x1u<<6)
#define	BSEC_SWLOCK0_SWLOCK5_B_0X0		(0x0u<<5)
#define	BSEC_SWLOCK0_SWLOCK5_B_0X1		(0x1u<<5)
#define	BSEC_SWLOCK0_SWLOCK4_B_0X0		(0x0u<<4)
#define	BSEC_SWLOCK0_SWLOCK4_B_0X1		(0x1u<<4)
#define	BSEC_SWLOCK0_SWLOCK3_B_0X0		(0x0u<<3)
#define	BSEC_SWLOCK0_SWLOCK3_B_0X1		(0x1u<<3)
#define	BSEC_SWLOCK0_SWLOCK2_B_0X0		(0x0u<<2)
#define	BSEC_SWLOCK0_SWLOCK2_B_0X1		(0x1u<<2)
#define	BSEC_SWLOCK0_SWLOCK1_B_0X0		(0x0u<<1)
#define	BSEC_SWLOCK0_SWLOCK1_B_0X1		(0x1u<<1)
#define	BSEC_SWLOCK0_SWLOCK0_B_0X0		(0x0u<<0)
#define	BSEC_SWLOCK0_SWLOCK0_B_0X1		(0x1u<<0)

// SWLOCK1 Configuration

#define	BSEC_SWLOCK1_SWLOCK63			(0x1u<<31)
#define	BSEC_SWLOCK1_SWLOCK62			(0x1u<<30)
#define	BSEC_SWLOCK1_SWLOCK61			(0x1u<<29)
#define	BSEC_SWLOCK1_SWLOCK60			(0x1u<<28)
#define	BSEC_SWLOCK1_SWLOCK59			(0x1u<<27)
#define	BSEC_SWLOCK1_SWLOCK58			(0x1u<<26)
#define	BSEC_SWLOCK1_SWLOCK57			(0x1u<<25)
#define	BSEC_SWLOCK1_SWLOCK56			(0x1u<<24)
#define	BSEC_SWLOCK1_SWLOCK55			(0x1u<<23)
#define	BSEC_SWLOCK1_SWLOCK54			(0x1u<<22)
#define	BSEC_SWLOCK1_SWLOCK53			(0x1u<<21)
#define	BSEC_SWLOCK1_SWLOCK52			(0x1u<<20)
#define	BSEC_SWLOCK1_SWLOCK51			(0x1u<<19)
#define	BSEC_SWLOCK1_SWLOCK50			(0x1u<<18)
#define	BSEC_SWLOCK1_SWLOCK49			(0x1u<<17)
#define	BSEC_SWLOCK1_SWLOCK48			(0x1u<<16)
#define	BSEC_SWLOCK1_SWLOCK47			(0x1u<<15)
#define	BSEC_SWLOCK1_SWLOCK46			(0x1u<<14)
#define	BSEC_SWLOCK1_SWLOCK45			(0x1u<<13)
#define	BSEC_SWLOCK1_SWLOCK44			(0x1u<<12)
#define	BSEC_SWLOCK1_SWLOCK43			(0x1u<<11)
#define	BSEC_SWLOCK1_SWLOCK42			(0x1u<<10)
#define	BSEC_SWLOCK1_SWLOCK41			(0x1u<<9)
#define	BSEC_SWLOCK1_SWLOCK40			(0x1u<<8)
#define	BSEC_SWLOCK1_SWLOCK39			(0x1u<<7)
#define	BSEC_SWLOCK1_SWLOCK38			(0x1u<<6)
#define	BSEC_SWLOCK1_SWLOCK37			(0x1u<<5)
#define	BSEC_SWLOCK1_SWLOCK36			(0x1u<<4)
#define	BSEC_SWLOCK1_SWLOCK35			(0x1u<<3)
#define	BSEC_SWLOCK1_SWLOCK34			(0x1u<<2)
#define	BSEC_SWLOCK1_SWLOCK33			(0x1u<<1)
#define	BSEC_SWLOCK1_SWLOCK32			(0x1u<<0)

#define	BSEC_SWLOCK1_SWLOCK63_B_0X0		(0x0u<<31)
#define	BSEC_SWLOCK1_SWLOCK63_B_0X1		(0x1u<<31)
#define	BSEC_SWLOCK1_SWLOCK62_B_0X0		(0x0u<<30)
#define	BSEC_SWLOCK1_SWLOCK62_B_0X1		(0x1u<<30)
#define	BSEC_SWLOCK1_SWLOCK61_B_0X0		(0x0u<<29)
#define	BSEC_SWLOCK1_SWLOCK61_B_0X1		(0x1u<<29)
#define	BSEC_SWLOCK1_SWLOCK60_B_0X0		(0x0u<<28)
#define	BSEC_SWLOCK1_SWLOCK60_B_0X1		(0x1u<<28)
#define	BSEC_SWLOCK1_SWLOCK59_B_0X0		(0x0u<<27)
#define	BSEC_SWLOCK1_SWLOCK59_B_0X1		(0x1u<<27)
#define	BSEC_SWLOCK1_SWLOCK58_B_0X0		(0x0u<<26)
#define	BSEC_SWLOCK1_SWLOCK58_B_0X1		(0x1u<<26)
#define	BSEC_SWLOCK1_SWLOCK57_B_0X0		(0x0u<<25)
#define	BSEC_SWLOCK1_SWLOCK57_B_0X1		(0x1u<<25)
#define	BSEC_SWLOCK1_SWLOCK56_B_0X0		(0x0u<<24)
#define	BSEC_SWLOCK1_SWLOCK56_B_0X1		(0x1u<<24)
#define	BSEC_SWLOCK1_SWLOCK55_B_0X0		(0x0u<<23)
#define	BSEC_SWLOCK1_SWLOCK55_B_0X1		(0x1u<<23)
#define	BSEC_SWLOCK1_SWLOCK54_B_0X0		(0x0u<<22)
#define	BSEC_SWLOCK1_SWLOCK54_B_0X1		(0x1u<<22)
#define	BSEC_SWLOCK1_SWLOCK53_B_0X0		(0x0u<<21)
#define	BSEC_SWLOCK1_SWLOCK53_B_0X1		(0x1u<<21)
#define	BSEC_SWLOCK1_SWLOCK52_B_0X0		(0x0u<<20)
#define	BSEC_SWLOCK1_SWLOCK52_B_0X1		(0x1u<<20)
#define	BSEC_SWLOCK1_SWLOCK51_B_0X0		(0x0u<<19)
#define	BSEC_SWLOCK1_SWLOCK51_B_0X1		(0x1u<<19)
#define	BSEC_SWLOCK1_SWLOCK50_B_0X0		(0x0u<<18)
#define	BSEC_SWLOCK1_SWLOCK50_B_0X1		(0x1u<<18)
#define	BSEC_SWLOCK1_SWLOCK49_B_0X0		(0x0u<<17)
#define	BSEC_SWLOCK1_SWLOCK49_B_0X1		(0x1u<<17)
#define	BSEC_SWLOCK1_SWLOCK48_B_0X0		(0x0u<<16)
#define	BSEC_SWLOCK1_SWLOCK48_B_0X1		(0x1u<<16)
#define	BSEC_SWLOCK1_SWLOCK47_B_0X0		(0x0u<<15)
#define	BSEC_SWLOCK1_SWLOCK47_B_0X1		(0x1u<<15)
#define	BSEC_SWLOCK1_SWLOCK46_B_0X0		(0x0u<<14)
#define	BSEC_SWLOCK1_SWLOCK46_B_0X1		(0x1u<<14)
#define	BSEC_SWLOCK1_SWLOCK45_B_0X0		(0x0u<<13)
#define	BSEC_SWLOCK1_SWLOCK45_B_0X1		(0x1u<<13)
#define	BSEC_SWLOCK1_SWLOCK44_B_0X0		(0x0u<<12)
#define	BSEC_SWLOCK1_SWLOCK44_B_0X1		(0x1u<<12)
#define	BSEC_SWLOCK1_SWLOCK43_B_0X0		(0x0u<<11)
#define	BSEC_SWLOCK1_SWLOCK43_B_0X1		(0x1u<<11)
#define	BSEC_SWLOCK1_SWLOCK42_B_0X0		(0x0u<<10)
#define	BSEC_SWLOCK1_SWLOCK42_B_0X1		(0x1u<<10)
#define	BSEC_SWLOCK1_SWLOCK41_B_0X0		(0x0u<<9)
#define	BSEC_SWLOCK1_SWLOCK41_B_0X1		(0x1u<<9)
#define	BSEC_SWLOCK1_SWLOCK40_B_0X0		(0x0u<<8)
#define	BSEC_SWLOCK1_SWLOCK40_B_0X1		(0x1u<<8)
#define	BSEC_SWLOCK1_SWLOCK39_B_0X0		(0x0u<<7)
#define	BSEC_SWLOCK1_SWLOCK39_B_0X1		(0x1u<<7)
#define	BSEC_SWLOCK1_SWLOCK38_B_0X0		(0x0u<<6)
#define	BSEC_SWLOCK1_SWLOCK38_B_0X1		(0x1u<<6)
#define	BSEC_SWLOCK1_SWLOCK37_B_0X0		(0x0u<<5)
#define	BSEC_SWLOCK1_SWLOCK37_B_0X1		(0x1u<<5)
#define	BSEC_SWLOCK1_SWLOCK36_B_0X0		(0x0u<<4)
#define	BSEC_SWLOCK1_SWLOCK36_B_0X1		(0x1u<<4)
#define	BSEC_SWLOCK1_SWLOCK35_B_0X0		(0x0u<<3)
#define	BSEC_SWLOCK1_SWLOCK35_B_0X1		(0x1u<<3)
#define	BSEC_SWLOCK1_SWLOCK34_B_0X0		(0x0u<<2)
#define	BSEC_SWLOCK1_SWLOCK34_B_0X1		(0x1u<<2)
#define	BSEC_SWLOCK1_SWLOCK33_B_0X0		(0x0u<<1)
#define	BSEC_SWLOCK1_SWLOCK33_B_0X1		(0x1u<<1)
#define	BSEC_SWLOCK1_SWLOCK32_B_0X0		(0x0u<<0)
#define	BSEC_SWLOCK1_SWLOCK32_B_0X1		(0x1u<<0)

// SWLOCK2 Configuration

#define	BSEC_SWLOCK2_SWLOCK95			(0x1u<<31)
#define	BSEC_SWLOCK2_SWLOCK94			(0x1u<<30)
#define	BSEC_SWLOCK2_SWLOCK93			(0x1u<<29)
#define	BSEC_SWLOCK2_SWLOCK92			(0x1u<<28)
#define	BSEC_SWLOCK2_SWLOCK91			(0x1u<<27)
#define	BSEC_SWLOCK2_SWLOCK90			(0x1u<<26)
#define	BSEC_SWLOCK2_SWLOCK89			(0x1u<<25)
#define	BSEC_SWLOCK2_SWLOCK88			(0x1u<<24)
#define	BSEC_SWLOCK2_SWLOCK87			(0x1u<<23)
#define	BSEC_SWLOCK2_SWLOCK86			(0x1u<<22)
#define	BSEC_SWLOCK2_SWLOCK85			(0x1u<<21)
#define	BSEC_SWLOCK2_SWLOCK84			(0x1u<<20)
#define	BSEC_SWLOCK2_SWLOCK83			(0x1u<<19)
#define	BSEC_SWLOCK2_SWLOCK82			(0x1u<<18)
#define	BSEC_SWLOCK2_SWLOCK81			(0x1u<<17)
#define	BSEC_SWLOCK2_SWLOCK80			(0x1u<<16)
#define	BSEC_SWLOCK2_SWLOCK79			(0x1u<<15)
#define	BSEC_SWLOCK2_SWLOCK78			(0x1u<<14)
#define	BSEC_SWLOCK2_SWLOCK77			(0x1u<<13)
#define	BSEC_SWLOCK2_SWLOCK76			(0x1u<<12)
#define	BSEC_SWLOCK2_SWLOCK75			(0x1u<<11)
#define	BSEC_SWLOCK2_SWLOCK74			(0x1u<<10)
#define	BSEC_SWLOCK2_SWLOCK73			(0x1u<<9)
#define	BSEC_SWLOCK2_SWLOCK72			(0x1u<<8)
#define	BSEC_SWLOCK2_SWLOCK71			(0x1u<<7)
#define	BSEC_SWLOCK2_SWLOCK70			(0x1u<<6)
#define	BSEC_SWLOCK2_SWLOCK69			(0x1u<<5)
#define	BSEC_SWLOCK2_SWLOCK68			(0x1u<<4)
#define	BSEC_SWLOCK2_SWLOCK67			(0x1u<<3)
#define	BSEC_SWLOCK2_SWLOCK66			(0x1u<<2)
#define	BSEC_SWLOCK2_SWLOCK65			(0x1u<<1)
#define	BSEC_SWLOCK2_SWLOCK64			(0x1u<<0)

#define	BSEC_SWLOCK2_SWLOCK95_B_0X0		(0x0u<<31)
#define	BSEC_SWLOCK2_SWLOCK95_B_0X1		(0x1u<<31)
#define	BSEC_SWLOCK2_SWLOCK94_B_0X0		(0x0u<<30)
#define	BSEC_SWLOCK2_SWLOCK94_B_0X1		(0x1u<<30)
#define	BSEC_SWLOCK2_SWLOCK93_B_0X0		(0x0u<<29)
#define	BSEC_SWLOCK2_SWLOCK93_B_0X1		(0x1u<<29)
#define	BSEC_SWLOCK2_SWLOCK92_B_0X0		(0x0u<<28)
#define	BSEC_SWLOCK2_SWLOCK92_B_0X1		(0x1u<<28)
#define	BSEC_SWLOCK2_SWLOCK91_B_0X0		(0x0u<<27)
#define	BSEC_SWLOCK2_SWLOCK91_B_0X1		(0x1u<<27)
#define	BSEC_SWLOCK2_SWLOCK90_B_0X0		(0x0u<<26)
#define	BSEC_SWLOCK2_SWLOCK90_B_0X1		(0x1u<<26)
#define	BSEC_SWLOCK2_SWLOCK89_B_0X0		(0x0u<<25)
#define	BSEC_SWLOCK2_SWLOCK89_B_0X1		(0x1u<<25)
#define	BSEC_SWLOCK2_SWLOCK88_B_0X0		(0x0u<<24)
#define	BSEC_SWLOCK2_SWLOCK88_B_0X1		(0x1u<<24)
#define	BSEC_SWLOCK2_SWLOCK87_B_0X0		(0x0u<<23)
#define	BSEC_SWLOCK2_SWLOCK87_B_0X1		(0x1u<<23)
#define	BSEC_SWLOCK2_SWLOCK86_B_0X0		(0x0u<<22)
#define	BSEC_SWLOCK2_SWLOCK86_B_0X1		(0x1u<<22)
#define	BSEC_SWLOCK2_SWLOCK85_B_0X0		(0x0u<<21)
#define	BSEC_SWLOCK2_SWLOCK85_B_0X1		(0x1u<<21)
#define	BSEC_SWLOCK2_SWLOCK84_B_0X0		(0x0u<<20)
#define	BSEC_SWLOCK2_SWLOCK84_B_0X1		(0x1u<<20)
#define	BSEC_SWLOCK2_SWLOCK83_B_0X0		(0x0u<<19)
#define	BSEC_SWLOCK2_SWLOCK83_B_0X1		(0x1u<<19)
#define	BSEC_SWLOCK2_SWLOCK82_B_0X0		(0x0u<<18)
#define	BSEC_SWLOCK2_SWLOCK82_B_0X1		(0x1u<<18)
#define	BSEC_SWLOCK2_SWLOCK81_B_0X0		(0x0u<<17)
#define	BSEC_SWLOCK2_SWLOCK81_B_0X1		(0x1u<<17)
#define	BSEC_SWLOCK2_SWLOCK80_B_0X0		(0x0u<<16)
#define	BSEC_SWLOCK2_SWLOCK80_B_0X1		(0x1u<<16)
#define	BSEC_SWLOCK2_SWLOCK79_B_0X0		(0x0u<<15)
#define	BSEC_SWLOCK2_SWLOCK79_B_0X1		(0x1u<<15)
#define	BSEC_SWLOCK2_SWLOCK78_B_0X0		(0x0u<<14)
#define	BSEC_SWLOCK2_SWLOCK78_B_0X1		(0x1u<<14)
#define	BSEC_SWLOCK2_SWLOCK77_B_0X0		(0x0u<<13)
#define	BSEC_SWLOCK2_SWLOCK77_B_0X1		(0x1u<<13)
#define	BSEC_SWLOCK2_SWLOCK76_B_0X0		(0x0u<<12)
#define	BSEC_SWLOCK2_SWLOCK76_B_0X1		(0x1u<<12)
#define	BSEC_SWLOCK2_SWLOCK75_B_0X0		(0x0u<<11)
#define	BSEC_SWLOCK2_SWLOCK75_B_0X1		(0x1u<<11)
#define	BSEC_SWLOCK2_SWLOCK74_B_0X0		(0x0u<<10)
#define	BSEC_SWLOCK2_SWLOCK74_B_0X1		(0x1u<<10)
#define	BSEC_SWLOCK2_SWLOCK73_B_0X0		(0x0u<<9)
#define	BSEC_SWLOCK2_SWLOCK73_B_0X1		(0x1u<<9)
#define	BSEC_SWLOCK2_SWLOCK72_B_0X0		(0x0u<<8)
#define	BSEC_SWLOCK2_SWLOCK72_B_0X1		(0x1u<<8)
#define	BSEC_SWLOCK2_SWLOCK71_B_0X0		(0x0u<<7)
#define	BSEC_SWLOCK2_SWLOCK71_B_0X1		(0x1u<<7)
#define	BSEC_SWLOCK2_SWLOCK70_B_0X0		(0x0u<<6)
#define	BSEC_SWLOCK2_SWLOCK70_B_0X1		(0x1u<<6)
#define	BSEC_SWLOCK2_SWLOCK69_B_0X0		(0x0u<<5)
#define	BSEC_SWLOCK2_SWLOCK69_B_0X1		(0x1u<<5)
#define	BSEC_SWLOCK2_SWLOCK68_B_0X0		(0x0u<<4)
#define	BSEC_SWLOCK2_SWLOCK68_B_0X1		(0x1u<<4)
#define	BSEC_SWLOCK2_SWLOCK67_B_0X0		(0x0u<<3)
#define	BSEC_SWLOCK2_SWLOCK67_B_0X1		(0x1u<<3)
#define	BSEC_SWLOCK2_SWLOCK66_B_0X0		(0x0u<<2)
#define	BSEC_SWLOCK2_SWLOCK66_B_0X1		(0x1u<<2)
#define	BSEC_SWLOCK2_SWLOCK65_B_0X0		(0x0u<<1)
#define	BSEC_SWLOCK2_SWLOCK65_B_0X1		(0x1u<<1)
#define	BSEC_SWLOCK2_SWLOCK64_B_0X0		(0x0u<<0)
#define	BSEC_SWLOCK2_SWLOCK64_B_0X1		(0x1u<<0)

// SWLOCK3 Configuration

#define	BSEC_SWLOCK3_SWLOCK127			(0x1u<<31)
#define	BSEC_SWLOCK3_SWLOCK126			(0x1u<<30)
#define	BSEC_SWLOCK3_SWLOCK125			(0x1u<<29)
#define	BSEC_SWLOCK3_SWLOCK124			(0x1u<<28)
#define	BSEC_SWLOCK3_SWLOCK123			(0x1u<<27)
#define	BSEC_SWLOCK3_SWLOCK122			(0x1u<<26)
#define	BSEC_SWLOCK3_SWLOCK121			(0x1u<<25)
#define	BSEC_SWLOCK3_SWLOCK120			(0x1u<<24)
#define	BSEC_SWLOCK3_SWLOCK119			(0x1u<<23)
#define	BSEC_SWLOCK3_SWLOCK118			(0x1u<<22)
#define	BSEC_SWLOCK3_SWLOCK117			(0x1u<<21)
#define	BSEC_SWLOCK3_SWLOCK116			(0x1u<<20)
#define	BSEC_SWLOCK3_SWLOCK115			(0x1u<<19)
#define	BSEC_SWLOCK3_SWLOCK114			(0x1u<<18)
#define	BSEC_SWLOCK3_SWLOCK113			(0x1u<<17)
#define	BSEC_SWLOCK3_SWLOCK112			(0x1u<<16)
#define	BSEC_SWLOCK3_SWLOCK111			(0x1u<<15)
#define	BSEC_SWLOCK3_SWLOCK110			(0x1u<<14)
#define	BSEC_SWLOCK3_SWLOCK109			(0x1u<<13)
#define	BSEC_SWLOCK3_SWLOCK108			(0x1u<<12)
#define	BSEC_SWLOCK3_SWLOCK107			(0x1u<<11)
#define	BSEC_SWLOCK3_SWLOCK106			(0x1u<<10)
#define	BSEC_SWLOCK3_SWLOCK105			(0x1u<<9)
#define	BSEC_SWLOCK3_SWLOCK104			(0x1u<<8)
#define	BSEC_SWLOCK3_SWLOCK103			(0x1u<<7)
#define	BSEC_SWLOCK3_SWLOCK102			(0x1u<<6)
#define	BSEC_SWLOCK3_SWLOCK101			(0x1u<<5)
#define	BSEC_SWLOCK3_SWLOCK100			(0x1u<<4)
#define	BSEC_SWLOCK3_SWLOCK99			(0x1u<<3)
#define	BSEC_SWLOCK3_SWLOCK98			(0x1u<<2)
#define	BSEC_SWLOCK3_SWLOCK97			(0x1u<<1)
#define	BSEC_SWLOCK3_SWLOCK96			(0x1u<<0)

#define	BSEC_SWLOCK3_SWLOCK127_B_0X0	(0x0u<<31)
#define	BSEC_SWLOCK3_SWLOCK127_B_0X1	(0x1u<<31)
#define	BSEC_SWLOCK3_SWLOCK126_B_0X0	(0x0u<<30)
#define	BSEC_SWLOCK3_SWLOCK126_B_0X1	(0x1u<<30)
#define	BSEC_SWLOCK3_SWLOCK125_B_0X0	(0x0u<<29)
#define	BSEC_SWLOCK3_SWLOCK125_B_0X1	(0x1u<<29)
#define	BSEC_SWLOCK3_SWLOCK124_B_0X0	(0x0u<<28)
#define	BSEC_SWLOCK3_SWLOCK124_B_0X1	(0x1u<<28)
#define	BSEC_SWLOCK3_SWLOCK123_B_0X0	(0x0u<<27)
#define	BSEC_SWLOCK3_SWLOCK123_B_0X1	(0x1u<<27)
#define	BSEC_SWLOCK3_SWLOCK122_B_0X0	(0x0u<<26)
#define	BSEC_SWLOCK3_SWLOCK122_B_0X1	(0x1u<<26)
#define	BSEC_SWLOCK3_SWLOCK121_B_0X0	(0x0u<<25)
#define	BSEC_SWLOCK3_SWLOCK121_B_0X1	(0x1u<<25)
#define	BSEC_SWLOCK3_SWLOCK120_B_0X0	(0x0u<<24)
#define	BSEC_SWLOCK3_SWLOCK120_B_0X1	(0x1u<<24)
#define	BSEC_SWLOCK3_SWLOCK119_B_0X0	(0x0u<<23)
#define	BSEC_SWLOCK3_SWLOCK119_B_0X1	(0x1u<<23)
#define	BSEC_SWLOCK3_SWLOCK118_B_0X0	(0x0u<<22)
#define	BSEC_SWLOCK3_SWLOCK118_B_0X1	(0x1u<<22)
#define	BSEC_SWLOCK3_SWLOCK117_B_0X0	(0x0u<<21)
#define	BSEC_SWLOCK3_SWLOCK117_B_0X1	(0x1u<<21)
#define	BSEC_SWLOCK3_SWLOCK116_B_0X0	(0x0u<<20)
#define	BSEC_SWLOCK3_SWLOCK116_B_0X1	(0x1u<<20)
#define	BSEC_SWLOCK3_SWLOCK115_B_0X0	(0x0u<<19)
#define	BSEC_SWLOCK3_SWLOCK115_B_0X1	(0x1u<<19)
#define	BSEC_SWLOCK3_SWLOCK114_B_0X0	(0x0u<<18)
#define	BSEC_SWLOCK3_SWLOCK114_B_0X1	(0x1u<<18)
#define	BSEC_SWLOCK3_SWLOCK113_B_0X0	(0x0u<<17)
#define	BSEC_SWLOCK3_SWLOCK113_B_0X1	(0x1u<<17)
#define	BSEC_SWLOCK3_SWLOCK112_B_0X0	(0x0u<<16)
#define	BSEC_SWLOCK3_SWLOCK112_B_0X1	(0x1u<<16)
#define	BSEC_SWLOCK3_SWLOCK111_B_0X0	(0x0u<<15)
#define	BSEC_SWLOCK3_SWLOCK111_B_0X1	(0x1u<<15)
#define	BSEC_SWLOCK3_SWLOCK110_B_0X0	(0x0u<<14)
#define	BSEC_SWLOCK3_SWLOCK110_B_0X1	(0x1u<<14)
#define	BSEC_SWLOCK3_SWLOCK109_B_0X0	(0x0u<<13)
#define	BSEC_SWLOCK3_SWLOCK109_B_0X1	(0x1u<<13)
#define	BSEC_SWLOCK3_SWLOCK108_B_0X0	(0x0u<<12)
#define	BSEC_SWLOCK3_SWLOCK108_B_0X1	(0x1u<<12)
#define	BSEC_SWLOCK3_SWLOCK107_B_0X0	(0x0u<<11)
#define	BSEC_SWLOCK3_SWLOCK107_B_0X1	(0x1u<<11)
#define	BSEC_SWLOCK3_SWLOCK106_B_0X0	(0x0u<<10)
#define	BSEC_SWLOCK3_SWLOCK106_B_0X1	(0x1u<<10)
#define	BSEC_SWLOCK3_SWLOCK105_B_0X0	(0x0u<<9)
#define	BSEC_SWLOCK3_SWLOCK105_B_0X1	(0x1u<<9)
#define	BSEC_SWLOCK3_SWLOCK104_B_0X0	(0x0u<<8)
#define	BSEC_SWLOCK3_SWLOCK104_B_0X1	(0x1u<<8)
#define	BSEC_SWLOCK3_SWLOCK103_B_0X0	(0x0u<<7)
#define	BSEC_SWLOCK3_SWLOCK103_B_0X1	(0x1u<<7)
#define	BSEC_SWLOCK3_SWLOCK102_B_0X0	(0x0u<<6)
#define	BSEC_SWLOCK3_SWLOCK102_B_0X1	(0x1u<<6)
#define	BSEC_SWLOCK3_SWLOCK101_B_0X0	(0x0u<<5)
#define	BSEC_SWLOCK3_SWLOCK101_B_0X1	(0x1u<<5)
#define	BSEC_SWLOCK3_SWLOCK100_B_0X0	(0x0u<<4)
#define	BSEC_SWLOCK3_SWLOCK100_B_0X1	(0x1u<<4)
#define	BSEC_SWLOCK3_SWLOCK99_B_0X0		(0x0u<<3)
#define	BSEC_SWLOCK3_SWLOCK99_B_0X1		(0x1u<<3)
#define	BSEC_SWLOCK3_SWLOCK98_B_0X0		(0x0u<<2)
#define	BSEC_SWLOCK3_SWLOCK98_B_0X1		(0x1u<<2)
#define	BSEC_SWLOCK3_SWLOCK97_B_0X0		(0x0u<<1)
#define	BSEC_SWLOCK3_SWLOCK97_B_0X1		(0x1u<<1)
#define	BSEC_SWLOCK3_SWLOCK96_B_0X0		(0x0u<<0)
#define	BSEC_SWLOCK3_SWLOCK96_B_0X1		(0x1u<<0)

// SWLOCK4 Configuration

#define	BSEC_SWLOCK4_SWLOCK159			(0x1u<<31)
#define	BSEC_SWLOCK4_SWLOCK158			(0x1u<<30)
#define	BSEC_SWLOCK4_SWLOCK157			(0x1u<<29)
#define	BSEC_SWLOCK4_SWLOCK156			(0x1u<<28)
#define	BSEC_SWLOCK4_SWLOCK155			(0x1u<<27)
#define	BSEC_SWLOCK4_SWLOCK154			(0x1u<<26)
#define	BSEC_SWLOCK4_SWLOCK153			(0x1u<<25)
#define	BSEC_SWLOCK4_SWLOCK152			(0x1u<<24)
#define	BSEC_SWLOCK4_SWLOCK151			(0x1u<<23)
#define	BSEC_SWLOCK4_SWLOCK150			(0x1u<<22)
#define	BSEC_SWLOCK4_SWLOCK149			(0x1u<<21)
#define	BSEC_SWLOCK4_SWLOCK148			(0x1u<<20)
#define	BSEC_SWLOCK4_SWLOCK147			(0x1u<<19)
#define	BSEC_SWLOCK4_SWLOCK146			(0x1u<<18)
#define	BSEC_SWLOCK4_SWLOCK145			(0x1u<<17)
#define	BSEC_SWLOCK4_SWLOCK144			(0x1u<<16)
#define	BSEC_SWLOCK4_SWLOCK143			(0x1u<<15)
#define	BSEC_SWLOCK4_SWLOCK142			(0x1u<<14)
#define	BSEC_SWLOCK4_SWLOCK141			(0x1u<<13)
#define	BSEC_SWLOCK4_SWLOCK140			(0x1u<<12)
#define	BSEC_SWLOCK4_SWLOCK139			(0x1u<<11)
#define	BSEC_SWLOCK4_SWLOCK138			(0x1u<<10)
#define	BSEC_SWLOCK4_SWLOCK137			(0x1u<<9)
#define	BSEC_SWLOCK4_SWLOCK136			(0x1u<<8)
#define	BSEC_SWLOCK4_SWLOCK135			(0x1u<<7)
#define	BSEC_SWLOCK4_SWLOCK134			(0x1u<<6)
#define	BSEC_SWLOCK4_SWLOCK133			(0x1u<<5)
#define	BSEC_SWLOCK4_SWLOCK132			(0x1u<<4)
#define	BSEC_SWLOCK4_SWLOCK131			(0x1u<<3)
#define	BSEC_SWLOCK4_SWLOCK130			(0x1u<<2)
#define	BSEC_SWLOCK4_SWLOCK129			(0x1u<<1)
#define	BSEC_SWLOCK4_SWLOCK128			(0x1u<<0)

#define	BSEC_SWLOCK4_SWLOCK159_B_0X0	(0x0u<<31)
#define	BSEC_SWLOCK4_SWLOCK159_B_0X1	(0x1u<<31)
#define	BSEC_SWLOCK4_SWLOCK158_B_0X0	(0x0u<<30)
#define	BSEC_SWLOCK4_SWLOCK158_B_0X1	(0x1u<<30)
#define	BSEC_SWLOCK4_SWLOCK157_B_0X0	(0x0u<<29)
#define	BSEC_SWLOCK4_SWLOCK157_B_0X1	(0x1u<<29)
#define	BSEC_SWLOCK4_SWLOCK156_B_0X0	(0x0u<<28)
#define	BSEC_SWLOCK4_SWLOCK156_B_0X1	(0x1u<<28)
#define	BSEC_SWLOCK4_SWLOCK155_B_0X0	(0x0u<<27)
#define	BSEC_SWLOCK4_SWLOCK155_B_0X1	(0x1u<<27)
#define	BSEC_SWLOCK4_SWLOCK154_B_0X0	(0x0u<<26)
#define	BSEC_SWLOCK4_SWLOCK154_B_0X1	(0x1u<<26)
#define	BSEC_SWLOCK4_SWLOCK153_B_0X0	(0x0u<<25)
#define	BSEC_SWLOCK4_SWLOCK153_B_0X1	(0x1u<<25)
#define	BSEC_SWLOCK4_SWLOCK152_B_0X0	(0x0u<<24)
#define	BSEC_SWLOCK4_SWLOCK152_B_0X1	(0x1u<<24)
#define	BSEC_SWLOCK4_SWLOCK151_B_0X0	(0x0u<<23)
#define	BSEC_SWLOCK4_SWLOCK151_B_0X1	(0x1u<<23)
#define	BSEC_SWLOCK4_SWLOCK150_B_0X0	(0x0u<<22)
#define	BSEC_SWLOCK4_SWLOCK150_B_0X1	(0x1u<<22)
#define	BSEC_SWLOCK4_SWLOCK149_B_0X0	(0x0u<<21)
#define	BSEC_SWLOCK4_SWLOCK149_B_0X1	(0x1u<<21)
#define	BSEC_SWLOCK4_SWLOCK148_B_0X0	(0x0u<<20)
#define	BSEC_SWLOCK4_SWLOCK148_B_0X1	(0x1u<<20)
#define	BSEC_SWLOCK4_SWLOCK147_B_0X0	(0x0u<<19)
#define	BSEC_SWLOCK4_SWLOCK147_B_0X1	(0x1u<<19)
#define	BSEC_SWLOCK4_SWLOCK146_B_0X0	(0x0u<<18)
#define	BSEC_SWLOCK4_SWLOCK146_B_0X1	(0x1u<<18)
#define	BSEC_SWLOCK4_SWLOCK145_B_0X0	(0x0u<<17)
#define	BSEC_SWLOCK4_SWLOCK145_B_0X1	(0x1u<<17)
#define	BSEC_SWLOCK4_SWLOCK144_B_0X0	(0x0u<<16)
#define	BSEC_SWLOCK4_SWLOCK144_B_0X1	(0x1u<<16)
#define	BSEC_SWLOCK4_SWLOCK143_B_0X0	(0x0u<<15)
#define	BSEC_SWLOCK4_SWLOCK143_B_0X1	(0x1u<<15)
#define	BSEC_SWLOCK4_SWLOCK142_B_0X0	(0x0u<<14)
#define	BSEC_SWLOCK4_SWLOCK142_B_0X1	(0x1u<<14)
#define	BSEC_SWLOCK4_SWLOCK141_B_0X0	(0x0u<<13)
#define	BSEC_SWLOCK4_SWLOCK141_B_0X1	(0x1u<<13)
#define	BSEC_SWLOCK4_SWLOCK140_B_0X0	(0x0u<<12)
#define	BSEC_SWLOCK4_SWLOCK140_B_0X1	(0x1u<<12)
#define	BSEC_SWLOCK4_SWLOCK139_B_0X0	(0x0u<<11)
#define	BSEC_SWLOCK4_SWLOCK139_B_0X1	(0x1u<<11)
#define	BSEC_SWLOCK4_SWLOCK138_B_0X0	(0x0u<<10)
#define	BSEC_SWLOCK4_SWLOCK138_B_0X1	(0x1u<<10)
#define	BSEC_SWLOCK4_SWLOCK137_B_0X0	(0x0u<<9)
#define	BSEC_SWLOCK4_SWLOCK137_B_0X1	(0x1u<<9)
#define	BSEC_SWLOCK4_SWLOCK136_B_0X0	(0x0u<<8)
#define	BSEC_SWLOCK4_SWLOCK136_B_0X1	(0x1u<<8)
#define	BSEC_SWLOCK4_SWLOCK135_B_0X0	(0x0u<<7)
#define	BSEC_SWLOCK4_SWLOCK135_B_0X1	(0x1u<<7)
#define	BSEC_SWLOCK4_SWLOCK134_B_0X0	(0x0u<<6)
#define	BSEC_SWLOCK4_SWLOCK134_B_0X1	(0x1u<<6)
#define	BSEC_SWLOCK4_SWLOCK133_B_0X0	(0x0u<<5)
#define	BSEC_SWLOCK4_SWLOCK133_B_0X1	(0x1u<<5)
#define	BSEC_SWLOCK4_SWLOCK132_B_0X0	(0x0u<<4)
#define	BSEC_SWLOCK4_SWLOCK132_B_0X1	(0x1u<<4)
#define	BSEC_SWLOCK4_SWLOCK131_B_0X0	(0x0u<<3)
#define	BSEC_SWLOCK4_SWLOCK131_B_0X1	(0x1u<<3)
#define	BSEC_SWLOCK4_SWLOCK130_B_0X0	(0x0u<<2)
#define	BSEC_SWLOCK4_SWLOCK130_B_0X1	(0x1u<<2)
#define	BSEC_SWLOCK4_SWLOCK129_B_0X0	(0x0u<<1)
#define	BSEC_SWLOCK4_SWLOCK129_B_0X1	(0x1u<<1)
#define	BSEC_SWLOCK4_SWLOCK128_B_0X0	(0x0u<<0)
#define	BSEC_SWLOCK4_SWLOCK128_B_0X1	(0x1u<<0)

// SWLOCK5 Configuration

#define	BSEC_SWLOCK5_SWLOCK191			(0x1u<<31)
#define	BSEC_SWLOCK5_SWLOCK190			(0x1u<<30)
#define	BSEC_SWLOCK5_SWLOCK189			(0x1u<<29)
#define	BSEC_SWLOCK5_SWLOCK188			(0x1u<<28)
#define	BSEC_SWLOCK5_SWLOCK187			(0x1u<<27)
#define	BSEC_SWLOCK5_SWLOCK186			(0x1u<<26)
#define	BSEC_SWLOCK5_SWLOCK185			(0x1u<<25)
#define	BSEC_SWLOCK5_SWLOCK184			(0x1u<<24)
#define	BSEC_SWLOCK5_SWLOCK183			(0x1u<<23)
#define	BSEC_SWLOCK5_SWLOCK182			(0x1u<<22)
#define	BSEC_SWLOCK5_SWLOCK181			(0x1u<<21)
#define	BSEC_SWLOCK5_SWLOCK180			(0x1u<<20)
#define	BSEC_SWLOCK5_SWLOCK179			(0x1u<<19)
#define	BSEC_SWLOCK5_SWLOCK178			(0x1u<<18)
#define	BSEC_SWLOCK5_SWLOCK177			(0x1u<<17)
#define	BSEC_SWLOCK5_SWLOCK176			(0x1u<<16)
#define	BSEC_SWLOCK5_SWLOCK175			(0x1u<<15)
#define	BSEC_SWLOCK5_SWLOCK174			(0x1u<<14)
#define	BSEC_SWLOCK5_SWLOCK173			(0x1u<<13)
#define	BSEC_SWLOCK5_SWLOCK172			(0x1u<<12)
#define	BSEC_SWLOCK5_SWLOCK171			(0x1u<<11)
#define	BSEC_SWLOCK5_SWLOCK170			(0x1u<<10)
#define	BSEC_SWLOCK5_SWLOCK169			(0x1u<<9)
#define	BSEC_SWLOCK5_SWLOCK168			(0x1u<<8)
#define	BSEC_SWLOCK5_SWLOCK167			(0x1u<<7)
#define	BSEC_SWLOCK5_SWLOCK166			(0x1u<<6)
#define	BSEC_SWLOCK5_SWLOCK165			(0x1u<<5)
#define	BSEC_SWLOCK5_SWLOCK164			(0x1u<<4)
#define	BSEC_SWLOCK5_SWLOCK163			(0x1u<<3)
#define	BSEC_SWLOCK5_SWLOCK162			(0x1u<<2)
#define	BSEC_SWLOCK5_SWLOCK161			(0x1u<<1)
#define	BSEC_SWLOCK5_SWLOCK160			(0x1u<<0)

#define	BSEC_SWLOCK5_SWLOCK191_B_0X0	(0x0u<<31)
#define	BSEC_SWLOCK5_SWLOCK191_B_0X1	(0x1u<<31)
#define	BSEC_SWLOCK5_SWLOCK190_B_0X0	(0x0u<<30)
#define	BSEC_SWLOCK5_SWLOCK190_B_0X1	(0x1u<<30)
#define	BSEC_SWLOCK5_SWLOCK189_B_0X0	(0x0u<<29)
#define	BSEC_SWLOCK5_SWLOCK189_B_0X1	(0x1u<<29)
#define	BSEC_SWLOCK5_SWLOCK188_B_0X0	(0x0u<<28)
#define	BSEC_SWLOCK5_SWLOCK188_B_0X1	(0x1u<<28)
#define	BSEC_SWLOCK5_SWLOCK187_B_0X0	(0x0u<<27)
#define	BSEC_SWLOCK5_SWLOCK187_B_0X1	(0x1u<<27)
#define	BSEC_SWLOCK5_SWLOCK186_B_0X0	(0x0u<<26)
#define	BSEC_SWLOCK5_SWLOCK186_B_0X1	(0x1u<<26)
#define	BSEC_SWLOCK5_SWLOCK185_B_0X0	(0x0u<<25)
#define	BSEC_SWLOCK5_SWLOCK185_B_0X1	(0x1u<<25)
#define	BSEC_SWLOCK5_SWLOCK184_B_0X0	(0x0u<<24)
#define	BSEC_SWLOCK5_SWLOCK184_B_0X1	(0x1u<<24)
#define	BSEC_SWLOCK5_SWLOCK183_B_0X0	(0x0u<<23)
#define	BSEC_SWLOCK5_SWLOCK183_B_0X1	(0x1u<<23)
#define	BSEC_SWLOCK5_SWLOCK182_B_0X0	(0x0u<<22)
#define	BSEC_SWLOCK5_SWLOCK182_B_0X1	(0x1u<<22)
#define	BSEC_SWLOCK5_SWLOCK181_B_0X0	(0x0u<<21)
#define	BSEC_SWLOCK5_SWLOCK181_B_0X1	(0x1u<<21)
#define	BSEC_SWLOCK5_SWLOCK180_B_0X0	(0x0u<<20)
#define	BSEC_SWLOCK5_SWLOCK180_B_0X1	(0x1u<<20)
#define	BSEC_SWLOCK5_SWLOCK179_B_0X0	(0x0u<<19)
#define	BSEC_SWLOCK5_SWLOCK179_B_0X1	(0x1u<<19)
#define	BSEC_SWLOCK5_SWLOCK178_B_0X0	(0x0u<<18)
#define	BSEC_SWLOCK5_SWLOCK178_B_0X1	(0x1u<<18)
#define	BSEC_SWLOCK5_SWLOCK177_B_0X0	(0x0u<<17)
#define	BSEC_SWLOCK5_SWLOCK177_B_0X1	(0x1u<<17)
#define	BSEC_SWLOCK5_SWLOCK176_B_0X0	(0x0u<<16)
#define	BSEC_SWLOCK5_SWLOCK176_B_0X1	(0x1u<<16)
#define	BSEC_SWLOCK5_SWLOCK175_B_0X0	(0x0u<<15)
#define	BSEC_SWLOCK5_SWLOCK175_B_0X1	(0x1u<<15)
#define	BSEC_SWLOCK5_SWLOCK174_B_0X0	(0x0u<<14)
#define	BSEC_SWLOCK5_SWLOCK174_B_0X1	(0x1u<<14)
#define	BSEC_SWLOCK5_SWLOCK173_B_0X0	(0x0u<<13)
#define	BSEC_SWLOCK5_SWLOCK173_B_0X1	(0x1u<<13)
#define	BSEC_SWLOCK5_SWLOCK172_B_0X0	(0x0u<<12)
#define	BSEC_SWLOCK5_SWLOCK172_B_0X1	(0x1u<<12)
#define	BSEC_SWLOCK5_SWLOCK171_B_0X0	(0x0u<<11)
#define	BSEC_SWLOCK5_SWLOCK171_B_0X1	(0x1u<<11)
#define	BSEC_SWLOCK5_SWLOCK170_B_0X0	(0x0u<<10)
#define	BSEC_SWLOCK5_SWLOCK170_B_0X1	(0x1u<<10)
#define	BSEC_SWLOCK5_SWLOCK169_B_0X0	(0x0u<<9)
#define	BSEC_SWLOCK5_SWLOCK169_B_0X1	(0x1u<<9)
#define	BSEC_SWLOCK5_SWLOCK168_B_0X0	(0x0u<<8)
#define	BSEC_SWLOCK5_SWLOCK168_B_0X1	(0x1u<<8)
#define	BSEC_SWLOCK5_SWLOCK167_B_0X0	(0x0u<<7)
#define	BSEC_SWLOCK5_SWLOCK167_B_0X1	(0x1u<<7)
#define	BSEC_SWLOCK5_SWLOCK166_B_0X0	(0x0u<<6)
#define	BSEC_SWLOCK5_SWLOCK166_B_0X1	(0x1u<<6)
#define	BSEC_SWLOCK5_SWLOCK165_B_0X0	(0x0u<<5)
#define	BSEC_SWLOCK5_SWLOCK165_B_0X1	(0x1u<<5)
#define	BSEC_SWLOCK5_SWLOCK164_B_0X0	(0x0u<<4)
#define	BSEC_SWLOCK5_SWLOCK164_B_0X1	(0x1u<<4)
#define	BSEC_SWLOCK5_SWLOCK163_B_0X0	(0x0u<<3)
#define	BSEC_SWLOCK5_SWLOCK163_B_0X1	(0x1u<<3)
#define	BSEC_SWLOCK5_SWLOCK162_B_0X0	(0x0u<<2)
#define	BSEC_SWLOCK5_SWLOCK162_B_0X1	(0x1u<<2)
#define	BSEC_SWLOCK5_SWLOCK161_B_0X0	(0x0u<<1)
#define	BSEC_SWLOCK5_SWLOCK161_B_0X1	(0x1u<<1)
#define	BSEC_SWLOCK5_SWLOCK160_B_0X0	(0x0u<<0)
#define	BSEC_SWLOCK5_SWLOCK160_B_0X1	(0x1u<<0)

// SWLOCK6 Configuration

#define	BSEC_SWLOCK6_SWLOCK223			(0x1u<<31)
#define	BSEC_SWLOCK6_SWLOCK222			(0x1u<<30)
#define	BSEC_SWLOCK6_SWLOCK221			(0x1u<<29)
#define	BSEC_SWLOCK6_SWLOCK220			(0x1u<<28)
#define	BSEC_SWLOCK6_SWLOCK219			(0x1u<<27)
#define	BSEC_SWLOCK6_SWLOCK218			(0x1u<<26)
#define	BSEC_SWLOCK6_SWLOCK217			(0x1u<<25)
#define	BSEC_SWLOCK6_SWLOCK216			(0x1u<<24)
#define	BSEC_SWLOCK6_SWLOCK215			(0x1u<<23)
#define	BSEC_SWLOCK6_SWLOCK214			(0x1u<<22)
#define	BSEC_SWLOCK6_SWLOCK213			(0x1u<<21)
#define	BSEC_SWLOCK6_SWLOCK212			(0x1u<<20)
#define	BSEC_SWLOCK6_SWLOCK211			(0x1u<<19)
#define	BSEC_SWLOCK6_SWLOCK210			(0x1u<<18)
#define	BSEC_SWLOCK6_SWLOCK209			(0x1u<<17)
#define	BSEC_SWLOCK6_SWLOCK208			(0x1u<<16)
#define	BSEC_SWLOCK6_SWLOCK207			(0x1u<<15)
#define	BSEC_SWLOCK6_SWLOCK206			(0x1u<<14)
#define	BSEC_SWLOCK6_SWLOCK205			(0x1u<<13)
#define	BSEC_SWLOCK6_SWLOCK204			(0x1u<<12)
#define	BSEC_SWLOCK6_SWLOCK203			(0x1u<<11)
#define	BSEC_SWLOCK6_SWLOCK202			(0x1u<<10)
#define	BSEC_SWLOCK6_SWLOCK201			(0x1u<<9)
#define	BSEC_SWLOCK6_SWLOCK200			(0x1u<<8)
#define	BSEC_SWLOCK6_SWLOCK199			(0x1u<<7)
#define	BSEC_SWLOCK6_SWLOCK198			(0x1u<<6)
#define	BSEC_SWLOCK6_SWLOCK197			(0x1u<<5)
#define	BSEC_SWLOCK6_SWLOCK196			(0x1u<<4)
#define	BSEC_SWLOCK6_SWLOCK195			(0x1u<<3)
#define	BSEC_SWLOCK6_SWLOCK194			(0x1u<<2)
#define	BSEC_SWLOCK6_SWLOCK193			(0x1u<<1)
#define	BSEC_SWLOCK6_SWLOCK192			(0x1u<<0)

#define	BSEC_SWLOCK6_SWLOCK223_B_0X0	(0x0u<<31)
#define	BSEC_SWLOCK6_SWLOCK223_B_0X1	(0x1u<<31)
#define	BSEC_SWLOCK6_SWLOCK222_B_0X0	(0x0u<<30)
#define	BSEC_SWLOCK6_SWLOCK222_B_0X1	(0x1u<<30)
#define	BSEC_SWLOCK6_SWLOCK221_B_0X0	(0x0u<<29)
#define	BSEC_SWLOCK6_SWLOCK221_B_0X1	(0x1u<<29)
#define	BSEC_SWLOCK6_SWLOCK220_B_0X0	(0x0u<<28)
#define	BSEC_SWLOCK6_SWLOCK220_B_0X1	(0x1u<<28)
#define	BSEC_SWLOCK6_SWLOCK219_B_0X0	(0x0u<<27)
#define	BSEC_SWLOCK6_SWLOCK219_B_0X1	(0x1u<<27)
#define	BSEC_SWLOCK6_SWLOCK218_B_0X0	(0x0u<<26)
#define	BSEC_SWLOCK6_SWLOCK218_B_0X1	(0x1u<<26)
#define	BSEC_SWLOCK6_SWLOCK217_B_0X0	(0x0u<<25)
#define	BSEC_SWLOCK6_SWLOCK217_B_0X1	(0x1u<<25)
#define	BSEC_SWLOCK6_SWLOCK216_B_0X0	(0x0u<<24)
#define	BSEC_SWLOCK6_SWLOCK216_B_0X1	(0x1u<<24)
#define	BSEC_SWLOCK6_SWLOCK215_B_0X0	(0x0u<<23)
#define	BSEC_SWLOCK6_SWLOCK215_B_0X1	(0x1u<<23)
#define	BSEC_SWLOCK6_SWLOCK214_B_0X0	(0x0u<<22)
#define	BSEC_SWLOCK6_SWLOCK214_B_0X1	(0x1u<<22)
#define	BSEC_SWLOCK6_SWLOCK213_B_0X0	(0x0u<<21)
#define	BSEC_SWLOCK6_SWLOCK213_B_0X1	(0x1u<<21)
#define	BSEC_SWLOCK6_SWLOCK212_B_0X0	(0x0u<<20)
#define	BSEC_SWLOCK6_SWLOCK212_B_0X1	(0x1u<<20)
#define	BSEC_SWLOCK6_SWLOCK211_B_0X0	(0x0u<<19)
#define	BSEC_SWLOCK6_SWLOCK211_B_0X1	(0x1u<<19)
#define	BSEC_SWLOCK6_SWLOCK210_B_0X0	(0x0u<<18)
#define	BSEC_SWLOCK6_SWLOCK210_B_0X1	(0x1u<<18)
#define	BSEC_SWLOCK6_SWLOCK209_B_0X0	(0x0u<<17)
#define	BSEC_SWLOCK6_SWLOCK209_B_0X1	(0x1u<<17)
#define	BSEC_SWLOCK6_SWLOCK208_B_0X0	(0x0u<<16)
#define	BSEC_SWLOCK6_SWLOCK208_B_0X1	(0x1u<<16)
#define	BSEC_SWLOCK6_SWLOCK207_B_0X0	(0x0u<<15)
#define	BSEC_SWLOCK6_SWLOCK207_B_0X1	(0x1u<<15)
#define	BSEC_SWLOCK6_SWLOCK206_B_0X0	(0x0u<<14)
#define	BSEC_SWLOCK6_SWLOCK206_B_0X1	(0x1u<<14)
#define	BSEC_SWLOCK6_SWLOCK205_B_0X0	(0x0u<<13)
#define	BSEC_SWLOCK6_SWLOCK205_B_0X1	(0x1u<<13)
#define	BSEC_SWLOCK6_SWLOCK204_B_0X0	(0x0u<<12)
#define	BSEC_SWLOCK6_SWLOCK204_B_0X1	(0x1u<<12)
#define	BSEC_SWLOCK6_SWLOCK203_B_0X0	(0x0u<<11)
#define	BSEC_SWLOCK6_SWLOCK203_B_0X1	(0x1u<<11)
#define	BSEC_SWLOCK6_SWLOCK202_B_0X0	(0x0u<<10)
#define	BSEC_SWLOCK6_SWLOCK202_B_0X1	(0x1u<<10)
#define	BSEC_SWLOCK6_SWLOCK201_B_0X0	(0x0u<<9)
#define	BSEC_SWLOCK6_SWLOCK201_B_0X1	(0x1u<<9)
#define	BSEC_SWLOCK6_SWLOCK200_B_0X0	(0x0u<<8)
#define	BSEC_SWLOCK6_SWLOCK200_B_0X1	(0x1u<<8)
#define	BSEC_SWLOCK6_SWLOCK199_B_0X0	(0x0u<<7)
#define	BSEC_SWLOCK6_SWLOCK199_B_0X1	(0x1u<<7)
#define	BSEC_SWLOCK6_SWLOCK198_B_0X0	(0x0u<<6)
#define	BSEC_SWLOCK6_SWLOCK198_B_0X1	(0x1u<<6)
#define	BSEC_SWLOCK6_SWLOCK197_B_0X0	(0x0u<<5)
#define	BSEC_SWLOCK6_SWLOCK197_B_0X1	(0x1u<<5)
#define	BSEC_SWLOCK6_SWLOCK196_B_0X0	(0x0u<<4)
#define	BSEC_SWLOCK6_SWLOCK196_B_0X1	(0x1u<<4)
#define	BSEC_SWLOCK6_SWLOCK195_B_0X0	(0x0u<<3)
#define	BSEC_SWLOCK6_SWLOCK195_B_0X1	(0x1u<<3)
#define	BSEC_SWLOCK6_SWLOCK194_B_0X0	(0x0u<<2)
#define	BSEC_SWLOCK6_SWLOCK194_B_0X1	(0x1u<<2)
#define	BSEC_SWLOCK6_SWLOCK193_B_0X0	(0x0u<<1)
#define	BSEC_SWLOCK6_SWLOCK193_B_0X1	(0x1u<<1)
#define	BSEC_SWLOCK6_SWLOCK192_B_0X0	(0x0u<<0)
#define	BSEC_SWLOCK6_SWLOCK192_B_0X1	(0x1u<<0)

// SWLOCK7 Configuration

#define	BSEC_SWLOCK7_SWLOCK255			(0x1u<<31)
#define	BSEC_SWLOCK7_SWLOCK254			(0x1u<<30)
#define	BSEC_SWLOCK7_SWLOCK253			(0x1u<<29)
#define	BSEC_SWLOCK7_SWLOCK252			(0x1u<<28)
#define	BSEC_SWLOCK7_SWLOCK251			(0x1u<<27)
#define	BSEC_SWLOCK7_SWLOCK250			(0x1u<<26)
#define	BSEC_SWLOCK7_SWLOCK249			(0x1u<<25)
#define	BSEC_SWLOCK7_SWLOCK248			(0x1u<<24)
#define	BSEC_SWLOCK7_SWLOCK247			(0x1u<<23)
#define	BSEC_SWLOCK7_SWLOCK246			(0x1u<<22)
#define	BSEC_SWLOCK7_SWLOCK245			(0x1u<<21)
#define	BSEC_SWLOCK7_SWLOCK244			(0x1u<<20)
#define	BSEC_SWLOCK7_SWLOCK243			(0x1u<<19)
#define	BSEC_SWLOCK7_SWLOCK242			(0x1u<<18)
#define	BSEC_SWLOCK7_SWLOCK241			(0x1u<<17)
#define	BSEC_SWLOCK7_SWLOCK240			(0x1u<<16)
#define	BSEC_SWLOCK7_SWLOCK239			(0x1u<<15)
#define	BSEC_SWLOCK7_SWLOCK238			(0x1u<<14)
#define	BSEC_SWLOCK7_SWLOCK237			(0x1u<<13)
#define	BSEC_SWLOCK7_SWLOCK236			(0x1u<<12)
#define	BSEC_SWLOCK7_SWLOCK235			(0x1u<<11)
#define	BSEC_SWLOCK7_SWLOCK234			(0x1u<<10)
#define	BSEC_SWLOCK7_SWLOCK233			(0x1u<<9)
#define	BSEC_SWLOCK7_SWLOCK232			(0x1u<<8)
#define	BSEC_SWLOCK7_SWLOCK231			(0x1u<<7)
#define	BSEC_SWLOCK7_SWLOCK230			(0x1u<<6)
#define	BSEC_SWLOCK7_SWLOCK229			(0x1u<<5)
#define	BSEC_SWLOCK7_SWLOCK228			(0x1u<<4)
#define	BSEC_SWLOCK7_SWLOCK227			(0x1u<<3)
#define	BSEC_SWLOCK7_SWLOCK226			(0x1u<<2)
#define	BSEC_SWLOCK7_SWLOCK225			(0x1u<<1)
#define	BSEC_SWLOCK7_SWLOCK224			(0x1u<<0)

#define	BSEC_SWLOCK7_SWLOCK255_B_0X0	(0x0u<<31)
#define	BSEC_SWLOCK7_SWLOCK255_B_0X1	(0x1u<<31)
#define	BSEC_SWLOCK7_SWLOCK254_B_0X0	(0x0u<<30)
#define	BSEC_SWLOCK7_SWLOCK254_B_0X1	(0x1u<<30)
#define	BSEC_SWLOCK7_SWLOCK253_B_0X0	(0x0u<<29)
#define	BSEC_SWLOCK7_SWLOCK253_B_0X1	(0x1u<<29)
#define	BSEC_SWLOCK7_SWLOCK252_B_0X0	(0x0u<<28)
#define	BSEC_SWLOCK7_SWLOCK252_B_0X1	(0x1u<<28)
#define	BSEC_SWLOCK7_SWLOCK251_B_0X0	(0x0u<<27)
#define	BSEC_SWLOCK7_SWLOCK251_B_0X1	(0x1u<<27)
#define	BSEC_SWLOCK7_SWLOCK250_B_0X0	(0x0u<<26)
#define	BSEC_SWLOCK7_SWLOCK250_B_0X1	(0x1u<<26)
#define	BSEC_SWLOCK7_SWLOCK249_B_0X0	(0x0u<<25)
#define	BSEC_SWLOCK7_SWLOCK249_B_0X1	(0x1u<<25)
#define	BSEC_SWLOCK7_SWLOCK248_B_0X0	(0x0u<<24)
#define	BSEC_SWLOCK7_SWLOCK248_B_0X1	(0x1u<<24)
#define	BSEC_SWLOCK7_SWLOCK247_B_0X0	(0x0u<<23)
#define	BSEC_SWLOCK7_SWLOCK247_B_0X1	(0x1u<<23)
#define	BSEC_SWLOCK7_SWLOCK246_B_0X0	(0x0u<<22)
#define	BSEC_SWLOCK7_SWLOCK246_B_0X1	(0x1u<<22)
#define	BSEC_SWLOCK7_SWLOCK245_B_0X0	(0x0u<<21)
#define	BSEC_SWLOCK7_SWLOCK245_B_0X1	(0x1u<<21)
#define	BSEC_SWLOCK7_SWLOCK244_B_0X0	(0x0u<<20)
#define	BSEC_SWLOCK7_SWLOCK244_B_0X1	(0x1u<<20)
#define	BSEC_SWLOCK7_SWLOCK243_B_0X0	(0x0u<<19)
#define	BSEC_SWLOCK7_SWLOCK243_B_0X1	(0x1u<<19)
#define	BSEC_SWLOCK7_SWLOCK242_B_0X0	(0x0u<<18)
#define	BSEC_SWLOCK7_SWLOCK242_B_0X1	(0x1u<<18)
#define	BSEC_SWLOCK7_SWLOCK241_B_0X0	(0x0u<<17)
#define	BSEC_SWLOCK7_SWLOCK241_B_0X1	(0x1u<<17)
#define	BSEC_SWLOCK7_SWLOCK240_B_0X0	(0x0u<<16)
#define	BSEC_SWLOCK7_SWLOCK240_B_0X1	(0x1u<<16)
#define	BSEC_SWLOCK7_SWLOCK239_B_0X0	(0x0u<<15)
#define	BSEC_SWLOCK7_SWLOCK239_B_0X1	(0x1u<<15)
#define	BSEC_SWLOCK7_SWLOCK238_B_0X0	(0x0u<<14)
#define	BSEC_SWLOCK7_SWLOCK238_B_0X1	(0x1u<<14)
#define	BSEC_SWLOCK7_SWLOCK237_B_0X0	(0x0u<<13)
#define	BSEC_SWLOCK7_SWLOCK237_B_0X1	(0x1u<<13)
#define	BSEC_SWLOCK7_SWLOCK236_B_0X0	(0x0u<<12)
#define	BSEC_SWLOCK7_SWLOCK236_B_0X1	(0x1u<<12)
#define	BSEC_SWLOCK7_SWLOCK235_B_0X0	(0x0u<<11)
#define	BSEC_SWLOCK7_SWLOCK235_B_0X1	(0x1u<<11)
#define	BSEC_SWLOCK7_SWLOCK234_B_0X0	(0x0u<<10)
#define	BSEC_SWLOCK7_SWLOCK234_B_0X1	(0x1u<<10)
#define	BSEC_SWLOCK7_SWLOCK233_B_0X0	(0x0u<<9)
#define	BSEC_SWLOCK7_SWLOCK233_B_0X1	(0x1u<<9)
#define	BSEC_SWLOCK7_SWLOCK232_B_0X0	(0x0u<<8)
#define	BSEC_SWLOCK7_SWLOCK232_B_0X1	(0x1u<<8)
#define	BSEC_SWLOCK7_SWLOCK231_B_0X0	(0x0u<<7)
#define	BSEC_SWLOCK7_SWLOCK231_B_0X1	(0x1u<<7)
#define	BSEC_SWLOCK7_SWLOCK230_B_0X0	(0x0u<<6)
#define	BSEC_SWLOCK7_SWLOCK230_B_0X1	(0x1u<<6)
#define	BSEC_SWLOCK7_SWLOCK229_B_0X0	(0x0u<<5)
#define	BSEC_SWLOCK7_SWLOCK229_B_0X1	(0x1u<<5)
#define	BSEC_SWLOCK7_SWLOCK228_B_0X0	(0x0u<<4)
#define	BSEC_SWLOCK7_SWLOCK228_B_0X1	(0x1u<<4)
#define	BSEC_SWLOCK7_SWLOCK227_B_0X0	(0x0u<<3)
#define	BSEC_SWLOCK7_SWLOCK227_B_0X1	(0x1u<<3)
#define	BSEC_SWLOCK7_SWLOCK226_B_0X0	(0x0u<<2)
#define	BSEC_SWLOCK7_SWLOCK226_B_0X1	(0x1u<<2)
#define	BSEC_SWLOCK7_SWLOCK225_B_0X0	(0x0u<<1)
#define	BSEC_SWLOCK7_SWLOCK225_B_0X1	(0x1u<<1)
#define	BSEC_SWLOCK7_SWLOCK224_B_0X0	(0x0u<<0)
#define	BSEC_SWLOCK7_SWLOCK224_B_0X1	(0x1u<<0)

// SWLOCK8 Configuration

#define	BSEC_SWLOCK8_SWLOCK287			(0x1u<<31)
#define	BSEC_SWLOCK8_SWLOCK286			(0x1u<<30)
#define	BSEC_SWLOCK8_SWLOCK285			(0x1u<<29)
#define	BSEC_SWLOCK8_SWLOCK284			(0x1u<<28)
#define	BSEC_SWLOCK8_SWLOCK283			(0x1u<<27)
#define	BSEC_SWLOCK8_SWLOCK282			(0x1u<<26)
#define	BSEC_SWLOCK8_SWLOCK281			(0x1u<<25)
#define	BSEC_SWLOCK8_SWLOCK280			(0x1u<<24)
#define	BSEC_SWLOCK8_SWLOCK279			(0x1u<<23)
#define	BSEC_SWLOCK8_SWLOCK278			(0x1u<<22)
#define	BSEC_SWLOCK8_SWLOCK277			(0x1u<<21)
#define	BSEC_SWLOCK8_SWLOCK276			(0x1u<<20)
#define	BSEC_SWLOCK8_SWLOCK275			(0x1u<<19)
#define	BSEC_SWLOCK8_SWLOCK274			(0x1u<<18)
#define	BSEC_SWLOCK8_SWLOCK273			(0x1u<<17)
#define	BSEC_SWLOCK8_SWLOCK272			(0x1u<<16)
#define	BSEC_SWLOCK8_SWLOCK271			(0x1u<<15)
#define	BSEC_SWLOCK8_SWLOCK270			(0x1u<<14)
#define	BSEC_SWLOCK8_SWLOCK269			(0x1u<<13)
#define	BSEC_SWLOCK8_SWLOCK268			(0x1u<<12)
#define	BSEC_SWLOCK8_SWLOCK267			(0x1u<<11)
#define	BSEC_SWLOCK8_SWLOCK266			(0x1u<<10)
#define	BSEC_SWLOCK8_SWLOCK265			(0x1u<<9)
#define	BSEC_SWLOCK8_SWLOCK264			(0x1u<<8)
#define	BSEC_SWLOCK8_SWLOCK263			(0x1u<<7)
#define	BSEC_SWLOCK8_SWLOCK262			(0x1u<<6)
#define	BSEC_SWLOCK8_SWLOCK261			(0x1u<<5)
#define	BSEC_SWLOCK8_SWLOCK260			(0x1u<<4)
#define	BSEC_SWLOCK8_SWLOCK259			(0x1u<<3)
#define	BSEC_SWLOCK8_SWLOCK258			(0x1u<<2)
#define	BSEC_SWLOCK8_SWLOCK257			(0x1u<<1)
#define	BSEC_SWLOCK8_SWLOCK256			(0x1u<<0)

#define	BSEC_SWLOCK8_SWLOCK287_B_0X0	(0x0u<<31)
#define	BSEC_SWLOCK8_SWLOCK287_B_0X1	(0x1u<<31)
#define	BSEC_SWLOCK8_SWLOCK286_B_0X0	(0x0u<<30)
#define	BSEC_SWLOCK8_SWLOCK286_B_0X1	(0x1u<<30)
#define	BSEC_SWLOCK8_SWLOCK285_B_0X0	(0x0u<<29)
#define	BSEC_SWLOCK8_SWLOCK285_B_0X1	(0x1u<<29)
#define	BSEC_SWLOCK8_SWLOCK284_B_0X0	(0x0u<<28)
#define	BSEC_SWLOCK8_SWLOCK284_B_0X1	(0x1u<<28)
#define	BSEC_SWLOCK8_SWLOCK283_B_0X0	(0x0u<<27)
#define	BSEC_SWLOCK8_SWLOCK283_B_0X1	(0x1u<<27)
#define	BSEC_SWLOCK8_SWLOCK282_B_0X0	(0x0u<<26)
#define	BSEC_SWLOCK8_SWLOCK282_B_0X1	(0x1u<<26)
#define	BSEC_SWLOCK8_SWLOCK281_B_0X0	(0x0u<<25)
#define	BSEC_SWLOCK8_SWLOCK281_B_0X1	(0x1u<<25)
#define	BSEC_SWLOCK8_SWLOCK280_B_0X0	(0x0u<<24)
#define	BSEC_SWLOCK8_SWLOCK280_B_0X1	(0x1u<<24)
#define	BSEC_SWLOCK8_SWLOCK279_B_0X0	(0x0u<<23)
#define	BSEC_SWLOCK8_SWLOCK279_B_0X1	(0x1u<<23)
#define	BSEC_SWLOCK8_SWLOCK278_B_0X0	(0x0u<<22)
#define	BSEC_SWLOCK8_SWLOCK278_B_0X1	(0x1u<<22)
#define	BSEC_SWLOCK8_SWLOCK277_B_0X0	(0x0u<<21)
#define	BSEC_SWLOCK8_SWLOCK277_B_0X1	(0x1u<<21)
#define	BSEC_SWLOCK8_SWLOCK276_B_0X0	(0x0u<<20)
#define	BSEC_SWLOCK8_SWLOCK276_B_0X1	(0x1u<<20)
#define	BSEC_SWLOCK8_SWLOCK275_B_0X0	(0x0u<<19)
#define	BSEC_SWLOCK8_SWLOCK275_B_0X1	(0x1u<<19)
#define	BSEC_SWLOCK8_SWLOCK274_B_0X0	(0x0u<<18)
#define	BSEC_SWLOCK8_SWLOCK274_B_0X1	(0x1u<<18)
#define	BSEC_SWLOCK8_SWLOCK273_B_0X0	(0x0u<<17)
#define	BSEC_SWLOCK8_SWLOCK273_B_0X1	(0x1u<<17)
#define	BSEC_SWLOCK8_SWLOCK272_B_0X0	(0x0u<<16)
#define	BSEC_SWLOCK8_SWLOCK272_B_0X1	(0x1u<<16)
#define	BSEC_SWLOCK8_SWLOCK271_B_0X0	(0x0u<<15)
#define	BSEC_SWLOCK8_SWLOCK271_B_0X1	(0x1u<<15)
#define	BSEC_SWLOCK8_SWLOCK270_B_0X0	(0x0u<<14)
#define	BSEC_SWLOCK8_SWLOCK270_B_0X1	(0x1u<<14)
#define	BSEC_SWLOCK8_SWLOCK269_B_0X0	(0x0u<<13)
#define	BSEC_SWLOCK8_SWLOCK269_B_0X1	(0x1u<<13)
#define	BSEC_SWLOCK8_SWLOCK268_B_0X0	(0x0u<<12)
#define	BSEC_SWLOCK8_SWLOCK268_B_0X1	(0x1u<<12)
#define	BSEC_SWLOCK8_SWLOCK267_B_0X0	(0x0u<<11)
#define	BSEC_SWLOCK8_SWLOCK267_B_0X1	(0x1u<<11)
#define	BSEC_SWLOCK8_SWLOCK266_B_0X0	(0x0u<<10)
#define	BSEC_SWLOCK8_SWLOCK266_B_0X1	(0x1u<<10)
#define	BSEC_SWLOCK8_SWLOCK265_B_0X0	(0x0u<<9)
#define	BSEC_SWLOCK8_SWLOCK265_B_0X1	(0x1u<<9)
#define	BSEC_SWLOCK8_SWLOCK264_B_0X0	(0x0u<<8)
#define	BSEC_SWLOCK8_SWLOCK264_B_0X1	(0x1u<<8)
#define	BSEC_SWLOCK8_SWLOCK263_B_0X0	(0x0u<<7)
#define	BSEC_SWLOCK8_SWLOCK263_B_0X1	(0x1u<<7)
#define	BSEC_SWLOCK8_SWLOCK262_B_0X0	(0x0u<<6)
#define	BSEC_SWLOCK8_SWLOCK262_B_0X1	(0x1u<<6)
#define	BSEC_SWLOCK8_SWLOCK261_B_0X0	(0x0u<<5)
#define	BSEC_SWLOCK8_SWLOCK261_B_0X1	(0x1u<<5)
#define	BSEC_SWLOCK8_SWLOCK260_B_0X0	(0x0u<<4)
#define	BSEC_SWLOCK8_SWLOCK260_B_0X1	(0x1u<<4)
#define	BSEC_SWLOCK8_SWLOCK259_B_0X0	(0x0u<<3)
#define	BSEC_SWLOCK8_SWLOCK259_B_0X1	(0x1u<<3)
#define	BSEC_SWLOCK8_SWLOCK258_B_0X0	(0x0u<<2)
#define	BSEC_SWLOCK8_SWLOCK258_B_0X1	(0x1u<<2)
#define	BSEC_SWLOCK8_SWLOCK257_B_0X0	(0x0u<<1)
#define	BSEC_SWLOCK8_SWLOCK257_B_0X1	(0x1u<<1)
#define	BSEC_SWLOCK8_SWLOCK256_B_0X0	(0x0u<<0)
#define	BSEC_SWLOCK8_SWLOCK256_B_0X1	(0x1u<<0)

// SWLOCK9 Configuration

#define	BSEC_SWLOCK9_SWLOCK319			(0x1u<<31)
#define	BSEC_SWLOCK9_SWLOCK318			(0x1u<<30)
#define	BSEC_SWLOCK9_SWLOCK317			(0x1u<<29)
#define	BSEC_SWLOCK9_SWLOCK316			(0x1u<<28)
#define	BSEC_SWLOCK9_SWLOCK315			(0x1u<<27)
#define	BSEC_SWLOCK9_SWLOCK314			(0x1u<<26)
#define	BSEC_SWLOCK9_SWLOCK313			(0x1u<<25)
#define	BSEC_SWLOCK9_SWLOCK312			(0x1u<<24)
#define	BSEC_SWLOCK9_SWLOCK311			(0x1u<<23)
#define	BSEC_SWLOCK9_SWLOCK310			(0x1u<<22)
#define	BSEC_SWLOCK9_SWLOCK309			(0x1u<<21)
#define	BSEC_SWLOCK9_SWLOCK308			(0x1u<<20)
#define	BSEC_SWLOCK9_SWLOCK307			(0x1u<<19)
#define	BSEC_SWLOCK9_SWLOCK306			(0x1u<<18)
#define	BSEC_SWLOCK9_SWLOCK305			(0x1u<<17)
#define	BSEC_SWLOCK9_SWLOCK304			(0x1u<<16)
#define	BSEC_SWLOCK9_SWLOCK303			(0x1u<<15)
#define	BSEC_SWLOCK9_SWLOCK302			(0x1u<<14)
#define	BSEC_SWLOCK9_SWLOCK301			(0x1u<<13)
#define	BSEC_SWLOCK9_SWLOCK300			(0x1u<<12)
#define	BSEC_SWLOCK9_SWLOCK299			(0x1u<<11)
#define	BSEC_SWLOCK9_SWLOCK298			(0x1u<<10)
#define	BSEC_SWLOCK9_SWLOCK297			(0x1u<<9)
#define	BSEC_SWLOCK9_SWLOCK296			(0x1u<<8)
#define	BSEC_SWLOCK9_SWLOCK295			(0x1u<<7)
#define	BSEC_SWLOCK9_SWLOCK294			(0x1u<<6)
#define	BSEC_SWLOCK9_SWLOCK293			(0x1u<<5)
#define	BSEC_SWLOCK9_SWLOCK292			(0x1u<<4)
#define	BSEC_SWLOCK9_SWLOCK291			(0x1u<<3)
#define	BSEC_SWLOCK9_SWLOCK290			(0x1u<<2)
#define	BSEC_SWLOCK9_SWLOCK289			(0x1u<<1)
#define	BSEC_SWLOCK9_SWLOCK288			(0x1u<<0)

#define	BSEC_SWLOCK9_SWLOCK319_B_0X0	(0x0u<<31)
#define	BSEC_SWLOCK9_SWLOCK319_B_0X1	(0x1u<<31)
#define	BSEC_SWLOCK9_SWLOCK318_B_0X0	(0x0u<<30)
#define	BSEC_SWLOCK9_SWLOCK318_B_0X1	(0x1u<<30)
#define	BSEC_SWLOCK9_SWLOCK317_B_0X0	(0x0u<<29)
#define	BSEC_SWLOCK9_SWLOCK317_B_0X1	(0x1u<<29)
#define	BSEC_SWLOCK9_SWLOCK316_B_0X0	(0x0u<<28)
#define	BSEC_SWLOCK9_SWLOCK316_B_0X1	(0x1u<<28)
#define	BSEC_SWLOCK9_SWLOCK315_B_0X0	(0x0u<<27)
#define	BSEC_SWLOCK9_SWLOCK315_B_0X1	(0x1u<<27)
#define	BSEC_SWLOCK9_SWLOCK314_B_0X0	(0x0u<<26)
#define	BSEC_SWLOCK9_SWLOCK314_B_0X1	(0x1u<<26)
#define	BSEC_SWLOCK9_SWLOCK313_B_0X0	(0x0u<<25)
#define	BSEC_SWLOCK9_SWLOCK313_B_0X1	(0x1u<<25)
#define	BSEC_SWLOCK9_SWLOCK312_B_0X0	(0x0u<<24)
#define	BSEC_SWLOCK9_SWLOCK312_B_0X1	(0x1u<<24)
#define	BSEC_SWLOCK9_SWLOCK311_B_0X0	(0x0u<<23)
#define	BSEC_SWLOCK9_SWLOCK311_B_0X1	(0x1u<<23)
#define	BSEC_SWLOCK9_SWLOCK310_B_0X0	(0x0u<<22)
#define	BSEC_SWLOCK9_SWLOCK310_B_0X1	(0x1u<<22)
#define	BSEC_SWLOCK9_SWLOCK309_B_0X0	(0x0u<<21)
#define	BSEC_SWLOCK9_SWLOCK309_B_0X1	(0x1u<<21)
#define	BSEC_SWLOCK9_SWLOCK308_B_0X0	(0x0u<<20)
#define	BSEC_SWLOCK9_SWLOCK308_B_0X1	(0x1u<<20)
#define	BSEC_SWLOCK9_SWLOCK307_B_0X0	(0x0u<<19)
#define	BSEC_SWLOCK9_SWLOCK307_B_0X1	(0x1u<<19)
#define	BSEC_SWLOCK9_SWLOCK306_B_0X0	(0x0u<<18)
#define	BSEC_SWLOCK9_SWLOCK306_B_0X1	(0x1u<<18)
#define	BSEC_SWLOCK9_SWLOCK305_B_0X0	(0x0u<<17)
#define	BSEC_SWLOCK9_SWLOCK305_B_0X1	(0x1u<<17)
#define	BSEC_SWLOCK9_SWLOCK304_B_0X0	(0x0u<<16)
#define	BSEC_SWLOCK9_SWLOCK304_B_0X1	(0x1u<<16)
#define	BSEC_SWLOCK9_SWLOCK303_B_0X0	(0x0u<<15)
#define	BSEC_SWLOCK9_SWLOCK303_B_0X1	(0x1u<<15)
#define	BSEC_SWLOCK9_SWLOCK302_B_0X0	(0x0u<<14)
#define	BSEC_SWLOCK9_SWLOCK302_B_0X1	(0x1u<<14)
#define	BSEC_SWLOCK9_SWLOCK301_B_0X0	(0x0u<<13)
#define	BSEC_SWLOCK9_SWLOCK301_B_0X1	(0x1u<<13)
#define	BSEC_SWLOCK9_SWLOCK300_B_0X0	(0x0u<<12)
#define	BSEC_SWLOCK9_SWLOCK300_B_0X1	(0x1u<<12)
#define	BSEC_SWLOCK9_SWLOCK299_B_0X0	(0x0u<<11)
#define	BSEC_SWLOCK9_SWLOCK299_B_0X1	(0x1u<<11)
#define	BSEC_SWLOCK9_SWLOCK298_B_0X0	(0x0u<<10)
#define	BSEC_SWLOCK9_SWLOCK298_B_0X1	(0x1u<<10)
#define	BSEC_SWLOCK9_SWLOCK297_B_0X0	(0x0u<<9)
#define	BSEC_SWLOCK9_SWLOCK297_B_0X1	(0x1u<<9)
#define	BSEC_SWLOCK9_SWLOCK296_B_0X0	(0x0u<<8)
#define	BSEC_SWLOCK9_SWLOCK296_B_0X1	(0x1u<<8)
#define	BSEC_SWLOCK9_SWLOCK295_B_0X0	(0x0u<<7)
#define	BSEC_SWLOCK9_SWLOCK295_B_0X1	(0x1u<<7)
#define	BSEC_SWLOCK9_SWLOCK294_B_0X0	(0x0u<<6)
#define	BSEC_SWLOCK9_SWLOCK294_B_0X1	(0x1u<<6)
#define	BSEC_SWLOCK9_SWLOCK293_B_0X0	(0x0u<<5)
#define	BSEC_SWLOCK9_SWLOCK293_B_0X1	(0x1u<<5)
#define	BSEC_SWLOCK9_SWLOCK292_B_0X0	(0x0u<<4)
#define	BSEC_SWLOCK9_SWLOCK292_B_0X1	(0x1u<<4)
#define	BSEC_SWLOCK9_SWLOCK291_B_0X0	(0x0u<<3)
#define	BSEC_SWLOCK9_SWLOCK291_B_0X1	(0x1u<<3)
#define	BSEC_SWLOCK9_SWLOCK290_B_0X0	(0x0u<<2)
#define	BSEC_SWLOCK9_SWLOCK290_B_0X1	(0x1u<<2)
#define	BSEC_SWLOCK9_SWLOCK289_B_0X0	(0x0u<<1)
#define	BSEC_SWLOCK9_SWLOCK289_B_0X1	(0x1u<<1)
#define	BSEC_SWLOCK9_SWLOCK288_B_0X0	(0x0u<<0)
#define	BSEC_SWLOCK9_SWLOCK288_B_0X1	(0x1u<<0)

// SWLOCK10 Configuration

#define	BSEC_SWLOCK10_SWLOCK351			(0x1u<<31)
#define	BSEC_SWLOCK10_SWLOCK350			(0x1u<<30)
#define	BSEC_SWLOCK10_SWLOCK349			(0x1u<<29)
#define	BSEC_SWLOCK10_SWLOCK348			(0x1u<<28)
#define	BSEC_SWLOCK10_SWLOCK347			(0x1u<<27)
#define	BSEC_SWLOCK10_SWLOCK346			(0x1u<<26)
#define	BSEC_SWLOCK10_SWLOCK345			(0x1u<<25)
#define	BSEC_SWLOCK10_SWLOCK344			(0x1u<<24)
#define	BSEC_SWLOCK10_SWLOCK343			(0x1u<<23)
#define	BSEC_SWLOCK10_SWLOCK342			(0x1u<<22)
#define	BSEC_SWLOCK10_SWLOCK341			(0x1u<<21)
#define	BSEC_SWLOCK10_SWLOCK340			(0x1u<<20)
#define	BSEC_SWLOCK10_SWLOCK339			(0x1u<<19)
#define	BSEC_SWLOCK10_SWLOCK338			(0x1u<<18)
#define	BSEC_SWLOCK10_SWLOCK337			(0x1u<<17)
#define	BSEC_SWLOCK10_SWLOCK336			(0x1u<<16)
#define	BSEC_SWLOCK10_SWLOCK335			(0x1u<<15)
#define	BSEC_SWLOCK10_SWLOCK334			(0x1u<<14)
#define	BSEC_SWLOCK10_SWLOCK333			(0x1u<<13)
#define	BSEC_SWLOCK10_SWLOCK332			(0x1u<<12)
#define	BSEC_SWLOCK10_SWLOCK331			(0x1u<<11)
#define	BSEC_SWLOCK10_SWLOCK330			(0x1u<<10)
#define	BSEC_SWLOCK10_SWLOCK329			(0x1u<<9)
#define	BSEC_SWLOCK10_SWLOCK328			(0x1u<<8)
#define	BSEC_SWLOCK10_SWLOCK327			(0x1u<<7)
#define	BSEC_SWLOCK10_SWLOCK326			(0x1u<<6)
#define	BSEC_SWLOCK10_SWLOCK325			(0x1u<<5)
#define	BSEC_SWLOCK10_SWLOCK324			(0x1u<<4)
#define	BSEC_SWLOCK10_SWLOCK323			(0x1u<<3)
#define	BSEC_SWLOCK10_SWLOCK322			(0x1u<<2)
#define	BSEC_SWLOCK10_SWLOCK321			(0x1u<<1)
#define	BSEC_SWLOCK10_SWLOCK320			(0x1u<<0)

#define	BSEC_SWLOCK10_SWLOCK351_B_0X0	(0x0u<<31)
#define	BSEC_SWLOCK10_SWLOCK351_B_0X1	(0x1u<<31)
#define	BSEC_SWLOCK10_SWLOCK350_B_0X0	(0x0u<<30)
#define	BSEC_SWLOCK10_SWLOCK350_B_0X1	(0x1u<<30)
#define	BSEC_SWLOCK10_SWLOCK349_B_0X0	(0x0u<<29)
#define	BSEC_SWLOCK10_SWLOCK349_B_0X1	(0x1u<<29)
#define	BSEC_SWLOCK10_SWLOCK348_B_0X0	(0x0u<<28)
#define	BSEC_SWLOCK10_SWLOCK348_B_0X1	(0x1u<<28)
#define	BSEC_SWLOCK10_SWLOCK347_B_0X0	(0x0u<<27)
#define	BSEC_SWLOCK10_SWLOCK347_B_0X1	(0x1u<<27)
#define	BSEC_SWLOCK10_SWLOCK346_B_0X0	(0x0u<<26)
#define	BSEC_SWLOCK10_SWLOCK346_B_0X1	(0x1u<<26)
#define	BSEC_SWLOCK10_SWLOCK345_B_0X0	(0x0u<<25)
#define	BSEC_SWLOCK10_SWLOCK345_B_0X1	(0x1u<<25)
#define	BSEC_SWLOCK10_SWLOCK344_B_0X0	(0x0u<<24)
#define	BSEC_SWLOCK10_SWLOCK344_B_0X1	(0x1u<<24)
#define	BSEC_SWLOCK10_SWLOCK343_B_0X0	(0x0u<<23)
#define	BSEC_SWLOCK10_SWLOCK343_B_0X1	(0x1u<<23)
#define	BSEC_SWLOCK10_SWLOCK342_B_0X0	(0x0u<<22)
#define	BSEC_SWLOCK10_SWLOCK342_B_0X1	(0x1u<<22)
#define	BSEC_SWLOCK10_SWLOCK341_B_0X0	(0x0u<<21)
#define	BSEC_SWLOCK10_SWLOCK341_B_0X1	(0x1u<<21)
#define	BSEC_SWLOCK10_SWLOCK340_B_0X0	(0x0u<<20)
#define	BSEC_SWLOCK10_SWLOCK340_B_0X1	(0x1u<<20)
#define	BSEC_SWLOCK10_SWLOCK339_B_0X0	(0x0u<<19)
#define	BSEC_SWLOCK10_SWLOCK339_B_0X1	(0x1u<<19)
#define	BSEC_SWLOCK10_SWLOCK338_B_0X0	(0x0u<<18)
#define	BSEC_SWLOCK10_SWLOCK338_B_0X1	(0x1u<<18)
#define	BSEC_SWLOCK10_SWLOCK337_B_0X0	(0x0u<<17)
#define	BSEC_SWLOCK10_SWLOCK337_B_0X1	(0x1u<<17)
#define	BSEC_SWLOCK10_SWLOCK336_B_0X0	(0x0u<<16)
#define	BSEC_SWLOCK10_SWLOCK336_B_0X1	(0x1u<<16)
#define	BSEC_SWLOCK10_SWLOCK335_B_0X0	(0x0u<<15)
#define	BSEC_SWLOCK10_SWLOCK335_B_0X1	(0x1u<<15)
#define	BSEC_SWLOCK10_SWLOCK334_B_0X0	(0x0u<<14)
#define	BSEC_SWLOCK10_SWLOCK334_B_0X1	(0x1u<<14)
#define	BSEC_SWLOCK10_SWLOCK333_B_0X0	(0x0u<<13)
#define	BSEC_SWLOCK10_SWLOCK333_B_0X1	(0x1u<<13)
#define	BSEC_SWLOCK10_SWLOCK332_B_0X0	(0x0u<<12)
#define	BSEC_SWLOCK10_SWLOCK332_B_0X1	(0x1u<<12)
#define	BSEC_SWLOCK10_SWLOCK331_B_0X0	(0x0u<<11)
#define	BSEC_SWLOCK10_SWLOCK331_B_0X1	(0x1u<<11)
#define	BSEC_SWLOCK10_SWLOCK330_B_0X0	(0x0u<<10)
#define	BSEC_SWLOCK10_SWLOCK330_B_0X1	(0x1u<<10)
#define	BSEC_SWLOCK10_SWLOCK329_B_0X0	(0x0u<<9)
#define	BSEC_SWLOCK10_SWLOCK329_B_0X1	(0x1u<<9)
#define	BSEC_SWLOCK10_SWLOCK328_B_0X0	(0x0u<<8)
#define	BSEC_SWLOCK10_SWLOCK328_B_0X1	(0x1u<<8)
#define	BSEC_SWLOCK10_SWLOCK327_B_0X0	(0x0u<<7)
#define	BSEC_SWLOCK10_SWLOCK327_B_0X1	(0x1u<<7)
#define	BSEC_SWLOCK10_SWLOCK326_B_0X0	(0x0u<<6)
#define	BSEC_SWLOCK10_SWLOCK326_B_0X1	(0x1u<<6)
#define	BSEC_SWLOCK10_SWLOCK325_B_0X0	(0x0u<<5)
#define	BSEC_SWLOCK10_SWLOCK325_B_0X1	(0x1u<<5)
#define	BSEC_SWLOCK10_SWLOCK324_B_0X0	(0x0u<<4)
#define	BSEC_SWLOCK10_SWLOCK324_B_0X1	(0x1u<<4)
#define	BSEC_SWLOCK10_SWLOCK323_B_0X0	(0x0u<<3)
#define	BSEC_SWLOCK10_SWLOCK323_B_0X1	(0x1u<<3)
#define	BSEC_SWLOCK10_SWLOCK322_B_0X0	(0x0u<<2)
#define	BSEC_SWLOCK10_SWLOCK322_B_0X1	(0x1u<<2)
#define	BSEC_SWLOCK10_SWLOCK321_B_0X0	(0x0u<<1)
#define	BSEC_SWLOCK10_SWLOCK321_B_0X1	(0x1u<<1)
#define	BSEC_SWLOCK10_SWLOCK320_B_0X0	(0x0u<<0)
#define	BSEC_SWLOCK10_SWLOCK320_B_0X1	(0x1u<<0)

// SWLOCK11 Configuration

#define	BSEC_SWLOCK11_SWLOCK383			(0x1u<<31)
#define	BSEC_SWLOCK11_SWLOCK382			(0x1u<<30)
#define	BSEC_SWLOCK11_SWLOCK381			(0x1u<<29)
#define	BSEC_SWLOCK11_SWLOCK380			(0x1u<<28)
#define	BSEC_SWLOCK11_SWLOCK379			(0x1u<<27)
#define	BSEC_SWLOCK11_SWLOCK378			(0x1u<<26)
#define	BSEC_SWLOCK11_SWLOCK377			(0x1u<<25)
#define	BSEC_SWLOCK11_SWLOCK376			(0x1u<<24)
#define	BSEC_SWLOCK11_SWLOCK375			(0x1u<<23)
#define	BSEC_SWLOCK11_SWLOCK374			(0x1u<<22)
#define	BSEC_SWLOCK11_SWLOCK373			(0x1u<<21)
#define	BSEC_SWLOCK11_SWLOCK372			(0x1u<<20)
#define	BSEC_SWLOCK11_SWLOCK371			(0x1u<<19)
#define	BSEC_SWLOCK11_SWLOCK370			(0x1u<<18)
#define	BSEC_SWLOCK11_SWLOCK369			(0x1u<<17)
#define	BSEC_SWLOCK11_SWLOCK368			(0x1u<<16)
#define	BSEC_SWLOCK11_SWLOCK367			(0x1u<<15)
#define	BSEC_SWLOCK11_SWLOCK366			(0x1u<<14)
#define	BSEC_SWLOCK11_SWLOCK365			(0x1u<<13)
#define	BSEC_SWLOCK11_SWLOCK364			(0x1u<<12)
#define	BSEC_SWLOCK11_SWLOCK363			(0x1u<<11)
#define	BSEC_SWLOCK11_SWLOCK362			(0x1u<<10)
#define	BSEC_SWLOCK11_SWLOCK361			(0x1u<<9)
#define	BSEC_SWLOCK11_SWLOCK360			(0x1u<<8)
#define	BSEC_SWLOCK11_SWLOCK359			(0x1u<<7)
#define	BSEC_SWLOCK11_SWLOCK358			(0x1u<<6)
#define	BSEC_SWLOCK11_SWLOCK357			(0x1u<<5)
#define	BSEC_SWLOCK11_SWLOCK356			(0x1u<<4)
#define	BSEC_SWLOCK11_SWLOCK355			(0x1u<<3)
#define	BSEC_SWLOCK11_SWLOCK354			(0x1u<<2)
#define	BSEC_SWLOCK11_SWLOCK353			(0x1u<<1)
#define	BSEC_SWLOCK11_SWLOCK352			(0x1u<<0)

#define	BSEC_SWLOCK11_SWLOCK383_B_0X0	(0x0u<<31)
#define	BSEC_SWLOCK11_SWLOCK383_B_0X1	(0x1u<<31)
#define	BSEC_SWLOCK11_SWLOCK382_B_0X0	(0x0u<<30)
#define	BSEC_SWLOCK11_SWLOCK382_B_0X1	(0x1u<<30)
#define	BSEC_SWLOCK11_SWLOCK381_B_0X0	(0x0u<<29)
#define	BSEC_SWLOCK11_SWLOCK381_B_0X1	(0x1u<<29)
#define	BSEC_SWLOCK11_SWLOCK380_B_0X0	(0x0u<<28)
#define	BSEC_SWLOCK11_SWLOCK380_B_0X1	(0x1u<<28)
#define	BSEC_SWLOCK11_SWLOCK379_B_0X0	(0x0u<<27)
#define	BSEC_SWLOCK11_SWLOCK379_B_0X1	(0x1u<<27)
#define	BSEC_SWLOCK11_SWLOCK378_B_0X0	(0x0u<<26)
#define	BSEC_SWLOCK11_SWLOCK378_B_0X1	(0x1u<<26)
#define	BSEC_SWLOCK11_SWLOCK377_B_0X0	(0x0u<<25)
#define	BSEC_SWLOCK11_SWLOCK377_B_0X1	(0x1u<<25)
#define	BSEC_SWLOCK11_SWLOCK376_B_0X0	(0x0u<<24)
#define	BSEC_SWLOCK11_SWLOCK376_B_0X1	(0x1u<<24)
#define	BSEC_SWLOCK11_SWLOCK375_B_0X0	(0x0u<<23)
#define	BSEC_SWLOCK11_SWLOCK375_B_0X1	(0x1u<<23)
#define	BSEC_SWLOCK11_SWLOCK374_B_0X0	(0x0u<<22)
#define	BSEC_SWLOCK11_SWLOCK374_B_0X1	(0x1u<<22)
#define	BSEC_SWLOCK11_SWLOCK373_B_0X0	(0x0u<<21)
#define	BSEC_SWLOCK11_SWLOCK373_B_0X1	(0x1u<<21)
#define	BSEC_SWLOCK11_SWLOCK372_B_0X0	(0x0u<<20)
#define	BSEC_SWLOCK11_SWLOCK372_B_0X1	(0x1u<<20)
#define	BSEC_SWLOCK11_SWLOCK371_B_0X0	(0x0u<<19)
#define	BSEC_SWLOCK11_SWLOCK371_B_0X1	(0x1u<<19)
#define	BSEC_SWLOCK11_SWLOCK370_B_0X0	(0x0u<<18)
#define	BSEC_SWLOCK11_SWLOCK370_B_0X1	(0x1u<<18)
#define	BSEC_SWLOCK11_SWLOCK369_B_0X0	(0x0u<<17)
#define	BSEC_SWLOCK11_SWLOCK369_B_0X1	(0x1u<<17)
#define	BSEC_SWLOCK11_SWLOCK368_B_0X0	(0x0u<<16)
#define	BSEC_SWLOCK11_SWLOCK368_B_0X1	(0x1u<<16)
#define	BSEC_SWLOCK11_SWLOCK367_B_0X0	(0x0u<<15)
#define	BSEC_SWLOCK11_SWLOCK367_B_0X1	(0x1u<<15)
#define	BSEC_SWLOCK11_SWLOCK366_B_0X0	(0x0u<<14)
#define	BSEC_SWLOCK11_SWLOCK366_B_0X1	(0x1u<<14)
#define	BSEC_SWLOCK11_SWLOCK365_B_0X0	(0x0u<<13)
#define	BSEC_SWLOCK11_SWLOCK365_B_0X1	(0x1u<<13)
#define	BSEC_SWLOCK11_SWLOCK364_B_0X0	(0x0u<<12)
#define	BSEC_SWLOCK11_SWLOCK364_B_0X1	(0x1u<<12)
#define	BSEC_SWLOCK11_SWLOCK363_B_0X0	(0x0u<<11)
#define	BSEC_SWLOCK11_SWLOCK363_B_0X1	(0x1u<<11)
#define	BSEC_SWLOCK11_SWLOCK362_B_0X0	(0x0u<<10)
#define	BSEC_SWLOCK11_SWLOCK362_B_0X1	(0x1u<<10)
#define	BSEC_SWLOCK11_SWLOCK361_B_0X0	(0x0u<<9)
#define	BSEC_SWLOCK11_SWLOCK361_B_0X1	(0x1u<<9)
#define	BSEC_SWLOCK11_SWLOCK360_B_0X0	(0x0u<<8)
#define	BSEC_SWLOCK11_SWLOCK360_B_0X1	(0x1u<<8)
#define	BSEC_SWLOCK11_SWLOCK359_B_0X0	(0x0u<<7)
#define	BSEC_SWLOCK11_SWLOCK359_B_0X1	(0x1u<<7)
#define	BSEC_SWLOCK11_SWLOCK358_B_0X0	(0x0u<<6)
#define	BSEC_SWLOCK11_SWLOCK358_B_0X1	(0x1u<<6)
#define	BSEC_SWLOCK11_SWLOCK357_B_0X0	(0x0u<<5)
#define	BSEC_SWLOCK11_SWLOCK357_B_0X1	(0x1u<<5)
#define	BSEC_SWLOCK11_SWLOCK356_B_0X0	(0x0u<<4)
#define	BSEC_SWLOCK11_SWLOCK356_B_0X1	(0x1u<<4)
#define	BSEC_SWLOCK11_SWLOCK355_B_0X0	(0x0u<<3)
#define	BSEC_SWLOCK11_SWLOCK355_B_0X1	(0x1u<<3)
#define	BSEC_SWLOCK11_SWLOCK354_B_0X0	(0x0u<<2)
#define	BSEC_SWLOCK11_SWLOCK354_B_0X1	(0x1u<<2)
#define	BSEC_SWLOCK11_SWLOCK353_B_0X0	(0x0u<<1)
#define	BSEC_SWLOCK11_SWLOCK353_B_0X1	(0x1u<<1)
#define	BSEC_SWLOCK11_SWLOCK352_B_0X0	(0x0u<<0)
#define	BSEC_SWLOCK11_SWLOCK352_B_0X1	(0x1u<<0)

// SRLOCK0 Configuration

#define	BSEC_SRLOCK0_SRLOCK31			(0x1u<<31)
#define	BSEC_SRLOCK0_SRLOCK30			(0x1u<<30)
#define	BSEC_SRLOCK0_SRLOCK29			(0x1u<<29)
#define	BSEC_SRLOCK0_SRLOCK28			(0x1u<<28)
#define	BSEC_SRLOCK0_SRLOCK27			(0x1u<<27)
#define	BSEC_SRLOCK0_SRLOCK26			(0x1u<<26)
#define	BSEC_SRLOCK0_SRLOCK25			(0x1u<<25)
#define	BSEC_SRLOCK0_SRLOCK24			(0x1u<<24)
#define	BSEC_SRLOCK0_SRLOCK23			(0x1u<<23)
#define	BSEC_SRLOCK0_SRLOCK22			(0x1u<<22)
#define	BSEC_SRLOCK0_SRLOCK21			(0x1u<<21)
#define	BSEC_SRLOCK0_SRLOCK20			(0x1u<<20)
#define	BSEC_SRLOCK0_SRLOCK19			(0x1u<<19)
#define	BSEC_SRLOCK0_SRLOCK18			(0x1u<<18)
#define	BSEC_SRLOCK0_SRLOCK17			(0x1u<<17)
#define	BSEC_SRLOCK0_SRLOCK16			(0x1u<<16)
#define	BSEC_SRLOCK0_SRLOCK15			(0x1u<<15)
#define	BSEC_SRLOCK0_SRLOCK14			(0x1u<<14)
#define	BSEC_SRLOCK0_SRLOCK13			(0x1u<<13)
#define	BSEC_SRLOCK0_SRLOCK12			(0x1u<<12)
#define	BSEC_SRLOCK0_SRLOCK11			(0x1u<<11)
#define	BSEC_SRLOCK0_SRLOCK10			(0x1u<<10)
#define	BSEC_SRLOCK0_SRLOCK9			(0x1u<<9)
#define	BSEC_SRLOCK0_SRLOCK8			(0x1u<<8)
#define	BSEC_SRLOCK0_SRLOCK7			(0x1u<<7)
#define	BSEC_SRLOCK0_SRLOCK6			(0x1u<<6)
#define	BSEC_SRLOCK0_SRLOCK5			(0x1u<<5)
#define	BSEC_SRLOCK0_SRLOCK4			(0x1u<<4)
#define	BSEC_SRLOCK0_SRLOCK3			(0x1u<<3)
#define	BSEC_SRLOCK0_SRLOCK2			(0x1u<<2)
#define	BSEC_SRLOCK0_SRLOCK1			(0x1u<<1)
#define	BSEC_SRLOCK0_SRLOCK0			(0x1u<<0)

#define	BSEC_SRLOCK0_SRLOCK31_B_0X0		(0x0u<<31)
#define	BSEC_SRLOCK0_SRLOCK31_B_0X1		(0x1u<<31)
#define	BSEC_SRLOCK0_SRLOCK30_B_0X0		(0x0u<<30)
#define	BSEC_SRLOCK0_SRLOCK30_B_0X1		(0x1u<<30)
#define	BSEC_SRLOCK0_SRLOCK29_B_0X0		(0x0u<<29)
#define	BSEC_SRLOCK0_SRLOCK29_B_0X1		(0x1u<<29)
#define	BSEC_SRLOCK0_SRLOCK28_B_0X0		(0x0u<<28)
#define	BSEC_SRLOCK0_SRLOCK28_B_0X1		(0x1u<<28)
#define	BSEC_SRLOCK0_SRLOCK27_B_0X0		(0x0u<<27)
#define	BSEC_SRLOCK0_SRLOCK27_B_0X1		(0x1u<<27)
#define	BSEC_SRLOCK0_SRLOCK26_B_0X0		(0x0u<<26)
#define	BSEC_SRLOCK0_SRLOCK26_B_0X1		(0x1u<<26)
#define	BSEC_SRLOCK0_SRLOCK25_B_0X0		(0x0u<<25)
#define	BSEC_SRLOCK0_SRLOCK25_B_0X1		(0x1u<<25)
#define	BSEC_SRLOCK0_SRLOCK24_B_0X0		(0x0u<<24)
#define	BSEC_SRLOCK0_SRLOCK24_B_0X1		(0x1u<<24)
#define	BSEC_SRLOCK0_SRLOCK23_B_0X0		(0x0u<<23)
#define	BSEC_SRLOCK0_SRLOCK23_B_0X1		(0x1u<<23)
#define	BSEC_SRLOCK0_SRLOCK22_B_0X0		(0x0u<<22)
#define	BSEC_SRLOCK0_SRLOCK22_B_0X1		(0x1u<<22)
#define	BSEC_SRLOCK0_SRLOCK21_B_0X0		(0x0u<<21)
#define	BSEC_SRLOCK0_SRLOCK21_B_0X1		(0x1u<<21)
#define	BSEC_SRLOCK0_SRLOCK20_B_0X0		(0x0u<<20)
#define	BSEC_SRLOCK0_SRLOCK20_B_0X1		(0x1u<<20)
#define	BSEC_SRLOCK0_SRLOCK19_B_0X0		(0x0u<<19)
#define	BSEC_SRLOCK0_SRLOCK19_B_0X1		(0x1u<<19)
#define	BSEC_SRLOCK0_SRLOCK18_B_0X0		(0x0u<<18)
#define	BSEC_SRLOCK0_SRLOCK18_B_0X1		(0x1u<<18)
#define	BSEC_SRLOCK0_SRLOCK17_B_0X0		(0x0u<<17)
#define	BSEC_SRLOCK0_SRLOCK17_B_0X1		(0x1u<<17)
#define	BSEC_SRLOCK0_SRLOCK16_B_0X0		(0x0u<<16)
#define	BSEC_SRLOCK0_SRLOCK16_B_0X1		(0x1u<<16)
#define	BSEC_SRLOCK0_SRLOCK15_B_0X0		(0x0u<<15)
#define	BSEC_SRLOCK0_SRLOCK15_B_0X1		(0x1u<<15)
#define	BSEC_SRLOCK0_SRLOCK14_B_0X0		(0x0u<<14)
#define	BSEC_SRLOCK0_SRLOCK14_B_0X1		(0x1u<<14)
#define	BSEC_SRLOCK0_SRLOCK13_B_0X0		(0x0u<<13)
#define	BSEC_SRLOCK0_SRLOCK13_B_0X1		(0x1u<<13)
#define	BSEC_SRLOCK0_SRLOCK12_B_0X0		(0x0u<<12)
#define	BSEC_SRLOCK0_SRLOCK12_B_0X1		(0x1u<<12)
#define	BSEC_SRLOCK0_SRLOCK11_B_0X0		(0x0u<<11)
#define	BSEC_SRLOCK0_SRLOCK11_B_0X1		(0x1u<<11)
#define	BSEC_SRLOCK0_SRLOCK10_B_0X0		(0x0u<<10)
#define	BSEC_SRLOCK0_SRLOCK10_B_0X1		(0x1u<<10)
#define	BSEC_SRLOCK0_SRLOCK9_B_0X0		(0x0u<<9)
#define	BSEC_SRLOCK0_SRLOCK9_B_0X1		(0x1u<<9)
#define	BSEC_SRLOCK0_SRLOCK8_B_0X0		(0x0u<<8)
#define	BSEC_SRLOCK0_SRLOCK8_B_0X1		(0x1u<<8)
#define	BSEC_SRLOCK0_SRLOCK7_B_0X0		(0x0u<<7)
#define	BSEC_SRLOCK0_SRLOCK7_B_0X1		(0x1u<<7)
#define	BSEC_SRLOCK0_SRLOCK6_B_0X0		(0x0u<<6)
#define	BSEC_SRLOCK0_SRLOCK6_B_0X1		(0x1u<<6)
#define	BSEC_SRLOCK0_SRLOCK5_B_0X0		(0x0u<<5)
#define	BSEC_SRLOCK0_SRLOCK5_B_0X1		(0x1u<<5)
#define	BSEC_SRLOCK0_SRLOCK4_B_0X0		(0x0u<<4)
#define	BSEC_SRLOCK0_SRLOCK4_B_0X1		(0x1u<<4)
#define	BSEC_SRLOCK0_SRLOCK3_B_0X0		(0x0u<<3)
#define	BSEC_SRLOCK0_SRLOCK3_B_0X1		(0x1u<<3)
#define	BSEC_SRLOCK0_SRLOCK2_B_0X0		(0x0u<<2)
#define	BSEC_SRLOCK0_SRLOCK2_B_0X1		(0x1u<<2)
#define	BSEC_SRLOCK0_SRLOCK1_B_0X0		(0x0u<<1)
#define	BSEC_SRLOCK0_SRLOCK1_B_0X1		(0x1u<<1)
#define	BSEC_SRLOCK0_SRLOCK0_B_0X0		(0x0u<<0)
#define	BSEC_SRLOCK0_SRLOCK0_B_0X1		(0x1u<<0)

// SRLOCK1 Configuration

#define	BSEC_SRLOCK1_SRLOCK63			(0x1u<<31)
#define	BSEC_SRLOCK1_SRLOCK62			(0x1u<<30)
#define	BSEC_SRLOCK1_SRLOCK61			(0x1u<<29)
#define	BSEC_SRLOCK1_SRLOCK60			(0x1u<<28)
#define	BSEC_SRLOCK1_SRLOCK59			(0x1u<<27)
#define	BSEC_SRLOCK1_SRLOCK58			(0x1u<<26)
#define	BSEC_SRLOCK1_SRLOCK57			(0x1u<<25)
#define	BSEC_SRLOCK1_SRLOCK56			(0x1u<<24)
#define	BSEC_SRLOCK1_SRLOCK55			(0x1u<<23)
#define	BSEC_SRLOCK1_SRLOCK54			(0x1u<<22)
#define	BSEC_SRLOCK1_SRLOCK53			(0x1u<<21)
#define	BSEC_SRLOCK1_SRLOCK52			(0x1u<<20)
#define	BSEC_SRLOCK1_SRLOCK51			(0x1u<<19)
#define	BSEC_SRLOCK1_SRLOCK50			(0x1u<<18)
#define	BSEC_SRLOCK1_SRLOCK49			(0x1u<<17)
#define	BSEC_SRLOCK1_SRLOCK48			(0x1u<<16)
#define	BSEC_SRLOCK1_SRLOCK47			(0x1u<<15)
#define	BSEC_SRLOCK1_SRLOCK46			(0x1u<<14)
#define	BSEC_SRLOCK1_SRLOCK45			(0x1u<<13)
#define	BSEC_SRLOCK1_SRLOCK44			(0x1u<<12)
#define	BSEC_SRLOCK1_SRLOCK43			(0x1u<<11)
#define	BSEC_SRLOCK1_SRLOCK42			(0x1u<<10)
#define	BSEC_SRLOCK1_SRLOCK41			(0x1u<<9)
#define	BSEC_SRLOCK1_SRLOCK40			(0x1u<<8)
#define	BSEC_SRLOCK1_SRLOCK39			(0x1u<<7)
#define	BSEC_SRLOCK1_SRLOCK38			(0x1u<<6)
#define	BSEC_SRLOCK1_SRLOCK37			(0x1u<<5)
#define	BSEC_SRLOCK1_SRLOCK36			(0x1u<<4)
#define	BSEC_SRLOCK1_SRLOCK35			(0x1u<<3)
#define	BSEC_SRLOCK1_SRLOCK34			(0x1u<<2)
#define	BSEC_SRLOCK1_SRLOCK33			(0x1u<<1)
#define	BSEC_SRLOCK1_SRLOCK32			(0x1u<<0)

#define	BSEC_SRLOCK1_SRLOCK63_B_0X0		(0x0u<<31)
#define	BSEC_SRLOCK1_SRLOCK63_B_0X1		(0x1u<<31)
#define	BSEC_SRLOCK1_SRLOCK62_B_0X0		(0x0u<<30)
#define	BSEC_SRLOCK1_SRLOCK62_B_0X1		(0x1u<<30)
#define	BSEC_SRLOCK1_SRLOCK61_B_0X0		(0x0u<<29)
#define	BSEC_SRLOCK1_SRLOCK61_B_0X1		(0x1u<<29)
#define	BSEC_SRLOCK1_SRLOCK60_B_0X0		(0x0u<<28)
#define	BSEC_SRLOCK1_SRLOCK60_B_0X1		(0x1u<<28)
#define	BSEC_SRLOCK1_SRLOCK59_B_0X0		(0x0u<<27)
#define	BSEC_SRLOCK1_SRLOCK59_B_0X1		(0x1u<<27)
#define	BSEC_SRLOCK1_SRLOCK58_B_0X0		(0x0u<<26)
#define	BSEC_SRLOCK1_SRLOCK58_B_0X1		(0x1u<<26)
#define	BSEC_SRLOCK1_SRLOCK57_B_0X0		(0x0u<<25)
#define	BSEC_SRLOCK1_SRLOCK57_B_0X1		(0x1u<<25)
#define	BSEC_SRLOCK1_SRLOCK56_B_0X0		(0x0u<<24)
#define	BSEC_SRLOCK1_SRLOCK56_B_0X1		(0x1u<<24)
#define	BSEC_SRLOCK1_SRLOCK55_B_0X0		(0x0u<<23)
#define	BSEC_SRLOCK1_SRLOCK55_B_0X1		(0x1u<<23)
#define	BSEC_SRLOCK1_SRLOCK54_B_0X0		(0x0u<<22)
#define	BSEC_SRLOCK1_SRLOCK54_B_0X1		(0x1u<<22)
#define	BSEC_SRLOCK1_SRLOCK53_B_0X0		(0x0u<<21)
#define	BSEC_SRLOCK1_SRLOCK53_B_0X1		(0x1u<<21)
#define	BSEC_SRLOCK1_SRLOCK52_B_0X0		(0x0u<<20)
#define	BSEC_SRLOCK1_SRLOCK52_B_0X1		(0x1u<<20)
#define	BSEC_SRLOCK1_SRLOCK51_B_0X0		(0x0u<<19)
#define	BSEC_SRLOCK1_SRLOCK51_B_0X1		(0x1u<<19)
#define	BSEC_SRLOCK1_SRLOCK50_B_0X0		(0x0u<<18)
#define	BSEC_SRLOCK1_SRLOCK50_B_0X1		(0x1u<<18)
#define	BSEC_SRLOCK1_SRLOCK49_B_0X0		(0x0u<<17)
#define	BSEC_SRLOCK1_SRLOCK49_B_0X1		(0x1u<<17)
#define	BSEC_SRLOCK1_SRLOCK48_B_0X0		(0x0u<<16)
#define	BSEC_SRLOCK1_SRLOCK48_B_0X1		(0x1u<<16)
#define	BSEC_SRLOCK1_SRLOCK47_B_0X0		(0x0u<<15)
#define	BSEC_SRLOCK1_SRLOCK47_B_0X1		(0x1u<<15)
#define	BSEC_SRLOCK1_SRLOCK46_B_0X0		(0x0u<<14)
#define	BSEC_SRLOCK1_SRLOCK46_B_0X1		(0x1u<<14)
#define	BSEC_SRLOCK1_SRLOCK45_B_0X0		(0x0u<<13)
#define	BSEC_SRLOCK1_SRLOCK45_B_0X1		(0x1u<<13)
#define	BSEC_SRLOCK1_SRLOCK44_B_0X0		(0x0u<<12)
#define	BSEC_SRLOCK1_SRLOCK44_B_0X1		(0x1u<<12)
#define	BSEC_SRLOCK1_SRLOCK43_B_0X0		(0x0u<<11)
#define	BSEC_SRLOCK1_SRLOCK43_B_0X1		(0x1u<<11)
#define	BSEC_SRLOCK1_SRLOCK42_B_0X0		(0x0u<<10)
#define	BSEC_SRLOCK1_SRLOCK42_B_0X1		(0x1u<<10)
#define	BSEC_SRLOCK1_SRLOCK41_B_0X0		(0x0u<<9)
#define	BSEC_SRLOCK1_SRLOCK41_B_0X1		(0x1u<<9)
#define	BSEC_SRLOCK1_SRLOCK40_B_0X0		(0x0u<<8)
#define	BSEC_SRLOCK1_SRLOCK40_B_0X1		(0x1u<<8)
#define	BSEC_SRLOCK1_SRLOCK39_B_0X0		(0x0u<<7)
#define	BSEC_SRLOCK1_SRLOCK39_B_0X1		(0x1u<<7)
#define	BSEC_SRLOCK1_SRLOCK38_B_0X0		(0x0u<<6)
#define	BSEC_SRLOCK1_SRLOCK38_B_0X1		(0x1u<<6)
#define	BSEC_SRLOCK1_SRLOCK37_B_0X0		(0x0u<<5)
#define	BSEC_SRLOCK1_SRLOCK37_B_0X1		(0x1u<<5)
#define	BSEC_SRLOCK1_SRLOCK36_B_0X0		(0x0u<<4)
#define	BSEC_SRLOCK1_SRLOCK36_B_0X1		(0x1u<<4)
#define	BSEC_SRLOCK1_SRLOCK35_B_0X0		(0x0u<<3)
#define	BSEC_SRLOCK1_SRLOCK35_B_0X1		(0x1u<<3)
#define	BSEC_SRLOCK1_SRLOCK34_B_0X0		(0x0u<<2)
#define	BSEC_SRLOCK1_SRLOCK34_B_0X1		(0x1u<<2)
#define	BSEC_SRLOCK1_SRLOCK33_B_0X0		(0x0u<<1)
#define	BSEC_SRLOCK1_SRLOCK33_B_0X1		(0x1u<<1)
#define	BSEC_SRLOCK1_SRLOCK32_B_0X0		(0x0u<<0)
#define	BSEC_SRLOCK1_SRLOCK32_B_0X1		(0x1u<<0)

// SRLOCK2 Configuration

#define	BSEC_SRLOCK2_SRLOCK95			(0x1u<<31)
#define	BSEC_SRLOCK2_SRLOCK94			(0x1u<<30)
#define	BSEC_SRLOCK2_SRLOCK93			(0x1u<<29)
#define	BSEC_SRLOCK2_SRLOCK92			(0x1u<<28)
#define	BSEC_SRLOCK2_SRLOCK91			(0x1u<<27)
#define	BSEC_SRLOCK2_SRLOCK90			(0x1u<<26)
#define	BSEC_SRLOCK2_SRLOCK89			(0x1u<<25)
#define	BSEC_SRLOCK2_SRLOCK88			(0x1u<<24)
#define	BSEC_SRLOCK2_SRLOCK87			(0x1u<<23)
#define	BSEC_SRLOCK2_SRLOCK86			(0x1u<<22)
#define	BSEC_SRLOCK2_SRLOCK85			(0x1u<<21)
#define	BSEC_SRLOCK2_SRLOCK84			(0x1u<<20)
#define	BSEC_SRLOCK2_SRLOCK83			(0x1u<<19)
#define	BSEC_SRLOCK2_SRLOCK82			(0x1u<<18)
#define	BSEC_SRLOCK2_SRLOCK81			(0x1u<<17)
#define	BSEC_SRLOCK2_SRLOCK80			(0x1u<<16)
#define	BSEC_SRLOCK2_SRLOCK79			(0x1u<<15)
#define	BSEC_SRLOCK2_SRLOCK78			(0x1u<<14)
#define	BSEC_SRLOCK2_SRLOCK77			(0x1u<<13)
#define	BSEC_SRLOCK2_SRLOCK76			(0x1u<<12)
#define	BSEC_SRLOCK2_SRLOCK75			(0x1u<<11)
#define	BSEC_SRLOCK2_SRLOCK74			(0x1u<<10)
#define	BSEC_SRLOCK2_SRLOCK73			(0x1u<<9)
#define	BSEC_SRLOCK2_SRLOCK72			(0x1u<<8)
#define	BSEC_SRLOCK2_SRLOCK71			(0x1u<<7)
#define	BSEC_SRLOCK2_SRLOCK70			(0x1u<<6)
#define	BSEC_SRLOCK2_SRLOCK69			(0x1u<<5)
#define	BSEC_SRLOCK2_SRLOCK68			(0x1u<<4)
#define	BSEC_SRLOCK2_SRLOCK67			(0x1u<<3)
#define	BSEC_SRLOCK2_SRLOCK66			(0x1u<<2)
#define	BSEC_SRLOCK2_SRLOCK65			(0x1u<<1)
#define	BSEC_SRLOCK2_SRLOCK64			(0x1u<<0)

#define	BSEC_SRLOCK2_SRLOCK95_B_0X0		(0x0u<<31)
#define	BSEC_SRLOCK2_SRLOCK95_B_0X1		(0x1u<<31)
#define	BSEC_SRLOCK2_SRLOCK94_B_0X0		(0x0u<<30)
#define	BSEC_SRLOCK2_SRLOCK94_B_0X1		(0x1u<<30)
#define	BSEC_SRLOCK2_SRLOCK93_B_0X0		(0x0u<<29)
#define	BSEC_SRLOCK2_SRLOCK93_B_0X1		(0x1u<<29)
#define	BSEC_SRLOCK2_SRLOCK92_B_0X0		(0x0u<<28)
#define	BSEC_SRLOCK2_SRLOCK92_B_0X1		(0x1u<<28)
#define	BSEC_SRLOCK2_SRLOCK91_B_0X0		(0x0u<<27)
#define	BSEC_SRLOCK2_SRLOCK91_B_0X1		(0x1u<<27)
#define	BSEC_SRLOCK2_SRLOCK90_B_0X0		(0x0u<<26)
#define	BSEC_SRLOCK2_SRLOCK90_B_0X1		(0x1u<<26)
#define	BSEC_SRLOCK2_SRLOCK89_B_0X0		(0x0u<<25)
#define	BSEC_SRLOCK2_SRLOCK89_B_0X1		(0x1u<<25)
#define	BSEC_SRLOCK2_SRLOCK88_B_0X0		(0x0u<<24)
#define	BSEC_SRLOCK2_SRLOCK88_B_0X1		(0x1u<<24)
#define	BSEC_SRLOCK2_SRLOCK87_B_0X0		(0x0u<<23)
#define	BSEC_SRLOCK2_SRLOCK87_B_0X1		(0x1u<<23)
#define	BSEC_SRLOCK2_SRLOCK86_B_0X0		(0x0u<<22)
#define	BSEC_SRLOCK2_SRLOCK86_B_0X1		(0x1u<<22)
#define	BSEC_SRLOCK2_SRLOCK85_B_0X0		(0x0u<<21)
#define	BSEC_SRLOCK2_SRLOCK85_B_0X1		(0x1u<<21)
#define	BSEC_SRLOCK2_SRLOCK84_B_0X0		(0x0u<<20)
#define	BSEC_SRLOCK2_SRLOCK84_B_0X1		(0x1u<<20)
#define	BSEC_SRLOCK2_SRLOCK83_B_0X0		(0x0u<<19)
#define	BSEC_SRLOCK2_SRLOCK83_B_0X1		(0x1u<<19)
#define	BSEC_SRLOCK2_SRLOCK82_B_0X0		(0x0u<<18)
#define	BSEC_SRLOCK2_SRLOCK82_B_0X1		(0x1u<<18)
#define	BSEC_SRLOCK2_SRLOCK81_B_0X0		(0x0u<<17)
#define	BSEC_SRLOCK2_SRLOCK81_B_0X1		(0x1u<<17)
#define	BSEC_SRLOCK2_SRLOCK80_B_0X0		(0x0u<<16)
#define	BSEC_SRLOCK2_SRLOCK80_B_0X1		(0x1u<<16)
#define	BSEC_SRLOCK2_SRLOCK79_B_0X0		(0x0u<<15)
#define	BSEC_SRLOCK2_SRLOCK79_B_0X1		(0x1u<<15)
#define	BSEC_SRLOCK2_SRLOCK78_B_0X0		(0x0u<<14)
#define	BSEC_SRLOCK2_SRLOCK78_B_0X1		(0x1u<<14)
#define	BSEC_SRLOCK2_SRLOCK77_B_0X0		(0x0u<<13)
#define	BSEC_SRLOCK2_SRLOCK77_B_0X1		(0x1u<<13)
#define	BSEC_SRLOCK2_SRLOCK76_B_0X0		(0x0u<<12)
#define	BSEC_SRLOCK2_SRLOCK76_B_0X1		(0x1u<<12)
#define	BSEC_SRLOCK2_SRLOCK75_B_0X0		(0x0u<<11)
#define	BSEC_SRLOCK2_SRLOCK75_B_0X1		(0x1u<<11)
#define	BSEC_SRLOCK2_SRLOCK74_B_0X0		(0x0u<<10)
#define	BSEC_SRLOCK2_SRLOCK74_B_0X1		(0x1u<<10)
#define	BSEC_SRLOCK2_SRLOCK73_B_0X0		(0x0u<<9)
#define	BSEC_SRLOCK2_SRLOCK73_B_0X1		(0x1u<<9)
#define	BSEC_SRLOCK2_SRLOCK72_B_0X0		(0x0u<<8)
#define	BSEC_SRLOCK2_SRLOCK72_B_0X1		(0x1u<<8)
#define	BSEC_SRLOCK2_SRLOCK71_B_0X0		(0x0u<<7)
#define	BSEC_SRLOCK2_SRLOCK71_B_0X1		(0x1u<<7)
#define	BSEC_SRLOCK2_SRLOCK70_B_0X0		(0x0u<<6)
#define	BSEC_SRLOCK2_SRLOCK70_B_0X1		(0x1u<<6)
#define	BSEC_SRLOCK2_SRLOCK69_B_0X0		(0x0u<<5)
#define	BSEC_SRLOCK2_SRLOCK69_B_0X1		(0x1u<<5)
#define	BSEC_SRLOCK2_SRLOCK68_B_0X0		(0x0u<<4)
#define	BSEC_SRLOCK2_SRLOCK68_B_0X1		(0x1u<<4)
#define	BSEC_SRLOCK2_SRLOCK67_B_0X0		(0x0u<<3)
#define	BSEC_SRLOCK2_SRLOCK67_B_0X1		(0x1u<<3)
#define	BSEC_SRLOCK2_SRLOCK66_B_0X0		(0x0u<<2)
#define	BSEC_SRLOCK2_SRLOCK66_B_0X1		(0x1u<<2)
#define	BSEC_SRLOCK2_SRLOCK65_B_0X0		(0x0u<<1)
#define	BSEC_SRLOCK2_SRLOCK65_B_0X1		(0x1u<<1)
#define	BSEC_SRLOCK2_SRLOCK64_B_0X0		(0x0u<<0)
#define	BSEC_SRLOCK2_SRLOCK64_B_0X1		(0x1u<<0)

// SRLOCK3 Configuration

#define	BSEC_SRLOCK3_SRLOCK127			(0x1u<<31)
#define	BSEC_SRLOCK3_SRLOCK126			(0x1u<<30)
#define	BSEC_SRLOCK3_SRLOCK125			(0x1u<<29)
#define	BSEC_SRLOCK3_SRLOCK124			(0x1u<<28)
#define	BSEC_SRLOCK3_SRLOCK123			(0x1u<<27)
#define	BSEC_SRLOCK3_SRLOCK122			(0x1u<<26)
#define	BSEC_SRLOCK3_SRLOCK121			(0x1u<<25)
#define	BSEC_SRLOCK3_SRLOCK120			(0x1u<<24)
#define	BSEC_SRLOCK3_SRLOCK119			(0x1u<<23)
#define	BSEC_SRLOCK3_SRLOCK118			(0x1u<<22)
#define	BSEC_SRLOCK3_SRLOCK117			(0x1u<<21)
#define	BSEC_SRLOCK3_SRLOCK116			(0x1u<<20)
#define	BSEC_SRLOCK3_SRLOCK115			(0x1u<<19)
#define	BSEC_SRLOCK3_SRLOCK114			(0x1u<<18)
#define	BSEC_SRLOCK3_SRLOCK113			(0x1u<<17)
#define	BSEC_SRLOCK3_SRLOCK112			(0x1u<<16)
#define	BSEC_SRLOCK3_SRLOCK111			(0x1u<<15)
#define	BSEC_SRLOCK3_SRLOCK110			(0x1u<<14)
#define	BSEC_SRLOCK3_SRLOCK109			(0x1u<<13)
#define	BSEC_SRLOCK3_SRLOCK108			(0x1u<<12)
#define	BSEC_SRLOCK3_SRLOCK107			(0x1u<<11)
#define	BSEC_SRLOCK3_SRLOCK106			(0x1u<<10)
#define	BSEC_SRLOCK3_SRLOCK105			(0x1u<<9)
#define	BSEC_SRLOCK3_SRLOCK104			(0x1u<<8)
#define	BSEC_SRLOCK3_SRLOCK103			(0x1u<<7)
#define	BSEC_SRLOCK3_SRLOCK102			(0x1u<<6)
#define	BSEC_SRLOCK3_SRLOCK101			(0x1u<<5)
#define	BSEC_SRLOCK3_SRLOCK100			(0x1u<<4)
#define	BSEC_SRLOCK3_SRLOCK99			(0x1u<<3)
#define	BSEC_SRLOCK3_SRLOCK98			(0x1u<<2)
#define	BSEC_SRLOCK3_SRLOCK97			(0x1u<<1)
#define	BSEC_SRLOCK3_SRLOCK96			(0x1u<<0)

#define	BSEC_SRLOCK3_SRLOCK127_B_0X0	(0x0u<<31)
#define	BSEC_SRLOCK3_SRLOCK127_B_0X1	(0x1u<<31)
#define	BSEC_SRLOCK3_SRLOCK126_B_0X0	(0x0u<<30)
#define	BSEC_SRLOCK3_SRLOCK126_B_0X1	(0x1u<<30)
#define	BSEC_SRLOCK3_SRLOCK125_B_0X0	(0x0u<<29)
#define	BSEC_SRLOCK3_SRLOCK125_B_0X1	(0x1u<<29)
#define	BSEC_SRLOCK3_SRLOCK124_B_0X0	(0x0u<<28)
#define	BSEC_SRLOCK3_SRLOCK124_B_0X1	(0x1u<<28)
#define	BSEC_SRLOCK3_SRLOCK123_B_0X0	(0x0u<<27)
#define	BSEC_SRLOCK3_SRLOCK123_B_0X1	(0x1u<<27)
#define	BSEC_SRLOCK3_SRLOCK122_B_0X0	(0x0u<<26)
#define	BSEC_SRLOCK3_SRLOCK122_B_0X1	(0x1u<<26)
#define	BSEC_SRLOCK3_SRLOCK121_B_0X0	(0x0u<<25)
#define	BSEC_SRLOCK3_SRLOCK121_B_0X1	(0x1u<<25)
#define	BSEC_SRLOCK3_SRLOCK120_B_0X0	(0x0u<<24)
#define	BSEC_SRLOCK3_SRLOCK120_B_0X1	(0x1u<<24)
#define	BSEC_SRLOCK3_SRLOCK119_B_0X0	(0x0u<<23)
#define	BSEC_SRLOCK3_SRLOCK119_B_0X1	(0x1u<<23)
#define	BSEC_SRLOCK3_SRLOCK118_B_0X0	(0x0u<<22)
#define	BSEC_SRLOCK3_SRLOCK118_B_0X1	(0x1u<<22)
#define	BSEC_SRLOCK3_SRLOCK117_B_0X0	(0x0u<<21)
#define	BSEC_SRLOCK3_SRLOCK117_B_0X1	(0x1u<<21)
#define	BSEC_SRLOCK3_SRLOCK116_B_0X0	(0x0u<<20)
#define	BSEC_SRLOCK3_SRLOCK116_B_0X1	(0x1u<<20)
#define	BSEC_SRLOCK3_SRLOCK115_B_0X0	(0x0u<<19)
#define	BSEC_SRLOCK3_SRLOCK115_B_0X1	(0x1u<<19)
#define	BSEC_SRLOCK3_SRLOCK114_B_0X0	(0x0u<<18)
#define	BSEC_SRLOCK3_SRLOCK114_B_0X1	(0x1u<<18)
#define	BSEC_SRLOCK3_SRLOCK113_B_0X0	(0x0u<<17)
#define	BSEC_SRLOCK3_SRLOCK113_B_0X1	(0x1u<<17)
#define	BSEC_SRLOCK3_SRLOCK112_B_0X0	(0x0u<<16)
#define	BSEC_SRLOCK3_SRLOCK112_B_0X1	(0x1u<<16)
#define	BSEC_SRLOCK3_SRLOCK111_B_0X0	(0x0u<<15)
#define	BSEC_SRLOCK3_SRLOCK111_B_0X1	(0x1u<<15)
#define	BSEC_SRLOCK3_SRLOCK110_B_0X0	(0x0u<<14)
#define	BSEC_SRLOCK3_SRLOCK110_B_0X1	(0x1u<<14)
#define	BSEC_SRLOCK3_SRLOCK109_B_0X0	(0x0u<<13)
#define	BSEC_SRLOCK3_SRLOCK109_B_0X1	(0x1u<<13)
#define	BSEC_SRLOCK3_SRLOCK108_B_0X0	(0x0u<<12)
#define	BSEC_SRLOCK3_SRLOCK108_B_0X1	(0x1u<<12)
#define	BSEC_SRLOCK3_SRLOCK107_B_0X0	(0x0u<<11)
#define	BSEC_SRLOCK3_SRLOCK107_B_0X1	(0x1u<<11)
#define	BSEC_SRLOCK3_SRLOCK106_B_0X0	(0x0u<<10)
#define	BSEC_SRLOCK3_SRLOCK106_B_0X1	(0x1u<<10)
#define	BSEC_SRLOCK3_SRLOCK105_B_0X0	(0x0u<<9)
#define	BSEC_SRLOCK3_SRLOCK105_B_0X1	(0x1u<<9)
#define	BSEC_SRLOCK3_SRLOCK104_B_0X0	(0x0u<<8)
#define	BSEC_SRLOCK3_SRLOCK104_B_0X1	(0x1u<<8)
#define	BSEC_SRLOCK3_SRLOCK103_B_0X0	(0x0u<<7)
#define	BSEC_SRLOCK3_SRLOCK103_B_0X1	(0x1u<<7)
#define	BSEC_SRLOCK3_SRLOCK102_B_0X0	(0x0u<<6)
#define	BSEC_SRLOCK3_SRLOCK102_B_0X1	(0x1u<<6)
#define	BSEC_SRLOCK3_SRLOCK101_B_0X0	(0x0u<<5)
#define	BSEC_SRLOCK3_SRLOCK101_B_0X1	(0x1u<<5)
#define	BSEC_SRLOCK3_SRLOCK100_B_0X0	(0x0u<<4)
#define	BSEC_SRLOCK3_SRLOCK100_B_0X1	(0x1u<<4)
#define	BSEC_SRLOCK3_SRLOCK99_B_0X0		(0x0u<<3)
#define	BSEC_SRLOCK3_SRLOCK99_B_0X1		(0x1u<<3)
#define	BSEC_SRLOCK3_SRLOCK98_B_0X0		(0x0u<<2)
#define	BSEC_SRLOCK3_SRLOCK98_B_0X1		(0x1u<<2)
#define	BSEC_SRLOCK3_SRLOCK97_B_0X0		(0x0u<<1)
#define	BSEC_SRLOCK3_SRLOCK97_B_0X1		(0x1u<<1)
#define	BSEC_SRLOCK3_SRLOCK96_B_0X0		(0x0u<<0)
#define	BSEC_SRLOCK3_SRLOCK96_B_0X1		(0x1u<<0)

// SRLOCK4 Configuration

#define	BSEC_SRLOCK4_SRLOCK159			(0x1u<<31)
#define	BSEC_SRLOCK4_SRLOCK158			(0x1u<<30)
#define	BSEC_SRLOCK4_SRLOCK157			(0x1u<<29)
#define	BSEC_SRLOCK4_SRLOCK156			(0x1u<<28)
#define	BSEC_SRLOCK4_SRLOCK155			(0x1u<<27)
#define	BSEC_SRLOCK4_SRLOCK154			(0x1u<<26)
#define	BSEC_SRLOCK4_SRLOCK153			(0x1u<<25)
#define	BSEC_SRLOCK4_SRLOCK152			(0x1u<<24)
#define	BSEC_SRLOCK4_SRLOCK151			(0x1u<<23)
#define	BSEC_SRLOCK4_SRLOCK150			(0x1u<<22)
#define	BSEC_SRLOCK4_SRLOCK149			(0x1u<<21)
#define	BSEC_SRLOCK4_SRLOCK148			(0x1u<<20)
#define	BSEC_SRLOCK4_SRLOCK147			(0x1u<<19)
#define	BSEC_SRLOCK4_SRLOCK146			(0x1u<<18)
#define	BSEC_SRLOCK4_SRLOCK145			(0x1u<<17)
#define	BSEC_SRLOCK4_SRLOCK144			(0x1u<<16)
#define	BSEC_SRLOCK4_SRLOCK143			(0x1u<<15)
#define	BSEC_SRLOCK4_SRLOCK142			(0x1u<<14)
#define	BSEC_SRLOCK4_SRLOCK141			(0x1u<<13)
#define	BSEC_SRLOCK4_SRLOCK140			(0x1u<<12)
#define	BSEC_SRLOCK4_SRLOCK139			(0x1u<<11)
#define	BSEC_SRLOCK4_SRLOCK138			(0x1u<<10)
#define	BSEC_SRLOCK4_SRLOCK137			(0x1u<<9)
#define	BSEC_SRLOCK4_SRLOCK136			(0x1u<<8)
#define	BSEC_SRLOCK4_SRLOCK135			(0x1u<<7)
#define	BSEC_SRLOCK4_SRLOCK134			(0x1u<<6)
#define	BSEC_SRLOCK4_SRLOCK133			(0x1u<<5)
#define	BSEC_SRLOCK4_SRLOCK132			(0x1u<<4)
#define	BSEC_SRLOCK4_SRLOCK131			(0x1u<<3)
#define	BSEC_SRLOCK4_SRLOCK130			(0x1u<<2)
#define	BSEC_SRLOCK4_SRLOCK129			(0x1u<<1)
#define	BSEC_SRLOCK4_SRLOCK128			(0x1u<<0)

#define	BSEC_SRLOCK4_SRLOCK159_B_0X0	(0x0u<<31)
#define	BSEC_SRLOCK4_SRLOCK159_B_0X1	(0x1u<<31)
#define	BSEC_SRLOCK4_SRLOCK158_B_0X0	(0x0u<<30)
#define	BSEC_SRLOCK4_SRLOCK158_B_0X1	(0x1u<<30)
#define	BSEC_SRLOCK4_SRLOCK157_B_0X0	(0x0u<<29)
#define	BSEC_SRLOCK4_SRLOCK157_B_0X1	(0x1u<<29)
#define	BSEC_SRLOCK4_SRLOCK156_B_0X0	(0x0u<<28)
#define	BSEC_SRLOCK4_SRLOCK156_B_0X1	(0x1u<<28)
#define	BSEC_SRLOCK4_SRLOCK155_B_0X0	(0x0u<<27)
#define	BSEC_SRLOCK4_SRLOCK155_B_0X1	(0x1u<<27)
#define	BSEC_SRLOCK4_SRLOCK154_B_0X0	(0x0u<<26)
#define	BSEC_SRLOCK4_SRLOCK154_B_0X1	(0x1u<<26)
#define	BSEC_SRLOCK4_SRLOCK153_B_0X0	(0x0u<<25)
#define	BSEC_SRLOCK4_SRLOCK153_B_0X1	(0x1u<<25)
#define	BSEC_SRLOCK4_SRLOCK152_B_0X0	(0x0u<<24)
#define	BSEC_SRLOCK4_SRLOCK152_B_0X1	(0x1u<<24)
#define	BSEC_SRLOCK4_SRLOCK151_B_0X0	(0x0u<<23)
#define	BSEC_SRLOCK4_SRLOCK151_B_0X1	(0x1u<<23)
#define	BSEC_SRLOCK4_SRLOCK150_B_0X0	(0x0u<<22)
#define	BSEC_SRLOCK4_SRLOCK150_B_0X1	(0x1u<<22)
#define	BSEC_SRLOCK4_SRLOCK149_B_0X0	(0x0u<<21)
#define	BSEC_SRLOCK4_SRLOCK149_B_0X1	(0x1u<<21)
#define	BSEC_SRLOCK4_SRLOCK148_B_0X0	(0x0u<<20)
#define	BSEC_SRLOCK4_SRLOCK148_B_0X1	(0x1u<<20)
#define	BSEC_SRLOCK4_SRLOCK147_B_0X0	(0x0u<<19)
#define	BSEC_SRLOCK4_SRLOCK147_B_0X1	(0x1u<<19)
#define	BSEC_SRLOCK4_SRLOCK146_B_0X0	(0x0u<<18)
#define	BSEC_SRLOCK4_SRLOCK146_B_0X1	(0x1u<<18)
#define	BSEC_SRLOCK4_SRLOCK145_B_0X0	(0x0u<<17)
#define	BSEC_SRLOCK4_SRLOCK145_B_0X1	(0x1u<<17)
#define	BSEC_SRLOCK4_SRLOCK144_B_0X0	(0x0u<<16)
#define	BSEC_SRLOCK4_SRLOCK144_B_0X1	(0x1u<<16)
#define	BSEC_SRLOCK4_SRLOCK143_B_0X0	(0x0u<<15)
#define	BSEC_SRLOCK4_SRLOCK143_B_0X1	(0x1u<<15)
#define	BSEC_SRLOCK4_SRLOCK142_B_0X0	(0x0u<<14)
#define	BSEC_SRLOCK4_SRLOCK142_B_0X1	(0x1u<<14)
#define	BSEC_SRLOCK4_SRLOCK141_B_0X0	(0x0u<<13)
#define	BSEC_SRLOCK4_SRLOCK141_B_0X1	(0x1u<<13)
#define	BSEC_SRLOCK4_SRLOCK140_B_0X0	(0x0u<<12)
#define	BSEC_SRLOCK4_SRLOCK140_B_0X1	(0x1u<<12)
#define	BSEC_SRLOCK4_SRLOCK139_B_0X0	(0x0u<<11)
#define	BSEC_SRLOCK4_SRLOCK139_B_0X1	(0x1u<<11)
#define	BSEC_SRLOCK4_SRLOCK138_B_0X0	(0x0u<<10)
#define	BSEC_SRLOCK4_SRLOCK138_B_0X1	(0x1u<<10)
#define	BSEC_SRLOCK4_SRLOCK137_B_0X0	(0x0u<<9)
#define	BSEC_SRLOCK4_SRLOCK137_B_0X1	(0x1u<<9)
#define	BSEC_SRLOCK4_SRLOCK136_B_0X0	(0x0u<<8)
#define	BSEC_SRLOCK4_SRLOCK136_B_0X1	(0x1u<<8)
#define	BSEC_SRLOCK4_SRLOCK135_B_0X0	(0x0u<<7)
#define	BSEC_SRLOCK4_SRLOCK135_B_0X1	(0x1u<<7)
#define	BSEC_SRLOCK4_SRLOCK134_B_0X0	(0x0u<<6)
#define	BSEC_SRLOCK4_SRLOCK134_B_0X1	(0x1u<<6)
#define	BSEC_SRLOCK4_SRLOCK133_B_0X0	(0x0u<<5)
#define	BSEC_SRLOCK4_SRLOCK133_B_0X1	(0x1u<<5)
#define	BSEC_SRLOCK4_SRLOCK132_B_0X0	(0x0u<<4)
#define	BSEC_SRLOCK4_SRLOCK132_B_0X1	(0x1u<<4)
#define	BSEC_SRLOCK4_SRLOCK131_B_0X0	(0x0u<<3)
#define	BSEC_SRLOCK4_SRLOCK131_B_0X1	(0x1u<<3)
#define	BSEC_SRLOCK4_SRLOCK130_B_0X0	(0x0u<<2)
#define	BSEC_SRLOCK4_SRLOCK130_B_0X1	(0x1u<<2)
#define	BSEC_SRLOCK4_SRLOCK129_B_0X0	(0x0u<<1)
#define	BSEC_SRLOCK4_SRLOCK129_B_0X1	(0x1u<<1)
#define	BSEC_SRLOCK4_SRLOCK128_B_0X0	(0x0u<<0)
#define	BSEC_SRLOCK4_SRLOCK128_B_0X1	(0x1u<<0)

// SRLOCK5 Configuration

#define	BSEC_SRLOCK5_SRLOCK191			(0x1u<<31)
#define	BSEC_SRLOCK5_SRLOCK190			(0x1u<<30)
#define	BSEC_SRLOCK5_SRLOCK189			(0x1u<<29)
#define	BSEC_SRLOCK5_SRLOCK188			(0x1u<<28)
#define	BSEC_SRLOCK5_SRLOCK187			(0x1u<<27)
#define	BSEC_SRLOCK5_SRLOCK186			(0x1u<<26)
#define	BSEC_SRLOCK5_SRLOCK185			(0x1u<<25)
#define	BSEC_SRLOCK5_SRLOCK184			(0x1u<<24)
#define	BSEC_SRLOCK5_SRLOCK183			(0x1u<<23)
#define	BSEC_SRLOCK5_SRLOCK182			(0x1u<<22)
#define	BSEC_SRLOCK5_SRLOCK181			(0x1u<<21)
#define	BSEC_SRLOCK5_SRLOCK180			(0x1u<<20)
#define	BSEC_SRLOCK5_SRLOCK179			(0x1u<<19)
#define	BSEC_SRLOCK5_SRLOCK178			(0x1u<<18)
#define	BSEC_SRLOCK5_SRLOCK177			(0x1u<<17)
#define	BSEC_SRLOCK5_SRLOCK176			(0x1u<<16)
#define	BSEC_SRLOCK5_SRLOCK175			(0x1u<<15)
#define	BSEC_SRLOCK5_SRLOCK174			(0x1u<<14)
#define	BSEC_SRLOCK5_SRLOCK173			(0x1u<<13)
#define	BSEC_SRLOCK5_SRLOCK172			(0x1u<<12)
#define	BSEC_SRLOCK5_SRLOCK171			(0x1u<<11)
#define	BSEC_SRLOCK5_SRLOCK170			(0x1u<<10)
#define	BSEC_SRLOCK5_SRLOCK169			(0x1u<<9)
#define	BSEC_SRLOCK5_SRLOCK168			(0x1u<<8)
#define	BSEC_SRLOCK5_SRLOCK167			(0x1u<<7)
#define	BSEC_SRLOCK5_SRLOCK166			(0x1u<<6)
#define	BSEC_SRLOCK5_SRLOCK165			(0x1u<<5)
#define	BSEC_SRLOCK5_SRLOCK164			(0x1u<<4)
#define	BSEC_SRLOCK5_SRLOCK163			(0x1u<<3)
#define	BSEC_SRLOCK5_SRLOCK162			(0x1u<<2)
#define	BSEC_SRLOCK5_SRLOCK161			(0x1u<<1)
#define	BSEC_SRLOCK5_SRLOCK160			(0x1u<<0)

#define	BSEC_SRLOCK5_SRLOCK191_B_0X0	(0x0u<<31)
#define	BSEC_SRLOCK5_SRLOCK191_B_0X1	(0x1u<<31)
#define	BSEC_SRLOCK5_SRLOCK190_B_0X0	(0x0u<<30)
#define	BSEC_SRLOCK5_SRLOCK190_B_0X1	(0x1u<<30)
#define	BSEC_SRLOCK5_SRLOCK189_B_0X0	(0x0u<<29)
#define	BSEC_SRLOCK5_SRLOCK189_B_0X1	(0x1u<<29)
#define	BSEC_SRLOCK5_SRLOCK188_B_0X0	(0x0u<<28)
#define	BSEC_SRLOCK5_SRLOCK188_B_0X1	(0x1u<<28)
#define	BSEC_SRLOCK5_SRLOCK187_B_0X0	(0x0u<<27)
#define	BSEC_SRLOCK5_SRLOCK187_B_0X1	(0x1u<<27)
#define	BSEC_SRLOCK5_SRLOCK186_B_0X0	(0x0u<<26)
#define	BSEC_SRLOCK5_SRLOCK186_B_0X1	(0x1u<<26)
#define	BSEC_SRLOCK5_SRLOCK185_B_0X0	(0x0u<<25)
#define	BSEC_SRLOCK5_SRLOCK185_B_0X1	(0x1u<<25)
#define	BSEC_SRLOCK5_SRLOCK184_B_0X0	(0x0u<<24)
#define	BSEC_SRLOCK5_SRLOCK184_B_0X1	(0x1u<<24)
#define	BSEC_SRLOCK5_SRLOCK183_B_0X0	(0x0u<<23)
#define	BSEC_SRLOCK5_SRLOCK183_B_0X1	(0x1u<<23)
#define	BSEC_SRLOCK5_SRLOCK182_B_0X0	(0x0u<<22)
#define	BSEC_SRLOCK5_SRLOCK182_B_0X1	(0x1u<<22)
#define	BSEC_SRLOCK5_SRLOCK181_B_0X0	(0x0u<<21)
#define	BSEC_SRLOCK5_SRLOCK181_B_0X1	(0x1u<<21)
#define	BSEC_SRLOCK5_SRLOCK180_B_0X0	(0x0u<<20)
#define	BSEC_SRLOCK5_SRLOCK180_B_0X1	(0x1u<<20)
#define	BSEC_SRLOCK5_SRLOCK179_B_0X0	(0x0u<<19)
#define	BSEC_SRLOCK5_SRLOCK179_B_0X1	(0x1u<<19)
#define	BSEC_SRLOCK5_SRLOCK178_B_0X0	(0x0u<<18)
#define	BSEC_SRLOCK5_SRLOCK178_B_0X1	(0x1u<<18)
#define	BSEC_SRLOCK5_SRLOCK177_B_0X0	(0x0u<<17)
#define	BSEC_SRLOCK5_SRLOCK177_B_0X1	(0x1u<<17)
#define	BSEC_SRLOCK5_SRLOCK176_B_0X0	(0x0u<<16)
#define	BSEC_SRLOCK5_SRLOCK176_B_0X1	(0x1u<<16)
#define	BSEC_SRLOCK5_SRLOCK175_B_0X0	(0x0u<<15)
#define	BSEC_SRLOCK5_SRLOCK175_B_0X1	(0x1u<<15)
#define	BSEC_SRLOCK5_SRLOCK174_B_0X0	(0x0u<<14)
#define	BSEC_SRLOCK5_SRLOCK174_B_0X1	(0x1u<<14)
#define	BSEC_SRLOCK5_SRLOCK173_B_0X0	(0x0u<<13)
#define	BSEC_SRLOCK5_SRLOCK173_B_0X1	(0x1u<<13)
#define	BSEC_SRLOCK5_SRLOCK172_B_0X0	(0x0u<<12)
#define	BSEC_SRLOCK5_SRLOCK172_B_0X1	(0x1u<<12)
#define	BSEC_SRLOCK5_SRLOCK171_B_0X0	(0x0u<<11)
#define	BSEC_SRLOCK5_SRLOCK171_B_0X1	(0x1u<<11)
#define	BSEC_SRLOCK5_SRLOCK170_B_0X0	(0x0u<<10)
#define	BSEC_SRLOCK5_SRLOCK170_B_0X1	(0x1u<<10)
#define	BSEC_SRLOCK5_SRLOCK169_B_0X0	(0x0u<<9)
#define	BSEC_SRLOCK5_SRLOCK169_B_0X1	(0x1u<<9)
#define	BSEC_SRLOCK5_SRLOCK168_B_0X0	(0x0u<<8)
#define	BSEC_SRLOCK5_SRLOCK168_B_0X1	(0x1u<<8)
#define	BSEC_SRLOCK5_SRLOCK167_B_0X0	(0x0u<<7)
#define	BSEC_SRLOCK5_SRLOCK167_B_0X1	(0x1u<<7)
#define	BSEC_SRLOCK5_SRLOCK166_B_0X0	(0x0u<<6)
#define	BSEC_SRLOCK5_SRLOCK166_B_0X1	(0x1u<<6)
#define	BSEC_SRLOCK5_SRLOCK165_B_0X0	(0x0u<<5)
#define	BSEC_SRLOCK5_SRLOCK165_B_0X1	(0x1u<<5)
#define	BSEC_SRLOCK5_SRLOCK164_B_0X0	(0x0u<<4)
#define	BSEC_SRLOCK5_SRLOCK164_B_0X1	(0x1u<<4)
#define	BSEC_SRLOCK5_SRLOCK163_B_0X0	(0x0u<<3)
#define	BSEC_SRLOCK5_SRLOCK163_B_0X1	(0x1u<<3)
#define	BSEC_SRLOCK5_SRLOCK162_B_0X0	(0x0u<<2)
#define	BSEC_SRLOCK5_SRLOCK162_B_0X1	(0x1u<<2)
#define	BSEC_SRLOCK5_SRLOCK161_B_0X0	(0x0u<<1)
#define	BSEC_SRLOCK5_SRLOCK161_B_0X1	(0x1u<<1)
#define	BSEC_SRLOCK5_SRLOCK160_B_0X0	(0x0u<<0)
#define	BSEC_SRLOCK5_SRLOCK160_B_0X1	(0x1u<<0)

// SRLOCK6 Configuration

#define	BSEC_SRLOCK6_SRLOCK223			(0x1u<<31)
#define	BSEC_SRLOCK6_SRLOCK222			(0x1u<<30)
#define	BSEC_SRLOCK6_SRLOCK221			(0x1u<<29)
#define	BSEC_SRLOCK6_SRLOCK220			(0x1u<<28)
#define	BSEC_SRLOCK6_SRLOCK219			(0x1u<<27)
#define	BSEC_SRLOCK6_SRLOCK218			(0x1u<<26)
#define	BSEC_SRLOCK6_SRLOCK217			(0x1u<<25)
#define	BSEC_SRLOCK6_SRLOCK216			(0x1u<<24)
#define	BSEC_SRLOCK6_SRLOCK215			(0x1u<<23)
#define	BSEC_SRLOCK6_SRLOCK214			(0x1u<<22)
#define	BSEC_SRLOCK6_SRLOCK213			(0x1u<<21)
#define	BSEC_SRLOCK6_SRLOCK212			(0x1u<<20)
#define	BSEC_SRLOCK6_SRLOCK211			(0x1u<<19)
#define	BSEC_SRLOCK6_SRLOCK210			(0x1u<<18)
#define	BSEC_SRLOCK6_SRLOCK209			(0x1u<<17)
#define	BSEC_SRLOCK6_SRLOCK208			(0x1u<<16)
#define	BSEC_SRLOCK6_SRLOCK207			(0x1u<<15)
#define	BSEC_SRLOCK6_SRLOCK206			(0x1u<<14)
#define	BSEC_SRLOCK6_SRLOCK205			(0x1u<<13)
#define	BSEC_SRLOCK6_SRLOCK204			(0x1u<<12)
#define	BSEC_SRLOCK6_SRLOCK203			(0x1u<<11)
#define	BSEC_SRLOCK6_SRLOCK202			(0x1u<<10)
#define	BSEC_SRLOCK6_SRLOCK201			(0x1u<<9)
#define	BSEC_SRLOCK6_SRLOCK200			(0x1u<<8)
#define	BSEC_SRLOCK6_SRLOCK199			(0x1u<<7)
#define	BSEC_SRLOCK6_SRLOCK198			(0x1u<<6)
#define	BSEC_SRLOCK6_SRLOCK197			(0x1u<<5)
#define	BSEC_SRLOCK6_SRLOCK196			(0x1u<<4)
#define	BSEC_SRLOCK6_SRLOCK195			(0x1u<<3)
#define	BSEC_SRLOCK6_SRLOCK194			(0x1u<<2)
#define	BSEC_SRLOCK6_SRLOCK193			(0x1u<<1)
#define	BSEC_SRLOCK6_SRLOCK192			(0x1u<<0)

#define	BSEC_SRLOCK6_SRLOCK223_B_0X0	(0x0u<<31)
#define	BSEC_SRLOCK6_SRLOCK223_B_0X1	(0x1u<<31)
#define	BSEC_SRLOCK6_SRLOCK222_B_0X0	(0x0u<<30)
#define	BSEC_SRLOCK6_SRLOCK222_B_0X1	(0x1u<<30)
#define	BSEC_SRLOCK6_SRLOCK221_B_0X0	(0x0u<<29)
#define	BSEC_SRLOCK6_SRLOCK221_B_0X1	(0x1u<<29)
#define	BSEC_SRLOCK6_SRLOCK220_B_0X0	(0x0u<<28)
#define	BSEC_SRLOCK6_SRLOCK220_B_0X1	(0x1u<<28)
#define	BSEC_SRLOCK6_SRLOCK219_B_0X0	(0x0u<<27)
#define	BSEC_SRLOCK6_SRLOCK219_B_0X1	(0x1u<<27)
#define	BSEC_SRLOCK6_SRLOCK218_B_0X0	(0x0u<<26)
#define	BSEC_SRLOCK6_SRLOCK218_B_0X1	(0x1u<<26)
#define	BSEC_SRLOCK6_SRLOCK217_B_0X0	(0x0u<<25)
#define	BSEC_SRLOCK6_SRLOCK217_B_0X1	(0x1u<<25)
#define	BSEC_SRLOCK6_SRLOCK216_B_0X0	(0x0u<<24)
#define	BSEC_SRLOCK6_SRLOCK216_B_0X1	(0x1u<<24)
#define	BSEC_SRLOCK6_SRLOCK215_B_0X0	(0x0u<<23)
#define	BSEC_SRLOCK6_SRLOCK215_B_0X1	(0x1u<<23)
#define	BSEC_SRLOCK6_SRLOCK214_B_0X0	(0x0u<<22)
#define	BSEC_SRLOCK6_SRLOCK214_B_0X1	(0x1u<<22)
#define	BSEC_SRLOCK6_SRLOCK213_B_0X0	(0x0u<<21)
#define	BSEC_SRLOCK6_SRLOCK213_B_0X1	(0x1u<<21)
#define	BSEC_SRLOCK6_SRLOCK212_B_0X0	(0x0u<<20)
#define	BSEC_SRLOCK6_SRLOCK212_B_0X1	(0x1u<<20)
#define	BSEC_SRLOCK6_SRLOCK211_B_0X0	(0x0u<<19)
#define	BSEC_SRLOCK6_SRLOCK211_B_0X1	(0x1u<<19)
#define	BSEC_SRLOCK6_SRLOCK210_B_0X0	(0x0u<<18)
#define	BSEC_SRLOCK6_SRLOCK210_B_0X1	(0x1u<<18)
#define	BSEC_SRLOCK6_SRLOCK209_B_0X0	(0x0u<<17)
#define	BSEC_SRLOCK6_SRLOCK209_B_0X1	(0x1u<<17)
#define	BSEC_SRLOCK6_SRLOCK208_B_0X0	(0x0u<<16)
#define	BSEC_SRLOCK6_SRLOCK208_B_0X1	(0x1u<<16)
#define	BSEC_SRLOCK6_SRLOCK207_B_0X0	(0x0u<<15)
#define	BSEC_SRLOCK6_SRLOCK207_B_0X1	(0x1u<<15)
#define	BSEC_SRLOCK6_SRLOCK206_B_0X0	(0x0u<<14)
#define	BSEC_SRLOCK6_SRLOCK206_B_0X1	(0x1u<<14)
#define	BSEC_SRLOCK6_SRLOCK205_B_0X0	(0x0u<<13)
#define	BSEC_SRLOCK6_SRLOCK205_B_0X1	(0x1u<<13)
#define	BSEC_SRLOCK6_SRLOCK204_B_0X0	(0x0u<<12)
#define	BSEC_SRLOCK6_SRLOCK204_B_0X1	(0x1u<<12)
#define	BSEC_SRLOCK6_SRLOCK203_B_0X0	(0x0u<<11)
#define	BSEC_SRLOCK6_SRLOCK203_B_0X1	(0x1u<<11)
#define	BSEC_SRLOCK6_SRLOCK202_B_0X0	(0x0u<<10)
#define	BSEC_SRLOCK6_SRLOCK202_B_0X1	(0x1u<<10)
#define	BSEC_SRLOCK6_SRLOCK201_B_0X0	(0x0u<<9)
#define	BSEC_SRLOCK6_SRLOCK201_B_0X1	(0x1u<<9)
#define	BSEC_SRLOCK6_SRLOCK200_B_0X0	(0x0u<<8)
#define	BSEC_SRLOCK6_SRLOCK200_B_0X1	(0x1u<<8)
#define	BSEC_SRLOCK6_SRLOCK199_B_0X0	(0x0u<<7)
#define	BSEC_SRLOCK6_SRLOCK199_B_0X1	(0x1u<<7)
#define	BSEC_SRLOCK6_SRLOCK198_B_0X0	(0x0u<<6)
#define	BSEC_SRLOCK6_SRLOCK198_B_0X1	(0x1u<<6)
#define	BSEC_SRLOCK6_SRLOCK197_B_0X0	(0x0u<<5)
#define	BSEC_SRLOCK6_SRLOCK197_B_0X1	(0x1u<<5)
#define	BSEC_SRLOCK6_SRLOCK196_B_0X0	(0x0u<<4)
#define	BSEC_SRLOCK6_SRLOCK196_B_0X1	(0x1u<<4)
#define	BSEC_SRLOCK6_SRLOCK195_B_0X0	(0x0u<<3)
#define	BSEC_SRLOCK6_SRLOCK195_B_0X1	(0x1u<<3)
#define	BSEC_SRLOCK6_SRLOCK194_B_0X0	(0x0u<<2)
#define	BSEC_SRLOCK6_SRLOCK194_B_0X1	(0x1u<<2)
#define	BSEC_SRLOCK6_SRLOCK193_B_0X0	(0x0u<<1)
#define	BSEC_SRLOCK6_SRLOCK193_B_0X1	(0x1u<<1)
#define	BSEC_SRLOCK6_SRLOCK192_B_0X0	(0x0u<<0)
#define	BSEC_SRLOCK6_SRLOCK192_B_0X1	(0x1u<<0)

// SRLOCK7 Configuration

#define	BSEC_SRLOCK7_SRLOCK255			(0x1u<<31)
#define	BSEC_SRLOCK7_SRLOCK254			(0x1u<<30)
#define	BSEC_SRLOCK7_SRLOCK253			(0x1u<<29)
#define	BSEC_SRLOCK7_SRLOCK252			(0x1u<<28)
#define	BSEC_SRLOCK7_SRLOCK251			(0x1u<<27)
#define	BSEC_SRLOCK7_SRLOCK250			(0x1u<<26)
#define	BSEC_SRLOCK7_SRLOCK249			(0x1u<<25)
#define	BSEC_SRLOCK7_SRLOCK248			(0x1u<<24)
#define	BSEC_SRLOCK7_SRLOCK247			(0x1u<<23)
#define	BSEC_SRLOCK7_SRLOCK246			(0x1u<<22)
#define	BSEC_SRLOCK7_SRLOCK245			(0x1u<<21)
#define	BSEC_SRLOCK7_SRLOCK244			(0x1u<<20)
#define	BSEC_SRLOCK7_SRLOCK243			(0x1u<<19)
#define	BSEC_SRLOCK7_SRLOCK242			(0x1u<<18)
#define	BSEC_SRLOCK7_SRLOCK241			(0x1u<<17)
#define	BSEC_SRLOCK7_SRLOCK240			(0x1u<<16)
#define	BSEC_SRLOCK7_SRLOCK239			(0x1u<<15)
#define	BSEC_SRLOCK7_SRLOCK238			(0x1u<<14)
#define	BSEC_SRLOCK7_SRLOCK237			(0x1u<<13)
#define	BSEC_SRLOCK7_SRLOCK236			(0x1u<<12)
#define	BSEC_SRLOCK7_SRLOCK235			(0x1u<<11)
#define	BSEC_SRLOCK7_SRLOCK234			(0x1u<<10)
#define	BSEC_SRLOCK7_SRLOCK233			(0x1u<<9)
#define	BSEC_SRLOCK7_SRLOCK232			(0x1u<<8)
#define	BSEC_SRLOCK7_SRLOCK231			(0x1u<<7)
#define	BSEC_SRLOCK7_SRLOCK230			(0x1u<<6)
#define	BSEC_SRLOCK7_SRLOCK229			(0x1u<<5)
#define	BSEC_SRLOCK7_SRLOCK228			(0x1u<<4)
#define	BSEC_SRLOCK7_SRLOCK227			(0x1u<<3)
#define	BSEC_SRLOCK7_SRLOCK226			(0x1u<<2)
#define	BSEC_SRLOCK7_SRLOCK225			(0x1u<<1)
#define	BSEC_SRLOCK7_SRLOCK224			(0x1u<<0)

#define	BSEC_SRLOCK7_SRLOCK255_B_0X0	(0x0u<<31)
#define	BSEC_SRLOCK7_SRLOCK255_B_0X1	(0x1u<<31)
#define	BSEC_SRLOCK7_SRLOCK254_B_0X0	(0x0u<<30)
#define	BSEC_SRLOCK7_SRLOCK254_B_0X1	(0x1u<<30)
#define	BSEC_SRLOCK7_SRLOCK253_B_0X0	(0x0u<<29)
#define	BSEC_SRLOCK7_SRLOCK253_B_0X1	(0x1u<<29)
#define	BSEC_SRLOCK7_SRLOCK252_B_0X0	(0x0u<<28)
#define	BSEC_SRLOCK7_SRLOCK252_B_0X1	(0x1u<<28)
#define	BSEC_SRLOCK7_SRLOCK251_B_0X0	(0x0u<<27)
#define	BSEC_SRLOCK7_SRLOCK251_B_0X1	(0x1u<<27)
#define	BSEC_SRLOCK7_SRLOCK250_B_0X0	(0x0u<<26)
#define	BSEC_SRLOCK7_SRLOCK250_B_0X1	(0x1u<<26)
#define	BSEC_SRLOCK7_SRLOCK249_B_0X0	(0x0u<<25)
#define	BSEC_SRLOCK7_SRLOCK249_B_0X1	(0x1u<<25)
#define	BSEC_SRLOCK7_SRLOCK248_B_0X0	(0x0u<<24)
#define	BSEC_SRLOCK7_SRLOCK248_B_0X1	(0x1u<<24)
#define	BSEC_SRLOCK7_SRLOCK247_B_0X0	(0x0u<<23)
#define	BSEC_SRLOCK7_SRLOCK247_B_0X1	(0x1u<<23)
#define	BSEC_SRLOCK7_SRLOCK246_B_0X0	(0x0u<<22)
#define	BSEC_SRLOCK7_SRLOCK246_B_0X1	(0x1u<<22)
#define	BSEC_SRLOCK7_SRLOCK245_B_0X0	(0x0u<<21)
#define	BSEC_SRLOCK7_SRLOCK245_B_0X1	(0x1u<<21)
#define	BSEC_SRLOCK7_SRLOCK244_B_0X0	(0x0u<<20)
#define	BSEC_SRLOCK7_SRLOCK244_B_0X1	(0x1u<<20)
#define	BSEC_SRLOCK7_SRLOCK243_B_0X0	(0x0u<<19)
#define	BSEC_SRLOCK7_SRLOCK243_B_0X1	(0x1u<<19)
#define	BSEC_SRLOCK7_SRLOCK242_B_0X0	(0x0u<<18)
#define	BSEC_SRLOCK7_SRLOCK242_B_0X1	(0x1u<<18)
#define	BSEC_SRLOCK7_SRLOCK241_B_0X0	(0x0u<<17)
#define	BSEC_SRLOCK7_SRLOCK241_B_0X1	(0x1u<<17)
#define	BSEC_SRLOCK7_SRLOCK240_B_0X0	(0x0u<<16)
#define	BSEC_SRLOCK7_SRLOCK240_B_0X1	(0x1u<<16)
#define	BSEC_SRLOCK7_SRLOCK239_B_0X0	(0x0u<<15)
#define	BSEC_SRLOCK7_SRLOCK239_B_0X1	(0x1u<<15)
#define	BSEC_SRLOCK7_SRLOCK238_B_0X0	(0x0u<<14)
#define	BSEC_SRLOCK7_SRLOCK238_B_0X1	(0x1u<<14)
#define	BSEC_SRLOCK7_SRLOCK237_B_0X0	(0x0u<<13)
#define	BSEC_SRLOCK7_SRLOCK237_B_0X1	(0x1u<<13)
#define	BSEC_SRLOCK7_SRLOCK236_B_0X0	(0x0u<<12)
#define	BSEC_SRLOCK7_SRLOCK236_B_0X1	(0x1u<<12)
#define	BSEC_SRLOCK7_SRLOCK235_B_0X0	(0x0u<<11)
#define	BSEC_SRLOCK7_SRLOCK235_B_0X1	(0x1u<<11)
#define	BSEC_SRLOCK7_SRLOCK234_B_0X0	(0x0u<<10)
#define	BSEC_SRLOCK7_SRLOCK234_B_0X1	(0x1u<<10)
#define	BSEC_SRLOCK7_SRLOCK233_B_0X0	(0x0u<<9)
#define	BSEC_SRLOCK7_SRLOCK233_B_0X1	(0x1u<<9)
#define	BSEC_SRLOCK7_SRLOCK232_B_0X0	(0x0u<<8)
#define	BSEC_SRLOCK7_SRLOCK232_B_0X1	(0x1u<<8)
#define	BSEC_SRLOCK7_SRLOCK231_B_0X0	(0x0u<<7)
#define	BSEC_SRLOCK7_SRLOCK231_B_0X1	(0x1u<<7)
#define	BSEC_SRLOCK7_SRLOCK230_B_0X0	(0x0u<<6)
#define	BSEC_SRLOCK7_SRLOCK230_B_0X1	(0x1u<<6)
#define	BSEC_SRLOCK7_SRLOCK229_B_0X0	(0x0u<<5)
#define	BSEC_SRLOCK7_SRLOCK229_B_0X1	(0x1u<<5)
#define	BSEC_SRLOCK7_SRLOCK228_B_0X0	(0x0u<<4)
#define	BSEC_SRLOCK7_SRLOCK228_B_0X1	(0x1u<<4)
#define	BSEC_SRLOCK7_SRLOCK227_B_0X0	(0x0u<<3)
#define	BSEC_SRLOCK7_SRLOCK227_B_0X1	(0x1u<<3)
#define	BSEC_SRLOCK7_SRLOCK226_B_0X0	(0x0u<<2)
#define	BSEC_SRLOCK7_SRLOCK226_B_0X1	(0x1u<<2)
#define	BSEC_SRLOCK7_SRLOCK225_B_0X0	(0x0u<<1)
#define	BSEC_SRLOCK7_SRLOCK225_B_0X1	(0x1u<<1)
#define	BSEC_SRLOCK7_SRLOCK224_B_0X0	(0x0u<<0)
#define	BSEC_SRLOCK7_SRLOCK224_B_0X1	(0x1u<<0)

// SRLOCK8 Configuration

#define	BSEC_SRLOCK8_SRLOCK287			(0x1u<<31)
#define	BSEC_SRLOCK8_SRLOCK286			(0x1u<<30)
#define	BSEC_SRLOCK8_SRLOCK285			(0x1u<<29)
#define	BSEC_SRLOCK8_SRLOCK284			(0x1u<<28)
#define	BSEC_SRLOCK8_SRLOCK283			(0x1u<<27)
#define	BSEC_SRLOCK8_SRLOCK282			(0x1u<<26)
#define	BSEC_SRLOCK8_SRLOCK281			(0x1u<<25)
#define	BSEC_SRLOCK8_SRLOCK280			(0x1u<<24)
#define	BSEC_SRLOCK8_SRLOCK279			(0x1u<<23)
#define	BSEC_SRLOCK8_SRLOCK278			(0x1u<<22)
#define	BSEC_SRLOCK8_SRLOCK277			(0x1u<<21)
#define	BSEC_SRLOCK8_SRLOCK276			(0x1u<<20)
#define	BSEC_SRLOCK8_SRLOCK275			(0x1u<<19)
#define	BSEC_SRLOCK8_SRLOCK274			(0x1u<<18)
#define	BSEC_SRLOCK8_SRLOCK273			(0x1u<<17)
#define	BSEC_SRLOCK8_SRLOCK272			(0x1u<<16)
#define	BSEC_SRLOCK8_SRLOCK271			(0x1u<<15)
#define	BSEC_SRLOCK8_SRLOCK270			(0x1u<<14)
#define	BSEC_SRLOCK8_SRLOCK269			(0x1u<<13)
#define	BSEC_SRLOCK8_SRLOCK268			(0x1u<<12)
#define	BSEC_SRLOCK8_SRLOCK267			(0x1u<<11)
#define	BSEC_SRLOCK8_SRLOCK266			(0x1u<<10)
#define	BSEC_SRLOCK8_SRLOCK265			(0x1u<<9)
#define	BSEC_SRLOCK8_SRLOCK264			(0x1u<<8)
#define	BSEC_SRLOCK8_SRLOCK263			(0x1u<<7)
#define	BSEC_SRLOCK8_SRLOCK262			(0x1u<<6)
#define	BSEC_SRLOCK8_SRLOCK261			(0x1u<<5)
#define	BSEC_SRLOCK8_SRLOCK260			(0x1u<<4)
#define	BSEC_SRLOCK8_SRLOCK259			(0x1u<<3)
#define	BSEC_SRLOCK8_SRLOCK258			(0x1u<<2)
#define	BSEC_SRLOCK8_SRLOCK257			(0x1u<<1)
#define	BSEC_SRLOCK8_SRLOCK256			(0x1u<<0)

#define	BSEC_SRLOCK8_SRLOCK287_B_0X0	(0x0u<<31)
#define	BSEC_SRLOCK8_SRLOCK287_B_0X1	(0x1u<<31)
#define	BSEC_SRLOCK8_SRLOCK286_B_0X0	(0x0u<<30)
#define	BSEC_SRLOCK8_SRLOCK286_B_0X1	(0x1u<<30)
#define	BSEC_SRLOCK8_SRLOCK285_B_0X0	(0x0u<<29)
#define	BSEC_SRLOCK8_SRLOCK285_B_0X1	(0x1u<<29)
#define	BSEC_SRLOCK8_SRLOCK284_B_0X0	(0x0u<<28)
#define	BSEC_SRLOCK8_SRLOCK284_B_0X1	(0x1u<<28)
#define	BSEC_SRLOCK8_SRLOCK283_B_0X0	(0x0u<<27)
#define	BSEC_SRLOCK8_SRLOCK283_B_0X1	(0x1u<<27)
#define	BSEC_SRLOCK8_SRLOCK282_B_0X0	(0x0u<<26)
#define	BSEC_SRLOCK8_SRLOCK282_B_0X1	(0x1u<<26)
#define	BSEC_SRLOCK8_SRLOCK281_B_0X0	(0x0u<<25)
#define	BSEC_SRLOCK8_SRLOCK281_B_0X1	(0x1u<<25)
#define	BSEC_SRLOCK8_SRLOCK280_B_0X0	(0x0u<<24)
#define	BSEC_SRLOCK8_SRLOCK280_B_0X1	(0x1u<<24)
#define	BSEC_SRLOCK8_SRLOCK279_B_0X0	(0x0u<<23)
#define	BSEC_SRLOCK8_SRLOCK279_B_0X1	(0x1u<<23)
#define	BSEC_SRLOCK8_SRLOCK278_B_0X0	(0x0u<<22)
#define	BSEC_SRLOCK8_SRLOCK278_B_0X1	(0x1u<<22)
#define	BSEC_SRLOCK8_SRLOCK277_B_0X0	(0x0u<<21)
#define	BSEC_SRLOCK8_SRLOCK277_B_0X1	(0x1u<<21)
#define	BSEC_SRLOCK8_SRLOCK276_B_0X0	(0x0u<<20)
#define	BSEC_SRLOCK8_SRLOCK276_B_0X1	(0x1u<<20)
#define	BSEC_SRLOCK8_SRLOCK275_B_0X0	(0x0u<<19)
#define	BSEC_SRLOCK8_SRLOCK275_B_0X1	(0x1u<<19)
#define	BSEC_SRLOCK8_SRLOCK274_B_0X0	(0x0u<<18)
#define	BSEC_SRLOCK8_SRLOCK274_B_0X1	(0x1u<<18)
#define	BSEC_SRLOCK8_SRLOCK273_B_0X0	(0x0u<<17)
#define	BSEC_SRLOCK8_SRLOCK273_B_0X1	(0x1u<<17)
#define	BSEC_SRLOCK8_SRLOCK272_B_0X0	(0x0u<<16)
#define	BSEC_SRLOCK8_SRLOCK272_B_0X1	(0x1u<<16)
#define	BSEC_SRLOCK8_SRLOCK271_B_0X0	(0x0u<<15)
#define	BSEC_SRLOCK8_SRLOCK271_B_0X1	(0x1u<<15)
#define	BSEC_SRLOCK8_SRLOCK270_B_0X0	(0x0u<<14)
#define	BSEC_SRLOCK8_SRLOCK270_B_0X1	(0x1u<<14)
#define	BSEC_SRLOCK8_SRLOCK269_B_0X0	(0x0u<<13)
#define	BSEC_SRLOCK8_SRLOCK269_B_0X1	(0x1u<<13)
#define	BSEC_SRLOCK8_SRLOCK268_B_0X0	(0x0u<<12)
#define	BSEC_SRLOCK8_SRLOCK268_B_0X1	(0x1u<<12)
#define	BSEC_SRLOCK8_SRLOCK267_B_0X0	(0x0u<<11)
#define	BSEC_SRLOCK8_SRLOCK267_B_0X1	(0x1u<<11)
#define	BSEC_SRLOCK8_SRLOCK266_B_0X0	(0x0u<<10)
#define	BSEC_SRLOCK8_SRLOCK266_B_0X1	(0x1u<<10)
#define	BSEC_SRLOCK8_SRLOCK265_B_0X0	(0x0u<<9)
#define	BSEC_SRLOCK8_SRLOCK265_B_0X1	(0x1u<<9)
#define	BSEC_SRLOCK8_SRLOCK264_B_0X0	(0x0u<<8)
#define	BSEC_SRLOCK8_SRLOCK264_B_0X1	(0x1u<<8)
#define	BSEC_SRLOCK8_SRLOCK263_B_0X0	(0x0u<<7)
#define	BSEC_SRLOCK8_SRLOCK263_B_0X1	(0x1u<<7)
#define	BSEC_SRLOCK8_SRLOCK262_B_0X0	(0x0u<<6)
#define	BSEC_SRLOCK8_SRLOCK262_B_0X1	(0x1u<<6)
#define	BSEC_SRLOCK8_SRLOCK261_B_0X0	(0x0u<<5)
#define	BSEC_SRLOCK8_SRLOCK261_B_0X1	(0x1u<<5)
#define	BSEC_SRLOCK8_SRLOCK260_B_0X0	(0x0u<<4)
#define	BSEC_SRLOCK8_SRLOCK260_B_0X1	(0x1u<<4)
#define	BSEC_SRLOCK8_SRLOCK259_B_0X0	(0x0u<<3)
#define	BSEC_SRLOCK8_SRLOCK259_B_0X1	(0x1u<<3)
#define	BSEC_SRLOCK8_SRLOCK258_B_0X0	(0x0u<<2)
#define	BSEC_SRLOCK8_SRLOCK258_B_0X1	(0x1u<<2)
#define	BSEC_SRLOCK8_SRLOCK257_B_0X0	(0x0u<<1)
#define	BSEC_SRLOCK8_SRLOCK257_B_0X1	(0x1u<<1)
#define	BSEC_SRLOCK8_SRLOCK256_B_0X0	(0x0u<<0)
#define	BSEC_SRLOCK8_SRLOCK256_B_0X1	(0x1u<<0)

// SRLOCK9 Configuration

#define	BSEC_SRLOCK9_SRLOCK319			(0x1u<<31)
#define	BSEC_SRLOCK9_SRLOCK318			(0x1u<<30)
#define	BSEC_SRLOCK9_SRLOCK317			(0x1u<<29)
#define	BSEC_SRLOCK9_SRLOCK316			(0x1u<<28)
#define	BSEC_SRLOCK9_SRLOCK315			(0x1u<<27)
#define	BSEC_SRLOCK9_SRLOCK314			(0x1u<<26)
#define	BSEC_SRLOCK9_SRLOCK313			(0x1u<<25)
#define	BSEC_SRLOCK9_SRLOCK312			(0x1u<<24)
#define	BSEC_SRLOCK9_SRLOCK311			(0x1u<<23)
#define	BSEC_SRLOCK9_SRLOCK310			(0x1u<<22)
#define	BSEC_SRLOCK9_SRLOCK309			(0x1u<<21)
#define	BSEC_SRLOCK9_SRLOCK308			(0x1u<<20)
#define	BSEC_SRLOCK9_SRLOCK307			(0x1u<<19)
#define	BSEC_SRLOCK9_SRLOCK306			(0x1u<<18)
#define	BSEC_SRLOCK9_SRLOCK305			(0x1u<<17)
#define	BSEC_SRLOCK9_SRLOCK304			(0x1u<<16)
#define	BSEC_SRLOCK9_SRLOCK303			(0x1u<<15)
#define	BSEC_SRLOCK9_SRLOCK302			(0x1u<<14)
#define	BSEC_SRLOCK9_SRLOCK301			(0x1u<<13)
#define	BSEC_SRLOCK9_SRLOCK300			(0x1u<<12)
#define	BSEC_SRLOCK9_SRLOCK299			(0x1u<<11)
#define	BSEC_SRLOCK9_SRLOCK298			(0x1u<<10)
#define	BSEC_SRLOCK9_SRLOCK297			(0x1u<<9)
#define	BSEC_SRLOCK9_SRLOCK296			(0x1u<<8)
#define	BSEC_SRLOCK9_SRLOCK295			(0x1u<<7)
#define	BSEC_SRLOCK9_SRLOCK294			(0x1u<<6)
#define	BSEC_SRLOCK9_SRLOCK293			(0x1u<<5)
#define	BSEC_SRLOCK9_SRLOCK292			(0x1u<<4)
#define	BSEC_SRLOCK9_SRLOCK291			(0x1u<<3)
#define	BSEC_SRLOCK9_SRLOCK290			(0x1u<<2)
#define	BSEC_SRLOCK9_SRLOCK289			(0x1u<<1)
#define	BSEC_SRLOCK9_SRLOCK288			(0x1u<<0)

#define	BSEC_SRLOCK9_SRLOCK319_B_0X0	(0x0u<<31)
#define	BSEC_SRLOCK9_SRLOCK319_B_0X1	(0x1u<<31)
#define	BSEC_SRLOCK9_SRLOCK318_B_0X0	(0x0u<<30)
#define	BSEC_SRLOCK9_SRLOCK318_B_0X1	(0x1u<<30)
#define	BSEC_SRLOCK9_SRLOCK317_B_0X0	(0x0u<<29)
#define	BSEC_SRLOCK9_SRLOCK317_B_0X1	(0x1u<<29)
#define	BSEC_SRLOCK9_SRLOCK316_B_0X0	(0x0u<<28)
#define	BSEC_SRLOCK9_SRLOCK316_B_0X1	(0x1u<<28)
#define	BSEC_SRLOCK9_SRLOCK315_B_0X0	(0x0u<<27)
#define	BSEC_SRLOCK9_SRLOCK315_B_0X1	(0x1u<<27)
#define	BSEC_SRLOCK9_SRLOCK314_B_0X0	(0x0u<<26)
#define	BSEC_SRLOCK9_SRLOCK314_B_0X1	(0x1u<<26)
#define	BSEC_SRLOCK9_SRLOCK313_B_0X0	(0x0u<<25)
#define	BSEC_SRLOCK9_SRLOCK313_B_0X1	(0x1u<<25)
#define	BSEC_SRLOCK9_SRLOCK312_B_0X0	(0x0u<<24)
#define	BSEC_SRLOCK9_SRLOCK312_B_0X1	(0x1u<<24)
#define	BSEC_SRLOCK9_SRLOCK311_B_0X0	(0x0u<<23)
#define	BSEC_SRLOCK9_SRLOCK311_B_0X1	(0x1u<<23)
#define	BSEC_SRLOCK9_SRLOCK310_B_0X0	(0x0u<<22)
#define	BSEC_SRLOCK9_SRLOCK310_B_0X1	(0x1u<<22)
#define	BSEC_SRLOCK9_SRLOCK309_B_0X0	(0x0u<<21)
#define	BSEC_SRLOCK9_SRLOCK309_B_0X1	(0x1u<<21)
#define	BSEC_SRLOCK9_SRLOCK308_B_0X0	(0x0u<<20)
#define	BSEC_SRLOCK9_SRLOCK308_B_0X1	(0x1u<<20)
#define	BSEC_SRLOCK9_SRLOCK307_B_0X0	(0x0u<<19)
#define	BSEC_SRLOCK9_SRLOCK307_B_0X1	(0x1u<<19)
#define	BSEC_SRLOCK9_SRLOCK306_B_0X0	(0x0u<<18)
#define	BSEC_SRLOCK9_SRLOCK306_B_0X1	(0x1u<<18)
#define	BSEC_SRLOCK9_SRLOCK305_B_0X0	(0x0u<<17)
#define	BSEC_SRLOCK9_SRLOCK305_B_0X1	(0x1u<<17)
#define	BSEC_SRLOCK9_SRLOCK304_B_0X0	(0x0u<<16)
#define	BSEC_SRLOCK9_SRLOCK304_B_0X1	(0x1u<<16)
#define	BSEC_SRLOCK9_SRLOCK303_B_0X0	(0x0u<<15)
#define	BSEC_SRLOCK9_SRLOCK303_B_0X1	(0x1u<<15)
#define	BSEC_SRLOCK9_SRLOCK302_B_0X0	(0x0u<<14)
#define	BSEC_SRLOCK9_SRLOCK302_B_0X1	(0x1u<<14)
#define	BSEC_SRLOCK9_SRLOCK301_B_0X0	(0x0u<<13)
#define	BSEC_SRLOCK9_SRLOCK301_B_0X1	(0x1u<<13)
#define	BSEC_SRLOCK9_SRLOCK300_B_0X0	(0x0u<<12)
#define	BSEC_SRLOCK9_SRLOCK300_B_0X1	(0x1u<<12)
#define	BSEC_SRLOCK9_SRLOCK299_B_0X0	(0x0u<<11)
#define	BSEC_SRLOCK9_SRLOCK299_B_0X1	(0x1u<<11)
#define	BSEC_SRLOCK9_SRLOCK298_B_0X0	(0x0u<<10)
#define	BSEC_SRLOCK9_SRLOCK298_B_0X1	(0x1u<<10)
#define	BSEC_SRLOCK9_SRLOCK297_B_0X0	(0x0u<<9)
#define	BSEC_SRLOCK9_SRLOCK297_B_0X1	(0x1u<<9)
#define	BSEC_SRLOCK9_SRLOCK296_B_0X0	(0x0u<<8)
#define	BSEC_SRLOCK9_SRLOCK296_B_0X1	(0x1u<<8)
#define	BSEC_SRLOCK9_SRLOCK295_B_0X0	(0x0u<<7)
#define	BSEC_SRLOCK9_SRLOCK295_B_0X1	(0x1u<<7)
#define	BSEC_SRLOCK9_SRLOCK294_B_0X0	(0x0u<<6)
#define	BSEC_SRLOCK9_SRLOCK294_B_0X1	(0x1u<<6)
#define	BSEC_SRLOCK9_SRLOCK293_B_0X0	(0x0u<<5)
#define	BSEC_SRLOCK9_SRLOCK293_B_0X1	(0x1u<<5)
#define	BSEC_SRLOCK9_SRLOCK292_B_0X0	(0x0u<<4)
#define	BSEC_SRLOCK9_SRLOCK292_B_0X1	(0x1u<<4)
#define	BSEC_SRLOCK9_SRLOCK291_B_0X0	(0x0u<<3)
#define	BSEC_SRLOCK9_SRLOCK291_B_0X1	(0x1u<<3)
#define	BSEC_SRLOCK9_SRLOCK290_B_0X0	(0x0u<<2)
#define	BSEC_SRLOCK9_SRLOCK290_B_0X1	(0x1u<<2)
#define	BSEC_SRLOCK9_SRLOCK289_B_0X0	(0x0u<<1)
#define	BSEC_SRLOCK9_SRLOCK289_B_0X1	(0x1u<<1)
#define	BSEC_SRLOCK9_SRLOCK288_B_0X0	(0x0u<<0)
#define	BSEC_SRLOCK9_SRLOCK288_B_0X1	(0x1u<<0)

// SRLOCK10 Configuration

#define	BSEC_SRLOCK10_SRLOCK351			(0x1u<<31)
#define	BSEC_SRLOCK10_SRLOCK350			(0x1u<<30)
#define	BSEC_SRLOCK10_SRLOCK349			(0x1u<<29)
#define	BSEC_SRLOCK10_SRLOCK348			(0x1u<<28)
#define	BSEC_SRLOCK10_SRLOCK347			(0x1u<<27)
#define	BSEC_SRLOCK10_SRLOCK346			(0x1u<<26)
#define	BSEC_SRLOCK10_SRLOCK345			(0x1u<<25)
#define	BSEC_SRLOCK10_SRLOCK344			(0x1u<<24)
#define	BSEC_SRLOCK10_SRLOCK343			(0x1u<<23)
#define	BSEC_SRLOCK10_SRLOCK342			(0x1u<<22)
#define	BSEC_SRLOCK10_SRLOCK341			(0x1u<<21)
#define	BSEC_SRLOCK10_SRLOCK340			(0x1u<<20)
#define	BSEC_SRLOCK10_SRLOCK339			(0x1u<<19)
#define	BSEC_SRLOCK10_SRLOCK338			(0x1u<<18)
#define	BSEC_SRLOCK10_SRLOCK337			(0x1u<<17)
#define	BSEC_SRLOCK10_SRLOCK336			(0x1u<<16)
#define	BSEC_SRLOCK10_SRLOCK335			(0x1u<<15)
#define	BSEC_SRLOCK10_SRLOCK334			(0x1u<<14)
#define	BSEC_SRLOCK10_SRLOCK333			(0x1u<<13)
#define	BSEC_SRLOCK10_SRLOCK332			(0x1u<<12)
#define	BSEC_SRLOCK10_SRLOCK331			(0x1u<<11)
#define	BSEC_SRLOCK10_SRLOCK330			(0x1u<<10)
#define	BSEC_SRLOCK10_SRLOCK329			(0x1u<<9)
#define	BSEC_SRLOCK10_SRLOCK328			(0x1u<<8)
#define	BSEC_SRLOCK10_SRLOCK327			(0x1u<<7)
#define	BSEC_SRLOCK10_SRLOCK326			(0x1u<<6)
#define	BSEC_SRLOCK10_SRLOCK325			(0x1u<<5)
#define	BSEC_SRLOCK10_SRLOCK324			(0x1u<<4)
#define	BSEC_SRLOCK10_SRLOCK323			(0x1u<<3)
#define	BSEC_SRLOCK10_SRLOCK322			(0x1u<<2)
#define	BSEC_SRLOCK10_SRLOCK321			(0x1u<<1)
#define	BSEC_SRLOCK10_SRLOCK320			(0x1u<<0)

#define	BSEC_SRLOCK10_SRLOCK351_B_0X0	(0x0u<<31)
#define	BSEC_SRLOCK10_SRLOCK351_B_0X1	(0x1u<<31)
#define	BSEC_SRLOCK10_SRLOCK350_B_0X0	(0x0u<<30)
#define	BSEC_SRLOCK10_SRLOCK350_B_0X1	(0x1u<<30)
#define	BSEC_SRLOCK10_SRLOCK349_B_0X0	(0x0u<<29)
#define	BSEC_SRLOCK10_SRLOCK349_B_0X1	(0x1u<<29)
#define	BSEC_SRLOCK10_SRLOCK348_B_0X0	(0x0u<<28)
#define	BSEC_SRLOCK10_SRLOCK348_B_0X1	(0x1u<<28)
#define	BSEC_SRLOCK10_SRLOCK347_B_0X0	(0x0u<<27)
#define	BSEC_SRLOCK10_SRLOCK347_B_0X1	(0x1u<<27)
#define	BSEC_SRLOCK10_SRLOCK346_B_0X0	(0x0u<<26)
#define	BSEC_SRLOCK10_SRLOCK346_B_0X1	(0x1u<<26)
#define	BSEC_SRLOCK10_SRLOCK345_B_0X0	(0x0u<<25)
#define	BSEC_SRLOCK10_SRLOCK345_B_0X1	(0x1u<<25)
#define	BSEC_SRLOCK10_SRLOCK344_B_0X0	(0x0u<<24)
#define	BSEC_SRLOCK10_SRLOCK344_B_0X1	(0x1u<<24)
#define	BSEC_SRLOCK10_SRLOCK343_B_0X0	(0x0u<<23)
#define	BSEC_SRLOCK10_SRLOCK343_B_0X1	(0x1u<<23)
#define	BSEC_SRLOCK10_SRLOCK342_B_0X0	(0x0u<<22)
#define	BSEC_SRLOCK10_SRLOCK342_B_0X1	(0x1u<<22)
#define	BSEC_SRLOCK10_SRLOCK341_B_0X0	(0x0u<<21)
#define	BSEC_SRLOCK10_SRLOCK341_B_0X1	(0x1u<<21)
#define	BSEC_SRLOCK10_SRLOCK340_B_0X0	(0x0u<<20)
#define	BSEC_SRLOCK10_SRLOCK340_B_0X1	(0x1u<<20)
#define	BSEC_SRLOCK10_SRLOCK339_B_0X0	(0x0u<<19)
#define	BSEC_SRLOCK10_SRLOCK339_B_0X1	(0x1u<<19)
#define	BSEC_SRLOCK10_SRLOCK338_B_0X0	(0x0u<<18)
#define	BSEC_SRLOCK10_SRLOCK338_B_0X1	(0x1u<<18)
#define	BSEC_SRLOCK10_SRLOCK337_B_0X0	(0x0u<<17)
#define	BSEC_SRLOCK10_SRLOCK337_B_0X1	(0x1u<<17)
#define	BSEC_SRLOCK10_SRLOCK336_B_0X0	(0x0u<<16)
#define	BSEC_SRLOCK10_SRLOCK336_B_0X1	(0x1u<<16)
#define	BSEC_SRLOCK10_SRLOCK335_B_0X0	(0x0u<<15)
#define	BSEC_SRLOCK10_SRLOCK335_B_0X1	(0x1u<<15)
#define	BSEC_SRLOCK10_SRLOCK334_B_0X0	(0x0u<<14)
#define	BSEC_SRLOCK10_SRLOCK334_B_0X1	(0x1u<<14)
#define	BSEC_SRLOCK10_SRLOCK333_B_0X0	(0x0u<<13)
#define	BSEC_SRLOCK10_SRLOCK333_B_0X1	(0x1u<<13)
#define	BSEC_SRLOCK10_SRLOCK332_B_0X0	(0x0u<<12)
#define	BSEC_SRLOCK10_SRLOCK332_B_0X1	(0x1u<<12)
#define	BSEC_SRLOCK10_SRLOCK331_B_0X0	(0x0u<<11)
#define	BSEC_SRLOCK10_SRLOCK331_B_0X1	(0x1u<<11)
#define	BSEC_SRLOCK10_SRLOCK330_B_0X0	(0x0u<<10)
#define	BSEC_SRLOCK10_SRLOCK330_B_0X1	(0x1u<<10)
#define	BSEC_SRLOCK10_SRLOCK329_B_0X0	(0x0u<<9)
#define	BSEC_SRLOCK10_SRLOCK329_B_0X1	(0x1u<<9)
#define	BSEC_SRLOCK10_SRLOCK328_B_0X0	(0x0u<<8)
#define	BSEC_SRLOCK10_SRLOCK328_B_0X1	(0x1u<<8)
#define	BSEC_SRLOCK10_SRLOCK327_B_0X0	(0x0u<<7)
#define	BSEC_SRLOCK10_SRLOCK327_B_0X1	(0x1u<<7)
#define	BSEC_SRLOCK10_SRLOCK326_B_0X0	(0x0u<<6)
#define	BSEC_SRLOCK10_SRLOCK326_B_0X1	(0x1u<<6)
#define	BSEC_SRLOCK10_SRLOCK325_B_0X0	(0x0u<<5)
#define	BSEC_SRLOCK10_SRLOCK325_B_0X1	(0x1u<<5)
#define	BSEC_SRLOCK10_SRLOCK324_B_0X0	(0x0u<<4)
#define	BSEC_SRLOCK10_SRLOCK324_B_0X1	(0x1u<<4)
#define	BSEC_SRLOCK10_SRLOCK323_B_0X0	(0x0u<<3)
#define	BSEC_SRLOCK10_SRLOCK323_B_0X1	(0x1u<<3)
#define	BSEC_SRLOCK10_SRLOCK322_B_0X0	(0x0u<<2)
#define	BSEC_SRLOCK10_SRLOCK322_B_0X1	(0x1u<<2)
#define	BSEC_SRLOCK10_SRLOCK321_B_0X0	(0x0u<<1)
#define	BSEC_SRLOCK10_SRLOCK321_B_0X1	(0x1u<<1)
#define	BSEC_SRLOCK10_SRLOCK320_B_0X0	(0x0u<<0)
#define	BSEC_SRLOCK10_SRLOCK320_B_0X1	(0x1u<<0)

// SRLOCK11 Configuration

#define	BSEC_SRLOCK11_SRLOCK383			(0x1u<<31)
#define	BSEC_SRLOCK11_SRLOCK382			(0x1u<<30)
#define	BSEC_SRLOCK11_SRLOCK381			(0x1u<<29)
#define	BSEC_SRLOCK11_SRLOCK380			(0x1u<<28)
#define	BSEC_SRLOCK11_SRLOCK379			(0x1u<<27)
#define	BSEC_SRLOCK11_SRLOCK378			(0x1u<<26)
#define	BSEC_SRLOCK11_SRLOCK377			(0x1u<<25)
#define	BSEC_SRLOCK11_SRLOCK376			(0x1u<<24)
#define	BSEC_SRLOCK11_SRLOCK375			(0x1u<<23)
#define	BSEC_SRLOCK11_SRLOCK374			(0x1u<<22)
#define	BSEC_SRLOCK11_SRLOCK373			(0x1u<<21)
#define	BSEC_SRLOCK11_SRLOCK372			(0x1u<<20)
#define	BSEC_SRLOCK11_SRLOCK371			(0x1u<<19)
#define	BSEC_SRLOCK11_SRLOCK370			(0x1u<<18)
#define	BSEC_SRLOCK11_SRLOCK369			(0x1u<<17)
#define	BSEC_SRLOCK11_SRLOCK368			(0x1u<<16)
#define	BSEC_SRLOCK11_SRLOCK367			(0x1u<<15)
#define	BSEC_SRLOCK11_SRLOCK366			(0x1u<<14)
#define	BSEC_SRLOCK11_SRLOCK365			(0x1u<<13)
#define	BSEC_SRLOCK11_SRLOCK364			(0x1u<<12)
#define	BSEC_SRLOCK11_SRLOCK363			(0x1u<<11)
#define	BSEC_SRLOCK11_SRLOCK362			(0x1u<<10)
#define	BSEC_SRLOCK11_SRLOCK361			(0x1u<<9)
#define	BSEC_SRLOCK11_SRLOCK360			(0x1u<<8)
#define	BSEC_SRLOCK11_SRLOCK359			(0x1u<<7)
#define	BSEC_SRLOCK11_SRLOCK358			(0x1u<<6)
#define	BSEC_SRLOCK11_SRLOCK357			(0x1u<<5)
#define	BSEC_SRLOCK11_SRLOCK356			(0x1u<<4)
#define	BSEC_SRLOCK11_SRLOCK355			(0x1u<<3)
#define	BSEC_SRLOCK11_SRLOCK354			(0x1u<<2)
#define	BSEC_SRLOCK11_SRLOCK353			(0x1u<<1)
#define	BSEC_SRLOCK11_SRLOCK352			(0x1u<<0)

#define	BSEC_SRLOCK11_SRLOCK383_B_0X0	(0x0u<<31)
#define	BSEC_SRLOCK11_SRLOCK383_B_0X1	(0x1u<<31)
#define	BSEC_SRLOCK11_SRLOCK382_B_0X0	(0x0u<<30)
#define	BSEC_SRLOCK11_SRLOCK382_B_0X1	(0x1u<<30)
#define	BSEC_SRLOCK11_SRLOCK381_B_0X0	(0x0u<<29)
#define	BSEC_SRLOCK11_SRLOCK381_B_0X1	(0x1u<<29)
#define	BSEC_SRLOCK11_SRLOCK380_B_0X0	(0x0u<<28)
#define	BSEC_SRLOCK11_SRLOCK380_B_0X1	(0x1u<<28)
#define	BSEC_SRLOCK11_SRLOCK379_B_0X0	(0x0u<<27)
#define	BSEC_SRLOCK11_SRLOCK379_B_0X1	(0x1u<<27)
#define	BSEC_SRLOCK11_SRLOCK378_B_0X0	(0x0u<<26)
#define	BSEC_SRLOCK11_SRLOCK378_B_0X1	(0x1u<<26)
#define	BSEC_SRLOCK11_SRLOCK377_B_0X0	(0x0u<<25)
#define	BSEC_SRLOCK11_SRLOCK377_B_0X1	(0x1u<<25)
#define	BSEC_SRLOCK11_SRLOCK376_B_0X0	(0x0u<<24)
#define	BSEC_SRLOCK11_SRLOCK376_B_0X1	(0x1u<<24)
#define	BSEC_SRLOCK11_SRLOCK375_B_0X0	(0x0u<<23)
#define	BSEC_SRLOCK11_SRLOCK375_B_0X1	(0x1u<<23)
#define	BSEC_SRLOCK11_SRLOCK374_B_0X0	(0x0u<<22)
#define	BSEC_SRLOCK11_SRLOCK374_B_0X1	(0x1u<<22)
#define	BSEC_SRLOCK11_SRLOCK373_B_0X0	(0x0u<<21)
#define	BSEC_SRLOCK11_SRLOCK373_B_0X1	(0x1u<<21)
#define	BSEC_SRLOCK11_SRLOCK372_B_0X0	(0x0u<<20)
#define	BSEC_SRLOCK11_SRLOCK372_B_0X1	(0x1u<<20)
#define	BSEC_SRLOCK11_SRLOCK371_B_0X0	(0x0u<<19)
#define	BSEC_SRLOCK11_SRLOCK371_B_0X1	(0x1u<<19)
#define	BSEC_SRLOCK11_SRLOCK370_B_0X0	(0x0u<<18)
#define	BSEC_SRLOCK11_SRLOCK370_B_0X1	(0x1u<<18)
#define	BSEC_SRLOCK11_SRLOCK369_B_0X0	(0x0u<<17)
#define	BSEC_SRLOCK11_SRLOCK369_B_0X1	(0x1u<<17)
#define	BSEC_SRLOCK11_SRLOCK368_B_0X0	(0x0u<<16)
#define	BSEC_SRLOCK11_SRLOCK368_B_0X1	(0x1u<<16)
#define	BSEC_SRLOCK11_SRLOCK367_B_0X0	(0x0u<<15)
#define	BSEC_SRLOCK11_SRLOCK367_B_0X1	(0x1u<<15)
#define	BSEC_SRLOCK11_SRLOCK366_B_0X0	(0x0u<<14)
#define	BSEC_SRLOCK11_SRLOCK366_B_0X1	(0x1u<<14)
#define	BSEC_SRLOCK11_SRLOCK365_B_0X0	(0x0u<<13)
#define	BSEC_SRLOCK11_SRLOCK365_B_0X1	(0x1u<<13)
#define	BSEC_SRLOCK11_SRLOCK364_B_0X0	(0x0u<<12)
#define	BSEC_SRLOCK11_SRLOCK364_B_0X1	(0x1u<<12)
#define	BSEC_SRLOCK11_SRLOCK363_B_0X0	(0x0u<<11)
#define	BSEC_SRLOCK11_SRLOCK363_B_0X1	(0x1u<<11)
#define	BSEC_SRLOCK11_SRLOCK362_B_0X0	(0x0u<<10)
#define	BSEC_SRLOCK11_SRLOCK362_B_0X1	(0x1u<<10)
#define	BSEC_SRLOCK11_SRLOCK361_B_0X0	(0x0u<<9)
#define	BSEC_SRLOCK11_SRLOCK361_B_0X1	(0x1u<<9)
#define	BSEC_SRLOCK11_SRLOCK360_B_0X0	(0x0u<<8)
#define	BSEC_SRLOCK11_SRLOCK360_B_0X1	(0x1u<<8)
#define	BSEC_SRLOCK11_SRLOCK359_B_0X0	(0x0u<<7)
#define	BSEC_SRLOCK11_SRLOCK359_B_0X1	(0x1u<<7)
#define	BSEC_SRLOCK11_SRLOCK358_B_0X0	(0x0u<<6)
#define	BSEC_SRLOCK11_SRLOCK358_B_0X1	(0x1u<<6)
#define	BSEC_SRLOCK11_SRLOCK357_B_0X0	(0x0u<<5)
#define	BSEC_SRLOCK11_SRLOCK357_B_0X1	(0x1u<<5)
#define	BSEC_SRLOCK11_SRLOCK356_B_0X0	(0x0u<<4)
#define	BSEC_SRLOCK11_SRLOCK356_B_0X1	(0x1u<<4)
#define	BSEC_SRLOCK11_SRLOCK355_B_0X0	(0x0u<<3)
#define	BSEC_SRLOCK11_SRLOCK355_B_0X1	(0x1u<<3)
#define	BSEC_SRLOCK11_SRLOCK354_B_0X0	(0x0u<<2)
#define	BSEC_SRLOCK11_SRLOCK354_B_0X1	(0x1u<<2)
#define	BSEC_SRLOCK11_SRLOCK353_B_0X0	(0x0u<<1)
#define	BSEC_SRLOCK11_SRLOCK353_B_0X1	(0x1u<<1)
#define	BSEC_SRLOCK11_SRLOCK352_B_0X0	(0x0u<<0)
#define	BSEC_SRLOCK11_SRLOCK352_B_0X1	(0x1u<<0)

// OTPVLDR0 Configuration

#define	BSEC_OTPVLDR0_VLDF31			(0x1u<<31)
#define	BSEC_OTPVLDR0_VLDF30			(0x1u<<30)
#define	BSEC_OTPVLDR0_VLDF29			(0x1u<<29)
#define	BSEC_OTPVLDR0_VLDF28			(0x1u<<28)
#define	BSEC_OTPVLDR0_VLDF27			(0x1u<<27)
#define	BSEC_OTPVLDR0_VLDF26			(0x1u<<26)
#define	BSEC_OTPVLDR0_VLDF25			(0x1u<<25)
#define	BSEC_OTPVLDR0_VLDF24			(0x1u<<24)
#define	BSEC_OTPVLDR0_VLDF23			(0x1u<<23)
#define	BSEC_OTPVLDR0_VLDF22			(0x1u<<22)
#define	BSEC_OTPVLDR0_VLDF21			(0x1u<<21)
#define	BSEC_OTPVLDR0_VLDF20			(0x1u<<20)
#define	BSEC_OTPVLDR0_VLDF19			(0x1u<<19)
#define	BSEC_OTPVLDR0_VLDF18			(0x1u<<18)
#define	BSEC_OTPVLDR0_VLDF17			(0x1u<<17)
#define	BSEC_OTPVLDR0_VLDF16			(0x1u<<16)
#define	BSEC_OTPVLDR0_VLDF15			(0x1u<<15)
#define	BSEC_OTPVLDR0_VLDF14			(0x1u<<14)
#define	BSEC_OTPVLDR0_VLDF13			(0x1u<<13)
#define	BSEC_OTPVLDR0_VLDF12			(0x1u<<12)
#define	BSEC_OTPVLDR0_VLDF11			(0x1u<<11)
#define	BSEC_OTPVLDR0_VLDF10			(0x1u<<10)
#define	BSEC_OTPVLDR0_VLDF9				(0x1u<<9)
#define	BSEC_OTPVLDR0_VLDF8				(0x1u<<8)
#define	BSEC_OTPVLDR0_VLDF7				(0x1u<<7)
#define	BSEC_OTPVLDR0_VLDF6				(0x1u<<6)
#define	BSEC_OTPVLDR0_VLDF5				(0x1u<<5)
#define	BSEC_OTPVLDR0_VLDF4				(0x1u<<4)
#define	BSEC_OTPVLDR0_VLDF3				(0x1u<<3)
#define	BSEC_OTPVLDR0_VLDF2				(0x1u<<2)
#define	BSEC_OTPVLDR0_VLDF1				(0x1u<<1)
#define	BSEC_OTPVLDR0_VLDF0				(0x1u<<0)

#define	BSEC_OTPVLDR0_VLDF31_B_0X0		(0x0u<<31)
#define	BSEC_OTPVLDR0_VLDF31_B_0X1		(0x1u<<31)
#define	BSEC_OTPVLDR0_VLDF30_B_0X0		(0x0u<<30)
#define	BSEC_OTPVLDR0_VLDF30_B_0X1		(0x1u<<30)
#define	BSEC_OTPVLDR0_VLDF29_B_0X0		(0x0u<<29)
#define	BSEC_OTPVLDR0_VLDF29_B_0X1		(0x1u<<29)
#define	BSEC_OTPVLDR0_VLDF28_B_0X0		(0x0u<<28)
#define	BSEC_OTPVLDR0_VLDF28_B_0X1		(0x1u<<28)
#define	BSEC_OTPVLDR0_VLDF27_B_0X0		(0x0u<<27)
#define	BSEC_OTPVLDR0_VLDF27_B_0X1		(0x1u<<27)
#define	BSEC_OTPVLDR0_VLDF26_B_0X0		(0x0u<<26)
#define	BSEC_OTPVLDR0_VLDF26_B_0X1		(0x1u<<26)
#define	BSEC_OTPVLDR0_VLDF25_B_0X0		(0x0u<<25)
#define	BSEC_OTPVLDR0_VLDF25_B_0X1		(0x1u<<25)
#define	BSEC_OTPVLDR0_VLDF24_B_0X0		(0x0u<<24)
#define	BSEC_OTPVLDR0_VLDF24_B_0X1		(0x1u<<24)
#define	BSEC_OTPVLDR0_VLDF23_B_0X0		(0x0u<<23)
#define	BSEC_OTPVLDR0_VLDF23_B_0X1		(0x1u<<23)
#define	BSEC_OTPVLDR0_VLDF22_B_0X0		(0x0u<<22)
#define	BSEC_OTPVLDR0_VLDF22_B_0X1		(0x1u<<22)
#define	BSEC_OTPVLDR0_VLDF21_B_0X0		(0x0u<<21)
#define	BSEC_OTPVLDR0_VLDF21_B_0X1		(0x1u<<21)
#define	BSEC_OTPVLDR0_VLDF20_B_0X0		(0x0u<<20)
#define	BSEC_OTPVLDR0_VLDF20_B_0X1		(0x1u<<20)
#define	BSEC_OTPVLDR0_VLDF19_B_0X0		(0x0u<<19)
#define	BSEC_OTPVLDR0_VLDF19_B_0X1		(0x1u<<19)
#define	BSEC_OTPVLDR0_VLDF18_B_0X0		(0x0u<<18)
#define	BSEC_OTPVLDR0_VLDF18_B_0X1		(0x1u<<18)
#define	BSEC_OTPVLDR0_VLDF17_B_0X0		(0x0u<<17)
#define	BSEC_OTPVLDR0_VLDF17_B_0X1		(0x1u<<17)
#define	BSEC_OTPVLDR0_VLDF16_B_0X0		(0x0u<<16)
#define	BSEC_OTPVLDR0_VLDF16_B_0X1		(0x1u<<16)
#define	BSEC_OTPVLDR0_VLDF15_B_0X0		(0x0u<<15)
#define	BSEC_OTPVLDR0_VLDF15_B_0X1		(0x1u<<15)
#define	BSEC_OTPVLDR0_VLDF14_B_0X0		(0x0u<<14)
#define	BSEC_OTPVLDR0_VLDF14_B_0X1		(0x1u<<14)
#define	BSEC_OTPVLDR0_VLDF13_B_0X0		(0x0u<<13)
#define	BSEC_OTPVLDR0_VLDF13_B_0X1		(0x1u<<13)
#define	BSEC_OTPVLDR0_VLDF12_B_0X0		(0x0u<<12)
#define	BSEC_OTPVLDR0_VLDF12_B_0X1		(0x1u<<12)
#define	BSEC_OTPVLDR0_VLDF11_B_0X0		(0x0u<<11)
#define	BSEC_OTPVLDR0_VLDF11_B_0X1		(0x1u<<11)
#define	BSEC_OTPVLDR0_VLDF10_B_0X0		(0x0u<<10)
#define	BSEC_OTPVLDR0_VLDF10_B_0X1		(0x1u<<10)
#define	BSEC_OTPVLDR0_VLDF9_B_0X0		(0x0u<<9)
#define	BSEC_OTPVLDR0_VLDF9_B_0X1		(0x1u<<9)
#define	BSEC_OTPVLDR0_VLDF8_B_0X0		(0x0u<<8)
#define	BSEC_OTPVLDR0_VLDF8_B_0X1		(0x1u<<8)
#define	BSEC_OTPVLDR0_VLDF7_B_0X0		(0x0u<<7)
#define	BSEC_OTPVLDR0_VLDF7_B_0X1		(0x1u<<7)
#define	BSEC_OTPVLDR0_VLDF6_B_0X0		(0x0u<<6)
#define	BSEC_OTPVLDR0_VLDF6_B_0X1		(0x1u<<6)
#define	BSEC_OTPVLDR0_VLDF5_B_0X0		(0x0u<<5)
#define	BSEC_OTPVLDR0_VLDF5_B_0X1		(0x1u<<5)
#define	BSEC_OTPVLDR0_VLDF4_B_0X0		(0x0u<<4)
#define	BSEC_OTPVLDR0_VLDF4_B_0X1		(0x1u<<4)
#define	BSEC_OTPVLDR0_VLDF3_B_0X0		(0x0u<<3)
#define	BSEC_OTPVLDR0_VLDF3_B_0X1		(0x1u<<3)
#define	BSEC_OTPVLDR0_VLDF2_B_0X0		(0x0u<<2)
#define	BSEC_OTPVLDR0_VLDF2_B_0X1		(0x1u<<2)
#define	BSEC_OTPVLDR0_VLDF1_B_0X0		(0x0u<<1)
#define	BSEC_OTPVLDR0_VLDF1_B_0X1		(0x1u<<1)
#define	BSEC_OTPVLDR0_VLDF0_B_0X0		(0x0u<<0)
#define	BSEC_OTPVLDR0_VLDF0_B_0X1		(0x1u<<0)

// OTPVLDR1 Configuration

#define	BSEC_OTPVLDR1_VLDF63			(0x1u<<31)
#define	BSEC_OTPVLDR1_VLDF62			(0x1u<<30)
#define	BSEC_OTPVLDR1_VLDF61			(0x1u<<29)
#define	BSEC_OTPVLDR1_VLDF60			(0x1u<<28)
#define	BSEC_OTPVLDR1_VLDF59			(0x1u<<27)
#define	BSEC_OTPVLDR1_VLDF58			(0x1u<<26)
#define	BSEC_OTPVLDR1_VLDF57			(0x1u<<25)
#define	BSEC_OTPVLDR1_VLDF56			(0x1u<<24)
#define	BSEC_OTPVLDR1_VLDF55			(0x1u<<23)
#define	BSEC_OTPVLDR1_VLDF54			(0x1u<<22)
#define	BSEC_OTPVLDR1_VLDF53			(0x1u<<21)
#define	BSEC_OTPVLDR1_VLDF52			(0x1u<<20)
#define	BSEC_OTPVLDR1_VLDF51			(0x1u<<19)
#define	BSEC_OTPVLDR1_VLDF50			(0x1u<<18)
#define	BSEC_OTPVLDR1_VLDF49			(0x1u<<17)
#define	BSEC_OTPVLDR1_VLDF48			(0x1u<<16)
#define	BSEC_OTPVLDR1_VLDF47			(0x1u<<15)
#define	BSEC_OTPVLDR1_VLDF46			(0x1u<<14)
#define	BSEC_OTPVLDR1_VLDF45			(0x1u<<13)
#define	BSEC_OTPVLDR1_VLDF44			(0x1u<<12)
#define	BSEC_OTPVLDR1_VLDF43			(0x1u<<11)
#define	BSEC_OTPVLDR1_VLDF42			(0x1u<<10)
#define	BSEC_OTPVLDR1_VLDF41			(0x1u<<9)
#define	BSEC_OTPVLDR1_VLDF40			(0x1u<<8)
#define	BSEC_OTPVLDR1_VLDF39			(0x1u<<7)
#define	BSEC_OTPVLDR1_VLDF38			(0x1u<<6)
#define	BSEC_OTPVLDR1_VLDF37			(0x1u<<5)
#define	BSEC_OTPVLDR1_VLDF36			(0x1u<<4)
#define	BSEC_OTPVLDR1_VLDF35			(0x1u<<3)
#define	BSEC_OTPVLDR1_VLDF34			(0x1u<<2)
#define	BSEC_OTPVLDR1_VLDF33			(0x1u<<1)
#define	BSEC_OTPVLDR1_VLDF32			(0x1u<<0)

#define	BSEC_OTPVLDR1_VLDF63_B_0X0		(0x0u<<31)
#define	BSEC_OTPVLDR1_VLDF63_B_0X1		(0x1u<<31)
#define	BSEC_OTPVLDR1_VLDF62_B_0X0		(0x0u<<30)
#define	BSEC_OTPVLDR1_VLDF62_B_0X1		(0x1u<<30)
#define	BSEC_OTPVLDR1_VLDF61_B_0X0		(0x0u<<29)
#define	BSEC_OTPVLDR1_VLDF61_B_0X1		(0x1u<<29)
#define	BSEC_OTPVLDR1_VLDF60_B_0X0		(0x0u<<28)
#define	BSEC_OTPVLDR1_VLDF60_B_0X1		(0x1u<<28)
#define	BSEC_OTPVLDR1_VLDF59_B_0X0		(0x0u<<27)
#define	BSEC_OTPVLDR1_VLDF59_B_0X1		(0x1u<<27)
#define	BSEC_OTPVLDR1_VLDF58_B_0X0		(0x0u<<26)
#define	BSEC_OTPVLDR1_VLDF58_B_0X1		(0x1u<<26)
#define	BSEC_OTPVLDR1_VLDF57_B_0X0		(0x0u<<25)
#define	BSEC_OTPVLDR1_VLDF57_B_0X1		(0x1u<<25)
#define	BSEC_OTPVLDR1_VLDF56_B_0X0		(0x0u<<24)
#define	BSEC_OTPVLDR1_VLDF56_B_0X1		(0x1u<<24)
#define	BSEC_OTPVLDR1_VLDF55_B_0X0		(0x0u<<23)
#define	BSEC_OTPVLDR1_VLDF55_B_0X1		(0x1u<<23)
#define	BSEC_OTPVLDR1_VLDF54_B_0X0		(0x0u<<22)
#define	BSEC_OTPVLDR1_VLDF54_B_0X1		(0x1u<<22)
#define	BSEC_OTPVLDR1_VLDF53_B_0X0		(0x0u<<21)
#define	BSEC_OTPVLDR1_VLDF53_B_0X1		(0x1u<<21)
#define	BSEC_OTPVLDR1_VLDF52_B_0X0		(0x0u<<20)
#define	BSEC_OTPVLDR1_VLDF52_B_0X1		(0x1u<<20)
#define	BSEC_OTPVLDR1_VLDF51_B_0X0		(0x0u<<19)
#define	BSEC_OTPVLDR1_VLDF51_B_0X1		(0x1u<<19)
#define	BSEC_OTPVLDR1_VLDF50_B_0X0		(0x0u<<18)
#define	BSEC_OTPVLDR1_VLDF50_B_0X1		(0x1u<<18)
#define	BSEC_OTPVLDR1_VLDF49_B_0X0		(0x0u<<17)
#define	BSEC_OTPVLDR1_VLDF49_B_0X1		(0x1u<<17)
#define	BSEC_OTPVLDR1_VLDF48_B_0X0		(0x0u<<16)
#define	BSEC_OTPVLDR1_VLDF48_B_0X1		(0x1u<<16)
#define	BSEC_OTPVLDR1_VLDF47_B_0X0		(0x0u<<15)
#define	BSEC_OTPVLDR1_VLDF47_B_0X1		(0x1u<<15)
#define	BSEC_OTPVLDR1_VLDF46_B_0X0		(0x0u<<14)
#define	BSEC_OTPVLDR1_VLDF46_B_0X1		(0x1u<<14)
#define	BSEC_OTPVLDR1_VLDF45_B_0X0		(0x0u<<13)
#define	BSEC_OTPVLDR1_VLDF45_B_0X1		(0x1u<<13)
#define	BSEC_OTPVLDR1_VLDF44_B_0X0		(0x0u<<12)
#define	BSEC_OTPVLDR1_VLDF44_B_0X1		(0x1u<<12)
#define	BSEC_OTPVLDR1_VLDF43_B_0X0		(0x0u<<11)
#define	BSEC_OTPVLDR1_VLDF43_B_0X1		(0x1u<<11)
#define	BSEC_OTPVLDR1_VLDF42_B_0X0		(0x0u<<10)
#define	BSEC_OTPVLDR1_VLDF42_B_0X1		(0x1u<<10)
#define	BSEC_OTPVLDR1_VLDF41_B_0X0		(0x0u<<9)
#define	BSEC_OTPVLDR1_VLDF41_B_0X1		(0x1u<<9)
#define	BSEC_OTPVLDR1_VLDF40_B_0X0		(0x0u<<8)
#define	BSEC_OTPVLDR1_VLDF40_B_0X1		(0x1u<<8)
#define	BSEC_OTPVLDR1_VLDF39_B_0X0		(0x0u<<7)
#define	BSEC_OTPVLDR1_VLDF39_B_0X1		(0x1u<<7)
#define	BSEC_OTPVLDR1_VLDF38_B_0X0		(0x0u<<6)
#define	BSEC_OTPVLDR1_VLDF38_B_0X1		(0x1u<<6)
#define	BSEC_OTPVLDR1_VLDF37_B_0X0		(0x0u<<5)
#define	BSEC_OTPVLDR1_VLDF37_B_0X1		(0x1u<<5)
#define	BSEC_OTPVLDR1_VLDF36_B_0X0		(0x0u<<4)
#define	BSEC_OTPVLDR1_VLDF36_B_0X1		(0x1u<<4)
#define	BSEC_OTPVLDR1_VLDF35_B_0X0		(0x0u<<3)
#define	BSEC_OTPVLDR1_VLDF35_B_0X1		(0x1u<<3)
#define	BSEC_OTPVLDR1_VLDF34_B_0X0		(0x0u<<2)
#define	BSEC_OTPVLDR1_VLDF34_B_0X1		(0x1u<<2)
#define	BSEC_OTPVLDR1_VLDF33_B_0X0		(0x0u<<1)
#define	BSEC_OTPVLDR1_VLDF33_B_0X1		(0x1u<<1)
#define	BSEC_OTPVLDR1_VLDF32_B_0X0		(0x0u<<0)
#define	BSEC_OTPVLDR1_VLDF32_B_0X1		(0x1u<<0)

// OTPVLDR2 Configuration

#define	BSEC_OTPVLDR2_VLDF95			(0x1u<<31)
#define	BSEC_OTPVLDR2_VLDF94			(0x1u<<30)
#define	BSEC_OTPVLDR2_VLDF93			(0x1u<<29)
#define	BSEC_OTPVLDR2_VLDF92			(0x1u<<28)
#define	BSEC_OTPVLDR2_VLDF91			(0x1u<<27)
#define	BSEC_OTPVLDR2_VLDF90			(0x1u<<26)
#define	BSEC_OTPVLDR2_VLDF89			(0x1u<<25)
#define	BSEC_OTPVLDR2_VLDF88			(0x1u<<24)
#define	BSEC_OTPVLDR2_VLDF87			(0x1u<<23)
#define	BSEC_OTPVLDR2_VLDF86			(0x1u<<22)
#define	BSEC_OTPVLDR2_VLDF85			(0x1u<<21)
#define	BSEC_OTPVLDR2_VLDF84			(0x1u<<20)
#define	BSEC_OTPVLDR2_VLDF83			(0x1u<<19)
#define	BSEC_OTPVLDR2_VLDF82			(0x1u<<18)
#define	BSEC_OTPVLDR2_VLDF81			(0x1u<<17)
#define	BSEC_OTPVLDR2_VLDF80			(0x1u<<16)
#define	BSEC_OTPVLDR2_VLDF79			(0x1u<<15)
#define	BSEC_OTPVLDR2_VLDF78			(0x1u<<14)
#define	BSEC_OTPVLDR2_VLDF77			(0x1u<<13)
#define	BSEC_OTPVLDR2_VLDF76			(0x1u<<12)
#define	BSEC_OTPVLDR2_VLDF75			(0x1u<<11)
#define	BSEC_OTPVLDR2_VLDF74			(0x1u<<10)
#define	BSEC_OTPVLDR2_VLDF73			(0x1u<<9)
#define	BSEC_OTPVLDR2_VLDF72			(0x1u<<8)
#define	BSEC_OTPVLDR2_VLDF71			(0x1u<<7)
#define	BSEC_OTPVLDR2_VLDF70			(0x1u<<6)
#define	BSEC_OTPVLDR2_VLDF69			(0x1u<<5)
#define	BSEC_OTPVLDR2_VLDF68			(0x1u<<4)
#define	BSEC_OTPVLDR2_VLDF67			(0x1u<<3)
#define	BSEC_OTPVLDR2_VLDF66			(0x1u<<2)
#define	BSEC_OTPVLDR2_VLDF65			(0x1u<<1)
#define	BSEC_OTPVLDR2_VLDF64			(0x1u<<0)

#define	BSEC_OTPVLDR2_VLDF95_B_0X0		(0x0u<<31)
#define	BSEC_OTPVLDR2_VLDF95_B_0X1		(0x1u<<31)
#define	BSEC_OTPVLDR2_VLDF94_B_0X0		(0x0u<<30)
#define	BSEC_OTPVLDR2_VLDF94_B_0X1		(0x1u<<30)
#define	BSEC_OTPVLDR2_VLDF93_B_0X0		(0x0u<<29)
#define	BSEC_OTPVLDR2_VLDF93_B_0X1		(0x1u<<29)
#define	BSEC_OTPVLDR2_VLDF92_B_0X0		(0x0u<<28)
#define	BSEC_OTPVLDR2_VLDF92_B_0X1		(0x1u<<28)
#define	BSEC_OTPVLDR2_VLDF91_B_0X0		(0x0u<<27)
#define	BSEC_OTPVLDR2_VLDF91_B_0X1		(0x1u<<27)
#define	BSEC_OTPVLDR2_VLDF90_B_0X0		(0x0u<<26)
#define	BSEC_OTPVLDR2_VLDF90_B_0X1		(0x1u<<26)
#define	BSEC_OTPVLDR2_VLDF89_B_0X0		(0x0u<<25)
#define	BSEC_OTPVLDR2_VLDF89_B_0X1		(0x1u<<25)
#define	BSEC_OTPVLDR2_VLDF88_B_0X0		(0x0u<<24)
#define	BSEC_OTPVLDR2_VLDF88_B_0X1		(0x1u<<24)
#define	BSEC_OTPVLDR2_VLDF87_B_0X0		(0x0u<<23)
#define	BSEC_OTPVLDR2_VLDF87_B_0X1		(0x1u<<23)
#define	BSEC_OTPVLDR2_VLDF86_B_0X0		(0x0u<<22)
#define	BSEC_OTPVLDR2_VLDF86_B_0X1		(0x1u<<22)
#define	BSEC_OTPVLDR2_VLDF85_B_0X0		(0x0u<<21)
#define	BSEC_OTPVLDR2_VLDF85_B_0X1		(0x1u<<21)
#define	BSEC_OTPVLDR2_VLDF84_B_0X0		(0x0u<<20)
#define	BSEC_OTPVLDR2_VLDF84_B_0X1		(0x1u<<20)
#define	BSEC_OTPVLDR2_VLDF83_B_0X0		(0x0u<<19)
#define	BSEC_OTPVLDR2_VLDF83_B_0X1		(0x1u<<19)
#define	BSEC_OTPVLDR2_VLDF82_B_0X0		(0x0u<<18)
#define	BSEC_OTPVLDR2_VLDF82_B_0X1		(0x1u<<18)
#define	BSEC_OTPVLDR2_VLDF81_B_0X0		(0x0u<<17)
#define	BSEC_OTPVLDR2_VLDF81_B_0X1		(0x1u<<17)
#define	BSEC_OTPVLDR2_VLDF80_B_0X0		(0x0u<<16)
#define	BSEC_OTPVLDR2_VLDF80_B_0X1		(0x1u<<16)
#define	BSEC_OTPVLDR2_VLDF79_B_0X0		(0x0u<<15)
#define	BSEC_OTPVLDR2_VLDF79_B_0X1		(0x1u<<15)
#define	BSEC_OTPVLDR2_VLDF78_B_0X0		(0x0u<<14)
#define	BSEC_OTPVLDR2_VLDF78_B_0X1		(0x1u<<14)
#define	BSEC_OTPVLDR2_VLDF77_B_0X0		(0x0u<<13)
#define	BSEC_OTPVLDR2_VLDF77_B_0X1		(0x1u<<13)
#define	BSEC_OTPVLDR2_VLDF76_B_0X0		(0x0u<<12)
#define	BSEC_OTPVLDR2_VLDF76_B_0X1		(0x1u<<12)
#define	BSEC_OTPVLDR2_VLDF75_B_0X0		(0x0u<<11)
#define	BSEC_OTPVLDR2_VLDF75_B_0X1		(0x1u<<11)
#define	BSEC_OTPVLDR2_VLDF74_B_0X0		(0x0u<<10)
#define	BSEC_OTPVLDR2_VLDF74_B_0X1		(0x1u<<10)
#define	BSEC_OTPVLDR2_VLDF73_B_0X0		(0x0u<<9)
#define	BSEC_OTPVLDR2_VLDF73_B_0X1		(0x1u<<9)
#define	BSEC_OTPVLDR2_VLDF72_B_0X0		(0x0u<<8)
#define	BSEC_OTPVLDR2_VLDF72_B_0X1		(0x1u<<8)
#define	BSEC_OTPVLDR2_VLDF71_B_0X0		(0x0u<<7)
#define	BSEC_OTPVLDR2_VLDF71_B_0X1		(0x1u<<7)
#define	BSEC_OTPVLDR2_VLDF70_B_0X0		(0x0u<<6)
#define	BSEC_OTPVLDR2_VLDF70_B_0X1		(0x1u<<6)
#define	BSEC_OTPVLDR2_VLDF69_B_0X0		(0x0u<<5)
#define	BSEC_OTPVLDR2_VLDF69_B_0X1		(0x1u<<5)
#define	BSEC_OTPVLDR2_VLDF68_B_0X0		(0x0u<<4)
#define	BSEC_OTPVLDR2_VLDF68_B_0X1		(0x1u<<4)
#define	BSEC_OTPVLDR2_VLDF67_B_0X0		(0x0u<<3)
#define	BSEC_OTPVLDR2_VLDF67_B_0X1		(0x1u<<3)
#define	BSEC_OTPVLDR2_VLDF66_B_0X0		(0x0u<<2)
#define	BSEC_OTPVLDR2_VLDF66_B_0X1		(0x1u<<2)
#define	BSEC_OTPVLDR2_VLDF65_B_0X0		(0x0u<<1)
#define	BSEC_OTPVLDR2_VLDF65_B_0X1		(0x1u<<1)
#define	BSEC_OTPVLDR2_VLDF64_B_0X0		(0x0u<<0)
#define	BSEC_OTPVLDR2_VLDF64_B_0X1		(0x1u<<0)

// OTPVLDR3 Configuration

#define	BSEC_OTPVLDR3_VLDF127			(0x1u<<31)
#define	BSEC_OTPVLDR3_VLDF126			(0x1u<<30)
#define	BSEC_OTPVLDR3_VLDF125			(0x1u<<29)
#define	BSEC_OTPVLDR3_VLDF124			(0x1u<<28)
#define	BSEC_OTPVLDR3_VLDF123			(0x1u<<27)
#define	BSEC_OTPVLDR3_VLDF122			(0x1u<<26)
#define	BSEC_OTPVLDR3_VLDF121			(0x1u<<25)
#define	BSEC_OTPVLDR3_VLDF120			(0x1u<<24)
#define	BSEC_OTPVLDR3_VLDF119			(0x1u<<23)
#define	BSEC_OTPVLDR3_VLDF118			(0x1u<<22)
#define	BSEC_OTPVLDR3_VLDF117			(0x1u<<21)
#define	BSEC_OTPVLDR3_VLDF116			(0x1u<<20)
#define	BSEC_OTPVLDR3_VLDF115			(0x1u<<19)
#define	BSEC_OTPVLDR3_VLDF114			(0x1u<<18)
#define	BSEC_OTPVLDR3_VLDF113			(0x1u<<17)
#define	BSEC_OTPVLDR3_VLDF112			(0x1u<<16)
#define	BSEC_OTPVLDR3_VLDF111			(0x1u<<15)
#define	BSEC_OTPVLDR3_VLDF110			(0x1u<<14)
#define	BSEC_OTPVLDR3_VLDF109			(0x1u<<13)
#define	BSEC_OTPVLDR3_VLDF108			(0x1u<<12)
#define	BSEC_OTPVLDR3_VLDF107			(0x1u<<11)
#define	BSEC_OTPVLDR3_VLDF106			(0x1u<<10)
#define	BSEC_OTPVLDR3_VLDF105			(0x1u<<9)
#define	BSEC_OTPVLDR3_VLDF104			(0x1u<<8)
#define	BSEC_OTPVLDR3_VLDF103			(0x1u<<7)
#define	BSEC_OTPVLDR3_VLDF102			(0x1u<<6)
#define	BSEC_OTPVLDR3_VLDF101			(0x1u<<5)
#define	BSEC_OTPVLDR3_VLDF100			(0x1u<<4)
#define	BSEC_OTPVLDR3_VLDF99			(0x1u<<3)
#define	BSEC_OTPVLDR3_VLDF98			(0x1u<<2)
#define	BSEC_OTPVLDR3_VLDF97			(0x1u<<1)
#define	BSEC_OTPVLDR3_VLDF96			(0x1u<<0)

#define	BSEC_OTPVLDR3_VLDF127_B_0X0		(0x0u<<31)
#define	BSEC_OTPVLDR3_VLDF127_B_0X1		(0x1u<<31)
#define	BSEC_OTPVLDR3_VLDF126_B_0X0		(0x0u<<30)
#define	BSEC_OTPVLDR3_VLDF126_B_0X1		(0x1u<<30)
#define	BSEC_OTPVLDR3_VLDF125_B_0X0		(0x0u<<29)
#define	BSEC_OTPVLDR3_VLDF125_B_0X1		(0x1u<<29)
#define	BSEC_OTPVLDR3_VLDF124_B_0X0		(0x0u<<28)
#define	BSEC_OTPVLDR3_VLDF124_B_0X1		(0x1u<<28)
#define	BSEC_OTPVLDR3_VLDF123_B_0X0		(0x0u<<27)
#define	BSEC_OTPVLDR3_VLDF123_B_0X1		(0x1u<<27)
#define	BSEC_OTPVLDR3_VLDF122_B_0X0		(0x0u<<26)
#define	BSEC_OTPVLDR3_VLDF122_B_0X1		(0x1u<<26)
#define	BSEC_OTPVLDR3_VLDF121_B_0X0		(0x0u<<25)
#define	BSEC_OTPVLDR3_VLDF121_B_0X1		(0x1u<<25)
#define	BSEC_OTPVLDR3_VLDF120_B_0X0		(0x0u<<24)
#define	BSEC_OTPVLDR3_VLDF120_B_0X1		(0x1u<<24)
#define	BSEC_OTPVLDR3_VLDF119_B_0X0		(0x0u<<23)
#define	BSEC_OTPVLDR3_VLDF119_B_0X1		(0x1u<<23)
#define	BSEC_OTPVLDR3_VLDF118_B_0X0		(0x0u<<22)
#define	BSEC_OTPVLDR3_VLDF118_B_0X1		(0x1u<<22)
#define	BSEC_OTPVLDR3_VLDF117_B_0X0		(0x0u<<21)
#define	BSEC_OTPVLDR3_VLDF117_B_0X1		(0x1u<<21)
#define	BSEC_OTPVLDR3_VLDF116_B_0X0		(0x0u<<20)
#define	BSEC_OTPVLDR3_VLDF116_B_0X1		(0x1u<<20)
#define	BSEC_OTPVLDR3_VLDF115_B_0X0		(0x0u<<19)
#define	BSEC_OTPVLDR3_VLDF115_B_0X1		(0x1u<<19)
#define	BSEC_OTPVLDR3_VLDF114_B_0X0		(0x0u<<18)
#define	BSEC_OTPVLDR3_VLDF114_B_0X1		(0x1u<<18)
#define	BSEC_OTPVLDR3_VLDF113_B_0X0		(0x0u<<17)
#define	BSEC_OTPVLDR3_VLDF113_B_0X1		(0x1u<<17)
#define	BSEC_OTPVLDR3_VLDF112_B_0X0		(0x0u<<16)
#define	BSEC_OTPVLDR3_VLDF112_B_0X1		(0x1u<<16)
#define	BSEC_OTPVLDR3_VLDF111_B_0X0		(0x0u<<15)
#define	BSEC_OTPVLDR3_VLDF111_B_0X1		(0x1u<<15)
#define	BSEC_OTPVLDR3_VLDF110_B_0X0		(0x0u<<14)
#define	BSEC_OTPVLDR3_VLDF110_B_0X1		(0x1u<<14)
#define	BSEC_OTPVLDR3_VLDF109_B_0X0		(0x0u<<13)
#define	BSEC_OTPVLDR3_VLDF109_B_0X1		(0x1u<<13)
#define	BSEC_OTPVLDR3_VLDF108_B_0X0		(0x0u<<12)
#define	BSEC_OTPVLDR3_VLDF108_B_0X1		(0x1u<<12)
#define	BSEC_OTPVLDR3_VLDF107_B_0X0		(0x0u<<11)
#define	BSEC_OTPVLDR3_VLDF107_B_0X1		(0x1u<<11)
#define	BSEC_OTPVLDR3_VLDF106_B_0X0		(0x0u<<10)
#define	BSEC_OTPVLDR3_VLDF106_B_0X1		(0x1u<<10)
#define	BSEC_OTPVLDR3_VLDF105_B_0X0		(0x0u<<9)
#define	BSEC_OTPVLDR3_VLDF105_B_0X1		(0x1u<<9)
#define	BSEC_OTPVLDR3_VLDF104_B_0X0		(0x0u<<8)
#define	BSEC_OTPVLDR3_VLDF104_B_0X1		(0x1u<<8)
#define	BSEC_OTPVLDR3_VLDF103_B_0X0		(0x0u<<7)
#define	BSEC_OTPVLDR3_VLDF103_B_0X1		(0x1u<<7)
#define	BSEC_OTPVLDR3_VLDF102_B_0X0		(0x0u<<6)
#define	BSEC_OTPVLDR3_VLDF102_B_0X1		(0x1u<<6)
#define	BSEC_OTPVLDR3_VLDF101_B_0X0		(0x0u<<5)
#define	BSEC_OTPVLDR3_VLDF101_B_0X1		(0x1u<<5)
#define	BSEC_OTPVLDR3_VLDF100_B_0X0		(0x0u<<4)
#define	BSEC_OTPVLDR3_VLDF100_B_0X1		(0x1u<<4)
#define	BSEC_OTPVLDR3_VLDF99_B_0X0		(0x0u<<3)
#define	BSEC_OTPVLDR3_VLDF99_B_0X1		(0x1u<<3)
#define	BSEC_OTPVLDR3_VLDF98_B_0X0		(0x0u<<2)
#define	BSEC_OTPVLDR3_VLDF98_B_0X1		(0x1u<<2)
#define	BSEC_OTPVLDR3_VLDF97_B_0X0		(0x0u<<1)
#define	BSEC_OTPVLDR3_VLDF97_B_0X1		(0x1u<<1)
#define	BSEC_OTPVLDR3_VLDF96_B_0X0		(0x0u<<0)
#define	BSEC_OTPVLDR3_VLDF96_B_0X1		(0x1u<<0)

// OTPVLDR4 Configuration

#define	BSEC_OTPVLDR4_VLDF159			(0x1u<<31)
#define	BSEC_OTPVLDR4_VLDF158			(0x1u<<30)
#define	BSEC_OTPVLDR4_VLDF157			(0x1u<<29)
#define	BSEC_OTPVLDR4_VLDF156			(0x1u<<28)
#define	BSEC_OTPVLDR4_VLDF155			(0x1u<<27)
#define	BSEC_OTPVLDR4_VLDF154			(0x1u<<26)
#define	BSEC_OTPVLDR4_VLDF153			(0x1u<<25)
#define	BSEC_OTPVLDR4_VLDF152			(0x1u<<24)
#define	BSEC_OTPVLDR4_VLDF151			(0x1u<<23)
#define	BSEC_OTPVLDR4_VLDF150			(0x1u<<22)
#define	BSEC_OTPVLDR4_VLDF149			(0x1u<<21)
#define	BSEC_OTPVLDR4_VLDF148			(0x1u<<20)
#define	BSEC_OTPVLDR4_VLDF147			(0x1u<<19)
#define	BSEC_OTPVLDR4_VLDF146			(0x1u<<18)
#define	BSEC_OTPVLDR4_VLDF145			(0x1u<<17)
#define	BSEC_OTPVLDR4_VLDF144			(0x1u<<16)
#define	BSEC_OTPVLDR4_VLDF143			(0x1u<<15)
#define	BSEC_OTPVLDR4_VLDF142			(0x1u<<14)
#define	BSEC_OTPVLDR4_VLDF141			(0x1u<<13)
#define	BSEC_OTPVLDR4_VLDF140			(0x1u<<12)
#define	BSEC_OTPVLDR4_VLDF139			(0x1u<<11)
#define	BSEC_OTPVLDR4_VLDF138			(0x1u<<10)
#define	BSEC_OTPVLDR4_VLDF137			(0x1u<<9)
#define	BSEC_OTPVLDR4_VLDF136			(0x1u<<8)
#define	BSEC_OTPVLDR4_VLDF135			(0x1u<<7)
#define	BSEC_OTPVLDR4_VLDF134			(0x1u<<6)
#define	BSEC_OTPVLDR4_VLDF133			(0x1u<<5)
#define	BSEC_OTPVLDR4_VLDF132			(0x1u<<4)
#define	BSEC_OTPVLDR4_VLDF131			(0x1u<<3)
#define	BSEC_OTPVLDR4_VLDF130			(0x1u<<2)
#define	BSEC_OTPVLDR4_VLDF129			(0x1u<<1)
#define	BSEC_OTPVLDR4_VLDF128			(0x1u<<0)

#define	BSEC_OTPVLDR4_VLDF159_B_0X0		(0x0u<<31)
#define	BSEC_OTPVLDR4_VLDF159_B_0X1		(0x1u<<31)
#define	BSEC_OTPVLDR4_VLDF158_B_0X0		(0x0u<<30)
#define	BSEC_OTPVLDR4_VLDF158_B_0X1		(0x1u<<30)
#define	BSEC_OTPVLDR4_VLDF157_B_0X0		(0x0u<<29)
#define	BSEC_OTPVLDR4_VLDF157_B_0X1		(0x1u<<29)
#define	BSEC_OTPVLDR4_VLDF156_B_0X0		(0x0u<<28)
#define	BSEC_OTPVLDR4_VLDF156_B_0X1		(0x1u<<28)
#define	BSEC_OTPVLDR4_VLDF155_B_0X0		(0x0u<<27)
#define	BSEC_OTPVLDR4_VLDF155_B_0X1		(0x1u<<27)
#define	BSEC_OTPVLDR4_VLDF154_B_0X0		(0x0u<<26)
#define	BSEC_OTPVLDR4_VLDF154_B_0X1		(0x1u<<26)
#define	BSEC_OTPVLDR4_VLDF153_B_0X0		(0x0u<<25)
#define	BSEC_OTPVLDR4_VLDF153_B_0X1		(0x1u<<25)
#define	BSEC_OTPVLDR4_VLDF152_B_0X0		(0x0u<<24)
#define	BSEC_OTPVLDR4_VLDF152_B_0X1		(0x1u<<24)
#define	BSEC_OTPVLDR4_VLDF151_B_0X0		(0x0u<<23)
#define	BSEC_OTPVLDR4_VLDF151_B_0X1		(0x1u<<23)
#define	BSEC_OTPVLDR4_VLDF150_B_0X0		(0x0u<<22)
#define	BSEC_OTPVLDR4_VLDF150_B_0X1		(0x1u<<22)
#define	BSEC_OTPVLDR4_VLDF149_B_0X0		(0x0u<<21)
#define	BSEC_OTPVLDR4_VLDF149_B_0X1		(0x1u<<21)
#define	BSEC_OTPVLDR4_VLDF148_B_0X0		(0x0u<<20)
#define	BSEC_OTPVLDR4_VLDF148_B_0X1		(0x1u<<20)
#define	BSEC_OTPVLDR4_VLDF147_B_0X0		(0x0u<<19)
#define	BSEC_OTPVLDR4_VLDF147_B_0X1		(0x1u<<19)
#define	BSEC_OTPVLDR4_VLDF146_B_0X0		(0x0u<<18)
#define	BSEC_OTPVLDR4_VLDF146_B_0X1		(0x1u<<18)
#define	BSEC_OTPVLDR4_VLDF145_B_0X0		(0x0u<<17)
#define	BSEC_OTPVLDR4_VLDF145_B_0X1		(0x1u<<17)
#define	BSEC_OTPVLDR4_VLDF144_B_0X0		(0x0u<<16)
#define	BSEC_OTPVLDR4_VLDF144_B_0X1		(0x1u<<16)
#define	BSEC_OTPVLDR4_VLDF143_B_0X0		(0x0u<<15)
#define	BSEC_OTPVLDR4_VLDF143_B_0X1		(0x1u<<15)
#define	BSEC_OTPVLDR4_VLDF142_B_0X0		(0x0u<<14)
#define	BSEC_OTPVLDR4_VLDF142_B_0X1		(0x1u<<14)
#define	BSEC_OTPVLDR4_VLDF141_B_0X0		(0x0u<<13)
#define	BSEC_OTPVLDR4_VLDF141_B_0X1		(0x1u<<13)
#define	BSEC_OTPVLDR4_VLDF140_B_0X0		(0x0u<<12)
#define	BSEC_OTPVLDR4_VLDF140_B_0X1		(0x1u<<12)
#define	BSEC_OTPVLDR4_VLDF139_B_0X0		(0x0u<<11)
#define	BSEC_OTPVLDR4_VLDF139_B_0X1		(0x1u<<11)
#define	BSEC_OTPVLDR4_VLDF138_B_0X0		(0x0u<<10)
#define	BSEC_OTPVLDR4_VLDF138_B_0X1		(0x1u<<10)
#define	BSEC_OTPVLDR4_VLDF137_B_0X0		(0x0u<<9)
#define	BSEC_OTPVLDR4_VLDF137_B_0X1		(0x1u<<9)
#define	BSEC_OTPVLDR4_VLDF136_B_0X0		(0x0u<<8)
#define	BSEC_OTPVLDR4_VLDF136_B_0X1		(0x1u<<8)
#define	BSEC_OTPVLDR4_VLDF135_B_0X0		(0x0u<<7)
#define	BSEC_OTPVLDR4_VLDF135_B_0X1		(0x1u<<7)
#define	BSEC_OTPVLDR4_VLDF134_B_0X0		(0x0u<<6)
#define	BSEC_OTPVLDR4_VLDF134_B_0X1		(0x1u<<6)
#define	BSEC_OTPVLDR4_VLDF133_B_0X0		(0x0u<<5)
#define	BSEC_OTPVLDR4_VLDF133_B_0X1		(0x1u<<5)
#define	BSEC_OTPVLDR4_VLDF132_B_0X0		(0x0u<<4)
#define	BSEC_OTPVLDR4_VLDF132_B_0X1		(0x1u<<4)
#define	BSEC_OTPVLDR4_VLDF131_B_0X0		(0x0u<<3)
#define	BSEC_OTPVLDR4_VLDF131_B_0X1		(0x1u<<3)
#define	BSEC_OTPVLDR4_VLDF130_B_0X0		(0x0u<<2)
#define	BSEC_OTPVLDR4_VLDF130_B_0X1		(0x1u<<2)
#define	BSEC_OTPVLDR4_VLDF129_B_0X0		(0x0u<<1)
#define	BSEC_OTPVLDR4_VLDF129_B_0X1		(0x1u<<1)
#define	BSEC_OTPVLDR4_VLDF128_B_0X0		(0x0u<<0)
#define	BSEC_OTPVLDR4_VLDF128_B_0X1		(0x1u<<0)

// OTPVLDR5 Configuration

#define	BSEC_OTPVLDR5_VLDF191			(0x1u<<31)
#define	BSEC_OTPVLDR5_VLDF190			(0x1u<<30)
#define	BSEC_OTPVLDR5_VLDF189			(0x1u<<29)
#define	BSEC_OTPVLDR5_VLDF188			(0x1u<<28)
#define	BSEC_OTPVLDR5_VLDF187			(0x1u<<27)
#define	BSEC_OTPVLDR5_VLDF186			(0x1u<<26)
#define	BSEC_OTPVLDR5_VLDF185			(0x1u<<25)
#define	BSEC_OTPVLDR5_VLDF184			(0x1u<<24)
#define	BSEC_OTPVLDR5_VLDF183			(0x1u<<23)
#define	BSEC_OTPVLDR5_VLDF182			(0x1u<<22)
#define	BSEC_OTPVLDR5_VLDF181			(0x1u<<21)
#define	BSEC_OTPVLDR5_VLDF180			(0x1u<<20)
#define	BSEC_OTPVLDR5_VLDF179			(0x1u<<19)
#define	BSEC_OTPVLDR5_VLDF178			(0x1u<<18)
#define	BSEC_OTPVLDR5_VLDF177			(0x1u<<17)
#define	BSEC_OTPVLDR5_VLDF176			(0x1u<<16)
#define	BSEC_OTPVLDR5_VLDF175			(0x1u<<15)
#define	BSEC_OTPVLDR5_VLDF174			(0x1u<<14)
#define	BSEC_OTPVLDR5_VLDF173			(0x1u<<13)
#define	BSEC_OTPVLDR5_VLDF172			(0x1u<<12)
#define	BSEC_OTPVLDR5_VLDF171			(0x1u<<11)
#define	BSEC_OTPVLDR5_VLDF170			(0x1u<<10)
#define	BSEC_OTPVLDR5_VLDF169			(0x1u<<9)
#define	BSEC_OTPVLDR5_VLDF168			(0x1u<<8)
#define	BSEC_OTPVLDR5_VLDF167			(0x1u<<7)
#define	BSEC_OTPVLDR5_VLDF166			(0x1u<<6)
#define	BSEC_OTPVLDR5_VLDF165			(0x1u<<5)
#define	BSEC_OTPVLDR5_VLDF164			(0x1u<<4)
#define	BSEC_OTPVLDR5_VLDF163			(0x1u<<3)
#define	BSEC_OTPVLDR5_VLDF162			(0x1u<<2)
#define	BSEC_OTPVLDR5_VLDF161			(0x1u<<1)
#define	BSEC_OTPVLDR5_VLDF160			(0x1u<<0)

#define	BSEC_OTPVLDR5_VLDF191_B_0X0		(0x0u<<31)
#define	BSEC_OTPVLDR5_VLDF191_B_0X1		(0x1u<<31)
#define	BSEC_OTPVLDR5_VLDF190_B_0X0		(0x0u<<30)
#define	BSEC_OTPVLDR5_VLDF190_B_0X1		(0x1u<<30)
#define	BSEC_OTPVLDR5_VLDF189_B_0X0		(0x0u<<29)
#define	BSEC_OTPVLDR5_VLDF189_B_0X1		(0x1u<<29)
#define	BSEC_OTPVLDR5_VLDF188_B_0X0		(0x0u<<28)
#define	BSEC_OTPVLDR5_VLDF188_B_0X1		(0x1u<<28)
#define	BSEC_OTPVLDR5_VLDF187_B_0X0		(0x0u<<27)
#define	BSEC_OTPVLDR5_VLDF187_B_0X1		(0x1u<<27)
#define	BSEC_OTPVLDR5_VLDF186_B_0X0		(0x0u<<26)
#define	BSEC_OTPVLDR5_VLDF186_B_0X1		(0x1u<<26)
#define	BSEC_OTPVLDR5_VLDF185_B_0X0		(0x0u<<25)
#define	BSEC_OTPVLDR5_VLDF185_B_0X1		(0x1u<<25)
#define	BSEC_OTPVLDR5_VLDF184_B_0X0		(0x0u<<24)
#define	BSEC_OTPVLDR5_VLDF184_B_0X1		(0x1u<<24)
#define	BSEC_OTPVLDR5_VLDF183_B_0X0		(0x0u<<23)
#define	BSEC_OTPVLDR5_VLDF183_B_0X1		(0x1u<<23)
#define	BSEC_OTPVLDR5_VLDF182_B_0X0		(0x0u<<22)
#define	BSEC_OTPVLDR5_VLDF182_B_0X1		(0x1u<<22)
#define	BSEC_OTPVLDR5_VLDF181_B_0X0		(0x0u<<21)
#define	BSEC_OTPVLDR5_VLDF181_B_0X1		(0x1u<<21)
#define	BSEC_OTPVLDR5_VLDF180_B_0X0		(0x0u<<20)
#define	BSEC_OTPVLDR5_VLDF180_B_0X1		(0x1u<<20)
#define	BSEC_OTPVLDR5_VLDF179_B_0X0		(0x0u<<19)
#define	BSEC_OTPVLDR5_VLDF179_B_0X1		(0x1u<<19)
#define	BSEC_OTPVLDR5_VLDF178_B_0X0		(0x0u<<18)
#define	BSEC_OTPVLDR5_VLDF178_B_0X1		(0x1u<<18)
#define	BSEC_OTPVLDR5_VLDF177_B_0X0		(0x0u<<17)
#define	BSEC_OTPVLDR5_VLDF177_B_0X1		(0x1u<<17)
#define	BSEC_OTPVLDR5_VLDF176_B_0X0		(0x0u<<16)
#define	BSEC_OTPVLDR5_VLDF176_B_0X1		(0x1u<<16)
#define	BSEC_OTPVLDR5_VLDF175_B_0X0		(0x0u<<15)
#define	BSEC_OTPVLDR5_VLDF175_B_0X1		(0x1u<<15)
#define	BSEC_OTPVLDR5_VLDF174_B_0X0		(0x0u<<14)
#define	BSEC_OTPVLDR5_VLDF174_B_0X1		(0x1u<<14)
#define	BSEC_OTPVLDR5_VLDF173_B_0X0		(0x0u<<13)
#define	BSEC_OTPVLDR5_VLDF173_B_0X1		(0x1u<<13)
#define	BSEC_OTPVLDR5_VLDF172_B_0X0		(0x0u<<12)
#define	BSEC_OTPVLDR5_VLDF172_B_0X1		(0x1u<<12)
#define	BSEC_OTPVLDR5_VLDF171_B_0X0		(0x0u<<11)
#define	BSEC_OTPVLDR5_VLDF171_B_0X1		(0x1u<<11)
#define	BSEC_OTPVLDR5_VLDF170_B_0X0		(0x0u<<10)
#define	BSEC_OTPVLDR5_VLDF170_B_0X1		(0x1u<<10)
#define	BSEC_OTPVLDR5_VLDF169_B_0X0		(0x0u<<9)
#define	BSEC_OTPVLDR5_VLDF169_B_0X1		(0x1u<<9)
#define	BSEC_OTPVLDR5_VLDF168_B_0X0		(0x0u<<8)
#define	BSEC_OTPVLDR5_VLDF168_B_0X1		(0x1u<<8)
#define	BSEC_OTPVLDR5_VLDF167_B_0X0		(0x0u<<7)
#define	BSEC_OTPVLDR5_VLDF167_B_0X1		(0x1u<<7)
#define	BSEC_OTPVLDR5_VLDF166_B_0X0		(0x0u<<6)
#define	BSEC_OTPVLDR5_VLDF166_B_0X1		(0x1u<<6)
#define	BSEC_OTPVLDR5_VLDF165_B_0X0		(0x0u<<5)
#define	BSEC_OTPVLDR5_VLDF165_B_0X1		(0x1u<<5)
#define	BSEC_OTPVLDR5_VLDF164_B_0X0		(0x0u<<4)
#define	BSEC_OTPVLDR5_VLDF164_B_0X1		(0x1u<<4)
#define	BSEC_OTPVLDR5_VLDF163_B_0X0		(0x0u<<3)
#define	BSEC_OTPVLDR5_VLDF163_B_0X1		(0x1u<<3)
#define	BSEC_OTPVLDR5_VLDF162_B_0X0		(0x0u<<2)
#define	BSEC_OTPVLDR5_VLDF162_B_0X1		(0x1u<<2)
#define	BSEC_OTPVLDR5_VLDF161_B_0X0		(0x0u<<1)
#define	BSEC_OTPVLDR5_VLDF161_B_0X1		(0x1u<<1)
#define	BSEC_OTPVLDR5_VLDF160_B_0X0		(0x0u<<0)
#define	BSEC_OTPVLDR5_VLDF160_B_0X1		(0x1u<<0)

// OTPVLDR6 Configuration

#define	BSEC_OTPVLDR6_VLDF223			(0x1u<<31)
#define	BSEC_OTPVLDR6_VLDF222			(0x1u<<30)
#define	BSEC_OTPVLDR6_VLDF221			(0x1u<<29)
#define	BSEC_OTPVLDR6_VLDF220			(0x1u<<28)
#define	BSEC_OTPVLDR6_VLDF219			(0x1u<<27)
#define	BSEC_OTPVLDR6_VLDF218			(0x1u<<26)
#define	BSEC_OTPVLDR6_VLDF217			(0x1u<<25)
#define	BSEC_OTPVLDR6_VLDF216			(0x1u<<24)
#define	BSEC_OTPVLDR6_VLDF215			(0x1u<<23)
#define	BSEC_OTPVLDR6_VLDF214			(0x1u<<22)
#define	BSEC_OTPVLDR6_VLDF213			(0x1u<<21)
#define	BSEC_OTPVLDR6_VLDF212			(0x1u<<20)
#define	BSEC_OTPVLDR6_VLDF211			(0x1u<<19)
#define	BSEC_OTPVLDR6_VLDF210			(0x1u<<18)
#define	BSEC_OTPVLDR6_VLDF209			(0x1u<<17)
#define	BSEC_OTPVLDR6_VLDF208			(0x1u<<16)
#define	BSEC_OTPVLDR6_VLDF207			(0x1u<<15)
#define	BSEC_OTPVLDR6_VLDF206			(0x1u<<14)
#define	BSEC_OTPVLDR6_VLDF205			(0x1u<<13)
#define	BSEC_OTPVLDR6_VLDF204			(0x1u<<12)
#define	BSEC_OTPVLDR6_VLDF203			(0x1u<<11)
#define	BSEC_OTPVLDR6_VLDF202			(0x1u<<10)
#define	BSEC_OTPVLDR6_VLDF201			(0x1u<<9)
#define	BSEC_OTPVLDR6_VLDF200			(0x1u<<8)
#define	BSEC_OTPVLDR6_VLDF199			(0x1u<<7)
#define	BSEC_OTPVLDR6_VLDF198			(0x1u<<6)
#define	BSEC_OTPVLDR6_VLDF197			(0x1u<<5)
#define	BSEC_OTPVLDR6_VLDF196			(0x1u<<4)
#define	BSEC_OTPVLDR6_VLDF195			(0x1u<<3)
#define	BSEC_OTPVLDR6_VLDF194			(0x1u<<2)
#define	BSEC_OTPVLDR6_VLDF193			(0x1u<<1)
#define	BSEC_OTPVLDR6_VLDF192			(0x1u<<0)

#define	BSEC_OTPVLDR6_VLDF223_B_0X0		(0x0u<<31)
#define	BSEC_OTPVLDR6_VLDF223_B_0X1		(0x1u<<31)
#define	BSEC_OTPVLDR6_VLDF222_B_0X0		(0x0u<<30)
#define	BSEC_OTPVLDR6_VLDF222_B_0X1		(0x1u<<30)
#define	BSEC_OTPVLDR6_VLDF221_B_0X0		(0x0u<<29)
#define	BSEC_OTPVLDR6_VLDF221_B_0X1		(0x1u<<29)
#define	BSEC_OTPVLDR6_VLDF220_B_0X0		(0x0u<<28)
#define	BSEC_OTPVLDR6_VLDF220_B_0X1		(0x1u<<28)
#define	BSEC_OTPVLDR6_VLDF219_B_0X0		(0x0u<<27)
#define	BSEC_OTPVLDR6_VLDF219_B_0X1		(0x1u<<27)
#define	BSEC_OTPVLDR6_VLDF218_B_0X0		(0x0u<<26)
#define	BSEC_OTPVLDR6_VLDF218_B_0X1		(0x1u<<26)
#define	BSEC_OTPVLDR6_VLDF217_B_0X0		(0x0u<<25)
#define	BSEC_OTPVLDR6_VLDF217_B_0X1		(0x1u<<25)
#define	BSEC_OTPVLDR6_VLDF216_B_0X0		(0x0u<<24)
#define	BSEC_OTPVLDR6_VLDF216_B_0X1		(0x1u<<24)
#define	BSEC_OTPVLDR6_VLDF215_B_0X0		(0x0u<<23)
#define	BSEC_OTPVLDR6_VLDF215_B_0X1		(0x1u<<23)
#define	BSEC_OTPVLDR6_VLDF214_B_0X0		(0x0u<<22)
#define	BSEC_OTPVLDR6_VLDF214_B_0X1		(0x1u<<22)
#define	BSEC_OTPVLDR6_VLDF213_B_0X0		(0x0u<<21)
#define	BSEC_OTPVLDR6_VLDF213_B_0X1		(0x1u<<21)
#define	BSEC_OTPVLDR6_VLDF212_B_0X0		(0x0u<<20)
#define	BSEC_OTPVLDR6_VLDF212_B_0X1		(0x1u<<20)
#define	BSEC_OTPVLDR6_VLDF211_B_0X0		(0x0u<<19)
#define	BSEC_OTPVLDR6_VLDF211_B_0X1		(0x1u<<19)
#define	BSEC_OTPVLDR6_VLDF210_B_0X0		(0x0u<<18)
#define	BSEC_OTPVLDR6_VLDF210_B_0X1		(0x1u<<18)
#define	BSEC_OTPVLDR6_VLDF209_B_0X0		(0x0u<<17)
#define	BSEC_OTPVLDR6_VLDF209_B_0X1		(0x1u<<17)
#define	BSEC_OTPVLDR6_VLDF208_B_0X0		(0x0u<<16)
#define	BSEC_OTPVLDR6_VLDF208_B_0X1		(0x1u<<16)
#define	BSEC_OTPVLDR6_VLDF207_B_0X0		(0x0u<<15)
#define	BSEC_OTPVLDR6_VLDF207_B_0X1		(0x1u<<15)
#define	BSEC_OTPVLDR6_VLDF206_B_0X0		(0x0u<<14)
#define	BSEC_OTPVLDR6_VLDF206_B_0X1		(0x1u<<14)
#define	BSEC_OTPVLDR6_VLDF205_B_0X0		(0x0u<<13)
#define	BSEC_OTPVLDR6_VLDF205_B_0X1		(0x1u<<13)
#define	BSEC_OTPVLDR6_VLDF204_B_0X0		(0x0u<<12)
#define	BSEC_OTPVLDR6_VLDF204_B_0X1		(0x1u<<12)
#define	BSEC_OTPVLDR6_VLDF203_B_0X0		(0x0u<<11)
#define	BSEC_OTPVLDR6_VLDF203_B_0X1		(0x1u<<11)
#define	BSEC_OTPVLDR6_VLDF202_B_0X0		(0x0u<<10)
#define	BSEC_OTPVLDR6_VLDF202_B_0X1		(0x1u<<10)
#define	BSEC_OTPVLDR6_VLDF201_B_0X0		(0x0u<<9)
#define	BSEC_OTPVLDR6_VLDF201_B_0X1		(0x1u<<9)
#define	BSEC_OTPVLDR6_VLDF200_B_0X0		(0x0u<<8)
#define	BSEC_OTPVLDR6_VLDF200_B_0X1		(0x1u<<8)
#define	BSEC_OTPVLDR6_VLDF199_B_0X0		(0x0u<<7)
#define	BSEC_OTPVLDR6_VLDF199_B_0X1		(0x1u<<7)
#define	BSEC_OTPVLDR6_VLDF198_B_0X0		(0x0u<<6)
#define	BSEC_OTPVLDR6_VLDF198_B_0X1		(0x1u<<6)
#define	BSEC_OTPVLDR6_VLDF197_B_0X0		(0x0u<<5)
#define	BSEC_OTPVLDR6_VLDF197_B_0X1		(0x1u<<5)
#define	BSEC_OTPVLDR6_VLDF196_B_0X0		(0x0u<<4)
#define	BSEC_OTPVLDR6_VLDF196_B_0X1		(0x1u<<4)
#define	BSEC_OTPVLDR6_VLDF195_B_0X0		(0x0u<<3)
#define	BSEC_OTPVLDR6_VLDF195_B_0X1		(0x1u<<3)
#define	BSEC_OTPVLDR6_VLDF194_B_0X0		(0x0u<<2)
#define	BSEC_OTPVLDR6_VLDF194_B_0X1		(0x1u<<2)
#define	BSEC_OTPVLDR6_VLDF193_B_0X0		(0x0u<<1)
#define	BSEC_OTPVLDR6_VLDF193_B_0X1		(0x1u<<1)
#define	BSEC_OTPVLDR6_VLDF192_B_0X0		(0x0u<<0)
#define	BSEC_OTPVLDR6_VLDF192_B_0X1		(0x1u<<0)

// OTPVLDR7 Configuration

#define	BSEC_OTPVLDR7_VLDF255			(0x1u<<31)
#define	BSEC_OTPVLDR7_VLDF254			(0x1u<<30)
#define	BSEC_OTPVLDR7_VLDF253			(0x1u<<29)
#define	BSEC_OTPVLDR7_VLDF252			(0x1u<<28)
#define	BSEC_OTPVLDR7_VLDF251			(0x1u<<27)
#define	BSEC_OTPVLDR7_VLDF250			(0x1u<<26)
#define	BSEC_OTPVLDR7_VLDF249			(0x1u<<25)
#define	BSEC_OTPVLDR7_VLDF248			(0x1u<<24)
#define	BSEC_OTPVLDR7_VLDF247			(0x1u<<23)
#define	BSEC_OTPVLDR7_VLDF246			(0x1u<<22)
#define	BSEC_OTPVLDR7_VLDF245			(0x1u<<21)
#define	BSEC_OTPVLDR7_VLDF244			(0x1u<<20)
#define	BSEC_OTPVLDR7_VLDF243			(0x1u<<19)
#define	BSEC_OTPVLDR7_VLDF242			(0x1u<<18)
#define	BSEC_OTPVLDR7_VLDF241			(0x1u<<17)
#define	BSEC_OTPVLDR7_VLDF240			(0x1u<<16)
#define	BSEC_OTPVLDR7_VLDF239			(0x1u<<15)
#define	BSEC_OTPVLDR7_VLDF238			(0x1u<<14)
#define	BSEC_OTPVLDR7_VLDF237			(0x1u<<13)
#define	BSEC_OTPVLDR7_VLDF236			(0x1u<<12)
#define	BSEC_OTPVLDR7_VLDF235			(0x1u<<11)
#define	BSEC_OTPVLDR7_VLDF234			(0x1u<<10)
#define	BSEC_OTPVLDR7_VLDF233			(0x1u<<9)
#define	BSEC_OTPVLDR7_VLDF232			(0x1u<<8)
#define	BSEC_OTPVLDR7_VLDF231			(0x1u<<7)
#define	BSEC_OTPVLDR7_VLDF230			(0x1u<<6)
#define	BSEC_OTPVLDR7_VLDF229			(0x1u<<5)
#define	BSEC_OTPVLDR7_VLDF228			(0x1u<<4)
#define	BSEC_OTPVLDR7_VLDF227			(0x1u<<3)
#define	BSEC_OTPVLDR7_VLDF226			(0x1u<<2)
#define	BSEC_OTPVLDR7_VLDF225			(0x1u<<1)
#define	BSEC_OTPVLDR7_VLDF224			(0x1u<<0)

#define	BSEC_OTPVLDR7_VLDF255_B_0X0		(0x0u<<31)
#define	BSEC_OTPVLDR7_VLDF255_B_0X1		(0x1u<<31)
#define	BSEC_OTPVLDR7_VLDF254_B_0X0		(0x0u<<30)
#define	BSEC_OTPVLDR7_VLDF254_B_0X1		(0x1u<<30)
#define	BSEC_OTPVLDR7_VLDF253_B_0X0		(0x0u<<29)
#define	BSEC_OTPVLDR7_VLDF253_B_0X1		(0x1u<<29)
#define	BSEC_OTPVLDR7_VLDF252_B_0X0		(0x0u<<28)
#define	BSEC_OTPVLDR7_VLDF252_B_0X1		(0x1u<<28)
#define	BSEC_OTPVLDR7_VLDF251_B_0X0		(0x0u<<27)
#define	BSEC_OTPVLDR7_VLDF251_B_0X1		(0x1u<<27)
#define	BSEC_OTPVLDR7_VLDF250_B_0X0		(0x0u<<26)
#define	BSEC_OTPVLDR7_VLDF250_B_0X1		(0x1u<<26)
#define	BSEC_OTPVLDR7_VLDF249_B_0X0		(0x0u<<25)
#define	BSEC_OTPVLDR7_VLDF249_B_0X1		(0x1u<<25)
#define	BSEC_OTPVLDR7_VLDF248_B_0X0		(0x0u<<24)
#define	BSEC_OTPVLDR7_VLDF248_B_0X1		(0x1u<<24)
#define	BSEC_OTPVLDR7_VLDF247_B_0X0		(0x0u<<23)
#define	BSEC_OTPVLDR7_VLDF247_B_0X1		(0x1u<<23)
#define	BSEC_OTPVLDR7_VLDF246_B_0X0		(0x0u<<22)
#define	BSEC_OTPVLDR7_VLDF246_B_0X1		(0x1u<<22)
#define	BSEC_OTPVLDR7_VLDF245_B_0X0		(0x0u<<21)
#define	BSEC_OTPVLDR7_VLDF245_B_0X1		(0x1u<<21)
#define	BSEC_OTPVLDR7_VLDF244_B_0X0		(0x0u<<20)
#define	BSEC_OTPVLDR7_VLDF244_B_0X1		(0x1u<<20)
#define	BSEC_OTPVLDR7_VLDF243_B_0X0		(0x0u<<19)
#define	BSEC_OTPVLDR7_VLDF243_B_0X1		(0x1u<<19)
#define	BSEC_OTPVLDR7_VLDF242_B_0X0		(0x0u<<18)
#define	BSEC_OTPVLDR7_VLDF242_B_0X1		(0x1u<<18)
#define	BSEC_OTPVLDR7_VLDF241_B_0X0		(0x0u<<17)
#define	BSEC_OTPVLDR7_VLDF241_B_0X1		(0x1u<<17)
#define	BSEC_OTPVLDR7_VLDF240_B_0X0		(0x0u<<16)
#define	BSEC_OTPVLDR7_VLDF240_B_0X1		(0x1u<<16)
#define	BSEC_OTPVLDR7_VLDF239_B_0X0		(0x0u<<15)
#define	BSEC_OTPVLDR7_VLDF239_B_0X1		(0x1u<<15)
#define	BSEC_OTPVLDR7_VLDF238_B_0X0		(0x0u<<14)
#define	BSEC_OTPVLDR7_VLDF238_B_0X1		(0x1u<<14)
#define	BSEC_OTPVLDR7_VLDF237_B_0X0		(0x0u<<13)
#define	BSEC_OTPVLDR7_VLDF237_B_0X1		(0x1u<<13)
#define	BSEC_OTPVLDR7_VLDF236_B_0X0		(0x0u<<12)
#define	BSEC_OTPVLDR7_VLDF236_B_0X1		(0x1u<<12)
#define	BSEC_OTPVLDR7_VLDF235_B_0X0		(0x0u<<11)
#define	BSEC_OTPVLDR7_VLDF235_B_0X1		(0x1u<<11)
#define	BSEC_OTPVLDR7_VLDF234_B_0X0		(0x0u<<10)
#define	BSEC_OTPVLDR7_VLDF234_B_0X1		(0x1u<<10)
#define	BSEC_OTPVLDR7_VLDF233_B_0X0		(0x0u<<9)
#define	BSEC_OTPVLDR7_VLDF233_B_0X1		(0x1u<<9)
#define	BSEC_OTPVLDR7_VLDF232_B_0X0		(0x0u<<8)
#define	BSEC_OTPVLDR7_VLDF232_B_0X1		(0x1u<<8)
#define	BSEC_OTPVLDR7_VLDF231_B_0X0		(0x0u<<7)
#define	BSEC_OTPVLDR7_VLDF231_B_0X1		(0x1u<<7)
#define	BSEC_OTPVLDR7_VLDF230_B_0X0		(0x0u<<6)
#define	BSEC_OTPVLDR7_VLDF230_B_0X1		(0x1u<<6)
#define	BSEC_OTPVLDR7_VLDF229_B_0X0		(0x0u<<5)
#define	BSEC_OTPVLDR7_VLDF229_B_0X1		(0x1u<<5)
#define	BSEC_OTPVLDR7_VLDF228_B_0X0		(0x0u<<4)
#define	BSEC_OTPVLDR7_VLDF228_B_0X1		(0x1u<<4)
#define	BSEC_OTPVLDR7_VLDF227_B_0X0		(0x0u<<3)
#define	BSEC_OTPVLDR7_VLDF227_B_0X1		(0x1u<<3)
#define	BSEC_OTPVLDR7_VLDF226_B_0X0		(0x0u<<2)
#define	BSEC_OTPVLDR7_VLDF226_B_0X1		(0x1u<<2)
#define	BSEC_OTPVLDR7_VLDF225_B_0X0		(0x0u<<1)
#define	BSEC_OTPVLDR7_VLDF225_B_0X1		(0x1u<<1)
#define	BSEC_OTPVLDR7_VLDF224_B_0X0		(0x0u<<0)
#define	BSEC_OTPVLDR7_VLDF224_B_0X1		(0x1u<<0)

// OTPVLDR8 Configuration

#define	BSEC_OTPVLDR8_VLDF287			(0x1u<<31)
#define	BSEC_OTPVLDR8_VLDF286			(0x1u<<30)
#define	BSEC_OTPVLDR8_VLDF285			(0x1u<<29)
#define	BSEC_OTPVLDR8_VLDF284			(0x1u<<28)
#define	BSEC_OTPVLDR8_VLDF283			(0x1u<<27)
#define	BSEC_OTPVLDR8_VLDF282			(0x1u<<26)
#define	BSEC_OTPVLDR8_VLDF281			(0x1u<<25)
#define	BSEC_OTPVLDR8_VLDF280			(0x1u<<24)
#define	BSEC_OTPVLDR8_VLDF279			(0x1u<<23)
#define	BSEC_OTPVLDR8_VLDF278			(0x1u<<22)
#define	BSEC_OTPVLDR8_VLDF277			(0x1u<<21)
#define	BSEC_OTPVLDR8_VLDF276			(0x1u<<20)
#define	BSEC_OTPVLDR8_VLDF275			(0x1u<<19)
#define	BSEC_OTPVLDR8_VLDF274			(0x1u<<18)
#define	BSEC_OTPVLDR8_VLDF273			(0x1u<<17)
#define	BSEC_OTPVLDR8_VLDF272			(0x1u<<16)
#define	BSEC_OTPVLDR8_VLDF271			(0x1u<<15)
#define	BSEC_OTPVLDR8_VLDF270			(0x1u<<14)
#define	BSEC_OTPVLDR8_VLDF269			(0x1u<<13)
#define	BSEC_OTPVLDR8_VLDF268			(0x1u<<12)
#define	BSEC_OTPVLDR8_VLDF267			(0x1u<<11)
#define	BSEC_OTPVLDR8_VLDF266			(0x1u<<10)
#define	BSEC_OTPVLDR8_VLDF265			(0x1u<<9)
#define	BSEC_OTPVLDR8_VLDF264			(0x1u<<8)
#define	BSEC_OTPVLDR8_VLDF263			(0x1u<<7)
#define	BSEC_OTPVLDR8_VLDF262			(0x1u<<6)
#define	BSEC_OTPVLDR8_VLDF261			(0x1u<<5)
#define	BSEC_OTPVLDR8_VLDF260			(0x1u<<4)
#define	BSEC_OTPVLDR8_VLDF259			(0x1u<<3)
#define	BSEC_OTPVLDR8_VLDF258			(0x1u<<2)
#define	BSEC_OTPVLDR8_VLDF257			(0x1u<<1)
#define	BSEC_OTPVLDR8_VLDF256			(0x1u<<0)

#define	BSEC_OTPVLDR8_VLDF287_B_0X0		(0x0u<<31)
#define	BSEC_OTPVLDR8_VLDF287_B_0X1		(0x1u<<31)
#define	BSEC_OTPVLDR8_VLDF286_B_0X0		(0x0u<<30)
#define	BSEC_OTPVLDR8_VLDF286_B_0X1		(0x1u<<30)
#define	BSEC_OTPVLDR8_VLDF285_B_0X0		(0x0u<<29)
#define	BSEC_OTPVLDR8_VLDF285_B_0X1		(0x1u<<29)
#define	BSEC_OTPVLDR8_VLDF284_B_0X0		(0x0u<<28)
#define	BSEC_OTPVLDR8_VLDF284_B_0X1		(0x1u<<28)
#define	BSEC_OTPVLDR8_VLDF283_B_0X0		(0x0u<<27)
#define	BSEC_OTPVLDR8_VLDF283_B_0X1		(0x1u<<27)
#define	BSEC_OTPVLDR8_VLDF282_B_0X0		(0x0u<<26)
#define	BSEC_OTPVLDR8_VLDF282_B_0X1		(0x1u<<26)
#define	BSEC_OTPVLDR8_VLDF281_B_0X0		(0x0u<<25)
#define	BSEC_OTPVLDR8_VLDF281_B_0X1		(0x1u<<25)
#define	BSEC_OTPVLDR8_VLDF280_B_0X0		(0x0u<<24)
#define	BSEC_OTPVLDR8_VLDF280_B_0X1		(0x1u<<24)
#define	BSEC_OTPVLDR8_VLDF279_B_0X0		(0x0u<<23)
#define	BSEC_OTPVLDR8_VLDF279_B_0X1		(0x1u<<23)
#define	BSEC_OTPVLDR8_VLDF278_B_0X0		(0x0u<<22)
#define	BSEC_OTPVLDR8_VLDF278_B_0X1		(0x1u<<22)
#define	BSEC_OTPVLDR8_VLDF277_B_0X0		(0x0u<<21)
#define	BSEC_OTPVLDR8_VLDF277_B_0X1		(0x1u<<21)
#define	BSEC_OTPVLDR8_VLDF276_B_0X0		(0x0u<<20)
#define	BSEC_OTPVLDR8_VLDF276_B_0X1		(0x1u<<20)
#define	BSEC_OTPVLDR8_VLDF275_B_0X0		(0x0u<<19)
#define	BSEC_OTPVLDR8_VLDF275_B_0X1		(0x1u<<19)
#define	BSEC_OTPVLDR8_VLDF274_B_0X0		(0x0u<<18)
#define	BSEC_OTPVLDR8_VLDF274_B_0X1		(0x1u<<18)
#define	BSEC_OTPVLDR8_VLDF273_B_0X0		(0x0u<<17)
#define	BSEC_OTPVLDR8_VLDF273_B_0X1		(0x1u<<17)
#define	BSEC_OTPVLDR8_VLDF272_B_0X0		(0x0u<<16)
#define	BSEC_OTPVLDR8_VLDF272_B_0X1		(0x1u<<16)
#define	BSEC_OTPVLDR8_VLDF271_B_0X0		(0x0u<<15)
#define	BSEC_OTPVLDR8_VLDF271_B_0X1		(0x1u<<15)
#define	BSEC_OTPVLDR8_VLDF270_B_0X0		(0x0u<<14)
#define	BSEC_OTPVLDR8_VLDF270_B_0X1		(0x1u<<14)
#define	BSEC_OTPVLDR8_VLDF269_B_0X0		(0x0u<<13)
#define	BSEC_OTPVLDR8_VLDF269_B_0X1		(0x1u<<13)
#define	BSEC_OTPVLDR8_VLDF268_B_0X0		(0x0u<<12)
#define	BSEC_OTPVLDR8_VLDF268_B_0X1		(0x1u<<12)
#define	BSEC_OTPVLDR8_VLDF267_B_0X0		(0x0u<<11)
#define	BSEC_OTPVLDR8_VLDF267_B_0X1		(0x1u<<11)
#define	BSEC_OTPVLDR8_VLDF266_B_0X0		(0x0u<<10)
#define	BSEC_OTPVLDR8_VLDF266_B_0X1		(0x1u<<10)
#define	BSEC_OTPVLDR8_VLDF265_B_0X0		(0x0u<<9)
#define	BSEC_OTPVLDR8_VLDF265_B_0X1		(0x1u<<9)
#define	BSEC_OTPVLDR8_VLDF264_B_0X0		(0x0u<<8)
#define	BSEC_OTPVLDR8_VLDF264_B_0X1		(0x1u<<8)
#define	BSEC_OTPVLDR8_VLDF263_B_0X0		(0x0u<<7)
#define	BSEC_OTPVLDR8_VLDF263_B_0X1		(0x1u<<7)
#define	BSEC_OTPVLDR8_VLDF262_B_0X0		(0x0u<<6)
#define	BSEC_OTPVLDR8_VLDF262_B_0X1		(0x1u<<6)
#define	BSEC_OTPVLDR8_VLDF261_B_0X0		(0x0u<<5)
#define	BSEC_OTPVLDR8_VLDF261_B_0X1		(0x1u<<5)
#define	BSEC_OTPVLDR8_VLDF260_B_0X0		(0x0u<<4)
#define	BSEC_OTPVLDR8_VLDF260_B_0X1		(0x1u<<4)
#define	BSEC_OTPVLDR8_VLDF259_B_0X0		(0x0u<<3)
#define	BSEC_OTPVLDR8_VLDF259_B_0X1		(0x1u<<3)
#define	BSEC_OTPVLDR8_VLDF258_B_0X0		(0x0u<<2)
#define	BSEC_OTPVLDR8_VLDF258_B_0X1		(0x1u<<2)
#define	BSEC_OTPVLDR8_VLDF257_B_0X0		(0x0u<<1)
#define	BSEC_OTPVLDR8_VLDF257_B_0X1		(0x1u<<1)
#define	BSEC_OTPVLDR8_VLDF256_B_0X0		(0x0u<<0)
#define	BSEC_OTPVLDR8_VLDF256_B_0X1		(0x1u<<0)

// OTPVLDR9 Configuration

#define	BSEC_OTPVLDR9_VLDF319			(0x1u<<31)
#define	BSEC_OTPVLDR9_VLDF318			(0x1u<<30)
#define	BSEC_OTPVLDR9_VLDF317			(0x1u<<29)
#define	BSEC_OTPVLDR9_VLDF316			(0x1u<<28)
#define	BSEC_OTPVLDR9_VLDF315			(0x1u<<27)
#define	BSEC_OTPVLDR9_VLDF314			(0x1u<<26)
#define	BSEC_OTPVLDR9_VLDF313			(0x1u<<25)
#define	BSEC_OTPVLDR9_VLDF312			(0x1u<<24)
#define	BSEC_OTPVLDR9_VLDF311			(0x1u<<23)
#define	BSEC_OTPVLDR9_VLDF310			(0x1u<<22)
#define	BSEC_OTPVLDR9_VLDF309			(0x1u<<21)
#define	BSEC_OTPVLDR9_VLDF308			(0x1u<<20)
#define	BSEC_OTPVLDR9_VLDF307			(0x1u<<19)
#define	BSEC_OTPVLDR9_VLDF306			(0x1u<<18)
#define	BSEC_OTPVLDR9_VLDF305			(0x1u<<17)
#define	BSEC_OTPVLDR9_VLDF304			(0x1u<<16)
#define	BSEC_OTPVLDR9_VLDF303			(0x1u<<15)
#define	BSEC_OTPVLDR9_VLDF302			(0x1u<<14)
#define	BSEC_OTPVLDR9_VLDF301			(0x1u<<13)
#define	BSEC_OTPVLDR9_VLDF300			(0x1u<<12)
#define	BSEC_OTPVLDR9_VLDF299			(0x1u<<11)
#define	BSEC_OTPVLDR9_VLDF298			(0x1u<<10)
#define	BSEC_OTPVLDR9_VLDF297			(0x1u<<9)
#define	BSEC_OTPVLDR9_VLDF296			(0x1u<<8)
#define	BSEC_OTPVLDR9_VLDF295			(0x1u<<7)
#define	BSEC_OTPVLDR9_VLDF294			(0x1u<<6)
#define	BSEC_OTPVLDR9_VLDF293			(0x1u<<5)
#define	BSEC_OTPVLDR9_VLDF292			(0x1u<<4)
#define	BSEC_OTPVLDR9_VLDF291			(0x1u<<3)
#define	BSEC_OTPVLDR9_VLDF290			(0x1u<<2)
#define	BSEC_OTPVLDR9_VLDF289			(0x1u<<1)
#define	BSEC_OTPVLDR9_VLDF288			(0x1u<<0)

#define	BSEC_OTPVLDR9_VLDF319_B_0X0		(0x0u<<31)
#define	BSEC_OTPVLDR9_VLDF319_B_0X1		(0x1u<<31)
#define	BSEC_OTPVLDR9_VLDF318_B_0X0		(0x0u<<30)
#define	BSEC_OTPVLDR9_VLDF318_B_0X1		(0x1u<<30)
#define	BSEC_OTPVLDR9_VLDF317_B_0X0		(0x0u<<29)
#define	BSEC_OTPVLDR9_VLDF317_B_0X1		(0x1u<<29)
#define	BSEC_OTPVLDR9_VLDF316_B_0X0		(0x0u<<28)
#define	BSEC_OTPVLDR9_VLDF316_B_0X1		(0x1u<<28)
#define	BSEC_OTPVLDR9_VLDF315_B_0X0		(0x0u<<27)
#define	BSEC_OTPVLDR9_VLDF315_B_0X1		(0x1u<<27)
#define	BSEC_OTPVLDR9_VLDF314_B_0X0		(0x0u<<26)
#define	BSEC_OTPVLDR9_VLDF314_B_0X1		(0x1u<<26)
#define	BSEC_OTPVLDR9_VLDF313_B_0X0		(0x0u<<25)
#define	BSEC_OTPVLDR9_VLDF313_B_0X1		(0x1u<<25)
#define	BSEC_OTPVLDR9_VLDF312_B_0X0		(0x0u<<24)
#define	BSEC_OTPVLDR9_VLDF312_B_0X1		(0x1u<<24)
#define	BSEC_OTPVLDR9_VLDF311_B_0X0		(0x0u<<23)
#define	BSEC_OTPVLDR9_VLDF311_B_0X1		(0x1u<<23)
#define	BSEC_OTPVLDR9_VLDF310_B_0X0		(0x0u<<22)
#define	BSEC_OTPVLDR9_VLDF310_B_0X1		(0x1u<<22)
#define	BSEC_OTPVLDR9_VLDF309_B_0X0		(0x0u<<21)
#define	BSEC_OTPVLDR9_VLDF309_B_0X1		(0x1u<<21)
#define	BSEC_OTPVLDR9_VLDF308_B_0X0		(0x0u<<20)
#define	BSEC_OTPVLDR9_VLDF308_B_0X1		(0x1u<<20)
#define	BSEC_OTPVLDR9_VLDF307_B_0X0		(0x0u<<19)
#define	BSEC_OTPVLDR9_VLDF307_B_0X1		(0x1u<<19)
#define	BSEC_OTPVLDR9_VLDF306_B_0X0		(0x0u<<18)
#define	BSEC_OTPVLDR9_VLDF306_B_0X1		(0x1u<<18)
#define	BSEC_OTPVLDR9_VLDF305_B_0X0		(0x0u<<17)
#define	BSEC_OTPVLDR9_VLDF305_B_0X1		(0x1u<<17)
#define	BSEC_OTPVLDR9_VLDF304_B_0X0		(0x0u<<16)
#define	BSEC_OTPVLDR9_VLDF304_B_0X1		(0x1u<<16)
#define	BSEC_OTPVLDR9_VLDF303_B_0X0		(0x0u<<15)
#define	BSEC_OTPVLDR9_VLDF303_B_0X1		(0x1u<<15)
#define	BSEC_OTPVLDR9_VLDF302_B_0X0		(0x0u<<14)
#define	BSEC_OTPVLDR9_VLDF302_B_0X1		(0x1u<<14)
#define	BSEC_OTPVLDR9_VLDF301_B_0X0		(0x0u<<13)
#define	BSEC_OTPVLDR9_VLDF301_B_0X1		(0x1u<<13)
#define	BSEC_OTPVLDR9_VLDF300_B_0X0		(0x0u<<12)
#define	BSEC_OTPVLDR9_VLDF300_B_0X1		(0x1u<<12)
#define	BSEC_OTPVLDR9_VLDF299_B_0X0		(0x0u<<11)
#define	BSEC_OTPVLDR9_VLDF299_B_0X1		(0x1u<<11)
#define	BSEC_OTPVLDR9_VLDF298_B_0X0		(0x0u<<10)
#define	BSEC_OTPVLDR9_VLDF298_B_0X1		(0x1u<<10)
#define	BSEC_OTPVLDR9_VLDF297_B_0X0		(0x0u<<9)
#define	BSEC_OTPVLDR9_VLDF297_B_0X1		(0x1u<<9)
#define	BSEC_OTPVLDR9_VLDF296_B_0X0		(0x0u<<8)
#define	BSEC_OTPVLDR9_VLDF296_B_0X1		(0x1u<<8)
#define	BSEC_OTPVLDR9_VLDF295_B_0X0		(0x0u<<7)
#define	BSEC_OTPVLDR9_VLDF295_B_0X1		(0x1u<<7)
#define	BSEC_OTPVLDR9_VLDF294_B_0X0		(0x0u<<6)
#define	BSEC_OTPVLDR9_VLDF294_B_0X1		(0x1u<<6)
#define	BSEC_OTPVLDR9_VLDF293_B_0X0		(0x0u<<5)
#define	BSEC_OTPVLDR9_VLDF293_B_0X1		(0x1u<<5)
#define	BSEC_OTPVLDR9_VLDF292_B_0X0		(0x0u<<4)
#define	BSEC_OTPVLDR9_VLDF292_B_0X1		(0x1u<<4)
#define	BSEC_OTPVLDR9_VLDF291_B_0X0		(0x0u<<3)
#define	BSEC_OTPVLDR9_VLDF291_B_0X1		(0x1u<<3)
#define	BSEC_OTPVLDR9_VLDF290_B_0X0		(0x0u<<2)
#define	BSEC_OTPVLDR9_VLDF290_B_0X1		(0x1u<<2)
#define	BSEC_OTPVLDR9_VLDF289_B_0X0		(0x0u<<1)
#define	BSEC_OTPVLDR9_VLDF289_B_0X1		(0x1u<<1)
#define	BSEC_OTPVLDR9_VLDF288_B_0X0		(0x0u<<0)
#define	BSEC_OTPVLDR9_VLDF288_B_0X1		(0x1u<<0)

// OTPVLDR10 Configuration

#define	BSEC_OTPVLDR10_VLDF351			(0x1u<<31)
#define	BSEC_OTPVLDR10_VLDF350			(0x1u<<30)
#define	BSEC_OTPVLDR10_VLDF349			(0x1u<<29)
#define	BSEC_OTPVLDR10_VLDF348			(0x1u<<28)
#define	BSEC_OTPVLDR10_VLDF347			(0x1u<<27)
#define	BSEC_OTPVLDR10_VLDF346			(0x1u<<26)
#define	BSEC_OTPVLDR10_VLDF345			(0x1u<<25)
#define	BSEC_OTPVLDR10_VLDF344			(0x1u<<24)
#define	BSEC_OTPVLDR10_VLDF343			(0x1u<<23)
#define	BSEC_OTPVLDR10_VLDF342			(0x1u<<22)
#define	BSEC_OTPVLDR10_VLDF341			(0x1u<<21)
#define	BSEC_OTPVLDR10_VLDF340			(0x1u<<20)
#define	BSEC_OTPVLDR10_VLDF339			(0x1u<<19)
#define	BSEC_OTPVLDR10_VLDF338			(0x1u<<18)
#define	BSEC_OTPVLDR10_VLDF337			(0x1u<<17)
#define	BSEC_OTPVLDR10_VLDF336			(0x1u<<16)
#define	BSEC_OTPVLDR10_VLDF335			(0x1u<<15)
#define	BSEC_OTPVLDR10_VLDF334			(0x1u<<14)
#define	BSEC_OTPVLDR10_VLDF333			(0x1u<<13)
#define	BSEC_OTPVLDR10_VLDF332			(0x1u<<12)
#define	BSEC_OTPVLDR10_VLDF331			(0x1u<<11)
#define	BSEC_OTPVLDR10_VLDF330			(0x1u<<10)
#define	BSEC_OTPVLDR10_VLDF329			(0x1u<<9)
#define	BSEC_OTPVLDR10_VLDF328			(0x1u<<8)
#define	BSEC_OTPVLDR10_VLDF327			(0x1u<<7)
#define	BSEC_OTPVLDR10_VLDF326			(0x1u<<6)
#define	BSEC_OTPVLDR10_VLDF325			(0x1u<<5)
#define	BSEC_OTPVLDR10_VLDF324			(0x1u<<4)
#define	BSEC_OTPVLDR10_VLDF323			(0x1u<<3)
#define	BSEC_OTPVLDR10_VLDF322			(0x1u<<2)
#define	BSEC_OTPVLDR10_VLDF321			(0x1u<<1)
#define	BSEC_OTPVLDR10_VLDF320			(0x1u<<0)

#define	BSEC_OTPVLDR10_VLDF351_B_0X0	(0x0u<<31)
#define	BSEC_OTPVLDR10_VLDF351_B_0X1	(0x1u<<31)
#define	BSEC_OTPVLDR10_VLDF350_B_0X0	(0x0u<<30)
#define	BSEC_OTPVLDR10_VLDF350_B_0X1	(0x1u<<30)
#define	BSEC_OTPVLDR10_VLDF349_B_0X0	(0x0u<<29)
#define	BSEC_OTPVLDR10_VLDF349_B_0X1	(0x1u<<29)
#define	BSEC_OTPVLDR10_VLDF348_B_0X0	(0x0u<<28)
#define	BSEC_OTPVLDR10_VLDF348_B_0X1	(0x1u<<28)
#define	BSEC_OTPVLDR10_VLDF347_B_0X0	(0x0u<<27)
#define	BSEC_OTPVLDR10_VLDF347_B_0X1	(0x1u<<27)
#define	BSEC_OTPVLDR10_VLDF346_B_0X0	(0x0u<<26)
#define	BSEC_OTPVLDR10_VLDF346_B_0X1	(0x1u<<26)
#define	BSEC_OTPVLDR10_VLDF345_B_0X0	(0x0u<<25)
#define	BSEC_OTPVLDR10_VLDF345_B_0X1	(0x1u<<25)
#define	BSEC_OTPVLDR10_VLDF344_B_0X0	(0x0u<<24)
#define	BSEC_OTPVLDR10_VLDF344_B_0X1	(0x1u<<24)
#define	BSEC_OTPVLDR10_VLDF343_B_0X0	(0x0u<<23)
#define	BSEC_OTPVLDR10_VLDF343_B_0X1	(0x1u<<23)
#define	BSEC_OTPVLDR10_VLDF342_B_0X0	(0x0u<<22)
#define	BSEC_OTPVLDR10_VLDF342_B_0X1	(0x1u<<22)
#define	BSEC_OTPVLDR10_VLDF341_B_0X0	(0x0u<<21)
#define	BSEC_OTPVLDR10_VLDF341_B_0X1	(0x1u<<21)
#define	BSEC_OTPVLDR10_VLDF340_B_0X0	(0x0u<<20)
#define	BSEC_OTPVLDR10_VLDF340_B_0X1	(0x1u<<20)
#define	BSEC_OTPVLDR10_VLDF339_B_0X0	(0x0u<<19)
#define	BSEC_OTPVLDR10_VLDF339_B_0X1	(0x1u<<19)
#define	BSEC_OTPVLDR10_VLDF338_B_0X0	(0x0u<<18)
#define	BSEC_OTPVLDR10_VLDF338_B_0X1	(0x1u<<18)
#define	BSEC_OTPVLDR10_VLDF337_B_0X0	(0x0u<<17)
#define	BSEC_OTPVLDR10_VLDF337_B_0X1	(0x1u<<17)
#define	BSEC_OTPVLDR10_VLDF336_B_0X0	(0x0u<<16)
#define	BSEC_OTPVLDR10_VLDF336_B_0X1	(0x1u<<16)
#define	BSEC_OTPVLDR10_VLDF335_B_0X0	(0x0u<<15)
#define	BSEC_OTPVLDR10_VLDF335_B_0X1	(0x1u<<15)
#define	BSEC_OTPVLDR10_VLDF334_B_0X0	(0x0u<<14)
#define	BSEC_OTPVLDR10_VLDF334_B_0X1	(0x1u<<14)
#define	BSEC_OTPVLDR10_VLDF333_B_0X0	(0x0u<<13)
#define	BSEC_OTPVLDR10_VLDF333_B_0X1	(0x1u<<13)
#define	BSEC_OTPVLDR10_VLDF332_B_0X0	(0x0u<<12)
#define	BSEC_OTPVLDR10_VLDF332_B_0X1	(0x1u<<12)
#define	BSEC_OTPVLDR10_VLDF331_B_0X0	(0x0u<<11)
#define	BSEC_OTPVLDR10_VLDF331_B_0X1	(0x1u<<11)
#define	BSEC_OTPVLDR10_VLDF330_B_0X0	(0x0u<<10)
#define	BSEC_OTPVLDR10_VLDF330_B_0X1	(0x1u<<10)
#define	BSEC_OTPVLDR10_VLDF329_B_0X0	(0x0u<<9)
#define	BSEC_OTPVLDR10_VLDF329_B_0X1	(0x1u<<9)
#define	BSEC_OTPVLDR10_VLDF328_B_0X0	(0x0u<<8)
#define	BSEC_OTPVLDR10_VLDF328_B_0X1	(0x1u<<8)
#define	BSEC_OTPVLDR10_VLDF327_B_0X0	(0x0u<<7)
#define	BSEC_OTPVLDR10_VLDF327_B_0X1	(0x1u<<7)
#define	BSEC_OTPVLDR10_VLDF326_B_0X0	(0x0u<<6)
#define	BSEC_OTPVLDR10_VLDF326_B_0X1	(0x1u<<6)
#define	BSEC_OTPVLDR10_VLDF325_B_0X0	(0x0u<<5)
#define	BSEC_OTPVLDR10_VLDF325_B_0X1	(0x1u<<5)
#define	BSEC_OTPVLDR10_VLDF324_B_0X0	(0x0u<<4)
#define	BSEC_OTPVLDR10_VLDF324_B_0X1	(0x1u<<4)
#define	BSEC_OTPVLDR10_VLDF323_B_0X0	(0x0u<<3)
#define	BSEC_OTPVLDR10_VLDF323_B_0X1	(0x1u<<3)
#define	BSEC_OTPVLDR10_VLDF322_B_0X0	(0x0u<<2)
#define	BSEC_OTPVLDR10_VLDF322_B_0X1	(0x1u<<2)
#define	BSEC_OTPVLDR10_VLDF321_B_0X0	(0x0u<<1)
#define	BSEC_OTPVLDR10_VLDF321_B_0X1	(0x1u<<1)
#define	BSEC_OTPVLDR10_VLDF320_B_0X0	(0x0u<<0)
#define	BSEC_OTPVLDR10_VLDF320_B_0X1	(0x1u<<0)

// OTPVLDR11 Configuration

#define	BSEC_OTPVLDR11_VLDF383			(0x1u<<31)
#define	BSEC_OTPVLDR11_VLDF382			(0x1u<<30)
#define	BSEC_OTPVLDR11_VLDF381			(0x1u<<29)
#define	BSEC_OTPVLDR11_VLDF380			(0x1u<<28)
#define	BSEC_OTPVLDR11_VLDF379			(0x1u<<27)
#define	BSEC_OTPVLDR11_VLDF378			(0x1u<<26)
#define	BSEC_OTPVLDR11_VLDF377			(0x1u<<25)
#define	BSEC_OTPVLDR11_VLDF376			(0x1u<<24)
#define	BSEC_OTPVLDR11_VLDF375			(0x1u<<23)
#define	BSEC_OTPVLDR11_VLDF374			(0x1u<<22)
#define	BSEC_OTPVLDR11_VLDF373			(0x1u<<21)
#define	BSEC_OTPVLDR11_VLDF372			(0x1u<<20)
#define	BSEC_OTPVLDR11_VLDF371			(0x1u<<19)
#define	BSEC_OTPVLDR11_VLDF370			(0x1u<<18)
#define	BSEC_OTPVLDR11_VLDF369			(0x1u<<17)
#define	BSEC_OTPVLDR11_VLDF368			(0x1u<<16)
#define	BSEC_OTPVLDR11_VLDF367			(0x1u<<15)
#define	BSEC_OTPVLDR11_VLDF366			(0x1u<<14)
#define	BSEC_OTPVLDR11_VLDF365			(0x1u<<13)
#define	BSEC_OTPVLDR11_VLDF364			(0x1u<<12)
#define	BSEC_OTPVLDR11_VLDF363			(0x1u<<11)
#define	BSEC_OTPVLDR11_VLDF362			(0x1u<<10)
#define	BSEC_OTPVLDR11_VLDF361			(0x1u<<9)
#define	BSEC_OTPVLDR11_VLDF360			(0x1u<<8)
#define	BSEC_OTPVLDR11_VLDF359			(0x1u<<7)
#define	BSEC_OTPVLDR11_VLDF358			(0x1u<<6)
#define	BSEC_OTPVLDR11_VLDF357			(0x1u<<5)
#define	BSEC_OTPVLDR11_VLDF356			(0x1u<<4)
#define	BSEC_OTPVLDR11_VLDF355			(0x1u<<3)
#define	BSEC_OTPVLDR11_VLDF354			(0x1u<<2)
#define	BSEC_OTPVLDR11_VLDF353			(0x1u<<1)
#define	BSEC_OTPVLDR11_VLDF352			(0x1u<<0)

#define	BSEC_OTPVLDR11_VLDF383_B_0X0	(0x0u<<31)
#define	BSEC_OTPVLDR11_VLDF383_B_0X1	(0x1u<<31)
#define	BSEC_OTPVLDR11_VLDF382_B_0X0	(0x0u<<30)
#define	BSEC_OTPVLDR11_VLDF382_B_0X1	(0x1u<<30)
#define	BSEC_OTPVLDR11_VLDF381_B_0X0	(0x0u<<29)
#define	BSEC_OTPVLDR11_VLDF381_B_0X1	(0x1u<<29)
#define	BSEC_OTPVLDR11_VLDF380_B_0X0	(0x0u<<28)
#define	BSEC_OTPVLDR11_VLDF380_B_0X1	(0x1u<<28)
#define	BSEC_OTPVLDR11_VLDF379_B_0X0	(0x0u<<27)
#define	BSEC_OTPVLDR11_VLDF379_B_0X1	(0x1u<<27)
#define	BSEC_OTPVLDR11_VLDF378_B_0X0	(0x0u<<26)
#define	BSEC_OTPVLDR11_VLDF378_B_0X1	(0x1u<<26)
#define	BSEC_OTPVLDR11_VLDF377_B_0X0	(0x0u<<25)
#define	BSEC_OTPVLDR11_VLDF377_B_0X1	(0x1u<<25)
#define	BSEC_OTPVLDR11_VLDF376_B_0X0	(0x0u<<24)
#define	BSEC_OTPVLDR11_VLDF376_B_0X1	(0x1u<<24)
#define	BSEC_OTPVLDR11_VLDF375_B_0X0	(0x0u<<23)
#define	BSEC_OTPVLDR11_VLDF375_B_0X1	(0x1u<<23)
#define	BSEC_OTPVLDR11_VLDF374_B_0X0	(0x0u<<22)
#define	BSEC_OTPVLDR11_VLDF374_B_0X1	(0x1u<<22)
#define	BSEC_OTPVLDR11_VLDF373_B_0X0	(0x0u<<21)
#define	BSEC_OTPVLDR11_VLDF373_B_0X1	(0x1u<<21)
#define	BSEC_OTPVLDR11_VLDF372_B_0X0	(0x0u<<20)
#define	BSEC_OTPVLDR11_VLDF372_B_0X1	(0x1u<<20)
#define	BSEC_OTPVLDR11_VLDF371_B_0X0	(0x0u<<19)
#define	BSEC_OTPVLDR11_VLDF371_B_0X1	(0x1u<<19)
#define	BSEC_OTPVLDR11_VLDF370_B_0X0	(0x0u<<18)
#define	BSEC_OTPVLDR11_VLDF370_B_0X1	(0x1u<<18)
#define	BSEC_OTPVLDR11_VLDF369_B_0X0	(0x0u<<17)
#define	BSEC_OTPVLDR11_VLDF369_B_0X1	(0x1u<<17)
#define	BSEC_OTPVLDR11_VLDF368_B_0X0	(0x0u<<16)
#define	BSEC_OTPVLDR11_VLDF368_B_0X1	(0x1u<<16)
#define	BSEC_OTPVLDR11_VLDF367_B_0X0	(0x0u<<15)
#define	BSEC_OTPVLDR11_VLDF367_B_0X1	(0x1u<<15)
#define	BSEC_OTPVLDR11_VLDF366_B_0X0	(0x0u<<14)
#define	BSEC_OTPVLDR11_VLDF366_B_0X1	(0x1u<<14)
#define	BSEC_OTPVLDR11_VLDF365_B_0X0	(0x0u<<13)
#define	BSEC_OTPVLDR11_VLDF365_B_0X1	(0x1u<<13)
#define	BSEC_OTPVLDR11_VLDF364_B_0X0	(0x0u<<12)
#define	BSEC_OTPVLDR11_VLDF364_B_0X1	(0x1u<<12)
#define	BSEC_OTPVLDR11_VLDF363_B_0X0	(0x0u<<11)
#define	BSEC_OTPVLDR11_VLDF363_B_0X1	(0x1u<<11)
#define	BSEC_OTPVLDR11_VLDF362_B_0X0	(0x0u<<10)
#define	BSEC_OTPVLDR11_VLDF362_B_0X1	(0x1u<<10)
#define	BSEC_OTPVLDR11_VLDF361_B_0X0	(0x0u<<9)
#define	BSEC_OTPVLDR11_VLDF361_B_0X1	(0x1u<<9)
#define	BSEC_OTPVLDR11_VLDF360_B_0X0	(0x0u<<8)
#define	BSEC_OTPVLDR11_VLDF360_B_0X1	(0x1u<<8)
#define	BSEC_OTPVLDR11_VLDF359_B_0X0	(0x0u<<7)
#define	BSEC_OTPVLDR11_VLDF359_B_0X1	(0x1u<<7)
#define	BSEC_OTPVLDR11_VLDF358_B_0X0	(0x0u<<6)
#define	BSEC_OTPVLDR11_VLDF358_B_0X1	(0x1u<<6)
#define	BSEC_OTPVLDR11_VLDF357_B_0X0	(0x0u<<5)
#define	BSEC_OTPVLDR11_VLDF357_B_0X1	(0x1u<<5)
#define	BSEC_OTPVLDR11_VLDF356_B_0X0	(0x0u<<4)
#define	BSEC_OTPVLDR11_VLDF356_B_0X1	(0x1u<<4)
#define	BSEC_OTPVLDR11_VLDF355_B_0X0	(0x0u<<3)
#define	BSEC_OTPVLDR11_VLDF355_B_0X1	(0x1u<<3)
#define	BSEC_OTPVLDR11_VLDF354_B_0X0	(0x0u<<2)
#define	BSEC_OTPVLDR11_VLDF354_B_0X1	(0x1u<<2)
#define	BSEC_OTPVLDR11_VLDF353_B_0X0	(0x0u<<1)
#define	BSEC_OTPVLDR11_VLDF353_B_0X1	(0x1u<<1)
#define	BSEC_OTPVLDR11_VLDF352_B_0X0	(0x0u<<0)
#define	BSEC_OTPVLDR11_VLDF352_B_0X1	(0x1u<<0)

// SFSR0 Configuration

#define	BSEC_SFSR0_SFW31				(0x1u<<31)
#define	BSEC_SFSR0_SFW30				(0x1u<<30)
#define	BSEC_SFSR0_SFW29				(0x1u<<29)
#define	BSEC_SFSR0_SFW28				(0x1u<<28)
#define	BSEC_SFSR0_SFW27				(0x1u<<27)
#define	BSEC_SFSR0_SFW26				(0x1u<<26)
#define	BSEC_SFSR0_SFW25				(0x1u<<25)
#define	BSEC_SFSR0_SFW24				(0x1u<<24)
#define	BSEC_SFSR0_SFW23				(0x1u<<23)
#define	BSEC_SFSR0_SFW22				(0x1u<<22)
#define	BSEC_SFSR0_SFW21				(0x1u<<21)
#define	BSEC_SFSR0_SFW20				(0x1u<<20)
#define	BSEC_SFSR0_SFW19				(0x1u<<19)
#define	BSEC_SFSR0_SFW18				(0x1u<<18)
#define	BSEC_SFSR0_SFW17				(0x1u<<17)
#define	BSEC_SFSR0_SFW16				(0x1u<<16)
#define	BSEC_SFSR0_SFW15				(0x1u<<15)
#define	BSEC_SFSR0_SFW14				(0x1u<<14)
#define	BSEC_SFSR0_SFW13				(0x1u<<13)
#define	BSEC_SFSR0_SFW12				(0x1u<<12)
#define	BSEC_SFSR0_SFW11				(0x1u<<11)
#define	BSEC_SFSR0_SFW10				(0x1u<<10)
#define	BSEC_SFSR0_SFW9					(0x1u<<9)
#define	BSEC_SFSR0_SFW8					(0x1u<<8)
#define	BSEC_SFSR0_SFW7					(0x1u<<7)
#define	BSEC_SFSR0_SFW6					(0x1u<<6)
#define	BSEC_SFSR0_SFW5					(0x1u<<5)
#define	BSEC_SFSR0_SFW4					(0x1u<<4)
#define	BSEC_SFSR0_SFW3					(0x1u<<3)
#define	BSEC_SFSR0_SFW2					(0x1u<<2)
#define	BSEC_SFSR0_SFW1					(0x1u<<1)
#define	BSEC_SFSR0_SFW0					(0x1u<<0)

#define	BSEC_SFSR0_SFW31_B_0X0			(0x0u<<31)
#define	BSEC_SFSR0_SFW31_B_0X1			(0x1u<<31)
#define	BSEC_SFSR0_SFW30_B_0X0			(0x0u<<30)
#define	BSEC_SFSR0_SFW30_B_0X1			(0x1u<<30)
#define	BSEC_SFSR0_SFW29_B_0X0			(0x0u<<29)
#define	BSEC_SFSR0_SFW29_B_0X1			(0x1u<<29)
#define	BSEC_SFSR0_SFW28_B_0X0			(0x0u<<28)
#define	BSEC_SFSR0_SFW28_B_0X1			(0x1u<<28)
#define	BSEC_SFSR0_SFW27_B_0X0			(0x0u<<27)
#define	BSEC_SFSR0_SFW27_B_0X1			(0x1u<<27)
#define	BSEC_SFSR0_SFW26_B_0X0			(0x0u<<26)
#define	BSEC_SFSR0_SFW26_B_0X1			(0x1u<<26)
#define	BSEC_SFSR0_SFW25_B_0X0			(0x0u<<25)
#define	BSEC_SFSR0_SFW25_B_0X1			(0x1u<<25)
#define	BSEC_SFSR0_SFW24_B_0X0			(0x0u<<24)
#define	BSEC_SFSR0_SFW24_B_0X1			(0x1u<<24)
#define	BSEC_SFSR0_SFW23_B_0X0			(0x0u<<23)
#define	BSEC_SFSR0_SFW23_B_0X1			(0x1u<<23)
#define	BSEC_SFSR0_SFW22_B_0X0			(0x0u<<22)
#define	BSEC_SFSR0_SFW22_B_0X1			(0x1u<<22)
#define	BSEC_SFSR0_SFW21_B_0X0			(0x0u<<21)
#define	BSEC_SFSR0_SFW21_B_0X1			(0x1u<<21)
#define	BSEC_SFSR0_SFW20_B_0X0			(0x0u<<20)
#define	BSEC_SFSR0_SFW20_B_0X1			(0x1u<<20)
#define	BSEC_SFSR0_SFW19_B_0X0			(0x0u<<19)
#define	BSEC_SFSR0_SFW19_B_0X1			(0x1u<<19)
#define	BSEC_SFSR0_SFW18_B_0X0			(0x0u<<18)
#define	BSEC_SFSR0_SFW18_B_0X1			(0x1u<<18)
#define	BSEC_SFSR0_SFW17_B_0X0			(0x0u<<17)
#define	BSEC_SFSR0_SFW17_B_0X1			(0x1u<<17)
#define	BSEC_SFSR0_SFW16_B_0X0			(0x0u<<16)
#define	BSEC_SFSR0_SFW16_B_0X1			(0x1u<<16)
#define	BSEC_SFSR0_SFW15_B_0X0			(0x0u<<15)
#define	BSEC_SFSR0_SFW15_B_0X1			(0x1u<<15)
#define	BSEC_SFSR0_SFW14_B_0X0			(0x0u<<14)
#define	BSEC_SFSR0_SFW14_B_0X1			(0x1u<<14)
#define	BSEC_SFSR0_SFW13_B_0X0			(0x0u<<13)
#define	BSEC_SFSR0_SFW13_B_0X1			(0x1u<<13)
#define	BSEC_SFSR0_SFW12_B_0X0			(0x0u<<12)
#define	BSEC_SFSR0_SFW12_B_0X1			(0x1u<<12)
#define	BSEC_SFSR0_SFW11_B_0X0			(0x0u<<11)
#define	BSEC_SFSR0_SFW11_B_0X1			(0x1u<<11)
#define	BSEC_SFSR0_SFW10_B_0X0			(0x0u<<10)
#define	BSEC_SFSR0_SFW10_B_0X1			(0x1u<<10)
#define	BSEC_SFSR0_SFW9_B_0X0			(0x0u<<9)
#define	BSEC_SFSR0_SFW9_B_0X1			(0x1u<<9)
#define	BSEC_SFSR0_SFW8_B_0X0			(0x0u<<8)
#define	BSEC_SFSR0_SFW8_B_0X1			(0x1u<<8)
#define	BSEC_SFSR0_SFW7_B_0X0			(0x0u<<7)
#define	BSEC_SFSR0_SFW7_B_0X1			(0x1u<<7)
#define	BSEC_SFSR0_SFW6_B_0X0			(0x0u<<6)
#define	BSEC_SFSR0_SFW6_B_0X1			(0x1u<<6)
#define	BSEC_SFSR0_SFW5_B_0X0			(0x0u<<5)
#define	BSEC_SFSR0_SFW5_B_0X1			(0x1u<<5)
#define	BSEC_SFSR0_SFW4_B_0X0			(0x0u<<4)
#define	BSEC_SFSR0_SFW4_B_0X1			(0x1u<<4)
#define	BSEC_SFSR0_SFW3_B_0X0			(0x0u<<3)
#define	BSEC_SFSR0_SFW3_B_0X1			(0x1u<<3)
#define	BSEC_SFSR0_SFW2_B_0X0			(0x0u<<2)
#define	BSEC_SFSR0_SFW2_B_0X1			(0x1u<<2)
#define	BSEC_SFSR0_SFW1_B_0X0			(0x0u<<1)
#define	BSEC_SFSR0_SFW1_B_0X1			(0x1u<<1)
#define	BSEC_SFSR0_SFW0_B_0X0			(0x0u<<0)
#define	BSEC_SFSR0_SFW0_B_0X1			(0x1u<<0)

// SFSR1 Configuration

#define	BSEC_SFSR1_SFW63				(0x1u<<31)
#define	BSEC_SFSR1_SFW62				(0x1u<<30)
#define	BSEC_SFSR1_SFW61				(0x1u<<29)
#define	BSEC_SFSR1_SFW60				(0x1u<<28)
#define	BSEC_SFSR1_SFW59				(0x1u<<27)
#define	BSEC_SFSR1_SFW58				(0x1u<<26)
#define	BSEC_SFSR1_SFW57				(0x1u<<25)
#define	BSEC_SFSR1_SFW56				(0x1u<<24)
#define	BSEC_SFSR1_SFW55				(0x1u<<23)
#define	BSEC_SFSR1_SFW54				(0x1u<<22)
#define	BSEC_SFSR1_SFW53				(0x1u<<21)
#define	BSEC_SFSR1_SFW52				(0x1u<<20)
#define	BSEC_SFSR1_SFW51				(0x1u<<19)
#define	BSEC_SFSR1_SFW50				(0x1u<<18)
#define	BSEC_SFSR1_SFW49				(0x1u<<17)
#define	BSEC_SFSR1_SFW48				(0x1u<<16)
#define	BSEC_SFSR1_SFW47				(0x1u<<15)
#define	BSEC_SFSR1_SFW46				(0x1u<<14)
#define	BSEC_SFSR1_SFW45				(0x1u<<13)
#define	BSEC_SFSR1_SFW44				(0x1u<<12)
#define	BSEC_SFSR1_SFW43				(0x1u<<11)
#define	BSEC_SFSR1_SFW42				(0x1u<<10)
#define	BSEC_SFSR1_SFW41				(0x1u<<9)
#define	BSEC_SFSR1_SFW40				(0x1u<<8)
#define	BSEC_SFSR1_SFW39				(0x1u<<7)
#define	BSEC_SFSR1_SFW38				(0x1u<<6)
#define	BSEC_SFSR1_SFW37				(0x1u<<5)
#define	BSEC_SFSR1_SFW36				(0x1u<<4)
#define	BSEC_SFSR1_SFW35				(0x1u<<3)
#define	BSEC_SFSR1_SFW34				(0x1u<<2)
#define	BSEC_SFSR1_SFW33				(0x1u<<1)
#define	BSEC_SFSR1_SFW32				(0x1u<<0)

#define	BSEC_SFSR1_SFW63_B_0X0			(0x0u<<31)
#define	BSEC_SFSR1_SFW63_B_0X1			(0x1u<<31)
#define	BSEC_SFSR1_SFW62_B_0X0			(0x0u<<30)
#define	BSEC_SFSR1_SFW62_B_0X1			(0x1u<<30)
#define	BSEC_SFSR1_SFW61_B_0X0			(0x0u<<29)
#define	BSEC_SFSR1_SFW61_B_0X1			(0x1u<<29)
#define	BSEC_SFSR1_SFW60_B_0X0			(0x0u<<28)
#define	BSEC_SFSR1_SFW60_B_0X1			(0x1u<<28)
#define	BSEC_SFSR1_SFW59_B_0X0			(0x0u<<27)
#define	BSEC_SFSR1_SFW59_B_0X1			(0x1u<<27)
#define	BSEC_SFSR1_SFW58_B_0X0			(0x0u<<26)
#define	BSEC_SFSR1_SFW58_B_0X1			(0x1u<<26)
#define	BSEC_SFSR1_SFW57_B_0X0			(0x0u<<25)
#define	BSEC_SFSR1_SFW57_B_0X1			(0x1u<<25)
#define	BSEC_SFSR1_SFW56_B_0X0			(0x0u<<24)
#define	BSEC_SFSR1_SFW56_B_0X1			(0x1u<<24)
#define	BSEC_SFSR1_SFW55_B_0X0			(0x0u<<23)
#define	BSEC_SFSR1_SFW55_B_0X1			(0x1u<<23)
#define	BSEC_SFSR1_SFW54_B_0X0			(0x0u<<22)
#define	BSEC_SFSR1_SFW54_B_0X1			(0x1u<<22)
#define	BSEC_SFSR1_SFW53_B_0X0			(0x0u<<21)
#define	BSEC_SFSR1_SFW53_B_0X1			(0x1u<<21)
#define	BSEC_SFSR1_SFW52_B_0X0			(0x0u<<20)
#define	BSEC_SFSR1_SFW52_B_0X1			(0x1u<<20)
#define	BSEC_SFSR1_SFW51_B_0X0			(0x0u<<19)
#define	BSEC_SFSR1_SFW51_B_0X1			(0x1u<<19)
#define	BSEC_SFSR1_SFW50_B_0X0			(0x0u<<18)
#define	BSEC_SFSR1_SFW50_B_0X1			(0x1u<<18)
#define	BSEC_SFSR1_SFW49_B_0X0			(0x0u<<17)
#define	BSEC_SFSR1_SFW49_B_0X1			(0x1u<<17)
#define	BSEC_SFSR1_SFW48_B_0X0			(0x0u<<16)
#define	BSEC_SFSR1_SFW48_B_0X1			(0x1u<<16)
#define	BSEC_SFSR1_SFW47_B_0X0			(0x0u<<15)
#define	BSEC_SFSR1_SFW47_B_0X1			(0x1u<<15)
#define	BSEC_SFSR1_SFW46_B_0X0			(0x0u<<14)
#define	BSEC_SFSR1_SFW46_B_0X1			(0x1u<<14)
#define	BSEC_SFSR1_SFW45_B_0X0			(0x0u<<13)
#define	BSEC_SFSR1_SFW45_B_0X1			(0x1u<<13)
#define	BSEC_SFSR1_SFW44_B_0X0			(0x0u<<12)
#define	BSEC_SFSR1_SFW44_B_0X1			(0x1u<<12)
#define	BSEC_SFSR1_SFW43_B_0X0			(0x0u<<11)
#define	BSEC_SFSR1_SFW43_B_0X1			(0x1u<<11)
#define	BSEC_SFSR1_SFW42_B_0X0			(0x0u<<10)
#define	BSEC_SFSR1_SFW42_B_0X1			(0x1u<<10)
#define	BSEC_SFSR1_SFW41_B_0X0			(0x0u<<9)
#define	BSEC_SFSR1_SFW41_B_0X1			(0x1u<<9)
#define	BSEC_SFSR1_SFW40_B_0X0			(0x0u<<8)
#define	BSEC_SFSR1_SFW40_B_0X1			(0x1u<<8)
#define	BSEC_SFSR1_SFW39_B_0X0			(0x0u<<7)
#define	BSEC_SFSR1_SFW39_B_0X1			(0x1u<<7)
#define	BSEC_SFSR1_SFW38_B_0X0			(0x0u<<6)
#define	BSEC_SFSR1_SFW38_B_0X1			(0x1u<<6)
#define	BSEC_SFSR1_SFW37_B_0X0			(0x0u<<5)
#define	BSEC_SFSR1_SFW37_B_0X1			(0x1u<<5)
#define	BSEC_SFSR1_SFW36_B_0X0			(0x0u<<4)
#define	BSEC_SFSR1_SFW36_B_0X1			(0x1u<<4)
#define	BSEC_SFSR1_SFW35_B_0X0			(0x0u<<3)
#define	BSEC_SFSR1_SFW35_B_0X1			(0x1u<<3)
#define	BSEC_SFSR1_SFW34_B_0X0			(0x0u<<2)
#define	BSEC_SFSR1_SFW34_B_0X1			(0x1u<<2)
#define	BSEC_SFSR1_SFW33_B_0X0			(0x0u<<1)
#define	BSEC_SFSR1_SFW33_B_0X1			(0x1u<<1)
#define	BSEC_SFSR1_SFW32_B_0X0			(0x0u<<0)
#define	BSEC_SFSR1_SFW32_B_0X1			(0x1u<<0)

// SFSR2 Configuration

#define	BSEC_SFSR2_SFW95				(0x1u<<31)
#define	BSEC_SFSR2_SFW94				(0x1u<<30)
#define	BSEC_SFSR2_SFW93				(0x1u<<29)
#define	BSEC_SFSR2_SFW92				(0x1u<<28)
#define	BSEC_SFSR2_SFW91				(0x1u<<27)
#define	BSEC_SFSR2_SFW90				(0x1u<<26)
#define	BSEC_SFSR2_SFW89				(0x1u<<25)
#define	BSEC_SFSR2_SFW88				(0x1u<<24)
#define	BSEC_SFSR2_SFW87				(0x1u<<23)
#define	BSEC_SFSR2_SFW86				(0x1u<<22)
#define	BSEC_SFSR2_SFW85				(0x1u<<21)
#define	BSEC_SFSR2_SFW84				(0x1u<<20)
#define	BSEC_SFSR2_SFW83				(0x1u<<19)
#define	BSEC_SFSR2_SFW82				(0x1u<<18)
#define	BSEC_SFSR2_SFW81				(0x1u<<17)
#define	BSEC_SFSR2_SFW80				(0x1u<<16)
#define	BSEC_SFSR2_SFW79				(0x1u<<15)
#define	BSEC_SFSR2_SFW78				(0x1u<<14)
#define	BSEC_SFSR2_SFW77				(0x1u<<13)
#define	BSEC_SFSR2_SFW76				(0x1u<<12)
#define	BSEC_SFSR2_SFW75				(0x1u<<11)
#define	BSEC_SFSR2_SFW74				(0x1u<<10)
#define	BSEC_SFSR2_SFW73				(0x1u<<9)
#define	BSEC_SFSR2_SFW72				(0x1u<<8)
#define	BSEC_SFSR2_SFW71				(0x1u<<7)
#define	BSEC_SFSR2_SFW70				(0x1u<<6)
#define	BSEC_SFSR2_SFW69				(0x1u<<5)
#define	BSEC_SFSR2_SFW68				(0x1u<<4)
#define	BSEC_SFSR2_SFW67				(0x1u<<3)
#define	BSEC_SFSR2_SFW66				(0x1u<<2)
#define	BSEC_SFSR2_SFW65				(0x1u<<1)
#define	BSEC_SFSR2_SFW64				(0x1u<<0)

#define	BSEC_SFSR2_SFW95_B_0X0			(0x0u<<31)
#define	BSEC_SFSR2_SFW95_B_0X1			(0x1u<<31)
#define	BSEC_SFSR2_SFW94_B_0X0			(0x0u<<30)
#define	BSEC_SFSR2_SFW94_B_0X1			(0x1u<<30)
#define	BSEC_SFSR2_SFW93_B_0X0			(0x0u<<29)
#define	BSEC_SFSR2_SFW93_B_0X1			(0x1u<<29)
#define	BSEC_SFSR2_SFW92_B_0X0			(0x0u<<28)
#define	BSEC_SFSR2_SFW92_B_0X1			(0x1u<<28)
#define	BSEC_SFSR2_SFW91_B_0X0			(0x0u<<27)
#define	BSEC_SFSR2_SFW91_B_0X1			(0x1u<<27)
#define	BSEC_SFSR2_SFW90_B_0X0			(0x0u<<26)
#define	BSEC_SFSR2_SFW90_B_0X1			(0x1u<<26)
#define	BSEC_SFSR2_SFW89_B_0X0			(0x0u<<25)
#define	BSEC_SFSR2_SFW89_B_0X1			(0x1u<<25)
#define	BSEC_SFSR2_SFW88_B_0X0			(0x0u<<24)
#define	BSEC_SFSR2_SFW88_B_0X1			(0x1u<<24)
#define	BSEC_SFSR2_SFW87_B_0X0			(0x0u<<23)
#define	BSEC_SFSR2_SFW87_B_0X1			(0x1u<<23)
#define	BSEC_SFSR2_SFW86_B_0X0			(0x0u<<22)
#define	BSEC_SFSR2_SFW86_B_0X1			(0x1u<<22)
#define	BSEC_SFSR2_SFW85_B_0X0			(0x0u<<21)
#define	BSEC_SFSR2_SFW85_B_0X1			(0x1u<<21)
#define	BSEC_SFSR2_SFW84_B_0X0			(0x0u<<20)
#define	BSEC_SFSR2_SFW84_B_0X1			(0x1u<<20)
#define	BSEC_SFSR2_SFW83_B_0X0			(0x0u<<19)
#define	BSEC_SFSR2_SFW83_B_0X1			(0x1u<<19)
#define	BSEC_SFSR2_SFW82_B_0X0			(0x0u<<18)
#define	BSEC_SFSR2_SFW82_B_0X1			(0x1u<<18)
#define	BSEC_SFSR2_SFW81_B_0X0			(0x0u<<17)
#define	BSEC_SFSR2_SFW81_B_0X1			(0x1u<<17)
#define	BSEC_SFSR2_SFW80_B_0X0			(0x0u<<16)
#define	BSEC_SFSR2_SFW80_B_0X1			(0x1u<<16)
#define	BSEC_SFSR2_SFW79_B_0X0			(0x0u<<15)
#define	BSEC_SFSR2_SFW79_B_0X1			(0x1u<<15)
#define	BSEC_SFSR2_SFW78_B_0X0			(0x0u<<14)
#define	BSEC_SFSR2_SFW78_B_0X1			(0x1u<<14)
#define	BSEC_SFSR2_SFW77_B_0X0			(0x0u<<13)
#define	BSEC_SFSR2_SFW77_B_0X1			(0x1u<<13)
#define	BSEC_SFSR2_SFW76_B_0X0			(0x0u<<12)
#define	BSEC_SFSR2_SFW76_B_0X1			(0x1u<<12)
#define	BSEC_SFSR2_SFW75_B_0X0			(0x0u<<11)
#define	BSEC_SFSR2_SFW75_B_0X1			(0x1u<<11)
#define	BSEC_SFSR2_SFW74_B_0X0			(0x0u<<10)
#define	BSEC_SFSR2_SFW74_B_0X1			(0x1u<<10)
#define	BSEC_SFSR2_SFW73_B_0X0			(0x0u<<9)
#define	BSEC_SFSR2_SFW73_B_0X1			(0x1u<<9)
#define	BSEC_SFSR2_SFW72_B_0X0			(0x0u<<8)
#define	BSEC_SFSR2_SFW72_B_0X1			(0x1u<<8)
#define	BSEC_SFSR2_SFW71_B_0X0			(0x0u<<7)
#define	BSEC_SFSR2_SFW71_B_0X1			(0x1u<<7)
#define	BSEC_SFSR2_SFW70_B_0X0			(0x0u<<6)
#define	BSEC_SFSR2_SFW70_B_0X1			(0x1u<<6)
#define	BSEC_SFSR2_SFW69_B_0X0			(0x0u<<5)
#define	BSEC_SFSR2_SFW69_B_0X1			(0x1u<<5)
#define	BSEC_SFSR2_SFW68_B_0X0			(0x0u<<4)
#define	BSEC_SFSR2_SFW68_B_0X1			(0x1u<<4)
#define	BSEC_SFSR2_SFW67_B_0X0			(0x0u<<3)
#define	BSEC_SFSR2_SFW67_B_0X1			(0x1u<<3)
#define	BSEC_SFSR2_SFW66_B_0X0			(0x0u<<2)
#define	BSEC_SFSR2_SFW66_B_0X1			(0x1u<<2)
#define	BSEC_SFSR2_SFW65_B_0X0			(0x0u<<1)
#define	BSEC_SFSR2_SFW65_B_0X1			(0x1u<<1)
#define	BSEC_SFSR2_SFW64_B_0X0			(0x0u<<0)
#define	BSEC_SFSR2_SFW64_B_0X1			(0x1u<<0)

// SFSR3 Configuration

#define	BSEC_SFSR3_SFW127				(0x1u<<31)
#define	BSEC_SFSR3_SFW126				(0x1u<<30)
#define	BSEC_SFSR3_SFW125				(0x1u<<29)
#define	BSEC_SFSR3_SFW124				(0x1u<<28)
#define	BSEC_SFSR3_SFW123				(0x1u<<27)
#define	BSEC_SFSR3_SFW122				(0x1u<<26)
#define	BSEC_SFSR3_SFW121				(0x1u<<25)
#define	BSEC_SFSR3_SFW120				(0x1u<<24)
#define	BSEC_SFSR3_SFW119				(0x1u<<23)
#define	BSEC_SFSR3_SFW118				(0x1u<<22)
#define	BSEC_SFSR3_SFW117				(0x1u<<21)
#define	BSEC_SFSR3_SFW116				(0x1u<<20)
#define	BSEC_SFSR3_SFW115				(0x1u<<19)
#define	BSEC_SFSR3_SFW114				(0x1u<<18)
#define	BSEC_SFSR3_SFW113				(0x1u<<17)
#define	BSEC_SFSR3_SFW112				(0x1u<<16)
#define	BSEC_SFSR3_SFW111				(0x1u<<15)
#define	BSEC_SFSR3_SFW110				(0x1u<<14)
#define	BSEC_SFSR3_SFW109				(0x1u<<13)
#define	BSEC_SFSR3_SFW108				(0x1u<<12)
#define	BSEC_SFSR3_SFW107				(0x1u<<11)
#define	BSEC_SFSR3_SFW106				(0x1u<<10)
#define	BSEC_SFSR3_SFW105				(0x1u<<9)
#define	BSEC_SFSR3_SFW104				(0x1u<<8)
#define	BSEC_SFSR3_SFW103				(0x1u<<7)
#define	BSEC_SFSR3_SFW102				(0x1u<<6)
#define	BSEC_SFSR3_SFW101				(0x1u<<5)
#define	BSEC_SFSR3_SFW100				(0x1u<<4)
#define	BSEC_SFSR3_SFW99				(0x1u<<3)
#define	BSEC_SFSR3_SFW98				(0x1u<<2)
#define	BSEC_SFSR3_SFW97				(0x1u<<1)
#define	BSEC_SFSR3_SFW96				(0x1u<<0)

#define	BSEC_SFSR3_SFW127_B_0X0			(0x0u<<31)
#define	BSEC_SFSR3_SFW127_B_0X1			(0x1u<<31)
#define	BSEC_SFSR3_SFW126_B_0X0			(0x0u<<30)
#define	BSEC_SFSR3_SFW126_B_0X1			(0x1u<<30)
#define	BSEC_SFSR3_SFW125_B_0X0			(0x0u<<29)
#define	BSEC_SFSR3_SFW125_B_0X1			(0x1u<<29)
#define	BSEC_SFSR3_SFW124_B_0X0			(0x0u<<28)
#define	BSEC_SFSR3_SFW124_B_0X1			(0x1u<<28)
#define	BSEC_SFSR3_SFW123_B_0X0			(0x0u<<27)
#define	BSEC_SFSR3_SFW123_B_0X1			(0x1u<<27)
#define	BSEC_SFSR3_SFW122_B_0X0			(0x0u<<26)
#define	BSEC_SFSR3_SFW122_B_0X1			(0x1u<<26)
#define	BSEC_SFSR3_SFW121_B_0X0			(0x0u<<25)
#define	BSEC_SFSR3_SFW121_B_0X1			(0x1u<<25)
#define	BSEC_SFSR3_SFW120_B_0X0			(0x0u<<24)
#define	BSEC_SFSR3_SFW120_B_0X1			(0x1u<<24)
#define	BSEC_SFSR3_SFW119_B_0X0			(0x0u<<23)
#define	BSEC_SFSR3_SFW119_B_0X1			(0x1u<<23)
#define	BSEC_SFSR3_SFW118_B_0X0			(0x0u<<22)
#define	BSEC_SFSR3_SFW118_B_0X1			(0x1u<<22)
#define	BSEC_SFSR3_SFW117_B_0X0			(0x0u<<21)
#define	BSEC_SFSR3_SFW117_B_0X1			(0x1u<<21)
#define	BSEC_SFSR3_SFW116_B_0X0			(0x0u<<20)
#define	BSEC_SFSR3_SFW116_B_0X1			(0x1u<<20)
#define	BSEC_SFSR3_SFW115_B_0X0			(0x0u<<19)
#define	BSEC_SFSR3_SFW115_B_0X1			(0x1u<<19)
#define	BSEC_SFSR3_SFW114_B_0X0			(0x0u<<18)
#define	BSEC_SFSR3_SFW114_B_0X1			(0x1u<<18)
#define	BSEC_SFSR3_SFW113_B_0X0			(0x0u<<17)
#define	BSEC_SFSR3_SFW113_B_0X1			(0x1u<<17)
#define	BSEC_SFSR3_SFW112_B_0X0			(0x0u<<16)
#define	BSEC_SFSR3_SFW112_B_0X1			(0x1u<<16)
#define	BSEC_SFSR3_SFW111_B_0X0			(0x0u<<15)
#define	BSEC_SFSR3_SFW111_B_0X1			(0x1u<<15)
#define	BSEC_SFSR3_SFW110_B_0X0			(0x0u<<14)
#define	BSEC_SFSR3_SFW110_B_0X1			(0x1u<<14)
#define	BSEC_SFSR3_SFW109_B_0X0			(0x0u<<13)
#define	BSEC_SFSR3_SFW109_B_0X1			(0x1u<<13)
#define	BSEC_SFSR3_SFW108_B_0X0			(0x0u<<12)
#define	BSEC_SFSR3_SFW108_B_0X1			(0x1u<<12)
#define	BSEC_SFSR3_SFW107_B_0X0			(0x0u<<11)
#define	BSEC_SFSR3_SFW107_B_0X1			(0x1u<<11)
#define	BSEC_SFSR3_SFW106_B_0X0			(0x0u<<10)
#define	BSEC_SFSR3_SFW106_B_0X1			(0x1u<<10)
#define	BSEC_SFSR3_SFW105_B_0X0			(0x0u<<9)
#define	BSEC_SFSR3_SFW105_B_0X1			(0x1u<<9)
#define	BSEC_SFSR3_SFW104_B_0X0			(0x0u<<8)
#define	BSEC_SFSR3_SFW104_B_0X1			(0x1u<<8)
#define	BSEC_SFSR3_SFW103_B_0X0			(0x0u<<7)
#define	BSEC_SFSR3_SFW103_B_0X1			(0x1u<<7)
#define	BSEC_SFSR3_SFW102_B_0X0			(0x0u<<6)
#define	BSEC_SFSR3_SFW102_B_0X1			(0x1u<<6)
#define	BSEC_SFSR3_SFW101_B_0X0			(0x0u<<5)
#define	BSEC_SFSR3_SFW101_B_0X1			(0x1u<<5)
#define	BSEC_SFSR3_SFW100_B_0X0			(0x0u<<4)
#define	BSEC_SFSR3_SFW100_B_0X1			(0x1u<<4)
#define	BSEC_SFSR3_SFW99_B_0X0			(0x0u<<3)
#define	BSEC_SFSR3_SFW99_B_0X1			(0x1u<<3)
#define	BSEC_SFSR3_SFW98_B_0X0			(0x0u<<2)
#define	BSEC_SFSR3_SFW98_B_0X1			(0x1u<<2)
#define	BSEC_SFSR3_SFW97_B_0X0			(0x0u<<1)
#define	BSEC_SFSR3_SFW97_B_0X1			(0x1u<<1)
#define	BSEC_SFSR3_SFW96_B_0X0			(0x0u<<0)
#define	BSEC_SFSR3_SFW96_B_0X1			(0x1u<<0)

// SFSR4 Configuration

#define	BSEC_SFSR4_SFW159				(0x1u<<31)
#define	BSEC_SFSR4_SFW158				(0x1u<<30)
#define	BSEC_SFSR4_SFW157				(0x1u<<29)
#define	BSEC_SFSR4_SFW156				(0x1u<<28)
#define	BSEC_SFSR4_SFW155				(0x1u<<27)
#define	BSEC_SFSR4_SFW154				(0x1u<<26)
#define	BSEC_SFSR4_SFW153				(0x1u<<25)
#define	BSEC_SFSR4_SFW152				(0x1u<<24)
#define	BSEC_SFSR4_SFW151				(0x1u<<23)
#define	BSEC_SFSR4_SFW150				(0x1u<<22)
#define	BSEC_SFSR4_SFW149				(0x1u<<21)
#define	BSEC_SFSR4_SFW148				(0x1u<<20)
#define	BSEC_SFSR4_SFW147				(0x1u<<19)
#define	BSEC_SFSR4_SFW146				(0x1u<<18)
#define	BSEC_SFSR4_SFW145				(0x1u<<17)
#define	BSEC_SFSR4_SFW144				(0x1u<<16)
#define	BSEC_SFSR4_SFW143				(0x1u<<15)
#define	BSEC_SFSR4_SFW142				(0x1u<<14)
#define	BSEC_SFSR4_SFW141				(0x1u<<13)
#define	BSEC_SFSR4_SFW140				(0x1u<<12)
#define	BSEC_SFSR4_SFW139				(0x1u<<11)
#define	BSEC_SFSR4_SFW138				(0x1u<<10)
#define	BSEC_SFSR4_SFW137				(0x1u<<9)
#define	BSEC_SFSR4_SFW136				(0x1u<<8)
#define	BSEC_SFSR4_SFW135				(0x1u<<7)
#define	BSEC_SFSR4_SFW134				(0x1u<<6)
#define	BSEC_SFSR4_SFW133				(0x1u<<5)
#define	BSEC_SFSR4_SFW132				(0x1u<<4)
#define	BSEC_SFSR4_SFW131				(0x1u<<3)
#define	BSEC_SFSR4_SFW130				(0x1u<<2)
#define	BSEC_SFSR4_SFW129				(0x1u<<1)
#define	BSEC_SFSR4_SFW128				(0x1u<<0)

#define	BSEC_SFSR4_SFW159_B_0X0			(0x0u<<31)
#define	BSEC_SFSR4_SFW159_B_0X1			(0x1u<<31)
#define	BSEC_SFSR4_SFW158_B_0X0			(0x0u<<30)
#define	BSEC_SFSR4_SFW158_B_0X1			(0x1u<<30)
#define	BSEC_SFSR4_SFW157_B_0X0			(0x0u<<29)
#define	BSEC_SFSR4_SFW157_B_0X1			(0x1u<<29)
#define	BSEC_SFSR4_SFW156_B_0X0			(0x0u<<28)
#define	BSEC_SFSR4_SFW156_B_0X1			(0x1u<<28)
#define	BSEC_SFSR4_SFW155_B_0X0			(0x0u<<27)
#define	BSEC_SFSR4_SFW155_B_0X1			(0x1u<<27)
#define	BSEC_SFSR4_SFW154_B_0X0			(0x0u<<26)
#define	BSEC_SFSR4_SFW154_B_0X1			(0x1u<<26)
#define	BSEC_SFSR4_SFW153_B_0X0			(0x0u<<25)
#define	BSEC_SFSR4_SFW153_B_0X1			(0x1u<<25)
#define	BSEC_SFSR4_SFW152_B_0X0			(0x0u<<24)
#define	BSEC_SFSR4_SFW152_B_0X1			(0x1u<<24)
#define	BSEC_SFSR4_SFW151_B_0X0			(0x0u<<23)
#define	BSEC_SFSR4_SFW151_B_0X1			(0x1u<<23)
#define	BSEC_SFSR4_SFW150_B_0X0			(0x0u<<22)
#define	BSEC_SFSR4_SFW150_B_0X1			(0x1u<<22)
#define	BSEC_SFSR4_SFW149_B_0X0			(0x0u<<21)
#define	BSEC_SFSR4_SFW149_B_0X1			(0x1u<<21)
#define	BSEC_SFSR4_SFW148_B_0X0			(0x0u<<20)
#define	BSEC_SFSR4_SFW148_B_0X1			(0x1u<<20)
#define	BSEC_SFSR4_SFW147_B_0X0			(0x0u<<19)
#define	BSEC_SFSR4_SFW147_B_0X1			(0x1u<<19)
#define	BSEC_SFSR4_SFW146_B_0X0			(0x0u<<18)
#define	BSEC_SFSR4_SFW146_B_0X1			(0x1u<<18)
#define	BSEC_SFSR4_SFW145_B_0X0			(0x0u<<17)
#define	BSEC_SFSR4_SFW145_B_0X1			(0x1u<<17)
#define	BSEC_SFSR4_SFW144_B_0X0			(0x0u<<16)
#define	BSEC_SFSR4_SFW144_B_0X1			(0x1u<<16)
#define	BSEC_SFSR4_SFW143_B_0X0			(0x0u<<15)
#define	BSEC_SFSR4_SFW143_B_0X1			(0x1u<<15)
#define	BSEC_SFSR4_SFW142_B_0X0			(0x0u<<14)
#define	BSEC_SFSR4_SFW142_B_0X1			(0x1u<<14)
#define	BSEC_SFSR4_SFW141_B_0X0			(0x0u<<13)
#define	BSEC_SFSR4_SFW141_B_0X1			(0x1u<<13)
#define	BSEC_SFSR4_SFW140_B_0X0			(0x0u<<12)
#define	BSEC_SFSR4_SFW140_B_0X1			(0x1u<<12)
#define	BSEC_SFSR4_SFW139_B_0X0			(0x0u<<11)
#define	BSEC_SFSR4_SFW139_B_0X1			(0x1u<<11)
#define	BSEC_SFSR4_SFW138_B_0X0			(0x0u<<10)
#define	BSEC_SFSR4_SFW138_B_0X1			(0x1u<<10)
#define	BSEC_SFSR4_SFW137_B_0X0			(0x0u<<9)
#define	BSEC_SFSR4_SFW137_B_0X1			(0x1u<<9)
#define	BSEC_SFSR4_SFW136_B_0X0			(0x0u<<8)
#define	BSEC_SFSR4_SFW136_B_0X1			(0x1u<<8)
#define	BSEC_SFSR4_SFW135_B_0X0			(0x0u<<7)
#define	BSEC_SFSR4_SFW135_B_0X1			(0x1u<<7)
#define	BSEC_SFSR4_SFW134_B_0X0			(0x0u<<6)
#define	BSEC_SFSR4_SFW134_B_0X1			(0x1u<<6)
#define	BSEC_SFSR4_SFW133_B_0X0			(0x0u<<5)
#define	BSEC_SFSR4_SFW133_B_0X1			(0x1u<<5)
#define	BSEC_SFSR4_SFW132_B_0X0			(0x0u<<4)
#define	BSEC_SFSR4_SFW132_B_0X1			(0x1u<<4)
#define	BSEC_SFSR4_SFW131_B_0X0			(0x0u<<3)
#define	BSEC_SFSR4_SFW131_B_0X1			(0x1u<<3)
#define	BSEC_SFSR4_SFW130_B_0X0			(0x0u<<2)
#define	BSEC_SFSR4_SFW130_B_0X1			(0x1u<<2)
#define	BSEC_SFSR4_SFW129_B_0X0			(0x0u<<1)
#define	BSEC_SFSR4_SFW129_B_0X1			(0x1u<<1)
#define	BSEC_SFSR4_SFW128_B_0X0			(0x0u<<0)
#define	BSEC_SFSR4_SFW128_B_0X1			(0x1u<<0)

// SFSR5 Configuration

#define	BSEC_SFSR5_SFW191				(0x1u<<31)
#define	BSEC_SFSR5_SFW190				(0x1u<<30)
#define	BSEC_SFSR5_SFW189				(0x1u<<29)
#define	BSEC_SFSR5_SFW188				(0x1u<<28)
#define	BSEC_SFSR5_SFW187				(0x1u<<27)
#define	BSEC_SFSR5_SFW186				(0x1u<<26)
#define	BSEC_SFSR5_SFW185				(0x1u<<25)
#define	BSEC_SFSR5_SFW184				(0x1u<<24)
#define	BSEC_SFSR5_SFW183				(0x1u<<23)
#define	BSEC_SFSR5_SFW182				(0x1u<<22)
#define	BSEC_SFSR5_SFW181				(0x1u<<21)
#define	BSEC_SFSR5_SFW180				(0x1u<<20)
#define	BSEC_SFSR5_SFW179				(0x1u<<19)
#define	BSEC_SFSR5_SFW178				(0x1u<<18)
#define	BSEC_SFSR5_SFW177				(0x1u<<17)
#define	BSEC_SFSR5_SFW176				(0x1u<<16)
#define	BSEC_SFSR5_SFW175				(0x1u<<15)
#define	BSEC_SFSR5_SFW174				(0x1u<<14)
#define	BSEC_SFSR5_SFW173				(0x1u<<13)
#define	BSEC_SFSR5_SFW172				(0x1u<<12)
#define	BSEC_SFSR5_SFW171				(0x1u<<11)
#define	BSEC_SFSR5_SFW170				(0x1u<<10)
#define	BSEC_SFSR5_SFW169				(0x1u<<9)
#define	BSEC_SFSR5_SFW168				(0x1u<<8)
#define	BSEC_SFSR5_SFW167				(0x1u<<7)
#define	BSEC_SFSR5_SFW166				(0x1u<<6)
#define	BSEC_SFSR5_SFW165				(0x1u<<5)
#define	BSEC_SFSR5_SFW164				(0x1u<<4)
#define	BSEC_SFSR5_SFW163				(0x1u<<3)
#define	BSEC_SFSR5_SFW162				(0x1u<<2)
#define	BSEC_SFSR5_SFW161				(0x1u<<1)
#define	BSEC_SFSR5_SFW160				(0x1u<<0)

#define	BSEC_SFSR5_SFW191_B_0X0			(0x0u<<31)
#define	BSEC_SFSR5_SFW191_B_0X1			(0x1u<<31)
#define	BSEC_SFSR5_SFW190_B_0X0			(0x0u<<30)
#define	BSEC_SFSR5_SFW190_B_0X1			(0x1u<<30)
#define	BSEC_SFSR5_SFW189_B_0X0			(0x0u<<29)
#define	BSEC_SFSR5_SFW189_B_0X1			(0x1u<<29)
#define	BSEC_SFSR5_SFW188_B_0X0			(0x0u<<28)
#define	BSEC_SFSR5_SFW188_B_0X1			(0x1u<<28)
#define	BSEC_SFSR5_SFW187_B_0X0			(0x0u<<27)
#define	BSEC_SFSR5_SFW187_B_0X1			(0x1u<<27)
#define	BSEC_SFSR5_SFW186_B_0X0			(0x0u<<26)
#define	BSEC_SFSR5_SFW186_B_0X1			(0x1u<<26)
#define	BSEC_SFSR5_SFW185_B_0X0			(0x0u<<25)
#define	BSEC_SFSR5_SFW185_B_0X1			(0x1u<<25)
#define	BSEC_SFSR5_SFW184_B_0X0			(0x0u<<24)
#define	BSEC_SFSR5_SFW184_B_0X1			(0x1u<<24)
#define	BSEC_SFSR5_SFW183_B_0X0			(0x0u<<23)
#define	BSEC_SFSR5_SFW183_B_0X1			(0x1u<<23)
#define	BSEC_SFSR5_SFW182_B_0X0			(0x0u<<22)
#define	BSEC_SFSR5_SFW182_B_0X1			(0x1u<<22)
#define	BSEC_SFSR5_SFW181_B_0X0			(0x0u<<21)
#define	BSEC_SFSR5_SFW181_B_0X1			(0x1u<<21)
#define	BSEC_SFSR5_SFW180_B_0X0			(0x0u<<20)
#define	BSEC_SFSR5_SFW180_B_0X1			(0x1u<<20)
#define	BSEC_SFSR5_SFW179_B_0X0			(0x0u<<19)
#define	BSEC_SFSR5_SFW179_B_0X1			(0x1u<<19)
#define	BSEC_SFSR5_SFW178_B_0X0			(0x0u<<18)
#define	BSEC_SFSR5_SFW178_B_0X1			(0x1u<<18)
#define	BSEC_SFSR5_SFW177_B_0X0			(0x0u<<17)
#define	BSEC_SFSR5_SFW177_B_0X1			(0x1u<<17)
#define	BSEC_SFSR5_SFW176_B_0X0			(0x0u<<16)
#define	BSEC_SFSR5_SFW176_B_0X1			(0x1u<<16)
#define	BSEC_SFSR5_SFW175_B_0X0			(0x0u<<15)
#define	BSEC_SFSR5_SFW175_B_0X1			(0x1u<<15)
#define	BSEC_SFSR5_SFW174_B_0X0			(0x0u<<14)
#define	BSEC_SFSR5_SFW174_B_0X1			(0x1u<<14)
#define	BSEC_SFSR5_SFW173_B_0X0			(0x0u<<13)
#define	BSEC_SFSR5_SFW173_B_0X1			(0x1u<<13)
#define	BSEC_SFSR5_SFW172_B_0X0			(0x0u<<12)
#define	BSEC_SFSR5_SFW172_B_0X1			(0x1u<<12)
#define	BSEC_SFSR5_SFW171_B_0X0			(0x0u<<11)
#define	BSEC_SFSR5_SFW171_B_0X1			(0x1u<<11)
#define	BSEC_SFSR5_SFW170_B_0X0			(0x0u<<10)
#define	BSEC_SFSR5_SFW170_B_0X1			(0x1u<<10)
#define	BSEC_SFSR5_SFW169_B_0X0			(0x0u<<9)
#define	BSEC_SFSR5_SFW169_B_0X1			(0x1u<<9)
#define	BSEC_SFSR5_SFW168_B_0X0			(0x0u<<8)
#define	BSEC_SFSR5_SFW168_B_0X1			(0x1u<<8)
#define	BSEC_SFSR5_SFW167_B_0X0			(0x0u<<7)
#define	BSEC_SFSR5_SFW167_B_0X1			(0x1u<<7)
#define	BSEC_SFSR5_SFW166_B_0X0			(0x0u<<6)
#define	BSEC_SFSR5_SFW166_B_0X1			(0x1u<<6)
#define	BSEC_SFSR5_SFW165_B_0X0			(0x0u<<5)
#define	BSEC_SFSR5_SFW165_B_0X1			(0x1u<<5)
#define	BSEC_SFSR5_SFW164_B_0X0			(0x0u<<4)
#define	BSEC_SFSR5_SFW164_B_0X1			(0x1u<<4)
#define	BSEC_SFSR5_SFW163_B_0X0			(0x0u<<3)
#define	BSEC_SFSR5_SFW163_B_0X1			(0x1u<<3)
#define	BSEC_SFSR5_SFW162_B_0X0			(0x0u<<2)
#define	BSEC_SFSR5_SFW162_B_0X1			(0x1u<<2)
#define	BSEC_SFSR5_SFW161_B_0X0			(0x0u<<1)
#define	BSEC_SFSR5_SFW161_B_0X1			(0x1u<<1)
#define	BSEC_SFSR5_SFW160_B_0X0			(0x0u<<0)
#define	BSEC_SFSR5_SFW160_B_0X1			(0x1u<<0)

// SFSR6 Configuration

#define	BSEC_SFSR6_SFW223				(0x1u<<31)
#define	BSEC_SFSR6_SFW222				(0x1u<<30)
#define	BSEC_SFSR6_SFW221				(0x1u<<29)
#define	BSEC_SFSR6_SFW220				(0x1u<<28)
#define	BSEC_SFSR6_SFW219				(0x1u<<27)
#define	BSEC_SFSR6_SFW218				(0x1u<<26)
#define	BSEC_SFSR6_SFW217				(0x1u<<25)
#define	BSEC_SFSR6_SFW216				(0x1u<<24)
#define	BSEC_SFSR6_SFW215				(0x1u<<23)
#define	BSEC_SFSR6_SFW214				(0x1u<<22)
#define	BSEC_SFSR6_SFW213				(0x1u<<21)
#define	BSEC_SFSR6_SFW212				(0x1u<<20)
#define	BSEC_SFSR6_SFW211				(0x1u<<19)
#define	BSEC_SFSR6_SFW210				(0x1u<<18)
#define	BSEC_SFSR6_SFW209				(0x1u<<17)
#define	BSEC_SFSR6_SFW208				(0x1u<<16)
#define	BSEC_SFSR6_SFW207				(0x1u<<15)
#define	BSEC_SFSR6_SFW206				(0x1u<<14)
#define	BSEC_SFSR6_SFW205				(0x1u<<13)
#define	BSEC_SFSR6_SFW204				(0x1u<<12)
#define	BSEC_SFSR6_SFW203				(0x1u<<11)
#define	BSEC_SFSR6_SFW202				(0x1u<<10)
#define	BSEC_SFSR6_SFW201				(0x1u<<9)
#define	BSEC_SFSR6_SFW200				(0x1u<<8)
#define	BSEC_SFSR6_SFW199				(0x1u<<7)
#define	BSEC_SFSR6_SFW198				(0x1u<<6)
#define	BSEC_SFSR6_SFW197				(0x1u<<5)
#define	BSEC_SFSR6_SFW196				(0x1u<<4)
#define	BSEC_SFSR6_SFW195				(0x1u<<3)
#define	BSEC_SFSR6_SFW194				(0x1u<<2)
#define	BSEC_SFSR6_SFW193				(0x1u<<1)
#define	BSEC_SFSR6_SFW192				(0x1u<<0)

#define	BSEC_SFSR6_SFW223_B_0X0			(0x0u<<31)
#define	BSEC_SFSR6_SFW223_B_0X1			(0x1u<<31)
#define	BSEC_SFSR6_SFW222_B_0X0			(0x0u<<30)
#define	BSEC_SFSR6_SFW222_B_0X1			(0x1u<<30)
#define	BSEC_SFSR6_SFW221_B_0X0			(0x0u<<29)
#define	BSEC_SFSR6_SFW221_B_0X1			(0x1u<<29)
#define	BSEC_SFSR6_SFW220_B_0X0			(0x0u<<28)
#define	BSEC_SFSR6_SFW220_B_0X1			(0x1u<<28)
#define	BSEC_SFSR6_SFW219_B_0X0			(0x0u<<27)
#define	BSEC_SFSR6_SFW219_B_0X1			(0x1u<<27)
#define	BSEC_SFSR6_SFW218_B_0X0			(0x0u<<26)
#define	BSEC_SFSR6_SFW218_B_0X1			(0x1u<<26)
#define	BSEC_SFSR6_SFW217_B_0X0			(0x0u<<25)
#define	BSEC_SFSR6_SFW217_B_0X1			(0x1u<<25)
#define	BSEC_SFSR6_SFW216_B_0X0			(0x0u<<24)
#define	BSEC_SFSR6_SFW216_B_0X1			(0x1u<<24)
#define	BSEC_SFSR6_SFW215_B_0X0			(0x0u<<23)
#define	BSEC_SFSR6_SFW215_B_0X1			(0x1u<<23)
#define	BSEC_SFSR6_SFW214_B_0X0			(0x0u<<22)
#define	BSEC_SFSR6_SFW214_B_0X1			(0x1u<<22)
#define	BSEC_SFSR6_SFW213_B_0X0			(0x0u<<21)
#define	BSEC_SFSR6_SFW213_B_0X1			(0x1u<<21)
#define	BSEC_SFSR6_SFW212_B_0X0			(0x0u<<20)
#define	BSEC_SFSR6_SFW212_B_0X1			(0x1u<<20)
#define	BSEC_SFSR6_SFW211_B_0X0			(0x0u<<19)
#define	BSEC_SFSR6_SFW211_B_0X1			(0x1u<<19)
#define	BSEC_SFSR6_SFW210_B_0X0			(0x0u<<18)
#define	BSEC_SFSR6_SFW210_B_0X1			(0x1u<<18)
#define	BSEC_SFSR6_SFW209_B_0X0			(0x0u<<17)
#define	BSEC_SFSR6_SFW209_B_0X1			(0x1u<<17)
#define	BSEC_SFSR6_SFW208_B_0X0			(0x0u<<16)
#define	BSEC_SFSR6_SFW208_B_0X1			(0x1u<<16)
#define	BSEC_SFSR6_SFW207_B_0X0			(0x0u<<15)
#define	BSEC_SFSR6_SFW207_B_0X1			(0x1u<<15)
#define	BSEC_SFSR6_SFW206_B_0X0			(0x0u<<14)
#define	BSEC_SFSR6_SFW206_B_0X1			(0x1u<<14)
#define	BSEC_SFSR6_SFW205_B_0X0			(0x0u<<13)
#define	BSEC_SFSR6_SFW205_B_0X1			(0x1u<<13)
#define	BSEC_SFSR6_SFW204_B_0X0			(0x0u<<12)
#define	BSEC_SFSR6_SFW204_B_0X1			(0x1u<<12)
#define	BSEC_SFSR6_SFW203_B_0X0			(0x0u<<11)
#define	BSEC_SFSR6_SFW203_B_0X1			(0x1u<<11)
#define	BSEC_SFSR6_SFW202_B_0X0			(0x0u<<10)
#define	BSEC_SFSR6_SFW202_B_0X1			(0x1u<<10)
#define	BSEC_SFSR6_SFW201_B_0X0			(0x0u<<9)
#define	BSEC_SFSR6_SFW201_B_0X1			(0x1u<<9)
#define	BSEC_SFSR6_SFW200_B_0X0			(0x0u<<8)
#define	BSEC_SFSR6_SFW200_B_0X1			(0x1u<<8)
#define	BSEC_SFSR6_SFW199_B_0X0			(0x0u<<7)
#define	BSEC_SFSR6_SFW199_B_0X1			(0x1u<<7)
#define	BSEC_SFSR6_SFW198_B_0X0			(0x0u<<6)
#define	BSEC_SFSR6_SFW198_B_0X1			(0x1u<<6)
#define	BSEC_SFSR6_SFW197_B_0X0			(0x0u<<5)
#define	BSEC_SFSR6_SFW197_B_0X1			(0x1u<<5)
#define	BSEC_SFSR6_SFW196_B_0X0			(0x0u<<4)
#define	BSEC_SFSR6_SFW196_B_0X1			(0x1u<<4)
#define	BSEC_SFSR6_SFW195_B_0X0			(0x0u<<3)
#define	BSEC_SFSR6_SFW195_B_0X1			(0x1u<<3)
#define	BSEC_SFSR6_SFW194_B_0X0			(0x0u<<2)
#define	BSEC_SFSR6_SFW194_B_0X1			(0x1u<<2)
#define	BSEC_SFSR6_SFW193_B_0X0			(0x0u<<1)
#define	BSEC_SFSR6_SFW193_B_0X1			(0x1u<<1)
#define	BSEC_SFSR6_SFW192_B_0X0			(0x0u<<0)
#define	BSEC_SFSR6_SFW192_B_0X1			(0x1u<<0)

// SFSR7 Configuration

#define	BSEC_SFSR7_SFW255				(0x1u<<31)
#define	BSEC_SFSR7_SFW254				(0x1u<<30)
#define	BSEC_SFSR7_SFW253				(0x1u<<29)
#define	BSEC_SFSR7_SFW252				(0x1u<<28)
#define	BSEC_SFSR7_SFW251				(0x1u<<27)
#define	BSEC_SFSR7_SFW250				(0x1u<<26)
#define	BSEC_SFSR7_SFW249				(0x1u<<25)
#define	BSEC_SFSR7_SFW248				(0x1u<<24)
#define	BSEC_SFSR7_SFW247				(0x1u<<23)
#define	BSEC_SFSR7_SFW246				(0x1u<<22)
#define	BSEC_SFSR7_SFW245				(0x1u<<21)
#define	BSEC_SFSR7_SFW244				(0x1u<<20)
#define	BSEC_SFSR7_SFW243				(0x1u<<19)
#define	BSEC_SFSR7_SFW242				(0x1u<<18)
#define	BSEC_SFSR7_SFW241				(0x1u<<17)
#define	BSEC_SFSR7_SFW240				(0x1u<<16)
#define	BSEC_SFSR7_SFW239				(0x1u<<15)
#define	BSEC_SFSR7_SFW238				(0x1u<<14)
#define	BSEC_SFSR7_SFW237				(0x1u<<13)
#define	BSEC_SFSR7_SFW236				(0x1u<<12)
#define	BSEC_SFSR7_SFW235				(0x1u<<11)
#define	BSEC_SFSR7_SFW234				(0x1u<<10)
#define	BSEC_SFSR7_SFW233				(0x1u<<9)
#define	BSEC_SFSR7_SFW232				(0x1u<<8)
#define	BSEC_SFSR7_SFW231				(0x1u<<7)
#define	BSEC_SFSR7_SFW230				(0x1u<<6)
#define	BSEC_SFSR7_SFW229				(0x1u<<5)
#define	BSEC_SFSR7_SFW228				(0x1u<<4)
#define	BSEC_SFSR7_SFW227				(0x1u<<3)
#define	BSEC_SFSR7_SFW226				(0x1u<<2)
#define	BSEC_SFSR7_SFW225				(0x1u<<1)
#define	BSEC_SFSR7_SFW224				(0x1u<<0)

#define	BSEC_SFSR7_SFW255_B_0X0			(0x0u<<31)
#define	BSEC_SFSR7_SFW255_B_0X1			(0x1u<<31)
#define	BSEC_SFSR7_SFW254_B_0X0			(0x0u<<30)
#define	BSEC_SFSR7_SFW254_B_0X1			(0x1u<<30)
#define	BSEC_SFSR7_SFW253_B_0X0			(0x0u<<29)
#define	BSEC_SFSR7_SFW253_B_0X1			(0x1u<<29)
#define	BSEC_SFSR7_SFW252_B_0X0			(0x0u<<28)
#define	BSEC_SFSR7_SFW252_B_0X1			(0x1u<<28)
#define	BSEC_SFSR7_SFW251_B_0X0			(0x0u<<27)
#define	BSEC_SFSR7_SFW251_B_0X1			(0x1u<<27)
#define	BSEC_SFSR7_SFW250_B_0X0			(0x0u<<26)
#define	BSEC_SFSR7_SFW250_B_0X1			(0x1u<<26)
#define	BSEC_SFSR7_SFW249_B_0X0			(0x0u<<25)
#define	BSEC_SFSR7_SFW249_B_0X1			(0x1u<<25)
#define	BSEC_SFSR7_SFW248_B_0X0			(0x0u<<24)
#define	BSEC_SFSR7_SFW248_B_0X1			(0x1u<<24)
#define	BSEC_SFSR7_SFW247_B_0X0			(0x0u<<23)
#define	BSEC_SFSR7_SFW247_B_0X1			(0x1u<<23)
#define	BSEC_SFSR7_SFW246_B_0X0			(0x0u<<22)
#define	BSEC_SFSR7_SFW246_B_0X1			(0x1u<<22)
#define	BSEC_SFSR7_SFW245_B_0X0			(0x0u<<21)
#define	BSEC_SFSR7_SFW245_B_0X1			(0x1u<<21)
#define	BSEC_SFSR7_SFW244_B_0X0			(0x0u<<20)
#define	BSEC_SFSR7_SFW244_B_0X1			(0x1u<<20)
#define	BSEC_SFSR7_SFW243_B_0X0			(0x0u<<19)
#define	BSEC_SFSR7_SFW243_B_0X1			(0x1u<<19)
#define	BSEC_SFSR7_SFW242_B_0X0			(0x0u<<18)
#define	BSEC_SFSR7_SFW242_B_0X1			(0x1u<<18)
#define	BSEC_SFSR7_SFW241_B_0X0			(0x0u<<17)
#define	BSEC_SFSR7_SFW241_B_0X1			(0x1u<<17)
#define	BSEC_SFSR7_SFW240_B_0X0			(0x0u<<16)
#define	BSEC_SFSR7_SFW240_B_0X1			(0x1u<<16)
#define	BSEC_SFSR7_SFW239_B_0X0			(0x0u<<15)
#define	BSEC_SFSR7_SFW239_B_0X1			(0x1u<<15)
#define	BSEC_SFSR7_SFW238_B_0X0			(0x0u<<14)
#define	BSEC_SFSR7_SFW238_B_0X1			(0x1u<<14)
#define	BSEC_SFSR7_SFW237_B_0X0			(0x0u<<13)
#define	BSEC_SFSR7_SFW237_B_0X1			(0x1u<<13)
#define	BSEC_SFSR7_SFW236_B_0X0			(0x0u<<12)
#define	BSEC_SFSR7_SFW236_B_0X1			(0x1u<<12)
#define	BSEC_SFSR7_SFW235_B_0X0			(0x0u<<11)
#define	BSEC_SFSR7_SFW235_B_0X1			(0x1u<<11)
#define	BSEC_SFSR7_SFW234_B_0X0			(0x0u<<10)
#define	BSEC_SFSR7_SFW234_B_0X1			(0x1u<<10)
#define	BSEC_SFSR7_SFW233_B_0X0			(0x0u<<9)
#define	BSEC_SFSR7_SFW233_B_0X1			(0x1u<<9)
#define	BSEC_SFSR7_SFW232_B_0X0			(0x0u<<8)
#define	BSEC_SFSR7_SFW232_B_0X1			(0x1u<<8)
#define	BSEC_SFSR7_SFW231_B_0X0			(0x0u<<7)
#define	BSEC_SFSR7_SFW231_B_0X1			(0x1u<<7)
#define	BSEC_SFSR7_SFW230_B_0X0			(0x0u<<6)
#define	BSEC_SFSR7_SFW230_B_0X1			(0x1u<<6)
#define	BSEC_SFSR7_SFW229_B_0X0			(0x0u<<5)
#define	BSEC_SFSR7_SFW229_B_0X1			(0x1u<<5)
#define	BSEC_SFSR7_SFW228_B_0X0			(0x0u<<4)
#define	BSEC_SFSR7_SFW228_B_0X1			(0x1u<<4)
#define	BSEC_SFSR7_SFW227_B_0X0			(0x0u<<3)
#define	BSEC_SFSR7_SFW227_B_0X1			(0x1u<<3)
#define	BSEC_SFSR7_SFW226_B_0X0			(0x0u<<2)
#define	BSEC_SFSR7_SFW226_B_0X1			(0x1u<<2)
#define	BSEC_SFSR7_SFW225_B_0X0			(0x0u<<1)
#define	BSEC_SFSR7_SFW225_B_0X1			(0x1u<<1)
#define	BSEC_SFSR7_SFW224_B_0X0			(0x0u<<0)
#define	BSEC_SFSR7_SFW224_B_0X1			(0x1u<<0)

// SFSR8 Configuration

#define	BSEC_SFSR8_SFW287				(0x1u<<31)
#define	BSEC_SFSR8_SFW286				(0x1u<<30)
#define	BSEC_SFSR8_SFW285				(0x1u<<29)
#define	BSEC_SFSR8_SFW284				(0x1u<<28)
#define	BSEC_SFSR8_SFW283				(0x1u<<27)
#define	BSEC_SFSR8_SFW282				(0x1u<<26)
#define	BSEC_SFSR8_SFW281				(0x1u<<25)
#define	BSEC_SFSR8_SFW280				(0x1u<<24)
#define	BSEC_SFSR8_SFW279				(0x1u<<23)
#define	BSEC_SFSR8_SFW278				(0x1u<<22)
#define	BSEC_SFSR8_SFW277				(0x1u<<21)
#define	BSEC_SFSR8_SFW276				(0x1u<<20)
#define	BSEC_SFSR8_SFW275				(0x1u<<19)
#define	BSEC_SFSR8_SFW274				(0x1u<<18)
#define	BSEC_SFSR8_SFW273				(0x1u<<17)
#define	BSEC_SFSR8_SFW272				(0x1u<<16)
#define	BSEC_SFSR8_SFW271				(0x1u<<15)
#define	BSEC_SFSR8_SFW270				(0x1u<<14)
#define	BSEC_SFSR8_SFW269				(0x1u<<13)
#define	BSEC_SFSR8_SFW268				(0x1u<<12)
#define	BSEC_SFSR8_SFW267				(0x1u<<11)
#define	BSEC_SFSR8_SFW266				(0x1u<<10)
#define	BSEC_SFSR8_SFW265				(0x1u<<9)
#define	BSEC_SFSR8_SFW264				(0x1u<<8)
#define	BSEC_SFSR8_SFW263				(0x1u<<7)
#define	BSEC_SFSR8_SFW262				(0x1u<<6)
#define	BSEC_SFSR8_SFW261				(0x1u<<5)
#define	BSEC_SFSR8_SFW260				(0x1u<<4)
#define	BSEC_SFSR8_SFW259				(0x1u<<3)
#define	BSEC_SFSR8_SFW258				(0x1u<<2)
#define	BSEC_SFSR8_SFW257				(0x1u<<1)
#define	BSEC_SFSR8_SFW256				(0x1u<<0)

#define	BSEC_SFSR8_SFW287_B_0X0			(0x0u<<31)
#define	BSEC_SFSR8_SFW287_B_0X1			(0x1u<<31)
#define	BSEC_SFSR8_SFW286_B_0X0			(0x0u<<30)
#define	BSEC_SFSR8_SFW286_B_0X1			(0x1u<<30)
#define	BSEC_SFSR8_SFW285_B_0X0			(0x0u<<29)
#define	BSEC_SFSR8_SFW285_B_0X1			(0x1u<<29)
#define	BSEC_SFSR8_SFW284_B_0X0			(0x0u<<28)
#define	BSEC_SFSR8_SFW284_B_0X1			(0x1u<<28)
#define	BSEC_SFSR8_SFW283_B_0X0			(0x0u<<27)
#define	BSEC_SFSR8_SFW283_B_0X1			(0x1u<<27)
#define	BSEC_SFSR8_SFW282_B_0X0			(0x0u<<26)
#define	BSEC_SFSR8_SFW282_B_0X1			(0x1u<<26)
#define	BSEC_SFSR8_SFW281_B_0X0			(0x0u<<25)
#define	BSEC_SFSR8_SFW281_B_0X1			(0x1u<<25)
#define	BSEC_SFSR8_SFW280_B_0X0			(0x0u<<24)
#define	BSEC_SFSR8_SFW280_B_0X1			(0x1u<<24)
#define	BSEC_SFSR8_SFW279_B_0X0			(0x0u<<23)
#define	BSEC_SFSR8_SFW279_B_0X1			(0x1u<<23)
#define	BSEC_SFSR8_SFW278_B_0X0			(0x0u<<22)
#define	BSEC_SFSR8_SFW278_B_0X1			(0x1u<<22)
#define	BSEC_SFSR8_SFW277_B_0X0			(0x0u<<21)
#define	BSEC_SFSR8_SFW277_B_0X1			(0x1u<<21)
#define	BSEC_SFSR8_SFW276_B_0X0			(0x0u<<20)
#define	BSEC_SFSR8_SFW276_B_0X1			(0x1u<<20)
#define	BSEC_SFSR8_SFW275_B_0X0			(0x0u<<19)
#define	BSEC_SFSR8_SFW275_B_0X1			(0x1u<<19)
#define	BSEC_SFSR8_SFW274_B_0X0			(0x0u<<18)
#define	BSEC_SFSR8_SFW274_B_0X1			(0x1u<<18)
#define	BSEC_SFSR8_SFW273_B_0X0			(0x0u<<17)
#define	BSEC_SFSR8_SFW273_B_0X1			(0x1u<<17)
#define	BSEC_SFSR8_SFW272_B_0X0			(0x0u<<16)
#define	BSEC_SFSR8_SFW272_B_0X1			(0x1u<<16)
#define	BSEC_SFSR8_SFW271_B_0X0			(0x0u<<15)
#define	BSEC_SFSR8_SFW271_B_0X1			(0x1u<<15)
#define	BSEC_SFSR8_SFW270_B_0X0			(0x0u<<14)
#define	BSEC_SFSR8_SFW270_B_0X1			(0x1u<<14)
#define	BSEC_SFSR8_SFW269_B_0X0			(0x0u<<13)
#define	BSEC_SFSR8_SFW269_B_0X1			(0x1u<<13)
#define	BSEC_SFSR8_SFW268_B_0X0			(0x0u<<12)
#define	BSEC_SFSR8_SFW268_B_0X1			(0x1u<<12)
#define	BSEC_SFSR8_SFW267_B_0X0			(0x0u<<11)
#define	BSEC_SFSR8_SFW267_B_0X1			(0x1u<<11)
#define	BSEC_SFSR8_SFW266_B_0X0			(0x0u<<10)
#define	BSEC_SFSR8_SFW266_B_0X1			(0x1u<<10)
#define	BSEC_SFSR8_SFW265_B_0X0			(0x0u<<9)
#define	BSEC_SFSR8_SFW265_B_0X1			(0x1u<<9)
#define	BSEC_SFSR8_SFW264_B_0X0			(0x0u<<8)
#define	BSEC_SFSR8_SFW264_B_0X1			(0x1u<<8)
#define	BSEC_SFSR8_SFW263_B_0X0			(0x0u<<7)
#define	BSEC_SFSR8_SFW263_B_0X1			(0x1u<<7)
#define	BSEC_SFSR8_SFW262_B_0X0			(0x0u<<6)
#define	BSEC_SFSR8_SFW262_B_0X1			(0x1u<<6)
#define	BSEC_SFSR8_SFW261_B_0X0			(0x0u<<5)
#define	BSEC_SFSR8_SFW261_B_0X1			(0x1u<<5)
#define	BSEC_SFSR8_SFW260_B_0X0			(0x0u<<4)
#define	BSEC_SFSR8_SFW260_B_0X1			(0x1u<<4)
#define	BSEC_SFSR8_SFW259_B_0X0			(0x0u<<3)
#define	BSEC_SFSR8_SFW259_B_0X1			(0x1u<<3)
#define	BSEC_SFSR8_SFW258_B_0X0			(0x0u<<2)
#define	BSEC_SFSR8_SFW258_B_0X1			(0x1u<<2)
#define	BSEC_SFSR8_SFW257_B_0X0			(0x0u<<1)
#define	BSEC_SFSR8_SFW257_B_0X1			(0x1u<<1)
#define	BSEC_SFSR8_SFW256_B_0X0			(0x0u<<0)
#define	BSEC_SFSR8_SFW256_B_0X1			(0x1u<<0)

// SFSR9 Configuration

#define	BSEC_SFSR9_SFW319				(0x1u<<31)
#define	BSEC_SFSR9_SFW318				(0x1u<<30)
#define	BSEC_SFSR9_SFW317				(0x1u<<29)
#define	BSEC_SFSR9_SFW316				(0x1u<<28)
#define	BSEC_SFSR9_SFW315				(0x1u<<27)
#define	BSEC_SFSR9_SFW314				(0x1u<<26)
#define	BSEC_SFSR9_SFW313				(0x1u<<25)
#define	BSEC_SFSR9_SFW312				(0x1u<<24)
#define	BSEC_SFSR9_SFW311				(0x1u<<23)
#define	BSEC_SFSR9_SFW310				(0x1u<<22)
#define	BSEC_SFSR9_SFW309				(0x1u<<21)
#define	BSEC_SFSR9_SFW308				(0x1u<<20)
#define	BSEC_SFSR9_SFW307				(0x1u<<19)
#define	BSEC_SFSR9_SFW306				(0x1u<<18)
#define	BSEC_SFSR9_SFW305				(0x1u<<17)
#define	BSEC_SFSR9_SFW304				(0x1u<<16)
#define	BSEC_SFSR9_SFW303				(0x1u<<15)
#define	BSEC_SFSR9_SFW302				(0x1u<<14)
#define	BSEC_SFSR9_SFW301				(0x1u<<13)
#define	BSEC_SFSR9_SFW300				(0x1u<<12)
#define	BSEC_SFSR9_SFW299				(0x1u<<11)
#define	BSEC_SFSR9_SFW298				(0x1u<<10)
#define	BSEC_SFSR9_SFW297				(0x1u<<9)
#define	BSEC_SFSR9_SFW296				(0x1u<<8)
#define	BSEC_SFSR9_SFW295				(0x1u<<7)
#define	BSEC_SFSR9_SFW294				(0x1u<<6)
#define	BSEC_SFSR9_SFW293				(0x1u<<5)
#define	BSEC_SFSR9_SFW292				(0x1u<<4)
#define	BSEC_SFSR9_SFW291				(0x1u<<3)
#define	BSEC_SFSR9_SFW290				(0x1u<<2)
#define	BSEC_SFSR9_SFW289				(0x1u<<1)
#define	BSEC_SFSR9_SFW288				(0x1u<<0)

#define	BSEC_SFSR9_SFW319_B_0X0			(0x0u<<31)
#define	BSEC_SFSR9_SFW319_B_0X1			(0x1u<<31)
#define	BSEC_SFSR9_SFW318_B_0X0			(0x0u<<30)
#define	BSEC_SFSR9_SFW318_B_0X1			(0x1u<<30)
#define	BSEC_SFSR9_SFW317_B_0X0			(0x0u<<29)
#define	BSEC_SFSR9_SFW317_B_0X1			(0x1u<<29)
#define	BSEC_SFSR9_SFW316_B_0X0			(0x0u<<28)
#define	BSEC_SFSR9_SFW316_B_0X1			(0x1u<<28)
#define	BSEC_SFSR9_SFW315_B_0X0			(0x0u<<27)
#define	BSEC_SFSR9_SFW315_B_0X1			(0x1u<<27)
#define	BSEC_SFSR9_SFW314_B_0X0			(0x0u<<26)
#define	BSEC_SFSR9_SFW314_B_0X1			(0x1u<<26)
#define	BSEC_SFSR9_SFW313_B_0X0			(0x0u<<25)
#define	BSEC_SFSR9_SFW313_B_0X1			(0x1u<<25)
#define	BSEC_SFSR9_SFW312_B_0X0			(0x0u<<24)
#define	BSEC_SFSR9_SFW312_B_0X1			(0x1u<<24)
#define	BSEC_SFSR9_SFW311_B_0X0			(0x0u<<23)
#define	BSEC_SFSR9_SFW311_B_0X1			(0x1u<<23)
#define	BSEC_SFSR9_SFW310_B_0X0			(0x0u<<22)
#define	BSEC_SFSR9_SFW310_B_0X1			(0x1u<<22)
#define	BSEC_SFSR9_SFW309_B_0X0			(0x0u<<21)
#define	BSEC_SFSR9_SFW309_B_0X1			(0x1u<<21)
#define	BSEC_SFSR9_SFW308_B_0X0			(0x0u<<20)
#define	BSEC_SFSR9_SFW308_B_0X1			(0x1u<<20)
#define	BSEC_SFSR9_SFW307_B_0X0			(0x0u<<19)
#define	BSEC_SFSR9_SFW307_B_0X1			(0x1u<<19)
#define	BSEC_SFSR9_SFW306_B_0X0			(0x0u<<18)
#define	BSEC_SFSR9_SFW306_B_0X1			(0x1u<<18)
#define	BSEC_SFSR9_SFW305_B_0X0			(0x0u<<17)
#define	BSEC_SFSR9_SFW305_B_0X1			(0x1u<<17)
#define	BSEC_SFSR9_SFW304_B_0X0			(0x0u<<16)
#define	BSEC_SFSR9_SFW304_B_0X1			(0x1u<<16)
#define	BSEC_SFSR9_SFW303_B_0X0			(0x0u<<15)
#define	BSEC_SFSR9_SFW303_B_0X1			(0x1u<<15)
#define	BSEC_SFSR9_SFW302_B_0X0			(0x0u<<14)
#define	BSEC_SFSR9_SFW302_B_0X1			(0x1u<<14)
#define	BSEC_SFSR9_SFW301_B_0X0			(0x0u<<13)
#define	BSEC_SFSR9_SFW301_B_0X1			(0x1u<<13)
#define	BSEC_SFSR9_SFW300_B_0X0			(0x0u<<12)
#define	BSEC_SFSR9_SFW300_B_0X1			(0x1u<<12)
#define	BSEC_SFSR9_SFW299_B_0X0			(0x0u<<11)
#define	BSEC_SFSR9_SFW299_B_0X1			(0x1u<<11)
#define	BSEC_SFSR9_SFW298_B_0X0			(0x0u<<10)
#define	BSEC_SFSR9_SFW298_B_0X1			(0x1u<<10)
#define	BSEC_SFSR9_SFW297_B_0X0			(0x0u<<9)
#define	BSEC_SFSR9_SFW297_B_0X1			(0x1u<<9)
#define	BSEC_SFSR9_SFW296_B_0X0			(0x0u<<8)
#define	BSEC_SFSR9_SFW296_B_0X1			(0x1u<<8)
#define	BSEC_SFSR9_SFW295_B_0X0			(0x0u<<7)
#define	BSEC_SFSR9_SFW295_B_0X1			(0x1u<<7)
#define	BSEC_SFSR9_SFW294_B_0X0			(0x0u<<6)
#define	BSEC_SFSR9_SFW294_B_0X1			(0x1u<<6)
#define	BSEC_SFSR9_SFW293_B_0X0			(0x0u<<5)
#define	BSEC_SFSR9_SFW293_B_0X1			(0x1u<<5)
#define	BSEC_SFSR9_SFW292_B_0X0			(0x0u<<4)
#define	BSEC_SFSR9_SFW292_B_0X1			(0x1u<<4)
#define	BSEC_SFSR9_SFW291_B_0X0			(0x0u<<3)
#define	BSEC_SFSR9_SFW291_B_0X1			(0x1u<<3)
#define	BSEC_SFSR9_SFW290_B_0X0			(0x0u<<2)
#define	BSEC_SFSR9_SFW290_B_0X1			(0x1u<<2)
#define	BSEC_SFSR9_SFW289_B_0X0			(0x0u<<1)
#define	BSEC_SFSR9_SFW289_B_0X1			(0x1u<<1)
#define	BSEC_SFSR9_SFW288_B_0X0			(0x0u<<0)
#define	BSEC_SFSR9_SFW288_B_0X1			(0x1u<<0)

// SFSR10 Configuration

#define	BSEC_SFSR10_SFW351				(0x1u<<31)
#define	BSEC_SFSR10_SFW350				(0x1u<<30)
#define	BSEC_SFSR10_SFW349				(0x1u<<29)
#define	BSEC_SFSR10_SFW348				(0x1u<<28)
#define	BSEC_SFSR10_SFW347				(0x1u<<27)
#define	BSEC_SFSR10_SFW346				(0x1u<<26)
#define	BSEC_SFSR10_SFW345				(0x1u<<25)
#define	BSEC_SFSR10_SFW344				(0x1u<<24)
#define	BSEC_SFSR10_SFW343				(0x1u<<23)
#define	BSEC_SFSR10_SFW342				(0x1u<<22)
#define	BSEC_SFSR10_SFW341				(0x1u<<21)
#define	BSEC_SFSR10_SFW340				(0x1u<<20)
#define	BSEC_SFSR10_SFW339				(0x1u<<19)
#define	BSEC_SFSR10_SFW338				(0x1u<<18)
#define	BSEC_SFSR10_SFW337				(0x1u<<17)
#define	BSEC_SFSR10_SFW336				(0x1u<<16)
#define	BSEC_SFSR10_SFW335				(0x1u<<15)
#define	BSEC_SFSR10_SFW334				(0x1u<<14)
#define	BSEC_SFSR10_SFW333				(0x1u<<13)
#define	BSEC_SFSR10_SFW332				(0x1u<<12)
#define	BSEC_SFSR10_SFW331				(0x1u<<11)
#define	BSEC_SFSR10_SFW330				(0x1u<<10)
#define	BSEC_SFSR10_SFW329				(0x1u<<9)
#define	BSEC_SFSR10_SFW328				(0x1u<<8)
#define	BSEC_SFSR10_SFW327				(0x1u<<7)
#define	BSEC_SFSR10_SFW326				(0x1u<<6)
#define	BSEC_SFSR10_SFW325				(0x1u<<5)
#define	BSEC_SFSR10_SFW324				(0x1u<<4)
#define	BSEC_SFSR10_SFW323				(0x1u<<3)
#define	BSEC_SFSR10_SFW322				(0x1u<<2)
#define	BSEC_SFSR10_SFW321				(0x1u<<1)
#define	BSEC_SFSR10_SFW320				(0x1u<<0)

#define	BSEC_SFSR10_SFW351_B_0X0		(0x0u<<31)
#define	BSEC_SFSR10_SFW351_B_0X1		(0x1u<<31)
#define	BSEC_SFSR10_SFW350_B_0X0		(0x0u<<30)
#define	BSEC_SFSR10_SFW350_B_0X1		(0x1u<<30)
#define	BSEC_SFSR10_SFW349_B_0X0		(0x0u<<29)
#define	BSEC_SFSR10_SFW349_B_0X1		(0x1u<<29)
#define	BSEC_SFSR10_SFW348_B_0X0		(0x0u<<28)
#define	BSEC_SFSR10_SFW348_B_0X1		(0x1u<<28)
#define	BSEC_SFSR10_SFW347_B_0X0		(0x0u<<27)
#define	BSEC_SFSR10_SFW347_B_0X1		(0x1u<<27)
#define	BSEC_SFSR10_SFW346_B_0X0		(0x0u<<26)
#define	BSEC_SFSR10_SFW346_B_0X1		(0x1u<<26)
#define	BSEC_SFSR10_SFW345_B_0X0		(0x0u<<25)
#define	BSEC_SFSR10_SFW345_B_0X1		(0x1u<<25)
#define	BSEC_SFSR10_SFW344_B_0X0		(0x0u<<24)
#define	BSEC_SFSR10_SFW344_B_0X1		(0x1u<<24)
#define	BSEC_SFSR10_SFW343_B_0X0		(0x0u<<23)
#define	BSEC_SFSR10_SFW343_B_0X1		(0x1u<<23)
#define	BSEC_SFSR10_SFW342_B_0X0		(0x0u<<22)
#define	BSEC_SFSR10_SFW342_B_0X1		(0x1u<<22)
#define	BSEC_SFSR10_SFW341_B_0X0		(0x0u<<21)
#define	BSEC_SFSR10_SFW341_B_0X1		(0x1u<<21)
#define	BSEC_SFSR10_SFW340_B_0X0		(0x0u<<20)
#define	BSEC_SFSR10_SFW340_B_0X1		(0x1u<<20)
#define	BSEC_SFSR10_SFW339_B_0X0		(0x0u<<19)
#define	BSEC_SFSR10_SFW339_B_0X1		(0x1u<<19)
#define	BSEC_SFSR10_SFW338_B_0X0		(0x0u<<18)
#define	BSEC_SFSR10_SFW338_B_0X1		(0x1u<<18)
#define	BSEC_SFSR10_SFW337_B_0X0		(0x0u<<17)
#define	BSEC_SFSR10_SFW337_B_0X1		(0x1u<<17)
#define	BSEC_SFSR10_SFW336_B_0X0		(0x0u<<16)
#define	BSEC_SFSR10_SFW336_B_0X1		(0x1u<<16)
#define	BSEC_SFSR10_SFW335_B_0X0		(0x0u<<15)
#define	BSEC_SFSR10_SFW335_B_0X1		(0x1u<<15)
#define	BSEC_SFSR10_SFW334_B_0X0		(0x0u<<14)
#define	BSEC_SFSR10_SFW334_B_0X1		(0x1u<<14)
#define	BSEC_SFSR10_SFW333_B_0X0		(0x0u<<13)
#define	BSEC_SFSR10_SFW333_B_0X1		(0x1u<<13)
#define	BSEC_SFSR10_SFW332_B_0X0		(0x0u<<12)
#define	BSEC_SFSR10_SFW332_B_0X1		(0x1u<<12)
#define	BSEC_SFSR10_SFW331_B_0X0		(0x0u<<11)
#define	BSEC_SFSR10_SFW331_B_0X1		(0x1u<<11)
#define	BSEC_SFSR10_SFW330_B_0X0		(0x0u<<10)
#define	BSEC_SFSR10_SFW330_B_0X1		(0x1u<<10)
#define	BSEC_SFSR10_SFW329_B_0X0		(0x0u<<9)
#define	BSEC_SFSR10_SFW329_B_0X1		(0x1u<<9)
#define	BSEC_SFSR10_SFW328_B_0X0		(0x0u<<8)
#define	BSEC_SFSR10_SFW328_B_0X1		(0x1u<<8)
#define	BSEC_SFSR10_SFW327_B_0X0		(0x0u<<7)
#define	BSEC_SFSR10_SFW327_B_0X1		(0x1u<<7)
#define	BSEC_SFSR10_SFW326_B_0X0		(0x0u<<6)
#define	BSEC_SFSR10_SFW326_B_0X1		(0x1u<<6)
#define	BSEC_SFSR10_SFW325_B_0X0		(0x0u<<5)
#define	BSEC_SFSR10_SFW325_B_0X1		(0x1u<<5)
#define	BSEC_SFSR10_SFW324_B_0X0		(0x0u<<4)
#define	BSEC_SFSR10_SFW324_B_0X1		(0x1u<<4)
#define	BSEC_SFSR10_SFW323_B_0X0		(0x0u<<3)
#define	BSEC_SFSR10_SFW323_B_0X1		(0x1u<<3)
#define	BSEC_SFSR10_SFW322_B_0X0		(0x0u<<2)
#define	BSEC_SFSR10_SFW322_B_0X1		(0x1u<<2)
#define	BSEC_SFSR10_SFW321_B_0X0		(0x0u<<1)
#define	BSEC_SFSR10_SFW321_B_0X1		(0x1u<<1)
#define	BSEC_SFSR10_SFW320_B_0X0		(0x0u<<0)
#define	BSEC_SFSR10_SFW320_B_0X1		(0x1u<<0)

// SFSR11 Configuration

#define	BSEC_SFSR11_SFW383				(0x1u<<31)
#define	BSEC_SFSR11_SFW382				(0x1u<<30)
#define	BSEC_SFSR11_SFW381				(0x1u<<29)
#define	BSEC_SFSR11_SFW380				(0x1u<<28)
#define	BSEC_SFSR11_SFW379				(0x1u<<27)
#define	BSEC_SFSR11_SFW378				(0x1u<<26)
#define	BSEC_SFSR11_SFW377				(0x1u<<25)
#define	BSEC_SFSR11_SFW376				(0x1u<<24)
#define	BSEC_SFSR11_SFW375				(0x1u<<23)
#define	BSEC_SFSR11_SFW374				(0x1u<<22)
#define	BSEC_SFSR11_SFW373				(0x1u<<21)
#define	BSEC_SFSR11_SFW372				(0x1u<<20)
#define	BSEC_SFSR11_SFW371				(0x1u<<19)
#define	BSEC_SFSR11_SFW370				(0x1u<<18)
#define	BSEC_SFSR11_SFW369				(0x1u<<17)
#define	BSEC_SFSR11_SFW368				(0x1u<<16)
#define	BSEC_SFSR11_SFW367				(0x1u<<15)
#define	BSEC_SFSR11_SFW366				(0x1u<<14)
#define	BSEC_SFSR11_SFW365				(0x1u<<13)
#define	BSEC_SFSR11_SFW364				(0x1u<<12)
#define	BSEC_SFSR11_SFW363				(0x1u<<11)
#define	BSEC_SFSR11_SFW362				(0x1u<<10)
#define	BSEC_SFSR11_SFW361				(0x1u<<9)
#define	BSEC_SFSR11_SFW360				(0x1u<<8)
#define	BSEC_SFSR11_SFW359				(0x1u<<7)
#define	BSEC_SFSR11_SFW358				(0x1u<<6)
#define	BSEC_SFSR11_SFW357				(0x1u<<5)
#define	BSEC_SFSR11_SFW356				(0x1u<<4)
#define	BSEC_SFSR11_SFW355				(0x1u<<3)
#define	BSEC_SFSR11_SFW354				(0x1u<<2)
#define	BSEC_SFSR11_SFW353				(0x1u<<1)
#define	BSEC_SFSR11_SFW352				(0x1u<<0)

#define	BSEC_SFSR11_SFW383_B_0X0		(0x0u<<31)
#define	BSEC_SFSR11_SFW383_B_0X1		(0x1u<<31)
#define	BSEC_SFSR11_SFW382_B_0X0		(0x0u<<30)
#define	BSEC_SFSR11_SFW382_B_0X1		(0x1u<<30)
#define	BSEC_SFSR11_SFW381_B_0X0		(0x0u<<29)
#define	BSEC_SFSR11_SFW381_B_0X1		(0x1u<<29)
#define	BSEC_SFSR11_SFW380_B_0X0		(0x0u<<28)
#define	BSEC_SFSR11_SFW380_B_0X1		(0x1u<<28)
#define	BSEC_SFSR11_SFW379_B_0X0		(0x0u<<27)
#define	BSEC_SFSR11_SFW379_B_0X1		(0x1u<<27)
#define	BSEC_SFSR11_SFW378_B_0X0		(0x0u<<26)
#define	BSEC_SFSR11_SFW378_B_0X1		(0x1u<<26)
#define	BSEC_SFSR11_SFW377_B_0X0		(0x0u<<25)
#define	BSEC_SFSR11_SFW377_B_0X1		(0x1u<<25)
#define	BSEC_SFSR11_SFW376_B_0X0		(0x0u<<24)
#define	BSEC_SFSR11_SFW376_B_0X1		(0x1u<<24)
#define	BSEC_SFSR11_SFW375_B_0X0		(0x0u<<23)
#define	BSEC_SFSR11_SFW375_B_0X1		(0x1u<<23)
#define	BSEC_SFSR11_SFW374_B_0X0		(0x0u<<22)
#define	BSEC_SFSR11_SFW374_B_0X1		(0x1u<<22)
#define	BSEC_SFSR11_SFW373_B_0X0		(0x0u<<21)
#define	BSEC_SFSR11_SFW373_B_0X1		(0x1u<<21)
#define	BSEC_SFSR11_SFW372_B_0X0		(0x0u<<20)
#define	BSEC_SFSR11_SFW372_B_0X1		(0x1u<<20)
#define	BSEC_SFSR11_SFW371_B_0X0		(0x0u<<19)
#define	BSEC_SFSR11_SFW371_B_0X1		(0x1u<<19)
#define	BSEC_SFSR11_SFW370_B_0X0		(0x0u<<18)
#define	BSEC_SFSR11_SFW370_B_0X1		(0x1u<<18)
#define	BSEC_SFSR11_SFW369_B_0X0		(0x0u<<17)
#define	BSEC_SFSR11_SFW369_B_0X1		(0x1u<<17)
#define	BSEC_SFSR11_SFW368_B_0X0		(0x0u<<16)
#define	BSEC_SFSR11_SFW368_B_0X1		(0x1u<<16)
#define	BSEC_SFSR11_SFW367_B_0X0		(0x0u<<15)
#define	BSEC_SFSR11_SFW367_B_0X1		(0x1u<<15)
#define	BSEC_SFSR11_SFW366_B_0X0		(0x0u<<14)
#define	BSEC_SFSR11_SFW366_B_0X1		(0x1u<<14)
#define	BSEC_SFSR11_SFW365_B_0X0		(0x0u<<13)
#define	BSEC_SFSR11_SFW365_B_0X1		(0x1u<<13)
#define	BSEC_SFSR11_SFW364_B_0X0		(0x0u<<12)
#define	BSEC_SFSR11_SFW364_B_0X1		(0x1u<<12)
#define	BSEC_SFSR11_SFW363_B_0X0		(0x0u<<11)
#define	BSEC_SFSR11_SFW363_B_0X1		(0x1u<<11)
#define	BSEC_SFSR11_SFW362_B_0X0		(0x0u<<10)
#define	BSEC_SFSR11_SFW362_B_0X1		(0x1u<<10)
#define	BSEC_SFSR11_SFW361_B_0X0		(0x0u<<9)
#define	BSEC_SFSR11_SFW361_B_0X1		(0x1u<<9)
#define	BSEC_SFSR11_SFW360_B_0X0		(0x0u<<8)
#define	BSEC_SFSR11_SFW360_B_0X1		(0x1u<<8)
#define	BSEC_SFSR11_SFW359_B_0X0		(0x0u<<7)
#define	BSEC_SFSR11_SFW359_B_0X1		(0x1u<<7)
#define	BSEC_SFSR11_SFW358_B_0X0		(0x0u<<6)
#define	BSEC_SFSR11_SFW358_B_0X1		(0x1u<<6)
#define	BSEC_SFSR11_SFW357_B_0X0		(0x0u<<5)
#define	BSEC_SFSR11_SFW357_B_0X1		(0x1u<<5)
#define	BSEC_SFSR11_SFW356_B_0X0		(0x0u<<4)
#define	BSEC_SFSR11_SFW356_B_0X1		(0x1u<<4)
#define	BSEC_SFSR11_SFW355_B_0X0		(0x0u<<3)
#define	BSEC_SFSR11_SFW355_B_0X1		(0x1u<<3)
#define	BSEC_SFSR11_SFW354_B_0X0		(0x0u<<2)
#define	BSEC_SFSR11_SFW354_B_0X1		(0x1u<<2)
#define	BSEC_SFSR11_SFW353_B_0X0		(0x0u<<1)
#define	BSEC_SFSR11_SFW353_B_0X1		(0x1u<<1)
#define	BSEC_SFSR11_SFW352_B_0X0		(0x0u<<0)
#define	BSEC_SFSR11_SFW352_B_0X1		(0x1u<<0)

// OTPCR Configuration

#define	BSEC_OTPCR_LASTCID				(0x7u<<19)
#define	BSEC_OTPCR_LASTCID_0			(0x1u<<19)
#define	BSEC_OTPCR_PPLOCK				(0x1u<<14)
#define	BSEC_OTPCR_PROG					(0x1u<<13)
#define	BSEC_OTPCR_ADDR					(0x1FFu<<0)
#define	BSEC_OTPCR_ADDR_0				(0x1u<<0)

#define	BSEC_OTPCR_PPLOCK_B_0X0			(0x0u<<14)
#define	BSEC_OTPCR_PPLOCK_B_0X1			(0x1u<<14)
#define	BSEC_OTPCR_PROG_B_0X0			(0x0u<<13)
#define	BSEC_OTPCR_PROG_B_0X1			(0x1u<<13)

// WDR Configuration

#define	BSEC_WDR_WRDATA					(0xFFFFFFFFu<<0)
#define	BSEC_WDR_WRDATA_0				(0x1u<<0)

// SCRATCHR0 Configuration

#define	BSEC_SCRATCHR0_SDATA			(0xFFFFFFFFu<<0)
#define	BSEC_SCRATCHR0_SDATA_0			(0x1u<<0)

// SCRATCHR1 Configuration

#define	BSEC_SCRATCHR1_SDATA			(0xFFFFFFFFu<<0)
#define	BSEC_SCRATCHR1_SDATA_0			(0x1u<<0)

// SCRATCHR2 Configuration

#define	BSEC_SCRATCHR2_SDATA			(0xFFFFFFFFu<<0)
#define	BSEC_SCRATCHR2_SDATA_0			(0x1u<<0)

// SCRATCHR3 Configuration

#define	BSEC_SCRATCHR3_SDATA			(0xFFFFFFFFu<<0)
#define	BSEC_SCRATCHR3_SDATA_0			(0x1u<<0)

// LOCKR Configuration

#define	BSEC_LOCKR_HKLOCK				(0x1u<<2)
#define	BSEC_LOCKR_GWLOCK				(0x1u<<0)

#define	BSEC_LOCKR_HKLOCK_B_0X0			(0x0u<<2)
#define	BSEC_LOCKR_HKLOCK_B_0X1			(0x1u<<2)
#define	BSEC_LOCKR_GWLOCK_B_0X0			(0x0u<<0)
#define	BSEC_LOCKR_GWLOCK_B_0X1			(0x1u<<0)

// JTAGINR Configuration

#define	BSEC_JTAGINR_JDATAIN			(0xFFFFFFFFu<<0)
#define	BSEC_JTAGINR_JDATAIN_0			(0x1u<<0)

// JTAGOUTR Configuration

#define	BSEC_JTAGOUTR_JDATAOUT			(0xFFFFFFFFu<<0)
#define	BSEC_JTAGOUTR_JDATAOUT_0		(0x1u<<0)

// UNMAPR Configuration

#define	BSEC_UNMAPR_UNMAP				(0xFFFFFFFFu<<0)
#define	BSEC_UNMAPR_UNMAP_0				(0x1u<<0)

// SR Configuration

#define	BSEC_SR_NVSTATE					(0x3Fu<<26)
#define	BSEC_SR_NVSTATE_0				(0x1u<<26)
#define	BSEC_SR_DBGREQ					(0x1u<<16)
#define	BSEC_SR_HVALID					(0x1u<<1)

#define	BSEC_SR_NVSTATE_B_0X16			(0x16u<<26)
#define	BSEC_SR_NVSTATE_B_0X0D			(0xDu<<26)
#define	BSEC_SR_NVSTATE_B_0X7			(0x7u<<26)
#define	BSEC_SR_NVSTATE_B_0X23			(0x23u<<26)
#define	BSEC_SR_DBGREQ_B_0X0			(0x0u<<16)
#define	BSEC_SR_DBGREQ_B_0X1			(0x1u<<16)
#define	BSEC_SR_HVALID_B_0X0			(0x0u<<1)
#define	BSEC_SR_HVALID_B_0X1			(0x1u<<1)

// OTPSR Configuration

#define	BSEC_OTPSR_AMEF					(0x1u<<22)
#define	BSEC_OTPSR_PPLMF				(0x1u<<21)
#define	BSEC_OTPSR_PPLF					(0x1u<<20)
#define	BSEC_OTPSR_SECF					(0x1u<<19)
#define	BSEC_OTPSR_DEDF					(0x1u<<18)
#define	BSEC_OTPSR_DISTURBF				(0x1u<<17)
#define	BSEC_OTPSR_PROGFAIL				(0x1u<<16)
#define	BSEC_OTPSR_OTPSEC				(0x1u<<6)
#define	BSEC_OTPSR_OTPERR				(0x1u<<5)
#define	BSEC_OTPSR_OTPNVIR				(0x1u<<4)
#define	BSEC_OTPSR_HIDEUP				(0x1u<<2)
#define	BSEC_OTPSR_INIT_DONE			(0x1u<<1)
#define	BSEC_OTPSR_BUSY					(0x1u<<0)

#define	BSEC_OTPSR_BUSY_B_0X0			(0x0u<<0)
#define	BSEC_OTPSR_BUSY_B_0X1			(0x1u<<0)

// EPOCHR0 Configuration

#define	BSEC_EPOCHR0_EPOCH				(0xFFFFFFFFu<<0)
#define	BSEC_EPOCHR0_EPOCH_0			(0x1u<<0)

// EPOCHR1 Configuration

#define	BSEC_EPOCHR1_EPOCH				(0xFFFFFFFFu<<0)
#define	BSEC_EPOCHR1_EPOCH_0			(0x1u<<0)

// EPOCH_SELR Configuration

#define	BSEC_EPOCH_SELR_EPSEL			(0x1u<<0)

#define	BSEC_EPOCH_SELR_EPSEL_B_0X0		(0x0u<<0)
#define	BSEC_EPOCH_SELR_EPSEL_B_0X1		(0x1u<<0)

// DBGCR Configuration

#define	BSEC_DBGCR_AUTH_SEC				(0xFFu<<24)
#define	BSEC_DBGCR_AUTH_SEC_0			(0x1u<<24)
#define	BSEC_DBGCR_AUTH_HDPL			(0xFFu<<16)
#define	BSEC_DBGCR_AUTH_HDPL_0			(0x1u<<16)
#define	BSEC_DBGCR_UNLOCK				(0xFFu<<8)
#define	BSEC_DBGCR_UNLOCK_0				(0x1u<<8)

#define	BSEC_DBGCR_AUTH_SEC_B_0XB4		(0xB4u<<24)
#define	BSEC_DBGCR_AUTH_HDPL_B_0XB4		(0xB4u<<16)
#define	BSEC_DBGCR_AUTH_HDPL_B_0X51		(0x51u<<16)
#define	BSEC_DBGCR_AUTH_HDPL_B_0X8A		(0x8Au<<16)
#define	BSEC_DBGCR_AUTH_HDPL_B_0X6F		(0x6Fu<<16)
#define	BSEC_DBGCR_UNLOCK_B_0XB4		(0xB4u<<8)

// AP_UNLOCK Configuration

#define	BSEC_AP_UNLOCK_UNLOCK			(0xFFu<<0)
#define	BSEC_AP_UNLOCK_UNLOCK_0			(0x1u<<0)

#define	BSEC_AP_UNLOCK_UNLOCK_B_0XB4	(0xB4u<<0)

// HDPLSR Configuration

#define	BSEC_HDPLSR_HDPL				(0xFFu<<0)
#define	BSEC_HDPLSR_HDPL_0				(0x1u<<0)

#define	BSEC_HDPLSR_HDPL_B_0XB4			(0xB4u<<0)
#define	BSEC_HDPLSR_HDPL_B_0X51			(0x51u<<0)
#define	BSEC_HDPLSR_HDPL_B_0X8A			(0x8Au<<0)
#define	BSEC_HDPLSR_HDPL_B_0X6F			(0x6Fu<<0)

// HDPLCR Configuration

#define	BSEC_HDPLCR_INCR_HDPL			(0xFFFFFFFFu<<0)
#define	BSEC_HDPLCR_INCR_HDPL_0			(0x1u<<0)

// NEXTLR Configuration

#define	BSEC_NEXTLR_INCR				(0x3u<<0)
#define	BSEC_NEXTLR_INCR_0				(0x1u<<0)

// WOSCR0 Configuration

#define	BSEC_WOSCR0_WOSDATA				(0xFFFFFFFFu<<0)
#define	BSEC_WOSCR0_WOSDATA_0			(0x1u<<0)

// WOSCR1 Configuration

#define	BSEC_WOSCR1_WOSDATA				(0xFFFFFFFFu<<0)
#define	BSEC_WOSCR1_WOSDATA_0			(0x1u<<0)

// WOSCR2 Configuration

#define	BSEC_WOSCR2_WOSDATA				(0xFFFFFFFFu<<0)
#define	BSEC_WOSCR2_WOSDATA_0			(0x1u<<0)

// WOSCR3 Configuration

#define	BSEC_WOSCR3_WOSDATA				(0xFFFFFFFFu<<0)
#define	BSEC_WOSCR3_WOSDATA_0			(0x1u<<0)

// WOSCR4 Configuration

#define	BSEC_WOSCR4_WOSDATA				(0xFFFFFFFFu<<0)
#define	BSEC_WOSCR4_WOSDATA_0			(0x1u<<0)

// WOSCR5 Configuration

#define	BSEC_WOSCR5_WOSDATA				(0xFFFFFFFFu<<0)
#define	BSEC_WOSCR5_WOSDATA_0			(0x1u<<0)

// WOSCR6 Configuration

#define	BSEC_WOSCR6_WOSDATA				(0xFFFFFFFFu<<0)
#define	BSEC_WOSCR6_WOSDATA_0			(0x1u<<0)

// WOSCR7 Configuration

#define	BSEC_WOSCR7_WOSDATA				(0xFFFFFFFFu<<0)
#define	BSEC_WOSCR7_WOSDATA_0			(0x1u<<0)

// HRCR Configuration

#define	BSEC_HRCR_HRC					(0xFFFFFFFFu<<0)
#define	BSEC_HRCR_HRC_0					(0x1u<<0)

// WRCR Configuration

#define	BSEC_WRCR_WRC					(0xFFFFFFFFu<<0)
#define	BSEC_WRCR_WRC_0					(0x1u<<0)
