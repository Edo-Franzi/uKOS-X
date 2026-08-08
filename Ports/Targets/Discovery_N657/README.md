# Target Discovery_N657

(c) 2025-2026, Edo. Franzi, 2026-08-05

## Base

| Base |                     |
| ---- | ------------------- |
| CPU  | STM32N657 @ 800-MHz |
| Core | M55                 |
| Comm | urt0, cdc0          |
## Variants

| Variant      | Description       | Specific                         |
| ------------ | ----------------- | -------------------------------- |
| Variant_Test | For Initial tests | With MicroPython embedded        |
|              |                   | With HS CDC TinyUSB              |
|              |                   | With LTDC, TensorFlow,  STEdgeAI |

## Programming

```bash
# A simple system can be programmed using:
cd ${PATH_UKOS_X_PACKAGE}/Ports/Targets/Discovery_N657/Variant_Test/System
make burn

# Adding the autorun gan application
# Without changing the switch position
cd ${PATH_UKOS_X_PACKAGE}/Applications/uKOS_Appls_Downloadable/l_MLPs/gan/Discovery_N657
./burn.sh

# Adding the NN weights for the gan application
# Without changing the switch position
cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/Library/AI/gan
./burn.sh
```

