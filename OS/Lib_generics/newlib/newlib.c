/*
; newlib.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		newLib interface for gcc C compiler (reentrant version).
;
;			See: https://linux.die.net/man/
;
;			Fully or partially supported functions to support
;
;			Open - close - read - write newlib functions
;			_open_r
;			_close_r
;			_write_r
;			_read_r
;
;			time/calendat functions
;			_gettimeofday_r
;			_times_r
;
;			Generic newlib functions
;			_isatty_r
;			_wait_r
;			__errno
;			_fork_r
;			_stat_r
;			_fstat_r
;			_link_r
;			_unlink_r
;			_lseek_r
;			_getpid_r
;			_kill_r
;			_exit
;
;			Allocator newlib functions
;			_sbrk_r
;			__wrap__malloc_r
;			__wrap__free_r
;			__wrap__realloc_r
;			__wrap__calloc_r
;
;			Suported devices controlled by the open - close - read - write newlib functions
;			urt0
;			urt1
;			urt2
;			urt3
;			urt4
;			cdc0
;			cdc1
;			wfi0
;
;			syst
;			def0
;			stdin
;			stdout
;			stderr
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

#include	"uKOS.h"
#include	"kern/private/private_processes.h"
#include	<unistd.h>
#include	<errno.h>
#include	<malloc.h>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/time.h>
#include	<sys/times.h>

#if (defined(CONFIG_MAN_NEWLIB_S))

// uKOS-X specific (see the module.h)
// ==================================

// ----------------------------------I------------I-----------------------------------------I--------------I

STRG_LOC_CONST(aStrApplication[]) =	"newlib       newlib manager.                           (c) EFr-2025";
STRG_LOC_CONST(aStrHelp[])		  = "newlib manager\n"
									"==============\n\n"

									"This manager ...\n\n"

									"Module built on "__DATE__"  "__TIME__" (c) EFr-2025\n\n";

MODULE(
	Newlib,									// Module name (the first letter has to be upper case)
	KID_FAM_GENERICS,						// Family (defined in the module.h)
	KNUM_NEWLIB,							// Module identifier (defined in the module.h)
	NULL,									// Address of the initialisation code (early pre-init)
	NULL,									// Address of the code (prgm for tools, aStart for applications, NULL for libraries)
	NULL,									// Address of the clean code (clean the module)
	" 1.0",									// Revision string (major . minor)
	(1u<<BSHOW),							// Flags (BSHOW = visible with "man", BEXE_CONSOLE = executable, BCONFIDENTIAL = hidden)
	0										// Execution cores
);

// Library specific
// ================

typedef	struct	tzinfo		tzinfo_t;
typedef	struct	devOptTab	devOptTab_t;
typedef			_CLOCK_T_	clock_t;
typedef			_off_t		off_t;

#define	KNEWLIB_LN_OUTPUT_BUFFER	128u	// Size of the send buffer

// Prototypes

static	void		local_outLine(serialManager_t serialManager, const uint8_t *output, uint32_t size);
static	uint8_t		local_inbyte(serialManager_t serialManager);
static	_ssize_t	local_write(serialManager_t serialManager, const void *buf, size_t count);
static	_ssize_t	local_read(serialManager_t serialManager, void *buf, size_t count);
extern	void		crt0_exit(int number);

// NOLINTBEGIN(bugprone-reserved-identifier,cert-dcl37-c,cert-dcl51-cpp)
//
// Newlib open - close - read - write functions
// --------------------------------------------

/*
 * \brief _open_r
 *
 * - open - Open a file
 *
 */
int		_open_r(reent_t *reent, const char_t *path, int oflag, int mode) {

	UNUSED(path);
	UNUSED(oflag);
	UNUSED(mode);

	reent->_errno = ENODEV;
	return (-1);
}

/*
 * \brief _close_r
 *
 * - close - Close a file descriptor
 *
 */
int		_close_r(reent_t *reent, int fd) {

	UNUSED(fd);

	reent->_errno = EBADF;
	return (-1);
}

/*
 * \brief _write_r
 *
 * - write - Write to a file descriptor
 *
 */
_ssize_t	_write_r(reent_t *reent, int fd, const void *buf, size_t count) {
	_ssize_t			nbPrintChars;
	serialManager_t		serialManager;
	uint32_t			stdio = (uint32_t)fd;
	proc_t				*process;

	UNUSED(reent);

	switch (stdio) {

// KNOTR and KSTDERR: use the default Serial Communication Manager without to reserve it

		case KSTDERR:
		case KNOTR: {
			nbPrintChars = local_write(KDEF0, buf, count);
			break;
		}

// KSYST and KSTDIN and KSTDOUT: use the process specified Serial Communication Manager with its reservation

		case KSTDIN:
		case KSTDOUT:
		case KSYST: {
			kern_getProcessRun(&process);
			kern_getSerialForProcess(process, &serialManager);

			RESERVE_SERIAL(serialManager, KMODE_WRITE);
			nbPrintChars = local_write(serialManager, buf, count);
			RELEASE_SERIAL(serialManager, KMODE_WRITE);

			break;
		}

// KXXX: use the specified Serial Communication Manager with its reservation

		default: {
			serialManager = (serialManager_t)stdio;

			RESERVE_SERIAL(serialManager, KMODE_WRITE);
			nbPrintChars = local_write(serialManager, buf, count);
			RELEASE_SERIAL(serialManager, KMODE_WRITE);

			break;
		}
	}
	return (nbPrintChars);
}

/*
 * \brief _read_r
 *
 * - read - Read from a file descriptor
 *
 */
_ssize_t	_read_r(reent_t *reent, int fd, void *buf, size_t count) {
	_ssize_t			nbReadChars;
	serialManager_t		serialManager;
	uint32_t			stdio = (uint32_t)fd;
	proc_t				*process;

	UNUSED(reent);

	switch (stdio) {

// KNOTR and KSTDERR: use the default Serial Communication Manager without to reserve it

		case KSTDERR:
		case KNOTR: {
			nbReadChars = local_read(KDEF0, buf, count);
			break;
		}

// KSYST and KSTDIN and KSTDOUT: use the process specified Serial Communication Manager with its reservation

		case KSTDIN:
		case KSTDOUT:
		case KSYST: {
			kern_getProcessRun(&process);
			kern_getSerialForProcess(process, &serialManager);

			RESERVE_SERIAL(serialManager, KMODE_READ);
			nbReadChars = local_read(serialManager, buf, count);
			RELEASE_SERIAL(serialManager, KMODE_READ);

			break;
		}

// KXXX: use the specified Serial Communication Manager with its reservation

		default: {
			serialManager = (serialManager_t)stdio;

			RESERVE_SERIAL(serialManager, KMODE_READ);
			nbReadChars = local_read(serialManager, buf, count);
			RELEASE_SERIAL(serialManager, KMODE_READ);

			break;
		}
	}
	return (nbReadChars);
}

// Newlib time/calendat functions
// ------------------------------

/*
 * \brief _gettimeofday_r
 *
 * - gettimeofday_r - Get the date and time
 *
 */
int		_gettimeofday_r(reent_t *reent, struct timeval *tv, void *tzvp) {
	uint64_t	unixTime;

	UNUSED(reent);
	UNUSED(tzvp);

// Read the 64-bit time @ 1-us resolution
// Extract the seconds and the micro-seconds

	calendar_readUnixTime(KFROM_TIMER, &unixTime);

	tv->tv_sec  = (time_t)(unixTime / CLOCKS_PER_SEC);
	tv->tv_usec = (suseconds_t)(unixTime % CLOCKS_PER_SEC);
	return (0);
}

/*
 * \brief _times_r
 *
 * - times - Get process times
 *
 */
clock_t		_times_r(reent_t *reent, struct tms *buf) {
	struct timeval	tv = { 0, 0 };

	#if (KKERN_WITH_STATISTICS_S == true)
	proc_t	*process;

	kern_getProcessRun(&process);

	PRIVILEGE_ELEVATE;
	buf->tms_utime	= (clock_t) process->oStatistic.oTimePAvg;
	buf->tms_stime	= (clock_t)(process->oStatistic.oTimeKAvg + process->oStatistic.oTimeEAvg);
	buf->tms_cutime	= (clock_t) process->oStatistic.oTimePCum;
	buf->tms_cstime	= (clock_t)(process->oStatistic.oTimeKCum + process->oStatistic.oTimeECum);
	PRIVILEGE_RESTORE;

	#else
	*buf = (struct tms){ 0 };
	#endif

	_gettimeofday_r(reent, &tv, NULL);
	return ((clock_t)tv.tv_usec);
}

// Newlib generic functions
// ------------------------

/*
 * \brief _isatty_r
 *
 * - isatty - Test whether a file descriptor refers to a terminal
 *
 */
int		_isatty_r(reent_t *reent, int fd) {

	UNUSED(reent);

	return ((fd <= 2) ? (1) : (0));
}

/*
 * \brief _wait_r
 *
 * - wait - Wait for a child process to stop or terminate
 *
 */
int		_wait_r(reent_t *reent, const int *stat_loc) {

	UNUSED(stat_loc);

	reent->_errno = ECHILD;
	return (-1);
}

/*
 * \brief __errno
 *
 * - errno - Number of last error
 *
 */
int		*__errno(void) {

	return (&_impure_ptr->_errno);
}

/*
 * \brief _fork_r
 *
 * - fork - Create a new process
 *
 */
int		_fork_r(reent_t *reent) {

	reent->_errno = ENOTSUP;
	return (-1);
}

/*
 * \brief _stat_r
 *
 * - stat - Get file status
 *
 */
int		_stat_r(reent_t *reent, const char_t *path, struct stat *pstat) {

	UNUSED(reent);
	UNUSED(path);

	pstat->st_mode = S_IFCHR;
	return (0);
}

/*
 * \brief _fstat_r
 *
 * - fstat - Get file status
 *
 */
int		_fstat_r(reent_t *reent, int fd, struct stat *pstat) {

	UNUSED(reent);
	UNUSED(fd);

	pstat->st_mode = S_IFCHR;
	return (0);
}

/*
 * \brief _link_r
 *
 * - link - Call the link function to create a link to a file
 *
 */
int		_link_r(reent_t *reent, const char_t *oldpath, const char_t *newpath) {

	UNUSED(oldpath);
	UNUSED(newpath);

	reent->_errno = EMLINK;
	return (-1);
}

/*
 * \brief _unlink_r
 *
 * - unlink - Delete a name and possibly the file it refers to
 *
 */
int		_unlink_r(reent_t *reent, const char_t *pathname) {

	UNUSED(pathname);

	reent->_errno = EMLINK;
	return (-1);
}

/*
 * \brief _lseek_r
 *
 * - lseek - Reposition read/write file offset
 *
 */
off_t	_lseek_r(reent_t *reent, int filedes, off_t offset, int whence) {

	UNUSED(reent);
	UNUSED(filedes);
	UNUSED(offset);
	UNUSED(whence);

	return (0);
}

/*
 * \brief _getpid_r
 *
 * - getpid - Get the process ID
 *
 */
int		_getpid_r(reent_t *reent) {
	int			id;
	uint32_t	core;
	proc_t		*process;

	UNUSED(reent);

	core = GET_RUNNING_CORE;

	kern_getProcessRun(&process);
	id = (int)(((uintptr_t)process - (uintptr_t)&vKern_proc[core][0]) / sizeof(proc_t));
	return (id);
}

/*
 * \brief _kill_r
 *
 * - kill - Send signal to a process
 *
 */
int		_kill_r(reent_t *reent, int pid, int sig) {
	proc_t		*process;
	uint32_t	core;

	UNUSED(reent);
	UNUSED(sig);

	core = GET_RUNNING_CORE;

	process = (proc_t *)(((uintptr_t)pid * (uintptr_t)sizeof(proc_t)) + (uintptr_t)&vKern_proc[core][0]);
	kern_killProcess(process);
	return (0);
}

/*
 * \brief _exit
 *
 * - exit - Call the crt0 exit
 *
 */
void	__attribute__ ((noreturn)) _exit(int number) {

	crt0_exit(number);
	while (true) { ; }
}

// Newlib allocator functions
// --------------------------

// Make happy the linker.
// sbrk is not used but "end" sometimes need to be defined

uint32_t	end;

/*
 * \brief _sbrk_r
 *
 * - sbrk - Change data segment size
 *
 */
void	*_sbrk_r(reent_t *reent, ptrdiff_t increment) {

	UNUSED(increment);

	reent->_errno = ENOMEM;

// cppcheck-suppress premium-invalidPointerCast
//
	return (void *)(uintptr_t)-1;
}

/*
 * \brief __wrap__malloc_r
 *
 * - malloc - Allocate a memory block
 *
 */
void	*__wrap__malloc_r(reent_t *reent, size_t size) {
	void	*address;

	UNUSED(reent);

	address = memo_malloc(KMEMO_ALIGN_8, ((uint32_t)size * sizeof(uint8_t)), "__wrap__malloc_r");
	if (address == NULL) {
		reent->_errno = ENOMEM;
		return (NULL);
	}

	return (address);
}

/*
 * \brief __wrap__free_r
 *
 * - free - Release a memory block
 *
 */
void	__wrap__free_r(reent_t *reent, void *address) {

	UNUSED(reent);

	memo_free(address);
}

/*
 * \brief __wrap__realloc_r
 *
 * - realloc - Realloc a memory block
 *
 */
void	*__wrap__realloc_r(reent_t *reent, void *address, size_t size) {
	void	*newAddress;

	UNUSED(reent);

	newAddress = memo_realloc(KMEMO_ALIGN_8, address, (uint32_t)size, "__wrap__realloc_r");
	if (newAddress == NULL) {
		reent->_errno = ENOMEM;
		return (NULL);
	}

	return (newAddress);
}

/*
 * \brief __wrap__calloc_r
 *
 * - calloc - Allocate a memory block and set the block to 0
 *
 */
void	*__wrap__calloc_r(reent_t *reent, size_t num, size_t size) {
	void	*address;

	UNUSED(reent);

	address = memo_malloc(KMEMO_ALIGN_8, ((uint32_t)((num * size) * sizeof(uint8_t))), "__wrap__calloc_r");
	if (address == NULL) {
		reent->_errno = ENOMEM;
		return (NULL);
	}

	memset(address, 0u, (num * size));
	return (address);
}

// This variable is supposed to only be used in relation to shared libraries.
// However, some standard library C++ functions related to construction and
// destruction seem to require it

const void	*const	__dso_handle = NULL;

// Called in relation to global C++ destructors.
// This will never be used, as the system will never exit properly.
// However, some standard libraries still require an implementation of this function

void	_fini(void) {

}

// Local routines
// ==============

/*
 * \brief local_write
 *
 * - Write a string to the comm device
 *
 */
static	_ssize_t	local_write(serialManager_t serialManager, const void *buf, size_t count) {
			uint8_t		output[KNEWLIB_LN_OUTPUT_BUFFER + 2];
			uint32_t	i, j = 0u;
	const	uint8_t		*wkAscii;

	wkAscii = (const uint8_t *)buf;

	for (i = 0u; i < count; i++) {
		output[j] = wkAscii[i];

		j++;
		if (j >= KNEWLIB_LN_OUTPUT_BUFFER) {
			local_outLine(serialManager, output, j);
			j = 0u;
		}
	}

	if (j > 0u) {
		local_outLine(serialManager, output, j);
	}
	return ((_ssize_t)count);
}

/*
 * \brief local_outLine
 *
 * - Write a string to the comm device
 *
 */
static	void	local_outLine(serialManager_t serialManager, const uint8_t *output, uint32_t size) {
	int32_t		status;

	while (true) {
		status = serial_write(serialManager, output, size);
		if (status != KERR_SERIAL_NOERR) {
			kern_suspendProcess(1u);
		}
		else {

// Give some time to allow the manager to send the data
// before sending another bloc

			kern_suspendProcess(1u);
			return;
		}
	}
}

/*
 * \brief local_read
 *
 * - Read a string to the comm device
 *
 */
static	_ssize_t	local_read(serialManager_t serialManager, void *buf, size_t count) {
	uint8_t		*ascii;
	uint32_t	i;
	bool		terminate = false;

	i = (uint32_t)count;
	if (count > 0u) {
		ascii = (uint8_t *)buf;

		i = 0u;
		do {
			*(ascii + i) = local_inbyte(serialManager);
			if ((*(ascii + i) == '\n') || (*(ascii + i) == '\r')) {
				terminate = true;
			}
			i++;
		} while ((i < (uint32_t)count) && (terminate == false));
	}
	return ((_ssize_t)i);
}

/*
 * \brief local_inbyte
 *
 * - Read a byte from the comm device
 *
 */
static	uint8_t	local_inbyte(serialManager_t serialManager) {
	int32_t		status;
	uint32_t	size;
    uint8_t		byte = 0u;

	do {
		kern_suspendProcess(1u);
		size = 1u;
		status = serial_read(serialManager, &byte, &size);
	} while (status != KERR_SERIAL_NOERR);

	if (byte > 0x7Fu) { byte = (uint8_t)'?'; }

	return (byte);
}
// NOLINTEND(bugprone-reserved-identifier,cert-dcl37-c,cert-dcl51-cpp)

#endif
