# Target MAiXDUiNO

(c) 2025-2026, Edo. Franzi, 2025-01-01

## Base

| Base |                                  |
| ---- | -------------------------------- |
| CPU  | 2 RV64 @ 400-MHz                 |
| Core | RISC-V (RV64)                    |
| Comm | 1 x urt0 (usart2 for the core 0) |
| Comm | 1 x urt0 (usart1 for the core 1) |

## Variants

| Variant      | Description       | Specific                  |
| ------------ | ----------------- | ------------------------- |
| Variant_Test | For Initial tests | With MicroPython embedded |
|              |                   | With TensorFlow,          |

## Note

| To communicate with the core 1, it is necessary to connect an external usb/uart converter. P5.7 is the gnd,  P5.6 is the RX of the terminal and  P5.5 is the TX of the terminal. |
| ------------------------------------------------------------ |

![](README.png)
