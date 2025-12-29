# TinyUSB.
# ========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi		The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		makefile for uKOS-X systems (TinyUSB part).
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

ifndef SOC
$(error SOC is not defined)
endif
ifndef PROVIDER
$(error PROVIDER is not defined)
endif
ifndef PROFILE
$(error PROFILE is not defined)
endif
ifndef PATH_UKOS
$(error PATH_UKOS is not defined)
endif
ifndef PATH_TINYUSB
$(error PATH_TINYUSB is not defined)
endif

PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Includes
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Lib_kernels
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Lib_kernels/kern
PATH_INCLUDES		+= -I$(PATH_UKOS)/OS/Lib_kernels/kern/private

PATH_INCLUDES		+= -I$(PATH_TINYUSB)/uKOS_Interface/OSAL
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/Library/Family/$(FAMILY)/$(SOC)/$(PROFILE)
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/hw
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/src
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/src/common
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/src/device
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/src/class/hid
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/src/class/cdc
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/src/class/msc

ifeq ($(PROVIDER), st)
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/CMSIS_5/CMSIS/Core/Include
PATH_INCLUDES		+= -I$(PATH_UKOS)/Ports/EquatesModels/Generic/Runtime
PATH_INCLUDES		+= -I$(PATH_UKOS)/Ports/EquatesModels/SOCs/$(SOC)/Includes
PATH_INCLUDES		+= -I$(PATH_UKOS)/Ports/EquatesModels/Cores/$(CORE)/Includes
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/uKOS_Interface/Includes/mcu/$(PROVIDER)
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/hw/mcu/st/cmsis_device_$(FAMILY)/Include
endif

ifeq ($(PROVIDER), nordic)
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/CMSIS_5/CMSIS/Core/Include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/hw/bsp/nrf
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/hw/bsp/nrf/nrfx_config
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/hw/mcu/nordic/nrfx
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/hw/mcu/nordic/nrfx/mdk
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/hw/mcu/nordic/nrfx/hal
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/hw/mcu/nordic/nrfx/templates
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/hw/mcu/nordic/nrfx/drivers
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/hw/mcu/nordic/nrfx/drivers/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/hw/mcu/nordic/nrfx/drivers/src
endif

ifeq ($(PROVIDER), raspberrypi)
PATH_INCLUDES		+= -I$(PATH_UKOS)/Ports/EquatesModels/Generic/Runtime
PATH_INCLUDES		+= -I$(PATH_UKOS)/Ports/EquatesModels/SOCs/$(SOC)/Includes
PATH_INCLUDES		+= -I$(PATH_UKOS)/Ports/EquatesModels/Cores/$(CORE)/Includes
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/uKOS_Interface/Includes/mcu/raspberrypi
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/src/portable/raspberrypi/rp2040

PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/common/pico_base_headers/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_platform/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_base/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_irq/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_resets/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_sync/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_sync_spin_lock/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_timer/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_claim/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_structs/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_platform_compiler/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_platform_sections/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_platform_panic/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_platform_common/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2350/pico_platform/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2350/hardware_structs/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2350/hardware_regs/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/bazel/include

PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_runtime_init/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_runtime/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/common/hardware_claim/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/common/pico_sync/include
PATH_INCLUDES		+= -I$(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/common/pico_time/include
endif

SRC					=   $(PATH_TINYUSB)/uKOS_System/headerTusb.c
SRC					+=  $(PATH_TINYUSB)/uKOS_Interface/Descriptors/$(PROFILE)/usb_descriptors.c
SRC					+=  $(PATH_TINYUSB)/uKOS_Interface/OSAL/tusb_os_custom.c
SRC					+=  $(PATH_TINYUSB)/TinyUSB-current/src/tusb.c
SRC					+=  $(shell find $(PATH_TINYUSB)/TinyUSB-current/src/class -name '*.c')
SRC					+=  $(shell find $(PATH_TINYUSB)/TinyUSB-current/src/common -name '*.c')
SRC					+=  $(shell find $(PATH_TINYUSB)/TinyUSB-current/src/device -name '*.c')
SRC					+=  $(shell find $(PATH_TINYUSB)/TinyUSB-current/src/host -name '*.c')
SRC					+=  $(shell find $(PATH_TINYUSB)/TinyUSB-current/src/osal -name '*.c')
SRC					+=  $(shell find $(PATH_TINYUSB)/TinyUSB-current/src/typec -name '*.c')

ifeq ($(PROVIDER), st)
SRC					+=  $(shell find $(PATH_TINYUSB)/TinyUSB-current/src/portable/st -name '*.c')
SRC					+=  $(shell find $(PATH_TINYUSB)/TinyUSB-current/src/portable/synopsys -name '*.c')
endif

ifeq ($(PROVIDER), nordic)
SRC					+=  $(shell find $(PATH_TINYUSB)/TinyUSB-current/src/portable/nordic -name '*.c')
SRC					+=  $(PATH_TINYUSB)/TinyUSB-current/hw/mcu/nordic/nrfx/drivers/src/nrfx_usbreg.c
SRC					+=  $(PATH_TINYUSB)/TinyUSB-current/hw/mcu/nordic/nrfx/drivers/src/nrfx_power.c
SRC					+=  $(PATH_TINYUSB)/TinyUSB-current/hw/mcu/nordic/nrfx/mdk/system_nrf5340_application.c
SRC					+=  $(PATH_TINYUSB)/Library/Family/$(FAMILY)/$(SOC)/init.c
endif

ifeq ($(PROVIDER), raspberrypi)
SRC					+=  $(shell find $(PATH_TINYUSB)/TinyUSB-current/src/portable/raspberrypi/pio_usb -name '*.c')
SRC					+=  $(PATH_TINYUSB)/TinyUSB-current/src/portable/raspberrypi/rp2040/hcd_rp2040.c
SRC					+=  $(PATH_TINYUSB)/TinyUSB-current/src/portable/raspberrypi/rp2040/rp2040_usb.c
SRC					+=  $(PATH_TINYUSB)/uKOS_Interface/Patches/mcu/raspberrypi/$(FAMILY)/dcd_rp2040.c
SRC					+=  $(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/common/hardware_claim/claim.c
SRC_A				+=  $(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_irq/irq_handler_chain.S
SRC					+=  $(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_irq/irq.c
SRC					+=  $(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/pico_platform_panic/panic.c
SRC					+=  $(PATH_TINYUSB)/TinyUSB-current/lib/pico-sdk/src/rp2_common/hardware_sync_spin_lock/sync_spin_lock.c
SRC					+=  $(PATH_TINYUSB)/Library/Family/$(FAMILY)/$(SOC)/init.c

CPPFLAGS			+= $(PATH_INCLUDES)
ASFLAGS				+= $(CPUFLAGS) -x assembler-with-cpp
CFLAGS				+= -D__not_in_flash\(x\)=
endif

vpath %.S $(sort $(dir $(SRC_A)))

OBJ_C				=  $(patsubst %.c,%.o,$(SRC))
OBJ_A				=  $(notdir $(patsubst %.S,%.o,$(SRC_A)))

OBJ_C_FS			=  $(OBJ_C:.o=.fs.o)
OBJ_C_HS			=  $(OBJ_C:.o=.hs.o)
OBJ_A_FS			=  $(OBJ_A:.o=.fs.o)
OBJ_A_HS			=  $(OBJ_A:.o=.hs.o)

CFLAGS				+= -c -g3 $(OPTIMISATION)
CFLAGS				+= $(CPU_SPEC) $(FLAGS_FP)
CFLAGS				+= $(STANDARD)
CFLAGS				+= $(FLAGS_UKOS)
CFLAGS				+= -MMD
CFLAGS				+= $(PATH_INCLUDES)

CFLAGS				+= -Wall
CFLAGS				+= -Wno-pedantic
CFLAGS				+= -Wlogical-op
CFLAGS				+= -fsingle-precision-constant
CFLAGS				+= -Wno-error=undef
CFLAGS				+= -Wno-error=unused-parameter
CFLAGS				+= -Wno-error=cast-align
CFLAGS				+= -Wno-error=cast-qual
CFLAGS				+= -Wno-error=redundant-decls
CFLAGS				+= -Wno-error=strict-prototypes
CFLAGS				+= -Wno-missing-braces

ifneq ($(PREFIX),llvm-)
ifneq (,$(filter $(CORE),CORTEX_M3 CORTEX_M4 CORTEX_M7 CORTEX_M33 CORTEX_M55))
CFLAGS += -mpoke-function-name
endif
endif

all :
	@$(MAKE)	clr_all
	$(MAKE)		build_fs
	$(MAKE)		archive_fs
	$(MAKE)		remove_fs
	@$(MAKE)	clr
	$(MAKE)		build_hs
	$(MAKE)		archive_hs
	$(MAKE)		remove_hs
	@$(MAKE)	clr

# Clean

LIB_CLEAN_DIRS := . $(sort $(dir $(SRC)))

clr_all:
	@rm -f $(addsuffix /*.a,$(LIB_CLEAN_DIRS))		\
		   $(addsuffix /*.d,$(LIB_CLEAN_DIRS))		\
		   $(addsuffix /*.o,$(LIB_CLEAN_DIRS))		\
		   $(addsuffix /*.fs.o,$(LIB_CLEAN_DIRS))	\
		   $(addsuffix /*.hs.o,$(LIB_CLEAN_DIRS))	\
		   $(addsuffix /*.o.*,$(LIB_CLEAN_DIRS))

clr:
	@rm -f $(addsuffix /*.d,$(LIB_CLEAN_DIRS))		\
		   $(addsuffix /*.o,$(LIB_CLEAN_DIRS))		\
		   $(addsuffix /*.fs.o,$(LIB_CLEAN_DIRS))	\
		   $(addsuffix /*.hs.o,$(LIB_CLEAN_DIRS))	\
		   $(addsuffix /*.o.*,$(LIB_CLEAN_DIRS))

# Archive

archive_fs : $(OBJ_C_FS) $(OBJ_A_FS)
	$(AR) rcs $(TINYUSB_FS) $(OBJ_C_FS) $(OBJ_A_FS)

archive_hs : $(OBJ_C_HS) $(OBJ_A_HS)
	$(AR) rcs $(TINYUSB_HS) $(OBJ_C_HS) $(OBJ_A_HS)

# Build & remove

build_fs : $(OBJ_C_FS) $(OBJ_A_FS)
build_hs : $(OBJ_C_HS) $(OBJ_A_HS)

%.fs.o : %.c
	@echo "Compiling $(notdir $<)"
	@$(CC) -DSYSTEM_TINYUSB_FS_S $(CFLAGS) -c $< -o $@

%.fs.o : %.S
	@echo "Assembling $(notdir $<)"
	@$(CC) -c -DSYSTEM_TINYUSB_FS_S $(CPPFLAGS) $(ASFLAGS) $< -o $@

%.hs.o : %.c
	@echo "Compiling $(notdir $<)"
	@$(CC) -DSYSTEM_TINYUSB_HS_S $(CFLAGS) -c $< -o $@

%.hs.o : %.S
	@echo "Assembling $(notdir $<)"
	@$(CC) -c -DSYSTEM_TINYUSB_HS_S $(CPPFLAGS) $(ASFLAGS) $< -o $@

remove_fs :
	$(ST) --strip-unneeded $(TINYUSB_FS)

remove_hs :
	$(ST) --strip-unneeded $(TINYUSB_HS)
