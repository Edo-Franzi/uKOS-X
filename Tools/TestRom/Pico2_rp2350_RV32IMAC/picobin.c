/*
; picobin.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-04-30
; Modifs:
;
; Project:	uKOS-X
; Goal:		Picobin IMAGE_DEF block for RP2350 RISC-V boot. The bootrom reads the
;			entry point and initial SP from this block; both fields are resolved by
;			the linker against Reset_C0_Handler and linker_topStackFirst_C0, so they
;			track the real addresses if the image is relaid out.
;
;   (c) 2026, Laurent von Allmen
;   ----------------------------
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

#define	NO_PICO_PLATFORM
#include	"picobin.h"
#include	<stdint.h>

// Item header layout in flash: low byte = item id, high byte = item size in
// 32-bit words (counted from the start of the item to the start of the next)

#define	PICOBIN_HDR(size_words, id)		(uint16_t)(((size_words)<<8u) | (id))

#ifdef	__riscv
extern	void	Reset_C0_Handler(void);
extern	uint8_t	linker_topStackFirst_C0[];

struct	picobin_image_def {
	uint32_t	start;
	uint16_t	image_type_hdr;
	uint16_t	image_type_flags;
	uint16_t	entry_hdr;
	uint16_t	entry_pad;
	void		(*entry_point)(void);
	void		*initial_sp;
	uint16_t	last_hdr;
	uint16_t	last_pad;
	uint32_t	next;
	uint32_t	end;
};

[[gnu::used, gnu::section(".picobin_block")]]
static	const	struct picobin_image_def picobin_block = {
	.start				= PICOBIN_BLOCK_MARKER_START,
	.image_type_hdr		= PICOBIN_HDR(1u, PICOBIN_BLOCK_ITEM_1BS_IMAGE_TYPE),
	.image_type_flags	= (uint16_t)(PICOBIN_IMAGE_TYPE_IMAGE_TYPE_AS_BITS(EXE)
									| PICOBIN_IMAGE_TYPE_EXE_CPU_AS_BITS(RISCV)
									| PICOBIN_IMAGE_TYPE_EXE_CHIP_AS_BITS(RP2350)),
	.entry_hdr			= PICOBIN_HDR(3u, PICOBIN_BLOCK_ITEM_1BS_ENTRY_POINT),
	.entry_pad			= 0u,
	.entry_point		= &Reset_C0_Handler,
	.initial_sp			= linker_topStackFirst_C0,
	.last_hdr			= PICOBIN_HDR(4u, PICOBIN_BLOCK_ITEM_2BS_LAST),
	.last_pad			= 0u,
	.next				= 0u,
	.end				= PICOBIN_BLOCK_MARKER_END,
};

#else
struct	picobin_image_def {
	uint32_t	start;
	uint16_t	image_type_hdr;
	uint16_t	image_type_flags;
	uint16_t	last_hdr;
	uint16_t	last_pad;
	uint32_t	next;
	uint32_t	end;
};

[[gnu::used, gnu::section(".picobin_block")]]
static	const	struct picobin_image_def picobin_block = {
	.start				= PICOBIN_BLOCK_MARKER_START,
	.image_type_hdr		= PICOBIN_HDR(1u, PICOBIN_BLOCK_ITEM_1BS_IMAGE_TYPE),
	.image_type_flags	= (uint16_t)(PICOBIN_IMAGE_TYPE_IMAGE_TYPE_AS_BITS(EXE)
									| PICOBIN_IMAGE_TYPE_EXE_SECURITY_AS_BITS(S)
									| PICOBIN_IMAGE_TYPE_EXE_CPU_AS_BITS(ARM)
									| PICOBIN_IMAGE_TYPE_EXE_CHIP_AS_BITS(RP2350)),
	.last_hdr			= PICOBIN_HDR(1u, PICOBIN_BLOCK_ITEM_2BS_LAST),
	.last_pad			= 0u,
	.next				= 0u,
	.end				= PICOBIN_BLOCK_MARKER_END,
};

#endif
