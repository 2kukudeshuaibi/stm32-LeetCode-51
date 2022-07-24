#include "mydma.h"

void mydma_Init(DMA_Channel_TypeDef* DMAy_Channelx,u32 arrp,u32 arrb,u16 times)
{
	DMA_InitTypeDef DMA_Initstruct;
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	DMA_Initstruct.DMA_PeripheralBaseAddr=arrp;
	DMA_Initstruct.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte;
	DMA_Initstruct.DMA_PeripheralInc=DMA_PeripheralInc_Enable;
	DMA_Initstruct.DMA_MemoryBaseAddr=arrb;
	DMA_Initstruct.DMA_MemoryDataSize=DMA_MemoryDataSize_Byte;
	DMA_Initstruct.DMA_MemoryInc=DMA_MemoryInc_Enable;
	
	DMA_Initstruct.DMA_BufferSize=times;
	DMA_Initstruct.DMA_DIR=DMA_DIR_PeripheralSRC;
	DMA_Initstruct.DMA_M2M=DMA_M2M_Enable;
	DMA_Initstruct.DMA_Mode=DMA_Mode_Normal;
	DMA_Initstruct.DMA_Priority=DMA_Priority_Medium;
	DMA_Init(DMAy_Channelx,&DMA_Initstruct);
	
	DMA_Cmd(DMAy_Channelx,DISABLE);
}

void DMA_Transfer(DMA_Channel_TypeDef* DMAy_Channelx,u16 times)
{
	DMA_Cmd(DMAy_Channelx,DISABLE);
	DMA_SetCurrDataCounter(DMAy_Channelx,times);
	DMA_Cmd(DMAy_Channelx,ENABLE);
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1)==RESET);
	DMA_ClearFlag(DMA1_FLAG_TC1);
}