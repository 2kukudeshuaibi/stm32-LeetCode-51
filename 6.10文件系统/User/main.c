#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"
#include "usart.h"
#include "tftlcd.h"
#include "spi_flash.h"
#include "ff.h"

FATFS fsobject;
FIL pf;


char wdata[]="°¢ËÉ¿¬Ä£°¢Ë¹ÆÕ";
char rdata[10]={0};
UINT bw=0;
UINT rw=0;
int main()
{
	u8 i=0;
	FRESULT res;
	
	systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	
	USART1_Init(115200);
	SPI2_FLASH_Init();
	TFTLCD_Init();
	SPI_FLASH_Erase_Chip();
	res=f_mount(&fsobject,"1:",1);
	printf("f_mount1=%d\r\n",res);
	if(res==FR_NO_FILESYSTEM)
	{
		res=f_mkfs("1:",0,0);
		printf("f_mkfs=%d\r\n",res);
		res=f_mount(NULL,"1:",1);
		printf("f_mount2=%d\r\n",res);
		res=f_mount(&fsobject,"1:",1);
		printf("f_mount3=%d\r\n",res);
	}
	res=f_open(&pf,"1:abcd.txt",FA_OPEN_ALWAYS|FA_READ|FA_WRITE);
	printf("f_open=%d\r\n",res);
	if(res==FR_OK)
	{
		res=f_write(&pf,wdata,sizeof(wdata),&bw);
		printf("f_write=%d\r\n",res);
		printf("bw:%d\r\n",bw);
		if(res==FR_OK)
		{
			f_lseek(&pf,0);
			res=f_read(&pf,rdata,f_size(&pf),&rw);
			printf("f_read=%d\r\n",res);
			if(res==FR_OK)
			{
				printf("rdata:%s rw=%d \r\n",rdata,rw);
			}
			
		}
	}
	
	res=f_close(&pf);
	printf("f_close=%d\r\n",res);
	while(1)
	{
		if(i%20==0)
		{
			LED2=!LED2;
		}
		delay_ms(10);
		i++;
	}
	return 0;
}