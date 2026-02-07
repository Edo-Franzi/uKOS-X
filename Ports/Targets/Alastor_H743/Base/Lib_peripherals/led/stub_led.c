/*
; stub_led.
; =========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the "led" manager module.
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

static	bool	vMute;

/*
 * \brief stub_led_init
 *
 * - Initialise some specific hardware parts:
 *   - The LEDs state
 *
 */
int32_t	stub_led_init(void) {

	INTERRUPTION_OFF;
	vMute = false;

	GPIOB->ODR &= (uint32_t)~(1u<<BLED_0);
	GPIOB->ODR &= (uint32_t)~(1u<<BLED_1);
	GPIOB->ODR &= (uint32_t)~(1u<<BLED_2);
	GPIOC->ODR &= (uint32_t)~(1u<<BLED_3);
	GPIOC->ODR &= (uint32_t)~(1u<<BLED_4);
	GPIOC->ODR &= (uint32_t)~(1u<<BLED_5);
	GPIOC->ODR &= (uint32_t)~(1u<<BLED_6);
	GPIOC->ODR &= (uint32_t)~(1u<<BLED_7);

	GPIOI->ODR &= (uint32_t)~(1u<<BLOGIC_0);
	GPIOI->ODR &= (uint32_t)~(1u<<BLOGIC_1);
	RETURN_INT_RESTORE(KERR_LED_NOERR);
}

/*
 * \brief stub_led_on
 *
 * - Turn on a LED
 *
 */
int32_t	stub_led_on(uint8_t ledNb) {

	INTERRUPTION_OFF;
	if (vMute == true) { RETURN_INT_RESTORE(KERR_LED_NOERR); }
	switch (ledNb) {
		case 0u: { GPIOB->ODR |= (1u<<BLED_0);		break; }
		case 1u: { GPIOB->ODR |= (1u<<BLED_1);		break; }
		case 2u: { GPIOB->ODR |= (1u<<BLED_2);		break; }
		case 3u: { GPIOC->ODR |= (1u<<BLED_3);		break; }
		case 4u: { GPIOC->ODR |= (1u<<BLED_4);		break; }
		case 5u: { GPIOC->ODR |= (1u<<BLED_5);		break; }
		case 6u: { GPIOC->ODR |= (1u<<BLED_6);		break; }
		case 7u: { GPIOC->ODR |= (1u<<BLED_7);		break; }

		case 8u: { GPIOI->ODR |= (1u<<BLOGIC_0);	break; }
		case 9u: { GPIOI->ODR |= (1u<<BLOGIC_1);	break; }
		default: { RETURN_INT_RESTORE(KERR_LED_NODEV);	   }
	}

	RETURN_INT_RESTORE(KERR_LED_NOERR);
}

/*
 * \brief stub_led_off
 *
 * - Turn off a LED
 *
 */
int32_t	stub_led_off(uint8_t ledNb) {

	INTERRUPTION_OFF;
	if (vMute == true) { RETURN_INT_RESTORE(KERR_LED_NOERR); }
	switch (ledNb) {
		case 0u: { GPIOB->ODR &= (uint32_t)~(1u<<BLED_0);	break; }
		case 1u: { GPIOB->ODR &= (uint32_t)~(1u<<BLED_1);	break; }
		case 2u: { GPIOB->ODR &= (uint32_t)~(1u<<BLED_2);	break; }
		case 3u: { GPIOC->ODR &= (uint32_t)~(1u<<BLED_3);	break; }
		case 4u: { GPIOC->ODR &= (uint32_t)~(1u<<BLED_4);	break; }
		case 5u: { GPIOC->ODR &= (uint32_t)~(1u<<BLED_5);	break; }
		case 6u: { GPIOC->ODR &= (uint32_t)~(1u<<BLED_6);	break; }
		case 7u: { GPIOC->ODR &= (uint32_t)~(1u<<BLED_7);	break; }

		case 8u: { GPIOI->ODR &= (uint32_t)~(1u<<BLOGIC_0);	break; }
		case 9u: { GPIOI->ODR &= (uint32_t)~(1u<<BLOGIC_1);	break; }
		default: { RETURN_INT_RESTORE(KERR_LED_NODEV);			   }
	}

	RETURN_INT_RESTORE(KERR_LED_NOERR);
}

/*
 * \brief stub_led_toggle
 *
 * - Change the state of a LED
 *
 */
int32_t	stub_led_toggle(uint8_t ledNb) {

	INTERRUPTION_OFF;
	if (vMute == true) { RETURN_INT_RESTORE(KERR_LED_NOERR); }
	switch (ledNb) {
		case 0u: { GPIOB->ODR ^= (1u<<BLED_0);	 break; }
		case 1u: { GPIOB->ODR ^= (1u<<BLED_1);	 break; }
		case 2u: { GPIOB->ODR ^= (1u<<BLED_2);	 break; }
		case 3u: { GPIOC->ODR ^= (1u<<BLED_3);	 break; }
		case 4u: { GPIOC->ODR ^= (1u<<BLED_4);	 break; }
		case 5u: { GPIOC->ODR ^= (1u<<BLED_5);	 break; }
		case 6u: { GPIOC->ODR ^= (1u<<BLED_6);	 break; }
		case 7u: { GPIOC->ODR ^= (1u<<BLED_7);	 break; }

		case 8u: { GPIOI->ODR ^= (1u<<BLOGIC_0); break; }
		case 9u: { GPIOI->ODR ^= (1u<<BLOGIC_1); break; }
		default: { RETURN_INT_RESTORE(KERR_LED_NODEV);	}
	}

	RETURN_INT_RESTORE(KERR_LED_NOERR);
}

/*
 * \brief stub_led_mute
 *
 * - Control (general) of the LEDs
 *
 */
int32_t	stub_led_mute(bool mute) {

	if (mute == false) { vMute = false; return (KERR_LED_NOERR); }

	INTERRUPTION_OFF;
	vMute = true;

	GPIOB->ODR &= (uint32_t)~(1u<<BLED_0);
	GPIOB->ODR &= (uint32_t)~(1u<<BLED_1);
	GPIOB->ODR &= (uint32_t)~(1u<<BLED_2);
	GPIOC->ODR &= (uint32_t)~(1u<<BLED_3);
	GPIOC->ODR &= (uint32_t)~(1u<<BLED_4);
	GPIOC->ODR &= (uint32_t)~(1u<<BLED_5);
	GPIOC->ODR &= (uint32_t)~(1u<<BLED_6);
	GPIOC->ODR &= (uint32_t)~(1u<<BLED_7);

	GPIOI->ODR &= (uint32_t)~(1u<<BLOGIC_0);
	GPIOI->ODR &= (uint32_t)~(1u<<BLOGIC_1);
	RETURN_INT_RESTORE(KERR_LED_NOERR);
}
