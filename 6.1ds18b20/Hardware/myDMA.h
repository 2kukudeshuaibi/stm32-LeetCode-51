#ifndef _myDMA_H
#define _myDMA_H

#include "stm32f10x.h"

void My_DMA_Init(DMA_Channel_TypeDef* DMAy_Channelx,u32 arrp,u32 arrb,u16 times);
void Start_Transfer(DMA_Channel_TypeDef* DMAy_Channelx,u16 times);


#endif