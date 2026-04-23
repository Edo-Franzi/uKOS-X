/*
; test_lcd.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Some lcd tests.
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
#include	"../../Lib_peripherals/lcd0/lcd0.h"

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"test_lcd     Some lcd tests.                           (c) EFr-2026";
STRG_LOC_CONST(aStrHelp[])		  = "Test of the lcd\n"
									"===============\n\n"

									"This tool performs some lcd tests.\n\n"

									"Input format:  test_lcd\n"
									"Output format: [result]\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2026\n\n";

static	int32_t		prgm(uint32_t argc, const char_t *argv[]);

MODULE(
	Test_lcd,									// Module name (the first letter has to be upper case)
	KID_FAM_CLI,								// Family (defined in the module.h)
	(((uint32_t)'_'<<8u)+(uint32_t)'L'),		// Module identifier (defined in the module.h)
	nullptr,									// Address of the initialisation code (early pre-init)
	prgm,										// Address of the code (prgm for tools, aStart for applications, nullptr for libraries)
	nullptr,									// Address of the clean code (clean the module)
	" 1.0",										// Revision string (major . minor)
	((1u<<BSHOW) | (1u<<BEXE_CONSOLE)),			// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0											// Execution cores
);

// CLI tool specific
// =================

// -----------------------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrIden_0[]) = "Process_LCD0";
STRG_LOC_CONST(aStrText_0[]) = "Process LCD0.                             (c) EFr-2026";
STRG_LOC_CONST(aStrIden_1[]) = "Process_LCD1";
STRG_LOC_CONST(aStrText_1[]) = "Process LCD1.                             (c) EFr-2026";
STRG_LOC_CONST(aStrIden_2[]) = "Process_LCD2";
STRG_LOC_CONST(aStrText_2[]) = "Process LCD2.                             (c) EFr-2026";
STRG_LOC_CONST(aStrIden_3[]) = "Process_LCD3";
STRG_LOC_CONST(aStrText_3[]) = "Process LCD3.                             (c) EFr-2026";
STRG_LOC_CONST(aStrIden_4[]) = "Process_LCD4";
STRG_LOC_CONST(aStrText_4[]) = "Process LCD4.                             (c) EFr-2026";

#define	KNB_COLORS	18u

const	uint16_t	aTabColor[KNB_COLORS] = { KBLACK, KNAVY, KDARKGREEN, KDARKCYAN,
											  KMAROON, KPURPLE, KOLIVE, KLIGHTGREY,
											  KBLUE, KGREEN, KCYAN, KRED,
											  KMAGENTA, KYELLOW, KWHITE, KORANGE,
											  KGREENYELLOW, KPINK };

#define	KBACKGROUNG		KBLACK

// Prototypes

static	void	local_process_0(const void *argument);
static	void	local_process_1(const void *argument);
static	void	local_process_2(const void *argument);
static	void	local_process_3(const void *argument);
static	void	local_process_4(const void *argument);

/*
 * \brief Main entry point
 *
 */
static	int32_t	prgm(uint32_t argc, const char_t *argv[]) {
	proc_t	*process_0, *process_1, *process_2, *process_3, *process_4;

	UNUSED(argc);
	UNUSED(argv);

	(void)dprintf(KSYST, "LCD tests.\n");

	lcd0_clear(KBACKGROUNG);

	PROCESS_STACKMALLOC(
		0,									// Index
		specification_0,					// Specifications (just use specification_x)
		aStrText_0,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process_0,					// Code of the process
		aStrIden_0,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_NORMAL_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		1,									// Index
		specification_1,					// Specifications (just use specification_x)
		aStrText_1,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process_1,					// Code of the process
		aStrIden_1,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_NORMAL_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		2,									// Index
		specification_2,					// Specifications (just use specification_x)
		aStrText_2,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process_2,					// Code of the process
		aStrIden_2,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_NORMAL_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		3,									// Index
		specification_3,					// Specifications (just use specification_x)
		aStrText_3,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process_3,					// Code of the process
		aStrIden_3,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_NORMAL_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	PROCESS_STACKMALLOC(
		4,									// Index
		specification_4,					// Specifications (just use specification_x)
		aStrText_4,							// Info string (nullptr if anonymous)
		KKERN_SZ_STACK_MM,					// KKERN_SZ_STACK_xx Stack size (number of words (machine size). _XL Extra large, _LL Large, _MM Medium, _SS Small)
		local_process_4,					// Code of the process
		aStrIden_4,							// Identifier (nullptr if anonymous)
		KSYST,								// Default Serial Communication Manager (KDEF0, KURTx, KSYST, ...)
		KKERN_PRIORITY_NORMAL_01			// KKERN_PRIORITY_HIGH < Priority < KKERN_PRIORITY_LOW_14. KKERN_PRIORITY_LOW_15 is reserved for the idle process
	);

	if (kern_createProcess(&specification_0, nullptr, &process_0) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "test_lcd: create proc"); exit(EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_1, nullptr, &process_1) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "test_lcd: create proc"); exit(EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_2, nullptr, &process_2) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "test_lcd: create proc"); exit(EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_3, nullptr, &process_3) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "test_lcd: create proc"); exit(EXIT_OS_FAILURE); }
	if (kern_createProcess(&specification_4, nullptr, &process_4) != KERR_KERN_NOERR) { LOG(KFATAL_USER, "test_lcd: create proc"); exit(EXIT_OS_FAILURE); }
	return (EXIT_OS_SUCCESS_CLI);
}

// Local routines
// ==============

/*
 * \brief local_process_0
 *
 * - Display textes with random colors
 *
 */
static void __attribute__ ((noreturn)) local_process_0(const void *argument) {

// Window position

	#define	KW0_X0		0u
	#define	KW0_Y0		0u
	#define	KW0_DX		16u
	#define	KW0_DY0		60u
	#define	KW0_DY1		80u
	#define	KW0_DY2		100u
	#define	KW0_DY3		120u

			uint32_t	color_0, color_1, color_2, color_3;
	const	char_t		strg0[] = "Mais nous n'avons pas peur,";
	const	char_t		strg1[] = "nous sommes toujours";
	const	char_t		strg2[] = "vainqueurs ... nous sommes ";
	const	char_t		strg3[] = "les petits Schtroumpfs.";

	UNUSED(argument);

	RESERVE(LCD0, KMODE_READ_WRITE);
	lcd0_setDirection(KDIR_XY_LRDU);
	RELEASE(LCD0, KMODE_READ_WRITE);

	while (true) {

// Write the strings with a random color

		random_read(KRANDOM_SOFT, &color_0, 1u); color_0 %= KNB_COLORS;
		random_read(KRANDOM_SOFT, &color_1, 1u); color_1 %= KNB_COLORS;
		random_read(KRANDOM_SOFT, &color_2, 1u); color_2 %= KNB_COLORS;
		random_read(KRANDOM_SOFT, &color_3, 1u); color_3 %= KNB_COLORS;

		RESERVE(LCD0, KMODE_READ_WRITE);
		lcd0_drawString((KW0_X0 + KW0_DX), (KW0_Y0 + KW0_DY0), strg0, aTabColor[color_0]);
		RELEASE(LCD0, KMODE_READ_WRITE);
		kern_suspendProcess(1000u);

		RESERVE(LCD0, KMODE_READ_WRITE);
		lcd0_drawString((KW0_X0 + KW0_DX), (KW0_Y0 + KW0_DY1), strg1, aTabColor[color_1]);
		RELEASE(LCD0, KMODE_READ_WRITE);
		kern_suspendProcess(1000u);

		RESERVE(LCD0, KMODE_READ_WRITE);
		lcd0_drawString((KW0_X0 + KW0_DX), (KW0_Y0 + KW0_DY2), strg2, aTabColor[color_2]);
		RELEASE(LCD0, KMODE_READ_WRITE);
		kern_suspendProcess(1000u);

		RESERVE(LCD0, KMODE_READ_WRITE);
		lcd0_drawString((KW0_X0 + KW0_DX), (KW0_Y0 + KW0_DY3), strg3, aTabColor[color_3]);
		RELEASE(LCD0, KMODE_READ_WRITE);
		kern_suspendProcess(1000u);
	}
}

/*
 * \brief local_process_1
 *
 * - Display random colors dots
 *
 */
static void __attribute__ ((noreturn)) local_process_1(const void *argument) {

// Window position

	#define	KW1_X0		0u
	#define	KW1_Y0		160u
	#define	KW1_DX		40u
	#define	KW1_DY		(KLCD_Y_MAX - KW1_Y0)

	uint16_t	x, y, color;
	uint32_t	value;

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(10u);
		random_read(KRANDOM_SOFT, &value, 1);

		x	  = (uint16_t)(value       % KW1_DX);
		y	  = (uint16_t)((value>>8u) % KW1_DY);
		color = (uint16_t)(value>>16u  & 0x0000FFFFu) % KNB_COLORS;

		RESERVE(LCD0, KMODE_READ_WRITE);
		lcd0_drawPoint((KW1_X0 + x), (KW1_Y0 + y), aTabColor[color]);
		RELEASE(LCD0, KMODE_READ_WRITE);
	}
}

/*
 * \brief local_process_2
 *
 * - Display random colors rectangles
 *
 */
static void __attribute__ ((noreturn)) local_process_2(const void *argument) {

// Window position

	#define	KW2_X0		(40u + 5u)
	#define	KW2_Y0		160u
	#define	KW2_DX		(KLCD_X_MAX - KW2_X0)
	#define	KW2_DY		(KLCD_Y_MAX - KW2_Y0)

			uint32_t	core, value, time = 0u;
			uint16_t	x, y, result, oldResult = 0xFFu;
			uint16_t	color_0 = 0u, color_1 = 0u, color_2 = 0u, color_3 = 0u, color_4 = 0u;
	static	uint16_t	vImage[KNB_CORES][KW2_DX * KW2_DY];

	UNUSED(argument);

	core = GET_RUNNING_CORE;

	while (true) {
		time = (time < 1u) ? (500u) : (time - 1u);
		kern_suspendProcess(time);

		for (y = 0; y < KW2_DY; y++) {
			result = y / (KW2_DY / 4);
			if (result != oldResult) {
				oldResult = result;

				random_read(KRANDOM_SOFT, &value, 1u); color_0 = aTabColor[value % KNB_COLORS];
				random_read(KRANDOM_SOFT, &value, 1u); color_1 = aTabColor[value % KNB_COLORS];
				random_read(KRANDOM_SOFT, &value, 1u); color_2 = aTabColor[value % KNB_COLORS];
				random_read(KRANDOM_SOFT, &value, 1u); color_3 = aTabColor[value % KNB_COLORS];
				random_read(KRANDOM_SOFT, &value, 1u); color_4 = aTabColor[value % KNB_COLORS];
			}

			for (x = 0; x < (uint16_t)KW2_DX; x++) {
				switch (x / (KW2_DX / 5u)) {
					default:
					case 0u: { vImage[core][(y * KW2_DX) + x] = color_0; break; }
					case 1u: { vImage[core][(y * KW2_DX) + x] = color_1; break; }
					case 2u: { vImage[core][(y * KW2_DX) + x] = color_2; break; }
					case 3u: { vImage[core][(y * KW2_DX) + x] = color_3; break; }
					case 4u: { vImage[core][(y * KW2_DX) + x] = color_4; break; }
				}
			}
		}

		RESERVE(LCD0, KMODE_READ_WRITE);
		lcd0_drawPicture(KW2_X0, KW2_Y0, KW2_DX, KW2_DY, &vImage[core][0]);
		RELEASE(LCD0, KMODE_READ_WRITE);
	}
}

/*
 * \brief local_process_3
 *
 * - Display the uKOS-X logo
 *
 */
static void __attribute__ ((noreturn)) local_process_3(const void *argument) {

	#define	KW3_X0		60u
	#define	KW3_Y0		20u
	#define	KW3_DX		127u
	#define	KW3_DY		17u

					uint16_t	x, y, color[10];
					uint32_t	value;
	static	const	char_t		aUKOS[KW3_DY][KW3_DX] = {
									{ "              2       2   3333333    44444444            6        6                 7777777   888888888   9999999    00000000" },
									{ "              2      2   3       3  4                    6        6                7       7      8      9       9  0        " },
									{ "              2     2    3       3  4                     6      6                 7       7      8      9       9  0        " },
									{ "              2    2     3       3  4                     6      6                 7       7      8      9       9  0        " },
									{ "              2   2      3       3  4                      6    6                  7       7      8      9       9  0        " },
									{ "              2  2       3       3  4                      6    6                  7       7      8      9       9  0        " },
									{ "              2 2        3       3  4                       6  6                   7       7      8      9       9  0        " },
									{ "              22         3       3   4444444     555555      66                    77777777       8      9       9   0000000 " },
									{ "              2 2        3       3          4               6  6                   7 7            8      9       9          0" },
									{ "     1     1  2  2       3       3          4               6  6                   7  7           8      9       9          0" },
									{ "     1     1  2   2      3       3          4              6    6                  7   7          8      9       9          0" },
									{ "     1     1  2    2     3       3          4              6    6                  7    7         8      9       9          0" },
									{ "     1     1  2     2    3       3          4             6      6                 7     7        8      9       9          0" },
									{ "    11     1  2      2   3       3          4             6      6                 7      7       8      9       9          0" },
									{ "   1  11111   2       2   3333333   44444444             6        6                7       7      8       9999999   00000000 " },
									{ "  1                                                                                                                          " },
									{ " 1                                                                                                                           " }
								};

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(1000u);
		random_read(KRANDOM_SOFT, &value, 1u); color[0] = (uint16_t)(value>>16u & 0x0000FFFFu) % KNB_COLORS;
		random_read(KRANDOM_SOFT, &value, 1u); color[1] = (uint16_t)(value>>16u & 0x0000FFFFu) % KNB_COLORS;
		random_read(KRANDOM_SOFT, &value, 1u); color[2] = (uint16_t)(value>>16u & 0x0000FFFFu) % KNB_COLORS;
		random_read(KRANDOM_SOFT, &value, 1u); color[3] = (uint16_t)(value>>16u & 0x0000FFFFu) % KNB_COLORS;
		random_read(KRANDOM_SOFT, &value, 1u); color[4] = (uint16_t)(value>>16u & 0x0000FFFFu) % KNB_COLORS;
		random_read(KRANDOM_SOFT, &value, 1u); color[5] = (uint16_t)(value>>16u & 0x0000FFFFu) % KNB_COLORS;
		random_read(KRANDOM_SOFT, &value, 1u); color[6] = (uint16_t)(value>>16u & 0x0000FFFFu) % KNB_COLORS;
		random_read(KRANDOM_SOFT, &value, 1u); color[7] = (uint16_t)(value>>16u & 0x0000FFFFu) % KNB_COLORS;
		random_read(KRANDOM_SOFT, &value, 1u); color[8] = (uint16_t)(value>>16u & 0x0000FFFFu) % KNB_COLORS;
		random_read(KRANDOM_SOFT, &value, 1u); color[9] = (uint16_t)(value>>16u & 0x0000FFFFu) % KNB_COLORS;

		for (y = 0u; y < KW3_DY; y++) {
			for (x = 0u; x < KW3_DX; x++) {
				switch (aUKOS[y][x]) {
					case '0':  { RESERVE(LCD0, KMODE_READ_WRITE); lcd0_drawPoint((KW3_X0 + x), (KW3_Y0 + y), aTabColor[color[0]]); RELEASE(LCD0, KMODE_READ_WRITE); break; }
					case '1':  { RESERVE(LCD0, KMODE_READ_WRITE); lcd0_drawPoint((KW3_X0 + x), (KW3_Y0 + y), aTabColor[color[1]]); RELEASE(LCD0, KMODE_READ_WRITE); break; }
					case '2':  { RESERVE(LCD0, KMODE_READ_WRITE); lcd0_drawPoint((KW3_X0 + x), (KW3_Y0 + y), aTabColor[color[2]]); RELEASE(LCD0, KMODE_READ_WRITE); break; }
					case '3':  { RESERVE(LCD0, KMODE_READ_WRITE); lcd0_drawPoint((KW3_X0 + x), (KW3_Y0 + y), aTabColor[color[3]]); RELEASE(LCD0, KMODE_READ_WRITE); break; }
					case '4':  { RESERVE(LCD0, KMODE_READ_WRITE); lcd0_drawPoint((KW3_X0 + x), (KW3_Y0 + y), aTabColor[color[4]]); RELEASE(LCD0, KMODE_READ_WRITE); break; }
					case '5':  { RESERVE(LCD0, KMODE_READ_WRITE); lcd0_drawPoint((KW3_X0 + x), (KW3_Y0 + y), aTabColor[color[5]]); RELEASE(LCD0, KMODE_READ_WRITE); break; }
					case '6':  { RESERVE(LCD0, KMODE_READ_WRITE); lcd0_drawPoint((KW3_X0 + x), (KW3_Y0 + y), aTabColor[color[6]]); RELEASE(LCD0, KMODE_READ_WRITE); break; }
					case '7':  { RESERVE(LCD0, KMODE_READ_WRITE); lcd0_drawPoint((KW3_X0 + x), (KW3_Y0 + y), aTabColor[color[7]]); RELEASE(LCD0, KMODE_READ_WRITE); break; }
					case '8':  { RESERVE(LCD0, KMODE_READ_WRITE); lcd0_drawPoint((KW3_X0 + x), (KW3_Y0 + y), aTabColor[color[8]]); RELEASE(LCD0, KMODE_READ_WRITE); break; }
					case '9':  { RESERVE(LCD0, KMODE_READ_WRITE); lcd0_drawPoint((KW3_X0 + x), (KW3_Y0 + y), aTabColor[color[9]]); RELEASE(LCD0, KMODE_READ_WRITE); break; }
					default: {

// Make MISRA happy :-)

						break;
					}
				}
			}
		}
	}
}

/*
 * \brief local_process_4
 *
 * - Change the background
 *
 */
static void __attribute__ ((noreturn)) local_process_4(const void *argument) {
	uint16_t	color;
	uint32_t	value;

	UNUSED(argument);

	while (true) {
		kern_suspendProcess(60000u);
		random_read(KRANDOM_SOFT, &value, 1u);

		color = (uint16_t)((value>>16u) & 0x0000FFFFu) % KNB_COLORS;

		RESERVE(LCD0, KMODE_READ_WRITE);
		lcd0_clear(aTabColor[color]);
		RELEASE(LCD0, KMODE_READ_WRITE);
	}
}
