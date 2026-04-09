# STM32 Bare-Metal Labs (F446RE)

A curated STM32F446RE bare-metal workspace with multiple learning projects, shared references, and reusable headers.  
Organized for frequent uploads so each experiment stays clean and easy to find.

## Why I built this

I wanted to move from simple GPIO/UART exercises into real sensor-style data flow.  
The goal was to understand ADC setup at register level and push readings to serial in a clean loop.

## Features

- Multiple project folders under `projects/`
- ADC continuous conversion + UART serial output demo
- SysTick delay + LED/UART timing demo
- Shared docs and chip headers in one place
- Clean workspace-style repository structure

## Tech stack

- C (embedded, bare metal)
- STM32F446RE (Nucleo target)
- STM32CubeIDE toolchain

## Project structure

- `projects/10_adc_continuous_conversion/` - ADC continuous conversion project
- `projects/11_systick_delay/` - SysTick delay demo project
- `docs/reference/` - datasheet, reference manuals, Cortex-M4 guide, chip headers

## How to run

1. Open STM32CubeIDE.
2. Import one project from `projects/` (for example `projects/11_systick_delay`).
3. Build the selected project in `Debug` or `Release`.
4. Flash to STM32F446RE board.
5. Use serial monitor at `115200` for UART-based demos.

## Screenshots

No screenshots added yet. I usually verify using a serial terminal output window.

## Future improvements

- Add moving-average filtering before print
- Add sampling interval control with timer trigger
- Add lightweight command parser over UART
- Add small ring buffer for non-blocking serial output

---

If you clone this and try it on your board, feel free to tweak pin/channel mapping and make it your own 🙂.
