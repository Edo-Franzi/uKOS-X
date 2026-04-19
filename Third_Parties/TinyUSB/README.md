# TinyUSB for uKOS-X (v.1.15)

(c) 2025-2026, Edo. Franzi, 2026-04-17

## After each TinyUSB update

```bash
# Verify and eventually adapt the patch for the rp2350:

# Reference
TinyUSB-current/src/portable/raspberrypi/rp2040/dcd_rp2040.c

# Patch
Construction/Interface/Patches/mcu/raspberrypi/pico2/dcd_rp2040.c
```

## Trick

```bash
# For testing the package examples, in the application Makefile, add
# In a script point to the right compiler

CURRENT_PATH=examples/device/TheExample
PATH_GCC_ARM=${PATH_TOOLS_GCC}/cross/gcc-15.2.0/arm/bin
PATH=${PATH}:${PATH_GCC_ARM}
export PATH_GCC_ARM
```

