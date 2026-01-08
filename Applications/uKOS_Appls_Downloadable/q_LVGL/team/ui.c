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
;			Simple UI for the team demo.
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
#include	"lvgl.h"
#include	"team.h"

typedef	struct	labeledBar	labeledBar_t;

struct labeledBar {
	lv_obj_t	*oLabel;
	lv_obj_t	*oBar;
};

static	labeledBar_t	vBar_1, vBar_2, vBar_3;
static	lv_obj_t		*vImage, *vBar;

// Prototypes

static	void	local_DrawImage(void);
static	void	local_DrawBars(void);
static	void	local_InitBars(labeledBar_t *bar, lv_obj_t *parent, lv_coord_t x, lv_coord_t y, const char *text, int32_t initialValue);
static	void	local_BarEvent_cb(lv_event_t *event);
static	void	local_setBars(labeledBar_t *bar, uint32_t position);

/*
 * \brief ui_draw
 *
 * - Draw all the objects
 *
 * - Draw the uKOS-X team picture
 * - Draw the process time usage bars
 *
 */
void	ui_draw(void) {

	local_DrawImage();
	local_DrawBars();
}

/*
 * \brief local_DrawImage
 *
 * - Draw the uKOS-X team picture
 *
 */
static	void	local_DrawImage(void) {

	vImage = lv_img_create(lv_screen_active());
	lv_img_set_src(vImage, &Team);
	lv_obj_align(vImage, LV_ALIGN_TOP_MID, 0, 15);
    lv_obj_clear_flag(vImage, LV_OBJ_FLAG_HIDDEN);
}

/*
 * \brief local_DrawBars
 *
 * - Draw the process time usage bars
 *
 */
static	void	local_DrawBars(void) {

	vBar = lv_screen_active();
	local_InitBars(&vBar_1, vBar, KBAR_POS_Y, KBAR_POS_X_1, "P idle", 0);
	local_InitBars(&vBar_2, vBar, KBAR_POS_Y, KBAR_POS_X_2, "P tick", 0);
	local_InitBars(&vBar_3, vBar, KBAR_POS_Y, KBAR_POS_X_3, "P lvgl", 0);
}

/*
 * \brief local_InitBars
 *
 * - Draw a process time usage bar
 *
 */
static	void	local_InitBars(labeledBar_t *bar, lv_obj_t *parent, lv_coord_t x, lv_coord_t y, const char *text, int32_t initialValue) {

// Create a bar

	bar->oBar = lv_bar_create(parent);
	lv_bar_set_range(bar->oBar, KBAR_MIN_VALUE, KBAR_MAX_VALUE);
	lv_obj_set_size(bar->oBar, KBAR_WIDTH, KBAR_HEIGHT);
	lv_obj_set_pos(bar->oBar, (x + (lv_coord_t)KBAR_LABEL_WIDTH + (lv_coord_t)KBAR_GAP_Y), y);

// Set the values & prepare the callback

	lv_bar_set_value(bar->oBar, initialValue, LV_ANIM_OFF);
	lv_obj_add_event_cb(bar->oBar, local_BarEvent_cb, LV_EVENT_DRAW_MAIN_END, NULL);

	bar->oLabel = lv_label_create(parent);
	lv_label_set_text(bar->oLabel, text);
	lv_obj_set_width(bar->oLabel, KBAR_LABEL_WIDTH);
	lv_label_set_long_mode(bar->oLabel, LV_LABEL_LONG_DOT);

	lv_obj_align_to(bar->oLabel, bar->oBar, LV_ALIGN_OUT_LEFT_MID, -(int32_t)KBAR_GAP_Y, 0);
}

static	void	local_BarEvent_cb(lv_event_t *event) {
	lv_obj_t				*bar;
	lv_draw_label_dsc_t		dscLabel;
	lv_point_t				textSize;
	lv_area_t				textArea, indicationArea;
	lv_layer_t				*layer;
	char_t					buffer[8];

	bar = lv_event_get_target_obj(event);

	lv_draw_label_dsc_init(&dscLabel);
	dscLabel.font = LV_FONT_DEFAULT;

    lv_snprintf(buffer, sizeof(buffer), "%d", (int)lv_bar_get_value(bar));
	lv_text_get_size(&textSize, buffer, dscLabel.font, dscLabel.letter_space, dscLabel.line_space, LV_COORD_MAX, dscLabel.flag);

	textArea.x1 = 0;				textArea.y1 = 0;
	textArea.x2 = (textSize.x - 1); textArea.y2 = (textSize.y - 1);

	lv_obj_get_coords(bar, &indicationArea);
	lv_area_set_width(&indicationArea, (lv_area_get_width(&indicationArea) * lv_bar_get_value(bar)) / (int32_t)KBAR_MAX_VALUE);

	if (lv_area_get_width(&indicationArea) > (textSize.x + 20)) {
		lv_area_align(&indicationArea, &textArea, LV_ALIGN_RIGHT_MID, -10, 0);
		dscLabel.color = lv_color_white();
	} else {
		lv_area_align(&indicationArea, &textArea, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
		dscLabel.color = lv_color_black();
	}

	dscLabel.text		= buffer;
	dscLabel.text_local = true;

	layer = lv_event_get_layer(event);
	lv_draw_label(layer, &dscLabel, &textArea);
}

/*
 * \brief ui_setBar_x
 *
 * - Set a value for a bar
 *
 */
void	ui_setBar_1(uint32_t position) { local_setBars(&vBar_1, position); }
void	ui_setBar_2(uint32_t position) { local_setBars(&vBar_2, position); }
void	ui_setBar_3(uint32_t position) { local_setBars(&vBar_3, position); }

static	void	local_setBars(labeledBar_t *bar, uint32_t position) {

	if ((bar == NULL) || (bar->oBar == NULL)) { return; }

	position = (position < (KBAR_MIN_VALUE + 1u)) ? (KBAR_MIN_VALUE) : (position);
	position = (position >  KBAR_MAX_VALUE)		  ? (KBAR_MAX_VALUE) : (position);

	lv_bar_set_value(bar->oBar, (int32_t)position, LV_ANIM_OFF);
	lv_obj_invalidate(bar->oBar);
}
