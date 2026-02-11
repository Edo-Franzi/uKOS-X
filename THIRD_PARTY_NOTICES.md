# Third-Party Notices — uKOS-X

(c) 2025-2026, Edo. Franzi, 2026-02-11



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
- Version: 2.19.0
- License: GPL-3.0-or-later
- Copyright:
  -  See upstream project copyright notices in source headers.
- Notes: Development tool only (not linked into firmware binaries).

### 2.2) decnumber
- Location: `Third_Parties/decnumber/`
- Upstream: https://github.com/raitechnology/libdecnumber.git
- Version: 3.68 / commit ace3fa6
- License: See `,LICENSES/License_DecNumbers.txt`
- Copyright:
  -  See upstream project copyright notices in source headers

### 2.3) Doxygen-awesome
- Location: `Third_Parties/Doxygen-awesome/`
- Upstream: https://github.com/jothepro/doxygen-awesome-css.git
- Version: 3.41
- License: MIT
- Copyright:
  -  Copyright (c) 2021 - 2023 jothepro

### 2.4) FatFs
- Location: `Third_Parties/FatFs/`
- Upstream: https://github.com/abbrev/fatfs.git
- Version: 0.16 / commit 30ca13c
- License: FatFs (ChaN)
- Copyright:
  -  Copyright (c) 20xx, ChaN, all right reserved

### 2.5) IntelRDFPMath
- Location: `Third_Parties/IntelRDFPMath/`
- Upstream: https://github.com/xmake-mirror/IntelRDFPMathLib.git
- Version: 2.3 / commit ffca6d2
- License: Intel Corp.
- Copyright:
  -  Copyright (c) 2007-2024, Intel Corp.

### 2.6) LVGL
- Location: `Third_Parties/LVGL/`
- Upstream: https://github.com/lvgl/lvgl.git
- Version: 9.4.0
- License: MIT
- Copyright:
  -  Copyright (c) LVGL Kft and contributors

### 2.7) MicroPython
- Location: `Third_Parties/MicroPython/`
- Upstream: https://github.com/micropython/micropython.git
- Version: 1.27.0
- License: MIT
- Copyright:
  -  Copyright (c) 2013-2019 Damien P. George

### 2.8) Tflite-micro
- Location: `Third_Parties/Tflite-micro/`
- Upstream: https://github.com/tensorflow/tflite-micro.git
- Version: commit 510a6c5
- License: Apache-2.0
- Copyright:
  -  Copyright (c) 2020 The TensorFlow Authors. All rights reserved.

### 2.9) TinyUSB-micro
- Location: `Third_Parties/TinyUSB/`
- Upstream: https://github.com/hathach/tinyusb.git
- Version: 0.20.0 / commit e416a81
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
