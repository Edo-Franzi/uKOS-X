#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# tflite_structure.
# =================

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
#
# Project:	uKOS-X
# Goal:		Extract the NN architecture from a TensorFlow Lite model
#
#			Necessary packages:
#			python3 -m pip install --user numpy flatbuffers tflite
#
#			Usage:
#			python3 tflite_structure.py mlp_model.tflite -o structure.c
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
import	sys
import	numpy as np

# Helpers format C
# ----------------

def c_float(v: float, decimals: int = 6) -> str:
	return f"{v:.{decimals}f}f"

# Activation mapping
# ------------------

def act_name_from_enum(enum_name: str) -> str:
	mapping = {
		"NONE": "LINEAR",
		"LOGISTIC": "SIGMOID",
		"RELU": "RELU",
		"RELU6": "RELU6",
		"TANH": "TANH",
		"HARD_SWISH": "HARD_SWISH",
		"SIGN_BIT": "SIGN_BIT",
	}

	return mapping.get(enum_name, enum_name)

# Convertion from a flatbuffers enum to its symbolic name
# -------------------------------------------------------

def enum_to_name(enum_module, value: int) -> str:
	for k in dir(enum_module):
		if k.isupper():
			try:
				if int(getattr(enum_module, k)) == int(value):
					return k

			except Exception:
				pass

	return "UNKNOWN"

# Read a tensor float32 from its buffer
# -------------------------------------

def read_tensor_f32_constant(model, tensor, TensorType) -> np.ndarray:
	if int(tensor.Type()) != int(TensorType.FLOAT32):
		raise ValueError(
			f"TensorType != FLOAT32 (type={int(tensor.Type())}). Requested f32."
		)

	shape = [int(tensor.Shape(i)) for i in range(tensor.ShapeLength())]
	buf_idx = int(tensor.Buffer())
	buf = model.Buffers(buf_idx)

	data = buf.DataAsNumpy()
	if data is None or data.size == 0:
		raise ValueError("!!! Buffer empty.")

	arr = np.frombuffer(data.tobytes(), dtype=np.float32)
	if shape:
		arr = arr.reshape(shape)
	return arr

# Main
# ----

def main() -> int:
	ap = argparse.ArgumentParser(
		description="MLP TFLite dump (FULLY_CONNECTED) in float32 for uKOS-X usage. The bias vector is included in the weight set input bias = 1."
	)
	ap.add_argument("model", help="Path to the file .tflite")
	ap.add_argument("-o", "--out", default="-", help="Output file (default: stdout)")
	ap.add_argument("--decimals", type=int, default=6, help="Decimals for floats (default: 6)")
	args = ap.parse_args()

	# Import the tflite bindings of the package  (pip)
	try:
		import tflite
		from tflite.BuiltinOperator import BuiltinOperator
		from tflite.BuiltinOptions import BuiltinOptions
		from tflite.FullyConnectedOptions import FullyConnectedOptions
		from tflite.ActivationFunctionType import ActivationFunctionType
		from tflite.TensorType import TensorType

	except Exception as e:
		print(
			"[Error] not possible to import the 'tflite' package.\n"
			f"Details: {e}",
			file=sys.stderr,
		)
		return 1

	# Read the file
	try:
		with open(args.model, "rb") as f:
			buf = f.read()

	except OSError as e:
		print(f"[Error] Impossible to open {args.model}: {e}", file=sys.stderr)
		return 1

	# Open the output
	if args.out == "-" or args.out.strip() == "":
		out = sys.stdout
	else:
		try:
			out = open(args.out, "w", encoding="utf-8")

		except OSError as e:
			print(f"[Error] Impossible to open {args.out} en écriture: {e}", file=sys.stderr)
			return 1

	try:
		model = tflite.Model.GetRootAsModel(buf, 0)
		if model.SubgraphsLength() < 1:
			print("[Error] No subgraph in this model.", file=sys.stderr)
			return 1

		sg = model.Subgraphs(0)

		# opcode_index -> builtin operator
		builtin_ops = []
		for i in range(model.OperatorCodesLength()):
			oc = model.OperatorCodes(i)
			builtin_ops.append(int(oc.BuiltinCode()))

		layers = []  # list of (act, nb_in_aug, nb_out, W_aug)

		# --- scan ops
		for i in range(sg.OperatorsLength()):
			op = sg.Operators(i)
			opcode_index = int(op.OpcodeIndex())
			builtin = builtin_ops[opcode_index]

			if builtin != int(BuiltinOperator.FULLY_CONNECTED):
				continue

			# inputs: [input, weights, bias]
			if op.InputsLength() < 2:
				continue

			w_tid = int(op.Inputs(1))
			b_tid = int(op.Inputs(2)) if op.InputsLength() >= 3 else -1

			W = read_tensor_f32_constant(model, sg.Tensors(w_tid), TensorType)

			if b_tid >= 0:
				b = read_tensor_f32_constant(model, sg.Tensors(b_tid), TensorType).reshape(-1)
			else:

				# No bias
				if W.ndim != 2:
					raise ValueError("Bias absent et W non 2D: impossible de déduire nb_out.")
				b = np.zeros((W.shape[0],), dtype=np.float32)

			# Activation fused (if disponible)
			act = "LINEAR"

			if int(op.BuiltinOptionsType()) == int(BuiltinOptions.FullyConnectedOptions):
				opt = FullyConnectedOptions()
				opt.Init(op.BuiltinOptions().Bytes, op.BuiltinOptions().Pos)
				act_id = int(opt.FusedActivationFunction())
				act_enum = enum_to_name(ActivationFunctionType, act_id)
				act = act_name_from_enum(act_enum)

			# If activation non fused -> verify the next l'op
			if act == "LINEAR" and i + 1 < sg.OperatorsLength():
				next_op = sg.Operators(i + 1)
				next_opcode = builtin_ops[int(next_op.OpcodeIndex())]

				activation_ops = {
					int(BuiltinOperator.TANH): "TANH",
					int(BuiltinOperator.RELU): "RELU",
					int(BuiltinOperator.RELU6): "RELU6",
					int(BuiltinOperator.LOGISTIC): "SIGMOID",
					int(BuiltinOperator.HARD_SWISH): "HARD_SWISH",
					int(BuiltinOperator.SOFTMAX): "SOFTMAX",
				}

				if next_opcode in activation_ops:
					act = activation_ops[next_opcode]

			# Verify if transposed W en (out, in)
			nb_out = int(b.shape[0])
			if W.ndim != 2:
				raise ValueError(f"W ndim={W.ndim}, expected 2 for FULLY_CONNECTED.")
			if W.shape[0] == nb_out:
				W_use = W
			elif W.shape[1] == nb_out:
				W_use = W.T
			else:
				raise ValueError(f"Impossible to see if transposition W={W.shape} with b={b.shape}.")

			nb_out, nb_in = int(W_use.shape[0]), int(W_use.shape[1])

			# Fusion of the bias
			W_aug = np.concatenate([W_use, b.reshape(nb_out, 1)], axis=1).astype(np.float32)

			layers.append((act, nb_in + 1, nb_out, W_aug))

		if not layers:
			print("[Error] FULLY_CONNECTED layer found 0.", file=sys.stderr)
			return 1

		# --- Print header
		print( "// uKOS-X", file=out)
		print( "// TFLite MLP dump (pip-only) - float32", file=out)
		print(f"// Model: {args.model}", file=out)
		print(f"// Number of layerss (FULLY_CONNECTED): {len(layers)}", file=out)
		print( "// NB_IN contains 1 input to 1 for the bias à 1 ; last weight column = bias", file=out)

		print(f"#define\tKMLPN_NB_LAYERS\t{len(layers)}\n", file=out)

		# --- Summary
		for li, (act, nb_in_aug, nb_out, _) in enumerate(layers, start=1):
			print(f"// Layer {li}: NB_IN={nb_in_aug}, NB_OUT={nb_out}, ACT={act}", file=out)
		print("", file=out)

		# --- Dump each layer in C format
		for li, (act, nb_in_aug, nb_out, W_aug) in enumerate(layers, start=1):
			print(f"// Layer {li}", file=out)
			print(f"// Activation: {act}", file=out)
			print(f"#define\tKMLPN_L{li}_NB_IN\t{nb_in_aug}", file=out)
			print(f"#define\tKMLPN_L{li}_NB_OUT\t{nb_out}\n", file=out)

			print(
				f"static\tconst\tfloat\tvWeight_L{li}[KMLPN_L{li}_NB_OUT][KMLPN_L{li}_NB_IN] = {{",
				file=out,
			)
			for r in range(nb_out):
				row = ", ".join(c_float(float(x), decimals=args.decimals) for x in W_aug[r, :])
				print(f"\t{{ {row} }},", file=out)
			print("};\n", file=out)

		return 0

	except Exception as e:
		print(f"[ERREUR] {e}", file=sys.stderr)
		return 1

	finally:
		if out is not sys.stdout:
			out.close()

if __name__ == "__main__":
	raise SystemExit(main())
