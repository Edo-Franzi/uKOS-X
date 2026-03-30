# tflite_structure usage

(c) 2025-2026, Edo. Franzi, 2026-03-30

This guide provides comprehensive instructions for converting a TensorFlow Lite model (.tflite) into a µKOS-X MLPn format, with the goal of accelerating neural network inference and improving overall runtime performance on embedded systems.

## Prerequisites

The following python3 packages have to be installed:

1. `numpy` - Numerical computing
2. `flatbuffers` - Cross-platform serialization library
3. `tflite` - Python bindings for TensorFlow Lite

The following python3 packages have to be installed:

```
python3 -m pip install --user numpy flatbuffers tflite
```

## Usage

The simplest way to generate the information required for a µKOS-X MLPn is:

1. Generate the **.tflite** file (e.g., **mlp_model.tflite**) using TensorFlow
2. Run the **tflite_structure.py** converter
3. Include the generated output (**i.e., structure.c**) into the MLPn model (**e.g., network.c_inc**)

```shell
# Example, go to the example application

cd ${PATH_UKOS_X_PACKAGE}/Applications/uKOS_Appls_Downloadable/l_MLPs/class_TFL/_Training
python3 ${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/uKOS_Tools/tflite_structure/tflite_structure.py mlp_model.tflite -o structure.c
```

