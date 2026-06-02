# Third-Party Notices — uKOS-X

(c) 2025-2026, Edo. Franzi, 2026-06-02



This project includes or may include third-party software components.
Each component remains under its original license. This file summarizes
the third-party components shipped in this repository.

> Scope:
> - This notice covers third-party code *vendored inside this repository* (e.g. `Third_Parties/`).
> - If you build firmware that also links vendor SDKs (e.g., STM32Cube), you must add those licenses/notices
>   in your final product distribution. See “Firmware builds” section below.

---

## 1) uKOS-X

- Project: uKOS-X
- Copyright: (c) Edo. Franzi and contributors
- License: MIT (see `LICENSE.md`)

---

## 2) Components vendored in this repository

### 2.1) Cppcheck
- Location: `Third_Parties/Cppcheck/`
- Upstream: https://github.com/danmar/cppcheck.git
- Version: 2.20.0
- License: GPL-3.0-or-later
- Copyright:
  -  See upstream project copyright notices in source headers.
- Notes: Development tool only (not linked into firmware binaries).

### 2.2) decnumber
- Location: `Third_Parties/decnumber/`
- Upstream: https://github.com/raitechnology/libdecnumber.git
- Version: 3.68 / commit a941bd3
- License: See `,LICENSES/License_DecNumbers.txt`
- Copyright:
  -  See upstream project copyright notices in source headers

### 2.3) Doxygen-awesome
- Location: `Third_Parties/Doxygen-awesome/`
- Upstream: https://github.com/jothepro/doxygen-awesome-css.git
- Version: 2.42
- License: MIT
- Copyright:
  -  Copyright (c) 2021 - 2023 jothepro

### 2.4) esp32

- Location: `Third_Parties/Tflite-micro/`
- Upstream: https://github.com/espressif/esp-idf.git
- Version: 6.0.1
- License: Apache-2.0
- Copyright:
  -  Copyright (c) 2016-2024, Espressif Systems (Shanghai) Co., Ltd.

### 2.5) FatFs

- Location: `Third_Parties/FatFs/`
- Upstream: https://github.com/abbrev/fatfs.git
- Version: 0.16 / commit 30ca13c
- License: FatFs (ChaN)
- Copyright:
  -  Copyright (c) 20xx, ChaN, all right reserved

### 2.6) IntelRDFPMath
- Location: `Third_Parties/IntelRDFPMath/`
- Upstream: https://github.com/xmake-mirror/IntelRDFPMathLib.git
- Version: 2.3 / commit ffca6d2
- License: Intel Corp.
- Copyright:
  -  Copyright (c) 2007-2024, Intel Corp.

### 2.7) LVGL
- Location: `Third_Parties/LVGL/`
- Upstream: https://github.com/lvgl/lvgl.git
- Version: 9.5.0
- License: MIT
- Copyright:
  -  Copyright (c) LVGL Kft and contributors

### 2.8) MicroPython
- Location: `Third_Parties/MicroPython/`
- Upstream: https://github.com/micropython/micropython.git
- Version: 1.28.0
- License: MIT
- Copyright:
  -  Copyright (c) 2013-2019 Damien P. George

### 2.9) Tflite-micro
- Location: `Third_Parties/Tflite-micro/`
- Upstream: https://github.com/tensorflow/tflite-micro.git
- Version: commit 730449f
- License: Apache-2.0
- Copyright:
  -  Copyright (c) 2020 The TensorFlow Authors. All rights reserved.

### 2.10) TinyUSB-micro
- Location: `Third_Parties/TinyUSB/`
- Upstream: https://github.com/hathach/tinyusb.git
- Version: 0.20.0 / commit f78715d
- License: MIT
- Copyright:
  -  Copyright (c) 2018, hathach (tinyusb.org)

## 3) External vendor SDKs (not included in this repository)

### 3.1) STM32Cube_FW_N6

- Upstream:  https://github.com/STMicroelectronics/STM32CubeN6.git
- Version: 1.3.0
- License: BSD-3-Clause
- Copyright:
  -  Copyright (c) 2024, STMicroelectronics
-  Notes: Not distributed in this repository.

### 3.2) Picotools

- Upstream:  https://github.com/raspberrypi/picotool.git
- Version: 2.2.0-a4
- License: BSD-3-Clause
- Copyright:
  - Copyright (c) 2020 Raspberry Pi (Trading) Ltd
- Notes: Not distributed in this repository.

### 3.3) Pico_SDK

- Upstream:  https://github.com/raspberrypi/pico-sdk.git
- Version: 2.2.0
- License: BSD-3-Clause
- Copyright:
  - Copyright (c) 2020 Raspberry Pi (Trading) Ltd
- Notes: Not distributed in this repository.
