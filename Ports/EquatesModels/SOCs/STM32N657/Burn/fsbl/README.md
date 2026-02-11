# STM32N657 FSBL - Build Instructions

(c) 2025-2026, Laurent von Allmen, 2026-02-11



This package contains a pre-configured First Stage Boot Loader (FSBL) project for the STM32N657 NUCLEO board in Load-and-Run mode.

**Key Feature:** This project builds directly from STM32CubeN6 sources without copying files, making it easy to update to new STM32Cube versions.

## What is this?

The FSBL is a bootloader that runs from AXISRAM2 (address 0x3418_0400) and copies your application from external NOR flash to internal SRAM before jumping to it. This is required because the STM32N657 has no internal flash.

## Prerequisites

Install the following tools:

| Tool | Version | Installation |
|------|---------|--------------|
| **arm-none-eabi-gcc** | 12+ | ARM GCC toolchain with Cortex-M55 support |
| **CMake** | 3.22+ | `brew install cmake` (macOS) or package manager |
| **Ninja** | Latest | `brew install ninja` (macOS) or package manager |
| **STM32CubeProgrammer** | 2.18+ | Download from [st.com](https://www.st.com/en/development-tools/stm32cubeprog.html) |
| **Git** | Any | For cloning STM32CubeN6 |

**Note:** You do NOT need STM32CubeIDE.

## Quick Start

### Option A: Use local STM32CubeN6 (inside project)

```bash
# 1. Extract this archive
tar -xzf stm32n657-fsbl.tar.gz
cd stm32n657-fsbl

# 2. Clone STM32CubeN6 inside the project
git clone --recursive --depth 1 \
    https://github.com/STMicroelectronics/STM32CubeN6.git

# 3. Configure
cmake --preset release

# 4. Build
cmake --build build/release
```

### Option B: Use shared STM32CubeN6 installation

```bash
# 1. Extract this archive
tar -xzf stm32n657-fsbl.tar.gz
cd stm32n657-fsbl

# 2. Point to your existing STM32CubeN6 installation
cmake --preset release -DCUBE_ROOT=/path/to/your/STM32CubeN6

# 3. Build
cmake --build build/release
```

### Option C: Use environment variable

```bash
# 1. Set STM32CubeN6 location once
export STM32CUBEN6_ROOT=/path/to/your/STM32CubeN6

# 2. Extract and configure
tar -xzf stm32n657-fsbl.tar.gz
cd stm32n657-fsbl
cmake --preset release

# 3. Build
cmake --build build/release
```

**Result:** `build/release/fsbl.bin` ready to flash at **0x70000000** (unsigned - will be signed by flash script)

## Detailed Setup Instructions

### 1. Extract the archive

```bash
tar -xzf stm32n657-fsbl.tar.gz
cd stm32n657-fsbl
```

### 2. Configure STM32CubeN6 location

You have **three options** for where STM32CubeN6 is located:

#### Option A: Inside the project (default)

Clone STM32CubeN6 directly into the project directory:

```bash
git clone --recursive --depth 1 \
    https://github.com/STMicroelectronics/STM32CubeN6.git
```

⚠️ **Important:** The `--recursive` flag is mandatory to get CMSIS submodules.

Structure:
```
stm32n657-fsbl/
├── STM32CubeN6/           # Cloned here
├── fsbl/                  # Your FSBL application
├── CMakeLists.txt
└── ...
```

#### Option B: Shared installation (via CMake variable)

If you have STM32CubeN6 installed elsewhere (e.g., shared across projects):

```bash
# No need to clone - just point to existing installation
cmake --preset release -DCUBE_ROOT=/path/to/your/STM32CubeN6
```

**Benefits:**
- Share one STM32CubeN6 across multiple projects
- Save disk space
- Easier to update centrally

#### Option C: Shared installation (via environment variable)

Set once in your shell profile (`~/.bashrc`, `~/.zshrc`):

```bash
export STM32CUBEN6_ROOT=/path/to/your/STM32CubeN6
```

Then just use standard build commands - it will automatically find STM32CubeN6.

### 3. Build

```bash
# Configure (Release build - unsigned by default)
cmake --preset release

# Build
cmake --build build/release
```

The unsigned `fsbl.bin` will be generated in `build/release/`.

**Note:** The release build produces an unsigned binary by default. Your flash script will sign it on-the-fly when programming. If you need a pre-signed binary for testing, use the `release-signed` preset instead:

```bash
cmake --preset release-signed
cmake --build build/release-signed
# Output: build/release-signed/fsbl-trusted.bin
```

### Alternative: Manual configuration

```bash
# Default location (inside project)
cmake -B build -DCMAKE_BUILD_TYPE=Release -G Ninja

# Custom location
cmake -B build -DCMAKE_BUILD_TYPE=Release -G Ninja \
    -DCUBE_ROOT=/path/to/STM32CubeN6

cmake --build build
```

## Binary Signing

The FSBL binary can be built in two modes:

### Default: Unsigned (Recommended)

```bash
cmake --preset release
cmake --build build/release
# Output: fsbl.bin (unsigned)
```

**Use this when:** Your flash script signs binaries during programming (typical workflow).

### Optional: Pre-signed

```bash
cmake --preset release-signed
cmake --build build/release-signed
# Output: fsbl-trusted.bin (pre-signed)
```

**Use this when:** You need to test the signed binary directly or distribute pre-signed binaries.

**Behind the scenes:** The signing process uses `STM32_SigningTool_CLI` to add the trusted header (v2.3) required by the STM32N657 secure boot.

## Build Artifacts

After a successful build, you'll find in `build/release/`:

- `fsbl.elf` - ELF executable with debug symbols
- **`fsbl.bin`** - Unsigned binary (default) ⭐
- `fsbl.hex` - Intel HEX format
- `fsbl.map` - Linker map file

**Optional:** If using `release-signed` preset:
- `fsbl-trusted.bin` - Pre-signed binary (only if built with `--preset release-signed`)

## Using the FSBL with Your Firmware

### Memory Layout

| Component | Flash Address | Size |
|-----------|---------------|------|
| **FSBL** (this project) | 0x7000_0000 | ~32 KB |
| **Your Application** | 0x7000_8000 | (depends on your app) |

### Programming Sequence

1. Program FSBL: `fsbl.bin` at address `0x70000000` (your flash script will sign it automatically)
2. Program your application at `0x70008000` (or as configured)
3. Set boot switches to External flash mode
4. Reset the board

**Note:** The unsigned `fsbl.bin` is sufficient - your flash script handles signing during programming.

### Boot Switch Configuration

| Mode | BOOT0 | BOOT1 | Use Case |
|------|-------|-------|----------|
| DEV (debug) | — | 2-3 | For flashing via SWD |
| External flash | 1-2 | 1-2 | Normal boot from flash |

## Updating to New STM32CubeN6 Versions

This is the key advantage of this project structure!

```bash
cd STM32CubeN6
git pull
git submodule update --init --recursive
cd ..
cmake --build build/release --clean-first
```

That's it! The build system automatically uses the updated drivers.

## Configuration

### Critical Configuration Files

#### 1. `fsbl/inc/stm32_extmem_conf.h`

**Most important setting:**

```c
#define EXTMEM_LRUN_SOURCE_SIZE  (your_application_size_in_bytes)
```

⚠️ This MUST match your application binary size. Default is 64 KB, which may be too small.

#### 2. `fsbl/inc/stm32n6xx_hal_conf.h`

Controls which HAL modules are enabled. Typically doesn't need modification.

### Adding HAL Drivers

If you need additional HAL drivers:

1. Enable in `fsbl/inc/stm32n6xx_hal_conf.h`: `#define HAL_XXX_MODULE_ENABLED`
2. Add to `CMakeLists.txt` in the `HAL_SOURCES` section:
   ```cmake
   ${CUBE_ROOT}/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_xxx.c
   ```

No file copying needed - it references STM32CubeN6 directly!

## Troubleshooting

### Error: "STM32CubeN6 not found"

You need to clone STM32CubeN6 in the project directory:

```bash
git clone --recursive --depth 1 \
    https://github.com/STMicroelectronics/STM32CubeN6.git
```

### Error: "CMSIS submodules not initialized"

The CMSIS headers weren't downloaded:

```bash
cd STM32CubeN6
git submodule update --init --recursive
cd ..
```

### Build fails with "undefined reference to HAL_XXX"

You need to add the corresponding HAL driver to `CMakeLists.txt` (see "Adding HAL Drivers" above).

### Binary too large (> 511 KB)

The FSBL must fit in AXISRAM2 (511 KB). If it's too large:

- Remove unused HAL drivers from `CMakeLists.txt`
- Verify you're using Release build (`--preset release`)
- Review and minimize code

### Application doesn't boot after FSBL

Check that `EXTMEM_LRUN_SOURCE_SIZE` in `fsbl/inc/stm32_extmem_conf.h` is set to your actual application size (or larger).

## Project Structure

```
stm32n657-fsbl/
├── CMakeLists.txt              # Build configuration (references STM32CubeN6)
├── CMakePresets.json           # Build presets (debug/release)
├── TEAM_README.md              # This file
├── CLAUDE.md                   # Detailed technical documentation
├── README.md                   # Project overview (French)
│
├── cmake/
│   └── arm-none-eabi-gcc.cmake # Toolchain definition
│
├── fsbl/                       # FSBL application (project-specific)
│   ├── src/                    # Your FSBL source code
│   │   ├── main.c
│   │   ├── extmem.c
│   │   ├── stm32n6xx_hal_msp.c
│   │   ├── stm32n6xx_it.c
│   │   └── system_stm32n6xx_fsbl.c
│   └── inc/                    # Your FSBL headers
│       ├── main.h
│       ├── stm32n6xx_hal_conf.h     # ⚠️ HAL configuration
│       └── stm32_extmem_conf.h      # ⚠️ ExtMem configuration
│
├── startup/                    # Startup code (device-specific)
│   └── startup_stm32n657xx.s
│
├── linker/                     # Linker script
│   └── STM32N657XX_AXISRAM2_fsbl.ld
│
├── scripts/
│   ├── sign_fsbl.sh            # Sign the binary (manual)
│   └── flash_fsbl.sh           # Flash to board
│
└── STM32CubeN6/               # ⚠️ Clone this separately (not in archive)
    ├── Drivers/                # HAL, CMSIS, BSP (referenced by build)
    ├── Middlewares/            # ExtMem Manager (referenced by build)
    └── ...
```

## What's NOT in the Archive

The archive is intentionally small (~100 KB) because it doesn't include:

- ❌ `STM32CubeN6/` - You clone this separately (3+ GB)
- ❌ `build/` - Generated during build
- ❌ Copied driver files - Project references them from STM32CubeN6

This makes it easy to:
- Update to new STM32Cube versions (just `git pull` in STM32CubeN6)
- Share the project (small archive size)
- Track only project-specific changes

## Configuring STM32CubeN6 Location

The build system supports multiple ways to specify where STM32CubeN6 is located (in priority order):

### 1. CMake command line (highest priority)

```bash
cmake --preset release -DCUBE_ROOT=/path/to/STM32CubeN6
# OR
cmake -B build -DCUBE_ROOT=/path/to/STM32CubeN6
```

**Use case:** Override per-project, temporary testing

### 2. Environment variable

```bash
export STM32CUBEN6_ROOT=/path/to/STM32CubeN6
cmake --preset release
```

**Use case:** Team-wide standard location, set in shell profile

### 3. Default location (lowest priority)

```bash
# Project expects: ./STM32CubeN6/
cmake --preset release
```

**Use case:** Self-contained project, each project has its own copy

### Examples

```bash
# Use company-wide shared installation
export STM32CUBEN6_ROOT=/opt/st/STM32CubeN6
cmake --preset release

# Override for testing a different version
cmake --preset release -DCUBE_ROOT=/home/user/STM32CubeN6-dev

# Use project-local copy (clone it first)
git clone --recursive --depth 1 \
    https://github.com/STMicroelectronics/STM32CubeN6.git
cmake --preset release
```

## Additional Resources

- **CLAUDE.md** - Comprehensive documentation for working with this codebase
- **README.md** - Original project description (French)
- [STM32N6 FSBL explained](https://community.st.com/t5/stm32-mcus/stm32n6-fsbl-explained/ta-p/764307)
- [How to create an STM32N6 FSBL](https://community.st.com/t5/stm32-mcus/how-to-create-an-stm32n6-fsbl-load-and-run/ta-p/768206)
- [STM32CubeN6 GitHub](https://github.com/STMicroelectronics/STM32CubeN6)

## Quick Reference

```bash
# Full build from scratch
tar -xzf stm32n657-fsbl.tar.gz
cd stm32n657-fsbl
git clone --recursive --depth 1 https://github.com/STMicroelectronics/STM32CubeN6.git
cmake --preset release
cmake --build build/release

# Output: build/release/fsbl.bin (unsigned - flash script will sign it)
```

```bash
# Rebuild after code changes
cmake --build build/release

# Clean rebuild
cmake --build build/release --clean-first

# Update STM32CubeN6 to latest version
cd STM32CubeN6 && git pull && git submodule update --init --recursive && cd ..
cmake --build build/release --clean-first
```
