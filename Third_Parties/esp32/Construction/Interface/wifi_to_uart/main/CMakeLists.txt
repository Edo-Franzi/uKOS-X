idf_component_register(
    SRCS
        "wifi_to_uart.c"

    INCLUDE_DIRS
        "."

    REQUIRES
        driver
        esp_wifi
        esp_netif
        esp_event
        nvs_flash
)
