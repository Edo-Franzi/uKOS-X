/*
; stm32N657_venc.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_venc equates.
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

// VENC address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	SWREG0;
	volatile	uint32_t	SWREG1;
	volatile	uint32_t	SWREG2;
	volatile	uint32_t	SWREG3;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	SWREG5;
	volatile	uint32_t	SWREG6;
	volatile	uint32_t	SWREG7;
	volatile	uint32_t	SWREG8;
	volatile	uint32_t	SWREG9;
	volatile	uint32_t	SWREG10;
	volatile	uint32_t	SWREG11;
	volatile	uint32_t	SWREG12;
	volatile	uint32_t	SWREG13;
	volatile	uint32_t	SWREG14;
	volatile	uint32_t	SWREG15;
	volatile	uint32_t	SWREG16;
	volatile	uint32_t	SWREG17;
	volatile	uint32_t	SWREG18;
	volatile	uint32_t	SWREG19;
	volatile	uint32_t	SWREG20;
	volatile	uint32_t	SWREG21;
	volatile	uint32_t	SWREG22;
	volatile	uint32_t	SWREG23;
	volatile	uint32_t	SWREG24;
	volatile	uint32_t	SWREG25;
	volatile	uint32_t	SWREG26;
	volatile	uint32_t	SWREG27;
	volatile	uint32_t	SWREG28;
	volatile	uint32_t	SWREG29;
	volatile	uint32_t	SWREG30;
	volatile	uint32_t	SWREG31;
	volatile	uint32_t	SWREG32;
	volatile	uint32_t	SWREG33;
	volatile	uint32_t	SWREG34;
	volatile	uint32_t	SWREG35;
	volatile	uint32_t	SWREG36;
	volatile	uint32_t	SWREG37;
	volatile	uint32_t	SWREG38;
	volatile	uint32_t	SWREG39;
	volatile	uint32_t	SWREG40;
	volatile	uint32_t	SWREG41;
	volatile	uint32_t	SWREG42;
	volatile	uint32_t	SWREG43;
	volatile	uint32_t	SWREG44;
	volatile	uint32_t	SWREG45;
	volatile	uint32_t	SWREG46;
	volatile	uint32_t	SWREG47;
	volatile	uint32_t	SWREG48;
	volatile	uint32_t	SWREG49;
	volatile	uint32_t	SWREG50;
	volatile	uint32_t	SWREG51;
	volatile	uint32_t	SWREG52;
	volatile	uint32_t	SWREG53;
	volatile	uint32_t	SWREG54;
	volatile	uint32_t	SWREG55;
	volatile	uint32_t	SWREG56;
	volatile	uint32_t	SWREG57;
	volatile	uint32_t	SWREG58;
	volatile	uint32_t	SWREG59;
	volatile	uint32_t	SWREG60;
	volatile	uint32_t	SWREG61;
	volatile	uint32_t	SWREG62;
	volatile	uint32_t	SWREG63;
	volatile	uint32_t	SWREG64;
	volatile	uint32_t	SWREG65;
	volatile	uint32_t	SWREG66;
	volatile	uint32_t	SWREG67;
	volatile	uint32_t	SWREG68;
	volatile	uint32_t	SWREG69;
	volatile	uint32_t	SWREG70;
	volatile	uint32_t	SWREG71;
	volatile	uint32_t	SWREG72;
	volatile	uint32_t	SWREG73;
	volatile	uint32_t	SWREG74;
	volatile	uint32_t	SWREG75;
	volatile	uint32_t	SWREG76;
	volatile	uint32_t	SWREG77;
	volatile	uint32_t	SWREG78;
	volatile	uint32_t	SWREG79;
	volatile	uint32_t	SWREG80;
	volatile	uint32_t	SWREG81;
	volatile	uint32_t	SWREG82;
	volatile	uint32_t	SWREG83;
	volatile	uint32_t	SWREG84;
	volatile	uint32_t	SWREG85;
	volatile	uint32_t	SWREG86;
	volatile	uint32_t	SWREG87;
	volatile	uint32_t	SWREG88;
	volatile	uint32_t	SWREG89;
	volatile	uint32_t	SWREG90;
	volatile	uint32_t	SWREG91;
	volatile	uint32_t	SWREG92;
	volatile	uint32_t	SWREG93;
	volatile	uint32_t	SWREG94;
	volatile	uint32_t	SWREG95;
	volatile	uint32_t	SWREG96;
	volatile	uint32_t	SWREG97;
	volatile	uint32_t	SWREG98;
	volatile	uint32_t	SWREG99;
	volatile	uint32_t	SWREG100;
	volatile	uint32_t	SWREG101;
	volatile	uint32_t	SWREG102;
	volatile	uint32_t	SWREG103;
	volatile	uint32_t	SWREG104;
	volatile	uint32_t	SWREG105;
	volatile	uint32_t	SWREG106;
	volatile	uint32_t	SWREG107;
	volatile	uint32_t	SWREG108;
	volatile	uint32_t	SWREG109;
	volatile	uint32_t	SWREG110;
	volatile	uint32_t	SWREG111;
	volatile	uint32_t	SWREG112;
	volatile	uint32_t	SWREG113;
	volatile	uint32_t	SWREG114;
	volatile	uint32_t	SWREG115;
	volatile	uint32_t	SWREG116;
	volatile	uint32_t	SWREG117;
	volatile	uint32_t	SWREG118;
	volatile	uint32_t	SWREG119;
	volatile	uint32_t	SWREG120;
	volatile	uint32_t	SWREG121;
	volatile	uint32_t	SWREG122;
	volatile	uint32_t	SWREG123;
	volatile	uint32_t	SWREG124;
	volatile	uint32_t	SWREG125;
	volatile	uint32_t	SWREG126;
	volatile	uint32_t	SWREG127;
	volatile	uint32_t	SWREG128;
	volatile	uint32_t	SWREG129;
	volatile	uint32_t	SWREG130;
	volatile	uint32_t	SWREG131;
	volatile	uint32_t	SWREG132;
	volatile	uint32_t	SWREG133;
	volatile	uint32_t	SWREG134;
	volatile	uint32_t	SWREG135;
	volatile	uint32_t	SWREG136;
	volatile	uint32_t	SWREG137;
	volatile	uint32_t	SWREG138;
	volatile	uint32_t	SWREG139;
	volatile	uint32_t	SWREG140;
	volatile	uint32_t	SWREG141;
	volatile	uint32_t	SWREG142;
	volatile	uint32_t	SWREG143;
	volatile	uint32_t	SWREG144;
	volatile	uint32_t	SWREG145;
	volatile	uint32_t	SWREG146;
	volatile	uint32_t	SWREG147;
	volatile	uint32_t	SWREG148;
	volatile	uint32_t	SWREG149;
	volatile	uint32_t	SWREG150;
	volatile	uint32_t	SWREG151;
	volatile	uint32_t	SWREG152;
	volatile	uint32_t	SWREG153;
	volatile	uint32_t	SWREG154;
	volatile	uint32_t	SWREG155;
	volatile	uint32_t	SWREG156;
	volatile	uint32_t	SWREG157;
	volatile	uint32_t	SWREG158;
	volatile	uint32_t	SWREG159;
	volatile	uint32_t	RESERVED1[71];
	volatile	uint32_t	SWREG231;
	volatile	uint32_t	SWREG232;
	volatile	uint32_t	SWREG233;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	SWREG236;
	volatile	uint32_t	SWREG237;
	volatile	uint32_t	SWREG238;
	volatile	uint32_t	RESERVED3[17];
	volatile	uint32_t	SWREG256;
	volatile	uint32_t	SWREG257;
	volatile	uint32_t	SWREG258;
	volatile	uint32_t	SWREG259;
	volatile	uint32_t	SWREG260;
	volatile	uint32_t	SWREG261;
	volatile	uint32_t	SWREG262;
	volatile	uint32_t	SWREG263;
	volatile	uint32_t	SWREG264;
	volatile	uint32_t	SWREG265;
	volatile	uint32_t	SWREG266;
	volatile	uint32_t	SWREG267;
	volatile	uint32_t	SWREG268;
	volatile	uint32_t	SWREG269;
	volatile	uint32_t	SWREG270;
	volatile	uint32_t	SWREG271;
	volatile	uint32_t	SWREG272;
	volatile	uint32_t	SWREG273;
	volatile	uint32_t	SWREG274;
	volatile	uint32_t	SWREG275;
	volatile	uint32_t	SWREG276;
	volatile	uint32_t	SWREG277;
	volatile	uint32_t	SWREG278;
	volatile	uint32_t	SWREG279;
	volatile	uint32_t	SWREG280;
	volatile	uint32_t	SWREG281;
	volatile	uint32_t	SWREG282;
	volatile	uint32_t	SWREG283;
	volatile	uint32_t	SWREG284;
	volatile	uint32_t	SWREG285;
	volatile	uint32_t	SWREG286;
	volatile	uint32_t	SWREG287;
	volatile	uint32_t	SWREG288;
	volatile	uint32_t	SWREG289;
	volatile	uint32_t	SWREG290;
	volatile	uint32_t	SWREG291;
	volatile	uint32_t	RESERVED4[2];
	volatile	uint32_t	SWREG294;
	volatile	uint32_t	SWREG295;
	volatile	uint32_t	SWREG296;
	volatile	uint32_t	SWREG297;
	volatile	uint32_t	SWREG298;
	volatile	uint32_t	SWREG299;
	volatile	uint32_t	SWREG300;
	volatile	uint32_t	SWREG301;
	volatile	uint32_t	SWREG302;
	volatile	uint32_t	SWREG303;
	volatile	uint32_t	SWREG304;
	volatile	uint32_t	SWREG305;
	volatile	uint32_t	SWREG306;
	volatile	uint32_t	SWREG307;
	volatile	uint32_t	SWREG308;
	volatile	uint32_t	SWREG309;
	volatile	uint32_t	SWREG310;
	volatile	uint32_t	SWREG311;
	volatile	uint32_t	SWREG312;
	volatile	uint32_t	SWREG313;
	volatile	uint32_t	SWREG314;
	volatile	uint32_t	SWREG315;
	volatile	uint32_t	SWREG316;
	volatile	uint32_t	SWREG317;
	volatile	uint32_t	SWREG318;
	volatile	uint32_t	SWREG319;
	volatile	uint32_t	SWREG320;
	volatile	uint32_t	SWREG321;
	volatile	uint32_t	SWREG322;
	volatile	uint32_t	SWREG323;
	volatile	uint32_t	SWREG324;
	volatile	uint32_t	SWREG325;
	volatile	uint32_t	SWREG326;
	volatile	uint32_t	SWREG327;
	volatile	uint32_t	SWREG328;
	volatile	uint32_t	SWREG329;
	volatile	uint32_t	SWREG330;
	volatile	uint32_t	SWREG331;
	volatile	uint32_t	SWREG332;
	volatile	uint32_t	SWREG333;
	volatile	uint32_t	SWREG334;
	volatile	uint32_t	SWREG335;
	volatile	uint32_t	SWREG336;
	volatile	uint32_t	SWREG337;
	volatile	uint32_t	SWREG338;
	volatile	uint32_t	SWREG339;
	volatile	uint32_t	SWREG340;
	volatile	uint32_t	SWREG341;
	volatile	uint32_t	SWREG342;
	volatile	uint32_t	SWREG343;
	volatile	uint32_t	SWREG344;
	volatile	uint32_t	SWREG345;
	volatile	uint32_t	SWREG346;
	volatile	uint32_t	SWREG347;
	volatile	uint32_t	SWREG348;
	volatile	uint32_t	SWREG349;
	volatile	uint32_t	SWREG350;
	volatile	uint32_t	SWREG351;
	volatile	uint32_t	SWREG352;
	volatile	uint32_t	SWREG353;
	volatile	uint32_t	SWREG354;
	volatile	uint32_t	SWREG355;
	volatile	uint32_t	SWREG356;
	volatile	uint32_t	SWREG357;
	volatile	uint32_t	SWREG358;
	volatile	uint32_t	SWREG359;
	volatile	uint32_t	SWREG360;
	volatile	uint32_t	SWREG361;
	volatile	uint32_t	SWREG362;
	volatile	uint32_t	SWREG363;
	volatile	uint32_t	SWREG364;
	volatile	uint32_t	SWREG365;
	volatile	uint32_t	SWREG366;
	volatile	uint32_t	SWREG367;
	volatile	uint32_t	SWREG368;
	volatile	uint32_t	SWREG369;
	volatile	uint32_t	SWREG370;
	volatile	uint32_t	SWREG371;
	volatile	uint32_t	SWREG372;
	volatile	uint32_t	SWREG373;
	volatile	uint32_t	SWREG374;
	volatile	uint32_t	SWREG375;
	volatile	uint32_t	SWREG376;
	volatile	uint32_t	SWREG377;
	volatile	uint32_t	SWREG378;
	volatile	uint32_t	SWREG379;
	volatile	uint32_t	SWREG380;
	volatile	uint32_t	SWREG381;
	volatile	uint32_t	SWREG382;
	volatile	uint32_t	SWREG383;
	volatile	uint32_t	SWREG384;
	volatile	uint32_t	SWREG385;
	volatile	uint32_t	SWREG386;
	volatile	uint32_t	SWREG387;
	volatile	uint32_t	SWREG388;
	volatile	uint32_t	SWREG389;
	volatile	uint32_t	SWREG390;
	volatile	uint32_t	SWREG391;
	volatile	uint32_t	SWREG392;
	volatile	uint32_t	SWREG393;
	volatile	uint32_t	SWREG394;
	volatile	uint32_t	SWREG395;
	volatile	uint32_t	SWREG396;
	volatile	uint32_t	SWREG397;
	volatile	uint32_t	SWREG398;
	volatile	uint32_t	SWREG399;
	volatile	uint32_t	SWREG400;
	volatile	uint32_t	SWREG401;
	volatile	uint32_t	SWREG402;
	volatile	uint32_t	SWREG403;
	volatile	uint32_t	SWREG404;
	volatile	uint32_t	SWREG405;
	volatile	uint32_t	SWREG406;
	volatile	uint32_t	SWREG407;
	volatile	uint32_t	SWREG408;
	volatile	uint32_t	SWREG409;
	volatile	uint32_t	SWREG410;
	volatile	uint32_t	SWREG411;
	volatile	uint32_t	SWREG412;
	volatile	uint32_t	SWREG413;
	volatile	uint32_t	SWREG414;
	volatile	uint32_t	SWREG415;
	volatile	uint32_t	SWREG416;
	volatile	uint32_t	SWREG417;
	volatile	uint32_t	SWREG418;
	volatile	uint32_t	SWREG419;
	volatile	uint32_t	SWREG420;
	volatile	uint32_t	SWREG421;
	volatile	uint32_t	SWREG422;
	volatile	uint32_t	SWREG423;
	volatile	uint32_t	SWREG424;
	volatile	uint32_t	SWREG425;
	volatile	uint32_t	SWREG426;
	volatile	uint32_t	SWREG427;
	volatile	uint32_t	SWREG428;
	volatile	uint32_t	SWREG429;
	volatile	uint32_t	SWREG430;
	volatile	uint32_t	SWREG431;
	volatile	uint32_t	SWREG432;
	volatile	uint32_t	SWREG433;
	volatile	uint32_t	SWREG434;
	volatile	uint32_t	SWREG435;
	volatile	uint32_t	SWREG436;
	volatile	uint32_t	SWREG437;
	volatile	uint32_t	SWREG438;
	volatile	uint32_t	SWREG439;
	volatile	uint32_t	SWREG440;
	volatile	uint32_t	SWREG441;
	volatile	uint32_t	SWREG442;
	volatile	uint32_t	SWREG443;
	volatile	uint32_t	SWREG444;
	volatile	uint32_t	RESERVED5[4];
	volatile	uint32_t	SWREG449;
	volatile	uint32_t	RESERVED6[47];
	volatile	uint32_t	SWREG497;
	volatile	uint32_t	SWREG498;
} VENC_TypeDef;

#if (defined(__cplusplus))
#define	VENC_NS	reinterpret_cast<VENC_TypeDef *>(0x48005000u)
#define	VENC_S	reinterpret_cast<VENC_TypeDef *>(0x58005000u)

#else
#define	VENC_NS	((VENC_TypeDef *)0x48005000u)
#define	VENC_S	((VENC_TypeDef *)0x58005000u)
#endif

// SWREG0 Configuration

#define	VENC_SWREG0_SWREG_FIELD		(0xFFFFFFFFu<<0)
#define	VENC_SWREG0_SWREG_FIELD_0	(0x1u<<0)

// SWREG1 Configuration

#define	VENC_SWREG1_SWREG_FIELD		(0xFFFFFFFFu<<0)
#define	VENC_SWREG1_SWREG_FIELD_0	(0x1u<<0)

// SWREG2 Configuration

#define	VENC_SWREG2_SWREG_FIELD		(0xFFFFFFFFu<<0)
#define	VENC_SWREG2_SWREG_FIELD_0	(0x1u<<0)

// SWREG3 Configuration

#define	VENC_SWREG3_SWREG_FIELD		(0xFFFFFFFFu<<0)
#define	VENC_SWREG3_SWREG_FIELD_0	(0x1u<<0)

// SWREG5 Configuration

#define	VENC_SWREG5_SWREG_FIELD		(0xFFFFFFFFu<<0)
#define	VENC_SWREG5_SWREG_FIELD_0	(0x1u<<0)

// SWREG6 Configuration

#define	VENC_SWREG6_SWREG_FIELD		(0xFFFFFFFFu<<0)
#define	VENC_SWREG6_SWREG_FIELD_0	(0x1u<<0)

// SWREG7 Configuration

#define	VENC_SWREG7_SWREG_FIELD		(0xFFFFFFFFu<<0)
#define	VENC_SWREG7_SWREG_FIELD_0	(0x1u<<0)

// SWREG8 Configuration

#define	VENC_SWREG8_SWREG_FIELD		(0xFFFFFFFFu<<0)
#define	VENC_SWREG8_SWREG_FIELD_0	(0x1u<<0)

// SWREG9 Configuration

#define	VENC_SWREG9_SWREG_FIELD		(0xFFFFFFFFu<<0)
#define	VENC_SWREG9_SWREG_FIELD_0	(0x1u<<0)

// SWREG10 Configuration

#define	VENC_SWREG10_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG10_SWREG_FIELD_0	(0x1u<<0)

// SWREG11 Configuration

#define	VENC_SWREG11_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG11_SWREG_FIELD_0	(0x1u<<0)

// SWREG12 Configuration

#define	VENC_SWREG12_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG12_SWREG_FIELD_0	(0x1u<<0)

// SWREG13 Configuration

#define	VENC_SWREG13_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG13_SWREG_FIELD_0	(0x1u<<0)

// SWREG14 Configuration

#define	VENC_SWREG14_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG14_SWREG_FIELD_0	(0x1u<<0)

// SWREG15 Configuration

#define	VENC_SWREG15_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG15_SWREG_FIELD_0	(0x1u<<0)

// SWREG16 Configuration

#define	VENC_SWREG16_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG16_SWREG_FIELD_0	(0x1u<<0)

// SWREG17 Configuration

#define	VENC_SWREG17_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG17_SWREG_FIELD_0	(0x1u<<0)

// SWREG18 Configuration

#define	VENC_SWREG18_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG18_SWREG_FIELD_0	(0x1u<<0)

// SWREG19 Configuration

#define	VENC_SWREG19_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG19_SWREG_FIELD_0	(0x1u<<0)

// SWREG20 Configuration

#define	VENC_SWREG20_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG20_SWREG_FIELD_0	(0x1u<<0)

// SWREG21 Configuration

#define	VENC_SWREG21_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG21_SWREG_FIELD_0	(0x1u<<0)

// SWREG22 Configuration

#define	VENC_SWREG22_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG22_SWREG_FIELD_0	(0x1u<<0)

// SWREG23 Configuration

#define	VENC_SWREG23_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG23_SWREG_FIELD_0	(0x1u<<0)

// SWREG24 Configuration

#define	VENC_SWREG24_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG24_SWREG_FIELD_0	(0x1u<<0)

// SWREG25 Configuration

#define	VENC_SWREG25_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG25_SWREG_FIELD_0	(0x1u<<0)

// SWREG26 Configuration

#define	VENC_SWREG26_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG26_SWREG_FIELD_0	(0x1u<<0)

// SWREG27 Configuration

#define	VENC_SWREG27_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG27_SWREG_FIELD_0	(0x1u<<0)

// SWREG28 Configuration

#define	VENC_SWREG28_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG28_SWREG_FIELD_0	(0x1u<<0)

// SWREG29 Configuration

#define	VENC_SWREG29_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG29_SWREG_FIELD_0	(0x1u<<0)

// SWREG30 Configuration

#define	VENC_SWREG30_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG30_SWREG_FIELD_0	(0x1u<<0)

// SWREG31 Configuration

#define	VENC_SWREG31_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG31_SWREG_FIELD_0	(0x1u<<0)

// SWREG32 Configuration

#define	VENC_SWREG32_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG32_SWREG_FIELD_0	(0x1u<<0)

// SWREG33 Configuration

#define	VENC_SWREG33_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG33_SWREG_FIELD_0	(0x1u<<0)

// SWREG34 Configuration

#define	VENC_SWREG34_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG34_SWREG_FIELD_0	(0x1u<<0)

// SWREG35 Configuration

#define	VENC_SWREG35_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG35_SWREG_FIELD_0	(0x1u<<0)

// SWREG36 Configuration

#define	VENC_SWREG36_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG36_SWREG_FIELD_0	(0x1u<<0)

// SWREG37 Configuration

#define	VENC_SWREG37_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG37_SWREG_FIELD_0	(0x1u<<0)

// SWREG38 Configuration

#define	VENC_SWREG38_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG38_SWREG_FIELD_0	(0x1u<<0)

// SWREG39 Configuration

#define	VENC_SWREG39_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG39_SWREG_FIELD_0	(0x1u<<0)

// SWREG40 Configuration

#define	VENC_SWREG40_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG40_SWREG_FIELD_0	(0x1u<<0)

// SWREG41 Configuration

#define	VENC_SWREG41_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG41_SWREG_FIELD_0	(0x1u<<0)

// SWREG42 Configuration

#define	VENC_SWREG42_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG42_SWREG_FIELD_0	(0x1u<<0)

// SWREG43 Configuration

#define	VENC_SWREG43_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG43_SWREG_FIELD_0	(0x1u<<0)

// SWREG44 Configuration

#define	VENC_SWREG44_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG44_SWREG_FIELD_0	(0x1u<<0)

// SWREG45 Configuration

#define	VENC_SWREG45_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG45_SWREG_FIELD_0	(0x1u<<0)

// SWREG46 Configuration

#define	VENC_SWREG46_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG46_SWREG_FIELD_0	(0x1u<<0)

// SWREG47 Configuration

#define	VENC_SWREG47_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG47_SWREG_FIELD_0	(0x1u<<0)

// SWREG48 Configuration

#define	VENC_SWREG48_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG48_SWREG_FIELD_0	(0x1u<<0)

// SWREG49 Configuration

#define	VENC_SWREG49_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG49_SWREG_FIELD_0	(0x1u<<0)

// SWREG50 Configuration

#define	VENC_SWREG50_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG50_SWREG_FIELD_0	(0x1u<<0)

// SWREG51 Configuration

#define	VENC_SWREG51_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG51_SWREG_FIELD_0	(0x1u<<0)

// SWREG52 Configuration

#define	VENC_SWREG52_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG52_SWREG_FIELD_0	(0x1u<<0)

// SWREG53 Configuration

#define	VENC_SWREG53_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG53_SWREG_FIELD_0	(0x1u<<0)

// SWREG54 Configuration

#define	VENC_SWREG54_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG54_SWREG_FIELD_0	(0x1u<<0)

// SWREG55 Configuration

#define	VENC_SWREG55_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG55_SWREG_FIELD_0	(0x1u<<0)

// SWREG56 Configuration

#define	VENC_SWREG56_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG56_SWREG_FIELD_0	(0x1u<<0)

// SWREG57 Configuration

#define	VENC_SWREG57_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG57_SWREG_FIELD_0	(0x1u<<0)

// SWREG58 Configuration

#define	VENC_SWREG58_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG58_SWREG_FIELD_0	(0x1u<<0)

// SWREG59 Configuration

#define	VENC_SWREG59_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG59_SWREG_FIELD_0	(0x1u<<0)

// SWREG60 Configuration

#define	VENC_SWREG60_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG60_SWREG_FIELD_0	(0x1u<<0)

// SWREG61 Configuration

#define	VENC_SWREG61_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG61_SWREG_FIELD_0	(0x1u<<0)

// SWREG62 Configuration

#define	VENC_SWREG62_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG62_SWREG_FIELD_0	(0x1u<<0)

// SWREG63 Configuration

#define	VENC_SWREG63_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG63_SWREG_FIELD_0	(0x1u<<0)

// SWREG64 Configuration

#define	VENC_SWREG64_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG64_SWREG_FIELD_0	(0x1u<<0)

// SWREG65 Configuration

#define	VENC_SWREG65_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG65_SWREG_FIELD_0	(0x1u<<0)

// SWREG66 Configuration

#define	VENC_SWREG66_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG66_SWREG_FIELD_0	(0x1u<<0)

// SWREG67 Configuration

#define	VENC_SWREG67_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG67_SWREG_FIELD_0	(0x1u<<0)

// SWREG68 Configuration

#define	VENC_SWREG68_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG68_SWREG_FIELD_0	(0x1u<<0)

// SWREG69 Configuration

#define	VENC_SWREG69_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG69_SWREG_FIELD_0	(0x1u<<0)

// SWREG70 Configuration

#define	VENC_SWREG70_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG70_SWREG_FIELD_0	(0x1u<<0)

// SWREG71 Configuration

#define	VENC_SWREG71_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG71_SWREG_FIELD_0	(0x1u<<0)

// SWREG72 Configuration

#define	VENC_SWREG72_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG72_SWREG_FIELD_0	(0x1u<<0)

// SWREG73 Configuration

#define	VENC_SWREG73_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG73_SWREG_FIELD_0	(0x1u<<0)

// SWREG74 Configuration

#define	VENC_SWREG74_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG74_SWREG_FIELD_0	(0x1u<<0)

// SWREG75 Configuration

#define	VENC_SWREG75_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG75_SWREG_FIELD_0	(0x1u<<0)

// SWREG76 Configuration

#define	VENC_SWREG76_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG76_SWREG_FIELD_0	(0x1u<<0)

// SWREG77 Configuration

#define	VENC_SWREG77_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG77_SWREG_FIELD_0	(0x1u<<0)

// SWREG78 Configuration

#define	VENC_SWREG78_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG78_SWREG_FIELD_0	(0x1u<<0)

// SWREG79 Configuration

#define	VENC_SWREG79_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG79_SWREG_FIELD_0	(0x1u<<0)

// SWREG80 Configuration

#define	VENC_SWREG80_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG80_SWREG_FIELD_0	(0x1u<<0)

// SWREG81 Configuration

#define	VENC_SWREG81_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG81_SWREG_FIELD_0	(0x1u<<0)

// SWREG82 Configuration

#define	VENC_SWREG82_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG82_SWREG_FIELD_0	(0x1u<<0)

// SWREG83 Configuration

#define	VENC_SWREG83_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG83_SWREG_FIELD_0	(0x1u<<0)

// SWREG84 Configuration

#define	VENC_SWREG84_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG84_SWREG_FIELD_0	(0x1u<<0)

// SWREG85 Configuration

#define	VENC_SWREG85_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG85_SWREG_FIELD_0	(0x1u<<0)

// SWREG86 Configuration

#define	VENC_SWREG86_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG86_SWREG_FIELD_0	(0x1u<<0)

// SWREG87 Configuration

#define	VENC_SWREG87_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG87_SWREG_FIELD_0	(0x1u<<0)

// SWREG88 Configuration

#define	VENC_SWREG88_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG88_SWREG_FIELD_0	(0x1u<<0)

// SWREG89 Configuration

#define	VENC_SWREG89_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG89_SWREG_FIELD_0	(0x1u<<0)

// SWREG90 Configuration

#define	VENC_SWREG90_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG90_SWREG_FIELD_0	(0x1u<<0)

// SWREG91 Configuration

#define	VENC_SWREG91_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG91_SWREG_FIELD_0	(0x1u<<0)

// SWREG92 Configuration

#define	VENC_SWREG92_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG92_SWREG_FIELD_0	(0x1u<<0)

// SWREG93 Configuration

#define	VENC_SWREG93_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG93_SWREG_FIELD_0	(0x1u<<0)

// SWREG94 Configuration

#define	VENC_SWREG94_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG94_SWREG_FIELD_0	(0x1u<<0)

// SWREG95 Configuration

#define	VENC_SWREG95_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG95_SWREG_FIELD_0	(0x1u<<0)

// SWREG96 Configuration

#define	VENC_SWREG96_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG96_SWREG_FIELD_0	(0x1u<<0)

// SWREG97 Configuration

#define	VENC_SWREG97_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG97_SWREG_FIELD_0	(0x1u<<0)

// SWREG98 Configuration

#define	VENC_SWREG98_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG98_SWREG_FIELD_0	(0x1u<<0)

// SWREG99 Configuration

#define	VENC_SWREG99_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG99_SWREG_FIELD_0	(0x1u<<0)

// SWREG100 Configuration

#define	VENC_SWREG100_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG100_SWREG_FIELD_0	(0x1u<<0)

// SWREG101 Configuration

#define	VENC_SWREG101_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG101_SWREG_FIELD_0	(0x1u<<0)

// SWREG102 Configuration

#define	VENC_SWREG102_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG102_SWREG_FIELD_0	(0x1u<<0)

// SWREG103 Configuration

#define	VENC_SWREG103_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG103_SWREG_FIELD_0	(0x1u<<0)

// SWREG104 Configuration

#define	VENC_SWREG104_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG104_SWREG_FIELD_0	(0x1u<<0)

// SWREG105 Configuration

#define	VENC_SWREG105_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG105_SWREG_FIELD_0	(0x1u<<0)

// SWREG106 Configuration

#define	VENC_SWREG106_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG106_SWREG_FIELD_0	(0x1u<<0)

// SWREG107 Configuration

#define	VENC_SWREG107_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG107_SWREG_FIELD_0	(0x1u<<0)

// SWREG108 Configuration

#define	VENC_SWREG108_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG108_SWREG_FIELD_0	(0x1u<<0)

// SWREG109 Configuration

#define	VENC_SWREG109_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG109_SWREG_FIELD_0	(0x1u<<0)

// SWREG110 Configuration

#define	VENC_SWREG110_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG110_SWREG_FIELD_0	(0x1u<<0)

// SWREG111 Configuration

#define	VENC_SWREG111_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG111_SWREG_FIELD_0	(0x1u<<0)

// SWREG112 Configuration

#define	VENC_SWREG112_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG112_SWREG_FIELD_0	(0x1u<<0)

// SWREG113 Configuration

#define	VENC_SWREG113_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG113_SWREG_FIELD_0	(0x1u<<0)

// SWREG114 Configuration

#define	VENC_SWREG114_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG114_SWREG_FIELD_0	(0x1u<<0)

// SWREG115 Configuration

#define	VENC_SWREG115_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG115_SWREG_FIELD_0	(0x1u<<0)

// SWREG116 Configuration

#define	VENC_SWREG116_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG116_SWREG_FIELD_0	(0x1u<<0)

// SWREG117 Configuration

#define	VENC_SWREG117_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG117_SWREG_FIELD_0	(0x1u<<0)

// SWREG118 Configuration

#define	VENC_SWREG118_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG118_SWREG_FIELD_0	(0x1u<<0)

// SWREG119 Configuration

#define	VENC_SWREG119_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG119_SWREG_FIELD_0	(0x1u<<0)

// SWREG120 Configuration

#define	VENC_SWREG120_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG120_SWREG_FIELD_0	(0x1u<<0)

// SWREG121 Configuration

#define	VENC_SWREG121_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG121_SWREG_FIELD_0	(0x1u<<0)

// SWREG122 Configuration

#define	VENC_SWREG122_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG122_SWREG_FIELD_0	(0x1u<<0)

// SWREG123 Configuration

#define	VENC_SWREG123_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG123_SWREG_FIELD_0	(0x1u<<0)

// SWREG124 Configuration

#define	VENC_SWREG124_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG124_SWREG_FIELD_0	(0x1u<<0)

// SWREG125 Configuration

#define	VENC_SWREG125_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG125_SWREG_FIELD_0	(0x1u<<0)

// SWREG126 Configuration

#define	VENC_SWREG126_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG126_SWREG_FIELD_0	(0x1u<<0)

// SWREG127 Configuration

#define	VENC_SWREG127_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG127_SWREG_FIELD_0	(0x1u<<0)

// SWREG128 Configuration

#define	VENC_SWREG128_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG128_SWREG_FIELD_0	(0x1u<<0)

// SWREG129 Configuration

#define	VENC_SWREG129_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG129_SWREG_FIELD_0	(0x1u<<0)

// SWREG130 Configuration

#define	VENC_SWREG130_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG130_SWREG_FIELD_0	(0x1u<<0)

// SWREG131 Configuration

#define	VENC_SWREG131_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG131_SWREG_FIELD_0	(0x1u<<0)

// SWREG132 Configuration

#define	VENC_SWREG132_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG132_SWREG_FIELD_0	(0x1u<<0)

// SWREG133 Configuration

#define	VENC_SWREG133_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG133_SWREG_FIELD_0	(0x1u<<0)

// SWREG134 Configuration

#define	VENC_SWREG134_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG134_SWREG_FIELD_0	(0x1u<<0)

// SWREG135 Configuration

#define	VENC_SWREG135_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG135_SWREG_FIELD_0	(0x1u<<0)

// SWREG136 Configuration

#define	VENC_SWREG136_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG136_SWREG_FIELD_0	(0x1u<<0)

// SWREG137 Configuration

#define	VENC_SWREG137_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG137_SWREG_FIELD_0	(0x1u<<0)

// SWREG138 Configuration

#define	VENC_SWREG138_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG138_SWREG_FIELD_0	(0x1u<<0)

// SWREG139 Configuration

#define	VENC_SWREG139_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG139_SWREG_FIELD_0	(0x1u<<0)

// SWREG140 Configuration

#define	VENC_SWREG140_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG140_SWREG_FIELD_0	(0x1u<<0)

// SWREG141 Configuration

#define	VENC_SWREG141_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG141_SWREG_FIELD_0	(0x1u<<0)

// SWREG142 Configuration

#define	VENC_SWREG142_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG142_SWREG_FIELD_0	(0x1u<<0)

// SWREG143 Configuration

#define	VENC_SWREG143_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG143_SWREG_FIELD_0	(0x1u<<0)

// SWREG144 Configuration

#define	VENC_SWREG144_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG144_SWREG_FIELD_0	(0x1u<<0)

// SWREG145 Configuration

#define	VENC_SWREG145_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG145_SWREG_FIELD_0	(0x1u<<0)

// SWREG146 Configuration

#define	VENC_SWREG146_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG146_SWREG_FIELD_0	(0x1u<<0)

// SWREG147 Configuration

#define	VENC_SWREG147_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG147_SWREG_FIELD_0	(0x1u<<0)

// SWREG148 Configuration

#define	VENC_SWREG148_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG148_SWREG_FIELD_0	(0x1u<<0)

// SWREG149 Configuration

#define	VENC_SWREG149_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG149_SWREG_FIELD_0	(0x1u<<0)

// SWREG150 Configuration

#define	VENC_SWREG150_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG150_SWREG_FIELD_0	(0x1u<<0)

// SWREG151 Configuration

#define	VENC_SWREG151_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG151_SWREG_FIELD_0	(0x1u<<0)

// SWREG152 Configuration

#define	VENC_SWREG152_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG152_SWREG_FIELD_0	(0x1u<<0)

// SWREG153 Configuration

#define	VENC_SWREG153_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG153_SWREG_FIELD_0	(0x1u<<0)

// SWREG154 Configuration

#define	VENC_SWREG154_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG154_SWREG_FIELD_0	(0x1u<<0)

// SWREG155 Configuration

#define	VENC_SWREG155_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG155_SWREG_FIELD_0	(0x1u<<0)

// SWREG156 Configuration

#define	VENC_SWREG156_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG156_SWREG_FIELD_0	(0x1u<<0)

// SWREG157 Configuration

#define	VENC_SWREG157_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG157_SWREG_FIELD_0	(0x1u<<0)

// SWREG158 Configuration

#define	VENC_SWREG158_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG158_SWREG_FIELD_0	(0x1u<<0)

// SWREG159 Configuration

#define	VENC_SWREG159_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG159_SWREG_FIELD_0	(0x1u<<0)

// SWREG231 Configuration

#define	VENC_SWREG231_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG231_SWREG_FIELD_0	(0x1u<<0)

// SWREG232 Configuration

#define	VENC_SWREG232_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG232_SWREG_FIELD_0	(0x1u<<0)

// SWREG233 Configuration

#define	VENC_SWREG233_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG233_SWREG_FIELD_0	(0x1u<<0)

// SWREG236 Configuration

#define	VENC_SWREG236_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG236_SWREG_FIELD_0	(0x1u<<0)

// SWREG237 Configuration

#define	VENC_SWREG237_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG237_SWREG_FIELD_0	(0x1u<<0)

// SWREG238 Configuration

#define	VENC_SWREG238_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG238_SWREG_FIELD_0	(0x1u<<0)

// SWREG256 Configuration

#define	VENC_SWREG256_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG256_SWREG_FIELD_0	(0x1u<<0)

// SWREG257 Configuration

#define	VENC_SWREG257_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG257_SWREG_FIELD_0	(0x1u<<0)

// SWREG258 Configuration

#define	VENC_SWREG258_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG258_SWREG_FIELD_0	(0x1u<<0)

// SWREG259 Configuration

#define	VENC_SWREG259_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG259_SWREG_FIELD_0	(0x1u<<0)

// SWREG260 Configuration

#define	VENC_SWREG260_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG260_SWREG_FIELD_0	(0x1u<<0)

// SWREG261 Configuration

#define	VENC_SWREG261_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG261_SWREG_FIELD_0	(0x1u<<0)

// SWREG262 Configuration

#define	VENC_SWREG262_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG262_SWREG_FIELD_0	(0x1u<<0)

// SWREG263 Configuration

#define	VENC_SWREG263_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG263_SWREG_FIELD_0	(0x1u<<0)

// SWREG264 Configuration

#define	VENC_SWREG264_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG264_SWREG_FIELD_0	(0x1u<<0)

// SWREG265 Configuration

#define	VENC_SWREG265_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG265_SWREG_FIELD_0	(0x1u<<0)

// SWREG266 Configuration

#define	VENC_SWREG266_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG266_SWREG_FIELD_0	(0x1u<<0)

// SWREG267 Configuration

#define	VENC_SWREG267_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG267_SWREG_FIELD_0	(0x1u<<0)

// SWREG268 Configuration

#define	VENC_SWREG268_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG268_SWREG_FIELD_0	(0x1u<<0)

// SWREG269 Configuration

#define	VENC_SWREG269_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG269_SWREG_FIELD_0	(0x1u<<0)

// SWREG270 Configuration

#define	VENC_SWREG270_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG270_SWREG_FIELD_0	(0x1u<<0)

// SWREG271 Configuration

#define	VENC_SWREG271_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG271_SWREG_FIELD_0	(0x1u<<0)

// SWREG272 Configuration

#define	VENC_SWREG272_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG272_SWREG_FIELD_0	(0x1u<<0)

// SWREG273 Configuration

#define	VENC_SWREG273_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG273_SWREG_FIELD_0	(0x1u<<0)

// SWREG274 Configuration

#define	VENC_SWREG274_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG274_SWREG_FIELD_0	(0x1u<<0)

// SWREG275 Configuration

#define	VENC_SWREG275_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG275_SWREG_FIELD_0	(0x1u<<0)

// SWREG276 Configuration

#define	VENC_SWREG276_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG276_SWREG_FIELD_0	(0x1u<<0)

// SWREG277 Configuration

#define	VENC_SWREG277_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG277_SWREG_FIELD_0	(0x1u<<0)

// SWREG278 Configuration

#define	VENC_SWREG278_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG278_SWREG_FIELD_0	(0x1u<<0)

// SWREG279 Configuration

#define	VENC_SWREG279_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG279_SWREG_FIELD_0	(0x1u<<0)

// SWREG280 Configuration

#define	VENC_SWREG280_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG280_SWREG_FIELD_0	(0x1u<<0)

// SWREG281 Configuration

#define	VENC_SWREG281_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG281_SWREG_FIELD_0	(0x1u<<0)

// SWREG282 Configuration

#define	VENC_SWREG282_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG282_SWREG_FIELD_0	(0x1u<<0)

// SWREG283 Configuration

#define	VENC_SWREG283_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG283_SWREG_FIELD_0	(0x1u<<0)

// SWREG284 Configuration

#define	VENC_SWREG284_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG284_SWREG_FIELD_0	(0x1u<<0)

// SWREG285 Configuration

#define	VENC_SWREG285_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG285_SWREG_FIELD_0	(0x1u<<0)

// SWREG286 Configuration

#define	VENC_SWREG286_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG286_SWREG_FIELD_0	(0x1u<<0)

// SWREG287 Configuration

#define	VENC_SWREG287_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG287_SWREG_FIELD_0	(0x1u<<0)

// SWREG288 Configuration

#define	VENC_SWREG288_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG288_SWREG_FIELD_0	(0x1u<<0)

// SWREG289 Configuration

#define	VENC_SWREG289_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG289_SWREG_FIELD_0	(0x1u<<0)

// SWREG290 Configuration

#define	VENC_SWREG290_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG290_SWREG_FIELD_0	(0x1u<<0)

// SWREG291 Configuration

#define	VENC_SWREG291_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG291_SWREG_FIELD_0	(0x1u<<0)

// SWREG294 Configuration

#define	VENC_SWREG294_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG294_SWREG_FIELD_0	(0x1u<<0)

// SWREG295 Configuration

#define	VENC_SWREG295_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG295_SWREG_FIELD_0	(0x1u<<0)

// SWREG296 Configuration

#define	VENC_SWREG296_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG296_SWREG_FIELD_0	(0x1u<<0)

// SWREG297 Configuration

#define	VENC_SWREG297_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG297_SWREG_FIELD_0	(0x1u<<0)

// SWREG298 Configuration

#define	VENC_SWREG298_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG298_SWREG_FIELD_0	(0x1u<<0)

// SWREG299 Configuration

#define	VENC_SWREG299_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG299_SWREG_FIELD_0	(0x1u<<0)

// SWREG300 Configuration

#define	VENC_SWREG300_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG300_SWREG_FIELD_0	(0x1u<<0)

// SWREG301 Configuration

#define	VENC_SWREG301_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG301_SWREG_FIELD_0	(0x1u<<0)

// SWREG302 Configuration

#define	VENC_SWREG302_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG302_SWREG_FIELD_0	(0x1u<<0)

// SWREG303 Configuration

#define	VENC_SWREG303_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG303_SWREG_FIELD_0	(0x1u<<0)

// SWREG304 Configuration

#define	VENC_SWREG304_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG304_SWREG_FIELD_0	(0x1u<<0)

// SWREG305 Configuration

#define	VENC_SWREG305_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG305_SWREG_FIELD_0	(0x1u<<0)

// SWREG306 Configuration

#define	VENC_SWREG306_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG306_SWREG_FIELD_0	(0x1u<<0)

// SWREG307 Configuration

#define	VENC_SWREG307_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG307_SWREG_FIELD_0	(0x1u<<0)

// SWREG308 Configuration

#define	VENC_SWREG308_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG308_SWREG_FIELD_0	(0x1u<<0)

// SWREG309 Configuration

#define	VENC_SWREG309_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG309_SWREG_FIELD_0	(0x1u<<0)

// SWREG310 Configuration

#define	VENC_SWREG310_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG310_SWREG_FIELD_0	(0x1u<<0)

// SWREG311 Configuration

#define	VENC_SWREG311_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG311_SWREG_FIELD_0	(0x1u<<0)

// SWREG312 Configuration

#define	VENC_SWREG312_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG312_SWREG_FIELD_0	(0x1u<<0)

// SWREG313 Configuration

#define	VENC_SWREG313_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG313_SWREG_FIELD_0	(0x1u<<0)

// SWREG314 Configuration

#define	VENC_SWREG314_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG314_SWREG_FIELD_0	(0x1u<<0)

// SWREG315 Configuration

#define	VENC_SWREG315_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG315_SWREG_FIELD_0	(0x1u<<0)

// SWREG316 Configuration

#define	VENC_SWREG316_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG316_SWREG_FIELD_0	(0x1u<<0)

// SWREG317 Configuration

#define	VENC_SWREG317_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG317_SWREG_FIELD_0	(0x1u<<0)

// SWREG318 Configuration

#define	VENC_SWREG318_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG318_SWREG_FIELD_0	(0x1u<<0)

// SWREG319 Configuration

#define	VENC_SWREG319_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG319_SWREG_FIELD_0	(0x1u<<0)

// SWREG320 Configuration

#define	VENC_SWREG320_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG320_SWREG_FIELD_0	(0x1u<<0)

// SWREG321 Configuration

#define	VENC_SWREG321_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG321_SWREG_FIELD_0	(0x1u<<0)

// SWREG322 Configuration

#define	VENC_SWREG322_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG322_SWREG_FIELD_0	(0x1u<<0)

// SWREG323 Configuration

#define	VENC_SWREG323_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG323_SWREG_FIELD_0	(0x1u<<0)

// SWREG324 Configuration

#define	VENC_SWREG324_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG324_SWREG_FIELD_0	(0x1u<<0)

// SWREG325 Configuration

#define	VENC_SWREG325_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG325_SWREG_FIELD_0	(0x1u<<0)

// SWREG326 Configuration

#define	VENC_SWREG326_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG326_SWREG_FIELD_0	(0x1u<<0)

// SWREG327 Configuration

#define	VENC_SWREG327_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG327_SWREG_FIELD_0	(0x1u<<0)

// SWREG328 Configuration

#define	VENC_SWREG328_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG328_SWREG_FIELD_0	(0x1u<<0)

// SWREG329 Configuration

#define	VENC_SWREG329_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG329_SWREG_FIELD_0	(0x1u<<0)

// SWREG330 Configuration

#define	VENC_SWREG330_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG330_SWREG_FIELD_0	(0x1u<<0)

// SWREG331 Configuration

#define	VENC_SWREG331_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG331_SWREG_FIELD_0	(0x1u<<0)

// SWREG332 Configuration

#define	VENC_SWREG332_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG332_SWREG_FIELD_0	(0x1u<<0)

// SWREG333 Configuration

#define	VENC_SWREG333_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG333_SWREG_FIELD_0	(0x1u<<0)

// SWREG334 Configuration

#define	VENC_SWREG334_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG334_SWREG_FIELD_0	(0x1u<<0)

// SWREG335 Configuration

#define	VENC_SWREG335_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG335_SWREG_FIELD_0	(0x1u<<0)

// SWREG336 Configuration

#define	VENC_SWREG336_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG336_SWREG_FIELD_0	(0x1u<<0)

// SWREG337 Configuration

#define	VENC_SWREG337_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG337_SWREG_FIELD_0	(0x1u<<0)

// SWREG338 Configuration

#define	VENC_SWREG338_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG338_SWREG_FIELD_0	(0x1u<<0)

// SWREG339 Configuration

#define	VENC_SWREG339_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG339_SWREG_FIELD_0	(0x1u<<0)

// SWREG340 Configuration

#define	VENC_SWREG340_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG340_SWREG_FIELD_0	(0x1u<<0)

// SWREG341 Configuration

#define	VENC_SWREG341_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG341_SWREG_FIELD_0	(0x1u<<0)

// SWREG342 Configuration

#define	VENC_SWREG342_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG342_SWREG_FIELD_0	(0x1u<<0)

// SWREG343 Configuration

#define	VENC_SWREG343_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG343_SWREG_FIELD_0	(0x1u<<0)

// SWREG344 Configuration

#define	VENC_SWREG344_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG344_SWREG_FIELD_0	(0x1u<<0)

// SWREG345 Configuration

#define	VENC_SWREG345_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG345_SWREG_FIELD_0	(0x1u<<0)

// SWREG346 Configuration

#define	VENC_SWREG346_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG346_SWREG_FIELD_0	(0x1u<<0)

// SWREG347 Configuration

#define	VENC_SWREG347_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG347_SWREG_FIELD_0	(0x1u<<0)

// SWREG348 Configuration

#define	VENC_SWREG348_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG348_SWREG_FIELD_0	(0x1u<<0)

// SWREG349 Configuration

#define	VENC_SWREG349_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG349_SWREG_FIELD_0	(0x1u<<0)

// SWREG350 Configuration

#define	VENC_SWREG350_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG350_SWREG_FIELD_0	(0x1u<<0)

// SWREG351 Configuration

#define	VENC_SWREG351_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG351_SWREG_FIELD_0	(0x1u<<0)

// SWREG352 Configuration

#define	VENC_SWREG352_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG352_SWREG_FIELD_0	(0x1u<<0)

// SWREG353 Configuration

#define	VENC_SWREG353_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG353_SWREG_FIELD_0	(0x1u<<0)

// SWREG354 Configuration

#define	VENC_SWREG354_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG354_SWREG_FIELD_0	(0x1u<<0)

// SWREG355 Configuration

#define	VENC_SWREG355_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG355_SWREG_FIELD_0	(0x1u<<0)

// SWREG356 Configuration

#define	VENC_SWREG356_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG356_SWREG_FIELD_0	(0x1u<<0)

// SWREG357 Configuration

#define	VENC_SWREG357_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG357_SWREG_FIELD_0	(0x1u<<0)

// SWREG358 Configuration

#define	VENC_SWREG358_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG358_SWREG_FIELD_0	(0x1u<<0)

// SWREG359 Configuration

#define	VENC_SWREG359_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG359_SWREG_FIELD_0	(0x1u<<0)

// SWREG360 Configuration

#define	VENC_SWREG360_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG360_SWREG_FIELD_0	(0x1u<<0)

// SWREG361 Configuration

#define	VENC_SWREG361_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG361_SWREG_FIELD_0	(0x1u<<0)

// SWREG362 Configuration

#define	VENC_SWREG362_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG362_SWREG_FIELD_0	(0x1u<<0)

// SWREG363 Configuration

#define	VENC_SWREG363_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG363_SWREG_FIELD_0	(0x1u<<0)

// SWREG364 Configuration

#define	VENC_SWREG364_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG364_SWREG_FIELD_0	(0x1u<<0)

// SWREG365 Configuration

#define	VENC_SWREG365_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG365_SWREG_FIELD_0	(0x1u<<0)

// SWREG366 Configuration

#define	VENC_SWREG366_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG366_SWREG_FIELD_0	(0x1u<<0)

// SWREG367 Configuration

#define	VENC_SWREG367_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG367_SWREG_FIELD_0	(0x1u<<0)

// SWREG368 Configuration

#define	VENC_SWREG368_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG368_SWREG_FIELD_0	(0x1u<<0)

// SWREG369 Configuration

#define	VENC_SWREG369_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG369_SWREG_FIELD_0	(0x1u<<0)

// SWREG370 Configuration

#define	VENC_SWREG370_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG370_SWREG_FIELD_0	(0x1u<<0)

// SWREG371 Configuration

#define	VENC_SWREG371_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG371_SWREG_FIELD_0	(0x1u<<0)

// SWREG372 Configuration

#define	VENC_SWREG372_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG372_SWREG_FIELD_0	(0x1u<<0)

// SWREG373 Configuration

#define	VENC_SWREG373_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG373_SWREG_FIELD_0	(0x1u<<0)

// SWREG374 Configuration

#define	VENC_SWREG374_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG374_SWREG_FIELD_0	(0x1u<<0)

// SWREG375 Configuration

#define	VENC_SWREG375_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG375_SWREG_FIELD_0	(0x1u<<0)

// SWREG376 Configuration

#define	VENC_SWREG376_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG376_SWREG_FIELD_0	(0x1u<<0)

// SWREG377 Configuration

#define	VENC_SWREG377_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG377_SWREG_FIELD_0	(0x1u<<0)

// SWREG378 Configuration

#define	VENC_SWREG378_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG378_SWREG_FIELD_0	(0x1u<<0)

// SWREG379 Configuration

#define	VENC_SWREG379_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG379_SWREG_FIELD_0	(0x1u<<0)

// SWREG380 Configuration

#define	VENC_SWREG380_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG380_SWREG_FIELD_0	(0x1u<<0)

// SWREG381 Configuration

#define	VENC_SWREG381_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG381_SWREG_FIELD_0	(0x1u<<0)

// SWREG382 Configuration

#define	VENC_SWREG382_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG382_SWREG_FIELD_0	(0x1u<<0)

// SWREG383 Configuration

#define	VENC_SWREG383_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG383_SWREG_FIELD_0	(0x1u<<0)

// SWREG384 Configuration

#define	VENC_SWREG384_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG384_SWREG_FIELD_0	(0x1u<<0)

// SWREG385 Configuration

#define	VENC_SWREG385_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG385_SWREG_FIELD_0	(0x1u<<0)

// SWREG386 Configuration

#define	VENC_SWREG386_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG386_SWREG_FIELD_0	(0x1u<<0)

// SWREG387 Configuration

#define	VENC_SWREG387_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG387_SWREG_FIELD_0	(0x1u<<0)

// SWREG388 Configuration

#define	VENC_SWREG388_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG388_SWREG_FIELD_0	(0x1u<<0)

// SWREG389 Configuration

#define	VENC_SWREG389_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG389_SWREG_FIELD_0	(0x1u<<0)

// SWREG390 Configuration

#define	VENC_SWREG390_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG390_SWREG_FIELD_0	(0x1u<<0)

// SWREG391 Configuration

#define	VENC_SWREG391_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG391_SWREG_FIELD_0	(0x1u<<0)

// SWREG392 Configuration

#define	VENC_SWREG392_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG392_SWREG_FIELD_0	(0x1u<<0)

// SWREG393 Configuration

#define	VENC_SWREG393_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG393_SWREG_FIELD_0	(0x1u<<0)

// SWREG394 Configuration

#define	VENC_SWREG394_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG394_SWREG_FIELD_0	(0x1u<<0)

// SWREG395 Configuration

#define	VENC_SWREG395_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG395_SWREG_FIELD_0	(0x1u<<0)

// SWREG396 Configuration

#define	VENC_SWREG396_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG396_SWREG_FIELD_0	(0x1u<<0)

// SWREG397 Configuration

#define	VENC_SWREG397_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG397_SWREG_FIELD_0	(0x1u<<0)

// SWREG398 Configuration

#define	VENC_SWREG398_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG398_SWREG_FIELD_0	(0x1u<<0)

// SWREG399 Configuration

#define	VENC_SWREG399_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG399_SWREG_FIELD_0	(0x1u<<0)

// SWREG400 Configuration

#define	VENC_SWREG400_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG400_SWREG_FIELD_0	(0x1u<<0)

// SWREG401 Configuration

#define	VENC_SWREG401_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG401_SWREG_FIELD_0	(0x1u<<0)

// SWREG402 Configuration

#define	VENC_SWREG402_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG402_SWREG_FIELD_0	(0x1u<<0)

// SWREG403 Configuration

#define	VENC_SWREG403_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG403_SWREG_FIELD_0	(0x1u<<0)

// SWREG404 Configuration

#define	VENC_SWREG404_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG404_SWREG_FIELD_0	(0x1u<<0)

// SWREG405 Configuration

#define	VENC_SWREG405_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG405_SWREG_FIELD_0	(0x1u<<0)

// SWREG406 Configuration

#define	VENC_SWREG406_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG406_SWREG_FIELD_0	(0x1u<<0)

// SWREG407 Configuration

#define	VENC_SWREG407_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG407_SWREG_FIELD_0	(0x1u<<0)

// SWREG408 Configuration

#define	VENC_SWREG408_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG408_SWREG_FIELD_0	(0x1u<<0)

// SWREG409 Configuration

#define	VENC_SWREG409_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG409_SWREG_FIELD_0	(0x1u<<0)

// SWREG410 Configuration

#define	VENC_SWREG410_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG410_SWREG_FIELD_0	(0x1u<<0)

// SWREG411 Configuration

#define	VENC_SWREG411_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG411_SWREG_FIELD_0	(0x1u<<0)

// SWREG412 Configuration

#define	VENC_SWREG412_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG412_SWREG_FIELD_0	(0x1u<<0)

// SWREG413 Configuration

#define	VENC_SWREG413_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG413_SWREG_FIELD_0	(0x1u<<0)

// SWREG414 Configuration

#define	VENC_SWREG414_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG414_SWREG_FIELD_0	(0x1u<<0)

// SWREG415 Configuration

#define	VENC_SWREG415_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG415_SWREG_FIELD_0	(0x1u<<0)

// SWREG416 Configuration

#define	VENC_SWREG416_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG416_SWREG_FIELD_0	(0x1u<<0)

// SWREG417 Configuration

#define	VENC_SWREG417_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG417_SWREG_FIELD_0	(0x1u<<0)

// SWREG418 Configuration

#define	VENC_SWREG418_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG418_SWREG_FIELD_0	(0x1u<<0)

// SWREG419 Configuration

#define	VENC_SWREG419_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG419_SWREG_FIELD_0	(0x1u<<0)

// SWREG420 Configuration

#define	VENC_SWREG420_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG420_SWREG_FIELD_0	(0x1u<<0)

// SWREG421 Configuration

#define	VENC_SWREG421_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG421_SWREG_FIELD_0	(0x1u<<0)

// SWREG422 Configuration

#define	VENC_SWREG422_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG422_SWREG_FIELD_0	(0x1u<<0)

// SWREG423 Configuration

#define	VENC_SWREG423_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG423_SWREG_FIELD_0	(0x1u<<0)

// SWREG424 Configuration

#define	VENC_SWREG424_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG424_SWREG_FIELD_0	(0x1u<<0)

// SWREG425 Configuration

#define	VENC_SWREG425_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG425_SWREG_FIELD_0	(0x1u<<0)

// SWREG426 Configuration

#define	VENC_SWREG426_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG426_SWREG_FIELD_0	(0x1u<<0)

// SWREG427 Configuration

#define	VENC_SWREG427_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG427_SWREG_FIELD_0	(0x1u<<0)

// SWREG428 Configuration

#define	VENC_SWREG428_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG428_SWREG_FIELD_0	(0x1u<<0)

// SWREG429 Configuration

#define	VENC_SWREG429_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG429_SWREG_FIELD_0	(0x1u<<0)

// SWREG430 Configuration

#define	VENC_SWREG430_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG430_SWREG_FIELD_0	(0x1u<<0)

// SWREG431 Configuration

#define	VENC_SWREG431_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG431_SWREG_FIELD_0	(0x1u<<0)

// SWREG432 Configuration

#define	VENC_SWREG432_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG432_SWREG_FIELD_0	(0x1u<<0)

// SWREG433 Configuration

#define	VENC_SWREG433_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG433_SWREG_FIELD_0	(0x1u<<0)

// SWREG434 Configuration

#define	VENC_SWREG434_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG434_SWREG_FIELD_0	(0x1u<<0)

// SWREG435 Configuration

#define	VENC_SWREG435_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG435_SWREG_FIELD_0	(0x1u<<0)

// SWREG436 Configuration

#define	VENC_SWREG436_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG436_SWREG_FIELD_0	(0x1u<<0)

// SWREG437 Configuration

#define	VENC_SWREG437_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG437_SWREG_FIELD_0	(0x1u<<0)

// SWREG438 Configuration

#define	VENC_SWREG438_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG438_SWREG_FIELD_0	(0x1u<<0)

// SWREG439 Configuration

#define	VENC_SWREG439_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG439_SWREG_FIELD_0	(0x1u<<0)

// SWREG440 Configuration

#define	VENC_SWREG440_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG440_SWREG_FIELD_0	(0x1u<<0)

// SWREG441 Configuration

#define	VENC_SWREG441_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG441_SWREG_FIELD_0	(0x1u<<0)

// SWREG442 Configuration

#define	VENC_SWREG442_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG442_SWREG_FIELD_0	(0x1u<<0)

// SWREG443 Configuration

#define	VENC_SWREG443_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG443_SWREG_FIELD_0	(0x1u<<0)

// SWREG444 Configuration

#define	VENC_SWREG444_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG444_SWREG_FIELD_0	(0x1u<<0)

// SWREG449 Configuration

#define	VENC_SWREG449_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG449_SWREG_FIELD_0	(0x1u<<0)

// SWREG497 Configuration

#define	VENC_SWREG497_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG497_SWREG_FIELD_0	(0x1u<<0)

// SWREG498 Configuration

#define	VENC_SWREG498_SWREG_FIELD	(0xFFFFFFFFu<<0)
#define	VENC_SWREG498_SWREG_FIELD_0	(0x1u<<0)
