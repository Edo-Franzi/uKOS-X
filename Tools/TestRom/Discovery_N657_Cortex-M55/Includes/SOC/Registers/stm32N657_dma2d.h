/*
; stm32N657_dma2d.
; ================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_dma2d equates.
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

// DMA2D address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	ISR;
	volatile	uint32_t	IFCR;
	volatile	uint32_t	FGMAR;
	volatile	uint32_t	FGOR;
	volatile	uint32_t	BGMAR;
	volatile	uint32_t	BGOR;
	volatile	uint32_t	FGPFCCR;
	volatile	uint32_t	FGCOLR;
	volatile	uint32_t	BGPFCCR;
	volatile	uint32_t	BGCOLR;
	volatile	uint32_t	FGCMAR;
	volatile	uint32_t	BGCMAR;
	volatile	uint32_t	OPFCCR;
	volatile	uint32_t	OCOLR;
	volatile	uint32_t	OMAR;
	volatile	uint32_t	OOR;
	volatile	uint32_t	NLR;
	volatile	uint32_t	LWR;
	volatile	uint32_t	AMTCR;
	volatile	uint32_t	RESERVED0[236];
	volatile	uint32_t	FGCLUT0;
	volatile	uint32_t	FGCLUT1;
	volatile	uint32_t	FGCLUT2;
	volatile	uint32_t	FGCLUT3;
	volatile	uint32_t	FGCLUT4;
	volatile	uint32_t	FGCLUT5;
	volatile	uint32_t	FGCLUT6;
	volatile	uint32_t	FGCLUT7;
	volatile	uint32_t	FGCLUT8;
	volatile	uint32_t	FGCLUT9;
	volatile	uint32_t	FGCLUT10;
	volatile	uint32_t	FGCLUT11;
	volatile	uint32_t	FGCLUT12;
	volatile	uint32_t	FGCLUT13;
	volatile	uint32_t	FGCLUT14;
	volatile	uint32_t	FGCLUT15;
	volatile	uint32_t	FGCLUT16;
	volatile	uint32_t	FGCLUT17;
	volatile	uint32_t	FGCLUT18;
	volatile	uint32_t	FGCLUT19;
	volatile	uint32_t	FGCLUT20;
	volatile	uint32_t	FGCLUT21;
	volatile	uint32_t	FGCLUT22;
	volatile	uint32_t	FGCLUT23;
	volatile	uint32_t	FGCLUT24;
	volatile	uint32_t	FGCLUT25;
	volatile	uint32_t	FGCLUT26;
	volatile	uint32_t	FGCLUT27;
	volatile	uint32_t	FGCLUT28;
	volatile	uint32_t	FGCLUT29;
	volatile	uint32_t	FGCLUT30;
	volatile	uint32_t	FGCLUT31;
	volatile	uint32_t	FGCLUT32;
	volatile	uint32_t	FGCLUT33;
	volatile	uint32_t	FGCLUT34;
	volatile	uint32_t	FGCLUT35;
	volatile	uint32_t	FGCLUT36;
	volatile	uint32_t	FGCLUT37;
	volatile	uint32_t	FGCLUT38;
	volatile	uint32_t	FGCLUT39;
	volatile	uint32_t	FGCLUT40;
	volatile	uint32_t	FGCLUT41;
	volatile	uint32_t	FGCLUT42;
	volatile	uint32_t	FGCLUT43;
	volatile	uint32_t	FGCLUT44;
	volatile	uint32_t	FGCLUT45;
	volatile	uint32_t	FGCLUT46;
	volatile	uint32_t	FGCLUT47;
	volatile	uint32_t	FGCLUT48;
	volatile	uint32_t	FGCLUT49;
	volatile	uint32_t	FGCLUT50;
	volatile	uint32_t	FGCLUT51;
	volatile	uint32_t	FGCLUT52;
	volatile	uint32_t	FGCLUT53;
	volatile	uint32_t	FGCLUT54;
	volatile	uint32_t	FGCLUT55;
	volatile	uint32_t	FGCLUT56;
	volatile	uint32_t	FGCLUT57;
	volatile	uint32_t	FGCLUT58;
	volatile	uint32_t	FGCLUT59;
	volatile	uint32_t	FGCLUT60;
	volatile	uint32_t	FGCLUT61;
	volatile	uint32_t	FGCLUT62;
	volatile	uint32_t	FGCLUT63;
	volatile	uint32_t	FGCLUT64;
	volatile	uint32_t	FGCLUT65;
	volatile	uint32_t	FGCLUT66;
	volatile	uint32_t	FGCLUT67;
	volatile	uint32_t	FGCLUT68;
	volatile	uint32_t	FGCLUT69;
	volatile	uint32_t	FGCLUT70;
	volatile	uint32_t	FGCLUT71;
	volatile	uint32_t	FGCLUT72;
	volatile	uint32_t	FGCLUT73;
	volatile	uint32_t	FGCLUT74;
	volatile	uint32_t	FGCLUT75;
	volatile	uint32_t	FGCLUT76;
	volatile	uint32_t	FGCLUT77;
	volatile	uint32_t	FGCLUT78;
	volatile	uint32_t	FGCLUT79;
	volatile	uint32_t	FGCLUT80;
	volatile	uint32_t	FGCLUT81;
	volatile	uint32_t	FGCLUT82;
	volatile	uint32_t	FGCLUT83;
	volatile	uint32_t	FGCLUT84;
	volatile	uint32_t	FGCLUT85;
	volatile	uint32_t	FGCLUT86;
	volatile	uint32_t	FGCLUT87;
	volatile	uint32_t	FGCLUT88;
	volatile	uint32_t	FGCLUT89;
	volatile	uint32_t	FGCLUT90;
	volatile	uint32_t	FGCLUT91;
	volatile	uint32_t	FGCLUT92;
	volatile	uint32_t	FGCLUT93;
	volatile	uint32_t	FGCLUT94;
	volatile	uint32_t	FGCLUT95;
	volatile	uint32_t	FGCLUT96;
	volatile	uint32_t	FGCLUT97;
	volatile	uint32_t	FGCLUT98;
	volatile	uint32_t	FGCLUT99;
	volatile	uint32_t	FGCLUT100;
	volatile	uint32_t	FGCLUT101;
	volatile	uint32_t	FGCLUT102;
	volatile	uint32_t	FGCLUT103;
	volatile	uint32_t	FGCLUT104;
	volatile	uint32_t	FGCLUT105;
	volatile	uint32_t	FGCLUT106;
	volatile	uint32_t	FGCLUT107;
	volatile	uint32_t	FGCLUT108;
	volatile	uint32_t	FGCLUT109;
	volatile	uint32_t	FGCLUT110;
	volatile	uint32_t	FGCLUT111;
	volatile	uint32_t	FGCLUT112;
	volatile	uint32_t	FGCLUT113;
	volatile	uint32_t	FGCLUT114;
	volatile	uint32_t	FGCLUT115;
	volatile	uint32_t	FGCLUT116;
	volatile	uint32_t	FGCLUT117;
	volatile	uint32_t	FGCLUT118;
	volatile	uint32_t	FGCLUT119;
	volatile	uint32_t	FGCLUT120;
	volatile	uint32_t	FGCLUT121;
	volatile	uint32_t	FGCLUT122;
	volatile	uint32_t	FGCLUT123;
	volatile	uint32_t	FGCLUT124;
	volatile	uint32_t	FGCLUT125;
	volatile	uint32_t	FGCLUT126;
	volatile	uint32_t	FGCLUT127;
	volatile	uint32_t	FGCLUT128;
	volatile	uint32_t	FGCLUT129;
	volatile	uint32_t	FGCLUT130;
	volatile	uint32_t	FGCLUT131;
	volatile	uint32_t	FGCLUT132;
	volatile	uint32_t	FGCLUT133;
	volatile	uint32_t	FGCLUT134;
	volatile	uint32_t	FGCLUT135;
	volatile	uint32_t	FGCLUT136;
	volatile	uint32_t	FGCLUT137;
	volatile	uint32_t	FGCLUT138;
	volatile	uint32_t	FGCLUT139;
	volatile	uint32_t	FGCLUT140;
	volatile	uint32_t	FGCLUT141;
	volatile	uint32_t	FGCLUT142;
	volatile	uint32_t	FGCLUT143;
	volatile	uint32_t	FGCLUT144;
	volatile	uint32_t	FGCLUT145;
	volatile	uint32_t	FGCLUT146;
	volatile	uint32_t	FGCLUT147;
	volatile	uint32_t	FGCLUT148;
	volatile	uint32_t	FGCLUT149;
	volatile	uint32_t	FGCLUT150;
	volatile	uint32_t	FGCLUT151;
	volatile	uint32_t	FGCLUT152;
	volatile	uint32_t	FGCLUT153;
	volatile	uint32_t	FGCLUT154;
	volatile	uint32_t	FGCLUT155;
	volatile	uint32_t	FGCLUT156;
	volatile	uint32_t	FGCLUT157;
	volatile	uint32_t	FGCLUT158;
	volatile	uint32_t	FGCLUT159;
	volatile	uint32_t	FGCLUT160;
	volatile	uint32_t	FGCLUT161;
	volatile	uint32_t	FGCLUT162;
	volatile	uint32_t	FGCLUT163;
	volatile	uint32_t	FGCLUT164;
	volatile	uint32_t	FGCLUT165;
	volatile	uint32_t	FGCLUT166;
	volatile	uint32_t	FGCLUT167;
	volatile	uint32_t	FGCLUT168;
	volatile	uint32_t	FGCLUT169;
	volatile	uint32_t	FGCLUT170;
	volatile	uint32_t	FGCLUT171;
	volatile	uint32_t	FGCLUT172;
	volatile	uint32_t	FGCLUT173;
	volatile	uint32_t	FGCLUT174;
	volatile	uint32_t	FGCLUT175;
	volatile	uint32_t	FGCLUT176;
	volatile	uint32_t	FGCLUT177;
	volatile	uint32_t	FGCLUT178;
	volatile	uint32_t	FGCLUT179;
	volatile	uint32_t	FGCLUT180;
	volatile	uint32_t	FGCLUT181;
	volatile	uint32_t	FGCLUT182;
	volatile	uint32_t	FGCLUT183;
	volatile	uint32_t	FGCLUT184;
	volatile	uint32_t	FGCLUT185;
	volatile	uint32_t	FGCLUT186;
	volatile	uint32_t	FGCLUT187;
	volatile	uint32_t	FGCLUT188;
	volatile	uint32_t	FGCLUT189;
	volatile	uint32_t	FGCLUT190;
	volatile	uint32_t	FGCLUT191;
	volatile	uint32_t	FGCLUT192;
	volatile	uint32_t	FGCLUT193;
	volatile	uint32_t	FGCLUT194;
	volatile	uint32_t	FGCLUT195;
	volatile	uint32_t	FGCLUT196;
	volatile	uint32_t	FGCLUT197;
	volatile	uint32_t	FGCLUT198;
	volatile	uint32_t	FGCLUT199;
	volatile	uint32_t	FGCLUT200;
	volatile	uint32_t	FGCLUT201;
	volatile	uint32_t	FGCLUT202;
	volatile	uint32_t	FGCLUT203;
	volatile	uint32_t	FGCLUT204;
	volatile	uint32_t	FGCLUT205;
	volatile	uint32_t	FGCLUT206;
	volatile	uint32_t	FGCLUT207;
	volatile	uint32_t	FGCLUT208;
	volatile	uint32_t	FGCLUT209;
	volatile	uint32_t	FGCLUT210;
	volatile	uint32_t	FGCLUT211;
	volatile	uint32_t	FGCLUT212;
	volatile	uint32_t	FGCLUT213;
	volatile	uint32_t	FGCLUT214;
	volatile	uint32_t	FGCLUT215;
	volatile	uint32_t	FGCLUT216;
	volatile	uint32_t	FGCLUT217;
	volatile	uint32_t	FGCLUT218;
	volatile	uint32_t	FGCLUT219;
	volatile	uint32_t	FGCLUT220;
	volatile	uint32_t	FGCLUT221;
	volatile	uint32_t	FGCLUT222;
	volatile	uint32_t	FGCLUT223;
	volatile	uint32_t	FGCLUT224;
	volatile	uint32_t	FGCLUT225;
	volatile	uint32_t	FGCLUT226;
	volatile	uint32_t	FGCLUT227;
	volatile	uint32_t	FGCLUT228;
	volatile	uint32_t	FGCLUT229;
	volatile	uint32_t	FGCLUT230;
	volatile	uint32_t	FGCLUT231;
	volatile	uint32_t	FGCLUT232;
	volatile	uint32_t	FGCLUT233;
	volatile	uint32_t	FGCLUT234;
	volatile	uint32_t	FGCLUT235;
	volatile	uint32_t	FGCLUT236;
	volatile	uint32_t	FGCLUT237;
	volatile	uint32_t	FGCLUT238;
	volatile	uint32_t	FGCLUT239;
	volatile	uint32_t	FGCLUT240;
	volatile	uint32_t	FGCLUT241;
	volatile	uint32_t	FGCLUT242;
	volatile	uint32_t	FGCLUT243;
	volatile	uint32_t	FGCLUT244;
	volatile	uint32_t	FGCLUT245;
	volatile	uint32_t	FGCLUT246;
	volatile	uint32_t	FGCLUT247;
	volatile	uint32_t	FGCLUT248;
	volatile	uint32_t	FGCLUT249;
	volatile	uint32_t	FGCLUT250;
	volatile	uint32_t	FGCLUT251;
	volatile	uint32_t	FGCLUT252;
	volatile	uint32_t	FGCLUT253;
	volatile	uint32_t	FGCLUT254;
	volatile	uint32_t	FGCLUT255;
	volatile	uint32_t	BGCLUT0;
	volatile	uint32_t	BGCLUT1;
	volatile	uint32_t	BGCLUT2;
	volatile	uint32_t	BGCLUT3;
	volatile	uint32_t	BGCLUT4;
	volatile	uint32_t	BGCLUT5;
	volatile	uint32_t	BGCLUT6;
	volatile	uint32_t	BGCLUT7;
	volatile	uint32_t	BGCLUT8;
	volatile	uint32_t	BGCLUT9;
	volatile	uint32_t	BGCLUT10;
	volatile	uint32_t	BGCLUT11;
	volatile	uint32_t	BGCLUT12;
	volatile	uint32_t	BGCLUT13;
	volatile	uint32_t	BGCLUT14;
	volatile	uint32_t	BGCLUT15;
	volatile	uint32_t	BGCLUT16;
	volatile	uint32_t	BGCLUT17;
	volatile	uint32_t	BGCLUT18;
	volatile	uint32_t	BGCLUT19;
	volatile	uint32_t	BGCLUT20;
	volatile	uint32_t	BGCLUT21;
	volatile	uint32_t	BGCLUT22;
	volatile	uint32_t	BGCLUT23;
	volatile	uint32_t	BGCLUT24;
	volatile	uint32_t	BGCLUT25;
	volatile	uint32_t	BGCLUT26;
	volatile	uint32_t	BGCLUT27;
	volatile	uint32_t	BGCLUT28;
	volatile	uint32_t	BGCLUT29;
	volatile	uint32_t	BGCLUT30;
	volatile	uint32_t	BGCLUT31;
	volatile	uint32_t	BGCLUT32;
	volatile	uint32_t	BGCLUT33;
	volatile	uint32_t	BGCLUT34;
	volatile	uint32_t	BGCLUT35;
	volatile	uint32_t	BGCLUT36;
	volatile	uint32_t	BGCLUT37;
	volatile	uint32_t	BGCLUT38;
	volatile	uint32_t	BGCLUT39;
	volatile	uint32_t	BGCLUT40;
	volatile	uint32_t	BGCLUT41;
	volatile	uint32_t	BGCLUT42;
	volatile	uint32_t	BGCLUT43;
	volatile	uint32_t	BGCLUT44;
	volatile	uint32_t	BGCLUT45;
	volatile	uint32_t	BGCLUT46;
	volatile	uint32_t	BGCLUT47;
	volatile	uint32_t	BGCLUT48;
	volatile	uint32_t	BGCLUT49;
	volatile	uint32_t	BGCLUT50;
	volatile	uint32_t	BGCLUT51;
	volatile	uint32_t	BGCLUT52;
	volatile	uint32_t	BGCLUT53;
	volatile	uint32_t	BGCLUT54;
	volatile	uint32_t	BGCLUT55;
	volatile	uint32_t	BGCLUT56;
	volatile	uint32_t	BGCLUT57;
	volatile	uint32_t	BGCLUT58;
	volatile	uint32_t	BGCLUT59;
	volatile	uint32_t	BGCLUT60;
	volatile	uint32_t	BGCLUT61;
	volatile	uint32_t	BGCLUT62;
	volatile	uint32_t	BGCLUT63;
	volatile	uint32_t	BGCLUT64;
	volatile	uint32_t	BGCLUT65;
	volatile	uint32_t	BGCLUT66;
	volatile	uint32_t	BGCLUT67;
	volatile	uint32_t	BGCLUT68;
	volatile	uint32_t	BGCLUT69;
	volatile	uint32_t	BGCLUT70;
	volatile	uint32_t	BGCLUT71;
	volatile	uint32_t	BGCLUT72;
	volatile	uint32_t	BGCLUT73;
	volatile	uint32_t	BGCLUT74;
	volatile	uint32_t	BGCLUT75;
	volatile	uint32_t	BGCLUT76;
	volatile	uint32_t	BGCLUT77;
	volatile	uint32_t	BGCLUT78;
	volatile	uint32_t	BGCLUT79;
	volatile	uint32_t	BGCLUT80;
	volatile	uint32_t	BGCLUT81;
	volatile	uint32_t	BGCLUT82;
	volatile	uint32_t	BGCLUT83;
	volatile	uint32_t	BGCLUT84;
	volatile	uint32_t	BGCLUT85;
	volatile	uint32_t	BGCLUT86;
	volatile	uint32_t	BGCLUT87;
	volatile	uint32_t	BGCLUT88;
	volatile	uint32_t	BGCLUT89;
	volatile	uint32_t	BGCLUT90;
	volatile	uint32_t	BGCLUT91;
	volatile	uint32_t	BGCLUT92;
	volatile	uint32_t	BGCLUT93;
	volatile	uint32_t	BGCLUT94;
	volatile	uint32_t	BGCLUT95;
	volatile	uint32_t	BGCLUT96;
	volatile	uint32_t	BGCLUT97;
	volatile	uint32_t	BGCLUT98;
	volatile	uint32_t	BGCLUT99;
	volatile	uint32_t	BGCLUT100;
	volatile	uint32_t	BGCLUT101;
	volatile	uint32_t	BGCLUT102;
	volatile	uint32_t	BGCLUT103;
	volatile	uint32_t	BGCLUT104;
	volatile	uint32_t	BGCLUT105;
	volatile	uint32_t	BGCLUT106;
	volatile	uint32_t	BGCLUT107;
	volatile	uint32_t	BGCLUT108;
	volatile	uint32_t	BGCLUT109;
	volatile	uint32_t	BGCLUT110;
	volatile	uint32_t	BGCLUT111;
	volatile	uint32_t	BGCLUT112;
	volatile	uint32_t	BGCLUT113;
	volatile	uint32_t	BGCLUT114;
	volatile	uint32_t	BGCLUT115;
	volatile	uint32_t	BGCLUT116;
	volatile	uint32_t	BGCLUT117;
	volatile	uint32_t	BGCLUT118;
	volatile	uint32_t	BGCLUT119;
	volatile	uint32_t	BGCLUT120;
	volatile	uint32_t	BGCLUT121;
	volatile	uint32_t	BGCLUT122;
	volatile	uint32_t	BGCLUT123;
	volatile	uint32_t	BGCLUT124;
	volatile	uint32_t	BGCLUT125;
	volatile	uint32_t	BGCLUT126;
	volatile	uint32_t	BGCLUT127;
	volatile	uint32_t	BGCLUT128;
	volatile	uint32_t	BGCLUT129;
	volatile	uint32_t	BGCLUT130;
	volatile	uint32_t	BGCLUT131;
	volatile	uint32_t	BGCLUT132;
	volatile	uint32_t	BGCLUT133;
	volatile	uint32_t	BGCLUT134;
	volatile	uint32_t	BGCLUT135;
	volatile	uint32_t	BGCLUT136;
	volatile	uint32_t	BGCLUT137;
	volatile	uint32_t	BGCLUT138;
	volatile	uint32_t	BGCLUT139;
	volatile	uint32_t	BGCLUT140;
	volatile	uint32_t	BGCLUT141;
	volatile	uint32_t	BGCLUT142;
	volatile	uint32_t	BGCLUT143;
	volatile	uint32_t	BGCLUT144;
	volatile	uint32_t	BGCLUT145;
	volatile	uint32_t	BGCLUT146;
	volatile	uint32_t	BGCLUT147;
	volatile	uint32_t	BGCLUT148;
	volatile	uint32_t	BGCLUT149;
	volatile	uint32_t	BGCLUT150;
	volatile	uint32_t	BGCLUT151;
	volatile	uint32_t	BGCLUT152;
	volatile	uint32_t	BGCLUT153;
	volatile	uint32_t	BGCLUT154;
	volatile	uint32_t	BGCLUT155;
	volatile	uint32_t	BGCLUT156;
	volatile	uint32_t	BGCLUT157;
	volatile	uint32_t	BGCLUT158;
	volatile	uint32_t	BGCLUT159;
	volatile	uint32_t	BGCLUT160;
	volatile	uint32_t	BGCLUT161;
	volatile	uint32_t	BGCLUT162;
	volatile	uint32_t	BGCLUT163;
	volatile	uint32_t	BGCLUT164;
	volatile	uint32_t	BGCLUT165;
	volatile	uint32_t	BGCLUT166;
	volatile	uint32_t	BGCLUT167;
	volatile	uint32_t	BGCLUT168;
	volatile	uint32_t	BGCLUT169;
	volatile	uint32_t	BGCLUT170;
	volatile	uint32_t	BGCLUT171;
	volatile	uint32_t	BGCLUT172;
	volatile	uint32_t	BGCLUT173;
	volatile	uint32_t	BGCLUT174;
	volatile	uint32_t	BGCLUT175;
	volatile	uint32_t	BGCLUT176;
	volatile	uint32_t	BGCLUT177;
	volatile	uint32_t	BGCLUT178;
	volatile	uint32_t	BGCLUT179;
	volatile	uint32_t	BGCLUT180;
	volatile	uint32_t	BGCLUT181;
	volatile	uint32_t	BGCLUT182;
	volatile	uint32_t	BGCLUT183;
	volatile	uint32_t	BGCLUT184;
	volatile	uint32_t	BGCLUT185;
	volatile	uint32_t	BGCLUT186;
	volatile	uint32_t	BGCLUT187;
	volatile	uint32_t	BGCLUT188;
	volatile	uint32_t	BGCLUT189;
	volatile	uint32_t	BGCLUT190;
	volatile	uint32_t	BGCLUT191;
	volatile	uint32_t	BGCLUT192;
	volatile	uint32_t	BGCLUT193;
	volatile	uint32_t	BGCLUT194;
	volatile	uint32_t	BGCLUT195;
	volatile	uint32_t	BGCLUT196;
	volatile	uint32_t	BGCLUT197;
	volatile	uint32_t	BGCLUT198;
	volatile	uint32_t	BGCLUT199;
	volatile	uint32_t	BGCLUT200;
	volatile	uint32_t	BGCLUT201;
	volatile	uint32_t	BGCLUT202;
	volatile	uint32_t	BGCLUT203;
	volatile	uint32_t	BGCLUT204;
	volatile	uint32_t	BGCLUT205;
	volatile	uint32_t	BGCLUT206;
	volatile	uint32_t	BGCLUT207;
	volatile	uint32_t	BGCLUT208;
	volatile	uint32_t	BGCLUT209;
	volatile	uint32_t	BGCLUT210;
	volatile	uint32_t	BGCLUT211;
	volatile	uint32_t	BGCLUT212;
	volatile	uint32_t	BGCLUT213;
	volatile	uint32_t	BGCLUT214;
	volatile	uint32_t	BGCLUT215;
	volatile	uint32_t	BGCLUT216;
	volatile	uint32_t	BGCLUT217;
	volatile	uint32_t	BGCLUT218;
	volatile	uint32_t	BGCLUT219;
	volatile	uint32_t	BGCLUT220;
	volatile	uint32_t	BGCLUT221;
	volatile	uint32_t	BGCLUT222;
	volatile	uint32_t	BGCLUT223;
	volatile	uint32_t	BGCLUT224;
	volatile	uint32_t	BGCLUT225;
	volatile	uint32_t	BGCLUT226;
	volatile	uint32_t	BGCLUT227;
	volatile	uint32_t	BGCLUT228;
	volatile	uint32_t	BGCLUT229;
	volatile	uint32_t	BGCLUT230;
	volatile	uint32_t	BGCLUT231;
	volatile	uint32_t	BGCLUT232;
	volatile	uint32_t	BGCLUT233;
	volatile	uint32_t	BGCLUT234;
	volatile	uint32_t	BGCLUT235;
	volatile	uint32_t	BGCLUT236;
	volatile	uint32_t	BGCLUT237;
	volatile	uint32_t	BGCLUT238;
	volatile	uint32_t	BGCLUT239;
	volatile	uint32_t	BGCLUT240;
	volatile	uint32_t	BGCLUT241;
	volatile	uint32_t	BGCLUT242;
	volatile	uint32_t	BGCLUT243;
	volatile	uint32_t	BGCLUT244;
	volatile	uint32_t	BGCLUT245;
	volatile	uint32_t	BGCLUT246;
	volatile	uint32_t	BGCLUT247;
	volatile	uint32_t	BGCLUT248;
	volatile	uint32_t	BGCLUT249;
	volatile	uint32_t	BGCLUT250;
	volatile	uint32_t	BGCLUT251;
	volatile	uint32_t	BGCLUT252;
	volatile	uint32_t	BGCLUT253;
	volatile	uint32_t	BGCLUT254;
	volatile	uint32_t	BGCLUT255;
} DMA2D_TypeDef;

#if (defined(__cplusplus))
#define	DMA2D_NS	reinterpret_cast<DMA2D_TypeDef *>(0x48021000u)
#define	DMA2D_S		reinterpret_cast<DMA2D_TypeDef *>(0x58021000u)

#else
#define	DMA2D_NS	((DMA2D_TypeDef *)0x48021000u)
#define	DMA2D_S		((DMA2D_TypeDef *)0x58021000u)
#endif

// CR Configuration

#define	DMA2D_CR_MODE				(0x7u<<16)
#define	DMA2D_CR_MODE_0				(0x1u<<16)
#define	DMA2D_CR_CEIE				(0x1u<<13)
#define	DMA2D_CR_CTCIE				(0x1u<<12)
#define	DMA2D_CR_CAEIE				(0x1u<<11)
#define	DMA2D_CR_TWIE				(0x1u<<10)
#define	DMA2D_CR_TCIE				(0x1u<<9)
#define	DMA2D_CR_TEIE				(0x1u<<8)
#define	DMA2D_CR_LOM				(0x1u<<6)
#define	DMA2D_CR_ABORT				(0x1u<<2)
#define	DMA2D_CR_SUSP				(0x1u<<1)
#define	DMA2D_CR_START				(0x1u<<0)

#define	DMA2D_CR_MODE_B_0X0			(0x0u<<16)
#define	DMA2D_CR_MODE_B_0X1			(0x1u<<16)
#define	DMA2D_CR_MODE_B_0X2			(0x2u<<16)
#define	DMA2D_CR_MODE_B_0X3			(0x3u<<16)
#define	DMA2D_CR_MODE_B_0X4			(0x4u<<16)
#define	DMA2D_CR_MODE_B_0X5			(0x5u<<16)
#define	DMA2D_CR_CEIE_B_0X0			(0x0u<<13)
#define	DMA2D_CR_CEIE_B_0X1			(0x1u<<13)
#define	DMA2D_CR_CTCIE_B_0X0		(0x0u<<12)
#define	DMA2D_CR_CTCIE_B_0X1		(0x1u<<12)
#define	DMA2D_CR_CAEIE_B_0X0		(0x0u<<11)
#define	DMA2D_CR_CAEIE_B_0X1		(0x1u<<11)
#define	DMA2D_CR_TWIE_B_0X0			(0x0u<<10)
#define	DMA2D_CR_TWIE_B_0X1			(0x1u<<10)
#define	DMA2D_CR_TCIE_B_0X0			(0x0u<<9)
#define	DMA2D_CR_TCIE_B_0X1			(0x1u<<9)
#define	DMA2D_CR_TEIE_B_0X0			(0x0u<<8)
#define	DMA2D_CR_TEIE_B_0X1			(0x1u<<8)
#define	DMA2D_CR_LOM_B_0X0			(0x0u<<6)
#define	DMA2D_CR_LOM_B_0X1			(0x1u<<6)
#define	DMA2D_CR_ABORT_B_0X0		(0x0u<<2)
#define	DMA2D_CR_ABORT_B_0X1		(0x1u<<2)
#define	DMA2D_CR_SUSP_B_0X0			(0x0u<<1)
#define	DMA2D_CR_SUSP_B_0X1			(0x1u<<1)

// ISR Configuration

#define	DMA2D_ISR_CEIF				(0x1u<<5)
#define	DMA2D_ISR_CTCIF				(0x1u<<4)
#define	DMA2D_ISR_CAEIF				(0x1u<<3)
#define	DMA2D_ISR_TWIF				(0x1u<<2)
#define	DMA2D_ISR_TCIF				(0x1u<<1)
#define	DMA2D_ISR_TEIF				(0x1u<<0)

// IFCR Configuration

#define	DMA2D_IFCR_CCEIF			(0x1u<<5)
#define	DMA2D_IFCR_CCTCIF			(0x1u<<4)
#define	DMA2D_IFCR_CAECIF			(0x1u<<3)
#define	DMA2D_IFCR_CTWIF			(0x1u<<2)
#define	DMA2D_IFCR_CTCIF			(0x1u<<1)
#define	DMA2D_IFCR_CTEIF			(0x1u<<0)

// FGMAR Configuration

#define	DMA2D_FGMAR_MA				(0xFFFFFFFFu<<0)
#define	DMA2D_FGMAR_MA_0			(0x1u<<0)

// FGOR Configuration

#define	DMA2D_FGOR_LO				(0xFFFFu<<0)
#define	DMA2D_FGOR_LO_0				(0x1u<<0)

// BGMAR Configuration

#define	DMA2D_BGMAR_MA				(0xFFFFFFFFu<<0)
#define	DMA2D_BGMAR_MA_0			(0x1u<<0)

// BGOR Configuration

#define	DMA2D_BGOR_LO				(0xFFFFu<<0)
#define	DMA2D_BGOR_LO_0				(0x1u<<0)

// FGPFCCR Configuration

#define	DMA2D_FGPFCCR_ALPHA			(0xFFu<<24)
#define	DMA2D_FGPFCCR_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGPFCCR_RBS			(0x1u<<21)
#define	DMA2D_FGPFCCR_AI			(0x1u<<20)
#define	DMA2D_FGPFCCR_CSS			(0x3u<<18)
#define	DMA2D_FGPFCCR_CSS_0			(0x1u<<18)
#define	DMA2D_FGPFCCR_AM			(0x3u<<16)
#define	DMA2D_FGPFCCR_AM_0			(0x1u<<16)
#define	DMA2D_FGPFCCR_CS			(0xFFu<<8)
#define	DMA2D_FGPFCCR_CS_0			(0x1u<<8)
#define	DMA2D_FGPFCCR_START			(0x1u<<5)
#define	DMA2D_FGPFCCR_CCM			(0x1u<<4)
#define	DMA2D_FGPFCCR_CM			(0xFu<<0)
#define	DMA2D_FGPFCCR_CM_0			(0x1u<<0)

#define	DMA2D_FGPFCCR_RBS_B_0X0		(0x0u<<21)
#define	DMA2D_FGPFCCR_RBS_B_0X1		(0x1u<<21)
#define	DMA2D_FGPFCCR_AI_B_0X0		(0x0u<<20)
#define	DMA2D_FGPFCCR_AI_B_0X1		(0x1u<<20)
#define	DMA2D_FGPFCCR_CSS_B_0X0		(0x0u<<18)
#define	DMA2D_FGPFCCR_CSS_B_0X1		(0x1u<<18)
#define	DMA2D_FGPFCCR_CSS_B_0X2		(0x2u<<18)
#define	DMA2D_FGPFCCR_AM_B_0X0		(0x0u<<16)
#define	DMA2D_FGPFCCR_AM_B_0X1		(0x1u<<16)
#define	DMA2D_FGPFCCR_AM_B_0X2		(0x2u<<16)
#define	DMA2D_FGPFCCR_CCM_B_0X0		(0x0u<<4)
#define	DMA2D_FGPFCCR_CCM_B_0X1		(0x1u<<4)
#define	DMA2D_FGPFCCR_CM_B_0X0		(0x0u<<0)
#define	DMA2D_FGPFCCR_CM_B_0X1		(0x1u<<0)
#define	DMA2D_FGPFCCR_CM_B_0X2		(0x2u<<0)
#define	DMA2D_FGPFCCR_CM_B_0X3		(0x3u<<0)
#define	DMA2D_FGPFCCR_CM_B_0X4		(0x4u<<0)
#define	DMA2D_FGPFCCR_CM_B_0X5		(0x5u<<0)
#define	DMA2D_FGPFCCR_CM_B_0X6		(0x6u<<0)
#define	DMA2D_FGPFCCR_CM_B_0X7		(0x7u<<0)
#define	DMA2D_FGPFCCR_CM_B_0X8		(0x8u<<0)
#define	DMA2D_FGPFCCR_CM_B_0X9		(0x9u<<0)
#define	DMA2D_FGPFCCR_CM_B_0XA		(0xAu<<0)
#define	DMA2D_FGPFCCR_CM_B_0XB		(0xBu<<0)

// FGCOLR Configuration

#define	DMA2D_FGCOLR_RED			(0xFFu<<16)
#define	DMA2D_FGCOLR_RED_0			(0x1u<<16)
#define	DMA2D_FGCOLR_GREEN			(0xFFu<<8)
#define	DMA2D_FGCOLR_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCOLR_BLUE			(0xFFu<<0)
#define	DMA2D_FGCOLR_BLUE_0			(0x1u<<0)

// BGPFCCR Configuration

#define	DMA2D_BGPFCCR_ALPHA			(0xFFu<<24)
#define	DMA2D_BGPFCCR_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGPFCCR_RBS			(0x1u<<21)
#define	DMA2D_BGPFCCR_AI			(0x1u<<20)
#define	DMA2D_BGPFCCR_AM			(0x3u<<16)
#define	DMA2D_BGPFCCR_AM_0			(0x1u<<16)
#define	DMA2D_BGPFCCR_CS			(0xFFu<<8)
#define	DMA2D_BGPFCCR_CS_0			(0x1u<<8)
#define	DMA2D_BGPFCCR_START			(0x1u<<5)
#define	DMA2D_BGPFCCR_CCM			(0x1u<<4)
#define	DMA2D_BGPFCCR_CM			(0xFu<<0)
#define	DMA2D_BGPFCCR_CM_0			(0x1u<<0)

#define	DMA2D_BGPFCCR_RBS_B_0X0		(0x0u<<21)
#define	DMA2D_BGPFCCR_RBS_B_0X1		(0x1u<<21)
#define	DMA2D_BGPFCCR_AI_B_0X0		(0x0u<<20)
#define	DMA2D_BGPFCCR_AI_B_0X1		(0x1u<<20)
#define	DMA2D_BGPFCCR_AM_B_0X0		(0x0u<<16)
#define	DMA2D_BGPFCCR_AM_B_0X1		(0x1u<<16)
#define	DMA2D_BGPFCCR_AM_B_0X2		(0x2u<<16)
#define	DMA2D_BGPFCCR_CCM_B_0X0		(0x0u<<4)
#define	DMA2D_BGPFCCR_CCM_B_0X1		(0x1u<<4)
#define	DMA2D_BGPFCCR_CM_B_0X0		(0x0u<<0)
#define	DMA2D_BGPFCCR_CM_B_0X1		(0x1u<<0)
#define	DMA2D_BGPFCCR_CM_B_0X2		(0x2u<<0)
#define	DMA2D_BGPFCCR_CM_B_0X3		(0x3u<<0)
#define	DMA2D_BGPFCCR_CM_B_0X4		(0x4u<<0)
#define	DMA2D_BGPFCCR_CM_B_0X5		(0x5u<<0)
#define	DMA2D_BGPFCCR_CM_B_0X6		(0x6u<<0)
#define	DMA2D_BGPFCCR_CM_B_0X7		(0x7u<<0)
#define	DMA2D_BGPFCCR_CM_B_0X8		(0x8u<<0)
#define	DMA2D_BGPFCCR_CM_B_0X9		(0x9u<<0)
#define	DMA2D_BGPFCCR_CM_B_0XA		(0xAu<<0)

// BGCOLR Configuration

#define	DMA2D_BGCOLR_RED			(0xFFu<<16)
#define	DMA2D_BGCOLR_RED_0			(0x1u<<16)
#define	DMA2D_BGCOLR_GREEN			(0xFFu<<8)
#define	DMA2D_BGCOLR_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCOLR_BLUE			(0xFFu<<0)
#define	DMA2D_BGCOLR_BLUE_0			(0x1u<<0)

// FGCMAR Configuration

#define	DMA2D_FGCMAR_MA				(0xFFFFFFFFu<<0)
#define	DMA2D_FGCMAR_MA_0			(0x1u<<0)

// BGCMAR Configuration

#define	DMA2D_BGCMAR_MA				(0xFFFFFFFFu<<0)
#define	DMA2D_BGCMAR_MA_0			(0x1u<<0)

// OPFCCR Configuration

#define	DMA2D_OPFCCR_RBS			(0x1u<<21)
#define	DMA2D_OPFCCR_AI				(0x1u<<20)
#define	DMA2D_OPFCCR_SB				(0x1u<<8)
#define	DMA2D_OPFCCR_CM				(0x7u<<0)
#define	DMA2D_OPFCCR_CM_0			(0x1u<<0)

#define	DMA2D_OPFCCR_RBS_B_0X0		(0x0u<<21)
#define	DMA2D_OPFCCR_RBS_B_0X1		(0x1u<<21)
#define	DMA2D_OPFCCR_AI_B_0X0		(0x0u<<20)
#define	DMA2D_OPFCCR_AI_B_0X1		(0x1u<<20)
#define	DMA2D_OPFCCR_SB_B_0X0		(0x0u<<8)
#define	DMA2D_OPFCCR_SB_B_0X1		(0x1u<<8)
#define	DMA2D_OPFCCR_CM_B_0X0		(0x0u<<0)
#define	DMA2D_OPFCCR_CM_B_0X1		(0x1u<<0)
#define	DMA2D_OPFCCR_CM_B_0X2		(0x2u<<0)
#define	DMA2D_OPFCCR_CM_B_0X3		(0x3u<<0)
#define	DMA2D_OPFCCR_CM_B_0X4		(0x4u<<0)

// OCOLR Configuration

#define	DMA2D_OCOLR_ALPHA			(0xFFu<<24)
#define	DMA2D_OCOLR_ALPHA_0			(0x1u<<24)
#define	DMA2D_OCOLR_RED				(0xFFu<<16)
#define	DMA2D_OCOLR_RED_0			(0x1u<<16)
#define	DMA2D_OCOLR_GREEN			(0xFFu<<8)
#define	DMA2D_OCOLR_GREEN_0			(0x1u<<8)
#define	DMA2D_OCOLR_BLUE			(0xFFu<<0)
#define	DMA2D_OCOLR_BLUE_0			(0x1u<<0)

// OMAR Configuration

#define	DMA2D_OMAR_MA				(0xFFFFFFFFu<<0)
#define	DMA2D_OMAR_MA_0				(0x1u<<0)

// OOR Configuration

#define	DMA2D_OOR_LO				(0xFFFFu<<0)
#define	DMA2D_OOR_LO_0				(0x1u<<0)

// NLR Configuration

#define	DMA2D_NLR_PL				(0x3FFFu<<16)
#define	DMA2D_NLR_PL_0				(0x1u<<16)
#define	DMA2D_NLR_NL				(0xFFFFu<<0)
#define	DMA2D_NLR_NL_0				(0x1u<<0)

// LWR Configuration

#define	DMA2D_LWR_LW				(0xFFFFu<<0)
#define	DMA2D_LWR_LW_0				(0x1u<<0)

// AMTCR Configuration

#define	DMA2D_AMTCR_DT				(0xFFu<<8)
#define	DMA2D_AMTCR_DT_0			(0x1u<<8)
#define	DMA2D_AMTCR_EN				(0x1u<<0)

// FGCLUT0 Configuration

#define	DMA2D_FGCLUT0_ALPHA			(0xFFu<<24)
#define	DMA2D_FGCLUT0_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT0_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT0_RED_0			(0x1u<<16)
#define	DMA2D_FGCLUT0_GREEN			(0xFFu<<8)
#define	DMA2D_FGCLUT0_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT0_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT0_BLUE_0		(0x1u<<0)

// FGCLUT1 Configuration

#define	DMA2D_FGCLUT1_ALPHA			(0xFFu<<24)
#define	DMA2D_FGCLUT1_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT1_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT1_RED_0			(0x1u<<16)
#define	DMA2D_FGCLUT1_GREEN			(0xFFu<<8)
#define	DMA2D_FGCLUT1_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT1_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT1_BLUE_0		(0x1u<<0)

// FGCLUT2 Configuration

#define	DMA2D_FGCLUT2_ALPHA			(0xFFu<<24)
#define	DMA2D_FGCLUT2_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT2_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT2_RED_0			(0x1u<<16)
#define	DMA2D_FGCLUT2_GREEN			(0xFFu<<8)
#define	DMA2D_FGCLUT2_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT2_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT2_BLUE_0		(0x1u<<0)

// FGCLUT3 Configuration

#define	DMA2D_FGCLUT3_ALPHA			(0xFFu<<24)
#define	DMA2D_FGCLUT3_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT3_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT3_RED_0			(0x1u<<16)
#define	DMA2D_FGCLUT3_GREEN			(0xFFu<<8)
#define	DMA2D_FGCLUT3_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT3_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT3_BLUE_0		(0x1u<<0)

// FGCLUT4 Configuration

#define	DMA2D_FGCLUT4_ALPHA			(0xFFu<<24)
#define	DMA2D_FGCLUT4_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT4_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT4_RED_0			(0x1u<<16)
#define	DMA2D_FGCLUT4_GREEN			(0xFFu<<8)
#define	DMA2D_FGCLUT4_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT4_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT4_BLUE_0		(0x1u<<0)

// FGCLUT5 Configuration

#define	DMA2D_FGCLUT5_ALPHA			(0xFFu<<24)
#define	DMA2D_FGCLUT5_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT5_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT5_RED_0			(0x1u<<16)
#define	DMA2D_FGCLUT5_GREEN			(0xFFu<<8)
#define	DMA2D_FGCLUT5_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT5_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT5_BLUE_0		(0x1u<<0)

// FGCLUT6 Configuration

#define	DMA2D_FGCLUT6_ALPHA			(0xFFu<<24)
#define	DMA2D_FGCLUT6_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT6_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT6_RED_0			(0x1u<<16)
#define	DMA2D_FGCLUT6_GREEN			(0xFFu<<8)
#define	DMA2D_FGCLUT6_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT6_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT6_BLUE_0		(0x1u<<0)

// FGCLUT7 Configuration

#define	DMA2D_FGCLUT7_ALPHA			(0xFFu<<24)
#define	DMA2D_FGCLUT7_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT7_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT7_RED_0			(0x1u<<16)
#define	DMA2D_FGCLUT7_GREEN			(0xFFu<<8)
#define	DMA2D_FGCLUT7_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT7_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT7_BLUE_0		(0x1u<<0)

// FGCLUT8 Configuration

#define	DMA2D_FGCLUT8_ALPHA			(0xFFu<<24)
#define	DMA2D_FGCLUT8_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT8_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT8_RED_0			(0x1u<<16)
#define	DMA2D_FGCLUT8_GREEN			(0xFFu<<8)
#define	DMA2D_FGCLUT8_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT8_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT8_BLUE_0		(0x1u<<0)

// FGCLUT9 Configuration

#define	DMA2D_FGCLUT9_ALPHA			(0xFFu<<24)
#define	DMA2D_FGCLUT9_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT9_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT9_RED_0			(0x1u<<16)
#define	DMA2D_FGCLUT9_GREEN			(0xFFu<<8)
#define	DMA2D_FGCLUT9_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT9_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT9_BLUE_0		(0x1u<<0)

// FGCLUT10 Configuration

#define	DMA2D_FGCLUT10_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT10_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT10_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT10_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT10_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT10_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT10_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT10_BLUE_0		(0x1u<<0)

// FGCLUT11 Configuration

#define	DMA2D_FGCLUT11_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT11_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT11_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT11_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT11_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT11_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT11_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT11_BLUE_0		(0x1u<<0)

// FGCLUT12 Configuration

#define	DMA2D_FGCLUT12_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT12_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT12_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT12_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT12_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT12_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT12_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT12_BLUE_0		(0x1u<<0)

// FGCLUT13 Configuration

#define	DMA2D_FGCLUT13_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT13_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT13_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT13_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT13_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT13_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT13_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT13_BLUE_0		(0x1u<<0)

// FGCLUT14 Configuration

#define	DMA2D_FGCLUT14_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT14_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT14_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT14_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT14_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT14_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT14_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT14_BLUE_0		(0x1u<<0)

// FGCLUT15 Configuration

#define	DMA2D_FGCLUT15_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT15_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT15_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT15_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT15_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT15_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT15_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT15_BLUE_0		(0x1u<<0)

// FGCLUT16 Configuration

#define	DMA2D_FGCLUT16_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT16_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT16_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT16_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT16_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT16_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT16_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT16_BLUE_0		(0x1u<<0)

// FGCLUT17 Configuration

#define	DMA2D_FGCLUT17_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT17_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT17_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT17_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT17_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT17_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT17_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT17_BLUE_0		(0x1u<<0)

// FGCLUT18 Configuration

#define	DMA2D_FGCLUT18_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT18_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT18_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT18_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT18_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT18_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT18_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT18_BLUE_0		(0x1u<<0)

// FGCLUT19 Configuration

#define	DMA2D_FGCLUT19_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT19_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT19_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT19_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT19_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT19_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT19_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT19_BLUE_0		(0x1u<<0)

// FGCLUT20 Configuration

#define	DMA2D_FGCLUT20_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT20_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT20_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT20_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT20_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT20_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT20_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT20_BLUE_0		(0x1u<<0)

// FGCLUT21 Configuration

#define	DMA2D_FGCLUT21_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT21_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT21_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT21_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT21_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT21_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT21_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT21_BLUE_0		(0x1u<<0)

// FGCLUT22 Configuration

#define	DMA2D_FGCLUT22_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT22_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT22_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT22_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT22_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT22_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT22_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT22_BLUE_0		(0x1u<<0)

// FGCLUT23 Configuration

#define	DMA2D_FGCLUT23_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT23_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT23_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT23_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT23_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT23_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT23_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT23_BLUE_0		(0x1u<<0)

// FGCLUT24 Configuration

#define	DMA2D_FGCLUT24_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT24_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT24_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT24_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT24_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT24_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT24_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT24_BLUE_0		(0x1u<<0)

// FGCLUT25 Configuration

#define	DMA2D_FGCLUT25_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT25_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT25_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT25_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT25_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT25_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT25_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT25_BLUE_0		(0x1u<<0)

// FGCLUT26 Configuration

#define	DMA2D_FGCLUT26_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT26_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT26_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT26_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT26_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT26_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT26_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT26_BLUE_0		(0x1u<<0)

// FGCLUT27 Configuration

#define	DMA2D_FGCLUT27_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT27_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT27_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT27_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT27_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT27_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT27_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT27_BLUE_0		(0x1u<<0)

// FGCLUT28 Configuration

#define	DMA2D_FGCLUT28_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT28_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT28_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT28_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT28_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT28_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT28_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT28_BLUE_0		(0x1u<<0)

// FGCLUT29 Configuration

#define	DMA2D_FGCLUT29_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT29_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT29_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT29_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT29_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT29_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT29_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT29_BLUE_0		(0x1u<<0)

// FGCLUT30 Configuration

#define	DMA2D_FGCLUT30_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT30_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT30_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT30_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT30_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT30_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT30_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT30_BLUE_0		(0x1u<<0)

// FGCLUT31 Configuration

#define	DMA2D_FGCLUT31_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT31_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT31_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT31_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT31_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT31_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT31_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT31_BLUE_0		(0x1u<<0)

// FGCLUT32 Configuration

#define	DMA2D_FGCLUT32_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT32_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT32_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT32_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT32_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT32_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT32_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT32_BLUE_0		(0x1u<<0)

// FGCLUT33 Configuration

#define	DMA2D_FGCLUT33_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT33_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT33_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT33_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT33_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT33_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT33_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT33_BLUE_0		(0x1u<<0)

// FGCLUT34 Configuration

#define	DMA2D_FGCLUT34_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT34_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT34_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT34_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT34_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT34_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT34_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT34_BLUE_0		(0x1u<<0)

// FGCLUT35 Configuration

#define	DMA2D_FGCLUT35_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT35_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT35_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT35_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT35_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT35_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT35_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT35_BLUE_0		(0x1u<<0)

// FGCLUT36 Configuration

#define	DMA2D_FGCLUT36_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT36_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT36_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT36_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT36_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT36_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT36_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT36_BLUE_0		(0x1u<<0)

// FGCLUT37 Configuration

#define	DMA2D_FGCLUT37_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT37_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT37_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT37_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT37_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT37_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT37_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT37_BLUE_0		(0x1u<<0)

// FGCLUT38 Configuration

#define	DMA2D_FGCLUT38_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT38_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT38_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT38_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT38_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT38_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT38_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT38_BLUE_0		(0x1u<<0)

// FGCLUT39 Configuration

#define	DMA2D_FGCLUT39_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT39_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT39_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT39_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT39_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT39_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT39_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT39_BLUE_0		(0x1u<<0)

// FGCLUT40 Configuration

#define	DMA2D_FGCLUT40_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT40_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT40_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT40_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT40_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT40_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT40_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT40_BLUE_0		(0x1u<<0)

// FGCLUT41 Configuration

#define	DMA2D_FGCLUT41_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT41_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT41_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT41_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT41_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT41_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT41_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT41_BLUE_0		(0x1u<<0)

// FGCLUT42 Configuration

#define	DMA2D_FGCLUT42_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT42_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT42_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT42_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT42_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT42_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT42_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT42_BLUE_0		(0x1u<<0)

// FGCLUT43 Configuration

#define	DMA2D_FGCLUT43_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT43_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT43_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT43_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT43_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT43_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT43_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT43_BLUE_0		(0x1u<<0)

// FGCLUT44 Configuration

#define	DMA2D_FGCLUT44_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT44_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT44_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT44_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT44_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT44_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT44_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT44_BLUE_0		(0x1u<<0)

// FGCLUT45 Configuration

#define	DMA2D_FGCLUT45_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT45_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT45_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT45_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT45_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT45_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT45_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT45_BLUE_0		(0x1u<<0)

// FGCLUT46 Configuration

#define	DMA2D_FGCLUT46_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT46_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT46_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT46_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT46_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT46_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT46_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT46_BLUE_0		(0x1u<<0)

// FGCLUT47 Configuration

#define	DMA2D_FGCLUT47_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT47_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT47_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT47_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT47_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT47_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT47_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT47_BLUE_0		(0x1u<<0)

// FGCLUT48 Configuration

#define	DMA2D_FGCLUT48_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT48_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT48_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT48_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT48_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT48_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT48_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT48_BLUE_0		(0x1u<<0)

// FGCLUT49 Configuration

#define	DMA2D_FGCLUT49_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT49_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT49_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT49_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT49_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT49_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT49_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT49_BLUE_0		(0x1u<<0)

// FGCLUT50 Configuration

#define	DMA2D_FGCLUT50_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT50_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT50_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT50_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT50_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT50_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT50_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT50_BLUE_0		(0x1u<<0)

// FGCLUT51 Configuration

#define	DMA2D_FGCLUT51_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT51_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT51_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT51_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT51_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT51_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT51_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT51_BLUE_0		(0x1u<<0)

// FGCLUT52 Configuration

#define	DMA2D_FGCLUT52_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT52_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT52_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT52_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT52_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT52_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT52_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT52_BLUE_0		(0x1u<<0)

// FGCLUT53 Configuration

#define	DMA2D_FGCLUT53_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT53_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT53_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT53_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT53_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT53_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT53_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT53_BLUE_0		(0x1u<<0)

// FGCLUT54 Configuration

#define	DMA2D_FGCLUT54_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT54_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT54_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT54_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT54_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT54_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT54_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT54_BLUE_0		(0x1u<<0)

// FGCLUT55 Configuration

#define	DMA2D_FGCLUT55_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT55_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT55_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT55_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT55_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT55_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT55_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT55_BLUE_0		(0x1u<<0)

// FGCLUT56 Configuration

#define	DMA2D_FGCLUT56_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT56_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT56_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT56_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT56_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT56_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT56_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT56_BLUE_0		(0x1u<<0)

// FGCLUT57 Configuration

#define	DMA2D_FGCLUT57_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT57_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT57_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT57_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT57_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT57_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT57_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT57_BLUE_0		(0x1u<<0)

// FGCLUT58 Configuration

#define	DMA2D_FGCLUT58_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT58_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT58_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT58_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT58_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT58_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT58_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT58_BLUE_0		(0x1u<<0)

// FGCLUT59 Configuration

#define	DMA2D_FGCLUT59_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT59_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT59_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT59_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT59_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT59_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT59_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT59_BLUE_0		(0x1u<<0)

// FGCLUT60 Configuration

#define	DMA2D_FGCLUT60_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT60_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT60_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT60_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT60_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT60_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT60_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT60_BLUE_0		(0x1u<<0)

// FGCLUT61 Configuration

#define	DMA2D_FGCLUT61_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT61_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT61_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT61_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT61_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT61_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT61_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT61_BLUE_0		(0x1u<<0)

// FGCLUT62 Configuration

#define	DMA2D_FGCLUT62_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT62_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT62_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT62_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT62_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT62_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT62_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT62_BLUE_0		(0x1u<<0)

// FGCLUT63 Configuration

#define	DMA2D_FGCLUT63_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT63_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT63_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT63_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT63_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT63_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT63_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT63_BLUE_0		(0x1u<<0)

// FGCLUT64 Configuration

#define	DMA2D_FGCLUT64_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT64_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT64_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT64_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT64_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT64_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT64_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT64_BLUE_0		(0x1u<<0)

// FGCLUT65 Configuration

#define	DMA2D_FGCLUT65_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT65_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT65_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT65_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT65_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT65_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT65_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT65_BLUE_0		(0x1u<<0)

// FGCLUT66 Configuration

#define	DMA2D_FGCLUT66_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT66_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT66_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT66_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT66_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT66_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT66_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT66_BLUE_0		(0x1u<<0)

// FGCLUT67 Configuration

#define	DMA2D_FGCLUT67_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT67_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT67_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT67_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT67_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT67_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT67_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT67_BLUE_0		(0x1u<<0)

// FGCLUT68 Configuration

#define	DMA2D_FGCLUT68_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT68_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT68_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT68_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT68_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT68_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT68_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT68_BLUE_0		(0x1u<<0)

// FGCLUT69 Configuration

#define	DMA2D_FGCLUT69_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT69_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT69_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT69_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT69_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT69_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT69_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT69_BLUE_0		(0x1u<<0)

// FGCLUT70 Configuration

#define	DMA2D_FGCLUT70_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT70_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT70_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT70_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT70_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT70_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT70_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT70_BLUE_0		(0x1u<<0)

// FGCLUT71 Configuration

#define	DMA2D_FGCLUT71_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT71_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT71_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT71_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT71_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT71_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT71_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT71_BLUE_0		(0x1u<<0)

// FGCLUT72 Configuration

#define	DMA2D_FGCLUT72_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT72_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT72_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT72_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT72_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT72_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT72_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT72_BLUE_0		(0x1u<<0)

// FGCLUT73 Configuration

#define	DMA2D_FGCLUT73_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT73_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT73_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT73_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT73_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT73_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT73_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT73_BLUE_0		(0x1u<<0)

// FGCLUT74 Configuration

#define	DMA2D_FGCLUT74_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT74_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT74_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT74_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT74_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT74_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT74_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT74_BLUE_0		(0x1u<<0)

// FGCLUT75 Configuration

#define	DMA2D_FGCLUT75_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT75_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT75_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT75_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT75_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT75_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT75_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT75_BLUE_0		(0x1u<<0)

// FGCLUT76 Configuration

#define	DMA2D_FGCLUT76_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT76_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT76_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT76_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT76_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT76_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT76_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT76_BLUE_0		(0x1u<<0)

// FGCLUT77 Configuration

#define	DMA2D_FGCLUT77_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT77_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT77_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT77_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT77_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT77_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT77_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT77_BLUE_0		(0x1u<<0)

// FGCLUT78 Configuration

#define	DMA2D_FGCLUT78_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT78_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT78_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT78_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT78_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT78_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT78_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT78_BLUE_0		(0x1u<<0)

// FGCLUT79 Configuration

#define	DMA2D_FGCLUT79_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT79_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT79_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT79_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT79_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT79_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT79_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT79_BLUE_0		(0x1u<<0)

// FGCLUT80 Configuration

#define	DMA2D_FGCLUT80_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT80_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT80_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT80_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT80_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT80_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT80_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT80_BLUE_0		(0x1u<<0)

// FGCLUT81 Configuration

#define	DMA2D_FGCLUT81_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT81_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT81_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT81_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT81_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT81_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT81_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT81_BLUE_0		(0x1u<<0)

// FGCLUT82 Configuration

#define	DMA2D_FGCLUT82_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT82_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT82_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT82_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT82_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT82_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT82_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT82_BLUE_0		(0x1u<<0)

// FGCLUT83 Configuration

#define	DMA2D_FGCLUT83_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT83_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT83_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT83_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT83_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT83_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT83_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT83_BLUE_0		(0x1u<<0)

// FGCLUT84 Configuration

#define	DMA2D_FGCLUT84_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT84_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT84_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT84_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT84_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT84_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT84_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT84_BLUE_0		(0x1u<<0)

// FGCLUT85 Configuration

#define	DMA2D_FGCLUT85_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT85_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT85_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT85_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT85_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT85_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT85_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT85_BLUE_0		(0x1u<<0)

// FGCLUT86 Configuration

#define	DMA2D_FGCLUT86_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT86_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT86_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT86_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT86_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT86_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT86_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT86_BLUE_0		(0x1u<<0)

// FGCLUT87 Configuration

#define	DMA2D_FGCLUT87_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT87_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT87_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT87_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT87_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT87_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT87_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT87_BLUE_0		(0x1u<<0)

// FGCLUT88 Configuration

#define	DMA2D_FGCLUT88_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT88_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT88_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT88_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT88_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT88_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT88_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT88_BLUE_0		(0x1u<<0)

// FGCLUT89 Configuration

#define	DMA2D_FGCLUT89_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT89_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT89_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT89_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT89_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT89_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT89_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT89_BLUE_0		(0x1u<<0)

// FGCLUT90 Configuration

#define	DMA2D_FGCLUT90_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT90_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT90_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT90_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT90_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT90_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT90_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT90_BLUE_0		(0x1u<<0)

// FGCLUT91 Configuration

#define	DMA2D_FGCLUT91_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT91_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT91_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT91_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT91_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT91_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT91_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT91_BLUE_0		(0x1u<<0)

// FGCLUT92 Configuration

#define	DMA2D_FGCLUT92_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT92_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT92_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT92_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT92_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT92_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT92_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT92_BLUE_0		(0x1u<<0)

// FGCLUT93 Configuration

#define	DMA2D_FGCLUT93_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT93_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT93_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT93_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT93_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT93_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT93_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT93_BLUE_0		(0x1u<<0)

// FGCLUT94 Configuration

#define	DMA2D_FGCLUT94_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT94_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT94_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT94_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT94_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT94_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT94_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT94_BLUE_0		(0x1u<<0)

// FGCLUT95 Configuration

#define	DMA2D_FGCLUT95_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT95_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT95_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT95_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT95_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT95_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT95_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT95_BLUE_0		(0x1u<<0)

// FGCLUT96 Configuration

#define	DMA2D_FGCLUT96_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT96_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT96_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT96_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT96_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT96_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT96_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT96_BLUE_0		(0x1u<<0)

// FGCLUT97 Configuration

#define	DMA2D_FGCLUT97_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT97_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT97_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT97_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT97_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT97_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT97_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT97_BLUE_0		(0x1u<<0)

// FGCLUT98 Configuration

#define	DMA2D_FGCLUT98_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT98_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT98_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT98_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT98_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT98_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT98_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT98_BLUE_0		(0x1u<<0)

// FGCLUT99 Configuration

#define	DMA2D_FGCLUT99_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT99_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT99_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT99_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT99_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT99_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT99_BLUE			(0xFFu<<0)
#define	DMA2D_FGCLUT99_BLUE_0		(0x1u<<0)

// FGCLUT100 Configuration

#define	DMA2D_FGCLUT100_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT100_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT100_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT100_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT100_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT100_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT100_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT100_BLUE_0		(0x1u<<0)

// FGCLUT101 Configuration

#define	DMA2D_FGCLUT101_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT101_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT101_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT101_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT101_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT101_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT101_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT101_BLUE_0		(0x1u<<0)

// FGCLUT102 Configuration

#define	DMA2D_FGCLUT102_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT102_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT102_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT102_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT102_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT102_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT102_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT102_BLUE_0		(0x1u<<0)

// FGCLUT103 Configuration

#define	DMA2D_FGCLUT103_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT103_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT103_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT103_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT103_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT103_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT103_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT103_BLUE_0		(0x1u<<0)

// FGCLUT104 Configuration

#define	DMA2D_FGCLUT104_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT104_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT104_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT104_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT104_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT104_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT104_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT104_BLUE_0		(0x1u<<0)

// FGCLUT105 Configuration

#define	DMA2D_FGCLUT105_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT105_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT105_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT105_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT105_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT105_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT105_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT105_BLUE_0		(0x1u<<0)

// FGCLUT106 Configuration

#define	DMA2D_FGCLUT106_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT106_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT106_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT106_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT106_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT106_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT106_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT106_BLUE_0		(0x1u<<0)

// FGCLUT107 Configuration

#define	DMA2D_FGCLUT107_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT107_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT107_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT107_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT107_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT107_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT107_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT107_BLUE_0		(0x1u<<0)

// FGCLUT108 Configuration

#define	DMA2D_FGCLUT108_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT108_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT108_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT108_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT108_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT108_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT108_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT108_BLUE_0		(0x1u<<0)

// FGCLUT109 Configuration

#define	DMA2D_FGCLUT109_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT109_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT109_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT109_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT109_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT109_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT109_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT109_BLUE_0		(0x1u<<0)

// FGCLUT110 Configuration

#define	DMA2D_FGCLUT110_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT110_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT110_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT110_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT110_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT110_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT110_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT110_BLUE_0		(0x1u<<0)

// FGCLUT111 Configuration

#define	DMA2D_FGCLUT111_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT111_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT111_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT111_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT111_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT111_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT111_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT111_BLUE_0		(0x1u<<0)

// FGCLUT112 Configuration

#define	DMA2D_FGCLUT112_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT112_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT112_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT112_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT112_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT112_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT112_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT112_BLUE_0		(0x1u<<0)

// FGCLUT113 Configuration

#define	DMA2D_FGCLUT113_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT113_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT113_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT113_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT113_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT113_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT113_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT113_BLUE_0		(0x1u<<0)

// FGCLUT114 Configuration

#define	DMA2D_FGCLUT114_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT114_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT114_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT114_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT114_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT114_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT114_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT114_BLUE_0		(0x1u<<0)

// FGCLUT115 Configuration

#define	DMA2D_FGCLUT115_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT115_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT115_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT115_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT115_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT115_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT115_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT115_BLUE_0		(0x1u<<0)

// FGCLUT116 Configuration

#define	DMA2D_FGCLUT116_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT116_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT116_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT116_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT116_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT116_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT116_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT116_BLUE_0		(0x1u<<0)

// FGCLUT117 Configuration

#define	DMA2D_FGCLUT117_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT117_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT117_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT117_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT117_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT117_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT117_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT117_BLUE_0		(0x1u<<0)

// FGCLUT118 Configuration

#define	DMA2D_FGCLUT118_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT118_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT118_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT118_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT118_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT118_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT118_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT118_BLUE_0		(0x1u<<0)

// FGCLUT119 Configuration

#define	DMA2D_FGCLUT119_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT119_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT119_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT119_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT119_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT119_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT119_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT119_BLUE_0		(0x1u<<0)

// FGCLUT120 Configuration

#define	DMA2D_FGCLUT120_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT120_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT120_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT120_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT120_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT120_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT120_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT120_BLUE_0		(0x1u<<0)

// FGCLUT121 Configuration

#define	DMA2D_FGCLUT121_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT121_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT121_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT121_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT121_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT121_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT121_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT121_BLUE_0		(0x1u<<0)

// FGCLUT122 Configuration

#define	DMA2D_FGCLUT122_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT122_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT122_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT122_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT122_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT122_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT122_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT122_BLUE_0		(0x1u<<0)

// FGCLUT123 Configuration

#define	DMA2D_FGCLUT123_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT123_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT123_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT123_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT123_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT123_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT123_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT123_BLUE_0		(0x1u<<0)

// FGCLUT124 Configuration

#define	DMA2D_FGCLUT124_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT124_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT124_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT124_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT124_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT124_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT124_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT124_BLUE_0		(0x1u<<0)

// FGCLUT125 Configuration

#define	DMA2D_FGCLUT125_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT125_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT125_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT125_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT125_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT125_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT125_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT125_BLUE_0		(0x1u<<0)

// FGCLUT126 Configuration

#define	DMA2D_FGCLUT126_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT126_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT126_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT126_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT126_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT126_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT126_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT126_BLUE_0		(0x1u<<0)

// FGCLUT127 Configuration

#define	DMA2D_FGCLUT127_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT127_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT127_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT127_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT127_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT127_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT127_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT127_BLUE_0		(0x1u<<0)

// FGCLUT128 Configuration

#define	DMA2D_FGCLUT128_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT128_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT128_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT128_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT128_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT128_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT128_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT128_BLUE_0		(0x1u<<0)

// FGCLUT129 Configuration

#define	DMA2D_FGCLUT129_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT129_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT129_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT129_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT129_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT129_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT129_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT129_BLUE_0		(0x1u<<0)

// FGCLUT130 Configuration

#define	DMA2D_FGCLUT130_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT130_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT130_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT130_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT130_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT130_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT130_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT130_BLUE_0		(0x1u<<0)

// FGCLUT131 Configuration

#define	DMA2D_FGCLUT131_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT131_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT131_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT131_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT131_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT131_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT131_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT131_BLUE_0		(0x1u<<0)

// FGCLUT132 Configuration

#define	DMA2D_FGCLUT132_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT132_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT132_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT132_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT132_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT132_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT132_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT132_BLUE_0		(0x1u<<0)

// FGCLUT133 Configuration

#define	DMA2D_FGCLUT133_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT133_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT133_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT133_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT133_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT133_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT133_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT133_BLUE_0		(0x1u<<0)

// FGCLUT134 Configuration

#define	DMA2D_FGCLUT134_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT134_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT134_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT134_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT134_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT134_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT134_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT134_BLUE_0		(0x1u<<0)

// FGCLUT135 Configuration

#define	DMA2D_FGCLUT135_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT135_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT135_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT135_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT135_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT135_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT135_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT135_BLUE_0		(0x1u<<0)

// FGCLUT136 Configuration

#define	DMA2D_FGCLUT136_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT136_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT136_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT136_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT136_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT136_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT136_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT136_BLUE_0		(0x1u<<0)

// FGCLUT137 Configuration

#define	DMA2D_FGCLUT137_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT137_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT137_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT137_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT137_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT137_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT137_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT137_BLUE_0		(0x1u<<0)

// FGCLUT138 Configuration

#define	DMA2D_FGCLUT138_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT138_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT138_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT138_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT138_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT138_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT138_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT138_BLUE_0		(0x1u<<0)

// FGCLUT139 Configuration

#define	DMA2D_FGCLUT139_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT139_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT139_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT139_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT139_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT139_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT139_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT139_BLUE_0		(0x1u<<0)

// FGCLUT140 Configuration

#define	DMA2D_FGCLUT140_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT140_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT140_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT140_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT140_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT140_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT140_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT140_BLUE_0		(0x1u<<0)

// FGCLUT141 Configuration

#define	DMA2D_FGCLUT141_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT141_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT141_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT141_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT141_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT141_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT141_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT141_BLUE_0		(0x1u<<0)

// FGCLUT142 Configuration

#define	DMA2D_FGCLUT142_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT142_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT142_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT142_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT142_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT142_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT142_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT142_BLUE_0		(0x1u<<0)

// FGCLUT143 Configuration

#define	DMA2D_FGCLUT143_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT143_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT143_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT143_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT143_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT143_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT143_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT143_BLUE_0		(0x1u<<0)

// FGCLUT144 Configuration

#define	DMA2D_FGCLUT144_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT144_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT144_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT144_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT144_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT144_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT144_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT144_BLUE_0		(0x1u<<0)

// FGCLUT145 Configuration

#define	DMA2D_FGCLUT145_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT145_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT145_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT145_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT145_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT145_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT145_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT145_BLUE_0		(0x1u<<0)

// FGCLUT146 Configuration

#define	DMA2D_FGCLUT146_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT146_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT146_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT146_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT146_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT146_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT146_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT146_BLUE_0		(0x1u<<0)

// FGCLUT147 Configuration

#define	DMA2D_FGCLUT147_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT147_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT147_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT147_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT147_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT147_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT147_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT147_BLUE_0		(0x1u<<0)

// FGCLUT148 Configuration

#define	DMA2D_FGCLUT148_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT148_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT148_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT148_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT148_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT148_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT148_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT148_BLUE_0		(0x1u<<0)

// FGCLUT149 Configuration

#define	DMA2D_FGCLUT149_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT149_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT149_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT149_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT149_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT149_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT149_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT149_BLUE_0		(0x1u<<0)

// FGCLUT150 Configuration

#define	DMA2D_FGCLUT150_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT150_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT150_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT150_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT150_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT150_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT150_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT150_BLUE_0		(0x1u<<0)

// FGCLUT151 Configuration

#define	DMA2D_FGCLUT151_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT151_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT151_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT151_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT151_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT151_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT151_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT151_BLUE_0		(0x1u<<0)

// FGCLUT152 Configuration

#define	DMA2D_FGCLUT152_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT152_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT152_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT152_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT152_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT152_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT152_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT152_BLUE_0		(0x1u<<0)

// FGCLUT153 Configuration

#define	DMA2D_FGCLUT153_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT153_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT153_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT153_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT153_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT153_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT153_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT153_BLUE_0		(0x1u<<0)

// FGCLUT154 Configuration

#define	DMA2D_FGCLUT154_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT154_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT154_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT154_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT154_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT154_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT154_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT154_BLUE_0		(0x1u<<0)

// FGCLUT155 Configuration

#define	DMA2D_FGCLUT155_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT155_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT155_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT155_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT155_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT155_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT155_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT155_BLUE_0		(0x1u<<0)

// FGCLUT156 Configuration

#define	DMA2D_FGCLUT156_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT156_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT156_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT156_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT156_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT156_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT156_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT156_BLUE_0		(0x1u<<0)

// FGCLUT157 Configuration

#define	DMA2D_FGCLUT157_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT157_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT157_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT157_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT157_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT157_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT157_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT157_BLUE_0		(0x1u<<0)

// FGCLUT158 Configuration

#define	DMA2D_FGCLUT158_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT158_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT158_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT158_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT158_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT158_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT158_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT158_BLUE_0		(0x1u<<0)

// FGCLUT159 Configuration

#define	DMA2D_FGCLUT159_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT159_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT159_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT159_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT159_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT159_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT159_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT159_BLUE_0		(0x1u<<0)

// FGCLUT160 Configuration

#define	DMA2D_FGCLUT160_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT160_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT160_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT160_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT160_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT160_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT160_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT160_BLUE_0		(0x1u<<0)

// FGCLUT161 Configuration

#define	DMA2D_FGCLUT161_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT161_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT161_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT161_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT161_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT161_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT161_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT161_BLUE_0		(0x1u<<0)

// FGCLUT162 Configuration

#define	DMA2D_FGCLUT162_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT162_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT162_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT162_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT162_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT162_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT162_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT162_BLUE_0		(0x1u<<0)

// FGCLUT163 Configuration

#define	DMA2D_FGCLUT163_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT163_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT163_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT163_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT163_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT163_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT163_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT163_BLUE_0		(0x1u<<0)

// FGCLUT164 Configuration

#define	DMA2D_FGCLUT164_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT164_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT164_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT164_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT164_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT164_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT164_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT164_BLUE_0		(0x1u<<0)

// FGCLUT165 Configuration

#define	DMA2D_FGCLUT165_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT165_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT165_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT165_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT165_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT165_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT165_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT165_BLUE_0		(0x1u<<0)

// FGCLUT166 Configuration

#define	DMA2D_FGCLUT166_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT166_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT166_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT166_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT166_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT166_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT166_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT166_BLUE_0		(0x1u<<0)

// FGCLUT167 Configuration

#define	DMA2D_FGCLUT167_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT167_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT167_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT167_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT167_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT167_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT167_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT167_BLUE_0		(0x1u<<0)

// FGCLUT168 Configuration

#define	DMA2D_FGCLUT168_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT168_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT168_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT168_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT168_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT168_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT168_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT168_BLUE_0		(0x1u<<0)

// FGCLUT169 Configuration

#define	DMA2D_FGCLUT169_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT169_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT169_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT169_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT169_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT169_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT169_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT169_BLUE_0		(0x1u<<0)

// FGCLUT170 Configuration

#define	DMA2D_FGCLUT170_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT170_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT170_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT170_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT170_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT170_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT170_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT170_BLUE_0		(0x1u<<0)

// FGCLUT171 Configuration

#define	DMA2D_FGCLUT171_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT171_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT171_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT171_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT171_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT171_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT171_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT171_BLUE_0		(0x1u<<0)

// FGCLUT172 Configuration

#define	DMA2D_FGCLUT172_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT172_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT172_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT172_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT172_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT172_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT172_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT172_BLUE_0		(0x1u<<0)

// FGCLUT173 Configuration

#define	DMA2D_FGCLUT173_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT173_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT173_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT173_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT173_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT173_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT173_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT173_BLUE_0		(0x1u<<0)

// FGCLUT174 Configuration

#define	DMA2D_FGCLUT174_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT174_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT174_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT174_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT174_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT174_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT174_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT174_BLUE_0		(0x1u<<0)

// FGCLUT175 Configuration

#define	DMA2D_FGCLUT175_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT175_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT175_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT175_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT175_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT175_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT175_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT175_BLUE_0		(0x1u<<0)

// FGCLUT176 Configuration

#define	DMA2D_FGCLUT176_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT176_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT176_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT176_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT176_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT176_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT176_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT176_BLUE_0		(0x1u<<0)

// FGCLUT177 Configuration

#define	DMA2D_FGCLUT177_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT177_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT177_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT177_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT177_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT177_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT177_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT177_BLUE_0		(0x1u<<0)

// FGCLUT178 Configuration

#define	DMA2D_FGCLUT178_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT178_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT178_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT178_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT178_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT178_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT178_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT178_BLUE_0		(0x1u<<0)

// FGCLUT179 Configuration

#define	DMA2D_FGCLUT179_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT179_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT179_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT179_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT179_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT179_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT179_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT179_BLUE_0		(0x1u<<0)

// FGCLUT180 Configuration

#define	DMA2D_FGCLUT180_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT180_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT180_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT180_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT180_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT180_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT180_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT180_BLUE_0		(0x1u<<0)

// FGCLUT181 Configuration

#define	DMA2D_FGCLUT181_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT181_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT181_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT181_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT181_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT181_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT181_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT181_BLUE_0		(0x1u<<0)

// FGCLUT182 Configuration

#define	DMA2D_FGCLUT182_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT182_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT182_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT182_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT182_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT182_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT182_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT182_BLUE_0		(0x1u<<0)

// FGCLUT183 Configuration

#define	DMA2D_FGCLUT183_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT183_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT183_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT183_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT183_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT183_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT183_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT183_BLUE_0		(0x1u<<0)

// FGCLUT184 Configuration

#define	DMA2D_FGCLUT184_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT184_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT184_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT184_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT184_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT184_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT184_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT184_BLUE_0		(0x1u<<0)

// FGCLUT185 Configuration

#define	DMA2D_FGCLUT185_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT185_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT185_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT185_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT185_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT185_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT185_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT185_BLUE_0		(0x1u<<0)

// FGCLUT186 Configuration

#define	DMA2D_FGCLUT186_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT186_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT186_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT186_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT186_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT186_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT186_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT186_BLUE_0		(0x1u<<0)

// FGCLUT187 Configuration

#define	DMA2D_FGCLUT187_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT187_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT187_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT187_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT187_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT187_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT187_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT187_BLUE_0		(0x1u<<0)

// FGCLUT188 Configuration

#define	DMA2D_FGCLUT188_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT188_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT188_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT188_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT188_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT188_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT188_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT188_BLUE_0		(0x1u<<0)

// FGCLUT189 Configuration

#define	DMA2D_FGCLUT189_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT189_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT189_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT189_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT189_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT189_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT189_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT189_BLUE_0		(0x1u<<0)

// FGCLUT190 Configuration

#define	DMA2D_FGCLUT190_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT190_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT190_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT190_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT190_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT190_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT190_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT190_BLUE_0		(0x1u<<0)

// FGCLUT191 Configuration

#define	DMA2D_FGCLUT191_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT191_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT191_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT191_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT191_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT191_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT191_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT191_BLUE_0		(0x1u<<0)

// FGCLUT192 Configuration

#define	DMA2D_FGCLUT192_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT192_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT192_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT192_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT192_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT192_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT192_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT192_BLUE_0		(0x1u<<0)

// FGCLUT193 Configuration

#define	DMA2D_FGCLUT193_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT193_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT193_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT193_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT193_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT193_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT193_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT193_BLUE_0		(0x1u<<0)

// FGCLUT194 Configuration

#define	DMA2D_FGCLUT194_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT194_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT194_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT194_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT194_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT194_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT194_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT194_BLUE_0		(0x1u<<0)

// FGCLUT195 Configuration

#define	DMA2D_FGCLUT195_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT195_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT195_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT195_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT195_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT195_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT195_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT195_BLUE_0		(0x1u<<0)

// FGCLUT196 Configuration

#define	DMA2D_FGCLUT196_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT196_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT196_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT196_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT196_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT196_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT196_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT196_BLUE_0		(0x1u<<0)

// FGCLUT197 Configuration

#define	DMA2D_FGCLUT197_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT197_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT197_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT197_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT197_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT197_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT197_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT197_BLUE_0		(0x1u<<0)

// FGCLUT198 Configuration

#define	DMA2D_FGCLUT198_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT198_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT198_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT198_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT198_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT198_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT198_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT198_BLUE_0		(0x1u<<0)

// FGCLUT199 Configuration

#define	DMA2D_FGCLUT199_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT199_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT199_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT199_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT199_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT199_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT199_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT199_BLUE_0		(0x1u<<0)

// FGCLUT200 Configuration

#define	DMA2D_FGCLUT200_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT200_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT200_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT200_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT200_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT200_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT200_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT200_BLUE_0		(0x1u<<0)

// FGCLUT201 Configuration

#define	DMA2D_FGCLUT201_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT201_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT201_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT201_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT201_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT201_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT201_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT201_BLUE_0		(0x1u<<0)

// FGCLUT202 Configuration

#define	DMA2D_FGCLUT202_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT202_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT202_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT202_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT202_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT202_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT202_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT202_BLUE_0		(0x1u<<0)

// FGCLUT203 Configuration

#define	DMA2D_FGCLUT203_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT203_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT203_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT203_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT203_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT203_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT203_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT203_BLUE_0		(0x1u<<0)

// FGCLUT204 Configuration

#define	DMA2D_FGCLUT204_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT204_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT204_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT204_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT204_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT204_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT204_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT204_BLUE_0		(0x1u<<0)

// FGCLUT205 Configuration

#define	DMA2D_FGCLUT205_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT205_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT205_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT205_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT205_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT205_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT205_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT205_BLUE_0		(0x1u<<0)

// FGCLUT206 Configuration

#define	DMA2D_FGCLUT206_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT206_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT206_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT206_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT206_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT206_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT206_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT206_BLUE_0		(0x1u<<0)

// FGCLUT207 Configuration

#define	DMA2D_FGCLUT207_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT207_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT207_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT207_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT207_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT207_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT207_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT207_BLUE_0		(0x1u<<0)

// FGCLUT208 Configuration

#define	DMA2D_FGCLUT208_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT208_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT208_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT208_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT208_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT208_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT208_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT208_BLUE_0		(0x1u<<0)

// FGCLUT209 Configuration

#define	DMA2D_FGCLUT209_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT209_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT209_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT209_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT209_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT209_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT209_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT209_BLUE_0		(0x1u<<0)

// FGCLUT210 Configuration

#define	DMA2D_FGCLUT210_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT210_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT210_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT210_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT210_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT210_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT210_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT210_BLUE_0		(0x1u<<0)

// FGCLUT211 Configuration

#define	DMA2D_FGCLUT211_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT211_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT211_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT211_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT211_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT211_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT211_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT211_BLUE_0		(0x1u<<0)

// FGCLUT212 Configuration

#define	DMA2D_FGCLUT212_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT212_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT212_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT212_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT212_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT212_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT212_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT212_BLUE_0		(0x1u<<0)

// FGCLUT213 Configuration

#define	DMA2D_FGCLUT213_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT213_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT213_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT213_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT213_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT213_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT213_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT213_BLUE_0		(0x1u<<0)

// FGCLUT214 Configuration

#define	DMA2D_FGCLUT214_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT214_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT214_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT214_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT214_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT214_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT214_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT214_BLUE_0		(0x1u<<0)

// FGCLUT215 Configuration

#define	DMA2D_FGCLUT215_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT215_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT215_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT215_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT215_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT215_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT215_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT215_BLUE_0		(0x1u<<0)

// FGCLUT216 Configuration

#define	DMA2D_FGCLUT216_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT216_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT216_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT216_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT216_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT216_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT216_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT216_BLUE_0		(0x1u<<0)

// FGCLUT217 Configuration

#define	DMA2D_FGCLUT217_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT217_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT217_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT217_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT217_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT217_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT217_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT217_BLUE_0		(0x1u<<0)

// FGCLUT218 Configuration

#define	DMA2D_FGCLUT218_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT218_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT218_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT218_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT218_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT218_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT218_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT218_BLUE_0		(0x1u<<0)

// FGCLUT219 Configuration

#define	DMA2D_FGCLUT219_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT219_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT219_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT219_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT219_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT219_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT219_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT219_BLUE_0		(0x1u<<0)

// FGCLUT220 Configuration

#define	DMA2D_FGCLUT220_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT220_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT220_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT220_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT220_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT220_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT220_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT220_BLUE_0		(0x1u<<0)

// FGCLUT221 Configuration

#define	DMA2D_FGCLUT221_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT221_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT221_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT221_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT221_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT221_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT221_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT221_BLUE_0		(0x1u<<0)

// FGCLUT222 Configuration

#define	DMA2D_FGCLUT222_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT222_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT222_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT222_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT222_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT222_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT222_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT222_BLUE_0		(0x1u<<0)

// FGCLUT223 Configuration

#define	DMA2D_FGCLUT223_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT223_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT223_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT223_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT223_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT223_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT223_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT223_BLUE_0		(0x1u<<0)

// FGCLUT224 Configuration

#define	DMA2D_FGCLUT224_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT224_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT224_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT224_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT224_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT224_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT224_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT224_BLUE_0		(0x1u<<0)

// FGCLUT225 Configuration

#define	DMA2D_FGCLUT225_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT225_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT225_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT225_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT225_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT225_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT225_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT225_BLUE_0		(0x1u<<0)

// FGCLUT226 Configuration

#define	DMA2D_FGCLUT226_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT226_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT226_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT226_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT226_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT226_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT226_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT226_BLUE_0		(0x1u<<0)

// FGCLUT227 Configuration

#define	DMA2D_FGCLUT227_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT227_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT227_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT227_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT227_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT227_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT227_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT227_BLUE_0		(0x1u<<0)

// FGCLUT228 Configuration

#define	DMA2D_FGCLUT228_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT228_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT228_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT228_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT228_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT228_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT228_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT228_BLUE_0		(0x1u<<0)

// FGCLUT229 Configuration

#define	DMA2D_FGCLUT229_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT229_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT229_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT229_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT229_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT229_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT229_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT229_BLUE_0		(0x1u<<0)

// FGCLUT230 Configuration

#define	DMA2D_FGCLUT230_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT230_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT230_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT230_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT230_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT230_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT230_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT230_BLUE_0		(0x1u<<0)

// FGCLUT231 Configuration

#define	DMA2D_FGCLUT231_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT231_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT231_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT231_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT231_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT231_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT231_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT231_BLUE_0		(0x1u<<0)

// FGCLUT232 Configuration

#define	DMA2D_FGCLUT232_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT232_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT232_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT232_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT232_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT232_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT232_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT232_BLUE_0		(0x1u<<0)

// FGCLUT233 Configuration

#define	DMA2D_FGCLUT233_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT233_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT233_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT233_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT233_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT233_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT233_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT233_BLUE_0		(0x1u<<0)

// FGCLUT234 Configuration

#define	DMA2D_FGCLUT234_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT234_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT234_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT234_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT234_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT234_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT234_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT234_BLUE_0		(0x1u<<0)

// FGCLUT235 Configuration

#define	DMA2D_FGCLUT235_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT235_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT235_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT235_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT235_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT235_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT235_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT235_BLUE_0		(0x1u<<0)

// FGCLUT236 Configuration

#define	DMA2D_FGCLUT236_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT236_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT236_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT236_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT236_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT236_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT236_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT236_BLUE_0		(0x1u<<0)

// FGCLUT237 Configuration

#define	DMA2D_FGCLUT237_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT237_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT237_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT237_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT237_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT237_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT237_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT237_BLUE_0		(0x1u<<0)

// FGCLUT238 Configuration

#define	DMA2D_FGCLUT238_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT238_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT238_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT238_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT238_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT238_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT238_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT238_BLUE_0		(0x1u<<0)

// FGCLUT239 Configuration

#define	DMA2D_FGCLUT239_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT239_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT239_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT239_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT239_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT239_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT239_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT239_BLUE_0		(0x1u<<0)

// FGCLUT240 Configuration

#define	DMA2D_FGCLUT240_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT240_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT240_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT240_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT240_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT240_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT240_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT240_BLUE_0		(0x1u<<0)

// FGCLUT241 Configuration

#define	DMA2D_FGCLUT241_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT241_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT241_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT241_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT241_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT241_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT241_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT241_BLUE_0		(0x1u<<0)

// FGCLUT242 Configuration

#define	DMA2D_FGCLUT242_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT242_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT242_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT242_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT242_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT242_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT242_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT242_BLUE_0		(0x1u<<0)

// FGCLUT243 Configuration

#define	DMA2D_FGCLUT243_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT243_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT243_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT243_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT243_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT243_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT243_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT243_BLUE_0		(0x1u<<0)

// FGCLUT244 Configuration

#define	DMA2D_FGCLUT244_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT244_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT244_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT244_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT244_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT244_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT244_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT244_BLUE_0		(0x1u<<0)

// FGCLUT245 Configuration

#define	DMA2D_FGCLUT245_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT245_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT245_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT245_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT245_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT245_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT245_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT245_BLUE_0		(0x1u<<0)

// FGCLUT246 Configuration

#define	DMA2D_FGCLUT246_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT246_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT246_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT246_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT246_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT246_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT246_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT246_BLUE_0		(0x1u<<0)

// FGCLUT247 Configuration

#define	DMA2D_FGCLUT247_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT247_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT247_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT247_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT247_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT247_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT247_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT247_BLUE_0		(0x1u<<0)

// FGCLUT248 Configuration

#define	DMA2D_FGCLUT248_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT248_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT248_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT248_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT248_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT248_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT248_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT248_BLUE_0		(0x1u<<0)

// FGCLUT249 Configuration

#define	DMA2D_FGCLUT249_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT249_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT249_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT249_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT249_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT249_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT249_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT249_BLUE_0		(0x1u<<0)

// FGCLUT250 Configuration

#define	DMA2D_FGCLUT250_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT250_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT250_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT250_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT250_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT250_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT250_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT250_BLUE_0		(0x1u<<0)

// FGCLUT251 Configuration

#define	DMA2D_FGCLUT251_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT251_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT251_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT251_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT251_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT251_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT251_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT251_BLUE_0		(0x1u<<0)

// FGCLUT252 Configuration

#define	DMA2D_FGCLUT252_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT252_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT252_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT252_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT252_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT252_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT252_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT252_BLUE_0		(0x1u<<0)

// FGCLUT253 Configuration

#define	DMA2D_FGCLUT253_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT253_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT253_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT253_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT253_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT253_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT253_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT253_BLUE_0		(0x1u<<0)

// FGCLUT254 Configuration

#define	DMA2D_FGCLUT254_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT254_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT254_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT254_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT254_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT254_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT254_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT254_BLUE_0		(0x1u<<0)

// FGCLUT255 Configuration

#define	DMA2D_FGCLUT255_ALPHA		(0xFFu<<24)
#define	DMA2D_FGCLUT255_ALPHA_0		(0x1u<<24)
#define	DMA2D_FGCLUT255_RED			(0xFFu<<16)
#define	DMA2D_FGCLUT255_RED_0		(0x1u<<16)
#define	DMA2D_FGCLUT255_GREEN		(0xFFu<<8)
#define	DMA2D_FGCLUT255_GREEN_0		(0x1u<<8)
#define	DMA2D_FGCLUT255_BLUE		(0xFFu<<0)
#define	DMA2D_FGCLUT255_BLUE_0		(0x1u<<0)

// BGCLUT0 Configuration

#define	DMA2D_BGCLUT0_ALPHA			(0xFFu<<24)
#define	DMA2D_BGCLUT0_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT0_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT0_RED_0			(0x1u<<16)
#define	DMA2D_BGCLUT0_GREEN			(0xFFu<<8)
#define	DMA2D_BGCLUT0_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT0_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT0_BLUE_0		(0x1u<<0)

// BGCLUT1 Configuration

#define	DMA2D_BGCLUT1_ALPHA			(0xFFu<<24)
#define	DMA2D_BGCLUT1_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT1_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT1_RED_0			(0x1u<<16)
#define	DMA2D_BGCLUT1_GREEN			(0xFFu<<8)
#define	DMA2D_BGCLUT1_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT1_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT1_BLUE_0		(0x1u<<0)

// BGCLUT2 Configuration

#define	DMA2D_BGCLUT2_ALPHA			(0xFFu<<24)
#define	DMA2D_BGCLUT2_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT2_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT2_RED_0			(0x1u<<16)
#define	DMA2D_BGCLUT2_GREEN			(0xFFu<<8)
#define	DMA2D_BGCLUT2_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT2_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT2_BLUE_0		(0x1u<<0)

// BGCLUT3 Configuration

#define	DMA2D_BGCLUT3_ALPHA			(0xFFu<<24)
#define	DMA2D_BGCLUT3_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT3_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT3_RED_0			(0x1u<<16)
#define	DMA2D_BGCLUT3_GREEN			(0xFFu<<8)
#define	DMA2D_BGCLUT3_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT3_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT3_BLUE_0		(0x1u<<0)

// BGCLUT4 Configuration

#define	DMA2D_BGCLUT4_ALPHA			(0xFFu<<24)
#define	DMA2D_BGCLUT4_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT4_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT4_RED_0			(0x1u<<16)
#define	DMA2D_BGCLUT4_GREEN			(0xFFu<<8)
#define	DMA2D_BGCLUT4_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT4_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT4_BLUE_0		(0x1u<<0)

// BGCLUT5 Configuration

#define	DMA2D_BGCLUT5_ALPHA			(0xFFu<<24)
#define	DMA2D_BGCLUT5_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT5_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT5_RED_0			(0x1u<<16)
#define	DMA2D_BGCLUT5_GREEN			(0xFFu<<8)
#define	DMA2D_BGCLUT5_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT5_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT5_BLUE_0		(0x1u<<0)

// BGCLUT6 Configuration

#define	DMA2D_BGCLUT6_ALPHA			(0xFFu<<24)
#define	DMA2D_BGCLUT6_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT6_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT6_RED_0			(0x1u<<16)
#define	DMA2D_BGCLUT6_GREEN			(0xFFu<<8)
#define	DMA2D_BGCLUT6_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT6_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT6_BLUE_0		(0x1u<<0)

// BGCLUT7 Configuration

#define	DMA2D_BGCLUT7_ALPHA			(0xFFu<<24)
#define	DMA2D_BGCLUT7_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT7_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT7_RED_0			(0x1u<<16)
#define	DMA2D_BGCLUT7_GREEN			(0xFFu<<8)
#define	DMA2D_BGCLUT7_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT7_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT7_BLUE_0		(0x1u<<0)

// BGCLUT8 Configuration

#define	DMA2D_BGCLUT8_ALPHA			(0xFFu<<24)
#define	DMA2D_BGCLUT8_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT8_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT8_RED_0			(0x1u<<16)
#define	DMA2D_BGCLUT8_GREEN			(0xFFu<<8)
#define	DMA2D_BGCLUT8_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT8_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT8_BLUE_0		(0x1u<<0)

// BGCLUT9 Configuration

#define	DMA2D_BGCLUT9_ALPHA			(0xFFu<<24)
#define	DMA2D_BGCLUT9_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT9_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT9_RED_0			(0x1u<<16)
#define	DMA2D_BGCLUT9_GREEN			(0xFFu<<8)
#define	DMA2D_BGCLUT9_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT9_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT9_BLUE_0		(0x1u<<0)

// BGCLUT10 Configuration

#define	DMA2D_BGCLUT10_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT10_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT10_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT10_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT10_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT10_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT10_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT10_BLUE_0		(0x1u<<0)

// BGCLUT11 Configuration

#define	DMA2D_BGCLUT11_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT11_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT11_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT11_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT11_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT11_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT11_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT11_BLUE_0		(0x1u<<0)

// BGCLUT12 Configuration

#define	DMA2D_BGCLUT12_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT12_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT12_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT12_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT12_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT12_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT12_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT12_BLUE_0		(0x1u<<0)

// BGCLUT13 Configuration

#define	DMA2D_BGCLUT13_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT13_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT13_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT13_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT13_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT13_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT13_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT13_BLUE_0		(0x1u<<0)

// BGCLUT14 Configuration

#define	DMA2D_BGCLUT14_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT14_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT14_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT14_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT14_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT14_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT14_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT14_BLUE_0		(0x1u<<0)

// BGCLUT15 Configuration

#define	DMA2D_BGCLUT15_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT15_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT15_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT15_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT15_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT15_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT15_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT15_BLUE_0		(0x1u<<0)

// BGCLUT16 Configuration

#define	DMA2D_BGCLUT16_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT16_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT16_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT16_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT16_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT16_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT16_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT16_BLUE_0		(0x1u<<0)

// BGCLUT17 Configuration

#define	DMA2D_BGCLUT17_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT17_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT17_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT17_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT17_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT17_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT17_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT17_BLUE_0		(0x1u<<0)

// BGCLUT18 Configuration

#define	DMA2D_BGCLUT18_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT18_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT18_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT18_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT18_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT18_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT18_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT18_BLUE_0		(0x1u<<0)

// BGCLUT19 Configuration

#define	DMA2D_BGCLUT19_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT19_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT19_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT19_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT19_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT19_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT19_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT19_BLUE_0		(0x1u<<0)

// BGCLUT20 Configuration

#define	DMA2D_BGCLUT20_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT20_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT20_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT20_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT20_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT20_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT20_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT20_BLUE_0		(0x1u<<0)

// BGCLUT21 Configuration

#define	DMA2D_BGCLUT21_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT21_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT21_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT21_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT21_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT21_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT21_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT21_BLUE_0		(0x1u<<0)

// BGCLUT22 Configuration

#define	DMA2D_BGCLUT22_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT22_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT22_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT22_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT22_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT22_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT22_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT22_BLUE_0		(0x1u<<0)

// BGCLUT23 Configuration

#define	DMA2D_BGCLUT23_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT23_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT23_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT23_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT23_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT23_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT23_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT23_BLUE_0		(0x1u<<0)

// BGCLUT24 Configuration

#define	DMA2D_BGCLUT24_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT24_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT24_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT24_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT24_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT24_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT24_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT24_BLUE_0		(0x1u<<0)

// BGCLUT25 Configuration

#define	DMA2D_BGCLUT25_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT25_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT25_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT25_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT25_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT25_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT25_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT25_BLUE_0		(0x1u<<0)

// BGCLUT26 Configuration

#define	DMA2D_BGCLUT26_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT26_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT26_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT26_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT26_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT26_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT26_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT26_BLUE_0		(0x1u<<0)

// BGCLUT27 Configuration

#define	DMA2D_BGCLUT27_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT27_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT27_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT27_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT27_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT27_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT27_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT27_BLUE_0		(0x1u<<0)

// BGCLUT28 Configuration

#define	DMA2D_BGCLUT28_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT28_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT28_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT28_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT28_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT28_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT28_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT28_BLUE_0		(0x1u<<0)

// BGCLUT29 Configuration

#define	DMA2D_BGCLUT29_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT29_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT29_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT29_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT29_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT29_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT29_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT29_BLUE_0		(0x1u<<0)

// BGCLUT30 Configuration

#define	DMA2D_BGCLUT30_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT30_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT30_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT30_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT30_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT30_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT30_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT30_BLUE_0		(0x1u<<0)

// BGCLUT31 Configuration

#define	DMA2D_BGCLUT31_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT31_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT31_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT31_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT31_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT31_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT31_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT31_BLUE_0		(0x1u<<0)

// BGCLUT32 Configuration

#define	DMA2D_BGCLUT32_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT32_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT32_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT32_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT32_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT32_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT32_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT32_BLUE_0		(0x1u<<0)

// BGCLUT33 Configuration

#define	DMA2D_BGCLUT33_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT33_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT33_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT33_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT33_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT33_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT33_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT33_BLUE_0		(0x1u<<0)

// BGCLUT34 Configuration

#define	DMA2D_BGCLUT34_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT34_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT34_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT34_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT34_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT34_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT34_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT34_BLUE_0		(0x1u<<0)

// BGCLUT35 Configuration

#define	DMA2D_BGCLUT35_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT35_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT35_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT35_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT35_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT35_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT35_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT35_BLUE_0		(0x1u<<0)

// BGCLUT36 Configuration

#define	DMA2D_BGCLUT36_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT36_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT36_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT36_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT36_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT36_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT36_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT36_BLUE_0		(0x1u<<0)

// BGCLUT37 Configuration

#define	DMA2D_BGCLUT37_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT37_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT37_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT37_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT37_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT37_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT37_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT37_BLUE_0		(0x1u<<0)

// BGCLUT38 Configuration

#define	DMA2D_BGCLUT38_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT38_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT38_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT38_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT38_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT38_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT38_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT38_BLUE_0		(0x1u<<0)

// BGCLUT39 Configuration

#define	DMA2D_BGCLUT39_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT39_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT39_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT39_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT39_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT39_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT39_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT39_BLUE_0		(0x1u<<0)

// BGCLUT40 Configuration

#define	DMA2D_BGCLUT40_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT40_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT40_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT40_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT40_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT40_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT40_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT40_BLUE_0		(0x1u<<0)

// BGCLUT41 Configuration

#define	DMA2D_BGCLUT41_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT41_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT41_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT41_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT41_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT41_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT41_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT41_BLUE_0		(0x1u<<0)

// BGCLUT42 Configuration

#define	DMA2D_BGCLUT42_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT42_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT42_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT42_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT42_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT42_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT42_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT42_BLUE_0		(0x1u<<0)

// BGCLUT43 Configuration

#define	DMA2D_BGCLUT43_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT43_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT43_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT43_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT43_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT43_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT43_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT43_BLUE_0		(0x1u<<0)

// BGCLUT44 Configuration

#define	DMA2D_BGCLUT44_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT44_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT44_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT44_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT44_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT44_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT44_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT44_BLUE_0		(0x1u<<0)

// BGCLUT45 Configuration

#define	DMA2D_BGCLUT45_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT45_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT45_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT45_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT45_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT45_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT45_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT45_BLUE_0		(0x1u<<0)

// BGCLUT46 Configuration

#define	DMA2D_BGCLUT46_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT46_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT46_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT46_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT46_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT46_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT46_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT46_BLUE_0		(0x1u<<0)

// BGCLUT47 Configuration

#define	DMA2D_BGCLUT47_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT47_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT47_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT47_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT47_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT47_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT47_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT47_BLUE_0		(0x1u<<0)

// BGCLUT48 Configuration

#define	DMA2D_BGCLUT48_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT48_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT48_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT48_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT48_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT48_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT48_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT48_BLUE_0		(0x1u<<0)

// BGCLUT49 Configuration

#define	DMA2D_BGCLUT49_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT49_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT49_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT49_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT49_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT49_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT49_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT49_BLUE_0		(0x1u<<0)

// BGCLUT50 Configuration

#define	DMA2D_BGCLUT50_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT50_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT50_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT50_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT50_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT50_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT50_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT50_BLUE_0		(0x1u<<0)

// BGCLUT51 Configuration

#define	DMA2D_BGCLUT51_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT51_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT51_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT51_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT51_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT51_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT51_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT51_BLUE_0		(0x1u<<0)

// BGCLUT52 Configuration

#define	DMA2D_BGCLUT52_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT52_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT52_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT52_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT52_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT52_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT52_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT52_BLUE_0		(0x1u<<0)

// BGCLUT53 Configuration

#define	DMA2D_BGCLUT53_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT53_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT53_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT53_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT53_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT53_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT53_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT53_BLUE_0		(0x1u<<0)

// BGCLUT54 Configuration

#define	DMA2D_BGCLUT54_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT54_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT54_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT54_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT54_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT54_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT54_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT54_BLUE_0		(0x1u<<0)

// BGCLUT55 Configuration

#define	DMA2D_BGCLUT55_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT55_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT55_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT55_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT55_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT55_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT55_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT55_BLUE_0		(0x1u<<0)

// BGCLUT56 Configuration

#define	DMA2D_BGCLUT56_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT56_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT56_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT56_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT56_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT56_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT56_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT56_BLUE_0		(0x1u<<0)

// BGCLUT57 Configuration

#define	DMA2D_BGCLUT57_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT57_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT57_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT57_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT57_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT57_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT57_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT57_BLUE_0		(0x1u<<0)

// BGCLUT58 Configuration

#define	DMA2D_BGCLUT58_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT58_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT58_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT58_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT58_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT58_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT58_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT58_BLUE_0		(0x1u<<0)

// BGCLUT59 Configuration

#define	DMA2D_BGCLUT59_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT59_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT59_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT59_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT59_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT59_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT59_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT59_BLUE_0		(0x1u<<0)

// BGCLUT60 Configuration

#define	DMA2D_BGCLUT60_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT60_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT60_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT60_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT60_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT60_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT60_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT60_BLUE_0		(0x1u<<0)

// BGCLUT61 Configuration

#define	DMA2D_BGCLUT61_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT61_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT61_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT61_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT61_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT61_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT61_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT61_BLUE_0		(0x1u<<0)

// BGCLUT62 Configuration

#define	DMA2D_BGCLUT62_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT62_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT62_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT62_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT62_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT62_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT62_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT62_BLUE_0		(0x1u<<0)

// BGCLUT63 Configuration

#define	DMA2D_BGCLUT63_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT63_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT63_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT63_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT63_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT63_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT63_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT63_BLUE_0		(0x1u<<0)

// BGCLUT64 Configuration

#define	DMA2D_BGCLUT64_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT64_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT64_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT64_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT64_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT64_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT64_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT64_BLUE_0		(0x1u<<0)

// BGCLUT65 Configuration

#define	DMA2D_BGCLUT65_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT65_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT65_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT65_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT65_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT65_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT65_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT65_BLUE_0		(0x1u<<0)

// BGCLUT66 Configuration

#define	DMA2D_BGCLUT66_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT66_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT66_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT66_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT66_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT66_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT66_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT66_BLUE_0		(0x1u<<0)

// BGCLUT67 Configuration

#define	DMA2D_BGCLUT67_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT67_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT67_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT67_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT67_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT67_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT67_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT67_BLUE_0		(0x1u<<0)

// BGCLUT68 Configuration

#define	DMA2D_BGCLUT68_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT68_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT68_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT68_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT68_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT68_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT68_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT68_BLUE_0		(0x1u<<0)

// BGCLUT69 Configuration

#define	DMA2D_BGCLUT69_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT69_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT69_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT69_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT69_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT69_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT69_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT69_BLUE_0		(0x1u<<0)

// BGCLUT70 Configuration

#define	DMA2D_BGCLUT70_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT70_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT70_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT70_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT70_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT70_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT70_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT70_BLUE_0		(0x1u<<0)

// BGCLUT71 Configuration

#define	DMA2D_BGCLUT71_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT71_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT71_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT71_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT71_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT71_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT71_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT71_BLUE_0		(0x1u<<0)

// BGCLUT72 Configuration

#define	DMA2D_BGCLUT72_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT72_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT72_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT72_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT72_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT72_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT72_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT72_BLUE_0		(0x1u<<0)

// BGCLUT73 Configuration

#define	DMA2D_BGCLUT73_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT73_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT73_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT73_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT73_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT73_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT73_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT73_BLUE_0		(0x1u<<0)

// BGCLUT74 Configuration

#define	DMA2D_BGCLUT74_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT74_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT74_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT74_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT74_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT74_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT74_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT74_BLUE_0		(0x1u<<0)

// BGCLUT75 Configuration

#define	DMA2D_BGCLUT75_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT75_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT75_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT75_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT75_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT75_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT75_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT75_BLUE_0		(0x1u<<0)

// BGCLUT76 Configuration

#define	DMA2D_BGCLUT76_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT76_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT76_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT76_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT76_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT76_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT76_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT76_BLUE_0		(0x1u<<0)

// BGCLUT77 Configuration

#define	DMA2D_BGCLUT77_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT77_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT77_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT77_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT77_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT77_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT77_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT77_BLUE_0		(0x1u<<0)

// BGCLUT78 Configuration

#define	DMA2D_BGCLUT78_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT78_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT78_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT78_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT78_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT78_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT78_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT78_BLUE_0		(0x1u<<0)

// BGCLUT79 Configuration

#define	DMA2D_BGCLUT79_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT79_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT79_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT79_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT79_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT79_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT79_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT79_BLUE_0		(0x1u<<0)

// BGCLUT80 Configuration

#define	DMA2D_BGCLUT80_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT80_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT80_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT80_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT80_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT80_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT80_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT80_BLUE_0		(0x1u<<0)

// BGCLUT81 Configuration

#define	DMA2D_BGCLUT81_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT81_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT81_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT81_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT81_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT81_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT81_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT81_BLUE_0		(0x1u<<0)

// BGCLUT82 Configuration

#define	DMA2D_BGCLUT82_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT82_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT82_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT82_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT82_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT82_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT82_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT82_BLUE_0		(0x1u<<0)

// BGCLUT83 Configuration

#define	DMA2D_BGCLUT83_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT83_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT83_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT83_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT83_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT83_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT83_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT83_BLUE_0		(0x1u<<0)

// BGCLUT84 Configuration

#define	DMA2D_BGCLUT84_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT84_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT84_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT84_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT84_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT84_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT84_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT84_BLUE_0		(0x1u<<0)

// BGCLUT85 Configuration

#define	DMA2D_BGCLUT85_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT85_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT85_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT85_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT85_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT85_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT85_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT85_BLUE_0		(0x1u<<0)

// BGCLUT86 Configuration

#define	DMA2D_BGCLUT86_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT86_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT86_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT86_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT86_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT86_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT86_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT86_BLUE_0		(0x1u<<0)

// BGCLUT87 Configuration

#define	DMA2D_BGCLUT87_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT87_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT87_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT87_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT87_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT87_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT87_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT87_BLUE_0		(0x1u<<0)

// BGCLUT88 Configuration

#define	DMA2D_BGCLUT88_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT88_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT88_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT88_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT88_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT88_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT88_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT88_BLUE_0		(0x1u<<0)

// BGCLUT89 Configuration

#define	DMA2D_BGCLUT89_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT89_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT89_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT89_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT89_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT89_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT89_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT89_BLUE_0		(0x1u<<0)

// BGCLUT90 Configuration

#define	DMA2D_BGCLUT90_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT90_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT90_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT90_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT90_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT90_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT90_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT90_BLUE_0		(0x1u<<0)

// BGCLUT91 Configuration

#define	DMA2D_BGCLUT91_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT91_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT91_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT91_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT91_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT91_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT91_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT91_BLUE_0		(0x1u<<0)

// BGCLUT92 Configuration

#define	DMA2D_BGCLUT92_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT92_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT92_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT92_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT92_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT92_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT92_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT92_BLUE_0		(0x1u<<0)

// BGCLUT93 Configuration

#define	DMA2D_BGCLUT93_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT93_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT93_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT93_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT93_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT93_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT93_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT93_BLUE_0		(0x1u<<0)

// BGCLUT94 Configuration

#define	DMA2D_BGCLUT94_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT94_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT94_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT94_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT94_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT94_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT94_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT94_BLUE_0		(0x1u<<0)

// BGCLUT95 Configuration

#define	DMA2D_BGCLUT95_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT95_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT95_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT95_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT95_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT95_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT95_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT95_BLUE_0		(0x1u<<0)

// BGCLUT96 Configuration

#define	DMA2D_BGCLUT96_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT96_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT96_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT96_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT96_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT96_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT96_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT96_BLUE_0		(0x1u<<0)

// BGCLUT97 Configuration

#define	DMA2D_BGCLUT97_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT97_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT97_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT97_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT97_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT97_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT97_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT97_BLUE_0		(0x1u<<0)

// BGCLUT98 Configuration

#define	DMA2D_BGCLUT98_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT98_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT98_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT98_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT98_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT98_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT98_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT98_BLUE_0		(0x1u<<0)

// BGCLUT99 Configuration

#define	DMA2D_BGCLUT99_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT99_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT99_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT99_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT99_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT99_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT99_BLUE			(0xFFu<<0)
#define	DMA2D_BGCLUT99_BLUE_0		(0x1u<<0)

// BGCLUT100 Configuration

#define	DMA2D_BGCLUT100_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT100_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT100_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT100_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT100_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT100_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT100_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT100_BLUE_0		(0x1u<<0)

// BGCLUT101 Configuration

#define	DMA2D_BGCLUT101_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT101_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT101_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT101_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT101_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT101_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT101_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT101_BLUE_0		(0x1u<<0)

// BGCLUT102 Configuration

#define	DMA2D_BGCLUT102_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT102_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT102_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT102_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT102_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT102_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT102_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT102_BLUE_0		(0x1u<<0)

// BGCLUT103 Configuration

#define	DMA2D_BGCLUT103_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT103_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT103_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT103_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT103_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT103_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT103_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT103_BLUE_0		(0x1u<<0)

// BGCLUT104 Configuration

#define	DMA2D_BGCLUT104_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT104_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT104_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT104_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT104_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT104_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT104_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT104_BLUE_0		(0x1u<<0)

// BGCLUT105 Configuration

#define	DMA2D_BGCLUT105_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT105_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT105_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT105_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT105_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT105_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT105_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT105_BLUE_0		(0x1u<<0)

// BGCLUT106 Configuration

#define	DMA2D_BGCLUT106_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT106_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT106_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT106_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT106_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT106_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT106_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT106_BLUE_0		(0x1u<<0)

// BGCLUT107 Configuration

#define	DMA2D_BGCLUT107_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT107_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT107_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT107_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT107_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT107_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT107_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT107_BLUE_0		(0x1u<<0)

// BGCLUT108 Configuration

#define	DMA2D_BGCLUT108_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT108_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT108_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT108_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT108_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT108_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT108_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT108_BLUE_0		(0x1u<<0)

// BGCLUT109 Configuration

#define	DMA2D_BGCLUT109_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT109_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT109_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT109_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT109_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT109_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT109_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT109_BLUE_0		(0x1u<<0)

// BGCLUT110 Configuration

#define	DMA2D_BGCLUT110_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT110_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT110_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT110_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT110_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT110_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT110_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT110_BLUE_0		(0x1u<<0)

// BGCLUT111 Configuration

#define	DMA2D_BGCLUT111_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT111_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT111_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT111_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT111_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT111_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT111_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT111_BLUE_0		(0x1u<<0)

// BGCLUT112 Configuration

#define	DMA2D_BGCLUT112_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT112_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT112_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT112_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT112_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT112_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT112_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT112_BLUE_0		(0x1u<<0)

// BGCLUT113 Configuration

#define	DMA2D_BGCLUT113_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT113_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT113_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT113_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT113_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT113_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT113_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT113_BLUE_0		(0x1u<<0)

// BGCLUT114 Configuration

#define	DMA2D_BGCLUT114_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT114_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT114_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT114_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT114_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT114_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT114_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT114_BLUE_0		(0x1u<<0)

// BGCLUT115 Configuration

#define	DMA2D_BGCLUT115_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT115_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT115_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT115_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT115_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT115_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT115_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT115_BLUE_0		(0x1u<<0)

// BGCLUT116 Configuration

#define	DMA2D_BGCLUT116_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT116_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT116_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT116_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT116_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT116_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT116_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT116_BLUE_0		(0x1u<<0)

// BGCLUT117 Configuration

#define	DMA2D_BGCLUT117_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT117_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT117_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT117_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT117_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT117_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT117_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT117_BLUE_0		(0x1u<<0)

// BGCLUT118 Configuration

#define	DMA2D_BGCLUT118_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT118_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT118_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT118_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT118_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT118_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT118_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT118_BLUE_0		(0x1u<<0)

// BGCLUT119 Configuration

#define	DMA2D_BGCLUT119_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT119_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT119_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT119_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT119_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT119_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT119_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT119_BLUE_0		(0x1u<<0)

// BGCLUT120 Configuration

#define	DMA2D_BGCLUT120_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT120_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT120_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT120_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT120_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT120_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT120_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT120_BLUE_0		(0x1u<<0)

// BGCLUT121 Configuration

#define	DMA2D_BGCLUT121_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT121_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT121_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT121_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT121_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT121_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT121_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT121_BLUE_0		(0x1u<<0)

// BGCLUT122 Configuration

#define	DMA2D_BGCLUT122_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT122_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT122_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT122_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT122_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT122_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT122_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT122_BLUE_0		(0x1u<<0)

// BGCLUT123 Configuration

#define	DMA2D_BGCLUT123_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT123_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT123_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT123_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT123_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT123_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT123_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT123_BLUE_0		(0x1u<<0)

// BGCLUT124 Configuration

#define	DMA2D_BGCLUT124_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT124_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT124_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT124_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT124_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT124_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT124_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT124_BLUE_0		(0x1u<<0)

// BGCLUT125 Configuration

#define	DMA2D_BGCLUT125_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT125_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT125_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT125_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT125_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT125_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT125_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT125_BLUE_0		(0x1u<<0)

// BGCLUT126 Configuration

#define	DMA2D_BGCLUT126_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT126_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT126_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT126_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT126_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT126_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT126_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT126_BLUE_0		(0x1u<<0)

// BGCLUT127 Configuration

#define	DMA2D_BGCLUT127_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT127_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT127_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT127_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT127_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT127_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT127_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT127_BLUE_0		(0x1u<<0)

// BGCLUT128 Configuration

#define	DMA2D_BGCLUT128_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT128_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT128_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT128_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT128_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT128_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT128_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT128_BLUE_0		(0x1u<<0)

// BGCLUT129 Configuration

#define	DMA2D_BGCLUT129_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT129_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT129_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT129_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT129_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT129_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT129_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT129_BLUE_0		(0x1u<<0)

// BGCLUT130 Configuration

#define	DMA2D_BGCLUT130_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT130_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT130_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT130_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT130_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT130_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT130_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT130_BLUE_0		(0x1u<<0)

// BGCLUT131 Configuration

#define	DMA2D_BGCLUT131_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT131_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT131_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT131_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT131_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT131_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT131_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT131_BLUE_0		(0x1u<<0)

// BGCLUT132 Configuration

#define	DMA2D_BGCLUT132_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT132_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT132_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT132_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT132_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT132_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT132_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT132_BLUE_0		(0x1u<<0)

// BGCLUT133 Configuration

#define	DMA2D_BGCLUT133_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT133_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT133_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT133_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT133_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT133_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT133_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT133_BLUE_0		(0x1u<<0)

// BGCLUT134 Configuration

#define	DMA2D_BGCLUT134_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT134_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT134_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT134_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT134_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT134_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT134_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT134_BLUE_0		(0x1u<<0)

// BGCLUT135 Configuration

#define	DMA2D_BGCLUT135_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT135_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT135_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT135_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT135_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT135_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT135_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT135_BLUE_0		(0x1u<<0)

// BGCLUT136 Configuration

#define	DMA2D_BGCLUT136_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT136_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT136_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT136_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT136_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT136_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT136_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT136_BLUE_0		(0x1u<<0)

// BGCLUT137 Configuration

#define	DMA2D_BGCLUT137_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT137_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT137_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT137_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT137_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT137_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT137_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT137_BLUE_0		(0x1u<<0)

// BGCLUT138 Configuration

#define	DMA2D_BGCLUT138_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT138_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT138_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT138_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT138_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT138_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT138_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT138_BLUE_0		(0x1u<<0)

// BGCLUT139 Configuration

#define	DMA2D_BGCLUT139_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT139_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT139_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT139_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT139_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT139_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT139_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT139_BLUE_0		(0x1u<<0)

// BGCLUT140 Configuration

#define	DMA2D_BGCLUT140_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT140_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT140_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT140_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT140_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT140_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT140_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT140_BLUE_0		(0x1u<<0)

// BGCLUT141 Configuration

#define	DMA2D_BGCLUT141_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT141_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT141_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT141_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT141_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT141_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT141_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT141_BLUE_0		(0x1u<<0)

// BGCLUT142 Configuration

#define	DMA2D_BGCLUT142_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT142_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT142_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT142_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT142_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT142_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT142_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT142_BLUE_0		(0x1u<<0)

// BGCLUT143 Configuration

#define	DMA2D_BGCLUT143_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT143_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT143_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT143_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT143_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT143_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT143_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT143_BLUE_0		(0x1u<<0)

// BGCLUT144 Configuration

#define	DMA2D_BGCLUT144_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT144_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT144_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT144_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT144_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT144_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT144_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT144_BLUE_0		(0x1u<<0)

// BGCLUT145 Configuration

#define	DMA2D_BGCLUT145_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT145_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT145_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT145_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT145_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT145_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT145_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT145_BLUE_0		(0x1u<<0)

// BGCLUT146 Configuration

#define	DMA2D_BGCLUT146_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT146_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT146_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT146_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT146_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT146_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT146_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT146_BLUE_0		(0x1u<<0)

// BGCLUT147 Configuration

#define	DMA2D_BGCLUT147_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT147_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT147_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT147_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT147_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT147_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT147_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT147_BLUE_0		(0x1u<<0)

// BGCLUT148 Configuration

#define	DMA2D_BGCLUT148_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT148_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT148_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT148_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT148_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT148_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT148_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT148_BLUE_0		(0x1u<<0)

// BGCLUT149 Configuration

#define	DMA2D_BGCLUT149_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT149_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT149_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT149_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT149_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT149_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT149_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT149_BLUE_0		(0x1u<<0)

// BGCLUT150 Configuration

#define	DMA2D_BGCLUT150_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT150_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT150_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT150_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT150_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT150_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT150_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT150_BLUE_0		(0x1u<<0)

// BGCLUT151 Configuration

#define	DMA2D_BGCLUT151_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT151_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT151_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT151_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT151_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT151_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT151_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT151_BLUE_0		(0x1u<<0)

// BGCLUT152 Configuration

#define	DMA2D_BGCLUT152_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT152_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT152_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT152_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT152_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT152_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT152_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT152_BLUE_0		(0x1u<<0)

// BGCLUT153 Configuration

#define	DMA2D_BGCLUT153_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT153_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT153_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT153_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT153_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT153_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT153_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT153_BLUE_0		(0x1u<<0)

// BGCLUT154 Configuration

#define	DMA2D_BGCLUT154_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT154_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT154_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT154_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT154_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT154_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT154_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT154_BLUE_0		(0x1u<<0)

// BGCLUT155 Configuration

#define	DMA2D_BGCLUT155_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT155_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT155_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT155_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT155_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT155_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT155_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT155_BLUE_0		(0x1u<<0)

// BGCLUT156 Configuration

#define	DMA2D_BGCLUT156_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT156_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT156_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT156_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT156_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT156_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT156_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT156_BLUE_0		(0x1u<<0)

// BGCLUT157 Configuration

#define	DMA2D_BGCLUT157_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT157_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT157_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT157_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT157_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT157_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT157_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT157_BLUE_0		(0x1u<<0)

// BGCLUT158 Configuration

#define	DMA2D_BGCLUT158_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT158_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT158_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT158_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT158_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT158_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT158_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT158_BLUE_0		(0x1u<<0)

// BGCLUT159 Configuration

#define	DMA2D_BGCLUT159_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT159_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT159_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT159_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT159_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT159_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT159_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT159_BLUE_0		(0x1u<<0)

// BGCLUT160 Configuration

#define	DMA2D_BGCLUT160_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT160_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT160_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT160_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT160_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT160_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT160_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT160_BLUE_0		(0x1u<<0)

// BGCLUT161 Configuration

#define	DMA2D_BGCLUT161_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT161_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT161_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT161_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT161_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT161_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT161_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT161_BLUE_0		(0x1u<<0)

// BGCLUT162 Configuration

#define	DMA2D_BGCLUT162_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT162_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT162_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT162_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT162_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT162_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT162_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT162_BLUE_0		(0x1u<<0)

// BGCLUT163 Configuration

#define	DMA2D_BGCLUT163_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT163_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT163_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT163_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT163_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT163_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT163_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT163_BLUE_0		(0x1u<<0)

// BGCLUT164 Configuration

#define	DMA2D_BGCLUT164_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT164_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT164_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT164_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT164_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT164_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT164_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT164_BLUE_0		(0x1u<<0)

// BGCLUT165 Configuration

#define	DMA2D_BGCLUT165_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT165_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT165_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT165_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT165_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT165_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT165_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT165_BLUE_0		(0x1u<<0)

// BGCLUT166 Configuration

#define	DMA2D_BGCLUT166_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT166_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT166_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT166_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT166_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT166_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT166_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT166_BLUE_0		(0x1u<<0)

// BGCLUT167 Configuration

#define	DMA2D_BGCLUT167_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT167_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT167_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT167_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT167_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT167_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT167_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT167_BLUE_0		(0x1u<<0)

// BGCLUT168 Configuration

#define	DMA2D_BGCLUT168_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT168_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT168_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT168_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT168_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT168_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT168_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT168_BLUE_0		(0x1u<<0)

// BGCLUT169 Configuration

#define	DMA2D_BGCLUT169_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT169_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT169_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT169_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT169_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT169_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT169_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT169_BLUE_0		(0x1u<<0)

// BGCLUT170 Configuration

#define	DMA2D_BGCLUT170_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT170_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT170_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT170_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT170_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT170_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT170_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT170_BLUE_0		(0x1u<<0)

// BGCLUT171 Configuration

#define	DMA2D_BGCLUT171_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT171_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT171_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT171_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT171_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT171_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT171_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT171_BLUE_0		(0x1u<<0)

// BGCLUT172 Configuration

#define	DMA2D_BGCLUT172_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT172_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT172_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT172_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT172_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT172_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT172_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT172_BLUE_0		(0x1u<<0)

// BGCLUT173 Configuration

#define	DMA2D_BGCLUT173_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT173_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT173_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT173_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT173_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT173_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT173_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT173_BLUE_0		(0x1u<<0)

// BGCLUT174 Configuration

#define	DMA2D_BGCLUT174_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT174_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT174_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT174_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT174_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT174_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT174_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT174_BLUE_0		(0x1u<<0)

// BGCLUT175 Configuration

#define	DMA2D_BGCLUT175_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT175_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT175_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT175_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT175_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT175_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT175_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT175_BLUE_0		(0x1u<<0)

// BGCLUT176 Configuration

#define	DMA2D_BGCLUT176_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT176_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT176_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT176_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT176_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT176_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT176_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT176_BLUE_0		(0x1u<<0)

// BGCLUT177 Configuration

#define	DMA2D_BGCLUT177_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT177_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT177_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT177_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT177_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT177_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT177_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT177_BLUE_0		(0x1u<<0)

// BGCLUT178 Configuration

#define	DMA2D_BGCLUT178_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT178_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT178_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT178_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT178_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT178_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT178_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT178_BLUE_0		(0x1u<<0)

// BGCLUT179 Configuration

#define	DMA2D_BGCLUT179_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT179_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT179_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT179_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT179_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT179_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT179_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT179_BLUE_0		(0x1u<<0)

// BGCLUT180 Configuration

#define	DMA2D_BGCLUT180_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT180_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT180_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT180_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT180_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT180_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT180_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT180_BLUE_0		(0x1u<<0)

// BGCLUT181 Configuration

#define	DMA2D_BGCLUT181_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT181_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT181_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT181_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT181_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT181_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT181_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT181_BLUE_0		(0x1u<<0)

// BGCLUT182 Configuration

#define	DMA2D_BGCLUT182_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT182_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT182_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT182_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT182_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT182_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT182_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT182_BLUE_0		(0x1u<<0)

// BGCLUT183 Configuration

#define	DMA2D_BGCLUT183_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT183_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT183_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT183_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT183_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT183_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT183_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT183_BLUE_0		(0x1u<<0)

// BGCLUT184 Configuration

#define	DMA2D_BGCLUT184_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT184_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT184_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT184_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT184_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT184_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT184_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT184_BLUE_0		(0x1u<<0)

// BGCLUT185 Configuration

#define	DMA2D_BGCLUT185_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT185_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT185_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT185_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT185_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT185_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT185_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT185_BLUE_0		(0x1u<<0)

// BGCLUT186 Configuration

#define	DMA2D_BGCLUT186_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT186_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT186_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT186_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT186_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT186_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT186_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT186_BLUE_0		(0x1u<<0)

// BGCLUT187 Configuration

#define	DMA2D_BGCLUT187_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT187_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT187_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT187_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT187_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT187_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT187_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT187_BLUE_0		(0x1u<<0)

// BGCLUT188 Configuration

#define	DMA2D_BGCLUT188_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT188_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT188_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT188_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT188_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT188_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT188_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT188_BLUE_0		(0x1u<<0)

// BGCLUT189 Configuration

#define	DMA2D_BGCLUT189_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT189_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT189_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT189_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT189_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT189_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT189_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT189_BLUE_0		(0x1u<<0)

// BGCLUT190 Configuration

#define	DMA2D_BGCLUT190_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT190_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT190_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT190_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT190_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT190_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT190_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT190_BLUE_0		(0x1u<<0)

// BGCLUT191 Configuration

#define	DMA2D_BGCLUT191_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT191_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT191_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT191_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT191_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT191_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT191_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT191_BLUE_0		(0x1u<<0)

// BGCLUT192 Configuration

#define	DMA2D_BGCLUT192_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT192_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT192_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT192_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT192_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT192_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT192_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT192_BLUE_0		(0x1u<<0)

// BGCLUT193 Configuration

#define	DMA2D_BGCLUT193_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT193_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT193_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT193_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT193_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT193_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT193_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT193_BLUE_0		(0x1u<<0)

// BGCLUT194 Configuration

#define	DMA2D_BGCLUT194_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT194_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT194_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT194_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT194_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT194_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT194_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT194_BLUE_0		(0x1u<<0)

// BGCLUT195 Configuration

#define	DMA2D_BGCLUT195_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT195_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT195_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT195_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT195_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT195_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT195_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT195_BLUE_0		(0x1u<<0)

// BGCLUT196 Configuration

#define	DMA2D_BGCLUT196_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT196_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT196_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT196_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT196_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT196_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT196_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT196_BLUE_0		(0x1u<<0)

// BGCLUT197 Configuration

#define	DMA2D_BGCLUT197_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT197_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT197_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT197_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT197_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT197_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT197_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT197_BLUE_0		(0x1u<<0)

// BGCLUT198 Configuration

#define	DMA2D_BGCLUT198_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT198_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT198_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT198_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT198_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT198_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT198_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT198_BLUE_0		(0x1u<<0)

// BGCLUT199 Configuration

#define	DMA2D_BGCLUT199_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT199_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT199_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT199_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT199_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT199_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT199_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT199_BLUE_0		(0x1u<<0)

// BGCLUT200 Configuration

#define	DMA2D_BGCLUT200_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT200_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT200_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT200_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT200_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT200_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT200_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT200_BLUE_0		(0x1u<<0)

// BGCLUT201 Configuration

#define	DMA2D_BGCLUT201_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT201_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT201_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT201_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT201_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT201_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT201_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT201_BLUE_0		(0x1u<<0)

// BGCLUT202 Configuration

#define	DMA2D_BGCLUT202_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT202_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT202_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT202_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT202_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT202_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT202_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT202_BLUE_0		(0x1u<<0)

// BGCLUT203 Configuration

#define	DMA2D_BGCLUT203_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT203_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT203_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT203_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT203_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT203_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT203_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT203_BLUE_0		(0x1u<<0)

// BGCLUT204 Configuration

#define	DMA2D_BGCLUT204_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT204_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT204_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT204_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT204_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT204_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT204_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT204_BLUE_0		(0x1u<<0)

// BGCLUT205 Configuration

#define	DMA2D_BGCLUT205_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT205_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT205_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT205_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT205_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT205_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT205_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT205_BLUE_0		(0x1u<<0)

// BGCLUT206 Configuration

#define	DMA2D_BGCLUT206_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT206_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT206_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT206_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT206_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT206_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT206_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT206_BLUE_0		(0x1u<<0)

// BGCLUT207 Configuration

#define	DMA2D_BGCLUT207_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT207_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT207_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT207_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT207_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT207_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT207_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT207_BLUE_0		(0x1u<<0)

// BGCLUT208 Configuration

#define	DMA2D_BGCLUT208_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT208_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT208_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT208_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT208_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT208_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT208_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT208_BLUE_0		(0x1u<<0)

// BGCLUT209 Configuration

#define	DMA2D_BGCLUT209_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT209_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT209_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT209_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT209_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT209_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT209_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT209_BLUE_0		(0x1u<<0)

// BGCLUT210 Configuration

#define	DMA2D_BGCLUT210_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT210_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT210_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT210_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT210_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT210_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT210_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT210_BLUE_0		(0x1u<<0)

// BGCLUT211 Configuration

#define	DMA2D_BGCLUT211_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT211_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT211_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT211_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT211_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT211_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT211_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT211_BLUE_0		(0x1u<<0)

// BGCLUT212 Configuration

#define	DMA2D_BGCLUT212_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT212_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT212_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT212_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT212_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT212_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT212_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT212_BLUE_0		(0x1u<<0)

// BGCLUT213 Configuration

#define	DMA2D_BGCLUT213_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT213_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT213_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT213_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT213_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT213_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT213_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT213_BLUE_0		(0x1u<<0)

// BGCLUT214 Configuration

#define	DMA2D_BGCLUT214_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT214_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT214_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT214_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT214_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT214_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT214_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT214_BLUE_0		(0x1u<<0)

// BGCLUT215 Configuration

#define	DMA2D_BGCLUT215_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT215_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT215_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT215_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT215_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT215_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT215_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT215_BLUE_0		(0x1u<<0)

// BGCLUT216 Configuration

#define	DMA2D_BGCLUT216_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT216_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT216_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT216_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT216_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT216_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT216_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT216_BLUE_0		(0x1u<<0)

// BGCLUT217 Configuration

#define	DMA2D_BGCLUT217_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT217_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT217_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT217_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT217_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT217_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT217_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT217_BLUE_0		(0x1u<<0)

// BGCLUT218 Configuration

#define	DMA2D_BGCLUT218_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT218_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT218_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT218_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT218_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT218_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT218_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT218_BLUE_0		(0x1u<<0)

// BGCLUT219 Configuration

#define	DMA2D_BGCLUT219_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT219_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT219_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT219_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT219_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT219_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT219_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT219_BLUE_0		(0x1u<<0)

// BGCLUT220 Configuration

#define	DMA2D_BGCLUT220_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT220_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT220_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT220_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT220_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT220_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT220_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT220_BLUE_0		(0x1u<<0)

// BGCLUT221 Configuration

#define	DMA2D_BGCLUT221_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT221_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT221_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT221_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT221_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT221_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT221_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT221_BLUE_0		(0x1u<<0)

// BGCLUT222 Configuration

#define	DMA2D_BGCLUT222_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT222_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT222_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT222_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT222_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT222_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT222_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT222_BLUE_0		(0x1u<<0)

// BGCLUT223 Configuration

#define	DMA2D_BGCLUT223_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT223_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT223_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT223_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT223_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT223_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT223_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT223_BLUE_0		(0x1u<<0)

// BGCLUT224 Configuration

#define	DMA2D_BGCLUT224_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT224_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT224_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT224_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT224_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT224_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT224_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT224_BLUE_0		(0x1u<<0)

// BGCLUT225 Configuration

#define	DMA2D_BGCLUT225_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT225_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT225_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT225_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT225_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT225_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT225_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT225_BLUE_0		(0x1u<<0)

// BGCLUT226 Configuration

#define	DMA2D_BGCLUT226_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT226_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT226_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT226_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT226_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT226_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT226_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT226_BLUE_0		(0x1u<<0)

// BGCLUT227 Configuration

#define	DMA2D_BGCLUT227_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT227_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT227_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT227_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT227_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT227_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT227_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT227_BLUE_0		(0x1u<<0)

// BGCLUT228 Configuration

#define	DMA2D_BGCLUT228_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT228_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT228_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT228_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT228_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT228_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT228_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT228_BLUE_0		(0x1u<<0)

// BGCLUT229 Configuration

#define	DMA2D_BGCLUT229_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT229_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT229_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT229_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT229_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT229_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT229_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT229_BLUE_0		(0x1u<<0)

// BGCLUT230 Configuration

#define	DMA2D_BGCLUT230_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT230_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT230_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT230_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT230_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT230_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT230_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT230_BLUE_0		(0x1u<<0)

// BGCLUT231 Configuration

#define	DMA2D_BGCLUT231_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT231_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT231_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT231_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT231_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT231_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT231_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT231_BLUE_0		(0x1u<<0)

// BGCLUT232 Configuration

#define	DMA2D_BGCLUT232_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT232_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT232_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT232_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT232_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT232_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT232_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT232_BLUE_0		(0x1u<<0)

// BGCLUT233 Configuration

#define	DMA2D_BGCLUT233_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT233_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT233_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT233_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT233_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT233_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT233_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT233_BLUE_0		(0x1u<<0)

// BGCLUT234 Configuration

#define	DMA2D_BGCLUT234_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT234_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT234_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT234_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT234_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT234_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT234_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT234_BLUE_0		(0x1u<<0)

// BGCLUT235 Configuration

#define	DMA2D_BGCLUT235_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT235_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT235_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT235_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT235_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT235_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT235_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT235_BLUE_0		(0x1u<<0)

// BGCLUT236 Configuration

#define	DMA2D_BGCLUT236_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT236_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT236_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT236_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT236_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT236_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT236_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT236_BLUE_0		(0x1u<<0)

// BGCLUT237 Configuration

#define	DMA2D_BGCLUT237_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT237_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT237_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT237_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT237_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT237_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT237_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT237_BLUE_0		(0x1u<<0)

// BGCLUT238 Configuration

#define	DMA2D_BGCLUT238_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT238_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT238_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT238_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT238_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT238_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT238_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT238_BLUE_0		(0x1u<<0)

// BGCLUT239 Configuration

#define	DMA2D_BGCLUT239_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT239_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT239_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT239_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT239_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT239_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT239_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT239_BLUE_0		(0x1u<<0)

// BGCLUT240 Configuration

#define	DMA2D_BGCLUT240_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT240_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT240_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT240_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT240_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT240_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT240_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT240_BLUE_0		(0x1u<<0)

// BGCLUT241 Configuration

#define	DMA2D_BGCLUT241_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT241_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT241_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT241_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT241_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT241_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT241_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT241_BLUE_0		(0x1u<<0)

// BGCLUT242 Configuration

#define	DMA2D_BGCLUT242_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT242_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT242_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT242_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT242_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT242_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT242_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT242_BLUE_0		(0x1u<<0)

// BGCLUT243 Configuration

#define	DMA2D_BGCLUT243_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT243_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT243_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT243_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT243_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT243_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT243_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT243_BLUE_0		(0x1u<<0)

// BGCLUT244 Configuration

#define	DMA2D_BGCLUT244_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT244_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT244_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT244_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT244_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT244_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT244_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT244_BLUE_0		(0x1u<<0)

// BGCLUT245 Configuration

#define	DMA2D_BGCLUT245_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT245_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT245_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT245_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT245_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT245_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT245_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT245_BLUE_0		(0x1u<<0)

// BGCLUT246 Configuration

#define	DMA2D_BGCLUT246_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT246_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT246_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT246_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT246_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT246_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT246_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT246_BLUE_0		(0x1u<<0)

// BGCLUT247 Configuration

#define	DMA2D_BGCLUT247_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT247_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT247_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT247_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT247_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT247_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT247_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT247_BLUE_0		(0x1u<<0)

// BGCLUT248 Configuration

#define	DMA2D_BGCLUT248_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT248_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT248_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT248_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT248_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT248_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT248_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT248_BLUE_0		(0x1u<<0)

// BGCLUT249 Configuration

#define	DMA2D_BGCLUT249_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT249_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT249_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT249_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT249_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT249_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT249_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT249_BLUE_0		(0x1u<<0)

// BGCLUT250 Configuration

#define	DMA2D_BGCLUT250_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT250_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT250_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT250_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT250_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT250_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT250_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT250_BLUE_0		(0x1u<<0)

// BGCLUT251 Configuration

#define	DMA2D_BGCLUT251_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT251_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT251_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT251_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT251_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT251_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT251_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT251_BLUE_0		(0x1u<<0)

// BGCLUT252 Configuration

#define	DMA2D_BGCLUT252_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT252_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT252_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT252_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT252_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT252_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT252_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT252_BLUE_0		(0x1u<<0)

// BGCLUT253 Configuration

#define	DMA2D_BGCLUT253_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT253_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT253_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT253_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT253_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT253_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT253_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT253_BLUE_0		(0x1u<<0)

// BGCLUT254 Configuration

#define	DMA2D_BGCLUT254_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT254_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT254_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT254_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT254_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT254_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT254_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT254_BLUE_0		(0x1u<<0)

// BGCLUT255 Configuration

#define	DMA2D_BGCLUT255_ALPHA		(0xFFu<<24)
#define	DMA2D_BGCLUT255_ALPHA_0		(0x1u<<24)
#define	DMA2D_BGCLUT255_RED			(0xFFu<<16)
#define	DMA2D_BGCLUT255_RED_0		(0x1u<<16)
#define	DMA2D_BGCLUT255_GREEN		(0xFFu<<8)
#define	DMA2D_BGCLUT255_GREEN_0		(0x1u<<8)
#define	DMA2D_BGCLUT255_BLUE		(0xFFu<<0)
#define	DMA2D_BGCLUT255_BLUE_0		(0x1u<<0)
