# System customisation

(c) 2025-2026, Edo. Franzi, 2025-01-01



The system offers extensive customization capabilities to achieve the desired behaviour, with fine-tuning accomplished by strategically modifying the behavioural descriptions within the makefile.

### Adding console tools or processes

```makefile
# Example: adding the man tool
CLI_U      += $(PATH_UKOS)/OS/CLI/man/man.c

# Example: adding the process alive
PROC_U      =  $(PATH_UKOS)/OS/Processes/alive/alive.c
PROC_HIDE_U =  $(PATH_BASE)/OS/Processes/alive/stub_alive.c
```

### Adding managers

```makefile
# Example: adding the urt0 manager
CONF_SYSTEM += -DCONFIG_MAN_URT0_S
LIBX_P      += $(PATH_UKOS)/OS/Lib_serials/urt0/urt0.c
```

### Adding third party MicroPython library

```makefile
# Adding the MicroPython support
PATH_LIB_MICROPYTHON = $(PATH_UKOS)/Third_Parties/MicroPython/Library/$(CORE)
MICROPYTHON          = libMicroPython
...
# Example: adding the MicroPython tool
CLI_U           += $(PATH_UKOS)/OS/CLI/microPython/microPython.c
...
# With the MicroPython manager (MicroPython Engine)
CONF_SYSTEM     += -DCONFIG_MAN_MICROPYTHON_S
UKOS_COMPONENTS += $(MICROPYTHON).a
```

### Adding third party TinyUSB (FS) library

```makefile
# Adding the TinyUSB support
# - Provider (st)
# - Family (nrf)
# - Speed (FS)
# - Profile (cdc_cdc)
PATH_LIB_TINYUSB = \
    $(PATH_UKOS)/Third_Parties/TinyUSB/Library/Family/$(FAMILY)/$(SOC)/$(PROFILE)
TINYUSB   =  libTinyUSB_$(SPEED)
PROVIDER  =  nordic
FAMILY    =  nrf
SPEED     =  FS
PROFILE   =  cdc_cdc

PATH_INCLUDES  += \
    -I$(PATH_UKOS)/Third_Parties/TinyUSB/Library/Family/$(FAMILY)/$(SOC)/$(PROFILE)
PATH_INCLUDES  += -I$(PATH_UKOS)/Third_Parties/TinyUSB/uKOS_Interface/OSAL
PATH_INCLUDES  += -I$(PATH_UKOS)/Third_Parties/TinyUSB/TinyUSB-current/src
PATH_INCLUDES  += -I$(PATH_UKOS)/Third_Parties/TinyUSB/TinyUSB-current/src/device
PATH_INCLUDES  += -I$(PATH_UKOS)/Third_Parties/TinyUSB/TinyUSB-current/src/class
...
# With the TinyUSB process
PROC_U      =  $(PATH_UKOS)/OS/TinyUSB/TinyUSB.c
PROC_HIDE_U =  $(PATH_VARI)/OS/Processes/TinyUSB/stub_TinyUSB.c
...
# With the TinyUSB library
CONF_SYSTEM     += -DSYSTEM_TINYUSB_$(SPEED)_S
UKOS_COMPONENTS += $(TINYUSB).a
```

### Adding third party TinyUSB (HS) library

```makefile
# Adding the TinyUSB support
# - Provider (st)
# - Family (u5)
# - Speed (HS)
# - Profile (cdc_video)
PATH_LIB_TINYUSB = \
               $(PATH_UKOS)/Third_Parties/TinyUSB/Library/Family/$(FAMILY)/$(SOC)/$(PROFILE)
TINYUSB   =  libTinyUSB_$(SPEED)
PROVIDER  =  st
FAMILY    =  u5
SPEED     =  HS
PROFILE   =  cdc_video

PATH_INCLUDES  += \
    -I$(PATH_UKOS)/Third_Parties/TinyUSB/Library/Family/$(FAMILY)/$(SOC)/$(PROFILE)
PATH_INCLUDES  += -I$(PATH_UKOS)/Third_Parties/TinyUSB/uKOS_Interface/OSAL
PATH_INCLUDES  += -I$(PATH_UKOS)/Third_Parties/TinyUSB/TinyUSB-current/src
...
# With the TinyUSB process
PROC_U      =  $(PATH_UKOS)/OS/TinyUSB/TinyUSB.c
PROC_HIDE_U =  $(PATH_VARI)/OS/Processes/TinyUSB/stub_TinyUSB.c
...
# With the TinyUSB library
CONF_SYSTEM     += -DSYSTEM_TINYUSB_$(SPEED)_S
UKOS_COMPONENTS += $(TINYUSB).a
```

### Adding third party FatFs library

```makefile
# Adding the FatFs support
PATH_LIB_FATFS = $(PATH_UKOS)/Third_Parties/FatFs/Library/$(CORE)
FATFS          = libFatFs
...
# With the FATFS manager (File system)
CONF_SYSTEM     += -DCONFIG_MAN_FATFS_S
UKOS_COMPONENTS += $(FATFS).a
```

### Customising the kernel

By construction, the kernel is set with the following configuration:

| Argument          |  Description                                                    |
| ----------------- | --------------------------------------------------------------- |
| KKERN_WITH_STATISTICS_S = true | Include the statistics |
| KKERN_WITH_DEBUG_S = true | Include the stop |
| KKERN_WITH_TRTC_S = true | Support the hardware RTC              |
| KKERN_NB_PROCESSES = 48 | Max. 48 processes                |
| KKERN_NB_MAILBOXES = 48 | Max. 48 mailboxes |
| KKERN_NB_SEMAPHORES = 48 | Max. 48 semaphores       |
| KKERN_NB_MUTEXES = 48 | Max. 48 mutexes |
| KKERN_NB_SOFTWARE_TIMERS = 8 | Max. 8 software timers |
| KKERN_NB_SIGNALS = 8 | Max. 8 signals |
| KKERN_NB_POOLS = 8 | Max. 8 pool regions    |
| KKERN_NB_PRECISE_SIGNALS = 8 | Max. 8 precise signals |

Adaptation example

```makefile
# Modifying the number of objects

# Number of process
CONF_SYSTEM += -DKKERN_NB_PROCESSES=8
# Number of mailboxes
CONF_SYSTEM += -DKKERN_NB_MAILBOXES=4
# Number of memory pools
CONF_SYSTEM += -DKKERN_NB_POOLS=0
...
# Modifying the behaviour of the kernel

# Remove the statistics
CONF_SYSTEM += -DKKERN_WITH_STATISTICS_S=false
```

### Customising the libraries

By construction, the libraries are set with the following configuration:

| Argument                  | Description                                  |
| ------------------------- | -------------------------------------------- |
| KGLOBAL_WITH_MMX1_S = false | Without the support of an external SPI FLASH |
| KGLOBAL_RND_SOFT_S = true   | With a software random generator             |

Adaptation example

```makefile
# Adding the support of the MMX
CONF_SYSTEM += -DKGLOBAL_WITH_MMX1_S=true
```

### Switches defined by the .mk of the cores

| Argument          | Description                             |
| ----------------- | --------------------------------------- |
| -DUKOS_S          | Indicates we are using the uKOS package |
| -D$(BOARD)_S      | Board used by the project               |
| -D$(SOC)_S        | SOC used by the project                 |
| -D$(CORE)_S       | Core used by the project                |
| -DLITTLE_ENDIAN_S | Endianness "little"                     |
| -DBIG_ENDIAN_S    | Endianness "big"                        |
| -DROMABLE_S       | To allows romable applications          |
| -DCACHE_D_S       | To indicate a core with the cache       |
|                   |                                         |
