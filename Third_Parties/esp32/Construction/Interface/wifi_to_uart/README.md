# ESP32 Wi-Fi ↔ UART Bridge (TCP client)

(c) 2025-2026, Edo. Franzi, 2026-05-03

## Introduction

This firmware implements a **transparent bidirectional bridge** between a UART interface and a Wi-Fi TCP connection.

The ESP32 runs as a **Wi-Fi Station (STA)** and connects to an existing network. It exposes a **TCP server** on the assigned IP address.

- **Wi-Fi → UART**: TCP data is forwarded to UART
- **UART → Wi-Fi**: UART data is sent to the TCP client

## Features

- Transparent byte stream (no protocol overhead)
- Wi-Fi **STA mode** (connects to existing router)
- Standard TCP socket interface
- Compatible with any TCP client (netcat, telnet, custom apps)
- Single-client connection model
- High throughput compared to BLE

## Wi-Fi Configuration

### Station (Client Mode)

```bash
#define KWIFI_SSID     "Your_WiFi_Name"
#define KWIFI_PASSWORD "Your_WiFi_Password"
```

### TCP Server

```bash
Port: 3333
Protocol: TCP
```

IP address is assigned by the router (e.g. `192.168.1.xxx`)

Only **one client** can be connected at a time

New connection replaces the previous one

## Build Instructions

### For Alastor-H743

```bash
# Set-up the environment
source setup.sh

# In the main.c
#undef  KUART_0
#undef  KWITHOUT_LOGS

# Optional board control
esp32 -reset
esp32 -boot

cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/Construction/Interface/wifi_to_uart
idf.py set-target esp32
idf.py build
idf.py -p /dev/cu.usbserial-uKOS_1 flash

# If the host has to provide the SSID and the password
esp32 -reset
esp32 -wifi "Netwok_Name" "Password"
console urt2
```

### For MAiXDUiNO_K210

```bash
# Set-up the environment
source setup.sh

# In the main.c
#define KUART_0
#define KWITHOUT_LOGS

# Push, and maintain, the boot button
esp32 -reset
# Push reset
# Release the reset button
# Release the boot button

cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/Construction/Interface/wifi_to_uart
idf.py set-target esp32
idf.py build
idf.py -p /dev/cu.usbserial-00320000001 -b 115200 flash

# If the host has to provide the SSID and the password
esp32 -reset
esp32 -wifi "Netwok_Name" "Password"
console urt1
```

## Testing

### PC / macOS / Linux

```
nc <ESP32_IP> 3333
```

### Steps

1. Power the ESP32
1. Ensure it connects to your Wi-Fi network
1. Retrieve its IP address (router, logs, DHCP list)
1. Connect using `nc` or any TCP client
1. Start sending/receiving data

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
- Network load
- CPU load
- TCP stack tuning

Typical range:

- **100 kB/s → 1+ MB/s**

## Internal Behavior

- ESP32 operates in **STA mode**
- Connects to Wi-Fi at boot
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

| Feature    | Wi-Fi (this firmware) | BLE version |
| ---------- | --------------------- | ----------- |
| Throughput | High                  | Low–Medium  |
| Latency    | Medium                | Low         |
| Range      | Long                  | Short       |
| Power      | Higher                | Low         |
| Setup      | Requires Wi-Fi        | Very simple |

## Typical Use Cases

- High-speed debug console
- Data streaming (logs, sensors)
- Firmware communication bridge
- Replacement for USB-UART in embedded setups

## Notes

- This firmware is ideal when **throughput matters more than power**

- For mobile / low-power applications, prefer the BLE version

- Extensions possible:

  - STA + AP dual mode

  - UDP mode (lower latency)

  - TLS (secure TCP)

  - Multi-client support
