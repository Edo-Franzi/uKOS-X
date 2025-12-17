# 🌈  Annex G, cross toolchains

## The gcc compiler

**macOS** is now a UNIX-compliant operating system, which means the use of GCC toolchains is fully supported. Below are the necessary steps for building **Cortex-Mx**, and **RISC-V** cross-compilers on macOS hosts. The same procedure applies when working on Ubuntu.

Since µKOS-X is built around a **µKernel**, it supports multitasking, allowing multiple programs to run concurrently. As a result, **newlib** must be configured with support for **reentrant system calls** to ensure thread-safe behaviour.

### Special compiler setting-up for RISC-V

Working with **µKOS-X** requires the use of a compiler that supports **multilibs** — specifically, both standard and FPU-enabled variants. The compiler's behaviour regarding **multilib** generation is defined in the **t-elf-multilib** file. This configuration ensures that all necessary libraries are generated for the selected targets.

For ARM architectures, this process is handled automatically via a patch applied during the creation of the cross-compiler.

To enable similar support for RISC-V, the **t-elf-multilib** file located at:

```
 ${PATH_TOOLS_GCC}/Packages/gcc-15.2.0/gcc/config/riscv/
```

should be modified as follows:

```bash
MULTILIB_OPTIONS    =
MULTILIB_DIRNAMES   =
MULTILIB_REQUIRED   =

# Useful RISC-V combinations for RV32:

MULTILIB_OPTIONS    += march=rv32i/march=rv32im/march=rv32imafd/march=rv32iac/
                       march=rv32imac/march=rv32imafc
MULTILIB_DIRNAMES   += rv32i rv32im rv32imafd rv32iac rv32imac rv32imafc

# Useful RISC-V combinations for RV64:

MULTILIB_OPTIONS    += march=rv64i/march=rv64ia/march=rv64im/march=rv64if/
                       march=rv64ifd/march=rv64iaf/march=rv64iac/march=rv64iafd/
                       march=rv64imafd/march=rv64imf/march=rv64imac/march=rv64imaf/
                       march=rv64imafc/march=rv64imafdc
MULTILIB_DIRNAMES   += rv64i rv64ia rv64im rv64if rv64ifd rv64iaf rv64iac
                       rv64iafd rv64imafd rv64imf rv64imac rv64imaf rv64imafc
                       rv64imafdc

# Supported ABI:

MULTILIB_OPTIONS    += mabi=ilp32/mabi=ilp32f/mabi=ilp32d/mabi=lp64/mabi=lp64f/
                       mabi=lp64d
MULTILIB_DIRNAMES   += ilp32 ilp32f ilp32d lp64 lp64f lp64d

MULTILIB_OPTIONS    += mcmodel=medany
MULTILIB_DIRNAMES   += medany

# RISC-V, RV32 supported combinations:

MULTILIB_REQUIRED   += march=rv32i/mabi=ilp32
MULTILIB_REQUIRED   += march=rv32im/mabi=ilp32
MULTILIB_REQUIRED   += march=rv32imafd/mabi=ilp32d
MULTILIB_REQUIRED   += march=rv32iac/mabi=ilp32
MULTILIB_REQUIRED   += march=rv32imac/mabi=ilp32
MULTILIB_REQUIRED   += march=rv32imafc/mabi=ilp32f

# RISC-V, RV64 supported combinations:

MULTILIB_REQUIRED   += march=rv64i/mabi=lp64
MULTILIB_REQUIRED   += march=rv64i/mabi=lp64/mcmodel=medany
MULTILIB_REQUIRED   += march=rv64ia/mabi=lp64
MULTILIB_REQUIRED   += march=rv64ia/mabi=lp64/mcmodel=medany
MULTILIB_REQUIRED   += march=rv64im/mabi=lp64
MULTILIB_REQUIRED   += march=rv64im/mabi=lp64/mcmodel=medany
MULTILIB_REQUIRED   += march=rv64if/mabi=lp64f
MULTILIB_REQUIRED   += march=rv64if/mabi=lp64f/mcmodel=medany
MULTILIB_REQUIRED   += march=rv64ifd/mabi=lp64d
MULTILIB_REQUIRED   += march=rv64ifd/mabi=lp64d/mcmodel=medany
MULTILIB_REQUIRED   += march=rv64iaf/mabi=lp64f
MULTILIB_REQUIRED   += march=rv64iaf/mabi=lp64f/mcmodel=medany
MULTILIB_REQUIRED   += march=rv64iac/mabi=lp64
MULTILIB_REQUIRED   += march=rv64iac/mabi=lp64/mcmodel=medany
MULTILIB_REQUIRED   += march=rv64iafd/mabi=lp64d
MULTILIB_REQUIRED   += march=rv64iafd/mabi=lp64d/mcmodel=medany
MULTILIB_REQUIRED   += march=rv64imafd/mabi=lp64d
MULTILIB_REQUIRED   += march=rv64imafd/mabi=lp64d/mcmodel=medany
MULTILIB_REQUIRED   += march=rv64imf/mabi=lp64f
MULTILIB_REQUIRED   += march=rv64imf/mabi=lp64f/mcmodel=medany
MULTILIB_REQUIRED   += march=rv64imac/mabi=lp64
MULTILIB_REQUIRED   += march=rv64imac/mabi=lp64/mcmodel=medany
MULTILIB_REQUIRED   += march=rv64imaf/mabi=lp64f
MULTILIB_REQUIRED   += march=rv64imaf/mabi=lp64f/mcmodel=medany
MULTILIB_REQUIRED   += march=rv64imafc/mabi=lp64f
MULTILIB_REQUIRED   += march=rv64imafc/mabi=lp64f/mcmodel=medany
MULTILIB_REQUIRED   += march=rv64imafdc/mabi=lp64d
MULTILIB_REQUIRED   += march=rv64imafdc/mabi=lp64d/mcmodel=medany
```

### Building the packages in this order

Launch a terminal.

```bash
# Enter into the Scripts folder:
cd ${PATH_SCRIPTS}

# Build the gmp and mpfr library (needed by gdb):
./ukos_gmp.sh
./ukos_mpfr.sh

# Build the gcc ARM cortex and RISC-V toolchain:
# this step takes many hours
./ukos_gnu_gcc_arm_eabi.sh
./ukos_gnu_gcc_riscv_elf.sh

# Build the llvm ARM cortex and RISC-V toolchain:
# this step takes many hours
./ukos_clang_llvm_arm_eabi.sh
./ukos_clang_llvm_riscv_elf.sh

# Build the D2XX driver:
./ukos_D2XX.sh

# Build the libftdi, libusb, lib confuse & libjaylink:
./ukos_libForOpenocd.sh

# Build the openocd:
./ukos_openocd_cortex.sh
./ukos_openocd_stm.sh
./ukos_openocd_riscv.sh

# Build the doxygen and graphviz:
./ukos_doxygen.sh
./ukos_graphviz.sh

# Build the Cppcheck:
./ukos_cppcheck.sh

# Build the dfu_util:
./ukos_dfu-util.sh

# Build the picotool:
./ukos_picotool.sh
```

### Script for building gcc ARM cross-compilers

```bash
#!/usr/bin/env zsh

# ukos_gnu_gcc_arm_eabi.
# ======================

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:     Edo. Franzi    The 2025-01-01
# Modifs:
#
# Project:    uKOS-X
# Goal:       Toolchain for generating generic gcc cross compilers
#             for UNIX like machines (for the uKOS-X project)
#
#             ARM (cortex M3-M4-M7-M23-M33-A7) family
#
#             Usage:
#             ./ukos_gnu_gcc_arm_eabi.sh
#
#             OS:
#             OSX 26.xx           yes
#             Ubuntu 24.04 LTS    yes
#
#   (c) 2025-20xx, Edo. Franzi
#   --------------------------
#                                              __ ______  _____
#   Edo. Franzi                         __  __/ //_/ __ \/ ___/
#   5-Route de Cheseaux                / / / / ,< / / / /\__ \
#   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
#                                     \__,_/_/ |_\____//____/
#   edo.franzi@ukos.ch
#
#   See the MIT License (License_uKOS-X.txt)
#
#------------------------------------------------------------------------

# Source the configuration file from the same directory
source "$(dirname "$0")"/config_install.sh

set -euo pipefail

# Choice of the native compiler
# -----------------------------

# For OSX, the native compiler is LLVM
# For Ubuntu, the native compiler is gcc

case "$(uname)" in
    "Darwin")
        echo "Target OSX clang"
        export CC=clang
        export CXX=clang++
        export PARALLEL_JOBS=$(( $(sysctl -n hw.ncpu) - 1 ))
        ;;
    "Linux")
        echo "Target Linux"
        export PARALLEL_JOBS=4
        ;;
esac

# Target
# ------

export TARGET=arm-none-eabi
export MACHINE=arm
export GCC_VER="${GCC_ARM_VER}"

# Environment
# -----------

export PACKS_GCC="${PATH_TOOLS_GCC}"/Packages/gcc-"${GCC_VER}"
export PACKS_BIN="${PATH_TOOLS_GCC}"/Packages/binutils-"${BIN_VER}"
export PACKS_NBL="${PATH_TOOLS_GCC}"/Packages/newlib-"${NLB_VER}"
export PACKS_GDB="${PATH_TOOLS_GCC}"/Packages/gdb-"${GDB_VER}"

export PATCH="${PATH_SCRIPTS}"/Patches
export BUILD="${PATH_TOOLS_GCC}"/builds/gcc-"${GCC_VER}"
export CROSS="${PATH_TOOLS_GCC}"/cross/gcc-"${GCC_VER}"

export prefix="${CROSS}"/"${MACHINE}"
export executables="${prefix}"/bin

build_machine="${BUILD}"/"${MACHINE}"
readonly LOG_FILE="${build_machine}"/gnu_gcc_arm_temp.txt

PATH="${executables}":"${PATH}"

# Downloading sources
# -------------------

cd "${PATH_TOOLS_ROOT}"/Packages/,Sources

if [[ ! -f "binutils-${BIN_VER}.tar.bz2" ]]; then
    echo Downloading binutils-${BIN_VER}
    move_to_archive 'binutils-*'
    "${WGET[@]}" http://gnu.mirror.constant.com/binutils/binutils-"${BIN_VER}".tar.bz2
fi

if [[ ! -f "gdb-${GDB_VER}.tar.gz" ]]; then
    echo Downloading gdb-${GDB_VER}
    move_to_archive 'gdb-*'
    "${WGET[@]}" ftp://ftp.gnu.org/pub/gnu/gdb/gdb-"${GDB_VER}".tar.gz
fi

cd ..
echo Extracting binutils sources
tar xjf ,Sources/binutils-${BIN_VER}.tar.bz2

echo Extracting gdb sources
tar xzf ,Sources/gdb-${GDB_VER}.tar.gz

if [[ ! -d gcc-${GCC_VER} ]]; then
    echo Downloading gcc-${GCC_VER}
    git clone git://gcc.gnu.org/git/gcc.git "gcc-${GCC_VER}"
    git -C gcc-"${GCC_VER}" fetch --tags
    git -C gcc-"${GCC_VER}" checkout tags/releases/gcc-${GCC_VER}
    cd "gcc-${GCC_VER}"
    ./contrib/download_prerequisites
    if [[ -d "Patches/gcc/${GCC_VER}" ]]; then
        for file in Patches/gcc/${GCC_VER}; do
            patch -p1 < "$file"
        done
    fi
    cd ..
fi

if [[ ! -d newlib-"${NLB_VER}" ]]; then
    echo Downloading newlib-${NLB_VER}
    git clone https://sourceware.org/git/newlib-cygwin.git "newlib-${NLB_VER}"
    git -C newlib-"${NLB_VER}" fetch --tags
    git -C newlib-"${NLB_VER}" checkout tags/newlib-${NLB_VER}
fi

# Configurations
# --------------

export BIN_CONFIG=" \
    --enable-interwork"
GCC1_CONFIG=" \
    --disable-shared \
    --disable-nls \
    --disable-threads \
    --disable-tls \
    --enable-checking=release \
    --enable-languages=c \
    --without-cloog \
    --without-isl \
    --with-newlib \
    --without-headers \
    --with-gnu-as \
    --with-gnu-ld \
    --with-multilib-list=aprofile,rmprofile"
export GCC1_CONFIG
GCC2_CONFIG=" \
    --disable-shared \
    --disable-nls \
    --disable-threads \
    --disable-tls \
    --enable-checking=release \
    --enable-languages=c,c++ \
    --without-cloog \
    --without-isl \
    --with-newlib \
    --with-headers=yes \
    --with-gnu-as \
    --with-gnu-ld \
    --with-multilib-list=aprofile,rmprofile"
export GCC2_CONFIG
export NLB_CONFIG=" \
    --enable-newlib-interwork \
    --enable-newlib-io-long-long \
    --enable-newlib-io-float"
export GDB_CONFIG=" \
    --enable-interwork"

# Building the toolchain
# ----------------------

rm -rf "${build_machine}"
rm -rf "${CROSS}"/"${MACHINE}"
mkdir -p "${build_machine}"

echo "Start of build: $(date)" > "${LOG_FILE}"

cd "${PACKS_GCC}"

# Uncomment the following 2 lines if the script is used as a stand-alone script
# (without using download_essential)
#
./contrib/download_prerequisites
"${PATH_SCRIPTS}"/_gnu_gcc_patch.sh

"${PATH_SCRIPTS}"/_gnu_binutils_build.sh
if [[ ! -f "${build_machine}"/gnu_binutils_ready.txt ]]; then
    echo "Failed to build binutils"
    exit 1
fi
cat "${build_machine}"/gnu_binutils_ready.txt >> "${LOG_FILE}"
"${PATH_SCRIPTS}"/_gnu_gcc_pass1_build.sh
if [[ ! -f "${build_machine}"/gnu_gcc_pass1_ready.txt ]]; then
    echo "Failed to complete pass 1 for gcc"
    exit 1
fi
cat "${build_machine}"/gnu_gcc_pass1_ready.txt >> "${LOG_FILE}"
"${PATH_SCRIPTS}"/_newlib_build.sh
if [[ ! -f "${build_machine}"/newlib_ready.txt ]]; then
    echo "Failed to build newlib"
    exit 1
fi
cat "${build_machine}"/newlib_ready.txt >> "${LOG_FILE}"
"${PATH_SCRIPTS}"/_gnu_gcc_pass2_build.sh
if [[ ! -f "${build_machine}"/gnu_gcc_pass2_ready.txt ]]; then
    echo "Failed to complete pass 2 for gcc"
    exit 1
fi
cat "${build_machine}"/gnu_gcc_pass2_ready.txt >> "${LOG_FILE}"
"${PATH_SCRIPTS}"/_gnu_gdb_build.sh
if [[ ! -f "${build_machine}"/gnu_gdb_ready.txt ]]; then
    echo "Failed to build gdb"
    exit 1
fi
cat "${build_machine}"/gnu_gdb_ready.txt >> "${LOG_FILE}"

# Strip the binaries

find "${CROSS}"/${MACHINE}/arm-none-eabi -name "lib*.a" \
    -exec "${CROSS}"/${MACHINE}/bin/arm-none-eabi-strip --strip-unneeded {} \;

# Update path links

current_dir="${PATH_TOOLS_ROOT}"/cross/gcc-current
if [[ ! -d "${current_dir}" ]]; then
    mkdir "${current_dir}"
fi
cd "${current_dir}"
rm -f "${MACHINE}"
ln -s ../gcc-"${GCC_VER}"/"${MACHINE}" "${MACHINE}"

echo "End of build:      $(date)" >> "${LOG_FILE}"
mv "${LOG_FILE}" "${build_machine}"/gnu_gcc_arm_ready.txt
```

###  Intermediate scripts for building the binutils, gcc, newlib and gdb

#### Patch gcc

```bash
readonly log_file="${BUILD}"/"${MACHINE}"/gnu_gcc_patch_temp.txt

echo "Start patch gcc: $(date)" > "${log_file}"

if [[ -d "${PATH_SCRIPTS}"/Patches/gcc/"${GCC_VER}" ]]; then
    for file in "${PATH_SCRIPTS}"/Patches/gcc/"${GCC_VER}"/*; do
        patch -Np1 < "$file"
    done
fi

echo "End patch gcc:   $(date)" >> "${log_file}"
mv "${log_file}" "${BUILD}"/"${MACHINE}"/gnu_gcc_patch_ready.txt
```

#### Binutils

```bash
readonly build_machine="${BUILD}"/"${MACHINE}"
readonly log_file="${build_machine}"/gnu_binutils_temp.txt

echo "Start building binutils: $(date)" > "${log_file}"

mkdir -p "${build_machine}"/binutils-"${BIN_VER}"
cd "${build_machine}"/binutils-"${BIN_VER}"
"${PACKS_BIN}"/configure \
    --target="${TARGET}" \
    --prefix="${prefix}" \
    --enable-multilib \
    --disable-werror \
    --disable-nls \
    --disable-libssp \
    --with-system-zlib \
    ${=BIN_CONFIG}                         || { echo "Error configuring binutils";   exit 1; }
make -j ${PARALLEL_JOBS}                   || { echo "Error building binutils";      exit 1; }
make install-strip                         || { echo "Error installing binutils";    exit 1; }
make clean                                 || { echo "Error cleaning binutils";      exit 1; }

echo "End building binutils:   $(date)" >> "${log_file}"
mv "${log_file}" "${build_machine}"/gnu_binutils_ready.txt
```

#### gcc pass 1

```bash
readonly build_machine="${BUILD}"/"${MACHINE}"
readonly log_file="${build_machine}"/gnu_gcc_pass1_temp.txt

echo "Start gcc pass 1: $(date)" > "${log_file}"

mkdir -p "${build_machine}"/gcc-"${GCC_VER}"
cd "${build_machine}"/gcc-"${GCC_VER}"
case "$(uname)" in
    "Darwin")
        CFLAGS="-O2 -fbracket-depth=1024 -pipe"
        CXXFLAGS="-O2 -fbracket-depth=1024 -pipe"
        "${PACKS_GCC}"/configure \
            --target="${TARGET}" \
            --prefix="${prefix}" \
            --with-native-system-header-dir="${CROSS}"/"${MACHINE}"/"${TARGET}"/include \
            --with-sysroot \
            --with-headers="${PACKS_NBL}"/newlib/libc/include \
            --with-system-zlib \
            --disable-werror \
            --disable-libgloss \
            --disable-libssp \
            ${=GCC1_CONFIG}                || { echo "Error configuring gcc pass 1"; exit 1; }
        make CXXFLAGS="-fbracket-depth=1024" \
        all-gcc -j "${PARALLEL_JOBS}"      || { echo "Error building gcc pass 1";    exit 1; }
        make install-gcc                   || { echo "Error installing gcc pass 1";  exit 1; }
        ;;
    "Linux")
        "${PACKS_GCC}"/configure \
            --target="${TARGET}" \
            --prefix="${prefix}" \
            --with-native-system-header-dir="${CROSS}"/"${MACHINE}"/"${TARGET}"/include \
            --with-sysroot= \
            --with-system-zlib \
            --disable-werror \
            --disable-libgloss \
            --disable-libssp \
            ${=GCC1_CONFIG}                || { echo "Error configuring gcc pass 1"; exit 1; }
        make all-gcc -j "${PARALLEL_JOBS}" || { echo "Error building gcc pass 1";    exit 1; }
        make install-gcc                   || { echo "Error installing gcc pass 1";  exit 1; }
        ;;
esac

echo "End gcc pass 1:    $(date)" >> "${log_file}"
mv "${log_file}" "${build_machine}"/gnu_gcc_pass1_ready.txt
```

#### gcc pass 2

```bash
readonly log_file="${BUILD}"/"${MACHINE}"/gnu_gcc_pass2_temp.txt

echo "Start gcc pass 2: $(date)" > "${log_file}"

cd "${BUILD}"/"${MACHINE}"/gcc-"${GCC_VER}"
case "$(uname)" in
    "Darwin")
        "${PACKS_GCC}"/configure \
                  --target="${TARGET}" \
                  --prefix="${prefix}" \
                  --with-native-system-header-dir="${CROSS}"/"${MACHINE}"/"${TARGET}"/include \
                  --with-sysroot \
                  --with-system-zlib \
                  --enable-multilib \
                  --disable-werror \
                  --disable-libgloss \
                  --disable-libssp \
                  ${=GCC2_CONFIG}          || { echo "Error configuring gcc pass 2"; exit 1; }
            make CXXFLAGS="-fbracket-depth=1024" \
                -j "${PARALLEL_JOBS}"      || { echo "Error building gcc pass 2";    exit 1; }
            make install-strip             || { echo "Error installing gcc pass 2";  exit 1; }
            make clean                     || { echo "Error cleaning gcc pass 2";    exit 1; }
            ;;
    "Linux")
            "${PACKS_GCC}"/configure \
                  --target="${TARGET}" \
                  --prefix="${prefix}" \
                  --with-native-system-header-dir="${CROSS}"/"${MACHINE}"/"${TARGET}"/include \
                  --with-sysroot \
                  --with-system-zlib \
                  --enable-multilib \
                  --disable-werror \
                  --disable-libgloss \
                  --disable-libssp \
                  ${=GCC2_CONFIG}          || { echo "Error configuring gcc pass 2"; exit 1; }
            make -j "${PARALLEL_JOBS}"     || { echo "Error building gcc pass 2";    exit 1; }
            make install-strip             || { echo "Error installing gcc pass 2";  exit 1; }
            make clean                     || { echo "Error cleaning gcc pass 2";    exit 1; }
            ;;
esac

echo "End gcc pass 2:    $(date)" >> "${log_file}"
mv "${log_file}" "${BUILD}"/"${MACHINE}"/gnu_gcc_pass2_ready.txt
```

#### gcc (for all the CPUs)

```bash
readonly build_machine="${BUILD}"/"${MACHINE}"
readonly log_file="${build_machine}"/gnu_gcc_temp.txt

echo "Start building gcc: $(date)" > "${log_file}"

mkdir -p "${BUILD}"/"${MACHINE}"/gcc-${GCC_VER}
cd "${BUILD}"/"${MACHINE}"/gcc-${GCC_VER}
"${PACKS_GCC}"/configure \
    --target="${TARGET}" \
      --prefix="${prefix}" \
      --enable-shared \
      --enable-multilib \
      --enable-target-optspace \
      --disable-nls \
      --disable-libssp \
      --with-gnu-as \
      --with-gnu-ld \
      "${GCC_CONFIG}"                      || { echo "Error configuring gcc";        exit 1; }
make -j "${PARALLEL_JOBS}"                 || { echo "Error building gcc";           exit 1; }
make install-strip                         || { echo "Error installing gcc";         exit 1; }
make clean                                 || { echo "Error cleaning gcc";           exit 1; }

echo "End building gcc:   $(date)" >> "${log_file}"
mv "${log_file}" "${build_machine}"/gnu_gcc_ready.txt
```

#### newlib

```bash
readonly build_machine="${BUILD}"/"${MACHINE}"
readonly log_file="${build_machine}"/newlib_temp.txt

echo "Start building newlib: $(date)" > "${log_file}"

mkdir -p "${build_machine}"/newlib-"${NLB_VER}"
cd "${build_machine}"/newlib-"${NLB_VER}"
"${PACKS_NBL}"/configure \
    --target="${TARGET}" \
      --prefix="${prefix}" \
      --enable-multilib \
      --disable-werror \
      --disable-nls \
      --disable-libssp \
      ${=NLB_CONFIG}                       || { echo "Error configuring newlib";     exit 1; }
make -j ${PARALLEL_JOBS}                   || { echo "Error building newlib";        exit 1; }
make install                               || { echo "Error installing newlib";      exit 1; }
make clean                                 || { echo "Error cleaning newlib";        exit 1; }

echo "End building newlib:     $(date)" >> "${log_file}"
mv "${log_file}" "${build_machine}"/newlib_ready.txt
```

#### gdb

```bash
readonly build_machine="${BUILD}"/"${MACHINE}"
readonly log_file="${build_machine}"/gnu_gdb_temp.txt

echo "Start building gdb: $(date)" > "${log_file}"

readonly DIRLOCAL="${PATH_TOOLS_ROOT}"/local

mkdir -p "${build_machine}"/gdb-"${GDB_VER}"
cd "${build_machine}"/gdb-"${GDB_VER}"
"${PACKS_GDB}"/configure CFLAGS="-I${DIRLOCAL}/include \
    -L${DIRLOCAL}/lib" CXXFLAGS="-I${DIRLOCAL}/include -L${DIRLOCAL}/lib" \
    --target="${TARGET}" \
      --prefix="${prefix}" \
      --enable-multilib \
      --with-system-zlib \
      --disable-werror \
      --disable-nls \
      --disable-libssp \
    ${=GDB_CONFIG}                         || { echo "Error configuring gdb";        exit 1; }
make -j "${PARALLEL_JOBS}"                 || { echo "Error building gdb";           exit 1; }
make install                               || { echo "Error installing gdb";         exit 1; }
make clean                                 || { echo "Error cleaning gdb";           exit 1; }

echo "End building gdb:      $(date)" >> "${log_file}"
mv "${log_file}" "${build_machine}"/gnu_gdb_ready.txt
```
