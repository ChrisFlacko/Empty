/*
 * hal_memorymap.h
 *
 *  Created on: Jun 10, 2025
 *      Author: chris
 *
 *  Description:
 *		This file contains all the necessary addresses of the Nucleo-F303RE evaluation board.
 */

#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_
#include <stdint.h>

#define __IO					volatile

/* Bus addresses */
#define APB1_BASE_ADDR			0x40000000UL
#define APB2_BASE_ADDR			0x40010000UL
#define AHB1_BASE_ADDR			0x40020000UL
#define AHB2_BASE_ADDR			0x48000000UL
#define AHB3_BASE_ADDR			0x50000000UL
#define AHB4_BASE_ADDR			0x60000000UL

/* APB1 bus modules */
#define TIM2_BASE_ADDR			(APB1_BASE_ADDR + 0x00000000)
#define TIM3_BASE_ADDR			(APB1_BASE_ADDR + 0x00000400)
#define TIM6_BASE_ADDR			(APB1_BASE_ADDR + 0x00001000)
#define TIM7_BASE_ADDR			(APB1_BASE_ADDR + 0x00001400)
#define RTC_BASE_ADDR			(APB1_BASE_ADDR + 0x00002800)
#define WWDG_BASE_ADDR			(APB1_BASE_ADDR + 0x00002800)
#define IWDG_BASE_ADDR			(APB1_BASE_ADDR + 0x00003000)
#define USART2_BASE_ADDR		(APB1_BASE_ADDR + 0x00004400)
#define USART3_BASE_ADDR		(APB1_BASE_ADDR + 0x00004800)
#define I2C1_BASE_ADDR			(APB1_BASE_ADDR + 0x00005400)
#define BXCAN_BASE_ADDR			(APB1_BASE_ADDR + 0x00006400)
#define PWR_BASE_ADDR			(APB1_BASE_ADDR + 0x00007000)
#define DAC1_BASE_ADDR			(APB1_BASE_ADDR + 0x00007400)
#define DAC2_BASE_ADDR			(APB1_BASE_ADDR + 0x00009800)
#define SPI3_BASE_ADDR			(APB1_BASE_ADDR + 0x00003C00)
#define SPI2_BASE_ADDR			(APB1_BASE_ADDR + 0x00003800)

/* APB2 bus modules */
#define SYSCFG_BASE_ADDR		(APB2_BASE_ADDR)
#define EXTI_BASE_ADDR			(APB2_BASE_ADDR + 0x00000400)
#define SPI1_BASE_ADDR			(APB2_BASE_ADDR + 0x00003000)

/* AHB1 bus modules */
#define DMA1_BASE_ADDR			(AHB1_BASE_ADDR)
#define DMA2_BASE_ADDR			(AHB1_BASE_ADDR + 0x00000400)
#define RCC_BASE_ADDR			(AHB1_BASE_ADDR + 0x00001000)
#define FLASH_BASE_ADDR		    (AHB1_BASE_ADDR + 0x00002000)
#define CRC_BASE_ADDR			(AHB1_BASE_ADDR + 0x00003000)
#define TSC_BASE_ADDR			(AHB1_BASE_ADDR + 0x00004000)

/* AHB2 bus modules */
#define GPIOA_BASE_ADDR			(AHB2_BASE_ADDR)
#define GPIOB_BASE_ADDR			(AHB2_BASE_ADDR + 0x00000400)
#define GPIOC_BASE_ADDR			(AHB2_BASE_ADDR + 0x00000800)
#define GPIOD_BASE_ADDR			(AHB2_BASE_ADDR + 0x00000C00)
#define GPIOE_BASE_ADDR			(AHB2_BASE_ADDR + 0x00001000)
#define GPIOH_BASE_ADDR			(AHB2_BASE_ADDR + 0x00001400)

/* AHB3 bus modules */
#define ADC1_BASE_ADDR			(AHB3_BASE_ADDR)

/* Internal processor registers */
#define NVIC_ISER0				(*(volatile uint32_t*)0xE000E100)
#define NVIC_ISER1				(*(volatile uint32_t*)0xE000E104)
#define NVIC_ISER2                (*(volatile uint32_t*)0xE000E108)
#define NVIC_ISER3                (*(volatile uint32_t*)0xE000E10C)
#define NVIC_ISER4                (*(volatile uint32_t*)0xE000E110)
#define NVIC_ISER5                (*(volatile uint32_t*)0xE000E114)
#define NVIC_ISER6                (*(volatile uint32_t*)0xE000E118)
#define NVIC_ISER7                (*(volatile uint32_t*)0xE000E11C)

#define SYSTICK_BASE			(*(volatile uint32_t*)0xE000E010)
#define SYSTCK 					((TypeDef_SysTick*) SYSTICK_BASE)
#define SCB_ICSR 				(*(volatile uint32_t*)0xE000E00C)
#define SCB_SHPR3				(*(volatile uint32_t*)0xE000ED20)
#define ICSR					(*(volatile uint32_t*)0xE000ED04)

/* SYS Tick */
#define STK_CTRL   (*(volatile uint32_t*)0xE000E010)
#define STK_LOAD   (*(volatile uint32_t*)0xE000E014)
#define STK_VAL    (*(volatile uint32_t*)0xE000E018)
#define STK_CALIB  (*(volatile uint32_t*)0xE000E01C)


#endif /* MEMORYMAP_H_ */
