#include "memorymap.h"
#include "peripherals.h"
#include "typedefs.h"

#define FLASH_ACR_LATENCY_Pos        (0U)
#define FLASH_ACR_LATENCY_Msk        (0x7U << FLASH_ACR_LATENCY_Pos) 
#define FLASH_ACR_LATENCY            FLASH_ACR_LATENCY_Msk
#define FLASH_ACR_LATENCY_EN(x)      (((x) & 0x7U) << FLASH_ACR_LATENCY_Pos)

#define FLASH_ACR_HLFCYA_Pos        (3U)
#define FLASH_ACR_HLFCYA_Msk        (1U << FLASH_ACR_HLFCYA_Pos)
#define FLASH_ACR_HLFCYA            FLASH_ACR_HLFCYA_Msk
#define FLASH_ACR_HLFCYA_SET        (1U << FLASH_ACR_HLFCYA_Pos)

#define FLASH_ACR_PRFTBE_Pos        (4U)
#define FLASH_ACR_PRFTBE_Msk        (1U << FLASH_ACR_PRFTBE_Pos)
#define FLASH_ACR_PRFTBE            FLASH_ACR_PRFTBE_Msk
#define FLASH_ACR_PRFTBE_SET        (1U << FLASH_ACR_PRFTBE_Pos)

#define FLASH_ACR_PRFTBS_Pos        (5U)
#define FLASH_ACR_PRFTBS_Msk        (1U << FLASH_ACR_PRFTBS_Pos)
#define FLASH_ACR_PRFTBS            FLASH_ACR_PRFTBS_Msk    
#define FLASH_ACR_PRFTBS_SET        (1U << FLASH_ACR_PRFTBS_Pos)

void Driver_Init_Flash(uint8_t frequency);