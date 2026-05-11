#!/usr/bin/env python
# -*- coding: utf-8 -*-

# mlp_model.
# ==========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
#
# Project:	uKOS-X
# Goal:		Generate the TensorFlow Lite C model
#			for uKOS system.
#			We use the Sysquake database for the training.
#
#			Necessary packages:
#			python3 -m pip install numpy tensorflow pillow
#
#			python3 mlp_model.py --model_file mlp_model.tflite --mode val
#			python3 mlp_model.py --model_file mlp_model.tflite --mode full
#			xxd -i mlp_model.tflite > mlp_model.c_inc
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

import	argparse
import	numpy as np
import	tensorflow as tf
import	os
import	logging
from	tensorflow import keras
from	tensorflow.keras import layers

# 0 = all logs, 1 = info, 2 = warning, 3 = error only
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '3'
logging.getLogger('absl').setLevel(logging.ERROR)

# Load the learning dataset
# -------------------------

def load_data(file_path):
	try:

		# Use genfromtxt (more flexible than loadtxt)
		print(f"Read the file : {file_path}")
		data = np.genfromtxt(file_path, delimiter = '\t', dtype = np.float32)
		data = np.atleast_2d(data)

		# Remove invalid rows containing NaN or Inf
		data = data[~np.isnan(data).any(axis = 1)]
		data = data[~np.isinf(data).any(axis = 1)]

		print("Data read from the file :")
		print(data)

		if data.shape[1] != 5:
			raise ValueError("The file needs exactly 4 columns (x1, x2, y1, y2, y3) per line.")

		# Get the inputs (X) and the output (Y)
		# (x1, x2) are the inputs
		# (y1, y3) are the output
		X = data[:, :2]
		Y = data[:, 2:]
		return X, Y

	except Exception as e:
		print(f"Error during the file reading : {e}")
		return None, None

# Build the model
# ---------------

def build_model():
	model = tf.keras.Sequential([
		tf.keras.layers.InputLayer(shape = (2,), dtype = tf.float32),											# Layer 1,  2 - 52
		tf.keras.layers.Dense(52, activation = 'tanh', kernel_regularizer = tf.keras.regularizers.l2(1e-4)),	# Layer 2, 52 - 73
		tf.keras.layers.Dense(73, activation = 'tanh', kernel_regularizer = tf.keras.regularizers.l2(1e-4)),	# Layer 3, 73 - 3
		tf.keras.layers.Dense(3,  activation = 'softmax')														# Layer 4, 3
	])

	# Compile the model
	model.compile(
		optimizer = tf.keras.optimizers.Adam(learning_rate = 1e-3),
		loss = 'categorical_crossentropy',
		metrics = ['accuracy']
	)
	return model

# Main
# ----

def main():

	# Set up command-line arguments using argparse
	parser = argparse.ArgumentParser(description = 'Train and test a TensorFlow model.')
	parser.add_argument('--model_file', type = str, help = 'Path to the TFLite model file', required = True)
	args = parser.parse_args()

	# Load the learning dataset
	X, Y = load_data('DB_L_file.txt')

	if X is None or Y is None:
		print("Data cannot be loaded!")
		return

	# Shuffle the dataset
	indices = np.arange(X.shape[0])
	np.random.shuffle(indices)
	X = X[indices]
	Y = Y[indices]

	# Build the model
	model = build_model()
	model.fit(X, Y, epochs = 100, batch_size = 32, validation_split = 0.2)
	loss = model.evaluate(X, Y)
	print(f'Loss of the model : {loss}')

	# Test the model with TensorFlow
	output = model(np.array([[0.912431, 0.719052], [-0.460302, -0.637331], [-0.626125, -0.250060]], dtype = np.float32))
	print("Output TF", output)

	# Convert the model to TFLite format
	model.save('mlp_model.keras')
	converter = tf.lite.TFLiteConverter.from_keras_model(model)
	tflite_model = converter.convert()
	with open('mlp_model.tflite', 'wb') as f:
		f.write(tflite_model)

	# Use TensorFlow Lite Interpreter to test the TFLite model
	# Use the argument passed to the command line
	interpreter = tf.lite.Interpreter(model_path = args.model_file)
	interpreter.allocate_tensors()
	input_details  = interpreter.get_input_details()
	output_details = interpreter.get_output_details()

	for input_data in [[0.912431, 0.719052], [-0.460302, -0.637331], [-0.626125, -0.250060]]:
		interpreter.set_tensor(input_details[0]['index'], np.array([input_data], dtype = np.float32))
		interpreter.invoke()
		output = interpreter.get_tensor(output_details[0]['index'])
		print("Output TFLite", output)

# Main entry point
if __name__ == "__main__":
	main()
