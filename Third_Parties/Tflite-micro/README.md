# TFLite for uKOS-X (v.1.7)

(c) 2025-2026, Edo. Franzi, Antonio José Restrepo Zea, Laurent von Allmen 

## Tools and libraries installation

###  Intel cores Macs, Tensorflow 2.17 need to be build from sources

```bash
# Install bazelisk
sudo port install bazelisk

# Build Tensorflow
cd /tmp
wget https://github.com/tensorflow/tensorflow/archive/refs/tags/v2.17.0.tar.gz
tar xvf v2.17.0.tar.gz

cd /tmp/tensorflow-2.17.0
./configure
```

> You have bazel 6.5.0 installed.
>
> Please specify the location of python. [Default is ........]: <ENTER>
>
> Please input the desired Python library path to use.  Default is [......]: <ENTER>
>
> Do you wish to build TensorFlow with ROCm support? [y/N]: <ENTER>
>
> Do you wish to build TensorFlow with CUDA support? [y/N]: <ENTER>
>
> Please specify optimization flags to use during compilation when bazel option "--config=opt" is specified [Default is -Wno-sign-compare]: <ENTER>
>
> Would you like to interactively configure ./WORKSPACE for Android builds? [y/N]: <ENTER>
>
> Do you wish to build TensorFlow with iOS support? [y/N]: <ENTER>

```bash
bazel build //tensorflow/tools/pip_package:wheel --repo_env=WHEEL_NAME=tensorflow_cpu
```

> ................
>
> **<AFTER SOME TIME.....>**
>
> INFO: Analysed target //tensorflow/tools/pip_package:wheel (673 packages loaded, 43110 targets configured).
>
> INFO: Found 1 target...Target //tensorflow/tools/pip_package:wheel up-to-date:  bazel-bin/tensorflow/tools/pip_package/wheel_house
>
> INFO: Elapsed time: 12547.387s, Critical Path: 816.00s
>
> INFO: 22512 processes: 5023 internal, 17489 local.
>
> INFO: Build completed successfully, 22512 total actions

```bash
pip3 install bazel-bin/tensorflow/tools/pip_package/wheel_house/tensorflow_cpu-2.17.0-cp311-cp311-macosx_15_0_x86_64.whl
```

> Successfully installed keras-3.6.0 ml-dtypes-0.4.1 tensorboard-2.17.1 tensorflow-cpu-2.17.0

### Arm core Macs, just use pip

As TensorFlow Lite needs Python 3.13 to create a virtual environment.

```bash
# To regenerate requirements.txt, just use pip freeze > requirements.txt
# Use pip and not pip3 to be sure to use the virtual environment version

cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv
python3.13 -m venv Tflite_Pyenv
source Tflite_Pyenv/bin/activate

pip install -r requirements.txt
```

```bash
# To update the environmant
# Use pip and not pip3 to be sure to use the virtual environment version

cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv
source Tflite_Pyenv/bin/activate

pip install -r requirements.txt --upgrade
```

### Building the TFLite libraries

A complete script for downloading, building and organising the libraries is available. This is the last installation step before using TFLite in applications.

```bash
# Build all the necessary libraries:
# For RISC-V: rv32imac and rv64imafdc
# For arm:    cortex-m3, -m4, -m7 -m33 -m55 and -m85

cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro
./build.sh
```

## Building the example

Downloadable examples are available in the package.

```bash
# Ex. class_TFL: Build the TFLite model

cd ${PATH_UKOS_X_PACKAGE}/Applications/uKOS_Appls_Downloadable/l_Neuros/class_TFL/_Training
./build.sh

# Ex. class_TFL: Build the application example (e.g for Nucleo_H743)

cd ${PATH_UKOS_X_PACKAGE}/Applications/uKOS_Appls_Downloadable/l_Neuros/class_TFL/Nucleo_H743
make -j USER_MODE=1
```
