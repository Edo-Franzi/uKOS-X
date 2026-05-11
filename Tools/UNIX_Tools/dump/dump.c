/*
; dump.
; =====

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Dump a serial stream on a file.
;
; Usage:	dump [driverID]
;			or
; 			dump [driver] [driverID] [baudrate] [display] [type] [file_name]
;			driver		input	-vcp | -d2x
;			driverID 	input	(ie. usbserial-FT000001) for the vcp driver\n");
;			driverID    input	(ie. FT000001)           for the d2x driver\n");
;			baudrate	input	serial baudrate
;			display		input	-display | -nodisplay
;			type		input	-pipe | -file
;			file_name	output	the file_name
;
;			1. rm -rf /tmp/file_name
;			2. dump -vcp usbserial-FT000001 460800 -display -file /tmp/file_name
;			   dump -d2x FTWS6VG0D 460800 -nodisplay -pipe /tmp/file_name
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

#define	KMAXNBREAD				1000000000000							// 1'000'000'000'000 bytes before stopping

enum {
		KVCP = 0,
		KD2X
};

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

extern  void		vcp_list(void);
extern	int32_t		vcp_open(const char_t *driverID, int32_t baudrate);
extern	void		vcp_close(int32_t handle);
extern	bool		vcp_readAByte(int32_t handle, uint8_t *receive);
extern	bool		vcp_read(int32_t handle, uint8_t *receive, uint32_t *count);
extern	void		vcp_flush(int32_t handle);

extern  void		d2x_list(void);
extern	FT_HANDLE	d2x_open(const char_t *driverID, int32_t baudrate);
extern	void		d2x_close(FT_HANDLE handle);
extern	bool		d2x_readAByte(FT_HANDLE handle, uint8_t *receive);
extern	bool		d2x_read(FT_HANDLE handle, uint8_t *receive, uint32_t *count);
extern	void		d2x_flush(FT_HANDLE handle);

static	bool		local_open(uint32_t type, const char_t *fileName, FILE **fpFile, int32_t *fpPipe);
static	void		local_close(uint32_t type, const char_t *fileName, FILE *fpFile, int32_t fpPipe);
static	void		local_write(uint32_t type, FILE *fpFile, int32_t fpPipe, uint8_t *buffer, uint32_t count);
static	int32_t		local_app_vcp(char_t *driverID, uint32_t type, uint32_t display, const char_t *fileName, uint32_t baudrate);
static	int32_t		local_app_d2x(char_t *driverID, uint32_t type, uint32_t display, const char_t *fileName, uint32_t baudrate);

/*
 * \brief Main entry point
 *
 */
int		main(int32_t argc, const char_t *argv[]) {
	const	char_t		*fileName, *driver;
	char_t		driverID[50];
	int32_t		error;
	uint32_t	mode, type, display, baudrate;

	fprintf(stdout, "\nXfer data from the selected D2XX/vcp I/O port to the /tmp/pipe file/pipe\n");
	fprintf(stdout, __DATE__"  "__TIME__" (c) EFr-2026\n");

// Analyse the command line
// ------------------------
//
// Example:
//
// dump DCWZ1FL8
// dump -vcp DCWZ1FL8 115200 -display -file /tmp/file_name
// dump -d2x DCWZ1FL8 460800 -nodisplay -pipe /tmp/file_name

	error = KERRNOT;
	switch (argc) {
		case 2: {
			mode = KD2X;															// D2XX driver
			strcpy(driverID, argv[1]);												// Driver ID (FT000001)
			baudrate = 460800;														// Baudrate (460800)
			display = KDISPLAY;														// Display
			type = KFILE;															// Type file
			fileName = "/tmp/pipe";													// Filename
			break;
		}
		case 7: {
			if      (strcmp(argv[1], "-vcp")       == 0) { mode = KVCP;          }	// VCP driver
			else if (strcmp(argv[1], "-d2x")       == 0) { mode = KD2X;          }	// D2XX driver
			else                                         { error = KERRCLI; 	 }

			if      (strcmp(argv[5], "-pipe")      == 0) { type = KPIPE;         }	// Type pipe
			else if (strcmp(argv[5], "-file")      == 0) { type = KFILE;         }	// Type file
			else                                         { error = KERRCLI; 	 }

			if      (strcmp(argv[4], "-display")   == 0) { display = KDISPLAY;	 }	// Display
			else if (strcmp(argv[4], "-nodisplay") == 0) { display = KNODISPLAY; }	// No display
			else                                         { error = KERRCLI; 	 }

			strcpy(driverID, argv[2]);												// Driver ID (FT000001)
			baudrate = (uint32_t)strtoul(argv[3], nullptr, 10u);					// Baudrate (460800)
			fileName = argv[6];														// Filename
			break;
		}
		default: {
			error = KERRCLI;
			break;
		}
	}

	if (error == KERRNOT) {
		switch (mode) {
			case KVCP: { error = local_app_vcp(driverID, type, display, fileName, baudrate); break; }
			case KD2X: { error = local_app_d2x(driverID, type, display, fileName, baudrate); break; }
			default: {

// Make MISRA happy :-)

				break;
			}
		}
	}

	switch (error) {
		case KERRNOT: { fprintf(stdout, "Terminated\n");															return (EXIT_OS_SUCCESS); }
		case KERRAPP: { fprintf(stderr, "### Error: input/output file not found\n");								return (EXIT_OS_FAILURE); }
		case KERRCLI: { fprintf(stderr, "dump [driverID]\n");
						fprintf(stderr, "or\n");
						fprintf(stderr, "dump [driver] [driverID] [baudrate] [display] [type] [file_name]\n");
						fprintf(stderr, "[driver]        -vcp\n");
						fprintf(stderr, "[driver]        -d2x\n");
						fprintf(stderr, "[driverID]      driverID (ie. usbserial-FT000001) for the vcp driver\n");
						fprintf(stderr, "[driverID]      driverID (ie. FT000001)           for the d2x driver\n");
						fprintf(stderr, "[baudrate]      serial baudrate\n");
						fprintf(stderr, "[display]       -display\n");
						fprintf(stderr, "[display]       -nodisplay\n");
						fprintf(stderr, "[type]          -pipe\n");
						fprintf(stderr, "[type]          -file\n");
						fprintf(stderr, "[file_name]     the file_name file\n\n");
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
 * \brief local_app_vcp
 *
 * - Open the driver & the file or pipe
 * - Fill the file
 * - Close the driver & the file or pipe
 *
 */
static	int32_t	local_app_vcp(char_t *driverID, uint32_t type, uint32_t display, const char_t *fileName, uint32_t baudrate) {
	int32_t		handle;
	uint64_t	nbRead;
	uint32_t	i, count;
	bool		error;
	FILE		*fpFile;
	int32_t		fpPipe;

	handle = vcp_open(driverID, baudrate);
	error  = local_open(type, fileName, &fpFile, &fpPipe);
	if ((handle == 0) || (error == false)) {
		vcp_close(handle);
		local_close(type, fileName, fpFile, fpPipe);
		return (KERRAPP);
	}

// Fill the file

	vcp_flush(handle);
	nbRead = 0;

	while (true) {
		if (vcp_read(handle, vBuffer, &count) == false) {
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

	vcp_flush(handle);
	vcp_close(handle);
	local_close(type, fileName, fpFile, fpPipe);
	return (KERRNOT);
}

/*
 * \brief local_app_d2x
 *
 * - Open the driver & the file or pipe
 * - Fill the file
 * - Close the driver & the file or pipe
 *
 */
static	int32_t	local_app_d2x(char_t *driverID, uint32_t type, uint32_t display, const char_t *fileName, uint32_t baudrate) {
	FT_HANDLE	handle;
	uint64_t	nbRead;
	uint32_t	i, count;
	bool		error;
	FILE		*fpFile;
	int32_t		fpPipe;

	handle = d2x_open(driverID, baudrate);
	error  = local_open(type, fileName, &fpFile, &fpPipe);
	if ((handle == nullptr) || (error == false)) {
		d2x_close(handle);
		local_close(type, fileName, fpFile, fpPipe);
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

	d2x_flush(handle);
	d2x_close(handle);
	local_close(type, fileName, fpFile, fpPipe);
	return (KERRNOT);
}

/*
 * \brief local_open
 *
 * - Open a file or a pipe
 *
 */
static	bool	local_open(uint32_t type, const char_t *fileName, FILE **fpFile, int32_t *fpPipe) {

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
static	void	local_close(uint32_t type, const char_t *fileName, FILE *fpFile, int32_t fpPipe) {

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
			fflush(fpFile);
			break;
		}
		case KPIPE: {
			write(fpPipe, buffer, count);
			break;
		}
	}
}
