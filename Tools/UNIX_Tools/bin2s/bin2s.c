/*
; bin2s.
; ======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Generate an S file.
;
; Usage:	bin2s [-type] [hexa_address] [binary_file] [s_file]
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
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

// Prototypes

static	void		local_generateSFile(uint32_t sFormat, uint32_t address, FILE *fpin, FILE *fpout);
static	uint32_t	local_getSx(char_t type);
static	uint32_t	local_getAddress(const char_t *hexString);
static	void		local_usage(void);

/*
 * \brief Main entry point
 *
 */
int		main(int32_t argc, const char_t *argv[]) {
			uint32_t	sx, address;
			FILE		*fpin, *fpout;
	const	char_t		*inputFileName, *outputFileName;

	fprintf(stdout, __DATE__"  "__TIME__" (c) EFr-2026\n");

// Analyse the command line
// ------------------------
//
// Available cases:
//
// 1. bin2s binary_file s_file	  ---> Convert a binary to a S39 Motorola file
// 2. bin2s -1 binary_file s_file ---> Convert a binary to a S17 Motorola file
// 3. bin2s -2 binary_file s_file ---> Convert a binary to a S28 Motorola file
// 4. bin2s -3 binary_file s_file ---> Convert a binary to a S39 Motorola file

	sx = 3;
	address = 0;
	if (argc < 3) {
		fprintf(stderr, "### Error: too few parameters ...\n");
		local_usage();
		return (EXIT_OS_FAILURE);
	}

	else if (argc > 5) {
		fprintf(stderr, "### Error: too many parameters ...\n");
		local_usage();
		return (EXIT_OS_FAILURE);
	}

	else if (argc == 3) {
		inputFileName  = argv[1];
		outputFileName = argv[2];
	}

	else if (argc == 4) {
		if (*(argv[1]) != '-') {
			local_usage();
			return (EXIT_OS_FAILURE);
		}

		sx = local_getSx(*(argv[1] + 1));
		inputFileName  = argv[2];
		outputFileName = argv[3];
	}

	else if (argc == 5) {
		if (*(argv[1]) != '-') {
			local_usage();
			return (EXIT_OS_FAILURE);
		}

		sx = local_getSx(*(argv[1] + 1));
		address = local_getAddress(argv[2]);
		inputFileName  = argv[3];
		outputFileName = argv[4];
	}

	else {
		local_usage();
		return (EXIT_OS_FAILURE);
	}

// Convert the binary file to an S file

	fpin  = fopen(inputFileName, "rb");
	fpout = fopen(outputFileName, "w");

	if (fpin == nullptr) {
		fclose(fpin);
		fprintf(stderr, "### Error: input file not found\n");
		return (EXIT_OS_FAILURE);
	}

	if (fpout == nullptr) {
		fclose(fpout);
		fprintf(stderr, "### Error: output file not found\n");
		return (EXIT_OS_FAILURE);
	}

	local_generateSFile(sx, address, fpin, fpout);
	fclose(fpin);
	fclose(fpout);
	fprintf(stdout, "s%d file generated\n", sx);
	return (EXIT_OS_SUCCESS);
}

// Local routines
// ==============

/*
 * \brief local_generateSFile
 *
 * - Convert the binary to the xml file for some SPI EEPROMs
 * - Available S formats:
 * - Type Length Address Code/Data Checksum
 *
 * - Type:
 *   - S0 The header
 *   - S1 A record containing code/data and the 2-Byte address at which the code/data is to reside
 *   - S2 A record containing code/data and the 3-Byte address at which the code/data is to reside
 *   - S3 A record containing code/data and the 4-Byte address at which the code/data is to reside
 *   - S5 A record containing the number of S1-S2-S3 transmitted in a particular bloc
 *   - S7 A termination record for S3 records. The address field of 4-bytes is the execution address
 *   - S8 A termination record for S2 records. The address field of 3-bytes is the execution address
 *   - S9 A termination record for S1 records. The address field of 2-bytes is the execution address
 *
 * - Length:
 *   - The count of the character pair in the record, excluding the type and the record length
 *
 * - Address:
 *   - 2, 3 or 4-bytes address
 *
 * - Code/Data:
 *   - 0-2n Bytes
 *
 * - Checksum:
 *   - The last significant Byte of the one's complement of the sum of the values represented
 *   - by the pair of characters making up the record length, address, and the code/data fields
 *
 * - Example:
 *   - S3 25 00128000 6000007C465555410012800000000504001A0000000013020000001C312E3030 96
 *
 * \param[in]	sFormat	Format of the S record
 * \param[in]	fpin	Ptr on the binary file
 * \param[in]	fpout	Ptr on the checksum file
 *
 * \note This function does not return a value (None).
 *
 */
static	void	local_generateSFile(uint32_t sFormat, uint32_t address, FILE *fpin, FILE *fpout) {
					uint32_t	ckSumm = 0, i = 0, j;
					char_t		aByte, buffer[32];
	static	const	char_t		valToStr[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

// Write the header S0 (option)

	fprintf(fpout, "S0030000FC\n");

// Write the Sx (1-2-3) frame

	while (fscanf(fpin, "%c", &aByte) == 1) {

// Full 32-Byte frame

		buffer[i] = aByte;
		i++;
		ckSumm = ckSumm + aByte;
		if (i == 32) {
			switch (sFormat) {
				case 1: {
					fprintf(fpout, "S1%02X%04X", (32+2+1), address);
					ckSumm += (32+2+1);
					ckSumm += address & 0xFF;
					ckSumm += (address>>8) & 0xFF;
					break;
				}
				case 2: {
					fprintf(fpout, "S2%02X%06X", (32+3+1), address);
					ckSumm += (32+3+1);
					ckSumm += address & 0xFF;
					ckSumm += (address>>8) & 0xFF;
					ckSumm += (address>>16) & 0xFF;
					break;
				}
				case 3: {
					fprintf(fpout, "S3%02X%08X", (32+4+1), address);
					ckSumm += (32+4+1);
					ckSumm += address & 0xFF;
					ckSumm += (address>>8) & 0xFF;
					ckSumm += (address>>16) & 0xFF;
					ckSumm += (address>>24) & 0xFF;
					break;
				}
				default: {

// Make MISRA happy :-)

					break;
				}
			}

			for (j = 0; j < i; j++) {
				fprintf(fpout, "%c%c", valToStr[(buffer[j]>>4) & 0x0F], valToStr[buffer[j] & 0x0F]);
			}

			fprintf(fpout, "%02X\n", (~ckSumm) & 0xFF);
			i = 0;
			ckSumm = 0;
			address += 32;
		}
	}

// Not complete 32-Byte frame

		switch (sFormat) {
			case 1: {
				fprintf(fpout, "S1%02X%04X", (i+2+1), address);
				ckSumm += (i+2+1);
				ckSumm += address & 0xFF;
				ckSumm += (address>>8) & 0xFF;
				break;
			}
			case 2: {
				fprintf(fpout, "S2%02X%06X", (i+3+1), address);
				ckSumm += (i+3+1);
				ckSumm += address & 0xFF;
				ckSumm += (address>>8) & 0xFF;
				ckSumm += (address>>16) & 0xFF;
				break;
			}
			case 3: {
				fprintf(fpout, "S3%02X%08X", (i+4+1), address);
				ckSumm += (i+4+1);
				ckSumm += address & 0xFF;
				ckSumm += (address>>8) & 0xFF;
				ckSumm += (address>>16) & 0xFF;
				ckSumm += (address>>24) & 0xFF;
				break;
			}
			default: {

// Make MISRA happy :-)

				break;
			}
		}

	for (j = 0; j < i; j++) {
		fprintf(fpout, "%c%c", valToStr[(buffer[j]>>4) & 0xF], valToStr[buffer[j] & 0xF]);
	}

	fprintf(fpout, "%02X\n", (~ckSumm) & 0xFF);

// Write the Sx (9-8-7) frame

	ckSumm  = 0;
	address = 0;

	switch (sFormat) {
		case 1: {
			ckSumm = ckSumm + address + (2+1);
			fprintf(fpout, "S9%02X%04X%02X\n", (2+1), address, (~ckSumm) & 0xFF);
			break;
		}
		case 2: {
			ckSumm = ckSumm + address + (3+1);
			fprintf(fpout, "S8%02X%06X%02X\n", (3+1), address, (~ckSumm) & 0xFF);
			break;
		}
		case 3: {
			ckSumm = ckSumm + address + (4+1);
			fprintf(fpout, "S7%02X%08X%02X\n", (4+1), address, (~ckSumm) & 0xFF);
			break;
		}
		default: {

// Make MISRA happy :-)

			break;
		}
	}
}

/*
 * \brief local_getSx
 *
 * \param[in]	type	ASCII format of the S record
 * \return		sx		Integer format of the S record
 *
 */
static	uint32_t	local_getSx(char_t type) {
	uint32_t	sx;

	switch (type) {
		case '1': { sx = 1; break; }
		case '2': { sx = 2; break; }
		case '3':
		default:  { sx = 3; break; }
	}

	return (sx);
}

/*
 * \brief local_getAddress
 *
 * \param[in]	hexString	Address in a hexa string
 * \return		address		Integer format of the address
 *
 */
static	uint32_t	local_getAddress(const char_t *hexString) {

	return ((uint32_t)strtol(hexString, 0, 16u));
}

/*
 * \brief local_usage
 *
 * \param[in]	-
 *
 * \note This function does not return a value (None).
 *
 */
static	void	local_usage(void) {

	fprintf(stderr, "\n");
	fprintf(stderr, "Usage:       bin2s [-S=3] [hex address=0] [binary_file] [s_file]\n");
	fprintf(stderr, "Example:     bin2s binary_file.bin s_file.s3\n");
	fprintf(stderr, "             bin2s -1 binary_file.bin s_file.s3\n");
	fprintf(stderr, "             bin2s -2 0xD0000000 binary_file.bin s_file.s3\n\n");
}
