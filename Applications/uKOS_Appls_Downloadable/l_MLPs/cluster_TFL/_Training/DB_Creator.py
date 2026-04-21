#!/usr/bin/env python
# -*- coding: utf-8 -*-

# DB_Creator.
# ===========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi     The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Generate 2 database files (for learning and for validation).
# 			Display the 2 dataset
#
#			The databases:
#			Class 1:  x < -0.1 and y >  0.1
#			Class 2:  x >  0.1 and y >  0.1
#			Class 3:  x < -0.1 and y < -0.1
#			Class 4:  ((-0.1 < x < 0.1) or (-0.1 < y < 0.1))
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

KNB_CLASSES				= 5								# Number of classes
KNB_SAMPLES				= 5000							# Number of samples
KNB_SAMPLES_PER_CLASS	= (KNB_SAMPLES // KNB_CLASSES)	# Number of samples per classe
KABS_MAX_FUNCTION		= 1								# Max of the function
KABS_MAX_OUTPUT			= 0.98							# Abs max of the expected output
KGOOD					= KABS_MAX_OUTPUT				# Max value for "good" answers
KBAD					= 0.00							# Max value for "bad" answers

# Return an x-Y random value
# --------------------------

def generate_randomValues():
	return ((np.random.rand(2) - 0.5) * 2 * KABS_MAX_FUNCTION)

# Generate the data set
# ---------------------

def generate_dataSet(fd, ax, isLearning = True):
	class_counts = [0] * 5
	markers = ['ro', 'go', 'bo', 'yo', 'm.'] if isLearning else ['r+', 'g+', 'b+', 'y+', 'm+']
	ax.set_title("Learning" if isLearning else "Validation")
	ax.set_aspect("equal")
	ax.grid(True)

	while any(count < KNB_SAMPLES_PER_CLASS for count in class_counts):
		x, y = generate_randomValues()
		scaled_x, scaled_y = x / KABS_MAX_FUNCTION, y / KABS_MAX_FUNCTION
		output = [KBAD] * 5
		marker = None

		if x < -0.1 and y > 0.1 and class_counts[0] < KNB_SAMPLES_PER_CLASS:
			output[0] = KGOOD
			class_counts[0] += 1
			marker = markers[0]
		elif x > 0.1 and y > 0.1 and class_counts[1] < KNB_SAMPLES_PER_CLASS:
			output[1] = KGOOD
			class_counts[1] += 1
			marker = markers[1]
		elif x < -0.1 and y < -0.1 and class_counts[2] < KNB_SAMPLES_PER_CLASS:
			output[2] = KGOOD
			class_counts[2] += 1
			marker = markers[2]
		elif x > 0.1 and y < -0.1 and class_counts[3] < KNB_SAMPLES_PER_CLASS:
			output[3] = KGOOD
			class_counts[3] += 1
			marker = markers[3]
		elif ((-0.1 < x < 0.1) or (-0.1 < y < 0.1)) and class_counts[4] < KNB_SAMPLES_PER_CLASS:
			output[4] = KGOOD
			class_counts[4] += 1
			marker = markers[4]

		if marker:
			ax.plot(scaled_x, scaled_y, marker)
			fd.write(f"{scaled_x:.6f}\t{scaled_y:.6f}\t" + "\t".join(f"{v:.2f}" for v in output) + "\n")

# Main
# ----

def main():
	fig, (ax1, ax2) = plt.subplots(1, 2, figsize = (10, 5))

	# Open the DB_L_file & DB_V_file database files
	# Generate the dataset DB_L_file file
	# Generate the dataset DB_V_file file
	with open("DB_L_file.txt", "w") as fd_l, open("DB_V_file.txt", "w") as fd_v:
		generate_dataSet(fd_l, ax1, isLearning = True)
		generate_dataSet(fd_v, ax2, isLearning = False)

	plt.tight_layout()
	plt.show()

# Main entry point
if __name__ == "__main__":
	main()
