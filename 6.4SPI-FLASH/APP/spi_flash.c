#include "spi_flash.h"



static uint32_t SPITimeout = SPIT_LONG_TIMEOUT;
static uint32_t SPI_TIMOUT_UserCallback(uint8_t errorCode);



/**
  *SPI I/O配置
  *
  *
  */
static void SPI_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_Initstructure;
	
	/*使能与SPI相关的时钟*/
	FLASH_SPI_APBxClock_FUN(FLASH_SPI_CLK,ENABLE);
	FLASH_SPI_GPIO_APBxClock_FUN(FLASH_SPI_GPIO_CLK,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOG,ENABLE);
	
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Initstructure.GPIO_Pin=FLASH_SPI_SCK_PIN;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(FLASH_SPI_SCK_PORT,&GPIO_Initstructure);
	
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Initstructure.GPIO_Pin=FLASH_SPI_MOSI_PIN;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(FLASH_SPI_MOSI_PORT,&GPIO_Initstructure);
	
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Initstructure.GPIO_Pin=FLASH_SPI_MISO_PIN;
	GPIO_Init(FLASH_SPI_MISO_PORT,&GPIO_Initstructure);
	/*初始化CS引脚，使用软件控制*/
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Pin=FLASH_SPI_CS_PIN;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(FLASH_SPI_CS_PORT,&GPIO_Initstructure);
	
	EN25QXX_CS=1;
	
	
	GPIO_Initstructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_Initstructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOG, &GPIO_Initstructure);//初始化
	GPIO_SetBits(GPIOG,GPIO_Pin_7);
}


/**
  *SPI 模式配置
  *
  *
  */

static void SPI_Mode_Config()
{
	SPI_InitTypeDef SPI_InitTstructure;
	
	SPI_InitTstructure.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_2;
	SPI_InitTstructure.SPI_CPHA=SPI_CPHA_2Edge;
	SPI_InitTstructure.SPI_CPOL=SPI_CPOL_High;
	SPI_InitTstructure.SPI_CRCPolynomial=7;
	SPI_InitTstructure.SPI_DataSize=SPI_DataSize_8b;
	SPI_InitTstructure.SPI_Direction=SPI_Direction_2Lines_FullDuplex;
	SPI_InitTstructure.SPI_FirstBit=SPI_FirstBit_MSB;
	SPI_InitTstructure.SPI_Mode=SPI_Mode_Master;
	SPI_InitTstructure.SPI_NSS=SPI_NSS_Soft;
	SPI_Init(FLASH_SPIx,&SPI_InitTstructure);
	
	SPI_Cmd(FLASH_SPIx,ENABLE);
}

/**
  *SPI 初始化函数
  *
  *
  */

void SPI2_FLASH_Init()
{
	SPI_GPIO_Config();
	SPI_Mode_Config();
}

/**
*SPI 发送并接受一个字节
  *
  *
  */
uint8_t SPI_FLASH_Send_Byte(uint8_t data)
{
	//SPITimeout=SPIT_FLAG_TIMEOUT;
	
	//检查并等待TX缓冲区为空
	while(SPI_I2S_GetFlagStatus(FLASH_SPIx,SPI_I2S_FLAG_TXE)==RESET);
	
	//程序执行到此处说明缓冲区已经为空，可以发送一个字节
	SPI_I2S_SendData(FLASH_SPIx,data);
	
	//等待接受完一个字节
	while(SPI_I2S_GetFlagStatus(FLASH_SPIx,SPI_I2S_FLAG_RXNE)==RESET);
	
	//返回接受到的字节
	return SPI_I2S_ReceiveData(FLASH_SPIx);
}


uint8_t SPI_FLASH_Read_Byte()
{
	return SPI_FLASH_Send_Byte(DUMMY);
}


uint32_t SPI_Read_ID()
{
	u32 flash_id=0;
	
	EN25QXX_CS=0;
	SPI_FLASH_Send_Byte(READ_JEDBC_ID);
	
	flash_id = SPI_FLASH_Send_Byte(DUMMY);
	flash_id <<= 8;
	
	
	flash_id |= SPI_FLASH_Send_Byte(DUMMY);
	flash_id <<= 8;
	
	flash_id |= SPI_FLASH_Send_Byte(DUMMY);
	
	
	EN25QXX_CS=1;
	
	return flash_id;
}
//写使能
void SPI_FLASH_Writ_Eanble()
{
	//FLASH_SPI_CS_LOW;
	EN25QXX_CS=0;
	SPI_FLASH_Send_Byte(WRITE_ENABLE);
	EN25QXX_CS=1;
	//FLASH_SPI_CS_HIGH;
}

//等待擦除完成

void SPI_FLASH_Wartie_sector()
{
	uint8_t tmp=0;
	EN25QXX_CS=0;
	SPI_FLASH_Send_Byte(READ_REGISTER);
	do
	{
		tmp=SPI_FLASH_Send_Byte(DUMMY);
	}while((tmp&0x01)==1);
	EN25QXX_CS=1;
}

//擦除FLASH指定扇区
void SPI_FLASH_Sector_Erase(uint32_t addr)
{
	SPI_FLASH_Writ_Eanble();
	SPI_FLASH_Wartie_sector();
	EN25QXX_CS=0;
	SPI_FLASH_Send_Byte(SECTOR_ERASE);
	SPI_FLASH_Send_Byte((u8)(addr>>16));
	SPI_FLASH_Send_Byte((u8)(addr>>8));
	SPI_FLASH_Send_Byte((u8)(addr));
	EN25QXX_CS=1;
	SPI_FLASH_Wartie_sector();
}

//读取FLASH内容

void SPI_FLASH_Read_data(uint32_t addr,uint8_t* data,uint32_t numSize)
{
	uint32_t i=0;
	EN25QXX_CS=0;
	SPI_FLASH_Send_Byte(READ_DATA);
	SPI_FLASH_Send_Byte((u8)(addr>>16));
	SPI_FLASH_Send_Byte((u8)(addr>>8));
	SPI_FLASH_Send_Byte((u8)(addr));
	for(i=0;i<numSize;i++)
	{
		data[i]=SPI_FLASH_Send_Byte(DUMMY);
	}
	EN25QXX_CS=1;
}

//写入
void SPI_FLASH_Write_data(uint32_t addr,uint8_t* data,uint32_t numSize)
{
	uint32_t i=0;
	SPI_FLASH_Writ_Eanble();
	EN25QXX_CS=0;
	SPI_FLASH_Send_Byte(WRITE_DATA);
	SPI_FLASH_Send_Byte((u8)(addr>>16));
	SPI_FLASH_Send_Byte((u8)(addr>>8));
	SPI_FLASH_Send_Byte((u8)(addr));
	for(i=0;i<numSize;i++)
	{
		SPI_FLASH_Send_Byte(data[i]);
	}
	EN25QXX_CS=1;
	SPI_FLASH_Wartie_sector();
}

//擦除整个扇区
void SPI_FLASH_Erase_Chip()
{
	SPI_FLASH_Writ_Eanble();
	SPI_FLASH_Wartie_sector();
	EN25QXX_CS=0;
	SPI_FLASH_Send_Byte(ChipErase);
	EN25QXX_CS=1;
	SPI_FLASH_Wartie_sector();
}

void SPI_FLASH_Write_NoCheck(uint32_t addr,u8* data,uint32_t numsize)
{
	u16 pageremain=0;
	pageremain=256-addr%256;
	if(numsize<=pageremain)
		pageremain=numsize;
	while(1)
	{
		SPI_FLASH_Write_data(addr,data,pageremain);
		if(pageremain==numsize)
			break;
		else
		{
			data+=pageremain;
			addr+=pageremain;
			numsize-=pageremain;
			if(numsize>256)
			{
				pageremain=256;
			}
			else
			{
				pageremain=numsize;
			}
		}
	}
}

u8 BUFFER[4096];
void SPI_FLASH_Write(uint32_t addr,u8* data,uint32_t numsize)
{
	u32 secpos=0;
	u16 secoff=0;
	u16 secremain=0;
	u16 i=0;
	u8* Buf;
	Buf=BUFFER;
	secpos=addr/4096;
	secoff=addr%4096;
	secremain=4096-secoff;
	if(numsize<=secremain)
		secremain=numsize;
	while(1)
	{
		SPI_FLASH_Read_data(secpos*4096,Buf,4096);
		for(i=0;i<secremain;i++)
		{
			if(Buf[i+secoff]!=0xff)
				break;
		}
		if(i<secremain)
		{
			SPI_FLASH_Sector_Erase(secpos);
			for(i=0;i<secremain;i++)
			{
				Buf[i+secoff]=data[i];
			}
			SPI_FLASH_Write_NoCheck(secpos*4096,Buf,4096);
		}
		else
		{
			SPI_FLASH_Write_NoCheck(addr,data,secremain);
		}
		if(secremain==numsize)
		{
			break;
		}
		else
		{
			secpos++;
			secoff=0;
			data+=secremain;
			addr+=secremain;
			numsize-=secremain;
			if(numsize>4096)
			{
				secremain=4096;
			}
			else
			{
				secremain=numsize;
			}
		}
	}
}

static uint32_t SPI_TIMOUT_UserCallback(uint8_t errorCode)
{
	printf("SPI 等待超时！errorCode = %d\r\n",errorCode);
	return 0;
}

