# Classification with the TensorFlow lite Library

(c) 2025-2026, Edo. Franzi, 2026-07-29

## Introduction

This is an example of a complete neural network classifier demonstrating the full capabilities of µKOS-X in conjunction with TensorFlow Lite. The goal is to present, step by step, how to design and implement such a classifier.

As an illustrative case, we build a model capable of classifying 2D coordinates (x, y), where both values range from -1 to 1, into five distinct classes:

- **Class A (red):** top-left cluster
- **Class B (green):** top-right cluster
- **Class C (blue):** bottom-left cluster
- **Class D (yellow):** bottom-right cluster
- **Inter-class (violet):** the regions between all clusters

This example demonstrates how a neural network using µKOS-X can learn and distinguish different geometric regions in a two-dimensional space.

![](_Training/cluster.png)

## Dataset Creation and Classifier Generation

### Dataset creation

```bash
# Create the learning DB_L_file.txt and the validation DB_V_file.txt files
cd _Training
python3 DB_Creator.py
```

### Create the Neural Network

The file `NN_model.py` contains the high-level description of the neural network architecture and its configuration.

This Python script initialises the required libraries, reads the dataset files, and uses TensorFlow Lite to generate a trained model (a `.tflite` file). It defines the network structure, handles the training process, and prepares the model for deployment.

At the end of the process, the script generates the file `NN_model.c_inc`, which must be included in the application. This file contains the network parameters (such as weights and biases) in a format suitable for direct integration into the target system.

```bash
# Create the Neural Network
cd _Training
python3 NN_model.py --model_file NN_model.tflite --mode full
xxd -i NN_model.tflite > NN_model.c_inc
```

This file must then be included in the application so that the network architecture and its trained parameters can be embedded directly into the program. In this way, the application can use the classifier without requiring any external model file at runtime.

