#include "stm32f10x_gpio.h"


void GPIO_Init(GPIO_Typedef* GPIOx,GPIO_InitTypedef* GPIO_InitStruct)
{
	uint32_t currentmode=0x00;
	uint16_t currentspeed=0x00;
	uint32_t pos=0x00;
	uint32_t poserr=0x00;
	uint32_t tes=0x00;
	uint16_t pin=0x00;
	pin=GPIO_InitStruct->GPIO_Pin;
	currentmode=GPIO_InitStruct->GPIO_Mode;
	if(pin&0x00ff)
	{
		tes=GPIOx->CRL;
		for(poserr=0;poserr<8;poserr++)
		{
			pos=(0x01<<poserr);
			if(pos&pin)
			{
				pos=poserr<<2;
				tes&=~(0x0f<<pos);
				if(currentmode&0x10)
				{
					currentspeed=GPIO_InitStruct->GPIO_Speed;
					currentmode&=0x0f;
					tes=tes|((currentspeed|currentmode)<<pos);
				}
				else
				{
					if(GPIO_InitStruct->GPIO_Mode==GPIO_Mode_IPD)
					{
						GPIOx->BSRR|=(GPIO_InitStruct->GPIO_Pin<<16);
					}
					if(GPIO_InitStruct->GPIO_Mode==GPIO_Mode_IPU)
					{
						GPIOx->BSRR|=GPIO_InitStruct->GPIO_Pin;
					}
				}
			}
		}
		GPIOx->CRL=tes;
	}
	else
	{
		tes=GPIOx->CRH;
		for(poserr=0;poserr<8;poserr++)
		{
			pos=(0x01<<poserr+8);
			if(pos&pin)
			{
				pos=poserr<<2;
				tes&=~(0x0f<<pos);
				if(currentmode&0x10)
				{
					currentspeed=GPIO_InitStruct->GPIO_Speed;
					currentmode&=0x0f;
					tes=tes|((currentspeed|currentmode)<<pos);
				}
				else
				{
					if(GPIO_InitStruct->GPIO_Mode==GPIO_Mode_IPD)
					{
						GPIOx->BSRR|=(GPIO_InitStruct->GPIO_Pin<<16);
					}
					if(GPIO_InitStruct->GPIO_Mode==GPIO_Mode_IPU)
					{
						GPIOx->BSRR|=GPIO_InitStruct->GPIO_Pin;
					}
				}
			}
		}
		GPIOx->CRH=tes;
	}
}

void GPIO_SetBits(GPIO_Typedef* GPIOx,uint16_t GPIO_Pin)
{
	GPIOx->BSRR|=GPIO_Pin;
}

void GPIO_RSetBits(GPIO_Typedef* GPIOx,uint16_t GPIO_Pin)
{
	GPIOx->BSRR|=(GPIO_Pin<<16);
}
