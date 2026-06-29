/*
; tests_11.
; =========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Test of the SPI DMA transfer (read).
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

#if (defined(TEST_11_S))
#define	KSPIM_SZ_PAGE		256

		uint8_t		vBuffer[KSPIM_SZ_PAGE];
const	uint8_t		aBuffer[KSPIM_SZ_PAGE] = {
						0xAA, 0x04, 0x55, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
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
						0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x04, 0x02
					};

static	char_t		vString[20];

// Prototypes

static	void	local_initSPI1(void);
static	void	local_initDMA1(void);
static	void	local_DMA1_STR0_IRQHandler(void);
static	void	local_DMA1_STR1_IRQHandler(void);

/*
 * \brief test_11
 *
 * - Test of the SPI DMA transfer (read)
 *
 */
void	test_11(void) {
	uint32_t	i, *data;

	RCC->AHB1ENR |= RCC_AHB1ENR_DMA1EN;
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;

	for (i = 0; i < KSPIM_SZ_PAGE; i++) {
		vBuffer[i] = (uint8_t)(i | 0x80);
	}

	cmns_init();

// Initialise the SPI1 and the DMA1

	local_initSPI1();
	local_initDMA1();

// Waiting for the DMA interruption

	INTERRUPTION_ON_HARD;

	while (true) {

// SPI generate TX DMAs
// Start

		DMA1->S1CR |= DMA_S1CR_EN;
		DMA1->S0CR |= DMA_S0CR_EN;
		SPI3->CFG1 |= (SPI_CFG1_RXDMAEN | SPI_CFG1_TXDMAEN);
		SPI3->CR1  |= SPI_CR1_CSTART;

		LED_RED_TOGGLE;
		cmns_wait(100000);

// Display the result of the transfer

		(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)DMA1->S1NDTR);
		cmns_send(KURT0, "DMA NDTR 0x"); cmns_send(KURT0, vString); cmns_send(KURT0, "\n");

		for (i = 0; i < (KSPIM_SZ_PAGE / 4); i++) {
			(void)snprintf(vString, sizeof(vString), "%08"PRIX32, (uint32_t)vBuffer[i]);
			cmns_send(KURT0, "0x"); cmns_send(KURT0, vString);
			(((i + 1) % 4) == 0) ? (cmns_send(KURT0, "\n")) : (cmns_send(KURT0, " "));
		}
		cmns_send(KURT0, "\n");
	}
}

/*
 * \brief local_initSPI1
 *
 * - Initialise the SPI1
 *
 */
static	void	local_initSPI1(void) {

// 8-bit transfers
// Initialise the SPI Master, POL = PHA = 0, Fclk divided by 32

	SPI1->CR1  = 0;
	SPI1->CFG1 = (4 * SPI_CFG1_MBR_0)
			   | ((8u - 1u)<<0);

	SPI1->CFG2 = SPI_CFG2_SSOE
			   | SPI_CFG2_MASTER;

	SPI1->CR1 |= SPI_CR1_SPE;
}

/*
 * \brief local_initDMA1
 *
 * - Initialise the DMA1 stream 0 & 1 for the SPI transfer
 *
 */
static	void	local_initDMA1(void) {
	uint8_t		value = 0;

	INTERRUPT_VECTOR(DMA1_STR0_C0_IRQn, local_DMA1_STR0_IRQHandler);
	NVIC_SetPriority(DMA1_STR0_C0_IRQn, KINT_LEVEL_PERIPHERALS);
	NVIC_EnableIRQ(DMA1_STR0_C0_IRQn);

	INTERRUPT_VECTOR(DMA1_STR1_C0_IRQn, local_DMA1_STR1_IRQHandler);
	NVIC_SetPriority(DMA1_STR1_C0_IRQn, KINT_LEVEL_PERIPHERALS);
	NVIC_EnableIRQ(DMA1_STR1_C0_IRQn);

// Stream 0 SPI1 transfer (write)
//
// Direct mode enable
// Priority medium
// Memory size 16-bits
// Peripheral size 8-bits

	DMA1->S0CR   = 0x00000000;
	DMA1->S0PAR  = (uint32_t)(&SPI1->TXDR);
	DMA1->S0M0AR = (uint32_t)&value;
	DMA1->S0NDTR = KSPIM_SZ_PAGE;
	DMA1->S0FCR  = 0;

	DMA1->S0CR = (1 * DMA_S0CR_PL_0)
			   | (1 * DMA_S0CR_DIR_0)
			   | DMA_S0CR_TCIE;

	DMA1->LIFCR = DMA_LIFCR_CTCIF0 | DMA_LIFCR_CFEIF0;

// Routing the SPI1 TX requests with the Stream 0, No synchronization
// Stream 0 on the DMA1 -> DMAMUX1_Channel0 (0 + 0)

	DMAMUX1->C0CR = 0x00000000;
	DMAMUX1->C0CR = 38 * DMAMUX1_C0CR_DMAREQ_ID_0;

// Stream 1 SPI1 transfer (read)
//
// Direct mode enable
// Priority medium
// Memory size 16-bits
// Peripheral size 8-bits
// Memory auto incremented
// Transfer complete interruption

	DMA1->S1CR   = 0x00000000;
	DMA1->S1PAR  = (uint32_t)(&SPI1->RXDR);
	DMA1->S1M0AR = (uint32_t)vBuffer;
	DMA1->S1NDTR = KSPIM_SZ_PAGE;
	DMA1->S1FCR  = 0;

	DMA1->S1CR = (1 * DMA_S1CR_PL_0)
			   | (1 * DMA_S1CR_MSIZE_0)
			   | DMA_S1CR_MINC
			   | DMA_S1CR_TCIE;

	DMA1->LIFCR = DMA_LIFCR_CTCIF1 | DMA_LIFCR_CFEIF1;

// Routing the SPI1 RX requests with the Stream 1, No synchronization
// Stream 1 on the DMA1 -> DMAMUX1_Channel1 (1 + 0)

	DMAMUX1->C1CR = 0x00000000;
	DMAMUX1->C1CR = 37 * DMAMUX1_C1CR_DMAREQ_ID_0;
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

	LED_YELLOW_TOGGLE;
}

/*
 * \brief local_DMA1_STR1_IRQHandler
 *
 * - DMA interruption
 *
 */
static	void	local_DMA1_STR1_IRQHandler(void) {

	UNUSED(number);

	DMA1->LIFCR = DMA_LIFCR_CTCIF1 | DMA_LIFCR_CFEIF1;

	cache_D_Invalidate_Add((void *)(uintptr_t)vBuffer, KSPIM_SZ_PAGE);

	LED_GREEN_TOGGLE;
}

#endif
