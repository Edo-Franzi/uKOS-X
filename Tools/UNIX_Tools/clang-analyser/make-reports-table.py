#!/usr/bin/env python3

# make-reports-table.
# ===================

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-11-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Generate HTML table for static analysis reports
#
#   (c) 2025-2026, Laurent von Allmen
#   ---------------------------------
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

"""
Generate HTML table for static analysis reports.

This script scans report-*.html files in the analyser-reports directory,
extracts bug information from HTML comments, and generates a table HTML file.

Usage:
    python3 make-reports-table.py analyser-reports-directory

The script will:
1. Scan all report-*.html files in the specified directory
2. Extract bug metadata from HTML comments (BUGCATEGORY, BUGTYPE, BUGFILE, etc.)
3. Generate an HTML table with proper CSS classes and sortable structure
4. Save the output to table4index.html in the same directory

The table can then be inserted into index.html for display.
"""

import os
import re
import subprocess
import sys
from pathlib import Path
from typing import Dict, List, Optional

# Pre-compile regex patterns for performance
# Used to extract values from HTML comment tags like <!-- BUGTYPE Logic error -->
COMMENT_TAG_PATTERN = re.compile(r'<!--\s+(\w+)\s+(.*?)\s*-->')
# Used to normalize bug type class names (convert to lowercase, replace special chars)
NON_ALPHANUMERIC_PATTERN = re.compile(r'[^a-z0-9]+')
MULTIPLE_UNDERSCORES_PATTERN = re.compile(r'_+')


def get_git_repo_root() -> Optional[str]:
    """
    Get the root directory of the git repository.

    Returns:
        Absolute path to git repository root with trailing slash, or None if not in a git repo.
    """
    try:
        result = subprocess.run(
            ['git', 'rev-parse', '--show-toplevel'],
            capture_output=True,
            text=True,
            check=True
        )
        repo_root = result.stdout.strip()
        # Ensure trailing slash for consistent prefix removal
        return repo_root + '/' if repo_root else None
    except (subprocess.CalledProcessError, FileNotFoundError):
        return None


def extract_comment_value(content: str, tag: str) -> Optional[str]:
    """Extract value from HTML comment tag."""
    # Use pre-compiled pattern for better performance
    for match in COMMENT_TAG_PATTERN.finditer(content):
        if match.group(1) == tag:
            return match.group(2).strip()
    return None


def normalize_bug_type_class(bug_category: str, bug_type: str) -> str:
    """Create normalized CSS class name from bug category and type."""
    combined = f"{bug_category}_{bug_type}"
    # Convert to lowercase and replace spaces/special chars with underscores using pre-compiled pattern
    normalized = NON_ALPHANUMERIC_PATTERN.sub('_', combined.lower())
    # Remove leading/trailing underscores and collapse multiple underscores using pre-compiled pattern
    normalized = MULTIPLE_UNDERSCORES_PATTERN.sub('_', normalized).strip('_')
    return f"bt_{normalized}"


def parse_report_file(filepath: Path, repo_prefix: str) -> Dict[str, str]:
    """
    Parse a report HTML file and extract bug information.

    Args:
        filepath: Path to the report HTML file
        repo_prefix: Path prefix to remove from BUGFILE

    Returns:
        Dictionary with extracted bug information

    Raises:
        ValueError: If required tags are missing or invalid
    """
    with open(filepath, 'r', encoding='utf-8') as f:
        content = f.read()

    # Extract required fields
    bug_category = extract_comment_value(content, 'BUGCATEGORY')
    bug_type = extract_comment_value(content, 'BUGTYPE')
    bug_file = extract_comment_value(content, 'BUGFILE')
    function_name = extract_comment_value(content, 'FUNCTIONNAME')
    bug_line = extract_comment_value(content, 'BUGLINE')
    bug_path_length = extract_comment_value(content, 'BUGPATHLENGTH')

    # Validate all required fields are present
    missing_fields = []
    if not bug_category:
        missing_fields.append('BUGCATEGORY')
    if not bug_type:
        missing_fields.append('BUGTYPE')
    if not bug_file:
        missing_fields.append('BUGFILE')
    if not function_name:
        missing_fields.append('FUNCTIONNAME')
    if not bug_line:
        missing_fields.append('BUGLINE')
    if not bug_path_length:
        missing_fields.append('BUGPATHLENGTH')

    if missing_fields:
        raise ValueError(f"Missing required tags: {', '.join(missing_fields)}")

    # Remove repository prefix from file path
    if bug_file.startswith(repo_prefix):
        bug_file = bug_file[len(repo_prefix):]
    else:
        raise ValueError(
            f"BUGFILE path does not start with expected prefix.\n"
            f"Expected prefix: {repo_prefix}\n"
            f"Actual path: {bug_file}"
        )

    return {
        'bug_category': bug_category,
        'bug_type': bug_type,
        'file': bug_file,
        'function': function_name,
        'line': bug_line,
        'path_length': bug_path_length,
        'report_file': filepath.name
    }


def generate_table_html(reports: List[Dict[str, str]]) -> str:
    """
    Generate HTML table from report data.

    Args:
        reports: List of dictionaries containing bug information

    Returns:
        HTML string for the table
    """
    html_parts = []

    # Table opening with proper attributes
    html_parts.append('<table id="reports_table" class="sortable" style="table-layout:automatic">')

    # Table header
    html_parts.append('<thead><tr>')
    html_parts.append('  <td>Bug Group</td>')
    html_parts.append('  <td class="sorttable_sorted">Bug Type<span id="sorttable_sortfwdind">&nbsp;&#x25BE;</span></td>')
    html_parts.append('  <td>File</td>')
    html_parts.append('  <td>Function/Method</td>')
    html_parts.append('  <td class="Q">Line</td>')
    html_parts.append('  <td class="Q">Path Length</td>')
    html_parts.append('  <td class="sorttable_nosort"></td>')
    html_parts.append('  <!-- REPORTBUGCOL -->')
    html_parts.append('</tr></thead>')

    # Table body
    html_parts.append('<tbody>')

    for report in reports:
        # Generate row class from bug category and type
        row_class = normalize_bug_type_class(report['bug_category'], report['bug_type'])

        html_parts.append(f'<tr class="{row_class}">')
        html_parts.append(f'  <td class="DESC">{report["bug_category"]}</td>')
        html_parts.append(f'  <td class="DESC">{report["bug_type"]}</td>')
        html_parts.append(f'  <td>{report["file"]}</td>')
        html_parts.append(f'  <td class="DESC">{report["function"]}</td>')
        html_parts.append(f'  <td class="Q">{report["line"]}</td>')
        html_parts.append(f'  <td class="Q">{report["path_length"]}</td>')
        html_parts.append(f'  <td><a href="{report["report_file"]}#EndPath">View Report</a></td>')
        html_parts.append(f'  <!-- REPORTBUG id="{report["report_file"]}" -->')
        html_parts.append('</tr>')

    html_parts.append('</tbody>')
    html_parts.append('</table>')

    return '\n'.join(html_parts)


def main():
    """Main function to generate the reports table."""
    # Auto-detect git repository root for portable path prefix removal
    repo_prefix = get_git_repo_root()
    if not repo_prefix:
        print("Error: Not in a git repository. Cannot determine repository root.", file=sys.stderr)
        print("Please run this script from within a git repository.", file=sys.stderr)
        sys.exit(1)

    # Check command-line arguments
    if len(sys.argv) != 2:
        print("Usage: python3 make-reports-table.py analyser-reports-directory", file=sys.stderr)
        sys.exit(1)

    reports_dir = Path(sys.argv[1])
    output_file = reports_dir / 'table4index.html'

    # Check if reports directory exists
    if not reports_dir.exists():
        print(f"Error: Reports directory does not exist: {reports_dir}", file=sys.stderr)
        sys.exit(1)

    # Find all report HTML files
    report_files = sorted(reports_dir.glob('report-*.html'))

    if not report_files:
        print(f"Error: No report-*.html files found in {reports_dir}", file=sys.stderr)
        sys.exit(1)

    print(f"Found {len(report_files)} report files")

    # Parse all report files
    reports = []
    for report_file in report_files:
        try:
            report_data = parse_report_file(report_file, repo_prefix)
            reports.append(report_data)
        except ValueError as e:
            # Missing required tags or path prefix mismatch
            print(f"Error processing file: {report_file}", file=sys.stderr)
            print(f"Error: {e}", file=sys.stderr)
            sys.exit(1)
        except (OSError, IOError) as e:
            # File reading errors
            print(f"Error reading file: {report_file}", file=sys.stderr)
            print(f"Error: {e}", file=sys.stderr)
            sys.exit(1)
        except UnicodeDecodeError as e:
            # File encoding issues
            print(f"Error decoding file: {report_file}", file=sys.stderr)
            print(f"Error: {e}", file=sys.stderr)
            sys.exit(1)

    # Generate HTML table
    table_html = generate_table_html(reports)

    # Write output file
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(table_html)

    print(f"Successfully generated table with {len(reports)} entries")
    print(f"Output written to: {output_file}")


if __name__ == '__main__':
    main()
