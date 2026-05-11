#!/usr/bin/env python
# -*- coding: utf-8 -*-

# DB_Creator.
# ===========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi     The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Generate 2 database files (for learning and for validation).
# 			Display the 2 dataset
#
#			The databases:
#			Class 1:  150 < data < 600
#			Class 2a: data > (600 + 4 * KCLASS_MARGIN)
#			Class 2b: data < (150 - KCLASS_MARGIN)
#
#			Necessary packages:
#			python3 -m pip install numpy pyserial matplotlib
#
#			python3 DB_Creator.py
#
#   (c) 2025-2026, Edo. Franzi
#   --------------------------
#                                              __ ______  _____
#   Edo. Franzi                         __  __/ //_/ __ \/ ___/
#   5-Route de Cheseaux                / / / / ,< / / / /\__ \
#   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
#                                     \__,_/_/ |_\____//____/
#   edo.franzi@ukos.ch
#
#   Description: Lightweight, real-time multitasking operating
#   system for embedded microcontroller and DSP-based systems.
#
#   Permission is hereby granted, free of charge, to any person
#   obtaining a copy of this software and associated documentation
#   files (the "Software"), to deal in the Software without restriction,
#   including without limitation the rights to use, copy, modify,
#   merge, publish, distribute, sublicense, and/or sell copies of the
#   Software, and to permit persons to whom the Software is furnished
#   to do so, subject to the following conditions:
#
#   The above copyright notice and this permission notice shall be
#   included in all copies or substantial portions of the Software.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
#   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
#   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
#   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#   SOFTWARE.
#
#------------------------------------------------------------------------

# Necessary packages

import	numpy as np
import	matplotlib.pyplot as plt

KNB_SAMPLES_C1			= 1000								# Number of samples C1 (ring)
KNB_SAMPLES_C2a	 		= 1000								# Number of samples C2a (outer)
KNB_SAMPLES_C2b			= 1000								# Number of samples C2b (inner)
KNB_SAMPLES_C3			= 1000								# Number of samples C3 (square)
KABS_MAX_FUNCTION		= 40								# Max of the function (+/- 40 in x-y)
KRING_LIMITS_MIN		= (0.4 * KABS_MAX_FUNCTION)**2		# Min value for the ring
KRING_LIMITS_MAX		= (0.7 * KABS_MAX_FUNCTION)**2		# Max value for the ring
KSQUARE_LIMITS			= (0.6 * KABS_MAX_FUNCTION)			# Corner size (top-right)
KABS_MAX_OUTPUT			= 0.98								# Abs max of the expected output
KGOOD					= KABS_MAX_OUTPUT					# Max value for "good" answers
KBAD					= 0.00								# Max value for "bad" answers

# Return an X-Y random value
# --------------------------

def generate_randomValues():
	return ((np.random.rand(2) - 0.5) * 2 * KABS_MAX_FUNCTION)

# Return the X-Y squared norm
# ---------------------------

def norm_squared(x, y):
	return ((x * x) + (y * y))

# Normalize one point
# -------------------

def normalize_point(x, y):
	return (x / KABS_MAX_FUNCTION, y / KABS_MAX_FUNCTION)

# Generate the data set
# ---------------------

def generate_dataSet(fd, ax, colors, title):
	ax.set_title(title)
	ax.set_aspect("equal")
	ax.grid(True)

	# Display normalized coordinates
	ax.set_xlim(-1, 1)
	ax.set_ylim(-1, 1)
	ax.set_xticks(np.linspace(-1, 1, 5))
	ax.set_yticks(np.linspace(-1, 1, 5))

	# Class 1: KRING_LIMITS_MIN < data < KRING_LIMITS_MAX (ring)
	count = 0
	while count < KNB_SAMPLES_C1:
		x, y = generate_randomValues()
		r2 = norm_squared(x, y)
		if (KRING_LIMITS_MIN < r2 < KRING_LIMITS_MAX):
			xn, yn = normalize_point(x, y)
			ax.plot(xn, yn, colors[0])
			fd.write(f"{xn / KABS_MAX_FUNCTION:.6f}\t{yn / KABS_MAX_FUNCTION:.6f}\t{KGOOD:.2f}\t{KBAD:.2f}\t{KBAD:.2f}\n")
			count += 1

	# Class 2a: data > KRING_LIMITS_MAX (outer) & exclude the square corner Top-Right
	count = 0
	while count < KNB_SAMPLES_C2a:
		x, y = generate_randomValues()
		r2 = norm_squared(x, y)

		in_outer = (r2 > KRING_LIMITS_MAX)
		in_top_right_corner = (x > KSQUARE_LIMITS) and (y > KSQUARE_LIMITS)

		if in_outer and (not in_top_right_corner):
			xn, yn = normalize_point(x, y)
			ax.plot(xn, yn, colors[1])
			fd.write(f"{xn / KABS_MAX_FUNCTION:.6f}\t{yn / KABS_MAX_FUNCTION:.6f}\t{KBAD:.2f}\t{KGOOD:.2f}\t{KBAD:.2f}\n")
			count += 1

	# Class 2b: data < KRING_LIMITS_MIN (inner)
	count = 0
	while count < KNB_SAMPLES_C2b:
		x, y = generate_randomValues()
		r2 = norm_squared(x, y)
		if (r2 < KRING_LIMITS_MIN):
			xn, yn = normalize_point(x, y)
			ax.plot(xn, yn, colors[2])
			fd.write(f"{xn / KABS_MAX_FUNCTION:.6f}\t{yn / KABS_MAX_FUNCTION:.6f}\t{KBAD:.2f}\t{KGOOD:.2f}\t{KBAD:.2f}\n")
			count += 1

	# Class 3: x > KSQUARE_LIMITS & y > KSQUARE_LIMITS
	count = 0
	while count < KNB_SAMPLES_C3:
		x, y = generate_randomValues()
		in_top_right_corner = (x > KSQUARE_LIMITS) and (y > KSQUARE_LIMITS)
		if in_top_right_corner:
			xn, yn = normalize_point(x, y)
			ax.plot(xn, yn, colors[3])
			fd.write(f"{xn / KABS_MAX_FUNCTION:.6f}\t{yn / KABS_MAX_FUNCTION:.6f}\t{KBAD:.2f}\t{KBAD:.2f}\t{KGOOD:.2f}\n")
			count += 1

# Main
# ----

def main():
	fig, (ax1, ax2) = plt.subplots(1, 2, figsize = (10, 5))

	# Open the DB_L_file & DB_V_file database files
	# Generate the dataset DB_L_file file
	# Generate the dataset DB_V_file file
	with open("DB_L_file.txt", "w") as fd_l, open("DB_V_file.txt", "w") as fd_v:

		generate_dataSet(fd_l, ax1, colors = ["r+", "go", "g.", "bx"], title = "Learning data")
		generate_dataSet(fd_v, ax2, colors = ["ro", "gx", "g+", "b."], title = "Validation data")

	plt.tight_layout()
	plt.show()

# Main entry point
if __name__ == "__main__":
	main()
