#include "../include/rcc_driver.h"

void Driver_RCC_ClockSetup()
{
    /* Enable HSI Clock */
    RCC->CR |= RCC_CR_HSION_EN;
    while( (RCC->CR & RCC_CR_HSIRDY_Msk) != RCC_CR_HSIRDY_Msk)
    {
        ; //Wait till clock is ready
    }
}