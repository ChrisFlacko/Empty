#include "stdint.h"

#define SRAM_START		0x20000000U
#define SRAM_SIZE		(64 * 1024)
#define SRAM_END		(SRAM_START + SRAM_SIZE)
#define STACK_START		SRAM_END

extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _la_data;

extern uint32_t _sbss;
extern uint32_t _ebss;

int main(void);

void Reset_Handler(void);
void NMI_Handler(void) 			__attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) 	__attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)         __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)      __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void WWDG_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));   
void EXTI0_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel1_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel3_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel4_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel5_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel6_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel7_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void ADC1_2_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void CAN1_TX_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void CAN1_RX0_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void CAN1_RX1_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void CAN1_SCE_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));       
void TIM1_TRG_COM_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void USART3_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void)    __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler(void)    __attribute__((weak, alias("Default_Handler")));
void USBWakeUp_IRQHandler(void)    __attribute__((weak, alias("Default_Handler")));
void TIM8_BRK_IRQHandler(void)     __attribute__((weak, alias("Default_Handler")));
void TIM8_UP_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void TIM8_TRG_COM_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler(void)      __attribute__((weak, alias("Default_Handler")));
void ADC3_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void FSMC_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void UART4_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void UART5_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler(void)    __attribute__((weak, alias("Default_Handler")));
void TIM7_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ADC4_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));



uint32_t vectors[] __attribute__((section(".isr_vector"))) =
{
    STACK_START,
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    (uint32_t)&MemManage_Handler,
    (uint32_t)&BusFault_Handler,
    (uint32_t)&UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t)&SVC_Handler,
    0,                    // Debug Monitor -> optional
    0,                    // Reserved
    (uint32_t)&PendSV_Handler,
    (uint32_t)&SysTick_Handler,
    (uint32_t)&WWDG_IRQHandler,      /* Window Watchdog Interrupt */
    (uint32_t)&PVD_IRQHandler,       /* PVD through EXTI Line detection Interrupt */
    (uint32_t)&TAMP_STAMP_IRQHandler,/* Tamper and TimeStamp interrupts through the EXTI line */
    (uint32_t)&RTC_WKUP_IRQHandler,    /* RTC Wakeup interrupt through the EXTI line */
    (uint32_t)&FLASH_IRQHandler,     /* FLASH global Interrupt */
    (uint32_t)&RCC_IRQHandler,       /* RCC global Interrupt */
    (uint32_t)&EXTI0_IRQHandler,     /* EXTI Line0 Interrupt */
    (uint32_t)&EXTI1_IRQHandler,     /* EXTI Line1 Interrupt */
    (uint32_t)&EXTI2_IRQHandler,     /* EXTI Line2 Interrupt */
    (uint32_t)&EXTI3_IRQHandler,     /* EXTI Line3 Interrupt */
    (uint32_t)&EXTI4_IRQHandler,     /* EXTI Line4 Interrupt */
    (uint32_t)&DMA1_Channel1_IRQHandler, /* DMA1 Channel 1 Interrupt */
    (uint32_t)&DMA1_Channel2_IRQHandler, /* DMA1 Channel 2 Interrupt */
    (uint32_t)&DMA1_Channel3_IRQHandler, /* DMA1 Channel 3 Interrupt */
    (uint32_t)&DMA1_Channel4_IRQHandler, /* DMA1 Channel 4 Interrupt */
    (uint32_t)&DMA1_Channel5_IRQHandler, /* DMA1 Channel 5 Interrupt */
    (uint32_t)&DMA1_Channel6_IRQHandler, /* DMA1 Channel 6 Interrupt */
    (uint32_t)&DMA1_Channel7_IRQHandler, /* DMA1 Channel 7 Interrupt */
    (uint32_t)&ADC1_2_IRQHandler,    /* ADC1 and ADC2 global Interrupts */
    (uint32_t)&CAN1_TX_IRQHandler,    /* CAN1 TX Interrupt */
    (uint32_t)&CAN1_RX0_IRQHandler,   /* CAN1 RX0 Interrupt */
    (uint32_t)&CAN1_RX1_IRQHandler,   /* CAN1 RX1 Interrupt */
    (uint32_t)&CAN1_SCE_IRQHandler,   /* CAN1 SCE Interrupt */
    (uint32_t)&EXTI9_5_IRQHandler,    /* EXTI Line[9:5] Interrupts */
    (uint32_t)&TIM1_BRK_IRQHandler,    /* TIM1 Break Interrupt */
    (uint32_t)&TIM1_UP_IRQHandler,    /* TIM1 Update Interrupt */
    (uint32_t)&TIM1_TRG_COM_IRQHandler, /* TIM1 Trigger and Commutation Interrupt */
    (uint32_t)&TIM1_CC_IRQHandler,    /* TIM1 Capture Compare Interrupt */
    (uint32_t)&TIM2_IRQHandler,       /* TIM2 global Interrupt */
    (uint32_t)&TIM3_IRQHandler,       /* TIM3 global Interrupt */
    (uint32_t)&TIM4_IRQHandler,       /* TIM4 global Interrupt */
    (uint32_t)&I2C1_EV_IRQHandler,    /* I2C1 Event Interrupt */
    (uint32_t)&I2C1_ER_IRQHandler,    /* I2C1 Error Interrupt */
    (uint32_t)&I2C2_EV_IRQHandler,    /* I2C2 Event Interrupt */
    (uint32_t)&I2C2_ER_IRQHandler,    /* I2C2 Error Interrupt */
    (uint32_t)&SPI1_IRQHandler,      /* SPI1 global Interrupt */
    (uint32_t)&SPI2_IRQHandler,       /* SPI2 global Interrupt */
    (uint32_t)&USART1_IRQHandler,     /* USART1 global Interrupt */
    (uint32_t)&USART2_IRQHandler,     /* USART2 global Interrupt */
    (uint32_t)&USART3_IRQHandler,     /* USART3 global Interrupt */
    (uint32_t)&EXTI15_10_IRQHandler,  /* EXTI Line[15:10] Interrupts */
    (uint32_t)&RTC_Alarm_IRQHandler,  /* RTC Alarm (A and B) through EXTI Line Interrupt */
    (uint32_t)&USBWakeUp_IRQHandler,   /* USB Wakeup from suspend through EXTI line Interrupt */
    (uint32_t)&TIM8_BRK_IRQHandler,    /* TIM8 Break Interrupt */
    (uint32_t)&TIM8_UP_IRQHandler,     /* TIM8 Update Interrupt */
    (uint32_t)&TIM8_TRG_COM_IRQHandler, /* TIM8 Trigger and Commutation Interrupt */
    (uint32_t)&TIM8_CC_IRQHandler,     /* TIM8 Capture Compare Interrupt */
    (uint32_t)&ADC3_IRQHandler,     /* ADC3 global Interrupt */
    (uint32_t)&FSMC_IRQHandler,    /* FSMC global Interrupt */
    (uint32_t)0U,                     /* Reserved */
    (uint32_t)0U,                     /* Reserved */
    (uint32_t)&SPI3_IRQHandler,     /* SPI3 global Interrupt */
    (uint32_t)&UART4_IRQHandler,    /* UART4 global Interrupt */
    (uint32_t)&UART5_IRQHandler,    /* UART5 global Interrupt */
    (uint32_t)&TIM6_DAC_IRQHandler, /* TIM6 and DAC global Interrupt */
    (uint32_t)&TIM7_IRQHandler,     /* TIM7 global Interrupt */
    (uint32_t)&DMA2_Channel1_IRQHandler, /* DMA2 Channel 1 Interrupt */
    (uint32_t)&DMA2_Channel2_IRQHandler, /* DMA2 Channel 2 Interrupt */
    (uint32_t)&DMA2_Channel3_IRQHandler, /* DMA2 Channel 3 Interrupt */
    (uint32_t)&DMA2_Channel4_IRQHandler, /* DMA2 Channel 4 */
    (uint32_t)&DMA2_Channel5_IRQHandler, /* DMA2 Channel 5 Interrupt */
    (uint32_t)&ADC4_IRQHandler    /* ADC4 global Interrupt */
};



void Reset_Handler(void)
{
	uint32_t* src, *dest;
	// Copy .data to SRAM
	src = &_la_data;
	dest = &_sdata;

	while (dest < &_edata)
	{
		*dest++ = *src++;
	}
	// Init the .bss section to zero in SRAM
    dest = &_sbss;

    while (dest < &_ebss)
    {
        *dest++ = 0;
    }

	// call main()
    main();
}

void Default_Handler(void)
{

}
