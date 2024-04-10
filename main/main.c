#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <driver/gpio.h>
#include <driver/uart.h>
#include <esp_rrm.h>
#include <string.h>


#define GPIO_LED            2
#define DELAY_MS            1000
#define BAUD_RATE           115200
#define UART                UART_NUM_2
#define BUFFER_LEN          30
#define MSG                 "[UART2]Counter: %d\n"




// Estructura de configuracion: 

uart_config_t uart_config = {
    .baud_rate = BAUD_RATE,
    .data_bits = UART_DATA_8_BITS,
    .parity = UART_PARITY_DISABLE,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
};



// Buffer usado para enviar mensajes por UART2
char buffer_msg[BUFFER_LEN] = {0};


// Valor del led
bool level = true;






void app_main(void)
{
    printf("Inicio el programa \n");
   
    // Configuracion de perifericos: gpio
    // Configuro el gpio  GPIO_LED como salida (output)
    gpio_set_direction(GPIO_LED,GPIO_MODE_OUTPUT);

    //Configuracion del puerto serie:
    ESP_ERROR_CHECK(uart_param_config(UART,&uart_config));

    //Asignacion de pines TX:18 y RX:19
    ESP_ERROR_CHECK(uart_set_pin(UART,18,19,UART_PIN_NO_CHANGE,UART_PIN_NO_CHANGE));

    //Instalar driver
    const int uart_buffer = (1024 * 2);
    int counter = 0;
    uart_driver_install(UART,uart_buffer,uart_buffer,10,NULL,0);
    
    //Cuando led_status es 0 se apaga el led, caso contrario se enciende.    
    gpio_set_level(GPIO_LED,level);

    while(1){
    level = ! level;
    gpio_set_level(GPIO_LED,level)    ;   
    // Funcion de darle formato a un string    
    sprintf(buffer_msg,MSG,counter);
    uart_write_bytes(UART,buffer_msg,strlen(buffer_msg));
    vTaskDelay(DELAY_MS/ portTICK_PERIOD_MS);
    counter++;
    }   
}
