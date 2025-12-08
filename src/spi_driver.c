/*
 * spi_driver.c
 *
 *  Created on: Nov 22, 2025
 *      Author: chris
 */

#include "../include/spi_driver.h"

void Driver_SPI_Init()
{
    /* ---- CR1: Reset ---- */
    SPI3->CR1 = 0;

    /* ---- CR2: Reset ---- */
    SPI3->CR2 = 0;

    /* ---- CR1 Configuration ---- */
    SPI3->CR1 =
            SPI_CR1_MSTR_SET()      // Master mode
          | SPI_CR1_BR(2)           // Baudrate /8  (~1 MHz @ 8 MHz clk)
          | SPI_CR1_SSM_SET()       // Software slave select
          | SPI_CR1_SSI_SET();      // Internal NSS high (avoid MODF)

    /* ---- CR2 Configuration ---- */
    SPI3->CR2 =
            SPI_CR2_DS(7);          // 8-bit mode

    /* ---- Enable SPI ---- */
    SPI3->CR1 |= SPI_CR1_SPE_SET();
}
