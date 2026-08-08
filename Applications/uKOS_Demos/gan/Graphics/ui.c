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
;			Simple UI for the debris demo.
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

extern	mutx_t			*vLVGL_API[KNB_CORES];
extern	lv_image_dsc_t	background;
		lv_obj_t		*vImage[KNB_CORES];
		lv_obj_t		*vArc[KNB_CORES];
		lv_obj_t		*vL_random[KNB_CORES];
		lv_obj_t		*vL_Ex_TensorFlow[KNB_CORES];
		lv_obj_t		*vL_Ex_NPU[KNB_CORES];
		lv_image_dsc_t	vFaceImage[KNB_CORES];
		uint32_t		vFaceBuf[KNB_CORES][2][KFACE_DST_H * KFACE_DST_W];
		uint32_t        vFaceIndex[KNB_CORES];

// Prototypes

static	void	local_PrepareDrawingBackground(void);
static	void	local_PrepareDrawingArc(void);
static	void	local_PrepareDrawingImage(void);
static	void	local_setAngle_cb(void *object, int32_t angle);
static	void	local_PrepareDrawingText_Random(void);
static	void	local_PrepareDrawingText_TensorFlow(void);
static	void	local_PrepareDrawingText_NPU(void);

/*
 * \brief ui_draw
 *
 * - Draw all the widgets
 *
 */
void	ui_draw(void) {

	local_PrepareDrawingBackground();
	local_PrepareDrawingArc();
	local_PrepareDrawingImage();
	local_PrepareDrawingText_Random();
	local_PrepareDrawingText_TensorFlow();
	local_PrepareDrawingText_NPU();
}

/*
 * \brief ui_drawSmallImage
 *
 * - Process the smallImage (zoom)
 * - Apply an anti-aliasing
 * - Add some color noise
 *
 */
void	ui_drawFace(const uint8_t *face) {
	uint32_t	core, next;
	uint32_t	x, y;
	uint32_t	fx, fy;
	uint32_t	src_x, src_y;
	uint32_t	src_x1, src_y1;
	uint32_t	dx, dy;
	uint32_t	p00, p10, p01, p11;
	uint32_t	p0, p1;
	uint8_t		g;

	core = GET_RUNNING_CORE;

	next = vFaceIndex[core] ^ 1u;

// Scale the source image using bilinear interpolation
//
// Coordinates use an 8-bit fractional part

	for (y = 0u; y < KFACE_DST_H; y++) {
		fy = (y * (KFACE_SRC_H - 1u) * 256u) / (KFACE_DST_H - 1u);

		src_y = fy>>8u;
		src_y1 = (src_y + 1u < KFACE_SRC_H) ? (src_y + 1u) : src_y;
		dy = fy & 0xFFu;

		for (x = 0u; x < KFACE_DST_W; x++) {
			fx = (x * (KFACE_SRC_W - 1u) * 256u) / (KFACE_DST_W - 1u);

			src_x = fx>>8u;
			src_x1 = (src_x + 1u < KFACE_SRC_W) ? (src_x + 1u) : src_x;
			dx = fx & 0xFFu;

// Read the four surrounding source pixels

			p00 = face[src_y  * KFACE_SRC_W + src_x];
			p10 = face[src_y  * KFACE_SRC_W + src_x1];
			p01 = face[src_y1 * KFACE_SRC_W + src_x];
			p11 = face[src_y1 * KFACE_SRC_W + src_x1];

// Horizontal interpolation

			p0 = p00 * (256u - dx) + p10 * dx;
			p1 = p01 * (256u - dx) + p11 * dx;

// Vertical interpolation with rounding

			g = (uint8_t)((p0 * (256u - dy) + p1 * dy + 32768u)>>16u);

// XRGB8888: 0x00RRGGBB

			vFaceBuf[core][next][y * KFACE_DST_W + x] = ((uint32_t)g<<16u) | ((uint32_t)g<<8u) | ((uint32_t)g);
		}
	}

	kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
	vFaceIndex[core] = next;
	vFaceImage[core].data = (const uint8_t *)&vFaceBuf[core][next][0];
	lv_image_set_src(vImage[core], &vFaceImage[core]);
	lv_obj_invalidate(vImage[core]);
	kern_unlockMutex(vLVGL_API[core]);
}
/*
 * \brief ui_drawRandom
 *
 * - Draw the random
 *
 */
void	ui_drawRandom(const char_t *s) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
	lv_label_set_text(vL_random[core], s);
	kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief ui_drawTensorFlowExecutionTime
 *
 * - Draw the TensorFlow execution time
 *
 */
void	ui_drawTensorFlowExecutionTime(const char_t *s) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
	lv_label_set_text(vL_Ex_TensorFlow[core], s);
	kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief ui_drawNPUExecutionTime
 *
 * - Draw the NPU execution time
 *
 */
void	ui_drawNPUExecutionTime(const char_t *s) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
	lv_label_set_text(vL_Ex_NPU[core], s);
	kern_unlockMutex(vLVGL_API[core]);
}

// Local routines
// ==============

/*
 * \brief local_PrepareDrawingBackground
 *
 * - Prepare for drawing the background picture
 *
 */
static	void	local_PrepareDrawingBackground(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
	vImage[core] = lv_image_create(lv_screen_active());
	lv_image_set_src(vImage[core], &background);
	lv_obj_align(vImage[core], LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_remove_flag(vImage[core], LV_OBJ_FLAG_HIDDEN);
	kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief local_PrepareDrawingArc
 *
 * - Prepare for drawing the arc circle (continuously)
 *
 */
static	void	local_PrepareDrawingArc(void) {
	uint32_t	core;
	lv_anim_t	animation;

	core = GET_RUNNING_CORE;

	kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
	vArc[core] = lv_arc_create(lv_screen_active());
	lv_obj_set_size(vArc[core], KARC_DIAMETER, KARC_DIAMETER);
	lv_arc_set_rotation(vArc[core], 270u);
	lv_arc_set_bg_angles(vArc[core], 0u, 360u);
	lv_obj_remove_style(vArc[core], nullptr, LV_PART_KNOB);
	lv_obj_remove_flag(vArc[core], LV_OBJ_FLAG_CLICKABLE);
	lv_obj_set_pos(vArc[core], KARC_POS_X, KARC_POS_Y);

	lv_anim_init(&animation);
	lv_anim_set_var(&animation, vArc[core]);
	lv_anim_set_exec_cb(&animation, local_setAngle_cb);
	lv_anim_set_duration(&animation, 1000u);
	lv_anim_set_repeat_count(&animation, LV_ANIM_REPEAT_INFINITE);
	lv_anim_set_repeat_delay(&animation, 500u);
	lv_anim_set_values(&animation, 0u, 100u);
	lv_anim_start(&animation);
	kern_unlockMutex(vLVGL_API[core]);
}

static	void	local_setAngle_cb(void *object, int32_t angle) {

	lv_arc_set_value((lv_obj_t *)object, angle);
}

/*
 * \brief local_PrepareDrawingImage
 *
 * - Prepare for drawing the image
 *
 */
static void local_PrepareDrawingImage(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
	memset(&vFaceImage[core], 0, sizeof(vFaceImage[core]));
	memset(&vFaceBuf[core][0][0], 0, sizeof(vFaceBuf[core]));

	vFaceIndex[core] = 0u;

	vFaceImage[core].header.magic	= LV_IMAGE_HEADER_MAGIC;
	vFaceImage[core].header.cf		= LV_COLOR_FORMAT_XRGB8888;
	vFaceImage[core].header.w		= KFACE_DST_W;
	vFaceImage[core].header.h		= KFACE_DST_H;
	vFaceImage[core].header.stride	= KFACE_DST_W * 4u;
	vFaceImage[core].data_size		= KFACE_DST_W * KFACE_DST_H * 4u;
	vFaceImage[core].data			= (const uint8_t *)&vFaceBuf[core][0][0];

	vImage[core] = lv_image_create(lv_screen_active());
	lv_image_set_src(vImage[core], &vFaceImage[core]);
	lv_obj_set_pos(vImage[core], KFACE_POS_X, KFACE_POS_Y);
	kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief local_PrepareDrawingText_Random
 *
 * - Prepare for drawing the text, random
 *
 */
static	void	local_PrepareDrawingText_Random(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
	vL_random[core] = lv_label_create(lv_screen_active());
	lv_label_set_text(vL_random[core], " ");
	lv_obj_set_style_text_color(vL_random[core], lv_color_hex(KBLACK), 0);
	lv_obj_set_style_text_font(vL_random[core], &lv_font_montserrat_16, 0);
	lv_obj_align(vL_random[core], LV_ALIGN_TOP_LEFT, KTEXT_POS_X_1, KTEXT_POS_Y_1);
	kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief local_PrepareDrawingText_TensorFlow
 *
 * - Prepare for drawing the text execution time TensorFlow
 *
 */
static	void	local_PrepareDrawingText_TensorFlow(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
	vL_Ex_TensorFlow[core] = lv_label_create(lv_screen_active());
	lv_label_set_text(vL_Ex_TensorFlow[core], " ");
	lv_obj_set_style_text_color(vL_Ex_TensorFlow[core], lv_color_hex(KWHITE), 0);
	lv_obj_set_style_text_font(vL_Ex_TensorFlow[core], &lv_font_montserrat_16, 0);
	lv_obj_align(vL_Ex_TensorFlow[core], LV_ALIGN_TOP_LEFT, KTEXT_POS_X_2, KTEXT_POS_Y_2);
	kern_unlockMutex(vLVGL_API[core]);
}

/*
 * \brief local_PrepareDrawingText_NPU
 *
 * - Prepare for drawing the text execution time NPU
 *
 */
static	void	local_PrepareDrawingText_NPU(void) {
	uint32_t	core;

	core = GET_RUNNING_CORE;

	kern_lockMutex(vLVGL_API[core], KWAIT_INFINITY);
	vL_Ex_NPU[core] = lv_label_create(lv_screen_active());
	lv_label_set_text(vL_Ex_NPU[core], " ");
	lv_obj_set_style_text_color(vL_Ex_NPU[core], lv_color_hex(KWHITE), 0);
	lv_obj_set_style_text_font(vL_Ex_NPU[core], &lv_font_montserrat_16, 0);
	lv_obj_align(vL_Ex_NPU[core], LV_ALIGN_TOP_LEFT, KTEXT_POS_X_3, KTEXT_POS_Y_3);
	kern_unlockMutex(vLVGL_API[core]);
}
