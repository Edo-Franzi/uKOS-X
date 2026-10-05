# Burning the Discovery with the NPU information

(c) 2025-2026, Edo. Franzi, 2026-10-04

## Building all the components

```bash
# The OS
cd ${PATH_UKOS_X_PACKAGE}/Ports/Targets/Discovery_N657/Variant_Test/System
make -j USER_MODE=1

# The APP gan
cd ${PATH_UKOS_X_PACKAGE}/Applications/uKOS_Appls_Downloadable/l_MLPs/gan/Discovery_N657
make -j USER_MODE=1

# The NPU library
cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/Library/AI/gan
./build.sh
```

## Burning the FLASH

```bash
# Place the switch BOOT1

# Burn the OS
cd ${PATH_UKOS_X_PACKAGE}/Ports/Targets/Discovery_N657/Variant_Test/System
make burn

# Burn the APP gan
cd ${PATH_UKOS_X_PACKAGE}/Applications/uKOS_Appls_Downloadable/l_MLPs/gan/Discovery_N657
./burn.sh

# Burn the NPU library
cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/Library/AI/gan
./burn.sh
```
