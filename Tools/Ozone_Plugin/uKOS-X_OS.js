/*
; uKOS-X_OS.
; ==========
;
; SPDX-License-Identifier: MIT
; SPDX-FileCopyrightText: 2025-2026 Edo. Franzi
;
;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2026-10-24
; Modifs:
;
; Project:	uKOS-X
; Goal:		Ozone uKOS RTOS OSA OS plugin.
;
;			Installing the plugin:
;			Project.SetOSPlugin("xyz/OS_Kernel-X/Ports/Tools/Ozone_Plugin/uKOS-X_OS")
;
;			Limitations:
;			This plugin was tested only for cortex M & RV32 cpus.
;			The RVx64 implementation is not tested.
;
;   (c) 2025-2026, Edo. Franzi
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

var		vuKOS				= 0;
var		vuKOSArchitecture	= 0;
var		vCortex				= 0;
var		vRisc_vRV32			= 1;
var		vRisc_vRV64			= 2;
var		vuKOSRegRoutine		= null;
var		vukosMaxProcesses	= 0;
var		vCore				= 0;
var		vIndex				= [];

// Mandatory Ozone routines
// ========================

/*
 * init()
 *
 * Initialises the RTOS plugin and configures the process display.
 *
 */
function init() {
	var		arch;

	vuKOSArchitecture = Debug.evaluate("uKOS_ARCHITECTURE");

	arch = Number(vuKOSArchitecture);

	switch (arch) {
		default:
		case vCortex: {
			vuKOSRegRoutine = local_ukosRegsCortex;
			break;
		}
		case vRisc_vRV32: {
			vuKOSRegRoutine = local_ukosRegsRV32;
			break;
		}
		case vRisc_vRV64: {
			vuKOSRegRoutine = local_ukosRegsRV64;
			break;
		}
	}

	vukosMaxProcesses = Number(Debug.evaluate("KKERN_NB_PROCESSES"));
	vIndex = [];

	Threads.newqueue("Tasks");
	Threads.setColumns("Process", "Id", "Dynamic Priority", "Status", "Reason", "Timeout [ms]", "Nb Executions", "Stack", "Privilege");
	Threads.setSortByNumber("Id");
	Threads.setColor("Status", "Available", "Executing", "Waiting");
}

/*
 * update()
 *
 * Updates the process list.
 *
 */
function update() {
	var		KPROC_PRIVILEGED = 1;
	var		BPROC_INSTALLED = 1;
	var		i;
	var		state;
	var		ptr;
	var		current;
	var		identifier;
	var		dynaPriority;
	var		timeout;
	var		nbExecutions;
	var		stack;
	var		mode;
	var		flags;
	var		active;
	var		handle;

	Threads.clear();
	Threads.newqueue("Tasks");

	vIndex = [];

	if (vukosMaxProcesses <= 0 || vukosMaxProcesses > 100000) {
		return;
	}

	current = Debug.evaluate("vKern_runProc[" + vCore + "]");
	for (i = 0; i < vukosMaxProcesses; i++) {
		state = Debug.evaluate(local_ukosExpr(i, "oInternal.oState"));

// Ignore processes that are not installed.

		if (state == undefined || (Number(state) & (1<<BPROC_INSTALLED)) == 0) {
			continue;
		}

		ptr = Debug.evaluate("&vKern_proc[" + vCore + "][" + i + "]");
		if (ptr == undefined) {
			continue;
		}

		identifier	 = Debug.evaluate(local_ukosExpr(i, "oSpecification.oIdentifier"));
		dynaPriority = Debug.evaluate(local_ukosExpr(i, "oInternal.oDynamicPriority"));
		timeout		 = Debug.evaluate(local_ukosExpr(i, "oInternal.oTimeout"));
		nbExecutions = Debug.evaluate(local_ukosExpr(i, "oStatistic.oNbExecutions"));
		stack		 = Debug.evaluate(local_ukosExpr(i, "oSpecification.oStack"));
		mode		 = Debug.evaluate(local_ukosExpr(i, "oSpecification.oMode"));

		active = (current != undefined && Number(ptr) == Number(current));
		flags  = local_ukosState(Number(state), active);
		handle = active ? (undefined) : (Number(ptr));
		vIndex[String(ptr)] = i;

		Threads.add(
			String(identifier),
			String(i),
			String(dynaPriority),
			flags[0],
			flags[1],
			local_ukosTimeout(timeout),
			String(nbExecutions),
			local_ukosHex(stack),
			Number(mode) == KPROC_PRIVILEGED ? ("Privileged") : ("User"),
			handle
		);
	}
}

/*
 * getregs()
 *
 * Returns the saved register context of a suspended process.
 *
 */
function getregs(handle) {
	var		i;
	var		stack;

	if (handle == undefined) {
		return (null);
	}

	i = local_ukosFindProcess(handle);
	if (i < 0) {
		return (null);
	}

	stack = Debug.evaluate(local_ukosExpr(i, "oSpecification.oStack"));
	if (stack == undefined || Number(stack) == 0) {
		return (null);
	}

	return (vuKOSRegRoutine(stack));
}

/*
 * getname()
 *
 * Returns the process name.
 *
 */
function getname(handle) {
	var		i;

	i = local_ukosFindProcess(handle);

	if (i < 0) {
		return ("uKOS-X");
	}

	return (String(Debug.evaluate(local_ukosExpr(i, "oSpecification.oIdentifier"))));
}

/*
 * getOSName()
 *
 * Returns the OS name.
 *
 */
function getOSName() {

	return ("uKOS-X");
}

// Local routines
// ==============

/*
 * local_ukosExpr()
 *
 * Builds an expression referring to a process field.
 *
 */
function local_ukosExpr(i, field) {

	return ("vKern_proc[" + vCore + "][" + i + "]." + field);
}

/*
 * local_ukosState()
 *
 * Returns the process status and suspension reason.
 *
 */
function local_ukosState(state, active) {
	var		BPROC_SUSP_TIME		= 3;
	var		BPROC_SUSP_SIGN		= 4;
	var		BPROC_SUSP_SEMA		= 5;
	var		BPROC_SUSP_MUTX		= 6;
	var		BPROC_SUSP_MBOX_E	= 7;
	var		BPROC_SUSP_MBOX_F	= 8;
	var		BPROC_SUSP_DEBG		= 9;
	var		status;
	var		stateText;

	status	  = active ? ("Executing") : ("Available");
	stateText = active ? ("Running")   : ("Scheduled");

	if ((state & (1<<BPROC_SUSP_TIME))   != 0) { status = "Waiting"; stateText = "Susp. for a Time";		}
	if ((state & (1<<BPROC_SUSP_SIGN))   != 0) { status = "Waiting"; stateText = "Susp. for a Signal";		}
	if ((state & (1<<BPROC_SUSP_SEMA))   != 0) { status = "Waiting"; stateText = "Susp. for a Semaphore";	}
	if ((state & (1<<BPROC_SUSP_MUTX))   != 0) { status = "Waiting"; stateText = "Susp. for a Mutex";		}
	if ((state & (1<<BPROC_SUSP_MBOX_E)) != 0) { status = "Waiting"; stateText = "Susp. for a Mbox empty";	}
	if ((state & (1<<BPROC_SUSP_MBOX_F)) != 0) { status = "Waiting"; stateText = "Susp. for a Mbox full";	}
	if ((state & (1<<BPROC_SUSP_DEBG))   != 0) { status = "Waiting"; stateText = "Susp. for a Debug";		}

	return ([status, stateText]);
}

/*
 * local_ukosHex()
 *
 * Converts a value to a hexadecimal string.
 *
 */
function local_ukosHex(value) {

	if (value == undefined) {
		return ("?");
	}

	return ("0x" + Number(value).toString(16).toUpperCase());
}

/*
 * local_ukosTimeout()
 *
 * Converts a timeout value to a readable string.
 *
 */
function local_ukosTimeout(value) {
	var		KWAIT_INFINITY			= 0xFFFFFFFF;
	var		KWAIT_REMAINING_TIMEOUT	= 0xFFFFFFFE;

	if (Number(value) == KWAIT_INFINITY) {
		return ("Infinity");
	}

	if (Number(value) == KWAIT_REMAINING_TIMEOUT) {
		return ("Remaining");
	}

	return (String(value));
}

/*
 * local_ukosFindProcess()
 *
 * Returns the index of a process from its handle.
 *
 */
function local_ukosFindProcess(handle) {
	var		i;
	var		ptr;

	i = vIndex[String(handle)];

	if (i != undefined) {
		return (i);
	}

	for (i = 0; i < vukosMaxProcesses; i++) {
		ptr = Debug.evaluate("&vKern_proc[" + vCore + "][" + i + "]");

		if (ptr != undefined && Number(ptr) == Number(handle)) {
			return (i);
		}
	}
	return (-1);
}

/*
 * local_ukosRegsCortex()
 *
 * Reconstructs the register context of a suspended Cortex-M process.
 *
 * uKOS-X saved context;
 *
 *  No FPU (Basic frame)						With FPU (Extended FPU frame)
 *
 *	+0x50  SP used for Ozone stack unwinding	+0xD8  SP used for Ozone stack unwinding
 *	+0x48  Hardware-restored SP					+0xD0  Hardware-restored SP
 *												+0xCC  Reserved
 *												+0xC8  FPSCR
 *												+0x88  S15..S00
 *	+0x44  xPSR									+0x84  xPSR
 *	+0x40  PC									+0x80  PC									
 *	+0x3C  LR									+0x7C  LR
 *	+0x38  R12									+0x78  R12
 *	+0x28  R3..R0								+0x68  R3..R0						
 *	+0x08  R11..R4								+0x48  R11..R4
 * 	+0x04  BASEPRI								+0x44  BASEPRI
 *												+0x04  S31..S16
 * 	+0x00  EXC_RETURN							+0x00  EXC_RETURN
 *
 * The additional 8 bytes correspond to the two words pushed
 * by GOTO_KERN before SVC.
 *
 */
function local_ukosRegsCortex(stack) {
	var		addr;
	var		excReturn;
	var		offset;
	var		sp;

	addr = Number(stack);

// EXC_RETURN bit 4: 1 = Basic frame, 0 = Extended FPU frame

	excReturn = TargetInterface.peekWord(addr);
	offset	  = ((excReturn & 0x10) == 0) ? (0x40) : (0x00);

// Hardware frame size: 0x20 (basic), 0x68 (extended)
// Add 8 bytes pushed by GOTO_KERN before SVC

	sp = addr + (((excReturn & 0x10) == 0) ? (0xD8) : (0x50));

	return [
		TargetInterface.peekWord(addr + offset + 0x28),		// R0
		TargetInterface.peekWord(addr + offset + 0x2C),		// R1
		TargetInterface.peekWord(addr + offset + 0x30),		// R2
		TargetInterface.peekWord(addr + offset + 0x34),		// R3

		TargetInterface.peekWord(addr + offset + 0x08),		// R4
		TargetInterface.peekWord(addr + offset + 0x0C),		// R5
		TargetInterface.peekWord(addr + offset + 0x10),		// R6
		TargetInterface.peekWord(addr + offset + 0x14),		// R7
		TargetInterface.peekWord(addr + offset + 0x18),		// R8
		TargetInterface.peekWord(addr + offset + 0x1C),		// R9
		TargetInterface.peekWord(addr + offset + 0x20),		// R10
		TargetInterface.peekWord(addr + offset + 0x24),		// R11

		TargetInterface.peekWord(addr + offset + 0x38),		// R12
		sp,													// R13 (SP)
		TargetInterface.peekWord(addr + offset + 0x3C),		// R14 (LR)
		TargetInterface.peekWord(addr + offset + 0x40),		// R15 (PC)
		TargetInterface.peekWord(addr + offset + 0x44)		// xPSR
	];
}

/*
 * local_ukosRegsRV32()
 *
 * Reconstructs the register context of a suspended
 * uKOS-X RISC-V RV32 process.
 *
 * Saved frame:
 *
 *  +0x94  Original SP (before GOTO_KERN)
 *  +0x8C  SP at exception return (before GOTO_KERN cleanup)
 *  +0x88  RA
 *  +0x7C  T2..T0
 *  +0x78  S0
 *  +0x58  A7..A0
 *  +0x48  T6..T3
 *  +0x40  GP
 *  +0x3C  TP
 *  +0x10  S11..S1
 *  +0x08  MSTATUS
 *  +0x04  MCAUSE
 *  +0x00  MEPC
 *
 * Returns x0..x31, PC.
 *
 */
function local_ukosRegsRV32(stack) {
	var		addr;
	var		sp;

	addr = Number(stack);
	sp	 = addr + 0x90;

	var r = [
		0,													// x0  zero
		TargetInterface.peekWord(addr + 0x88),				// x1  ra
		sp,													// x2  sp
		TargetInterface.peekWord(addr + 0x40),				// x3  gp
		TargetInterface.peekWord(addr + 0x3C),				// x4  tp
		TargetInterface.peekWord(addr + 0x84),				// x5  t0
		TargetInterface.peekWord(addr + 0x80),				// x6  t1
		TargetInterface.peekWord(addr + 0x7C),				// x7  t2
		TargetInterface.peekWord(addr + 0x78),				// x8  s0 / fp
		TargetInterface.peekWord(addr + 0x38),				// x9  s1
		TargetInterface.peekWord(addr + 0x74),				// x10 a0
		TargetInterface.peekWord(addr + 0x70),				// x11 a1
		TargetInterface.peekWord(addr + 0x6C),				// x12 a2
		TargetInterface.peekWord(addr + 0x68),				// x13 a3
		TargetInterface.peekWord(addr + 0x64),				// x14 a4
		TargetInterface.peekWord(addr + 0x60),				// x15 a5
		TargetInterface.peekWord(addr + 0x5C),				// x16 a6
		TargetInterface.peekWord(addr + 0x58),				// x17 a7
		TargetInterface.peekWord(addr + 0x34),				// x18 s2
		TargetInterface.peekWord(addr + 0x30),				// x19 s3
		TargetInterface.peekWord(addr + 0x2C),				// x20 s4
		TargetInterface.peekWord(addr + 0x28),				// x21 s5
		TargetInterface.peekWord(addr + 0x24),				// x22 s6
		TargetInterface.peekWord(addr + 0x20),				// x23 s7
		TargetInterface.peekWord(addr + 0x1C),				// x24 s8
		TargetInterface.peekWord(addr + 0x18),				// x25 s9
		TargetInterface.peekWord(addr + 0x14),				// x26 s10
		TargetInterface.peekWord(addr + 0x10),				// x27 s11
		TargetInterface.peekWord(addr + 0x54),				// x28 t3
		TargetInterface.peekWord(addr + 0x50),				// x29 t4
		TargetInterface.peekWord(addr + 0x4C),				// x30 t5
		TargetInterface.peekWord(addr + 0x48),				// x31 t6
		TargetInterface.peekWord(addr + 0x00)				// PC (mepc)
	];

	return (r);
}

/*
 * local_ukosRegsRV64()
 *
 * Reconstructs the register context of a suspended
 * uKOS-X RISC-V RV64 process.
 *
 * Complete saved context: 560 bytes (0x230).
 *
 * SP at exception return = stack + 560.
 * SP before GOTO_KERN  = stack + 568.
 *
 * The additional 8 bytes pushed by GOTO_KERN
 * remain above the saved frame.
 *
 * Returns x0..x31, PC.
 *
 */
function local_ukosRegsRV64(stack) {
	var		addr;
	var		sp;
 	var		r = [];
 
	addr = Number(stack);
	sp	 = addr + 560;

// Read a 64-bit little-endian register.
// Note: JavaScript Number has 53 bits of integer precision.

	function read64(offset) {
		var		lsw;
		var		msw;

		lsw = TargetInterface.peekWord(addr + offset)>>>0;
		msw = TargetInterface.peekWord(addr + offset + 4)>>>0;
		return ((msw * 0x100000000) + lsw);
    }

	r = [
		0,													// x0  zero
		read64(552),										// x1  ra
		sp,													// x2  sp
		read64(144),										// x3  gp
		read64(152),										// x4  tp
		read64(544),										// x5  t0
		read64(528),										// x6  t1
		read64(520),										// x7  t2
		read64(512),										// x8  s0 / fp
		read64(504),										// x9  s1
		read64(496),										// x10 a0
		read64(488),										// x11 a1
		read64(480),										// x12 a2
		read64(472),										// x13 a3
		read64(464),										// x14 a4
		read64(456),										// x15 a5
		read64(448),										// x16 a6
		read64(440),										// x17 a7
		read64(160),										// x18 s2
		read64(168),										// x19 s3
		read64(176),										// x20 s4
		read64(184),										// x21 s5
		read64(192),										// x22 s6
		read64(200),										// x23 s7
		read64(208),										// x24 s8
		read64(216),										// x25 s9
		read64(224),										// x26 s10
		read64(232),										// x27 s11
		read64(432),										// x28 t3
		read64(424),										// x29 t4
		read64(416),										// x30 t5
		read64(408),										// x31 t6
		read64(32)											// PC = mepc
	];

	return (r);
}