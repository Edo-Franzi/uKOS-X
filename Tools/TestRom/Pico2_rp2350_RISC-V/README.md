# RISC-V TestROM for Raspberry Pi Pico 2 (RP2350)

Minimal bare-metal test environment for debugging RISC-V boot and basic functionality.

## Purpose

This TestROM provides a minimal environment to verify:
1. **Boot sequence** - RISC-V startup and initialisation
2. **Clock configuration** - PLL and system clocks
3. **GPIO** - LED control
4. **Serial communication** - UART for debugging
5. **Interrupts** - Timer and peripheral interrupts
6. **Dual-core** - Core 0 and Core 1 boot/communication

## Test Progression

### Test 00: LED Blink
- **Goal:** Verify basic boot, clocks, and GPIO
- **Hardware:** 4 LEDs on GPIO25, 11, 12, 13
- **Expected:** LEDs blink in sequence
- **Status:** ✅ Hardware verified

### Test 01: UART Send
- **Goal:** Verify UART TX functionality
- **Hardware:** UART0 on GPIO16(TX)/17(RX) @ 460800 baud
- **Expected:** Sends data continuously via UART0
- **Status:** ✅ Hardware verified

### Test 02: UART Echo
- **Goal:** Verify UART RX+TX (polling mode)
- **Hardware:** UART0 on GPIO16(TX)/17(RX) @ 460800 baud
- **Expected:** Characters received are echoed back
- **Status:** ✅ Hardware verified

### Test 03: UART0 RX Interrupt
- **Goal:** Verify Hazard3 external interrupt dispatch (MEIEA/meinext)
- **Hardware:** UART0 on GPIO16(TX)/17(RX) @ 460800 baud, LEDs
- **Expected:** Send a character, receive "OK interruptions\n", yellow LED toggles, red LED blinks independently
- **Status:** ✅ Hardware verified

### Test 04: UART0 TX Interrupt
- **Goal:** Verify UART TX interrupt-driven transmission
- **Status:** ✅ Hardware verified

### Test 05: TIM0 Alarm 0 & 1 Interrupts
- **Goal:** Verify timer alarm interrupts on single core
- **Status:** ✅ Hardware verified

### Test 06: Pico-Kernel with Ecall
- **Goal:** Verify ecall-based context switching (preliminary kernel)
- **Status:** ✅ Hardware verified

### Test 07: UART0 TX Interrupt (Char-by-Char)
- **Goal:** Verify character-by-character UART TX interrupt
- **Status:** ✅ Hardware verified

### Test 08: Dual-Core Boot
- **Goal:** Verify Core 1 launch via SIO FIFO mailbox protocol
- **Key discovery:** Hazard3 `h3.unblock` (`slt x0, x0, x1`) required to wake Core 1
- **Status:** ✅ Hardware verified

### Test 09: Dual-Core TIM0 Alarm Interrupts
- **Goal:** Alarm 0 on Core 0, Alarm 1 on Core 1
- **Key discovery:** TIMER0->INTE non-atomic R-M-W race between cores; fixed by setting both INTE bits from Core 0
- **Status:** ✅ Hardware verified

### Test 10: Dual-Core Spin Lock
- **Goal:** Verify C11 atomic_flag spinlock across two cores
- **Status:** ✅ Hardware verified

### Test 11: Inter-Core Doorbell Interrupt
- **Goal:** Core 0 rings SIO doorbell, Core 1 handles via IRQ 26
- **Key discovery:** Hazard3 MEIPRA defaults to priority 0 ("never taken") for SIO_IRQ_BELL; explicit `core_setExternalIRQPriority(irq, 1)` required
- **Status:** ✅ Hardware verified

## File Structure

```
Pico2_rp2350_RISC-V/
├── CMakeLists.txt          # Build configuration
├── first_rv.c              # RISC-V startup code (full version)
├── picobin_rv.c            # Boot block (ARCHSEL=1 for RISC-V)
├── init.c                  # Hardware initialisation
├── cmns.c                  # Common functions (delays, UART)
├── tests.c                 # Test dispatcher
├── tests_00.c              # Test 0: LED blink
├── tests_01.c              # Test 1: UART send
├── tests_02.c              # Test 2: UART echo
├── tests_03.c              # Test 3: UART0 RX interrupt
├── tests_04.c              # Test 4: UART0 TX interrupt
├── tests_05.c              # Test 5: TIM0 alarm interrupts
├── tests_06.c              # Test 6: Pico-kernel (ecall)
├── tests_07.c              # Test 7: UART0 TX char-by-char
├── tests_08.c              # Test 8: Dual-core boot
├── tests_09.c              # Test 9: Dual-core timer IRQs
├── tests_10.c              # Test 10: Dual-core spin lock
├── tests_11.c              # Test 11: Inter-core doorbell
├── Includes/
│   ├── board.h             # Board-specific definitions
│   ├── tests.h             # Test headers
│   ├── Core/               # RISC-V core headers
│   └── SOC/                # RP2350 peripheral headers
└── Runtime/
    ├── link_p.ld           # Main linker script
    ├── system_p.ld         # Section definitions
    └── rp2350.ld           # SoC memory map
```

## Building

### Prerequisites
```bash
# RISC-V toolchain must be installed
export PATH_GCC_RVXX=/opt/embedded/cross/gcc-current/riscv
```

### Build Test 00 (LED Blink)
```bash
cd /Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv-lva/Tools/TestRom/Pico2_rp2350_RISC-V

# Clean build
rm -rf build
cmake -S . -B build -DTEST_NUMBER=00 -DBOARD=Pico2

# Compile
cmake --build build

# Files generated in build/:
# - testROM.elf (ELF with debug symbols)
# - testROM.bin (raw binary)
# - testROM.hex (Intel HEX format)
# - testROM.map (memory map)
```

### Build Other Tests
```bash
cmake -S . -B build -DTEST_NUMBER=01  # UART send
cmake -S . -B build -DTEST_NUMBER=02  # UART echo
cmake -S . -B build -DTEST_NUMBER=03  # UART0 RX interrupt
# ... through TEST_NUMBER=11 (doorbell)
```

## Flashing

### Method 1: UF2 Bootloader
```bash
# Convert to UF2
picotool uf2 convert build/testROM.elf build/testROM.uf2 --family rp2350-riscv

# Flash: Hold BOOTSEL, connect USB, copy file
cp build/testROM.uf2 /Volumes/RPI-RP2/
```

### Method 2: Direct (requires picotool with USB)
```bash
picotool load build/testROM.elf --family rp2350-riscv --verify
```

## Hardware Connections

### LEDs (Test 00)
- **GPIO25** - System LED (onboard LED on Pico 2)
- **GPIO11** - Yellow LED
- **GPIO12** - Green LED
- **GPIO13** - Red LED

Connect external LEDs through 330Ω resistors to GND.

### UART (Test 01+)
- **GPIO16** - UART0 TX (output to serial monitor)
- **GPIO17** - UART0 RX (input from serial terminal)
- **Baud:** 460800 8N1
- **Voltage:** 3.3V logic level

## Expected Behavior

### Test 00: LED Blink
1. Power on Pico 2
2. All 4 LEDs should blink in sequence:
   - System LED (GPIO25) on for 100ms
   - Yellow LED (GPIO11) on for 100ms
   - Green LED (GPIO12) on for 100ms
   - Red LED (GPIO13) on for 100ms
   - Repeat continuously

**If not working:**
- Check picobin block has ARCHSEL=1 (RISC-V mode)
- Verify clock initialisation (should be 150 MHz)
- Check GPIO configuration
- Review startup code execution

## Debugging

### Check Binary Format
```bash
# Verify it's RISC-V
file build/testROM.elf
# Should show: "ELF 32-bit LSB executable, UCB RISC-V"

# Check picobin block
hexdump -C build/testROM.bin | grep "d3 de ff ff"
# Should show: d3 de ff ff 42 01 11 10
#                              ^^
#                              0x11 = RISC-V
```

### Memory Map
```bash
# View memory usage
cat build/testROM.map | grep "Memory region"
```

### Serial Debug (Test 01+)
```bash
# Connect serial monitor
screen /dev/tty.usbserial-* 460800

# Or use minicom
minicom -D /dev/tty.usbserial-* -b 460800
```

## Key Differences from ARM Version

| Feature              | ARM Cortex-M33            | RISC-V Hazard3                     |
|----------------------|---------------------------|------------------------------------|
| Entry Point          | Reset_Handler             | Reset_C0_Handler                   |
| Vector Table         | .isr_vector               | .text_vectors                      |
| Boot Block Byte 6    | 0x21 (ARM)                | 0x11 (RISC-V)                      |
| Startup File         | first.c                   | first_rv.c                         |
| Small Data Sections  | None                      | .sdata, .srodata                   |
| Delay Loop           | WFE instruction           | WFI instruction                    |
| Stack Alignment      | 8-byte                    | 16-byte (RISC-V ABI)              |
| IRQ Enable           | NVIC_EnableIRQ()          | core_enableExternalIRQ() (MEIEA)   |
| IRQ Priority         | NVIC_SetPriority()        | core_setExternalIRQPriority() (MEIPRA) |
| Global IRQ Enable    | `cpsie i`                 | INTERRUPTION_ON_HARD (mstatus.MIE) |
| SEV (wake other core)| `sev` instruction         | `slt x0, x0, x1` (h3.unblock)     |
| Ecall/SVC            | `svc #0`                  | `ecall`                            |

## Troubleshooting

### No LEDs Blinking

**Check 1: Verify RISC-V boot**
```bash
hexdump -C build/testROM.bin | head -30
# Look for RISC-V instructions at start (not ARM Thumb)
```

**Check 2: Clock not running**
- PLL configuration might be incorrect
- System clock not switched to PLL
- Review `local_PLL_Configuration()` in init.c

**Check 3: GPIO not configured**
- IO_BANK0 not released from reset
- GPIO function not set to SIO
- GPIO output enable not set

**Check 4: Code not reaching main**
- BSS/data not initialized correctly
- Stack pointer incorrect
- Trap in early boot code

### Incorrect LED Timing

**Too fast:** Reduce `cmns_wait()` parameter in tests_00.c

**Too slow:** Increase `cmns_wait()` parameter

**Calibration:** Adjust divisor in cmns.c line 207 based on actual clock speed

### Build Errors

**"undefined reference to..."**
- Check that all required .c files are in CMakeLists.txt
- Verify include paths are correct

**"section overlaps"**
- Linker script memory regions conflict
- Check Runtime/link_p.ld and Runtime/system_p.ld

## Next Steps

1. **Integrate with OS** - Use working TestROM code in full uKOS-X target

## References

- [RP2350 Datasheet](https://datasheets.raspberrypi.com/rp2350/rp2350-datasheet.pdf)
- [RISC-V Hazard3 Core Specification](https://github.com/Wren6991/Hazard3)
- ARM Cortex-M33 TestROM: `Tools/TestRom/Pico2_rp2350_Cortex-M33/`
- Full Target: `Ports/Targets/Pico2_rp2350_RVXX/`

## License

SPDX-License-Identifier: MIT
