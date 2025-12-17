# CMake Build System Guide

(c) 2025-20xx, Laurent von Allmen, 2025-01-01

This guide provides comprehensive instructions for building embedded system targets using CMake, supporting both GCC and LLVM toolchains with various configuration options.

## Prerequisites

Before using CMake, ensure the following environment variables are defined:

- `PATH_GCC_ARM` - Path to ARM GCC toolchain
- `PATH_GCC_RVXX` - Path to RISC-V GCC toolchain
- `PATH_LLVM_ARM` - Path to ARM LLVM toolchain
- `PATH_LLVM_RVXX` - Path to RISC-V LLVM toolchain

## Quick Start

The simplest way to build a target is to navigate to a **Variant** folder and configure the build:

```shell
mkdir build
cd build
cmake ..
make -j
make burn
```

### Complete Example: Nucleo_H743

```shell
cd ${PATH_UKOS_X_PACKAGE}/Ports/Nucleo_H743/Variant_Test
rm -fr build && mkdir build && cd build
cmake ..
make -j
make burn
```

## Build Configuration Options

CMake accepts several build options that control compilation behavior:

| Option | Default | Description |
|--------|---------|-------------|
| `-DWITH_LISTING=ON/OFF` | OFF | Generate listing and disassembly code from ELF file |
| `-DCANARY=ON/OFF` | ON | Enable/disable canary stack protection |
| `-DUSER_MODE=ON/OFF` | ON | Activate user mode of processor (code protection) |
| `-DUSE_LLVM=ON/OFF` | OFF | Use LLVM toolchain (clang) instead of GCC |
| `-DVERBOSE_LINK=ON/OFF` | OFF | Add verbose option (-v) when linking with lld |

## Using CMake Commands

CMake can handle the entire build process beyond just configuration.

### Advanced Configuration Example

To build a Nucleo_H743 system with user mode disabled and LLVM toolchain:

**Configure the project:**
```shell
cd ${PATH_UKOS_X_PACKAGE}/Ports/Nucleo_H743/Variant_Test
cmake -S . -B build -DUSER_MODE=OFF -DUSE_LLVM=ON
```

**Build the project:**
```shell
cmake --build build --parallel
```

**Program the processor:**
```shell
cmake --build build --target=burn
```

**Build and program in one command:**
```shell
cmake --build build --parallel --target=burn
```

**Clean and rebuild:**
```shell
cmake --build build --parallel --clean-first
```

## Out-of-Source Builds

Projects can be built in any directory outside the source tree:

```shell
cmake -S ${PATH_UKOS_X_PACKAGE}/Ports/Nucleo_H743/Variant_Test -B ${HOME}/mybuilds
cmake --build ${HOME}/mybuilds --parallel
```

Alternatively, you can use traditional make commands:

```shell
cmake -S ${PATH_UKOS_X_PACKAGE}/Ports/Nucleo_H743/Variant_Test -B ${HOME}/mybuilds
cd ${HOME}/mybuilds
make -j
```

## Build Presets

For convenience, common combinations of build options are available as presets:

```shell
cmake --list-presets
```

Available presets:
- `gcc` - Default GCC build
- `llvm` - Default LLVM build
- `gcc-nocanary` - GCC with user mode, no canary protection
- `gcc-nouser` - GCC without user mode, with canary protection
- `gcc-nouser-nocanary` - GCC without user mode or canary protection
- `llvm-nocanary` - LLVM with user mode, no canary protection
- `llvm-nouser` - LLVM without user mode, with canary protection
- `llvm-nouser-nocanary` - LLVM without user mode or canary protection

### Using Presets

Instead of specifying individual options:
```shell
cmake -B build -DUSE_LLVM=ON -DUSER_MODE=OFF
```

You can use a preset:
```shell
cmake --preset llvm-nouser
```

By default presets use Ninja, therefore there is no need to pass option `--parallel` to build a system.

## Build Types Summary

The build system supports two main execution modes:

**Privileged Mode:** All code runs with full processor privileges

```shell
cmake -B build -DUSER_MODE=OFF
```

**User Mode (default):** Enables code protection with separate user and system privileges

```shell
cmake -B build
```

which is equivalent to

```shell
cmake -B build -DUSER_MODE=ON
```

## Toolchain Selection

**GCC Toolchain (default):** Uses ARM/RISC-V GCC compilers

```shell
cmake -B build
```

which is equivalent to

```shell
cmake -B build -DUSE_LLVM=OFF
```

**LLVM Toolchain:** Uses Clang compilers for potentially better optimization
```shell
cmake -B build -DUSE_LLVM=ON
```

This build system provides flexible options for embedded development, supporting multiple architectures, toolchains, and security configurations to meet various project requirements.
