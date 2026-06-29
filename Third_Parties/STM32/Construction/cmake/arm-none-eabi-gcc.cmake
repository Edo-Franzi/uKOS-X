# -----------------------------------------------------------------------------
# Toolchain file: arm-none-eabi-gcc for STM32N657 (Cortex-M55)
# -----------------------------------------------------------------------------

set(CMAKE_SYSTEM_NAME       Generic)
set(CMAKE_SYSTEM_PROCESSOR  arm)

# ---------- toolchain prefix -------------------------------------------------
set(TOOLCHAIN_PREFIX "arm-none-eabi-")

# Optional: set TOOLCHAIN_PATH (via -DTOOLCHAIN_PATH=... or CMakeUserPresets.json)
# to the directory containing arm-none-eabi-* binaries.
# Falls back to searching PATH if not set.
set(TOOLCHAIN_PATH "" CACHE PATH "Directory containing arm-none-eabi-* binaries")

# Forward TOOLCHAIN_PATH into cmake's internal try_compile sub-projects so
# the toolchain file can find the cross-compiler there too.
list(APPEND CMAKE_TRY_COMPILE_PLATFORM_VARIABLES TOOLCHAIN_PATH)

find_program(CMAKE_C_COMPILER   ${TOOLCHAIN_PREFIX}gcc     HINTS "${TOOLCHAIN_PATH}" REQUIRED)
find_program(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}gcc     HINTS "${TOOLCHAIN_PATH}" REQUIRED)
find_program(CMAKE_OBJCOPY      ${TOOLCHAIN_PREFIX}objcopy HINTS "${TOOLCHAIN_PATH}" REQUIRED)
find_program(CMAKE_OBJDUMP      ${TOOLCHAIN_PREFIX}objdump HINTS "${TOOLCHAIN_PATH}" REQUIRED)
find_program(CMAKE_SIZE         ${TOOLCHAIN_PREFIX}size    HINTS "${TOOLCHAIN_PATH}" REQUIRED)

# ---------- CPU flags --------------------------------------------------------
# Cortex-M55: FPv5-D16 FPU, Helium (MVE), Thumb-2
# -mcmse: Enable ARMv8-M Security Extensions (TrustZone) support
set(MCU_FLAGS
    "-mcpu=cortex-m55"
    "-mfpu=fpv5-d16"
    "-mfloat-abi=hard"
    "-mthumb"
    "-mcmse"
)
list(JOIN MCU_FLAGS " " MCU_FLAGS_STR)

set(CMAKE_C_FLAGS_INIT   "${MCU_FLAGS_STR}")
set(CMAKE_ASM_FLAGS_INIT "${MCU_FLAGS_STR}")
set(CMAKE_EXE_LINKER_FLAGS_INIT
    "${MCU_FLAGS_STR} --specs=nosys.specs"
)

# ---------- search paths -----------------------------------------------------
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# ---------- skip compiler test (bare-metal, no OS) ---------------------------
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
