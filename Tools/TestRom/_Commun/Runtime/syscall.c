/*
; syscall.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		The syscall.
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

#include	"tests.h"
#include	<stddef.h>
#include	<errno.h>
#include	<sys/stat.h>
#include	<sys/types.h>

void	*_sbrk(ptrdiff_t incr) {

	(void)incr;

	errno = ENOMEM;
	return ((void *)-1);
}

int		_write(int fd, const void *buf, size_t count) {

	(void)fd;
	(void)buf;

	return ((int)count);
}

int		_read(int fd, void *buf, size_t count) {

	(void)fd;
	(void)buf;
	(void)count;

	errno = ENOSYS;
	return (-1);
}

int		_close(int fd) {

	(void)fd;

	return (-1);
}

int		_fstat(int fd, struct stat *st) {

	(void)fd;
	st->st_mode = S_IFCHR;

	return (0);
}

int		_isatty(int fd) {

	(void)fd;

	return (1);
}

off_t	_lseek(int fd, off_t offset, int whence) {

	(void)fd;
	(void)offset;
	(void)whence;

	return (0);
}

void	_exit(int status) {
	(void)status;

	while (true) { ; }
}

int		_kill(int pid, int sig) {

	(void)pid;
	(void)sig;

	errno = ENOSYS;
	return (-1);
}

int		_getpid(void) {

	return (1);
}