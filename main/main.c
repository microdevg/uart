#include <stdio.h>

#include "esp_err.h"
#include "freertos/FreeRTOS.h"      // Necesario para configurar los delay. Recordemos que estamos en un entorno Freertos
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "string.h"


#define UART_BAUDRATE          (115200)
#define NOT_USED               (0)
#define BUFFER_TX              (1024)
#define BUFFER_RX              (1024)

#define QUEUE_SIZE             (10)
#define QUEUE_USED             (NULL)

#define TEST_MESSAGE        "test message"



const int uart_num = UART_NUM_2;


uart_config_t uart_config = {
    .baud_rate = UART_BAUDRATE,
    .data_bits = UART_DATA_8_BITS,
    .parity = UART_PARITY_DISABLE,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
};



void app_main(void)
{

    ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));
    // Seleccione los pines a utilizar 
    // TX:17, RX:16 Default
    ESP_ERROR_CHECK(uart_set_pin(uart_num, 17, 16, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE));


    uart_driver_install(uart_num, BUFFER_RX,BUFFER_TX,QUEUE_SIZE , QUEUE_USED, 0);
    uint32_t counter = 0;
    char buffer_msg[30];

    while(1) {
        sprintf(buffer_msg,"UART2: Counter: %ld \r\n",counter);
        uart_write_bytes(uart_num,buffer_msg,strlen(buffer_msg));
        vTaskDelay(1000/portTICK_PERIOD_MS);
        counter ++;
    }

}