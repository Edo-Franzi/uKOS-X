/*
; xferSpi.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Dump a spi serial stream on a file. xferSpi is a simplified version of the dump.
;
; Usage:	xferSpi [driverID]
;			driverID	input	(ie. FT000001)
;
;			1. rm -rf /tmp/file_name
;			2. xferSpi FTWS6VG0D
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

#define		_DEFAULT_SOURCE

#include	"types_unix.h"
#include	"ftd2xx.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<sys/statistics.h>
#include	<unistd.h>

#define KNB_COLS				752											// Number of cols
#define KNB_ROWS				480											// Number of rows
#define	KXFER_NB_PACKETS		80											// Number of packets (has to be divisible by 2). See xfer.h
#define KPACKETSIZE				((KNB_COLS * KNB_ROWS) / KXFER_NB_PACKETS)	// Packet size (for a 480 x 480 buffer)
#define	KMAXIMAGEREAD			(2000 * KNB_COLS * KNB_ROWS)				// Nb of images to read before stopping

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

static	uint8_t		vBuffer[KPACKETSIZE];

// Prototypes

extern  void		spi_list(void);
extern	FT_HANDLE	spi_open(const char_t *driverID);
extern	void		spi_close(FT_HANDLE handle);
extern	bool		spi_read(FT_HANDLE handle, uint8_t *receive, uint32_t size, uint32_t *count);
extern	void		spi_flush(FT_HANDLE handle);

static	void		local_swap(uint8_t *buffer, uint32_t count);
static	bool		local_open(uint32_t type, char_t *fileName, FILE **fpFile, int32_t *fpPipe);
static	void		local_close(uint32_t type, char_t *fileName, FILE *fpFile, int32_t fpPipe);
static	void		local_write(uint32_t type, FILE *fpFile, int32_t fpPipe, uint8_t *buffer, uint32_t count);
static	int32_t		local_app_spi(char_t *driverID, uint32_t type, uint32_t display, char_t *fileName);

/*
 * \brief Main entry point
 *
 */
int		main(int32_t argc, const char_t *argv[]) {
	char_t		*fileName, *driver;
	char_t		driverID[50];
	int32_t		error;
	uint32_t	type, display, baudrate;

	fprintf(stdout, "\nXfer data from the selected D2XX I/O port to the /tmp/pipe file using the spi\n");
	fprintf(stdout, __DATE__"  "__TIME__" (c) EFr-2026\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// xferSpi DCWZ1FL8

	error = KERRNOT;
	switch (argc) {
		case 2: {
			type = KFILE;										// Type file
			display = KNODISPLAY;								// No display
			strcpy(driverID, argv[1]);							// Driver ID (FT000001)
			fileName = "/tmp/pipe";								// Filename
			break;
		}
		default: {
			error = KERRCLI;
			break;
		}
	}

	if (error == KERRNOT)
		error = local_app_spi(driverID, type, display, fileName);

	switch (error) {
		case KERRNOT: { fprintf(stdout, "Terminated\n");							 return (EXIT_OS_SUCCESS); }
		case KERRAPP: { fprintf(stderr, "### Error: input/output file not found\n"); return (EXIT_OS_FAILURE); }
		case KERRCLI: { fprintf(stderr, "xferSpi [driverID]\n");
						fprintf(stderr, "[driverID]  driverID (ie. FT000001)\n");
						spi_list();
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
 * \brief local_app_spi
 *
 * - Open the driver & the file or pipe
 * - Fill the file
 * - Close the driver & the file or pipe
 *
 */
static	int32_t	local_app_spi(char_t *driverID, uint32_t type, uint32_t display, char_t *fileName) {
	FT_HANDLE	handle;
	uint32_t	i, nbRead, nbPackets, nbImages, count;
	bool		error;
	FILE		*fpFile;
	int32_t		fpPipe;
	uint8_t		tmp;

	handle = spi_open(driverID);
	error  = local_open(type, fileName, &fpFile, &fpPipe);
	if ((handle == nullptr) || (error == false)) {
		spi_close(handle);
		local_close(type, fileName, fpFile, fpPipe);
		return (KERRAPP);
	}

// Fill the file

	spi_flush(handle);
	nbRead = 0; nbPackets = 0; nbImages = 0;

	while (true) {
		if (spi_read(handle, vBuffer, KPACKETSIZE, &count) == false) {
			break;
		}
		local_swap(vBuffer, KPACKETSIZE);
		local_write(type, fpFile, fpPipe, vBuffer, count);
		nbRead += count;
		if (display == KDISPLAY) {
			for (i = 0; i < count; i++) {
				fprintf(stdout, "%c", vBuffer[i]);
			}
		}
		usleep(20);
		nbPackets++;
		if (nbPackets == KXFER_NB_PACKETS) {
			nbPackets = 0;
			fprintf(stdout, "Image %d\n", ++nbImages);
		}
		if (nbRead > KMAXIMAGEREAD) {
			break;
		}
	}

	spi_close(handle);
	local_close(type, fileName, fpFile, fpPipe);
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
			*fpFile = fopen(fileName, "w");
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
			break;
		}
	}
}

/*
 * \brief local_swap
 *
 * - Swap the buffer (endianness)
 *
 */
static	void	local_swap(uint8_t *buffer, uint32_t count) {
	uint8_t		tmp;
	uint32_t	i;

	for (i = 0; i < count/2; i++) {
		tmp = *(buffer + 2*i + 0);
		*(buffer + 2*i + 0) = *(buffer + 2*i + 1);
		*(buffer + 2*i + 1) = tmp;
	}
}
