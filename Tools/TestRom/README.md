# uKOS-X TestRom

(c) 2025-2026, Edo. Franzi, 2025-01-01

## Objectives

The TestRom is intended to experiment new SOCs/CPUs and specific peripherals in order to prepare and to create the necessary files for a minimal porting of µKOS-X. This process takes place step-by-step. The minimal objective is:

1. Mastering the GPIOs (e.g. for LEDs and for logic analyser synchros)
2. Mastering the UARTs (minimal I/O channel)
3. Mastering the Timers
4. Mastering the interruptions
5. Mastering the basic contex switch

This code is a collection of minimal stand-alone programs written for the described purpose.

### Important files

**Folders _Commun/Include & _Commun/Runtime: Commun files to all the targets.**

| File                         | Purpose                           | Comment   |
| ---------------------------- | --------------------------------- | --------- |
| **_Commun/Include (folder)** | Commun files to all the targets   |           |
| **_Commun/Runtime (folder)** | Commun files to all the targets   |           |
| type.h                       | µKOS-X used types                 | Available |
| cmns.h                       | Minimal UART support (by polling) | Available |
| debug.c/h                    | Some useful string manipulation   | Available |
| crt0*.c                      | Initial C runtime                 | Available |
| spin.h                       | Spin management for multicores    | Available |
| linker.h                     | General linker equates            | Available |

The following files need to be consolidated before moving in the µKOS-X porting.

**Folders Include**

| File                 | Purpose                                                   | Comment            |
| -------------------- | --------------------------------------------------------- | ------------------ |
| **Include (folder)** | Target specific includes                                  |                    |
| Core                 | Folder with the Core equates                              | Has to be written  |
| Cpu                  | Folder with the SOCs equates                              | Has to be written  |
| board.h              | Minimal description of the avaiklable hardware ressources | Has to be written  |
| tests.h              | Selection of the test                                     | Available          |
|                      |                                                           |                    |
| **Runtime (folder)** | Target specific runtimes                                  |                    |
| link_p_.ld           | Target linker script                                      | Has to be written  |
| xyz.ld               | SoC ressource description                                 | Has to be written  |
| systewm_p_.ld        | Generic linker script                                     | Available          |
|                      |                                                           |                    |
| model_XXcache.c_inc  | Cache model (if cpu with cache)                           | Has to be written  |
| clockTree.h          | Clock tree definitions                                    | Has to be written  |
| cmns.c               | Minimal UART support (by polling)                         | Available template |
| first.c              | SOC specific interruption handlers                        | Has to be written  |
| init.c               | Very first initialisation code (e.g. HW initialisations)  | Available template |
| tests.c              | Test inclusion & launcher                                 | Available          |
| test_xx.c            | The basic tests                                           | Has to be written  |
| makefile             | The TestRom makefile                                      | Has to be written  |
| burn.sh              | Script for burning the cpu flash                          | Available template |
