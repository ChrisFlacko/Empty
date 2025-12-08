/*
 * i2c_driver.c
 *
 *  Created on: Nov 15, 2025
 *      Author: chris
 */

#include "../include/i2c_driver.h"

/*
 * The Timing: 8 MHz Input clock
 * PRESC = 1 -> 250ns time base (PRESC+1 * t_CLK)
 *
 *
 */
void Driver_I2C_Init()
{
	/* CR1-Register */
	I2C1->CR1 &= ~I2C_CR1_PE_Msk;		// Diable I2C1
	I2C1->CR1 |= I2C_CR1_TXIE_SET()		// Enable Tx Interrupt
			| I2C_CR1_RXIE_SET()		// Enable Rx Interrupt
			| I2C_CR1_TCIE_SET();		// Enable Transfer complete interrupt
	I2C1->CR1 &= ~I2C_CR1_ANFOFF_SET();	// Enable analog Filter
	I2C1->CR1 &= ~I2C_CR1_NOSTRETCH_SET();// Enable clock stretching

	/* TIMINGR-Register */
	I2C1->TIMINGR = I2C_TIMINGR_PRESC(1)		// Prescaler of 1 -> 250ns tick
		| I2C_TIMINGR_SCLL(20)		// Equals 5us
		| I2C_TIMINGR_SCLH(18)		// Equals 4,5us
		| I2C_TIMINGR_SDADEL(1)
		| I2C_TIMINGR_SCLDEL(1);

	I2C1->CR1 |= I2C_CR1_PE_SET(); 		// Enable I2C1
}

void Driver_I2C_Send(uint8_t bytes, uint8_t slaveAddress)
{
	I2C1->CR2 = I2C_CR2_SADD(slaveAddress)				// Address of the slave
		| I2C_CR2_NBYTES(bytes)			// Sending x Bytes
		| I2C_CR2_AUTOEND_SET();			// Automatically send stop after nbytes
	I2C1->CR2 &= ~I2C_CR2_RD_WRN_Msk;

	I2C1->CR2 |= I2C_CR2_START_SET();			// Start communication
}
