/*
 * dma_driver.c
 *
 *  Created on: Nov 16, 2025
 *      Author: chris
 */

#include "../include/dma_driver.h"
#include "../include/i2c_driver.h"

void Driver_DMA_Start(uint32_t* address)
{
    /* Disable DMA channel */
    DMA1->CCR1 &= ~DMA_CCR_EN_Msk;

    /* Peripheral = I2C TXDR */
    DMA1->CPAR1 = (uint32_t)&I2C1->TXDR;

    /* Memory source */
    DMA1->CMAR1 = (uint32_t)address;

    /* Number of data transfers */
    DMA1->CNDTR1 = 5;

    /* Configure the control register */
    DMA1->CCR1 =
          DMA_CCR_TCIE_SET()    // Transfer complete interrupt
        | DMA_CCR_TEIE_SET()    // Transfer error interrupt
        | DMA_CCR_DIR_SET()     // Memory -> Peripheral
        | DMA_CCR_MINC_SET()    // Memory increment
        | DMA_CCR_PSIZE(0)      // Peripheral size = 8-bit
        | DMA_CCR_MSIZE(0)      // Memory size = 8-bit
        | DMA_CCR_PL(1);        // Priority level

    /* Enable DMA channel */
    DMA1->CCR1 |= DMA_CCR_EN_SET();
}
