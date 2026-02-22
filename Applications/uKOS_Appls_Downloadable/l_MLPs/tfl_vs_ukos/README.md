# Inference performance of a tflite model

(c) 2025-2026, Edo. Franzi, 2026-02-20



To monitor the inference execution time, simply rename your file **myModelName.tflite** to **mlp_TFL_test.tflite** and place it in the **_models** folder.

1) Run the script to create the file **mlp_TFL_test.c_inc**

```
./build.sh
```

2) Run the Python script to extract the TFL structure of the  the file **mlp_TFL_test.tflite**; The information is included in the **structure.c** file
3) Modify the file **network.c_inc** with the information included in the file **structure.c**

Then compile and execute the file **tfl_vs_ukos.cpp**.

