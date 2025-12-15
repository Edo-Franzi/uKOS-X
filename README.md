# µKOS-X

(c) 2025-20xx, Edo. Franzi, [http://www.ukos.ch](http://www.ukos.ch/)

## Introduction

µKOS-X is a multitasking operating system designed specifically for **embedded microcontroller- and DSP-based** systems. Its development traces back to 1984, with the creation of **µKOS-0**. At that time, I developed a simple scheduler without any additional services, constrained by the extremely limited memory available. This early system ran on a Motorola MC6809 processor operating at 1 MHz.
The project gained momentum in 1992 during the development of the [Khepera](https://en.wikipedia.org/wiki/Khepera_mobile_robot) mobile robot, an influential academic robotics platform. During this phase, I created **µKOS-I**, written in **CALM assembler**, a language developed by **LAMI-EPFL**. That experience raised a critical question that would shape the future of µKOS: “How should one write software to control such a compact, resource-limited robot?”
This challenge laid the conceptual foundation for what would later become the **µKOS family**.
In 1996, I undertook a complete rewrite of µKOS-I in the C programming language, resulting in **µKOS-II**. Development was carried out on a Macintosh running Mac OS 9, using the MPW (Macintosh Programmer’s Workshop) environment, which offered a robust platform for embedded development at the time.
In 2002, following Apple’s transition to Mac OS X and the broader UNIX ecosystem, I chose to revive, modernise, and extend the µKOS project. This effort culminated in the creation of **µKOS-X**, a fully updated, feature-rich version of the operating system. My goal was to consolidate the ideas, insights, and experience accumulated over nearly three decades of embedded system design, and to make them available to others working in the same domain.
I consider this project to be open source, licensed under the MIT license.
The **µKOS** project is described and distributed with full support for a wide range of **ARM Cortex** microcontrollers — covering both single-core and multi-core architectures — including the M3, M4, M7, M33, and M55 families, as well as for **RISC-V** architectures, specifically RV32 and RV64.

## The proposed package

The proposed package includes all the OS sources, along with the necessary documentation and build instructions for generating both the required tools and the operating system itself for all supported targets. The supported compilers are **GCC** and **LLVM**. Both build systems, **Make** and **CMake**, are supported as well.

Additionally, the package provides configuration files, example setups, and guidelines to help developers quickly adapt the build process to different environments and platforms. This ensures flexibility, ease of integration, and reproducibility across various development workflows.



###### First step, consult the documentation

- [uKOS-X book](http://www.ukos.ch/doc/uKOS-X_RTOS.pdf)
- ./Documentation/USER_GUIDES/*.md



###### The µKOS-X Team, September 2025

- Edo. Franzi
- Laurent von Allmen
- Antonio José Restrepo Zea
