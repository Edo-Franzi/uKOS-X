/*
; wifi_to_uart_client.
; ====================

; SPDX-License-Identifier: MIT

;------------------------------------------------------------------------
; Author:	Edo. Franzi		The 2026-04-27
; Modifs:
;
; Project:	uKOS-X
; Goal:     Bridge between uart1 and Wi-Fi TCP socket (transparent mode).
;			This firmware connect the board to an existing network.
;			It is necessary to provide KWIFI_SSID and KWIFI_PASSWORD.
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
#include	<errno.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>
#include	<unistd.h>

#include	"freertos/FreeRTOS.h"
#include	"freertos/task.h"
#include	"freertos/semphr.h"
#include	"freertos/event_groups.h"

#include	"driver/uart.h"
#include	"driver/gpio.h"

#include	"esp_log.h"
#include	"esp_err.h"
#include	"esp_wifi.h"
#include	"esp_event.h"
#include	"esp_netif.h"
#include	"nvs_flash.h"

#undef	KUART_0
#undef	KWITHOUT_LOGS
#define	KTAG					"WIFI_UART"

// Wi-Fi Station configuration

#define	KWIFI_SSID				"La Taverne du Diable"
#define	KWIFI_PASSWORD			"xxxxxxxxx"
#define	KWIFI_MAXIMUM_RETRY		10u

#define	KWIFI_CONNECTED_BIT		BIT0
#define	KWIFI_FAIL_BIT			BIT1

// TCP server configuration

#define	KTCP_PORT				3333u
#define	KTCP_BACKLOG			1u

// UART used by the bridge

#define	KUART_BAUDRATE			460800u
#define	KUART_BUF_SIZE			1024u
#define	KUART_RTS_PIN			UART_PIN_NO_CHANGE
#define	KUART_CTS_PIN			UART_PIN_NO_CHANGE

#if (defined(KUART_0))
#define	KUART_PORT				UART_NUM_0
#define	KUART_TX_PIN			1u
#define	KUART_RX_PIN			3u

#else
#define	KUART_PORT				UART_NUM_1
#define	KUART_TX_PIN			17u
#define	KUART_RX_PIN			16u
#endif

static	int						vListenSock			= -1;
static	int						vClientSock			= -1;
static	int						vWifiRetryCount		= 0;
static	SemaphoreHandle_t		vSocketMutex		= NULL;
static	EventGroupHandle_t		vWifiEventGroup		= NULL;

// Prototypes

static	void	local_initUart(void);
static	void	local_initWifiSta(void);
static	void	local_wifiEventHandler(void *arg, esp_event_base_t eventBase, int32_t eventId, void *eventData);
static	void	local_tcpServerTask(void *arg);
static	void	local_uartToWifiTask(void *arg);
static	void	local_closeClient(void);
static	void	local_setClientSock(int sock);
static	int		local_getClientSock(void);

/*
 * \brief app_main
 *
 * - Main application entry point.
 *   Initialise NVS
 *   configure UART
 *   connect Wi-Fi station to an existing network
 *   start TCP server
 *   start UART-to-Wi-Fi bridge task
 *
 */
void	app_main(void) {
	esp_err_t	ret;
	BaseType_t	taskCreated;

	#if (defined(KWITHOUT_LOGS))
	esp_log_level_set("*", ESP_LOG_NONE);

	#else
	esp_log_level_set("*", ESP_LOG_INFO);
	esp_log_level_set(KTAG, ESP_LOG_INFO);
	#endif

	ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);

	vSocketMutex = xSemaphoreCreateMutex();
	if (vSocketMutex == NULL) {
		ESP_LOGE(KTAG, "Failed to create socket mutex");
		return;
	}

	local_initUart();
	local_initWifiSta();

	taskCreated = xTaskCreate(local_tcpServerTask, "tcp_server", 4096, NULL, 5, NULL);
	if (taskCreated != pdPASS) { ESP_LOGE(KTAG, "Failed to create tcp_server task");   }

	taskCreated = xTaskCreate(local_uartToWifiTask, "uart_to_wifi", 4096, NULL, 5, NULL);
	if (taskCreated != pdPASS) { ESP_LOGE(KTAG, "Failed to create uart_to_wifi task"); }

	ESP_LOGI(KTAG, "Wi-Fi UART bridge started");
}

// Local routines
// ==============

/*
 * \brief local_wifiEventHandler
 *
 * - Wi-Fi and IP event handler.
 *   Start connection when station mode starts.
 *   Retry connection on disconnection.
 *   Signal connection status when IP address is obtained.
 *
 */
static	void	local_wifiEventHandler(void *arg, esp_event_base_t eventBase, int32_t eventId, void *eventData) {
	ip_event_got_ip_t	*event;

	(void)arg;

	if ((eventBase == WIFI_EVENT) && (eventId == WIFI_EVENT_STA_START)) {
		esp_wifi_connect();
	}

	else if ((eventBase == WIFI_EVENT) && (eventId == WIFI_EVENT_STA_DISCONNECTED)) {
		if (vWifiRetryCount < KWIFI_MAXIMUM_RETRY) {
			esp_wifi_connect();
			vWifiRetryCount++;
			ESP_LOGW(KTAG, "Retrying Wi-Fi connection");
		}
		else {
			xEventGroupSetBits(vWifiEventGroup, KWIFI_FAIL_BIT);
		}
	}

	else if ((eventBase == IP_EVENT) && (eventId == IP_EVENT_STA_GOT_IP)) {
		event = (ip_event_got_ip_t *)eventData;

		ESP_LOGI(KTAG, "Wi-Fi connected, IP=" IPSTR, IP2STR(&event->ip_info.ip));

		vWifiRetryCount = 0;
		xEventGroupSetBits(vWifiEventGroup, KWIFI_CONNECTED_BIT);
	}
}

/*
 * \brief local_initWifiSta
 *
 * - Initialise the ESP32 as Wi-Fi station.
 *   The ESP32 connects to an existing Wi-Fi network.
 *   The TCP server listens on the IP address assigned by DHCP.
 *
 */
static	void	local_initWifiSta(void) {
			wifi_init_config_t	cfg = WIFI_INIT_CONFIG_DEFAULT();
			EventBits_t			bits;
	static	wifi_config_t		wifiConfig = {
									.sta = {
										.ssid				= KWIFI_SSID,
										.password			= KWIFI_PASSWORD,
										.threshold.authmode	= WIFI_AUTH_WPA2_PSK,
									},
								};

	vWifiEventGroup = xEventGroupCreate();
	if (vWifiEventGroup == NULL) {
		ESP_LOGE(KTAG, "Failed to create Wi-Fi event group");
		return;
	}

	ESP_ERROR_CHECK(esp_netif_init());
	ESP_ERROR_CHECK(esp_event_loop_create_default());

	esp_netif_create_default_wifi_sta();

	ESP_ERROR_CHECK(esp_wifi_init(&cfg));

	ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &local_wifiEventHandler, NULL, NULL));
	ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,   IP_EVENT_STA_GOT_IP, &local_wifiEventHandler, NULL, NULL));

	ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
	ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifiConfig));
	ESP_ERROR_CHECK(esp_wifi_start());

	ESP_LOGI(KTAG, "Connecting to Wi-Fi SSID=%s", KWIFI_SSID);

	bits = xEventGroupWaitBits(vWifiEventGroup, KWIFI_CONNECTED_BIT | KWIFI_FAIL_BIT, pdFALSE, pdFALSE, portMAX_DELAY);

	if (bits & KWIFI_CONNECTED_BIT) {
		ESP_LOGI(KTAG, "Connected to Wi-Fi network");
	}
	else if (bits & KWIFI_FAIL_BIT) {
		ESP_LOGE(KTAG, "Failed to connect to Wi-Fi network");
	}
}

/*
 * \brief local_tcpServerTask
 *
 * - TCP server task.
 *   Accepts one client at a time.
 *   Data received from Wi-Fi is forwarded to UART.
 *
 */
static	void	local_tcpServerTask(void *arg) {
			int				opt = 1;
			int				clientSock;
			int				len;
			uint8_t			buffer[KUART_BUF_SIZE];
	struct	sockaddr_in		serverAddr;
	struct	sockaddr_in		clientAddr;
			socklen_t		clientAddrLen = sizeof(clientAddr);

	(void)arg;

	vListenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
	if (vListenSock < 0) {
		ESP_LOGE(KTAG, "Unable to create socket: errno=%d", errno);
		vTaskDelete(NULL);
		return;
	}

	setsockopt(vListenSock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family      = AF_INET;
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddr.sin_port        = htons(KTCP_PORT);

	if (bind(vListenSock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
		ESP_LOGE(KTAG, "Socket bind failed: errno=%d", errno);
		close(vListenSock);
		vTaskDelete(NULL);
		return;
	}

	if (listen(vListenSock, KTCP_BACKLOG) < 0) {
		ESP_LOGE(KTAG, "Socket listen failed: errno=%d", errno);
		close(vListenSock);
		vTaskDelete(NULL);
		return;
	}

	ESP_LOGI(KTAG, "TCP server listening on port %d", KTCP_PORT);

	while (true) {
		clientAddrLen = sizeof(clientAddr);
		clientSock = accept(vListenSock, (struct sockaddr *)&clientAddr, &clientAddrLen);
		if (clientSock < 0) {
			ESP_LOGW(KTAG, "Unable to accept connection: errno=%d", errno);
			continue;
		}

		ESP_LOGI(KTAG, "TCP client connected: %s", inet_ntoa(clientAddr.sin_addr));

		local_closeClient();
		local_setClientSock(clientSock);

		while (true) {
			len = recv(clientSock, buffer, sizeof(buffer), 0);
			if (len > 0) {
				uart_write_bytes(KUART_PORT, (const char *)buffer, len);
			}
			else if (len == 0) { ESP_LOGI(KTAG, "TCP client disconnected");		 break; }
			else			   { ESP_LOGW(KTAG, "recv failed: errno=%d", errno); break; }
		}
		local_closeClient();
	}
}

/*
 * \brief local_uartToWifiTask
 *
 * - FreeRTOS task that continuously reads data from UART and
 *   forwards it to the connected TCP client.
 *
 */
static	void	local_uartToWifiTask(void *arg) {
	int			len;
	int			sock;
	int			sent;
	int			offset;
	uint8_t		buffer[KUART_BUF_SIZE];

	(void)arg;

	while (true) {
		len = uart_read_bytes(KUART_PORT, buffer, sizeof(buffer), pdMS_TO_TICKS(20));
		if (len > 0) {
			sock = local_getClientSock();
			if (sock >= 0) {
				offset = 0;

				while (offset < len) {
					sent = send(sock, buffer + offset, len - offset, 0);
					if (sent < 0) {
						ESP_LOGW(KTAG, "send failed: errno=%d", errno);
						local_closeClient();
						break;
					}
					offset += sent;
				}
			}
		}
	}
}

/*
 * \brief local_closeClient
 *
 * - Close the current TCP client socket.
 *
 */
static	void	local_closeClient(void) {
	int		sock;

	xSemaphoreTake(vSocketMutex, portMAX_DELAY);
	sock = vClientSock;
	vClientSock = -1;
	xSemaphoreGive(vSocketMutex);

	if (sock >= 0) {
		shutdown(sock, 0);
		close(sock);
	}
}

/*
 * \brief local_getClientSock
 *
 * - Return the current TCP client socket.
 *
 */
static	int	local_getClientSock(void) {
	int		sock;

	xSemaphoreTake(vSocketMutex, portMAX_DELAY);
	sock = vClientSock;
	xSemaphoreGive(vSocketMutex);
	return (sock);
}

/*
 * \brief local_setClientSock
 *
 * - Set the current TCP client socket.
 *
 */
static	void	local_setClientSock(int sock) {

	xSemaphoreTake(vSocketMutex, portMAX_DELAY);
	vClientSock = sock;
	xSemaphoreGive(vSocketMutex);
}

/*
 * \brief local_initUart
 *
 * - Initialise the UART peripheral with the configured
 *   parameters (baud rate, pins, buffer sizes).
 *
 */
static	void	local_initUart(void) {
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
