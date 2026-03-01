Checking that the tests can be build with clang.

**Building the binaries of a test**

```
rm -fr build && cmake -S . -B build -DUSE_LLVM=ON -DTEST_NUMBER=00 && cmake --build build
```

**Copying to the board**

- Move jumper to programming position
- Press RESET button
- `cmake --build build --target burn`
- Move jumper to running position
- Press RESET button

The test application should be running.


$PATH_LLVM_ARM/bin/llvm-readelf --syms build/testROM.elf | grep "linker_\|config_\|stm_"

$PATH_LLVM_ARM/bin/llvm-nm --numeric-sort build/testROM.elf | grep "linker_\|config_\|stm_"

$PATH_LLVM_ARM/bin/llvm-nm build/testROM.elf | grep "linker_\|config_\|stm_" | sed 's/\([^ ]*\) [^ ]* \([^ ]*\)/\2  \1/'


# Results

## Test_00

Green LED is blinking very fast

## Test_01

The three LEDs blue, green and red are blinking.

With BLINK_PAUSE = 500000, the period is about 0,88 s

## Test_02

Text is displayed on serial link.

With BLINK_PAUSE = 1000000, the red LED blinks with a period of about 0,7 s

## Test_03

Red LED is ON at boot.

Typing 'abcd' turn OFF red LED and displays:

```
a - lala
b - lala
c - lala
d - lala
```

Then, typing '12' turn ON red LED and displays:

```
1 - lala
2 - lala
```

## Test_04

With application "Seriel" in mode 'interactive' each time a character is typed, the blue LED toggles and the text line "OK interruptions" is printed.

The red LED toggles periodically.

## Test_05

Red led toggles periodically, and text lines "This is a text ..." are printed on Serial. Typing a character toggles the blue LED.

## Test_06

Red and blue LEDs toggle. On serial terminal lines are printed

```
.
Message 0x0000887D
Message 0x0000887E
Message 0x0000887F
Message 0x00008880
Message 0x00008881
Message 0x00008882
.
```

## Test_07

Red and blue LEDs toggle. On serial terminal lines are printed

```
.
Run P0
Kernel go to P1 Stack SV 0x341042D8
Kernel go to P1 Stack P1 0x34104600
Run P1
Kernel go to P0 Stack SV 0x34104600
Kernel go to P0 Stack P0 0x341042D8
Run P0
Kernel go to P1 Stack SV 0x341042D8
Kernel go to P1 Stack P1 0x34104600
Run P1
Kernel go to P0 Stack SV 0x34104600
Kernel go to P0 Stack P0 0x341042D8
.
```

## Test_08

Both LEDs blinking at ~1 Hz — the test works correctly with LLVM. Red toggles every 500ms from cmns_wait, blue toggles every 500ms from the TIM2 interrupt handler.

## Test_09

Red LED blinking at ~6 Hz (BLINK_PAUSE = 100000), blue LED blinking at ~1 Hz from the TIM3 interrupt handler (500ms toggle).

## Test_10

Red LED blinking at ~6 Hz (BLINK_PAUSE = 100000), blue LED blinking at ~1 Hz from the TIM4 interrupt handler (500ms toggle).

## Test_11

Red LED blinking at ~6 Hz (BLINK_PAUSE = 100000), blue LED blinking at ~1 Hz from the TIM5 interrupt handler (500ms toggle).

## Test_12

Blue and green LEDs toggling — AXISRAM6 (448 KB at 0x34350000) write/verify test passes.
