#include "uart.h"

#define GPIOAEN  (1U << 0)
#define UART2EN  (1U << 17)

#define CR1_TE   (1U << 3)
#define CR1_RE   (1U << 2)
#define CR1_UE   (1U << 13)

#define SR_TXE   (1U << 7)
#define SR_RXNE  (1U << 5)

#define SYS_FREQ     16000000U
#define APB1_CLK     SYS_FREQ
#define UART_BAUDRATE 115200U

void uart2_rxtx_init(void)
{
    RCC->AHB1ENR |= GPIOAEN;
    RCC->APB1ENR |= UART2EN;

    GPIOA->MODER &= ~(3U << 4);
    GPIOA->MODER |=  (2U << 4);

    GPIOA->MODER &= ~(3U << 6);
    GPIOA->MODER |=  (2U << 6);

    GPIOA->AFR[0] &= ~(0xFU << 8);
    GPIOA->AFR[0] |=  (7U << 8);
    GPIOA->AFR[0] &= ~(0xFU << 12);
    GPIOA->AFR[0] |=  (7U << 12);

    GPIOA->OSPEEDR |= (3U << 4) | (3U << 6);
    GPIOA->PUPDR   &= ~(3U << 6);
    GPIOA->PUPDR   |=  (1U << 6);

    USART2->BRR = (APB1_CLK + (UART_BAUDRATE / 2U)) / UART_BAUDRATE;

    USART2->CR1 = (CR1_TE | CR1_RE | CR1_UE);
}

char uart2_read(void)
{
    while (!(USART2->SR & SR_RXNE));
    return (char)USART2->DR;
}

void uart2_write(char ch)
{
    /* Keep this blocking for now; simple and predictable during board bring-up. */
    while (!(USART2->SR & SR_TXE));
    USART2->DR = (uint8_t)ch;
}
