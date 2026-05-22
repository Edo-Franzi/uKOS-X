#!/usr/bin/env zsh

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen


#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Building all the uKOS downloadable applications.
#
#			usage:
#			./add_new_target.sh Target SOC Core [refTarget]
#
#			i.e
#			./add_new_target.sh XYZ_H743 STM32H743 CORTEX_M7 Nucleo_H743
#
#   (c) 2025-2026, Laurent von Allmen
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

set -euo pipefail

if [[ -z "${PATH_UKOS_X_PACKAGE:-}" ]]; then
	echo 'Variable PATH_UKOS_X_PACKAGE is not set!'
	exit 1
fi

# Save parameters

export new_target="${1}"
export soc_new_target="${2}"
export core_new_target="${3}"

# check for optional reference target to use as source for copy
if [[ $# -gt 3 ]]; then
	export reference_target="${4}"
fi

# Create a list of all folders in uKOS_Appls_Downloadable
root_dir="${PATH_UKOS_X_PACKAGE}/Applications/uKOS_Appls_Downloadable"
cd "${root_dir}"

# Family application list (a_Basics, b_MailBoxes, ...)
app_family_list=("${(@f)$(find . -mindepth 1 -maxdepth 1 -type d -exec basename {} \;)}")

for app_family in "${app_family_list[@]}"
do
    # We are in root_dir; app_family is for example a_Basics
    app_family_dir="${root_dir}/${app_family}"

    # Application list for this family
    app_list=("${(@f)$(cd "${app_family_dir}" && find . -mindepth 1 -maxdepth 1 -type d -exec basename {} \;)}")

    for app in "${app_list[@]}"
    do
        # Full directory for the application
        app_dir="${app_family_dir}/${app}"
        cd "${app_dir}"

        # Reference target (if provided)
        if [[ -z "${reference_target:-}" ]]; then
            echo "Using first target found as reference in ${app_dir}"

            target_list=("${(@f)$(find . -mindepth 1 -maxdepth 1 -type d -exec basename {} \;)}")
            if (( ${#target_list[@]} == 0 )); then
                echo "No targets found in ${app_dir}, skipping." >&2
                continue
            fi
            reference_target="${target_list[1]}"
        fi

        # Vérify that the reference target is here
        if [[ ! -d "${reference_target}" ]]; then
            echo "Reference target '${reference_target}' not found in ${app_dir}, skipping." >&2
            continue
        fi

        # Copy the reference target to the new one
        rm -fr "${new_target}"
        cp -r "${reference_target}" "${new_target}"
        cd "${new_target}"

        mv makefile makefile.bak
        sed -e 's/BOARD\(.*\)=  \(.*\)/BOARD\1=  ${new_target}/' \
            -e 's/SOC\(.*\)=  \(.*\)/SOC\1=  ${soc_new_target}/' \
            -e 's/CORE\(.*\)=  \(.*\)/CORE\1=  ${core_new_target}/' \
            makefile.bak | envsubst '"${new_target}" "${soc_new_target}" "${core_new_target}"' > makefile
        rm makefile.bak
    done
done
