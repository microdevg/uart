# Control de led mediante señal PWM usando hardware (LEDC)


Este proyecto esta basado en la documentacion del espressif para el manejo del periferico UART[docs page](https://docs.espressif.com/projects/esp-idf/en/v4.2.3/esp32/api-reference/peripherals/uart.html#_CPPv419uart_driver_install11uart_port_tiiiP13QueueHandle_ti)

### Introduccion 
Descripción general
Un receptor/transmisor asíncrono universal (UART) es una característica de hardware que maneja la comunicación (es decir, requisitos de sincronización y entramado de datos) utilizando interfaces de comunicación en serie asíncronas ampliamente adaptadas, como RS232, RS422, RS485. Un UART proporciona un método económico y ampliamente adoptado para realizar el intercambio de datos full-duplex o half-duplex entre diferentes dispositivos.

El chip ESP32 tiene tres controladores UART (UART0, UART1 y UART2) que cuentan con un conjunto idéntico de registros para facilitar la programación y la flexibilidad.

Cada controlador UART se puede configurar de forma independiente con parámetros como velocidad en baudios, longitud de bits de datos, orden de bits, número de bits de parada, bits de paridad, etc. Todos los controladores son compatibles con dispositivos habilitados para UART de varios fabricantes y también pueden admitir protocolos de asociación de datos infrarrojos. (IrDA).


### Pasos a seguir
En este ejemplo simple vamos a enviar el mensaje de un contador por los pines 17(tx) 16(rx) del UART2. Para ello debemos realizar una seria de pasos:
- Configurar el hardware.
- Configurar los pines para manejar UART2.
- Configurar driver.


## Imagenes

### Monitor CUTECOM
<img src="imgs/cutecom.png" width="400" />


### Circuito
<img src="imgs/circuito.png" width="400" />


## Requisitos

Para ejecutar estos ejemplos, necesitarás un entorno de desarrollo configurado para la programación de la ESP32, que puede incluir:

- Placa de desarrollo ESP32.
- SDK de Espressif (IDF-ESP32).