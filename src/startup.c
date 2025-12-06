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
void SysTick_Handler(void)     __attribute__((weak, alias("Default_Handler")));


uint32_t vectors[] __attribute__((section(".isr_vector"))) =
{
		STACK_START,
		(uint32_t)&Reset_Handler,
		(uint32_t)&NMI_Handler,
		(uint32_t)&HardFault_Handler,
		(uint32_t)&MemManage_Handler,
		(uint32_t)&BusFault_Handler,
		(uint32_t)&UsageFault_Handler,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)0U,
		(uint32_t)&SVC_Handler,
		(uint32_t)&PendSV_Handler,
		(uint32_t)&SysTick_Handler
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
