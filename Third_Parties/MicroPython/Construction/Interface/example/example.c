/*
; example.
; ========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		uKOS example interface
;
;			Usage:
;			import example
;			example.add_ints(1, 3)
;				should return 4
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

#include	"py/obj.h"
#include	"py/runtime.h"
#include	"py/builtin.h"

/*
 * \brief Addition of 2 numbers
 *
 * Call example in MicroPython:
 *
 * \code{.c}
 * MicroPython usage:
 *
 * import example
 * result = example.add_ints(3,2)
 * \endcode
 *
 */
static	mp_obj_t	example_add_ints(mp_obj_t a_obj, mp_obj_t b_obj) {
	int32_t		a, b;

// Extract the ints from the MicroPython input objects

	a = mp_obj_get_int(a_obj);
	b = mp_obj_get_int(b_obj);

// Calculate the addition and convert to MicroPython object

   return (mp_obj_new_int(a + b));
}

// Define a MicroPython reference to the function above.

static MP_DEFINE_CONST_FUN_OBJ_2(example_add_ints_obj, example_add_ints);

/*
 * \brief Array copy
 *
 * Call example in MicroPython:
 *
 * \code{.c}
 * MicroPython usage:
 *
 * import example
 * a = bytearray(5)
 * b = bytearray(5)
 * a[0] = 1
 * a[1] = 2
 * a[2] = 3
 * a[3] = 4
 * a[4] = 5
 *
 * example.copy(a, b)
 * \endcode
 *
 */
static	mp_obj_t	example_copy(mp_obj_t a_obj, mp_obj_t b_obj) {
	uint32_t			i, len;
	uint64_t			*a, *b;
	mp_buffer_info_t	bufinfo_a, bufinfo_b;

// Extract the ints from the MicroPython input objects

	mp_get_buffer_raise(a_obj, &bufinfo_a, MP_BUFFER_READ);
	mp_get_buffer_raise(b_obj, &bufinfo_b, MP_BUFFER_WRITE);

	a   = (uint64_t *)bufinfo_a.buf;
	b   = (uint64_t *)bufinfo_b.buf;
	len = (uint32_t  )bufinfo_b.len;

	for (i = 0u; i < len; i++) {
		*b++ = *a++;
	}
	return (mp_const_none);
}

// Define a MicroPython reference to the function above.

static MP_DEFINE_CONST_FUN_OBJ_2(example_copy_obj, example_copy);

// Define all properties of the example module.
// Table entries are key/value pairs of the attribute name (a string)
// and the MicroPython object reference.
// All identifiers and strings are written as MP_QSTR_xxx and will be
// optimised to word-sized integers by the build system (interned strings).

static	const	mp_rom_map_elem_t	example_module_globals_table[] = {
	{ MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_example)	   },
	{ MP_ROM_QSTR(MP_QSTR_add_ints), MP_ROM_PTR(&example_add_ints_obj) },
	{ MP_ROM_QSTR(MP_QSTR_copy),	 MP_ROM_PTR(&example_copy_obj)	   },
};

static	MP_DEFINE_CONST_DICT(example_module_globals, example_module_globals_table);

// Define module object.

const	mp_obj_module_t	example_user_cmodule = {
	.base	 = { &mp_type_module },
	.globals = (mp_obj_dict_t *)&example_module_globals,
};

// Register the module to make it available in MicroPython.

MP_REGISTER_MODULE(MP_QSTR_example, example_user_cmodule);
