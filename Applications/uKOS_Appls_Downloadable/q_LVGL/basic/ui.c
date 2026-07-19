/*
; ui.
; ===

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

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
#include	"ulvgl.h"
#include	"ui.h"

extern	mutx_t		*vLVGL_API[KNB_CORES];
		lv_obj_t	*vL1[KNB_CORES];
		lv_obj_t	*vL2[KNB_CORES];
		lv_obj_t	*vL3[KNB_CORES];
		lv_obj_t	*vArc[KNB_CORES];
		lv_obj_t	*vSquare[KNB_CORES][KSQUARES_NB_MAX] = { nullptr };

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
 * - Draw all the widgets
 *
 */
void	ui_draw(void) {

	local_DrawText_1();
	local_DrawText_2();
	local_DrawText_3();
	local_DrawArc();
	local_DrawRandomSquares();
}

// Local routines
// ==============

/*
 * \brief local_DrawText_1
 *
 * - Draw the text 1 "uKOS-X"; every 200-ms change its color
 *
 */
static	void	local_DrawText_1(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
	vL1[core] = lv_label_create(lv_screen_active());
	lv_label_set_text(vL1[core], "uKOS-X");
	lv_obj_set_style_text_color(vL1[core], lv_color_hex(KRED), 0);
	lv_obj_set_style_text_font(vL1[core], &lv_font_montserrat_26, 0);
	lv_obj_align(vL1[core], LV_ALIGN_CENTER, KTEXT_POS_X, KTEXT_POS_Y_1);

// Install a timer callback (every 200-ms)

	lv_timer_create(local_colorL1_cb, 200, vL1[core]);
	kern_unlockMutex(vLVGL_API[core]);
}

static	void	local_colorL1_cb(lv_timer_t *time) {
	uint32_t	core, color;

	UNUSED(time);

	core = GET_RUNNING_CORE;

	random_read(KRANDOM_SOFT, &color, 1u);
	lv_obj_set_style_text_color(vL1[core], lv_color_hex(color & KMASK_24_BITS), 0);
}

/*
 * \brief local_DrawText_2
 *
 * - Draw the text 2 "LVGL under uKOS-X control"
 *
 */
static	void	local_DrawText_2(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
	vL2[core] = lv_label_create(lv_screen_active());
	lv_label_set_text(vL2[core], "LVGL under uKOS-X control");
	lv_obj_set_style_text_color(vL2[core], lv_color_hex(KGREEN), 0);
	lv_obj_align(vL2[core], LV_ALIGN_CENTER, KTEXT_POS_X, KTEXT_POS_Y_2);
	kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief local_DrawText_3
 *
 * - Draw the text 3 "(c) 2025-2026, Edo. Franzi"
 *
 */
static	void	local_DrawText_3(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
	vL3[core] = lv_label_create(lv_screen_active());
	lv_label_set_text(vL3[core], "(c) 2025-2026, Edo. Franzi");
	lv_obj_set_style_text_color(vL3[core], lv_color_hex(KBLUE), 0);
	lv_obj_align(vL3[core], LV_ALIGN_CENTER, KTEXT_POS_X, KTEXT_POS_Y_3);
	kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief local_DrawArc
 *
 * - Draw the arc circle (continuously)
 *
 */
static	void	local_DrawArc(void) {
	uint32_t	core;
	lv_anim_t	animation;

	core = GET_RUNNING_CORE;

	kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
	vArc[core] = lv_arc_create(lv_screen_active());
	lv_obj_set_size(vArc[core], KARC_DIAMETER, KARC_DIAMETER);
	lv_arc_set_rotation(vArc[core], 270);
	lv_arc_set_bg_angles(vArc[core], 0, 360);
	lv_obj_remove_style(vArc[core], nullptr, LV_PART_KNOB);
	lv_obj_remove_flag(vArc[core], LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_pos(vArc[core], KARC_POS_X, KARC_POS_Y);

	lv_anim_init(&animation);
	lv_anim_set_var(&animation, vArc[core]);
	lv_anim_set_exec_cb(&animation, local_setAngle_cb);
	lv_anim_set_duration(&animation, 1000);
	lv_anim_set_repeat_count(&animation, LV_ANIM_REPEAT_INFINITE);
	lv_anim_set_repeat_delay(&animation, 500);
	lv_anim_set_values(&animation, 0, 100);
	lv_anim_start(&animation);
	kern_unlockMutex(vLVGL_API[core]);
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

	lv_timer_create(local_square_cb, 100, nullptr);
}

static	void	local_square_cb(lv_timer_t *time) {
			uint32_t	core, position, color;
			int32_t		x, y, max_x, max_y;
			lv_obj_t	*localSquare;
	static	uint32_t	index = 0;

	UNUSED(time);

	core = GET_RUNNING_CORE;

	random_read(KRANDOM_SOFT, &position, 1u);
	color = position;

// Max range

	max_x = (int32_t)(KLCD_WIDTH - KARC_DIAMETER - KSQUARE_SIZE - (2u * KARC_MARGIN));
	max_y = (int32_t)((KLCD_HEIGHT / 2u) - KSQUARE_SIZE);

	x = (int32_t)(position		  % (uint32_t)(max_x + 1));
	y = (int32_t)((position>>16u) % (uint32_t)(max_y + 1));

// Delete the oldest handle
// Create a new one

	if (vSquare[core][index] != nullptr) { lv_obj_delete(vSquare[core][index]); }

	localSquare			 = lv_obj_create(lv_screen_active());
    vSquare[core][index] = localSquare;

	lv_obj_set_size(localSquare, KSQUARE_SIZE, KSQUARE_SIZE);
	lv_obj_set_pos(localSquare, x, y);

	lv_obj_set_style_bg_color(localSquare, lv_color_hex(color & KMASK_24_BITS), 0);
	lv_obj_set_style_bg_opa(localSquare, LV_OPA_COVER, 0);

    index = (index + 1u) % KSQUARES_NB_MAX;
}
