/*
; test_sdcard.
; ============

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		sdcard R/W tests.
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

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"test_sdcard  sdcard R/W tests.                         (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "sdcard R/W tests\n"
									"================\n\n"

									"R/W test of an sdcard.\n\n"

									"Input format:  test_sdcard\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);
static	int32_t		test_sdcard_clean(uint32_t argc, const char_t *argv[]);

MODULE(
	Test_sdcard,								// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	KNUM_TEST_SDCARD,							// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	test_sdcard_clean,							// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

#define	KNB_SD_SECTORS	100u

enum {
		KERR_NOMEM = 0u,
		KERR_SDCARD,
		KERR_WRITE,
		KERR_READ,
		KERR_MISMATCH
};

// ---------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden[]) = "Process_SDCard";
STRG_LOC_CONST(aStrText[]) = "Process sdcard; R/W 100 sectors.          (c) EFr-2026";

static	bool	vKillRequest[KNB_CORES] = MCSET(false);

// Prototypes

static	void	local_process(const void *argument);
static	void	local_error(uint8_t error, int32_t status, uint32_t sector, uint8_t *wBuffer, uint8_t *rBuffer);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	uint32_t	core;
	int32_t		status;
	proc_t		*process;

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;
	vKillRequest[core] = false;

	(void)dprintf(KSYST, "sdcard tests.\n");

	PROCESS_STACKMALLOC(
		0,									// Index
		specification,						// Specifications (just use specification_x)
		aStrText,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process,						// Code of the process
		aStrIden,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	status = (kern_createProcess(&specification, &vKillRequest[core], &process) == KERR_KERN_NOERR) ? (EXIT_OS_SUCCESS_CLI) : (EXIT_OS_FAILURE);

	if (status == EXIT_OS_FAILURE) {
		(void)dprintf(KSYST, "Error: cannot launch the process!\n\n");
	}
	return (status);
}

/*
 * \brief test_sdcard_clean
 *
 * - Try to clean the ressources
 *		- Free all the ressources
 *
 */
static	int32_t	test_sdcard_clean(uint32_t argc, const char_t *argv[]) {
	uint32_t	core;

	UNUSED(argc);
	UNUSED(argv);

	core = GET_RUNNING_CORE;
	vKillRequest[core] = true;

	return (EXIT_OS_SUCCESS);
}

// Local routines
// ==============

/*
 * \brief local_process
 *
 * - Check the sdcard (Write / Read) on all the sectors
 *
 */
[[noreturn]]
static	void	local_process(const void *argument) {
			uint8_t					*wBuffer;
			uint8_t					*rBuffer;
			int32_t					status;
			uint32_t				i, j, k = 0u, sector = 0u;
			uint64_t				tStamp[2];
			sdcard_specification_t	sdCard;
	const	bool					*killRequest;
	const	char_t					*card, *manufacturer, *voltage;

	killRequest	= (const bool *)argument;

	wBuffer = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (KNB_SD_SECTORS * KSDCARD_SZ_SECTOR * sizeof(uint8_t)), "test_sdcard");
	if (wBuffer == nullptr) {
		local_error(KERR_NOMEM, 0u, 0u, nullptr, nullptr);
	}

	rBuffer = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (KNB_SD_SECTORS * KSDCARD_SZ_SECTOR * sizeof(uint8_t)), "test_sdcard");
	if (rBuffer == nullptr) {
		local_error(KERR_NOMEM, 0u, 0u, wBuffer, nullptr);
	}

	RESERVE(SDCARD, KMODE_READ_WRITE);
	status = sdcard_initialise(&sdCard);
	if (status != KERR_STORAGE_NOERR) {
		local_error(KERR_SDCARD, status, 0u, wBuffer, rBuffer);
	}

// Display the sdcard properties

	if (sdCard.oCapacityStatus == KSDCARD_CT_SD1) { card = (const char_t *)"sdcard V.1";   }
	else										  { card = (const char_t *)"sdcard V.2";   }

	switch (sdCard.oManufacturer) {
		case KSDCARD_PANASONIC:	 { manufacturer = (const char_t *)"Panasanic";		break; }
		case KSDCARD_TOSHIBA:	 { manufacturer = (const char_t *)"Toshiba";		break; }
		case KSDCARD_SANDISK:	 { manufacturer = (const char_t *)"SanDisk";		break; }
		case KSDCARD_SAMSUNG:	 { manufacturer = (const char_t *)"Samsung";		break; }
		case KSDCARD_ADATA:		 { manufacturer = (const char_t *)"AData";			break; }
		case KSDCARD_PHISON:	 { manufacturer = (const char_t *)"Phison";			break; }
		case KSDCARD_LEXAR:		 { manufacturer = (const char_t *)"Lexar";			break; }
		case KSDCARD_SILICONPWR: { manufacturer = (const char_t *)"Silicon Power";	break; }
		case KSDCARD_KINGSTON:	 { manufacturer = (const char_t *)"Kingston";		break; }
		case KSDCARD_TRANSCEND:	 { manufacturer = (const char_t *)"Transcend";		break; }
		case KSDCARD_PATRIOT:	 { manufacturer = (const char_t *)"Patriot";		break; }
		case KSDCARD_SONY:		 { manufacturer = (const char_t *)"Sony";			break; }
		default:				 { manufacturer = (const char_t *)"Unknown";		break; }
	}

	switch (sdCard.oVoltage) {
		case KSDCARD_V_27_28:	 { voltage = (const char_t *)"2.7 to 2.8V"; 		break; }
		case KSDCARD_V_28_29:	 { voltage = (const char_t *)"2.8 to 2.9V"; 		break; }
		case KSDCARD_V_29_30:	 { voltage = (const char_t *)"2.9 to 3.0V"; 		break; }
		case KSDCARD_V_30_31:	 { voltage = (const char_t *)"3.0 to 3.1V"; 		break; }
		case KSDCARD_V_31_32:	 { voltage = (const char_t *)"3.1 to 3.2V"; 		break; }
		case KSDCARD_V_32_33:	 { voltage = (const char_t *)"3.2 to 3.3V"; 		break; }
		case KSDCARD_V_33_34:	 { voltage = (const char_t *)"3.3 to 3.4V"; 		break; }
		case KSDCARD_V_34_35:	 { voltage = (const char_t *)"3.4 to 3.5V"; 		break; }
		case KSDCARD_V_35_36:	 { voltage = (const char_t *)"3.5 to 3.6V"; 		break; }
		default:			 	 { voltage = (const char_t *)"Unknown";				break; }
	}

	(void)dprintf(KURT0, "\n\n");
	(void)dprintf(KURT0, "Card type             %s\n",				 card);
	(void)dprintf(KURT0, "Card Manufacturer ID  0x%02"PRIX8", %s\n", sdCard.oManufacturer, manufacturer);
	(void)dprintf(KURT0, "Card Product Name     %s\n",				 sdCard.oProductName);
	(void)dprintf(KURT0, "Card Serial Number    %08"PRIX32"\n",		 sdCard.oSerialNumber);
	(void)dprintf(KURT0, "Card size [Bytes]     %"PRIu64"\n",		 sdCard.oSize);
	(void)dprintf(KURT0, "Card speed            %"PRIu32"-bit/s\n",  sdCard.oSpeed);
	(void)dprintf(KURT0, "Card voltage          %s\n",				 voltage);

	while (*killRequest == false) {
		kern_suspendProcess(1u);

// Initialise the buffer

		for (i = 0u; i < KNB_SD_SECTORS; i++) {
			for (j = 0u; j < KSDCARD_SZ_SECTOR; j++) {
				*(wBuffer + (i * KSDCARD_SZ_SECTOR) + j) = (uint8_t)k;
				k++;
			}
		}

// Write 100 consecutive sectors
// Read 100 consecutive sectors

		kern_readTickCount(&tStamp[0]);
		status = sdcard_write(wBuffer, (KNB_SD_SECTORS * KSDCARD_SZ_SECTOR), sector);
		kern_readTickCount(&tStamp[1]);
		if (status != KERR_STORAGE_NOERR) {
			local_error(KERR_WRITE, status, sector, wBuffer, rBuffer);
		}
		(void)dprintf(KSYST, "Write time for 100 sectors:  %"PRIu32"-us, sector nb %"PRIu32"\n", (uint32_t)(tStamp[1] - tStamp[0]), sector);

		kern_suspendProcess(1u);

		kern_readTickCount(&tStamp[0]);
		status = sdcard_read(rBuffer, (KNB_SD_SECTORS * KSDCARD_SZ_SECTOR), sector);
		kern_readTickCount(&tStamp[1]);
		if (status != KERR_STORAGE_NOERR) {
			local_error(KERR_READ, status, sector, wBuffer, rBuffer);
		}
		(void)dprintf(KSYST, "Read  time for 100 sectors:  %"PRIu32"-us, sector nb %"PRIu32"\n", (uint32_t)(tStamp[1] - tStamp[0]), sector);

		kern_suspendProcess(1u);

// Test if the buffers are equals

		sector += KNB_SD_SECTORS;
		for (i = 0u; i < KNB_SD_SECTORS; i++) {
			for (j = 0u; j < KSDCARD_SZ_SECTOR; j++) {
				if (*(wBuffer + (i * KSDCARD_SZ_SECTOR) + j) != *(rBuffer + (i * KSDCARD_SZ_SECTOR) + j)) {
					local_error(KERR_MISMATCH, 0u, sector, wBuffer, rBuffer);
				}
			}
		}
	}

// Kill the process & the ressources

	INTERRUPTION_OFF;
	RELEASE(SDCARD, KMODE_READ_WRITE);

	memo_free(wBuffer);
	memo_free(rBuffer);

	exit(EXIT_OS_SUCCESS);
}

/*
 * \brief local_error
 *
 */
[[noreturn]]
static	void	local_error(uint8_t error, int32_t status, uint32_t sector, uint8_t *wBuffer, uint8_t *rBuffer) {

	switch (error) {
		case KERR_NOMEM:    { (void)dprintf(KSYST, "Error: Not enough memory\n");																  break; }
		case KERR_SDCARD:   { (void)dprintf(KSYST, "Error: status = %08"PRIX32"\n",					   ((uint32_t)status & 0x7FFFFFFFu));		  break; }
		case KERR_WRITE:    { (void)dprintf(KSYST, "Error: W status = %08"PRIX32" sector %"PRIu32"\n", ((uint32_t)status & 0x7FFFFFFFu), sector); break; }
		case KERR_READ:     { (void)dprintf(KSYST, "Error: R status = %08"PRIX32" sector %"PRIu32"\n", ((uint32_t)status & 0x7FFFFFFFu), sector); break; }
		case KERR_MISMATCH: { (void)dprintf(KSYST, "Error: Read & write mismatch\n");															  break; }
		default: {

// Make MISRA happy :-)

			break;
		}
	}

	if (wBuffer != nullptr) { memo_free(wBuffer); }
	if (rBuffer != nullptr) { memo_free(rBuffer); }
	RELEASE(SDCARD, KMODE_READ_WRITE);

	LOG(KFATAL_SYSTEM, "test_sdcard: SD-Card problem");
	exit(EXIT_OS_FAILURE);
}
