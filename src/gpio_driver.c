#include "../include/gpio_driver.h"
#include "../include/rcc_driver.h"

void Driver_GPIO_SetupPin(void)
{
    GPIOA->MODER &= GPIO_MODER_RESET(5);
    GPIOA->MODER |= GPIO_MODER_SET(5, 1);
    GPIOA->OSPEEDR |= GPIO_OPSPEED_SET(5,1);
}

void Driver_GPIO_SetupLED(void)
{
    // Enable the clock for GPIOA
    RCC_ENABLE_GPIOA();

    // Setup the GPIO pin for the LED
    Driver_GPIO_SetupPin();
}

void Driver_GPIO_ActivateLED(void)
{
    // Set the GPIO pin high to turn on the LED
    GPIOA->BSRR = GPIO_BSSR_SET(5, 1);
}

void Driver_GPIO_ToggleLED(void)
{
    // Toggle the GPIO pin to blink the LED
    GPIOA->ODR ^= (1 << 5);
}
