# ESP32 tools

(c) 2025-2026, Edo. Franzi, 2026-04-27

## Packages used for building ESP32 applications



### 1. Prepare the package

```bash
cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32
./build.sh
```

### 2. Add to environment :

This is necessary for working with all the esp32 packages. Ex. setup.sh, source setup.sh

```bash
# Set the esp32 tool paths
IDF_PATH="${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/esp-idf-current"
IDF_TOOLS_PATH="${IDF_PATH}/espressif-tools"
IDF_PYTHON_ENV_PATH="${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/Construction/Pyenv/esp32_Pyenv"

export IDF_PATH
export IDF_TOOLS_PATH
export IDF_PYTHON_ENV_PATH

source "${IDF_PYTHON_ENV_PATH}/bin/activate"
PYTHON="${IDF_PYTHON_ENV_PATH}/bin/python"
export PYTHON

eval "$("${PYTHON}" "${IDF_PATH}/tools/idf_tools.py" export --format shell)"
export PATH="${IDF_PATH}/tools:${PATH}"

echo "Set the esp32 environment path for the project: ${PROJECT}"
```

## Burn the new AT firmware

```bash
# Set-up the environment
source setup.sh

# From the Alastor console type
# esp32 -reset
# esp32 -boot
cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/esp32/Construction/Tools/
./firmware_AT.sh -erase

# From the Alastor console type
# esp32 -reset
# esp32 -boot
./firmware_AT.sh -burn

# Set the baudrate for the esp32 communications
# From the Alastor console type
# esp32 -reset
# esp32 -connect 115200
# Now we should have access to the AT commands
AT+UART_DEF=921600,8,1,0,1
```

### 1. Now configure for the uKOS-X usage (mode wifi)

```bash
# Change the baudrate & set the wifi nework name
# From the Alastor console type
# esp32 -reset
# esp32 -connect 921600
# Now we should have access to the AT commands

# Set the wifi name
AT+CWSAP="uKOS-X_wifi","",1,0,4,0

# reset the board
# Launch the wfi0 console
console wfi0

# On the main computer select the wifi network uKOS-X_wifi
# On a terminal launch nc
nc 192.168.4.1 9999
```

### 2. Now configure for the uKOS-X usage (mode Bluetooth)

```bash
# Change the baudrate & set the BT name
# From the Alastor console type
# esp32 -reset
# esp32 -connect 921600
# Now we should have access to the AT commands

# Initialisation
# and waiting for ready
AT+RST

AT
AT+CWMODE=0
AT+BLEINIT=0
AT+BLEINIT=2
AT+BLENAME="uKOS-X_AT_BLE"

# Create and start the GATT service
AT+BLEGATTSSRVCRE
AT+BLEGATTSSRVSTART

# Start the advertising
AT+BLEADVDATAEX="uKOS-X_AT_BLE","A002","0102030405",1
AT+BLEADVSTART

# On the iPhone we need the app "nRF Connect"
# scann
# Select uKOS-X_AT_BLE
# Connect
# Discover devices
#   0xC305 → Notify
#   0xC302 → Write

# On the esp32 we should receive
+BLECONN:0,"74:34:b5:9d:dc:d1"
+BLECFGMTU:0,517
+WRITE:0,1,6,1,2,..

# On the esp32 notify on 0xC305
AT+BLESPPCFG=1,1,6,1,3,1

# Activate the mode data
AT+BLESPP
OK
>

# Now we are in transparent mode; just type ...
uKOS-X forever
On the iPhone UUID C305 we should get value: 754B 4F53 ...

# On the iPhone type uKOS-X forever on the UUID C302 (UTF8)
# On the esp32 terminal we should receive 
uKOS-X forever
```

## Build and burn the ble_to_uart firmware

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

# From the Alastor console type
# esp32 -reset

esp32 -connect 460800
```

### 
