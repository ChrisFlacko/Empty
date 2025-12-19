#include "main.h"
#include "../include/gpio_driver.h"
#include "../include/tim_driver.h"
#include "../include/flash_driver.h"

/*---------------------------------------------- Defines------------------------------------------------------------------------------*/
#define PLL_FREQUENCY_72MHZ    72U
/*------------------------------------------------------------------------------------------------------------------------------------*/


/*---------------------------------------------- Local Functions ---------------------------------------------------------------------*/
void SysTick_Setup(uint32_t ticks);
/*------------------------------------------------------------------------------------------------------------------------------------*/


/*---------------------------------------------- Interrupt Functions -----------------------------------------------------------------*/
void SysTick_Handler(void)
{
    //SysTick Interrupt Handler
    Driver_GPIO_ToggleLED();
}
/*------------------------------------------------------------------------------------------------------------------------------------*/

int main(void)
{
    /* Initialize system in priviledged mode */
    System_Init_Privileged();

    /* Initialize GPIO for LED and activate it*/
    Driver_GPIO_SetupLED();
    //Driver_GPIO_ActivateLED();
    
    while(1){}
    return 1;
}

void SysTick_Setup(uint32_t ticks)
{
    /* Configure SysTick to interrupt at the requested rate */
    STK_LOAD  = (ticks & 0xFFFFFFUL) - 1UL;  /* set reload register */
    STK_VAL   = 0UL;                         /* Load the SysTick Counter Value */
    STK_CTRL  = (1 << 2) | (1 << 1) | (1 << 0);  /* Enable SysTick IRQ and SysTick Timer */
}

/* This function initialites the system in priviledge mode */
void System_Init_Privileged(void)
{
    /* Configure the FLASH */
    Driver_Init_Flash(PLL_FREQUENCY_72MHZ);

    /* Initialize system clock */
    Driver_RCC_ClockSetup(PLLClock, PLL_FREQUENCY_72MHZ);

    /* Initialize Timer Base */
    Timer2_Init();
    Timer6_Init();

    /* Enable SysTick for 1s interrupts */
    SysTick_Setup(72000000);

    /* Configuration of the Watchdog */
    Driver_IWDG_Init(IWDG_Prescaler_8, 5000);
}

