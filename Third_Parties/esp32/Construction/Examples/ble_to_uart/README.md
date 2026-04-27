# ESP32 ble_to_uart firmware

(c) 2025-2026, Edo. Franzi, 2026-04-27

## Introduction

This firmware is intended to create a transparent connection between an UART and the BLS.

- BLE Write -> UART
- UART -> BLE Notify

This emulate (and simplify) the AT firmware (available only on esp32 and not esp32-s3).

## UUIDs

Service NUS:

```text
6E400001-B5A3-F393-E0A9-E50E24DCCA9E
```

RX / Write:

```text
6E400002-B5A3-F393-E0A9-E50E24DCCA9E
```

TX / Notify:

```text
6E400003-B5A3-F393-E0A9-E50E24DCCA9E
```

## Build

```bash
# Set-up the environment
source setup.sh

# From the Alastor console type
# esp32 -reset
# esp32 -boot

cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/Construction/Examples/ble_to_uart
idf.py set-target esp32
idf.py build
idf.py -p /dev/cu.usbserial-uKOS_1 flash
```

## Test iPhone

Use the APP nRF Connect :

1. Scanner `uKOS-X_BLE`
2. Connect
3. Activate Notify on the TX characteristic
4. Write on the RX characteristic

## UART

By default the firmware uses `UART_NUM_1` à `460800 8N1`.

```c
#define UART_PORT UART_NUM_1
#define UART_TX_PIN 17
#define UART_RX_PIN 18
```

## Notes

- BLE does not provide a true serial stream: the firmware fragments packets according to the available MTU size.
- The preferred MTU is 517, but the final MTU is determined by the client.
- Throughput depends heavily on the phone, the MTU, and the connection parameters.
