# ESP32 BLE ↔ UART Bridge (NUS)

(c) 2025-2026, Edo. Franzi, 2026-04-28

## Introduction

This firmware implements a **transparent bidirectional bridge** between a UART interface and Bluetooth Low Energy (BLE), using the **Nordic UART Service (NUS)** profile.

- BLE Write -> UART
- UART -> BLE Notify

It emulates and simplifies the AT firmware, which is available for ESP32 but not for ESP32-S3.

## Features

- Lightweight implementation based on NimBLE
- Transparent byte stream abstraction
- Automatic MTU handling
- Compatible with standard BLE tools (iOS / Android / PC)
- No proprietary protocol required

## BLE configuration

### Device Name

```bash
uKOS-X_BLE
```

### Service: Nordic UART Service (NUS)

| Type        | UUID                                   | Direction   |
| ----------- | -------------------------------------- | ----------- |
| Service     | `6E400001-B5A3-F393-E0A9-E50E24DCCA9E` | —           |
| RX (Write)  | `6E400002-B5A3-F393-E0A9-E50E24DCCA9E` | BLE → ESP32 |
| TX (Notify) | `6E400003-B5A3-F393-E0A9-E50E24DCCA9E` | ESP32 → BLE |

## Build Instructions

```bash
# Set-up the environment
source setup.sh

# Optional board control
# esp32 -reset
# esp32 -boot

cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/Construction/Interface/ble_to_uart
idf.py set-target esp32
idf.py build
idf.py -p /dev/cu.usbserial-uKOS_1 flash

# esp32 -reset
# esp32 -connect 460800
```

## Testing (iOS/Android)

Use the app **nRF Connect**

1. Scan for `uKOS-X_BLE`
2. Connect to the device
3. Enable **notifications** on TX characteristic
4. Write data to RX characteristic

## UART

By default the firmware uses `UART_NUM_1` à `460800 8N1`.

```c
#define UART_PORT UART_NUM_1
#define UART_TX_PIN 17
#define UART_RX_PIN 16
```

## Performance & Limitations

### BLE Transport Constraints

BLE is **packet-based**, not a true streaming interface.

- Maximum ATT MTU: typically **517 bytes**
- Effective payload:

- Effective payload:

```bash
Payload = MTU - 3 bytes
```

### Throughput depends on:

- MTU size negotiated with client
- Connection interval
- PHY (1M / 2M)
- Mobile device capabilities

Typical range:

- ~5–20 kB/s (default settings)
- Higher with optimized parameters

## Internal Behavior

- UART is polled every ~20 ms
- BLE notifications are fragmented according to MTU
- Single active BLE connection
- Notifications must be enabled by client

## Comparison with Wi-Fi Version

| Feature     | BLE (this firmware) | Wi-Fi version |
| ----------- | ------------------- | ------------- |
| Latency     | Low                 | Medium        |
| Throughput  | Low–Medium          | High          |
| Power usage | Low                 | Higher        |
| Range       | Short               | Long          |
| Setup       | Simple              | Network req.  |

## Notes

- This firmware is ideal for:

  - Debug console over BLE

  - Low-bandwidth telemetry

  - Mobile app communication

- For high throughput applications, prefer the **Wi-Fi TCP bridge**.
