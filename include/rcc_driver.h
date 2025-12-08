/*
 * rcc_driver.h
 *
 *  Created on: Nov 23, 2025
 *      Author: chris
 */

#ifndef DRIVERS_RCC_DRIVER_H_
#define DRIVERS_RCC_DRIVER_H_

#include "memorymap.h"
#include "typedefs.h"
#include "peripherals.h"

/* Clock Macros */
#define RCC_CR_HSION_Pos            0U
#define RCC_CR_HSION_Msk            (1U << RCC_CR_HSION_Pos)
#define RCC_CR_HSION_EN             RCC_CR_HSION_Msk

#define RCC_CR_HSIRDY_Pos            1U
#define RCC_CR_HSIRDY_Msk            (1U << RCC_CR_HSIRDY_Pos)
#define RCC_CR_HSIRDY_EN             RCC_CR_HSIRDY_Msk

#define RCC_CFGR_SW_Pos             0U
#define RCC_CFGR_SW_Msk             (0x2U << RCC_CFGR_SW_Pos)
#define RCC_CFGR_SW_EN(x)           (x << RCC_CFGR_SW_Pos)


/* AHB Bus Index */
#define RCC_AHBEN_DMA1		(1 << 0)
#define RCC_AHBEN_DMA2		(1 << 1)
#define RCC_AHBEN_SRAM		(1 << 2)
#define RCC_AHBEN_FLITF		(1 << 4)
#define RCC_AHBEN_FMC		(1 << 5)
#define RCC_AHBEN_CRC		(1 << 6)
#define RCC_AHBEN_GPIOH		(1 << 16)
#define RCC_AHBEN_GPIOA		(1 << 17)
#define RCC_AHBEN_GPIOB		(1 << 18)
#define RCC_AHBEN_GPIOC		(1 << 19)
#define RCC_AHBEN_GPIOD		(1 << 20)
#define RCC_AHBEN_GPIOE		(1 << 21)
#define RCC_AHBEN_GPIOF		(1 << 22)
#define RCC_AHBEN_GPIOG		(1 << 23)
#define RCC_AHBEN_ADC12		(1 << 28)
#define RCC_AHBEN_ADC34		(1 << 29)

// APB1 Peripherie Clock
#define RCC_APB1ENR_USART2EN    (1 << 17)

// APB2 Peripherie Clock
#define RCC_APB2ENR_USART1EN    (1 << 14)


// Activate clocks
#define RCC_ENABLE_GPIOA()      (RCC->AHBENR |= RCC_AHBEN_GPIOA)
#define RCC_ENABLE_GPIOB()      (RCC->AHBENR |= RCC_AHBEN_GPIOB)
#define RCC_ENABLE_GPIOC()      (RCC->AHBENR |= RCC_AHBEN_GPIOC)
#define RCC_ENABLE_GPIOD()      (RCC->AHBENR |= RCC_AHBEN_GPIOD)
#define RCC_ENABLE_GPIOE()      (RCC->AHBENR |= RCC_AHBEN_GPIOE)
#define RCC_ENABLE_GPIOF()      (RCC->AHBENR |= RCC_AHBEN_GPIOF)
#define RCC_ENABLE_GPIOG()      (RCC->AHBENR |= RCC_AHBEN_GPIOG)
#define RCC_ENABLE_GPIOH()      (RCC->AHBENR |= RCC_AHBEN_GPIOH)


#define RCC_ENABLE_USART1()     (RCC->APB2ENR |= RCC_APB2ENR_USART1EN)
#define RCC_ENABLE_USART2()     (RCC->APB1ENR |= RCC_APB1ENR_USART2EN)

void Driver_RCC_ClockSetup();


#endif /* DRIVERS_RCC_DRIVER_H_ */
