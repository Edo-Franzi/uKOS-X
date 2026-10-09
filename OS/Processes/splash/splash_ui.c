/*
; splash_ui.
; ==========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2026 Laurent von Allmen

;------------------------------------------------------------------------
; Author:	Laurent von Allmen	The 2026-10-08
; Modifs:
;
; Project:	uKOS-X
; Goal:		Drawing of the boot banner of the splash process.
;
;   (c) 2026, Laurent von Allmen
;   ----------------------------
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
#include	"splash_ui.h"
#include	"ulvgl.h"

typedef struct	line	line_t;

struct	line {
		const	char_t		*oText;				// Ptr on the first character of the line
				uint32_t	oLength;			// Number of characters (without the '\n')
		};

// The same logo as the one printed by the startUp process

STRG_LOC_CONST(aStrLogo[]) = STRG_LOGO;

// Prototypes

static	bool	local_getLine(const char_t **text, line_t *line);
static	bool	local_isArt(const line_t *line);
static	bool	local_isRule(const line_t *line);
static	void	local_getTag(const line_t *line, line_t *tag);
static	void	local_drawLogo_cb(lv_event_t *event);

/*
 * \brief splash_ui_draw
 *
 * - Draw the boot banner: the title, the logo and its tag line, then
 *	 the signature of the system, its identifier and the value of the
 *	 switches
 *
 */
void	splash_ui_draw(void) {
			uint32_t	mode = 0u, nbRows = 0u, nbTags = 0u;
			line_t		line, title = { "", 0u }, tag[KLOGO_NB_TAG_LINES] = { { "", 0u }, { "", 0u } };
			bool		titleFound = false;
			lv_obj_t	*screen, *titleLabel, *logo, *tagLabel, *info;
	const	char_t		*identifier = "", *signature = "", *text = aStrLogo, *footer = "";

	(void)switch_read(&mode);
	(void)system_getSystemId(&identifier);
	(void)system_getSystemSignature(&signature);

// Split the logo: the title is its first text, the rows of the ASCII
// art are drawn, their ends are the tag lines and what follows the
// ASCII art is the footer

	while (local_getLine(&text, &line)) {
		if (local_isArt(&line)) {
			nbRows++;
			if (nbTags < KLOGO_NB_TAG_LINES) {
				local_getTag(&line, &tag[nbTags]);
				if (tag[nbTags].oLength > 0u) {
					nbTags++;
				}
			}
			footer = text;
		}
		else if ((!titleFound) && (line.oLength > 0u) && (!local_isRule(&line))) {
			title	   = line;
			titleFound = true;
		}
		else {

// Make MISRA happy :-)

		}
	}

	while (*footer == '\n') {
		footer++;
	}

	screen = lv_screen_active();
	lv_obj_set_style_bg_color(screen, lv_color_hex(KBACKGROUND), 0);
	lv_obj_set_style_bg_opa(screen, LV_OPA_COVER, 0);
	lv_obj_set_style_text_color(screen, lv_color_hex(KFOREGROUND), 0);
	lv_obj_set_style_text_font(screen, &lv_font_montserrat_16, 0);

// The title

	titleLabel = lv_label_create(screen);
	lv_obj_set_style_text_font(titleLabel, &lv_font_montserrat_26, 0);
	lv_label_set_text_fmt(titleLabel, "%.*s", (int)title.oLength, title.oText);

// The logo: an empty object, drawn by its callback

	logo = lv_obj_create(screen);
	lv_obj_remove_style_all(logo);
	lv_obj_set_size(logo, (int32_t)((KLOGO_NB_COLUMNS * KLOGO_CELL_WIDTH)  + (2u * KLOGO_LINE_WIDTH)),
						  (int32_t)((nbRows			  * KLOGO_CELL_HEIGHT) + (2u * KLOGO_LINE_WIDTH)));
	lv_obj_add_event_cb(logo, local_drawLogo_cb, LV_EVENT_DRAW_MAIN, nullptr);

	lv_obj_align(logo, LV_ALIGN_TOP_MID, 0, KTITLE_POS_Y + lv_font_montserrat_26.line_height + KLOGO_GAP_Y);
	lv_obj_align_to(titleLabel, logo, LV_ALIGN_OUT_TOP_LEFT, 0, -KLOGO_GAP_Y);

// The tag lines, in the bottom right corner of the logo, which is empty

	tagLabel = lv_label_create(screen);
	lv_obj_set_style_text_align(tagLabel, LV_TEXT_ALIGN_RIGHT, 0);
	lv_label_set_text_fmt(tagLabel, "%.*s\n%.*s", (int)tag[0].oLength, tag[0].oText, (int)tag[1].oLength, tag[1].oText);
	lv_obj_align_to(tagLabel, logo, LV_ALIGN_BOTTOM_RIGHT, 0, KTAG_GAP_Y);

// The footer, the signature, the identifier and the switches

	info = lv_label_create(screen);
	lv_label_set_text_fmt(info, "%s"
								"Signature:\n%s\n\n"
								"%ssw = %"PRIu32,
								footer, signature, identifier, mode);
	lv_obj_align_to(info, logo, LV_ALIGN_OUT_BOTTOM_LEFT, 0, KINFO_GAP_Y);
}

// Local routines
// ==============

/*
 * \brief local_getLine
 *
 * - Get the next line of a text and move to the following one
 * - Return false when the text is finished
 *
 */
static	bool	local_getLine(const char_t **text, line_t *line) {
	const	char_t	*end = *text;

	if (*end == '\0') {
		return (false);
	}

	while ((*end != '\n') && (*end != '\0')) {
		end++;
	}

	line->oText	  = *text;
	line->oLength = (uint32_t)(end - *text);
	*text		  = (*end == '\n') ? (&end[1]) : (end);
	return (true);
}

/*
 * \brief local_isArt
 *
 * - A row of the ASCII art is a line with a '/'
 *
 */
static	bool	local_isArt(const line_t *line) {
	uint32_t	i;

	for (i = 0u; i < line->oLength; i++) {
		if (line->oText[i] == '/') {
			return (true);
		}
	}
	return (false);
}

/*
 * \brief local_isRule
 *
 * - A rule is a line made only of '_'
 *
 */
static	bool	local_isRule(const line_t *line) {
	uint32_t	i;

	for (i = 0u; i < line->oLength; i++) {
		if (line->oText[i] != '_') {
			return (false);
		}
	}
	return (line->oLength > 0u);
}

/*
 * \brief local_getTag
 *
 * - Get the tag line of a row of the ASCII art: what follows the
 *	 columns of the ASCII art, without its leading ' ' and '_'
 *
 */
static	void	local_getTag(const line_t *line, line_t *tag) {
	uint32_t	i = KLOGO_NB_COLUMNS;

	while ((i < line->oLength) && ((line->oText[i] == ' ') || (line->oText[i] == '_'))) {
		i++;
	}

	tag->oText	 = (i < line->oLength) ? (&line->oText[i])	 : ("");
	tag->oLength = (i < line->oLength) ? (line->oLength - i) : (0u);
}

/*
 * \brief local_drawLogo_cb
 *
 * - Draw the ASCII art: a '_' is the bottom of its cell and a '/' its
 *	 diagonal. The cells share their corners, so the lines join up
 *
 */
static	void	local_drawLogo_cb(lv_event_t *event) {
			uint32_t			row = 0u, column;
			int32_t				x, y;
			line_t				line;
			lv_area_t			coords;
			lv_draw_line_dsc_t	dsc;
			lv_obj_t			*object = lv_event_get_target_obj(event);
			lv_layer_t			*layer	= lv_event_get_layer(event);
	const	char_t				*text = aStrLogo;

	lv_obj_get_coords(object, &coords);

	lv_draw_line_dsc_init(&dsc);
	dsc.color		= lv_color_hex(KFOREGROUND);
	dsc.width		= (int32_t)KLOGO_LINE_WIDTH;
	dsc.round_start = 1u;
	dsc.round_end	= 1u;

	while (local_getLine(&text, &line)) {
		if (local_isArt(&line)) {
			row++;
			y = coords.y1 + (int32_t)KLOGO_LINE_WIDTH + (int32_t)(row * KLOGO_CELL_HEIGHT);

			for (column = 0u; (column < line.oLength) && (column < KLOGO_NB_COLUMNS); column++) {
				x = coords.x1 + (int32_t)KLOGO_LINE_WIDTH + (int32_t)(column * KLOGO_CELL_WIDTH);

				dsc.p1.x = (lv_value_precise_t)x;
				dsc.p1.y = (lv_value_precise_t)y;
				dsc.p2.x = (lv_value_precise_t)(x + (int32_t)KLOGO_CELL_WIDTH);

				switch (line.oText[column]) {
					case '_': { dsc.p2.y = (lv_value_precise_t)y;								 lv_draw_line(layer, &dsc); break; }
					case '/': { dsc.p2.y = (lv_value_precise_t)(y - (int32_t)KLOGO_CELL_HEIGHT); lv_draw_line(layer, &dsc); break; }
					default: {

// Make MISRA happy :-)

						break;
					}
				}
			}
		}
	}
}
