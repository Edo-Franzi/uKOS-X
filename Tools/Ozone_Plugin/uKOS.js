/*
; uKOS-X.
; =======

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		Ozone uKOS plugin.
;			Installing the plugin:
;
;			Project.SetSmartViewPlugin("xyz/OS_Kernel-X/Ports/Tools/Ozone_Plugin/uKOS-X")
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

var		vuKOS				  = 0;
var		vuKOSMajor			  = 0;
var		vuKOSMinor			  = 0;
var		vuKOSPatch			  = 0;

var		vuKOSArchitecture	  = 0;
var		vCortex				  = 0;
var		vRisc_vRV32			  = 1;
var		vRisc_vRV64			  = 2;
var		vNbCores			  = 1;
var		vSzFrame			  = 0;
var		vInterface			  = [];
var		vArchString			  = "";
var		vuKOSString			  = ""
var		vuKOSMajorString	  = ""
var		vuKOSMinorString	  = ""
var		vuKOSPatchString	  = ""
var		vPadding			  = 0;

var		vLastPrimaryUsedRow	  = 0;
var		vLastAuxiliaryUsedRow = 0;
var		vCurrentRowOnPage	  = [];

// Mandatory Ozone routines
// ========================

/*
 * init()
 *
 *  Functions description:
 *    This function... Not yet sure what it does...
 */
function init() {
	var		arch;

	vuKOSArchitecture = Debug.evaluate("uKOS_ARCHITECTURE");
	vuKOS		  	  = Debug.evaluate("uKOS_VERSION_OS");	  vuKOSString	   = vuKOS.toString();
	vuKOSMajor	  	  = Debug.evaluate("uKOS_VERSION_MAJOR"); vuKOSMajorString = vuKOSMajor.toString();
	vuKOSMinor	  	  = Debug.evaluate("uKOS_VERSION_MINOR"); vuKOSMinorString = vuKOSMinor.toString();
	vuKOSPatch		  = Debug.evaluate("uKOS_VERSION_PATCH"); vuKOSPatchString = vuKOSPatch.toString();

	arch = Number(vuKOSArchitecture);

	switch (arch) {
		default:
		case vCortex: {
			vSzFrame = 10;
			vPadding = 8;
			vInterface = ["Process", "Id", "Privilege", "Prov. Privilege", "Nested Privilege", "State", "Timeout [ms]", "Nb Executions", "Dynamic Priority", "stack", "sp[0]", "sp[1]", "sp[2]", "sp[3]", "sp[4]", "sp[5]", "sp[6]", "sp[7]", "sp[8]", "sp[9]"];
			vArchString = "ARM - cortex M";
			vPadding = 8;
			break;
		}
		case vRisc_vRV32: {
			vSzFrame = 10;
			vPadding = 8;
			vInterface = ["Process", "Id", "Privilege", "Prov. Privilege", "Nested Privilege", "State", "Timeout [ms]", "Nb Executions", "Dynamic Priority", "stack", "sp[0]", "sp[1]", "sp[2]", "sp[3]", "sp[4]", "sp[5]", "sp[6]", "sp[7]", "sp[8]", "sp[9]"];
			vArchString = "RISC-V RV32";
			vPadding = 8;
			break;
		}
		case vRisc_vRV64: {
			vSzFrame = 10;
			vPadding = 16;
			vInterface = ["Process", "Id", "Privilege", "Prov. Privilege", "Nested Privilege", "State", "Timeout [ms]", "Nb Executions", "Dynamic Priority", "stack", "sp[0]", "sp[1]", "sp[2]", "sp[3]", "sp[4]", "sp[5]", "sp[6]", "sp[7]", "sp[8]", "sp[9]"];
			vArchString = "RISC-V RV32";
			vPadding = 8;
			break;
		}
	}

	vCurrentRowOnPage["Process"]		= 0;
	vCurrentRowOnPage["Mailbox"]		= 0;
	vCurrentRowOnPage["Semaphore"]		= 0;
	vCurrentRowOnPage["Mutex"]			= 0;
	vCurrentRowOnPage["Signal"]			= 0;
	vCurrentRowOnPage["Precise signal"] = 0;
	vCurrentRowOnPage["Software timer"]	= 0;
	vCurrentRowOnPage["Pool"]			= 0;
	vCurrentRowOnPage["Trace"]			= 0;
	vCurrentRowOnPage["Log"]			= 0;
	vCurrentRowOnPage["Memory"]			= 0;
	vCurrentRowOnPage["About ..."]		= 0;
}

/*
 * getName()
 *
 *  Functions description:
 *    Returns the name of the middleware this script supplies support
 *    for.
 */
function getName() {

	return ("uKOS-X");
}

/*
 * getPages()
 *
 *  Functions description:
 *    Returns the names of the pages this script is capable to display.
 */
function getPages() {

	init();
	return (["Process", "Mailbox", "Semaphore", "Mutex", "Signal", "Precise signal", "Software timer", "Pool", "Trace", "Log", "Memory", "About ..."]);
}

/*
 * getColHeaders()
 *
 *  Functions description:
 *    Returns the names of the colums for a given page.
 */
function getColHeaders(pageName) {
	var		result;

	result = uKOS_getColHeaders(pageName);
	return (result);
}

/*
 * getFirstRow()
 *
 *  Functions description:
 *    Returns the values of the 1st row for a given page.
 */
function getFirstRow(pageName) {
	var		result;

	vLastPrimaryUsedRow   = 0;
	vLastAuxiliaryUsedRow = 0;
	if (typeof vCurrentRowOnPage[pageName] != "undefined") {
		vCurrentRowOnPage[pageName] = 0;
		result = local_getCurrentRow(pageName);
	}
	else {
		result = null;
	}
	return (result);
}

/*
 * getNextRow()
 *
 *  Functions description:
 *    Returns the values of the next row for a given page.
 */
function getNextRow(pageName) {
	var		result;

	if (typeof vCurrentRowOnPage[pageName] != "undefined") {
		vCurrentRowOnPage[pageName] += 1;
		result = local_getCurrentRow(pageName);
	}
	else {
		result = null;
	}
	return (result);
}

/*
 * onTargetChanged()
 *
 *  Functions description:
 *    Handles the event of target state having changed.
 */
function onTargetChanged() {

}

// Local routines
// ==============

/*
 * local_getCurrentRow()
 *
 *  Functions description:
 *    Returns the values of the currently selected row for a given page.
 */
function local_getCurrentRow(pageName) {
	var		result;

	switch (pageName) {
		case "Process":			{ result = uKOS_getProcessRow(vCurrentRowOnPage[pageName]);			break; }
		case "Mailbox":			{ result = uKOS_getMailboxRow(vCurrentRowOnPage[pageName]);			break; }
		case "Semaphore":		{ result = uKOS_getSemaphoreRow(vCurrentRowOnPage[pageName]);		break; }
		case "Mutex":			{ result = uKOS_getMutexRow(vCurrentRowOnPage[pageName]);			break; }
		case "Signal":			{ result = uKOS_getSignalRow(vCurrentRowOnPage[pageName]);			break; }
		case "Precise signal":	{ result = uKOS_getPreciseSignalRow(vCurrentRowOnPage[pageName]);	break; }
		case "Software timer":	{ result = uKOS_getSoftwareTimerRow(vCurrentRowOnPage[pageName]);	break; }
		case "Pool":			{ result = uKOS_getPoolRow(vCurrentRowOnPage[pageName]);			break; }
		case "Trace":			{ result = uKOS_getTraceRow(vCurrentRowOnPage[pageName]);			break; }
		case "Log":				{ result = uKOS_getLogRow(vCurrentRowOnPage[pageName]);				break; }
		case "Memory":			{ result = uKOS_getMemoryRow(vCurrentRowOnPage[pageName]);			break; }
		case "About ...":		{ result = uKOS_getAboutRow(vCurrentRowOnPage[pageName]);			break; }
		default:				{ result = null;													break; }
	}
	return (result);
}

/*
 * local_padLeftString()
 *
 *  Functions description:
 *    Returns a string padded with "0"
 */
function local_padLeftString(string, width) {
	var		tmp;

	if (string.length >= width) {
		return (string);
	}

	width -= string.length;
	tmp = "";
	for (var i = 0; i < width; i++) {
		tmp += "0";
	}
	return (tmp + string);
}

// Specific uKOS-X routines
// ========================

/*
 * uKOS_getColHeaders()
 *
 *  Functions description:
 *    Returns the names of the colums for a given page.
 */
function uKOS_getColHeaders(pageName) {
	var		result;

	switch (pageName) {
		case "Process":			{ result = uKOS_getProcessHeader();			break; }
		case "Mailbox":			{ result = uKOS_getMailboxHeader();			break; }
		case "Semaphore":		{ result = uKOS_getSemaphoreHeader();		break; }
		case "Mutex":			{ result = uKOS_getMutexHeader();			break; }
		case "Signal":			{ result = uKOS_getSignalHeader();			break; }
		case "Precise signal":	{ result = uKOS_getPreciseSignalHeader();	break; }
		case "Software timer":	{ result = uKOS_getSoftwareTimerHeader();	break; }
		case "Pool":			{ result = uKOS_getPoolHeader();			break; }
		case "Trace":			{ result = uKOS_getTraceHeader();			break; }
		case "Log":				{ result = uKOS_getLogHeader();				break; }
		case "Memory":			{ result = uKOS_getMemoryHeader();			break; }
		case "About ...":		{ result = uKOS_getAboutHeader();			break; }
		default:				{ result = null;							break; }
	}
	return (result);
}

// Process management
// ------------------

/*
 * uKOS_getProcessHeader()
 *
 *  Functions description:
 *    Delivers the column headers of the respective page.
 */
function uKOS_getProcessHeader() {

	return (vInterface);
}

function uKOS_getProcessRow(rowIndex) {
	var		BPROC_FIRST				= 0;
	var		BPROC_INSTALLED			= 1;
	var		BPROC_RUNNING			= 2;
	var		BPROC_SUSP_TIME			= 3;
	var		BPROC_SUSP_SIGN			= 4;
	var		BPROC_SUSP_SEMA			= 5;
	var		BPROC_SUSP_MUTX			= 6;
	var		BPROC_SUSP_MBOX_E		= 7;
	var		BPROC_SUSP_MBOX_F		= 8;
	var		BPROC_SUSP_DEBG			= 9;
	var		BPROC_LIKE_ISR			= 10;
	var		BPROC_PRIV_ELEVATED		= 11;
	var		KPROC_USER				= 0;
	var		KPROC_PRIVILEGED		= 1;
	var		KWAIT_INFINITY			= 0xFFFFFFFF;
	var		KWAIT_REMAINING_TIMEOUT	= 0xFFFFFFFE;
	var		result					= [];
	var		nbProcess;
	var		process;
	var		currentProcess;
	var		identifier;
	var		nbExecutions;
	var		mode;
	var		elevation;
	var		nested;
	var		state;
	var		status;
	var		stateText;
	var		timeout;
	var		dynaPriority;
	var		stackPtr;
	var		stack;
	var		size;
	var		expr;
	var		value;
	var		arch;
	var		core;
	var		i;
	var		j;

	core = vNbCores - 1;
	arch = Number(vuKOSArchitecture);
	nbProcess = Debug.evaluate("KKERN_NB_PROCESSES");
	for (i = vLastPrimaryUsedRow; i < nbProcess; i++) {
		vLastPrimaryUsedRow++;
		state = Debug.evaluate("vKern_proc["+ core +"]["+ i +"].oInternal.oState");
		if ((state & (1<<BPROC_INSTALLED)) != 0) {
			process		   = Debug.evaluate("vKern_current["+ core +"]");
			currentProcess = Debug.evaluate("&vKern_proc["+ core +"]["+ i +"]");
			identifier	   = Debug.evaluate("vKern_proc["+ core +"]["+ i +"].oSpecification.oIdentifier").toString();
			stackPtr	   = Debug.evaluate("vKern_proc["+ core +"]["+ i +"].oSpecification.oStack");
			mode		   = Debug.evaluate("vKern_proc["+ core +"]["+ i +"].oSpecification.oMode");
			nbExecutions   = Debug.evaluate("vKern_proc["+ core +"]["+ i +"].oStatistic.oNbExecutions");
			nested		   = Debug.evaluate("vKern_proc["+ core +"]["+ i +"].oInternal.oNestedPrivilege");
			dynaPriority   = Debug.evaluate("vKern_proc["+ core +"]["+ i +"].oInternal.oDynamicPriority");
			timeout		   = Debug.evaluate("vKern_proc["+ core +"]["+ i +"].oInternal.oTimeout");

			stateText  = (process == currentProcess) ? ("Running")  : ("Scheduled");
			status	   = (process == currentProcess) ? ("Running")  : ("Scheduled");

			if ((state & (1<<BPROC_SUSP_TIME))   != 0) { status = "Waiting"; stateText = "Susp. for a Time";	   }
			if ((state & (1<<BPROC_SUSP_SIGN))   != 0) { status = "Waiting"; stateText = "Susp. for a Signal";	   }
			if ((state & (1<<BPROC_SUSP_SEMA))   != 0) { status = "Waiting"; stateText = "Susp. for a Semaphore";  }
			if ((state & (1<<BPROC_SUSP_MUTX))   != 0) { status = "Waiting"; stateText = "Susp. for a Mutex";	   }
			if ((state & (1<<BPROC_SUSP_MBOX_E)) != 0) { status = "Waiting"; stateText = "Susp. for a Mbox empty"; }
			if ((state & (1<<BPROC_SUSP_MBOX_F)) != 0) { status = "Waiting"; stateText = "Susp. for a Mbox full";  }
			if ((state & (1<<BPROC_SUSP_DEBG))   != 0) { status = "Blocked"; stateText = "Susp. for a Debug";	   }

			timeout   = (timeout == KWAIT_INFINITY)				  ? ("Infinity")   : (timeout);
			timeout   = (timeout == KWAIT_REMAINING_TIMEOUT)	  ? ("Remaining")  : (timeout);
			mode	  = (mode	 == KPROC_PRIVILEGED)        	  ? ("Privileged") : ("User");
			elevation = ((state & (1<<BPROC_PRIV_ELEVATED)) != 0) ? ("Elevated")   : ("-");

			result.push(identifier);
			result.push(i.toString(10));
			result.push(mode);
			result.push(elevation);
			result.push(nested);
			result.push(stateText);
			result.push(timeout.toString(10));
			result.push(nbExecutions.toString(10));
			result.push(dynaPriority.toString(10));
			result.push("0x" + local_padLeftString(stackPtr.toString(16).toUpperCase(), vPadding));

			size = (arch == 2) ? (8) : (4);

			for (j = 0; j < vSzFrame; j++) {
				value = TargetInterface.peekWord(stackPtr + (j * size));
				result.push("0x" + local_padLeftString(value.toString(16).toUpperCase(), vPadding));
			}
			return (result);
		}
	}
	return (null);
}

// Mailbox management
// ------------------

/*
 * uKOS_getMailboxHeader()
 *
 *  Functions description:
 *    Delivers the column headers of the respective page.
 */
function uKOS_getMailboxHeader() {
	var		result;

	result = ["Mailbox", "Id", "State", "Max packs", "Used packs", "Entry data size"];
	return (result);
}

/*
 * uKOS_getMailboxRow()
 *
 *  Functions description:
 *    Returns a row for the respective page.
 */
function uKOS_getMailboxRow(rowIndex) {
	var		BMBOX_INSTALLED	 = 0;
	var		BMBOX_CONFIGURED = 1;
	var		BMBOX_EMPTY		 = 2;
	var		BMBOX_FULL		 = 3;
	var		BMBOX_BY_COPY	 = 4;
	var		result			 = [];
	var		nbMailbox;
	var		identifier;
	var		state;
	var		stateText;
	var		nbMaxPacks;
	var		nNbUsdPacks;
	var		dataEntrySize;
	var		core;
	var		i;

	core	  = vNbCores - 1;
	nbMailbox = Debug.evaluate("KKERN_NB_MAILBOXES");
	for (i = vLastPrimaryUsedRow; i < nbMailbox; i++) {
		vLastPrimaryUsedRow++;
		state = Debug.evaluate("vKern_mbox["+ core +"]["+ i +"].oState");
		if ((state & (1<<BMBOX_INSTALLED)) != 0) {
			identifier	  = Debug.evaluate("vKern_mbox["+ core +"]["+ i +"].oIdentifier").toString();
			nbMaxPacks	  = Debug.evaluate("vKern_mbox["+ core +"]["+ i +"].oNbMaxPacks");
			nbUsdPacks	  = Debug.evaluate("vKern_mbox["+ core +"]["+ i +"].oNbUsedPacks");
			dataEntrySize = Debug.evaluate("vKern_mbox["+ core +"]["+ i +"].oDataEntrySize");

			stateText = "Installed";
			if ((state & (1<<BMBOX_CONFIGURED)) != 0) { stateText += ", Configured";   }
			if ((state & (1<<BMBOX_EMPTY))	    != 0) { stateText += ", Empty";		   }
			if ((state & (1<<BMBOX_FULL))	    != 0) { stateText += ", Full";		   }
			if ((state & (1<<BMBOX_BY_COPY))	!= 0) { stateText += ", Mbox by copy"; }

			result.push(identifier);
			result.push(i.toString(10));
			result.push(stateText);
			result.push(nbMaxPacks.toString(10));
			result.push(nbUsdPacks.toString(10));
			result.push(dataEntrySize.toString(10));
			return (result);
		}

	}
	return (null);
}

// Semaphore management
// --------------------

/*
 * uKOS_getSemaphoreHeader()
 *
 *  Functions description:
 *    Delivers the column headers of the respective page.
 */
function uKOS_getSemaphoreHeader() {
	var		result;

	result = ["Semaphore", "Id", "State", "Counter", "Max counter", "Owner"];
	return (result);
}

/*
 * uKOS_getSemaphoreRow()
 *
 *  Functions description:
 *    Returns a row for the respective page.
 */
function uKOS_getSemaphoreRow(rowIndex) {
	var		BSEMA_INSTALLED = 0;
	var		result			= [];
	var		nbSemaphore;
	var		identifier;
	var		state;
	var		stateText;
	var		counter;
	var		maxCounter;
	var		owner;
	var		core;
	var		i;

	core		= vNbCores - 1;
	nbSemaphore = Debug.evaluate("KKERN_NB_SEMAPHORES");
	for (i = vLastPrimaryUsedRow; i < nbSemaphore; i++) {
		vLastPrimaryUsedRow++;
		state = Debug.evaluate("vKern_sema["+ core +"]["+ i +"].oState");
		if ((state & (1<<BSEMA_INSTALLED)) != 0) {
			identifier = Debug.evaluate("vKern_sema["+ core +"]["+ i +"].oIdentifier").toString();
			counter	   = Debug.evaluate("vKern_sema["+ core +"]["+ i +"].oCounter");
			maxCounter = Debug.evaluate("vKern_sema["+ core +"]["+ i +"].oMaxCounter");
			owner	   = Debug.evaluate("vKern_sema["+ core +"]["+ i +"].oOwner->oSpecification.oIdentifier").toString();

			stateText = "Installed";
			maxCounter = (maxCounter == 0x7FFFFFFF) ? ("2^31 - 1") : (maxCounter);

			result.push(identifier);
			result.push(i.toString(10));
			result.push(stateText);
			result.push(counter.toString(10));
			result.push(maxCounter.toString());
			result.push(owner);
			return (result);
		}

	}
	return (null);
}

// Mutex management
// ----------------

/*
 * uKOS_getMutexHeader()
 *
 *  Functions description:
 *    Delivers the column headers of the respective page.
 */
function uKOS_getMutexHeader() {
	var		result;

	result = ["Mutex", "Id", "State", "Counter", "Max counter", "Owner"];
	return (result);
}

/*
 * uKOS_getMutexRow()
 *
 *  Functions description:
 *    Returns a row for the respective page.
 */
function uKOS_getMutexRow(rowIndex) {
	var		BMUTX_INSTALLED = 0;
	var		result			= [];
	var		nbMutex;
	var		identifier;
	var		state;
	var		stateText;
	var		counter;
	var		maxCounter;
	var		owner;
	var		core;
	var		i;

	core	= vNbCores - 1;
	nbMutex = Debug.evaluate("KKERN_NB_MUTEXES");
	for (i = vLastPrimaryUsedRow; i < nbMutex; i++) {
		vLastPrimaryUsedRow++;
		state = Debug.evaluate("vKern_mutx["+ core +"]["+ i +"].oState");
		if ((state & (1<<BMUTX_INSTALLED)) != 0) {
			identifier = Debug.evaluate("vKern_mutx["+ core +"]["+ i +"].oIdentifier").toString();
			counter	   = Debug.evaluate("vKern_mutx["+ core +"]["+ i +"].oCounter");
			maxCounter = Debug.evaluate("vKern_mutx["+ core +"]["+ i +"].oMaxCounter");
			owner	   = Debug.evaluate("vKern_mutx["+ core +"]["+ i +"].oOwner->oSpecification.oIdentifier").toString();

			stateText = "Installed";
			maxCounter = (maxCounter == 0x7FFFFFFF) ? ("2^31 - 1") : (maxCounter);

			result.push(identifier);
			result.push(i.toString(10));
			result.push(stateText);
			result.push(counter.toString(10));
			result.push(maxCounter.toString());
			result.push(owner);
			return (result);
		}

	}
	return (null);
}

// Signal management
// -----------------

/*
 * uKOS_getSignalHeader()
 *
 *  Functions description:
 *    Delivers the column headers of the respective page.
 */
function uKOS_getSignalHeader() {
	var		result;

	result = ["Signal", "Id", "Process", "Bit pending", "Bit generated", "Signal from"];
	return (result);
}

/*
 * uKOS_getSignalRow()
 *
 *  Functions description:
 *    Returns a row for the respective page.
 */
function uKOS_getSignalRow(rowIndex) {
	var		BPROC_INSTALLED		   = 1;
	var		BSIGN_INSTALLED		   = 0;
	var		KKERN_HANDLE_WRONG	   = 0;
	var		KKERN_HANDLE_FROM_ISR  = 1;
	var		KKERN_HANDLE_BROADCAST = 2;
	var		result				   = [];
	var		nbSignal;
	var		nbProcess;
	var		identifier;
	var		process;
	var		bitPending;
	var		bitGenerated;
	var		signalFrom;
	var		from;
	var		state;
	var		core;
	var		i;
	var		j;

	core	  = vNbCores - 1;
	nbSignal  = Debug.evaluate("KKERN_NB_SIGNALS");
	nbProcess = Debug.evaluate("KKERN_NB_PROCESSES");
	for (i = vLastPrimaryUsedRow; i < nbSignal; i++) {
		state = Debug.evaluate("vKern_sign["+ core +"]["+ i +"].oState");
		if ((state & (1<<BSIGN_INSTALLED)) != 0) {
			identifier	= Debug.evaluate("vKern_sign["+ core +"]["+ i +"].oIdentifier").toString();

			for (j = vLastAuxiliaryUsedRow; j < nbProcess; j++) {
				vLastAuxiliaryUsedRow++;
				state = Debug.evaluate("vKern_proc["+ core +"]["+ j +"].oInternal.oState");
				if ((state & (1<<BPROC_INSTALLED)) != 0) {
					process		 = Debug.evaluate("vKern_proc["+ core +"]["+ j +"].oSpecification.oIdentifier").toString();
					bitPending	 = Debug.evaluate("vKern_sign["+ core +"]["+ i +"].oSynchro["+ j +"].oSignalBitPending");
					bitGenerated = Debug.evaluate("vKern_sign["+ core +"]["+ i +"].oSynchro["+ j +"].oSignalBitGenerate");
					signalFrom	 = Debug.evaluate("vKern_sign["+ core +"]["+ i +"].oSynchro["+ j +"].oSignalFromProcess");

					from = " ";
					from = (signalFrom == KKERN_HANDLE_FROM_ISR)  ? ("From ISR routine")  : (from);
					from = (signalFrom == KKERN_HANDLE_BROADCAST) ? ("Broadcast")		  : (from);
					from = (signalFrom <= KKERN_HANDLE_BROADCAST) ? (from)				  : (Debug.evaluate("vKern_sign["+ core +"]["+ i +"].oSynchro["+ j +"].oSignalFromProcess->oSpecification.oIdentifier").toString());

					result.push(identifier);
					result.push(i.toString(10));
					result.push(process);
					result.push("b" + bitPending.toString(2));
					result.push("b" + bitGenerated.toString(2));
					result.push(from);
					return (result);
				}

			}
			vLastPrimaryUsedRow++;
			vLastAuxiliaryUsedRow = 0;
		}
	}
	return (null);
}

// Precise signal management
// -------------------------

/*
 * uKOS_getPreciseSignalHeader()
 *
 *  Functions description:
 *    Delivers the column headers of the respective page.
 */
function uKOS_getPreciseSignalHeader() {
	var		result;

	result = ["Precise signal", "Id", "State", "Mode", "Next time [us]", "Period [us]", "Signal", "Signal group", "Process"];
	return (result);
}

/*
 * uKOS_getPreciseSignalRow()
 *
 *  Functions description:
 *    Returns a row for the respective page.
 */
function uKOS_getPreciseSignalRow(rowIndex) {
	var		BPRCS_INSTALLED	  = 0;
	var		KPRCS_STOP		  = 0;
	var		KPRCS_SINGLE_SHOT = 1;
	var		KPRCS_CONTINUOUS  = 2;
	var		result			  = [];
	var		nbPreciseSignal;
	var		identifier;
	var		nextTime;
	var		period;
	var		signal;
	var		mode;
	var		signalGroup;
	var		process;
	var		state;
	var		core;
	var		i;

	core			= vNbCores - 1;
	nbPreciseSignal = Debug.evaluate("KKERN_NB_PRECISE_SIGNALS");
	for (i = vLastPrimaryUsedRow; i < nbPreciseSignal; i++) {
		vLastPrimaryUsedRow++;
		state = Debug.evaluate("vKern_prcs["+ core +"]["+ i +"].oState");
		if ((state & (1<<BPRCS_INSTALLED)) != 0) {
			identifier	= Debug.evaluate("vKern_prcs["+ core +"]["+ i +"].oIdentifier").toString();
			nextTime	= Debug.evaluate("vKern_prcs["+ core +"]["+ i +"].oNextTime");
			period		= Debug.evaluate("vKern_prcs["+ core +"]["+ i +"].oPeriod");
			signal		= Debug.evaluate("vKern_prcs["+ core +"]["+ i +"].oSignal");
			mode		= Debug.evaluate("vKern_prcs["+ core +"]["+ i +"].oMode");
			signalGroup	= Debug.evaluate("vKern_prcs["+ core +"]["+ i +"].oSignalGroup->oIdentifier").toString();
			process		= Debug.evaluate("vKern_prcs["+ core +"]["+ i +"].oToProcess->oSpecification.oIdentifier").toString();

			stateText = "Installed";

			modeText = "";
			if ((mode & (1<<KPRCS_STOP))		!= 0) { modeText += "Stop";		   }
			if ((mode & (1<<KPRCS_SINGLE_SHOT)) != 0) { modeText += "Single shot"; }
			if ((mode & (1<<KPRCS_CONTINUOUS))	!= 0) { modeText += "Continuous";  }

			result.push(identifier);
			result.push(i.toString(10));
			result.push(stateText);
			result.push(modeText);
			result.push(nextTime.toString(10));
			result.push(period.toString(10));
			result.push("b" + signal.toString(2));
			result.push(signalGroup);
			result.push(process);
			return (result);
		}

	}
	return (null);
}

// Software timer management
// -------------------------

/*
 * uKOS_getSoftwareTimerHeader()
 *
 *  Functions description:
 *    Delivers the column headers of the respective page.
 */
function uKOS_getSoftwareTimerHeader() {
	var		result;

	result = ["Software timer", "Id", "State", "Mode", "Init Time [ms]", "Time [ms]", "Init Counter", "Counter"];
	return (result);
}

/*
 * uKOS_getSoftwareTimerRow()
 *
 *  Functions description:
 *    Returns a row for the respective page.
 */
function uKOS_getSoftwareTimerRow(rowIndex) {
	var		BSTIM_INSTALLED		= 0;
	var		BSTIM_CONFIGURED	= 1;
	var		BSTIM_RE_CONFIGURED	= 2;
	var		BSTIM_RUNNING		= 3;
	var		BSTIM_EXECUTED		= 4;
	var		KSTIM_STOP			= 0;
	var		KSTIM_SINGLE_SHOT	= 1;
	var		KSTIM_CONTINUOUS	= 2;
	var		result				= [];
	var		nbSoftwareTimer;
	var		identifier;
	var		state;
	var		stateText;
	var		mode;
	var		modeText;
	var		initCounter;
	var		counter;
	var		iniTime;
	var		time;
	var		core;
	var		i;

	core			= vNbCores - 1;
	nbSoftwareTimer = Debug.evaluate("KKERN_NB_SOFTWARE_TIMERS");
	for (i = vLastPrimaryUsedRow; i < nbSoftwareTimer; i++) {
		vLastPrimaryUsedRow++;
		state = Debug.evaluate("vKern_stim["+ core +"]["+ i +"].oState");
		if ((state & (1<<BSTIM_INSTALLED)) != 0) {
			identifier	= Debug.evaluate("vKern_stim["+ core +"]["+ i +"].oIdentifier").toString();
			initCounter	= Debug.evaluate("vKern_stim["+ core +"]["+ i +"].oInitCounter");
			counter		= Debug.evaluate("vKern_stim["+ core +"]["+ i +"].oCounter");
			mode		= Debug.evaluate("vKern_stim["+ core +"]["+ i +"].oTimerSpec.oMode");
			iniTime		= Debug.evaluate("vKern_stim["+ core +"]["+ i +"].oTimerSpec.oInitialTime");
			time		= Debug.evaluate("vKern_stim["+ core +"]["+ i +"].oTimerSpec.oTime");

			stateText = "Installed";
			if ((state & (1<<BSTIM_CONFIGURED))	   != 0) { stateText += ", Configured";	  }
			if ((state & (1<<BSTIM_RE_CONFIGURED)) != 0) { stateText += ", Reconfigured"; }
			if ((state & (1<<BSTIM_RUNNING))	   != 0) { stateText += ", Running";	  }
			if ((state & (1<<BSTIM_EXECUTED))	   != 0) { stateText += ", Executed";	  }

			modeText = "";
			if ((mode & (1<<KSTIM_STOP))		!= 0) { modeText += "Stop";		   }
			if ((mode & (1<<KSTIM_SINGLE_SHOT)) != 0) { modeText += "Single shot"; }
			if ((mode & (1<<KSTIM_CONTINUOUS))  != 0) { modeText += "Continuous";  }

			result.push(identifier);
			result.push(i.toString(10));
			result.push(stateText);
			result.push(modeText);
			result.push(iniTime.toString(10));
			result.push(time.toString(10));
			result.push(initCounter.toString(10));
			result.push(counter.toString(10));
			return (result);
		}

	}
	return (null);
}

// Pool management
// ---------------

/*
 * uKOS_getPoolHeader()
 *
 *  Functions description:
 *    Delivers the column headers of the respective page.
 */
function uKOS_getPoolHeader() {
	var		result;

	result = ["Pool", "Id", "State", "Number of blocks", "Blocksize [KBytes]", "Block array", "Used block", "Semaphore", "Counter"];
	return (result);
}

/*
 * uKOS_getPoolRow()
 *
 *  Functions description:
 *    Returns a row for the respective page.
 */
function uKOS_getPoolRow(rowIndex) {
	var		BPOOL_INSTALLED	 = 0;
	var		BPOOL_CONFIGURED = 1;
	var		result			 = [];
	var		nbPool;
	var		identifier;
	var		state;
	var		stateText;
	var		nbBlocks;
	var		blocksSize;
	var		blockArray;
	var		usedBlocks;
	var		semaphore;
	var		counter;
	var		core;
	var		i;

	core   = vNbCores - 1;
	nbPool = Debug.evaluate("KKERN_NB_POOLS");
	for (i = vLastPrimaryUsedRow; i < nbPool; i++) {
		vLastPrimaryUsedRow++;
		state = Debug.evaluate("vKern_pool["+ core +"]["+ i +"].oState");
		if ((state & (1<<BPOOL_INSTALLED)) != 0) {
			identifier = Debug.evaluate("vKern_pool["+ core +"]["+ i +"].oIdentifier").toString();
			nbBlocks   = Debug.evaluate("vKern_pool["+ core +"]["+ i +"].oNbBlocks");
			blocksSize = Debug.evaluate("vKern_pool["+ core +"]["+ i +"].oBlockSize");
			blockArray = Debug.evaluate("vKern_pool["+ core +"]["+ i +"].oBlockArray");
			usedBlocks = Debug.evaluate("vKern_pool["+ core +"]["+ i +"].oUsedBlocks");
			semaphore  = Debug.evaluate("vKern_pool["+ core +"]["+ i +"].oReleaseSema->oIdentifier").toString();
			counter	   = Debug.evaluate("vKern_pool["+ core +"]["+ i +"].oReleaseSema->oCounter");

			blocksSize	= blocksSize / 1024;

			stateText = "Installed";
			if ((state & (1<<BPOOL_CONFIGURED)) != 0) { stateText += ", Configured";	}

			result.push(identifier);
			result.push(i.toString(10));
			result.push(stateText);
			result.push(nbBlocks.toString(10));
			result.push(blocksSize.toString(10));
			result.push("0x" + local_padLeftString(blockArray.toString(16).toUpperCase(), vPadding));
			result.push("0x" + local_padLeftString(usedBlocks.toString(16).toUpperCase(), vPadding));
			result.push(semaphore);
			result.push(counter.toString(10));
			return (result);
		}

	}
	return (null);
}

// Trace management
// ----------------

/*
 * uKOS_getTraceHeader()
 *
 *  Functions description:
 *    Delivers the column headers of the respective page.
 */
function uKOS_getTraceHeader() {
	var		result;

	result = ["TimeStamp [us]", "Process", "Parameter", "Message"];
	return (result);
}

/*
 * uKOS_getTraceRow()
 *
 *  Functions description:
 *    Returns a row for the respective page.
 */
function uKOS_getTraceRow(rowIndex) {
	var		szTraceFifo;
	var		identifier;
	var		timeStamp;
	var		message;
	var		parameter;
	var		core;
	var		i;
	var		result = [];

	core		= vNbCores - 1;
	i			= rowIndex;
	szTraceFifo = Debug.evaluate("KRECORD_SZ_TRACE_FIFO");
	timeStamp	= Debug.evaluate("vRecord_traceFifo["+ core +"]["+ i +"].oTimeStamp");

	if ((i >= szTraceFifo) || (timeStamp == 0)) { return (null); }

	message	   = Debug.evaluate("vRecord_traceFifo["+ core +"]["+ i +"].oMessage").toString();
	parameter  = Debug.evaluate("vRecord_traceFifo["+ core +"]["+ i +"].oParameter");
	identifier = Debug.evaluate("vRecord_traceFifo["+ core +"]["+ i +"].oProcess->oSpecification.oIdentifier").toString();
	if (identifier == "") { identifier = "From ISR routine"; }

	result.push(timeStamp.toString(10));
	result.push(identifier);
	result.push("0x" + local_padLeftString(parameter.toString(16).toUpperCase(), vPadding));
	result.push(message);
	return (result);
}

// Log management
// --------------

/*
 * uKOS_getLogHeader()
 *
 *  Functions description:
 *    Delivers the column headers of the respective page.
 */
function uKOS_getLogHeader() {
	var		result;

	result = ["TimeStamp [us]", "Category", "lineNumber", "function", "Message"];
	return (result);
}

/*
 * uKOS_getLogRow()
 *
 *  Functions description:
 *    Returns a row for the respective page.
 */
function uKOS_getLogRow(rowIndex) {
	var		KFATAL_SYSTEM	 = 0x10;
	var		KFATAL_KERNEL	 = 0x11;
	var		KFATAL_MANAGER	 = 0x12;
	var		KFATAL_USER		 = 0x13;
	var		KERROR_SYSTEM	 = 0x20;
	var		KERROR_KERNEL	 = 0x21;
	var		KERROR_MANAGER	 = 0x22;
	var		KERROR_USER		 = 0x23;
	var		KWARNING_SYSTEM	 = 0x30;
	var		KWARNING_KERNEL	 = 0x31;
	var		KWARNING_MANAGER = 0x32;
	var		KWARNING_USER	 = 0x33;
	var		KINFO_SYSTEM	 = 0x40;
	var		KINFO_KERNEL	 = 0x41;
	var		KINFO_MANAGER 	 = 0x42;
	var		KINFO_USER		 = 0x43;
	var		result			 = [];
	var		szTraceLog;
	var		timeStamp;
	var		category;
	var		categoryText;
	var		identifier;
	var		lineNumber;
	var		message;
	var		core;
	var		i;

	core		= vNbCores - 1;
	i			= rowIndex;
	szTraceLog	= Debug.evaluate("KRECORD_SZ_LOG_BUF");
	timeStamp	= Debug.evaluate("vRecord_logBuffer["+ core +"]["+ i +"].oTimeStamp");

	if ((i >= szTraceLog) || (timeStamp == 0)) { return (null); }

	category   = Debug.evaluate("vRecord_logBuffer["+ core +"]["+ i +"].oLogCategory");
	message	   = Debug.evaluate("vRecord_logBuffer["+ core +"]["+ i +"].oMessage").toString();
	identifier = Debug.evaluate("vRecord_logBuffer["+ core +"]["+ i +"].oFunction").toString();
	lineNumber = Debug.evaluate("vRecord_logBuffer["+ core +"]["+ i +"].oLineNumber");
	if (identifier == "") { identifier = "From ISR routine"; }

	categoryText = "";
	if (category == KFATAL_SYSTEM)	  { categoryText = "FATAL system";	  }
	if (category == KFATAL_KERNEL)	  { categoryText = "FATAL uKernel";	  }
	if (category == KFATAL_MANAGER)	  { categoryText = "FATAL manager";	  }
	if (category == KFATAL_USER)	  { categoryText = "FATAL user";	  }

	if (category == KERROR_SYSTEM)	  { categoryText = "ERROR system";	  }
	if (category == KERROR_KERNEL)	  { categoryText = "ERROR uKernel";	  }
	if (category == KERROR_MANAGER)	  { categoryText = "ERROR manager";	  }
	if (category == KERROR_USER)	  { categoryText = "ERROR user";	  }

	if (category == KWARNING_SYSTEM)  { categoryText = "WARNING system";  }
	if (category == KWARNING_KERNEL)  { categoryText = "WARNING uKernel"; }
	if (category == KWARNING_MANAGER) { categoryText = "WARNING manager"; }
	if (category == KWARNING_USER)	  { categoryText = "WARNING user";	  }

	if (category == KINFO_SYSTEM)  	  { categoryText = "KINFO system";	  }
	if (category == KINFO_KERNEL)  	  { categoryText = "KINFO uKernel";	  }
	if (category == KINFO_MANAGER) 	  { categoryText = "KINFO manager";	  }
	if (category == KINFO_USER)		  { categoryText = "KINFO user";	  }

	result.push(timeStamp.toString(10));
	result.push(categoryText);
	result.push(lineNumber.toString(10));
	result.push(identifier);
	result.push(message);
	return (result);
}

// Memory management
// -----------------

/*
 * uKOS_getMemoryHeader()
 *
 *  Functions description:
 *    Delivers the column headers of the respective page.
 */
function uKOS_getMemoryHeader() {
	var		result;

	result = ["Heap", "Start address", "Total size [KBytes]", "Used [KBytes]", "Used [%]", "Number of used blocks", "Max. number of used blocks"];
	return (result);
}

/*
 * uKOS_getMemoryRow()
 *
 *  Functions description:
 *    Returns a row for the respective page.
 */
function local_displayHeapInformation(heap, heapStart, heapSize, heapUsedMemory, heapNbBlocks, heapNbMaxBlocks) {
	var		address;
	var		totalSize;
	var		uesed;
	var		usedPerCent;
	var		nbBloks;
	var		nbMaxBloks;
	var		postfix;
	var		result = [];

	address	= Debug.evaluate(heapStart);
	if (address > 0) {
		postfix		= ""
		totalSize	= Debug.evaluate(heapSize);
		used		= Debug.evaluate(heapUsedMemory);
		nbBloks		= Debug.evaluate(heapNbBlocks);
		nbMaxBloks	= Debug.evaluate(heapNbMaxBlocks);
		usedPerCent	= (used / totalSize) * 100;

		totalSize	= totalSize / 1024;
		used		= used / 1024;
	}
	else {
		postfix		= " - Not available";
		totalSize	= 0;
		used		= 0;
		nbBloks		= 0
		nbMaxBloks	= 0;
		usedPerCent	= 0;
	}

	result.push(heap + postfix);
	result.push("0x" + local_padLeftString(address.toString(16).toUpperCase(), vPadding));
	result.push(totalSize.toString());
	result.push(used.toString());
	result.push(usedPerCent.toString());
	result.push(nbBloks.toString());
	result.push(nbMaxBloks.toString());
	return (result);
}

function uKOS_getMemoryRow(rowIndex) {

	if (rowIndex == 0) { return (local_displayHeapInformation(" ", "linker_stHeap", "linker_lnHeap", "vMemo_heapInfo.oUsdMemory", "vMemo_heapInfo.oNbBlocks", "vMemo_heapInfo.oNbMaxBlocks")); }
	return (null);
}

// The about
// ---------

/*
 * uKOS_getAboutHeader()
 *
 *  Functions description:
 *    Delivers the column headers of the respective page.
 */
function uKOS_getAboutHeader() {
	var		result;

	result = ["About ..."];
	return (result);
}

/*
 * uKOS_getAboutRow()
 *
 *  Functions description:
 *    Returns a row for the respective page.
 */
function uKOS_getAboutRow(rowIndex) {
	var		line0 = ["uKOS-X plug-in V-2.0.0"																				 ];
	var		line1 = ["Last modification: 2026-02-22"																		 ];
	var		line2 = [" "																									 ];
	var		line3 = ["uKOS-" + vuKOSString																					 ];
	var		line4 = ["uKOS-X OS version under debug V " + vuKOSMajorString + "." + vuKOSMinorString + "." + vuKOSPatchString ];
	var		line5 = ["Architecture under debug: " + vArchString																 ];
	var		line6 = ["(c) 2025-2026, Edo. Franzi"																			 ];

	if (rowIndex == 0) { return (line0); }
	if (rowIndex == 1) { return (line1); }
	if (rowIndex == 2) { return (line2); }
	if (rowIndex == 3) { return (line3); }
	if (rowIndex == 4) { return (line4); }
	if (rowIndex == 5) { return (line5); }
	if (rowIndex == 6) { return (line6); }
	return (null);
}
