/*
; stm32N657_gfxmmu.
; =================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Generated using the .svd description	The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stm32N657_gfxmmu equates.
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

#pragma	once

// GFXMMU address definitions
// --------------------------

typedef struct {
	volatile	uint32_t	CR;
	volatile	uint32_t	SR;
	volatile	uint32_t	FCR;
	volatile	uint32_t	RESERVED0;
	volatile	uint32_t	DVR;
	volatile	uint32_t	DAR;
	volatile	uint32_t	RESERVED1[2];
	volatile	uint32_t	B0CR;
	volatile	uint32_t	B1CR;
	volatile	uint32_t	B2CR;
	volatile	uint32_t	B3CR;
	volatile	uint32_t	RESERVED2[1012];
	volatile	uint32_t	LUT0L;
	volatile	uint32_t	LUT0H;
	volatile	uint32_t	LUT1L;
	volatile	uint32_t	LUT1H;
	volatile	uint32_t	LUT2L;
	volatile	uint32_t	LUT2H;
	volatile	uint32_t	LUT3L;
	volatile	uint32_t	LUT3H;
	volatile	uint32_t	LUT4L;
	volatile	uint32_t	LUT4H;
	volatile	uint32_t	LUT5L;
	volatile	uint32_t	LUT5H;
	volatile	uint32_t	LUT6L;
	volatile	uint32_t	LUT6H;
	volatile	uint32_t	LUT7L;
	volatile	uint32_t	LUT7H;
	volatile	uint32_t	LUT8L;
	volatile	uint32_t	LUT8H;
	volatile	uint32_t	LUT9L;
	volatile	uint32_t	LUT9H;
	volatile	uint32_t	LUT10L;
	volatile	uint32_t	LUT10H;
	volatile	uint32_t	LUT11L;
	volatile	uint32_t	LUT11H;
	volatile	uint32_t	LUT12L;
	volatile	uint32_t	LUT12H;
	volatile	uint32_t	LUT13L;
	volatile	uint32_t	LUT13H;
	volatile	uint32_t	LUT14L;
	volatile	uint32_t	LUT14H;
	volatile	uint32_t	LUT15L;
	volatile	uint32_t	LUT15H;
	volatile	uint32_t	LUT16L;
	volatile	uint32_t	LUT16H;
	volatile	uint32_t	LUT17L;
	volatile	uint32_t	LUT17H;
	volatile	uint32_t	LUT18L;
	volatile	uint32_t	LUT18H;
	volatile	uint32_t	LUT19L;
	volatile	uint32_t	LUT19H;
	volatile	uint32_t	LUT20L;
	volatile	uint32_t	LUT20H;
	volatile	uint32_t	LUT21L;
	volatile	uint32_t	LUT21H;
	volatile	uint32_t	LUT22L;
	volatile	uint32_t	LUT22H;
	volatile	uint32_t	LUT23L;
	volatile	uint32_t	LUT23H;
	volatile	uint32_t	LUT24L;
	volatile	uint32_t	LUT24H;
	volatile	uint32_t	LUT25L;
	volatile	uint32_t	LUT25H;
	volatile	uint32_t	LUT26L;
	volatile	uint32_t	LUT26H;
	volatile	uint32_t	LUT27L;
	volatile	uint32_t	LUT27H;
	volatile	uint32_t	LUT28L;
	volatile	uint32_t	LUT28H;
	volatile	uint32_t	LUT29L;
	volatile	uint32_t	LUT29H;
	volatile	uint32_t	LUT30L;
	volatile	uint32_t	LUT30H;
	volatile	uint32_t	LUT31L;
	volatile	uint32_t	LUT31H;
	volatile	uint32_t	LUT32L;
	volatile	uint32_t	LUT32H;
	volatile	uint32_t	LUT33L;
	volatile	uint32_t	LUT33H;
	volatile	uint32_t	LUT34L;
	volatile	uint32_t	LUT34H;
	volatile	uint32_t	LUT35L;
	volatile	uint32_t	LUT35H;
	volatile	uint32_t	LUT36L;
	volatile	uint32_t	LUT36H;
	volatile	uint32_t	LUT37L;
	volatile	uint32_t	LUT37H;
	volatile	uint32_t	LUT38L;
	volatile	uint32_t	LUT38H;
	volatile	uint32_t	LUT39L;
	volatile	uint32_t	LUT39H;
	volatile	uint32_t	LUT40L;
	volatile	uint32_t	LUT40H;
	volatile	uint32_t	LUT41L;
	volatile	uint32_t	LUT41H;
	volatile	uint32_t	LUT42L;
	volatile	uint32_t	LUT42H;
	volatile	uint32_t	LUT43L;
	volatile	uint32_t	LUT43H;
	volatile	uint32_t	LUT44L;
	volatile	uint32_t	LUT44H;
	volatile	uint32_t	LUT45L;
	volatile	uint32_t	LUT45H;
	volatile	uint32_t	LUT46L;
	volatile	uint32_t	LUT46H;
	volatile	uint32_t	LUT47L;
	volatile	uint32_t	LUT47H;
	volatile	uint32_t	LUT48L;
	volatile	uint32_t	LUT48H;
	volatile	uint32_t	LUT49L;
	volatile	uint32_t	LUT49H;
	volatile	uint32_t	LUT50L;
	volatile	uint32_t	LUT50H;
	volatile	uint32_t	LUT51L;
	volatile	uint32_t	LUT51H;
	volatile	uint32_t	LUT52L;
	volatile	uint32_t	LUT52H;
	volatile	uint32_t	LUT53L;
	volatile	uint32_t	LUT53H;
	volatile	uint32_t	LUT54L;
	volatile	uint32_t	LUT54H;
	volatile	uint32_t	LUT55L;
	volatile	uint32_t	LUT55H;
	volatile	uint32_t	LUT56L;
	volatile	uint32_t	LUT56H;
	volatile	uint32_t	LUT57L;
	volatile	uint32_t	LUT57H;
	volatile	uint32_t	LUT58L;
	volatile	uint32_t	LUT58H;
	volatile	uint32_t	LUT59L;
	volatile	uint32_t	LUT59H;
	volatile	uint32_t	LUT60L;
	volatile	uint32_t	LUT60H;
	volatile	uint32_t	LUT61L;
	volatile	uint32_t	LUT61H;
	volatile	uint32_t	LUT62L;
	volatile	uint32_t	LUT62H;
	volatile	uint32_t	LUT63L;
	volatile	uint32_t	LUT63H;
	volatile	uint32_t	LUT64L;
	volatile	uint32_t	LUT64H;
	volatile	uint32_t	LUT65L;
	volatile	uint32_t	LUT65H;
	volatile	uint32_t	LUT66L;
	volatile	uint32_t	LUT66H;
	volatile	uint32_t	LUT67L;
	volatile	uint32_t	LUT67H;
	volatile	uint32_t	LUT68L;
	volatile	uint32_t	LUT68H;
	volatile	uint32_t	LUT69L;
	volatile	uint32_t	LUT69H;
	volatile	uint32_t	LUT70L;
	volatile	uint32_t	LUT70H;
	volatile	uint32_t	LUT71L;
	volatile	uint32_t	LUT71H;
	volatile	uint32_t	LUT72L;
	volatile	uint32_t	LUT72H;
	volatile	uint32_t	LUT73L;
	volatile	uint32_t	LUT73H;
	volatile	uint32_t	LUT74L;
	volatile	uint32_t	LUT74H;
	volatile	uint32_t	LUT75L;
	volatile	uint32_t	LUT75H;
	volatile	uint32_t	LUT76L;
	volatile	uint32_t	LUT76H;
	volatile	uint32_t	LUT77L;
	volatile	uint32_t	LUT77H;
	volatile	uint32_t	LUT78L;
	volatile	uint32_t	LUT78H;
	volatile	uint32_t	LUT79L;
	volatile	uint32_t	LUT79H;
	volatile	uint32_t	LUT80L;
	volatile	uint32_t	LUT80H;
	volatile	uint32_t	LUT81L;
	volatile	uint32_t	LUT81H;
	volatile	uint32_t	LUT82L;
	volatile	uint32_t	LUT82H;
	volatile	uint32_t	LUT83L;
	volatile	uint32_t	LUT83H;
	volatile	uint32_t	LUT84L;
	volatile	uint32_t	LUT84H;
	volatile	uint32_t	LUT85L;
	volatile	uint32_t	LUT85H;
	volatile	uint32_t	LUT86L;
	volatile	uint32_t	LUT86H;
	volatile	uint32_t	LUT87L;
	volatile	uint32_t	LUT87H;
	volatile	uint32_t	LUT88L;
	volatile	uint32_t	LUT88H;
	volatile	uint32_t	LUT89L;
	volatile	uint32_t	LUT89H;
	volatile	uint32_t	LUT90L;
	volatile	uint32_t	LUT90H;
	volatile	uint32_t	LUT91L;
	volatile	uint32_t	LUT91H;
	volatile	uint32_t	LUT92L;
	volatile	uint32_t	LUT92H;
	volatile	uint32_t	LUT93L;
	volatile	uint32_t	LUT93H;
	volatile	uint32_t	LUT94L;
	volatile	uint32_t	LUT94H;
	volatile	uint32_t	LUT95L;
	volatile	uint32_t	LUT95H;
	volatile	uint32_t	LUT96L;
	volatile	uint32_t	LUT96H;
	volatile	uint32_t	LUT97L;
	volatile	uint32_t	LUT97H;
	volatile	uint32_t	LUT98L;
	volatile	uint32_t	LUT98H;
	volatile	uint32_t	LUT99L;
	volatile	uint32_t	LUT99H;
	volatile	uint32_t	LUT100L;
	volatile	uint32_t	LUT100H;
	volatile	uint32_t	LUT101L;
	volatile	uint32_t	LUT101H;
	volatile	uint32_t	LUT102L;
	volatile	uint32_t	LUT102H;
	volatile	uint32_t	LUT103L;
	volatile	uint32_t	LUT103H;
	volatile	uint32_t	LUT104L;
	volatile	uint32_t	LUT104H;
	volatile	uint32_t	LUT105L;
	volatile	uint32_t	LUT105H;
	volatile	uint32_t	LUT106L;
	volatile	uint32_t	LUT106H;
	volatile	uint32_t	LUT107L;
	volatile	uint32_t	LUT107H;
	volatile	uint32_t	LUT108L;
	volatile	uint32_t	LUT108H;
	volatile	uint32_t	LUT109L;
	volatile	uint32_t	LUT109H;
	volatile	uint32_t	LUT110L;
	volatile	uint32_t	LUT110H;
	volatile	uint32_t	LUT111L;
	volatile	uint32_t	LUT111H;
	volatile	uint32_t	LUT112L;
	volatile	uint32_t	LUT112H;
	volatile	uint32_t	LUT113L;
	volatile	uint32_t	LUT113H;
	volatile	uint32_t	LUT114L;
	volatile	uint32_t	LUT114H;
	volatile	uint32_t	LUT115L;
	volatile	uint32_t	LUT115H;
	volatile	uint32_t	LUT116L;
	volatile	uint32_t	LUT116H;
	volatile	uint32_t	LUT117L;
	volatile	uint32_t	LUT117H;
	volatile	uint32_t	LUT118L;
	volatile	uint32_t	LUT118H;
	volatile	uint32_t	LUT119L;
	volatile	uint32_t	LUT119H;
	volatile	uint32_t	LUT120L;
	volatile	uint32_t	LUT120H;
	volatile	uint32_t	LUT121L;
	volatile	uint32_t	LUT121H;
	volatile	uint32_t	LUT122L;
	volatile	uint32_t	LUT122H;
	volatile	uint32_t	LUT123L;
	volatile	uint32_t	LUT123H;
	volatile	uint32_t	LUT124L;
	volatile	uint32_t	LUT124H;
	volatile	uint32_t	LUT125L;
	volatile	uint32_t	LUT125H;
	volatile	uint32_t	LUT126L;
	volatile	uint32_t	LUT126H;
	volatile	uint32_t	LUT127L;
	volatile	uint32_t	LUT127H;
	volatile	uint32_t	LUT128L;
	volatile	uint32_t	LUT128H;
	volatile	uint32_t	LUT129L;
	volatile	uint32_t	LUT129H;
	volatile	uint32_t	LUT130L;
	volatile	uint32_t	LUT130H;
	volatile	uint32_t	LUT131L;
	volatile	uint32_t	LUT131H;
	volatile	uint32_t	LUT132L;
	volatile	uint32_t	LUT132H;
	volatile	uint32_t	LUT133L;
	volatile	uint32_t	LUT133H;
	volatile	uint32_t	LUT134L;
	volatile	uint32_t	LUT134H;
	volatile	uint32_t	LUT135L;
	volatile	uint32_t	LUT135H;
	volatile	uint32_t	LUT136L;
	volatile	uint32_t	LUT136H;
	volatile	uint32_t	LUT137L;
	volatile	uint32_t	LUT137H;
	volatile	uint32_t	LUT138L;
	volatile	uint32_t	LUT138H;
	volatile	uint32_t	LUT139L;
	volatile	uint32_t	LUT139H;
	volatile	uint32_t	LUT140L;
	volatile	uint32_t	LUT140H;
	volatile	uint32_t	LUT141L;
	volatile	uint32_t	LUT141H;
	volatile	uint32_t	LUT142L;
	volatile	uint32_t	LUT142H;
	volatile	uint32_t	LUT143L;
	volatile	uint32_t	LUT143H;
	volatile	uint32_t	LUT144L;
	volatile	uint32_t	LUT144H;
	volatile	uint32_t	LUT145L;
	volatile	uint32_t	LUT145H;
	volatile	uint32_t	LUT146L;
	volatile	uint32_t	LUT146H;
	volatile	uint32_t	LUT147L;
	volatile	uint32_t	LUT147H;
	volatile	uint32_t	LUT148L;
	volatile	uint32_t	LUT148H;
	volatile	uint32_t	LUT149L;
	volatile	uint32_t	LUT149H;
	volatile	uint32_t	LUT150L;
	volatile	uint32_t	LUT150H;
	volatile	uint32_t	LUT151L;
	volatile	uint32_t	LUT151H;
	volatile	uint32_t	LUT152L;
	volatile	uint32_t	LUT152H;
	volatile	uint32_t	LUT153L;
	volatile	uint32_t	LUT153H;
	volatile	uint32_t	LUT154L;
	volatile	uint32_t	LUT154H;
	volatile	uint32_t	LUT155L;
	volatile	uint32_t	LUT155H;
	volatile	uint32_t	LUT156L;
	volatile	uint32_t	LUT156H;
	volatile	uint32_t	LUT157L;
	volatile	uint32_t	LUT157H;
	volatile	uint32_t	LUT158L;
	volatile	uint32_t	LUT158H;
	volatile	uint32_t	LUT159L;
	volatile	uint32_t	LUT159H;
	volatile	uint32_t	LUT160L;
	volatile	uint32_t	LUT160H;
	volatile	uint32_t	LUT161L;
	volatile	uint32_t	LUT161H;
	volatile	uint32_t	LUT162L;
	volatile	uint32_t	LUT162H;
	volatile	uint32_t	LUT163L;
	volatile	uint32_t	LUT163H;
	volatile	uint32_t	LUT164L;
	volatile	uint32_t	LUT164H;
	volatile	uint32_t	LUT165L;
	volatile	uint32_t	LUT165H;
	volatile	uint32_t	LUT166L;
	volatile	uint32_t	LUT166H;
	volatile	uint32_t	LUT167L;
	volatile	uint32_t	LUT167H;
	volatile	uint32_t	LUT168L;
	volatile	uint32_t	LUT168H;
	volatile	uint32_t	LUT169L;
	volatile	uint32_t	LUT169H;
	volatile	uint32_t	LUT170L;
	volatile	uint32_t	LUT170H;
	volatile	uint32_t	LUT171L;
	volatile	uint32_t	LUT171H;
	volatile	uint32_t	LUT172L;
	volatile	uint32_t	LUT172H;
	volatile	uint32_t	LUT173L;
	volatile	uint32_t	LUT173H;
	volatile	uint32_t	LUT174L;
	volatile	uint32_t	LUT174H;
	volatile	uint32_t	LUT175L;
	volatile	uint32_t	LUT175H;
	volatile	uint32_t	LUT176L;
	volatile	uint32_t	LUT176H;
	volatile	uint32_t	LUT177L;
	volatile	uint32_t	LUT177H;
	volatile	uint32_t	LUT178L;
	volatile	uint32_t	LUT178H;
	volatile	uint32_t	LUT179L;
	volatile	uint32_t	LUT179H;
	volatile	uint32_t	LUT180L;
	volatile	uint32_t	LUT180H;
	volatile	uint32_t	LUT181L;
	volatile	uint32_t	LUT181H;
	volatile	uint32_t	LUT182L;
	volatile	uint32_t	LUT182H;
	volatile	uint32_t	LUT183L;
	volatile	uint32_t	LUT183H;
	volatile	uint32_t	LUT184L;
	volatile	uint32_t	LUT184H;
	volatile	uint32_t	LUT185L;
	volatile	uint32_t	LUT185H;
	volatile	uint32_t	LUT186L;
	volatile	uint32_t	LUT186H;
	volatile	uint32_t	LUT187L;
	volatile	uint32_t	LUT187H;
	volatile	uint32_t	LUT188L;
	volatile	uint32_t	LUT188H;
	volatile	uint32_t	LUT189L;
	volatile	uint32_t	LUT189H;
	volatile	uint32_t	LUT190L;
	volatile	uint32_t	LUT190H;
	volatile	uint32_t	LUT191L;
	volatile	uint32_t	LUT191H;
	volatile	uint32_t	LUT192L;
	volatile	uint32_t	LUT192H;
	volatile	uint32_t	LUT193L;
	volatile	uint32_t	LUT193H;
	volatile	uint32_t	LUT194L;
	volatile	uint32_t	LUT194H;
	volatile	uint32_t	LUT195L;
	volatile	uint32_t	LUT195H;
	volatile	uint32_t	LUT196L;
	volatile	uint32_t	LUT196H;
	volatile	uint32_t	LUT197L;
	volatile	uint32_t	LUT197H;
	volatile	uint32_t	LUT198L;
	volatile	uint32_t	LUT198H;
	volatile	uint32_t	LUT199L;
	volatile	uint32_t	LUT199H;
	volatile	uint32_t	LUT200L;
	volatile	uint32_t	LUT200H;
	volatile	uint32_t	LUT201L;
	volatile	uint32_t	LUT201H;
	volatile	uint32_t	LUT202L;
	volatile	uint32_t	LUT202H;
	volatile	uint32_t	LUT203L;
	volatile	uint32_t	LUT203H;
	volatile	uint32_t	LUT204L;
	volatile	uint32_t	LUT204H;
	volatile	uint32_t	LUT205L;
	volatile	uint32_t	LUT205H;
	volatile	uint32_t	LUT206L;
	volatile	uint32_t	LUT206H;
	volatile	uint32_t	LUT207L;
	volatile	uint32_t	LUT207H;
	volatile	uint32_t	LUT208L;
	volatile	uint32_t	LUT208H;
	volatile	uint32_t	LUT209L;
	volatile	uint32_t	LUT209H;
	volatile	uint32_t	LUT210L;
	volatile	uint32_t	LUT210H;
	volatile	uint32_t	LUT211L;
	volatile	uint32_t	LUT211H;
	volatile	uint32_t	LUT212L;
	volatile	uint32_t	LUT212H;
	volatile	uint32_t	LUT213L;
	volatile	uint32_t	LUT213H;
	volatile	uint32_t	LUT214L;
	volatile	uint32_t	LUT214H;
	volatile	uint32_t	LUT215L;
	volatile	uint32_t	LUT215H;
	volatile	uint32_t	LUT216L;
	volatile	uint32_t	LUT216H;
	volatile	uint32_t	LUT217L;
	volatile	uint32_t	LUT217H;
	volatile	uint32_t	LUT218L;
	volatile	uint32_t	LUT218H;
	volatile	uint32_t	LUT219L;
	volatile	uint32_t	LUT219H;
	volatile	uint32_t	LUT220L;
	volatile	uint32_t	LUT220H;
	volatile	uint32_t	LUT221L;
	volatile	uint32_t	LUT221H;
	volatile	uint32_t	LUT222L;
	volatile	uint32_t	LUT222H;
	volatile	uint32_t	LUT223L;
	volatile	uint32_t	LUT223H;
	volatile	uint32_t	LUT224L;
	volatile	uint32_t	LUT224H;
	volatile	uint32_t	LUT225L;
	volatile	uint32_t	LUT225H;
	volatile	uint32_t	LUT226L;
	volatile	uint32_t	LUT226H;
	volatile	uint32_t	LUT227L;
	volatile	uint32_t	LUT227H;
	volatile	uint32_t	LUT228L;
	volatile	uint32_t	LUT228H;
	volatile	uint32_t	LUT229L;
	volatile	uint32_t	LUT229H;
	volatile	uint32_t	LUT230L;
	volatile	uint32_t	LUT230H;
	volatile	uint32_t	LUT231L;
	volatile	uint32_t	LUT231H;
	volatile	uint32_t	LUT232L;
	volatile	uint32_t	LUT232H;
	volatile	uint32_t	LUT233L;
	volatile	uint32_t	LUT233H;
	volatile	uint32_t	LUT234L;
	volatile	uint32_t	LUT234H;
	volatile	uint32_t	LUT235L;
	volatile	uint32_t	LUT235H;
	volatile	uint32_t	LUT236L;
	volatile	uint32_t	LUT236H;
	volatile	uint32_t	LUT237L;
	volatile	uint32_t	LUT237H;
	volatile	uint32_t	LUT238L;
	volatile	uint32_t	LUT238H;
	volatile	uint32_t	LUT239L;
	volatile	uint32_t	LUT239H;
	volatile	uint32_t	LUT240L;
	volatile	uint32_t	LUT240H;
	volatile	uint32_t	LUT241L;
	volatile	uint32_t	LUT241H;
	volatile	uint32_t	LUT242L;
	volatile	uint32_t	LUT242H;
	volatile	uint32_t	LUT243L;
	volatile	uint32_t	LUT243H;
	volatile	uint32_t	LUT244L;
	volatile	uint32_t	LUT244H;
	volatile	uint32_t	LUT245L;
	volatile	uint32_t	LUT245H;
	volatile	uint32_t	LUT246L;
	volatile	uint32_t	LUT246H;
	volatile	uint32_t	LUT247L;
	volatile	uint32_t	LUT247H;
	volatile	uint32_t	LUT248L;
	volatile	uint32_t	LUT248H;
	volatile	uint32_t	LUT249L;
	volatile	uint32_t	LUT249H;
	volatile	uint32_t	LUT250L;
	volatile	uint32_t	LUT250H;
	volatile	uint32_t	LUT251L;
	volatile	uint32_t	LUT251H;
	volatile	uint32_t	LUT252L;
	volatile	uint32_t	LUT252H;
	volatile	uint32_t	LUT253L;
	volatile	uint32_t	LUT253H;
	volatile	uint32_t	LUT254L;
	volatile	uint32_t	LUT254H;
	volatile	uint32_t	LUT255L;
	volatile	uint32_t	LUT255H;
	volatile	uint32_t	LUT256L;
	volatile	uint32_t	LUT256H;
	volatile	uint32_t	LUT257L;
	volatile	uint32_t	LUT257H;
	volatile	uint32_t	LUT258L;
	volatile	uint32_t	LUT258H;
	volatile	uint32_t	LUT259L;
	volatile	uint32_t	LUT259H;
	volatile	uint32_t	LUT260L;
	volatile	uint32_t	LUT260H;
	volatile	uint32_t	LUT261L;
	volatile	uint32_t	LUT261H;
	volatile	uint32_t	LUT262L;
	volatile	uint32_t	LUT262H;
	volatile	uint32_t	LUT263L;
	volatile	uint32_t	LUT263H;
	volatile	uint32_t	LUT264L;
	volatile	uint32_t	LUT264H;
	volatile	uint32_t	LUT265L;
	volatile	uint32_t	LUT265H;
	volatile	uint32_t	LUT266L;
	volatile	uint32_t	LUT266H;
	volatile	uint32_t	LUT267L;
	volatile	uint32_t	LUT267H;
	volatile	uint32_t	LUT268L;
	volatile	uint32_t	LUT268H;
	volatile	uint32_t	LUT269L;
	volatile	uint32_t	LUT269H;
	volatile	uint32_t	LUT270L;
	volatile	uint32_t	LUT270H;
	volatile	uint32_t	LUT271L;
	volatile	uint32_t	LUT271H;
	volatile	uint32_t	LUT272L;
	volatile	uint32_t	LUT272H;
	volatile	uint32_t	LUT273L;
	volatile	uint32_t	LUT273H;
	volatile	uint32_t	LUT274L;
	volatile	uint32_t	LUT274H;
	volatile	uint32_t	LUT275L;
	volatile	uint32_t	LUT275H;
	volatile	uint32_t	LUT276L;
	volatile	uint32_t	LUT276H;
	volatile	uint32_t	LUT277L;
	volatile	uint32_t	LUT277H;
	volatile	uint32_t	LUT278L;
	volatile	uint32_t	LUT278H;
	volatile	uint32_t	LUT279L;
	volatile	uint32_t	LUT279H;
	volatile	uint32_t	LUT280L;
	volatile	uint32_t	LUT280H;
	volatile	uint32_t	LUT281L;
	volatile	uint32_t	LUT281H;
	volatile	uint32_t	LUT282L;
	volatile	uint32_t	LUT282H;
	volatile	uint32_t	LUT283L;
	volatile	uint32_t	LUT283H;
	volatile	uint32_t	LUT284L;
	volatile	uint32_t	LUT284H;
	volatile	uint32_t	LUT285L;
	volatile	uint32_t	LUT285H;
	volatile	uint32_t	LUT286L;
	volatile	uint32_t	LUT286H;
	volatile	uint32_t	LUT287L;
	volatile	uint32_t	LUT287H;
	volatile	uint32_t	LUT288L;
	volatile	uint32_t	LUT288H;
	volatile	uint32_t	LUT289L;
	volatile	uint32_t	LUT289H;
	volatile	uint32_t	LUT290L;
	volatile	uint32_t	LUT290H;
	volatile	uint32_t	LUT291L;
	volatile	uint32_t	LUT291H;
	volatile	uint32_t	LUT292L;
	volatile	uint32_t	LUT292H;
	volatile	uint32_t	LUT293L;
	volatile	uint32_t	LUT293H;
	volatile	uint32_t	LUT294L;
	volatile	uint32_t	LUT294H;
	volatile	uint32_t	LUT295L;
	volatile	uint32_t	LUT295H;
	volatile	uint32_t	LUT296L;
	volatile	uint32_t	LUT296H;
	volatile	uint32_t	LUT297L;
	volatile	uint32_t	LUT297H;
	volatile	uint32_t	LUT298L;
	volatile	uint32_t	LUT298H;
	volatile	uint32_t	LUT299L;
	volatile	uint32_t	LUT299H;
	volatile	uint32_t	LUT300L;
	volatile	uint32_t	LUT300H;
	volatile	uint32_t	LUT301L;
	volatile	uint32_t	LUT301H;
	volatile	uint32_t	LUT302L;
	volatile	uint32_t	LUT302H;
	volatile	uint32_t	LUT303L;
	volatile	uint32_t	LUT303H;
	volatile	uint32_t	LUT304L;
	volatile	uint32_t	LUT304H;
	volatile	uint32_t	LUT305L;
	volatile	uint32_t	LUT305H;
	volatile	uint32_t	LUT306L;
	volatile	uint32_t	LUT306H;
	volatile	uint32_t	LUT307L;
	volatile	uint32_t	LUT307H;
	volatile	uint32_t	LUT308L;
	volatile	uint32_t	LUT308H;
	volatile	uint32_t	LUT309L;
	volatile	uint32_t	LUT309H;
	volatile	uint32_t	LUT310L;
	volatile	uint32_t	LUT310H;
	volatile	uint32_t	LUT311L;
	volatile	uint32_t	LUT311H;
	volatile	uint32_t	LUT312L;
	volatile	uint32_t	LUT312H;
	volatile	uint32_t	LUT313L;
	volatile	uint32_t	LUT313H;
	volatile	uint32_t	LUT314L;
	volatile	uint32_t	LUT314H;
	volatile	uint32_t	LUT315L;
	volatile	uint32_t	LUT315H;
	volatile	uint32_t	LUT316L;
	volatile	uint32_t	LUT316H;
	volatile	uint32_t	LUT317L;
	volatile	uint32_t	LUT317H;
	volatile	uint32_t	LUT318L;
	volatile	uint32_t	LUT318H;
	volatile	uint32_t	LUT319L;
	volatile	uint32_t	LUT319H;
	volatile	uint32_t	LUT320L;
	volatile	uint32_t	LUT320H;
	volatile	uint32_t	LUT321L;
	volatile	uint32_t	LUT321H;
	volatile	uint32_t	LUT322L;
	volatile	uint32_t	LUT322H;
	volatile	uint32_t	LUT323L;
	volatile	uint32_t	LUT323H;
	volatile	uint32_t	LUT324L;
	volatile	uint32_t	LUT324H;
	volatile	uint32_t	LUT325L;
	volatile	uint32_t	LUT325H;
	volatile	uint32_t	LUT326L;
	volatile	uint32_t	LUT326H;
	volatile	uint32_t	LUT327L;
	volatile	uint32_t	LUT327H;
	volatile	uint32_t	LUT328L;
	volatile	uint32_t	LUT328H;
	volatile	uint32_t	LUT329L;
	volatile	uint32_t	LUT329H;
	volatile	uint32_t	LUT330L;
	volatile	uint32_t	LUT330H;
	volatile	uint32_t	LUT331L;
	volatile	uint32_t	LUT331H;
	volatile	uint32_t	LUT332L;
	volatile	uint32_t	LUT332H;
	volatile	uint32_t	LUT333L;
	volatile	uint32_t	LUT333H;
	volatile	uint32_t	LUT334L;
	volatile	uint32_t	LUT334H;
	volatile	uint32_t	LUT335L;
	volatile	uint32_t	LUT335H;
	volatile	uint32_t	LUT336L;
	volatile	uint32_t	LUT336H;
	volatile	uint32_t	LUT337L;
	volatile	uint32_t	LUT337H;
	volatile	uint32_t	LUT338L;
	volatile	uint32_t	LUT338H;
	volatile	uint32_t	LUT339L;
	volatile	uint32_t	LUT339H;
	volatile	uint32_t	LUT340L;
	volatile	uint32_t	LUT340H;
	volatile	uint32_t	LUT341L;
	volatile	uint32_t	LUT341H;
	volatile	uint32_t	LUT342L;
	volatile	uint32_t	LUT342H;
	volatile	uint32_t	LUT343L;
	volatile	uint32_t	LUT343H;
	volatile	uint32_t	LUT344L;
	volatile	uint32_t	LUT344H;
	volatile	uint32_t	LUT345L;
	volatile	uint32_t	LUT345H;
	volatile	uint32_t	LUT346L;
	volatile	uint32_t	LUT346H;
	volatile	uint32_t	LUT347L;
	volatile	uint32_t	LUT347H;
	volatile	uint32_t	LUT348L;
	volatile	uint32_t	LUT348H;
	volatile	uint32_t	LUT349L;
	volatile	uint32_t	LUT349H;
	volatile	uint32_t	LUT350L;
	volatile	uint32_t	LUT350H;
	volatile	uint32_t	LUT351L;
	volatile	uint32_t	LUT351H;
	volatile	uint32_t	LUT352L;
	volatile	uint32_t	LUT352H;
	volatile	uint32_t	LUT353L;
	volatile	uint32_t	LUT353H;
	volatile	uint32_t	LUT354L;
	volatile	uint32_t	LUT354H;
	volatile	uint32_t	LUT355L;
	volatile	uint32_t	LUT355H;
	volatile	uint32_t	LUT356L;
	volatile	uint32_t	LUT356H;
	volatile	uint32_t	LUT357L;
	volatile	uint32_t	LUT357H;
	volatile	uint32_t	LUT358L;
	volatile	uint32_t	LUT358H;
	volatile	uint32_t	LUT359L;
	volatile	uint32_t	LUT359H;
	volatile	uint32_t	LUT360L;
	volatile	uint32_t	LUT360H;
	volatile	uint32_t	LUT361L;
	volatile	uint32_t	LUT361H;
	volatile	uint32_t	LUT362L;
	volatile	uint32_t	LUT362H;
	volatile	uint32_t	LUT363L;
	volatile	uint32_t	LUT363H;
	volatile	uint32_t	LUT364L;
	volatile	uint32_t	LUT364H;
	volatile	uint32_t	LUT365L;
	volatile	uint32_t	LUT365H;
	volatile	uint32_t	LUT366L;
	volatile	uint32_t	LUT366H;
	volatile	uint32_t	LUT367L;
	volatile	uint32_t	LUT367H;
	volatile	uint32_t	LUT368L;
	volatile	uint32_t	LUT368H;
	volatile	uint32_t	LUT369L;
	volatile	uint32_t	LUT369H;
	volatile	uint32_t	LUT370L;
	volatile	uint32_t	LUT370H;
	volatile	uint32_t	LUT371L;
	volatile	uint32_t	LUT371H;
	volatile	uint32_t	LUT372L;
	volatile	uint32_t	LUT372H;
	volatile	uint32_t	LUT373L;
	volatile	uint32_t	LUT373H;
	volatile	uint32_t	LUT374L;
	volatile	uint32_t	LUT374H;
	volatile	uint32_t	LUT375L;
	volatile	uint32_t	LUT375H;
	volatile	uint32_t	LUT376L;
	volatile	uint32_t	LUT376H;
	volatile	uint32_t	LUT377L;
	volatile	uint32_t	LUT377H;
	volatile	uint32_t	LUT378L;
	volatile	uint32_t	LUT378H;
	volatile	uint32_t	LUT379L;
	volatile	uint32_t	LUT379H;
	volatile	uint32_t	LUT380L;
	volatile	uint32_t	LUT380H;
	volatile	uint32_t	LUT381L;
	volatile	uint32_t	LUT381H;
	volatile	uint32_t	LUT382L;
	volatile	uint32_t	LUT382H;
	volatile	uint32_t	LUT383L;
	volatile	uint32_t	LUT383H;
	volatile	uint32_t	LUT384L;
	volatile	uint32_t	LUT384H;
	volatile	uint32_t	LUT385L;
	volatile	uint32_t	LUT385H;
	volatile	uint32_t	LUT386L;
	volatile	uint32_t	LUT386H;
	volatile	uint32_t	LUT387L;
	volatile	uint32_t	LUT387H;
	volatile	uint32_t	LUT388L;
	volatile	uint32_t	LUT388H;
	volatile	uint32_t	LUT389L;
	volatile	uint32_t	LUT389H;
	volatile	uint32_t	LUT390L;
	volatile	uint32_t	LUT390H;
	volatile	uint32_t	LUT391L;
	volatile	uint32_t	LUT391H;
	volatile	uint32_t	LUT392L;
	volatile	uint32_t	LUT392H;
	volatile	uint32_t	LUT393L;
	volatile	uint32_t	LUT393H;
	volatile	uint32_t	LUT394L;
	volatile	uint32_t	LUT394H;
	volatile	uint32_t	LUT395L;
	volatile	uint32_t	LUT395H;
	volatile	uint32_t	LUT396L;
	volatile	uint32_t	LUT396H;
	volatile	uint32_t	LUT397L;
	volatile	uint32_t	LUT397H;
	volatile	uint32_t	LUT398L;
	volatile	uint32_t	LUT398H;
	volatile	uint32_t	LUT399L;
	volatile	uint32_t	LUT399H;
	volatile	uint32_t	LUT400L;
	volatile	uint32_t	LUT400H;
	volatile	uint32_t	LUT401L;
	volatile	uint32_t	LUT401H;
	volatile	uint32_t	LUT402L;
	volatile	uint32_t	LUT402H;
	volatile	uint32_t	LUT403L;
	volatile	uint32_t	LUT403H;
	volatile	uint32_t	LUT404L;
	volatile	uint32_t	LUT404H;
	volatile	uint32_t	LUT405L;
	volatile	uint32_t	LUT405H;
	volatile	uint32_t	LUT406L;
	volatile	uint32_t	LUT406H;
	volatile	uint32_t	LUT407L;
	volatile	uint32_t	LUT407H;
	volatile	uint32_t	LUT408L;
	volatile	uint32_t	LUT408H;
	volatile	uint32_t	LUT409L;
	volatile	uint32_t	LUT409H;
	volatile	uint32_t	LUT410L;
	volatile	uint32_t	LUT410H;
	volatile	uint32_t	LUT411L;
	volatile	uint32_t	LUT411H;
	volatile	uint32_t	LUT412L;
	volatile	uint32_t	LUT412H;
	volatile	uint32_t	LUT413L;
	volatile	uint32_t	LUT413H;
	volatile	uint32_t	LUT414L;
	volatile	uint32_t	LUT414H;
	volatile	uint32_t	LUT415L;
	volatile	uint32_t	LUT415H;
	volatile	uint32_t	LUT416L;
	volatile	uint32_t	LUT416H;
	volatile	uint32_t	LUT417L;
	volatile	uint32_t	LUT417H;
	volatile	uint32_t	LUT418L;
	volatile	uint32_t	LUT418H;
	volatile	uint32_t	LUT419L;
	volatile	uint32_t	LUT419H;
	volatile	uint32_t	LUT420L;
	volatile	uint32_t	LUT420H;
	volatile	uint32_t	LUT421L;
	volatile	uint32_t	LUT421H;
	volatile	uint32_t	LUT422L;
	volatile	uint32_t	LUT422H;
	volatile	uint32_t	LUT423L;
	volatile	uint32_t	LUT423H;
	volatile	uint32_t	LUT424L;
	volatile	uint32_t	LUT424H;
	volatile	uint32_t	LUT425L;
	volatile	uint32_t	LUT425H;
	volatile	uint32_t	LUT426L;
	volatile	uint32_t	LUT426H;
	volatile	uint32_t	LUT427L;
	volatile	uint32_t	LUT427H;
	volatile	uint32_t	LUT428L;
	volatile	uint32_t	LUT428H;
	volatile	uint32_t	LUT429L;
	volatile	uint32_t	LUT429H;
	volatile	uint32_t	LUT430L;
	volatile	uint32_t	LUT430H;
	volatile	uint32_t	LUT431L;
	volatile	uint32_t	LUT431H;
	volatile	uint32_t	LUT432L;
	volatile	uint32_t	LUT432H;
	volatile	uint32_t	LUT433L;
	volatile	uint32_t	LUT433H;
	volatile	uint32_t	LUT434L;
	volatile	uint32_t	LUT434H;
	volatile	uint32_t	LUT435L;
	volatile	uint32_t	LUT435H;
	volatile	uint32_t	LUT436L;
	volatile	uint32_t	LUT436H;
	volatile	uint32_t	LUT437L;
	volatile	uint32_t	LUT437H;
	volatile	uint32_t	LUT438L;
	volatile	uint32_t	LUT438H;
	volatile	uint32_t	LUT439L;
	volatile	uint32_t	LUT439H;
	volatile	uint32_t	LUT440L;
	volatile	uint32_t	LUT440H;
	volatile	uint32_t	LUT441L;
	volatile	uint32_t	LUT441H;
	volatile	uint32_t	LUT442L;
	volatile	uint32_t	LUT442H;
	volatile	uint32_t	LUT443L;
	volatile	uint32_t	LUT443H;
	volatile	uint32_t	LUT444L;
	volatile	uint32_t	LUT444H;
	volatile	uint32_t	LUT445L;
	volatile	uint32_t	LUT445H;
	volatile	uint32_t	LUT446L;
	volatile	uint32_t	LUT446H;
	volatile	uint32_t	LUT447L;
	volatile	uint32_t	LUT447H;
	volatile	uint32_t	LUT448L;
	volatile	uint32_t	LUT448H;
	volatile	uint32_t	LUT449L;
	volatile	uint32_t	LUT449H;
	volatile	uint32_t	LUT450L;
	volatile	uint32_t	LUT450H;
	volatile	uint32_t	LUT451L;
	volatile	uint32_t	LUT451H;
	volatile	uint32_t	LUT452L;
	volatile	uint32_t	LUT452H;
	volatile	uint32_t	LUT453L;
	volatile	uint32_t	LUT453H;
	volatile	uint32_t	LUT454L;
	volatile	uint32_t	LUT454H;
	volatile	uint32_t	LUT455L;
	volatile	uint32_t	LUT455H;
	volatile	uint32_t	LUT456L;
	volatile	uint32_t	LUT456H;
	volatile	uint32_t	LUT457L;
	volatile	uint32_t	LUT457H;
	volatile	uint32_t	LUT458L;
	volatile	uint32_t	LUT458H;
	volatile	uint32_t	LUT459L;
	volatile	uint32_t	LUT459H;
	volatile	uint32_t	LUT460L;
	volatile	uint32_t	LUT460H;
	volatile	uint32_t	LUT461L;
	volatile	uint32_t	LUT461H;
	volatile	uint32_t	LUT462L;
	volatile	uint32_t	LUT462H;
	volatile	uint32_t	LUT463L;
	volatile	uint32_t	LUT463H;
	volatile	uint32_t	LUT464L;
	volatile	uint32_t	LUT464H;
	volatile	uint32_t	LUT465L;
	volatile	uint32_t	LUT465H;
	volatile	uint32_t	LUT466L;
	volatile	uint32_t	LUT466H;
	volatile	uint32_t	LUT467L;
	volatile	uint32_t	LUT467H;
	volatile	uint32_t	LUT468L;
	volatile	uint32_t	LUT468H;
	volatile	uint32_t	LUT469L;
	volatile	uint32_t	LUT469H;
	volatile	uint32_t	LUT470L;
	volatile	uint32_t	LUT470H;
	volatile	uint32_t	LUT471L;
	volatile	uint32_t	LUT471H;
	volatile	uint32_t	LUT472L;
	volatile	uint32_t	LUT472H;
	volatile	uint32_t	LUT473L;
	volatile	uint32_t	LUT473H;
	volatile	uint32_t	LUT474L;
	volatile	uint32_t	LUT474H;
	volatile	uint32_t	LUT475L;
	volatile	uint32_t	LUT475H;
	volatile	uint32_t	LUT476L;
	volatile	uint32_t	LUT476H;
	volatile	uint32_t	LUT477L;
	volatile	uint32_t	LUT477H;
	volatile	uint32_t	LUT478L;
	volatile	uint32_t	LUT478H;
	volatile	uint32_t	LUT479L;
	volatile	uint32_t	LUT479H;
	volatile	uint32_t	LUT480L;
	volatile	uint32_t	LUT480H;
	volatile	uint32_t	LUT481L;
	volatile	uint32_t	LUT481H;
	volatile	uint32_t	LUT482L;
	volatile	uint32_t	LUT482H;
	volatile	uint32_t	LUT483L;
	volatile	uint32_t	LUT483H;
	volatile	uint32_t	LUT484L;
	volatile	uint32_t	LUT484H;
	volatile	uint32_t	LUT485L;
	volatile	uint32_t	LUT485H;
	volatile	uint32_t	LUT486L;
	volatile	uint32_t	LUT486H;
	volatile	uint32_t	LUT487L;
	volatile	uint32_t	LUT487H;
	volatile	uint32_t	LUT488L;
	volatile	uint32_t	LUT488H;
	volatile	uint32_t	LUT489L;
	volatile	uint32_t	LUT489H;
	volatile	uint32_t	LUT490L;
	volatile	uint32_t	LUT490H;
	volatile	uint32_t	LUT491L;
	volatile	uint32_t	LUT491H;
	volatile	uint32_t	LUT492L;
	volatile	uint32_t	LUT492H;
	volatile	uint32_t	LUT493L;
	volatile	uint32_t	LUT493H;
	volatile	uint32_t	LUT494L;
	volatile	uint32_t	LUT494H;
	volatile	uint32_t	LUT495L;
	volatile	uint32_t	LUT495H;
	volatile	uint32_t	LUT496L;
	volatile	uint32_t	LUT496H;
	volatile	uint32_t	LUT497L;
	volatile	uint32_t	LUT497H;
	volatile	uint32_t	LUT498L;
	volatile	uint32_t	LUT498H;
	volatile	uint32_t	LUT499L;
	volatile	uint32_t	LUT499H;
	volatile	uint32_t	LUT500L;
	volatile	uint32_t	LUT500H;
	volatile	uint32_t	LUT501L;
	volatile	uint32_t	LUT501H;
	volatile	uint32_t	LUT502L;
	volatile	uint32_t	LUT502H;
	volatile	uint32_t	LUT503L;
	volatile	uint32_t	LUT503H;
	volatile	uint32_t	LUT504L;
	volatile	uint32_t	LUT504H;
	volatile	uint32_t	LUT505L;
	volatile	uint32_t	LUT505H;
	volatile	uint32_t	LUT506L;
	volatile	uint32_t	LUT506H;
	volatile	uint32_t	LUT507L;
	volatile	uint32_t	LUT507H;
	volatile	uint32_t	LUT508L;
	volatile	uint32_t	LUT508H;
	volatile	uint32_t	LUT509L;
	volatile	uint32_t	LUT509H;
	volatile	uint32_t	LUT510L;
	volatile	uint32_t	LUT510H;
	volatile	uint32_t	LUT511L;
	volatile	uint32_t	LUT511H;
	volatile	uint32_t	LUT512L;
	volatile	uint32_t	LUT512H;
	volatile	uint32_t	LUT513L;
	volatile	uint32_t	LUT513H;
	volatile	uint32_t	LUT514L;
	volatile	uint32_t	LUT514H;
	volatile	uint32_t	LUT515L;
	volatile	uint32_t	LUT515H;
	volatile	uint32_t	LUT516L;
	volatile	uint32_t	LUT516H;
	volatile	uint32_t	LUT517L;
	volatile	uint32_t	LUT517H;
	volatile	uint32_t	LUT518L;
	volatile	uint32_t	LUT518H;
	volatile	uint32_t	LUT519L;
	volatile	uint32_t	LUT519H;
	volatile	uint32_t	LUT520L;
	volatile	uint32_t	LUT520H;
	volatile	uint32_t	LUT521L;
	volatile	uint32_t	LUT521H;
	volatile	uint32_t	LUT522L;
	volatile	uint32_t	LUT522H;
	volatile	uint32_t	LUT523L;
	volatile	uint32_t	LUT523H;
	volatile	uint32_t	LUT524L;
	volatile	uint32_t	LUT524H;
	volatile	uint32_t	LUT525L;
	volatile	uint32_t	LUT525H;
	volatile	uint32_t	LUT526L;
	volatile	uint32_t	LUT526H;
	volatile	uint32_t	LUT527L;
	volatile	uint32_t	LUT527H;
	volatile	uint32_t	LUT528L;
	volatile	uint32_t	LUT528H;
	volatile	uint32_t	LUT529L;
	volatile	uint32_t	LUT529H;
	volatile	uint32_t	LUT530L;
	volatile	uint32_t	LUT530H;
	volatile	uint32_t	LUT531L;
	volatile	uint32_t	LUT531H;
	volatile	uint32_t	LUT532L;
	volatile	uint32_t	LUT532H;
	volatile	uint32_t	LUT533L;
	volatile	uint32_t	LUT533H;
	volatile	uint32_t	LUT534L;
	volatile	uint32_t	LUT534H;
	volatile	uint32_t	LUT535L;
	volatile	uint32_t	LUT535H;
	volatile	uint32_t	LUT536L;
	volatile	uint32_t	LUT536H;
	volatile	uint32_t	LUT537L;
	volatile	uint32_t	LUT537H;
	volatile	uint32_t	LUT538L;
	volatile	uint32_t	LUT538H;
	volatile	uint32_t	LUT539L;
	volatile	uint32_t	LUT539H;
	volatile	uint32_t	LUT540L;
	volatile	uint32_t	LUT540H;
	volatile	uint32_t	LUT541L;
	volatile	uint32_t	LUT541H;
	volatile	uint32_t	LUT542L;
	volatile	uint32_t	LUT542H;
	volatile	uint32_t	LUT543L;
	volatile	uint32_t	LUT543H;
	volatile	uint32_t	LUT544L;
	volatile	uint32_t	LUT544H;
	volatile	uint32_t	LUT545L;
	volatile	uint32_t	LUT545H;
	volatile	uint32_t	LUT546L;
	volatile	uint32_t	LUT546H;
	volatile	uint32_t	LUT547L;
	volatile	uint32_t	LUT547H;
	volatile	uint32_t	LUT548L;
	volatile	uint32_t	LUT548H;
	volatile	uint32_t	LUT549L;
	volatile	uint32_t	LUT549H;
	volatile	uint32_t	LUT550L;
	volatile	uint32_t	LUT550H;
	volatile	uint32_t	LUT551L;
	volatile	uint32_t	LUT551H;
	volatile	uint32_t	LUT552L;
	volatile	uint32_t	LUT552H;
	volatile	uint32_t	LUT553L;
	volatile	uint32_t	LUT553H;
	volatile	uint32_t	LUT554L;
	volatile	uint32_t	LUT554H;
	volatile	uint32_t	LUT555L;
	volatile	uint32_t	LUT555H;
	volatile	uint32_t	LUT556L;
	volatile	uint32_t	LUT556H;
	volatile	uint32_t	LUT557L;
	volatile	uint32_t	LUT557H;
	volatile	uint32_t	LUT558L;
	volatile	uint32_t	LUT558H;
	volatile	uint32_t	LUT559L;
	volatile	uint32_t	LUT559H;
	volatile	uint32_t	LUT560L;
	volatile	uint32_t	LUT560H;
	volatile	uint32_t	LUT561L;
	volatile	uint32_t	LUT561H;
	volatile	uint32_t	LUT562L;
	volatile	uint32_t	LUT562H;
	volatile	uint32_t	LUT563L;
	volatile	uint32_t	LUT563H;
	volatile	uint32_t	LUT564L;
	volatile	uint32_t	LUT564H;
	volatile	uint32_t	LUT565L;
	volatile	uint32_t	LUT565H;
	volatile	uint32_t	LUT566L;
	volatile	uint32_t	LUT566H;
	volatile	uint32_t	LUT567L;
	volatile	uint32_t	LUT567H;
	volatile	uint32_t	LUT568L;
	volatile	uint32_t	LUT568H;
	volatile	uint32_t	LUT569L;
	volatile	uint32_t	LUT569H;
	volatile	uint32_t	LUT570L;
	volatile	uint32_t	LUT570H;
	volatile	uint32_t	LUT571L;
	volatile	uint32_t	LUT571H;
	volatile	uint32_t	LUT572L;
	volatile	uint32_t	LUT572H;
	volatile	uint32_t	LUT573L;
	volatile	uint32_t	LUT573H;
	volatile	uint32_t	LUT574L;
	volatile	uint32_t	LUT574H;
	volatile	uint32_t	LUT575L;
	volatile	uint32_t	LUT575H;
	volatile	uint32_t	LUT576L;
	volatile	uint32_t	LUT576H;
	volatile	uint32_t	LUT577L;
	volatile	uint32_t	LUT577H;
	volatile	uint32_t	LUT578L;
	volatile	uint32_t	LUT578H;
	volatile	uint32_t	LUT579L;
	volatile	uint32_t	LUT579H;
	volatile	uint32_t	LUT580L;
	volatile	uint32_t	LUT580H;
	volatile	uint32_t	LUT581L;
	volatile	uint32_t	LUT581H;
	volatile	uint32_t	LUT582L;
	volatile	uint32_t	LUT582H;
	volatile	uint32_t	LUT583L;
	volatile	uint32_t	LUT583H;
	volatile	uint32_t	LUT584L;
	volatile	uint32_t	LUT584H;
	volatile	uint32_t	LUT585L;
	volatile	uint32_t	LUT585H;
	volatile	uint32_t	LUT586L;
	volatile	uint32_t	LUT586H;
	volatile	uint32_t	LUT587L;
	volatile	uint32_t	LUT587H;
	volatile	uint32_t	LUT588L;
	volatile	uint32_t	LUT588H;
	volatile	uint32_t	LUT589L;
	volatile	uint32_t	LUT589H;
	volatile	uint32_t	LUT590L;
	volatile	uint32_t	LUT590H;
	volatile	uint32_t	LUT591L;
	volatile	uint32_t	LUT591H;
	volatile	uint32_t	LUT592L;
	volatile	uint32_t	LUT592H;
	volatile	uint32_t	LUT593L;
	volatile	uint32_t	LUT593H;
	volatile	uint32_t	LUT594L;
	volatile	uint32_t	LUT594H;
	volatile	uint32_t	LUT595L;
	volatile	uint32_t	LUT595H;
	volatile	uint32_t	LUT596L;
	volatile	uint32_t	LUT596H;
	volatile	uint32_t	LUT597L;
	volatile	uint32_t	LUT597H;
	volatile	uint32_t	LUT598L;
	volatile	uint32_t	LUT598H;
	volatile	uint32_t	LUT599L;
	volatile	uint32_t	LUT599H;
	volatile	uint32_t	LUT600L;
	volatile	uint32_t	LUT600H;
	volatile	uint32_t	LUT601L;
	volatile	uint32_t	LUT601H;
	volatile	uint32_t	LUT602L;
	volatile	uint32_t	LUT602H;
	volatile	uint32_t	LUT603L;
	volatile	uint32_t	LUT603H;
	volatile	uint32_t	LUT604L;
	volatile	uint32_t	LUT604H;
	volatile	uint32_t	LUT605L;
	volatile	uint32_t	LUT605H;
	volatile	uint32_t	LUT606L;
	volatile	uint32_t	LUT606H;
	volatile	uint32_t	LUT607L;
	volatile	uint32_t	LUT607H;
	volatile	uint32_t	LUT608L;
	volatile	uint32_t	LUT608H;
	volatile	uint32_t	LUT609L;
	volatile	uint32_t	LUT609H;
	volatile	uint32_t	LUT610L;
	volatile	uint32_t	LUT610H;
	volatile	uint32_t	LUT611L;
	volatile	uint32_t	LUT611H;
	volatile	uint32_t	LUT612L;
	volatile	uint32_t	LUT612H;
	volatile	uint32_t	LUT613L;
	volatile	uint32_t	LUT613H;
	volatile	uint32_t	LUT614L;
	volatile	uint32_t	LUT614H;
	volatile	uint32_t	LUT615L;
	volatile	uint32_t	LUT615H;
	volatile	uint32_t	LUT616L;
	volatile	uint32_t	LUT616H;
	volatile	uint32_t	LUT617L;
	volatile	uint32_t	LUT617H;
	volatile	uint32_t	LUT618L;
	volatile	uint32_t	LUT618H;
	volatile	uint32_t	LUT619L;
	volatile	uint32_t	LUT619H;
	volatile	uint32_t	LUT620L;
	volatile	uint32_t	LUT620H;
	volatile	uint32_t	LUT621L;
	volatile	uint32_t	LUT621H;
	volatile	uint32_t	LUT622L;
	volatile	uint32_t	LUT622H;
	volatile	uint32_t	LUT623L;
	volatile	uint32_t	LUT623H;
	volatile	uint32_t	LUT624L;
	volatile	uint32_t	LUT624H;
	volatile	uint32_t	LUT625L;
	volatile	uint32_t	LUT625H;
	volatile	uint32_t	LUT626L;
	volatile	uint32_t	LUT626H;
	volatile	uint32_t	LUT627L;
	volatile	uint32_t	LUT627H;
	volatile	uint32_t	LUT628L;
	volatile	uint32_t	LUT628H;
	volatile	uint32_t	LUT629L;
	volatile	uint32_t	LUT629H;
	volatile	uint32_t	LUT630L;
	volatile	uint32_t	LUT630H;
	volatile	uint32_t	LUT631L;
	volatile	uint32_t	LUT631H;
	volatile	uint32_t	LUT632L;
	volatile	uint32_t	LUT632H;
	volatile	uint32_t	LUT633L;
	volatile	uint32_t	LUT633H;
	volatile	uint32_t	LUT634L;
	volatile	uint32_t	LUT634H;
	volatile	uint32_t	LUT635L;
	volatile	uint32_t	LUT635H;
	volatile	uint32_t	LUT636L;
	volatile	uint32_t	LUT636H;
	volatile	uint32_t	LUT637L;
	volatile	uint32_t	LUT637H;
	volatile	uint32_t	LUT638L;
	volatile	uint32_t	LUT638H;
	volatile	uint32_t	LUT639L;
	volatile	uint32_t	LUT639H;
	volatile	uint32_t	LUT640L;
	volatile	uint32_t	LUT640H;
	volatile	uint32_t	LUT641L;
	volatile	uint32_t	LUT641H;
	volatile	uint32_t	LUT642L;
	volatile	uint32_t	LUT642H;
	volatile	uint32_t	LUT643L;
	volatile	uint32_t	LUT643H;
	volatile	uint32_t	LUT644L;
	volatile	uint32_t	LUT644H;
	volatile	uint32_t	LUT645L;
	volatile	uint32_t	LUT645H;
	volatile	uint32_t	LUT646L;
	volatile	uint32_t	LUT646H;
	volatile	uint32_t	LUT647L;
	volatile	uint32_t	LUT647H;
	volatile	uint32_t	LUT648L;
	volatile	uint32_t	LUT648H;
	volatile	uint32_t	LUT649L;
	volatile	uint32_t	LUT649H;
	volatile	uint32_t	LUT650L;
	volatile	uint32_t	LUT650H;
	volatile	uint32_t	LUT651L;
	volatile	uint32_t	LUT651H;
	volatile	uint32_t	LUT652L;
	volatile	uint32_t	LUT652H;
	volatile	uint32_t	LUT653L;
	volatile	uint32_t	LUT653H;
	volatile	uint32_t	LUT654L;
	volatile	uint32_t	LUT654H;
	volatile	uint32_t	LUT655L;
	volatile	uint32_t	LUT655H;
	volatile	uint32_t	LUT656L;
	volatile	uint32_t	LUT656H;
	volatile	uint32_t	LUT657L;
	volatile	uint32_t	LUT657H;
	volatile	uint32_t	LUT658L;
	volatile	uint32_t	LUT658H;
	volatile	uint32_t	LUT659L;
	volatile	uint32_t	LUT659H;
	volatile	uint32_t	LUT660L;
	volatile	uint32_t	LUT660H;
	volatile	uint32_t	LUT661L;
	volatile	uint32_t	LUT661H;
	volatile	uint32_t	LUT662L;
	volatile	uint32_t	LUT662H;
	volatile	uint32_t	LUT663L;
	volatile	uint32_t	LUT663H;
	volatile	uint32_t	LUT664L;
	volatile	uint32_t	LUT664H;
	volatile	uint32_t	LUT665L;
	volatile	uint32_t	LUT665H;
	volatile	uint32_t	LUT666L;
	volatile	uint32_t	LUT666H;
	volatile	uint32_t	LUT667L;
	volatile	uint32_t	LUT667H;
	volatile	uint32_t	LUT668L;
	volatile	uint32_t	LUT668H;
	volatile	uint32_t	LUT669L;
	volatile	uint32_t	LUT669H;
	volatile	uint32_t	LUT670L;
	volatile	uint32_t	LUT670H;
	volatile	uint32_t	LUT671L;
	volatile	uint32_t	LUT671H;
	volatile	uint32_t	LUT672L;
	volatile	uint32_t	LUT672H;
	volatile	uint32_t	LUT673L;
	volatile	uint32_t	LUT673H;
	volatile	uint32_t	LUT674L;
	volatile	uint32_t	LUT674H;
	volatile	uint32_t	LUT675L;
	volatile	uint32_t	LUT675H;
	volatile	uint32_t	LUT676L;
	volatile	uint32_t	LUT676H;
	volatile	uint32_t	LUT677L;
	volatile	uint32_t	LUT677H;
	volatile	uint32_t	LUT678L;
	volatile	uint32_t	LUT678H;
	volatile	uint32_t	LUT679L;
	volatile	uint32_t	LUT679H;
	volatile	uint32_t	LUT680L;
	volatile	uint32_t	LUT680H;
	volatile	uint32_t	LUT681L;
	volatile	uint32_t	LUT681H;
	volatile	uint32_t	LUT682L;
	volatile	uint32_t	LUT682H;
	volatile	uint32_t	LUT683L;
	volatile	uint32_t	LUT683H;
	volatile	uint32_t	LUT684L;
	volatile	uint32_t	LUT684H;
	volatile	uint32_t	LUT685L;
	volatile	uint32_t	LUT685H;
	volatile	uint32_t	LUT686L;
	volatile	uint32_t	LUT686H;
	volatile	uint32_t	LUT687L;
	volatile	uint32_t	LUT687H;
	volatile	uint32_t	LUT688L;
	volatile	uint32_t	LUT688H;
	volatile	uint32_t	LUT689L;
	volatile	uint32_t	LUT689H;
	volatile	uint32_t	LUT690L;
	volatile	uint32_t	LUT690H;
	volatile	uint32_t	LUT691L;
	volatile	uint32_t	LUT691H;
	volatile	uint32_t	LUT692L;
	volatile	uint32_t	LUT692H;
	volatile	uint32_t	LUT693L;
	volatile	uint32_t	LUT693H;
	volatile	uint32_t	LUT694L;
	volatile	uint32_t	LUT694H;
	volatile	uint32_t	LUT695L;
	volatile	uint32_t	LUT695H;
	volatile	uint32_t	LUT696L;
	volatile	uint32_t	LUT696H;
	volatile	uint32_t	LUT697L;
	volatile	uint32_t	LUT697H;
	volatile	uint32_t	LUT698L;
	volatile	uint32_t	LUT698H;
	volatile	uint32_t	LUT699L;
	volatile	uint32_t	LUT699H;
	volatile	uint32_t	LUT700L;
	volatile	uint32_t	LUT700H;
	volatile	uint32_t	LUT701L;
	volatile	uint32_t	LUT701H;
	volatile	uint32_t	LUT702L;
	volatile	uint32_t	LUT702H;
	volatile	uint32_t	LUT703L;
	volatile	uint32_t	LUT703H;
	volatile	uint32_t	LUT704L;
	volatile	uint32_t	LUT704H;
	volatile	uint32_t	LUT705L;
	volatile	uint32_t	LUT705H;
	volatile	uint32_t	LUT706L;
	volatile	uint32_t	LUT706H;
	volatile	uint32_t	LUT707L;
	volatile	uint32_t	LUT707H;
	volatile	uint32_t	LUT708L;
	volatile	uint32_t	LUT708H;
	volatile	uint32_t	LUT709L;
	volatile	uint32_t	LUT709H;
	volatile	uint32_t	LUT710L;
	volatile	uint32_t	LUT710H;
	volatile	uint32_t	LUT711L;
	volatile	uint32_t	LUT711H;
	volatile	uint32_t	LUT712L;
	volatile	uint32_t	LUT712H;
	volatile	uint32_t	LUT713L;
	volatile	uint32_t	LUT713H;
	volatile	uint32_t	LUT714L;
	volatile	uint32_t	LUT714H;
	volatile	uint32_t	LUT715L;
	volatile	uint32_t	LUT715H;
	volatile	uint32_t	LUT716L;
	volatile	uint32_t	LUT716H;
	volatile	uint32_t	LUT717L;
	volatile	uint32_t	LUT717H;
	volatile	uint32_t	LUT718L;
	volatile	uint32_t	LUT718H;
	volatile	uint32_t	LUT719L;
	volatile	uint32_t	LUT719H;
	volatile	uint32_t	LUT720L;
	volatile	uint32_t	LUT720H;
	volatile	uint32_t	LUT721L;
	volatile	uint32_t	LUT721H;
	volatile	uint32_t	LUT722L;
	volatile	uint32_t	LUT722H;
	volatile	uint32_t	LUT723L;
	volatile	uint32_t	LUT723H;
	volatile	uint32_t	LUT724L;
	volatile	uint32_t	LUT724H;
	volatile	uint32_t	LUT725L;
	volatile	uint32_t	LUT725H;
	volatile	uint32_t	LUT726L;
	volatile	uint32_t	LUT726H;
	volatile	uint32_t	LUT727L;
	volatile	uint32_t	LUT727H;
	volatile	uint32_t	LUT728L;
	volatile	uint32_t	LUT728H;
	volatile	uint32_t	LUT729L;
	volatile	uint32_t	LUT729H;
	volatile	uint32_t	LUT730L;
	volatile	uint32_t	LUT730H;
	volatile	uint32_t	LUT731L;
	volatile	uint32_t	LUT731H;
	volatile	uint32_t	LUT732L;
	volatile	uint32_t	LUT732H;
	volatile	uint32_t	LUT733L;
	volatile	uint32_t	LUT733H;
	volatile	uint32_t	LUT734L;
	volatile	uint32_t	LUT734H;
	volatile	uint32_t	LUT735L;
	volatile	uint32_t	LUT735H;
	volatile	uint32_t	LUT736L;
	volatile	uint32_t	LUT736H;
	volatile	uint32_t	LUT737L;
	volatile	uint32_t	LUT737H;
	volatile	uint32_t	LUT738L;
	volatile	uint32_t	LUT738H;
	volatile	uint32_t	LUT739L;
	volatile	uint32_t	LUT739H;
	volatile	uint32_t	LUT740L;
	volatile	uint32_t	LUT740H;
	volatile	uint32_t	LUT741L;
	volatile	uint32_t	LUT741H;
	volatile	uint32_t	LUT742L;
	volatile	uint32_t	LUT742H;
	volatile	uint32_t	LUT743L;
	volatile	uint32_t	LUT743H;
	volatile	uint32_t	LUT744L;
	volatile	uint32_t	LUT744H;
	volatile	uint32_t	LUT745L;
	volatile	uint32_t	LUT745H;
	volatile	uint32_t	LUT746L;
	volatile	uint32_t	LUT746H;
	volatile	uint32_t	LUT747L;
	volatile	uint32_t	LUT747H;
	volatile	uint32_t	LUT748L;
	volatile	uint32_t	LUT748H;
	volatile	uint32_t	LUT749L;
	volatile	uint32_t	LUT749H;
	volatile	uint32_t	LUT750L;
	volatile	uint32_t	LUT750H;
	volatile	uint32_t	LUT751L;
	volatile	uint32_t	LUT751H;
	volatile	uint32_t	LUT752L;
	volatile	uint32_t	LUT752H;
	volatile	uint32_t	LUT753L;
	volatile	uint32_t	LUT753H;
	volatile	uint32_t	LUT754L;
	volatile	uint32_t	LUT754H;
	volatile	uint32_t	LUT755L;
	volatile	uint32_t	LUT755H;
	volatile	uint32_t	LUT756L;
	volatile	uint32_t	LUT756H;
	volatile	uint32_t	LUT757L;
	volatile	uint32_t	LUT757H;
	volatile	uint32_t	LUT758L;
	volatile	uint32_t	LUT758H;
	volatile	uint32_t	LUT759L;
	volatile	uint32_t	LUT759H;
	volatile	uint32_t	LUT760L;
	volatile	uint32_t	LUT760H;
	volatile	uint32_t	LUT761L;
	volatile	uint32_t	LUT761H;
	volatile	uint32_t	LUT762L;
	volatile	uint32_t	LUT762H;
	volatile	uint32_t	LUT763L;
	volatile	uint32_t	LUT763H;
	volatile	uint32_t	LUT764L;
	volatile	uint32_t	LUT764H;
	volatile	uint32_t	LUT765L;
	volatile	uint32_t	LUT765H;
	volatile	uint32_t	LUT766L;
	volatile	uint32_t	LUT766H;
	volatile	uint32_t	LUT767L;
	volatile	uint32_t	LUT767H;
	volatile	uint32_t	LUT768L;
	volatile	uint32_t	LUT768H;
	volatile	uint32_t	LUT769L;
	volatile	uint32_t	LUT769H;
	volatile	uint32_t	LUT770L;
	volatile	uint32_t	LUT770H;
	volatile	uint32_t	LUT771L;
	volatile	uint32_t	LUT771H;
	volatile	uint32_t	LUT772L;
	volatile	uint32_t	LUT772H;
	volatile	uint32_t	LUT773L;
	volatile	uint32_t	LUT773H;
	volatile	uint32_t	LUT774L;
	volatile	uint32_t	LUT774H;
	volatile	uint32_t	LUT775L;
	volatile	uint32_t	LUT775H;
	volatile	uint32_t	LUT776L;
	volatile	uint32_t	LUT776H;
	volatile	uint32_t	LUT777L;
	volatile	uint32_t	LUT777H;
	volatile	uint32_t	LUT778L;
	volatile	uint32_t	LUT778H;
	volatile	uint32_t	LUT779L;
	volatile	uint32_t	LUT779H;
	volatile	uint32_t	LUT780L;
	volatile	uint32_t	LUT780H;
	volatile	uint32_t	LUT781L;
	volatile	uint32_t	LUT781H;
	volatile	uint32_t	LUT782L;
	volatile	uint32_t	LUT782H;
	volatile	uint32_t	LUT783L;
	volatile	uint32_t	LUT783H;
	volatile	uint32_t	LUT784L;
	volatile	uint32_t	LUT784H;
	volatile	uint32_t	LUT785L;
	volatile	uint32_t	LUT785H;
	volatile	uint32_t	LUT786L;
	volatile	uint32_t	LUT786H;
	volatile	uint32_t	LUT787L;
	volatile	uint32_t	LUT787H;
	volatile	uint32_t	LUT788L;
	volatile	uint32_t	LUT788H;
	volatile	uint32_t	LUT789L;
	volatile	uint32_t	LUT789H;
	volatile	uint32_t	LUT790L;
	volatile	uint32_t	LUT790H;
	volatile	uint32_t	LUT791L;
	volatile	uint32_t	LUT791H;
	volatile	uint32_t	LUT792L;
	volatile	uint32_t	LUT792H;
	volatile	uint32_t	LUT793L;
	volatile	uint32_t	LUT793H;
	volatile	uint32_t	LUT794L;
	volatile	uint32_t	LUT794H;
	volatile	uint32_t	LUT795L;
	volatile	uint32_t	LUT795H;
	volatile	uint32_t	LUT796L;
	volatile	uint32_t	LUT796H;
	volatile	uint32_t	LUT797L;
	volatile	uint32_t	LUT797H;
	volatile	uint32_t	LUT798L;
	volatile	uint32_t	LUT798H;
	volatile	uint32_t	LUT799L;
	volatile	uint32_t	LUT799H;
	volatile	uint32_t	LUT800L;
	volatile	uint32_t	LUT800H;
	volatile	uint32_t	LUT801L;
	volatile	uint32_t	LUT801H;
	volatile	uint32_t	LUT802L;
	volatile	uint32_t	LUT802H;
	volatile	uint32_t	LUT803L;
	volatile	uint32_t	LUT803H;
	volatile	uint32_t	LUT804L;
	volatile	uint32_t	LUT804H;
	volatile	uint32_t	LUT805L;
	volatile	uint32_t	LUT805H;
	volatile	uint32_t	LUT806L;
	volatile	uint32_t	LUT806H;
	volatile	uint32_t	LUT807L;
	volatile	uint32_t	LUT807H;
	volatile	uint32_t	LUT808L;
	volatile	uint32_t	LUT808H;
	volatile	uint32_t	LUT809L;
	volatile	uint32_t	LUT809H;
	volatile	uint32_t	LUT810L;
	volatile	uint32_t	LUT810H;
	volatile	uint32_t	LUT811L;
	volatile	uint32_t	LUT811H;
	volatile	uint32_t	LUT812L;
	volatile	uint32_t	LUT812H;
	volatile	uint32_t	LUT813L;
	volatile	uint32_t	LUT813H;
	volatile	uint32_t	LUT814L;
	volatile	uint32_t	LUT814H;
	volatile	uint32_t	LUT815L;
	volatile	uint32_t	LUT815H;
	volatile	uint32_t	LUT816L;
	volatile	uint32_t	LUT816H;
	volatile	uint32_t	LUT817L;
	volatile	uint32_t	LUT817H;
	volatile	uint32_t	LUT818L;
	volatile	uint32_t	LUT818H;
	volatile	uint32_t	LUT819L;
	volatile	uint32_t	LUT819H;
	volatile	uint32_t	LUT820L;
	volatile	uint32_t	LUT820H;
	volatile	uint32_t	LUT821L;
	volatile	uint32_t	LUT821H;
	volatile	uint32_t	LUT822L;
	volatile	uint32_t	LUT822H;
	volatile	uint32_t	LUT823L;
	volatile	uint32_t	LUT823H;
	volatile	uint32_t	LUT824L;
	volatile	uint32_t	LUT824H;
	volatile	uint32_t	LUT825L;
	volatile	uint32_t	LUT825H;
	volatile	uint32_t	LUT826L;
	volatile	uint32_t	LUT826H;
	volatile	uint32_t	LUT827L;
	volatile	uint32_t	LUT827H;
	volatile	uint32_t	LUT828L;
	volatile	uint32_t	LUT828H;
	volatile	uint32_t	LUT829L;
	volatile	uint32_t	LUT829H;
	volatile	uint32_t	LUT830L;
	volatile	uint32_t	LUT830H;
	volatile	uint32_t	LUT831L;
	volatile	uint32_t	LUT831H;
	volatile	uint32_t	LUT832L;
	volatile	uint32_t	LUT832H;
	volatile	uint32_t	LUT833L;
	volatile	uint32_t	LUT833H;
	volatile	uint32_t	LUT834L;
	volatile	uint32_t	LUT834H;
	volatile	uint32_t	LUT835L;
	volatile	uint32_t	LUT835H;
	volatile	uint32_t	LUT836L;
	volatile	uint32_t	LUT836H;
	volatile	uint32_t	LUT837L;
	volatile	uint32_t	LUT837H;
	volatile	uint32_t	LUT838L;
	volatile	uint32_t	LUT838H;
	volatile	uint32_t	LUT839L;
	volatile	uint32_t	LUT839H;
	volatile	uint32_t	LUT840L;
	volatile	uint32_t	LUT840H;
	volatile	uint32_t	LUT841L;
	volatile	uint32_t	LUT841H;
	volatile	uint32_t	LUT842L;
	volatile	uint32_t	LUT842H;
	volatile	uint32_t	LUT843L;
	volatile	uint32_t	LUT843H;
	volatile	uint32_t	LUT844L;
	volatile	uint32_t	LUT844H;
	volatile	uint32_t	LUT845L;
	volatile	uint32_t	LUT845H;
	volatile	uint32_t	LUT846L;
	volatile	uint32_t	LUT846H;
	volatile	uint32_t	LUT847L;
	volatile	uint32_t	LUT847H;
	volatile	uint32_t	LUT848L;
	volatile	uint32_t	LUT848H;
	volatile	uint32_t	LUT849L;
	volatile	uint32_t	LUT849H;
	volatile	uint32_t	LUT850L;
	volatile	uint32_t	LUT850H;
	volatile	uint32_t	LUT851L;
	volatile	uint32_t	LUT851H;
	volatile	uint32_t	LUT852L;
	volatile	uint32_t	LUT852H;
	volatile	uint32_t	LUT853L;
	volatile	uint32_t	LUT853H;
	volatile	uint32_t	LUT854L;
	volatile	uint32_t	LUT854H;
	volatile	uint32_t	LUT855L;
	volatile	uint32_t	LUT855H;
	volatile	uint32_t	LUT856L;
	volatile	uint32_t	LUT856H;
	volatile	uint32_t	LUT857L;
	volatile	uint32_t	LUT857H;
	volatile	uint32_t	LUT858L;
	volatile	uint32_t	LUT858H;
	volatile	uint32_t	LUT859L;
	volatile	uint32_t	LUT859H;
	volatile	uint32_t	LUT860L;
	volatile	uint32_t	LUT860H;
	volatile	uint32_t	LUT861L;
	volatile	uint32_t	LUT861H;
	volatile	uint32_t	LUT862L;
	volatile	uint32_t	LUT862H;
	volatile	uint32_t	LUT863L;
	volatile	uint32_t	LUT863H;
	volatile	uint32_t	LUT864L;
	volatile	uint32_t	LUT864H;
	volatile	uint32_t	LUT865L;
	volatile	uint32_t	LUT865H;
	volatile	uint32_t	LUT866L;
	volatile	uint32_t	LUT866H;
	volatile	uint32_t	LUT867L;
	volatile	uint32_t	LUT867H;
	volatile	uint32_t	LUT868L;
	volatile	uint32_t	LUT868H;
	volatile	uint32_t	LUT869L;
	volatile	uint32_t	LUT869H;
	volatile	uint32_t	LUT870L;
	volatile	uint32_t	LUT870H;
	volatile	uint32_t	LUT871L;
	volatile	uint32_t	LUT871H;
	volatile	uint32_t	LUT872L;
	volatile	uint32_t	LUT872H;
	volatile	uint32_t	LUT873L;
	volatile	uint32_t	LUT873H;
	volatile	uint32_t	LUT874L;
	volatile	uint32_t	LUT874H;
	volatile	uint32_t	LUT875L;
	volatile	uint32_t	LUT875H;
	volatile	uint32_t	LUT876L;
	volatile	uint32_t	LUT876H;
	volatile	uint32_t	LUT877L;
	volatile	uint32_t	LUT877H;
	volatile	uint32_t	LUT878L;
	volatile	uint32_t	LUT878H;
	volatile	uint32_t	LUT879L;
	volatile	uint32_t	LUT879H;
	volatile	uint32_t	LUT880L;
	volatile	uint32_t	LUT880H;
	volatile	uint32_t	LUT881L;
	volatile	uint32_t	LUT881H;
	volatile	uint32_t	LUT882L;
	volatile	uint32_t	LUT882H;
	volatile	uint32_t	LUT883L;
	volatile	uint32_t	LUT883H;
	volatile	uint32_t	LUT884L;
	volatile	uint32_t	LUT884H;
	volatile	uint32_t	LUT885L;
	volatile	uint32_t	LUT885H;
	volatile	uint32_t	LUT886L;
	volatile	uint32_t	LUT886H;
	volatile	uint32_t	LUT887L;
	volatile	uint32_t	LUT887H;
	volatile	uint32_t	LUT888L;
	volatile	uint32_t	LUT888H;
	volatile	uint32_t	LUT889L;
	volatile	uint32_t	LUT889H;
	volatile	uint32_t	LUT890L;
	volatile	uint32_t	LUT890H;
	volatile	uint32_t	LUT891L;
	volatile	uint32_t	LUT891H;
	volatile	uint32_t	LUT892L;
	volatile	uint32_t	LUT892H;
	volatile	uint32_t	LUT893L;
	volatile	uint32_t	LUT893H;
	volatile	uint32_t	LUT894L;
	volatile	uint32_t	LUT894H;
	volatile	uint32_t	LUT895L;
	volatile	uint32_t	LUT895H;
	volatile	uint32_t	LUT896L;
	volatile	uint32_t	LUT896H;
	volatile	uint32_t	LUT897L;
	volatile	uint32_t	LUT897H;
	volatile	uint32_t	LUT898L;
	volatile	uint32_t	LUT898H;
	volatile	uint32_t	LUT899L;
	volatile	uint32_t	LUT899H;
	volatile	uint32_t	LUT900L;
	volatile	uint32_t	LUT900H;
	volatile	uint32_t	LUT901L;
	volatile	uint32_t	LUT901H;
	volatile	uint32_t	LUT902L;
	volatile	uint32_t	LUT902H;
	volatile	uint32_t	LUT903L;
	volatile	uint32_t	LUT903H;
	volatile	uint32_t	LUT904L;
	volatile	uint32_t	LUT904H;
	volatile	uint32_t	LUT905L;
	volatile	uint32_t	LUT905H;
	volatile	uint32_t	LUT906L;
	volatile	uint32_t	LUT906H;
	volatile	uint32_t	LUT907L;
	volatile	uint32_t	LUT907H;
	volatile	uint32_t	LUT908L;
	volatile	uint32_t	LUT908H;
	volatile	uint32_t	LUT909L;
	volatile	uint32_t	LUT909H;
	volatile	uint32_t	LUT910L;
	volatile	uint32_t	LUT910H;
	volatile	uint32_t	LUT911L;
	volatile	uint32_t	LUT911H;
	volatile	uint32_t	LUT912L;
	volatile	uint32_t	LUT912H;
	volatile	uint32_t	LUT913L;
	volatile	uint32_t	LUT913H;
	volatile	uint32_t	LUT914L;
	volatile	uint32_t	LUT914H;
	volatile	uint32_t	LUT915L;
	volatile	uint32_t	LUT915H;
	volatile	uint32_t	LUT916L;
	volatile	uint32_t	LUT916H;
	volatile	uint32_t	LUT917L;
	volatile	uint32_t	LUT917H;
	volatile	uint32_t	LUT918L;
	volatile	uint32_t	LUT918H;
	volatile	uint32_t	LUT919L;
	volatile	uint32_t	LUT919H;
	volatile	uint32_t	LUT920L;
	volatile	uint32_t	LUT920H;
	volatile	uint32_t	LUT921L;
	volatile	uint32_t	LUT921H;
	volatile	uint32_t	LUT922L;
	volatile	uint32_t	LUT922H;
	volatile	uint32_t	LUT923L;
	volatile	uint32_t	LUT923H;
	volatile	uint32_t	LUT924L;
	volatile	uint32_t	LUT924H;
	volatile	uint32_t	LUT925L;
	volatile	uint32_t	LUT925H;
	volatile	uint32_t	LUT926L;
	volatile	uint32_t	LUT926H;
	volatile	uint32_t	LUT927L;
	volatile	uint32_t	LUT927H;
	volatile	uint32_t	LUT928L;
	volatile	uint32_t	LUT928H;
	volatile	uint32_t	LUT929L;
	volatile	uint32_t	LUT929H;
	volatile	uint32_t	LUT930L;
	volatile	uint32_t	LUT930H;
	volatile	uint32_t	LUT931L;
	volatile	uint32_t	LUT931H;
	volatile	uint32_t	LUT932L;
	volatile	uint32_t	LUT932H;
	volatile	uint32_t	LUT933L;
	volatile	uint32_t	LUT933H;
	volatile	uint32_t	LUT934L;
	volatile	uint32_t	LUT934H;
	volatile	uint32_t	LUT935L;
	volatile	uint32_t	LUT935H;
	volatile	uint32_t	LUT936L;
	volatile	uint32_t	LUT936H;
	volatile	uint32_t	LUT937L;
	volatile	uint32_t	LUT937H;
	volatile	uint32_t	LUT938L;
	volatile	uint32_t	LUT938H;
	volatile	uint32_t	LUT939L;
	volatile	uint32_t	LUT939H;
	volatile	uint32_t	LUT940L;
	volatile	uint32_t	LUT940H;
	volatile	uint32_t	LUT941L;
	volatile	uint32_t	LUT941H;
	volatile	uint32_t	LUT942L;
	volatile	uint32_t	LUT942H;
	volatile	uint32_t	LUT943L;
	volatile	uint32_t	LUT943H;
	volatile	uint32_t	LUT944L;
	volatile	uint32_t	LUT944H;
	volatile	uint32_t	LUT945L;
	volatile	uint32_t	LUT945H;
	volatile	uint32_t	LUT946L;
	volatile	uint32_t	LUT946H;
	volatile	uint32_t	LUT947L;
	volatile	uint32_t	LUT947H;
	volatile	uint32_t	LUT948L;
	volatile	uint32_t	LUT948H;
	volatile	uint32_t	LUT949L;
	volatile	uint32_t	LUT949H;
	volatile	uint32_t	LUT950L;
	volatile	uint32_t	LUT950H;
	volatile	uint32_t	LUT951L;
	volatile	uint32_t	LUT951H;
	volatile	uint32_t	LUT952L;
	volatile	uint32_t	LUT952H;
	volatile	uint32_t	LUT953L;
	volatile	uint32_t	LUT953H;
	volatile	uint32_t	LUT954L;
	volatile	uint32_t	LUT954H;
	volatile	uint32_t	LUT955L;
	volatile	uint32_t	LUT955H;
	volatile	uint32_t	LUT956L;
	volatile	uint32_t	LUT956H;
	volatile	uint32_t	LUT957L;
	volatile	uint32_t	LUT957H;
	volatile	uint32_t	LUT958L;
	volatile	uint32_t	LUT958H;
	volatile	uint32_t	LUT959L;
	volatile	uint32_t	LUT959H;
	volatile	uint32_t	LUT960L;
	volatile	uint32_t	LUT960H;
	volatile	uint32_t	LUT961L;
	volatile	uint32_t	LUT961H;
	volatile	uint32_t	LUT962L;
	volatile	uint32_t	LUT962H;
	volatile	uint32_t	LUT963L;
	volatile	uint32_t	LUT963H;
	volatile	uint32_t	LUT964L;
	volatile	uint32_t	LUT964H;
	volatile	uint32_t	LUT965L;
	volatile	uint32_t	LUT965H;
	volatile	uint32_t	LUT966L;
	volatile	uint32_t	LUT966H;
	volatile	uint32_t	LUT967L;
	volatile	uint32_t	LUT967H;
	volatile	uint32_t	LUT968L;
	volatile	uint32_t	LUT968H;
	volatile	uint32_t	LUT969L;
	volatile	uint32_t	LUT969H;
	volatile	uint32_t	LUT970L;
	volatile	uint32_t	LUT970H;
	volatile	uint32_t	LUT971L;
	volatile	uint32_t	LUT971H;
	volatile	uint32_t	LUT972L;
	volatile	uint32_t	LUT972H;
	volatile	uint32_t	LUT973L;
	volatile	uint32_t	LUT973H;
	volatile	uint32_t	LUT974L;
	volatile	uint32_t	LUT974H;
	volatile	uint32_t	LUT975L;
	volatile	uint32_t	LUT975H;
	volatile	uint32_t	LUT976L;
	volatile	uint32_t	LUT976H;
	volatile	uint32_t	LUT977L;
	volatile	uint32_t	LUT977H;
	volatile	uint32_t	LUT978L;
	volatile	uint32_t	LUT978H;
	volatile	uint32_t	LUT979L;
	volatile	uint32_t	LUT979H;
	volatile	uint32_t	LUT980L;
	volatile	uint32_t	LUT980H;
	volatile	uint32_t	LUT981L;
	volatile	uint32_t	LUT981H;
	volatile	uint32_t	LUT982L;
	volatile	uint32_t	LUT982H;
	volatile	uint32_t	LUT983L;
	volatile	uint32_t	LUT983H;
	volatile	uint32_t	LUT984L;
	volatile	uint32_t	LUT984H;
	volatile	uint32_t	LUT985L;
	volatile	uint32_t	LUT985H;
	volatile	uint32_t	LUT986L;
	volatile	uint32_t	LUT986H;
	volatile	uint32_t	LUT987L;
	volatile	uint32_t	LUT987H;
	volatile	uint32_t	LUT988L;
	volatile	uint32_t	LUT988H;
	volatile	uint32_t	LUT989L;
	volatile	uint32_t	LUT989H;
	volatile	uint32_t	LUT990L;
	volatile	uint32_t	LUT990H;
	volatile	uint32_t	LUT991L;
	volatile	uint32_t	LUT991H;
	volatile	uint32_t	LUT992L;
	volatile	uint32_t	LUT992H;
	volatile	uint32_t	LUT993L;
	volatile	uint32_t	LUT993H;
	volatile	uint32_t	LUT994L;
	volatile	uint32_t	LUT994H;
	volatile	uint32_t	LUT995L;
	volatile	uint32_t	LUT995H;
	volatile	uint32_t	LUT996L;
	volatile	uint32_t	LUT996H;
	volatile	uint32_t	LUT997L;
	volatile	uint32_t	LUT997H;
	volatile	uint32_t	LUT998L;
	volatile	uint32_t	LUT998H;
	volatile	uint32_t	LUT999L;
	volatile	uint32_t	LUT999H;
	volatile	uint32_t	LUT1000L;
	volatile	uint32_t	LUT1000H;
	volatile	uint32_t	LUT1001L;
	volatile	uint32_t	LUT1001H;
	volatile	uint32_t	LUT1002L;
	volatile	uint32_t	LUT1002H;
	volatile	uint32_t	LUT1003L;
	volatile	uint32_t	LUT1003H;
	volatile	uint32_t	LUT1004L;
	volatile	uint32_t	LUT1004H;
	volatile	uint32_t	LUT1005L;
	volatile	uint32_t	LUT1005H;
	volatile	uint32_t	LUT1006L;
	volatile	uint32_t	LUT1006H;
	volatile	uint32_t	LUT1007L;
	volatile	uint32_t	LUT1007H;
	volatile	uint32_t	LUT1008L;
	volatile	uint32_t	LUT1008H;
	volatile	uint32_t	LUT1009L;
	volatile	uint32_t	LUT1009H;
	volatile	uint32_t	LUT1010L;
	volatile	uint32_t	LUT1010H;
	volatile	uint32_t	LUT1011L;
	volatile	uint32_t	LUT1011H;
	volatile	uint32_t	LUT1012L;
	volatile	uint32_t	LUT1012H;
	volatile	uint32_t	LUT1013L;
	volatile	uint32_t	LUT1013H;
	volatile	uint32_t	LUT1014L;
	volatile	uint32_t	LUT1014H;
	volatile	uint32_t	LUT1015L;
	volatile	uint32_t	LUT1015H;
	volatile	uint32_t	LUT1016L;
	volatile	uint32_t	LUT1016H;
	volatile	uint32_t	LUT1017L;
	volatile	uint32_t	LUT1017H;
	volatile	uint32_t	LUT1018L;
	volatile	uint32_t	LUT1018H;
	volatile	uint32_t	LUT1019L;
	volatile	uint32_t	LUT1019H;
	volatile	uint32_t	LUT1020L;
	volatile	uint32_t	LUT1020H;
	volatile	uint32_t	LUT1021L;
	volatile	uint32_t	LUT1021H;
	volatile	uint32_t	LUT1022L;
	volatile	uint32_t	LUT1022H;
	volatile	uint32_t	LUT1023L;
	volatile	uint32_t	LUT1023H;
} GFXMMU_TypeDef;

#if (defined(__cplusplus))
#define	GFXMMU_NS	reinterpret_cast<GFXMMU_TypeDef *>(0x48030000u)
#define	GFXMMU_S	reinterpret_cast<GFXMMU_TypeDef *>(0x58030000u)

#else
#define	GFXMMU_NS	((GFXMMU_TypeDef *)0x48030000u)
#define	GFXMMU_S	((GFXMMU_TypeDef *)0x58030000u)
#endif

// CR Configuration

#define	GFXMMU_CR_B3PM				(0x1u<<31)
#define	GFXMMU_CR_B3PE				(0x1u<<30)
#define	GFXMMU_CR_B2PM				(0x1u<<29)
#define	GFXMMU_CR_B2PE				(0x1u<<28)
#define	GFXMMU_CR_B1PM				(0x1u<<27)
#define	GFXMMU_CR_B1PE				(0x1u<<26)
#define	GFXMMU_CR_B0PM				(0x1u<<25)
#define	GFXMMU_CR_B0PE				(0x1u<<24)
#define	GFXMMU_CR_ATE				(0x1u<<15)
#define	GFXMMU_CR_BS				(0x1u<<6)
#define	GFXMMU_CR_AMEIE				(0x1u<<4)
#define	GFXMMU_CR_B3OIE				(0x1u<<3)
#define	GFXMMU_CR_B2OIE				(0x1u<<2)
#define	GFXMMU_CR_B1OIE				(0x1u<<1)
#define	GFXMMU_CR_B0OIE				(0x1u<<0)

#define	GFXMMU_CR_B3PM_B_0X0		(0x0u<<31)
#define	GFXMMU_CR_B3PM_B_0X1		(0x1u<<31)
#define	GFXMMU_CR_B3PE_B_0X0		(0x0u<<30)
#define	GFXMMU_CR_B3PE_B_0X1		(0x1u<<30)
#define	GFXMMU_CR_B2PM_B_0X0		(0x0u<<29)
#define	GFXMMU_CR_B2PM_B_0X1		(0x1u<<29)
#define	GFXMMU_CR_B2PE_B_0X0		(0x0u<<28)
#define	GFXMMU_CR_B2PE_B_0X1		(0x1u<<28)
#define	GFXMMU_CR_B1PM_B_0X0		(0x0u<<27)
#define	GFXMMU_CR_B1PM_B_0X1		(0x1u<<27)
#define	GFXMMU_CR_B1PE_B_0X0		(0x0u<<26)
#define	GFXMMU_CR_B1PE_B_0X1		(0x1u<<26)
#define	GFXMMU_CR_B0PM_B_0X0		(0x0u<<25)
#define	GFXMMU_CR_B0PM_B_0X1		(0x1u<<25)
#define	GFXMMU_CR_B0PE_B_0X0		(0x0u<<24)
#define	GFXMMU_CR_B0PE_B_0X1		(0x1u<<24)
#define	GFXMMU_CR_ATE_B_0X0			(0x0u<<15)
#define	GFXMMU_CR_ATE_B_0X1			(0x1u<<15)
#define	GFXMMU_CR_BS_B_0X0			(0x0u<<6)
#define	GFXMMU_CR_BS_B_0X1			(0x1u<<6)
#define	GFXMMU_CR_AMEIE_B_0X0		(0x0u<<4)
#define	GFXMMU_CR_AMEIE_B_0X1		(0x1u<<4)
#define	GFXMMU_CR_B3OIE_B_0X0		(0x0u<<3)
#define	GFXMMU_CR_B3OIE_B_0X1		(0x1u<<3)
#define	GFXMMU_CR_B2OIE_B_0X0		(0x0u<<2)
#define	GFXMMU_CR_B2OIE_B_0X1		(0x1u<<2)
#define	GFXMMU_CR_B1OIE_B_0X0		(0x0u<<1)
#define	GFXMMU_CR_B1OIE_B_0X1		(0x1u<<1)
#define	GFXMMU_CR_B0OIE_B_0X0		(0x0u<<0)
#define	GFXMMU_CR_B0OIE_B_0X1		(0x1u<<0)

// SR Configuration

#define	GFXMMU_SR_AMEF				(0x1u<<4)
#define	GFXMMU_SR_B3OF				(0x1u<<3)
#define	GFXMMU_SR_B2OF				(0x1u<<2)
#define	GFXMMU_SR_B1OF				(0x1u<<1)
#define	GFXMMU_SR_B0OF				(0x1u<<0)

// FCR Configuration

#define	GFXMMU_FCR_CAMEF			(0x1u<<4)
#define	GFXMMU_FCR_CB3OF			(0x1u<<3)
#define	GFXMMU_FCR_CB2OF			(0x1u<<2)
#define	GFXMMU_FCR_CB1OF			(0x1u<<1)
#define	GFXMMU_FCR_CB0OF			(0x1u<<0)

// DVR Configuration

#define	GFXMMU_DVR_DV				(0xFFFFFFFFu<<0)
#define	GFXMMU_DVR_DV_0				(0x1u<<0)

// DAR Configuration

#define	GFXMMU_DAR_DA				(0xFFu<<0)
#define	GFXMMU_DAR_DA_0				(0x1u<<0)

// B0CR Configuration

#define	GFXMMU_B0CR_PBBA			(0x1FFu<<23)
#define	GFXMMU_B0CR_PBBA_0			(0x1u<<23)
#define	GFXMMU_B0CR_PBO				(0x7FFFFu<<4)
#define	GFXMMU_B0CR_PBO_0			(0x1u<<4)

// B1CR Configuration

#define	GFXMMU_B1CR_PBBA			(0x1FFu<<23)
#define	GFXMMU_B1CR_PBBA_0			(0x1u<<23)
#define	GFXMMU_B1CR_PBO				(0x7FFFFu<<4)
#define	GFXMMU_B1CR_PBO_0			(0x1u<<4)

// B2CR Configuration

#define	GFXMMU_B2CR_PBBA			(0x1FFu<<23)
#define	GFXMMU_B2CR_PBBA_0			(0x1u<<23)
#define	GFXMMU_B2CR_PBO				(0x7FFFFu<<4)
#define	GFXMMU_B2CR_PBO_0			(0x1u<<4)

// B3CR Configuration

#define	GFXMMU_B3CR_PBBA			(0x1FFu<<23)
#define	GFXMMU_B3CR_PBBA_0			(0x1u<<23)
#define	GFXMMU_B3CR_PBO				(0x7FFFFu<<4)
#define	GFXMMU_B3CR_PBO_0			(0x1u<<4)

// LUT0L Configuration

#define	GFXMMU_LUT0L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT0L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT0L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT0L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT0L_EN				(0x1u<<0)

#define	GFXMMU_LUT0L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT0L_EN_B_0X1		(0x1u<<0)

// LUT0H Configuration

#define	GFXMMU_LUT0H_LO				(0x3FFFFu<<0)
#define	GFXMMU_LUT0H_LO_0			(0x1u<<0)

// LUT1L Configuration

#define	GFXMMU_LUT1L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT1L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT1L_EN				(0x1u<<0)

#define	GFXMMU_LUT1L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT1L_EN_B_0X1		(0x1u<<0)

// LUT1H Configuration

#define	GFXMMU_LUT1H_LO				(0x3FFFFu<<0)
#define	GFXMMU_LUT1H_LO_0			(0x1u<<0)

// LUT2L Configuration

#define	GFXMMU_LUT2L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT2L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT2L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT2L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT2L_EN				(0x1u<<0)

#define	GFXMMU_LUT2L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT2L_EN_B_0X1		(0x1u<<0)

// LUT2H Configuration

#define	GFXMMU_LUT2H_LO				(0x3FFFFu<<0)
#define	GFXMMU_LUT2H_LO_0			(0x1u<<0)

// LUT3L Configuration

#define	GFXMMU_LUT3L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT3L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT3L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT3L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT3L_EN				(0x1u<<0)

#define	GFXMMU_LUT3L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT3L_EN_B_0X1		(0x1u<<0)

// LUT3H Configuration

#define	GFXMMU_LUT3H_LO				(0x3FFFFu<<0)
#define	GFXMMU_LUT3H_LO_0			(0x1u<<0)

// LUT4L Configuration

#define	GFXMMU_LUT4L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT4L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT4L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT4L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT4L_EN				(0x1u<<0)

#define	GFXMMU_LUT4L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT4L_EN_B_0X1		(0x1u<<0)

// LUT4H Configuration

#define	GFXMMU_LUT4H_LO				(0x3FFFFu<<0)
#define	GFXMMU_LUT4H_LO_0			(0x1u<<0)

// LUT5L Configuration

#define	GFXMMU_LUT5L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT5L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT5L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT5L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT5L_EN				(0x1u<<0)

#define	GFXMMU_LUT5L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT5L_EN_B_0X1		(0x1u<<0)

// LUT5H Configuration

#define	GFXMMU_LUT5H_LO				(0x3FFFFu<<0)
#define	GFXMMU_LUT5H_LO_0			(0x1u<<0)

// LUT6L Configuration

#define	GFXMMU_LUT6L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT6L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT6L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT6L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT6L_EN				(0x1u<<0)

#define	GFXMMU_LUT6L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT6L_EN_B_0X1		(0x1u<<0)

// LUT6H Configuration

#define	GFXMMU_LUT6H_LO				(0x3FFFFu<<0)
#define	GFXMMU_LUT6H_LO_0			(0x1u<<0)

// LUT7L Configuration

#define	GFXMMU_LUT7L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT7L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT7L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT7L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT7L_EN				(0x1u<<0)

#define	GFXMMU_LUT7L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT7L_EN_B_0X1		(0x1u<<0)

// LUT7H Configuration

#define	GFXMMU_LUT7H_LO				(0x3FFFFu<<0)
#define	GFXMMU_LUT7H_LO_0			(0x1u<<0)

// LUT8L Configuration

#define	GFXMMU_LUT8L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT8L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT8L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT8L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT8L_EN				(0x1u<<0)

#define	GFXMMU_LUT8L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT8L_EN_B_0X1		(0x1u<<0)

// LUT8H Configuration

#define	GFXMMU_LUT8H_LO				(0x3FFFFu<<0)
#define	GFXMMU_LUT8H_LO_0			(0x1u<<0)

// LUT9L Configuration

#define	GFXMMU_LUT9L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT9L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT9L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT9L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT9L_EN				(0x1u<<0)

#define	GFXMMU_LUT9L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT9L_EN_B_0X1		(0x1u<<0)

// LUT9H Configuration

#define	GFXMMU_LUT9H_LO				(0x3FFFFu<<0)
#define	GFXMMU_LUT9H_LO_0			(0x1u<<0)

// LUT10L Configuration

#define	GFXMMU_LUT10L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT10L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT10L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT10L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT10L_EN			(0x1u<<0)

#define	GFXMMU_LUT10L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT10L_EN_B_0X1		(0x1u<<0)

// LUT10H Configuration

#define	GFXMMU_LUT10H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT10H_LO_0			(0x1u<<0)

// LUT11L Configuration

#define	GFXMMU_LUT11L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT11L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT11L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT11L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT11L_EN			(0x1u<<0)

#define	GFXMMU_LUT11L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT11L_EN_B_0X1		(0x1u<<0)

// LUT11H Configuration

#define	GFXMMU_LUT11H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT11H_LO_0			(0x1u<<0)

// LUT12L Configuration

#define	GFXMMU_LUT12L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT12L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT12L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT12L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT12L_EN			(0x1u<<0)

#define	GFXMMU_LUT12L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT12L_EN_B_0X1		(0x1u<<0)

// LUT12H Configuration

#define	GFXMMU_LUT12H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT12H_LO_0			(0x1u<<0)

// LUT13L Configuration

#define	GFXMMU_LUT13L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT13L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT13L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT13L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT13L_EN			(0x1u<<0)

#define	GFXMMU_LUT13L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT13L_EN_B_0X1		(0x1u<<0)

// LUT13H Configuration

#define	GFXMMU_LUT13H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT13H_LO_0			(0x1u<<0)

// LUT14L Configuration

#define	GFXMMU_LUT14L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT14L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT14L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT14L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT14L_EN			(0x1u<<0)

#define	GFXMMU_LUT14L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT14L_EN_B_0X1		(0x1u<<0)

// LUT14H Configuration

#define	GFXMMU_LUT14H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT14H_LO_0			(0x1u<<0)

// LUT15L Configuration

#define	GFXMMU_LUT15L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT15L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT15L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT15L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT15L_EN			(0x1u<<0)

#define	GFXMMU_LUT15L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT15L_EN_B_0X1		(0x1u<<0)

// LUT15H Configuration

#define	GFXMMU_LUT15H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT15H_LO_0			(0x1u<<0)

// LUT16L Configuration

#define	GFXMMU_LUT16L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT16L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT16L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT16L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT16L_EN			(0x1u<<0)

#define	GFXMMU_LUT16L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT16L_EN_B_0X1		(0x1u<<0)

// LUT16H Configuration

#define	GFXMMU_LUT16H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT16H_LO_0			(0x1u<<0)

// LUT17L Configuration

#define	GFXMMU_LUT17L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT17L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT17L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT17L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT17L_EN			(0x1u<<0)

#define	GFXMMU_LUT17L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT17L_EN_B_0X1		(0x1u<<0)

// LUT17H Configuration

#define	GFXMMU_LUT17H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT17H_LO_0			(0x1u<<0)

// LUT18L Configuration

#define	GFXMMU_LUT18L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT18L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT18L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT18L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT18L_EN			(0x1u<<0)

#define	GFXMMU_LUT18L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT18L_EN_B_0X1		(0x1u<<0)

// LUT18H Configuration

#define	GFXMMU_LUT18H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT18H_LO_0			(0x1u<<0)

// LUT19L Configuration

#define	GFXMMU_LUT19L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT19L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT19L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT19L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT19L_EN			(0x1u<<0)

#define	GFXMMU_LUT19L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT19L_EN_B_0X1		(0x1u<<0)

// LUT19H Configuration

#define	GFXMMU_LUT19H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT19H_LO_0			(0x1u<<0)

// LUT20L Configuration

#define	GFXMMU_LUT20L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT20L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT20L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT20L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT20L_EN			(0x1u<<0)

#define	GFXMMU_LUT20L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT20L_EN_B_0X1		(0x1u<<0)

// LUT20H Configuration

#define	GFXMMU_LUT20H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT20H_LO_0			(0x1u<<0)

// LUT21L Configuration

#define	GFXMMU_LUT21L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT21L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT21L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT21L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT21L_EN			(0x1u<<0)

#define	GFXMMU_LUT21L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT21L_EN_B_0X1		(0x1u<<0)

// LUT21H Configuration

#define	GFXMMU_LUT21H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT21H_LO_0			(0x1u<<0)

// LUT22L Configuration

#define	GFXMMU_LUT22L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT22L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT22L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT22L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT22L_EN			(0x1u<<0)

#define	GFXMMU_LUT22L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT22L_EN_B_0X1		(0x1u<<0)

// LUT22H Configuration

#define	GFXMMU_LUT22H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT22H_LO_0			(0x1u<<0)

// LUT23L Configuration

#define	GFXMMU_LUT23L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT23L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT23L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT23L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT23L_EN			(0x1u<<0)

#define	GFXMMU_LUT23L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT23L_EN_B_0X1		(0x1u<<0)

// LUT23H Configuration

#define	GFXMMU_LUT23H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT23H_LO_0			(0x1u<<0)

// LUT24L Configuration

#define	GFXMMU_LUT24L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT24L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT24L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT24L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT24L_EN			(0x1u<<0)

#define	GFXMMU_LUT24L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT24L_EN_B_0X1		(0x1u<<0)

// LUT24H Configuration

#define	GFXMMU_LUT24H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT24H_LO_0			(0x1u<<0)

// LUT25L Configuration

#define	GFXMMU_LUT25L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT25L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT25L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT25L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT25L_EN			(0x1u<<0)

#define	GFXMMU_LUT25L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT25L_EN_B_0X1		(0x1u<<0)

// LUT25H Configuration

#define	GFXMMU_LUT25H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT25H_LO_0			(0x1u<<0)

// LUT26L Configuration

#define	GFXMMU_LUT26L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT26L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT26L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT26L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT26L_EN			(0x1u<<0)

#define	GFXMMU_LUT26L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT26L_EN_B_0X1		(0x1u<<0)

// LUT26H Configuration

#define	GFXMMU_LUT26H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT26H_LO_0			(0x1u<<0)

// LUT27L Configuration

#define	GFXMMU_LUT27L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT27L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT27L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT27L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT27L_EN			(0x1u<<0)

#define	GFXMMU_LUT27L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT27L_EN_B_0X1		(0x1u<<0)

// LUT27H Configuration

#define	GFXMMU_LUT27H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT27H_LO_0			(0x1u<<0)

// LUT28L Configuration

#define	GFXMMU_LUT28L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT28L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT28L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT28L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT28L_EN			(0x1u<<0)

#define	GFXMMU_LUT28L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT28L_EN_B_0X1		(0x1u<<0)

// LUT28H Configuration

#define	GFXMMU_LUT28H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT28H_LO_0			(0x1u<<0)

// LUT29L Configuration

#define	GFXMMU_LUT29L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT29L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT29L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT29L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT29L_EN			(0x1u<<0)

#define	GFXMMU_LUT29L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT29L_EN_B_0X1		(0x1u<<0)

// LUT29H Configuration

#define	GFXMMU_LUT29H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT29H_LO_0			(0x1u<<0)

// LUT30L Configuration

#define	GFXMMU_LUT30L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT30L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT30L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT30L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT30L_EN			(0x1u<<0)

#define	GFXMMU_LUT30L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT30L_EN_B_0X1		(0x1u<<0)

// LUT30H Configuration

#define	GFXMMU_LUT30H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT30H_LO_0			(0x1u<<0)

// LUT31L Configuration

#define	GFXMMU_LUT31L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT31L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT31L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT31L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT31L_EN			(0x1u<<0)

#define	GFXMMU_LUT31L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT31L_EN_B_0X1		(0x1u<<0)

// LUT31H Configuration

#define	GFXMMU_LUT31H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT31H_LO_0			(0x1u<<0)

// LUT32L Configuration

#define	GFXMMU_LUT32L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT32L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT32L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT32L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT32L_EN			(0x1u<<0)

#define	GFXMMU_LUT32L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT32L_EN_B_0X1		(0x1u<<0)

// LUT32H Configuration

#define	GFXMMU_LUT32H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT32H_LO_0			(0x1u<<0)

// LUT33L Configuration

#define	GFXMMU_LUT33L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT33L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT33L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT33L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT33L_EN			(0x1u<<0)

#define	GFXMMU_LUT33L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT33L_EN_B_0X1		(0x1u<<0)

// LUT33H Configuration

#define	GFXMMU_LUT33H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT33H_LO_0			(0x1u<<0)

// LUT34L Configuration

#define	GFXMMU_LUT34L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT34L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT34L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT34L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT34L_EN			(0x1u<<0)

#define	GFXMMU_LUT34L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT34L_EN_B_0X1		(0x1u<<0)

// LUT34H Configuration

#define	GFXMMU_LUT34H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT34H_LO_0			(0x1u<<0)

// LUT35L Configuration

#define	GFXMMU_LUT35L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT35L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT35L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT35L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT35L_EN			(0x1u<<0)

#define	GFXMMU_LUT35L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT35L_EN_B_0X1		(0x1u<<0)

// LUT35H Configuration

#define	GFXMMU_LUT35H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT35H_LO_0			(0x1u<<0)

// LUT36L Configuration

#define	GFXMMU_LUT36L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT36L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT36L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT36L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT36L_EN			(0x1u<<0)

#define	GFXMMU_LUT36L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT36L_EN_B_0X1		(0x1u<<0)

// LUT36H Configuration

#define	GFXMMU_LUT36H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT36H_LO_0			(0x1u<<0)

// LUT37L Configuration

#define	GFXMMU_LUT37L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT37L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT37L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT37L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT37L_EN			(0x1u<<0)

#define	GFXMMU_LUT37L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT37L_EN_B_0X1		(0x1u<<0)

// LUT37H Configuration

#define	GFXMMU_LUT37H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT37H_LO_0			(0x1u<<0)

// LUT38L Configuration

#define	GFXMMU_LUT38L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT38L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT38L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT38L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT38L_EN			(0x1u<<0)

#define	GFXMMU_LUT38L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT38L_EN_B_0X1		(0x1u<<0)

// LUT38H Configuration

#define	GFXMMU_LUT38H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT38H_LO_0			(0x1u<<0)

// LUT39L Configuration

#define	GFXMMU_LUT39L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT39L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT39L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT39L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT39L_EN			(0x1u<<0)

#define	GFXMMU_LUT39L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT39L_EN_B_0X1		(0x1u<<0)

// LUT39H Configuration

#define	GFXMMU_LUT39H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT39H_LO_0			(0x1u<<0)

// LUT40L Configuration

#define	GFXMMU_LUT40L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT40L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT40L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT40L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT40L_EN			(0x1u<<0)

#define	GFXMMU_LUT40L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT40L_EN_B_0X1		(0x1u<<0)

// LUT40H Configuration

#define	GFXMMU_LUT40H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT40H_LO_0			(0x1u<<0)

// LUT41L Configuration

#define	GFXMMU_LUT41L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT41L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT41L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT41L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT41L_EN			(0x1u<<0)

#define	GFXMMU_LUT41L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT41L_EN_B_0X1		(0x1u<<0)

// LUT41H Configuration

#define	GFXMMU_LUT41H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT41H_LO_0			(0x1u<<0)

// LUT42L Configuration

#define	GFXMMU_LUT42L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT42L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT42L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT42L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT42L_EN			(0x1u<<0)

#define	GFXMMU_LUT42L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT42L_EN_B_0X1		(0x1u<<0)

// LUT42H Configuration

#define	GFXMMU_LUT42H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT42H_LO_0			(0x1u<<0)

// LUT43L Configuration

#define	GFXMMU_LUT43L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT43L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT43L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT43L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT43L_EN			(0x1u<<0)

#define	GFXMMU_LUT43L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT43L_EN_B_0X1		(0x1u<<0)

// LUT43H Configuration

#define	GFXMMU_LUT43H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT43H_LO_0			(0x1u<<0)

// LUT44L Configuration

#define	GFXMMU_LUT44L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT44L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT44L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT44L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT44L_EN			(0x1u<<0)

#define	GFXMMU_LUT44L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT44L_EN_B_0X1		(0x1u<<0)

// LUT44H Configuration

#define	GFXMMU_LUT44H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT44H_LO_0			(0x1u<<0)

// LUT45L Configuration

#define	GFXMMU_LUT45L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT45L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT45L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT45L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT45L_EN			(0x1u<<0)

#define	GFXMMU_LUT45L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT45L_EN_B_0X1		(0x1u<<0)

// LUT45H Configuration

#define	GFXMMU_LUT45H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT45H_LO_0			(0x1u<<0)

// LUT46L Configuration

#define	GFXMMU_LUT46L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT46L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT46L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT46L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT46L_EN			(0x1u<<0)

#define	GFXMMU_LUT46L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT46L_EN_B_0X1		(0x1u<<0)

// LUT46H Configuration

#define	GFXMMU_LUT46H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT46H_LO_0			(0x1u<<0)

// LUT47L Configuration

#define	GFXMMU_LUT47L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT47L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT47L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT47L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT47L_EN			(0x1u<<0)

#define	GFXMMU_LUT47L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT47L_EN_B_0X1		(0x1u<<0)

// LUT47H Configuration

#define	GFXMMU_LUT47H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT47H_LO_0			(0x1u<<0)

// LUT48L Configuration

#define	GFXMMU_LUT48L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT48L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT48L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT48L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT48L_EN			(0x1u<<0)

#define	GFXMMU_LUT48L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT48L_EN_B_0X1		(0x1u<<0)

// LUT48H Configuration

#define	GFXMMU_LUT48H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT48H_LO_0			(0x1u<<0)

// LUT49L Configuration

#define	GFXMMU_LUT49L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT49L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT49L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT49L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT49L_EN			(0x1u<<0)

#define	GFXMMU_LUT49L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT49L_EN_B_0X1		(0x1u<<0)

// LUT49H Configuration

#define	GFXMMU_LUT49H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT49H_LO_0			(0x1u<<0)

// LUT50L Configuration

#define	GFXMMU_LUT50L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT50L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT50L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT50L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT50L_EN			(0x1u<<0)

#define	GFXMMU_LUT50L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT50L_EN_B_0X1		(0x1u<<0)

// LUT50H Configuration

#define	GFXMMU_LUT50H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT50H_LO_0			(0x1u<<0)

// LUT51L Configuration

#define	GFXMMU_LUT51L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT51L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT51L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT51L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT51L_EN			(0x1u<<0)

#define	GFXMMU_LUT51L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT51L_EN_B_0X1		(0x1u<<0)

// LUT51H Configuration

#define	GFXMMU_LUT51H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT51H_LO_0			(0x1u<<0)

// LUT52L Configuration

#define	GFXMMU_LUT52L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT52L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT52L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT52L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT52L_EN			(0x1u<<0)

#define	GFXMMU_LUT52L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT52L_EN_B_0X1		(0x1u<<0)

// LUT52H Configuration

#define	GFXMMU_LUT52H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT52H_LO_0			(0x1u<<0)

// LUT53L Configuration

#define	GFXMMU_LUT53L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT53L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT53L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT53L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT53L_EN			(0x1u<<0)

#define	GFXMMU_LUT53L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT53L_EN_B_0X1		(0x1u<<0)

// LUT53H Configuration

#define	GFXMMU_LUT53H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT53H_LO_0			(0x1u<<0)

// LUT54L Configuration

#define	GFXMMU_LUT54L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT54L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT54L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT54L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT54L_EN			(0x1u<<0)

#define	GFXMMU_LUT54L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT54L_EN_B_0X1		(0x1u<<0)

// LUT54H Configuration

#define	GFXMMU_LUT54H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT54H_LO_0			(0x1u<<0)

// LUT55L Configuration

#define	GFXMMU_LUT55L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT55L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT55L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT55L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT55L_EN			(0x1u<<0)

#define	GFXMMU_LUT55L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT55L_EN_B_0X1		(0x1u<<0)

// LUT55H Configuration

#define	GFXMMU_LUT55H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT55H_LO_0			(0x1u<<0)

// LUT56L Configuration

#define	GFXMMU_LUT56L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT56L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT56L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT56L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT56L_EN			(0x1u<<0)

#define	GFXMMU_LUT56L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT56L_EN_B_0X1		(0x1u<<0)

// LUT56H Configuration

#define	GFXMMU_LUT56H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT56H_LO_0			(0x1u<<0)

// LUT57L Configuration

#define	GFXMMU_LUT57L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT57L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT57L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT57L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT57L_EN			(0x1u<<0)

#define	GFXMMU_LUT57L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT57L_EN_B_0X1		(0x1u<<0)

// LUT57H Configuration

#define	GFXMMU_LUT57H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT57H_LO_0			(0x1u<<0)

// LUT58L Configuration

#define	GFXMMU_LUT58L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT58L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT58L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT58L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT58L_EN			(0x1u<<0)

#define	GFXMMU_LUT58L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT58L_EN_B_0X1		(0x1u<<0)

// LUT58H Configuration

#define	GFXMMU_LUT58H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT58H_LO_0			(0x1u<<0)

// LUT59L Configuration

#define	GFXMMU_LUT59L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT59L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT59L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT59L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT59L_EN			(0x1u<<0)

#define	GFXMMU_LUT59L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT59L_EN_B_0X1		(0x1u<<0)

// LUT59H Configuration

#define	GFXMMU_LUT59H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT59H_LO_0			(0x1u<<0)

// LUT60L Configuration

#define	GFXMMU_LUT60L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT60L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT60L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT60L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT60L_EN			(0x1u<<0)

#define	GFXMMU_LUT60L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT60L_EN_B_0X1		(0x1u<<0)

// LUT60H Configuration

#define	GFXMMU_LUT60H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT60H_LO_0			(0x1u<<0)

// LUT61L Configuration

#define	GFXMMU_LUT61L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT61L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT61L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT61L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT61L_EN			(0x1u<<0)

#define	GFXMMU_LUT61L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT61L_EN_B_0X1		(0x1u<<0)

// LUT61H Configuration

#define	GFXMMU_LUT61H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT61H_LO_0			(0x1u<<0)

// LUT62L Configuration

#define	GFXMMU_LUT62L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT62L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT62L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT62L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT62L_EN			(0x1u<<0)

#define	GFXMMU_LUT62L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT62L_EN_B_0X1		(0x1u<<0)

// LUT62H Configuration

#define	GFXMMU_LUT62H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT62H_LO_0			(0x1u<<0)

// LUT63L Configuration

#define	GFXMMU_LUT63L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT63L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT63L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT63L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT63L_EN			(0x1u<<0)

#define	GFXMMU_LUT63L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT63L_EN_B_0X1		(0x1u<<0)

// LUT63H Configuration

#define	GFXMMU_LUT63H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT63H_LO_0			(0x1u<<0)

// LUT64L Configuration

#define	GFXMMU_LUT64L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT64L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT64L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT64L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT64L_EN			(0x1u<<0)

#define	GFXMMU_LUT64L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT64L_EN_B_0X1		(0x1u<<0)

// LUT64H Configuration

#define	GFXMMU_LUT64H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT64H_LO_0			(0x1u<<0)

// LUT65L Configuration

#define	GFXMMU_LUT65L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT65L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT65L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT65L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT65L_EN			(0x1u<<0)

#define	GFXMMU_LUT65L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT65L_EN_B_0X1		(0x1u<<0)

// LUT65H Configuration

#define	GFXMMU_LUT65H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT65H_LO_0			(0x1u<<0)

// LUT66L Configuration

#define	GFXMMU_LUT66L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT66L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT66L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT66L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT66L_EN			(0x1u<<0)

#define	GFXMMU_LUT66L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT66L_EN_B_0X1		(0x1u<<0)

// LUT66H Configuration

#define	GFXMMU_LUT66H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT66H_LO_0			(0x1u<<0)

// LUT67L Configuration

#define	GFXMMU_LUT67L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT67L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT67L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT67L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT67L_EN			(0x1u<<0)

#define	GFXMMU_LUT67L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT67L_EN_B_0X1		(0x1u<<0)

// LUT67H Configuration

#define	GFXMMU_LUT67H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT67H_LO_0			(0x1u<<0)

// LUT68L Configuration

#define	GFXMMU_LUT68L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT68L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT68L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT68L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT68L_EN			(0x1u<<0)

#define	GFXMMU_LUT68L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT68L_EN_B_0X1		(0x1u<<0)

// LUT68H Configuration

#define	GFXMMU_LUT68H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT68H_LO_0			(0x1u<<0)

// LUT69L Configuration

#define	GFXMMU_LUT69L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT69L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT69L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT69L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT69L_EN			(0x1u<<0)

#define	GFXMMU_LUT69L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT69L_EN_B_0X1		(0x1u<<0)

// LUT69H Configuration

#define	GFXMMU_LUT69H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT69H_LO_0			(0x1u<<0)

// LUT70L Configuration

#define	GFXMMU_LUT70L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT70L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT70L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT70L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT70L_EN			(0x1u<<0)

#define	GFXMMU_LUT70L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT70L_EN_B_0X1		(0x1u<<0)

// LUT70H Configuration

#define	GFXMMU_LUT70H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT70H_LO_0			(0x1u<<0)

// LUT71L Configuration

#define	GFXMMU_LUT71L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT71L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT71L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT71L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT71L_EN			(0x1u<<0)

#define	GFXMMU_LUT71L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT71L_EN_B_0X1		(0x1u<<0)

// LUT71H Configuration

#define	GFXMMU_LUT71H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT71H_LO_0			(0x1u<<0)

// LUT72L Configuration

#define	GFXMMU_LUT72L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT72L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT72L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT72L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT72L_EN			(0x1u<<0)

#define	GFXMMU_LUT72L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT72L_EN_B_0X1		(0x1u<<0)

// LUT72H Configuration

#define	GFXMMU_LUT72H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT72H_LO_0			(0x1u<<0)

// LUT73L Configuration

#define	GFXMMU_LUT73L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT73L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT73L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT73L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT73L_EN			(0x1u<<0)

#define	GFXMMU_LUT73L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT73L_EN_B_0X1		(0x1u<<0)

// LUT73H Configuration

#define	GFXMMU_LUT73H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT73H_LO_0			(0x1u<<0)

// LUT74L Configuration

#define	GFXMMU_LUT74L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT74L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT74L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT74L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT74L_EN			(0x1u<<0)

#define	GFXMMU_LUT74L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT74L_EN_B_0X1		(0x1u<<0)

// LUT74H Configuration

#define	GFXMMU_LUT74H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT74H_LO_0			(0x1u<<0)

// LUT75L Configuration

#define	GFXMMU_LUT75L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT75L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT75L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT75L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT75L_EN			(0x1u<<0)

#define	GFXMMU_LUT75L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT75L_EN_B_0X1		(0x1u<<0)

// LUT75H Configuration

#define	GFXMMU_LUT75H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT75H_LO_0			(0x1u<<0)

// LUT76L Configuration

#define	GFXMMU_LUT76L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT76L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT76L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT76L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT76L_EN			(0x1u<<0)

#define	GFXMMU_LUT76L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT76L_EN_B_0X1		(0x1u<<0)

// LUT76H Configuration

#define	GFXMMU_LUT76H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT76H_LO_0			(0x1u<<0)

// LUT77L Configuration

#define	GFXMMU_LUT77L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT77L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT77L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT77L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT77L_EN			(0x1u<<0)

#define	GFXMMU_LUT77L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT77L_EN_B_0X1		(0x1u<<0)

// LUT77H Configuration

#define	GFXMMU_LUT77H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT77H_LO_0			(0x1u<<0)

// LUT78L Configuration

#define	GFXMMU_LUT78L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT78L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT78L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT78L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT78L_EN			(0x1u<<0)

#define	GFXMMU_LUT78L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT78L_EN_B_0X1		(0x1u<<0)

// LUT78H Configuration

#define	GFXMMU_LUT78H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT78H_LO_0			(0x1u<<0)

// LUT79L Configuration

#define	GFXMMU_LUT79L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT79L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT79L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT79L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT79L_EN			(0x1u<<0)

#define	GFXMMU_LUT79L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT79L_EN_B_0X1		(0x1u<<0)

// LUT79H Configuration

#define	GFXMMU_LUT79H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT79H_LO_0			(0x1u<<0)

// LUT80L Configuration

#define	GFXMMU_LUT80L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT80L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT80L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT80L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT80L_EN			(0x1u<<0)

#define	GFXMMU_LUT80L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT80L_EN_B_0X1		(0x1u<<0)

// LUT80H Configuration

#define	GFXMMU_LUT80H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT80H_LO_0			(0x1u<<0)

// LUT81L Configuration

#define	GFXMMU_LUT81L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT81L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT81L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT81L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT81L_EN			(0x1u<<0)

#define	GFXMMU_LUT81L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT81L_EN_B_0X1		(0x1u<<0)

// LUT81H Configuration

#define	GFXMMU_LUT81H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT81H_LO_0			(0x1u<<0)

// LUT82L Configuration

#define	GFXMMU_LUT82L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT82L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT82L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT82L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT82L_EN			(0x1u<<0)

#define	GFXMMU_LUT82L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT82L_EN_B_0X1		(0x1u<<0)

// LUT82H Configuration

#define	GFXMMU_LUT82H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT82H_LO_0			(0x1u<<0)

// LUT83L Configuration

#define	GFXMMU_LUT83L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT83L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT83L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT83L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT83L_EN			(0x1u<<0)

#define	GFXMMU_LUT83L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT83L_EN_B_0X1		(0x1u<<0)

// LUT83H Configuration

#define	GFXMMU_LUT83H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT83H_LO_0			(0x1u<<0)

// LUT84L Configuration

#define	GFXMMU_LUT84L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT84L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT84L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT84L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT84L_EN			(0x1u<<0)

#define	GFXMMU_LUT84L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT84L_EN_B_0X1		(0x1u<<0)

// LUT84H Configuration

#define	GFXMMU_LUT84H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT84H_LO_0			(0x1u<<0)

// LUT85L Configuration

#define	GFXMMU_LUT85L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT85L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT85L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT85L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT85L_EN			(0x1u<<0)

#define	GFXMMU_LUT85L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT85L_EN_B_0X1		(0x1u<<0)

// LUT85H Configuration

#define	GFXMMU_LUT85H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT85H_LO_0			(0x1u<<0)

// LUT86L Configuration

#define	GFXMMU_LUT86L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT86L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT86L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT86L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT86L_EN			(0x1u<<0)

#define	GFXMMU_LUT86L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT86L_EN_B_0X1		(0x1u<<0)

// LUT86H Configuration

#define	GFXMMU_LUT86H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT86H_LO_0			(0x1u<<0)

// LUT87L Configuration

#define	GFXMMU_LUT87L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT87L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT87L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT87L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT87L_EN			(0x1u<<0)

#define	GFXMMU_LUT87L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT87L_EN_B_0X1		(0x1u<<0)

// LUT87H Configuration

#define	GFXMMU_LUT87H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT87H_LO_0			(0x1u<<0)

// LUT88L Configuration

#define	GFXMMU_LUT88L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT88L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT88L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT88L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT88L_EN			(0x1u<<0)

#define	GFXMMU_LUT88L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT88L_EN_B_0X1		(0x1u<<0)

// LUT88H Configuration

#define	GFXMMU_LUT88H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT88H_LO_0			(0x1u<<0)

// LUT89L Configuration

#define	GFXMMU_LUT89L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT89L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT89L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT89L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT89L_EN			(0x1u<<0)

#define	GFXMMU_LUT89L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT89L_EN_B_0X1		(0x1u<<0)

// LUT89H Configuration

#define	GFXMMU_LUT89H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT89H_LO_0			(0x1u<<0)

// LUT90L Configuration

#define	GFXMMU_LUT90L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT90L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT90L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT90L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT90L_EN			(0x1u<<0)

#define	GFXMMU_LUT90L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT90L_EN_B_0X1		(0x1u<<0)

// LUT90H Configuration

#define	GFXMMU_LUT90H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT90H_LO_0			(0x1u<<0)

// LUT91L Configuration

#define	GFXMMU_LUT91L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT91L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT91L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT91L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT91L_EN			(0x1u<<0)

#define	GFXMMU_LUT91L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT91L_EN_B_0X1		(0x1u<<0)

// LUT91H Configuration

#define	GFXMMU_LUT91H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT91H_LO_0			(0x1u<<0)

// LUT92L Configuration

#define	GFXMMU_LUT92L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT92L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT92L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT92L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT92L_EN			(0x1u<<0)

#define	GFXMMU_LUT92L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT92L_EN_B_0X1		(0x1u<<0)

// LUT92H Configuration

#define	GFXMMU_LUT92H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT92H_LO_0			(0x1u<<0)

// LUT93L Configuration

#define	GFXMMU_LUT93L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT93L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT93L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT93L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT93L_EN			(0x1u<<0)

#define	GFXMMU_LUT93L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT93L_EN_B_0X1		(0x1u<<0)

// LUT93H Configuration

#define	GFXMMU_LUT93H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT93H_LO_0			(0x1u<<0)

// LUT94L Configuration

#define	GFXMMU_LUT94L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT94L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT94L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT94L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT94L_EN			(0x1u<<0)

#define	GFXMMU_LUT94L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT94L_EN_B_0X1		(0x1u<<0)

// LUT94H Configuration

#define	GFXMMU_LUT94H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT94H_LO_0			(0x1u<<0)

// LUT95L Configuration

#define	GFXMMU_LUT95L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT95L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT95L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT95L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT95L_EN			(0x1u<<0)

#define	GFXMMU_LUT95L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT95L_EN_B_0X1		(0x1u<<0)

// LUT95H Configuration

#define	GFXMMU_LUT95H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT95H_LO_0			(0x1u<<0)

// LUT96L Configuration

#define	GFXMMU_LUT96L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT96L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT96L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT96L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT96L_EN			(0x1u<<0)

#define	GFXMMU_LUT96L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT96L_EN_B_0X1		(0x1u<<0)

// LUT96H Configuration

#define	GFXMMU_LUT96H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT96H_LO_0			(0x1u<<0)

// LUT97L Configuration

#define	GFXMMU_LUT97L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT97L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT97L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT97L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT97L_EN			(0x1u<<0)

#define	GFXMMU_LUT97L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT97L_EN_B_0X1		(0x1u<<0)

// LUT97H Configuration

#define	GFXMMU_LUT97H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT97H_LO_0			(0x1u<<0)

// LUT98L Configuration

#define	GFXMMU_LUT98L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT98L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT98L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT98L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT98L_EN			(0x1u<<0)

#define	GFXMMU_LUT98L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT98L_EN_B_0X1		(0x1u<<0)

// LUT98H Configuration

#define	GFXMMU_LUT98H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT98H_LO_0			(0x1u<<0)

// LUT99L Configuration

#define	GFXMMU_LUT99L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT99L_LVB_0			(0x1u<<16)
#define	GFXMMU_LUT99L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT99L_FVB_0			(0x1u<<8)
#define	GFXMMU_LUT99L_EN			(0x1u<<0)

#define	GFXMMU_LUT99L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT99L_EN_B_0X1		(0x1u<<0)

// LUT99H Configuration

#define	GFXMMU_LUT99H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT99H_LO_0			(0x1u<<0)

// LUT100L Configuration

#define	GFXMMU_LUT100L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT100L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT100L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT100L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT100L_EN			(0x1u<<0)

#define	GFXMMU_LUT100L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT100L_EN_B_0X1		(0x1u<<0)

// LUT100H Configuration

#define	GFXMMU_LUT100H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT100H_LO_0			(0x1u<<0)

// LUT101L Configuration

#define	GFXMMU_LUT101L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT101L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT101L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT101L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT101L_EN			(0x1u<<0)

#define	GFXMMU_LUT101L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT101L_EN_B_0X1		(0x1u<<0)

// LUT101H Configuration

#define	GFXMMU_LUT101H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT101H_LO_0			(0x1u<<0)

// LUT102L Configuration

#define	GFXMMU_LUT102L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT102L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT102L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT102L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT102L_EN			(0x1u<<0)

#define	GFXMMU_LUT102L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT102L_EN_B_0X1		(0x1u<<0)

// LUT102H Configuration

#define	GFXMMU_LUT102H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT102H_LO_0			(0x1u<<0)

// LUT103L Configuration

#define	GFXMMU_LUT103L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT103L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT103L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT103L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT103L_EN			(0x1u<<0)

#define	GFXMMU_LUT103L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT103L_EN_B_0X1		(0x1u<<0)

// LUT103H Configuration

#define	GFXMMU_LUT103H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT103H_LO_0			(0x1u<<0)

// LUT104L Configuration

#define	GFXMMU_LUT104L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT104L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT104L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT104L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT104L_EN			(0x1u<<0)

#define	GFXMMU_LUT104L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT104L_EN_B_0X1		(0x1u<<0)

// LUT104H Configuration

#define	GFXMMU_LUT104H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT104H_LO_0			(0x1u<<0)

// LUT105L Configuration

#define	GFXMMU_LUT105L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT105L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT105L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT105L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT105L_EN			(0x1u<<0)

#define	GFXMMU_LUT105L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT105L_EN_B_0X1		(0x1u<<0)

// LUT105H Configuration

#define	GFXMMU_LUT105H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT105H_LO_0			(0x1u<<0)

// LUT106L Configuration

#define	GFXMMU_LUT106L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT106L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT106L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT106L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT106L_EN			(0x1u<<0)

#define	GFXMMU_LUT106L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT106L_EN_B_0X1		(0x1u<<0)

// LUT106H Configuration

#define	GFXMMU_LUT106H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT106H_LO_0			(0x1u<<0)

// LUT107L Configuration

#define	GFXMMU_LUT107L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT107L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT107L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT107L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT107L_EN			(0x1u<<0)

#define	GFXMMU_LUT107L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT107L_EN_B_0X1		(0x1u<<0)

// LUT107H Configuration

#define	GFXMMU_LUT107H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT107H_LO_0			(0x1u<<0)

// LUT108L Configuration

#define	GFXMMU_LUT108L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT108L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT108L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT108L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT108L_EN			(0x1u<<0)

#define	GFXMMU_LUT108L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT108L_EN_B_0X1		(0x1u<<0)

// LUT108H Configuration

#define	GFXMMU_LUT108H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT108H_LO_0			(0x1u<<0)

// LUT109L Configuration

#define	GFXMMU_LUT109L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT109L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT109L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT109L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT109L_EN			(0x1u<<0)

#define	GFXMMU_LUT109L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT109L_EN_B_0X1		(0x1u<<0)

// LUT109H Configuration

#define	GFXMMU_LUT109H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT109H_LO_0			(0x1u<<0)

// LUT110L Configuration

#define	GFXMMU_LUT110L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT110L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT110L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT110L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT110L_EN			(0x1u<<0)

#define	GFXMMU_LUT110L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT110L_EN_B_0X1		(0x1u<<0)

// LUT110H Configuration

#define	GFXMMU_LUT110H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT110H_LO_0			(0x1u<<0)

// LUT111L Configuration

#define	GFXMMU_LUT111L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT111L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT111L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT111L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT111L_EN			(0x1u<<0)

#define	GFXMMU_LUT111L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT111L_EN_B_0X1		(0x1u<<0)

// LUT111H Configuration

#define	GFXMMU_LUT111H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT111H_LO_0			(0x1u<<0)

// LUT112L Configuration

#define	GFXMMU_LUT112L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT112L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT112L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT112L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT112L_EN			(0x1u<<0)

#define	GFXMMU_LUT112L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT112L_EN_B_0X1		(0x1u<<0)

// LUT112H Configuration

#define	GFXMMU_LUT112H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT112H_LO_0			(0x1u<<0)

// LUT113L Configuration

#define	GFXMMU_LUT113L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT113L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT113L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT113L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT113L_EN			(0x1u<<0)

#define	GFXMMU_LUT113L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT113L_EN_B_0X1		(0x1u<<0)

// LUT113H Configuration

#define	GFXMMU_LUT113H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT113H_LO_0			(0x1u<<0)

// LUT114L Configuration

#define	GFXMMU_LUT114L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT114L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT114L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT114L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT114L_EN			(0x1u<<0)

#define	GFXMMU_LUT114L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT114L_EN_B_0X1		(0x1u<<0)

// LUT114H Configuration

#define	GFXMMU_LUT114H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT114H_LO_0			(0x1u<<0)

// LUT115L Configuration

#define	GFXMMU_LUT115L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT115L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT115L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT115L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT115L_EN			(0x1u<<0)

#define	GFXMMU_LUT115L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT115L_EN_B_0X1		(0x1u<<0)

// LUT115H Configuration

#define	GFXMMU_LUT115H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT115H_LO_0			(0x1u<<0)

// LUT116L Configuration

#define	GFXMMU_LUT116L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT116L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT116L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT116L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT116L_EN			(0x1u<<0)

#define	GFXMMU_LUT116L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT116L_EN_B_0X1		(0x1u<<0)

// LUT116H Configuration

#define	GFXMMU_LUT116H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT116H_LO_0			(0x1u<<0)

// LUT117L Configuration

#define	GFXMMU_LUT117L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT117L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT117L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT117L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT117L_EN			(0x1u<<0)

#define	GFXMMU_LUT117L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT117L_EN_B_0X1		(0x1u<<0)

// LUT117H Configuration

#define	GFXMMU_LUT117H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT117H_LO_0			(0x1u<<0)

// LUT118L Configuration

#define	GFXMMU_LUT118L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT118L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT118L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT118L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT118L_EN			(0x1u<<0)

#define	GFXMMU_LUT118L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT118L_EN_B_0X1		(0x1u<<0)

// LUT118H Configuration

#define	GFXMMU_LUT118H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT118H_LO_0			(0x1u<<0)

// LUT119L Configuration

#define	GFXMMU_LUT119L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT119L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT119L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT119L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT119L_EN			(0x1u<<0)

#define	GFXMMU_LUT119L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT119L_EN_B_0X1		(0x1u<<0)

// LUT119H Configuration

#define	GFXMMU_LUT119H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT119H_LO_0			(0x1u<<0)

// LUT120L Configuration

#define	GFXMMU_LUT120L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT120L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT120L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT120L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT120L_EN			(0x1u<<0)

#define	GFXMMU_LUT120L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT120L_EN_B_0X1		(0x1u<<0)

// LUT120H Configuration

#define	GFXMMU_LUT120H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT120H_LO_0			(0x1u<<0)

// LUT121L Configuration

#define	GFXMMU_LUT121L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT121L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT121L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT121L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT121L_EN			(0x1u<<0)

#define	GFXMMU_LUT121L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT121L_EN_B_0X1		(0x1u<<0)

// LUT121H Configuration

#define	GFXMMU_LUT121H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT121H_LO_0			(0x1u<<0)

// LUT122L Configuration

#define	GFXMMU_LUT122L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT122L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT122L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT122L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT122L_EN			(0x1u<<0)

#define	GFXMMU_LUT122L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT122L_EN_B_0X1		(0x1u<<0)

// LUT122H Configuration

#define	GFXMMU_LUT122H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT122H_LO_0			(0x1u<<0)

// LUT123L Configuration

#define	GFXMMU_LUT123L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT123L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT123L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT123L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT123L_EN			(0x1u<<0)

#define	GFXMMU_LUT123L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT123L_EN_B_0X1		(0x1u<<0)

// LUT123H Configuration

#define	GFXMMU_LUT123H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT123H_LO_0			(0x1u<<0)

// LUT124L Configuration

#define	GFXMMU_LUT124L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT124L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT124L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT124L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT124L_EN			(0x1u<<0)

#define	GFXMMU_LUT124L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT124L_EN_B_0X1		(0x1u<<0)

// LUT124H Configuration

#define	GFXMMU_LUT124H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT124H_LO_0			(0x1u<<0)

// LUT125L Configuration

#define	GFXMMU_LUT125L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT125L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT125L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT125L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT125L_EN			(0x1u<<0)

#define	GFXMMU_LUT125L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT125L_EN_B_0X1		(0x1u<<0)

// LUT125H Configuration

#define	GFXMMU_LUT125H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT125H_LO_0			(0x1u<<0)

// LUT126L Configuration

#define	GFXMMU_LUT126L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT126L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT126L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT126L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT126L_EN			(0x1u<<0)

#define	GFXMMU_LUT126L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT126L_EN_B_0X1		(0x1u<<0)

// LUT126H Configuration

#define	GFXMMU_LUT126H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT126H_LO_0			(0x1u<<0)

// LUT127L Configuration

#define	GFXMMU_LUT127L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT127L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT127L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT127L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT127L_EN			(0x1u<<0)

#define	GFXMMU_LUT127L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT127L_EN_B_0X1		(0x1u<<0)

// LUT127H Configuration

#define	GFXMMU_LUT127H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT127H_LO_0			(0x1u<<0)

// LUT128L Configuration

#define	GFXMMU_LUT128L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT128L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT128L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT128L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT128L_EN			(0x1u<<0)

#define	GFXMMU_LUT128L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT128L_EN_B_0X1		(0x1u<<0)

// LUT128H Configuration

#define	GFXMMU_LUT128H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT128H_LO_0			(0x1u<<0)

// LUT129L Configuration

#define	GFXMMU_LUT129L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT129L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT129L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT129L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT129L_EN			(0x1u<<0)

#define	GFXMMU_LUT129L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT129L_EN_B_0X1		(0x1u<<0)

// LUT129H Configuration

#define	GFXMMU_LUT129H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT129H_LO_0			(0x1u<<0)

// LUT130L Configuration

#define	GFXMMU_LUT130L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT130L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT130L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT130L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT130L_EN			(0x1u<<0)

#define	GFXMMU_LUT130L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT130L_EN_B_0X1		(0x1u<<0)

// LUT130H Configuration

#define	GFXMMU_LUT130H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT130H_LO_0			(0x1u<<0)

// LUT131L Configuration

#define	GFXMMU_LUT131L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT131L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT131L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT131L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT131L_EN			(0x1u<<0)

#define	GFXMMU_LUT131L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT131L_EN_B_0X1		(0x1u<<0)

// LUT131H Configuration

#define	GFXMMU_LUT131H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT131H_LO_0			(0x1u<<0)

// LUT132L Configuration

#define	GFXMMU_LUT132L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT132L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT132L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT132L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT132L_EN			(0x1u<<0)

#define	GFXMMU_LUT132L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT132L_EN_B_0X1		(0x1u<<0)

// LUT132H Configuration

#define	GFXMMU_LUT132H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT132H_LO_0			(0x1u<<0)

// LUT133L Configuration

#define	GFXMMU_LUT133L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT133L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT133L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT133L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT133L_EN			(0x1u<<0)

#define	GFXMMU_LUT133L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT133L_EN_B_0X1		(0x1u<<0)

// LUT133H Configuration

#define	GFXMMU_LUT133H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT133H_LO_0			(0x1u<<0)

// LUT134L Configuration

#define	GFXMMU_LUT134L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT134L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT134L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT134L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT134L_EN			(0x1u<<0)

#define	GFXMMU_LUT134L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT134L_EN_B_0X1		(0x1u<<0)

// LUT134H Configuration

#define	GFXMMU_LUT134H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT134H_LO_0			(0x1u<<0)

// LUT135L Configuration

#define	GFXMMU_LUT135L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT135L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT135L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT135L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT135L_EN			(0x1u<<0)

#define	GFXMMU_LUT135L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT135L_EN_B_0X1		(0x1u<<0)

// LUT135H Configuration

#define	GFXMMU_LUT135H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT135H_LO_0			(0x1u<<0)

// LUT136L Configuration

#define	GFXMMU_LUT136L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT136L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT136L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT136L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT136L_EN			(0x1u<<0)

#define	GFXMMU_LUT136L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT136L_EN_B_0X1		(0x1u<<0)

// LUT136H Configuration

#define	GFXMMU_LUT136H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT136H_LO_0			(0x1u<<0)

// LUT137L Configuration

#define	GFXMMU_LUT137L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT137L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT137L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT137L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT137L_EN			(0x1u<<0)

#define	GFXMMU_LUT137L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT137L_EN_B_0X1		(0x1u<<0)

// LUT137H Configuration

#define	GFXMMU_LUT137H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT137H_LO_0			(0x1u<<0)

// LUT138L Configuration

#define	GFXMMU_LUT138L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT138L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT138L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT138L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT138L_EN			(0x1u<<0)

#define	GFXMMU_LUT138L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT138L_EN_B_0X1		(0x1u<<0)

// LUT138H Configuration

#define	GFXMMU_LUT138H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT138H_LO_0			(0x1u<<0)

// LUT139L Configuration

#define	GFXMMU_LUT139L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT139L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT139L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT139L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT139L_EN			(0x1u<<0)

#define	GFXMMU_LUT139L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT139L_EN_B_0X1		(0x1u<<0)

// LUT139H Configuration

#define	GFXMMU_LUT139H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT139H_LO_0			(0x1u<<0)

// LUT140L Configuration

#define	GFXMMU_LUT140L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT140L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT140L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT140L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT140L_EN			(0x1u<<0)

#define	GFXMMU_LUT140L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT140L_EN_B_0X1		(0x1u<<0)

// LUT140H Configuration

#define	GFXMMU_LUT140H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT140H_LO_0			(0x1u<<0)

// LUT141L Configuration

#define	GFXMMU_LUT141L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT141L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT141L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT141L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT141L_EN			(0x1u<<0)

#define	GFXMMU_LUT141L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT141L_EN_B_0X1		(0x1u<<0)

// LUT141H Configuration

#define	GFXMMU_LUT141H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT141H_LO_0			(0x1u<<0)

// LUT142L Configuration

#define	GFXMMU_LUT142L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT142L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT142L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT142L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT142L_EN			(0x1u<<0)

#define	GFXMMU_LUT142L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT142L_EN_B_0X1		(0x1u<<0)

// LUT142H Configuration

#define	GFXMMU_LUT142H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT142H_LO_0			(0x1u<<0)

// LUT143L Configuration

#define	GFXMMU_LUT143L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT143L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT143L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT143L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT143L_EN			(0x1u<<0)

#define	GFXMMU_LUT143L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT143L_EN_B_0X1		(0x1u<<0)

// LUT143H Configuration

#define	GFXMMU_LUT143H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT143H_LO_0			(0x1u<<0)

// LUT144L Configuration

#define	GFXMMU_LUT144L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT144L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT144L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT144L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT144L_EN			(0x1u<<0)

#define	GFXMMU_LUT144L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT144L_EN_B_0X1		(0x1u<<0)

// LUT144H Configuration

#define	GFXMMU_LUT144H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT144H_LO_0			(0x1u<<0)

// LUT145L Configuration

#define	GFXMMU_LUT145L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT145L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT145L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT145L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT145L_EN			(0x1u<<0)

#define	GFXMMU_LUT145L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT145L_EN_B_0X1		(0x1u<<0)

// LUT145H Configuration

#define	GFXMMU_LUT145H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT145H_LO_0			(0x1u<<0)

// LUT146L Configuration

#define	GFXMMU_LUT146L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT146L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT146L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT146L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT146L_EN			(0x1u<<0)

#define	GFXMMU_LUT146L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT146L_EN_B_0X1		(0x1u<<0)

// LUT146H Configuration

#define	GFXMMU_LUT146H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT146H_LO_0			(0x1u<<0)

// LUT147L Configuration

#define	GFXMMU_LUT147L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT147L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT147L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT147L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT147L_EN			(0x1u<<0)

#define	GFXMMU_LUT147L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT147L_EN_B_0X1		(0x1u<<0)

// LUT147H Configuration

#define	GFXMMU_LUT147H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT147H_LO_0			(0x1u<<0)

// LUT148L Configuration

#define	GFXMMU_LUT148L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT148L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT148L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT148L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT148L_EN			(0x1u<<0)

#define	GFXMMU_LUT148L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT148L_EN_B_0X1		(0x1u<<0)

// LUT148H Configuration

#define	GFXMMU_LUT148H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT148H_LO_0			(0x1u<<0)

// LUT149L Configuration

#define	GFXMMU_LUT149L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT149L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT149L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT149L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT149L_EN			(0x1u<<0)

#define	GFXMMU_LUT149L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT149L_EN_B_0X1		(0x1u<<0)

// LUT149H Configuration

#define	GFXMMU_LUT149H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT149H_LO_0			(0x1u<<0)

// LUT150L Configuration

#define	GFXMMU_LUT150L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT150L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT150L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT150L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT150L_EN			(0x1u<<0)

#define	GFXMMU_LUT150L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT150L_EN_B_0X1		(0x1u<<0)

// LUT150H Configuration

#define	GFXMMU_LUT150H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT150H_LO_0			(0x1u<<0)

// LUT151L Configuration

#define	GFXMMU_LUT151L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT151L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT151L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT151L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT151L_EN			(0x1u<<0)

#define	GFXMMU_LUT151L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT151L_EN_B_0X1		(0x1u<<0)

// LUT151H Configuration

#define	GFXMMU_LUT151H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT151H_LO_0			(0x1u<<0)

// LUT152L Configuration

#define	GFXMMU_LUT152L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT152L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT152L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT152L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT152L_EN			(0x1u<<0)

#define	GFXMMU_LUT152L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT152L_EN_B_0X1		(0x1u<<0)

// LUT152H Configuration

#define	GFXMMU_LUT152H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT152H_LO_0			(0x1u<<0)

// LUT153L Configuration

#define	GFXMMU_LUT153L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT153L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT153L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT153L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT153L_EN			(0x1u<<0)

#define	GFXMMU_LUT153L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT153L_EN_B_0X1		(0x1u<<0)

// LUT153H Configuration

#define	GFXMMU_LUT153H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT153H_LO_0			(0x1u<<0)

// LUT154L Configuration

#define	GFXMMU_LUT154L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT154L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT154L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT154L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT154L_EN			(0x1u<<0)

#define	GFXMMU_LUT154L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT154L_EN_B_0X1		(0x1u<<0)

// LUT154H Configuration

#define	GFXMMU_LUT154H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT154H_LO_0			(0x1u<<0)

// LUT155L Configuration

#define	GFXMMU_LUT155L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT155L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT155L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT155L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT155L_EN			(0x1u<<0)

#define	GFXMMU_LUT155L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT155L_EN_B_0X1		(0x1u<<0)

// LUT155H Configuration

#define	GFXMMU_LUT155H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT155H_LO_0			(0x1u<<0)

// LUT156L Configuration

#define	GFXMMU_LUT156L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT156L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT156L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT156L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT156L_EN			(0x1u<<0)

#define	GFXMMU_LUT156L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT156L_EN_B_0X1		(0x1u<<0)

// LUT156H Configuration

#define	GFXMMU_LUT156H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT156H_LO_0			(0x1u<<0)

// LUT157L Configuration

#define	GFXMMU_LUT157L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT157L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT157L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT157L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT157L_EN			(0x1u<<0)

#define	GFXMMU_LUT157L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT157L_EN_B_0X1		(0x1u<<0)

// LUT157H Configuration

#define	GFXMMU_LUT157H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT157H_LO_0			(0x1u<<0)

// LUT158L Configuration

#define	GFXMMU_LUT158L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT158L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT158L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT158L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT158L_EN			(0x1u<<0)

#define	GFXMMU_LUT158L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT158L_EN_B_0X1		(0x1u<<0)

// LUT158H Configuration

#define	GFXMMU_LUT158H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT158H_LO_0			(0x1u<<0)

// LUT159L Configuration

#define	GFXMMU_LUT159L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT159L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT159L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT159L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT159L_EN			(0x1u<<0)

#define	GFXMMU_LUT159L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT159L_EN_B_0X1		(0x1u<<0)

// LUT159H Configuration

#define	GFXMMU_LUT159H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT159H_LO_0			(0x1u<<0)

// LUT160L Configuration

#define	GFXMMU_LUT160L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT160L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT160L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT160L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT160L_EN			(0x1u<<0)

#define	GFXMMU_LUT160L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT160L_EN_B_0X1		(0x1u<<0)

// LUT160H Configuration

#define	GFXMMU_LUT160H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT160H_LO_0			(0x1u<<0)

// LUT161L Configuration

#define	GFXMMU_LUT161L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT161L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT161L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT161L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT161L_EN			(0x1u<<0)

#define	GFXMMU_LUT161L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT161L_EN_B_0X1		(0x1u<<0)

// LUT161H Configuration

#define	GFXMMU_LUT161H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT161H_LO_0			(0x1u<<0)

// LUT162L Configuration

#define	GFXMMU_LUT162L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT162L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT162L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT162L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT162L_EN			(0x1u<<0)

#define	GFXMMU_LUT162L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT162L_EN_B_0X1		(0x1u<<0)

// LUT162H Configuration

#define	GFXMMU_LUT162H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT162H_LO_0			(0x1u<<0)

// LUT163L Configuration

#define	GFXMMU_LUT163L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT163L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT163L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT163L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT163L_EN			(0x1u<<0)

#define	GFXMMU_LUT163L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT163L_EN_B_0X1		(0x1u<<0)

// LUT163H Configuration

#define	GFXMMU_LUT163H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT163H_LO_0			(0x1u<<0)

// LUT164L Configuration

#define	GFXMMU_LUT164L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT164L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT164L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT164L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT164L_EN			(0x1u<<0)

#define	GFXMMU_LUT164L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT164L_EN_B_0X1		(0x1u<<0)

// LUT164H Configuration

#define	GFXMMU_LUT164H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT164H_LO_0			(0x1u<<0)

// LUT165L Configuration

#define	GFXMMU_LUT165L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT165L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT165L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT165L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT165L_EN			(0x1u<<0)

#define	GFXMMU_LUT165L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT165L_EN_B_0X1		(0x1u<<0)

// LUT165H Configuration

#define	GFXMMU_LUT165H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT165H_LO_0			(0x1u<<0)

// LUT166L Configuration

#define	GFXMMU_LUT166L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT166L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT166L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT166L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT166L_EN			(0x1u<<0)

#define	GFXMMU_LUT166L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT166L_EN_B_0X1		(0x1u<<0)

// LUT166H Configuration

#define	GFXMMU_LUT166H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT166H_LO_0			(0x1u<<0)

// LUT167L Configuration

#define	GFXMMU_LUT167L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT167L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT167L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT167L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT167L_EN			(0x1u<<0)

#define	GFXMMU_LUT167L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT167L_EN_B_0X1		(0x1u<<0)

// LUT167H Configuration

#define	GFXMMU_LUT167H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT167H_LO_0			(0x1u<<0)

// LUT168L Configuration

#define	GFXMMU_LUT168L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT168L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT168L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT168L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT168L_EN			(0x1u<<0)

#define	GFXMMU_LUT168L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT168L_EN_B_0X1		(0x1u<<0)

// LUT168H Configuration

#define	GFXMMU_LUT168H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT168H_LO_0			(0x1u<<0)

// LUT169L Configuration

#define	GFXMMU_LUT169L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT169L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT169L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT169L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT169L_EN			(0x1u<<0)

#define	GFXMMU_LUT169L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT169L_EN_B_0X1		(0x1u<<0)

// LUT169H Configuration

#define	GFXMMU_LUT169H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT169H_LO_0			(0x1u<<0)

// LUT170L Configuration

#define	GFXMMU_LUT170L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT170L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT170L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT170L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT170L_EN			(0x1u<<0)

#define	GFXMMU_LUT170L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT170L_EN_B_0X1		(0x1u<<0)

// LUT170H Configuration

#define	GFXMMU_LUT170H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT170H_LO_0			(0x1u<<0)

// LUT171L Configuration

#define	GFXMMU_LUT171L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT171L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT171L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT171L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT171L_EN			(0x1u<<0)

#define	GFXMMU_LUT171L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT171L_EN_B_0X1		(0x1u<<0)

// LUT171H Configuration

#define	GFXMMU_LUT171H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT171H_LO_0			(0x1u<<0)

// LUT172L Configuration

#define	GFXMMU_LUT172L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT172L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT172L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT172L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT172L_EN			(0x1u<<0)

#define	GFXMMU_LUT172L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT172L_EN_B_0X1		(0x1u<<0)

// LUT172H Configuration

#define	GFXMMU_LUT172H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT172H_LO_0			(0x1u<<0)

// LUT173L Configuration

#define	GFXMMU_LUT173L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT173L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT173L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT173L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT173L_EN			(0x1u<<0)

#define	GFXMMU_LUT173L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT173L_EN_B_0X1		(0x1u<<0)

// LUT173H Configuration

#define	GFXMMU_LUT173H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT173H_LO_0			(0x1u<<0)

// LUT174L Configuration

#define	GFXMMU_LUT174L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT174L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT174L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT174L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT174L_EN			(0x1u<<0)

#define	GFXMMU_LUT174L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT174L_EN_B_0X1		(0x1u<<0)

// LUT174H Configuration

#define	GFXMMU_LUT174H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT174H_LO_0			(0x1u<<0)

// LUT175L Configuration

#define	GFXMMU_LUT175L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT175L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT175L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT175L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT175L_EN			(0x1u<<0)

#define	GFXMMU_LUT175L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT175L_EN_B_0X1		(0x1u<<0)

// LUT175H Configuration

#define	GFXMMU_LUT175H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT175H_LO_0			(0x1u<<0)

// LUT176L Configuration

#define	GFXMMU_LUT176L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT176L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT176L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT176L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT176L_EN			(0x1u<<0)

#define	GFXMMU_LUT176L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT176L_EN_B_0X1		(0x1u<<0)

// LUT176H Configuration

#define	GFXMMU_LUT176H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT176H_LO_0			(0x1u<<0)

// LUT177L Configuration

#define	GFXMMU_LUT177L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT177L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT177L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT177L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT177L_EN			(0x1u<<0)

#define	GFXMMU_LUT177L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT177L_EN_B_0X1		(0x1u<<0)

// LUT177H Configuration

#define	GFXMMU_LUT177H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT177H_LO_0			(0x1u<<0)

// LUT178L Configuration

#define	GFXMMU_LUT178L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT178L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT178L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT178L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT178L_EN			(0x1u<<0)

#define	GFXMMU_LUT178L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT178L_EN_B_0X1		(0x1u<<0)

// LUT178H Configuration

#define	GFXMMU_LUT178H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT178H_LO_0			(0x1u<<0)

// LUT179L Configuration

#define	GFXMMU_LUT179L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT179L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT179L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT179L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT179L_EN			(0x1u<<0)

#define	GFXMMU_LUT179L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT179L_EN_B_0X1		(0x1u<<0)

// LUT179H Configuration

#define	GFXMMU_LUT179H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT179H_LO_0			(0x1u<<0)

// LUT180L Configuration

#define	GFXMMU_LUT180L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT180L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT180L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT180L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT180L_EN			(0x1u<<0)

#define	GFXMMU_LUT180L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT180L_EN_B_0X1		(0x1u<<0)

// LUT180H Configuration

#define	GFXMMU_LUT180H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT180H_LO_0			(0x1u<<0)

// LUT181L Configuration

#define	GFXMMU_LUT181L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT181L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT181L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT181L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT181L_EN			(0x1u<<0)

#define	GFXMMU_LUT181L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT181L_EN_B_0X1		(0x1u<<0)

// LUT181H Configuration

#define	GFXMMU_LUT181H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT181H_LO_0			(0x1u<<0)

// LUT182L Configuration

#define	GFXMMU_LUT182L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT182L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT182L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT182L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT182L_EN			(0x1u<<0)

#define	GFXMMU_LUT182L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT182L_EN_B_0X1		(0x1u<<0)

// LUT182H Configuration

#define	GFXMMU_LUT182H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT182H_LO_0			(0x1u<<0)

// LUT183L Configuration

#define	GFXMMU_LUT183L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT183L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT183L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT183L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT183L_EN			(0x1u<<0)

#define	GFXMMU_LUT183L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT183L_EN_B_0X1		(0x1u<<0)

// LUT183H Configuration

#define	GFXMMU_LUT183H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT183H_LO_0			(0x1u<<0)

// LUT184L Configuration

#define	GFXMMU_LUT184L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT184L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT184L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT184L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT184L_EN			(0x1u<<0)

#define	GFXMMU_LUT184L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT184L_EN_B_0X1		(0x1u<<0)

// LUT184H Configuration

#define	GFXMMU_LUT184H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT184H_LO_0			(0x1u<<0)

// LUT185L Configuration

#define	GFXMMU_LUT185L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT185L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT185L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT185L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT185L_EN			(0x1u<<0)

#define	GFXMMU_LUT185L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT185L_EN_B_0X1		(0x1u<<0)

// LUT185H Configuration

#define	GFXMMU_LUT185H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT185H_LO_0			(0x1u<<0)

// LUT186L Configuration

#define	GFXMMU_LUT186L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT186L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT186L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT186L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT186L_EN			(0x1u<<0)

#define	GFXMMU_LUT186L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT186L_EN_B_0X1		(0x1u<<0)

// LUT186H Configuration

#define	GFXMMU_LUT186H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT186H_LO_0			(0x1u<<0)

// LUT187L Configuration

#define	GFXMMU_LUT187L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT187L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT187L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT187L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT187L_EN			(0x1u<<0)

#define	GFXMMU_LUT187L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT187L_EN_B_0X1		(0x1u<<0)

// LUT187H Configuration

#define	GFXMMU_LUT187H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT187H_LO_0			(0x1u<<0)

// LUT188L Configuration

#define	GFXMMU_LUT188L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT188L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT188L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT188L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT188L_EN			(0x1u<<0)

#define	GFXMMU_LUT188L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT188L_EN_B_0X1		(0x1u<<0)

// LUT188H Configuration

#define	GFXMMU_LUT188H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT188H_LO_0			(0x1u<<0)

// LUT189L Configuration

#define	GFXMMU_LUT189L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT189L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT189L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT189L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT189L_EN			(0x1u<<0)

#define	GFXMMU_LUT189L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT189L_EN_B_0X1		(0x1u<<0)

// LUT189H Configuration

#define	GFXMMU_LUT189H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT189H_LO_0			(0x1u<<0)

// LUT190L Configuration

#define	GFXMMU_LUT190L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT190L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT190L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT190L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT190L_EN			(0x1u<<0)

#define	GFXMMU_LUT190L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT190L_EN_B_0X1		(0x1u<<0)

// LUT190H Configuration

#define	GFXMMU_LUT190H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT190H_LO_0			(0x1u<<0)

// LUT191L Configuration

#define	GFXMMU_LUT191L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT191L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT191L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT191L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT191L_EN			(0x1u<<0)

#define	GFXMMU_LUT191L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT191L_EN_B_0X1		(0x1u<<0)

// LUT191H Configuration

#define	GFXMMU_LUT191H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT191H_LO_0			(0x1u<<0)

// LUT192L Configuration

#define	GFXMMU_LUT192L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT192L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT192L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT192L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT192L_EN			(0x1u<<0)

#define	GFXMMU_LUT192L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT192L_EN_B_0X1		(0x1u<<0)

// LUT192H Configuration

#define	GFXMMU_LUT192H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT192H_LO_0			(0x1u<<0)

// LUT193L Configuration

#define	GFXMMU_LUT193L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT193L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT193L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT193L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT193L_EN			(0x1u<<0)

#define	GFXMMU_LUT193L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT193L_EN_B_0X1		(0x1u<<0)

// LUT193H Configuration

#define	GFXMMU_LUT193H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT193H_LO_0			(0x1u<<0)

// LUT194L Configuration

#define	GFXMMU_LUT194L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT194L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT194L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT194L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT194L_EN			(0x1u<<0)

#define	GFXMMU_LUT194L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT194L_EN_B_0X1		(0x1u<<0)

// LUT194H Configuration

#define	GFXMMU_LUT194H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT194H_LO_0			(0x1u<<0)

// LUT195L Configuration

#define	GFXMMU_LUT195L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT195L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT195L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT195L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT195L_EN			(0x1u<<0)

#define	GFXMMU_LUT195L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT195L_EN_B_0X1		(0x1u<<0)

// LUT195H Configuration

#define	GFXMMU_LUT195H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT195H_LO_0			(0x1u<<0)

// LUT196L Configuration

#define	GFXMMU_LUT196L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT196L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT196L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT196L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT196L_EN			(0x1u<<0)

#define	GFXMMU_LUT196L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT196L_EN_B_0X1		(0x1u<<0)

// LUT196H Configuration

#define	GFXMMU_LUT196H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT196H_LO_0			(0x1u<<0)

// LUT197L Configuration

#define	GFXMMU_LUT197L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT197L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT197L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT197L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT197L_EN			(0x1u<<0)

#define	GFXMMU_LUT197L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT197L_EN_B_0X1		(0x1u<<0)

// LUT197H Configuration

#define	GFXMMU_LUT197H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT197H_LO_0			(0x1u<<0)

// LUT198L Configuration

#define	GFXMMU_LUT198L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT198L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT198L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT198L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT198L_EN			(0x1u<<0)

#define	GFXMMU_LUT198L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT198L_EN_B_0X1		(0x1u<<0)

// LUT198H Configuration

#define	GFXMMU_LUT198H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT198H_LO_0			(0x1u<<0)

// LUT199L Configuration

#define	GFXMMU_LUT199L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT199L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT199L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT199L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT199L_EN			(0x1u<<0)

#define	GFXMMU_LUT199L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT199L_EN_B_0X1		(0x1u<<0)

// LUT199H Configuration

#define	GFXMMU_LUT199H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT199H_LO_0			(0x1u<<0)

// LUT200L Configuration

#define	GFXMMU_LUT200L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT200L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT200L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT200L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT200L_EN			(0x1u<<0)

#define	GFXMMU_LUT200L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT200L_EN_B_0X1		(0x1u<<0)

// LUT200H Configuration

#define	GFXMMU_LUT200H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT200H_LO_0			(0x1u<<0)

// LUT201L Configuration

#define	GFXMMU_LUT201L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT201L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT201L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT201L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT201L_EN			(0x1u<<0)

#define	GFXMMU_LUT201L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT201L_EN_B_0X1		(0x1u<<0)

// LUT201H Configuration

#define	GFXMMU_LUT201H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT201H_LO_0			(0x1u<<0)

// LUT202L Configuration

#define	GFXMMU_LUT202L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT202L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT202L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT202L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT202L_EN			(0x1u<<0)

#define	GFXMMU_LUT202L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT202L_EN_B_0X1		(0x1u<<0)

// LUT202H Configuration

#define	GFXMMU_LUT202H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT202H_LO_0			(0x1u<<0)

// LUT203L Configuration

#define	GFXMMU_LUT203L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT203L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT203L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT203L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT203L_EN			(0x1u<<0)

#define	GFXMMU_LUT203L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT203L_EN_B_0X1		(0x1u<<0)

// LUT203H Configuration

#define	GFXMMU_LUT203H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT203H_LO_0			(0x1u<<0)

// LUT204L Configuration

#define	GFXMMU_LUT204L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT204L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT204L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT204L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT204L_EN			(0x1u<<0)

#define	GFXMMU_LUT204L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT204L_EN_B_0X1		(0x1u<<0)

// LUT204H Configuration

#define	GFXMMU_LUT204H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT204H_LO_0			(0x1u<<0)

// LUT205L Configuration

#define	GFXMMU_LUT205L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT205L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT205L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT205L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT205L_EN			(0x1u<<0)

#define	GFXMMU_LUT205L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT205L_EN_B_0X1		(0x1u<<0)

// LUT205H Configuration

#define	GFXMMU_LUT205H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT205H_LO_0			(0x1u<<0)

// LUT206L Configuration

#define	GFXMMU_LUT206L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT206L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT206L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT206L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT206L_EN			(0x1u<<0)

#define	GFXMMU_LUT206L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT206L_EN_B_0X1		(0x1u<<0)

// LUT206H Configuration

#define	GFXMMU_LUT206H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT206H_LO_0			(0x1u<<0)

// LUT207L Configuration

#define	GFXMMU_LUT207L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT207L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT207L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT207L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT207L_EN			(0x1u<<0)

#define	GFXMMU_LUT207L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT207L_EN_B_0X1		(0x1u<<0)

// LUT207H Configuration

#define	GFXMMU_LUT207H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT207H_LO_0			(0x1u<<0)

// LUT208L Configuration

#define	GFXMMU_LUT208L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT208L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT208L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT208L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT208L_EN			(0x1u<<0)

#define	GFXMMU_LUT208L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT208L_EN_B_0X1		(0x1u<<0)

// LUT208H Configuration

#define	GFXMMU_LUT208H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT208H_LO_0			(0x1u<<0)

// LUT209L Configuration

#define	GFXMMU_LUT209L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT209L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT209L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT209L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT209L_EN			(0x1u<<0)

#define	GFXMMU_LUT209L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT209L_EN_B_0X1		(0x1u<<0)

// LUT209H Configuration

#define	GFXMMU_LUT209H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT209H_LO_0			(0x1u<<0)

// LUT210L Configuration

#define	GFXMMU_LUT210L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT210L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT210L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT210L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT210L_EN			(0x1u<<0)

#define	GFXMMU_LUT210L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT210L_EN_B_0X1		(0x1u<<0)

// LUT210H Configuration

#define	GFXMMU_LUT210H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT210H_LO_0			(0x1u<<0)

// LUT211L Configuration

#define	GFXMMU_LUT211L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT211L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT211L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT211L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT211L_EN			(0x1u<<0)

#define	GFXMMU_LUT211L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT211L_EN_B_0X1		(0x1u<<0)

// LUT211H Configuration

#define	GFXMMU_LUT211H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT211H_LO_0			(0x1u<<0)

// LUT212L Configuration

#define	GFXMMU_LUT212L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT212L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT212L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT212L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT212L_EN			(0x1u<<0)

#define	GFXMMU_LUT212L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT212L_EN_B_0X1		(0x1u<<0)

// LUT212H Configuration

#define	GFXMMU_LUT212H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT212H_LO_0			(0x1u<<0)

// LUT213L Configuration

#define	GFXMMU_LUT213L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT213L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT213L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT213L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT213L_EN			(0x1u<<0)

#define	GFXMMU_LUT213L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT213L_EN_B_0X1		(0x1u<<0)

// LUT213H Configuration

#define	GFXMMU_LUT213H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT213H_LO_0			(0x1u<<0)

// LUT214L Configuration

#define	GFXMMU_LUT214L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT214L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT214L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT214L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT214L_EN			(0x1u<<0)

#define	GFXMMU_LUT214L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT214L_EN_B_0X1		(0x1u<<0)

// LUT214H Configuration

#define	GFXMMU_LUT214H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT214H_LO_0			(0x1u<<0)

// LUT215L Configuration

#define	GFXMMU_LUT215L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT215L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT215L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT215L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT215L_EN			(0x1u<<0)

#define	GFXMMU_LUT215L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT215L_EN_B_0X1		(0x1u<<0)

// LUT215H Configuration

#define	GFXMMU_LUT215H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT215H_LO_0			(0x1u<<0)

// LUT216L Configuration

#define	GFXMMU_LUT216L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT216L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT216L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT216L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT216L_EN			(0x1u<<0)

#define	GFXMMU_LUT216L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT216L_EN_B_0X1		(0x1u<<0)

// LUT216H Configuration

#define	GFXMMU_LUT216H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT216H_LO_0			(0x1u<<0)

// LUT217L Configuration

#define	GFXMMU_LUT217L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT217L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT217L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT217L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT217L_EN			(0x1u<<0)

#define	GFXMMU_LUT217L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT217L_EN_B_0X1		(0x1u<<0)

// LUT217H Configuration

#define	GFXMMU_LUT217H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT217H_LO_0			(0x1u<<0)

// LUT218L Configuration

#define	GFXMMU_LUT218L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT218L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT218L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT218L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT218L_EN			(0x1u<<0)

#define	GFXMMU_LUT218L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT218L_EN_B_0X1		(0x1u<<0)

// LUT218H Configuration

#define	GFXMMU_LUT218H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT218H_LO_0			(0x1u<<0)

// LUT219L Configuration

#define	GFXMMU_LUT219L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT219L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT219L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT219L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT219L_EN			(0x1u<<0)

#define	GFXMMU_LUT219L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT219L_EN_B_0X1		(0x1u<<0)

// LUT219H Configuration

#define	GFXMMU_LUT219H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT219H_LO_0			(0x1u<<0)

// LUT220L Configuration

#define	GFXMMU_LUT220L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT220L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT220L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT220L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT220L_EN			(0x1u<<0)

#define	GFXMMU_LUT220L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT220L_EN_B_0X1		(0x1u<<0)

// LUT220H Configuration

#define	GFXMMU_LUT220H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT220H_LO_0			(0x1u<<0)

// LUT221L Configuration

#define	GFXMMU_LUT221L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT221L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT221L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT221L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT221L_EN			(0x1u<<0)

#define	GFXMMU_LUT221L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT221L_EN_B_0X1		(0x1u<<0)

// LUT221H Configuration

#define	GFXMMU_LUT221H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT221H_LO_0			(0x1u<<0)

// LUT222L Configuration

#define	GFXMMU_LUT222L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT222L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT222L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT222L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT222L_EN			(0x1u<<0)

#define	GFXMMU_LUT222L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT222L_EN_B_0X1		(0x1u<<0)

// LUT222H Configuration

#define	GFXMMU_LUT222H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT222H_LO_0			(0x1u<<0)

// LUT223L Configuration

#define	GFXMMU_LUT223L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT223L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT223L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT223L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT223L_EN			(0x1u<<0)

#define	GFXMMU_LUT223L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT223L_EN_B_0X1		(0x1u<<0)

// LUT223H Configuration

#define	GFXMMU_LUT223H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT223H_LO_0			(0x1u<<0)

// LUT224L Configuration

#define	GFXMMU_LUT224L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT224L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT224L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT224L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT224L_EN			(0x1u<<0)

#define	GFXMMU_LUT224L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT224L_EN_B_0X1		(0x1u<<0)

// LUT224H Configuration

#define	GFXMMU_LUT224H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT224H_LO_0			(0x1u<<0)

// LUT225L Configuration

#define	GFXMMU_LUT225L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT225L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT225L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT225L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT225L_EN			(0x1u<<0)

#define	GFXMMU_LUT225L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT225L_EN_B_0X1		(0x1u<<0)

// LUT225H Configuration

#define	GFXMMU_LUT225H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT225H_LO_0			(0x1u<<0)

// LUT226L Configuration

#define	GFXMMU_LUT226L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT226L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT226L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT226L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT226L_EN			(0x1u<<0)

#define	GFXMMU_LUT226L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT226L_EN_B_0X1		(0x1u<<0)

// LUT226H Configuration

#define	GFXMMU_LUT226H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT226H_LO_0			(0x1u<<0)

// LUT227L Configuration

#define	GFXMMU_LUT227L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT227L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT227L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT227L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT227L_EN			(0x1u<<0)

#define	GFXMMU_LUT227L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT227L_EN_B_0X1		(0x1u<<0)

// LUT227H Configuration

#define	GFXMMU_LUT227H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT227H_LO_0			(0x1u<<0)

// LUT228L Configuration

#define	GFXMMU_LUT228L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT228L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT228L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT228L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT228L_EN			(0x1u<<0)

#define	GFXMMU_LUT228L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT228L_EN_B_0X1		(0x1u<<0)

// LUT228H Configuration

#define	GFXMMU_LUT228H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT228H_LO_0			(0x1u<<0)

// LUT229L Configuration

#define	GFXMMU_LUT229L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT229L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT229L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT229L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT229L_EN			(0x1u<<0)

#define	GFXMMU_LUT229L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT229L_EN_B_0X1		(0x1u<<0)

// LUT229H Configuration

#define	GFXMMU_LUT229H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT229H_LO_0			(0x1u<<0)

// LUT230L Configuration

#define	GFXMMU_LUT230L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT230L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT230L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT230L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT230L_EN			(0x1u<<0)

#define	GFXMMU_LUT230L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT230L_EN_B_0X1		(0x1u<<0)

// LUT230H Configuration

#define	GFXMMU_LUT230H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT230H_LO_0			(0x1u<<0)

// LUT231L Configuration

#define	GFXMMU_LUT231L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT231L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT231L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT231L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT231L_EN			(0x1u<<0)

#define	GFXMMU_LUT231L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT231L_EN_B_0X1		(0x1u<<0)

// LUT231H Configuration

#define	GFXMMU_LUT231H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT231H_LO_0			(0x1u<<0)

// LUT232L Configuration

#define	GFXMMU_LUT232L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT232L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT232L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT232L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT232L_EN			(0x1u<<0)

#define	GFXMMU_LUT232L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT232L_EN_B_0X1		(0x1u<<0)

// LUT232H Configuration

#define	GFXMMU_LUT232H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT232H_LO_0			(0x1u<<0)

// LUT233L Configuration

#define	GFXMMU_LUT233L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT233L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT233L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT233L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT233L_EN			(0x1u<<0)

#define	GFXMMU_LUT233L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT233L_EN_B_0X1		(0x1u<<0)

// LUT233H Configuration

#define	GFXMMU_LUT233H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT233H_LO_0			(0x1u<<0)

// LUT234L Configuration

#define	GFXMMU_LUT234L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT234L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT234L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT234L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT234L_EN			(0x1u<<0)

#define	GFXMMU_LUT234L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT234L_EN_B_0X1		(0x1u<<0)

// LUT234H Configuration

#define	GFXMMU_LUT234H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT234H_LO_0			(0x1u<<0)

// LUT235L Configuration

#define	GFXMMU_LUT235L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT235L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT235L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT235L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT235L_EN			(0x1u<<0)

#define	GFXMMU_LUT235L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT235L_EN_B_0X1		(0x1u<<0)

// LUT235H Configuration

#define	GFXMMU_LUT235H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT235H_LO_0			(0x1u<<0)

// LUT236L Configuration

#define	GFXMMU_LUT236L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT236L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT236L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT236L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT236L_EN			(0x1u<<0)

#define	GFXMMU_LUT236L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT236L_EN_B_0X1		(0x1u<<0)

// LUT236H Configuration

#define	GFXMMU_LUT236H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT236H_LO_0			(0x1u<<0)

// LUT237L Configuration

#define	GFXMMU_LUT237L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT237L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT237L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT237L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT237L_EN			(0x1u<<0)

#define	GFXMMU_LUT237L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT237L_EN_B_0X1		(0x1u<<0)

// LUT237H Configuration

#define	GFXMMU_LUT237H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT237H_LO_0			(0x1u<<0)

// LUT238L Configuration

#define	GFXMMU_LUT238L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT238L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT238L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT238L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT238L_EN			(0x1u<<0)

#define	GFXMMU_LUT238L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT238L_EN_B_0X1		(0x1u<<0)

// LUT238H Configuration

#define	GFXMMU_LUT238H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT238H_LO_0			(0x1u<<0)

// LUT239L Configuration

#define	GFXMMU_LUT239L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT239L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT239L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT239L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT239L_EN			(0x1u<<0)

#define	GFXMMU_LUT239L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT239L_EN_B_0X1		(0x1u<<0)

// LUT239H Configuration

#define	GFXMMU_LUT239H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT239H_LO_0			(0x1u<<0)

// LUT240L Configuration

#define	GFXMMU_LUT240L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT240L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT240L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT240L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT240L_EN			(0x1u<<0)

#define	GFXMMU_LUT240L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT240L_EN_B_0X1		(0x1u<<0)

// LUT240H Configuration

#define	GFXMMU_LUT240H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT240H_LO_0			(0x1u<<0)

// LUT241L Configuration

#define	GFXMMU_LUT241L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT241L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT241L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT241L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT241L_EN			(0x1u<<0)

#define	GFXMMU_LUT241L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT241L_EN_B_0X1		(0x1u<<0)

// LUT241H Configuration

#define	GFXMMU_LUT241H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT241H_LO_0			(0x1u<<0)

// LUT242L Configuration

#define	GFXMMU_LUT242L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT242L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT242L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT242L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT242L_EN			(0x1u<<0)

#define	GFXMMU_LUT242L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT242L_EN_B_0X1		(0x1u<<0)

// LUT242H Configuration

#define	GFXMMU_LUT242H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT242H_LO_0			(0x1u<<0)

// LUT243L Configuration

#define	GFXMMU_LUT243L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT243L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT243L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT243L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT243L_EN			(0x1u<<0)

#define	GFXMMU_LUT243L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT243L_EN_B_0X1		(0x1u<<0)

// LUT243H Configuration

#define	GFXMMU_LUT243H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT243H_LO_0			(0x1u<<0)

// LUT244L Configuration

#define	GFXMMU_LUT244L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT244L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT244L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT244L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT244L_EN			(0x1u<<0)

#define	GFXMMU_LUT244L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT244L_EN_B_0X1		(0x1u<<0)

// LUT244H Configuration

#define	GFXMMU_LUT244H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT244H_LO_0			(0x1u<<0)

// LUT245L Configuration

#define	GFXMMU_LUT245L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT245L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT245L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT245L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT245L_EN			(0x1u<<0)

#define	GFXMMU_LUT245L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT245L_EN_B_0X1		(0x1u<<0)

// LUT245H Configuration

#define	GFXMMU_LUT245H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT245H_LO_0			(0x1u<<0)

// LUT246L Configuration

#define	GFXMMU_LUT246L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT246L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT246L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT246L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT246L_EN			(0x1u<<0)

#define	GFXMMU_LUT246L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT246L_EN_B_0X1		(0x1u<<0)

// LUT246H Configuration

#define	GFXMMU_LUT246H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT246H_LO_0			(0x1u<<0)

// LUT247L Configuration

#define	GFXMMU_LUT247L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT247L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT247L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT247L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT247L_EN			(0x1u<<0)

#define	GFXMMU_LUT247L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT247L_EN_B_0X1		(0x1u<<0)

// LUT247H Configuration

#define	GFXMMU_LUT247H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT247H_LO_0			(0x1u<<0)

// LUT248L Configuration

#define	GFXMMU_LUT248L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT248L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT248L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT248L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT248L_EN			(0x1u<<0)

#define	GFXMMU_LUT248L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT248L_EN_B_0X1		(0x1u<<0)

// LUT248H Configuration

#define	GFXMMU_LUT248H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT248H_LO_0			(0x1u<<0)

// LUT249L Configuration

#define	GFXMMU_LUT249L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT249L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT249L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT249L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT249L_EN			(0x1u<<0)

#define	GFXMMU_LUT249L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT249L_EN_B_0X1		(0x1u<<0)

// LUT249H Configuration

#define	GFXMMU_LUT249H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT249H_LO_0			(0x1u<<0)

// LUT250L Configuration

#define	GFXMMU_LUT250L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT250L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT250L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT250L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT250L_EN			(0x1u<<0)

#define	GFXMMU_LUT250L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT250L_EN_B_0X1		(0x1u<<0)

// LUT250H Configuration

#define	GFXMMU_LUT250H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT250H_LO_0			(0x1u<<0)

// LUT251L Configuration

#define	GFXMMU_LUT251L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT251L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT251L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT251L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT251L_EN			(0x1u<<0)

#define	GFXMMU_LUT251L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT251L_EN_B_0X1		(0x1u<<0)

// LUT251H Configuration

#define	GFXMMU_LUT251H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT251H_LO_0			(0x1u<<0)

// LUT252L Configuration

#define	GFXMMU_LUT252L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT252L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT252L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT252L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT252L_EN			(0x1u<<0)

#define	GFXMMU_LUT252L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT252L_EN_B_0X1		(0x1u<<0)

// LUT252H Configuration

#define	GFXMMU_LUT252H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT252H_LO_0			(0x1u<<0)

// LUT253L Configuration

#define	GFXMMU_LUT253L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT253L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT253L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT253L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT253L_EN			(0x1u<<0)

#define	GFXMMU_LUT253L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT253L_EN_B_0X1		(0x1u<<0)

// LUT253H Configuration

#define	GFXMMU_LUT253H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT253H_LO_0			(0x1u<<0)

// LUT254L Configuration

#define	GFXMMU_LUT254L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT254L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT254L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT254L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT254L_EN			(0x1u<<0)

#define	GFXMMU_LUT254L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT254L_EN_B_0X1		(0x1u<<0)

// LUT254H Configuration

#define	GFXMMU_LUT254H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT254H_LO_0			(0x1u<<0)

// LUT255L Configuration

#define	GFXMMU_LUT255L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT255L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT255L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT255L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT255L_EN			(0x1u<<0)

#define	GFXMMU_LUT255L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT255L_EN_B_0X1		(0x1u<<0)

// LUT255H Configuration

#define	GFXMMU_LUT255H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT255H_LO_0			(0x1u<<0)

// LUT256L Configuration

#define	GFXMMU_LUT256L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT256L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT256L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT256L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT256L_EN			(0x1u<<0)

#define	GFXMMU_LUT256L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT256L_EN_B_0X1		(0x1u<<0)

// LUT256H Configuration

#define	GFXMMU_LUT256H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT256H_LO_0			(0x1u<<0)

// LUT257L Configuration

#define	GFXMMU_LUT257L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT257L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT257L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT257L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT257L_EN			(0x1u<<0)

#define	GFXMMU_LUT257L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT257L_EN_B_0X1		(0x1u<<0)

// LUT257H Configuration

#define	GFXMMU_LUT257H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT257H_LO_0			(0x1u<<0)

// LUT258L Configuration

#define	GFXMMU_LUT258L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT258L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT258L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT258L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT258L_EN			(0x1u<<0)

#define	GFXMMU_LUT258L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT258L_EN_B_0X1		(0x1u<<0)

// LUT258H Configuration

#define	GFXMMU_LUT258H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT258H_LO_0			(0x1u<<0)

// LUT259L Configuration

#define	GFXMMU_LUT259L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT259L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT259L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT259L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT259L_EN			(0x1u<<0)

#define	GFXMMU_LUT259L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT259L_EN_B_0X1		(0x1u<<0)

// LUT259H Configuration

#define	GFXMMU_LUT259H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT259H_LO_0			(0x1u<<0)

// LUT260L Configuration

#define	GFXMMU_LUT260L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT260L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT260L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT260L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT260L_EN			(0x1u<<0)

#define	GFXMMU_LUT260L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT260L_EN_B_0X1		(0x1u<<0)

// LUT260H Configuration

#define	GFXMMU_LUT260H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT260H_LO_0			(0x1u<<0)

// LUT261L Configuration

#define	GFXMMU_LUT261L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT261L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT261L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT261L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT261L_EN			(0x1u<<0)

#define	GFXMMU_LUT261L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT261L_EN_B_0X1		(0x1u<<0)

// LUT261H Configuration

#define	GFXMMU_LUT261H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT261H_LO_0			(0x1u<<0)

// LUT262L Configuration

#define	GFXMMU_LUT262L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT262L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT262L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT262L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT262L_EN			(0x1u<<0)

#define	GFXMMU_LUT262L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT262L_EN_B_0X1		(0x1u<<0)

// LUT262H Configuration

#define	GFXMMU_LUT262H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT262H_LO_0			(0x1u<<0)

// LUT263L Configuration

#define	GFXMMU_LUT263L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT263L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT263L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT263L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT263L_EN			(0x1u<<0)

#define	GFXMMU_LUT263L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT263L_EN_B_0X1		(0x1u<<0)

// LUT263H Configuration

#define	GFXMMU_LUT263H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT263H_LO_0			(0x1u<<0)

// LUT264L Configuration

#define	GFXMMU_LUT264L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT264L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT264L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT264L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT264L_EN			(0x1u<<0)

#define	GFXMMU_LUT264L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT264L_EN_B_0X1		(0x1u<<0)

// LUT264H Configuration

#define	GFXMMU_LUT264H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT264H_LO_0			(0x1u<<0)

// LUT265L Configuration

#define	GFXMMU_LUT265L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT265L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT265L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT265L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT265L_EN			(0x1u<<0)

#define	GFXMMU_LUT265L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT265L_EN_B_0X1		(0x1u<<0)

// LUT265H Configuration

#define	GFXMMU_LUT265H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT265H_LO_0			(0x1u<<0)

// LUT266L Configuration

#define	GFXMMU_LUT266L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT266L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT266L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT266L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT266L_EN			(0x1u<<0)

#define	GFXMMU_LUT266L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT266L_EN_B_0X1		(0x1u<<0)

// LUT266H Configuration

#define	GFXMMU_LUT266H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT266H_LO_0			(0x1u<<0)

// LUT267L Configuration

#define	GFXMMU_LUT267L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT267L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT267L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT267L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT267L_EN			(0x1u<<0)

#define	GFXMMU_LUT267L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT267L_EN_B_0X1		(0x1u<<0)

// LUT267H Configuration

#define	GFXMMU_LUT267H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT267H_LO_0			(0x1u<<0)

// LUT268L Configuration

#define	GFXMMU_LUT268L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT268L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT268L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT268L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT268L_EN			(0x1u<<0)

#define	GFXMMU_LUT268L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT268L_EN_B_0X1		(0x1u<<0)

// LUT268H Configuration

#define	GFXMMU_LUT268H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT268H_LO_0			(0x1u<<0)

// LUT269L Configuration

#define	GFXMMU_LUT269L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT269L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT269L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT269L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT269L_EN			(0x1u<<0)

#define	GFXMMU_LUT269L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT269L_EN_B_0X1		(0x1u<<0)

// LUT269H Configuration

#define	GFXMMU_LUT269H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT269H_LO_0			(0x1u<<0)

// LUT270L Configuration

#define	GFXMMU_LUT270L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT270L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT270L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT270L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT270L_EN			(0x1u<<0)

#define	GFXMMU_LUT270L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT270L_EN_B_0X1		(0x1u<<0)

// LUT270H Configuration

#define	GFXMMU_LUT270H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT270H_LO_0			(0x1u<<0)

// LUT271L Configuration

#define	GFXMMU_LUT271L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT271L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT271L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT271L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT271L_EN			(0x1u<<0)

#define	GFXMMU_LUT271L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT271L_EN_B_0X1		(0x1u<<0)

// LUT271H Configuration

#define	GFXMMU_LUT271H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT271H_LO_0			(0x1u<<0)

// LUT272L Configuration

#define	GFXMMU_LUT272L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT272L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT272L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT272L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT272L_EN			(0x1u<<0)

#define	GFXMMU_LUT272L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT272L_EN_B_0X1		(0x1u<<0)

// LUT272H Configuration

#define	GFXMMU_LUT272H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT272H_LO_0			(0x1u<<0)

// LUT273L Configuration

#define	GFXMMU_LUT273L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT273L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT273L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT273L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT273L_EN			(0x1u<<0)

#define	GFXMMU_LUT273L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT273L_EN_B_0X1		(0x1u<<0)

// LUT273H Configuration

#define	GFXMMU_LUT273H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT273H_LO_0			(0x1u<<0)

// LUT274L Configuration

#define	GFXMMU_LUT274L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT274L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT274L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT274L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT274L_EN			(0x1u<<0)

#define	GFXMMU_LUT274L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT274L_EN_B_0X1		(0x1u<<0)

// LUT274H Configuration

#define	GFXMMU_LUT274H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT274H_LO_0			(0x1u<<0)

// LUT275L Configuration

#define	GFXMMU_LUT275L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT275L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT275L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT275L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT275L_EN			(0x1u<<0)

#define	GFXMMU_LUT275L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT275L_EN_B_0X1		(0x1u<<0)

// LUT275H Configuration

#define	GFXMMU_LUT275H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT275H_LO_0			(0x1u<<0)

// LUT276L Configuration

#define	GFXMMU_LUT276L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT276L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT276L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT276L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT276L_EN			(0x1u<<0)

#define	GFXMMU_LUT276L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT276L_EN_B_0X1		(0x1u<<0)

// LUT276H Configuration

#define	GFXMMU_LUT276H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT276H_LO_0			(0x1u<<0)

// LUT277L Configuration

#define	GFXMMU_LUT277L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT277L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT277L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT277L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT277L_EN			(0x1u<<0)

#define	GFXMMU_LUT277L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT277L_EN_B_0X1		(0x1u<<0)

// LUT277H Configuration

#define	GFXMMU_LUT277H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT277H_LO_0			(0x1u<<0)

// LUT278L Configuration

#define	GFXMMU_LUT278L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT278L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT278L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT278L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT278L_EN			(0x1u<<0)

#define	GFXMMU_LUT278L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT278L_EN_B_0X1		(0x1u<<0)

// LUT278H Configuration

#define	GFXMMU_LUT278H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT278H_LO_0			(0x1u<<0)

// LUT279L Configuration

#define	GFXMMU_LUT279L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT279L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT279L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT279L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT279L_EN			(0x1u<<0)

#define	GFXMMU_LUT279L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT279L_EN_B_0X1		(0x1u<<0)

// LUT279H Configuration

#define	GFXMMU_LUT279H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT279H_LO_0			(0x1u<<0)

// LUT280L Configuration

#define	GFXMMU_LUT280L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT280L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT280L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT280L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT280L_EN			(0x1u<<0)

#define	GFXMMU_LUT280L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT280L_EN_B_0X1		(0x1u<<0)

// LUT280H Configuration

#define	GFXMMU_LUT280H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT280H_LO_0			(0x1u<<0)

// LUT281L Configuration

#define	GFXMMU_LUT281L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT281L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT281L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT281L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT281L_EN			(0x1u<<0)

#define	GFXMMU_LUT281L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT281L_EN_B_0X1		(0x1u<<0)

// LUT281H Configuration

#define	GFXMMU_LUT281H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT281H_LO_0			(0x1u<<0)

// LUT282L Configuration

#define	GFXMMU_LUT282L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT282L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT282L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT282L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT282L_EN			(0x1u<<0)

#define	GFXMMU_LUT282L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT282L_EN_B_0X1		(0x1u<<0)

// LUT282H Configuration

#define	GFXMMU_LUT282H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT282H_LO_0			(0x1u<<0)

// LUT283L Configuration

#define	GFXMMU_LUT283L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT283L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT283L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT283L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT283L_EN			(0x1u<<0)

#define	GFXMMU_LUT283L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT283L_EN_B_0X1		(0x1u<<0)

// LUT283H Configuration

#define	GFXMMU_LUT283H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT283H_LO_0			(0x1u<<0)

// LUT284L Configuration

#define	GFXMMU_LUT284L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT284L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT284L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT284L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT284L_EN			(0x1u<<0)

#define	GFXMMU_LUT284L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT284L_EN_B_0X1		(0x1u<<0)

// LUT284H Configuration

#define	GFXMMU_LUT284H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT284H_LO_0			(0x1u<<0)

// LUT285L Configuration

#define	GFXMMU_LUT285L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT285L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT285L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT285L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT285L_EN			(0x1u<<0)

#define	GFXMMU_LUT285L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT285L_EN_B_0X1		(0x1u<<0)

// LUT285H Configuration

#define	GFXMMU_LUT285H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT285H_LO_0			(0x1u<<0)

// LUT286L Configuration

#define	GFXMMU_LUT286L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT286L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT286L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT286L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT286L_EN			(0x1u<<0)

#define	GFXMMU_LUT286L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT286L_EN_B_0X1		(0x1u<<0)

// LUT286H Configuration

#define	GFXMMU_LUT286H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT286H_LO_0			(0x1u<<0)

// LUT287L Configuration

#define	GFXMMU_LUT287L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT287L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT287L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT287L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT287L_EN			(0x1u<<0)

#define	GFXMMU_LUT287L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT287L_EN_B_0X1		(0x1u<<0)

// LUT287H Configuration

#define	GFXMMU_LUT287H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT287H_LO_0			(0x1u<<0)

// LUT288L Configuration

#define	GFXMMU_LUT288L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT288L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT288L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT288L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT288L_EN			(0x1u<<0)

#define	GFXMMU_LUT288L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT288L_EN_B_0X1		(0x1u<<0)

// LUT288H Configuration

#define	GFXMMU_LUT288H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT288H_LO_0			(0x1u<<0)

// LUT289L Configuration

#define	GFXMMU_LUT289L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT289L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT289L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT289L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT289L_EN			(0x1u<<0)

#define	GFXMMU_LUT289L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT289L_EN_B_0X1		(0x1u<<0)

// LUT289H Configuration

#define	GFXMMU_LUT289H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT289H_LO_0			(0x1u<<0)

// LUT290L Configuration

#define	GFXMMU_LUT290L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT290L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT290L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT290L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT290L_EN			(0x1u<<0)

#define	GFXMMU_LUT290L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT290L_EN_B_0X1		(0x1u<<0)

// LUT290H Configuration

#define	GFXMMU_LUT290H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT290H_LO_0			(0x1u<<0)

// LUT291L Configuration

#define	GFXMMU_LUT291L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT291L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT291L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT291L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT291L_EN			(0x1u<<0)

#define	GFXMMU_LUT291L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT291L_EN_B_0X1		(0x1u<<0)

// LUT291H Configuration

#define	GFXMMU_LUT291H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT291H_LO_0			(0x1u<<0)

// LUT292L Configuration

#define	GFXMMU_LUT292L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT292L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT292L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT292L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT292L_EN			(0x1u<<0)

#define	GFXMMU_LUT292L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT292L_EN_B_0X1		(0x1u<<0)

// LUT292H Configuration

#define	GFXMMU_LUT292H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT292H_LO_0			(0x1u<<0)

// LUT293L Configuration

#define	GFXMMU_LUT293L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT293L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT293L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT293L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT293L_EN			(0x1u<<0)

#define	GFXMMU_LUT293L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT293L_EN_B_0X1		(0x1u<<0)

// LUT293H Configuration

#define	GFXMMU_LUT293H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT293H_LO_0			(0x1u<<0)

// LUT294L Configuration

#define	GFXMMU_LUT294L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT294L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT294L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT294L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT294L_EN			(0x1u<<0)

#define	GFXMMU_LUT294L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT294L_EN_B_0X1		(0x1u<<0)

// LUT294H Configuration

#define	GFXMMU_LUT294H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT294H_LO_0			(0x1u<<0)

// LUT295L Configuration

#define	GFXMMU_LUT295L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT295L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT295L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT295L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT295L_EN			(0x1u<<0)

#define	GFXMMU_LUT295L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT295L_EN_B_0X1		(0x1u<<0)

// LUT295H Configuration

#define	GFXMMU_LUT295H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT295H_LO_0			(0x1u<<0)

// LUT296L Configuration

#define	GFXMMU_LUT296L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT296L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT296L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT296L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT296L_EN			(0x1u<<0)

#define	GFXMMU_LUT296L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT296L_EN_B_0X1		(0x1u<<0)

// LUT296H Configuration

#define	GFXMMU_LUT296H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT296H_LO_0			(0x1u<<0)

// LUT297L Configuration

#define	GFXMMU_LUT297L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT297L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT297L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT297L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT297L_EN			(0x1u<<0)

#define	GFXMMU_LUT297L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT297L_EN_B_0X1		(0x1u<<0)

// LUT297H Configuration

#define	GFXMMU_LUT297H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT297H_LO_0			(0x1u<<0)

// LUT298L Configuration

#define	GFXMMU_LUT298L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT298L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT298L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT298L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT298L_EN			(0x1u<<0)

#define	GFXMMU_LUT298L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT298L_EN_B_0X1		(0x1u<<0)

// LUT298H Configuration

#define	GFXMMU_LUT298H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT298H_LO_0			(0x1u<<0)

// LUT299L Configuration

#define	GFXMMU_LUT299L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT299L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT299L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT299L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT299L_EN			(0x1u<<0)

#define	GFXMMU_LUT299L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT299L_EN_B_0X1		(0x1u<<0)

// LUT299H Configuration

#define	GFXMMU_LUT299H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT299H_LO_0			(0x1u<<0)

// LUT300L Configuration

#define	GFXMMU_LUT300L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT300L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT300L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT300L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT300L_EN			(0x1u<<0)

#define	GFXMMU_LUT300L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT300L_EN_B_0X1		(0x1u<<0)

// LUT300H Configuration

#define	GFXMMU_LUT300H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT300H_LO_0			(0x1u<<0)

// LUT301L Configuration

#define	GFXMMU_LUT301L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT301L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT301L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT301L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT301L_EN			(0x1u<<0)

#define	GFXMMU_LUT301L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT301L_EN_B_0X1		(0x1u<<0)

// LUT301H Configuration

#define	GFXMMU_LUT301H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT301H_LO_0			(0x1u<<0)

// LUT302L Configuration

#define	GFXMMU_LUT302L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT302L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT302L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT302L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT302L_EN			(0x1u<<0)

#define	GFXMMU_LUT302L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT302L_EN_B_0X1		(0x1u<<0)

// LUT302H Configuration

#define	GFXMMU_LUT302H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT302H_LO_0			(0x1u<<0)

// LUT303L Configuration

#define	GFXMMU_LUT303L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT303L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT303L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT303L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT303L_EN			(0x1u<<0)

#define	GFXMMU_LUT303L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT303L_EN_B_0X1		(0x1u<<0)

// LUT303H Configuration

#define	GFXMMU_LUT303H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT303H_LO_0			(0x1u<<0)

// LUT304L Configuration

#define	GFXMMU_LUT304L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT304L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT304L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT304L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT304L_EN			(0x1u<<0)

#define	GFXMMU_LUT304L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT304L_EN_B_0X1		(0x1u<<0)

// LUT304H Configuration

#define	GFXMMU_LUT304H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT304H_LO_0			(0x1u<<0)

// LUT305L Configuration

#define	GFXMMU_LUT305L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT305L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT305L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT305L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT305L_EN			(0x1u<<0)

#define	GFXMMU_LUT305L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT305L_EN_B_0X1		(0x1u<<0)

// LUT305H Configuration

#define	GFXMMU_LUT305H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT305H_LO_0			(0x1u<<0)

// LUT306L Configuration

#define	GFXMMU_LUT306L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT306L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT306L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT306L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT306L_EN			(0x1u<<0)

#define	GFXMMU_LUT306L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT306L_EN_B_0X1		(0x1u<<0)

// LUT306H Configuration

#define	GFXMMU_LUT306H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT306H_LO_0			(0x1u<<0)

// LUT307L Configuration

#define	GFXMMU_LUT307L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT307L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT307L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT307L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT307L_EN			(0x1u<<0)

#define	GFXMMU_LUT307L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT307L_EN_B_0X1		(0x1u<<0)

// LUT307H Configuration

#define	GFXMMU_LUT307H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT307H_LO_0			(0x1u<<0)

// LUT308L Configuration

#define	GFXMMU_LUT308L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT308L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT308L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT308L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT308L_EN			(0x1u<<0)

#define	GFXMMU_LUT308L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT308L_EN_B_0X1		(0x1u<<0)

// LUT308H Configuration

#define	GFXMMU_LUT308H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT308H_LO_0			(0x1u<<0)

// LUT309L Configuration

#define	GFXMMU_LUT309L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT309L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT309L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT309L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT309L_EN			(0x1u<<0)

#define	GFXMMU_LUT309L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT309L_EN_B_0X1		(0x1u<<0)

// LUT309H Configuration

#define	GFXMMU_LUT309H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT309H_LO_0			(0x1u<<0)

// LUT310L Configuration

#define	GFXMMU_LUT310L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT310L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT310L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT310L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT310L_EN			(0x1u<<0)

#define	GFXMMU_LUT310L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT310L_EN_B_0X1		(0x1u<<0)

// LUT310H Configuration

#define	GFXMMU_LUT310H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT310H_LO_0			(0x1u<<0)

// LUT311L Configuration

#define	GFXMMU_LUT311L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT311L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT311L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT311L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT311L_EN			(0x1u<<0)

#define	GFXMMU_LUT311L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT311L_EN_B_0X1		(0x1u<<0)

// LUT311H Configuration

#define	GFXMMU_LUT311H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT311H_LO_0			(0x1u<<0)

// LUT312L Configuration

#define	GFXMMU_LUT312L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT312L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT312L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT312L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT312L_EN			(0x1u<<0)

#define	GFXMMU_LUT312L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT312L_EN_B_0X1		(0x1u<<0)

// LUT312H Configuration

#define	GFXMMU_LUT312H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT312H_LO_0			(0x1u<<0)

// LUT313L Configuration

#define	GFXMMU_LUT313L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT313L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT313L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT313L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT313L_EN			(0x1u<<0)

#define	GFXMMU_LUT313L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT313L_EN_B_0X1		(0x1u<<0)

// LUT313H Configuration

#define	GFXMMU_LUT313H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT313H_LO_0			(0x1u<<0)

// LUT314L Configuration

#define	GFXMMU_LUT314L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT314L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT314L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT314L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT314L_EN			(0x1u<<0)

#define	GFXMMU_LUT314L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT314L_EN_B_0X1		(0x1u<<0)

// LUT314H Configuration

#define	GFXMMU_LUT314H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT314H_LO_0			(0x1u<<0)

// LUT315L Configuration

#define	GFXMMU_LUT315L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT315L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT315L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT315L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT315L_EN			(0x1u<<0)

#define	GFXMMU_LUT315L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT315L_EN_B_0X1		(0x1u<<0)

// LUT315H Configuration

#define	GFXMMU_LUT315H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT315H_LO_0			(0x1u<<0)

// LUT316L Configuration

#define	GFXMMU_LUT316L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT316L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT316L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT316L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT316L_EN			(0x1u<<0)

#define	GFXMMU_LUT316L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT316L_EN_B_0X1		(0x1u<<0)

// LUT316H Configuration

#define	GFXMMU_LUT316H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT316H_LO_0			(0x1u<<0)

// LUT317L Configuration

#define	GFXMMU_LUT317L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT317L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT317L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT317L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT317L_EN			(0x1u<<0)

#define	GFXMMU_LUT317L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT317L_EN_B_0X1		(0x1u<<0)

// LUT317H Configuration

#define	GFXMMU_LUT317H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT317H_LO_0			(0x1u<<0)

// LUT318L Configuration

#define	GFXMMU_LUT318L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT318L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT318L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT318L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT318L_EN			(0x1u<<0)

#define	GFXMMU_LUT318L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT318L_EN_B_0X1		(0x1u<<0)

// LUT318H Configuration

#define	GFXMMU_LUT318H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT318H_LO_0			(0x1u<<0)

// LUT319L Configuration

#define	GFXMMU_LUT319L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT319L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT319L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT319L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT319L_EN			(0x1u<<0)

#define	GFXMMU_LUT319L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT319L_EN_B_0X1		(0x1u<<0)

// LUT319H Configuration

#define	GFXMMU_LUT319H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT319H_LO_0			(0x1u<<0)

// LUT320L Configuration

#define	GFXMMU_LUT320L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT320L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT320L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT320L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT320L_EN			(0x1u<<0)

#define	GFXMMU_LUT320L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT320L_EN_B_0X1		(0x1u<<0)

// LUT320H Configuration

#define	GFXMMU_LUT320H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT320H_LO_0			(0x1u<<0)

// LUT321L Configuration

#define	GFXMMU_LUT321L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT321L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT321L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT321L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT321L_EN			(0x1u<<0)

#define	GFXMMU_LUT321L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT321L_EN_B_0X1		(0x1u<<0)

// LUT321H Configuration

#define	GFXMMU_LUT321H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT321H_LO_0			(0x1u<<0)

// LUT322L Configuration

#define	GFXMMU_LUT322L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT322L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT322L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT322L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT322L_EN			(0x1u<<0)

#define	GFXMMU_LUT322L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT322L_EN_B_0X1		(0x1u<<0)

// LUT322H Configuration

#define	GFXMMU_LUT322H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT322H_LO_0			(0x1u<<0)

// LUT323L Configuration

#define	GFXMMU_LUT323L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT323L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT323L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT323L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT323L_EN			(0x1u<<0)

#define	GFXMMU_LUT323L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT323L_EN_B_0X1		(0x1u<<0)

// LUT323H Configuration

#define	GFXMMU_LUT323H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT323H_LO_0			(0x1u<<0)

// LUT324L Configuration

#define	GFXMMU_LUT324L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT324L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT324L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT324L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT324L_EN			(0x1u<<0)

#define	GFXMMU_LUT324L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT324L_EN_B_0X1		(0x1u<<0)

// LUT324H Configuration

#define	GFXMMU_LUT324H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT324H_LO_0			(0x1u<<0)

// LUT325L Configuration

#define	GFXMMU_LUT325L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT325L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT325L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT325L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT325L_EN			(0x1u<<0)

#define	GFXMMU_LUT325L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT325L_EN_B_0X1		(0x1u<<0)

// LUT325H Configuration

#define	GFXMMU_LUT325H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT325H_LO_0			(0x1u<<0)

// LUT326L Configuration

#define	GFXMMU_LUT326L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT326L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT326L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT326L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT326L_EN			(0x1u<<0)

#define	GFXMMU_LUT326L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT326L_EN_B_0X1		(0x1u<<0)

// LUT326H Configuration

#define	GFXMMU_LUT326H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT326H_LO_0			(0x1u<<0)

// LUT327L Configuration

#define	GFXMMU_LUT327L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT327L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT327L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT327L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT327L_EN			(0x1u<<0)

#define	GFXMMU_LUT327L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT327L_EN_B_0X1		(0x1u<<0)

// LUT327H Configuration

#define	GFXMMU_LUT327H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT327H_LO_0			(0x1u<<0)

// LUT328L Configuration

#define	GFXMMU_LUT328L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT328L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT328L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT328L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT328L_EN			(0x1u<<0)

#define	GFXMMU_LUT328L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT328L_EN_B_0X1		(0x1u<<0)

// LUT328H Configuration

#define	GFXMMU_LUT328H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT328H_LO_0			(0x1u<<0)

// LUT329L Configuration

#define	GFXMMU_LUT329L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT329L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT329L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT329L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT329L_EN			(0x1u<<0)

#define	GFXMMU_LUT329L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT329L_EN_B_0X1		(0x1u<<0)

// LUT329H Configuration

#define	GFXMMU_LUT329H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT329H_LO_0			(0x1u<<0)

// LUT330L Configuration

#define	GFXMMU_LUT330L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT330L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT330L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT330L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT330L_EN			(0x1u<<0)

#define	GFXMMU_LUT330L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT330L_EN_B_0X1		(0x1u<<0)

// LUT330H Configuration

#define	GFXMMU_LUT330H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT330H_LO_0			(0x1u<<0)

// LUT331L Configuration

#define	GFXMMU_LUT331L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT331L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT331L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT331L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT331L_EN			(0x1u<<0)

#define	GFXMMU_LUT331L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT331L_EN_B_0X1		(0x1u<<0)

// LUT331H Configuration

#define	GFXMMU_LUT331H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT331H_LO_0			(0x1u<<0)

// LUT332L Configuration

#define	GFXMMU_LUT332L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT332L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT332L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT332L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT332L_EN			(0x1u<<0)

#define	GFXMMU_LUT332L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT332L_EN_B_0X1		(0x1u<<0)

// LUT332H Configuration

#define	GFXMMU_LUT332H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT332H_LO_0			(0x1u<<0)

// LUT333L Configuration

#define	GFXMMU_LUT333L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT333L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT333L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT333L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT333L_EN			(0x1u<<0)

#define	GFXMMU_LUT333L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT333L_EN_B_0X1		(0x1u<<0)

// LUT333H Configuration

#define	GFXMMU_LUT333H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT333H_LO_0			(0x1u<<0)

// LUT334L Configuration

#define	GFXMMU_LUT334L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT334L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT334L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT334L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT334L_EN			(0x1u<<0)

#define	GFXMMU_LUT334L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT334L_EN_B_0X1		(0x1u<<0)

// LUT334H Configuration

#define	GFXMMU_LUT334H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT334H_LO_0			(0x1u<<0)

// LUT335L Configuration

#define	GFXMMU_LUT335L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT335L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT335L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT335L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT335L_EN			(0x1u<<0)

#define	GFXMMU_LUT335L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT335L_EN_B_0X1		(0x1u<<0)

// LUT335H Configuration

#define	GFXMMU_LUT335H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT335H_LO_0			(0x1u<<0)

// LUT336L Configuration

#define	GFXMMU_LUT336L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT336L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT336L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT336L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT336L_EN			(0x1u<<0)

#define	GFXMMU_LUT336L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT336L_EN_B_0X1		(0x1u<<0)

// LUT336H Configuration

#define	GFXMMU_LUT336H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT336H_LO_0			(0x1u<<0)

// LUT337L Configuration

#define	GFXMMU_LUT337L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT337L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT337L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT337L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT337L_EN			(0x1u<<0)

#define	GFXMMU_LUT337L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT337L_EN_B_0X1		(0x1u<<0)

// LUT337H Configuration

#define	GFXMMU_LUT337H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT337H_LO_0			(0x1u<<0)

// LUT338L Configuration

#define	GFXMMU_LUT338L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT338L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT338L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT338L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT338L_EN			(0x1u<<0)

#define	GFXMMU_LUT338L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT338L_EN_B_0X1		(0x1u<<0)

// LUT338H Configuration

#define	GFXMMU_LUT338H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT338H_LO_0			(0x1u<<0)

// LUT339L Configuration

#define	GFXMMU_LUT339L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT339L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT339L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT339L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT339L_EN			(0x1u<<0)

#define	GFXMMU_LUT339L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT339L_EN_B_0X1		(0x1u<<0)

// LUT339H Configuration

#define	GFXMMU_LUT339H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT339H_LO_0			(0x1u<<0)

// LUT340L Configuration

#define	GFXMMU_LUT340L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT340L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT340L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT340L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT340L_EN			(0x1u<<0)

#define	GFXMMU_LUT340L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT340L_EN_B_0X1		(0x1u<<0)

// LUT340H Configuration

#define	GFXMMU_LUT340H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT340H_LO_0			(0x1u<<0)

// LUT341L Configuration

#define	GFXMMU_LUT341L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT341L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT341L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT341L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT341L_EN			(0x1u<<0)

#define	GFXMMU_LUT341L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT341L_EN_B_0X1		(0x1u<<0)

// LUT341H Configuration

#define	GFXMMU_LUT341H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT341H_LO_0			(0x1u<<0)

// LUT342L Configuration

#define	GFXMMU_LUT342L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT342L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT342L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT342L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT342L_EN			(0x1u<<0)

#define	GFXMMU_LUT342L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT342L_EN_B_0X1		(0x1u<<0)

// LUT342H Configuration

#define	GFXMMU_LUT342H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT342H_LO_0			(0x1u<<0)

// LUT343L Configuration

#define	GFXMMU_LUT343L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT343L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT343L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT343L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT343L_EN			(0x1u<<0)

#define	GFXMMU_LUT343L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT343L_EN_B_0X1		(0x1u<<0)

// LUT343H Configuration

#define	GFXMMU_LUT343H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT343H_LO_0			(0x1u<<0)

// LUT344L Configuration

#define	GFXMMU_LUT344L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT344L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT344L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT344L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT344L_EN			(0x1u<<0)

#define	GFXMMU_LUT344L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT344L_EN_B_0X1		(0x1u<<0)

// LUT344H Configuration

#define	GFXMMU_LUT344H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT344H_LO_0			(0x1u<<0)

// LUT345L Configuration

#define	GFXMMU_LUT345L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT345L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT345L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT345L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT345L_EN			(0x1u<<0)

#define	GFXMMU_LUT345L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT345L_EN_B_0X1		(0x1u<<0)

// LUT345H Configuration

#define	GFXMMU_LUT345H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT345H_LO_0			(0x1u<<0)

// LUT346L Configuration

#define	GFXMMU_LUT346L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT346L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT346L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT346L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT346L_EN			(0x1u<<0)

#define	GFXMMU_LUT346L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT346L_EN_B_0X1		(0x1u<<0)

// LUT346H Configuration

#define	GFXMMU_LUT346H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT346H_LO_0			(0x1u<<0)

// LUT347L Configuration

#define	GFXMMU_LUT347L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT347L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT347L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT347L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT347L_EN			(0x1u<<0)

#define	GFXMMU_LUT347L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT347L_EN_B_0X1		(0x1u<<0)

// LUT347H Configuration

#define	GFXMMU_LUT347H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT347H_LO_0			(0x1u<<0)

// LUT348L Configuration

#define	GFXMMU_LUT348L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT348L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT348L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT348L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT348L_EN			(0x1u<<0)

#define	GFXMMU_LUT348L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT348L_EN_B_0X1		(0x1u<<0)

// LUT348H Configuration

#define	GFXMMU_LUT348H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT348H_LO_0			(0x1u<<0)

// LUT349L Configuration

#define	GFXMMU_LUT349L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT349L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT349L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT349L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT349L_EN			(0x1u<<0)

#define	GFXMMU_LUT349L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT349L_EN_B_0X1		(0x1u<<0)

// LUT349H Configuration

#define	GFXMMU_LUT349H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT349H_LO_0			(0x1u<<0)

// LUT350L Configuration

#define	GFXMMU_LUT350L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT350L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT350L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT350L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT350L_EN			(0x1u<<0)

#define	GFXMMU_LUT350L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT350L_EN_B_0X1		(0x1u<<0)

// LUT350H Configuration

#define	GFXMMU_LUT350H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT350H_LO_0			(0x1u<<0)

// LUT351L Configuration

#define	GFXMMU_LUT351L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT351L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT351L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT351L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT351L_EN			(0x1u<<0)

#define	GFXMMU_LUT351L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT351L_EN_B_0X1		(0x1u<<0)

// LUT351H Configuration

#define	GFXMMU_LUT351H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT351H_LO_0			(0x1u<<0)

// LUT352L Configuration

#define	GFXMMU_LUT352L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT352L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT352L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT352L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT352L_EN			(0x1u<<0)

#define	GFXMMU_LUT352L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT352L_EN_B_0X1		(0x1u<<0)

// LUT352H Configuration

#define	GFXMMU_LUT352H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT352H_LO_0			(0x1u<<0)

// LUT353L Configuration

#define	GFXMMU_LUT353L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT353L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT353L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT353L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT353L_EN			(0x1u<<0)

#define	GFXMMU_LUT353L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT353L_EN_B_0X1		(0x1u<<0)

// LUT353H Configuration

#define	GFXMMU_LUT353H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT353H_LO_0			(0x1u<<0)

// LUT354L Configuration

#define	GFXMMU_LUT354L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT354L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT354L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT354L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT354L_EN			(0x1u<<0)

#define	GFXMMU_LUT354L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT354L_EN_B_0X1		(0x1u<<0)

// LUT354H Configuration

#define	GFXMMU_LUT354H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT354H_LO_0			(0x1u<<0)

// LUT355L Configuration

#define	GFXMMU_LUT355L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT355L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT355L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT355L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT355L_EN			(0x1u<<0)

#define	GFXMMU_LUT355L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT355L_EN_B_0X1		(0x1u<<0)

// LUT355H Configuration

#define	GFXMMU_LUT355H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT355H_LO_0			(0x1u<<0)

// LUT356L Configuration

#define	GFXMMU_LUT356L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT356L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT356L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT356L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT356L_EN			(0x1u<<0)

#define	GFXMMU_LUT356L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT356L_EN_B_0X1		(0x1u<<0)

// LUT356H Configuration

#define	GFXMMU_LUT356H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT356H_LO_0			(0x1u<<0)

// LUT357L Configuration

#define	GFXMMU_LUT357L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT357L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT357L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT357L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT357L_EN			(0x1u<<0)

#define	GFXMMU_LUT357L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT357L_EN_B_0X1		(0x1u<<0)

// LUT357H Configuration

#define	GFXMMU_LUT357H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT357H_LO_0			(0x1u<<0)

// LUT358L Configuration

#define	GFXMMU_LUT358L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT358L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT358L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT358L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT358L_EN			(0x1u<<0)

#define	GFXMMU_LUT358L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT358L_EN_B_0X1		(0x1u<<0)

// LUT358H Configuration

#define	GFXMMU_LUT358H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT358H_LO_0			(0x1u<<0)

// LUT359L Configuration

#define	GFXMMU_LUT359L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT359L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT359L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT359L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT359L_EN			(0x1u<<0)

#define	GFXMMU_LUT359L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT359L_EN_B_0X1		(0x1u<<0)

// LUT359H Configuration

#define	GFXMMU_LUT359H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT359H_LO_0			(0x1u<<0)

// LUT360L Configuration

#define	GFXMMU_LUT360L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT360L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT360L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT360L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT360L_EN			(0x1u<<0)

#define	GFXMMU_LUT360L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT360L_EN_B_0X1		(0x1u<<0)

// LUT360H Configuration

#define	GFXMMU_LUT360H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT360H_LO_0			(0x1u<<0)

// LUT361L Configuration

#define	GFXMMU_LUT361L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT361L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT361L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT361L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT361L_EN			(0x1u<<0)

#define	GFXMMU_LUT361L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT361L_EN_B_0X1		(0x1u<<0)

// LUT361H Configuration

#define	GFXMMU_LUT361H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT361H_LO_0			(0x1u<<0)

// LUT362L Configuration

#define	GFXMMU_LUT362L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT362L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT362L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT362L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT362L_EN			(0x1u<<0)

#define	GFXMMU_LUT362L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT362L_EN_B_0X1		(0x1u<<0)

// LUT362H Configuration

#define	GFXMMU_LUT362H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT362H_LO_0			(0x1u<<0)

// LUT363L Configuration

#define	GFXMMU_LUT363L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT363L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT363L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT363L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT363L_EN			(0x1u<<0)

#define	GFXMMU_LUT363L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT363L_EN_B_0X1		(0x1u<<0)

// LUT363H Configuration

#define	GFXMMU_LUT363H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT363H_LO_0			(0x1u<<0)

// LUT364L Configuration

#define	GFXMMU_LUT364L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT364L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT364L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT364L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT364L_EN			(0x1u<<0)

#define	GFXMMU_LUT364L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT364L_EN_B_0X1		(0x1u<<0)

// LUT364H Configuration

#define	GFXMMU_LUT364H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT364H_LO_0			(0x1u<<0)

// LUT365L Configuration

#define	GFXMMU_LUT365L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT365L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT365L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT365L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT365L_EN			(0x1u<<0)

#define	GFXMMU_LUT365L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT365L_EN_B_0X1		(0x1u<<0)

// LUT365H Configuration

#define	GFXMMU_LUT365H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT365H_LO_0			(0x1u<<0)

// LUT366L Configuration

#define	GFXMMU_LUT366L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT366L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT366L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT366L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT366L_EN			(0x1u<<0)

#define	GFXMMU_LUT366L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT366L_EN_B_0X1		(0x1u<<0)

// LUT366H Configuration

#define	GFXMMU_LUT366H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT366H_LO_0			(0x1u<<0)

// LUT367L Configuration

#define	GFXMMU_LUT367L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT367L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT367L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT367L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT367L_EN			(0x1u<<0)

#define	GFXMMU_LUT367L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT367L_EN_B_0X1		(0x1u<<0)

// LUT367H Configuration

#define	GFXMMU_LUT367H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT367H_LO_0			(0x1u<<0)

// LUT368L Configuration

#define	GFXMMU_LUT368L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT368L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT368L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT368L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT368L_EN			(0x1u<<0)

#define	GFXMMU_LUT368L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT368L_EN_B_0X1		(0x1u<<0)

// LUT368H Configuration

#define	GFXMMU_LUT368H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT368H_LO_0			(0x1u<<0)

// LUT369L Configuration

#define	GFXMMU_LUT369L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT369L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT369L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT369L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT369L_EN			(0x1u<<0)

#define	GFXMMU_LUT369L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT369L_EN_B_0X1		(0x1u<<0)

// LUT369H Configuration

#define	GFXMMU_LUT369H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT369H_LO_0			(0x1u<<0)

// LUT370L Configuration

#define	GFXMMU_LUT370L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT370L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT370L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT370L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT370L_EN			(0x1u<<0)

#define	GFXMMU_LUT370L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT370L_EN_B_0X1		(0x1u<<0)

// LUT370H Configuration

#define	GFXMMU_LUT370H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT370H_LO_0			(0x1u<<0)

// LUT371L Configuration

#define	GFXMMU_LUT371L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT371L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT371L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT371L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT371L_EN			(0x1u<<0)

#define	GFXMMU_LUT371L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT371L_EN_B_0X1		(0x1u<<0)

// LUT371H Configuration

#define	GFXMMU_LUT371H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT371H_LO_0			(0x1u<<0)

// LUT372L Configuration

#define	GFXMMU_LUT372L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT372L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT372L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT372L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT372L_EN			(0x1u<<0)

#define	GFXMMU_LUT372L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT372L_EN_B_0X1		(0x1u<<0)

// LUT372H Configuration

#define	GFXMMU_LUT372H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT372H_LO_0			(0x1u<<0)

// LUT373L Configuration

#define	GFXMMU_LUT373L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT373L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT373L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT373L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT373L_EN			(0x1u<<0)

#define	GFXMMU_LUT373L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT373L_EN_B_0X1		(0x1u<<0)

// LUT373H Configuration

#define	GFXMMU_LUT373H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT373H_LO_0			(0x1u<<0)

// LUT374L Configuration

#define	GFXMMU_LUT374L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT374L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT374L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT374L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT374L_EN			(0x1u<<0)

#define	GFXMMU_LUT374L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT374L_EN_B_0X1		(0x1u<<0)

// LUT374H Configuration

#define	GFXMMU_LUT374H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT374H_LO_0			(0x1u<<0)

// LUT375L Configuration

#define	GFXMMU_LUT375L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT375L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT375L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT375L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT375L_EN			(0x1u<<0)

#define	GFXMMU_LUT375L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT375L_EN_B_0X1		(0x1u<<0)

// LUT375H Configuration

#define	GFXMMU_LUT375H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT375H_LO_0			(0x1u<<0)

// LUT376L Configuration

#define	GFXMMU_LUT376L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT376L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT376L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT376L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT376L_EN			(0x1u<<0)

#define	GFXMMU_LUT376L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT376L_EN_B_0X1		(0x1u<<0)

// LUT376H Configuration

#define	GFXMMU_LUT376H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT376H_LO_0			(0x1u<<0)

// LUT377L Configuration

#define	GFXMMU_LUT377L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT377L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT377L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT377L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT377L_EN			(0x1u<<0)

#define	GFXMMU_LUT377L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT377L_EN_B_0X1		(0x1u<<0)

// LUT377H Configuration

#define	GFXMMU_LUT377H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT377H_LO_0			(0x1u<<0)

// LUT378L Configuration

#define	GFXMMU_LUT378L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT378L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT378L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT378L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT378L_EN			(0x1u<<0)

#define	GFXMMU_LUT378L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT378L_EN_B_0X1		(0x1u<<0)

// LUT378H Configuration

#define	GFXMMU_LUT378H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT378H_LO_0			(0x1u<<0)

// LUT379L Configuration

#define	GFXMMU_LUT379L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT379L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT379L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT379L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT379L_EN			(0x1u<<0)

#define	GFXMMU_LUT379L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT379L_EN_B_0X1		(0x1u<<0)

// LUT379H Configuration

#define	GFXMMU_LUT379H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT379H_LO_0			(0x1u<<0)

// LUT380L Configuration

#define	GFXMMU_LUT380L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT380L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT380L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT380L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT380L_EN			(0x1u<<0)

#define	GFXMMU_LUT380L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT380L_EN_B_0X1		(0x1u<<0)

// LUT380H Configuration

#define	GFXMMU_LUT380H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT380H_LO_0			(0x1u<<0)

// LUT381L Configuration

#define	GFXMMU_LUT381L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT381L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT381L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT381L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT381L_EN			(0x1u<<0)

#define	GFXMMU_LUT381L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT381L_EN_B_0X1		(0x1u<<0)

// LUT381H Configuration

#define	GFXMMU_LUT381H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT381H_LO_0			(0x1u<<0)

// LUT382L Configuration

#define	GFXMMU_LUT382L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT382L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT382L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT382L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT382L_EN			(0x1u<<0)

#define	GFXMMU_LUT382L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT382L_EN_B_0X1		(0x1u<<0)

// LUT382H Configuration

#define	GFXMMU_LUT382H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT382H_LO_0			(0x1u<<0)

// LUT383L Configuration

#define	GFXMMU_LUT383L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT383L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT383L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT383L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT383L_EN			(0x1u<<0)

#define	GFXMMU_LUT383L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT383L_EN_B_0X1		(0x1u<<0)

// LUT383H Configuration

#define	GFXMMU_LUT383H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT383H_LO_0			(0x1u<<0)

// LUT384L Configuration

#define	GFXMMU_LUT384L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT384L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT384L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT384L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT384L_EN			(0x1u<<0)

#define	GFXMMU_LUT384L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT384L_EN_B_0X1		(0x1u<<0)

// LUT384H Configuration

#define	GFXMMU_LUT384H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT384H_LO_0			(0x1u<<0)

// LUT385L Configuration

#define	GFXMMU_LUT385L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT385L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT385L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT385L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT385L_EN			(0x1u<<0)

#define	GFXMMU_LUT385L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT385L_EN_B_0X1		(0x1u<<0)

// LUT385H Configuration

#define	GFXMMU_LUT385H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT385H_LO_0			(0x1u<<0)

// LUT386L Configuration

#define	GFXMMU_LUT386L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT386L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT386L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT386L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT386L_EN			(0x1u<<0)

#define	GFXMMU_LUT386L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT386L_EN_B_0X1		(0x1u<<0)

// LUT386H Configuration

#define	GFXMMU_LUT386H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT386H_LO_0			(0x1u<<0)

// LUT387L Configuration

#define	GFXMMU_LUT387L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT387L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT387L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT387L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT387L_EN			(0x1u<<0)

#define	GFXMMU_LUT387L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT387L_EN_B_0X1		(0x1u<<0)

// LUT387H Configuration

#define	GFXMMU_LUT387H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT387H_LO_0			(0x1u<<0)

// LUT388L Configuration

#define	GFXMMU_LUT388L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT388L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT388L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT388L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT388L_EN			(0x1u<<0)

#define	GFXMMU_LUT388L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT388L_EN_B_0X1		(0x1u<<0)

// LUT388H Configuration

#define	GFXMMU_LUT388H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT388H_LO_0			(0x1u<<0)

// LUT389L Configuration

#define	GFXMMU_LUT389L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT389L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT389L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT389L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT389L_EN			(0x1u<<0)

#define	GFXMMU_LUT389L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT389L_EN_B_0X1		(0x1u<<0)

// LUT389H Configuration

#define	GFXMMU_LUT389H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT389H_LO_0			(0x1u<<0)

// LUT390L Configuration

#define	GFXMMU_LUT390L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT390L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT390L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT390L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT390L_EN			(0x1u<<0)

#define	GFXMMU_LUT390L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT390L_EN_B_0X1		(0x1u<<0)

// LUT390H Configuration

#define	GFXMMU_LUT390H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT390H_LO_0			(0x1u<<0)

// LUT391L Configuration

#define	GFXMMU_LUT391L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT391L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT391L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT391L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT391L_EN			(0x1u<<0)

#define	GFXMMU_LUT391L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT391L_EN_B_0X1		(0x1u<<0)

// LUT391H Configuration

#define	GFXMMU_LUT391H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT391H_LO_0			(0x1u<<0)

// LUT392L Configuration

#define	GFXMMU_LUT392L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT392L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT392L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT392L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT392L_EN			(0x1u<<0)

#define	GFXMMU_LUT392L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT392L_EN_B_0X1		(0x1u<<0)

// LUT392H Configuration

#define	GFXMMU_LUT392H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT392H_LO_0			(0x1u<<0)

// LUT393L Configuration

#define	GFXMMU_LUT393L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT393L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT393L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT393L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT393L_EN			(0x1u<<0)

#define	GFXMMU_LUT393L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT393L_EN_B_0X1		(0x1u<<0)

// LUT393H Configuration

#define	GFXMMU_LUT393H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT393H_LO_0			(0x1u<<0)

// LUT394L Configuration

#define	GFXMMU_LUT394L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT394L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT394L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT394L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT394L_EN			(0x1u<<0)

#define	GFXMMU_LUT394L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT394L_EN_B_0X1		(0x1u<<0)

// LUT394H Configuration

#define	GFXMMU_LUT394H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT394H_LO_0			(0x1u<<0)

// LUT395L Configuration

#define	GFXMMU_LUT395L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT395L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT395L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT395L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT395L_EN			(0x1u<<0)

#define	GFXMMU_LUT395L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT395L_EN_B_0X1		(0x1u<<0)

// LUT395H Configuration

#define	GFXMMU_LUT395H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT395H_LO_0			(0x1u<<0)

// LUT396L Configuration

#define	GFXMMU_LUT396L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT396L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT396L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT396L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT396L_EN			(0x1u<<0)

#define	GFXMMU_LUT396L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT396L_EN_B_0X1		(0x1u<<0)

// LUT396H Configuration

#define	GFXMMU_LUT396H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT396H_LO_0			(0x1u<<0)

// LUT397L Configuration

#define	GFXMMU_LUT397L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT397L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT397L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT397L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT397L_EN			(0x1u<<0)

#define	GFXMMU_LUT397L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT397L_EN_B_0X1		(0x1u<<0)

// LUT397H Configuration

#define	GFXMMU_LUT397H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT397H_LO_0			(0x1u<<0)

// LUT398L Configuration

#define	GFXMMU_LUT398L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT398L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT398L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT398L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT398L_EN			(0x1u<<0)

#define	GFXMMU_LUT398L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT398L_EN_B_0X1		(0x1u<<0)

// LUT398H Configuration

#define	GFXMMU_LUT398H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT398H_LO_0			(0x1u<<0)

// LUT399L Configuration

#define	GFXMMU_LUT399L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT399L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT399L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT399L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT399L_EN			(0x1u<<0)

#define	GFXMMU_LUT399L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT399L_EN_B_0X1		(0x1u<<0)

// LUT399H Configuration

#define	GFXMMU_LUT399H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT399H_LO_0			(0x1u<<0)

// LUT400L Configuration

#define	GFXMMU_LUT400L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT400L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT400L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT400L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT400L_EN			(0x1u<<0)

#define	GFXMMU_LUT400L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT400L_EN_B_0X1		(0x1u<<0)

// LUT400H Configuration

#define	GFXMMU_LUT400H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT400H_LO_0			(0x1u<<0)

// LUT401L Configuration

#define	GFXMMU_LUT401L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT401L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT401L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT401L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT401L_EN			(0x1u<<0)

#define	GFXMMU_LUT401L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT401L_EN_B_0X1		(0x1u<<0)

// LUT401H Configuration

#define	GFXMMU_LUT401H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT401H_LO_0			(0x1u<<0)

// LUT402L Configuration

#define	GFXMMU_LUT402L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT402L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT402L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT402L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT402L_EN			(0x1u<<0)

#define	GFXMMU_LUT402L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT402L_EN_B_0X1		(0x1u<<0)

// LUT402H Configuration

#define	GFXMMU_LUT402H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT402H_LO_0			(0x1u<<0)

// LUT403L Configuration

#define	GFXMMU_LUT403L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT403L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT403L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT403L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT403L_EN			(0x1u<<0)

#define	GFXMMU_LUT403L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT403L_EN_B_0X1		(0x1u<<0)

// LUT403H Configuration

#define	GFXMMU_LUT403H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT403H_LO_0			(0x1u<<0)

// LUT404L Configuration

#define	GFXMMU_LUT404L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT404L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT404L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT404L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT404L_EN			(0x1u<<0)

#define	GFXMMU_LUT404L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT404L_EN_B_0X1		(0x1u<<0)

// LUT404H Configuration

#define	GFXMMU_LUT404H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT404H_LO_0			(0x1u<<0)

// LUT405L Configuration

#define	GFXMMU_LUT405L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT405L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT405L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT405L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT405L_EN			(0x1u<<0)

#define	GFXMMU_LUT405L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT405L_EN_B_0X1		(0x1u<<0)

// LUT405H Configuration

#define	GFXMMU_LUT405H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT405H_LO_0			(0x1u<<0)

// LUT406L Configuration

#define	GFXMMU_LUT406L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT406L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT406L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT406L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT406L_EN			(0x1u<<0)

#define	GFXMMU_LUT406L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT406L_EN_B_0X1		(0x1u<<0)

// LUT406H Configuration

#define	GFXMMU_LUT406H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT406H_LO_0			(0x1u<<0)

// LUT407L Configuration

#define	GFXMMU_LUT407L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT407L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT407L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT407L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT407L_EN			(0x1u<<0)

#define	GFXMMU_LUT407L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT407L_EN_B_0X1		(0x1u<<0)

// LUT407H Configuration

#define	GFXMMU_LUT407H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT407H_LO_0			(0x1u<<0)

// LUT408L Configuration

#define	GFXMMU_LUT408L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT408L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT408L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT408L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT408L_EN			(0x1u<<0)

#define	GFXMMU_LUT408L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT408L_EN_B_0X1		(0x1u<<0)

// LUT408H Configuration

#define	GFXMMU_LUT408H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT408H_LO_0			(0x1u<<0)

// LUT409L Configuration

#define	GFXMMU_LUT409L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT409L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT409L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT409L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT409L_EN			(0x1u<<0)

#define	GFXMMU_LUT409L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT409L_EN_B_0X1		(0x1u<<0)

// LUT409H Configuration

#define	GFXMMU_LUT409H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT409H_LO_0			(0x1u<<0)

// LUT410L Configuration

#define	GFXMMU_LUT410L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT410L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT410L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT410L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT410L_EN			(0x1u<<0)

#define	GFXMMU_LUT410L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT410L_EN_B_0X1		(0x1u<<0)

// LUT410H Configuration

#define	GFXMMU_LUT410H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT410H_LO_0			(0x1u<<0)

// LUT411L Configuration

#define	GFXMMU_LUT411L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT411L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT411L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT411L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT411L_EN			(0x1u<<0)

#define	GFXMMU_LUT411L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT411L_EN_B_0X1		(0x1u<<0)

// LUT411H Configuration

#define	GFXMMU_LUT411H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT411H_LO_0			(0x1u<<0)

// LUT412L Configuration

#define	GFXMMU_LUT412L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT412L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT412L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT412L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT412L_EN			(0x1u<<0)

#define	GFXMMU_LUT412L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT412L_EN_B_0X1		(0x1u<<0)

// LUT412H Configuration

#define	GFXMMU_LUT412H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT412H_LO_0			(0x1u<<0)

// LUT413L Configuration

#define	GFXMMU_LUT413L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT413L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT413L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT413L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT413L_EN			(0x1u<<0)

#define	GFXMMU_LUT413L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT413L_EN_B_0X1		(0x1u<<0)

// LUT413H Configuration

#define	GFXMMU_LUT413H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT413H_LO_0			(0x1u<<0)

// LUT414L Configuration

#define	GFXMMU_LUT414L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT414L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT414L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT414L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT414L_EN			(0x1u<<0)

#define	GFXMMU_LUT414L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT414L_EN_B_0X1		(0x1u<<0)

// LUT414H Configuration

#define	GFXMMU_LUT414H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT414H_LO_0			(0x1u<<0)

// LUT415L Configuration

#define	GFXMMU_LUT415L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT415L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT415L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT415L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT415L_EN			(0x1u<<0)

#define	GFXMMU_LUT415L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT415L_EN_B_0X1		(0x1u<<0)

// LUT415H Configuration

#define	GFXMMU_LUT415H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT415H_LO_0			(0x1u<<0)

// LUT416L Configuration

#define	GFXMMU_LUT416L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT416L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT416L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT416L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT416L_EN			(0x1u<<0)

#define	GFXMMU_LUT416L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT416L_EN_B_0X1		(0x1u<<0)

// LUT416H Configuration

#define	GFXMMU_LUT416H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT416H_LO_0			(0x1u<<0)

// LUT417L Configuration

#define	GFXMMU_LUT417L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT417L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT417L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT417L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT417L_EN			(0x1u<<0)

#define	GFXMMU_LUT417L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT417L_EN_B_0X1		(0x1u<<0)

// LUT417H Configuration

#define	GFXMMU_LUT417H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT417H_LO_0			(0x1u<<0)

// LUT418L Configuration

#define	GFXMMU_LUT418L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT418L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT418L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT418L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT418L_EN			(0x1u<<0)

#define	GFXMMU_LUT418L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT418L_EN_B_0X1		(0x1u<<0)

// LUT418H Configuration

#define	GFXMMU_LUT418H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT418H_LO_0			(0x1u<<0)

// LUT419L Configuration

#define	GFXMMU_LUT419L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT419L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT419L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT419L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT419L_EN			(0x1u<<0)

#define	GFXMMU_LUT419L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT419L_EN_B_0X1		(0x1u<<0)

// LUT419H Configuration

#define	GFXMMU_LUT419H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT419H_LO_0			(0x1u<<0)

// LUT420L Configuration

#define	GFXMMU_LUT420L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT420L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT420L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT420L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT420L_EN			(0x1u<<0)

#define	GFXMMU_LUT420L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT420L_EN_B_0X1		(0x1u<<0)

// LUT420H Configuration

#define	GFXMMU_LUT420H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT420H_LO_0			(0x1u<<0)

// LUT421L Configuration

#define	GFXMMU_LUT421L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT421L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT421L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT421L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT421L_EN			(0x1u<<0)

#define	GFXMMU_LUT421L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT421L_EN_B_0X1		(0x1u<<0)

// LUT421H Configuration

#define	GFXMMU_LUT421H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT421H_LO_0			(0x1u<<0)

// LUT422L Configuration

#define	GFXMMU_LUT422L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT422L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT422L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT422L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT422L_EN			(0x1u<<0)

#define	GFXMMU_LUT422L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT422L_EN_B_0X1		(0x1u<<0)

// LUT422H Configuration

#define	GFXMMU_LUT422H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT422H_LO_0			(0x1u<<0)

// LUT423L Configuration

#define	GFXMMU_LUT423L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT423L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT423L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT423L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT423L_EN			(0x1u<<0)

#define	GFXMMU_LUT423L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT423L_EN_B_0X1		(0x1u<<0)

// LUT423H Configuration

#define	GFXMMU_LUT423H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT423H_LO_0			(0x1u<<0)

// LUT424L Configuration

#define	GFXMMU_LUT424L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT424L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT424L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT424L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT424L_EN			(0x1u<<0)

#define	GFXMMU_LUT424L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT424L_EN_B_0X1		(0x1u<<0)

// LUT424H Configuration

#define	GFXMMU_LUT424H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT424H_LO_0			(0x1u<<0)

// LUT425L Configuration

#define	GFXMMU_LUT425L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT425L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT425L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT425L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT425L_EN			(0x1u<<0)

#define	GFXMMU_LUT425L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT425L_EN_B_0X1		(0x1u<<0)

// LUT425H Configuration

#define	GFXMMU_LUT425H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT425H_LO_0			(0x1u<<0)

// LUT426L Configuration

#define	GFXMMU_LUT426L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT426L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT426L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT426L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT426L_EN			(0x1u<<0)

#define	GFXMMU_LUT426L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT426L_EN_B_0X1		(0x1u<<0)

// LUT426H Configuration

#define	GFXMMU_LUT426H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT426H_LO_0			(0x1u<<0)

// LUT427L Configuration

#define	GFXMMU_LUT427L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT427L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT427L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT427L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT427L_EN			(0x1u<<0)

#define	GFXMMU_LUT427L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT427L_EN_B_0X1		(0x1u<<0)

// LUT427H Configuration

#define	GFXMMU_LUT427H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT427H_LO_0			(0x1u<<0)

// LUT428L Configuration

#define	GFXMMU_LUT428L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT428L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT428L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT428L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT428L_EN			(0x1u<<0)

#define	GFXMMU_LUT428L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT428L_EN_B_0X1		(0x1u<<0)

// LUT428H Configuration

#define	GFXMMU_LUT428H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT428H_LO_0			(0x1u<<0)

// LUT429L Configuration

#define	GFXMMU_LUT429L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT429L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT429L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT429L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT429L_EN			(0x1u<<0)

#define	GFXMMU_LUT429L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT429L_EN_B_0X1		(0x1u<<0)

// LUT429H Configuration

#define	GFXMMU_LUT429H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT429H_LO_0			(0x1u<<0)

// LUT430L Configuration

#define	GFXMMU_LUT430L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT430L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT430L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT430L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT430L_EN			(0x1u<<0)

#define	GFXMMU_LUT430L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT430L_EN_B_0X1		(0x1u<<0)

// LUT430H Configuration

#define	GFXMMU_LUT430H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT430H_LO_0			(0x1u<<0)

// LUT431L Configuration

#define	GFXMMU_LUT431L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT431L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT431L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT431L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT431L_EN			(0x1u<<0)

#define	GFXMMU_LUT431L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT431L_EN_B_0X1		(0x1u<<0)

// LUT431H Configuration

#define	GFXMMU_LUT431H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT431H_LO_0			(0x1u<<0)

// LUT432L Configuration

#define	GFXMMU_LUT432L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT432L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT432L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT432L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT432L_EN			(0x1u<<0)

#define	GFXMMU_LUT432L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT432L_EN_B_0X1		(0x1u<<0)

// LUT432H Configuration

#define	GFXMMU_LUT432H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT432H_LO_0			(0x1u<<0)

// LUT433L Configuration

#define	GFXMMU_LUT433L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT433L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT433L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT433L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT433L_EN			(0x1u<<0)

#define	GFXMMU_LUT433L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT433L_EN_B_0X1		(0x1u<<0)

// LUT433H Configuration

#define	GFXMMU_LUT433H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT433H_LO_0			(0x1u<<0)

// LUT434L Configuration

#define	GFXMMU_LUT434L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT434L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT434L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT434L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT434L_EN			(0x1u<<0)

#define	GFXMMU_LUT434L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT434L_EN_B_0X1		(0x1u<<0)

// LUT434H Configuration

#define	GFXMMU_LUT434H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT434H_LO_0			(0x1u<<0)

// LUT435L Configuration

#define	GFXMMU_LUT435L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT435L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT435L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT435L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT435L_EN			(0x1u<<0)

#define	GFXMMU_LUT435L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT435L_EN_B_0X1		(0x1u<<0)

// LUT435H Configuration

#define	GFXMMU_LUT435H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT435H_LO_0			(0x1u<<0)

// LUT436L Configuration

#define	GFXMMU_LUT436L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT436L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT436L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT436L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT436L_EN			(0x1u<<0)

#define	GFXMMU_LUT436L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT436L_EN_B_0X1		(0x1u<<0)

// LUT436H Configuration

#define	GFXMMU_LUT436H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT436H_LO_0			(0x1u<<0)

// LUT437L Configuration

#define	GFXMMU_LUT437L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT437L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT437L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT437L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT437L_EN			(0x1u<<0)

#define	GFXMMU_LUT437L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT437L_EN_B_0X1		(0x1u<<0)

// LUT437H Configuration

#define	GFXMMU_LUT437H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT437H_LO_0			(0x1u<<0)

// LUT438L Configuration

#define	GFXMMU_LUT438L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT438L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT438L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT438L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT438L_EN			(0x1u<<0)

#define	GFXMMU_LUT438L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT438L_EN_B_0X1		(0x1u<<0)

// LUT438H Configuration

#define	GFXMMU_LUT438H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT438H_LO_0			(0x1u<<0)

// LUT439L Configuration

#define	GFXMMU_LUT439L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT439L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT439L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT439L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT439L_EN			(0x1u<<0)

#define	GFXMMU_LUT439L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT439L_EN_B_0X1		(0x1u<<0)

// LUT439H Configuration

#define	GFXMMU_LUT439H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT439H_LO_0			(0x1u<<0)

// LUT440L Configuration

#define	GFXMMU_LUT440L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT440L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT440L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT440L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT440L_EN			(0x1u<<0)

#define	GFXMMU_LUT440L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT440L_EN_B_0X1		(0x1u<<0)

// LUT440H Configuration

#define	GFXMMU_LUT440H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT440H_LO_0			(0x1u<<0)

// LUT441L Configuration

#define	GFXMMU_LUT441L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT441L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT441L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT441L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT441L_EN			(0x1u<<0)

#define	GFXMMU_LUT441L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT441L_EN_B_0X1		(0x1u<<0)

// LUT441H Configuration

#define	GFXMMU_LUT441H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT441H_LO_0			(0x1u<<0)

// LUT442L Configuration

#define	GFXMMU_LUT442L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT442L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT442L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT442L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT442L_EN			(0x1u<<0)

#define	GFXMMU_LUT442L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT442L_EN_B_0X1		(0x1u<<0)

// LUT442H Configuration

#define	GFXMMU_LUT442H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT442H_LO_0			(0x1u<<0)

// LUT443L Configuration

#define	GFXMMU_LUT443L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT443L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT443L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT443L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT443L_EN			(0x1u<<0)

#define	GFXMMU_LUT443L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT443L_EN_B_0X1		(0x1u<<0)

// LUT443H Configuration

#define	GFXMMU_LUT443H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT443H_LO_0			(0x1u<<0)

// LUT444L Configuration

#define	GFXMMU_LUT444L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT444L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT444L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT444L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT444L_EN			(0x1u<<0)

#define	GFXMMU_LUT444L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT444L_EN_B_0X1		(0x1u<<0)

// LUT444H Configuration

#define	GFXMMU_LUT444H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT444H_LO_0			(0x1u<<0)

// LUT445L Configuration

#define	GFXMMU_LUT445L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT445L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT445L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT445L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT445L_EN			(0x1u<<0)

#define	GFXMMU_LUT445L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT445L_EN_B_0X1		(0x1u<<0)

// LUT445H Configuration

#define	GFXMMU_LUT445H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT445H_LO_0			(0x1u<<0)

// LUT446L Configuration

#define	GFXMMU_LUT446L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT446L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT446L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT446L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT446L_EN			(0x1u<<0)

#define	GFXMMU_LUT446L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT446L_EN_B_0X1		(0x1u<<0)

// LUT446H Configuration

#define	GFXMMU_LUT446H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT446H_LO_0			(0x1u<<0)

// LUT447L Configuration

#define	GFXMMU_LUT447L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT447L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT447L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT447L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT447L_EN			(0x1u<<0)

#define	GFXMMU_LUT447L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT447L_EN_B_0X1		(0x1u<<0)

// LUT447H Configuration

#define	GFXMMU_LUT447H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT447H_LO_0			(0x1u<<0)

// LUT448L Configuration

#define	GFXMMU_LUT448L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT448L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT448L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT448L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT448L_EN			(0x1u<<0)

#define	GFXMMU_LUT448L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT448L_EN_B_0X1		(0x1u<<0)

// LUT448H Configuration

#define	GFXMMU_LUT448H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT448H_LO_0			(0x1u<<0)

// LUT449L Configuration

#define	GFXMMU_LUT449L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT449L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT449L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT449L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT449L_EN			(0x1u<<0)

#define	GFXMMU_LUT449L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT449L_EN_B_0X1		(0x1u<<0)

// LUT449H Configuration

#define	GFXMMU_LUT449H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT449H_LO_0			(0x1u<<0)

// LUT450L Configuration

#define	GFXMMU_LUT450L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT450L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT450L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT450L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT450L_EN			(0x1u<<0)

#define	GFXMMU_LUT450L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT450L_EN_B_0X1		(0x1u<<0)

// LUT450H Configuration

#define	GFXMMU_LUT450H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT450H_LO_0			(0x1u<<0)

// LUT451L Configuration

#define	GFXMMU_LUT451L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT451L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT451L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT451L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT451L_EN			(0x1u<<0)

#define	GFXMMU_LUT451L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT451L_EN_B_0X1		(0x1u<<0)

// LUT451H Configuration

#define	GFXMMU_LUT451H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT451H_LO_0			(0x1u<<0)

// LUT452L Configuration

#define	GFXMMU_LUT452L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT452L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT452L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT452L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT452L_EN			(0x1u<<0)

#define	GFXMMU_LUT452L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT452L_EN_B_0X1		(0x1u<<0)

// LUT452H Configuration

#define	GFXMMU_LUT452H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT452H_LO_0			(0x1u<<0)

// LUT453L Configuration

#define	GFXMMU_LUT453L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT453L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT453L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT453L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT453L_EN			(0x1u<<0)

#define	GFXMMU_LUT453L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT453L_EN_B_0X1		(0x1u<<0)

// LUT453H Configuration

#define	GFXMMU_LUT453H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT453H_LO_0			(0x1u<<0)

// LUT454L Configuration

#define	GFXMMU_LUT454L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT454L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT454L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT454L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT454L_EN			(0x1u<<0)

#define	GFXMMU_LUT454L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT454L_EN_B_0X1		(0x1u<<0)

// LUT454H Configuration

#define	GFXMMU_LUT454H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT454H_LO_0			(0x1u<<0)

// LUT455L Configuration

#define	GFXMMU_LUT455L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT455L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT455L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT455L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT455L_EN			(0x1u<<0)

#define	GFXMMU_LUT455L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT455L_EN_B_0X1		(0x1u<<0)

// LUT455H Configuration

#define	GFXMMU_LUT455H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT455H_LO_0			(0x1u<<0)

// LUT456L Configuration

#define	GFXMMU_LUT456L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT456L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT456L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT456L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT456L_EN			(0x1u<<0)

#define	GFXMMU_LUT456L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT456L_EN_B_0X1		(0x1u<<0)

// LUT456H Configuration

#define	GFXMMU_LUT456H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT456H_LO_0			(0x1u<<0)

// LUT457L Configuration

#define	GFXMMU_LUT457L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT457L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT457L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT457L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT457L_EN			(0x1u<<0)

#define	GFXMMU_LUT457L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT457L_EN_B_0X1		(0x1u<<0)

// LUT457H Configuration

#define	GFXMMU_LUT457H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT457H_LO_0			(0x1u<<0)

// LUT458L Configuration

#define	GFXMMU_LUT458L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT458L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT458L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT458L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT458L_EN			(0x1u<<0)

#define	GFXMMU_LUT458L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT458L_EN_B_0X1		(0x1u<<0)

// LUT458H Configuration

#define	GFXMMU_LUT458H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT458H_LO_0			(0x1u<<0)

// LUT459L Configuration

#define	GFXMMU_LUT459L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT459L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT459L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT459L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT459L_EN			(0x1u<<0)

#define	GFXMMU_LUT459L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT459L_EN_B_0X1		(0x1u<<0)

// LUT459H Configuration

#define	GFXMMU_LUT459H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT459H_LO_0			(0x1u<<0)

// LUT460L Configuration

#define	GFXMMU_LUT460L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT460L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT460L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT460L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT460L_EN			(0x1u<<0)

#define	GFXMMU_LUT460L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT460L_EN_B_0X1		(0x1u<<0)

// LUT460H Configuration

#define	GFXMMU_LUT460H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT460H_LO_0			(0x1u<<0)

// LUT461L Configuration

#define	GFXMMU_LUT461L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT461L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT461L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT461L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT461L_EN			(0x1u<<0)

#define	GFXMMU_LUT461L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT461L_EN_B_0X1		(0x1u<<0)

// LUT461H Configuration

#define	GFXMMU_LUT461H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT461H_LO_0			(0x1u<<0)

// LUT462L Configuration

#define	GFXMMU_LUT462L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT462L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT462L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT462L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT462L_EN			(0x1u<<0)

#define	GFXMMU_LUT462L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT462L_EN_B_0X1		(0x1u<<0)

// LUT462H Configuration

#define	GFXMMU_LUT462H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT462H_LO_0			(0x1u<<0)

// LUT463L Configuration

#define	GFXMMU_LUT463L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT463L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT463L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT463L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT463L_EN			(0x1u<<0)

#define	GFXMMU_LUT463L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT463L_EN_B_0X1		(0x1u<<0)

// LUT463H Configuration

#define	GFXMMU_LUT463H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT463H_LO_0			(0x1u<<0)

// LUT464L Configuration

#define	GFXMMU_LUT464L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT464L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT464L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT464L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT464L_EN			(0x1u<<0)

#define	GFXMMU_LUT464L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT464L_EN_B_0X1		(0x1u<<0)

// LUT464H Configuration

#define	GFXMMU_LUT464H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT464H_LO_0			(0x1u<<0)

// LUT465L Configuration

#define	GFXMMU_LUT465L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT465L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT465L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT465L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT465L_EN			(0x1u<<0)

#define	GFXMMU_LUT465L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT465L_EN_B_0X1		(0x1u<<0)

// LUT465H Configuration

#define	GFXMMU_LUT465H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT465H_LO_0			(0x1u<<0)

// LUT466L Configuration

#define	GFXMMU_LUT466L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT466L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT466L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT466L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT466L_EN			(0x1u<<0)

#define	GFXMMU_LUT466L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT466L_EN_B_0X1		(0x1u<<0)

// LUT466H Configuration

#define	GFXMMU_LUT466H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT466H_LO_0			(0x1u<<0)

// LUT467L Configuration

#define	GFXMMU_LUT467L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT467L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT467L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT467L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT467L_EN			(0x1u<<0)

#define	GFXMMU_LUT467L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT467L_EN_B_0X1		(0x1u<<0)

// LUT467H Configuration

#define	GFXMMU_LUT467H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT467H_LO_0			(0x1u<<0)

// LUT468L Configuration

#define	GFXMMU_LUT468L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT468L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT468L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT468L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT468L_EN			(0x1u<<0)

#define	GFXMMU_LUT468L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT468L_EN_B_0X1		(0x1u<<0)

// LUT468H Configuration

#define	GFXMMU_LUT468H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT468H_LO_0			(0x1u<<0)

// LUT469L Configuration

#define	GFXMMU_LUT469L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT469L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT469L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT469L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT469L_EN			(0x1u<<0)

#define	GFXMMU_LUT469L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT469L_EN_B_0X1		(0x1u<<0)

// LUT469H Configuration

#define	GFXMMU_LUT469H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT469H_LO_0			(0x1u<<0)

// LUT470L Configuration

#define	GFXMMU_LUT470L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT470L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT470L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT470L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT470L_EN			(0x1u<<0)

#define	GFXMMU_LUT470L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT470L_EN_B_0X1		(0x1u<<0)

// LUT470H Configuration

#define	GFXMMU_LUT470H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT470H_LO_0			(0x1u<<0)

// LUT471L Configuration

#define	GFXMMU_LUT471L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT471L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT471L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT471L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT471L_EN			(0x1u<<0)

#define	GFXMMU_LUT471L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT471L_EN_B_0X1		(0x1u<<0)

// LUT471H Configuration

#define	GFXMMU_LUT471H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT471H_LO_0			(0x1u<<0)

// LUT472L Configuration

#define	GFXMMU_LUT472L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT472L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT472L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT472L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT472L_EN			(0x1u<<0)

#define	GFXMMU_LUT472L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT472L_EN_B_0X1		(0x1u<<0)

// LUT472H Configuration

#define	GFXMMU_LUT472H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT472H_LO_0			(0x1u<<0)

// LUT473L Configuration

#define	GFXMMU_LUT473L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT473L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT473L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT473L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT473L_EN			(0x1u<<0)

#define	GFXMMU_LUT473L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT473L_EN_B_0X1		(0x1u<<0)

// LUT473H Configuration

#define	GFXMMU_LUT473H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT473H_LO_0			(0x1u<<0)

// LUT474L Configuration

#define	GFXMMU_LUT474L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT474L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT474L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT474L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT474L_EN			(0x1u<<0)

#define	GFXMMU_LUT474L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT474L_EN_B_0X1		(0x1u<<0)

// LUT474H Configuration

#define	GFXMMU_LUT474H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT474H_LO_0			(0x1u<<0)

// LUT475L Configuration

#define	GFXMMU_LUT475L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT475L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT475L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT475L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT475L_EN			(0x1u<<0)

#define	GFXMMU_LUT475L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT475L_EN_B_0X1		(0x1u<<0)

// LUT475H Configuration

#define	GFXMMU_LUT475H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT475H_LO_0			(0x1u<<0)

// LUT476L Configuration

#define	GFXMMU_LUT476L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT476L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT476L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT476L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT476L_EN			(0x1u<<0)

#define	GFXMMU_LUT476L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT476L_EN_B_0X1		(0x1u<<0)

// LUT476H Configuration

#define	GFXMMU_LUT476H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT476H_LO_0			(0x1u<<0)

// LUT477L Configuration

#define	GFXMMU_LUT477L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT477L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT477L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT477L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT477L_EN			(0x1u<<0)

#define	GFXMMU_LUT477L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT477L_EN_B_0X1		(0x1u<<0)

// LUT477H Configuration

#define	GFXMMU_LUT477H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT477H_LO_0			(0x1u<<0)

// LUT478L Configuration

#define	GFXMMU_LUT478L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT478L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT478L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT478L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT478L_EN			(0x1u<<0)

#define	GFXMMU_LUT478L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT478L_EN_B_0X1		(0x1u<<0)

// LUT478H Configuration

#define	GFXMMU_LUT478H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT478H_LO_0			(0x1u<<0)

// LUT479L Configuration

#define	GFXMMU_LUT479L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT479L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT479L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT479L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT479L_EN			(0x1u<<0)

#define	GFXMMU_LUT479L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT479L_EN_B_0X1		(0x1u<<0)

// LUT479H Configuration

#define	GFXMMU_LUT479H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT479H_LO_0			(0x1u<<0)

// LUT480L Configuration

#define	GFXMMU_LUT480L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT480L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT480L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT480L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT480L_EN			(0x1u<<0)

#define	GFXMMU_LUT480L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT480L_EN_B_0X1		(0x1u<<0)

// LUT480H Configuration

#define	GFXMMU_LUT480H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT480H_LO_0			(0x1u<<0)

// LUT481L Configuration

#define	GFXMMU_LUT481L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT481L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT481L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT481L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT481L_EN			(0x1u<<0)

#define	GFXMMU_LUT481L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT481L_EN_B_0X1		(0x1u<<0)

// LUT481H Configuration

#define	GFXMMU_LUT481H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT481H_LO_0			(0x1u<<0)

// LUT482L Configuration

#define	GFXMMU_LUT482L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT482L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT482L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT482L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT482L_EN			(0x1u<<0)

#define	GFXMMU_LUT482L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT482L_EN_B_0X1		(0x1u<<0)

// LUT482H Configuration

#define	GFXMMU_LUT482H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT482H_LO_0			(0x1u<<0)

// LUT483L Configuration

#define	GFXMMU_LUT483L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT483L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT483L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT483L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT483L_EN			(0x1u<<0)

#define	GFXMMU_LUT483L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT483L_EN_B_0X1		(0x1u<<0)

// LUT483H Configuration

#define	GFXMMU_LUT483H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT483H_LO_0			(0x1u<<0)

// LUT484L Configuration

#define	GFXMMU_LUT484L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT484L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT484L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT484L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT484L_EN			(0x1u<<0)

#define	GFXMMU_LUT484L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT484L_EN_B_0X1		(0x1u<<0)

// LUT484H Configuration

#define	GFXMMU_LUT484H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT484H_LO_0			(0x1u<<0)

// LUT485L Configuration

#define	GFXMMU_LUT485L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT485L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT485L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT485L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT485L_EN			(0x1u<<0)

#define	GFXMMU_LUT485L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT485L_EN_B_0X1		(0x1u<<0)

// LUT485H Configuration

#define	GFXMMU_LUT485H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT485H_LO_0			(0x1u<<0)

// LUT486L Configuration

#define	GFXMMU_LUT486L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT486L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT486L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT486L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT486L_EN			(0x1u<<0)

#define	GFXMMU_LUT486L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT486L_EN_B_0X1		(0x1u<<0)

// LUT486H Configuration

#define	GFXMMU_LUT486H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT486H_LO_0			(0x1u<<0)

// LUT487L Configuration

#define	GFXMMU_LUT487L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT487L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT487L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT487L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT487L_EN			(0x1u<<0)

#define	GFXMMU_LUT487L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT487L_EN_B_0X1		(0x1u<<0)

// LUT487H Configuration

#define	GFXMMU_LUT487H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT487H_LO_0			(0x1u<<0)

// LUT488L Configuration

#define	GFXMMU_LUT488L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT488L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT488L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT488L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT488L_EN			(0x1u<<0)

#define	GFXMMU_LUT488L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT488L_EN_B_0X1		(0x1u<<0)

// LUT488H Configuration

#define	GFXMMU_LUT488H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT488H_LO_0			(0x1u<<0)

// LUT489L Configuration

#define	GFXMMU_LUT489L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT489L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT489L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT489L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT489L_EN			(0x1u<<0)

#define	GFXMMU_LUT489L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT489L_EN_B_0X1		(0x1u<<0)

// LUT489H Configuration

#define	GFXMMU_LUT489H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT489H_LO_0			(0x1u<<0)

// LUT490L Configuration

#define	GFXMMU_LUT490L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT490L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT490L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT490L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT490L_EN			(0x1u<<0)

#define	GFXMMU_LUT490L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT490L_EN_B_0X1		(0x1u<<0)

// LUT490H Configuration

#define	GFXMMU_LUT490H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT490H_LO_0			(0x1u<<0)

// LUT491L Configuration

#define	GFXMMU_LUT491L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT491L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT491L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT491L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT491L_EN			(0x1u<<0)

#define	GFXMMU_LUT491L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT491L_EN_B_0X1		(0x1u<<0)

// LUT491H Configuration

#define	GFXMMU_LUT491H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT491H_LO_0			(0x1u<<0)

// LUT492L Configuration

#define	GFXMMU_LUT492L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT492L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT492L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT492L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT492L_EN			(0x1u<<0)

#define	GFXMMU_LUT492L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT492L_EN_B_0X1		(0x1u<<0)

// LUT492H Configuration

#define	GFXMMU_LUT492H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT492H_LO_0			(0x1u<<0)

// LUT493L Configuration

#define	GFXMMU_LUT493L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT493L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT493L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT493L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT493L_EN			(0x1u<<0)

#define	GFXMMU_LUT493L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT493L_EN_B_0X1		(0x1u<<0)

// LUT493H Configuration

#define	GFXMMU_LUT493H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT493H_LO_0			(0x1u<<0)

// LUT494L Configuration

#define	GFXMMU_LUT494L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT494L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT494L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT494L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT494L_EN			(0x1u<<0)

#define	GFXMMU_LUT494L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT494L_EN_B_0X1		(0x1u<<0)

// LUT494H Configuration

#define	GFXMMU_LUT494H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT494H_LO_0			(0x1u<<0)

// LUT495L Configuration

#define	GFXMMU_LUT495L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT495L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT495L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT495L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT495L_EN			(0x1u<<0)

#define	GFXMMU_LUT495L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT495L_EN_B_0X1		(0x1u<<0)

// LUT495H Configuration

#define	GFXMMU_LUT495H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT495H_LO_0			(0x1u<<0)

// LUT496L Configuration

#define	GFXMMU_LUT496L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT496L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT496L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT496L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT496L_EN			(0x1u<<0)

#define	GFXMMU_LUT496L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT496L_EN_B_0X1		(0x1u<<0)

// LUT496H Configuration

#define	GFXMMU_LUT496H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT496H_LO_0			(0x1u<<0)

// LUT497L Configuration

#define	GFXMMU_LUT497L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT497L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT497L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT497L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT497L_EN			(0x1u<<0)

#define	GFXMMU_LUT497L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT497L_EN_B_0X1		(0x1u<<0)

// LUT497H Configuration

#define	GFXMMU_LUT497H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT497H_LO_0			(0x1u<<0)

// LUT498L Configuration

#define	GFXMMU_LUT498L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT498L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT498L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT498L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT498L_EN			(0x1u<<0)

#define	GFXMMU_LUT498L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT498L_EN_B_0X1		(0x1u<<0)

// LUT498H Configuration

#define	GFXMMU_LUT498H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT498H_LO_0			(0x1u<<0)

// LUT499L Configuration

#define	GFXMMU_LUT499L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT499L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT499L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT499L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT499L_EN			(0x1u<<0)

#define	GFXMMU_LUT499L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT499L_EN_B_0X1		(0x1u<<0)

// LUT499H Configuration

#define	GFXMMU_LUT499H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT499H_LO_0			(0x1u<<0)

// LUT500L Configuration

#define	GFXMMU_LUT500L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT500L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT500L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT500L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT500L_EN			(0x1u<<0)

#define	GFXMMU_LUT500L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT500L_EN_B_0X1		(0x1u<<0)

// LUT500H Configuration

#define	GFXMMU_LUT500H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT500H_LO_0			(0x1u<<0)

// LUT501L Configuration

#define	GFXMMU_LUT501L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT501L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT501L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT501L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT501L_EN			(0x1u<<0)

#define	GFXMMU_LUT501L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT501L_EN_B_0X1		(0x1u<<0)

// LUT501H Configuration

#define	GFXMMU_LUT501H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT501H_LO_0			(0x1u<<0)

// LUT502L Configuration

#define	GFXMMU_LUT502L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT502L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT502L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT502L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT502L_EN			(0x1u<<0)

#define	GFXMMU_LUT502L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT502L_EN_B_0X1		(0x1u<<0)

// LUT502H Configuration

#define	GFXMMU_LUT502H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT502H_LO_0			(0x1u<<0)

// LUT503L Configuration

#define	GFXMMU_LUT503L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT503L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT503L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT503L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT503L_EN			(0x1u<<0)

#define	GFXMMU_LUT503L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT503L_EN_B_0X1		(0x1u<<0)

// LUT503H Configuration

#define	GFXMMU_LUT503H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT503H_LO_0			(0x1u<<0)

// LUT504L Configuration

#define	GFXMMU_LUT504L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT504L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT504L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT504L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT504L_EN			(0x1u<<0)

#define	GFXMMU_LUT504L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT504L_EN_B_0X1		(0x1u<<0)

// LUT504H Configuration

#define	GFXMMU_LUT504H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT504H_LO_0			(0x1u<<0)

// LUT505L Configuration

#define	GFXMMU_LUT505L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT505L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT505L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT505L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT505L_EN			(0x1u<<0)

#define	GFXMMU_LUT505L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT505L_EN_B_0X1		(0x1u<<0)

// LUT505H Configuration

#define	GFXMMU_LUT505H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT505H_LO_0			(0x1u<<0)

// LUT506L Configuration

#define	GFXMMU_LUT506L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT506L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT506L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT506L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT506L_EN			(0x1u<<0)

#define	GFXMMU_LUT506L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT506L_EN_B_0X1		(0x1u<<0)

// LUT506H Configuration

#define	GFXMMU_LUT506H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT506H_LO_0			(0x1u<<0)

// LUT507L Configuration

#define	GFXMMU_LUT507L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT507L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT507L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT507L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT507L_EN			(0x1u<<0)

#define	GFXMMU_LUT507L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT507L_EN_B_0X1		(0x1u<<0)

// LUT507H Configuration

#define	GFXMMU_LUT507H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT507H_LO_0			(0x1u<<0)

// LUT508L Configuration

#define	GFXMMU_LUT508L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT508L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT508L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT508L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT508L_EN			(0x1u<<0)

#define	GFXMMU_LUT508L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT508L_EN_B_0X1		(0x1u<<0)

// LUT508H Configuration

#define	GFXMMU_LUT508H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT508H_LO_0			(0x1u<<0)

// LUT509L Configuration

#define	GFXMMU_LUT509L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT509L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT509L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT509L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT509L_EN			(0x1u<<0)

#define	GFXMMU_LUT509L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT509L_EN_B_0X1		(0x1u<<0)

// LUT509H Configuration

#define	GFXMMU_LUT509H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT509H_LO_0			(0x1u<<0)

// LUT510L Configuration

#define	GFXMMU_LUT510L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT510L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT510L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT510L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT510L_EN			(0x1u<<0)

#define	GFXMMU_LUT510L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT510L_EN_B_0X1		(0x1u<<0)

// LUT510H Configuration

#define	GFXMMU_LUT510H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT510H_LO_0			(0x1u<<0)

// LUT511L Configuration

#define	GFXMMU_LUT511L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT511L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT511L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT511L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT511L_EN			(0x1u<<0)

#define	GFXMMU_LUT511L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT511L_EN_B_0X1		(0x1u<<0)

// LUT511H Configuration

#define	GFXMMU_LUT511H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT511H_LO_0			(0x1u<<0)

// LUT512L Configuration

#define	GFXMMU_LUT512L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT512L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT512L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT512L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT512L_EN			(0x1u<<0)

#define	GFXMMU_LUT512L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT512L_EN_B_0X1		(0x1u<<0)

// LUT512H Configuration

#define	GFXMMU_LUT512H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT512H_LO_0			(0x1u<<0)

// LUT513L Configuration

#define	GFXMMU_LUT513L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT513L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT513L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT513L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT513L_EN			(0x1u<<0)

#define	GFXMMU_LUT513L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT513L_EN_B_0X1		(0x1u<<0)

// LUT513H Configuration

#define	GFXMMU_LUT513H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT513H_LO_0			(0x1u<<0)

// LUT514L Configuration

#define	GFXMMU_LUT514L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT514L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT514L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT514L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT514L_EN			(0x1u<<0)

#define	GFXMMU_LUT514L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT514L_EN_B_0X1		(0x1u<<0)

// LUT514H Configuration

#define	GFXMMU_LUT514H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT514H_LO_0			(0x1u<<0)

// LUT515L Configuration

#define	GFXMMU_LUT515L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT515L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT515L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT515L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT515L_EN			(0x1u<<0)

#define	GFXMMU_LUT515L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT515L_EN_B_0X1		(0x1u<<0)

// LUT515H Configuration

#define	GFXMMU_LUT515H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT515H_LO_0			(0x1u<<0)

// LUT516L Configuration

#define	GFXMMU_LUT516L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT516L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT516L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT516L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT516L_EN			(0x1u<<0)

#define	GFXMMU_LUT516L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT516L_EN_B_0X1		(0x1u<<0)

// LUT516H Configuration

#define	GFXMMU_LUT516H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT516H_LO_0			(0x1u<<0)

// LUT517L Configuration

#define	GFXMMU_LUT517L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT517L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT517L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT517L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT517L_EN			(0x1u<<0)

#define	GFXMMU_LUT517L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT517L_EN_B_0X1		(0x1u<<0)

// LUT517H Configuration

#define	GFXMMU_LUT517H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT517H_LO_0			(0x1u<<0)

// LUT518L Configuration

#define	GFXMMU_LUT518L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT518L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT518L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT518L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT518L_EN			(0x1u<<0)

#define	GFXMMU_LUT518L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT518L_EN_B_0X1		(0x1u<<0)

// LUT518H Configuration

#define	GFXMMU_LUT518H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT518H_LO_0			(0x1u<<0)

// LUT519L Configuration

#define	GFXMMU_LUT519L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT519L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT519L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT519L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT519L_EN			(0x1u<<0)

#define	GFXMMU_LUT519L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT519L_EN_B_0X1		(0x1u<<0)

// LUT519H Configuration

#define	GFXMMU_LUT519H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT519H_LO_0			(0x1u<<0)

// LUT520L Configuration

#define	GFXMMU_LUT520L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT520L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT520L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT520L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT520L_EN			(0x1u<<0)

#define	GFXMMU_LUT520L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT520L_EN_B_0X1		(0x1u<<0)

// LUT520H Configuration

#define	GFXMMU_LUT520H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT520H_LO_0			(0x1u<<0)

// LUT521L Configuration

#define	GFXMMU_LUT521L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT521L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT521L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT521L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT521L_EN			(0x1u<<0)

#define	GFXMMU_LUT521L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT521L_EN_B_0X1		(0x1u<<0)

// LUT521H Configuration

#define	GFXMMU_LUT521H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT521H_LO_0			(0x1u<<0)

// LUT522L Configuration

#define	GFXMMU_LUT522L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT522L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT522L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT522L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT522L_EN			(0x1u<<0)

#define	GFXMMU_LUT522L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT522L_EN_B_0X1		(0x1u<<0)

// LUT522H Configuration

#define	GFXMMU_LUT522H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT522H_LO_0			(0x1u<<0)

// LUT523L Configuration

#define	GFXMMU_LUT523L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT523L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT523L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT523L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT523L_EN			(0x1u<<0)

#define	GFXMMU_LUT523L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT523L_EN_B_0X1		(0x1u<<0)

// LUT523H Configuration

#define	GFXMMU_LUT523H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT523H_LO_0			(0x1u<<0)

// LUT524L Configuration

#define	GFXMMU_LUT524L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT524L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT524L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT524L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT524L_EN			(0x1u<<0)

#define	GFXMMU_LUT524L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT524L_EN_B_0X1		(0x1u<<0)

// LUT524H Configuration

#define	GFXMMU_LUT524H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT524H_LO_0			(0x1u<<0)

// LUT525L Configuration

#define	GFXMMU_LUT525L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT525L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT525L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT525L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT525L_EN			(0x1u<<0)

#define	GFXMMU_LUT525L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT525L_EN_B_0X1		(0x1u<<0)

// LUT525H Configuration

#define	GFXMMU_LUT525H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT525H_LO_0			(0x1u<<0)

// LUT526L Configuration

#define	GFXMMU_LUT526L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT526L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT526L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT526L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT526L_EN			(0x1u<<0)

#define	GFXMMU_LUT526L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT526L_EN_B_0X1		(0x1u<<0)

// LUT526H Configuration

#define	GFXMMU_LUT526H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT526H_LO_0			(0x1u<<0)

// LUT527L Configuration

#define	GFXMMU_LUT527L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT527L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT527L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT527L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT527L_EN			(0x1u<<0)

#define	GFXMMU_LUT527L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT527L_EN_B_0X1		(0x1u<<0)

// LUT527H Configuration

#define	GFXMMU_LUT527H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT527H_LO_0			(0x1u<<0)

// LUT528L Configuration

#define	GFXMMU_LUT528L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT528L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT528L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT528L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT528L_EN			(0x1u<<0)

#define	GFXMMU_LUT528L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT528L_EN_B_0X1		(0x1u<<0)

// LUT528H Configuration

#define	GFXMMU_LUT528H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT528H_LO_0			(0x1u<<0)

// LUT529L Configuration

#define	GFXMMU_LUT529L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT529L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT529L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT529L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT529L_EN			(0x1u<<0)

#define	GFXMMU_LUT529L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT529L_EN_B_0X1		(0x1u<<0)

// LUT529H Configuration

#define	GFXMMU_LUT529H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT529H_LO_0			(0x1u<<0)

// LUT530L Configuration

#define	GFXMMU_LUT530L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT530L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT530L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT530L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT530L_EN			(0x1u<<0)

#define	GFXMMU_LUT530L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT530L_EN_B_0X1		(0x1u<<0)

// LUT530H Configuration

#define	GFXMMU_LUT530H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT530H_LO_0			(0x1u<<0)

// LUT531L Configuration

#define	GFXMMU_LUT531L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT531L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT531L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT531L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT531L_EN			(0x1u<<0)

#define	GFXMMU_LUT531L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT531L_EN_B_0X1		(0x1u<<0)

// LUT531H Configuration

#define	GFXMMU_LUT531H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT531H_LO_0			(0x1u<<0)

// LUT532L Configuration

#define	GFXMMU_LUT532L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT532L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT532L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT532L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT532L_EN			(0x1u<<0)

#define	GFXMMU_LUT532L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT532L_EN_B_0X1		(0x1u<<0)

// LUT532H Configuration

#define	GFXMMU_LUT532H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT532H_LO_0			(0x1u<<0)

// LUT533L Configuration

#define	GFXMMU_LUT533L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT533L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT533L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT533L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT533L_EN			(0x1u<<0)

#define	GFXMMU_LUT533L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT533L_EN_B_0X1		(0x1u<<0)

// LUT533H Configuration

#define	GFXMMU_LUT533H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT533H_LO_0			(0x1u<<0)

// LUT534L Configuration

#define	GFXMMU_LUT534L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT534L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT534L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT534L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT534L_EN			(0x1u<<0)

#define	GFXMMU_LUT534L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT534L_EN_B_0X1		(0x1u<<0)

// LUT534H Configuration

#define	GFXMMU_LUT534H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT534H_LO_0			(0x1u<<0)

// LUT535L Configuration

#define	GFXMMU_LUT535L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT535L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT535L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT535L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT535L_EN			(0x1u<<0)

#define	GFXMMU_LUT535L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT535L_EN_B_0X1		(0x1u<<0)

// LUT535H Configuration

#define	GFXMMU_LUT535H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT535H_LO_0			(0x1u<<0)

// LUT536L Configuration

#define	GFXMMU_LUT536L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT536L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT536L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT536L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT536L_EN			(0x1u<<0)

#define	GFXMMU_LUT536L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT536L_EN_B_0X1		(0x1u<<0)

// LUT536H Configuration

#define	GFXMMU_LUT536H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT536H_LO_0			(0x1u<<0)

// LUT537L Configuration

#define	GFXMMU_LUT537L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT537L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT537L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT537L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT537L_EN			(0x1u<<0)

#define	GFXMMU_LUT537L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT537L_EN_B_0X1		(0x1u<<0)

// LUT537H Configuration

#define	GFXMMU_LUT537H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT537H_LO_0			(0x1u<<0)

// LUT538L Configuration

#define	GFXMMU_LUT538L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT538L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT538L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT538L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT538L_EN			(0x1u<<0)

#define	GFXMMU_LUT538L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT538L_EN_B_0X1		(0x1u<<0)

// LUT538H Configuration

#define	GFXMMU_LUT538H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT538H_LO_0			(0x1u<<0)

// LUT539L Configuration

#define	GFXMMU_LUT539L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT539L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT539L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT539L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT539L_EN			(0x1u<<0)

#define	GFXMMU_LUT539L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT539L_EN_B_0X1		(0x1u<<0)

// LUT539H Configuration

#define	GFXMMU_LUT539H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT539H_LO_0			(0x1u<<0)

// LUT540L Configuration

#define	GFXMMU_LUT540L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT540L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT540L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT540L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT540L_EN			(0x1u<<0)

#define	GFXMMU_LUT540L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT540L_EN_B_0X1		(0x1u<<0)

// LUT540H Configuration

#define	GFXMMU_LUT540H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT540H_LO_0			(0x1u<<0)

// LUT541L Configuration

#define	GFXMMU_LUT541L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT541L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT541L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT541L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT541L_EN			(0x1u<<0)

#define	GFXMMU_LUT541L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT541L_EN_B_0X1		(0x1u<<0)

// LUT541H Configuration

#define	GFXMMU_LUT541H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT541H_LO_0			(0x1u<<0)

// LUT542L Configuration

#define	GFXMMU_LUT542L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT542L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT542L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT542L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT542L_EN			(0x1u<<0)

#define	GFXMMU_LUT542L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT542L_EN_B_0X1		(0x1u<<0)

// LUT542H Configuration

#define	GFXMMU_LUT542H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT542H_LO_0			(0x1u<<0)

// LUT543L Configuration

#define	GFXMMU_LUT543L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT543L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT543L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT543L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT543L_EN			(0x1u<<0)

#define	GFXMMU_LUT543L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT543L_EN_B_0X1		(0x1u<<0)

// LUT543H Configuration

#define	GFXMMU_LUT543H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT543H_LO_0			(0x1u<<0)

// LUT544L Configuration

#define	GFXMMU_LUT544L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT544L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT544L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT544L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT544L_EN			(0x1u<<0)

#define	GFXMMU_LUT544L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT544L_EN_B_0X1		(0x1u<<0)

// LUT544H Configuration

#define	GFXMMU_LUT544H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT544H_LO_0			(0x1u<<0)

// LUT545L Configuration

#define	GFXMMU_LUT545L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT545L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT545L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT545L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT545L_EN			(0x1u<<0)

#define	GFXMMU_LUT545L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT545L_EN_B_0X1		(0x1u<<0)

// LUT545H Configuration

#define	GFXMMU_LUT545H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT545H_LO_0			(0x1u<<0)

// LUT546L Configuration

#define	GFXMMU_LUT546L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT546L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT546L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT546L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT546L_EN			(0x1u<<0)

#define	GFXMMU_LUT546L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT546L_EN_B_0X1		(0x1u<<0)

// LUT546H Configuration

#define	GFXMMU_LUT546H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT546H_LO_0			(0x1u<<0)

// LUT547L Configuration

#define	GFXMMU_LUT547L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT547L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT547L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT547L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT547L_EN			(0x1u<<0)

#define	GFXMMU_LUT547L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT547L_EN_B_0X1		(0x1u<<0)

// LUT547H Configuration

#define	GFXMMU_LUT547H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT547H_LO_0			(0x1u<<0)

// LUT548L Configuration

#define	GFXMMU_LUT548L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT548L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT548L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT548L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT548L_EN			(0x1u<<0)

#define	GFXMMU_LUT548L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT548L_EN_B_0X1		(0x1u<<0)

// LUT548H Configuration

#define	GFXMMU_LUT548H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT548H_LO_0			(0x1u<<0)

// LUT549L Configuration

#define	GFXMMU_LUT549L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT549L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT549L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT549L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT549L_EN			(0x1u<<0)

#define	GFXMMU_LUT549L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT549L_EN_B_0X1		(0x1u<<0)

// LUT549H Configuration

#define	GFXMMU_LUT549H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT549H_LO_0			(0x1u<<0)

// LUT550L Configuration

#define	GFXMMU_LUT550L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT550L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT550L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT550L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT550L_EN			(0x1u<<0)

#define	GFXMMU_LUT550L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT550L_EN_B_0X1		(0x1u<<0)

// LUT550H Configuration

#define	GFXMMU_LUT550H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT550H_LO_0			(0x1u<<0)

// LUT551L Configuration

#define	GFXMMU_LUT551L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT551L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT551L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT551L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT551L_EN			(0x1u<<0)

#define	GFXMMU_LUT551L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT551L_EN_B_0X1		(0x1u<<0)

// LUT551H Configuration

#define	GFXMMU_LUT551H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT551H_LO_0			(0x1u<<0)

// LUT552L Configuration

#define	GFXMMU_LUT552L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT552L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT552L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT552L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT552L_EN			(0x1u<<0)

#define	GFXMMU_LUT552L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT552L_EN_B_0X1		(0x1u<<0)

// LUT552H Configuration

#define	GFXMMU_LUT552H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT552H_LO_0			(0x1u<<0)

// LUT553L Configuration

#define	GFXMMU_LUT553L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT553L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT553L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT553L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT553L_EN			(0x1u<<0)

#define	GFXMMU_LUT553L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT553L_EN_B_0X1		(0x1u<<0)

// LUT553H Configuration

#define	GFXMMU_LUT553H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT553H_LO_0			(0x1u<<0)

// LUT554L Configuration

#define	GFXMMU_LUT554L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT554L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT554L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT554L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT554L_EN			(0x1u<<0)

#define	GFXMMU_LUT554L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT554L_EN_B_0X1		(0x1u<<0)

// LUT554H Configuration

#define	GFXMMU_LUT554H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT554H_LO_0			(0x1u<<0)

// LUT555L Configuration

#define	GFXMMU_LUT555L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT555L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT555L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT555L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT555L_EN			(0x1u<<0)

#define	GFXMMU_LUT555L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT555L_EN_B_0X1		(0x1u<<0)

// LUT555H Configuration

#define	GFXMMU_LUT555H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT555H_LO_0			(0x1u<<0)

// LUT556L Configuration

#define	GFXMMU_LUT556L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT556L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT556L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT556L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT556L_EN			(0x1u<<0)

#define	GFXMMU_LUT556L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT556L_EN_B_0X1		(0x1u<<0)

// LUT556H Configuration

#define	GFXMMU_LUT556H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT556H_LO_0			(0x1u<<0)

// LUT557L Configuration

#define	GFXMMU_LUT557L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT557L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT557L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT557L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT557L_EN			(0x1u<<0)

#define	GFXMMU_LUT557L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT557L_EN_B_0X1		(0x1u<<0)

// LUT557H Configuration

#define	GFXMMU_LUT557H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT557H_LO_0			(0x1u<<0)

// LUT558L Configuration

#define	GFXMMU_LUT558L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT558L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT558L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT558L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT558L_EN			(0x1u<<0)

#define	GFXMMU_LUT558L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT558L_EN_B_0X1		(0x1u<<0)

// LUT558H Configuration

#define	GFXMMU_LUT558H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT558H_LO_0			(0x1u<<0)

// LUT559L Configuration

#define	GFXMMU_LUT559L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT559L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT559L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT559L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT559L_EN			(0x1u<<0)

#define	GFXMMU_LUT559L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT559L_EN_B_0X1		(0x1u<<0)

// LUT559H Configuration

#define	GFXMMU_LUT559H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT559H_LO_0			(0x1u<<0)

// LUT560L Configuration

#define	GFXMMU_LUT560L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT560L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT560L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT560L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT560L_EN			(0x1u<<0)

#define	GFXMMU_LUT560L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT560L_EN_B_0X1		(0x1u<<0)

// LUT560H Configuration

#define	GFXMMU_LUT560H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT560H_LO_0			(0x1u<<0)

// LUT561L Configuration

#define	GFXMMU_LUT561L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT561L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT561L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT561L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT561L_EN			(0x1u<<0)

#define	GFXMMU_LUT561L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT561L_EN_B_0X1		(0x1u<<0)

// LUT561H Configuration

#define	GFXMMU_LUT561H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT561H_LO_0			(0x1u<<0)

// LUT562L Configuration

#define	GFXMMU_LUT562L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT562L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT562L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT562L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT562L_EN			(0x1u<<0)

#define	GFXMMU_LUT562L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT562L_EN_B_0X1		(0x1u<<0)

// LUT562H Configuration

#define	GFXMMU_LUT562H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT562H_LO_0			(0x1u<<0)

// LUT563L Configuration

#define	GFXMMU_LUT563L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT563L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT563L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT563L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT563L_EN			(0x1u<<0)

#define	GFXMMU_LUT563L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT563L_EN_B_0X1		(0x1u<<0)

// LUT563H Configuration

#define	GFXMMU_LUT563H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT563H_LO_0			(0x1u<<0)

// LUT564L Configuration

#define	GFXMMU_LUT564L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT564L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT564L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT564L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT564L_EN			(0x1u<<0)

#define	GFXMMU_LUT564L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT564L_EN_B_0X1		(0x1u<<0)

// LUT564H Configuration

#define	GFXMMU_LUT564H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT564H_LO_0			(0x1u<<0)

// LUT565L Configuration

#define	GFXMMU_LUT565L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT565L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT565L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT565L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT565L_EN			(0x1u<<0)

#define	GFXMMU_LUT565L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT565L_EN_B_0X1		(0x1u<<0)

// LUT565H Configuration

#define	GFXMMU_LUT565H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT565H_LO_0			(0x1u<<0)

// LUT566L Configuration

#define	GFXMMU_LUT566L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT566L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT566L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT566L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT566L_EN			(0x1u<<0)

#define	GFXMMU_LUT566L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT566L_EN_B_0X1		(0x1u<<0)

// LUT566H Configuration

#define	GFXMMU_LUT566H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT566H_LO_0			(0x1u<<0)

// LUT567L Configuration

#define	GFXMMU_LUT567L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT567L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT567L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT567L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT567L_EN			(0x1u<<0)

#define	GFXMMU_LUT567L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT567L_EN_B_0X1		(0x1u<<0)

// LUT567H Configuration

#define	GFXMMU_LUT567H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT567H_LO_0			(0x1u<<0)

// LUT568L Configuration

#define	GFXMMU_LUT568L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT568L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT568L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT568L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT568L_EN			(0x1u<<0)

#define	GFXMMU_LUT568L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT568L_EN_B_0X1		(0x1u<<0)

// LUT568H Configuration

#define	GFXMMU_LUT568H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT568H_LO_0			(0x1u<<0)

// LUT569L Configuration

#define	GFXMMU_LUT569L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT569L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT569L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT569L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT569L_EN			(0x1u<<0)

#define	GFXMMU_LUT569L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT569L_EN_B_0X1		(0x1u<<0)

// LUT569H Configuration

#define	GFXMMU_LUT569H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT569H_LO_0			(0x1u<<0)

// LUT570L Configuration

#define	GFXMMU_LUT570L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT570L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT570L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT570L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT570L_EN			(0x1u<<0)

#define	GFXMMU_LUT570L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT570L_EN_B_0X1		(0x1u<<0)

// LUT570H Configuration

#define	GFXMMU_LUT570H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT570H_LO_0			(0x1u<<0)

// LUT571L Configuration

#define	GFXMMU_LUT571L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT571L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT571L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT571L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT571L_EN			(0x1u<<0)

#define	GFXMMU_LUT571L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT571L_EN_B_0X1		(0x1u<<0)

// LUT571H Configuration

#define	GFXMMU_LUT571H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT571H_LO_0			(0x1u<<0)

// LUT572L Configuration

#define	GFXMMU_LUT572L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT572L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT572L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT572L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT572L_EN			(0x1u<<0)

#define	GFXMMU_LUT572L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT572L_EN_B_0X1		(0x1u<<0)

// LUT572H Configuration

#define	GFXMMU_LUT572H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT572H_LO_0			(0x1u<<0)

// LUT573L Configuration

#define	GFXMMU_LUT573L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT573L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT573L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT573L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT573L_EN			(0x1u<<0)

#define	GFXMMU_LUT573L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT573L_EN_B_0X1		(0x1u<<0)

// LUT573H Configuration

#define	GFXMMU_LUT573H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT573H_LO_0			(0x1u<<0)

// LUT574L Configuration

#define	GFXMMU_LUT574L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT574L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT574L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT574L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT574L_EN			(0x1u<<0)

#define	GFXMMU_LUT574L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT574L_EN_B_0X1		(0x1u<<0)

// LUT574H Configuration

#define	GFXMMU_LUT574H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT574H_LO_0			(0x1u<<0)

// LUT575L Configuration

#define	GFXMMU_LUT575L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT575L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT575L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT575L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT575L_EN			(0x1u<<0)

#define	GFXMMU_LUT575L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT575L_EN_B_0X1		(0x1u<<0)

// LUT575H Configuration

#define	GFXMMU_LUT575H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT575H_LO_0			(0x1u<<0)

// LUT576L Configuration

#define	GFXMMU_LUT576L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT576L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT576L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT576L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT576L_EN			(0x1u<<0)

#define	GFXMMU_LUT576L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT576L_EN_B_0X1		(0x1u<<0)

// LUT576H Configuration

#define	GFXMMU_LUT576H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT576H_LO_0			(0x1u<<0)

// LUT577L Configuration

#define	GFXMMU_LUT577L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT577L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT577L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT577L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT577L_EN			(0x1u<<0)

#define	GFXMMU_LUT577L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT577L_EN_B_0X1		(0x1u<<0)

// LUT577H Configuration

#define	GFXMMU_LUT577H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT577H_LO_0			(0x1u<<0)

// LUT578L Configuration

#define	GFXMMU_LUT578L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT578L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT578L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT578L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT578L_EN			(0x1u<<0)

#define	GFXMMU_LUT578L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT578L_EN_B_0X1		(0x1u<<0)

// LUT578H Configuration

#define	GFXMMU_LUT578H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT578H_LO_0			(0x1u<<0)

// LUT579L Configuration

#define	GFXMMU_LUT579L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT579L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT579L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT579L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT579L_EN			(0x1u<<0)

#define	GFXMMU_LUT579L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT579L_EN_B_0X1		(0x1u<<0)

// LUT579H Configuration

#define	GFXMMU_LUT579H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT579H_LO_0			(0x1u<<0)

// LUT580L Configuration

#define	GFXMMU_LUT580L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT580L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT580L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT580L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT580L_EN			(0x1u<<0)

#define	GFXMMU_LUT580L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT580L_EN_B_0X1		(0x1u<<0)

// LUT580H Configuration

#define	GFXMMU_LUT580H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT580H_LO_0			(0x1u<<0)

// LUT581L Configuration

#define	GFXMMU_LUT581L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT581L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT581L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT581L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT581L_EN			(0x1u<<0)

#define	GFXMMU_LUT581L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT581L_EN_B_0X1		(0x1u<<0)

// LUT581H Configuration

#define	GFXMMU_LUT581H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT581H_LO_0			(0x1u<<0)

// LUT582L Configuration

#define	GFXMMU_LUT582L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT582L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT582L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT582L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT582L_EN			(0x1u<<0)

#define	GFXMMU_LUT582L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT582L_EN_B_0X1		(0x1u<<0)

// LUT582H Configuration

#define	GFXMMU_LUT582H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT582H_LO_0			(0x1u<<0)

// LUT583L Configuration

#define	GFXMMU_LUT583L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT583L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT583L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT583L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT583L_EN			(0x1u<<0)

#define	GFXMMU_LUT583L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT583L_EN_B_0X1		(0x1u<<0)

// LUT583H Configuration

#define	GFXMMU_LUT583H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT583H_LO_0			(0x1u<<0)

// LUT584L Configuration

#define	GFXMMU_LUT584L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT584L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT584L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT584L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT584L_EN			(0x1u<<0)

#define	GFXMMU_LUT584L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT584L_EN_B_0X1		(0x1u<<0)

// LUT584H Configuration

#define	GFXMMU_LUT584H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT584H_LO_0			(0x1u<<0)

// LUT585L Configuration

#define	GFXMMU_LUT585L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT585L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT585L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT585L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT585L_EN			(0x1u<<0)

#define	GFXMMU_LUT585L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT585L_EN_B_0X1		(0x1u<<0)

// LUT585H Configuration

#define	GFXMMU_LUT585H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT585H_LO_0			(0x1u<<0)

// LUT586L Configuration

#define	GFXMMU_LUT586L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT586L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT586L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT586L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT586L_EN			(0x1u<<0)

#define	GFXMMU_LUT586L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT586L_EN_B_0X1		(0x1u<<0)

// LUT586H Configuration

#define	GFXMMU_LUT586H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT586H_LO_0			(0x1u<<0)

// LUT587L Configuration

#define	GFXMMU_LUT587L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT587L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT587L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT587L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT587L_EN			(0x1u<<0)

#define	GFXMMU_LUT587L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT587L_EN_B_0X1		(0x1u<<0)

// LUT587H Configuration

#define	GFXMMU_LUT587H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT587H_LO_0			(0x1u<<0)

// LUT588L Configuration

#define	GFXMMU_LUT588L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT588L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT588L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT588L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT588L_EN			(0x1u<<0)

#define	GFXMMU_LUT588L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT588L_EN_B_0X1		(0x1u<<0)

// LUT588H Configuration

#define	GFXMMU_LUT588H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT588H_LO_0			(0x1u<<0)

// LUT589L Configuration

#define	GFXMMU_LUT589L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT589L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT589L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT589L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT589L_EN			(0x1u<<0)

#define	GFXMMU_LUT589L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT589L_EN_B_0X1		(0x1u<<0)

// LUT589H Configuration

#define	GFXMMU_LUT589H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT589H_LO_0			(0x1u<<0)

// LUT590L Configuration

#define	GFXMMU_LUT590L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT590L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT590L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT590L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT590L_EN			(0x1u<<0)

#define	GFXMMU_LUT590L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT590L_EN_B_0X1		(0x1u<<0)

// LUT590H Configuration

#define	GFXMMU_LUT590H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT590H_LO_0			(0x1u<<0)

// LUT591L Configuration

#define	GFXMMU_LUT591L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT591L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT591L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT591L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT591L_EN			(0x1u<<0)

#define	GFXMMU_LUT591L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT591L_EN_B_0X1		(0x1u<<0)

// LUT591H Configuration

#define	GFXMMU_LUT591H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT591H_LO_0			(0x1u<<0)

// LUT592L Configuration

#define	GFXMMU_LUT592L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT592L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT592L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT592L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT592L_EN			(0x1u<<0)

#define	GFXMMU_LUT592L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT592L_EN_B_0X1		(0x1u<<0)

// LUT592H Configuration

#define	GFXMMU_LUT592H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT592H_LO_0			(0x1u<<0)

// LUT593L Configuration

#define	GFXMMU_LUT593L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT593L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT593L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT593L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT593L_EN			(0x1u<<0)

#define	GFXMMU_LUT593L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT593L_EN_B_0X1		(0x1u<<0)

// LUT593H Configuration

#define	GFXMMU_LUT593H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT593H_LO_0			(0x1u<<0)

// LUT594L Configuration

#define	GFXMMU_LUT594L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT594L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT594L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT594L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT594L_EN			(0x1u<<0)

#define	GFXMMU_LUT594L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT594L_EN_B_0X1		(0x1u<<0)

// LUT594H Configuration

#define	GFXMMU_LUT594H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT594H_LO_0			(0x1u<<0)

// LUT595L Configuration

#define	GFXMMU_LUT595L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT595L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT595L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT595L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT595L_EN			(0x1u<<0)

#define	GFXMMU_LUT595L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT595L_EN_B_0X1		(0x1u<<0)

// LUT595H Configuration

#define	GFXMMU_LUT595H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT595H_LO_0			(0x1u<<0)

// LUT596L Configuration

#define	GFXMMU_LUT596L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT596L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT596L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT596L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT596L_EN			(0x1u<<0)

#define	GFXMMU_LUT596L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT596L_EN_B_0X1		(0x1u<<0)

// LUT596H Configuration

#define	GFXMMU_LUT596H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT596H_LO_0			(0x1u<<0)

// LUT597L Configuration

#define	GFXMMU_LUT597L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT597L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT597L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT597L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT597L_EN			(0x1u<<0)

#define	GFXMMU_LUT597L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT597L_EN_B_0X1		(0x1u<<0)

// LUT597H Configuration

#define	GFXMMU_LUT597H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT597H_LO_0			(0x1u<<0)

// LUT598L Configuration

#define	GFXMMU_LUT598L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT598L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT598L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT598L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT598L_EN			(0x1u<<0)

#define	GFXMMU_LUT598L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT598L_EN_B_0X1		(0x1u<<0)

// LUT598H Configuration

#define	GFXMMU_LUT598H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT598H_LO_0			(0x1u<<0)

// LUT599L Configuration

#define	GFXMMU_LUT599L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT599L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT599L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT599L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT599L_EN			(0x1u<<0)

#define	GFXMMU_LUT599L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT599L_EN_B_0X1		(0x1u<<0)

// LUT599H Configuration

#define	GFXMMU_LUT599H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT599H_LO_0			(0x1u<<0)

// LUT600L Configuration

#define	GFXMMU_LUT600L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT600L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT600L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT600L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT600L_EN			(0x1u<<0)

#define	GFXMMU_LUT600L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT600L_EN_B_0X1		(0x1u<<0)

// LUT600H Configuration

#define	GFXMMU_LUT600H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT600H_LO_0			(0x1u<<0)

// LUT601L Configuration

#define	GFXMMU_LUT601L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT601L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT601L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT601L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT601L_EN			(0x1u<<0)

#define	GFXMMU_LUT601L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT601L_EN_B_0X1		(0x1u<<0)

// LUT601H Configuration

#define	GFXMMU_LUT601H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT601H_LO_0			(0x1u<<0)

// LUT602L Configuration

#define	GFXMMU_LUT602L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT602L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT602L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT602L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT602L_EN			(0x1u<<0)

#define	GFXMMU_LUT602L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT602L_EN_B_0X1		(0x1u<<0)

// LUT602H Configuration

#define	GFXMMU_LUT602H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT602H_LO_0			(0x1u<<0)

// LUT603L Configuration

#define	GFXMMU_LUT603L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT603L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT603L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT603L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT603L_EN			(0x1u<<0)

#define	GFXMMU_LUT603L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT603L_EN_B_0X1		(0x1u<<0)

// LUT603H Configuration

#define	GFXMMU_LUT603H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT603H_LO_0			(0x1u<<0)

// LUT604L Configuration

#define	GFXMMU_LUT604L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT604L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT604L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT604L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT604L_EN			(0x1u<<0)

#define	GFXMMU_LUT604L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT604L_EN_B_0X1		(0x1u<<0)

// LUT604H Configuration

#define	GFXMMU_LUT604H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT604H_LO_0			(0x1u<<0)

// LUT605L Configuration

#define	GFXMMU_LUT605L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT605L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT605L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT605L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT605L_EN			(0x1u<<0)

#define	GFXMMU_LUT605L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT605L_EN_B_0X1		(0x1u<<0)

// LUT605H Configuration

#define	GFXMMU_LUT605H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT605H_LO_0			(0x1u<<0)

// LUT606L Configuration

#define	GFXMMU_LUT606L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT606L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT606L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT606L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT606L_EN			(0x1u<<0)

#define	GFXMMU_LUT606L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT606L_EN_B_0X1		(0x1u<<0)

// LUT606H Configuration

#define	GFXMMU_LUT606H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT606H_LO_0			(0x1u<<0)

// LUT607L Configuration

#define	GFXMMU_LUT607L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT607L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT607L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT607L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT607L_EN			(0x1u<<0)

#define	GFXMMU_LUT607L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT607L_EN_B_0X1		(0x1u<<0)

// LUT607H Configuration

#define	GFXMMU_LUT607H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT607H_LO_0			(0x1u<<0)

// LUT608L Configuration

#define	GFXMMU_LUT608L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT608L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT608L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT608L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT608L_EN			(0x1u<<0)

#define	GFXMMU_LUT608L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT608L_EN_B_0X1		(0x1u<<0)

// LUT608H Configuration

#define	GFXMMU_LUT608H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT608H_LO_0			(0x1u<<0)

// LUT609L Configuration

#define	GFXMMU_LUT609L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT609L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT609L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT609L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT609L_EN			(0x1u<<0)

#define	GFXMMU_LUT609L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT609L_EN_B_0X1		(0x1u<<0)

// LUT609H Configuration

#define	GFXMMU_LUT609H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT609H_LO_0			(0x1u<<0)

// LUT610L Configuration

#define	GFXMMU_LUT610L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT610L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT610L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT610L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT610L_EN			(0x1u<<0)

#define	GFXMMU_LUT610L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT610L_EN_B_0X1		(0x1u<<0)

// LUT610H Configuration

#define	GFXMMU_LUT610H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT610H_LO_0			(0x1u<<0)

// LUT611L Configuration

#define	GFXMMU_LUT611L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT611L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT611L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT611L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT611L_EN			(0x1u<<0)

#define	GFXMMU_LUT611L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT611L_EN_B_0X1		(0x1u<<0)

// LUT611H Configuration

#define	GFXMMU_LUT611H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT611H_LO_0			(0x1u<<0)

// LUT612L Configuration

#define	GFXMMU_LUT612L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT612L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT612L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT612L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT612L_EN			(0x1u<<0)

#define	GFXMMU_LUT612L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT612L_EN_B_0X1		(0x1u<<0)

// LUT612H Configuration

#define	GFXMMU_LUT612H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT612H_LO_0			(0x1u<<0)

// LUT613L Configuration

#define	GFXMMU_LUT613L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT613L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT613L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT613L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT613L_EN			(0x1u<<0)

#define	GFXMMU_LUT613L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT613L_EN_B_0X1		(0x1u<<0)

// LUT613H Configuration

#define	GFXMMU_LUT613H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT613H_LO_0			(0x1u<<0)

// LUT614L Configuration

#define	GFXMMU_LUT614L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT614L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT614L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT614L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT614L_EN			(0x1u<<0)

#define	GFXMMU_LUT614L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT614L_EN_B_0X1		(0x1u<<0)

// LUT614H Configuration

#define	GFXMMU_LUT614H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT614H_LO_0			(0x1u<<0)

// LUT615L Configuration

#define	GFXMMU_LUT615L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT615L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT615L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT615L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT615L_EN			(0x1u<<0)

#define	GFXMMU_LUT615L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT615L_EN_B_0X1		(0x1u<<0)

// LUT615H Configuration

#define	GFXMMU_LUT615H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT615H_LO_0			(0x1u<<0)

// LUT616L Configuration

#define	GFXMMU_LUT616L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT616L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT616L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT616L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT616L_EN			(0x1u<<0)

#define	GFXMMU_LUT616L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT616L_EN_B_0X1		(0x1u<<0)

// LUT616H Configuration

#define	GFXMMU_LUT616H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT616H_LO_0			(0x1u<<0)

// LUT617L Configuration

#define	GFXMMU_LUT617L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT617L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT617L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT617L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT617L_EN			(0x1u<<0)

#define	GFXMMU_LUT617L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT617L_EN_B_0X1		(0x1u<<0)

// LUT617H Configuration

#define	GFXMMU_LUT617H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT617H_LO_0			(0x1u<<0)

// LUT618L Configuration

#define	GFXMMU_LUT618L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT618L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT618L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT618L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT618L_EN			(0x1u<<0)

#define	GFXMMU_LUT618L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT618L_EN_B_0X1		(0x1u<<0)

// LUT618H Configuration

#define	GFXMMU_LUT618H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT618H_LO_0			(0x1u<<0)

// LUT619L Configuration

#define	GFXMMU_LUT619L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT619L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT619L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT619L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT619L_EN			(0x1u<<0)

#define	GFXMMU_LUT619L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT619L_EN_B_0X1		(0x1u<<0)

// LUT619H Configuration

#define	GFXMMU_LUT619H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT619H_LO_0			(0x1u<<0)

// LUT620L Configuration

#define	GFXMMU_LUT620L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT620L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT620L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT620L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT620L_EN			(0x1u<<0)

#define	GFXMMU_LUT620L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT620L_EN_B_0X1		(0x1u<<0)

// LUT620H Configuration

#define	GFXMMU_LUT620H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT620H_LO_0			(0x1u<<0)

// LUT621L Configuration

#define	GFXMMU_LUT621L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT621L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT621L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT621L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT621L_EN			(0x1u<<0)

#define	GFXMMU_LUT621L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT621L_EN_B_0X1		(0x1u<<0)

// LUT621H Configuration

#define	GFXMMU_LUT621H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT621H_LO_0			(0x1u<<0)

// LUT622L Configuration

#define	GFXMMU_LUT622L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT622L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT622L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT622L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT622L_EN			(0x1u<<0)

#define	GFXMMU_LUT622L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT622L_EN_B_0X1		(0x1u<<0)

// LUT622H Configuration

#define	GFXMMU_LUT622H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT622H_LO_0			(0x1u<<0)

// LUT623L Configuration

#define	GFXMMU_LUT623L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT623L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT623L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT623L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT623L_EN			(0x1u<<0)

#define	GFXMMU_LUT623L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT623L_EN_B_0X1		(0x1u<<0)

// LUT623H Configuration

#define	GFXMMU_LUT623H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT623H_LO_0			(0x1u<<0)

// LUT624L Configuration

#define	GFXMMU_LUT624L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT624L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT624L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT624L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT624L_EN			(0x1u<<0)

#define	GFXMMU_LUT624L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT624L_EN_B_0X1		(0x1u<<0)

// LUT624H Configuration

#define	GFXMMU_LUT624H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT624H_LO_0			(0x1u<<0)

// LUT625L Configuration

#define	GFXMMU_LUT625L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT625L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT625L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT625L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT625L_EN			(0x1u<<0)

#define	GFXMMU_LUT625L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT625L_EN_B_0X1		(0x1u<<0)

// LUT625H Configuration

#define	GFXMMU_LUT625H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT625H_LO_0			(0x1u<<0)

// LUT626L Configuration

#define	GFXMMU_LUT626L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT626L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT626L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT626L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT626L_EN			(0x1u<<0)

#define	GFXMMU_LUT626L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT626L_EN_B_0X1		(0x1u<<0)

// LUT626H Configuration

#define	GFXMMU_LUT626H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT626H_LO_0			(0x1u<<0)

// LUT627L Configuration

#define	GFXMMU_LUT627L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT627L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT627L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT627L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT627L_EN			(0x1u<<0)

#define	GFXMMU_LUT627L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT627L_EN_B_0X1		(0x1u<<0)

// LUT627H Configuration

#define	GFXMMU_LUT627H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT627H_LO_0			(0x1u<<0)

// LUT628L Configuration

#define	GFXMMU_LUT628L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT628L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT628L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT628L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT628L_EN			(0x1u<<0)

#define	GFXMMU_LUT628L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT628L_EN_B_0X1		(0x1u<<0)

// LUT628H Configuration

#define	GFXMMU_LUT628H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT628H_LO_0			(0x1u<<0)

// LUT629L Configuration

#define	GFXMMU_LUT629L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT629L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT629L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT629L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT629L_EN			(0x1u<<0)

#define	GFXMMU_LUT629L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT629L_EN_B_0X1		(0x1u<<0)

// LUT629H Configuration

#define	GFXMMU_LUT629H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT629H_LO_0			(0x1u<<0)

// LUT630L Configuration

#define	GFXMMU_LUT630L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT630L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT630L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT630L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT630L_EN			(0x1u<<0)

#define	GFXMMU_LUT630L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT630L_EN_B_0X1		(0x1u<<0)

// LUT630H Configuration

#define	GFXMMU_LUT630H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT630H_LO_0			(0x1u<<0)

// LUT631L Configuration

#define	GFXMMU_LUT631L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT631L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT631L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT631L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT631L_EN			(0x1u<<0)

#define	GFXMMU_LUT631L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT631L_EN_B_0X1		(0x1u<<0)

// LUT631H Configuration

#define	GFXMMU_LUT631H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT631H_LO_0			(0x1u<<0)

// LUT632L Configuration

#define	GFXMMU_LUT632L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT632L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT632L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT632L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT632L_EN			(0x1u<<0)

#define	GFXMMU_LUT632L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT632L_EN_B_0X1		(0x1u<<0)

// LUT632H Configuration

#define	GFXMMU_LUT632H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT632H_LO_0			(0x1u<<0)

// LUT633L Configuration

#define	GFXMMU_LUT633L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT633L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT633L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT633L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT633L_EN			(0x1u<<0)

#define	GFXMMU_LUT633L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT633L_EN_B_0X1		(0x1u<<0)

// LUT633H Configuration

#define	GFXMMU_LUT633H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT633H_LO_0			(0x1u<<0)

// LUT634L Configuration

#define	GFXMMU_LUT634L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT634L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT634L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT634L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT634L_EN			(0x1u<<0)

#define	GFXMMU_LUT634L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT634L_EN_B_0X1		(0x1u<<0)

// LUT634H Configuration

#define	GFXMMU_LUT634H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT634H_LO_0			(0x1u<<0)

// LUT635L Configuration

#define	GFXMMU_LUT635L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT635L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT635L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT635L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT635L_EN			(0x1u<<0)

#define	GFXMMU_LUT635L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT635L_EN_B_0X1		(0x1u<<0)

// LUT635H Configuration

#define	GFXMMU_LUT635H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT635H_LO_0			(0x1u<<0)

// LUT636L Configuration

#define	GFXMMU_LUT636L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT636L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT636L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT636L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT636L_EN			(0x1u<<0)

#define	GFXMMU_LUT636L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT636L_EN_B_0X1		(0x1u<<0)

// LUT636H Configuration

#define	GFXMMU_LUT636H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT636H_LO_0			(0x1u<<0)

// LUT637L Configuration

#define	GFXMMU_LUT637L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT637L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT637L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT637L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT637L_EN			(0x1u<<0)

#define	GFXMMU_LUT637L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT637L_EN_B_0X1		(0x1u<<0)

// LUT637H Configuration

#define	GFXMMU_LUT637H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT637H_LO_0			(0x1u<<0)

// LUT638L Configuration

#define	GFXMMU_LUT638L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT638L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT638L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT638L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT638L_EN			(0x1u<<0)

#define	GFXMMU_LUT638L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT638L_EN_B_0X1		(0x1u<<0)

// LUT638H Configuration

#define	GFXMMU_LUT638H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT638H_LO_0			(0x1u<<0)

// LUT639L Configuration

#define	GFXMMU_LUT639L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT639L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT639L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT639L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT639L_EN			(0x1u<<0)

#define	GFXMMU_LUT639L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT639L_EN_B_0X1		(0x1u<<0)

// LUT639H Configuration

#define	GFXMMU_LUT639H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT639H_LO_0			(0x1u<<0)

// LUT640L Configuration

#define	GFXMMU_LUT640L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT640L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT640L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT640L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT640L_EN			(0x1u<<0)

#define	GFXMMU_LUT640L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT640L_EN_B_0X1		(0x1u<<0)

// LUT640H Configuration

#define	GFXMMU_LUT640H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT640H_LO_0			(0x1u<<0)

// LUT641L Configuration

#define	GFXMMU_LUT641L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT641L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT641L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT641L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT641L_EN			(0x1u<<0)

#define	GFXMMU_LUT641L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT641L_EN_B_0X1		(0x1u<<0)

// LUT641H Configuration

#define	GFXMMU_LUT641H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT641H_LO_0			(0x1u<<0)

// LUT642L Configuration

#define	GFXMMU_LUT642L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT642L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT642L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT642L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT642L_EN			(0x1u<<0)

#define	GFXMMU_LUT642L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT642L_EN_B_0X1		(0x1u<<0)

// LUT642H Configuration

#define	GFXMMU_LUT642H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT642H_LO_0			(0x1u<<0)

// LUT643L Configuration

#define	GFXMMU_LUT643L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT643L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT643L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT643L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT643L_EN			(0x1u<<0)

#define	GFXMMU_LUT643L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT643L_EN_B_0X1		(0x1u<<0)

// LUT643H Configuration

#define	GFXMMU_LUT643H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT643H_LO_0			(0x1u<<0)

// LUT644L Configuration

#define	GFXMMU_LUT644L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT644L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT644L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT644L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT644L_EN			(0x1u<<0)

#define	GFXMMU_LUT644L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT644L_EN_B_0X1		(0x1u<<0)

// LUT644H Configuration

#define	GFXMMU_LUT644H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT644H_LO_0			(0x1u<<0)

// LUT645L Configuration

#define	GFXMMU_LUT645L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT645L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT645L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT645L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT645L_EN			(0x1u<<0)

#define	GFXMMU_LUT645L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT645L_EN_B_0X1		(0x1u<<0)

// LUT645H Configuration

#define	GFXMMU_LUT645H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT645H_LO_0			(0x1u<<0)

// LUT646L Configuration

#define	GFXMMU_LUT646L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT646L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT646L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT646L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT646L_EN			(0x1u<<0)

#define	GFXMMU_LUT646L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT646L_EN_B_0X1		(0x1u<<0)

// LUT646H Configuration

#define	GFXMMU_LUT646H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT646H_LO_0			(0x1u<<0)

// LUT647L Configuration

#define	GFXMMU_LUT647L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT647L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT647L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT647L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT647L_EN			(0x1u<<0)

#define	GFXMMU_LUT647L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT647L_EN_B_0X1		(0x1u<<0)

// LUT647H Configuration

#define	GFXMMU_LUT647H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT647H_LO_0			(0x1u<<0)

// LUT648L Configuration

#define	GFXMMU_LUT648L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT648L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT648L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT648L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT648L_EN			(0x1u<<0)

#define	GFXMMU_LUT648L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT648L_EN_B_0X1		(0x1u<<0)

// LUT648H Configuration

#define	GFXMMU_LUT648H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT648H_LO_0			(0x1u<<0)

// LUT649L Configuration

#define	GFXMMU_LUT649L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT649L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT649L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT649L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT649L_EN			(0x1u<<0)

#define	GFXMMU_LUT649L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT649L_EN_B_0X1		(0x1u<<0)

// LUT649H Configuration

#define	GFXMMU_LUT649H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT649H_LO_0			(0x1u<<0)

// LUT650L Configuration

#define	GFXMMU_LUT650L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT650L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT650L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT650L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT650L_EN			(0x1u<<0)

#define	GFXMMU_LUT650L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT650L_EN_B_0X1		(0x1u<<0)

// LUT650H Configuration

#define	GFXMMU_LUT650H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT650H_LO_0			(0x1u<<0)

// LUT651L Configuration

#define	GFXMMU_LUT651L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT651L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT651L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT651L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT651L_EN			(0x1u<<0)

#define	GFXMMU_LUT651L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT651L_EN_B_0X1		(0x1u<<0)

// LUT651H Configuration

#define	GFXMMU_LUT651H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT651H_LO_0			(0x1u<<0)

// LUT652L Configuration

#define	GFXMMU_LUT652L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT652L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT652L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT652L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT652L_EN			(0x1u<<0)

#define	GFXMMU_LUT652L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT652L_EN_B_0X1		(0x1u<<0)

// LUT652H Configuration

#define	GFXMMU_LUT652H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT652H_LO_0			(0x1u<<0)

// LUT653L Configuration

#define	GFXMMU_LUT653L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT653L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT653L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT653L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT653L_EN			(0x1u<<0)

#define	GFXMMU_LUT653L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT653L_EN_B_0X1		(0x1u<<0)

// LUT653H Configuration

#define	GFXMMU_LUT653H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT653H_LO_0			(0x1u<<0)

// LUT654L Configuration

#define	GFXMMU_LUT654L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT654L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT654L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT654L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT654L_EN			(0x1u<<0)

#define	GFXMMU_LUT654L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT654L_EN_B_0X1		(0x1u<<0)

// LUT654H Configuration

#define	GFXMMU_LUT654H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT654H_LO_0			(0x1u<<0)

// LUT655L Configuration

#define	GFXMMU_LUT655L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT655L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT655L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT655L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT655L_EN			(0x1u<<0)

#define	GFXMMU_LUT655L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT655L_EN_B_0X1		(0x1u<<0)

// LUT655H Configuration

#define	GFXMMU_LUT655H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT655H_LO_0			(0x1u<<0)

// LUT656L Configuration

#define	GFXMMU_LUT656L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT656L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT656L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT656L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT656L_EN			(0x1u<<0)

#define	GFXMMU_LUT656L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT656L_EN_B_0X1		(0x1u<<0)

// LUT656H Configuration

#define	GFXMMU_LUT656H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT656H_LO_0			(0x1u<<0)

// LUT657L Configuration

#define	GFXMMU_LUT657L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT657L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT657L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT657L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT657L_EN			(0x1u<<0)

#define	GFXMMU_LUT657L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT657L_EN_B_0X1		(0x1u<<0)

// LUT657H Configuration

#define	GFXMMU_LUT657H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT657H_LO_0			(0x1u<<0)

// LUT658L Configuration

#define	GFXMMU_LUT658L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT658L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT658L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT658L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT658L_EN			(0x1u<<0)

#define	GFXMMU_LUT658L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT658L_EN_B_0X1		(0x1u<<0)

// LUT658H Configuration

#define	GFXMMU_LUT658H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT658H_LO_0			(0x1u<<0)

// LUT659L Configuration

#define	GFXMMU_LUT659L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT659L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT659L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT659L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT659L_EN			(0x1u<<0)

#define	GFXMMU_LUT659L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT659L_EN_B_0X1		(0x1u<<0)

// LUT659H Configuration

#define	GFXMMU_LUT659H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT659H_LO_0			(0x1u<<0)

// LUT660L Configuration

#define	GFXMMU_LUT660L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT660L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT660L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT660L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT660L_EN			(0x1u<<0)

#define	GFXMMU_LUT660L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT660L_EN_B_0X1		(0x1u<<0)

// LUT660H Configuration

#define	GFXMMU_LUT660H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT660H_LO_0			(0x1u<<0)

// LUT661L Configuration

#define	GFXMMU_LUT661L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT661L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT661L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT661L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT661L_EN			(0x1u<<0)

#define	GFXMMU_LUT661L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT661L_EN_B_0X1		(0x1u<<0)

// LUT661H Configuration

#define	GFXMMU_LUT661H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT661H_LO_0			(0x1u<<0)

// LUT662L Configuration

#define	GFXMMU_LUT662L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT662L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT662L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT662L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT662L_EN			(0x1u<<0)

#define	GFXMMU_LUT662L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT662L_EN_B_0X1		(0x1u<<0)

// LUT662H Configuration

#define	GFXMMU_LUT662H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT662H_LO_0			(0x1u<<0)

// LUT663L Configuration

#define	GFXMMU_LUT663L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT663L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT663L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT663L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT663L_EN			(0x1u<<0)

#define	GFXMMU_LUT663L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT663L_EN_B_0X1		(0x1u<<0)

// LUT663H Configuration

#define	GFXMMU_LUT663H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT663H_LO_0			(0x1u<<0)

// LUT664L Configuration

#define	GFXMMU_LUT664L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT664L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT664L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT664L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT664L_EN			(0x1u<<0)

#define	GFXMMU_LUT664L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT664L_EN_B_0X1		(0x1u<<0)

// LUT664H Configuration

#define	GFXMMU_LUT664H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT664H_LO_0			(0x1u<<0)

// LUT665L Configuration

#define	GFXMMU_LUT665L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT665L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT665L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT665L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT665L_EN			(0x1u<<0)

#define	GFXMMU_LUT665L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT665L_EN_B_0X1		(0x1u<<0)

// LUT665H Configuration

#define	GFXMMU_LUT665H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT665H_LO_0			(0x1u<<0)

// LUT666L Configuration

#define	GFXMMU_LUT666L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT666L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT666L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT666L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT666L_EN			(0x1u<<0)

#define	GFXMMU_LUT666L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT666L_EN_B_0X1		(0x1u<<0)

// LUT666H Configuration

#define	GFXMMU_LUT666H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT666H_LO_0			(0x1u<<0)

// LUT667L Configuration

#define	GFXMMU_LUT667L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT667L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT667L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT667L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT667L_EN			(0x1u<<0)

#define	GFXMMU_LUT667L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT667L_EN_B_0X1		(0x1u<<0)

// LUT667H Configuration

#define	GFXMMU_LUT667H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT667H_LO_0			(0x1u<<0)

// LUT668L Configuration

#define	GFXMMU_LUT668L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT668L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT668L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT668L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT668L_EN			(0x1u<<0)

#define	GFXMMU_LUT668L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT668L_EN_B_0X1		(0x1u<<0)

// LUT668H Configuration

#define	GFXMMU_LUT668H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT668H_LO_0			(0x1u<<0)

// LUT669L Configuration

#define	GFXMMU_LUT669L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT669L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT669L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT669L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT669L_EN			(0x1u<<0)

#define	GFXMMU_LUT669L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT669L_EN_B_0X1		(0x1u<<0)

// LUT669H Configuration

#define	GFXMMU_LUT669H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT669H_LO_0			(0x1u<<0)

// LUT670L Configuration

#define	GFXMMU_LUT670L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT670L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT670L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT670L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT670L_EN			(0x1u<<0)

#define	GFXMMU_LUT670L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT670L_EN_B_0X1		(0x1u<<0)

// LUT670H Configuration

#define	GFXMMU_LUT670H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT670H_LO_0			(0x1u<<0)

// LUT671L Configuration

#define	GFXMMU_LUT671L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT671L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT671L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT671L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT671L_EN			(0x1u<<0)

#define	GFXMMU_LUT671L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT671L_EN_B_0X1		(0x1u<<0)

// LUT671H Configuration

#define	GFXMMU_LUT671H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT671H_LO_0			(0x1u<<0)

// LUT672L Configuration

#define	GFXMMU_LUT672L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT672L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT672L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT672L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT672L_EN			(0x1u<<0)

#define	GFXMMU_LUT672L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT672L_EN_B_0X1		(0x1u<<0)

// LUT672H Configuration

#define	GFXMMU_LUT672H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT672H_LO_0			(0x1u<<0)

// LUT673L Configuration

#define	GFXMMU_LUT673L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT673L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT673L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT673L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT673L_EN			(0x1u<<0)

#define	GFXMMU_LUT673L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT673L_EN_B_0X1		(0x1u<<0)

// LUT673H Configuration

#define	GFXMMU_LUT673H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT673H_LO_0			(0x1u<<0)

// LUT674L Configuration

#define	GFXMMU_LUT674L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT674L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT674L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT674L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT674L_EN			(0x1u<<0)

#define	GFXMMU_LUT674L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT674L_EN_B_0X1		(0x1u<<0)

// LUT674H Configuration

#define	GFXMMU_LUT674H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT674H_LO_0			(0x1u<<0)

// LUT675L Configuration

#define	GFXMMU_LUT675L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT675L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT675L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT675L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT675L_EN			(0x1u<<0)

#define	GFXMMU_LUT675L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT675L_EN_B_0X1		(0x1u<<0)

// LUT675H Configuration

#define	GFXMMU_LUT675H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT675H_LO_0			(0x1u<<0)

// LUT676L Configuration

#define	GFXMMU_LUT676L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT676L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT676L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT676L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT676L_EN			(0x1u<<0)

#define	GFXMMU_LUT676L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT676L_EN_B_0X1		(0x1u<<0)

// LUT676H Configuration

#define	GFXMMU_LUT676H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT676H_LO_0			(0x1u<<0)

// LUT677L Configuration

#define	GFXMMU_LUT677L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT677L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT677L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT677L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT677L_EN			(0x1u<<0)

#define	GFXMMU_LUT677L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT677L_EN_B_0X1		(0x1u<<0)

// LUT677H Configuration

#define	GFXMMU_LUT677H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT677H_LO_0			(0x1u<<0)

// LUT678L Configuration

#define	GFXMMU_LUT678L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT678L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT678L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT678L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT678L_EN			(0x1u<<0)

#define	GFXMMU_LUT678L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT678L_EN_B_0X1		(0x1u<<0)

// LUT678H Configuration

#define	GFXMMU_LUT678H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT678H_LO_0			(0x1u<<0)

// LUT679L Configuration

#define	GFXMMU_LUT679L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT679L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT679L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT679L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT679L_EN			(0x1u<<0)

#define	GFXMMU_LUT679L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT679L_EN_B_0X1		(0x1u<<0)

// LUT679H Configuration

#define	GFXMMU_LUT679H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT679H_LO_0			(0x1u<<0)

// LUT680L Configuration

#define	GFXMMU_LUT680L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT680L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT680L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT680L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT680L_EN			(0x1u<<0)

#define	GFXMMU_LUT680L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT680L_EN_B_0X1		(0x1u<<0)

// LUT680H Configuration

#define	GFXMMU_LUT680H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT680H_LO_0			(0x1u<<0)

// LUT681L Configuration

#define	GFXMMU_LUT681L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT681L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT681L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT681L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT681L_EN			(0x1u<<0)

#define	GFXMMU_LUT681L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT681L_EN_B_0X1		(0x1u<<0)

// LUT681H Configuration

#define	GFXMMU_LUT681H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT681H_LO_0			(0x1u<<0)

// LUT682L Configuration

#define	GFXMMU_LUT682L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT682L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT682L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT682L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT682L_EN			(0x1u<<0)

#define	GFXMMU_LUT682L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT682L_EN_B_0X1		(0x1u<<0)

// LUT682H Configuration

#define	GFXMMU_LUT682H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT682H_LO_0			(0x1u<<0)

// LUT683L Configuration

#define	GFXMMU_LUT683L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT683L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT683L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT683L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT683L_EN			(0x1u<<0)

#define	GFXMMU_LUT683L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT683L_EN_B_0X1		(0x1u<<0)

// LUT683H Configuration

#define	GFXMMU_LUT683H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT683H_LO_0			(0x1u<<0)

// LUT684L Configuration

#define	GFXMMU_LUT684L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT684L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT684L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT684L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT684L_EN			(0x1u<<0)

#define	GFXMMU_LUT684L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT684L_EN_B_0X1		(0x1u<<0)

// LUT684H Configuration

#define	GFXMMU_LUT684H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT684H_LO_0			(0x1u<<0)

// LUT685L Configuration

#define	GFXMMU_LUT685L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT685L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT685L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT685L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT685L_EN			(0x1u<<0)

#define	GFXMMU_LUT685L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT685L_EN_B_0X1		(0x1u<<0)

// LUT685H Configuration

#define	GFXMMU_LUT685H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT685H_LO_0			(0x1u<<0)

// LUT686L Configuration

#define	GFXMMU_LUT686L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT686L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT686L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT686L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT686L_EN			(0x1u<<0)

#define	GFXMMU_LUT686L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT686L_EN_B_0X1		(0x1u<<0)

// LUT686H Configuration

#define	GFXMMU_LUT686H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT686H_LO_0			(0x1u<<0)

// LUT687L Configuration

#define	GFXMMU_LUT687L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT687L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT687L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT687L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT687L_EN			(0x1u<<0)

#define	GFXMMU_LUT687L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT687L_EN_B_0X1		(0x1u<<0)

// LUT687H Configuration

#define	GFXMMU_LUT687H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT687H_LO_0			(0x1u<<0)

// LUT688L Configuration

#define	GFXMMU_LUT688L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT688L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT688L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT688L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT688L_EN			(0x1u<<0)

#define	GFXMMU_LUT688L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT688L_EN_B_0X1		(0x1u<<0)

// LUT688H Configuration

#define	GFXMMU_LUT688H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT688H_LO_0			(0x1u<<0)

// LUT689L Configuration

#define	GFXMMU_LUT689L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT689L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT689L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT689L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT689L_EN			(0x1u<<0)

#define	GFXMMU_LUT689L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT689L_EN_B_0X1		(0x1u<<0)

// LUT689H Configuration

#define	GFXMMU_LUT689H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT689H_LO_0			(0x1u<<0)

// LUT690L Configuration

#define	GFXMMU_LUT690L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT690L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT690L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT690L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT690L_EN			(0x1u<<0)

#define	GFXMMU_LUT690L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT690L_EN_B_0X1		(0x1u<<0)

// LUT690H Configuration

#define	GFXMMU_LUT690H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT690H_LO_0			(0x1u<<0)

// LUT691L Configuration

#define	GFXMMU_LUT691L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT691L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT691L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT691L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT691L_EN			(0x1u<<0)

#define	GFXMMU_LUT691L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT691L_EN_B_0X1		(0x1u<<0)

// LUT691H Configuration

#define	GFXMMU_LUT691H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT691H_LO_0			(0x1u<<0)

// LUT692L Configuration

#define	GFXMMU_LUT692L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT692L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT692L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT692L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT692L_EN			(0x1u<<0)

#define	GFXMMU_LUT692L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT692L_EN_B_0X1		(0x1u<<0)

// LUT692H Configuration

#define	GFXMMU_LUT692H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT692H_LO_0			(0x1u<<0)

// LUT693L Configuration

#define	GFXMMU_LUT693L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT693L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT693L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT693L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT693L_EN			(0x1u<<0)

#define	GFXMMU_LUT693L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT693L_EN_B_0X1		(0x1u<<0)

// LUT693H Configuration

#define	GFXMMU_LUT693H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT693H_LO_0			(0x1u<<0)

// LUT694L Configuration

#define	GFXMMU_LUT694L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT694L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT694L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT694L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT694L_EN			(0x1u<<0)

#define	GFXMMU_LUT694L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT694L_EN_B_0X1		(0x1u<<0)

// LUT694H Configuration

#define	GFXMMU_LUT694H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT694H_LO_0			(0x1u<<0)

// LUT695L Configuration

#define	GFXMMU_LUT695L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT695L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT695L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT695L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT695L_EN			(0x1u<<0)

#define	GFXMMU_LUT695L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT695L_EN_B_0X1		(0x1u<<0)

// LUT695H Configuration

#define	GFXMMU_LUT695H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT695H_LO_0			(0x1u<<0)

// LUT696L Configuration

#define	GFXMMU_LUT696L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT696L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT696L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT696L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT696L_EN			(0x1u<<0)

#define	GFXMMU_LUT696L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT696L_EN_B_0X1		(0x1u<<0)

// LUT696H Configuration

#define	GFXMMU_LUT696H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT696H_LO_0			(0x1u<<0)

// LUT697L Configuration

#define	GFXMMU_LUT697L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT697L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT697L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT697L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT697L_EN			(0x1u<<0)

#define	GFXMMU_LUT697L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT697L_EN_B_0X1		(0x1u<<0)

// LUT697H Configuration

#define	GFXMMU_LUT697H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT697H_LO_0			(0x1u<<0)

// LUT698L Configuration

#define	GFXMMU_LUT698L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT698L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT698L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT698L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT698L_EN			(0x1u<<0)

#define	GFXMMU_LUT698L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT698L_EN_B_0X1		(0x1u<<0)

// LUT698H Configuration

#define	GFXMMU_LUT698H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT698H_LO_0			(0x1u<<0)

// LUT699L Configuration

#define	GFXMMU_LUT699L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT699L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT699L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT699L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT699L_EN			(0x1u<<0)

#define	GFXMMU_LUT699L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT699L_EN_B_0X1		(0x1u<<0)

// LUT699H Configuration

#define	GFXMMU_LUT699H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT699H_LO_0			(0x1u<<0)

// LUT700L Configuration

#define	GFXMMU_LUT700L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT700L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT700L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT700L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT700L_EN			(0x1u<<0)

#define	GFXMMU_LUT700L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT700L_EN_B_0X1		(0x1u<<0)

// LUT700H Configuration

#define	GFXMMU_LUT700H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT700H_LO_0			(0x1u<<0)

// LUT701L Configuration

#define	GFXMMU_LUT701L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT701L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT701L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT701L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT701L_EN			(0x1u<<0)

#define	GFXMMU_LUT701L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT701L_EN_B_0X1		(0x1u<<0)

// LUT701H Configuration

#define	GFXMMU_LUT701H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT701H_LO_0			(0x1u<<0)

// LUT702L Configuration

#define	GFXMMU_LUT702L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT702L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT702L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT702L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT702L_EN			(0x1u<<0)

#define	GFXMMU_LUT702L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT702L_EN_B_0X1		(0x1u<<0)

// LUT702H Configuration

#define	GFXMMU_LUT702H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT702H_LO_0			(0x1u<<0)

// LUT703L Configuration

#define	GFXMMU_LUT703L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT703L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT703L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT703L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT703L_EN			(0x1u<<0)

#define	GFXMMU_LUT703L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT703L_EN_B_0X1		(0x1u<<0)

// LUT703H Configuration

#define	GFXMMU_LUT703H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT703H_LO_0			(0x1u<<0)

// LUT704L Configuration

#define	GFXMMU_LUT704L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT704L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT704L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT704L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT704L_EN			(0x1u<<0)

#define	GFXMMU_LUT704L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT704L_EN_B_0X1		(0x1u<<0)

// LUT704H Configuration

#define	GFXMMU_LUT704H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT704H_LO_0			(0x1u<<0)

// LUT705L Configuration

#define	GFXMMU_LUT705L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT705L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT705L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT705L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT705L_EN			(0x1u<<0)

#define	GFXMMU_LUT705L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT705L_EN_B_0X1		(0x1u<<0)

// LUT705H Configuration

#define	GFXMMU_LUT705H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT705H_LO_0			(0x1u<<0)

// LUT706L Configuration

#define	GFXMMU_LUT706L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT706L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT706L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT706L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT706L_EN			(0x1u<<0)

#define	GFXMMU_LUT706L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT706L_EN_B_0X1		(0x1u<<0)

// LUT706H Configuration

#define	GFXMMU_LUT706H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT706H_LO_0			(0x1u<<0)

// LUT707L Configuration

#define	GFXMMU_LUT707L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT707L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT707L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT707L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT707L_EN			(0x1u<<0)

#define	GFXMMU_LUT707L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT707L_EN_B_0X1		(0x1u<<0)

// LUT707H Configuration

#define	GFXMMU_LUT707H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT707H_LO_0			(0x1u<<0)

// LUT708L Configuration

#define	GFXMMU_LUT708L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT708L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT708L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT708L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT708L_EN			(0x1u<<0)

#define	GFXMMU_LUT708L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT708L_EN_B_0X1		(0x1u<<0)

// LUT708H Configuration

#define	GFXMMU_LUT708H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT708H_LO_0			(0x1u<<0)

// LUT709L Configuration

#define	GFXMMU_LUT709L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT709L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT709L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT709L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT709L_EN			(0x1u<<0)

#define	GFXMMU_LUT709L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT709L_EN_B_0X1		(0x1u<<0)

// LUT709H Configuration

#define	GFXMMU_LUT709H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT709H_LO_0			(0x1u<<0)

// LUT710L Configuration

#define	GFXMMU_LUT710L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT710L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT710L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT710L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT710L_EN			(0x1u<<0)

#define	GFXMMU_LUT710L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT710L_EN_B_0X1		(0x1u<<0)

// LUT710H Configuration

#define	GFXMMU_LUT710H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT710H_LO_0			(0x1u<<0)

// LUT711L Configuration

#define	GFXMMU_LUT711L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT711L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT711L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT711L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT711L_EN			(0x1u<<0)

#define	GFXMMU_LUT711L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT711L_EN_B_0X1		(0x1u<<0)

// LUT711H Configuration

#define	GFXMMU_LUT711H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT711H_LO_0			(0x1u<<0)

// LUT712L Configuration

#define	GFXMMU_LUT712L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT712L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT712L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT712L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT712L_EN			(0x1u<<0)

#define	GFXMMU_LUT712L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT712L_EN_B_0X1		(0x1u<<0)

// LUT712H Configuration

#define	GFXMMU_LUT712H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT712H_LO_0			(0x1u<<0)

// LUT713L Configuration

#define	GFXMMU_LUT713L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT713L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT713L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT713L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT713L_EN			(0x1u<<0)

#define	GFXMMU_LUT713L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT713L_EN_B_0X1		(0x1u<<0)

// LUT713H Configuration

#define	GFXMMU_LUT713H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT713H_LO_0			(0x1u<<0)

// LUT714L Configuration

#define	GFXMMU_LUT714L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT714L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT714L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT714L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT714L_EN			(0x1u<<0)

#define	GFXMMU_LUT714L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT714L_EN_B_0X1		(0x1u<<0)

// LUT714H Configuration

#define	GFXMMU_LUT714H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT714H_LO_0			(0x1u<<0)

// LUT715L Configuration

#define	GFXMMU_LUT715L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT715L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT715L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT715L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT715L_EN			(0x1u<<0)

#define	GFXMMU_LUT715L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT715L_EN_B_0X1		(0x1u<<0)

// LUT715H Configuration

#define	GFXMMU_LUT715H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT715H_LO_0			(0x1u<<0)

// LUT716L Configuration

#define	GFXMMU_LUT716L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT716L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT716L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT716L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT716L_EN			(0x1u<<0)

#define	GFXMMU_LUT716L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT716L_EN_B_0X1		(0x1u<<0)

// LUT716H Configuration

#define	GFXMMU_LUT716H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT716H_LO_0			(0x1u<<0)

// LUT717L Configuration

#define	GFXMMU_LUT717L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT717L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT717L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT717L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT717L_EN			(0x1u<<0)

#define	GFXMMU_LUT717L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT717L_EN_B_0X1		(0x1u<<0)

// LUT717H Configuration

#define	GFXMMU_LUT717H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT717H_LO_0			(0x1u<<0)

// LUT718L Configuration

#define	GFXMMU_LUT718L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT718L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT718L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT718L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT718L_EN			(0x1u<<0)

#define	GFXMMU_LUT718L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT718L_EN_B_0X1		(0x1u<<0)

// LUT718H Configuration

#define	GFXMMU_LUT718H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT718H_LO_0			(0x1u<<0)

// LUT719L Configuration

#define	GFXMMU_LUT719L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT719L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT719L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT719L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT719L_EN			(0x1u<<0)

#define	GFXMMU_LUT719L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT719L_EN_B_0X1		(0x1u<<0)

// LUT719H Configuration

#define	GFXMMU_LUT719H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT719H_LO_0			(0x1u<<0)

// LUT720L Configuration

#define	GFXMMU_LUT720L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT720L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT720L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT720L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT720L_EN			(0x1u<<0)

#define	GFXMMU_LUT720L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT720L_EN_B_0X1		(0x1u<<0)

// LUT720H Configuration

#define	GFXMMU_LUT720H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT720H_LO_0			(0x1u<<0)

// LUT721L Configuration

#define	GFXMMU_LUT721L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT721L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT721L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT721L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT721L_EN			(0x1u<<0)

#define	GFXMMU_LUT721L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT721L_EN_B_0X1		(0x1u<<0)

// LUT721H Configuration

#define	GFXMMU_LUT721H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT721H_LO_0			(0x1u<<0)

// LUT722L Configuration

#define	GFXMMU_LUT722L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT722L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT722L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT722L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT722L_EN			(0x1u<<0)

#define	GFXMMU_LUT722L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT722L_EN_B_0X1		(0x1u<<0)

// LUT722H Configuration

#define	GFXMMU_LUT722H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT722H_LO_0			(0x1u<<0)

// LUT723L Configuration

#define	GFXMMU_LUT723L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT723L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT723L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT723L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT723L_EN			(0x1u<<0)

#define	GFXMMU_LUT723L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT723L_EN_B_0X1		(0x1u<<0)

// LUT723H Configuration

#define	GFXMMU_LUT723H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT723H_LO_0			(0x1u<<0)

// LUT724L Configuration

#define	GFXMMU_LUT724L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT724L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT724L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT724L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT724L_EN			(0x1u<<0)

#define	GFXMMU_LUT724L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT724L_EN_B_0X1		(0x1u<<0)

// LUT724H Configuration

#define	GFXMMU_LUT724H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT724H_LO_0			(0x1u<<0)

// LUT725L Configuration

#define	GFXMMU_LUT725L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT725L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT725L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT725L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT725L_EN			(0x1u<<0)

#define	GFXMMU_LUT725L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT725L_EN_B_0X1		(0x1u<<0)

// LUT725H Configuration

#define	GFXMMU_LUT725H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT725H_LO_0			(0x1u<<0)

// LUT726L Configuration

#define	GFXMMU_LUT726L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT726L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT726L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT726L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT726L_EN			(0x1u<<0)

#define	GFXMMU_LUT726L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT726L_EN_B_0X1		(0x1u<<0)

// LUT726H Configuration

#define	GFXMMU_LUT726H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT726H_LO_0			(0x1u<<0)

// LUT727L Configuration

#define	GFXMMU_LUT727L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT727L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT727L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT727L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT727L_EN			(0x1u<<0)

#define	GFXMMU_LUT727L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT727L_EN_B_0X1		(0x1u<<0)

// LUT727H Configuration

#define	GFXMMU_LUT727H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT727H_LO_0			(0x1u<<0)

// LUT728L Configuration

#define	GFXMMU_LUT728L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT728L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT728L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT728L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT728L_EN			(0x1u<<0)

#define	GFXMMU_LUT728L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT728L_EN_B_0X1		(0x1u<<0)

// LUT728H Configuration

#define	GFXMMU_LUT728H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT728H_LO_0			(0x1u<<0)

// LUT729L Configuration

#define	GFXMMU_LUT729L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT729L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT729L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT729L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT729L_EN			(0x1u<<0)

#define	GFXMMU_LUT729L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT729L_EN_B_0X1		(0x1u<<0)

// LUT729H Configuration

#define	GFXMMU_LUT729H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT729H_LO_0			(0x1u<<0)

// LUT730L Configuration

#define	GFXMMU_LUT730L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT730L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT730L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT730L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT730L_EN			(0x1u<<0)

#define	GFXMMU_LUT730L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT730L_EN_B_0X1		(0x1u<<0)

// LUT730H Configuration

#define	GFXMMU_LUT730H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT730H_LO_0			(0x1u<<0)

// LUT731L Configuration

#define	GFXMMU_LUT731L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT731L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT731L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT731L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT731L_EN			(0x1u<<0)

#define	GFXMMU_LUT731L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT731L_EN_B_0X1		(0x1u<<0)

// LUT731H Configuration

#define	GFXMMU_LUT731H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT731H_LO_0			(0x1u<<0)

// LUT732L Configuration

#define	GFXMMU_LUT732L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT732L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT732L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT732L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT732L_EN			(0x1u<<0)

#define	GFXMMU_LUT732L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT732L_EN_B_0X1		(0x1u<<0)

// LUT732H Configuration

#define	GFXMMU_LUT732H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT732H_LO_0			(0x1u<<0)

// LUT733L Configuration

#define	GFXMMU_LUT733L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT733L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT733L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT733L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT733L_EN			(0x1u<<0)

#define	GFXMMU_LUT733L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT733L_EN_B_0X1		(0x1u<<0)

// LUT733H Configuration

#define	GFXMMU_LUT733H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT733H_LO_0			(0x1u<<0)

// LUT734L Configuration

#define	GFXMMU_LUT734L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT734L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT734L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT734L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT734L_EN			(0x1u<<0)

#define	GFXMMU_LUT734L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT734L_EN_B_0X1		(0x1u<<0)

// LUT734H Configuration

#define	GFXMMU_LUT734H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT734H_LO_0			(0x1u<<0)

// LUT735L Configuration

#define	GFXMMU_LUT735L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT735L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT735L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT735L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT735L_EN			(0x1u<<0)

#define	GFXMMU_LUT735L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT735L_EN_B_0X1		(0x1u<<0)

// LUT735H Configuration

#define	GFXMMU_LUT735H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT735H_LO_0			(0x1u<<0)

// LUT736L Configuration

#define	GFXMMU_LUT736L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT736L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT736L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT736L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT736L_EN			(0x1u<<0)

#define	GFXMMU_LUT736L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT736L_EN_B_0X1		(0x1u<<0)

// LUT736H Configuration

#define	GFXMMU_LUT736H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT736H_LO_0			(0x1u<<0)

// LUT737L Configuration

#define	GFXMMU_LUT737L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT737L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT737L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT737L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT737L_EN			(0x1u<<0)

#define	GFXMMU_LUT737L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT737L_EN_B_0X1		(0x1u<<0)

// LUT737H Configuration

#define	GFXMMU_LUT737H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT737H_LO_0			(0x1u<<0)

// LUT738L Configuration

#define	GFXMMU_LUT738L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT738L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT738L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT738L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT738L_EN			(0x1u<<0)

#define	GFXMMU_LUT738L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT738L_EN_B_0X1		(0x1u<<0)

// LUT738H Configuration

#define	GFXMMU_LUT738H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT738H_LO_0			(0x1u<<0)

// LUT739L Configuration

#define	GFXMMU_LUT739L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT739L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT739L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT739L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT739L_EN			(0x1u<<0)

#define	GFXMMU_LUT739L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT739L_EN_B_0X1		(0x1u<<0)

// LUT739H Configuration

#define	GFXMMU_LUT739H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT739H_LO_0			(0x1u<<0)

// LUT740L Configuration

#define	GFXMMU_LUT740L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT740L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT740L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT740L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT740L_EN			(0x1u<<0)

#define	GFXMMU_LUT740L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT740L_EN_B_0X1		(0x1u<<0)

// LUT740H Configuration

#define	GFXMMU_LUT740H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT740H_LO_0			(0x1u<<0)

// LUT741L Configuration

#define	GFXMMU_LUT741L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT741L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT741L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT741L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT741L_EN			(0x1u<<0)

#define	GFXMMU_LUT741L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT741L_EN_B_0X1		(0x1u<<0)

// LUT741H Configuration

#define	GFXMMU_LUT741H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT741H_LO_0			(0x1u<<0)

// LUT742L Configuration

#define	GFXMMU_LUT742L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT742L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT742L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT742L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT742L_EN			(0x1u<<0)

#define	GFXMMU_LUT742L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT742L_EN_B_0X1		(0x1u<<0)

// LUT742H Configuration

#define	GFXMMU_LUT742H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT742H_LO_0			(0x1u<<0)

// LUT743L Configuration

#define	GFXMMU_LUT743L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT743L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT743L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT743L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT743L_EN			(0x1u<<0)

#define	GFXMMU_LUT743L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT743L_EN_B_0X1		(0x1u<<0)

// LUT743H Configuration

#define	GFXMMU_LUT743H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT743H_LO_0			(0x1u<<0)

// LUT744L Configuration

#define	GFXMMU_LUT744L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT744L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT744L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT744L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT744L_EN			(0x1u<<0)

#define	GFXMMU_LUT744L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT744L_EN_B_0X1		(0x1u<<0)

// LUT744H Configuration

#define	GFXMMU_LUT744H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT744H_LO_0			(0x1u<<0)

// LUT745L Configuration

#define	GFXMMU_LUT745L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT745L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT745L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT745L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT745L_EN			(0x1u<<0)

#define	GFXMMU_LUT745L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT745L_EN_B_0X1		(0x1u<<0)

// LUT745H Configuration

#define	GFXMMU_LUT745H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT745H_LO_0			(0x1u<<0)

// LUT746L Configuration

#define	GFXMMU_LUT746L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT746L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT746L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT746L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT746L_EN			(0x1u<<0)

#define	GFXMMU_LUT746L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT746L_EN_B_0X1		(0x1u<<0)

// LUT746H Configuration

#define	GFXMMU_LUT746H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT746H_LO_0			(0x1u<<0)

// LUT747L Configuration

#define	GFXMMU_LUT747L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT747L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT747L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT747L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT747L_EN			(0x1u<<0)

#define	GFXMMU_LUT747L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT747L_EN_B_0X1		(0x1u<<0)

// LUT747H Configuration

#define	GFXMMU_LUT747H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT747H_LO_0			(0x1u<<0)

// LUT748L Configuration

#define	GFXMMU_LUT748L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT748L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT748L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT748L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT748L_EN			(0x1u<<0)

#define	GFXMMU_LUT748L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT748L_EN_B_0X1		(0x1u<<0)

// LUT748H Configuration

#define	GFXMMU_LUT748H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT748H_LO_0			(0x1u<<0)

// LUT749L Configuration

#define	GFXMMU_LUT749L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT749L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT749L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT749L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT749L_EN			(0x1u<<0)

#define	GFXMMU_LUT749L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT749L_EN_B_0X1		(0x1u<<0)

// LUT749H Configuration

#define	GFXMMU_LUT749H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT749H_LO_0			(0x1u<<0)

// LUT750L Configuration

#define	GFXMMU_LUT750L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT750L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT750L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT750L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT750L_EN			(0x1u<<0)

#define	GFXMMU_LUT750L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT750L_EN_B_0X1		(0x1u<<0)

// LUT750H Configuration

#define	GFXMMU_LUT750H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT750H_LO_0			(0x1u<<0)

// LUT751L Configuration

#define	GFXMMU_LUT751L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT751L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT751L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT751L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT751L_EN			(0x1u<<0)

#define	GFXMMU_LUT751L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT751L_EN_B_0X1		(0x1u<<0)

// LUT751H Configuration

#define	GFXMMU_LUT751H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT751H_LO_0			(0x1u<<0)

// LUT752L Configuration

#define	GFXMMU_LUT752L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT752L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT752L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT752L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT752L_EN			(0x1u<<0)

#define	GFXMMU_LUT752L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT752L_EN_B_0X1		(0x1u<<0)

// LUT752H Configuration

#define	GFXMMU_LUT752H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT752H_LO_0			(0x1u<<0)

// LUT753L Configuration

#define	GFXMMU_LUT753L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT753L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT753L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT753L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT753L_EN			(0x1u<<0)

#define	GFXMMU_LUT753L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT753L_EN_B_0X1		(0x1u<<0)

// LUT753H Configuration

#define	GFXMMU_LUT753H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT753H_LO_0			(0x1u<<0)

// LUT754L Configuration

#define	GFXMMU_LUT754L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT754L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT754L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT754L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT754L_EN			(0x1u<<0)

#define	GFXMMU_LUT754L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT754L_EN_B_0X1		(0x1u<<0)

// LUT754H Configuration

#define	GFXMMU_LUT754H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT754H_LO_0			(0x1u<<0)

// LUT755L Configuration

#define	GFXMMU_LUT755L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT755L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT755L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT755L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT755L_EN			(0x1u<<0)

#define	GFXMMU_LUT755L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT755L_EN_B_0X1		(0x1u<<0)

// LUT755H Configuration

#define	GFXMMU_LUT755H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT755H_LO_0			(0x1u<<0)

// LUT756L Configuration

#define	GFXMMU_LUT756L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT756L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT756L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT756L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT756L_EN			(0x1u<<0)

#define	GFXMMU_LUT756L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT756L_EN_B_0X1		(0x1u<<0)

// LUT756H Configuration

#define	GFXMMU_LUT756H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT756H_LO_0			(0x1u<<0)

// LUT757L Configuration

#define	GFXMMU_LUT757L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT757L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT757L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT757L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT757L_EN			(0x1u<<0)

#define	GFXMMU_LUT757L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT757L_EN_B_0X1		(0x1u<<0)

// LUT757H Configuration

#define	GFXMMU_LUT757H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT757H_LO_0			(0x1u<<0)

// LUT758L Configuration

#define	GFXMMU_LUT758L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT758L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT758L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT758L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT758L_EN			(0x1u<<0)

#define	GFXMMU_LUT758L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT758L_EN_B_0X1		(0x1u<<0)

// LUT758H Configuration

#define	GFXMMU_LUT758H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT758H_LO_0			(0x1u<<0)

// LUT759L Configuration

#define	GFXMMU_LUT759L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT759L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT759L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT759L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT759L_EN			(0x1u<<0)

#define	GFXMMU_LUT759L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT759L_EN_B_0X1		(0x1u<<0)

// LUT759H Configuration

#define	GFXMMU_LUT759H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT759H_LO_0			(0x1u<<0)

// LUT760L Configuration

#define	GFXMMU_LUT760L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT760L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT760L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT760L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT760L_EN			(0x1u<<0)

#define	GFXMMU_LUT760L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT760L_EN_B_0X1		(0x1u<<0)

// LUT760H Configuration

#define	GFXMMU_LUT760H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT760H_LO_0			(0x1u<<0)

// LUT761L Configuration

#define	GFXMMU_LUT761L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT761L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT761L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT761L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT761L_EN			(0x1u<<0)

#define	GFXMMU_LUT761L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT761L_EN_B_0X1		(0x1u<<0)

// LUT761H Configuration

#define	GFXMMU_LUT761H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT761H_LO_0			(0x1u<<0)

// LUT762L Configuration

#define	GFXMMU_LUT762L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT762L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT762L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT762L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT762L_EN			(0x1u<<0)

#define	GFXMMU_LUT762L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT762L_EN_B_0X1		(0x1u<<0)

// LUT762H Configuration

#define	GFXMMU_LUT762H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT762H_LO_0			(0x1u<<0)

// LUT763L Configuration

#define	GFXMMU_LUT763L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT763L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT763L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT763L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT763L_EN			(0x1u<<0)

#define	GFXMMU_LUT763L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT763L_EN_B_0X1		(0x1u<<0)

// LUT763H Configuration

#define	GFXMMU_LUT763H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT763H_LO_0			(0x1u<<0)

// LUT764L Configuration

#define	GFXMMU_LUT764L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT764L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT764L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT764L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT764L_EN			(0x1u<<0)

#define	GFXMMU_LUT764L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT764L_EN_B_0X1		(0x1u<<0)

// LUT764H Configuration

#define	GFXMMU_LUT764H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT764H_LO_0			(0x1u<<0)

// LUT765L Configuration

#define	GFXMMU_LUT765L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT765L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT765L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT765L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT765L_EN			(0x1u<<0)

#define	GFXMMU_LUT765L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT765L_EN_B_0X1		(0x1u<<0)

// LUT765H Configuration

#define	GFXMMU_LUT765H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT765H_LO_0			(0x1u<<0)

// LUT766L Configuration

#define	GFXMMU_LUT766L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT766L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT766L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT766L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT766L_EN			(0x1u<<0)

#define	GFXMMU_LUT766L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT766L_EN_B_0X1		(0x1u<<0)

// LUT766H Configuration

#define	GFXMMU_LUT766H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT766H_LO_0			(0x1u<<0)

// LUT767L Configuration

#define	GFXMMU_LUT767L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT767L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT767L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT767L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT767L_EN			(0x1u<<0)

#define	GFXMMU_LUT767L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT767L_EN_B_0X1		(0x1u<<0)

// LUT767H Configuration

#define	GFXMMU_LUT767H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT767H_LO_0			(0x1u<<0)

// LUT768L Configuration

#define	GFXMMU_LUT768L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT768L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT768L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT768L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT768L_EN			(0x1u<<0)

#define	GFXMMU_LUT768L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT768L_EN_B_0X1		(0x1u<<0)

// LUT768H Configuration

#define	GFXMMU_LUT768H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT768H_LO_0			(0x1u<<0)

// LUT769L Configuration

#define	GFXMMU_LUT769L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT769L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT769L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT769L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT769L_EN			(0x1u<<0)

#define	GFXMMU_LUT769L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT769L_EN_B_0X1		(0x1u<<0)

// LUT769H Configuration

#define	GFXMMU_LUT769H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT769H_LO_0			(0x1u<<0)

// LUT770L Configuration

#define	GFXMMU_LUT770L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT770L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT770L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT770L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT770L_EN			(0x1u<<0)

#define	GFXMMU_LUT770L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT770L_EN_B_0X1		(0x1u<<0)

// LUT770H Configuration

#define	GFXMMU_LUT770H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT770H_LO_0			(0x1u<<0)

// LUT771L Configuration

#define	GFXMMU_LUT771L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT771L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT771L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT771L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT771L_EN			(0x1u<<0)

#define	GFXMMU_LUT771L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT771L_EN_B_0X1		(0x1u<<0)

// LUT771H Configuration

#define	GFXMMU_LUT771H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT771H_LO_0			(0x1u<<0)

// LUT772L Configuration

#define	GFXMMU_LUT772L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT772L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT772L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT772L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT772L_EN			(0x1u<<0)

#define	GFXMMU_LUT772L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT772L_EN_B_0X1		(0x1u<<0)

// LUT772H Configuration

#define	GFXMMU_LUT772H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT772H_LO_0			(0x1u<<0)

// LUT773L Configuration

#define	GFXMMU_LUT773L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT773L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT773L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT773L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT773L_EN			(0x1u<<0)

#define	GFXMMU_LUT773L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT773L_EN_B_0X1		(0x1u<<0)

// LUT773H Configuration

#define	GFXMMU_LUT773H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT773H_LO_0			(0x1u<<0)

// LUT774L Configuration

#define	GFXMMU_LUT774L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT774L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT774L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT774L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT774L_EN			(0x1u<<0)

#define	GFXMMU_LUT774L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT774L_EN_B_0X1		(0x1u<<0)

// LUT774H Configuration

#define	GFXMMU_LUT774H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT774H_LO_0			(0x1u<<0)

// LUT775L Configuration

#define	GFXMMU_LUT775L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT775L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT775L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT775L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT775L_EN			(0x1u<<0)

#define	GFXMMU_LUT775L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT775L_EN_B_0X1		(0x1u<<0)

// LUT775H Configuration

#define	GFXMMU_LUT775H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT775H_LO_0			(0x1u<<0)

// LUT776L Configuration

#define	GFXMMU_LUT776L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT776L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT776L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT776L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT776L_EN			(0x1u<<0)

#define	GFXMMU_LUT776L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT776L_EN_B_0X1		(0x1u<<0)

// LUT776H Configuration

#define	GFXMMU_LUT776H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT776H_LO_0			(0x1u<<0)

// LUT777L Configuration

#define	GFXMMU_LUT777L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT777L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT777L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT777L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT777L_EN			(0x1u<<0)

#define	GFXMMU_LUT777L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT777L_EN_B_0X1		(0x1u<<0)

// LUT777H Configuration

#define	GFXMMU_LUT777H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT777H_LO_0			(0x1u<<0)

// LUT778L Configuration

#define	GFXMMU_LUT778L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT778L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT778L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT778L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT778L_EN			(0x1u<<0)

#define	GFXMMU_LUT778L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT778L_EN_B_0X1		(0x1u<<0)

// LUT778H Configuration

#define	GFXMMU_LUT778H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT778H_LO_0			(0x1u<<0)

// LUT779L Configuration

#define	GFXMMU_LUT779L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT779L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT779L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT779L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT779L_EN			(0x1u<<0)

#define	GFXMMU_LUT779L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT779L_EN_B_0X1		(0x1u<<0)

// LUT779H Configuration

#define	GFXMMU_LUT779H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT779H_LO_0			(0x1u<<0)

// LUT780L Configuration

#define	GFXMMU_LUT780L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT780L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT780L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT780L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT780L_EN			(0x1u<<0)

#define	GFXMMU_LUT780L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT780L_EN_B_0X1		(0x1u<<0)

// LUT780H Configuration

#define	GFXMMU_LUT780H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT780H_LO_0			(0x1u<<0)

// LUT781L Configuration

#define	GFXMMU_LUT781L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT781L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT781L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT781L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT781L_EN			(0x1u<<0)

#define	GFXMMU_LUT781L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT781L_EN_B_0X1		(0x1u<<0)

// LUT781H Configuration

#define	GFXMMU_LUT781H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT781H_LO_0			(0x1u<<0)

// LUT782L Configuration

#define	GFXMMU_LUT782L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT782L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT782L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT782L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT782L_EN			(0x1u<<0)

#define	GFXMMU_LUT782L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT782L_EN_B_0X1		(0x1u<<0)

// LUT782H Configuration

#define	GFXMMU_LUT782H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT782H_LO_0			(0x1u<<0)

// LUT783L Configuration

#define	GFXMMU_LUT783L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT783L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT783L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT783L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT783L_EN			(0x1u<<0)

#define	GFXMMU_LUT783L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT783L_EN_B_0X1		(0x1u<<0)

// LUT783H Configuration

#define	GFXMMU_LUT783H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT783H_LO_0			(0x1u<<0)

// LUT784L Configuration

#define	GFXMMU_LUT784L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT784L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT784L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT784L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT784L_EN			(0x1u<<0)

#define	GFXMMU_LUT784L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT784L_EN_B_0X1		(0x1u<<0)

// LUT784H Configuration

#define	GFXMMU_LUT784H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT784H_LO_0			(0x1u<<0)

// LUT785L Configuration

#define	GFXMMU_LUT785L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT785L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT785L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT785L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT785L_EN			(0x1u<<0)

#define	GFXMMU_LUT785L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT785L_EN_B_0X1		(0x1u<<0)

// LUT785H Configuration

#define	GFXMMU_LUT785H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT785H_LO_0			(0x1u<<0)

// LUT786L Configuration

#define	GFXMMU_LUT786L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT786L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT786L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT786L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT786L_EN			(0x1u<<0)

#define	GFXMMU_LUT786L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT786L_EN_B_0X1		(0x1u<<0)

// LUT786H Configuration

#define	GFXMMU_LUT786H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT786H_LO_0			(0x1u<<0)

// LUT787L Configuration

#define	GFXMMU_LUT787L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT787L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT787L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT787L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT787L_EN			(0x1u<<0)

#define	GFXMMU_LUT787L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT787L_EN_B_0X1		(0x1u<<0)

// LUT787H Configuration

#define	GFXMMU_LUT787H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT787H_LO_0			(0x1u<<0)

// LUT788L Configuration

#define	GFXMMU_LUT788L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT788L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT788L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT788L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT788L_EN			(0x1u<<0)

#define	GFXMMU_LUT788L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT788L_EN_B_0X1		(0x1u<<0)

// LUT788H Configuration

#define	GFXMMU_LUT788H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT788H_LO_0			(0x1u<<0)

// LUT789L Configuration

#define	GFXMMU_LUT789L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT789L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT789L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT789L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT789L_EN			(0x1u<<0)

#define	GFXMMU_LUT789L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT789L_EN_B_0X1		(0x1u<<0)

// LUT789H Configuration

#define	GFXMMU_LUT789H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT789H_LO_0			(0x1u<<0)

// LUT790L Configuration

#define	GFXMMU_LUT790L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT790L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT790L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT790L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT790L_EN			(0x1u<<0)

#define	GFXMMU_LUT790L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT790L_EN_B_0X1		(0x1u<<0)

// LUT790H Configuration

#define	GFXMMU_LUT790H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT790H_LO_0			(0x1u<<0)

// LUT791L Configuration

#define	GFXMMU_LUT791L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT791L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT791L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT791L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT791L_EN			(0x1u<<0)

#define	GFXMMU_LUT791L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT791L_EN_B_0X1		(0x1u<<0)

// LUT791H Configuration

#define	GFXMMU_LUT791H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT791H_LO_0			(0x1u<<0)

// LUT792L Configuration

#define	GFXMMU_LUT792L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT792L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT792L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT792L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT792L_EN			(0x1u<<0)

#define	GFXMMU_LUT792L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT792L_EN_B_0X1		(0x1u<<0)

// LUT792H Configuration

#define	GFXMMU_LUT792H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT792H_LO_0			(0x1u<<0)

// LUT793L Configuration

#define	GFXMMU_LUT793L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT793L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT793L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT793L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT793L_EN			(0x1u<<0)

#define	GFXMMU_LUT793L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT793L_EN_B_0X1		(0x1u<<0)

// LUT793H Configuration

#define	GFXMMU_LUT793H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT793H_LO_0			(0x1u<<0)

// LUT794L Configuration

#define	GFXMMU_LUT794L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT794L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT794L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT794L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT794L_EN			(0x1u<<0)

#define	GFXMMU_LUT794L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT794L_EN_B_0X1		(0x1u<<0)

// LUT794H Configuration

#define	GFXMMU_LUT794H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT794H_LO_0			(0x1u<<0)

// LUT795L Configuration

#define	GFXMMU_LUT795L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT795L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT795L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT795L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT795L_EN			(0x1u<<0)

#define	GFXMMU_LUT795L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT795L_EN_B_0X1		(0x1u<<0)

// LUT795H Configuration

#define	GFXMMU_LUT795H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT795H_LO_0			(0x1u<<0)

// LUT796L Configuration

#define	GFXMMU_LUT796L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT796L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT796L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT796L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT796L_EN			(0x1u<<0)

#define	GFXMMU_LUT796L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT796L_EN_B_0X1		(0x1u<<0)

// LUT796H Configuration

#define	GFXMMU_LUT796H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT796H_LO_0			(0x1u<<0)

// LUT797L Configuration

#define	GFXMMU_LUT797L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT797L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT797L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT797L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT797L_EN			(0x1u<<0)

#define	GFXMMU_LUT797L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT797L_EN_B_0X1		(0x1u<<0)

// LUT797H Configuration

#define	GFXMMU_LUT797H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT797H_LO_0			(0x1u<<0)

// LUT798L Configuration

#define	GFXMMU_LUT798L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT798L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT798L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT798L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT798L_EN			(0x1u<<0)

#define	GFXMMU_LUT798L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT798L_EN_B_0X1		(0x1u<<0)

// LUT798H Configuration

#define	GFXMMU_LUT798H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT798H_LO_0			(0x1u<<0)

// LUT799L Configuration

#define	GFXMMU_LUT799L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT799L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT799L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT799L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT799L_EN			(0x1u<<0)

#define	GFXMMU_LUT799L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT799L_EN_B_0X1		(0x1u<<0)

// LUT799H Configuration

#define	GFXMMU_LUT799H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT799H_LO_0			(0x1u<<0)

// LUT800L Configuration

#define	GFXMMU_LUT800L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT800L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT800L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT800L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT800L_EN			(0x1u<<0)

#define	GFXMMU_LUT800L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT800L_EN_B_0X1		(0x1u<<0)

// LUT800H Configuration

#define	GFXMMU_LUT800H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT800H_LO_0			(0x1u<<0)

// LUT801L Configuration

#define	GFXMMU_LUT801L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT801L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT801L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT801L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT801L_EN			(0x1u<<0)

#define	GFXMMU_LUT801L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT801L_EN_B_0X1		(0x1u<<0)

// LUT801H Configuration

#define	GFXMMU_LUT801H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT801H_LO_0			(0x1u<<0)

// LUT802L Configuration

#define	GFXMMU_LUT802L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT802L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT802L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT802L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT802L_EN			(0x1u<<0)

#define	GFXMMU_LUT802L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT802L_EN_B_0X1		(0x1u<<0)

// LUT802H Configuration

#define	GFXMMU_LUT802H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT802H_LO_0			(0x1u<<0)

// LUT803L Configuration

#define	GFXMMU_LUT803L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT803L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT803L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT803L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT803L_EN			(0x1u<<0)

#define	GFXMMU_LUT803L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT803L_EN_B_0X1		(0x1u<<0)

// LUT803H Configuration

#define	GFXMMU_LUT803H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT803H_LO_0			(0x1u<<0)

// LUT804L Configuration

#define	GFXMMU_LUT804L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT804L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT804L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT804L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT804L_EN			(0x1u<<0)

#define	GFXMMU_LUT804L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT804L_EN_B_0X1		(0x1u<<0)

// LUT804H Configuration

#define	GFXMMU_LUT804H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT804H_LO_0			(0x1u<<0)

// LUT805L Configuration

#define	GFXMMU_LUT805L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT805L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT805L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT805L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT805L_EN			(0x1u<<0)

#define	GFXMMU_LUT805L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT805L_EN_B_0X1		(0x1u<<0)

// LUT805H Configuration

#define	GFXMMU_LUT805H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT805H_LO_0			(0x1u<<0)

// LUT806L Configuration

#define	GFXMMU_LUT806L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT806L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT806L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT806L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT806L_EN			(0x1u<<0)

#define	GFXMMU_LUT806L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT806L_EN_B_0X1		(0x1u<<0)

// LUT806H Configuration

#define	GFXMMU_LUT806H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT806H_LO_0			(0x1u<<0)

// LUT807L Configuration

#define	GFXMMU_LUT807L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT807L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT807L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT807L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT807L_EN			(0x1u<<0)

#define	GFXMMU_LUT807L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT807L_EN_B_0X1		(0x1u<<0)

// LUT807H Configuration

#define	GFXMMU_LUT807H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT807H_LO_0			(0x1u<<0)

// LUT808L Configuration

#define	GFXMMU_LUT808L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT808L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT808L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT808L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT808L_EN			(0x1u<<0)

#define	GFXMMU_LUT808L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT808L_EN_B_0X1		(0x1u<<0)

// LUT808H Configuration

#define	GFXMMU_LUT808H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT808H_LO_0			(0x1u<<0)

// LUT809L Configuration

#define	GFXMMU_LUT809L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT809L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT809L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT809L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT809L_EN			(0x1u<<0)

#define	GFXMMU_LUT809L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT809L_EN_B_0X1		(0x1u<<0)

// LUT809H Configuration

#define	GFXMMU_LUT809H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT809H_LO_0			(0x1u<<0)

// LUT810L Configuration

#define	GFXMMU_LUT810L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT810L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT810L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT810L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT810L_EN			(0x1u<<0)

#define	GFXMMU_LUT810L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT810L_EN_B_0X1		(0x1u<<0)

// LUT810H Configuration

#define	GFXMMU_LUT810H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT810H_LO_0			(0x1u<<0)

// LUT811L Configuration

#define	GFXMMU_LUT811L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT811L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT811L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT811L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT811L_EN			(0x1u<<0)

#define	GFXMMU_LUT811L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT811L_EN_B_0X1		(0x1u<<0)

// LUT811H Configuration

#define	GFXMMU_LUT811H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT811H_LO_0			(0x1u<<0)

// LUT812L Configuration

#define	GFXMMU_LUT812L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT812L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT812L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT812L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT812L_EN			(0x1u<<0)

#define	GFXMMU_LUT812L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT812L_EN_B_0X1		(0x1u<<0)

// LUT812H Configuration

#define	GFXMMU_LUT812H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT812H_LO_0			(0x1u<<0)

// LUT813L Configuration

#define	GFXMMU_LUT813L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT813L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT813L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT813L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT813L_EN			(0x1u<<0)

#define	GFXMMU_LUT813L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT813L_EN_B_0X1		(0x1u<<0)

// LUT813H Configuration

#define	GFXMMU_LUT813H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT813H_LO_0			(0x1u<<0)

// LUT814L Configuration

#define	GFXMMU_LUT814L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT814L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT814L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT814L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT814L_EN			(0x1u<<0)

#define	GFXMMU_LUT814L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT814L_EN_B_0X1		(0x1u<<0)

// LUT814H Configuration

#define	GFXMMU_LUT814H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT814H_LO_0			(0x1u<<0)

// LUT815L Configuration

#define	GFXMMU_LUT815L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT815L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT815L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT815L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT815L_EN			(0x1u<<0)

#define	GFXMMU_LUT815L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT815L_EN_B_0X1		(0x1u<<0)

// LUT815H Configuration

#define	GFXMMU_LUT815H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT815H_LO_0			(0x1u<<0)

// LUT816L Configuration

#define	GFXMMU_LUT816L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT816L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT816L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT816L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT816L_EN			(0x1u<<0)

#define	GFXMMU_LUT816L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT816L_EN_B_0X1		(0x1u<<0)

// LUT816H Configuration

#define	GFXMMU_LUT816H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT816H_LO_0			(0x1u<<0)

// LUT817L Configuration

#define	GFXMMU_LUT817L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT817L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT817L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT817L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT817L_EN			(0x1u<<0)

#define	GFXMMU_LUT817L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT817L_EN_B_0X1		(0x1u<<0)

// LUT817H Configuration

#define	GFXMMU_LUT817H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT817H_LO_0			(0x1u<<0)

// LUT818L Configuration

#define	GFXMMU_LUT818L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT818L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT818L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT818L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT818L_EN			(0x1u<<0)

#define	GFXMMU_LUT818L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT818L_EN_B_0X1		(0x1u<<0)

// LUT818H Configuration

#define	GFXMMU_LUT818H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT818H_LO_0			(0x1u<<0)

// LUT819L Configuration

#define	GFXMMU_LUT819L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT819L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT819L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT819L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT819L_EN			(0x1u<<0)

#define	GFXMMU_LUT819L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT819L_EN_B_0X1		(0x1u<<0)

// LUT819H Configuration

#define	GFXMMU_LUT819H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT819H_LO_0			(0x1u<<0)

// LUT820L Configuration

#define	GFXMMU_LUT820L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT820L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT820L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT820L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT820L_EN			(0x1u<<0)

#define	GFXMMU_LUT820L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT820L_EN_B_0X1		(0x1u<<0)

// LUT820H Configuration

#define	GFXMMU_LUT820H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT820H_LO_0			(0x1u<<0)

// LUT821L Configuration

#define	GFXMMU_LUT821L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT821L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT821L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT821L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT821L_EN			(0x1u<<0)

#define	GFXMMU_LUT821L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT821L_EN_B_0X1		(0x1u<<0)

// LUT821H Configuration

#define	GFXMMU_LUT821H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT821H_LO_0			(0x1u<<0)

// LUT822L Configuration

#define	GFXMMU_LUT822L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT822L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT822L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT822L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT822L_EN			(0x1u<<0)

#define	GFXMMU_LUT822L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT822L_EN_B_0X1		(0x1u<<0)

// LUT822H Configuration

#define	GFXMMU_LUT822H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT822H_LO_0			(0x1u<<0)

// LUT823L Configuration

#define	GFXMMU_LUT823L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT823L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT823L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT823L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT823L_EN			(0x1u<<0)

#define	GFXMMU_LUT823L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT823L_EN_B_0X1		(0x1u<<0)

// LUT823H Configuration

#define	GFXMMU_LUT823H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT823H_LO_0			(0x1u<<0)

// LUT824L Configuration

#define	GFXMMU_LUT824L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT824L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT824L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT824L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT824L_EN			(0x1u<<0)

#define	GFXMMU_LUT824L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT824L_EN_B_0X1		(0x1u<<0)

// LUT824H Configuration

#define	GFXMMU_LUT824H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT824H_LO_0			(0x1u<<0)

// LUT825L Configuration

#define	GFXMMU_LUT825L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT825L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT825L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT825L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT825L_EN			(0x1u<<0)

#define	GFXMMU_LUT825L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT825L_EN_B_0X1		(0x1u<<0)

// LUT825H Configuration

#define	GFXMMU_LUT825H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT825H_LO_0			(0x1u<<0)

// LUT826L Configuration

#define	GFXMMU_LUT826L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT826L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT826L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT826L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT826L_EN			(0x1u<<0)

#define	GFXMMU_LUT826L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT826L_EN_B_0X1		(0x1u<<0)

// LUT826H Configuration

#define	GFXMMU_LUT826H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT826H_LO_0			(0x1u<<0)

// LUT827L Configuration

#define	GFXMMU_LUT827L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT827L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT827L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT827L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT827L_EN			(0x1u<<0)

#define	GFXMMU_LUT827L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT827L_EN_B_0X1		(0x1u<<0)

// LUT827H Configuration

#define	GFXMMU_LUT827H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT827H_LO_0			(0x1u<<0)

// LUT828L Configuration

#define	GFXMMU_LUT828L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT828L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT828L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT828L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT828L_EN			(0x1u<<0)

#define	GFXMMU_LUT828L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT828L_EN_B_0X1		(0x1u<<0)

// LUT828H Configuration

#define	GFXMMU_LUT828H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT828H_LO_0			(0x1u<<0)

// LUT829L Configuration

#define	GFXMMU_LUT829L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT829L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT829L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT829L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT829L_EN			(0x1u<<0)

#define	GFXMMU_LUT829L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT829L_EN_B_0X1		(0x1u<<0)

// LUT829H Configuration

#define	GFXMMU_LUT829H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT829H_LO_0			(0x1u<<0)

// LUT830L Configuration

#define	GFXMMU_LUT830L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT830L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT830L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT830L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT830L_EN			(0x1u<<0)

#define	GFXMMU_LUT830L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT830L_EN_B_0X1		(0x1u<<0)

// LUT830H Configuration

#define	GFXMMU_LUT830H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT830H_LO_0			(0x1u<<0)

// LUT831L Configuration

#define	GFXMMU_LUT831L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT831L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT831L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT831L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT831L_EN			(0x1u<<0)

#define	GFXMMU_LUT831L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT831L_EN_B_0X1		(0x1u<<0)

// LUT831H Configuration

#define	GFXMMU_LUT831H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT831H_LO_0			(0x1u<<0)

// LUT832L Configuration

#define	GFXMMU_LUT832L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT832L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT832L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT832L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT832L_EN			(0x1u<<0)

#define	GFXMMU_LUT832L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT832L_EN_B_0X1		(0x1u<<0)

// LUT832H Configuration

#define	GFXMMU_LUT832H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT832H_LO_0			(0x1u<<0)

// LUT833L Configuration

#define	GFXMMU_LUT833L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT833L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT833L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT833L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT833L_EN			(0x1u<<0)

#define	GFXMMU_LUT833L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT833L_EN_B_0X1		(0x1u<<0)

// LUT833H Configuration

#define	GFXMMU_LUT833H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT833H_LO_0			(0x1u<<0)

// LUT834L Configuration

#define	GFXMMU_LUT834L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT834L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT834L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT834L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT834L_EN			(0x1u<<0)

#define	GFXMMU_LUT834L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT834L_EN_B_0X1		(0x1u<<0)

// LUT834H Configuration

#define	GFXMMU_LUT834H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT834H_LO_0			(0x1u<<0)

// LUT835L Configuration

#define	GFXMMU_LUT835L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT835L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT835L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT835L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT835L_EN			(0x1u<<0)

#define	GFXMMU_LUT835L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT835L_EN_B_0X1		(0x1u<<0)

// LUT835H Configuration

#define	GFXMMU_LUT835H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT835H_LO_0			(0x1u<<0)

// LUT836L Configuration

#define	GFXMMU_LUT836L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT836L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT836L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT836L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT836L_EN			(0x1u<<0)

#define	GFXMMU_LUT836L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT836L_EN_B_0X1		(0x1u<<0)

// LUT836H Configuration

#define	GFXMMU_LUT836H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT836H_LO_0			(0x1u<<0)

// LUT837L Configuration

#define	GFXMMU_LUT837L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT837L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT837L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT837L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT837L_EN			(0x1u<<0)

#define	GFXMMU_LUT837L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT837L_EN_B_0X1		(0x1u<<0)

// LUT837H Configuration

#define	GFXMMU_LUT837H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT837H_LO_0			(0x1u<<0)

// LUT838L Configuration

#define	GFXMMU_LUT838L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT838L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT838L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT838L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT838L_EN			(0x1u<<0)

#define	GFXMMU_LUT838L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT838L_EN_B_0X1		(0x1u<<0)

// LUT838H Configuration

#define	GFXMMU_LUT838H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT838H_LO_0			(0x1u<<0)

// LUT839L Configuration

#define	GFXMMU_LUT839L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT839L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT839L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT839L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT839L_EN			(0x1u<<0)

#define	GFXMMU_LUT839L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT839L_EN_B_0X1		(0x1u<<0)

// LUT839H Configuration

#define	GFXMMU_LUT839H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT839H_LO_0			(0x1u<<0)

// LUT840L Configuration

#define	GFXMMU_LUT840L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT840L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT840L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT840L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT840L_EN			(0x1u<<0)

#define	GFXMMU_LUT840L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT840L_EN_B_0X1		(0x1u<<0)

// LUT840H Configuration

#define	GFXMMU_LUT840H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT840H_LO_0			(0x1u<<0)

// LUT841L Configuration

#define	GFXMMU_LUT841L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT841L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT841L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT841L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT841L_EN			(0x1u<<0)

#define	GFXMMU_LUT841L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT841L_EN_B_0X1		(0x1u<<0)

// LUT841H Configuration

#define	GFXMMU_LUT841H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT841H_LO_0			(0x1u<<0)

// LUT842L Configuration

#define	GFXMMU_LUT842L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT842L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT842L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT842L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT842L_EN			(0x1u<<0)

#define	GFXMMU_LUT842L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT842L_EN_B_0X1		(0x1u<<0)

// LUT842H Configuration

#define	GFXMMU_LUT842H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT842H_LO_0			(0x1u<<0)

// LUT843L Configuration

#define	GFXMMU_LUT843L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT843L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT843L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT843L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT843L_EN			(0x1u<<0)

#define	GFXMMU_LUT843L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT843L_EN_B_0X1		(0x1u<<0)

// LUT843H Configuration

#define	GFXMMU_LUT843H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT843H_LO_0			(0x1u<<0)

// LUT844L Configuration

#define	GFXMMU_LUT844L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT844L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT844L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT844L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT844L_EN			(0x1u<<0)

#define	GFXMMU_LUT844L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT844L_EN_B_0X1		(0x1u<<0)

// LUT844H Configuration

#define	GFXMMU_LUT844H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT844H_LO_0			(0x1u<<0)

// LUT845L Configuration

#define	GFXMMU_LUT845L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT845L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT845L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT845L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT845L_EN			(0x1u<<0)

#define	GFXMMU_LUT845L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT845L_EN_B_0X1		(0x1u<<0)

// LUT845H Configuration

#define	GFXMMU_LUT845H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT845H_LO_0			(0x1u<<0)

// LUT846L Configuration

#define	GFXMMU_LUT846L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT846L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT846L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT846L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT846L_EN			(0x1u<<0)

#define	GFXMMU_LUT846L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT846L_EN_B_0X1		(0x1u<<0)

// LUT846H Configuration

#define	GFXMMU_LUT846H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT846H_LO_0			(0x1u<<0)

// LUT847L Configuration

#define	GFXMMU_LUT847L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT847L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT847L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT847L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT847L_EN			(0x1u<<0)

#define	GFXMMU_LUT847L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT847L_EN_B_0X1		(0x1u<<0)

// LUT847H Configuration

#define	GFXMMU_LUT847H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT847H_LO_0			(0x1u<<0)

// LUT848L Configuration

#define	GFXMMU_LUT848L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT848L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT848L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT848L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT848L_EN			(0x1u<<0)

#define	GFXMMU_LUT848L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT848L_EN_B_0X1		(0x1u<<0)

// LUT848H Configuration

#define	GFXMMU_LUT848H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT848H_LO_0			(0x1u<<0)

// LUT849L Configuration

#define	GFXMMU_LUT849L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT849L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT849L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT849L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT849L_EN			(0x1u<<0)

#define	GFXMMU_LUT849L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT849L_EN_B_0X1		(0x1u<<0)

// LUT849H Configuration

#define	GFXMMU_LUT849H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT849H_LO_0			(0x1u<<0)

// LUT850L Configuration

#define	GFXMMU_LUT850L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT850L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT850L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT850L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT850L_EN			(0x1u<<0)

#define	GFXMMU_LUT850L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT850L_EN_B_0X1		(0x1u<<0)

// LUT850H Configuration

#define	GFXMMU_LUT850H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT850H_LO_0			(0x1u<<0)

// LUT851L Configuration

#define	GFXMMU_LUT851L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT851L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT851L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT851L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT851L_EN			(0x1u<<0)

#define	GFXMMU_LUT851L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT851L_EN_B_0X1		(0x1u<<0)

// LUT851H Configuration

#define	GFXMMU_LUT851H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT851H_LO_0			(0x1u<<0)

// LUT852L Configuration

#define	GFXMMU_LUT852L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT852L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT852L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT852L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT852L_EN			(0x1u<<0)

#define	GFXMMU_LUT852L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT852L_EN_B_0X1		(0x1u<<0)

// LUT852H Configuration

#define	GFXMMU_LUT852H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT852H_LO_0			(0x1u<<0)

// LUT853L Configuration

#define	GFXMMU_LUT853L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT853L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT853L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT853L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT853L_EN			(0x1u<<0)

#define	GFXMMU_LUT853L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT853L_EN_B_0X1		(0x1u<<0)

// LUT853H Configuration

#define	GFXMMU_LUT853H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT853H_LO_0			(0x1u<<0)

// LUT854L Configuration

#define	GFXMMU_LUT854L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT854L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT854L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT854L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT854L_EN			(0x1u<<0)

#define	GFXMMU_LUT854L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT854L_EN_B_0X1		(0x1u<<0)

// LUT854H Configuration

#define	GFXMMU_LUT854H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT854H_LO_0			(0x1u<<0)

// LUT855L Configuration

#define	GFXMMU_LUT855L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT855L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT855L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT855L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT855L_EN			(0x1u<<0)

#define	GFXMMU_LUT855L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT855L_EN_B_0X1		(0x1u<<0)

// LUT855H Configuration

#define	GFXMMU_LUT855H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT855H_LO_0			(0x1u<<0)

// LUT856L Configuration

#define	GFXMMU_LUT856L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT856L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT856L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT856L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT856L_EN			(0x1u<<0)

#define	GFXMMU_LUT856L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT856L_EN_B_0X1		(0x1u<<0)

// LUT856H Configuration

#define	GFXMMU_LUT856H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT856H_LO_0			(0x1u<<0)

// LUT857L Configuration

#define	GFXMMU_LUT857L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT857L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT857L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT857L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT857L_EN			(0x1u<<0)

#define	GFXMMU_LUT857L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT857L_EN_B_0X1		(0x1u<<0)

// LUT857H Configuration

#define	GFXMMU_LUT857H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT857H_LO_0			(0x1u<<0)

// LUT858L Configuration

#define	GFXMMU_LUT858L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT858L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT858L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT858L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT858L_EN			(0x1u<<0)

#define	GFXMMU_LUT858L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT858L_EN_B_0X1		(0x1u<<0)

// LUT858H Configuration

#define	GFXMMU_LUT858H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT858H_LO_0			(0x1u<<0)

// LUT859L Configuration

#define	GFXMMU_LUT859L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT859L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT859L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT859L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT859L_EN			(0x1u<<0)

#define	GFXMMU_LUT859L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT859L_EN_B_0X1		(0x1u<<0)

// LUT859H Configuration

#define	GFXMMU_LUT859H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT859H_LO_0			(0x1u<<0)

// LUT860L Configuration

#define	GFXMMU_LUT860L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT860L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT860L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT860L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT860L_EN			(0x1u<<0)

#define	GFXMMU_LUT860L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT860L_EN_B_0X1		(0x1u<<0)

// LUT860H Configuration

#define	GFXMMU_LUT860H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT860H_LO_0			(0x1u<<0)

// LUT861L Configuration

#define	GFXMMU_LUT861L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT861L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT861L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT861L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT861L_EN			(0x1u<<0)

#define	GFXMMU_LUT861L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT861L_EN_B_0X1		(0x1u<<0)

// LUT861H Configuration

#define	GFXMMU_LUT861H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT861H_LO_0			(0x1u<<0)

// LUT862L Configuration

#define	GFXMMU_LUT862L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT862L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT862L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT862L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT862L_EN			(0x1u<<0)

#define	GFXMMU_LUT862L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT862L_EN_B_0X1		(0x1u<<0)

// LUT862H Configuration

#define	GFXMMU_LUT862H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT862H_LO_0			(0x1u<<0)

// LUT863L Configuration

#define	GFXMMU_LUT863L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT863L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT863L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT863L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT863L_EN			(0x1u<<0)

#define	GFXMMU_LUT863L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT863L_EN_B_0X1		(0x1u<<0)

// LUT863H Configuration

#define	GFXMMU_LUT863H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT863H_LO_0			(0x1u<<0)

// LUT864L Configuration

#define	GFXMMU_LUT864L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT864L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT864L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT864L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT864L_EN			(0x1u<<0)

#define	GFXMMU_LUT864L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT864L_EN_B_0X1		(0x1u<<0)

// LUT864H Configuration

#define	GFXMMU_LUT864H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT864H_LO_0			(0x1u<<0)

// LUT865L Configuration

#define	GFXMMU_LUT865L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT865L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT865L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT865L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT865L_EN			(0x1u<<0)

#define	GFXMMU_LUT865L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT865L_EN_B_0X1		(0x1u<<0)

// LUT865H Configuration

#define	GFXMMU_LUT865H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT865H_LO_0			(0x1u<<0)

// LUT866L Configuration

#define	GFXMMU_LUT866L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT866L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT866L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT866L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT866L_EN			(0x1u<<0)

#define	GFXMMU_LUT866L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT866L_EN_B_0X1		(0x1u<<0)

// LUT866H Configuration

#define	GFXMMU_LUT866H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT866H_LO_0			(0x1u<<0)

// LUT867L Configuration

#define	GFXMMU_LUT867L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT867L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT867L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT867L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT867L_EN			(0x1u<<0)

#define	GFXMMU_LUT867L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT867L_EN_B_0X1		(0x1u<<0)

// LUT867H Configuration

#define	GFXMMU_LUT867H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT867H_LO_0			(0x1u<<0)

// LUT868L Configuration

#define	GFXMMU_LUT868L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT868L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT868L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT868L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT868L_EN			(0x1u<<0)

#define	GFXMMU_LUT868L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT868L_EN_B_0X1		(0x1u<<0)

// LUT868H Configuration

#define	GFXMMU_LUT868H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT868H_LO_0			(0x1u<<0)

// LUT869L Configuration

#define	GFXMMU_LUT869L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT869L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT869L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT869L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT869L_EN			(0x1u<<0)

#define	GFXMMU_LUT869L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT869L_EN_B_0X1		(0x1u<<0)

// LUT869H Configuration

#define	GFXMMU_LUT869H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT869H_LO_0			(0x1u<<0)

// LUT870L Configuration

#define	GFXMMU_LUT870L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT870L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT870L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT870L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT870L_EN			(0x1u<<0)

#define	GFXMMU_LUT870L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT870L_EN_B_0X1		(0x1u<<0)

// LUT870H Configuration

#define	GFXMMU_LUT870H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT870H_LO_0			(0x1u<<0)

// LUT871L Configuration

#define	GFXMMU_LUT871L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT871L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT871L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT871L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT871L_EN			(0x1u<<0)

#define	GFXMMU_LUT871L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT871L_EN_B_0X1		(0x1u<<0)

// LUT871H Configuration

#define	GFXMMU_LUT871H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT871H_LO_0			(0x1u<<0)

// LUT872L Configuration

#define	GFXMMU_LUT872L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT872L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT872L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT872L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT872L_EN			(0x1u<<0)

#define	GFXMMU_LUT872L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT872L_EN_B_0X1		(0x1u<<0)

// LUT872H Configuration

#define	GFXMMU_LUT872H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT872H_LO_0			(0x1u<<0)

// LUT873L Configuration

#define	GFXMMU_LUT873L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT873L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT873L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT873L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT873L_EN			(0x1u<<0)

#define	GFXMMU_LUT873L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT873L_EN_B_0X1		(0x1u<<0)

// LUT873H Configuration

#define	GFXMMU_LUT873H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT873H_LO_0			(0x1u<<0)

// LUT874L Configuration

#define	GFXMMU_LUT874L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT874L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT874L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT874L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT874L_EN			(0x1u<<0)

#define	GFXMMU_LUT874L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT874L_EN_B_0X1		(0x1u<<0)

// LUT874H Configuration

#define	GFXMMU_LUT874H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT874H_LO_0			(0x1u<<0)

// LUT875L Configuration

#define	GFXMMU_LUT875L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT875L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT875L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT875L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT875L_EN			(0x1u<<0)

#define	GFXMMU_LUT875L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT875L_EN_B_0X1		(0x1u<<0)

// LUT875H Configuration

#define	GFXMMU_LUT875H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT875H_LO_0			(0x1u<<0)

// LUT876L Configuration

#define	GFXMMU_LUT876L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT876L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT876L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT876L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT876L_EN			(0x1u<<0)

#define	GFXMMU_LUT876L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT876L_EN_B_0X1		(0x1u<<0)

// LUT876H Configuration

#define	GFXMMU_LUT876H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT876H_LO_0			(0x1u<<0)

// LUT877L Configuration

#define	GFXMMU_LUT877L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT877L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT877L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT877L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT877L_EN			(0x1u<<0)

#define	GFXMMU_LUT877L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT877L_EN_B_0X1		(0x1u<<0)

// LUT877H Configuration

#define	GFXMMU_LUT877H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT877H_LO_0			(0x1u<<0)

// LUT878L Configuration

#define	GFXMMU_LUT878L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT878L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT878L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT878L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT878L_EN			(0x1u<<0)

#define	GFXMMU_LUT878L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT878L_EN_B_0X1		(0x1u<<0)

// LUT878H Configuration

#define	GFXMMU_LUT878H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT878H_LO_0			(0x1u<<0)

// LUT879L Configuration

#define	GFXMMU_LUT879L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT879L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT879L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT879L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT879L_EN			(0x1u<<0)

#define	GFXMMU_LUT879L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT879L_EN_B_0X1		(0x1u<<0)

// LUT879H Configuration

#define	GFXMMU_LUT879H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT879H_LO_0			(0x1u<<0)

// LUT880L Configuration

#define	GFXMMU_LUT880L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT880L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT880L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT880L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT880L_EN			(0x1u<<0)

#define	GFXMMU_LUT880L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT880L_EN_B_0X1		(0x1u<<0)

// LUT880H Configuration

#define	GFXMMU_LUT880H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT880H_LO_0			(0x1u<<0)

// LUT881L Configuration

#define	GFXMMU_LUT881L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT881L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT881L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT881L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT881L_EN			(0x1u<<0)

#define	GFXMMU_LUT881L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT881L_EN_B_0X1		(0x1u<<0)

// LUT881H Configuration

#define	GFXMMU_LUT881H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT881H_LO_0			(0x1u<<0)

// LUT882L Configuration

#define	GFXMMU_LUT882L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT882L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT882L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT882L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT882L_EN			(0x1u<<0)

#define	GFXMMU_LUT882L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT882L_EN_B_0X1		(0x1u<<0)

// LUT882H Configuration

#define	GFXMMU_LUT882H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT882H_LO_0			(0x1u<<0)

// LUT883L Configuration

#define	GFXMMU_LUT883L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT883L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT883L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT883L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT883L_EN			(0x1u<<0)

#define	GFXMMU_LUT883L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT883L_EN_B_0X1		(0x1u<<0)

// LUT883H Configuration

#define	GFXMMU_LUT883H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT883H_LO_0			(0x1u<<0)

// LUT884L Configuration

#define	GFXMMU_LUT884L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT884L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT884L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT884L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT884L_EN			(0x1u<<0)

#define	GFXMMU_LUT884L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT884L_EN_B_0X1		(0x1u<<0)

// LUT884H Configuration

#define	GFXMMU_LUT884H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT884H_LO_0			(0x1u<<0)

// LUT885L Configuration

#define	GFXMMU_LUT885L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT885L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT885L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT885L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT885L_EN			(0x1u<<0)

#define	GFXMMU_LUT885L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT885L_EN_B_0X1		(0x1u<<0)

// LUT885H Configuration

#define	GFXMMU_LUT885H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT885H_LO_0			(0x1u<<0)

// LUT886L Configuration

#define	GFXMMU_LUT886L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT886L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT886L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT886L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT886L_EN			(0x1u<<0)

#define	GFXMMU_LUT886L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT886L_EN_B_0X1		(0x1u<<0)

// LUT886H Configuration

#define	GFXMMU_LUT886H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT886H_LO_0			(0x1u<<0)

// LUT887L Configuration

#define	GFXMMU_LUT887L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT887L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT887L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT887L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT887L_EN			(0x1u<<0)

#define	GFXMMU_LUT887L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT887L_EN_B_0X1		(0x1u<<0)

// LUT887H Configuration

#define	GFXMMU_LUT887H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT887H_LO_0			(0x1u<<0)

// LUT888L Configuration

#define	GFXMMU_LUT888L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT888L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT888L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT888L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT888L_EN			(0x1u<<0)

#define	GFXMMU_LUT888L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT888L_EN_B_0X1		(0x1u<<0)

// LUT888H Configuration

#define	GFXMMU_LUT888H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT888H_LO_0			(0x1u<<0)

// LUT889L Configuration

#define	GFXMMU_LUT889L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT889L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT889L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT889L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT889L_EN			(0x1u<<0)

#define	GFXMMU_LUT889L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT889L_EN_B_0X1		(0x1u<<0)

// LUT889H Configuration

#define	GFXMMU_LUT889H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT889H_LO_0			(0x1u<<0)

// LUT890L Configuration

#define	GFXMMU_LUT890L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT890L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT890L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT890L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT890L_EN			(0x1u<<0)

#define	GFXMMU_LUT890L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT890L_EN_B_0X1		(0x1u<<0)

// LUT890H Configuration

#define	GFXMMU_LUT890H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT890H_LO_0			(0x1u<<0)

// LUT891L Configuration

#define	GFXMMU_LUT891L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT891L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT891L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT891L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT891L_EN			(0x1u<<0)

#define	GFXMMU_LUT891L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT891L_EN_B_0X1		(0x1u<<0)

// LUT891H Configuration

#define	GFXMMU_LUT891H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT891H_LO_0			(0x1u<<0)

// LUT892L Configuration

#define	GFXMMU_LUT892L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT892L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT892L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT892L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT892L_EN			(0x1u<<0)

#define	GFXMMU_LUT892L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT892L_EN_B_0X1		(0x1u<<0)

// LUT892H Configuration

#define	GFXMMU_LUT892H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT892H_LO_0			(0x1u<<0)

// LUT893L Configuration

#define	GFXMMU_LUT893L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT893L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT893L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT893L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT893L_EN			(0x1u<<0)

#define	GFXMMU_LUT893L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT893L_EN_B_0X1		(0x1u<<0)

// LUT893H Configuration

#define	GFXMMU_LUT893H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT893H_LO_0			(0x1u<<0)

// LUT894L Configuration

#define	GFXMMU_LUT894L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT894L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT894L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT894L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT894L_EN			(0x1u<<0)

#define	GFXMMU_LUT894L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT894L_EN_B_0X1		(0x1u<<0)

// LUT894H Configuration

#define	GFXMMU_LUT894H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT894H_LO_0			(0x1u<<0)

// LUT895L Configuration

#define	GFXMMU_LUT895L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT895L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT895L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT895L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT895L_EN			(0x1u<<0)

#define	GFXMMU_LUT895L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT895L_EN_B_0X1		(0x1u<<0)

// LUT895H Configuration

#define	GFXMMU_LUT895H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT895H_LO_0			(0x1u<<0)

// LUT896L Configuration

#define	GFXMMU_LUT896L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT896L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT896L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT896L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT896L_EN			(0x1u<<0)

#define	GFXMMU_LUT896L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT896L_EN_B_0X1		(0x1u<<0)

// LUT896H Configuration

#define	GFXMMU_LUT896H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT896H_LO_0			(0x1u<<0)

// LUT897L Configuration

#define	GFXMMU_LUT897L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT897L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT897L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT897L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT897L_EN			(0x1u<<0)

#define	GFXMMU_LUT897L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT897L_EN_B_0X1		(0x1u<<0)

// LUT897H Configuration

#define	GFXMMU_LUT897H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT897H_LO_0			(0x1u<<0)

// LUT898L Configuration

#define	GFXMMU_LUT898L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT898L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT898L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT898L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT898L_EN			(0x1u<<0)

#define	GFXMMU_LUT898L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT898L_EN_B_0X1		(0x1u<<0)

// LUT898H Configuration

#define	GFXMMU_LUT898H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT898H_LO_0			(0x1u<<0)

// LUT899L Configuration

#define	GFXMMU_LUT899L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT899L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT899L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT899L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT899L_EN			(0x1u<<0)

#define	GFXMMU_LUT899L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT899L_EN_B_0X1		(0x1u<<0)

// LUT899H Configuration

#define	GFXMMU_LUT899H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT899H_LO_0			(0x1u<<0)

// LUT900L Configuration

#define	GFXMMU_LUT900L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT900L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT900L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT900L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT900L_EN			(0x1u<<0)

#define	GFXMMU_LUT900L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT900L_EN_B_0X1		(0x1u<<0)

// LUT900H Configuration

#define	GFXMMU_LUT900H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT900H_LO_0			(0x1u<<0)

// LUT901L Configuration

#define	GFXMMU_LUT901L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT901L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT901L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT901L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT901L_EN			(0x1u<<0)

#define	GFXMMU_LUT901L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT901L_EN_B_0X1		(0x1u<<0)

// LUT901H Configuration

#define	GFXMMU_LUT901H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT901H_LO_0			(0x1u<<0)

// LUT902L Configuration

#define	GFXMMU_LUT902L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT902L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT902L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT902L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT902L_EN			(0x1u<<0)

#define	GFXMMU_LUT902L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT902L_EN_B_0X1		(0x1u<<0)

// LUT902H Configuration

#define	GFXMMU_LUT902H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT902H_LO_0			(0x1u<<0)

// LUT903L Configuration

#define	GFXMMU_LUT903L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT903L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT903L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT903L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT903L_EN			(0x1u<<0)

#define	GFXMMU_LUT903L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT903L_EN_B_0X1		(0x1u<<0)

// LUT903H Configuration

#define	GFXMMU_LUT903H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT903H_LO_0			(0x1u<<0)

// LUT904L Configuration

#define	GFXMMU_LUT904L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT904L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT904L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT904L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT904L_EN			(0x1u<<0)

#define	GFXMMU_LUT904L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT904L_EN_B_0X1		(0x1u<<0)

// LUT904H Configuration

#define	GFXMMU_LUT904H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT904H_LO_0			(0x1u<<0)

// LUT905L Configuration

#define	GFXMMU_LUT905L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT905L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT905L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT905L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT905L_EN			(0x1u<<0)

#define	GFXMMU_LUT905L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT905L_EN_B_0X1		(0x1u<<0)

// LUT905H Configuration

#define	GFXMMU_LUT905H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT905H_LO_0			(0x1u<<0)

// LUT906L Configuration

#define	GFXMMU_LUT906L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT906L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT906L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT906L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT906L_EN			(0x1u<<0)

#define	GFXMMU_LUT906L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT906L_EN_B_0X1		(0x1u<<0)

// LUT906H Configuration

#define	GFXMMU_LUT906H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT906H_LO_0			(0x1u<<0)

// LUT907L Configuration

#define	GFXMMU_LUT907L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT907L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT907L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT907L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT907L_EN			(0x1u<<0)

#define	GFXMMU_LUT907L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT907L_EN_B_0X1		(0x1u<<0)

// LUT907H Configuration

#define	GFXMMU_LUT907H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT907H_LO_0			(0x1u<<0)

// LUT908L Configuration

#define	GFXMMU_LUT908L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT908L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT908L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT908L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT908L_EN			(0x1u<<0)

#define	GFXMMU_LUT908L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT908L_EN_B_0X1		(0x1u<<0)

// LUT908H Configuration

#define	GFXMMU_LUT908H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT908H_LO_0			(0x1u<<0)

// LUT909L Configuration

#define	GFXMMU_LUT909L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT909L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT909L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT909L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT909L_EN			(0x1u<<0)

#define	GFXMMU_LUT909L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT909L_EN_B_0X1		(0x1u<<0)

// LUT909H Configuration

#define	GFXMMU_LUT909H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT909H_LO_0			(0x1u<<0)

// LUT910L Configuration

#define	GFXMMU_LUT910L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT910L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT910L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT910L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT910L_EN			(0x1u<<0)

#define	GFXMMU_LUT910L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT910L_EN_B_0X1		(0x1u<<0)

// LUT910H Configuration

#define	GFXMMU_LUT910H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT910H_LO_0			(0x1u<<0)

// LUT911L Configuration

#define	GFXMMU_LUT911L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT911L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT911L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT911L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT911L_EN			(0x1u<<0)

#define	GFXMMU_LUT911L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT911L_EN_B_0X1		(0x1u<<0)

// LUT911H Configuration

#define	GFXMMU_LUT911H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT911H_LO_0			(0x1u<<0)

// LUT912L Configuration

#define	GFXMMU_LUT912L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT912L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT912L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT912L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT912L_EN			(0x1u<<0)

#define	GFXMMU_LUT912L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT912L_EN_B_0X1		(0x1u<<0)

// LUT912H Configuration

#define	GFXMMU_LUT912H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT912H_LO_0			(0x1u<<0)

// LUT913L Configuration

#define	GFXMMU_LUT913L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT913L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT913L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT913L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT913L_EN			(0x1u<<0)

#define	GFXMMU_LUT913L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT913L_EN_B_0X1		(0x1u<<0)

// LUT913H Configuration

#define	GFXMMU_LUT913H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT913H_LO_0			(0x1u<<0)

// LUT914L Configuration

#define	GFXMMU_LUT914L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT914L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT914L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT914L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT914L_EN			(0x1u<<0)

#define	GFXMMU_LUT914L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT914L_EN_B_0X1		(0x1u<<0)

// LUT914H Configuration

#define	GFXMMU_LUT914H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT914H_LO_0			(0x1u<<0)

// LUT915L Configuration

#define	GFXMMU_LUT915L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT915L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT915L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT915L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT915L_EN			(0x1u<<0)

#define	GFXMMU_LUT915L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT915L_EN_B_0X1		(0x1u<<0)

// LUT915H Configuration

#define	GFXMMU_LUT915H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT915H_LO_0			(0x1u<<0)

// LUT916L Configuration

#define	GFXMMU_LUT916L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT916L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT916L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT916L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT916L_EN			(0x1u<<0)

#define	GFXMMU_LUT916L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT916L_EN_B_0X1		(0x1u<<0)

// LUT916H Configuration

#define	GFXMMU_LUT916H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT916H_LO_0			(0x1u<<0)

// LUT917L Configuration

#define	GFXMMU_LUT917L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT917L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT917L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT917L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT917L_EN			(0x1u<<0)

#define	GFXMMU_LUT917L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT917L_EN_B_0X1		(0x1u<<0)

// LUT917H Configuration

#define	GFXMMU_LUT917H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT917H_LO_0			(0x1u<<0)

// LUT918L Configuration

#define	GFXMMU_LUT918L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT918L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT918L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT918L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT918L_EN			(0x1u<<0)

#define	GFXMMU_LUT918L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT918L_EN_B_0X1		(0x1u<<0)

// LUT918H Configuration

#define	GFXMMU_LUT918H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT918H_LO_0			(0x1u<<0)

// LUT919L Configuration

#define	GFXMMU_LUT919L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT919L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT919L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT919L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT919L_EN			(0x1u<<0)

#define	GFXMMU_LUT919L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT919L_EN_B_0X1		(0x1u<<0)

// LUT919H Configuration

#define	GFXMMU_LUT919H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT919H_LO_0			(0x1u<<0)

// LUT920L Configuration

#define	GFXMMU_LUT920L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT920L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT920L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT920L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT920L_EN			(0x1u<<0)

#define	GFXMMU_LUT920L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT920L_EN_B_0X1		(0x1u<<0)

// LUT920H Configuration

#define	GFXMMU_LUT920H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT920H_LO_0			(0x1u<<0)

// LUT921L Configuration

#define	GFXMMU_LUT921L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT921L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT921L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT921L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT921L_EN			(0x1u<<0)

#define	GFXMMU_LUT921L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT921L_EN_B_0X1		(0x1u<<0)

// LUT921H Configuration

#define	GFXMMU_LUT921H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT921H_LO_0			(0x1u<<0)

// LUT922L Configuration

#define	GFXMMU_LUT922L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT922L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT922L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT922L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT922L_EN			(0x1u<<0)

#define	GFXMMU_LUT922L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT922L_EN_B_0X1		(0x1u<<0)

// LUT922H Configuration

#define	GFXMMU_LUT922H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT922H_LO_0			(0x1u<<0)

// LUT923L Configuration

#define	GFXMMU_LUT923L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT923L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT923L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT923L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT923L_EN			(0x1u<<0)

#define	GFXMMU_LUT923L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT923L_EN_B_0X1		(0x1u<<0)

// LUT923H Configuration

#define	GFXMMU_LUT923H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT923H_LO_0			(0x1u<<0)

// LUT924L Configuration

#define	GFXMMU_LUT924L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT924L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT924L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT924L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT924L_EN			(0x1u<<0)

#define	GFXMMU_LUT924L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT924L_EN_B_0X1		(0x1u<<0)

// LUT924H Configuration

#define	GFXMMU_LUT924H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT924H_LO_0			(0x1u<<0)

// LUT925L Configuration

#define	GFXMMU_LUT925L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT925L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT925L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT925L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT925L_EN			(0x1u<<0)

#define	GFXMMU_LUT925L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT925L_EN_B_0X1		(0x1u<<0)

// LUT925H Configuration

#define	GFXMMU_LUT925H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT925H_LO_0			(0x1u<<0)

// LUT926L Configuration

#define	GFXMMU_LUT926L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT926L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT926L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT926L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT926L_EN			(0x1u<<0)

#define	GFXMMU_LUT926L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT926L_EN_B_0X1		(0x1u<<0)

// LUT926H Configuration

#define	GFXMMU_LUT926H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT926H_LO_0			(0x1u<<0)

// LUT927L Configuration

#define	GFXMMU_LUT927L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT927L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT927L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT927L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT927L_EN			(0x1u<<0)

#define	GFXMMU_LUT927L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT927L_EN_B_0X1		(0x1u<<0)

// LUT927H Configuration

#define	GFXMMU_LUT927H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT927H_LO_0			(0x1u<<0)

// LUT928L Configuration

#define	GFXMMU_LUT928L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT928L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT928L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT928L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT928L_EN			(0x1u<<0)

#define	GFXMMU_LUT928L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT928L_EN_B_0X1		(0x1u<<0)

// LUT928H Configuration

#define	GFXMMU_LUT928H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT928H_LO_0			(0x1u<<0)

// LUT929L Configuration

#define	GFXMMU_LUT929L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT929L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT929L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT929L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT929L_EN			(0x1u<<0)

#define	GFXMMU_LUT929L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT929L_EN_B_0X1		(0x1u<<0)

// LUT929H Configuration

#define	GFXMMU_LUT929H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT929H_LO_0			(0x1u<<0)

// LUT930L Configuration

#define	GFXMMU_LUT930L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT930L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT930L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT930L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT930L_EN			(0x1u<<0)

#define	GFXMMU_LUT930L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT930L_EN_B_0X1		(0x1u<<0)

// LUT930H Configuration

#define	GFXMMU_LUT930H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT930H_LO_0			(0x1u<<0)

// LUT931L Configuration

#define	GFXMMU_LUT931L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT931L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT931L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT931L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT931L_EN			(0x1u<<0)

#define	GFXMMU_LUT931L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT931L_EN_B_0X1		(0x1u<<0)

// LUT931H Configuration

#define	GFXMMU_LUT931H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT931H_LO_0			(0x1u<<0)

// LUT932L Configuration

#define	GFXMMU_LUT932L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT932L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT932L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT932L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT932L_EN			(0x1u<<0)

#define	GFXMMU_LUT932L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT932L_EN_B_0X1		(0x1u<<0)

// LUT932H Configuration

#define	GFXMMU_LUT932H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT932H_LO_0			(0x1u<<0)

// LUT933L Configuration

#define	GFXMMU_LUT933L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT933L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT933L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT933L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT933L_EN			(0x1u<<0)

#define	GFXMMU_LUT933L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT933L_EN_B_0X1		(0x1u<<0)

// LUT933H Configuration

#define	GFXMMU_LUT933H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT933H_LO_0			(0x1u<<0)

// LUT934L Configuration

#define	GFXMMU_LUT934L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT934L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT934L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT934L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT934L_EN			(0x1u<<0)

#define	GFXMMU_LUT934L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT934L_EN_B_0X1		(0x1u<<0)

// LUT934H Configuration

#define	GFXMMU_LUT934H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT934H_LO_0			(0x1u<<0)

// LUT935L Configuration

#define	GFXMMU_LUT935L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT935L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT935L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT935L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT935L_EN			(0x1u<<0)

#define	GFXMMU_LUT935L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT935L_EN_B_0X1		(0x1u<<0)

// LUT935H Configuration

#define	GFXMMU_LUT935H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT935H_LO_0			(0x1u<<0)

// LUT936L Configuration

#define	GFXMMU_LUT936L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT936L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT936L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT936L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT936L_EN			(0x1u<<0)

#define	GFXMMU_LUT936L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT936L_EN_B_0X1		(0x1u<<0)

// LUT936H Configuration

#define	GFXMMU_LUT936H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT936H_LO_0			(0x1u<<0)

// LUT937L Configuration

#define	GFXMMU_LUT937L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT937L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT937L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT937L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT937L_EN			(0x1u<<0)

#define	GFXMMU_LUT937L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT937L_EN_B_0X1		(0x1u<<0)

// LUT937H Configuration

#define	GFXMMU_LUT937H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT937H_LO_0			(0x1u<<0)

// LUT938L Configuration

#define	GFXMMU_LUT938L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT938L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT938L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT938L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT938L_EN			(0x1u<<0)

#define	GFXMMU_LUT938L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT938L_EN_B_0X1		(0x1u<<0)

// LUT938H Configuration

#define	GFXMMU_LUT938H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT938H_LO_0			(0x1u<<0)

// LUT939L Configuration

#define	GFXMMU_LUT939L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT939L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT939L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT939L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT939L_EN			(0x1u<<0)

#define	GFXMMU_LUT939L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT939L_EN_B_0X1		(0x1u<<0)

// LUT939H Configuration

#define	GFXMMU_LUT939H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT939H_LO_0			(0x1u<<0)

// LUT940L Configuration

#define	GFXMMU_LUT940L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT940L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT940L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT940L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT940L_EN			(0x1u<<0)

#define	GFXMMU_LUT940L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT940L_EN_B_0X1		(0x1u<<0)

// LUT940H Configuration

#define	GFXMMU_LUT940H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT940H_LO_0			(0x1u<<0)

// LUT941L Configuration

#define	GFXMMU_LUT941L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT941L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT941L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT941L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT941L_EN			(0x1u<<0)

#define	GFXMMU_LUT941L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT941L_EN_B_0X1		(0x1u<<0)

// LUT941H Configuration

#define	GFXMMU_LUT941H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT941H_LO_0			(0x1u<<0)

// LUT942L Configuration

#define	GFXMMU_LUT942L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT942L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT942L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT942L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT942L_EN			(0x1u<<0)

#define	GFXMMU_LUT942L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT942L_EN_B_0X1		(0x1u<<0)

// LUT942H Configuration

#define	GFXMMU_LUT942H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT942H_LO_0			(0x1u<<0)

// LUT943L Configuration

#define	GFXMMU_LUT943L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT943L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT943L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT943L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT943L_EN			(0x1u<<0)

#define	GFXMMU_LUT943L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT943L_EN_B_0X1		(0x1u<<0)

// LUT943H Configuration

#define	GFXMMU_LUT943H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT943H_LO_0			(0x1u<<0)

// LUT944L Configuration

#define	GFXMMU_LUT944L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT944L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT944L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT944L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT944L_EN			(0x1u<<0)

#define	GFXMMU_LUT944L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT944L_EN_B_0X1		(0x1u<<0)

// LUT944H Configuration

#define	GFXMMU_LUT944H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT944H_LO_0			(0x1u<<0)

// LUT945L Configuration

#define	GFXMMU_LUT945L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT945L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT945L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT945L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT945L_EN			(0x1u<<0)

#define	GFXMMU_LUT945L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT945L_EN_B_0X1		(0x1u<<0)

// LUT945H Configuration

#define	GFXMMU_LUT945H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT945H_LO_0			(0x1u<<0)

// LUT946L Configuration

#define	GFXMMU_LUT946L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT946L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT946L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT946L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT946L_EN			(0x1u<<0)

#define	GFXMMU_LUT946L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT946L_EN_B_0X1		(0x1u<<0)

// LUT946H Configuration

#define	GFXMMU_LUT946H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT946H_LO_0			(0x1u<<0)

// LUT947L Configuration

#define	GFXMMU_LUT947L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT947L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT947L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT947L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT947L_EN			(0x1u<<0)

#define	GFXMMU_LUT947L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT947L_EN_B_0X1		(0x1u<<0)

// LUT947H Configuration

#define	GFXMMU_LUT947H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT947H_LO_0			(0x1u<<0)

// LUT948L Configuration

#define	GFXMMU_LUT948L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT948L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT948L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT948L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT948L_EN			(0x1u<<0)

#define	GFXMMU_LUT948L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT948L_EN_B_0X1		(0x1u<<0)

// LUT948H Configuration

#define	GFXMMU_LUT948H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT948H_LO_0			(0x1u<<0)

// LUT949L Configuration

#define	GFXMMU_LUT949L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT949L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT949L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT949L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT949L_EN			(0x1u<<0)

#define	GFXMMU_LUT949L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT949L_EN_B_0X1		(0x1u<<0)

// LUT949H Configuration

#define	GFXMMU_LUT949H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT949H_LO_0			(0x1u<<0)

// LUT950L Configuration

#define	GFXMMU_LUT950L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT950L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT950L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT950L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT950L_EN			(0x1u<<0)

#define	GFXMMU_LUT950L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT950L_EN_B_0X1		(0x1u<<0)

// LUT950H Configuration

#define	GFXMMU_LUT950H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT950H_LO_0			(0x1u<<0)

// LUT951L Configuration

#define	GFXMMU_LUT951L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT951L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT951L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT951L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT951L_EN			(0x1u<<0)

#define	GFXMMU_LUT951L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT951L_EN_B_0X1		(0x1u<<0)

// LUT951H Configuration

#define	GFXMMU_LUT951H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT951H_LO_0			(0x1u<<0)

// LUT952L Configuration

#define	GFXMMU_LUT952L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT952L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT952L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT952L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT952L_EN			(0x1u<<0)

#define	GFXMMU_LUT952L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT952L_EN_B_0X1		(0x1u<<0)

// LUT952H Configuration

#define	GFXMMU_LUT952H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT952H_LO_0			(0x1u<<0)

// LUT953L Configuration

#define	GFXMMU_LUT953L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT953L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT953L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT953L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT953L_EN			(0x1u<<0)

#define	GFXMMU_LUT953L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT953L_EN_B_0X1		(0x1u<<0)

// LUT953H Configuration

#define	GFXMMU_LUT953H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT953H_LO_0			(0x1u<<0)

// LUT954L Configuration

#define	GFXMMU_LUT954L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT954L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT954L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT954L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT954L_EN			(0x1u<<0)

#define	GFXMMU_LUT954L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT954L_EN_B_0X1		(0x1u<<0)

// LUT954H Configuration

#define	GFXMMU_LUT954H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT954H_LO_0			(0x1u<<0)

// LUT955L Configuration

#define	GFXMMU_LUT955L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT955L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT955L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT955L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT955L_EN			(0x1u<<0)

#define	GFXMMU_LUT955L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT955L_EN_B_0X1		(0x1u<<0)

// LUT955H Configuration

#define	GFXMMU_LUT955H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT955H_LO_0			(0x1u<<0)

// LUT956L Configuration

#define	GFXMMU_LUT956L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT956L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT956L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT956L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT956L_EN			(0x1u<<0)

#define	GFXMMU_LUT956L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT956L_EN_B_0X1		(0x1u<<0)

// LUT956H Configuration

#define	GFXMMU_LUT956H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT956H_LO_0			(0x1u<<0)

// LUT957L Configuration

#define	GFXMMU_LUT957L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT957L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT957L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT957L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT957L_EN			(0x1u<<0)

#define	GFXMMU_LUT957L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT957L_EN_B_0X1		(0x1u<<0)

// LUT957H Configuration

#define	GFXMMU_LUT957H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT957H_LO_0			(0x1u<<0)

// LUT958L Configuration

#define	GFXMMU_LUT958L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT958L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT958L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT958L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT958L_EN			(0x1u<<0)

#define	GFXMMU_LUT958L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT958L_EN_B_0X1		(0x1u<<0)

// LUT958H Configuration

#define	GFXMMU_LUT958H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT958H_LO_0			(0x1u<<0)

// LUT959L Configuration

#define	GFXMMU_LUT959L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT959L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT959L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT959L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT959L_EN			(0x1u<<0)

#define	GFXMMU_LUT959L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT959L_EN_B_0X1		(0x1u<<0)

// LUT959H Configuration

#define	GFXMMU_LUT959H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT959H_LO_0			(0x1u<<0)

// LUT960L Configuration

#define	GFXMMU_LUT960L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT960L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT960L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT960L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT960L_EN			(0x1u<<0)

#define	GFXMMU_LUT960L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT960L_EN_B_0X1		(0x1u<<0)

// LUT960H Configuration

#define	GFXMMU_LUT960H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT960H_LO_0			(0x1u<<0)

// LUT961L Configuration

#define	GFXMMU_LUT961L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT961L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT961L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT961L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT961L_EN			(0x1u<<0)

#define	GFXMMU_LUT961L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT961L_EN_B_0X1		(0x1u<<0)

// LUT961H Configuration

#define	GFXMMU_LUT961H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT961H_LO_0			(0x1u<<0)

// LUT962L Configuration

#define	GFXMMU_LUT962L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT962L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT962L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT962L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT962L_EN			(0x1u<<0)

#define	GFXMMU_LUT962L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT962L_EN_B_0X1		(0x1u<<0)

// LUT962H Configuration

#define	GFXMMU_LUT962H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT962H_LO_0			(0x1u<<0)

// LUT963L Configuration

#define	GFXMMU_LUT963L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT963L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT963L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT963L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT963L_EN			(0x1u<<0)

#define	GFXMMU_LUT963L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT963L_EN_B_0X1		(0x1u<<0)

// LUT963H Configuration

#define	GFXMMU_LUT963H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT963H_LO_0			(0x1u<<0)

// LUT964L Configuration

#define	GFXMMU_LUT964L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT964L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT964L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT964L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT964L_EN			(0x1u<<0)

#define	GFXMMU_LUT964L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT964L_EN_B_0X1		(0x1u<<0)

// LUT964H Configuration

#define	GFXMMU_LUT964H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT964H_LO_0			(0x1u<<0)

// LUT965L Configuration

#define	GFXMMU_LUT965L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT965L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT965L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT965L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT965L_EN			(0x1u<<0)

#define	GFXMMU_LUT965L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT965L_EN_B_0X1		(0x1u<<0)

// LUT965H Configuration

#define	GFXMMU_LUT965H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT965H_LO_0			(0x1u<<0)

// LUT966L Configuration

#define	GFXMMU_LUT966L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT966L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT966L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT966L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT966L_EN			(0x1u<<0)

#define	GFXMMU_LUT966L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT966L_EN_B_0X1		(0x1u<<0)

// LUT966H Configuration

#define	GFXMMU_LUT966H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT966H_LO_0			(0x1u<<0)

// LUT967L Configuration

#define	GFXMMU_LUT967L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT967L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT967L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT967L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT967L_EN			(0x1u<<0)

#define	GFXMMU_LUT967L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT967L_EN_B_0X1		(0x1u<<0)

// LUT967H Configuration

#define	GFXMMU_LUT967H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT967H_LO_0			(0x1u<<0)

// LUT968L Configuration

#define	GFXMMU_LUT968L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT968L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT968L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT968L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT968L_EN			(0x1u<<0)

#define	GFXMMU_LUT968L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT968L_EN_B_0X1		(0x1u<<0)

// LUT968H Configuration

#define	GFXMMU_LUT968H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT968H_LO_0			(0x1u<<0)

// LUT969L Configuration

#define	GFXMMU_LUT969L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT969L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT969L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT969L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT969L_EN			(0x1u<<0)

#define	GFXMMU_LUT969L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT969L_EN_B_0X1		(0x1u<<0)

// LUT969H Configuration

#define	GFXMMU_LUT969H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT969H_LO_0			(0x1u<<0)

// LUT970L Configuration

#define	GFXMMU_LUT970L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT970L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT970L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT970L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT970L_EN			(0x1u<<0)

#define	GFXMMU_LUT970L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT970L_EN_B_0X1		(0x1u<<0)

// LUT970H Configuration

#define	GFXMMU_LUT970H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT970H_LO_0			(0x1u<<0)

// LUT971L Configuration

#define	GFXMMU_LUT971L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT971L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT971L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT971L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT971L_EN			(0x1u<<0)

#define	GFXMMU_LUT971L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT971L_EN_B_0X1		(0x1u<<0)

// LUT971H Configuration

#define	GFXMMU_LUT971H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT971H_LO_0			(0x1u<<0)

// LUT972L Configuration

#define	GFXMMU_LUT972L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT972L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT972L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT972L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT972L_EN			(0x1u<<0)

#define	GFXMMU_LUT972L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT972L_EN_B_0X1		(0x1u<<0)

// LUT972H Configuration

#define	GFXMMU_LUT972H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT972H_LO_0			(0x1u<<0)

// LUT973L Configuration

#define	GFXMMU_LUT973L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT973L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT973L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT973L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT973L_EN			(0x1u<<0)

#define	GFXMMU_LUT973L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT973L_EN_B_0X1		(0x1u<<0)

// LUT973H Configuration

#define	GFXMMU_LUT973H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT973H_LO_0			(0x1u<<0)

// LUT974L Configuration

#define	GFXMMU_LUT974L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT974L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT974L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT974L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT974L_EN			(0x1u<<0)

#define	GFXMMU_LUT974L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT974L_EN_B_0X1		(0x1u<<0)

// LUT974H Configuration

#define	GFXMMU_LUT974H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT974H_LO_0			(0x1u<<0)

// LUT975L Configuration

#define	GFXMMU_LUT975L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT975L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT975L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT975L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT975L_EN			(0x1u<<0)

#define	GFXMMU_LUT975L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT975L_EN_B_0X1		(0x1u<<0)

// LUT975H Configuration

#define	GFXMMU_LUT975H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT975H_LO_0			(0x1u<<0)

// LUT976L Configuration

#define	GFXMMU_LUT976L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT976L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT976L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT976L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT976L_EN			(0x1u<<0)

#define	GFXMMU_LUT976L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT976L_EN_B_0X1		(0x1u<<0)

// LUT976H Configuration

#define	GFXMMU_LUT976H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT976H_LO_0			(0x1u<<0)

// LUT977L Configuration

#define	GFXMMU_LUT977L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT977L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT977L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT977L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT977L_EN			(0x1u<<0)

#define	GFXMMU_LUT977L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT977L_EN_B_0X1		(0x1u<<0)

// LUT977H Configuration

#define	GFXMMU_LUT977H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT977H_LO_0			(0x1u<<0)

// LUT978L Configuration

#define	GFXMMU_LUT978L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT978L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT978L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT978L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT978L_EN			(0x1u<<0)

#define	GFXMMU_LUT978L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT978L_EN_B_0X1		(0x1u<<0)

// LUT978H Configuration

#define	GFXMMU_LUT978H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT978H_LO_0			(0x1u<<0)

// LUT979L Configuration

#define	GFXMMU_LUT979L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT979L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT979L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT979L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT979L_EN			(0x1u<<0)

#define	GFXMMU_LUT979L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT979L_EN_B_0X1		(0x1u<<0)

// LUT979H Configuration

#define	GFXMMU_LUT979H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT979H_LO_0			(0x1u<<0)

// LUT980L Configuration

#define	GFXMMU_LUT980L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT980L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT980L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT980L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT980L_EN			(0x1u<<0)

#define	GFXMMU_LUT980L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT980L_EN_B_0X1		(0x1u<<0)

// LUT980H Configuration

#define	GFXMMU_LUT980H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT980H_LO_0			(0x1u<<0)

// LUT981L Configuration

#define	GFXMMU_LUT981L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT981L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT981L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT981L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT981L_EN			(0x1u<<0)

#define	GFXMMU_LUT981L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT981L_EN_B_0X1		(0x1u<<0)

// LUT981H Configuration

#define	GFXMMU_LUT981H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT981H_LO_0			(0x1u<<0)

// LUT982L Configuration

#define	GFXMMU_LUT982L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT982L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT982L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT982L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT982L_EN			(0x1u<<0)

#define	GFXMMU_LUT982L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT982L_EN_B_0X1		(0x1u<<0)

// LUT982H Configuration

#define	GFXMMU_LUT982H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT982H_LO_0			(0x1u<<0)

// LUT983L Configuration

#define	GFXMMU_LUT983L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT983L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT983L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT983L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT983L_EN			(0x1u<<0)

#define	GFXMMU_LUT983L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT983L_EN_B_0X1		(0x1u<<0)

// LUT983H Configuration

#define	GFXMMU_LUT983H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT983H_LO_0			(0x1u<<0)

// LUT984L Configuration

#define	GFXMMU_LUT984L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT984L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT984L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT984L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT984L_EN			(0x1u<<0)

#define	GFXMMU_LUT984L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT984L_EN_B_0X1		(0x1u<<0)

// LUT984H Configuration

#define	GFXMMU_LUT984H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT984H_LO_0			(0x1u<<0)

// LUT985L Configuration

#define	GFXMMU_LUT985L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT985L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT985L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT985L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT985L_EN			(0x1u<<0)

#define	GFXMMU_LUT985L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT985L_EN_B_0X1		(0x1u<<0)

// LUT985H Configuration

#define	GFXMMU_LUT985H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT985H_LO_0			(0x1u<<0)

// LUT986L Configuration

#define	GFXMMU_LUT986L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT986L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT986L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT986L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT986L_EN			(0x1u<<0)

#define	GFXMMU_LUT986L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT986L_EN_B_0X1		(0x1u<<0)

// LUT986H Configuration

#define	GFXMMU_LUT986H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT986H_LO_0			(0x1u<<0)

// LUT987L Configuration

#define	GFXMMU_LUT987L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT987L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT987L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT987L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT987L_EN			(0x1u<<0)

#define	GFXMMU_LUT987L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT987L_EN_B_0X1		(0x1u<<0)

// LUT987H Configuration

#define	GFXMMU_LUT987H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT987H_LO_0			(0x1u<<0)

// LUT988L Configuration

#define	GFXMMU_LUT988L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT988L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT988L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT988L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT988L_EN			(0x1u<<0)

#define	GFXMMU_LUT988L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT988L_EN_B_0X1		(0x1u<<0)

// LUT988H Configuration

#define	GFXMMU_LUT988H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT988H_LO_0			(0x1u<<0)

// LUT989L Configuration

#define	GFXMMU_LUT989L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT989L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT989L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT989L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT989L_EN			(0x1u<<0)

#define	GFXMMU_LUT989L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT989L_EN_B_0X1		(0x1u<<0)

// LUT989H Configuration

#define	GFXMMU_LUT989H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT989H_LO_0			(0x1u<<0)

// LUT990L Configuration

#define	GFXMMU_LUT990L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT990L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT990L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT990L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT990L_EN			(0x1u<<0)

#define	GFXMMU_LUT990L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT990L_EN_B_0X1		(0x1u<<0)

// LUT990H Configuration

#define	GFXMMU_LUT990H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT990H_LO_0			(0x1u<<0)

// LUT991L Configuration

#define	GFXMMU_LUT991L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT991L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT991L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT991L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT991L_EN			(0x1u<<0)

#define	GFXMMU_LUT991L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT991L_EN_B_0X1		(0x1u<<0)

// LUT991H Configuration

#define	GFXMMU_LUT991H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT991H_LO_0			(0x1u<<0)

// LUT992L Configuration

#define	GFXMMU_LUT992L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT992L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT992L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT992L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT992L_EN			(0x1u<<0)

#define	GFXMMU_LUT992L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT992L_EN_B_0X1		(0x1u<<0)

// LUT992H Configuration

#define	GFXMMU_LUT992H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT992H_LO_0			(0x1u<<0)

// LUT993L Configuration

#define	GFXMMU_LUT993L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT993L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT993L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT993L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT993L_EN			(0x1u<<0)

#define	GFXMMU_LUT993L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT993L_EN_B_0X1		(0x1u<<0)

// LUT993H Configuration

#define	GFXMMU_LUT993H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT993H_LO_0			(0x1u<<0)

// LUT994L Configuration

#define	GFXMMU_LUT994L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT994L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT994L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT994L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT994L_EN			(0x1u<<0)

#define	GFXMMU_LUT994L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT994L_EN_B_0X1		(0x1u<<0)

// LUT994H Configuration

#define	GFXMMU_LUT994H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT994H_LO_0			(0x1u<<0)

// LUT995L Configuration

#define	GFXMMU_LUT995L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT995L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT995L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT995L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT995L_EN			(0x1u<<0)

#define	GFXMMU_LUT995L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT995L_EN_B_0X1		(0x1u<<0)

// LUT995H Configuration

#define	GFXMMU_LUT995H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT995H_LO_0			(0x1u<<0)

// LUT996L Configuration

#define	GFXMMU_LUT996L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT996L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT996L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT996L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT996L_EN			(0x1u<<0)

#define	GFXMMU_LUT996L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT996L_EN_B_0X1		(0x1u<<0)

// LUT996H Configuration

#define	GFXMMU_LUT996H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT996H_LO_0			(0x1u<<0)

// LUT997L Configuration

#define	GFXMMU_LUT997L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT997L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT997L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT997L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT997L_EN			(0x1u<<0)

#define	GFXMMU_LUT997L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT997L_EN_B_0X1		(0x1u<<0)

// LUT997H Configuration

#define	GFXMMU_LUT997H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT997H_LO_0			(0x1u<<0)

// LUT998L Configuration

#define	GFXMMU_LUT998L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT998L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT998L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT998L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT998L_EN			(0x1u<<0)

#define	GFXMMU_LUT998L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT998L_EN_B_0X1		(0x1u<<0)

// LUT998H Configuration

#define	GFXMMU_LUT998H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT998H_LO_0			(0x1u<<0)

// LUT999L Configuration

#define	GFXMMU_LUT999L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT999L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT999L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT999L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT999L_EN			(0x1u<<0)

#define	GFXMMU_LUT999L_EN_B_0X0		(0x0u<<0)
#define	GFXMMU_LUT999L_EN_B_0X1		(0x1u<<0)

// LUT999H Configuration

#define	GFXMMU_LUT999H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT999H_LO_0			(0x1u<<0)

// LUT1000L Configuration

#define	GFXMMU_LUT1000L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1000L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1000L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1000L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1000L_EN			(0x1u<<0)

#define	GFXMMU_LUT1000L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1000L_EN_B_0X1	(0x1u<<0)

// LUT1000H Configuration

#define	GFXMMU_LUT1000H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1000H_LO_0		(0x1u<<0)

// LUT1001L Configuration

#define	GFXMMU_LUT1001L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1001L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1001L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1001L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1001L_EN			(0x1u<<0)

#define	GFXMMU_LUT1001L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1001L_EN_B_0X1	(0x1u<<0)

// LUT1001H Configuration

#define	GFXMMU_LUT1001H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1001H_LO_0		(0x1u<<0)

// LUT1002L Configuration

#define	GFXMMU_LUT1002L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1002L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1002L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1002L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1002L_EN			(0x1u<<0)

#define	GFXMMU_LUT1002L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1002L_EN_B_0X1	(0x1u<<0)

// LUT1002H Configuration

#define	GFXMMU_LUT1002H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1002H_LO_0		(0x1u<<0)

// LUT1003L Configuration

#define	GFXMMU_LUT1003L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1003L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1003L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1003L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1003L_EN			(0x1u<<0)

#define	GFXMMU_LUT1003L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1003L_EN_B_0X1	(0x1u<<0)

// LUT1003H Configuration

#define	GFXMMU_LUT1003H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1003H_LO_0		(0x1u<<0)

// LUT1004L Configuration

#define	GFXMMU_LUT1004L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1004L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1004L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1004L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1004L_EN			(0x1u<<0)

#define	GFXMMU_LUT1004L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1004L_EN_B_0X1	(0x1u<<0)

// LUT1004H Configuration

#define	GFXMMU_LUT1004H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1004H_LO_0		(0x1u<<0)

// LUT1005L Configuration

#define	GFXMMU_LUT1005L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1005L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1005L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1005L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1005L_EN			(0x1u<<0)

#define	GFXMMU_LUT1005L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1005L_EN_B_0X1	(0x1u<<0)

// LUT1005H Configuration

#define	GFXMMU_LUT1005H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1005H_LO_0		(0x1u<<0)

// LUT1006L Configuration

#define	GFXMMU_LUT1006L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1006L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1006L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1006L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1006L_EN			(0x1u<<0)

#define	GFXMMU_LUT1006L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1006L_EN_B_0X1	(0x1u<<0)

// LUT1006H Configuration

#define	GFXMMU_LUT1006H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1006H_LO_0		(0x1u<<0)

// LUT1007L Configuration

#define	GFXMMU_LUT1007L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1007L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1007L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1007L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1007L_EN			(0x1u<<0)

#define	GFXMMU_LUT1007L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1007L_EN_B_0X1	(0x1u<<0)

// LUT1007H Configuration

#define	GFXMMU_LUT1007H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1007H_LO_0		(0x1u<<0)

// LUT1008L Configuration

#define	GFXMMU_LUT1008L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1008L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1008L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1008L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1008L_EN			(0x1u<<0)

#define	GFXMMU_LUT1008L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1008L_EN_B_0X1	(0x1u<<0)

// LUT1008H Configuration

#define	GFXMMU_LUT1008H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1008H_LO_0		(0x1u<<0)

// LUT1009L Configuration

#define	GFXMMU_LUT1009L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1009L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1009L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1009L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1009L_EN			(0x1u<<0)

#define	GFXMMU_LUT1009L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1009L_EN_B_0X1	(0x1u<<0)

// LUT1009H Configuration

#define	GFXMMU_LUT1009H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1009H_LO_0		(0x1u<<0)

// LUT1010L Configuration

#define	GFXMMU_LUT1010L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1010L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1010L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1010L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1010L_EN			(0x1u<<0)

#define	GFXMMU_LUT1010L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1010L_EN_B_0X1	(0x1u<<0)

// LUT1010H Configuration

#define	GFXMMU_LUT1010H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1010H_LO_0		(0x1u<<0)

// LUT1011L Configuration

#define	GFXMMU_LUT1011L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1011L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1011L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1011L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1011L_EN			(0x1u<<0)

#define	GFXMMU_LUT1011L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1011L_EN_B_0X1	(0x1u<<0)

// LUT1011H Configuration

#define	GFXMMU_LUT1011H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1011H_LO_0		(0x1u<<0)

// LUT1012L Configuration

#define	GFXMMU_LUT1012L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1012L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1012L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1012L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1012L_EN			(0x1u<<0)

#define	GFXMMU_LUT1012L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1012L_EN_B_0X1	(0x1u<<0)

// LUT1012H Configuration

#define	GFXMMU_LUT1012H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1012H_LO_0		(0x1u<<0)

// LUT1013L Configuration

#define	GFXMMU_LUT1013L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1013L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1013L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1013L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1013L_EN			(0x1u<<0)

#define	GFXMMU_LUT1013L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1013L_EN_B_0X1	(0x1u<<0)

// LUT1013H Configuration

#define	GFXMMU_LUT1013H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1013H_LO_0		(0x1u<<0)

// LUT1014L Configuration

#define	GFXMMU_LUT1014L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1014L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1014L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1014L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1014L_EN			(0x1u<<0)

#define	GFXMMU_LUT1014L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1014L_EN_B_0X1	(0x1u<<0)

// LUT1014H Configuration

#define	GFXMMU_LUT1014H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1014H_LO_0		(0x1u<<0)

// LUT1015L Configuration

#define	GFXMMU_LUT1015L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1015L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1015L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1015L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1015L_EN			(0x1u<<0)

#define	GFXMMU_LUT1015L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1015L_EN_B_0X1	(0x1u<<0)

// LUT1015H Configuration

#define	GFXMMU_LUT1015H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1015H_LO_0		(0x1u<<0)

// LUT1016L Configuration

#define	GFXMMU_LUT1016L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1016L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1016L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1016L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1016L_EN			(0x1u<<0)

#define	GFXMMU_LUT1016L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1016L_EN_B_0X1	(0x1u<<0)

// LUT1016H Configuration

#define	GFXMMU_LUT1016H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1016H_LO_0		(0x1u<<0)

// LUT1017L Configuration

#define	GFXMMU_LUT1017L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1017L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1017L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1017L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1017L_EN			(0x1u<<0)

#define	GFXMMU_LUT1017L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1017L_EN_B_0X1	(0x1u<<0)

// LUT1017H Configuration

#define	GFXMMU_LUT1017H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1017H_LO_0		(0x1u<<0)

// LUT1018L Configuration

#define	GFXMMU_LUT1018L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1018L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1018L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1018L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1018L_EN			(0x1u<<0)

#define	GFXMMU_LUT1018L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1018L_EN_B_0X1	(0x1u<<0)

// LUT1018H Configuration

#define	GFXMMU_LUT1018H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1018H_LO_0		(0x1u<<0)

// LUT1019L Configuration

#define	GFXMMU_LUT1019L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1019L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1019L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1019L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1019L_EN			(0x1u<<0)

#define	GFXMMU_LUT1019L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1019L_EN_B_0X1	(0x1u<<0)

// LUT1019H Configuration

#define	GFXMMU_LUT1019H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1019H_LO_0		(0x1u<<0)

// LUT1020L Configuration

#define	GFXMMU_LUT1020L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1020L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1020L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1020L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1020L_EN			(0x1u<<0)

#define	GFXMMU_LUT1020L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1020L_EN_B_0X1	(0x1u<<0)

// LUT1020H Configuration

#define	GFXMMU_LUT1020H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1020H_LO_0		(0x1u<<0)

// LUT1021L Configuration

#define	GFXMMU_LUT1021L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1021L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1021L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1021L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1021L_EN			(0x1u<<0)

#define	GFXMMU_LUT1021L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1021L_EN_B_0X1	(0x1u<<0)

// LUT1021H Configuration

#define	GFXMMU_LUT1021H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1021H_LO_0		(0x1u<<0)

// LUT1022L Configuration

#define	GFXMMU_LUT1022L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1022L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1022L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1022L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1022L_EN			(0x1u<<0)

#define	GFXMMU_LUT1022L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1022L_EN_B_0X1	(0x1u<<0)

// LUT1022H Configuration

#define	GFXMMU_LUT1022H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1022H_LO_0		(0x1u<<0)

// LUT1023L Configuration

#define	GFXMMU_LUT1023L_LVB			(0xFFu<<16)
#define	GFXMMU_LUT1023L_LVB_0		(0x1u<<16)
#define	GFXMMU_LUT1023L_FVB			(0xFFu<<8)
#define	GFXMMU_LUT1023L_FVB_0		(0x1u<<8)
#define	GFXMMU_LUT1023L_EN			(0x1u<<0)

#define	GFXMMU_LUT1023L_EN_B_0X0	(0x0u<<0)
#define	GFXMMU_LUT1023L_EN_B_0X1	(0x1u<<0)

// LUT1023H Configuration

#define	GFXMMU_LUT1023H_LO			(0x3FFFFu<<0)
#define	GFXMMU_LUT1023H_LO_0		(0x1u<<0)
