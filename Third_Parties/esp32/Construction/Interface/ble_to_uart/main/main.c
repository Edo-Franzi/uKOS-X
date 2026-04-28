/*
; ble_to_uart.
; ============

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2026-04-27
; Modifs:
;
; Project:	uKOS-X
; Goal:		Bridge between uart1 and BLE (transparent mode).
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

#include	<stdio.h>
#include	<string.h>
#include	<stdbool.h>

#include	"freertos/FreeRTOS.h"
#include	"freertos/task.h"

#include	"driver/uart.h"
#include	"driver/gpio.h"

#include	"esp_log.h"
#include	"esp_err.h"
#include	"nvs_flash.h"

#include	"nimble/ble.h"
#include	"nimble/nimble_port.h"
#include	"nimble/nimble_port_freertos.h"
#include	"host/ble_hs.h"
#include	"host/ble_uuid.h"
#include	"host/util/util.h"
#include	"services/gap/ble_svc_gap.h"
#include	"services/gatt/ble_svc_gatt.h"

#define	KDEVICE_NAME	"uKOS-X_BLE"
#define KTAG			"BLE_UART"

// UART used by the bridge

#define	KUART_PORT		UART_NUM_1
#define	KUART_BAUDRATE	460800u
#define	KUART_BUF_SIZE	1024u

#define	KUART_TX_PIN	17u
#define	KUART_RX_PIN	16u
#define	KUART_RTS_PIN	UART_PIN_NO_CHANGE
#define	KUART_CTS_PIN	UART_PIN_NO_CHANGE

// Nordic UART Service UUIDs, little-endian format for NimBLE
// RX: central writes here, ESP32 receives
// TX: ESP32 notifies central here

static	const	ble_uuid128_t	aUartServiceUUID = BLE_UUID128_INIT(0x9E, 0xCA, 0xDC, 0x24, 0x0E, 0xE5, 0xA9, 0xE0, 0x93, 0xF3, 0xA3, 0xB5, 0x01, 0x00, 0x40, 0x6E);
static	const	ble_uuid128_t	aUartRxUUID		 = BLE_UUID128_INIT(0x9E, 0xCA, 0xDC, 0x24, 0x0E, 0xE5, 0xA9, 0xE0, 0x93, 0xF3, 0xA3, 0xB5, 0x02, 0x00, 0x40, 0x6E);
static	const	ble_uuid128_t	aUartTxUUID		 = BLE_UUID128_INIT(0x9E, 0xCA, 0xDC, 0x24, 0x0E, 0xE5, 0xA9, 0xE0, 0x93, 0xF3, 0xA3, 0xB5, 0x03, 0x00, 0x40, 0x6E);

static			bool			vNotifyEnabled	 = false;
static			uint16_t		vConnHandle		 = BLE_HS_CONN_HANDLE_NONE;
static			uint16_t		vTxValHandle	 = 0;
static			uint16_t		vMtuPayload		 = 20;
static			uint8_t			vOwnAddrType;

// Prototypes

static	void	local_bleOnSync(void);
static	void	local_startAdvertising(void);
static	void	local_notifyUartData(const uint8_t *data, uint16_t len);
static	void	local_uartToBleTask(void *arg);
static	void	local_bleOnReset(int reason);
static	void	local_nimbleHostTask(void *param);
static	void	local_initUart(void);
static	int		local_bleUartTXAccess_cb(uint16_t conn_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt *ctxt, void *arg);
static	int		local_bleUartRXAccess_cb(uint16_t conn_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt *ctxt, void *arg);
static	int		local_gapEvent_cb(struct ble_gap_event *event, void *arg);

static	const	struct	ble_gatt_svc_def aGattService[] = {
	{
		.type = BLE_GATT_SVC_TYPE_PRIMARY,
		.uuid = &aUartServiceUUID.u,
		.characteristics = (struct ble_gatt_chr_def[]) {
			{
				.uuid = &aUartRxUUID.u,
				.access_cb = local_bleUartRXAccess_cb,
				.flags = BLE_GATT_CHR_F_WRITE | BLE_GATT_CHR_F_WRITE_NO_RSP,
			},
			{
				.uuid = &aUartTxUUID.u,
				.access_cb = local_bleUartTXAccess_cb,
				.val_handle = &vTxValHandle,
				.flags = BLE_GATT_CHR_F_NOTIFY,
			},
			{ 0 }
		},
	},
	{ 0 }
};

/*
 * \brief app_main
 *
 * - Main application entry point.
 *   Initialise NVS
 *   configure UART
 *   set up and initialise the NimBLE BLE stack (GAP/GATT services and device name)
 *   register the UART service
 *   starts both the BLE host task and the UART-to-BLE bridge task
 *
 */
void	app_main(void) {
	esp_err_t	ret;
	BaseType_t	taskCreated;

	ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);

	local_initUart();

	ESP_ERROR_CHECK(nimble_port_init());
	ESP_ERROR_CHECK(ble_att_set_preferred_mtu(517));

	ble_hs_cfg.reset_cb	 = local_bleOnReset;
	ble_hs_cfg.sync_cb	 = local_bleOnSync;
	ble_hs_cfg.sm_io_cap = BLE_HS_IO_NO_INPUT_OUTPUT;

	ble_svc_gap_init();
	ble_svc_gatt_init();

	ESP_ERROR_CHECK(ble_svc_gap_device_name_set(KDEVICE_NAME));
	ESP_ERROR_CHECK(ble_gatts_count_cfg(aGattService));
	ESP_ERROR_CHECK(ble_gatts_add_svcs(aGattService));

	nimble_port_freertos_init(local_nimbleHostTask);
	taskCreated = xTaskCreate(local_uartToBleTask, "uart_to_ble", 4096, NULL, 5, NULL);
	if (taskCreated != pdPASS) { ESP_LOGE(KTAG, "Failed to create uart_to_ble task"); }

	ESP_LOGI(KTAG, "BLE UART bridge started");
}

// Local routines
// ==============

/*
 * \brief local_startAdvertising
 *
 * - Start BLE advertising with the device name and predefined parameters (connectable,
 *   general discovery mode, advertising interval)
 *
 */
static	void	local_startAdvertising(void) {
			int					rc;
	struct	ble_gap_adv_params	adv_params;
	struct	ble_hs_adv_fields	fields;

	memset(&fields, 0, sizeof(fields));
	fields.flags			= BLE_HS_ADV_F_DISC_GEN | BLE_HS_ADV_F_BREDR_UNSUP;
	fields.name				= (const uint8_t *)KDEVICE_NAME;
	fields.name_len			= strlen(KDEVICE_NAME);
	fields.name_is_complete = 1;

	rc = ble_gap_adv_set_fields(&fields);
	if (rc != 0) { ESP_LOGE(KTAG, "ble_gap_adv_set_fields failed: %d", rc); return; }

	memset(&adv_params, 0, sizeof(adv_params));
	adv_params.conn_mode   = BLE_GAP_CONN_MODE_UND;
	adv_params.disc_mode   = BLE_GAP_DISC_MODE_GEN;
	adv_params.channel_map = BLE_GAP_ADV_DFLT_CHANNEL_MAP;

// 0x20 = 20 ms, 0x40 = 40 ms environ

	adv_params.itvl_min = 0x20;
	adv_params.itvl_max = 0x40;

	rc = ble_gap_adv_start(vOwnAddrType, NULL, BLE_HS_FOREVER, &adv_params, local_gapEvent_cb, NULL);
	if (rc != 0) { ESP_LOGE(KTAG, "ble_gap_adv_start failed: %d", rc); }
	else		 { ESP_LOGI(KTAG, "Advertising as uKOS-X_BLE");		   }
}

/*
 * \brief local_bleUartTXAccess_cb
 *
 * - GATT access callback for the TX characteristic (notify only).
 *   Currently unused since TX is handled via notifications
 *
 */
static	int		local_bleUartTXAccess_cb(uint16_t conn_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt *ctxt, void *arg) {

	(void)conn_handle;
	(void)attr_handle;
	(void)ctxt;
	(void)arg;

	return (0);
}

/*
 * \brief local_bleUartRXAccess_cb
 *
 * - Handle data written by the BLE central to the RX characteristic.
 *   Received data is extracted from the BLE buffer and forwarded to the UART
 *
 */
static	int		local_bleUartRXAccess_cb(uint16_t conn_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt *ctxt, void *arg) {
	int			rc;
	int			len = OS_MBUF_PKTLEN(ctxt->om);
	int			offset = 0;
	uint8_t		buffer[KUART_BUF_SIZE];

	(void)conn_handle;
	(void)attr_handle;
	(void)arg;

	if (len <= 0) { return (0); }

	while (offset < len) {
		int chunk = len - offset;
		if (chunk > (int)sizeof(buffer)) {
			chunk = sizeof(buffer);
		}

		rc = os_mbuf_copydata(ctxt->om, offset, chunk, buffer);
		if (rc != 0) { ESP_LOGW(KTAG, "os_mbuf_copydata failed: %d", rc); return (BLE_ATT_ERR_UNLIKELY); }

		uart_write_bytes(KUART_PORT, (const char *)buffer, chunk);
		offset += chunk;
	}
	return (0);
}

/*
 * \brief local_notifyUartData
 *
 * - Send UART data over BLE using notifications.
 *   The data is fragmented according to the negotiated MTU payload size
 *
 */
static	void	local_notifyUartData(const uint8_t *data, uint16_t len) {
			int			rc;
			uint16_t	offset = 0;
			uint16_t	chunk;
	struct	os_mbuf		*om;

	if ((vConnHandle == BLE_HS_CONN_HANDLE_NONE) || (!vNotifyEnabled)) { return; }

	while (offset < len) {
		chunk = len - offset;
		if (chunk > vMtuPayload) {
			chunk = vMtuPayload;
		}

		om = ble_hs_mbuf_from_flat((data + offset), chunk);
		if (om == NULL) { ESP_LOGW(KTAG, "Failed to allocate mbuf"); return; }

		rc = ble_gattc_notify_custom(vConnHandle, vTxValHandle, om);
		if (rc != 0)	{ ESP_LOGW(KTAG, "notify failed: %d", rc);	 return; }

		offset += chunk;
		vTaskDelay(pdMS_TO_TICKS(2));
	}
}

/*
 * \brief local_uartToBleTask
 *
 * - FreeRTOS task that continuously reads data from UART and
 *   forwards it to BLE using notifications
 *
 */
static	void	local_uartToBleTask(void *arg) {
	int			len;
	uint8_t		buffer[KUART_BUF_SIZE];

	(void)arg;

	while (true) {
		len = uart_read_bytes(KUART_PORT, buffer, sizeof(buffer), pdMS_TO_TICKS(20));
		if (len > 0) {
			local_notifyUartData(buffer, (uint16_t)len);
		}
	}
}

/*
 * \brief local_gapEvent_cb
 *
 * - Handles BLE GAP events such as connection, disconnection,
 *   subscription (notifications enable/disable), and MTU updates
 *
 */
static	int	local_gapEvent_cb(struct ble_gap_event *event, void *arg) {

	(void)arg;

	switch (event->type) {
		case BLE_GAP_EVENT_CONNECT: {
			if (event->connect.status == 0) {
				vConnHandle = event->connect.conn_handle;
				vNotifyEnabled = false;
				vMtuPayload = 20;
				ESP_LOGI(KTAG, "BLE connected, handle=%d", vConnHandle);
			} else {
				ESP_LOGW(KTAG, "Connection failed, status=%d", event->connect.status);
				local_startAdvertising();
			}
			return (0);
		}

		case BLE_GAP_EVENT_DISCONNECT: {
			ESP_LOGI(KTAG, "BLE disconnected, reason=%d", event->disconnect.reason);
			vConnHandle = BLE_HS_CONN_HANDLE_NONE;
			vNotifyEnabled = false;
			vMtuPayload = 20;
			local_startAdvertising();
			return (0);
		}

		case BLE_GAP_EVENT_SUBSCRIBE: {
			if (event->subscribe.attr_handle == vTxValHandle) {
				vNotifyEnabled = event->subscribe.cur_notify;
				ESP_LOGI(KTAG, "Notify %s", (vNotifyEnabled == true) ? ("enabled") : ("disabled"));
			}
			return (0);
		}

		case BLE_GAP_EVENT_MTU: {
			vMtuPayload = (event->mtu.value > 3) ? (event->mtu.value - 3) : (20);
			ESP_LOGI(KTAG, "MTU updated: %d, payload=%d", event->mtu.value, vMtuPayload);
			return (0);
		}

		default: {
			return 0;
		}
	}
}

/*
 * \brief local_bleOnSync
 *
 * - Called when the BLE stack is ready.
 *   Initialise the device address and start advertising
 *
 */
static	void	local_bleOnSync(void) {
	int		rc;

	rc = ble_hs_id_infer_auto(0, &vOwnAddrType);
	if (rc != 0) { ESP_LOGE(KTAG, "ble_hs_id_infer_auto failed: %d", rc); return; }

	local_startAdvertising();
}

/*
 * \brief local_bleOnReset
 *
 * - Called when the BLE stack resets.
 *   Logs the reset reason for debugging
 *
 */
static	void	local_bleOnReset(int reason) {

	ESP_LOGE(KTAG, "BLE host reset, reason=%d", reason);
}

/*
 * \brief local_nimbleHostTask
 *
 * - Run the NimBLE host stack inside a FreeRTOS task
 *
 */
static void local_nimbleHostTask(void *param) {

	(void)param;

	nimble_port_run();
	nimble_port_freertos_deinit();
}

/*
 * \brief local_initUart
 *
 * - Initialise the UART peripheral with the configured
 *   parameters (baud rate, pins, buffer sizes)
 */
static void local_initUart(void) {
	const	uart_config_t	aUartConfig = {
				.baud_rate	= KUART_BAUDRATE,
				.data_bits	= UART_DATA_8_BITS,
				.parity		= UART_PARITY_DISABLE,
				.stop_bits	= UART_STOP_BITS_1,
				.flow_ctrl	= UART_HW_FLOWCTRL_DISABLE,
				.source_clk	= UART_SCLK_DEFAULT,
			};

	ESP_ERROR_CHECK(uart_driver_install(KUART_PORT, (KUART_BUF_SIZE * 2), (KUART_BUF_SIZE * 2), 0, NULL, 0));
	ESP_ERROR_CHECK(uart_param_config(KUART_PORT, &aUartConfig));
	ESP_ERROR_CHECK(uart_set_pin(KUART_PORT, KUART_TX_PIN, KUART_RX_PIN, KUART_RTS_PIN, KUART_CTS_PIN));
}
