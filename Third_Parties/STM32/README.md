# STM32 for uKOS-X (v.1.0)

(c) 2025-2026, Edo. Franzi, 2026-07-26

## Prepare the setup.sh (source setup.sh)

```bash
# Locate the top package
PROJECT=OS_Kernel-X

# Prepare some useful paths
PATH_UKOS_ROOT=The_package_location
PATH_UKOS_X_PACKAGE="${PATH_UKOS_ROOT}/${PROJECT}"
PATH_SCRIPTS="${PATH_UKOS_X_PACKAGE}/Ports/Tools/Scripts"

# Special location to some ST tool/package
STM32_PRG_PATH="/Applications/STMicroelectronics/STM32Cube/STM32CubeProgrammer \
                /STM32CubeProgrammer.app/Contents/MacOs/bin"
STM32_NEURAL_ART="${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6 \
                  /STEdgeAI/4.0/Utilities/macarm"

# Set the uKOS-X paths

export	PROJECT
export	PATH_UKOS_ROOT
export	PATH_UKOS_X_PACKAGE
export	PATH_SCRIPTS
export	STM32_PRG_PATH
export	STM32_NEURAL_ART

PATH="${STM32_NEURAL_ART}:${PATH}"

```

## STM32N657

```bash
STM32
├── README.md
└── STM32N6
    ├── build.sh
    ├── Construction
    │   ├── AI
    │   │   └── gan_npu
    │   │       ├── build.sh
    │   │       ├── mapping
    │   │       │   ├── neural_art_ukos.json
    │   │       │   └── stm32n6_ukos_psram.mpool
    │   └── fsbl
    │       ├── cmake
    │       │   └── arm-none-eabi-gcc.cmake
    │       ├── CMakeLists.txt
    │       ├── CMakePresets.json
    │       ├── fsbl
    │       │   ├── inc
    │       │   │   ├── aps256xx_conf.h
    │       │   │   ├── extmem.h
    │       │   │   ├── main.h
    │       │   │   ├── mx25um51245g_conf.h
    │       │   │   ├── mx66uw1g45g_conf.h
    │       │   │   ├── stm32_extmem_conf.h
    │       │   │   ├── stm32n6570_discovery_conf.h
    │       │   │   ├── stm32n6xx_hal_conf.h
    │       │   │   ├── stm32n6xx_it.h
    │       │   │   └── stm32n6xx_nucleo_conf.h
    │       │   └── src
    │       │       ├── extmem.c
    │       │       ├── main.c
    │       │       ├── stm32n6xx_hal_msp.c
    │       │       ├── stm32n6xx_it.c
    │       │       └── system_stm32n6xx_fsbl.c
    │       ├── linker
    │       │   └── STM32N657XX_AXISRAM2_fsbl.ld
    │       └── startup
    │           └── startup_stm32n657xx.s
    ├── Library
    │   ├── AI
    │   │   └── gan_npu
    │   └── fsbl
    │       ├── fsbl_discovery.noSignature
    │       └── fsbl_nucleo.noSignature
    ├── STEdgeAI
    │   ├── ...
    └── STM32CubeN6
        ├── ...
```

### Building the FSBL for the STM32N657

```bash
cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6
./build.sh
```

### Install the STEdgeAI package

```bash
# Follow the instruction for the installation
# The package should be installed here
# "${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/STEdgeAI

https://www.st.com/en/development-tools/stedgeai-core.html
```

### Conversion of a .tflite file to npu ressources (example gan_npu)

```bash
cd ${PATH_UKOS_X_PACKAGE}/Third_Parties/STM32/STM32N6/Construction/AI/gan_npu
./build.sh
```

