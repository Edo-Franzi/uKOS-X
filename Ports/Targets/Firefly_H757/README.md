# Target Firefly_H757

(c) 2025-2026, Edo. Franzi, 2025-10-29

## Base

| Base       |                               |
| ---------- | ----------------------------- |
| CPU        | STM32H757 @ 480-MHz / 240-MHz |
| Core       | H7 - M4                       |
| Memory     | 8-MBytes SDRAM                |
| Comm       | urt0,  cdc0, cdc1             |
| Periph     |                               |
| Extensions |                               |

## Variants

| Variant          | Description       | Specific                  |
| ---------------- | ----------------- | ------------------------- |
| Variant_Test_CM4 | For Initial tests | test_mcore                |
| Variant_Test_CM7 | For Initial tests | With MicroPython embedded |
|                  |                   | With test_mcore           |
|                  |                   | WithFS CDC TinyUSB        |
|                  |                   |                           |
