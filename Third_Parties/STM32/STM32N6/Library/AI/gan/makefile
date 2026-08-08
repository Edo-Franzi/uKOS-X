# makefile.
# =========

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Edo. Franzi

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2026-08-02
# Modifs:
#
# Project:	uKOS-X
# Goal:		makefile for uKOS-X systems (gan_npu part).
#
#   (c) 2025-2026, Edo. Franzi
#   --------------------------
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

SHELL				= /bin/bash

ifndef PATH_UKOS_X_PACKAGE
$(error PATH_UKOS_X_PACKAGE is not defined)
endif
ifndef PATH_GCC_ARM
$(error PATH_GCC_ARM is not defined)
endif

PATH_UKOS					=  $(PATH_UKOS_X_PACKAGE)
PATH_COMPILER				=  $(PATH_GCC_ARM)
LIBRARY						=  libNN_Hardware
NN							=  gan

PATH_MAKE					:= $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
PATH_PROJECT				=  $(abspath $(PATH_MAKE)/../../../Construction/AI/network/$(LIBRARY))
PATH_STM32N6				=  $(abspath $(PATH_PROJECT)/../../../..)
PATH_NETWORK				=  $(PATH_STM32N6)/Library/AI/$(NN)
PATH_ST_AI_WS				=  $(PATH_NETWORK)/st_ai_ws
PATH_GENERATED				=  $(PATH_ST_AI_WS)/neural_art__network
PATH_PREBUILT				=  $(PATH_ST_AI_WS)/build_rt_network
PATH_STEDGEAI				=  $(PATH_STM32N6)/STEdgeAI/4.0
PATH_OUTPUT					=  $(PATH_STM32N6)/Library/AI/$(NN)
PATH_BUILD					=  $(PATH_NETWORK)/build

ARCHIVE						=  $(PATH_OUTPUT)/$(LIBRARY).a
PUBLIC_HEADER				=  $(PATH_OUTPUT)/$(LIBRARY).h

# Official non-PIC Cortex-M55 GCC runtime supplied by ST

LIB_ST_RUNTIME				=  $(lastword $(sort $(wildcard $(PATH_STEDGEAI)/Middlewares/ST/AI/Lib/GCC/ARMCortexM55/NetworkRuntime*_CM55_GCC.a)))

# ST public headers

HEADER_STM32N6				=  $(firstword $(shell find "$(PATH_STM32N6)"													  -type f -name stm32n6xx.h			 2>/dev/null))
HEADER_CORE_CM55			=  $(firstword $(shell find "$(PATH_STM32N6)"													  -type f -name core_cm55.h			 2>/dev/null))
HEADER_HAL_STM32N6			=  $(firstword $(shell find "$(PATH_STEDGEAI)/Projects/STM32N6570-DK/Applications/Drivers"		  -type f -name stm32n6xx_hal.h		 2>/dev/null))
HEADER_HAL_CNF_STM32N6		=  $(firstword $(shell find "$(PATH_STEDGEAI)/Projects/STM32N6570-DK/Applications/NPU_Validation" -type f -name stm32n6xx_hal_conf.h 2>/dev/null))

INCLUDES_STM32N6XX			=  $(patsubst %/,%,$(dir $(HEADER_STM32N6)))
INCLUDES_CORE_CMSIS			=  $(patsubst %/,%,$(dir $(HEADER_CORE_CM55)))
INCLUDES_HAL_STM32N6		=  $(patsubst %/,%,$(dir $(HEADER_HAL_STM32N6)))
INCLUDES_HAL_CNF_STM32N6	=  $(patsubst %/,%,$(dir $(HEADER_HAL_CNF_STM32N6)))

PATH_INCLUDES				+= -I$(PATH_PROJECT)/include
PATH_INCLUDES				+= -I$(PATH_GENERATED)
PATH_INCLUDES				+= -I$(PATH_STEDGEAI)/Middlewares/ST/AI/Npu/ll_aton
PATH_INCLUDES				+= -I$(PATH_STEDGEAI)/Middlewares/ST/AI/Npu/Devices/STM32N6xx
PATH_INCLUDES				+= -I$(PATH_STEDGEAI)/Middlewares/ST/AI/Npu/Inc
PATH_INCLUDES				+= -I$(PATH_STEDGEAI)/Middlewares/ST/AI/Inc
PATH_INCLUDES				+= -I$(INCLUDES_STM32N6XX)
PATH_INCLUDES				+= -I$(INCLUDES_CORE_CMSIS)
PATH_INCLUDES				+= -I$(INCLUDES_HAL_STM32N6)
PATH_INCLUDES				+= -I$(INCLUDES_HAL_CNF_STM32N6)

# Sources & objects

SRC_WRAPPER					=  $(PATH_PROJECT)/src/$(LIBRARY).c
SRC_NETWORK					=  $(PATH_GENERATED)/network.c
SRC_LL_ATON					=  $(PATH_STEDGEAI)/Middlewares/ST/AI/Npu/ll_aton/ll_aton.c
SRC_LL_ATON_RUNTIME			=  $(PATH_STEDGEAI)/Middlewares/ST/AI/Npu/ll_aton/ll_aton_runtime.c
SRC_STAI_INTERNAL			=  $(PATH_STEDGEAI)/Middlewares/ST/AI/Npu/ll_aton/ll_aton_stai_internal.c
SRC_MCU_CACHE				=  $(PATH_STEDGEAI)/Middlewares/ST/AI/Npu/Devices/STM32N6xx/mcu_cache.c
SRC_NPU_CACHE				=  $(PATH_STEDGEAI)/Middlewares/ST/AI/Npu/Devices/STM32N6xx/npu_cache.c
SRC_HAL_CACHEAXI			=  $(PATH_STEDGEAI)/Projects/STM32N6570-DK/Applications/Drivers/STM32N6xx_HAL_Driver/Src/stm32n6xx_hal_cacheaxi.c
SRC_HAL_STUB_GET_TICK		=  $(PATH_PROJECT)/src/stub_halGetTick.c

OBJ_WRAPPER					=  $(PATH_BUILD)/$(LIBRARY).o
OBJ_NETWORK					=  $(PATH_BUILD)/network.o
OBJ_LL_ATON					=  $(PATH_BUILD)/ll_aton.o
OBJ_LL_ATON_RUNTIME			=  $(PATH_BUILD)/ll_aton_runtime.o
OBJ_STAI_INTERNAL			=  $(PATH_BUILD)/ll_aton_stai_internal.o
OBJ_MCU_CACHE				=  $(PATH_BUILD)/mcu_cache.o
OBJ_NPU_CACHE				=  $(PATH_BUILD)/npu_cache.o
OBJ_HAL_CACHEAXI			=  $(PATH_BUILD)/stm32n6xx_hal_cacheaxi.o
OBJ_HAL_STUB_GET_TICK		=  $(PATH_BUILD)/stub_halGetTick.o

OBJ							=  $(OBJ_WRAPPER)
OBJ							+= $(OBJ_NETWORK)
OBJ							+= $(OBJ_LL_ATON)
OBJ							+= $(OBJ_LL_ATON_RUNTIME)
OBJ							+= $(OBJ_STAI_INTERNAL)
OBJ							+= $(OBJ_MCU_CACHE)
OBJ							+= $(OBJ_NPU_CACHE)
OBJ							+= $(OBJ_HAL_CACHEAXI)
OBJ							+= $(OBJ_HAL_STUB_GET_TICK)

SCRIPT_MRI					=  $(PATH_BUILD)/combine.mri
PATH_RUNTIME_EXTRACT		=  $(PATH_BUILD)/runtime_without_ll_aton
RUNTIME_EXTRACT_STAMP		=  $(PATH_RUNTIME_EXTRACT)/.extracted

# Compiler

PREFIX						?= arm-none-eabi-
CC							=  $(PATH_COMPILER)/bin/$(PREFIX)gcc
AR							=  $(PATH_COMPILER)/bin/$(PREFIX)ar
NM							=  $(PATH_COMPILER)/bin/$(PREFIX)nm
OBJDUMP						=  $(PATH_COMPILER)/bin/$(PREFIX)objdump

FLAGS_FP					?= -mfloat-abi=hard -mfpu=fpv5-sp-d16
CPU_SPEC					?= -march=armv8.1-m.main+mve.fp+fp.dp -mthumb

# Compiler flags

CFLAGS						+= $(CPU_SPEC) $(FLAGS_FP)
CFLAGS						+= -O2 -ffunction-sections -fdata-sections
CFLAGS						+= $(PATH_INCLUDES)
CFLAGS						+= -MMD -MP

CFLAGS						+= -DSTM32N657xx
CFLAGS						+= -DLL_ATON_PLATFORM=LL_ATON_PLAT_STM32N6
CFLAGS						+= -DLL_ATON_OSAL=LL_ATON_OSAL_BARE_METAL
CFLAGS						+= -DLL_ATON_RT_MODE=1
CFLAGS						+= -std=c23

CFLAGS						+= -Wall
CFLAGS						+= -Wextra
CFLAGS						+= -Werror=return-type

# Keep generated network/NPU objects, but exclude the standalone ST demo,
# startup and C-library adaptation objects owned by uKOS-X.

EXCLUDED_NAMES				=  ll_aton.o
EXCLUDED_NAMES				+= ll_aton_runtime.o
EXCLUDED_NAMES				+= startup_stm32xx.o
EXCLUDED_NAMES				+= startup_stm32n657xx.o
EXCLUDED_NAMES				+= main.o
EXCLUDED_NAMES				+= stedgeai_app_main.o
EXCLUDED_NAMES				+= syscalls.o
EXCLUDED_NAMES				+= sysmem.o
EXCLUDED_NAMES				+= network.o

OBJ_ST_PREBUILT				=  $(sort $(wildcard $(PATH_PREBUILT)/*.o))
OBJ_ST_ALL					=  $(filter-out $(addprefix $(PATH_PREBUILT)/,$(EXCLUDED_NAMES)),$(OBJ_ST_PREBUILT))

REQUIRED_STAI_SYMBOLS		=  stai_runtime_init
REQUIRED_STAI_SYMBOLS		+= __ll_aton_stai_init_network_instance
REQUIRED_STAI_SYMBOLS		+= __ll_aton_stai_deinit_network_instance
REQUIRED_STAI_SYMBOLS		+= __ll_aton_stai_run
REQUIRED_STAI_SYMBOLS		+= __ll_aton_stai_reset
REQUIRED_STAI_SYMBOLS		+= __ll_aton_stai_get_execution_status
REQUIRED_STAI_SYMBOLS		+= __ll_aton_stai_set_execution_status
REQUIRED_STAI_SYMBOLS		+= _stai_aton_internal_epoch_block_callback
REQUIRED_STAI_SYMBOLS		+= mcu_cache_clean_range
REQUIRED_STAI_SYMBOLS		+= mcu_cache_invalidate_range
REQUIRED_STAI_SYMBOLS		+= npu_cache_clean_range
REQUIRED_STAI_SYMBOLS		+= npu_cache_clean_invalidate_range
REQUIRED_STAI_SYMBOLS		+= HAL_CACHEAXI_Init
REQUIRED_STAI_SYMBOLS		+= HAL_CACHEAXI_Enable
REQUIRED_STAI_SYMBOLS		+= HAL_CACHEAXI_Disable
REQUIRED_STAI_SYMBOLS		+= HAL_CACHEAXI_DeInit
REQUIRED_STAI_SYMBOLS		+= HAL_CACHEAXI_Invalidate
REQUIRED_STAI_SYMBOLS		+= HAL_CACHEAXI_CleanByAddr
REQUIRED_STAI_SYMBOLS		+= HAL_CACHEAXI_CleanInvalidByAddr
REQUIRED_STAI_SYMBOLS		+= HAL_GetTick

REQUIRED_LIB_SYMBOLS		=  nn_hardware_init
REQUIRED_LIB_SYMBOLS		+= nn_hardware_deinit
REQUIRED_LIB_SYMBOLS		+= nn_hardware_putInput
REQUIRED_LIB_SYMBOLS		+= nn_hardware_inference
REQUIRED_LIB_SYMBOLS		+= nn_hardware_getOutput

.PHONY: all check clr_all clr build archive install symbols remove print-config

all :
	@$(MAKE)	clr_all
	$(MAKE)		check
	$(MAKE)		build
	$(MAKE)		archive
	$(MAKE)		install
	$(MAKE)		symbols
	$(MAKE)		remove
	@$(MAKE)	clr

# Check

check :
	@test -x "$(CC)"														|| { echo "ERROR: compiler not found: $(CC)";								exit 1; }
	@test -x "$(AR)"														|| { echo "ERROR: archiver not found: $(AR)";								exit 1; }
	@test -x "$(NM)"														|| { echo "ERROR: nm not found: $(NM)";										exit 1; }
	@test -x "$(OBJDUMP)"													|| { echo "ERROR: objdump not found: $(OBJDUMP)";							exit 1; }
	@test -f "$(PATH_GENERATED)/stai_network.h"								|| { echo "ERROR: missing $(PATH_GENERATED)/stai_network.h";				exit 1; }
	@test -n "$(HEADER_STM32N6)" -a -f "$(HEADER_STM32N6)"					|| { echo "ERROR: stm32n6xx.h not found below $(PATH_STM32N6)";				exit 1; }
	@test -n "$(HEADER_CORE_CM55)" -a -f "$(HEADER_CORE_CM55)"				|| { echo "ERROR: core_cm55.h not found below $(PATH_STM32N6)";				exit 1; }
	@test -n "$(HEADER_HAL_STM32N6)" -a -f "$(HEADER_HAL_STM32N6)"			|| { echo "ERROR: stm32n6xx_hal.h not found";								exit 1; }
	@test -n "$(HEADER_HAL_CNF_STM32N6)" -a -f "$(HEADER_HAL_CNF_STM32N6)"	|| { echo "ERROR: stm32n6xx_hal_conf.h not found";							exit 1; }
	@test -n "$(OBJ_ST_ALL)"												|| { echo "ERROR: no ST objects found in $(PATH_PREBUILT)";					exit 1; }
	@test -n "$(LIB_ST_RUNTIME)" -a -f "$(LIB_ST_RUNTIME)"					|| { echo "ERROR: official ST NetworkRuntime CM55 GCC archive not found";	exit 1; }
	@test -f "$(SRC_WRAPPER)"												|| { echo "ERROR: missing $(SRC_WRAPPER)";									exit 1; }
	@test -f "$(SRC_NETWORK)"												|| { echo "ERROR: missing $(SRC_NETWORK)";									exit 1; }
	@test -f "$(SRC_LL_ATON)"												|| { echo "ERROR: missing $(SRC_LL_ATON)";									exit 1; }
	@test -f "$(SRC_LL_ATON_RUNTIME)"										|| { echo "ERROR: missing $(SRC_LL_ATON_RUNTIME)";							exit 1; }
	@test -f "$(SRC_STAI_INTERNAL)"											|| { echo "ERROR: missing $(SRC_STAI_INTERNAL)";							exit 1; }
	@test -f "$(SRC_MCU_CACHE)"												|| { echo "ERROR: missing $(SRC_MCU_CACHE)";								exit 1; }
	@test -f "$(SRC_NPU_CACHE)"												|| { echo "ERROR: missing $(SRC_NPU_CACHE)";								exit 1; }
	@test -f "$(SRC_HAL_CACHEAXI)"											|| { echo "ERROR: missing $(SRC_HAL_CACHEAXI)";								exit 1; }
	@test -f "$(SRC_HAL_STUB_GET_TICK)"										|| { echo "ERROR: missing $(SRC_HAL_STUB_GET_TICK)";						exit 1; }

# Clean

clr_all :
	@rm -rf $(PATH_BUILD)
	@rm -f $(ARCHIVE) $(PUBLIC_HEADER)

clr :
	@rm -rf $(PATH_BUILD)

# Build

build : $(OBJ) $(OBJ_ST_ALL) $(RUNTIME_EXTRACT_STAMP)

$(PATH_BUILD) :
	@mkdir -p $@

$(OBJ_WRAPPER): $(SRC_WRAPPER) $(PATH_PROJECT)/include/$(LIBRARY).h | $(PATH_BUILD)
	@echo "Compiling $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_NETWORK): $(SRC_NETWORK) | $(PATH_BUILD)
	@echo "Compiling $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_LL_ATON): $(SRC_LL_ATON) | $(PATH_BUILD)
	@echo "Compiling $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_LL_ATON_RUNTIME): $(SRC_LL_ATON_RUNTIME) | $(PATH_BUILD)
	@echo "Compiling $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_STAI_INTERNAL): $(SRC_STAI_INTERNAL) | $(PATH_BUILD)
	@echo "Compiling $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_MCU_CACHE): $(SRC_MCU_CACHE) | $(PATH_BUILD)
	@echo "Compiling $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_NPU_CACHE): $(SRC_NPU_CACHE) | $(PATH_BUILD)
	@echo "Compiling $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_HAL_CACHEAXI): $(SRC_HAL_CACHEAXI) | $(PATH_BUILD)
	@echo "Compiling $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_HAL_STUB_GET_TICK): $(SRC_HAL_STUB_GET_TICK) | $(PATH_BUILD)
	@echo "Compiling $(notdir $<)"
	$(CC) $(CFLAGS) -c $< -o $@

# Extract the official runtime and discard its generic LL_ATON objects.

$(RUNTIME_EXTRACT_STAMP): $(LIB_ST_RUNTIME) | $(PATH_BUILD)
	@rm -rf "$(PATH_RUNTIME_EXTRACT)"
	@mkdir -p "$(PATH_RUNTIME_EXTRACT)"
	@cd "$(PATH_RUNTIME_EXTRACT)" && "$(AR)" x "$(LIB_ST_RUNTIME)"
	@rm -f "$(PATH_RUNTIME_EXTRACT)/ll_aton.o" "$(PATH_RUNTIME_EXTRACT)/ll_aton_runtime.o" "$(PATH_RUNTIME_EXTRACT)/stai_internal.o" "$(PATH_RUNTIME_EXTRACT)/ll_aton_stai_internal.o"
	@touch "$@"

# Archive

archive : $(SCRIPT_MRI)
	@mkdir -p $(dir $(ARCHIVE))
	@rm -f $(ARCHIVE)
	$(AR) -M < $(SCRIPT_MRI)
	@test -f $(ARCHIVE) || { echo "ERROR: archive was not created: $(ARCHIVE)"; exit 1; }
	@echo "Created: $(ARCHIVE)"

$(SCRIPT_MRI): $(OBJ) $(OBJ_ST_ALL) $(RUNTIME_EXTRACT_STAMP) | $(PATH_BUILD)
	@{ \
		echo "CREATE $(ARCHIVE)"; \
		find "$(PATH_RUNTIME_EXTRACT)" -maxdepth 1 -type f -name '*.o' -print | LC_ALL=C sort | while IFS= read -r obj; do echo "ADDMOD $$obj"; done; \
		for obj in $(OBJ_ST_ALL); do echo "ADDMOD $$obj"; done; \
		for obj in $(OBJ); do echo "ADDMOD $$obj"; done; \
		echo "SAVE"; \
		echo "END"; \
	} > "$@"

# Install

install : $(PATH_PROJECT)/include/$(LIBRARY).h
	@mkdir -p $(dir $(PUBLIC_HEADER))
	@cp $< $(PUBLIC_HEADER)
	@echo "Installed: $(PUBLIC_HEADER)"

# Symbols

symbols : $(ARCHIVE)
	@set -e; \
	defs="$$($(NM) -g --defined-only '$(ARCHIVE)')"; \
	for symbol in $(REQUIRED_LIB_SYMBOLS) $(REQUIRED_STAI_SYMBOLS); do \
		echo "$$defs" | grep -Eq "[[:space:]][TDBR][[:space:]]+$$symbol$$" || { echo "ERROR: final archive does not define $$symbol"; exit 1; }; \
	done; \
	count="$$($(AR) t '$(ARCHIVE)' | grep -xc 'network.o')"; \
	[ "$$count" -eq 1 ] || { echo "ERROR: final archive contains $$count network.o members"; exit 1; }; \
	count="$$($(AR) t '$(ARCHIVE)' | grep -xc 'll_aton.o')"; \
	[ "$$count" -eq 1 ] || { echo "ERROR: final archive contains $$count ll_aton.o members"; exit 1; }; \
	count="$$($(AR) t '$(ARCHIVE)' | grep -xc 'll_aton_runtime.o')"; \
	[ "$$count" -eq 1 ] || { echo "ERROR: final archive contains $$count ll_aton_runtime.o members"; exit 1; }; \
	if $(OBJDUMP) -d '$(OBJ_LL_ATON)' | grep -Eq '(^|[[:space:]])10000([[:space:]]|$$|,)'; then \
		echo "ERROR: rebuilt ll_aton.o still references 0x00010000"; \
		exit 1; \
	fi; \
	if $(OBJDUMP) -d '$(OBJ_LL_ATON_RUNTIME)' | grep -Eq '(^|[[:space:]])11000([[:space:]]|$$|,)'; then \
		echo "ERROR: rebuilt ll_aton_runtime.o still references 0x00011000"; \
		exit 1; \
	fi; \
	echo "Final archive symbols, network hook and LL_ATON objects: OK"

# Remove

remove :
	@rm -f $(SCRIPT_MRI)
	@rm -rf $(PATH_RUNTIME_EXTRACT)

# Configuration

print-config :
	@echo "PATH_PROJECT				= $(PATH_PROJECT)"
	@echo "PATH_STM32N6				= $(PATH_STM32N6)"
	@echo "PATH_NETWORK				= $(PATH_NETWORK)"
	@echo "PATH_GENERATED			= $(PATH_GENERATED)"
	@echo "PATH_PREBUILT			= $(PATH_PREBUILT)"
	@echo "PATH_STEDGEAI			= $(PATH_STEDGEAI)"
	@echo "LIB_ST_RUNTIME			= $(LIB_ST_RUNTIME)"
	@echo "PATH_OUTPUT				= $(PATH_OUTPUT)"
	@echo "INCLUDES_STM32N6XX		= $(INCLUDES_STM32N6XX)"
	@echo "INCLUDES_CORE_CMSIS		= $(INCLUDES_CORE_CMSIS)"
	@echo "INCLUDES_HAL_STM32N6		= $(INCLUDES_HAL_STM32N6)"
	@echo "HAL_CONF_INC				= $(INCLUDES_HAL_CNF_STM32N6)"
	@echo "CC						= $(CC)"
	@echo "ST object count			= $(words $(OBJ_ST_ALL))"
	@echo "LL_ATON_RT_MODE			= 1 (polling)"
	@echo "NETWORK_SOURCE			= $(SRC_NETWORK)"
	@echo "NETWORK_OBJECT			= $(OBJ_NETWORK)"

-include $(OBJ:.o=.d)
