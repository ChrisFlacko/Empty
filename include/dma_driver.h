/*
 * dma_driver.h
 *
 *  Created on: Nov 16, 2025
 *      Author: chris
 */

#ifndef DRIVERS_DMA_DRIVER_H_
#define DRIVERS_DMA_DRIVER_H_

#include "memorymap.h"
#include "peripherals.h"
#include "typedefs.h"


/* DMA_CCRx --------------------------------------------------- */
#define DMA_CCR_EN_Pos            0U
#define DMA_CCR_EN_Msk            (1U << DMA_CCR_EN_Pos)
#define DMA_CCR_EN                DMA_CCR_EN_Msk
#define DMA_CCR_EN_SET()          (1U << DMA_CCR_EN_Pos)

#define DMA_CCR_TCIE_Pos          1U
#define DMA_CCR_TCIE_Msk          (1U << DMA_CCR_TCIE_Pos)
#define DMA_CCR_TCIE              DMA_CCR_TCIE_Msk
#define DMA_CCR_TCIE_SET()        (1U << DMA_CCR_TCIE_Pos)

#define DMA_CCR_HTIE_Pos          2U
#define DMA_CCR_HTIE_Msk          (1U << DMA_CCR_HTIE_Pos)
#define DMA_CCR_HTIE              DMA_CCR_HTIE_Msk
#define DMA_CCR_HTIE_SET()        (1U << DMA_CCR_HTIE_Pos)

#define DMA_CCR_TEIE_Pos          3U
#define DMA_CCR_TEIE_Msk          (1U << DMA_CCR_TEIE_Pos)
#define DMA_CCR_TEIE              DMA_CCR_TEIE_Msk
#define DMA_CCR_TEIE_SET()        (1U << DMA_CCR_TEIE_Pos)

#define DMA_CCR_DIR_Pos           4U
#define DMA_CCR_DIR_Msk           (1U << DMA_CCR_DIR_Pos)
#define DMA_CCR_DIR               DMA_CCR_DIR_Msk
#define DMA_CCR_DIR_SET()         (1U << DMA_CCR_DIR_Pos)

#define DMA_CCR_CIRC_Pos          5U
#define DMA_CCR_CIRC_Msk          (1U << DMA_CCR_CIRC_Pos)
#define DMA_CCR_CIRC              DMA_CCR_CIRC_Msk
#define DMA_CCR_CIRC_SET()        (1U << DMA_CCR_CIRC_Pos)

#define DMA_CCR_PINC_Pos          6U
#define DMA_CCR_PINC_Msk          (1U << DMA_CCR_PINC_Pos)
#define DMA_CCR_PINC              DMA_CCR_PINC_Msk
#define DMA_CCR_PINC_SET()        (1U << DMA_CCR_PINC_Pos)

#define DMA_CCR_MINC_Pos          7U
#define DMA_CCR_MINC_Msk          (1U << DMA_CCR_MINC_Pos)
#define DMA_CCR_MINC              DMA_CCR_MINC_Msk
#define DMA_CCR_MINC_SET()        (1U << DMA_CCR_MINC_Pos)

/* PSIZE[1:0] — Peripheral size */
#define DMA_CCR_PSIZE_Pos         8U
#define DMA_CCR_PSIZE_Msk         (0x3U << DMA_CCR_PSIZE_Pos)
#define DMA_CCR_PSIZE(x)          (((x)&0x3U) << DMA_CCR_PSIZE_Pos)

/* MSIZE[1:0] — Memory size */
#define DMA_CCR_MSIZE_Pos         10U
#define DMA_CCR_MSIZE_Msk         (0x3U << DMA_CCR_MSIZE_Pos)
#define DMA_CCR_MSIZE(x)          (((x)&0x3U) << DMA_CCR_MSIZE_Pos)

/* PL[1:0] — Priority level */
#define DMA_CCR_PL_Pos            12U
#define DMA_CCR_PL_Msk            (0x3U << DMA_CCR_PL_Pos)
#define DMA_CCR_PL(x)             (((x)&0x3U) << DMA_CCR_PL_Pos)

#define DMA_CCR_MEM2MEM_Pos       14U
#define DMA_CCR_MEM2MEM_Msk       (1U << DMA_CCR_MEM2MEM_Pos)
#define DMA_CCR_MEM2MEM           DMA_CCR_MEM2MEM_Msk
#define DMA_CCR_MEM2MEM_SET()     (1U << DMA_CCR_MEM2MEM_Pos)

/* DMA_CNDTRx ------------------------------------------------- */
#define DMA_CNDTR_NDT_Pos         0U
#define DMA_CNDTR_NDT_Msk         (0xFFFFU << DMA_CNDTR_NDT_Pos)
#define DMA_CNDTR_NDT(x)          (((x) & 0xFFFFU) << DMA_CNDTR_NDT_Pos)

/* DMA_CPARx -------------------------------------------------- */
#define DMA_CPAR_PA_Pos           0U
#define DMA_CPAR_PA_Msk           (0xFFFFFFFFU << DMA_CPAR_PA_Pos)
#define DMA_CPAR_PA(x)            (((uint32_t)(x)) << DMA_CPAR_PA_Pos)

/* DMA_CMARx -------------------------------------------------- */
#define DMA_CMAR_MA_Pos           0U
#define DMA_CMAR_MA_Msk           (0xFFFFFFFFU << DMA_CMAR_MA_Pos)
#define DMA_CMAR_MA(x)            (((uint32_t)(x)) << DMA_CMAR_MA_Pos)

/* DMA_ISR ----------------------------------------------------- */
/* Channel 1 */
#define DMA_ISR_GIF1_Pos          0U
#define DMA_ISR_GIF1_Msk          (1U << DMA_ISR_GIF1_Pos)
#define DMA_ISR_GIF1              DMA_ISR_GIF1_Msk

#define DMA_ISR_TCIF1_Pos         1U
#define DMA_ISR_TCIF1_Msk         (1U << DMA_ISR_TCIF1_Pos)
#define DMA_ISR_TCIF1             DMA_ISR_TCIF1_Msk

#define DMA_ISR_HTIF1_Pos         2U
#define DMA_ISR_HTIF1_Msk         (1U << DMA_ISR_HTIF1_Pos)
#define DMA_ISR_HTIF1             DMA_ISR_HTIF1_Msk

#define DMA_ISR_TEIF1_Pos         3U
#define DMA_ISR_TEIF1_Msk         (1U << DMA_ISR_TEIF1_Pos)
#define DMA_ISR_TEIF1             DMA_ISR_TEIF1_Msk

/* Channel 2 */
#define DMA_ISR_GIF2_Pos          4U
#define DMA_ISR_GIF2_Msk          (1U << DMA_ISR_GIF2_Pos)
#define DMA_ISR_GIF2              DMA_ISR_GIF2_Msk

#define DMA_ISR_TCIF2_Pos         5U
#define DMA_ISR_TCIF2_Msk         (1U << DMA_ISR_TCIF2_Pos)
#define DMA_ISR_TCIF2             DMA_ISR_TCIF2_Msk

#define DMA_ISR_HTIF2_Pos         6U
#define DMA_ISR_HTIF2_Msk         (1U << DMA_ISR_HTIF2_Pos)
#define DMA_ISR_HTIF2             DMA_ISR_HTIF2_Msk

#define DMA_ISR_TEIF2_Pos         7U
#define DMA_ISR_TEIF2_Msk         (1U << DMA_ISR_TEIF2_Pos)
#define DMA_ISR_TEIF2             DMA_ISR_TEIF2_Msk

/* Channel 3 */
#define DMA_ISR_GIF3_Pos          8U
#define DMA_ISR_GIF3_Msk          (1U << DMA_ISR_GIF3_Pos)
#define DMA_ISR_GIF3              DMA_ISR_GIF3_Msk

#define DMA_ISR_TCIF3_Pos         9U
#define DMA_ISR_TCIF3_Msk         (1U << DMA_ISR_TCIF3_Pos)
#define DMA_ISR_TCIF3             DMA_ISR_TCIF3_Msk

#define DMA_ISR_HTIF3_Pos         10U
#define DMA_ISR_HTIF3_Msk         (1U << DMA_ISR_HTIF3_Pos)
#define DMA_ISR_HTIF3             DMA_ISR_HTIF3_Msk

#define DMA_ISR_TEIF3_Pos         11U
#define DMA_ISR_TEIF3_Msk         (1U << DMA_ISR_TEIF3_Pos)
#define DMA_ISR_TEIF3             DMA_ISR_TEIF3_Msk

/* Channel 4 */
#define DMA_ISR_GIF4_Pos          12U
#define DMA_ISR_GIF4_Msk          (1U << DMA_ISR_GIF4_Pos)
#define DMA_ISR_GIF4              DMA_ISR_GIF4_Msk

#define DMA_ISR_TCIF4_Pos         13U
#define DMA_ISR_TCIF4_Msk         (1U << DMA_ISR_TCIF4_Pos)
#define DMA_ISR_TCIF4             DMA_ISR_TCIF4_Msk

#define DMA_ISR_HTIF4_Pos         14U
#define DMA_ISR_HTIF4_Msk         (1U << DMA_ISR_HTIF4_Pos)
#define DMA_ISR_HTIF4             DMA_ISR_HTIF4_Msk

#define DMA_ISR_TEIF4_Pos         15U
#define DMA_ISR_TEIF4_Msk         (1U << DMA_ISR_TEIF4_Pos)
#define DMA_ISR_TEIF4             DMA_ISR_TEIF4_Msk

/* Channel 5 */
#define DMA_ISR_GIF5_Pos          16U
#define DMA_ISR_GIF5_Msk          (1U << DMA_ISR_GIF5_Pos)
#define DMA_ISR_GIF5              DMA_ISR_GIF5_Msk

#define DMA_ISR_TCIF5_Pos         17U
#define DMA_ISR_TCIF5_Msk         (1U << DMA_ISR_TCIF5_Pos)
#define DMA_ISR_TCIF5             DMA_ISR_TCIF5_Msk

#define DMA_ISR_HTIF5_Pos         18U
#define DMA_ISR_HTIF5_Msk         (1U << DMA_ISR_HTIF5_Pos)
#define DMA_ISR_HTIF5             DMA_ISR_HTIF5_Msk

#define DMA_ISR_TEIF5_Pos         19U
#define DMA_ISR_TEIF5_Msk         (1U << DMA_ISR_TEIF5_Pos)
#define DMA_ISR_TEIF5             DMA_ISR_TEIF5_Msk

/* Channel 6 */
#define DMA_ISR_GIF6_Pos          20U
#define DMA_ISR_GIF6_Msk          (1U << DMA_ISR_GIF6_Pos)
#define DMA_ISR_GIF6              DMA_ISR_GIF6_Msk

#define DMA_ISR_TCIF6_Pos         21U
#define DMA_ISR_TCIF6_Msk         (1U << DMA_ISR_TCIF6_Pos)
#define DMA_ISR_TCIF6             DMA_ISR_TCIF6_Msk

#define DMA_ISR_HTIF6_Pos         22U
#define DMA_ISR_HTIF6_Msk         (1U << DMA_ISR_HTIF6_Pos)
#define DMA_ISR_HTIF6             DMA_ISR_HTIF6_Msk

#define DMA_ISR_TEIF6_Pos         23U
#define DMA_ISR_TEIF6_Msk         (1U << DMA_ISR_TEIF6_Pos)
#define DMA_ISR_TEIF6             DMA_ISR_TEIF6_Msk

/* Channel 7 */
#define DMA_ISR_GIF7_Pos          24U
#define DMA_ISR_GIF7_Msk          (1U << DMA_ISR_GIF7_Pos)
#define DMA_ISR_GIF7              DMA_ISR_GIF7_Msk

#define DMA_ISR_TCIF7_Pos         25U
#define DMA_ISR_TCIF7_Msk         (1U << DMA_ISR_TCIF7_Pos)
#define DMA_ISR_TCIF7             DMA_ISR_TCIF7_Msk

#define DMA_ISR_HTIF7_Pos         26U
#define DMA_ISR_HTIF7_Msk         (1U << DMA_ISR_HTIF7_Pos)
#define DMA_ISR_HTIF7             DMA_ISR_HTIF7_Msk

#define DMA_ISR_TEIF7_Pos         27U
#define DMA_ISR_TEIF7_Msk         (1U << DMA_ISR_TEIF7_Pos)
#define DMA_ISR_TEIF7             DMA_ISR_TEIF7_Msk

/* DMA_IFCR ---------------------------------------------------- */
/* Channel 1 */
#define DMA_IFCR_CGIF1_Pos        0U
#define DMA_IFCR_CGIF1_Msk        (1U << DMA_IFCR_CGIF1_Pos)
#define DMA_IFCR_CGIF1_SET()      (1U << DMA_IFCR_CGIF1_Pos)

#define DMA_IFCR_CTCIF1_Pos       1U
#define DMA_IFCR_CTCIF1_Msk       (1U << DMA_IFCR_CTCIF1_Pos)
#define DMA_IFCR_CTCIF1_SET()     (1U << DMA_IFCR_CTCIF1_Pos)

#define DMA_IFCR_CHTIF1_Pos       2U
#define DMA_IFCR_CHTIF1_Msk       (1U << DMA_IFCR_CHTIF1_Pos)
#define DMA_IFCR_CHTIF1_SET()     (1U << DMA_IFCR_CHTIF1_Pos)

#define DMA_IFCR_CTEIF1_Pos       3U
#define DMA_IFCR_CTEIF1_Msk       (1U << DMA_IFCR_CTEIF1_Pos)
#define DMA_IFCR_CTEIF1_SET()     (1U << DMA_IFCR_CTEIF1_Pos)

/* ... identisch bis Channel 7 ... */

void Driver_DMA_Start(uint32_t* address);

#endif /* DRIVERS_DMA_DRIVER_H_ */
