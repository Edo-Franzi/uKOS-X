/*
; lv_conf.
; ========

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2026-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Basic LVGL configuration
;			Set 16 & 26 pixel fonts.
;			Internal memory allocator
;
;			Configuration file for LVGL v9.5.x
;			(based on lv_conf_template.h v9.5.0)
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

#if	1

#ifndef LV_CONF_H
#define	LV_CONF_H

// COLOR SETTINGS
// ==============

// Color depth: 1 (I1), 8 (L8), 16 (RGB565), 24 (RGB888), 32 (XRGB8888)
//
#define	LV_COLOR_DEPTH									16

// STDLIB WRAPPER SETTINGS
// =======================

// Possible values
// - LV_STDLIB_BUILTIN: LVGL's built in implementation
// - LV_STDLIB_CLIB: Standard C functions, like malloc, strlen, etc
// - LV_STDLIB_MICROPYTHON: MicroPython implementation
// - LV_STDLIB_RTTHREAD: RT-Thread implementation
// - LV_STDLIB_CUSTOM: Implement the functions externally
//
#define	LV_USE_STDLIB_MALLOC							LV_STDLIB_BUILTIN

// Possible values
// - LV_STDLIB_BUILTIN
// - LV_STDLIB_CLIB
// - LV_STDLIB_MICROPYTHON
// - LV_STDLIB_RTTHREAD
// - LV_STDLIB_CUSTOM
//
#define	LV_USE_STDLIB_STRING							LV_STDLIB_BUILTIN

// Possible values
// - LV_STDLIB_BUILTIN
// - LV_STDLIB_CLIB
// - LV_STDLIB_MICROPYTHON
// - LV_STDLIB_RTTHREAD
// - LV_STDLIB_CUSTOM
//
#define	LV_USE_STDLIB_SPRINTF							LV_STDLIB_CLIB

// Std includes
//
#define	LV_STDINT_INCLUDE								<stdint.h>
#define	LV_STDDEF_INCLUDE								<stddef.h>
#define	LV_STDBOOL_INCLUDE								<stdbool.h>
#define	LV_INTTYPES_INCLUDE								<inttypes.h>
#define	LV_LIMITS_INCLUDE								<limits.h>
#define	LV_STDARG_INCLUDE								<stdarg.h>

// HAL SETTINGS
// ============

// Default display refresh, input device read and animation step period i ms
//
#define	LV_DEF_REFR_PERIOD								33

// Default Dots Per Inch.[px/inch]
//
#define	LV_DPI_DEF										130

// Resolution
//
#define	LV_HOR_RES_MAX									320
#define	LV_VER_RES_MAX									240

// OPERATING SYSTEM
// ================

// Select operating system to use
//
#define	LV_USE_OS										LV_OS_NONE

// RENDERING CONFIGURATION
// =======================

#define	LV_DRAW_BUF_STRIDE_ALIGN						1
#define	LV_DRAW_BUF_ALIGN								4

#define	LV_DRAW_TRANSFORM_USE_MATRIX					0
#define	LV_DRAW_LAYER_SIMPLE_BUF_SIZE					(24 * 1024)
#define	LV_DRAW_LAYER_MAX_MEMORY						0
#define	LV_DRAW_THREAD_STACK_SIZE						(8 * 1024)
#define	LV_DRAW_THREAD_PRIO								LV_THREAD_PRIO_HIGH

#define	LV_USE_DRAW_SW									1
#if LV_USE_DRAW_SW == 1
	#define	LV_DRAW_SW_SUPPORT_RGB565					1
	#define	LV_DRAW_SW_SUPPORT_RGB565_SWAPPED			1
	#define	LV_DRAW_SW_SUPPORT_RGB565A8					1
	#define	LV_DRAW_SW_SUPPORT_RGB888					1
	#define	LV_DRAW_SW_SUPPORT_XRGB8888					1
	#define	LV_DRAW_SW_SUPPORT_ARGB8888					1
	#define	LV_DRAW_SW_SUPPORT_ARGB8888_PREMULTIPLIED	1
	#define	LV_DRAW_SW_SUPPORT_L8						1
	#define	LV_DRAW_SW_SUPPORT_AL88						1
	#define	LV_DRAW_SW_SUPPORT_A8						1
	#define	LV_DRAW_SW_SUPPORT_I1						1
	#define	LV_DRAW_SW_I1_LUM_THRESHOLD					127
	#define	LV_DRAW_SW_DRAW_UNIT_CNT					1
	#define	LV_USE_DRAW_ARM2D_SYNC						0
	#define	LV_USE_NATIVE_HELIUM_ASM					0
	#define	LV_DRAW_SW_COMPLEX							1
	#if LV_DRAW_SW_COMPLEX == 1
		#define	LV_DRAW_SW_SHADOW_CACHE_SIZE			0
		#define	LV_DRAW_SW_CIRCLE_CACHE_SIZE			4
	#endif
	#define	LV_USE_DRAW_SW_ASM							LV_DRAW_SW_ASM_NONE
	#define	LV_USE_DRAW_SW_COMPLEX_GRADIENTS			0
#endif

// FEATURE CONFIGURATION
// =====================

// Logging
//
#define	LV_USE_LOG										0

// Asserts
//
#define	LV_USE_ASSERT_NULL								0
#define	LV_USE_ASSERT_MALLOC							0
#define	LV_USE_ASSERT_STYLE								0
#define	LV_USE_ASSERT_MEM_INTEGRITY						0
#define	LV_USE_ASSERT_OBJ								0

#define	LV_ASSERT_HANDLER_INCLUDE						<stdint.h>
#define	LV_ASSERT_HANDLER								while(1);

// Others
//
#define	LV_ENABLE_GLOBAL_CUSTOM							0
#define	LV_CACHE_DEF_SIZE								0
#define	LV_IMAGE_HEADER_CACHE_DEF_CNT					0
#define	LV_GRADIENT_MAX_STOPS							2
#define	LV_COLOR_MIX_ROUND_OFS							0
#define	LV_OBJ_STYLE_CACHE								0
#define	LV_USE_OBJ_ID									0
#define	LV_USE_OBJ_ID_BUILTIN							1
#define	LV_USE_OBJ_PROPERTY								0
#define	LV_USE_OBJ_PROPERTY_NAME						1

// FONT USAGE
// ==========

#define	LV_FONT_MONTSERRAT_8							0
#define	LV_FONT_MONTSERRAT_10							0
#define	LV_FONT_MONTSERRAT_12							0
#define	LV_FONT_MONTSERRAT_14							0
#define	LV_FONT_MONTSERRAT_16							1
#define	LV_FONT_MONTSERRAT_18							0
#define	LV_FONT_MONTSERRAT_20							0
#define	LV_FONT_MONTSERRAT_22							0
#define	LV_FONT_MONTSERRAT_24							0
#define	LV_FONT_MONTSERRAT_26							1
#define	LV_FONT_MONTSERRAT_28							0
#define	LV_FONT_MONTSERRAT_30							0
#define	LV_FONT_MONTSERRAT_32							0
#define	LV_FONT_MONTSERRAT_34							0
#define	LV_FONT_MONTSERRAT_36							0
#define	LV_FONT_MONTSERRAT_38							0
#define	LV_FONT_MONTSERRAT_40							0
#define	LV_FONT_MONTSERRAT_42							0
#define	LV_FONT_MONTSERRAT_44							0
#define	LV_FONT_MONTSERRAT_46							0
#define	LV_FONT_MONTSERRAT_48							0

#define	LV_FONT_MONTSERRAT_28_COMPRESSED				0
#define	LV_FONT_DEJAVU_16_PERSIAN_HEBREW				0
#define	LV_FONT_SIMSUN_14_CJK							0
#define	LV_FONT_SIMSUN_16_CJK							0
#define	LV_FONT_SOURCE_HAN_SANS_SC_14_CJK 				0
#define	LV_FONT_SOURCE_HAN_SANS_SC_16_CJK 				0

#define	LV_FONT_DEFAULT									&lv_font_montserrat_16

#define	LV_FONT_FMT_TXT_LARGE							0
#define	LV_USE_FONT_COMPRESSED							0
#define	LV_USE_FONT_PLACEHOLDER							1

// TEXT SETTINGS
// =============

#define	LV_TXT_ENC										LV_TXT_ENC_UTF8
#define	LV_TXT_BREAK_CHARS								" ,.;:-_)]}"
#define	LV_TXT_LINE_BREAK_LONG_LEN						0
#define	LV_TXT_LINE_BREAK_LONG_PRE_MIN_LEN				3
#define	LV_TXT_LINE_BREAK_LONG_POST_MIN_LEN				3

#define	LV_USE_BIDI										0
#define	LV_USE_ARABIC_PERSIAN_CHARS						0
#define	LV_TXT_COLOR_CMD								"#"

// WIDGETS
// =======

#define	LV_WIDGETS_HAS_DEFAULT_VALUE					1
#define	LV_USE_ANIMIMG									1
#define	LV_USE_ARC										1
#define	LV_USE_ARCLABEL									1
#define	LV_USE_BAR										1
#define	LV_USE_BUTTON									1
#define	LV_USE_BUTTONMATRIX								1
#define	LV_USE_CALENDAR									1
#if LV_USE_CALENDAR
	#define	LV_CALENDAR_WEEK_STARTS_MONDAY				0
	#if LV_CALENDAR_WEEK_STARTS_MONDAY
		#define	LV_CALENDAR_DEFAULT_DAY_NAMES			{ "Mo", "Tu", "We", "Th", "Fr", "Sa", "Su" }
	#else
		#define	LV_CALENDAR_DEFAULT_DAY_NAMES			{ "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" }
	#endif
	#define	LV_CALENDAR_DEFAULT_MONTH_NAMES				{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" }
	#define	LV_USE_CALENDAR_HEADER_ARROW				1
	#define	LV_USE_CALENDAR_HEADER_DROPDOWN				1
	#define	LV_USE_CALENDAR_CHINESE						0
#endif
#define	LV_USE_CANVAS									1
#define	LV_USE_CHART									1
#define	LV_USE_CHECKBOX									1
#define	LV_USE_DROPDOWN									1
#define	LV_USE_IMAGE									1
#define	LV_USE_IMAGEBUTTON								1
#define	LV_USE_KEYBOARD									1
#define	LV_USE_LABEL									1
#if LV_USE_LABEL
	#define	LV_LABEL_TEXT_SELECTION						1
	#define	LV_LABEL_LONG_TXT_HINT						1
	#define	LV_LABEL_WAIT_CHAR_COUNT					3
#endif
#define	LV_USE_LED										1
#define	LV_USE_LINE										1
#define	LV_USE_LIST										1
#define	LV_USE_LOTTIE									0
#define	LV_USE_MENU										1
#define	LV_USE_MSGBOX									1
#define	LV_USE_ROLLER									1
#define	LV_USE_SCALE									1
#define	LV_USE_SLIDER									1
#define	LV_USE_SPAN										1
#if LV_USE_SPAN
	#define	LV_SPAN_SNIPPET_STACK_SIZE					64
#endif
#define	LV_USE_SPINBOX									1
#define	LV_USE_SPINNER									1
#define	LV_USE_SWITCH									1
#define	LV_USE_TABLE									1
#define	LV_USE_TABVIEW									1
#define	LV_USE_TEXTAREA									1
#if LV_USE_TEXTAREA
	#define	LV_TEXTAREA_DEF_PWD_SHOW_TIME				1500
#endif
#define	LV_USE_TILEVIEW									1
#define	LV_USE_WIN										1

// THEMES
// ======

#define	LV_USE_THEME_DEFAULT							0
#if LV_USE_THEME_DEFAULT
	#define	LV_THEME_DEFAULT_DARK						0
	#define	LV_THEME_DEFAULT_GROW						1
	#define	LV_THEME_DEFAULT_TRANSITION_TIME			80
#endif
#define	LV_USE_THEME_SIMPLE								1
#define	LV_USE_THEME_MONO								0

// BUILD OPTIONS
// =============

#define	LV_DISABLE_API_MAPPING							1
#define	LV_BUILD_EXAMPLES								0
#define	LV_BUILD_DEMOS									0

#endif
#endif
