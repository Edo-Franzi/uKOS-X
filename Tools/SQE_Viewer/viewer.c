/*
; viewer.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		viewer interface for Sysquake.
;
;			To build the library, open the terminal
;			For OSX
;			gcc -bundle -undefined suppress -Wl,-flat_namespace -o viewer.so ftdiSPI.c viewer.c -L/opt/uKOS/Packages/D2XX -lftd2xx
;
;			For ubuntu
;			gcc -shared -o viewer.so ftdiSPI.c viewer.c -L/opt/uKOS/Packages/D2XX -lftd2xx
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

#include	"ftdiSPI.h"
#include	"LME_Ext.h"
#include	"ftd2xx.h"
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>

static	FT_HANDLE	vFtHandle;
static	uint8_t		*vImage;

/*
 * \brief Get the number of FTDI devices
 *
 * Call example in C:
 *
 * \code{.c}
 * lme_err    status;
 * lme_ref    lme;
 * lme_int    nargin;
 * lme_int    nargout;
 *
 *    status = viewer_getNbDevices(lme_ref lme, lme_int nargin, lme_int nargout);
 * \endcode
 *
 * \param[in]	lme					LME reference
 * \param[in]	nargin				Nb of input arguments
 * \param[in]	nargout				Nb of output arguments
 * \return		k_lme_err_success	OK
 * \return		k_lme_err_failure	Problem
 *
 */
static lme_err viewer_getNbDevices(lme_ref lme, lme_int nargin, lme_int nargout) {
	lme_float64		*reO;
	uint32_t		nbDevices;

	if (LMECB_PushMatrix(1, 1, &reO, 0) == k_lme_err_failure) { LMECB_DbgWriteStr("sque problem!");						 return (k_lme_err_failure); }
	if (ftdiSPI_getNbDevices(&nbDevices) == KFTDIGEERR)		  { LMECB_DbgWriteStr("ftdi problem! ftdiSPI_getNbDevices"); return (k_lme_err_failure); }

	reO[0] = (lme_float64)nbDevices;
	return (k_lme_err_success);
}

/*
 * \brief Get the device Id
 *
 * Call example in C:
 *
 * \code{.c}
 * lme_err    status;
 * lme_ref    lme;
 * lme_int    nargin;
 * lme_int    nargout;
 *
 *    status = viewer_getDeviceId(lme_ref lme, lme_int nargin, lme_int nargout);
 * \endcode
 *
 * \param[in]	lme					LME reference
 * \param[in]	nargin				Nb of input arguments
 * \param[in]	nargout				Nb of output arguments
 * \return		k_lme_err_success	OK
 * \return		k_lme_err_failure	Problem
 *
 */
static lme_err viewer_getDeviceId(lme_ref lme, lme_int nargin, lme_int nargout) {
	lme_float64		*reI, *imI;
	lme_string8		string;
	lme_int			m, n;
	char_t			deviceId[64];
	uint32_t		i;
	uintptr_t		deviceNb;

	if (LMECB_GetMatrix(1, &m, &n, &reI, &imI) == k_lme_err_failure)		   { LMECB_DbgWriteStr("sque problem!"); return (k_lme_err_failure); }
	deviceNb = (uintptr_t)reI[0];

	if (ftdiSPI_getDeviceId(deviceNb, &deviceId[0]) == KFTDIGEERR)			   { LMECB_DbgWriteStr("sque problem!"); return (k_lme_err_failure); }
	if (LMECB_StartPushString(strlen(deviceId), &string) == k_lme_err_failure) { LMECB_DbgWriteStr("sque problem!"); return (k_lme_err_failure); }

	for (i = 0; i < strlen(deviceId); i++) {
		string[i] = deviceId[i];
	}
	if (LMECB_EndPushString() == k_lme_err_failure)							   { LMECB_DbgWriteStr("sque problem!"); return (k_lme_err_failure); }

	return (k_lme_err_success);
}

/*
 * \brief Open the device
 *
 * Call example in C:
 *
 * \code{.c}
 * lme_err    status;
 * lme_ref    lme;
 * lme_int    nargin;
 * lme_int    nargout;
 *
 *    status = viewer_openDevice(lme_ref lme, lme_int nargin, lme_int nargout);
 * \endcode
 *
 * \param[in]	lme					LME reference
 * \param[in]	nargin				Nb of input arguments
 * \param[in]	nargout				Nb of output arguments
 * \return		k_lme_err_success	OK
 * \return		k_lme_err_failure	Problem
 *
 */
static lme_err viewer_openDevice(lme_ref lme, lme_int nargin, lme_int nargout) {
	lme_float64		*reI, *imI, *reO;
	lme_int			m, n;
	uintptr_t		deviceNb;

	if (LMECB_GetMatrix(1, &m, &n, &reI, &imI) == k_lme_err_failure) { LMECB_DbgWriteStr("sque problem!");					  return (k_lme_err_failure); }

	deviceNb = (uintptr_t)reI[0];
	if (ftdiSPI_openDevice(&vFtHandle, deviceNb) == KFTDIGEERR)		 { LMECB_DbgWriteStr("ftdi problem! ftdiSPI_openDevice"); return (k_lme_err_failure); }

	vImage = (uint8_t *)malloc(sizeof(uint8_t) * 2000 * 2000 * 2);
	if (vImage == nullptr)											 { LMECB_DbgWriteStr("malloc problem!");				  return (k_lme_err_failure); }

	return (k_lme_err_success);
}

/*
 * \brief Close the device
 *
 * Call example in C:
 *
 * \code{.c}
 * lme_err    status;
 * lme_ref    lme;
 * lme_int    nargin;
 * lme_int    nargout;
 *
 *    status = viewer_closeDevice(lme_ref lme, lme_int nargin, lme_int nargout);
 * \endcode
 *
 * \param[in]	lme					LME reference
 * \param[in]	nargin				Nb of input arguments
 * \param[in]	nargout				Nb of output arguments
 * \return		k_lme_err_success	OK
 * \return		k_lme_err_failure	Problem
 *
 */
static lme_err viewer_closeDevice(lme_ref lme, lme_int nargin, lme_int nargout) {

	free(vImage);
	if (ftdiSPI_closeDevice(vFtHandle) == KFTDIGEERR) { LMECB_DbgWriteStr("ftdi problem! ftdiSPI_closeDevice"); return (k_lme_err_failure); }

	return (k_lme_err_success);
}

/*
 * \brief Get the bitmap
 *
 * Call example in C:
 *
 * \code{.c}
 * lme_err    status;
 * lme_ref    lme;
 * lme_int    nargin;
 * lme_int    nargout;
 *
 *    status = viewer_getBitmap(lme_ref lme, lme_int nargin, lme_int nargout);
 * \endcode
 *
 * \param[in]	lme					LME reference
 * \param[in]	nargin				Nb of input arguments
 * \param[in]	nargout				Nb of output arguments
 * \return		k_lme_err_success	OK
 * \return		k_lme_err_failure	Problem
 *
 */
static lme_err viewer_getBitmap(lme_ref lme, lme_int nargin, lme_int nargout) {
	lme_float64		*reI, *imI, *reO_0, *reO_1;
	lme_int			m, n;
	uint8_t			*buffer_08, tmp;
	uint16_t		*buffer_10;
	uint32_t		i, nbRead, nbWrite, nbCols, nbRows, deep, inverse, swap, delay, modeBuffer;

	if (LMECB_GetMatrix(1, &m, &n, &reI, &imI) == k_lme_err_failure)   { LMECB_DbgWriteStr("sque problem!"); return (k_lme_err_failure); }
	m = reI[1]; n = reI[0];
	if (LMECB_PushMatrix(m, n, &reO_0, 0)== k_lme_err_failure)		   { LMECB_DbgWriteStr("sque problem!"); return (k_lme_err_failure); }
	if (LMECB_PushMatrix(1, 1, &reO_1, 0)== k_lme_err_failure)		   { LMECB_DbgWriteStr("sque problem!"); return (k_lme_err_failure); }

// Read the image
// Copy the image to the SQE buffer
//
// nbCols		- col
// nbRows		- row
// deep			- deep
// inverse		- natural / reverse
// swap			- swap
// delay		- delay in [us] between packs
// modeBuffer	- big / small transfer buffers

	nbCols		= (uint32_t)reI[0];
	nbRows		= (uint32_t)reI[1];
	deep		= (uint32_t)reI[2];
	inverse		= (uint32_t)reI[3];
	swap		= (uint32_t)reI[4];
	delay		= (uint32_t)reI[5];
	modeBuffer	= (uint32_t)reI[6];

	if (ftdiSPI_getData(vFtHandle, vImage, (nbCols * nbRows * deep), delay, modeBuffer) == KFTDIGEERR) { LMECB_DbgWriteStr("ftdi problem! ftdiSPI_getData"); return (k_lme_err_failure); }

// Image number (if any)

	buffer_08 = (uint8_t *)vImage;
	reO_1[0] = (lme_float64)((vImage[0]<<24) | (vImage[1]<<16) | (vImage[2]<<8) | (vImage[3]<<0));

// Swap the image MSB - LSB --> LSB - MSB

	if (swap == 0) {
		buffer_08 = (uint8_t *)vImage;
		for (i = 1; i < (nbCols * nbRows); i += 2) {
			tmp = buffer_08[i];
			buffer_08[i] = buffer_08[i - 1];
			buffer_08[i - 1] = tmp;
		}
	}

// Inverse the image

	buffer_08 = (uint8_t  *)vImage;
	buffer_10 = (uint16_t *)vImage;
	for (i = 0; i < (nbCols * nbRows); i++) {
		if (deep == 1) {
			if (inverse == 0) {
				reO_0[i] = (lme_float64)(*buffer_08++);
			}
			else {
				reO_0[i] = (lme_float64)(~*buffer_08++);
			}
		}
		else {
			if (inverse == 0) {
				reO_0[i] = (lme_float64)(*buffer_10++ & 0x3FF);
			}
			else {
				reO_0[i] = (lme_float64)(~*buffer_10++ & 0x3FF);
			}
		}
	}
	return (k_lme_err_success);
}

static lme_fn fn[] = {
	{ "viewer_getNbDevices", viewer_getNbDevices, 0, 0, 1, 1 },
	{ "viewer_getDeviceId",  viewer_getDeviceId,  1, 1, 0, 0 },
	{ "viewer_openDevice",   viewer_openDevice,   1, 1, 0, 0 },
	{ "viewer_closeDevice",  viewer_closeDevice,  0, 0, 0, 0 },
	{ "viewer_getBitmap",    viewer_getBitmap,    1, 1, 2, 2 }
};

lme_int InstallFn(lme_ref lme, lme_fn **fnarray) {

	LMECB_DbgWriteStr("Installing viewer extensions V14.0");
	*fnarray = fn;
	return (sizeof(fn) / sizeof(fn[0]));
}
