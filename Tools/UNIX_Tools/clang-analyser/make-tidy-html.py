#!/usr/bin/env python3

# make-tidy-html.
# ===============

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Laurent von Allmen

#------------------------------------------------------------------------
# Author:	Laurent von Allmen	The 2025-12-04
# Modifs:
#
# Project:	uKOS-X
# Goal:		Generate HTML reports for clang-tidy from .txt and .yaml files
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
Generate HTML reports for clang-tidy analysis.

This script processes clang-tidy output files (.txt and .yaml) and generates
well-formatted HTML reports that combine information from both sources.

Usage:
    python3 make-tidy-html.py tidy-reports-directory

The script will:
1. Scan all .txt and .yaml file pairs in the specified directory
2. Parse diagnostic information from YAML files
3. Parse code snippets and line numbers from text files
4. Generate formatted HTML reports with proper styling and navigation
5. Save individual HTML files for each source file analysed

The HTML reports include:
- Source file information
- Diagnostic names and levels
- Warning messages with context
- Code snippets with line number anchors
- Links back to the main index
"""

import html
import re
import sys
import yaml
from pathlib import Path
from typing import Dict, List, Optional


# Pre-compile regex patterns for performance
# Match warning lines: filepath:line:col: warning: message [diagnostic-name]
WARNING_PATTERN = re.compile(r'^(.+?):(\d+):(\d+):\s+warning:\s+(.+?)\s+\[(.+?)\]$')


def parse_txt_file(txt_path: Path) -> List[Dict[str, str]]:
	"""
	Parse clang-tidy text output file.

	Args:
		txt_path: Path to the .txt file

	Returns:
		List of dictionaries containing warning information
	"""
	warnings = []

	with open(txt_path, 'r', encoding='utf-8') as f:
		lines = f.readlines()

	i = 0
	while i < len(lines):
		line = lines[i].rstrip('\n')
		match = WARNING_PATTERN.match(line)

		if match:
			filepath = match.group(1)
			line_num = match.group(2)
			col_num = match.group(3)
			message = match.group(4)
			diagnostic = match.group(5)

			# Collect code snippet (next lines until empty line or next warning)
			code_lines = []
			i += 1
			while i < len(lines):
				next_line = lines[i].rstrip('\n')
				if not next_line or WARNING_PATTERN.match(next_line):
					break
				code_lines.append(next_line)
				i += 1

			warnings.append({
				'filepath': filepath,
				'line': line_num,
				'column': col_num,
				'message': message,
				'diagnostic': diagnostic,
				'code_snippet': '\n'.join(code_lines)
			})
		else:
			i += 1

	return warnings


def parse_yaml_file(yaml_path: Path) -> Dict:
	"""
	Parse clang-tidy YAML output file.

	Args:
		yaml_path: Path to the .yaml file

	Returns:
		Dictionary containing structured diagnostic information
	"""
	with open(yaml_path, 'r', encoding='utf-8') as f:
		data = yaml.safe_load(f)

	return data if data else {}


def generate_html(filename: str, txt_warnings: List[Dict], yaml_data: Dict) -> str:
	"""
	Generate HTML report from parsed data.

	Args:
		filename: Name of the source file being reported
		txt_warnings: List of warnings parsed from .txt file
		yaml_data: Structured data from .yaml file

	Returns:
		Complete HTML document as a string
	"""
	# Extract source file path from YAML
	source_file = yaml_data.get('MainSourceFile', 'Unknown')
	diagnostics = yaml_data.get('Diagnostics', [])

	# Build HTML
	html_parts = []

	# HTML header
	html_parts.append('<!DOCTYPE html>')
	html_parts.append('<html>')
	html_parts.append('<head>')
	html_parts.append(f'<title>{html.escape(filename)} - clang-tidy report</title>')
	html_parts.append('<style>')
	html_parts.append('body { font-family: monospace; margin: 20px; background: #f5f5f5; }')
	html_parts.append('pre { background: white; padding: 15px; border: 1px solid #ddd; overflow: auto; }')
	html_parts.append('.warning { color: #d14; font-weight: bold; }')
	html_parts.append('.note { color: #0086b3; }')
	html_parts.append('.diagnostic { color: #666; font-style: italic; }')
	html_parts.append('a { text-decoration: none; color: #0366d6; }')
	html_parts.append('a:hover { text-decoration: underline; }')
	html_parts.append('h1 { color: #333; }')
	html_parts.append('h3 { color: #666; margin-top: 30px; margin-bottom: 10px; }')
	html_parts.append('.metadata { color: #666; margin: 5px 0; }')
	html_parts.append('</style>')
	html_parts.append('</head>')
	html_parts.append('<body>')

	# Title and navigation
	html_parts.append(f'<h1>{html.escape(filename)} - clang-tidy report</h1>')
	html_parts.append('<p><a href="../index.html">Back to main report</a></p>')
	html_parts.append(f'<p class="metadata">Source file: {html.escape(source_file)}</p>')

	# Generate sections for each warning
	for i, warning in enumerate(txt_warnings):
		# Try to match with YAML diagnostic for additional info
		yaml_diag = diagnostics[i] if i < len(diagnostics) else {}
		level = yaml_diag.get('Level', 'Warning')
		diag_name = warning['diagnostic']

		html_parts.append(f'<h3>Level: {html.escape(level)}</h3>')
		html_parts.append(f'<p class="diagnostic">Diagnostic: {html.escape(diag_name)}</p>')
		html_parts.append(f'<p><span class="warning">{html.escape(warning["message"])}</span></p>')

		# Code snippet with line anchor
		line_num = warning['line']
		code_snippet = warning['code_snippet']
		html_parts.append('<pre>')
		html_parts.append(f'<a name="line{line_num}"></a>{html.escape(code_snippet)}')
		html_parts.append('</pre>')
		html_parts.append('')

	# Close HTML
	html_parts.append('</body>')
	html_parts.append('</html>')

	return '\n'.join(html_parts)


def process_tidy_reports(reports_dir: Path) -> int:
	"""
	Process all clang-tidy report pairs in the directory.

	Args:
		reports_dir: Path to the directory containing .txt and .yaml files

	Returns:
		Number of HTML files generated
	"""
	# Find all .txt files
	txt_files = sorted(reports_dir.glob('*.txt'))

	# Filter out index.txt
	txt_files = [f for f in txt_files if f.name != 'index.txt']

	if not txt_files:
		print(f"No .txt files found in {reports_dir}")
		return 0

	generated_count = 0

	for txt_file in txt_files:
		# Find corresponding .yaml file
		yaml_file = txt_file.with_suffix('.yaml')

		if not yaml_file.exists():
			print(f"Warning: No corresponding .yaml file for {txt_file.name}", file=sys.stderr)
			continue

		# Parse both files
		try:
			txt_warnings = parse_txt_file(txt_file)
			yaml_data = parse_yaml_file(yaml_file)

			# Skip if no warnings
			if not txt_warnings:
				continue

			# Generate HTML
			html_content = generate_html(txt_file.stem, txt_warnings, yaml_data)

			# Write HTML file
			html_file = txt_file.with_suffix('.html')
			with open(html_file, 'w', encoding='utf-8') as f:
				f.write(html_content)

			generated_count += 1
# 			print(f"Generated: {html_file.name}")

		except Exception as e:
			print(f"Error processing {txt_file.name}: {e}", file=sys.stderr)
			continue

	return generated_count


def main():
	"""Main function to generate HTML reports from clang-tidy output."""
	# Check command-line arguments
	if len(sys.argv) != 2:
		print("Usage: python3 make-tidy-html.py tidy-reports-directory", file=sys.stderr)
		sys.exit(1)

	reports_dir = Path(sys.argv[1])

	# Check if reports directory exists
	if not reports_dir.exists():
		print(f"Error: Reports directory does not exist: {reports_dir}", file=sys.stderr)
		sys.exit(1)

	if not reports_dir.is_dir():
		print(f"Error: Path is not a directory: {reports_dir}", file=sys.stderr)
		sys.exit(1)

	# Process all report files
	_ = process_tidy_reports(reports_dir)


if __name__ == '__main__':
	main()
