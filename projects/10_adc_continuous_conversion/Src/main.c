#include "stdio.h"
#include "uart.h"
#include "stdint.h"
#include "stm32f4xx.h"
#include "adc.h"

uint32_t sensor_value;

int main(void)
{
    uart2_rxtx_init();
    pa1_adc_init();
    start_conversion();
    while(1)
    {
        sensor_value = adc_read();
        printf("sensor value : %ld\r\n", sensor_value);
    }
}
