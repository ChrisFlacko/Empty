#include "../include/rcc_driver.h"

void Driver_RCC_ClockSetup(SysClock_e sysclock, uint32_t pllFreq)
{
    switch(sysclock)
    {
        case HSIClock:
        /* Enable HSI Clock */
        RCC->CR |= RCC_CR_HSION_EN;
        while( (RCC->CR & RCC_CR_HSIRDY_Msk) != RCC_CR_HSIRDY_Msk)
        {
            ; //Wait till clock is ready
        }
        break;

        case HSEClock:
        break;

        case PLLClock:
        uint32_t pllMulFactor = ((pllFreq / 8U) - 2U);
        
        /* Setup PLL clock */
        RCC->CFGR |= RCC_CFGR_SW_EN(2U); //Select PLL as system clock
        RCC->CFGR |= RCC_CFGR_HPRE_EN(0U); //AHB prescaler = 1
        RCC->CFGR |= RCC_CFGR_PPRE1_EN(4U); //APB1 prescaler = 2
        RCC->CFGR |= RCC_CFGR_PPRE2_EN(0U); //APB2 prescaler = 1
        RCC->CFGR |= RCC_CFGR_PLLSRC_EN(0U); //HSI as PLL source
        RCC->CFGR |= RCC_CFGR_PLLMUL_EN(pllMulFactor); //PLL multiplication factor = 9 (8MHz * 9 = 72MHz)
        RCC->CR |= RCC_CR_PLLON_EN; //Enable PLL
        while( (RCC->CR & RCC_CR_PLLRDY_Msk) != RCC_CR_PLLRDY_Msk)
        {
            ; //Wait till PLL is ready
        }
        
        break;

        default:
        break;
    }

}