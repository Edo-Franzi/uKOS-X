# TinyUSBConfig.cmake
# ===================
#
# CMake package configuration file for TinyUSB library
# Generated automatically by TinyUSB.cmake
#
# This file defines imported targets for TinyUSB libraries:
#   - TinyUSB::FS - Full Speed USB library
#   - TinyUSB::HS - High Speed USB library
#
# Usage in your CMakeLists.txt:
#   find_package(TinyUSB REQUIRED
#       PATHS ${PATH_TINYUSB}/Library/Family/${FAMILY}/${SOC}/${PROFILE}
#       NO_DEFAULT_PATH
#   )
#   target_link_libraries(your_target PRIVATE TinyUSB::FS)
#
# Configuration:
#   SOC:      STM32N657
#   PROFILE:  cdc_msc
#   PROVIDER: st
#   FAMILY:   n6

# Ensure PATH_TINYUSB is defined
if(NOT DEFINED PATH_TINYUSB)
    get_filename_component(PATH_TINYUSB "${CMAKE_CURRENT_LIST_DIR}/../../../../../" ABSOLUTE)
    message(STATUS "TinyUSB: PATH_TINYUSB set to ${PATH_TINYUSB}")
endif()

# Check that library files exist
if(NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/libTinyUSB_FS.a")
    message(FATAL_ERROR "TinyUSB FS library not found: ${CMAKE_CURRENT_LIST_DIR}/libTinyUSB_FS.a")
endif()
if(NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/libTinyUSB_HS.a")
    message(FATAL_ERROR "TinyUSB HS library not found: ${CMAKE_CURRENT_LIST_DIR}/libTinyUSB_HS.a")
endif()

# Build the list of interface include directories
set(TINYUSB_INTERFACE_INCLUDES
    ${PATH_TINYUSB}/Construction/Interface/OSAL
    ${PATH_TINYUSB}/TinyUSB-current/src
    ${PATH_TINYUSB}/TinyUSB-current/src/common
    ${PATH_TINYUSB}/TinyUSB-current/src/device
    ${PATH_TINYUSB}/TinyUSB-current/src/class
    ${CMAKE_CURRENT_LIST_DIR}
)
list(APPEND TINYUSB_INTERFACE_INCLUDES
    ${PATH_TINYUSB}/Construction/Interface/Includes/mcu/st
)

# Define imported target for Full Speed library
if(NOT TARGET TinyUSB::FS)
    add_library(TinyUSB::FS STATIC IMPORTED)
    set_target_properties(TinyUSB::FS PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/libTinyUSB_FS.a"
        INTERFACE_INCLUDE_DIRECTORIES "${TINYUSB_INTERFACE_INCLUDES}"
        INTERFACE_COMPILE_DEFINITIONS "SYSTEM_TINYUSB_FS_S"
    )
endif()

# Define imported target for High Speed library
if(NOT TARGET TinyUSB::HS)
    add_library(TinyUSB::HS STATIC IMPORTED)
    set_target_properties(TinyUSB::HS PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/libTinyUSB_HS.a"
        INTERFACE_INCLUDE_DIRECTORIES "${TINYUSB_INTERFACE_INCLUDES}"
        INTERFACE_COMPILE_DEFINITIONS "SYSTEM_TINYUSB_HS_S"
    )
endif()

# Mark package as found
set(TinyUSB_FOUND TRUE)
set(TinyUSB_VERSION "1.0")

message(STATUS "Found TinyUSB: STM32N657/cdc_msc (Full Speed and High Speed variants)")
