#!/usr/bin/env python
# -*- coding: utf-8 -*-

# concat_proto.
# =============

# SPDX-License-Identifier: MIT
# SPDX-FileCopyrightText: 2025-2026 Jean-Marc Koller

#------------------------------------------------------------------------
# Author:	Jean-Marc Koller	The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Create a flat file uKOS.h without comments
#			for a specific target
#
#			Usage:
#			1. cd .../System of the selected uKOS system
#			2. Buid the system (without erasing the intermediate results)
#			   make -j NOCLEAN=1
#			3. concat_proto.py > uKOS.h
#			4. Copy at least these files in a specific folder
#			   uKOS.h
#			   first.o
#			   librtcb.a
#			   libprot.a
#			   libproc.a
#			   liblibx.a
#			   libkern.a
#			   libTinyUSB.a
#
#   (c) 2025-2026, Jean-Marc Koller
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

flist = []

def getFile(n) :
	global flist
	return [m for m in flist if n in m]

with open('kern.d', 'r') as fi :
	while True :
		l = fi.readline()
		if l == '' :
			break
		l = l.strip().strip(' \\')
		if l[-2:] == '.h' :
			flist.append(l)

def processInclude(n) :
	#if n == 'conf_kernel.h' or n == 'conf_system.h' or n == 'board.h' :
	#	return None
	fn = getFile('/'+n)
	if fn == [] :
		return None
	#print("//  Including ",fn[0])
	output = ''
	with open(fn[0], 'r') as fi :
		while True :
			l = fi.readline()
			if l == '' :
				return output
			if l[:len('#include')] == '#include' :
				ls = l.split()
				li = ls[1][1:-1]
				includeRes = processInclude(li)
				if includeRes != None :
					output += includeRes
					continue
			output += l

output = processInclude('uKOS.h')

# C comment remover
# from https://stackoverflow.com/questions/241327/remove-c-and-c-comments-using-python
import re
def removeCCppComment( text ) :
	def blotOutNonNewlines( strIn ) :  # Return a string containing only the newline chars contained in strIn
		return "" + ("\n" * strIn.count('\n'))
	def replacer( match ) :
		s = match.group(0)
		if s.startswith('/'):  # Matched string is //...EOL or /*...*/  ==> Blot out all non-newline chars
			return blotOutNonNewlines(s)
		else:                  # Matched string is '...' or "..."  ==> Keep unchanged
			return s
	pattern = re.compile(
		r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
		re.DOTALL | re.MULTILINE
	)
	return re.sub(pattern, replacer, text)

output_noComment = removeCCppComment(output)

output_noComment_cleaned = ''
for l in output_noComment.split("\n") :
	if l != '' :
		output_noComment_cleaned += l.strip()+"\n"

print(output_noComment_cleaned)
