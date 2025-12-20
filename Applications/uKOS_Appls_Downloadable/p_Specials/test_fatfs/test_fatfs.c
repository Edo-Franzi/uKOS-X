/*
; test_fatfs.
; ===========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			This application shows how to operate with the uKOS-X uKernel.
;
;   (c) 2025-20xx, Edo. Franzi
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
 *			Launch 1 processes:
 *
 *			- P0: f_mkf:		format the sdcard
 *				  f_mount:		mount the sdcard
 *				  f_open:		create a file on the sdcard
 *				  f_write:		write some data to the created files
 *				  f_close:		close a file on the sdcard
 *
 *				  waiting for 5-s
 *
 *				  f_open:		open a file on the sdcard
 *				  f_read:		read the data stored on the sdcard
 *
 *				  display the result
 *
 */

#include	"uKOS.h"
#include	<ff.h>

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"test_fatFs   Example of how to use the FatFs.          (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "This is a romable C application\n"
									"===============================\n\n"

									"This user function module is a C written application.\n\n"

									"Input format:  test_fatFs\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

MODULE(
	UserAppl,									// Module name (the first letter has to be upper case)
	KID_FAM_APPLICATIONS,						// Family (defined in the module.h)
	KNUM_APPLICATION,							// Module identifier (defined in the module.h)
	NULL,										// Address of the initialisation code (early pre-init)
	aStart,										// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,										// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// Important: FATFS and FIL variables have to be static
// and not local; the size of the variable is huge!!

static			FATFS		fs_sdcard, fs_serialFlash;
static			FIL			fp_sdcard_1, fp_sdcard_2, fp_sdcard_3, fp_serialFlash_1, fp_serialFlash_2, fp_serialFlash_3;
static			DIR			dir;
static			FILINFO		fno;

static			BYTE		work[FF_MAX_SS];
static			char_t		buffer_sdcard_1[128];
static			char_t		buffer_sdcard_2[128];
static			char_t		buffer_sdcard_3[128];
static			char_t		buffer_serialFlash_1[128];
static			char_t		buffer_serialFlash_2[128];
static			char_t		buffer_serialFlash_3[128];

static	const	char_t		aTest_sdcard_1[]		= "F1: The old dreams were good dreams. They didn't work out, but I'm glad I had them.";
static	const	char_t		aTest_sdcard_2[]		= "F2: The quick brown fox jumps over the lazy dog.";
static	const	char_t		aTest_sdcard_3[]		= "F3: I didn't know he was dead...I thought he was British. (Woody Allen).";
static	const	char_t		aTest_serialFlash_1[]	= "F4: The best time to code was yesterday; the next best time is now.";
static	const	char_t		aTest_serialFlash_2[]	= "F5: Measure twice, cut once; test thrice, deploy once.";
static	const	char_t		aTest_serialFlash_3[]	= "F6: When in doubt, print it out - logs are cheap, bugs aren't.";

// Prototype

static	void	test_format(const char_t *device);
static	void	test_mount(FATFS *fs, const char_t *device);
static	void	test_folder(const char_t *folder);
static	void	test_create(FIL *fp, const char_t *name, BYTE mode);
static	void	test_write(FIL *fp, const void *buffer, UINT size, UINT *sizeWritten);
static	void	test_close(FIL *fp);
static	void	test_open(FIL *fp, const char_t *name, BYTE mode);
static	void	test_read(FIL *fp, void *buffer, UINT size, UINT *sizeRead);
static	void	test_display(void *buffer, UINT size);
static	void	test_listDirectory(const char_t *path);
static	void	test_listDirectoryTree(const char *path, uint8_t depth);

/*
 * \brief aProcess 0
 *
 * - P0:
 *		 f_mkf:			format the devices
 *		 f_mount:		mount the devices
 *		 f_open:		create files on the devices
 *		 f_write:		write data to the created files
 *		 f_close:		close the files on the devices
 *
 *		 f_open:		open the files on the devices
 *		 f_read:		read the data from the opened files
 *		 f_close:		close the files on the devices
 *
 *		 display the results
 *
 *		 display the directory
 *		 suicide
 *
 */
#define	KWITH_FLASH_S
#define	KWITH_SDCARD_S
#define	KWITH_FORMAT_S

#define	DRIVE_FLASH		"/flash"
#define	DRIVE_SDCARD	"/sdcard"

static void __attribute__ ((noreturn)) aProcess_0(const void *argument) {
	UINT	bytesRead_sdcard_1, bytesRead_sdcard_2, bytesRead_sdcard_3;
	UINT	bytesRead_serialFlash_1, bytesRead_serialFlash_2, bytesRead_serialFlash_3;
	UINT	bytesWrote_sdcard_1, bytesWrote_sdcard_2, bytesWrote_sdcard_3;
	UINT	bytesWrote_serialFlash_1, bytesWrote_serialFlash_2, bytesWrote_serialFlash_3;

	UNUSED(argument);

// Format the devices
// ------------------

	#if (defined(KWITH_FORMAT_S))
	#if (defined(KWITH_SDCARD_S))
	test_format(DRIVE_SDCARD);
	#endif

	#if (defined(KWITH_FLASH_S))
	test_format(DRIVE_FLASH);
	#endif
	#endif

// Mount the devices
// -----------------

	#if (defined(KWITH_SDCARD_S))
	test_mount(&fs_sdcard, DRIVE_SDCARD);
	#endif

	#if (defined(KWITH_FLASH_S))
	test_mount(&fs_serialFlash, DRIVE_FLASH);
	#endif

// Create the folders
// ------------------

	#if (defined(KWITH_SDCARD_S))
	test_folder(DRIVE_SDCARD	"/Poppett");
	test_folder(DRIVE_SDCARD	"/Muppett");
	test_folder(DRIVE_SDCARD	"/Floppet");
	#endif

	#if (defined(KWITH_FLASH_S))
	test_folder(DRIVE_FLASH		"/Snuppet");
	test_folder(DRIVE_FLASH		"/Bloopet");
	test_folder(DRIVE_FLASH		"/Truppet");
	#endif

// Create the files
// ----------------

	#if (defined(KWITH_SDCARD_S))
	test_create(&fp_sdcard_1,		DRIVE_SDCARD	"/Poppett/test_1.txt", FA_CREATE_ALWAYS | FA_WRITE);
	test_create(&fp_sdcard_2,		DRIVE_SDCARD	"/Muppett/test_2.txt", FA_CREATE_ALWAYS | FA_WRITE);
	test_create(&fp_sdcard_3,		DRIVE_SDCARD	"/Floppet/test_3.txt", FA_CREATE_ALWAYS | FA_WRITE);
	#endif

	#if (defined(KWITH_FLASH_S))
	test_create(&fp_serialFlash_1,	DRIVE_FLASH		"/Snuppet/test_1.txt", FA_CREATE_ALWAYS | FA_WRITE);
	test_create(&fp_serialFlash_2,	DRIVE_FLASH		"/Bloopet/test_2.txt", FA_CREATE_ALWAYS | FA_WRITE);
	test_create(&fp_serialFlash_3,	DRIVE_FLASH		"/Truppet/test_3.txt", FA_CREATE_ALWAYS | FA_WRITE);
	#endif

// Write into the files
// --------------------

	#if (defined(KWITH_SDCARD_S))
	test_write(&fp_sdcard_1,		aTest_sdcard_1,			sizeof(aTest_sdcard_1),			&bytesWrote_sdcard_1);
	test_write(&fp_sdcard_2,		aTest_sdcard_2,			sizeof(aTest_sdcard_2),			&bytesWrote_sdcard_2);
	test_write(&fp_sdcard_3,		aTest_sdcard_3,			sizeof(aTest_sdcard_3),			&bytesWrote_sdcard_3);
	#endif

	#if (defined(KWITH_FLASH_S))
	test_write(&fp_serialFlash_1,	aTest_serialFlash_1,	sizeof(aTest_serialFlash_1),	&bytesWrote_serialFlash_1);
	test_write(&fp_serialFlash_2,	aTest_serialFlash_2,	sizeof(aTest_serialFlash_2),	&bytesWrote_serialFlash_2);
	test_write(&fp_serialFlash_3,	aTest_serialFlash_3,	sizeof(aTest_serialFlash_3),	&bytesWrote_serialFlash_3);
	#endif

// Close the files
// ---------------

	#if (defined(KWITH_SDCARD_S))
	test_close(&fp_sdcard_1);
	test_close(&fp_sdcard_2);
	test_close(&fp_sdcard_3);
	#endif

	#if (defined(KWITH_FLASH_S))
	test_close(&fp_serialFlash_1);
	test_close(&fp_serialFlash_2);
	test_close(&fp_serialFlash_3);
	#endif

// Open the files
// --------------

	#if (defined(KWITH_SDCARD_S))
	test_open(&fp_sdcard_1,			DRIVE_SDCARD	"/Poppett/test_1.txt", FA_READ);
	test_open(&fp_sdcard_2,			DRIVE_SDCARD	"/Muppett/test_2.txt", FA_READ);
	test_open(&fp_sdcard_3,			DRIVE_SDCARD	"/Floppet/test_3.txt", FA_READ);
	#endif

	#if (defined(KWITH_FLASH_S))
	test_open(&fp_serialFlash_1,	DRIVE_FLASH		"/Snuppet/test_1.txt", FA_READ);
	test_open(&fp_serialFlash_2,	DRIVE_FLASH		"/Bloopet/test_2.txt", FA_READ);
	test_open(&fp_serialFlash_3,	DRIVE_FLASH		"/Truppet/test_3.txt", FA_READ);
	#endif

// Read from the files
// -------------------

	#if (defined(KWITH_SDCARD_S))
	test_read(&fp_sdcard_1,			buffer_sdcard_1,		sizeof(buffer_sdcard_1),		&bytesRead_sdcard_1);
	test_read(&fp_sdcard_2,			buffer_sdcard_2,		sizeof(buffer_sdcard_2),		&bytesRead_sdcard_2);
	test_read(&fp_sdcard_3,			buffer_sdcard_3,		sizeof(buffer_sdcard_3),		&bytesRead_sdcard_3);
	#endif

	#if (defined(KWITH_FLASH_S))
	test_read(&fp_serialFlash_1,	buffer_serialFlash_1,	sizeof(buffer_serialFlash_1),	&bytesRead_serialFlash_1);
	test_read(&fp_serialFlash_2,	buffer_serialFlash_2,	sizeof(buffer_serialFlash_2),	&bytesRead_serialFlash_2);
	test_read(&fp_serialFlash_3,	buffer_serialFlash_3,	sizeof(buffer_serialFlash_3),	&bytesRead_serialFlash_3);
	#endif

// Close the files
// ---------------

	#if (defined(KWITH_SDCARD_S))
	test_close(&fp_sdcard_1);
	test_close(&fp_sdcard_2);
	test_close(&fp_sdcard_3);
	#endif

	#if (defined(KWITH_FLASH_S))
	test_close(&fp_serialFlash_1);
	test_close(&fp_serialFlash_2);
	test_close(&fp_serialFlash_3);
	#endif

// Display the files
// -----------------

	#if (defined(KWITH_SDCARD_S))
	test_display(buffer_sdcard_1,		bytesRead_sdcard_1);
	test_display(buffer_sdcard_2,		bytesRead_sdcard_2);
	test_display(buffer_sdcard_3,		bytesRead_sdcard_3);
	#endif

	#if (defined(KWITH_FLASH_S))
	test_display(buffer_serialFlash_1,	bytesRead_serialFlash_1);
	test_display(buffer_serialFlash_2,	bytesRead_serialFlash_2);
	test_display(buffer_serialFlash_3,	bytesRead_serialFlash_3);
	#endif

// List the directory
// ------------------

	#if (defined(KWITH_SDCARD_S))
	test_listDirectory(DRIVE_SDCARD "/");
	#endif

	#if (defined(KWITH_FLASH_S))
	test_listDirectory(DRIVE_FLASH "/");
	#endif

	#if (defined(KWITH_SDCARD_S))
	test_listDirectoryTree(DRIVE_SDCARD "/", 0u);
	#endif

	#if (defined(KWITH_FLASH_S))
	test_listDirectoryTree(DRIVE_FLASH "/", 0u);
	#endif

	exit(EXIT_OS_SUCCESS);
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
	proc_t	*process_0;

// ---------------------------------I-----------------------------------------I--------------I

	STRG_LOC_CONST(aStrIden_0[]) = "Process_User_0";
	STRG_LOC_CONST(aStrText_0[]) = "Process user 0.                           (c) EFr-2025";

	UNUSED(argc);
	UNUSED(argv);

// Specifications for the processes

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use specification_x)
		aStrText_0,							// Info string (NULL if anonymous)
		KKERN_SZ_STACK_XL,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		aProcess_0,							// Code of the process
		aStrIden_0,							// Identifier (NULL if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_LOW_14				// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, NULL,  &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "Create proc"); return (EXIT_OS_FAILURE); }

	LOG(KINFO_USER, "Application launched");
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief test_format
 *
 * - Format the device
 *
 */
static	void	test_format(const char_t *device) {
	FRESULT		res;

	(void)dprintf(KSYST, "f_mkfs needs some time ...\n");

	res = f_mkfs(device, NULL, work, sizeof work);
	if (res != FR_OK) {
		(void)dprintf(KSYST, "f_mkfs erreur %d\n", res);
		while (true) { ; }
	}
	(void)dprintf(KSYST, "f_mkfs passed\n");
}

/*
 * \brief test_mount
 *
 * - Mount the device
 *
 */
static	void	test_mount(FATFS *fs, const char_t *device) {
	FRESULT		res;

	res = f_mount(fs, device, 1u);
	if (res != FR_OK) {
		(void)dprintf(KSYST, "f_mount erreur %d\n", res);
		while (true) { ; }
	}
	(void)dprintf(KSYST, "f_mount passed\n");
}

/*
 * \brief test_folder
 *
 * - create a folder
 *
 */
static	void	test_folder(const char_t *folder) {
	FRESULT		res;

	res = f_mkdir(folder);
	if ((res != FR_OK) && (res != FR_EXIST)) {
		(void)dprintf(KSYST, "f_mkdir erreur %d\n", res);
		while (true) { ; }
	}
	(void)dprintf(KSYST, "f_mkdir passed\n");
}

/*
 * \brief test_create
 *
 * - Create a file
 *
 */
static	void	test_create(FIL *fp, const char_t *name, BYTE mode) {
	FRESULT		res;

	res = f_open(fp, name, mode);
	if (res != FR_OK) {
		(void)dprintf(KSYST, "f_open erreur %d\n", res);
		while (true) { ; }
	}
	(void)dprintf(KSYST, "f_open passed\n");
}

/*
 * \brief test_write
 *
 * - Write date into a file
 *
 */
static	void	test_write(FIL *fp, const void *buffer, UINT size, UINT *sizeWritten) {
	FRESULT		res;

	res = f_write(fp, buffer, size, sizeWritten);
	if (res != FR_OK) {
		(void)dprintf(KSYST, "f_write erreur %d\n", res);
		while (true) { ; }
	}
	(void)dprintf(KSYST, "f_write passed\n");
}

/*
 * \brief test_close
 *
 * - Close a file
 *
 */
static	void	test_close(FIL *fp) {
	FRESULT		res;

	res = f_close(fp);
	if (res != FR_OK) {
		(void)dprintf(KSYST, "f_close erreur %d\n", res);
		while (true) { ; }
	}
	(void)dprintf(KSYST, "f_close passed\n");
}

/*
 * \brief test_open
 *
 * - Open a file
 *
 */
static	void	test_open(FIL *fp, const char_t *name, BYTE mode) {
	FRESULT		res;

	res = f_open(fp, name, mode);
	if (res != FR_OK) {
		(void)dprintf(KSYST, "f_open erreur %d\n", res);
		while (true) { ; }
	}
	(void)dprintf(KSYST, "f_open passed\n");
}

/*
 * \brief test_read
 *
 * - Read a file
 *
 */
static	void	test_read(FIL *fp, void *buffer, UINT size, UINT *sizeRead) {
	FRESULT		res;

	res = f_read(fp, buffer, size, sizeRead);
	if (res != FR_OK) {
		(void)dprintf(KSYST, "f_read erreur %d\n", res);
		while (true) { ; }
	}
	(void)dprintf(KSYST, "f_read passed\n");
}

/*
 * \brief test_display
 *
 * - Display the buffer
 *
 */
static	void	test_display(void *buffer, UINT size) {
	UINT		i;
	char_t		*ascii = (char_t *)buffer;

	(void)dprintf(KSYST, "\nFile: buffer\n");
	for (i = 0u; i < size; i++) {
		(void)dprintf(KSYST, "%c", ascii[i]);
	}
	(void)dprintf(KSYST, "\n");
}

/*
 * \brief test_listDirectory
 *
 * - Display the directory
 *
 */
static	void	test_listDirectory(const char_t *path) {
	FRESULT		res;
	int			nbFile = 0, nbDir = 0;

	(void)dprintf(KSYST, "\nDirectory %s\n", path);

// Open the directory

	res = f_opendir(&dir, path);
	if (res == FR_OK) {
        while (true) {

// Read a directory item

			res = f_readdir(&dir, &fno);
			UNUSED(res);

			if (fno.fname[0] == 0) { break; }
			if (fno.fattrib & AM_DIR) {
				(void)dprintf(KSYST, "   <DIR>   %s\n", fno.fname); nbDir++;
			}
			else {
				(void)dprintf(KSYST, "%10lu %s\n", fno.fsize, fno.fname); nbFile++;
			}
		}
		f_closedir(&dir);
		(void)dprintf(KSYST, "%d dirs, %d files.\n", nbDir, nbFile);
	}
	else {
		(void)dprintf(KSYST, "Failed to open \"%s\". (%u)\n", path, res);;
		while (true) { ; }
	}
}

/*
 * \brief test_listTree
 *
 * - Display the directory tree
 *
 */
static	void	print_date(uint16_t date, uint16_t time) {
	uint16_t	years, months, days, hours, minutes, seconds;

	years	= ((date>>9u) + 1980u);
	months	= (date>>5u) & 0xFu;
	days	= date & 0x1Fu;
	hours	= time>>11u;
	minutes = (time>>5) & 0x3Fu;
	seconds	= (time & 0x1Fu) * 2u;

	(void)dprintf(KSYST, "%02d-%02d-%04d   %02d:%02d:%02d", days, months, years, hours, minutes, seconds);
}

static	void	listDirectoryTree(const char *path, uint8_t depth) {
	DIR			localDir;
	FILINFO		localFile;
	char_t		next[128];

	if (f_opendir(&localDir, path) != FR_OK) { return; }

	while (true) {
		if (f_readdir(&localDir, &localFile) != FR_OK || !localFile.fname[0]) { break; }
		if (localFile.fname[0] == '.') { continue; }

		const	char_t	*name = localFile.fname;

		print_date((uint16_t)localFile.fdate, (uint16_t)localFile.ftime);

// Directory or file

		if ((localFile.fattrib & AM_DIR) != 0) { (void)dprintf(KSYST, "  %s/\n",   name); }
		else {									 (void)dprintf(KSYST, "     %s\n", name); }

		if ((localFile.fattrib & AM_DIR) != 0u) {
			(void)snprintf(next, sizeof(next), "%s/%s", path, name);
			listDirectoryTree(next, (depth + 1));
		}
	}
	f_closedir(&localDir);
}

static	void	test_listDirectoryTree(const char *path, uint8_t depth) {

	(void)dprintf(KSYST, "Device %s\n", path);
	listDirectoryTree(path, depth);
	(void)dprintf(KSYST, "\n");
}
