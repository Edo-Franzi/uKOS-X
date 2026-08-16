# RISC-V TestROM Build Success

## Status: ✅ Build Complete

The RISC-V TestROM for RP2350 now builds successfully and is ready for hardware testing.

---

## Build Summary

**Date:** 2026-02-13
**Target:** Raspberry Pi Pico 2 (RP2350 RISC-V Hazard3)
**Test:** Test 00 - LED Blink

### Build Output

```
Memory region         Used Size  Region Size  %age Used
       prgm_code:       15092 B         4 MB      0.36%
       prgm_data:       12824 B       128 KB      9.78%
```

### Files Generated

| File | Size | Description |
|------|------|-------------|
| `testROM.elf` | 95K | ELF executable with debug symbols |
| `testROM.bin` | 15K | Raw binary for flashing |
| `testROM.hex` | 42K | Intel HEX format |
| `testROM.map` | 66K | Memory map and symbol table |

### Binary Verification

```bash
$ file build/testROM.elf
ELF 32-bit LSB executable, UCB RISC-V, RVC, soft-float ABI, version 1 (SYSV),
statically linked, with debug_info, not stripped

$ hexdump -C build/testROM.bin | head -1
00000000  d3 de ff ff 42 01 11 10  ff 01 00 00 00 00 00 00
                            ^^  ^^
                            |   └─ 0x10 = ARM bit clear
                            └───── 0x11 = ARCHSEL=1 (RISC-V)
```

**Picobin block is correct:** Byte 6 = `0x11` selects RISC-V Hazard3 mode.

---

## Issues Fixed

The following linking errors were resolved to achieve a successful build:

### 1. Variable Name Mismatch ❌→✅

**Problem:**
- `first_rv.c` declared `extern bool vExce_isException[KNB_CORES]`
- `tests.c` defined `volatile bool vPriv_insideException[KNB_CORES]`
- The macro `EXCEPTION_SPECIFIC_HANDLER` in `macros_core.h` uses `vExce_isException`

**Error:**
```
undefined reference to `vExce_isException'
conflicting types for 'vExce_isException'; have 'volatile _Bool[2]'
```

**Solution:**
- Changed `tests.c` line 39 from:
  ```c
  volatile bool vPriv_insideException[KNB_CORES] = MCSET(false);
  ```
  to:
  ```c
  bool vExce_isException[KNB_CORES] = MCSET(false);
  ```
- Updated `first_rv.c` line 58 to match (removed volatile)

**Files Modified:**
- `first_rv.c` (line 58)
- `tests.c` (line 39)

---

### 2. Missing Core 1 Stack Symbols ❌→✅

**Problem:**
- `first_rv.c` line 97 references `linker_topStackFirst_C1` for Core 1 reset handler
- Linker script only defined Core 0 stack symbols

**Error:**
```
undefined reference to `linker_topStackFirst_C1'
```

**Solution:**

**`Runtime/link_p.ld`** - Added Core 1 stack size definitions:
```ld
linker_sizeStackSystem_C1   = (4K);		/* System stack for core 1 */
linker_sizeStackFirst_C1    = (2K);     /* Application stack for core 1 */
```

**`Runtime/system_p.ld`** - Added Core 1 stack sections:
```ld
.stacks (NOLOAD) : {
    /* Core 0 stacks */
    linker_lowStackSystem_C0 = ABSOLUTE(.);
    . += linker_sizeStackSystem_C0;
    linker_topStackSystem_C0 = ABSOLUTE(.) - 8;

    linker_lowStackFirst_C0 = ABSOLUTE(.);
    . += linker_sizeStackFirst_C0;
    linker_topStackFirst_C0 = ABSOLUTE(.) - 8;

    /* Core 1 stacks (NEW) */
    linker_lowStackSystem_C1 = ABSOLUTE(.);
    . += linker_sizeStackSystem_C1;
    linker_topStackSystem_C1 = ABSOLUTE(.) - 8;

    linker_lowStackFirst_C1 = ABSOLUTE(.);
    . += linker_sizeStackFirst_C1;
    linker_topStackFirst_C1 = ABSOLUTE(.) - 8;
} > prgm_data
```

**Files Modified:**
- `Runtime/link_p.ld` (added lines 39-40)
- `Runtime/system_p.ld` (added lines 87-95)

---

### 3. Missing Heap Symbols ❌→✅

**Problem:**
- C runtime (`crt0.c` or `debug.c`) references heap symbols for dynamic memory allocation
- Linker script did not define heap region

**Error:**
```
undefined reference to `linker_stHeap'
undefined reference to `linker_lnHeap'
```

**Solution:**

**`Runtime/system_p.ld`** - Added heap section after stacks:
```ld
/* Heap */
.heap (NOLOAD) : {
    . = ALIGN(8);
    linker_stHeap = ABSOLUTE(.);
    linker_lnHeap = ORIGIN(prgm_data) + LENGTH(prgm_data) - ABSOLUTE(.);
} > prgm_data
```

This allocates all remaining RAM after stacks as heap space.

**Files Modified:**
- `Runtime/system_p.ld` (added lines 97-102)

---

### 4. Missing cmns_send() Function ❌→✅

**Problem:**
- `CMakeLists.txt` includes `../_Common/Runtime/debug.c`
- `debug.c` calls `cmns_send()` for console output
- RISC-V `cmns.c` only had `cmns_wait()`, missing `cmns_send()`

**Error:**
```
undefined reference to `cmns_send'
```

**Solution:**

Added `cmns_send()` function to `cmns.c` (copied from ARM version):
```c
void cmns_send(serialManager_t serialManager, const char_t *ascii) {
    uint8_t     data;
    uint32_t    core;
    const char_t *wkAscii = ascii;

    UNUSED(serialManager);
    core = GET_RUNNING_CORE;
    if (ascii == nullptr) { return; }

    switch (core) {
        case KCORE_0:
            while (true) {
                while ((REG(UART0)->UARTFR & UART_UARTFR_TXFF) != 0u) { }
                data = (uint8_t)*wkAscii++;
                if (data == '\0') { return; }
                cmns_wait(100);
                REG(UART0)->UARTDR = (uint32_t)data;
            }
            break;

        case KCORE_1:
            while (true) {
                while ((REG(UART1)->UARTFR & UART_UARTFR_TXFF) != 0u) { }
                data = (uint8_t)*wkAscii++;
                if (data == '\0') { return; }
                cmns_wait(100);
                REG(UART1)->UARTDR = (uint32_t)data;
            }
            break;
    }
}
```

**Note:** RP2350 UART registers are identical between ARM and RISC-V modes, so the same code works for both.

**Files Modified:**
- `cmns.c` (added lines 31-73)

---

## Previous Fixes

These issues were fixed in earlier iterations:

### GPIO Configuration Fix

**Problem:** Used array syntax `REG(IO_BANK0)->GPIO[pin].CTRL`
**Solution:** Changed to individual registers `REG(IO_BANK0)->GPIO25_CTRL`

### PLL Configuration Fix

**Problem:** Used incorrect define names and non-existent array access
**Solution:** Replaced entire function with working ARM version (registers are identical)

### Missing clockTree.h

**Problem:** `tests.h` included missing `clockTree.h`
**Solution:** Created `clockTree.h` with clock frequency definitions

---

## Build Instructions

```bash
cd /Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv-lva/Tools/TestRom/Pico2_rp2350_RISC-V

# Clean build
rm -rf build
cmake -S . -B build -DTEST_NUMBER=00 -DBOARD=Pico2

# Compile
cmake --build build

# Output files in build/:
# - testROM.elf
# - testROM.bin
# - testROM.hex
# - testROM.map
```

---

## Next Steps

### 1. Flash to Hardware

Convert to UF2 format for bootloader:
```bash
picotool uf2 convert build/testROM.elf build/testROM.uf2 --family rp2350-riscv

# Flash: Hold BOOTSEL button, connect USB, copy file
cp build/testROM.uf2 /Volumes/RPI-RP2/
```

### 2. Expected Behavior (Test 00)

Once flashed, the Pico 2 should:
1. Boot in RISC-V Hazard3 mode (ARCHSEL=1)
2. Initialize PLL to 150 MHz
3. Configure GPIO pins for LEDs
4. Blink 4 LEDs in sequence:
   - System LED (GPIO25) - 100ms on
   - Yellow LED (GPIO11) - 100ms on
   - Green LED (GPIO12) - 100ms on
   - Red LED (GPIO13) - 100ms on
   - Repeat continuously

### 3. Debugging If Not Working

**No LEDs blinking:**
- Check picobin block: `hexdump -C build/testROM.bin | head -1`
- Verify byte 6 = `0x11` (RISC-V mode)
- Check that binary is RISC-V: `file build/testROM.elf`

**Slow or fast blinking:**
- Adjust `cmns_wait()` calibration in `cmns.c` lines 47-50
- Current calibration assumes 150 MHz with cache enabled

**Other issues:**
- Connect serial console to UART0 (GPIO16/17) @ 115200 baud
- Add debug output to track boot progress
- Use JTAG debugger if available

### 4. Testing Progress

All tests verified on hardware:
- **Test 00:** LED blink (boot, clocks, GPIO) ✅
- **Test 01:** UART send (UART TX) ✅
- **Test 02:** UART echo (UART RX+TX polling) ✅
- **Test 03:** UART0 RX interrupt (Hazard3 MEIEA/meinext dispatch) ✅
- **Test 04:** UART0 TX interrupt ✅
- **Test 05:** TIM0 alarm 0 & 1 interrupts ✅
- **Test 06:** Pico-kernel with ecall context switching ✅
- **Test 07:** UART0 TX interrupt (char-by-char) ✅
- **Test 08:** Dual-core boot via SIO FIFO (Hazard3 h3.unblock) ✅
- **Test 09:** Dual-core TIM0 alarm interrupts ✅
- **Test 10:** Dual-core spin lock (C11 atomic_flag) ✅
- **Test 11:** Inter-core doorbell interrupt (Hazard3 MEIPRA priority fix) ✅

Use working TestROM code to debug main RISC-V target implementation.

---

### 5. Hazard3 MEIPRA Default Priority Issue ❌→✅

**Problem:**
- SIO_IRQ_BELL (IRQ 26) doorbell interrupt never fired despite MEIEA enable
- Polling confirmed doorbell bits arrived at core 1, ruling out register access issues
- Timer IRQs (0, 1) worked without explicit priority setting

**Root Cause:**
- The Hazard3 MEIPRA (external interrupt priority array) defaults to priority 0 for
  some IRQs (including SIO_IRQ_BELL at IRQ 26)
- Priority 0 means "never taken" — the interrupt is masked regardless of MEIEA
- Timer IRQs (0, 1) appear to get non-zero default priorities from the bootrom

**Solution:**
- Added `core_setExternalIRQPriority()` helper to `Includes/Core/core.h`
- Call `core_setExternalIRQPriority(irqNum, 1u)` before enabling IRQs that have
  default priority 0 (e.g., SIO_IRQ_BELL)
- MEIPRA CSR (0xBE3) uses windowed access: 4 IRQs per window, 4 priority bits each

**Files Modified:**
- `Includes/Core/core.h` (added `core_setExternalIRQPriority()`)
- `tests_11.c` (uses explicit priority for doorbell IRQ)

---

### 6. TIMER0 INTE Race Condition (Dual-Core) ❌→✅

**Problem:**
- Non-atomic `TIMER0->INTE |= TIMER_INTE_ALARM_x` from two cores caused one
  core's alarm enable bit to be overwritten (TOCTOU race)
- Symptom: core 0's timer interrupt stopped working when core 1 modified INTE

**Solution:**
- Core 0 sets `TIMER0->INTE = TIMER_INTE_ALARM_0 | TIMER_INTE_ALARM_1` before
  launching core 1
- Core 1 no longer touches INTE

**Files Modified:**
- `tests_09.c`, `tests_10.c`

---

### 7. Hazard3 h3.unblock for SIO FIFO Wakeup ❌→✅

**Problem:**
- Core 1 boot protocol requires waking core 1 from idle after FIFO writes
- ARM uses `sev` (Send Event) instruction; RISC-V has no direct equivalent
- `SIO->RISCV_SOFTIRQ` triggers MSIP (software interrupt), not event signalling

**Root Cause:**
- The RP2350 boot ROM uses Hazard3 custom `h3.block` instruction to idle core 1
- `h3.block` requires `h3.unblock` from the other core to wake up

**Solution:**
- Added `sev()` inline function: `__asm volatile ("slt x0, x0, x1" ::: "memory")`
- `slt x0, x0, x1` is the Hazard3 `h3.unblock` encoding (wakes other cores)
- `slt x0, x0, x0` would be `h3.block` (enters idle until unblocked)

**Files Modified:**
- `init.c` (added `sev()`, replaced RISCV_SOFTIRQ calls)

---

## Files Summary

### Modified Files

| File | Lines Modified | Purpose |
|------|----------------|---------|
| `first_rv.c` | 58 | Changed variable name to `vExce_isException` |
| `tests.c` | 39 | Changed variable name and removed volatile |
| `cmns.c` | 31-73 | Added `cmns_send()` function |
| `Runtime/link_p.ld` | 39-40 | Added Core 1 stack size definitions |
| `Runtime/system_p.ld` | 87-102 | Added Core 1 stack and heap sections |

### Previously Created Files

| File | Purpose |
|------|---------|
| `init.c` | Hardware initialisation (GPIO, PLL, clocks) |
| `clockTree.h` | Clock frequency definitions |
| `Runtime/link_p.ld` | Main linker script |
| `Runtime/system_p.ld` | Section definitions |
| `Runtime/rp2350.ld` | SoC memory map |
| `README.md` | Complete TestROM documentation |
| `CMAKE_REVIEW.md` | CMakeLists.txt verification |

---

## Conclusion

✅ **The RISC-V TestROM is now ready for hardware testing!**

All compilation and linking errors have been resolved. The binary is correctly configured for RISC-V mode and contains the proper boot block. Test 00 (LED blink) should work once flashed to the Pico 2.

**Build verified on:** 2026-02-13 16:44
**Toolchain:** GCC 15.2.0 for RISC-V (riscv64-unknown-elf)
**Target:** RP2350 Hazard3 (RV32IMAC)
