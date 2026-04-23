# Classification with the MLPN Library

(c) 2025-2026, Edo. Franzi, 2026-04-23

## Introduction

This is an example of a complete neural network classifier demonstrating the full capabilities of µKOS-X. The goal is to present, step by step, how to design and implement such a classifier.

As an illustrative case, we aim to build a model capable of classifying 2D coordinates (x, y), where both values range from -1 to 1, into three distinct classes:

- **C1 – Ring (red):** points forming a circular ring structure
- **C2 – Inner-Outer (green):** points located between the inner and outer regions
- **C3 – Square (blue):** points forming a square-shaped region

This example highlights how different geometric patterns can be learned and distinguished by a neural network using µKOS-X.

![](_Training/class.png)

## Dataset Creation and Classifier Generation

### Dataset creation

```bash
# Create the learning DB_L_file.txt and the validation DB_V_file.txt files
cd _Training
python3 DB_Creator.py
```

### Define the network

The file `config.py` contains the high-level description of the neural network architecture and its configuration. It defines the main components of the model, such as the number of layers, the type of neurons, activation functions, and other key parameters required to build the classifier. This file serves as the central place for configuring the network before training, making it easier to adjust the model structure and experiment with different settings.

```bash
# Application / Network configuration
#
# L1 - 2 inputs
# L1 - 52 output
# L2 - 52 input (the bias is automatically added)
# L2 - 73 output
# L3 - 73 input (the bias is automatically added)
# L3 - 3 output
#              I1  O1  O2  O3
KLAYERS     = [2, 52, 73, 3]
KNB_INPUTS  = 2
KNB_OUTPUTS = 3

# KMLPN_TAN0 = libm tanh
# KMLPN_TAN1 = Lambert's tanh approximation
# KMLPN_TAN2 = Ultrafast tanh approximation (~2% precision)
# KMLPN_TAN3 = Fastest tanh approximation (less precise)
# KMLPN_RELU = Ultrafast relu
# KMLPN_LINE = Ultrafast linear
# KMLPN_SMAX = Ultrafast softmax
#
KNON_LINEAR     = "KMLPN_TAN2"
KNON_LINEAR_OUT = "KMLPN_SMAX"

KGAIN     = 0.005
KMOMENTUM = 0.0
KEPOCHS   = 1000000

# Some Input/Output samples for rapid validation
#
#               Input -x -y          Class -1 -2 -3
KVALIDATION = [
              [ 0.490344,  0.051584, 0.98, 0.0,  0.0],
              [ 0.458057, -0.458232, 0.98, 0.0,  0.0],
              [ 0.266116,  0.944208, 0.0,  0.98, 0.0],
              [-0.002234, -0.117944, 0.0,  0.98, 0.0],
              [ 0.834344,  0.854564, 0.0,  0.0,  0.98]
              ]
```

For this example, we use a three-layer neural network with 2 input neurons and three successive layers of 52, 73, and 3 neurons, respectively.

The first two layers (L1 and L2) use a non-linear activation function based on an ultrafast approximation of the hyperbolic tangent (tanh). The final layer (L3) uses an ultrafast softmax function to produce normalized output probabilities for the three target classes.

### Create the Neural Network

```bash
# Create the Neural Network
cd _Training
./build.sh
```

At this step, the file **`network.c_inc`** is created. It contains the structure of the neural network as well as the set of weights associated with it.

This file must then be included in the application so that the network architecture and its trained parameters can be embedded directly into the program. In this way, the application can use the classifier without requiring any external model file at runtime.

