#include "../include/tim_driver.h"
#include "../include/rcc_driver.h"
#include "../include/nvic_driver.h"

void Timer6_Init(void)
{
    /* Enable Clock for Timer 6 */
    RCC_ENABLE_TIM6();

    /* Configure Timer 6 */
    TIM6->CR1 &= ~BASIC_TIM_CR1_CEN_EN;          /* Disable Timer */
    TIM6->PSC = BASIC_TIM_PSC_SET(359);          /* Set Prescaler so there is a 10µs Tick */
    TIM6->ARR = 999U;                            /* Set Auto-Reload Value , so the timer overflows at 10ms */
    TIM6->CR1 |= BASIC_TIM_CR1_ARPE_EN;          /* Enable Auto-Reload Preload */
    TIM6->CR1 &= ~BASIC_TIM_CR1_OPM_EN;          /* Set Timer to Continuous Mode */
    TIM6->DIER |= BASIC_TIM_DIER_UIE_EN;         /* Enable Update Interrupt */
    TIM6->EGR |= BASIC_TIM_EGR_UG_EN;            /* Generate an Update Event to load the Prescaler value immediately */
    TIM6->SR &= ~BASIC_TIM_SR_UIF_EN;            /* Clear Update Interrupt Flag */
    configureNVIC(TIM6_DAC_IRQn, 4);             /* Configure NVIC for TIM6 Interrupts */
    TIM6->CR1 |= BASIC_TIM_CR1_CEN_EN;           /* Enable Timer */
}

void Timer2_Init(void)
{
    /* Enable clock for Timer 2 */
    RCC_ENABLE_TIM2();

    /* Configure Timer 2 */
    TIM2->CR1 &= ~BASIC_TIM_CR1_CEN_EN;          /* Disable Timer */
    TIM2->PSC = BASIC_TIM_PSC_SET(35);           /* Set Prescaler so there is a 1µs Tick */
    TIM2->ARR = 0xFFFFFFFFU;                     /* Set Auto-Reload Value to the max value possible */
    TIM2->CR1 &= ~BASIC_TIM_CR1_OPM_EN;          /* Set Timer to Continuous Mode */
    TIM2->DIER &= ~BASIC_TIM_DIER_UIE_EN;         /* Disable Update Interrupt */
    TIM2->EGR |= BASIC_TIM_EGR_UG_EN;            /* Generate an Update Event to load the Prescaler value immediately */
    TIM2->SR &= ~BASIC_TIM_SR_UIF_EN;            /* Clear Update Interrupt Flag */
    TIM2->CR1 |= BASIC_TIM_CR1_CEN_EN;           /* Enable Timer */
}

// Reload 5000 with prescaler 8 gives a 1s timeout with a 40kHz clock
void Driver_IWDG_Init(IWDG_Prescaler_TypeDef prescaler, uint16_t reload)
{
    /* Enable the write access to the IWDG */
    IWDG->KR = IWDG_KR_UNLOCK_EN;               /* Unlock the IWDG */
    IWDG->PR = prescaler;                     /* Set the Prescaler */
    IWDG->RLR = reload;                        /* Set the Reload value */
    IWDG->KR = IWDG_KR_RELOAD_EN;               /* Reload the IWDG counter */
    IWDG->KR = IWDG_KR_START_EN;                /* Start the IWDG */
}