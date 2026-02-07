/*
; sdcard.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application shows how to operate with the uKOS-X uKernel.
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

/*!
 * \file
 * \ingroup app_special
 * \brief This application shows how to operate with the uKOS uKernel.
 *
 *			Launch 2 processes:
 *
 *			- P0: Every 1000-ms
 *					- Toggle LED 1
 *
 *			- P1: Initialise the sdcard
 *				  Decode and launch the test (x)
 *				  exit
 *
 *			sloader test x
 *			x = test number (0..5)
 *
 *			0:  Read n sectors and display the content
 *			1:  Read all the sectors (about. 20h)
 *			2:  Write/Read 2 consecutive sectors
 *			3:  Read the sdcard parameters
 *			4:  Write/Read 100 consecutive sectors and measure the Write/Read access time
 *			5:  Write/read float64 numbers
 *
 */

#include	"uKOS.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"sdcard       Example of how to use the sdcard.         (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  sdcard\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

MODULE(
	UserAppl,									// Module name (the first letter has to be upper case)
	KID_FAM_APPLICATIONS,						// Family (defined in the module.h)
	KNUM_APPLICATION,							// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	aStart,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// Application specific
// ====================

typedef	struct	myPack	myPack_t;

struct	myPack {
			const	char_t		**oArgv;		// Ptr on the argv
					uint32_t	oArgc;			// argc
					bool		*oReleasePack;	// Release the pack
		};

// Prototypes

static	void	aTest_0(void);
static	void	aTest_1(void);
static	void	aTest_2(void);
static	void	aTest_3(void);
static	void	aTest_4(void);
static	void	aTest_5(void);

/*
 * \brief aProcess 0
 *
 * - P0: Every 1000-ms
 * 			- Toggle LED 1
 *
 */
static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(1000u);
		led_toggle(KLED_1);
	}
}

/*
 * \brief aProcess 1
 *
 * - P1: Initialise the sdcard
 * 		 - Decode and launch the test
 *		 - exit
 *
 */
static void __attribute__ ((noreturn)) aProcess_1(const void *argument) {
			char_t		*dummy;
			int32_t		testNumber;
			uint32_t	argc;
			bool		*releasePack;
	const	char_t		**argv;
	const	myPack_t	*pack;

	pack = (const myPack_t *)argument;

	argc		 = pack->oArgc;
	argv		 = pack->oArgv;
	releasePack  = pack->oReleasePack;
	*releasePack = true;

// Read the command line

	if (argc != 3) {
		LOG(KFATAL_USER, "Format problem");
		exit(EXIT_OS_FAILURE);
	}

	testNumber = (int32_t)strtol(argv[2], &dummy, 10u);

// Reserve the sdcard

	RESERVE(SDCARD, KMODE_READ_WRITE);

// Execute the selected test

	switch (testNumber) {
		case 0:  { aTest_0(); break; }
		case 1:  { aTest_1(); break; }
		case 2:  { aTest_2(); break; }
		case 3:  { aTest_3(); break; }
		case 4:  { aTest_4(); break; }
		case 5:  { aTest_5(); break; }
		default: {

// Make MISRA happy :-)

			break;
		}
	}
	RELEASE(SDCARD, KMODE_READ_WRITE);

	exit(EXIT_OS_SUCCESS_CLI);
}

/*
 * \brief aTest_0
 *
 * - Read n sectors and display the content
 *
 * \note This function does not return a value (None).
 *
 */
static	void	aTest_0(void) {
	#define		KT0_INIT_SECTOR	0u
	#define		KT0_NB_SECTORS	3u
	int32_t		status;
	uint32_t	i, j, n;
	uint8_t		*buffer;

	buffer = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (KSDCARD_SZ_SECTOR * sizeof(uint8_t)), "sdcard");
	if (buffer == nullptr) {
		LOG(KFATAL_USER, "Out of memory");
		exit(EXIT_OS_FAILURE);
	}

	for (n = 0u; n < KT0_NB_SECTORS; n++) {
		led_toggle(KLED_1);

// Read the sector 0 to ...

		kern_suspendProcess(1000u);

		status = sdcard_read(buffer, KSDCARD_SZ_SECTOR, (KT0_INIT_SECTOR + n));
		if (status != KERR_STORAGE_NOERR) {
			memo_free(buffer);
			LOG(KFATAL_USER, "Read problem");
			exit(EXIT_OS_FAILURE);
		}

		(void)dprintf(KSYST, "Sector = %"PRIu32"\n", (KT0_INIT_SECTOR + n));

		for (j = 0u; j < KSDCARD_SZ_SECTOR; j += 16u) {
			for (i = 0u; i < 16u; i++) {
				(void)dprintf(KSYST, "0x%02X ", *(buffer + i + j));
			}
			(void)dprintf(KSYST, "\n");
		}
		(void)dprintf(KSYST, "\n\n");
	}
	memo_free(buffer);
}

/*
 * \brief aTest_1
 *
 * - Read all the sectors (about. 20h)
 *
 * \note This function does not return a value (None).
 *
 */
static	void	aTest_1(void) {
	#define		KT1_NB_SECTORS	10
	int32_t		status;
	uint32_t	sector = 0;
	uint8_t		*buffer;

	buffer = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (KT1_NB_SECTORS * KSDCARD_SZ_SECTOR * sizeof(uint8_t)), "sdcard");
	if (buffer == nullptr) {
		LOG(KFATAL_USER, "Out of memory");
		exit(EXIT_OS_FAILURE);
	}

	while (true) {
		led_toggle(KLED_1);

// Read all the sectors (about. 20h)

		if ((sector % 1000) == 0) {
			(void)dprintf(KSYST, "sector %"PRIu32"\n", sector);
		}

		status = sdcard_read(buffer, (KT1_NB_SECTORS * KSDCARD_SZ_SECTOR), sector);
		if (status != KERR_STORAGE_NOERR) {
			memo_free(buffer);
			LOG(KFATAL_USER, "Read problem");
			exit(EXIT_OS_FAILURE);
		}

		sector += 10;
	}
}

/*
 * \brief aTest_2
 *
 * - Write/Read 2 consecutive sectors
 *
 * \note This function does not return a value (None).
 *
 */
static	void	aTest_2(void) {
	#define		KT2_NB_BYTES	(KSDCARD_SZ_SECTOR * 2)
	#define		KT2_NB_SECTORS	2
	int32_t		status;
	uint32_t	i, j, s, sector = 0;
	uint8_t		*wBuffer;
	uint8_t		*rBuffer;

	wBuffer = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (KT2_NB_SECTORS * KSDCARD_SZ_SECTOR * sizeof(uint8_t)), "sdcard");
	if (wBuffer == nullptr) {
		LOG(KFATAL_USER, "Out of memory");
		exit(EXIT_OS_FAILURE);
	}

	rBuffer = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (KT2_NB_SECTORS * KSDCARD_SZ_SECTOR * sizeof(uint8_t)), "sdcard");
	if (rBuffer == nullptr) {
		memo_free(wBuffer);
		LOG(KFATAL_USER, "Out of memory");
		exit(EXIT_OS_FAILURE);
	}

// Initialise the buffer

	for (i = 0; i < KSDCARD_SZ_SECTOR; i++) {
		*(wBuffer + i)						 = 0x55;
		*(wBuffer + KSDCARD_SZ_SECTOR + i) = 0xAA;
	}

	while (true) {
		led_toggle(KLED_1);

// Write/read 2 consecutive sectors

		kern_suspendProcess(1000);

		(void)dprintf(KSYST, "Sector = %"PRIu32"\n\n", sector);

		status = sdcard_write(wBuffer, KT2_NB_BYTES, sector);
		if (status != KERR_STORAGE_NOERR) {
			memo_free(wBuffer);
			memo_free(rBuffer);
			LOG(KFATAL_USER, "Write problem");
			exit(EXIT_OS_FAILURE);
		}

		status = sdcard_read(rBuffer, KT2_NB_BYTES, sector);
		if (status != KERR_STORAGE_NOERR) {
			memo_free(wBuffer);
			memo_free(rBuffer);
			LOG(KFATAL_USER, "Read problem");
			exit(EXIT_OS_FAILURE);
		}

		for (s = 0; s < KT2_NB_SECTORS; s++) {
			(void)dprintf(KSYST, "s = %"PRIu32"\n", s);
			for (j = 0; j < KSDCARD_SZ_SECTOR; j += 16) {
				for (i = 0; i < 16; i++) {
					(void)dprintf(KSYST, "0x%02X ", *(rBuffer + (KSDCARD_SZ_SECTOR * s) + i + j));
				}
				(void)dprintf(KSYST, "\n");
			}
		}
		(void)dprintf(KSYST, "\n\n");
		sector += 1;
	}
}

/*
 * \brief aTest_3
 *
 * - Read the sdcard parameters
 *
 * \note This function does not return a value (None).
 *
 */
static	void	aTest_3(void) {
	char_t					*card, *manufacturer;
	sdcard_specification_t	sdCard;

	while (true) {
		led_toggle(KLED_1);

// Read the sdcard sdCard

		kern_suspendProcess(2000);

		sdcard_initialise(&sdCard);

		if (sdCard.oCapacityStatus == KSDCARD_CT_SD1) { card = "sdcard V.1"; }
		else										  { card = "sdcard V.2"; }

		switch (sdCard.oManufacturer) {
			case KSDCARD_PANASONIC:	 { manufacturer = "Panasanic";	   break; }
			case KSDCARD_TOSHIBA:	 { manufacturer = "Toshiba";	   break; }
			case KSDCARD_SANDISK:	 { manufacturer = "SanDisk";	   break; }
			case KSDCARD_SAMSUNG:	 { manufacturer = "Samsung";	   break; }
			case KSDCARD_ADATA:		 { manufacturer = "AData";		   break; }
			case KSDCARD_PHISON:	 { manufacturer = "Phison";		   break; }
			case KSDCARD_LEXAR:		 { manufacturer = "Lexar";		   break; }
			case KSDCARD_SILICONPWR: { manufacturer = "Silicon Power"; break; }
			case KSDCARD_KINGSTON:	 { manufacturer = "Kingston";	   break; }
			case KSDCARD_TRANSCEND:	 { manufacturer = "Transcend";	   break; }
			case KSDCARD_PATRIOT:	 { manufacturer = "Patriot";	   break; }
			case KSDCARD_SONY:		 { manufacturer = "Sony";		   break; }
			default:				 { manufacturer = "Unknown";	   break; }
		}

		(void)dprintf(KSYST, "Card type             %s\n",				 card);
		(void)dprintf(KSYST, "Card Manufacturer ID  0x%02"PRIX8", %s\n", sdCard.oManufacturer, manufacturer);
		(void)dprintf(KSYST, "Card Product Name     %s\n",				 sdCard.oProductName);
		(void)dprintf(KSYST, "Card Serial Number    %08"PRIX32"\n",		 sdCard.oSerialNumber);
		(void)dprintf(KSYST, "Card size [Bytes]     %"PRIu64"\n",		 sdCard.oSize);
		(void)dprintf(KSYST, "Card voltage          %04"PRIX16"\n",		 sdCard.oVoltage);

// Print the supported voltages

		if ((sdCard.oVoltage & 0x001) != 0) { (void)dprintf(KSYST, " - Supported voltage  2.7 to 2.8V\n");   }
		if ((sdCard.oVoltage & 0x002) != 0) { (void)dprintf(KSYST, " - Supported voltage  2.8 to 2.9V\n");   }
		if ((sdCard.oVoltage & 0x004) != 0) { (void)dprintf(KSYST, " - Supported voltage  2.9 to 3.0V\n");   }
		if ((sdCard.oVoltage & 0x008) != 0) { (void)dprintf(KSYST, " - Supported voltage  3.0 to 3.1V\n");   }
		if ((sdCard.oVoltage & 0x010) != 0) { (void)dprintf(KSYST, " - Supported voltage  3.1 to 3.2V\n");   }
		if ((sdCard.oVoltage & 0x020) != 0) { (void)dprintf(KSYST, " - Supported voltage  3.2 to 3.3V\n");   }
		if ((sdCard.oVoltage & 0x040) != 0) { (void)dprintf(KSYST, " - Supported voltage  3.3 to 3.4V\n");   }
		if ((sdCard.oVoltage & 0x080) != 0) { (void)dprintf(KSYST, " - Supported voltage  3.4 to 3.5V\n");   }
		if ((sdCard.oVoltage & 0x100) != 0) { (void)dprintf(KSYST, " - Supported voltage  3.5 to 3.6V\n\n"); }
	}
}

/*
 * \brief aTest_4
 *
 * - Write/Read 100 consecutive sectors and measure the Write/Read access time
 *
 * \note This function does not return a value (None).
 *
 */
static	void	aTest_4(void) {
	#define		KT4_NB_SECTORS	100
	int32_t		status;
	uint32_t	i, j, k, sector = 0;
	uint64_t	tStamp[2];
	uint8_t		*wBuffer;
	uint8_t		*rBuffer;

	wBuffer = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (KT4_NB_SECTORS * KSDCARD_SZ_SECTOR * sizeof(uint8_t)), "sdcard");
	if (wBuffer == nullptr) {
		LOG(KFATAL_USER, "Out of memory");
		exit(EXIT_OS_FAILURE);
	}

	rBuffer = (uint8_t *)memo_malloc(KMEMO_ALIGN_8, (KT4_NB_SECTORS * KSDCARD_SZ_SECTOR * sizeof(uint8_t)), "sdcard");
	if (rBuffer == nullptr) {
		memo_free(wBuffer);
		LOG(KFATAL_USER, "Out of memory");
		exit(EXIT_OS_FAILURE);
	}

	k = 0;
	while (true) {
		led_toggle(KLED_1);

// Initialise the buffer

		for (i = 0; i < KT4_NB_SECTORS; i++) {
			for (j = 0; j < KSDCARD_SZ_SECTOR; j++) {
				*(wBuffer + (i * KSDCARD_SZ_SECTOR) + j) = (uint8_t)k;
				k++;
			}
		}

// Write/read 100 consecutive sectors (3 consecutive tries before stopping)

		kern_readTickCount(&tStamp[0]);
		status = sdcard_write(wBuffer, (KT4_NB_SECTORS * KSDCARD_SZ_SECTOR), sector);
		kern_readTickCount(&tStamp[1]);
		if (status != KERR_STORAGE_NOERR) {
			memo_free(wBuffer);
			memo_free(rBuffer);
			LOG(KFATAL_USER, "Write problem");
			exit(EXIT_OS_FAILURE);
		}

		(void)dprintf(KSYST, "Write time for 100 sectors:  %"PRIu32"-us, sector nb %"PRIu32"\n", (uint32_t)(tStamp[1] - tStamp[0]), sector);

		kern_readTickCount(&tStamp[0]);
		status = sdcard_read(rBuffer, (KT4_NB_SECTORS * KSDCARD_SZ_SECTOR), sector);
		kern_readTickCount(&tStamp[1]);
		if (status != KERR_STORAGE_NOERR) {
			memo_free(wBuffer);
			memo_free(rBuffer);
			LOG(KFATAL_USER, "read problem");
			exit(EXIT_OS_FAILURE);
		}

		(void)dprintf(KSYST, "Read time for 100 sectors:   %"PRIu32"-us, sector nb %"PRIu32"\n", (uint32_t)(tStamp[1] - tStamp[0]), sector);

		sector += KT4_NB_SECTORS;

// Test if the buffers are equals

		for (i = 0; i < KT4_NB_SECTORS; i++) {
			for (j = 0; j < KSDCARD_SZ_SECTOR; j++) {
				if (*(wBuffer + (i * KSDCARD_SZ_SECTOR) + j) != *(rBuffer + (i * KSDCARD_SZ_SECTOR) + j)) {
					LOG(KFATAL_USER, "Coherency problem!!");
					exit(EXIT_OS_FAILURE);
				}

			}
		}
	}
}

/*
 * \brief aTest_5
 *
 * - Write/read float64 numbers
 *
 * \note This function does not return a value (None).
 *
 */
static	void	aTest_5(void) {
	int32_t		status;
	float64_t	*ref, *res;

	VAR_DECLARED_ALIGN(static uint8_t vBufRef[KSDCARD_SZ_SECTOR], 8);
	VAR_DECLARED_ALIGN(static uint8_t vBufRes[KSDCARD_SZ_SECTOR], 8);

// Save the GCC diagnostic
//
	#pragma GCC diagnostic	push

// Ignore the GCC diagnostic
//
	#pragma GCC diagnostic	ignored	"-Wcast-align"
	ref = (float64_t *)&vBufRef[0];
	res = (float64_t *)&vBufRes[0];

// Restore the GCC diagnostic
//
	#pragma GCC	diagnostic	pop

	*(ref + 0) = 3.141516;
	*(ref + 1) = 1.843256;

	while (true) {
		led_toggle(KLED_1);
		kern_suspendProcess(1000);

// Write 2 float64 numbers on the sector 0

		status = sdcard_write(vBufRef, 10, 0);
		if (status != KERR_STORAGE_NOERR) {
			LOG(KFATAL_USER, "Write problem");
			exit(EXIT_OS_FAILURE);
		}

// Read 2 float64 numbers from the sector 0

		status = sdcard_read(vBufRes, 10, 0);
		if (status != KERR_STORAGE_NOERR) {
			LOG(KFATAL_USER, "Read problem");
			exit(EXIT_OS_FAILURE);
		}

		(void)dprintf(KSYST, "%6.3f %6.3f %6.3f %6.3f\n", *(ref + 0), *(ref + 1), *(res + 0), *(res + 1));
	}
}

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
int		main(int argc, const char *argv[]) {
	myPack_t	pack;
	bool		releasePack = false;
	proc_t		*process_0, *process_1;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrIden_1[]) = "Process_User_1";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2026";
	STRG_LOC_CONST(aStrText_1[]) = "Process user 1.                           (c) EFr-2026";

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use specification_x)
		aStrText_0,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		aStrIden_0,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		1,									// Index
		specification_1,					// Specifications (just use specification_x)
		aStrText_1,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_1,							// Code of the process
		aStrIden_1,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_HIGH_01				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	pack.oArgc 		  = (uint32_t)argc;
	pack.oArgv 		  = (const char_t **)argv;
	pack.oReleasePack = &releasePack;

	if (kern_createProcess(&specification_0, nullptr,  &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, &pack, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

// Let the time to the process "aProcess_1" to run

	do { kern_suspendProcess(1u); } while (releasePack == false);

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}
