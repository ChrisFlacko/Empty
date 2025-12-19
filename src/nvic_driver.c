#include "../include/nvic_driver.h"

void configureNVIC(NVIC_ModuleIRQn module, uint8_t priority)
{
    uint32_t iser_index = module / 32;
    uint32_t iser_bit = module % 32;
    switch (iser_index)
    {
        case 0:
        NVIC_ISER0 |= (1U << iser_bit);
            break;
        case 1:
            NVIC_ISER1 |= (1U << iser_bit);
            break;
        case 2:
            NVIC_ISER2 |= (1U << iser_bit);
            break;
        case 3:
            NVIC_ISER3 |= (1U << iser_bit);
            break;
        case 4:
            NVIC_ISER4 |= (1U << iser_bit);
            break;
        case 5:
            NVIC_ISER5 |= (1U << iser_bit);
            break;
        case 6:
            NVIC_ISER6 |= (1U << iser_bit);
            break;
        case 7:
            NVIC_ISER7 |= (1U << iser_bit);
            break;
        default:
            return; // Invalid IRQn
    }
}