#include "stm32f4xx.h"
#include "adc.h"

#define GPIOAEN      (1U << 0)
#define ADC1EN       (1U << 8)
#define ADC_CH1      1U
#define ADC_CONT     (1U << 1)
#define ADC_ADON     (1U << 0)
#define ADC_SWSTART  (1U << 30)
#define ADC_EOC      (1U << 1)

void pa1_adc_init(void)
{
    RCC->AHB1ENR |= GPIOAEN;
    GPIOA->MODER |= (1U << 2) | (1U << 3);
    RCC->APB2ENR |= ADC1EN;
    ADC1->SQR3 = ADC_CH1;
    ADC1->SQR1 = 0;
    ADC1->CR2 |= ADC_ADON;
}

void start_conversion(void)
{
    ADC1->CR2 |= ADC_CONT;
    ADC1->CR2 |= ADC_SWSTART;
}

uint32_t adc_read(void)
{
    while (!(ADC1->SR & ADC_EOC)) {}
    return ADC1->DR;
}
