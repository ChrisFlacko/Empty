/*
 * spi_driver.h
 *
 *  Created on: Nov 22, 2025
 *      Author: chris
 */

#ifndef DRIVERS_SPI_DRIVER_H_
#define DRIVERS_SPI_DRIVER_H_

#include "memorymap.h"
#include "peripherals.h"
#include "typedefs.h"

#define SPI_CR1_CPHA_Pos           0U
#define SPI_CR1_CPHA_Msk           (1U << SPI_CR1_CPHA_Pos)
#define SPI_CR1_CPHA_SET()         (1U << SPI_CR1_CPHA_Pos)

#define SPI_CR1_CPOL_Pos           1U
#define SPI_CR1_CPOL_Msk           (1U << SPI_CR1_CPOL_Pos)
#define SPI_CR1_CPOL_SET()         (1U << SPI_CR1_CPOL_Pos)

#define SPI_CR1_MSTR_Pos           2U
#define SPI_CR1_MSTR_Msk           (1U << SPI_CR1_MSTR_Pos)
#define SPI_CR1_MSTR_SET()         (1U << SPI_CR1_MSTR_Pos)

#define SPI_CR1_BR_Pos             3U
#define SPI_CR1_BR_Msk             (7U << SPI_CR1_BR_Pos)
#define SPI_CR1_BR(val)            ((val & 0x7) << SPI_CR1_BR_Pos)

#define SPI_CR1_SPE_Pos            6U
#define SPI_CR1_SPE_Msk            (1U << SPI_CR1_SPE_Pos)
#define SPI_CR1_SPE_SET()          (1U << SPI_CR1_SPE_Pos)

#define SPI_CR1_LSBFIRST_Pos       7U
#define SPI_CR1_LSBFIRST_Msk       (1U << SPI_CR1_LSBFIRST_Pos)
#define SPI_CR1_LSBFIRST_SET()     (1U << SPI_CR1_LSBFIRST_Pos)

#define SPI_CR1_SSI_Pos            8U
#define SPI_CR1_SSI_Msk            (1U << SPI_CR1_SSI_Pos)
#define SPI_CR1_SSI_SET()          (1U << SPI_CR1_SSI_Pos)

#define SPI_CR1_SSM_Pos            9U
#define SPI_CR1_SSM_Msk            (1U << SPI_CR1_SSM_Pos)
#define SPI_CR1_SSM_SET()          (1U << SPI_CR1_SSM_Pos)

#define SPI_CR1_RXONLY_Pos         10U
#define SPI_CR1_RXONLY_Msk         (1U << SPI_CR1_RXONLY_Pos)
#define SPI_CR1_RXONLY_SET()       (1U << SPI_CR1_RXONLY_Pos)

#define SPI_CR1_DFF_Pos            11U
#define SPI_CR1_DFF_Msk            (1U << SPI_CR1_DFF_Pos)
#define SPI_CR1_DFF_SET()          (1U << SPI_CR1_DFF_Pos)

#define SPI_CR1_CRCNEXT_Pos        12U
#define SPI_CR1_CRCNEXT_Msk        (1U << SPI_CR1_CRCNEXT_Pos)
#define SPI_CR1_CRCNEXT_SET()      (1U << SPI_CR1_CRCNEXT_Pos)

#define SPI_CR1_CRCEN_Pos          13U
#define SPI_CR1_CRCEN_Msk          (1U << SPI_CR1_CRCEN_Pos)
#define SPI_CR1_CRCEN_SET()        (1U << SPI_CR1_CRCEN_Pos)

#define SPI_CR1_BIDIOE_Pos         14U
#define SPI_CR1_BIDIOE_Msk         (1U << SPI_CR1_BIDIOE_Pos)
#define SPI_CR1_BIDIOE_SET()       (1U << SPI_CR1_BIDIOE_Pos)

#define SPI_CR1_BIDIMODE_Pos       15U
#define SPI_CR1_BIDIMODE_Msk       (1U << SPI_CR1_BIDIMODE_Pos)
#define SPI_CR1_BIDIMODE_SET()     (1U << SPI_CR1_BIDIMODE_Pos)

#define SPI_CR2_RXDMAEN_Pos        0U
#define SPI_CR2_RXDMAEN_Msk        (1U << SPI_CR2_RXDMAEN_Pos)
#define SPI_CR2_RXDMAEN_SET()      (1U << SPI_CR2_RXDMAEN_Pos)

#define SPI_CR2_TXDMAEN_Pos        1U
#define SPI_CR2_TXDMAEN_Msk        (1U << SPI_CR2_TXDMAEN_Pos)
#define SPI_CR2_TXDMAEN_SET()      (1U << SPI_CR2_TXDMAEN_Pos)

#define SPI_CR2_SSOE_Pos           2U
#define SPI_CR2_SSOE_Msk           (1U << SPI_CR2_SSOE_Pos)
#define SPI_CR2_SSOE_SET()         (1U << SPI_CR2_SSOE_Pos)

#define SPI_CR2_NSSP_Pos           3U
#define SPI_CR2_NSSP_Msk           (1U << SPI_CR2_NSSP_Pos)
#define SPI_CR2_NSSP_SET()         (1U << SPI_CR2_NSSP_Pos)

#define SPI_CR2_FRF_Pos            4U
#define SPI_CR2_FRF_Msk            (1U << SPI_CR2_FRF_Pos)
#define SPI_CR2_FRF_SET()          (1U << SPI_CR2_FRF_Pos)

#define SPI_CR2_ERRIE_Pos          5U
#define SPI_CR2_ERRIE_Msk          (1U << SPI_CR2_ERRIE_Pos)
#define SPI_CR2_ERRIE_SET()        (1U << SPI_CR2_ERRIE_Pos)

#define SPI_CR2_RXNEIE_Pos         6U
#define SPI_CR2_RXNEIE_Msk         (1U << SPI_CR2_RXNEIE_Pos)
#define SPI_CR2_RXNEIE_SET()       (1U << SPI_CR2_RXNEIE_Pos)

#define SPI_CR2_TXEIE_Pos          7U
#define SPI_CR2_TXEIE_Msk          (1U << SPI_CR2_TXEIE_Pos)
#define SPI_CR2_TXEIE_SET()        (1U << SPI_CR2_TXEIE_Pos)

#define SPI_CR2_DS_Pos             8U
#define SPI_CR2_DS_Msk             (0xF << SPI_CR2_DS_Pos)
#define SPI_CR2_DS(val)            ((val & 0xF) << SPI_CR2_DS_Pos)

#define SPI_CR2_FRXTH_Pos          12U
#define SPI_CR2_FRXTH_Msk          (1U << SPI_CR2_FRXTH_Pos)
#define SPI_CR2_FRXTH_SET()        (1U << SPI_CR2_FRXTH_Pos)

#define SPI_CR2_LDMA_RX_Pos        13U
#define SPI_CR2_LDMA_RX_Msk        (1U << SPI_CR2_LDMA_RX_Pos)
#define SPI_CR2_LDMA_RX_SET()      (1U << SPI_CR2_LDMA_RX_Pos)

#define SPI_CR2_LDMA_TX_Pos        14U
#define SPI_CR2_LDMA_TX_Msk        (1U << SPI_CR2_LDMA_TX_Pos)
#define SPI_CR2_LDMA_TX_SET()      (1U << SPI_CR2_LDMA_TX_Pos)

#define SPI_SR_RXNE_Pos            0U
#define SPI_SR_RXNE_Msk            (1U << SPI_SR_RXNE_Pos)
#define SPI_SR_RXNE_SET()          (1U << SPI_SR_RXNE_Pos)

#define SPI_SR_TXE_Pos             1U
#define SPI_SR_TXE_Msk             (1U << SPI_SR_TXE_Pos)
#define SPI_SR_TXE_SET()           (1U << SPI_SR_TXE_Pos)

#define SPI_SR_CHSIDE_Pos          2U
#define SPI_SR_CHSIDE_Msk          (1U << SPI_SR_CHSIDE_Pos)
#define SPI_SR_CHSIDE_SET()        (1U << SPI_SR_CHSIDE_Pos)

#define SPI_SR_UDR_Pos             3U
#define SPI_SR_UDR_Msk             (1U << SPI_SR_UDR_Pos)
#define SPI_SR_UDR_SET()           (1U << SPI_SR_UDR_Pos)

#define SPI_SR_CRCERR_Pos          4U
#define SPI_SR_CRCERR_Msk          (1U << SPI_SR_CRCERR_Pos)
#define SPI_SR_CRCERR_SET()        (1U << SPI_SR_CRCERR_Pos)

#define SPI_SR_MODF_Pos            5U
#define SPI_SR_MODF_Msk            (1U << SPI_SR_MODF_Pos)
#define SPI_SR_MODF_SET()          (1U << SPI_SR_MODF_Pos)

#define SPI_SR_OVR_Pos             6U
#define SPI_SR_OVR_Msk             (1U << SPI_SR_OVR_Pos)
#define SPI_SR_OVR_SET()           (1U << SPI_SR_OVR_Pos)

#define SPI_SR_BSY_Pos             7U
#define SPI_SR_BSY_Msk             (1U << SPI_SR_BSY_Pos)
#define SPI_SR_BSY_SET()           (1U << SPI_SR_BSY_Pos)

#define SPI_SR_FRE_Pos             8U
#define SPI_SR_FRE_Msk             (1U << SPI_SR_FRE_Pos)
#define SPI_SR_FRE_SET()           (1U << SPI_SR_FRE_Pos)



#endif /* DRIVERS_SPI_DRIVER_H_ */
