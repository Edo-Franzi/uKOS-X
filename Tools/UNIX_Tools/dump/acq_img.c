/*
; acq_img.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Dump images from the serial stream to a file.
;
; Usage:	acq_img [W H] [driverID]
;
;			acq_img 320 240 usbserial-FT000001
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

#define	KMAXNBREAD	1000000000000			// 1'000'000'000'000 bytes before stopping
#define	KBAUDRATE	3000000					// Baudrate

enum {
		KERRNOT = 0,
		KERRAPP,
		KERRCLI
};

static	uint8_t		vBuffer[4 * (752 * 480)];

// Prototypes

extern  void		d2x_list(void);
extern	FT_HANDLE	d2x_open(const char_t *driverID, int32_t baudrate);
extern	void		d2x_close(FT_HANDLE handle);
extern	bool		d2x_readAByte(FT_HANDLE handle, uint8_t *receive);
extern	bool		d2x_read(FT_HANDLE handle, uint8_t *receive, uint32_t *count);
extern	void		d2x_flush(FT_HANDLE handle);

static	bool		local_open(const char_t *fileName, FILE **fpFile);
static	void		local_close(FILE *fpFile);
static	void		local_write(FILE *fpFile, uint8_t *buffer, uint32_t count);
static	int32_t		local_app_d2x(char_t *driverID, uint32_t baudrate, uint32_t szImage);

/*
 * \brief Main entry point
 *
 */
int		main(int32_t argc, const char_t *argv[]) {
			char_t		driverID[50];
			int32_t		error;
			int32_t		width, heigh;
	const	char_t		*driver;

	fprintf(stdout, "\nDump images from the serial stream to image_xx.raw files\n");
	fprintf(stdout, __DATE__"  "__TIME__" (c) EFr-2026\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// acq_img 320 240 usbserial-FT000001
// acq_img 752 480 usbserial-FT000001

	error = KERRNOT;
	switch (argc) {
		case 4: {
			width = atoi(argv[1]);			//
			heigh = atoi(argv[2]);			// Image dimensions
			strcpy(driverID, argv[3]);		// Driver ID (FT000001)
			break;
		}
		default: {
			error = KERRCLI;
			break;
		}
	}

	if (error == KERRNOT) {
		error = local_app_d2x(driverID, KBAUDRATE, (width * heigh));
	}

	switch (error) {
		case KERRNOT: { fprintf(stdout, "Terminated\n");								return (EXIT_OS_SUCCESS); }
		case KERRAPP: { fprintf(stderr, "### Error: input/output file not found\n");	return (EXIT_OS_FAILURE); }
		case KERRCLI: { fprintf(stderr, "acq_img [W H] [driverID]\n");
						fprintf(stderr, "[driverID] driverID (ie. FT000001)\n");
						fprintf(stderr, "[H][W] image dimensions\n");
						d2x_list();														return (EXIT_OS_FAILURE); }
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
 * - Open the driver & the file
 * - Fill the file
 * - Close the driver & the file
 *
 */
static	int32_t	local_app_d2x(char_t *driverID, uint32_t baudrate, uint32_t szImage) {
	FT_HANDLE	handle;
	uint64_t	totalRead;
	uint32_t	i, count, nbRead, nbBytes, nbImage, nbBytesToWrite;
	bool		error;
	FILE		*fpFile;
	char		fileName[100];

	handle = d2x_open(driverID, baudrate);
	if (handle == nullptr) {
		d2x_close(handle);
		return (KERRAPP);
	}

	d2x_flush(handle);

// Read as many images as possible
// -------------------------------

	totalRead = 0;
	nbBytes   = 0;
	nbImage   = 0;

	while (true) {
		sprintf(fileName, "/tmp/image_%d.raw", nbImage);
		error = local_open(fileName, &fpFile);
		if (error == false) {
			d2x_close(handle);
			local_close(fpFile);
			return (KERRAPP);
		}

// Fill the file (if we have read more bytes in the previous cycle)

		if (nbBytes > 0) {
			local_write(fpFile, &vBuffer[nbBytesToWrite], nbBytes);
		}

// Read an image and save it into the file
//
// Try to read a full image
// If false, then timeout error
// If the number of bytes is > 320x240, then save the image & prepare for the next one

		while (true) {
			if (d2x_read(handle, vBuffer, &count) == false) {
				d2x_close(handle);
				local_close(fpFile);
				return (KERRNOT);
			}

			nbBytesToWrite = ((nbBytes + count) > szImage) ? (szImage - nbBytes) : (count);

			nbBytes   += count;
			totalRead += count;
			if (totalRead > KMAXNBREAD) {
				d2x_close(handle);
				local_close(fpFile);
				return (KERRNOT);
			}

// If the number of read bytes is < 320x240, then save into the image file
// If not, close the file and continue

			local_write(fpFile, vBuffer, nbBytesToWrite);

			if (nbBytes > szImage) {
				nbImage++;
				nbBytes -= szImage;
				local_close(fpFile);
				break;
			}
		}
	}
}

/*
 * \brief local_open
 *
 * - Open a file
 *
 */
static	bool	local_open(const char_t *fileName, FILE **fpFile) {

	*fpFile = fopen(fileName, "w");
	return (*fpFile == 0) ? (false) : (true);
}

/*
 * \brief local_close
 *
 * - Close a file or a pipe
 *
 */
static	void	local_close(FILE *fpFile) {

	fclose(fpFile);
}

/*
 * \brief local_write
 *
 * - Write a file or a pipe
 *
 */
static	void	local_write(FILE *fpFile, uint8_t *buffer, uint32_t count) {

	fwrite(buffer, 1, (size_t)count, fpFile);
	fflush(fpFile);
}
