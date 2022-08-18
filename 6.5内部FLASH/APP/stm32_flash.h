#ifndef _stm32_flash_H
#define _stm32_flash_H

#include "system.h"
#include "usart.h"

#define STM32_FLASH_BASE   0x08000000
#define STM32_FLASH_SIZE   512
#define STM32_FLASH_SECTOR 2048

void STM32_FLASH_Read(u32 addr,u16* buf,u16 num);
void STM32_FLASH_Write(u32 addr,u16* buf,u16 num);


#endif