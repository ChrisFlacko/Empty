#include "main.h"
#include "../include/gpio_driver.h"

/*---------------------------------------------- Local Functions ---------------------------------------------------------------------*/
static void Clock_Setup(void);
/*------------------------------------------------------------------------------------------------------------------------------------*/



int main(void)
{
    /* Initialize system clock and LED */
    Clock_Setup();
    while(1)
    {
    }
    return 1;
}

static void Clock_Setup(void)
{
    /* Enable the HSI clock */
    Driver_RCC_ClockSetup();
    RCC_ENABLE_GPIOA();
    Driver_GPIO_SetupPin();
}