/*
; led.
; ====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		uKOS led interface
;
;			Usage:
;			import led
;			status = led.led(led_number, led_state)
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

#include	"types.h"
#include	"led/led.h"
#include	"py/obj.h"
#include	"py/runtime.h"
#include	"py/builtin.h"

/*
 * \brief Control of the LEDs
 *
 * Call example in MicroPython:
 *
 * \code{.c}
 * MicroPython usage:
 *
 * import led
 * status = led.led(3,2)
 * \endcode
 *
 */
static	mp_obj_t	led_led(mp_obj_t ledNb_obj, mp_obj_t action_obj) {
	int32_t		status, ledNb, action;

// Extract the ints from the MicroPython input objects

	ledNb  = mp_obj_get_int(ledNb_obj);
	action = mp_obj_get_int(action_obj);

	switch (action) {
		case 0u: { status = led_off((uint8_t)ledNb);	break; }
		case 1u: { status = led_on((uint8_t)ledNb);		break; }
		case 2u: { status = led_toggle((uint8_t)ledNb);	break; }
		default: { status = led_toggle((uint8_t)ledNb);	break; }
	}
	return (mp_obj_new_int(status & 0x7FFFFFFFu));
}

// Define a Python reference to the function above.

static	MP_DEFINE_CONST_FUN_OBJ_2(led_led_obj,  led_led);

// Define all properties of the example module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimised to word-sized integers by the build system (interned strings).

static	const	mp_rom_map_elem_t	led_module_globals_table[] = {
	{ MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_led)  },
	{ MP_ROM_QSTR(MP_QSTR_led),		 MP_ROM_PTR(&led_led_obj)  },
};

static	MP_DEFINE_CONST_DICT(led_module_globals, led_module_globals_table);

// Define module object.

const	mp_obj_module_t	led_user_cmodule = {
	.base	 = { &mp_type_module },
	.globals = (mp_obj_dict_t *)&led_module_globals,
};

// Register the module to make it available in MicroPython.

MP_REGISTER_MODULE(MP_QSTR_led, led_user_cmodule);
