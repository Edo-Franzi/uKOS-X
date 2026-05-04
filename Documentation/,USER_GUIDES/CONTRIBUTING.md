# Typography

(c) 2025-2026, Laurent von Allmen, 2025-01-01



1. Files shall be encoded in UTF-8 and employ UNIX-style line endings (LF).

2. Lines shall terminate without trailing whitespace.

3. Code indentation shall employ TAB characters, configured to represent 4 spaces.


## File header

Files shall start with a header in comment style of the source.

Exemple for C source file:

```
/*
; uKOS.
; =====

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:    Edo. Franzi			     The 2025-01-01
; Modifs:    Laurent von Allmen    The 2025-01-01
;
; Project:   µKOS-X
; Goal:      Universal h file for µKOS-X systems.
;
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
*/
```

## Rules

### Section 1

This section gives the name of the source file without its extension.

```
/*
; fileName.
; =========

;------------------------------------------------------------------------
```

Line 1 : contains the name of the file

Line 2 : underlying of line 1 with character '='

Line 3 : blank line

Line 4 : separator line (72 '-')

### Section 2

```
; Author:	Edo. Franzi    The 2025-01-01
```

### Section 3

```
; Modifs: Laurent von Allmen    The 2025-01-01
;
```

Can contain several instances of line 'Modifs'.

Last line of section is blank.

### Section 4

```
; Project:   µKOS-X
; Goal:      Universal h file for µKOS-X systems.
;
```

Line 1 of this section is a constant

Goal description can extend to more lines, e.g.

```
; Goal:      kern manager (uKernel core).
;
;            The KERN manager operates on a series of linked lists
;            where the processes are located.
;
;            Service system calls
;            --------------------
;
;            int32_t	kern_init(void);
```

Last line of section is blank.

### Section 5

```
;   (c) 2025-2026, Edo. Franzi
;   --------------------------
```

Author names

### Section 6

Constant section.

```
;                                              __ ______  _____
;   Edo. Franzi                         __  __/ //_/ __ \/ ___/
;   5-Route de Cheseaux                / / / / ,< / / / /\__ \
;   CH 1400 Cheseaux-Noréaz           / /_/ / /| / /_/ /___/ /
;                                     \__,_/_/ |_\____//____/
;   edo.franzi@ukos.ch
;
;   Description: Lightweight, real-time multitasking operating
;   system for embedded microcontroller and DSP-based systems.
;
;   Permission is hereby granted, free of charge, to any person
;   obtaining a copy of this software and associated documentation
;   files (the "Software"), to deal in the Software without restriction,
;   including without limitation the rights to use, copy, modify,
;   merge, publish, distribute, sublicense, and/or sell copies of the
;   Software, and to permit persons to whom the Software is furnished
;   to do so, subject to the following conditions:
;
;   The above copyright notice and this permission notice shall be
;   included in all copies or substantial portions of the Software.
;
;   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;   SOFTWARE.
;
;------------------------------------------------------------------------
```

The last line is a copy of the separator line (72 '-') previously mentioned.
