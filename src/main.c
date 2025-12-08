#include "main.h"
#include "../include/gpio_driver.h"

/*---------------------------------------------- Local Functions ---------------------------------------------------------------------*/
static void Clock_Setup(void);
/*------------------------------------------------------------------------------------------------------------------------------------*/



int main(void)
{
    /* Initialize system clock */
    Clock_Setup();

    /* Initialize GPIO for LED and activate it*/
    Driver_GPIO_SetupLED();
    Driver_GPIO_ActivateLED();

    while(1){}
    return 1;
}

static void Clock_Setup(void)
{
    /* Enable the HSI clock */
    Driver_RCC_ClockSetup();
}
