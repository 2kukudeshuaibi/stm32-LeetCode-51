#include "oled.h"
#include "oled_font.h"

void OLED_I2C_Init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
 	GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
 	GPIO_Init(GPIOD, &GPIO_InitStructure);
	IIC_SCL=1;
	IIC_SDA=1;
}

void OLED_I2C_Start(void)
{
	IIC_SDA=1;
	IIC_SCL=1;
	delay_us(5);
	IIC_SDA=0;
	IIC_SCL=0;
}


void OLED_I2C_Stop(void)
{
	IIC_SDA=0;
	IIC_SCL=1;
	delay_us(5);
	IIC_SDA=1;
}


void OLED_I2C_SendByte(uint8_t Byte)
{
	u8 i=0;
	IIC_SCL=0;
	for(i=0;i<8;i++)
	{
		if(Byte&(0x80>>i))
		{
			IIC_SDA=1;
		}
		else
		{
			IIC_SDA=0;
		}
		delay_us(5);
		IIC_SCL=1;
		delay_us(5);
		IIC_SCL=0;
	}
	IIC_SCL=1;
	delay_us(5);
	IIC_SCL=0;
}




/**
  * @brief  OLED写命令
  * @param  Command 要写入的命令
  * @retval 无
  */
void OLED_WriteCommand(uint8_t Command)
{
	OLED_I2C_Start();
	OLED_I2C_SendByte(0x78);		//从机地址
	OLED_I2C_SendByte(0x00);		//写命令
	OLED_I2C_SendByte(Command); 
	OLED_I2C_Stop();
}

/**
  * @brief  OLED写数据
  * @param  Data 要写入的数据
  * @retval 无
  */
void OLED_WriteData(uint8_t Data)
{
	OLED_I2C_Start();
	OLED_I2C_SendByte(0x78);		//从机地址
	OLED_I2C_SendByte(0x40);		//写数据
	OLED_I2C_SendByte(Data);
	OLED_I2C_Stop();
}

/**
  * @brief  OLED设置光标位置
  * @param  Y 以左上角为原点，向下方向的坐标，范围：0~7
  * @param  X 以左上角为原点，向右方向的坐标，范围：0~127
  * @retval 无
  */
void OLED_SetCursor(uint8_t Y, uint8_t X)
{
	OLED_WriteCommand(0xB0 | Y);					//设置Y位置
	OLED_WriteCommand(0x10 | ((X & 0xF0) >> 4));	//设置X位置低4位
	OLED_WriteCommand(0x00 | (X & 0x0F));			//设置X位置高4位
}

/**
  * @brief  OLED清屏
  * @param  无
  * @retval 无
  */
void OLED_Clear(void)
{  
	uint8_t i, j;
	for (j = 0; j < 8; j++)
	{
		OLED_SetCursor(j, 0);
		for(i = 0; i < 128; i++)
		{
			OLED_WriteData(0x00);
		}
	}
}

/**
  * @brief  OLED显示一个字符
  * @param  Line 行位置，范围：1~4
  * @param  Column 列位置，范围：1~16
  * @param  Char 要显示的一个字符，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char)
{      	
	uint8_t i;
	OLED_SetCursor((Line - 1) * 2, (Column - 1) * 8);		//设置光标位置在上半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i]);			//显示上半部分内容
	}
	OLED_SetCursor((Line - 1) * 2 + 1, (Column - 1) * 8);	//设置光标位置在下半部分
	for (i = 0; i < 8; i++)
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i + 8]);		//显示下半部分内容
	}
}

void OLED_ShowString(uint8_t Line, uint8_t Column, char *String)
{
	uint8_t i;
	for (i = 0; String[i] != '\0'; i++)
	{
		OLED_ShowChar(Line, Column + i, String[i]);
	}
}

uint32_t OLED_Pow(uint32_t x,uint32_t y)
{
	uint32_t tmp=1;
	while(y--)
	{
		tmp*=x;
	}
	return tmp;
}

void OLED_ShowNum(u8 l,u8 c,uint32_t num,u8 len)
{
	u8 i=0;
	for(i=0;i<len;i++)
	{
		OLED_ShowChar(l,c+i,num/(OLED_Pow(10,len-i-1))%10+'0');
	}
}