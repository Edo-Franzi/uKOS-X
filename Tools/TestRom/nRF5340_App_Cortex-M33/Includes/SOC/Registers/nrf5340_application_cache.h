/*
; nrf5340_application_cache.
; ==========================
;
; SPDX-License-Identifier: MIT
;
;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		nrf5340_application_cache equates.
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

#pragma	once

// CACHE address definitions
// -------------------------

typedef struct {
	volatile	uint32_t	RESERVED0[256];
	volatile	uint32_t	PROFILING0_IHIT;
	volatile	uint32_t	PROFILING0_IMISS;
	volatile	uint32_t	PROFILING0_DHIT;
	volatile	uint32_t	PROFILING0_DMISS;
	volatile	uint32_t	RESERVED1[4];
	volatile	uint32_t	PROFILING1_IHIT;
	volatile	uint32_t	PROFILING1_IMISS;
	volatile	uint32_t	PROFILING1_DHIT;
	volatile	uint32_t	PROFILING1_DMISS;
	volatile	uint32_t	RESERVED2[52];
	volatile	uint32_t	ENABLE;
	volatile	uint32_t	INVALIDATE;
	volatile	uint32_t	ERASE;
	volatile	uint32_t	PROFILINGENABLE;
	volatile	uint32_t	PROFILINGCLEAR;
	volatile	uint32_t	MODE;
	volatile	uint32_t	DEBUGLOCK;
	volatile	uint32_t	ERASESTATUS;
	volatile	uint32_t	WRITELOCK;
} CACHE_TypeDef;

#if (defined(__cplusplus))
#define	NCACHE_S	reinterpret_cast<CACHE_TypeDef *>(0x50001000u)

#else
#define	NCACHE_S	((CACHE_TypeDef *)0x50001000u)
#endif

// IHIT Configuration

#define	CACHE_PROFILING_IHIT_HITS							(0xFFFFFFFFu<<0)
#define	CACHE_PROFILING_IHIT_HITS_0							(0x1u<<0)

// IMISS Configuration

#define	CACHE_PROFILING_IMISS_MISSES				(0xFFFFFFFFu<<0)
#define	CACHE_PROFILING_IMISS_MISSES_0				(0x1u<<0)

// DHIT Configuration

#define	CACHE_PROFILING_DHIT_HITS					(0xFFFFFFFFu<<0)
#define	CACHE_PROFILING_DHIT_HITS_0					(0x1u<<0)

// DMISS Configuration

#define	CACHE_PROFILING_DMISS_MISSES				(0xFFFFFFFFu<<0)
#define	CACHE_PROFILING_DMISS_MISSES_0				(0x1u<<0)

// ENABLE Configuration

#define	CACHE_ENABLE_ENABLE							(0x1u<<0)
#define	CACHE_ENABLE_ENABLE_DISABLED				(0x0u<<0)
#define	CACHE_ENABLE_ENABLE_ENABLED					(0x1u<<0)

// INVALIDATE Configuration

#define	CACHE_INVALIDATE_INVALIDATE					(0x1u<<0)
#define	CACHE_INVALIDATE_INVALIDATE_INVALIDATE		(0x1u<<0)

// ERASE Configuration

#define	CACHE_ERASE_ERASE							(0x1u<<0)
#define	CACHE_ERASE_ERASE_ERASE						(0x1u<<0)

// PROFILINGENABLE Configuration

#define	CACHE_PROFILINGENABLE_ENABLE				(0x1u<<0)
#define	CACHE_PROFILINGENABLE_ENABLE_DISABLE		(0x0u<<0)
#define	CACHE_PROFILINGENABLE_ENABLE_ENABLE			(0x1u<<0)

// PROFILINGCLEAR Configuration

#define	CACHE_PROFILINGCLEAR_CLEAR					(0x1u<<0)
#define	CACHE_PROFILINGCLEAR_CLEAR_CLEAR			(0x1u<<0)

// MODE Configuration

#define	CACHE_MODE_MODE								(0x1u<<0)
#define	CACHE_MODE_MODE_CACHE						(0x0u<<0)
#define	CACHE_MODE_MODE_RAM							(0x1u<<0)

// DEBUGLOCK Configuration

#define	CACHE_DEBUGLOCK_DEBUGLOCK					(0x1u<<0)
#define	CACHE_DEBUGLOCK_DEBUGLOCK_UNLOCKED			(0x0u<<0)
#define	CACHE_DEBUGLOCK_DEBUGLOCK_LOCKED			(0x1u<<0)

// ERASESTATUS Configuration

#define	CACHE_ERASESTATUS_ERASESTATUS				(0x1u<<0)
#define	CACHE_ERASESTATUS_ERASESTATUS_IDLE			(0x0u<<0)
#define	CACHE_ERASESTATUS_ERASESTATUS_FINISHED		(0x1u<<0)

// WRITELOCK Configuration

#define	CACHE_WRITELOCK_WRITELOCK					(0x1u<<0)
#define	CACHE_WRITELOCK_WRITELOCK_UNLOCKED			(0x0u<<0)
#define	CACHE_WRITELOCK_WRITELOCK_LOCKED			(0x1u<<0)
