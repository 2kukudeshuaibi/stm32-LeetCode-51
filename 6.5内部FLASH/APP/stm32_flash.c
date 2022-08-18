#include "stm32_flash.h"


//vu16 stm32_flash_ReadHalfWord(u32 faddr)
//{
//	return *(vu16*)faddr;
//}


//void stm32_flash_Read(u32 addr,u16* buf,u16 num)
//{
//	u16 i=0;
//	for(i=0;i<num;i++)
//	{
//		buf[i]=stm32_flash_ReadHalfWord(addr);
//		addr+=2;
//	}
//}

//void stm32_flash_WriteNocheck(u32 addr,u16* buf,u16 num)
//{
//	u16 i=0;
//	for(i=0;i<num;i++)
//	{
//		FLASH_ProgramHalfWord(addr,buf[i]);
//		addr+=2;
//	}
//}

//u16 pbuff[STM32_SECTOR_SIZE/2];

//void stm32_flash_Write(u32 addr,u16* buf,u16 num)
//{
//	u16 i=0;
//	u32 sqdz=0;
//	u16 sqpy=0;
//	u16 sqsy=0;
//	u32 zsdz=0;
//	FLASH_Unlock();
//	if((addr<STM32_FLASH_BASE)||(addr>=(STM32_FLASH_BASE+1024*STM32_FLASH_SIZE)))
//	{
//		return;
//	}
//	zsdz=addr-STM32_FLASH_BASE;
//	sqdz=zsdz/STM32_SECTOR_SIZE;
//	sqpy=(zsdz%STM32_SECTOR_SIZE)/2;
//	sqsy=STM32_SECTOR_SIZE/2-sqpy;
//	if(num<=sqsy)
//		sqsy=num;
//	while(1)
//	{
//		stm32_flash_Read(sqdz*STM32_SECTOR_SIZE+STM32_FLASH_BASE,pbuff,STM32_SECTOR_SIZE/2);
//		for(i=0;i<sqsy;i++)
//		{
//			if(pbuff[i+sqpy]!=0xffff)
//				break;
//		}
//		if(i<sqsy)
//		{
//			FLASH_ErasePage(sqdz*STM32_SECTOR_SIZE+STM32_FLASH_BASE);
//			for(i=0;i<sqsy;i++)
//			{
//				pbuff[i+sqpy]=buf[i];
//			}
//			stm32_flash_WriteNocheck(sqdz*STM32_SECTOR_SIZE+STM32_FLASH_BASE,pbuff,STM32_SECTOR_SIZE/2);
//		}
//		else
//		{
//			stm32_flash_WriteNocheck(addr,buf,sqsy);
//		}
//		if(sqsy==num)
//		{
//			break;
//		}
//		else
//		{
//			sqdz++;
//			sqpy=0;
//			addr+=sqsy;
//			buf+=sqsy;
//			num-=sqsy;
//			if(num>(STM32_SECTOR_SIZE/2))
//			{
//				sqsy=STM32_SECTOR_SIZE/2;
//			}
//			else
//			{
//				sqsy=num;
//			}
//		}
//	}
//	
//	FLASH_Lock();
//}


vu16 STM32_FLASH_HalfRead(u32 addr)
{
	return *(vu16*)addr;
}

void STM32_WriteNoCheck(u32 addr,u16* buf,u16 num)
{
	u16 i = 0;
	for(i = 0;i < num;i++)
	{
		FLASH_ProgramHalfWord(addr,buf[i]);
		addr+=2;
	}
}

void STM32_FLASH_Read(u32 addr,u16* buf,u16 num)
{
	u16 i = 0;
	for(i = 0;i < num;i++)
	{
		buf[i]=STM32_FLASH_HalfRead(addr);
		addr+=2;
	}
}

u16 BUFF[STM32_FLASH_SECTOR/2];
void STM32_FLASH_Write(u32 addr,u16* buf,u16 num)
{
	printf("²âÊÔ1\r\n");
	u32 secpos=0;
	u16 secoff=0;
	u16 secres=0;
	u32 secsta=0;
	u16 i=0;
	if((addr<STM32_FLASH_BASE)||(addr>=(STM32_FLASH_BASE+1024*STM32_FLASH_SIZE)))
	{
		return;
	}
	secsta=addr-STM32_FLASH_BASE;
	secpos=secsta/STM32_FLASH_SECTOR;
	secoff=(secsta%STM32_FLASH_SECTOR)/2;
	secres=(STM32_FLASH_SECTOR/2)-secoff;
	if(num<=secres)
	{
		secres=num;
	}
	printf("²âÊÔ2\r\n");
	FLASH_Unlock();
	printf("²âÊÔ3\r\n");
	while(1)
	{
		STM32_FLASH_Read(secpos*STM32_FLASH_SECTOR+STM32_FLASH_BASE,BUFF,STM32_FLASH_SECTOR/2);
		for(i=0;i<secres;i++)
		{
			if(BUFF[i+secoff]!=0xffff)
			{
				break;
			}
		}
		if(i<secres)
		{
			FLASH_ErasePage(secpos*STM32_FLASH_SECTOR+STM32_FLASH_BASE);
			for(i=0;i<secres;i++)
			{
				BUFF[i+secoff]=buf[i];
			}
			STM32_WriteNoCheck(secpos*STM32_FLASH_SECTOR+STM32_FLASH_BASE,BUFF,STM32_FLASH_SECTOR/2);
		}
		else
		{
			STM32_WriteNoCheck(addr,buf,secres);
		}
		if(secres==num)
		{
			break;
		}
		else
		{
			secpos++;
			secoff=0;
			
			addr+=secres;
			buf+=secres;
			num-=secres;
			if(num>(STM32_FLASH_SECTOR/2))
			{
				secres=STM32_FLASH_SECTOR/2;
			}
			else
			{
				secres=num;
			}
		}
	}
	FLASH_Lock();
}
