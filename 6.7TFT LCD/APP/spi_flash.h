#ifndef _spi_flash_H
#define _spi_flash_H

#include "system.h"
#include "usart.h"

/*************************SPI参数定义******************************/
#define				FLASH_SPIx						SPI2
#define				FLASH_SPI_APBxClock_FUN			RCC_APB1PeriphClockCmd
#define				FLASH_SPI_CLK					RCC_APB1Periph_SPI2
#define 			FLASH_SPI_GPIO_APBxClock_FUN    RCC_APB2PeriphClockCmd

#define 			FLASH_SPI_SCK_PORT				GPIOB
#define				FLASH_SPI_SCK_PIN				GPIO_Pin_13

#define 			FLASH_SPI_MOSI_PORT				GPIOB
#define				FLASH_SPI_MOSI_PIN				GPIO_Pin_15

#define 			FLASH_SPI_MISO_PORT				GPIOB
#define				FLASH_SPI_MISO_PIN				GPIO_Pin_14


#define				FLASH_SPI_GPIO_CLK				RCC_APB2Periph_GPIOB
#define 			FLASH_SPI_CS_PORT				GPIOB
#define				FLASH_SPI_CS_PIN				GPIO_Pin_12

#define 			EN25QXX_CS 		PBout(12)

//等待超时时间
#define 			SPIT_FLAG_TIMEOUT				((uint32_t)0x1000)
#define 			SPIT_LONG_TIMEOUT				((uint32_t)(10*SPIT_FLAG_TIMEOUT))

#define 			DUMMY							0xff
#define  			READ_JEDBC_ID					0x9f
#define 			WRITE_ENABLE					0x06
#define				SECTOR_ERASE					0x20
#define 			READ_REGISTER					0x05
#define				READ_DATA						0x03
#define 			WRITE_DATA						0x02
#define 			ChipErase					0xC7 

uint8_t SPI_FLASH_Send_Byte(uint8_t data);
void SPI2_FLASH_Init();
uint32_t SPI_Read_ID();
void SPI_FLASH_Writ_Eanble();
void SPI_FLASH_Wartie_sector();
void SPI_FLASH_Sector_Erase(uint32_t addr);
void SPI_FLASH_Read_data(uint32_t addr,uint8_t* data,uint32_t numSize);
void SPI_FLASH_Write_data(uint32_t addr,uint8_t* data,uint32_t numSize);
void SPI_FLASH_Erase_Chip();
void SPI_FLASH_Write(uint32_t addr,u8* data,uint32_t numsize);
void SPI_FLASH_show_data(uint32_t addr,uint32_t numSize);

#endif
