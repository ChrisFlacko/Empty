#include "../include/gpio_driver.h"
#include "../include/rcc_driver.h"

void Driver_GPIO_SetupPin(GPIO_Port_TypeDef port, uint8_t pin, GPIO_Mode_TypeDef mode)
{
    if(port == GPIO_A)
    {
        GPIOA->MODER &= GPIO_MODER_RESET(pin);
        GPIOA->MODER |= GPIO_MODER_SET(pin, mode);
        GPIOA->OSPEEDR |= GPIO_OPSPEED_SET(pin,1);
    }
    else if(port == GPIO_B)
    {
        GPIOB->MODER &= GPIO_MODER_RESET(pin);
        GPIOB->MODER |= GPIO_MODER_SET(pin, mode);
        GPIOB->OSPEEDR |= GPIO_OPSPEED_SET(pin,1);
    }
    // Add more ports as needed
}

void Driver_GPIO_SetupLED(void)
{
    // Enable the clock for GPIOA
    RCC_ENABLE_GPIOA();

    // Setup the GPIO pin for the LED
    Driver_GPIO_SetupPin(GPIO_A, 5, GPIO_MODE_OUTPUT);
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

void Driver_GPIO_HumiditySensorSetup(void)
{
    // Enable clock for GPIOB
    RCC_ENABLE_GPIOB();

    // Setup Pin PB6 as input for Humidity Sensor
}
