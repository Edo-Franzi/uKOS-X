# Gan demo for uKOS-X (v.1.0)

(c) 2025-2026, Edo. Franzi, 2026-07-29

## Tools and libraries installation

### Generate the NN_model.c_inc for the demo

The Third_Parties Tflite-micro has to be installed

```bash
# Activate the the virtual environment
cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/Tflite-micro/Construction/Pyenv
source Tflite_Pyenv/bin/activate

# Train the network
cd ${PATH_UKOS_X_PACKAGE}/Applications/uKOS_Demos/gan/Classifier/_Training
./build

# At this stage, mlp_model.c_inc should be in the folder
# Now, build the system with the embedded the demo
cd ${PATH_UKOS_X_PACKAGE}/Ports/Targets/Discovery_xyz/Variant_Test/System
make -j USER_MODE=1 WITHAPP=gan
```

### How to use a better model?

Inside the `generated_faces` folder, there is a list of result images for each epoch. If visual inspection shows that the generator from another epoch performs better, we can use it for the application.

```bash
# Example, the epoch 0600 is the better visual result
# We want to use it
cd ${PATH_UKOS_X_PACKAGE}/Applications/uKOS_Demos/gan/Classifier/_Training
xxd generator_epoch_0600.tflite > NN_model.xxd
xxd -i generator_epoch_0600.tflite > NN_model.c_inc
```

