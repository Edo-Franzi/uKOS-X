/*
; core.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Collection of core routines
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

#include	<stdbool.h>
#include	<stdint.h>
#include	"core_reg.h"

#define	core_getBASEPRI		core_getBASEPRI_S
#define	core_setBASEPRI		core_setBASEPRI_S
#define	core_getPSP			core_getPSP_S
#define	core_setPSP			core_setPSP_S
#define	core_getMSP			core_getMSP_S
#define	core_setMSP			core_setMSP_S
#define	core_getCONTROL		core_getCONTROL_S
#define	core_setCONTROL		core_setCONTROL_S
#define	core_getPSPLIM		core_getPSPLIM_S
#define	core_setPSPLIM		core_setPSPLIM_S
#define	core_getMSPLIM		core_getMSPLIM_S
#define	core_setMSPLIM		core_setMSPLIM_S
#define	core_getIPSR		core_getIPSR_S

/*
 * \brief core_getBASEPRI_S
 *
 * - Get the BASEPRI register
 *
 * \param[in]	-
 * \return		BASEPRI		The BASEPRI register
 *
 */
__attribute__ ((always_inline))	static	inline	uint32_t	core_getBASEPRI_S(void) {
	uint32_t	valBASEPRI;

	__asm volatile (
	"mrs		%0,basepri"
	: "=r" (valBASEPRI)
	);

	return (valBASEPRI);
}

/*
 * \brief core_getBASEPRI_NS
 *
 * - Get the BASEPRI register
 *
 * \param[in]	-
 * \return		BASEPRI		The BASEPRI register
 *
 */
__attribute__ ((always_inline))	static	inline	uint32_t	core_getBASEPRI_NS(void) {
	uint32_t	valBASEPRI;

	__asm volatile (
	"mrs		%0,basepri_ns"
	: "=r" (valBASEPRI)
	);

	return (valBASEPRI);
}

/*
 * \brief core_setBASEPRI_S
 *
 * - Set the BASEPRI register
 *
 * \param[in]	BASEPRI		The BASEPRI register
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	core_setBASEPRI_S(uint32_t valBASEPRI) {

	__asm volatile (
	"msr		basepri,%0"
	:
	: "r" (valBASEPRI)
	);
}

/*
 * \brief core_setBASEPRI_NS
 *
 * - Set the BASEPRI register
 *
 * \param[in]	BASEPRI		The BASEPRI register
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	core_setBASEPRI_NS(uint32_t valBASEPRI) {

	__asm volatile (
	"msr		basepri_ns,%0"
	:
	: "r" (valBASEPRI)
	);
}

/*
 * \brief core_getPSP_S
 *
 * - Get the PSP stack
 *
 * \param[in]	-
 * \return		stackPSP	The thread stack PSP
 *
 */
__attribute__ ((always_inline))	static	inline	uintptr_t	core_getPSP_S(void) {
	uintptr_t	stackPSP;

	__asm volatile (
	"mrs		%0,psp"
	: "=r" (stackPSP)
	);

	return (stackPSP);
}

/*
 * \brief core_getPSP_NS
 *
 * - Get the PSP stack
 *
 * \param[in]	-
 * \return		stackPSP	The thread stack PSP
 *
 */
__attribute__ ((always_inline))	static	inline	uintptr_t	core_getPSP_NS(void) {
	uintptr_t	stackPSP;

	__asm volatile (
	"mrs		%0,psp_ns"
	: "=r" (stackPSP)
	);

	return (stackPSP);
}

/*
 * \brief core_setPSP_S
 *
 * - Set the PSP stack
 *
 * \param[in]	stackPSP	The thread stack PSP
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	core_setPSP_S(uintptr_t stackPSP) {

	__asm volatile (
	"msr		psp,%0"
	:
	: "r" (stackPSP)
	);
}

/*
 * \brief core_setPSP_NS
 *
 * - Set the PSP stack
 *
 * \param[in]	stackPSP	The thread stack PSP
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	core_setPSP_NS(uintptr_t stackPSP) {

	__asm volatile (
	"msr		psp_ns,%0"
	:
	: "r" (stackPSP)
	);
}

/*
 * \brief core_getMSP_S
 *
 * - Get the MSP stack
 *
 * \param[in]	-
 * \return		stackMSP	The system stack MSP
 *
 */
__attribute__ ((always_inline))	static	inline	uintptr_t	core_getMSP_S(void) {
	uintptr_t	stackMSP;

	__asm volatile (
	"mrs		%0,msp"
	: "=r" (stackMSP)
	);

	return (stackMSP);
}

/*
 * \brief core_getMSP_NS
 *
 * - Get the MSP stack
 *
 * \param[in]	-
 * \return		stackMSP	The system stack MSP
 *
 */
__attribute__ ((always_inline))	static	inline	uintptr_t	core_getMSP_NS(void) {
	uintptr_t	stackMSP;

	__asm volatile (
	"mrs		%0,msp_ns"
	: "=r" (stackMSP)
	);

	return (stackMSP);
}

/*
 * \brief core_setMSP_S
 *
 * - Set the MSP stack
 *
 * \param[in]	stackMSP	The system stack MSP
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	core_setMSP_S(uintptr_t stackMSP) {

	__asm volatile (
	"msr		msp,%0"
	:
	: "r" (stackMSP)
	);
}

/*
 * \brief core_setMSP_NS
 *
 * - Set the MSP_NS stack
 *
 * \param[in]	stackMSP	The system stack MSP
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	core_setMSP_NS(uintptr_t stackMSP) {

	__asm volatile (
	"msr		msp_ns,%0"
	:
	: "r" (stackMSP)
	);
}

/*
 * \brief core_getCONTROL_S
 *
 * - Get the CONTROL register
 *
 * \param[in]	-
 * \return		CONTROL		The CONTROL register
 *
 */
__attribute__ ((always_inline))	static	inline	uint32_t	core_getCONTROL_S(void) {
	uint32_t	valCONTROL;

	__asm volatile (
	"mrs		%0,control"
	: "=r" (valCONTROL)
	);

	return (valCONTROL);
}

/*
 * \brief core_getCONTROL_NS
 *
 * - Get the CONTROL register
 *
 * \param[in]	-
 * \return		CONTROL		The CONTROL register
 *
 */
__attribute__ ((always_inline))	static	inline	uint32_t	core_getCONTROL_NS(void) {
	uint32_t	valCONTROL;

	__asm volatile (
	"mrs		%0,control_ns"
	: "=r" (valCONTROL)
	);

	return (valCONTROL);
}

/*
 * \brief core_setCONTROL_S
 *
 * - Set the core CONTROL register
 *
 * \param[in]	control	The system control register
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	core_setCONTROL_S(uint32_t valControl) {

	__asm volatile (
	"msr		control,%0"
	:
	: "r" (valControl)
	);
}

/*
 * \brief core_setCONTROL_NS
 *
 * - Set the core CONTROL register
 *
 * \param[in]	control	The system control register
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	core_setCONTROL_NS(uint32_t valControl) {

	__asm volatile (
	"msr		control_ns,%0"
	:
	: "r" (valControl)
	);
}

/*
 * \brief core_getPSPLIM_S
 *
 * - Get the PSP Limit
 *
 * \param[in]	-
 * \return		PSPLim	The thread stack PSP limit
 *
 */
__attribute__ ((always_inline))	static	inline	uintptr_t	core_getPSPLIM_S(void) {
	uintptr_t	valPSPLim;

	__asm volatile (
	"mrs		%0,psplim"
	: "=r" (valPSPLim)
	);

	return (valPSPLim);
}

/*
 * \brief core_getPSPLIM_NS
 *
 * - Get the PSP Limit
 *
 * \param[in]	-
 * \return		PSPLim	The thread stack PSP limit
 *
 */
__attribute__ ((always_inline))	static	inline	uintptr_t	core_getPSPLIM_NS(void) {
	uintptr_t	valPSPLim;

	__asm volatile (
	"mrs		%0,psplim_ns"
	: "=r" (valPSPLim)
	);

	return (valPSPLim);
}

/*
 * \brief core_setPSPLIM_S
 *
 * - Set the PSP stack
 *
 * \param[in]	stackPSP	The thread stack PSP
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	core_setPSPLIM_S(uintptr_t valPSPLim) {

	__asm volatile (
	"msr		psplim,%0"
	:
	: "r" (valPSPLim)
	);
}

/*
 * \brief core_setPSPLIM_NS
 *
 * - Set the PSP stack
 *
 * \param[in]	stackPSP	The thread stack PSP
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	core_setPSPLIM_NS(uintptr_t valPSPLim) {

	__asm volatile (
	"msr		psplim_ns,%0"
	:
	: "r" (valPSPLim)
	);
}

/*
 * \brief core_getMSPLIM_S
 *
 * - Get the MSP Limit
 *
 * \param[in]	-
 * \return		MSPLim	The thread stack MSP limit
 *
 */
__attribute__ ((always_inline))	static	inline	uintptr_t	core_getMSPLIM_S(void) {
	uintptr_t	valMSPLim;

	__asm volatile (
	"mrs		%0,msplim"
	: "=r" (valMSPLim)
	);

	return (valMSPLim);
}

/*
 * \brief core_getMSPLIM_NS
 *
 * - Get the MSP Limit
 *
 * \param[in]	-
 * \return		MSPLim	The thread stack MSP limit
 *
 */
__attribute__ ((always_inline))	static	inline	uintptr_t	core_getMSPLIM_NS(void) {
	uintptr_t	valMSPLim;

	__asm volatile (
	"mrs		%0,msplim_ns"
	: "=r" (valMSPLim)
	);

	return (valMSPLim);
}

/*
 * \brief core_setMSPLIM_S
 *
 * - Set the MSP stack
 *
 * \param[in]	stackMSP	The thread stack MSP
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	core_setMSPLIM_S(uintptr_t valMSPLim) {

	__asm volatile (
	"msr		msplim,%0"
	:
	: "r" (valMSPLim)
	);
}

/*
 * \brief core_setMSPLIM_NS
 *
 * - Set the MSP stack
 *
 * \param[in]	stackMSP	The thread stack MSP
 *
 * \note This function does not return a value (None).
 *
 */
__attribute__ ((always_inline))	static	inline	void	core_setMSPLIM_NS(uintptr_t valMSPLim) {

	__asm volatile (
	"msr		msplim_ns,%0"
	:
	: "r" (valMSPLim)
	);
}

/*
 * \brief core_getLR
 *
 * - Get the LR register
 *
 * \param[in]	-
 * \return		LR		The LR register
 *
 */
__attribute__ ((always_inline))	static	inline	uintptr_t	core_getLR(void) {
	uintptr_t	valLR;

	__asm volatile (
	"mov		%0,LR"
	: "=r" (valLR)
	);

	return (valLR);
}

/*
 * \brief core_getIPSR_S
 *
 * - Get the IPSR register
 *
 * \param[in]	-
 * \return		IPSR		The IPSR register
 *
 */
__attribute__ ((always_inline))	static	inline	uint32_t	core_getIPSR_S(void) {
	uint32_t	valIPSR;

	__asm volatile (
	"mrs		%0,ipsr"
	: "=r" (valIPSR)
	);

	return (valIPSR);
}

/*
 * \brief core_getIPSR_S
 *
 * - Get the IPSR register
 *
 * \param[in]	-
 * \return		IPSR		The IPSR register
 *
 */
__attribute__ ((always_inline))	static	inline	uint32_t	core_getIPSR_NS(void) {
	uint32_t	valIPSR;

	__asm volatile (
	"mrs		%0,ipsr_ns"
	: "=r" (valIPSR)
	);

	return (valIPSR);
}
