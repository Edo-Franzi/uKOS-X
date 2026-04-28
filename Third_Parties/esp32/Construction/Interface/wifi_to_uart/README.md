# ESP32 Wi-Fi ↔ UART Bridge (TCP)

(c) 2025-2026, Edo. Franzi, 2026-04-28

## Introduction

This firmware implements a **transparent bidirectional bridge** between a UART interface and a Wi-Fi TCP connection.

The ESP32 runs as a **Wi-Fi SoftAP** and exposes a **TCP server**.

- **Wi-Fi → UART**: TCP data is forwarded to UART
- **UART → Wi-Fi**: UART data is sent to the TCP client

## Features

- Transparent byte stream (no protocol overhead)
- Wi-Fi SoftAP mode (no router required)
- Standard TCP socket interface
- Compatible with any TCP client (netcat, telnet, custom apps)
- Single-client connection model
- High throughput compared to BLE

## Wi-Fi Configuration

### Access Point

```bash
SSID:     uKOS-X_WIFI
Password: 12345678
IP:       192.168.4.1
```

### TCP Server

```bash
Port: 3333
Protocol: TCP
```

Only **one client** can be connected at a time

New connection replaces the previous one

## Build Instructions

```bash
# Set-up the environment
source setup.sh

# Optional board control
# esp32 -reset
# esp32 -boot

cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/Construction/Interface/wifi_to_uart
idf.py set-target esp32
idf.py build
idf.py -p /dev/cu.usbserial-uKOS_1 flash

# esp32 -reset
# esp32 -connect 460800
```

## Testing

### PC / macOS / Linux

```
nc 192.168.4.1 3333
```

### Steps

1. Connect to Wi-Fi network `uKOS-X_WIFI`
2. Enter password `12345678`
3. Open TCP connection using `nc` or any TCP client
4. Start sending/receiving data

## UART

By default the firmware uses `UART_NUM_1` à `460800 8N1`.

```c
#define UART_PORT UART_NUM_1
#define UART_TX_PIN 17
#define UART_RX_PIN 16
```

## Performance & Limitations

### Characteristics

- True **stream-oriented** transport (TCP)
- No fragmentation at application level
- Reliable (retransmissions handled by TCP)

### Throughput

Depends on:

- Wi-Fi signal quality
- CPU load
- TCP window / stack tuning

Typical range:

- **100 kB/s → 1+ MB/s**

## Internal Behavior

- ESP32 operates in **SoftAP mode**
- TCP server listens on port `3333`
- One active client at a time
- UART polled every ~20 ms
- Partial sends handled (loop until all data sent)
- Socket protected by mutex

## Limitations

- Single client only
- No encryption (WPA2 only at Wi-Fi level)
- No buffering beyond UART + TCP stack
- No flow control between UART and TCP

## Comparison with BLE Version

| Feature     | Wi-Fi (this firmware) | BLE version |
| ----------- | --------------------- | ----------- |
| Throughput  | High                  | Low–Medium  |
| Latency     | Medium                | Low         |
| Range       | Long                  | Short       |
| Power usage | Higher                | Low         |
| Setup       | Requires Wi-Fi        | Very simple |

## Typical Use Cases

- High-speed debug console
- Data streaming (logs, sensors)
- Firmware communication bridge
- Replacement for USB-UART in embedded setups

## Notes

- This firmware is ideal when **throughput matters more than power**

- For mobile / low-power applications, prefer the BLE version

- You can easily adapt this to:

  - **STA mode (connect to existing Wi-Fi)**

  - **UDP mode (lower latency, no guarantee)**

  - **TLS (secure socket)**
