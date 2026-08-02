# tflite.
# =======

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2026-07-30
# Modifs:
#
# Project:	uKOS-X
# Goal:		TensorFlow Lite Micro integration for CMake builds
#
#			Reconstruct <name>.c_inc ("xxd -i" format)
#			from a committed <name>.xxd hex dump.
#
#			A temporary <name>.tflite is recreated first ("xxd -r") so
#			that "xxd -i"emits the historical symbol names <name>_tflite
#			/ <name>_tflite_len.
#
#			Requires (must be set before calling):
#				TARGET      - An existing target that compiles sources
#							  including the .c_inc
#
#			Usage example:
#				ukos_add_tflite_models(${TARGET_ELF} ${PATH_MYPR}/_Training/mlp_model.xxd)
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

function(ukos_add_tflite_models TARGET)
    set(GENERATED "")
    foreach(MODEL_XXD IN LISTS ARGN)
        if(NOT EXISTS "${MODEL_XXD}")
            message(FATAL_ERROR "ukos_add_tflite_models: TFLite model hex dump not found: ${MODEL_XXD}")
        endif()
        cmake_path(GET MODEL_XXD PARENT_PATH MODEL_DIR)
        cmake_path(GET MODEL_XXD STEM MODEL_NAME)
        set(MODEL_C_INC "${MODEL_DIR}/${MODEL_NAME}.c_inc")
        # The command works in a private temporary folder and atomically renames
        # the result, so that concurrent generations of the same model cannot
        # corrupt it (i.e. two build trees sharing the same source folder)
        add_custom_command(
            OUTPUT ${MODEL_C_INC}
            COMMAND sh -c "tmp=.gen_$$ && trap 'rm -rf \"$tmp\"' EXIT && mkdir \"$tmp\" && xxd -r ${MODEL_NAME}.xxd \"$tmp/${MODEL_NAME}.tflite\" && (cd \"$tmp\" && xxd -i ${MODEL_NAME}.tflite) > \"$tmp/${MODEL_NAME}.c_inc\" && mv -f \"$tmp/${MODEL_NAME}.c_inc\" ${MODEL_NAME}.c_inc"
            WORKING_DIRECTORY ${MODEL_DIR}
            DEPENDS ${MODEL_XXD}
            COMMENT "Generating ${MODEL_NAME}.c_inc"
            VERBATIM
        )
        list(APPEND GENERATED ${MODEL_C_INC})
    endforeach()
    if(GENERATED)
        add_custom_target(${TARGET}_tflite_models DEPENDS ${GENERATED})
        add_dependencies(${TARGET} ${TARGET}_tflite_models)
    endif()
endfunction()
