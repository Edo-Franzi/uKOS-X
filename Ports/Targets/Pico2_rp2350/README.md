# Target Pico2_rp2350

(c) 2025-2026, Edo. Franzi, 2026-05-25

## Base

| Base       |                      |
| ---------- | -------------------- |
| CPU        | 2 x rp2350 @ 150-MHz |
| Core       | M33 / RV32IMAC       |
| Comm       | urt0, cdc0, cdc1     |
| Periph     |                      |
| Extensions |                      |

## Variants

| Variant      | Description           | Specific                  |
| ------------ | --------------------- | ------------------------- |
| Variant_Test | For Initial tests     | With MicroPython embedded |
|              | Building for M33      | make -j USER_MODE=1       |
|              | Building for RV32IMAC | make -j CORE=RV32IMAC     |
|              |                       | With FS CDC TinyUSB       |
|              |                       | With TensorFlow           |
