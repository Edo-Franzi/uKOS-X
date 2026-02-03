/*
; ui.
; ===

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Demo of a C application.
;			Simple UI for the basic demo.
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
#include	"ui.h"
#include	"../ulvgl.h"

static	lv_obj_t	*vL1, *vL2, *vL3, *vArc, *vSquare[KSQUARES_NB_MAX] = { NULL };

// Prototypes

static	void	local_DrawText_1(void);
static	void	local_DrawText_2(void);
static	void	local_DrawText_3(void);
static	void	local_DrawArc(void);
static	void	local_DrawRandomSquares(void);

static	void	local_colorL1_cb(lv_timer_t *time);
static	void	local_setAngle_cb(void *object, int32_t angle);
static	void	local_square_cb(lv_timer_t *time);

/*
 * \brief ui_draw
 *
 * - Draw all the objects
 *
 * - Draw the text 1 "uKOS-X"; every 200-ms change its color
 * - Draw the text 2 "LVGL under uKOS-X control"
 * - Draw the text 3 "(c) 2025-2026, Edo. Franzi"
 * - Draw the arc circle (continuously)
 * - Draw up to 20 squares (continuously)
 *
 */
void	ui_draw(void) {

	local_DrawText_1();
	local_DrawText_2();
	local_DrawText_3();
	local_DrawArc();
	local_DrawRandomSquares();
}

/*
 * \brief local_DrawText_1
 *
 * - Draw the text 1 "uKOS-X"; every 200-ms change its color
 *
 */
static	void	local_DrawText_1(void) {

// Red line ... and then randomly changed every 200-ms

	vL1 = lv_label_create(lv_screen_active());
	lv_label_set_text(vL1, "uKOS-X");
	lv_obj_set_style_text_color(vL1, lv_color_hex(KRED), 0);
	lv_obj_set_style_text_font(vL1, &lv_font_montserrat_26, 0);
	lv_obj_align(vL1, LV_ALIGN_CENTER, KTEXT_POS_X, KTEXT_POS_Y_1);

// Install a timer callback (every 200-ms)

	lv_timer_create(local_colorL1_cb, 200, vL1);
}

static	void	local_colorL1_cb(lv_timer_t *time) {
	uint32_t	color;

	UNUSED(time);

	random_read(KRANDOM_SOFT, &color, 1u);

	lv_obj_set_style_text_color(vL1, lv_color_hex(color & KMASK_24_BITS), 0);
}

/*
 * \brief local_DrawText_2
 *
 * - Draw the text 2 "LVGL under uKOS-X control"
 *
 */
static	void	local_DrawText_2(void) {

// Green line

	vL2 = lv_label_create(lv_screen_active());
	lv_label_set_text(vL2, "LVGL under uKOS-X control");
	lv_obj_set_style_text_color(vL2, lv_color_hex(KGREEN), 0);
	lv_obj_align(vL2, LV_ALIGN_CENTER, KTEXT_POS_X, KTEXT_POS_Y_2);
}

/*
 * \brief local_DrawText_3
 *
 * - Draw the text 3 "(c) 2025-2026, Edo. Franzi"
 *
 */
static	void	local_DrawText_3(void) {

// Blue line

	vL3 = lv_label_create(lv_screen_active());
	lv_label_set_text(vL3, "(c) 2025-2026, Edo. Franzi");
	lv_obj_set_style_text_color(vL3, lv_color_hex(KBLUE), 0);
	lv_obj_align(vL3, LV_ALIGN_CENTER, KTEXT_POS_X, KTEXT_POS_Y_3);
}

/*
 * \brief local_DrawArc
 *
 * - Draw the arc circle (continuously)
 *
 */
static	void	local_DrawArc(void) {
	lv_anim_t	animation;

	vArc = lv_arc_create(lv_screen_active());
	lv_obj_set_size(vArc, KARC_DIAMETER, KARC_DIAMETER);
	lv_arc_set_rotation(vArc, 270);
	lv_arc_set_bg_angles(vArc, 0, 360);
	lv_obj_remove_style(vArc, NULL, LV_PART_KNOB);
	lv_obj_remove_flag(vArc, LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_pos(vArc, KARC_POS_X, KARC_POS_Y);

	lv_anim_init(&animation);
	lv_anim_set_var(&animation, vArc);
	lv_anim_set_exec_cb(&animation, local_setAngle_cb);
	lv_anim_set_duration(&animation, 1000);
	lv_anim_set_repeat_count(&animation, LV_ANIM_REPEAT_INFINITE);
	lv_anim_set_repeat_delay(&animation, 500);
	lv_anim_set_values(&animation, 0, 100);
	lv_anim_start(&animation);
}

static	void	local_setAngle_cb(void *object, int32_t angle) {

	lv_arc_set_value((lv_obj_t *)object, angle);
}

/*
 * \brief local_DrawRandomSquares
 *
 * - Draw up to 20 squares (continuously)
 *
 */
static	void	local_DrawRandomSquares(void) {

// Install a timer callback (every 100-ms)

	lv_timer_create(local_square_cb, 100, NULL);
}

static	void	local_square_cb(lv_timer_t *time) {
			uint32_t	position, color;
			int32_t		x, y, max_x, max_y;
			lv_obj_t	*localSquare;
	static	uint32_t	index = 0;

	UNUSED(time);

	random_read(KRANDOM_SOFT, &position, 1u);
	color = position;

// Max range

	max_x = (int32_t)(KLCD_WIDTH - KARC_DIAMETER - KSQUARE_SIZE - (2u * KARC_MARGIN));
	max_y = (int32_t)((KLCD_HEIGHT / 2u) - KSQUARE_SIZE);

	x = (int32_t)(position		  % (uint32_t)(max_x + 1));
	y = (int32_t)((position>>16u) % (uint32_t)(max_y + 1));

// Delete the oldest handle
// Create a new one

	if (vSquare[index] != NULL) { lv_obj_delete(vSquare[index]); }

	localSquare	   = lv_obj_create(lv_screen_active());
    vSquare[index] = localSquare;

	lv_obj_set_size(localSquare, KSQUARE_SIZE, KSQUARE_SIZE);
	lv_obj_set_pos(localSquare, x, y);

	lv_obj_set_style_bg_color(localSquare, lv_color_hex(color & KMASK_24_BITS), 0);
	lv_obj_set_style_bg_opa(localSquare, LV_OPA_COVER, 0);

    index = (index + 1u) % KSQUARES_NB_MAX;
}
