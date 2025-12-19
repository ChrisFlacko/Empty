#include "../include/flash_driver.h"


void Driver_Init_Flash(uint8_t frequency)
{
    /* Configure flash latency and prefetch */
    uint8_t temp = (frequency-1)/24;
    FLASH->ACR &= ~FLASH_ACR_LATENCY;               // Clear latency bits
    FLASH->ACR |= FLASH_ACR_LATENCY_EN(temp);       // Set latency
    FLASH->ACR |= FLASH_ACR_PRFTBE_SET;             // Enable prefetch buffer
}