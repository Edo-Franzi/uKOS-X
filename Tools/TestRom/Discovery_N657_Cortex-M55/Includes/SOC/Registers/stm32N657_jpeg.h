/*
; stm32N657_jpeg.
; ===============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_jpeg equates.
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

// JPEG address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CONFR0;
	volatile	uint32_t	CONFR1;
	volatile	uint32_t	CONFR2;
	volatile	uint32_t	CONFR3;
	volatile	uint32_t	CONFR4;
	volatile	uint32_t	CONFR5;
	volatile	uint32_t	CONFR6;
	volatile	uint32_t	CONFR7;
	volatile	uint32_t	RESERVED0[4];
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	CFR;
	volatile	uint32_t	RESERVED1;
	volatile	uint32_t	DIR;
	volatile	uint32_t	DOR;
	volatile	uint32_t	RESERVED2[2];
	volatile	uint32_t	QMEM0_0;
	volatile	uint32_t	QMEM0_1;
	volatile	uint32_t	QMEM0_2;
	volatile	uint32_t	QMEM0_3;
	volatile	uint32_t	QMEM0_4;
	volatile	uint32_t	QMEM0_5;
	volatile	uint32_t	QMEM0_6;
	volatile	uint32_t	QMEM0_7;
	volatile	uint32_t	QMEM0_8;
	volatile	uint32_t	QMEM0_9;
	volatile	uint32_t	QMEM0_10;
	volatile	uint32_t	QMEM0_11;
	volatile	uint32_t	QMEM0_12;
	volatile	uint32_t	QMEM0_13;
	volatile	uint32_t	QMEM0_14;
	volatile	uint32_t	QMEM0_15;
	volatile	uint32_t	QMEM1_0;
	volatile	uint32_t	QMEM1_1;
	volatile	uint32_t	QMEM1_2;
	volatile	uint32_t	QMEM1_3;
	volatile	uint32_t	QMEM1_4;
	volatile	uint32_t	QMEM1_5;
	volatile	uint32_t	QMEM1_6;
	volatile	uint32_t	QMEM1_7;
	volatile	uint32_t	QMEM1_8;
	volatile	uint32_t	QMEM1_9;
	volatile	uint32_t	QMEM1_10;
	volatile	uint32_t	QMEM1_11;
	volatile	uint32_t	QMEM1_12;
	volatile	uint32_t	QMEM1_13;
	volatile	uint32_t	QMEM1_14;
	volatile	uint32_t	QMEM1_15;
	volatile	uint32_t	QMEM2_0;
	volatile	uint32_t	QMEM2_1;
	volatile	uint32_t	QMEM2_2;
	volatile	uint32_t	QMEM2_3;
	volatile	uint32_t	QMEM2_4;
	volatile	uint32_t	QMEM2_5;
	volatile	uint32_t	QMEM2_6;
	volatile	uint32_t	QMEM2_7;
	volatile	uint32_t	QMEM2_8;
	volatile	uint32_t	QMEM2_9;
	volatile	uint32_t	QMEM2_10;
	volatile	uint32_t	QMEM2_11;
	volatile	uint32_t	QMEM2_12;
	volatile	uint32_t	QMEM2_13;
	volatile	uint32_t	QMEM2_14;
	volatile	uint32_t	QMEM2_15;
	volatile	uint32_t	QMEM3_0;
	volatile	uint32_t	QMEM3_1;
	volatile	uint32_t	QMEM3_2;
	volatile	uint32_t	QMEM3_3;
	volatile	uint32_t	QMEM3_4;
	volatile	uint32_t	QMEM3_5;
	volatile	uint32_t	QMEM3_6;
	volatile	uint32_t	QMEM3_7;
	volatile	uint32_t	QMEM3_8;
	volatile	uint32_t	QMEM3_9;
	volatile	uint32_t	QMEM3_10;
	volatile	uint32_t	QMEM3_11;
	volatile	uint32_t	QMEM3_12;
	volatile	uint32_t	QMEM3_13;
	volatile	uint32_t	QMEM3_14;
	volatile	uint32_t	QMEM3_15;
	volatile	uint32_t	HUFFMIN0_0;
	volatile	uint32_t	HUFFMIN0_1;
	volatile	uint32_t	HUFFMIN0_2;
	volatile	uint32_t	HUFFMIN0_3;
	volatile	uint32_t	HUFFMIN1_0;
	volatile	uint32_t	HUFFMIN1_1;
	volatile	uint32_t	HUFFMIN1_2;
	volatile	uint32_t	HUFFMIN1_3;
	volatile	uint32_t	HUFFMIN2_0;
	volatile	uint32_t	HUFFMIN2_1;
	volatile	uint32_t	HUFFMIN2_2;
	volatile	uint32_t	HUFFMIN2_3;
	volatile	uint32_t	HUFFMIN3_0;
	volatile	uint32_t	HUFFMIN3_1;
	volatile	uint32_t	HUFFMIN3_2;
	volatile	uint32_t	HUFFMIN3_3;
	volatile	uint32_t	HUFFBASE0;
	volatile	uint32_t	HUFFBASE1;
	volatile	uint32_t	HUFFBASE2;
	volatile	uint32_t	HUFFBASE3;
	volatile	uint32_t	HUFFBASE4;
	volatile	uint32_t	HUFFBASE5;
	volatile	uint32_t	HUFFBASE6;
	volatile	uint32_t	HUFFBASE7;
	volatile	uint32_t	HUFFBASE8;
	volatile	uint32_t	HUFFBASE9;
	volatile	uint32_t	HUFFBASE10;
	volatile	uint32_t	HUFFBASE11;
	volatile	uint32_t	HUFFBASE12;
	volatile	uint32_t	HUFFBASE13;
	volatile	uint32_t	HUFFBASE14;
	volatile	uint32_t	HUFFBASE15;
	volatile	uint32_t	HUFFBASE16;
	volatile	uint32_t	HUFFBASE17;
	volatile	uint32_t	HUFFBASE18;
	volatile	uint32_t	HUFFBASE19;
	volatile	uint32_t	HUFFBASE20;
	volatile	uint32_t	HUFFBASE21;
	volatile	uint32_t	HUFFBASE22;
	volatile	uint32_t	HUFFBASE23;
	volatile	uint32_t	HUFFBASE24;
	volatile	uint32_t	HUFFBASE25;
	volatile	uint32_t	HUFFBASE26;
	volatile	uint32_t	HUFFBASE27;
	volatile	uint32_t	HUFFBASE28;
	volatile	uint32_t	HUFFBASE29;
	volatile	uint32_t	HUFFBASE30;
	volatile	uint32_t	HUFFBASE31;
	volatile	uint32_t	HUFFSYMB0;
	volatile	uint32_t	HUFFSYMB1;
	volatile	uint32_t	HUFFSYMB2;
	volatile	uint32_t	HUFFSYMB3;
	volatile	uint32_t	HUFFSYMB4;
	volatile	uint32_t	HUFFSYMB5;
	volatile	uint32_t	HUFFSYMB6;
	volatile	uint32_t	HUFFSYMB7;
	volatile	uint32_t	HUFFSYMB8;
	volatile	uint32_t	HUFFSYMB9;
	volatile	uint32_t	HUFFSYMB10;
	volatile	uint32_t	HUFFSYMB11;
	volatile	uint32_t	HUFFSYMB12;
	volatile	uint32_t	HUFFSYMB13;
	volatile	uint32_t	HUFFSYMB14;
	volatile	uint32_t	HUFFSYMB15;
	volatile	uint32_t	HUFFSYMB16;
	volatile	uint32_t	HUFFSYMB17;
	volatile	uint32_t	HUFFSYMB18;
	volatile	uint32_t	HUFFSYMB19;
	volatile	uint32_t	HUFFSYMB20;
	volatile	uint32_t	HUFFSYMB21;
	volatile	uint32_t	HUFFSYMB22;
	volatile	uint32_t	HUFFSYMB23;
	volatile	uint32_t	HUFFSYMB24;
	volatile	uint32_t	HUFFSYMB25;
	volatile	uint32_t	HUFFSYMB26;
	volatile	uint32_t	HUFFSYMB27;
	volatile	uint32_t	HUFFSYMB28;
	volatile	uint32_t	HUFFSYMB29;
	volatile	uint32_t	HUFFSYMB30;
	volatile	uint32_t	HUFFSYMB31;
	volatile	uint32_t	HUFFSYMB32;
	volatile	uint32_t	HUFFSYMB33;
	volatile	uint32_t	HUFFSYMB34;
	volatile	uint32_t	HUFFSYMB35;
	volatile	uint32_t	HUFFSYMB36;
	volatile	uint32_t	HUFFSYMB37;
	volatile	uint32_t	HUFFSYMB38;
	volatile	uint32_t	HUFFSYMB39;
	volatile	uint32_t	HUFFSYMB40;
	volatile	uint32_t	HUFFSYMB41;
	volatile	uint32_t	HUFFSYMB42;
	volatile	uint32_t	HUFFSYMB43;
	volatile	uint32_t	HUFFSYMB44;
	volatile	uint32_t	HUFFSYMB45;
	volatile	uint32_t	HUFFSYMB46;
	volatile	uint32_t	HUFFSYMB47;
	volatile	uint32_t	HUFFSYMB48;
	volatile	uint32_t	HUFFSYMB49;
	volatile	uint32_t	HUFFSYMB50;
	volatile	uint32_t	HUFFSYMB51;
	volatile	uint32_t	HUFFSYMB52;
	volatile	uint32_t	HUFFSYMB53;
	volatile	uint32_t	HUFFSYMB54;
	volatile	uint32_t	HUFFSYMB55;
	volatile	uint32_t	HUFFSYMB56;
	volatile	uint32_t	HUFFSYMB57;
	volatile	uint32_t	HUFFSYMB58;
	volatile	uint32_t	HUFFSYMB59;
	volatile	uint32_t	HUFFSYMB60;
	volatile	uint32_t	HUFFSYMB61;
	volatile	uint32_t	HUFFSYMB62;
	volatile	uint32_t	HUFFSYMB63;
	volatile	uint32_t	HUFFSYMB64;
	volatile	uint32_t	HUFFSYMB65;
	volatile	uint32_t	HUFFSYMB66;
	volatile	uint32_t	HUFFSYMB67;
	volatile	uint32_t	HUFFSYMB68;
	volatile	uint32_t	HUFFSYMB69;
	volatile	uint32_t	HUFFSYMB70;
	volatile	uint32_t	HUFFSYMB71;
	volatile	uint32_t	HUFFSYMB72;
	volatile	uint32_t	HUFFSYMB73;
	volatile	uint32_t	HUFFSYMB74;
	volatile	uint32_t	HUFFSYMB75;
	volatile	uint32_t	HUFFSYMB76;
	volatile	uint32_t	HUFFSYMB77;
	volatile	uint32_t	HUFFSYMB78;
	volatile	uint32_t	HUFFSYMB79;
	volatile	uint32_t	HUFFSYMB80;
	volatile	uint32_t	HUFFSYMB81;
	volatile	uint32_t	HUFFSYMB82;
	volatile	uint32_t	HUFFSYMB83;
	volatile	uint32_t	DHTMEM0;
	volatile	uint32_t	DHTMEM1;
	volatile	uint32_t	DHTMEM2;
	volatile	uint32_t	DHTMEM3;
	volatile	uint32_t	DHTMEM4;
	volatile	uint32_t	DHTMEM5;
	volatile	uint32_t	DHTMEM6;
	volatile	uint32_t	DHTMEM7;
	volatile	uint32_t	DHTMEM8;
	volatile	uint32_t	DHTMEM9;
	volatile	uint32_t	DHTMEM10;
	volatile	uint32_t	DHTMEM11;
	volatile	uint32_t	DHTMEM12;
	volatile	uint32_t	DHTMEM13;
	volatile	uint32_t	DHTMEM14;
	volatile	uint32_t	DHTMEM15;
	volatile	uint32_t	DHTMEM16;
	volatile	uint32_t	DHTMEM17;
	volatile	uint32_t	DHTMEM18;
	volatile	uint32_t	DHTMEM19;
	volatile	uint32_t	DHTMEM20;
	volatile	uint32_t	DHTMEM21;
	volatile	uint32_t	DHTMEM22;
	volatile	uint32_t	DHTMEM23;
	volatile	uint32_t	DHTMEM24;
	volatile	uint32_t	DHTMEM25;
	volatile	uint32_t	DHTMEM26;
	volatile	uint32_t	DHTMEM27;
	volatile	uint32_t	DHTMEM28;
	volatile	uint32_t	DHTMEM29;
	volatile	uint32_t	DHTMEM30;
	volatile	uint32_t	DHTMEM31;
	volatile	uint32_t	DHTMEM32;
	volatile	uint32_t	DHTMEM33;
	volatile	uint32_t	DHTMEM34;
	volatile	uint32_t	DHTMEM35;
	volatile	uint32_t	DHTMEM36;
	volatile	uint32_t	DHTMEM37;
	volatile	uint32_t	DHTMEM38;
	volatile	uint32_t	DHTMEM39;
	volatile	uint32_t	DHTMEM40;
	volatile	uint32_t	DHTMEM41;
	volatile	uint32_t	DHTMEM42;
	volatile	uint32_t	DHTMEM43;
	volatile	uint32_t	DHTMEM44;
	volatile	uint32_t	DHTMEM45;
	volatile	uint32_t	DHTMEM46;
	volatile	uint32_t	DHTMEM47;
	volatile	uint32_t	DHTMEM48;
	volatile	uint32_t	DHTMEM49;
	volatile	uint32_t	DHTMEM50;
	volatile	uint32_t	DHTMEM51;
	volatile	uint32_t	DHTMEM52;
	volatile	uint32_t	DHTMEM53;
	volatile	uint32_t	DHTMEM54;
	volatile	uint32_t	DHTMEM55;
	volatile	uint32_t	DHTMEM56;
	volatile	uint32_t	DHTMEM57;
	volatile	uint32_t	DHTMEM58;
	volatile	uint32_t	DHTMEM59;
	volatile	uint32_t	DHTMEM60;
	volatile	uint32_t	DHTMEM61;
	volatile	uint32_t	DHTMEM62;
	volatile	uint32_t	DHTMEM63;
	volatile	uint32_t	DHTMEM64;
	volatile	uint32_t	DHTMEM65;
	volatile	uint32_t	DHTMEM66;
	volatile	uint32_t	DHTMEM67;
	volatile	uint32_t	DHTMEM68;
	volatile	uint32_t	DHTMEM69;
	volatile	uint32_t	DHTMEM70;
	volatile	uint32_t	DHTMEM71;
	volatile	uint32_t	DHTMEM72;
	volatile	uint32_t	DHTMEM73;
	volatile	uint32_t	DHTMEM74;
	volatile	uint32_t	DHTMEM75;
	volatile	uint32_t	DHTMEM76;
	volatile	uint32_t	DHTMEM77;
	volatile	uint32_t	DHTMEM78;
	volatile	uint32_t	DHTMEM79;
	volatile	uint32_t	DHTMEM80;
	volatile	uint32_t	DHTMEM81;
	volatile	uint32_t	DHTMEM82;
	volatile	uint32_t	DHTMEM83;
	volatile	uint32_t	DHTMEM84;
	volatile	uint32_t	DHTMEM85;
	volatile	uint32_t	DHTMEM86;
	volatile	uint32_t	DHTMEM87;
	volatile	uint32_t	DHTMEM88;
	volatile	uint32_t	DHTMEM89;
	volatile	uint32_t	DHTMEM90;
	volatile	uint32_t	DHTMEM91;
	volatile	uint32_t	DHTMEM92;
	volatile	uint32_t	DHTMEM93;
	volatile	uint32_t	DHTMEM94;
	volatile	uint32_t	DHTMEM95;
	volatile	uint32_t	DHTMEM96;
	volatile	uint32_t	DHTMEM97;
	volatile	uint32_t	DHTMEM98;
	volatile	uint32_t	DHTMEM99;
	volatile	uint32_t	DHTMEM100;
	volatile	uint32_t	DHTMEM101;
	volatile	uint32_t	DHTMEM102;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	HUFFENC_AC0_0;
	volatile	uint32_t	HUFFENC_AC0_1;
	volatile	uint32_t	HUFFENC_AC0_2;
	volatile	uint32_t	HUFFENC_AC0_3;
	volatile	uint32_t	HUFFENC_AC0_4;
	volatile	uint32_t	HUFFENC_AC0_5;
	volatile	uint32_t	HUFFENC_AC0_6;
	volatile	uint32_t	HUFFENC_AC0_7;
	volatile	uint32_t	HUFFENC_AC0_8;
	volatile	uint32_t	HUFFENC_AC0_9;
	volatile	uint32_t	HUFFENC_AC0_10;
	volatile	uint32_t	HUFFENC_AC0_11;
	volatile	uint32_t	HUFFENC_AC0_12;
	volatile	uint32_t	HUFFENC_AC0_13;
	volatile	uint32_t	HUFFENC_AC0_14;
	volatile	uint32_t	HUFFENC_AC0_15;
	volatile	uint32_t	HUFFENC_AC0_16;
	volatile	uint32_t	HUFFENC_AC0_17;
	volatile	uint32_t	HUFFENC_AC0_18;
	volatile	uint32_t	HUFFENC_AC0_19;
	volatile	uint32_t	HUFFENC_AC0_20;
	volatile	uint32_t	HUFFENC_AC0_21;
	volatile	uint32_t	HUFFENC_AC0_22;
	volatile	uint32_t	HUFFENC_AC0_23;
	volatile	uint32_t	HUFFENC_AC0_24;
	volatile	uint32_t	HUFFENC_AC0_25;
	volatile	uint32_t	HUFFENC_AC0_26;
	volatile	uint32_t	HUFFENC_AC0_27;
	volatile	uint32_t	HUFFENC_AC0_28;
	volatile	uint32_t	HUFFENC_AC0_29;
	volatile	uint32_t	HUFFENC_AC0_30;
	volatile	uint32_t	HUFFENC_AC0_31;
	volatile	uint32_t	HUFFENC_AC0_32;
	volatile	uint32_t	HUFFENC_AC0_33;
	volatile	uint32_t	HUFFENC_AC0_34;
	volatile	uint32_t	HUFFENC_AC0_35;
	volatile	uint32_t	HUFFENC_AC0_36;
	volatile	uint32_t	HUFFENC_AC0_37;
	volatile	uint32_t	HUFFENC_AC0_38;
	volatile	uint32_t	HUFFENC_AC0_39;
	volatile	uint32_t	HUFFENC_AC0_40;
	volatile	uint32_t	HUFFENC_AC0_41;
	volatile	uint32_t	HUFFENC_AC0_42;
	volatile	uint32_t	HUFFENC_AC0_43;
	volatile	uint32_t	HUFFENC_AC0_44;
	volatile	uint32_t	HUFFENC_AC0_45;
	volatile	uint32_t	HUFFENC_AC0_46;
	volatile	uint32_t	HUFFENC_AC0_47;
	volatile	uint32_t	HUFFENC_AC0_48;
	volatile	uint32_t	HUFFENC_AC0_49;
	volatile	uint32_t	HUFFENC_AC0_50;
	volatile	uint32_t	HUFFENC_AC0_51;
	volatile	uint32_t	HUFFENC_AC0_52;
	volatile	uint32_t	HUFFENC_AC0_53;
	volatile	uint32_t	HUFFENC_AC0_54;
	volatile	uint32_t	HUFFENC_AC0_55;
	volatile	uint32_t	HUFFENC_AC0_56;
	volatile	uint32_t	HUFFENC_AC0_57;
	volatile	uint32_t	HUFFENC_AC0_58;
	volatile	uint32_t	HUFFENC_AC0_59;
	volatile	uint32_t	HUFFENC_AC0_60;
	volatile	uint32_t	HUFFENC_AC0_61;
	volatile	uint32_t	HUFFENC_AC0_62;
	volatile	uint32_t	HUFFENC_AC0_63;
	volatile	uint32_t	HUFFENC_AC0_64;
	volatile	uint32_t	HUFFENC_AC0_65;
	volatile	uint32_t	HUFFENC_AC0_66;
	volatile	uint32_t	HUFFENC_AC0_67;
	volatile	uint32_t	HUFFENC_AC0_68;
	volatile	uint32_t	HUFFENC_AC0_69;
	volatile	uint32_t	HUFFENC_AC0_70;
	volatile	uint32_t	HUFFENC_AC0_71;
	volatile	uint32_t	HUFFENC_AC0_72;
	volatile	uint32_t	HUFFENC_AC0_73;
	volatile	uint32_t	HUFFENC_AC0_74;
	volatile	uint32_t	HUFFENC_AC0_75;
	volatile	uint32_t	HUFFENC_AC0_76;
	volatile	uint32_t	HUFFENC_AC0_77;
	volatile	uint32_t	HUFFENC_AC0_78;
	volatile	uint32_t	HUFFENC_AC0_79;
	volatile	uint32_t	HUFFENC_AC0_80;
	volatile	uint32_t	HUFFENC_AC0_81;
	volatile	uint32_t	HUFFENC_AC0_82;
	volatile	uint32_t	HUFFENC_AC0_83;
	volatile	uint32_t	HUFFENC_AC0_84;
	volatile	uint32_t	HUFFENC_AC0_85;
	volatile	uint32_t	HUFFENC_AC0_86;
	volatile	uint32_t	HUFFENC_AC0_87;
	volatile	uint32_t	HUFFENC_AC1_0;
	volatile	uint32_t	HUFFENC_AC1_1;
	volatile	uint32_t	HUFFENC_AC1_2;
	volatile	uint32_t	HUFFENC_AC1_3;
	volatile	uint32_t	HUFFENC_AC1_4;
	volatile	uint32_t	HUFFENC_AC1_5;
	volatile	uint32_t	HUFFENC_AC1_6;
	volatile	uint32_t	HUFFENC_AC1_7;
	volatile	uint32_t	HUFFENC_AC1_8;
	volatile	uint32_t	HUFFENC_AC1_9;
	volatile	uint32_t	HUFFENC_AC1_10;
	volatile	uint32_t	HUFFENC_AC1_11;
	volatile	uint32_t	HUFFENC_AC1_12;
	volatile	uint32_t	HUFFENC_AC1_13;
	volatile	uint32_t	HUFFENC_AC1_14;
	volatile	uint32_t	HUFFENC_AC1_15;
	volatile	uint32_t	HUFFENC_AC1_16;
	volatile	uint32_t	HUFFENC_AC1_17;
	volatile	uint32_t	HUFFENC_AC1_18;
	volatile	uint32_t	HUFFENC_AC1_19;
	volatile	uint32_t	HUFFENC_AC1_20;
	volatile	uint32_t	HUFFENC_AC1_21;
	volatile	uint32_t	HUFFENC_AC1_22;
	volatile	uint32_t	HUFFENC_AC1_23;
	volatile	uint32_t	HUFFENC_AC1_24;
	volatile	uint32_t	HUFFENC_AC1_25;
	volatile	uint32_t	HUFFENC_AC1_26;
	volatile	uint32_t	HUFFENC_AC1_27;
	volatile	uint32_t	HUFFENC_AC1_28;
	volatile	uint32_t	HUFFENC_AC1_29;
	volatile	uint32_t	HUFFENC_AC1_30;
	volatile	uint32_t	HUFFENC_AC1_31;
	volatile	uint32_t	HUFFENC_AC1_32;
	volatile	uint32_t	HUFFENC_AC1_33;
	volatile	uint32_t	HUFFENC_AC1_34;
	volatile	uint32_t	HUFFENC_AC1_35;
	volatile	uint32_t	HUFFENC_AC1_36;
	volatile	uint32_t	HUFFENC_AC1_37;
	volatile	uint32_t	HUFFENC_AC1_38;
	volatile	uint32_t	HUFFENC_AC1_39;
	volatile	uint32_t	HUFFENC_AC1_40;
	volatile	uint32_t	HUFFENC_AC1_41;
	volatile	uint32_t	HUFFENC_AC1_42;
	volatile	uint32_t	HUFFENC_AC1_43;
	volatile	uint32_t	HUFFENC_AC1_44;
	volatile	uint32_t	HUFFENC_AC1_45;
	volatile	uint32_t	HUFFENC_AC1_46;
	volatile	uint32_t	HUFFENC_AC1_47;
	volatile	uint32_t	HUFFENC_AC1_48;
	volatile	uint32_t	HUFFENC_AC1_49;
	volatile	uint32_t	HUFFENC_AC1_50;
	volatile	uint32_t	HUFFENC_AC1_51;
	volatile	uint32_t	HUFFENC_AC1_52;
	volatile	uint32_t	HUFFENC_AC1_53;
	volatile	uint32_t	HUFFENC_AC1_54;
	volatile	uint32_t	HUFFENC_AC1_55;
	volatile	uint32_t	HUFFENC_AC1_56;
	volatile	uint32_t	HUFFENC_AC1_57;
	volatile	uint32_t	HUFFENC_AC1_58;
	volatile	uint32_t	HUFFENC_AC1_59;
	volatile	uint32_t	HUFFENC_AC1_60;
	volatile	uint32_t	HUFFENC_AC1_61;
	volatile	uint32_t	HUFFENC_AC1_62;
	volatile	uint32_t	HUFFENC_AC1_63;
	volatile	uint32_t	HUFFENC_AC1_64;
	volatile	uint32_t	HUFFENC_AC1_65;
	volatile	uint32_t	HUFFENC_AC1_66;
	volatile	uint32_t	HUFFENC_AC1_67;
	volatile	uint32_t	HUFFENC_AC1_68;
	volatile	uint32_t	HUFFENC_AC1_69;
	volatile	uint32_t	HUFFENC_AC1_70;
	volatile	uint32_t	HUFFENC_AC1_71;
	volatile	uint32_t	HUFFENC_AC1_72;
	volatile	uint32_t	HUFFENC_AC1_73;
	volatile	uint32_t	HUFFENC_AC1_74;
	volatile	uint32_t	HUFFENC_AC1_75;
	volatile	uint32_t	HUFFENC_AC1_76;
	volatile	uint32_t	HUFFENC_AC1_77;
	volatile	uint32_t	HUFFENC_AC1_78;
	volatile	uint32_t	HUFFENC_AC1_79;
	volatile	uint32_t	HUFFENC_AC1_80;
	volatile	uint32_t	HUFFENC_AC1_81;
	volatile	uint32_t	HUFFENC_AC1_82;
	volatile	uint32_t	HUFFENC_AC1_83;
	volatile	uint32_t	HUFFENC_AC1_84;
	volatile	uint32_t	HUFFENC_AC1_85;
	volatile	uint32_t	HUFFENC_AC1_86;
	volatile	uint32_t	HUFFENC_AC1_87;
	volatile	uint32_t	HUFFENC_DC0_0;
	volatile	uint32_t	HUFFENC_DC0_1;
	volatile	uint32_t	HUFFENC_DC0_2;
	volatile	uint32_t	HUFFENC_DC0_3;
	volatile	uint32_t	HUFFENC_DC0_4;
	volatile	uint32_t	HUFFENC_DC0_5;
	volatile	uint32_t	HUFFENC_DC0_6;
	volatile	uint32_t	HUFFENC_DC0_7;
	volatile	uint32_t	HUFFENC_DC1_0;
	volatile	uint32_t	HUFFENC_DC1_1;
	volatile	uint32_t	HUFFENC_DC1_2;
	volatile	uint32_t	HUFFENC_DC1_3;
	volatile	uint32_t	HUFFENC_DC1_4;
	volatile	uint32_t	HUFFENC_DC1_5;
	volatile	uint32_t	HUFFENC_DC1_6;
	volatile	uint32_t	HUFFENC_DC1_7;
} JPEG_TypeDef;

#if (defined(__cplusplus))
#define	JPEG_NS	reinterpret_cast<JPEG_TypeDef *>(0x48023000u)
#define	JPEG_S	reinterpret_cast<JPEG_TypeDef *>(0x58023000u)

#else
#define	JPEG_NS	((JPEG_TypeDef *)0x48023000u)
#define	JPEG_S	((JPEG_TypeDef *)0x58023000u)
#endif

// CONFR0 Configuration

#define	JPEG_CONFR0_START				(0x1u<<0)

#define	JPEG_CONFR0_START_B_0X0			(0x0u<<0)
#define	JPEG_CONFR0_START_B_0X1			(0x1u<<0)

// CONFR1 Configuration

#define	JPEG_CONFR1_YSIZE				(0xFFFFu<<16)
#define	JPEG_CONFR1_YSIZE_0				(0x1u<<16)
#define	JPEG_CONFR1_HDR					(0x1u<<8)
#define	JPEG_CONFR1_NS					(0x3u<<6)
#define	JPEG_CONFR1_NS_0				(0x1u<<6)
#define	JPEG_CONFR1_COLSPACE			(0x3u<<4)
#define	JPEG_CONFR1_COLSPACE_0			(0x1u<<4)
#define	JPEG_CONFR1_DE					(0x1u<<3)
#define	JPEG_CONFR1_NF					(0x3u<<0)
#define	JPEG_CONFR1_NF_0				(0x1u<<0)

#define	JPEG_CONFR1_HDR_B_0X0			(0x0u<<8)
#define	JPEG_CONFR1_HDR_B_0X1			(0x1u<<8)
#define	JPEG_CONFR1_COLSPACE_B_0X0		(0x0u<<4)
#define	JPEG_CONFR1_COLSPACE_B_0X1		(0x1u<<4)
#define	JPEG_CONFR1_COLSPACE_B_0X2		(0x2u<<4)
#define	JPEG_CONFR1_COLSPACE_B_0X3		(0x3u<<4)
#define	JPEG_CONFR1_DE_B_0X0			(0x0u<<3)
#define	JPEG_CONFR1_DE_B_0X1			(0x1u<<3)
#define	JPEG_CONFR1_NF_B_0X0			(0x0u<<0)
#define	JPEG_CONFR1_NF_B_0X1			(0x1u<<0)
#define	JPEG_CONFR1_NF_B_0X2			(0x2u<<0)
#define	JPEG_CONFR1_NF_B_0X3			(0x3u<<0)

// CONFR2 Configuration

#define	JPEG_CONFR2_NMCU				(0x3FFFFFFu<<0)
#define	JPEG_CONFR2_NMCU_0				(0x1u<<0)

// CONFR3 Configuration

#define	JPEG_CONFR3_XSIZE				(0xFFFFu<<16)
#define	JPEG_CONFR3_XSIZE_0				(0x1u<<16)

// CONFR4 Configuration

#define	JPEG_CONFR4_HSF					(0xFu<<12)
#define	JPEG_CONFR4_HSF_0				(0x1u<<12)
#define	JPEG_CONFR4_VSF					(0xFu<<8)
#define	JPEG_CONFR4_VSF_0				(0x1u<<8)
#define	JPEG_CONFR4_NB					(0xFu<<4)
#define	JPEG_CONFR4_NB_0				(0x1u<<4)
#define	JPEG_CONFR4_QT					(0x3u<<2)
#define	JPEG_CONFR4_QT_0				(0x1u<<2)
#define	JPEG_CONFR4_HA					(0x1u<<1)
#define	JPEG_CONFR4_HD					(0x1u<<0)

#define	JPEG_CONFR4_QT_B_0X0			(0x0u<<2)
#define	JPEG_CONFR4_QT_B_0X1			(0x1u<<2)
#define	JPEG_CONFR4_QT_B_0X2			(0x2u<<2)
#define	JPEG_CONFR4_QT_B_0X3			(0x3u<<2)
#define	JPEG_CONFR4_HA_B_0X0			(0x0u<<1)
#define	JPEG_CONFR4_HA_B_0X1			(0x1u<<1)
#define	JPEG_CONFR4_HD_B_0X0			(0x0u<<0)
#define	JPEG_CONFR4_HD_B_0X1			(0x1u<<0)

// CONFR5 Configuration

#define	JPEG_CONFR5_HSF					(0xFu<<12)
#define	JPEG_CONFR5_HSF_0				(0x1u<<12)
#define	JPEG_CONFR5_VSF					(0xFu<<8)
#define	JPEG_CONFR5_VSF_0				(0x1u<<8)
#define	JPEG_CONFR5_NB					(0xFu<<4)
#define	JPEG_CONFR5_NB_0				(0x1u<<4)
#define	JPEG_CONFR5_QT					(0x3u<<2)
#define	JPEG_CONFR5_QT_0				(0x1u<<2)
#define	JPEG_CONFR5_HA					(0x1u<<1)
#define	JPEG_CONFR5_HD					(0x1u<<0)

#define	JPEG_CONFR5_QT_B_0X0			(0x0u<<2)
#define	JPEG_CONFR5_QT_B_0X1			(0x1u<<2)
#define	JPEG_CONFR5_QT_B_0X2			(0x2u<<2)
#define	JPEG_CONFR5_QT_B_0X3			(0x3u<<2)
#define	JPEG_CONFR5_HA_B_0X0			(0x0u<<1)
#define	JPEG_CONFR5_HA_B_0X1			(0x1u<<1)
#define	JPEG_CONFR5_HD_B_0X0			(0x0u<<0)
#define	JPEG_CONFR5_HD_B_0X1			(0x1u<<0)

// CONFR6 Configuration

#define	JPEG_CONFR6_HSF					(0xFu<<12)
#define	JPEG_CONFR6_HSF_0				(0x1u<<12)
#define	JPEG_CONFR6_VSF					(0xFu<<8)
#define	JPEG_CONFR6_VSF_0				(0x1u<<8)
#define	JPEG_CONFR6_NB					(0xFu<<4)
#define	JPEG_CONFR6_NB_0				(0x1u<<4)
#define	JPEG_CONFR6_QT					(0x3u<<2)
#define	JPEG_CONFR6_QT_0				(0x1u<<2)
#define	JPEG_CONFR6_HA					(0x1u<<1)
#define	JPEG_CONFR6_HD					(0x1u<<0)

#define	JPEG_CONFR6_QT_B_0X0			(0x0u<<2)
#define	JPEG_CONFR6_QT_B_0X1			(0x1u<<2)
#define	JPEG_CONFR6_QT_B_0X2			(0x2u<<2)
#define	JPEG_CONFR6_QT_B_0X3			(0x3u<<2)
#define	JPEG_CONFR6_HA_B_0X0			(0x0u<<1)
#define	JPEG_CONFR6_HA_B_0X1			(0x1u<<1)
#define	JPEG_CONFR6_HD_B_0X0			(0x0u<<0)
#define	JPEG_CONFR6_HD_B_0X1			(0x1u<<0)

// CONFR7 Configuration

#define	JPEG_CONFR7_HSF					(0xFu<<12)
#define	JPEG_CONFR7_HSF_0				(0x1u<<12)
#define	JPEG_CONFR7_VSF					(0xFu<<8)
#define	JPEG_CONFR7_VSF_0				(0x1u<<8)
#define	JPEG_CONFR7_NB					(0xFu<<4)
#define	JPEG_CONFR7_NB_0				(0x1u<<4)
#define	JPEG_CONFR7_QT					(0x3u<<2)
#define	JPEG_CONFR7_QT_0				(0x1u<<2)
#define	JPEG_CONFR7_HA					(0x1u<<1)
#define	JPEG_CONFR7_HD					(0x1u<<0)

#define	JPEG_CONFR7_QT_B_0X0			(0x0u<<2)
#define	JPEG_CONFR7_QT_B_0X1			(0x1u<<2)
#define	JPEG_CONFR7_QT_B_0X2			(0x2u<<2)
#define	JPEG_CONFR7_QT_B_0X3			(0x3u<<2)
#define	JPEG_CONFR7_HA_B_0X0			(0x0u<<1)
#define	JPEG_CONFR7_HA_B_0X1			(0x1u<<1)
#define	JPEG_CONFR7_HD_B_0X0			(0x0u<<0)
#define	JPEG_CONFR7_HD_B_0X1			(0x1u<<0)

// CR Configuration

#define	JPEG_CR_OFF						(0x1u<<14)
#define	JPEG_CR_IFF						(0x1u<<13)
#define	JPEG_CR_ODMAEN					(0x1u<<12)
#define	JPEG_CR_IDMAEN					(0x1u<<11)
#define	JPEG_CR_HPDIE					(0x1u<<6)
#define	JPEG_CR_EOCIE					(0x1u<<5)
#define	JPEG_CR_OFNEIE					(0x1u<<4)
#define	JPEG_CR_OFTIE					(0x1u<<3)
#define	JPEG_CR_IFNFIE					(0x1u<<2)
#define	JPEG_CR_IFTIE					(0x1u<<1)
#define	JPEG_CR_JCEN					(0x1u<<0)

#define	JPEG_CR_OFF_B_0X0				(0x0u<<14)
#define	JPEG_CR_OFF_B_0X1				(0x1u<<14)
#define	JPEG_CR_IFF_B_0X0				(0x0u<<13)
#define	JPEG_CR_IFF_B_0X1				(0x1u<<13)
#define	JPEG_CR_ODMAEN_B_0X0			(0x0u<<12)
#define	JPEG_CR_ODMAEN_B_0X1			(0x1u<<12)
#define	JPEG_CR_IDMAEN_B_0X0			(0x0u<<11)
#define	JPEG_CR_IDMAEN_B_0X1			(0x1u<<11)
#define	JPEG_CR_HPDIE_B_0X0				(0x0u<<6)
#define	JPEG_CR_HPDIE_B_0X1				(0x1u<<6)
#define	JPEG_CR_EOCIE_B_0X0				(0x0u<<5)
#define	JPEG_CR_EOCIE_B_0X1				(0x1u<<5)
#define	JPEG_CR_OFNEIE_B_0X0			(0x0u<<4)
#define	JPEG_CR_OFNEIE_B_0X1			(0x1u<<4)
#define	JPEG_CR_OFTIE_B_0X0				(0x0u<<3)
#define	JPEG_CR_OFTIE_B_0X1				(0x1u<<3)
#define	JPEG_CR_IFNFIE_B_0X0			(0x0u<<2)
#define	JPEG_CR_IFNFIE_B_0X1			(0x1u<<2)
#define	JPEG_CR_IFTIE_B_0X0				(0x0u<<1)
#define	JPEG_CR_IFTIE_B_0X1				(0x1u<<1)
#define	JPEG_CR_JCEN_B_0X0				(0x0u<<0)
#define	JPEG_CR_JCEN_B_0X1				(0x1u<<0)

// SR Configuration

#define	JPEG_SR_COF						(0x1u<<7)
#define	JPEG_SR_HPDF					(0x1u<<6)
#define	JPEG_SR_EOCF					(0x1u<<5)
#define	JPEG_SR_OFNEF					(0x1u<<4)
#define	JPEG_SR_OFTF					(0x1u<<3)
#define	JPEG_SR_IFNFF					(0x1u<<2)
#define	JPEG_SR_IFTF					(0x1u<<1)

#define	JPEG_SR_COF_B_0X0				(0x0u<<7)
#define	JPEG_SR_COF_B_0X1				(0x1u<<7)
#define	JPEG_SR_HPDF_B_0X0				(0x0u<<6)
#define	JPEG_SR_HPDF_B_0X1				(0x1u<<6)
#define	JPEG_SR_EOCF_B_0X0				(0x0u<<5)
#define	JPEG_SR_EOCF_B_0X1				(0x1u<<5)
#define	JPEG_SR_OFNEF_B_0X0				(0x0u<<4)
#define	JPEG_SR_OFNEF_B_0X1				(0x1u<<4)
#define	JPEG_SR_OFTF_B_0X0				(0x0u<<3)
#define	JPEG_SR_OFTF_B_0X1				(0x1u<<3)
#define	JPEG_SR_IFNFF_B_0X0				(0x0u<<2)
#define	JPEG_SR_IFNFF_B_0X1				(0x1u<<2)
#define	JPEG_SR_IFTF_B_0X0				(0x0u<<1)
#define	JPEG_SR_IFTF_B_0X1				(0x1u<<1)

// CFR Configuration

#define	JPEG_CFR_CHPDF					(0x1u<<6)
#define	JPEG_CFR_CEOCF					(0x1u<<5)

#define	JPEG_CFR_CHPDF_B_0X0			(0x0u<<6)
#define	JPEG_CFR_CHPDF_B_0X1			(0x1u<<6)
#define	JPEG_CFR_CEOCF_B_0X0			(0x0u<<5)
#define	JPEG_CFR_CEOCF_B_0X1			(0x1u<<5)

// DIR Configuration

#define	JPEG_DIR_DATAIN					(0xFFFFFFFFu<<0)
#define	JPEG_DIR_DATAIN_0				(0x1u<<0)

// DOR Configuration

#define	JPEG_DOR_DATAOUT				(0xFFFFFFFFu<<0)
#define	JPEG_DOR_DATAOUT_0				(0x1u<<0)

// QMEM0_0 Configuration

#define	JPEG_QMEM0_0_QCOEF3				(0xFFu<<24)
#define	JPEG_QMEM0_0_QCOEF3_0			(0x1u<<24)
#define	JPEG_QMEM0_0_QCOEF2				(0xFFu<<16)
#define	JPEG_QMEM0_0_QCOEF2_0			(0x1u<<16)
#define	JPEG_QMEM0_0_QCOEF1				(0xFFu<<8)
#define	JPEG_QMEM0_0_QCOEF1_0			(0x1u<<8)
#define	JPEG_QMEM0_0_QCOEF0				(0xFFu<<0)
#define	JPEG_QMEM0_0_QCOEF0_0			(0x1u<<0)

// QMEM0_1 Configuration

#define	JPEG_QMEM0_1_QCOEF7				(0xFFu<<24)
#define	JPEG_QMEM0_1_QCOEF7_0			(0x1u<<24)
#define	JPEG_QMEM0_1_QCOEF6				(0xFFu<<16)
#define	JPEG_QMEM0_1_QCOEF6_0			(0x1u<<16)
#define	JPEG_QMEM0_1_QCOEF5				(0xFFu<<8)
#define	JPEG_QMEM0_1_QCOEF5_0			(0x1u<<8)
#define	JPEG_QMEM0_1_QCOEF4				(0xFFu<<0)
#define	JPEG_QMEM0_1_QCOEF4_0			(0x1u<<0)

// QMEM0_2 Configuration

#define	JPEG_QMEM0_2_QCOEF11			(0xFFu<<24)
#define	JPEG_QMEM0_2_QCOEF11_0			(0x1u<<24)
#define	JPEG_QMEM0_2_QCOEF10			(0xFFu<<16)
#define	JPEG_QMEM0_2_QCOEF10_0			(0x1u<<16)
#define	JPEG_QMEM0_2_QCOEF9				(0xFFu<<8)
#define	JPEG_QMEM0_2_QCOEF9_0			(0x1u<<8)
#define	JPEG_QMEM0_2_QCOEF8				(0xFFu<<0)
#define	JPEG_QMEM0_2_QCOEF8_0			(0x1u<<0)

// QMEM0_3 Configuration

#define	JPEG_QMEM0_3_QCOEF15			(0xFFu<<24)
#define	JPEG_QMEM0_3_QCOEF15_0			(0x1u<<24)
#define	JPEG_QMEM0_3_QCOEF14			(0xFFu<<16)
#define	JPEG_QMEM0_3_QCOEF14_0			(0x1u<<16)
#define	JPEG_QMEM0_3_QCOEF13			(0xFFu<<8)
#define	JPEG_QMEM0_3_QCOEF13_0			(0x1u<<8)
#define	JPEG_QMEM0_3_QCOEF12			(0xFFu<<0)
#define	JPEG_QMEM0_3_QCOEF12_0			(0x1u<<0)

// QMEM0_4 Configuration

#define	JPEG_QMEM0_4_QCOEF19			(0xFFu<<24)
#define	JPEG_QMEM0_4_QCOEF19_0			(0x1u<<24)
#define	JPEG_QMEM0_4_QCOEF18			(0xFFu<<16)
#define	JPEG_QMEM0_4_QCOEF18_0			(0x1u<<16)
#define	JPEG_QMEM0_4_QCOEF17			(0xFFu<<8)
#define	JPEG_QMEM0_4_QCOEF17_0			(0x1u<<8)
#define	JPEG_QMEM0_4_QCOEF16			(0xFFu<<0)
#define	JPEG_QMEM0_4_QCOEF16_0			(0x1u<<0)

// QMEM0_5 Configuration

#define	JPEG_QMEM0_5_QCOEF23			(0xFFu<<24)
#define	JPEG_QMEM0_5_QCOEF23_0			(0x1u<<24)
#define	JPEG_QMEM0_5_QCOEF22			(0xFFu<<16)
#define	JPEG_QMEM0_5_QCOEF22_0			(0x1u<<16)
#define	JPEG_QMEM0_5_QCOEF21			(0xFFu<<8)
#define	JPEG_QMEM0_5_QCOEF21_0			(0x1u<<8)
#define	JPEG_QMEM0_5_QCOEF20			(0xFFu<<0)
#define	JPEG_QMEM0_5_QCOEF20_0			(0x1u<<0)

// QMEM0_6 Configuration

#define	JPEG_QMEM0_6_QCOEF27			(0xFFu<<24)
#define	JPEG_QMEM0_6_QCOEF27_0			(0x1u<<24)
#define	JPEG_QMEM0_6_QCOEF26			(0xFFu<<16)
#define	JPEG_QMEM0_6_QCOEF26_0			(0x1u<<16)
#define	JPEG_QMEM0_6_QCOEF25			(0xFFu<<8)
#define	JPEG_QMEM0_6_QCOEF25_0			(0x1u<<8)
#define	JPEG_QMEM0_6_QCOEF24			(0xFFu<<0)
#define	JPEG_QMEM0_6_QCOEF24_0			(0x1u<<0)

// QMEM0_7 Configuration

#define	JPEG_QMEM0_7_QCOEF31			(0xFFu<<24)
#define	JPEG_QMEM0_7_QCOEF31_0			(0x1u<<24)
#define	JPEG_QMEM0_7_QCOEF30			(0xFFu<<16)
#define	JPEG_QMEM0_7_QCOEF30_0			(0x1u<<16)
#define	JPEG_QMEM0_7_QCOEF29			(0xFFu<<8)
#define	JPEG_QMEM0_7_QCOEF29_0			(0x1u<<8)
#define	JPEG_QMEM0_7_QCOEF28			(0xFFu<<0)
#define	JPEG_QMEM0_7_QCOEF28_0			(0x1u<<0)

// QMEM0_8 Configuration

#define	JPEG_QMEM0_8_QCOEF35			(0xFFu<<24)
#define	JPEG_QMEM0_8_QCOEF35_0			(0x1u<<24)
#define	JPEG_QMEM0_8_QCOEF34			(0xFFu<<16)
#define	JPEG_QMEM0_8_QCOEF34_0			(0x1u<<16)
#define	JPEG_QMEM0_8_QCOEF33			(0xFFu<<8)
#define	JPEG_QMEM0_8_QCOEF33_0			(0x1u<<8)
#define	JPEG_QMEM0_8_QCOEF32			(0xFFu<<0)
#define	JPEG_QMEM0_8_QCOEF32_0			(0x1u<<0)

// QMEM0_9 Configuration

#define	JPEG_QMEM0_9_QCOEF39			(0xFFu<<24)
#define	JPEG_QMEM0_9_QCOEF39_0			(0x1u<<24)
#define	JPEG_QMEM0_9_QCOEF38			(0xFFu<<16)
#define	JPEG_QMEM0_9_QCOEF38_0			(0x1u<<16)
#define	JPEG_QMEM0_9_QCOEF37			(0xFFu<<8)
#define	JPEG_QMEM0_9_QCOEF37_0			(0x1u<<8)
#define	JPEG_QMEM0_9_QCOEF36			(0xFFu<<0)
#define	JPEG_QMEM0_9_QCOEF36_0			(0x1u<<0)

// QMEM0_10 Configuration

#define	JPEG_QMEM0_10_QCOEF43			(0xFFu<<24)
#define	JPEG_QMEM0_10_QCOEF43_0			(0x1u<<24)
#define	JPEG_QMEM0_10_QCOEF42			(0xFFu<<16)
#define	JPEG_QMEM0_10_QCOEF42_0			(0x1u<<16)
#define	JPEG_QMEM0_10_QCOEF41			(0xFFu<<8)
#define	JPEG_QMEM0_10_QCOEF41_0			(0x1u<<8)
#define	JPEG_QMEM0_10_QCOEF40			(0xFFu<<0)
#define	JPEG_QMEM0_10_QCOEF40_0			(0x1u<<0)

// QMEM0_11 Configuration

#define	JPEG_QMEM0_11_QCOEF47			(0xFFu<<24)
#define	JPEG_QMEM0_11_QCOEF47_0			(0x1u<<24)
#define	JPEG_QMEM0_11_QCOEF46			(0xFFu<<16)
#define	JPEG_QMEM0_11_QCOEF46_0			(0x1u<<16)
#define	JPEG_QMEM0_11_QCOEF45			(0xFFu<<8)
#define	JPEG_QMEM0_11_QCOEF45_0			(0x1u<<8)
#define	JPEG_QMEM0_11_QCOEF44			(0xFFu<<0)
#define	JPEG_QMEM0_11_QCOEF44_0			(0x1u<<0)

// QMEM0_12 Configuration

#define	JPEG_QMEM0_12_QCOEF51			(0xFFu<<24)
#define	JPEG_QMEM0_12_QCOEF51_0			(0x1u<<24)
#define	JPEG_QMEM0_12_QCOEF50			(0xFFu<<16)
#define	JPEG_QMEM0_12_QCOEF50_0			(0x1u<<16)
#define	JPEG_QMEM0_12_QCOEF49			(0xFFu<<8)
#define	JPEG_QMEM0_12_QCOEF49_0			(0x1u<<8)
#define	JPEG_QMEM0_12_QCOEF48			(0xFFu<<0)
#define	JPEG_QMEM0_12_QCOEF48_0			(0x1u<<0)

// QMEM0_13 Configuration

#define	JPEG_QMEM0_13_QCOEF55			(0xFFu<<24)
#define	JPEG_QMEM0_13_QCOEF55_0			(0x1u<<24)
#define	JPEG_QMEM0_13_QCOEF54			(0xFFu<<16)
#define	JPEG_QMEM0_13_QCOEF54_0			(0x1u<<16)
#define	JPEG_QMEM0_13_QCOEF53			(0xFFu<<8)
#define	JPEG_QMEM0_13_QCOEF53_0			(0x1u<<8)
#define	JPEG_QMEM0_13_QCOEF52			(0xFFu<<0)
#define	JPEG_QMEM0_13_QCOEF52_0			(0x1u<<0)

// QMEM0_14 Configuration

#define	JPEG_QMEM0_14_QCOEF59			(0xFFu<<24)
#define	JPEG_QMEM0_14_QCOEF59_0			(0x1u<<24)
#define	JPEG_QMEM0_14_QCOEF58			(0xFFu<<16)
#define	JPEG_QMEM0_14_QCOEF58_0			(0x1u<<16)
#define	JPEG_QMEM0_14_QCOEF57			(0xFFu<<8)
#define	JPEG_QMEM0_14_QCOEF57_0			(0x1u<<8)
#define	JPEG_QMEM0_14_QCOEF56			(0xFFu<<0)
#define	JPEG_QMEM0_14_QCOEF56_0			(0x1u<<0)

// QMEM0_15 Configuration

#define	JPEG_QMEM0_15_QCOEF63			(0xFFu<<24)
#define	JPEG_QMEM0_15_QCOEF63_0			(0x1u<<24)
#define	JPEG_QMEM0_15_QCOEF62			(0xFFu<<16)
#define	JPEG_QMEM0_15_QCOEF62_0			(0x1u<<16)
#define	JPEG_QMEM0_15_QCOEF61			(0xFFu<<8)
#define	JPEG_QMEM0_15_QCOEF61_0			(0x1u<<8)
#define	JPEG_QMEM0_15_QCOEF60			(0xFFu<<0)
#define	JPEG_QMEM0_15_QCOEF60_0			(0x1u<<0)

// QMEM1_0 Configuration

#define	JPEG_QMEM1_0_QCOEF3				(0xFFu<<24)
#define	JPEG_QMEM1_0_QCOEF3_0			(0x1u<<24)
#define	JPEG_QMEM1_0_QCOEF2				(0xFFu<<16)
#define	JPEG_QMEM1_0_QCOEF2_0			(0x1u<<16)
#define	JPEG_QMEM1_0_QCOEF1				(0xFFu<<8)
#define	JPEG_QMEM1_0_QCOEF1_0			(0x1u<<8)
#define	JPEG_QMEM1_0_QCOEF0				(0xFFu<<0)
#define	JPEG_QMEM1_0_QCOEF0_0			(0x1u<<0)

// QMEM1_1 Configuration

#define	JPEG_QMEM1_1_QCOEF7				(0xFFu<<24)
#define	JPEG_QMEM1_1_QCOEF7_0			(0x1u<<24)
#define	JPEG_QMEM1_1_QCOEF6				(0xFFu<<16)
#define	JPEG_QMEM1_1_QCOEF6_0			(0x1u<<16)
#define	JPEG_QMEM1_1_QCOEF5				(0xFFu<<8)
#define	JPEG_QMEM1_1_QCOEF5_0			(0x1u<<8)
#define	JPEG_QMEM1_1_QCOEF4				(0xFFu<<0)
#define	JPEG_QMEM1_1_QCOEF4_0			(0x1u<<0)

// QMEM1_2 Configuration

#define	JPEG_QMEM1_2_QCOEF11			(0xFFu<<24)
#define	JPEG_QMEM1_2_QCOEF11_0			(0x1u<<24)
#define	JPEG_QMEM1_2_QCOEF10			(0xFFu<<16)
#define	JPEG_QMEM1_2_QCOEF10_0			(0x1u<<16)
#define	JPEG_QMEM1_2_QCOEF9				(0xFFu<<8)
#define	JPEG_QMEM1_2_QCOEF9_0			(0x1u<<8)
#define	JPEG_QMEM1_2_QCOEF8				(0xFFu<<0)
#define	JPEG_QMEM1_2_QCOEF8_0			(0x1u<<0)

// QMEM1_3 Configuration

#define	JPEG_QMEM1_3_QCOEF15			(0xFFu<<24)
#define	JPEG_QMEM1_3_QCOEF15_0			(0x1u<<24)
#define	JPEG_QMEM1_3_QCOEF14			(0xFFu<<16)
#define	JPEG_QMEM1_3_QCOEF14_0			(0x1u<<16)
#define	JPEG_QMEM1_3_QCOEF13			(0xFFu<<8)
#define	JPEG_QMEM1_3_QCOEF13_0			(0x1u<<8)
#define	JPEG_QMEM1_3_QCOEF12			(0xFFu<<0)
#define	JPEG_QMEM1_3_QCOEF12_0			(0x1u<<0)

// QMEM1_4 Configuration

#define	JPEG_QMEM1_4_QCOEF19			(0xFFu<<24)
#define	JPEG_QMEM1_4_QCOEF19_0			(0x1u<<24)
#define	JPEG_QMEM1_4_QCOEF18			(0xFFu<<16)
#define	JPEG_QMEM1_4_QCOEF18_0			(0x1u<<16)
#define	JPEG_QMEM1_4_QCOEF17			(0xFFu<<8)
#define	JPEG_QMEM1_4_QCOEF17_0			(0x1u<<8)
#define	JPEG_QMEM1_4_QCOEF16			(0xFFu<<0)
#define	JPEG_QMEM1_4_QCOEF16_0			(0x1u<<0)

// QMEM1_5 Configuration

#define	JPEG_QMEM1_5_QCOEF23			(0xFFu<<24)
#define	JPEG_QMEM1_5_QCOEF23_0			(0x1u<<24)
#define	JPEG_QMEM1_5_QCOEF22			(0xFFu<<16)
#define	JPEG_QMEM1_5_QCOEF22_0			(0x1u<<16)
#define	JPEG_QMEM1_5_QCOEF21			(0xFFu<<8)
#define	JPEG_QMEM1_5_QCOEF21_0			(0x1u<<8)
#define	JPEG_QMEM1_5_QCOEF20			(0xFFu<<0)
#define	JPEG_QMEM1_5_QCOEF20_0			(0x1u<<0)

// QMEM1_6 Configuration

#define	JPEG_QMEM1_6_QCOEF27			(0xFFu<<24)
#define	JPEG_QMEM1_6_QCOEF27_0			(0x1u<<24)
#define	JPEG_QMEM1_6_QCOEF26			(0xFFu<<16)
#define	JPEG_QMEM1_6_QCOEF26_0			(0x1u<<16)
#define	JPEG_QMEM1_6_QCOEF25			(0xFFu<<8)
#define	JPEG_QMEM1_6_QCOEF25_0			(0x1u<<8)
#define	JPEG_QMEM1_6_QCOEF24			(0xFFu<<0)
#define	JPEG_QMEM1_6_QCOEF24_0			(0x1u<<0)

// QMEM1_7 Configuration

#define	JPEG_QMEM1_7_QCOEF31			(0xFFu<<24)
#define	JPEG_QMEM1_7_QCOEF31_0			(0x1u<<24)
#define	JPEG_QMEM1_7_QCOEF30			(0xFFu<<16)
#define	JPEG_QMEM1_7_QCOEF30_0			(0x1u<<16)
#define	JPEG_QMEM1_7_QCOEF29			(0xFFu<<8)
#define	JPEG_QMEM1_7_QCOEF29_0			(0x1u<<8)
#define	JPEG_QMEM1_7_QCOEF28			(0xFFu<<0)
#define	JPEG_QMEM1_7_QCOEF28_0			(0x1u<<0)

// QMEM1_8 Configuration

#define	JPEG_QMEM1_8_QCOEF35			(0xFFu<<24)
#define	JPEG_QMEM1_8_QCOEF35_0			(0x1u<<24)
#define	JPEG_QMEM1_8_QCOEF34			(0xFFu<<16)
#define	JPEG_QMEM1_8_QCOEF34_0			(0x1u<<16)
#define	JPEG_QMEM1_8_QCOEF33			(0xFFu<<8)
#define	JPEG_QMEM1_8_QCOEF33_0			(0x1u<<8)
#define	JPEG_QMEM1_8_QCOEF32			(0xFFu<<0)
#define	JPEG_QMEM1_8_QCOEF32_0			(0x1u<<0)

// QMEM1_9 Configuration

#define	JPEG_QMEM1_9_QCOEF39			(0xFFu<<24)
#define	JPEG_QMEM1_9_QCOEF39_0			(0x1u<<24)
#define	JPEG_QMEM1_9_QCOEF38			(0xFFu<<16)
#define	JPEG_QMEM1_9_QCOEF38_0			(0x1u<<16)
#define	JPEG_QMEM1_9_QCOEF37			(0xFFu<<8)
#define	JPEG_QMEM1_9_QCOEF37_0			(0x1u<<8)
#define	JPEG_QMEM1_9_QCOEF36			(0xFFu<<0)
#define	JPEG_QMEM1_9_QCOEF36_0			(0x1u<<0)

// QMEM1_10 Configuration

#define	JPEG_QMEM1_10_QCOEF43			(0xFFu<<24)
#define	JPEG_QMEM1_10_QCOEF43_0			(0x1u<<24)
#define	JPEG_QMEM1_10_QCOEF42			(0xFFu<<16)
#define	JPEG_QMEM1_10_QCOEF42_0			(0x1u<<16)
#define	JPEG_QMEM1_10_QCOEF41			(0xFFu<<8)
#define	JPEG_QMEM1_10_QCOEF41_0			(0x1u<<8)
#define	JPEG_QMEM1_10_QCOEF40			(0xFFu<<0)
#define	JPEG_QMEM1_10_QCOEF40_0			(0x1u<<0)

// QMEM1_11 Configuration

#define	JPEG_QMEM1_11_QCOEF47			(0xFFu<<24)
#define	JPEG_QMEM1_11_QCOEF47_0			(0x1u<<24)
#define	JPEG_QMEM1_11_QCOEF46			(0xFFu<<16)
#define	JPEG_QMEM1_11_QCOEF46_0			(0x1u<<16)
#define	JPEG_QMEM1_11_QCOEF45			(0xFFu<<8)
#define	JPEG_QMEM1_11_QCOEF45_0			(0x1u<<8)
#define	JPEG_QMEM1_11_QCOEF44			(0xFFu<<0)
#define	JPEG_QMEM1_11_QCOEF44_0			(0x1u<<0)

// QMEM1_12 Configuration

#define	JPEG_QMEM1_12_QCOEF51			(0xFFu<<24)
#define	JPEG_QMEM1_12_QCOEF51_0			(0x1u<<24)
#define	JPEG_QMEM1_12_QCOEF50			(0xFFu<<16)
#define	JPEG_QMEM1_12_QCOEF50_0			(0x1u<<16)
#define	JPEG_QMEM1_12_QCOEF49			(0xFFu<<8)
#define	JPEG_QMEM1_12_QCOEF49_0			(0x1u<<8)
#define	JPEG_QMEM1_12_QCOEF48			(0xFFu<<0)
#define	JPEG_QMEM1_12_QCOEF48_0			(0x1u<<0)

// QMEM1_13 Configuration

#define	JPEG_QMEM1_13_QCOEF55			(0xFFu<<24)
#define	JPEG_QMEM1_13_QCOEF55_0			(0x1u<<24)
#define	JPEG_QMEM1_13_QCOEF54			(0xFFu<<16)
#define	JPEG_QMEM1_13_QCOEF54_0			(0x1u<<16)
#define	JPEG_QMEM1_13_QCOEF53			(0xFFu<<8)
#define	JPEG_QMEM1_13_QCOEF53_0			(0x1u<<8)
#define	JPEG_QMEM1_13_QCOEF52			(0xFFu<<0)
#define	JPEG_QMEM1_13_QCOEF52_0			(0x1u<<0)

// QMEM1_14 Configuration

#define	JPEG_QMEM1_14_QCOEF59			(0xFFu<<24)
#define	JPEG_QMEM1_14_QCOEF59_0			(0x1u<<24)
#define	JPEG_QMEM1_14_QCOEF58			(0xFFu<<16)
#define	JPEG_QMEM1_14_QCOEF58_0			(0x1u<<16)
#define	JPEG_QMEM1_14_QCOEF57			(0xFFu<<8)
#define	JPEG_QMEM1_14_QCOEF57_0			(0x1u<<8)
#define	JPEG_QMEM1_14_QCOEF56			(0xFFu<<0)
#define	JPEG_QMEM1_14_QCOEF56_0			(0x1u<<0)

// QMEM1_15 Configuration

#define	JPEG_QMEM1_15_QCOEF63			(0xFFu<<24)
#define	JPEG_QMEM1_15_QCOEF63_0			(0x1u<<24)
#define	JPEG_QMEM1_15_QCOEF62			(0xFFu<<16)
#define	JPEG_QMEM1_15_QCOEF62_0			(0x1u<<16)
#define	JPEG_QMEM1_15_QCOEF61			(0xFFu<<8)
#define	JPEG_QMEM1_15_QCOEF61_0			(0x1u<<8)
#define	JPEG_QMEM1_15_QCOEF60			(0xFFu<<0)
#define	JPEG_QMEM1_15_QCOEF60_0			(0x1u<<0)

// QMEM2_0 Configuration

#define	JPEG_QMEM2_0_QCOEF3				(0xFFu<<24)
#define	JPEG_QMEM2_0_QCOEF3_0			(0x1u<<24)
#define	JPEG_QMEM2_0_QCOEF2				(0xFFu<<16)
#define	JPEG_QMEM2_0_QCOEF2_0			(0x1u<<16)
#define	JPEG_QMEM2_0_QCOEF1				(0xFFu<<8)
#define	JPEG_QMEM2_0_QCOEF1_0			(0x1u<<8)
#define	JPEG_QMEM2_0_QCOEF0				(0xFFu<<0)
#define	JPEG_QMEM2_0_QCOEF0_0			(0x1u<<0)

// QMEM2_1 Configuration

#define	JPEG_QMEM2_1_QCOEF7				(0xFFu<<24)
#define	JPEG_QMEM2_1_QCOEF7_0			(0x1u<<24)
#define	JPEG_QMEM2_1_QCOEF6				(0xFFu<<16)
#define	JPEG_QMEM2_1_QCOEF6_0			(0x1u<<16)
#define	JPEG_QMEM2_1_QCOEF5				(0xFFu<<8)
#define	JPEG_QMEM2_1_QCOEF5_0			(0x1u<<8)
#define	JPEG_QMEM2_1_QCOEF4				(0xFFu<<0)
#define	JPEG_QMEM2_1_QCOEF4_0			(0x1u<<0)

// QMEM2_2 Configuration

#define	JPEG_QMEM2_2_QCOEF11			(0xFFu<<24)
#define	JPEG_QMEM2_2_QCOEF11_0			(0x1u<<24)
#define	JPEG_QMEM2_2_QCOEF10			(0xFFu<<16)
#define	JPEG_QMEM2_2_QCOEF10_0			(0x1u<<16)
#define	JPEG_QMEM2_2_QCOEF9				(0xFFu<<8)
#define	JPEG_QMEM2_2_QCOEF9_0			(0x1u<<8)
#define	JPEG_QMEM2_2_QCOEF8				(0xFFu<<0)
#define	JPEG_QMEM2_2_QCOEF8_0			(0x1u<<0)

// QMEM2_3 Configuration

#define	JPEG_QMEM2_3_QCOEF15			(0xFFu<<24)
#define	JPEG_QMEM2_3_QCOEF15_0			(0x1u<<24)
#define	JPEG_QMEM2_3_QCOEF14			(0xFFu<<16)
#define	JPEG_QMEM2_3_QCOEF14_0			(0x1u<<16)
#define	JPEG_QMEM2_3_QCOEF13			(0xFFu<<8)
#define	JPEG_QMEM2_3_QCOEF13_0			(0x1u<<8)
#define	JPEG_QMEM2_3_QCOEF12			(0xFFu<<0)
#define	JPEG_QMEM2_3_QCOEF12_0			(0x1u<<0)

// QMEM2_4 Configuration

#define	JPEG_QMEM2_4_QCOEF19			(0xFFu<<24)
#define	JPEG_QMEM2_4_QCOEF19_0			(0x1u<<24)
#define	JPEG_QMEM2_4_QCOEF18			(0xFFu<<16)
#define	JPEG_QMEM2_4_QCOEF18_0			(0x1u<<16)
#define	JPEG_QMEM2_4_QCOEF17			(0xFFu<<8)
#define	JPEG_QMEM2_4_QCOEF17_0			(0x1u<<8)
#define	JPEG_QMEM2_4_QCOEF16			(0xFFu<<0)
#define	JPEG_QMEM2_4_QCOEF16_0			(0x1u<<0)

// QMEM2_5 Configuration

#define	JPEG_QMEM2_5_QCOEF23			(0xFFu<<24)
#define	JPEG_QMEM2_5_QCOEF23_0			(0x1u<<24)
#define	JPEG_QMEM2_5_QCOEF22			(0xFFu<<16)
#define	JPEG_QMEM2_5_QCOEF22_0			(0x1u<<16)
#define	JPEG_QMEM2_5_QCOEF21			(0xFFu<<8)
#define	JPEG_QMEM2_5_QCOEF21_0			(0x1u<<8)
#define	JPEG_QMEM2_5_QCOEF20			(0xFFu<<0)
#define	JPEG_QMEM2_5_QCOEF20_0			(0x1u<<0)

// QMEM2_6 Configuration

#define	JPEG_QMEM2_6_QCOEF27			(0xFFu<<24)
#define	JPEG_QMEM2_6_QCOEF27_0			(0x1u<<24)
#define	JPEG_QMEM2_6_QCOEF26			(0xFFu<<16)
#define	JPEG_QMEM2_6_QCOEF26_0			(0x1u<<16)
#define	JPEG_QMEM2_6_QCOEF25			(0xFFu<<8)
#define	JPEG_QMEM2_6_QCOEF25_0			(0x1u<<8)
#define	JPEG_QMEM2_6_QCOEF24			(0xFFu<<0)
#define	JPEG_QMEM2_6_QCOEF24_0			(0x1u<<0)

// QMEM2_7 Configuration

#define	JPEG_QMEM2_7_QCOEF31			(0xFFu<<24)
#define	JPEG_QMEM2_7_QCOEF31_0			(0x1u<<24)
#define	JPEG_QMEM2_7_QCOEF30			(0xFFu<<16)
#define	JPEG_QMEM2_7_QCOEF30_0			(0x1u<<16)
#define	JPEG_QMEM2_7_QCOEF29			(0xFFu<<8)
#define	JPEG_QMEM2_7_QCOEF29_0			(0x1u<<8)
#define	JPEG_QMEM2_7_QCOEF28			(0xFFu<<0)
#define	JPEG_QMEM2_7_QCOEF28_0			(0x1u<<0)

// QMEM2_8 Configuration

#define	JPEG_QMEM2_8_QCOEF35			(0xFFu<<24)
#define	JPEG_QMEM2_8_QCOEF35_0			(0x1u<<24)
#define	JPEG_QMEM2_8_QCOEF34			(0xFFu<<16)
#define	JPEG_QMEM2_8_QCOEF34_0			(0x1u<<16)
#define	JPEG_QMEM2_8_QCOEF33			(0xFFu<<8)
#define	JPEG_QMEM2_8_QCOEF33_0			(0x1u<<8)
#define	JPEG_QMEM2_8_QCOEF32			(0xFFu<<0)
#define	JPEG_QMEM2_8_QCOEF32_0			(0x1u<<0)

// QMEM2_9 Configuration

#define	JPEG_QMEM2_9_QCOEF39			(0xFFu<<24)
#define	JPEG_QMEM2_9_QCOEF39_0			(0x1u<<24)
#define	JPEG_QMEM2_9_QCOEF38			(0xFFu<<16)
#define	JPEG_QMEM2_9_QCOEF38_0			(0x1u<<16)
#define	JPEG_QMEM2_9_QCOEF37			(0xFFu<<8)
#define	JPEG_QMEM2_9_QCOEF37_0			(0x1u<<8)
#define	JPEG_QMEM2_9_QCOEF36			(0xFFu<<0)
#define	JPEG_QMEM2_9_QCOEF36_0			(0x1u<<0)

// QMEM2_10 Configuration

#define	JPEG_QMEM2_10_QCOEF43			(0xFFu<<24)
#define	JPEG_QMEM2_10_QCOEF43_0			(0x1u<<24)
#define	JPEG_QMEM2_10_QCOEF42			(0xFFu<<16)
#define	JPEG_QMEM2_10_QCOEF42_0			(0x1u<<16)
#define	JPEG_QMEM2_10_QCOEF41			(0xFFu<<8)
#define	JPEG_QMEM2_10_QCOEF41_0			(0x1u<<8)
#define	JPEG_QMEM2_10_QCOEF40			(0xFFu<<0)
#define	JPEG_QMEM2_10_QCOEF40_0			(0x1u<<0)

// QMEM2_11 Configuration

#define	JPEG_QMEM2_11_QCOEF47			(0xFFu<<24)
#define	JPEG_QMEM2_11_QCOEF47_0			(0x1u<<24)
#define	JPEG_QMEM2_11_QCOEF46			(0xFFu<<16)
#define	JPEG_QMEM2_11_QCOEF46_0			(0x1u<<16)
#define	JPEG_QMEM2_11_QCOEF45			(0xFFu<<8)
#define	JPEG_QMEM2_11_QCOEF45_0			(0x1u<<8)
#define	JPEG_QMEM2_11_QCOEF44			(0xFFu<<0)
#define	JPEG_QMEM2_11_QCOEF44_0			(0x1u<<0)

// QMEM2_12 Configuration

#define	JPEG_QMEM2_12_QCOEF51			(0xFFu<<24)
#define	JPEG_QMEM2_12_QCOEF51_0			(0x1u<<24)
#define	JPEG_QMEM2_12_QCOEF50			(0xFFu<<16)
#define	JPEG_QMEM2_12_QCOEF50_0			(0x1u<<16)
#define	JPEG_QMEM2_12_QCOEF49			(0xFFu<<8)
#define	JPEG_QMEM2_12_QCOEF49_0			(0x1u<<8)
#define	JPEG_QMEM2_12_QCOEF48			(0xFFu<<0)
#define	JPEG_QMEM2_12_QCOEF48_0			(0x1u<<0)

// QMEM2_13 Configuration

#define	JPEG_QMEM2_13_QCOEF55			(0xFFu<<24)
#define	JPEG_QMEM2_13_QCOEF55_0			(0x1u<<24)
#define	JPEG_QMEM2_13_QCOEF54			(0xFFu<<16)
#define	JPEG_QMEM2_13_QCOEF54_0			(0x1u<<16)
#define	JPEG_QMEM2_13_QCOEF53			(0xFFu<<8)
#define	JPEG_QMEM2_13_QCOEF53_0			(0x1u<<8)
#define	JPEG_QMEM2_13_QCOEF52			(0xFFu<<0)
#define	JPEG_QMEM2_13_QCOEF52_0			(0x1u<<0)

// QMEM2_14 Configuration

#define	JPEG_QMEM2_14_QCOEF59			(0xFFu<<24)
#define	JPEG_QMEM2_14_QCOEF59_0			(0x1u<<24)
#define	JPEG_QMEM2_14_QCOEF58			(0xFFu<<16)
#define	JPEG_QMEM2_14_QCOEF58_0			(0x1u<<16)
#define	JPEG_QMEM2_14_QCOEF57			(0xFFu<<8)
#define	JPEG_QMEM2_14_QCOEF57_0			(0x1u<<8)
#define	JPEG_QMEM2_14_QCOEF56			(0xFFu<<0)
#define	JPEG_QMEM2_14_QCOEF56_0			(0x1u<<0)

// QMEM2_15 Configuration

#define	JPEG_QMEM2_15_QCOEF63			(0xFFu<<24)
#define	JPEG_QMEM2_15_QCOEF63_0			(0x1u<<24)
#define	JPEG_QMEM2_15_QCOEF62			(0xFFu<<16)
#define	JPEG_QMEM2_15_QCOEF62_0			(0x1u<<16)
#define	JPEG_QMEM2_15_QCOEF61			(0xFFu<<8)
#define	JPEG_QMEM2_15_QCOEF61_0			(0x1u<<8)
#define	JPEG_QMEM2_15_QCOEF60			(0xFFu<<0)
#define	JPEG_QMEM2_15_QCOEF60_0			(0x1u<<0)

// QMEM3_0 Configuration

#define	JPEG_QMEM3_0_QCOEF3				(0xFFu<<24)
#define	JPEG_QMEM3_0_QCOEF3_0			(0x1u<<24)
#define	JPEG_QMEM3_0_QCOEF2				(0xFFu<<16)
#define	JPEG_QMEM3_0_QCOEF2_0			(0x1u<<16)
#define	JPEG_QMEM3_0_QCOEF1				(0xFFu<<8)
#define	JPEG_QMEM3_0_QCOEF1_0			(0x1u<<8)
#define	JPEG_QMEM3_0_QCOEF0				(0xFFu<<0)
#define	JPEG_QMEM3_0_QCOEF0_0			(0x1u<<0)

// QMEM3_1 Configuration

#define	JPEG_QMEM3_1_QCOEF7				(0xFFu<<24)
#define	JPEG_QMEM3_1_QCOEF7_0			(0x1u<<24)
#define	JPEG_QMEM3_1_QCOEF6				(0xFFu<<16)
#define	JPEG_QMEM3_1_QCOEF6_0			(0x1u<<16)
#define	JPEG_QMEM3_1_QCOEF5				(0xFFu<<8)
#define	JPEG_QMEM3_1_QCOEF5_0			(0x1u<<8)
#define	JPEG_QMEM3_1_QCOEF4				(0xFFu<<0)
#define	JPEG_QMEM3_1_QCOEF4_0			(0x1u<<0)

// QMEM3_2 Configuration

#define	JPEG_QMEM3_2_QCOEF11			(0xFFu<<24)
#define	JPEG_QMEM3_2_QCOEF11_0			(0x1u<<24)
#define	JPEG_QMEM3_2_QCOEF10			(0xFFu<<16)
#define	JPEG_QMEM3_2_QCOEF10_0			(0x1u<<16)
#define	JPEG_QMEM3_2_QCOEF9				(0xFFu<<8)
#define	JPEG_QMEM3_2_QCOEF9_0			(0x1u<<8)
#define	JPEG_QMEM3_2_QCOEF8				(0xFFu<<0)
#define	JPEG_QMEM3_2_QCOEF8_0			(0x1u<<0)

// QMEM3_3 Configuration

#define	JPEG_QMEM3_3_QCOEF15			(0xFFu<<24)
#define	JPEG_QMEM3_3_QCOEF15_0			(0x1u<<24)
#define	JPEG_QMEM3_3_QCOEF14			(0xFFu<<16)
#define	JPEG_QMEM3_3_QCOEF14_0			(0x1u<<16)
#define	JPEG_QMEM3_3_QCOEF13			(0xFFu<<8)
#define	JPEG_QMEM3_3_QCOEF13_0			(0x1u<<8)
#define	JPEG_QMEM3_3_QCOEF12			(0xFFu<<0)
#define	JPEG_QMEM3_3_QCOEF12_0			(0x1u<<0)

// QMEM3_4 Configuration

#define	JPEG_QMEM3_4_QCOEF19			(0xFFu<<24)
#define	JPEG_QMEM3_4_QCOEF19_0			(0x1u<<24)
#define	JPEG_QMEM3_4_QCOEF18			(0xFFu<<16)
#define	JPEG_QMEM3_4_QCOEF18_0			(0x1u<<16)
#define	JPEG_QMEM3_4_QCOEF17			(0xFFu<<8)
#define	JPEG_QMEM3_4_QCOEF17_0			(0x1u<<8)
#define	JPEG_QMEM3_4_QCOEF16			(0xFFu<<0)
#define	JPEG_QMEM3_4_QCOEF16_0			(0x1u<<0)

// QMEM3_5 Configuration

#define	JPEG_QMEM3_5_QCOEF23			(0xFFu<<24)
#define	JPEG_QMEM3_5_QCOEF23_0			(0x1u<<24)
#define	JPEG_QMEM3_5_QCOEF22			(0xFFu<<16)
#define	JPEG_QMEM3_5_QCOEF22_0			(0x1u<<16)
#define	JPEG_QMEM3_5_QCOEF21			(0xFFu<<8)
#define	JPEG_QMEM3_5_QCOEF21_0			(0x1u<<8)
#define	JPEG_QMEM3_5_QCOEF20			(0xFFu<<0)
#define	JPEG_QMEM3_5_QCOEF20_0			(0x1u<<0)

// QMEM3_6 Configuration

#define	JPEG_QMEM3_6_QCOEF27			(0xFFu<<24)
#define	JPEG_QMEM3_6_QCOEF27_0			(0x1u<<24)
#define	JPEG_QMEM3_6_QCOEF26			(0xFFu<<16)
#define	JPEG_QMEM3_6_QCOEF26_0			(0x1u<<16)
#define	JPEG_QMEM3_6_QCOEF25			(0xFFu<<8)
#define	JPEG_QMEM3_6_QCOEF25_0			(0x1u<<8)
#define	JPEG_QMEM3_6_QCOEF24			(0xFFu<<0)
#define	JPEG_QMEM3_6_QCOEF24_0			(0x1u<<0)

// QMEM3_7 Configuration

#define	JPEG_QMEM3_7_QCOEF31			(0xFFu<<24)
#define	JPEG_QMEM3_7_QCOEF31_0			(0x1u<<24)
#define	JPEG_QMEM3_7_QCOEF30			(0xFFu<<16)
#define	JPEG_QMEM3_7_QCOEF30_0			(0x1u<<16)
#define	JPEG_QMEM3_7_QCOEF29			(0xFFu<<8)
#define	JPEG_QMEM3_7_QCOEF29_0			(0x1u<<8)
#define	JPEG_QMEM3_7_QCOEF28			(0xFFu<<0)
#define	JPEG_QMEM3_7_QCOEF28_0			(0x1u<<0)

// QMEM3_8 Configuration

#define	JPEG_QMEM3_8_QCOEF35			(0xFFu<<24)
#define	JPEG_QMEM3_8_QCOEF35_0			(0x1u<<24)
#define	JPEG_QMEM3_8_QCOEF34			(0xFFu<<16)
#define	JPEG_QMEM3_8_QCOEF34_0			(0x1u<<16)
#define	JPEG_QMEM3_8_QCOEF33			(0xFFu<<8)
#define	JPEG_QMEM3_8_QCOEF33_0			(0x1u<<8)
#define	JPEG_QMEM3_8_QCOEF32			(0xFFu<<0)
#define	JPEG_QMEM3_8_QCOEF32_0			(0x1u<<0)

// QMEM3_9 Configuration

#define	JPEG_QMEM3_9_QCOEF39			(0xFFu<<24)
#define	JPEG_QMEM3_9_QCOEF39_0			(0x1u<<24)
#define	JPEG_QMEM3_9_QCOEF38			(0xFFu<<16)
#define	JPEG_QMEM3_9_QCOEF38_0			(0x1u<<16)
#define	JPEG_QMEM3_9_QCOEF37			(0xFFu<<8)
#define	JPEG_QMEM3_9_QCOEF37_0			(0x1u<<8)
#define	JPEG_QMEM3_9_QCOEF36			(0xFFu<<0)
#define	JPEG_QMEM3_9_QCOEF36_0			(0x1u<<0)

// QMEM3_10 Configuration

#define	JPEG_QMEM3_10_QCOEF43			(0xFFu<<24)
#define	JPEG_QMEM3_10_QCOEF43_0			(0x1u<<24)
#define	JPEG_QMEM3_10_QCOEF42			(0xFFu<<16)
#define	JPEG_QMEM3_10_QCOEF42_0			(0x1u<<16)
#define	JPEG_QMEM3_10_QCOEF41			(0xFFu<<8)
#define	JPEG_QMEM3_10_QCOEF41_0			(0x1u<<8)
#define	JPEG_QMEM3_10_QCOEF40			(0xFFu<<0)
#define	JPEG_QMEM3_10_QCOEF40_0			(0x1u<<0)

// QMEM3_11 Configuration

#define	JPEG_QMEM3_11_QCOEF47			(0xFFu<<24)
#define	JPEG_QMEM3_11_QCOEF47_0			(0x1u<<24)
#define	JPEG_QMEM3_11_QCOEF46			(0xFFu<<16)
#define	JPEG_QMEM3_11_QCOEF46_0			(0x1u<<16)
#define	JPEG_QMEM3_11_QCOEF45			(0xFFu<<8)
#define	JPEG_QMEM3_11_QCOEF45_0			(0x1u<<8)
#define	JPEG_QMEM3_11_QCOEF44			(0xFFu<<0)
#define	JPEG_QMEM3_11_QCOEF44_0			(0x1u<<0)

// QMEM3_12 Configuration

#define	JPEG_QMEM3_12_QCOEF51			(0xFFu<<24)
#define	JPEG_QMEM3_12_QCOEF51_0			(0x1u<<24)
#define	JPEG_QMEM3_12_QCOEF50			(0xFFu<<16)
#define	JPEG_QMEM3_12_QCOEF50_0			(0x1u<<16)
#define	JPEG_QMEM3_12_QCOEF49			(0xFFu<<8)
#define	JPEG_QMEM3_12_QCOEF49_0			(0x1u<<8)
#define	JPEG_QMEM3_12_QCOEF48			(0xFFu<<0)
#define	JPEG_QMEM3_12_QCOEF48_0			(0x1u<<0)

// QMEM3_13 Configuration

#define	JPEG_QMEM3_13_QCOEF55			(0xFFu<<24)
#define	JPEG_QMEM3_13_QCOEF55_0			(0x1u<<24)
#define	JPEG_QMEM3_13_QCOEF54			(0xFFu<<16)
#define	JPEG_QMEM3_13_QCOEF54_0			(0x1u<<16)
#define	JPEG_QMEM3_13_QCOEF53			(0xFFu<<8)
#define	JPEG_QMEM3_13_QCOEF53_0			(0x1u<<8)
#define	JPEG_QMEM3_13_QCOEF52			(0xFFu<<0)
#define	JPEG_QMEM3_13_QCOEF52_0			(0x1u<<0)

// QMEM3_14 Configuration

#define	JPEG_QMEM3_14_QCOEF59			(0xFFu<<24)
#define	JPEG_QMEM3_14_QCOEF59_0			(0x1u<<24)
#define	JPEG_QMEM3_14_QCOEF58			(0xFFu<<16)
#define	JPEG_QMEM3_14_QCOEF58_0			(0x1u<<16)
#define	JPEG_QMEM3_14_QCOEF57			(0xFFu<<8)
#define	JPEG_QMEM3_14_QCOEF57_0			(0x1u<<8)
#define	JPEG_QMEM3_14_QCOEF56			(0xFFu<<0)
#define	JPEG_QMEM3_14_QCOEF56_0			(0x1u<<0)

// QMEM3_15 Configuration

#define	JPEG_QMEM3_15_QCOEF63			(0xFFu<<24)
#define	JPEG_QMEM3_15_QCOEF63_0			(0x1u<<24)
#define	JPEG_QMEM3_15_QCOEF62			(0xFFu<<16)
#define	JPEG_QMEM3_15_QCOEF62_0			(0x1u<<16)
#define	JPEG_QMEM3_15_QCOEF61			(0xFFu<<8)
#define	JPEG_QMEM3_15_QCOEF61_0			(0x1u<<8)
#define	JPEG_QMEM3_15_QCOEF60			(0xFFu<<0)
#define	JPEG_QMEM3_15_QCOEF60_0			(0x1u<<0)

// HUFFMIN0_0 Configuration

#define	JPEG_HUFFMIN0_0_DATA0			(0xFFFFFFFFu<<0)
#define	JPEG_HUFFMIN0_0_DATA0_0			(0x1u<<0)

// HUFFMIN0_1 Configuration

#define	JPEG_HUFFMIN0_1_DATA0			(0xFFFFFFFFu<<0)
#define	JPEG_HUFFMIN0_1_DATA0_0			(0x1u<<0)

// HUFFMIN0_2 Configuration

#define	JPEG_HUFFMIN0_2_DATA0			(0xFFFFFFFFu<<0)
#define	JPEG_HUFFMIN0_2_DATA0_0			(0x1u<<0)

// HUFFMIN0_3 Configuration

#define	JPEG_HUFFMIN0_3_DATA0			(0xFu<<0)
#define	JPEG_HUFFMIN0_3_DATA0_0			(0x1u<<0)

// HUFFMIN1_0 Configuration

#define	JPEG_HUFFMIN1_0_DATA1			(0xFFFFFFFFu<<0)
#define	JPEG_HUFFMIN1_0_DATA1_0			(0x1u<<0)

// HUFFMIN1_1 Configuration

#define	JPEG_HUFFMIN1_1_DATA1			(0xFFFFFFFFu<<0)
#define	JPEG_HUFFMIN1_1_DATA1_0			(0x1u<<0)

// HUFFMIN1_2 Configuration

#define	JPEG_HUFFMIN1_2_DATA1			(0xFFFFFFFFu<<0)
#define	JPEG_HUFFMIN1_2_DATA1_0			(0x1u<<0)

// HUFFMIN1_3 Configuration

#define	JPEG_HUFFMIN1_3_DATA1			(0xFu<<0)
#define	JPEG_HUFFMIN1_3_DATA1_0			(0x1u<<0)

// HUFFMIN2_0 Configuration

#define	JPEG_HUFFMIN2_0_DATA2			(0xFFFFFFFFu<<0)
#define	JPEG_HUFFMIN2_0_DATA2_0			(0x1u<<0)

// HUFFMIN2_1 Configuration

#define	JPEG_HUFFMIN2_1_DATA2			(0xFFFFFFFFu<<0)
#define	JPEG_HUFFMIN2_1_DATA2_0			(0x1u<<0)

// HUFFMIN2_2 Configuration

#define	JPEG_HUFFMIN2_2_DATA2			(0xFFFFFFFFu<<0)
#define	JPEG_HUFFMIN2_2_DATA2_0			(0x1u<<0)

// HUFFMIN2_3 Configuration

#define	JPEG_HUFFMIN2_3_DATA2			(0xFu<<0)
#define	JPEG_HUFFMIN2_3_DATA2_0			(0x1u<<0)

// HUFFMIN3_0 Configuration

#define	JPEG_HUFFMIN3_0_DATA3			(0xFFFFFFFFu<<0)
#define	JPEG_HUFFMIN3_0_DATA3_0			(0x1u<<0)

// HUFFMIN3_1 Configuration

#define	JPEG_HUFFMIN3_1_DATA3			(0xFFFFFFFFu<<0)
#define	JPEG_HUFFMIN3_1_DATA3_0			(0x1u<<0)

// HUFFMIN3_2 Configuration

#define	JPEG_HUFFMIN3_2_DATA3			(0xFFFFFFFFu<<0)
#define	JPEG_HUFFMIN3_2_DATA3_0			(0x1u<<0)

// HUFFMIN3_3 Configuration

#define	JPEG_HUFFMIN3_3_DATA3			(0xFu<<0)
#define	JPEG_HUFFMIN3_3_DATA3_0			(0x1u<<0)

// HUFFBASE0 Configuration

#define	JPEG_HUFFBASE0_DATA1			(0x1FFu<<16)
#define	JPEG_HUFFBASE0_DATA1_0			(0x1u<<16)
#define	JPEG_HUFFBASE0_DATA0			(0x1FFu<<0)
#define	JPEG_HUFFBASE0_DATA0_0			(0x1u<<0)

// HUFFBASE1 Configuration

#define	JPEG_HUFFBASE1_DATA3			(0x1FFu<<16)
#define	JPEG_HUFFBASE1_DATA3_0			(0x1u<<16)
#define	JPEG_HUFFBASE1_DATA2			(0x1FFu<<0)
#define	JPEG_HUFFBASE1_DATA2_0			(0x1u<<0)

// HUFFBASE2 Configuration

#define	JPEG_HUFFBASE2_DATA5			(0x1FFu<<16)
#define	JPEG_HUFFBASE2_DATA5_0			(0x1u<<16)
#define	JPEG_HUFFBASE2_DATA4			(0x1FFu<<0)
#define	JPEG_HUFFBASE2_DATA4_0			(0x1u<<0)

// HUFFBASE3 Configuration

#define	JPEG_HUFFBASE3_DATA7			(0x1FFu<<16)
#define	JPEG_HUFFBASE3_DATA7_0			(0x1u<<16)
#define	JPEG_HUFFBASE3_DATA6			(0x1FFu<<0)
#define	JPEG_HUFFBASE3_DATA6_0			(0x1u<<0)

// HUFFBASE4 Configuration

#define	JPEG_HUFFBASE4_DATA9			(0x1FFu<<16)
#define	JPEG_HUFFBASE4_DATA9_0			(0x1u<<16)
#define	JPEG_HUFFBASE4_DATA8			(0x1FFu<<0)
#define	JPEG_HUFFBASE4_DATA8_0			(0x1u<<0)

// HUFFBASE5 Configuration

#define	JPEG_HUFFBASE5_DATA11			(0x1FFu<<16)
#define	JPEG_HUFFBASE5_DATA11_0			(0x1u<<16)
#define	JPEG_HUFFBASE5_DATA10			(0x1FFu<<0)
#define	JPEG_HUFFBASE5_DATA10_0			(0x1u<<0)

// HUFFBASE6 Configuration

#define	JPEG_HUFFBASE6_DATA13			(0x1FFu<<16)
#define	JPEG_HUFFBASE6_DATA13_0			(0x1u<<16)
#define	JPEG_HUFFBASE6_DATA12			(0x1FFu<<0)
#define	JPEG_HUFFBASE6_DATA12_0			(0x1u<<0)

// HUFFBASE7 Configuration

#define	JPEG_HUFFBASE7_DATA15			(0x1FFu<<16)
#define	JPEG_HUFFBASE7_DATA15_0			(0x1u<<16)
#define	JPEG_HUFFBASE7_DATA14			(0x1FFu<<0)
#define	JPEG_HUFFBASE7_DATA14_0			(0x1u<<0)

// HUFFBASE8 Configuration

#define	JPEG_HUFFBASE8_DATA17			(0x1FFu<<16)
#define	JPEG_HUFFBASE8_DATA17_0			(0x1u<<16)
#define	JPEG_HUFFBASE8_DATA16			(0x1FFu<<0)
#define	JPEG_HUFFBASE8_DATA16_0			(0x1u<<0)

// HUFFBASE9 Configuration

#define	JPEG_HUFFBASE9_DATA19			(0x1FFu<<16)
#define	JPEG_HUFFBASE9_DATA19_0			(0x1u<<16)
#define	JPEG_HUFFBASE9_DATA18			(0x1FFu<<0)
#define	JPEG_HUFFBASE9_DATA18_0			(0x1u<<0)

// HUFFBASE10 Configuration

#define	JPEG_HUFFBASE10_DATA21			(0x1FFu<<16)
#define	JPEG_HUFFBASE10_DATA21_0		(0x1u<<16)
#define	JPEG_HUFFBASE10_DATA20			(0x1FFu<<0)
#define	JPEG_HUFFBASE10_DATA20_0		(0x1u<<0)

// HUFFBASE11 Configuration

#define	JPEG_HUFFBASE11_DATA23			(0x1FFu<<16)
#define	JPEG_HUFFBASE11_DATA23_0		(0x1u<<16)
#define	JPEG_HUFFBASE11_DATA22			(0x1FFu<<0)
#define	JPEG_HUFFBASE11_DATA22_0		(0x1u<<0)

// HUFFBASE12 Configuration

#define	JPEG_HUFFBASE12_DATA25			(0x1FFu<<16)
#define	JPEG_HUFFBASE12_DATA25_0		(0x1u<<16)
#define	JPEG_HUFFBASE12_DATA24			(0x1FFu<<0)
#define	JPEG_HUFFBASE12_DATA24_0		(0x1u<<0)

// HUFFBASE13 Configuration

#define	JPEG_HUFFBASE13_DATA27			(0x1FFu<<16)
#define	JPEG_HUFFBASE13_DATA27_0		(0x1u<<16)
#define	JPEG_HUFFBASE13_DATA26			(0x1FFu<<0)
#define	JPEG_HUFFBASE13_DATA26_0		(0x1u<<0)

// HUFFBASE14 Configuration

#define	JPEG_HUFFBASE14_DATA29			(0x1FFu<<16)
#define	JPEG_HUFFBASE14_DATA29_0		(0x1u<<16)
#define	JPEG_HUFFBASE14_DATA28			(0x1FFu<<0)
#define	JPEG_HUFFBASE14_DATA28_0		(0x1u<<0)

// HUFFBASE15 Configuration

#define	JPEG_HUFFBASE15_DATA31			(0x1FFu<<16)
#define	JPEG_HUFFBASE15_DATA31_0		(0x1u<<16)
#define	JPEG_HUFFBASE15_DATA30			(0x1FFu<<0)
#define	JPEG_HUFFBASE15_DATA30_0		(0x1u<<0)

// HUFFBASE16 Configuration

#define	JPEG_HUFFBASE16_DATA33			(0x1FFu<<16)
#define	JPEG_HUFFBASE16_DATA33_0		(0x1u<<16)
#define	JPEG_HUFFBASE16_DATA32			(0x1FFu<<0)
#define	JPEG_HUFFBASE16_DATA32_0		(0x1u<<0)

// HUFFBASE17 Configuration

#define	JPEG_HUFFBASE17_DATA35			(0x1FFu<<16)
#define	JPEG_HUFFBASE17_DATA35_0		(0x1u<<16)
#define	JPEG_HUFFBASE17_DATA34			(0x1FFu<<0)
#define	JPEG_HUFFBASE17_DATA34_0		(0x1u<<0)

// HUFFBASE18 Configuration

#define	JPEG_HUFFBASE18_DATA37			(0x1FFu<<16)
#define	JPEG_HUFFBASE18_DATA37_0		(0x1u<<16)
#define	JPEG_HUFFBASE18_DATA36			(0x1FFu<<0)
#define	JPEG_HUFFBASE18_DATA36_0		(0x1u<<0)

// HUFFBASE19 Configuration

#define	JPEG_HUFFBASE19_DATA39			(0x1FFu<<16)
#define	JPEG_HUFFBASE19_DATA39_0		(0x1u<<16)
#define	JPEG_HUFFBASE19_DATA38			(0x1FFu<<0)
#define	JPEG_HUFFBASE19_DATA38_0		(0x1u<<0)

// HUFFBASE20 Configuration

#define	JPEG_HUFFBASE20_DATA41			(0x1FFu<<16)
#define	JPEG_HUFFBASE20_DATA41_0		(0x1u<<16)
#define	JPEG_HUFFBASE20_DATA40			(0x1FFu<<0)
#define	JPEG_HUFFBASE20_DATA40_0		(0x1u<<0)

// HUFFBASE21 Configuration

#define	JPEG_HUFFBASE21_DATA43			(0x1FFu<<16)
#define	JPEG_HUFFBASE21_DATA43_0		(0x1u<<16)
#define	JPEG_HUFFBASE21_DATA42			(0x1FFu<<0)
#define	JPEG_HUFFBASE21_DATA42_0		(0x1u<<0)

// HUFFBASE22 Configuration

#define	JPEG_HUFFBASE22_DATA45			(0x1FFu<<16)
#define	JPEG_HUFFBASE22_DATA45_0		(0x1u<<16)
#define	JPEG_HUFFBASE22_DATA44			(0x1FFu<<0)
#define	JPEG_HUFFBASE22_DATA44_0		(0x1u<<0)

// HUFFBASE23 Configuration

#define	JPEG_HUFFBASE23_DATA47			(0x1FFu<<16)
#define	JPEG_HUFFBASE23_DATA47_0		(0x1u<<16)
#define	JPEG_HUFFBASE23_DATA46			(0x1FFu<<0)
#define	JPEG_HUFFBASE23_DATA46_0		(0x1u<<0)

// HUFFBASE24 Configuration

#define	JPEG_HUFFBASE24_DATA49			(0x1FFu<<16)
#define	JPEG_HUFFBASE24_DATA49_0		(0x1u<<16)
#define	JPEG_HUFFBASE24_DATA48			(0x1FFu<<0)
#define	JPEG_HUFFBASE24_DATA48_0		(0x1u<<0)

// HUFFBASE25 Configuration

#define	JPEG_HUFFBASE25_DATA51			(0x1FFu<<16)
#define	JPEG_HUFFBASE25_DATA51_0		(0x1u<<16)
#define	JPEG_HUFFBASE25_DATA50			(0x1FFu<<0)
#define	JPEG_HUFFBASE25_DATA50_0		(0x1u<<0)

// HUFFBASE26 Configuration

#define	JPEG_HUFFBASE26_DATA53			(0x1FFu<<16)
#define	JPEG_HUFFBASE26_DATA53_0		(0x1u<<16)
#define	JPEG_HUFFBASE26_DATA52			(0x1FFu<<0)
#define	JPEG_HUFFBASE26_DATA52_0		(0x1u<<0)

// HUFFBASE27 Configuration

#define	JPEG_HUFFBASE27_DATA55			(0x1FFu<<16)
#define	JPEG_HUFFBASE27_DATA55_0		(0x1u<<16)
#define	JPEG_HUFFBASE27_DATA54			(0x1FFu<<0)
#define	JPEG_HUFFBASE27_DATA54_0		(0x1u<<0)

// HUFFBASE28 Configuration

#define	JPEG_HUFFBASE28_DATA57			(0x1FFu<<16)
#define	JPEG_HUFFBASE28_DATA57_0		(0x1u<<16)
#define	JPEG_HUFFBASE28_DATA56			(0x1FFu<<0)
#define	JPEG_HUFFBASE28_DATA56_0		(0x1u<<0)

// HUFFBASE29 Configuration

#define	JPEG_HUFFBASE29_DATA59			(0x1FFu<<16)
#define	JPEG_HUFFBASE29_DATA59_0		(0x1u<<16)
#define	JPEG_HUFFBASE29_DATA58			(0x1FFu<<0)
#define	JPEG_HUFFBASE29_DATA58_0		(0x1u<<0)

// HUFFBASE30 Configuration

#define	JPEG_HUFFBASE30_DATA61			(0x1FFu<<16)
#define	JPEG_HUFFBASE30_DATA61_0		(0x1u<<16)
#define	JPEG_HUFFBASE30_DATA60			(0x1FFu<<0)
#define	JPEG_HUFFBASE30_DATA60_0		(0x1u<<0)

// HUFFBASE31 Configuration

#define	JPEG_HUFFBASE31_DATA63			(0x1FFu<<16)
#define	JPEG_HUFFBASE31_DATA63_0		(0x1u<<16)
#define	JPEG_HUFFBASE31_DATA62			(0x1FFu<<0)
#define	JPEG_HUFFBASE31_DATA62_0		(0x1u<<0)

// HUFFSYMB0 Configuration

#define	JPEG_HUFFSYMB0_DATA3			(0xFFu<<24)
#define	JPEG_HUFFSYMB0_DATA3_0			(0x1u<<24)
#define	JPEG_HUFFSYMB0_DATA2			(0xFFu<<16)
#define	JPEG_HUFFSYMB0_DATA2_0			(0x1u<<16)
#define	JPEG_HUFFSYMB0_DATA1			(0xFFu<<8)
#define	JPEG_HUFFSYMB0_DATA1_0			(0x1u<<8)
#define	JPEG_HUFFSYMB0_DATA0			(0xFFu<<0)
#define	JPEG_HUFFSYMB0_DATA0_0			(0x1u<<0)

// HUFFSYMB1 Configuration

#define	JPEG_HUFFSYMB1_DATA7			(0xFFu<<24)
#define	JPEG_HUFFSYMB1_DATA7_0			(0x1u<<24)
#define	JPEG_HUFFSYMB1_DATA6			(0xFFu<<16)
#define	JPEG_HUFFSYMB1_DATA6_0			(0x1u<<16)
#define	JPEG_HUFFSYMB1_DATA5			(0xFFu<<8)
#define	JPEG_HUFFSYMB1_DATA5_0			(0x1u<<8)
#define	JPEG_HUFFSYMB1_DATA4			(0xFFu<<0)
#define	JPEG_HUFFSYMB1_DATA4_0			(0x1u<<0)

// HUFFSYMB2 Configuration

#define	JPEG_HUFFSYMB2_DATA11			(0xFFu<<24)
#define	JPEG_HUFFSYMB2_DATA11_0			(0x1u<<24)
#define	JPEG_HUFFSYMB2_DATA10			(0xFFu<<16)
#define	JPEG_HUFFSYMB2_DATA10_0			(0x1u<<16)
#define	JPEG_HUFFSYMB2_DATA9			(0xFFu<<8)
#define	JPEG_HUFFSYMB2_DATA9_0			(0x1u<<8)
#define	JPEG_HUFFSYMB2_DATA8			(0xFFu<<0)
#define	JPEG_HUFFSYMB2_DATA8_0			(0x1u<<0)

// HUFFSYMB3 Configuration

#define	JPEG_HUFFSYMB3_DATA15			(0xFFu<<24)
#define	JPEG_HUFFSYMB3_DATA15_0			(0x1u<<24)
#define	JPEG_HUFFSYMB3_DATA14			(0xFFu<<16)
#define	JPEG_HUFFSYMB3_DATA14_0			(0x1u<<16)
#define	JPEG_HUFFSYMB3_DATA13			(0xFFu<<8)
#define	JPEG_HUFFSYMB3_DATA13_0			(0x1u<<8)
#define	JPEG_HUFFSYMB3_DATA12			(0xFFu<<0)
#define	JPEG_HUFFSYMB3_DATA12_0			(0x1u<<0)

// HUFFSYMB4 Configuration

#define	JPEG_HUFFSYMB4_DATA19			(0xFFu<<24)
#define	JPEG_HUFFSYMB4_DATA19_0			(0x1u<<24)
#define	JPEG_HUFFSYMB4_DATA18			(0xFFu<<16)
#define	JPEG_HUFFSYMB4_DATA18_0			(0x1u<<16)
#define	JPEG_HUFFSYMB4_DATA17			(0xFFu<<8)
#define	JPEG_HUFFSYMB4_DATA17_0			(0x1u<<8)
#define	JPEG_HUFFSYMB4_DATA16			(0xFFu<<0)
#define	JPEG_HUFFSYMB4_DATA16_0			(0x1u<<0)

// HUFFSYMB5 Configuration

#define	JPEG_HUFFSYMB5_DATA23			(0xFFu<<24)
#define	JPEG_HUFFSYMB5_DATA23_0			(0x1u<<24)
#define	JPEG_HUFFSYMB5_DATA22			(0xFFu<<16)
#define	JPEG_HUFFSYMB5_DATA22_0			(0x1u<<16)
#define	JPEG_HUFFSYMB5_DATA21			(0xFFu<<8)
#define	JPEG_HUFFSYMB5_DATA21_0			(0x1u<<8)
#define	JPEG_HUFFSYMB5_DATA20			(0xFFu<<0)
#define	JPEG_HUFFSYMB5_DATA20_0			(0x1u<<0)

// HUFFSYMB6 Configuration

#define	JPEG_HUFFSYMB6_DATA27			(0xFFu<<24)
#define	JPEG_HUFFSYMB6_DATA27_0			(0x1u<<24)
#define	JPEG_HUFFSYMB6_DATA26			(0xFFu<<16)
#define	JPEG_HUFFSYMB6_DATA26_0			(0x1u<<16)
#define	JPEG_HUFFSYMB6_DATA25			(0xFFu<<8)
#define	JPEG_HUFFSYMB6_DATA25_0			(0x1u<<8)
#define	JPEG_HUFFSYMB6_DATA24			(0xFFu<<0)
#define	JPEG_HUFFSYMB6_DATA24_0			(0x1u<<0)

// HUFFSYMB7 Configuration

#define	JPEG_HUFFSYMB7_DATA31			(0xFFu<<24)
#define	JPEG_HUFFSYMB7_DATA31_0			(0x1u<<24)
#define	JPEG_HUFFSYMB7_DATA30			(0xFFu<<16)
#define	JPEG_HUFFSYMB7_DATA30_0			(0x1u<<16)
#define	JPEG_HUFFSYMB7_DATA29			(0xFFu<<8)
#define	JPEG_HUFFSYMB7_DATA29_0			(0x1u<<8)
#define	JPEG_HUFFSYMB7_DATA28			(0xFFu<<0)
#define	JPEG_HUFFSYMB7_DATA28_0			(0x1u<<0)

// HUFFSYMB8 Configuration

#define	JPEG_HUFFSYMB8_DATA35			(0xFFu<<24)
#define	JPEG_HUFFSYMB8_DATA35_0			(0x1u<<24)
#define	JPEG_HUFFSYMB8_DATA34			(0xFFu<<16)
#define	JPEG_HUFFSYMB8_DATA34_0			(0x1u<<16)
#define	JPEG_HUFFSYMB8_DATA33			(0xFFu<<8)
#define	JPEG_HUFFSYMB8_DATA33_0			(0x1u<<8)
#define	JPEG_HUFFSYMB8_DATA32			(0xFFu<<0)
#define	JPEG_HUFFSYMB8_DATA32_0			(0x1u<<0)

// HUFFSYMB9 Configuration

#define	JPEG_HUFFSYMB9_DATA39			(0xFFu<<24)
#define	JPEG_HUFFSYMB9_DATA39_0			(0x1u<<24)
#define	JPEG_HUFFSYMB9_DATA38			(0xFFu<<16)
#define	JPEG_HUFFSYMB9_DATA38_0			(0x1u<<16)
#define	JPEG_HUFFSYMB9_DATA37			(0xFFu<<8)
#define	JPEG_HUFFSYMB9_DATA37_0			(0x1u<<8)
#define	JPEG_HUFFSYMB9_DATA36			(0xFFu<<0)
#define	JPEG_HUFFSYMB9_DATA36_0			(0x1u<<0)

// HUFFSYMB10 Configuration

#define	JPEG_HUFFSYMB10_DATA43			(0xFFu<<24)
#define	JPEG_HUFFSYMB10_DATA43_0		(0x1u<<24)
#define	JPEG_HUFFSYMB10_DATA42			(0xFFu<<16)
#define	JPEG_HUFFSYMB10_DATA42_0		(0x1u<<16)
#define	JPEG_HUFFSYMB10_DATA41			(0xFFu<<8)
#define	JPEG_HUFFSYMB10_DATA41_0		(0x1u<<8)
#define	JPEG_HUFFSYMB10_DATA40			(0xFFu<<0)
#define	JPEG_HUFFSYMB10_DATA40_0		(0x1u<<0)

// HUFFSYMB11 Configuration

#define	JPEG_HUFFSYMB11_DATA47			(0xFFu<<24)
#define	JPEG_HUFFSYMB11_DATA47_0		(0x1u<<24)
#define	JPEG_HUFFSYMB11_DATA46			(0xFFu<<16)
#define	JPEG_HUFFSYMB11_DATA46_0		(0x1u<<16)
#define	JPEG_HUFFSYMB11_DATA45			(0xFFu<<8)
#define	JPEG_HUFFSYMB11_DATA45_0		(0x1u<<8)
#define	JPEG_HUFFSYMB11_DATA44			(0xFFu<<0)
#define	JPEG_HUFFSYMB11_DATA44_0		(0x1u<<0)

// HUFFSYMB12 Configuration

#define	JPEG_HUFFSYMB12_DATA51			(0xFFu<<24)
#define	JPEG_HUFFSYMB12_DATA51_0		(0x1u<<24)
#define	JPEG_HUFFSYMB12_DATA50			(0xFFu<<16)
#define	JPEG_HUFFSYMB12_DATA50_0		(0x1u<<16)
#define	JPEG_HUFFSYMB12_DATA49			(0xFFu<<8)
#define	JPEG_HUFFSYMB12_DATA49_0		(0x1u<<8)
#define	JPEG_HUFFSYMB12_DATA48			(0xFFu<<0)
#define	JPEG_HUFFSYMB12_DATA48_0		(0x1u<<0)

// HUFFSYMB13 Configuration

#define	JPEG_HUFFSYMB13_DATA55			(0xFFu<<24)
#define	JPEG_HUFFSYMB13_DATA55_0		(0x1u<<24)
#define	JPEG_HUFFSYMB13_DATA54			(0xFFu<<16)
#define	JPEG_HUFFSYMB13_DATA54_0		(0x1u<<16)
#define	JPEG_HUFFSYMB13_DATA53			(0xFFu<<8)
#define	JPEG_HUFFSYMB13_DATA53_0		(0x1u<<8)
#define	JPEG_HUFFSYMB13_DATA52			(0xFFu<<0)
#define	JPEG_HUFFSYMB13_DATA52_0		(0x1u<<0)

// HUFFSYMB14 Configuration

#define	JPEG_HUFFSYMB14_DATA59			(0xFFu<<24)
#define	JPEG_HUFFSYMB14_DATA59_0		(0x1u<<24)
#define	JPEG_HUFFSYMB14_DATA58			(0xFFu<<16)
#define	JPEG_HUFFSYMB14_DATA58_0		(0x1u<<16)
#define	JPEG_HUFFSYMB14_DATA57			(0xFFu<<8)
#define	JPEG_HUFFSYMB14_DATA57_0		(0x1u<<8)
#define	JPEG_HUFFSYMB14_DATA56			(0xFFu<<0)
#define	JPEG_HUFFSYMB14_DATA56_0		(0x1u<<0)

// HUFFSYMB15 Configuration

#define	JPEG_HUFFSYMB15_DATA63			(0xFFu<<24)
#define	JPEG_HUFFSYMB15_DATA63_0		(0x1u<<24)
#define	JPEG_HUFFSYMB15_DATA62			(0xFFu<<16)
#define	JPEG_HUFFSYMB15_DATA62_0		(0x1u<<16)
#define	JPEG_HUFFSYMB15_DATA61			(0xFFu<<8)
#define	JPEG_HUFFSYMB15_DATA61_0		(0x1u<<8)
#define	JPEG_HUFFSYMB15_DATA60			(0xFFu<<0)
#define	JPEG_HUFFSYMB15_DATA60_0		(0x1u<<0)

// HUFFSYMB16 Configuration

#define	JPEG_HUFFSYMB16_DATA67			(0xFFu<<24)
#define	JPEG_HUFFSYMB16_DATA67_0		(0x1u<<24)
#define	JPEG_HUFFSYMB16_DATA66			(0xFFu<<16)
#define	JPEG_HUFFSYMB16_DATA66_0		(0x1u<<16)
#define	JPEG_HUFFSYMB16_DATA65			(0xFFu<<8)
#define	JPEG_HUFFSYMB16_DATA65_0		(0x1u<<8)
#define	JPEG_HUFFSYMB16_DATA64			(0xFFu<<0)
#define	JPEG_HUFFSYMB16_DATA64_0		(0x1u<<0)

// HUFFSYMB17 Configuration

#define	JPEG_HUFFSYMB17_DATA71			(0xFFu<<24)
#define	JPEG_HUFFSYMB17_DATA71_0		(0x1u<<24)
#define	JPEG_HUFFSYMB17_DATA70			(0xFFu<<16)
#define	JPEG_HUFFSYMB17_DATA70_0		(0x1u<<16)
#define	JPEG_HUFFSYMB17_DATA69			(0xFFu<<8)
#define	JPEG_HUFFSYMB17_DATA69_0		(0x1u<<8)
#define	JPEG_HUFFSYMB17_DATA68			(0xFFu<<0)
#define	JPEG_HUFFSYMB17_DATA68_0		(0x1u<<0)

// HUFFSYMB18 Configuration

#define	JPEG_HUFFSYMB18_DATA75			(0xFFu<<24)
#define	JPEG_HUFFSYMB18_DATA75_0		(0x1u<<24)
#define	JPEG_HUFFSYMB18_DATA74			(0xFFu<<16)
#define	JPEG_HUFFSYMB18_DATA74_0		(0x1u<<16)
#define	JPEG_HUFFSYMB18_DATA73			(0xFFu<<8)
#define	JPEG_HUFFSYMB18_DATA73_0		(0x1u<<8)
#define	JPEG_HUFFSYMB18_DATA72			(0xFFu<<0)
#define	JPEG_HUFFSYMB18_DATA72_0		(0x1u<<0)

// HUFFSYMB19 Configuration

#define	JPEG_HUFFSYMB19_DATA79			(0xFFu<<24)
#define	JPEG_HUFFSYMB19_DATA79_0		(0x1u<<24)
#define	JPEG_HUFFSYMB19_DATA78			(0xFFu<<16)
#define	JPEG_HUFFSYMB19_DATA78_0		(0x1u<<16)
#define	JPEG_HUFFSYMB19_DATA77			(0xFFu<<8)
#define	JPEG_HUFFSYMB19_DATA77_0		(0x1u<<8)
#define	JPEG_HUFFSYMB19_DATA76			(0xFFu<<0)
#define	JPEG_HUFFSYMB19_DATA76_0		(0x1u<<0)

// HUFFSYMB20 Configuration

#define	JPEG_HUFFSYMB20_DATA83			(0xFFu<<24)
#define	JPEG_HUFFSYMB20_DATA83_0		(0x1u<<24)
#define	JPEG_HUFFSYMB20_DATA82			(0xFFu<<16)
#define	JPEG_HUFFSYMB20_DATA82_0		(0x1u<<16)
#define	JPEG_HUFFSYMB20_DATA81			(0xFFu<<8)
#define	JPEG_HUFFSYMB20_DATA81_0		(0x1u<<8)
#define	JPEG_HUFFSYMB20_DATA80			(0xFFu<<0)
#define	JPEG_HUFFSYMB20_DATA80_0		(0x1u<<0)

// HUFFSYMB21 Configuration

#define	JPEG_HUFFSYMB21_DATA87			(0xFFu<<24)
#define	JPEG_HUFFSYMB21_DATA87_0		(0x1u<<24)
#define	JPEG_HUFFSYMB21_DATA86			(0xFFu<<16)
#define	JPEG_HUFFSYMB21_DATA86_0		(0x1u<<16)
#define	JPEG_HUFFSYMB21_DATA85			(0xFFu<<8)
#define	JPEG_HUFFSYMB21_DATA85_0		(0x1u<<8)
#define	JPEG_HUFFSYMB21_DATA84			(0xFFu<<0)
#define	JPEG_HUFFSYMB21_DATA84_0		(0x1u<<0)

// HUFFSYMB22 Configuration

#define	JPEG_HUFFSYMB22_DATA91			(0xFFu<<24)
#define	JPEG_HUFFSYMB22_DATA91_0		(0x1u<<24)
#define	JPEG_HUFFSYMB22_DATA90			(0xFFu<<16)
#define	JPEG_HUFFSYMB22_DATA90_0		(0x1u<<16)
#define	JPEG_HUFFSYMB22_DATA89			(0xFFu<<8)
#define	JPEG_HUFFSYMB22_DATA89_0		(0x1u<<8)
#define	JPEG_HUFFSYMB22_DATA88			(0xFFu<<0)
#define	JPEG_HUFFSYMB22_DATA88_0		(0x1u<<0)

// HUFFSYMB23 Configuration

#define	JPEG_HUFFSYMB23_DATA95			(0xFFu<<24)
#define	JPEG_HUFFSYMB23_DATA95_0		(0x1u<<24)
#define	JPEG_HUFFSYMB23_DATA94			(0xFFu<<16)
#define	JPEG_HUFFSYMB23_DATA94_0		(0x1u<<16)
#define	JPEG_HUFFSYMB23_DATA93			(0xFFu<<8)
#define	JPEG_HUFFSYMB23_DATA93_0		(0x1u<<8)
#define	JPEG_HUFFSYMB23_DATA92			(0xFFu<<0)
#define	JPEG_HUFFSYMB23_DATA92_0		(0x1u<<0)

// HUFFSYMB24 Configuration

#define	JPEG_HUFFSYMB24_DATA99			(0xFFu<<24)
#define	JPEG_HUFFSYMB24_DATA99_0		(0x1u<<24)
#define	JPEG_HUFFSYMB24_DATA98			(0xFFu<<16)
#define	JPEG_HUFFSYMB24_DATA98_0		(0x1u<<16)
#define	JPEG_HUFFSYMB24_DATA97			(0xFFu<<8)
#define	JPEG_HUFFSYMB24_DATA97_0		(0x1u<<8)
#define	JPEG_HUFFSYMB24_DATA96			(0xFFu<<0)
#define	JPEG_HUFFSYMB24_DATA96_0		(0x1u<<0)

// HUFFSYMB25 Configuration

#define	JPEG_HUFFSYMB25_DATA103			(0xFFu<<24)
#define	JPEG_HUFFSYMB25_DATA103_0		(0x1u<<24)
#define	JPEG_HUFFSYMB25_DATA102			(0xFFu<<16)
#define	JPEG_HUFFSYMB25_DATA102_0		(0x1u<<16)
#define	JPEG_HUFFSYMB25_DATA101			(0xFFu<<8)
#define	JPEG_HUFFSYMB25_DATA101_0		(0x1u<<8)
#define	JPEG_HUFFSYMB25_DATA100			(0xFFu<<0)
#define	JPEG_HUFFSYMB25_DATA100_0		(0x1u<<0)

// HUFFSYMB26 Configuration

#define	JPEG_HUFFSYMB26_DATA107			(0xFFu<<24)
#define	JPEG_HUFFSYMB26_DATA107_0		(0x1u<<24)
#define	JPEG_HUFFSYMB26_DATA106			(0xFFu<<16)
#define	JPEG_HUFFSYMB26_DATA106_0		(0x1u<<16)
#define	JPEG_HUFFSYMB26_DATA105			(0xFFu<<8)
#define	JPEG_HUFFSYMB26_DATA105_0		(0x1u<<8)
#define	JPEG_HUFFSYMB26_DATA104			(0xFFu<<0)
#define	JPEG_HUFFSYMB26_DATA104_0		(0x1u<<0)

// HUFFSYMB27 Configuration

#define	JPEG_HUFFSYMB27_DATA111			(0xFFu<<24)
#define	JPEG_HUFFSYMB27_DATA111_0		(0x1u<<24)
#define	JPEG_HUFFSYMB27_DATA110			(0xFFu<<16)
#define	JPEG_HUFFSYMB27_DATA110_0		(0x1u<<16)
#define	JPEG_HUFFSYMB27_DATA109			(0xFFu<<8)
#define	JPEG_HUFFSYMB27_DATA109_0		(0x1u<<8)
#define	JPEG_HUFFSYMB27_DATA108			(0xFFu<<0)
#define	JPEG_HUFFSYMB27_DATA108_0		(0x1u<<0)

// HUFFSYMB28 Configuration

#define	JPEG_HUFFSYMB28_DATA115			(0xFFu<<24)
#define	JPEG_HUFFSYMB28_DATA115_0		(0x1u<<24)
#define	JPEG_HUFFSYMB28_DATA114			(0xFFu<<16)
#define	JPEG_HUFFSYMB28_DATA114_0		(0x1u<<16)
#define	JPEG_HUFFSYMB28_DATA113			(0xFFu<<8)
#define	JPEG_HUFFSYMB28_DATA113_0		(0x1u<<8)
#define	JPEG_HUFFSYMB28_DATA112			(0xFFu<<0)
#define	JPEG_HUFFSYMB28_DATA112_0		(0x1u<<0)

// HUFFSYMB29 Configuration

#define	JPEG_HUFFSYMB29_DATA119			(0xFFu<<24)
#define	JPEG_HUFFSYMB29_DATA119_0		(0x1u<<24)
#define	JPEG_HUFFSYMB29_DATA118			(0xFFu<<16)
#define	JPEG_HUFFSYMB29_DATA118_0		(0x1u<<16)
#define	JPEG_HUFFSYMB29_DATA117			(0xFFu<<8)
#define	JPEG_HUFFSYMB29_DATA117_0		(0x1u<<8)
#define	JPEG_HUFFSYMB29_DATA116			(0xFFu<<0)
#define	JPEG_HUFFSYMB29_DATA116_0		(0x1u<<0)

// HUFFSYMB30 Configuration

#define	JPEG_HUFFSYMB30_DATA123			(0xFFu<<24)
#define	JPEG_HUFFSYMB30_DATA123_0		(0x1u<<24)
#define	JPEG_HUFFSYMB30_DATA122			(0xFFu<<16)
#define	JPEG_HUFFSYMB30_DATA122_0		(0x1u<<16)
#define	JPEG_HUFFSYMB30_DATA121			(0xFFu<<8)
#define	JPEG_HUFFSYMB30_DATA121_0		(0x1u<<8)
#define	JPEG_HUFFSYMB30_DATA120			(0xFFu<<0)
#define	JPEG_HUFFSYMB30_DATA120_0		(0x1u<<0)

// HUFFSYMB31 Configuration

#define	JPEG_HUFFSYMB31_DATA127			(0xFFu<<24)
#define	JPEG_HUFFSYMB31_DATA127_0		(0x1u<<24)
#define	JPEG_HUFFSYMB31_DATA126			(0xFFu<<16)
#define	JPEG_HUFFSYMB31_DATA126_0		(0x1u<<16)
#define	JPEG_HUFFSYMB31_DATA125			(0xFFu<<8)
#define	JPEG_HUFFSYMB31_DATA125_0		(0x1u<<8)
#define	JPEG_HUFFSYMB31_DATA124			(0xFFu<<0)
#define	JPEG_HUFFSYMB31_DATA124_0		(0x1u<<0)

// HUFFSYMB32 Configuration

#define	JPEG_HUFFSYMB32_DATA131			(0xFFu<<24)
#define	JPEG_HUFFSYMB32_DATA131_0		(0x1u<<24)
#define	JPEG_HUFFSYMB32_DATA130			(0xFFu<<16)
#define	JPEG_HUFFSYMB32_DATA130_0		(0x1u<<16)
#define	JPEG_HUFFSYMB32_DATA129			(0xFFu<<8)
#define	JPEG_HUFFSYMB32_DATA129_0		(0x1u<<8)
#define	JPEG_HUFFSYMB32_DATA128			(0xFFu<<0)
#define	JPEG_HUFFSYMB32_DATA128_0		(0x1u<<0)

// HUFFSYMB33 Configuration

#define	JPEG_HUFFSYMB33_DATA135			(0xFFu<<24)
#define	JPEG_HUFFSYMB33_DATA135_0		(0x1u<<24)
#define	JPEG_HUFFSYMB33_DATA134			(0xFFu<<16)
#define	JPEG_HUFFSYMB33_DATA134_0		(0x1u<<16)
#define	JPEG_HUFFSYMB33_DATA133			(0xFFu<<8)
#define	JPEG_HUFFSYMB33_DATA133_0		(0x1u<<8)
#define	JPEG_HUFFSYMB33_DATA132			(0xFFu<<0)
#define	JPEG_HUFFSYMB33_DATA132_0		(0x1u<<0)

// HUFFSYMB34 Configuration

#define	JPEG_HUFFSYMB34_DATA139			(0xFFu<<24)
#define	JPEG_HUFFSYMB34_DATA139_0		(0x1u<<24)
#define	JPEG_HUFFSYMB34_DATA138			(0xFFu<<16)
#define	JPEG_HUFFSYMB34_DATA138_0		(0x1u<<16)
#define	JPEG_HUFFSYMB34_DATA137			(0xFFu<<8)
#define	JPEG_HUFFSYMB34_DATA137_0		(0x1u<<8)
#define	JPEG_HUFFSYMB34_DATA136			(0xFFu<<0)
#define	JPEG_HUFFSYMB34_DATA136_0		(0x1u<<0)

// HUFFSYMB35 Configuration

#define	JPEG_HUFFSYMB35_DATA143			(0xFFu<<24)
#define	JPEG_HUFFSYMB35_DATA143_0		(0x1u<<24)
#define	JPEG_HUFFSYMB35_DATA142			(0xFFu<<16)
#define	JPEG_HUFFSYMB35_DATA142_0		(0x1u<<16)
#define	JPEG_HUFFSYMB35_DATA141			(0xFFu<<8)
#define	JPEG_HUFFSYMB35_DATA141_0		(0x1u<<8)
#define	JPEG_HUFFSYMB35_DATA140			(0xFFu<<0)
#define	JPEG_HUFFSYMB35_DATA140_0		(0x1u<<0)

// HUFFSYMB36 Configuration

#define	JPEG_HUFFSYMB36_DATA147			(0xFFu<<24)
#define	JPEG_HUFFSYMB36_DATA147_0		(0x1u<<24)
#define	JPEG_HUFFSYMB36_DATA146			(0xFFu<<16)
#define	JPEG_HUFFSYMB36_DATA146_0		(0x1u<<16)
#define	JPEG_HUFFSYMB36_DATA145			(0xFFu<<8)
#define	JPEG_HUFFSYMB36_DATA145_0		(0x1u<<8)
#define	JPEG_HUFFSYMB36_DATA144			(0xFFu<<0)
#define	JPEG_HUFFSYMB36_DATA144_0		(0x1u<<0)

// HUFFSYMB37 Configuration

#define	JPEG_HUFFSYMB37_DATA151			(0xFFu<<24)
#define	JPEG_HUFFSYMB37_DATA151_0		(0x1u<<24)
#define	JPEG_HUFFSYMB37_DATA150			(0xFFu<<16)
#define	JPEG_HUFFSYMB37_DATA150_0		(0x1u<<16)
#define	JPEG_HUFFSYMB37_DATA149			(0xFFu<<8)
#define	JPEG_HUFFSYMB37_DATA149_0		(0x1u<<8)
#define	JPEG_HUFFSYMB37_DATA148			(0xFFu<<0)
#define	JPEG_HUFFSYMB37_DATA148_0		(0x1u<<0)

// HUFFSYMB38 Configuration

#define	JPEG_HUFFSYMB38_DATA155			(0xFFu<<24)
#define	JPEG_HUFFSYMB38_DATA155_0		(0x1u<<24)
#define	JPEG_HUFFSYMB38_DATA154			(0xFFu<<16)
#define	JPEG_HUFFSYMB38_DATA154_0		(0x1u<<16)
#define	JPEG_HUFFSYMB38_DATA153			(0xFFu<<8)
#define	JPEG_HUFFSYMB38_DATA153_0		(0x1u<<8)
#define	JPEG_HUFFSYMB38_DATA152			(0xFFu<<0)
#define	JPEG_HUFFSYMB38_DATA152_0		(0x1u<<0)

// HUFFSYMB39 Configuration

#define	JPEG_HUFFSYMB39_DATA159			(0xFFu<<24)
#define	JPEG_HUFFSYMB39_DATA159_0		(0x1u<<24)
#define	JPEG_HUFFSYMB39_DATA158			(0xFFu<<16)
#define	JPEG_HUFFSYMB39_DATA158_0		(0x1u<<16)
#define	JPEG_HUFFSYMB39_DATA157			(0xFFu<<8)
#define	JPEG_HUFFSYMB39_DATA157_0		(0x1u<<8)
#define	JPEG_HUFFSYMB39_DATA156			(0xFFu<<0)
#define	JPEG_HUFFSYMB39_DATA156_0		(0x1u<<0)

// HUFFSYMB40 Configuration

#define	JPEG_HUFFSYMB40_DATA163			(0xFFu<<24)
#define	JPEG_HUFFSYMB40_DATA163_0		(0x1u<<24)
#define	JPEG_HUFFSYMB40_DATA162			(0xFFu<<16)
#define	JPEG_HUFFSYMB40_DATA162_0		(0x1u<<16)
#define	JPEG_HUFFSYMB40_DATA161			(0xFFu<<8)
#define	JPEG_HUFFSYMB40_DATA161_0		(0x1u<<8)
#define	JPEG_HUFFSYMB40_DATA160			(0xFFu<<0)
#define	JPEG_HUFFSYMB40_DATA160_0		(0x1u<<0)

// HUFFSYMB41 Configuration

#define	JPEG_HUFFSYMB41_DATA167			(0xFFu<<24)
#define	JPEG_HUFFSYMB41_DATA167_0		(0x1u<<24)
#define	JPEG_HUFFSYMB41_DATA166			(0xFFu<<16)
#define	JPEG_HUFFSYMB41_DATA166_0		(0x1u<<16)
#define	JPEG_HUFFSYMB41_DATA165			(0xFFu<<8)
#define	JPEG_HUFFSYMB41_DATA165_0		(0x1u<<8)
#define	JPEG_HUFFSYMB41_DATA164			(0xFFu<<0)
#define	JPEG_HUFFSYMB41_DATA164_0		(0x1u<<0)

// HUFFSYMB42 Configuration

#define	JPEG_HUFFSYMB42_DATA171			(0xFFu<<24)
#define	JPEG_HUFFSYMB42_DATA171_0		(0x1u<<24)
#define	JPEG_HUFFSYMB42_DATA170			(0xFFu<<16)
#define	JPEG_HUFFSYMB42_DATA170_0		(0x1u<<16)
#define	JPEG_HUFFSYMB42_DATA169			(0xFFu<<8)
#define	JPEG_HUFFSYMB42_DATA169_0		(0x1u<<8)
#define	JPEG_HUFFSYMB42_DATA168			(0xFFu<<0)
#define	JPEG_HUFFSYMB42_DATA168_0		(0x1u<<0)

// HUFFSYMB43 Configuration

#define	JPEG_HUFFSYMB43_DATA175			(0xFFu<<24)
#define	JPEG_HUFFSYMB43_DATA175_0		(0x1u<<24)
#define	JPEG_HUFFSYMB43_DATA174			(0xFFu<<16)
#define	JPEG_HUFFSYMB43_DATA174_0		(0x1u<<16)
#define	JPEG_HUFFSYMB43_DATA173			(0xFFu<<8)
#define	JPEG_HUFFSYMB43_DATA173_0		(0x1u<<8)
#define	JPEG_HUFFSYMB43_DATA172			(0xFFu<<0)
#define	JPEG_HUFFSYMB43_DATA172_0		(0x1u<<0)

// HUFFSYMB44 Configuration

#define	JPEG_HUFFSYMB44_DATA179			(0xFFu<<24)
#define	JPEG_HUFFSYMB44_DATA179_0		(0x1u<<24)
#define	JPEG_HUFFSYMB44_DATA178			(0xFFu<<16)
#define	JPEG_HUFFSYMB44_DATA178_0		(0x1u<<16)
#define	JPEG_HUFFSYMB44_DATA177			(0xFFu<<8)
#define	JPEG_HUFFSYMB44_DATA177_0		(0x1u<<8)
#define	JPEG_HUFFSYMB44_DATA176			(0xFFu<<0)
#define	JPEG_HUFFSYMB44_DATA176_0		(0x1u<<0)

// HUFFSYMB45 Configuration

#define	JPEG_HUFFSYMB45_DATA183			(0xFFu<<24)
#define	JPEG_HUFFSYMB45_DATA183_0		(0x1u<<24)
#define	JPEG_HUFFSYMB45_DATA182			(0xFFu<<16)
#define	JPEG_HUFFSYMB45_DATA182_0		(0x1u<<16)
#define	JPEG_HUFFSYMB45_DATA181			(0xFFu<<8)
#define	JPEG_HUFFSYMB45_DATA181_0		(0x1u<<8)
#define	JPEG_HUFFSYMB45_DATA180			(0xFFu<<0)
#define	JPEG_HUFFSYMB45_DATA180_0		(0x1u<<0)

// HUFFSYMB46 Configuration

#define	JPEG_HUFFSYMB46_DATA187			(0xFFu<<24)
#define	JPEG_HUFFSYMB46_DATA187_0		(0x1u<<24)
#define	JPEG_HUFFSYMB46_DATA186			(0xFFu<<16)
#define	JPEG_HUFFSYMB46_DATA186_0		(0x1u<<16)
#define	JPEG_HUFFSYMB46_DATA185			(0xFFu<<8)
#define	JPEG_HUFFSYMB46_DATA185_0		(0x1u<<8)
#define	JPEG_HUFFSYMB46_DATA184			(0xFFu<<0)
#define	JPEG_HUFFSYMB46_DATA184_0		(0x1u<<0)

// HUFFSYMB47 Configuration

#define	JPEG_HUFFSYMB47_DATA191			(0xFFu<<24)
#define	JPEG_HUFFSYMB47_DATA191_0		(0x1u<<24)
#define	JPEG_HUFFSYMB47_DATA190			(0xFFu<<16)
#define	JPEG_HUFFSYMB47_DATA190_0		(0x1u<<16)
#define	JPEG_HUFFSYMB47_DATA189			(0xFFu<<8)
#define	JPEG_HUFFSYMB47_DATA189_0		(0x1u<<8)
#define	JPEG_HUFFSYMB47_DATA188			(0xFFu<<0)
#define	JPEG_HUFFSYMB47_DATA188_0		(0x1u<<0)

// HUFFSYMB48 Configuration

#define	JPEG_HUFFSYMB48_DATA195			(0xFFu<<24)
#define	JPEG_HUFFSYMB48_DATA195_0		(0x1u<<24)
#define	JPEG_HUFFSYMB48_DATA194			(0xFFu<<16)
#define	JPEG_HUFFSYMB48_DATA194_0		(0x1u<<16)
#define	JPEG_HUFFSYMB48_DATA193			(0xFFu<<8)
#define	JPEG_HUFFSYMB48_DATA193_0		(0x1u<<8)
#define	JPEG_HUFFSYMB48_DATA192			(0xFFu<<0)
#define	JPEG_HUFFSYMB48_DATA192_0		(0x1u<<0)

// HUFFSYMB49 Configuration

#define	JPEG_HUFFSYMB49_DATA199			(0xFFu<<24)
#define	JPEG_HUFFSYMB49_DATA199_0		(0x1u<<24)
#define	JPEG_HUFFSYMB49_DATA198			(0xFFu<<16)
#define	JPEG_HUFFSYMB49_DATA198_0		(0x1u<<16)
#define	JPEG_HUFFSYMB49_DATA197			(0xFFu<<8)
#define	JPEG_HUFFSYMB49_DATA197_0		(0x1u<<8)
#define	JPEG_HUFFSYMB49_DATA196			(0xFFu<<0)
#define	JPEG_HUFFSYMB49_DATA196_0		(0x1u<<0)

// HUFFSYMB50 Configuration

#define	JPEG_HUFFSYMB50_DATA203			(0xFFu<<24)
#define	JPEG_HUFFSYMB50_DATA203_0		(0x1u<<24)
#define	JPEG_HUFFSYMB50_DATA202			(0xFFu<<16)
#define	JPEG_HUFFSYMB50_DATA202_0		(0x1u<<16)
#define	JPEG_HUFFSYMB50_DATA201			(0xFFu<<8)
#define	JPEG_HUFFSYMB50_DATA201_0		(0x1u<<8)
#define	JPEG_HUFFSYMB50_DATA200			(0xFFu<<0)
#define	JPEG_HUFFSYMB50_DATA200_0		(0x1u<<0)

// HUFFSYMB51 Configuration

#define	JPEG_HUFFSYMB51_DATA207			(0xFFu<<24)
#define	JPEG_HUFFSYMB51_DATA207_0		(0x1u<<24)
#define	JPEG_HUFFSYMB51_DATA206			(0xFFu<<16)
#define	JPEG_HUFFSYMB51_DATA206_0		(0x1u<<16)
#define	JPEG_HUFFSYMB51_DATA205			(0xFFu<<8)
#define	JPEG_HUFFSYMB51_DATA205_0		(0x1u<<8)
#define	JPEG_HUFFSYMB51_DATA204			(0xFFu<<0)
#define	JPEG_HUFFSYMB51_DATA204_0		(0x1u<<0)

// HUFFSYMB52 Configuration

#define	JPEG_HUFFSYMB52_DATA211			(0xFFu<<24)
#define	JPEG_HUFFSYMB52_DATA211_0		(0x1u<<24)
#define	JPEG_HUFFSYMB52_DATA210			(0xFFu<<16)
#define	JPEG_HUFFSYMB52_DATA210_0		(0x1u<<16)
#define	JPEG_HUFFSYMB52_DATA209			(0xFFu<<8)
#define	JPEG_HUFFSYMB52_DATA209_0		(0x1u<<8)
#define	JPEG_HUFFSYMB52_DATA208			(0xFFu<<0)
#define	JPEG_HUFFSYMB52_DATA208_0		(0x1u<<0)

// HUFFSYMB53 Configuration

#define	JPEG_HUFFSYMB53_DATA215			(0xFFu<<24)
#define	JPEG_HUFFSYMB53_DATA215_0		(0x1u<<24)
#define	JPEG_HUFFSYMB53_DATA214			(0xFFu<<16)
#define	JPEG_HUFFSYMB53_DATA214_0		(0x1u<<16)
#define	JPEG_HUFFSYMB53_DATA213			(0xFFu<<8)
#define	JPEG_HUFFSYMB53_DATA213_0		(0x1u<<8)
#define	JPEG_HUFFSYMB53_DATA212			(0xFFu<<0)
#define	JPEG_HUFFSYMB53_DATA212_0		(0x1u<<0)

// HUFFSYMB54 Configuration

#define	JPEG_HUFFSYMB54_DATA219			(0xFFu<<24)
#define	JPEG_HUFFSYMB54_DATA219_0		(0x1u<<24)
#define	JPEG_HUFFSYMB54_DATA218			(0xFFu<<16)
#define	JPEG_HUFFSYMB54_DATA218_0		(0x1u<<16)
#define	JPEG_HUFFSYMB54_DATA217			(0xFFu<<8)
#define	JPEG_HUFFSYMB54_DATA217_0		(0x1u<<8)
#define	JPEG_HUFFSYMB54_DATA216			(0xFFu<<0)
#define	JPEG_HUFFSYMB54_DATA216_0		(0x1u<<0)

// HUFFSYMB55 Configuration

#define	JPEG_HUFFSYMB55_DATA223			(0xFFu<<24)
#define	JPEG_HUFFSYMB55_DATA223_0		(0x1u<<24)
#define	JPEG_HUFFSYMB55_DATA222			(0xFFu<<16)
#define	JPEG_HUFFSYMB55_DATA222_0		(0x1u<<16)
#define	JPEG_HUFFSYMB55_DATA221			(0xFFu<<8)
#define	JPEG_HUFFSYMB55_DATA221_0		(0x1u<<8)
#define	JPEG_HUFFSYMB55_DATA220			(0xFFu<<0)
#define	JPEG_HUFFSYMB55_DATA220_0		(0x1u<<0)

// HUFFSYMB56 Configuration

#define	JPEG_HUFFSYMB56_DATA227			(0xFFu<<24)
#define	JPEG_HUFFSYMB56_DATA227_0		(0x1u<<24)
#define	JPEG_HUFFSYMB56_DATA226			(0xFFu<<16)
#define	JPEG_HUFFSYMB56_DATA226_0		(0x1u<<16)
#define	JPEG_HUFFSYMB56_DATA225			(0xFFu<<8)
#define	JPEG_HUFFSYMB56_DATA225_0		(0x1u<<8)
#define	JPEG_HUFFSYMB56_DATA224			(0xFFu<<0)
#define	JPEG_HUFFSYMB56_DATA224_0		(0x1u<<0)

// HUFFSYMB57 Configuration

#define	JPEG_HUFFSYMB57_DATA231			(0xFFu<<24)
#define	JPEG_HUFFSYMB57_DATA231_0		(0x1u<<24)
#define	JPEG_HUFFSYMB57_DATA230			(0xFFu<<16)
#define	JPEG_HUFFSYMB57_DATA230_0		(0x1u<<16)
#define	JPEG_HUFFSYMB57_DATA229			(0xFFu<<8)
#define	JPEG_HUFFSYMB57_DATA229_0		(0x1u<<8)
#define	JPEG_HUFFSYMB57_DATA228			(0xFFu<<0)
#define	JPEG_HUFFSYMB57_DATA228_0		(0x1u<<0)

// HUFFSYMB58 Configuration

#define	JPEG_HUFFSYMB58_DATA235			(0xFFu<<24)
#define	JPEG_HUFFSYMB58_DATA235_0		(0x1u<<24)
#define	JPEG_HUFFSYMB58_DATA234			(0xFFu<<16)
#define	JPEG_HUFFSYMB58_DATA234_0		(0x1u<<16)
#define	JPEG_HUFFSYMB58_DATA233			(0xFFu<<8)
#define	JPEG_HUFFSYMB58_DATA233_0		(0x1u<<8)
#define	JPEG_HUFFSYMB58_DATA232			(0xFFu<<0)
#define	JPEG_HUFFSYMB58_DATA232_0		(0x1u<<0)

// HUFFSYMB59 Configuration

#define	JPEG_HUFFSYMB59_DATA239			(0xFFu<<24)
#define	JPEG_HUFFSYMB59_DATA239_0		(0x1u<<24)
#define	JPEG_HUFFSYMB59_DATA238			(0xFFu<<16)
#define	JPEG_HUFFSYMB59_DATA238_0		(0x1u<<16)
#define	JPEG_HUFFSYMB59_DATA237			(0xFFu<<8)
#define	JPEG_HUFFSYMB59_DATA237_0		(0x1u<<8)
#define	JPEG_HUFFSYMB59_DATA236			(0xFFu<<0)
#define	JPEG_HUFFSYMB59_DATA236_0		(0x1u<<0)

// HUFFSYMB60 Configuration

#define	JPEG_HUFFSYMB60_DATA243			(0xFFu<<24)
#define	JPEG_HUFFSYMB60_DATA243_0		(0x1u<<24)
#define	JPEG_HUFFSYMB60_DATA242			(0xFFu<<16)
#define	JPEG_HUFFSYMB60_DATA242_0		(0x1u<<16)
#define	JPEG_HUFFSYMB60_DATA241			(0xFFu<<8)
#define	JPEG_HUFFSYMB60_DATA241_0		(0x1u<<8)
#define	JPEG_HUFFSYMB60_DATA240			(0xFFu<<0)
#define	JPEG_HUFFSYMB60_DATA240_0		(0x1u<<0)

// HUFFSYMB61 Configuration

#define	JPEG_HUFFSYMB61_DATA247			(0xFFu<<24)
#define	JPEG_HUFFSYMB61_DATA247_0		(0x1u<<24)
#define	JPEG_HUFFSYMB61_DATA246			(0xFFu<<16)
#define	JPEG_HUFFSYMB61_DATA246_0		(0x1u<<16)
#define	JPEG_HUFFSYMB61_DATA245			(0xFFu<<8)
#define	JPEG_HUFFSYMB61_DATA245_0		(0x1u<<8)
#define	JPEG_HUFFSYMB61_DATA244			(0xFFu<<0)
#define	JPEG_HUFFSYMB61_DATA244_0		(0x1u<<0)

// HUFFSYMB62 Configuration

#define	JPEG_HUFFSYMB62_DATA251			(0xFFu<<24)
#define	JPEG_HUFFSYMB62_DATA251_0		(0x1u<<24)
#define	JPEG_HUFFSYMB62_DATA250			(0xFFu<<16)
#define	JPEG_HUFFSYMB62_DATA250_0		(0x1u<<16)
#define	JPEG_HUFFSYMB62_DATA249			(0xFFu<<8)
#define	JPEG_HUFFSYMB62_DATA249_0		(0x1u<<8)
#define	JPEG_HUFFSYMB62_DATA248			(0xFFu<<0)
#define	JPEG_HUFFSYMB62_DATA248_0		(0x1u<<0)

// HUFFSYMB63 Configuration

#define	JPEG_HUFFSYMB63_DATA255			(0xFFu<<24)
#define	JPEG_HUFFSYMB63_DATA255_0		(0x1u<<24)
#define	JPEG_HUFFSYMB63_DATA254			(0xFFu<<16)
#define	JPEG_HUFFSYMB63_DATA254_0		(0x1u<<16)
#define	JPEG_HUFFSYMB63_DATA253			(0xFFu<<8)
#define	JPEG_HUFFSYMB63_DATA253_0		(0x1u<<8)
#define	JPEG_HUFFSYMB63_DATA252			(0xFFu<<0)
#define	JPEG_HUFFSYMB63_DATA252_0		(0x1u<<0)

// HUFFSYMB64 Configuration

#define	JPEG_HUFFSYMB64_DATA259			(0xFFu<<24)
#define	JPEG_HUFFSYMB64_DATA259_0		(0x1u<<24)
#define	JPEG_HUFFSYMB64_DATA258			(0xFFu<<16)
#define	JPEG_HUFFSYMB64_DATA258_0		(0x1u<<16)
#define	JPEG_HUFFSYMB64_DATA257			(0xFFu<<8)
#define	JPEG_HUFFSYMB64_DATA257_0		(0x1u<<8)
#define	JPEG_HUFFSYMB64_DATA256			(0xFFu<<0)
#define	JPEG_HUFFSYMB64_DATA256_0		(0x1u<<0)

// HUFFSYMB65 Configuration

#define	JPEG_HUFFSYMB65_DATA263			(0xFFu<<24)
#define	JPEG_HUFFSYMB65_DATA263_0		(0x1u<<24)
#define	JPEG_HUFFSYMB65_DATA262			(0xFFu<<16)
#define	JPEG_HUFFSYMB65_DATA262_0		(0x1u<<16)
#define	JPEG_HUFFSYMB65_DATA261			(0xFFu<<8)
#define	JPEG_HUFFSYMB65_DATA261_0		(0x1u<<8)
#define	JPEG_HUFFSYMB65_DATA260			(0xFFu<<0)
#define	JPEG_HUFFSYMB65_DATA260_0		(0x1u<<0)

// HUFFSYMB66 Configuration

#define	JPEG_HUFFSYMB66_DATA267			(0xFFu<<24)
#define	JPEG_HUFFSYMB66_DATA267_0		(0x1u<<24)
#define	JPEG_HUFFSYMB66_DATA266			(0xFFu<<16)
#define	JPEG_HUFFSYMB66_DATA266_0		(0x1u<<16)
#define	JPEG_HUFFSYMB66_DATA265			(0xFFu<<8)
#define	JPEG_HUFFSYMB66_DATA265_0		(0x1u<<8)
#define	JPEG_HUFFSYMB66_DATA264			(0xFFu<<0)
#define	JPEG_HUFFSYMB66_DATA264_0		(0x1u<<0)

// HUFFSYMB67 Configuration

#define	JPEG_HUFFSYMB67_DATA271			(0xFFu<<24)
#define	JPEG_HUFFSYMB67_DATA271_0		(0x1u<<24)
#define	JPEG_HUFFSYMB67_DATA270			(0xFFu<<16)
#define	JPEG_HUFFSYMB67_DATA270_0		(0x1u<<16)
#define	JPEG_HUFFSYMB67_DATA269			(0xFFu<<8)
#define	JPEG_HUFFSYMB67_DATA269_0		(0x1u<<8)
#define	JPEG_HUFFSYMB67_DATA268			(0xFFu<<0)
#define	JPEG_HUFFSYMB67_DATA268_0		(0x1u<<0)

// HUFFSYMB68 Configuration

#define	JPEG_HUFFSYMB68_DATA275			(0xFFu<<24)
#define	JPEG_HUFFSYMB68_DATA275_0		(0x1u<<24)
#define	JPEG_HUFFSYMB68_DATA274			(0xFFu<<16)
#define	JPEG_HUFFSYMB68_DATA274_0		(0x1u<<16)
#define	JPEG_HUFFSYMB68_DATA273			(0xFFu<<8)
#define	JPEG_HUFFSYMB68_DATA273_0		(0x1u<<8)
#define	JPEG_HUFFSYMB68_DATA272			(0xFFu<<0)
#define	JPEG_HUFFSYMB68_DATA272_0		(0x1u<<0)

// HUFFSYMB69 Configuration

#define	JPEG_HUFFSYMB69_DATA279			(0xFFu<<24)
#define	JPEG_HUFFSYMB69_DATA279_0		(0x1u<<24)
#define	JPEG_HUFFSYMB69_DATA278			(0xFFu<<16)
#define	JPEG_HUFFSYMB69_DATA278_0		(0x1u<<16)
#define	JPEG_HUFFSYMB69_DATA277			(0xFFu<<8)
#define	JPEG_HUFFSYMB69_DATA277_0		(0x1u<<8)
#define	JPEG_HUFFSYMB69_DATA276			(0xFFu<<0)
#define	JPEG_HUFFSYMB69_DATA276_0		(0x1u<<0)

// HUFFSYMB70 Configuration

#define	JPEG_HUFFSYMB70_DATA283			(0xFFu<<24)
#define	JPEG_HUFFSYMB70_DATA283_0		(0x1u<<24)
#define	JPEG_HUFFSYMB70_DATA282			(0xFFu<<16)
#define	JPEG_HUFFSYMB70_DATA282_0		(0x1u<<16)
#define	JPEG_HUFFSYMB70_DATA281			(0xFFu<<8)
#define	JPEG_HUFFSYMB70_DATA281_0		(0x1u<<8)
#define	JPEG_HUFFSYMB70_DATA280			(0xFFu<<0)
#define	JPEG_HUFFSYMB70_DATA280_0		(0x1u<<0)

// HUFFSYMB71 Configuration

#define	JPEG_HUFFSYMB71_DATA287			(0xFFu<<24)
#define	JPEG_HUFFSYMB71_DATA287_0		(0x1u<<24)
#define	JPEG_HUFFSYMB71_DATA286			(0xFFu<<16)
#define	JPEG_HUFFSYMB71_DATA286_0		(0x1u<<16)
#define	JPEG_HUFFSYMB71_DATA285			(0xFFu<<8)
#define	JPEG_HUFFSYMB71_DATA285_0		(0x1u<<8)
#define	JPEG_HUFFSYMB71_DATA284			(0xFFu<<0)
#define	JPEG_HUFFSYMB71_DATA284_0		(0x1u<<0)

// HUFFSYMB72 Configuration

#define	JPEG_HUFFSYMB72_DATA291			(0xFFu<<24)
#define	JPEG_HUFFSYMB72_DATA291_0		(0x1u<<24)
#define	JPEG_HUFFSYMB72_DATA290			(0xFFu<<16)
#define	JPEG_HUFFSYMB72_DATA290_0		(0x1u<<16)
#define	JPEG_HUFFSYMB72_DATA289			(0xFFu<<8)
#define	JPEG_HUFFSYMB72_DATA289_0		(0x1u<<8)
#define	JPEG_HUFFSYMB72_DATA288			(0xFFu<<0)
#define	JPEG_HUFFSYMB72_DATA288_0		(0x1u<<0)

// HUFFSYMB73 Configuration

#define	JPEG_HUFFSYMB73_DATA295			(0xFFu<<24)
#define	JPEG_HUFFSYMB73_DATA295_0		(0x1u<<24)
#define	JPEG_HUFFSYMB73_DATA294			(0xFFu<<16)
#define	JPEG_HUFFSYMB73_DATA294_0		(0x1u<<16)
#define	JPEG_HUFFSYMB73_DATA293			(0xFFu<<8)
#define	JPEG_HUFFSYMB73_DATA293_0		(0x1u<<8)
#define	JPEG_HUFFSYMB73_DATA292			(0xFFu<<0)
#define	JPEG_HUFFSYMB73_DATA292_0		(0x1u<<0)

// HUFFSYMB74 Configuration

#define	JPEG_HUFFSYMB74_DATA299			(0xFFu<<24)
#define	JPEG_HUFFSYMB74_DATA299_0		(0x1u<<24)
#define	JPEG_HUFFSYMB74_DATA298			(0xFFu<<16)
#define	JPEG_HUFFSYMB74_DATA298_0		(0x1u<<16)
#define	JPEG_HUFFSYMB74_DATA297			(0xFFu<<8)
#define	JPEG_HUFFSYMB74_DATA297_0		(0x1u<<8)
#define	JPEG_HUFFSYMB74_DATA296			(0xFFu<<0)
#define	JPEG_HUFFSYMB74_DATA296_0		(0x1u<<0)

// HUFFSYMB75 Configuration

#define	JPEG_HUFFSYMB75_DATA303			(0xFFu<<24)
#define	JPEG_HUFFSYMB75_DATA303_0		(0x1u<<24)
#define	JPEG_HUFFSYMB75_DATA302			(0xFFu<<16)
#define	JPEG_HUFFSYMB75_DATA302_0		(0x1u<<16)
#define	JPEG_HUFFSYMB75_DATA301			(0xFFu<<8)
#define	JPEG_HUFFSYMB75_DATA301_0		(0x1u<<8)
#define	JPEG_HUFFSYMB75_DATA300			(0xFFu<<0)
#define	JPEG_HUFFSYMB75_DATA300_0		(0x1u<<0)

// HUFFSYMB76 Configuration

#define	JPEG_HUFFSYMB76_DATA307			(0xFFu<<24)
#define	JPEG_HUFFSYMB76_DATA307_0		(0x1u<<24)
#define	JPEG_HUFFSYMB76_DATA306			(0xFFu<<16)
#define	JPEG_HUFFSYMB76_DATA306_0		(0x1u<<16)
#define	JPEG_HUFFSYMB76_DATA305			(0xFFu<<8)
#define	JPEG_HUFFSYMB76_DATA305_0		(0x1u<<8)
#define	JPEG_HUFFSYMB76_DATA304			(0xFFu<<0)
#define	JPEG_HUFFSYMB76_DATA304_0		(0x1u<<0)

// HUFFSYMB77 Configuration

#define	JPEG_HUFFSYMB77_DATA311			(0xFFu<<24)
#define	JPEG_HUFFSYMB77_DATA311_0		(0x1u<<24)
#define	JPEG_HUFFSYMB77_DATA310			(0xFFu<<16)
#define	JPEG_HUFFSYMB77_DATA310_0		(0x1u<<16)
#define	JPEG_HUFFSYMB77_DATA309			(0xFFu<<8)
#define	JPEG_HUFFSYMB77_DATA309_0		(0x1u<<8)
#define	JPEG_HUFFSYMB77_DATA308			(0xFFu<<0)
#define	JPEG_HUFFSYMB77_DATA308_0		(0x1u<<0)

// HUFFSYMB78 Configuration

#define	JPEG_HUFFSYMB78_DATA315			(0xFFu<<24)
#define	JPEG_HUFFSYMB78_DATA315_0		(0x1u<<24)
#define	JPEG_HUFFSYMB78_DATA314			(0xFFu<<16)
#define	JPEG_HUFFSYMB78_DATA314_0		(0x1u<<16)
#define	JPEG_HUFFSYMB78_DATA313			(0xFFu<<8)
#define	JPEG_HUFFSYMB78_DATA313_0		(0x1u<<8)
#define	JPEG_HUFFSYMB78_DATA312			(0xFFu<<0)
#define	JPEG_HUFFSYMB78_DATA312_0		(0x1u<<0)

// HUFFSYMB79 Configuration

#define	JPEG_HUFFSYMB79_DATA319			(0xFFu<<24)
#define	JPEG_HUFFSYMB79_DATA319_0		(0x1u<<24)
#define	JPEG_HUFFSYMB79_DATA318			(0xFFu<<16)
#define	JPEG_HUFFSYMB79_DATA318_0		(0x1u<<16)
#define	JPEG_HUFFSYMB79_DATA317			(0xFFu<<8)
#define	JPEG_HUFFSYMB79_DATA317_0		(0x1u<<8)
#define	JPEG_HUFFSYMB79_DATA316			(0xFFu<<0)
#define	JPEG_HUFFSYMB79_DATA316_0		(0x1u<<0)

// HUFFSYMB80 Configuration

#define	JPEG_HUFFSYMB80_DATA323			(0xFFu<<24)
#define	JPEG_HUFFSYMB80_DATA323_0		(0x1u<<24)
#define	JPEG_HUFFSYMB80_DATA322			(0xFFu<<16)
#define	JPEG_HUFFSYMB80_DATA322_0		(0x1u<<16)
#define	JPEG_HUFFSYMB80_DATA321			(0xFFu<<8)
#define	JPEG_HUFFSYMB80_DATA321_0		(0x1u<<8)
#define	JPEG_HUFFSYMB80_DATA320			(0xFFu<<0)
#define	JPEG_HUFFSYMB80_DATA320_0		(0x1u<<0)

// HUFFSYMB81 Configuration

#define	JPEG_HUFFSYMB81_DATA327			(0xFFu<<24)
#define	JPEG_HUFFSYMB81_DATA327_0		(0x1u<<24)
#define	JPEG_HUFFSYMB81_DATA326			(0xFFu<<16)
#define	JPEG_HUFFSYMB81_DATA326_0		(0x1u<<16)
#define	JPEG_HUFFSYMB81_DATA325			(0xFFu<<8)
#define	JPEG_HUFFSYMB81_DATA325_0		(0x1u<<8)
#define	JPEG_HUFFSYMB81_DATA324			(0xFFu<<0)
#define	JPEG_HUFFSYMB81_DATA324_0		(0x1u<<0)

// HUFFSYMB82 Configuration

#define	JPEG_HUFFSYMB82_DATA331			(0xFFu<<24)
#define	JPEG_HUFFSYMB82_DATA331_0		(0x1u<<24)
#define	JPEG_HUFFSYMB82_DATA330			(0xFFu<<16)
#define	JPEG_HUFFSYMB82_DATA330_0		(0x1u<<16)
#define	JPEG_HUFFSYMB82_DATA329			(0xFFu<<8)
#define	JPEG_HUFFSYMB82_DATA329_0		(0x1u<<8)
#define	JPEG_HUFFSYMB82_DATA328			(0xFFu<<0)
#define	JPEG_HUFFSYMB82_DATA328_0		(0x1u<<0)

// HUFFSYMB83 Configuration

#define	JPEG_HUFFSYMB83_DATA335			(0xFFu<<24)
#define	JPEG_HUFFSYMB83_DATA335_0		(0x1u<<24)
#define	JPEG_HUFFSYMB83_DATA334			(0xFFu<<16)
#define	JPEG_HUFFSYMB83_DATA334_0		(0x1u<<16)
#define	JPEG_HUFFSYMB83_DATA333			(0xFFu<<8)
#define	JPEG_HUFFSYMB83_DATA333_0		(0x1u<<8)
#define	JPEG_HUFFSYMB83_DATA332			(0xFFu<<0)
#define	JPEG_HUFFSYMB83_DATA332_0		(0x1u<<0)

// DHTMEM0 Configuration

#define	JPEG_DHTMEM0_DATA3				(0xFFu<<24)
#define	JPEG_DHTMEM0_DATA3_0			(0x1u<<24)
#define	JPEG_DHTMEM0_DATA2				(0xFFu<<16)
#define	JPEG_DHTMEM0_DATA2_0			(0x1u<<16)
#define	JPEG_DHTMEM0_DATA1				(0xFFu<<8)
#define	JPEG_DHTMEM0_DATA1_0			(0x1u<<8)
#define	JPEG_DHTMEM0_DATA0				(0xFFu<<0)
#define	JPEG_DHTMEM0_DATA0_0			(0x1u<<0)

// DHTMEM1 Configuration

#define	JPEG_DHTMEM1_DATA7				(0xFFu<<24)
#define	JPEG_DHTMEM1_DATA7_0			(0x1u<<24)
#define	JPEG_DHTMEM1_DATA6				(0xFFu<<16)
#define	JPEG_DHTMEM1_DATA6_0			(0x1u<<16)
#define	JPEG_DHTMEM1_DATA5				(0xFFu<<8)
#define	JPEG_DHTMEM1_DATA5_0			(0x1u<<8)
#define	JPEG_DHTMEM1_DATA4				(0xFFu<<0)
#define	JPEG_DHTMEM1_DATA4_0			(0x1u<<0)

// DHTMEM2 Configuration

#define	JPEG_DHTMEM2_DATA11				(0xFFu<<24)
#define	JPEG_DHTMEM2_DATA11_0			(0x1u<<24)
#define	JPEG_DHTMEM2_DATA10				(0xFFu<<16)
#define	JPEG_DHTMEM2_DATA10_0			(0x1u<<16)
#define	JPEG_DHTMEM2_DATA9				(0xFFu<<8)
#define	JPEG_DHTMEM2_DATA9_0			(0x1u<<8)
#define	JPEG_DHTMEM2_DATA8				(0xFFu<<0)
#define	JPEG_DHTMEM2_DATA8_0			(0x1u<<0)

// DHTMEM3 Configuration

#define	JPEG_DHTMEM3_DATA15				(0xFFu<<24)
#define	JPEG_DHTMEM3_DATA15_0			(0x1u<<24)
#define	JPEG_DHTMEM3_DATA14				(0xFFu<<16)
#define	JPEG_DHTMEM3_DATA14_0			(0x1u<<16)
#define	JPEG_DHTMEM3_DATA13				(0xFFu<<8)
#define	JPEG_DHTMEM3_DATA13_0			(0x1u<<8)
#define	JPEG_DHTMEM3_DATA12				(0xFFu<<0)
#define	JPEG_DHTMEM3_DATA12_0			(0x1u<<0)

// DHTMEM4 Configuration

#define	JPEG_DHTMEM4_DATA19				(0xFFu<<24)
#define	JPEG_DHTMEM4_DATA19_0			(0x1u<<24)
#define	JPEG_DHTMEM4_DATA18				(0xFFu<<16)
#define	JPEG_DHTMEM4_DATA18_0			(0x1u<<16)
#define	JPEG_DHTMEM4_DATA17				(0xFFu<<8)
#define	JPEG_DHTMEM4_DATA17_0			(0x1u<<8)
#define	JPEG_DHTMEM4_DATA16				(0xFFu<<0)
#define	JPEG_DHTMEM4_DATA16_0			(0x1u<<0)

// DHTMEM5 Configuration

#define	JPEG_DHTMEM5_DATA23				(0xFFu<<24)
#define	JPEG_DHTMEM5_DATA23_0			(0x1u<<24)
#define	JPEG_DHTMEM5_DATA22				(0xFFu<<16)
#define	JPEG_DHTMEM5_DATA22_0			(0x1u<<16)
#define	JPEG_DHTMEM5_DATA21				(0xFFu<<8)
#define	JPEG_DHTMEM5_DATA21_0			(0x1u<<8)
#define	JPEG_DHTMEM5_DATA20				(0xFFu<<0)
#define	JPEG_DHTMEM5_DATA20_0			(0x1u<<0)

// DHTMEM6 Configuration

#define	JPEG_DHTMEM6_DATA27				(0xFFu<<24)
#define	JPEG_DHTMEM6_DATA27_0			(0x1u<<24)
#define	JPEG_DHTMEM6_DATA26				(0xFFu<<16)
#define	JPEG_DHTMEM6_DATA26_0			(0x1u<<16)
#define	JPEG_DHTMEM6_DATA25				(0xFFu<<8)
#define	JPEG_DHTMEM6_DATA25_0			(0x1u<<8)
#define	JPEG_DHTMEM6_DATA24				(0xFFu<<0)
#define	JPEG_DHTMEM6_DATA24_0			(0x1u<<0)

// DHTMEM7 Configuration

#define	JPEG_DHTMEM7_DATA31				(0xFFu<<24)
#define	JPEG_DHTMEM7_DATA31_0			(0x1u<<24)
#define	JPEG_DHTMEM7_DATA30				(0xFFu<<16)
#define	JPEG_DHTMEM7_DATA30_0			(0x1u<<16)
#define	JPEG_DHTMEM7_DATA29				(0xFFu<<8)
#define	JPEG_DHTMEM7_DATA29_0			(0x1u<<8)
#define	JPEG_DHTMEM7_DATA28				(0xFFu<<0)
#define	JPEG_DHTMEM7_DATA28_0			(0x1u<<0)

// DHTMEM8 Configuration

#define	JPEG_DHTMEM8_DATA35				(0xFFu<<24)
#define	JPEG_DHTMEM8_DATA35_0			(0x1u<<24)
#define	JPEG_DHTMEM8_DATA34				(0xFFu<<16)
#define	JPEG_DHTMEM8_DATA34_0			(0x1u<<16)
#define	JPEG_DHTMEM8_DATA33				(0xFFu<<8)
#define	JPEG_DHTMEM8_DATA33_0			(0x1u<<8)
#define	JPEG_DHTMEM8_DATA32				(0xFFu<<0)
#define	JPEG_DHTMEM8_DATA32_0			(0x1u<<0)

// DHTMEM9 Configuration

#define	JPEG_DHTMEM9_DATA39				(0xFFu<<24)
#define	JPEG_DHTMEM9_DATA39_0			(0x1u<<24)
#define	JPEG_DHTMEM9_DATA38				(0xFFu<<16)
#define	JPEG_DHTMEM9_DATA38_0			(0x1u<<16)
#define	JPEG_DHTMEM9_DATA37				(0xFFu<<8)
#define	JPEG_DHTMEM9_DATA37_0			(0x1u<<8)
#define	JPEG_DHTMEM9_DATA36				(0xFFu<<0)
#define	JPEG_DHTMEM9_DATA36_0			(0x1u<<0)

// DHTMEM10 Configuration

#define	JPEG_DHTMEM10_DATA43			(0xFFu<<24)
#define	JPEG_DHTMEM10_DATA43_0			(0x1u<<24)
#define	JPEG_DHTMEM10_DATA42			(0xFFu<<16)
#define	JPEG_DHTMEM10_DATA42_0			(0x1u<<16)
#define	JPEG_DHTMEM10_DATA41			(0xFFu<<8)
#define	JPEG_DHTMEM10_DATA41_0			(0x1u<<8)
#define	JPEG_DHTMEM10_DATA40			(0xFFu<<0)
#define	JPEG_DHTMEM10_DATA40_0			(0x1u<<0)

// DHTMEM11 Configuration

#define	JPEG_DHTMEM11_DATA47			(0xFFu<<24)
#define	JPEG_DHTMEM11_DATA47_0			(0x1u<<24)
#define	JPEG_DHTMEM11_DATA46			(0xFFu<<16)
#define	JPEG_DHTMEM11_DATA46_0			(0x1u<<16)
#define	JPEG_DHTMEM11_DATA45			(0xFFu<<8)
#define	JPEG_DHTMEM11_DATA45_0			(0x1u<<8)
#define	JPEG_DHTMEM11_DATA44			(0xFFu<<0)
#define	JPEG_DHTMEM11_DATA44_0			(0x1u<<0)

// DHTMEM12 Configuration

#define	JPEG_DHTMEM12_DATA51			(0xFFu<<24)
#define	JPEG_DHTMEM12_DATA51_0			(0x1u<<24)
#define	JPEG_DHTMEM12_DATA50			(0xFFu<<16)
#define	JPEG_DHTMEM12_DATA50_0			(0x1u<<16)
#define	JPEG_DHTMEM12_DATA49			(0xFFu<<8)
#define	JPEG_DHTMEM12_DATA49_0			(0x1u<<8)
#define	JPEG_DHTMEM12_DATA48			(0xFFu<<0)
#define	JPEG_DHTMEM12_DATA48_0			(0x1u<<0)

// DHTMEM13 Configuration

#define	JPEG_DHTMEM13_DATA55			(0xFFu<<24)
#define	JPEG_DHTMEM13_DATA55_0			(0x1u<<24)
#define	JPEG_DHTMEM13_DATA54			(0xFFu<<16)
#define	JPEG_DHTMEM13_DATA54_0			(0x1u<<16)
#define	JPEG_DHTMEM13_DATA53			(0xFFu<<8)
#define	JPEG_DHTMEM13_DATA53_0			(0x1u<<8)
#define	JPEG_DHTMEM13_DATA52			(0xFFu<<0)
#define	JPEG_DHTMEM13_DATA52_0			(0x1u<<0)

// DHTMEM14 Configuration

#define	JPEG_DHTMEM14_DATA59			(0xFFu<<24)
#define	JPEG_DHTMEM14_DATA59_0			(0x1u<<24)
#define	JPEG_DHTMEM14_DATA58			(0xFFu<<16)
#define	JPEG_DHTMEM14_DATA58_0			(0x1u<<16)
#define	JPEG_DHTMEM14_DATA57			(0xFFu<<8)
#define	JPEG_DHTMEM14_DATA57_0			(0x1u<<8)
#define	JPEG_DHTMEM14_DATA56			(0xFFu<<0)
#define	JPEG_DHTMEM14_DATA56_0			(0x1u<<0)

// DHTMEM15 Configuration

#define	JPEG_DHTMEM15_DATA63			(0xFFu<<24)
#define	JPEG_DHTMEM15_DATA63_0			(0x1u<<24)
#define	JPEG_DHTMEM15_DATA62			(0xFFu<<16)
#define	JPEG_DHTMEM15_DATA62_0			(0x1u<<16)
#define	JPEG_DHTMEM15_DATA61			(0xFFu<<8)
#define	JPEG_DHTMEM15_DATA61_0			(0x1u<<8)
#define	JPEG_DHTMEM15_DATA60			(0xFFu<<0)
#define	JPEG_DHTMEM15_DATA60_0			(0x1u<<0)

// DHTMEM16 Configuration

#define	JPEG_DHTMEM16_DATA67			(0xFFu<<24)
#define	JPEG_DHTMEM16_DATA67_0			(0x1u<<24)
#define	JPEG_DHTMEM16_DATA66			(0xFFu<<16)
#define	JPEG_DHTMEM16_DATA66_0			(0x1u<<16)
#define	JPEG_DHTMEM16_DATA65			(0xFFu<<8)
#define	JPEG_DHTMEM16_DATA65_0			(0x1u<<8)
#define	JPEG_DHTMEM16_DATA64			(0xFFu<<0)
#define	JPEG_DHTMEM16_DATA64_0			(0x1u<<0)

// DHTMEM17 Configuration

#define	JPEG_DHTMEM17_DATA71			(0xFFu<<24)
#define	JPEG_DHTMEM17_DATA71_0			(0x1u<<24)
#define	JPEG_DHTMEM17_DATA70			(0xFFu<<16)
#define	JPEG_DHTMEM17_DATA70_0			(0x1u<<16)
#define	JPEG_DHTMEM17_DATA69			(0xFFu<<8)
#define	JPEG_DHTMEM17_DATA69_0			(0x1u<<8)
#define	JPEG_DHTMEM17_DATA68			(0xFFu<<0)
#define	JPEG_DHTMEM17_DATA68_0			(0x1u<<0)

// DHTMEM18 Configuration

#define	JPEG_DHTMEM18_DATA75			(0xFFu<<24)
#define	JPEG_DHTMEM18_DATA75_0			(0x1u<<24)
#define	JPEG_DHTMEM18_DATA74			(0xFFu<<16)
#define	JPEG_DHTMEM18_DATA74_0			(0x1u<<16)
#define	JPEG_DHTMEM18_DATA73			(0xFFu<<8)
#define	JPEG_DHTMEM18_DATA73_0			(0x1u<<8)
#define	JPEG_DHTMEM18_DATA72			(0xFFu<<0)
#define	JPEG_DHTMEM18_DATA72_0			(0x1u<<0)

// DHTMEM19 Configuration

#define	JPEG_DHTMEM19_DATA79			(0xFFu<<24)
#define	JPEG_DHTMEM19_DATA79_0			(0x1u<<24)
#define	JPEG_DHTMEM19_DATA78			(0xFFu<<16)
#define	JPEG_DHTMEM19_DATA78_0			(0x1u<<16)
#define	JPEG_DHTMEM19_DATA77			(0xFFu<<8)
#define	JPEG_DHTMEM19_DATA77_0			(0x1u<<8)
#define	JPEG_DHTMEM19_DATA76			(0xFFu<<0)
#define	JPEG_DHTMEM19_DATA76_0			(0x1u<<0)

// DHTMEM20 Configuration

#define	JPEG_DHTMEM20_DATA83			(0xFFu<<24)
#define	JPEG_DHTMEM20_DATA83_0			(0x1u<<24)
#define	JPEG_DHTMEM20_DATA82			(0xFFu<<16)
#define	JPEG_DHTMEM20_DATA82_0			(0x1u<<16)
#define	JPEG_DHTMEM20_DATA81			(0xFFu<<8)
#define	JPEG_DHTMEM20_DATA81_0			(0x1u<<8)
#define	JPEG_DHTMEM20_DATA80			(0xFFu<<0)
#define	JPEG_DHTMEM20_DATA80_0			(0x1u<<0)

// DHTMEM21 Configuration

#define	JPEG_DHTMEM21_DATA87			(0xFFu<<24)
#define	JPEG_DHTMEM21_DATA87_0			(0x1u<<24)
#define	JPEG_DHTMEM21_DATA86			(0xFFu<<16)
#define	JPEG_DHTMEM21_DATA86_0			(0x1u<<16)
#define	JPEG_DHTMEM21_DATA85			(0xFFu<<8)
#define	JPEG_DHTMEM21_DATA85_0			(0x1u<<8)
#define	JPEG_DHTMEM21_DATA84			(0xFFu<<0)
#define	JPEG_DHTMEM21_DATA84_0			(0x1u<<0)

// DHTMEM22 Configuration

#define	JPEG_DHTMEM22_DATA91			(0xFFu<<24)
#define	JPEG_DHTMEM22_DATA91_0			(0x1u<<24)
#define	JPEG_DHTMEM22_DATA90			(0xFFu<<16)
#define	JPEG_DHTMEM22_DATA90_0			(0x1u<<16)
#define	JPEG_DHTMEM22_DATA89			(0xFFu<<8)
#define	JPEG_DHTMEM22_DATA89_0			(0x1u<<8)
#define	JPEG_DHTMEM22_DATA88			(0xFFu<<0)
#define	JPEG_DHTMEM22_DATA88_0			(0x1u<<0)

// DHTMEM23 Configuration

#define	JPEG_DHTMEM23_DATA95			(0xFFu<<24)
#define	JPEG_DHTMEM23_DATA95_0			(0x1u<<24)
#define	JPEG_DHTMEM23_DATA94			(0xFFu<<16)
#define	JPEG_DHTMEM23_DATA94_0			(0x1u<<16)
#define	JPEG_DHTMEM23_DATA93			(0xFFu<<8)
#define	JPEG_DHTMEM23_DATA93_0			(0x1u<<8)
#define	JPEG_DHTMEM23_DATA92			(0xFFu<<0)
#define	JPEG_DHTMEM23_DATA92_0			(0x1u<<0)

// DHTMEM24 Configuration

#define	JPEG_DHTMEM24_DATA99			(0xFFu<<24)
#define	JPEG_DHTMEM24_DATA99_0			(0x1u<<24)
#define	JPEG_DHTMEM24_DATA98			(0xFFu<<16)
#define	JPEG_DHTMEM24_DATA98_0			(0x1u<<16)
#define	JPEG_DHTMEM24_DATA97			(0xFFu<<8)
#define	JPEG_DHTMEM24_DATA97_0			(0x1u<<8)
#define	JPEG_DHTMEM24_DATA96			(0xFFu<<0)
#define	JPEG_DHTMEM24_DATA96_0			(0x1u<<0)

// DHTMEM25 Configuration

#define	JPEG_DHTMEM25_DATA103			(0xFFu<<24)
#define	JPEG_DHTMEM25_DATA103_0			(0x1u<<24)
#define	JPEG_DHTMEM25_DATA102			(0xFFu<<16)
#define	JPEG_DHTMEM25_DATA102_0			(0x1u<<16)
#define	JPEG_DHTMEM25_DATA101			(0xFFu<<8)
#define	JPEG_DHTMEM25_DATA101_0			(0x1u<<8)
#define	JPEG_DHTMEM25_DATA100			(0xFFu<<0)
#define	JPEG_DHTMEM25_DATA100_0			(0x1u<<0)

// DHTMEM26 Configuration

#define	JPEG_DHTMEM26_DATA107			(0xFFu<<24)
#define	JPEG_DHTMEM26_DATA107_0			(0x1u<<24)
#define	JPEG_DHTMEM26_DATA106			(0xFFu<<16)
#define	JPEG_DHTMEM26_DATA106_0			(0x1u<<16)
#define	JPEG_DHTMEM26_DATA105			(0xFFu<<8)
#define	JPEG_DHTMEM26_DATA105_0			(0x1u<<8)
#define	JPEG_DHTMEM26_DATA104			(0xFFu<<0)
#define	JPEG_DHTMEM26_DATA104_0			(0x1u<<0)

// DHTMEM27 Configuration

#define	JPEG_DHTMEM27_DATA111			(0xFFu<<24)
#define	JPEG_DHTMEM27_DATA111_0			(0x1u<<24)
#define	JPEG_DHTMEM27_DATA110			(0xFFu<<16)
#define	JPEG_DHTMEM27_DATA110_0			(0x1u<<16)
#define	JPEG_DHTMEM27_DATA109			(0xFFu<<8)
#define	JPEG_DHTMEM27_DATA109_0			(0x1u<<8)
#define	JPEG_DHTMEM27_DATA108			(0xFFu<<0)
#define	JPEG_DHTMEM27_DATA108_0			(0x1u<<0)

// DHTMEM28 Configuration

#define	JPEG_DHTMEM28_DATA115			(0xFFu<<24)
#define	JPEG_DHTMEM28_DATA115_0			(0x1u<<24)
#define	JPEG_DHTMEM28_DATA114			(0xFFu<<16)
#define	JPEG_DHTMEM28_DATA114_0			(0x1u<<16)
#define	JPEG_DHTMEM28_DATA113			(0xFFu<<8)
#define	JPEG_DHTMEM28_DATA113_0			(0x1u<<8)
#define	JPEG_DHTMEM28_DATA112			(0xFFu<<0)
#define	JPEG_DHTMEM28_DATA112_0			(0x1u<<0)

// DHTMEM29 Configuration

#define	JPEG_DHTMEM29_DATA119			(0xFFu<<24)
#define	JPEG_DHTMEM29_DATA119_0			(0x1u<<24)
#define	JPEG_DHTMEM29_DATA118			(0xFFu<<16)
#define	JPEG_DHTMEM29_DATA118_0			(0x1u<<16)
#define	JPEG_DHTMEM29_DATA117			(0xFFu<<8)
#define	JPEG_DHTMEM29_DATA117_0			(0x1u<<8)
#define	JPEG_DHTMEM29_DATA116			(0xFFu<<0)
#define	JPEG_DHTMEM29_DATA116_0			(0x1u<<0)

// DHTMEM30 Configuration

#define	JPEG_DHTMEM30_DATA123			(0xFFu<<24)
#define	JPEG_DHTMEM30_DATA123_0			(0x1u<<24)
#define	JPEG_DHTMEM30_DATA122			(0xFFu<<16)
#define	JPEG_DHTMEM30_DATA122_0			(0x1u<<16)
#define	JPEG_DHTMEM30_DATA121			(0xFFu<<8)
#define	JPEG_DHTMEM30_DATA121_0			(0x1u<<8)
#define	JPEG_DHTMEM30_DATA120			(0xFFu<<0)
#define	JPEG_DHTMEM30_DATA120_0			(0x1u<<0)

// DHTMEM31 Configuration

#define	JPEG_DHTMEM31_DATA127			(0xFFu<<24)
#define	JPEG_DHTMEM31_DATA127_0			(0x1u<<24)
#define	JPEG_DHTMEM31_DATA126			(0xFFu<<16)
#define	JPEG_DHTMEM31_DATA126_0			(0x1u<<16)
#define	JPEG_DHTMEM31_DATA125			(0xFFu<<8)
#define	JPEG_DHTMEM31_DATA125_0			(0x1u<<8)
#define	JPEG_DHTMEM31_DATA124			(0xFFu<<0)
#define	JPEG_DHTMEM31_DATA124_0			(0x1u<<0)

// DHTMEM32 Configuration

#define	JPEG_DHTMEM32_DATA131			(0xFFu<<24)
#define	JPEG_DHTMEM32_DATA131_0			(0x1u<<24)
#define	JPEG_DHTMEM32_DATA130			(0xFFu<<16)
#define	JPEG_DHTMEM32_DATA130_0			(0x1u<<16)
#define	JPEG_DHTMEM32_DATA129			(0xFFu<<8)
#define	JPEG_DHTMEM32_DATA129_0			(0x1u<<8)
#define	JPEG_DHTMEM32_DATA128			(0xFFu<<0)
#define	JPEG_DHTMEM32_DATA128_0			(0x1u<<0)

// DHTMEM33 Configuration

#define	JPEG_DHTMEM33_DATA135			(0xFFu<<24)
#define	JPEG_DHTMEM33_DATA135_0			(0x1u<<24)
#define	JPEG_DHTMEM33_DATA134			(0xFFu<<16)
#define	JPEG_DHTMEM33_DATA134_0			(0x1u<<16)
#define	JPEG_DHTMEM33_DATA133			(0xFFu<<8)
#define	JPEG_DHTMEM33_DATA133_0			(0x1u<<8)
#define	JPEG_DHTMEM33_DATA132			(0xFFu<<0)
#define	JPEG_DHTMEM33_DATA132_0			(0x1u<<0)

// DHTMEM34 Configuration

#define	JPEG_DHTMEM34_DATA139			(0xFFu<<24)
#define	JPEG_DHTMEM34_DATA139_0			(0x1u<<24)
#define	JPEG_DHTMEM34_DATA138			(0xFFu<<16)
#define	JPEG_DHTMEM34_DATA138_0			(0x1u<<16)
#define	JPEG_DHTMEM34_DATA137			(0xFFu<<8)
#define	JPEG_DHTMEM34_DATA137_0			(0x1u<<8)
#define	JPEG_DHTMEM34_DATA136			(0xFFu<<0)
#define	JPEG_DHTMEM34_DATA136_0			(0x1u<<0)

// DHTMEM35 Configuration

#define	JPEG_DHTMEM35_DATA143			(0xFFu<<24)
#define	JPEG_DHTMEM35_DATA143_0			(0x1u<<24)
#define	JPEG_DHTMEM35_DATA142			(0xFFu<<16)
#define	JPEG_DHTMEM35_DATA142_0			(0x1u<<16)
#define	JPEG_DHTMEM35_DATA141			(0xFFu<<8)
#define	JPEG_DHTMEM35_DATA141_0			(0x1u<<8)
#define	JPEG_DHTMEM35_DATA140			(0xFFu<<0)
#define	JPEG_DHTMEM35_DATA140_0			(0x1u<<0)

// DHTMEM36 Configuration

#define	JPEG_DHTMEM36_DATA147			(0xFFu<<24)
#define	JPEG_DHTMEM36_DATA147_0			(0x1u<<24)
#define	JPEG_DHTMEM36_DATA146			(0xFFu<<16)
#define	JPEG_DHTMEM36_DATA146_0			(0x1u<<16)
#define	JPEG_DHTMEM36_DATA145			(0xFFu<<8)
#define	JPEG_DHTMEM36_DATA145_0			(0x1u<<8)
#define	JPEG_DHTMEM36_DATA144			(0xFFu<<0)
#define	JPEG_DHTMEM36_DATA144_0			(0x1u<<0)

// DHTMEM37 Configuration

#define	JPEG_DHTMEM37_DATA151			(0xFFu<<24)
#define	JPEG_DHTMEM37_DATA151_0			(0x1u<<24)
#define	JPEG_DHTMEM37_DATA150			(0xFFu<<16)
#define	JPEG_DHTMEM37_DATA150_0			(0x1u<<16)
#define	JPEG_DHTMEM37_DATA149			(0xFFu<<8)
#define	JPEG_DHTMEM37_DATA149_0			(0x1u<<8)
#define	JPEG_DHTMEM37_DATA148			(0xFFu<<0)
#define	JPEG_DHTMEM37_DATA148_0			(0x1u<<0)

// DHTMEM38 Configuration

#define	JPEG_DHTMEM38_DATA155			(0xFFu<<24)
#define	JPEG_DHTMEM38_DATA155_0			(0x1u<<24)
#define	JPEG_DHTMEM38_DATA154			(0xFFu<<16)
#define	JPEG_DHTMEM38_DATA154_0			(0x1u<<16)
#define	JPEG_DHTMEM38_DATA153			(0xFFu<<8)
#define	JPEG_DHTMEM38_DATA153_0			(0x1u<<8)
#define	JPEG_DHTMEM38_DATA152			(0xFFu<<0)
#define	JPEG_DHTMEM38_DATA152_0			(0x1u<<0)

// DHTMEM39 Configuration

#define	JPEG_DHTMEM39_DATA159			(0xFFu<<24)
#define	JPEG_DHTMEM39_DATA159_0			(0x1u<<24)
#define	JPEG_DHTMEM39_DATA158			(0xFFu<<16)
#define	JPEG_DHTMEM39_DATA158_0			(0x1u<<16)
#define	JPEG_DHTMEM39_DATA157			(0xFFu<<8)
#define	JPEG_DHTMEM39_DATA157_0			(0x1u<<8)
#define	JPEG_DHTMEM39_DATA156			(0xFFu<<0)
#define	JPEG_DHTMEM39_DATA156_0			(0x1u<<0)

// DHTMEM40 Configuration

#define	JPEG_DHTMEM40_DATA163			(0xFFu<<24)
#define	JPEG_DHTMEM40_DATA163_0			(0x1u<<24)
#define	JPEG_DHTMEM40_DATA162			(0xFFu<<16)
#define	JPEG_DHTMEM40_DATA162_0			(0x1u<<16)
#define	JPEG_DHTMEM40_DATA161			(0xFFu<<8)
#define	JPEG_DHTMEM40_DATA161_0			(0x1u<<8)
#define	JPEG_DHTMEM40_DATA160			(0xFFu<<0)
#define	JPEG_DHTMEM40_DATA160_0			(0x1u<<0)

// DHTMEM41 Configuration

#define	JPEG_DHTMEM41_DATA167			(0xFFu<<24)
#define	JPEG_DHTMEM41_DATA167_0			(0x1u<<24)
#define	JPEG_DHTMEM41_DATA166			(0xFFu<<16)
#define	JPEG_DHTMEM41_DATA166_0			(0x1u<<16)
#define	JPEG_DHTMEM41_DATA165			(0xFFu<<8)
#define	JPEG_DHTMEM41_DATA165_0			(0x1u<<8)
#define	JPEG_DHTMEM41_DATA164			(0xFFu<<0)
#define	JPEG_DHTMEM41_DATA164_0			(0x1u<<0)

// DHTMEM42 Configuration

#define	JPEG_DHTMEM42_DATA171			(0xFFu<<24)
#define	JPEG_DHTMEM42_DATA171_0			(0x1u<<24)
#define	JPEG_DHTMEM42_DATA170			(0xFFu<<16)
#define	JPEG_DHTMEM42_DATA170_0			(0x1u<<16)
#define	JPEG_DHTMEM42_DATA169			(0xFFu<<8)
#define	JPEG_DHTMEM42_DATA169_0			(0x1u<<8)
#define	JPEG_DHTMEM42_DATA168			(0xFFu<<0)
#define	JPEG_DHTMEM42_DATA168_0			(0x1u<<0)

// DHTMEM43 Configuration

#define	JPEG_DHTMEM43_DATA175			(0xFFu<<24)
#define	JPEG_DHTMEM43_DATA175_0			(0x1u<<24)
#define	JPEG_DHTMEM43_DATA174			(0xFFu<<16)
#define	JPEG_DHTMEM43_DATA174_0			(0x1u<<16)
#define	JPEG_DHTMEM43_DATA173			(0xFFu<<8)
#define	JPEG_DHTMEM43_DATA173_0			(0x1u<<8)
#define	JPEG_DHTMEM43_DATA172			(0xFFu<<0)
#define	JPEG_DHTMEM43_DATA172_0			(0x1u<<0)

// DHTMEM44 Configuration

#define	JPEG_DHTMEM44_DATA179			(0xFFu<<24)
#define	JPEG_DHTMEM44_DATA179_0			(0x1u<<24)
#define	JPEG_DHTMEM44_DATA178			(0xFFu<<16)
#define	JPEG_DHTMEM44_DATA178_0			(0x1u<<16)
#define	JPEG_DHTMEM44_DATA177			(0xFFu<<8)
#define	JPEG_DHTMEM44_DATA177_0			(0x1u<<8)
#define	JPEG_DHTMEM44_DATA176			(0xFFu<<0)
#define	JPEG_DHTMEM44_DATA176_0			(0x1u<<0)

// DHTMEM45 Configuration

#define	JPEG_DHTMEM45_DATA183			(0xFFu<<24)
#define	JPEG_DHTMEM45_DATA183_0			(0x1u<<24)
#define	JPEG_DHTMEM45_DATA182			(0xFFu<<16)
#define	JPEG_DHTMEM45_DATA182_0			(0x1u<<16)
#define	JPEG_DHTMEM45_DATA181			(0xFFu<<8)
#define	JPEG_DHTMEM45_DATA181_0			(0x1u<<8)
#define	JPEG_DHTMEM45_DATA180			(0xFFu<<0)
#define	JPEG_DHTMEM45_DATA180_0			(0x1u<<0)

// DHTMEM46 Configuration

#define	JPEG_DHTMEM46_DATA187			(0xFFu<<24)
#define	JPEG_DHTMEM46_DATA187_0			(0x1u<<24)
#define	JPEG_DHTMEM46_DATA186			(0xFFu<<16)
#define	JPEG_DHTMEM46_DATA186_0			(0x1u<<16)
#define	JPEG_DHTMEM46_DATA185			(0xFFu<<8)
#define	JPEG_DHTMEM46_DATA185_0			(0x1u<<8)
#define	JPEG_DHTMEM46_DATA184			(0xFFu<<0)
#define	JPEG_DHTMEM46_DATA184_0			(0x1u<<0)

// DHTMEM47 Configuration

#define	JPEG_DHTMEM47_DATA191			(0xFFu<<24)
#define	JPEG_DHTMEM47_DATA191_0			(0x1u<<24)
#define	JPEG_DHTMEM47_DATA190			(0xFFu<<16)
#define	JPEG_DHTMEM47_DATA190_0			(0x1u<<16)
#define	JPEG_DHTMEM47_DATA189			(0xFFu<<8)
#define	JPEG_DHTMEM47_DATA189_0			(0x1u<<8)
#define	JPEG_DHTMEM47_DATA188			(0xFFu<<0)
#define	JPEG_DHTMEM47_DATA188_0			(0x1u<<0)

// DHTMEM48 Configuration

#define	JPEG_DHTMEM48_DATA195			(0xFFu<<24)
#define	JPEG_DHTMEM48_DATA195_0			(0x1u<<24)
#define	JPEG_DHTMEM48_DATA194			(0xFFu<<16)
#define	JPEG_DHTMEM48_DATA194_0			(0x1u<<16)
#define	JPEG_DHTMEM48_DATA193			(0xFFu<<8)
#define	JPEG_DHTMEM48_DATA193_0			(0x1u<<8)
#define	JPEG_DHTMEM48_DATA192			(0xFFu<<0)
#define	JPEG_DHTMEM48_DATA192_0			(0x1u<<0)

// DHTMEM49 Configuration

#define	JPEG_DHTMEM49_DATA199			(0xFFu<<24)
#define	JPEG_DHTMEM49_DATA199_0			(0x1u<<24)
#define	JPEG_DHTMEM49_DATA198			(0xFFu<<16)
#define	JPEG_DHTMEM49_DATA198_0			(0x1u<<16)
#define	JPEG_DHTMEM49_DATA197			(0xFFu<<8)
#define	JPEG_DHTMEM49_DATA197_0			(0x1u<<8)
#define	JPEG_DHTMEM49_DATA196			(0xFFu<<0)
#define	JPEG_DHTMEM49_DATA196_0			(0x1u<<0)

// DHTMEM50 Configuration

#define	JPEG_DHTMEM50_DATA203			(0xFFu<<24)
#define	JPEG_DHTMEM50_DATA203_0			(0x1u<<24)
#define	JPEG_DHTMEM50_DATA202			(0xFFu<<16)
#define	JPEG_DHTMEM50_DATA202_0			(0x1u<<16)
#define	JPEG_DHTMEM50_DATA201			(0xFFu<<8)
#define	JPEG_DHTMEM50_DATA201_0			(0x1u<<8)
#define	JPEG_DHTMEM50_DATA200			(0xFFu<<0)
#define	JPEG_DHTMEM50_DATA200_0			(0x1u<<0)

// DHTMEM51 Configuration

#define	JPEG_DHTMEM51_DATA207			(0xFFu<<24)
#define	JPEG_DHTMEM51_DATA207_0			(0x1u<<24)
#define	JPEG_DHTMEM51_DATA206			(0xFFu<<16)
#define	JPEG_DHTMEM51_DATA206_0			(0x1u<<16)
#define	JPEG_DHTMEM51_DATA205			(0xFFu<<8)
#define	JPEG_DHTMEM51_DATA205_0			(0x1u<<8)
#define	JPEG_DHTMEM51_DATA204			(0xFFu<<0)
#define	JPEG_DHTMEM51_DATA204_0			(0x1u<<0)

// DHTMEM52 Configuration

#define	JPEG_DHTMEM52_DATA211			(0xFFu<<24)
#define	JPEG_DHTMEM52_DATA211_0			(0x1u<<24)
#define	JPEG_DHTMEM52_DATA210			(0xFFu<<16)
#define	JPEG_DHTMEM52_DATA210_0			(0x1u<<16)
#define	JPEG_DHTMEM52_DATA209			(0xFFu<<8)
#define	JPEG_DHTMEM52_DATA209_0			(0x1u<<8)
#define	JPEG_DHTMEM52_DATA208			(0xFFu<<0)
#define	JPEG_DHTMEM52_DATA208_0			(0x1u<<0)

// DHTMEM53 Configuration

#define	JPEG_DHTMEM53_DATA215			(0xFFu<<24)
#define	JPEG_DHTMEM53_DATA215_0			(0x1u<<24)
#define	JPEG_DHTMEM53_DATA214			(0xFFu<<16)
#define	JPEG_DHTMEM53_DATA214_0			(0x1u<<16)
#define	JPEG_DHTMEM53_DATA213			(0xFFu<<8)
#define	JPEG_DHTMEM53_DATA213_0			(0x1u<<8)
#define	JPEG_DHTMEM53_DATA212			(0xFFu<<0)
#define	JPEG_DHTMEM53_DATA212_0			(0x1u<<0)

// DHTMEM54 Configuration

#define	JPEG_DHTMEM54_DATA219			(0xFFu<<24)
#define	JPEG_DHTMEM54_DATA219_0			(0x1u<<24)
#define	JPEG_DHTMEM54_DATA218			(0xFFu<<16)
#define	JPEG_DHTMEM54_DATA218_0			(0x1u<<16)
#define	JPEG_DHTMEM54_DATA217			(0xFFu<<8)
#define	JPEG_DHTMEM54_DATA217_0			(0x1u<<8)
#define	JPEG_DHTMEM54_DATA216			(0xFFu<<0)
#define	JPEG_DHTMEM54_DATA216_0			(0x1u<<0)

// DHTMEM55 Configuration

#define	JPEG_DHTMEM55_DATA223			(0xFFu<<24)
#define	JPEG_DHTMEM55_DATA223_0			(0x1u<<24)
#define	JPEG_DHTMEM55_DATA222			(0xFFu<<16)
#define	JPEG_DHTMEM55_DATA222_0			(0x1u<<16)
#define	JPEG_DHTMEM55_DATA221			(0xFFu<<8)
#define	JPEG_DHTMEM55_DATA221_0			(0x1u<<8)
#define	JPEG_DHTMEM55_DATA220			(0xFFu<<0)
#define	JPEG_DHTMEM55_DATA220_0			(0x1u<<0)

// DHTMEM56 Configuration

#define	JPEG_DHTMEM56_DATA227			(0xFFu<<24)
#define	JPEG_DHTMEM56_DATA227_0			(0x1u<<24)
#define	JPEG_DHTMEM56_DATA226			(0xFFu<<16)
#define	JPEG_DHTMEM56_DATA226_0			(0x1u<<16)
#define	JPEG_DHTMEM56_DATA225			(0xFFu<<8)
#define	JPEG_DHTMEM56_DATA225_0			(0x1u<<8)
#define	JPEG_DHTMEM56_DATA224			(0xFFu<<0)
#define	JPEG_DHTMEM56_DATA224_0			(0x1u<<0)

// DHTMEM57 Configuration

#define	JPEG_DHTMEM57_DATA231			(0xFFu<<24)
#define	JPEG_DHTMEM57_DATA231_0			(0x1u<<24)
#define	JPEG_DHTMEM57_DATA230			(0xFFu<<16)
#define	JPEG_DHTMEM57_DATA230_0			(0x1u<<16)
#define	JPEG_DHTMEM57_DATA229			(0xFFu<<8)
#define	JPEG_DHTMEM57_DATA229_0			(0x1u<<8)
#define	JPEG_DHTMEM57_DATA228			(0xFFu<<0)
#define	JPEG_DHTMEM57_DATA228_0			(0x1u<<0)

// DHTMEM58 Configuration

#define	JPEG_DHTMEM58_DATA235			(0xFFu<<24)
#define	JPEG_DHTMEM58_DATA235_0			(0x1u<<24)
#define	JPEG_DHTMEM58_DATA234			(0xFFu<<16)
#define	JPEG_DHTMEM58_DATA234_0			(0x1u<<16)
#define	JPEG_DHTMEM58_DATA233			(0xFFu<<8)
#define	JPEG_DHTMEM58_DATA233_0			(0x1u<<8)
#define	JPEG_DHTMEM58_DATA232			(0xFFu<<0)
#define	JPEG_DHTMEM58_DATA232_0			(0x1u<<0)

// DHTMEM59 Configuration

#define	JPEG_DHTMEM59_DATA239			(0xFFu<<24)
#define	JPEG_DHTMEM59_DATA239_0			(0x1u<<24)
#define	JPEG_DHTMEM59_DATA238			(0xFFu<<16)
#define	JPEG_DHTMEM59_DATA238_0			(0x1u<<16)
#define	JPEG_DHTMEM59_DATA237			(0xFFu<<8)
#define	JPEG_DHTMEM59_DATA237_0			(0x1u<<8)
#define	JPEG_DHTMEM59_DATA236			(0xFFu<<0)
#define	JPEG_DHTMEM59_DATA236_0			(0x1u<<0)

// DHTMEM60 Configuration

#define	JPEG_DHTMEM60_DATA243			(0xFFu<<24)
#define	JPEG_DHTMEM60_DATA243_0			(0x1u<<24)
#define	JPEG_DHTMEM60_DATA242			(0xFFu<<16)
#define	JPEG_DHTMEM60_DATA242_0			(0x1u<<16)
#define	JPEG_DHTMEM60_DATA241			(0xFFu<<8)
#define	JPEG_DHTMEM60_DATA241_0			(0x1u<<8)
#define	JPEG_DHTMEM60_DATA240			(0xFFu<<0)
#define	JPEG_DHTMEM60_DATA240_0			(0x1u<<0)

// DHTMEM61 Configuration

#define	JPEG_DHTMEM61_DATA247			(0xFFu<<24)
#define	JPEG_DHTMEM61_DATA247_0			(0x1u<<24)
#define	JPEG_DHTMEM61_DATA246			(0xFFu<<16)
#define	JPEG_DHTMEM61_DATA246_0			(0x1u<<16)
#define	JPEG_DHTMEM61_DATA245			(0xFFu<<8)
#define	JPEG_DHTMEM61_DATA245_0			(0x1u<<8)
#define	JPEG_DHTMEM61_DATA244			(0xFFu<<0)
#define	JPEG_DHTMEM61_DATA244_0			(0x1u<<0)

// DHTMEM62 Configuration

#define	JPEG_DHTMEM62_DATA251			(0xFFu<<24)
#define	JPEG_DHTMEM62_DATA251_0			(0x1u<<24)
#define	JPEG_DHTMEM62_DATA250			(0xFFu<<16)
#define	JPEG_DHTMEM62_DATA250_0			(0x1u<<16)
#define	JPEG_DHTMEM62_DATA249			(0xFFu<<8)
#define	JPEG_DHTMEM62_DATA249_0			(0x1u<<8)
#define	JPEG_DHTMEM62_DATA248			(0xFFu<<0)
#define	JPEG_DHTMEM62_DATA248_0			(0x1u<<0)

// DHTMEM63 Configuration

#define	JPEG_DHTMEM63_DATA255			(0xFFu<<24)
#define	JPEG_DHTMEM63_DATA255_0			(0x1u<<24)
#define	JPEG_DHTMEM63_DATA254			(0xFFu<<16)
#define	JPEG_DHTMEM63_DATA254_0			(0x1u<<16)
#define	JPEG_DHTMEM63_DATA253			(0xFFu<<8)
#define	JPEG_DHTMEM63_DATA253_0			(0x1u<<8)
#define	JPEG_DHTMEM63_DATA252			(0xFFu<<0)
#define	JPEG_DHTMEM63_DATA252_0			(0x1u<<0)

// DHTMEM64 Configuration

#define	JPEG_DHTMEM64_DATA259			(0xFFu<<24)
#define	JPEG_DHTMEM64_DATA259_0			(0x1u<<24)
#define	JPEG_DHTMEM64_DATA258			(0xFFu<<16)
#define	JPEG_DHTMEM64_DATA258_0			(0x1u<<16)
#define	JPEG_DHTMEM64_DATA257			(0xFFu<<8)
#define	JPEG_DHTMEM64_DATA257_0			(0x1u<<8)
#define	JPEG_DHTMEM64_DATA256			(0xFFu<<0)
#define	JPEG_DHTMEM64_DATA256_0			(0x1u<<0)

// DHTMEM65 Configuration

#define	JPEG_DHTMEM65_DATA263			(0xFFu<<24)
#define	JPEG_DHTMEM65_DATA263_0			(0x1u<<24)
#define	JPEG_DHTMEM65_DATA262			(0xFFu<<16)
#define	JPEG_DHTMEM65_DATA262_0			(0x1u<<16)
#define	JPEG_DHTMEM65_DATA261			(0xFFu<<8)
#define	JPEG_DHTMEM65_DATA261_0			(0x1u<<8)
#define	JPEG_DHTMEM65_DATA260			(0xFFu<<0)
#define	JPEG_DHTMEM65_DATA260_0			(0x1u<<0)

// DHTMEM66 Configuration

#define	JPEG_DHTMEM66_DATA267			(0xFFu<<24)
#define	JPEG_DHTMEM66_DATA267_0			(0x1u<<24)
#define	JPEG_DHTMEM66_DATA266			(0xFFu<<16)
#define	JPEG_DHTMEM66_DATA266_0			(0x1u<<16)
#define	JPEG_DHTMEM66_DATA265			(0xFFu<<8)
#define	JPEG_DHTMEM66_DATA265_0			(0x1u<<8)
#define	JPEG_DHTMEM66_DATA264			(0xFFu<<0)
#define	JPEG_DHTMEM66_DATA264_0			(0x1u<<0)

// DHTMEM67 Configuration

#define	JPEG_DHTMEM67_DATA271			(0xFFu<<24)
#define	JPEG_DHTMEM67_DATA271_0			(0x1u<<24)
#define	JPEG_DHTMEM67_DATA270			(0xFFu<<16)
#define	JPEG_DHTMEM67_DATA270_0			(0x1u<<16)
#define	JPEG_DHTMEM67_DATA269			(0xFFu<<8)
#define	JPEG_DHTMEM67_DATA269_0			(0x1u<<8)
#define	JPEG_DHTMEM67_DATA268			(0xFFu<<0)
#define	JPEG_DHTMEM67_DATA268_0			(0x1u<<0)

// DHTMEM68 Configuration

#define	JPEG_DHTMEM68_DATA275			(0xFFu<<24)
#define	JPEG_DHTMEM68_DATA275_0			(0x1u<<24)
#define	JPEG_DHTMEM68_DATA274			(0xFFu<<16)
#define	JPEG_DHTMEM68_DATA274_0			(0x1u<<16)
#define	JPEG_DHTMEM68_DATA273			(0xFFu<<8)
#define	JPEG_DHTMEM68_DATA273_0			(0x1u<<8)
#define	JPEG_DHTMEM68_DATA272			(0xFFu<<0)
#define	JPEG_DHTMEM68_DATA272_0			(0x1u<<0)

// DHTMEM69 Configuration

#define	JPEG_DHTMEM69_DATA279			(0xFFu<<24)
#define	JPEG_DHTMEM69_DATA279_0			(0x1u<<24)
#define	JPEG_DHTMEM69_DATA278			(0xFFu<<16)
#define	JPEG_DHTMEM69_DATA278_0			(0x1u<<16)
#define	JPEG_DHTMEM69_DATA277			(0xFFu<<8)
#define	JPEG_DHTMEM69_DATA277_0			(0x1u<<8)
#define	JPEG_DHTMEM69_DATA276			(0xFFu<<0)
#define	JPEG_DHTMEM69_DATA276_0			(0x1u<<0)

// DHTMEM70 Configuration

#define	JPEG_DHTMEM70_DATA283			(0xFFu<<24)
#define	JPEG_DHTMEM70_DATA283_0			(0x1u<<24)
#define	JPEG_DHTMEM70_DATA282			(0xFFu<<16)
#define	JPEG_DHTMEM70_DATA282_0			(0x1u<<16)
#define	JPEG_DHTMEM70_DATA281			(0xFFu<<8)
#define	JPEG_DHTMEM70_DATA281_0			(0x1u<<8)
#define	JPEG_DHTMEM70_DATA280			(0xFFu<<0)
#define	JPEG_DHTMEM70_DATA280_0			(0x1u<<0)

// DHTMEM71 Configuration

#define	JPEG_DHTMEM71_DATA287			(0xFFu<<24)
#define	JPEG_DHTMEM71_DATA287_0			(0x1u<<24)
#define	JPEG_DHTMEM71_DATA286			(0xFFu<<16)
#define	JPEG_DHTMEM71_DATA286_0			(0x1u<<16)
#define	JPEG_DHTMEM71_DATA285			(0xFFu<<8)
#define	JPEG_DHTMEM71_DATA285_0			(0x1u<<8)
#define	JPEG_DHTMEM71_DATA284			(0xFFu<<0)
#define	JPEG_DHTMEM71_DATA284_0			(0x1u<<0)

// DHTMEM72 Configuration

#define	JPEG_DHTMEM72_DATA291			(0xFFu<<24)
#define	JPEG_DHTMEM72_DATA291_0			(0x1u<<24)
#define	JPEG_DHTMEM72_DATA290			(0xFFu<<16)
#define	JPEG_DHTMEM72_DATA290_0			(0x1u<<16)
#define	JPEG_DHTMEM72_DATA289			(0xFFu<<8)
#define	JPEG_DHTMEM72_DATA289_0			(0x1u<<8)
#define	JPEG_DHTMEM72_DATA288			(0xFFu<<0)
#define	JPEG_DHTMEM72_DATA288_0			(0x1u<<0)

// DHTMEM73 Configuration

#define	JPEG_DHTMEM73_DATA295			(0xFFu<<24)
#define	JPEG_DHTMEM73_DATA295_0			(0x1u<<24)
#define	JPEG_DHTMEM73_DATA294			(0xFFu<<16)
#define	JPEG_DHTMEM73_DATA294_0			(0x1u<<16)
#define	JPEG_DHTMEM73_DATA293			(0xFFu<<8)
#define	JPEG_DHTMEM73_DATA293_0			(0x1u<<8)
#define	JPEG_DHTMEM73_DATA292			(0xFFu<<0)
#define	JPEG_DHTMEM73_DATA292_0			(0x1u<<0)

// DHTMEM74 Configuration

#define	JPEG_DHTMEM74_DATA299			(0xFFu<<24)
#define	JPEG_DHTMEM74_DATA299_0			(0x1u<<24)
#define	JPEG_DHTMEM74_DATA298			(0xFFu<<16)
#define	JPEG_DHTMEM74_DATA298_0			(0x1u<<16)
#define	JPEG_DHTMEM74_DATA297			(0xFFu<<8)
#define	JPEG_DHTMEM74_DATA297_0			(0x1u<<8)
#define	JPEG_DHTMEM74_DATA296			(0xFFu<<0)
#define	JPEG_DHTMEM74_DATA296_0			(0x1u<<0)

// DHTMEM75 Configuration

#define	JPEG_DHTMEM75_DATA303			(0xFFu<<24)
#define	JPEG_DHTMEM75_DATA303_0			(0x1u<<24)
#define	JPEG_DHTMEM75_DATA302			(0xFFu<<16)
#define	JPEG_DHTMEM75_DATA302_0			(0x1u<<16)
#define	JPEG_DHTMEM75_DATA301			(0xFFu<<8)
#define	JPEG_DHTMEM75_DATA301_0			(0x1u<<8)
#define	JPEG_DHTMEM75_DATA300			(0xFFu<<0)
#define	JPEG_DHTMEM75_DATA300_0			(0x1u<<0)

// DHTMEM76 Configuration

#define	JPEG_DHTMEM76_DATA307			(0xFFu<<24)
#define	JPEG_DHTMEM76_DATA307_0			(0x1u<<24)
#define	JPEG_DHTMEM76_DATA306			(0xFFu<<16)
#define	JPEG_DHTMEM76_DATA306_0			(0x1u<<16)
#define	JPEG_DHTMEM76_DATA305			(0xFFu<<8)
#define	JPEG_DHTMEM76_DATA305_0			(0x1u<<8)
#define	JPEG_DHTMEM76_DATA304			(0xFFu<<0)
#define	JPEG_DHTMEM76_DATA304_0			(0x1u<<0)

// DHTMEM77 Configuration

#define	JPEG_DHTMEM77_DATA311			(0xFFu<<24)
#define	JPEG_DHTMEM77_DATA311_0			(0x1u<<24)
#define	JPEG_DHTMEM77_DATA310			(0xFFu<<16)
#define	JPEG_DHTMEM77_DATA310_0			(0x1u<<16)
#define	JPEG_DHTMEM77_DATA309			(0xFFu<<8)
#define	JPEG_DHTMEM77_DATA309_0			(0x1u<<8)
#define	JPEG_DHTMEM77_DATA308			(0xFFu<<0)
#define	JPEG_DHTMEM77_DATA308_0			(0x1u<<0)

// DHTMEM78 Configuration

#define	JPEG_DHTMEM78_DATA315			(0xFFu<<24)
#define	JPEG_DHTMEM78_DATA315_0			(0x1u<<24)
#define	JPEG_DHTMEM78_DATA314			(0xFFu<<16)
#define	JPEG_DHTMEM78_DATA314_0			(0x1u<<16)
#define	JPEG_DHTMEM78_DATA313			(0xFFu<<8)
#define	JPEG_DHTMEM78_DATA313_0			(0x1u<<8)
#define	JPEG_DHTMEM78_DATA312			(0xFFu<<0)
#define	JPEG_DHTMEM78_DATA312_0			(0x1u<<0)

// DHTMEM79 Configuration

#define	JPEG_DHTMEM79_DATA319			(0xFFu<<24)
#define	JPEG_DHTMEM79_DATA319_0			(0x1u<<24)
#define	JPEG_DHTMEM79_DATA318			(0xFFu<<16)
#define	JPEG_DHTMEM79_DATA318_0			(0x1u<<16)
#define	JPEG_DHTMEM79_DATA317			(0xFFu<<8)
#define	JPEG_DHTMEM79_DATA317_0			(0x1u<<8)
#define	JPEG_DHTMEM79_DATA316			(0xFFu<<0)
#define	JPEG_DHTMEM79_DATA316_0			(0x1u<<0)

// DHTMEM80 Configuration

#define	JPEG_DHTMEM80_DATA323			(0xFFu<<24)
#define	JPEG_DHTMEM80_DATA323_0			(0x1u<<24)
#define	JPEG_DHTMEM80_DATA322			(0xFFu<<16)
#define	JPEG_DHTMEM80_DATA322_0			(0x1u<<16)
#define	JPEG_DHTMEM80_DATA321			(0xFFu<<8)
#define	JPEG_DHTMEM80_DATA321_0			(0x1u<<8)
#define	JPEG_DHTMEM80_DATA320			(0xFFu<<0)
#define	JPEG_DHTMEM80_DATA320_0			(0x1u<<0)

// DHTMEM81 Configuration

#define	JPEG_DHTMEM81_DATA327			(0xFFu<<24)
#define	JPEG_DHTMEM81_DATA327_0			(0x1u<<24)
#define	JPEG_DHTMEM81_DATA326			(0xFFu<<16)
#define	JPEG_DHTMEM81_DATA326_0			(0x1u<<16)
#define	JPEG_DHTMEM81_DATA325			(0xFFu<<8)
#define	JPEG_DHTMEM81_DATA325_0			(0x1u<<8)
#define	JPEG_DHTMEM81_DATA324			(0xFFu<<0)
#define	JPEG_DHTMEM81_DATA324_0			(0x1u<<0)

// DHTMEM82 Configuration

#define	JPEG_DHTMEM82_DATA331			(0xFFu<<24)
#define	JPEG_DHTMEM82_DATA331_0			(0x1u<<24)
#define	JPEG_DHTMEM82_DATA330			(0xFFu<<16)
#define	JPEG_DHTMEM82_DATA330_0			(0x1u<<16)
#define	JPEG_DHTMEM82_DATA329			(0xFFu<<8)
#define	JPEG_DHTMEM82_DATA329_0			(0x1u<<8)
#define	JPEG_DHTMEM82_DATA328			(0xFFu<<0)
#define	JPEG_DHTMEM82_DATA328_0			(0x1u<<0)

// DHTMEM83 Configuration

#define	JPEG_DHTMEM83_DATA335			(0xFFu<<24)
#define	JPEG_DHTMEM83_DATA335_0			(0x1u<<24)
#define	JPEG_DHTMEM83_DATA334			(0xFFu<<16)
#define	JPEG_DHTMEM83_DATA334_0			(0x1u<<16)
#define	JPEG_DHTMEM83_DATA333			(0xFFu<<8)
#define	JPEG_DHTMEM83_DATA333_0			(0x1u<<8)
#define	JPEG_DHTMEM83_DATA332			(0xFFu<<0)
#define	JPEG_DHTMEM83_DATA332_0			(0x1u<<0)

// DHTMEM84 Configuration

#define	JPEG_DHTMEM84_DATA339			(0xFFu<<24)
#define	JPEG_DHTMEM84_DATA339_0			(0x1u<<24)
#define	JPEG_DHTMEM84_DATA338			(0xFFu<<16)
#define	JPEG_DHTMEM84_DATA338_0			(0x1u<<16)
#define	JPEG_DHTMEM84_DATA337			(0xFFu<<8)
#define	JPEG_DHTMEM84_DATA337_0			(0x1u<<8)
#define	JPEG_DHTMEM84_DATA336			(0xFFu<<0)
#define	JPEG_DHTMEM84_DATA336_0			(0x1u<<0)

// DHTMEM85 Configuration

#define	JPEG_DHTMEM85_DATA343			(0xFFu<<24)
#define	JPEG_DHTMEM85_DATA343_0			(0x1u<<24)
#define	JPEG_DHTMEM85_DATA342			(0xFFu<<16)
#define	JPEG_DHTMEM85_DATA342_0			(0x1u<<16)
#define	JPEG_DHTMEM85_DATA341			(0xFFu<<8)
#define	JPEG_DHTMEM85_DATA341_0			(0x1u<<8)
#define	JPEG_DHTMEM85_DATA340			(0xFFu<<0)
#define	JPEG_DHTMEM85_DATA340_0			(0x1u<<0)

// DHTMEM86 Configuration

#define	JPEG_DHTMEM86_DATA347			(0xFFu<<24)
#define	JPEG_DHTMEM86_DATA347_0			(0x1u<<24)
#define	JPEG_DHTMEM86_DATA346			(0xFFu<<16)
#define	JPEG_DHTMEM86_DATA346_0			(0x1u<<16)
#define	JPEG_DHTMEM86_DATA345			(0xFFu<<8)
#define	JPEG_DHTMEM86_DATA345_0			(0x1u<<8)
#define	JPEG_DHTMEM86_DATA344			(0xFFu<<0)
#define	JPEG_DHTMEM86_DATA344_0			(0x1u<<0)

// DHTMEM87 Configuration

#define	JPEG_DHTMEM87_DATA351			(0xFFu<<24)
#define	JPEG_DHTMEM87_DATA351_0			(0x1u<<24)
#define	JPEG_DHTMEM87_DATA350			(0xFFu<<16)
#define	JPEG_DHTMEM87_DATA350_0			(0x1u<<16)
#define	JPEG_DHTMEM87_DATA349			(0xFFu<<8)
#define	JPEG_DHTMEM87_DATA349_0			(0x1u<<8)
#define	JPEG_DHTMEM87_DATA348			(0xFFu<<0)
#define	JPEG_DHTMEM87_DATA348_0			(0x1u<<0)

// DHTMEM88 Configuration

#define	JPEG_DHTMEM88_DATA355			(0xFFu<<24)
#define	JPEG_DHTMEM88_DATA355_0			(0x1u<<24)
#define	JPEG_DHTMEM88_DATA354			(0xFFu<<16)
#define	JPEG_DHTMEM88_DATA354_0			(0x1u<<16)
#define	JPEG_DHTMEM88_DATA353			(0xFFu<<8)
#define	JPEG_DHTMEM88_DATA353_0			(0x1u<<8)
#define	JPEG_DHTMEM88_DATA352			(0xFFu<<0)
#define	JPEG_DHTMEM88_DATA352_0			(0x1u<<0)

// DHTMEM89 Configuration

#define	JPEG_DHTMEM89_DATA359			(0xFFu<<24)
#define	JPEG_DHTMEM89_DATA359_0			(0x1u<<24)
#define	JPEG_DHTMEM89_DATA358			(0xFFu<<16)
#define	JPEG_DHTMEM89_DATA358_0			(0x1u<<16)
#define	JPEG_DHTMEM89_DATA357			(0xFFu<<8)
#define	JPEG_DHTMEM89_DATA357_0			(0x1u<<8)
#define	JPEG_DHTMEM89_DATA356			(0xFFu<<0)
#define	JPEG_DHTMEM89_DATA356_0			(0x1u<<0)

// DHTMEM90 Configuration

#define	JPEG_DHTMEM90_DATA363			(0xFFu<<24)
#define	JPEG_DHTMEM90_DATA363_0			(0x1u<<24)
#define	JPEG_DHTMEM90_DATA362			(0xFFu<<16)
#define	JPEG_DHTMEM90_DATA362_0			(0x1u<<16)
#define	JPEG_DHTMEM90_DATA361			(0xFFu<<8)
#define	JPEG_DHTMEM90_DATA361_0			(0x1u<<8)
#define	JPEG_DHTMEM90_DATA360			(0xFFu<<0)
#define	JPEG_DHTMEM90_DATA360_0			(0x1u<<0)

// DHTMEM91 Configuration

#define	JPEG_DHTMEM91_DATA367			(0xFFu<<24)
#define	JPEG_DHTMEM91_DATA367_0			(0x1u<<24)
#define	JPEG_DHTMEM91_DATA366			(0xFFu<<16)
#define	JPEG_DHTMEM91_DATA366_0			(0x1u<<16)
#define	JPEG_DHTMEM91_DATA365			(0xFFu<<8)
#define	JPEG_DHTMEM91_DATA365_0			(0x1u<<8)
#define	JPEG_DHTMEM91_DATA364			(0xFFu<<0)
#define	JPEG_DHTMEM91_DATA364_0			(0x1u<<0)

// DHTMEM92 Configuration

#define	JPEG_DHTMEM92_DATA371			(0xFFu<<24)
#define	JPEG_DHTMEM92_DATA371_0			(0x1u<<24)
#define	JPEG_DHTMEM92_DATA370			(0xFFu<<16)
#define	JPEG_DHTMEM92_DATA370_0			(0x1u<<16)
#define	JPEG_DHTMEM92_DATA369			(0xFFu<<8)
#define	JPEG_DHTMEM92_DATA369_0			(0x1u<<8)
#define	JPEG_DHTMEM92_DATA368			(0xFFu<<0)
#define	JPEG_DHTMEM92_DATA368_0			(0x1u<<0)

// DHTMEM93 Configuration

#define	JPEG_DHTMEM93_DATA375			(0xFFu<<24)
#define	JPEG_DHTMEM93_DATA375_0			(0x1u<<24)
#define	JPEG_DHTMEM93_DATA374			(0xFFu<<16)
#define	JPEG_DHTMEM93_DATA374_0			(0x1u<<16)
#define	JPEG_DHTMEM93_DATA373			(0xFFu<<8)
#define	JPEG_DHTMEM93_DATA373_0			(0x1u<<8)
#define	JPEG_DHTMEM93_DATA372			(0xFFu<<0)
#define	JPEG_DHTMEM93_DATA372_0			(0x1u<<0)

// DHTMEM94 Configuration

#define	JPEG_DHTMEM94_DATA379			(0xFFu<<24)
#define	JPEG_DHTMEM94_DATA379_0			(0x1u<<24)
#define	JPEG_DHTMEM94_DATA378			(0xFFu<<16)
#define	JPEG_DHTMEM94_DATA378_0			(0x1u<<16)
#define	JPEG_DHTMEM94_DATA377			(0xFFu<<8)
#define	JPEG_DHTMEM94_DATA377_0			(0x1u<<8)
#define	JPEG_DHTMEM94_DATA376			(0xFFu<<0)
#define	JPEG_DHTMEM94_DATA376_0			(0x1u<<0)

// DHTMEM95 Configuration

#define	JPEG_DHTMEM95_DATA383			(0xFFu<<24)
#define	JPEG_DHTMEM95_DATA383_0			(0x1u<<24)
#define	JPEG_DHTMEM95_DATA382			(0xFFu<<16)
#define	JPEG_DHTMEM95_DATA382_0			(0x1u<<16)
#define	JPEG_DHTMEM95_DATA381			(0xFFu<<8)
#define	JPEG_DHTMEM95_DATA381_0			(0x1u<<8)
#define	JPEG_DHTMEM95_DATA380			(0xFFu<<0)
#define	JPEG_DHTMEM95_DATA380_0			(0x1u<<0)

// DHTMEM96 Configuration

#define	JPEG_DHTMEM96_DATA387			(0xFFu<<24)
#define	JPEG_DHTMEM96_DATA387_0			(0x1u<<24)
#define	JPEG_DHTMEM96_DATA386			(0xFFu<<16)
#define	JPEG_DHTMEM96_DATA386_0			(0x1u<<16)
#define	JPEG_DHTMEM96_DATA385			(0xFFu<<8)
#define	JPEG_DHTMEM96_DATA385_0			(0x1u<<8)
#define	JPEG_DHTMEM96_DATA384			(0xFFu<<0)
#define	JPEG_DHTMEM96_DATA384_0			(0x1u<<0)

// DHTMEM97 Configuration

#define	JPEG_DHTMEM97_DATA391			(0xFFu<<24)
#define	JPEG_DHTMEM97_DATA391_0			(0x1u<<24)
#define	JPEG_DHTMEM97_DATA390			(0xFFu<<16)
#define	JPEG_DHTMEM97_DATA390_0			(0x1u<<16)
#define	JPEG_DHTMEM97_DATA389			(0xFFu<<8)
#define	JPEG_DHTMEM97_DATA389_0			(0x1u<<8)
#define	JPEG_DHTMEM97_DATA388			(0xFFu<<0)
#define	JPEG_DHTMEM97_DATA388_0			(0x1u<<0)

// DHTMEM98 Configuration

#define	JPEG_DHTMEM98_DATA395			(0xFFu<<24)
#define	JPEG_DHTMEM98_DATA395_0			(0x1u<<24)
#define	JPEG_DHTMEM98_DATA394			(0xFFu<<16)
#define	JPEG_DHTMEM98_DATA394_0			(0x1u<<16)
#define	JPEG_DHTMEM98_DATA393			(0xFFu<<8)
#define	JPEG_DHTMEM98_DATA393_0			(0x1u<<8)
#define	JPEG_DHTMEM98_DATA392			(0xFFu<<0)
#define	JPEG_DHTMEM98_DATA392_0			(0x1u<<0)

// DHTMEM99 Configuration

#define	JPEG_DHTMEM99_DATA399			(0xFFu<<24)
#define	JPEG_DHTMEM99_DATA399_0			(0x1u<<24)
#define	JPEG_DHTMEM99_DATA398			(0xFFu<<16)
#define	JPEG_DHTMEM99_DATA398_0			(0x1u<<16)
#define	JPEG_DHTMEM99_DATA397			(0xFFu<<8)
#define	JPEG_DHTMEM99_DATA397_0			(0x1u<<8)
#define	JPEG_DHTMEM99_DATA396			(0xFFu<<0)
#define	JPEG_DHTMEM99_DATA396_0			(0x1u<<0)

// DHTMEM100 Configuration

#define	JPEG_DHTMEM100_DATA403			(0xFFu<<24)
#define	JPEG_DHTMEM100_DATA403_0		(0x1u<<24)
#define	JPEG_DHTMEM100_DATA402			(0xFFu<<16)
#define	JPEG_DHTMEM100_DATA402_0		(0x1u<<16)
#define	JPEG_DHTMEM100_DATA401			(0xFFu<<8)
#define	JPEG_DHTMEM100_DATA401_0		(0x1u<<8)
#define	JPEG_DHTMEM100_DATA400			(0xFFu<<0)
#define	JPEG_DHTMEM100_DATA400_0		(0x1u<<0)

// DHTMEM101 Configuration

#define	JPEG_DHTMEM101_DATA407			(0xFFu<<24)
#define	JPEG_DHTMEM101_DATA407_0		(0x1u<<24)
#define	JPEG_DHTMEM101_DATA406			(0xFFu<<16)
#define	JPEG_DHTMEM101_DATA406_0		(0x1u<<16)
#define	JPEG_DHTMEM101_DATA405			(0xFFu<<8)
#define	JPEG_DHTMEM101_DATA405_0		(0x1u<<8)
#define	JPEG_DHTMEM101_DATA404			(0xFFu<<0)
#define	JPEG_DHTMEM101_DATA404_0		(0x1u<<0)

// DHTMEM102 Configuration

#define	JPEG_DHTMEM102_DATA411			(0xFFu<<24)
#define	JPEG_DHTMEM102_DATA411_0		(0x1u<<24)
#define	JPEG_DHTMEM102_DATA410			(0xFFu<<16)
#define	JPEG_DHTMEM102_DATA410_0		(0x1u<<16)
#define	JPEG_DHTMEM102_DATA409			(0xFFu<<8)
#define	JPEG_DHTMEM102_DATA409_0		(0x1u<<8)
#define	JPEG_DHTMEM102_DATA408			(0xFFu<<0)
#define	JPEG_DHTMEM102_DATA408_0		(0x1u<<0)

// HUFFENC_AC0_0 Configuration

#define	JPEG_HUFFENC_AC0_0_HLEN1		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_0_HLEN1_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC0_0_HCODE1		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_0_HCODE1_0		(0x1u<<16)
#define	JPEG_HUFFENC_AC0_0_HLEN0		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_0_HLEN0_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC0_0_HCODE0		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_0_HCODE0_0		(0x1u<<0)

// HUFFENC_AC0_1 Configuration

#define	JPEG_HUFFENC_AC0_1_HLEN3		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_1_HLEN3_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC0_1_HCODE3		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_1_HCODE3_0		(0x1u<<16)
#define	JPEG_HUFFENC_AC0_1_HLEN2		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_1_HLEN2_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC0_1_HCODE2		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_1_HCODE2_0		(0x1u<<0)

// HUFFENC_AC0_2 Configuration

#define	JPEG_HUFFENC_AC0_2_HLEN5		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_2_HLEN5_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC0_2_HCODE5		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_2_HCODE5_0		(0x1u<<16)
#define	JPEG_HUFFENC_AC0_2_HLEN4		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_2_HLEN4_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC0_2_HCODE4		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_2_HCODE4_0		(0x1u<<0)

// HUFFENC_AC0_3 Configuration

#define	JPEG_HUFFENC_AC0_3_HLEN7		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_3_HLEN7_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC0_3_HCODE7		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_3_HCODE7_0		(0x1u<<16)
#define	JPEG_HUFFENC_AC0_3_HLEN6		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_3_HLEN6_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC0_3_HCODE6		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_3_HCODE6_0		(0x1u<<0)

// HUFFENC_AC0_4 Configuration

#define	JPEG_HUFFENC_AC0_4_HLEN9		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_4_HLEN9_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC0_4_HCODE9		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_4_HCODE9_0		(0x1u<<16)
#define	JPEG_HUFFENC_AC0_4_HLEN8		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_4_HLEN8_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC0_4_HCODE8		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_4_HCODE8_0		(0x1u<<0)

// HUFFENC_AC0_5 Configuration

#define	JPEG_HUFFENC_AC0_5_HLEN11		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_5_HLEN11_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC0_5_HCODE11		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_5_HCODE11_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_5_HLEN10		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_5_HLEN10_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC0_5_HCODE10		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_5_HCODE10_0	(0x1u<<0)

// HUFFENC_AC0_6 Configuration

#define	JPEG_HUFFENC_AC0_6_HLEN13		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_6_HLEN13_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC0_6_HCODE13		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_6_HCODE13_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_6_HLEN12		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_6_HLEN12_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC0_6_HCODE12		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_6_HCODE12_0	(0x1u<<0)

// HUFFENC_AC0_7 Configuration

#define	JPEG_HUFFENC_AC0_7_HLEN15		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_7_HLEN15_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC0_7_HCODE15		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_7_HCODE15_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_7_HLEN14		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_7_HLEN14_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC0_7_HCODE14		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_7_HCODE14_0	(0x1u<<0)

// HUFFENC_AC0_8 Configuration

#define	JPEG_HUFFENC_AC0_8_HLEN17		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_8_HLEN17_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC0_8_HCODE17		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_8_HCODE17_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_8_HLEN16		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_8_HLEN16_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC0_8_HCODE16		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_8_HCODE16_0	(0x1u<<0)

// HUFFENC_AC0_9 Configuration

#define	JPEG_HUFFENC_AC0_9_HLEN19		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_9_HLEN19_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC0_9_HCODE19		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_9_HCODE19_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_9_HLEN18		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_9_HLEN18_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC0_9_HCODE18		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_9_HCODE18_0	(0x1u<<0)

// HUFFENC_AC0_10 Configuration

#define	JPEG_HUFFENC_AC0_10_HLEN21		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_10_HLEN21_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_10_HCODE21		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_10_HCODE21_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_10_HLEN20		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_10_HLEN20_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_10_HCODE20		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_10_HCODE20_0	(0x1u<<0)

// HUFFENC_AC0_11 Configuration

#define	JPEG_HUFFENC_AC0_11_HLEN23		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_11_HLEN23_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_11_HCODE23		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_11_HCODE23_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_11_HLEN22		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_11_HLEN22_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_11_HCODE22		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_11_HCODE22_0	(0x1u<<0)

// HUFFENC_AC0_12 Configuration

#define	JPEG_HUFFENC_AC0_12_HLEN25		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_12_HLEN25_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_12_HCODE25		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_12_HCODE25_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_12_HLEN24		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_12_HLEN24_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_12_HCODE24		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_12_HCODE24_0	(0x1u<<0)

// HUFFENC_AC0_13 Configuration

#define	JPEG_HUFFENC_AC0_13_HLEN27		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_13_HLEN27_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_13_HCODE27		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_13_HCODE27_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_13_HLEN26		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_13_HLEN26_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_13_HCODE26		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_13_HCODE26_0	(0x1u<<0)

// HUFFENC_AC0_14 Configuration

#define	JPEG_HUFFENC_AC0_14_HLEN29		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_14_HLEN29_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_14_HCODE29		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_14_HCODE29_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_14_HLEN28		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_14_HLEN28_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_14_HCODE28		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_14_HCODE28_0	(0x1u<<0)

// HUFFENC_AC0_15 Configuration

#define	JPEG_HUFFENC_AC0_15_HLEN31		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_15_HLEN31_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_15_HCODE31		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_15_HCODE31_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_15_HLEN30		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_15_HLEN30_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_15_HCODE30		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_15_HCODE30_0	(0x1u<<0)

// HUFFENC_AC0_16 Configuration

#define	JPEG_HUFFENC_AC0_16_HLEN33		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_16_HLEN33_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_16_HCODE33		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_16_HCODE33_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_16_HLEN32		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_16_HLEN32_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_16_HCODE32		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_16_HCODE32_0	(0x1u<<0)

// HUFFENC_AC0_17 Configuration

#define	JPEG_HUFFENC_AC0_17_HLEN35		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_17_HLEN35_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_17_HCODE35		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_17_HCODE35_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_17_HLEN34		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_17_HLEN34_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_17_HCODE34		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_17_HCODE34_0	(0x1u<<0)

// HUFFENC_AC0_18 Configuration

#define	JPEG_HUFFENC_AC0_18_HLEN37		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_18_HLEN37_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_18_HCODE37		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_18_HCODE37_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_18_HLEN36		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_18_HLEN36_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_18_HCODE36		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_18_HCODE36_0	(0x1u<<0)

// HUFFENC_AC0_19 Configuration

#define	JPEG_HUFFENC_AC0_19_HLEN39		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_19_HLEN39_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_19_HCODE39		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_19_HCODE39_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_19_HLEN38		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_19_HLEN38_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_19_HCODE38		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_19_HCODE38_0	(0x1u<<0)

// HUFFENC_AC0_20 Configuration

#define	JPEG_HUFFENC_AC0_20_HLEN41		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_20_HLEN41_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_20_HCODE41		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_20_HCODE41_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_20_HLEN40		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_20_HLEN40_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_20_HCODE40		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_20_HCODE40_0	(0x1u<<0)

// HUFFENC_AC0_21 Configuration

#define	JPEG_HUFFENC_AC0_21_HLEN43		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_21_HLEN43_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_21_HCODE43		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_21_HCODE43_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_21_HLEN42		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_21_HLEN42_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_21_HCODE42		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_21_HCODE42_0	(0x1u<<0)

// HUFFENC_AC0_22 Configuration

#define	JPEG_HUFFENC_AC0_22_HLEN45		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_22_HLEN45_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_22_HCODE45		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_22_HCODE45_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_22_HLEN44		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_22_HLEN44_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_22_HCODE44		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_22_HCODE44_0	(0x1u<<0)

// HUFFENC_AC0_23 Configuration

#define	JPEG_HUFFENC_AC0_23_HLEN47		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_23_HLEN47_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_23_HCODE47		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_23_HCODE47_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_23_HLEN46		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_23_HLEN46_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_23_HCODE46		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_23_HCODE46_0	(0x1u<<0)

// HUFFENC_AC0_24 Configuration

#define	JPEG_HUFFENC_AC0_24_HLEN49		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_24_HLEN49_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_24_HCODE49		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_24_HCODE49_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_24_HLEN48		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_24_HLEN48_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_24_HCODE48		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_24_HCODE48_0	(0x1u<<0)

// HUFFENC_AC0_25 Configuration

#define	JPEG_HUFFENC_AC0_25_HLEN51		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_25_HLEN51_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_25_HCODE51		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_25_HCODE51_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_25_HLEN50		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_25_HLEN50_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_25_HCODE50		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_25_HCODE50_0	(0x1u<<0)

// HUFFENC_AC0_26 Configuration

#define	JPEG_HUFFENC_AC0_26_HLEN53		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_26_HLEN53_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_26_HCODE53		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_26_HCODE53_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_26_HLEN52		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_26_HLEN52_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_26_HCODE52		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_26_HCODE52_0	(0x1u<<0)

// HUFFENC_AC0_27 Configuration

#define	JPEG_HUFFENC_AC0_27_HLEN55		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_27_HLEN55_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_27_HCODE55		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_27_HCODE55_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_27_HLEN54		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_27_HLEN54_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_27_HCODE54		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_27_HCODE54_0	(0x1u<<0)

// HUFFENC_AC0_28 Configuration

#define	JPEG_HUFFENC_AC0_28_HLEN57		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_28_HLEN57_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_28_HCODE57		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_28_HCODE57_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_28_HLEN56		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_28_HLEN56_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_28_HCODE56		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_28_HCODE56_0	(0x1u<<0)

// HUFFENC_AC0_29 Configuration

#define	JPEG_HUFFENC_AC0_29_HLEN59		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_29_HLEN59_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_29_HCODE59		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_29_HCODE59_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_29_HLEN58		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_29_HLEN58_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_29_HCODE58		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_29_HCODE58_0	(0x1u<<0)

// HUFFENC_AC0_30 Configuration

#define	JPEG_HUFFENC_AC0_30_HLEN61		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_30_HLEN61_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_30_HCODE61		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_30_HCODE61_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_30_HLEN60		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_30_HLEN60_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_30_HCODE60		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_30_HCODE60_0	(0x1u<<0)

// HUFFENC_AC0_31 Configuration

#define	JPEG_HUFFENC_AC0_31_HLEN63		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_31_HLEN63_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_31_HCODE63		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_31_HCODE63_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_31_HLEN62		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_31_HLEN62_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_31_HCODE62		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_31_HCODE62_0	(0x1u<<0)

// HUFFENC_AC0_32 Configuration

#define	JPEG_HUFFENC_AC0_32_HLEN65		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_32_HLEN65_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_32_HCODE65		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_32_HCODE65_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_32_HLEN64		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_32_HLEN64_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_32_HCODE64		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_32_HCODE64_0	(0x1u<<0)

// HUFFENC_AC0_33 Configuration

#define	JPEG_HUFFENC_AC0_33_HLEN67		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_33_HLEN67_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_33_HCODE67		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_33_HCODE67_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_33_HLEN66		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_33_HLEN66_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_33_HCODE66		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_33_HCODE66_0	(0x1u<<0)

// HUFFENC_AC0_34 Configuration

#define	JPEG_HUFFENC_AC0_34_HLEN69		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_34_HLEN69_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_34_HCODE69		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_34_HCODE69_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_34_HLEN68		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_34_HLEN68_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_34_HCODE68		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_34_HCODE68_0	(0x1u<<0)

// HUFFENC_AC0_35 Configuration

#define	JPEG_HUFFENC_AC0_35_HLEN71		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_35_HLEN71_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_35_HCODE71		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_35_HCODE71_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_35_HLEN70		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_35_HLEN70_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_35_HCODE70		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_35_HCODE70_0	(0x1u<<0)

// HUFFENC_AC0_36 Configuration

#define	JPEG_HUFFENC_AC0_36_HLEN73		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_36_HLEN73_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_36_HCODE73		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_36_HCODE73_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_36_HLEN72		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_36_HLEN72_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_36_HCODE72		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_36_HCODE72_0	(0x1u<<0)

// HUFFENC_AC0_37 Configuration

#define	JPEG_HUFFENC_AC0_37_HLEN75		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_37_HLEN75_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_37_HCODE75		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_37_HCODE75_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_37_HLEN74		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_37_HLEN74_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_37_HCODE74		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_37_HCODE74_0	(0x1u<<0)

// HUFFENC_AC0_38 Configuration

#define	JPEG_HUFFENC_AC0_38_HLEN77		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_38_HLEN77_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_38_HCODE77		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_38_HCODE77_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_38_HLEN76		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_38_HLEN76_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_38_HCODE76		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_38_HCODE76_0	(0x1u<<0)

// HUFFENC_AC0_39 Configuration

#define	JPEG_HUFFENC_AC0_39_HLEN79		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_39_HLEN79_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_39_HCODE79		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_39_HCODE79_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_39_HLEN78		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_39_HLEN78_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_39_HCODE78		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_39_HCODE78_0	(0x1u<<0)

// HUFFENC_AC0_40 Configuration

#define	JPEG_HUFFENC_AC0_40_HLEN81		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_40_HLEN81_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_40_HCODE81		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_40_HCODE81_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_40_HLEN80		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_40_HLEN80_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_40_HCODE80		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_40_HCODE80_0	(0x1u<<0)

// HUFFENC_AC0_41 Configuration

#define	JPEG_HUFFENC_AC0_41_HLEN83		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_41_HLEN83_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_41_HCODE83		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_41_HCODE83_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_41_HLEN82		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_41_HLEN82_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_41_HCODE82		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_41_HCODE82_0	(0x1u<<0)

// HUFFENC_AC0_42 Configuration

#define	JPEG_HUFFENC_AC0_42_HLEN85		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_42_HLEN85_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_42_HCODE85		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_42_HCODE85_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_42_HLEN84		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_42_HLEN84_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_42_HCODE84		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_42_HCODE84_0	(0x1u<<0)

// HUFFENC_AC0_43 Configuration

#define	JPEG_HUFFENC_AC0_43_HLEN87		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_43_HLEN87_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_43_HCODE87		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_43_HCODE87_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_43_HLEN86		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_43_HLEN86_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_43_HCODE86		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_43_HCODE86_0	(0x1u<<0)

// HUFFENC_AC0_44 Configuration

#define	JPEG_HUFFENC_AC0_44_HLEN89		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_44_HLEN89_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_44_HCODE89		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_44_HCODE89_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_44_HLEN88		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_44_HLEN88_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_44_HCODE88		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_44_HCODE88_0	(0x1u<<0)

// HUFFENC_AC0_45 Configuration

#define	JPEG_HUFFENC_AC0_45_HLEN91		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_45_HLEN91_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_45_HCODE91		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_45_HCODE91_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_45_HLEN90		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_45_HLEN90_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_45_HCODE90		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_45_HCODE90_0	(0x1u<<0)

// HUFFENC_AC0_46 Configuration

#define	JPEG_HUFFENC_AC0_46_HLEN93		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_46_HLEN93_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_46_HCODE93		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_46_HCODE93_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_46_HLEN92		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_46_HLEN92_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_46_HCODE92		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_46_HCODE92_0	(0x1u<<0)

// HUFFENC_AC0_47 Configuration

#define	JPEG_HUFFENC_AC0_47_HLEN95		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_47_HLEN95_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_47_HCODE95		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_47_HCODE95_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_47_HLEN94		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_47_HLEN94_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_47_HCODE94		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_47_HCODE94_0	(0x1u<<0)

// HUFFENC_AC0_48 Configuration

#define	JPEG_HUFFENC_AC0_48_HLEN97		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_48_HLEN97_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_48_HCODE97		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_48_HCODE97_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_48_HLEN96		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_48_HLEN96_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_48_HCODE96		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_48_HCODE96_0	(0x1u<<0)

// HUFFENC_AC0_49 Configuration

#define	JPEG_HUFFENC_AC0_49_HLEN99		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_49_HLEN99_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_49_HCODE99		(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_49_HCODE99_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_49_HLEN98		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_49_HLEN98_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_49_HCODE98		(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_49_HCODE98_0	(0x1u<<0)

// HUFFENC_AC0_50 Configuration

#define	JPEG_HUFFENC_AC0_50_HLEN101		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_50_HLEN101_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_50_HCODE101	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_50_HCODE101_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_50_HLEN100		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_50_HLEN100_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_50_HCODE100	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_50_HCODE100_0	(0x1u<<0)

// HUFFENC_AC0_51 Configuration

#define	JPEG_HUFFENC_AC0_51_HLEN103		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_51_HLEN103_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_51_HCODE103	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_51_HCODE103_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_51_HLEN102		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_51_HLEN102_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_51_HCODE102	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_51_HCODE102_0	(0x1u<<0)

// HUFFENC_AC0_52 Configuration

#define	JPEG_HUFFENC_AC0_52_HLEN105		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_52_HLEN105_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_52_HCODE105	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_52_HCODE105_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_52_HLEN104		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_52_HLEN104_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_52_HCODE104	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_52_HCODE104_0	(0x1u<<0)

// HUFFENC_AC0_53 Configuration

#define	JPEG_HUFFENC_AC0_53_HLEN107		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_53_HLEN107_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_53_HCODE107	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_53_HCODE107_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_53_HLEN106		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_53_HLEN106_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_53_HCODE106	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_53_HCODE106_0	(0x1u<<0)

// HUFFENC_AC0_54 Configuration

#define	JPEG_HUFFENC_AC0_54_HLEN109		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_54_HLEN109_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_54_HCODE109	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_54_HCODE109_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_54_HLEN108		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_54_HLEN108_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_54_HCODE108	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_54_HCODE108_0	(0x1u<<0)

// HUFFENC_AC0_55 Configuration

#define	JPEG_HUFFENC_AC0_55_HLEN111		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_55_HLEN111_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_55_HCODE111	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_55_HCODE111_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_55_HLEN110		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_55_HLEN110_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_55_HCODE110	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_55_HCODE110_0	(0x1u<<0)

// HUFFENC_AC0_56 Configuration

#define	JPEG_HUFFENC_AC0_56_HLEN113		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_56_HLEN113_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_56_HCODE113	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_56_HCODE113_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_56_HLEN112		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_56_HLEN112_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_56_HCODE112	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_56_HCODE112_0	(0x1u<<0)

// HUFFENC_AC0_57 Configuration

#define	JPEG_HUFFENC_AC0_57_HLEN115		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_57_HLEN115_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_57_HCODE115	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_57_HCODE115_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_57_HLEN114		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_57_HLEN114_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_57_HCODE114	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_57_HCODE114_0	(0x1u<<0)

// HUFFENC_AC0_58 Configuration

#define	JPEG_HUFFENC_AC0_58_HLEN117		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_58_HLEN117_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_58_HCODE117	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_58_HCODE117_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_58_HLEN116		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_58_HLEN116_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_58_HCODE116	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_58_HCODE116_0	(0x1u<<0)

// HUFFENC_AC0_59 Configuration

#define	JPEG_HUFFENC_AC0_59_HLEN119		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_59_HLEN119_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_59_HCODE119	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_59_HCODE119_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_59_HLEN118		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_59_HLEN118_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_59_HCODE118	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_59_HCODE118_0	(0x1u<<0)

// HUFFENC_AC0_60 Configuration

#define	JPEG_HUFFENC_AC0_60_HLEN121		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_60_HLEN121_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_60_HCODE121	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_60_HCODE121_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_60_HLEN120		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_60_HLEN120_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_60_HCODE120	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_60_HCODE120_0	(0x1u<<0)

// HUFFENC_AC0_61 Configuration

#define	JPEG_HUFFENC_AC0_61_HLEN123		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_61_HLEN123_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_61_HCODE123	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_61_HCODE123_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_61_HLEN122		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_61_HLEN122_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_61_HCODE122	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_61_HCODE122_0	(0x1u<<0)

// HUFFENC_AC0_62 Configuration

#define	JPEG_HUFFENC_AC0_62_HLEN125		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_62_HLEN125_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_62_HCODE125	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_62_HCODE125_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_62_HLEN124		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_62_HLEN124_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_62_HCODE124	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_62_HCODE124_0	(0x1u<<0)

// HUFFENC_AC0_63 Configuration

#define	JPEG_HUFFENC_AC0_63_HLEN127		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_63_HLEN127_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_63_HCODE127	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_63_HCODE127_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_63_HLEN126		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_63_HLEN126_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_63_HCODE126	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_63_HCODE126_0	(0x1u<<0)

// HUFFENC_AC0_64 Configuration

#define	JPEG_HUFFENC_AC0_64_HLEN129		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_64_HLEN129_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_64_HCODE129	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_64_HCODE129_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_64_HLEN128		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_64_HLEN128_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_64_HCODE128	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_64_HCODE128_0	(0x1u<<0)

// HUFFENC_AC0_65 Configuration

#define	JPEG_HUFFENC_AC0_65_HLEN131		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_65_HLEN131_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_65_HCODE131	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_65_HCODE131_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_65_HLEN130		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_65_HLEN130_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_65_HCODE130	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_65_HCODE130_0	(0x1u<<0)

// HUFFENC_AC0_66 Configuration

#define	JPEG_HUFFENC_AC0_66_HLEN133		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_66_HLEN133_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_66_HCODE133	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_66_HCODE133_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_66_HLEN132		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_66_HLEN132_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_66_HCODE132	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_66_HCODE132_0	(0x1u<<0)

// HUFFENC_AC0_67 Configuration

#define	JPEG_HUFFENC_AC0_67_HLEN135		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_67_HLEN135_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_67_HCODE135	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_67_HCODE135_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_67_HLEN134		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_67_HLEN134_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_67_HCODE134	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_67_HCODE134_0	(0x1u<<0)

// HUFFENC_AC0_68 Configuration

#define	JPEG_HUFFENC_AC0_68_HLEN137		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_68_HLEN137_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_68_HCODE137	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_68_HCODE137_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_68_HLEN136		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_68_HLEN136_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_68_HCODE136	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_68_HCODE136_0	(0x1u<<0)

// HUFFENC_AC0_69 Configuration

#define	JPEG_HUFFENC_AC0_69_HLEN139		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_69_HLEN139_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_69_HCODE139	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_69_HCODE139_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_69_HLEN138		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_69_HLEN138_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_69_HCODE138	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_69_HCODE138_0	(0x1u<<0)

// HUFFENC_AC0_70 Configuration

#define	JPEG_HUFFENC_AC0_70_HLEN141		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_70_HLEN141_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_70_HCODE141	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_70_HCODE141_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_70_HLEN140		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_70_HLEN140_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_70_HCODE140	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_70_HCODE140_0	(0x1u<<0)

// HUFFENC_AC0_71 Configuration

#define	JPEG_HUFFENC_AC0_71_HLEN143		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_71_HLEN143_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_71_HCODE143	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_71_HCODE143_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_71_HLEN142		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_71_HLEN142_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_71_HCODE142	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_71_HCODE142_0	(0x1u<<0)

// HUFFENC_AC0_72 Configuration

#define	JPEG_HUFFENC_AC0_72_HLEN145		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_72_HLEN145_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_72_HCODE145	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_72_HCODE145_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_72_HLEN144		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_72_HLEN144_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_72_HCODE144	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_72_HCODE144_0	(0x1u<<0)

// HUFFENC_AC0_73 Configuration

#define	JPEG_HUFFENC_AC0_73_HLEN147		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_73_HLEN147_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_73_HCODE147	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_73_HCODE147_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_73_HLEN146		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_73_HLEN146_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_73_HCODE146	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_73_HCODE146_0	(0x1u<<0)

// HUFFENC_AC0_74 Configuration

#define	JPEG_HUFFENC_AC0_74_HLEN149		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_74_HLEN149_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_74_HCODE149	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_74_HCODE149_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_74_HLEN148		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_74_HLEN148_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_74_HCODE148	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_74_HCODE148_0	(0x1u<<0)

// HUFFENC_AC0_75 Configuration

#define	JPEG_HUFFENC_AC0_75_HLEN151		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_75_HLEN151_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_75_HCODE151	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_75_HCODE151_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_75_HLEN150		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_75_HLEN150_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_75_HCODE150	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_75_HCODE150_0	(0x1u<<0)

// HUFFENC_AC0_76 Configuration

#define	JPEG_HUFFENC_AC0_76_HLEN153		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_76_HLEN153_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_76_HCODE153	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_76_HCODE153_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_76_HLEN152		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_76_HLEN152_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_76_HCODE152	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_76_HCODE152_0	(0x1u<<0)

// HUFFENC_AC0_77 Configuration

#define	JPEG_HUFFENC_AC0_77_HLEN155		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_77_HLEN155_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_77_HCODE155	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_77_HCODE155_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_77_HLEN154		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_77_HLEN154_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_77_HCODE154	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_77_HCODE154_0	(0x1u<<0)

// HUFFENC_AC0_78 Configuration

#define	JPEG_HUFFENC_AC0_78_HLEN157		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_78_HLEN157_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_78_HCODE157	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_78_HCODE157_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_78_HLEN156		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_78_HLEN156_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_78_HCODE156	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_78_HCODE156_0	(0x1u<<0)

// HUFFENC_AC0_79 Configuration

#define	JPEG_HUFFENC_AC0_79_HLEN159		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_79_HLEN159_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_79_HCODE159	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_79_HCODE159_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_79_HLEN158		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_79_HLEN158_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_79_HCODE158	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_79_HCODE158_0	(0x1u<<0)

// HUFFENC_AC0_80 Configuration

#define	JPEG_HUFFENC_AC0_80_HLEN161		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_80_HLEN161_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_80_HCODE161	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_80_HCODE161_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_80_HLEN160		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_80_HLEN160_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_80_HCODE160	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_80_HCODE160_0	(0x1u<<0)

// HUFFENC_AC0_81 Configuration

#define	JPEG_HUFFENC_AC0_81_HLEN163		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_81_HLEN163_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_81_HCODE163	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_81_HCODE163_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_81_HLEN162		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_81_HLEN162_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_81_HCODE162	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_81_HCODE162_0	(0x1u<<0)

// HUFFENC_AC0_82 Configuration

#define	JPEG_HUFFENC_AC0_82_HLEN165		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_82_HLEN165_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_82_HCODE165	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_82_HCODE165_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_82_HLEN164		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_82_HLEN164_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_82_HCODE164	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_82_HCODE164_0	(0x1u<<0)

// HUFFENC_AC0_83 Configuration

#define	JPEG_HUFFENC_AC0_83_HLEN167		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_83_HLEN167_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_83_HCODE167	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_83_HCODE167_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_83_HLEN166		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_83_HLEN166_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_83_HCODE166	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_83_HCODE166_0	(0x1u<<0)

// HUFFENC_AC0_84 Configuration

#define	JPEG_HUFFENC_AC0_84_HLEN169		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_84_HLEN169_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_84_HCODE169	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_84_HCODE169_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_84_HLEN168		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_84_HLEN168_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_84_HCODE168	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_84_HCODE168_0	(0x1u<<0)

// HUFFENC_AC0_85 Configuration

#define	JPEG_HUFFENC_AC0_85_HLEN171		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_85_HLEN171_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_85_HCODE171	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_85_HCODE171_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_85_HLEN170		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_85_HLEN170_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_85_HCODE170	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_85_HCODE170_0	(0x1u<<0)

// HUFFENC_AC0_86 Configuration

#define	JPEG_HUFFENC_AC0_86_HLEN173		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_86_HLEN173_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_86_HCODE173	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_86_HCODE173_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_86_HLEN172		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_86_HLEN172_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_86_HCODE172	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_86_HCODE172_0	(0x1u<<0)

// HUFFENC_AC0_87 Configuration

#define	JPEG_HUFFENC_AC0_87_HLEN175		(0xFu<<24)
#define	JPEG_HUFFENC_AC0_87_HLEN175_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC0_87_HCODE175	(0xFFu<<16)
#define	JPEG_HUFFENC_AC0_87_HCODE175_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC0_87_HLEN174		(0xFu<<8)
#define	JPEG_HUFFENC_AC0_87_HLEN174_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC0_87_HCODE174	(0xFFu<<0)
#define	JPEG_HUFFENC_AC0_87_HCODE174_0	(0x1u<<0)

// HUFFENC_AC1_0 Configuration

#define	JPEG_HUFFENC_AC1_0_HLEN1		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_0_HLEN1_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC1_0_HCODE1		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_0_HCODE1_0		(0x1u<<16)
#define	JPEG_HUFFENC_AC1_0_HLEN0		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_0_HLEN0_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC1_0_HCODE0		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_0_HCODE0_0		(0x1u<<0)

// HUFFENC_AC1_1 Configuration

#define	JPEG_HUFFENC_AC1_1_HLEN3		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_1_HLEN3_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC1_1_HCODE3		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_1_HCODE3_0		(0x1u<<16)
#define	JPEG_HUFFENC_AC1_1_HLEN2		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_1_HLEN2_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC1_1_HCODE2		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_1_HCODE2_0		(0x1u<<0)

// HUFFENC_AC1_2 Configuration

#define	JPEG_HUFFENC_AC1_2_HLEN5		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_2_HLEN5_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC1_2_HCODE5		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_2_HCODE5_0		(0x1u<<16)
#define	JPEG_HUFFENC_AC1_2_HLEN4		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_2_HLEN4_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC1_2_HCODE4		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_2_HCODE4_0		(0x1u<<0)

// HUFFENC_AC1_3 Configuration

#define	JPEG_HUFFENC_AC1_3_HLEN7		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_3_HLEN7_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC1_3_HCODE7		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_3_HCODE7_0		(0x1u<<16)
#define	JPEG_HUFFENC_AC1_3_HLEN6		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_3_HLEN6_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC1_3_HCODE6		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_3_HCODE6_0		(0x1u<<0)

// HUFFENC_AC1_4 Configuration

#define	JPEG_HUFFENC_AC1_4_HLEN9		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_4_HLEN9_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC1_4_HCODE9		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_4_HCODE9_0		(0x1u<<16)
#define	JPEG_HUFFENC_AC1_4_HLEN8		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_4_HLEN8_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC1_4_HCODE8		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_4_HCODE8_0		(0x1u<<0)

// HUFFENC_AC1_5 Configuration

#define	JPEG_HUFFENC_AC1_5_HLEN11		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_5_HLEN11_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC1_5_HCODE11		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_5_HCODE11_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_5_HLEN10		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_5_HLEN10_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC1_5_HCODE10		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_5_HCODE10_0	(0x1u<<0)

// HUFFENC_AC1_6 Configuration

#define	JPEG_HUFFENC_AC1_6_HLEN13		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_6_HLEN13_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC1_6_HCODE13		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_6_HCODE13_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_6_HLEN12		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_6_HLEN12_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC1_6_HCODE12		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_6_HCODE12_0	(0x1u<<0)

// HUFFENC_AC1_7 Configuration

#define	JPEG_HUFFENC_AC1_7_HLEN15		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_7_HLEN15_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC1_7_HCODE15		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_7_HCODE15_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_7_HLEN14		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_7_HLEN14_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC1_7_HCODE14		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_7_HCODE14_0	(0x1u<<0)

// HUFFENC_AC1_8 Configuration

#define	JPEG_HUFFENC_AC1_8_HLEN17		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_8_HLEN17_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC1_8_HCODE17		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_8_HCODE17_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_8_HLEN16		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_8_HLEN16_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC1_8_HCODE16		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_8_HCODE16_0	(0x1u<<0)

// HUFFENC_AC1_9 Configuration

#define	JPEG_HUFFENC_AC1_9_HLEN19		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_9_HLEN19_0		(0x1u<<24)
#define	JPEG_HUFFENC_AC1_9_HCODE19		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_9_HCODE19_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_9_HLEN18		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_9_HLEN18_0		(0x1u<<8)
#define	JPEG_HUFFENC_AC1_9_HCODE18		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_9_HCODE18_0	(0x1u<<0)

// HUFFENC_AC1_10 Configuration

#define	JPEG_HUFFENC_AC1_10_HLEN21		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_10_HLEN21_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_10_HCODE21		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_10_HCODE21_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_10_HLEN20		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_10_HLEN20_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_10_HCODE20		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_10_HCODE20_0	(0x1u<<0)

// HUFFENC_AC1_11 Configuration

#define	JPEG_HUFFENC_AC1_11_HLEN23		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_11_HLEN23_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_11_HCODE23		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_11_HCODE23_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_11_HLEN22		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_11_HLEN22_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_11_HCODE22		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_11_HCODE22_0	(0x1u<<0)

// HUFFENC_AC1_12 Configuration

#define	JPEG_HUFFENC_AC1_12_HLEN25		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_12_HLEN25_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_12_HCODE25		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_12_HCODE25_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_12_HLEN24		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_12_HLEN24_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_12_HCODE24		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_12_HCODE24_0	(0x1u<<0)

// HUFFENC_AC1_13 Configuration

#define	JPEG_HUFFENC_AC1_13_HLEN27		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_13_HLEN27_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_13_HCODE27		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_13_HCODE27_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_13_HLEN26		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_13_HLEN26_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_13_HCODE26		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_13_HCODE26_0	(0x1u<<0)

// HUFFENC_AC1_14 Configuration

#define	JPEG_HUFFENC_AC1_14_HLEN29		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_14_HLEN29_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_14_HCODE29		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_14_HCODE29_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_14_HLEN28		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_14_HLEN28_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_14_HCODE28		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_14_HCODE28_0	(0x1u<<0)

// HUFFENC_AC1_15 Configuration

#define	JPEG_HUFFENC_AC1_15_HLEN31		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_15_HLEN31_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_15_HCODE31		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_15_HCODE31_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_15_HLEN30		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_15_HLEN30_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_15_HCODE30		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_15_HCODE30_0	(0x1u<<0)

// HUFFENC_AC1_16 Configuration

#define	JPEG_HUFFENC_AC1_16_HLEN33		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_16_HLEN33_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_16_HCODE33		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_16_HCODE33_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_16_HLEN32		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_16_HLEN32_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_16_HCODE32		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_16_HCODE32_0	(0x1u<<0)

// HUFFENC_AC1_17 Configuration

#define	JPEG_HUFFENC_AC1_17_HLEN35		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_17_HLEN35_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_17_HCODE35		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_17_HCODE35_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_17_HLEN34		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_17_HLEN34_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_17_HCODE34		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_17_HCODE34_0	(0x1u<<0)

// HUFFENC_AC1_18 Configuration

#define	JPEG_HUFFENC_AC1_18_HLEN37		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_18_HLEN37_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_18_HCODE37		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_18_HCODE37_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_18_HLEN36		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_18_HLEN36_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_18_HCODE36		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_18_HCODE36_0	(0x1u<<0)

// HUFFENC_AC1_19 Configuration

#define	JPEG_HUFFENC_AC1_19_HLEN39		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_19_HLEN39_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_19_HCODE39		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_19_HCODE39_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_19_HLEN38		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_19_HLEN38_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_19_HCODE38		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_19_HCODE38_0	(0x1u<<0)

// HUFFENC_AC1_20 Configuration

#define	JPEG_HUFFENC_AC1_20_HLEN41		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_20_HLEN41_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_20_HCODE41		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_20_HCODE41_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_20_HLEN40		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_20_HLEN40_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_20_HCODE40		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_20_HCODE40_0	(0x1u<<0)

// HUFFENC_AC1_21 Configuration

#define	JPEG_HUFFENC_AC1_21_HLEN43		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_21_HLEN43_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_21_HCODE43		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_21_HCODE43_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_21_HLEN42		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_21_HLEN42_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_21_HCODE42		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_21_HCODE42_0	(0x1u<<0)

// HUFFENC_AC1_22 Configuration

#define	JPEG_HUFFENC_AC1_22_HLEN45		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_22_HLEN45_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_22_HCODE45		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_22_HCODE45_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_22_HLEN44		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_22_HLEN44_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_22_HCODE44		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_22_HCODE44_0	(0x1u<<0)

// HUFFENC_AC1_23 Configuration

#define	JPEG_HUFFENC_AC1_23_HLEN47		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_23_HLEN47_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_23_HCODE47		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_23_HCODE47_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_23_HLEN46		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_23_HLEN46_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_23_HCODE46		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_23_HCODE46_0	(0x1u<<0)

// HUFFENC_AC1_24 Configuration

#define	JPEG_HUFFENC_AC1_24_HLEN49		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_24_HLEN49_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_24_HCODE49		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_24_HCODE49_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_24_HLEN48		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_24_HLEN48_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_24_HCODE48		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_24_HCODE48_0	(0x1u<<0)

// HUFFENC_AC1_25 Configuration

#define	JPEG_HUFFENC_AC1_25_HLEN51		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_25_HLEN51_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_25_HCODE51		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_25_HCODE51_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_25_HLEN50		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_25_HLEN50_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_25_HCODE50		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_25_HCODE50_0	(0x1u<<0)

// HUFFENC_AC1_26 Configuration

#define	JPEG_HUFFENC_AC1_26_HLEN53		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_26_HLEN53_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_26_HCODE53		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_26_HCODE53_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_26_HLEN52		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_26_HLEN52_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_26_HCODE52		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_26_HCODE52_0	(0x1u<<0)

// HUFFENC_AC1_27 Configuration

#define	JPEG_HUFFENC_AC1_27_HLEN55		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_27_HLEN55_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_27_HCODE55		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_27_HCODE55_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_27_HLEN54		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_27_HLEN54_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_27_HCODE54		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_27_HCODE54_0	(0x1u<<0)

// HUFFENC_AC1_28 Configuration

#define	JPEG_HUFFENC_AC1_28_HLEN57		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_28_HLEN57_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_28_HCODE57		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_28_HCODE57_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_28_HLEN56		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_28_HLEN56_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_28_HCODE56		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_28_HCODE56_0	(0x1u<<0)

// HUFFENC_AC1_29 Configuration

#define	JPEG_HUFFENC_AC1_29_HLEN59		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_29_HLEN59_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_29_HCODE59		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_29_HCODE59_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_29_HLEN58		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_29_HLEN58_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_29_HCODE58		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_29_HCODE58_0	(0x1u<<0)

// HUFFENC_AC1_30 Configuration

#define	JPEG_HUFFENC_AC1_30_HLEN61		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_30_HLEN61_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_30_HCODE61		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_30_HCODE61_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_30_HLEN60		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_30_HLEN60_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_30_HCODE60		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_30_HCODE60_0	(0x1u<<0)

// HUFFENC_AC1_31 Configuration

#define	JPEG_HUFFENC_AC1_31_HLEN63		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_31_HLEN63_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_31_HCODE63		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_31_HCODE63_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_31_HLEN62		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_31_HLEN62_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_31_HCODE62		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_31_HCODE62_0	(0x1u<<0)

// HUFFENC_AC1_32 Configuration

#define	JPEG_HUFFENC_AC1_32_HLEN65		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_32_HLEN65_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_32_HCODE65		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_32_HCODE65_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_32_HLEN64		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_32_HLEN64_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_32_HCODE64		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_32_HCODE64_0	(0x1u<<0)

// HUFFENC_AC1_33 Configuration

#define	JPEG_HUFFENC_AC1_33_HLEN67		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_33_HLEN67_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_33_HCODE67		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_33_HCODE67_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_33_HLEN66		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_33_HLEN66_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_33_HCODE66		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_33_HCODE66_0	(0x1u<<0)

// HUFFENC_AC1_34 Configuration

#define	JPEG_HUFFENC_AC1_34_HLEN69		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_34_HLEN69_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_34_HCODE69		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_34_HCODE69_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_34_HLEN68		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_34_HLEN68_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_34_HCODE68		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_34_HCODE68_0	(0x1u<<0)

// HUFFENC_AC1_35 Configuration

#define	JPEG_HUFFENC_AC1_35_HLEN71		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_35_HLEN71_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_35_HCODE71		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_35_HCODE71_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_35_HLEN70		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_35_HLEN70_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_35_HCODE70		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_35_HCODE70_0	(0x1u<<0)

// HUFFENC_AC1_36 Configuration

#define	JPEG_HUFFENC_AC1_36_HLEN73		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_36_HLEN73_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_36_HCODE73		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_36_HCODE73_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_36_HLEN72		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_36_HLEN72_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_36_HCODE72		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_36_HCODE72_0	(0x1u<<0)

// HUFFENC_AC1_37 Configuration

#define	JPEG_HUFFENC_AC1_37_HLEN75		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_37_HLEN75_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_37_HCODE75		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_37_HCODE75_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_37_HLEN74		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_37_HLEN74_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_37_HCODE74		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_37_HCODE74_0	(0x1u<<0)

// HUFFENC_AC1_38 Configuration

#define	JPEG_HUFFENC_AC1_38_HLEN77		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_38_HLEN77_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_38_HCODE77		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_38_HCODE77_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_38_HLEN76		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_38_HLEN76_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_38_HCODE76		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_38_HCODE76_0	(0x1u<<0)

// HUFFENC_AC1_39 Configuration

#define	JPEG_HUFFENC_AC1_39_HLEN79		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_39_HLEN79_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_39_HCODE79		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_39_HCODE79_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_39_HLEN78		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_39_HLEN78_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_39_HCODE78		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_39_HCODE78_0	(0x1u<<0)

// HUFFENC_AC1_40 Configuration

#define	JPEG_HUFFENC_AC1_40_HLEN81		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_40_HLEN81_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_40_HCODE81		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_40_HCODE81_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_40_HLEN80		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_40_HLEN80_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_40_HCODE80		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_40_HCODE80_0	(0x1u<<0)

// HUFFENC_AC1_41 Configuration

#define	JPEG_HUFFENC_AC1_41_HLEN83		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_41_HLEN83_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_41_HCODE83		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_41_HCODE83_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_41_HLEN82		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_41_HLEN82_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_41_HCODE82		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_41_HCODE82_0	(0x1u<<0)

// HUFFENC_AC1_42 Configuration

#define	JPEG_HUFFENC_AC1_42_HLEN85		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_42_HLEN85_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_42_HCODE85		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_42_HCODE85_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_42_HLEN84		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_42_HLEN84_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_42_HCODE84		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_42_HCODE84_0	(0x1u<<0)

// HUFFENC_AC1_43 Configuration

#define	JPEG_HUFFENC_AC1_43_HLEN87		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_43_HLEN87_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_43_HCODE87		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_43_HCODE87_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_43_HLEN86		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_43_HLEN86_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_43_HCODE86		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_43_HCODE86_0	(0x1u<<0)

// HUFFENC_AC1_44 Configuration

#define	JPEG_HUFFENC_AC1_44_HLEN89		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_44_HLEN89_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_44_HCODE89		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_44_HCODE89_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_44_HLEN88		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_44_HLEN88_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_44_HCODE88		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_44_HCODE88_0	(0x1u<<0)

// HUFFENC_AC1_45 Configuration

#define	JPEG_HUFFENC_AC1_45_HLEN91		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_45_HLEN91_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_45_HCODE91		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_45_HCODE91_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_45_HLEN90		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_45_HLEN90_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_45_HCODE90		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_45_HCODE90_0	(0x1u<<0)

// HUFFENC_AC1_46 Configuration

#define	JPEG_HUFFENC_AC1_46_HLEN93		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_46_HLEN93_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_46_HCODE93		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_46_HCODE93_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_46_HLEN92		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_46_HLEN92_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_46_HCODE92		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_46_HCODE92_0	(0x1u<<0)

// HUFFENC_AC1_47 Configuration

#define	JPEG_HUFFENC_AC1_47_HLEN95		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_47_HLEN95_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_47_HCODE95		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_47_HCODE95_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_47_HLEN94		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_47_HLEN94_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_47_HCODE94		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_47_HCODE94_0	(0x1u<<0)

// HUFFENC_AC1_48 Configuration

#define	JPEG_HUFFENC_AC1_48_HLEN97		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_48_HLEN97_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_48_HCODE97		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_48_HCODE97_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_48_HLEN96		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_48_HLEN96_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_48_HCODE96		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_48_HCODE96_0	(0x1u<<0)

// HUFFENC_AC1_49 Configuration

#define	JPEG_HUFFENC_AC1_49_HLEN99		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_49_HLEN99_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_49_HCODE99		(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_49_HCODE99_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_49_HLEN98		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_49_HLEN98_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_49_HCODE98		(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_49_HCODE98_0	(0x1u<<0)

// HUFFENC_AC1_50 Configuration

#define	JPEG_HUFFENC_AC1_50_HLEN101		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_50_HLEN101_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_50_HCODE101	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_50_HCODE101_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_50_HLEN100		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_50_HLEN100_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_50_HCODE100	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_50_HCODE100_0	(0x1u<<0)

// HUFFENC_AC1_51 Configuration

#define	JPEG_HUFFENC_AC1_51_HLEN103		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_51_HLEN103_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_51_HCODE103	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_51_HCODE103_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_51_HLEN102		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_51_HLEN102_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_51_HCODE102	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_51_HCODE102_0	(0x1u<<0)

// HUFFENC_AC1_52 Configuration

#define	JPEG_HUFFENC_AC1_52_HLEN105		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_52_HLEN105_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_52_HCODE105	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_52_HCODE105_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_52_HLEN104		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_52_HLEN104_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_52_HCODE104	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_52_HCODE104_0	(0x1u<<0)

// HUFFENC_AC1_53 Configuration

#define	JPEG_HUFFENC_AC1_53_HLEN107		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_53_HLEN107_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_53_HCODE107	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_53_HCODE107_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_53_HLEN106		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_53_HLEN106_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_53_HCODE106	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_53_HCODE106_0	(0x1u<<0)

// HUFFENC_AC1_54 Configuration

#define	JPEG_HUFFENC_AC1_54_HLEN109		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_54_HLEN109_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_54_HCODE109	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_54_HCODE109_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_54_HLEN108		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_54_HLEN108_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_54_HCODE108	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_54_HCODE108_0	(0x1u<<0)

// HUFFENC_AC1_55 Configuration

#define	JPEG_HUFFENC_AC1_55_HLEN111		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_55_HLEN111_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_55_HCODE111	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_55_HCODE111_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_55_HLEN110		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_55_HLEN110_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_55_HCODE110	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_55_HCODE110_0	(0x1u<<0)

// HUFFENC_AC1_56 Configuration

#define	JPEG_HUFFENC_AC1_56_HLEN113		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_56_HLEN113_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_56_HCODE113	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_56_HCODE113_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_56_HLEN112		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_56_HLEN112_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_56_HCODE112	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_56_HCODE112_0	(0x1u<<0)

// HUFFENC_AC1_57 Configuration

#define	JPEG_HUFFENC_AC1_57_HLEN115		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_57_HLEN115_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_57_HCODE115	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_57_HCODE115_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_57_HLEN114		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_57_HLEN114_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_57_HCODE114	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_57_HCODE114_0	(0x1u<<0)

// HUFFENC_AC1_58 Configuration

#define	JPEG_HUFFENC_AC1_58_HLEN117		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_58_HLEN117_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_58_HCODE117	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_58_HCODE117_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_58_HLEN116		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_58_HLEN116_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_58_HCODE116	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_58_HCODE116_0	(0x1u<<0)

// HUFFENC_AC1_59 Configuration

#define	JPEG_HUFFENC_AC1_59_HLEN119		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_59_HLEN119_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_59_HCODE119	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_59_HCODE119_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_59_HLEN118		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_59_HLEN118_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_59_HCODE118	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_59_HCODE118_0	(0x1u<<0)

// HUFFENC_AC1_60 Configuration

#define	JPEG_HUFFENC_AC1_60_HLEN121		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_60_HLEN121_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_60_HCODE121	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_60_HCODE121_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_60_HLEN120		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_60_HLEN120_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_60_HCODE120	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_60_HCODE120_0	(0x1u<<0)

// HUFFENC_AC1_61 Configuration

#define	JPEG_HUFFENC_AC1_61_HLEN123		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_61_HLEN123_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_61_HCODE123	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_61_HCODE123_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_61_HLEN122		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_61_HLEN122_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_61_HCODE122	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_61_HCODE122_0	(0x1u<<0)

// HUFFENC_AC1_62 Configuration

#define	JPEG_HUFFENC_AC1_62_HLEN125		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_62_HLEN125_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_62_HCODE125	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_62_HCODE125_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_62_HLEN124		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_62_HLEN124_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_62_HCODE124	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_62_HCODE124_0	(0x1u<<0)

// HUFFENC_AC1_63 Configuration

#define	JPEG_HUFFENC_AC1_63_HLEN127		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_63_HLEN127_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_63_HCODE127	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_63_HCODE127_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_63_HLEN126		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_63_HLEN126_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_63_HCODE126	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_63_HCODE126_0	(0x1u<<0)

// HUFFENC_AC1_64 Configuration

#define	JPEG_HUFFENC_AC1_64_HLEN129		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_64_HLEN129_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_64_HCODE129	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_64_HCODE129_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_64_HLEN128		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_64_HLEN128_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_64_HCODE128	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_64_HCODE128_0	(0x1u<<0)

// HUFFENC_AC1_65 Configuration

#define	JPEG_HUFFENC_AC1_65_HLEN131		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_65_HLEN131_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_65_HCODE131	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_65_HCODE131_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_65_HLEN130		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_65_HLEN130_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_65_HCODE130	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_65_HCODE130_0	(0x1u<<0)

// HUFFENC_AC1_66 Configuration

#define	JPEG_HUFFENC_AC1_66_HLEN133		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_66_HLEN133_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_66_HCODE133	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_66_HCODE133_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_66_HLEN132		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_66_HLEN132_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_66_HCODE132	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_66_HCODE132_0	(0x1u<<0)

// HUFFENC_AC1_67 Configuration

#define	JPEG_HUFFENC_AC1_67_HLEN135		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_67_HLEN135_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_67_HCODE135	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_67_HCODE135_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_67_HLEN134		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_67_HLEN134_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_67_HCODE134	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_67_HCODE134_0	(0x1u<<0)

// HUFFENC_AC1_68 Configuration

#define	JPEG_HUFFENC_AC1_68_HLEN137		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_68_HLEN137_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_68_HCODE137	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_68_HCODE137_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_68_HLEN136		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_68_HLEN136_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_68_HCODE136	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_68_HCODE136_0	(0x1u<<0)

// HUFFENC_AC1_69 Configuration

#define	JPEG_HUFFENC_AC1_69_HLEN139		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_69_HLEN139_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_69_HCODE139	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_69_HCODE139_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_69_HLEN138		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_69_HLEN138_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_69_HCODE138	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_69_HCODE138_0	(0x1u<<0)

// HUFFENC_AC1_70 Configuration

#define	JPEG_HUFFENC_AC1_70_HLEN141		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_70_HLEN141_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_70_HCODE141	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_70_HCODE141_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_70_HLEN140		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_70_HLEN140_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_70_HCODE140	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_70_HCODE140_0	(0x1u<<0)

// HUFFENC_AC1_71 Configuration

#define	JPEG_HUFFENC_AC1_71_HLEN143		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_71_HLEN143_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_71_HCODE143	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_71_HCODE143_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_71_HLEN142		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_71_HLEN142_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_71_HCODE142	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_71_HCODE142_0	(0x1u<<0)

// HUFFENC_AC1_72 Configuration

#define	JPEG_HUFFENC_AC1_72_HLEN145		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_72_HLEN145_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_72_HCODE145	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_72_HCODE145_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_72_HLEN144		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_72_HLEN144_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_72_HCODE144	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_72_HCODE144_0	(0x1u<<0)

// HUFFENC_AC1_73 Configuration

#define	JPEG_HUFFENC_AC1_73_HLEN147		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_73_HLEN147_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_73_HCODE147	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_73_HCODE147_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_73_HLEN146		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_73_HLEN146_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_73_HCODE146	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_73_HCODE146_0	(0x1u<<0)

// HUFFENC_AC1_74 Configuration

#define	JPEG_HUFFENC_AC1_74_HLEN149		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_74_HLEN149_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_74_HCODE149	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_74_HCODE149_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_74_HLEN148		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_74_HLEN148_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_74_HCODE148	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_74_HCODE148_0	(0x1u<<0)

// HUFFENC_AC1_75 Configuration

#define	JPEG_HUFFENC_AC1_75_HLEN151		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_75_HLEN151_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_75_HCODE151	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_75_HCODE151_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_75_HLEN150		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_75_HLEN150_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_75_HCODE150	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_75_HCODE150_0	(0x1u<<0)

// HUFFENC_AC1_76 Configuration

#define	JPEG_HUFFENC_AC1_76_HLEN153		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_76_HLEN153_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_76_HCODE153	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_76_HCODE153_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_76_HLEN152		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_76_HLEN152_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_76_HCODE152	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_76_HCODE152_0	(0x1u<<0)

// HUFFENC_AC1_77 Configuration

#define	JPEG_HUFFENC_AC1_77_HLEN155		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_77_HLEN155_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_77_HCODE155	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_77_HCODE155_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_77_HLEN154		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_77_HLEN154_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_77_HCODE154	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_77_HCODE154_0	(0x1u<<0)

// HUFFENC_AC1_78 Configuration

#define	JPEG_HUFFENC_AC1_78_HLEN157		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_78_HLEN157_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_78_HCODE157	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_78_HCODE157_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_78_HLEN156		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_78_HLEN156_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_78_HCODE156	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_78_HCODE156_0	(0x1u<<0)

// HUFFENC_AC1_79 Configuration

#define	JPEG_HUFFENC_AC1_79_HLEN159		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_79_HLEN159_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_79_HCODE159	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_79_HCODE159_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_79_HLEN158		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_79_HLEN158_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_79_HCODE158	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_79_HCODE158_0	(0x1u<<0)

// HUFFENC_AC1_80 Configuration

#define	JPEG_HUFFENC_AC1_80_HLEN161		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_80_HLEN161_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_80_HCODE161	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_80_HCODE161_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_80_HLEN160		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_80_HLEN160_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_80_HCODE160	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_80_HCODE160_0	(0x1u<<0)

// HUFFENC_AC1_81 Configuration

#define	JPEG_HUFFENC_AC1_81_HLEN163		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_81_HLEN163_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_81_HCODE163	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_81_HCODE163_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_81_HLEN162		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_81_HLEN162_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_81_HCODE162	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_81_HCODE162_0	(0x1u<<0)

// HUFFENC_AC1_82 Configuration

#define	JPEG_HUFFENC_AC1_82_HLEN165		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_82_HLEN165_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_82_HCODE165	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_82_HCODE165_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_82_HLEN164		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_82_HLEN164_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_82_HCODE164	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_82_HCODE164_0	(0x1u<<0)

// HUFFENC_AC1_83 Configuration

#define	JPEG_HUFFENC_AC1_83_HLEN167		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_83_HLEN167_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_83_HCODE167	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_83_HCODE167_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_83_HLEN166		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_83_HLEN166_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_83_HCODE166	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_83_HCODE166_0	(0x1u<<0)

// HUFFENC_AC1_84 Configuration

#define	JPEG_HUFFENC_AC1_84_HLEN169		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_84_HLEN169_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_84_HCODE169	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_84_HCODE169_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_84_HLEN168		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_84_HLEN168_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_84_HCODE168	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_84_HCODE168_0	(0x1u<<0)

// HUFFENC_AC1_85 Configuration

#define	JPEG_HUFFENC_AC1_85_HLEN171		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_85_HLEN171_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_85_HCODE171	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_85_HCODE171_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_85_HLEN170		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_85_HLEN170_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_85_HCODE170	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_85_HCODE170_0	(0x1u<<0)

// HUFFENC_AC1_86 Configuration

#define	JPEG_HUFFENC_AC1_86_HLEN173		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_86_HLEN173_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_86_HCODE173	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_86_HCODE173_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_86_HLEN172		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_86_HLEN172_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_86_HCODE172	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_86_HCODE172_0	(0x1u<<0)

// HUFFENC_AC1_87 Configuration

#define	JPEG_HUFFENC_AC1_87_HLEN175		(0xFu<<24)
#define	JPEG_HUFFENC_AC1_87_HLEN175_0	(0x1u<<24)
#define	JPEG_HUFFENC_AC1_87_HCODE175	(0xFFu<<16)
#define	JPEG_HUFFENC_AC1_87_HCODE175_0	(0x1u<<16)
#define	JPEG_HUFFENC_AC1_87_HLEN174		(0xFu<<8)
#define	JPEG_HUFFENC_AC1_87_HLEN174_0	(0x1u<<8)
#define	JPEG_HUFFENC_AC1_87_HCODE174	(0xFFu<<0)
#define	JPEG_HUFFENC_AC1_87_HCODE174_0	(0x1u<<0)

// HUFFENC_DC0_0 Configuration

#define	JPEG_HUFFENC_DC0_0_HLEN1		(0xFu<<24)
#define	JPEG_HUFFENC_DC0_0_HLEN1_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC0_0_HCODE1		(0xFFu<<16)
#define	JPEG_HUFFENC_DC0_0_HCODE1_0		(0x1u<<16)
#define	JPEG_HUFFENC_DC0_0_HLEN0		(0xFu<<8)
#define	JPEG_HUFFENC_DC0_0_HLEN0_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC0_0_HCODE0		(0xFFu<<0)
#define	JPEG_HUFFENC_DC0_0_HCODE0_0		(0x1u<<0)

// HUFFENC_DC0_1 Configuration

#define	JPEG_HUFFENC_DC0_1_HLEN3		(0xFu<<24)
#define	JPEG_HUFFENC_DC0_1_HLEN3_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC0_1_HCODE3		(0xFFu<<16)
#define	JPEG_HUFFENC_DC0_1_HCODE3_0		(0x1u<<16)
#define	JPEG_HUFFENC_DC0_1_HLEN2		(0xFu<<8)
#define	JPEG_HUFFENC_DC0_1_HLEN2_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC0_1_HCODE2		(0xFFu<<0)
#define	JPEG_HUFFENC_DC0_1_HCODE2_0		(0x1u<<0)

// HUFFENC_DC0_2 Configuration

#define	JPEG_HUFFENC_DC0_2_HLEN5		(0xFu<<24)
#define	JPEG_HUFFENC_DC0_2_HLEN5_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC0_2_HCODE5		(0xFFu<<16)
#define	JPEG_HUFFENC_DC0_2_HCODE5_0		(0x1u<<16)
#define	JPEG_HUFFENC_DC0_2_HLEN4		(0xFu<<8)
#define	JPEG_HUFFENC_DC0_2_HLEN4_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC0_2_HCODE4		(0xFFu<<0)
#define	JPEG_HUFFENC_DC0_2_HCODE4_0		(0x1u<<0)

// HUFFENC_DC0_3 Configuration

#define	JPEG_HUFFENC_DC0_3_HLEN7		(0xFu<<24)
#define	JPEG_HUFFENC_DC0_3_HLEN7_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC0_3_HCODE7		(0xFFu<<16)
#define	JPEG_HUFFENC_DC0_3_HCODE7_0		(0x1u<<16)
#define	JPEG_HUFFENC_DC0_3_HLEN6		(0xFu<<8)
#define	JPEG_HUFFENC_DC0_3_HLEN6_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC0_3_HCODE6		(0xFFu<<0)
#define	JPEG_HUFFENC_DC0_3_HCODE6_0		(0x1u<<0)

// HUFFENC_DC0_4 Configuration

#define	JPEG_HUFFENC_DC0_4_HLEN9		(0xFu<<24)
#define	JPEG_HUFFENC_DC0_4_HLEN9_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC0_4_HCODE9		(0xFFu<<16)
#define	JPEG_HUFFENC_DC0_4_HCODE9_0		(0x1u<<16)
#define	JPEG_HUFFENC_DC0_4_HLEN8		(0xFu<<8)
#define	JPEG_HUFFENC_DC0_4_HLEN8_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC0_4_HCODE8		(0xFFu<<0)
#define	JPEG_HUFFENC_DC0_4_HCODE8_0		(0x1u<<0)

// HUFFENC_DC0_5 Configuration

#define	JPEG_HUFFENC_DC0_5_HLEN11		(0xFu<<24)
#define	JPEG_HUFFENC_DC0_5_HLEN11_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC0_5_HCODE11		(0xFFu<<16)
#define	JPEG_HUFFENC_DC0_5_HCODE11_0	(0x1u<<16)
#define	JPEG_HUFFENC_DC0_5_HLEN10		(0xFu<<8)
#define	JPEG_HUFFENC_DC0_5_HLEN10_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC0_5_HCODE10		(0xFFu<<0)
#define	JPEG_HUFFENC_DC0_5_HCODE10_0	(0x1u<<0)

// HUFFENC_DC0_6 Configuration

#define	JPEG_HUFFENC_DC0_6_HLEN13		(0xFu<<24)
#define	JPEG_HUFFENC_DC0_6_HLEN13_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC0_6_HCODE13		(0xFFu<<16)
#define	JPEG_HUFFENC_DC0_6_HCODE13_0	(0x1u<<16)
#define	JPEG_HUFFENC_DC0_6_HLEN12		(0xFu<<8)
#define	JPEG_HUFFENC_DC0_6_HLEN12_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC0_6_HCODE12		(0xFFu<<0)
#define	JPEG_HUFFENC_DC0_6_HCODE12_0	(0x1u<<0)

// HUFFENC_DC0_7 Configuration

#define	JPEG_HUFFENC_DC0_7_HLEN15		(0xFu<<24)
#define	JPEG_HUFFENC_DC0_7_HLEN15_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC0_7_HCODE15		(0xFFu<<16)
#define	JPEG_HUFFENC_DC0_7_HCODE15_0	(0x1u<<16)
#define	JPEG_HUFFENC_DC0_7_HLEN14		(0xFu<<8)
#define	JPEG_HUFFENC_DC0_7_HLEN14_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC0_7_HCODE14		(0xFFu<<0)
#define	JPEG_HUFFENC_DC0_7_HCODE14_0	(0x1u<<0)

// HUFFENC_DC1_0 Configuration

#define	JPEG_HUFFENC_DC1_0_HLEN1		(0xFu<<24)
#define	JPEG_HUFFENC_DC1_0_HLEN1_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC1_0_HCODE1		(0xFFu<<16)
#define	JPEG_HUFFENC_DC1_0_HCODE1_0		(0x1u<<16)
#define	JPEG_HUFFENC_DC1_0_HLEN0		(0xFu<<8)
#define	JPEG_HUFFENC_DC1_0_HLEN0_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC1_0_HCODE0		(0xFFu<<0)
#define	JPEG_HUFFENC_DC1_0_HCODE0_0		(0x1u<<0)

// HUFFENC_DC1_1 Configuration

#define	JPEG_HUFFENC_DC1_1_HLEN3		(0xFu<<24)
#define	JPEG_HUFFENC_DC1_1_HLEN3_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC1_1_HCODE3		(0xFFu<<16)
#define	JPEG_HUFFENC_DC1_1_HCODE3_0		(0x1u<<16)
#define	JPEG_HUFFENC_DC1_1_HLEN2		(0xFu<<8)
#define	JPEG_HUFFENC_DC1_1_HLEN2_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC1_1_HCODE2		(0xFFu<<0)
#define	JPEG_HUFFENC_DC1_1_HCODE2_0		(0x1u<<0)

// HUFFENC_DC1_2 Configuration

#define	JPEG_HUFFENC_DC1_2_HLEN5		(0xFu<<24)
#define	JPEG_HUFFENC_DC1_2_HLEN5_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC1_2_HCODE5		(0xFFu<<16)
#define	JPEG_HUFFENC_DC1_2_HCODE5_0		(0x1u<<16)
#define	JPEG_HUFFENC_DC1_2_HLEN4		(0xFu<<8)
#define	JPEG_HUFFENC_DC1_2_HLEN4_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC1_2_HCODE4		(0xFFu<<0)
#define	JPEG_HUFFENC_DC1_2_HCODE4_0		(0x1u<<0)

// HUFFENC_DC1_3 Configuration

#define	JPEG_HUFFENC_DC1_3_HLEN7		(0xFu<<24)
#define	JPEG_HUFFENC_DC1_3_HLEN7_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC1_3_HCODE7		(0xFFu<<16)
#define	JPEG_HUFFENC_DC1_3_HCODE7_0		(0x1u<<16)
#define	JPEG_HUFFENC_DC1_3_HLEN6		(0xFu<<8)
#define	JPEG_HUFFENC_DC1_3_HLEN6_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC1_3_HCODE6		(0xFFu<<0)
#define	JPEG_HUFFENC_DC1_3_HCODE6_0		(0x1u<<0)

// HUFFENC_DC1_4 Configuration

#define	JPEG_HUFFENC_DC1_4_HLEN9		(0xFu<<24)
#define	JPEG_HUFFENC_DC1_4_HLEN9_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC1_4_HCODE9		(0xFFu<<16)
#define	JPEG_HUFFENC_DC1_4_HCODE9_0		(0x1u<<16)
#define	JPEG_HUFFENC_DC1_4_HLEN8		(0xFu<<8)
#define	JPEG_HUFFENC_DC1_4_HLEN8_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC1_4_HCODE8		(0xFFu<<0)
#define	JPEG_HUFFENC_DC1_4_HCODE8_0		(0x1u<<0)

// HUFFENC_DC1_5 Configuration

#define	JPEG_HUFFENC_DC1_5_HLEN11		(0xFu<<24)
#define	JPEG_HUFFENC_DC1_5_HLEN11_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC1_5_HCODE11		(0xFFu<<16)
#define	JPEG_HUFFENC_DC1_5_HCODE11_0	(0x1u<<16)
#define	JPEG_HUFFENC_DC1_5_HLEN10		(0xFu<<8)
#define	JPEG_HUFFENC_DC1_5_HLEN10_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC1_5_HCODE10		(0xFFu<<0)
#define	JPEG_HUFFENC_DC1_5_HCODE10_0	(0x1u<<0)

// HUFFENC_DC1_6 Configuration

#define	JPEG_HUFFENC_DC1_6_HLEN13		(0xFu<<24)
#define	JPEG_HUFFENC_DC1_6_HLEN13_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC1_6_HCODE13		(0xFFu<<16)
#define	JPEG_HUFFENC_DC1_6_HCODE13_0	(0x1u<<16)
#define	JPEG_HUFFENC_DC1_6_HLEN12		(0xFu<<8)
#define	JPEG_HUFFENC_DC1_6_HLEN12_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC1_6_HCODE12		(0xFFu<<0)
#define	JPEG_HUFFENC_DC1_6_HCODE12_0	(0x1u<<0)

// HUFFENC_DC1_7 Configuration

#define	JPEG_HUFFENC_DC1_7_HLEN15		(0xFu<<24)
#define	JPEG_HUFFENC_DC1_7_HLEN15_0		(0x1u<<24)
#define	JPEG_HUFFENC_DC1_7_HCODE15		(0xFFu<<16)
#define	JPEG_HUFFENC_DC1_7_HCODE15_0	(0x1u<<16)
#define	JPEG_HUFFENC_DC1_7_HLEN14		(0xFu<<8)
#define	JPEG_HUFFENC_DC1_7_HLEN14_0		(0x1u<<8)
#define	JPEG_HUFFENC_DC1_7_HCODE14		(0xFFu<<0)
#define	JPEG_HUFFENC_DC1_7_HCODE14_0	(0x1u<<0)
