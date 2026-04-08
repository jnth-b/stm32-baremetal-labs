#include "stdio.h"
#include "uart.h"
#include "stdint.h"
#include "stm32f4xx.h"

int main(void)
{
    uart2_rxtx_init();
    while(1)
    {
        printf("uart ready...\r\n");
        for (volatile uint32_t i = 0; i < 800000; i++) {}
    }
}
