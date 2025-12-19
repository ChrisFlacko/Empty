#include "memorymap.h"
#include "peripherals.h"
#include "typedefs.h"

typedef enum NVIC_ModuleIRQn
{
    TIM6_DAC_IRQn = 54

}NVIC_ModuleIRQn;


void configureNVIC(NVIC_ModuleIRQn module, uint8_t priority);