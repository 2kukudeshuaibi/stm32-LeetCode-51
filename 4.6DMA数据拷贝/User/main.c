#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"
#include "beep.h"
#include "exit.h"
#include "Time.h"
#include "usart.h"
#include "mydma.h"


u8 dataA[]={0x01,0x02,0x03,0x04};
u8 dataB[]={0,0,0,0};

int main()
{
	u8 i=0;
	systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	USART1_Init(115200);
	mydma_Init(DMA1_Channel1,(u32)dataA,(u32)dataB,4);
	while(1)
	{
		if(i%2==0)
		{
			LED2=!LED2;
		}
		//delay_ms(10);
		i++;
		printf("dataA:%d %d %d %d\r\n",dataA[0],dataA[1],dataA[2],dataA[3]);
		printf("dataB:%d %d %d %d\r\n",dataB[0],dataB[1],dataB[2],dataB[3]);
		delay_ms(1000);
		DMA_Transfer(DMA1_Channel1,4);
		printf("dataA:%d %d %d %d\r\n",dataA[0],dataA[1],dataA[2],dataA[3]);
		printf("dataB:%d %d %d %d\r\n",dataB[0],dataB[1],dataB[2],dataB[3]);
		dataA[0]++;
		dataA[1]++;
		dataA[2]++;
		dataA[3]++;
	}
	return 0;
}