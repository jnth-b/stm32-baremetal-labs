# STM32 ADC Continuous Conversion (Bare Metal)

A small STM32F446RE bare-metal project that reads ADC values on `PA1` and streams them over UART2.  
Built as part of my driver-learning series while keeping things modular and easy to extend.

## Why I built this

I wanted to move from simple GPIO/UART exercises into real sensor-style data flow.  
The goal was to understand ADC setup at register level and push readings to serial in a clean loop.

## Features

- Bare-metal ADC1 setup on `PA1` (no HAL)
- Continuous conversion flow for repeated sampling
- UART2 TX/RX driver on `PA2`/`PA3`
- Modular source layout (`Src/` + `Inc/`)
- `printf` output redirected through UART for quick serial monitoring

## Tech stack

- C (embedded, bare metal)
- STM32F446RE (Nucleo target)
- STM32CubeIDE toolchain

## Project structure

- `Src/main.c` - application loop and serial print
- `Src/adc.c` - ADC init, trigger, read helpers
- `Src/uart.c` - UART2 init/read/write
- `Inc/adc.h`, `Inc/uart.h` - interfaces
- `projects/11_systick_delay` - separate SysTick delay demo project
- `common-files/` - shared references (datasheet, manuals, chip headers)

## How to run

1. Open STM32CubeIDE.
2. Import this folder as an existing STM32 project.
3. Build in `Debug` or `Release`.
4. Flash to STM32F446RE board.
5. Open serial monitor at `115200` baud and watch ADC readings.

## Screenshots

No screenshots added yet. I usually verify using a serial terminal output window.

## Future improvements

- Add moving-average filtering before print
- Add sampling interval control with timer trigger
- Add lightweight command parser over UART
- Add small ring buffer for non-blocking serial output

---

If you clone this and try it on your board, feel free to tweak pin/channel mapping and make it your own 🙂.
