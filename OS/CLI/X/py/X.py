#!/usr/bin/env python
# -*- coding: utf-8 -*-

# X.
# ==

# SPDX-License-Identifier: MIT

#------------------------------------------------------------------------
# Author:	Edo. Franzi     The 2025-01-01
# Modifs:
#
# Project:	uKOS-X
# Goal:		Read a 128 element vector (temperature).
# 			Display the temperature vector
# 			Display the FFT of the temperature vector
#
#			Necessary packages:
#			python3 -m pip install numpy pyserial matplotlib
#
#			python3 X.py
#
#   (c) 2025-2026, Edo. Franzi
#   --------------------------
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

# Necessary packages

import	serial
import	serial.tools.list_ports
import	time
import	numpy as np
import	matplotlib.pyplot as plt

KNB_SAMPLES			= 128					# Number of samples
KNB_SAMPLES_P2		= 128					# Next power of 2 >= KNB_SAMPLES (For FFT)
KSAMPLING_FREQUENCY	= 5						# Sampling frequency (Hz)
KTIME_LOOP			= 0.05					# Loop time (s)
KDELTA_TEMPERATURE	= 30					# Delta temperature (for display)
KSERIAL_PORT_STLINK	= 'usbmodem'			# 'usbmodem' for STLink
KSERIAL_PORT_FTDI	= 'usbserial-uKOS_2'	# 'usbserial' for FTDI (usually, uKOS uses the port 2)
KBAUDRATE			= 460800				# Baudrate

# Compute the FFT of the temperature vector
# -----------------------------------------

def compute_fft(temperatures):
	frequencies   = np.linspace(0, KSAMPLING_FREQUENCY / 2, (KNB_SAMPLES_P2 // 2) + 1)
	result		  = np.fft.fft(temperatures, KNB_SAMPLES_P2) / KNB_SAMPLES
	amplitudes	  = np.abs(result[:(KNB_SAMPLES_P2 // 2) + 1])
	dcValue       = amplitudes[0]
	amplitudes[0] = 0

	foIndex = int(np.argmax(amplitudes))
	fo = (KSAMPLING_FREQUENCY / 2) * foIndex / (KNB_SAMPLES / 2)
	return (frequencies, (amplitudes * 2), dcValue, fo)

# Read the temperature vector
# ---------------------------

# Clean the input buffer
# Send the X command to the target
# Recover the answer x,23456,34345,33355,..\n
# Create a clean "temperature" vector

def read_temperatureVector(fdSerial):
	fdSerial.reset_input_buffer()
	fdSerial.write(b'X\n')

	answer = fdSerial.readline().decode().strip()
	if not answer.startswith("x,"):
		raise Exception("Unexpected response from device!")

	rawData = answer[2:].split(',')[:-1]
	vector = [int(val) for val in rawData]
	temperatures = np.array(vector) / 100.0
	return (temperatures)

# Serial channel management
# -------------------------

# Try to open the channel
#	List all the possible candidates that contain "KSERIAL_PORT_STLINK" or "KSERIAL_PORT_FTDI"
#
# Configure the channel

def serial_portList():
	ports = list(serial.tools.list_ports.comports())
	return ([deviceName.device for deviceName in ports if KSERIAL_PORT_STLINK in deviceName.device or KSERIAL_PORT_FTDI in deviceName.device])

def serial_openConnection():
	ports = serial_portList()
	if not ports:
		raise Exception("No matching serial ports found!")

	port = ports[0]
	fdSerial = serial.Serial(port, KBAUDRATE, timeout = 10)
	print(f"Connected to {port}")
	return (fdSerial)

# Main
# ----

# Mode interactif ON
# Display the temperature vector
# Display the FFT of the temperature vector

def main():
	fdSerial = None

	try:
		fdSerial = serial_openConnection()
		plt.ion()

		fig, (ax1, ax2) = plt.subplots(2, 1, figsize = (6, 4))
		fig.subplots_adjust(hspace = 0.5)

		line1, = ax1.plot([], [], 'g', label = "Temperature (K)")
		line2, = ax2.plot([], [], 'r', label = "FFT Amplitude")

		ax1.set_ylim(273 + (KDELTA_TEMPERATURE // 2), 273 + KDELTA_TEMPERATURE)
		ax1.set_xlim(0, KNB_SAMPLES)
		ax1.set_title("Temperature")
		ax1.set_ylabel("Kelvin")
		ax1.grid(True)

		ax2.set_xlim(0, KSAMPLING_FREQUENCY / 2)
		ax2.set_ylim(0, 10)
		ax2.set_title("FFT")
		ax2.set_xlabel("Hz")
		ax2.set_ylabel("|A|")
		ax2.grid(True)

		while True:
			try:
				temperatures = read_temperatureVector(fdSerial)
				frequencies, amplitudes, dcValue, fo = compute_fft(temperatures)

				print(f"DC = {dcValue:.2f} K, fo = {fo:.2f} Hz")

				line1.set_ydata(temperatures)
				line1.set_xdata(np.arange(len(temperatures)))
				line2.set_ydata(amplitudes)
				line2.set_xdata(frequencies)
				ax2.set_ylim(float(np.mean(amplitudes)) * 0.95, float(np.max(amplitudes) * 1.05))

				fig.canvas.draw()
				fig.canvas.flush_events()
				time.sleep(KTIME_LOOP)

			except Exception as e:
				print("Acquisition error:", e)
				time.sleep(1)

	finally:
		if 'fdSerial' in locals() and fdSerial.is_open:
			fdSerial.close()
			print("Serial connection closed.")

# Main entry point
if __name__ == '__main__':
	main()
