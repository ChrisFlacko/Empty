/*
 * i2c_driver.h
 *
 *  Created on: Nov 15, 2025
 *      Author: chris
 */

#ifndef DRIVERS_I2C_DRIVER_H_
#define DRIVERS_I2C_DRIVER_H_

#include "memorymap.h"
#include "peripherals.h"
#include "typedefs.h"

/*
 * I2C register/bit definitions (CMSIS style)
 * For STM32F3 series (RM0316)
 *
 * Generated fields:
 *  - <REG>_<FIELD>_Pos
 *  - <REG>_<FIELD>_Msk
 *  - <REG>_<FIELD>        (for single-bit flags)
 *  - <REG>_<FIELD>_SET()  (convenience macro to produce the set value)
 *  - <REG>_<FIELD>(x)     (for bitfields: value macro)
 *
 * Source: STM32F303/STM32F3 Reference Manual (RM0316). See embedded excerpts included
 * in the project documentation.
 */

/* ------------------------------- I2C_CR1 ---------------------------------- */
/* Control register 1 (offset 0x00) */
#define I2C_CR1_PE_Pos            0U
#define I2C_CR1_PE_Msk            (1U << I2C_CR1_PE_Pos)
#define I2C_CR1_PE                I2C_CR1_PE_Msk
#define I2C_CR1_PE_SET()          (1U << I2C_CR1_PE_Pos)

#define I2C_CR1_TXIE_Pos          1U
#define I2C_CR1_TXIE_Msk          (1U << I2C_CR1_TXIE_Pos)
#define I2C_CR1_TXIE              I2C_CR1_TXIE_Msk
#define I2C_CR1_TXIE_SET()        (1U << I2C_CR1_TXIE_Pos)

#define I2C_CR1_RXIE_Pos          2U
#define I2C_CR1_RXIE_Msk          (1U << I2C_CR1_RXIE_Pos)
#define I2C_CR1_RXIE              I2C_CR1_RXIE_Msk
#define I2C_CR1_RXIE_SET()        (1U << I2C_CR1_RXIE_Pos)

#define I2C_CR1_ADDRIE_Pos        3U
#define I2C_CR1_ADDRIE_Msk        (1U << I2C_CR1_ADDRIE_Pos)
#define I2C_CR1_ADDRIE            I2C_CR1_ADDRIE_Msk
#define I2C_CR1_ADDRIE_SET()      (1U << I2C_CR1_ADDRIE_Pos)

#define I2C_CR1_NACKIE_Pos        4U
#define I2C_CR1_NACKIE_Msk        (1U << I2C_CR1_NACKIE_Pos)
#define I2C_CR1_NACKIE            I2C_CR1_NACKIE_Msk
#define I2C_CR1_NACKIE_SET()      (1U << I2C_CR1_NACKIE_Pos)

#define I2C_CR1_STOPIE_Pos        5U
#define I2C_CR1_STOPIE_Msk        (1U << I2C_CR1_STOPIE_Pos)
#define I2C_CR1_STOPIE            I2C_CR1_STOPIE_Msk
#define I2C_CR1_STOPIE_SET()      (1U << I2C_CR1_STOPIE_Pos)

#define I2C_CR1_TCIE_Pos          6U
#define I2C_CR1_TCIE_Msk          (1U << I2C_CR1_TCIE_Pos)
#define I2C_CR1_TCIE              I2C_CR1_TCIE_Msk
#define I2C_CR1_TCIE_SET()        (1U << I2C_CR1_TCIE_Pos)

#define I2C_CR1_ERRIE_Pos         7U
#define I2C_CR1_ERRIE_Msk         (1U << I2C_CR1_ERRIE_Pos)
#define I2C_CR1_ERRIE             I2C_CR1_ERRIE_Msk
#define I2C_CR1_ERRIE_SET()       (1U << I2C_CR1_ERRIE_Pos)

/* DNF[3:0] (bits 11:8) */
#define I2C_CR1_DNF_Pos           8U
#define I2C_CR1_DNF_Msk           (0xFU << I2C_CR1_DNF_Pos)
#define I2C_CR1_DNF(x)            (((x) & 0xFU) << I2C_CR1_DNF_Pos)

/* ANFOFF bit (12) */
#define I2C_CR1_ANFOFF_Pos        12U
#define I2C_CR1_ANFOFF_Msk        (1U << I2C_CR1_ANFOFF_Pos)
#define I2C_CR1_ANFOFF            I2C_CR1_ANFOFF_Msk
#define I2C_CR1_ANFOFF_SET()      (1U << I2C_CR1_ANFOFF_Pos)

/* TXDMAEN (14), RXDMAEN (15) */
#define I2C_CR1_TXDMAEN_Pos       14U
#define I2C_CR1_TXDMAEN_Msk       (1U << I2C_CR1_TXDMAEN_Pos)
#define I2C_CR1_TXDMAEN           I2C_CR1_TXDMAEN_Msk
#define I2C_CR1_TXDMAEN_SET()     (1U << I2C_CR1_TXDMAEN_Pos)

#define I2C_CR1_RXDMAEN_Pos       15U
#define I2C_CR1_RXDMAEN_Msk       (1U << I2C_CR1_RXDMAEN_Pos)
#define I2C_CR1_RXDMAEN           I2C_CR1_RXDMAEN_Msk
#define I2C_CR1_RXDMAEN_SET()     (1U << I2C_CR1_RXDMAEN_Pos)

/* SBC (16), NOSTRETCH (17), WUPEN (18), GCEN (19) */
#define I2C_CR1_SBC_Pos           16U
#define I2C_CR1_SBC_Msk           (1U << I2C_CR1_SBC_Pos)
#define I2C_CR1_SBC               I2C_CR1_SBC_Msk
#define I2C_CR1_SBC_SET()         (1U << I2C_CR1_SBC_Pos)

#define I2C_CR1_NOSTRETCH_Pos     17U
#define I2C_CR1_NOSTRETCH_Msk     (1U << I2C_CR1_NOSTRETCH_Pos)
#define I2C_CR1_NOSTRETCH         I2C_CR1_NOSTRETCH_Msk
#define I2C_CR1_NOSTRETCH_SET()   (1U << I2C_CR1_NOSTRETCH_Pos)

#define I2C_CR1_WUPEN_Pos         18U
#define I2C_CR1_WUPEN_Msk         (1U << I2C_CR1_WUPEN_Pos)
#define I2C_CR1_WUPEN             I2C_CR1_WUPEN_Msk
#define I2C_CR1_WUPEN_SET()       (1U << I2C_CR1_WUPEN_Pos)

#define I2C_CR1_GCEN_Pos          19U
#define I2C_CR1_GCEN_Msk          (1U << I2C_CR1_GCEN_Pos)
#define I2C_CR1_GCEN              I2C_CR1_GCEN_Msk
#define I2C_CR1_GCEN_SET()        (1U << I2C_CR1_GCEN_Pos)

/* SMBHEN (20), SMBDEN (21), ALERTEN (22), PECEN (23) */
#define I2C_CR1_SMBHEN_Pos        20U
#define I2C_CR1_SMBHEN_Msk        (1U << I2C_CR1_SMBHEN_Pos)
#define I2C_CR1_SMBHEN            I2C_CR1_SMBHEN_Msk
#define I2C_CR1_SMBHEN_SET()      (1U << I2C_CR1_SMBHEN_Pos)

#define I2C_CR1_SMBDEN_Pos        21U
#define I2C_CR1_SMBDEN_Msk        (1U << I2C_CR1_SMBDEN_Pos)
#define I2C_CR1_SMBDEN            I2C_CR1_SMBDEN_Msk
#define I2C_CR1_SMBDEN_SET()      (1U << I2C_CR1_SMBDEN_Pos)

#define I2C_CR1_ALERTEN_Pos       22U
#define I2C_CR1_ALERTEN_Msk       (1U << I2C_CR1_ALERTEN_Pos)
#define I2C_CR1_ALERTEN           I2C_CR1_ALERTEN_Msk
#define I2C_CR1_ALERTEN_SET()     (1U << I2C_CR1_ALERTEN_Pos)

#define I2C_CR1_PECEN_Pos         23U
#define I2C_CR1_PECEN_Msk         (1U << I2C_CR1_PECEN_Pos)
#define I2C_CR1_PECEN             I2C_CR1_PECEN_Msk
#define I2C_CR1_PECEN_SET()       (1U << I2C_CR1_PECEN_Pos)


/* ------------------------------- I2C_CR2 ---------------------------------- */
/* Control register 2 (offset 0x04) */
#define I2C_CR2_SADD_Pos          0U
#define I2C_CR2_SADD_Msk          (0x3FFU << I2C_CR2_SADD_Pos)   /* 10 bits */
#define I2C_CR2_SADD(x)           (((x) & 0x3FFU) << I2C_CR2_SADD_Pos)

#define I2C_CR2_RD_WRN_Pos        10U
#define I2C_CR2_RD_WRN_Msk        (1U << I2C_CR2_RD_WRN_Pos)
#define I2C_CR2_RD_WRN            I2C_CR2_RD_WRN_Msk
#define I2C_CR2_RD_WRN_SET()      (1U << I2C_CR2_RD_WRN_Pos)

#define I2C_CR2_ADD10_Pos         11U
#define I2C_CR2_ADD10_Msk         (1U << I2C_CR2_ADD10_Pos)
#define I2C_CR2_ADD10             I2C_CR2_ADD10_Msk
#define I2C_CR2_ADD10_SET()       (1U << I2C_CR2_ADD10_Pos)

#define I2C_CR2_HEAD10R_Pos       12U
#define I2C_CR2_HEAD10R_Msk       (1U << I2C_CR2_HEAD10R_Pos)
#define I2C_CR2_HEAD10R           I2C_CR2_HEAD10R_Msk
#define I2C_CR2_HEAD10R_SET()     (1U << I2C_CR2_HEAD10R_Pos)

#define I2C_CR2_START_Pos         13U
#define I2C_CR2_START_Msk         (1U << I2C_CR2_START_Pos)
#define I2C_CR2_START             I2C_CR2_START_Msk
#define I2C_CR2_START_SET()       (1U << I2C_CR2_START_Pos)

#define I2C_CR2_STOP_Pos          14U
#define I2C_CR2_STOP_Msk          (1U << I2C_CR2_STOP_Pos)
#define I2C_CR2_STOP              I2C_CR2_STOP_Msk
#define I2C_CR2_STOP_SET()        (1U << I2C_CR2_STOP_Pos)

#define I2C_CR2_NACK_Pos          15U
#define I2C_CR2_NACK_Msk          (1U << I2C_CR2_NACK_Pos)
#define I2C_CR2_NACK              I2C_CR2_NACK_Msk
#define I2C_CR2_NACK_SET()        (1U << I2C_CR2_NACK_Pos)

/* NBYTES[7:0] bits 23:16 */
#define I2C_CR2_NBYTES_Pos        16U
#define I2C_CR2_NBYTES_Msk        (0xFFU << I2C_CR2_NBYTES_Pos)
#define I2C_CR2_NBYTES(x)         (((x) & 0xFFU) << I2C_CR2_NBYTES_Pos)

/* RELOAD (24), AUTOEND (25), PECBYTE (26) */
#define I2C_CR2_RELOAD_Pos        24U
#define I2C_CR2_RELOAD_Msk        (1U << I2C_CR2_RELOAD_Pos)
#define I2C_CR2_RELOAD            I2C_CR2_RELOAD_Msk
#define I2C_CR2_RELOAD_SET()      (1U << I2C_CR2_RELOAD_Pos)

#define I2C_CR2_AUTOEND_Pos       25U
#define I2C_CR2_AUTOEND_Msk       (1U << I2C_CR2_AUTOEND_Pos)
#define I2C_CR2_AUTOEND           I2C_CR2_AUTOEND_Msk
#define I2C_CR2_AUTOEND_SET()     (1U << I2C_CR2_AUTOEND_Pos)

#define I2C_CR2_PECBYTE_Pos       26U
#define I2C_CR2_PECBYTE_Msk       (1U << I2C_CR2_PECBYTE_Pos)
#define I2C_CR2_PECBYTE           I2C_CR2_PECBYTE_Msk
#define I2C_CR2_PECBYTE_SET()     (1U << I2C_CR2_PECBYTE_Pos)


/* ------------------------------- I2C_OAR1 --------------------------------- */
/* Own address register 1 (offset 0x08) */
#define I2C_OAR1_OA1_Pos          0U
#define I2C_OAR1_OA1_Msk          (0x3FFU << I2C_OAR1_OA1_Pos) /* OA1[9:0] */
#define I2C_OAR1_OA1(x)           (((x) & 0x3FFU) << I2C_OAR1_OA1_Pos)

#define I2C_OAR1_OA1MODE_Pos      10U
#define I2C_OAR1_OA1MODE_Msk      (1U << I2C_OAR1_OA1MODE_Pos) /* 0:7-bit,1:10-bit */
#define I2C_OAR1_OA1MODE          I2C_OAR1_OA1MODE_Msk
#define I2C_OAR1_OA1MODE_SET()    (1U << I2C_OAR1_OA1MODE_Pos)

#define I2C_OAR1_OA1EN_Pos        15U
#define I2C_OAR1_OA1EN_Msk        (1U << I2C_OAR1_OA1EN_Pos)
#define I2C_OAR1_OA1EN            I2C_OAR1_OA1EN_Msk
#define I2C_OAR1_OA1EN_SET()      (1U << I2C_OAR1_OA1EN_Pos)


/* ------------------------------- I2C_OAR2 --------------------------------- */
/* Own address register 2 (offset 0x0C) */
#define I2C_OAR2_OA2_Pos          1U
#define I2C_OAR2_OA2_Msk          (0x7FU << I2C_OAR2_OA2_Pos) /* OA2[7:1] (7 bits) */
#define I2C_OAR2_OA2(x)           (((x) & 0x7FU) << I2C_OAR2_OA2_Pos)

#define I2C_OAR2_OA2MSK_Pos       8U
#define I2C_OAR2_OA2MSK_Msk       (0x7U << I2C_OAR2_OA2MSK_Pos) /* OA2MSK[2:0] */
#define I2C_OAR2_OA2MSK(x)        (((x) & 0x7U) << I2C_OAR2_OA2MSK_Pos)

#define I2C_OAR2_OA2EN_Pos        15U
#define I2C_OAR2_OA2EN_Msk        (1U << I2C_OAR2_OA2EN_Pos)
#define I2C_OAR2_OA2EN            I2C_OAR2_OA2EN_Msk
#define I2C_OAR2_OA2EN_SET()      (1U << I2C_OAR2_OA2EN_Pos)


/* ------------------------------- I2C_TIMINGR ------------------------------ */
/* Timing register (offset 0x10) */
#define I2C_TIMINGR_PRESC_Pos     28U
#define I2C_TIMINGR_PRESC_Msk     (0xFU << I2C_TIMINGR_PRESC_Pos)
#define I2C_TIMINGR_PRESC(x)      (((x) & 0xFU) << I2C_TIMINGR_PRESC_Pos)

#define I2C_TIMINGR_SCLDEL_Pos    20U
#define I2C_TIMINGR_SCLDEL_Msk    (0xFU << I2C_TIMINGR_SCLDEL_Pos)
#define I2C_TIMINGR_SCLDEL(x)     (((x) & 0xFU) << I2C_TIMINGR_SCLDEL_Pos)

#define I2C_TIMINGR_SDADEL_Pos    16U
#define I2C_TIMINGR_SDADEL_Msk    (0xFU << I2C_TIMINGR_SDADEL_Pos)
#define I2C_TIMINGR_SDADEL(x)     (((x) & 0xFU) << I2C_TIMINGR_SDADEL_Pos)

#define I2C_TIMINGR_SCLH_Pos      8U
#define I2C_TIMINGR_SCLH_Msk      (0xFFU << I2C_TIMINGR_SCLH_Pos)
#define I2C_TIMINGR_SCLH(x)       (((x) & 0xFFU) << I2C_TIMINGR_SCLH_Pos)

#define I2C_TIMINGR_SCLL_Pos      0U
#define I2C_TIMINGR_SCLL_Msk      (0xFFU << I2C_TIMINGR_SCLL_Pos)
#define I2C_TIMINGR_SCLL(x)       (((x) & 0xFFU) << I2C_TIMINGR_SCLL_Pos)


/* ------------------------------- I2C_TIMEOUTR ------------------------------ */
/* Timeout register (offset 0x14) */
#define I2C_TIMEOUTR_TIMEOUTA_Pos 0U
#define I2C_TIMEOUTR_TIMEOUTA_Msk (0xFFFU << I2C_TIMEOUTR_TIMEOUTA_Pos) /* 12 bits */
#define I2C_TIMEOUTR_TIMEOUTA(x)  (((x) & 0xFFFU) << I2C_TIMEOUTR_TIMEOUTA_Pos)

#define I2C_TIMEOUTR_TIDLE_Pos    12U
#define I2C_TIMEOUTR_TIDLE_Msk    (1U << I2C_TIMEOUTR_TIDLE_Pos)
#define I2C_TIMEOUTR_TIDLE        I2C_TIMEOUTR_TIDLE_Msk
#define I2C_TIMEOUTR_TIDLE_SET()  (1U << I2C_TIMEOUTR_TIDLE_Pos)

#define I2C_TIMEOUTR_TIMOUTEN_Pos 15U
#define I2C_TIMEOUTR_TIMOUTEN_Msk (1U << I2C_TIMEOUTR_TIMOUTEN_Pos)
#define I2C_TIMEOUTR_TIMOUTEN     I2C_TIMEOUTR_TIMOUTEN_Msk
#define I2C_TIMEOUTR_TIMOUTEN_SET() (1U << I2C_TIMEOUTR_TIMOUTEN_Pos)

#define I2C_TIMEOUTR_TIMEOUTB_Pos 16U
#define I2C_TIMEOUTR_TIMEOUTB_Msk (0xFFFU << I2C_TIMEOUTR_TIMEOUTB_Pos)
#define I2C_TIMEOUTR_TIMEOUTB(x)  (((x) & 0xFFFU) << I2C_TIMEOUTR_TIMEOUTB_Pos)

#define I2C_TIMEOUTR_TEXTEN_Pos   31U
#define I2C_TIMEOUTR_TEXTEN_Msk   (1U << I2C_TIMEOUTR_TEXTEN_Pos)
#define I2C_TIMEOUTR_TEXTEN       I2C_TIMEOUTR_TEXTEN_Msk
#define I2C_TIMEOUTR_TEXTEN_SET() (1U << I2C_TIMEOUTR_TEXTEN_Pos)


/* ------------------------------- I2C_ISR ---------------------------------- */
/* Interrupt and status register (offset 0x18) */
/* Bits 0..15: TXE/TXIS/RXNE/ADDR/NACKF/STOPF/TC/TCR/BERR/ARLO/OVR/PECERR/TIMEOUT/ALERT/BUSY */
#define I2C_ISR_TXE_Pos           0U
#define I2C_ISR_TXE_Msk           (1U << I2C_ISR_TXE_Pos)
#define I2C_ISR_TXE               I2C_ISR_TXE_Msk

#define I2C_ISR_TXIS_Pos          1U
#define I2C_ISR_TXIS_Msk          (1U << I2C_ISR_TXIS_Pos)
#define I2C_ISR_TXIS              I2C_ISR_TXIS_Msk

#define I2C_ISR_RXNE_Pos          2U
#define I2C_ISR_RXNE_Msk          (1U << I2C_ISR_RXNE_Pos)
#define I2C_ISR_RXNE              I2C_ISR_RXNE_Msk

#define I2C_ISR_ADDR_Pos          3U
#define I2C_ISR_ADDR_Msk          (1U << I2C_ISR_ADDR_Pos)
#define I2C_ISR_ADDR              I2C_ISR_ADDR_Msk

#define I2C_ISR_NACKF_Pos         4U
#define I2C_ISR_NACKF_Msk         (1U << I2C_ISR_NACKF_Pos)
#define I2C_ISR_NACKF             I2C_ISR_NACKF_Msk

#define I2C_ISR_STOPF_Pos         5U
#define I2C_ISR_STOPF_Msk         (1U << I2C_ISR_STOPF_Pos)
#define I2C_ISR_STOPF             I2C_ISR_STOPF_Msk

#define I2C_ISR_TC_Pos            6U
#define I2C_ISR_TC_Msk            (1U << I2C_ISR_TC_Pos)
#define I2C_ISR_TC                I2C_ISR_TC_Msk

#define I2C_ISR_TCR_Pos           7U
#define I2C_ISR_TCR_Msk           (1U << I2C_ISR_TCR_Pos)
#define I2C_ISR_TCR               I2C_ISR_TCR_Msk

#define I2C_ISR_BERR_Pos          8U
#define I2C_ISR_BERR_Msk          (1U << I2C_ISR_BERR_Pos)
#define I2C_ISR_BERR              I2C_ISR_BERR_Msk

#define I2C_ISR_ARLO_Pos          9U
#define I2C_ISR_ARLO_Msk          (1U << I2C_ISR_ARLO_Pos)
#define I2C_ISR_ARLO              I2C_ISR_ARLO_Msk

#define I2C_ISR_OVR_Pos           10U
#define I2C_ISR_OVR_Msk           (1U << I2C_ISR_OVR_Pos)
#define I2C_ISR_OVR               I2C_ISR_OVR_Msk

#define I2C_ISR_PECERR_Pos        11U
#define I2C_ISR_PECERR_Msk        (1U << I2C_ISR_PECERR_Pos)
#define I2C_ISR_PECERR            I2C_ISR_PECERR_Msk

#define I2C_ISR_TIMEOUT_Pos       12U
#define I2C_ISR_TIMEOUT_Msk       (1U << I2C_ISR_TIMEOUT_Pos)
#define I2C_ISR_TIMEOUT           I2C_ISR_TIMEOUT_Msk

#define I2C_ISR_ALERT_Pos         13U
#define I2C_ISR_ALERT_Msk         (1U << I2C_ISR_ALERT_Pos)
#define I2C_ISR_ALERT             I2C_ISR_ALERT_Msk

#define I2C_ISR_BUSY_Pos          15U
#define I2C_ISR_BUSY_Msk          (1U << I2C_ISR_BUSY_Pos)
#define I2C_ISR_BUSY              I2C_ISR_BUSY_Msk

/* ADDCODE[6:0] at bits 23:17 */
#define I2C_ISR_ADDCODE_Pos       17U
#define I2C_ISR_ADDCODE_Msk       (0x7FU << I2C_ISR_ADDCODE_Pos)
#define I2C_ISR_ADDCODE(x)        (((x) & 0x7FU) << I2C_ISR_ADDCODE_Pos)

#define I2C_ISR_DIR_Pos           16U
#define I2C_ISR_DIR_Msk           (1U << I2C_ISR_DIR_Pos)
#define I2C_ISR_DIR               I2C_ISR_DIR_Msk


/* ------------------------------- I2C_ICR ---------------------------------- */
/* Interrupt clear register (offset 0x1C) */
/* Write 1 to clear corresponding flag */
#define I2C_ICR_ADDRCF_Pos        3U
#define I2C_ICR_ADDRCF_Msk        (1U << I2C_ICR_ADDRCF_Pos)
#define I2C_ICR_ADDRCF_SET()      (1U << I2C_ICR_ADDRCF_Pos)

#define I2C_ICR_NACKCF_Pos        4U
#define I2C_ICR_NACKCF_Msk        (1U << I2C_ICR_NACKCF_Pos)
#define I2C_ICR_NACKCF_SET()      (1U << I2C_ICR_NACKCF_Pos)

#define I2C_ICR_STOPCF_Pos        5U
#define I2C_ICR_STOPCF_Msk        (1U << I2C_ICR_STOPCF_Pos)
#define I2C_ICR_STOPCF_SET()      (1U << I2C_ICR_STOPCF_Pos)

#define I2C_ICR_BERRCF_Pos        8U
#define I2C_ICR_BERRCF_Msk        (1U << I2C_ICR_BERRCF_Pos)
#define I2C_ICR_BERRCF_SET()      (1U << I2C_ICR_BERRCF_Pos)

#define I2C_ICR_ARLOCF_Pos        9U
#define I2C_ICR_ARLOCF_Msk        (1U << I2C_ICR_ARLOCF_Pos)
#define I2C_ICR_ARLOCF_SET()      (1U << I2C_ICR_ARLOCF_Pos)

#define I2C_ICR_OVRCF_Pos         10U
#define I2C_ICR_OVRCF_Msk         (1U << I2C_ICR_OVRCF_Pos)
#define I2C_ICR_OVRCF_SET()       (1U << I2C_ICR_OVRCF_Pos)

#define I2C_ICR_PECCF_Pos         11U
#define I2C_ICR_PECCF_Msk         (1U << I2C_ICR_PECCF_Pos)
#define I2C_ICR_PECCF_SET()       (1U << I2C_ICR_PECCF_Pos)

#define I2C_ICR_TIMEOUTCF_Pos     12U
#define I2C_ICR_TIMEOUTCF_Msk     (1U << I2C_ICR_TIMEOUTCF_Pos)
#define I2C_ICR_TIMEOUTCF_SET()   (1U << I2C_ICR_TIMEOUTCF_Pos)

#define I2C_ICR_ALERTCF_Pos       13U
#define I2C_ICR_ALERTCF_Msk       (1U << I2C_ICR_ALERTCF_Pos)
#define I2C_ICR_ALERTCF_SET()     (1U << I2C_ICR_ALERTCF_Pos)


/* ------------------------------- I2C_PECR --------------------------------- */
/* Packet error checking register (offset 0x20) */
/* PECR mostly read/write bytes through helper routines; no bitfields needed here.
   Keep placeholder macros if you want to access PEC byte(s). */
#define I2C_PECR_PEC_Pos          0U
#define I2C_PECR_PEC_Msk          (0xFFU << I2C_PECR_PEC_Pos)
#define I2C_PECR_PEC(x)           (((x) & 0xFFU) << I2C_PECR_PEC_Pos)


/* ------------------------------- I2C_RXDR --------------------------------- */
/* Receive data register (offset 0x24) */
#define I2C_RXDR_RXDATA_Pos       0U
#define I2C_RXDR_RXDATA_Msk       (0xFFU << I2C_RXDR_RXDATA_Pos)
#define I2C_RXDR_RXDATA(x)        (((x) & 0xFFU) << I2C_RXDR_RXDATA_Pos)


/* ------------------------------- I2C_TXDR --------------------------------- */
/* Transmit data register (offset 0x28) */
#define I2C_TXDR_TXDATA_Pos       0U
#define I2C_TXDR_TXDATA_Msk       (0xFFU << I2C_TXDR_TXDATA_Pos)
#define I2C_TXDR_TXDATA(x)        (((x) & 0xFFU) << I2C_TXDR_TXDATA_Pos)

/*
 * Initialization of the I2C:
 * 1) Configure CR1
 * 2) Configure TIMINGR
 * 3) Configure OAR1
 * 4) Configure CR2
 */
void Driver_I2C_Init(void);



#endif /* DRIVERS_I2C_DRIVER_H_ */
