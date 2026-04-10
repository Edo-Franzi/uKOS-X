# 🌈  Annex D, Making ROMable applications

## Making ROMable applications

Developing ROMable applications is a relatively simple and straightforward process. All applications intended for download can be integrated directly into the **µKOS-X** operating system's **Flash** memory.

A ROMable application typically offers a performance improvement of approximately **two to four** times compared to its downloadable counterpart — though this gain is naturally dependent on the specific hardware configuration. In the case of STM32 Cortex microcontrollers, the observed performance enhancement is close to a factor of four. This significant increase is largely attributed to the fact that both the internal RAM and Flash memory can be accessed with zero wait states.

## How to proceed

Starting from a downloadable application (for example, see the Classifier application located in the Applications folder), the following steps and modifications are required to make it ROMable:

1. **Programming Guidelines**.
    Follow the specific programming rules applicable to ROMable applications to ensure compatibility with µKOS-X Flash integration.
2. Modification of **application.c**.
    Adapt the application.c file to meet the requirements for static linking and execution from ROM. This may involve adjustments to initialisation routines and memory usage.
3. Modification of the **Main µKOS-X Makefile.**
    Update the main µKOS-X makefile to include the application in the build process. This ensures the application is linked directly into the system image and loaded into Flash at runtime.

### Programming Guidelines

To fully leverage the hardware capabilities of STM32 Cortex microcontrollers — particularly the high-speed access to internal RAM and Flash memory — the following recommendations should be considered:

1. Use of Flash for **Constant** Data.
    The Flash memory is significantly larger than the internal RAM and offers comparable access speeds. Therefore, constant arrays should be stored in Flash memory whenever possible to preserve valuable RAM resources.
2. **Efficient Use of the RAM**.
    As the internal RAM is limited in size, it is generally unsuitable for storing large data arrays. In such cases, large arrays should be placed in external memory, which provides greater capacity but at the cost of slower access times. This introduces a trade-off between memory size and performance that must be carefully evaluated. When the required memory size is modest, allocating data in internal RAM is preferable due to its superior speed.

```c
Use “const” for the array of non-modifiable data

Instead of writing …
static uint8_t    aWeightSet[10] = { 0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u };
… write
const  uint8_t    aWeightSet[10] = { 0u, 1u, 2u, 3u, 4u, 5u, 6u, 7u, 8u, 9u };

Use “memo_malloc” for reserving large data arrays

Instead of writing …
static uint8_t    vImage[752*480];
static uint8_t    vXProjection[752];
static uint8_t    vYProjection[480];
… write
static uint8_t    *vImage;
static uint8_t    *vXProjection;
static uint8_t    *vYProjection;
...
vImage       = (uint8_t  *)memo_malloc(KEXTERNAL,  KMEMO_ALIGN_8, 752u*480u, "image");
vXProjection = (uint8_t  *)memo_malloc(KINTERNAL0, KMEMO_ALIGN_8, 752u,      "projection");
vYProjection = (uint8_t  *)memo_malloc(KINTERNAL0, KMEMO_ALIGN_8, 480u,      "projection");
vXProjection = (uint16_t *)memo_malloc(KINTERNAL,  KMEMO_ALIGN_8, 752u,      "projection");
```

### Adaptation of the application.c

```c
// Module specifications (See the modules.h)
// =========================================

#if (defined(ROMABLE_S))
static int32_t prgm(uint32_t argc, const char_t *argv[]);

MODULE(UserAppl,
    KID_FAM_TOOL,
    ((‘_'<<8)+'C'),
    nullptr,
    prgm,
    nullptr,
    “ 1.0",
    ((1<<BSHOW) | (1<<BEXE_CONSOLE)),
    0
);

#else
MODULE(UserAppl
    KID_FAM_APPLICATION,
    KNUM_APPLICATION,
    nullptr,
    aStart,
    nullptr,
    “ 1.0",
    ((1<<BSHOW) | (1<<BEXE_CONSOLE))
    0
);
#endif
...

/*
 * \brief main
 *
 * - Initialise the used libraries
 * - Launch all the processes
 * - Kill the "main". At this moment only the launched processes are executed
 *
 */
MAIN_ENTRY(argc, const char_t *argv[]) {

    ...
    return (EXIT_OS_SUCCESS_CLI);
}
```

### Adaptation of the main µKOS-X makefile

Add the file /Target/Alastor_H743/Variant_Test/System/app.mk.

```makefile
FLAGS_UKOS  += -DWITHAPP_S

PATH_APPL		=  $(PATH_UKOS)/Applications/uKOS_Appls_Downloadable

CLI_U				+= $(PATH_UKOS)/Applications/uKOS_Appls_Downloadable/ \
               l_MLPs/class_Py/class_Py.c
```

Build the system to include the app.

```bash
make -j USER_MODE=1 WITHAPP=1
```

