#include "wwdg.h"
#include "stdio.h"

void WWDG_Init()
{
	
	NVIC_InitTypeDef NVIC_Initstruct;
	NVIC_Initstruct.NVIC_IRQChannel=WWDG_IRQn;
	NVIC_Initstruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Initstruct.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_Initstruct.NVIC_IRQChannelSubPriority=3;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	WWDG_SetPrescaler(WWDG_Prescaler_8);
	WWDG_SetWindowValue(0x6f);
    NVIC_Init(&NVIC_Initstruct);
	WWDG_Enable(0x7f);
	WWDG_ClearFlag();
	WWDG_EnableIT();
	
}

void WWDG_IRQHandler()
{
	if(!key_scan())
	{
		WWDG_SetCounter(0x7f);
	}
	WWDG_ClearFlag();
	LED2=!LED2;
}