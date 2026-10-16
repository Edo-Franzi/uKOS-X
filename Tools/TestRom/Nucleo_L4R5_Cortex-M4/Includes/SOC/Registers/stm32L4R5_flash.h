/*
; stm32L4R5_flash.
; ================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32L4R5_flash equates.
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

// FLASH address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	ACR;
	volatile	uint32_t	PDKEYR;
	volatile	uint32_t	KEYR;
	volatile	uint32_t	OPTKEYR;
	volatile	uint32_t	SR;
	volatile	uint32_t	CR;
	volatile	uint32_t	ECCR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	OPTR;
	volatile	uint32_t	PCROP1SR;
	volatile	uint32_t	PCROP1ER;
	volatile	uint32_t	WRP1AR;
	volatile	uint32_t	WRP2AR;
	volatile	uint32_t	RESERVED1[4];
	volatile	uint32_t	PCROP2SR;
	volatile	uint32_t	PCROP2ER;
	volatile	uint32_t	WRP1BR;
	volatile	uint32_t	WRP2BR;
	volatile	uint32_t	RESERVED2[55];
	volatile	uint32_t	CFGR;
} FLASH_TypeDef;

#if (defined(__cplusplus))
#define	FLASH	reinterpret_cast<FLASH_TypeDef *>(0x40022000u)

#else
#define	FLASH	((FLASH_TypeDef *)0x40022000u)
#endif

// ACR Configuration

#define	FLASH_ACR_SLEEP_PD				(0x1u<<14)
#define	FLASH_ACR_RUN_PD				(0x1u<<13)
#define	FLASH_ACR_DCRST					(0x1u<<12)
#define	FLASH_ACR_ICRST					(0x1u<<11)
#define	FLASH_ACR_DCEN					(0x1u<<10)
#define	FLASH_ACR_ICEN					(0x1u<<9)
#define	FLASH_ACR_PRFTEN				(0x1u<<8)
#define	FLASH_ACR_LATENCY				(0xFu<<0)
#define	FLASH_ACR_LATENCY_0				(0x1u<<0)

// PDKEYR Configuration

#define	FLASH_PDKEYR_PDKEYR				(0xFFFFFFFFu<<0)
#define	FLASH_PDKEYR_PDKEYR_0			(0x1u<<0)

// KEYR Configuration

#define	FLASH_KEYR_KEYR					(0xFFFFFFFFu<<0)
#define	FLASH_KEYR_KEYR_0				(0x1u<<0)

// OPTKEYR Configuration

#define	FLASH_OPTKEYR_OPTKEYR			(0xFFFFFFFFu<<0)
#define	FLASH_OPTKEYR_OPTKEYR_0			(0x1u<<0)

// SR Configuration

#define	FLASH_SR_PEMPTY					(0x1u<<17)
#define	FLASH_SR_BSY					(0x1u<<16)
#define	FLASH_SR_OPTVERR				(0x1u<<15)
#define	FLASH_SR_RDERR					(0x1u<<14)
#define	FLASH_SR_FASTERR				(0x1u<<9)
#define	FLASH_SR_MISERR					(0x1u<<8)
#define	FLASH_SR_PGSERR					(0x1u<<7)
#define	FLASH_SR_SIZERR					(0x1u<<6)
#define	FLASH_SR_PGAERR					(0x1u<<5)
#define	FLASH_SR_WRPERR					(0x1u<<4)
#define	FLASH_SR_PROGERR				(0x1u<<3)
#define	FLASH_SR_OPERR					(0x1u<<1)
#define	FLASH_SR_EOP					(0x1u<<0)

// CR Configuration

#define	FLASH_CR_LOCK					(0x1u<<31)
#define	FLASH_CR_OPTLOCK				(0x1u<<30)
#define	FLASH_CR_OBL_LAUNCH				(0x1u<<27)
#define	FLASH_CR_RDERRIE				(0x1u<<26)
#define	FLASH_CR_ERRIE					(0x1u<<25)
#define	FLASH_CR_EOPIE					(0x1u<<24)
#define	FLASH_CR_FSTPG					(0x1u<<18)
#define	FLASH_CR_OPTSTRT				(0x1u<<17)
#define	FLASH_CR_START					(0x1u<<16)
#define	FLASH_CR_MER2					(0x1u<<15)
#define	FLASH_CR_BKER					(0x1u<<11)
#define	FLASH_CR_PNB					(0xFFu<<3)
#define	FLASH_CR_PNB_0					(0x1u<<3)
#define	FLASH_CR_MER1					(0x1u<<2)
#define	FLASH_CR_PER					(0x1u<<1)
#define	FLASH_CR_PG						(0x1u<<0)

// ECCR Configuration

#define	FLASH_ECCR_ECCD					(0x1u<<31)
#define	FLASH_ECCR_ECCC					(0x1u<<30)
#define	FLASH_ECCR_ECCD2				(0x1u<<29)
#define	FLASH_ECCR_ECCC2				(0x1u<<28)
#define	FLASH_ECCR_ECCIE				(0x1u<<24)
#define	FLASH_ECCR_SYSF_ECC				(0x1u<<22)
#define	FLASH_ECCR_BK_ECC				(0x1u<<21)
#define	FLASH_ECCR_ADDR_ECC				(0x1FFFFFu<<0)
#define	FLASH_ECCR_ADDR_ECC_0			(0x1u<<0)

// OPTR Configuration

#define	FLASH_OPTR_NBOOT0				(0x1u<<27)
#define	FLASH_OPTR_NSWBOOT0				(0x1u<<26)
#define	FLASH_OPTR_SRAM2_RST			(0x1u<<25)
#define	FLASH_OPTR_SRAM2_PE				(0x1u<<24)
#define	FLASH_OPTR_NBOOT1				(0x1u<<23)
#define	FLASH_OPTR_DBANK				(0x1u<<22)
#define	FLASH_OPTR_DB1M					(0x1u<<21)
#define	FLASH_OPTR_BFB2					(0x1u<<20)
#define	FLASH_OPTR_WWDG_SW				(0x1u<<19)
#define	FLASH_OPTR_IWDG_STDBY			(0x1u<<18)
#define	FLASH_OPTR_IWDG_STOP			(0x1u<<17)
#define	FLASH_OPTR_IWDG_SW				(0x1u<<16)
#define	FLASH_OPTR_NRST_SHDW			(0x1u<<14)
#define	FLASH_OPTR_NRST_STDBY			(0x1u<<13)
#define	FLASH_OPTR_NRST_STOP			(0x1u<<12)
#define	FLASH_OPTR_BOR_LEV				(0x7u<<8)
#define	FLASH_OPTR_BOR_LEV_0			(0x1u<<8)
#define	FLASH_OPTR_RDP					(0xFFu<<0)
#define	FLASH_OPTR_RDP_0				(0x1u<<0)

// PCROP1SR Configuration

#define	FLASH_PCROP1SR_PCROP1_STRT		(0x1FFFFu<<0)
#define	FLASH_PCROP1SR_PCROP1_STRT_0	(0x1u<<0)

// PCROP1ER Configuration

#define	FLASH_PCROP1ER_PCROP_RDP		(0x1u<<31)
#define	FLASH_PCROP1ER_PCROP1_END		(0x1FFFFu<<0)
#define	FLASH_PCROP1ER_PCROP1_END_0		(0x1u<<0)

// WRP1AR Configuration

#define	FLASH_WRP1AR_WRP1A_END			(0xFFu<<16)
#define	FLASH_WRP1AR_WRP1A_END_0		(0x1u<<16)
#define	FLASH_WRP1AR_WRP1A_STRT			(0xFFu<<0)
#define	FLASH_WRP1AR_WRP1A_STRT_0		(0x1u<<0)

// WRP2AR Configuration

#define	FLASH_WRP2AR_WRP2A_STRT			(0xFFu<<0)
#define	FLASH_WRP2AR_WRP2A_STRT_0		(0x1u<<0)
#define	FLASH_WRP2AR_WRP2A_END			(0xFFu<<16)
#define	FLASH_WRP2AR_WRP2A_END_0		(0x1u<<16)

// PCROP2SR Configuration

#define	FLASH_PCROP2SR_PCROP2_STRT		(0x1FFFFu<<0)
#define	FLASH_PCROP2SR_PCROP2_STRT_0	(0x1u<<0)

// PCROP2ER Configuration

#define	FLASH_PCROP2ER_PCROP2_END		(0x1FFFFu<<0)
#define	FLASH_PCROP2ER_PCROP2_END_0		(0x1u<<0)

// WRP1BR Configuration

#define	FLASH_WRP1BR_WRP1B_END			(0xFFu<<16)
#define	FLASH_WRP1BR_WRP1B_END_0		(0x1u<<16)
#define	FLASH_WRP1BR_WRP1B_STRT			(0xFFu<<0)
#define	FLASH_WRP1BR_WRP1B_STRT_0		(0x1u<<0)

// WRP2BR Configuration

#define	FLASH_WRP2BR_WRP2B_END			(0xFFu<<16)
#define	FLASH_WRP2BR_WRP2B_END_0		(0x1u<<16)
#define	FLASH_WRP2BR_WRP2B_STRT			(0xFFu<<0)
#define	FLASH_WRP2BR_WRP2B_STRT_0		(0x1u<<0)

// CFGR Configuration

#define	FLASH_CFGR_LVEN					(0x1u<<0)
