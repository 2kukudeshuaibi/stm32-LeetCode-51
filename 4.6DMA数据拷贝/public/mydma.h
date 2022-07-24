#ifndef _mydma_H
#define _mydma_H

#include "system.h"
void mydma_Init(DMA_Channel_TypeDef* DMAy_Channelx,u32 arrp,u32 arrb,u16 times);
void DMA_Transfer(DMA_Channel_TypeDef* DMAy_Channelx,u16 times);


#endif