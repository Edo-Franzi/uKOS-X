/*
; nrf5340_application_cti.
; ========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_cti equates.
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

// CTI address definitions
// -----------------------

typedef struct {
	volatile	uint32_t	CTICONTROL;
	volatile	uint32_t	RESERVED0[3];
	volatile	uint32_t	CTIINTACK;
	volatile	uint32_t	CTIAPPSET;
	volatile	uint32_t	CTIAPPCLEAR;
	volatile	uint32_t	CTIAPPPULSE;
	volatile	uint32_t	CTIINEN[8];
	volatile	uint32_t	RESERVED1[24];
	volatile	uint32_t	CTIOUTEN[8];
	volatile	uint32_t	RESERVED2[28];
	volatile	uint32_t	CTITRIGINSTATUS;
	volatile	uint32_t	CTITRIGOUTSTATUS;
	volatile	uint32_t	CTICHINSTATUS;
	volatile	uint32_t	RESERVED3;
	volatile	uint32_t	CTIGATE;
	volatile	uint32_t	RESERVED4[926];
	volatile	uint32_t	DEVARCH;
	volatile	uint32_t	RESERVED5[2];
	volatile	uint32_t	DEVID;
	volatile	uint32_t	DEVTYPE;
	volatile	uint32_t	PIDR4;
	volatile	uint32_t	PIDR5;
	volatile	uint32_t	PIDR6;
	volatile	uint32_t	PIDR7;
	volatile	uint32_t	PIDR0;
	volatile	uint32_t	PIDR1;
	volatile	uint32_t	PIDR2;
	volatile	uint32_t	PIDR3;
	volatile	uint32_t	CIDR0;
	volatile	uint32_t	CIDR1;
	volatile	uint32_t	CIDR2;
	volatile	uint32_t	CIDR3;
} CTI_TypeDef;

#if (defined(__cplusplus))
#define	CTI_S	reinterpret_cast<CTI_TypeDef *>(0xE0042000u)

#else
#define	CTI_S	((CTI_TypeDef *)0xE0042000u)
#endif

// CTICONTROL Configuration

#define	CTI_CTICONTROL_GLBEN						(0x1u<<0)
#define	CTI_CTICONTROL_GLBEN_DISABLED				(0x0u<<0)
#define	CTI_CTICONTROL_GLBEN_ENABLED				(0x1u<<0)

// CTIINTACK Configuration

#define	CTI_CTIINTACK_ETMEVTIN3						(0x1u<<7)
#define	CTI_CTIINTACK_ETMEVTIN2						(0x1u<<6)
#define	CTI_CTIINTACK_ETMEVTIN1						(0x1u<<5)
#define	CTI_CTIINTACK_ETMEVTIN0						(0x1u<<4)
#define	CTI_CTIINTACK_UNUSED1						(0x1u<<3)
#define	CTI_CTIINTACK_UNUSED0						(0x1u<<2)
#define	CTI_CTIINTACK_CPURESTART					(0x1u<<1)
#define	CTI_CTIINTACK_DEBUGREQ						(0x1u<<0)
#define	CTI_CTIINTACK_ETMEVTIN3_ACKNOWLEDGE			(0x1u<<7)
#define	CTI_CTIINTACK_ETMEVTIN2_ACKNOWLEDGE			(0x1u<<6)
#define	CTI_CTIINTACK_ETMEVTIN1_ACKNOWLEDGE			(0x1u<<5)
#define	CTI_CTIINTACK_ETMEVTIN0_ACKNOWLEDGE			(0x1u<<4)
#define	CTI_CTIINTACK_UNUSED1_ACKNOWLEDGE			(0x1u<<3)
#define	CTI_CTIINTACK_UNUSED0_ACKNOWLEDGE			(0x1u<<2)
#define	CTI_CTIINTACK_CPURESTART_ACKNOWLEDGE		(0x1u<<1)
#define	CTI_CTIINTACK_DEBUGREQ_ACKNOWLEDGE			(0x1u<<0)

// CTIAPPSET Configuration

#define	CTI_CTIAPPSET_APPSET_3						(0x1u<<3)
#define	CTI_CTIAPPSET_APPSET_2						(0x1u<<2)
#define	CTI_CTIAPPSET_APPSET_1						(0x1u<<1)
#define	CTI_CTIAPPSET_APPSET_0						(0x1u<<0)
#define	CTI_CTIAPPSET_APPSET_3_INACTIVE				(0x0u<<3)
#define	CTI_CTIAPPSET_APPSET_3_ACTIVE				(0x1u<<3)
#define	CTI_CTIAPPSET_APPSET_3_ACTIVATE				(0x1u<<3)
#define	CTI_CTIAPPSET_APPSET_2_INACTIVE				(0x0u<<2)
#define	CTI_CTIAPPSET_APPSET_2_ACTIVE				(0x1u<<2)
#define	CTI_CTIAPPSET_APPSET_2_ACTIVATE				(0x1u<<2)
#define	CTI_CTIAPPSET_APPSET_1_INACTIVE				(0x0u<<1)
#define	CTI_CTIAPPSET_APPSET_1_ACTIVE				(0x1u<<1)
#define	CTI_CTIAPPSET_APPSET_1_ACTIVATE				(0x1u<<1)
#define	CTI_CTIAPPSET_APPSET_0_INACTIVE				(0x0u<<0)
#define	CTI_CTIAPPSET_APPSET_0_ACTIVE				(0x1u<<0)
#define	CTI_CTIAPPSET_APPSET_0_ACTIVATE				(0x1u<<0)

// CTIAPPCLEAR Configuration

#define	CTI_CTIAPPCLEAR_APPCLEAR_3					(0x1u<<3)
#define	CTI_CTIAPPCLEAR_APPCLEAR_2					(0x1u<<2)
#define	CTI_CTIAPPCLEAR_APPCLEAR_1					(0x1u<<1)
#define	CTI_CTIAPPCLEAR_APPCLEAR_0					(0x1u<<0)
#define	CTI_CTIAPPCLEAR_APPCLEAR_3_CLEAR			(0x1u<<3)
#define	CTI_CTIAPPCLEAR_APPCLEAR_2_CLEAR			(0x1u<<2)
#define	CTI_CTIAPPCLEAR_APPCLEAR_1_CLEAR			(0x1u<<1)
#define	CTI_CTIAPPCLEAR_APPCLEAR_0_CLEAR			(0x1u<<0)

// CTIAPPPULSE Configuration

#define	CTI_CTIAPPPULSE_APPULSE_3					(0x1u<<3)
#define	CTI_CTIAPPPULSE_APPULSE_2					(0x1u<<2)
#define	CTI_CTIAPPPULSE_APPULSE_1					(0x1u<<1)
#define	CTI_CTIAPPPULSE_APPULSE_0					(0x1u<<0)
#define	CTI_CTIAPPPULSE_APPULSE_3_GENERATE			(0x1u<<3)
#define	CTI_CTIAPPPULSE_APPULSE_2_GENERATE			(0x1u<<2)
#define	CTI_CTIAPPPULSE_APPULSE_1_GENERATE			(0x1u<<1)
#define	CTI_CTIAPPPULSE_APPULSE_0_GENERATE			(0x1u<<0)

// CTIINEN Configuration

#define	CTI_CTIINEN_TRIGINEN_3						(0x1u<<3)
#define	CTI_CTIINEN_TRIGINEN_2						(0x1u<<2)
#define	CTI_CTIINEN_TRIGINEN_1						(0x1u<<1)
#define	CTI_CTIINEN_TRIGINEN_0						(0x1u<<0)
#define	CTI_CTIINEN_TRIGINEN_3_DISABLED				(0x0u<<3)
#define	CTI_CTIINEN_TRIGINEN_3_ENABLED				(0x1u<<3)
#define	CTI_CTIINEN_TRIGINEN_2_DISABLED				(0x0u<<2)
#define	CTI_CTIINEN_TRIGINEN_2_ENABLED				(0x1u<<2)
#define	CTI_CTIINEN_TRIGINEN_1_DISABLED				(0x0u<<1)
#define	CTI_CTIINEN_TRIGINEN_1_ENABLED				(0x1u<<1)
#define	CTI_CTIINEN_TRIGINEN_0_DISABLED				(0x0u<<0)
#define	CTI_CTIINEN_TRIGINEN_0_ENABLED				(0x1u<<0)

// CTIOUTEN Configuration

#define	CTI_CTIOUTEN_TRIGOUTEN_3					(0x1u<<3)
#define	CTI_CTIOUTEN_TRIGOUTEN_2					(0x1u<<2)
#define	CTI_CTIOUTEN_TRIGOUTEN_1					(0x1u<<1)
#define	CTI_CTIOUTEN_TRIGOUTEN_0					(0x1u<<0)
#define	CTI_CTIOUTEN_TRIGOUTEN_3_DISABLED			(0x0u<<3)
#define	CTI_CTIOUTEN_TRIGOUTEN_3_ENABLED			(0x1u<<3)
#define	CTI_CTIOUTEN_TRIGOUTEN_2_DISABLED			(0x0u<<2)
#define	CTI_CTIOUTEN_TRIGOUTEN_2_ENABLED			(0x1u<<2)
#define	CTI_CTIOUTEN_TRIGOUTEN_1_DISABLED			(0x0u<<1)
#define	CTI_CTIOUTEN_TRIGOUTEN_1_ENABLED			(0x1u<<1)
#define	CTI_CTIOUTEN_TRIGOUTEN_0_DISABLED			(0x0u<<0)
#define	CTI_CTIOUTEN_TRIGOUTEN_0_ENABLED			(0x1u<<0)

// CTITRIGINSTATUS Configuration

#define	CTI_CTITRIGINSTATUS_UNUSED1					(0x1u<<7)
#define	CTI_CTITRIGINSTATUS_UNUSED0					(0x1u<<6)
#define	CTI_CTITRIGINSTATUS_ETMEVTOUT1				(0x1u<<5)
#define	CTI_CTITRIGINSTATUS_ETMEVTOUT0				(0x1u<<4)
#define	CTI_CTITRIGINSTATUS_DWTCOMPOUT2				(0x1u<<3)
#define	CTI_CTITRIGINSTATUS_DWTCOMPOUT1				(0x1u<<2)
#define	CTI_CTITRIGINSTATUS_DWTCOMPOUT0				(0x1u<<1)
#define	CTI_CTITRIGINSTATUS_CPUHALTED				(0x1u<<0)
#define	CTI_CTITRIGINSTATUS_UNUSED1_ACTIVE			(0x1u<<7)
#define	CTI_CTITRIGINSTATUS_UNUSED1_INACTIVE		(0x0u<<7)
#define	CTI_CTITRIGINSTATUS_UNUSED0_ACTIVE			(0x1u<<6)
#define	CTI_CTITRIGINSTATUS_UNUSED0_INACTIVE		(0x0u<<6)
#define	CTI_CTITRIGINSTATUS_ETMEVTOUT1_ACTIVE		(0x1u<<5)
#define	CTI_CTITRIGINSTATUS_ETMEVTOUT1_INACTIVE		(0x0u<<5)
#define	CTI_CTITRIGINSTATUS_ETMEVTOUT0_ACTIVE		(0x1u<<4)
#define	CTI_CTITRIGINSTATUS_ETMEVTOUT0_INACTIVE		(0x0u<<4)
#define	CTI_CTITRIGINSTATUS_DWTCOMPOUT2_ACTIVE		(0x1u<<3)
#define	CTI_CTITRIGINSTATUS_DWTCOMPOUT2_INACTIVE	(0x0u<<3)
#define	CTI_CTITRIGINSTATUS_DWTCOMPOUT1_ACTIVE		(0x1u<<2)
#define	CTI_CTITRIGINSTATUS_DWTCOMPOUT1_INACTIVE	(0x0u<<2)
#define	CTI_CTITRIGINSTATUS_DWTCOMPOUT0_ACTIVE		(0x1u<<1)
#define	CTI_CTITRIGINSTATUS_DWTCOMPOUT0_INACTIVE	(0x0u<<1)
#define	CTI_CTITRIGINSTATUS_CPUHALTED_ACTIVE		(0x1u<<0)
#define	CTI_CTITRIGINSTATUS_CPUHALTED_INACTIVE		(0x0u<<0)

// CTITRIGOUTSTATUS Configuration

#define	CTI_CTITRIGOUTSTATUS_ETMEVTIN3				(0x1u<<7)
#define	CTI_CTITRIGOUTSTATUS_ETMEVTIN2				(0x1u<<6)
#define	CTI_CTITRIGOUTSTATUS_ETMEVTIN1				(0x1u<<5)
#define	CTI_CTITRIGOUTSTATUS_ETMEVTIN0				(0x1u<<4)
#define	CTI_CTITRIGOUTSTATUS_UNUSED1				(0x1u<<3)
#define	CTI_CTITRIGOUTSTATUS_UNUSED0				(0x1u<<2)
#define	CTI_CTITRIGOUTSTATUS_CPURESTART				(0x1u<<1)
#define	CTI_CTITRIGOUTSTATUS_DEBUGREQ				(0x1u<<0)
#define	CTI_CTITRIGOUTSTATUS_ETMEVTIN3_ACTIVE		(0x1u<<7)
#define	CTI_CTITRIGOUTSTATUS_ETMEVTIN3_INACTIVE		(0x0u<<7)
#define	CTI_CTITRIGOUTSTATUS_ETMEVTIN2_ACTIVE		(0x1u<<6)
#define	CTI_CTITRIGOUTSTATUS_ETMEVTIN2_INACTIVE		(0x0u<<6)
#define	CTI_CTITRIGOUTSTATUS_ETMEVTIN1_ACTIVE		(0x1u<<5)
#define	CTI_CTITRIGOUTSTATUS_ETMEVTIN1_INACTIVE		(0x0u<<5)
#define	CTI_CTITRIGOUTSTATUS_ETMEVTIN0_ACTIVE		(0x1u<<4)
#define	CTI_CTITRIGOUTSTATUS_ETMEVTIN0_INACTIVE		(0x0u<<4)
#define	CTI_CTITRIGOUTSTATUS_UNUSED1_ACTIVE			(0x1u<<3)
#define	CTI_CTITRIGOUTSTATUS_UNUSED1_INACTIVE		(0x0u<<3)
#define	CTI_CTITRIGOUTSTATUS_UNUSED0_ACTIVE			(0x1u<<2)
#define	CTI_CTITRIGOUTSTATUS_UNUSED0_INACTIVE		(0x0u<<2)
#define	CTI_CTITRIGOUTSTATUS_CPURESTART_ACTIVE		(0x1u<<1)
#define	CTI_CTITRIGOUTSTATUS_CPURESTART_INACTIVE	(0x0u<<1)
#define	CTI_CTITRIGOUTSTATUS_DEBUGREQ_ACTIVE		(0x1u<<0)
#define	CTI_CTITRIGOUTSTATUS_DEBUGREQ_INACTIVE		(0x0u<<0)

// CTICHINSTATUS Configuration

#define	CTI_CTICHINSTATUS_CTICHINSTATUS_3			(0x1u<<3)
#define	CTI_CTICHINSTATUS_CTICHINSTATUS_2			(0x1u<<2)
#define	CTI_CTICHINSTATUS_CTICHINSTATUS_1			(0x1u<<1)
#define	CTI_CTICHINSTATUS_CTICHINSTATUS_0			(0x1u<<0)
#define	CTI_CTICHINSTATUS_CTICHINSTATUS_3_ACTIVE	(0x1u<<3)
#define	CTI_CTICHINSTATUS_CTICHINSTATUS_3_INACTIVE	(0x0u<<3)
#define	CTI_CTICHINSTATUS_CTICHINSTATUS_2_ACTIVE	(0x1u<<2)
#define	CTI_CTICHINSTATUS_CTICHINSTATUS_2_INACTIVE	(0x0u<<2)
#define	CTI_CTICHINSTATUS_CTICHINSTATUS_1_ACTIVE	(0x1u<<1)
#define	CTI_CTICHINSTATUS_CTICHINSTATUS_1_INACTIVE	(0x0u<<1)
#define	CTI_CTICHINSTATUS_CTICHINSTATUS_0_ACTIVE	(0x1u<<0)
#define	CTI_CTICHINSTATUS_CTICHINSTATUS_0_INACTIVE	(0x0u<<0)

// CTIGATE Configuration

#define	CTI_CTIGATE_CTIGATEEN_3						(0x1u<<3)
#define	CTI_CTIGATE_CTIGATEEN_2						(0x1u<<2)
#define	CTI_CTIGATE_CTIGATEEN_1						(0x1u<<1)
#define	CTI_CTIGATE_CTIGATEEN_0						(0x1u<<0)
#define	CTI_CTIGATE_CTIGATEEN_3_ENABLED				(0x1u<<3)
#define	CTI_CTIGATE_CTIGATEEN_3_DISABLED			(0x0u<<3)
#define	CTI_CTIGATE_CTIGATEEN_2_ENABLED				(0x1u<<2)
#define	CTI_CTIGATE_CTIGATEEN_2_DISABLED			(0x0u<<2)
#define	CTI_CTIGATE_CTIGATEEN_1_ENABLED				(0x1u<<1)
#define	CTI_CTIGATE_CTIGATEEN_1_DISABLED			(0x0u<<1)
#define	CTI_CTIGATE_CTIGATEEN_0_ENABLED				(0x1u<<0)
#define	CTI_CTIGATE_CTIGATEEN_0_DISABLED			(0x0u<<0)

// DEVARCH Configuration

#define	CTI_DEVARCH_ARCHITECTURE					(0x1u<<0)

// DEVID Configuration

#define	CTI_DEVID_NUMCH								(0xFu<<16)
#define	CTI_DEVID_NUMCH_0							(0x1u<<16)
#define	CTI_DEVID_NUMTRIG							(0xFFu<<8)
#define	CTI_DEVID_NUMTRIG_0							(0x1u<<8)
#define	CTI_DEVID_EXTMUXNUM							(0x1Fu<<0)
#define	CTI_DEVID_EXTMUXNUM_0						(0x1u<<0)

// DEVTYPE Configuration

#define	CTI_DEVTYPE_SUB								(0xFu<<4)
#define	CTI_DEVTYPE_SUB_0							(0x1u<<4)
#define	CTI_DEVTYPE_MAJOR							(0xFu<<0)
#define	CTI_DEVTYPE_MAJOR_0							(0x1u<<0)
#define	CTI_DEVTYPE_SUB_CROSSTRIGGER				(0x1u<<4)
#define	CTI_DEVTYPE_MAJOR_CONTROLLER				(0x4u<<0)

// PIDR4 Configuration

#define	CTI_PIDR4_SIZE								(0xFu<<4)
#define	CTI_PIDR4_SIZE_0							(0x1u<<4)
#define	CTI_PIDR4_DES_2								(0xFu<<0)
#define	CTI_PIDR4_DES_2_0							(0x1u<<0)
#define	CTI_PIDR4_DES_2_CODE						(0x4u<<0)

// PIDR0 Configuration

#define	CTI_PIDR0_PART_0							(0xFFu<<0)
#define	CTI_PIDR0_PART_0_0							(0x1u<<0)
#define	CTI_PIDR0_PART_0_PARTNUMBERL				(0x21u<<0)

// PIDR1 Configuration

#define	CTI_PIDR1_DES_0								(0xFu<<4)
#define	CTI_PIDR1_DES_0_0							(0x1u<<4)
#define	CTI_PIDR1_PART_1							(0xFu<<0)
#define	CTI_PIDR1_PART_1_0							(0x1u<<0)
#define	CTI_PIDR1_DES_0_ARM							(0xBu<<4)
#define	CTI_PIDR1_PART_1_PARTNUMBERH				(0xDu<<0)

// PIDR2 Configuration

#define	CTI_PIDR2_REVISION							(0xFu<<4)
#define	CTI_PIDR2_REVISION_0						(0x1u<<4)
#define	CTI_PIDR2_JEDEC								(0x1u<<3)
#define	CTI_PIDR2_DES_1								(0x7u<<0)
#define	CTI_PIDR2_DES_1_0							(0x1u<<0)
#define	CTI_PIDR2_REVISION_REV0P0					(0x0u<<4)
#define	CTI_PIDR2_DES_1_ARM							(0x3u<<0)

// PIDR3 Configuration

#define	CTI_PIDR3_REVAND							(0xFu<<4)
#define	CTI_PIDR3_REVAND_0							(0x1u<<4)
#define	CTI_PIDR3_CMOD								(0xFu<<0)
#define	CTI_PIDR3_CMOD_0							(0x1u<<0)
#define	CTI_PIDR3_REVAND_NOERRATA					(0x0u<<4)
#define	CTI_PIDR3_CMOD_UNMODIFIED					(0x0u<<0)

// CIDR0 Configuration

#define	CTI_CIDR0_PRMBL_0							(0xFFu<<0)
#define	CTI_CIDR0_PRMBL_0_0							(0x1u<<0)
#define	CTI_CIDR0_PRMBL_0_VALUE						(0xDu<<0)

// CIDR1 Configuration

#define	CTI_CIDR1_CLASS								(0xFu<<4)
#define	CTI_CIDR1_CLASS_0							(0x1u<<4)
#define	CTI_CIDR1_PRMBL_1							(0xFu<<0)
#define	CTI_CIDR1_PRMBL_1_0							(0x1u<<0)
#define	CTI_CIDR1_CLASS_CORESIGHT					(0x9u<<4)
#define	CTI_CIDR1_PRMBL_1_VALUE						(0x0u<<0)

// CIDR2 Configuration

#define	CTI_CIDR2_PRMBL_2							(0xFFu<<0)
#define	CTI_CIDR2_PRMBL_2_0							(0x1u<<0)
#define	CTI_CIDR2_PRMBL_2_VALUE						(0x5u<<0)

// CIDR3 Configuration

#define	CTI_CIDR3_PRMBL_3							(0xFFu<<0)
#define	CTI_CIDR3_PRMBL_3_0							(0x1u<<0)
#define	CTI_CIDR3_PRMBL_3_VALUE						(0xB1u<<0)
