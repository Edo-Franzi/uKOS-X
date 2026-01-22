#!/usr/bin/env python
# -*- coding: utf-8 -*-

# backprop.
# =========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi     The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Back-propagation for multi-layers perceptrons
#
#			The databases ha to have this generic format
#			X1 X2 .. Xn Y1 Y2 .. Yn
#			With X the input vector & Y the expected vector
#
#			Necessary packages:
#			pip3 install numpy matplotlib
#
#			python3 backprop.py
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

import	config

KDISPLAY_SHIFT		= 50000
KMLPN_NB_MAX_LAYERS	= 5

# Load the data set for the training
# ----------------------------------

def	mlp_loadData():
	data = np.loadtxt("DB_L_file.txt")

	# Extract the X - Y vectors
	# X vector has to be normalized
	X = data[:, :config.KNB_INPUTS].T
	Y = data[:, -config.KNB_OUTPUTS:].T
	samples = X.shape[1]
	return (X, Y, samples)

# Non linear and derivative functions
# -----------------------------------

def mlp_tanh(x):
	return (np.tanh(x))

def mlp_dtanh(x):
	return (1.0 - np.tanh(x) ** 2)

# Compute the forward neural network
# ----------------------------------

def mlp_forward(x, weights):
	outputs	   = [x]
	potentials = []

	for w in weights:
		a = np.vstack([outputs[-1], np.ones((1, x.shape[1]))])
		z = np.dot(w, a)
		potentials.append(z)
		outputs.append(mlp_tanh(z))
	return (outputs, potentials)

# Compute the back-propagation neural network
# -------------------------------------------

def mlp_backprop(weights, outputs, potentials, y, gain, momentum, previousDeltas):

	# For the last layer
	gradients	  = [None] * len(weights)
	deltas		  = [np.zeros_like(w) for w in weights]
	delta		  = (outputs[-1] - y) * mlp_dtanh(potentials[-1])
	gradients[-1] = delta

	# From the last layer-1 to the first one
	for i in reversed(range(len(weights) - 1)):
		W			 = weights[i + 1][:, :-1]
		delta		 = np.dot(W.T, gradients[i + 1]) * mlp_dtanh(potentials[i])
		gradients[i] = delta

	for i in range(len(weights)):
		a			= np.vstack([outputs[i], np.ones((1, outputs[i].shape[1]))])
		dW			= (-gain * np.dot(gradients[i], a.T)) + (momentum * previousDeltas[i])
		deltas[i]	= dW
		weights[i] += dW
	return (weights, deltas)

# Export the C model for the mlpn library
# ---------------------------------------

def mlp_exportNetwork(weights, layers, filename = "network.c_inc"):
	with open(filename, "w") as f:

		# mlpn descriptions
		f.write("// MLPN description\n")
		f.write("// ----------------\n\n")

		for index, w in enumerate(weights, 1):
			nb_out, nb_in = w.shape

			# Layer descriptions
			f.write(f"// Layer {index}\n\n")

			f.write(f"#define\tKMLPN_L{index}_NB_IN\t{nb_in}\n")
			f.write(f"#define\tKMLPN_L{index}_NB_OUT\t{nb_out}\n\n")

			if index == 1:
				f.write(f"static\t\t\tfloat32_t\tvInput_L1[KMLPN_L1_NB_IN] __attribute__((aligned(16)));\n")
			f.write(f"static\t\t\tfloat32_t\tvActivation_L{index}[KMLPN_L{index}_NB_OUT] __attribute__((aligned(16)));\n")
			f.write(f"static\t\t\tfloat32_t\tvOutput_L{index}[KMLPN_L{index}_NB_OUT + 1] __attribute__((aligned(16)));\n")
			f.write(f"static\tconst\tfloat32_t\tvWeight_L{index}[KMLPN_L{index}_NB_OUT][KMLPN_L{index}_NB_IN] __attribute__((aligned(16))) = {{\n")
			for row in w:
				values = ', '.join(f"{v:.6f}f" for v in row)
				f.write(f"\t\t\t\t\t\t\t\t{{ {values} }},\n")
			f.write("\t\t\t\t\t\t\t};\n\n")

			# Layer structure
			f.write(f"static\tmlpnLayer_t\taLayer_L{index} = {{\n")
			f.write(f"\t\t\t\t\t\t\t{config.KNON_LINEAR},\n")
			f.write(f"\t\t\t\t\t\t\tKMLPN_L{index}_NB_IN,\n")
			f.write(f"\t\t\t\t\t\t\tKMLPN_L{index}_NB_OUT,\n")
			if index == 1:
				f.write(f"\t\t\t\t\t\t\t&vInput_L1[0],\n")
			else:
				f.write(f"\t\t\t\t\t\t\t&vOutput_L{index-1}[0],\n")
			f.write(f"\t\t\t\t\t\t\t&vActivation_L{index}[0],\n")
			f.write(f"\t\t\t\t\t\t\t&vOutput_L{index}[0],\n")
			f.write(f"\t\t\t\t\t\t\t&vWeight_L{index}[0][0]\n")
			f.write("\t\t\t\t\t\t};\n\n")

		# Network structure
		f.write("// The full network\n\n")

		f.write(f"#define\tKMLPN_NB_LAYERS\t{len(weights)}\n\n")

		f.write("static\tconst\tmlpnNetwork_t\taNetwork = {\n")
		f.write("\t\t\t\t\t\t\t\t\tKMLPN_NB_LAYERS,\n")
		for index in range(1, len(weights) + 1):
			f.write(f"\t\t\t\t\t\t\t\t\t&aLayer_L{index},\n")
		for index in range(len(weights), KMLPN_NB_MAX_LAYERS):
			if index < (KMLPN_NB_MAX_LAYERS - 1):
				f.write("\t\t\t\t\t\t\t\t\tNULL,\n")
			else:
				f.write("\t\t\t\t\t\t\t\t\tNULL\n")
		f.write("\t\t\t\t\t\t\t\t};\n")

# Some sample validation
# ----------------------

def	mlp_validation(weights, X):
	print("\nTest samples:")
	for sample in config.KVALIDATION:
		x	   = np.array(sample[:config.KNB_INPUTS]).reshape(-1, 1)
		y_true = np.array(sample[-config.KNB_OUTPUTS:]).reshape(-1, 1)

		outputs, _ = mlp_forward(x, weights)
		y_pred = outputs[-1]
		error  = 0.5 * np.mean((y_pred - y_true) ** 2)

		print(f"Input: {x.ravel()} | Target: {y_true.ravel()} → Pred: {y_pred.ravel()} | Err = {error:.6f}")

# Display the quadratic error
# ---------------------------

def displayError(fig, ax, shown_x, shown_y, epoch, error):
	shown_x.append(epoch)
	shown_y.append(error)
	x_visible = np.array(shown_x)
	y_visible = np.array(shown_y)

	# For displaying the data
	mask = x_visible > (epoch - KDISPLAY_SHIFT)
	x_visible = x_visible[mask]
	y_visible = y_visible[mask]

	ax.clear()
	ax.plot(x_visible, y_visible, label = "Quadratic Error")
	ax.set_xlabel("Epoch")
	ax.set_ylabel("Error")
	ax.set_title("Quadratic Error")
	ax.grid(True)
	ax.legend()
	ax.set_xlim(x_visible[0], x_visible[-1])

	y_min, y_max = float(np.min(y_visible)), float(np.max(y_visible))
	if abs(y_max - y_min) < 1e-6:
		y_min -= 0.01
		y_max += 0.01
	else:
		padding = 0.05 * (y_max - y_min)
		y_min -= padding
		y_max += padding

	ax.set_ylim(y_min, y_max)

	fig.canvas.draw()
	fig.canvas.flush_events()
	plt.pause(0.001)

# Main
# ----

def main():

	# Load the data set for the training
	# Initialise the weights to small values
	X, Y, samples = mlp_loadData()

	np.random.seed(0)
	weights = [np.random.randn(config.KLAYERS[i + 1], config.KLAYERS[i] + 1) * 0.5 for i in range(len(config.KLAYERS) - 1)]
	previousDeltas = [np.zeros_like(w) for w in weights]

	shown_x, shown_y = [], []
	plt.ion()
	fig, ax = plt.subplots()

	# Training loop
	for epoch in range(config.KEPOCHS):

		# Read a random sample (X _ Y)
		# Compute the forward network
		# Compute the error
		index = np.random.randint(samples)
		x = X[:, index:index + 1]
		y = Y[:, index:index + 1]
		outputs, potentials = mlp_forward(x, weights)
		y_prediction = outputs[-1]
		error = 0.5 * np.mean((y_prediction - y) ** 2)

		# Display the error every 500 batches
		if epoch % 500 == 0:
			displayError(fig, ax, shown_x, shown_y, epoch, error)

		# Print the Y demanded and the Y prediction
		# Back-propagation
		print(f"Epoch {epoch}: Err = {error:.6f} | "
			  f"y: [{', '.join(f'{v:.2f}' for v in y.ravel())}] "
			  f"-> pred: [{', '.join(f'{v:.2f}' for v in y_prediction.ravel())}]")

		weights, previousDeltas = mlp_backprop(weights, outputs , potentials, y, config.KGAIN, config.KMOMENTUM, previousDeltas)

	plt.ioff()
	plt.show()

	# Export the network structure for the uKOS-X mlp0 library
	mlp_exportNetwork(weights, config.KLAYERS)
	mlp_validation(weights, X)

# Main entry point
if __name__ == "__main__":
	main()
