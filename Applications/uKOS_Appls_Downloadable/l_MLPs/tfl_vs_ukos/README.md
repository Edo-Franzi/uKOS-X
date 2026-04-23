# Inference performance of a TFL vs µKOS-X MLPN

(c) 2025-2026, Edo. Franzi, 2026-04-23

## Introduction

This example aims to compare the inference speed of a TensorFlow Lite model with that of the µKOS-X MLPN implementation.

The starting point is to use an existing TensorFlow Lite model and extract all the relevant information required to run it with the µKOS-X MLPN library. This includes the network architecture, weights, and associated parameters.

The model used in this example is derived from the `class_TFL` application.

## Generate the model for MLPN library

### Dataset creation

```bash
# From the .tflite to network.c_inc
# This extract the information of .tflite and create the structure.c file
cd _Models
./build

# Modify the file network.c_inc with the information included in the file structure.c
```

### Compile & execute the test

1) Run the script to create the file **mlp_TFL_test.c_inc**

```bash
# i.e. for the target Alastor_H743
cd Alastor_H743
make -j USER_MODE=1
```

```bash
# Typical results
Exec time for TensorFlowLite, min = 333 [us], max = 351 [us]
Exec time for MLPN uKOS-X,    min = 186 [us], max = 191 [us]
```

