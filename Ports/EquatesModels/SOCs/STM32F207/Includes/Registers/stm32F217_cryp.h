/*
; stm32F217_cryp.
; ===============
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32F217_cryp equates.
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

// CRYP address definitions
// ------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	DIN;
	volatile	uint32_t	DOUT;
	volatile	uint32_t	DMACR;
	volatile	uint32_t	IMSCR;
	volatile	uint32_t	RISR;
	volatile	uint32_t	MISR;
	volatile	uint32_t	K0LR;
	volatile	uint32_t	K0RR;
	volatile	uint32_t	K1LR;
	volatile	uint32_t	K1RR;
	volatile	uint32_t	K2LR;
	volatile	uint32_t	K2RR;
	volatile	uint32_t	K3LR;
	volatile	uint32_t	K3RR;
	volatile	uint32_t	IV0LR;
	volatile	uint32_t	IV0RR;
	volatile	uint32_t	IV1LR;
	volatile	uint32_t	IV1RR;
} CRYP_TypeDef;

#if (defined(__cplusplus))
#define	CRYP	reinterpret_cast<CRYP_TypeDef *>(0x50060000u)

#else
#define	CRYP	((CRYP_TypeDef *)0x50060000u)
#endif

// CR Configuration

#define	CRYP_CR_ALGODIR		(0x1u<<2)
#define	CRYP_CR_ALGOMODE	(0x7u<<3)
#define	CRYP_CR_ALGOMODE_0	(0x1u<<3)
#define	CRYP_CR_DATATYPE	(0x3u<<6)
#define	CRYP_CR_DATATYPE_0	(0x1u<<6)
#define	CRYP_CR_KEYSIZE		(0x3u<<8)
#define	CRYP_CR_KEYSIZE_0	(0x1u<<8)
#define	CRYP_CR_FFLUSH		(0x1u<<14)
#define	CRYP_CR_CRYPEN		(0x1u<<15)

// SR Configuration

#define	CRYP_SR_IFEM		(0x1u<<0)
#define	CRYP_SR_IFNF		(0x1u<<1)
#define	CRYP_SR_OFNE		(0x1u<<2)
#define	CRYP_SR_OFFU		(0x1u<<3)
#define	CRYP_SR_BUSY		(0x1u<<4)

// DIN Configuration

#define	CRYP_DIN_DATAIN		(0xFFFFFFFFu<<0)
#define	CRYP_DIN_DATAIN_0	(0x1u<<0)

// DOUT Configuration

#define	CRYP_DOUT_DATAOUT	(0xFFFFFFFFu<<0)
#define	CRYP_DOUT_DATAOUT_0	(0x1u<<0)

// DMACR Configuration

#define	CRYP_DMACR_DIEN		(0x1u<<0)
#define	CRYP_DMACR_DOEN		(0x1u<<1)

// IMSCR Configuration

#define	CRYP_IMSCR_INIM		(0x1u<<0)
#define	CRYP_IMSCR_OUTIM	(0x1u<<1)

// RISR Configuration

#define	CRYP_RISR_INRIS		(0x1u<<0)
#define	CRYP_RISR_OUTRIS	(0x1u<<1)

// MISR Configuration

#define	CRYP_MISR_INMIS		(0x1u<<0)
#define	CRYP_MISR_OUTMIS	(0x1u<<1)

// K0LR Configuration

#define	CRYP_K0LR_B255		(0x1u<<31)
#define	CRYP_K0LR_B254		(0x1u<<30)
#define	CRYP_K0LR_B253		(0x1u<<29)
#define	CRYP_K0LR_B252		(0x1u<<28)
#define	CRYP_K0LR_B251		(0x1u<<27)
#define	CRYP_K0LR_B250		(0x1u<<26)
#define	CRYP_K0LR_B249		(0x1u<<25)
#define	CRYP_K0LR_B248		(0x1u<<24)
#define	CRYP_K0LR_B247		(0x1u<<23)
#define	CRYP_K0LR_B246		(0x1u<<22)
#define	CRYP_K0LR_B245		(0x1u<<21)
#define	CRYP_K0LR_B244		(0x1u<<20)
#define	CRYP_K0LR_B243		(0x1u<<19)
#define	CRYP_K0LR_B242		(0x1u<<18)
#define	CRYP_K0LR_B241		(0x1u<<17)
#define	CRYP_K0LR_B240		(0x1u<<16)
#define	CRYP_K0LR_B239		(0x1u<<15)
#define	CRYP_K0LR_B238		(0x1u<<14)
#define	CRYP_K0LR_B237		(0x1u<<13)
#define	CRYP_K0LR_B236		(0x1u<<12)
#define	CRYP_K0LR_B235		(0x1u<<11)
#define	CRYP_K0LR_B234		(0x1u<<10)
#define	CRYP_K0LR_B233		(0x1u<<9)
#define	CRYP_K0LR_B232		(0x1u<<8)
#define	CRYP_K0LR_B231		(0x1u<<7)
#define	CRYP_K0LR_B230		(0x1u<<6)
#define	CRYP_K0LR_B229		(0x1u<<5)
#define	CRYP_K0LR_B228		(0x1u<<4)
#define	CRYP_K0LR_B227		(0x1u<<3)
#define	CRYP_K0LR_B226		(0x1u<<2)
#define	CRYP_K0LR_B225		(0x1u<<1)
#define	CRYP_K0LR_B224		(0x1u<<0)

// K0RR Configuration

#define	CRYP_K0RR_B223		(0x1u<<31)
#define	CRYP_K0RR_B222		(0x1u<<30)
#define	CRYP_K0RR_B221		(0x1u<<29)
#define	CRYP_K0RR_B220		(0x1u<<28)
#define	CRYP_K0RR_B219		(0x1u<<27)
#define	CRYP_K0RR_B218		(0x1u<<26)
#define	CRYP_K0RR_B217		(0x1u<<25)
#define	CRYP_K0RR_B216		(0x1u<<24)
#define	CRYP_K0RR_B215		(0x1u<<23)
#define	CRYP_K0RR_B214		(0x1u<<22)
#define	CRYP_K0RR_B213		(0x1u<<21)
#define	CRYP_K0RR_B212		(0x1u<<20)
#define	CRYP_K0RR_B211		(0x1u<<19)
#define	CRYP_K0RR_B210		(0x1u<<18)
#define	CRYP_K0RR_B209		(0x1u<<17)
#define	CRYP_K0RR_B208		(0x1u<<16)
#define	CRYP_K0RR_B207		(0x1u<<15)
#define	CRYP_K0RR_B206		(0x1u<<14)
#define	CRYP_K0RR_B205		(0x1u<<13)
#define	CRYP_K0RR_B204		(0x1u<<12)
#define	CRYP_K0RR_B203		(0x1u<<11)
#define	CRYP_K0RR_B202		(0x1u<<10)
#define	CRYP_K0RR_B201		(0x1u<<9)
#define	CRYP_K0RR_B200		(0x1u<<8)
#define	CRYP_K0RR_B199		(0x1u<<7)
#define	CRYP_K0RR_B198		(0x1u<<6)
#define	CRYP_K0RR_B197		(0x1u<<5)
#define	CRYP_K0RR_B196		(0x1u<<4)
#define	CRYP_K0RR_B195		(0x1u<<3)
#define	CRYP_K0RR_B194		(0x1u<<2)
#define	CRYP_K0RR_B193		(0x1u<<1)
#define	CRYP_K0RR_B192		(0x1u<<0)

// K1LR Configuration

#define	CRYP_K1LR_B191		(0x1u<<31)
#define	CRYP_K1LR_B190		(0x1u<<30)
#define	CRYP_K1LR_B189		(0x1u<<29)
#define	CRYP_K1LR_B188		(0x1u<<28)
#define	CRYP_K1LR_B187		(0x1u<<27)
#define	CRYP_K1LR_B186		(0x1u<<26)
#define	CRYP_K1LR_B185		(0x1u<<25)
#define	CRYP_K1LR_B184		(0x1u<<24)
#define	CRYP_K1LR_B183		(0x1u<<23)
#define	CRYP_K1LR_B182		(0x1u<<22)
#define	CRYP_K1LR_B181		(0x1u<<21)
#define	CRYP_K1LR_B180		(0x1u<<20)
#define	CRYP_K1LR_B179		(0x1u<<19)
#define	CRYP_K1LR_B178		(0x1u<<18)
#define	CRYP_K1LR_B177		(0x1u<<17)
#define	CRYP_K1LR_B176		(0x1u<<16)
#define	CRYP_K1LR_B175		(0x1u<<15)
#define	CRYP_K1LR_B174		(0x1u<<14)
#define	CRYP_K1LR_B173		(0x1u<<13)
#define	CRYP_K1LR_B172		(0x1u<<12)
#define	CRYP_K1LR_B171		(0x1u<<11)
#define	CRYP_K1LR_B170		(0x1u<<10)
#define	CRYP_K1LR_B169		(0x1u<<9)
#define	CRYP_K1LR_B168		(0x1u<<8)
#define	CRYP_K1LR_B167		(0x1u<<7)
#define	CRYP_K1LR_B166		(0x1u<<6)
#define	CRYP_K1LR_B165		(0x1u<<5)
#define	CRYP_K1LR_B164		(0x1u<<4)
#define	CRYP_K1LR_B163		(0x1u<<3)
#define	CRYP_K1LR_B162		(0x1u<<2)
#define	CRYP_K1LR_B161		(0x1u<<1)
#define	CRYP_K1LR_B160		(0x1u<<0)

// K1RR Configuration

#define	CRYP_K1RR_B159		(0x1u<<31)
#define	CRYP_K1RR_B158		(0x1u<<30)
#define	CRYP_K1RR_B157		(0x1u<<29)
#define	CRYP_K1RR_B156		(0x1u<<28)
#define	CRYP_K1RR_B155		(0x1u<<27)
#define	CRYP_K1RR_B154		(0x1u<<26)
#define	CRYP_K1RR_B153		(0x1u<<25)
#define	CRYP_K1RR_B152		(0x1u<<24)
#define	CRYP_K1RR_B151		(0x1u<<23)
#define	CRYP_K1RR_B150		(0x1u<<22)
#define	CRYP_K1RR_B149		(0x1u<<21)
#define	CRYP_K1RR_B148		(0x1u<<20)
#define	CRYP_K1RR_B147		(0x1u<<19)
#define	CRYP_K1RR_B146		(0x1u<<18)
#define	CRYP_K1RR_B145		(0x1u<<17)
#define	CRYP_K1RR_B144		(0x1u<<16)
#define	CRYP_K1RR_B143		(0x1u<<15)
#define	CRYP_K1RR_B142		(0x1u<<14)
#define	CRYP_K1RR_B141		(0x1u<<13)
#define	CRYP_K1RR_B140		(0x1u<<12)
#define	CRYP_K1RR_B139		(0x1u<<11)
#define	CRYP_K1RR_B138		(0x1u<<10)
#define	CRYP_K1RR_B137		(0x1u<<9)
#define	CRYP_K1RR_B136		(0x1u<<8)
#define	CRYP_K1RR_B135		(0x1u<<7)
#define	CRYP_K1RR_B134		(0x1u<<6)
#define	CRYP_K1RR_B133		(0x1u<<5)
#define	CRYP_K1RR_B132		(0x1u<<4)
#define	CRYP_K1RR_B131		(0x1u<<3)
#define	CRYP_K1RR_B130		(0x1u<<2)
#define	CRYP_K1RR_B129		(0x1u<<1)
#define	CRYP_K1RR_B128		(0x1u<<0)

// K2LR Configuration

#define	CRYP_K2LR_B127		(0x1u<<31)
#define	CRYP_K2LR_B126		(0x1u<<30)
#define	CRYP_K2LR_B125		(0x1u<<29)
#define	CRYP_K2LR_B124		(0x1u<<28)
#define	CRYP_K2LR_B123		(0x1u<<27)
#define	CRYP_K2LR_B122		(0x1u<<26)
#define	CRYP_K2LR_B121		(0x1u<<25)
#define	CRYP_K2LR_B120		(0x1u<<24)
#define	CRYP_K2LR_B119		(0x1u<<23)
#define	CRYP_K2LR_B118		(0x1u<<22)
#define	CRYP_K2LR_B117		(0x1u<<21)
#define	CRYP_K2LR_B116		(0x1u<<20)
#define	CRYP_K2LR_B115		(0x1u<<19)
#define	CRYP_K2LR_B114		(0x1u<<18)
#define	CRYP_K2LR_B113		(0x1u<<17)
#define	CRYP_K2LR_B112		(0x1u<<16)
#define	CRYP_K2LR_B111		(0x1u<<15)
#define	CRYP_K2LR_B110		(0x1u<<14)
#define	CRYP_K2LR_B109		(0x1u<<13)
#define	CRYP_K2LR_B108		(0x1u<<12)
#define	CRYP_K2LR_B107		(0x1u<<11)
#define	CRYP_K2LR_B106		(0x1u<<10)
#define	CRYP_K2LR_B105		(0x1u<<9)
#define	CRYP_K2LR_B104		(0x1u<<8)
#define	CRYP_K2LR_B103		(0x1u<<7)
#define	CRYP_K2LR_B102		(0x1u<<6)
#define	CRYP_K2LR_B101		(0x1u<<5)
#define	CRYP_K2LR_B100		(0x1u<<4)
#define	CRYP_K2LR_B99		(0x1u<<3)
#define	CRYP_K2LR_B98		(0x1u<<2)
#define	CRYP_K2LR_B97		(0x1u<<1)
#define	CRYP_K2LR_B96		(0x1u<<0)

// K2RR Configuration

#define	CRYP_K2RR_B95		(0x1u<<31)
#define	CRYP_K2RR_B94		(0x1u<<30)
#define	CRYP_K2RR_B93		(0x1u<<29)
#define	CRYP_K2RR_B92		(0x1u<<28)
#define	CRYP_K2RR_B91		(0x1u<<27)
#define	CRYP_K2RR_B90		(0x1u<<26)
#define	CRYP_K2RR_B89		(0x1u<<25)
#define	CRYP_K2RR_B88		(0x1u<<24)
#define	CRYP_K2RR_B87		(0x1u<<23)
#define	CRYP_K2RR_B86		(0x1u<<22)
#define	CRYP_K2RR_B85		(0x1u<<21)
#define	CRYP_K2RR_B84		(0x1u<<20)
#define	CRYP_K2RR_B83		(0x1u<<19)
#define	CRYP_K2RR_B82		(0x1u<<18)
#define	CRYP_K2RR_B81		(0x1u<<17)
#define	CRYP_K2RR_B80		(0x1u<<16)
#define	CRYP_K2RR_B79		(0x1u<<15)
#define	CRYP_K2RR_B78		(0x1u<<14)
#define	CRYP_K2RR_B77		(0x1u<<13)
#define	CRYP_K2RR_B76		(0x1u<<12)
#define	CRYP_K2RR_B75		(0x1u<<11)
#define	CRYP_K2RR_B74		(0x1u<<10)
#define	CRYP_K2RR_B73		(0x1u<<9)
#define	CRYP_K2RR_B72		(0x1u<<8)
#define	CRYP_K2RR_B71		(0x1u<<7)
#define	CRYP_K2RR_B70		(0x1u<<6)
#define	CRYP_K2RR_B69		(0x1u<<5)
#define	CRYP_K2RR_B68		(0x1u<<4)
#define	CRYP_K2RR_B67		(0x1u<<3)
#define	CRYP_K2RR_B66		(0x1u<<2)
#define	CRYP_K2RR_B65		(0x1u<<1)
#define	CRYP_K2RR_B64		(0x1u<<0)

// K3LR Configuration

#define	CRYP_K3LR_B63		(0x1u<<31)
#define	CRYP_K3LR_B62		(0x1u<<30)
#define	CRYP_K3LR_B61		(0x1u<<29)
#define	CRYP_K3LR_B60		(0x1u<<28)
#define	CRYP_K3LR_B59		(0x1u<<27)
#define	CRYP_K3LR_B58		(0x1u<<26)
#define	CRYP_K3LR_B57		(0x1u<<25)
#define	CRYP_K3LR_B56		(0x1u<<24)
#define	CRYP_K3LR_B55		(0x1u<<23)
#define	CRYP_K3LR_B54		(0x1u<<22)
#define	CRYP_K3LR_B53		(0x1u<<21)
#define	CRYP_K3LR_B52		(0x1u<<20)
#define	CRYP_K3LR_B51		(0x1u<<19)
#define	CRYP_K3LR_B50		(0x1u<<18)
#define	CRYP_K3LR_B49		(0x1u<<17)
#define	CRYP_K3LR_B48		(0x1u<<16)
#define	CRYP_K3LR_B47		(0x1u<<15)
#define	CRYP_K3LR_B46		(0x1u<<14)
#define	CRYP_K3LR_B45		(0x1u<<13)
#define	CRYP_K3LR_B44		(0x1u<<12)
#define	CRYP_K3LR_B43		(0x1u<<11)
#define	CRYP_K3LR_B42		(0x1u<<10)
#define	CRYP_K3LR_B41		(0x1u<<9)
#define	CRYP_K3LR_B40		(0x1u<<8)
#define	CRYP_K3LR_B39		(0x1u<<7)
#define	CRYP_K3LR_B38		(0x1u<<6)
#define	CRYP_K3LR_B37		(0x1u<<5)
#define	CRYP_K3LR_B36		(0x1u<<4)
#define	CRYP_K3LR_B35		(0x1u<<3)
#define	CRYP_K3LR_B34		(0x1u<<2)
#define	CRYP_K3LR_B33		(0x1u<<1)
#define	CRYP_K3LR_B32		(0x1u<<0)

// K3RR Configuration

#define	CRYP_K3RR_B31		(0x1u<<31)
#define	CRYP_K3RR_B30		(0x1u<<30)
#define	CRYP_K3RR_B29		(0x1u<<29)
#define	CRYP_K3RR_B28		(0x1u<<28)
#define	CRYP_K3RR_B27		(0x1u<<27)
#define	CRYP_K3RR_B26		(0x1u<<26)
#define	CRYP_K3RR_B25		(0x1u<<25)
#define	CRYP_K3RR_B24		(0x1u<<24)
#define	CRYP_K3RR_B23		(0x1u<<23)
#define	CRYP_K3RR_B22		(0x1u<<22)
#define	CRYP_K3RR_B21		(0x1u<<21)
#define	CRYP_K3RR_B20		(0x1u<<20)
#define	CRYP_K3RR_B19		(0x1u<<19)
#define	CRYP_K3RR_B18		(0x1u<<18)
#define	CRYP_K3RR_B17		(0x1u<<17)
#define	CRYP_K3RR_B16		(0x1u<<16)
#define	CRYP_K3RR_B15		(0x1u<<15)
#define	CRYP_K3RR_B14		(0x1u<<14)
#define	CRYP_K3RR_B13		(0x1u<<13)
#define	CRYP_K3RR_B12		(0x1u<<12)
#define	CRYP_K3RR_B11		(0x1u<<11)
#define	CRYP_K3RR_B10		(0x1u<<10)
#define	CRYP_K3RR_B9		(0x1u<<9)
#define	CRYP_K3RR_B8		(0x1u<<8)
#define	CRYP_K3RR_B7		(0x1u<<7)
#define	CRYP_K3RR_B6		(0x1u<<6)
#define	CRYP_K3RR_B5		(0x1u<<5)
#define	CRYP_K3RR_B4		(0x1u<<4)
#define	CRYP_K3RR_B3		(0x1u<<3)
#define	CRYP_K3RR_B2		(0x1u<<2)
#define	CRYP_K3RR_B1		(0x1u<<1)
#define	CRYP_K3RR_B0		(0x1u<<0)

// IV0LR Configuration

#define	CRYP_IV0LR_IV0		(0x1u<<31)
#define	CRYP_IV0LR_IV1		(0x1u<<30)
#define	CRYP_IV0LR_IV2		(0x1u<<29)
#define	CRYP_IV0LR_IV3		(0x1u<<28)
#define	CRYP_IV0LR_IV4		(0x1u<<27)
#define	CRYP_IV0LR_IV5		(0x1u<<26)
#define	CRYP_IV0LR_IV6		(0x1u<<25)
#define	CRYP_IV0LR_IV7		(0x1u<<24)
#define	CRYP_IV0LR_IV8		(0x1u<<23)
#define	CRYP_IV0LR_IV9		(0x1u<<22)
#define	CRYP_IV0LR_IV10		(0x1u<<21)
#define	CRYP_IV0LR_IV11		(0x1u<<20)
#define	CRYP_IV0LR_IV12		(0x1u<<19)
#define	CRYP_IV0LR_IV13		(0x1u<<18)
#define	CRYP_IV0LR_IV14		(0x1u<<17)
#define	CRYP_IV0LR_IV15		(0x1u<<16)
#define	CRYP_IV0LR_IV16		(0x1u<<15)
#define	CRYP_IV0LR_IV17		(0x1u<<14)
#define	CRYP_IV0LR_IV18		(0x1u<<13)
#define	CRYP_IV0LR_IV19		(0x1u<<12)
#define	CRYP_IV0LR_IV20		(0x1u<<11)
#define	CRYP_IV0LR_IV21		(0x1u<<10)
#define	CRYP_IV0LR_IV22		(0x1u<<9)
#define	CRYP_IV0LR_IV23		(0x1u<<8)
#define	CRYP_IV0LR_IV24		(0x1u<<7)
#define	CRYP_IV0LR_IV25		(0x1u<<6)
#define	CRYP_IV0LR_IV26		(0x1u<<5)
#define	CRYP_IV0LR_IV27		(0x1u<<4)
#define	CRYP_IV0LR_IV28		(0x1u<<3)
#define	CRYP_IV0LR_IV29		(0x1u<<2)
#define	CRYP_IV0LR_IV30		(0x1u<<1)
#define	CRYP_IV0LR_IV31		(0x1u<<0)

// IV0RR Configuration

#define	CRYP_IV0RR_IV32		(0x1u<<31)
#define	CRYP_IV0RR_IV33		(0x1u<<30)
#define	CRYP_IV0RR_IV34		(0x1u<<29)
#define	CRYP_IV0RR_IV35		(0x1u<<28)
#define	CRYP_IV0RR_IV36		(0x1u<<27)
#define	CRYP_IV0RR_IV37		(0x1u<<26)
#define	CRYP_IV0RR_IV38		(0x1u<<25)
#define	CRYP_IV0RR_IV39		(0x1u<<24)
#define	CRYP_IV0RR_IV40		(0x1u<<23)
#define	CRYP_IV0RR_IV41		(0x1u<<22)
#define	CRYP_IV0RR_IV42		(0x1u<<21)
#define	CRYP_IV0RR_IV43		(0x1u<<20)
#define	CRYP_IV0RR_IV44		(0x1u<<19)
#define	CRYP_IV0RR_IV45		(0x1u<<18)
#define	CRYP_IV0RR_IV46		(0x1u<<17)
#define	CRYP_IV0RR_IV47		(0x1u<<16)
#define	CRYP_IV0RR_IV48		(0x1u<<15)
#define	CRYP_IV0RR_IV49		(0x1u<<14)
#define	CRYP_IV0RR_IV50		(0x1u<<13)
#define	CRYP_IV0RR_IV51		(0x1u<<12)
#define	CRYP_IV0RR_IV52		(0x1u<<11)
#define	CRYP_IV0RR_IV53		(0x1u<<10)
#define	CRYP_IV0RR_IV54		(0x1u<<9)
#define	CRYP_IV0RR_IV55		(0x1u<<8)
#define	CRYP_IV0RR_IV56		(0x1u<<7)
#define	CRYP_IV0RR_IV57		(0x1u<<6)
#define	CRYP_IV0RR_IV58		(0x1u<<5)
#define	CRYP_IV0RR_IV59		(0x1u<<4)
#define	CRYP_IV0RR_IV60		(0x1u<<3)
#define	CRYP_IV0RR_IV61		(0x1u<<2)
#define	CRYP_IV0RR_IV62		(0x1u<<1)
#define	CRYP_IV0RR_IV63		(0x1u<<0)

// IV1LR Configuration

#define	CRYP_IV1LR_IV64		(0x1u<<31)
#define	CRYP_IV1LR_IV65		(0x1u<<30)
#define	CRYP_IV1LR_IV66		(0x1u<<29)
#define	CRYP_IV1LR_IV67		(0x1u<<28)
#define	CRYP_IV1LR_IV68		(0x1u<<27)
#define	CRYP_IV1LR_IV69		(0x1u<<26)
#define	CRYP_IV1LR_IV70		(0x1u<<25)
#define	CRYP_IV1LR_IV71		(0x1u<<24)
#define	CRYP_IV1LR_IV72		(0x1u<<23)
#define	CRYP_IV1LR_IV73		(0x1u<<22)
#define	CRYP_IV1LR_IV74		(0x1u<<21)
#define	CRYP_IV1LR_IV75		(0x1u<<20)
#define	CRYP_IV1LR_IV76		(0x1u<<19)
#define	CRYP_IV1LR_IV77		(0x1u<<18)
#define	CRYP_IV1LR_IV78		(0x1u<<17)
#define	CRYP_IV1LR_IV79		(0x1u<<16)
#define	CRYP_IV1LR_IV80		(0x1u<<15)
#define	CRYP_IV1LR_IV81		(0x1u<<14)
#define	CRYP_IV1LR_IV82		(0x1u<<13)
#define	CRYP_IV1LR_IV83		(0x1u<<12)
#define	CRYP_IV1LR_IV84		(0x1u<<11)
#define	CRYP_IV1LR_IV85		(0x1u<<10)
#define	CRYP_IV1LR_IV86		(0x1u<<9)
#define	CRYP_IV1LR_IV87		(0x1u<<8)
#define	CRYP_IV1LR_IV88		(0x1u<<7)
#define	CRYP_IV1LR_IV89		(0x1u<<6)
#define	CRYP_IV1LR_IV90		(0x1u<<5)
#define	CRYP_IV1LR_IV91		(0x1u<<4)
#define	CRYP_IV1LR_IV92		(0x1u<<3)
#define	CRYP_IV1LR_IV93		(0x1u<<2)
#define	CRYP_IV1LR_IV94		(0x1u<<1)
#define	CRYP_IV1LR_IV95		(0x1u<<0)

// IV1RR Configuration

#define	CRYP_IV1RR_IV96		(0x1u<<31)
#define	CRYP_IV1RR_IV97		(0x1u<<30)
#define	CRYP_IV1RR_IV98		(0x1u<<29)
#define	CRYP_IV1RR_IV99		(0x1u<<28)
#define	CRYP_IV1RR_IV100	(0x1u<<27)
#define	CRYP_IV1RR_IV101	(0x1u<<26)
#define	CRYP_IV1RR_IV102	(0x1u<<25)
#define	CRYP_IV1RR_IV103	(0x1u<<24)
#define	CRYP_IV1RR_IV104	(0x1u<<23)
#define	CRYP_IV1RR_IV105	(0x1u<<22)
#define	CRYP_IV1RR_IV106	(0x1u<<21)
#define	CRYP_IV1RR_IV107	(0x1u<<20)
#define	CRYP_IV1RR_IV108	(0x1u<<19)
#define	CRYP_IV1RR_IV109	(0x1u<<18)
#define	CRYP_IV1RR_IV110	(0x1u<<17)
#define	CRYP_IV1RR_IV111	(0x1u<<16)
#define	CRYP_IV1RR_IV112	(0x1u<<15)
#define	CRYP_IV1RR_IV113	(0x1u<<14)
#define	CRYP_IV1RR_IV114	(0x1u<<13)
#define	CRYP_IV1RR_IV115	(0x1u<<12)
#define	CRYP_IV1RR_IV116	(0x1u<<11)
#define	CRYP_IV1RR_IV117	(0x1u<<10)
#define	CRYP_IV1RR_IV118	(0x1u<<9)
#define	CRYP_IV1RR_IV119	(0x1u<<8)
#define	CRYP_IV1RR_IV120	(0x1u<<7)
#define	CRYP_IV1RR_IV121	(0x1u<<6)
#define	CRYP_IV1RR_IV122	(0x1u<<5)
#define	CRYP_IV1RR_IV123	(0x1u<<4)
#define	CRYP_IV1RR_IV124	(0x1u<<3)
#define	CRYP_IV1RR_IV125	(0x1u<<2)
#define	CRYP_IV1RR_IV126	(0x1u<<1)
#define	CRYP_IV1RR_IV127	(0x1u<<0)
