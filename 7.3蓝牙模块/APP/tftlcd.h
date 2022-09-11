#ifndef _TFTLCD_H
#define _TFTLCD_H

#include "system.h"
#include "systick.h"
#include "usart.h"
#include "front.h"
#include "spi_flash.h"

#define     W_CMD			*((u16*)(0x6c000000))
#define     W_DATA			*((u16*)(0x6c000800))


/*LCD控制信号*/
#define		LCD_CS_CLK		RCC_APB2Periph_GPIOG
#define		LCD_CS_PORT		GPIOG
#define		LCD_CS_PIN		GPIO_Pin_12

#define		LCD_BK_CLK		RCC_APB2Periph_GPIOB
#define		LCD_BK_PORT		GPIOB
#define		LCD_BK_PIN		GPIO_Pin_0

#define		LCD_RD_CLK		RCC_APB2Periph_GPIOD
#define		LCD_RD_PORT		GPIOD
#define		LCD_RD_PIN		GPIO_Pin_4

#define		LCD_WR_CLK		RCC_APB2Periph_GPIOD
#define		LCD_WR_PORT		GPIOD
#define		LCD_WR_PIN		GPIO_Pin_5

#define		LCD_DC_CLK		RCC_APB2Periph_GPIOG
#define		LCD_DC_PORT		GPIOG
#define		LCD_DC_PIN		GPIO_Pin_0

#define     LCD_BK			PBout(0)

/*数据线*/
#define  	LCD_D0_CLK      RCC_APB2Periph_GPIOD
#define		LCD_D0_PORT		GPIOD
#define		LCD_D0_PIN		GPIO_Pin_14

#define  	LCD_D1_CLK      RCC_APB2Periph_GPIOD
#define		LCD_D1_PORT		GPIOD
#define		LCD_D1_PIN		GPIO_Pin_15

#define  	LCD_D2_CLK      RCC_APB2Periph_GPIOD
#define		LCD_D2_PORT		GPIOD
#define		LCD_D2_PIN		GPIO_Pin_0

#define  	LCD_D3_CLK      RCC_APB2Periph_GPIOD
#define		LCD_D3_PORT		GPIOD
#define		LCD_D3_PIN		GPIO_Pin_1

#define  	LCD_D4_CLK      RCC_APB2Periph_GPIOE
#define		LCD_D4_PORT		GPIOE
#define		LCD_D4_PIN		GPIO_Pin_7

#define  	LCD_D5_CLK      RCC_APB2Periph_GPIOE
#define		LCD_D5_PORT		GPIOE
#define		LCD_D5_PIN		GPIO_Pin_8


#define  	LCD_D6_CLK      RCC_APB2Periph_GPIOE
#define		LCD_D6_PORT		GPIOE
#define		LCD_D6_PIN		GPIO_Pin_9

#define  	LCD_D7_CLK      RCC_APB2Periph_GPIOE
#define		LCD_D7_PORT		GPIOE
#define		LCD_D7_PIN		GPIO_Pin_10

#define  	LCD_D8_CLK      RCC_APB2Periph_GPIOE
#define		LCD_D8_PORT		GPIOE
#define		LCD_D8_PIN		GPIO_Pin_11

#define  	LCD_D9_CLK      RCC_APB2Periph_GPIOE
#define		LCD_D9_PORT		GPIOE
#define		LCD_D9_PIN		GPIO_Pin_12

#define  	LCD_D10_CLK     RCC_APB2Periph_GPIOE
#define		LCD_D10_PORT	GPIOE
#define		LCD_D10_PIN		GPIO_Pin_13

#define  	LCD_D11_CLK     RCC_APB2Periph_GPIOE
#define		LCD_D11_PORT	GPIOE
#define		LCD_D11_PIN		GPIO_Pin_14

#define  	LCD_D12_CLK     RCC_APB2Periph_GPIOE
#define		LCD_D12_PORT	GPIOE
#define		LCD_D12_PIN		GPIO_Pin_15

#define  	LCD_D13_CLK     RCC_APB2Periph_GPIOD
#define		LCD_D13_PORT	GPIOD
#define		LCD_D13_PIN		GPIO_Pin_8

#define  	LCD_D14_CLK     RCC_APB2Periph_GPIOD
#define		LCD_D14_PORT	GPIOD
#define		LCD_D14_PIN		GPIO_Pin_9

#define  	LCD_D15_CLK     RCC_APB2Periph_GPIOD
#define		LCD_D15_PORT	GPIOD
#define		LCD_D15_PIN		GPIO_Pin_10

//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	 0x001F
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色
#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
#define LIGHTGREEN     	 0X841F //浅绿色
#define LIGHTGRAY        0XEF5B //浅灰色(PANNEL)
#define LGRAY 			 0XC618 //浅灰色(PANNEL),窗体背景色
#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)
#define RGB888_2_RGB565(R,G,B)  (u16)(((R&0X1F)<<11)|((G&0X3F)<<5)|(B&0X1F))

void TFTLCD_Init();//初始化
void FULL_COloc(u16 color);
void TFTLCD_Set_Window(u16 x,u16 y,u16 width,u16 heigh);//开窗
void TFTLCD_Rectangle(u16 x,u16 y,u16 width,u16 heigh,u16 color);//画矩形
void TFTLCD_Dot(u16 x,u16 y,u16 color);//画点
void TFTLCD_Line(u16 col,u16 row,u16 len,u16 color);//画线
void LCD_Draw_Circle(u16 x0,u16 y0,u8 r);//画圆
void TFTLCD_Show_Char(u16 x,u16 y,u8 ch,u8 size,u8 mode);//显示字符
void TFTLCD_Show_String(u16 x,u16 y,u8* str,u8 size);//显示字符串
void TFTLCD_Show_HZ(u16 x,u16 y,u8* cn);
void TFTLCD_Show_NUM(u16 x,u16 y,u16 num,u8 len);//显示数字
void TFTLCD_Show_HEX(u16 x,u16 y,u16 num,u8 len);//显示16进制
void TFTLCD_Set_dir(u8 dir);
void TFTLCD_Draw_Line(u16 x1,u16 y1,u16 x2,u16 y2,u16 color);

#endif

