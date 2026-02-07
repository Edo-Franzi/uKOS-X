/*
; xferUart.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Dump a uart serial stream on a file. xferUart is a simplified version of the dump.
;
; Usage:	xferUart [driverID]
;			driverID	input	(ie. FT000001)
;			!!! The baudrate is fixed @ 3'000'000-b/s
;
;			1. rm -rf /tmp/file_name
;			2. xferUart FTWS6VG0D
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

#include	"types_unix.h"
#include	"ftd2xx.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<sys/statistics.h>

#define	KMAXNBREAD	100000000								// 100'000'000 bytes before stopping

enum {
		KPIPE = 0,
		KFILE
};

enum {
		KDISPLAY = 0,
		KNODISPLAY
};

enum {
		KERRNOT = 0,
		KERRAPP,
		KERRCLI
};

static	uint8_t		vBuffer[100000];

// Prototypes

extern  void		d2x_list(void);
extern	FT_HANDLE	d2x_open(const char_t *driverID, int32_t baudrate);
extern	void		d2x_close(FT_HANDLE handle);
extern	bool		d2x_readAByte(FT_HANDLE handle, uint8_t *receive);
extern	bool		d2x_read(FT_HANDLE handle, uint8_t *receive, uint32_t *count);
extern	void		d2x_flush(FT_HANDLE handle);

static	bool		local_open(uint32_t type, char_t *fileName, FILE **fpFile, int32_t *fpPipe);
static	void		local_close(uint32_t type, char_t *fileName, FILE *fpFile, int32_t fpPipe);
static	void		local_write(uint32_t type, FILE *fpFile, int32_t fpPipe, uint8_t *buffer, uint32_t count);
static	int32_t		local_app_d2x(char_t *driverID, uint32_t type, uint32_t display, char_t *fileName, uint32_t baudrate);

/*
 * \brief Main entry point
 *
 */
int		main(int32_t argc, const char_t *argv[]) {
	char_t		*fileName, *driver;
	char_t		driverID[50];
	int32_t		error;
	uint32_t	type, display, baudrate;

	fprintf(stdout, "\nXfer data from the selected D2XX I/O port to the /tmp/pipe file @ 3'000'000-b/s\n");
	fprintf(stdout, __DATE__"  "__TIME__" (c) EFr-2026\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// xferUart DCWZ1FL8

	error = KERRNOT;
	switch (argc) {
		case 2: {
			type = KFILE;										// Type file
			display = KNODISPLAY;								// No display
			baudrate = 3000000;									// Baudrate (3000000)
			strcpy(driverID, argv[1]);							// Driver ID (FT000001)
			fileName = "/tmp/pipe";								// Filename
			break;
		}
		default: {
			error = KERRCLI;
			break;
		}
	}

	if (error == KERRNOT) {
		error = local_app_d2x(driverID, type, display, fileName, baudrate);
	}

	switch (error) {
		case KERRNOT: { fprintf(stdout, "Terminated\n");							 return (EXIT_OS_SUCCESS); }
		case KERRAPP: { fprintf(stderr, "### Error: input/output file not found\n"); return (EXIT_OS_FAILURE); }
		case KERRCLI: { fprintf(stderr, "xferUart [driverID]\n");
						fprintf(stderr, "[driverID] driverID (ie. FT000001)\n");
						d2x_list();
																					 return (EXIT_OS_FAILURE); }
		default: {

// Make MISRA happy :-)

			break;
		}
	}
}

// Local routines
// ==============

/*
 * \brief local_app_d2x
 *
 * - Open the driver & the file or pipe
 * - Fill the file
 * - Close the driver & the file or pipe
 *
 */
static	int32_t	local_app_d2x(char_t *driverID, uint32_t type, uint32_t display, char_t *fileName, uint32_t baudrate) {
	FT_HANDLE	handle;
	uint32_t	i, nbRead, count;
	bool		error;
	FILE		*fpFile;
	int32_t		fpPipe;

	handle = d2x_open(driverID, baudrate);
	error = local_open(type, fileName, &fpFile, &fpPipe);
	if ((handle == nullptr) || (error == false)) {
		d2x_close(handle); local_close(type, fileName, fpFile, fpPipe);
		return (KERRAPP);
	}

// Fill the file

	d2x_flush(handle);
	nbRead = 0;

	while (true) {
		if (d2x_read(handle, vBuffer, &count) == false) {
			break;
		}
		local_write(type, fpFile, fpPipe, vBuffer, count);
		nbRead += count;
		if (display == KDISPLAY) {
			for (i = 0; i < count; i++) {
				fprintf(stdout, "%c", vBuffer[i]);
			}
		}
		if (nbRead > KMAXNBREAD) {
			break;
		}
	}
	d2x_close(handle); local_close(type, fileName, fpFile, fpPipe);
	return (KERRNOT);
}

/*
 * \brief local_open
 *
 * - Open a file or a pipe
 *
 */
static	bool	local_open(uint32_t type, char_t *fileName, FILE **fpFile, int32_t *fpPipe) {

	switch (type) {
		default:
		case KFILE: {
			*fpFile  = fopen(fileName, "w");
			return (*fpFile == 0) ? (false) : (true);
		}
		case KPIPE: {
			mkfifo(fileName, 0666);
			*fpPipe = open(fileName, O_WRONLY);
			return (*fpPipe == 0) ? (false) : (true);
		}
	}
}

/*
 * \brief local_close
 *
 * - Close a file or a pipe
 *
 */
static	void	local_close(uint32_t type, char_t *fileName, FILE *fpFile, int32_t fpPipe) {

	switch (type) {
		default:
		case KFILE: {
			fclose(fpFile);
			break;
		}
		case KPIPE: {
			unlink(fileName);
			close(fpPipe);
			break;
		}
	}
}

/*
 * \brief local_write
 *
 * - Write a file or a pipe
 *
 */
static	void	local_write(uint32_t type, FILE *fpFile, int32_t fpPipe, uint8_t *buffer, uint32_t count) {

	switch (type) {
		default:
		case KFILE: {
			fwrite(buffer, 1, (size_t)count, fpFile);
			break;
		}
		case KPIPE: {
			write(fpPipe, buffer, count);
		}
	}
}
