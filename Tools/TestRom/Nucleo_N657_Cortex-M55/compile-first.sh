#!/usr/bin/env zsh

# Based on the command from a compile_commands.json
# /opt/embedded/cross/gcc-current/arm/bin/arm-none-eabi-gcc -DCACHE_S -DSECURE_S -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/_Commun -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/_Commun/Includes -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/_Commun/Runtime -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/Nucleo_N657_Cortex-M55 -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/Nucleo_N657_Cortex-M55/Includes -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/Nucleo_N657_Cortex-M55/Includes/SOC -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/Nucleo_N657_Cortex-M55/Includes/Core -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/Nucleo_N657_Cortex-M55/Runtime -g -Os -Wall -Wlogical-op -mcpu=cortex-m55 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 -o first.c.o -c first.c
# make a function so that it is possible to play with compile options:
# -mcpu=
# -mthumb
# -mfloat-abi=
# -mfpu=

export SOURCE_DATE_EPOCH=1785062700

local_cc() {
/opt/embedded/cross/gcc-current/arm/bin/arm-none-eabi-gcc -DCACHE_S -DSECURE_S -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/_Commun -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/_Commun/Includes -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/_Commun/Runtime -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/Nucleo_N657_Cortex-M55 -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/Nucleo_N657_Cortex-M55/Includes -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/Nucleo_N657_Cortex-M55/Includes/SOC -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/Nucleo_N657_Cortex-M55/Includes/Core -I/Users/lva/Dev/edo-rtos-uKOSX/uKOS-X-priv/Tools/TestRom/Nucleo_N657_Cortex-M55/Runtime -Os -Wall -Wlogical-op $@ -o first.o -c first.c
}

local_objdump=/opt/embedded/cross/gcc-current/arm/bin/arm-none-eabi-objdump
local_readelf=/opt/embedded/cross/gcc-current/arm/bin/arm-none-eabi-readelf
local_size=/opt/embedded/cross/gcc-current/arm/bin/arm-none-eabi-size

local_green='\033[0;32m'
local_red='\033[0;31m'
local_reset='\033[0m'

compare_objects() {
	local ref=$1
	local other=$2

	if cmp -s "$ref" "$other"; then
		echo "${local_green}$ref and $other are byte-identical${local_reset}"
		return
	fi

	local size_ref=$(stat -f%z "$ref")
	local size_other=$(stat -f%z "$other")

	if [[ $size_ref -ne $size_other ]]; then
		echo "$ref and $other differ in size: $size_ref vs $size_other bytes (delta: $((size_other - size_ref)))"
	else
		echo "$ref and $other differ (same size: $size_ref bytes)"
	fi

	# Check if code (.text) differs
	local text_diff=$(diff <($local_objdump -d "$ref" | tail -n +3) <($local_objdump -d "$other" | tail -n +3))
	if [[ -n "$text_diff" ]]; then
		echo "  ${local_red}.text (code) DIFFERS${local_reset}"
		echo "$text_diff"
	else
		echo "  ${local_green}.text (code) is identical${local_reset}"
	fi

	# Check functional sections (.rodata, .data, .bss)
	local func_sections_differ=0
	for section in .rodata .data .bss; do
		local sec_diff=$(diff \
			<($local_objdump -s -j "$section" "$ref" 2>/dev/null | tail -n +5) \
			<($local_objdump -s -j "$section" "$other" 2>/dev/null | tail -n +5))
		if [[ -n "$sec_diff" ]]; then
			echo "  ${local_red}$section DIFFERS${local_reset}"
			func_sections_differ=1
		fi
	done

	if [[ -z "$text_diff" && $func_sections_differ -eq 0 ]]; then
		echo "  ${local_green}Functionally identical (same .text, .rodata, .data, .bss)${local_reset}"
	fi

	# Identify which other sections differ
	local sections=$($local_objdump -h "$ref" | awk 'NR>5 && NF>=2 {print $2}')
	for section in ${(f)sections}; do
		[[ "$section" == .text || "$section" == .rodata || "$section" == .data || "$section" == .bss ]] && continue
		local sec_diff=$(diff \
			<($local_objdump -s -j "$section" "$ref" 2>/dev/null | tail -n +5) \
			<($local_objdump -s -j "$section" "$other" 2>/dev/null | tail -n +5))
		if [[ -n "$sec_diff" ]]; then
			echo "  $section differs"
		fi
	done

	# Show ARM attributes diff if .ARM.attributes differs
	local attr_diff=$(diff \
		<($local_readelf -A "$ref" 2>/dev/null | sed '/^File:/d;/^Attribute Section:/d') \
		<($local_readelf -A "$other" 2>/dev/null | sed '/^File:/d;/^Attribute Section:/d'))
	if [[ -n "$attr_diff" ]]; then
		echo "  --- ARM attributes diff ---"
		echo "$attr_diff"
	fi

	$local_size "$ref" "$other"
	echo ""
}

# Purpose:
# Determine which compile option combinations produce functionally different
# code compared to the reference build (first-0.o). Each variant is compiled
# with a different set of -mcpu/-march/-mthumb/-mfpu flags and compared against
# first-0.o. Only .text, .rodata, .data, and .bss matter for functional
# equivalence; .ARM.attributes is ELF metadata not loaded into programme memory.
#
# Findings:
# All four compilations produce functionally identical code (.text is the same,
# no .rodata/.data/.bss differences). The only differences are in .ARM.attributes:
#   - first-0 vs first-1: byte-identical (explicit -mthumb is redundant for cortex-m55)
#   - first-0 vs first-2: Tag_ABI_HardFP_use "SP only" absent without explicit -mfpu
#   - first-0 vs first-3: Tag_CPU_name "cortex-m55" vs "8.1-M.MAIN" (-mcpu vs -march)
#                          and Tag_ABI_HardFP_use absent as above
# .ARM.attributes differences may influence linker compatibility checks when
# mixing object files with conflicting attributes.

rm -f first.o first-*(N)
local_cc -mcpu=cortex-m55 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16
mv first.o first-0.o

local_cc -mcpu=cortex-m55 -mfloat-abi=hard -mfpu=fpv5-sp-d16
mv first.o first-1.o
compare_objects first-0.o first-1.o

local_cc -mcpu=cortex-m55 -mfloat-abi=hard
mv first.o first-2.o
compare_objects first-0.o first-2.o

local_cc -march=armv8.1-m.main+mve.fp+fp.dp -mthumb -mfloat-abi=hard
mv first.o first-3.o
compare_objects first-0.o first-3.o
