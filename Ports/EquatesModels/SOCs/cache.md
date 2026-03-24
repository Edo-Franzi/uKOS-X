# MCU Caches

| MCU       | Cache | Size | Type                           | Cache | Size | Type                      | Special Cache                                 |
| :-------- | :---- | :--- | :----------------------------- | :---- | :--- | :------------------------ | :-------------------------------------------- |
|           | Inst  | Inst | Inst                           | Data  | Data | Data                      |                                               |
|           |       | KB   |                                |       | KB   |                           |                                               |
|           |       |      |                                |       |      |                           |                                               |
| GD32VF103 | No    | 0    | —                              | No    | 0    | —                         | SRAM/Flash cache (~6–32 KB, not standard I/D) |
| K210      | Yes   | ~16  | RISC-V standard                | Yes   | ~8   | RISC-V standard           | KPU / AI memory subsystem                     |
| nRF5340   | Yes   | 8    | Flash cache (not CPU standard) | No    | 0    | —                         | Flash cache (2 KB on network core)            |
| RP2350    | Yes   | 16   | XIP cache (not CPU standard)   | No    | 0    | —                         | External flash XIP cache                      |
| STM32F207 | No    | 0    | —                              | No    | 0    | —                         | ART accelerator (flash)                       |
| STM32H743 | Yes   | 16   | ARM standard (Cortex-M7)       | Yes   | 16   | ARM standard (Cortex-M7)  | ITCM/DTCM (not cache)                         |
| STM32H747 | Yes   | 16   | ARM standard (Cortex-M7)       | Yes   | 16   | ARM standard (Cortex-M7)  | Dual-core + TCM (M4 has no cache)             |
| STM32L4R5 | No*   | 0*   | —                              | No*   | 0*   | —                         | Flash cache: 1 KB I + 256 B buffer            |
| STM32N657 | Yes   | 32   | ARM standard (Cortex-M55)      | Yes   | 32   | ARM standard (Cortex-M55) | TCM + NPU memory/cache                        |
| STM32U5G9 | Yes   | 8    | ST ICACHE (not CPU standard)   | No**  | 0**  | —                         | DCACHE1 (~4–32 KB) + DCACHE2 (~16 KB)         |
| STM32V873 | Yes   | 32   | ARM standard (Cortex-M85)      | Yes   | 32   | ARM standard (Cortex-M85) | Advanced memory / accelerator caches          |

`No*` (**STM32L4R5**) → No CPU I/D cache, but has **flash accelerator cache** (not a true CPU cache)

`No**` (**STM32U5G9**) → No CPU D-cache, but has **system-level data caches (DCACHE1/2)**
