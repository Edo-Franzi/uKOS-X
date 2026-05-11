/*
; tests_09.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the SPI DMA transfer (write).
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

#if (defined(TEST_09_S))
#define	KSPIM_SZ_PAGE		256

const	uint8_t		aBuffer[KSPIM_SZ_PAGE] = {
						0x0A, 0x02, 0xFF, 0x00, 0xAA, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0x02
					};

// Prototypes

static	void	local_initSPI3(void);
static	void	local_initDMA1(void);
static	void	local_DMA1_STR0_IRQHandler(void);

/*
 * \brief test_09
 *
 * - Test of the SPI DMA transfer (write)
 *
 */
void	test_09(void) {

	RCC->AHB1ENR  |= RCC_AHB1ENR_DMA1EN;
	RCC->APB1LENR |= RCC_APB1LENR_SPI3EN;

// Initialise the SPI3 and the DMA1

	local_initSPI3();
	local_initDMA1();

// Waiting for the DMA interruption

	INTERRUPTION_ON_HARD;

	while (true) {

// SPI generate TX DMAs
// Start

		cache_D_Clean_Add((void *)(uintptr_t)aBuffer, KSPIM_SZ_PAGE);

		DMA1->S0CR |= DMA_S0CR_EN;
		SPI3->CFG1 |= SPI_CFG1_TXDMAEN;
		SPI3->CR1  |= SPI_CR1_CSTART;

		LED_RED_TOGGLE;
		cmns_wait(1000000);
	}
}

/*
 * \brief local_initSPI3
 *
 * - Initialise the SPI3
 *
 */
static	void	local_initSPI3(void) {

// 8-bit transfers
// Initialise the SPI Master, POL = PHA = 0, Fclk divided by 32

	SPI3->CR1  = 0;
	SPI3->CFG1 = (4 * SPI_CFG1_MBR_0)
			   | ((8u - 1u)<<0);

	SPI3->CFG2 = SPI_CFG2_SSOE
			   | SPI_CFG2_MASTER;

	SPI3->CR1 |= SPI_CR1_SPE;
}

/*
 * \brief local_initDMA1
 *
 * - Initialise the DMA1 stream 0 for the SPI transfer
 *
 */
static	void	local_initDMA1(void) {

	INTERRUPT_VECTOR(DMA1_STR0_C0_IRQn, local_DMA1_STR0_IRQHandler);
	NVIC_SetPriority(DMA1_STR0_C0_IRQn, KINT_LEVEL_PERIPHERALS);
	NVIC_EnableIRQ(DMA1_STR0_C0_IRQn);

// Stream 0 SPI3 transfer
//
// Direct mode disable
// FIFO full
// Priority medium
// Memory size 16-bits
// Peripheral size 8-bits
// Memory auto incremented
// Transfer complete interruption
// Read bursts of 2 x 16-bits

	DMA1->S0CR   = 0x00000000;
	DMA1->S0PAR  = (uint32_t)(&SPI3->TXDR);
	DMA1->S0M0AR = (uint32_t)aBuffer;
	DMA1->S0NDTR = KSPIM_SZ_PAGE;
	DMA1->S0FCR  = 0;

	DMA1->S0CR = (1 * DMA_S0CR_PL_0)
			   | (1 * DMA_S0CR_DIR_0)
			   | DMA_S0CR_MINC
			   | DMA_S0CR_TCIE;

	DMA1->LIFCR = DMA_LIFCR_CTCIF0 | DMA_LIFCR_CFEIF0;

// Routing the SPI3 TX requests with the Stream 0, No synchronization
// Stream 0 on the DMA1 -> DMAMUX1_Channel0 (0 + 0)

	DMAMUX1->C0CR = 0x00000000;
	DMAMUX1->C0CR = 61 * DMAMUX1_C0CR_DMAREQ_ID_0;
}

/*
 * \brief local_DMA1_STR0_IRQHandler
 *
 * - DMA interruption
 *
 */
static	void	local_DMA1_STR0_IRQHandler(void) {

	UNUSED(number);

	DMA1->LIFCR = DMA_LIFCR_CTCIF0 | DMA_LIFCR_CFEIF0;

	LED_GREEN_TOGGLE;
}

#endif
