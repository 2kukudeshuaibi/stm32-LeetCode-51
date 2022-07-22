#include "dma.h"

void DMAX_Init(DMA_Channel_TypeDef* DMAy_Channelx,u32 par,u32 mar,u16 ndtr)
{
	DMA_InitTypeDef DMA_Initstruct;
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	DMA_Initstruct.DMA_PeripheralBaseAddr=par;
	DMA_Initstruct.DMA_MemoryBaseAddr=mar;
	DMA_Initstruct.DMA_BufferSize=ndtr;
	DMA_Initstruct.DMA_DIR=DMA_DIR_PeripheralDST;
	DMA_Initstruct.DMA_M2M=DMA_M2M_Disable;
	DMA_Initstruct.DMA_MemoryDataSize=DMA_MemoryDataSize_Byte;
	DMA_Initstruct.DMA_MemoryInc=DMA_MemoryInc_Enable;
	DMA_Initstruct.DMA_Mode=DMA_Mode_Normal;
	DMA_Initstruct.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte;
	DMA_Initstruct.DMA_PeripheralInc=DMA_PeripheralInc_Disable;
	DMA_Initstruct.DMA_Priority=DMA_Priority_Medium;
	DMA_Init(DMAy_Channelx,&DMA_Initstruct);
}

void DMAX_ENABLE(DMA_Channel_TypeDef* DMAy_Channelx,u16 ndtr)
{
	DMA_Cmd(DMAy_Channelx,DISABLE);
	DMA_SetCurrDataCounter(DMAy_Channelx,ndtr);
	DMA_Cmd(DMAy_Channelx,ENABLE);
}