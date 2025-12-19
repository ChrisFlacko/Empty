#include "memorymap.h"
#include "peripherals.h"
#include "typedefs.h"


/*---------------------------------------------- Basic Timers TIM6/7 -------------------------------------------------------------*/
#define BASIC_TIM_CR1_UIFREMAP_POS        11U
#define BASIC_TIM_CR1_UIFREMAP_MSK        (1U << BASIC_TIM_CR1_UIFREMAP_POS)
#define BASIC_TIM_CR1_UIFREMAP_EN         (BASIC_TIM_CR1_UIFREMAP_MSK)
#define BASIC_TIM_CR1_ARPE_POS          7U
#define BASIC_TIM_CR1_ARPE_MSK          (1U << BASIC_TIM_CR1_ARPE_POS)
#define BASIC_TIM_CR1_ARPE_EN           (BASIC_TIM_CR1_ARPE_MSK)
#define BASIC_TIM_CR1_OPM_POS            3U
#define BASIC_TIM_CR1_OPM_MSK            (1U << BASIC_TIM_CR1_OPM_POS)
#define BASIC_TIM_CR1_OPM_EN             (BASIC_TIM_CR1_OPM_MSK)
#define BASIC_TIM_CR1_URS_POS            2U
#define BASIC_TIM_CR1_URS_MSK            (1U << BASIC_TIM_CR1_URS_POS)
#define BASIC_TIM_CR1_URS_EN             (BASIC_TIM_CR1_URS_MSK)
#define BASIC_TIM_CR1_UDIS_POS           1U
#define BASIC_TIM_CR1_UDIS_MSK           (1U << BASIC_TIM_CR1_UDIS_POS)
#define BASIC_TIM_CR1_UDIS_EN            (BASIC_TIM_CR1_UDIS_MSK)
#define BASIC_TIM_CR1_CEN_POS            0U
#define BASIC_TIM_CR1_CEN_MSK            (1U << BASIC_TIM_CR1_CEN_POS)
#define BASIC_TIM_CR1_CEN_EN             (BASIC_TIM_CR1_CEN_MSK)

/* CR2 - Control Register 2 */
#define BASIC_TIM_CR2_MMS_POS            4U      /* Master Mode Selection */
#define BASIC_TIM_CR2_MMS_MSK            (7U << BASIC_TIM_CR2_MMS_POS)  /* Bits [6:4] */


/* DIER - DMA/Interrupt Enable Register */
#define BASIC_TIM_DIER_UDE_POS           8U      /* Update DMA Request Enable */
#define BASIC_TIM_DIER_UDE_MSK           (1U << BASIC_TIM_DIER_UDE_POS)  /* Bit 8 */
#define BASIC_TIM_DIER_UDE_EN            (BASIC_TIM_DIER_UDE_MSK)
#define BASIC_TIM_DIER_UIE_POS           0U      /* Update Interrupt Enable */
#define BASIC_TIM_DIER_UIE_MSK           (1U << BASIC_TIM_DIER_UIE_POS)  /* Bit 0 */
#define BASIC_TIM_DIER_UIE_EN            (BASIC_TIM_DIER_UIE_MSK)

/* SR - Status Register */
#define BASIC_TIM_SR_UIF_POS             0U      /* Update Interrupt Flag */
#define BASIC_TIM_SR_UIF_MSK             (1U << BASIC_TIM_SR_UIF_POS)   /* Bit 0 */
#define BASIC_TIM_SR_UIF_EN              (BASIC_TIM_SR_UIF_MSK)

/* EGR - Event Generation Register */
#define BASIC_TIM_EGR_UG_POS             0U      /* Update Generation */
#define BASIC_TIM_EGR_UG_MSK             (1U << BASIC_TIM_EGR_UG_POS)   /* Bit 0 */
#define BASIC_TIM_EGR_UG_EN              (BASIC_TIM_EGR_UG_MSK)

/* CNT - Counter Register */
#define BASIC_TIM_CNT_POS                0U      /* Counter Value */
#define BASIC_TIM_CNT_MSK                (0xFFFFU << BASIC_TIM_CNT_POS)  /* Bits [15:0] */

/* PSC - Prescaler Register */
#define BASIC_TIM_PSC_POS                0U      /* Prescaler Value */
#define BASIC_TIM_PSC_MSK                (0xFFFFU << BASIC_TIM_PSC_POS)  /* Bits [15:0] */
#define BASIC_TIM_PSC_SET(x)             ((x << BASIC_TIM_PSC_POS) & BASIC_TIM_PSC_MSK)

/* ARR - Auto-Reload Register */
#define BASIC_TIM_ARR_POS                0U      /* Auto-Reload Value */
#define BASIC_TIM_ARR_MSK                (0xFFFFU << BASIC_TIM_ARR_POS)  /* Bits [15:0] */
/*------------------------------------------------------------------------------------------------------------------------------------*/



/*---------------------------------------------- Functions ---------------------------------------------------------------------------*/
void Timer6_Init(void);
void Timer2_Init(void);
/*------------------------------------------------------------------------------------------------------------------------------------*/


/*---------------------------------------------- Independent Watchdog (IWDG) -------------------------------------------------------*/
#define IWDG_KR_POS        0U
#define IWDG_KR_MSK        (0xFFFFU << IWDG_KR_POS)
#define IWDG_KR_START_EN   (0xCCCCU << IWDG_KR_POS)
#define IWDG_KR_UNLOCK_EN  (0x5555U << IWDG_KR_POS)
#define IWDG_KR_RELOAD_EN  (0xAAAAU << IWDG_KR_POS)

#define IWDG_PR_POS       0U
#define IWDG_PR_MSK       (0x7U << IWDG_PR_POS)
#define IWDG_PR_EN(x)     (((x) & 0x7U) << IWDG_PR_POS)  

#define IWDG_RLR_POS      0U
#define IWDG_RLR_MSK      (0xFFFU << IWDG_RLR_POS)
#define IWDG_RLR_EN(x)    (((x) & 0xFFFU) << IWDG_RLR_POS)

#define IWDG_WINR_POS    0U
#define IWDG_WINR_MSK    (0xFFFU << IWDG_WINR_POS)
#define IWDG_WINR_EN(x)  (((x) & 0xFFFU) << IWDG_WINR_POS)

typedef enum
{
    IWDG_Prescaler_4   = 0U,
    IWDG_Prescaler_8   = 1U,
    IWDG_Prescaler_16  = 2U,
    IWDG_Prescaler_32  = 3U,
    IWDG_Prescaler_64  = 4U,
    IWDG_Prescaler_128 = 5U,
    IWDG_Prescaler_256 = 6U
}IWDG_Prescaler_TypeDef;

/*---------------------------------------------- Functions ---------------------------------------------------------------------------*/
void Driver_IWDG_Init(IWDG_Prescaler_TypeDef prescaler, uint16_t reload);
/*------------------------------------------------------------------------------------------------------------------------------------*/
