/*
; stm32H757_CM7_flash.
; ====================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32H757_CM7_flash equates.
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
	volatile	uint32_t	KEYR1;
	volatile	uint32_t	OPTKEYR;
	volatile	uint32_t	CR1;
	volatile	uint32_t	SR1;
	volatile	uint32_t	CCR1;
	volatile	uint32_t	OPTCR;
	volatile	uint32_t	OPTSR_CUR;
	volatile	uint32_t	OPTSR_PRG;
	volatile	uint32_t	OPTCCR;
	volatile	uint32_t	PRAR_CUR1;
		union {
	volatile	uint32_t	PRAR_PRG1;
	volatile	uint32_t	PRAR_PRG2;
		};
	volatile	uint32_t	SCAR_CUR1;
	volatile	uint32_t	SCAR_PRG1;
	volatile	uint32_t	WPSN_CUR1R;
	volatile	uint32_t	WPSN_PRG1R;
	volatile	uint32_t	BOOT_CURR;
	volatile	uint32_t	BOOT_PRGR;
	volatile	uint32_t	RESERVED0[2];
	volatile	uint32_t	CRCCR1;
	volatile	uint32_t	CRCSADD1R;
	volatile	uint32_t	CRCEADD1R;
	volatile	uint32_t	CRCDATAR;
	volatile	uint32_t	ECC_FA1R;
	volatile	uint32_t	RESERVED1[39];
	volatile	uint32_t	ACR_;
	volatile	uint32_t	KEYR2;
	volatile	uint32_t	OPTKEYR_;
	volatile	uint32_t	CR2;
	volatile	uint32_t	SR2;
	volatile	uint32_t	CCR2;
	volatile	uint32_t	OPTCR_;
	volatile	uint32_t	OPTSR_CUR_;
	volatile	uint32_t	OPTSR_PRG_;
	volatile	uint32_t	OPTCCR_;
	volatile	uint32_t	PRAR_CUR2;
	volatile	uint32_t	RESERVED2;
	volatile	uint32_t	SCAR_CUR2;
	volatile	uint32_t	SCAR_PRG2;
	volatile	uint32_t	WPSN_CUR2R;
	volatile	uint32_t	WPSN_PRG2R;
	volatile	uint32_t	RESERVED3[4];
	volatile	uint32_t	CRCCR2;
	volatile	uint32_t	CRCSADD2R;
	volatile	uint32_t	CRCEADD2R;
	volatile	uint32_t	RESERVED4;
	volatile	uint32_t	ECC_FA2R;
} FLASH_TypeDef;

#if (defined(__cplusplus))
#define	FLASH	reinterpret_cast<FLASH_TypeDef *>(0x52002000u)

#else
#define	FLASH	((FLASH_TypeDef *)0x52002000u)
#endif

// ACR Configuration

#define	FLASH_ACR_WRHIGHFREQ				(0x3u<<4)
#define	FLASH_ACR_WRHIGHFREQ_0				(0x1u<<4)
#define	FLASH_ACR_LATENCY					(0x7u<<0)
#define	FLASH_ACR_LATENCY_0					(0x1u<<0)

// KEYR1 Configuration

#define	FLASH_KEYR1_KEYR1					(0xFFFFFFFFu<<0)
#define	FLASH_KEYR1_KEYR1_0					(0x1u<<0)

// OPTKEYR Configuration

#define	FLASH_OPTKEYR_OPTKEYR				(0xFFFFFFFFu<<0)
#define	FLASH_OPTKEYR_OPTKEYR_0				(0x1u<<0)

// CR1 Configuration

#define	FLASH_CR1_CRCENDIE1					(0x1u<<27)
#define	FLASH_CR1_DBECCERRIE1				(0x1u<<26)
#define	FLASH_CR1_SNECCERRIE1				(0x1u<<25)
#define	FLASH_CR1_RDSERRIE1					(0x1u<<24)
#define	FLASH_CR1_RDPERRIE1					(0x1u<<23)
#define	FLASH_CR1_OPERRIE1					(0x1u<<22)
#define	FLASH_CR1_INCERRIE1					(0x1u<<21)
#define	FLASH_CR1_STRBERRIE1				(0x1u<<19)
#define	FLASH_CR1_PGSERRIE1					(0x1u<<18)
#define	FLASH_CR1_WRPERRIE1					(0x1u<<17)
#define	FLASH_CR1_EOPIE1					(0x1u<<16)
#define	FLASH_CR1_CRC_EN					(0x1u<<15)
#define	FLASH_CR1_SNB1						(0x7u<<8)
#define	FLASH_CR1_SNB1_0					(0x1u<<8)
#define	FLASH_CR1_START1					(0x1u<<7)
#define	FLASH_CR1_FW1						(0x1u<<6)
#define	FLASH_CR1_PSIZE1					(0x3u<<4)
#define	FLASH_CR1_PSIZE1_0					(0x1u<<4)
#define	FLASH_CR1_BER1						(0x1u<<3)
#define	FLASH_CR1_SER1						(0x1u<<2)
#define	FLASH_CR1_PG1						(0x1u<<1)
#define	FLASH_CR1_LOCK1						(0x1u<<0)

// SR1 Configuration

#define	FLASH_SR1_CRCEND1					(0x1u<<27)
#define	FLASH_SR1_DBECCERR1					(0x1u<<26)
#define	FLASH_SR1_SNECCERR11				(0x1u<<25)
#define	FLASH_SR1_RDSERR1					(0x1u<<24)
#define	FLASH_SR1_RDPERR1					(0x1u<<23)
#define	FLASH_SR1_OPERR1					(0x1u<<22)
#define	FLASH_SR1_INCERR1					(0x1u<<21)
#define	FLASH_SR1_STRBERR1					(0x1u<<19)
#define	FLASH_SR1_PGSERR1					(0x1u<<18)
#define	FLASH_SR1_WRPERR1					(0x1u<<17)
#define	FLASH_SR1_EOP1						(0x1u<<16)
#define	FLASH_SR1_CRC_BUSY1					(0x1u<<3)
#define	FLASH_SR1_QW1						(0x1u<<2)
#define	FLASH_SR1_WBNE1						(0x1u<<1)
#define	FLASH_SR1_BSY1						(0x1u<<0)

// CCR1 Configuration

#define	FLASH_CCR1_CLR_CRCEND1				(0x1u<<27)
#define	FLASH_CCR1_CLR_DBECCERR1			(0x1u<<26)
#define	FLASH_CCR1_CLR_SNECCERR1			(0x1u<<25)
#define	FLASH_CCR1_CLR_RDSERR1				(0x1u<<24)
#define	FLASH_CCR1_CLR_RDPERR1				(0x1u<<23)
#define	FLASH_CCR1_CLR_OPERR1				(0x1u<<22)
#define	FLASH_CCR1_CLR_INCERR1				(0x1u<<21)
#define	FLASH_CCR1_CLR_STRBERR1				(0x1u<<19)
#define	FLASH_CCR1_CLR_PGSERR1				(0x1u<<18)
#define	FLASH_CCR1_CLR_WRPERR1				(0x1u<<17)
#define	FLASH_CCR1_CLR_EOP1					(0x1u<<16)

// OPTCR Configuration

#define	FLASH_OPTCR_SWAP_BANK				(0x1u<<31)
#define	FLASH_OPTCR_OPTCHANGEERRIE			(0x1u<<30)
#define	FLASH_OPTCR_MER						(0x1u<<4)
#define	FLASH_OPTCR_OPTSTART				(0x1u<<1)
#define	FLASH_OPTCR_OPTLOCK					(0x1u<<0)

// OPTSR_CUR Configuration

#define	FLASH_OPTSR_CUR_SWAP_BANK_OPT		(0x1u<<31)
#define	FLASH_OPTSR_CUR_OPTCHANGEERR		(0x1u<<30)
#define	FLASH_OPTSR_CUR_IO_HSLV				(0x1u<<29)
#define	FLASH_OPTSR_CUR_PERSO_OK			(0x1u<<28)
#define	FLASH_OPTSR_CUR_RSS1				(0x1u<<26)
#define	FLASH_OPTSR_CUR_SECURITY			(0x1u<<21)
#define	FLASH_OPTSR_CUR_ST_RAM_SIZE			(0x3u<<19)
#define	FLASH_OPTSR_CUR_ST_RAM_SIZE_0		(0x1u<<19)
#define	FLASH_OPTSR_CUR_FZ_IWDG_SDBY		(0x1u<<18)
#define	FLASH_OPTSR_CUR_FZ_IWDG_STOP		(0x1u<<17)
#define	FLASH_OPTSR_CUR_RDP					(0xFFu<<8)
#define	FLASH_OPTSR_CUR_RDP_0				(0x1u<<8)
#define	FLASH_OPTSR_CUR_NRST_STBY_D1		(0x1u<<7)
#define	FLASH_OPTSR_CUR_NRST_STOP_D1		(0x1u<<6)
#define	FLASH_OPTSR_CUR_IWDG1_HW			(0x1u<<4)
#define	FLASH_OPTSR_CUR_BOR_LEV				(0x3u<<2)
#define	FLASH_OPTSR_CUR_BOR_LEV_0			(0x1u<<2)
#define	FLASH_OPTSR_CUR_OPT_BUSY			(0x1u<<0)

// OPTSR_PRG Configuration

#define	FLASH_OPTSR_PRG_SWAP_BANK_OPT		(0x1u<<31)
#define	FLASH_OPTSR_PRG_IO_HSLV				(0x1u<<29)
#define	FLASH_OPTSR_PRG_RSS2				(0x1u<<27)
#define	FLASH_OPTSR_PRG_RSS1				(0x1u<<26)
#define	FLASH_OPTSR_PRG_SECURITY			(0x1u<<21)
#define	FLASH_OPTSR_PRG_ST_RAM_SIZE			(0x3u<<19)
#define	FLASH_OPTSR_PRG_ST_RAM_SIZE_0		(0x1u<<19)
#define	FLASH_OPTSR_PRG_FZ_IWDG_SDBY		(0x1u<<18)
#define	FLASH_OPTSR_PRG_FZ_IWDG_STOP		(0x1u<<17)
#define	FLASH_OPTSR_PRG_RDP					(0xFFu<<8)
#define	FLASH_OPTSR_PRG_RDP_0				(0x1u<<8)
#define	FLASH_OPTSR_PRG_NRST_STBY_D1		(0x1u<<7)
#define	FLASH_OPTSR_PRG_NRST_STOP_D1		(0x1u<<6)
#define	FLASH_OPTSR_PRG_IWDG1_HW			(0x1u<<4)
#define	FLASH_OPTSR_PRG_BOR_LEV				(0x3u<<2)
#define	FLASH_OPTSR_PRG_BOR_LEV_0			(0x1u<<2)

// OPTCCR Configuration

#define	FLASH_OPTCCR_CLR_OPTCHANGEERR		(0x1u<<30)

// PRAR_CUR1 Configuration

#define	FLASH_PRAR_CUR1_DMEP1				(0x1u<<31)
#define	FLASH_PRAR_CUR1_PROT_AREA_END1		(0xFFFu<<16)
#define	FLASH_PRAR_CUR1_PROT_AREA_END1_0	(0x1u<<16)
#define	FLASH_PRAR_CUR1_PROT_AREA_START1	(0xFFFu<<0)
#define	FLASH_PRAR_CUR1_PROT_AREA_START1_0	(0x1u<<0)

// PRAR_PRG1 Configuration

#define	FLASH_PRAR_PRG1_DMEP1				(0x1u<<31)
#define	FLASH_PRAR_PRG1_PROT_AREA_END1		(0xFFFu<<16)
#define	FLASH_PRAR_PRG1_PROT_AREA_END1_0	(0x1u<<16)
#define	FLASH_PRAR_PRG1_PROT_AREA_START1	(0xFFFu<<0)
#define	FLASH_PRAR_PRG1_PROT_AREA_START1_0	(0x1u<<0)

// PRAR_PRG2 Configuration

#define	FLASH_PRAR_PRG2_DMEP2				(0x1u<<31)
#define	FLASH_PRAR_PRG2_PROT_AREA_END2		(0xFFFu<<16)
#define	FLASH_PRAR_PRG2_PROT_AREA_END2_0	(0x1u<<16)
#define	FLASH_PRAR_PRG2_PROT_AREA_START2	(0xFFFu<<0)
#define	FLASH_PRAR_PRG2_PROT_AREA_START2_0	(0x1u<<0)

// SCAR_CUR1 Configuration

#define	FLASH_SCAR_CUR1_DMES1				(0x1u<<31)
#define	FLASH_SCAR_CUR1_SEC_AREA_END1		(0xFFFu<<16)
#define	FLASH_SCAR_CUR1_SEC_AREA_END1_0		(0x1u<<16)
#define	FLASH_SCAR_CUR1_SEC_AREA_START1		(0xFFFu<<0)
#define	FLASH_SCAR_CUR1_SEC_AREA_START1_0	(0x1u<<0)

// SCAR_PRG1 Configuration

#define	FLASH_SCAR_PRG1_DMES1				(0x1u<<31)
#define	FLASH_SCAR_PRG1_SEC_AREA_END1		(0xFFFu<<16)
#define	FLASH_SCAR_PRG1_SEC_AREA_END1_0		(0x1u<<16)
#define	FLASH_SCAR_PRG1_SEC_AREA_START1		(0xFFFu<<0)
#define	FLASH_SCAR_PRG1_SEC_AREA_START1_0	(0x1u<<0)

// WPSN_CUR1R Configuration

#define	FLASH_WPSN_CUR1R_WRPSN1				(0xFFu<<0)
#define	FLASH_WPSN_CUR1R_WRPSN1_0			(0x1u<<0)

// WPSN_PRG1R Configuration

#define	FLASH_WPSN_PRG1R_WRPSN1				(0xFFu<<0)
#define	FLASH_WPSN_PRG1R_WRPSN1_0			(0x1u<<0)

// BOOT_CURR Configuration

#define	FLASH_BOOT_CURR_BOOT_ADD1			(0xFFFFu<<16)
#define	FLASH_BOOT_CURR_BOOT_ADD1_0			(0x1u<<16)
#define	FLASH_BOOT_CURR_BOOT_ADD0			(0xFFFFu<<0)
#define	FLASH_BOOT_CURR_BOOT_ADD0_0			(0x1u<<0)

// BOOT_PRGR Configuration

#define	FLASH_BOOT_PRGR_BOOT_ADD1			(0xFFFFu<<16)
#define	FLASH_BOOT_PRGR_BOOT_ADD1_0			(0x1u<<16)
#define	FLASH_BOOT_PRGR_BOOT_ADD0			(0xFFFFu<<0)
#define	FLASH_BOOT_PRGR_BOOT_ADD0_0			(0x1u<<0)

// CRCCR1 Configuration

#define	FLASH_CRCCR1_CRC_BURST				(0x3u<<20)
#define	FLASH_CRCCR1_CRC_BURST_0			(0x1u<<20)
#define	FLASH_CRCCR1_CLEAN_CRC				(0x1u<<17)
#define	FLASH_CRCCR1_START_CRC				(0x1u<<16)
#define	FLASH_CRCCR1_CLEAN_SECT				(0x1u<<10)
#define	FLASH_CRCCR1_ADD_SECT				(0x1u<<9)
#define	FLASH_CRCCR1_CRC_BY_SECT			(0x1u<<8)
#define	FLASH_CRCCR1_ALL_BANK				(0x1u<<7)
#define	FLASH_CRCCR1_CRC_SECT				(0x7u<<0)
#define	FLASH_CRCCR1_CRC_SECT_0				(0x1u<<0)

// CRCSADD1R Configuration

#define	FLASH_CRCSADD1R_CRC_START_ADDR		(0xFFFFFFFFu<<0)
#define	FLASH_CRCSADD1R_CRC_START_ADDR_0	(0x1u<<0)

// CRCEADD1R Configuration

#define	FLASH_CRCEADD1R_CRC_END_ADDR		(0xFFFFFFFFu<<0)
#define	FLASH_CRCEADD1R_CRC_END_ADDR_0		(0x1u<<0)

// CRCDATAR Configuration

#define	FLASH_CRCDATAR_CRC_DATA				(0xFFFFFFFFu<<0)
#define	FLASH_CRCDATAR_CRC_DATA_0			(0x1u<<0)

// ECC_FA1R Configuration

#define	FLASH_ECC_FA1R_FAIL_ECC_ADDR1		(0x7FFFu<<0)
#define	FLASH_ECC_FA1R_FAIL_ECC_ADDR1_0		(0x1u<<0)

// ACR_ Configuration

#define	FLASH_ACR__WRHIGHFREQ				(0x3u<<4)
#define	FLASH_ACR__WRHIGHFREQ_0				(0x1u<<4)
#define	FLASH_ACR__LATENCY					(0x7u<<0)
#define	FLASH_ACR__LATENCY_0				(0x1u<<0)

// KEYR2 Configuration

#define	FLASH_KEYR2_KEYR2					(0xFFFFFFFFu<<0)
#define	FLASH_KEYR2_KEYR2_0					(0x1u<<0)

// OPTKEYR_ Configuration

#define	FLASH_OPTKEYR__OPTKEYR				(0xFFFFFFFFu<<0)
#define	FLASH_OPTKEYR__OPTKEYR_0			(0x1u<<0)

// CR2 Configuration

#define	FLASH_CR2_CRCENDIE2					(0x1u<<27)
#define	FLASH_CR2_DBECCERRIE2				(0x1u<<26)
#define	FLASH_CR2_SNECCERRIE2				(0x1u<<25)
#define	FLASH_CR2_RDSERRIE2					(0x1u<<24)
#define	FLASH_CR2_RDPERRIE2					(0x1u<<23)
#define	FLASH_CR2_OPERRIE2					(0x1u<<22)
#define	FLASH_CR2_INCERRIE2					(0x1u<<21)
#define	FLASH_CR2_STRBERRIE2				(0x1u<<19)
#define	FLASH_CR2_PGSERRIE2					(0x1u<<18)
#define	FLASH_CR2_WRPERRIE2					(0x1u<<17)
#define	FLASH_CR2_EOPIE2					(0x1u<<16)
#define	FLASH_CR2_CRC_EN					(0x1u<<15)
#define	FLASH_CR2_SNB2						(0x7u<<8)
#define	FLASH_CR2_SNB2_0					(0x1u<<8)
#define	FLASH_CR2_START2					(0x1u<<7)
#define	FLASH_CR2_FW2						(0x1u<<6)
#define	FLASH_CR2_PSIZE2					(0x3u<<4)
#define	FLASH_CR2_PSIZE2_0					(0x1u<<4)
#define	FLASH_CR2_BER2						(0x1u<<3)
#define	FLASH_CR2_SER2						(0x1u<<2)
#define	FLASH_CR2_PG2						(0x1u<<1)
#define	FLASH_CR2_LOCK2						(0x1u<<0)

// SR2 Configuration

#define	FLASH_SR2_CRCEND2					(0x1u<<27)
#define	FLASH_SR2_DBECCERR2					(0x1u<<26)
#define	FLASH_SR2_SNECCERR2					(0x1u<<25)
#define	FLASH_SR2_RDSERR2					(0x1u<<24)
#define	FLASH_SR2_RDPERR2					(0x1u<<23)
#define	FLASH_SR2_OPERR2					(0x1u<<22)
#define	FLASH_SR2_INCERR2					(0x1u<<21)
#define	FLASH_SR2_STRBERR2					(0x1u<<19)
#define	FLASH_SR2_PGSERR2					(0x1u<<18)
#define	FLASH_SR2_WRPERR2					(0x1u<<17)
#define	FLASH_SR2_EOP2						(0x1u<<16)
#define	FLASH_SR2_CRC_BUSY2					(0x1u<<3)
#define	FLASH_SR2_QW2						(0x1u<<2)
#define	FLASH_SR2_WBNE2						(0x1u<<1)
#define	FLASH_SR2_BSY2						(0x1u<<0)

// CCR2 Configuration

#define	FLASH_CCR2_CLR_CRCEND2				(0x1u<<27)
#define	FLASH_CCR2_CLR_DBECCERR1			(0x1u<<26)
#define	FLASH_CCR2_CLR_SNECCERR2			(0x1u<<25)
#define	FLASH_CCR2_CLR_RDSERR1				(0x1u<<24)
#define	FLASH_CCR2_CLR_RDPERR2				(0x1u<<23)
#define	FLASH_CCR2_CLR_OPERR2				(0x1u<<22)
#define	FLASH_CCR2_CLR_INCERR2				(0x1u<<21)
#define	FLASH_CCR2_CLR_STRBERR2				(0x1u<<19)
#define	FLASH_CCR2_CLR_PGSERR2				(0x1u<<18)
#define	FLASH_CCR2_CLR_WRPERR2				(0x1u<<17)
#define	FLASH_CCR2_CLR_EOP2					(0x1u<<16)

// OPTCR_ Configuration

#define	FLASH_OPTCR__SWAP_BANK				(0x1u<<31)
#define	FLASH_OPTCR__OPTCHANGEERRIE			(0x1u<<30)
#define	FLASH_OPTCR__MER					(0x1u<<4)
#define	FLASH_OPTCR__OPTSTART				(0x1u<<1)
#define	FLASH_OPTCR__OPTLOCK				(0x1u<<0)

// OPTSR_CUR_ Configuration

#define	FLASH_OPTSR_CUR__SWAP_BANK_OPT		(0x1u<<31)
#define	FLASH_OPTSR_CUR__OPTCHANGEERR		(0x1u<<30)
#define	FLASH_OPTSR_CUR__IO_HSLV			(0x1u<<29)
#define	FLASH_OPTSR_CUR__PERSO_OK			(0x1u<<28)
#define	FLASH_OPTSR_CUR__RSS1				(0x1u<<26)
#define	FLASH_OPTSR_CUR__SECURITY			(0x1u<<21)
#define	FLASH_OPTSR_CUR__ST_RAM_SIZE		(0x3u<<19)
#define	FLASH_OPTSR_CUR__ST_RAM_SIZE_0		(0x1u<<19)
#define	FLASH_OPTSR_CUR__FZ_IWDG_SDBY		(0x1u<<18)
#define	FLASH_OPTSR_CUR__FZ_IWDG_STOP		(0x1u<<17)
#define	FLASH_OPTSR_CUR__RDP				(0xFFu<<8)
#define	FLASH_OPTSR_CUR__RDP_0				(0x1u<<8)
#define	FLASH_OPTSR_CUR__NRST_STBY_D1		(0x1u<<7)
#define	FLASH_OPTSR_CUR__NRST_STOP_D1		(0x1u<<6)
#define	FLASH_OPTSR_CUR__IWDG1_HW			(0x1u<<4)
#define	FLASH_OPTSR_CUR__BOR_LEV			(0x3u<<2)
#define	FLASH_OPTSR_CUR__BOR_LEV_0			(0x1u<<2)
#define	FLASH_OPTSR_CUR__OPT_BUSY			(0x1u<<0)

// OPTSR_PRG_ Configuration

#define	FLASH_OPTSR_PRG__SWAP_BANK_OPT		(0x1u<<31)
#define	FLASH_OPTSR_PRG__IO_HSLV			(0x1u<<29)
#define	FLASH_OPTSR_PRG__RSS2				(0x1u<<27)
#define	FLASH_OPTSR_PRG__RSS1				(0x1u<<26)
#define	FLASH_OPTSR_PRG__SECURITY			(0x1u<<21)
#define	FLASH_OPTSR_PRG__ST_RAM_SIZE		(0x3u<<19)
#define	FLASH_OPTSR_PRG__ST_RAM_SIZE_0		(0x1u<<19)
#define	FLASH_OPTSR_PRG__FZ_IWDG_SDBY		(0x1u<<18)
#define	FLASH_OPTSR_PRG__FZ_IWDG_STOP		(0x1u<<17)
#define	FLASH_OPTSR_PRG__RDP				(0xFFu<<8)
#define	FLASH_OPTSR_PRG__RDP_0				(0x1u<<8)
#define	FLASH_OPTSR_PRG__NRST_STBY_D1		(0x1u<<7)
#define	FLASH_OPTSR_PRG__NRST_STOP_D1		(0x1u<<6)
#define	FLASH_OPTSR_PRG__IWDG1_HW			(0x1u<<4)
#define	FLASH_OPTSR_PRG__BOR_LEV			(0x3u<<2)
#define	FLASH_OPTSR_PRG__BOR_LEV_0			(0x1u<<2)

// OPTCCR_ Configuration

#define	FLASH_OPTCCR__CLR_OPTCHANGEERR		(0x1u<<30)

// PRAR_CUR2 Configuration

#define	FLASH_PRAR_CUR2_DMEP2				(0x1u<<31)
#define	FLASH_PRAR_CUR2_PROT_AREA_END2		(0xFFFu<<16)
#define	FLASH_PRAR_CUR2_PROT_AREA_END2_0	(0x1u<<16)
#define	FLASH_PRAR_CUR2_PROT_AREA_START2	(0xFFFu<<0)
#define	FLASH_PRAR_CUR2_PROT_AREA_START2_0	(0x1u<<0)

// SCAR_CUR2 Configuration

#define	FLASH_SCAR_CUR2_DMES2				(0x1u<<31)
#define	FLASH_SCAR_CUR2_SEC_AREA_END2		(0xFFFu<<16)
#define	FLASH_SCAR_CUR2_SEC_AREA_END2_0		(0x1u<<16)
#define	FLASH_SCAR_CUR2_SEC_AREA_START2		(0xFFFu<<0)
#define	FLASH_SCAR_CUR2_SEC_AREA_START2_0	(0x1u<<0)

// SCAR_PRG2 Configuration

#define	FLASH_SCAR_PRG2_DMES2				(0x1u<<31)
#define	FLASH_SCAR_PRG2_SEC_AREA_END2		(0xFFFu<<16)
#define	FLASH_SCAR_PRG2_SEC_AREA_END2_0		(0x1u<<16)
#define	FLASH_SCAR_PRG2_SEC_AREA_START2		(0xFFFu<<0)
#define	FLASH_SCAR_PRG2_SEC_AREA_START2_0	(0x1u<<0)

// WPSN_CUR2R Configuration

#define	FLASH_WPSN_CUR2R_WRPSN2				(0xFFu<<0)
#define	FLASH_WPSN_CUR2R_WRPSN2_0			(0x1u<<0)

// WPSN_PRG2R Configuration

#define	FLASH_WPSN_PRG2R_WRPSN2				(0xFFu<<0)
#define	FLASH_WPSN_PRG2R_WRPSN2_0			(0x1u<<0)

// CRCCR2 Configuration

#define	FLASH_CRCCR2_CRC_BURST				(0x3u<<20)
#define	FLASH_CRCCR2_CRC_BURST_0			(0x1u<<20)
#define	FLASH_CRCCR2_CLEAN_CRC				(0x1u<<17)
#define	FLASH_CRCCR2_START_CRC				(0x1u<<16)
#define	FLASH_CRCCR2_CLEAN_SECT				(0x1u<<10)
#define	FLASH_CRCCR2_ADD_SECT				(0x1u<<9)
#define	FLASH_CRCCR2_CRC_BY_SECT			(0x1u<<8)
#define	FLASH_CRCCR2_ALL_BANK				(0x1u<<7)
#define	FLASH_CRCCR2_CRC_SECT				(0x7u<<0)
#define	FLASH_CRCCR2_CRC_SECT_0				(0x1u<<0)

// CRCSADD2R Configuration

#define	FLASH_CRCSADD2R_CRC_START_ADDR		(0xFFFFFFFFu<<0)
#define	FLASH_CRCSADD2R_CRC_START_ADDR_0	(0x1u<<0)

// CRCEADD2R Configuration

#define	FLASH_CRCEADD2R_CRC_END_ADDR		(0xFFFFFFFFu<<0)
#define	FLASH_CRCEADD2R_CRC_END_ADDR_0		(0x1u<<0)

// ECC_FA2R Configuration

#define	FLASH_ECC_FA2R_FAIL_ECC_ADDR2		(0x7FFFu<<0)
#define	FLASH_ECC_FA2R_FAIL_ECC_ADDR2_0		(0x1u<<0)
