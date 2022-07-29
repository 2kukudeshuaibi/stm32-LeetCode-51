#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"
#include "beep.h"
#include "exit.h"
#include "Time.h"
#include "usart.h"
#include "IR.h"


int main()
{
	u8 i=0;
	u8 addr=0;
	u8 command=0;
	systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	USART1_Init(115200);
	IR_Init();
	while(1)
	{
		if(i%20==0)
		{
			LED2=!LED2;
		}
		delay_ms(10);
		i++;
		if(Get_data_flag())
		{
			addr=Get_add();
			command=Get_command();
			printf("地址为:%x\r\n",addr);
			printf("键值为:%x\r\n",command);
		}
		if(command!=0)
		{
			LED1=0;
		}
		
	}
	return 0;
}