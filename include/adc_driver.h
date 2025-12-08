/*
 * adc_driver.h
 *
 *  Created on: Nov 23, 2025
 *      Author: chris
 */

#ifndef DRIVERS_ADC_DRIVER_H_
#define DRIVERS_ADC_DRIVER_H_

#include "memorymap.h"
#include "peripherals.h"
#include "typedefs.h"

/* ADC_CCR: Prescaler */
#define ADC_CCR_PRESC_Pos        18U
#define ADC_CCR_PRESC_Msk        (0x3U << ADC_CCR_PRESC_Pos)
#define ADC_CCR_PRESC(x)         ((x) << ADC_CCR_PRESC_Pos)

/* ADC_CCR: MULTIMODE */
#define ADC_CCR_MULTI_Pos        0U
#define ADC_CCR_MULTI_Msk        (0x1FU << ADC_CCR_MULTI_Pos)
#define ADC_CCR_MULTI(x)         ((x) << ADC_CCR_MULTI_Pos)

/* ADEN: ADC Enable */
#define ADC_CR_ADEN_Pos          0U
#define ADC_CR_ADEN_Msk          (1U << ADC_CR_ADEN_Pos)
#define ADC_CR_ADEN_SET()        (1U << ADC_CR_ADEN_Pos)

/* ADDIS: ADC Disable */
#define ADC_CR_ADDIS_Pos         1U
#define ADC_CR_ADDIS_Msk         (1U << ADC_CR_ADDIS_Pos)
#define ADC_CR_ADDIS_SET()       (1U << ADC_CR_ADDIS_Pos)

/* ADSTART: Start regular conversion */
#define ADC_CR_ADSTART_Pos       2U
#define ADC_CR_ADSTART_Msk       (1U << ADC_CR_ADSTART_Pos)
#define ADC_CR_ADSTART_SET()     (1U << ADC_CR_ADSTART_Pos)

/* JADSTART: Start injected conversion */
#define ADC_CR_JADSTART_Pos      3U
#define ADC_CR_JADSTART_Msk      (1U << ADC_CR_JADSTART_Pos)
#define ADC_CR_JADSTART_SET()    (1U << ADC_CR_JADSTART_Pos)

/* ADSTP: Stop regular conversion */
#define ADC_CR_ADSTP_Pos         4U
#define ADC_CR_ADSTP_Msk         (1U << ADC_CR_ADSTP_Pos)
#define ADC_CR_ADSTP_SET()       (1U << ADC_CR_ADSTP_Pos)

/* JADSTP: Stop injected conversion */
#define ADC_CR_JADSTP_Pos        5U
#define ADC_CR_JADSTP_Msk        (1U << ADC_CR_JADSTP_Pos)
#define ADC_CR_JADSTP_SET()      (1U << ADC_CR_JADSTP_Pos)

/* ADVREGEN: Voltage regulator */
#define ADC_CR_ADVREGEN_Pos      28U
#define ADC_CR_ADVREGEN_Msk      (1U << ADC_CR_ADVREGEN_Pos)
#define ADC_CR_ADVREGEN_SET()    (1U << ADC_CR_ADVREGEN_Pos)

/* ADRDY: Ready */
#define ADC_ISR_ADRDY_Pos        0U
#define ADC_ISR_ADRDY_Msk        (1U << ADC_ISR_ADRDY_Pos)
#define ADC_ISR_ADRDY_SET()      (1U << ADC_ISR_ADRDY_Pos)

/* EOSMP: End of sampling */
#define ADC_ISR_EOSMP_Pos        1U
#define ADC_ISR_EOSMP_Msk        (1U << ADC_ISR_EOSMP_Pos)
#define ADC_ISR_EOSMP_SET()      (1U << ADC_ISR_EOSMP_Pos)

/* EOC: End of regular conversion */
#define ADC_ISR_EOC_Pos          2U
#define ADC_ISR_EOC_Msk          (1U << ADC_ISR_EOC_Pos)
#define ADC_ISR_EOC_SET()        (1U << ADC_ISR_EOC_Pos)

/* EOS: End of sequence */
#define ADC_ISR_EOS_Pos          3U
#define ADC_ISR_EOS_Msk          (1U << ADC_ISR_EOS_Pos)
#define ADC_ISR_EOS_SET()        (1U << ADC_ISR_EOS_Pos)

/* OVR: Overrun */
#define ADC_ISR_OVR_Pos          4U
#define ADC_ISR_OVR_Msk          (1U << ADC_ISR_OVR_Pos)
#define ADC_ISR_OVR_SET()        (1U << ADC_ISR_OVR_Pos)

#define ADC_IER_ADRDYIE_Pos      0U
#define ADC_IER_ADRDYIE_Msk      (1U << ADC_IER_ADRDYIE_Pos)
#define ADC_IER_ADRDYIE_SET()    (1U << ADC_IER_ADRDYIE_Pos)

#define ADC_IER_EOCIE_Pos        2U
#define ADC_IER_EOCIE_Msk        (1U << ADC_IER_EOCIE_Pos)
#define ADC_IER_EOCIE_SET()      (1U << ADC_IER_EOCIE_Pos)

#define ADC_IER_OVRIE_Pos        4U
#define ADC_IER_OVRIE_Msk        (1U << ADC_IER_OVRIE_Pos)
#define ADC_IER_OVRIE_SET()      (1U << ADC_IER_OVRIE_Pos)

#define ADC_SMPR1_SMP0_Pos       0U
#define ADC_SMPR1_SMP0_Msk       (0x7U << ADC_SMPR1_SMP0_Pos)
#define ADC_SMPR1_SMP0(x)        ((x) << ADC_SMPR1_SMP0_Pos)

/* Kanal 1 */
#define ADC_SMPR1_SMP1_Pos       3U
#define ADC_SMPR1_SMP1_Msk       (0x7U << ADC_SMPR1_SMP1_Pos)
#define ADC_SMPR1_SMP1(x)        ((x) << ADC_SMPR1_SMP1_Pos)

/* L: sequence length */
#define ADC_SQR1_L_Pos           0U
#define ADC_SQR1_L_Msk           (0xFU << ADC_SQR1_L_Pos)
#define ADC_SQR1_L(x)            ((x) << ADC_SQR1_L_Pos)

/* SQ1: first channel */
#define ADC_SQR1_SQ1_Pos         6U
#define ADC_SQR1_SQ1_Msk         (0x1FU << ADC_SQR1_SQ1_Pos)
#define ADC_SQR1_SQ1(x)          ((x) << ADC_SQR1_SQ1_Pos)

void Driver_ADC_Init(void);

#endif /* DRIVERS_ADC_DRIVER_H_ */
