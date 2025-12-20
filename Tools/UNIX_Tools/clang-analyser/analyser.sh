#!/usr/bin/env zsh

# analyser.
# =========

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-11-13
# Modifs:
#
# Project:	uKOS-X
# Goal:		Run clang analyser; replace scan-build not working with CMake
#			and use clang-tidy as linter tool.
#
#			Usage:
#				alias run-analyser='$PATH_UKOS_X_PACKAGE/Tools/UNIX_Tools/clang-analyser/analyser.sh'
#				cd variant
#				run-analyser
#
#   © 2025-20xx, Laurent von Allmen
#   -------------------------------
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

emulate -L zsh
setopt ERR_EXIT NO_UNSET PIPE_FAIL EXTENDED_GLOB

# Determine script directory (works if executed via ./script.sh or zsh script.sh)
readonly PATH_PRG="${0:A:h}"

# Colours for messages
readonly RED='\033[0;31m'
readonly GREEN='\033[0;32m'
readonly YELLOW='\033[0;33m'
readonly BLUE='\033[0;34m'
readonly BOLD='\033[1m'
readonly FAINT='\033[2m'
readonly ITALIC='\033[3m'
readonly NC='\033[0m' # No Color

# Check if in a project directory
if [[ ! -f CMakeLists.txt ]]; then
	print "Error: not in a target directory"
	exit 1
fi

# Derive project name from current directory
readonly PROJECT_NAME=$(basename $(pwd))
readonly OUTPUT_DIR=Static_Analysis
readonly BUILD_DIR="${OUTPUT_DIR}/build"

# Fresh output directory
rm -rf "${OUTPUT_DIR}"
mkdir -p "${OUTPUT_DIR}"
echo "*" > "${OUTPUT_DIR}"/.gitignore

printf "%bBuilding list of files to check%b\n" "${YELLOW}" "${NC}"
if ! cmake -S . -B "${BUILD_DIR}" -DUSE_LLVM=ON -DCMAKE_EXPORT_COMPILE_COMMANDS=ON > /dev/null 2>&1; then
	printf "%bError: CMake configuration failed%b\n" "${RED}" "${NC}" >&2
	printf "Please check that the 'llvm' preset is defined and your CMake configuration is correct.\n" >&2
	exit 1
fi
readonly COMPILE_DB="${BUILD_DIR}/compile_commands.json"

if [[ ! -f "${COMPILE_DB}" ]]; then
    print "Error: ${COMPILE_DB} not found after CMake configure"
    exit 1
fi

printf '%b═══════════════════════════════════════════════════════════════
  Clang Static Analyzer
═══════════════════════════════════════════════════════════════%b\n\n' "${BLUE}" "${NC}"

# Total number of files
readonly length_DB=$(jq length "${COMPILE_DB}")
if grep -q "sig\.c" "${COMPILE_DB}"; then
	readonly TOTAL=$((length_DB - 1))
else
	readonly TOTAL=${length_DB}
fi
printf 'Found %d C/C++ files to analyze\n' "${TOTAL}"

# Pre-parse the entire compile_commands.json once for performance
# This avoids calling jq multiple times per file in the loop
printf '%bParsing compile database...%b\n' "${YELLOW}" "${NC}"

# Cache file paths and names
declare -a filenames
# Cache all_commands as serialized strings (we'll parse per-file later)
declare -a all_commands
while IFS= read -r entry; do
    file=$(jq -r '.[0]' <<< "$entry")
    command=$(jq -r '.[1]' <<< "$entry")
    filenames+=("${file##*/}")
    all_commands+=("$command")
done < <(jq -cr '.[] | [.file, .command]' "${COMPILE_DB}")

if [[ $length_DB -ne ${#all_commands[@]} ]] ||
   [[ $length_DB -ne ${#filenames[@]} ]]; then
    printf "Internal error: compile_commands.json arrays inconsistent\n" >&2
    exit 2
fi

# Parse and analyze each file
warnings=0

for current in {1..$length_DB}; do
    filename="${filenames[$current]}"

    # Skip signature files explicitly
    if [[ $filename == *.sig.c ]]; then
        continue
    fi

    # Accept only C-family source files
    case "$filename" in
        *.c|*.cc|*.cpp|*.cxx)
            ;;   # OK
        *)
            continue
            ;;
    esac

    printf "[%3d/%3d] %-40s " "$current" "${TOTAL}" "$filename"

    # Rewrite the -o <...>.o part to analyzer invocation
    cmd_data="${all_commands[$current]}"
    analyse_cmd=$(
        printf '%s\n' "${cmd_data}" | sed -E \
            -e 's|-o [^ ]*\.o|--analyze -Xanalyzer -analyzer-output=html|' \
            -e 's| -c | |'
    )
    analyse_cmd+=' -Xanalyzer -analyzer-disable-checker=core.FixedAddressDereference -o "$OUTPUT_DIR"'

    # Run analyzer; do not abort on failures, but capture output
    analyse_res=$(eval "${analyse_cmd}" 2>&1 || true)

    # Count warnings safely (removes whitespace/newlines)
    count=$(grep -c 'warning:' <<< "$analyse_res" || true)
    count=$(echo "$count" | tr -d '[:space:]')

    # Report results
    if [[ "$count" -gt 0 ]]; then
        printf '✗ %d warnings\n' "$count"
        warnings=$((warnings + count))
    else
        printf '✓\n'
    fi

done

readonly COMPILER="${analyse_cmd%% *}"

printf '\n═══════════════════════════════════════════════════════════════\n'

# Report analyzer results
if [[ "$warnings" -eq 0 ]]; then
    printf '%b  Analyzer: No issues found!%b\n' "${BOLD}" "${NC}"
    printf '═══════════════════════════════════════════════════════════════\n'
else
    printf '%b  Analysis Complete: %d warnings found%b\n' "${BOLD}" "$warnings" "${NC}"
    printf '═══════════════════════════════════════════════════════════════\n'
fi

# ═══════════════════════════════════════════════════════════════
# PHASE 2: Run clang-tidy (separate from analyzer)
# ═══════════════════════════════════════════════════════════════

# Detect which clang-tidy to use
# Prefer embedded toolchain clang-tidy (matches compiler) over system clang-tidy
detect_clang_tidy_path() {
	local compile_db="$1"
	local compiler_path=$(jq -r '.[0].command' "${compile_db}" | awk '{print $1}')

	# Determine architecture from compiler path
	if [[ "$compiler_path" == *"riscv"* ]] || [[ "$compiler_path" == *"RVXX"* ]]; then
		# RISC-V architecture: check embedded toolchain first
		if [[ -x "${PATH_LLVM_RVXX}/bin/clang-tidy" ]]; then
			echo "${PATH_LLVM_RVXX}/bin/clang-tidy"
			return
		fi
	else
		# ARM architecture: check embedded toolchain first
		if [[ -x "${PATH_LLVM_ARM}/bin/clang-tidy" ]]; then
			echo "${PATH_LLVM_ARM}/bin/clang-tidy"
			return
		fi
	fi
}

readonly CLANG_TIDY=$(detect_clang_tidy_path "${COMPILE_DB}")

# Verify clang-tidy is available
if [[ ! -x "${CLANG_TIDY}" ]]; then
	printf "%bWarning: clang-tidy not found at %s%b\n" "${YELLOW}" "${CLANG_TIDY}" "${NC}" >&2
	printf "%bSkipping clang-tidy checks%b\n" "${YELLOW}" "${NC}" >&2
	exit 1
fi

readonly tidy_config_file="${PATH_PRG}/dot-clang-tidy"
if [[ ! -f "${tidy_config_file}" ]]; then
	print "ERROR: missing file ${tidy_config_file}"
	exit 1
fi

printf '\n%b═══════════════════════════════════════════════════════════════
  Running clang-tidy checks
═══════════════════════════════════════════════════════════════%b\n\n' "${BLUE}" "${NC}"

printf '%bUsing: %s\n' "${YELLOW}" "${CLANG_TIDY}"
printf 'Config: %s%b\n\n' "${tidy_config_file}" "${NC}"

# Create tidy output directory
readonly TIDY_OUTPUT="${OUTPUT_DIR}/tidy-reports"
mkdir -p "${TIDY_OUTPUT}"

# Run clang-tidy on all source files
tidy_warnings=0
tidy_file_count=0

for current in {1..$length_DB}; do
	filename="${filenames[$current]}"

	# Skip signature files
	if [[ $filename == *.sig.c ]]; then
		continue
	fi

	# Accept only C-family source files
	case "$filename" in
		*.c|*.cc|*.cpp|*.cxx)
			;;
		*)
			continue
			;;
	esac

	# Get source file path
	source_file=$(jq -r ".[$((current-1))].file" "${COMPILE_DB}")

	printf "[%3d/%3d] %-40s " "$current" "${TOTAL}" "$filename"

	# Run clang-tidy and capture output (filter out summary lines)
	tidy_output_file="${TIDY_OUTPUT}/${filename}.txt"
	tidy_fix_file="${TIDY_OUTPUT}/${filename}.yaml"
	"${CLANG_TIDY}" -config-file="${tidy_config_file}" -p="${BUILD_DIR}" --export-fixes="${tidy_fix_file}" -checks=-clang-analyzer-core.FixedAddressDereference "${source_file}" 2>&1 | \
		sed -E '/warnings generated\./d; /^Suppressed .* warnings/d; /^Use -header-filter=/d' > "${tidy_output_file}" || true

	# Count warnings in output
	file_warnings=$(grep -c ': warning:' "${tidy_output_file}" 2>/dev/null || echo "0")
	file_warnings=$(echo "$file_warnings" | tr -d '[:space:]')

	if [[ "$file_warnings" -gt 0 ]]; then
		printf '✗ %d warnings\n' "$file_warnings"
		tidy_warnings=$((tidy_warnings + file_warnings))
		tidy_file_count=$((tidy_file_count + 1))
	else
		printf '✓\n'
		# Remove empty output file
		rm -f "${tidy_output_file}"
	fi
done

# Generate summary report
printf '\n═══════════════════════════════════════════════════════════════\n'

if [[ "$tidy_warnings" -eq 0 ]]; then
	printf '%b  clang-tidy: No issues found!%b\n' "${BOLD}" "${NC}"
	printf '═══════════════════════════════════════════════════════════════\n'
	rm -fr "${TIDY_OUTPUT}"
else
	printf '%b  clang-tidy Complete: %d warnings in %d files%b\n' "${BOLD}" "$tidy_warnings" "$tidy_file_count" "${NC}"
	printf '═══════════════════════════════════════════════════════════════\n'
	printf '\nTidy reports: %s\n' "${TIDY_OUTPUT}"

	# Create simple index file for tidy reports
	{
		echo "clang-tidy Analysis Results"
		echo "==========================="
		echo ""
		echo "Total warnings: ${tidy_warnings}"
		echo "Files with warnings: ${tidy_file_count}"
		echo ""
		echo "Individual reports:"
		for report in "${TIDY_OUTPUT}"/*.txt; do
			if [[ -f "$report" ]]; then
				basename=$(basename "$report")
				count=$(grep -c ': warning:' "$report" || echo "0")
				echo "  - ${basename}: ${count} warnings"
			fi
		done
	} > "${TIDY_OUTPUT}/index.tmp"
	mv "${TIDY_OUTPUT}/index.tmp" "${TIDY_OUTPUT}/index.txt"
	printf 'Tidy summary: %s/index.txt\n\n' "${TIDY_OUTPUT}"

	# Generate HTML reports from .txt and .yaml files using Python script
	printf '%bGenerating HTML reports from clang-tidy output...%b\n' "${YELLOW}" "${NC}"
	python3 "${PATH_PRG}/make-tidy-html.py" "${TIDY_OUTPUT}"
fi

# ═══════════════════════════════════════════════════════════════
# Generate unified HTML report (analyzer + tidy)
# ═══════════════════════════════════════════════════════════════

if [[ "$warnings" -gt 0 ]] || [[ "${tidy_warnings:-0}" -gt 0 ]]; then
	printf '%bGenerating unified HTML report...%b\n\n' "${YELLOW}" "${NC}"

	# Prepare analyzer table if warnings exist
	if [[ "$warnings" -gt 0 ]]; then
		python3 "${PATH_PRG}/make-reports-table.py" "${OUTPUT_DIR}"
	fi

	readonly COMPILER_VERSION="$($COMPILER --version | head -n 1)"
	readonly USERNOM="$(whoami)@$(hostname)"

	# Generate unified index.html
	rm -f "${OUTPUT_DIR}/index.html"

	{
		cat <<EOF
<html>
<head>
<title>${PROJECT_NAME} - Static Analysis Results</title>
EOF
		cat "${PATH_PRG}/head.html"
		cat <<EOF
<body>
<h1>${PROJECT_NAME} - Static Analysis Results</h1>

<table>
<tr><th>User:</th><td>${USERNOM}</td></tr>
<tr><th>Working Directory:</th><td>$(pwd)</td></tr>
<tr><th>Clang Version:</th><td>${COMPILER_VERSION}</td></tr>
<tr><th>Date:</th><td>$(date +"%a %d %b %H:%M:%S %Y")</td></tr>
</table>

<!-- Analyzer Section -->
<h2>Clang Static Analyzer Results</h2>
EOF

		if [[ "$warnings" -gt 0 ]]; then
			cat <<EOF
<p>Total warnings: ${warnings}</p>

<h3>Bug Summary</h3>
<table>
<thead><tr><td>Bug Type</td><td>Quantity</td><td class="sorttable_nosort">Display?</td></tr></thead>
<tr style="font-weight:bold"><td class="SUMM_DESC">All Bugs</td><td class="Q">${warnings}</td><td><center><input type="checkbox" id="AllBugsCheck" onClick="CopyCheckedStateToCheckButtons(this);" checked/></center></td></tr>
<tr><th>Logic error</th><th colspan=2></th></tr>
<tr><td class="SUMM_DESC">Dereference of a fixed address</td><td class="Q">${warnings}</td><td><center><input type="checkbox" onClick="ToggleDisplay(this,'bt_logic_error_dereference_of_a_fixed_address');" checked/></center></td></tr>
</table>

<h3>Filter Results by File</h3>
<input
  type="text"
  id="file_input"
  onkeyup="searchFiles()"
  placeholder="Enter a path or filename"
  title="Enter a path or filename">

<h3>Analyzer Reports</h3>

EOF
			cat "${OUTPUT_DIR}/table4index.html"
		else
			echo "<p><em>No issues found</em></p>"
		fi

		# Add tidy section if tidy reports exist
		if [[ -d "${OUTPUT_DIR}/tidy-reports" ]] && [[ "${tidy_warnings:-0}" -gt 0 ]]; then
			cat <<EOF

<!-- clang-tidy Section -->
<h2>clang-tidy Results</h2>
<p>Total warnings: ${tidy_warnings} in ${tidy_file_count} files</p>

<h3>Check Categories</h3>
<p>Enabled checks: cert-*, bugprone-*, misc-*, performance-*, portability-*, modernize-* (selected)</p>

<h3>Tidy Reports</h3>
<table id="tidy_reports_table" class="sortable">
<thead><tr>
  <td>File</td>
  <td class="Q">Warnings</td>
  <td class="sorttable_nosort">Report</td>
</tr></thead>
<tbody>
EOF
			# Generate table rows for tidy reports
			for report in "${OUTPUT_DIR}/tidy-reports"/*.txt; do
				if [[ -f "$report" ]] && [[ "$(basename "$report")" != "index.txt" ]]; then
					report_basename=$(basename "$report")
					report_filename="${report_basename%.txt}"
					report_count=$(grep -c ': warning:' "$report" || echo "0")
					html_report="tidy-reports/${report_filename}.html"

					echo "<tr>"
					echo "  <td>${report_filename}</td>"
					echo "  <td class=\"Q\">${report_count}</td>"
					echo "  <td><a href=\"${html_report}\">View Report</a></td>"
					echo "</tr>"
				fi
			done
			cat <<EOF
</tbody>
</table>
EOF
		fi

		cat <<EOF
</body>
</html>
EOF
	} > "${OUTPUT_DIR}/index.html"

	# Copy CSS and JS files
	cp -f "${PATH_PRG}/scanview.css" "${OUTPUT_DIR}"
	cp -f "${PATH_PRG}/sorttable.js" "${OUTPUT_DIR}"

	# Clean up temporary files
	rm -f "${OUTPUT_DIR}"/table4index.html
	rm -fr "${OUTPUT_DIR}"/build

	printf '%bReport generated: %s/index.html%b\n\n' "${GREEN}" "$OUTPUT_DIR" "${NC}"
fi

# Final cleanup (keep tidy-reports/ if it exists)
if [[ "$warnings" -gt 0 ]] || [[ "${tidy_warnings:-0}" -gt 0 ]]; then
	# Keep build directory for debugging if warnings found
	case "$(uname)" in
		"Darwin")
			open "${OUTPUT_DIR}"/index.html
			;;
		"Linux")
			printf "%bopen Static_Analysis/html/index.html in your browswer.%b\n" "${BOLD}" "${NC}"
			;;
	esac
else
	# Clean up build directory if no issues found anywhere
	rm -fr "${OUTPUT_DIR}"
fi
