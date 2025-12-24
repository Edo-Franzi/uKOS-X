# config_install.
# ===============

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-01-01
# Modifs:	Edo. Franzi			The 2025-01-01
#
# Project:	uKOS-X
# Goal:		Prepare the environment to install the tools
#			for macOS & ubuntu machines (for the uKOS-X project)
#
#			Usage:
#			source config_install.sh
#
#   (c) 2025-20xx, Laurent von Allmen
#   ---------------------------------
#                                              __ ______  _____
#   Edo. Franzi                         __  __/ //_/ __ \/ ___/
#   5-Route de Cheseaux                / / / / ,< / / / /\__ \
#   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
#                                     \__,_/_/ |_\____//____/
#   edo.franzi@ukos.ch
#
#   Description: Lightweight, real-time multitasking operating
#   system for embedded microcontroller and DSP-based systems.
#
#   Permission is hereby granted, free of charge, to any person
#   obtaining a copy of this software and associated documentation
#   files (the "Software"), to deal in the Software without restriction,
#   including without limitation the rights to use, copy, modify,
#   merge, publish, distribute, sublicense, and/or sell copies of the
#   Software, and to permit persons to whom the Software is furnished
#   to do so, subject to the following conditions:
#
#   The above copyright notice and this permission notice shall be
#   included in all copies or substantial portions of the Software.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
#   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
#   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
#   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#   SOFTWARE.
#
#------------------------------------------------------------------------

if [[ -z "${PATH_TOOLS_ROOT:-}" ]]; then
	echo "ERROR: variable PATH_TOOLS_ROOT is not set!"
	return
fi

# check that the directory exists, if not create it

if [[ ! -d "${PATH_TOOLS_ROOT}" ]]; then
umask 002
sudo mkdir -p "${PATH_TOOLS_ROOT}"
sudo chgrp admin "${PATH_TOOLS_ROOT}"
case "$(uname)" in
	"Darwin")
		sudo chmod g+w "${PATH_TOOLS_ROOT}"
		;;
	"Linux")
		sudo chmod g+sw "${PATH_TOOLS_ROOT}"
		;;
esac
mkdir -p "${PATH_TOOLS_ROOT}"/local/bin
fi

# Get directory of the script

if [[ ${SHELL} == *"zsh"* ]]; then
	if [[ -n "${ZSH_VERSION-}" ]]; then
		PATH_SCRIPTS=${0:a:h}
	else
		PATH_SCRIPTS="$(cd "$(dirname "$0")" && pwd)"
	fi
elif [[ ${SHELL} == *"bash"* ]]; then
	PATH_SCRIPTS="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
else
	PATH_SCRIPTS="$(cd "$(dirname "$0")" && pwd)"
fi
export PATH_SCRIPTS

# Packages
# --------
#
# Edit this section to select the version of the source code for
# - binutils
# - gcc
# - newlib
# - gdb
# - llvm
# - gmp
# - mpfr
# - openocd
# - D2XX
# - libftdi
# - libusb
# - libconfuse
# - dfu-util
# - libjaylink
# - Cppcheck

# The following libraries are installed inside DIRLOCAL
# - D2XX
# - libftdi
# - libusb
# - libconfuse
# - gmp
# - mpfr

export BIN_VER=2.45.1
export GCC_ARM_VER=15.2.0
export GCC_RVXX_VER=15.2.0
export NLB_VER=4.5.0
export GDB_VER=17.1
export LLVM_ARM_VER=21.1.8
export LLVM_ARM_COMMIT=fc180f47
export LLVM_RVXX_VER=21.1.8
export LLVM_RVXX_COMMIT=b42e48a6
export GMP_VER=6.3.0
export MPFR_VER=4.2.2
export OPENOCD_VER=0.12.0
export D2XX_OSX_VER=1.4.30
export D2XX_LINUX_VER=1.4.34
export LIBFTDI_VER=1.5
export LIBUSB_VER=1.0.29
export LIBCONFUSE_VER=3.3
export DFUUTIL_VER=1.1
export LIBJAYLINK_VER=0.4.0
export DOXYGEN_VER=1.15.0
export GRAPHVIZ_VER=14.1.1
export CPPCHECK_VER=2.19.0

# Goodies
# Not used for the uKOS-X project

export GCC_ARC_VER=15.2.0
export BOOST_VER=1.90.0
export IMAGEMAGICK_VER=7.1.2-11
export PK2CMD_VER=1.27.01
export SDCC_VER=4.5.0
export SRECORD_VER=1.65
export GPUTILS_VER=1.5.2
export PICO_SDK_VER=2.2.0
export PICOTOOL_VER=2.2.0-a4

# Installation shall inherit group rights

umask 002

export PATH_TOOLS_GCC="${PATH_TOOLS_ROOT}"
export PATH_TOOLS_UNIX="${PATH_TOOLS_ROOT}"/local/bin

# Settings for gcc arm toolchain
# Settings for RISC-V toolchain
# Settings for LLVM arm toolchain

export PATH_GCC_ARM="${PATH_TOOLS_GCC}"/cross/gcc-${GCC_ARM_VER}/arm
export PATH_GCC_RVXX="${PATH_TOOLS_GCC}"/cross/gcc-${GCC_RVXX_VER}/riscv
export PATH_LLVM_ARM="${PATH_TOOLS_ROOT}"/cross/llvm-${LLVM_ARM_VER}/arm

PATH=${PATH}:${PATH_TOOLS_UNIX}

export PATH

# Choice of WGET
# --------------

case "$(uname)" in
	"Darwin")
		WGET=(curl -OL)
		;;
	*)
		WGET=(wget)
		;;
esac
readonly WGET

mkdir -p "${PATH_TOOLS_ROOT}"/Packages/,Sources
mkdir -p "${PATH_TOOLS_ROOT}"/Packages/,Archive

# Helper function:
# Move file to Archive only if it exists (do not fail on missing file)

move_to_archive () {
	# Move files matching a quoted glob pattern to ../,Archive/
	# Usage:
	#	move_to_archive "dummy-*"
	#	move_to_archive "data-*.tgz"
	#
	# The argument MUST be quoted so the pattern is passed literally.
	# Temporarily disable nomatch error for this function
	setopt local_options null_glob

	local pattern="${1}"
	local files=( ${~pattern} )	 # ~ forces zsh to expand pattern stored inside a variable

	# Move each matched file safely
	for file in "${files[@]}"; do
		[[ -e "$file" ]] && mv -- "$file" ../,Archive/
	done
}

# Environment validation
check_env() {
   setopt localoptions no_err_exit

   local missing_tools=()
   local errors=0

   # Check required commands
   local required_commands=(
      "git"
      "tar"
      "make"
      "cmake"
      "ninja"
      "cc"
      "cpp"
      "automake"
      "autoconf"
      "libtool"
      "pkg-config"
      "awk"
      "sed"
      "find"
      "xargs"
      "patch"
   )

   for cmd in "${required_commands[@]}"; do
      if ! command -v "$cmd" &>/dev/null; then
         missing_tools+=("$cmd")
         ((errors++))
      fi
   done

   # Check disk space (require at least 10GB free)
   local available_space_gb
   if [[ "$(uname -s)" == "Darwin" ]]; then
      available_space_gb=$(df -g "${PATH_TOOLS_ROOT}" | awk 'NR==2 {print $4}')
   else
      # Linux: use -BG for gigabyte blocks, strip the 'G' suffix
      available_space_gb=$(df -BG "${PATH_TOOLS_ROOT}" | awk 'NR==2 {print $4}' | tr -d 'G')
   fi
   if [[ $available_space_gb -lt 10 ]]; then
      echo "ERROR: Insufficient disk space. Need at least 10GB, have ${available_space_gb}GB"
      ((errors++))
   fi

   # Check write permissions
   if [[ ! -w "${PATH_TOOLS_ROOT}" ]]; then
      echo "ERROR: No write permission for ${PATH_TOOLS_ROOT}"
      ((errors++))
   fi

   # Check macOS specific requirements if on Darwin
   if [[ "$(uname -s)" == "Darwin" ]]; then
      if ! xcode-select -p &>/dev/null; then
         echo "ERROR: Xcode Command Line Tools not installed"
         echo "       Run: xcode-select --install"
         ((errors++))
      fi
   fi

   # Report findings
   if [[ ${#missing_tools[@]} -gt 0 ]]; then
      echo ""
      echo "ERROR: Missing required tools:"
      printf '  - %s\n' "${missing_tools[@]}"
   fi

   if [[ $errors -gt 0 ]]; then
      echo ""
      echo "Prerequisites check failed with $errors error(s)."
      echo "Please resolve the issues above before proceeding."
      exit 1
   fi
}

check_env
#       if ! command -v pkg-config >/dev/null 2>&1; then
#          missing_libs+=("pkg-config (required to detect gmp/mpfr on arm64)")
#          ((errors++))
#       else
#          local gmp_prefix mpfr_prefix
#
#          if gmp_prefix=$(get_lib_prefix gmp); then
#             typeset -g CFG_GMP="--with-gmp=${gmp_prefix}"
#          else
#             missing_libs+=("gmp (install via: brew install gmp OR port install gmp)")
#             ((errors++))
#          fi
#
#          if mpfr_prefix=$(get_lib_prefix mpfr); then
#             typeset -g CFG_MPFR="--with-mpfr=${mpfr_prefix}"
#          else
#             missing_libs+=("mpfr (install via: brew install mpfr OR port install mpfr)")
#             ((errors++))
#          fi
#       fi
