/*
; stub_wfi0_usart1_esp32_wifi_AP.
; ===============================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2025-01-01
; Modifs:
;
; Project:	uKOS-X
; Goal:		stub for the connection of the "wfi0" manager to the "usart1 - esp32" device.
;			wifi mode in access point
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

#include	"uKOS.h"

#undef	VERBOSE_S				// Display the answer

// Connect the physical device to the logical manager
// --------------------------------------------------

#define	USART							USART1
#define	USART_VECTOR_NUMBER				USART1_C0_IRQn
#define	USART_FREQUENCY					KFREQUENCY_APB2

#define	model_usart_init				stub_wfi0_init
#define	model_usart_configure			stub_wfi0_configure
#define	model_usart_writeTransparent	stub_wfi0_writeTransparent
#define	model_usart_write				stub_wfi0_write
#define	model_usart_read				stub_wfi0_read
#define	model_usart_flush				stub_wfi0_flush

#define	KUSART_SEMA_RX_S
#define	KUSART_SEMA_TX_S
#define	KUSART_SEMAPHORE_RX				KWFI0_SEMAPHORE_RX
#define	KUSART_SEMAPHORE_TX				KWFI0_SEMAPHORE_TX

#define	KUSART_SZ_TX_BUF				1024u
#define	KUSART_SZ_RX_BUF				1024u

extern	volatile	uint8_t		vRecBuffer[KUSART_SZ_RX_BUF];
extern	volatile	uint8_t		* volatile vRRecBuffer;
extern	volatile	uint8_t		* volatile vWRecBuffer;
extern	volatile	int32_t		vStatus;
extern	volatile	bool		vReadyToSend;
extern	volatile	bool		vSendAck;
extern	volatile	bool		vConnected;
static				bool		vEndInitSeq = false;
static				void		(*vState)(uint8_t data) = nullptr;

// Prototypes

static	void	local_sndCommand(const uint8_t *command, uint32_t wait);
static	void	local_state_CX(uint8_t data);
static	void	local_state_CO(uint8_t data);
static	void	local_state_CL(uint8_t data);
static	void	local_state_PX(uint8_t data);
static	void	local_state_PD(uint8_t data);
static	void	local_state_BG(uint8_t data);
static	void	local_state_SN(uint8_t data);
static	void	local_state_EM(uint8_t data);
		int32_t	stub_wfi0_write(const uint8_t *buffer, uint32_t size);
		int32_t	stub_wfi0_writeTransparent(const uint8_t *buffer, uint32_t size);
		int32_t	stub_wfi0_read(uint8_t *buffer, uint32_t *size);

// Model callbacks
// ---------------

/*
 * \brief cb_enable
 *
 * - Enable the device (clock)
 *
 */
static	void	cb_enable(void) {

	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
}

/*
 * \brief cb_CTSCheck
 *
 * - Verify the CTS state
 *   If CTS =  1, then disable the uart TX interruptions
 *
 */
static	bool	cb_CTSCheck(void) {

	return (true);
}

/*
 * \brief cb_init
 *
 * - Specific initialisations          __
 *   i.e the hardware CTS interruption   \__
 *
 */
static	void	cb_init(void) {
	const	uint8_t		aAT[]				= "AT\r\n";
	const	uint8_t		aCWMODE[]			= "AT+CWMODE=2\r\n";
	const	uint8_t		aCWSAP[]			= "AT+CWSAP=\"uKOS-X_wifi\",\"\",1,2,1,0\r\n";
	const	uint8_t		aCIPMUX[]			= "AT+CIPMUX=1\r\n";
	const	uint8_t		aCIPSERVERMAXCONN[] = "AT+CIPSERVERMAXCONN=1\r\n";
	const	uint8_t		aCIPSERVER[]		= "AT+CIPSERVER=1,9999\r\n";
	const	uint8_t		aATE0[]				= "ATE0\r\n";

// Initialise the ESP32 chip
// Set the TCP server mode

	kern_suspendProcess(10u);

	GPIOD->ODR |=			 (1u<<BESP32_NDOWNLOAD);
	GPIOE->ODR &= (uint32_t)~(1u<<BESP32_ENABLE);
	kern_suspendProcess(10u);
	GPIOE->ODR |=			 (1u<<BESP32_ENABLE);

// Set-up a personalised access-point:
//	AT+CWMODE=2
//	AT+CWSAP="uKOS-X_wifi","",1,0,4,0
//
// Open a TCP server:
//	AT+CIPMUX=1
//	AT+CIPSERVERMAXCONN=1
//	AT+CIPSERVER=1,9999

	local_sndCommand(aAT,			    100u);			// AT test
	local_sndCommand(aCWMODE,		    100u);			// SoftAP mode
	local_sndCommand(aCWSAP,			1000u);			// ssid, password, channel 1, WPA2_PSK, max connection 1, SSID broadcast
	local_sndCommand(aCIPMUX,		    100u);			// Multiple connection
	local_sndCommand(aCIPSERVERMAXCONN, 100u);			// Max. number of clients
	local_sndCommand(aCIPSERVER,	    100u);			// Create server on the 9999 port
	local_sndCommand(aATE0,			    100u);			// Without echo

	vEndInitSeq = true;
}

/*
 * \brief cb_read
 *
 * - Read the data
 *   !!! From the interruption routine
 *
 */
static	void	cb_read(void) {
	static	uint8_t		vData;

	vData = (uint8_t)USART->RDR;

	#if (defined(VERBOSE_S))
	urt1_write(&vData, 1u);
	#endif

// State machine management
// During the initialisation sequence, do not run the state-machine

	if (vEndInitSeq == true) {
		if (vState != nullptr) {
			(*vState)(vData);
			return;
		}

		switch (vData) {
			case '0': {
				vState = local_state_CX;
				(*vState)(vData);
				break;
			}
			case '+': {
				vState = local_state_PX;
				(*vState)(vData);
				break;
			}
			case '>': {
				vState = local_state_BG;
				(*vState)(vData);
				break;
			}
			case 'S': {
				vState = local_state_SN;
				(*vState)(vData);
				break;
			}
			default: {
				vState = local_state_EM;
				(*vState)(vData);
				break;
			}
		}
	}
}

// State machine
// =============

/*
 * \brief local_state_CX
 *
 * - Waiting for 0,CX
 *		- Then, waiting for "0,CONNECT\r\n" or "0,CLOSED\r\n"
 *
 */
static	void	local_state_CX(uint8_t data) {
	static	uint8_t		vI = 0u;
	const	uint8_t		aWaitingFor[] = "0,Cx";

	if (aWaitingFor[vI] == data) {
		if (++vI == (sizeof(aWaitingFor) - 1u)) {
			vI = 0u; vState = nullptr;
		}
	}
	else {
		if (vI == 3u) {
			switch (data) {
				case 'O': { vI = 0u; vState = local_state_CO; break; }
				case 'L': { vI = 0u; vState = local_state_CL; break; }
				default:  { vI = 0u; vState = local_state_EM; break; }
			}
		}
		else {
			vI = 0; vState = local_state_EM;
		}
	}
}

/*
 * \brief local_state_CO
 *
 * - Waiting for "0,CONNECT\r\n"
 *
 */
static	void	local_state_CO(uint8_t data) {
	static	uint8_t		vI = 4u;
	const	uint8_t		aWaitingFor[] = "0,CONNECT\r\n";
//              Tested under CX             ^
//              Entry on CO                  ^

	if (aWaitingFor[vI] == data) {
		if (++vI == (sizeof(aWaitingFor) - 1u)) {
			vI = 4u; vState = nullptr;
			vConnected = true;
		}
	}
	else {
		vI = 4; vState = local_state_EM;
	}
}

/*
 * \brief local_state_CL
 *
 * - Waiting for "0,CLOSED\r\n"
 *
 */
static	void	local_state_CL(uint8_t data) {
	static	uint8_t		vI = 4u;
	const	uint8_t		aWaitingFor[] = "0,CLOSED\r\n";
//              Tested under CX             ^
//              Entry on CL                  ^

	if (aWaitingFor[vI] == data) {
		if (++vI == (sizeof(aWaitingFor) - 1u)) {
			vI = 4u; vState = nullptr;
			vConnected = false;
		}
	}
	else {
		vI = 4; vState = local_state_EM;
	}
}

/*
 * \brief local_state_PX
 *
 * - Waiting for +IPD,0,
 *		- Then, waiting for "+IPD,0,n:xxxxxxxxx...x\r\n"
 *
 */
static	void	local_state_PX(uint8_t data) {
	static	uint8_t		vI = 0u;
	const	uint8_t		aWaitingFor[] = "+IPD,0,";

	if (aWaitingFor[vI] == data) {
		if (++vI == (sizeof(aWaitingFor) - 1u)) {
			vI = 0u; vState = local_state_PD;
		}
	}
	else {
		vI = 0u; vState = local_state_EM;
	}
}

/*
 * \brief local_state_PD
 *
 * - Waiting for nn.n and the data
 *
 */
static	void	local_state_PD(uint8_t data) {
			char_t		*dummy;
	static	uint8_t		vI = 0u;
	static	char_t		vASCIINumber[4 + 1];
	static	int32_t		vSize;
	static	bool		vRead = false;

	if (vRead == false) {
		if (data != ':') {
			vASCIINumber[vI] = (char_t)data;
			vI++;
			if (vI == (sizeof(vASCIINumber) - 1u)) {
				vI = 0u; vState = local_state_EM;
			}
		}
		else {
			vASCIINumber[vI] = '\0';
			vSize = (int32_t)strtol(&vASCIINumber[0], &dummy, 10u);
			vRead = true;
		}
	}

// Read the data

	else {
		*vWRecBuffer = data;
		vWRecBuffer++;

		const	uintptr_t	w = (uintptr_t)vWRecBuffer;
		const	uintptr_t	r = (uintptr_t)vRRecBuffer;
		const	uintptr_t	e = (uintptr_t)&vRecBuffer[KUSART_SZ_RX_BUF];

		if (w == r) { vStatus = KERR_SERIAL_RBFUL; }
		if (w == e) { vWRecBuffer = vRecBuffer;	   }

		if (--vSize == 0) {
			vRead = false;
			vI = 0u; vState = nullptr;
		}
	}
}

/*
 * \brief local_state_SN
 *
 * - Waiting for "SEND OK\r\n"
 *
 */
static	void	local_state_SN(uint8_t data) {
	static	uint8_t		vI = 0u;
	const	uint8_t		aWaitingFor[] = "SEND OK\r\n";

	if (aWaitingFor[vI] == data) {
		if (++vI == (sizeof(aWaitingFor) - 1u)) {
			vI = 0; vState = nullptr;
			vSendAck = true;
		}
	}
	else {
		vI = 0u; vState = local_state_EM;
	}
}

/*
 * \brief local_state_EM
 *
 * - Waiting for "\r\n"
 *
 */
static	void	local_state_EM(uint8_t data) {
	static	uint8_t		i = 0u;
	const	uint8_t		aWaitingFor[] = "\r\n";

	if (aWaitingFor[i] == data) {
		if (++i == (sizeof(aWaitingFor) - 1u)) {
			i = 0u; vState = nullptr;
		}
	}
	else {
		i = 0u;
	}
}

/*
 * \brief local_state_BG
 *
 * - Set the flag vReadyToSend
 *
 */
static	void	local_state_BG(uint8_t data) {

	UNUSED(data);

	vReadyToSend = true;
	vState = nullptr;
}

// Local routines
// ==============

/*
 * \brief local_sndCommand
 *
 * - Send a command to the ESP32 and read the answer
 *
 */
static	void	local_sndCommand(const uint8_t *command, uint32_t wait) {
	size_t	size;

// Send the command

	size = strlen((const char_t *)command);
	stub_wfi0_writeTransparent(command, (uint32_t)size);
	kern_suspendProcess(wait);
}

#include	"model_usart_esp32_wifi_AP.c_inc"
