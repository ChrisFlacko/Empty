# Empty
This project focus on creating a embedded environment (necessary files, drivers, RTOS and other stuff) for self learning purposes.

# RCC - Register
3 clocks are available: 
  HSI = 8 MHz
  HSE
  PLL = 16 - 72 MHz
  LSI = 40 kHz (between 30 and 50 kHz)

HSI can be used as PLL input with a prescaler of 2 (divide by 2)

Buses:
  AHB (max 72 MHz)
  APB1 (max 36 MHz)
  APB2 (max 72 MHz)


