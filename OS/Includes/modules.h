/*
; modules.
; ========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Module IDs for uKOS-X systems.
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

#pragma	once

// Specification module macro
// --------------------------

#if (defined(__cplusplus))
extern	"C" {
#define	C_DECLARE	extern	"C"
#else
#define	C_DECLARE
#endif

typedef	struct	uKOS_header		uKOS_header_t;
typedef	struct	uKOS_directory	uKOS_directory_t;
typedef	struct	uKOS_module		uKOS_module_t;

// Header, directory and module structures
// ---------------------------------------

typedef	enum {
			KNO_MEM = 0u,																					// No memory mass
			KMEM0	= (((uint32_t)'m'<<24u) | ((uint32_t)'e'<<16u) | ((uint32_t)'m'<<8u) | (uint32_t)'0'),	// Memory location = Internal Flash
			KMEMU	= (((uint32_t)'m'<<24u) | ((uint32_t)'e'<<16u) | ((uint32_t)'m'<<8u) | (uint32_t)'U')	// Memory location = User RAM
} memLocation_t;

struct uKOS_header {
			memLocation_t		oMemLocation;																// Memory mass location
			int32_t				(*oStart)(uint32_t argc, const char_t *argv[]);								// Ptr on the start (aStart)
			uintptr_t			oLnApplication;																// Length of the application
	const	uKOS_module_t		*oModule;																	// Ptr on the module
};

typedef	enum {
			KNO_MODULE = 0u,																					// KNO_MODULE = no more modules
			KBUILD_IN,																						// KBUILD_IN = module built in
			KSERIAL_EEPROM 																					// KSERIAL_EEPROM = module built in the serial EEPROM
} moduleLocation_t;

struct uKOS_directory {
			moduleLocation_t	oModuleLocation;															// Module location
	const	uKOS_module_t		*oModule;																	// Ptr on the module
};

struct uKOS_module {
			uint32_t			oIdModule;																	// Module identifier
	const	char_t				*oStrApplication;															// Ptr on the application string
	const	char_t				*oStrHelp;																	// Ptr on the help string
			int32_t				(*oInit)(uint32_t argc, const char_t *argv[]);								// Ptr on the initialisation (early pre-init)
			int32_t				(*oExecution)(uint32_t argc, const char_t *argv[]);							// Ptr on the start (aStart)
			int32_t				(*oClean)(uint32_t argc, const char_t *argv[]);								// Ptr on the clean (clean the module)
	const	char_t				*oStrRevision;																// Program Revision
			uint8_t				oFlag;																		// Module flag
			#define				BSHOW					0u													// Visible in help
			#define				BEXE_CONSOLE			1u													// Executable from the Console
			#define				BCONFIDENTIAL			2u													// No comment

			uint8_t				oExecutionCore;																// Execution cores
			#define				BCORE_0					0u													// Only for core 0
			#define				BCORE_1					1u													// Only for core 1
			#define				BCORE_2					2u													// Only for core 2
			#define				BCORE_3					3u													// Only for core 3
};

#define	MODULE(name, family, idModule, init, execution, clean, revision, flag, executionCore)															\
	C_DECLARE	const	uKOS_module_t		a##name##_Specifications = {																				\
												.oIdModule		 = ( ((uint32_t)family<<24u) | ((uint32_t)idModule<<8u) | ((uint32_t)(uint8_t)'_')),	\
												.oStrApplication = aStrApplication,																		\
												.oStrHelp		 = aStrHelp,																			\
												.oInit			 = (int32_t (*)(uint32_t argc, const char_t *argv[]))init,								\
												.oExecution		 = (int32_t (*)(uint32_t argc, const char_t *argv[]))execution,							\
												.oClean			 = (int32_t (*)(uint32_t argc, const char_t *argv[]))clean,								\
												.oStrRevision	 = revision,																			\
												.oFlag			 = flag,																				\
												.oExecutionCore	 = executionCore																		\
											};																											\
	C_DECLARE	const	uKOS_directory_t	dir##name __attribute__ ((section (".directory"))) = {														\
												.oModuleLocation = KBUILD_IN,																			\
												.oModule		 = (const uKOS_module_t *)&a##name##_Specifications										\
											}

// ID of the library families
// --------------------------

// Families

enum {
			KID_FAM_ALL_FAMILIES   = (uint32_t)'A',															// "A x x _" ---> All families
			KID_FAM_APPLICATIONS   = (uint32_t)'U',															// "U x x _" ---> Stand-alone applications
			KID_FAM_CLI			   = (uint32_t)'X',															// "X x x _" ---> CLI
			KID_FAM_COMPANY		   = (uint32_t)'F',															// "F x x _" ---> Company
			KID_FAM_CRYPTOGRAPHICS = (uint32_t)'Q',															// "Q x x _" ---> Cryptographics
			KID_FAM_DAEMONS		   = (uint32_t)'D',															// "D x x _" ---> Daemons
			KID_FAM_GENERICS	   = (uint32_t)'L',															// "L x x _" ---> Generics
			KID_FAM_KERNELS		   = (uint32_t)'K',															// "K x x _" ---> Kernels
			KID_FAM_NEURALS		   = (uint32_t)'N',															// "N x x _" ---> Neurals
			KID_FAM_PERIPHERALS	   = (uint32_t)'P',															// "P x x _" ---> Peripherals
			KID_FAM_PROCESSES	   = (uint32_t)'T',															// "T x x _" ---> Processes
			KID_FAM_THIRD_PARTIES  = (uint32_t)'Z',															// "Z x x _" ---> Third parties
			KID_FAM_SERIALS		   = (uint32_t)'C',															// "C x x _" ---> Communications
			KID_FAM_SHARED		   = (uint32_t)'G',															// "G x x _" ---> Shared
			KID_FAM_STARTUPS	   = (uint32_t)'S',															// "S x x _" ---> Start-ups
			KID_FAM_STORAGE		   = (uint32_t)'M'															// "M x x _" ---> Storage
};

// Lib_kernels

enum {
			KNUM_KERN			   = (((uint32_t)'0'<<8) + (uint32_t)'0')									// kern manager
};

// Lib_generics

enum {
			KNUM_ASMP			   = (((uint32_t)'0'<<8) + (uint32_t)'0'),									// asmp manager
			KNUM_CALENDAR		   = (((uint32_t)'0'<<8) + (uint32_t)'1'),									// calendar manager
			KNUM_MACHINE		   = (((uint32_t)'0'<<8) + (uint32_t)'2'),									// machine manager
			KNUM_MEMO			   = (((uint32_t)'0'<<8) + (uint32_t)'3'),									// memo manager
			KNUM_NEWLIB			   = (((uint32_t)'0'<<8) + (uint32_t)'4'),									// newlib module
			KNUM_RECORD			   = (((uint32_t)'0'<<8) + (uint32_t)'5'),									// record manager
			KNUM_SYSTEM			   = (((uint32_t)'0'<<8) + (uint32_t)'6'),									// system manager
			KNUM_TEXT			   = (((uint32_t)'0'<<8) + (uint32_t)'7')									// text manager
};

// Lib_peripherals

enum {
			KNUM_ADC			   = (((uint32_t)'0'<<8) + (uint32_t)'0'),									// adc manager
			KNUM_BATTERY		   = (((uint32_t)'0'<<8) + (uint32_t)'1'),									// battery manager
			KNUM_I2C			   = (((uint32_t)'0'<<8) + (uint32_t)'2'),									// i2c manager
			KNUM_I2C0			   = (((uint32_t)'0'<<8) + (uint32_t)'3'),									// i2c0 manager
			KNUM_I2C1			   = (((uint32_t)'0'<<8) + (uint32_t)'4'),									// i2c1 manager
			KNUM_I2C2			   = (((uint32_t)'0'<<8) + (uint32_t)'5'),									// i2c2 manager
			KNUM_I2C3			   = (((uint32_t)'0'<<8) + (uint32_t)'6'),									// i2c3 manager
			KNUM_IMAGER			   = (((uint32_t)'0'<<8) + (uint32_t)'7'),									// imager manager
			KNUM_IMU			   = (((uint32_t)'0'<<8) + (uint32_t)'8'),									// imu manager
			KNUM_LED			   = (((uint32_t)'0'<<8) + (uint32_t)'9'),									// led manager
			KNUM_SPI			   = (((uint32_t)'1'<<8) + (uint32_t)'0'),									// spi manager
			KNUM_SPI0			   = (((uint32_t)'1'<<8) + (uint32_t)'1'),									// spi0 manager
			KNUM_SPI1			   = (((uint32_t)'1'<<8) + (uint32_t)'2'),									// spi1 manager
			KNUM_SPI2			   = (((uint32_t)'1'<<8) + (uint32_t)'3'),									// spi2 manager
			KNUM_SPI3			   = (((uint32_t)'1'<<8) + (uint32_t)'4'),									// spi3 manager
			KNUM_SWITCH			   = (((uint32_t)'1'<<8) + (uint32_t)'5'),									// switch manager
			KNUM_TEMPERATURE	   = (((uint32_t)'1'<<8) + (uint32_t)'6'),									// temperature manager
			KNUM_WATCHDOG		   = (((uint32_t)'1'<<8) + (uint32_t)'7')									// watchdog manager
};

// Lib_serials

enum {
			KNUM_CDC0			   = (((uint32_t)'0'<<8) + (uint32_t)'0'),									// cdc0 manager
			KNUM_CDC1			   = (((uint32_t)'0'<<8) + (uint32_t)'1'),									// cdc1 manager
			KNUM_SERIAL			   = (((uint32_t)'0'<<8) + (uint32_t)'2'),									// serial manager
			KNUM_URT0			   = (((uint32_t)'0'<<8) + (uint32_t)'3'),									// urt0 manager
			KNUM_URT1			   = (((uint32_t)'0'<<8) + (uint32_t)'4'),									// urt1 manager
			KNUM_URT2			   = (((uint32_t)'0'<<8) + (uint32_t)'5'),									// urt2 manager
			KNUM_URT3			   = (((uint32_t)'0'<<8) + (uint32_t)'6'),									// urt3 manager
			KNUM_URT4			   = (((uint32_t)'0'<<8) + (uint32_t)'7'),									// urt4 manager
			KNUM_WFI0			   = (((uint32_t)'0'<<8) + (uint32_t)'8')									// wfi0 manager
};

// Lib_cryptographics

enum {
			KNUM_RANDOM			   = (((uint32_t)'0'<<8) + (uint32_t)'0')									// random manager
};

// Lib_neurals

enum {
			KNUM_MLPN			   = (((uint32_t)'0'<<8) + (uint32_t)'0')									// mlpn manager
};

// CLI

enum {
			KNUM_BANGLA			   = (((uint32_t)'0'<<8) + (uint32_t)'0'),									// bangla module
			KNUM_BENCH			   = (((uint32_t)'0'<<8) + (uint32_t)'1'),									// bench module
			KNUM_CONSOLE		   = (((uint32_t)'0'<<8) + (uint32_t)'2'),									// console module
			KNUM_CYCLE			   = (((uint32_t)'0'<<8) + (uint32_t)'3'),									// cycle module
			KNUM_DUMP			   = (((uint32_t)'0'<<8) + (uint32_t)'4'),									// dump module
			KNUM_DUMP_LOG		   = (((uint32_t)'0'<<8) + (uint32_t)'5'),									// dumplog module
			KNUM_DUMP_SHARED	   = (((uint32_t)'0'<<8) + (uint32_t)'6'),									// dumplog module
			KNUM_DUMP_TRACE		   = (((uint32_t)'0'<<8) + (uint32_t)'7'),									// dumptrace module
			KNUM_DATE			   = (((uint32_t)'0'<<8) + (uint32_t)'8'),									// date management
			KNUM_ECHO			   = (((uint32_t)'0'<<8) + (uint32_t)'9'),									// echo module
			KNUM_ESP32			   = (((uint32_t)'1'<<8) + (uint32_t)'0'),									// esp32 module
			KNUM_FILL			   = (((uint32_t)'1'<<8) + (uint32_t)'1'),									// fill module
			KNUM_FLASH			   = (((uint32_t)'1'<<8) + (uint32_t)'2'),									// flash management
			KNUM_GDB			   = (((uint32_t)'1'<<8) + (uint32_t)'3'),									// gdb management
			KNUM_HEX_LOADER	       = (((uint32_t)'1'<<8) + (uint32_t)'4'),									// hexloader module
			KNUM_KILL			   = (((uint32_t)'1'<<8) + (uint32_t)'5'),									// kill module
			KNUM_LIST			   = (((uint32_t)'1'<<8) + (uint32_t)'6'),									// list module
			KNUM_MEMORY			   = (((uint32_t)'1'<<8) + (uint32_t)'7'),									// memory module
			KNUM_MAN			   = (((uint32_t)'1'<<8) + (uint32_t)'8'),									// man module
			KNUM_MEM_CK			   = (((uint32_t)'1'<<8) + (uint32_t)'9'),									// memck module
			KNUM_MUTEX			   = (((uint32_t)'2'<<8) + (uint32_t)'0'),									// mutex module
			KNUM_OBJECT			   = (((uint32_t)'2'<<8) + (uint32_t)'1'),									// object module
			KNUM_POWER			   = (((uint32_t)'2'<<8) + (uint32_t)'2'),									// power module
			KNUM_PROCESS		   = (((uint32_t)'2'<<8) + (uint32_t)'3'),									// process module
			KNUM_RND			   = (((uint32_t)'2'<<8) + (uint32_t)'4'),									// rnd module
			KNUM_ROMABLE_0		   = (((uint32_t)'2'<<8) + (uint32_t)'5'),									// romable module 0
			KNUM_ROMABLE_1		   = (((uint32_t)'2'<<8) + (uint32_t)'6'),									// romable module 1
			KNUM_ROMABLE_2		   = (((uint32_t)'2'<<8) + (uint32_t)'7'),									// romable module 2
			KNUM_ROMABLE_3		   = (((uint32_t)'2'<<8) + (uint32_t)'8'),									// romable module 3
			KNUM_RUN			   = (((uint32_t)'2'<<8) + (uint32_t)'9'),									// run module
			KNUM_RESTART		   = (((uint32_t)'3'<<8) + (uint32_t)'0'),									// remote module
			KNUM_S_LOADER		   = (((uint32_t)'3'<<8) + (uint32_t)'1'),									// sloader module
			KNUM_SEMAPHORE		   = (((uint32_t)'3'<<8) + (uint32_t)'2'),									// semaphore module
			KNUM_SZ_KERN		   = (((uint32_t)'3'<<8) + (uint32_t)'3'),									// szkern module
			KNUM_TEST_ASMP		   = (((uint32_t)'3'<<8) + (uint32_t)'4'),									// test of the multi-core asmp layer
			KNUM_TEST_MALLOC	   = (((uint32_t)'3'<<8) + (uint32_t)'5'),									// test of the memo_malloc module
			KNUM_TEST_HEAP		   = (((uint32_t)'3'<<8) + (uint32_t)'6'),									// test of the heap
			KNUM_TEST_RAM		   = (((uint32_t)'3'<<8) + (uint32_t)'7'),									// test of the RAM (hardware) module
			KNUM_TEST_SDCARD	   = (((uint32_t)'3'<<8) + (uint32_t)'8'),									// test of the sdcard module
			KNUM_TEST_MCORE		   = (((uint32_t)'3'<<8) + (uint32_t)'9'),									// test of the multi-core mcore layer
			KNUM_UKOS			   = (((uint32_t)'4'<<8) + (uint32_t)'0'),									// uKOS-X module
			KNUM_VIEWER			   = (((uint32_t)'4'<<8) + (uint32_t)'1'),									// viewer module
			KNUM_WK_MICROPYTHON	   = (((uint32_t)'4'<<8) + (uint32_t)'2'),									// micropython module
			KNUM_WK_SERIAL		   = (((uint32_t)'4'<<8) + (uint32_t)'3'),									// serial module
			KNUM_WK_I2C			   = (((uint32_t)'4'<<8) + (uint32_t)'4'),									// i2c module
			KNUM_WK_SPI			   = (((uint32_t)'4'<<8) + (uint32_t)'5'),									// spi module
			KNUM_X				   = (((uint32_t)'4'<<8) + (uint32_t)'6')									// X module
};

// Startups

enum {
			KNUM_BOOT			   = (((uint32_t)'0'<<8) + (uint32_t)'O'),									// boot module
			KNUM_CMNS			   = (((uint32_t)'0'<<8) + (uint32_t)'1'),									// cmns module
			KNUM_CRT0			   = (((uint32_t)'0'<<8) + (uint32_t)'2'),									// crt0 module
			KNUM_EXCE			   = (((uint32_t)'0'<<8) + (uint32_t)'3'),									// exce module
			KNUM_INIT			   = (((uint32_t)'0'<<8) + (uint32_t)'4')									// init module
};

// Processes

enum {
			KNUM_ALIVE			   = (((uint32_t)'0'<<8) + (uint32_t)'0'),									// alive module
			KNUM_EEPROM			   = (((uint32_t)'0'<<8) + (uint32_t)'1'),									// eeprom module (test)
			KNUM_GET_IMAGE		   = (((uint32_t)'0'<<8) + (uint32_t)'2'),									// getImage module
			KNUM_GET_TEMP		   = (((uint32_t)'0'<<8) + (uint32_t)'3'),									// get temp module (demo)
			KNUM_LAUNCHER		   = (((uint32_t)'0'<<8) + (uint32_t)'4'),									// launcher module
			KNUM_MCORE			   = (((uint32_t)'0'<<8) + (uint32_t)'5'),									// multi-core module
			KNUM_NOP			   = (((uint32_t)'0'<<8) + (uint32_t)'6'),									// nop module (test)
			KNUM_STARTUP		   = (((uint32_t)'0'<<8) + (uint32_t)'7'),									// startup module
			KNUM_TUSB			   = (((uint32_t)'0'<<8) + (uint32_t)'8')									// TinyUSB moduele
};

// Daemons

enum {
			KNUM_IDLE			   = (((uint32_t)'0'<<8) + (uint32_t)'0'),									// idle module
			KNUM_RTC			   = (((uint32_t)'0'<<8) + (uint32_t)'1'),									// rtc module
			KNUM_STIMER			   = (((uint32_t)'0'<<8) + (uint32_t)'2'),									// stimer module
			KNUM_STACK			   = (((uint32_t)'0'<<8) + (uint32_t)'3')									// stack module
};

// Shared

enum {
			KNUM_SHARED_I2C_0	   = (((uint32_t)'0'<<8) + (uint32_t)'0'),									// shared i2c0 module
			KNUM_SHARED_I2C_1	   = (((uint32_t)'0'<<8) + (uint32_t)'1'),									// shared i2c1 module
			KNUM_SHARED_I2C_2	   = (((uint32_t)'0'<<8) + (uint32_t)'2'),									// shared i2c2 module
			KNUM_SHARED_I2C_3	   = (((uint32_t)'0'<<8) + (uint32_t)'3'),									// shared i2c3 module
			KNUM_SHARED_SPI_0	   = (((uint32_t)'0'<<8) + (uint32_t)'4'),									// shared spi0 module
			KNUM_SHARED_SPI_1	   = (((uint32_t)'0'<<8) + (uint32_t)'5'),									// shared spi1 module
			KNUM_SHARED_SPI_2	   = (((uint32_t)'0'<<8) + (uint32_t)'6'),									// shared spi2 module
			KNUM_SHARED_SPI_3	   = (((uint32_t)'0'<<8) + (uint32_t)'7')									// shared spi3 module
};

// Storage

enum {
			KNUM_SDCARD			   = (((uint32_t)'0'<<8) + (uint32_t)'0'),									// sdcard manager
			KNUM_SERIAL_FLASH	   = (((uint32_t)'0'<<8) + (uint32_t)'1'),									// serialFlash manager
			KNUM_STORAGE		   = (((uint32_t)'0'<<8) + (uint32_t)'2')									// storage manager
};

// Applications

enum {
			KNUM_APPLICATION	   = (((uint32_t)'0'<<8) + (uint32_t)'0')									// user application module
};

// Third parties

enum {
			KNUM_FATFS			   = (((uint32_t)'0'<<8) + (uint32_t)'0'),									// FatFs library
			KNUM_MICROPYTHON	   = (((uint32_t)'0'<<8) + (uint32_t)'1'),									// mpyt (micropython)library
			KNUM_TFLITE			   = (((uint32_t)'0'<<8) + (uint32_t)'2'),									// tensorflow lite library
			KNUM_TINYUSB		   = (((uint32_t)'0'<<8) + (uint32_t)'3'),									// tinyusb library
			KNUM_LVGL			   = (((uint32_t)'0'<<8) + (uint32_t)'4'),									// lvgl library
			KNUM_DEC_NUMBER		   = (((uint32_t)'0'<<8) + (uint32_t)'5'),									// decnumber library
			KNUM_INTEL_RDF_MATH	   = (((uint32_t)'0'<<8) + (uint32_t)'6')									// IntelRDFMath library
};

#if (defined(__cplusplus))
}
#endif
