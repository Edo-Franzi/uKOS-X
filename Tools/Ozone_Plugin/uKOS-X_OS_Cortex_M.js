/*
; uKOS-X.
; =======
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
;			Project.SetOSPlugin("xyz/OS_Kernel-X/Ports/Tools/Ozone_Plugin/uKOS-X")
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

		active = (Number(ptr) == Number(current));
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
		return ([]);
	}

	i = local_ukosFindProcess(handle);
	if (i < 0) {
		return ([]);
	}

	stack = Debug.evaluate(local_ukosExpr(i, "oSpecification.oStack"));
	if (stack == undefined || Number(stack) == 0) {
		return ([]);
	}

	return (local_ukosCortexRegs(stack));
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

		if (Number(ptr) == Number(handle)) {
			return (i);
		}
	}
	return (-1);
}

/*
 * local_ukosCortexRegs()
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
function local_ukosCortexRegs(stack) {
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
