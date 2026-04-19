# ESP32 AT firmware

(c) 2025-2026, Edo. Franzi, 2026-04-17

## Packages used for building ESP32 WROOM applications

### 1. Add to environment :

```bash
IDF_PATH=${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/esp-idf-current
IDF_TOOLS_PATH=${IDF_PATH}/tools
ESP_PYTHON=/opt/local/bin/python

PATH=${PATH}:${IDF_PATH}
PATH=${PATH}:${IDF_PATH}/tools

export IDF_PATH
export IDF_TOOLS_PATH
```

### 2. Get the esp-idf & the AT firmware

```bash
cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32
./build.sh
```

### 3. Install esptool.py

```bash
pip install esptool
```

## Burn the new AT firmware

```bash
# From the Alastor console type
# esp32 -reset
# esp32 -boot

cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/Construction/Tools/
./firmware_AT.sh -erase

# From the Alastor console type
# esp32 -reset
# esp32 -boot

./firmware_AT.sh -burn
```

## Terminate: now configure for the uKOS-X usage

```bash
# Change the baudrate & set the wifi nework name
# From the Alastor console type
# esp32 -reset
# esp32 -connect 115200
# Now we should have access to the AT commandfs

AT+CWSAP="uKOS-X_wifi","",1,0,4,0
AT+UART_DEF=921600,8,1,0,1

# reset the board
# Launch the wfi0 console

console wfi0

# On the main computer select the wifi network uKOS-X_wifi
# On a terminal launch nc

nc 192.168.4.1 9999
```
