#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# backprop.
# =========
#
# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
#
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
#			python3 -m pip install numpy matplotlib
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

import	io
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
#
# The functions of the mlpn library (mlpn.c), clamps included, so that a
# network is trained with the function the target runs: the name written
# into network.c_inc is the name used here. Each entry is f(z) and f'(z);
# KMLPN_SMAX is not elementwise and has no f'(z), see mlp_activationDelta

def mlp_tanh(x):
	return (np.tanh(x))

def mlp_dtanh(x):
	return (1.0 - np.tanh(x) ** 2)

# KMLPN_TAN1, Lambert's continued fraction, clamped outside [-3, 3]
# a = p (s^3 + 378 s^2 + 17325 s + 135135), b = 28 s^3 + 3150 s^2 + 62370 s + 135135, s = p^2

def mlp_tan1(x):
	s = x * x
	a = ((((s + 378.0) * s) + 17325.0) * s + 135135.0) * x
	b = ((((28.0 * s) + 3150.0) * s) + 62370.0) * s + 135135.0
	return (np.where(x < -3.0, -1.0, np.where(x > 3.0, 1.0, a / b)))

def mlp_dtan1(x):
	s  = x * x
	a  = ((((s + 378.0) * s) + 17325.0) * s + 135135.0) * x
	b  = ((((28.0 * s) + 3150.0) * s) + 62370.0) * s + 135135.0
	da = ((((s + 378.0) * s) + 17325.0) * s + 135135.0) + (2.0 * s * ((((3.0 * s) + 756.0) * s) + 17325.0))
	db = 2.0 * x * ((((84.0 * s) + 6300.0) * s) + 62370.0)
	return (np.where(np.abs(x) > 3.0, 0.0, ((da * b) - (a * db)) / (b * b)))

# KMLPN_TAN2, the Pade ratio p (27 + p^2) / (27 + 9 p^2), clamped outside ]-3, 3[
# Its derivative (p^2 - 9)^2 / (9 (p^2 + 3)^2) is 1 at 0 and 0 at +/-3, where it meets the clamp

def mlp_tan2(x):
	x2 = x * x
	return (np.where(x <= -3.0, -1.0, np.where(x >= 3.0, 1.0, (x * (27.0 + x2)) / (27.0 + (9.0 * x2)))))

def mlp_dtan2(x):
	x2 = x * x
	return (np.where(np.abs(x) >= 3.0, 0.0, ((x2 - 9.0) ** 2) / (9.0 * ((x2 + 3.0) ** 2))))

# KMLPN_TAN3, a hard clamp to [-1, 1]

def mlp_tan3(x):
	return (np.clip(x, -1.0, 1.0))

def mlp_dtan3(x):
	return (np.where(np.abs(x) >= 1.0, 0.0, 1.0))

# KMLPN_RELU and KMLPN_LINE

def mlp_relu(x):
	return (np.where(x <= 0.0, 0.0, x))

def mlp_drelu(x):
	return (np.where(x <= 0.0, 0.0, 1.0))

def mlp_line(x):
	return (x)

def mlp_dline(x):
	return (np.ones_like(x))

# KMLPN_SMAX, with the max subtracted as mlpn.c does

def mlp_softmax(x):
	x_shift = x - np.max(x, axis = 0, keepdims = True)
	exp_x = np.exp(x_shift)
	return (exp_x / np.sum(exp_x, axis = 0, keepdims = True))

KACTIVATIONS = {
	"KMLPN_TAN0": (mlp_tanh,	mlp_dtanh),
	"KMLPN_TAN1": (mlp_tan1,	mlp_dtan1),
	"KMLPN_TAN2": (mlp_tan2,	mlp_dtan2),
	"KMLPN_TAN3": (mlp_tan3,	mlp_dtan3),
	"KMLPN_RELU": (mlp_relu,	mlp_drelu),
	"KMLPN_LINE": (mlp_line,	mlp_dline),
	"KMLPN_SMAX": (mlp_softmax,	None)
}

def mlp_checkConfig():
	for name in (config.KNON_LINEAR, config.KNON_LINEAR_OUT):
		if name not in KACTIVATIONS:
			raise SystemExit(f"config.py: unknown non-linear function {name}; valid: {', '.join(KACTIVATIONS)}")

def mlp_layerFunction(i, nbLayers):
	return (config.KNON_LINEAR_OUT if i == (nbLayers - 1) else config.KNON_LINEAR)

def mlp_activation(name, z):
	return (KACTIVATIONS[name][0](z))

# From dE/d(output) to dE/d(potential)

def mlp_activationDelta(name, potential, output, gradient):
	if name == "KMLPN_SMAX":
		# J_softmax = diag(s) - s s^T, so for one sample
		# delta     = s * (gradient - sum(s * gradient))
		projection = np.sum(output * gradient, axis = 0, keepdims = True)
		return (output * (gradient - projection))
	return (gradient * KACTIVATIONS[name][1](potential))

# Compute the forward neural network
# ----------------------------------

def mlp_forward(x, weights):
	outputs	   = [x]
	potentials = []

	for i, w in enumerate(weights):
		a = np.vstack([outputs[-1], np.ones((1, x.shape[1]))])
		z = np.dot(w, a)
		potentials.append(z)
		outputs.append(mlp_activation(mlp_layerFunction(i, len(weights)), z))
	return (outputs, potentials)

# Compute the back-propagation neural network
# -------------------------------------------
#
# Quadratic error E = 0.5 sum (output - y)^2, so dE/d(output) = output - y

def mlp_backprop(weights, outputs, potentials, y, gain, momentum, previousDeltas):

	# For the last layer
	nbLayers	  = len(weights)
	gradients	  = [None] * nbLayers
	deltas		  = [np.zeros_like(w) for w in weights]
	gradients[-1] = mlp_activationDelta(mlp_layerFunction(nbLayers - 1, nbLayers), potentials[-1], outputs[-1], outputs[-1] - y)

	# From the last layer-1 to the first one
	for i in reversed(range(nbLayers - 1)):
		W			 = weights[i + 1][:, :-1]
		gradients[i] = mlp_activationDelta(mlp_layerFunction(i, nbLayers), potentials[i], outputs[i + 1], np.dot(W.T, gradients[i + 1]))

	for i in range(nbLayers):
		a			= np.vstack([outputs[i], np.ones((1, outputs[i].shape[1]))])
		dW			= (-gain * np.dot(gradients[i], a.T)) + (momentum * previousDeltas[i])
		deltas[i]	= dW
		weights[i] += dW
	return (weights, deltas)

# Export the C model for the mlpn library
# ---------------------------------------

# Written in the repository's typography (CONTRIBUTING.md): no tabs, 4-column
# stops, upper-case F suffixes and trailing commas, so that a retrained network
# differs from the committed one by its weights only

def mlp_exportNetwork(weights, layers, filename = "network.c_inc"):
	f = io.StringIO()

	# mlpn descriptions
	f.write("// MLPN description\n")
	f.write("// ----------------\n\n")

	for index, w in enumerate(weights, 1):
		nb_out, nb_in = w.shape

		# Layer descriptions
		f.write(f"// Layer {index}\n\n")

		f.write(f"#define\tKMLPN_L{index}_NB_IN\t{nb_in}\n")
		f.write(f"#define\tKMLPN_L{index}_NB_OUT\t{nb_out}\n")

		if index == 1:
			f.write(f"\n[[gnu::aligned(16)]]\nstatic\t\t\tfloat32_t\tvInput_L1_f[KMLPN_L1_NB_IN];\n")
		f.write(f"\n[[gnu::aligned(16)]]\nstatic\t\t\tfloat32_t\tvActivation_L{index}_f[KMLPN_L{index}_NB_OUT];\n")
		f.write(f"\n[[gnu::aligned(16)]]\nstatic\t\t\tfloat32_t\tvOutput_L{index}_f[KMLPN_L{index}_NB_OUT + 1];\n")
		f.write(f"\n[[gnu::aligned(16)]]\nstatic\tconst\tfloat32_t\tvWeight_L{index}_f[KMLPN_L{index}_NB_OUT][KMLPN_L{index}_NB_IN] = {{\n")
		for row in w:
			values = ', '.join(f"{v:.6f}f" for v in row)
			f.write(f"\t\t\t\t\t\t\t\t{{ {values} }},\n")
		f.write("\t\t\t\t\t\t\t};\n\n")

		# Layer structure
		f.write(f"static\tmlpnLayer_t\taLayer_L{index} = {{\n")
		if index == len(weights):
			f.write(f"\t\t\t\t\t\t\t{config.KNON_LINEAR_OUT},\n")
		else:
			f.write(f"\t\t\t\t\t\t\t{config.KNON_LINEAR},\n")
		f.write(f"\t\t\t\t\t\t\tKMLPN_L{index}_NB_IN,\n")
		f.write(f"\t\t\t\t\t\t\tKMLPN_L{index}_NB_OUT,\n")
		if index == 1:
			f.write(f"\t\t\t\t\t\t\t&vInput_L1_f[0],\n")
		else:
			f.write(f"\t\t\t\t\t\t\t&vOutput_L{index-1}_f[0],\n")
		f.write(f"\t\t\t\t\t\t\t&vActivation_L{index}_f[0],\n")
		f.write(f"\t\t\t\t\t\t\t&vOutput_L{index}_f[0],\n")
		f.write(f"\t\t\t\t\t\t\t&vWeight_L{index}_f[0][0]\n")
		f.write("\t\t\t\t\t\t};\n\n")

	# Network structure
	f.write("// The full network\n\n")

	f.write(f"#define\tKMLPN_NB_LAYERS\t{len(weights)}\n\n")

	f.write("static\tconst\tmlpnNetwork_t\taNetwork = {\n")
	f.write("\t\t\t\t\t\t\t\t\tKMLPN_NB_LAYERS,\n")
	for index in range(1, len(weights) + 1):
		f.write(f"\t\t\t\t\t\t\t\t\t&aLayer_L{index},\n")
	for index in range(len(weights), KMLPN_NB_MAX_LAYERS):
		f.write("\t\t\t\t\t\t\t\t\tnullptr,\n")
	f.write("\t\t\t\t\t\t\t\t};\n")

	with open(filename, "w") as out:
		out.write(f.getvalue().expandtabs(4))

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
	mlp_checkConfig()
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

	# Export the network structure for the uKOS-X mlpn library
	mlp_exportNetwork(weights, config.KLAYERS)
	mlp_validation(weights, X)

# Main entry point
if __name__ == "__main__":
	main()
