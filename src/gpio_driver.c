#include "../include/gpio_driver.h"

void Driver_GPIO_SetupPin(void)
{
    GPIOA->MODER |= GPIO_MODER_SET(5, 1);
    GPIOA->OSPEEDR |= GPIO_OPSPEED_SET(5,1);
    GPIOA->BSRR = GPIO_BSSR_SET(5,1);
}

