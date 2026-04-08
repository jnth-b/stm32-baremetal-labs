#include "stm32f4xx.h"
#include "adc.h"

void pa1_adc_init(void)
{
    RCC->AHB1ENR |= (1U << 0);
    GPIOA->MODER |= (1U << 2) | (1U << 3);
    RCC->APB2ENR |= (1U << 8);
    ADC1->SQR3 = 1;
    ADC1->SQR1 = 0;
    ADC1->CR2 |= (1U << 0);
}

void start_conversion(void)
{
	ADC1->CR2 |= (1U << 1);
    ADC1->CR2 |= (1U << 30);
}

uint32_t adc_read(void)
{
    while(!(ADC1->SR & (1U << 1))) {}
    return ADC1->DR;
}
