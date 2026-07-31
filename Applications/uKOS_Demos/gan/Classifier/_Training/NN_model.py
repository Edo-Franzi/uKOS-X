#!/usr/bin/env python
# -*- coding: utf-8 -*-

# NN_model.
# =========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2026-05-18
#
# Project:	uKOS-X
# Goal:		Generate the TensorFlow Lite C model for the uKOS system.
#			This application trains a GAN network to generate faces
#			from random vectors.
#
#			The database is downloaded from:
#			https://scikit-learn.org
#
#			A dedicated Python script downloads 1000 samples for training:
#			python DB_Creator.py
#
#			The GAN is composed of a Generator and a Discriminator.
#
#			Generator architecture (embedded-friendly CNN):
#			-----------------------------------------------
#
#			Input:
#				Random latent vector of 64 float32 values
#
#			Dense:
#				64 -> 4 x 4 x 96
#
#			Feature map expansion:
#
#				4x4x96
#					|
#					+-- Resize 8x8
#					+-- Conv2D(48)
#					+-- BatchNorm
#					+-- ReLU
#
#				8x8x48
#					|
#					+-- Resize 16x16
#					+-- Conv2D(24)
#					+-- BatchNorm
#					+-- ReLU
#
#				16x16x24
#					|
#					+-- Resize 32x32
#					+-- Conv2D(12)
#					+-- BatchNorm
#					+-- ReLU
#
#				32x32x12
#					|
#					+-- Resize 64x64
#					+-- Conv2D(8)
#					+-- BatchNorm
#					+-- ReLU
#
#				64x64x8
#					|
#					+-- Conv2D(8)
#					+-- BatchNorm
#					+-- ReLU
#
#				64x64x8
#					|
#					+-- Conv2D(1)
#					+-- tanh
#
#			Output:
#				64x64 grayscale image
#
#			Discriminator architecture:
#			---------------------------
#
#			Input:
#				64x64 grayscale image
#
#				Conv2D(24), stride=2
#				LeakyReLU(0.2)
#
#				Conv2D(48), stride=2
#				LeakyReLU(0.2)
#
#				Conv2D(96), stride=2
#				LeakyReLU(0.2)
#
#				Flatten
#
#				Dense(96)
#				LeakyReLU(0.2)
#
#				Dense(1)
#
#			Embedded constraints:
#				- Only the Generator is exported to TensorFlow Lite.
#				- int8 inference.
#				- Reduced channel count for embedded execution.
#				- Compatible with TensorFlow Lite Micro.
#
#			Notes:
#				- BatchNormalization layers are used only during training.
#				- They are typically folded into Conv2D layers during
#				  TensorFlow Lite conversion.
#
#			Output files:
#				- best_generator.keras
#				- generator_epoch_xxxx.keras
#				- NN_model.tflite
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

import	os
import	glob
import	numpy as np
import	matplotlib.pyplot as plt
import	tensorflow as tf
from 	PIL import Image
from 	tensorflow.keras import layers

# Configuration
# -------------

IMAGE_FOLDER		= "DB_faces"
OUTPUT_DIR			= "generated_faces"

IMG_SIZE			= 64
LATENT_DIM			= 64

BATCH_SIZE			= 32
EPOCHS				= 1000
DISPLAY_EVERY		= 5

LEARNING_RATE_G		= 0.0001
LEARNING_RATE_D		= 0.0002

BEST_KERAS_FILE		= "best_generator.keras"
FINAL_TFLITE_FILE	= "NN_model.tflite"

os.makedirs(OUTPUT_DIR, exist_ok=True)

# Load the learning dataset
# -------------------------

def load_faces_from_folder(folder):
	image_paths = sorted(glob.glob(os.path.join(folder, "*.png")) +
						 glob.glob(os.path.join(folder, "*.jpg")) +
						 glob.glob(os.path.join(folder, "*.jpeg"))
	)

	if len(image_paths) == 0:
		raise RuntimeError(f"No images in the folder {folder}")

	print(f"{len(image_paths)} images found.")

	faces = []
	for i, path in enumerate(image_paths):
		img = Image.open(path).convert("L")
		img = img.resize((IMG_SIZE, IMG_SIZE), Image.Resampling.LANCZOS)

		arr = np.array(img).astype("float32")

		# Scaling [0,255] -> [-1,1]
		arr = (arr / 127.5) - 1.0
		faces.append(arr)

		if i % 100 == 0:
			print(f"Loaded {i}/{len(image_paths)}")

	faces = np.array(faces, dtype=np.float32)

	# (N,100,100) -> (N,100,100,1)
	faces = np.expand_dims(faces, axis=-1)
	return faces

# Generator model (lightweight CNN)
# ---------------------------------
#
# Lightweight face generator optimized for embedded inference.
#
# Input:
#		Latent vector of LATENT_DIM float values.
#
# Architecture:
#
#		Dense(4 x 4 x 96)
#			↓
#		Reshape(4,4,96)
#			↓
#		Resize 8x8  → Conv2D(48)
#			↓
#		Resize 16x16 → Conv2D(24)
#			↓
#		Resize 32x32 → Conv2D(12)
#			↓
#		Resize 64x64 → Conv2D(8)
#			↓
#		Conv2D(8)    (feature refinement)
#			↓
#		Conv2D(1) + tanh
#
# Channel configuration:
#
#		96 → 48 → 24 → 12 → 8 → 8 → 1
#
# Training-only layers:
#
#		BatchNormalization is used after each convolution
#		to stabilize GAN training. These layers are folded
#		into the convolution weights during TFLite export.
#
# Supported TensorFlow Lite operators:
#
#		- FullyConnected
#		- Reshape
#		- ResizeNearestNeighbor
#		- Conv2D
#		- ReLU
#		- Tanh
#
# Design goals:
#
#		- Small memory footprint
#		- Fast embedded inference
#		- TensorFlow Lite / TensorFlow Lite Micro compatible
#		- Suitable for Cortex-Mx and Neural-ART based targets
#
# Output:
#
#		64 x 64 grayscale image in [-1, +1]
#
def build_generator():
	return tf.keras.Sequential([
		layers.Input(shape=(LATENT_DIM,)),

		layers.Dense(4 * 4 * 96),
		layers.ReLU(),
		layers.Reshape((4, 4, 96)),

		layers.Resizing(8, 8, interpolation="nearest"),
		layers.Conv2D(48, 3, padding="same"),
		layers.BatchNormalization(),
		layers.ReLU(),

		layers.Resizing(16, 16, interpolation="nearest"),
		layers.Conv2D(24, 3, padding="same"),
		layers.BatchNormalization(),
		layers.ReLU(),

		layers.Resizing(32, 32, interpolation="nearest"),
		layers.Conv2D(12, 3, padding="same"),
		layers.BatchNormalization(),
		layers.ReLU(),

		layers.Resizing(64, 64, interpolation="nearest"),
		layers.Conv2D(8, 3, padding="same"),
		layers.BatchNormalization(),
		layers.ReLU(),

		layers.Conv2D(8, 3, padding="same"),
		layers.BatchNormalization(),
		layers.ReLU(),

		layers.Conv2D(1, 3, padding="same", activation="tanh")
	])

# Discriminator model (CNN)
# -------------------------
#
# Binary classifier used only during GAN training.
#
# Input:
#
#		64 x 64 grayscale image
#
# Architecture:
#
#		Conv2D(24), stride=2
#			↓
#		Conv2D(48), stride=2
#			↓
#		Conv2D(96), stride=2
#			↓
#		Flatten
#			↓
#		Dense(96)
#			↓
#		Dense(1)
#
# Activations:
#
#		LeakyReLU(0.2)
#
# Output:
#
#		Single logit representing the probability
#		that the input image belongs to the training set.
#
# Notes:
#
#		The discriminator is used only during training.
#		It is not exported to TensorFlow Lite.
#
def build_discriminator():
	return tf.keras.Sequential([
		layers.Input((64, 64, 1)),

		layers.Conv2D(24, 4, strides=2, padding='same'),
		layers.LeakyReLU(0.2),

		layers.Conv2D(48, 4, strides=2, padding='same'),
		layers.LeakyReLU(0.2),

		layers.Conv2D(96, 4, strides=2, padding='same'),
		layers.LeakyReLU(0.2),

		layers.Flatten(),

		layers.Dense(96),
		layers.LeakyReLU(0.2),

		layers.Dense(1)
	])

# Loss functions
# --------------

cross_entropy = tf.keras.losses.BinaryCrossentropy(from_logits=True)

def discriminator_loss(real_output, fake_output):
	real_loss = cross_entropy(tf.ones_like(real_output) * 0.9, real_output)
	fake_loss = cross_entropy(tf.zeros_like(fake_output), fake_output)
	return real_loss + fake_loss

def generator_loss(fake_output):
	return cross_entropy(tf.ones_like(fake_output), fake_output)

# Display & save images
# ---------------------

def show_and_save_generated_images(generator, noise, epoch):
	generated = generator(noise, training=False)
	generated = (generated + 1.0) / 2.0
	generated = generated.numpy()

	plt.close("all")
	fig = plt.figure(figsize=(6, 6))

	for i in range(16):
		ax = fig.add_subplot(4, 4, i + 1)
		ax.imshow(generated[i, :, :, 0], cmap="gray", vmin=0, vmax=1)
		ax.axis("off")

	fig.suptitle(f"Epoch {epoch}")

	filename = os.path.join(OUTPUT_DIR, f"generated_epoch_{epoch:04d}.png")
	fig.savefig(filename)

	plt.show(block=False)
	plt.pause(0.1)

	print(f"Image saved : {filename}")

# Training & save the best model
# ------------------------------

@tf.function
def train_step(real_images, generator, discriminator, g_optimizer, d_optimizer):
	batch_size = tf.shape(real_images)[0]

	# Training the discriminator
	noise = tf.random.normal([batch_size, LATENT_DIM])
	with tf.GradientTape() as d_tape:
		fake_images = generator(noise, training=True)
		real_output = discriminator(real_images, training=True)
		fake_output = discriminator(fake_images, training=True)
		d_loss = discriminator_loss(real_output, fake_output)

	d_gradients = d_tape.gradient(d_loss, discriminator.trainable_variables)
	d_optimizer.apply_gradients(zip(d_gradients, discriminator.trainable_variables))

	# Training the generator
	noise = tf.random.normal([batch_size, LATENT_DIM])
	with tf.GradientTape() as g_tape:
		fake_images = generator(noise, training=True)
		fake_output = discriminator(fake_images, training=False)
		g_loss = generator_loss(fake_output)

	g_gradients = g_tape.gradient(g_loss, generator.trainable_variables)
	g_optimizer.apply_gradients(zip(g_gradients, generator.trainable_variables))
	return g_loss, d_loss

def representative_dataset():
	for _ in range(500):
		z = np.random.normal(0.0, 1.0, (1, LATENT_DIM)).astype(np.float32)
		yield [z]

def export_tflite_int8(generator, filename=FINAL_TFLITE_FILE):
	print("")
	print("Export TFLite int8...")

	@tf.function(input_signature=[
		tf.TensorSpec(shape=[1, LATENT_DIM], dtype=tf.float32)
	])
	def serving_fn(z):
		return generator(z, training=False)

	concrete_func = serving_fn.get_concrete_function()
	converter = tf.lite.TFLiteConverter.from_concrete_functions([concrete_func], generator)
	converter.optimizations = [tf.lite.Optimize.DEFAULT]
	converter.representative_dataset = representative_dataset
	converter.target_spec.supported_ops = [tf.lite.OpsSet.TFLITE_BUILTINS_INT8]
	converter.inference_input_type = tf.int8
	converter.inference_output_type = tf.int8

	tflite_model = converter.convert()

	with open(filename, "wb") as f:
		f.write(tflite_model)

	print(f"TFLite int8 model saved : {os.path.abspath(FINAL_TFLITE_FILE)}")
	print(f"TFLite int8 size        : {len(tflite_model) / 1024 / 1024:.2f} MB")

# Main
# ----

def main():
	print("Load the images...")
	faces = load_faces_from_folder(IMAGE_FOLDER)

	# Dataset TensorFlow
	dataset = tf.data.Dataset.from_tensor_slices(faces)
	dataset = dataset.shuffle(buffer_size=len(faces))
	dataset = dataset.batch(BATCH_SIZE)
	dataset = dataset.prefetch(tf.data.AUTOTUNE)

	print("Create the generator...")
	generator = build_generator()

	print("Create the discriminator...")
	discriminator = build_discriminator()

	generator.summary()
	discriminator.summary()

	# Adam optimiser
	g_optimizer = tf.keras.optimizers.Adam(learning_rate=LEARNING_RATE_G, beta_1=0.5)
	d_optimizer = tf.keras.optimizers.Adam(learning_rate=LEARNING_RATE_D, beta_1=0.5)

	# Some noise
	fixed_noise = tf.random.normal([16, LATENT_DIM])

	# Interactive matplotlib mode
	plt.ion()

	print("Start of the training...")
	best_g_loss = float("inf")

	for epoch in range(EPOCHS + 1):
		for real_batch in dataset:
			g_loss, d_loss = train_step(real_batch, generator, discriminator, g_optimizer, d_optimizer)

		if epoch % DISPLAY_EVERY == 0:
			print(f"Epoch {epoch} | "f"G loss: {g_loss.numpy():.4f} | "f"D loss: {d_loss.numpy():.4f}")
			show_and_save_generated_images(generator, fixed_noise, epoch)

		# Save the best generator
		if epoch % 50 == 0:
			generator.save(f"generator_epoch_{epoch:04d}.keras")
			export_tflite_int8(generator, f"generator_epoch_{epoch:04d}.tflite")

	print("Training terminated.")
	generator.save(BEST_KERAS_FILE)
	export_tflite_int8(generator)

# Main entry point
if __name__ == "__main__":
	main()
