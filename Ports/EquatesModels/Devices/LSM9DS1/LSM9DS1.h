/*
; LSM9DS1.
; ========

; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		ST LSM9DS1 iNEMO equates.
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

// Accelerometer/Gyroscope registers

#define	LSM9DS1_ACT_THS						0x04u							//
#define	LSM9DS1_ACT_DUR						0x05u							//
#define	LSM9DS1_INT_GEN_CFG_XL				0x06u							//
#define	LSM9DS1_INT_GEN_THS_X_XL			0x07u							//
#define	LSM9DS1_INT_GEN_THS_Y_XL			0x08u							//
#define	LSM9DS1_INT_GEN_THS_Z_XL			0x09u							//
#define	LSM9DS1_INT_GEN_DUR_XL				0x0Au							//
#define	LSM9DS1_REFERENCE_G					0x0Bu							//
#define	LSM9DS1_INT1_CTRL					0x0Cu							//
#define	LSM9DS1_INT2_CTRL					0x0Du							//
#define	LSM9DS1_WHO_AM_I					0x0Fu							//
#define	LSM9DS1_CTRL_REG1_G					0x10u							//
#define	LSM9DS1_CTRL_REG2_G					0x11u							//
#define	LSM9DS1_CTRL_REG3_G					0x12u							//
#define	LSM9DS1_ORIENT_CFG_G				0x13u							//
#define	LSM9DS1_INT_GEN_SRC_G				0x14u							//
#define	LSM9DS1_OUT_TEMP_L					0x15u							//
#define	LSM9DS1_OUT_TEMP_H					0x16u							//
#define	LSM9DS1_STATUS_REG1					0x17u							//
#define	LSM9DS1_OUT_X_L_G					0x18u							//
#define	LSM9DS1_OUT_X_H_G					0x19u							//
#define	LSM9DS1_OUT_Y_L_G					0x1Au							//
#define	LSM9DS1_OUT_Y_H_G					0x1Bu							//
#define	LSM9DS1_OUT_Z_L_G					0x1Cu							//
#define	LSM9DS1_OUT_Z_H_G					0x1Du							//
#define	LSM9DS1_CTRL_REG4_G					0x1Eu							//
#define	LSM9DS1_CTRL_REG5_XL				0x1Fu							//
#define	LSM9DS1_CTRL_REG6_XL				0x20u							//
#define	LSM9DS1_CTRL_REG7_XL				0x21u							//
#define	LSM9DS1_CTRL_REG8					0x22u							//
#define	LSM9DS1_CTRL_REG9					0x23u							//
#define	LSM9DS1_CTRL_REG10					0x24u							//
#define	LSM9DS1_INT_GEN_SRC_XL				0x26u							//
#define	LSM9DS1_STATUS_REG2					0x27u							//
#define	LSM9DS1_OUT_X_L_XL					0x28u							//
#define	LSM9DS1_OUT_X_H_XL					0x29u							//
#define	LSM9DS1_OUT_Y_L_XL					0x2Au							//
#define	LSM9DS1_OUT_Y_H_XL					0x2Bu							//
#define	LSM9DS1_OUT_Z_L_XL					0x2Cu							//
#define	LSM9DS1_OUT_Z_H_XL					0x2Du							//
#define	LSM9DS1_FIFO_CTRL					0x2Eu							//
#define	LSM9DS1_FIFO_SRC					0x2Fu							//
#define	LSM9DS1_INT_GEN_CFG_G				0x30u							//
#define	LSM9DS1_INT_GEN_THS_X_GL			0x31u							//
#define	LSM9DS1_INT_GEN_THS_X_GH			0x32u							//
#define	LSM9DS1_INT_GEN_THS_Y_GL			0x33u							//
#define	LSM9DS1_INT_GEN_THS_Y_GH			0x34u							//
#define	LSM9DS1_INT_GEN_THS_Z_GL			0x35u							//
#define	LSM9DS1_INT_GEN_THS_Z_GH			0x36u							//
#define	LSM9DS1_INT_GEN_DUR_G				0x37u							//

// Magnetometer registers

#define	LSM9DS1_OFFSET_X_REG_L_M			0x05u							//
#define	LSM9DS1_OFFSET_X_REG_H_M			0x06u							//
#define	LSM9DS1_OFFSET_Y_REG_L_M			0x07u							//
#define	LSM9DS1_OFFSET_Y_REG_H_M			0x08u							//
#define	LSM9DS1_OFFSET_Z_REG_L_M			0x09u							//
#define	LSM9DS1_OFFSET_Z_REG_H_M			0x0Au							//
#define	LSM9DS1_WHO_AM_I_M					0x0Fu							//
#define	LSM9DS1_CTRL_REG1_M					0x20u							//
#define	LSM9DS1_CTRL_REG2_M					0x21u							//
#define	LSM9DS1_CTRL_REG3_M					0x22u							//
#define	LSM9DS1_CTRL_REG4_M					0x23u							//
#define	LSM9DS1_CTRL_REG5_M					0x24u							//
#define	LSM9DS1_STATUS_REG_M				0x27u							//
#define	LSM9DS1_OUT_X_L_M					0x28u							//
#define	LSM9DS1_OUT_X_H_M					0x29u							//
#define	LSM9DS1_OUT_Y_L_M					0x2Au							//
#define	LSM9DS1_OUT_Y_H_M					0x2Bu							//
#define	LSM9DS1_OUT_Z_L_M					0x2Cu							//
#define	LSM9DS1_OUT_Z_H_M					0x2Du							//
#define	LSM9DS1_INT_CFG_M					0x30u							//
#define	LSM9DS1_INT_SRC_M					0x31u							//
#define	LSM9DS1_INT_THS_L_M					0x32u							//
#define	LSM9DS1_INT_THS_H_M					0x33u							//
